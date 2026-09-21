---
title: "Manual de Referencia: bishop"
subtitle: "Bishop — Visualizador Pedagógico de Memoria Stack & Heap en ASCII y Mermaid"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-bishop)=
# Bishop — Visualizador Pedagógico de Memoria Stack & Heap en ASCII y Mermaid

:::{note} Resumen Técnico del Satélite

**Rol en el ecosistema:** Inspección dinámica de memoria en C, renderizando
marcos de pila (Stack Frames), variables locales, punteros y bloques del Heap.

:::
<!-- {note} Resumen Técnico del Satélite -->

---

(manual-bishop-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`bishop`** forma parte del ecosistema oficial de software de la
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

(manual-bishop-instalacion)=
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

### 2.2 Métodos de Instalación de `bishop`

Podés instalar `bishop` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `bishop` cuenta con autocompletado nativo para comandos,
flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
bishop --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
bishop doctor

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

(manual-bishop-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `bishop`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `bishop trace -- ./bin/programa` | Ejecuta el binario bajo GDB y dibuja la memoria en cada instrucción. |
| `bishop trace --format mermaid -- ./bin/programa` | Exporta el estado de memoria a diagrama Mermaid para informes. |
| `bishop inspect <pid>` | Inspecciona la memoria de un proceso en ejecución. |
| `bishop snapshot -o memoria.txt -- ./bin/programa` | Guarda una captura completa del mapa de memoria en ASCII. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-bishop-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdlib.h>

void f(int a) {
    int *dinamico = malloc(sizeof(int) * 2);
    dinamico[0] = a;
    dinamico[1] = a * 2;
    // Inspección en este punto
    free(dinamico);
}

int main(void) {
    int x = 42;
    f(x);
    return 0;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
bishop trace -- ./bin/programa

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
┌────────────────────────────────────────────────────────┐
│ STACK FRAME: f (ret 0x00401180)                        │
│ ├─ a: [ 42 ] @ 0x7fffffffe340                          │
│ └─ dinamico: [ 0x0055555556b2a0 ] @ 0x7fffffffe348    │
└───────────────────────┬────────────────────────────────┘
                        │
                        ▼ (Heap Allocation: 8 bytes)
┌────────────────────────────────────────────────────────┐
│ HEAP CHUNK @ 0x0055555556b2a0                          │
│ [ 0 ]: 42  |  [ 1 ]: 84                                │
└────────────────────────────────────────────────────────┘

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-bishop-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`bishop`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Paso por Referencia vs Paso por Valor
:label: bishop-desafio-1
Escribir `swap(int *a, int *b)` y observar los marcos de pila en Bishop.

**Instrucción de ejecución:**
``` bash
bishop trace -- ./bin/swap_test
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Paso por Referencia vs Paso por Valor -->

::::{solution} bishop-desafio-1

``` bash
bishop trace -- ./bin/swap_test
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} bishop-desafio-1 -->

::::{exercise} Desafío 2: Detección de Dangling Pointer
:label: bishop-desafio-2
Inspeccionar un puntero tras llamar a free() sin asignarle NULL.

**Instrucción de ejecución:**
``` bash
bishop trace -- ./bin/dangling_test
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Detección de Dangling Pointer -->

::::{solution} bishop-desafio-2

``` bash
bishop trace -- ./bin/dangling_test
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} bishop-desafio-2 -->

::::{exercise} Desafío 3: Diagrama Mermaid de Lista Enlazada
:label: bishop-desafio-3
Generar diagrama de una lista de 3 nodos en el Heap.

**Instrucción de ejecución:**
``` bash
bishop trace --format mermaid -o memoria.md -- ./bin/test_lista
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Diagrama Mermaid de Lista Enlazada -->

::::{solution} bishop-desafio-3

``` bash
bishop trace --format mermaid -o memoria.md -- ./bin/test_lista
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} bishop-desafio-3 -->

---

(manual-bishop-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `bishop` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-bishop:
	@echo "=== Ejecutando verificación con bishop ==="
	bishop check src/ include/

.PHONY: check-bishop

````
<!-- {code-block} makefile -->

Ejecutá `make check-bishop` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-bishop-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`bishop`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `GDB/MI Machine Interface + DWARF Symbol Parser + Rich
  Terminal Tables + Mermaid JS Engine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-bishop-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`bishop`** forma parte del
pipeline integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    DAE[Daedalus: Compilador -g3] -->|Binario con DWARF| BSH[Bishop: Inspector
    de Memoria]
    BSH -->|Inspección Stack & Heap| GDB[GDB/MI Protocol]
    BSH -->|Diagramas ASCII| TERM[Terminal del Estudiante]
    BSH -->|Diagramas Mermaid| MYST[Myst-Tools: Apuntes y Guías]
    BSH -->|Contexto de Punteros| HAL[Hal: Forense de Crashes]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `daedalus (binarios C con símbolos de depuración -g3)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `hal (trazas de memoria)`
- `deckard (diagramas para enunciados)`
- `myst-tools (apuntes)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `sebastian`, `brett`, `hal` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `bishop` con otras herramientas del ecosistema en una única
línea de comando:

````{code-block} bash
# Pipeline de integración típico
daedalus compile src/main.c -g3 -o bin/app && bishop trace --format mermaid -o memoria.md -- ./bin/app

````
<!-- {code-block} bash -->

---

(manual-bishop-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `bishop`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
