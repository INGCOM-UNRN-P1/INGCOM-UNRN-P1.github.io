#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[10];
    for (size_t i = 0; i < 100 ; i++)
    {
        if (i % 5 == 0)
        {
            printf("\n");
        }
        arreglo[i] = 0;
//        printf("%zu/%d|",i, arreglo[i]);
        printf("%zu, ", i);
    }
    return 0;
}
