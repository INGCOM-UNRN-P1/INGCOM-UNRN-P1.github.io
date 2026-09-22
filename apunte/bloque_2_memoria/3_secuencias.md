---
title: "Secuencias: Arreglos y Cadenas"
short_title: Secuencias
subtitle: "Colecciones de datos homogéneos y texto."
---

> **Prerrequisitos**: variables, lazos, punteros básicos y límites de arreglos.
>
> **Objetivos**: 1. Recorrer un arreglo sin salir de sus límites. 2. Distinguir un arreglo de una cadena terminada en `\0`.
>
> **Comprobación de salida**: predecí el resultado de recorrer una cadena y justificá dónde termina.

(capitulo-secuencias)=
# Secuencias: Arreglos y Cadenas

## Introducción

En C, una **secuencia** es una colección de elementos de datos del mismo tipo,
almacenados en **ubicaciones de memoria contiguas**. Esta organización en
memoria es una de las características que definen el rendimiento de C, ya que
permite al hardware acceder a los datos con una gran eficiencia.

La forma más general de una secuencia es el **arreglo**, que puede contener
cualquier tipo de dato, como `int`, `float` o estructuras más complejas que
veremos más adelante. Aquí, el rol del programador es gestionarlos; definiendo
su tamaño y respetando sus límites, ya que el lenguaje no lo hará por nosotros.

Un caso particular y muy importante es la **cadena de caracteres**. En C, una
cadena no es un tipo de dato especial, sino una **convención**: se trata de un
arreglo de caracteres (`char`) cuyo final se indica con un carácter especial, el
**carácter nulo** (`\0`). Esta convención es la base sobre la que se construye
toda la manipulación de texto en C y también la de algunos problemas.

(arreglos-secuencias-de-datos)=
## Desarrollo

Introducción a las Secuencias en C

### Arreglos: Secuencias de datos

(definicion-y-disposicion-en-memoria)=
#### Definición y Disposición en Memoria

Un **arreglo** es una colección de tamaño fijo de elementos homogéneos. Al
declararlo, el compilador reserva un bloque de memoria continuo y
suficientemente grande para albergar todos sus elementos.

:::{code-block}c

int mi_arreglo[4];

:::
<!-- {code-block}c -->

Esta declaración reserva espacio para 4 enteros. Si un `int` ocupa 4 bytes, la
disposición en memoria es contigua:

:::{figure} 3/array_memory_layout.svg
:label: fig-array-memory-layout
:align: center

Mapeo de un arreglo en la memoria física RAM. Los elementos se ordenan en
bloques contiguos.

:::
<!-- {figure} 3/array_memory_layout.svg -->

Esta contigüidad es lo que permite el acceso indexado (`mi_arreglo[2]`) de forma
casi instantánea.

(2_secuencias-declaracion-e-inicializacion)=
#### Declaración e Inicialización

La declaración de un arreglo sigue la sintaxis `tipo identificador[cantidad];`.

La inicialización define los valores iniciales del arreglo. Es importante
distinguir entre arreglos locales (dentro de una función) y los globales o
estáticos:

- **Arreglos locales no inicializados**: Contienen valores indeterminados
  ("basura"), lo cual viola la regla de estilo {ref}`0x7001h`.
- **Arreglos globales o estáticos no inicializados**: Sus elementos se
  inicializan a cero por defecto.

Formas de inicialización explícita:

:::{figure} 3/array_initialization.svg
:label: fig-array-initialization
:align: center

Inicialización de arreglos en C. Si se omiten elementos, el compilador los
rellena con ceros.

:::
<!-- {figure} 3/array_initialization.svg -->

- **Completa**: `int arr[5] = {10, 20, 30, 40, 50};`
- **Parcial**: `int arr[5] = {10, 20};` (los elementos restantes, `arr[2]` a
  `arr[4]`, se inicializan a `0`).
- **Implícita**: `int arr[] = {10, 20, 30};` (el compilador infiere el tamaño,
  en este caso 3).
- **Inicializadores designados (C99)**: Permite inicializar índices específicos.
  `int arr[5] = {[0] = 10, [4] = 50};` (los no indicados se inicializan a `0`).

(el-operador-sizeof)=
#### El Operador `sizeof`

Para comprender mejor el manejo de memoria de los arreglos, es necesario
introducir el operador `sizeof`.

Este operador es una herramienta de **tiempo de compilación** que devuelve el
tamaño en bytes de un tipo de dato o una variable. Esto es posible por la forma
en la que C crea las variables en la memoria, con un único tipo, los "tipos
estáticos". El valor que retorna es de tipo {term}`size_t`, un tipo de entero
sin signo.

:::{note} El Tipo `size_t`

El tipo `size_t` es un entero sin signo definido en el estándar C para
representar el tamaño de cualquier objeto en memoria (en bytes) y para indexar
arreglos de manera segura. Su tamaño físico se adapta automáticamente a la
arquitectura de la computadora (generalmente 32 o 64 bits).

:::
<!-- {note} El Tipo `size_t` -->

::::{code-block}c
:linenos:
int numeros[10];
// sizeof(int) -> Devuelve el tamaño de un entero (4 bytes)
// sizeof(numeros[0]) -> Devuelve el tamaño de los elementos del arreglo (4
bytes)
// sizeof(numeros) -> Devuelve el tamaño total del arreglo (40 bytes)

::::
<!-- {code-block}c -->

Esto nos permite calcular la cantidad de elementos de un arreglo de una forma
simple, esto es de suma importancia en C, ya que los arreglos no guardan su
tamaño.

::::{code-block}c
:linenos:
// Funciona incluso si cambiamos 'numeros' a 'long numeros[]'.
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
// La cuenta es, el tamaño total del arreglo / el tamaño de un elemento.
// Qué aplicado al arreglo anterior, nos debiera dar 10.

::::
<!-- {code-block}c -->

Teniendo en cuenta que los tamaños de los tipos básicos como `int` o `long`,
pueden cambiar de tamaño entre compiladores.

::::{code-block}c
:linenos:
#include <stdio.h>
int main(void)
{
    printf("Tamaño de char: %zu bytes\n", sizeof(char));
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de float: %zu bytes\n", sizeof(float));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    printf("Tamaño de long long: %zu bytes\n", sizeof(long long));
    return 0;
}

::::
<!-- {code-block}c -->

La salida de este código en una computadora de escritorio actual sería:

``` text
Tamaño de char: 1 bytes
Tamaño de int: 4 bytes
Tamaño de float: 4 bytes
Tamaño de double: 8 bytes
Tamaño de long long: 8 bytes
```
<!-- text -->

Una característica del lenguaje C es que los tamaños de sus tipos de datos
numéricos pueden variar entre diferentes arquitecturas de hardware. El operador
`sizeof` permite escribir código portable que no dependa de un tamaño de tipo de
dato fijo, facilitando la adaptación del software a distintas plataformas.

Por ejemplo, históricamente, un `int` en sistemas de 16-bits ocupa 2 bytes,
mientras que en sistemas de 32-bits o 64-bits, comúnmente ocupa 4 bytes.

El uso de `sizeof` es crucial en la gestión de memoria dinámica, un tema que se
abordará más adelante.

::::{note}

Para imprimir un valor de tipo {term}`size_t` con `printf`, se utiliza el
especificador de formato `%zu`. El uso de `%d` o `%lu` puede provocar
advertencias del compilador debido a posibles inconsistencias de tipo.

::::
<!-- {note} -->







---

(acceso-modificacion-y-la-identidad-del-arreglo)=
#### Acceso, Modificación y la Identidad del Arreglo

Se accede a los elementos mediante el operador de subíndice `[]`, donde el
índice va de `0` a `cantidad - 1`.

