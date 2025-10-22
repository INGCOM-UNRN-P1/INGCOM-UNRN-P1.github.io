#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para generar números aleatorios

// --- Prototipos de funciones ---
void llenar_matriz_jagged(int filas, int **matriz, const int *tamanos_columnas);
void imprimir_matriz_jagged(int filas, int **matriz, const int *tamanos_columnas);

int main() {
    int filas = 5;
    int columnas = 5;

    // Estos serán los tamaños de las columnas para cada fila.
    // Fila 0 -> 3 columnas, Fila 1 -> 7 columnas, etc.
    int tamanos_columnas[5] = {3, 7, 4, 9, 5};

    printf("Creando una matriz jagged (irregular) de %d filas.\n", filas);
    for (int i = 0; i < filas; i++) {
        printf(" -> Fila %d tendrá %d columnas.\n", i, tamanos_columnas[i]);
    }
    printf("\n");

    /*
     * PASO 1: Asignar memoria para el array de punteros (las filas).
     * Se crea un array que contendrá punteros a cada una de las filas.
     * `m` es un puntero a un puntero de entero (int **).
     */
    int **m = (int **) malloc(filas * sizeof(int *));

    if (m == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para las filas.\n");
        return 1;
    }

    /*
     * PASO 2: Asignar memoria para cada fila individualmente.
     * Se itera sobre el array de punteros y se asigna a cada uno un bloque
     * de memoria de diferente tamaño, según lo definido en `tamanos_columnas`.
     */
    for (int i = 0; i < filas; i++) {
        m[i] = (int *) malloc(columnas * sizeof(int));
        if (m[i] == NULL) {
            fprintf(stderr, "Error: No se pudo asignar memoria para la fila %d.\n", i);
            // Si falla la asignación para una fila, debemos liberar toda la memoria
            // que ya habíamos asignado antes de salir para evitar fugas de memoria.
            for (int k = 0; k < i; k++) {
                free(m[k]);
            }
            free(m);
            return 1;
        }
    }

    // Usamos la matriz jagged
    llenar_matriz_jagged(filas, m, tamanos_columnas);
    imprimir_matriz_jagged(filas, m, tamanos_columnas);

    /*
     * PASO 3: Liberar la memoria en orden inverso a la asignación.
     * Primero, se libera la memoria de cada fila individual.
     */
    printf("\nLiberando memoria...\n");
    for (int i = 0; i < filas; i++) {
        free(m[i]);
    }

    /*
     * PASO 4: Liberar la memoria del array de punteros.
     */
    free(m);
    printf("Memoria liberada correctamente.\n");


    return 0;
}

/**
 * @brief Rellena la matriz jagged con valores aleatorios.
 * @param filas El número de filas de la matriz.
 * @param matriz El puntero al array de punteros de fila.
 * @param tamanos_columnas Un array que contiene el número de columnas para cada fila.
 */
void llenar_matriz_jagged(int filas, int **matriz, const int *tamanos_columnas) {
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    for (int i = 0; i < filas; i++) {
        // El bucle interno itera solo hasta el tamaño de la columna de la fila actual.
        for (int j = 0; j < tamanos_columnas[i]; j++) {
            matriz[i][j] = rand() % 100; // Valor aleatorio entre 0 y 99
        }
    }
}

/**
 * @brief Imprime el contenido de la matriz jagged en la consola.
 * @param filas El número de filas de la matriz.
 * @param matriz El puntero al array de punteros de fila.
 * @param tamanos_columnas Un array que contiene el número de columnas para cada fila.
 */
void imprimir_matriz_jagged(int filas, int **matriz, const int *tamanos_columnas) {
    printf("Contenido de la matriz jagged:\n");
    for (int i = 0; i < filas; i++) {
        printf("Fila %d: ", i);
        for (int j = 0; j < tamanos_columnas[i]; j++) {
            printf("%-4d", matriz[i][j]);
        }
        printf("\n");
    }
}
