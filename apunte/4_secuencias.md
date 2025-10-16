---
title: "Secuencias: Arreglos y Cadenas"
short_title: "4 - Secuencias"
subtitle: "Colecciones de datos homogéneos y texto."
---

## Introducción a las Secuencias en C

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

## Arreglos: Secuencias de datos

### Definición y Disposición en Memoria

Un **arreglo** es una colección de tamaño fijo de elementos homogéneos. Al
declararlo, el compilador reserva un bloque de memoria continuo y
suficientemente grande para albergar todos sus elementos.

`int mi_arreglo[4];`

Esta declaración reserva espacio para 4 enteros. Si un `int` ocupa 4 bytes, la disposición en memoria es contigua:

```{figure} ./4/array_memory_layout.svg
:name: fig-array-memory-layout
:width: 100%

Disposición en memoria de un arreglo de enteros. Los elementos se almacenan de forma contigua, lo que permite calcular la dirección de cualquier elemento mediante aritmética: dirección_base + (índice × tamaño_elemento). Esta organización es fundamental para el acceso eficiente en tiempo constante O(1).
```

Esta contigüidad es lo que permite el acceso indexado (`mi_arreglo[2]`) de forma casi instantánea.

### Declaración e Inicialización

La declaración de un arreglo sigue la sintaxis `tipo identificador[cantidad];`.

La inicialización define los valores iniciales del arreglo. Es importante
distinguir entre arreglos locales (dentro de una función) y los globales o
estáticos:

- **Arreglos locales no inicializados**: Contienen valores indeterminados
  ("basura"), lo cual viola la regla de estilo {ref}`0x0003h`.
- **Arreglos globales o estáticos no inicializados**: Sus elementos se
  inicializan a cero por defecto.

Formas de inicialización explícita:

```{figure} ./4/array_initialization.svg
:name: fig-array-initialization
:width: 100%

Tres formas de inicializar arreglos en C: completa (todos los valores especificados), parcial (valores restantes a cero), y con inicializadores designados C99 (índices específicos). Los elementos no inicializados explícitamente en arreglos locales contienen basura (regla {ref}`0x0003h`).
```

- **Completa**: `int arr[5] = {10, 20, 30, 40, 50};`
- **Parcial**: `int arr[5] = {10, 20};` (los elementos restantes, `arr[2]` a
  `arr[4]`, se inicializan a `0`).
- **Implícita**: `int arr[] = {10, 20, 30};` (el compilador infiere el tamaño,
  en este caso 3).
- **Inicializadores designados (C99)**: Permite inicializar índices específicos.
  `int arr[5] = {[0] = 10, [4] = 50};` (los no indicados se inicializan a `0`).

### El Operador `sizeof`

Para comprender mejor el manejo de memoria de los arreglos, es necesario
introducir el operador `sizeof`.

Este operador es una herramienta de **tiempo de compilación** que devuelve el
tamaño en bytes de un tipo de dato o una variable. Esto es posible por la forma
en la que C crea las variables en la memoria, con un único tipo, los "tipos
estáticos". El valor que retorna es de tipo {term}`size_t`, un tipo de entero
sin signo.

````{code-block}c
:linenos:
int numeros[10];

// sizeof(int) -> Devuelve el tamaño de un entero (4 bytes)
// sizeof(numeros[0]) -> Devuelve el tamaño de los elementos del arreglo (4 bytes)
// sizeof(numeros) -> Devuelve el tamaño total del arreglo (40 bytes)
````

Esto nos permite calcular la cantidad de elementos de un arreglo de una forma
simple, esto es de suma importancia en C, ya que los arreglos no guardan su
tamaño.

````{code-block}c
:linenos:
// Funciona incluso si cambiamos 'numeros' a 'long numeros[]'.
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
// La cuenta es, el tamaño total del arreglo / el tamaño de un elemento.
// Qué aplicado al arreglo anterior, nos debiera dar 10.
````

Teniendo en cuenta que los tamaños de los tipos básicos como `int` o `long`,
pueden cambiar de tamaño entre compiladores.

````{code-block}c
:linenos:
#include <stdio.h>

int main() {
    printf("Tamaño de char: %zu bytes\n", sizeof(char));
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de float: %zu bytes\n", sizeof(float));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    printf("Tamaño de long long: %zu bytes\n", sizeof(long long));
    return 0;
}
````

