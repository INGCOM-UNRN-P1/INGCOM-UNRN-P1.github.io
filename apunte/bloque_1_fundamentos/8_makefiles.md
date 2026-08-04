title: Automatización de Compilación con Makefiles
short_title: 'Makefiles'
subtitle: 'Estructura de Makefiles, dependencias y compilación incremental en C'

(capitulo-makefiles-basico)=
## Introducción

A medida que los proyectos escritos en C crecen y se modularizan en múltiples
archivos de cabecera (`.h`) y de implementación (`.c`), compilar el código
manualmente invocando directamente al compilador en la terminal se vuelve
ineficiente y propenso a errores.

Para automatizar este flujo, en el ecosistema Unix se emplea la herramienta
**`make`**, la cual lee las reglas de construcción de un archivo de
configuración denominado **`Makefile`**.


## Desarrollo

### 1. ¿Qué es un Makefile y la Compilación Incremental?

La utilidad `make` funciona modelando el proyecto como un **Grafo Dirigido
Acíclico (DAG)**. En esta estructura formal, los nodos representan archivos
físicos del sistema de archivos y las aristas dirigidas representan las
relaciones de dependencia lógica entre ellos.

#### Compilación Incremental y Marcas de Tiempo

La principal ventaja de `make` es la **compilación incremental**. La herramienta
`make` decide si un archivo objetivo debe reconstruirse comparando la marca de
tiempo de modificación física del objetivo con la de sus dependencias en el
disco:

$$\text{Si } T(\text{Objetivo}) < T(\text{Dependencia}) \implies \text{Se ejecuta la regla de compilación}$$

Si cambiaste un archivo de cabecera `punto.h`, todos los archivos `.o` que
dependen de él serán detectados como más viejos que la cabecera modificada y se
recompilarán. Los módulos que no dependen de `punto.h` no serán procesados,
permitiendo una compilación incremental eficiente.

:::{figure} 8/dag_compilacion.svg
:label: fig-dag-compilacion
:align: center
:width: 85%

Representación como Grafo Dirigido Acíclico (DAG) de dependencias de
compilación. Si `main.c` cambia, se invalida `main.o` y por ende se requiere
volver a generar el ejecutable `programa`, pero se omite la recompilación de
`comun.c`.

:::
<!-- {figure} 2/dag_compilacion.svg -->

### 2. Anatomía de una Regla en un Makefile

Un archivo `Makefile` está compuesto por un conjunto de reglas que tienen la
siguiente estructura sintáctica:

``` makefile
objetivo: dependencias
	receta (comandos de compilación)
```
<!-- makefile -->

*   **Objetivo (Target):** El archivo físico que se desea generar (o una acción
    ficticia).
*   **Dependencias (Prerequisites):** La lista de archivos necesarios para
    construir el objetivo.
*   **Receta (Recipe):** El comando de consola que se ejecuta para generar el
    objetivo.

:::{important} Requisito de Indentación Estricto

Los comandos de la receta en un `Makefile` deben estar precedidos
**obligatoriamente por un carácter de tabulación físico (Tab)**. Si utilizás
espacios en su lugar, `make` fallará arrojando un error sintáctico de tipo
`Makefile: missing separator`.

:::
<!-- {important} Requisito de Indentación Estricto -->


### 3. Evolución Gradual de un Makefile (Las 3 Fases)

Para simplificar la introducción a la sintaxis de `make`, analizaremos cómo
evoluciona un Makefile de forma incremental. Supongamos un proyecto con:
*   `calculadora.c` y `calculadora.h` (implementación de aritmética).
*   `main.c` (punto de entrada que utiliza la calculadora).

:::{note} Si funciona...

Cualquiera de las siguientes tres fases va bien, en la medida que funcione al
proyecto.

Pero si se ven en la necesidad de modificar mucho los Makefiles, quizás sea el
momento de mejorarlos.

