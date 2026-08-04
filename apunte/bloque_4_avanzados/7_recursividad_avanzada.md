---
title: Recursión de Cola y Divide y Vencerás
short_title: 'Recursión Avanzada'
subtitle: 'TCO, optimización de la pila y algoritmos de división recursiva en C'
---

(capitulo-recursividad-avanzada)=
# Ventajas y Desventajas

## Introducción

(recursividad-avanzada-capitulo)=

## Desarrollo

### Recursión de Cola (Tail Recursion) y Optimización TCO


Una llamada recursiva se considera **recursiva de cola** (*tail recursive*) si
la llamada a sí misma es la última instrucción ejecutada por la función antes de
retornar, y su resultado se devuelve directamente sin realizar ninguna operación
aritmética o lógica adicional.

Por ejemplo, la función `factorial` tradicional expuesta en el apunte
introductorio **no** es recursiva de cola porque, tras el retorno de
`factorial(n - 1)`, la función debe realizar la multiplicación por `n`.

Podemos reescribir la función factorial para que sea recursiva de cola
utilizando un acumulador:

```{code-block} c
:linenos:
long int factorial_tail_rec(int n, long int acumulador) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return acumulador;
    }
    // La llamada recursiva es la última operación física.
    return factorial_tail_rec(n - 1, n * acumulador);
}

```
<!-- {code-block} c -->

#### Optimización por parte del compilador (TCO)

Cuando una llamada es recursiva de cola, los compiladores modernos pueden
aplicar una optimización llamada **Tail Call Optimization (TCO)**. En lugar de
empujar un nuevo marco de pila al *call stack*, el compilador sobrescribe el
marco de pila de la función actual y reutiliza sus registros y variables
locales, transformando efectivamente la recursión en un salto incondicional
(equivalente a un lazo de control). Esto reduce la complejidad espacial auxiliar
del algoritmo de $O(n)$ a $O(1)$.

:::{warning} Falta de Garantías en C

El estándar ISO/IEC 9899 (C estándar) **no** garantiza ni exige la optimización
TCO. Su aplicación depende exclusivamente del compilador y el nivel de
optimización configurado (como `-O2` o `-O3` en GCC o Clang). Confiar en TCO
para la estabilidad y robustez de un software crítico en C de producción
constituye un antipatrón. Si se requiere un consumo constante de memoria, se
debe implementar una versión puramente iterativa utilizando lazos.

:::
<!-- {warning} Falta de Garantías en C -->

:::{warning} Recursión vs. Iteración

Para tareas lineales simples (como recorrer una lista, buscar un elemento o
sumar valores de forma consecutiva), la iteración mediante **lazos de control**
(`for` o `while`) es infinitamente más segura y eficiente. Los lazos no consumen
marcos de pila adicionales por cada repetición. Por lo tanto, reservá la
recursividad para estructuras de datos intrínsecamente jerárquicas o ramificadas
(como árboles y grafos) o algoritmos basados en *Divide y Vencerás* con
profundidad de pila acotada (usualmente $O(\log n)$).

:::
<!-- {warning} Recursión vs. Iteración -->

A continuación se presenta una tabla comparativa sobre el uso de recursos entre
ambas aproximaciones:

:::{table} Comparación de recursos: Iteración vs. Recursividad
:label: tbl-iter-vs-recur

| Aspecto | Iteración (Lazos) | Recursividad |
| :--- | :--- | :--- |
| **Uso de Memoria en el Stack** | $O(1)$ constante. El mismo marco de pila se reutiliza durante todo el lazo. | $O(d)$ donde $d$ es la profundidad máxima de llamadas (salvo TCO exitoso). |
| **Rendimiento** | Más rápido. Evita la sobrecarga de llamadas y retornos de función. | Más lento por la constante asignación y liberación de marcos de pila. |
| **Límite de Ejecución** | Limitado solo por el tiempo de procesamiento o valores numéricos. | Físicamente limitado por el tamaño máximo del *stack* del sistema. |

:::
<!-- {table} Comparación de recursos: Iteración vs. Recursividad -->







---


### Paradigma de Divide y Vencerás


El paradigma de "Divide y Conquista" (Divide and Conquer) es una potente
estrategia para el diseño de algoritmos que consiste en resolver un problema
complejo descomponiéndolo en subproblemas más pequeños y manejables. Este
paradigma aplica naturalmente la recursividad para su implementación. El proceso
se puede resumir en tres fases principales:

