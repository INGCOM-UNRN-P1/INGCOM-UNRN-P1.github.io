#include <stdio.h>

int operar(int largo, int *arreglo,  int (*func_ptr)(int))
{
    for(int i = 0; i < largo; i++)
    {
        func_ptr(arreglo[i]);
    }
    return 0;
}

int imprime(int valor)
{
    prinft("%d ", valor);
}

int suma(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

int main()
{
    int (*funcion_ptr)(int, int);
    funcion_ptr = &resta;
    int resultado = funcion_ptr(3,5);
    printf("Resultado es =%d\n", resultado);
    
    return 0;
}
