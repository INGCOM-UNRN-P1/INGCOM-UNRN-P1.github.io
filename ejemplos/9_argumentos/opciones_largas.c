// Procesamiento de opciones largas (estilo --opcion)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    bool verbose;
    bool help;
    char *archivo_entrada;
    char *archivo_salida;
} Opciones;

void mostrar_ayuda(const char *programa) {
    printf("Uso: %s [opciones]\n\n", programa);
    printf("Opciones:\n");
    printf("  --help              Muestra esta ayuda\n");
    printf("  --verbose           Modo verboso\n");
    printf("  --input <archivo>   Archivo de entrada\n");
    printf("  --output <archivo>  Archivo de salida\n");
}

int procesar_argumentos(int argc, char *argv[], Opciones *opts) {
    // Inicializar opciones
    opts->verbose = false;
    opts->help = false;
    opts->archivo_entrada = NULL;
    opts->archivo_salida = NULL;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            opts->help = true;
        } else if (strcmp(argv[i], "--verbose") == 0) {
            opts->verbose = true;
        } else if (strcmp(argv[i], "--input") == 0) {
            if (i + 1 < argc) {
                opts->archivo_entrada = argv[++i];
            } else {
                fprintf(stderr, "Error: --input requiere un argumento\n");
                return 0;
            }
        } else if (strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                opts->archivo_salida = argv[++i];
            } else {
                fprintf(stderr, "Error: --output requiere un argumento\n");
                return 0;
            }
        } else {
            fprintf(stderr, "Opción desconocida: %s\n", argv[i]);
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, char *argv[]) {
    Opciones opciones;
    
    if (!procesar_argumentos(argc, argv, &opciones)) {
        mostrar_ayuda(argv[0]);
        return 1;
    }
    
    if (opciones.help) {
        mostrar_ayuda(argv[0]);
        return 0;
    }
    
    // Mostrar opciones procesadas
    printf("Opciones configuradas:\n");
    printf("Verbose: %s\n", opciones.verbose ? "Sí" : "No");
    printf("Entrada: %s\n", opciones.archivo_entrada ? opciones.archivo_entrada : "(ninguno)");
    printf("Salida: %s\n", opciones.archivo_salida ? opciones.archivo_salida : "(ninguno)");
    
    if (opciones.verbose) {
        printf("\nModo verboso activado\n");
        printf("Procesando archivos...\n");
    }
    
    return 0;
}
