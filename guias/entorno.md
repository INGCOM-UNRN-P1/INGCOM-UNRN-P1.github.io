# Manual del Entorno de Desarrollo

Para simplificar los aspectos técnicos de las herramientas que seran utilizadas en la cátedra, hemos creado una caja de herramientas autocontenida con todo lo necesario para llevar la materia.

Aquí, describimos el funcionamiento, la arquitectura y las principales herramientas de la caja de herramientas.

---

## 0. Requisitos previos

- Windows 10/11 x64

o

- GNU/Linux

## 1. Casos de uso

Los casos de uso, son las situaciones que la cátedra ha considerado en la construcción de esta herramienta e incluyen:

### Estudiante sin Conectividad Constante (Desarrollo Offline)

Muchos estudiantes no cuentan con conexiones a Internet de banda ancha estables en sus hogares para descargar herramientas pesadas como Visual Studio Code, compiladores de C/C++, e intérpretes de Python, o necesitan instalar el entorno en múltiples equipos sin consumir datos repetidamente.

### Programación en Computadoras Compartidas (Laboratorios y Cybers)

Al programar en computadoras de laboratorios de la universidad o de terceros, los estudiantes a menudo se enfrentan a:
1. Restricciones de permisos (no poder instalar compiladores en el sistema host).
2. Pérdida de privacidad (dejar historiales de consola, llaves SSH privadas, tokens de GitHub o credenciales en el disco duro local).
3. Desconfiguración del entorno al cambiar de máquina en cada clase.

### Homogeneidad y Consistencia en la Cátedra ("En mi máquina funciona")

El docente y los estudiantes se enfrentan a diario con errores de compilación causados por sutiles diferencias de versiones entre sistemas operativos, variables de entorno globales en conflicto o compiladores preinstalados obsoletos. Esto consume valioso tiempo de clase en depurar problemas de configuración del host.

### Gestión Sencilla de Librerías en C para Principiantes

Instalar librerías externas de C (como `raylib`, `inih`, `Nuklear`, etc.) en sistemas Windows suele ser un proceso sumamente complejo que involucra compilar desde código fuente, enlazar manualmente rutas de cabeceras (`.h`) y archivos de biblioteca (`.a` / `.dll`), frustrando a alumnos iniciales de programación.


## 1. Arquitectura del Entorno

El entorno está diseñado para mantenerse estrictamente separado de lo que esté instalado en la computadora. A continuación se presenta el diagrama de bloques que detalla cómo se organizan y comunican sus componentes:

:::{figure} images/arquitectura_entorno.svg
:alt: Diagrama de arquitectura del entorno de desarrollo portable. Muestra los flujos de inicialización desde los lanzadores (launch.bat/launch.ps1), la configuración del PATH local apuntando a bin/ y clang64/bin, el aislamiento de datos de VS Code en la carpeta vscode/data, y la persistencia de las claves y configuraciones de usuario dentro del directorio personal home/.
:align: center
:width: 100%

Arquitectura del entorno de desarrollo portable y flujo de aislamiento de
variables.

:::
<!-- {figure} images/arquitectura_entorno.svg -->

En GNU/Linux, el entorno está pensado para:

* **No invasivo**: No modifica ningún archivo fuera del directorio del repositorio.
* **Sin privilegios elevados**: Nunca ejecuta gestores de paquetes con `sudo` ni requiere permisos de administrador.
* **Aislamiento de usuario**: Redirige `$HOME` hacia `home/` (o el nombre definido en `.env`), resguardando tus configuraciones personales, historial de Bash, llaves SSH y credenciales de Git dentro del entorno portable.
* **Limpieza absoluta**: La activación afecta únicamente la subshell o sesión actual de terminal; al invocar `deactivate` o cerrar la terminal, el sistema anfitrión queda en su estado original sin residuos.



## 2. Instalación

### En Windows

