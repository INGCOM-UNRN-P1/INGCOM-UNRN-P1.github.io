---
title: 'Punteros a Funciones'
short_title: 'Punteros III'
description: 'Punteros a funciones, genericidad básica en C utilizando void* y el uso de callbacks para ordenar y filtrar datos.'
---

(capitulo-punteros-funciones)=
# Lecturas Recomendadas

## Introducción

(genericidad-y-callbacks-punteros-a-funciones)=
# Genericidad y Callbacks (Punteros a Funciones)

En capítulos anteriores, exploramos cómo los punteros nos permiten referenciar y
manipular datos en el heap de manera dinámica. Sin embargo, en C, las
instrucciones ejecutables de una función también residen en la memoria virtual
(en el segmento de código o de texto del espacio de direcciones virtual del
proceso).

Un **puntero a función** almacena la dirección de memoria de una función
ejecutable, lo que nos permite invocarla dinámicamente y pasar comportamiento
como argumento a otras funciones. Este mecanismo se conoce como **callback** y
es el pilar para construir código genérico y extensible en C.

## Desarrollo

(punteros-a-funciones-sintaxis-y-declaracion)=
### Punteros a Funciones: Sintaxis y Declaración


La sintaxis para declarar un puntero a función en C puede parecer compleja al
principio, ya que requiere agrupar el operador de indirección con el nombre del
puntero para diferenciarlo de una función que retorna un puntero.

(declaracion-basica)=
#### Declaración Básica

La estructura general de una declaración es:

:::{code-block}c

tipo_retorno (*nombre_puntero)(tipo_parametro1, tipo_parametro2, ...);

:::
<!-- {code-block}c -->

*   El paréntesis alrededor de `*nombre_puntero` es **obligatorio**. Si se
    omite, se declara una función normal que retorna un puntero del tipo
    especificado.

:::{code-block}c

int *funcion(int, int);   // Declaración de una función que retorna un puntero a
int (int *)
int (*puntero)(int, int); // Declaración de un puntero a una función que retorna
int

:::
<!-- {code-block}c -->

(asignacion-e-invocacion)=
#### Asignación e Invocación

Asignar una función a un puntero es directo: solo se utiliza el nombre de la
función (que decae en su dirección de instrucción en el segmento de código
virtual del proceso).

:::{code-block}c
:linenos:
#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int main(void) {
    // Declaración
    int (*operacion)(int, int);

    // Asignación
    operacion = sumar; // O bien: operacion = &sumar;

    // Invocación (ambas sintaxis son válidas bajo el estándar)
    int res1 = operacion(5, 3);   // Invocación directa (sintaxis recomendada
    por legibilidad)
    int res2 = (*operacion)(5, 3); // Invocación explícita desreferenciando el
    puntero

    printf("Resultados: %d, %d\n", res1, res2);
    return 0;
}

:::
<!-- {code-block}c -->

(simplificacion-con-typedef)=
#### Simplificación con `typedef`

Para evitar declarar firmas de punteros complejas repetidamente, es una buena
práctica de ingeniería de software definir alias de tipos utilizando `typedef`
(regla {ref}`0x3004h`):

:::{code-block}c
:linenos:
// Definimos el alias 'operacion_fn' para representar punteros a funciones (int,
int) -> int
typedef int (*operacion_fn)(int, int);

// Ahora la declaración es simple:
operacion_fn mi_operacion = sumar;

:::
<!-- {code-block}c -->

---

(ejercicios-de-autoevaluacion-sintaxis-y-declaracion)=
#### Ejercicios de Autoevaluación (Sintaxis y Declaración)







---


(callbacks-comportamiento-como-parametro)=
### Callbacks: Comportamiento como Parámetro


Un **callback** es una función que se pasa a otra función como argumento para
ser ejecutada ("llamada de vuelta") bajo ciertas condiciones o flujos de
control.

(ejemplo-clasico-qsort-de-la-biblioteca-estandar)=
#### Ejemplo Clásico: qsort() de la Biblioteca Estándar

