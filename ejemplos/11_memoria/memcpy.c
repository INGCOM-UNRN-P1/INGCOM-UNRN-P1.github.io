#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{


    const int origen[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int largo_origen = sizeof(origen) / sizeof(int);
    int *destino = (int*)malloc(largo_origen * sizeof(int));

    for (int i = 0; i < largo_origen; i++){
        printf("%d, %d\t", i, origen[i]);
    }
    printf("\n");
    if ((destino != NULL)){
        destino = memcpy(destino, origen, sizeof(origen));
    } else {
    	exit(EXIT_FAILURE);
    }
    for (int i = 0; i < largo_origen; i++){

        printf("%d, %d -> %d\t", i, origen[i], destino[i]);
    }
    printf("\n");
    return 0;
}
