---
title: Introducción a la programación en C
short_title: 2 - C base
subtitle: La sintaxis y programas básicos.
---

## Introducción

Antes de iniciar el estudio de la programación en C, es fundamental comprender
que programar no consiste únicamente en aprender un lenguaje, sino en desarrollar
una forma de pensar. El lenguaje es la herramienta, pero el verdadero arte
reside en la construcción de instrucciones lógicas para resolver problemas.

Programar es el acto de proporcionar instrucciones precisas a una computadora
para que realice una tarea específica. Una diferencia clave con la comunicación
humana es que la computadora **no interpreta ambigüedades**. No comprende
conceptos como «más o menos». Cada paso debe estar perfectamente definido. En
este sentido, C presenta ciertas ambigüedades que pueden conducir a resultados
inesperados.

Durante la programación, la omisión de un solo detalle puede provocar que el
programa no funcione. Por ello, es necesario aprender a **pensar como una
máquina**, pero también a **estructurar el pensamiento como un ser humano
inteligente**.

En C, no existen atajos, lo cual es una ventaja, ya que te obliga a pensar
de forma clara y lógica.

## ¿Por qué aprender C?

El lenguaje C fue creado en 1972 por **Dennis Ritchie** y **Brian Kernighan** en
los Bell Labs. A pesar de tener más de 50 años de existencia, se sigue
utilizando ampliamente debido a sus características fundamentales:

- **Simplicidad**: Tiene una sintaxis reducida que facilita entender cómo se
  relacionan las instrucciones con el hardware.

- **Eficiencia**: El código compilado en C es muy rápido, cercano al rendimiento
  del lenguaje ensamblador.

- **Portabilidad**: Permite escribir programas que pueden ejecutarse en
  distintos sistemas operativos con mínimas modificaciones.

- **Historia y origen:** Nació de la necesidad de tener un lenguaje eficiente y
  portable para desarrollar el sistema operativo UNIX.

