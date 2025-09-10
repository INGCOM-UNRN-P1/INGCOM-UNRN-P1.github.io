#include <stdlib.h>
#include <stdio.h>


int compara_menor_mayor (const void *_a, const void *_b)
{
    int a = *(int*)_a;
    int b = *(int*)_b;
 
    return a - b;
}

int compara_mayor_menor(const void *_a, const void *_b)
{
    return -compara_menor_mayor(_a, _b);
}

void muestra(int largo, int *arreglo)
{
    for(int i = 0; i<largo; i++)
    {
        printf("%d ", arreglo[i]);
    }
    putchar('\n');
}

int main()
{
    int arreglo[10] = {15,23,32,14,15,46,67,898,49,340};
    muestra(10,arreglo);
    qsort(arreglo, 10, sizeof(int), &compara_mayor_menor);
    muestra(10,arreglo);
    return 0;
}
