---
title: "Ejercicios: Ordenamiento y Búsqueda"
short_title: "5. Ordenamiento y Búsqueda"
---

# Ejercicios de Ordenamiento y Búsqueda

## Acerca de

Estos ejercicios tienen como propósito comprender, implementar y analizar la
complejidad temporal y espacial de los algoritmos clásicos de búsqueda (lineal,
binaria) y ordenamiento (burbuja, selección, inserción, fusión, rápido) en C11.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-secuencias`
- {ref}`capitulo-complejidad`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Arreglos contiguos y paso de arreglos por referencia ({ref}`capitulo-arreglos`).
2. Aritmética de punteros e intercambio de variables por referencia (`swap`).
3. Notación asintótica Big-O ($O(1)$, $O(\log n)$, $O(n)$, $O(n^2)$, $O(n \log n)$).
4. Principios de recursividad para algoritmos divide y conquistar.

### Cuestiones de Estilo Aplicables
- **Modularidad y genericidad:** Implementá funciones auxiliares de intercambio
  (`static void intercambiar(int *a, int *b)`) reutilizables (ver reglas en
  {ref}`0x2008h`).
- **Invariantes de bucle:** Mantené explícitas las fronteras de segmentos
  ordenados y no ordenados.

---

## Algoritmos de Búsqueda

(ej_b4_c08_01)=
### Ejercicio 4.08.01 - Búsqueda Lineal ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c08_01_lineal

Implementá la búsqueda lineal o secuencial sobre un arreglo de enteros. Debe
retornar el índice de la primera coincidencia, o `-1` si no existe.

```c
long long busqueda_lineal(const int *arr, size_t n, int objetivo);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Objetivo | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| `[4, 2, 7, 1, 9]` | `5` | `7` | `2` |
| `[4, 2, 7, 1, 9]` | `5` | `4` | `0` |
| `[4, 2, 7, 1, 9]` | `5` | `99` | `-1` |
| `[]` | `0` | `10` | `-1` |

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
