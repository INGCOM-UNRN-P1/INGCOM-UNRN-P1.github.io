---
title: "Ejercicios: Ordenamiento y Búsqueda"
short_title: "5. Ordenamiento y Búsqueda"
---

# Ejercicios de Ordenamiento y Búsqueda

## Prerrequisitos y Entorno de Ejecución Requerido

Para compilar y verificar las soluciones de este módulo bajo el estándar C11 estricto de cátedra, se requiere:
- **Compilador C11:** GCC 9+ o Clang 11+ configurado con flags `-Wall -Wextra -Werror -pedantic -std=c11`.
- **Entorno POSIX:** Linux o WSL con utilidades estándar, soporte de arreglos contiguos y memoria dinámica.
- **Herramientas de Verificación:** Valgrind (memcheck) y AddressSanitizer (`-fsanitize=address,undefined`) para auditar límites de arreglos (*buffer bounds*) y memoria dinámica en algoritmos de partición y fusión.
- **Conocimientos Previos:** Arreglos contiguos, punteros, paso por referencia, notación asintótica Big-O ($O(1)$, $O(\log n)$, $O(n)$, $O(n \log n)$, $O(n^2)$) y recursión.

## Objetivos Pedagógicos y Competencias (Taxonomía de Bloom)

- **Nivel 2 (Comprensión):** Analizar el comportamiento de particiones, invariantes de bucle y comparación de costos asintóticos en el mejor, peor y caso promedio.
- **Nivel 3 (Aplicación):** Implementar algoritmos de búsqueda lineal y binaria, así como ordenamientos cuadráticos (burbuja, selección, inserción) y logarítmicos (mergesort, quicksort) en C11.
- **Nivel 4 (Análisis):** Evaluar estabilidad algorítmica, consumo de memoria auxiliar ($O(1)$ vs $O(n)$) y condiciones de parada recursivas.
- **Andamiaje Progresivo:** Ejercicios andamiados con contratos formales (precondiciones/postcondiciones), tablas de vectores de prueba y suites ejecutables con `assert()`.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-secuencias`
- {ref}`capitulo-complejidad`

### Cuestiones de Estilo Aplicables
- **Modularidad y genericidad:** Implementá funciones auxiliares de intercambio (`static void intercambiar(int *a, int *b)`) reutilizables (ver reglas en {ref}`0x2008h`).
- **Invariantes de bucle:** Mantené explícitas las fronteras de segmentos ordenados y no ordenados.

---

## Algoritmos de Búsqueda

(ej_b4_c08_01)=
### Ejercicio 4.08.01 - Búsqueda Lineal ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_01_lineal
:enumerator: ord-busq-1

Implementá la búsqueda lineal o secuencial sobre un arreglo de enteros. Debe retornar el índice de la primera coincidencia encontrada, o `-1` si el elemento no existe en el arreglo o el puntero es nulo.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Recorrido unidimensional de arreglos contiguos, punteros de sólo lectura (`const int *`), centinelas y complejidad temporal en el peor caso $O(n)$.  
**Techo conceptual:** Prohibido el uso de variables globales.

#### Contrato de la Función
- **Firma:** `long long busqueda_lineal(const int *arr, size_t n, int objetivo);`
- **Precondiciones:** `arr` apunta a un bloque contiguo de al menos `n` elementos si `n > 0`.
- **Postcondiciones:** Retorna el índice $0 \le i < n$ de la primera aparición de `objetivo`; retorna `-1` si no existe o si `arr == NULL` con `n > 0`.

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Arreglo | `n` | Objetivo | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Elemento Central** | `[4, 2, 7, 1, 9]` | `5` | `7` | `2` | Coincidencia intermedia exitosa |
| **Primer Elemento** | `[4, 2, 7, 1, 9]` | `5` | `4` | `0` | Mejor caso $O(1)$ en la cabeza |
| **Inexistente** | `[4, 2, 7, 1, 9]` | `5` | `99` | `-1` | Peor caso $O(n)$, escaneo total |
| **Arreglo Vacío** | `[]` | `0` | `10` | `-1` | Caso borde cardinalidad cero |

:::
<!-- {exercise} -->

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

long long busqueda_lineal(const int *arr, size_t n, int objetivo) {
    if (arr == NULL) {
        return -1;
    }
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] == objetivo) {
            return (long long)i;
        }
    }
    return -1;
}

int main(void) {
    int datos[] = {4, 2, 7, 1, 9};
    assert(busqueda_lineal(datos, 5, 7) == 2);
    assert(busqueda_lineal(datos, 5, 4) == 0);
    assert(busqueda_lineal(datos, 5, 9) == 4);
    assert(busqueda_lineal(datos, 5, 99) == -1);
    assert(busqueda_lineal(datos, 0, 4) == -1);
    assert(busqueda_lineal(NULL, 5, 4) == -1);
    return 0;
}
```
::::
:::

