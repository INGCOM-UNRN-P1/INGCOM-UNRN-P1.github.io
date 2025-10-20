#include <stdio.h>
#include <stdlib.h>

long fibonacci(int termino)
{

    if (termino == 0) {
        return 0L;
    } else if (termino == 1) {
        return 1L;
    } else {
        return fibonacci(termino - 1) + fibonacci(termino - 2);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc == 2)
    {
        int termino = atoi(argv[1]);
        long resultado = fibonacci(termino);
        printf("Fibonacci termino %d es %ld\n", termino, resultado);    
    }
    else
    {
        printf("Calculo de fibonacci\n");
        printf("\tUso: %s n\n", argv[0]);
    }
    return 0;
}

