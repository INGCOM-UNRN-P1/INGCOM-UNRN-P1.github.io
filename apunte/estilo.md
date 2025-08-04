---
title: Cuestiones de estilo
short_title: 0x0000h - Estilo
subtitle: Para que podemos usar variables.
authors:
  - name: Martín René Vilugrón
    affiliations:
      - Universidad Nacional de Rio Negro
exports:
  - format: pdf
    template: volcanica
    article_type: Report
abstract: |
  La introducción a la cátedra con los terminos y condicones de la misma.
---

## Introducción

Este documento reúne un conjunto de reglas de estilo diseñadas para hacer que el
código en C sea más claro, fácil de leer y menos propenso a errores. Programar
en C puede ser bastante flexible, pero también es fácil caer en malas prácticas
que pueden llevar a errores difíciles de detectar. Por eso, tener un conjunto de
reglas claras ayuda a mantener el código ordenado y seguro.

La idea detrás de estas reglas es que un buen código no solo funcione, sino que
también sea comprensible para cualquier persona que tenga que leerlo, ya sea el
mismo programador en el futuro o alguien más que se sume al proyecto. Un código
limpio y bien organizado facilita mucho el trabajo en equipo, ahorra tiempo en
correcciones y evita dolores de cabeza cuando llega el momento de depurarlo o
actualizarlo.

Estas reglas cubren todo, desde cómo nombrar variables y funciones hasta cómo
estructurar los condicionales y lazos. Seguirlas no solo ayuda a mantener la
coherencia en el proyecto, sino que también hace que el código sea más robusto y
fácil de mantener a largo plazo.

Comenzar con reglas rígidas en un lenguaje flexible, nos da un respaldo
adicional y cuando nuestro entendimiento del lenguaje mejore, podemos comenzar a
doblar las reglas y llegar a un estilo propio.

## Se aceptan sugerencias y conversiones del tema

Estamos abiertos a conversar todas las reglas, solo tienen que abrir un hilo en
Discussions (o un Ticket en el Issue Tracker) asi como nuevas reglas,
clasificaciones, explicacioes y potenciales excepciones.

## Principios Clave

- **Claridad:** El código debe ser fácil de entender.
- **Mantenibilidad:** Debe ser sencillo de modificar y extender.
- **Consistencia:** El uso de un estilo uniforme mejora la colaboración.
- **Eficiencia:** Se debe optimizar el rendimiento sin sacrificar legibilidad.

## Las reglas

(En algún momento dejaremos)

(0x0000h)=
### Regla `0x0000h`: La claridad y prolijidad son muy importantes

El código debe ser claro y fácil de entender para cualquiera que lo lea, no solo
para quien lo escribe. Un código limpio y prolijo evita errores, facilita el
mantenimiento y mejora la colaboración en equipo. La claridad es preferible a
trucos de programación o técnicas avanzadas que solo complican el entendimiento.

```diff
- for (int i = 0, j = 10; i < j; i++, j--) { printf("%d", i+j); }
+ for (int i = 0; i < 10; i++)
+ {
+     int suma = i + (10 - i);
+     printf("%d", suma);
+ }
```

(0x0001h)=
### Regla `0x0001h`: Los identificadores deben ser descriptivos

Los nombres de variables, funciones y demás identificadores deben reflejar
claramente su propósito. Esto ayuda a que el código sea autodescriptivo, sin
necesidad de comentarios adicionales. Usar nombres significativos facilita la
lectura y comprensión.

- Malos identificadores

```c
int a, b;
a = obtener_precio();
b = calcular_descuento(a);
```

- Buenos identificadores

```c
int precio, descuento;
precio = obtener_precio();
descuento = calcular_descuento(precio);
```

#### Pero, no tengas miedo de los nombres cortos de variables

1. Si el ámbito de la variable es reducido, (entra en la pantalla)
2. La variable se usa en muchos lugares
3. Tiene un identificador de una o dos letras obvias para representarla.

Probá y fijate si ayuda a la legibilidad. _Probablemente sí_.

El ejemplo primordial de esto es ni mas ni menos que `i` y `j` como contadores.
Y situaciones en las que lo que estamos programando, se representa de esta forma,
como algo matemático.

De todas formas, si aplican las condiciones anteriores quizas tengamos alguna otra.

(0x0002h)=
### Regla `0x0002h`: Una declaración de variable por línea

```diff
-int a, b, c;
+int a;
+int b;
+int c;
```

