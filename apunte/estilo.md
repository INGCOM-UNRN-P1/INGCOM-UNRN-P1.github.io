---
title: Cuestiones de estilo
short_title: Estilo
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

# Las cuestiones de estilo

Este documento reúne un conjunto de reglas de estilo diseñadas para
hacer que el código en C sea más claro, fácil de leer y menos propenso
a errores. Programar en C puede ser bastante flexible, pero también es
fácil caer en malas prácticas que pueden llevar a errores difíciles de
detectar. Por eso, tener un conjunto de reglas claras ayuda a mantener
el código ordenado y seguro.

La idea detrás de estas reglas es que un buen código no solo funcione,
sino que también sea comprensible para cualquier persona que tenga que
leerlo, ya sea el mismo programador en el futuro o alguien más que se
sume al proyecto. Un código limpio y bien organizado facilita mucho el
trabajo en equipo, ahorra tiempo en correcciones y evita dolores de
cabeza cuando llega el momento de depurarlo o actualizarlo.

Estas reglas cubren todo, desde cómo nombrar variables y funciones hasta
cómo estructurar los condicionales y lazos. Seguirlas no solo ayuda a
mantener la coherencia en el proyecto, sino que también hace que el
código sea más robusto y fácil de mantener a largo plazo.

Comenzar con reglas rígidas en un lenguaje flexible, nos da un respaldo
adicional y cuando nuestro entendimiento del lenguaje mejore, podemos
comenzar a doblar las reglas y llegar a un estilo propio.

## Se aceptan sugerencias y conversiones del tema

Estamos abiertos a conversar todas las reglas, solo tienen que abrir
un hilo en Discussions (o un Ticket en el Issue Tracker) asi como
nuevas reglas, clasificaciones, explicacioes y potenciales excepciones.

## Las reglas

(En algún momento dejaremos)

### Regla `0x0000`: La claridad y prolijidad son muy importantes

El código debe ser claro y fácil de entender para cualquiera que lo lea,
no solo para quien lo escribe. Un código limpio y prolijo evita errores,
facilita el mantenimiento y mejora la colaboración en equipo. La claridad
es preferible a trucos de programación o técnicas avanzadas que solo
complican el entendimiento.

```diff
- for (int i = 0, j = 10; i < j; i++, j--) { printf("%d", i+j); }
+ for (int i = 0; i < 10; i++)
+ {
+     int suma = i + (10 - i);
+     printf("%d", suma);
+ }
```

### Regla `0x0001`: Los identificadores deben ser descriptivos

Los nombres de variables, funciones y demás identificadores deben reflejar
claramente su propósito. Esto ayuda a que el código sea autodescriptivo,
sin necesidad de comentarios adicionales. Usar nombres significativos
facilita la lectura y comprensión.

```diff
// Malos identificadores
- int a, b;
- a = obtener_precio();
- b = calcular_descuento(a);

// Identificadores descriptivos
+ int precio, descuento;
+ precio = obtener_precio();
+ descuento = calcular_descuento(precio);
```

#### Pero, no tengas miedo de los nombres cortos de variables

1. Si el ámbito de la variable es reducido, (entra en la pantalla)
2. La variable se usa en muchos lugares
3. Tiene un identificador de una o dos letras obvias para representarla.

Probá y fijate si ayuda a la legibilidad. _Probablemente sí_.

El ejemplo primordial de esto es ni mas ni menos que `i` y `j`, como contadores.
Igual, si aplican las condiciones anteriores quizas tengamos alguna otra.

### Regla `0x0002`: Una declaración de variable por línea

```diff
-int a, b, c;
+int a;
+int b;
+int c;
```

### Regla `0x0003`: Siempre inicializar la variable a un valor conocido

Es importante que una variable utilizada como R-Value tenga un valor
conocido antes de tomar lo que tenga.

### Regla `0x0004`: Un espacio antes y después de cada operador

```diff
-uno=dos+tres;
+uno = dos + tres;
```

### Regla `0x0005`: Las llaves de los bloques van en una línea propia

```c
if (condicion)
{
    //camino true
}
else
{
    //camino false
}
```

### Regla `0x0006`: Los lazos sin `break` y `continue` en su lugar, lazos con bandera

El uso de break y continue dentro de los lazos puede generar un flujo de
control inesperado, lo que dificulta el seguimiento del programa. Es preferible
utilizar una bandera (variable de control) para salir de los lazos de forma
explícita y ordenada, lo que hace el código más predecible y fácil de mantener.

### Regla `0x0007`: Prefieran usar while en lugar de `for`

