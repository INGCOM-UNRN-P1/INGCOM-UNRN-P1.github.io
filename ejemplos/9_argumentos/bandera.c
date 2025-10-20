#include <stdio.h>
#include <string.h> // Para strcmp()

int main(int argc, char *argv[]) {
    // Si se pasa el argumento "--help", muestra un mensaje de ayuda
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printf("Este programa es un ejemplo.\n");
        printf("Uso: %s [opciones]\n", argv[0]);
        return 0;
    }

    printf("Ejecutando normalmente...\n");
    return 0;
}