La salida de este código en una computadora de escritorio actual sería:

````
Tamaño de char: 1 bytes
Tamaño de int: 4 bytes
Tamaño de float: 4 bytes
Tamaño de double: 8 bytes
Tamaño de long long: 8 bytes
````

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
### Acceso, Modificación y la Identidad del Arreglo

Se accede a los elementos mediante el operador de subíndice `[]`, donde el
índice va de `0` a `cantidad - 1`.

#### Acceso (lectura)

Para leer el valor de un elemento, se utiliza el operador de subíndice `[]` con
el índice del elemento deseado. Es importante recordar que los índices en C
comienzan en cero. Una expresión de acceso como `miArreglo[i]` es un "r-value",
ya que representa un valor que puede ser leído.

Por ejemplo `int valor = mi_arreglo[3];`. Aquí, `mi_arreglo[3]` nos permite
acceder al valor de la cuarta posición.

````{code-block}c
:linenos:
int calificaciones[5] = {10, 8, 9, 7, 10};

// Obtener el valor del primer elemento (índice 0)
int primera = calificaciones[0];

// Obtener el valor del cuarto elemento (índice 3)
int cuarta = calificaciones[3];

printf("La primera calificación es: %d\n", primera);
printf("La cuarta calificación es: %d\n", cuarta);
printf("Acceso directo al segundo elemento: %d\n", calificaciones[1]);
````

Salida:

````
La primera calificación es: 10
La cuarta calificación es: 7
Acceso directo al segundo elemento: 8
````

#### Modificación (escritura)

Para escribir un nuevo valor en un elemento, la expresión de subíndice
`mi_arreglo[i]` se coloca en el lado izquierdo de una operación de asignación.
En este contexto, la expresión es un "l-value", ya que representa una ubicación
de memoria modificable.

Por ejemplo, `mi_arreglo[3] = 100;`. Acá, `mi_arreglo[3]` nos permite modificar
el cuarto valor de la secuencia.

````{code-block}c
:linenos:
int edades[4] = {20, 25, 22, 28};
// 1. Mostrar el valor original del tercer elemento (índice 2)
printf("La edad original en el índice 2 es: %d\n", edades[2]);
// 2. Modificar el valor en el índice 2. 'edades[2]' es un l-value.
edades[2] = 23;
// 3. Mostrar el valor modificado. 'edades[2]' se evalúa como un r-value.
printf("La nueva edad en el índice 2 es: %d\n", edades[2]);
````

Salida:

````
La edad original en el índice 2 es: 22
La nueva edad en el índice 2 es: 23
````

#### Identidad

El identificador de un arreglo, como `mi_arreglo`, es especial. No es una
variable que _contiene_ el arreglo, sino que está **permanentemente asociado con
la dirección de memoria del primer elemento de esa secuencia**. Por esta razón,
no se puede reasignar para que se refiera a otra secuencia. La operación
`arr1 = arr2;` es ilegal. Para copiar los valores, se debe recorrer y copiar
cada elemento, uno por uno.

El identificador de un arreglo es una constante que representa la dirección de
inicio del bloque de memoria asignado. Por esta razón, el nombre de un arreglo
es un **l-value no modificable**.

````{code-block}c
:linenos:
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {10, 20, 30, 40, 50};

// La siguiente línea es ilegal y causará un error de compilación.
arr1 = arr2; // Error: expression is not assignable.
````

### Recorrido de Arreglos y Comportamiento Indefinido

La estructura de control ideal para iterar sobre un arreglo es el lazo `for`.
El uso de `size_t` para el índice del lazo es la forma correcta de hacerlo, tal como lo indica la regla de estilo {ref}`0x002Eh`.

````{code-block}c
:linenos:
int numeros[] = {10, 20, 30, 40, 50};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

for (size_t i = 0; i < cantidad; i++) {
    printf("Elemento %zu: %d\n", i, numeros[i]);
}
````

::::{warning} Cuestiones de límites
C no verifica los límites del arreglo. Acceder a un índice fuera del rango
(`numeros[5]` o `numeros[-1]`) resulta en **comportamiento indefinido**. Esto no
siempre causa un error inmediato. Podría corromper datos de otras variables,
causar fallos de seguridad o funcionar aparentemente bien hasta que un cambio
trivial en otra parte del código revele el error latente. Es responsabilidad del programador garantizar que esto no ocurra, como lo exige la regla {ref}`0x0027h`.

