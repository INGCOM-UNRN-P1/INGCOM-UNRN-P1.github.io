---
title: `Makefiles`
short_title: `make`
subtitle: Estructurando a proyectos
---

## El receterio de cocina

Siendo que `make` se usa para _literalmente_ hornear nuestros programas, este
apunte está construido de forma que nos ayude a construir `Makefiles` razonables
para automatizar la compilación de programas más grandes que un "`Hola Mundo`"
;-).

Mucha de la funcionalidad avanzada está puesta como una receta, de forma que
podamos leer de que se trata cuando tengamos que ver que pasa con algún makefile
ya hecho.

En particular porque el manual es _colosal_
[Manual GNU/Make](https://www.gnu.org/software/make/manual/html_node/index.html)

Traducido y adaptado del [Tutorial de Makefile](https://makefiletutorial.com/)
escrito por [Chase Lambert](https://github.com/chaselambda/) en
[chaselambda/makefiletutorial](https://github.com/chaselambda/makefiletutorial)

## El ciclo de un programa en C

Lo que conocemos como la compilación de un programa C, es una de las cuatro
etapas que pasa un programa para ser ejecutable. Actualmente, el compilador se
encarga de todas las etapas que le sea posible. En especial cuando se trate

## Primeros pasos

### ¿Por qué existen los `Makefiles`?

Los `Makefiles` existen por la misma razón que los scripts de Bash, la
automatización. Solo que en este caso, la herramienta está dedicada a la
construcción y ensamblado de cualquier cosa que requiera de múltiples pasos _y
configuración_. Se usa generalmente para programas compilados y enlazados, pero
se puede utilizar para cualquier cosa que podamos llamar desde la consola, como
por ejemplo, la creación del archivo PDF de este apunte.

Hemos hablado antes de que los programas son como recetas de cocina, pero los
`Makefiles` son literalmente las recetas para hornear nuestro programa. Contiene
las instrucciones para transformar el código en un programa. Esta herramienta
viene con un agregado para acelerar la cocción, el trabajo únicamente será hecho
en aquellos archivos que tengan cambios exclusivamente.

Esta herramienta tiene muchos años ya
([1979](https://doi.org/10.1002%2Fspe.4380090402)) y fue creada para que la
construcción de programas complejos no demore mucho tiempo. En los ejemplos y
trabajos de la cátedra, el proceso es instantáneo, pero pensando en proyectos
grandes, como el [kernel de Linux](https://github.com/torvalds/linux), el
proceso de compilación demorar tanto que se lo utiliza como
[medida de](https://openbenchmarking.org/test/pts/build-linux-kernel&eval=095284d5c95ecf2ec79cabe9e4c51a295825423f#metrics)[la capacidad de cómputo](https://openbenchmarking.org/test/pts/build-linux-kernel&eval=095284d5c95ecf2ec79cabe9e4c51a295825423f#metrics)[^1]
de una computadora.

### ¿Hay alternativas a `make`?

No solo existen alternativas directas, SCons, CMake, Bazel y Ninja, por nombrar
los más populares, algunos entornos de desarrollo como Microsoft Visual Studio
tienen sus propias herramientas de compilación. Por otro lado, para el lenguaje
de programación Java están las herramientas Ant, Maven y Gradle. Y otros
lenguajes como Go y Rust tienen sus propias herramientas de compilación.

Los lenguajes interpretados como Python, Ruby y Javascript no requieren un
análogo a `Makefiles`, cuando sus archivos de programa cambian, no es necesario
compilar nada, simplemente se ejecuta directamente la versión más reciente del
archivo (podemos decir que la tarea de `make` ya está integrada en el lenguaje).

### Las versiones y tipos de `make`

Hay una variedad de implementaciones de `make`, en especial si tenemos en cuenta
que tiene 43 años de vida. Este apunte funcionará en cualquier versión que estés
usando, ya que apuntaremos al mínimo común denominador de funcionalidad. Sin
embargo, está escrita específicamente para
[GNU `make`](https://www.gnu.org/software/`make`/), que es la estándar en Linux,
MacOS y las herramientas que utilizaremos en Windows. Todos los ejemplos
funcionan para las versiones 3 y 4 de `make`, que son _casi_ equivalentes salvo
algunas diferencias esotéricas que no vamos a ver.

### Instalación

No es necesario instalar _específicamente_ `make`, este ya viene como parte del
kit de herramientas del compilador, por lo que refiéranse a la guía de
instalación especifica antes de seguir con este apunte.

Pero pueden verificar que está todo en orden ejecutando.

```text
$> make
```

Debieran ver...

```text
`make`: *** No targets specified and no makefile found.  Stop.
```

Que indica que la herramienta está lista para ser configurada.

### Ejecución de los ejemplos

Para cada ejemplo, pon el contenido en un archivo llamado _Makefile_, y en ese
directorio ejecuta el comando `make`. Comencemos con el "Hola Mundo" de los
_`Makefiles`_:

```makefile
hola:
	echo "hola mundo"
```

:::{attention} Indentación

Los _Makefiles_ deben ser indentados con tabulaciones ya que si usamos espacios,
fallará.

:::

Aquí está la salida de la ejecución del ejemplo anterior:

```text
$> make
echo "hola mundo"
hola mundo
```

Este es un ejemplo simple, pero como ves, es simplemente una forma de llamar a
otros programas, en donde veremos como salida, el comando ejecutado y luego la
salida del mismo.

### Sintaxis del _Makefile_

Un _Makefile_ consiste en un conjunto de reglas. Una regla generalmente tiene el
siguiente aspecto:

```makefile
objetivo: prerequisitos
	comando
	comando
	comando
```

- Los objetivos es el nombre del archivo generado por los comandos en la regla.
  Aunque, lo más común es que cada regla contenga un único archivo como
  objetivo, es posible que sea una lista, la cual estará separada por espacios.

- Los comandos son la serie de programas que se utilizan para construir el
  objetivo. Deben comenzar con un carácter de **tabulación** `\t`, no con
  espacios.

- Los prerrequisitos son también nombres de archivos, separados por espacios.
  Estos son los archivos que deben existir antes que el objetivo, estos son los
  archivos de los cuales depende el objetivo, por lo que también se los
  denominan dependencias.

Nos podemos imaginar que el objetivo es cualquier paso intermedio y final en una
receta de cocina, los comandos como las operaciones individuales en la receta y
los prerrequisitos como todo aquello que sea posible hacer por separado, del que
dependa alguno de los pasos. Por ejemplo, cocinar unas galletitas para hornear.

```makefile
bandeja_galletitas_crudas: bandeja_en_mantecada masa_preparada
	hacer_galletitas bandeja masa --en=bandeja_galletitas_crudas
bandeja_galletitas: bandeja_galletitas_crudas
	hornear 20min 250C bandeja_galletitas_crudas
```

De este ejemplo podemos extraer un detalle interesante, ¿en qué se diferencia
una receta de este tipo de una en la que todos los pasos son una secuencia
completa?

Esta herramienta simplifica la forma de dividir las tareas, dedicándose a la
coordinación en la construcción de las piezas y su ensamblado final.

Pero al igual que la compilación de un programa, si es de un solo archivo, o un
solo paso; mucho sentido no tiene armar un Makefile si podemos llamar
directamente la herramienta que hace el trabajo, como venimos utilizando `gcc`
hasta ahora, concretamente.

### Un ejemplo simple

El siguiente _Makefile_ tiene tres reglas separadas. Cuando ejecute _make blah_
en la terminal, construirá un programa llamado `blah` en una serie de pasos:

- A `make` se le da `blah` como objetivo, por lo que primero busca este objetivo
- `blah` requiere `blah.o`, así que `make` busca el objetivo `blah.o`
- `blah.o` requiere `blah.c`, así que `make` busca el objetivo `blah.c`
- `blah.c` no tiene dependencias, así que se ejecuta el comando `echo`
- Entonces se ejecuta el comando `gcc -c`, porque todas las dependencias de
  `blah.o` están listas
- Se ejecuta el comando `gcc` de arriba, porque todas las dependencias de `blah`
  están listas
- Eso es todo: `blah` es un programa C compilado

```makefile
blah: blah.o
	cc blah.o -o blah # Tercero
blah.o: blah.c
	cc -c blah.c -o blah.o # Segundo
blah.c:
	echo "int main() { return 0; }" > blah.c # Primero
```

### Objetivo 'implícito'

El siguiente `makefile` tiene un único objetivo, llamado `some_file`. El
objetivo por defecto es el primer objetivo, por lo que en este caso `some_file`
se ejecutará.

```makefile
some_file:
	echo "Esta línea siempre imprime"
```

Como `make` no "ve" el archivo `some_file`, el objetivo no es alcanzado y `make`
seguirá ejecutando sus comandos.

### ¿Qué pasa cuando lo ejecutamos dos veces?

En el siguiente ejemplo, al ejecutar ` make some_file` por segunda vez, veremos
algo como `make: 'some_file' is up to date.`. Esto pasa porque `some_file` es
creado dentro del objetivo, y como se llega al objetivo, no es necesario volver
a modificarlo.

Esta es una de las características más importantes de la herramienta, si la
"dependencia" no cambió, entonces, no es necesario volver a completar el paso.

:::{tip} Recompilación

`make` verifica que la fecha (y hora) de modificación del archivo dependiente
sea la misma que la de salida, por lo que si utilizamos el comando `touch`, que
la modifica al momento en el que lo ejecutamos, podemos volver a completar el
paso sin que se haya modificado realmente el archivo.

:::

### Dependencias

Aquí, el objetivo `some_file` "depende" de `other_file`. Cuando ejecutamos
`make`, el objetivo por defecto (`some_file`, ya que es el primero) será
llamado. Primero mirará su lista de dependencias, y si alguna de ellas es más
antigua, primero ejecutará los objetivos de esas dependencias, y luego se
ejecutará a sí mismo. La segunda vez que se ejecute, ningún objetivo se
ejecutará porque ambos objetivos existen.

```makefile
some_file: other_file
	echo "Esto va después, porque depende de other_file"
	touch some_file

other_file:
	echo "Esto va primero"
	touch other_file
```

La noción de dependencia es importante, en el siguiente Makefile, ambos
objetivos se ejecutarán, ya que la dependencia de `some_file` con respecto de
`other_file` nunca es satisfecha, ya que el archivo no es creado.

```makefile
some_file: other_file
	touch some_file

other_file:
	echo "Tipo nada"
```

### Empezando de cero con `clean`

El objetivo `clean` es uno muy común y se utiliza para limpiar las salidas de
los objetivos, esto es usado para "empezar de cero". Este objetivo no lleva un
nombre especial o reservado, y lo podríamos llamar "limpiar", pero es mejor
apegarnos al nombre en inglés para mantener consistencia.

```makefile
some_file:
	touch some_file

clean:
	rm -f some_file`
```

### Variables

Las variables solo pueden contener texto. Lo más común es utilizar `:=`, pero
`=` también funciona.

<!-- TODO: TRANSFORMAR A REFERENCIA MD -->

Hay más sobre este tema por acá [variables parte 2](#7.Variables parte
2|outline).

Acá tenés un ejemplo con variables:

```makefile
files := file1 file2
some_file: $(files)
	echo "Mirá a esta variable!: " $(files)
	touch some_file

file1:
	touch file1
file2:
	touch file2

clean:
	rm -f file1 file2 some_file
```

Podes referenciar las variables con `${}` o `$()`

```makefile
x := coso

all:
	echo $(x)
	echo ${x}
```

Demás está decir que es muy recomendable usar nombres razonables para las
variables

## Objetivos

### El objetivo `all`

¿Estás construyendo múltiples objetivos sin dependencias entre sí y deseas
ejecutarlos todos?

Es muy recomendable agregar al principio a este objetivo. Ya que de esta forma,
será el llamado si no indicamos uno específico y de esta forma podemos compilar
_todo_ sin tener que indicarlo puntualmente cada vez.

```makefile

all: one two three

one:
	touch one
two:
	touch two
three:
	touch three

clean:
	rm -f one two three
```

### Objetivos múltiples

Cuando hay varios objetivos para una regla, los comandos se ejecutarán para cada
objetivo, para saber cuál se está procesando, podemos utilizar la variable
automática `$@` que contiene el nombre del objetivo.

```makefile
all: f1.o f2.o

f1.o f2.o:
	echo "ahora con" $@
# Equivalente a:
# f1.o:
#	echo f1.o
# f2.o:
#	echo f2.o
```

Es particularmente útil cuando tenemos que hacer lo mismo en varios archivos
diferentes, pero no es la única forma.

## Variables automáticas y comodines

### Comodín `*` (wildcard)

Tanto `*` como `%` se llaman comodines en `make`, pero significan cosas
totalmente diferentes. `*` busca en su sistema de archivos nombres de archivos
que coincidan. Es muy recomendable que siempre esté envuelto en la función
`wildcard`, porque de lo contrario podés caer en una trampa común que se
describe un poco más abajo.

```makefile
# Imprime información de cada archivo .c
print: $(wildcard *.c)
	ls -la  $?
```

El comodín `*` puede ser utilizado en el objetivo, prerrequisitos o en la
función `wildcard`.

Pero, no es posible usarlo directamente en la creación de variables, y cuando no
hay coincidencias, es dejado como está, a no ser que sea utilizado dentro de la
función `wildcard`.

```{code}makefile
:caption: Trampa con el comodín

thing_wrong := *.o # No lo hagas. '*' no se expandirá
thing_right := $(wildcard *.o)

all: one two three four

# Falla, porque $(thing_wrong) es la cadena "*.o"
one: $(thing_wrong)

# Se queda como *.o si no hay archivos que coincidan con este patrón :(
two: *.o

# Funciona como cabría esperar. En este caso, no hace nada.
three: $(thing_right)

# Igual que la regla three
four: $(wildcard *.o)
```

### El comodín `%`

El _otro_ comodín, es realmente útil, pero es algo confuso debido a la variedad
de situaciones en las que se puede utilizar.

- Cuando se utiliza en modo "coincidente", coincide con uno o más caracteres de
  una cadena. Esta coincidencia se denomina tronco[^2].
- Cuando se usa en modo "reemplazo", toma la raíz que se ha comparado y la
  reemplaza en una cadena.
- `%` se utiliza sobre todo en las definiciones de reglas y en algunas funciones
  específicas.

Consulte estas secciones para ver ejemplos de su uso:

<!-- integrar al apunte -->

- [Static Pattern Rules](https://makefiletutorial.com/#static-pattern-rules)
- [Pattern Rules](https://makefiletutorial.com/#pattern-rules)
- [String Substitution](https://makefiletutorial.com/#string-substitution)
- [The vpath Directive](https://makefiletutorial.com/#the-vpath-directive)

### Variables automáticas

Hay más
[variables](https://www.gnu.org/software/`make`/manual/html_node/Automatic-Variables.html)[s ](https://www.gnu.org/software/`make`/manual/html_node/Automatic-Variables.html)[automáticas](https://www.gnu.org/software/`make`/manual/html_node/Automatic-Variables.html),
pero estas son las más comunes:

```makefile
hey: one two
	# Da como resultado "hey", ya que este es el primer objetivo
	echo $@

	# Muestra a todos los prerrequisitos más nuevos que el objetivo
	echo $?

	# Muestra a todos los prerrequisitos
	echo $^

	touch hey

one:
	touch one

two:
	touch two

clean:
	rm -f hey one two
```

## Fancy Rules

### Reglas implícitas

A `make` le encanta la compilación de C. Y cada vez que expresa su amor, las
cosas se vuelven confusas, y quizás lo más enrevesado de la herramienta son las
reglas mágicas/automáticas.

`make` llama a estas reglas "implícitas". Personalmente no estoy de acuerdo con
esta decisión de diseño, y no recomiendo usarlas, pero se usan seguido y por lo
tanto, es importante conocerlas. Aquí hay una lista de reglas implícitas:

- Compilación de un programa C: `n.o` que es construido a partir de `n.c` con un
  comando que sigue la forma: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
- Compilación de un programa C++: `n.o` es construido a partir de `n.cc` o
  `n.cpp` con un comando que sigue la forma: `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)`
- Enlace de un archivo objeto único: el archivo `n` es construido
  automáticamente a partir de `n.o` ejecutando el comando
  `$(CC) $(LDFLAGS) n.o $(LDLIBS)`

Las variables importantes que utilizan las reglas implícitas son:

- `CC`: Compilador de C, por defecto `cc`
- `CXX`: Compilador para C++, por defecto `g++`
- `CFLAGS`: Opciones adicionales para el compilador de C
- `CXXFLAGS`: Opciones adicionales para el compilador de C++
- `CPPFLAGS`: Opciones adicionales para el preprocesador de C
- `LDFLAGS`: Opciones adicionales para el enlazador.

Veamos cómo podemos ahora construir un programa en C sin tener que decirle
explícitamente a `make` cómo hacer la compilación:

```makefile
CC = gcc    # Utilizamos gcc como compilador
CFLAGS = -g # Activar la información de depuración

# #1: blah se construye a través de la regla implícita del enlazador de C
# #2: blah.o se construye a través de la regla implícita de compilación de C,
#     porque blah.c existe

blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah*
```

### Patrones de reglas estáticas

Las reglas de patrones estáticos son otra forma de escribir menos en un
Makefile, pero yo diría que son más útiles y un poco menos "mágicas". Esta es su
sintaxis:

```makefile
objetivos...: patron-objetivo: patrones-prereq ...
	comandos
```

La esencia es que el `objetivo` dado coincide con el `patrón-objetivo` (a través
de un comodín `%`). Lo que se ha encontrado se denomina "tronco", este se
sustituye por `patrones-prereq`, para generar los prerrequisitos del objetivo.

Un caso de uso típico es compilar archivos `.c` en archivos `.o`. Esta es la
forma manual:

```makefile
objects = foo.o bar.o all.o
all: $(objects)

# Estos archivos se compilan mediante reglas implícitas
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```

Esta es la forma más eficiente, utilizando una regla de patrón estático:

```makefile
objects = foo.o bar.o all.o
all: $(objects)

# Estos archivos son compilados por las reglas implicitas
# Sintaxis - targets ...: target-patterns: prereq-patterns ...
# En el caso del primer objetivo, foo.o, el patrón-objetivo coincide
#  con foo.o y establece que la "raíz" sea "foo".
# A continuación, sustituye el "%" de patrones-prereq por esa raíz

$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```

### Reglas y filtro de patrones estáticos

Si bien las funciones son introducidas más adelante, adelantaré lo que se puede
hacer con ellas. La función `filter` se puede utilizar en las reglas de patrones
estáticos para hacer coincidir los archivos correctos. En este ejemplo, hice las
extensiones `.raw` y `.result`.

```makefile
obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

.PHONY: all
all: $(obj_files)

$(filter %.o,$(obj_files)): %.o: %.c
	echo "target: $@ prereq: $<"
$(filter %.result,$(obj_files)): %.result: %.raw
	echo "target: $@ prereq: $<"

%.c %.raw:
	touch $@

clean:
	rm -f $(src_files)
```

### Reglas de los patrones

Las reglas de los patrones se utilizan a menudo, pero son bastante confusas.
Puedes verlas de dos maneras:

- Una forma de definir sus propias reglas implícitas
- Una forma más simple de reglas de patrones estáticos

Empecemos con un ejemplo:

```makefile
# Definir una regla de patrón que compile cada archivo .c en un archivo .o
%.o : %.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
```

Las reglas de patrones contienen un '`%`' en el objetivo. Este '`%`' coincide
con cualquier cadena no vacía, y los demás caracteres coinciden por sí mismos.
El '`%`' en un prerrequisito de una regla de patrón representa el mismo tronco
que fue igualado por el '`%`' en el objetivo.

Aquí hay otro ejemplo:

```makefile
# Definir una regla de patrón que no tenga ningún
#   patrón en los prerrequisitos.
# Esto sólo crea archivos .c vacíos cuando es necesario.
%.c:
   touch $@
```

### Reglas de dos puntos

Las Reglas de dos puntos se utilizan raramente, pero permiten definir múltiples
reglas para el mismo objetivo. Si fueran dos puntos simples, se imprimiría una
advertencia y solo se ejecutaría el segundo conjunto de comandos.

```makefile
all: blah

blah::
	echo "Hola!"

blah::
	echo "Hola denuevo!"
```

## Comandos y ejecución

### Eco de comandos/Silencio

Añade una _@_ antes de un comando para evitar que se imprima. También puedes
ejecutar `make` con _-s_ para añadir una _@_ antes de cada línea

```makefile
all:
	@echo "Esto no va a aparecer en la salida"
	echo "Pero eso si!"
```

### Ejecución de comandos

Cada comando se ejecuta en un nuevo shell (o al menos el efecto es como tal)

```makefile
all:
	cd ..
	# El cd anterior no afecta a esta línea,
		porque cada comando se ejecuta efectivamente en un nuevo shell
	echo `pwd`

	# Este comando cd afecta al siguiente porque están en la misma línea
	cd ..;echo `pwd`

	# Igual que antes, pero con la barra para dividir la linea en dos
	cd ..; \
	echo `pwd`
```

### Shell por defecto

El shell por defecto es `/bin/sh`. Es posible cambiar esto modificando la
variable `SHELL`:

```makefile
SHELL=/bin/bash

cool:
	echo "Hola desde bash"
```

### Gestión de errores con `-k`, `-i`, y `-`

Añadí `-k` cuando ejecutes `make` para que siga funcionando incluso ante
errores. Útil si querés ver todos los errores de `make` a la vez.
(`--keep-going`)

Agregá un `-` antes de un comando para suprimir el error

Y con `-i` al llamar a `make` para que esto pase con cada comando.
(`--ignore-errors`)

```makefile
one:
	# Este error se imprimirá pero se ignorará, make continuará ejecutándose
	-false
	touch one
```

### Uso recursivo de `make`

Para llamar recursivamente a un `makefile`, usá el especial `$(make)` en lugar
de `make`, ya que pasará las opciones de la llamada original de `make` por usted
y no se verá afectado por ellas.

```makefile
new_contents = "hello:\n\ttouch a inside_file"
all:
	mkdir -p subdir
	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
	cd subdir && $(MAKE)

clean:
	rm -rf subdir
```

### Usar export para un `make` recursivo

La directiva `export` toma una variable y la hace accesible a los comandos
sub-`make`. En este ejemplo, cooly se exporta de tal manera que el `makefile` en
el subdirectorio puede usarlo.

Nota: _export_ tiene la misma sintaxis que en la terminal de la consola (`sh`,
`bash`), pero no están relacionados (aunque son similares en su función)

```makefile
new_contents = "hello:\n\\techo \$$(cooly)"

all:
	mkdir -p subdir
	echo $(new_contents) | sed -e 's/^ //' > subdir/makefile
	@echo "---MAKEFILE CONTENTS---"
	@cd subdir && cat makefile
	@echo "---END MAKEFILE CONTENTS---"
	cd subdir && $(MAKE)

# Tenga en cuenta que las variables y las exportaciones.
#	Se establecen/afectan globalmente.
cooly = "¡El subdirectorio puede verme!"
export cooly
# Esto anularía la línea anterior: unexport cooly

clean:
	rm -rf subdir
```

Es necesario exportar las variables para que se ejecuten también en el shell.

```makefile
one=esto sólo funcionará localmente
export two=podemos ejecutar subcomandos con esto

all:
	@echo $(one)
	@echo $$one
	@echo $(two)
	@echo $$two
```

Mientras que `.EXPORT_ALL_VARIABLES` lo hace por tí, para todas las variables.

```makefile
.EXPORT_ALL_VARIABLES:
new_contents = "hello:\n\techo \$$(cooly)"

cooly = "¡El subdirectorio puede verme!"
# Esto anularía la línea anterior: unexport cooly

all:
	mkdir -p subdir
	echo $(new_contents) | sed -e 's/^ //' > subdir/makefile
	@echo "---MAKEFILE CONTENTS---"
	@cd subdir && cat makefile
	@echo "---END MAKEFILE CONTENTS---"
	cd subdir && $(MAKE)

clean:
	rm -rf subdir
```

### Argumentos a `make`

De la muy bonita lista en el manual
[lista de opciones](http://www.gnu.org/software/`make`/manual/`make`.html#Options-Summary),
peguenlé una mirada a `--dry-run`, `--touch` y `--old-file`. Además de ver en
detalle que hace `-i` y `-k`.

El otro tipo de argumentos son los objetivos a ejecutar, y podemos ejecutar
varios y en orden, solo tenemos que indicarlos uno a continuación de otro.

Por ejemplo:

```text
$> make clean run test
```

Que limpia los archivos generados previamente (`clean`), compila y ejecuta el
programa (`run`) y finalmente corre los `test`'s.

## Variables parte 2

### Sabores y modificaciones

Hay dos sabores de variables

- Recursivo (usá `=`) - sólo construye el valor de la variable cuando se utiliza
  el comando, no cuando se define.
- Expansión simple (usa `:=`) - como en programación normal, las variables toman
  su valor cuando son definidas, sin expansión

```makefile
# Variable recursiva. Esto imprimirá "tardio" a continuación
uno = uno ${later_variable}
# Variable simplemente expandida. Esto no imprimirá "tardio" abajo
dos := dos ${later_variable}

later_variable = tardio

all:
	echo $(uno)
	echo $(dos)
```

La expansión simple (utilizando `:=`) permite añadir a una variable. Las
definiciones recursivas darán un error de bucle infinito.

```makefile
uno = hola
uno ?= no será asignado
dos ?= será asignado

all:
	echo $(uno)
	echo $(dos)
```

Los espacios al final de una línea no se eliminan, pero sí los del principio.
Para crear una variable con un solo espacio, utilice `$(nullstring)`

```makefile
con_espacios = alo   # con_espacios tiene 3 espacios luego de "alo"
after = $(con_espacios)there

nullstring =
space = $(nullstring) # Hace una variable con un solo espacio.

all:
	echo "$(after)"
	echo inicio"$(space)"fin
```

Una variable indefinida es en realidad una cadena vacía, por lo que emplear una
variable desconocida no producirá un error.

```makefile
all:
	# Las variables no definidas son sólo cadenas vacías!
	echo $(nowhere)
```

Y podes usar `+=` para concatenar.

```makefile
foo := start
foo += more

all:
	echo $(foo)
```

La substitución de cadenas es una forma muy útil para modificar el contenido de
las variables. Para más información, consulten las páginas del manual
[Text Functions](https://www.gnu.org/software/`make`/manual/html_node/Text-Functions.html#Text-Functions)
y
[Filename Functions](https://www.gnu.org/software/`make`/manual/html_node/File-Name-Functions.html#File-Name-Functions)
de GNU/`make`.

### Argumentos de linea de comandos y anulaciones

Puedes anular las variables que provienen de la línea de comandos utilizando
`override`. Aquí ejecutamos `make` con `make option_one=hi`

```makefile
# Supera los argumentos de la línea de comandos
override option_one = did_override
# No anula los argumentos de la línea de comandos
option_two = not_override
all:
	echo $(option_one)
	echo $(option_two)
```

Puesto de otra manera, no importa lo que venga de afuera, el valor siempre va a
ser el que este definido internamente.

### Lista de comandos y definición

"`define`" es en realidad sólo una lista de comandos. No tiene nada que ver con
ser una función. Tené en cuenta aquí que es un poco diferente a tener un punto y
coma entre los comandos, porque cada uno se ejecuta en un shell separado, como
se espera.

```makefile
one = export blah="Estaba definida!"; echo $$blah

define two
export blah=set
echo $$blah
endef

# One y two son diferentes.

all:
	@echo "Esto muestra 'Estaba definida!'"
	@$(one)
	@echo "Esto no muestra 'Estaba definida!', ya que cada comando se ejecuta en un shell separado."
	@$(two)
```

### Variables específicas de los objetivos

Las variables pueden ser asignadas para objetivos específicos:

```makefile
all: uno = copado

all:
	echo uno esta definida: $(uno)

other:
	echo uno esta definida: $(uno)
```

### Variables específicas a patrones

Así como podemos definir variables para objetivos específicos, podemos también
asignarlas a patrones.

```makefile
%.c: one = buenardo

blah.c:
	echo uno esta definida: $(one)

other:
	echo uno esta definida: $(one)
```

## La parte condicional de los `Makefiles`

### Un `if`/`else` clásico

```makefile
foo = ok

all:
ifeq ($(foo), ok)
	echo "foo vale ok"
else
	echo "nope"
endif
```

### []{#anchor-13}Verificar si una variable esta vacía

```makefile
nullstring =
foo = $(nullstring) # fin de linea; noten que hay un espacio acá

all:
ifeq ($(strip $(foo)),)
	echo "foo está vacío después de ser limpiada"
endif
ifeq ($(nullstring),)
	echo "nullstring ni siquiera tiene espacios"
endif
```

### Verificar si una variable está definida

`ifdef` no expande las referencias a variables, solo se encarga de verificar que
existen.

```makefile
bar =
foo = $(bar)

all:
ifdef foo
	echo "foo esta definida"
endif
ifndef bar
	echo "pero bar no lo esta"
endif
```

### `$(makeflags)`

Este ejemplo muestra como verificar opciones (flags) con `findstring` y
`MAKEFLAGS`. Estos son útiles para indicar alguna variación en lo que se desea
construir.

Para el siguiente ejemplo, utilizá `-i` para ver el texto en el `echo`.

```makefile
bar =
foo = $(bar)

all:
# Buscando por la opción "-i". MAKEFLAGS es solo una lista de caracteres
# Y en estes caso, busca por "i"
ifneq (,$(findstring i, $(MAKEFLAGS)))
	echo "la opcion i fue agregada a MAKEFLAGS"
endif
```

## Funciones

### Primeras funciones

Las funciones son principalmente para procesamiento de texto, después de todo,
la idea de esta herramienta es llamar a otras. Estas se llaman con la siguiente
sintaxis:

_\$(fn, argumentos)_ o _\${fn, argumentos}_.

Podes hacer `make` propio utilizando
[call](https://www.gnu.org/software/`make`/manual/html_node/Call-Function.html#Call-Function)
para llamar funciones 'de libreria'. Y `make` tiene una cantidad interesante de
[funciones integradas](https://www.gnu.org/software/`make`/manual/html_node/Functions.html).

### Substituciones textuales (`subst`)

```makefile
bar := ${subst no, absolutamentoe, "Yo no soy Paturuzu"}
all:
	@echo $(bar)
```

Si querés reemplazar espacio o comas, usá variables:

```makefile
comma := ,
empty:=
space := $(empty) $(empty)
foo := a b c
bar := $(subst $(space),$(comma),$(foo))

all:
	@echo $(bar)
```

No incluyas espacios en los argumentos antes del primero, esto será visto como
parte de la cadena.

```makefile
comma := ,
empty:=
space := $(empty) $(empty)
foo := a b c
bar := $(subst $(space), $(comma) , $(foo))

all:
	# La salida es is ", a , b , c". Mirá los espacios que se introdujeron
	@echo $(bar)
```

### Substituciones usando patrones (`patsubst`)

`$(patsubst patron,reemplazo,texto)` does the following:

Según el manual:

> "Busca palabras separadas por espacios en blanco en el texto que coinciden con
> el patrón y las reemplaza con el 'reemplazo' indicado. Aquí, el patrón puede
> contener un "`%`", que actúa como comodón y coincide con cualquier número de
> caracteres dentro de una palabra. Si el reemplazo también contiene un "`%`",
> este se reemplaza por el texto que coincidió con el "`%`" en el patrón. Solo
> el primero "`%`" en el patrón y el reemplazo se trata de esta manera;
> cualquier "`%`" posterior no se modifica.

([GNU docs](https://www.gnu.org/software/`make`/manual/html_node/Text-Functions.html#Text-Functions))

La referencia de substitución `$(texto:patron=reemplazo)` es un atajo para esto.

Existe otra abreviación que solo reemplaza sufijos, `$(texto:sufijo=reemplazo)`.
No es necesario el comodín "`%`".

:::{note}Cuidado con los espacios No agregues espacios para este atajo, ya que
será interpretado como una búsqueda o término de reemplazo. :::

```makefile
foo := a.o b.o l.a c.o
one := $(patsubst %.o,%.c,$(foo))
# Esto es un atajo para lo de arriba
two := $(foo:%.o=%.c)
# Este es el atajo con la forma de sufijos y que, ademas, es equivalente a lo anterior.
three := $(foo:.o=.c)

all:
	echo $(one)
	echo $(two)
	echo $(three)
```

### La función `foreach`

La función `foreach` se ve así: `$(foreach var,list,texto)` y se encarga de
convertir una lista de palabras separadas por espacios en otra. `var` se asigna
a cada palabra de la lista y texto se expande para cada palabra.

El siguiente ejemplo agrega una exclamación `!` a cada palabra.

```makefile
foo := quien so vo
# para cada 'palabra' en 'foo', mostrá esa palabra con una exclamación a continuación.
bar := $(foreach palabra,$(foo),$(palabra)!)

all:
	# Output is "who! are! you!"
	@echo $(bar)
```

### La función `if`

`if` verifica si el primer argumento tiene algo (no vacío), entonces, devuelve
el segundo y sino, devuelve el tercero.

```makefile
foo := $(if no-vacio,entonces!,sino!)
empty :=
bar := $(if $(empty),entonces!,sino!)

all:
	@echo $(foo)
	@echo $(bar)
```

### La función `call`

`make` soporta crear funciones básicas, estas se definen crea una variable, pero
se usan los parámetros `$(0)`, `$(1)`, `$(2)`, etc. Al momento de llamarla se
hace con la función especial `call`.

Son más parecidas a plantillas de texto que a _verdaderas_ funciones.

La sintaxis de un llamado a función es el siguiente,
`$(call variable_funcion,parametro,parametro)`

```makefile
mi_super_funcion = Nombre funcion: $(0) primer arg: $(1) segundo arg: $(2) variable vacia: $(3)

all:
	# Outputs "Variable Name: mi_super_funcion First: go Second: tigers Empty Variable:"
    # muestra "Nombre funcion: mi_super_funcion primer arg: vamo segundo arg: bokee variable vacia:"
	@echo $(call mi_super_funcion, vamo, bokee)
```

Los argumentos no indicados no hacen fallar a la función, simplemente quedan
vacíos.

### La función `shell`

Esta llama a un programa en la consola reemplazando los saltos de línea con
espacios.

```makefile
all:
	@echo $(shell ls -la) # Horrendo porque los saltos de línea se van, pero funciona!
```

## Otras características

### Incluir otros `Makefiles`

Esta directiva le indica a `make` que debe tomar objetivos de otro `Makefile` en
una instrucción que tiene la forma `include nombremakefile`.

Esto es particularmente útil cuando tenés opciones de compilación como `-M` que
crean `Makefiles` en función del código fuente. Por ejemplo, si algún archivo
`.c` incluye un header, ese será agregado a un `Makefile` que es escrito por
`gcc`. Hay un ejemplo de esto en el recetario más abajo.

### La directiva `vpath`

Esta se utiliza para indicar en donde encontrar algún conjunto de
prerrequisitos. Su formato es

```makefile
vpath <patrón> <directorios, separados por coma o espacios>
```

Puede tener una `%`, que significa que coincide a cero o más caracteres.

Esto se puede hacer de forma _un poco_ más global utilizando la variable `VPATH`

```makefile
vpath %.h ../headers ../otro-directorio

some_binary: ../headers blah.h
	touch un_binario

../headers:
	mkdir ../headers

blah.h:
	touch ../headers/blah.h

clean:
	rm -rf ../headers
	rm -f un_binario
```

### Saltos de línea

La barra invertida "`\`" nos da la posibilidad de dividir una línea cuando es
demasiado larga.

```makefile
some_file:
	echo esta linea es demasiado larga, por lo que \
		la dividimos en varias.
```

### `.phony`

Agregar `.PHONY` a un objetivo, prevendrá que `make` lo confunda con el nombre
de un archivo. En el siguiente ejemplo, si el archivo `clean` es creado,
`make clean` retendrá su objetivo de limpieza en lugar de intentar construir el
archivo con ese nombre.

`.PHONY` es fantástico para usarlo, pero no indispensable, ya que solo tenemos
que evitar crear archivos con el nombre de estos 'objetivos' especiales, como
`test`, `run`, `clean` y otros, por lo que lo saltearemos para mantener todo más
simple.

```makefile
some_file:
	touch un_archivo
	touch clean

.PHONY: clean
clean:
	rm -f un_archivo
	rm -f clean
```

### `.delete_on_error`

`make` detendrá la ejecución de una regla, y propagará hacia atrás a los
prerrequisitos cuando un comando retorna un valor distinto de cero, indicando
que ocurrió algún fallo.

Utilizá `.DELETE_ON_ERROR` en el objetivo `all`, de esta forma, todos los
objetivos no dejarán algo a mitad de cocinar por un error de las instrucciones
de cocina, incluyendo los dependientes.

Esto es importante de activar, ya que si tenemos un problema en las
herramientas, la salida en sí no tiene mucho sentido.

```makefile
.DELETE_ON_ERROR:
all: uno dos

one:
	touch uno
	false

two:
	touch dos
	false
```

[Más información](https://innolitics.com/articles/make-delete-on-error/)

## La receta de `Makefile`

Repasemos un ejemplo de `make` realmente jugoso que funciona bien para proyectos
de tamaño mediano.

Lo piola de este archivo `Makefile` es que determina automáticamente las
dependencias. Solo tienes que colocar tus archivos C/C++ en la carpeta `src/`.

```makefile
# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := final_program

BUILD_DIR := ./build
SRC_DIRS := ./src

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
#
# Encontramos todos los archivos de C y C++ que queremos compilar
# Observá las comillas simples en los comodines *, Make los expandira incorrectamente de otra forma.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
#
# Substitución en cada archivo encontrado, de forma que
# un archivo hello.cpp se transforme en ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
#
# Substitución de cadenas, (atajo de substitución sin la %)
# el archivo ./build/hello.cpp.o se transforma en ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
#
# Cada directorio en ./src debe ser pasado a GCC para que pueda encontrar los headers
INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
#
# Agregamos un prefijo a INC_DIRS, de forma que 'moduloA' se transforme en '-ImoduloA'
# la forma en la que gcc entiende la inclusión.
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
#
# Las opciones -MMD y -MP juntas, generan Makefiles para nosotros!
# Estos archivos tendran .d en lugar de .o como su salida
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# The final build step.
#
# El paso de compilación final, enlazado
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
#
# Paso de compilación de los fuentes C
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
#
# Paso de compilación de los fuentes C++
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
#
# Incluir los makefiles .d generados. El - al principio suprime los errores de
# Makefiles faltantes. Esto es importante ya que en la primera pasada, todos los
# .d no estaran generados
-include $(DEPS)

```

[^1]:
    A julio del 2022, el primer puesto lo tiene una computadora doble
    [AMD EPYC 7773X](https://openbenchmarking.org/s/2+x+AMD+EPYC+7773X+64-Core)
    de 64 núcleos, para hacer un total de ¡128 núcleos! Completando la tarea en
    138 segundos. Una computadora más mundana, suele llevar varias horas.

[^2]: NdT: stem