El lazo while es más flexible y adecuado cuando no se conoce de antemano
el número de iteraciones. Además, el while es generalmente más fácil de
leer cuando la condición de parada no está claramente relacionada con un
contador. Si se utiliza un lazo para repetir indefinidamente o hasta que
una condición específica sea verdadera, while es preferible a for.

### Regla `0x0008`: Una sola instrucción `return` por función

Limitar una función a un único punto de retorno mejora la legibilidad
y facilita el seguimiento del flujo de control. Además, ayuda a evitar
errores relacionados con la liberación de recursos o la ejecución de
código después de múltiples retornos.

### Regla `0x0009`: Las funciones no van con `printf` o `scanf`, a no ser que ese sea su propósito

Las funciones deben estar separadas de la entrada y salida (I/O) para
que sean útiles en otros contextos y se probar.

Si el propósito de la función no es realizar I/O, estos llamados deben
evitarse, delegando la entrada y salida a otras funciones.

### Regla `0x000A`: Todas las funciones con documentación completa y en la forma

```c
/**
 * Descripción de la función.
 * @param parametro rol
 *          PRE:
 * @returns caracteristicas del valor de retorno.
 *          POST:
 */
```

### Regla `0x000B`: Sin usar variables globales, no están permitidas

Las variables globales pueden ser modificadas desde cualquier parte del
programa, lo que puede causar efectos secundarios inesperados y
dificultar el rastreo de errores.

### Regla `0x000C`: Siempre que sea posible\*, una responsabilidad por función

Cada función debe encargarse de una sola tarea o responsabilidad. Esto
mejora la legibilidad y facilita la reutilización y el mantenimiento del
código. Las funciones pequeñas y especializadas son más fáciles de probar
y depurar.

### Regla `0x000D`: Las condiciones complejas deben ser simplificadas y comentadas

Si una condición contiene múltiples operadores lógicos, divídela en partes
más pequeñas o agrega comentarios explicativos.

```c
if (condicion1 && (condicion2 || !condicion3)) {
    // Explicar qué hace cada condición
}
```

### Regla `0x000E`: Los arreglos estáticos solo pueden ser creados de un tamaño fijo al compilar

Los arreglos ALV no estan permitidos por los problemas que pueden ocasionar,
por lo que deben ser definidos con un tamaño fijo que se determina en tiempo
de compilación.

```diff
- int n = 10;
- int numeros[n]; // ALV
+ int numeros[10];
```

### Regla `0x000F`: Un caso por función de prueba

Pueden lograr esto creando una función que reciba los argumentos y el
resultado esperado para comparar, o hacer una funcion para cada caso.

### Regla `0x0010`: Evitar las condiciones ambiguas que pueden depender del tipo de dato

Por ejemplo, si una variable numérica se usa como condición, siempre se
debe ser explícito:

```diff
- if (x) {
+ if (x != 0) {
```

### Regla `0x0010`: Mantengan el alcance de las variables al mínimo

Historicamente, C requeria que todas las variables sean declaradas al inicio
de la función, para saber cuanto tiene que cambiar el stack en una llamada a
dicha funcion. Hoy día, no es necesario limitarnos y podemos crear variables
de alcance especifico.

```c
for (int i = 0; i < MAXIMO; i++)
```

Declarar `i` en este lugar, hace que la variable solo sea conocida por el lazo.

No siempre es posible, pero en la mayoria de los casos, _sí_.

### Regla `0x0011`: Los retornos numéricos específicos deben ser una constante de preprocesador

El usar nombres descriptivos para los valores facilita la comprensión
del propósito del retorno al darle un nombre explicito.

```diff
-return -1;
+return NO_FUNCIONO;
```

```c
#define NO_FUNCIONO -1
```

### Regla `0x0012`: Todos los lazos y condicionales van con llaves

Incluso para bloques de una sola línea.

```diff
- if (condicion) accion;
+ if (condicion) {
+     accion;
+ }
```

### Regla `0x0013`: Cada bloque lleva cuatro espacios más que el que lo contiene

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

### Regla `0x0014`: Sin instrucción `goto`

El uso de `goto` rompe el flujo natural del programa y dificulta la lectura
y depuración del código, ya que salta entre diferentes partes del programa
de manera impredecible. En lugar de usar esta instrucción, emplea estructuras
de control como `if-else`, `for`, `while` y `switch`, que permiten un flujo
claro y estructurado.

### Regla `0x0015`: Sin operador condicional (ternario) `?:;`

El operador condicional (ternario) es compacto, pero puede hacer que el código
sea difícil de leer, especialmente si se usa de manera excesiva o anidada.