##### Acceso (lectura)

Para leer el valor de un elemento, se utiliza el operador de subíndice `[]` con
el índice del elemento deseado. Es importante recordar que los índices en C
comienzan en cero. Una expresión de acceso como `miArreglo[i]` es un "r-value",
ya que representa un valor que puede ser leído.

Por ejemplo `int valor = mi_arreglo[3];`. Aquí, `mi_arreglo[3]` nos permite
acceder al valor de la cuarta posición.

:::{code-block}c
:linenos:
int calificaciones[5] = {10, 8, 9, 7, 10};
// Obtener el valor del primer elemento (índice 0)
int primera = calificaciones[0];
// Obtener el valor del cuarto elemento (índice 3)
int cuarta = calificaciones[3];
printf("La primera calificación es: %d\n", primera);
printf("La cuarta calificación es: %d\n", cuarta);
printf("Acceso directo al segundo elemento: %d\n", calificaciones[1]);

:::
<!-- {code-block}c -->

Salida:

``` text
La primera calificación es: 10
La cuarta calificación es: 7
Acceso directo al segundo elemento: 8
```
<!-- text -->

##### Modificación (escritura)

Para escribir un nuevo valor en un elemento, la expresión de subíndice
`mi_arreglo[i]` se coloca en el lado izquierdo de una operación de asignación.
En este contexto, la expresión es un "l-value", ya que representa una ubicación
de memoria modificable.

Por ejemplo, `mi_arreglo[3] = 100;`. Acá, `mi_arreglo[3]` nos permite modificar
el cuarto valor de la secuencia.

:::{code-block}c
:linenos:
int edades[4] = {20, 25, 22, 28};
// 1. Mostrar el valor original del tercer elemento (índice 2)
printf("La edad original en el índice 2 es: %d\n", edades[2]);
// 2. Modificar el valor en el índice 2. 'edades[2]' es un l-value.
edades[2] = 23;
// 3. Mostrar el valor modificado. 'edades[2]' se evalúa como un r-value.
printf("La nueva edad en el índice 2 es: %d\n", edades[2]);

:::
<!-- {code-block}c -->

Salida:

``` text
La edad original en el índice 2 es: 22
La nueva edad en el índice 2 es: 23
```
<!-- text -->

##### Identidad

El identificador de un arreglo, como `mi_arreglo`, es especial. No es una
variable que _contiene_ el arreglo, sino que está **permanentemente asociado con
la dirección de memoria del primer elemento de esa secuencia**. Por esta razón,
no se puede reasignar para que se refiera a otra secuencia. La operación
`arr1 = arr2;` es ilegal. Para copiar los valores, se debe recorrer y copiar
cada elemento, uno por uno.

El identificador de un arreglo es una constante que representa la dirección de
inicio del bloque de memoria asignado. Por esta razón, el nombre de un arreglo
es un **l-value no modificable**.

::::{code-block}c
:linenos:
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {10, 20, 30, 40, 50};
// La siguiente línea es ilegal y causará un error de compilación.
arr1 = arr2; // Error: expression is not assignable.

::::
<!-- {code-block}c -->

(recorrido-de-arreglos-y-comportamiento-indefinido)=
#### Recorrido de Arreglos y Comportamiento Indefinido

La estructura de control ideal para iterar sobre un arreglo es el lazo `for`.
El uso de `size_t` para el índice del lazo es la forma correcta de hacerlo, tal
como lo indica la regla de estilo {ref}`0x3010h`.

::::{code-block}c
:linenos:
int numeros[] = {10, 20, 30, 40, 50};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
for (size_t i = 0; i < cantidad; i++)
{
    printf("Elemento %zu: %d\n", i, numeros[i]);
}

::::
<!-- {code-block}c -->

::::{warning} Cuestiones de límites

C no verifica los límites del arreglo. Acceder a un índice fuera del rango
(`numeros[5]` o `numeros[-1]`) resulta en **comportamiento indefinido**. Esto no
siempre causa un error inmediato. Podría corromper datos de otras variables,
causar fallos de seguridad o funcionar aparentemente bien hasta que un cambio
trivial en otra parte del código revele el error latente. Es responsabilidad del
programador garantizar que esto no ocurra, como lo exige la regla
{ref}`0x300Ch`.

::::
<!-- {warning} Cuestiones de límites -->

(arreglos-de-longitud-variable-alv-vla)=
#### Arreglos de Longitud Variable (ALV/VLA)

Desde el estándar C99, C permite declarar arreglos cuyo tamaño se determina en
tiempo de ejecución. Estos se conocen como {abbr}`ALV (Array Largo Variable)` o
{abbr}`VLA (Variable Length Array)` (en Inglés).

::::{code-block}c
:linenos:
int cantidad = 0;
printf("Ingrese el tamaño del arreglo:\n");
scanf("%d", &cantidad);
int arreglo[cantidad]; // Declaración de un VLA
printf("El tamaño del arreglo en bytes es: %zu\n", sizeof(arreglo));
// El resultado será sizeof(int) * cantidad

::::
<!-- {code-block}c -->

Estos tienen limitaciones importantes. Por ejemplo, un ALV no puede ser
inicializado en su declaración. Intentarlo producirá un error de compilación:

``` text
error: variable-sized object may not be initialized
```
<!-- text -->

Las implicaciones y el uso correcto de la memoria dinámica, que es la
alternativa recomendada a los ALV, se abordarán en [Memoria
Dinámica](5_memoria_dinamica.md).

De todas formas y como se imaginarán, hay una regla de estilo {ref}`0x5001h`.

(el-mecanismo-de-paso-a-funciones-paso-por-referencia-simulado)=
#### El Mecanismo de Paso a Funciones: Decaimiento de Arreglos

En C, **todo pasaje de parámetros se realiza estrictamente por valor** (copia
física en el Stack Frame). Sin embargo, los arreglos poseen un comportamiento
físico particular al ser transmitidos a una función: el compilador no realiza
una copia de todos los elementos del arreglo en el registro de activación de la
función receptora.

En su lugar, el nombre del arreglo **decae implícitamente a un puntero** que
almacena la dirección de memoria de su primer elemento (es decir, `arr` se
evalúa como `&arr[0]`). Lo que recibe la función en su Stack Frame es una copia
por valor de ese puntero (dirección física).

Como consecuencia, cualquier lectura o modificación que la función realice sobre
los elementos utilizando el operador de indexación (`[]`) afectará de forma
directa e inmediata a los datos originales en la memoria del programa, logrando
una **simulación de pasaje por referencia mediante indirección**.

:::{note} El concepto subyacente: Aritmética de Punteros

Este mecanismo requiere comprender cómo se organizan las direcciones de memoria
físicas y el operador de indirección `*`. Para profundizar en estos conceptos,
consultá el capítulo de {ref}`capitulo-punteros` en [](2_punteros.md).

:::
<!-- {note} El concepto subyacente: Aritmética de Punteros -->

:::{figure} 3/degradacion_puntero.svg
:label: fig-degradacion-puntero
:align: center
:width: 90%

Decaimiento físico de un arreglo a puntero al ser pasado a una función. El
parámetro `ptr` en el Stack Frame de la función `mostrar` recibe una copia del
valor de la dirección física del inicio del arreglo `0x7FFEE100`.

:::
<!-- {figure} 3/degradacion_puntero.svg -->

(funciones-puras-y-con-efectos-secundarios)=
#### Funciones Puras y con Efectos Secundarios

