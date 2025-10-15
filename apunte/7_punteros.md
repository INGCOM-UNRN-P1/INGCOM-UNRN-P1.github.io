---
title: "Punteros"
short_title: "7 - Punteros I"
subtitle: "Comenzando con la lengua prohibida de Mordor"
---

## Introducción a los Punteros y la Memoria

Para profundizar en cómo funcionan estructuras como los arreglos y para ganar un
control más directo y eficiente sobre los recursos de tu programa, es
fundamental entender los **punteros**. Los punteros son la herramienta que nos
permite pasar de trabajar solo con los _valores_ de las variables a trabajar con
sus _ubicaciones_ en la memoria.

### ¿Qué es una Dirección de Memoria?

Cada vez que declarás una variable, el sistema operativo le asigna un espacio en
la memoria RAM de la computadora. Podés imaginar la memoria como una gigantesca
fila de casilleros numerados. Cada casillero puede guardar un dato (el valor de
tu variable), y el número del casillero es su **dirección de memoria** única.

### Entonces, ¿qué es un Puntero?

Un **puntero** es, simplemente, una variable especial cuyo único propósito es
guardar la dirección de memoria de otra variable.

En lugar de contener un dato como un número o un carácter, contiene el "número
de casillero" donde se encuentra otro dato. Siguiendo la analogía, un puntero no
es el casillero en sí, sino una nota adhesiva donde tenés apuntado el número de
un casillero específico para no olvidarte dónde guardaste algo importante.

```{figure} 7/concepto_puntero.svg
:label: fig-concepto-puntero
:align: center

Representación conceptual de un puntero apuntando a una variable en memoria.
```

## Declaración de punteros

Para declarar un puntero, debés especificar el tipo de dato al que va a apuntar,
seguido de un asterisco (`*`) y el nombre de la variable. La regla de estilo
{ref}`0x0018h` indica que el asterisco debe ir junto al nombre de la variable.

```{code-block}c
:linenos:
int *ptr_entero;
double *ptr_double;
char *ptr_char;
```

Una vez declarado, un puntero debe ser inicializado para que apunte a una
dirección de memoria específica y válida. No hacerlo es una fuente común de
errores graves. Tenés principalmente dos formas de inicializar un puntero:

### Asignación a una dirección específica

Para que un puntero sea útil, generalmente lo hacés apuntar a una variable
existente. Esto se logra utilizando el operador de dirección `&` (ampersand), el
cual obtiene la dirección de memoria de dicha variable.

```{code-block}c
:linenos:
int numero = 42;
int *ptr_numero = &numero; // ptr_numero ahora almacena la dirección de 'numero'
```

### Inicializar a Nulo (`NULL`)

Si al momento de declarar un puntero no tenés una dirección de memoria válida
para asignarle, es **fundamental** inicializarlo a un estado seguro y conocido.
Para esto se utiliza la macro `NULL`.

:::{tip} Estilo: Inicialización Segura

La regla {ref}`0x0003h` (siempre inicializar variables) es especialmente crítica
para los punteros. Un puntero no inicializado es un "puntero salvaje" que apunta
a una dirección de memoria aleatoria. Adicionalmente, la regla {ref}`0x0022h`
indica que se debe usar `NULL` en lugar de `0` para esta inicialización, ya que
`NULL` expresa semánticamente la intención de que el puntero no apunta a ningún
objeto válido.

:::

`NULL` es una constante de preprocesador, que se encuentra definida en el
encabezado `<stddef.h>` y representa la dirección a «ningún lado».

```{code-block}c
:linenos:
#include <stddef.h> // Necesario para NULL

int *puntero_seguro = NULL;
```

Es una práctica habitual en C que las funciones que devuelven punteros retornen
`NULL` para indicar un error o la ausencia de un resultado. Siempre debés
comprobar si un puntero es `NULL` antes de intentar desreferenciarlo (usar el
operador `*` sobre él).

```{figure} 7/punteros_null.svg
:label: fig-punteros-null
:align: center

Representación de un puntero nulo y la verificación antes de desreferenciar.
```

:::{danger} Peligro: Punteros No Inicializados (Punteros Salvajes)

Un puntero que ha sido declarado, pero no inicializado se conoce como "puntero
salvaje" (_wild pointer_). Contiene una dirección de memoria basura, es decir,
un valor aleatorio que podría apuntar a cualquier parte: a código del programa,
a datos del sistema operativo o a una zona no permitida.

Intentar leer o escribir en la dirección de un puntero salvaje es una operación
de alto riesgo que conduce a un **comportamiento indefinido**. Tu programa
podría fallar inmediatamente, corromper datos silenciosamente o crear
vulnerabilidades de seguridad.

:::

**Regla de oro:** Siempre inicializá tus punteros, ya sea con la dirección de
una variable válida o con `NULL`.

## Operadores de Punteros

- **Operador `&` («dirección de»)**: Toma un L-value (por ejemplo, una variable)
  y devuelve su dirección de memoria. El resultado de esta operación es un
  R-value, ya que la dirección en sí es un valor que se puede asignar a un
  puntero. No podés hacer `&numero = …`, porque la dirección de una variable es
  un valor, no una locación a la que se pueda asignar algo.

