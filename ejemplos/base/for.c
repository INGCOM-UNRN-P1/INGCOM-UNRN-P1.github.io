#include <stdio.h>

int main() {
    // Ejemplo 1: Bucle for básico con variable de control
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    // Ejemplo 2: Bucle for con varias variables de control
    for (int i = 0, j = 5; i < j; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }
    
// Ejemplo 3: Bucle for sin cuerpo, solo incrementa y controla
    int sum = 0;
    for (int i = 1; i <= 10; sum += i++); // Calcula la suma de 1 a 10
    printf("Sum = %d\n", sum);

    // Ejemplo 4: Bucle infinito utilizando for(;;)
    int count = 0;
    for (;;)
    {
        printf("Count = %d\n", count);
        if (++count == 3) // Rompe el bucle después de 3 iteraciones
            break;
    }

    return 0;
}