1.  **Dividir:** Se descompone el problema principal en un número de
    subproblemas que son instancias más pequeñas del mismo problema.
2.  **Conquistar:** Se resuelven los subproblemas de forma recursiva. Si un
    subproblema es lo suficientemente pequeño (caso base), se resuelve de manera
    directa.
3.  **Combinar:** Se combinan las soluciones de los subproblemas para construir
    la solución del problema original.

Este flujo de trabajo de divide y vencerás se puede visualizar de manera gráfica
en el algoritmo de ordenamiento Merge Sort:

:::{figure} ../bloque_3_algoritmos_estructuras/7/divide_conquista_merge.svg
:label: fig-divide-conquista
:align: center
:width: 85%

Paradigma de Divide y Vencerás aplicado a la ordenación del arreglo [12, 11, 13,
5] mediante Merge Sort.

:::
<!-- {figure} ../bloque_1_fundamentos/6/divide_conquista_merge.svg -->

#### Ejemplo 1: Búsqueda Binaria

La búsqueda binaria es un algoritmo altamente eficiente para localizar un
elemento dentro de un **arreglo ordenado**. Se basa en el paradigma de divide y
conquista.

Sin embargo, a menudo se enseña implementado mediante recursividad, lo cual es
ineficiente desde la perspectiva del uso de memoria en sistemas reales.

* **Fase de División:** Se compara el elemento buscado con el valor central del
  subarreglo. El espacio de búsqueda se reduce a la mitad.
* **Fase de Conquista:** Si hay coincidencia, se retorna la posición. De lo
  contrario, se realiza una llamada recursiva sobre el subarreglo izquierdo o
  derecho. El caso base ocurre cuando el subarreglo está vacío (índices
  cruzados).
* **Fase de Combinación:** Es trivial, ya que el resultado encontrado se propaga
  directamente hacia arriba en la pila.

##### Justificación del Consumo de Pila y Complejidad Espacial

En la versión recursiva, cada paso de división genera un nuevo marco de pila.
Como el espacio se reduce a la mitad en cada paso, la profundidad máxima de la
pila es de $O(\log n)$. Por ende, consume un espacio auxiliar de $O(\log n)$
marcos de pila en el stack del sistema.

En contraste, la versión iterativa clásica resuelve el mismo problema utilizando
un único lazo de control `while` y variables locales reescritas, requiriendo un
espacio espacial auxiliar de $O(1)$ (constante) de manera óptima, lo que elimina
cualquier riesgo de *stack overflow*.

##### Implementaciones en C

Para cumplir con la regla de uso de variables de tipo `size_t` en índices y
tamaños (regla {ref}`0x3010h`), debemos prever y evitar el desbordamiento por
decremento bajo cero (ya que `size_t` es un tipo de dato sin signo). Además,
declaramos el arreglo de entrada como `const` dado que la función no modifica
sus elementos (regla {ref}`0x3007h`).

```{code-block} c
:linenos:
#include <stdio.h>
#include <stddef.h>

// Búsqueda binaria recursiva
int buscar_binario_recursivo(const int arr[], size_t l, size_t r, int x, size_t *indice_encontrado) {
    if (l <= r) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            *indice_encontrado = mid;
            return 1;
        }

        if (arr[mid] > x) {
            if (mid > 0) {
                return buscar_binario_recursivo(arr, l, mid - 1, x, indice_encontrado);
            }
        } else {
            return buscar_binario_recursivo(arr, mid + 1, r, x, indice_encontrado);
        }
    }
    return 0; // Caso base: no encontrado
}

// Búsqueda binaria iterativa (espacio O(1) óptimo)
int buscar_binario_iterativo(const int arr[], size_t size, int x, size_t *indice_encontrado) {
    if (size == 0) {
        return 0;
    }
    size_t l = 0;
    size_t r = size - 1;

    while (l <= r) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            *indice_encontrado = mid;
            return 1;
        }

        if (arr[mid] > x) {
            if (mid == 0) {
                break; // Evita el desbordamiento inferior de size_t al decrementar
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}

```
<!-- {code-block} c -->

#### Ejemplo 2: Ordenamiento por Fusión (Merge Sort)

Merge Sort representa una aplicación más compleja del paradigma de divide y
vencerás que involucra recursión múltiple (dos llamadas recursivas) y una fase
de combinación no trivial (la fusión de arreglos ordenados).

