#include <stdio.h>
#define TAMAÑO 100

int main() {
    int arreglo[TAMAÑO];
    for (int i = 0; i < TAMAÑO; i++) {
        arreglo[i] = i;
    }
    int suma = 0;
    for (int i = 0; i < TAMAÑO; i++) {
        suma += arreglo[i];
    }
    printf("Suma: %d\n", suma);
    return 0;
}

/*
Y para compilar:
gcc -S -O0 loop.c -o normal.s
gcc -S -O3 loop.c -o expandido.s
*/

