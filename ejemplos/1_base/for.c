#include <stdio.h>

int main() {
    // Ejemplo 1: lazo for básico con variable de control
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    // Ejemplo 2: lazo for con varias variables de control
    for (int i = 0, j = 5; i < j; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }
    
// Ejemplo 3: lazo for sin cuerpo, solo incrementa y controla
    int sum = 0;
    for (int i = 1; i <= 10; sum += i++); // Calcula la suma de 1 a 10
    printf("Sum = %d\n", sum);

    // Ejemplo 4: lazo infinito utilizando for(;;)
    int count = 0;
    for (;;)
    {
        printf("Count = %d\n", count);
        if (++count == 3) // Rompe el lazo después de 3 iteraciones
            break;
    }

    return 0;
}
