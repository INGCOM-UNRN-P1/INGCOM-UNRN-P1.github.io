---
title: "Guía completa de GCC"
short_title: "Manual GCC"
subtitle: "Instalación, configuración y uso del compilador GNU"
---

## Introducción a GCC

GCC (GNU Compiler Collection, originalmente GNU C Compiler) es el compilador de
código abierto más importante y ampliamente usado en el mundo. Desarrollado como
parte del Proyecto GNU de la Free Software Foundation, GCC es el compilador
estándar de facto en sistemas Unix y Linux.

### ¿Por qué usar GCC?

- **Estabilidad y madurez**: Con más de 35 años de desarrollo continuo, GCC es
  extremadamente robusto y confiable
- **Optimización de código**: Genera código altamente optimizado, frecuentemente
  superando otros compiladores en benchmarks
- **Soporte multiplataforma**: Funciona en prácticamente cualquier arquitectura
  (x86, ARM, PowerPC, MIPS, RISC-V, etc.)
- **Estándares completos**: Implementación completa y rigurosa de los estándares
  C (C89, C99, C11, C17, C23)
- **Ecosistema GNU**: Integración perfecta con herramientas GNU (GDB, Make,
  Binutils, etc.)
- **Código abierto**: Software libre bajo licencia GPL, garantizando libertad y
  transparencia
- **Documentación exhaustiva**: Décadas de documentación, tutoriales y recursos
  comunitarios

:::{note}

**Historia**

GCC fue creado en 1987 por Richard Stallman como parte del Proyecto GNU, con el
objetivo de crear un sistema operativo completamente libre. El primer release de
GCC solo compilaba C, pero rápidamente se expandió para soportar C++,
Objective-C, Fortran, Ada y otros lenguajes. Hoy en día, GCC es el compilador
por defecto en Linux y BSD, compilando la mayoría del software de código abierto
del mundo, incluyendo el kernel de Linux.

:::
<!-- {note} -->

### ¿Cuándo usar GCC?

GCC es la elección ideal cuando:

- **Buscás máxima portabilidad**: GCC corre en casi cualquier plataforma
  imaginable
- **Necesitás las mejores optimizaciones**: En benchmarks, GCC frecuentemente
  genera el código más rápido
- **Trabajás con hardware específico**: GCC soporta arquitecturas que otros
  compiladores no
- **Usás Linux/BSD**: GCC es el compilador nativo del ecosistema
- **Querés estabilidad probada**: Décadas de uso en producción garantizan
  confiabilidad
- **Desarrollás software embebido**: GCC es el estándar en sistemas embebidos

:::{tip}

Para estudiantes que están aprendiendo C, GCC es una excelente elección porque:

1. **Está en todas partes**: Lo encontrarás en cualquier sistema Unix/Linux
2. **Es el estándar de la industria**: La mayoría del software de código abierto
   se compila con GCC
3. **Enseña disciplina**: Sus mensajes de error, aunque técnicos, te obligan a
   entender qué está mal
4. **Tiene décadas de tutoriales**: Hay soluciones a cualquier problema que
   encuentres

:::
<!-- {tip} -->

## GCC: Instalación y Compilación

