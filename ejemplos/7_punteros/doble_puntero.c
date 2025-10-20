// Punteros a punteros (doble indirección)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que modifica un puntero mediante doble puntero
void asignar_memoria(int **ptr, int valor) {
    *ptr = malloc(sizeof(int));
    if (*ptr != NULL) {
        **ptr = valor;
    }
}

// Función que intercambia dos punteros
void intercambiar_punteros(int **p1, int **p2) {
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(void) {
    // Ejemplo 1: Modificar un puntero desde una función
    int *numero = NULL;
    printf("Antes: numero = %p\n", (void *)numero);
    
    asignar_memoria(&numero, 42);
    printf("Después: numero = %p, *numero = %d\n\n", (void *)numero, *numero);
    
    // Ejemplo 2: Intercambiar punteros
    int a = 10, b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;
    
    printf("Antes del intercambio:\n");
    printf("ptr_a apunta a %d\n", *ptr_a);
    printf("ptr_b apunta a %d\n", *ptr_b);
    
    intercambiar_punteros(&ptr_a, &ptr_b);
    
    printf("\nDespués del intercambio:\n");
    printf("ptr_a apunta a %d\n", *ptr_a);
    printf("ptr_b apunta a %d\n", *ptr_b);
    
    // Ejemplo 3: Arreglo de cadenas
    char *nombres[] = {
        "Ana",
        "Bruno",
        "Carlos",
        "Diana"
    };
    
    int n_nombres = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("\nArreglo de cadenas:\n");
    for (int i = 0; i < n_nombres; i++) {
        printf("%d: %s\n", i, nombres[i]);
    }
    
    // Liberación de memoria
    free(numero);
    
    return 0;
}