### Regla `0x0016`: Los ejercicios deben ser resueltos con una función

Esto fomenta la modularización del código, facilita la prueba de unidades, y
promueve la reutilización del código. Dividir la lógica en funciones permite
que el código sea más organizado y comprensible.

### Regla `0x0017`: Los nombres de las funciones y procedimientos van en minúsculas y `snake_case`

El uso de snake_case (nombres en minúsculas con guiones bajos entre palabras)
para los nombres de funciones y procedimientos es una convención de estilo que
mejora la consistencia y legibilidad del código. De esta forma y siguiendo las
otras reglas de este estilo, podemos saber inmediatamente que es una funcion,
una variable, una constante y las demás piezas del programa.

### Regla `0x0018`: Los punteros deben ser declarados con el asterisco pegado al identificador

Para facilitar la identificación visual de la variable como un puntero y
mejora la claridad.

```diff
-int* ptr;
+int *ptr;
```

### Regla 0x6`0x0019`7h: Siempre verificar la asignación exitosa de memoria dinámica

Cualquier asignación dinámica de memoria con `malloc`, `calloc` o `realloc`
debe ser seguida por una comprobación de éxito:

```c
ptr = malloc(tamaño);
if (!ptr)
{
    // Manejo de error
}
```

### Regla `0x001A`: Liberar siempre la memoria dinámica

Cada vez que se usa `malloc`/`calloc`/`realloc`, debe asegurarse que
la memoria sea liberada correctamente usando free.

```c
free(ptr);
ptr = NULL;  // Evitar punteros colgantes
```

### Regla `0x001B`: No mezclar operaciones de asignación y comparación en una sola línea

Mantener las asignaciones y comparaciones en líneas separadas reduce la
posibilidad de errores sutiles.

```diff
- if ((ptr = malloc(tamaño)) == NULL) {
+ ptr = malloc(tamaño);
+ if (!ptr) {
```

### Regla `0x001C`: Prefieran fgets a gets y scanf para leer archivos o cadenas

fgets es más seguro que `gets` y `scanf` porque evita desbordamientos de buffer.

```c
fgets(buffer, sizeof(buffer), archivo);
```

### Regla `0x001D`: Manejar correctamente la apertura y cierre de archivos

Siempre verificar si el archivo se abre correctamente y cerrarlo después de su uso:

```c

FILE *archivo = fopen("archivo.txt", "r");
if (!archivo)
{
    // Manejo de error
}
fclose(archivo);
```

### Regla `0x001E`: Las estructuras deben ser inicializadas completamente al ser declaradas

```c
struct Ejemplo ejemplo = {0};  // Inicializa todos los campos a cero o NULL
```

### Regla `0x001F`: Uso explícito de typedef para estructuras complejas

Facilita el manejo y mejora la legibilidad del código al declarar tipos complejos:

```c
typedef struct {
    int campo1;
    char *campo2;
} MiEstructura;
```

### Regla `0x0020`: Acceso a estructuras a través de punteros, usando la notación de flecha (->)

Cuando se accede a los campos de una estructura mediante un puntero,
siempre usar `->` en lugar de `.`:

```c
ptr->campo = valor;
```

### Regla `0x0021`: Evitar el uso de punteros genéricos (void \*) siempre que sea posible

El uso de punteros genéricos debe ser evitado a menos que sea
estrictamente necesario, ya que puede ocultar errores de tipo.

### Regla `0x0022`: Evitar usar múltiples niveles de punteros a menos que sea absolutamente necesario

Esto complica la lectura y el manejo, especialmente cuando se trata de asignación 
o liberación de memoria.

### Regla `0x0023`: Documentar la propiedad de los recursos al usar punteros

Cuando una función recibe o devuelve un puntero a memoria dinámica, es
importante documentar quién es responsable de liberar la memoria:

```c
/**
 * @param ptr Puntero que será liberado por el llamador.
 */
```

Recuerden que no es posible que el programa diferencie la memoria dinámica de la 
automática.

### Regla `0x0024`: Siempre usar const en punteros y parámetros que no deben ser modificados

El uso de const proporciona garantías adicionales y ayuda a evitar modificaciones 
accidentales:

```c
void funcion(const int *ptr);
```

### Regla `0x0025`: Los punteros nulos deben ser inicializados como NULL, no 0

Usa `NULL` para inicializar y verificar punteros, no 0, para mayor claridad y 
coherencia semántica.

```c
int *ptr = NULL;
if (ptr == NULL) {
    // ...
}
```

