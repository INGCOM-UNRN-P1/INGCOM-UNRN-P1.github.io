// Operadores aritméticos, lógicos y relacionales

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // Operadores aritméticos
    int a = 10, b = 3;
    printf("Operadores Aritméticos:\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d (división entera)\n", a, b, a / b);
    printf("%d %% %d = %d (módulo)\n", a, b, a % b);
    
    // Operadores relacionales
    printf("\nOperadores Relacionales:\n");
    printf("%d == %d: %d\n", a, b, a == b);
    printf("%d != %d: %d\n", a, b, a != b);
    printf("%d > %d: %d\n", a, b, a > b);
    printf("%d < %d: %d\n", a, b, a < b);
    printf("%d >= %d: %d\n", a, b, a >= b);
    printf("%d <= %d: %d\n", a, b, a <= b);
    
    // Operadores lógicos
    bool verdadero = true;
    bool falso = false;
    printf("\nOperadores Lógicos:\n");
    printf("true && false: %d\n", verdadero && falso);
    printf("true || false: %d\n", verdadero || falso);
    printf("!true: %d\n", !verdadero);
    
    // Operadores de incremento/decremento
    int x = 5;
    printf("\nIncremento/Decremento:\n");
    printf("x = %d\n", x);
    printf("x++ = %d, después x = %d\n", x++, x);
    printf("++x = %d, después x = %d\n", ++x, x);
    printf("x-- = %d, después x = %d\n", x--, x);
    printf("--x = %d, después x = %d\n", --x, x);
    
    return 0;
}
