---
title: "Manual de Referencia: dietrich"
subtitle: "Dietrich — Validador de Cobertura Lógica MC/DC (Modified Condition/Decision Coverage) en C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-dietrich)=
# Dietrich — Validador de Cobertura Lógica MC/DC (Modified Condition/Decision Coverage) en C

````{abstract}
**Rol en el ecosistema:** Análisis formal de cobertura lógica sobre condiciones booleanas complejas en estructuras de control (if, while), manteniendo que cada condición atómica afecte independientemente el resultado.
````

---

(manual-dietrich-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`dietrich`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-dietrich-instalacion)=
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

### 2.2 Métodos de Instalación de `dietrich`

Podés instalar `dietrich` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `dietrich` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
dietrich --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
dietrich doctor
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

(manual-dietrich-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `dietrich`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `dietrich analyze src/auth.c` | Calcula la matriz de cobertura MC/DC sobre todas las decisiones lógicas. |
| `dietrich report --md reporte_mcdc.md src/` | Genera el informe de pares de prueba faltantes en Markdown. |
| `dietrich test-matrix src/controlador.c` | Imprime la tabla de verdad y combinaciones evaluadas. |
| `dietrich doctor` | Verifica la integración con gcov y llvm-cov. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-dietrich-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdbool.h>

// Decisión booleana compuesta con 3 condiciones atómicas: (A && B) || C
bool autorizar_acceso(bool es_admin, bool tiene_token, bool modo_emergencia) {
    if ((es_admin && tiene_token) || modo_emergencia) {
        return true;
    }
    return false;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
dietrich analyze src/auth.c
````

### Salida Obtenida en Consola

````{code-block} text
Decisión: ((es_admin && tiene_token) || modo_emergencia) en auth.c:5
┌─────────────────────────┬──────────────┬──────────────┬──────────────────┐
│ Condición Atómica       │ True Outcome │ False Outcome│ MC/DC Satisfecho │
├─────────────────────────┼──────────────┼──────────────┼──────────────────┤
│ A (es_admin)            │ Testcase #1  │ Testcase #2  │ ✓ SÍ             │
│ B (tiene_token)         │ Testcase #1  │ Testcase #3  │ ✓ SÍ             │
│ C (modo_emergencia)     │ Testcase #4  │ Testcase #5  │ ✓ SÍ             │
└─────────────────────────┴──────────────┴──────────────┴──────────────────┘
[✓] Cobertura MC/DC: 100% (4 pares de prueba independientes cubiertos).
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-dietrich-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`dietrich`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Auditoría de Validador de Acceso
Evaluar si la suite de tests actual cubre todas las ramas atómicas de `autorizar_acceso()`.

**Instrucción de ejecución:**
```bash
dietrich analyze src/auth.c
```
````

````{solution} Desafío 1
```bash
dietrich analyze src/auth.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Generación de Pares de Prueba Faltantes
Obtener los casos de prueba requeridos para satisfacer 100% MC/DC en un clasificador.

**Instrucción de ejecución:**
```bash
dietrich test-matrix src/clasificador.c
```
````

````{solution} Desafío 2
```bash
dietrich test-matrix src/clasificador.c
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Informe para Certificación Docente
Exportar el informe Markdown de cobertura lógica de la entrega.

**Instrucción de ejecución:**
```bash
dietrich report --md reporte_mcdc.md src/
```
````

````{solution} Desafío 3
```bash
dietrich report --md reporte_mcdc.md src/
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-dietrich-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `dietrich` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-dietrich:
	@echo "=== Ejecutando verificación con dietrich ==="
	dietrich check src/ include/

.PHONY: check-dietrich
````

Ejecutá `make check-dietrich` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-dietrich-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`dietrich`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `gcov / llvm-cov AST Instrumenter + Boolean Condition Parser + Truth Table Evaluator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-dietrich-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`dietrich`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C + Tests Unitarios] --> DTR[Dietrich: Cobertura MC/DC]
    DTR -->|Instrumentación Lógica| GCOV[gcov / llvm-cov Engine]
    DTR -->|Tabla de Verdad y Pares| REP[Reporte de Cobertura]
    DTR -->|Casos Faltantes| VAS[Vassili: Mutation Testing]
    DTR -->|Métricas de Calidad| DRD[Dredd: Calificador Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código C y suites de pruebas unitarias` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (reporte de cobertura lógica)`
- `vassili (mutation testing)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `vassili`, `drake`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `dietrich` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
dietrich analyze src/auth.c --tests bin/test_suite --md reporte_mcdc.md
````

---

(manual-dietrich-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `dietrich` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