### Regla `0x0026`: Usar punteros con cast explícito al convertir tipos, evitando conversiones implícitas

Las conversiones de tipos deben ser claras y explícitas para evitar errores:

```c
void *mem = malloc(sizeof(int));
int *ptr = (int *) mem;  // Cast explícito
```

### Regla `0x0027`: Usar macros de tamaño (sizeof) siempre que sea posible en asignaciones de memoria dinámica

Facilita la modificación y reduce errores al manejar estructuras y tipos dinámicos:

```c
ptr = malloc(sizeof(*ptr));  // Asigna la cantidad correcta de memoria para el tipo de ptr
```

### Regla `0x0028`: Verificar siempre los límites de los arreglos antes de acceder a sus elementos

Evita accesos fuera de los límites del arreglo, esto es una de las fuentes más
comunes de errores en C:

```c
if (indice >= 0 && indice < tamaño_arreglo) {
    arreglo[indice] = valor;
}
```

### Regla `0x0029`: Evitar el uso de punteros a funciones si no es estrictamente necesario

Los punteros a funciones pueden introducir complejidad innecesaria. Prefiere mantener
las funciones independientes si es posible.

### Regla `0x002A`: Usar enum en lugar de números mágicos para estados y valores constantes

Mejora la legibilidad y reduce errores al manejar múltiples constantes:

```c
enum Estado { INACTIVO, ACTIVO, PAUSADO };
Estado estado = ACTIVO;
```

### Regla `0x002B`: Documentar explícitamente el comportamiento de las funciones al manejar punteros nulos

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

### Regla `0x002C`: Liberar memoria en el orden inverso a su asignación

Esto es especialmente importante en programas complejos donde varias porciones
de memoria son asignadas en secuencia, como con matrices.

```c
free(ptr2);
free(ptr1);
```

### Regla `0x002D`: Nunca con más de 79 caracteres por línea

Nunca escribas líneas de más de 79 caracteres.

80 caracteres por línea es un estándar de facto para la visualización de código.
Los lectores de tu código que confían en ese estándar, y tienen su terminal o
editor dimensionado a 80 caracteres de ancho, pueden caber más en la pantalla
colocando ventanas una al lado de la otra.

Debes ceñirte a un máximo de 79 caracteres para que siempre haya un espacio en
la última columna. Esto hace más evidente que la línea no continúa en la
siguiente. También proporciona un margen derecho.

Si superas los 80 caracteres, estás haciendo que tu código sea significativamente
más difícil de leer para las personas que intentan confiar en el estándar de 80
columnas. O bien la línea se enrolla, lo que dificulta la lectura, o bien los
lectores tienen que desplazar la ventana hacia la derecha para leer los últimos
caracteres. Cualquiera de estos dos resultados hace que el código sea más difícil
de leer que si hubieras resuelto un salto de línea tú mismo.

Es más difícil leer líneas largas porque tus ojos tienen que desplazarse más lejos
para llegar al principio de la siguiente línea, y cuanto más lejos tengan que ir,
más probable es que tengas que reajustarte visualmente. Los estilos de ancho 100
y 120 son más fáciles de escribir, pero más difíciles de leer.

Puede ser muy tentador dejar que una línea aquí o allá supere los 79 caracteres,
pero sus lectores pagarán el precio cada vez que tengan que leer una línea así.
Trate los 79 caracteres como un límite estricto, sin peros. Averigüe cuál es la
mejor manera de dividir las líneas largas y sus lectores se lo agradecerán.

En C, muchas instrucciones admiten estar en dos lineas, y otras necesitan del
caracter de continuación `\` para seguir en la linea siguiente.

Haga lo que hacen los demás, escriba para las 80 columnas y todos saldremos ganando.

- [Emacs Wiki: Regla de las ochenta columnas](http://www.emacswiki.org/emacs/EightyColumnRule)
- [Programmers' Stack Exchange: ¿Sigue siendo relevante el límite de 80 caracteres?](http://programmers.stackexchange.com/questions/604/is-the-80-character-limit-still-relevant-in-times-of-widescreen-monitors)

### Regla `0x002E`: Compará explicitamente valores, no te fíes de su "veracidad"

Las comparaciones explícitas indican al lector con qué está trabajando,
porque no siempre es obvio en C, y _siempre_ es importante. ¿Estamos
trabajando con cuentas, caracteres, booleanos o punteros? Lo primero que
hago cuando veo que se comprueba la veracidad de una variable en C es
buscar su tipo en la declaración. Ojalá el programador me lo hubiera
dicho en la comparación.

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
