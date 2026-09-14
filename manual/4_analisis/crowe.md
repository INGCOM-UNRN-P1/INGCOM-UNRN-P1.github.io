---
title: "Manual de Referencia: crowe"
subtitle: "Crowe — Linter de Portabilidad Multi-Arquitectura, Endianness y Tipos de Ancho Fijo"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-crowe)=
# Crowe — Linter de Portabilidad Multi-Arquitectura, Endianness y Tipos de Ancho Fijo

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Detección de asunciones no portables en C: tamaño de punteros, orden de bytes (Little vs Big Endian), alineación y uso de tipos primitivos no estándar.
````

---

(manual-crowe-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`crowe`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-crowe-instalacion)=
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

### 2.2 Métodos de Instalación de `crowe`

Podés instalar `crowe` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `crowe` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
crowe --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
crowe doctor
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

(manual-crowe-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `crowe`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `crowe audit src/` | Audita el código fuente buscando incompatibilidades entre x86_64, ARM64 y 32-bit. |
| `crowe endianness src/serializador.c` | Detecta casteo directo de punteros o desplazamientos dependientes de Little Endian. |
| `crowe fix-types src/` | Sustituye tipos dependientes de plataforma por <stdint.h> (int32_t, uint64_t, size_t). |
| `crowe doctor` | Verifica toolchains cruzadas disponibles (GCC multiarch, QEMU user). |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-crowe-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>
#include <stdint.h>

// Código no portable: asume que sizeof(long) == sizeof(void*) y Little Endian
void serializar_mal(unsigned long valor, char *buf) {
    *(unsigned long*)buf = valor; // Peligro de alineación y endianness
}

// Código portable auditado por Crowe
void serializar_bien(uint32_t valor, uint8_t *buf) {
    buf[0] = (uint8_t)(valor >> 24);
    buf[1] = (uint8_t)(valor >> 16);
    buf[2] = (uint8_t)(valor >> 8);
    buf[3] = (uint8_t)(valor);
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
crowe audit src/
````

### Salida Obtenida en Consola

````{code-block} text
[!] src/serializador.c:5:5: ALERTA DE PORTABILIDAD [CROWE-001]
    Casteo de puntero a tipo 'unsigned long*' asume tamaño de 8 bytes (falla en arquitecturas de 32 bits y Windows x64 donde sizeof(long)==4).
    Sugerencia: Utilizá uint32_t o uint64_t de <stdint.h> con serialización explícita byte a byte.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-crowe-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`crowe`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Auditoría de Serializador Binario
:label: crowe-desafio-1
Detectar problemas de orden de bytes en `src/protocolo.c`.

**Instrucción de ejecución:**
```bash
crowe endianness src/protocolo.c
```
````

````{solution} crowe-desafio-1
```bash
crowe endianness src/protocolo.c
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Migración a Tipos de Ancho Fijo
:label: crowe-desafio-2
Reemplazar `unsigned int` y `long` por `uint32_t` y `int64_t`.

**Instrucción de ejecución:**
```bash
crowe fix-types src/ -i
```
````

````{solution} crowe-desafio-2
```bash
crowe fix-types src/ -i
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Simulación en Arquitectura Big Endian
:label: crowe-desafio-3
Verificar el comportamiento bajo emulación MIPS/PowerPC con QEMU.

**Instrucción de ejecución:**
```bash
crowe audit src/ --target mips
```
````

````{solution} crowe-desafio-3
```bash
crowe audit src/ --target mips
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-crowe-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `crowe` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-crowe:
	@echo "=== Ejecutando verificación con crowe ==="
	crowe check src/ include/

.PHONY: check-crowe
````

Ejecutá `make check-crowe` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-crowe-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`crowe`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `GCC Cross-Toolchains + QEMU User Emulation + Clang Target AST Matcher`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-crowe-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`crowe`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SRC[Código C] --> CRW[Crowe: Linter Multi-Arquitectura]
    CRW -->|Chequeo Endianness/Tipos| ABI[Modelos x86_64, ARM, 32-bit]
    CRW -->|Tipos Seguros stdint.h| DAE[Daedalus: Compilador Defensivo]
    CRW -->|Binario Portable| NOS[Nostromo: Sandbox Linux]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código fuente C (.c y .h)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `daedalus (compilación cruzada)`
- `nostromo (ejecución multiarch)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `brett`, `kane`, `ferro` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `crowe` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
crowe audit src/ && daedalus compile src/*.c -o bin/app
````

---

(manual-crowe-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `crowe` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