(ej_b4_c08_02)=
### Ejercicio 4.08.02 - Búsqueda Binaria ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_02_binaria

Implementá el algoritmo de búsqueda binaria iterativa sobre un arreglo
previamente ordenado en orden ascendente. Complejidad temporal $O(\log n)$.

```c
long long busqueda_binaria(const int *arr, size_t n, int objetivo);
```

**Tabla de Vectores de Prueba:**

| Arreglo Ordenado | `n` | Objetivo | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| `[2, 5, 8, 12, 16, 23, 38]` | `7` | `16` | `4` |
| `[2, 5, 8, 12, 16, 23, 38]` | `7` | `2` | `0` |
| `[2, 5, 8, 12, 16, 23, 38]` | `7` | `38` | `6` |
| `[2, 5, 8, 12, 16, 23, 38]` | `7` | `15` | `-1` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

long long busqueda_binaria(const int *arr, size_t n, int objetivo) {
    if (arr == NULL || n == 0) {
        return -1;
    }
    size_t izq = 0;
    size_t der = n - 1;

    while (izq <= der) {
        size_t medio = izq + (der - izq) / 2;
        if (arr[medio] == objetivo) {
            return (long long)medio;
        }
        if (arr[medio] < objetivo) {
            izq = medio + 1;
        } else {
            if (medio == 0) {
                break;
            }
            der = medio - 1;
        }
    }
    return -1;
}

int main(void) {
    int ordenado[] = {2, 5, 8, 12, 16, 23, 38};
    assert(busqueda_binaria(ordenado, 7, 16) == 4);
    assert(busqueda_binaria(ordenado, 7, 2) == 0);
    assert(busqueda_binaria(ordenado, 7, 38) == 6);
    assert(busqueda_binaria(ordenado, 7, 15) == -1);
    assert(busqueda_binaria(ordenado, 7, 1) == -1);
    assert(busqueda_binaria(ordenado, 7, 99) == -1);
    assert(busqueda_binaria(ordenado, 0, 5) == -1);
    return 0;
}
```
::::
:::

---

## Algoritmos de Ordenamiento Cuadráticos ($O(n^2)$)

(ej_b4_c08_03)=
### Ejercicio 4.08.03 - Ordenamiento Burbuja Optimizado ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_03_burbuja

Implementá Bubble Sort in-place incorporando una bandera de corte temprano
para finalizar en $O(n)$ si el arreglo ya está ordenado.

```c
void ordenamiento_burbuja(int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo Inicial | `n` | Arreglo Final Ordenado |
| :--- | :--- | :--- |
| `[64, 34, 25, 12, 22, 11, 90]` | `7` | `[11, 12, 22, 25, 34, 64, 90]` |
| `[1, 2, 3, 4, 5]` | `5` | `[1, 2, 3, 4, 5]` |
| `[5, 4, 3, 2, 1]` | `5` | `[1, 2, 3, 4, 5]` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

static void intercambiar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordenamiento_burbuja(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }
    for (size_t i = 0; i < n - 1; ++i) {
        bool hubo_intercambio = false;
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                intercambiar(&arr[j], &arr[j + 1]);
                hubo_intercambio = true;
            }
        }
        if (!hubo_intercambio) {
            break;
        }
    }
}