Al trabajar con secuencias, la distinción entre funciones puras y aquellas con
efectos secundarios (ver {ref}`funciones-puras-y-con-efectos-secundarios`)
adquiere una relevancia
crítica debido al mecanismo de pasaje de parámetros en C. Como los arreglos se
transmiten mediante su dirección de memoria (paso por referencia simulado), las
funciones pueden modificar su contenido directamente en el invocador.

##### Funciones puras sobre arreglos

Una función que opera sobre arreglos es pura si se limita a leer sus elementos
sin alterar el contenido original. Para indicar explícitamente esta intención y
garantizar la portabilidad y seguridad, se debe usar el calificador `const` en
el parámetro del arreglo (ver regla de estilo {ref}`0x3007h`).

**Ejemplo de función pura:**

```{code-block} c
:linenos:
int maximo(const int valores[], size_t cantidad)
{
    int max = valores[0];
    for (size_t i = 1; i < cantidad; i++)
    {
        if (valores[i] > max)
        {
            max = valores[i];
        }
    }
    return max;
}

```
<!-- {code-block} c -->

Esta función sólo **lee** el contenido del arreglo y **devuelve** un resultado.
No altera el contenido original.

##### Funciones con efectos secundarios en arreglos

Una función con efectos secundarios modifica el contenido del arreglo original.
En este caso, el parámetro de arreglo no debe llevar el calificador `const`.

**Ejemplo de función con efectos secundarios:**

```{code-block} c
:linenos:
void ordenar(int v[], size_t cantidad)
{
    for (size_t i = 0; i < cantidad - 1; i++)
    {
        for (size_t j = 0; j < cantidad - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

```
<!-- {code-block} c -->

Esta función cambia el contenido del arreglo original; su ejecución modifica el
estado de la secuencia en el invocador.

##### ¿Por qué distinguirlas?

- **Legibilidad**: un lector puede asumir que una función pura no altera nada,
  lo que simplifica su comprensión.
- **Reutilización**: las funciones puras son más fáciles de testear y componer.
- **Depuración**: los errores son más fáciles de rastrear si las funciones
  tienen efectos bien delimitados.

##### Buenas prácticas

- Usá funciones puras para cálculo, conteo o análisis.
- Reservá funciones con efectos para inicialización, transformación explícita o
  lazo de interacción con el entorno.
- Documentá claramente qué efectos tiene cada función.
- Cuando una función modifica su entrada, elegí un nombre que lo indique:
  `normalizar`, `ordenar`, `ajustar`, etc.

##### Estrategia mixta

En algunos casos, puede ser útil definir **una función pura** que calcule un
resultado y **otra función con efectos** que lo aplique.

Por ejemplo:

:::{code-block}c
:linenos:
int encontrar_maximo(const int v[], int cantidad);
void imprimir_maximo(const int v[], int cantidad)
{
    int m = encontrar_maximo(v, cantidad);
    printf("El máximo es %d\n", m);
}

:::
<!-- {code-block}c -->

Esta separación permite testear `encontrar_maximo` independientemente de la
función que interactúa con el usuario.

Esto explica dos situaciones clave:

##### Efectos secundarios en arreglos

Al recibir la "dirección de la casa", los cambios en el arreglo que pasamos a la
función, se reflejan en el arreglo original, efectivamente dando un resultado
por fuera del _retorno_ explícito de la función.

Esta situación se puede dar cuando utilizamos al arreglo como una variable más.

:::{code-block}c
:caption: Contraejemplo con efectos secundarios destructivos
:emphasize-lines: 4
:linenos:
int maximo(int arreglo[], size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (arreglo[i] > arreglo[0])
        {
            arreglo[0] = arreglo[i];
        }
    }
    return arreglo[0];
}

:::
<!-- {code-block}c -->

El problema principal del código es el efecto secundario **destructivo**. La
función no solo calcula el valor máximo, sino que también modifica de manera
irreversible el arreglo que se le pasa como argumento.

Este tipo de comportamiento puede llevar a errores sutiles y difíciles de
depurar, especialmente en programas grandes donde el arreglo original podría ser
necesario para operaciones posteriores. Por ejemplo, si el valor original en la
posición `0` fuera crucial para otro cálculo, esa información se perdería
permanentemente. Para evitar modificaciones no deseadas, es una buena práctica
usar el calificador `const` en los parámetros de arreglo que no deben ser
alterados, adhiriendo a la regla de estilo {ref}`0x3007h`.

Resolver este problema solo requiere agregar una variable para reemplazar
`arreglo[0]`, pero es un buen contraejemplo de un uso negativo de los efectos
secundarios de los arreglos.

Si la función (o procedimiento) modifica el arreglo, esto debe estar claramente
expresado en la documentación.

Aunque parezca algo negativo, la utilización de efectos secundarios en arreglos
es sumamente importante y se utiliza en código que, por ejemplo, ordene los
valores que contiene.

##### Pérdida de `sizeof`

Dentro de la función, `sizeof(arreglo)` no funciona como se espera. La función
solo conoce la dirección en memoria del arreglo, no el tamaño total de la
secuencia original.

:::{code-block}c
:linenos:
/**
 * Esta funcion, ¡no cumple con su objetivo!
 * para cualquier arreglo que le pasemos;
 * ¡vamos a obtener el mismo valor!
 */
size_t obtener_tamanio(int arreglo[])
{
    printf("Tamaño del arreglo: %zu\n", sizeof(arreglo));
    // El arreglo es siempre de tamaño 8 (la dirección)
    printf("Tamaño de un valor: %zu\n", sizeof(arreglo[0]));
    // El valor apuntado va a ser siempre `int` con 4 bytes.
    return sizeof(arreglo) / sizeof(arreglo[0]);
}
int main(void)
{
    int arreglo1[] = {10, 20, 30, 40, 50};
    int arreglo2[20];
    size_t uno = obtener_tamanio(arreglo1);
    size_t dos = obtener_tamanio(arreglo2);
    printf("Tamaño de arreglo1: %zu\n", uno); // obtenemos 2
    printf("Tamaño de arreglo2: %zu\n", dos); // obtenemos 2
    return 0;
}

:::
<!-- {code-block}c -->

Esta situación se explica porque, teniendo en cuenta que `sizeof` se resuelve en
tiempo de compilación, el operador no puede saber con qué arreglo vamos a llamar
a la función.

Por lo tanto, para que una función pueda trabajar sobre cualquier arreglo, se
debe pasar el tamaño de forma explícita, como un argumento separado. La firma
correcta de la función debe incluir el tamaño del arreglo como parámetro. El uso
de `size_t` para el tamaño ({ref}`0x3010h`) y el hecho de pasar el tamaño
explícitamente ({ref}`0x300Ch`) son cruciales para la seguridad y portabilidad.

::::{code-block}c
:linenos:
/**
 * Imprime los elementos de un arreglo de enteros en la salida estándar.
 *
 * @param arreglo de números a mostrar.
 * @param size    la cantidad de valores en el arreglo.
 *
 * @post
 * - Los elementos del arreglo `arreglo` se han impreso.
 * - El `arreglo` no será modificado.
 */
void imprimir_arreglo(int arreglo[], size_t size);

::::
<!-- {code-block}c -->

::::{note} Uso de {term}`size_t`

Aunque no es estrictamente necesario que sea de tipo {term}`size_t`, su uso se
recomienda porque este tipo se asocia al tamaño o las 'dimensiones' de las
cosas.

::::
<!-- {note} Uso de {term}`size_t` -->

(retorno-de-secuencias-desde-funciones)=
#### Retorno de Secuencias desde Funciones

