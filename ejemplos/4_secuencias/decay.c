#include <stdio.h>
#include <stdlib.h>

size_t largo(int arreglo[10])
{
    printf("%zu:%zu\n", sizeof(arreglo), sizeof(arreglo[0]));
    return sizeof(arreglo) / sizeof(arreglo[0]);
}

void imprime(int arreglo[], size_t largo)
{
    for(size_t i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = { };
    size_t len = sizeof(arr) / sizeof(arr[0]);
    size_t calculado = largo(arr);

    printf("el largo es <%zu> y el calculado es <%zu>\n", len, calculado);
    imprime(arr, len);
    return 0;
}
