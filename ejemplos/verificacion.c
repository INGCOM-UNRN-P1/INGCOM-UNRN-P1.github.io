#include <stdio.h>

#define DIM 3

// La función recibe la matriz y su dimensión
int sumar_diagonal_principal(int matriz[][DIM], int dimension) {
  int suma = 0;
  for (int i = 0; i < dimension; i++) {
    suma = suma + matriz[i][i];
    // Accedemos solo a los elementos donde fila == columna
  }
  return suma;
}

int main() {
  int matriz_cuadrada[DIM][DIM] = {{10, 2, 3}, {4, 20, 6}, {7, 8, 30}};

  int suma = sumar_diagonal_principal(matriz_cuadrada, DIM);
  printf("La suma de la diagonal principal es: %d\n", suma);

  return 0;
}