int main(void) {
    int a1[] = {64, 34, 25, 12, 22, 11, 90};
    ordenamiento_burbuja(a1, 7);
    int esp1[] = {11, 12, 22, 25, 34, 64, 90};
    for (size_t i = 0; i < 7; ++i) assert(a1[i] == esp1[i]);

    int a2[] = {5, 4, 3, 2, 1};
    ordenamiento_burbuja(a2, 5);
    for (size_t i = 0; i < 5; ++i) assert(a2[i] == (int)(i + 1));

    int a3[] = {10};
    ordenamiento_burbuja(a3, 1);
    assert(a3[0] == 10);
    return 0;
}
```
::::
:::

(ej_b4_c08_04)=
### Ejercicio 4.08.04 - Ordenamiento por Selección ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_04_seleccion

Implementá Selection Sort seleccionando en cada pasada el valor mínimo de la
porción restante no ordenada e intercambiándolo a su posición final.

```c
void ordenamiento_seleccion(int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Entrada | `n` | Salida Ordenada |
| :--- | :--- | :--- |
| `[29, 10, 14, 37, 13]` | `5` | `[10, 13, 14, 29, 37]` |
| `[5, 1]` | `2` | `[1, 5]` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

static void intercambiar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordenamiento_seleccion(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }
    for (size_t i = 0; i < n - 1; ++i) {
        size_t idx_min = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[idx_min]) {
                idx_min = j;
            }
        }
        if (idx_min != i) {
            intercambiar(&arr[i], &arr[idx_min]);
        }
    }
}

int main(void) {
    int datos[] = {29, 10, 14, 37, 13};
    ordenamiento_seleccion(datos, 5);
    int esp[] = {10, 13, 14, 29, 37};
    for (size_t i = 0; i < 5; ++i) {
        assert(datos[i] == esp[i]);
    }
    return 0;
}
```
::::
:::

(ej_b4_c08_05)=
### Ejercicio 4.08.05 - Ordenamiento por Inserción ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_05_insercion

Implementá Insertion Sort desplazando elementos mayores hacia la derecha para
abrir espacio al elemento actual.

```c
void ordenamiento_insercion(int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Entrada | `n` | Salida Ordenada |
| :--- | :--- | :--- |
| `[12, 11, 13, 5, 6]` | `5` | `[5, 6, 11, 12, 13]` |
| `[3, -1, 0]` | `3` | `[-1, 0, 3]` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void ordenamiento_insercion(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }
    for (size_t i = 1; i < n; ++i) {
        int clave = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > clave) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = clave;
    }
}

