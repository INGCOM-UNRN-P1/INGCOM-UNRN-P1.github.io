// Paso de parámetros por valor

#include <stdio.h>

// Función que intenta modificar su parámetro
void intentar_modificar(int x) {
    x = x * 2;
    printf("Dentro de la función: x = %d\n", x);
}

// Función con múltiples parámetros
int suma(int a, int b) {
    return a + b;
}

// Función que retorna el máximo de dos números
int maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Función recursiva simple
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    // Paso por valor
    int numero = 5;
    printf("Antes de llamar: numero = %d\n", numero);
    intentar_modificar(numero);
    printf("Después de llamar: numero = %d\n", numero);
    printf("(El valor NO se modificó)\n\n");
    
    // Múltiples parámetros
    int resultado = suma(10, 20);
    printf("10 + 20 = %d\n\n", resultado);
    
    // Retorno de valor
    int a = 15, b = 23;
    printf("Máximo entre %d y %d: %d\n\n", a, b, maximo(a, b));
    
    // Recursión
    int n = 5;
    printf("Factorial de %d: %d\n", n, factorial(n));
    
    return 0;
}