* **Dividir:** Se divide el arreglo de $n$ elementos en dos subarreglos de
  tamaño $n/2$ cada uno.
* **Conquistar:** Se ordena cada subarreglo de forma recursiva. El caso base es
  un arreglo de longitud menor o igual a 1, que ya se encuentra ordenado.
* **Combinar:** Se fusionan (*merge*) los dos subarreglos ya ordenados para
  producir el arreglo final ordenado.

Este flujo no lineal de llamadas se puede visualizar detalladamente en la
siguiente traza de ejecución:

:::{figure} ../bloque_3_algoritmos_estructuras/7/traza_merge_sort.svg
:label: fig-traza-merge-sort
:align: center
:width: 85%

Árbol de llamadas recursivas y secuencia de fusión para Merge Sort con el
arreglo inicial [5, 2, 7, 3]. Los números en los círculos indican el orden
cronológico de ejecución (DFS).

:::
<!-- {figure} ../bloque_1_fundamentos/6/traza_merge_sort.svg -->

##### Deficiencia del malloc en recursión profunda y optimización de buffer único

:::{important} Evitar Reservas Dinámicas Repetitivas

Una implementación ingenua de Merge Sort reserva memoria dinámica mediante
`malloc` dentro de la función `merge` en cada nivel de recursión para crear
subarreglos temporales.

Realizar `malloc` y `free` repetidamente en un algoritmo recursivo introduce una
enorme sobrecarga debido a las llamadas al sistema (*system calls*) para
interactuar con el administrador de memoria del sistema operativo, fragmentando
además el heap.

La forma correcta y óptima de resolver esto es preasignar un **único arreglo
auxiliar** de tamaño $n$ en la función envolvente (wrapper) y propagarlo
mediante punteros a lo largo de las sucesivas llamadas recursivas, eliminando
cualquier reserva de memoria intermedia.

:::
<!-- {important} Evitar Reservas Dinámicas Repetitivas -->

##### Implementación Optimizada en C

A continuación se expone la implementación correcta de Merge Sort. En
concordancia con las reglas de estilo de la cátedra, todos los bloques y
estructuras de control emplean llaves obligatoriamente (regla {ref}`0x1001h`) y
los tamaños e índices se definen utilizando el tipo `size_t` (regla
{ref}`0x3010h`).

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>

