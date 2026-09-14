---
title: "Manual de Referencia: tetsuo"
subtitle: "Tetsuo — Traductor y Explicador Pedagógico en Español de Sanitizers ASan/UBSan"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-tetsuo)=
# Tetsuo — Traductor y Explicador Pedagógico en Español de Sanitizers ASan/UBSan

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Traducción de informes crípticos generados por AddressSanitizer (ASan) y UndefinedBehaviorSanitizer (UBSan) a explicaciones claras en español rioplatense, con diagramas de memoria y sugerencias directas.
````

---

(manual-tetsuo-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`tetsuo`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-tetsuo-instalacion)=
## 2. Instalación y Verificación del Entorno

````{important}
Para proveer la reproducibilidad técnica de la cátedra, verificá instalar las dependencias nativas del sistema operativo antes de instalar el paquete Python.
````

### 2.1 Requisitos Previos del Sistema

Instalá los paquetes del sistema requeridos según tu distribución o entorno:

````{tab-set}
```{tab-item} Ubuntu / Debian
sudo apt update && sudo apt install -y \
    build-essential \
    gcc \
    gdb \
    valgrind \
    clang-format \
    libclang-dev \
    bubblewrap \
    typst \
    graphviz \
    python3-pip \
    python3-venv
```

```{tab-item} Arch Linux / Manjaro
sudo pacman -S --needed \
    base-devel \
    gcc \
    gdb \
    valgrind \
    clang \
    bubblewrap \
    typst \
    graphviz \
    python-pip \
    uv
```

```{tab-item} Fedora / RHEL
sudo dnf install -y \
    gcc \
    gcc-c++ \
    gdb \
    valgrind \
    clang-tools-extra \
    bubblewrap \
    typst \
    graphviz \
    python3-pip
```

```{tab-item} macOS (Homebrew)
brew install gcc gdb clang-format typst graphviz uv
```

```{tab-item} Windows (MSYS2 / WSL2)
# En WSL2 (Ubuntu): utilizar los paquetes de Ubuntu/Debian arriba.
# En MSYS2 MINGW64:
pacman -S --needed \
    mingw-w64-x86_64-gcc \
    mingw-w64-x86_64-gdb \
    mingw-w64-x86_64-clang-tools-extra
```
````

---

### 2.2 Métodos de Instalación de `tetsuo`

Podés instalar `tetsuo` mediante cualquiera de los siguientes métodos estándar:

````{tab-set}
```{tab-item} uv tool (Recomendado)
# Instalación aislada de alta velocidad con uv
uv tool install . --editable

# O instalar todo el ecosistema de herramientas de la cátedra en lote:
source ./install_tools.sh
```

```{tab-item} pip / venv
# Crear y activar un entorno virtual
python3 -m venv .venv
source .venv/bin/activate

# Instalar en modo editable para desarrollo
pip install -e .
```

```{tab-item} pipx
# Instalación global aislada en tu PATH
pipx install --editable .
```
````

---

### 2.3 Autocompletado en la Shell

La interfaz CLI de `tetsuo` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
tetsuo --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
tetsuo doctor
````

#### Comprobaciones Ejecutadas por el Diagnóstico:
- **Compilador C**: Verifica disponibilidad de `gcc` o `clang` con soporte de estándares C11 y C23.
- **Depurador y Core Dumps**: Comprueba que `gdb` esté instalado y que `ulimit -c` permita generación de core dumps.
- **Herramientas de Memoria**: Valida la presencia de `valgrind` y librerías `libasan`/`libubsan`.
- **Formateo y Estilo**: Verifica el binario `clang-format` (versión 16+).
- **Sandboxing de Kernel**: Audita permisos no privilegiados de `bwrap` (Bubblewrap namespaces).
- **Generador de Tipografía y Documentos**: Comprueba `typst` ($\ge 0.11$) y `dot` (Graphviz).

#### Matriz de Resolución de Problemas:

| Síntoma / Alerta de `doctor` | Causa Raíz | Acción Correctiva |
| :--- | :--- | :--- |
| `❌ gcc / clang no encontrado` | Toolchain C faltante | Instalá `build-essential` o `base-devel`. |
| `❌ bwrap permisos insuficientes` | User namespaces desactivados | Habilitá `sysctl kernel.unprivileged_userns_clone=1`. |
| `❌ typst no disponible` | Motor de PDF faltante | Descargá Typst vía `cargo install typst-cli` o gestor de paquetes. |
| `❌ gdb no responde` | GDB sin interfaz MI/Python | Reinstalá `gdb` completo desde el repositorio oficial. |

