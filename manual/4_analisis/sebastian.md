---
title: "Manual de Referencia: sebastian"
subtitle: "Sebastian — Analizador de Funciones Recursivas, Caso Base y Árboles de Llamadas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-sebastian)=
# Sebastian — Analizador de Funciones Recursivas, Caso Base y Árboles de Llamadas

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Detección estática y dinámica de funciones recursivas,
verificación formal de caso base, análisis de consumo de marcos de pila (Stack
Depth) y exportación de árboles de llamadas en ASCII/Mermaid.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-sebastian-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`sebastian`** forma parte del ecosistema oficial de software de
la cátedra. Su diseño sigue principios pedagógicos rigurosos:

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

(manual-sebastian-instalacion)=
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

### 2.2 Métodos de Instalación de `sebastian`

Podés instalar `sebastian` mediante cualquiera de los siguientes métodos
estándar:

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

La interfaz CLI de `sebastian` cuenta con autocompletado nativo para comandos,
flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
sebastian --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
sebastian doctor

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

(manual-sebastian-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en
`sebastian`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `sebastian trace src/recursivo.c` | Detecta funciones recursivas y verifica la presencia de caso base. |
| `sebastian tree src/arbol.c --function recorrer` | Dibuja el árbol de llamadas recursivas en ASCII o Mermaid. |
| `sebastian stack-profile -- ./bin/fibonacci 10` | Mide la profundidad máxima del Stack alcanzada en runtime. |
| `sebastian doctor` | Verifica analizadores de AST y perfiles de pila. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-sebastian-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Función recursiva analizada por Sebastian
int factorial(int n) {
    if (n <= 1) { // Caso base verificado por Sebastian
        return 1;
    }
    return n * factorial(n - 1); // Llamada recursiva con reducción de tamaño
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
sebastian trace src/recursivo.c

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
[✓] SEBASTIAN RECURSION ANALYSIS: 'factorial()' en src/recursivo.c:
    • Tipo de recursión: Recursión lineal simple (no terminal).
    • Caso Base: Detectado en línea 2 ('if (n <= 1) return 1;').
    • Condición de Convergencia: Parámetro 'n' decrece hacia el caso base ('n - 1').
    • Profundidad de Stack estimada: O(N) marcos de pila (aprox. 32 bytes por marco).

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-sebastian-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`sebastian`** resolviendo los siguientes
ejercicios:

::::{exercise} Desafío 1: Detección de Recursión Infinita sin Caso Base
:label: sebastian-desafio-1
Analizar una función recursiva defectuosa y encontrar por qué produce Stack
Overflow.

**Instrucción de ejecución:**
``` bash
sebastian trace src/bug_recursivo.c
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Detección de Recursión Infinita sin Caso Base -->

::::{solution} sebastian-desafio-1

``` bash
sebastian trace src/bug_recursivo.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} sebastian-desafio-1 -->

::::{exercise} Desafío 2: Renderizado de Árbol de Llamadas de Fibonacci
:label: sebastian-desafio-2
Visualizar el árbol de ramificación de Fibonacci en Mermaid.

**Instrucción de ejecución:**
``` bash
sebastian tree src/fib.c --function fib --format mermaid
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Renderizado de Árbol de Llamadas de Fibonacci -->

::::{solution} sebastian-desafio-2

``` bash
sebastian tree src/fib.c --function fib --format mermaid
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} sebastian-desafio-2 -->

::::{exercise} Desafío 3: Optimización a Recursión de Cola (Tail Recursion)
:label: sebastian-desafio-3
Transformar una función recursiva para permitir optimización TCO por el
compilador.

**Instrucción de ejecución:**
``` bash
sebastian trace src/tail_rec.c
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Optimización a Recursión de Cola (Tail Recursion) -->

::::{solution} sebastian-desafio-3

``` bash
sebastian trace src/tail_rec.c
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} sebastian-desafio-3 -->

---

(manual-sebastian-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `sebastian` de forma automática a tu flujo de desarrollo, agregá
la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-sebastian:
	@echo "=== Ejecutando verificación con sebastian ==="
	sebastian check src/ include/

.PHONY: check-sebastian

````
<!-- {code-block} makefile -->

Ejecutá `make check-sebastian` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-sebastian-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`sebastian`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C AST Recursion Matcher + Stack Frame Size
  Evaluator + Mermaid Call Tree Generator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-sebastian-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`sebastian`** forma parte del
pipeline integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    SRC[Código C Recursivo] --> SEB[Sebastian: Análisis de Recursión]
    SEB -->|Verificación de Caso Base| AST[Tree-Sitter C Engine]
    SEB -->|Árbol de Llamadas Mermaid| MYST[Myst-Tools: Apuntes y Guías]
    SEB -->|Profundidad de Stack| BSH[Bishop: Inspector de Memoria]
    SEB -->|Alerta de Stack Overflow| HAL[Hal: Forense de Crashes]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Funciones recursivas en C` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `bishop (visualización de marcos)`
- `myst-tools (diagramas de árbol)`
- `hal (mitigación de stack overflow)` | Informes Markdown, diagnósticos Rich,
  JSON, actas |
| **Sincronización** | `bishop`, `giger`, `hal` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `sebastian` con otras herramientas del ecosistema en una única
línea de comando:

````{code-block} bash
# Pipeline de integración típico
sebastian tree src/recursivo.c --format mermaid -o arbol.md

````
<!-- {code-block} bash -->

---

(manual-sebastian-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `sebastian`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
