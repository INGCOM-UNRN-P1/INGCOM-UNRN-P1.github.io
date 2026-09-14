---
title: "Manual de Referencia: deckard"
subtitle: "Deckard — Gestor de Bancos de Ejercicios, Guías de Trabajos Prácticos y Taxonomía Bloom"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-deckard)=
# Deckard — Gestor de Bancos de Ejercicios, Guías de Trabajos Prácticos y Taxonomía Bloom

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Curaduría pedagógica de ejercicios, composición de guías según carga horaria y niveles Bloom, exportación a Typst/Jupyter, starter ZIPs y control LanguageTool.
````

---

(manual-deckard-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`deckard`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-deckard-instalacion)=
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

### 2.2 Métodos de Instalación de `deckard`

Podés instalar `deckard` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `deckard` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
deckard --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
deckard doctor
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

(manual-deckard-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `deckard`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `deckard compose <guia.yaml> -o guia.typ` | Compone la guía maquetada con ejercicios seleccionados. |
| `deckard pack-zip <ejercicio_o_guia> -o starter.zip` | Genera el starter kit ZIP con Makefile y clave de entrega. |
| `deckard check-ambiguity [ejercicio]` | Audita la claridad de consignas y ausencia de ambigüedades. |
| `deckard check-load <guia.yaml>` | Calcula la carga horaria acumulada y balance Bloom. |
| `deckard export-hints <ejercicio> --rot13` | Genera pistas escalonadas con ofuscación anti-spoilers. |
| `deckard spellcheck <guia.yaml>` | Audita ortografía y gramática con LanguageTool. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-deckard-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Ejercicio gestionado en banco/punteros/01_invertir/
/*
 * ID: ptr_invertir_vector
 * Bloom: APLICAR | Tiempo: 30 min
 */
void invertir_vector(int *v, size_t n);
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
deckard compose <guia.yaml> -o guia.typ
````

### Salida Obtenida en Consola

````{code-block} text
[✓] Guía compuesta: TP2_Punteros_y_Memoria.typ (Typst 0.11)
[✓] Total de ejercicios: 6 | Carga horaria acumulada: 3.5 horas (Balance: 2 Recordar, 3 Aplicar, 1 Analizar)
[✓] Starter ZIP generado: starter_tp2.zip (Clave de entrega: DKD-A1B2-C3D4)
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-deckard-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`deckard`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Composición de Guía Equilibrada
:label: deckard-desafio-1
Crear una guía semanal con cota de 4 horas y balance Bloom.

**Instrucción de ejecución:**
```bash
deckard compose guias/tp1.yaml -o tp1.typ
```
````

````{solution} deckard-desafio-1
```bash
deckard compose guias/tp1.yaml -o tp1.typ
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Empaquetado de Starter Kit con Clave
:label: deckard-desafio-2
Generar el archivo ZIP descargable para los estudiantes.

**Instrucción de ejecución:**
```bash
deckard pack-zip guias/tp1.yaml -o entregas/starter_tp1.zip
```
````

````{solution} deckard-desafio-2
```bash
deckard pack-zip guias/tp1.yaml -o entregas/starter_tp1.zip
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auditoría de Enunciados Docentes
:label: deckard-desafio-3
Verificar que los ejercicios no contengan términos vagos ni falta de casos borde.

**Instrucción de ejecución:**
```bash
deckard check-ambiguity --banco ./banco
```
````

````{solution} deckard-desafio-3
```bash
deckard check-ambiguity --banco ./banco
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-deckard-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `deckard` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-deckard:
	@echo "=== Ejecutando verificación con deckard ==="
	deckard check src/ include/

.PHONY: check-deckard
````

Ejecutá `make check-deckard` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-deckard-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`deckard`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Typst Compiler + PyYAML + Bloom Taxonomy Analyzer + ROT13 Hints Obfuscator + Zipfile Engine`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-deckard-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`deckard`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    BNC[Banco de Ejercicios YAML] --> DKD[Deckard: Gestor de Guías]
    DKD -->|Starter Kits + Clave SHA-256| ZIP[Estudiantes: starter_tpX.zip]
    DKD -->|Guías Maquetadas Typst| PDF[Campus Virtual: Guías PDF]
    DKD -->|Pautas y Criterios| DRD[Dredd: Autograding Masivo]
    DKD -->|Preguntas de Código| ALU[Alucard: Generador de Parciales]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Bancos de ejercicios YAML y resolvé canónicas` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `dredd (consignas de evaluación)`
- `alucarD (exámenes)`
- `Estudiantes (starter ZIPs)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `dredd`, `alucarD`, `idkfa`, `myst-tools` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `deckard` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
deckard compose guias/tp1.yaml -o tp1.typ && deckard pack-zip guias/tp1.yaml -o starter_tp1.zip
````

---

(manual-deckard-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `deckard` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
