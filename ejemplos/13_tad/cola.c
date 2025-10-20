// TAD Cola (Queue) - Implementación con lista enlazada

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *frente;
    Nodo *final;
    int tamano;
} Cola;

// Crea una cola vacía
Cola *cola_crear(void) {
    Cola *cola = malloc(sizeof(Cola));
    if (cola == NULL) {
        return NULL;
    }
    cola->frente = NULL;
    cola->final = NULL;
    cola->tamano = 0;
    return cola;
}

// Verifica si la cola está vacía
bool cola_vacia(const Cola *cola) {
    return cola->frente == NULL;
}

// Retorna el tamaño de la cola
int cola_tamano(const Cola *cola) {
    return cola->tamano;
}

// Encola un elemento (enqueue)
bool cola_encolar(Cola *cola, int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (cola_vacia(cola)) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    
    cola->tamano++;
    return true;
}

// Desencola un elemento (dequeue)
bool cola_desencolar(Cola *cola, int *dato) {
    if (cola_vacia(cola)) {
        return false;
    }
    
    Nodo *a_eliminar = cola->frente;
    *dato = a_eliminar->dato;
    cola->frente = cola->frente->siguiente;
    
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(a_eliminar);
    cola->tamano--;
    return true;
}

// Ve el elemento al frente sin desencolar (peek)
bool cola_frente(const Cola *cola, int *dato) {
    if (cola_vacia(cola)) {
        return false;
    }
    *dato = cola->frente->dato;
    return true;
}

// Destruye la cola
void cola_destruir(Cola *cola) {
    while (!cola_vacia(cola)) {
        int dato;
        cola_desencolar(cola, &dato);
    }
    free(cola);
}

// Imprime la cola
void cola_imprimir(const Cola *cola) {
    printf("Cola (frente -> final): ");
    Nodo *actual = cola->frente;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("(tamaño: %d)\n", cola->tamano);
}

int main(void) {
    Cola *mi_cola = cola_crear();
    if (mi_cola == NULL) {
        fprintf(stderr, "Error al crear la cola\n");
        return 1;
    }
    
    printf("Cola creada\n");
    cola_imprimir(mi_cola);
    
    // Encolar elementos
    printf("\nEncolando: 10, 20, 30\n");
    cola_encolar(mi_cola, 10);
    cola_encolar(mi_cola, 20);
    cola_encolar(mi_cola, 30);
    cola_imprimir(mi_cola);
    
    // Ver el frente
    int frente;
    if (cola_frente(mi_cola, &frente)) {
        printf("\nElemento al frente: %d\n", frente);
    }
    
    // Desencolar
    printf("\nDesencolando elementos:\n");
    int dato;
    while (cola_desencolar(mi_cola, &dato)) {
        printf("Desencolado: %d\n", dato);
        cola_imprimir(mi_cola);
    }
    
    cola_destruir(mi_cola);
    return 0;
}
