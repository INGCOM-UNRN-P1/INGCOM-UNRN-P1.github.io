// Entrada y salida básica en C

#include <stdio.h>

int main(void) {
    char nombre[50];
    int edad;
    float altura;
    
    // Salida básica
    printf("=== Sistema de Registro ===\n\n");
    
    // Entrada de cadena
    printf("Ingresá tu nombre: ");
    if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
        // Remover el salto de línea si existe
        for (int i = 0; nombre[i] != '\0'; i++) {
            if (nombre[i] == '\n') {
                nombre[i] = '\0';
                break;
            }
        }
    }
    
    // Entrada de entero
    printf("Ingresá tu edad: ");
    if (scanf("%d", &edad) != 1) {
        printf("Error al leer la edad\n");
        return 1;
    }
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    // Entrada de flotante
    printf("Ingresá tu altura (en metros): ");
    if (scanf("%f", &altura) != 1) {
        printf("Error al leer la altura\n");
        return 1;
    }
    
    // Mostrar resultados
    printf("\n=== Datos Registrados ===\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d años\n", edad);
    printf("Altura: %.2f m\n", altura);
    
    return 0;
}
