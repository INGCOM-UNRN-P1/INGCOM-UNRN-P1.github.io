---
title: "Manual de Referencia: alucarD"
subtitle: "Alucard — Generador de Exámenes Impresos, Variantes Anti-Copia y Plantillas OMR"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-alucard)=
# Alucard — Generador de Exámenes Impresos, Variantes Anti-Copia y Plantillas OMR

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Generación y maquetación de exámenes presenciales con Typst, síntesis de variantes permutadas y lectura óptica OMR.
```

---

(manual-alucard-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`alucarD`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-alucard-instalacion)=
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

### 2.2 Métodos de Instalación de `alucarD`

Podés instalar `alucarD` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `alucard` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
alucard --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
alucard doctor
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

(manual-alucard-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `alucard`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `alucard render <examen.yaml>` | Compila el examen a PDF listo para impresión usando Typst. |
| `alucard randomize <examen.yaml> -n 4` | Genera 4 variantes/temas con opciones y ejercicios permutados. |
| `alucard omr-grid <examen.yaml>` | Genera la grilla de lectura óptica OMR para corrección rápida. |
| `alucard gift-lint <preguntas.gift>` | Audita la sintaxis y completitud de bancos de preguntas en formato GIFT. |
| `alucard spellcheck <examen.yaml>` | Verifica ortografía y gramática de enunciados con LanguageTool. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-alucard-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Pregunta de seguimiento de código para examen
int vec[] = {10, 20, 30, 40};
int *p = vec + 1;
*p += 5;
*(p + 2) -= 10;
printf("%d, %d\n", vec[1], vec[3]); // ¿Qué valor imprime?
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
alucard render <examen.yaml>
````

### Salida Obtenida en Consola

````{code-block} text
[✓] Compilando parcial_tema_1.typ -> parcial_tema_1.pdf (Typst 0.11)
[✓] Generada variante Tema 2 (semilla: 0xDEADBEEF) -> parcial_tema_2.pdf
[✓] Generada hoja de lectura óptica OMR de 20 preguntas -> omr_respuestas.pdf
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-alucard-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`alucarD`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Generación de Parcial con 3 Temas
:label: alucard-desafio-1
Definir un archivo `parcial.yaml` y compilar 3 temas con opciones permutadas.

**Instrucción de ejecución:**
```bash
alucard randomize parcial.yaml -n 3 -o ./pdf_temas
```
````

````{solution} alucard-desafio-1
```bash
alucard randomize parcial.yaml -n 3 -o ./pdf_temas
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Auditoría de Banco GIFT
:label: alucard-desafio-2
Validar que `preguntas.gift` no tenga opciones correctas faltantes.

**Instrucción de ejecución:**
```bash
alucard gift-lint preguntas.gift --fix
```
````

````{solution} alucard-desafio-2
```bash
alucard gift-lint preguntas.gift --fix
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Corrección Ortográfica con LanguageTool
:label: alucard-desafio-3
Verificar enunciados docentes antes de imprimir el examen.

**Instrucción de ejecución:**
```bash
alucard spellcheck parcial.yaml --lang es-AR
```
````

````{solution} alucard-desafio-3
```bash
alucard spellcheck parcial.yaml --lang es-AR
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-alucard-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `alucarD` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-alucard:
	@echo "=== Ejecutando verificación con alucarD ==="
	alucard check src/ include/

.PHONY: check-alucard
````

Ejecutá `make check-alucard` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-alucard-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`alucarD`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Typst 0.11 + PyYAML + PyMuPDF + OpenCV (OMR) + LanguageTool API`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-alucard-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`alucarD`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    DK[Deckard: Banco de Ejercicios] -->|Enunciados YAML| ALU[Alucard: Motor de Exámenes]
    MT[Moodle-Toolbox: Bancos GIFT] -->|Preguntas Teóricas| ALU
    DAE[Daedalus: Compilador C] -->|Verificación GCC| ALU
    ALU -->|PDFs Maquetados en Typst| IMP[Impresión / Campus Virtual]
    ALU -->|Grillas de Respuestas| OMR[Lectura Óptica OMR]
    ALU -->|Claves de Evaluación| DR[Dredd: Autograder Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `deckard (enunciados y starter codes)`
- `daedalus (código C verificado)`
- `moodle-toolbox (bancos GIFT/XML)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (pautas de corrección)`
- `Estudiantes / Imprenta (PDFs maquetados y hojas OMR)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `idkfa`, `deckard`, `moodle-toolbox` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `alucarD` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
deckard compose guia.yaml | alucard render parcial.yaml -o parcial.pdf
````

---

(manual-alucard-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `alucarD` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