(0x0003h)=
### Regla `0x0003h`: Siempre inicializar la variable a un valor conocido

Es importante que una variable utilizada como R-Value tenga un valor conocido
antes de tomar lo que tenga.

Incluso si nuestro programa corre en un sistema operativo moderno, en el que se
recibe la memoria en `0`, la reutilizacion de esta, puede hacer que valores asumidos
en este valor no lo esten. 

- Incorrecto:

```c
int contador;
```

- Correcto:

```c
int contador = 0;
```

:::{note} Opciones de compilación

Nos va a avisar que estamos utilizando una variable sin inicializar, pero solo
si tenemos activas las verificaciones y mensajes adicionales.

:::

#### Incluyendo evitar inicializaciones implícitas en estructuras.

- Incorrecto:

```c
struct Datos datos;
```

- Correcto:

```c
struct Datos datos = {0};
```

(0x0004h)=
### Regla `0x0004h`: Un espacio antes y después de cada operador

```diff
-uno=dos+tres;
+uno = dos + tres;
```

(0x0005h)=
### Regla `0x0005h`: Todas las estructuras de control van con llaves

Aunque las llaves son técnicamente opcionales, para mantener la prolijidad y
consistencia, deben ir siempre. Ademas, nos evitamos que al modificar el
programa luego nos encontremos con que el programa hace algo inesperado.

```c
if (condicion) {
    //camino true
} else {
    //camino false
}
```

Incluso para bloques de una sola línea.

```diff
- if (condicion) accion;
+ if (condicion) {
+     accion;
+ }
```

- Incorrecto:
    ```c
    if (x > 0) x++;
    ```
- Correcto:
    ```c
    if (x > 0)
    {
        x++;
    }
    ```

Y las mismas, van en una línea propia:

- Incorrecto:

```c
if (condicion) {
    accion();
}
```

- Correcto:

```c
if (condicion)
{
    accion();
}
```

(0x0006h)=
### Regla `0x0006h`: Los lazos sin `break` y `continue` en su lugar, lazos con bandera

El uso de break y continue dentro de los lazos puede generar un flujo de control
inesperado, lo que dificulta el seguimiento del programa. Es preferible utilizar
una bandera (variable de control) para salir de los lazos de forma explícita y
ordenada, lo que hace el código más predecible y fácil de mantener.

```c
#include <stdio.h>

int main()
{
    printf("Ejemplo usando break y continue:\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i == 4)
        {
            // Omite la iteración actual y salta a la siguiente
            continue;
        }
        if (i == 8)
        {
            // Sale del bucle completamente
            break;
        }
        printf("Número: %d\n", i);
    }
    return 0;
}
```

Uso de bandera

```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Ejemplo usando una bandera de control:\n");

    bool seguir_ejecutando = true; // La bandera para controlar el bucle
    int i = 1;

    while (i <= 10 && seguir_ejecutando)
    {
        if (i == 8)
        {
            // "Apagamos" la bandera para salir del bucle en 
            // el inicio del siguiente lazo
            seguir_ejecutando = false;
        }
        else if (i != 4) // Y en lugar de 'continue', simplemente 
                         //  no ejecutamos la acción
        {
            printf("Número: %d\n", i);
        }
        i++;
    }
    return 0;
}
```

(0x0007h)=
### Regla `0x0007h`: Prefieran usar while en lugar de `for`

El lazo while es más flexible y adecuado cuando no se conoce de antemano el
número de iteraciones. Además, el while es generalmente más fácil de leer cuando
la condición de parada no está claramente relacionada con un contador. Si se
utiliza un lazo para repetir indefinidamente o hasta que una condición
específica sea verdadera, while es preferible a for.

- Incorrecto:

```c
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;

    printf("Ejemplo con 'for' (poco legible):\n");

    // Se fuerza la lectura del dato dentro de la declaración y el paso del 'for'.
    // Esto es confuso y rompe la claridad del código.
    for (printf("Ingrese un número (0 termina): "), scanf("%d", &numero);
         numero != 0;
         printf("Ingrese un número (0 para terminar): "), scanf("%d", &numero))
    {
        suma = suma + numero;
    }

    printf("La suma total es: %d\n", suma);

    return 0;
}
```

- Correcto:

