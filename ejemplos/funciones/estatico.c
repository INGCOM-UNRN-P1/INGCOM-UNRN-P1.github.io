
#include <stdio.h>

int incremento (int numero)
{
    static int veces = 0;
    veces = (veces * 10)+1;
    printf("estatico: %d\n", veces);
    return numero + 1;
}


int main(int argc, char *argv[])
{
    for (int i = 0; i < 4; i++) 
    {
        printf("valor i %d \n", incremento(i));
    }
//    printf("Hola i %d \n", i);
    return 0;
}

