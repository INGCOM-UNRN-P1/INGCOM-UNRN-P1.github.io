#include <stdio.h>

#define FILAS 2
#define COLUMNAS 3

void imprimir_matriz(size_t filas, size_t columnas, int matriz[][COLUMNAS])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int filas = FILAS;
    int columnas = COLUMNAS;

    int mi_matriz[FILAS][COLUMNAS];

    // Llenar la matriz con datos
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            mi_matriz[i][j] = i;
        }
    }

    imprimir_matriz(filas, columnas, mi_matriz);

    return 0;
}
