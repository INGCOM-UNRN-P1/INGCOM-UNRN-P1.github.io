---
title: "Manual de Referencia: moodle-toolbox"
subtitle: "Moodle-Toolbox — Suite de Mantenimiento, Normalización y Conversión de Bancos GIFT/XML"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-moodle_toolbox)=
# Moodle-Toolbox — Suite de Mantenimiento, Normalización y Conversión de Bancos GIFT/XML

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Herramienta integral para validación, conversión bidireccional GIFT <-> Moodle XML, reorganización de árboles de categorías y corrección ortográfica de bancos.
````

---

(manual-moodle_toolbox-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`moodle-toolbox`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-moodle_toolbox-instalacion)=
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

### 2.2 Métodos de Instalación de `moodle-toolbox`

Podés instalar `moodle-toolbox` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `questions` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
questions --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
questions doctor
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

(manual-moodle_toolbox-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `questions`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `questions convert banco.gift -o banco.xml` | Convierte preguntas de formato GIFT a Moodle XML. |
| `questions convert banco.xml -o banco.gift` | Convierte Moodle XML a texto plano GIFT. |
| `questions validate banco.xml` | Valida la integridad estructural, pesos de respuestas e imágenes embebidas. |
| `questions spellcheck banco.gift` | Audita ortografía en enunciados y retroalimentaciones con LanguageTool. |
| `questions format banco.gift` | Normaliza indentación y formato limpio en archivos GIFT. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-moodle_toolbox-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Categoría y pregunta GIFT normalizada por moodle-toolbox
$CATEGORY: $course$/Parcial 1/Punteros

::Pregunta 01 - Aritmética de Punteros::
Dado el siguiente código en C:
<pre><code>int v[3] = {1, 2, 3}; int *p = v + 1;</code></pre>
¿Cuál es el valor de <code>*p</code>? {
    =2 #¡Correcto! p apunta al segundo elemento (índice 1).
    ~1 #Incorrecto: v[0] es 1, pero p fue incrementado en 1.
    ~3 #Incorrecto: v[2] es 3.
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
questions convert banco.gift -o banco.xml
````

### Salida Obtenida en Consola

````{code-block} text
[✓] 50 preguntas convertidas de GIFT a Moodle XML: banco.xml
[✓] 0 errores de validación en pesos porcentuales (suma 100% en opciones correctas).
[✓] Corrección ortográfica: 0 faltas detectadas en enunciados.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-moodle_toolbox-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`moodle-toolbox`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Conversión Bidireccional de Banco
:label: moodle_toolbox-desafio-1
Convertir preguntas de GIFT a XML para importar en el aula virtual.

**Instrucción de ejecución:**
```bash
questions convert preguntas.gift -o preguntas.xml
```
````

````{solution} moodle_toolbox-desafio-1
```bash
questions convert preguntas.gift -o preguntas.xml
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Validación de Categorías y Pesos
:label: moodle_toolbox-desafio-2
Verificar que ninguna pregunta tenga respuestas que no sumen 100%.

**Instrucción de ejecución:**
```bash
questions validate preguntas.xml
```
````

````{solution} moodle_toolbox-desafio-2
```bash
questions validate preguntas.xml
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Spellcheck con LanguageTool
:label: moodle_toolbox-desafio-3
Auditar ortografía en los textos de retroalimentación pedagógica.

**Instrucción de ejecución:**
```bash
questions spellcheck preguntas.gift --lang es-AR
```
````

````{solution} moodle_toolbox-desafio-3
```bash
questions spellcheck preguntas.gift --lang es-AR
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-moodle_toolbox-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `moodle-toolbox` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-moodle_toolbox:
	@echo "=== Ejecutando verificación con moodle-toolbox ==="
	questions check src/ include/

.PHONY: check-moodle_toolbox
````

Ejecutá `make check-moodle_toolbox` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-moodle_toolbox-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`moodle-toolbox`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Moodle XML Parser / Serializer + GIFT Grammar Lexer + LanguageTool REST Client`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-moodle_toolbox-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`moodle-toolbox`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    GIFT[Archivos GIFT / Texto] --> MT[Moodle-Toolbox: Gestor de Bancos]
    XML[Archivos Moodle XML] --> MT
    MT -->|Corrección Ortográfica| LT[LanguageTool API]
    MT -->|Conversión Bidireccional| ALU[Alucard: Generador Exámenes]
    MT -->|Bancos Validados| CAMPUS[Campus Virtual Moodle]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Bancos GIFT y XML de Alucard, Idkfa y docentes` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `Campus Virtual Moodle (bancos limpios)`
- `alucarD (preguntas normalizadas)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `alucarD`, `idkfa`, `myst-tools` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `moodle-toolbox` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
questions convert banco.gift -o banco.xml && questions spellcheck banco.xml --premium
````

---

(manual-moodle_toolbox-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `moodle-toolbox` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
