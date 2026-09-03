---
title: Manual del Entorno de Desarrollo Portable
short_title: Entorno de Desarrollo
subtitle: Instalación, arquitectura y uso de la caja de herramientas portable de la cátedra
---

# Manual del Entorno de Desarrollo Portable

Para simplificar los aspectos técnicos vinculados a la configuración de
compiladores, editores y utilidades de consola, la cátedra diseñó una caja de
herramientas autocontenida y portable. Este entorno integra todo el software
necesario para cursar la materia de forma homogénea, sin requerir permisos de
administrador ni modificar la configuración global del sistema operativo
anfitrión.

El objetivo central es eliminar la problemática del tipo «en mi máquina
funciona», permitiendo tanto el desarrollo en equipos personales como el trabajo
seguro desde memorias USB en computadoras compartidas o sin conexión a internet
constante.

---

## 1. Requisitos Previos

El entorno está preparado para operar en las siguientes plataformas:

*   **Windows:** Windows 10 (versión 1903 o superior) o Windows 11 sobre
    arquitectura x64, con permisos para ejecutar scripts en PowerShell
    (`RemoteSigned` o ejecución con directiva temporal `Bypass`).
*   **GNU/Linux:** Cualquier distribución moderna sobre arquitectura x86_64 con
    las herramientas base de compilación (`gcc`, `g++`, `make`, `cmake`,
    `ninja`, `python3`, `pip`, `git`, `curl`).

---

## 2. Casos de Uso Educativos

El diseño modular del entorno responde a cuatro situaciones críticas
identificadas en el dictado de la materia:

### Estudiante sin Conectividad Constante (Desarrollo Offline)

Muchos estudiantes no disponen de acceso continuo a conexiones de alta velocidad
para descargar herramientas pesadas (Visual Studio Code, compiladores,
depuradores e intérpretes), o necesitan replicar el entorno en varios equipos
sin consumir datos móviles reiteradamente. El entorno permite empaquetar una
instalación completa en un único archivo comprimido e instalarla de forma
desatendida sin conexión.

### Programación en Computadoras Compartidas (Laboratorios y Cibercafés)

Al trabajar en equipos de laboratorios universitarios o de uso público, se
presentan tres limitaciones habituales:
1. **Restricción de privilegios:** Imposibilidad de instalar compiladores en el
   sistema por carecer de permisos de administrador (`root` / Administrador).
2. **Exposición de datos personales:** Riesgo de dejar abiertas sesiones,
   historiales de consola, claves privadas SSH o tokens personales de GitHub en
   discos rígidos compartidos.
3. **Pérdida de configuraciones:** Cada reinicio o cambio de máquina suele
   restablecer el estado del sistema, forzando a reconfigurar herramientas desde
   cero.

El entorno portable encapsula tanto los binarios como el directorio personal de
usuario en el medio de almacenamiento extraíble, e incluye scripts específicos
de saneamiento de credenciales al finalizar la sesión.

### Homogeneidad y Consistencia en la Cátedra

Las sutiles discrepancias de versión entre compiladores, los conflictos en
variables de entorno globales (`PATH`) o la presencia de suites obsoletas
consumen tiempo valioso de clase en depurar problemas de configuración local
ajenos a la lógica algorítmica. Unificar las versiones de GCC, GDB, Cppcheck,
Python y VS Code garantiza que el código que compila en la máquina del
estudiante compile exactamente igual en las instancias de evaluación.

### Gestión Simplificada de Bibliotecas en C

La instalación manual de bibliotecas externas en C (por ejemplo `raylib`,
`inih`, `sqlite3` o `nuklear`) en sistemas Windows suele exigir compilación
desde fuentes, resolución de dependencias y enlace manual de rutas de cabeceras
(`-I`) y bibliotecas (`-L`, `-l`). El entorno automatiza la descarga,
compilación e instalación de bibliotecas directamente en el prefijo del
compilador con un único comando.

---

## 3. Arquitectura del Entorno y Aislamiento

El principio rector del entorno es el aislamiento respecto al sistema anfitrión.
Todos los componentes ejecutables, configuraciones y datos de usuario conviven
dentro del directorio raíz del entorno (`PORTABLE_ROOT`).

