// Ejemplo de compilación modular
// Este es el archivo principal

#include <stdio.h>
#include "matematica.h"
#include "utilidades.h"

int main(void) {
    printf("=== Programa Modular ===\n\n");
    
    // Usar funciones del módulo matemática
    int a = 15, b = 4;
    printf("Suma: %d + %d = %d\n", a, b, sumar(a, b));
    printf("Resta: %d - %d = %d\n", a, b, restar(a, b));
    printf("Multiplicación: %d * %d = %d\n", a, b, multiplicar(a, b));
    printf("División: %d / %d = %.2f\n\n", a, b, dividir(a, b));
    
    // Usar funciones del módulo utilidades
    saludar("Usuario");
    
    int numeros[] = {5, 2, 8, 1, 9};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("\nArreglo: ");
    imprimir_arreglo(numeros, n);
    
    printf("Máximo: %d\n", maximo(numeros, n));
    printf("Mínimo: %d\n", minimo(numeros, n));
    
    return 0;
}
