---
title: "Manual de Referencia: drake"
subtitle: "Drake — Fuzzer Guiado por Límites y Analizador de Robustez ante Entradas Extremas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-drake)=
# Drake — Fuzzer Guiado por Límites y Analizador de Robustez ante Entradas Extremas

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Generación procedural de casos de prueba límite (valores frontera como INT_MAX, INT_MIN, cadenas sin terminador, buffers gigantes) para detectar desbordes y caídas inesperadas en C.
````

---

(manual-drake-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`drake`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-drake-instalacion)=
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

### 2.2 Métodos de Instalación de `drake`

Podés instalar `drake` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `drake` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
drake --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
drake doctor
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

(manual-drake-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `drake`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `drake fuzz --binary ./bin/programa` | Ejecuta fuzzing guiado por límites contra la entrada estándar del binario. |
| `drake fuzz --target <archivo.c> --runs 100` | Compila y ejecuta 100 mutaciones de estrés. |
| `drake boundaries --type int` | Lista los valores frontera recomendados para tipos enteros y punteros. |
| `drake doctor` | Verifica la disponibilidad de AFL++ o motor LLVM libFuzzer. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-drake-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>
#include <limits.h>

// Vulnerable a desborde aritmético si a + b supera INT_MAX
int sumar_seguro(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        return 0; // Desborde detectado
    }
    return a + b;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
drake fuzz --binary ./bin/programa
````

### Salida Obtenida en Consola

````{code-block} text
[!] DRAKE FUZZER: Ejecutando 50 mutaciones de frontera...
[✓] Test 01: INT_MAX (2147483647) -> PASS (Manejado)
[✓] Test 02: INT_MIN (-2147483648) -> PASS (Manejado)
[✓] Test 03: Cadena de 65536 bytes -> PASS (Sin buffer overrun)
[✓] 50/50 escenarios de estrés superados sin caídas (0 SIGSEGV, 0 SIGFPE).
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-drake-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`drake`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Fuzzing de Parser de Números
:label: drake-desafio-1
Ejecutar 50 iteraciones de valores extremos contra `parsear_entero()`.

**Instrucción de ejecución:**
```bash
drake fuzz --binary ./bin/parser_test --runs 50
```
````

````{solution} drake-desafio-1
```bash
drake fuzz --binary ./bin/parser_test --runs 50
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Detección de División por Cero
:label: drake-desafio-2
Inyectar denominador 0 y desbordes en calculadora aritmética.

**Instrucción de ejecución:**
```bash
drake fuzz --binary ./bin/calc --type math
```
````

````{solution} drake-desafio-2
```bash
drake fuzz --binary ./bin/calc --type math
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Validación de Desbordes de String
:label: drake-desafio-3
Alimentar buffers de entrada con cadenas sin byte nulo `\0`.

**Instrucción de ejecución:**
```bash
drake fuzz --binary ./bin/string_app --type string
```
````

````{solution} drake-desafio-3
```bash
drake fuzz --binary ./bin/string_app --type string
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-drake-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `drake` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-drake:
	@echo "=== Ejecutando verificación con drake ==="
	drake check src/ include/

.PHONY: check-drake
````

Ejecutá `make check-drake` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-drake-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`drake`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `LLVM libFuzzer / AFL++ Engine + Boundary Numeric Synthesizer + Signal Trap Handler`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-drake-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`drake`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    BIN[Binario C Compilado] --> DRK[Drake: Fuzzer de Límites]
    DRK -->|Payloads: INT_MAX, Strings| NOS[Nostromo: Sandbox Aislado]
    NOS -->|Crash SIGSEGV / SIGFPE| HAL[Hal: Forense de Core Dumps]
    DRK -->|Reporte de Robustez| DRD[Dredd: Autograding Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios C compilados` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `hal (diagnóstico de crashes)`
- `nostromo (ejecución segura)`
- `dredd (robustez)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `vasquez`, `hal`, `tyrell` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `drake` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
drake fuzz --binary ./bin/programa | hal inspect --pipe
````

---

(manual-drake-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `drake` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