Podés iniciar la instalación descargando y ejecutando el script de inicio directamente desde internet. Abrí PowerShell en la carpeta donde quieras instalar el entorno y ejecutá:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; irm https://raw.githubusercontent.com/INGCOM-UNRN-P1/entorno/main/install.ps1 | iex
```

Este script descargará el instalador principal (`setup.ps1`) con el formato correcto y te indicará cómo ejecutarlo para completar la configuración del entorno portable.

### En GNU/Linux

Descarguen el repositorio y en el directorio `linux`

Dado que el entorno no instala paquetes a nivel de sistema operativo (ni tampoco hace uso de `sudo`), incluye un asistente de diagnóstico que audita las herramientas requeridas:

```bash
linux/bootstrap.sh
```

El script detecta automáticamente el gestor de paquetes de tu distribución (`apt`, `dnf`, `pacman`, `zypper`, `apk`) y clasifica el estado de:
* **Herramientas obligatorias (Core):** `git`, `gcc`, `g++`, `make`, `cmake`, `ninja`, `python3`, `pip`, `curl`.
* **Herramientas recomendadas (Toolchain ampliado):** `gdb`, `cppcheck`, `doxygen`, `gh` (GitHub CLI), `uv`.

Si falta alguna herramienta, `bootstrap.sh` imprime el comando exacto para que el usuario la instale en su distribución según corresponda (por ejemplo: `sudo apt install build-essential cmake ninja-build python3-pip curl`).


---

## 3. Inicialización y Arranque

Para arrancar el entorno tenés dos cargadores principales en la raíz del
directorio:

*   Ejecutá `launch.bat` desde el explorador de archivos.
*   Ejecutá `launch-vscode.bat` desde el explorador de archivos para abrir el entorno VSCode.

### Lanzar en GNU/Linux

En donde esté el repositorio del entorno;

```bash
source linux/activate.sh       # activa HOME portable + toolchain en el PATH
ayuda                          # guía rápida de comandos
deactivate                     # restaura tu sesión original
```

De ahí, `./home` será el nuevo `$HOME` mientras este activo.

---

## 4. Herramientas Especiales (`bin/`)

En la carpeta `bin/` tenés disponibles scripts de Bash agregados al `PATH` para
simplificar la administración del entorno. Ejecutalos directamente desde tu
terminal:

### Diagnóstico de Salud del Entorno
Si notás problemas con algún compilador o querés verificar el estado de las
herramientas, ejecutá:
``` bash
diagnose-env.sh
```
<!-- bash -->
Este script genera un informe técnico detallado en `diagnose.log` con las
versiones de Clang, CMake, Python, Git, Doxygen, los paquetes activos de pacman
y el contenido físico de la carpeta `bin/`. Adjunta este informe al pedir ayuda, así es más fácil detectar y descartar los problemas que puedan venir desde el entorno.

### Sincronización y Actualización de Paquetes
Para actualizar la base de datos de paquetes locales o instalar dependencias
faltantes, ejecutá:
``` bash
update-packages.sh
```
<!-- bash -->
El script realiza un `pacman -Syu` de forma segura dentro del subsistema
portable y consolida la instalación de herramientas clave.

### Configuración Aislada de Git y GitHub
Para registrar tu identidad de autor para commits de Git e iniciar sesión de
forma segura y portable en GitHub CLI (`gh`), ejecutá:
``` bash
configure-git.sh
```
<!-- bash -->
Tus credenciales de autenticación se guardarán de forma local en tu `home/`
portable y no afectarán a las credenciales globales del host.

### Instalador Automatizado de Librerías de C
Si necesitás compilar e instalar bibliotecas externas directamente desde
repositorios de GitHub en tu prefijo portable de `/clang64`, utilizá:
``` bash
install-lib.sh <usuario/repositorio_github> [rama_o_tag]
```
<!-- bash -->
El script descargará, compilará y copiará las cabeceras e instalables de manera
desatendida.
