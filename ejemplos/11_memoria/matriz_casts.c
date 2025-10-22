#include <stdio.h>

#define FILAS 3
#define COLUMNAS 4

int main() {
    // Una matriz 2D estática. En memoria, esto es un bloque contiguo
    // de 3x4 = 12 enteros.
    int a[FILAS][COLUMNAS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };

    printf("--- El Intento Incorrecto (y por qué) ---\n\n");

    // `p` es un puntero a un puntero a un entero.
    int **p;
    
    int *q = &a[0][0];
    
    // p = a; // <--- ¡AQUÍ ESTÁ EL ERROR!

    /*
     * ¿Por qué `p = a;` no funciona?
     *
     * 1. Incompatibilidad de Tipos:
     * - El tipo de `p` es `int **` (puntero a puntero a int).
     * - El identificador de la matriz `a`, en la mayoría de las expresiones, "decae"
     * en un puntero a su primer elemento. El primer elemento de `a` es `a[0]`,
     * que es un "array de 4 enteros" (su tipo es `int[4]`).
     * - Por lo tanto, el tipo de `a` cuando decae es `int (*)[4]` (un puntero
     * a un array de 4 enteros).
     *
     * El compilador ve que estás intentando asignar un `int (*)[4]` a un `int **`,
     * que son tipos de punteros fundamentalmente diferentes y no compatibles.
     * Por eso, la línea `p = a;` genera una advertencia (warning) como:
     * "initialization from incompatible pointer type"
     *
     * 2. Diferencia en el Layout de Memoria:
     * - `int a[3][4]` es un bloque contiguo de 12 enteros.
     * - `int **p` está diseñado para apuntar a un array de punteros (`int *`),
     * y cada uno de esos punteros apuntaría a un entero (o al inicio de
     * otra fila de enteros). Este es el layout de memoria de un "jagged array",
     * no de una matriz 2D estándar.
     */
    printf("El tipo de 'a' (cuando decae) es 'puntero a array de 4 enteros'.\n");
    printf("El tipo de 'p' es 'puntero a puntero a entero'.\n");
    printf("Estos tipos no son compatibles, por lo que 'p = a;' falla.\n\n");


    printf("--- Forma Correcta 1: El tipo de puntero correcto ---\n\n");

    // `ptr` es un puntero a un array de 4 enteros. Este es el tipo correcto.
    int (*ptr)[4] = a;

    printf("Declaramos 'int (*ptr)[4] = a;'. ¡Esto sí funciona!\n");
    printf("El compilador ahora sabe que cada 'salto' (ptr+1) debe mover el puntero\n");
    printf("4 * sizeof(int) bytes para llegar a la siguiente fila.\n\n");

    printf("Accediendo a los elementos con `ptr[fila][columna]`:\n");
    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna < COLUMNAS; columna++) {
            printf("%-4d", ptr[fila][columna]);
        }
        printf("\n");
    }


    printf("\n--- Forma Correcta 2: Puntero simple (tratando la matriz como plana) ---\n\n");

    // `p_simple` apunta al primer entero de la matriz (`a[0][0]`).
    // El cast `(int *)` le dice al compilador que trate la matriz como un
    // simple bloque de enteros, ignorando su estructura 2D.
    int *p_simple = (int *)a;

    printf("Declaramos 'int *p_simple = (int *)a;'.\n");
    printf("Ahora tratamos el bloque de memoria 3x4 como un array lineal de 12 elementos.\n");
    printf("Necesitamos calcular el índice manualmente: acceso = p_simple[(i * 4) + j]\n\n");

    printf("Accediendo a los elementos con aritmética de punteros:\n");
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 4; columna++) {
            // Se necesita la fórmula: (fila_actual * ANCHO_TOTAL) + columna_actual
            printf("%-4d", p_simple[(fila * 4) + columna]);
        }
        printf("\n");
    }

    return 0;
}
