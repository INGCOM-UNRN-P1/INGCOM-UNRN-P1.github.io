// Ordenamiento burbuja - O(n²)
// Demuestra una complejidad temporal cuadrática

#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool hubo_cambio = false;
        
        // En cada pasada, el elemento más grande "burbujea" al final
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambio
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                hubo_cambio = true;
            }
        }
        
        // Optimización: si no hubo cambios, ya está ordenado
        if (!hubo_cambio) {
            break;
        }
    }
}

void imprimir_arreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main(void) {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Arreglo original: ");
    imprimir_arreglo(numeros, tamano);
    
    bubble_sort(numeros, tamano);
    
    printf("Arreglo ordenado: ");
    imprimir_arreglo(numeros, tamano);
    
    return 0;
}
