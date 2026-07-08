title: Automatización de Compilación con Makefiles
short_title: 'Makefiles'
subtitle: 'Estructura de Makefiles, dependencias y compilación incremental en C'

(capitulo-makefiles-basico)=
## Introducción

A medida que los proyectos escritos en C crecen y se modularizan en múltiples archivos de cabecera (`.h`) y de implementación (`.c`), compilar el código manualmente invocando directamente al compilador en la terminal se vuelve ineficiente y propenso a errores.

Para automatizar este flujo, en el ecosistema Unix se emplea la herramienta **`make`**, la cual lee las reglas de construcción de un archivo de configuración denominado **`Makefile`**.


## Desarrollo

### 1. ¿Qué es un Makefile y la Compilación Incremental?

La utilidad `make` funciona modelando el proyecto como un **Grafo Dirigido Acíclico (DAG)**. En esta estructura formal, los nodos representan archivos físicos del sistema de archivos y las aristas dirigidas representan las relaciones de dependencia lógica entre ellos.

#### Compilación Incremental y Marcas de Tiempo

La principal ventaja de `make` es la **compilación incremental**. Al analizar las marcas de tiempo de modificación física (*timestamps*) de los archivos en el disco, la herramienta decide qué se debe reconstruir siguiendo una regla matemática simple:

$$
\text{Si } T(\text{Objetivo}) < T(\text{Dependencia}) \implies \text{Ejecutar receta de recompilación}
$$

Esto significa que:
1. `make` compara la fecha del archivo de salida (ej: un archivo objeto `.o`) con las fechas de sus archivos fuentes y cabeceras de entrada correspondientes.
2. Si ninguno de los archivos de entrada ha sido modificado desde la última compilación, `make` omite de forma inteligente la compilación de ese módulo.
3. Solo se recompilan los módulos modificados, lo que ahorra una cantidad significativa de tiempo de procesamiento en proyectos de mediana y gran escala.

```{figure} 2/dag_compilacion.svg
:label: fig-dag-compilacion
:align: center
:width: 85%

Representación como Grafo Dirigido Acíclico (DAG) de dependencias de compilación. Si `main.c` cambia, se invalida `main.o` y por ende se requiere volver a generar el ejecutable `programa`, pero se omite la recompilación de `comun.c`.
```

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


### 3. Evolución Gradual de un Makefile (Las 3 Fases)

Para evitar la sobrecarga cognitiva al introducir la sintaxis compleja de `make`, analizaremos cómo evoluciona un Makefile de forma incremental. Supongamos un proyecto con:
*   `calculadora.c` y `calculadora.h` (implementación de aritmética).
*   `main.c` (punto de entrada que utiliza la calculadora).

#### Fase 1: Makefiles Explícitos

En esta fase inicial, declaramos de forma rígida cada archivo y comando de compilación sin abstracciones. Cada regla llama directamente a `gcc`:

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

#### Fase 2: Introducción de Variables (CC y CFLAGS)

Para evitar repetir las banderas del compilador y permitir cambiar de compilador rápidamente (por ejemplo, a `clang`), introducimos variables (o macros de Makefile):

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

#### Fase 3: Reglas de Patrón y Variables Automáticas (Producción)

En proyectos reales con decenas de archivos, escribir una regla por cada `.c` es inviable. Para solucionar esto, la Fase 3 utiliza **reglas de patrón** (`%o: %c`) y **variables automáticas**:
*   `$@`: Representa el nombre del **Objetivo** actual de la regla.
*   `$<`: Representa la **primera dependencia** de la lista (normalmente el archivo fuente `.c`).
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


### 4. Objetivos Ficticios (`.PHONY`)

Los objetivos declarados bajo la directiva **`.PHONY`** son objetivos especiales que no representan archivos reales en el disco. Le indican a `make` que debe ejecutar la receta asociada de forma incondicional siempre que se invoque la regla, sin importar si existe un archivo físico con el mismo nombre en la carpeta.

```makefile
.PHONY: clean
clean:
	rm -f *.o programa
```


## Ejercicios de Autoevaluación

:::{exercise}
:label: 2_makefiles-ej-make-incremental
Describí el criterio físico que utiliza la herramienta `make` para decidir si es necesario reconstruir un archivo objeto (por ejemplo, `funciones.o`) a partir de su archivo fuente `funciones.c`.
:::

:::{solution} 2_makefiles-ej-make-incremental
:class: dropdown
`make` examina las **marcas de tiempo de modificación (timestamps)** de los archivos en el disco físico.

Si la fecha de última modificación del archivo de entrada (`funciones.c` o alguna de sus cabeceras declaradas como dependencias, ej: `funciones.h`) es **más reciente** que la fecha de última modificación del archivo objeto de salida (`funciones.o`), `make` deduce que el código fuente cambió y ejecuta la receta de compilación para reconstruir el objeto. Si el objeto es más nuevo que sus dependencias, `make` omite su compilación.
:::

:::{exercise}
:label: 2_makefiles-ej-make-clean-phony
Explicá detalladamente para qué sirve la regla `.PHONY: clean` en un Makefile y qué problema se produciría si se omitiera esta declaración y existiera en el directorio un archivo físico llamado `clean`.
:::

:::{solution} 2_makefiles-ej-make-clean-phony
:class: dropdown
La directiva `.PHONY` le indica a `make` que el objetivo indicado no corresponde a un archivo real que deba ser generado.

Si se omitiera `.PHONY: clean` y en el mismo directorio existiera un archivo llamado `clean`, al ejecutar `make clean`, la herramienta buscaría dependencias para el objetivo `clean`. Al no tener dependencias y ver que el archivo `clean` ya existe físicamente en el disco, `make` reportaría que el objetivo está actualizado (`make: 'clean' is up to date`) y se negaría a ejecutar el bloque de comandos para limpiar el proyecto.
:::

:::{exercise}
:label: 2_makefiles-ej-make-escritura
Escribí una regla de Makefile para compilar el archivo objeto `usuario.o` a partir de sus dependencias `usuario.c` y `usuario.h`. Utilizá variables para el compilador (`$(CC)`) y banderas (`$(CFLAGS)`), recordando el requisito de indentación de Makefiles.
:::

:::{solution} 2_makefiles-ej-make-escritura
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
