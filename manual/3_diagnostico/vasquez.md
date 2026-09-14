---
title: "Manual de Referencia: vasquez"
subtitle: "Vasquez — Inyector de Fallos en Runtime vía LD_PRELOAD sobre malloc, fopen y Syscalls"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-vasquez)=
# Vasquez — Inyector de Fallos en Runtime vía LD_PRELOAD sobre malloc, fopen y Syscalls

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Inyección no invasiva de fallos de hardware y sistema operativo en tiempo de ejecución interceptando llamadas a glibc mediante una librería `LD_PRELOAD` sin recompilar el código del estudiante.
````

---

(manual-vasquez-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`vasquez`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-vasquez-instalacion)=
## 2. Instalación y Verificación del Entorno

````{important}
Para proveer la reproducibilidad técnica de la cátedra, verificá instalar las dependencias nativas del sistema operativo antes de instalar el paquete Python.
````

### 2.1 Requisitos Previos del Sistema

Instalá los paquetes del sistema requeridos según tu distribución o entorno:

````{tab-set}
```{tab-item} Ubuntu / Debian
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
```

```{tab-item} Arch Linux / Manjaro
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
```

```{tab-item} Fedora / RHEL
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
```

```{tab-item} macOS (Homebrew)
brew install gcc gdb clang-format typst graphviz uv
```

```{tab-item} Windows (MSYS2 / WSL2)
# En WSL2 (Ubuntu): utilizar los paquetes de Ubuntu/Debian arriba.
# En MSYS2 MINGW64:
pacman -S --needed \
    mingw-w64-x86_64-gcc \
    mingw-w64-x86_64-gdb \
    mingw-w64-x86_64-clang-tools-extra
```
````

---

### 2.2 Métodos de Instalación de `vasquez`

Podés instalar `vasquez` mediante cualquiera de los siguientes métodos estándar:

````{tab-set}
```{tab-item} uv tool (Recomendado)
# Instalación aislada de alta velocidad con uv
uv tool install . --editable

# O instalar todo el ecosistema de herramientas de la cátedra en lote:
source ./install_tools.sh
```

```{tab-item} pip / venv
# Crear y activar un entorno virtual
python3 -m venv .venv
source .venv/bin/activate

# Instalar en modo editable para desarrollo
pip install -e .
```

```{tab-item} pipx
# Instalación global aislada en tu PATH
pipx install --editable .
```
````

---

### 2.3 Autocompletado en la Shell

La interfaz CLI de `vasquez` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
vasquez --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
vasquez doctor
````

#### Comprobaciones Ejecutadas por el Diagnóstico:
- **Compilador C**: Verifica disponibilidad de `gcc` o `clang` con soporte de estándares C11 y C23.
- **Depurador y Core Dumps**: Comprueba que `gdb` esté instalado y que `ulimit -c` permita generación de core dumps.
- **Herramientas de Memoria**: Valida la presencia de `valgrind` y librerías `libasan`/`libubsan`.
- **Formateo y Estilo**: Verifica el binario `clang-format` (versión 16+).
- **Sandboxing de Kernel**: Audita permisos no privilegiados de `bwrap` (Bubblewrap namespaces).
- **Generador de Tipografía y Documentos**: Comprueba `typst` ($\ge 0.11$) y `dot` (Graphviz).

#### Matriz de Resolución de Problemas:

| Síntoma / Alerta de `doctor` | Causa Raíz | Acción Correctiva |
| :--- | :--- | :--- |
| `❌ gcc / clang no encontrado` | Toolchain C faltante | Instalá `build-essential` o `base-devel`. |
| `❌ bwrap permisos insuficientes` | User namespaces desactivados | Habilitá `sysctl kernel.unprivileged_userns_clone=1`. |
| `❌ typst no disponible` | Motor de PDF faltante | Descargá Typst vía `cargo install typst-cli` o gestor de paquetes. |
| `❌ gdb no responde` | GDB sin interfaz MI/Python | Reinstalá `gdb` completo desde el repositorio oficial. |

