---
title: "Manual de Referencia: hal"
subtitle: "Hal — Asistente Forense de Core Dumps y Análisis Post-Mortem de Segfaults en C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-hal)=
# Hal — Asistente Forense de Core Dumps y Análisis Post-Mortem de Segfaults en C

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Diagnóstico forense automático de caídas fatales
(SIGSEGV, SIGABRT, SIGFPE), inspección de core dumps, extracción de stack traces
con GDB y explicación didáctica en español rioplatense.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-hal-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`hal`** forma parte del ecosistema oficial de software de la
cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO
   C (C11/C23), en el modelo de memoria del sistema o en convenciones
   arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción
   técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la
   entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo
   discrepancias subjetivas en la evaluación.

---

(manual-hal-instalacion)=
## 2. Instalación y Verificación del Entorno

::::{important}

Para proveer la reproducibilidad técnica de la cátedra, verificá instalar las
dependencias nativas del sistema operativo antes de instalar el paquete Python.

::::
<!-- {important} -->

### 2.1 Requisitos Previos del Sistema

Instalá los paquetes del sistema requeridos según tu distribución o entorno:

::::{tab-set}

:::{tab-item} Ubuntu / Debian

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

:::
<!-- {tab-item} Ubuntu / Debian -->

:::{tab-item} Arch Linux / Manjaro

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

:::
<!-- {tab-item} Arch Linux / Manjaro -->

:::{tab-item} Fedora / RHEL

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

:::
<!-- {tab-item} Fedora / RHEL -->

:::{tab-item} macOS (Homebrew)

brew install gcc gdb clang-format typst graphviz uv

:::
<!-- {tab-item} macOS (Homebrew) -->

:::{tab-item} Windows (MSYS2 / WSL2)

# En WSL2 (Ubuntu): utilizar los paquetes de Ubuntu/Debian arriba.
# En MSYS2 MINGW64:
pacman -S --needed \
    mingw-w64-x86_64-gcc \
    mingw-w64-x86_64-gdb \
    mingw-w64-x86_64-clang-tools-extra

:::
<!-- {tab-item} Windows (MSYS2 / WSL2) -->

::::
<!-- {tab-set} -->

---

### 2.2 Métodos de Instalación de `hal`

Podés instalar `hal` mediante cualquiera de los siguientes métodos estándar:

::::{tab-set}

:::{tab-item} uv tool (Recomendado)

# Instalación aislada de alta velocidad con uv
uv tool install . --editable

# O instalar todo el ecosistema de herramientas de la cátedra en lote:
source ./install_tools.sh

:::
<!-- {tab-item} uv tool (Recomendado) -->

:::{tab-item} pip / venv

# Crear y activar un entorno virtual
python3 -m venv .venv
source .venv/bin/activate

# Instalar en modo editable para desarrollo
pip install -e .

:::
<!-- {tab-item} pip / venv -->

:::{tab-item} pipx

# Instalación global aislada en tu PATH
pipx install --editable .

:::
<!-- {tab-item} pipx -->

::::
<!-- {tab-set} -->

---

### 2.3 Autocompletado en la Shell

La interfaz CLI de `hal` cuenta con autocompletado nativo para comandos, flags y
archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
hal --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
hal doctor

````
<!-- {code-block} bash -->

#### Comprobaciones Ejecutadas por el Diagnóstico:
- **Compilador C**: Verifica disponibilidad de `gcc` o `clang` con soporte de
  estándares C11 y C23.
- **Depurador y Core Dumps**: Comprueba que `gdb` esté instalado y que `ulimit
  -c` permita generación de core dumps.
- **Herramientas de Memoria**: Valida la presencia de `valgrind` y librerías
  `libasan`/`libubsan`.
- **Formateo y Estilo**: Verifica el binario `clang-format` (versión 16+).
- **Sandboxing de Kernel**: Audita permisos no privilegiados de `bwrap`
  (Bubblewrap namespaces).
- **Generador de Tipografía y Documentos**: Comprueba `typst` ($\ge 0.11$) y
  `dot` (Graphviz).

#### Matriz de Resolución de Problemas:

| Síntoma / Alerta de `doctor` | Causa Raíz | Acción Correctiva |
| :--- | :--- | :--- |
| `❌ gcc / clang no encontrado` | Toolchain C faltante | Instalá `build-essential` o `base-devel`. |
| `❌ bwrap permisos insuficientes` | User namespaces desactivados | Habilitá `sysctl kernel.unprivileged_userns_clone=1`. |
| `❌ typst no disponible` | Motor de PDF faltante | Descargá Typst vía `cargo install typst-cli` o gestor de paquetes. |
| `❌ gdb no responde` | GDB sin interfaz MI/Python | Reinstalá `gdb` completo desde el repositorio oficial. |

