#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 1. Reservamos dos bloques de memoria en el heap, uno después del otro.
    // malloc no garantiza que sean contiguos, pero en implementaciones simples
    // y con asignaciones consecutivas, es muy probable que lo sean.

    // Un búfer pequeño y vulnerable.
    char *buffer = (char *)malloc(sizeof(char) * 16);
    
    // Datos "importantes" que queremos proteger, ubicados justo después.
    char *secret_data = (char *)malloc(sizeof(char) * 64);

    if (buffer == NULL || secret_data == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        return 1;
    }

    // 2. Guardamos un mensaje secreto en el segundo bloque de memoria.
    strcpy(secret_data, "ESTA ES LA INFORMACION SECRETA");

    printf("--- ANTES DEL OVERFLOW ---\n");
    printf("Dirección del buffer      : %p\n", (void *)buffer);
    printf("Dirección de secret_data  : %p\n", (void *)secret_data);
    printf("Contenido de secret_data  : '%s'\n\n", secret_data);

    // 3. ¡El ataque! Escribimos en `buffer` una cadena mucho más grande que su capacidad.
    // La cadena tiene más de 16 caracteres, por lo que se "desbordará" y
    // comenzará a sobrescribir la memoria que le sigue, que es donde
    // se encuentra `secret_data`.
    char *attack_string = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA_CORROMPIDO";
    
    printf("--- REALIZANDO EL OVERFLOW ---\n");
    printf("Escribiendo %zu bytes en el buffer de 16 bytes...\n\n", strlen(attack_string));
    strcpy(buffer, attack_string); // ¡Peligro! strcpy no comprueba límites.

    // 4. Verificamos el resultado.
    // El contenido de `secret_data` ha sido parcial o totalmente sobrescrito
    // por los caracteres 'A' y el resto de la cadena de ataque.
    printf("--- DESPUÉS DEL OVERFLOW ---\n");
    printf("Contenido del buffer      : '%s'\n", buffer);
    printf("Contenido de secret_data  : '%s'  <-- ¡DATOS CORRUPTOS!\n\n", secret_data);

    printf("Como se puede ver, al escribir más allá de los límites del 'buffer',\n");
    printf("hemos 'solapado' y sobrescrito la memoria asignada para 'secret_data'.\n");

    // 5. Liberamos la memoria (aunque el heap ya podría estar en un estado inestable).
    free(buffer);
    free(secret_data);

    return 0;
}
