---
title: "Ejercicios: Compilación y Makefiles"
short_title: "8. Compilación"
---

# Ejercicios: Compilación y Makefiles

## Acerca de

Comprender el proceso de compilación y saber cómo automatizarlo es una habilidad
esencial para cualquier programador de C. Estos ejercicios te guiarán a través
de la creación de proyectos multi-archivo, el uso de `gcc` para compilar y
enlazar, y la escritura de `Makefiles` básicos para gestionar la compilación de
forma eficiente.

Para profundizar en los conceptos teóricos, podés consultar los siguientes
capítulos del apunte:
- [Compilación](../../apunte/bloque_2_proyectos/1_compilacion.md)
- [Makefiles](../../apunte/bloque_2_proyectos/2_makefiles.md)

## Proyecto Multi-archivo Manual
(ejercicio_6_1)=
### Ejercicio 6.1 - Separar un programa ⭐⭐☆☆☆

**Tarea**: Tomá un programa simple que tengas en un solo archivo `.c` (por
ejemplo, una calculadora con funciones `sumar` y `restar`) y dividilo en tres
archivos:

- **`calculadora.h`**: El archivo de cabecera. Debe contener solo los prototipos
  de las funciones `sumar` y `restar` y las guardas de inclusión.
- **`calculadora.c`**: La implementación. Debe incluir `calculadora.h` y
  contener el código de las funciones `sumar` y `restar`.
- **`main.c`**: El programa principal. Debe incluir `calculadora.h` y llamar a
  las funciones para usarlas.
(ejercicio_6_2)=

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Agregar una función adicional multiplicar en calculadora.c y declararla en calculadora.h.
-   **[*plus ultra*]:** Compilar el proyecto con -Wall y -Wextra para asegurar cero advertencias.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 6.2 - Compilación manual ⭐⭐☆☆☆

**Tarea**: Usando la terminal, compilá y enlazá los archivos del ejercicio
anterior sin usar un Makefile.

:::{hint} Pasos de Compilación
1.  **Compilar los archivos objeto (`.o`)**: Se usa la opción `-c` de `gcc` para
    compilar cada archivo fuente por separado.
    ```bash
    gcc -c main.c -o main.o
    gcc -c calculadora.c -o calculadora.o
    ```
2.  **Enlazar los objetos**: Se combinan los archivos objeto para crear el
    ejecutable final.
    ```bash
    gcc main.o calculadora.o -o mi_calculadora
    ```
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Crear un script de bash build.sh que ejecute los pasos de compilación y enlace de forma secuencial.
-   **[*plus ultra*]:** Probar qué ocurre si se modifica solo uno de los archivos .c y se recompila solo su .o.

:::
<!-- {hint} Pasos de Compilación -->

## Automatización con Makefile
(ejercicio_6_3)=
### Ejercicio 6.3 - Makefile básico ⭐☆☆☆☆

**Tarea**: Crear un `Makefile` para el proyecto del ejercicio anterior. El
Makefile debe tener los siguientes objetivos (`targets`):

- **`all`**: El objetivo por defecto, que debe compilar y enlazar todo el
  programa para crear el ejecutable `mi_calculadora`.
- **`clean`**: Un objetivo "phony" que elimina todos los archivos generados por
  la compilación (`.o` y el ejecutable).


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Agregar un target run que dependa de all y ejecute automáticamente el binario compilado.
-   **[*plus ultra*]:** Configurar CFLAGS con las opciones -Wall -Wextra -std=c99.

:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Estructura del Makefile

```{code-block} makefile
:linenos:
# Variable para el compilador
CC = gcc
# Flags de compilación
CFLAGS = -Wall -Wextra -g

# Archivos objeto necesarios
OBJS = main.o calculadora.o

# Nombre del ejecutable final
TARGET = mi_calculadora

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c calculadora.h
	$(CC) $(CFLAGS) -c main.c

calculadora.o: calculadora.c calculadora.h
	$(CC) $(CFLAGS) -c calculadora.c

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

```
<!-- {code-block} makefile -->

:::
<!-- {tip} Estructura del Makefile -->

## Compilación Condicional
(ejercicio_6_4)=
### Ejercicio 6.4 - Mensajes de depuración ⭐⭐☆☆☆

