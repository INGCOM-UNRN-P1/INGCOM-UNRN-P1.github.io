---
title: "Manual de Referencia: zhora"
subtitle: "Zhora — Linter y Auditor de Seguridad en Macros del Preprocesador #define"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-zhora)=
# Zhora — Linter y Auditor de Seguridad en Macros del Preprocesador #define

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Auditoría de seguridad y buenas prácticas en macros de
C: detección de parámetros sin paréntesis defensivos `(x)`, efectos colaterales
en argumentos (`MACRO(i++)`), macros con sentencias múltiples sin bloque `do {
... } while(0)` y sugerencia de funciones `inline` / `enum`.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-zhora-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`zhora`** forma parte del ecosistema oficial de software de la
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

(manual-zhora-instalacion)=
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

### 2.2 Métodos de Instalación de `zhora`

Podés instalar `zhora` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `zhora` cuenta con autocompletado nativo para comandos, flags
y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
zhora --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
zhora doctor

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

(manual-zhora-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `zhora`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `zhora audit include/ src/` | Audita todas las macros `#define` buscando vulnerabilidades de precedencia. |
| `zhora fix include/macros.h` | Agrega automáticamente paréntesis defensivos a los parámetros de macros. |
| `zhora to-inline include/macros.h` | Convierte macros complejas en funciones estáticas inline tipadas. |
| `zhora doctor` | Verifica analizadores de preprocesador C. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-zhora-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Macro insegura: falta de paréntesis y doble evaluación de argumentos
#define CUADRADO_MAL(x) x * x
#define MAX_MAL(a, b) ((a) > (b) ? (a) : (b))

// Invocaciones problemáticas:
// CUADRADO_MAL(1 + 2) expande a: 1 + 2 * 1 + 2 = 5 (esperado: 9)
// MAX_MAL(i++, j) evalúa 'i++' dos veces si 'a > b'

// Macro segura auditada por Zhora:
#define CUADRADO_BIEN(x) ((x) * (x))
// O preferiblemente función inline:
static inline int cuadrado(int x) { return x * x; }

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
zhora audit include/ src/

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
:linenos:
⚠️ ZHORA PREPROCESSOR SECURITY REPORT:
┌─────────────────┬────────────────────────────────────────────────────────┐
│ Ubicación       │ Diagnóstico de Seguridad y Sugerencia                  │
├─────────────────┼────────────────────────────────────────────────────────┤
│ macros.h:2:9    │ Macro 'CUADRADO_MAL': Parámetro 'x' sin paréntesis.    │
│                 │ 'x * x' fallará ante expresiones compuestas (1 + 2).   │
│ macros.h:3:9    │ Macro 'MAX_MAL': Doble evaluación de 'a'. Riesgo grave │
│                 │ ante argumentos con efectos colaterales (i++).         │
└─────────────────┴────────────────────────────────────────────────────────┘
💡 Ejecutá 'zhora fix include/macros.h' para agregar paréntesis protectores.

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-zhora-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`zhora`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Auditoría de Macros en Headers de Utilidad
:label: zhora-desafio-1
Escanear `include/util.h` y encontrar macros propensas a errores de precedencia.

**Instrucción de ejecución:**
``` bash
zhora audit include/util.h
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Auditoría de Macros en Headers de Utilidad -->

::::{solution} zhora-desafio-1

``` bash
zhora audit include/util.h
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} zhora-desafio-1 -->

::::{exercise} Desafío 2: Auto-Protección de Parámetros con Paréntesis
:label: zhora-desafio-2
Corregir automáticamente `#define MULT(a, b) a * b` por `((a) * (b))`.

**Instrucción de ejecución:**
``` bash
zhora fix include/util.h
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Auto-Protección de Parámetros con Paréntesis -->

::::{solution} zhora-desafio-2

``` bash
zhora fix include/util.h
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} zhora-desafio-2 -->

::::{exercise} Desafío 3: Migración de Macros a Funciones `inline`
:label: zhora-desafio-3
Reemplazar macros con efectos colaterales por funciones `static inline` con
chequeo de tipos.

**Instrucción de ejecución:**
``` bash
zhora to-inline include/matematica.h
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Migración de Macros a Funciones `inline` -->

::::{solution} zhora-desafio-3

``` bash
zhora to-inline include/matematica.h
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} zhora-desafio-3 -->

---

(manual-zhora-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `zhora` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-zhora:
	@echo "=== Ejecutando verificación con zhora ==="
	zhora check src/ include/

.PHONY: check-zhora

````
<!-- {code-block} makefile -->

Ejecutá `make check-zhora` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-zhora-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`zhora`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Clang Macro Expander + Preprocessor Security Tokenizer
  + Inline Function Transformer`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-zhora-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`zhora`** forma parte del pipeline
integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    HDR[include/*.h: Macros #define] --> ZHO[Zhora: Auditor de Macros]
    ZHO -->|Detección de Falta de Paréntesis| EXP[Clang Macro Expander]
    ZHO -->|Inyección de Paréntesis Protectores| GAF[Gaff: Formateo y Estilo]
    ZHO -->|Transformación a static inline| CRB[Corbel: Documentación de APIs]
    ZHO -->|Reglas de Preprocesador 0x4000h| RIP[Ripley: Microkernel de Reglas]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Macros #define en headers y código C` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ripley (reglas 0x4000h de macros)`
- `corbel (funciones inline tipadas)` | Informes Markdown, diagnósticos Rich,
  JSON, actas |
| **Sincronización** | `ripley`, `corbel`, `gaff` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `zhora` con otras herramientas del ecosistema en una única línea
de comando:

````{code-block} bash
# Pipeline de integración típico
zhora audit include/macros.h && zhora fix include/macros.h

````
<!-- {code-block} bash -->

---

(manual-zhora-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `zhora`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
