#include <stdio.h>

typedef int (*f_operacion_t)(int, int);

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
    printf("%d ", valor);
    return 0;
}

int suma(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

//int (*selectora (char argumento)) (int, int)
f_operacion_t selectora(char argumento)
{
    if (argumento == '+'){
        return &suma;
    } else if (argumento == '-') {
        return &resta;
    } else {
        return NULL;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    char argumento;
    scanf("%c", &argumento);
    int (*ptr)(int, int);
    ptr = selectora(argumento);
    int resultado = ptr(3,5);
    printf("resultado %d\n", resultado);

//    operar(7, arr, &imprime);

    return 0;
}
