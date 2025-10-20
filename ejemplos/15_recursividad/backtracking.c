// Backtracking: Generación de combinaciones

#include <stdio.h>
#include <stdbool.h>

// Imprime un arreglo
void imprimir_arreglo(int arr[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

// Genera todas las combinaciones de n elementos tomados de k en k
void combinaciones(int arr[], int n, int k, int inicio, int actual[], int pos) {
    // Caso base: ya tenemos k elementos
    if (pos == k) {
        imprimir_arreglo(actual, k);
        return;
    }
    
    // Probar cada elemento restante
    for (int i = inicio; i < n; i++) {
        actual[pos] = arr[i];
        combinaciones(arr, n, k, i + 1, actual, pos + 1);
    }
}

// Genera todas las permutaciones de un arreglo
void permutar(int arr[], int n, int inicio) {
    if (inicio == n - 1) {
        imprimir_arreglo(arr, n);
        return;
    }
    
    for (int i = inicio; i < n; i++) {
        // Intercambiar
        int temp = arr[inicio];
        arr[inicio] = arr[i];
        arr[i] = temp;
        
        // Recursión
        permutar(arr, n, inicio + 1);
        
        // Deshacer el intercambio (backtrack)
        temp = arr[inicio];
        arr[inicio] = arr[i];
        arr[i] = temp;
    }
}

// Resuelve el problema de las N reinas
bool es_seguro(int tablero[], int fila, int col) {
    for (int i = 0; i < fila; i++) {
        // Misma columna o diagonal
        if (tablero[i] == col || 
            tablero[i] - i == col - fila ||
            tablero[i] + i == col + fila) {
            return false;
        }
    }
    return true;
}

void n_reinas(int tablero[], int n, int fila, int *soluciones) {
    if (fila == n) {
        (*soluciones)++;
        printf("Solución %d: ", *soluciones);
        imprimir_arreglo(tablero, n);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (es_seguro(tablero, fila, col)) {
            tablero[fila] = col;
            n_reinas(tablero, n, fila + 1, soluciones);
        }
    }
}

int main(void) {
    // Combinaciones
    printf("Combinaciones de 4 elementos tomados de 2 en 2:\n");
    int numeros[] = {1, 2, 3, 4};
    int n = 4;
    int k = 2;
    int actual[2];
    combinaciones(numeros, n, k, 0, actual, 0);
    
    // Permutaciones
    printf("\nPermutaciones de {1, 2, 3}:\n");
    int perm[] = {1, 2, 3};
    permutar(perm, 3, 0);
    
    // N-Reinas (4x4)
    printf("\nProblema de las 4 reinas:\n");
    int tablero[4];
    int soluciones = 0;
    n_reinas(tablero, 4, 0, &soluciones);
    printf("Total de soluciones: %d\n", soluciones);
    
    return 0;
}
