---
title: "Manual de Referencia: ferro"
subtitle: "Ferro — Perfilador de Rendimiento Algorítmico, Caché y Contadores de Hardware en C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-ferro)=
# Ferro — Perfilador de Rendimiento Algorítmico, Caché y Contadores de Hardware en C

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Medición de métricas de rendimiento en tiempo de
ejecución: ciclos de CPU, instrucciones ejecutadas (IPC), aciertos y fallos de
caché L1/L2/L3 y predicción de saltos.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-ferro-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`ferro`** forma parte del ecosistema oficial de software de la
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

(manual-ferro-instalacion)=
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

### 2.2 Métodos de Instalación de `ferro`

Podés instalar `ferro` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `ferro` cuenta con autocompletado nativo para comandos, flags
y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
ferro --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
ferro doctor

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

(manual-ferro-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `ferro`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `ferro profile -- ./bin/programa` | Mide ciclos, tiempo de CPU y fallos de caché durante la ejecución. |
| `ferro compare --bin1 ./bin/opt --bin2 ./bin/naive` | Compara el rendimiento de dos algoritmos lado a lado. |
| `ferro cache-sim -- ./bin/matriz_mult` | Simula el comportamiento de las líneas de caché L1 (64 bytes). |
| `ferro doctor` | Verifica soporte de contadores de hardware `perf` o `valgrind --tool=cachegrind`. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-ferro-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#define N 1024
int matriz[N][N];

// Recorrido por filas (Cache-Friendly: acceso contiguo)
void recorrido_filas(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = 1;
}

// Recorrido por columnas (Cache-Unfriendly: saltos de N * 4 bytes)
void recorrido_columnas(void) {
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            matriz[i][j] = 1;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
ferro profile -- ./bin/programa

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
PERFIL FERRO: recorrido_filas vs recorrido_columnas (N = 1024)
┌──────────────────────────┬────────────────────┬────────────────────┬───────────┐
│ Métrica                  │ Recorrido Filas    │ Recorrido Columnas │ Ganancia  │
├──────────────────────────┼────────────────────┼────────────────────┼───────────┤
│ Tiempo de CPU            │ 1.82 ms            │ 14.30 ms           │ 7.85x     │
│ Fallos de Caché L1 (D1)  │ 16,384 (1.5%)      │ 1,048,576 (99.8%)  │ 64.0x     │
│ Instrucciones / Ciclo    │ 2.45 IPC           │ 0.38 IPC           │ 6.44x     │
└──────────────────────────┴────────────────────┴────────────────────┴───────────┘

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-ferro-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`ferro`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Optimización de Recorrido de Matrices
:label: ferro-desafio-1
Medir la tasa de fallos de caché L1 al transponer una matriz.

**Instrucción de ejecución:**
``` bash
ferro profile -- ./bin/transposicion
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Optimización de Recorrido de Matrices -->

::::{solution} ferro-desafio-1

``` bash
ferro profile -- ./bin/transposicion
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} ferro-desafio-1 -->

::::{exercise} Desafío 2: Comparativa de Algoritmos de Ordenamiento
:label: ferro-desafio-2
Comparar QuickSort vs BubbleSort midiendo instrucciones y saltos mal predichos.

**Instrucción de ejecución:**
``` bash
ferro compare --bin1 ./bin/quicksort --bin2 ./bin/bubblesort
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Comparativa de Algoritmos de Ordenamiento -->

::::{solution} ferro-desafio-2

``` bash
ferro compare --bin1 ./bin/quicksort --bin2 ./bin/bubblesort
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} ferro-desafio-2 -->

::::{exercise} Desafío 3: Simulación de Localidad Espacial
:label: ferro-desafio-3
Inspeccionar cómo el empaquetamiento de structs reduce accesos a memoria.

**Instrucción de ejecución:**
``` bash
ferro cache-sim -- ./bin/test_structs
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Simulación de Localidad Espacial -->

::::{solution} ferro-desafio-3

``` bash
ferro cache-sim -- ./bin/test_structs
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} ferro-desafio-3 -->

---

(manual-ferro-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `ferro` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-ferro:
	@echo "=== Ejecutando verificación con ferro ==="
	ferro check src/ include/

.PHONY: check-ferro

````
<!-- {code-block} makefile -->

Ejecutá `make check-ferro` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-ferro-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`ferro`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Linux Perf Events Subsystem + Valgrind Cachegrind
  Simulator + CPU Hardware Counters`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-ferro-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`ferro`** forma parte del pipeline
integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    BIN[Binario C Optimizado] --> FRR[Ferro: Perfilador de Hardware]
    FRR -->|Lectura de Contadores| PERF[Linux Perf / Cachegrind]
    FRR -->|Fallos L1/L2/L3| BRT[Brett: Auditor de Padding]
    FRR -->|Branch Misses| RCH[Rachel: Desensamblador Switch]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios compilados con símbolos de depuración` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `brett (evaluación de structs)`
- `rachel (impacto de saltos)` | Informes Markdown, diagnósticos Rich, JSON,
  actas |
| **Sincronización** | `brett`, `rachel`, `tyrell` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `ferro` con otras herramientas del ecosistema en una única línea
de comando:

````{code-block} bash
# Pipeline de integración típico
ferro profile -- ./bin/algoritmo_opt

````
<!-- {code-block} bash -->

---

(manual-ferro-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `ferro`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
