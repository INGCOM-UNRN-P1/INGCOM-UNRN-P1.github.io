#include <stdio.h>
#include <stdlib.h>

// --- Prototipos de funciones ---
void llenar_matriz(int filas, int columnas, int *matriz);
void imprimir_matriz(int filas, int columnas, int *matriz);

int main() {
    // Definimos las dimensiones de la matriz
    int filas = 5;
    int columnas = 10;

    printf("Creando una matriz simulada de %d filas y %d columnas con un puntero simple.\n\n", filas, columnas);

    /*
     * Asignación de memoria para la matriz.
     * 1. Se declara un puntero simple a entero: `int *m`.
     * 2. Se calcula el número total de elementos necesarios: `filas * columnas`.
     * 3. Se multiplica el total de elementos por el tamaño de un entero
     * para obtener el tamaño total en bytes.
     * 4. `malloc` reserva un único bloque contiguo de memoria de ese tamaño.
     * El cast a `(int *)` es opcional en C pero es una buena práctica.
     */
    int *m = (int *) malloc(filas * columnas * sizeof(int));

    // Verificación de que la memoria fue asignada correctamente
    if (m == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la matriz.\n");
        return 1; // Salir con código de error
    }

    // Pasamos el puntero y las dimensiones a las funciones
    llenar_matriz(filas, columnas, m);
    imprimir_matriz(filas, columnas, m);

    // Liberamos la memoria asignada con una sola llamada a free()
    // porque la memoria se asignó en un único bloque contiguo.
    free(m);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

/**
 * @brief Rellena la matriz con valores de ejemplo usando aritmética de punteros.
 * @param filas El número de filas de la matriz.
 * @param columnas El número de columnas de la matriz.
 * @param matriz Un puntero al primer elemento del bloque de memoria de la matriz.
 */
void llenar_matriz(int filas, int columnas, int *matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            /*
             * Esta es la fórmula clave para simular un acceso 2D en un array 1D.
             * (i * columnas) calcula el desplazamiento para llegar al inicio de la fila `i`.
             * `+ j` calcula el desplazamiento adicional para llegar a la columna `j`
             * dentro de esa fila.
             */
            matriz[(i * columnas) + j] = i * 100 + j;
        }
    }
}

/**
 * @brief Imprime el contenido de la matriz en la consola.
 * @param filas El número de filas de la matriz.
 * @param columnas El número de columnas de la matriz.
 * @param matriz Un puntero al primer elemento del bloque de memoria de la matriz.
 */
void imprimir_matriz(int filas, int columnas, int *matriz) {
    printf("Contenido de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Se utiliza la misma fórmula para acceder e imprimir cada elemento.
            printf("%-5d", matriz[(i * columnas) + j]);
        }
        printf("\n"); // Nueva línea al final de cada fila
    }
}