- **Operador `*` («indirección» o «desreferencia»)**: Este operador es especial
  porque puede producir tanto un L-value como un R-value, dependiendo del
  contexto.
  - **Como L-value (destino)**: Cuando usás `*puntero` a la **izquierda** de una
    asignación, estás haciendo referencia a la **locación** de memoria a la que
    apunta el puntero. Estás diciendo: "en la dirección que guarda `puntero`,
    almacená este nuevo valor".
  - **Como R-value (origen)**: Cuando usás `*puntero` a la **derecha** de una
    asignación o en cualquier otro lugar donde se espera un valor (como en un
    `printf`), estás accediendo al **valor** contenido en esa locación de
    memoria. Estás diciendo: "dame el valor que está guardado en la dirección a
    la que apunta `puntero`".

```{figure} 7/operadores_punteros.svg
:label: fig-operadores-punteros
:align: center

Funcionamiento de los operadores `&` (dirección de) y `*` (desreferencia).
```

```{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int numero = 99;
    int *puntero = &numero; // '&numero' produce un R-value (la dirección)

    // Uso de *puntero como R-value (leemos el valor)
    // La expresión *puntero aquí se evalúa al valor contenido en 'numero'.
    printf("El valor de 'numero' es: %d\n", *puntero); // Imprime 99

    // Uso de *puntero como L-value (escribimos en la locación)
    // La expresión *puntero aquí se refiere a la locación de 'numero'.
    *puntero = 150;
    printf("El nuevo valor de 'numero' es: %d\n", numero); // Imprime 150

    return 0;
}
```

Esta dualidad del operador de desreferencia es lo que hace a los punteros tan
poderosos, ya que nos permiten tanto leer como modificar datos de forma
indirecta.

### Punteros y arreglos

El nombre de un arreglo es, en esencia, un puntero constante a su primer
elemento. Esto significa que `arreglo` es equivalente a `&arreglo[0]`.

Esta relación nos permite usar punteros para acceder y manipular los elementos
de un arreglo, lo cual nos lleva directamente a la aritmética de punteros.

## Aritmética de punteros

La aritmética de punteros te permite realizar operaciones matemáticas sobre los
punteros. Sin embargo, estas operaciones no son como las operaciones aritméticas
tradicionales. El compilador ajusta automáticamente los cálculos según el tamaño
del tipo de dato al que apunta el puntero.

Si tenés un puntero `ptr` a un tipo de dato `T` que ocupa `sizeof(T)` bytes, al
hacer `ptr + 1`, la dirección de memoria no se incrementa en 1, sino en
`sizeof(T)`. Esto permite "saltar" de un elemento a otro en un arreglo.

```{figure} 7/aritmetica_punteros.svg
:label: fig-aritmetica-punteros
:align: center

Aritmética de punteros: cómo el compilador ajusta los incrementos según el tipo de dato.
```

### Incremento (`++`) y decremento (`--`)

Podés incrementar un puntero para que apunte al siguiente elemento de un arreglo
o decrementarlo para que apunte al anterior.

```{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr apunta a arr[0]

    ptr++; // Ahora ptr apunta a arr[1]
    printf("El segundo elemento es: %d\n", *ptr); // Imprime 20

    ptr++; // Ahora ptr apunta a arr[2]
    printf("El tercer elemento es: %d\n", *ptr); // Imprime 30

    ptr--; // Vuelve a apuntar a arr[1]
    printf("El segundo elemento de nuevo: %d\n", *ptr); // Imprime 20

    return 0;
}
```

### Suma (`+`) y resta (`-`)

Podés sumar o restar un valor entero a un puntero para desplazarte varias
posiciones dentro de un arreglo.

```{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr apunta a arr[0]

    // Acceder al cuarto elemento (índice 3)
    int *ptr_cuarto = ptr + 3;
    printf("El cuarto elemento es: %d\n", *ptr_cuarto); // Imprime 40
    printf("También se puede acceder así: %d\n", *(ptr + 3)); // Imprime 40

    return 0;
}
```

### Un detalle sobre la resta en punteros

Podés restar dos punteros que apunten a elementos del mismo arreglo. El
resultado no es una dirección de memoria, sino la cantidad de elementos que hay
entre ellos.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h> // Necesario para ptrdiff_t

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[4];

    ptrdiff_t diferencia = ptr2 - ptr1;
    printf("Hay %td elementos entre ptr1 y ptr2.\n", diferencia); // Imprime 3

    return 0;
}
```

:::{note} ¿Qué es `ptrdiff_t`?

El tipo de dato del resultado de la resta de punteros es
[`ptrdiff_t`](https://en.cppreference.com/w/c/types/ptrdiff_t.html), un tipo
entero con signo definido en la cabecera `<stddef.h>`. Para imprimirlo
correctamente con `printf`, se utiliza el especificador de formato `%td`.

Esto, teniendo en cuenta que `size_t`, es un número sin signo, que no podría
representar los valores negativos producto de ir "hacia atrás" de la posición
inicial.

:::

## Punteros en funciones y efectos secundarios

Una de las aplicaciones más poderosas de los punteros es su uso en funciones.
Por defecto, en C, los argumentos a las funciones se pasan **por valor**. Esto
significa que la función recibe una copia del argumento, y cualquier
modificación que haga sobre esa copia no afecta a la variable original.

Al pasar un puntero a una función, lo que estamos pasando es la dirección de
memoria de una variable. Aunque la dirección en sí se pasa por valor (la función
recibe una copia del puntero), el puntero dentro de la función apunta a la
variable original. Esto nos permite modificar la variable original desde dentro
de la función, un mecanismo conocido como **paso por referencia simulado**.

```{figure} 7/paso_por_referencia.svg
:label: fig-paso-por-referencia
:align: center

