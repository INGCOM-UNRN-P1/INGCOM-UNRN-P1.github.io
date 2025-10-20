// Búsqueda binaria - O(log n)
// Demuestra una complejidad temporal logarítmica

#include <stdio.h>
#include <time.h>

// Búsqueda binaria (requiere arreglo ordenado)
int busqueda_binaria(int arreglo[], int n, int objetivo) {
    int izq = 0;
    int der = n - 1;
    
    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        
        if (arreglo[medio] == objetivo) {
            return medio;
        }
        
        if (arreglo[medio] < objetivo) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    
    return -1;  // No encontrado
}

int main(void) {
    // Arreglo ordenado (requisito para búsqueda binaria)
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Arreglo ordenado: ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    int objetivo = 5;
    clock_t inicio = clock();
    int posicion = busqueda_binaria(numeros, tamano, objetivo);
    clock_t fin = clock();
    
    if (posicion != -1) {
        printf("Elemento %d encontrado en la posición %d\n", objetivo, posicion);
    } else {
        printf("Elemento %d no encontrado\n", objetivo);
    }
    
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);
    
    return 0;
}