:::{figure} images/arquitectura_entorno.svg
:label: fig-arquitectura-entorno
:alt: Diagrama de arquitectura del entorno de desarrollo portable. Muestra los flujos de inicialización desde los lanzadores (launch.bat/launch.ps1), la configuración del PATH local apuntando a bin/ y ucrt64/bin, el aislamiento de datos de VS Code en la carpeta vscode/data, y la persistencia de las claves y configuraciones de usuario dentro del directorio personal home/.
:align: center
:width: 100%

Arquitectura del entorno de desarrollo portable y flujo de aislamiento de
variables de sesión.

:::
<!-- {figure} images/arquitectura_entorno.svg -->

### Componentes Físicos y Lógicos

*   **Lanzadores de sesión (`launch.bat`, `launch.ps1`, `launch-vscode.bat`,
    `launch-vscode.ps1`):** Detectan de forma dinámica la ruta absoluta del
    entorno, inicializan las variables de entorno locales de la sesión
    (`PORTABLE_ROOT`, `PATH`, `HOME`), sanean la configuración de terminal y
    lanzan la aplicación correspondiente sin alterar las variables globales de
    Windows.
*   **Lanzadores ejecutables nativos (`launch.exe`, `launch-vscode.exe`):**
    Binarios compilados en C ubicados en la raíz que inician la consola o el
    editor de manera directa y silenciosa, suprimiendo la ventana negra
    transitoria de PowerShell.
*   **Directorio `bin/` (PATH local prioritario):** Contiene los scripts de
    automatización de la cátedra (`nuevo-proyecto`, `verificar`, `entregar`,
    `doctor`, `ripley`, entre otros). Esta carpeta se antepone al `PATH` de la
    sesión para tener precedencia sobre cualquier utilidad del sistema
    anfitrión.
*   **Subsistema MSYS2 (`msys64/`):** Provee el userland POSIX estándar
    (`usr/bin`: Bash, coreutils, Git, pacman, curl, OpenSSH) y el toolchain
    nativo de desarrollo bajo UCRT64 (`ucrt64/bin`: GCC, G++, GDB, Make, CMake,
    Ninja, Cppcheck, Doxygen, Python 3 con `uv`).
*   **Editor VS Code Portable (`vscode/`):** Desplegado en modo estrictamente
    portable mediante el directorio `vscode/data/`. Todas las extensiones
    instaladas, archivos de configuración (`settings.json`, `keybindings.json`)
    y estados de sesión se resguardan allí, sin escribir en `%APPDATA%` ni en
    `%USERPROFILE%`.
*   **Directorio HOME Aislado (`home/`):** Opera como el `$HOME` efectivo del
    usuario durante la sesión. El historial de Bash (`.bash_history`),
    configuraciones de herramientas (`.bashrc`, `.gitconfig`), claves SSH
    (`.ssh/`) y credenciales temporales se confinan a este directorio.

### Filosofía en GNU/Linux

En sistemas GNU/Linux, el entorno opera bajo un esquema de activación ligera de
sesión:

*   **No invasivo:** No crea ni modifica archivos fuera de la carpeta donde se
    descargó el repositorio.
*   **Sin permisos elevados:** No invoca gestores de paquetes con `sudo` ni
    requiere privilegios de administración.
*   **Aislamiento de usuario:** Redirige `$HOME` hacia `home/` (o el nombre
    establecido en `.env`), resguardando configuraciones y claves dentro del
    entorno local.
*   **Limpieza absoluta:** La activación afecta exclusivamente a la subshell
    actual. Al cerrar la terminal o ejecutar el comando `deactivate`, la sesión
    del sistema recupera sus variables originales de manera inmediata.

---

## 4. Instalación y Configuración Inicial

### Instalación en Windows

Existen dos vías para instalar el entorno en Windows. La Opción A es el método
recomendado.

#### Opción A: Instalación Directa desde PowerShell (Recomendada)

Abrí una consola de PowerShell en la carpeta donde desees alojar el entorno (por
ejemplo en la raíz de un pendrive o en `C:\dev\entorno`) y ejecutá la siguiente
instrucción:

``` powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; irm https://raw.githubusercontent.com/INGCOM-UNRN-P1/entorno/main/install.ps1 | iex
```
<!-- powershell -->

Este script descarga el instalador principal (`setup.ps1`) con la codificación y
sumas de verificación adecuadas, valida el espacio disponible en disco e
inicializa el entorno de forma asistida.

:::{tip} Opciones Avanzadas del Instalador

Una vez descargado `setup.ps1`, podés relanzar la instalación con parámetros
específicos:

