---
title: "Manual de Referencia: weyl"
subtitle: "Weyl — Diffing Semántico y Comparación Estructural de ASTs contra resolvé Canónicas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-weyl)=
# Weyl — Diffing Semántico y Comparación Estructural de ASTs contra resolvé Canónicas

````{abstract}
**Rol en el ecosistema:** Comparación estructural y semántica de código C entre la entrega del estudiante y la solución de referencia docente, ignorando cambios cosméticos de nombres de variables, espacios y comentarios.
````

---

(manual-weyl-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`weyl`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-weyl-instalacion)=
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

### 2.2 Métodos de Instalación de `weyl`

Podés instalar `weyl` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `weyl` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
weyl --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
weyl doctor
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

(manual-weyl-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `weyl`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `weyl diff src/lista.c canon/lista_canon.c` | Compara semánticamente dos implementaciones C a nivel AST. |
| `weyl ast-dump <archivo.c>` | Visualiza el árbol sintáctico abstracto normalizado. |
| `weyl similarity src/ canon/ --threshold 0.80` | Calcula el porcentaje de equivalencia estructural de la solución. |
| `weyl doctor` | Comprueba el motor Tree-Sitter de C. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-weyl-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Implementación A (Estudiante)
int suma(int x, int y) {
    int res = x + y;
    return res;
}

// Implementación B (Solución Canónica Docente)
// Weyl detecta que ambas son semánticamente equivalentes a nivel AST
int suma(int a, int b) {
    return a + b;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
weyl diff src/lista.c canon/lista_canon.c
````

### Salida Obtenida en Consola

````{code-block} text
WEYL SEMANTIC DIFF:
┌───────────────────────────┬────────────────────────────────────────────────────────┐
│ Métrica                   │ Resultado                                              │
├───────────────────────────┼────────────────────────────────────────────────────────┤
│ Similitud Estructural AST │ 98.4% (Equivalencia Semántica Canónica)                │
│ Funciones Homólogas       │ 4/4 identificadas (lista_crear, insertar, borrar, fin) │
│ Diferencias Detectadas    │ Variable intermedia 'res' omitida en versión canónica  │
└───────────────────────────┴────────────────────────────────────────────────────────┘
[✓] La solución del estudiante cumple con la estructura arquitectónica esperada.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-weyl-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`weyl`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Comparación Semántica contra Solución Docente
Verificar si el algoritmo implementado coincide estructuralmente con la solución modelo.

**Instrucción de ejecución:**
```bash
weyl diff src/lista.c canon/lista_canon.c
```
````

````{solution} Desafío 1
```bash
weyl diff src/lista.c canon/lista_canon.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Inspección del Árbol AST Normalizado
Examinar cómo Weyl abstrae los nombres de variables.

**Instrucción de ejecución:**
```bash
weyl ast-dump src/ordenamiento.c
```
````

````{solution} Desafío 2
```bash
weyl ast-dump src/ordenamiento.c
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Detección de Funciones Faltantes
Comprobar qué funciones requeridas de la API no fueron implementadas.

**Instrucción de ejecución:**
```bash
weyl diff src/tda.c canon/tda.c --check-missing
```
````

````{solution} Desafío 3
```bash
weyl diff src/tda.c canon/tda.c --check-missing
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-weyl-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `weyl` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-weyl:
	@echo "=== Ejecutando verificación con weyl ==="
	weyl check src/ include/

.PHONY: check-weyl
````

Ejecutá `make check-weyl` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-weyl-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`weyl`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C AST Structural Normalizer + Levenshtein AST Distance Calculator + Canonical Diff Engine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-weyl-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`weyl`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    EST[Entrega del Estudiante] --> WEY[Weyl: Diffing Semántico]
    CAN[Solución Canónica Docente] --> WEY
    WEY -->|Normalización de Nombres/Espacios| AST[Tree-Sitter AST Normalizer]
    WEY -->|Equivalencia Estructural| DRD[Dredd: Autograding Masivo]
    WEY -->|Verificación de APIs| DKD[Deckard: Banco Canónico]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Entrega del estudiante y solución canónica docente` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (similitud semántica y funciones faltantes)`
- `deckard (banco canónico)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `deckard`, `callahan`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `weyl` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
weyl diff src/lista.c canon/lista.c --threshold 0.85
````

---

(manual-weyl-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `weyl` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
