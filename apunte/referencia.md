---
title: Referencia del lenguaje C
short_title: 4 - C en profundidad
subtitle: La sintaxis y programas básicos.
---

Este apunte resume los conceptos fundamentales del lenguaje de programación C,
su historia, sus características principales y los elementos básicos de su
sintaxis, tal como se presentaron en la clase.

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

- **Historia y Origen:** Nació de la necesidad de tener un lenguaje eficiente y
  portable para desarrollar el sistema operativo UNIX.

- **Evolución y Estandarización:** Lejos de ser un lenguaje inamovible, C ha
  estado en constante revisión y mejora. Ha sido estandarizado primero por el
  {abbr}`ANSI (Instituto Nacional Estadounidense de Estándares)` y luego por la
  {abbr}`ISO (Organización Internacional de Normalización)` e
  {abbr}`IEC (Comisión Electrotécnica Internacional)`. De forma de mantener no
  solo la vigencia el lenguaje sinó su compatibilidad entre implementaciones,
  más adelante veremos algo al respecto a este tema.

  - [ANSI X3.159-1989](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub160.pdf)
  - [ISO/IEC 9899:1990](https://www.iso.org/standard/17782.html)
  - [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html)
  - [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html)
  - [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html)
  - [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)

- **Influencia:** C ha servido como base e inspiración para muchos de los
  lenguajes más utilizados hoy en día, incluyendo C++, C#, Java, JavaScript,
  Objective-C y PHP. Aprender C te da una base sólida para entender cómo
  funcionan muchos otros lenguajes, aprovecharemos esto en Programación 2 el
  cuatrimestre siguiente.

- **Popularidad**: Figura entre los lenguajes más usados según el
  [índice TIOBE](https://www.tiobe.com/tiobe-index/c/), que mide el "interes" en
  los diferentes lenguajes de programación, al momento de escribir esto, se
  encuentra en el puesto número 3.

## Características Principales de C

### Nivel de Abstracción

Aunque C es considerado un lenguaje de **nivel medio**, en el momento en el que
fue creado, era de "alto nivel", esto teniendo en cuenta la comparación con
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

- **Compilado** un programa es convertido a código de máquina de forma completa
  antes de ser ejecutado por otro programa, llamado compilador.
- **Imperativo:** Un programa consiste en una secuencia de instrucciones que
  modifican el estado (las variables) del programa.
- **Estructurado:** El código se organiza en bloques lógicos y funciones, lo que
  promueve la claridad y la reutilización.

### Fortalezas y debilidades del lenguaje

Ademas de las razones para aprender y utilizar el lenguaje que estan mas arriba,
hay un conjunto adicional de fortalezas importantes para tratar:

#### Acceso a conceptos de bajo nivel

Para ser utilizado como lenguaje de programacion para sistemas, C provee acceso
a conceptos directamente relacionados con el hardware que lo ejecutará.
Conceptos como el tamaño en memoria, punteros, segmentos y las instrucciones son
en definitiva muy similares a las que la computadora utiliza, de forma que los
programas sean lo mas rápidos posibles.

#### C es un lenguaje pequeño

El lenguaje provee un conjunto de instrucciones reducido, tengan en cuenta que
el documento que define el lenguaje original, el K&R Segunda Edición cubre el
lenguaje completo en 49 páginas. Todo lo demas provisto por el lenguaje es
cubierto con la libreria estándar integrada implementada con funciones.

#### C es un lenguaje permisivo

El lenguaje asume que sabes lo que estas haciendo, por lo que permite hacer una
mayor cantidad de cosas, para bien y para mal

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
para los desprevenidos. En clases siguientes, veremos cómo un punto y coma extra
puede crear un bucle infinito o un símbolo faltante puede causar que un programa
falle.

#### Los programas en C pueden ser difíciles de entender

Aunque C es un lenguaje pequeño según la mayoría de las medidas, tiene una serie
de características que no se encuentran en muchos lenguajes de programación (y
que, en consecuencia, a menudo se malinterpretan). Estas características se
pueden combinar de muchas maneras, muchas de las cuales, aunque obvias para el
autor original de un programa, pueden ser difíciles de entender. Otro problema
es la naturaleza concisa de los programas en C. C fue diseñado en un momento en
que la comunicación interactiva con las computadoras era tediosa en el mejor de
los casos. Como resultado, C fue creado a propósito para ser conciso y minimizar
el tiempo requerido para ingresar y editar programas. La flexibilidad de C
también puede ser un factor negativo; los programadores que son demasiado
inteligentes para su propio bien pueden hacer que los programas sean casi
imposibles de entender.

#### Los programas en C pueden ser difíciles de modificar

Los programas grandes escritos en C pueden ser difíciles de cambiar si no han
sido diseñados pensando en el mantenimiento. Los lenguajes de programación
modernos suelen proporcionar características como clases y paquetes que soportan
la división de un programa grande en piezas más manejables. C,
desafortunadamente, carece de tales características.

### C obfuscado

Incluso los fans mas acerrimos del lenguaje estan de acuerdo que el lenguaje
puede volverse dificil de leer con facilidad.

Esta "capacidad" del lenguaje se acentua en la competencia anual de código C
obfuscado [IOCC](https://www.ioccc.org/), en la que se buscan las formas más
rebuscadas posibles para crear programas que compilan y funciones pero de la
forma mas enrevesada posible.

El ganador en la categoria "El mejor de una linea" del 2019,
[Dave Burton, Contar palabras](https://www.ioccc.org/2019/burton/index.html)

```c
e,n,j,o,y;main(){for(++o;n=-~getchar();e+=11==n,y++)o=n>0xe^012>n&&'`'^n^65?!n:!o?++j:o;printf("%8d%8d%8d\n",e^n,j+=!o&&y,y);}
```

Como veran, el lenguaje se presta para crear bloques bastante duros.

## El lenguaje en sí, el "Hola Mundo" de C

El primer paso en cualquier lenguaje es el "Hola Mundo". Este simple programa
nos permite entender la estructura básica, la sintaxis y la gramática.

```{code} c
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

### Piezas por pieza

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

6. El código del ejemplo, hace uso de comentarios de linea para ayudarlos a
   ubicar la pieza especifica que se describe en esta lista.

### Compilación y Ejecución

Para ejecutar un programa en C, primero hay que compilarlo. Esto se hace desde
la terminal con un compilador como `gcc`. Y aunque vamos a ver y usar un entorno
gráfico, la consola es el mínimo común denominador.

```{code} sh
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

Si prestamos atención a la instrucción `printf`, vemos que estan faltando dos
caracteres que estan en el programa pero no se ven en la salida. Esto es una
secuencia de control, es la forma de ingresar caracteres que no son visibles, y
el `\n` es el "enter" o salto de linea.

## Sintaxis Básica

La **sintaxis** es el conjunto de reglas que definen cómo debe escribirse el
código para ser considerado válido.

Mientras que la **gramática** determina si el código tiene sentido lógico y
estructural. Es posible que algo sea sintácticamente válido pero gramaticalmente
incorrecto.

### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que damos a variables y funciones. Deben
empezar con una letra o un guion bajo (`_`) y pueden contener letras, números y
guiones bajos. C distingue entre mayúsculas y minúsculas (`suma` es diferente de
`Suma`).

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

Es importante tener en cuenta que hay una forma especifica para cada tipo de
identificador, esto lo iremos viendo a lo largo del curso y esta resumido en las
cuestiones de estilo.

### Variables y Tipos de Datos

En C, todas las variables deben ser declaradas con un tipo de dato específico
antes de ser usadas.

- **Declaración:** `tipo nombre_variable;`
- **Inicialización:** `tipo nombre_variable = valor;`

> **Cuestión de Estilo:** Es una buena práctica declarar una sola variable por
> línea e inicializarla siempre a un valor conocido para evitar comportamientos
> inesperados. `int contador = 0;`

#### Tipos de Datos Primitivos

- **Números Enteros:**

  - `int`: El entero estándar (usualmente 32 bits).
  - `short`: Entero corto.
  - `long`: Entero largo.
  - Pueden ser `signed` (con signo, por defecto) o `unsigned` (sin signo, solo
    positivos).
  - La librería `<stdint.h>` define tipos con tamaño específico como `int32_t` o
    `uint8_t`.

- **Números Reales (Punto Flotante):**

  - `float`: Precisión simple (4 bytes).
  - `double`: Precisión doble (8 bytes).

- **Caracteres:**

  - `char`: Almacena un único carácter (ej: `'a'`). Se encierra entre comillas
    simples.

- **Lógicos (Booleanos):**
  - `bool`: Almacena `true` o `false`. Requiere incluir la librería
    `<stdbool.h>` (estándar desde C99).

> **Nota:** C no tiene un tipo de dato `string` nativo. Las cadenas de texto se
> manejan como arreglos de caracteres, un tema que se verá más adelante.

#### Literales numéricos

Al momento de que nuestro código tenga algún valor numérico concreto, lo podemos
indicar de forma "literal"

- Números enteros
  - Decimal: `1234`
  - Binario: `0b1010`
  - Octal: `0173`
  - Hexadecimal: `0xCAFE`
- Números reales
  - Flotantes: `3.14f;`
  - Double: `3.14;`
- Caracteres: `'A'`
- Lógicos: `true` / `false`

### Salida y Entrada por Consola

#### `printf` (salida)

`printf("cadena de formato", var1, var2, ...);`

Usa códigos de formato para imprimir variables: `%d` para `int`, `%f` para
`double`/`float`, `%c` para `char`. Se pueden imprimir multiples variables en
una única llamada a `printf`.

```c
printf("numero: %d\n caracter:%c", 123, 'a');
```

(En este ejemplo se usan valores literales, que es correcto pero no muy útil)

##### Marcadores de formato comunes

- `%d`, `%i`: int
- `%f`: float
- `%u`: unsigned int
- `%c`: char

##### Secuencias de escape

Una secuencia de escape es una forma de cambiar como el compilador tratará el
siguiente caracter. El código siempre empieza con una barra invertida (\). Este
simbolo indica que hay un tratamiento especial para lo que viene a continuación.

Esto tiene dos propósitos:

- Dar un significado especial a un carácter normal: Por ejemplo, la letra n por
  sí sola es solo una n. Pero si le antepones la barra (`\n`), le estás dando el
  poder especial de crear una nueva línea en el texto. Has "escapado" de su
  significado literal para convertirlo en un comando.

- Quitar el significado especial a un carácter de control: En C, las comillas
  dobles (`"`) se usan para delimitar una cadena de texto. Pero, ¿y si queres
  imprimir unas comillas dobles literalmente? Si directamente usas `"`, el
  compilador va a entender que cadena de texto ha terminado. Para evitarlo, usas
  la secuencia de escape `\"`. La barra invertida le quita el poder de
  "delimitar la cadena" y lo convierte en un simple carácter de comillas para
  imprimir.

- `\n` Nueva Línea (Line Feed), Mueve el cursor al inicio de la siguiente línea.
- `\t` Tabulación Horizontal, Inserta un espacio de tabulación horizontal.
- `\0` Carácter Nulo (NULL), Carácter con valor cero, utilizado como terminador
  en las cadenas de caracteres de C.
- `\\` Barra Invertida, Representa un carácter de barra invertida (`\`).
- `\"` Comillas Dobles, Representa un carácter de comillas dobles (`"`) dentro
  de un literal de cadena.
- `\'` Comilla Simple, Representa un carácter de comilla simple (`'`) dentro de
  un literal de carácter.

#### `scanf` (entrada)

`scanf("%d", &variable);` Lee un valor desde la consola y lo guarda en la
dirección de memoria de una variable. El `&` es fundamental y se explicará para
que está en detalle más adelante.

Utiliza los mismos marcadores de formato que `printf`.

```C
int edad;
scanf("%d", &edad);
```

## Expresiones y Operadores

---

- **Asignación (`=`):** Asigna el valor de la derecha (R-VALUE) a la variable de
  la izquierda (L-VALUE).

- **Aritméticos:** `+`, `-`, `*`, `/`, `%` (módulo/resto).

- **Relacionales:** `==` (igual a), `!=` (distinto de), `>`, `<`, `>=`, `<=`.
  Devuelven `1` (verdadero) o `0` (falso).

- **Lógicos:** `&&` (Y lógico), `||` (O lógico), `!` (NO lógico).

## Estructuras de Control

Permiten alterar el flujo de un programa con decisiones.

:::{card} 🪐 Cuestión de estilo :link:
./estilo.md#regla-0x0005-todas-las-estructuras-de-control-van-con-llaves Todas
las estructuras de control van con llaves, por mas que sean tecnicamente
opcionales. ::: #regla-0x0005-todas-las-estructuras-de-control-van-con-llaves

estilo#regla-0x0013-cada-bloque-lleva-cuatro-espacios-m-s-que-el-que-lo-contiene

### Condicional `if-else`

```C
if (condicion) {
    // Bloque si es verdadero
} else if (otra_condicion) {
    // Bloque alternativo
} else {
    // Bloque si todo lo anterior es falso
}

```

Un ejemplo un poco mas concreto:

```c
if (x > 0) {
    printf("Positivo\n");
} else if (x == 0) {
    printf("Cero\n");
} else {
    printf("Negativo\n");
}
```

### Selección Múltiple `switch`

Útil para comparar una variable con múltiples valores constantes.

```C
switch (expresion) {
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
utilizada para agrupar "casos".

```c
switch (x) {
    case 1:
    case 2:
    case 3:
        printf("Entre 1 y 3\n");
        break;
    default:
        printf("Otro valor\n");
}
```

### Bucles (Lazos)

#### `for`: Lazo definido

Ideal cuando se conoce el número de iteraciones.
`for (inicio; condicion; incremento) { ... }`

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

#### `while`: Lazo indefinido

Se ejecuta mientras la condición sea verdadera. La condición se evalúa al
principio. `while (condicion) { ... }`

```c
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

#### `do-while`: Lazo indefinido invertido

Se ejecuta al menos una vez y luego evalúa la condición al final.
`do { ... } while (condicion);`

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 10);
```

#### Control de flujo dentro de bucles

- `break`: sale del bucle.

- `continue`: salta a la siguiente iteración.

TODO: Agregar ejemplos y detalles

## Funciones

Son bloques de código reutilizables que realizan una tarea específica. Son la
base de la programación estructurada.

### Definición

```C
/**
    * Comentario de documentación explicando qué hace la función.
    * @param parametro1 Descripción del primer parámetro.
    * @return Descripción de lo que retorna.
    */
tipo_retorno nombre_funcion(tipo_param1 nombre_param1) {
    // Cuerpo de la función
    return valor;
}
```

```c
int sumar(int a, int b) {
    return a + b;
}
```

### Llamada (o invocación)

`variable = nombre_funcion(argumento1);`

```c
int resultado = sumar(3, 4);
```

> **Cuestiones de Estilo:** TODO: VINCULAR LAS REGLAS PUNTUALES
>
> - Una función debe tener un único punto de salida (`return`).
>
> - Las funciones no deben interactuar directamente con el usuario (usando
>   `printf` o `scanf`), sino recibir datos a través de sus parámetros y
>   devolver resultados con `return`. Su propósito es procesar, no interactuar.
>
> - Toda función debe tener un comentario de documentación explicando su
>   propósito, parámetros y valor de retorno.

Ejemplo completo de una función con su documentación

```c
/**
 * Suma dos enteros.
 * @param a Primer número
 * @param b Segundo número
 * @return Resultado de la suma
 */
int sumar(int a, int b) {
    return a + b;
}
```

## Bibliografía y Recursos Adicionales

- Kernighan, B. W., & Ritchie, D. M. (1988). _The C Programming Language (2nd
  ed.)_. Prentice Hall. (El libro de referencia por los creadores del lenguaje,
  también conocido como "K&R").

- King, K. N. (2008). _C Programming: A Modern Approach (2nd ed.)_. W. W. Norton
  & Company. (Una excelente alternativa moderna, muy detallada y con buenos
  ejemplos).

## Glosario

:::{glossary} 

Lenguaje Ensamblador
: El lenguaje ensamblador (assembly language)
es un lenguaje de programación de bajo nivel que representa las instrucciones de
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
