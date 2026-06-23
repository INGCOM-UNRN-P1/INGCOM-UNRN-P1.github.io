# Manual de Compilación con LLVM / Clang

Este manual describe el funcionamiento de la infraestructura del compilador LLVM y el frontend Clang integrados en el subsistema portable CLANG64. El objetivo es comprender cómo se transforma tu código fuente en lenguaje C/C++ en un ejecutable binario de alto rendimiento optimizado para sistemas Windows usando UCRT.

---

## 1. Arquitectura de LLVM / Clang

LLVM utiliza una arquitectura modular de tres fases (Frontend, Optimizador y Backend) que se diferencia de los compiladores tradicionales monolíticos. A continuación podés observar el flujo de compilación detallado:

```{image} images/arquitectura_llvm.svg
:alt: Flujo de Compilación en LLVM / Clang
:align: center
:width: 100%
```

### Descripción de las Fases

1.  **Frontend (Clang):** Procesa tu código fuente (.c/.cpp). Realiza el análisis léxico (descomposición en tokens), el análisis sintáctico (construcción del AST - Árbol de Sintaxis Abstracta) y la validación semántica (chequeo de tipos y reglas del lenguaje). Finalmente, genera la **Representación Intermedia de LLVM (LLVM IR)**.
2.  **Representación Intermedia (LLVM IR):** Es un lenguaje de ensamblador universal, independiente de la arquitectura de destino. Permite que el optimizador trabaje sobre un estándar unificado.
3.  **Optimizador (opt):** Aplica transformaciones sobre el LLVM IR para mejorar el rendimiento y reducir el tamaño del ejecutable (ej: eliminación de código muerto, desenrollado de bucles, inlining de funciones). Es totalmente independiente del procesador del host.
4.  **Backend (Codegen / llc):** Toma el LLVM IR optimizado y lo traduce al lenguaje ensamblador específico de tu procesador (ej: x86-64).
5.  **Enlazador (lld):** Une los archivos de código objeto generados con las bibliotecas del sistema (como la UCRT de Windows) para producir el archivo binario ejecutable final (.exe).

---

## 2. Compilación Básica en la Terminal

Una vez que iniciás tu terminal con `launch.bat`, tenés disponible la suite completa de LLVM en tu PATH de sesión.

### Compilar un Programa Simple
Para compilar un archivo fuente único llamado `main.c`, ejecutá:
```bash
clang main.c -o main.exe
```

### Diagnósticos Clang (Mensajes de Error Claros)
Clang es conocido por proveer mensajes de diagnóstico sumamente legibles y detallados sobre errores y advertencias de sintaxis, marcándote la línea exacta y sugiriendo correcciones:
```bash
clang -Wall -Wextra main.c -o main.exe
```
*   **`-Wall`**: Habilita todas las advertencias comunes del compilador.
*   **`-Wextra`**: Habilita advertencias adicionales para prevenir comportamientos indefinidos.

---

## 3. Niveles de Optimización del Código

El optimizador de LLVM te permite controlar el balance entre el tiempo de compilación, el rendimiento del ejecutable y el tamaño del binario final:

| Bandera | Propósito | Descripción |
| :--- | :--- | :--- |
| **`-O0`** | Sin Optimización | Valor por defecto. Mapeo directo del código a ensamblador. Ideal para depurar con GDB. |
| **`-O1`** | Optimización Básica | Reduce tamaño y tiempo de ejecución sin incrementar drásticamente el tiempo de compilación. |
| **`-O2`** | Optimización Estándar | Recomendado para producción. Aplica la mayoría de las optimizaciones de velocidad del compilador. |
| **`-O3`** | Optimización Agresiva | Habilita optimizaciones que incrementan el tamaño del binario (ej. vectorización agresiva y desenrollado de bucles) para maximizar la velocidad. |
| **`-Os`** | Optimización de Tamaño | Optimiza la velocidad pero manteniendo a raya el crecimiento físico del ejecutable. |

Ejemplo para compilar en producción con optimización estándar:
```bash
clang -O2 -Wall -Wextra main.c -o main.exe
```

---

## 4. Compilación Multiarchivo y Enlazado

Cuando tu proyecto crece y se divide en múltiples módulos, debés compilar cada archivo fuente a código objeto (.o) y enlazarlos en un paso posterior.

### Compilación por Módulos
```bash
# 1. Compilar cada archivo fuente a objeto
clang -c main.c -o main.o
clang -c math_utils.c -o math_utils.o

# 2. Enlazar los objetos en el ejecutable final
clang main.o math_utils.o -o programa.exe
```

### Proyectos Complejos (CMake y Ninja)
Para no tener que escribir comandos manuales en la consola, el entorno portable incluye **CMake** y **Ninja**. Podés definir un archivo `CMakeLists.txt` básico:
```cmake
cmake_minimum_required(VERSION 3.20)
project(MiProyecto C)

set(CMAKE_C_STANDARD 11)

add_executable(programa main.c math_utils.c)
```

Y luego compilar desde tu consola ejecutando:
```bash
cmake -G Ninja -B build
cmake --build build
```
Ninja utilizará el compilador Clang en paralelo para realizar compilaciones incrementales ultrarrápidas.
