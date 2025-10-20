// Lectura y escritura de archivos CSV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

// Escribe personas en formato CSV
int escribir_csv(const char *archivo, Persona personas[], int n) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return 0;
    }
    
    // Encabezados
    fprintf(f, "nombre,edad,altura\n");
    
    // Datos
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s,%d,%.2f\n", 
                personas[i].nombre, 
                personas[i].edad, 
                personas[i].altura);
    }
    
    fclose(f);
    return 1;
}

// Lee personas desde un archivo CSV
int leer_csv(const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        return 0;
    }
    
    char linea[256];
    
    // Saltar encabezado
    if (fgets(linea, sizeof(linea), f) == NULL) {
        fclose(f);
        return 0;
    }
    
    printf("Datos leídos del CSV:\n");
    printf("%-20s %5s %7s\n", "Nombre", "Edad", "Altura");
    printf("%-20s %5s %7s\n", "------", "----", "------");
    
    // Leer datos
    while (fgets(linea, sizeof(linea), f) != NULL) {
        Persona p;
        
        // Parsear línea CSV
        char *token = strtok(linea, ",");
        if (token == NULL) continue;
        strncpy(p.nombre, token, sizeof(p.nombre) - 1);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        p.edad = atoi(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        p.altura = atof(token);
        
        printf("%-20s %5d %7.2f\n", p.nombre, p.edad, p.altura);
    }
    
    fclose(f);
    return 1;
}

int main(void) {
    const char *nombre_archivo = "personas.csv";
    
    // Crear datos de ejemplo
    Persona personas[] = {
        {"Ana Martínez", 25, 1.65},
        {"Bruno Silva", 30, 1.80},
        {"Carla Ruiz", 28, 1.70},
        {"Diego Pérez", 35, 1.75}
    };
    int n = sizeof(personas) / sizeof(personas[0]);
    
    // Escribir CSV
    printf("Escribiendo %d personas a CSV...\n\n", n);
    if (!escribir_csv(nombre_archivo, personas, n)) {
        fprintf(stderr, "Error al escribir CSV\n");
        return 1;
    }
    
    // Leer CSV
    if (!leer_csv(nombre_archivo)) {
        fprintf(stderr, "Error al leer CSV\n");
        return 1;
    }
    
    return 0;
}
