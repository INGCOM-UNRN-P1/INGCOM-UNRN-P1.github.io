// Búsqueda binaria recursiva

#include <stdio.h>

// Búsqueda binaria recursiva
int busqueda_binaria_rec(int arr[], int izq, int der, int objetivo) {
    // Caso base: elemento no encontrado
    if (izq > der) {
        return -1;
    }
    
    int medio = izq + (der - izq) / 2;
    
    // Caso base: elemento encontrado
    if (arr[medio] == objetivo) {
        return medio;
    }
    
    // Recursión en la mitad izquierda
    if (arr[medio] > objetivo) {
        return busqueda_binaria_rec(arr, izq, medio - 1, objetivo);
    }
    
    // Recursión en la mitad derecha
    return busqueda_binaria_rec(arr, medio + 1, der, objetivo);
}

// Wrapper para facilitar el uso
int buscar(int arr[], int n, int objetivo) {
    return busqueda_binaria_rec(arr, 0, n - 1, objetivo);
}

// MergeSort recursivo
void merge(int arr[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];
    
    int i = 0, j = 0, k = izq;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        
        merge_sort(arr, izq, medio);
        merge_sort(arr, medio + 1, der);
        merge(arr, izq, medio, der);
    }
}

void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Búsqueda binaria
    int numeros[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Arreglo: ");
    imprimir_arreglo(numeros, n);
    
    int objetivo = 13;
    int pos = buscar(numeros, n, objetivo);
    if (pos != -1) {
        printf("Elemento %d encontrado en posición %d\n\n", objetivo, pos);
    }
    
    // MergeSort
    int desordenado[] = {38, 27, 43, 3, 9, 82, 10};
    int m = sizeof(desordenado) / sizeof(desordenado[0]);
    
    printf("Antes de ordenar: ");
    imprimir_arreglo(desordenado, m);
    
    merge_sort(desordenado, 0, m - 1);
    
    printf("Después de MergeSort: ");
    imprimir_arreglo(desordenado, m);
    
    return 0;
}
