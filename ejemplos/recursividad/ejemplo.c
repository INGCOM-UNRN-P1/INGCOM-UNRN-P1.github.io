

#include <stdio.h>

long funcion(long valor)
{
    if (valor < 1){
        printf("fin! %ld\n", valor);
        return 1;
    }
    else
    {
        printf("previo: %ld\n", valor);
        long resultado = valor + funcion(valor - 1);
        printf("posterior: %ld - %ld\n", valor, resultado);
        return resultado;
    }
}


int main()
{
    long valor = 10L;
    long resultado = funcion(valor);
    printf("%ld=%ld\n", valor, resultado);
    return 0;
}
