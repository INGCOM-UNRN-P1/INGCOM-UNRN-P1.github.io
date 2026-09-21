---
title: "Manual de Referencia: gaff"
subtitle: "Gaff — Linter Pedagógico de Estilo Arquitectónico y Convenciones Cátedra con Autofix"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-gaff)=
# Gaff — Linter Pedagógico de Estilo Arquitectónico y Convenciones Cátedra con Autofix

:::{note} Resumen Técnico del Satélite

**Rol en el ecosistema:** Auditoría y corrección automática de estilo en C:
formato Allman, nomenclatura snake_case, espacios en palabras clave, guardas de
inclusión y prohibición de variables globales.

:::
<!-- {note} Resumen Técnico del Satélite -->

---

(manual-gaff-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`gaff`** forma parte del ecosistema oficial de software de la
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

(manual-gaff-instalacion)=
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

### 2.2 Métodos de Instalación de `gaff`

Podés instalar `gaff` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `gaff` cuenta con autocompletado nativo para comandos, flags
y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
gaff --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
gaff doctor

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

(manual-gaff-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `gaff`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `gaff check src/ include/ [-r / --recursive]` | Audita todas las reglas de estilo de cátedra. |
| `gaff fix src/ include/ [-r / --recursive]` | Aplica correcciones automáticas sobre reglas autofixables. |
| `gaff fix --interactive src/` | Previsualiza los cambios en un diff coloreado antes de aplicar. |
| `gaff rules` | Lista el catálogo oficial de reglas GAFF con sus alias 0xXXXXh. |
| `gaff export-rules -o manual_estilo.md` | Exporta la guía completa de convenciones en Markdown. |
| `gaff init-config` | Genera el archivo canónico `.clang-format` institucional. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-gaff-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Código con violaciones de estilo detectadas por GAFF
void FuncionPrueba(int a){ // 0x000Eh (camelCase), 0x000Bh (llave K&R)
    if(a>0){               // 0x0004h (falta espacio en if), 0x000Bh
        int* ptr=&a;       // 0x0006h (asterisco pegado a tipo)
    }
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
gaff check src/ include/ [-r / --recursive]

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
⚠️ Se encontraron 4 violaciones de estilo en src/prueba.c:
┌────────────────────┬─────────┬───────────────────────────────────────┬────────┐
│ Ubicación          │ Regla   │ Mensaje                               │ Fix    │
├────────────────────┼─────────┼───────────────────────────────────────┼────────┤
│ prueba.c:1:6       │ 0x000Eh │ Función 'FuncionPrueba' no snake_case │ manual │
│ prueba.c:1:26      │ 0x000Bh │ Llave '{' K&R en vez de Allman        │ ✓ auto │
│ prueba.c:2:5       │ 0x0004h │ Falta espacio tras 'if'               │ ✓ auto │
│ prueba.c:3:9       │ 0x0006h │ Formato puntero 'int* ptr'            │ ✓ auto │
└────────────────────┴─────────┴───────────────────────────────────────┴────────┘
💡 Ejecutá 'gaff fix src/' para corregir automáticamente los problemas marcados con '✓ auto'.

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-gaff-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`gaff`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Auditoría Recursiva de Proyecto
:label: gaff-desafio-1
Auditar todo el árbol de carpetas con el nuevo flag `-r`.

**Instrucción de ejecución:**
``` bash
gaff check src/ include/ -r
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Auditoría Recursiva de Proyecto -->

::::{solution} gaff-desafio-1

``` bash
gaff check src/ include/ -r
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} gaff-desafio-1 -->

::::{exercise} Desafío 2: Auto-Corrección Interactiva
:label: gaff-desafio-2
Corregir espaciados y llaves Allman previsualizando el diff.

**Instrucción de ejecución:**
``` bash
gaff fix --interactive src/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Auto-Corrección Interactiva -->

::::{solution} gaff-desafio-2

``` bash
gaff fix --interactive src/
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} gaff-desafio-2 -->

::::{exercise} Desafío 3: Exportación de Catálogo de Reglas
:label: gaff-desafio-3
Generar el manual Markdown de reglas de estilo para consulta del equipo.

**Instrucción de ejecución:**
``` bash
gaff export-rules -o REGLAS_ESTILO.md
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Exportación de Catálogo de Reglas -->

::::{solution} gaff-desafio-3

``` bash
gaff export-rules -o REGLAS_ESTILO.md
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} gaff-desafio-3 -->

---

(manual-gaff-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `gaff` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-gaff:
	@echo "=== Ejecutando verificación con gaff ==="
	gaff check src/ include/

.PHONY: check-gaff

````
<!-- {code-block} makefile -->

Ejecutá `make check-gaff` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-gaff-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`gaff`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `libclang / Clang-Format 18 Driver + Custom AST Style
  Rules Engine (Allman, snake_case)`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-gaff-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`gaff`** forma parte del pipeline
integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    SRC[Código C del Estudiante] --> GAF[Gaff: Linter de Estilo]
    GAF -->|Autofix Allman / snake_case| CLANG[clang-format Engine]
    GAF -->|Reporte de Violaciones| RIP[Ripley: Microkernel de Reglas]
    RIP -->|Evaluación Automática| DRD[Dredd: Calificador Masivo]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente C (.c y .h)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ripley (reglas de formato 0x0001h-0x00FFh)`
- `dredd (calificación de estilo)` | Informes Markdown, diagnósticos Rich, JSON,
  actas |
| **Sincronización** | `ripley`, `spunkmeyer`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `gaff` con otras herramientas del ecosistema en una única línea
de comando:

````{code-block} bash
# Pipeline de integración típico
gaff fix -r src/ include/ && ripley check src/

````
<!-- {code-block} bash -->

---

(manual-gaff-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `gaff`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
