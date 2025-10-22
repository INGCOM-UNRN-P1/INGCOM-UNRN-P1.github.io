#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Convierte un número de bytes a una cadena legible por humanos.
 *
 * Formatea un valor de bytes (B, KB, MB, GB, TB, PB, EB) en la unidad más
 * grande posible para que el valor numérico sea menor que 1024.
 *
 * @param bytes El número de bytes a formatear.
 * @param buffer Un puntero al búfer de caracteres donde se guardará la cadena.
 * @param size El tamaño total del búfer.
 * @return Un puntero al búfer formateado para conveniencia.
 */
char* format_bytes(unsigned long long bytes, char* buffer, size_t size) {
    // Si el buffer no es válido, no hacemos nada.
    if (buffer == NULL || size == 0) {
        return NULL;
    }

    // Las unidades que usaremos.
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB"};
    int unit_index = 0;

    // Usamos 'double' para manejar los decimales durante la división.
    double readable_value = (double)bytes;

    // Caso especial para 0 bytes
    if (bytes == 0) {
        snprintf(buffer, size, "0 B");
        return buffer;
    }

    // Dividimos por 1024 hasta que el valor sea menor que 1024,
    // o hasta que nos quedemos sin unidades.
    while (readable_value >= 1024.0 && unit_index < (sizeof(units) / sizeof(units[0])) - 1) {
        readable_value = readable_value / 1024.0;
        unit_index++;
    }

    // Formateamos la cadena de salida con dos decimales.
    snprintf(buffer, size, "%.2f %s", readable_value, units[unit_index]);

    return buffer;
}

int main() {
    // Rango de búsqueda: desde 0 hasta 200 GB.
    // Usamos unsigned long long para consistencia con format_bytes
    unsigned long long low = 0;
    
    unsigned long long high = 200ULL * 1024ULL * 1024ULL * 1024ULL;
    unsigned long long max_alloc_possible = 0;

    // Buffer para mostrar el límite de búsqueda formateado
    char high_formatted[32];
    format_bytes(high, high_formatted, sizeof(high_formatted));

    printf("Buscando el tamaño máximo de asignación de memoria con un límite de ~%s...\n", high_formatted);
    printf("Esto puede tardar unos segundos.\n\n");

    // Usamos una búsqueda binaria para encontrar el tamaño máximo de forma eficiente.
    while (low <= high) {
        // Calculamos el punto medio del rango actual.
        unsigned long long mid = low + (high - low) / 2;
        
        // Evitamos intentar malloc(0)
        if (mid == 0) {
            low = mid + 1;
            continue;
        }

        void *mem = malloc(mid);

        if (mem != NULL) {
            // Éxito: La asignación funcionó.
            // Esto significa que 'mid' es un tamaño posible. Lo guardamos.
            max_alloc_possible = mid;
            
            // Liberamos la memoria para la siguiente prueba.
            free(mem);
            
            // Ahora intentamos buscar un bloque aún más grande en la mitad superior.
            low = mid + 1;
        } else {
            // Fallo: La asignación no funcionó.
            // El bloque 'mid' es demasiado grande.
            // Buscamos un bloque más pequeño en la mitad inferior.
            high = mid - 1;
        }
    }

    if (max_alloc_possible > 0) {
        // Buffer para guardar el tamaño formateado.
        char formatted_size[32];
        format_bytes(max_alloc_possible, formatted_size, sizeof(formatted_size));

        printf("\n========================================================\n");
        printf("¡Búsqueda completada! El tamaño máximo encontrado es:\n");
        // CORREGIDO: Usamos %llu para unsigned long long
        printf("   -> %llu bytes (%s)\n", max_alloc_possible, formatted_size);
        printf("========================================================\n\n");
        printf("Nota: El valor es menor al límite porque el propio programa\n");
        printf("   (código, pila, librerías, etc.) ya consumen una parte de la memoria.\n");
    } else {
        printf("\nNo se pudo asignar ninguna cantidad significativa de memoria.\n");
        printf("Asegúrate de haber establecido el límite con 'ulimit' correctamente.\n");
    }

    return 0;
}