Diferencia entre el paso por valor y el paso por referencia simulado con punteros.
```

```{code-block}c
:linenos:
#include <stdio.h>

// La función recibe dos punteros a enteros
void intercambiar(int *a, int *b) {
    int temporal = *a; // Guardamos el valor al que apunta 'a'
    *a = *b;           // Asignamos al valor de 'a' el valor de 'b'
    *b = temporal;     // Asignamos al valor de 'b' el valor guardado
}

int main() {
    int x = 10;
    int y = 20;

    printf("Valores originales: x = %d, y = %d\n", x, y);

    // Pasamos las direcciones de memoria de 'x' e 'y'
    intercambiar(&x, &y);

    printf("Valores intercambiados: x = %d, y = %d\n", x, y);

    return 0;
}
```

### El impacto en los efectos secundarios

La capacidad de una función para modificar variables que no le pertenecen (es
decir, que no están en su ámbito local) es un nuevo tipo de efecto secundario
(side effect), que en parte, ya vimos en [](./4_secuencias.md).

Si bien los efectos secundarios son extremadamente útiles y necesarios (como en
nuestra función `intercambiar`), también pueden hacer que el código sea más
difícil de entender y depurar. Cuando una función modifica una variable externa,
tenés que rastrear no solo qué hace la función, sino también qué variables de tu
programa podrían haber cambiado después de llamarla.

## El Calificador `const`: el ancla de seguridad con punteros

El calificador `const` es una de las herramientas más importantes en C para
escribir código seguro, predecible y fácil de entender. Actúa como un "contrato"
que le dice al compilador y a otros programadores qué se supone que no debe
cambiar. Cuando lo usás con punteros, como lo exige la regla {ref}`0x0021h`, te
permite "bloquear" o bien el dato apuntado, el puntero en sí, o ambos.

`const` nos permite poner reglas sobre qué se puede modificar, _potencialmente_,
limitando los efectos secundarios productos de pasar el puntero a la función.

```{figure} 7/const_punteros.svg
:label: fig-const-punteros
:align: center

Diferentes combinaciones del calificador `const` con punteros.
```

### 1. Puntero a un Dato Constante (No podés cambiar el VALOR)

Esta es la forma más común. La nota adhesiva es normal (podés borrar el número y
escribir otro), pero el casillero al que apunta está cerrado con llave. No podés
cambiar su contenido a través de este puntero.

- **Sintaxis:** `const T *puntero`.
- **Regla:** El **valor** apuntado es constante. El **puntero** es variable.

```{code-block}c
:linenos:
#include <stdio.h>

void imprimir(const char *mensaje) {
    // mensaje[0] = 'X'; // ERROR DE COMPILACIÓN: intentás modificar un dato constante.
    printf("El mensaje es: %s\n", mensaje);
}

