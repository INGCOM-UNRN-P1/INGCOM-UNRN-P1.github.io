---
title: "Manual de Referencia: tyrell"
subtitle: "Tyrell — Generador Sintético y Determinista de Datasets y Casos de Prueba con Semillas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-tyrell)=
# Tyrell — Generador Sintético y Determinista de Datasets y Casos de Prueba con Semillas

````{abstract}
**Rol en el ecosistema:** Generación determinista y reproducible de datasets masivos (números, matrices, cadenas, registros estructurados) mediante generadores pseudoaleatorios con semilla fija para pruebas de carga y benchmarking.
````

---

(manual-tyrell-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`tyrell`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-tyrell-instalacion)=
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

### 2.2 Métodos de Instalación de `tyrell`

Podés instalar `tyrell` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `tyrell` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
tyrell --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
tyrell doctor
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

(manual-tyrell-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `tyrell`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `tyrell generate --schema dataset.yaml -n 1000 -o datos.in` | Genera un dataset de 1000 registros estructurados. |
| `tyrell matrix --rows 100 --cols 100 --seed 42 -o matriz.in` | Genera una matriz aleatoria determinista. |
| `tyrell fuzz-strings -n 50 -o strings.in` | Genera cadenas de prueba con caracteres especiales y UTF-8. |
| `tyrell doctor` | Verifica generadores de datos y esquemas. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-tyrell-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Esquema YAML procesado por Tyrell:
// schema:
//   - name: id
//     type: integer
//     min: 1000
//     max: 9999
//   - name: promedio
//     type: float
//     min: 1.0
//     max: 10.0
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
tyrell generate --schema dataset.yaml -n 1000 -o datos.in
````

### Salida Obtenida en Consola

````{code-block} text
[✓] Generados 1,000 registros en datos.in (Semilla: 0x1337BEEF)
[✓] Tamaño del archivo: 42.5 KB | Integridad SHA-256: 8f4a3c2...
[✓] Salida reproducible: la misma semilla generará exactamente los mismos datos.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-tyrell-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`tyrell`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Generación de Vector de 100,000 Elementos
Crear un archivo de entrada para pruebas de rendimiento de algoritmos de ordenamiento.

**Instrucción de ejecución:**
```bash
tyrell generate --type int --count 100000 --seed 12345 -o vector_grande.in
```
````

````{solution} Desafío 1
```bash
tyrell generate --type int --count 100000 --seed 12345 -o vector_grande.in
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Dataset de Estructuras para TDA
Generar archivo de texto con datos de paquetes postales para pruebas del TP.

**Instrucción de ejecución:**
```bash
tyrell generate --schema schemas/envios.yaml -n 500 -o envios.in
```
````

````{solution} Desafío 2
```bash
tyrell generate --schema schemas/envios.yaml -n 500 -o envios.in
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Casos de Prueba con Caracteres Extremos
Generar cadenas con caracteres nulos, emojis y secuencias de escape.

**Instrucción de ejecución:**
```bash
tyrell fuzz-strings -n 100 -o strings_extremos.in
```
````

````{solution} Desafío 3
```bash
tyrell fuzz-strings -n 100 -o strings_extremos.in
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-tyrell-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `tyrell` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-tyrell:
	@echo "=== Ejecutando verificación con tyrell ==="
	tyrell check src/ include/

.PHONY: check-tyrell
````

Ejecutá `make check-tyrell` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-tyrell-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`tyrell`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Mersenne Twister / PCG Deterministic RNG + Schema-Driven Data Generator + SHA-256 Checksum Validator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-tyrell-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`tyrell`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SCH[Esquemas YAML: Tipos y Rangos] --> TYR[Tyrell: Generador Sintético]
    TYR -->|Generación Determinista con Semilla| RNG[Mersenne Twister PRNG]
    TYR -->|Datasets Masivos .in| NOS[Nostromo: Sandbox y Test Runner]
    TYR -->|Cargas de Estrés| FRR[Ferro: Perfilador de Rendimiento]
    TYR -->|Casos de Prueba| DRD[Dredd: Autograding Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Esquemas YAML de datos y semillas fijas` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `nostromo (testcases .in)`
- `ferro (benchmarking)`
- `dredd (evaluación masiva)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `nostromo`, `drake`, `ferro` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `tyrell` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
tyrell generate --schema schemas/envios.yaml -n 1000 --seed 42 -o testcases/envios.in
````

---

(manual-tyrell-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `tyrell` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
