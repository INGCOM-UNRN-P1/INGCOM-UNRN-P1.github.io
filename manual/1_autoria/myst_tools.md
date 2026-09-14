---
title: "Manual de Referencia: myst-tools"
subtitle: "Myst-Tools — Suite de Normalización, Formateo a 80 Columnas, Anclas e Índices MyST"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-myst_tools)=
# Myst-Tools — Suite de Normalización, Formateo a 80 Columnas, Anclas e Índices MyST

````{abstract}
**Rol en el ecosistema:** Automatización y estandarización de material didáctico en formato MyST Markdown: formateo a 80 columnas respetando directivas, anclas semánticas, generación de índices y corrector LanguageTool.
````

---

(manual-myst_tools-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`myst-tools`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-myst_tools-instalacion)=
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

### 2.2 Métodos de Instalación de `myst-tools`

Podés instalar `myst-tools` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `myst_tools` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
myst_tools --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
myst_tools doctor
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

(manual-myst_tools-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `myst-tools`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `myst-tools fmt apunte/ [-w 80]` | Formatea la prosa a 80 columnas preservando directivas y código. |
| `myst-tools fix-anchors .` | Detecta y renombra anclas duplicadas `(slug)=` entre capítulos. |
| `myst-tools add-anchors docs/` | Inserta anclas automáticas en todos los encabezados Markdown. |
| `myst-tools gen-apunte apunte/` | Genera el índice temático general `indice.md`. |
| `myst-tools spellcheck apunte/ --premium` | Audita ortografía y estilo con LanguageTool (local o cloud). |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-myst_tools-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Directiva MyST Markdown formateada por myst-tools
(seccion-punteros)=
# Punteros y Gestión de Memoria

```{note}
Un puntero en C almacena la dirección de memoria de otra variable.
```

```{code-block} c
:linenos:
int x = 10;
int *p = &x;
```
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
myst-tools fmt apunte/ [-w 80]
````

### Salida Obtenida en Consola

````{code-block} text
[✓] 18 archivos formateados a 80 columnas respetando bloques MyST.
[✓] 0 colisiones de anclas duplicadas detectadas.
[✓] Índice general generado en apunte/indice.md.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-myst_tools-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`myst-tools`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Formateo Estándar de Apuntes
Normalizar el ancho de línea de un capítulo a 80 columnas.

**Instrucción de ejecución:**
```bash
myst-tools fmt apunte/capitulo1.md
```
````

````{solution} Desafío 1
```bash
myst-tools fmt apunte/capitulo1.md
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Resolución de Colisión de Anclas
Detectar y corregir encabezados con anclas repetidas.

**Instrucción de ejecución:**
```bash
myst-tools fix-anchors apunte/
```
````

````{solution} Desafío 2
```bash
myst-tools fix-anchors apunte/
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Corrección Ortográfica con LanguageTool
Auditar la ortografía de la guía de trabajos prácticos.

**Instrucción de ejecución:**
```bash
myst-tools spellcheck guias/ --lang es-AR
```
````

````{solution} Desafío 3
```bash
myst-tools spellcheck guias/ --lang es-AR
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-myst_tools-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `myst-tools` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-myst_tools:
	@echo "=== Ejecutando verificación con myst-tools ==="
	myst-tools check src/ include/

.PHONY: check-myst_tools
````

Ejecutá `make check-myst_tools` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-myst_tools-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`myst-tools`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `MyST Markdown AST Parser + 80-Col Prosa Formatter + LanguageTool Spellchecker + Slug Index Generator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-myst_tools-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`myst-tools`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    DKD[Deckard: Guías de Ejercicios] --> MYST[Myst-Tools: Suite MyST]
    CRB[Corbel: Documentación TDAs] --> MYST
    GAF[Gaff / Ripley: Reglas de Estilo] --> MYST
    MYST -->|Formateo a 80 Columnas| FMT[Prosa Normalizada]
    MYST -->|Auditoría Lingüística| LT[LanguageTool API]
    MYST -->|Sitio Web de Cátedra| HTML[Jupyter Book / MyST HTML]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Apuntes, guías de Deckard, documentación de Corbel, reglas de Gaff` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `Jupyter Book / MyST HTML (sitios web de cátedra)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `deckard`, `corbel`, `gaff`, `moodle-toolbox` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `myst-tools` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
myst-tools fmt apunte/ && myst-tools fix-anchors apunte/ && myst-tools spellcheck apunte/
````

---

(manual-myst_tools-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `myst-tools` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
