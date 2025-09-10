#include <stdio.h>

void imprimir_matriz(int filas, int columnas, int matriz[][columnas])
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

void imprimir_matriz_2(int filas, int columnas, int matriz[][columnas])
{
    int *magia = (int *)matriz;
    for (int i = 0; i < filas * columnas; i++)
    {
        printf("%d ", magia[i]);
    }
}

int main()
{
    int filas = 2;
    int columnas = 3;

    int mi_matriz[2][3];

    // Llenar la matriz con datos
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            mi_matriz[i][j] = i;
        }
    }

    imprimir_matriz(filas, columnas, mi_matriz);
    printf("Y ahora, algo medio raro...\n");
    imprimir_matriz_2(filas, columnas, mi_matriz);

    return 0;
}