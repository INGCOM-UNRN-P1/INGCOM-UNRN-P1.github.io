---
title: "Manual de Referencia: motoko"
subtitle: "Motoko — Verificador de Encapsulamiento Estricto, Opacidad de Structs e Invariantes de TDA"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-motoko)=
# Motoko — Verificador de Encapsulamiento Estricto, Opacidad de Structs e Invariantes de TDA

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Auditoría de modularidad en C para proveer que los tipos de datos abstractos (TDAs) mantengan sus estructuras opacas (incomplete types en .h) y ningún código cliente acceda a miembros privados.
````

---

(manual-motoko-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`motoko`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-motoko-instalacion)=
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

### 2.2 Métodos de Instalación de `motoko`

Podés instalar `motoko` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `motoko` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
motoko --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
motoko doctor
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

(manual-motoko-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `motoko`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `motoko check include/ src/` | Verifica que los clientes no rompan la encapsulación de los TDAs. |
| `motoko opacify include/lista.h` | Convierte una struct pública en un tipo opaco forward-declared. |
| `motoko invariants src/tda_pila.c` | Audita que las funciones públicas preserven los invariantes del TDA. |
| `motoko doctor` | Comprueba el analizador AST de C. |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-motoko-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// include/lista.h (Encapsulado estricto con Motoko)
typedef struct lista t_lista; // Tipo opaco: cliente NO ve los campos

t_lista* lista_crear(void);
void lista_destruir(t_lista *lista);

// src/lista.c (Implementación privada)
struct lista {
    struct nodo *primero;
    size_t cantidad;
};
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
motoko check include/ src/
````

### Salida Obtenida en Consola

````{code-block} text
[!] MOTOKO ENCAPSULATION VIOLATION en src/main.c:15:10:
    Acceso prohibido al miembro privado 'lista->cantidad'.
    Los campos internos de 'struct lista' son opacos para el código cliente.
    Sugerencia: Utilizá la función pública 'size_t lista_cantidad(const t_lista *l);'.
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-motoko-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`motoko`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Detección de Violaciones de Encapsulamiento
:label: motoko-desafio-1
Verificar que `src/cliente.c` solo interactúe mediante la API pública del TDA.

**Instrucción de ejecución:**
```bash
motoko check include/ src/
```
````

````{solution} motoko-desafio-1
```bash
motoko check include/ src/
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Opacificación de Headers de Cátedra
:label: motoko-desafio-2
Ocultar la definición interna de nodos en `include/arbol.h`.

**Instrucción de ejecución:**
```bash
motoko opacify include/arbol.h
```
````

````{solution} motoko-desafio-2
```bash
motoko opacify include/arbol.h
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Auditoría de Invariantes de Estado
:label: motoko-desafio-3
mantener que `pila_desapilar()` actualice siempre el tope y el contador.

**Instrucción de ejecución:**
```bash
motoko invariants src/pila.c
```
````

````{solution} motoko-desafio-3
```bash
motoko invariants src/pila.c
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-motoko-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `motoko` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-motoko:
	@echo "=== Ejecutando verificación con motoko ==="
	motoko check src/ include/

.PHONY: check-motoko
````

Ejecutá `make check-motoko` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-motoko-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`motoko`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `Tree-Sitter C AST + Incomplete Types Visibility Checker + Invariant Contract Validator`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-motoko-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`motoko`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    HDR[include/*.h: Tipos Opacos] --> MOT[Motoko: Verificador de TDA]
    SRC[src/*.c: Código Cliente] --> MOT
    MOT -->|Detección de Violación de Acceso| RIP[Ripley: Reglas de Modularidad]
    MOT -->|Validación de Encapsulamiento| CRB[Corbel: Documentación de APIs]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Código cliente (.c) y headers públicos (.h) de TDAs` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `ripley (reglas 0x2000h de modularidad)`
- `corbel (verificación de opacidad)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `corbel`, `parker`, `ripley` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `motoko` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
motoko check include/ src/ && ripley check src/
````

---

(manual-motoko-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `motoko` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
