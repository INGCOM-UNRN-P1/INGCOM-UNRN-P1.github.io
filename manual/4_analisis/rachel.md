---
title: "Manual de Referencia: rachel"
subtitle: "Rachel — Desensamblador y Verificador de Jump Tables O(1) en Sentencias Switch"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-rachel)=
# Rachel — Desensamblador y Verificador de Jump Tables O(1) en Sentencias Switch

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Desensamblado de código máquina y análisis de grafos de control para verificar si el compilador generó una tabla de saltos indexada O(1) (Jump Table / rodata) o una cascada ineficiente de comparaciones if-else O(N).
````

---

(manual-rachel-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`rachel`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-rachel-instalacion)=
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

### 2.2 Métodos de Instalación de `rachel`

Podés instalar `rachel` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `rachel` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
rachel --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
rachel doctor
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

(manual-rachel-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `rachel`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `rachel check src/procesador.c` | Analiza las sentencias switch y reporta si usan Jump Tables O(1). |
| `rachel disasm src/main.c --function <fn>` | Muestra el código ensamblador coloreado de la estructura de salto. |
| `rachel optimize-switch src/despachador.c` | Sugiere densificación de etiquetas case para forzar Jump Table. |
| `rachel doctor` | Verifica la disponibilidad de objdump, GDB y compiladores. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-rachel-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>

// Switch denso analizado por Rachel: el compilador genera Jump Table O(1)
void despachar_comando(int cmd) {
    switch (cmd) {
        case 1: printf("Alta\n"); break;
        case 2: printf("Baja\n"); break;
        case 3: printf("Modificación\n"); break;
        case 4: printf("Listado\n"); break;
        default: printf("Invalido\n"); break;
    }
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
rachel check src/procesador.c
````

### Salida Obtenida en Consola

````{code-block} text
[✓] RACHEL SWITCH AUDIT: src/procesador.c en 'despachar_comando()':
    • Patrón detectado: Jump Table O(1) indexada en .rodata (4 entradas contiguas).
    • Instrucción de despacho: 'jmpq *0x402060(,%rdi,8)'
    • Complejidad temporal: O(1) constante (independiente de la cantidad de cases).
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-rachel-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`rachel`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Verificación de Tabla de Saltos en Intérprete
:label: rachel-desafio-1
Comprobar que el switch del despachador de opcodes compila a Jump Table.

**Instrucción de ejecución:**
```bash
rachel check src/interprete.c
```
````

````{solution} rachel-desafio-1
```bash
rachel check src/interprete.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Densificación de Casos Esparsos
:label: rachel-desafio-2
Transformar un switch disperso (case 1, case 1000, case 50000) en densidad contigua.

**Instrucción de ejecución:**
```bash
rachel optimize-switch src/comandos.c
```
````

````{solution} rachel-desafio-2
```bash
rachel optimize-switch src/comandos.c
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Inspección de Instrucciones Ensamblador
:label: rachel-desafio-3
Desensamblar la función despachadora y examinar la tabla en `.rodata`.

**Instrucción de ejecución:**
```bash
rachel disasm src/procesador.c --function despachar_comando
```
````

````{solution} rachel-desafio-3
```bash
rachel disasm src/procesador.c --function despachar_comando
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-rachel-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `rachel` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-rachel:
	@echo "=== Ejecutando verificación con rachel ==="
	rachel check src/ include/

.PHONY: check-rachel
````

Ejecutá `make check-rachel` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-rachel-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`rachel`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `GNU objdump / GDB Disassembler + Jump Table .rodata Extractor + Control Flow Branch Predictor`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-rachel-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`rachel`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C: Sentencias switch] --> DAE[Daedalus: Compilador GCC]
    DAE -->|Binario Compilado| RCH[Rachel: Desensamblador O(1)]
    RCH -->|Inspección .rodata| OBJDUMP[GNU objdump Disassembler]
    RCH -->|Verificación O(1) vs O(N)| FRR[Ferro: Perfilador de Rendimiento]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios compilados con sentencias switch` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ferro (análisis de saltos)`
- `deckard (ejercicios de bajo nivel)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `daedalus`, `ferro`, `bishop` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `rachel` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
rachel check src/despachador.c --disasm
````

---

(manual-rachel-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `rachel` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