::::
### Arreglos de Longitud Variable (ALV/VLA)

Desde el estándar C99, C permite declarar arreglos cuyo tamaño se determina en
tiempo de ejecución. Estos se conocen como {abbr}`ALV (Array Largo Variable)` o
{abbr}`VLA (Variable Length Array)` (en Inglés).

````{code-block}c
:linenos:
int cantidad = 0;
printf("Ingrese el tamaño del arreglo:\n");
scanf("%d", &cantidad);

int arreglo[cantidad]; // Declaración de un VLA

printf("El tamaño del arreglo en bytes es: %zu\n", sizeof(arreglo));
// El resultado será sizeof(int) * cantidad
````

Estos tienen limitaciones importantes. Por ejemplo, un ALV no puede ser
inicializado en su declaración. Intentarlo producirá un error de compilación:

````text
error: variable-sized object may not be initialized
````

Las implicaciones y el uso correcto de la memoria dinámica, que es la
alternativa recomendada a los ALV, se abordarán en un capítulo posterior.

De todas formas y como se imaginarán, hay una regla de estilo {ref}`0x000Eh`.

### El Mecanismo de Paso a Funciones

Cuando un arreglo se pasa a una función, **no se crea una copia** del mismo. En su lugar, la función recibe la **dirección de memoria** del primer elemento. Es como darle a alguien la dirección de tu casa en lugar de una foto de ella; pueden entrar y redecorar.

```{figure} ./4/array_pass_by_reference.svg
:name: fig-array-pass-by-reference
:width: 100%

Paso de arreglos a funciones por referencia: a diferencia de las variables simples (que se copian), los arreglos se pasan mediante su dirección de memoria. Tanto el arreglo original como el parámetro de la función apuntan a la misma ubicación, permitiendo modificaciones directas del contenido original.
```

:::{note} Relación con Punteros
Este comportamiento está íntimamente relacionado con el concepto de punteros. Para una comprensión más profunda de cómo funcionan las direcciones de memoria y la relación entre arreglos y punteros, consultá el [](7_punteros).
:::

Esto explica dos situaciones clave:

#### Efectos secundarios en arreglos

Al recibir la "dirección de la casa", los cambios en el arreglo que pasamos a la
función, se reflejan en el arreglo original, efectivamente dando un resultado
por fuera del _retorno_ explícito de la función.

Esta situación se puede dar cuando utilizamos al arreglo como una variable más.

````{code-block}c
:caption: Contraejemplo con efectos secundarios destructivos
:emphasize-lines: 4
:linenos:
int maximo(int *arreglo, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (arreglo[i] > arreglo[0]) {
            arreglo[0] = arreglo[i];
        }
    }
    return arreglo[0];
}
````

El problema principal del código es el efecto secundario **destructivo**. La
función no solo calcula el valor máximo, sino que también modifica de manera
irreversible el arreglo que se le pasa como argumento.

Este tipo de comportamiento puede llevar a errores sutiles y difíciles de
depurar, especialmente en programas grandes donde el arreglo original podría ser
necesario para operaciones posteriores. Por ejemplo, si el valor original en la
posición `0` fuera crucial para otro cálculo, esa información se perdería
permanentemente. Para evitar modificaciones no deseadas, es una buena práctica usar el calificador `const` en los parámetros de arreglo que no deben ser alterados, adhiriendo a la regla de estilo {ref}`0x0021h`.

Resolver este problema solo requiere que agreguemos una variable para reemplazar
`arreglo[0]`, pero es un buen contraejemplo de un uso negativo de los efectos
secundarios de los arreglos.

Si la función (o procedimiento) modifica el arreglo, esto debe estar claramente
expresado en la documentación.

Y aunque parezca algo negativo, la utilización de efectos secundarios en
arreglos es sumamente importante, y se utiliza en código que, por ejemplo,
ordene los valores que contiene.

#### Pérdida de `sizeof`

Dentro de la función, `sizeof(arreglo)` no funciona como se espera. La función
solo conoce la dirección en memoria del arreglo, no el tamaño total de la
secuencia original.

````c
/**
 * Esta funcion, ¡no cumple con su objetivo!
 * para cualquier arreglo que le pasemos;
 * ¡vamos a obtener el mismo valor!
 */