```c
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;

    printf("Ejemplo con 'while' (preferido y claro):\n");
    printf("Ingrese un número (0 para terminar): ");
    scanf("%d", &numero);

    // La condición de parada es clara y está en un solo lugar.
    while (numero != 0)
    {
        suma = suma + numero;

        // Se pide el siguiente dato al final del bloque.
        printf("Ingrese un número (0 para terminar): ");
        scanf("%d", &numero);
    }

    printf("La suma total es: %d\n", suma);

    return 0;
}
```

(0x0008h)=
### Regla `0x0008h`: Una sola instrucción `return` por función

Limitar una función a un único punto de retorno mejora la legibilidad y facilita
el seguimiento del flujo de control. Además, ayuda a evitar errores relacionados
con la liberación de recursos o la ejecución de código después de múltiples
retornos.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_FUNCIONO -1

// Mal ejemplo: Múltiples puntos de retorno complican la gestión de recursos.
int procesar_archivo_con_multiples_retornos(const char *nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        // Punto de salida 1: No hay recursos que liberar aún.
        return NO_FUNCIONO;
    }

    char *buffer = (char *)malloc(100);
    if (buffer == NULL)
    {
        // Punto de salida 2: Hay que recordar cerrar el archivo.
        fclose(archivo);
        return NO_FUNCIONO;
    }

    if (fread(buffer, 1, 99, archivo) < 1)
    {
        // Punto de salida 3: Hay que recordar liberar memoria Y cerrar el archivo.
        free(buffer);
        fclose(archivo);
        return NO_FUNCIONO;
    }

    printf("Archivo procesado correctamente.\n");

    // Punto de salida 4 (el caso exitoso): Limpieza completa.
    free(buffer);
    fclose(archivo);
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_FUNCIONO -1

// Buen ejemplo: Un único punto de retorno facilita la legibilidad y la limpieza.
int procesar_archivo_con_un_retorno(const char *nombre_archivo)
{
    int valor_retorno = 0; // Asumimos éxito al principio
    FILE *archivo = NULL;
    char *buffer = NULL;

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        valor_retorno = NO_FUNCIONO; // Marcamos el error
    }

    if (valor_retorno == 0)
    {
        buffer = (char *)malloc(100);
        if (buffer == NULL)
        {
            valor_retorno = NO_FUNCIONO; // Marcamos el error
        }
    }

    if (valor_retorno == 0)
    {
        if (fread(buffer, 1, 99, archivo) < 1)
        {
            valor_retorno = NO_FUNCIONO; // Marcamos el error
        }
    }

    if (valor_retorno == 0)
    {
        printf("Archivo procesado correctamente.\n");
    }

    // ---- BLOQUE DE LIMPIEZA CENTRALIZADO ----
    // Este bloque se ejecuta sin importar el resultado.
    if (buffer != NULL)
    {
        free(buffer);
    }
    if (archivo != NULL)
    {
        fclose(archivo);
    }

    return valor_retorno; // ÚNICO punto de salida de la función.
}
```


(0x0009h)=
### Regla `0x0009h`: Las funciones no van con `printf` o `scanf`, a no ser que ese sea su propósito

Las funciones deben estar separadas de la entrada y salida (I/O) para que sean
útiles en otros contextos y se probar.

Si el propósito de la función no es realizar I/O, estos llamados deben evitarse,
delegando la entrada y salida a otras funciones.


(0x000Ah)=
### Regla `0x000Ah`: Todas las funciones con documentación completa y estructurada

El código no solo tiene funcionar, sino que también debe ser entendible para otros 
programadores y para tu "yo" del futuro. Una documentación razonable transforma una 
simple función en un componente reutilizable y fiable. 

Al describir claramente qué hace la función, qué datos necesita (parámetros) y qué 
resultado produce (valor de retorno), se crea un "contrato" que define su comportamiento.
Esto ahorra tiempo y reduce errores, ya que no es necesario leer y descifrar la lógica
interna cada vez que se quiere utilizar la función.

El formato de documentación especificado, que utiliza etiquetas como `@param`, `@pre`,
`@returns` y `@post`, no es una elección arbitraria. Sigue un estándar similar al
de herramientas como Doxygen, que pueden procesar estos comentarios paragenerar manuales
de referencia automáticamente. La idea de usar esta estructura, es estructurar y pensar
de manera explícita sobre las precondiciones y las poscondiciones. Este nivel de detalle
es crucial para construir software robusto y mantenible, donde cada pieza del código 
tiene un propósito y unas expectativas bien definidas.

Opcionalmente, se puede pensar en las invariantes con la etiqueta `@invariant`.


```c
/**
 * Descripción de la función.
 * @param parametro rol
 * @pre parametro
 * @returns caracteristicas del valor de retorno.
 * @post
 */