Una función **no puede retornar un arreglo local**. Las variables de un arreglo
local se alojan en el registro de activación (*stack frame*) de la función en la
pila. Al ejecutarse la instrucción de retorno, el registro de activación de la
función se desapila y destruye de forma física en memoria lógica, quedando ese
espacio disponible para ser sobrescrito por cualquier llamada subsiguiente en el
programa. Intentar acceder a la dirección de memoria de un objeto local que ya
ha sido liberado del stack constituye una desreferenciación de puntero colgante
y provoca comportamiento indefinido o fallas de segmentación.








---

(cadenas-secuencias-de-caracteres)=
### Cadenas: Secuencias de Caracteres

Una cadena es un arreglo de `char` que sigue una regla: el último carácter de
interés está seguido por un **carácter nulo (`\0`)**. Este terminador es
crucial, ya que las funciones de biblioteca como `strlen` o `printf` con `%s`
dependen de él para saber dónde termina el texto.

El comportamiento general de una cadena es el mismo que el de un arreglo.

Por ejemplo, la siguiente cadena:

:::{code-block}c

char cadena[7] = "Hola";

:::
<!-- {code-block}c -->

:::{figure} 3/string_null_terminator.svg
:name: fig-string-null-terminator
:width: 100%

Representación en memoria de una cadena con terminador nulo. La cadena "Hola"
ocupa 5 bytes (4 caracteres + '\0'), pero el arreglo tiene capacidad para 7. Los
bytes no inicializados contienen basura. El terminador '\0' marca el fin lógico
de la cadena y es esencial para las funciones de string.h.

:::
<!-- {figure} 3/string_null_terminator.svg -->

En donde los `?` _quizás_ sean cero (`\0`), pero como no está inicializado, no
podemos estar seguros del valor que tendrá, a todos los efectos prácticos, es
basura.

También, si aplicamos el cálculo de tamaño usando `sizeof` que vimos antes,
vamos a obtener el tamaño en bytes de la cadena.

:::{code-block}c

size_t espacio_reservado = sizeof(mi_cadena) / sizeof(mi_cadena[0]);

:::
<!-- {code-block}c -->

Esto coincide con el largo del arreglo, ya que en el estándar del lenguaje C, el
operador `sizeof(char)` es siempre igual a `1` por definición. El byte en C es,
precisamente, el tamaño de almacenamiento físico de un `char`. Esto es
independiente de la estrategia de codificación de caracteres empleada por la
plataforma (como ASCII o UTF-8), garantizando la portabilidad de este cálculo.

Por lo tanto, el `espacio_reservado` tendría `7`, y no el largo de la cadena que
es `4`.

(inicializacion-de-una-cadena)=
#### Inicialización de una cadena

Al declarar una cadena usando la sintaxis de arreglo, estás creando una copia
local y mutable del texto basada en el {term}`literal de cadena`; el texto entre
comillas dobles (`"`), sumando un carácter más para el terminador `\0`.

```` c
char mi_cadena[] = "Texto inicial";
````
<!-- c -->

Es sumamente importante destacar que los literales, que no están asignados a una
variable arreglo (`char []`), **no pueden ser modificados**. Esto significa que
nuestros programas no funcionaran si pasamos como argumento un literal a una
función que modifica dicha cadena.

:::{code-block}c
:caption: Modificando cadenas
:linenos:
void ordena_caracteres(char cadena[])
{
    size_t n = strlen(cadena);
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (cadena[j] > cadena[j + 1])
            {
                char temp = cadena[j];
                cadena[j] = cadena[j + 1];
                cadena[j + 1] = temp;
            }
        }
    }
}
int main(void)
{
    char mi_cadena[] = "ejemplo de cadena desordenada";
    printf("Cadena original: \"%s\"\n", mi_cadena);
    // Llama a la función para ordenar la cadena.
    ordena_caracteres(mi_cadena);
    printf("Cadena ordenada: \"%s\"\n", mi_cadena);
    // Además, ¿en dónde modificamos la cadena?
    ordena_caracteres("ejemplo de cadena desordenada");
    return 0;
}

:::
<!-- {code-block}c -->

Y la salida sería:

``` text
:linenos:
:emphasize-lines: 3
Cadena original: "ejemplo de cadena desordenada"
Cadena ordenada: "   aaaacdddddeeeeeejlmnnooprs"
Segmentation fault (core dumped)
```
<!-- text -->

Ese `Segmentation fault (core dumped)` resulta de intentar modificar algo que no
debía ser modificado, por lo que es importante utilizar una variable de cadena
intermedia para evitar este tipo de errores.

Más adelante veremos detalles adicionales sobre los literales de cadena y qué
situaciones nos podemos encontrar si no los utilizamos con cuidado.

(largo-de-cadenas)=
#### Largo de cadenas

Para obtener el largo de una cadena, podemos usar `strlen`, definido en
`<string.h>`.

Esta función está definida de la siguiente forma:

:::{code-block}c

size_t strlen(const char str[]);

:::
<!-- {code-block}c -->

Y se encarga de recorrer la cadena hasta encontrarse un carácter nulo (`\0`)

[Más información sobre
`strlen`](https://en.cppreference.com/w/c/string/byte/strlen)

::::{note} Largo vs. capacidad

Es muy importante tener en cuenta que las cadenas tienen dos "tamaños"
diferentes.

:::{figure} 3/string_length_vs_capacity.svg
:name: fig-string-length-vs-capacity
:width: 100%

Diferencia entre largo y capacidad: el largo (strlen) cuenta los caracteres
hasta '\0' (sin incluirlo), mientras que la capacidad (sizeof) es el tamaño
total del arreglo en memoria. La capacidad debe ser siempre mayor al largo para
incluir el terminador nulo. Esta distinción es fundamental para operaciones
seguras con cadenas.

:::
<!-- {figure} 3/string_length_vs_capacity.svg -->

Tenemos, por un lado, el largo, que es la cantidad de caracteres hasta el
terminador.

Por otro, tenemos el tamaño en memoria del arreglo de caracteres que guarda la
cadena, que debiera ser, por lo menos, uno más que el largo de la cadena. A esta
dimensión la llamaremos "capacidad".

Esta es la base para las cadenas seguras.

::::
<!-- {note} Largo vs. capacidad -->







---

(lectura-segura-de-cadenas)=
#### Lectura Segura de Cadenas

El uso de `scanf("%s", buffer)` y `gets()` constituye una de las mayores
vulnerabilidades de seguridad en lenguaje C. La alternativa segura y exigida es
`fgets`, de acuerdo con la regla de estilo {ref}`0x5006h`.

:::{warning} Vulnerabilidad Crítica: Desbordamiento de Búfer

La función estándar `gets()` fue removida de forma definitiva en el estándar C11
debido a que **no verifica el límite de almacenamiento del búfer de destino**.
Similarmente, `scanf("%s", ...)` lee datos de la entrada estándar y los escribe
en memoria de forma descontrolada hasta encontrar un espacio en blanco o una
nueva línea. Si el usuario ingresa una cadena de longitud mayor al tamaño
reservado, se produce un **desbordamiento de búfer** (*buffer overflow*),
sobrescribiendo celdas de variables contiguas o alterando la dirección de
retorno en el Stack Frame.

:::
<!-- {warning} Vulnerabilidad Crítica: Desbordamiento de Búfer -->

:::{code-block}c
:linenos:
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100
void leer_entrada(void)
{
    char buffer[BUFFER_SIZE];
    printf("Ingrese su nombre: ");
    // fgets garantiza que no se lean más bytes que el tamaño máximo del búfer
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        // Remover el '\n' si fue capturado
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        printf("Nombre ingresado: %s\n", buffer);
    }
}

:::
<!-- {code-block}c -->

(biblioteca-estandar-string-h-un-vistazo-rapido)=
#### Biblioteca Estándar `<string.h>`: Un Vistazo Rápido

