---
title: "Paradigma de Divide y Conquista en C"
description: "Una guía sobre la estrategia algorítmica de divide y conquista, con implementaciones en C de Merge Sort y Búsqueda Binaria."
---

El paradigma de "Divide y Conquista" (Divide and Conquer) es una potente estrategia para el diseño de algoritmos que consiste en resolver un problema complejo descomponiéndolo en subproblemas más pequeños y manejables. El proceso se puede resumir en tres fases principales:

1.  **Dividir:** Se descompone el problema principal en un número de subproblemas que son instancias más pequeñas del mismo problema.
2.  **Conquistar:** Se resuelven los subproblemas de forma recursiva. Si un subproblema es lo suficientemente pequeño (caso base), se resuelve de manera directa.
3.  **Combinar:** Se combinan las soluciones de los subproblemas para construir la solución del problema original.

Este flujo de trabajo se puede visualizar de la siguiente manera:

```{mermaid}
graph TD
    A[Problema Original de tamaño N] --> B{1. Dividir};
    B --> C[Subproblema 1 (N/2)];
    B --> D[Subproblema 2 (N/2)];
    C --> E{2. Conquistar (Recursión)};
    D --> F{2. Conquistar (Recursión)};
    E --> G[Solución 1];
    F --> H[Solución 2];
    G --> I{3. Combinar};
    H --> I;
    I --> J[Solución Final];
```

## Ejemplo 1: Ordenamiento por Fusión (Merge Sort)

Merge Sort es el ejemplo canónico del paradigma de divide y conquista. Su objetivo es ordenar un arreglo de elementos.

* **Dividir:** Se divide el arreglo de `n` elementos en dos sub-arreglos de `n/2` elementos cada uno.
* **Conquistar:** Se ordena cada sub-arreglo de forma recursiva utilizando Merge Sort. El caso base es un arreglo con un solo elemento, que ya se considera ordenado.
* **Combinar:** Se fusionan (*merge*) los dos sub-arreglos ya ordenados para producir la solución final: un único arreglo ordenado.

### Implementación en C

```{code} c
:caption: Implementación del algoritmo Merge Sort en C
:label: merge-sort-c

#include <stdio.h>
#include <stdlib.h>

// Función para combinar dos sub-arreglos de arr[]
// El primer sub-arreglo es arr[l..m]
// El segundo sub-arreglo es arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Fusionar los arreglos temporales de nuevo en arr[l..r]
    i = 0; // Índice inicial del primer sub-arreglo
    j = 0; // Índice inicial del segundo sub-arreglo
    k = l; // Índice inicial del sub-arreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// l es para el índice izquierdo y r es para el índice derecho del
// sub-arreglo de arr que será ordenado
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encuentra el punto medio para evitar desbordamiento
        int m = l + (r - l) / 2;

        // Ordena la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusiona las mitades ordenadas
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArreglo ordenado: \n");
    printArray(arr, arr_size);
    return 0;
}
```

:::{note} Complejidad
La relación de recurrencia para Merge Sort es $T(n) = 2T(n/2) + O(n)$. Esto se resuelve a una complejidad temporal de $O(n \log n)$, que es muy eficiente.
:::

## Ejemplo 2: Búsqueda Binaria

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en un **arreglo ordenado**. También se ajusta al modelo de divide y conquista.

* **Dividir:** Se compara el elemento buscado con el elemento central del arreglo. Esto divide el problema, reduciendo el espacio de búsqueda a la mitad.
* **Conquistar:** Si el elemento central es el buscado, la búsqueda termina. Si no, se realiza una llamada recursiva a la mitad izquierda o a la mitad derecha del arreglo, dependiendo de si el elemento buscado es menor o mayor que el central. El caso base ocurre cuando el sub-arreglo no tiene elementos.
* **Combinar:** En este caso, la fase de combinación es trivial. La solución al subproblema (encontrar o no el elemento) es directamente la solución al problema original.

### Implementación en C (Recursiva)

```{code} c
:caption: Implementación recursiva de la Búsqueda Binaria en C
:label: binary-search-c

#include <stdio.h>

// Una función de búsqueda binaria recursiva.
// Retorna la ubicación de x en arr[l..r] si está presente,
// de lo contrario retorna -1
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // Si el elemento está presente en el medio
        if (arr[mid] == x)
            return mid;

        // Si el elemento es más pequeño que el del medio, entonces
        // solo puede estar presente en el sub-arreglo izquierdo
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // De lo contrario, el elemento solo puede estar presente
        // en el sub-arreglo derecho
        return binarySearch(arr, mid + 1, r, x);
    }

    // El elemento no está presente en el arreglo
    return -1;
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("El elemento no está presente en el arreglo\n");
    else
        printf("Elemento encontrado en el índice %d\n", result);
    return 0;
}
```

## Ventajas y Desventajas

```{list-table} Balance del Paradigma Divide y Conquista
:header-rows: 1

* - Ventajas
  - Desventajas
* - Permite resolver problemas complejos de manera eficiente (por ejemplo, con complejidad $O(n \log n)$).
  - La sobrecarga de la recursividad (llamadas a funciones y uso de la pila) puede hacer que sea más lento que un enfoque iterativo para problemas pequeños.
* - Los algoritmos son naturalmente paralelizables, ya que los subproblemas son independientes.
  - Puede ser más complejo de implementar correctamente que las soluciones iterativas.
* - El código puede ser más elegante y fácil de entender, ya que refleja la estructura matemática del problema.
  - La recursividad profunda puede llevar a un desbordamiento de la pila (*stack overflow*) si no se maneja con cuidado.
```