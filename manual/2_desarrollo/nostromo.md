---
title: "Manual de Referencia: nostromo"
subtitle: "Nostromo — Sandbox de Ejecución Segura en Linux con Bubblewrap y Test Runner"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-nostromo)=
# Nostromo — Sandbox de Ejecución Segura en Linux con Bubblewrap y Test Runner

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Ejecución aislada y segura de binarios de estudiantes en contenedores ligeros de kernel (Bubblewrap / setrlimit), control de tiempo de CPU, memoria máxima y evaluación de casos de prueba .in/.out.
```

---

(manual-nostromo-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`nostromo`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-nostromo-instalacion)=
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

### 2.2 Métodos de Instalación de `nostromo`

Podés instalar `nostromo` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `nostromo` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
nostromo --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
nostromo doctor
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

(manual-nostromo-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `nostromo`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `nostromo run --binary ./bin/programa --testcases testcases/` | Evalúa la suite de pruebas .in/.out en sandbox aislado. |
| `nostromo exec --timeout 2s --mem 32M -- ./bin/programa` | Ejecuta un binario con cuotas estrictas de CPU y RAM. |
| `nostromo doctor` | Verifica capacidades no privilegiadas de Bubblewrap en el kernel. |
| `nostromo gen-testcases --binary ./bin/canon -i inputs/` | Genera los archivos .out canónicos esperados. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-nostromo-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Programa de alumno evaluado bajo sandbox Nostromo
#include <stdio.h>

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", a + b);
    }
    return 0;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
nostromo run --binary ./bin/programa --testcases testcases/
````

### Salida Obtenida en Consola

````{code-block} text
EVALUACIÓN NOSTROMO SANDBOX:
 ✓ Testcase 01 (suma_positivos.in): PASSED (12 ms, 4.2 MB)
 ✓ Testcase 02 (suma_negativos.in): PASSED (10 ms, 4.1 MB)
 ✓ Testcase 03 (limite_maximo.in): PASSED (11 ms, 4.2 MB)
[✓] 3/3 casos de prueba aprobados (Sandbox: Bubblewrap bwrap).
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-nostromo-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`nostromo`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Evaluación de Casos de Prueba en Sandbox
:label: nostromo-desafio-1
Correr una suite de 10 testcases sobre el ejecutable del TP.

**Instrucción de ejecución:**
```bash
nostromo run --binary ./bin/tp1 --testcases testcases/
```
````

````{solution} nostromo-desafio-1
```bash
nostromo run --binary ./bin/tp1 --testcases testcases/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Detección de Lazos Infinitos (Timeout)
:label: nostromo-desafio-2
Verificar que el sandbox interrumpe procesos que superan 2 segundos.

**Instrucción de ejecución:**
```bash
nostromo exec --timeout 2s -- ./bin/bucle_infinito
```
````

````{solution} nostromo-desafio-2
```bash
nostromo exec --timeout 2s -- ./bin/bucle_infinito
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Límite de Consumo de Memoria
:label: nostromo-desafio-3
Comprobar que un programa que solicita 500 MB es abortado con cuota de 32 MB.

**Instrucción de ejecución:**
```bash
nostromo exec --mem 32M -- ./bin/come_memoria
```
````

````{solution} nostromo-desafio-3
```bash
nostromo exec --mem 32M -- ./bin/come_memoria
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-nostromo-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `nostromo` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-nostromo:
	@echo "=== Ejecutando verificación con nostromo ==="
	nostromo check src/ include/

.PHONY: check-nostromo
````

Ejecutá `make check-nostromo` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-nostromo-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`nostromo`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Linux Bubblewrap (bwrap) + setrlimit CPU/RAM Quotas + Unix Pipes IPC + Timeout Watchdog`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-nostromo-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`nostromo`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    BIN[Binario Compilado] --> NOS[Nostromo: Sandbox Bubblewrap]
    TEST[Testcases .in/.out] --> NOS
    NOS -->|Aislamiento de Kernel (bwrap)| LINUX[Linux Namespaces / setrlimit]
    NOS -->|Ejecución Exitosa| DRD[Dredd: Autograding Masivo]
    NOS -->|Señal Fatal SIGSEGV| HAL[Hal: Forense de Core Dumps]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios compilados por Daedalus y testcases de Deckard o Tyrell` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (resultados de ejecución segura)`
- `hal (captura de crashes)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `daedalus`, `dredd`, `tyrell`, `hal` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `nostromo` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
nostromo run --binary ./bin/programa --testcases testcases/
````

---

(manual-nostromo-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `nostromo` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