int main() {
    char saludo[] = "Hola";
    char despedida[] = "Chau";

    const char *ptr = saludo;

    // *ptr = 'h'; // ERROR DE COMPILACIÓN: no se puede modificar el contenido.

    ptr = despedida; // VÁLIDO: el puntero puede apuntar a otra dirección.

    imprimir(ptr); // Imprime "Chau"
    return 0;
}
```

**¿Cuándo usarlo?:** Siempre que pases un puntero a una función que solo
necesita leer los datos, pero no modificarlos. Esto previene efectos secundarios
_accidentales_.

### 2. Puntero Constante a un Dato (No podés cambiar la dirección)

En este caso, la nota adhesiva está escrita con tinta imborrable: siempre
apuntará al mismo casillero. Sin embargo, el casillero en sí no tiene llave, por
lo que podés cambiar su contenido libremente.

- **Sintaxis:** `T * const puntero`.
- **Regla:** El puntero es constante. El valor apuntado es variable.

```{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int valor_a = 10;
    int valor_b = 20;

    // El puntero debe inicializarse en la declaración, ya que no se puede cambiar después.
    int * const ptr = &valor_a;

    *ptr = 50; // VÁLIDO: podés modificar el valor en la dirección apuntada.
               // Ahora, 'valor_a' es 50.

    // ptr = &valor_b; // ERROR DE COMPILACIÓN: no se puede reasignar un puntero constante.

    printf("El valor de A es: %d\n", valor_a); // Imprime 50
    return 0;
}
```

**Cuándo usarlo:** Cuando necesitás que un puntero se refiera siempre a la misma
ubicación de memoria, como un búfer fijo o una dirección de hardware específica.

### 3. Puntero Constante a un Dato Constante (No podés cambiar NADA)

Esta es la forma más restrictiva. La nota está escrita con tinta imborrable y el
casillero está cerrado con llave. No podés cambiar ni a dónde apunta el puntero,
ni el contenido del lugar al que apunta.

- **Sintaxis:** `const T * const puntero`.
- **Regla:** Tanto el puntero como el valor apuntado son constantes.

```{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int valor_fijo = 100;
    int otro_valor = 200;

    const int * const ptr = &valor_fijo;

    // *ptr = 150;     // ERROR DE COMPILACIÓN: el valor es constante.
    // ptr = &otro_valor; // ERROR DE COMPILACIÓN: el puntero es constante.

    printf("El valor fijo es: %d\n", *ptr); // Imprime 100
    return 0;
}
```

**Cuándo usarlo:** Para definir una referencia totalmente inmutable a un dato,
como un puntero a una tabla de configuración o a una constante almacenada en
memoria de solo lectura.

## Punteros Dobles: La Indirección a un Nuevo Nivel

Un puntero doble es, literalmente, un **puntero que apunta a otro puntero**.
Introduce un nivel adicional de indirección, lo que significa que necesitás
seguir dos direcciones para llegar al dato final.

Si un puntero (`int *p`) es una nota con la dirección de un cofre que contiene
un tesoro (un `int`), un puntero doble (`int **pp`) es una nota con la dirección
de **otra nota**, que a su vez tiene la dirección del cofre del tesoro.

```{code-block}c
:linenos:
int valor = 100;
int *p = &valor;    // p apunta a 'valor'
int **pp = &p;      // pp apunta a 'p'
```

Podemos acceder a `valor`, desreferenciando dos veces el puntero `pp`;

```{code-block}c
:linenos:
printf("%d\n", **pp);
```

Esta capacidad de manipular un puntero a través de otro puntero es
extremadamente poderosa y se usa principalmente en dos escenarios cruciales.

Uno de ellos lo veremos aquí, el segundo, lo haremos cuando veamos memoria
dinámica.

### Simular "Pasaje por Referencia" para Punteros

Recordá que C siempre pasa los argumentos a las funciones **por valor**. Esto
significa que la función recibe una **copia** del argumento. Si pasás un puntero
`int *p`, la función recibe una copia de la dirección que `p` contiene. Podés
usar esa copia para modificar el dato original (`*p = 99`), pero no podés
cambiar a dónde apunta el puntero original.

Para poder modificar el puntero original desde dentro de una función, necesitás
pasar la dirección de ese puntero, es decir, un puntero doble.

```{code-block}c
:linenos:
#include <stdio.h>

// Función para intercambiar el valor de dos punteros.
// Se utilizan punteros dobles (**), ya que necesitamos modificar
// las direcciones de memoria a las que apuntan los punteros originales.
void intercambiar_punteros(int **puntero1, int **puntero2) {
    int *temp = *puntero1;
    *puntero1 = *puntero2;
    *puntero2 = temp;
}

int main() {
    int a = 10;
    int b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("Antes del intercambio:\n");
    printf("ptr_a apunta a %d (direccion: %p)\n", *ptr_a, ptr_a);
    printf("ptr_b apunta a %d (direccion: %p)\n", *ptr_b, ptr_b);

    // Llamamos a la función pasando las direcciones de los punteros
    intercambiar_punteros(&ptr_a, &ptr_b);

    printf("\nDespues del intercambio:\n");
    printf("ptr_a apunta a %d (direccion: %p)\n", *ptr_a, ptr_a);
    printf("ptr_b apunta a %d (direccion: %p)\n", *ptr_b, ptr_b);

    return 0;
}
```

Al desreferenciar `puntero1` y `puntero2`, accedemos directamente a los punteros
originales (`ptr_a` y `ptr_b` en `main`) y podemos modificar las direcciones de
memoria que almacenan.

:::{note} Compilación del último ejemplo

En dicho ejemplo, se han eliminado unas conversiones (casts), que aunque la
funcionalidad del ejemplo no se ve afectada, provocará una advertencia de
compilación:

`"warning: format '%p' expects argument of type 'void *', but argument 3 has type 'int *'".`

Esta hace referencia a lo que se espera con el calificador `"%p"`, y trataremos
cuando veamos memoria dinámica.

:::

## Documentando funciones con punteros

Cuando una función utiliza punteros como parámetros, especialmente para
modificar datos fuera de su propio ámbito (efectos secundarios), una
documentación clara y precisa es fundamental. La documentación actúa como un
**contrato** entre la función y quien la llama (el "cliente"). Este contrato
establece las responsabilidades de cada parte para garantizar que la función
opere de manera segura y predecible.

Usaremos la función `intercambiar` como ejemplo para ilustrar cómo documentar
este contrato, definiendo el flujo de los datos, las precondiciones, las
poscondiciones y los invariantes.

### Dirección del Flujo de Información

Al trabajar con punteros, no solo es importante el tipo de dato, sino también la
"dirección" en la que fluye la información. Se usa una convención simple para
indicarlo:

- **`[in]`**: El puntero se usa solo para **leer** datos. La función no
  modificará el valor al que apunta. Es una buena práctica que estos parámetros
  sean `const`.
- **`[out]`**: El puntero se usa para **escribir** un resultado. El valor
  inicial al que apunta no es relevante para la función, pero al finalizar,
  contendrá un dato de salida.
- **`[in, out]`**: El puntero se usa tanto para **leer** el valor inicial como
  para **escribir** un nuevo valor. La función modifica el dato original.

---

### Contratos II: Precondiciones, Poscondiciones e Invariantes con punteros

Recordemos que es cada uno de ellos

- **Precondición**: Es una condición que **debe ser verdadera antes** de que se
  llame a la función. Es **responsabilidad del programador que llama** a la
  función cumplirla. Si no se cumple, la función no garantiza su comportamiento.
- **Poscondición**: Es una condición que la función **garantiza que será
  verdadera después** de que se ejecute exitosamente. Es la promesa o el
  resultado de la función.
- **Invariante**: Es una condición que es verdadera **antes, durante y después**
  de la ejecución de la función. Define propiedades que no cambian a lo largo de
  la operación. Estas son más importantes en las funciones que utilizan punteros
  dado que el código puede cambiar valores de forma indirecta.

Su uso como metodología de documentación es una simplificación de su verdadero
poder, pero nos ayuda a pensar que en términos de lo que entra, lo que sale y lo
que no cambia.

### Ejemplo de Documentación Completa

Aplicando estos conceptos, una documentación exhaustiva para la función
`intercambiar` se vería así, siguiendo el estilo creado por la cátedra.

```{code-block}c
:linenos:
/**
 * Intercambia los valores de dos variables enteras a través de sus punteros.
 * @param[in, out] primero Puntero al primer valor. Su contenido será leído y luego
 * sobrescrito con el del segundo.
 * @param[in, out] segundo Puntero al segundo valor. Su contenido será leído y luego
 * sobrescrito con el contenido del primero.
 * @pre Ambos punteros no deben ser NULL y apuntar a direcciones de memoria válidas y modificables.
 * @post El valor almacenado en la dirección apuntada por 'primero' será el valor original
 * que se encontraba en la dirección de 'segundo' y viceversa. No se introducirán otros valores por fuera
 * de los que estén referenciados.
 */
