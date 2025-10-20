// Tipos de datos básicos y variables en C

#include <stdio.h>

int main(void) {
    // Enteros
    int edad = 25;
    short temperatura = -5;
    long poblacion = 45000000L;
    
    // Caracteres
    char inicial = 'M';
    char letra = 65;  // Código ASCII de 'A'
    
    // Punto flotante
    float pi = 3.14159f;
    double precision = 3.141592653589793;
    
    // Impresión de valores
    printf("Edad: %d años\n", edad);
    printf("Temperatura: %hd°C\n", temperatura);
    printf("Población: %ld habitantes\n", poblacion);
    printf("Inicial: %c\n", inicial);
    printf("Letra (ASCII %d): %c\n", letra, letra);
    printf("Pi (float): %.5f\n", pi);
    printf("Pi (double): %.15f\n", precision);
    
    // Tamaños de los tipos
    printf("\nTamaños en bytes:\n");
    printf("int: %zu\n", sizeof(int));
    printf("short: %zu\n", sizeof(short));
    printf("long: %zu\n", sizeof(long));
    printf("char: %zu\n", sizeof(char));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    
    return 0;
}
