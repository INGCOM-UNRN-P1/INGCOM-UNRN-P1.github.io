#include <stdio.h>
#include <stdlib.h>

int maximo(int arreglo[], size_t largo)
{
    for (int i = 1; i < largo; i++) {
        if (arreglo[i] > arreglo[0]) {
            arreglo[0] = arreglo[i];
        }
    }
    return arreglo[0];
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    printf("El arreglo es: ");
    imprime(arr, len);
    int max = maximo(arr, len);
    printf("El maximo es: ");
    imprime(arr, len);
    return 0;
}