**Tarea**: Modificá tu proyecto para incluir mensajes de depuración que solo se
impriman cuando se compile en "modo debug".

:::{hint} Lógica y Consideraciones
1.  **En el código**: Encerrá tus `printf` de depuración dentro de bloques de
    preprocesador:
    ```c
    #ifdef DEBUG
    printf("[DEBUG] La función sumar fue llamada con a=%d, b=%d\n", a, b);
    #endif
    ```
2.  **En el Makefile**: Modificá la regla de compilación para que se pueda pasar
    una bandera al compilador. La opción `-D` de `gcc` permite definir una macro
    desde la línea de comandos.
    ```makefile
    # Añadir una variable para las macros
    CPPFLAGS =
    # Modificar la regla de compilación
    %.o: %.c
    	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
    ```
3.  **Uso**: Ahora podés compilar normalmente (`make`) o en modo debug (`make
    CPPFLAGS=-DDEBUG`).
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Agregar múltiples niveles de depuración (ej. DEBUG=1, DEBUG=2) utilizando directivas #if DEBUG >= 1.
-   **[*plus ultra*]:** Probar la compilación tanto en modo normal como en modo depuración.

:::
<!-- {hint} Lógica y Consideraciones -->
(ejercicio_6_5)=
## Ejercicio 6.5 - Compilación Básica ⭐☆☆☆☆

Compilá un programa simple desde línea de comandos.

**Orientación:**

:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Compilar con el flag -o especificando un nombre descriptivo para el binario resultante.
-   **[*plus ultra*]:** Ejecutar el programa y verificar su código de salida con echo $? en la terminal.

:::
<!-- {hint} Lógica y Consideraciones -->

``` bash
gcc -o programa programa.c
./programa
```
<!-- bash -->
- `-o` especifica nombre del ejecutable
- Sin `-o`, crea `a.out` por defecto

---
(ejercicio_6_6)=
## Ejercicio 6.6 - Warnings Habilitados ⭐☆☆☆☆

Compilá con warnings completos y corregí los problemas.

**Orientación:**

:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Agregar los flags -Werror -Wpedantic y verificar que el código compile limpiamente sin advertencias.
-   **[*plus ultra*]:** Identificar y corregir advertencias comunes como variables no utilizadas o conversiones implícitas.

:::
<!-- {hint} Lógica y Consideraciones -->

``` bash
gcc -Wall -Wextra -std=c99 -pedantic programa.c -o programa
```
<!-- bash -->
- `-Wall`: warnings comunes
- `-Wextra`: warnings adicionales
- `-std=c99`: estándar C99
- `-pedantic`: estricto con estándar

---
(ejercicio_6_7)=
## Ejercicio 6.7 - Dos Archivos Separados ⭐⭐☆☆☆

Separáun programa en main.c y funciones.c.

**funciones.h:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Estructurar los archivos en subdirectorios src/ e include/ y compilar con -Iinclude.
-   **[*plus ultra*]:** Añadir una tercera función en un módulo adicional utilidades.c y enlazar todos los objetos.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
#ifndef FUNCIONES_H
#define FUNCIONES_H
int sumar(int a, int b);
#endif
```
<!-- c -->

**funciones.c:**
``` c
#include "funciones.h"
int sumar(int a, int b)
{
    return a + b;
}
```
<!-- c -->

**main.c:**
``` c
#include "funciones.h"
#include <stdio.h>
int main()
{
    printf("%d\n", sumar(3, 4));
}
```
<!-- c -->

**Compilación:**
``` bash
gcc -c funciones.c    # Genera funciones.o
gcc -c main.c         # Genera main.o
gcc funciones.o main.o -o programa
```
<!-- bash -->

---
(ejercicio_6_8)=
## Ejercicio 6.8 - Include Guards ⭐⭐☆☆☆

Explicá por qué se necesitan include guards y implementalos.

**Orientación:**

:::{hint} Lógica y Consideraciones
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.

-   **[*plus ultra*]:** Explicar mediante un comentario qué problema de compilación ocurre si se omite la guarda de inclusión.
-   **[*plus ultra*]:** Probar qué sucede al incluir dos veces el mismo header en main.c.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
#ifndef MI_HEADER_H
#define MI_HEADER_H
// Contenido del header
#endif // MI_HEADER_H
```
<!-- c -->
- Previene inclusión múltiple
- Evita errores de redefinición