- **Evolución y estandarización:** Lejos de ser un lenguaje inamovible, C ha
  estado en constante revisión y mejora. Ha sido estandarizado primero por el
  {abbr}`ANSI (Instituto Nacional Estadounidense de Estándares)` y luego por la
  {abbr}`ISO (Organización Internacional de Normalización)` e
  {abbr}`IEC (Comisión Electrotécnica Internacional)`. De forma de mantener no
  solo la vigencia del lenguaje sinó su compatibilidad entre implementaciones,
  más adelante veremos algo al respecto a este tema.

  - [ANSI X3.159-1989](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub160.pdf)
  - [ISO/IEC 9899:1990](https://www.iso.org/standard/17782.html)
  - [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html)
  - [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html)
  - [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html)
  - [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)

- **Influencia:** C ha servido como base e inspiración para muchos de los
  lenguajes más utilizados hoy en día, incluyendo C++, C#, Java, JavaScript,
  Objective-C y PHP. Aprender C proporciona una base sólida para entender cómo
  funcionan muchos otros lenguajes, lo cual se aprovechará en la asignatura
  Programación II el cuatrimestre siguiente.

- **Popularidad**: Figura entre los lenguajes más usados según el
  [índice TIOBE](https://www.tiobe.com/tiobe-index/c/), que mide el «interes» en
  los diferentes lenguajes de programación, al momento de escribir esto, se
  encuentra en el puesto número 3.

## Características Principales de C

### Nivel de Abstracción

Aunque C es considerado un lenguaje de **nivel medio**, en el momento en el que
fue creado, era de «alto nivel», esto teniendo en cuenta la comparación con
otros lenguajes y en particular, el {term}`Lenguaje Ensamblador`.

Hoy en día y con el desarrollo de nuevos lenguajes, y teniendo en cuenta que
pasaron _solo_ 50 años de que fué creado, se lo sitúa en un nivel superior a los
de bajo nivel, pero inferior a los que actualmente son considerados de alto
nivel como Python o Java.

Esto le da un balance único:

- Permite un control muy cercano al hardware del sistema (gestión de memoria,
  registros, etc.).
- Ofrece construcciones de programación estructurada que facilitan el desarrollo
  de algoritmos complejos.

Esta característica está ligada a que C es un lenguaje **compilado**. El código
fuente se traduce directamente a código máquina antes de ejecutarse, a
diferencia de los lenguajes **interpretados** (como Python) que son traducidos
línea por línea en tiempo de ejecución.

### Atributos Clave

- **Compilado** un programa, es convertido a código de máquina de forma completa
  antes de ser ejecutado por otro programa, llamado compilador.
- **Imperativo:** Un programa consiste en una secuencia de instrucciones que
  modifican el estado (las variables) del programa.
- **Estructurado:** El código se organiza en bloques lógicos y funciones, lo que
  promueve la claridad y la reutilización.

### Fortalezas y debilidades del lenguaje

Además de las razones para aprender y utilizar el lenguaje que están más arriba,
hay un conjunto adicional de fortalezas importantes para tratar:

#### Acceso a conceptos de bajo nivel

Para ser utilizado como lenguaje de programación para sistemas, C provee acceso
a conceptos directamente relacionados con el hardware que lo ejecutará.
Conceptos como el tamaño en memoria, punteros, segmentos y las instrucciones son
en definitiva muy similares a las que la computadora utiliza, de forma que los
programas sean lo más rápidos posibles.

#### C es un lenguaje pequeño

El lenguaje provee un conjunto de instrucciones reducido; tengan en cuenta que
el documento que define el lenguaje original, el K&R Segunda Edición, cubre el
lenguaje completo en 49 páginas. Todo lo demás provisto por el lenguaje es
cubierto con la librería estándar integrada implementada con funciones.

#### C es un lenguaje permisivo

El lenguaje asume que el programador sabe lo que está haciendo, por lo que
permite hacer una mayor cantidad de cosas, para bien y para mal.

### Debilidades

El lenguaje C, a pesar de su gran popularidad y potencia, presenta ciertas
debilidades inherentes que deben ser comprendidas para un desarrollo eficiente y
seguro. Es crucial conocer estas limitaciones desde su origen para establecer
estrategias que las prevengan.

Estas surgen de la misma fuente que muchas de sus fortalezas: la cercanía del
lenguaje C a la máquina. A continuación, algunas de sus debilidades más notorias

#### Los programas en C pueden ser propensos a errores

La flexibilidad de C lo convierte en un lenguaje propenso a errores. Los errores
de programación que serían detectados en muchos otros lenguajes no pueden ser
detectados por un compilador de C. En este aspecto, C es muy parecido al
lenguaje ensamblador, donde la mayoría de los errores no se detectan hasta que
el programa se ejecuta. Para empeorar las cosas, C contiene una serie de trampas
para los desprevenidos. En las clases siguientes, veremos cómo un punto y coma
extra puede crear un lazo infinito o un símbolo faltante puede causar que un
programa falle.

#### Los programas en C pueden ser difíciles de entender

Aunque C es un lenguaje pequeño según la mayoría de las medidas, tiene una serie
de características que no se encuentran en muchos lenguajes de programación (y
que, en consecuencia, a menudo se malinterpretan). Estas características se
pueden combinar de muchas maneras, muchas de las cuales, aunque obvias para el
autor original de un programa, pueden ser difíciles de entender. Otro problema
es la naturaleza concisa de los programas en C; fue diseñado en un momento en el
que la comunicación interactiva con las computadoras era tediosa en el mejor de
los casos. Como resultado, el lenguaje fue creado con propósito para ser conciso
y minimizar el tiempo requerido para ingresar y editar programas. La
flexibilidad de C también puede ser un factor negativo; los programadores que
son demasiado inteligentes para su propio bien pueden hacer que los programas
sean casi imposibles de entender.

#### Los programas en C pueden ser difíciles de modificar

Los programas grandes escritos en C pueden ser difíciles de cambiar si no han
sido diseñados pensando en el mantenimiento. Los lenguajes de programación
modernos suelen proporcionar características como clases y paquetes que soportan
la división de un programa grande en piezas más manejables. C,
desafortunadamente, carece de tales características.

## Las herramientas del aprendiz

### Instale lo justo y necesario

- **Compilador C:** `gcc` o `clang`
- **Editor de texto:** `vim`, `nano`, `gedit`, CodeBlocks, VSCode... o el de tu
  preferencia.
- **Terminal:** se pasará una parte importante del tiempo acá y es importante
  aprender a usar el prompt.

En Debian/Ubuntu,

```bash
sudo apt install build-essential
```

Para Windows, podés seguir la guía sobre la instalación del
[compilador](../guias/compilador).

:::{warning} ¡Importante!

Si surgen problemas o dificultades en esta etapa, es crucial resolverlos lo
antes posible para no frenar el aprendizaje por  las herramientas.

Se recomienda consultar en las clases prácticas o en el espacio de
[Discussions](https://github.com/orgs/INGCOM-UNRN-P1/discussions).

:::

### Primer programa: el «Hola Mundo» al C

```{code-block} c
:label: holamundo
:caption: El indispensable Hola Mundo!
:linenos:
:filename: hola.c
#include <stdio.h>              // directiva al preprocesador

int main()                      // punto de entrada del programa
{                               // inicio de un bloque de código
    printf("Hola mundo C.\n");  // llamada a la instruccion de salida
    return 0;                   // finalización del programa
}                               // fin del bloque de código
```

#### Compilación y Ejecución

Para ejecutar un programa en C, primero hay que compilarlo. Esto se hace desde
la terminal con un compilador como `gcc`. Y aunque se verá y usará un entorno
gráfico, la consola es el mínimo común denominador.

```{code-block} sh
:label: salidamundo
:caption: La salida por la terminal.

# Compila el archivo hola.c y crea un ejecutable llamado a.out
# (en Linux/macOS) o a.exe (en Windows)
$> gcc hola.c

# Ejecuta el programa
$> ./a.out
Hola mundo C.
$>
```

Si se presta atención a la instrucción `printf`, se puede observar que faltan
dos caracteres que están en el programa, pero no se ven en la salida. Esto es
una secuencia de control, es la forma de ingresar caracteres que no son
visibles, y el `\n` es el «enter» o salto de linea.

#### Pieza por pieza

1. `#include <stdio.h>`: Es una **directiva del preprocesador**. Le indica al
   compilador que incluya la librería estándar de entrada/salida (`stdio.h`),
   que contiene la definición de la función `printf`.
2. `int main()`: Es el **punto de entrada** del programa. Todo programa en C
   comienza su ejecución aquí. La palabra `int` indica que la función devolverá
   un número entero.
3. `{ ... }`: Las llaves definen un **bloque de código**. Todo lo que está
   dentro de las llaves pertenece a la función `main`.
4. `printf("Hola mundo C.\n");`: Es una **instrucción** que llama a la función
   `printf` para imprimir el texto en la consola. `\n` es un carácter especial
   que representa un salto de línea.
5. `return 0;`: Es la instrucción que **finaliza la función `main`** y devuelve
   un valor al sistema operativo. Por convención, `0` significa que el programa
   terminó sin errores.
6. El código del ejemplo, hace uso de comentarios de línea para ayudar a
   ubicar la pieza específica que se describe en esta lista.

:::{warning} Atención

Si no se visualiza el mensaje que está dentro de la instrucción `printf`, hay
algún problema que es necesario solucionar. No se debe detener en este punto, ya
que es un bloqueante para los temas siguientes.

:::

## El Algoritmo: pensar antes de escribir

### Mentalidad de programador

1. **Leé el problema. Comprendelo. Dibújalo.**
2. **Divílo en pasos simples**, para que una máquina sin intuición los pueda
   seguir.
3. **Usá papel y lápiz**. No escribas código antes de tener claro el objetivo.
4. **Convertí esos pasos en instrucciones en C.**

:::{figure} think.jpg
:alt: Roll Safe thinking
:align: center

_Pensar es más importante que escribir._
:::

### Ejemplo simple, pero clave: sumar dos números

1. Leer un número.
2. Leer otro número.
3. Sumar.
4. Mostrar el resultado.

```c
#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Ingresá dos números: ");
    scanf("%d %d", &a, &b);
    printf("La suma es: %d\n", a + b);
    return 0;
}
```

## Sobre las reglas de estilo

El uso de reglas de estilo en la programación en C, aunque a veces se percibe
como una restricción, es fundamental para garantizar la consistencia y
legibilidad del código. Al adherirse a un conjunto de normas, como las
convenciones de nomenclatura, la indentación uniforme y la estructuración de
comentarios, se facilita enormemente la colaboración entre desarrolladores y el
mantenimiento del software a largo plazo. Incluso las reglas que pueden parecer
controvertidas o arbitrarias, como la posición de las llaves o el uso de
espacios en lugar de tabulaciones, tienen un propósito pedagógico. Obligan a los
programadores a ser más conscientes de su estilo de escritura, promoviendo un
aprendizaje más profundo sobre las mejores prácticas y la importancia de la
uniformidad en el desarrollo de software. Esto eleva la calidad del código no
solo en su funcionalidad, sino también en su estética y claridad. Para más
detalles, consulte la regla {ref}`0x0000h`.

Por otro lado, esto es parte del uso profesional del lenguaje, tanto que existen
múltiples estándares de estilo.

### C obfuscado

Incluso los fans más acérrimos del lenguaje están de acuerdo que el lenguaje
puede volverse difícil de leer con bastante facilidad.

Esta «capacidad» del lenguaje se acentúa en la competencia anual de código C
obfuscado [IOCC](https://www.ioccc.org/), en la que se buscan las formas más
rebuscadas posibles para crear programas que compilan y funcionan, pero de la
forma más enrevesada posible.

El ganador en la categoría «El mejor de una línea» del 2019,
[Dave Burton, Contar palabras](https://www.ioccc.org/2019/burton/index.html)

```c
e,n,j,o,y;main(){for(++o;n=-~getchar();e+=11==n,y++)o=n>0xe^012>n&&'`'^n^65?!n:!o?++j:o;printf("%8d%8d%8d\n",e^n,j+=!o&&y,y);}
```

Como se puede observar, el lenguaje se presta para crear código 
muy difícil de leer.

## Sintaxis Básica

La **sintaxis** es el conjunto de reglas que definen cómo debe escribirse el
código para ser considerado válido.

Mientras que la **gramática** determina si el código tiene sentido lógico y
estructural. Es posible que algo sea sintácticamente válido pero gramaticalmente
incorrecto.

### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que damos a variables y funciones.
Deben empezar con una letra o un guion bajo (`_`) y pueden contener letras,
números y guiones bajos. C distingue entre mayúsculas y minúsculas (`suma` es
diferente de `Suma`).

- Comienzan con letra o guion bajo: `azAZ_`
- Pueden incluir números después: `0-9`
- Pueden utilizar guiones bajos: `_`
- No pueden ser palabras reservadas.

**Palabras Reservadas:** Son palabras con un significado especial en C y no
pueden ser usadas como identificadores (ej: `int`, `if`, `else`, `while`,
`return`).

#### Ejemplos

- Correctos: `sumaTotal`, `valor_maximo`
- Incorrectos: `2variable`, `var-uno`, `int`

Es importante tener en cuenta que hay una forma específica para cada tipo de
identificador, esto lo iremos viendo a lo largo del curso y está resumido en las
cuestiones de estilo (ver {ref}`0x0001h`).

## Variables: las cajas

### ¿Qué son?

Una variable es un nombre simbólico para un espacio en memoria que guarda un
valor. Pensalo como una caja con una etiqueta y un contenido que se puede
cambiar.

### Tipos básicos en C

- `int`: números enteros (sin decimales)
- `float`: números reales con coma
- `char`: un carácter

### Declaración y asignación

```c
int edad = 42;      // caja llamada edad, con 42 adentro
float pi = 3.14;    // caja llamada pi, con 3.14
char inicial = 'A'; // caja llamada inicial, con 'A'
```

Podés declarar y luego asignar:

```c
int numero;
numero = 17;
```

### ¿Es necesario inicializar las variables?

Si se declara una variable, pero no se le asigna un valor inicial, su contenido
es **indeterminado**: puede contener cualquier cosa, lo que se conoce como
«basura». En sistemas operativos modernos, muchas veces la memoria se entrega
inicializada en cero para evitar que se filtren datos de otros programas, pero
**no se puede confiar en esta inicialización por defecto**.

A medida que el programa se ejecuta y reutiliza memoria, es posible que una
variable sin inicializar contenga valores viejos, distintos de cero, o cualquier
cosa inesperada. Por eso, **siempre inicializá las variables** antes de
usarlas. Esto evita errores difíciles de detectar y hace el código más seguro y
predecible.

Es en este punto donde entran en juego las reglas de estilo, como la {ref}`0x0003h`.

### ¿Cómo funcionan?

- Las variables deben declararse antes de usarse.
- No se puede cambiar el tipo una vez declarado.
- C es fuertemente tipado: `int` no es `float` ni `char`.

### Ejercicio 1

:::{exercise}
:label: Mostrando valores
:enumerator: Valores

Escribí un programa que guarde tu edad, tu altura en metros y tu inicial, y los
muestre por pantalla. Dejá esta información directamente en las variables, a
continuación vamos a ver como pedir esto por teclado.
:::

:::{solution} Mostrando valores
:class: dropdown

```{code-block} c
:linenos:

#include <stdio.h>

int main()
{
    int edad = 30;
    float altura = 1.75;
    char inicial = 'M';

    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}
```
:::

### Un poco más de detalle

En C, cada expresión tiene un «valor» y, fundamentalmente, se clasifica en una
de dos categorías: **L-value** o **R-value**. Esta distinción es crucial para
entender cómo el compilador maneja los datos, las asignaciones de memoria y los
diferentes roles de los identificadores en un programa.

#### L-Values

Un L-value (del inglés _locator_ value o _left_ value) representa a una variable
en la memoria, el identificador en sí (la etiqueta de la caja).

Esta es una ubicación que se puede modificar, y donde se guardan los resultados
de las expresiones derechas (R-Values). Por ejemplo, en la declaración
`int x = 10;`, la variable `x` es un L-value. `x` se refiere a una ubicación de
memoria específica donde se almacena el valor `10`. Se puede modificar su valor,
como en `x = 20;`.

#### R-Values

Un R-value (del inglés _read_ value, '_right_' value) es una expresión que
representa un valor temporal o literal que no tiene una ubicación específica en
la memoria.

Como su nombre indica, un R-value solo puede ser leído y, por lo tanto, solo
puede aparecer en el lado derecho de un operador de asignación. No se puede
asignar un nuevo valor a un R-value porque no hay un lugar garantizado en la
memoria para almacenarlo.

Ejemplos comunes de R-values son los literales numéricos (como `10`, `3.14`), el
resultado de una operación aritmética (`a + b`), o el valor de retorno de una
función (`mi_funcion()`). Intentar asignar un valor a un R-value, como en
`100 = x; o (a + b) = 5;`, dará como resultado un error de compilación, ya que
ni `100` ni el resultado de `a + b` son L-values con una dirección de memoria
asignable.

## Entrada y salida: hablar con el usuario

### `printf()` - Mostrar resultados

Sirve para mostrar texto y valores como mensajes; puede consultar el
[apunte más detallado del tema](../extras/printf).

```c
printf("Tiene %d años\n", edad);
```

El par de símbolos `\n` se usan para indicar el 'salto de línea', para que no
quede todo junto en una sola. Específicamente, cada vez que se ve una `\`, se
indica que el siguiente carácter tiene un significado diferente del que se ve;
esto se llama [secuencias de escape](../extras/printf#escape).

(formatos)=

### Especificadores más comunes

| Tipo     | Especificador       |
| -------- | ------------------- |
| `int`    | `%d`                |
| `float`  | `%f`                |
| `char`   | `%c`                |
| `string` | `%s` (con `char[])` |

### `scanf()` - Leer datos desde el teclado

La función `scanf()` sirve para que el programa reciba datos del usuario. Es
necesario indicar el tipo de dato y pasar a qué variable se le asignará el valor
obtenido (más adelante se analizará el uso y significado del operador `&`).

```c
int edad;
printf("Ingrese su edad: ");
scanf("%d", &edad);
```

Se usan los mismos códigos de formato que [`printf`](#formatos).

### Ejercicio 2

:::{exercise}
:label: entrada-1
:enumerator: entrada-1
Pedí al usuario la inicial de su nombre (un solo carácter), edad y nota promedio, y mostralos formateados.
:::

:::{solution} entrada-1
:class: dropdown

```{code-block} c
:linenos:

#include <stdio.h>

int main()
{
    char inicial;
    int edad;
    float nota;

    printf("Ingresá tu inicial: ");
    scanf(" %c", &inicial);  // espacio antes de %c para evitar problemas de buffer

    printf("Edad: ");
    scanf("%d", &edad);

    printf("Nota promedio: ");
    scanf("%f", &nota);

    printf("\nHola %c, tenés %d años y tu promedio es %.1f\n", inicial, edad, nota);

    return 0;
}
```
:::

## Condicionales, tomando decisiones

Las estructuras condicionales permiten que el programa tome decisiones.

### `if`, `else if`, `else`

```c
if (condicion)
{
    // bloque si se cumple
} else if (otra_condicion)
{
    // otro camino
} else
{
    // camino por defecto
}
```

En donde las condiciones, deben ser el resultado de una expresión lógica.

:::{note} «Veracidad»

Para C, los valores lógicos no forman parte del lenguaje original y el mismo
considera cualquier valor entero en `0` como falso y cualquier otro como
verdadero. Esto se conoce como "veracidad" ({ref}`0x0010h`) y su uso no
está permitido, ya que puede generar confusión.

:::

### Operadores lógicos comunes

- `==` igual
- `!=` distinto
- `>` mayor
- `<` menor
- `>=`, `<=`
- `&&` y lógico
- `||` o lógico

### Ejemplo

```c
int edad;
scanf("%d", &edad);

if (edad >= 18)
{
    printf("Mayor de edad\n");
} else
{
    printf("Menor de edad\n");
}
```

:::{attention} 🪐 Cuestión de estilo

Todas las estructuras de control que contienen un bloque, deben llevar _sí o sí_
llaves, según la regla {ref}`0x0005h`.

:::

### Ejercicio 3

:::{exercise}
:label: entrada-2
:enumerator: entrada-2
Pedí una nota y mostra su resultado en palabras:
- Promociona, con la nota mayor o igual a 6.
- Aprueba, con la nota mayor o igual a 4.
- Desaprueba: menor a 4
:::

:::{solution} entrada-2
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    int nota;
    printf("Ingrese su nota: ");
    scanf("%d", &nota);

    if (nota >= 6)
    {
        printf("Promociona\n");
    } else if (nota >= 4)
    {
        printf("Aprueba\n");
    } else
    {
        printf("Desaprueba\n");
    }
}
```
:::

### Decisiones múltiples `switch`

Útil para comparar una variable con múltiples valores constantes. Tenga en
cuenta que esta estructura solo compara igualdad, aunque se pueden agrupar.

```C
switch (expresion)
{
    case valor1:
        // sentencias
        break;
    case valor2:
        // sentencias
        break;
    default:
        // sentencias si no coincide ningún caso
}
```

Es importante destacar que la instrucción `break` es opcional, y puede ser
utilizada para agrupar «casos».

```c
switch (x)
{
    case 1:
    case 2:
    case 3:
        printf("Entre 1 y 3\n");
        break;
    default:
        printf("Otro valor\n");
}
```

:::{note}¿Qué se puede comparar?

Como está estructurado, funciona por igualdad, por lo que solo se puede utilizar
con valores numéricos enteros.

:::

## Lazos repetir hasta dominar el universo

Un **lazo**, o bucle, o _loop_ es una estructura que permite repetir una o más
instrucciones mientras se cumpla una condición. Esta es la forma en la que se le
indica a la máquina: «hacé esto muchas veces sin que yo tenga que copiar y
pegar»_.

Hay tres formas principales de lazos en C:

- `while` — mientras la condición sea verdadera.
- `for` — cuando sabés de antemano cuántas veces repetir.
- `do...while` — ejecuta el bloque al menos una vez.

### `while` — Repetición basada en condición

Las instrucciones del bloque contenido en el `while` se ejecutarán mientras la
condición (`i < 5`) sea verdadera. Si nunca lo es, el bloque no se ejecuta.

```c
int i = 0;
while (i < 5)
{
    printf("i vale %d\n", i);
    i = i + 1; // o i++
}
```

#### Flujo

```{mermaid}
flowchart TD
    subgraph while
      Inicio --> EvaluarCondicion{"¿Se cumple la condición?"}
      EvaluarCondicion -- "Verdadero" --> EjecutarBloque[Ejecutar bloque de código]
      EjecutarBloque --> EvaluarCondicion
      EvaluarCondicion -- "Falso" --> Fin
    end
```

### Ejercicio 4

:::{exercise}
:label: lazo_while 
:enumerator: while

Escribí un programa que imprima los números del 10 al 1 usando `while`.

:::

:::{solution} lazo_while
:label: solucion-lazo_while
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    int i = 10;
    while (i >= 1)
    {
        printf("%d\n", i);
        i--;
    }
    return 0;
}
```
:::

### `for` — Lazos controlados por un contador

Este tipo de lazo es ideal cuando se sabe cuántas veces se quiere repetir.
Aunque hace lo mismo que el `while`, este es más estructurado con secciones
específicas para cada acción del lazo.

```c
for (int i = 0; i < 5; i++)
{
    printf("i vale %d\n", i);
}
```

:::{admonition} Las partes del `for`

`for (inicio; condición; paso) { bloque }`

- **inicio:** una sola vez al comenzar.
- **condición:** se evalúa antes de cada iteración.
- **paso:** se ejecuta al final de cada vuelta.
- **bloque:** las instrucciones ejecutadas mientras la condición sea verdadera.

:::

**Y su equivalente con `while`:**

```c
int i = 0;                      // inicio
while (i < 5) {                 // condición
    printf("i vale %d\n", i);   // bloque
    i++;                        // paso
}
```

### Ejercicio 5

:::{exercise}
:label: lazo_for
:enumerator: for

Usá un `for` para mostrar los múltiplos de 3 entre 0 y 30.

:::

:::{solution} lazo_for
:label: solucion-lazo_for
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    for (int i = 0; i <= 30; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d es múltiplo de 3\n", i);
        }
    }
    return 0;
}
```
:::

### `do...while` — Ejecuta primero, pregunta después

> Do, do while, do while if...
>
> - Rammstein, du...while

```{image} lazos.jpg
:alt: Ejemplo Grafico de lazos
:align: center
```

```c
int clave;
do {
    printf("Ingresá la clave (123): ");
    scanf("%d", &clave);
} while (clave != 123);
```

Este tipo de lazo garantiza **al menos una ejecución**. Ideal para menús o
ingreso de datos que deben ejecutarse al menos una vez.

:::{warning} Tené cuidado con los lazos infinitos.

Si la condición **nunca** se vuelve falsa, el programa quedará atrapado en un
ciclo eterno.

:::

#### Flujo

```{mermaid}
flowchart TD
    subgraph do..while
        Inicio --> EjecutarBloque["Ejecutar bloque de código"]
        EjecutarBloque --> EvaluarCondicion{"¿Se cumple la condición?"}
        EvaluarCondicion -- "Verdadero" --> EjecutarBloque
        EvaluarCondicion -- "Falso" --> Fin
    end
```

### Ejercicio 6

:::{exercise}
:label: lazo_repeat
:enumerator: for

Usá un lazo `do..while` para controlar el acceso a un edificio, pidiéndole al
usuario que ingrese un número usado como clave.

:::

:::{solution} lazo_repeat
:label: solucion-lazo_repeat
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int clave;
    int clave_correcta = 1234; // Definimos una clave correcta

    do {
        printf("Ingresá la clave: ");
        scanf("%d", &clave);

        if (clave == clave_correcta) {
            printf("Acceso concedido. ¡Bienvenido!\n");
        } else {
            printf("Clave incorrecta. Intentá de nuevo.\n");
        }
    } while (clave != clave_correcta);

    return 0;
}
```
:::

### `break` y `continue` — Atajos dentro del ciclo

En C, `break` y `continue` son dos instrucciones de control que permiten
modificar el flujo normal de un lazo. Aunque pueden resultar útiles en ciertos
contextos, su uso abusivo o descontrolado puede reducir la claridad del código.

#### `break`

Sirve para **salir completamente del lazo**, sin importar si la condición sigue
siendo verdadera.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break; // termina el lazo cuando i vale 5
    }
    printf("i = %d", i);
}
```

#### `continue`

Sirve para **saltar al final del ciclo actual** y seguir con la siguiente
vuelta.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue; // omite imprimir cuando i vale 3
    }
    printf("i = %d", i);
}
```

:::{tip} ¿Cuándo usarlos?

Use `break` cuando ya no tenga sentido seguir iterando, y `continue` cuando
quieras saltear un caso particular.

:::

:::{admonition} Observación

La cátedra establece que el uso de `break` y `continue` no está permitido por
dos motivos:

1. **Reducen la legibilidad del código**: cuando hay muchas salidas posibles
   dentro de un lazo, se vuelve más difícil entender cuándo y por qué termina.
2. **Evitan el desarrollo del pensamiento algorítmico**: recurrir a estos atajos
   puede impedir que el estudiante busque una solución más clara, estructurada y
   general al problema.

Por eso, en las primeras etapas del aprendizaje, los evitaremos para fortalecer
la comprensión de la lógica de control (ver {ref}`0x0008h`).

En lugar de usar estos atajos, se pedirá el uso de lazos con bandera, que se
explican a continuación.

:::

### Ejercicio 7

:::{exercise}
:label: lazo_break
:enumerator: break

Modificá el siguiente código para que no utilice la instrucción `break`.

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("valor actual: %d\n", i);
        if (i == 4)
        {
            break;
        }
    }
    return 0;
}
```