*   `-HomeDirName <nombre>`: Asigna un nombre personalizado a la carpeta de
    usuario (por defecto `home`).
*   `-ImportHostConfig`: Copia al entorno portable las claves SSH y
    configuraciones de Git existentes en el equipo host.
*   `-Yes`: Ejecuta la instalación en modo no interactivo (recomendado para
    despliegues en lote en aulas).
*   `-Latest`: Instala las versiones más recientes de los paquetes omitiendo los
    pines de `versions.json`.

Ejemplo de uso combinado:
``` powershell
.\setup.ps1 -HomeDirName "alumno" -ImportHostConfig
```
<!-- powershell -->

:::
<!-- {tip} Opciones Avanzadas del Instalador -->

#### Opción B: Clonado o Descarga Manual del Repositorio

Si preferís clonar el repositorio mediante Git o descargarlo como archivo ZIP:

1. Cloná el repositorio en el destino seleccionado:
   ```bash
   git clone https://github.com/INGCOM-UNRN-P1/entorno.git
   cd entorno
   ```
2. Abrí PowerShell en dicho directorio e iniciá la instalación:
   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; .\setup.ps1
   ```

:::{warning} Exclusiones en Antivirus (Windows Defender)

En ocasiones, Windows Defender u otros antivirus pueden ralentizar las
compilaciones con GCC o generar falsos positivos con errores como
`VirtualProtect failed with code 0x5af`. Si esto ocurre, abrí PowerShell con
privilegios de Administrador en la raíz del entorno y ejecutá:

``` powershell
.\fix-antivirus.ps1
```
<!-- powershell -->

Este script añade automáticamente una exclusión de análisis a la carpeta raíz
del entorno portable.

:::
<!-- {warning} Exclusiones en Antivirus (Windows Defender) -->

---

### Instalación y Diagnóstico en GNU/Linux

En GNU/Linux no es necesario instalar una suite completa de MSYS2, ya que el
sistema cuenta con su propio núcleo POSIX. La variante Linux aprovecha las
herramientas instaladas en la distribución anfitriona y asegura su
compatibilidad mediante scripts de diagnóstico y activación.

1. Cloná el repositorio:
   ```bash
   git clone https://github.com/INGCOM-UNRN-P1/entorno.git
   cd entorno
   ```

2. Ejecutá el asistente de diagnóstico:
   ```bash
   linux/bootstrap.sh
   ```
   El script audita el sistema sin privilegios de `sudo` e identifica:
   *   **Herramientas obligatorias (Core):** `git`, `gcc`, `g++`, `make`,
       `cmake`, `ninja`, `python3`, `pip`, `curl`.
   *   **Herramientas recomendadas (Toolchain ampliado):** `gdb`, `cppcheck`,
       `doxygen`, `gh`, `uv`.

   Si falta algún componente, `bootstrap.sh` detecta el gestor de paquetes de tu
   distribución (`apt`, `dnf`, `pacman`, `zypper`, `apk`) e imprime el comando
   exacto para que lo instales en el sistema.

---

## 5. Inicialización y Arranque Diario

### En Windows

Para iniciar la jornada de trabajo contás con dos alternativas principales:

1. **Terminal Interactiva (WezTerm / Bash):**
   *   Desde el explorador de archivos: Doble clic en `launch.bat` (o
       `launch.exe`).
   *   Desde PowerShell: `.\launch.ps1`.
   *   *Fallback:* Si WezTerm no estuviera presente, el lanzador iniciará
       automáticamente una sesión de Bash UCRT64 en la consola estándar de
       Windows.

2. **Editor de Código (VS Code Portable):**
   *   Desde el explorador de archivos: Doble clic en `launch-vscode.bat` (o
       `launch-vscode.exe`).
   *   Desde PowerShell: `.\launch-vscode.ps1`.
   *   El editor hereda de inmediato el compilador GCC, Make, CMake, Ninja y
       Python en su terminal integrada, habilitando la compilación y depuración
       con la tecla F5 de forma nativa.

#### Compilación de Lanzadores Nativos `.exe`

Para suprimir el parpadeo de las ventanas de consola al abrir las aplicaciones
desde accesos directos, podés compilar los ejecutables de inicio nativos. Dentro
de la terminal portable, ejecutá:

``` bash
build-launcher.sh
```
<!-- bash -->

El script compilará los fuentes ubicados en `launcher/launcher.c` generando
`launch.exe` y `launch-vscode.exe` en la raíz del entorno.

---

### En GNU/Linux

La interacción en GNU/Linux se realiza activando la sesión mediante el script de
entorno:

```{code-block} bash
:linenos:
# 1. Activar el entorno portable en la terminal actual
source linux/activate.sh