---
(ejercicio_6_9)=
## Ejercicio 6.9 - Makefile Básico ⭐⭐⭐☆☆

Creá Makefile para compilar proyecto de ejercicio 3.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Usar variables automáticas ($@, $<) en las reglas del Makefile para simplificar los comandos.
-   **[*plus ultra*]:** Declarar el target clean como .PHONY.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

programa: main.o funciones.o
	$(CC) main.o funciones.o -o programa

main.o: main.c funciones.h
	$(CC) $(CFLAGS) -c main.c

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -f *.o programa

```
<!-- {code-block} makefile -->

**Uso:**
``` bash
make           # Compila
make clean     # Limpia
```
<!-- bash -->

---
(ejercicio_6_10)=
## Ejercicio 6.10 - Biblioteca Matemática ⭐⭐⭐☆☆

Creá biblioteca con funciones matemáticas: factorial, potencia, fibonacci.

**Estructura:**

:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Compilar enlazando con la biblioteca matemática estándar usando el flag -lm.
-   **[*plus ultra*]:** Crear un Makefile que compile y ejecute los ejemplos matemáticos automáticamente.

:::
<!-- {hint} Lógica y Consideraciones -->

```
proyecto/
├── matematica.h
├── matematica.c
├── test.c
└── Makefile
```

**Orientación:**
- `matematica.h`: declaraciones
- `matematica.c`: implementaciones
- `test.c`: programa que usa la biblioteca

---
(ejercicio_6_11)=
## Ejercicio 6.11 - Flags de Optimización ⭐⭐⭐☆☆

Compilá con diferentes niveles de optimización y medí diferencia.

**Orientación:**

:::{hint} Lógica y Consideraciones
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.

-   **[*plus ultra*]:** Comparar el tiempo de ejecución del programa compilado con -O0 frente a -O2 o -O3.
-   **[*plus ultra*]:** Inspeccionar el tamaño del binario resultante con cada nivel de optimización.

:::
<!-- {hint} Lógica y Consideraciones -->

``` bash
gcc -O0 programa.c -o prog_O0  # Sin optimización
gcc -O1 programa.c -o prog_O1  # Básica
gcc -O2 programa.c -o prog_O2  # Recomendada
gcc -O3 programa.c -o prog_O3  # Agresiva
```
<!-- bash -->
- Medí tiempo de ejecución: `time ./prog_O2`
- `-O0` útil para debugging
- `-O2` balance entre velocidad y tamaño
- `-O3` máxima optimización

---
(ejercicio_6_12)=
## Ejercicio 6.12 - Compilación Condicional ⭐⭐⭐☆☆

Usá directivas de preprocesador para debug opcional.

**Orientación:**

:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Definir macros de preprocesador mediante el flag -D (ej. -DVERSION="1.0.0").
-   **[*plus ultra*]:** Crear targets separados en el Makefile para compilar con distintas configuraciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
#ifdef DEBUG
printf("Debug: valor = %d\n", valor);
#endif
```
<!-- c -->

**Compilación:**
``` bash
gcc -DDEBUG programa.c -o programa  # Con debug
gcc programa.c -o programa           # Sin debug
```
<!-- bash -->

---
(ejercicio_6_13)=
## Ejercicio 6.13 - Módulo de Utilidades ⭐⭐⭐⭐☆

Creá módulo `utils` con funciones de uso general: intercambio, mínimo, máximo.

**Estructura:**

:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Crear una suite de pruebas en test_utilidades.c que verifique cada función con assert().
-   **[*plus ultra*]:** Agregar un target test en el Makefile que compile y corra las pruebas automáticamente.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
// utils.h
#ifndef UTILS_H
#define UTILS_H
void intercambiar(int *a, int *b);
int minimo(int a, int b);
int maximo(int a, int b);
#endif
// utils.c
#include "utils.h"
// Implementaciones...
// main.c
#include "utils.h"
// Uso...
```
<!-- {code-block} c -->

---
(ejercicio_6_14)=
## Ejercicio 6.14 - Makefile con Variables ⭐⭐⭐⭐☆

Mejorá Makefile usando variables y patrones.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Organizar el Makefile con variables CC, CFLAGS, LDFLAGS y OBJS.
-   **[*plus ultra*]:** Permitir sobrescribir variables desde la línea de comandos (ej. make CC=clang).

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -lm

SRCS = main.c utils.c matematica.c
OBJS = $(SRCS:.c=.o)
TARGET = programa

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean

```
<!-- {code-block} makefile -->

