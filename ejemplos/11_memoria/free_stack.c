#include <stdio.h>
#include <stdlib.h> // Necesario para 'free'

int main() {
    // 1. Declaramos una variable automática (en el stack).
    // Su memoria es gestionada por el compilador. Se crea al entrar
    // a la función 'main' y se destruye automáticamente al salir.
    int numero_en_stack = 42;

    // 2. Creamos un puntero que apunta a la dirección de esa variable.
    int* puntero_a_stack = &numero_en_stack;

    printf("El puntero apunta a la dirección: %p\n", (void*)puntero_a_stack);
    printf("El valor al que apunta es: %d\n", *puntero_a_stack);
    printf("---\n");
    printf(" Intentando liberar memoria del stack con 'free()...'\n");

    // 3. ERROR: Intentamos usar 'free()' en un puntero a memoria del stack.
    // 'free()' SÓLO debe usarse con punteros devueltos por 'malloc',
    // 'calloc' o 'realloc'.
    free(puntero_a_stack);

    // Esta línea probablemente nunca se ejecute. Si lo hace, es porque
    // el programa tiene un comportamiento indefinido y podría estar corrupto.
    printf("Si ves este mensaje, el programa no crasheó (lo cual es malo).\n");

    return 0; // El programa fallará aquí o al retornar.
}