El ejemplo por excelencia de genericidad y callbacks es `qsort` (definida en
`<stdlib.h>`), la cual implementa el algoritmo de ordenamiento rápido QuickSort
de forma genérica para cualquier tipo de arreglo:

:::{code-block}c

void qsort(void *base, size_t nmemb, size_t size,
           int (*comparar)(const void *, const void *));

:::
<!-- {code-block}c -->

Para ordenar un arreglo, le proveemos a `qsort`:
1. `void *base`: Dirección del primer elemento.
2. `size_t nmemb`: Cantidad de elementos del arreglo.
3. `size_t size`: Tamaño en bytes de cada elemento (ej: `sizeof(int)`).
4. `comparar`: Un callback de comparación que acepta dos punteros constantes
   genéricos `const void *` y retorna un entero:
   * Menor a 0 si el primer elemento es menor al segundo.
   * 0 si son iguales.
   * Mayor a 0 si el primer elemento es mayor al segundo.

##### Implementación Completa con qsort()

```{code} c
:caption: Uso de qsort con callbacks para ordenar enteros y structs en C
:label: qsort-callback-example
:linenos:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int edad;
} Persona;

// Callback para ordenar enteros de menor a mayor
int comparar_enteros(const void *a, const void *b) {
    // 1. Casteamos los punteros genéricos const void* al tipo real const int*
    const int *ptr_a = (const int *)a;
    const int *ptr_b = (const int *)b;

    // 2. Desreferenciamos y comparamos
    if (*ptr_a < *ptr_b) {
        return -1;
    }
    if (*ptr_a > *ptr_b) {
        return 1;
    }
    return 0;
}

// Callback para ordenar personas por edad
int comparar_personas_edad(const void *a, const void *b) {
    const Persona *p1 = (const Persona *)a;
    const Persona *p2 = (const Persona *)b;

    if (p1->edad < p2->edad) return -1;
    if (p1->edad > p2->edad) return 1;
    return 0;
}

int main(void) {
    int numeros[] = {34, 12, 5, 90, 45};
    size_t cant_nums = sizeof(numeros) / sizeof(numeros[0]);

    qsort(numeros, cant_nums, sizeof(int), comparar_enteros);

    printf("Numeros ordenados: ");
    for (size_t i = 0; i < cant_nums; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    Persona grupo[] = {
        {"Carlos", 30},
        {"Ana", 25},
        {"Beatriz", 28}
    };
    size_t cant_personas = sizeof(grupo) / sizeof(Persona);

    qsort(grupo, cant_personas, sizeof(Persona), comparar_personas_edad);

    printf("\nPersonas ordenadas por edad:\n");
    for (size_t i = 0; i < cant_personas; i++) {
        printf("- %s (%d anos)\n", grupo[i].nombre, grupo[i].edad);
    }

    return 0;
}

```
<!-- {code} c -->

---

(ejercicios-de-autoevaluacion-callbacks-y-qsort)=
#### Ejercicios de Autoevaluación (Callbacks y qsort)







---


(genericidad-en-c-mediante-void)=
### Genericidad en C mediante `void *`


Dado que C carece de tipos genéricos en tiempo de compilación (como *templates*
de C++ o genéricos de Java), la genericidad se simula a bajo nivel utilizando
punteros genéricos `void *`.

(reglas-de-oro-para-trabajar-con-void)=
#### Reglas de Oro para Trabajar con `void *`

1. **No se puede desreferenciar directamente un `void *`**: Como el compilador
   no sabe cuántos bytes ocupa el tipo apuntado, la expresión `*p_void` genera
   un error de compilación. Siempre debés realizar un casteo explícito a un
   puntero del tipo real antes de acceder a la memoria.
2. **No se permite aritmética de punteros sobre `void *`**: Sumar o restar a un
   `void *` genera comportamiento indefinido o errores, ya que la escala de
   incremento depende del tamaño del tipo. Nuevamente, debés castear previamente
   a un tipo con tamaño conocido (ej: `char *` para aritmética byte a byte).

(disenando-una-funcion-generica-de-busqueda-lineal)=
#### Diseñando una Función Genérica de Búsqueda Lineal

