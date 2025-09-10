
#include <stdio.h>

int main()
{

    int cantidad = 0;
    printf("de que tamaño es el arreglo?\n");
    scanf("%d", &cantidad);
    
    int arreglo[cantidad] = {4};
    printf("el tamaño es de %zu\n", sizeof(arreglo));
    // Que debiera de ser sizeof(int) * cantidad
    return 0;
}