void intercambiar(int *primero, int *segundo) {
    int temporal = *primero;
    *primero = *segundo;
    *segundo = temporal;
}
```

De esta forma, eliminamos las ambigüedades, y reducimos los potenciales errores.

## La "degradación" de arreglos a punteros

Uno de los comportamientos más importantes —y a menudo confusos— en C es que los
**arreglos se "degradan" (decay) a punteros** en la mayoría de los contextos.
Este no es un truco, sino una regla de conversión fundamental del lenguaje que
explica la íntima relación entre ambos conceptos.

### ¿Qué significa realmente la "degradación"?

La regla es simple: cuando usás el nombre de un arreglo en una expresión (por
ejemplo, al asignarlo a un puntero o pasarlo a una función), el compilador no
trabaja con el arreglo completo. En su lugar, lo convierte automáticamente en un
**puntero al primer elemento** de ese arreglo.

Por lo tanto, las siguientes dos líneas de código son funcionalmente idénticas:

```{code-block}c
:linenos:
int numeros[5] = {10, 20, 30, 40, 50};

// La "degradación" ocurre aquí: 'numeros' se convierte en la dirección de numeros[0]
int *p = numeros;

// Esta es la forma explícita y equivalente
int *p_explicito = &numeros[0];

printf("La dirección almacenada en p es: %p\n", (void*)p);
printf("La dirección del primer elemento es: %p\n", (void*)&numeros[0]);
```

### Consecuencias Prácticas (y Cruciales) de la Degradación

Entender esta conversión es vital porque tiene implicaciones directas en cómo
escribís tu código, especialmente con funciones y el operador `sizeof`.

Cuando pasás un arreglo a una función, lo que la función recibe en realidad es
una copia del puntero a su primer elemento. La función _nunca_ recibe la copia
del arreglo.

Por eso, estas tres declaraciones de función son absolutamente equivalentes para
el compilador:

```{code-block}c
:linenos:
void procesar_datos(int arr[10]); // El 10 es ignorado por el compilador
void procesar_datos(int arr[]);   // Notación más común para indicar que se espera un arreglo
void procesar_datos(int *arr);    // La forma más honesta: la función recibe un puntero
```

Debido a esto, la función pierde la información sobre el tamaño original del
arreglo y el tamaño que obtendremos es únicamente el de la dirección de memoria.

$$\text{sizeof(arreglo\_decaido)} = \text{sizeof(puntero)}$$

```{code-block}c
:linenos:
#include <stdio.h>

// La función recibe un puntero, sin importar cómo se declare el parámetro.
void imprimir_tamano(int arr[]) {
    // ¡Peligro! Esto NO mide el tamaño del arreglo original.
    // Mide el tamaño de un puntero en tu sistema (usualmente 4 u 8 bytes).
    printf("Tamaño DENTRO de la función: %zu bytes\n", sizeof(arr));
}
```

`sizeof` funciona como es esperado solo cuando su uso se hace en el mismo
alcance de la declaración del arreglo.

Por lo que hacer `sizeof(arreglo)` va a devolver el tamaño total en bytes del
arreglo, de forma que sea (número de elementos \* tamaño del tipo del arreglo).

$$\text{sizeof(arreglo)} = elementos \times \text{sizeof(T)}$$

```{code-block}c
:linenos:

