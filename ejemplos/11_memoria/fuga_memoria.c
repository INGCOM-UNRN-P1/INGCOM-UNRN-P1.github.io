// Ejemplo de fuga de memoria (memory leak)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INCORRECTO: Fuga de memoria
void funcion_con_fuga(void) {
    int *numeros = malloc(100 * sizeof(int));
    if (numeros == NULL) {
        return;
    }
    
    // Usamos la memoria...
    for (int i = 0; i < 100; i++) {
        numeros[i] = i;
    }
    
    // ERROR: No liberamos la memoria antes de salir
    // La memoria asignada se pierde y no puede recuperarse
}

// CORRECTO: Memoria liberada apropiadamente
void funcion_sin_fuga(void) {
    int *numeros = malloc(100 * sizeof(int));
    if (numeros == NULL) {
        return;
    }
    
    // Usamos la memoria...
    for (int i = 0; i < 100; i++) {
        numeros[i] = i;
    }
    
    // CORRECTO: Liberamos la memoria
    free(numeros);
}

// Fuga en estructuras complejas
typedef struct {
    char *nombre;
    int *datos;
    int n_datos;
} Registro;

// INCORRECTO: No libera la memoria interna
void destruir_registro_mal(Registro *reg) {
    free(reg);  // Solo libera la estructura, no sus miembros
}

// CORRECTO: Libera toda la memoria
void destruir_registro_bien(Registro *reg) {
    if (reg != NULL) {
        free(reg->nombre);   // Liberar miembros primero
        free(reg->datos);
        free(reg);           // Luego la estructura
    }
}

int main(void) {
    printf("Ejemplo de fugas de memoria\n\n");
    
    // Esto causaría una fuga si se llama muchas veces
    printf("Llamando a función con fuga...\n");
    funcion_con_fuga();
    printf("(Memoria perdida: 400 bytes)\n\n");
    
    // Esto libera correctamente la memoria
    printf("Llamando a función sin fuga...\n");
    funcion_sin_fuga();
    printf("(Memoria liberada correctamente)\n\n");
    
    // Ejemplo con estructura
    Registro *reg = malloc(sizeof(Registro));
    reg->nombre = malloc(50);
    strcpy(reg->nombre, "Ejemplo");
    reg->datos = malloc(10 * sizeof(int));
    reg->n_datos = 10;
    
    printf("Liberando estructura compleja correctamente...\n");
    destruir_registro_bien(reg);
    
    printf("\nUsa valgrind para detectar fugas de memoria:\n");
    printf("  valgrind --leak-check=full ./programa\n");
    
    return 0;
}
