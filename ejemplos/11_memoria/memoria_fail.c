#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Intentamos asignar 200 MB
    long size_mb = 200;
    long size_bytes = size_mb * 1024 * 1024;
    printf("Intentando asignar %ld MB de memoria...\n", size_mb);

    void *mem = malloc(size_bytes);
//    void *mem = malloc(0);

    if (mem == NULL) {
        perror("malloc falló");
        printf("¡Simulación de estrés exitosa! No se pudo asignar la memoria.\n");
        return 1;
    }

    printf("Memoria asignada exitosamente en %p.\n", mem);
    memset(mem, 0, size_bytes); // Usamos la memoria para asegurar que se materialice
    free(mem);
    free(mem);
    return 0;
}
