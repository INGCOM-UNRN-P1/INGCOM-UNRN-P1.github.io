

#include <stdio.h>

long factorial(long valor)
{
    if (valor < 1){
        printf("fin!\n");
        return 1;
    }
    else
    {
        printf("valor %ld\n", valor);
        return valor * factorial(valor - 1L);
    }
}


int main()
{
    long valor = 10L;
    long resultado = factorial(valor);
    printf("%ld!=%ld\n", valor, resultado);
    return 0;
}