# 2. Consultar la ayuda rápida de herramientas
ayuda

# 3. Al finalizar la jornada, restaurar el estado original de la terminal
deactivate

```
<!-- {code-block} bash -->

Al activarse la sesión:
*   `$HOME` pasa a apuntar a `./home`.
*   Se antepone `linux/bin/` al `PATH`.
*   Se configuran las variables de compilación e inclusión (`CC=gcc`, `CPATH`,
    `LIBRARY_PATH`, `PKG_CONFIG_PATH`, `CMAKE_PREFIX_PATH`) apuntando al prefijo
    local `local/`.

---

## 6. Comandos y Utilidades de Cátedra (`bin/`)

Una vez dentro de la terminal del entorno (en Windows o en Linux), disponés de
una serie de comandos integrados diseñados para el flujo de trabajos prácticos
de Programación 1:

:::{table} Comandos de Cátedra
:label: tbl-comandos-catedra

| Comando | Función Principal |
| :--- | :--- |
| `ayuda` | Muestra el resumen de comandos, rutas y utilidades disponibles en el entorno. |
| `nuevo-proyecto <nombre>` | Genera la estructura inicial de un proyecto de cátedra con Makefile y depuración lista. |
| `clonar <url>` | Clona un repositorio de GitHub Classroom en `~/proyectos`. |
| `verificar` | Ejecuta las pruebas automatizadas de cátedra (`tests/caso_NN.in/.out`) o corre Ripley. |
| `entregar` | Valida, compila y empaqueta el trabajo práctico en un archivo ZIP listo para entregar. |
| `doctor` | Realiza una auditoría rápida de salud: compila un programa de prueba y valida herramientas. |
| `doctor --fix` | Repara marcadores, plantillas base y configuraciones faltantes del entorno. |
| `ripley` | Ejecuta el motor pedagógico de análisis estático, reglas de cátedra y AddressSanitizer. |
| `backup` | Genera un respaldo comprimido del HOME portable y los manifiestos de bibliotecas. |
| `restaurar <archivo.zip>` | Restaura un respaldo previo sobre el HOME actual. |
| `configure-git.sh` | Asistente para configurar la firma de Git y autenticarse con GitHub CLI (`gh`). |
| `install-lib.sh <repo> [tag]` | Descarga, compila e instala una biblioteca de C desde GitHub en el entorno. |
| `uninstall-lib.sh <nombre>` | Desinstala una biblioteca de C previamente registrada. |
| `diagnose-env.sh` | Genera el informe técnico completo `diagnose.log` para solicitar soporte a docentes. |
| `update-env.sh` | Actualiza los scripts del entorno y el motor Ripley a la última versión disponible. |

:::
<!-- {table} Comandos de Cátedra -->

### Flujo de Trabajo en Trabajos Prácticos

#### 1. Creación de un Proyecto

Para crear un nuevo proyecto estructurado según los estándares de la cátedra:

```{code-block} bash
:linenos:
# Modalidad programa plano (por defecto): main.c, Makefile con reglas debug, asan, test, ripley
nuevo-proyecto tp01

# Modalidad Trabajo Práctico modular: estructura con libs/, ejercicios/ y script tp.sh
nuevo-proyecto --tipo tp tp02

# Modalidad Biblioteca de C: estructura para desarrollar bibliotecas reutilizables
nuevo-proyecto --tipo lib milib

```
<!-- {code-block} bash -->

Cada proyecto generado incluye:
*   Configuración de depuración lista para VS Code (`.vscode/launch.json` y
    `.vscode/tasks.json` asociados a GDB).
*   Reglas de estilo y formateo automático (`.clang-format` y `.editorconfig`).
*   Makefile estandarizado con metas `make` (compilación estándar), `make debug`
    (símbolos para GDB), `make asan` (AddressSanitizer para detección de fugas y
    desbordamientos) y `make ripley` (análisis estático).

#### 2. Auditoría y Análisis con Ripley

El entorno incluye el motor de análisis estático pedagógico **Ripley**
(`bin/ripley`), descargado automáticamente durante la instalación. Permite
auditar el código fuente contra las reglas de estilo de la cátedra, detectar
punteros descolgados, pérdidas de memoria y traducir los mensajes de error de
GCC al español:

``` bash
# Diagnosticar estado del motor Ripley
ripley doctor

