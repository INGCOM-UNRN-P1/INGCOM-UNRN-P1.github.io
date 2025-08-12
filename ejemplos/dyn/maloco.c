#include <stdio.h>
#include <stdlib.h>

void rellena(int largo, int arreglo[])
{
    int i = 0;
    while (i < largo) {
        arreglo[i] = i + 10;
        i++;
    }
}

void imprime(int largo, int arreglo[])
{
    int i = 0;
    while (i < largo) {
        printf("%d, ", arreglo[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    const int patron[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int* ptr_4 = (int*)calloc(10, sizeof(int));
    rellena(10, ptr_4);
    imprime(10, ptr_4);

    ptr_4 = (int*)realloc(ptr_4, sizeof(int) * 30);
    printf("realocado\n");
    imprime(30, ptr_4);

    ptr_4 = (int*)realloc(ptr_4, sizeof(int) * 5);
    printf("realocado\n");
    imprime(5, ptr_4);

    ptr_4 = (int*)realloc(ptr_4, sizeof(int) * 30);
    printf("realocado\n");
    imprime(30, ptr_4);
}