```

Ejemplo concreto
```c
/**
 * Calcula la suma de dos números enteros mediante incrementos o decrementos
 * sucesivos. Esta función simula la operación de suma utilizando únicamente
 * el operador de incremento (+1) o decremento (-1).
 *
 * @param sumando El primer término de la suma, que será la base para los
 *                incrementos.
 * @param sumador El segundo término, que determina la cantidad de incrementos
 *                o decrementos a realizar. Puede ser positivo, negativo o cero.
 *
 * @pre La suma resultante de 'sumando' y 'sumador' no debe causar un
 *      desbordamiento (overflow) del tipo 'int'.
 *
 * @returns Un entero que es el resultado de la suma de 'sumando' y 'sumador'.
 *
 * @post El valor retornado es matemáticamente equivalente a la operación
 *       'sumando + sumador'.
 */
int suma_lenta(int sumando, int sumador);
```

(0x000Bh)=
### Regla `0x000Bh`: Sin usar variables globales, no están permitidas

Las variables globales pueden ser modificadas desde cualquier parte del
programa, lo que puede causar efectos secundarios inesperados y dificultar el
rastreo de errores.

(0x000Ch)=
### Regla `0x000Ch`: Siempre que sea posible, una responsabilidad por función

Cada función debe encargarse de una sola tarea o responsabilidad. Esto mejora la
legibilidad y facilita la reutilización y el mantenimiento del código. Las
funciones pequeñas y especializadas son más fáciles de probar y depurar.

(0x000Dh)=
### Regla `0x000Dh`: Las condiciones complejas deben ser simplificadas y comentadas

Si una condición contiene múltiples operadores lógicos, divídela en partes más
pequeñas o agrega comentarios explicativos.

```c
if (condicion1 && (condicion2 || !condicion3)) {
    // Explicar qué hace cada condición
}
```

Aunque probablemente, si es _tan_ complejo, sea mejor dividirlo en varios `if`.

(0x000Eh)=
### Regla `0x000Eh`: Los arreglos estáticos solo pueden ser creados de un tamaño fijo al compilar

Los arreglos ALV no estan permitidos por los problemas que pueden ocasionar, por
lo que deben ser definidos con un tamaño fijo que se determina en tiempo de
compilación.

```diff
- int n = 10;
- int numeros[n]; // ALV
+ int numeros[10];
```

(0x000Fh)=
### Regla `0x000Fh`: Un caso por función de prueba

Pueden lograr esto creando una función que reciba los argumentos y el resultado
esperado para comparar, o hacer una funcion para cada caso.

(0x0010h)=
### Regla `0x0010h`: Evitar las condiciones ambiguas que pueden depender del tipo de dato

Las comparaciones explícitas indican al lector con qué está trabajando, porque
no siempre es obvio en C, y _siempre_ es importante. ¿Estamos trabajando con
cuentas, caracteres, booleanos o punteros? Lo primero que hago cuando veo que se
comprueba la veracidad de una variable en C es buscar su tipo en la declaración.
Ojalá el programador me lo hubiera dicho en la comparación.

Esto porque cualquier valor numérico distinto de cero se considera **verdadero** en un
contexto lógico, mientras que cero se considera **falso**. Esto se lo llama
"truthyness", o "veracidad" y depender de ello no ayuda a la legibilidad del código
y por lo tanto, no esta permitido.

Por ejemplo, si una variable numérica se usa como condición, siempre se debe ser
explícito:

```diff
- if (x) {
+ if (x != 0) {
```

Al evaluar una condicion, esta debe ser únicamente el resultado de una comparación.

```c
// Malo - ¿qué comprueban realmente estas expresiones?
if ( encendido );
return !caracter;
something( primero( xs ) );
while ( !trabajando );

// Bueno - informativo y elimina la ambigüedad
if ( encendido > 0 );
return caracter == NULL;
something( primero( xs ) != '\0' );
while ( trabajando == false );
```

(0x0011h)=
### Regla `0x0011h`: Mantengan el alcance de las variables al mínimo

Historicamente, C requeria que todas las variables sean declaradas al inicio de
la función, para saber cuanto tiene que cambiar el stack en una llamada a dicha
funcion. Hoy día, no es necesario limitarnos y podemos crear variables de
alcance especifico.

```c
for (int i = 0; i < MAXIMO; i++)
```

Declarar `i` en este lugar, hace que la variable solo sea conocida por el lazo.

No siempre es posible, pero en la mayoria de los casos, _sí_.

(0x0012h)=
### Regla `0x0012h`: Los retornos numéricos específicos deben ser una constante de preprocesador

El usar nombres descriptivos para los valores facilita la comprensión del
propósito del retorno al darle un nombre explicito.

```diff
-return -1;
+return NO_FUNCIONO;
```

```c
#define NO_FUNCIONO -1
```

(0x0013h)=
### Regla `0x0013h`: Cada bloque lleva cuatro espacios más que el que lo contiene

Esto permite elegir un ancho de sangría a medida de la situación, en las
instrucciones que no son bloques y sin romper la alineación general.

```c
//nivel 0
{
    //nivel 1
    {
        //nivel 2
        {
            //nivel 3
        }
    }
}
```

(0x0014h)=
### Regla `0x0014h`: Sin instrucción `goto`

El uso de `goto` rompe el flujo natural del programa y dificulta la lectura y
depuración del código, ya que salta entre diferentes partes del programa de
manera impredecible. En lugar de usar esta instrucción, emplea estructuras de
control como `if-else`, `for`, `while` y `switch`, que permiten un flujo claro y
estructurado.

(0x0015h)=
### Regla `0x0015h`: Sin operador condicional (ternario) `?:;`

El operador condicional (ternario) es compacto, pero puede hacer que el código
sea difícil de leer, especialmente si se usa de manera excesiva o anidada.

(0x0016h)=
### Regla `0x0016h`: Los ejercicios deben ser resueltos con una función

Esto fomenta la modularización del código, facilita la prueba de unidades, y
promueve la reutilización del código. Dividir la lógica en funciones permite que
el código sea más organizado y comprensible.

(0x0017h)=
### Regla `0x0017h`: Los nombres de las funciones y procedimientos van en minúsculas y `snake_case`

El uso de snake_case (nombres en minúsculas con guiones bajos entre palabras)
para los nombres de funciones y procedimientos es una convención de estilo que
mejora la consistencia y legibilidad del código. De esta forma y siguiendo las
otras reglas de este estilo, podemos saber inmediatamente que es una funcion,
una variable, una constante y las demás piezas del programa.

(0x0018h)=
### Regla `0x0018h`: Los punteros deben ser declarados con el asterisco pegado al identificador

Para facilitar la identificación visual de la variable como un puntero y mejora
la claridad.

```diff
-int* ptr;
+int *ptr;
```

(0x0019h)=
### Regla `0x0019h`: Siempre verificar la asignación exitosa de memoria dinámica

Cualquier asignación dinámica de memoria con `malloc`, `calloc` o `realloc` debe
ser seguida por una comprobación de éxito:

```c
ptr = malloc(tamaño);
if (!ptr)
{
    // Manejo de error
}
```

(0x001Ah)=
### Regla `0x001Ah`: Liberar siempre la memoria dinámica

Cada vez que se usa `malloc`/`calloc`/`realloc`, debe asegurarse que la memoria
sea liberada correctamente usando free.

```c
free(ptr);
ptr = NULL;  // Evitar punteros colgantes
```

#### Simetria al liberar

Y cuando llega el momento de liberar, es importante hacerlo al mismo nivel, esto implica:

Por un lado, si hemos pedido memoria en una función, es necesario crear otra función que
se encargue de liberarla, en el mismo nivel de abstracción. Esto porque si lo que hemos
construido dinámicamente, es suficientemente complejo para ameritar una función, es seguro
que la liberación tendrá una complejidad similar. En un par de funciones como `crear_recurso`
y `liberar_recurso`.

Esto es dificil que suceda con arreglos, pero cuando se trata de `struc`turas es posible.

(0x001Bh)=
### Regla `0x001Bh`: No mezclar operaciones de asignación y comparación en una sola línea

Mantener las asignaciones y comparaciones en líneas separadas reduce la
posibilidad de errores sutiles.

```diff
- if ((ptr = malloc(tamaño)) == NULL) {
+ ptr = malloc(tamaño);
+ if (!ptr) {
```

(0x001Ch)=
### Regla `0x001Ch`: Prefieran fgets a gets y scanf para leer archivos o cadenas

fgets es más seguro que `gets` y `scanf` porque evita desbordamientos de buffer.

```c
fgets(buffer, sizeof(buffer), archivo);
```

(0x001Dh)=
### Regla `0x001Dh`: Manejar correctamente la apertura y cierre de archivos

Siempre verificar si el archivo se abre correctamente y cerrarlo después de su
uso:

```c

FILE *archivo = fopen("archivo.txt", "r");
if (!archivo)
{
    // Manejo de error
}
fclose(archivo);
```

Esta regla tambien incluye el uso de `errno`.

(0x001Eh)=
### Regla `0x001Eh`: Uso explícito de typedef para estructuras complejas

Facilita el manejo y mejora la legibilidad del código al declarar tipos
complejos:

```c
typedef struct {
    int campo1;
    char *campo2;
} mi_estructura_t;
```

Los identificadores de tipos creados con `typedef` van con el sufijo `_t`
para poder distinguirlos rápidamente.

(0x001Fh)=
### Regla `0x001Fh`: Minimizar el uso de múltiples niveles de punteros

Esto complica la lectura y el manejo, especialmente cuando se trata de
asignación o liberación de memoria.

(0x0020h)=
### Regla `0x0020Fh`: Documentar la propiedad de los recursos al usar punteros

Cuando una función recibe o devuelve un puntero a memoria dinámica, es
importante documentar quién es responsable de liberar la memoria:

```c
/**
 * @param ptr Puntero que será liberado por el llamador.
 */
```

Recuerden que no es posible que el programa diferencie la memoria dinámica de la
automática.

(0x0021h)=
### Regla `0x0021h`: Siempre usar const en punteros y parámetros que no deben ser modificados

El uso de const proporciona garantías adicionales y ayuda a evitar
modificaciones accidentales:

```c
void funcion(const int *ptr);
```

(0x0022h)=
### Regla `0x0022h`: Los punteros nulos deben ser inicializados como `NULL`, no `0`

Usa `NULL` para inicializar y verificar punteros, no `0`, para mayor claridad y
coherencia semántica.

```c
int *ptr = NULL;
if (ptr == NULL) {
    // ...
}
```

(0x0023h)=
### Regla `0x0023h`: Documentar explícitamente el uso de punteros nulos.

Cuando una funcion devuelve punteros, y estos pueden ser `NULL`, documentar
en que casos nos podemos encontrar con uno.

(0x0024h)=
### Regla `0x0024h`: Usar punteros con cast explícito al convertir tipos, evitando conversiones implícitas

Las conversiones de tipos deben ser claras y explícitas para evitar errores:

```c
void *mem = malloc(sizeof(int));
int *ptr = (int *) mem;  // Cast explícito
```

(0x0026h)=
### Regla `0x0025h`: Usar macros de tamaño (sizeof) siempre que sea posible en asignaciones de memoria dinámica

Facilita la modificación y reduce errores al manejar estructuras y tipos
dinámicos:

```c
ptr = malloc(sizeof(*ptr));  // Asigna la cantidad correcta de memoria para el tipo de ptr
```

(0x0027h)=
### Regla `0x0027h`: Verificar siempre los límites de los arreglos antes de acceder a sus elementos

Evita accesos fuera de los límites del arreglo, esto es una de las fuentes más
comunes de errores en C:

```c
if (indice >= 0 && indice < tamaño_arreglo) {
    arreglo[indice] = valor;
}
```

En funciones, esto implica tambien, que es necesario pasar como argumento
el tamaño del arreglo.

:::{note} Strings

Esto incluye a las cadenas, y es obligatorio cuando la función modifica
posiciones de la misma.

:::


(0x0028h)=
### Regla `0x0028h`: Usar enum en lugar de números mágicos para estados y valores constantes

Mejora la legibilidad y reduce errores al manejar múltiples constantes:

```c
enum Estado { INACTIVO, ACTIVO, PAUSADO };
Estado estado = ACTIVO;
```

Esta regla es similar a [](#0x0012h), pero esta es mas completa, ya que
limita los valores a los que estan definidos en la enumeración.

(0x0029h)=
### Regla `0x0029`: Documentar explícitamente el comportamiento de las funciones al manejar punteros nulos

Cuando una función acepta o devuelve un puntero nulo, el comportamiento debe
estar claramente documentado:

```c
/**
 * @param ptr Puntero que puede ser NULL.
 * @returns NULL si ocurre un error.
 * @returns ERROR_POR_NULO no se pudió seguir.
 */
```

Esto no implica un cambio en la estructura de la función, es una cuestión de
documentar la situación en la estructura que tenga la función.

(0x002Ah)=
### Regla `0x002A`: Liberar memoria en el orden inverso a su asignación

Esto es especialmente importante en programas complejos donde varias porciones
de memoria son asignadas en secuencia, como con matrices.

```c
free(ptr2);
free(ptr1);
```

(0x002Bh)=
### Regla `0x002B`: Nunca con más de 79 caracteres por línea

Nunca escribas líneas de más de 79 caracteres.

80 caracteres por línea es un estándar de facto para la visualización de código.
Los lectores de tu código que confían en ese estándar, y tienen su terminal o
editor dimensionado a 80 caracteres de ancho, pueden caber más en la pantalla
colocando ventanas una al lado de la otra.

Debes ceñirte a un máximo de 79 caracteres para que siempre haya un espacio en
la última columna. Esto hace más evidente que la línea no continúa en la
siguiente. También proporciona un margen derecho.

Si superas los 80 caracteres, estás haciendo que tu código sea
significativamente más difícil de leer para las personas que intentan confiar en
el estándar de 80 columnas. O bien la línea se enrolla, lo que dificulta la
lectura, o bien los lectores tienen que desplazar la ventana hacia la derecha
para leer los últimos caracteres. Cualquiera de estos dos resultados hace que el
código sea más difícil de leer que si hubieras resuelto un salto de línea tú
mismo.

Es más difícil leer líneas largas porque tus ojos tienen que desplazarse más
lejos para llegar al principio de la siguiente línea, y cuanto más lejos tengan
que ir, más probable es que tengas que reajustarte visualmente. Los estilos de
ancho 100 y 120 son más fáciles de escribir, pero más difíciles de leer.

Puede ser muy tentador dejar que una línea aquí o allá supere los 79 caracteres,
pero sus lectores pagarán el precio cada vez que tengan que leer una línea así.
Trate los 79 caracteres como un límite estricto, sin peros. Averigüe cuál es la
mejor manera de dividir las líneas largas y sus lectores se lo agradecerán.

En C, muchas instrucciones admiten estar en dos lineas, y otras necesitan del
caracter de continuación `\` para seguir en la linea siguiente.

Haga lo que hacen los demás, escriba para las 80 columnas y todos saldremos
ganando.

- [Emacs Wiki: Regla de las ochenta columnas](http://www.emacswiki.org/emacs/EightyColumnRule)
- [Programmers' Stack Exchange: ¿Sigue siendo relevante el límite de 80 caracteres?](http://programmers.stackexchange.com/questions/604/is-the-80-character-limit-still-relevant-in-times-of-widescreen-monitors)

```


(0x002Ch)=
### Regla `0x002C`: Desarrolla y compila siempre con todas las advertencias (y más) activadas.

No hay excusas. Desarrolla y compila siempre con las advertencias activadas.
Resulta, sin embargo, que `-Wall` y `-Wextra` en realidad no activan «todas» las
advertencias. Hay algunas otras que pueden ser realmente útiles:

```make
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

# Warnings de GCC que Clang no proporciona:
ifeq ($(CC),gcc)
    CFLAGS += -Wjump-misses-init -Wlogical-op
endif
```

Compilar con las optimizaciones activadas también puede ayudar a detectar
errores:

```make
CFLAGS += -O2
```

(0x002Ch)=
### Regla `0x002C`: Utiliza guardas de inclusión

En todos los headers (`.h`) creados, para evitar la doble inclusión

[Include guards](https://en.wikipedia.org/wiki/Include_guard) permite incluir un
archivo header «dos veces» sin que se interrumpa la compilación.

```c
// Ejemplo de guarda
#ifndef INCLUDED_ALPHABET_H
#define INCLUDED_ALPHABET_H

...

#endif // ifndef INCLUDED_ALPHABET_H
```

El macro utilizado, debe ser similar al del ejemplo, terminar con `_H` y utilizar
un nombre relacionado al archivo que lo contiene.


[Rob Pike argumenta en contra de las protecciones de inclusión](http://www.lysator.liu.se/c/pikestyle.html),
diciendo que nunca se deben incluir archivos en archivos de inclusión. Dice que
las protecciones de inclusión «resultan en miles de líneas de código
innecesarias que pasan por el analizador léxico».

De hecho,
[GCC detectará los include guards](http://gcc.gnu.org/onlinedocs/cppinternals/Guard-Macros.html),
y no leerá tales ficheros una segunda vez. No sé si otros compiladores realizan
esta optimización.

No creo que sea una buena idea requerir a tus usuarios que incluyan las
dependencias de tus ficheros de cabecera. Las dependencias de tus archivos de
cabecera no deberían considerarse realmente «públicas». Aplicaría la regla «no
dependas de lo que incluyen tus ficheros de cabecera», pero se desmorona en
cuanto los ficheros de cabecera utilizan cosas que no necesitas, como `FILE` o
`bool`. Los usuarios no deberían preocuparse por eso si no lo necesitan.

Así que, escribe siempre «include guards», y haz la vida de tus usuarios más
fácil.

#### Comentarios al incluir un header no estandar

Los comentarios en los headers `#include`s de bibliotecas no estándar para indicar
qué símbolos usas de ellas.

Los espacios de nombres son uno de los grandes avances del desarrollo de
software. Por desgracia, C se lo perdió (los ámbitos no son espacios de
nombres). Pero, como los espacios de nombres son tan fantásticos, deberíamos
intentar simularlos con comentarios.

```c
#include <test.h> // Test, tests_run
#include "trie.h" // Trie, Trie_*
```

Esto ofrece algunas ventajas:

- los lectores no se ven obligados a consultar la documentación o utilizar
  `grep` para averiguar dónde está definido un símbolo (o, si no sigue la regla
  siguiente, de dónde procede): su código simplemente se lo dice
- los desarrolladores tienen la esperanza de poder determinar qué `#include`s se
  pueden eliminar y cuáles no
- los desarrolladores se ven forzados a considerar la contaminación del espacio
  de nombres (que de otro modo se ignora en la mayoría del código C), y les
  anima a proporcionar sólo cabeceras pequeñas y bien definidas

El inconveniente es que los comentarios `#include` no se comprueban ni se hacen
cumplir. He estado intentando escribir un comprobador para esto durante bastante
tiempo, pero por ahora, no hay nada que impida que los comentarios sean
erróneos - ya sea mencionando símbolos que ya no se usan, o no mencionando
símbolos que sí se usan. En tu proyecto, intenta cortar estos problemas de raíz,
para evitar que se extiendan. Siempre debes poder confiar en tu código. Este
mantenimiento es molesto, seguro, pero creo que los comentarios `#include`
merecen la pena en conjunto.

Encontrar de dónde vienen las cosas es siempre uno de mis principales retos
cuando aprendo una base de código. Podría ser mucho más fácil. Nunca he visto
ningún proyecto que escriba comentarios `#include` así, pero me encantaría que
se convirtiera en algo habitual.

#### `#include` la definición de todo lo que utilices.

No dependas de lo que incluyan tus cabeceras. Si tu código usa un símbolo,
incluye el fichero de cabecera donde ese símbolo está definido. Entonces, si tus
cabeceras cambian sus inclusiones, tu código no se romperá.

Además, combinado con la regla de comentario `#include` anterior, esto ahorra a
tus lectores y compañeros desarrolladores tener que seguir un rastro de
inclusiones sólo para encontrar la definición de un símbolo que estás usando. Tu
código debería decirles de dónde viene.

#### Evitar las cabeceras unificadas

Las cabeceras unificadas son generalmente malas, porque liberan al desarrollador
de la biblioteca de la responsabilidad de proporcionar módulos sueltos
claramente separados por su propósito y abstracción. Incluso si el desarrollador
(piensa que) hace esto de todos modos, una cabecera unificada aumenta el tiempo
de compilación, y acopla el programa del usuario a toda la biblioteca,
independientemente de si la necesita. Hay muchas otras desventajas, mencionadas
en los puntos anteriores.

Hubo una buena exposición sobre las cabeceras unificadas en
[Programmers' Stack Exchange](http://programmers.stackexchange.com/questions/185773/library-design-provide-a-common-header-file-or-multiple-headers).
Una respuesta menciona que es razonable que algo como GTK+ sólo proporcione un
único archivo de cabecera. Estoy de acuerdo, pero creo que eso se debe al mal
diseño de GTK+, y no es intrínseco a un conjunto de herramientas gráficas.

Es más difícil para los usuarios escribir múltiples `#include`s al igual que es
más difícil para los usuarios escribir tipos. Traer dificultad a esto es
perderse el bosque por los árboles.