int main() {
    int mi_arreglo[10] = {0};

    // Aquí 'sizeof' conoce el tamaño real del arreglo.
    printf("Tamaño FUERA de la función: %zu bytes\n", sizeof(mi_arreglo)); // Imprimirá 40 (10 * 4 bytes)

    imprimir_tamano(mi_arreglo); // Imprimirá 4 u 8

    return 0;
}
```

:::{important} Regla de Oro

Debido a la degradación, **tenés que pasar el tamaño de un arreglo a una función
como un parámetro extra**. La función no tiene otra forma de saber hasta dónde
puede leer o escribir de forma segura. (Y ya que estamos, como un `size_t` para
que todo quede más bonito.)

:::

## Manipulando arreglos con aritmética de punteros

La relación entre arreglos y punteros en C es tan estrecha que se pueden usar de
forma intercambiable en muchos contextos.

### 1. Recorrido solo lectura

La tarea más básica es iterar sobre todos los elementos para leerlos o
imprimirlos. La estrategia consiste en tener un puntero que avanza y un puntero
"límite" que nos indica cuándo detenernos.

**Método:**

1.  Declará un puntero `ptr` que apunte al inicio del arreglo.
2.  Declará otro puntero `fin` que apunte a la dirección de memoria
    **inmediatamente posterior** al último elemento. Esto substituye el 'conteo'
    de posiciónes.
3.  El lazo `while` se ejecuta mientras `ptr` sea menor que `fin`.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h> // Para size_t

void imprimir_arreglo(const int *arr, size_t tamano) {
    const int *ptr = arr;
    const int *fin = arr + tamano; // Puntero al final del arreglo + 1

    printf("Contenido del arreglo: ");
    while (ptr < fin) {
        printf("%d ", *ptr); // 1. Leer el valor actual
        ptr++;               // 2. Mover el puntero al siguiente elemento
    }
    printf("\n");
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    imprimir_arreglo(numeros, 5);
    return 0;
}
```

### 2. Búsqueda de un elemento

Para buscar un valor, recorremos el arreglo y nos detenemos si encontramos una
coincidencia. La función devolverá un puntero al elemento encontrado o `NULL` si
no se encuentra. La comprobación explícita contra `NULL` sigue la regla
{ref}`0x0010h`.

**Método:**

1.  Declará los punteros `ptr` y `fin` como en el ejemplo anterior.
2.  El lazo `while` se ejecuta mientras no lleguemos al final y no hayamos
    encontrado el valor.
3.  Después del lazo, si `ptr != fin`, significa que el lazo se detuvo porque
    encontramos el elemento. Si son iguales, es porque recorrimos todo sin
    éxito.
4.  Si el bucle termina sin encontrar el valor, devolver `NULL`.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h> // Para NULL y size_t

// Devuelve un puntero al primer elemento que coincida con 'valor', o NULL si no se encuentra.
int* buscar_valor(int *arr, size_t tamano, int valor) {
    int *ptr = arr;
    int *fin = arr + tamano;
    int *resultado = NULL; // Inicializamos con NULL

    // El bucle continúa mientras no hayamos llegado al final
    // Y no hayamos encontrado el valor.
    while (ptr < fin && resultado == NULL) {
        if (*ptr == valor) {
            resultado = ptr; // Asignamos la dirección si se encuentra
        }
        ptr++;
    }

    return resultado; // Devolvemos el resultado final
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int valor_a_buscar = 30;

    int *encontrado = buscar_valor(numeros, 5, valor_a_buscar);

    if (encontrado != NULL) {
        printf("Valor %d encontrado en la dirección de memoria %p\n", *encontrado, (void*)encontrado);
    } else {
        printf("Valor %d no encontrado en el arreglo.\n", valor_a_buscar);
    }

    return 0;
}
```

### 3. Modificando el arreglo

Para modificar los datos, usamos el operador de desreferencia (`*`) en el lado
izquierdo de una asignación. Esto modifica el valor en la memoria a la que
apunta el puntero.

**Método:**

1.  El recorrido es idéntico al de la lectura.
2.  Dentro del lazo, en lugar de leer, realizamos una asignación:
    `*ptr = nuevo_valor`.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h> // Para size_t

// Duplica el valor de cada elemento en el arreglo.
void duplicar_valores(int *arr, size_t tamano) {
    int *ptr = arr;
    int *fin = arr + tamano;

    while (ptr < fin) {
        *ptr = *ptr * 2; // Modifica el valor en la memoria apuntada
        ptr++;
    }
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};

    printf("Arreglo original: 1 2 3 4 5\n");
    // (Código para imprimirlo, podemos usar el de la primera sección)

    duplicar_valores(numeros, 5);

    printf("Arreglo modificado: %d %d %d %d %d\n", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4]);
    // Salida esperada: 2 4 6 8 10

    return 0;
}
```

### 4. Copiando un Arreglo

Para copiar un arreglo, necesitamos dos punteros: uno para la fuente (de donde
leemos) y otro para el destino (donde escribimos). Ambos deben avanzar en cada
paso.

**Método:**

1.  Creá un puntero `fuente` para el arreglo original y un puntero `destino`
    para el nuevo.

2.  El lazo se ejecuta mientras el puntero `fuente` no llegue a su final.

3.  Dentro del lazo, copiá el valor y luego incrementá **ambos** punteros.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h> // Para size_t

