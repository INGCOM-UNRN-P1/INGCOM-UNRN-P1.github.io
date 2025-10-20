// Lazos (bucles) en C

#include <stdio.h>

int main(void) {
    // Lazo for
    printf("Lazo for (0 a 4):\n");
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }
    
    // Lazo while
    printf("\nLazo while (cuenta regresiva):\n");
    int contador = 5;
    while (contador > 0) {
        printf("%d...\n", contador);
        contador--;
    }
    printf("¡Despegue!\n");
    
    // Lazo do-while
    printf("\nLazo do-while (se ejecuta al menos una vez):\n");
    int x = 10;
    do {
        printf("x = %d\n", x);
        x--;
    } while (x > 5);
    
    // break y continue
    printf("\nUso de break y continue:\n");
    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            printf("Saltando i = 3\n");
            continue;  // Salta a la siguiente iteración
        }
        if (i == 7) {
            printf("Interrumpiendo en i = 7\n");
            break;  // Sale del lazo
        }
        printf("i = %d\n", i);
    }
    
    // Lazos anidados
    printf("\nTabla de multiplicar (3x3):\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d x %d = %2d  ", i, j, i * j);
        }
        printf("\n");
    }
    
    return 0;
}