Las funciones de biblioteca para manipular cadenas más importantes:

- `strcpy(dest, src)`: Copia `src` en `dest`, incluyendo `\0`. No comprueba el
  tamaño de `dest`, siendo muy peligrosa.
- `strncpy(dest, src, n)`: Copia hasta `n` caracteres. **Cuidado**: si la
  longitud de `src` es `n` o más, **no añade el `\0`**. La terminación nula debe
  ser asegurada manualmente.
- `strcmp(s1, s2)`: Compara las cadenas carácter por carácter según su valor
  numérico. Devuelve `<0` si `s1<s2`, `0` si son iguales, y `>0` si `s1>s2`.
- `strcat(dest, src)`: Busca el `\0` en `dest` y copia `src` a partir de ahí.
  También es insegura por no verificar el tamaño.

[Más información sobre
`string.h`](https://en.cppreference.com/w/c/header/string.html)
y otras funciones disponibles.



---

(cadenas-seguras-el-dilema-del-nul)=
### Cadenas Seguras: El Dilema del NUL

El modelo de cadenas de C —terminadas en `'\0'` sin información de longitud— es
una fuente histórica de vulnerabilidades. La Regla {ref}`0x5004h` exige usar
operaciones seguras. Esta sección fundamenta por qué.

Las cadenas de caracteres en el lenguaje C son una de sus características más
fundamentales y, a la vez, una de sus mayores fuentes de vulnerabilidades de
seguridad. Entender su diseño histórico es clave para comprender por qué son
inseguras y por qué surgieron las "cadenas seguras".

(cadenas-tradicionales-en-c-el-legado-del-nul)=
### Cadenas Tradicionales en C: El Legado del `NUL`

(historia-y-diseno)=
#### Historia y Diseño

Cuando Dennis Ritchie y Ken Thompson diseñaron el lenguaje C en la década de
1970, lo hicieron pensando en la eficiencia y el hardware de la época (como la
PDP-11). Los recursos eran extremadamente limitados. Para representar una
secuencia de caracteres, adoptaron una convención simple y eficaz:

- Una cadena es una **secuencia contigua de bytes (caracteres) en memoria.**

- El final de la cadena se marca con un **carácter nulo (`\0`)**.

Este estilo se conoce como **cadena terminada en nulo** (o _null-terminated
string_). Por ejemplo, la cadena "HOLA" se almacena en memoria como:

| `H` | `o` | `l` | `a` | `\0` |
| --- | --- | --- | --- | ---- |

Esta simplicidad era genial para los sistemas de esa era. No se necesitaba
almacenar metadatos adicionales como la longitud; la función que leía la cadena
simplemente avanzaba hasta encontrar el `\0`.

(la-raiz-de-la-inseguridad-ausencia-de-informacion-de-tamano)=
#### La Raíz de la Inseguridad: Ausencia de Información de Tamaño

La principal debilidad de este diseño es que la propia cadena **no sabe cuál es
su longitud ni la capacidad del buffer que la contiene**. Para obtener su
longitud, una función como `strlen()` debe recorrerla carácter por carácter
desde el inicio hasta encontrar el `\0`, una operación de complejidad $O(n)$.

El verdadero peligro surge con funciones de manipulación como `strcpy()`
(copiar), `strcat()` (concatenar) o `gets()` (leer desde la entrada estándar).
Estas funciones escriben datos en una memoria destino **asumiendo ciegamente que
hay espacio suficiente**.

##### El Ataque Clásico: Buffer Overflow (Desbordamiento de Búfer)

Imagina este código:

:::{code-block}c
:linenos:
#include <stdio.h>
#include <string.h>
void vulnerable()
{
    char buffer_pequeno[10]; // Buffer con capacidad para 9 caracteres + \0
    char entrada_maliciosa[] = "AAAAAAAAAAAAAAAAAAAA"; // 20 caracteres
    // strcpy no sabe que buffer_pequeno solo tiene 10 bytes.
    // Copiará los 20 caracteres de la entrada, más el \0.
    strcpy(buffer_pequeno, entrada_maliciosa);
    printf("Contenido del buffer: %s\n", buffer_pequeno);
}

:::
<!-- {code-block}c -->

Al ejecutar `strcpy()`, se escriben 21 bytes (`20` 'A' más el `\0`) en un
espacio de solo `10` bytes. Los 11 bytes extra se escriben fuera de los límites
del `buffer_pequeno`, **sobrescribiendo otras áreas de la memoria** en el stack.

Esto puede causar desde un simple fallo del programa hasta las peores
vulnerabilidades de seguridad, como la **ejecución de código arbitrario**, si un
atacante diseña la `entrada_maliciosa` para sobrescribir la dirección de retorno
de la función con la dirección de su propio código malicioso.

(cadenas-seguras-la-solucion-del-tamano-explicito)=
### Cadenas Seguras: La Solución del Tamaño Explícito

Para solucionar estos problemas, surgieron las "cadenas seguras". El concepto
fundamental es simple pero poderoso: **la estructura de datos de la cadena debe
contener información sobre su tamaño**.

Una cadena segura generalmente almacena dos piezas clave de metadatos junto a
los datos de los caracteres:

1. **Longitud (length):** El número actual de caracteres en la cadena.

1. **Capacidad (capacity):** El tamaño total del bloque de memoria asignado para
   la cadena, indicado como un `size_t`.

Con esta información, cualquier operación de escritura puede verificar primero
si `longitud < capacidad`.

(ventajas-clave-de-las-cadenas-seguras)=
#### Ventajas Clave de las Cadenas Seguras

- **Seguridad:** Previenen los desbordamientos de búfer por diseño. Las
  funciones de copia o concatenación pueden negarse a operar o redimensionar el
  búfer si no hay espacio suficiente.

- **Eficiencia:** Obtener la longitud de la cadena es una operación instantánea
  (O(1)), ya que el valor está almacenado y no necesita ser calculado.

- **Compatibilidad Binaria:** Pueden almacenar datos que contienen caracteres
  nulos (`\0`) en medio de la secuencia, ya que el final no está determinado por
  el `\0`, sino por el campo de longitud.

(implementaciones-y-alternativas)=
#### Implementaciones y Alternativas

Existen varias formas de implementar cadenas seguras en C y otros lenguajes.

##### **1. Anexo K de C11 (Funciones `_s`)**

El estándar C11 introdujo un anexo opcional (Anexo K) con versiones "seguras" de
las funciones de cadena tradicionales. Estas funciones, como `strcpy_s()`,
`strcat_s()` y `snprintf_s()`, generalmente toman un argumento adicional: el
tamaño del búfer de destino.

:::{code-block}c
:linenos:
// Ejemplo con strcpy_s
char buffer[10];
const char *origen = "Texto largo";
// strcpy_s verifica que el tamaño del buffer (10)
// es suficiente para copiar el origen.
// En este caso, devolvería un error en lugar de desbordar.
errno_t resultado = strcpy_s(buffer, sizeof(buffer), origen);
if (resultado != 0)
{
    // Manejar el error de copia
}

:::
<!-- {code-block}c -->

**Problema:** Este anexo es **opcional** y su adopción ha sido muy limitada.
Compiladores populares como GCC y Clang no lo implementan por defecto, y la
comunidad lo ha criticado por su diseño y usabilidad. Microsoft sí lo implementa
en su compilador MSVC.

##### 2. Bibliotecas de Terceros (La Solución Práctica en C)

La forma más común y recomendada de usar cadenas seguras en C es a través de
bibliotecas de alta calidad.

- **Simple Dynamic Strings (SDS):** Es una de las más populares, creada para el
  proyecto Redis. Es extremadamente eficiente y fácil de usar. La estructura de
  SDS almacena la longitud y la capacidad en una cabecera justo antes del
  puntero a los datos, lo que la hace compatible con funciones C que esperan un
  `char*`.

:::{code-block}c
:linenos:
// Ejemplo (conceptual) de uso de SDS
#include "sds.h"
sds mi_cadena = sdsnew("Hola ");              // Crea una nueva cadena SDS
mi_cadena = sdscat(mi_cadena, "Mundo!");      // Concatena de forma segura
printf("%s\n", mi_cadena);                    // Imprime "Hola Mundo!"
printf("Longitud: %zu\n", sdslen(mi_cadena)); // Obtiene la longitud en O(1)
sdsfree(mi_cadena);                           // Libera la memoria

:::
<!-- {code-block}c -->

- **The Better String Library (bstring):** Otra biblioteca robusta y bien
  establecida que ofrece un enfoque similar a SDS.

(tabla-comparativa)=
#### Tabla Comparativa

| Característica         | Cadenas NUL-Terminadas                              | Anexo K de C11 (`_s`)                                 | Bibliotecas (SDS) / C++ `std::string`            |
| ---------------------- | --------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------ |
| **Seguridad**          | **Muy Baja** (propensa a overflows)              |  **Mejorada** (requiere disciplina del programador) |  **Alta** (seguridad por diseño)               |
| **Obtener Longitud**   | O(n) - Lento                                        | O(n) - Lento                                          | O(1) - Instantáneo                               |
| **Gestión de Memoria** | Manual y propensa a errores                         | Manual (el programador provee el buffer)              | Automática y gestionada por la biblioteca/objeto |
| **Facilidad de Uso**   | Simple para tareas básicas, compleja para seguridad | Verbosa y propensa a errores de uso                   | Muy alta, interfaz de alto nivel                 |
| **Datos Binarios**     |  **No** (el `\0` actúa como terminador)           |  **No**                                             |  **Sí** (la longitud determina el final)       |

(conclusion)=
#### Conclusión

Aunque las cadenas tradicionales de C son un pilar histórico de la programación
de sistemas, su diseño es inherentemente inseguro para el desarrollo de software
moderno. Ignorar la información sobre el tamaño del búfer fue una decisión
comprensible en su momento, pero ha sido la causa de innumerables
vulnerabilidades.

(2_secuencias-conexion-con-el-siguiente-tema)=
### Conexión con el Siguiente Tema

Los arreglos que estudiamos tienen una limitación crítica: **tamaño fijo
determinado en compilación**. Si declaramos `int arr[100]`, consumimos memoria
para 100 enteros incluso si solo usamos 10. Si necesitamos 101, el programa no
compila. Esta rigidez es problemática para software real que debe adaptarse a
cantidades variables de datos.

Además, cuando pasamos arreglos a funciones, vimos que en realidad estamos
pasando **la dirección del primer elemento**. ¿Qué significa "dirección"? ¿Cómo
manipulamos estas direcciones directamente?

El próximo tema introduce conceptos que profundizan en cómo se organiza y
manipula la memoria:

- Los **punteros** ([Punteros](2_punteros.md)) como variables que almacenan
  direcciones
- Las **matrices** ([Matrices](../bloque_3_algoritmos_estructuras/1_matrices.md))
  como arreglos multidimensionales
- La **gestión de memoria** ([Memoria
  Dinámica](5_memoria_dinamica.md)) para
  estructuras dinámicas

Los punteros son el concepto más poderoso y peligroso de C. Dominando punteros y
arreglos simultáneamente, se comprende la esencia del lenguaje: **control
directo sobre la memoria** con la sintaxis mínima necesaria.

**Pregunta puente**: Cuando escribimos `int arr[5]`, ¿dónde exactamente en la
memoria se almacenan estos 5 enteros? ¿Cómo accede la CPU a `arr[3]`? La
respuesta requiere entender direcciones de memoria, lo que nos lleva
naturalmente a los punteros.

(2_secuencias-textos-fundamentales)=
#### Textos Fundamentales

- {cite:t}`kernighan_c_2014`. Capítulo 5: Pointers and Arrays. La relación
  fundamental entre punteros y arreglos.

- {cite:t}`king_c_2008`. Capítulo 8: Arrays y Capítulo 13: Strings. Funciones de
  biblioteca y manipulación de cadenas.

- {cite:t}`weiss_data_2014`. Capítulo 3: Lists, Stacks, and Queues. Algoritmos
  sobre secuencias.

(algoritmos-sobre-arreglos)=
#### Algoritmos sobre Arreglos

- {cite:t}`cormen_introduction_2009`. Capítulo 2: Getting Started (Insertion
  Sort), Capítulo 6: Heapsort, Capítulo 9: Medians and Order Statistics.

- {cite:t}`sedgewick_algorithms_2011`. Capítulo 2: Sorting. Visualizaciones
  excelentes de algoritmos de ordenamiento.

(cadenas-y-procesamiento-de-texto)=
#### Cadenas y Procesamiento de Texto

- **POSIX String Handling** -
  https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/string.h.html
  - Especificación estándar de funciones de cadenas.

- {cite:t}`seacord_secure_2013`. Capítulo 2: Strings. Vulnerabilidades comunes
  con cadenas.

(2_secuencias-recursos-en-linea)=
#### Recursos en Línea

- **C String Handling** - https://en.cppreference.com/w/c/string
  - Referencia completa de `<string.h>` con ejemplos.

- **Sorting Algorithms Visualizations** - https://visualgo.net/en/sorting
  - Visualizaciones interactivas de algoritmos de ordenamiento.

- **Big-O Cheat Sheet** - https://www.bigocheatsheet.com/
  - Complejidades de operaciones comunes sobre arreglos.

(2_secuencias-herramientas)=
#### Herramientas

- **Valgrind** - https://valgrind.org/
  - Detección de accesos fuera de límites en arreglos.

- **AddressSanitizer** - https://github.com/google/sanitizers
  - Instrumentación de compilador para detectar errores de memoria.
  - Uso: `gcc -fsanitize=address programa.c`

(2_secuencias-ejercicios-y-practica)=
#### Ejercicios y Práctica

- **LeetCode - Array Problems** - https://leetcode.com/tag/array/
  - Cientos de problemas clasificados por dificultad.

- **HackerRank - Data Structures** -
  https://www.hackerrank.com/domains/data-structures
  - Arrays y strings con tests automáticos.

## Ejercicios de Autoevaluación

### Inicialización y Memoria

:::{exercise}
:label: ej-arr-sizeof-calc
Escribí la expresión matemática completa en C para determinar la cantidad de
elementos de un arreglo declarado como `double temperaturas[50]` utilizando el
operador `sizeof`. Explicá por qué es un cálculo portátil e independiente de la
arquitectura.

:::
<!-- {exercise} -->

:::{solution} ej-arr-sizeof-calc
:class: dropdown
La expresión correcta es:
``` c
size_t cantidad = sizeof(temperaturas) / sizeof(temperaturas[0]);
```
<!-- c -->
Este cálculo es portable porque:
- `sizeof(temperaturas)` devuelve el espacio en bytes reservado para todo el
  arreglo (ej: $50 \times 8 = 400$ bytes en plataformas de 64 bits).
- `sizeof(temperaturas[0])` devuelve el tamaño de un único elemento del arreglo,
  equivalente a `sizeof(double)` (8 bytes).
El cociente $400 / 8$ es siempre $50$, sin importar cuántos bytes asigne la
arquitectura física al tipo `double`.

:::
<!-- {solution} ej-arr-sizeof-calc -->

:::{exercise}
:label: ej-arr-init-parcial
Si declarás localmente un arreglo en C de la siguiente manera:
`int datos[10] = {1, 2, 3};`
Explicá detalladamente el estado lógico y físico de cada una de las posiciones
del arreglo desde `datos[0]` hasta `datos[9]`.

:::
<!-- {exercise} -->

:::{solution} ej-arr-init-parcial
:class: dropdown
En C, cuando se inicializa de forma parcial un arreglo:
- Los elementos correspondientes a los inicializadores explícitos toman los
  valores indicados: `datos[0]` vale `1`, `datos[1]` vale `2`, y `datos[2]` vale
  `3`.
- El estándar del lenguaje garantiza que **todos los elementos restantes** que
  no fueron declarados explícitamente (`datos[3]` a `datos[9]`) se inicializan
  automáticamente a `0`. No contienen datos "basura", a diferencia de una
  declaración sin inicializador como `int datos[10];`.

:::
<!-- {solution} ej-arr-init-parcial -->

:::{exercise}
:label: ej-arr-vla-restriction
Explicá detalladamente por qué el estándar de C prohíbe inicializar un arreglo
de longitud variable (ALV/VLA) en su declaración (ej: `int n = 5; int arr[n] =
{0};` causa un error de compilación).

:::
<!-- {exercise} -->

:::{solution} ej-arr-vla-restriction
:class: dropdown
La inicialización estática `{0}` requiere que el compilador conozca el tamaño y
el diseño del arreglo en **tiempo de compilación** para generar las
instrucciones de asignación de memoria correspondientes en el segmento de datos.
Dado que el tamaño de un ALV/VLA se determina recién en **tiempo de ejecución**
(según el valor de la variable `n`), el compilador no puede generar el bloque de
inicialización de antemano. Para inicializar un VLA, debés declararlo y luego
rellenar sus celdas de forma procedimental (por ejemplo, mediante un lazo
`for`).

:::
<!-- {solution} ej-arr-vla-restriction -->


### Acceso e Iteración

:::{exercise}
:label: ej-arr-func-pure
Implementá una **función pura** en C llamada `buscar_minimo` que reciba un
arreglo de enteros y su tamaño, y retorne el menor valor contenido. Respetá la
regla de estilo {ref}`0x3007h`.

:::
<!-- {exercise} -->

:::{solution} ej-arr-func-pure
:class: dropdown
Al ser una función pura, se utiliza el calificador `const` para prometer que el
arreglo original no será alterado.
```{code-block} c
:linenos:
#include <stddef.h>
int buscar_minimo(const int arreglo[], size_t size)
{
    // #PRE: size > 0
    int minimo = arreglo[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i];
        }
    }
    return minimo;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-arr-func-pure -->

:::{exercise}
:label: ej-arr-func-effect
Implementá una función con **efectos secundarios** llamada `escalar_arreglo` que
multiplique todos los elementos de un arreglo de enteros por un factor entero
dado. Explicá cómo se simula el paso por referencia de los arreglos.

:::
<!-- {exercise} -->

:::{solution} ej-arr-func-effect
:class: dropdown
Al ser una función con efectos secundarios, modificamos el arreglo original de
forma directa en su memoria física:
```{code-block} c
:linenos:
#include <stddef.h>
void escalar_arreglo(int arreglo[], size_t size, int factor)
{
    for (size_t i = 0; i < size; i++)
    {
        arreglo[i] = arreglo[i] * factor; // Efecto secundario
    }
}

```
<!-- {code-block} c -->
<!-- c -->
El paso por referencia se simula porque el compilador no copia los elementos a
la función; en su lugar, le pasa la dirección del primer elemento del arreglo.
La indexación `arreglo[i]` opera sobre la misma dirección física de la memoria
del invocador.

:::
<!-- {solution} ej-arr-func-effect -->

:::{exercise}
:label: ej-arr-decay-sizeof
Si pasás un arreglo a una función (ej: `void f(int arr[])`), explicá por qué
realizar `sizeof(arr)` dentro de la función devolverá el tamaño de un puntero
(habitualmente 8 bytes en 64 bits) y no el tamaño en bytes del arreglo original.

:::
<!-- {exercise} -->

:::{solution} ej-arr-decay-sizeof
:class: dropdown
Esto ocurre debido al fenómeno de **decaimiento de arreglo a puntero (array
decay)**.
Cuando un arreglo se pasa como parámetro a una función, la firma `int arr[]` es
convertida implícitamente por el compilador en un puntero al primer elemento
(`int *arr`). Dado que el operador `sizeof` evalúa el tipo de datos de su
operando en tiempo de compilación, calcula el tamaño de la variable parámetro
`arr` (que es de tipo puntero, ocupando 8 bytes en sistemas de 64 bits),
habiéndose perdido la información sobre la capacidad del bloque de memoria del
arreglo original.

:::
<!-- {solution} ej-arr-decay-sizeof -->


### Cadenas y Caracteres

:::{exercise}
:label: ej-cadena-literal-fault
Si declarás `char *p = "Hola";` e intentás modificar su primer carácter `p[0] =
'h';`, tu programa provocará un fallo de segmentación. Sin embargo, con `char
s[] = "Hola"; s[0] = 'h';` funciona correctamente. Explicá detalladamente por
qué.

:::
<!-- {exercise} -->

:::{solution} ej-cadena-literal-fault
:class: dropdown
La diferencia radica en la región de memoria física donde se almacena el
contenido:
- `char *p = "Hola"`: Crea un puntero `p` que apunta directamente a la dirección
  del literal de cadena `"Hola"`, el cual reside en una sección de la memoria
  del programa de solo lectura (como la sección `.rodata`). Intentar modificar
  esa región física viola los permisos de hardware, provocando un fallo de
  segmentación (*Segmentation Fault*).
- `char s[] = "Hola"`: Declara un arreglo local en el *stack* y **copia** los
  caracteres del literal `"Hola"` (incluido el `\0`) a dicho arreglo. Modificar
  `s[0]` es totalmente válido porque estamos escribiendo sobre memoria local del
  stack asignada al programa.

:::
<!-- {solution} ej-cadena-literal-fault -->

:::{exercise}
:label: ej-cadena-strlen-null
Explicá de qué manera funciona la función `strlen` en la biblioteca estándar y
qué consecuencias fatales se producen si se le pasa como argumento un arreglo de
caracteres que carece del carácter nulo `\0`.

:::
<!-- {exercise} -->

:::{solution} ej-cadena-strlen-null
:class: dropdown
La función `strlen` recorre de forma secuencial la memoria byte a byte desde la
dirección base recibida, incrementando un contador de longitud, hasta encontrar
el primer carácter que sea igual a `\0`.
Si el arreglo carece de `\0`, `strlen` continuará leyendo más allá de los
límites del arreglo en posiciones de memoria consecutivas (acceso fuera de
límites). Esto provocará que retorne un largo erróneo de forma impredecible o
que el programa aborte con un error de violación de acceso (*Segmentation
Fault*) si intenta leer una página de memoria no asignada.

:::
<!-- {solution} ej-cadena-strlen-null -->

:::{exercise}
:label: ej-cadena-largo-capacidad
Escribí un programa en C que declare una variable de cadena e imprima en consola
de forma clara su **capacidad física** en bytes y su **longitud lógica** actual
(sin incluir el carácter nulo), justificando los especificadores de formato
utilizados.

:::
<!-- {exercise} -->

:::{solution} ej-cadena-largo-capacidad
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <string.h>
int main(void)
{
    char mensaje[100] = "Hola Mundo";
    size_t capacidad = sizeof(mensaje);
    size_t longitud = strlen(mensaje);
    // Se utiliza %zu para variables de tipo size_t
    printf("Capacidad física: %zu bytes\n", capacidad);
    printf("Longitud lógica: %zu caracteres\n", longitud);
    return 0;
}

```
<!-- {code-block} c -->
La salida será:
```
Capacidad física: 100 bytes
Longitud lógica: 10 caracteres
```
- `sizeof(mensaje)` retorna la capacidad del arreglo físico (`100` bytes).
- `strlen(mensaje)` retorna la cantidad de caracteres antes del `\0` (`10`).

:::
<!-- {solution} ej-cadena-largo-capacidad -->


### Cadenas Seguras

:::{exercise}
:label: ej-seguro-fgets-newline
Escribí un fragmento de código estructurado que lea una cadena de forma segura
usando `fgets` en un buffer de capacidad 80 y elimine limpiamente el carácter de
salto de línea `\n` residual al final si estuviera presente.

:::
<!-- {exercise} -->

:::{solution} ej-seguro-fgets-newline
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer[80];
    printf("Ingresá un texto: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        size_t len = strlen(buffer);
        // Si el último carácter es un salto de línea, lo reemplazamos por el
        // terminador nulo
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        printf("Leído de forma segura: \"%s\"\n", buffer);
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-seguro-fgets-newline -->

:::{exercise}
:label: ej-seguro-strcmp-case
Implementá una función pura llamada `comparar_ignorar_caso` que compare dos
cadenas de caracteres de forma segura ignorando diferencias entre mayúsculas y
minúsculas (usando la función `tolower` de `<ctype.h>`).

:::
<!-- {exercise} -->

:::{solution} ej-seguro-strcmp-case
:class: dropdown
```{code-block} c
:linenos:
#include <ctype.h>
#include <stddef.h>
int comparar_ignorar_caso(const char s1[], const char s2[])
{
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        char c1 = tolower((unsigned char)s1[i]);
        char c2 = tolower((unsigned char)s2[i]);
        if (c1 != c2)
        {
            return c1 - c2;
        }
        i++;
    }
    return tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-seguro-strcmp-case -->

:::{exercise}
:label: ej-seguro-buffer-overflow
Explicá detalladamente por qué el uso de la función `strcpy(dest, src)` es
vulnerable e inseguro en C en contraposición con el uso de funciones con límites
explícitos.

:::
<!-- {exercise} -->

:::{solution} ej-seguro-buffer-overflow
:class: dropdown
La función `strcpy` copia los bytes de la cadena `src` al buffer `dest` de forma
incondicional hasta encontrar el `\0` en `src`. No tiene conocimiento del tamaño
físico asignado al buffer `dest`.
Si la longitud de `src` excede la capacidad de `dest`, `strcpy` continuará
escribiendo sobrepasando los límites del arreglo. Esto sobrescribe variables
adyacentes en el stack, incluyendo punteros y la dirección de retorno de la
función actual. Un atacante puede explotar esto para secuestrar el flujo de
control ejecutando código malicioso (vulnerabilidad de *stack buffer overflow*).
Para evitarlo, deben emplearse funciones con control de tamaño explícito o
comprobar los límites de antemano.

:::
<!-- {solution} ej-seguro-buffer-overflow -->


## Glosario

::::{glossary}

`size_t`

: Según el estándar ISO C de 1999 (C99), **size_t** es un tipo de dato entero
sin signo de al menos 16 bits (en las secciones 7.17 y 7.18.3). Este se utiliza
para representar el tamaño de un objeto. Las funciones de la biblioteca que
toman o devuelven tamaños esperan que estos sean de este tipo. Además, el
operador **`sizeof`**, que es evaluado en tiempo de compilación, debe dar como
resultado un valor que debe ser al menos, compatible. Para utilizarlo, es
necesario importar `stddef.h` o `stdlib.h`. Esto también implica que un
**`size_t`** es un tipo garantizado para contener cualquier índice de un
arreglo. Para mas información, ver:
[CPPReference - `size_t`](https://en.cppreference.com/w/c/types/size_t.html)

Literal de cadena

: Es el texto que se escribe directamente en el código, encerrado entre comillas
dobles, como "Texto inicial". Piensa en él como una plantilla de texto
original y constante que el programa crea al compilarse. Este literal se
almacena en una parte de la memoria del programa que se considera fija y no debe
alterarse. Cuando creas un arreglo como `char mi_cadena[] = "Texto inicial";`,
lo que realmente sucede es que el contenido de este literal se **copia** al
arreglo, permitiendo su modificación.

::::
<!-- {glossary} -->

---

## Síntesis y Resumen

Este apunte introduce las **secuencias** (arreglos) como la primera estructura
de datos para manejar colecciones homogéneas, y las **cadenas** como caso
especial para texto.

:::{important} Ideas Centrales

**Arreglos como Secuencias Contiguas**
- Almacenan múltiples valores del mismo tipo en posiciones consecutivas de
  memoria
- Acceso directo por índice en tiempo constante $O(1)$
- Tamaño fijo determinado en compilación (arreglos estáticos)
- Índices comienzan en 0: el primer elemento es `arr[0]`

**Paso de Arreglos a Funciones**
- Los arreglos **no se copian**: se pasa la dirección del primer elemento
- Modificaciones dentro de funciones afectan al arreglo original
- Diferencia fundamental con el paso por valor de tipos simples
- Necesidad de pasar el tamaño explícitamente

**Cadenas de Caracteres**
- Arreglos de `char` terminados en centinela `'\0'` (null terminator)
- Funciones de `<string.h>`: `strlen`, `strcpy`, `strcmp`, `strcat`
- Literales de cadena tienen terminador automático
- Cuidado con desbordamientos: el null terminator cuenta

**Transformaciones sobre Secuencias**
- **Operaciones**: map, filter y reduce expresadas mediante lazos

**Relación con Punteros**
- Los arreglos y los punteros están íntimamente vinculados en C.
- El estudio de las direcciones de memoria y la aritmética de punteros (por
  ejemplo, comprender que la expresión `arr[i]` equivale técnicamente a una
  operación de indirección sobre la dirección de memoria) se explican de forma
  detallada en el capítulo {ref}`capitulo-punteros` en [](2_punteros.md).

:::
<!-- {important} Ideas Centrales -->

(referencias-lecturas-secuencias)=
## Referencias y Lecturas Complementarias

- **Kernighan, B. W. y Ritchie, D. M.** [@kernighan_c_2014]. *The C Programming
  Language* (2.ª edición). Prentice Hall.
  - Consultá el **Capítulo 5: Pointers and Arrays**, que establece la relación
    fundamental entre punteros, arreglos y aritmética de direcciones en C, y
    explica la manipulación tradicional de cadenas basada en punteros.
- **King, K. N.** [@king_c_2008]. *C Programming: A Modern Approach* (2.ª
  edición). W. W. Norton & Company.
  - Revisá el **Capítulo 8: Arrays** para una introducción didáctica a la
    disposición en memoria de los arreglos estáticos, y el **Capítulo 13:
    Strings** para comprender en profundidad los riesgos y buenas prácticas en
    la lectura, manipulación y terminación de cadenas de caracteres en C.
- **Gustedt, J.** [@gustedt_modern_2019]. *Modern C*. Manning Publications.
  - Estudiá el **Nivel 1 (Encounter)**, específicamente las secciones dedicadas
    a tipos derivados, donde se analiza cómo C gestiona los arreglos estáticos
    en el stack y la importancia del terminador nulo en las cadenas.
- **Sommers, J.** [@sommers_jsommers/cbook_2025]. *jsommers/cbook*.
  - Consultá las secciones de introducción a arreglos y manipulación de texto
    para ejemplos prácticos e implementaciones de algoritmos sobre secuencias.