size_t tamanio_arreglo(int arreglo[]) {
    printf("Tamaño del arreglo: %zu\n", sizeof(arreglo));
    // El arreglo es siempre de tamaño 8 (la dirección)
    printf("Tamaño de un valor: %zu\n", sizeof(arreglo[0]));
    // El valor apuntado va a ser siempre `int` con 4 bytes.
    return sizeof(arreglo) / sizeof(arreglo[0]);
}

int main() {
    int arreglo1[] = {10, 20, 30, 40, 50};
    int arreglo2[20];
    size_t uno = tamanio_arreglo(arreglo1);
    size_t dos = tamanio_arreglo(arreglo2);
    printf("Tamaño de arreglo1: %zu\n", uno); // obtenemos 2
    printf("Tamaño de arreglo2: %zu\n", dos); // obtenemos 2
    return 0;
}
````

Esta situación se explica porque, teniendo en cuenta que `sizeof` se resuelve en
tiempo de compilación, el operador no puede saber con qué arreglo vamos a llamar
a la función.

Por lo tanto, para que una función pueda trabajar sobre cualquier arreglo, se
debe pasar el tamaño de forma explícita, como un argumento separado. La firma correcta de la función debe incluir el tamaño del arreglo como parámetro. El uso de `size_t` para el tamaño ({ref}`0x002Eh`) y el hecho de pasar el tamaño explícitamente ({ref}`0x0027h`) son cruciales para la seguridad y portabilidad.

````{code-block}c
:linenos:
/**
 * Imprime los elementos de un arreglo de enteros en la salida estándar.
 *
 * @param arreglo de numeros a mostrar.
 * @param size    la cantidad de valores en el arreglo.
 *
 * @post
 * - Los elementos del arreglo `arreglo` se han impreso.
 * - El `arreglo` no será modificado.
  */
void imprimir_arreglo(int arreglo[], size_t size);
````

::::{note} Uso de {term}`size_t`
Aunque no es estrictamente necesario que sea de tipo {term}`size_t`, su uso se
recomienda porque este tipo se asocia al tamaño o las 'dimensiones' de las
cosas.

::::
### Retorno de Secuencias desde Funciones

Una función **no puede retornar un arreglo local**. Cuando una función se
ejecuta, obtiene un espacio de memoria temporal (un _stack frame_). Al retornar,
ese espacio se considera libre y puede ser sobrescrito en cualquier momento.
Devolver la dirección de una variable local es como devolver la llave de una
habitación de hotel después de haber hecho el check-out: la llave puede seguir
existiendo, pero la habitación ya no te pertenece.

## Cadenas: Secuencias de Caracteres

Una cadena es un arreglo de `char` que sigue una regla: el último carácter de
interés está seguido por un **carácter nulo (`\0`)**. Este terminador es
crucial, ya que las funciones de biblioteca como `strlen` o `printf` con `%s`
dependen de él para saber dónde termina el texto.

El comportamiento general de una cadena, es el mismo que el de un arreglo.

Por ejemplo, la siguiente cadena:

````c
char cadena[7] = "Hola";
````

```{figure} ./4/string_null_terminator.svg
:name: fig-string-null-terminator
:width: 100%

Representación en memoria de una cadena con terminador nulo. La cadena "Hola" ocupa 5 bytes (4 caracteres + '\0'), pero el arreglo tiene capacidad para 7. Los bytes no inicializados contienen basura. El terminador '\0' marca el fin lógico de la cadena y es esencial para las funciones de string.h.
```

En donde los `?` _quizás_ sean cero (`\0`), pero como no está inicializado, no
podemos estar seguros del valor que tendrá, a todos los efectos prácticos, es
basura.

También, si aplicamos el cálculo de tamaño usando `sizeof` que vimos antes,
vamos a obtener el tamaño en bytes de la cadena.

````{code-block}c
:linenos:
size_t espacio_reservado = sizeof(mi_cadena) / sizeof(mi_cadena[0]);
````

Que casualmente, coincide con el largo del arreglo, esto es porque `char`
_suele_ ocupar 1-byte por la estrategia de codificación empleada, el código
{abbr}`ASCII (American Standard Code for Information Interchange)`

