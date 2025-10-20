// Algoritmos de ordenamiento simples

#include <stdio.h>

void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ordenamiento por selección
void ordenar_seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        
        // Buscar el mínimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx_min]) {
                idx_min = j;
            }
        }
        
        // Intercambiar
        if (idx_min != i) {
            int temp = arr[i];
            arr[i] = arr[idx_min];
            arr[idx_min] = temp;
        }
    }
}

// Ordenamiento por inserción
void ordenar_insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        // Mover elementos mayores que clave una posición adelante
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = clave;
    }
}

int main(void) {
    int numeros1[] = {64, 25, 12, 22, 11};
    int numeros2[] = {64, 25, 12, 22, 11};
    int n = sizeof(numeros1) / sizeof(numeros1[0]);
    
    printf("Arreglo original: ");
    imprimir_arreglo(numeros1, n);
    
    // Ordenamiento por selección
    ordenar_seleccion(numeros1, n);
    printf("Por selección:    ");
    imprimir_arreglo(numeros1, n);
    
    // Ordenamiento por inserción
    ordenar_insercion(numeros2, n);
    printf("Por inserción:    ");
    imprimir_arreglo(numeros2, n);
    
    return 0;
}
