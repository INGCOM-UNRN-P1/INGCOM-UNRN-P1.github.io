---
title: "Ejercicios: Compilación y Makefiles"
short_title: "14. Compilación"
---

# Ejercicios: Compilación y Makefiles

## Acerca de

Comprender el proceso de compilación y saber cómo automatizarlo es una habilidad esencial para cualquier programador de C. Estos ejercicios te guiarán a través de la creación de proyectos multi-archivo, el uso de `gcc` para compilar y enlazar, y la escritura de `Makefiles` básicos para gestionar la compilación de forma eficiente.

Para profundizar en los conceptos teóricos, podés consultar los siguientes capítulos del apunte:
- [Compilación](../../apunte/bloque_2_proyectos/1_compilacion.md)
- [Makefiles](../../apunte/bloque_2_proyectos/2_makefiles.md)

## Proyecto Multi-archivo Manual

### Ejercicio 2.1 - Separar un programa

**Tarea**: Tomá un programa simple que tengas en un solo archivo `.c` (por ejemplo, una calculadora con funciones `sumar` y `restar`) y dividilo en tres archivos:

- **`calculadora.h`**: El archivo de cabecera. Debe contener solo los prototipos de las funciones `sumar` y `restar` y las guardas de inclusión.
- **`calculadora.c`**: La implementación. Debe incluir `calculadora.h` y contener el código de las funciones `sumar` y `restar`.
- **`main.c`**: El programa principal. Debe incluir `calculadora.h` y llamar a las funciones para usarlas.

### Ejercicio 2.2 - Compilación manual

**Tarea**: Usando la terminal, compilá y enlazá los archivos del ejercicio anterior sin usar un Makefile.

:::{hint} Pasos de Compilación

1.  **Compilar los archivos objeto (`.o`)**: Se usa la opción `-c` de `gcc` para compilar cada archivo fuente por separado.
    ```bash
    gcc -c main.c -o main.o
    gcc -c calculadora.c -o calculadora.o
    ```
2.  **Enlazar los objetos**: Se combinan los archivos objeto para crear el ejecutable final.
    ```bash
    gcc main.o calculadora.o -o mi_calculadora
    ```

:::

## Automatización con Makefile

### Ejercicio 2.3 - Makefile básico

**Tarea**: Crear un `Makefile` para el proyecto del ejercicio anterior. El Makefile debe tener los siguientes objetivos (`targets`):

- **`all`**: El objetivo por defecto, que debe compilar y enlazar todo el programa para crear el ejecutable `mi_calculadora`.
- **`clean`**: Un objetivo "phony" que elimina todos los archivos generados por la compilación (`.o` y el ejecutable).

:::{tip} Estructura del Makefile

```makefile
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

:::

## Compilación Condicional

### Ejercicio 2.4 - Mensajes de depuración

**Tarea**: Modificá tu proyecto para incluir mensajes de depuración que solo se impriman cuando se compile en "modo debug".

:::{hint} Lógica y Consideraciones

1.  **En el código**: Encerrá tus `printf` de depuración dentro de bloques de preprocesador:
    ```c
    #ifdef DEBUG
        printf("[DEBUG] La función sumar fue llamada con a=%d, b=%d\n", a, b);
    #endif
    ```
2.  **En el Makefile**: Modificá la regla de compilación para que se pueda pasar una bandera al compilador. La opción `-D` de `gcc` permite definir una macro desde la línea de comandos.

    ```makefile
    # Añadir una variable para las macros
    CPPFLAGS =

    # Modificar la regla de compilación
    %.o: %.c
    	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
    ```

3.  **Uso**: Ahora podés compilar normalmente (`make`) o en modo debug (`make CPPFLAGS=-DDEBUG`).

:::