[Más información sobre ASCII](https://es.wikipedia.org/wiki/ASCII)

Por lo tanto, el `espacio_reservado` tendría `7`, y no el largo de la cadena que
es `4`.

### Inicialización de una cadena

Al declarar una cadena usando la sintaxis de arreglo, estás creando una copia
local y mutable del texto basada en el {term}`literal de cadena`; el texto entre
comillas dobles (`"`), sumando un carácter más para el terminador `\0`.

````c
char mi_cadena[] = "Texto inicial";
````

Es sumamente importante destacar que los literales, que no están asignados a una
variable arreglo (`char []`), **no pueden ser modificados**. Esto significa que
nuestros programas no funcionaran si pasamos como argumento un literal a una
función que modifica dicha cadena.

````{code-block}c
:caption: Modificando cadenas
:linenos:
void ordena_caracteres(char cadena[]) {
    size_t n = strlen(cadena);
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (cadena[j] > cadena[j + 1]) {
                char temp = cadena[j];
                cadena[j] = cadena[j + 1];
                cadena[j + 1] = temp;
            }
        }
    }
}

int main() {
    char mi_cadena[] = "ejemplo de cadena desordenada";

    printf("Cadena original: \"%s\"\n", mi_cadena);

    // Llama a la función para ordenar la cadena.
    ordena_caracteres(mi_cadena);

    printf("Cadena ordenada: \"%s\"\n", mi_cadena);

    //ademas, ¿en donde modificamos la cadena?
    ordena_caracteres("ejemplo de cadena desordenada");

    return 0;
}
````

Y la salida sería:

````{code-block}text
:linenos:
:emphasize-lines: 3
Cadena original: "ejemplo de cadena desordenada"
Cadena ordenada: "   aaaacdddddeeeeeejlmnnooprs"
Segmentation fault (core dumped)
````

Ese `Segmentation fault (core dumped)` es intentar modificar algo que no debía
ser modificado, por lo que es importante que utilicen una variable de cadena en
el medio para evitar este tipo de errores.

Más adelante veremos detalles adicionales sobre los literales de cadena y que
situaciones nos podemos encontrar si no los utilizamos con cuidado.

### Largo de cadenas

Para obtener el largo de una cadena, podemos usar `strlen`, definido en
`<string.h>`.

Esta función está definida de la siguiente forma:

````{code-block}c
size_t strlen( char str );
````

Y se encarga de recorrer la cadena hasta encontrarse un carácter nulo (`\0`)

[Más información sobre `strlen`](https://en.cppreference.com/w/c/string/byte/strlen)

::::{note} Largo vs. capacidad
Es muy importante tener en cuenta que las cadenas tienen dos "tamaños" diferentes.

```{figure} ./4/string_length_vs_capacity.svg
:name: fig-string-length-vs-capacity
:width: 100%

Diferencia entre largo y capacidad: el largo (strlen) cuenta los caracteres hasta '\0' (sin incluirlo), mientras que la capacidad (sizeof) es el tamaño total del arreglo en memoria. La capacidad debe ser siempre mayor al largo para incluir el terminador nulo. Esta distinción es fundamental para operaciones seguras con cadenas.
```

Tenemos, por un lado, el largo, que es la cantidad de caracteres hasta el terminador.

Y, por otro, tenemos el tamaño en memoria del arreglo de caracteres que guarda la cadena, que debiera de ser, por lo menos, uno más que el largo de la cadena. A esta dimensión, la llamaremos "capacidad". 

Esta es la base para las cadenas seguras.

::::
### Lectura Segura de Cadenas

El uso de `scanf("%s", buffer)` es una de las fuentes de errores de seguridad
más comunes en C. La alternativa segura es `fgets`, como lo recomienda la regla de estilo {ref}`0x001Ch`.

````{code-block}c
:linenos:
char buffer[100];
fgets(buffer, sizeof(buffer), stdin);

// fgets puede incluir el salto de línea ('\n'). Es buena práctica removerlo.
size_t len = strlen(buffer);
if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
}
````

### Biblioteca Estándar `<string.h>`: Un Vistazo rápido

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