void copiar_arreglo(int *destino, const int *fuente, size_t tamano) {
    const int *ptr_fuente = fuente;
    int *ptr_destino = destino;
    const int *fin_fuente = fuente + tamano;

    // Bucle principal de copia
    while (ptr_fuente < fin_fuente) {
        *ptr_destino = *ptr_fuente;
        ptr_fuente++;
        ptr_destino++;
    }

    // Una forma más compacta pero potencialmente
    // menos legible de escribir lo de arriba:
    // while (ptr_fuente < fin_fuente) {
    //     *ptr_destino++ = *ptr_fuente++;
    // }
}

int main() {
    int arreglo_a[] = {100, 200, 300};
    int arreglo_b[3]; // Arreglo vacío para recibir la copia

    copiar_arreglo(arreglo_b, arreglo_a, 3);

    printf("Contenido del arreglo copiado: %d %d %d\n", arreglo_b[0], arreglo_b[1], arreglo_b[2]);
    // Salida esperada: 100 200 300

    return 0;
}
```

:::{warning} Advertencia sobre los límites de los arreglos

Este último ejemplo, debiera de recibir un tamaño para cada arreglo y verificar
que los tamaños de ambos sean 'compatibles' entre sí. La regla de estilo
{ref}`0x0027h` es crucial aquí.

La mayor ventaja y el mayor peligro de la aritmética de punteros es su libertad.
El lenguaje C no te impedirá incrementar un puntero más allá del final de un
arreglo. Es **tu responsabilidad** como programador asegurarte de que tus lazos
y operaciones se mantengan siempre dentro de los límites válidos del arreglo
para evitar corrupción de memoria y comportamientos indefinidos.

:::

### 5. Versión alternativa

Si la función que necesitamos crear, necesita de la posición en la que nos
encontramos, no vamos a escapar de 'contar' posiciones.

En ese caso, lo que podemos hacer, es ir sumando al puntero del arreglo la
`i`-esima posición, en lugar de ir incrementando el puntero mismo.

```{code-block}c
:linenos:
for (size_t i = 0; i < 5; i++) {
    printf("%d ", *(p + i));
}
```

De esta forma, podemos obtener un código que es más similar al uso tradicional
de arreglos

```{code-block}c
:linenos:
void imprimir_arreglo(const int *ptr, size_t tamano) {
    printf("Contenido del arreglo: ");
    for (size_t i = 0; i < tamano; i++) {
        printf("%zu:%d ", i, *(ptr + i));
    }
    printf("\n");
}
```

Prestá atención a los paréntesis en `*(p + i)`, ya que son cruciales para el
orden de las operaciones. Su presencia asegura que primero realicemos la
aritmética de punteros (calculando la nueva dirección `p + i`) y **después**
desreferenciemos esa dirección para obtener el valor que contiene.

Si omitieras los paréntesis y escribieras `*p + i`, el resultado sería
completamente diferente. Debido a la precedencia de operadores, primero se
desreferenciaría `*p` (obteniendo el valor en la dirección actual) y luego se le
sumaría `i` a ese valor, lo cual es una operación matemática, no de punteros.

En resumen:

- `*(p + i)` significa: "Andá `i` lugares más allá y decime qué valor hay allá".
- `*p + i` significa: "Decime qué valor hay acá y sumale `i`".

## Ejercicios

```{exercise}
:label: intercambiar_valores
:enumerator: punteros-1

Implementá un procedimiento `void intercambiar(int *a, int *b)` que reciba dos punteros a enteros. La función debe intercambiar los valores de las variables originales a las que apuntan estos punteros.
```

````{solution} intercambiar_valores
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>

void intercambiar(int *a, int *b) {
  int temporal = *a; // Guardamos el valor al que apunta 'a'
  *a = *b;           // Asignamos al lugar de 'a' el valor al que apunta 'b'
  *b = temporal;     // Asignamos al lugar de 'b' el valor guardado
}

int main() {
  int x = 10;
  int y = 20;

  printf("Valores originales: x = %d, y = %d\n", x, y);

  // Pasamos las direcciones de memoria de x e y
  intercambiar(&x, &y);

  printf("Valores intercambiados: x = %d, y = %d\n", x, y);

  return 0;
}
```
````

```{exercise}
:label: encontrar_maximo
:enumerator: funciones-1

Escribí una función `int encontrar_maximo(const int *arreglo, size_t n)` que reciba un puntero al inicio de un arreglo de enteros (marcado como `const` para no modificarlo) y su tamaño. La función debe recorrer el arreglo usando el puntero y devolver el valor del elemento más grande.
```

````{solution} encontrar_maximo
:class: dropdown

```{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>

int encontrar_maximo(const int *arreglo, size_t n) {
  if (n == 0) {
    return 0; // O un valor de error apropiado
  }

  int maximo = *arreglo; // Suponemos que el primer elemento es el máximo

  // Avanzamos el puntero por el resto del arreglo
  for (size_t i = 1; i < n; i++) {
    // Usamos aritmética de punteros para acceder al siguiente elemento
    if (*(arreglo + i) > maximo) {
      maximo = *(arreglo + i);
    }
  }
  return maximo;
}

int main() {
  int numeros[] = {5, 2, 99, 45, 12, 50};
  size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

  int max = encontrar_maximo(numeros, cantidad);
  printf("El elemento máximo del arreglo es: %d\n", max);

  return 0;
}
```
````

