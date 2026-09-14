---
title: "Manual de Referencia: daedalus"
subtitle: "Daedalus — Compilador Asistido con Cátedra Flags y Traducción de Diagnósticos GCC/Clang"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-daedalus)=
# Daedalus — Compilador Asistido con Cátedra Flags y Traducción de Diagnósticos GCC/Clang

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Compilador pedagógico que aplica los flags de cátedra (-std=c11, -Wall, -Wextra, -Werror, -pedantic) y traduce mensajes crípticos del compilador a español claro con explicaciones didácticas.
```

---

(manual-daedalus-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`daedalus`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-daedalus-instalacion)=
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

### 2.2 Métodos de Instalación de `daedalus`

Podés instalar `daedalus` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `daedalus` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
daedalus --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
daedalus doctor
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

(manual-daedalus-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `daedalus`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `daedalus compile src/*.c -o ./bin/programa` | Compila bajo flags estrictos con traducción pedagógica. |
| `daedalus explain "<error_str>"` | Explica un error o advertencia de GCC/Clang en lenguaje accesible. |
| `daedalus suggest-flags` | Sugiere los flags defensivos adecuados según el estándar fijado. |
| `daedalus doctor` | Verifica compiladores GCC y Clang instalados en el sistema. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-daedalus-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>

int main(void) {
    int x; // Variable sin inicializar
    if (x = 5) { // Asignación dentro del if en lugar de comparación ==
        printf("Valor: %d\n", x);
    }
    return 0;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
daedalus compile src/*.c -o ./bin/programa
````

### Salida Obtenida en Consola

````{code-block} text
[!] ERROR PEDAGÓGICO DAEDALUS en main.c:5:9:
    Advertencia: sugerencia de paréntesis alrededor de la asignación usada como condición de verdad [-Wparentheses]

💡 EXPLICACIÓN DE CÁTEDRA:
    Escribiste 'x = 5' con un solo '=', lo cual ASIGNA el valor 5 a 'x' y siempre evalúa como verdadero.
    Si querías verificar igualdad, debés usar '==': 'if (x == 5)'.
    Si realmente deseabas una asignación dentro de la condición, encerrala entre paréntesis: 'if ((x = 5))'.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-daedalus-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`daedalus`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Corrección de Warnings Defensivos
:label: daedalus-desafio-1
Compilar un código con variables sin inicializar y resolver todos los warnings.

**Instrucción de ejecución:**
```bash
daedalus compile src/calculadora.c -o bin/calc
```
````

````{solution} daedalus-desafio-1
```bash
daedalus compile src/calculadora.c -o bin/calc
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Traducción de Error de Enlazado (Linker / undefined reference)
:label: daedalus-desafio-2
Explicar didácticamente el error `undefined reference to main` o función faltante.

**Instrucción de ejecución:**
```bash
daedalus explain "undefined reference to 'lista_crear'"
```
````

````{solution} daedalus-desafio-2
```bash
daedalus explain "undefined reference to 'lista_crear'"
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Configuración de Flags de Optimización y Debug
:label: daedalus-desafio-3
Compilar con símbolos DWARF completos para depurar con GDB.

**Instrucción de ejecución:**
```bash
daedalus compile src/main.c -g3 -o bin/debug_app
```
````

````{solution} daedalus-desafio-3
```bash
daedalus compile src/main.c -g3 -o bin/debug_app
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-daedalus-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `daedalus` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-daedalus:
	@echo "=== Ejecutando verificación con daedalus ==="
	daedalus check src/ include/

.PHONY: check-daedalus
````

Ejecutá `make check-daedalus` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-daedalus-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`daedalus`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `GCC 13/14 + Clang 18 + Regex Pedagogical Diagnostics Matcher + Cátedra Flags Engine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-daedalus-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`daedalus`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C del Estudiante] --> DAE[Daedalus: Compilador Pedagógico]
    DAE -->|Traducción de Warnings| TERM[Terminal Estudiante]
    DAE -->|Citas Normativas| ESP[Esper: Estándar ISO C11/C23]
    DAE -->|Binario con ASan/UBSan| TET[Tetsuo: Explicador Sanitizers]
    DAE -->|Binario Listo| NOS[Nostromo: Sandbox y Tests]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente de estudiantes y starter kits` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `tetsuo (sanitizers)`
- `hal (diagnósticos de crash)`
- `nostromo (ejecución)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `esper`, `ripley`, `hal`, `tetsuo` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `daedalus` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
daedalus compile src/*.c -o bin/app && nostromo run --binary ./bin/app
````

---

(manual-daedalus-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `daedalus` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