[Más información sobre `string.h`](https://en.cppreference.com/w/c/header/string.html)
y otras funciones disponibles.

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

## Ejercicios

```{exercise}
:label: sumar_arreglo
:enumerator: arreglos-1

Dado un arreglo de enteros, escribí un programa que calcule y muestre la suma de todos sus elementos.
Utilizá el operador `sizeof` para determinar la cantidad de elementos de forma dinámica.

```

````{solution} sumar_arreglo
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h>

int main()
{
    int numeros[] = {10, 20, 30, 40, 50, -10};
    int suma = 0;
    size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
    for (size_t i = 0; i < cantidad; i++) {
        suma += numeros[i];
    }

    printf("El arreglo tiene %zu elementos.\n", cantidad);
    printf("La suma de los elementos es: %d\n", suma);

    return 0;
}
```
````

```{exercise}
:label: promedio_arreglo
:enumerator: funciones-1

Implementá una función `promedio_arreglo` que reciba un arreglo de enteros y su tamaño.
La función debe devolver el promedio de sus elementos como un `float`.

```

````{solution} promedio_arreglo
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h>
float promedio_arreglo(int arreglo[], size_t cantidad)
{
    int suma = 0;
    for (size_t i = 0; i < cantidad; i++) {
        suma = suma + arreglo[i];
    }

    // Hacemos un cast a float para asegurar una división con decimales
    return (float)suma / cantidad;
}

int main()
{
    int notas[] = {8, 7, 10, 9, 6};
    size_t cantidad_notas = sizeof(notas) / sizeof(notas[0]);
    float prom = promedio_arreglo(notas, cantidad_notas);
    printf("El promedio de las notas es: %.2f\n", prom);
    return 0;
}
```

````

```{exercise}
:label: invertir_arreglo
:enumerator: funciones-2

Implementá un procedimiento `invertir_arreglo` que reciba un arreglo de enteros y su tamaño,
y modifique el arreglo invirtiendo el orden de sus elementos. La función no debe devolver nada (`void`).

```

````{solution} invertir_arreglo
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h>
void invertir_arreglo(int arreglo[], size_t cantidad)
{
    // Si no hay elementos o hay uno solo, no hay nada que hacer
    if (cantidad < 2) {
        return;
    }

    // Iteramos hasta la mitad del arreglo
    for (size_t i = 0; i < cantidad / 2; i++) {
        // Intercambiamos el elemento i con su correspondiente desde el final
        int temporal = arreglo[i];
        arreglo[i] = arreglo[cantidad - 1 - i];
        arreglo[cantidad - 1 - i] = temporal;
    }

}

void imprimir_arreglo(int arreglo[], size_t cantidad)
{
    printf("[ ");
    for (size_t i = 0; i < cantidad; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("]\n");
}
int main()
{
    int mi_arreglo[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(mi_arreglo) / sizeof(mi_arreglo[0]);

    printf("Arreglo original: ");
    imprimir_arreglo(mi_arreglo, n);
    invertir_arreglo(mi_arreglo, n);
    printf("Arreglo invertido: ");
    imprimir_arreglo(mi_arreglo, n);

    return 0;
}

```

````

```{exercise}
:label: contar_vocales
:enumerator: funciones-3

Implementá una función `contar_vocales` que reciba una cadena de caracteres y devuelva 
la cantidad de vocales (mayúsculas y minúsculas) que contiene.

```

````{solution} contar_vocales
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contar_vocales(char cadena[])
{
    int contador = 0;
    size_t largo = strlen(cadena);

    for (size_t i = 0; i < largo; i++) {
        // Convertimos el caracter a minúscula para simplificar la comparación
        char caracter = tolower(cadena[i]);
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
            contador++;
        }
    }
    return contador;
}

int main()
{
    char texto[] = "Este Es un Ejemplo de Cadena";
    int vocales = contar_vocales(texto);
    printf("La cadena: "%s"\n", texto);
    printf("Tiene %d vocales.\n", vocales);
    return 0;
}

````

```{exercise}
:label: leer_cadena
:enumerator: cadenas-1

Escribí un programa que pida al usuario su nombre. Leelo de forma segura usando `fgets` en un buffer de tamaño 50.
Luego, eliminá el carácter de nueva línea (`\n`) que `fgets` suele agregar al final y mostrá un saludo.

```

````{solution} leer_cadena
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <string.h>

int main()
{
    char nombre[50];
    printf("Por favor, ingresa tu nombre: ");
    // Leemos de forma segura desde la entrada estándar (stdin)
    fgets(nombre, sizeof(nombre), stdin);

    // Buscamos el salto de línea al final de la cadena
    size_t largo = strlen(nombre);
    if (largo > 0 && nombre[largo - 1] == '\n') {
        // Si lo encontramos, lo reemplazamos por el terminador nulo
        nombre[largo - 1] = '\0';
    }
    printf("¡Hola, %s! Bienvenido.\n", nombre);
    return 0;
}

```

````
