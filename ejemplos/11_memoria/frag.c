#include <stdio.h>
#include <stdlib.h>

#define NUM_ALLOCATIONS 20
#define LARGE_ALLOCATION_SIZE 1024 * 1024 * 40 // 60 MB

int main() {
    void *pointers[NUM_ALLOCATIONS];

    printf("Realizando una serie de asignaciones de memoria de diferentes tamaños...\n");

    // Asignar bloques de memoria de varios tamaños
    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        // Alternar entre tamaños pequeños y grandes para crear huecos
        int size_to_allocate = (i % 2 == 0) ? 128 : 256;
        pointers[i] = malloc(size_to_allocate);
        if (pointers[i] == NULL) {
            printf("Error: No se pudo asignar memoria para el puntero %d\n", i);
            // Liberar memoria asignada previamente antes de salir
            for (int j = 0; j < i; j++) {
                free(pointers[j]);
            }
            return 1;
        }
        printf("Puntero %d asignado con %d bytes en la dirección: %p\n", i, size_to_allocate, pointers[i]);
    }

    printf("\nLiberando los punteros de índice par para crear huecos en la memoria...\n");

    // Liberar cada segundo bloque de memoria para crear "huecos"
    for (int i = 0; i < NUM_ALLOCATIONS; i += 2) {
        printf("Liberando el puntero %d en la dirección: %p\n", i, pointers[i]);
        free(pointers[i]);
        pointers[i] = NULL; // Buena práctica para evitar punteros colgantes
    }

    printf("\nIntentando realizar una asignación de memoria grande...\n");

    // Intentar asignar un bloque grande de memoria
    void *large_pointer = malloc(LARGE_ALLOCATION_SIZE);

    if (large_pointer == NULL) {
        printf("\nResultado: ¡Falló la asignación de memoria grande!\n");
        printf("Esto probablemente se deba a la fragmentación de la memoria.\n");
        printf("Aunque puede haber suficiente memoria libre en total, no hay un bloque contiguo lo suficientemente grande.\n");
    } else {
        printf("\nResultado: La asignación de memoria grande fue exitosa en la dirección: %p\n", large_pointer);
        printf("Esto puede suceder si el sistema operativo pudo encontrar un bloque contiguo o si el 'heap' no estaba lo suficientemente fragmentado.\n");
        free(large_pointer);
    }

    // Liberar la memoria restante
    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        if (pointers[i] != NULL) {
            free(pointers[i]);
        }
    }

    return 0;
}