(manual-hal-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `hal`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `hal inspect ./bin/programa [args]` | Ejecuta el binario, captura el crash y genera el diagnóstico. |
| `hal core ./bin/programa core.dump` | Analiza post-mortem un archivo core dump generado por el kernel. |
| `hal valgrind ./bin/programa` | Ejecuta Valgrind y traduce las fugas y accesos inválidos. |
| `hal doctor` | Verifica la configuración de límites de core dump (`ulimit -c`) y GDB. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-hal-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>

typedef struct {
    int id;
    char *nombre;
} t_usuario;

void imprimir_usuario(t_usuario *u) {
    printf("Usuario: %s (ID: %d)\n", u->nombre, u->id); // Crash si u es NULL o nombre es NULL
}

int main(void) {
    t_usuario *u = NULL;
    imprimir_usuario(u);
    return 0;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
hal inspect ./bin/programa [args]

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
💥 SEÑAL FATAL DETECTADA: SIGSEGV (Violación de Segmento)
Ubicación: src/main.c:9 en función 'imprimir_usuario()'
Dirección de memoria inválida: 0x0000000000000004 (SEGV_MAPERR)

📋 STACK TRACE FORENSE:
  #0  imprimir_usuario (u=0x0) at src/main.c:9
  #1  main () at src/main.c:14

💡 DIAGNÓSTICO PEDAGÓGICO DE HAL:
  Intentaste acceder al campo 'u->id' a través de un puntero NULO (u == NULL).
  El procesador intentó leer la dirección 0x4 (desplazamiento del campo dentro del struct) que no pertenece al espacio de memoria de tu programa.

🔧 ACCIÓN RECOMENDADA:
  Agregá una verificación defensiva al inicio de 'imprimir_usuario':
  if (u == NULL || u->nombre == NULL) { return; }

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-hal-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`hal`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Diagnóstico de Puntero Nulo
:label: hal-desafio-1
Ejecutar un binario con crash por NULL y revisar el stack trace pedagógico.

**Instrucción de ejecución:**
``` bash
hal inspect ./bin/crash_null
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Diagnóstico de Puntero Nulo -->

::::{solution} hal-desafio-1

``` bash
hal inspect ./bin/crash_null
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} hal-desafio-1 -->

::::{exercise} Desafío 2: Análisis de Core Dump Post-Mortem
:label: hal-desafio-2
Inspeccionar un core dump generado en un servidor sin volver a compilar.

**Instrucción de ejecución:**
``` bash
hal core ./bin/servidor /var/cores/core.1234
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Análisis de Core Dump Post-Mortem -->

::::{solution} hal-desafio-2

``` bash
hal core ./bin/servidor /var/cores/core.1234
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} hal-desafio-2 -->

::::{exercise} Desafío 3: Traducción de Acceso Fuera de Límites (Buffer Overflow)
:label: hal-desafio-3
Diagnosticar un segfault provocado por escribir en `vec[1000000]`.

**Instrucción de ejecución:**
``` bash
hal inspect ./bin/crash_bounds
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Traducción de Acceso Fuera de Límites (Buffer Overflow) -->

::::{solution} hal-desafio-3

``` bash
hal inspect ./bin/crash_bounds
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} hal-desafio-3 -->

---

(manual-hal-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `hal` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-hal:
	@echo "=== Ejecutando verificación con hal ==="
	hal check src/ include/

.PHONY: check-hal

````
<!-- {code-block} makefile -->

Ejecutá `make check-hal` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-hal-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`hal`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `GDB Batch Processor + Linux Core Dump ELF Parser +
  DWARF Variable Inspector + Rich Diagnostic Formatter`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-hal-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`hal`** forma parte del pipeline
integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    NOS[Nostromo / Vasquez: Crash SIGSEGV] --> HAL[Hal: Asistente Forense]
    HAL -->|Inspección Post-Mortem| GDB[GDB Batch / Core Dumps]
    HAL -->|Stack Trace + Registros| DWARF[Símbolos DWARF]
    HAL -->|Explicación Pedagógica| TERM[Terminal Estudiante]
    HAL -->|Sección de Crash Markdown| DRD[Dredd: Informe alumno_rN.md]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios con crash, core dumps, señales SIGSEGV/SIGABRT, inyecciones Vasquez` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (diagnóstico en alumno_rN.md)`
- `Estudiante (diagnóstico en terminal)` | Informes Markdown, diagnósticos Rich,
  JSON, actas |
| **Sincronización** | `vasquez`, `daedalus`, `nostromo`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `hal` con otras herramientas del ecosistema en una única línea
de comando:

````{code-block} bash
# Pipeline de integración típico
vasquez inject --target ./bin/app --fail-malloc-at 1 | hal inspect --stdin

````
<!-- {code-block} bash -->

---

(manual-hal-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `hal`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
