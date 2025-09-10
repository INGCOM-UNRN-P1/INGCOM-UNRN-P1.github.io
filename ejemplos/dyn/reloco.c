#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void alvin(int cantidad, int i)
{
    char cadena[cantidad];
    // memset(cadena, 'a', cantidad);
    printf("%d: %s\n", i, cadena);
    alvin(cantidad, i + 1);
}

int main()
{
    int j = 1;
    int* ptr = &j;
    while (1) {
        *ptr = 0;
        ptr--;
        j++;
        printf("%d, ", j);
    }

    const int patron[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    const int largo_patron = sizeof(patron) / sizeof(int);
    int* memoria = NULL;
    memoria = (int*)malloc(largo_patron * sizeof(int));
    if (memoria != NULL) {
        memoria = memcpy(memoria, patron, sizeof(patron));
        imprime(largo_patron, memoria);
        memoria = memset(memoria, 999, sizeof(patron));
        imprime(largo_patron, memoria);
    } else {
        exit(2);
    }
}
