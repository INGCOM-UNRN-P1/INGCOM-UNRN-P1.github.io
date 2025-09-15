#include <stdio.h>

int main() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Obtenemos el tamaño de la matriz en bytes.
    size_t tamano_matriz = sizeof(matriz);

    // Obtenemos el tamaño de un solo elemento (un entero).
    size_t tamano_elemento = sizeof(matriz[0][0]);

    // Obtenemos el tamaño de una fila (un array de 4 enteros).
    size_t tamano_fila = sizeof(matriz[0]);

    // Calculamos el número total de elementos.
    size_t num_elementos = tamano_matriz / tamano_elemento;

    // Calculamos el número de filas.
    size_t num_filas = tamano_matriz / tamano_fila;

    // Calculamos el número de columnas.
    size_t num_columnas = tamano_fila / tamano_elemento;

    printf("Dimensiones de la matriz:\n");
    printf("Número de filas: %zu\n", num_filas);
    printf("Número de columnas: %zu\n", num_columnas);
    printf("Número total de elementos: %zu\n", num_elementos);
    
    return 0;
}
