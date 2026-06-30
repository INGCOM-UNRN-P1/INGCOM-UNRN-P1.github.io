---
title: Automatización de Compilación con Makefiles
short_title: '5b - Makefiles'
subtitle: 'Estructura de Makefiles, dependencias y compilación incremental en C'
---

(capitulo-makefiles-basico)=
## Introducción

A medida que los proyectos escritos en C crecen y se modularizan en múltiples archivos de cabecera (`.h`) y de implementación (`.c`), compilar el código manualmente invocando directamente al compilador en la terminal se vuelve ineficiente y propenso a errores. 

Para automatizar este flujo, en el ecosistema Unix se emplea la herramienta **`make`**, la cual lee las reglas de construcción de un archivo de configuración denominado **`Makefile`**.

## Desarrollo

### 1. ¿Qué es un Makefile y la Compilación Incremental?

La utilidad `make` funciona modelando el proyecto como un **grafo de dependencias** (un grafo dirigido donde los nodos representan archivos físicos y las aristas las relaciones de dependencia lógica entre ellos).

#### Compilación Incremental

La principal ventaja de `make` es la **compilación incremental**. Al analizar las marcas de tiempo de modificación física (*timestamps*) de los archivos en el disco:
1.  `make` compara la fecha del archivo de salida (ej: un archivo objeto `.o`) con las fechas de sus archivos fuentes y cabeceras de entrada correspondientes.
2.  Si ninguno de los archivos de entrada ha sido modificado desde la última compilación, `make` omite de forma inteligente la compilación de ese módulo.
3.  Solo se recompilan los módulos modificados, lo que ahorra una cantidad significativa de tiempo de procesamiento en proyectos de mediana y gran escala.

### 2. Anatomía de una Regla en un Makefile

Un archivo `Makefile` está compuesto por un conjunto de reglas que tienen la siguiente estructura sintáctica:

```makefile
objetivo: dependencias
	receta (comandos de compilación)
```

*   **Objetivo (Target):** El archivo físico que se desea generar (o una acción ficticia).
*   **Dependencias (Prerequisites):** La lista de archivos necesarios para construir el objetivo.
*   **Receta (Recipe):** El comando de consola que se ejecuta para generar el objetivo.

:::{important} Requisito de Indentación Estricto
Los comandos de la receta en un `Makefile` deben estar precedidos **obligatoriamente por un carácter de tabulación físico (Tab)**. Si utilizás espacios en su lugar, `make` fallará arrojando un error sintáctico de tipo `Makefile: missing separator`.
:::

#### Ejemplo de un Makefile Modular Básico

Supongamos un proyecto con una estructura simple:
*   `calculadora.c` y `calculadora.h` (implementación de aritmética).
*   `main.c` (punto de entrada que utiliza la calculadora).

El `Makefile` correspondiente para este proyecto se define de la siguiente manera:

```makefile
# Definición de variables para facilitar el mantenimiento
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

# El primer objetivo es el que se ejecuta por defecto al invocar "make"
programa: main.o calculadora.o
	$(CC) $(CFLAGS) -o programa main.o calculadora.o

# Reglas para construir los archivos objeto
main.o: main.c calculadora.h
	$(CC) $(CFLAGS) -c main.c -o main.o

calculadora.o: calculadora.c calculadora.h
	$(CC) $(CFLAGS) -c calculadora.c -o calculadora.o

# Regla de limpieza para borrar archivos binarios y temporales
.PHONY: clean
clean:
	rm -f *.o programa
```

#### Objetivos Ficticios (`.PHONY`)

Los objetivos declarados bajo la directiva **`.PHONY`** son objetivos especiales que no representan archivos reales en el disco. Le indican a `make` que debe ejecutar la receta asociada de forma incondicional siempre que se invoque la regla, sin importar si existe un archivo físico con el mismo nombre en la carpeta.

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-make-incremental
Describí el criterio físico que utiliza la herramienta `make` para decidir si es necesario reconstruir un archivo objeto (por ejemplo, `funciones.o`) a partir de su archivo fuente `funciones.c`.
:::

:::{solution} ej-make-incremental
:class: dropdown
`make` examina las **marcas de tiempo de modificación (timestamps)** de los archivos en el disco físico.

Si la fecha de última modificación del archivo de entrada (`funciones.c` o alguna de sus cabeceras declaradas como dependencias, ej: `funciones.h`) es **más reciente** que la fecha de última modificación del archivo objeto de salida (`funciones.o`), `make` deduce que el código fuente cambió y ejecuta la receta de compilación para reconstruir el objeto. Si el objeto es más nuevo que sus dependencias, `make` omite su compilación.
:::

:::{exercise}
:label: ej-make-clean-phony
Explicá detalladamente para qué sirve la regla `.PHONY: clean` en un Makefile y qué problema se produciría si se omitiera esta declaración y existiera en el directorio un archivo físico llamado `clean`.
:::

:::{solution} ej-make-clean-phony
:class: dropdown
La directiva `.PHONY` le indica a `make` que el objetivo indicado no corresponde a un archivo real que deba ser generado.

Si se omitiera `.PHONY: clean` y en el mismo directorio existiera un archivo llamado `clean`, al ejecutar `make clean`, la herramienta buscaría dependencias para el objetivo `clean`. Al no tener dependencias y ver que el archivo `clean` ya existe físicamente en el disco, `make` reportaría que el objetivo está actualizado (`make: 'clean' is up to date`) y se negaría a ejecutar el bloque de comandos para limpiar el proyecto.
:::

:::{exercise}
:label: ej-make-escritura
Escribí una regla de Makefile para compilar el archivo objeto `usuario.o` a partir de sus dependencias `usuario.c` y `usuario.h`. Utilizá variables para el compilador (`$(CC)`) y banderas (`$(CFLAGS)`), recordando el requisito de indentación de Makefiles.
:::

:::{solution} ej-make-escritura
:class: dropdown
```makefile
usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c -o usuario.o
```
*Nota: La línea de comandos de la receta debe estar precedida obligatoriamente por un carácter de tabulación (Tab) en el archivo físico.*
:::

## Glosario

:::{glossary}
Grafo de dependencias
: Estructura dirigida que representa las relaciones entre los archivos fuente y los archivos generados.

Compilación incremental
: Técnica de optimización que solo recompila los archivos modificados desde la última construcción.

Regla (.PHONY)
: Objetivo especial en un Makefile que no representa un archivo real y se ejecuta de forma incondicional.
:::

## Síntesis y Resumen

La herramienta `make` automatiza la compilación incremental leyendo un `Makefile`. Este archivo define un grafo de dependencias entre objetivos (archivos a generar), prerrequisitos (archivos de entrada) y recetas (comandos de compilación). Al comparar las marcas de tiempo físicas, `make` evita la recompilación innecesaria de módulos sin cambios. Se utilizan objetivos ficticios (`.PHONY`) para definir tareas que no producen archivos reales en disco.

## Referencias y Lecturas Complementarias

- {cite:t}`mecklenburg_managing_2004`. Guía práctica de Makefiles complejos.
- **Makefile Tutorial** - https://makefiletutorial.com/
