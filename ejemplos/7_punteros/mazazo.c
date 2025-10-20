
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("tamanio de un double %llu\n", sizeof (double));
    char* arreglo = (char *) malloc(1);
    *arreglo = 'h';
    for(int i = -20000; i<100000; i++)
    {
        printf("%c", arreglo[i]);
    }
    free(arreglo);
    return 0;
}
    