# Auditar el código del directorio actual
ripley check .
```
<!-- bash -->

#### 3. Verificación y Entrega

Antes de entregar un trabajo práctico, podés comprobar su funcionamiento contra
la suite de casos de prueba provista por la cátedra:

``` bash
# Ejecutar los casos de prueba (o delegar en ripley check si el proyecto tiene manifiesto)
verificar

# Compilar, verificar y generar el paquete ZIP de entrega
entregar
```
<!-- bash -->

El comando `entregar` previene entregas defectuosas: si el código no compila o
no supera las pruebas con rigor estricto, aborta la operación e indica las
fallas detectadas. Si el proyecto resulta exitoso, genera un archivo ZIP limpio,
excluyendo binarios compilados, carpetas temporales de compilación (`build/`,
`.vscode/`) y cachés.

---

## 7. Configuración de Git y Autenticación en GitHub

Dado que el entorno mantiene su propio directorio personal aislado, la
configuración de Git debe realizarse dentro del entorno portable para que tus
commits queden firmados correctamente:

1. Iniciá la terminal del entorno (`launch.bat` o `source linux/activate.sh`).
2. Ejecutá el asistente interactivo:
   ```bash
   configure-git.sh
   ```
3. Ingresá tu nombre y correo electrónico institucional.
4. El script iniciará el proceso de autenticación con GitHub CLI (`gh auth
   login`).

Las credenciales y tokens de acceso se resguardan de manera cifrada o mediante
el almacén local en `home/.git-credentials`, garantizando que no se filtren en
el sistema anfitrión.

---

## 8. Gestión de Bibliotecas en C (`install-lib.sh`)

La instalación de bibliotecas externas suele ser un obstáculo al comenzar a
programar en C. El comando `install-lib.sh` automatiza la clonación, compilación
y ubicación de encabezados (`.h`) y binarios (`.a` / `.dll`) en el prefijo
UCRT64 (Windows) o `local/` (Linux):

``` bash
install-lib.sh <usuario/repositorio_github> [rama_o_tag]
```
<!-- bash -->

### Ejemplos de Instalación

```{code-block} bash
:linenos:
# 1. Instalar Nuklear (interfaz gráfica modo inmediato, solo cabeceras)
install-lib.sh immediate-mode-ui/nuklear

# 2. Instalar inih (parser de archivos de configuración INI con CMake)
install-lib.sh davidsiaw/inih r29

# 3. Instalar una biblioteca modular desarrollada con la plantilla de cátedra
install-lib.sh mi-usuario/mi-biblioteca

```
<!-- {code-block} bash -->

Para desinstalar una biblioteca y limpiar sus archivos asociados:
``` bash
uninstall-lib.sh inih
```
<!-- bash -->

---

## 9. Seguridad en Computadoras Compartidas (Limpieza de Sesión)

Si utilizás el entorno desde una memoria USB en computadoras de laboratorios o
equipos compartidos, es imprescindible sanear tu sesión antes de desconectar el
dispositivo para evitar dejar accesos abiertos:

1. Cerrá Visual Studio Code y todas las terminales activas.
2. Abrí PowerShell en la raíz del entorno en el pendrive y ejecutá:
   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; .\clean-shared-host.ps1
   ```
3. El script listará los archivos a depurar (historial de comandos de Bash,
   claves privadas SSH, credenciales almacenadas de GitHub y extensiones
   temporales de VS Code). Confirmá la acción con la letra `s`.

:::{important} Saneamiento sin Pérdida de Herramientas

`clean-shared-host.ps1` no borra los compiladores, ni el editor, ni los paquetes
instalados. Solo suprime tus credenciales y rastros personales de navegación y
consola, dejando el pendrive listo para ser usado de forma segura en otro
equipo.

:::
<!-- {important} Saneamiento sin Pérdida de Herramientas -->

---

## 10. Distribución y Respaldo Offline

### Generación del Paquete Offline

Para crear un instalador completo listo para máquinas sin acceso a internet:

1. Ejecutá la instalación normal en un equipo con conectividad mediante
   `setup.ps1`.
