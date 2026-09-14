---
title: "Manual de Referencia: kane"
subtitle: "Kane — Simulador y Depurador Visual de I/O de Bajo Nivel y Perfiles Seccomp"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-kane)=
# Kane — Simulador y Depurador Visual de I/O de Bajo Nivel y Perfiles Seccomp

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Inspección de descriptores de archivo, mapeo binario de estructuras en disco, auditoría de syscalls de E/S (`read`, `write`, `lseek`) y filtrado con Seccomp.
````

---

(manual-kane-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`kane`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-kane-instalacion)=
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

### 2.2 Métodos de Instalación de `kane`

Podés instalar `kane` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `kane` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
kane --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
kane doctor
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

(manual-kane-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `kane`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `kane trace -- ./bin/programa` | Monitorea en tiempo real todas las operaciones de archivos y descriptores. |
| `kane dump-struct <archivo.bin> --format <struct_header.h>` | Mapea un archivo binario a campos de la struct C. |
| `kane audit-fds -- ./bin/servidor` | Detecta descriptores de archivo abiertos que no fueron cerrados con close/fclose. |
| `kane doctor` | Verifica el soporte de ptrace y seccomp en el kernel Linux. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-kane-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Registro {
    int legajo;
    float nota;
};

void guardar(const char *path) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    struct Registro r = {12345, 9.5f};
    write(fd, &r, sizeof(r));
    // Falta close(fd) -> Kane alertará fuga de FD
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
kane trace -- ./bin/programa
````

### Salida Obtenida en Consola

````{code-block} text
[!] KANE FD AUDITOR: Descriptor de archivo no liberado:
    • FD #3 abierto en main.c:10 (open('datos.bin')) nunca fue cerrado antes del fin del proceso.

[✓] Mapeo de Struct en datos.bin (8 bytes):
    ├─ legajo: 12345 (0x00003039)
    └─ nota: 9.500000 (0x41180000)
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-kane-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`kane`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Detección de Fugas de Descriptores (FD Leaks)
:label: kane-desafio-1
Encontrar archivos abiertos con `fopen` que no tienen `fclose`.

**Instrucción de ejecución:**
```bash
kane audit-fds -- ./bin/app_archivos
```
````

````{solution} kane-desafio-1
```bash
kane audit-fds -- ./bin/app_archivos
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Inspección Hexadecimal de Archivo Binario
:label: kane-desafio-2
Mapear un archivo `.dat` con la definición de `struct Alumno`.

**Instrucción de ejecución:**
```bash
kane dump-struct alumnos.dat --format include/alumno.h
```
````

````{solution} kane-desafio-2
```bash
kane dump-struct alumnos.dat --format include/alumno.h
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auditoría de Llamadas al Sistema de E/S
:label: kane-desafio-3
Monitorear offsets y bytes transferidos en operaciones `lseek`.

**Instrucción de ejecución:**
```bash
kane trace -- ./bin/lector_indices
```
````

````{solution} kane-desafio-3
```bash
kane trace -- ./bin/lector_indices
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-kane-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `kane` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-kane:
	@echo "=== Ejecutando verificación con kane ==="
	kane check src/ include/

.PHONY: check-kane
````

Ejecutá `make check-kane` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-kane-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`kane`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Linux ptrace Syscall Interceptor + Struct Memory Binary Unpacker + Seccomp BPF Filter`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-kane-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`kane`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    DAT[Archivos Binarios .dat/.bin] --> KAN[Kane: Depurador de E/S]
    HDR[Headers C: Structs] --> KAN
    KAN -->|Auditoría de Descriptores| PTRACE[Linux ptrace Engine]
    KAN -->|Layout en Disco| BRT[Brett: Auditor de Structs]
    KAN -->|Perfiles Seccomp BPF| NOS[Nostromo: Sandbox Seguro]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Binarios C y archivos de datos en disco (.bin, .dat)` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `brett (verificación de layout en disco)`
- `nostromo (perfiles seccomp)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `brett`, `nostromo`, `crowe` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `kane` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
kane dump-struct alumnos.dat --format include/alumno.h
````

---

(manual-kane-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `kane` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