int main(void) {
    int a[] = {12, 11, 13, 5, 6};
    ordenamiento_insercion(a, 5);
    int esp[] = {5, 6, 11, 12, 13};
    for (size_t i = 0; i < 5; ++i) {
        assert(a[i] == esp[i]);
    }

    int neg[] = {3, -1, 0};
    ordenamiento_insercion(neg, 3);
    assert(neg[0] == -1 && neg[1] == 0 && neg[2] == 3);
    return 0;
}
```
::::
:::

---

## Algoritmos de Ordenamiento Avanzados ($O(n \log n)$)

(ej_b4_c08_06)=
### Ejercicio 4.08.06 - Ordenamiento por Fusión (Merge Sort) ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_06_mergesort

Implementá Merge Sort dividiendo recursivamente el arreglo y fusionando ambas
mitades ordenadas mediante un búfer auxiliar dinámico.

```c
void ordenamiento_mergesort(int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Arreglo Ordenado |
| :--- | :--- | :--- |
| `[38, 27, 43, 3, 9, 82, 10]` | `7` | `[3, 9, 10, 27, 38, 43, 82]` |
| `[2, 1]` | `2` | `[1, 2]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

static void fusionar(int *arr, size_t izq, size_t medio, size_t der, int *aux) {
    size_t i = izq;
    size_t j = medio + 1;
    size_t k = izq;

    while (i <= medio && j <= der) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }
    while (i <= medio) {
        aux[k++] = arr[i++];
    }
    while (j <= der) {
        aux[k++] = arr[j++];
    }
    for (size_t p = izq; p <= der; ++p) {
        arr[p] = aux[p];
    }
}

static void mergesort_recursivo(int *arr, size_t izq, size_t der, int *aux) {
    if (izq >= der) {
        return;
    }
    size_t medio = izq + (der - izq) / 2;
    mergesort_recursivo(arr, izq, medio, aux);
    mergesort_recursivo(arr, medio + 1, der, aux);
    fusionar(arr, izq, medio, der, aux);
}

void ordenamiento_mergesort(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }
    int *aux = (int *)malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    mergesort_recursivo(arr, 0, n - 1, aux);
    free(aux);
}

int main(void) {
    int datos[] = {38, 27, 43, 3, 9, 82, 10};
    ordenamiento_mergesort(datos, 7);
    int esp[] = {3, 9, 10, 27, 38, 43, 82};
    for (size_t i = 0; i < 7; ++i) {
        assert(datos[i] == esp[i]);
    }
    return 0;
}
```
::::
:::

(ej_b4_c08_07)=
### Ejercicio 4.08.07 - Ordenamiento Rápido (Quick Sort) ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_07_quicksort

Implementá Quick Sort in-place utilizando el esquema de partición de Lomuto
(pivote en el extremo final).

```c
void ordenamiento_quicksort(int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo Desordenado | `n` | Arreglo Ordenado |
| :--- | :--- | :--- |
| `[10, 7, 8, 9, 1, 5]` | `6` | `[1, 5, 7, 8, 9, 10]` |
| `[5, 5, 5, 5]` | `4` | `[5, 5, 5, 5]` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

static void intercambiar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static size_t particionar(int *arr, size_t bajo, size_t alto) {
    int pivote = arr[alto];
    size_t i = bajo;
    for (size_t j = bajo; j < alto; ++j) {
        if (arr[j] <= pivote) {
            intercambiar(&arr[i], &arr[j]);
            i++;
        }
    }
    intercambiar(&arr[i], &arr[alto]);
    return i;
}

static void quicksort_recursivo(int *arr, size_t bajo, size_t alto) {
    if (bajo < alto) {
        size_t pi = particionar(arr, bajo, alto);
        if (pi > 0) {
            quicksort_recursivo(arr, bajo, pi - 1);
        }
        quicksort_recursivo(arr, pi + 1, alto);
    }
}

void ordenamiento_quicksort(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }
    quicksort_recursivo(arr, 0, n - 1);
}

int main(void) {
    int a[] = {10, 7, 8, 9, 1, 5};
    ordenamiento_quicksort(a, 6);
    int esp[] = {1, 5, 7, 8, 9, 10};
    for (size_t i = 0; i < 6; ++i) {
        assert(a[i] == esp[i]);
    }

    int rep[] = {5, 5, 5, 5};
    ordenamiento_quicksort(rep, 4);
    for (size_t i = 0; i < 4; ++i) {
        assert(rep[i] == 5);
    }
    return 0;
}
```
::::
:::

---

(ej_b4_c08_08)=
### Ejercicio 4.08.08 - Esquema de Partición de Hoare vs Lomuto Instrumentado ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b4_c08_08_hoare
:enumerator: ordenamiento-8

En el algoritmo QuickSort, la rutina de particionado es el núcleo computacional crítico. Existen dos esquemas canónicos:
1. **Esquema de Lomuto:** Emplea el último elemento como pivote y un puntero secuencial. Es más sencillo conceptualmente, pero realiza hasta tres veces más operaciones de intercambio (*swaps*) y degrada fuertemente ante elementos repetidos.
2. **Esquema de Hoare:** Emplea dos punteros convergentes desde ambos extremos hacia el centro. Realiza un promedio significativamente menor de intercambios.

Implementá ambos esquemas instrumentando el conteo de intercambios:
- `size_t particion_lomuto_contada(int *arr, size_t bajo, size_t alto, size_t *swaps);`
- `size_t particion_hoare_contada(int *arr, size_t bajo, size_t alto, size_t *swaps);`

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Arreglo ($n=6$) | Swaps Lomuto | Swaps Hoare | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Ya Ordenado** | `{1, 2, 3, 4, 5, 6}` | $6$ | $0$ | Hoare detecta condición ordenada sin intercambios |
| **Elementos Idénticos** | `{5, 5, 5, 5, 5, 5}` | $6$ | $3$ | Lomuto degrada intercambiando todos; Hoare divide simétricamente |
| **Desordenado** | `{3, 5, 2, 6, 1, 4}` | $4$ | $2$ | Hoare converge con menor número de swaps promedio |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

size_t particion_lomuto_contada(int *arr, size_t bajo, size_t alto, size_t *swaps) {
    int pivote = arr[alto];
    size_t i = bajo;

    for (size_t j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            swap(&arr[i], &arr[j]);
            if (swaps != NULL) (*swaps)++;
            i++;
        }
    }
    swap(&arr[i], &arr[alto]);
    if (swaps != NULL) (*swaps)++;
    return i;
}

