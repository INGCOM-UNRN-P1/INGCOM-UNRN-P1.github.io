---
title: 'Genericidad y Callbacks (Punteros a Funciones)'
short_title: '16 - Callbacks y Genericidad'
description: 'Punteros a funciones, genericidad básica en C utilizando void* y el uso de callbacks para ordenar y filtrar datos.'
---

(callbacks-genericidad-capitulo)=
# Genericidad y Callbacks (Punteros a Funciones)

En capítulos anteriores, exploramos cómo los punteros nos permiten referenciar y manipular datos en el heap de manera dinámica. Sin embargo, en C, las instrucciones ejecutables de una función también residen en la memoria física (en el segmento de código o de texto). 

Un **puntero a función** almacena la dirección de memoria de una función ejecutable, lo que nos permite invocarla dinámicamente y pasar comportamiento como argumento a otras funciones. Este mecanismo se conoce como **callback** y es el pilar para construir código genérico y extensible en C.

## Punteros a Funciones: Sintaxis y Declaración

La sintaxis para declarar un puntero a función en C puede parecer compleja al principio, ya que requiere agrupar el operador de indirección con el nombre del puntero para diferenciarlo de una función que retorna un puntero.

### Declaración Básica

La estructura general de una declaración es:

```{code-block}c
tipo_retorno (*nombre_puntero)(tipo_parametro1, tipo_parametro2, ...);
```

*   El paréntesis alrededor de `*nombre_puntero` es **obligatorio**. Si se omite, se declara una función normal que retorna un puntero del tipo especificado.

```{code-block}c
int *funcion(int, int);   // Declaración de una función que retorna un puntero a int (int *)
int (*puntero)(int, int); // Declaración de un puntero a una función que retorna int
```

### Asignación e Invocación

Asignar una función a un puntero es directo: solo se utiliza el nombre de la función (que decae en su dirección física de memoria).

```{code-block}c
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
    int res1 = operacion(5, 3);   // Invocación directa (sintaxis recomendada por legibilidad)
    int res2 = (*operacion)(5, 3); // Invocación explícita desreferenciando el puntero

    printf("Resultados: %d, %d\n", res1, res2);
    return 0;
}
```

### Simplificación con `typedef`

Para evitar declarar firmas de punteros complejas repetidamente, es una buena práctica de ingeniería de software definir alias de tipos utilizando `typedef` (regla {ref}`0x3004h`):

```{code-block}c
:linenos:
// Definimos el alias 'operacion_fn' para representar punteros a funciones (int, int) -> int
typedef int (*operacion_fn)(int, int);

// Ahora la declaración es simple:
operacion_fn mi_operacion = sumar;
```

---

## Callbacks: Comportamiento como Parámetro

Un **callback** es una función que se pasa a otra función como argumento para ser ejecutada ("llamada de vuelta") bajo ciertas condiciones o flujos de control.

### Ejemplo Clásico: qsort() de la Biblioteca Estándar

El ejemplo por excelencia de genericidad y callbacks es `qsort` (definida en `<stdlib.h>`), la cual implementa el algoritmo de ordenamiento rápido QuickSort de forma genérica para cualquier tipo de arreglo:

```{code-block}c
void qsort(void *base, size_t nmemb, size_t size,
           int (*comparar)(const void *, const void *));
```

Para ordenar un arreglo, le proveemos a `qsort`:
1. `void *base`: Dirección del primer elemento.
2. `size_t nmemb`: Cantidad de elementos del arreglo.
3. `size_t size`: Tamaño en bytes de cada elemento (ej: `sizeof(int)`).
4. `comparar`: Un callback de comparación que acepta dos punteros constantes genéricos `const void *` y retorna un entero:
   * Menor a 0 si el primer elemento es menor al segundo.
   * 0 si son iguales.
   * Mayor a 0 si el primer elemento es mayor al segundo.

#### Implementación Completa con qsort()

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

    return p1->edad - p2->edad;
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

---

## Genericidad en C mediante `void *`

Dado que C carece de tipos genéricos en tiempo de compilación (como *templates* de C++ o genéricos de Java), la genericidad se simula a bajo nivel utilizando punteros genéricos `void *`.

### Reglas de Oro para Trabajar con `void *`

1. **No se puede desreferenciar directamente un `void *`**: Como el compilador no sabe cuántos bytes ocupa el tipo apuntado, la expresión `*p_void` genera un error de compilación. Siempre debés realizar un casteo explícito a un puntero del tipo real antes de acceder a la memoria.
2. **No se permite aritmética de punteros sobre `void *`**: Sumar o restar a un `void *` genera comportamiento indefinido o errores, ya que la escala de incremento depende del tamaño del tipo. Nuevamente, debés castear previamente a un tipo con tamaño conocido (ej: `char *` para aritmética byte a byte).

### Diseñando una Función Genérica de Búsqueda Lineal

Para consolidar estos conceptos, implementemos nuestro propio algoritmo genérico de búsqueda lineal, capaz de buscar en cualquier tipo de arreglo utilizando un callback de comparación:

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
    return *(const int *)a - *(const int *)b;
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

## Ejercicios Prácticos

```{exercise}
:label: ej-genericidad-filtrar
Escribir una función genérica `filtrar_elementos` en C que reciba un arreglo genérico, su tamaño, el tamaño de cada elemento, y un callback de predicado (una función que recibe `const void*` y retorna un booleano `int`). La función debe imprimir los elementos que satisfagan el predicado.
```

:::{solution} ej-genericidad-filtrar
```{code-block}c
:linenos:
#include <stdio.h>
#include <stddef.h>

typedef int (*predicado_fn)(const void *);

void filtrar_elementos(const void *base, size_t nmemb, size_t size, predicado_fn predicado, void (*imprimir)(const void *)) {
    const char *ptr = (const char *)base;
    for (size_t i = 0; i < nmemb; i++) {
        const void *elem = ptr + (i * size);
        if (predicado(elem)) {
            imprimir(elem);
        }
    }
}

// Ejemplo de uso para números pares:
int es_par(const void *a) {
    return (*(const int *)a % 2) == 0;
}

void imprimir_int(const void *a) {
    printf("%d ", *(const int *)a);
}

int main(void) {
    int datos[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t n = sizeof(datos) / sizeof(datos[0]);
    
    printf("Numeros pares filtrados: ");
    filtrar_elementos(datos, n, sizeof(int), es_par, imprimir_int);
    printf("\n");
    return 0;
}
```
:::

## Lecturas Recomendadas

- **{cite:t}`king_c_2008`**. Capítulo 17: Advanced Uses of Pointers (sección de punteros a funciones).
- **{cite:t}`kernighan_c_2014`**. Capítulo 5: Pointers and Arrays (sección sobre punteros a funciones y qsort).
