// Búsqueda en arreglos

#include <stdio.h>
#include <stdbool.h>

// Búsqueda lineal
int buscar_lineal(int arr[], int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo) {
            return i;
        }
    }
    return -1;  // No encontrado
}

// Verifica si un arreglo está ordenado
bool esta_ordenado(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Cuenta ocurrencias de un valor
int contar_ocurrencias(int arr[], int n, int valor) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            contador++;
        }
    }
    return contador;
}

// Encuentra el índice del máximo
int indice_maximo(int arr[], int n) {
    int idx_max = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[idx_max]) {
            idx_max = i;
        }
    }
    return idx_max;
}

int main(void) {
    int numeros[] = {10, 25, 10, 42, 15, 30, 10};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n\n");
    
    // Búsqueda lineal
    int objetivo = 42;
    int pos = buscar_lineal(numeros, n, objetivo);
    if (pos != -1) {
        printf("%d encontrado en posición %d\n", objetivo, pos);
    }
    
    // Verificar si está ordenado
    printf("¿Está ordenado? %s\n", esta_ordenado(numeros, n) ? "Sí" : "No");
    
    // Contar ocurrencias
    int valor = 10;
    printf("Ocurrencias de %d: %d\n", valor, contar_ocurrencias(numeros, n, valor));
    
    // Encontrar máximo
    int idx_max = indice_maximo(numeros, n);
    printf("Valor máximo: %d (en posición %d)\n", numeros[idx_max], idx_max);
    
    return 0;
}
