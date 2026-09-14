---
title: "Manual de Referencia: kaneda"
subtitle: "Kaneda — Auditor Estático de Seguridad en C y Detección de Funciones Inseguras Prohibidas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-kaneda)=
# Kaneda — Auditor Estático de Seguridad en C y Detección de Funciones Inseguras Prohibidas

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Auditoría de vulnerabilidades en C: prohibición de `gets()`, `strcpy()`, `sprintf()`, detección de desbordes de buffer estáticos y vulnerabilidades de Format String.
```

---

(manual-kaneda-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`kaneda`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-kaneda-instalacion)=
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

### 2.2 Métodos de Instalación de `kaneda`

Podés instalar `kaneda` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `kaneda` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
kaneda --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
kaneda doctor
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

(manual-kaneda-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `kaneda`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `kaneda audit src/ include/` | Audita todos los archivos C buscando llamadas inseguras y vulnerabilidades. |
| `kaneda scan <archivo.c>` | Analiza un archivo individual y sugiere alternativas seguras (`fgets`, `snprintf`). |
| `kaneda rules` | Muestra el catálogo de funciones prohibidas y buenas prácticas de seguridad. |
| `kaneda doctor` | Verifica analizadores estáticos y reglas de seguridad. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-kaneda-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>
#include <string.h>

void vulnerabilidad_seguridad(void) {
    char buffer[16];
    gets(buffer);                     // Prohibido: Buffer Overflow crítico
    char destino[10];
    strcpy(destino, "Texto muy largo"); // Prohibido: Desborde
    printf(buffer);                   // Prohibido: Format String Vulnerability
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
kaneda audit src/ include/
````

### Salida Obtenida en Consola

````{code-block} text
🚨 KANEDA SECURITY AUDIT REPORT: 3 vulnerabilidades críticas detectadas:
┌──────────────────┬──────────┬────────────────────────────────────────────────────────┐
│ Ubicación        │ Gravedad │ Vulnerabilidad y Acción Requerida                      │
├──────────────────┼──────────┼────────────────────────────────────────────────────────┤
│ auth.c:5:5       │ CRÍTICA  │ Uso de 'gets()'. Reemplazá obligatoriamente por fgets()│
│ auth.c:7:5       │ ALTA     │ 'strcpy()' sin límite. Usá strncpy() o snprintf()      │
│ auth.c:8:5       │ ALTA     │ Format string sin formato fijo. Usá printf("%s", buf)  │
└──────────────────┴──────────┴────────────────────────────────────────────────────────┘
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-kaneda-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`kaneda`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Auditoría de Seguridad de Pre-Entrega
:label: kaneda-desafio-1
Escanear todo el proyecto para proveer 0 funciones inseguras.

**Instrucción de ejecución:**
```bash
kaneda audit src/ include/
```
````

````{solution} kaneda-desafio-1
```bash
kaneda audit src/ include/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Reemplazo de `gets` por `fgets`
:label: kaneda-desafio-2
Corregir lectura de teclado manteniendo el tamaño del buffer.

**Instrucción de ejecución:**
```bash
kaneda scan src/login.c
```
````

````{solution} kaneda-desafio-2
```bash
kaneda scan src/login.c
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Protección contra Format Strings
:label: kaneda-desafio-3
Revisar llamadas a `printf` y `syslog` que reciben buffers de usuario.

**Instrucción de ejecución:**
```bash
kaneda audit src/ --strict
```
````

````{solution} kaneda-desafio-3
```bash
kaneda audit src/ --strict
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-kaneda-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `kaneda` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-kaneda:
	@echo "=== Ejecutando verificación con kaneda ==="
	kaneda check src/ include/

.PHONY: check-kaneda
````

Ejecutá `make check-kaneda` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-kaneda-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`kaneda`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Clang Static Analyzer + Semgrep C Rules + Dangerous Functions AST Matcher`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-kaneda-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`kaneda`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C del Estudiante] --> KND[Kaneda: Auditor de Seguridad]
    KND -->|Detección gets/strcpy/sprintf| AST[Clang AST Matcher]
    KND -->|Alerta de Vulnerabilidad| RIP[Ripley: Microkernel de Reglas]
    KND -->|Penalización de Seguridad| DRD[Dredd: Autograding Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente C (.c y .h)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ripley (reglas 0x3000h de seguridad)`
- `dredd (bloqueo de entregas vulnerables)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `ripley`, `daedalus`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `kaneda` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
kaneda audit src/ && ripley check src/
````

---

(manual-kaneda-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `kaneda` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