(manual-vasquez-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `vasquez`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `vasquez inject --target ./bin/programa --fail-malloc-at 3` | Fuerza a que la 3ra llamada a malloc() devuelva NULL. |
| `vasquez inject --target ./bin/programa --faults "fopen:1,malloc:2"` | Simula fallos secuenciales en apertura de archivos y memoria. |
| `vasquez check-leaks ./bin/programa` | Verifica que el programa no pierda memoria en los caminos de error. |
| `vasquez doctor` | Verifica que el compilador y soporte de LD_PRELOAD funcionen correctamente. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-vasquez-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdlib.h>
#include <stdio.h>

// Código defensivo evaluado bajo inyección Vasquez
int* crear_vector(size_t n) {
    int *v = malloc(sizeof(int) * n);
    if (v == NULL) { // Vasquez fuerza este camino devolviendo NULL
        fprintf(stderr, "Error: Memoria insuficiente\n");
        return NULL;
    }
    return v;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
vasquez inject --target ./bin/programa --fail-malloc-at 3
````

### Salida Obtenida en Consola

````{code-block} text
INYECCIÓN DE FALLOS VASQUEZ:
┌─────────────────┬──────────────┬──────────────┬──────────────────────────────────┐
│ Escenario       │ Invocación # │ Resultado    │ Estado Defensivo                 │
├─────────────────┼──────────────┼──────────────┼──────────────────────────────────┤
│ malloc -> NULL  │ 1            │ ✓ MANEJADO   │ Retornó NULL limpiamente (PASS)  │
│ malloc -> NULL  │ 2            │ ✓ MANEJADO   │ Liberó recursos previos (PASS)   │
│ fopen -> NULL   │ 1            │ ❌ CRASH     │ SIGSEGV en procesar.c:28 (FAIL)  │
└─────────────────┴──────────────┴──────────────┴──────────────────────────────────┘
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-vasquez-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`vasquez`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Simulación de Memoria Agotada en `malloc`
:label: vasquez-desafio-1
Comprobar si el programa maneja el retorno `NULL` de memoria.

**Instrucción de ejecución:**
```bash
vasquez inject --target ./bin/tp1 --fail-malloc-at 1
```
````

````{solution} vasquez-desafio-1
```bash
vasquez inject --target ./bin/tp1 --fail-malloc-at 1
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Inyección de Falla en Archivo de Configuración
:label: vasquez-desafio-2
Forzar a que `fopen()` devuelva NULL y verificar mensaje de error.

**Instrucción de ejecución:**
```bash
vasquez inject --target ./bin/tp1 --faults "fopen:1"
```
````

````{solution} vasquez-desafio-2
```bash
vasquez inject --target ./bin/tp1 --faults "fopen:1"
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auditoría Integrada con Diagnóstico Forense HAL
:label: vasquez-desafio-3
Capturar el crash ante un fallo inyectado y visualizar la línea origen.

**Instrucción de ejecución:**
```bash
vasquez inject --target ./bin/tp1 --fail-malloc-at 2 --diagnose
```
````

````{solution} vasquez-desafio-3
```bash
vasquez inject --target ./bin/tp1 --fail-malloc-at 2 --diagnose
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-vasquez-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `vasquez` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-vasquez:
	@echo "=== Ejecutando verificación con vasquez ==="
	vasquez check src/ include/

.PHONY: check-vasquez
````

Ejecutá `make check-vasquez` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-vasquez-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`vasquez`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `C Dynamic Preload Library (LD_PRELOAD) + Function Interception Engine (dlsym RTLD_NEXT) + Fault State Machine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-vasquez-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`vasquez`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    BIN[Binario del Estudiante] --> VAS[Vasquez: Inyector LD_PRELOAD]
    VAS -->|Intercepta malloc/fopen/write| GLIBC[glibc Calls (RTLD_NEXT)]
    VAS -->|Fuerza Retorno NULL| FAULT[Simulación OOM / Falla I/O]
    FAULT -->|Código sin Chequeo Crash SIGSEGV| HAL[Hal: Forense de Core Dumps]
    VAS -->|Reporte de Manejo Defensivo| DRD[Dredd: Informe alumno_rN.md]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios C compilados de estudiantes` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `hal (diagnóstico correlacionado de caídas)`
- `dredd (evaluación de robustez defensiva)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `hal`, `holden`, `nostromo`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `vasquez` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
vasquez inject --target ./bin/app --faults "malloc:1" --diagnose
````

---

(manual-vasquez-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `vasquez` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