---
(ejercicio_6_15)=
## Ejercicio 6.15 - Dependencias Automáticas ⭐⭐⭐⭐☆

Generá dependencias automáticamente con gcc.

**Orientación:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Usar los flags de gcc -MMD -MP para generar archivos de dependencias .d automáticamente.
-   **[*plus ultra*]:** Incluir los archivos .d en el Makefile mediante la directiva -include.

:::
<!-- {hint} Lógica y Consideraciones -->

``` makefile
DEPS = $(OBJS:.o=.d)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
```
<!-- makefile -->
- `-MMD`: genera archivo .d con dependencias
- `-MP`: crea targets phony para headers

---
(ejercicio_6_16)=
## Ejercicio 6.16 - Biblioteca Estática ⭐⭐⭐⭐⭐

Creá biblioteca estática (.a) y usala en programa.

**Orientación:**

:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Crear una biblioteca estática (.a) utilizando la herramienta ar rcs.
-   **[*plus ultra*]:** Enlazar el ejecutable principal contra la biblioteca estática creada.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} bash
:linenos:
# Compilar objetos
gcc -c modulo1.c modulo2.c

# Crear biblioteca estática
ar rcs libmibiblioteca.a modulo1.o modulo2.o

# Usar biblioteca
gcc main.c -L. -lmibiblioteca -o programa

```
<!-- {code-block} bash -->
- `ar`: archiver, crea bibliotecas
- `-L.`: buscar bibliotecas en directorio actual
- `-lmibiblioteca`: enlazar con libmibiblioteca.a

---
(ejercicio_6_17)=
## Ejercicio 6.17 - Biblioteca Compartida ⭐⭐⭐⭐⭐

Creá biblioteca compartida (.so) y usala.

**Orientación:**

:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Crear una biblioteca compartida (.so) compilando con -fPIC y enlazando con -shared.
-   **[*plus ultra*]:** Ejecutar el programa configurando LD_LIBRARY_PATH.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} bash
:linenos:
# Compilar con PIC (Position Independent Code)
gcc -fPIC -c modulo.c

# Crear biblioteca compartida
gcc -shared modulo.o -o libmodulo.so

# Compilar programa
gcc main.c -L. -lmodulo -o programa

# Ejecutar (necesita encontrar .so)
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./programa

```
<!-- {code-block} bash -->

---
(ejercicio_6_18)=
## Ejercicio 6.18 - Proyecto Multi-Directorio ⭐⭐⭐⭐⭐

Organizá proyecto en directorios: src/, include/, obj/, bin/.

**Estructura:**

:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Organizar el proyecto con estructura src/, include/, obj/, bin/.
-   **[*plus ultra*]:** Crear un Makefile que cree automáticamente los directorios obj/ y bin/ si no existen.

:::
<!-- {hint} Lógica y Consideraciones -->

```
proyecto/
├── src/
│   ├── main.c
│   └── modulo.c
├── include/
│   └── modulo.h
├── obj/        (generado)
├── bin/        (generado)
└── Makefile
```

**Makefile:**
```{code-block} makefile
:linenos:
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

CFLAGS = -I$(INCDIR) -Wall -Wextra

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

$(BINDIR)/programa: $(OBJS) | $(BINDIR)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) $(BINDIR):
	mkdir -p $@

```
<!-- {code-block} makefile -->

---
(ejercicio_6_19)=
## Ejercicio 6.19 - Targets Adicionales ⭐⭐⭐⭐☆

Agregá targets útiles: run, test, install, uninstall.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Agregar targets adicionales como help, info y format en el Makefile.
-   **[*plus ultra*]:** Asegurar que todos los targets auxiliares estén listados en .PHONY.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET) test_input.txt

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

.PHONY: run test install uninstall

