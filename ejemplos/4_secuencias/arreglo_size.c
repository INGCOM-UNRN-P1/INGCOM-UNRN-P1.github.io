#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena_caracteres(char cadena[]) {
    // Determina la longitud de la cadena.
    size_t n = strlen(cadena);
    
    // Bucle externo para las pasadas de ordenamiento.
    for (size_t i = 0; i < n - 1; i++) {
        // Bucle interno para comparar y mover el elemento más grande al final.
        for (size_t j = 0; j < n - i - 1; j++) {
            // Compara los caracteres adyacentes.
            if (cadena[j] > cadena[j + 1]) {
                // Si el carácter actual es mayor que el siguiente, los intercambia.
                char temp = cadena[j];
                cadena[j] = cadena[j + 1];
                cadena[j + 1] = temp;
            }
        }
    }
}

int main() {
    char mi_cadena[] = "ejemplo de cadena desordenada";

    printf("Cadena original: \"%s\"\n", mi_cadena);

    // Llama a la función para ordenar la cadena.
    ordena_caracteres(mi_cadena);
    
    printf("Cadena ordenada: \"%s\"\n", mi_cadena);

    //ademas, ¿en donde modificamos la cadena?
    ordena_caracteres("ejemplo de cadena desordenada");

    return 0;
}
