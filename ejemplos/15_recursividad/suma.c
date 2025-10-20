#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n)
{   
    if ( n == 1)
    {
        return 1L;
    }
    else
    {
        return n * factorial(n - 1);
    }
}


int suma(int n)
{
    if ( n == 1)
    {
        printf("<1>");
        return 1;
    }
    else
    {
        printf("{%d}", n);
        int resultado = n + suma(n - 1);
        printf("[%d]", resultado);
        return resultado;
    }
}

/*
10 + suma(9)
    9 + suma(8)
        8 + suma(7)
            7 + suma(6)
                6 + suma(5)
                    5 + suma(4)
                        4 + suma(3)
                            3 + suma(2)
                                2 + suma(1)
                                    1
                                1 + 2
                            3 + 3
                        4 + 6
                    5 + 10
                6 + 15
            7 + 21
        8 + 28
    9 + 36
55 = 10 + 45

55         
*/
int main(int argc, char *argv[]) 
{
    if (argc == 2)
    {
        int termino = atoi(argv[1]);
        unsigned long long int resultado = factorial(termino);
        printf("termino: %d = resultado:%llu\n", termino, resultado);   
    }
    else
    {
        printf("\tUso: %s n\n", argv[0]);
    }
    return 0;
}