Para consolidar estos conceptos, implementemos nuestro propio algoritmo genérico
de búsqueda lineal, capaz de buscar en cualquier tipo de arreglo utilizando un
callback de comparación:

```{code} c
:caption: Implementación de búsqueda lineal genérica en C usando callbacks y void*
:label: generic-search-example
:linenos:

#include <stdio.h>
#include <stddef.h>
#include <string.h>

// Definición de tipo para el callback de comparación
typedef int (*comparar_fn)(const void *, const void *);

// Función genérica de búsqueda lineal
// Retorna la dirección del elemento si se encuentra, o NULL si no está.
const void *buscar_generico(const void *base, size_t nmemb, size_t size, 
                            const void *clave, comparar_fn cmp) {
    if (base == NULL || clave == NULL || cmp == NULL) {
        return NULL;
    }

    // Convertimos a const char* para poder realizar aritmética de punteros byte a byte
    const char *ptr = (const char *)base;

    for (size_t i = 0; i < nmemb; i++) {
        // Calculamos la dirección del elemento i-ésimo: base + i * size
        const void *elemento = ptr + (i * size);

        // Invocamos el callback de comparación
        if (cmp(elemento, clave) == 0) {
            return elemento; // Encontrado
        }
    }
    return NULL; // No encontrado
}

// Callback para buscar en enteros
int cmp_enteros(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int clave = 30;

    const void *resultado = buscar_generico(arr, n, sizeof(int), &clave, cmp_enteros);

    if (resultado != NULL) {
        printf("El numero %d fue encontrado en la posicion: %ld\n", 
               clave, ((const int *)resultado - arr));
    } else {
        printf("El numero %d no fue encontrado.\n", clave);
    }
    return 0;
}

```
<!-- {code} c -->

(ejercicios-de-autoevaluacion-genericidad-y-void)=
#### Ejercicios de Autoevaluación (Genericidad y void*)







---

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-fn-ptr-sintaxis-error
Explicá detalladamente la diferencia sintáctica y el significado para el
compilador de las siguientes dos declaraciones:
1. `double *procesar(double, double);`
2. `double (*procesar)(double, double);`

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-sintaxis-error
:class: dropdown
1. **`double *procesar(double, double);`**: Declara un prototipo de función
   ordinario llamado `procesar` que recibe dos parámetros de tipo `double` y
   retorna un **puntero a double** (`double *`).
2. **`double (*procesar)(double, double);`**: El paréntesis altera la
   precedencia indicando que el operador `*` se asocia directamente con el
   identificador. Declara una variable llamada `procesar` cuyo tipo de dato es
   **puntero a función**, la cual recibe dos parámetros de tipo `double` y
   retorna un valor de tipo `double`.

:::
<!-- {solution} ej-fn-ptr-sintaxis-error -->

:::{exercise}
:label: ej-fn-ptr-typedef-alias
Escribí la declaración de un alias de tipo utilizando `typedef` de acuerdo con
la regla de la cátedra {ref}`0x3004h` para representar punteros a funciones que
reciben como parámetro una cadena de caracteres constante (`const char *`) y
retornan un entero de tipo `size_t`.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-typedef-alias
:class: dropdown
La sintaxis correcta aplicando el sufijo de alias de tipo `_t` es:
``` c
#include <stddef.h>

typedef size_t (*medidor_cadena_fn_t)(const char *);
```
<!-- c -->
Este alias `medidor_cadena_fn_t` permite declarar punteros a funciones de forma
sencilla:
``` c
medidor_cadena_fn_t mi_funcion = strlen;
```
<!-- c -->

:::
<!-- {solution} ej-fn-ptr-typedef-alias -->

:::{exercise}
:label: ej-fn-ptr-invocacion-variacion
Dada una función `int multiplicar(int a, int b);` y un puntero a función
declarado y asignado como `int (*operacion)(int, int) = multiplicar;`, escribí
las dos líneas de código válidas bajo el estándar de C para realizar la
invocación de la función con los argumentos `10` y `20` a través del puntero,
indicando cuál es la preferida por legibilidad.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-invocacion-variacion
:class: dropdown
Las dos formas de invocación soportadas son:
1. **Invocación explícita (desreferencia)**:
   ```c
   int res1 = (*operacion)(10, 20);
   ```