2. Una vez finalizada, ejecutá el empaquetador en PowerShell:
   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; .\package-env.ps1
   ```
   *Parámetros opcionales:*
   *   `-Compact`: Remueve documentación y archivos de idioma prescindibles de
       MSYS2 para reducir el peso.
   *   `-ConExtensiones`: Incluye los paquetes offline `.vsix` de las
       extensiones de VS Code.
   *   `-IncluirLibs`: Conserva las bibliotecas compiladas en `local/`.

El resultado será el archivo comprimido `portable-env-offline.zip`.

### Instalación en Equipos sin Internet

En la máquina destino sin conexión, copiá el archivo `portable-env-offline.zip`
y ejecutá desde PowerShell:

``` powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; .\install-offline.ps1
```
<!-- powershell -->

El script desempaquetará el toolchain y dejará los lanzadores listos para operar
sin requerir conexión alguna.

### Copias de Seguridad del Directorio Personal (`backup` / `restaurar`)

Para respaldar tu código, tareas y configuraciones sin arrastrar los binarios
pesados del compilador:

``` bash
# Genera un archivo ZIP fechado con tu HOME y manifiestos de librerías
backup

# Restaura un respaldo en una instalación fresca
restaurar respaldo_2026-09-03.zip
```
<!-- bash -->

---

## 11. Personalización de Terminal

Podés personalizar el aspecto visual de la consola según tus preferencias de
trabajo:

1. **Configuración de WezTerm (Windows):**
   *   Doble clic en `customize-terminal.bat` o ejecutá
       `.\customize-terminal.ps1`.
   *   Permite seleccionar temas de color populares (Tokyo Night, Dracula,
       Gruvbox, Nord, One Half Dark), ajustar la tipografía, regular la
       transparencia de fondo y activar o desactivar la barra de pestañas.

2. **Configuración del Banner de Bash:**
   *   Dentro de la consola, ejecutá `customize-bash.sh`.
   *   Permite definir mensajes de bienvenida, colores de texto o seleccionar
       frases informativas de programación al abrir cada sesión.

---

## 12. Preguntas Frecuentes y Solución de Problemas

:::{note} Error: «Execution_Policies» al ejecutar scripts en PowerShell

Windows restringe la ejecución de scripts no firmados por defecto. Si PowerShell
rechaza la ejecución de `setup.ps1` o `launch.ps1`, podés desbloquear
temporalmente el proceso agregando el prefijo:
``` powershell
Set-ExecutionPolicy Bypass -Scope Process -Force
```
<!-- powershell -->
Esto habilita la ejecución únicamente en la ventana actual de PowerShell sin
alterar las políticas globales de seguridad de Windows.

:::
<!-- {note} Error: «Execution_Policies» al ejecutar scripts en PowerShell -->

:::{note} Error de Git: «fatal: detected dubious ownership in repository»

Si abrís un repositorio alojado en una partición compartida o pendrive bajo
GNU/Linux o Windows con distinto propietario de usuario, Git puede bloquear las
operaciones por seguridad. Para autorizar el directorio dentro del entorno
portable, ejecutá:
``` bash
git config --global --add safe.directory '*'
```
<!-- bash -->

:::
<!-- {note} Error de Git: «fatal: detected dubious ownership in repository» -->

:::{note} Error de Python / pip en GNU/Linux: «externally-managed-environment (PEP 668)»

Las distribuciones modernas de Linux impiden la instalación directa con `pip` a
nivel sistema para prevenir conflictos con los paquetes del sistema operativo.
Al estar activada la sesión portable con `source linux/activate.sh`, utilizá la
herramienta ultrarrápida `uv`:
``` bash
uv pip install <paquete>
```
<!-- bash -->
O bien recurrí a entornos virtuales locales con `uv venv`.

:::
<!-- {note} Error de Python / pip en GNU/Linux: «externally-managed-environment (PEP 668)» -->

:::{note} ¿Cómo solicitar asistencia técnica a la cátedra ante errores del entorno?

Si experimentás fallas en compilación, paquetes corruptos o comportamientos
anómalos en el entorno, ejecutá en la terminal:
``` bash
diagnose-env.sh
```
<!-- bash -->
El comando generará el archivo `diagnose.log` con el detalle de versiones,
variables de entorno y estado del sistema. Adjuntá dicho archivo al abrir una
consulta en los canales de la cátedra para facilitar el diagnóstico.

:::
<!-- {note} ¿Cómo solicitar asistencia técnica a la cátedra ante errores del entorno? -->

