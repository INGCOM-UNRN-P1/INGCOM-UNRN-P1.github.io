---
title: "Ejercicios: Compilación y Makefiles"
short_title: "14. Compilación"
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

### Ejercicio 2.1 - Separar un programa

**Tarea**: Tomá un programa simple que tengas en un solo archivo `.c` (por
ejemplo, una calculadora con funciones `sumar` y `restar`) y dividilo en tres
archivos:

- **`calculadora.h`**: El archivo de cabecera. Debe contener solo los prototipos
  de las funciones `sumar` y `restar` y las guardas de inclusión.
- **`calculadora.c`**: La implementación. Debe incluir `calculadora.h` y
  contener el código de las funciones `sumar` y `restar`.
- **`main.c`**: El programa principal. Debe incluir `calculadora.h` y llamar a
  las funciones para usarlas.

### Ejercicio 2.2 - Compilación manual

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

:::
<!-- {hint} Pasos de Compilación -->

## Automatización con Makefile

### Ejercicio 2.3 - Makefile básico

**Tarea**: Crear un `Makefile` para el proyecto del ejercicio anterior. El
Makefile debe tener los siguientes objetivos (`targets`):

- **`all`**: El objetivo por defecto, que debe compilar y enlazar todo el
  programa para crear el ejecutable `mi_calculadora`.
- **`clean`**: Un objetivo "phony" que elimina todos los archivos generados por
  la compilación (`.o` y el ejecutable).

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

### Ejercicio 2.4 - Mensajes de depuración

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

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Ejercicios Adicionales (Práctica Intensiva)

## Ejercicio 1: Compilación Básica

**Dificultad:** ⭐☆☆☆☆

Compilá un programa simple desde línea de comandos.

**Orientación:**
```bash
gcc -o programa programa.c
./programa
```
- `-o` especifica nombre del ejecutable
- Sin `-o`, crea `a.out` por defecto

---

## Ejercicio 2: Warnings Habilitados

**Dificultad:** ⭐☆☆☆☆

Compilá con warnings completos y corregí los problemas.

**Orientación:**
```bash
gcc -Wall -Wextra -std=c99 -pedantic programa.c -o programa
```
- `-Wall`: warnings comunes
- `-Wextra`: warnings adicionales
- `-std=c99`: estándar C99
- `-pedantic`: estricto con estándar

---

## Ejercicio 3: Dos Archivos Separados

**Dificultad:** ⭐⭐☆☆☆

Separáun programa en main.c y funciones.c.

**funciones.h:**
```c
#ifndef FUNCIONES_H
#define FUNCIONES_H

int sumar(int a, int b);

#endif
```

**funciones.c:**
```c
#include "funciones.h"

int sumar(int a, int b) {
    return a + b;
}
```

**main.c:**
```c
#include <stdio.h>
#include "funciones.h"

int main() {
    printf("%d\n", sumar(3, 4));
}
```

**Compilación:**
```bash
gcc -c funciones.c    # Genera funciones.o
gcc -c main.c         # Genera main.o
gcc funciones.o main.o -o programa
```

---

## Ejercicio 4: Include Guards

**Dificultad:** ⭐⭐☆☆☆

Explicá por qué se necesitan include guards y implementalos.

**Orientación:**
```c
#ifndef MI_HEADER_H
#define MI_HEADER_H

// Contenido del header

#endif  // MI_HEADER_H
```
- Previene inclusión múltiple
- Evita errores de redefinición

---

## Ejercicio 5: Makefile Básico

**Dificultad:** ⭐⭐⭐☆☆

Creá Makefile para compilar proyecto de ejercicio 3.

**Makefile:**
```makefile
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

**Uso:**
```bash
make           # Compila
make clean     # Limpia
```

---

## Ejercicio 6: Biblioteca Matemática

**Dificultad:** ⭐⭐⭐☆☆

Creá biblioteca con funciones matemáticas: factorial, potencia, fibonacci.

**Estructura:**
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

## Ejercicio 7: Flags de Optimización

**Dificultad:** ⭐⭐⭐☆☆

Compilá con diferentes niveles de optimización y medí diferencia.

**Orientación:**
```bash
gcc -O0 programa.c -o prog_O0  # Sin optimización
gcc -O1 programa.c -o prog_O1  # Básica
gcc -O2 programa.c -o prog_O2  # Recomendada
gcc -O3 programa.c -o prog_O3  # Agresiva
```
- Medí tiempo de ejecución: `time ./prog_O2`
- `-O0` útil para debugging
- `-O2` balance entre velocidad y tamaño
- `-O3` máxima optimización

---

## Ejercicio 8: Compilación Condicional

**Dificultad:** ⭐⭐⭐☆☆

Usá directivas de preprocesador para debug opcional.

**Orientación:**
```c
#ifdef DEBUG
    printf("Debug: valor = %d\n", valor);
