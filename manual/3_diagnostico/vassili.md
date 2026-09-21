---
title: "Manual de Referencia: vassili"
subtitle: "Vassili — Motor de Mutation Testing en C para Evaluación de Calidad de Suites de Pruebas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-vassili)=
# Vassili — Motor de Mutation Testing en C para Evaluación de Calidad de Suites de Pruebas

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Evaluación de la efectividad de los tests unitarios
mediante la inyección de mutaciones deliberadas en el código fuente (cambio de
operadores `+` por `-`, `<` por `<=`, constantes) para verificar si los tests
fallan.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-vassili-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`vassili`** forma parte del ecosistema oficial de software de
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

(manual-vassili-instalacion)=
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

### 2.2 Métodos de Instalación de `vassili`

Podés instalar `vassili` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `vassili` cuenta con autocompletado nativo para comandos,
flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
vassili --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
vassili doctor

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

(manual-vassili-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `vassili`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `vassili mutate src/calculadora.c --tests ./bin/test_suite` | Aplica operadores de mutación y calcula el Mutation Score. |
| `vassili report --format html -o reporte_mutaciones.html` | Exporta el informe visual de mutantes vivos y muertos. |
| `vassili list-mutators` | Lista todos los operadores de mutación disponibles (AOR, ROR, LCR, UOI). |
| `vassili doctor` | Verifica compiladores y suites de pruebas. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-vassili-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Código original
int maximo(int a, int b) {
    if (a > b) return a;
    return b;
}

// Mutante #1 generado por Vassili (Operador Relacional ROR: '>' cambiado por '>=')
// Si tus tests no prueban el caso 'a == b', este mutante SOBREVIVE.
int maximo_mutante1(int a, int b) {
    if (a >= b) return a;
    return b;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
vassili mutate src/calculadora.c --tests ./bin/test_suite

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
MUTATION TESTING REPORT (Vassili):
┌───────────────────────────┬────────┬───────────┐
│ Estado de Mutantes        │ Cant   │ Porcentaje│
├───────────────────────────┼────────┼───────────┤
│ Mutantes Asesinados (Killed)│ 42   │ 87.5%     │
│ Mutantes Vivos (Survived) │ 6      │ 12.5%     │
│ Mutantes Inválidos        │ 0      │ 0.0%      │
└───────────────────────────┴────────┴───────────┘
🎯 Mutation Score: 87.5% (Se recomienda > 80% para aprobación docente).

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-vassili-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`vassili`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Cálculo de Mutation Score
:label: vassili-desafio-1
Evaluar la suite de pruebas unitarias contra mutaciones en `src/tda_cola.c`.

**Instrucción de ejecución:**
``` bash
vassili mutate src/tda_cola.c --tests ./bin/test_cola
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Cálculo de Mutation Score -->

::::{solution} vassili-desafio-1

``` bash
vassili mutate src/tda_cola.c --tests ./bin/test_cola
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} vassili-desafio-1 -->

::::{exercise} Desafío 2: Identificación de Mutantes Vivos
:label: vassili-desafio-2
Descubrir qué casos borde no están siendo testeados por la suite.

**Instrucción de ejecución:**
``` bash
vassili report --survived-only
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Identificación de Mutantes Vivos -->

::::{solution} vassili-desafio-2

``` bash
vassili report --survived-only
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} vassili-desafio-2 -->

::::{exercise} Desafío 3: Generación de Informe HTML de Calidad
:label: vassili-desafio-3
Exportar el informe gráfico con diffs de mutantes para revisión docente.

**Instrucción de ejecución:**
``` bash
vassili report --format html -o mutaciones.html
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Generación de Informe HTML de Calidad -->

::::{solution} vassili-desafio-3

``` bash
vassili report --format html -o mutaciones.html
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} vassili-desafio-3 -->

---

(manual-vassili-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `vassili` de forma automática a tu flujo de desarrollo, agregá
la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-vassili:
	@echo "=== Ejecutando verificación con vassili ==="
	vassili check src/ include/

.PHONY: check-vassili

````
<!-- {code-block} makefile -->

Ejecutá `make check-vassili` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-vassili-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`vassili`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C AST Mutation Engine + GCC Subprocess
  Pool + Test Suite Mutation Score Evaluator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-vassili-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`vassili`** forma parte del
pipeline integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    SRC[Código C del TDA] --> VAS[Vassili: Mutation Testing]
    TEST[Suite de Pruebas Unitarias] --> VAS
    VAS -->|Operadores AOR, ROR, LCR| MUT[Generación de Mutantes en C]
    VAS -->|Ejecución Paralela de Tests| GCC[GCC Test Runner Pool]
    VAS -->|Cálculo de Mutation Score| DRD[Dredd: Calificación de Tests]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código C y suites de pruebas unitarias` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dietrich (análisis de cobertura)`
- `dredd (calificación de calidad de tests)` | Informes Markdown, diagnósticos
  Rich, JSON, actas |
| **Sincronización** | `dietrich`, `holden`, `deckard` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `vassili` con otras herramientas del ecosistema en una única
línea de comando:

````{code-block} bash
# Pipeline de integración típico
vassili mutate src/tda.c --tests ./bin/test_tda --md reporte_mutantes.md

````
<!-- {code-block} bash -->

---

(manual-vassili-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `vassili`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
