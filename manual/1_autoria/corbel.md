---
title: "Manual de Referencia: corbel"
subtitle: "Corbel — Generador de Documentación de APIs, TDAs y Verificación de Snippets C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-corbel)=
# Corbel — Generador de Documentación de APIs, TDAs y Verificación de Snippets C

:::{note} Resumen Técnico del Satélite

**Rol en el ecosistema:** Generación de documentación técnica a partir de
encabezados C y validación de que todos los ejemplos de código compilen y
ejecuten sin errores.

:::
<!-- {note} Resumen Técnico del Satélite -->

---

(manual-corbel-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`corbel`** forma parte del ecosistema oficial de software de la
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

(manual-corbel-instalacion)=
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

### 2.2 Métodos de Instalación de `corbel`

Podés instalar `corbel` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `corbel` cuenta con autocompletado nativo para comandos,
flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
corbel --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
corbel doctor

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

(manual-corbel-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `corbel`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `corbel build include/ -o docs/` | Genera el sitio web o manual Markdown a partir de los headers C. |
| `corbel test-snippets docs/` | Extrae y compila todos los bloques de código C de la documentación. |
| `corbel check-coverage include/` | Calcula el porcentaje de funciones y structs documentadas. |
| `corbel doctor` | Verifica la disponibilidad de compiladores y formateadores. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-corbel-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
/**
 * @brief Inserta un elemento al inicio de la lista enlazada.
 * @param lista Puntero a la estructura TDA Lista.
 * @param dato Puntero genérico al dato a almacenar.
 * @return true si se insertó con éxito, false ante fallo de memoria.
 * @code
 * t_lista *l = lista_crear();
 * int x = 42;
 * assert(lista_insertar_inicio(l, &x) == true);
 * @endcode
 */
bool lista_insertar_inicio(t_lista *lista, void *dato);

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
corbel build include/ -o docs/

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
[✓] 14 funciones parseadas en include/lista.h (Cobertura: 100%)
[✓] 6 snippets de código extraídos de la documentación.
[✓] Compilación de snippets: 6/6 PASS (GCC -std=c11 -Werror)
[✓] Documentación generada exitosamente en docs/index.html

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-corbel-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`corbel`** resolviendo los siguientes ejercicios:

::::{exercise} Desafío 1: Generación de Manual de TDA
:label: corbel-desafio-1
Generar la documentación Markdown de `include/tda_cola.h`.

**Instrucción de ejecución:**
``` bash
corbel build include/tda_cola.h -o docs/cola/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Generación de Manual de TDA -->

::::{solution} corbel-desafio-1

``` bash
corbel build include/tda_cola.h -o docs/cola/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} corbel-desafio-1 -->

::::{exercise} Desafío 2: Verificación de Snippets de Código
:label: corbel-desafio-2
Comprobar que los ejemplos en los comentarios compilan sin warnings.

**Instrucción de ejecución:**
``` bash
corbel test-snippets docs/cola/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Verificación de Snippets de Código -->

::::{solution} corbel-desafio-2

``` bash
corbel test-snippets docs/cola/
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} corbel-desafio-2 -->

::::{exercise} Desafío 3: Auditoría de Cobertura de Documentación
:label: corbel-desafio-3
Verificar que ninguna función pública carezca de descripción de parámetros.

**Instrucción de ejecución:**
``` bash
corbel check-coverage include/
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Auditoría de Cobertura de Documentación -->

::::{solution} corbel-desafio-3

``` bash
corbel check-coverage include/
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} corbel-desafio-3 -->

---

(manual-corbel-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `corbel` de forma automática a tu flujo de desarrollo, agregá la
siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-corbel:
	@echo "=== Ejecutando verificación con corbel ==="
	corbel check src/ include/

.PHONY: check-corbel

````
<!-- {code-block} makefile -->

Ejecutá `make check-corbel` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-corbel-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`corbel`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C / Doxygen Parser + GCC Test Runner +
  MyST Markdown Exporter`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-corbel-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`corbel`** forma parte del
pipeline integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    HDR[Headers C: include/*.h] --> CRB[Corbel: Generador de Docs]
    CRB -->|Extracción de Snippets| GCC[GCC: Compilación de Ejemplos]
    CRB -->|Verificación de Opacidad| MOT[Motoko: Encapsulamiento TDA]
    CRB -->|Documentación Markdown| MYST[Myst-Tools: Sitio Web y Apuntes]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Headers C (.h) con documentación de TDAs y APIs` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `myst-tools (sitios web y apuntes)`
- `deckard (documentación de consignas)` | Informes Markdown, diagnósticos Rich,
  JSON, actas |
| **Sincronización** | `motoko`, `parker`, `myst-tools` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `corbel` con otras herramientas del ecosistema en una única
línea de comando:

````{code-block} bash
# Pipeline de integración típico
corbel build include/ -o docs/ && corbel test-snippets docs/ && myst-tools fmt docs/

````
<!-- {code-block} bash -->

---

(manual-corbel-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `corbel`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