#endif
```

**Compilación:**
```bash
gcc -DDEBUG programa.c -o programa  # Con debug
gcc programa.c -o programa           # Sin debug
```

---

## Ejercicio 9: Módulo de Utilidades

**Dificultad:** ⭐⭐⭐⭐☆

Creá módulo `utils` con funciones de uso general: intercambio, mínimo, máximo.

**Estructura:**
```c
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

---

## Ejercicio 10: Makefile con Variables

**Dificultad:** ⭐⭐⭐⭐☆

Mejorá Makefile usando variables y patrones.

**Makefile:**
```makefile
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

---

## Ejercicio 11: Dependencias Automáticas

**Dificultad:** ⭐⭐⭐⭐☆

Generá dependencias automáticamente con gcc.

**Orientación:**
```makefile
DEPS = $(OBJS:.o=.d)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
```
- `-MMD`: genera archivo .d con dependencias
- `-MP`: crea targets phony para headers

---

## Ejercicio 12: Biblioteca Estática

**Dificultad:** ⭐⭐⭐⭐⭐

Creá biblioteca estática (.a) y usala en programa.

**Orientación:**
```bash
# Compilar objetos
gcc -c modulo1.c modulo2.c

# Crear biblioteca estática
ar rcs libmibiblioteca.a modulo1.o modulo2.o

# Usar biblioteca
gcc main.c -L. -lmibiblioteca -o programa
```
- `ar`: archiver, crea bibliotecas
- `-L.`: buscar bibliotecas en directorio actual
- `-lmibiblioteca`: enlazar con libmibiblioteca.a

---

## Ejercicio 13: Biblioteca Compartida

**Dificultad:** ⭐⭐⭐⭐⭐

Creá biblioteca compartida (.so) y usala.

**Orientación:**
```bash
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

---

## Ejercicio 14: Proyecto Multi-Directorio

**Dificultad:** ⭐⭐⭐⭐⭐

Organizá proyecto en directorios: src/, include/, obj/, bin/.

**Estructura:**
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
```makefile
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

---

## Ejercicio 15: Targets Adicionales

**Dificultad:** ⭐⭐⭐⭐☆

Agregá targets útiles: run, test, install, uninstall.

**Makefile:**
```makefile
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

---

## Ejercicio 16: Compilación Debug/Release

**Dificultad:** ⭐⭐⭐⭐⭐

Makefile con modo debug y release.

**Makefile:**
```makefile
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

---

## Ejercicio 17: Análisis Estático

**Dificultad:** ⭐⭐⭐⭐☆

Integrá herramientas de análisis en Makefile.

**Makefile:**
```makefile
check: $(SRCS)
	cppcheck --enable=all $(SRCS)

format: $(SRCS)
	clang-format -i $(SRCS)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: check format valgrind
```

---

## Ejercicio 18: Cross-Compilation

**Dificultad:** ⭐⭐⭐⭐⭐

Configurá cross-compilation para diferentes arquitecturas.

**Makefile:**
```makefile
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

---

## Ejercicio 19: Sistema de Build Completo

**Dificultad:** ⭐⭐⭐⭐⭐

Proyecto completo con múltiples bibliotecas y tests.

**Estructura:**
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

## Ejercicio 20: CMake Básico

**Dificultad:** ⭐⭐⭐⭐⭐

Convertí proyecto a usar CMake en lugar de Makefile.

**CMakeLists.txt:**
```cmake
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

**Uso:**
```bash
mkdir build
cd build
cmake ..
make
./programa
```

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

:::{note} Sintaxis de Makefile

**Regla básica:**
```makefile
target: dependencias
	comando
```
- **target:** Archivo a generar
- **dependencias:** Archivos necesarios
- **comando:** Qué ejecutar (debe empezar con TAB)

**Variables:**
```makefile
CC = gcc
CFLAGS = -Wall

$(CC) $(CFLAGS) programa.c
```

**Variables automáticas:**
- `$@`: Target
- `$<`: Primera dependencia
- `$^`: Todas las dependencias
- `$*`: Stem (parte que coincide con %)

**Patrones:**
```makefile
%.o: %.c
	$(CC) -c $< -o $@
```
:::

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
   #include "modulo.c"  // MAL
   #include "modulo.h"  // BIEN
   ```
:::

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
```bash
# Ver símbolos en objeto
nm programa.o

# Ver bibliotecas dinámicas necesarias
ldd programa

# Ver tamaño de secciones
size programa

# Desensamblar
objdump -d programa.o
```
:::

Estas consignas cubren compilación desde comandos básicos hasta proyectos complejos multi-archivo con automatización profesional.

