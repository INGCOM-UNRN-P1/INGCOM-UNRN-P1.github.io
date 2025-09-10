#include <stdio.h>
#include <stdlib.h> // Para atoi() y EXIT_FAILURE

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <número1> <número2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convertimos las cadenas a enteros
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int suma = num1 + num2;
    printf("El resultado de %d + %d es %d\n", num1, num2, suma);

    return 0;
}
