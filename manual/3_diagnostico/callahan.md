---
title: "Manual de Referencia: callahan"
subtitle: "Callahan — Verificador Formal de Contratos ACSL y Demostración Deductiva con Frama-C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-callahan)=
# Callahan — Verificador Formal de Contratos ACSL y Demostración Deductiva con Frama-C

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Verificación matemática de precondiciones,
postcondiciones, invariantes de lazo y ausencia de desbordes aritméticos con
Frama-C WP.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

(manual-callahan-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`callahan`** forma parte del ecosistema oficial de software de
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

(manual-callahan-instalacion)=
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

### 2.2 Métodos de Instalación de `callahan`

Podés instalar `callahan` mediante cualquiera de los siguientes métodos
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

La interfaz CLI de `callahan` cuenta con autocompletado nativo para comandos,
flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
callahan --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh

````
<!-- {code-block} bash -->

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`.
Ejecutalo para auditar el estado del entorno:

````{code-block} bash
callahan doctor

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

(manual-callahan-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en
`callahan`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `callahan check <archivo.c>` | Verifica los contratos ACSL del archivo con Frama-C WP. |
| `callahan gen-contracts <archivo.h>` | Genera plantillas de pre/postcondiciones para funciones C. |
| `callahan doctor` | Verifica la instalación de Frama-C, Alt-Ergo y Z3. |
| `callahan verify-loop <archivo.c> --function <fn>` | Demuestra formalmente la terminación e invariantes de un lazo. |

::::{tip}

Podés agregar el flag `--json` a la mayoría de los comandos para exportar
resultados en formato estructurado o `--md` para generar reportes Markdown para
el informe de entrega.

::::
<!-- {tip} -->

---

(manual-callahan-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
/*@
  @ requires \valid(v + (0 .. n-1));
  @ requires n > 0;
  @ assigns \nothing;
  @ ensures \forall integer i; 0 <= i < n ==> \result >= v[i];
  @*/
int buscar_maximo(const int *v, int n) {
    int max = v[0];
    /*@
      @ loop invariant 1 <= i <= n;
      @ loop invariant \forall integer k; 0 <= k < i ==> max >= v[k];
      @ loop assigns i, max;
      @ loop variant n - i;
      @*/
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}

````
<!-- {code-block} c -->

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
callahan check <archivo.c>

````
<!-- {code-block} bash -->

### Salida Obtenida en Consola

````{code-block} text
[WP] Proving goal buscar_maximo_ensures_1: Valid (Alt-Ergo 2.4)
[WP] Proving goal buscar_maximo_loop_invariant_1: Valid (Qed)
[WP] Proving goal buscar_maximo_loop_variant: Valid (Qed)
[✓] Todas las metas demostradas formalmente. 0 desbordes.

````
<!-- {code-block} text -->

::::{note}

Prestá atención a la explicación pedagógica generada: la herramienta no solo
señala la línea del problema, sino que explica la causa raíz y el impacto en
memoria o arquitectura.

::::
<!-- {note} -->

---

(manual-callahan-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`callahan`** resolviendo los siguientes
ejercicios:

::::{exercise} Desafío 1: Verificación de Búsqueda Binaria
:label: callahan-desafio-1
Demostrar que `busqueda_binaria()` no sufre desbordes al calcular `mid`.

**Instrucción de ejecución:**
``` bash
callahan check src/busqueda.c
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Verificación de Búsqueda Binaria -->

::::{solution} callahan-desafio-1

``` bash
callahan check src/busqueda.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
<!-- bash -->

::::
<!-- {solution} callahan-desafio-1 -->

::::{exercise} Desafío 2: Invariante de Lazo en Inversión de Vector
:label: callahan-desafio-2
Escribir contratos ACSL para invertir un vector.

**Instrucción de ejecución:**
``` bash
callahan check src/invertir.c
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: Invariante de Lazo en Inversión de Vector -->

::::{solution} callahan-desafio-2

``` bash
callahan check src/invertir.c
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
<!-- bash -->

::::
<!-- {solution} callahan-desafio-2 -->

::::{exercise} Desafío 3: Generación Automática de Contratos
:label: callahan-desafio-3
Generar precondiciones de punteros válidos para `include/lista.h`.

**Instrucción de ejecución:**
``` bash
callahan gen-contracts include/lista.h -o include/lista_contratos.h
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Generación Automática de Contratos -->

::::{solution} callahan-desafio-3

``` bash
callahan gen-contracts include/lista.h -o include/lista_contratos.h
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
<!-- bash -->

::::
<!-- {solution} callahan-desafio-3 -->

---

(manual-callahan-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `callahan` de forma automática a tu flujo de desarrollo, agregá
la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-callahan:
	@echo "=== Ejecutando verificación con callahan ==="
	callahan check src/ include/

.PHONY: check-callahan

````
<!-- {code-block} makefile -->

Ejecutá `make check-callahan` antes de cada commit para mantener que tu código
conserve el estado de aprobación.

---

(manual-callahan-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`callahan`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Frama-C Kernel 28.0 + WP Plugin (Weakest Precondition)
  + Solvers Alt-Ergo / Z3`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales
  en entornos de integración continua (CI), terminales de estudiantes y
  servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se
  traduce en una acción prescriptiva concreta con su respectiva justificación
  técnica.

---

(manual-callahan-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

::::{note}

Ninguna herramienta opera de forma aislada. **`callahan`** forma parte del
pipeline integral de evaluación, verificación y enseñanza de la cátedra.

::::
<!-- {note} -->

### Diagrama de Flujo e Interoperabilidad

::::{mermaid}

graph TD
    SRC[Código C + ACSL] --> CAL[Callahan: Verificador Formal]
    CAL -->|Metas Deductivas| WP[Frama-C WP Plugin]
    WP -->|Demostración Matemática| Z3[Alt-Ergo / Z3 Provers]
    CAL -->|resolvé Libres de UB| DK[Deckard: Banco Canónico]
    CAL -->|Contratos de API| CORB[Corbel: Documentación de TDAs]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código C con especificaciones formales ACSL` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `deckard (resolvé canónicas certificadas)`
- `dredd (oráculo formal)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `weyl`, `daedalus`, `deckard` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `callahan` con otras herramientas del ecosistema en una única
línea de comando:

````{code-block} bash
# Pipeline de integración típico
callahan check src/tda.c && weyl diff src/tda.c canon/tda.c

````
<!-- {code-block} bash -->

---

(manual-callahan-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `callahan`
programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)