```
<!-- {code-block} makefile -->

---
(ejercicio_6_20)=
## Ejercicio 6.20 - Compilación Debug/Release ⭐⭐⭐⭐⭐

Makefile con modo debug y release.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Definir reglas separadas en el Makefile para compilar en modo Debug (-g -O0) y Release (-O2 -DNDEBUG).
-   **[*plus ultra*]:** Colocar los binarios de cada perfil en carpetas de salida separadas (bin/debug/ y bin/release/).

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
MODE ?= release

ifeq ($(MODE),debug)
    CFLAGS += -g -O0 -DDEBUG
    TARGET = programa_debug
else
    CFLAGS += -O2 -DNDEBUG
    TARGET = programa
endif

all: $(TARGET)
	@echo "Compiled in $(MODE) mode"

# Uso:
# make              # Release
# make MODE=debug   # Debug

```
<!-- {code-block} makefile -->

---
(ejercicio_6_21)=
## Ejercicio 6.21 - Análisis Estático ⭐⭐⭐⭐☆

Integrá herramientas de análisis en Makefile.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Ejecutar herramientas de análisis como cppcheck o clang-tidy sobre los archivos fuente.
-   **[*plus ultra*]:** Integrar un target check o lint en el Makefile para correr el análisis estático.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
check: $(SRCS)
	cppcheck --enable=all $(SRCS)

format: $(SRCS)
	clang-format -i $(SRCS)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: check format valgrind

```
<!-- {code-block} makefile -->

---
(ejercicio_6_22)=
## Ejercicio 6.22 - Cross-Compilation ⭐⭐⭐⭐⭐

Configurá cross-compilation para diferentes arquitecturas.

**Makefile:**

:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Configurar el Makefile para soportar compilación cruzada especificando el prefijo CROSS_COMPILE.
-   **[*plus ultra*]:** Verificar que la arquitectura de destino sea configurable mediante una variable.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} makefile
:linenos:
# Compilación nativa
CC_NATIVE = gcc
TARGET_NATIVE = programa

# Cross-compilation para ARM
CC_ARM = arm-linux-gnueabi-gcc
TARGET_ARM = programa_arm

arm: CC = $(CC_ARM)
arm: TARGET = $(TARGET_ARM)
arm: $(TARGET)

native: CC = $(CC_NATIVE)
native: TARGET = $(TARGET_NATIVE)
native: $(TARGET)

```
<!-- {code-block} makefile -->

---
(ejercicio_6_23)=
## Ejercicio 6.23 - Sistema de Build Completo ⭐⭐⭐⭐⭐

Proyecto completo con múltiples bibliotecas y tests.

**Estructura:**

:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Diseñar un Makefile modular y completo que incluya compilación, tests, documentación y empaquetado.
-   **[*plus ultra*]:** Asegurar que make clean limpie absolutamente todos los artefactos intermedios generados.

:::
<!-- {hint} Lógica y Consideraciones -->

```
proyecto/
├── lib/
│   ├── util/
│   │   ├── util.h
│   │   └── util.c
│   └── math/
│       ├── math.h
│       └── math.c
├── src/
│   └── main.c
├── tests/
│   ├── test_util.c
│   └── test_math.c
└── Makefile
```

**Orientación:**
- Compilar bibliotecas separadamente
- Enlazar con main
- Target para tests
- Target para todo (all)

---
(ejercicio_6_24)=
## Ejercicio 6.24 - CMake Básico ⭐⭐⭐⭐⭐

Convertí proyecto a usar CMake en lugar de Makefile.

**CMakeLists.txt:**

:::{hint} Lógica y Consideraciones
    garantizar la liberación total de recursos en caso de error.
    leaks*) mediante Valgrind o AddressSanitizer.

