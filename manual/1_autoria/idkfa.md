---
title: "Manual de Referencia: idkfa"
subtitle: "Idkfa — Síntesis Procedural de Código C, Cuestionarios Anti-Copia y Trazado para Moodle"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-idkfa)=
# Idkfa — Síntesis Procedural de Código C, Cuestionarios Anti-Copia y Trazado para Moodle

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Generación de cuestionarios Moodle XML con variantes de código C compiladas y ejecutadas con GCC en tiempo real para obtener las respuestas numéricas exactas de cada tema.
```

---

(manual-idkfa-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`idkfa`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-idkfa-instalacion)=
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

### 2.2 Métodos de Instalación de `idkfa`

Podés instalar `idkfa` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `idkfa` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
idkfa --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
idkfa doctor
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

(manual-idkfa-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `idkfa`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `idkfa generate <plantilla.yaml> -n 20 -o banco.xml` | Sintetiza 20 variantes de preguntas C y genera Moodle XML. |
| `idkfa render <plantilla.yaml>` | Previsualiza el código C generado y su salida exacta de ejecución. |
| `idkfa spellcheck <plantilla.yaml>` | Verifica ortografía y enunciados con LanguageTool. |
| `idkfa doctor` | Verifica la instalación de GCC y Moodle XML parser. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-idkfa-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Plantilla Idkfa con variables procedurales {{A}}, {{B}}, {{OP}}
#include <stdio.h>
int main(void) {
    int x = {{A}};
    int y = {{B}};
    x {{OP}}= y;
    printf("%d\n", x);
    return 0;
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
idkfa generate <plantilla.yaml> -n 20 -o banco.xml
````

### Salida Obtenida en Consola

````{code-block} text
[✓] Compilando variante 1 (A=12, B=4, OP=+): Salida GCC = '16'
[✓] Compilando variante 2 (A=20, B=3, OP=*): Salida GCC = '60'
[✓] Generadas 20 preguntas con retroalimentación paso a paso en banco_moodle.xml
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-idkfa-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`idkfa`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Cuestionario de Punteros y Arreglos
:label: idkfa-desafio-1
Sintetizar 30 variantes de seguimiento de aritmética de punteros.

**Instrucción de ejecución:**
```bash
idkfa generate templates/punteros.yaml -n 30 -o moodle_ptr.xml
```
````

````{solution} idkfa-desafio-1
```bash
idkfa generate templates/punteros.yaml -n 30 -o moodle_ptr.xml
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Preguntas de Seguimiento de Lazos
:label: idkfa-desafio-2
Generar ejercicios de conteo de iteraciones en lazos anidados.

**Instrucción de ejecución:**
```bash
idkfa generate templates/lazos.yaml -n 25 -o moodle_lazos.xml
```
````

````{solution} idkfa-desafio-2
```bash
idkfa generate templates/lazos.yaml -n 25 -o moodle_lazos.xml
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auditoría Lingüística del Banco
:label: idkfa-desafio-3
Comprobar ortografía en las explicaciones paso a paso de las respuestas.

**Instrucción de ejecución:**
```bash
idkfa spellcheck templates/punteros.yaml
```
````

````{solution} idkfa-desafio-3
```bash
idkfa spellcheck templates/punteros.yaml
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-idkfa-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `idkfa` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-idkfa:
	@echo "=== Ejecutando verificación con idkfa ==="
	idkfa check src/ include/

.PHONY: check-idkfa
````

Ejecutá `make check-idkfa` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-idkfa-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`idkfa`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Procedural C Template Engine + GCC Runner en Sandbox + Moodle XML Serializer`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-idkfa-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`idkfa`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    TPL[Plantillas YAML con Variables] --> IDK[Idkfa: Síntesis Procedural]
    IDK -->|Compilación y Ejecución| GCC[GCC: Cálculo de Respuestas]
    IDK -->|Cuestionarios XML Anti-Copia| MDL[Moodle-Toolbox: Bancos Campus]
    IDK -->|Variantes de Seguimiento| ALU[Alucard: Exámenes Impresos]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Plantillas YAML con variables aleatorias y código C` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `moodle-toolbox (bancos XML)`
- `alucarD (preguntas de parcial)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `alucarD`, `moodle-toolbox`, `daedalus` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `idkfa` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
idkfa generate templates/punteros.yaml -n 50 -o banco_ptr.xml && questions validate banco_ptr.xml
````

---

(manual-idkfa-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `idkfa` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
