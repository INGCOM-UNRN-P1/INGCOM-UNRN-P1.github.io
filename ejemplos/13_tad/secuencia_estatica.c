// TAD Secuencia - Implementación Estática
// Usa un arreglo de tamaño fijo

#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACIDAD 100

typedef struct {
    int elementos[MAX_CAPACIDAD];
    int longitud;
} Secuencia;

// Crea una secuencia vacía
void secuencia_crear(Secuencia *sec) {
    sec->longitud = 0;
}

// Retorna la longitud actual
int secuencia_longitud(const Secuencia *sec) {
    return sec->longitud;
}

// Verifica si está llena
bool secuencia_llena(const Secuencia *sec) {
    return sec->longitud >= MAX_CAPACIDAD;
}

// Agrega un elemento al final
bool secuencia_agregar(Secuencia *sec, int valor) {
    if (secuencia_llena(sec)) {
        return false;
    }
    sec->elementos[sec->longitud] = valor;
    sec->longitud++;
    return true;
}

// Obtiene un elemento por índice
bool secuencia_obtener(const Secuencia *sec, int indice, int *valor) {
    if (indice < 0 || indice >= sec->longitud) {
        return false;
    }
    *valor = sec->elementos[indice];
    return true;
}

// Modifica un elemento por índice
bool secuencia_modificar(Secuencia *sec, int indice, int valor) {
    if (indice < 0 || indice >= sec->longitud) {
        return false;
    }
    sec->elementos[indice] = valor;
    return true;
}

// Imprime la secuencia
void secuencia_imprimir(const Secuencia *sec) {
    printf("[");
    for (int i = 0; i < sec->longitud; i++) {
        printf("%d", sec->elementos[i]);
        if (i < sec->longitud - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    Secuencia mi_secuencia;
    secuencia_crear(&mi_secuencia);
    
    printf("Agregando elementos...\n");
    secuencia_agregar(&mi_secuencia, 10);
    secuencia_agregar(&mi_secuencia, 20);
    secuencia_agregar(&mi_secuencia, 30);
    
    printf("Secuencia: ");
    secuencia_imprimir(&mi_secuencia);
    
    printf("Longitud: %d\n", secuencia_longitud(&mi_secuencia));
    
    int valor;
    if (secuencia_obtener(&mi_secuencia, 1, &valor)) {
        printf("Elemento en índice 1: %d\n", valor);
    }
    
    secuencia_modificar(&mi_secuencia, 1, 200);
    printf("Después de modificar índice 1: ");
    secuencia_imprimir(&mi_secuencia);
    
    return 0;
}
