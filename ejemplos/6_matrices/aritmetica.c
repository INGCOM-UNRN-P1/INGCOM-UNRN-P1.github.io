#include <stdio.h>

#define FILAS 3
#define COLUMNAS 4

int main() {
    // Declaramos e inicializamos una matriz de 3x4
    int matriz[FILAS][COLUMNAS] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    printf("Accediendo a la matriz con aritmética de punteros:\n\n");

    // Recorremos la matriz usando bucles
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // La expresión clave: *(*(matriz + i) + j)
            // Es equivalente a matriz[i][j]
            
            int valor = *(*(matriz + i) + j);
            
            printf("matriz[%d][%d] = %d\n", i, j, valor);
        }
        printf("\n"); // Salto de línea para separar las filas
    }
    
    // Ejemplo de acceso a un solo elemento
    int elemento_2_1 = *(*(matriz + 2) + 1); // Equivale a matriz[2][1]
    printf("El elemento en la posición [2][1] es: %d\n", elemento_2_1);

    return 0;
}
