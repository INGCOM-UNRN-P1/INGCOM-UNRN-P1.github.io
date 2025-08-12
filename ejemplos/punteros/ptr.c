#include <stdio.h>


int main()
{
    int valor = 10;
    int *puntero = &valor;
//    int **holy_cow = &puntero;
    printf("A: %x - %p\n", valor, puntero);

    *puntero = *(puntero * 2);
    
//    *puntero = *puntero + 10;

    printf("B: %d - %p\n", valor, puntero);
    printf("C: %d - %p\n", *puntero, &puntero);
//    printf("D: %d\n", sizeof(puntero));
//    printf("E: %d\n", sizeof(holy_cow));

}
