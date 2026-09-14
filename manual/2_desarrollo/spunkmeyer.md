---
title: "Manual de Referencia: spunkmeyer"
subtitle: "Spunkmeyer — Detector de Antipatrones de Programación y Vicios Didácticos en C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-spunkmeyer)=
# Spunkmeyer — Detector de Antipatrones de Programación y Vicios Didácticos en C

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Detección estática de antipatrones típicos de estudiantes: casteo innecesario de `malloc()`, lazos `while (!feof(f))`, comparaciones redundantes `if (cond == true)`, y punteros a variables locales devueltos desde el stack.
````

---

(manual-spunkmeyer-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`spunkmeyer`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-spunkmeyer-instalacion)=
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

### 2.2 Métodos de Instalación de `spunkmeyer`

Podés instalar `spunkmeyer` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `spunkmeyer` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
spunkmeyer --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
spunkmeyer doctor
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

(manual-spunkmeyer-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `spunkmeyer`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `spunkmeyer detect src/ include/` | Escanea el código fuente en busca de antipatrones educativos. |
| `spunkmeyer explain <codigo_antipatron>` | Explica por qué una construcción es considerada un antipatrón y cómo corregirla. |
| `spunkmeyer list` | Lista todos los antipatrones catalogados por Spunkmeyer. |
| `spunkmeyer fix src/` | Aplica correcciones automáticas sobre antipatrones seguros. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-spunkmeyer-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void antipatrones_comunes(FILE *f) {
    // 1. Casteo de malloc innecesario en C
    int *v = (int*) malloc(sizeof(int) * 10);
    
    // 2. Comparación booleana redundante
    bool flag = true;
    if (flag == true) { /* ... */ }
    
    // 3. while(!feof) lee el último dato duplicado
    int x;
    while (!feof(f)) {
        fscanf(f, "%d", &x);
    }
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
spunkmeyer detect src/ include/
````

### Salida Obtenida en Consola

````{code-block} text
⚠️ SPUNKMEYER DETECTÓ 3 ANTIPATRONES:
┌──────────────┬─────────────┬────────────────────────────────────────────────────────┐
│ Ubicación    │ Antipatrón  │ Corrección Pedagógica Recomendada                      │
├──────────────┼─────────────┼────────────────────────────────────────────────────────┤
│ app.c:6:14   │ MALLOC_CAST │ No castees el retorno de malloc() en C: 'int *v = mal…'│
│ app.c:10:9   │ BOOL_CMP    │ Simplificá 'if (flag == true)' por 'if (flag)'         │
│ app.c:14:5   │ WHILE_FEOF  │ 'while (!feof(f))' es erróneo. Validá el retorno de …  │
└──────────────┴─────────────┴────────────────────────────────────────────────────────┘
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-spunkmeyer-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`spunkmeyer`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Limpieza de Antipatrones en Código de Alumno
:label: spunkmeyer-desafio-1
Escanear una entrega y remover todos los vicios de programación.

**Instrucción de ejecución:**
```bash
spunkmeyer detect src/
```
````

````{solution} spunkmeyer-desafio-1
```bash
spunkmeyer detect src/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Consulta de Explicación de `while (!feof)`
:label: spunkmeyer-desafio-2
Leer el fundamento técnico de por qué `feof` no se activa antes de intentar leer.

**Instrucción de ejecución:**
```bash
spunkmeyer explain WHILE_FEOF
```
````

````{solution} spunkmeyer-desafio-2
```bash
spunkmeyer explain WHILE_FEOF
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auto-Corrección de Comparaciones Booleanas
:label: spunkmeyer-desafio-3
Corregir automáticamente expresiones redundantes con `--fix`.

**Instrucción de ejecución:**
```bash
spunkmeyer fix src/ --dry-run
```
````

````{solution} spunkmeyer-desafio-3
```bash
spunkmeyer fix src/ --dry-run
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-spunkmeyer-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `spunkmeyer` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-spunkmeyer:
	@echo "=== Ejecutando verificación con spunkmeyer ==="
	spunkmeyer check src/ include/

.PHONY: check-spunkmeyer
````

Ejecutá `make check-spunkmeyer` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-spunkmeyer-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`spunkmeyer`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `libclang AST Matcher + Antipattern Regex Classifier + Pedagogical Remediation Engine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-spunkmeyer-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`spunkmeyer`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C del Estudiante] --> SPK[Spunkmeyer: Detector de Antipatrones]
    SPK -->|Detección de Vicios Didácticos| AST[Clang AST Matcher]
    SPK -->|Fundamento Normativo| ESP[Esper: Citas ISO C11/C23]
    SPK -->|Reglas 0x1000h| RIP[Ripley: Microkernel de Auditoría]
    SPK -->|Autocorrección Segura| GAF[Gaff: Linter de Estilo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente C` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ripley (reglas 0x1000h)`
- `daedalus (alertas tempranas)`
- `dredd (corrección)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `ripley`, `gaff`, `esper` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `spunkmeyer` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
spunkmeyer detect src/ && spunkmeyer fix src/
````

---

(manual-spunkmeyer-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `spunkmeyer` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