size_t particion_hoare_contada(int *arr, size_t bajo, size_t alto, size_t *swaps) {
    int pivote = arr[bajo];
    size_t i = bajo;
    size_t j = alto;

    while (1) {
        while (arr[i] < pivote) {
            i++;
        }
        while (arr[j] > pivote) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(&arr[i], &arr[j]);
        if (swaps != NULL) (*swaps)++;
        i++;
        if (j > 0) j--;
    }
}

int main(void) {
    // 1. Arreglo ya ordenado: Hoare 0 swaps vs Lomuto 6 swaps
    int ord_lomuto[6] = {1, 2, 3, 4, 5, 6};
    int ord_hoare[6] = {1, 2, 3, 4, 5, 6};
    size_t s_lomuto = 0;
    size_t s_hoare = 0;

    particion_lomuto_contada(ord_lomuto, 0, 5, &s_lomuto);
    particion_hoare_contada(ord_hoare, 0, 5, &s_hoare);
    assert(s_hoare == 0);
    assert(s_lomuto == 6);

    // 2. Arreglo desordenado: Hoare 2 swaps vs Lomuto 4 swaps
    int des_lomuto[6] = {3, 5, 2, 6, 1, 4};
    int des_hoare[6] = {3, 5, 2, 6, 1, 4};
    s_lomuto = 0;
    s_hoare = 0;

    particion_lomuto_contada(des_lomuto, 0, 5, &s_lomuto);
    particion_hoare_contada(des_hoare, 0, 5, &s_hoare);
    assert(s_hoare < s_lomuto);
    assert(s_hoare == 2);
    assert(s_lomuto == 4);

    // 3. Arreglo con elementos idénticos: Hoare 3 swaps vs Lomuto 6 swaps
    int rep_lomuto[6] = {5, 5, 5, 5, 5, 5};
    int rep_hoare[6] = {5, 5, 5, 5, 5, 5};
    s_lomuto = 0;
    s_hoare = 0;

    particion_lomuto_contada(rep_lomuto, 0, 5, &s_lomuto);
    particion_hoare_contada(rep_hoare, 0, 5, &s_hoare);
    assert(s_hoare < s_lomuto);
    assert(s_hoare == 3);
    assert(s_lomuto == 6);

    return 0;
}
```
::::
:::

---

(ej_b4_c08_09)=
### Ejercicio 4.08.09 - Búsqueda Exponencial en Arreglos Ordenados ⭐⭐⭐☆☆

:::{exercise}
:label: busqueda_exponencial
:enumerator: ordenamiento-9

La búsqueda exponencial (*Exponential Search*) es especialmente eficiente para buscar en arreglos ordenados cuando se desconoce el tamaño a priori o cuando el elemento buscado se encuentra cerca del inicio del arreglo.
El algoritmo consta de dos etapas:
1. Encontrar el rango de búsqueda mediante duplicación sucesiva de índices ($i = 1, 2, 4, 8, \dots$) hasta hallar $i \ge n$ o un elemento `arr[i] >= objetivo`.
2. Ejecutar una búsqueda binaria estándar dentro del subrango acotado $[\lfloor i/2 \rfloor, \min(i, n - 1)]$.

Implementá la función:
```c
int busqueda_exponencial(const int *arr, size_t n, int objetivo);
```
que retorne el índice donde reside `objetivo`, o `-1` si no existe en el arreglo.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Búsqueda binaria, crecimiento exponencial de ventanas, complejidad $O(\log i)$ donde $i$ es la posición del elemento.  
**Techo conceptual:** El arreglo de entrada debe estar estrictamente ordenado de menor a mayor.

#### Contrato de la Función
- **Firma:** `int busqueda_exponencial(const int *arr, size_t n, int objetivo);`
- **Precondiciones:** Arreglo ordenado ascendentemente. Si `n > 0`, `arr != NULL`.
- **Postcondiciones:** Retorna el índice exacto si el elemento está presente; de lo contrario `-1`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Arreglo Entrada | Objetivo | Índice Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal (Inicio)** | `{2, 5, 8, 12, 16, 23, 38, 56}`, $n=8$ | `2` | `0` | Primer elemento resuelto en $O(1)$ |
| **Normal (Intermedio)**| Mismo arreglo | `23` | `5` | Rango detectado entre $i=4$ e $i=8$ |
| **Normal (Final)** | Mismo arreglo | `56` | `7` | Búsqueda en el extremo derecho |
| **Error (No presente)**| Mismo arreglo | `15` | `-1` | Elemento ausente en ventana acotada |
| **Borde (Vacío)** | Arreglo vacío, $n=0$ | `42` | `-1` | Manejo seguro de arreglo sin elementos |

:::
<!-- {exercise} -->

::::{solution} busqueda_exponencial
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

static int busqueda_binaria_rango(const int *arr, size_t izq, size_t der, int objetivo)
{
    while (izq <= der)
    {
        size_t medio = izq + (der - izq) / 2;
        if (arr[medio] == objetivo)
        {
            return (int)medio;
        }
        if (arr[medio] < objetivo)
        {
            izq = medio + 1;
        }
        else
        {
            if (medio == 0)
            {
                break;
            }
            der = medio - 1;
        }
    }
    return -1;
}

int busqueda_exponencial(const int *arr, size_t n, int objetivo)
{
    if (arr == NULL || n == 0)
    {
        return -1;
    }

    if (arr[0] == objetivo)
    {
        return 0;
    }

    size_t i = 1;
    while (i < n && arr[i] <= objetivo)
    {
        i *= 2;
    }

    size_t izq = i / 2;
    size_t der = (i < n) ? i : n - 1;

    return busqueda_binaria_rango(arr, izq, der, objetivo);
}

int main(void)
{
    int arr[8] = {2, 5, 8, 12, 16, 23, 38, 56};

    // Caso inicio
    assert(busqueda_exponencial(arr, 8, 2) == 0);

    // Caso intermedio
    assert(busqueda_exponencial(arr, 8, 23) == 5);

    // Caso fin
    assert(busqueda_exponencial(arr, 8, 56) == 7);

    // Elemento no presente
    assert(busqueda_exponencial(arr, 8, 15) == -1);
    assert(busqueda_exponencial(arr, 8, 1) == -1);
    assert(busqueda_exponencial(arr, 8, 100) == -1);

    // Arreglo vacío
    assert(busqueda_exponencial(NULL, 0, 42) == -1);

    return 0;
}
```

