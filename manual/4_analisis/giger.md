---
title: "Manual de Referencia: giger"
subtitle: "Giger — Generador de Grafos de Control de Flujo (CFG), Grafo de Llamadas y Dead Code"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-giger)=
# Giger — Generador de Grafos de Control de Flujo (CFG), Grafo de Llamadas y Dead Code

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Análisis estructural de código C para generar grafos
de llamadas entre funciones, grafos de flujo de control (CFG), detección de
lazos infinitos y funciones muertas no invocadas.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-giger-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`giger`** forma parte del ecosistema oficial de software de la
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

(manual-giger-instalacion)=
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

### 2.2 Métodos de Instalación de `giger`

Podés instalar `giger` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `giger` cuenta con autocompletado nativo para comandos, flags
y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
giger --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
giger doctor

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

(manual-giger-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `giger`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `giger callgraph src/ -o grafo.dot` | Genera el Call Graph del proyecto en formato DOT/Graphviz. |
| `giger cfg <archivo.c> --function <fn>` | Genera el grafo de flujo de control (CFG) de una función. |
| `giger dead-code src/` | Detecta funciones estáticas o públicas que nunca son invocadas. |
| `giger cycles src/` | Identifica ciclos de recursión directa o indirecta entre módulos. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-giger-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>

void funcion_muerta(void) {
    printf("Nunca se ejecuta\n");
}

void procesar(int x) {
    if (x > 0) {
        printf("Positivo\n");
    } else {
        printf("No positivo\n");
    }
}

int main(void) {
    procesar(10);
    return 0;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
giger callgraph src/ -o grafo.dot

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
[!] GIGER DEAD CODE DETECTED:
    • 'funcion_muerta()' en src/main.c:3 no tiene llamadores en el Call Graph.

[✓] CFG de 'procesar()': 4 bloques básicos, 2 ramas condicionales (Complejidad ciclomática: 2).
[✓] Grafo de llamadas exportado a 'grafo.dot'.

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-giger-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`giger`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Detección de Funciones Obsoletas
:label: giger-desafio-1
Identificar funciones huérfanas en un TDA de gran tamaño.

**Instrucción de ejecución:**
``` bash
giger dead-code src/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Detección de Funciones Obsoletas -->

::::{solution} giger-desafio-1

``` bash
giger dead-code src/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} giger-desafio-1 -->

::::{exercise} Desafío 2: Renderizado de Call Graph a PNG
:label: giger-desafio-2
Convertir el grafo DOT de llamadas a imagen con Graphviz.

**Instrucción de ejecución:**
``` bash
giger callgraph src/ -o callgraph.dot && dot -Tpng callgraph.dot -o callgraph.png
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Renderizado de Call Graph a PNG -->

::::{solution} giger-desafio-2

``` bash
giger callgraph src/ -o callgraph.dot && dot -Tpng callgraph.dot -o callgraph.png
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} giger-desafio-2 -->

::::{exercise} Desafío 3: Análisis de Ciclos de Recursión Cruzada
:label: giger-desafio-3
Verificar si la función A llama a B y B llama a A.

**Instrucción de ejecución:**
``` bash
giger cycles src/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Análisis de Ciclos de Recursión Cruzada -->

::::{solution} giger-desafio-3

``` bash
giger cycles src/
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} giger-desafio-3 -->

---

(manual-giger-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `giger` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-giger:
	@echo "=== Ejecutando verificación con giger ==="
	giger check src/ include/

.PHONY: check-giger

````
<!-- {code-block} makefile -->

Ejecutá `make check-giger` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-giger-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`giger`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C Call Graph Extractor + Graphviz DOT
  Generator + Cyclomatic Complexity Calculator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-giger-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`giger`** forma parte del pipeline
integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    SRC[Código Fuente C] --> GIG[Giger: Grafos de Flujo]
    GIG -->|Extracción de Llamadas| AST[Tree-Sitter C AST]
    GIG -->|Detección de Dead Code| DRD[Dredd: Auditor de Entrega]
    GIG -->|Diagramas CFG DOT/PNG| MYST[Myst-Tools: Documentación]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente C del proyecto` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `myst-tools (diagramas de flujo)`
- `dredd (auditoría de dead code)` | Informes Markdown, diagnósticos Rich, JSON,
  actas |
| **Sincronización** | `sebastian`, `dietrich`, `vassili` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `giger` con otras herramientas del ecosistema en una única línea
de comando:

````{code-block} bash
# Pipeline de integración típico
giger callgraph src/ -o grafo.dot && dot -Tpng grafo.dot -o grafo.png

````
<!-- {code-block} bash -->

---

(manual-giger-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `giger`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
