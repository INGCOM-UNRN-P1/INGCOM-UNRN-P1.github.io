// Operaciones con matrices

#include <stdio.h>

#define FILAS 3
#define COLS 3

void imprimir_matriz(int mat[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Suma de matrices
void sumar_matrices(int a[FILAS][COLS], int b[FILAS][COLS], int resultado[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Multiplicación por escalar
void multiplicar_escalar(int mat[FILAS][COLS], int escalar, int resultado[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[i][j] = mat[i][j] * escalar;
        }
    }
}

// Transpuesta
void transponer(int mat[FILAS][COLS], int resultado[COLS][FILAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[j][i] = mat[i][j];
        }
    }
}

// Traza (suma de la diagonal)
int traza(int mat[FILAS][COLS]) {
    int suma = 0;
    for (int i = 0; i < FILAS && i < COLS; i++) {
        suma += mat[i][i];
    }
    return suma;
}

int main(void) {
    int a[FILAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int b[FILAS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int resultado[FILAS][COLS];
    
    printf("Matriz A:\n");
    imprimir_matriz(a);
    
    printf("\nMatriz B:\n");
    imprimir_matriz(b);
    
    // Suma
    sumar_matrices(a, b, resultado);
    printf("\nA + B:\n");
    imprimir_matriz(resultado);
    
    // Multiplicación por escalar
    multiplicar_escalar(a, 2, resultado);
    printf("\n2 * A:\n");
    imprimir_matriz(resultado);
    
    // Traza
    printf("\nTraza de A: %d\n", traza(a));
    
    return 0;
}
