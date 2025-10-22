#include <stdio.h>
#include <stdlib.h>

void consumi_stack(long long counter) {
    char stack_eater[counter * 1024];
    stack_eater[0] = 'a'; // por si el compilador quiere optimizar la creación del arreglo.

    if (counter % 10 == 0) {
        printf("Nivel de recursión: %lld - %lld\n", counter, counter * 1024 * 100);
    }

    // "Ahí Les Va" (ALV) - la llamada recursiva que nos llevará al desastre.
    consumi_stack(counter + 1);
}

int main() {
    printf("Iniciando Stack Overflow.\n");
    
    printf("--- INSTRUCCIONES ---\n");
    printf("Para que funcione como se espera, limita la memoria virtual antes de ejecutarlo.\n");
    printf("Ejemplo para un límite de 200 MB:\n");
    printf("  1. Compila el código: gcc stack_overflow.c -o stack_overflow\n");
    printf("  2. Ejecuta con el límite: ulimit -s unlimited && ulimit -v 204800 && ./stack_overflow\n\n");
    printf("Presiona Enter para comenzar...\n");
    getchar();
    
    consumi_stack(1);

    printf("¡Esto no debería imprimirse!\n");

    return 0;
}