```{exercise}
:label: copiar_cadena
:enumerator: funciones-2

Implementá un procedimiento `void copiar_cadena(char *destino, const char *origen)`. La función debe copiar la cadena de caracteres de `origen` a `destino`, incluyendo el carácter nulo final (`\0`). Debés resolverlo recorriendo las cadenas exclusivamente con punteros.
```

````{solution} copiar_cadena
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>

void copiar_cadena(char *destino, const char *origen) {
  // Mientras el valor al que apunta 'origen' no sea el carácter nulo...
  while (*origen != '\0') {
    *destino = *origen; // Copiamos el valor
    origen++;           // Avanzamos el puntero de origen
    destino++;          // Avanzamos el puntero de destino
  }
  *destino = '\0'; // Aseguramos que la cadena destino termine con el nulo
}

int main() {
  const char *fuente = "Hola Punteros!";
  char buffer[50];

  copiar_cadena(buffer, fuente);

  printf("Cadena original: %s\n", fuente);
  printf("Cadena copiada: %s\n", buffer);

  return 0;
}
```
````

```{exercise}
:label: sumar_arreglo_punteros
:enumerator: funciones-3

Creá una función `int sumar_arreglo(const int *inicio, const int *fin)` que reciba un puntero al primer elemento de un arreglo y un puntero a la dirección de memoria inmediatamente posterior al último elemento. La función debe sumar los elementos del arreglo iterando con un puntero desde `inicio` hasta que alcance a `fin`.
```

````{solution} sumar_arreglo_punteros
:class: dropdown

```{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>

int sumar_arreglo(const int *inicio, const int *fin) {
  int suma = 0;
  // Iteramos mientras el puntero 'p' no haya llegado al puntero 'fin'
  for (const int *p = inicio; p < fin; p++) {
    suma += *p; // Sumamos el valor al que apunta 'p'
  }
  return suma;
}

int main() {
  int arreglo[] = {10, 20, 30, 40};
  size_t n = sizeof(arreglo) / sizeof(arreglo[0]);

  // El puntero 'fin' apunta a una posición después del último elemento
  int suma_total = sumar_arreglo(arreglo, arreglo + n);

  printf("La suma de los elementos es: %d\n", suma_total);

  return 0;
}
```
````

```{exercise}
:label: invertir_arreglo_inplace
:enumerator: punteros-2

Implementá un procedimiento `void invertir_arreglo(int *arreglo, size_t n)` que invierta el orden de los elementos de un arreglo "in-place" (sin usar un arreglo auxiliar). Utilizá dos punteros: uno que apunte al inicio del arreglo y otro que apunte al final. Intercambiá los valores a los que apuntan y mové los punteros hacia el centro hasta que se crucen.
```

````{solution} invertir_arreglo_inplace
:class: dropdown

```{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>

void invertir_arreglo(int *arreglo, size_t n) {
  if (n < 2) {
    return; // No hay nada que invertir
  }
  int *inicio = arreglo;
  int *fin = arreglo + n - 1;

  while (inicio < fin) {
    // Intercambiamos los valores
    int temp = *inicio;
    *inicio = *fin;
    *fin = temp;

    // Movemos los punteros hacia el centro
    inicio++;
    fin--;
  }
}

void imprimir_arreglo(int *arr, size_t n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int mi_arreglo[] = {1, 2, 3, 4, 5, 6};
  size_t cantidad = sizeof(mi_arreglo) / sizeof(mi_arreglo[0]);

  printf("Original: ");
  imprimir_arreglo(mi_arreglo, cantidad);

  invertir_arreglo(mi_arreglo, cantidad);

  printf("Invertido: ");
  imprimir_arreglo(mi_arreglo, cantidad);

  return 0;
}
```
````

## Próximos Pasos: Memoria Dinámica

Los punteros que estudiaste en este capítulo son fundamentales, pero hasta ahora solo trabajaste con memoria que el compilador gestiona automáticamente (variables locales y globales). El verdadero poder de los punteros se revela cuando aprendés a gestionar memoria **dinámicamente** durante la ejecución del programa.

En el {doc}`11_memoria`, vas a aprender sobre:

- **El heap (montón):** Una región de memoria que podés solicitar y liberar bajo demanda.
- **Funciones de asignación dinámica:** Como `malloc` y `calloc`, que te permiten crear estructuras de datos de tamaño variable.
- **Gestión manual de memoria:** Cómo y cuándo liberar la memoria que asignaste con `free`.
- **Punteros avanzados:** Incluyendo `void *`, casteos complejos, y punteros a arrays `(*)[N]`.
- **Errores de memoria:** Memory leaks, dangling pointers, y cómo evitarlos.

Estos conceptos amplían dramáticamente lo que podés hacer en C, permitiéndote crear programas que adaptan su uso de memoria a las necesidades del momento. Sin embargo, con este poder viene una gran responsabilidad: la gestión manual de memoria requiere disciplina y atención a los detalles.

Cuando te sientas cómodo con los conceptos de este capítulo, estás listo para dar el próximo paso hacia la memoria dinámica.