2. **Invocación implícita o directa**:
   ```c
   int res2 = operacion(10, 20);
   ```
Ambas son funcionalmente idénticas debido a que el compilador de C promociona
automáticamente el identificador de la función a su dirección de instrucción en
el segmento de código virtual del proceso. La cátedra
prefiere y recomienda la **segunda variante** (invocación directa) por
asemejarse a una llamada de función estándar, mejorando la claridad de lectura
del código.

:::
<!-- {solution} ej-fn-ptr-invocacion-variacion -->

:::{exercise}
:label: ej-fn-ptr-qsort-reversa
Escribí un callback de comparación compatible con `qsort` llamado
`comparar_reversa` que permita ordenar un arreglo de enteros de forma
descendente (de mayor a menor).

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-qsort-reversa
:class: dropdown
```{code-block} c
:linenos:
int comparar_reversa(const void *a, const void *b) {
    // 1. Casteamos los punteros genéricos const void* al tipo real const int*
    const int *ptr_a = (const int *)a;
    const int *ptr_b = (const int *)b;

    // 2. Para orden descendente:
    // Retorna mayor a 0 si b > a, menor a 0 si a > b, 0 si son iguales.
    if (*ptr_a < *ptr_b) {
        return 1;
    }
    if (*ptr_a > *ptr_b) {
        return -1;
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-fn-ptr-qsort-reversa -->

:::{exercise}
:label: ej-fn-ptr-qsort-cadenas
Escribí un callback de comparación para `qsort` que permita ordenar
alfabéticamente un arreglo de cadenas de caracteres (`const char *`).

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-qsort-cadenas
:class: dropdown
Al pasar un arreglo de cadenas `char *arr[]` a `qsort`, los elementos
individuales que se comparan son de tipo `char *`. Dado que `qsort` pasa
punteros a los elementos del arreglo, los punteros genéricos `a` y `b` que
recibe el callback deben ser interpretados como punteros a cadenas, es decir,
`const char **`.
```{code-block} c
:linenos:
#include <string.h>