(manual-tetsuo-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `tetsuo`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `tetsuo run -- ./bin/programa_con_asan` | Ejecuta el binario instrumentado con sanitizers y traduce la salida en tiempo real. |
| `tetsuo translate < asan.log` | Traduce un reporte de error de ASan guardado en un archivo de texto. |
| `tetsuo compile src/*.c -o ./bin/instrumentado` | Compila el código inyectando flags `-fsanitize=address,undefined`. |
| `tetsuo doctor` | Comprueba que GCC/Clang tengan soporte para libasan y libubsan. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-tetsuo-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdlib.h>

int main(void) {
    int *vec = malloc(sizeof(int) * 4);
    vec[4] = 42; // Heap-buffer-overflow (índice 4 en tamaño 4: fuera de rango)
    free(vec);
    return 0;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
tetsuo run -- ./bin/programa_con_asan
````

### Salida Obtenida en Consola

````{code-block} text
🚨 DIAGNÓSTICO TETSUO: Heap-Buffer-Overflow (Desborde de Memoria en el Heap)
Ubicación: src/main.c:5 en función 'main()'
Dirección afectada: 0x602000000020 (1 byte después del bloque reservado)

📊 MAPA DE MEMORIA ASAN:
  Bloque asignado: [ 0x602000000010 - 0x60200000001f ] (16 bytes = 4 enteros)
  Intento de escritura en: 0x602000000020 [ZONA PROHIBIDA / REDZONE]

💡 EXPLICACIÓN DIDÁCTICA:
  Reservaste memoria para 4 enteros (índices 0 a 3), pero intentaste escribir en 'vec[4]'.
  En C los arreglos comienzan en el índice 0, por lo que el índice 4 está fuera del bloque permitido.

🔧 SOLUCIÓN:
  verificá que tus lazos y accesos cumplan '0 <= indice < 4'.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-tetsuo-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`tetsuo`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Traducción de Heap-Use-After-Free
:label: tetsuo-desafio-1
Ejecutar un código que accede a memoria liberada y analizar la traducción de Tetsuo.

**Instrucción de ejecución:**
```bash
tetsuo run -- ./bin/use_after_free
```
````

````{solution} tetsuo-desafio-1
```bash
tetsuo run -- ./bin/use_after_free
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Diagnóstico de Stack-Buffer-Overflow
:label: tetsuo-desafio-2
Identificar desbordes en variables locales del stack.

**Instrucción de ejecución:**
```bash
tetsuo run -- ./bin/stack_overflow
```
````

````{solution} tetsuo-desafio-2
```bash
tetsuo run -- ./bin/stack_overflow
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Compilación Instrumentada Rápida
:label: tetsuo-desafio-3
Compilar con sanitizers completos mediante el comando asistido.

**Instrucción de ejecución:**
```bash
tetsuo compile src/main.c -o bin/debug_app
```
````

````{solution} tetsuo-desafio-3
```bash
tetsuo compile src/main.c -o bin/debug_app
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-tetsuo-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `tetsuo` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-tetsuo:
	@echo "=== Ejecutando verificación con tetsuo ==="
	tetsuo check src/ include/

.PHONY: check-tetsuo
````

Ejecutá `make check-tetsuo` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-tetsuo-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`tetsuo`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `LLVM AddressSanitizer / UndefinedBehaviorSanitizer Parser + Shadow Memory Mapper + Spanish Pedagogical Translator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-tetsuo-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`tetsuo`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    DAE[Daedalus: Compilador con Sanitizers] --> BIN[Binario + libasan/libubsan]
    BIN -->|Ejecución con Fuga o UB| ASAN[AddressSanitizer Engine]
    ASAN -->|Reporte Críptico en Inglés| TET[Tetsuo: Traductor Pedagógico]
    TET -->|Mapa de Shadow Memory| TERM[Terminal Estudiante (Español)]
    TET -->|Sección de Sanitizers| DRD[Dredd: Informe alumno_rN.md]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Salidas de error de ASan/UBSan` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `hal (correlación de fallas)`
- `dredd (informe en alumno_rN.md)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `daedalus`, `hal`, `nostromo`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `tetsuo` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
daedalus compile src/*.c -fsanitize=address,undefined -o bin/app && tetsuo run -- ./bin/app
````

---

(manual-tetsuo-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `tetsuo` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
