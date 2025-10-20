#include<stdio.h>
#include<stdlib.h>

// Código aportado por https://github.com/engineer01724

int global = 20;
int global_no_inic;

int main(void)
{
    int local = 30;
    static int estatica = 25;
    int *dinamic = (int *)malloc(sizeof(int));
    if(dinamic != NULL)
    {
        *dinamic = 76;

        printf("estatica (segmento datos): %p\n", (void*)&estatica);
        printf("Local (segmento Stack): %p\n", (void*)&local);
        printf("global (segmento datos): %p\n", (void*)&global);
        printf("global_no_inicializada (segmento datos): %p\n", (void*)&global_no_inic); 
        printf("dinamica (Segmento Heap): %p\n", (void*)dinamic);

        free(dinamic);
    }

   return EXIT_SUCCESS;
}