:::
<!-- {note} Si funciona... -->


#### Fase 1: Makefiles Explícitos

En esta fase inicial, declaramos de forma rígida cada archivo y comando de
compilación sin abstracciones. Cada regla llama directamente a `gcc`:

```{code-block} makefile
:caption: Makefile de Fase 1 (Explícito)
:linenos:

# El primer objetivo es el que se ejecuta por defecto
programa: main.o calculadora.o
	gcc -Wall -Wextra -Werror -std=c99 -o programa main.o calculadora.o

# Reglas rígidas para construir cada archivo objeto
main.o: main.c calculadora.h
	gcc -Wall -Wextra -Werror -std=c99 -c main.c -o main.o

calculadora.o: calculadora.c calculadora.h
	gcc -Wall -Wextra -Werror -std=c99 -c calculadora.c -o calculadora.o

```
<!-- {code-block} makefile -->

#### Fase 2: Introducción de Variables (CC y CFLAGS)

Para evitar repetir las banderas del compilador y permitir cambiar de compilador
rápidamente (por ejemplo, a `clang`), introducimos variables (o macros de
Makefile):

```{code-block} makefile
:caption: Makefile de Fase 2 (Parametrizado con Variables)
:linenos:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

programa: main.o calculadora.o
	$(CC) $(CFLAGS) -o programa main.o calculadora.o

main.o: main.c calculadora.h
	$(CC) $(CFLAGS) -c main.c -o main.o

calculadora.o: calculadora.c calculadora.h
	$(CC) $(CFLAGS) -c calculadora.c -o calculadora.o

```
<!-- {code-block} makefile -->

#### Fase 3: Reglas de Patrón y Variables Automáticas (Producción)

En proyectos reales con decenas de archivos, escribir una regla por cada `.c` es
inviable. Para solucionar esto, la Fase 3 utiliza **reglas de patrón** (`%o:
%c`) y **variables automáticas**:
*   `$@`: Representa el nombre del **Objetivo** actual de la regla.
*   `$<`: Representa la **primera dependencia** de la lista (normalmente el
    archivo fuente `.c`).
*   `$^`: Representa **todas las dependencias** de la regla.

```{code-block} makefile
:caption: Makefile de Fase 3 (Robustez y Patrones)
:linenos:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
OBJS = main.o calculadora.o

programa: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla de patrón: compila cualquier archivo .o a partir de su .c
# $@ toma el valor del objeto (ej. calculadora.o) y $< el del fuente (calculadora.c)
%.o: %.c calculadora.h
	$(CC) $(CFLAGS) -c $< -o $@

```
<!-- {code-block} makefile -->


#### Recetario de Plantilla Única

La cátedra provee en las prácticas una plantilla genérica funcional de Makefile
para que el alumno pueda copiarla y pegarla directamente en sus proyectos sin
necesidad de profundizar inmediatamente en la sintaxis interna de Make. Esta
plantilla escanea de forma automática todos los archivos `.c` de la carpeta para
generar el ejecutable:

```{code-block} makefile
:linenos:
# Variables de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

# Nombre del ejecutable binario
TARGET = programa

# Escaneo automático de archivos fuente y generación de objetos
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Regla principal por defecto
all: $(TARGET)

# Vinculación del ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilación de objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Objetivo de limpieza
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

```
<!-- {code-block} makefile -->

### 4. Objetivos Ficticios (`.PHONY`)

Los objetivos declarados bajo la directiva **`.PHONY`** son objetivos especiales
que no representan archivos reales en el disco. Le indican a `make` que debe
ejecutar la receta asociada de forma incondicional siempre que se invoque la
regla, sin importar si existe un archivo físico con el mismo nombre en la
carpeta.

``` makefile
.PHONY: clean
clean:
	rm -f *.o programa
```
<!-- makefile -->


## Ejercicios de Autoevaluación

