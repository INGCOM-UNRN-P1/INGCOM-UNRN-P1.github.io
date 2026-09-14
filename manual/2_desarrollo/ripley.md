---
title: "Manual de Referencia: ripley"
subtitle: "Ripley — Linter Pedagógico de Reglas Institucionales 0xXXXXh y Microkernel de Auditoría"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-ripley)=
# Ripley — Linter Pedagógico de Reglas Institucionales 0xXXXXh y Microkernel de Auditoría

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Linter central de cátedra que ejecuta el catálogo completo de reglas pedagógicas 0xXXXXh (estilo, modularidad, seguridad, antipatrones) y orquesta plugins desacoplados.
````

---

(manual-ripley-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`ripley`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-ripley-instalacion)=
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

### 2.2 Métodos de Instalación de `ripley`

Podés instalar `ripley` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `ripley` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
ripley --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
ripley doctor
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

(manual-ripley-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `ripley`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `ripley check src/ include/` | Ejecuta todas las reglas activas de cátedra sobre el proyecto. |
| `ripley check --rule 0x1001h src/` | Audita una regla específica del catálogo. |
| `ripley explain 0x0001h` | Explica en detalle el fundamento pedagógico de una regla. |
| `ripley list-rules` | Muestra el catálogo completo clasificado por categorías. |
| `ripley doctor` | Verifica dependencias y plugins registrados en el microkernel. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-ripley-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Violación de regla institucional 0x1001h (Estructura de control sin bloque de llaves)
void procesar(int a) {
    if (a > 0)
        a++; // Falla 0x1001h: Toda sentencia de control debe tener llaves {}
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
ripley check src/ include/
````

### Salida Obtenida en Consola

````{code-block} text
⚠️ REPORTE DE AUDITORÍA RIPLEY (Reglas de Cátedra):
┌──────────────┬─────────┬────────────────────────────────────────────────────────┐
│ Archivo:L:C  │ Regla   │ Descripción del Diagnóstico                            │
├──────────────┼─────────┼────────────────────────────────────────────────────────┤
│ proc.c:3:5   │ 0x1001h │ Estructura de control 'if' sin bloque explícito '{}'.  │
│ proc.c:1:23  │ 0x000Bh │ Llave de apertura en estilo K&R (exigido: Allman).     │
└──────────────┴─────────┴────────────────────────────────────────────────────────┘
💡 Ejecutá 'ripley explain 0x1001h' para ver el ejemplo correcto y fundamento.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-ripley-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`ripley`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Auditoría Integral de Código Estudiantil
:label: ripley-desafio-1
Escanear todo el código fuente antes de enviar al autograder.

**Instrucción de ejecución:**
```bash
ripley check src/ include/
```
````

````{solution} ripley-desafio-1
```bash
ripley check src/ include/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Consulta de Fundamentos Pedagógicos
:label: ripley-desafio-2
Consultar por qué está prohibida la sentencia `goto` (0x1006h).

**Instrucción de ejecución:**
```bash
ripley explain 0x1006h
```
````

````{solution} ripley-desafio-2
```bash
ripley explain 0x1006h
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Verificación con Modo Estricto de Cátedra
:label: ripley-desafio-3
Correr auditoría bloqueando commits si existen violaciones institucionales.

**Instrucción de ejecución:**
```bash
ripley check src/ --strict
```
````

````{solution} ripley-desafio-3
```bash
ripley check src/ --strict
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-ripley-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `ripley` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-ripley:
	@echo "=== Ejecutando verificación con ripley ==="
	ripley check src/ include/

.PHONY: check-ripley
````

Ejecutá `make check-ripley` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-ripley-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`ripley`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Python Microkernel Architecture + Pluggy Dynamic Plugin System + Multi-Format Reporter (Rich, JSON, MD)`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-ripley-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`ripley`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C del Estudiante] --> RIP[Ripley: Microkernel de Cátedra]
    GAF[Gaff: Estilo 0x00XXh] --> RIP
    SPK[Spunkmeyer: Antipatrones 0x10XXh] --> RIP
    MOT[Motoko: Modularidad 0x20XXh] --> RIP
    KND[Kaneda: Seguridad 0x30XXh] --> RIP
    ZHO[Zhora: Macros 0x40XXh] --> RIP
    RIP -->|Evaluación Unificada| DRD[Dredd: Autograding Masivo]
    RIP -->|Reporte Pedagógico| TERM[Terminal del Estudiante]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código C de entregas de estudiantes` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (orquestación masiva)`
- `Estudiante (diagnósticos en terminal)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `gaff`, `spunkmeyer`, `kaneda`, `zhora`, `motoko`, `wierzbowski`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `ripley` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
ripley check src/ include/ --md reporte_auditoria.md
````

---

(manual-ripley-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `ripley` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