:::

:::{solution} lazo_break
:label: solucion-lazo_break
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("valor actual: %d\n", i);
    }
    return 0;
}
```
:::

### Ejercicio 8

:::{exercise}
:label: lazo_continue
:enumerator: continue

Modifique el siguiente código para que no utilice la instrucción `continue`.

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        printf("i = %d\n", i);
    }
    return 0;
}
```

:::

:::{solution} lazo_continue
:label: solucion-lazo_continue
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i = i + 2) {
        printf("i = %d\n", i);
    }
    return 0;
}
```
:::

### Lazos con bandera (`flag`)

En algunos casos, no es posible reescribir el lazo para que no utilice `break`,
simplemente porque no hay una expresión que lo permita, o porque es necesario
salir del lazo antes, por lo que es necesario aplicar una estrategia clásica en
programación estructurada.

El uso de una **variable bandera** para controlar la repetición de un lazo. En
lugar de usar `break`, se define una variable booleana que indica si se debe
continuar o no.

Desde el estándar C99, se puede usar el tipo `bool` del encabezado `stdbool.h`,
lo cual mejora la legibilidad.

#### Ejemplo:

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool continuar = true;
    int numero;

    while (continuar) {
        printf("Ingresá un número (0 para salir): ");
        scanf("%d", &numero);

        if (numero == 0) {
            continuar = false; // apagamos la bandera
        } else {
            printf("Ingresaste: %d", numero);
        }
    }
    return 0;
}
```