:::{exercise}
:label: 2_makefiles-ej-make-incremental
Describí el criterio físico que utiliza la herramienta `make` para decidir si es
necesario reconstruir un archivo objeto (por ejemplo, `funciones.o`) a partir de
su archivo fuente `funciones.c`.

:::
<!-- {exercise} -->

:::{solution} 2_makefiles-ej-make-incremental
:class: dropdown
`make` examina las **marcas de tiempo de modificación (timestamps)** de los
archivos en el disco físico.

Si la fecha de última modificación del archivo de entrada (`funciones.c` o
alguna de sus cabeceras declaradas como dependencias, ej: `funciones.h`) es
**más reciente** que la fecha de última modificación del archivo objeto de
salida (`funciones.o`), `make` deduce que el código fuente cambió y ejecuta la
receta de compilación para reconstruir el objeto. Si el objeto es más nuevo que
sus dependencias, `make` omite su compilación.

:::
<!-- {solution} 2_makefiles-ej-make-incremental -->

:::{exercise}
:label: 2_makefiles-ej-make-clean-phony
Explicá detalladamente para qué sirve la regla `.PHONY: clean` en un Makefile y
qué problema se produciría si se omitiera esta declaración y existiera en el
directorio un archivo físico llamado `clean`.

:::
<!-- {exercise} -->

:::{solution} 2_makefiles-ej-make-clean-phony
:class: dropdown
La directiva `.PHONY` le indica a `make` que el objetivo indicado no corresponde
a un archivo real que deba ser generado.

Si se omitiera `.PHONY: clean` y en el mismo directorio existiera un archivo
llamado `clean`, al ejecutar `make clean`, la herramienta buscaría dependencias
para el objetivo `clean`. Al no tener dependencias y ver que el archivo `clean`
ya existe físicamente en el disco, `make` reportaría que el objetivo está
actualizado (`make: 'clean' is up to date`) y se negaría a ejecutar el bloque de
comandos para limpiar el proyecto.

:::
<!-- {solution} 2_makefiles-ej-make-clean-phony -->

:::{exercise}
:label: 2_makefiles-ej-make-escritura
Escribí una regla de Makefile para compilar el archivo objeto `usuario.o` a
partir de sus dependencias `usuario.c` y `usuario.h`. Utilizá variables para el
compilador (`$(CC)`) y banderas (`$(CFLAGS)`), recordando el requisito de
indentación de Makefiles.

:::
<!-- {exercise} -->

:::{solution} 2_makefiles-ej-make-escritura
:class: dropdown
``` makefile
usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c -o usuario.o
```
<!-- makefile -->
*Nota: La línea de comandos de la receta debe estar precedida obligatoriamente
por un carácter de tabulación (Tab) en el archivo físico.*

:::
<!-- {solution} 2_makefiles-ej-make-escritura -->


## Glosario

:::{glossary}

Grafo de dependencias
: Estructura dirigida que representa las relaciones entre los archivos fuente y
los archivos generados.

Compilación incremental
: Técnica de optimización que solo recompila los archivos modificados desde la
última construcción.

Regla (.PHONY)
: Objetivo especial en un Makefile que no representa un archivo real y se
ejecuta de forma incondicional.

:::
<!-- {glossary} -->


## Síntesis y Resumen

La herramienta `make` automatiza la compilación incremental leyendo un
`Makefile`. Este archivo define un grafo de dependencias entre objetivos
(archivos a generar), prerrequisitos (archivos de entrada) y recetas (comandos
de compilación). Al comparar las marcas de tiempo físicas, `make` evita la
recompilación innecesaria de módulos sin cambios. Se utilizan objetivos
ficticios (`.PHONY`) para definir tareas que no producen archivos reales en
disco.


## Referencias y Lecturas Complementarias

- {cite:t}`mecklenburg_managing_2004`. Guía práctica de Makefiles complejos.
- **Makefile Tutorial** - https://makefiletutorial.com/
