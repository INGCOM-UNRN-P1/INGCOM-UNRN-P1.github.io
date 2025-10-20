// TAD Secuencia - Implementación Dinámica
// Usa memoria dinámica con redimensionamiento automático

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACIDAD_INICIAL 4

typedef struct {
    int *elementos;
    int longitud;
    int capacidad;
} Secuencia;

// Crea una secuencia vacía
Secuencia *secuencia_crear(void) {
    Secuencia *sec = malloc(sizeof(Secuencia));
    if (sec == NULL) {
        return NULL;
    }
    
    sec->elementos = malloc(CAPACIDAD_INICIAL * sizeof(int));
    if (sec->elementos == NULL) {
        free(sec);
        return NULL;
    }
    
    sec->longitud = 0;
    sec->capacidad = CAPACIDAD_INICIAL;
    return sec;
}

// Destruye la secuencia
void secuencia_destruir(Secuencia *sec) {
    if (sec != NULL) {
        free(sec->elementos);
        free(sec);
    }
}

// Redimensiona la capacidad interna
static bool secuencia_redimensionar(Secuencia *sec) {
    int nueva_capacidad = sec->capacidad * 2;
    int *nuevos_elementos = realloc(sec->elementos, nueva_capacidad * sizeof(int));
    
    if (nuevos_elementos == NULL) {
        return false;
    }
    
    sec->elementos = nuevos_elementos;
    sec->capacidad = nueva_capacidad;
    return true;
}

// Agrega un elemento al final
bool secuencia_agregar(Secuencia *sec, int valor) {
    if (sec->longitud >= sec->capacidad) {
        if (!secuencia_redimensionar(sec)) {
            return false;
        }
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

// Imprime la secuencia
void secuencia_imprimir(const Secuencia *sec) {
    printf("[");
    for (int i = 0; i < sec->longitud; i++) {
        printf("%d", sec->elementos[i]);
        if (i < sec->longitud - 1) {
            printf(", ");
        }
    }
    printf("] (capacidad: %d)\n", sec->capacidad);
}

int main(void) {
    Secuencia *mi_secuencia = secuencia_crear();
    if (mi_secuencia == NULL) {
        fprintf(stderr, "Error al crear la secuencia\n");
        return 1;
    }
    
    printf("Agregando elementos (observá el redimensionamiento)...\n");
    for (int i = 1; i <= 10; i++) {
        secuencia_agregar(mi_secuencia, i * 10);
        printf("Elemento %d agregado: ", i);
        secuencia_imprimir(mi_secuencia);
    }
    
    secuencia_destruir(mi_secuencia);
    return 0;
}
