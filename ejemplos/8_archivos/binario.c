// Trabajo con archivos binarios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

// Escribe un arreglo de empleados en formato binario
int escribir_empleados(const char *archivo, Empleado empleados[], int n) {
    FILE *f = fopen(archivo, "wb");
    if (f == NULL) {
        return 0;
    }
    
    size_t escritos = fwrite(empleados, sizeof(Empleado), n, f);
    fclose(f);
    
    return escritos == (size_t)n;
}

// Lee empleados desde un archivo binario
int leer_empleados(const char *archivo, Empleado **empleados, int *n) {
    FILE *f = fopen(archivo, "rb");
    if (f == NULL) {
        return 0;
    }
    
    // Determinar el tamaño del archivo
    fseek(f, 0, SEEK_END);
    long tamano = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    *n = tamano / sizeof(Empleado);
    *empleados = malloc(*n * sizeof(Empleado));
    
    if (*empleados == NULL) {
        fclose(f);
        return 0;
    }
    
    size_t leidos = fread(*empleados, sizeof(Empleado), *n, f);
    fclose(f);
    
    return leidos == (size_t)*n;
}

int main(void) {
    const char *nombre_archivo = "empleados.dat";
    
    // Crear datos de ejemplo
    Empleado empleados[] = {
        {1, "Ana García", 45000.50},
        {2, "Bruno López", 52000.00},
        {3, "Carlos Ruiz", 38000.75}
    };
    int n_empleados = sizeof(empleados) / sizeof(empleados[0]);
    
    // Escribir a archivo binario
    printf("Escribiendo %d empleados a archivo binario...\n", n_empleados);
    if (escribir_empleados(nombre_archivo, empleados, n_empleados)) {
        printf("Escritura exitosa\n\n");
    } else {
        fprintf(stderr, "Error al escribir\n");
        return 1;
    }
    
    // Leer desde archivo binario
    Empleado *leidos;
    int n_leidos;
    
    printf("Leyendo empleados desde archivo binario...\n");
    if (leer_empleados(nombre_archivo, &leidos, &n_leidos)) {
        printf("Lectura exitosa: %d empleados\n\n", n_leidos);
        
        for (int i = 0; i < n_leidos; i++) {
            printf("ID: %d\n", leidos[i].id);
            printf("Nombre: %s\n", leidos[i].nombre);
            printf("Salario: $%.2f\n\n", leidos[i].salario);
        }
        
        free(leidos);
    } else {
        fprintf(stderr, "Error al leer\n");
        return 1;
    }
    
    return 0;
}
