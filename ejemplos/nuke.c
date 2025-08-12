#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned long long int contador = 1;
    while (1)
    {
        contador = contador * 2;
        printf("%llu \n", contador);
        malloc(contador);
        malloc(1024*1024);
    }
    return 0xCAFE;
}