::::
<!-- {solution} busqueda_exponencial -->

---

(ej_b4_c08_10)=
### Ejercicio 4.08.10 - Ordenamiento por Cuentas (Counting Sort) Acotado ⭐⭐⭐☆☆

:::{exercise}
:label: counting_sort_acotado
:enumerator: ordenamiento-10

Cuando los elementos a ordenar son números enteros pertenecientes a un rango cerrado $[min, max]$ de amplitud moderada $k = max - min + 1$, es posible superar la barrera teórica de comparación $\Omega(n \log n)$ mediante **Counting Sort**, logrando tiempo de ejecución lineal $O(n + k)$.

Implementá la función:
```c
bool counting_sort_acotado(int *arr, size_t n, int min_val, int max_val);
```

- **Precondiciones:** `arr != NULL` (si `n > 0`), `min_val <= max_val`.
- **Comportamiento:**
  1. Reserva un arreglo dinámico de conteo de tamaño $k = max\_val - min\_val + 1$. Si falla `malloc`, retorna `false`.
  2. Inicializa en cero y contabiliza la frecuencia de cada valor en `arr`.
  3. Reconstruye el arreglo `arr` secuencialmente en orden ascendente según las frecuencias acumuladas.
  4. Libera la memoria auxiliar de conteo y retorna `true`.