-   **[*plus ultra*]:** Crear un archivo CMakeLists.txt básico que defina el proyecto, ejecutables y bibliotecas.
-   **[*plus ultra*]:** Generar y compilar el proyecto en un directorio build/ separado.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} cmake
:linenos:
cmake_minimum_required(VERSION 3.10)
project(MiProyecto C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(programa
    src/main.c
    src/modulo.c
)

target_link_libraries(programa m)

# Tests
enable_testing()
add_executable(tests tests/test_main.c)
add_test(NAME tests COMMAND tests)

```
<!-- {code-block} cmake -->

**Uso:**
``` bash
mkdir build
cd build
cmake ..
make
./programa
```
<!-- bash -->

---

## Notas Finales

:::{tip} Proceso de Compilación

**Etapas:**
1. **Preprocesamiento:** Expande #include, #define
   - `gcc -E programa.c` para ver resultado
2. **Compilación:** C → Assembly
   - `gcc -S programa.c` genera programa.s
3. **Ensamblado:** Assembly → Código objeto
   - `gcc -c programa.c` genera programa.o
4. **Enlazado:** Objetos + bibliotecas → Ejecutable
   - `gcc programa.o -o programa`

**Flags útiles:**
- `-E`: Solo preprocesar
- `-S`: Generar assembly
- `-c`: Compilar sin enlazar
- `-o`: Especificar nombre de salida
- `-I`: Agregar directorio de includes
- `-L`: Agregar directorio de bibliotecas
- `-l`: Enlazar con biblioteca

:::
<!-- {tip} Proceso de Compilación -->

:::{note} Sintaxis de Makefile

**Regla básica:**
``` makefile
target: dependencias
	comando
```
<!-- makefile -->
- **target:** Archivo a generar
- **dependencias:** Archivos necesarios
- **comando:** Qué ejecutar (debe empezar con TAB)

**Variables:**
``` makefile
CC = gcc
CFLAGS = -Wall

$(CC) $(CFLAGS) programa.c
```
<!-- makefile -->

**Variables automáticas:**
- `$@`: Target
- `$<`: Primera dependencia
- `$^`: Todas las dependencias
- `$*`: Stem (parte que coincide con %)

**Patrones:**
``` makefile
%.o: %.c
	$(CC) -c $< -o $@
```
<!-- makefile -->

:::
<!-- {note} Sintaxis de Makefile -->

:::{warning} Errores Comunes

1. **Olvidar include guard:**
   ```c
   // Sin guard, múltiples inclusiones causan error
   #ifndef HEADER_H
   #define HEADER_H
   // ...
   #endif
   ```

2. **Orden de enlazado:**
   ```bash
   # MAL
   gcc -lm programa.c
   
   # BIEN
   gcc programa.c -lm
   ```
   - Bibliotecas después de los archivos que las usan

3. **Espacios en lugar de TAB en Makefile:**
   ```makefile
   target:
       comando  # MAL: espacios
   	comando  # BIEN: TAB
   ```

4. **Incluir .c en vez de .h:**
   ```c
   #include "modulo.c" // MAL
   #include "modulo.h" // BIEN
   ```

:::
<!-- {warning} Errores Comunes -->

:::{tip} Mejores Prácticas

1. **Headers:**
   - Siempre usar include guards
   - Solo declaraciones en .h
   - Documentar funciones públicas

2. **Separación:**
   - Un .c por módulo lógico
   - Header correspondiente para cada .c
   - main.c mínimo, lógica en módulos

3. **Makefile:**
   - Variables para CC, CFLAGS
   - Target `clean` siempre
   - `.PHONY` para targets sin archivo
   - Dependencias correctas

4. **Compilación:**
   - Siempre `-Wall -Wextra`
   - `-g` para debugging
   - `-O2` para release
   - `-std=c99` o superior

:::
<!-- {tip} Mejores Prácticas -->

:::{note} Herramientas Útiles

**Análisis:**
- `cppcheck`: Análisis estático
- `valgrind`: Detección de memory leaks
- `gdb`: Debugger
- `clang-format`: Formateo automático

**Build Systems:**
- `make`: Clásico, universal
- `cmake`: Moderno, cross-platform
- `autotools`: GNU standard (configure, make, make install)
- `ninja`: Muy rápido

**Comandos útiles:**
```{code-block} bash
:linenos:
# Ver símbolos en objeto
nm programa.o

# Ver bibliotecas dinámicas necesarias
ldd programa

# Ver tamaño de secciones
size programa

# Desensamblar
objdump -d programa.o

```
<!-- {code-block} bash -->

:::
<!-- {note} Herramientas Útiles -->

Estas consignas cubren compilación desde comandos básicos hasta proyectos
complejos multi-archivo con automatización profesional.

