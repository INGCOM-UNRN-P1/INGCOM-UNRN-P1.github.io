// Búsqueda lineal - O(n)
// Demuestra una complejidad temporal lineal

#include <stdio.h>
#include <time.h>

// Búsqueda lineal simple
int busqueda_lineal(int arreglo[], int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (arreglo[i] == objetivo) {
            return i;  // Encontrado
        }
    }
    return -1;  // No encontrado
}

int main(void) {
    int numeros[] = {3, 7, 2, 9, 1, 5, 8, 4, 6};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Arreglo: ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    int objetivo = 5;
    clock_t inicio = clock();
    int posicion = busqueda_lineal(numeros, tamano, objetivo);
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