- **Manejo de errores:** Si algún elemento de `arr` se encuentra fuera del rango $[min\_val, max\_val]$, la función debe abortar la operación, liberar la memoria y retornar `false`.

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Arreglo Inicial | Rango $[min, max]$ | Retorno Esperado | Arreglo Ordenado |
| :--- | :--- | :--- | :--- | :--- |
| **Normal con Repetidos** | `{4, 2, 2, 8, 3, 3, 1}` | $[1, 8]$ | `true` | `{1, 2, 2, 3, 3, 4, 8}` |
| **Rango Negativo** | `{-3, 0, -1, -3, 2}` | $[-3, 2]$ | `true` | `{-3, -3, -1, 0, 2}` |
| **Fuera de Rango** | `{10, 20, 99}` | $[0, 50]$ | `false` | Inalterado |
| **Rango Inválido** | `{1, 2}` | $[10, 5]$ | `false` | Inalterado |

:::
<!-- {exercise} counting_sort_acotado -->

::::{solution} counting_sort_acotado
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool counting_sort_acotado(int *arr, size_t n, int min_val, int max_val) {
    if (min_val > max_val) {
        return false;
    }
    if (arr == NULL || n <= 1) {
        return true;
    }

    size_t k = (size_t)(max_val - min_val + 1);
    size_t *conteo = (size_t *)calloc(k, sizeof(size_t));
    if (conteo == NULL) {
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        if (arr[i] < min_val || arr[i] > max_val) {
            free(conteo);
            return false;
        }
        size_t idx = (size_t)(arr[i] - min_val);
        conteo[idx]++;
    }

    size_t pos = 0;
    for (size_t i = 0; i < k; i++) {
        while (conteo[i] > 0) {
            arr[pos++] = (int)i + min_val;
            conteo[i]--;
        }
    }

    free(conteo);
    return true;
}

int main(void) {
    int arr1[7] = {4, 2, 2, 8, 3, 3, 1};
    assert(counting_sort_acotado(arr1, 7, 1, 8) == true);
    assert(arr1[0] == 1 && arr1[1] == 2 && arr1[2] == 2 && arr1[3] == 3 && arr1[4] == 3 && arr1[5] == 4 && arr1[6] == 8);

    int arr2[5] = {-3, 0, -1, -3, 2};
    assert(counting_sort_acotado(arr2, 5, -3, 2) == true);
    assert(arr2[0] == -3 && arr2[1] == -3 && arr2[2] == -1 && arr2[3] == 0 && arr2[4] == 2);

    int arr3[3] = {10, 20, 99};
    assert(counting_sort_acotado(arr3, 3, 0, 50) == false);

    assert(counting_sort_acotado(arr1, 7, 10, 5) == false);
    assert(counting_sort_acotado(NULL, 0, 0, 10) == true);

    return 0;
}
```

::::
<!-- {solution} counting_sort_acotado -->