GNU Compiler Collection ([GCC](https://gcc.gnu.org/)) es una colección de
compiladores que incluye soporte para C, C++, Objective-C, Fortran, Ada, Go y D,
entre otros lenguajes.

## Instalación del Compilador

Para utilizar GCC, debés instalar el compilador y configurar las variables de
entorno de tu sistema operativo.

*   **Windows**: Seguí el paso a paso de la [Guía de Instalación del
    Compilador](compilador.md) para configurar MinGW-w64 y la variable `PATH`.
*   **Visual Studio Code**: Consultá la [Guía de VSCode](vscode.md) para
    configurar tu editor de código.

## Instalación en Linux e independientes

### Opciones fundamentales de compilación

GCC ofrece numerosas opciones para controlar el proceso de compilación. Aquí
están las más importantes:

#### Warnings (advertencias)

Los warnings son mensajes que indican problemas potenciales sin detener la
compilación.

```{code-block} bash
:linenos:
# Warnings básicos (SIEMPRE usar)
gcc -Wall -Wextra ejercicio.c -o ejercicio

# Explicación de cada flag:
# -Wall: Habilita warnings comunes (pero no todos)
# -Wextra: Warnings adicionales no cubiertos por -Wall

# Warnings aún más estrictos (recomendado)
gcc -Wall -Wextra -Wpedantic ejercicio.c -o ejercicio
# -Wpedantic: Advierte sobre violaciones del estándar ISO C

# Tratar warnings como errores (útil en CI/CD)
gcc -Wall -Wextra -Werror ejercicio.c -o ejercicio
# -Werror: Convierte todos los warnings en errores de compilación

```
<!-- {code-block} bash -->

**Warnings adicionales útiles:**

```{code-block} bash
:linenos:
# Conjunto completo de warnings recomendado
gcc -Wall -Wextra -Wpedantic \
    -Wformat=2 \           # Verificación estricta de printf/scanf
    -Wshadow \             # Variables que ocultan otras
    -Wconversion \         # Conversiones implícitas peligrosas
    -Wnull-dereference \   # Potenciales desreferencias de NULL
    -Wdouble-promotion \   # Promoción de float a double
    -Wundef \              # Uso de macros no definidas en #if
    ejercicio.c -o ejercicio

```
<!-- {code-block} bash -->

#### Niveles de optimización

GCC puede optimizar el código generado para hacerlo más rápido o más pequeño.

```{code-block} bash
:linenos:
# Sin optimización (por defecto, mejor para debugging)
gcc -O0 ejercicio.c -o ejercicio

# Optimización básica (balance entre velocidad y tiempo de compilación)
gcc -O1 ejercicio.c -o ejercicio

# Optimización estándar (recomendado para producción)
gcc -O2 ejercicio.c -o ejercicio

# Optimización agresiva (puede aumentar tamaño del ejecutable)
gcc -O3 ejercicio.c -o ejercicio

# Optimizar para tamaño (útil en sistemas embebidos)
gcc -Os ejercicio.c -o ejercicio

# Optimización guiada por perfil (PGO - Profile Guided Optimization)
# Paso 1: Compilar con instrumentación
gcc -fprofile-generate ejercicio.c -o ejercicio
# Paso 2: Ejecutar el programa (genera datos de perfil)
./ejercicio
# Paso 3: Recompilar usando el perfil
gcc -fprofile-use ejercicio.c -o ejercicio

```
<!-- {code-block} bash -->

:::{important}

**Optimización y Debugging**

Las optimizaciones (-O2, -O3) pueden dificultar el debugging porque:
- Reordenan código
- Eliminan variables "innecesarias"
- Hacen inlining de funciones pequeñas

Para debugging, usá siempre `-O0` (sin optimización) junto con `-g`.

:::
<!-- {important} -->

#### Información de debugging

```{code-block} bash
:linenos:
# Información completa de debugging para GDB
gcc -g ejercicio.c -o ejercicio

# Debugging + sin optimizaciones (ideal para desarrollo)
gcc -g -O0 ejercicio.c -o ejercicio

# Nivel de información de debug específico
gcc -g3 ejercicio.c -o ejercicio  # Máxima información (incluye macros)

# Generar información de debug en formato DWARF específico
gcc -gdwarf-4 ejercicio.c -o ejercicio

```
<!-- {code-block} bash -->

#### Estándares de C

GCC soporta múltiples versiones del estándar C:

```{code-block} bash
:linenos:
# C89/C90 (ANSI C - el más antiguo)
gcc -std=c89 ejercicio.c -o ejercicio
gcc -std=c90 ejercicio.c -o ejercicio  # Equivalente a c89

# C99 (agrega features como declaración de variables en for loops)
gcc -std=c99 ejercicio.c -o ejercicio

# C11 (agrega threads, atomic operations, etc.)
gcc -std=c11 ejercicio.c -o ejercicio

# C17/C18 (corrige defectos de C11, sin features nuevas)
gcc -std=c17 ejercicio.c -o ejercicio

# C23 (borrador del próximo estándar, soporte experimental)
gcc -std=c2x ejercicio.c -o ejercicio

# GNU extensions (extensiones de GCC sobre el estándar)
gcc -std=gnu11 ejercicio.c -o ejercicio  # C11 + extensiones GNU

```
<!-- {code-block} bash -->

:::{note}

**¿Qué estándar usar?**

Para este curso, **usá C11** (`-std=c11`):
- Es un estándar ampliamente adoptado
- Tiene todas las features que necesitarás
- Es soportado por todos los compiladores modernos
- Evita extensiones específicas de GCC (mejor portabilidad)

:::
<!-- {note} -->

### Compilación modular

Para proyectos con múltiples archivos fuente:

```{code-block} bash
:linenos:
# Estructura de ejemplo:
# main.c
# lista.c
# lista.h
# utils.c
# utils.h

# Opción 1: Compilar todo junto (simple, pero lento para proyectos grandes)
gcc -Wall -Wextra -std=c11 main.c lista.c utils.c -o programa

# Opción 2: Compilar por separado (más eficiente)
# Paso 1: Compilar cada .c a .o (archivo objeto)
gcc -Wall -Wextra -std=c11 -c main.c   # genera main.o
gcc -Wall -Wextra -std=c11 -c lista.c  # genera lista.o
gcc -Wall -Wextra -std=c11 -c utils.c  # genera utils.o

# Paso 2: Linkear todos los .o
gcc main.o lista.o utils.o -o programa

# Ventaja: Si modificás solo main.c, solo recompilás main.o
# Los otros .o no necesitan recompilarse

```
<!-- {code-block} bash -->

**Con directorios de include:**

```{code-block} bash
:linenos:
# Si los .h están en un directorio separado
# Estructura:
# src/main.c
# src/lista.c
# include/lista.h
# include/utils.h

gcc -Wall -Wextra -std=c11 -Iinclude -c src/main.c
gcc -Wall -Wextra -std=c11 -Iinclude -c src/lista.c

# -I especifica directorios adicionales donde buscar .h

```
<!-- {code-block} bash -->

**Linkeo con bibliotecas:**

```{code-block} bash
:linenos:
# Linkear biblioteca matemática (libm)
gcc programa.c -o programa -lm
# -l especifica biblioteca a linkear (m = libm.so o libm.a)

# Linkear múltiples bibliotecas
gcc programa.c -o programa -lm -lpthread

# Especificar directorios de bibliotecas
gcc programa.c -o programa -L/ruta/a/libs -lmilibreria
# -L especifica dónde buscar bibliotecas

```
<!-- {code-block} bash -->

### Análisis estático con GCC

GCC incluye opciones de análisis estático que detectan bugs sin ejecutar el
código:

```{code-block} bash
:linenos:
# Análisis estático básico
gcc -fanalyzer ejercicio.c -o ejercicio

# Esto detecta:
# - Potenciales desreferencias de NULL
# - Use-after-free
# - Doble free
# - Memory leaks
# - Buffer overflows

# Ejemplo de uso completo
gcc -std=c11 -Wall -Wextra -fanalyzer -O2 -g ejercicio.c -o ejercicio

```
<!-- {code-block} bash -->

:::{tip}

**Uso de -fanalyzer**

La opción `-fanalyzer` (disponible desde GCC 10) es muy útil pero puede:
- Incrementar significativamente el tiempo de compilación
- Generar falsos positivos ocasionalmente

Recomendación: Úsalo periódicamente durante desarrollo, no en cada compilación.

:::
<!-- {tip} -->

### Generación de código ensamblador

Para aprender cómo funciona el código a bajo nivel:

```{code-block} bash
:linenos:
# Generar archivo .s (ensamblador)
gcc -S ejercicio.c

# Generar con sintaxis AT&T (default)
gcc -S ejercicio.c -o ejercicio_att.s

# Generar con sintaxis Intel (más legible)
gcc -S -masm=intel ejercicio.c -o ejercicio_intel.s

# Ver código ensamblador con código C intercalado
gcc -Wa,-adhln -g ejercicio.c > ejercicio_mixed.s

```
<!-- {code-block} bash -->

### Preprocesamiento

Ver el resultado después de que el preprocesador expande macros e includes:

```{code-block} bash
:linenos:
# Solo preprocesar (genera archivo .i)
gcc -E ejercicio.c -o ejercicio.i

# Esto es útil para:
# - Debuggear problemas con #define
# - Ver qué incluye realmente un .h
# - Entender errores del preprocesador

```
<!-- {code-block} bash -->

## Compilar con GCC

Considerá las siguientes líneas de código en un archivo llamado `ejercicio1.c`:

```{code-block} C
:linenos:
#include <stdio.h>

/*
 *  1. Hola Mundo
 *  Desarrollar un programa que muestre por STDOUT el mensaje "Hola Mundo C!".
 *  Indicar en un comentario la instrucción de compilación con GCC
 *  por línea de comandos.
 */


int main()
{
    printf("Hola Mundo C!\n");
    return 0;
}

```
<!-- {code-block} C -->

Para compilar el código, ejecutá el siguiente comando:

``` sh
gcc ejercicio1.c
```
<!-- sh -->

Si la compilación es exitosa, se genera un archivo ejecutable nombrado por
defecto como `a.out`. Para especificar un nombre personalizado al ejecutable,
usá la opción `-o`. Por ejemplo, si querés que el ejecutable se llame
`ejercicio1`:

``` sh
gcc ejercicio1.c -o ejercicio1
```
<!-- sh -->

:::{important}

Se recomienda **fuertemente** utilizar las verificaciones adicionales del
compilador mediante las opciones `-Wall` y `-Wextra`:

``` sh
gcc ejercicio1.c -Wall -Wextra -o ejercicio1
```
<!-- sh -->

De esta manera, el compilador te avisará sobre situaciones que potencialmente
pueden ser problemáticas, aunque no sean estrictamente errores.

:::
<!-- {important} -->

Finalmente, para ejecutar el programa:

``` sh
./ejercicio1
```
<!-- sh -->

Salida esperada:
```
Hola Mundo C!
```

## Opciones avanzadas de GCC

### Arquitecturas y plataformas

GCC puede compilar para diferentes arquitecturas:

```{code-block} bash
:linenos:
# Ver arquitectura actual
gcc -dumpmachine

# Compilar para 32 bits en sistema 64 bits
gcc -m32 programa.c -o programa32

# Compilar para arquitectura específica
gcc -march=native programa.c -o programa  # Optimizar para CPU actual
gcc -march=x86-64 programa.c -o programa
gcc -march=armv7 programa.c -o programa

# Cross-compilation (compilar para otra plataforma)
# Requiere cross-compiler instalado
arm-linux-gnueabi-gcc programa.c -o programa-arm

```
<!-- {code-block} bash -->

### Seguridad y hardening

Opciones para hacer el código más seguro:

```{code-block} bash
:linenos:
# Stack protection (detecta buffer overflows en stack)
gcc -fstack-protector-strong programa.c -o programa

# Position Independent Executable (PIE) - dificulta exploits
gcc -fPIE -pie programa.c -o programa

# Fortify source (verificaciones adicionales en funciones de biblioteca)
gcc -D_FORTIFY_SOURCE=2 -O2 programa.c -o programa

# Conjunto completo de flags de seguridad
gcc -Wall -Wextra -Werror \
    -fstack-protector-strong \
    -fPIE -pie \
    -D_FORTIFY_SOURCE=2 \
    -O2 \
    programa.c -o programa

```
<!-- {code-block} bash -->

### Generación de dependencias

Útil para Makefiles automáticos:

```{code-block} bash
:linenos:
# Generar dependencias de un archivo
gcc -MM main.c
# Output: main.o: main.c lista.h utils.h

# Generar archivo de dependencias
gcc -MM main.c > main.d

# Uso en Makefile:
# include $(SRC:.c=.d)

```
<!-- {code-block} bash -->

## Estructura de Trabajo Recomendada

Esta no es una obligación, sino una guía de cómo organizar los archivos de
trabajo. El objetivo es facilitarte la gestión de los trabajos prácticos y demás
actividades de la cátedra.

### Ubicación en la Computadora

Es **muy recomendable** que la ruta de trabajo no contenga espacios, ya que esto
puede complicar el uso de las herramientas de compilación y debugging.

:::{warning}

Las rutas con espacios pueden generar errores difíciles de diagnosticar al
compilar o ejecutar programas.

:::
<!-- {warning} -->

#### Ejemplos de Rutas Apropiadas

**En Windows:**

```
C:\Facultad\Programacion1
C:\Dev\P1
C:\Users\tu_usuario\uni\p1
```

**En Linux/macOS:**

```
/home/usuario/facultad/programacion1
/home/usuario/dev/p1
~/Universidad/P1
```

#### Ejemplos de Rutas No Recomendadas

**Evitá estas estructuras:**

```
❌ C:\Mis Documentos\Programación 1\Trabajos Prácticos
❌ C:\Users\Usuario Con Espacios\Desktop\TP 1
❌ /home/usuario/Mis Archivos/Programación/TP 1
```

:::{tip}

Es preferible una ruta simple a una ruta complicada. La "profundidad" excesiva
(muchos niveles de carpetas anidadas) también puede traer problemas con algunas
herramientas.

:::
<!-- {tip} -->

### Estructura de Carpetas Sugerida

Una organización clara te ayudará a mantener el trabajo ordenado a lo largo del
cuatrimestre:

```
p1/
+-- guias/
|   +-- guia01/
|   |   +-- ejercicio01.c
|   |   +-- ejercicio02.c
|   |   +-- ejercicio03.c
|   +-- guia02/
|   |   +-- ejercicio01.c
|   |   +-- ejercicio02.c
|   +-- guia03/
|       +-- ejercicio01.c
+-- tps/
|   +-- tp1/
|   |   +-- main.c
|   |   +-- funciones.c
|   |   +-- funciones.h
|   |   +-- README.md
|   +-- tp2/
|       +-- main.c
+-- parciales/
|   +-- parcial1/
|   +-- parcial2/
+-- apuntes/
    +-- notas.md
```

:::{note}

Esta estructura te permite:
- Separar claramente cada guía de ejercicios
- Mantener los TPs en carpetas independientes
- Conservar material de parciales organizados
- Tener un espacio para apuntes personales
- Abrir la carpeta en VSCode en la raíz, permite tener a mano todos los
  ejercicios hechos.

:::
<!-- {note} -->

### Convenciones de Nombres

Para los archivos fuente en C, seguí estas convenciones:

**Para ejercicios individuales:**
```
ejercicio01.c
ejercicio02.c
ejercicio03.c
```

**Para archivos de cabecera:**
```
funciones.h
tipos.h
operaciones.h
```

**Para archivos de implementación:**
```
funciones.c
tipos.c
operaciones.c
```

:::{important}

- Usá nombres descriptivos en minúsculas
- Evitá caracteres especiales (tildes, ñ, símbolos)
- Preferí guiones bajos `_` en lugar de espacios
- Mantené consistencia en la nomenclatura

:::
<!-- {important} -->

### Archivos Ejecutables

Al compilar, los ejecutables generados no deberían mezclarse con el código
fuente. Podés seguir alguna de estas estrategias:

#### Opción 1: Usar un Prefijo
``` sh
gcc ejercicio01.c -Wall -Wextra -o bin_ejercicio01
```
<!-- sh -->

#### Opción 2: Carpeta de Binarios
```
guia01/
+-- src/
|   +-- ejercicio01.c
|   +-- ejercicio02.c
+-- bin/
    +-- ejercicio01
    +-- ejercicio02
```

Compilación con carpetas separadas:
``` sh
gcc src/ejercicio01.c -Wall -Wextra -o bin/ejercicio01
```
<!-- sh -->

:::{tip}

La separación de binarios del código fuente facilita la limpieza del proyecto y
evita subir ejecutables al control de versiones (como Git).

:::
<!-- {tip} -->

### Control de Versiones (Opcional pero Recomendado)

Si usás Git para versionar tu código, incluí un archivo `.gitignore` en la raíz
del proyecto:

```{code-block} gitignore
:linenos:
# Ejecutables
*.exe
*.out
a.out

# Archivos objeto
*.o
*.obj

# Carpeta de binarios
bin/
build/

# Archivos temporales
*.tmp
*.swp
*~

# Dependencias del sistema
.DS_Store
Thumbs.db

```
<!-- {code-block} gitignore -->

:::{note}

Esto evita que archivos innecesarios (como ejecutables o archivos temporales) se
suban al repositorio.

:::
<!-- {note} -->

### Ejemplo Práctico de Flujo de Trabajo

Supongamos que vas a trabajar en el ejercicio 5 de la guía 3:

1. **Navegá al directorio correspondiente:**
   ```sh
   cd programacion1/guias/guia03
   ```

2. **Creá el archivo fuente:**
   ```sh
   # En Windows (usando notepad o VSCode)
   code ejercicio05.c
   
   # En Linux (usando nano, vim o VSCode)
   nano ejercicio05.c
   ```

3. **Escribí tu código**

4. **Compilá con las opciones recomendadas:**
   ```sh
   gcc ejercicio05.c -Wall -Wextra -std=c11 -o ejercicio05
   ```

5. **Ejecutá el programa:**
   ```sh
   # En Windows
   ejercicio05.exe
   
   # En Linux/macOS
   ./ejercicio05
   ```

6. **Iterá:** Si hay errores, corregí y recompilá

:::{tip}

Mantener un terminal abierto en el directorio de trabajo acelera el ciclo
editar-compilar-ejecutar.

:::
<!-- {tip} -->

### Herramientas Complementarias

Además del compilador y un editor de texto, considerá estas herramientas:

| Herramienta | Propósito | Comando Básico |
|-------------|-----------|----------------|
| **GDB** | Debugger para C | `gdb ./programa` |
| **Valgrind** | Detección de errores de memoria | `valgrind ./programa` |
| **Make** | Automatización de compilación | `make` |
| **Git** | Control de versiones | `git status` |

:::{note}

Estas herramientas se introducirán gradualmente durante el curso. No es
necesario instalarlas todas al inicio.

:::
<!-- {note} -->

### Resumen de Buenas Prácticas

:::{list-table}
:header-rows: 1

* - Aspecto
  - Recomendación
  - Ejemplo
* - Rutas
  - Sin espacios, simples
  - `C:\Dev\P1`
* - Nombres de archivos
  - Descriptivos, sin tildes
  - `ejercicio01.c`
* - Compilación
  - Con warnings habilitados
  - `gcc -Wall -Wextra`
* - Organización
  - Por guías/temas
  - `guias/guia01/`
* - Binarios
  - Separados del código
  - `bin/` o prefijo `bin_`

:::
<!-- {list-table} -->

:::{important}

La organización es una habilidad fundamental en programación. Un proyecto bien
estructurado facilita el mantenimiento, la colaboración y la depuración del
código.

:::
<!-- {important} -->

## Flags recomendados para diferentes situaciones

### Para estudiantes (desarrollo y aprendizaje)

```{code-block} bash
:linenos:
# Comando básico recomendado
gcc -Wall -Wextra -Wpedantic -std=c11 -g -O0 ejercicio.c -o ejercicio

# Explicación:
# -Wall -Wextra -Wpedantic: Todos los warnings importantes
# -std=c11: Usar estándar C11
# -g: Información de debugging para GDB
# -O0: Sin optimizaciones (mejor para debugging)

```
<!-- {code-block} bash -->

**Crear alias útiles** (agregar a `~/.bashrc` en Linux o macOS):

``` bash
# Alias para compilación rápida
alias gcc11='gcc -Wall -Wextra -Wpedantic -std=c11 -g -O0'

# Uso:
gcc11 ejercicio.c -o ejercicio
```
<!-- bash -->

### Para testing y validación

```{code-block} bash
:linenos:
# Compilación estricta con análisis estático
gcc -Wall -Wextra -Wpedantic -Werror \
    -std=c11 -g -O0 \
    -fanalyzer \
    -fsanitize=address,undefined \
    ejercicio.c -o ejercicio

# Explicación adicional:
# -Werror: Warnings son errores (fuerza a corregirlos)
# -fanalyzer: Análisis estático
# -fsanitize=address,undefined: Detectores de bugs en runtime

```
<!-- {code-block} bash -->

### Para producción/release

```{code-block} bash
:linenos:
# Optimización y seguridad
gcc -Wall -Wextra -std=c11 \
    -O2 \
    -DNDEBUG \
    -fstack-protector-strong \
    -D_FORTIFY_SOURCE=2 \
    -fPIE -pie \
    programa.c -o programa

# Explicación:
# -O2: Optimización estándar
# -DNDEBUG: Desactiva assert()
# -fstack-protector-strong: Protección contra stack overflow
# -D_FORTIFY_SOURCE=2: Verificaciones extra de seguridad
# -fPIE -pie: Position Independent Executable

```
<!-- {code-block} bash -->

## Comparación de compiladores: GCC vs Clang

Si bien esta guía se enfoca en GCC, es útil conocer las diferencias con Clang:

### Cuándo preferir GCC:

- **Máxima portabilidad**: GCC corre en más plataformas
- **Mejor optimización**: En benchmarks, GCC frecuentemente genera código más
  rápido
- **Desarrollo en Linux**: GCC es el compilador nativo
- **Proyectos existentes**: La mayoría del código libre se compila con GCC
- **Hardware específico**: GCC soporta arquitecturas exóticas

### Cuándo considerar Clang:

- **Mensajes de error claros**: Clang explica mejor qué está mal
- **Velocidad de compilación**: Clang es más rápido compilando
- **Herramientas integradas**: clang-format, clang-tidy, clangd
- **Desarrollo en macOS**: Clang es el compilador nativo de Apple
- **Proyectos nuevos**: El ecosistema LLVM es moderno y activo

:::{tip}

**Lo ideal: conocer ambos**

Como estudiante de programación, es valioso aprender a usar tanto GCC como
Clang:
- La mayoría de proyectos de código abierto usan GCC
- Empresas tech modernas usan Clang
- Ambos son herramientas profesionales estándar de la industria

Todos los conceptos que aprendas con GCC se transfieren directamente a Clang y
viceversa.

:::
<!-- {tip} -->

## Troubleshooting: problemas comunes

### GCC no se encuentra después de instalar

```{code-block} bash
:linenos:
# Linux: verificar que esté en el PATH
which gcc
echo $PATH

# Si no está, agregarlo (ejemplo Ubuntu)
export PATH="/usr/bin:$PATH"

# Hacer permanente (agregar a ~/.bashrc)
echo 'export PATH="/usr/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

```
<!-- {code-block} bash -->

### Error: "undefined reference to..."

```{code-block} bash
:linenos:
# Olvidaste linkear una biblioteca
# ❌ gcc programa.c -o programa
# ✅ gcc programa.c -o programa -lm

# O falta un archivo .c
# ❌ gcc main.c -o programa  (falta lista.c)
# ✅ gcc main.c lista.c -o programa

```
<!-- {code-block} bash -->

### Warning: implicit declaration of function

```{code-block} bash
:linenos:
# Olvidaste incluir un .h
# Solución: agregar #include apropiado

# Ejemplo:
# ❌ int main() { printf("hola"); }
# ✅ #include <stdio.h>
#    int main() { printf("hola"); }

```
<!-- {code-block} bash -->

### Segmentation fault (core dumped)

```{code-block} bash
:linenos:
# Desreferenciar puntero NULL, buffer overflow, etc.
# Compilar con debugging y ejecutar en GDB

gcc -g -O0 programa.c -o programa
gdb ./programa
(gdb) run
# GDB mostrará exactamente dónde ocurrió el error

# O usar Valgrind
valgrind ./programa

```
<!-- {code-block} bash -->

### Permission denied al ejecutar

```{code-block} bash
:linenos:
# El archivo no tiene permisos de ejecución
chmod +x programa
./programa

# En Windows, asegurate que el nombre incluya .exe
gcc programa.c -o programa.exe
programa.exe

```
<!-- {code-block} bash -->

## Recursos adicionales

### Documentación oficial

- [GCC Online Documentation](https://gcc.gnu.org/onlinedocs/) - Documentación
  completa oficial
- [GCC Manual](https://gcc.gnu.org/onlinedocs/gcc/) - Manual del usuario
- [GCC Wiki](https://gcc.gnu.org/wiki) - Wiki de la comunidad GCC
- [GDB Documentation](https://sourceware.org/gdb/documentation/) - Manual de GDB

### Tutoriales y guías

- [GCC
  Tutorial](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html) -
  Tutorial completo de GCC y Make
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) - Guía excelente
  de C
- [The C Book](http://publications.gbdirect.co.uk/c_book/) - Libro online
  gratuito

### Herramientas complementarias

- [Compiler Explorer (Godbolt)](https://godbolt.org/) - Ver código ensamblador
  generado
- [OnlineGDB](https://www.onlinegdb.com/) - IDE online con GCC
- [Quick Bench](https://quick-bench.com/) - Benchmarking online

### Comunidad y soporte

- [Stack Overflow - C Tag](https://stackoverflow.com/questions/tagged/c) -
  Preguntas y respuestas
- [r/C_Programming](https://reddit.com/r/C_Programming) - Comunidad de Reddit
- [GCC Mailing Lists](https://gcc.gnu.org/lists.html) - Listas de correo
  oficiales

## Conclusión

GCC es una herramienta fundamental para cualquier programador de C:

- **Gratuito y de código abierto**: Sin restricciones ni costos
- **Maduro y confiable**: 35+ años de desarrollo y refinamiento
- **Estándar de la industria**: Usado en Linux, BSD, y millones de proyectos
- **Optimización excelente**: Genera código muy eficiente
- **Ecosistema completo**: GDB, Make, Valgrind, etc. trabajan perfectamente
  juntos

Para estudiantes, dominar GCC significa:
- Entender cómo se transforma código fuente a ejecutable
- Aprender a interpretar mensajes del compilador
- Usar herramientas profesionales desde el inicio
- Estar preparado para desarrollo en sistemas Unix/Linux

:::{tip}

**Recomendación final**

Empezá simple con:
``` bash
gcc -Wall -Wextra -std=c11 -g programa.c -o programa
```
<!-- bash -->

A medida que avances, incorporá:
- `-fanalyzer` para análisis estático
- Valgrind para detectar memory leaks
- GDB para debugging complejo
- Make para automatizar compilación

La maestría se logra con práctica constante. ¡Compilá, ejecutá, debuggeá,
repetí!

:::
<!-- {tip} -->

```{code-block} bash
:linenos:
$ gcc --version
gcc (Ubuntu 13.2.0-23ubuntu4) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.

$ echo "¡Listo para compilar con GCC!"
¡Listo para compilar con GCC!

```
<!-- {code-block} bash -->

---