int comparar_cadenas(const void *a, const void *b) {
    // Casteo a puntero de cadena (char**)
    const char * const *str_a = (const char * const *)a;
    const char * const *str_b = (const char * const *)b;

    // Comparación léxica de los contenidos apuntados
    return strcmp(*str_a, *str_b);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-fn-ptr-qsort-cadenas -->

:::{exercise}
:label: ej-fn-ptr-qsort-struct-dos-criterios
Dada la estructura:
``` c
typedef struct {
    int codigo;
    double precio;
} producto_t;
```
<!-- c -->
Implementá un callback de comparación para ordenar un arreglo de `producto_t`
por `precio` de menor a mayor. En caso de que dos productos tengan el mismo
precio, se debe desempatar ordenando por `codigo` de menor a mayor.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-qsort-struct-dos-criterios
:class: dropdown
```{code-block} c
:linenos:
int comparar_productos(const void *a, const void *b) {
    const producto_t *p1 = (const producto_t *)a;
    const producto_t *p2 = (const producto_t *)b;

    // Primer criterio: comparación de precios
    if (p1->precio < p2->precio) {
        return -1;
    }
    if (p1->precio > p2->precio) {
        return 1;
    }

    // Segundo criterio (desempate): comparación de códigos
    if (p1->codigo < p2->codigo) {
        return -1;
    }
    if (p1->codigo > p2->codigo) {
        return 1;
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-fn-ptr-qsort-struct-dos-criterios -->

:::{exercise}
:label: ej-fn-ptr-void-dereferencia
Explicá por qué el compilador de C rechaza expresiones como `*ptr` o `ptr++`
cuando la variable `ptr` es un puntero genérico de tipo `void *`, y cómo se debe
proceder para realizar la manipulación correcta de la memoria física.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-void-dereferencia
:class: dropdown
El tipo `void *` representa una dirección de memoria genérica sin información
sobre el tipo de dato subyacente.
- **Desreferencia (`*ptr`)**: Para leer o escribir a través de un puntero, el
  compilador requiere saber cuántos bytes ocupa el dato (por ejemplo, 4 bytes
  para un `int`, 8 para un `double`) para leer la palabra de memoria correcta.
  Al ser `void` (vacío de tipo), el tamaño es indeterminado, resultando en un
  error de compilación.
- **Aritmética (`ptr++`)**: Para avanzar al siguiente elemento, el compilador
  escala la suma de bytes por el tamaño del tipo apuntado (`sizeof(tipo)`). Sin
  tipo asociado, el tamaño es desconocido.
La solución consiste en realizar un casteo (*cast*) explícito al tipo de puntero
real correspondiente antes de operar (por ejemplo, `const char *` para
aritmética byte a byte).

:::
<!-- {solution} ej-fn-ptr-void-dereferencia -->

:::{exercise}
:label: ej-fn-ptr-generic-filter
Implementá una función genérica en C llamada `filtrar_arreglo` que reciba un
arreglo genérico de elementos, su cantidad, el tamaño en bytes de cada elemento,
un callback de predicado (que reciba `const void*` y retorne un booleano `int`),
y un callback de impresión. La función debe recorrer el arreglo e imprimir los
elementos que cumplan con la condición.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-generic-filter
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <stddef.h>

typedef int (*predicado_fn_t)(const void *);
typedef void (*imprimir_fn_t)(const void *);

void filtrar_arreglo(const void *base, size_t nmemb, size_t size, 
                     predicado_fn_t predicado, imprimir_fn_t imprimir) {
    if (base == NULL || predicado == NULL || imprimir == NULL) {
        return;
    }

    // Casteo a const char* para aritmética de punteros byte a byte
    const char *ptr = (const char *)base;

    for (size_t i = 0; i < nmemb; i++) {
        // Cálculo de dirección del elemento i-ésimo: base + i * size
        const void *elem = ptr + (i * size);

        if (predicado(elem)) {
            imprimir(elem);
        }
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-fn-ptr-generic-filter -->

:::{exercise}
:label: ej-fn-ptr-generic-swap
Implementá un procedimiento genérico en C llamado `intercambiar_bloques` que
reciba dos punteros genéricos `void *a` y `void *b` junto con el tamaño de su
tipo `size_t size` en bytes, y realice el intercambio de sus contenidos físicos
byte a byte en memoria.

:::
<!-- {exercise} -->

:::{solution} ej-fn-ptr-generic-swap
:class: dropdown
```{code-block} c
:linenos:
#include <stddef.h>

void intercambiar_bloques(void *a, void *b, size_t size) {
    if (a == NULL || b == NULL || size == 0) {
        return;
    }

    // Casteo a char* para operar sobre bytes individuales de forma contigua
    char *ptr_a = (char *)a;
    char *ptr_b = (char *)b;

    for (size_t i = 0; i < size; i++) {
        // Intercambio clásico byte a byte
        char temp = ptr_a[i];
        ptr_a[i] = ptr_b[i];
        ptr_b[i] = temp;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-fn-ptr-generic-swap -->

## Glosario

:::{glossary}

Puntero a Función
: Puntero que almacena la dirección de código ejecutable.

Callback
: Función pasada como argumento a otra función para ser invocada posteriormente.

Genericidad
: Técnica de programación que permite escribir algoritmos independientes del
tipo de datos.

:::
<!-- {glossary} -->

## Síntesis y Resumen

En este apunte se han presentado los conceptos fundamentales del tema.

## Referencias y Lecturas Complementarias

(lecturas-recomendadas)=
### Lecturas Recomendadas


- **{cite:t}`king_c_2008`**. Capítulo 17: Advanced Uses of Pointers (sección de
  punteros a funciones).
- **{cite:t}`kernighan_c_2014`**. Capítulo 5: Pointers and Arrays (sección sobre
  punteros a funciones y qsort).
