#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 10;
    void* ptr = malloc(sizeof(int) * numero);
    double* arr_largo = (double*)malloc(sizeof(double) * numero);

    int* ptr_numero = (int*)ptr;
    int i = 0;
    while (i < numero) {
        malloc(1024);
        ptr_numero[i] = i;
        i++;
    }
    i = 0;
    printf("i: %d / %p\n", i, &i);
    while (i < numero) {
        printf("%d / %d / %p\n", i, ptr_numero[i], &ptr_numero[i]);
        i++;
    }

    free(ptr_numero + 1);
}