// Combina dos mitades ordenadas arr[l..m] y arr[m+1..r] utilizando el búfer auxiliar único aux[]
void fusionar(int arr[], size_t l, size_t m, size_t r, int aux[]) {
    size_t i = l;
    size_t j = m + 1;
    size_t k = l;

    for (size_t idx = l; idx <= r; idx++) {
        aux[idx] = arr[idx];
    }

    while ((i <= m) && (j <= r)) {
        if (aux[i] <= aux[j]) {
            arr[k] = aux[i];
            i++;
        } else {
            arr[k] = aux[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        arr[k] = aux[i];
        i++;
        k++;
    }

    while (j <= r) {
        arr[k] = aux[j];
        j++;
        k++;
    }
}

// Función recursiva interna
void merge_sort_recursivo(int arr[], size_t l, size_t r, int aux[]) {
    if (l < r) {
        size_t m = l + (r - l) / 2;

        merge_sort_recursivo(arr, l, m, aux);
        merge_sort_recursivo(arr, m + 1, r, aux);
        fusionar(arr, l, m, r, aux);
    }
}

// Función envolvente que preasigna el búfer auxiliar único
int ordenar_merge_sort(int arr[], size_t size) {
    if (size <= 1) {
        return 0; // Ya ordenado
    }

    int *aux = (int*) malloc(size * sizeof(*aux));

    // Validar asignación de memoria dinámica (regla {ref}`0x3001h`)
    if (aux == NULL) {
        return -1;
    }

    merge_sort_recursivo(arr, 0, size - 1, aux);

    free(aux);
    return 0;
}

```
<!-- {code-block} c -->

:::{warning} Validación de Memoria Dinámica

En C, toda asignación dinámica mediante `malloc` o `calloc` puede fallar si el
sistema no dispone de suficiente memoria. Para asegurar la robustez del
programa, es obligatorio verificar que los punteros obtenidos no sean `NULL`
antes de utilizarlos (regla {ref}`0x3001h`).

:::
<!-- {warning} Validación de Memoria Dinámica -->

:::{note} Complejidad

La relación de recurrencia para Merge Sort es $T(n) = 2T(n/2) + O(n)$. Esto se
resuelve a una complejidad temporal de $O(n \log n)$. Para un análisis
matemático de cómo se resuelve esta recurrencia, consultá la sección de
Complejidad.

:::
<!-- {note} Complejidad -->








### Ventajas y Desventajas


:::{list-table}
:header-rows: 1

* - Ventajas
  - Desventajas
* - Permite resolver problemas complejos de manera eficiente (por ejemplo, con
    complejidad $O(n \log n)$).
  - La sobrecarga de la recursividad (llamadas a funciones y uso de la pila)
    puede hacer que sea más lento que un enfoque iterativo para problemas
    pequeños.
* - Los algoritmos son naturalmente paralelizables, ya que los subproblemas son
    independientes.
  - Puede ser más complejo de implementar correctamente que las soluciones
    iterativas.
* - El código puede ser más elegante y fácil de entender, ya que refleja la
    estructura matemática del problema.
  - La recursividad profunda puede llevar a un desbordamiento de la pila (*stack
    overflow*) si no se maneja con cuidado.

:::
<!-- {list-table} -->

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-cola-suma-arreglo
Escribí una función recursiva de cola en C para sumar los elementos de un
arreglo de enteros. La función debe recibir un acumulador para permitir la
optimización TCO y tener la firma `int sumar_arreglo_cola(const int arr[],
size_t size, int acumulador)`.

:::
<!-- {exercise} -->

:::{solution} ej-cola-suma-arreglo
:class: dropdown
Siguiendo las reglas de estilo de la cátedra, el arreglo se declara como `const`
({ref}`0x3007h`) y el tamaño `size` utiliza el tipo `size_t` ({ref}`0x3010h`):

```{code-block} c
:linenos:
#include <stddef.h>

int sumar_arreglo_cola(const int arr[], size_t size, int acumulador) {
    // Caso Base: no quedan elementos por procesar
    if (size == 0) {
        return acumulador;
    }
    
    // Paso Recursivo de cola: sumamos el primer elemento al acumulador,
    // desplazamos el puntero del arreglo y decrementamos el tamaño
    return sumar_arreglo_cola(arr + 1, size - 1, acumulador + arr[0]);
}

```
<!-- {code-block} c -->

Dado que la llamada recursiva es la última instrucción ejecutada y su valor de
retorno no se ve afectado por operaciones aritméticas pendientes, los
compiladores modernos pueden reutilizar el mismo marco de pila (TCO) reduciendo
el uso de stack de $O(n)$ a $O(1)$.

:::
<!-- {solution} ej-cola-suma-arreglo -->

:::{exercise}
:label: ej-cola-fibonacci
La función de Fibonacci recursiva estándar tiene una complejidad temporal
exponencial de $O(2^n)$ y no es de cola. Diseñá una versión recursiva de cola en
C utilizando acumuladores para lograr una complejidad temporal lineal de $O(n)$
y espacial de $O(1)$ con TCO. La firma sugerida es: `unsigned long
fibonacci_cola(size_t n, unsigned long a, unsigned long b)`.

:::
<!-- {exercise} -->

:::{solution} ej-cola-fibonacci
:class: dropdown
Para resolver este ejercicio con recursión de cola, los acumuladores `a` y `b`
representarán los dos números consecutivos de Fibonacci $F(i)$ y $F(i+1)$ en
cada llamada:

```{code-block} c
:linenos:
#include <stddef.h>

// Para calcular F(n), la función debe invocarse inicialmente como:
// fibonacci_cola(n, 0, 1)
unsigned long fibonacci_cola(size_t n, unsigned long a, unsigned long b) {
    // Caso Base 1: n == 0 retorna el primer acumulador
    if (n == 0) {
        return a;
    }
    // Caso Base 2: n == 1 retorna el segundo acumulador
    if (n == 1) {
        return b;
    }
    // Paso recursivo de cola: decrementamos n, el acumulador 'a' pasa a ser 'b'
    // y el acumulador 'b' toma el valor de la suma acumulada 'a + b'
    return fibonacci_cola(n - 1, b, a + b);
}

```
<!-- {code-block} c -->

Al ser recursiva de cola pura y estar libre de operaciones pendientes tras la
invocación recursiva, el compilador puede optimizar esta función reemplazando el
marco en pila, logrando un espacio constante de pila.

:::
<!-- {solution} ej-cola-fibonacci -->

:::{exercise}
:label: ej-cola-conteo-digitos
Transformá la definición recursiva estándar para contar dígitos de un número
entero positivo (vista en el ejercicio {ref}`ej-def-mat-cantidad-digitos`) a una
función con recursión de cola en C.

:::
<!-- {exercise} -->

:::{solution} ej-cola-conteo-digitos
:class: dropdown
Para estructurar la recursión de cola, implementamos un acumulador que registre
la cantidad de dígitos procesados en cada paso recursivo:

```{code-block} c
:linenos:
#include <stddef.h>

// La función envolvente debe invocarla inicialmente con acumulador = 0
size_t contar_digitos_cola(unsigned long n, size_t acumulador) {
    // Caso Base: si el número es menor a 10, sumamos el último dígito y retornamos
    if (n < 10) {
        return acumulador + 1;
    }
    
    // Paso Recursivo de cola: dividimos el número y sumamos 1 al acumulador
    return contar_digitos_cola(n / 10, acumulador + 1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-cola-conteo-digitos -->

:::{exercise}
:label: ej-divide-maximo
Escribí una función recursiva en C que encuentre el elemento máximo de un
arreglo de enteros utilizando el paradigma de Divide y Vencerás. La firma debe
ser `int maximo_divide_y_venceras(const int arr[], size_t ini, size_t fin)`.

:::
<!-- {exercise} -->

:::{solution} ej-divide-maximo
:class: dropdown
De acuerdo a las reglas de estilo, el arreglo es `const` ({ref}`0x3007h`) y los
índices son de tipo `size_t` ({ref}`0x3010h`):

```{code-block} c
:linenos:
#include <stddef.h>

int maximo_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    if (ini == fin) {
        return arr[ini];
    }
    
    size_t mid = ini + (fin - ini) / 2;
    int max_izq = maximo_divide_y_venceras(arr, ini, mid);
    int max_der = maximo_divide_y_venceras(arr, mid + 1, fin);
    
    if (max_izq > max_der) {
        return max_izq;
    } else {
        return max_der;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-divide-maximo -->

:::{exercise}
:label: ej-divide-suma
Implementá una función en C para sumar todos los elementos de un arreglo de
enteros utilizando el paradigma de Divide y Vencerás. ¿Cuál es la profundidad
máxima de la pila de llamadas para un arreglo de tamaño $n$?

:::
<!-- {exercise} -->

:::{solution} ej-divide-suma
:class: dropdown
El algoritmo divide el arreglo en dos mitades hasta llegar a elementos
individuales:

```{code-block} c
:linenos:
#include <stddef.h>

long int sumar_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    if (ini == fin) {
        return arr[ini];
    }
    
    size_t mid = ini + (fin - ini) / 2;
    return sumar_divide_y_venceras(arr, ini, mid) + 
           sumar_divide_y_venceras(arr, mid + 1, fin);
}

```
<!-- {code-block} c -->

La profundidad máxima del *call stack* es $O(\log n)$ debido a la división
binaria del espacio.

:::
<!-- {solution} ej-divide-suma -->

:::{exercise}
:label: ej-divide-conteo-pares
Diseñá una función en C que determine la cantidad de números pares en un arreglo
de enteros utilizando el paradigma de Divide y Vencerás.

:::
<!-- {exercise} -->

:::{solution} ej-divide-conteo-pares
:class: dropdown
La función evalúa los elementos individuales en las hojas de la recursión y
acumula las cantidades en el paso de combinación:

```{code-block} c
:linenos:
#include <stddef.h>

size_t contar_pares_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    if (ini == fin) {
        return (arr[ini] % 2 == 0) ? 1 : 0;
    }
    
    size_t mid = ini + (fin - ini) / 2;
    size_t pares_izq = contar_pares_divide_y_venceras(arr, ini, mid);
    size_t pares_der = contar_pares_divide_y_venceras(arr, mid + 1, fin);
    return pares_izq + pares_der;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-divide-conteo-pares -->

## Glosario

- **Recursividad**: Técnica donde una función se invoca a sí misma para resolver
  subproblemas más pequeños.
- **Caso Base**: Condición que detiene la recursión.
- **Caso Recursivo**: Paso donde el problema se reduce y la función se vuelve a
  invocar.

## Síntesis y Resumen

En este apunte se han presentado los conceptos fundamentales del tema.

## Referencias y Lecturas Complementarias

No se especifican lecturas complementarias para este tema.
