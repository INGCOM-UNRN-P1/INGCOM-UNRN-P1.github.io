#include <stdio.h>
#include <stdlib.h>

// --- Prototipos de funciones ---
void llenar_matriz(int filas, int columnas, int matriz[][columnas]);
void imprimir_matriz(int filas, int columnas, int matriz[][columnas]);

int main() {
    // Definimos las dimensiones de la matriz
    int filas = 5;
    int columnas = 10;

    printf("Creando una matriz dinámica de %d filas y %d columnas.\n\n", filas, columnas);

    /*
     * Asignación de memoria para la matriz.
     * 1. `sizeof *m`: Calcula el tamaño de lo que `m` apunta. Como `m` es un
     * puntero a un "array de `columnas` enteros", `*m` es ese array.
     * Por lo tanto, `sizeof *m` es equivalente a `sizeof(int[columnas])` o
     * `columnas * sizeof(int)`, que es el tamaño de una fila completa.
     *
     * 2. `sizeof *m * filas`: Multiplica el tamaño de una fila por el número
     * de filas para obtener el tamaño total en bytes para toda la matriz.
     *
     * 3. `malloc(...)`: Solicita un bloque contiguo de memoria de ese tamaño total.
     *
     * 4. `(int (*)[columnas])`: Este es el cast (conversión de tipo). Le dice al
     * compilador que trate el puntero genérico `void*` que devuelve `malloc`
     * como un "puntero a un array de `columnas` enteros". Esto es crucial
     * para que el compilador sepa cómo calcular los desplazamientos de memoria
     * al acceder a elementos como `m[i][j]`.
     */
    int (*m)[columnas] = (int (*)[columnas]) malloc(sizeof(int)*columnas * filas);

    // Verificación de que la memoria fue asignada correctamente
    if (m == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la matriz.\n");
        return 1; // Salir con código de error
    }

    // Usamos la matriz como si fuera una matriz estática normal
    llenar_matriz(filas, columnas, m);
    imprimir_matriz(filas, columnas, m);

    // Liberamos la memoria asignada con una sola llamada a free()
    // porque la memoria se asignó en un único bloque contiguo.
    free(m);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

/**
 * @brief Rellena la matriz con valores de ejemplo.
 * @param filas El número de filas de la matriz.
 * @param columnas El número de columnas de la matriz.
 * @param matriz La matriz a llenar. Nótese que la sintaxis es la misma que
 * para una matriz estática, gracias al tipo de puntero correcto.
 */
void llenar_matriz(int filas, int columnas, int matriz[][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * 100 + j;
        }
    }
}

/**
 * @brief Imprime el contenido de la matriz en la consola.
 * @param filas El número de filas de la matriz.
 * @param columnas El número de columnas de la matriz.
 * @param matriz La matriz a imprimir.
 */
void imprimir_matriz(int filas, int columnas, int matriz[][columnas]) {
    printf("Contenido de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // %-5d alinea los números a la izquierda con un ancho de 5 caracteres
            printf("%-5d", matriz[i][j]);
        }
        printf("\n"); // Nueva línea al final de cada fila
    }
}
