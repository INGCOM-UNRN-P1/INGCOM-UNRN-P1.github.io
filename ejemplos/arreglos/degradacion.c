#include <stdio.h>

#define CAPACIDAD 200

int generador(int capacidad, char cad[])
{
    printf("%ld\n", sizeof(cad));
    cad[0] = 'X';
}

int main(int argc, char *argv[])
{
    char cadena[CAPACIDAD] = "Hola Mundo";
    printf("%s\n", cadena);
    generador(CAPACIDAD, cadena);
    printf("%s\n", cadena);
    return 0;
}

