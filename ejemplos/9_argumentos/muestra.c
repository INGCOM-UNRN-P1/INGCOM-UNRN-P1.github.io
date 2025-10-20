#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Número total de argumentos: %d\n\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