#### Ventajas

- Mejora la legibilidad y estructura lógica.
- Permite definir con claridad la condición de corte.
- Favorece el razonamiento algorítmico en vez de usar interrupciones abruptas
  como `break`.

### Ejercicio 9

:::{exercise}
:label: lazo_flag_break
:enumerator: continue

Reescribí el ingreso de clave usando una bandera booleana en lugar de `break` o
`do...while`.

:::

:::{solution} lazo_flag_break
:label: solucion-lazo_flag_break
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h> // Se necesita esta librería para usar 'bool'

int main()
{
    int clave;
    int clave_correcta = 1234; // Definimos la clave correcta
    bool acceso_concedido = false; // Nuestra bandera booleana

    // Usamos un lazo while y controlamos la salida con la bandera
    while (!acceso_concedido)
    {
        printf("Ingresá la clave: ");
        scanf("%d", &clave);

        if (clave == clave_correcta)
        {
            printf("Acceso concedido. ¡Bienvenido!\n");
            acceso_concedido = true; // Cambiamos la bandera para salir del lazo
        }
        else
        {
            printf("Clave incorrecta. Intentá de nuevo.\n");
        }
    }

    return 0;
}
```
:::

## Ejercicios

10. Pida dos números y muestre el mayor.
11. Muestre los números del 1 al 100.
12. Sume los números pares del 1 al 100.
13. Pida un número e indique si es primo.
14. Pida una nota (0 a 10) e indique si aprobó.
15. Haga un programa que pida la contraseña hasta que sea la correcta.

## Pensar antes de escribir (otra vez)

Cuando estés atascado:

- Escribí el algoritmo en sus propias palabras.
- Dibujá un diagrama de flujo; no tiene que ser perfecto, solo sirve para
  cambiar el punto de vista.
- Usá una prueba de escritorio (dry-run).
- Y si todo lo demás falla, inserte instrucciones `printf` para depurar.

> _El compilador le dirá qué no entiende. Escúchelo, corrija e intentá 
> nuevamente._

:::{figure} zach-galifianakis-math.gif
:alt: Zach Galifianakis doing math
:align: center
:::

## No siga más allá (todavía)

No se adelante a las partes siguientes del apunte, a los referidos a funciones,
punteros, `structs` ni `arrays` (aún).

Primero entendé lo esencial:

- El código se ejecuta de arriba a abajo.
- Las variables viven en la memoria.
- Los algoritmos son secuencias lógicas.

Ya vamos a ver...

- [](3_funciones.md) — Definición de funciones, parámetros, retorno, alcances y descomposición funcional para estructurar programas más grandes.
- [](4_secuencias.md) — Arreglos y cadenas: memoria contigua, acceso seguro, paso a funciones y utilidades para manipular colecciones de datos.
- [](5_compilacion.md) — Proceso de compilación con GCC, fases del compilador, archivos de cabecera y organización de proyectos con `Makefiles`.
- [](7_punteros.md) — Punteros, direcciones de memoria, aritmética de punteros y su relación con arreglos y funciones.
- [](8_archivos.md) — Entrada/salida con archivos de texto: apertura, lectura, escritura, posicionamiento y manejo robusto de errores.

¡Y algunas cosas más!

- [](0_estilo.md) — Que es una mezcla de restricciones pedagógicas y de experiencia acumulada para ayudarlos a desarrollar lo mejor posible.

## Afilando el código

Programar bien es:

- Pensar simple.
- Probar seguido.
- No repetir código, ya que casi siempre es una mala señal.
- Comentar lo que no sea obvio.
- Leer programas ajenos y tomar buenas ideas.

> _"Escriba código que un colega pueda entender a las 3 AM."_

## Bibliografía y Recursos Adicionales

- Kernighan, B. W., & Ritchie, D. M. (1988). _The C Programming Language (2nd
  ed.)_. Prentice Hall. (El libro de referencia por los creadores del lenguaje,
  también conocido como «K&R»).

- King, K. N. (2008). _C Programming: A Modern Approach (2nd ed.)_. W. W. Norton
  & Company. (Una excelente alternativa moderna, muy detallada y con buenos
  ejemplos).

## Glosario

:::{glossary}

Lenguaje Ensamblador
: El lenguaje ensamblador (assembly language) es un
lenguaje de programación de bajo nivel que representa las instrucciones de
código de máquina de una arquitectura de procesador específica mediante
mnemónicos. Mantiene una correspondencia casi directa (a menudo uno a uno) con
las operaciones del hardware. Requiere un programa llamado ensamblador
(assembler) para traducir los mnemónicos al código de máquina ejecutable por el
procesador. Ofrece control preciso sobre el hardware con una legibilidad
superior a la del código máquina.

Lenguaje de Máquina
: El lenguaje de máquina (machine language o machine code)
es el conjunto de instrucciones en formato binario (secuencias de ceros y unos)
que la unidad central de procesamiento (CPU) de una computadora puede ejecutar
directamente. Es el nivel más bajo de lenguaje de programación, específico para
cada arquitectura de procesador. Todas las formas de software deben ser
traducidas o interpretadas a este lenguaje para poder ser ejecutadas por el
hardware.

:::
