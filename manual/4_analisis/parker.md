---
title: "Manual de Referencia: parker"
subtitle: "Parker — Auditor de Estabilidad de ABIs, Visibilidad de Símbolos y Librerías Dinámicas"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-parker)=
# Parker — Auditor de Estabilidad de ABIs, Visibilidad de Símbolos y Librerías Dinámicas

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Auditoría de binarios y librerías compartidas (`.so` / `.dylib`) para validar que solo se exporten los símbolos públicos declarados en la API y mitigar contaminación del espacio de nombres global.
````

---

(manual-parker-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`parker`** forma parte del ecosistema oficial de software de la cátedra. Su diseño sigue principios pedagógicos rigurosos:

1. **Evidencia Técnica Directa**: Todo diagnóstico se fundamenta en la norma ISO C (C11/C23), en el modelo de memoria del sistema o en convenciones arquitectónicas formales.
2. **Acción Correctiva Concreta**: Cada advertencia incluye la prescripción técnica inmediata para resolver el defecto sin recurrir a conjeturas.
3. **Autonomía del Estudiante**: Facilita la autoevaluación local antes de la entrega final del trabajo práctico.
4. **Objetividad Docente**: Estandariza la corrección automática removiendo discrepancias subjetivas en la evaluación.

---

(manual-parker-instalacion)=
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

### 2.2 Métodos de Instalación de `parker`

Podés instalar `parker` mediante cualquiera de los siguientes métodos estándar:

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

La interfaz CLI de `parker` cuenta con autocompletado nativo para comandos, flags y archivos. Para configurarlo permanentemente en tu shell:

````{code-block} bash
# Configuración automática en Bash / Zsh / Fish
parker --install-completion

# Para cargar el autocompletado en la sesión actual de inmediato:
source ./install_tools.sh
````

---

### 2.4 Verificación del Entorno con `doctor`

Toda herramienta del ecosistema cuenta con el subcomando unificado `doctor`. Ejecutalo para auditar el estado del entorno:

````{code-block} bash
parker doctor
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

(manual-parker-comandos)=
## 3. Referencia Completa de Comandos CLI

A continuación se detallan los subcomandos principales disponibles en `parker`:

| Sintaxis del Comando | Descripción y Efecto |
| :--- | :--- |
| `parker audit-symbols ./lib/libtda.so include/tda.h` | Compara los símbolos exportados por la librería con los prototipos del header. |
| `parker check-abi --v1 lib_v1.so --v2 lib_v2.so` | Detecta incompatibilidades binarias (ABI breaks) entre versiones. |
| `parker hide-symbols src/ -o lib_clean.so` | Aplica `__attribute__((visibility("hidden")))` a funciones privadas. |
| `parker doctor` | Verifica herramientas de introspección binaria (`nm`, `readelf`, `objdump`). |

````{tip}
Podés agregar el flag `--json` a la mayoría de los comandos para exportar resultados en formato estructurado o `--md` para generar reportes Markdown para el informe de entrega.
````

---

(manual-parker-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Caso de Estudio

Considerá el siguiente fragmento de código representativo:

````{code-block} c
:linenos:
// Función privada interna que NO debe exportarse en la librería
__attribute__((visibility("hidden")))
void balancear_arbol_interno(void *nodo) {
    // detalle privado
}

// Función pública de la API
__attribute__((visibility("default")))
void arbol_insertar(void *arbol, int clave) {
    // llamada pública
}
````

### Ejecución de la Herramienta

Ejecutá el análisis desde tu terminal:

````{code-block} bash
parker audit-symbols ./lib/libtda.so include/tda.h
````

### Salida Obtenida en Consola

````{code-block} text
[!] PARKER ABI AUDITOR: 2 símbolos privados expuestos en libtda.so:
    • 'nodo_crear_interno' (Exportado globalmente en tabla de símbolos ELF).
    • 'buffer_temporal' (Variable global visible externamente).
Sugerencia: Marcá estas funciones como 'static' o agregá '__attribute__((visibility("hidden")))'. 
````

````{note}
Prestá atención a la explicación pedagógica generada: la herramienta no solo señala la línea del problema, sino que explica la causa raíz y el impacto en memoria o arquitectura.
````

---

(manual-parker-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

Practicá el uso avanzado de **`parker`** resolviendo los siguientes ejercicios:

````{exercise} Desafío 1: Auditoría de Símbolos Exportados
:label: parker-desafio-1
Comprobar que una librería compartida solo exporta su interfaz pública.

**Instrucción de ejecución:**
```bash
parker audit-symbols ./lib/liblista.so include/lista.h
```
````

````{solution} parker-desafio-1
```bash
parker audit-symbols ./lib/liblista.so include/lista.h
# Verificá que la operación concluya exitosamente con código de salida 0.
```
````

````{exercise} Desafío 2: Detección de Ruptura de ABI
:label: parker-desafio-2
Verificar si cambiar el orden de campos en un struct rompe compatibilidad binaria.

**Instrucción de ejecución:**
```bash
parker check-abi --v1 lib1.so --v2 lib2.so
```
````

````{solution} parker-desafio-2
```bash
parker check-abi --v1 lib1.so --v2 lib2.so
# Revisá el archivo generado o el informe en terminal para confirmar la resolución del problema.
```
````

````{exercise} Desafío 3: Ocultamiento Automático de Símbolos
:label: parker-desafio-3
Compilar con `-fvisibility=hidden` y exportar selectivamente.

**Instrucción de ejecución:**
```bash
parker hide-symbols src/ -o lib/libtda.so
```
````

````{solution} parker-desafio-3
```bash
parker hide-symbols src/ -o lib/libtda.so
# Comprobá que la salida confirme la ausencia de advertencias o errores pendientes.
```
````

---

(manual-parker-makefile)=
## 6. Integración en el Flujo de Trabajo y Makefile

Para incorporar `parker` de forma automática a tu flujo de desarrollo, agregá la siguiente regla en el `Makefile` de tu proyecto:

````{code-block} makefile
check-parker:
	@echo "=== Ejecutando verificación con parker ==="
	parker check src/ include/

.PHONY: check-parker
````

Ejecutá `make check-parker` antes de cada commit para mantener que tu código conserve el estado de aprobación.

---

(manual-parker-arquitectura)=
## 7. Arquitectura Interna y Mecanismo Técnico

La herramienta **`parker`** implementa un motor de alta precisión basado en:

- **Tecnología Núcleo:** `ELF Symbol Table Reader (readelf/nm) + DWARF ABI Comparator + Visibility Attribute Injector`.
- **Aislamiento y Determinismo:** Diseñada para operar sin efectos colaterales en entornos de integración continua (CI), terminales de estudiantes y servidores docentes headless.
- **Manejo de Errores Pedagógico:** Todo fallo de sintaxis, memoria o lógica se traduce en una acción prescriptiva concreta con su respectiva justificación técnica.

---

(manual-parker-ecosistema)=
## 8. Integración y Conexión con el Ecosistema

````{note}
Ninguna herramienta opera de forma aislada. **`parker`** forma parte del pipeline integral de evaluación, verificación y enseñanza de la cátedra.
````

### Diagrama de Flujo e Interoperabilidad

````{mermaid}
graph TD
    SO[libtda.so: Librería Compartida] --> PRK[Parker: Auditor de ABI]
    HDR[include/tda.h: API Pública] --> PRK
    PRK -->|Inspección Tabla ELF| NM[readelf / nm Engine]
    PRK -->|Ocultamiento de Símbolos| MOT[Motoko: Modularidad Estricta]
    PRK -->|Reporte de Estabilidad ABI| DRD[Dredd: Orquestador Masivo]
````

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | - `Librerías compartidas (.so) y headers de exportación` | Código fuente, AST, binarios, testcases, contratos |
| **Salidas (Outputs)** | - `motoko (encapsulamiento binario)`
- `dredd (auditoría de entregas librerías)` | Informes Markdown, diagnósticos Rich, JSON, actas |
| **Sincronización** | `motoko`, `corbel`, `dredd` | Validación cruzada, flags compartidos y autofix |

### Pipeline de Integración Recomendado

Podés encadenar `parker` con otras herramientas del ecosistema en una única línea de comando:

````{code-block} bash
# Pipeline de integración típico
parker audit-symbols ./lib/libtda.so include/tda.h
````

---

(manual-parker-seccion-plugins)=
## 9. Extensión, Desarrollo de Plugins y API Python

Para crear tus propias reglas, conectores de evaluación o integrar `parker` programáticamente en pipelines de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de Plugins](plugins.md)
