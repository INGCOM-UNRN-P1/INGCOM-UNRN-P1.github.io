// TAD Pila (Stack) - Implementación con lista enlazada

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *tope;
    int tamano;
} Pila;

// Crea una pila vacía
Pila *pila_crear(void) {
    Pila *pila = malloc(sizeof(Pila));
    if (pila == NULL) {
        return NULL;
    }
    pila->tope = NULL;
    pila->tamano = 0;
    return pila;
}

// Verifica si la pila está vacía
bool pila_vacia(const Pila *pila) {
    return pila->tope == NULL;
}

// Retorna el tamaño de la pila
int pila_tamano(const Pila *pila) {
    return pila->tamano;
}

// Apila un elemento (push)
bool pila_apilar(Pila *pila, int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->tamano++;
    return true;
}

// Desapila un elemento (pop)
bool pila_desapilar(Pila *pila, int *dato) {
    if (pila_vacia(pila)) {
        return false;
    }
    
    Nodo *a_eliminar = pila->tope;
    *dato = a_eliminar->dato;
    pila->tope = pila->tope->siguiente;
    free(a_eliminar);
    pila->tamano--;
    return true;
}

// Ve el elemento en el tope sin desapilar (peek)
bool pila_tope(const Pila *pila, int *dato) {
    if (pila_vacia(pila)) {
        return false;
    }
    *dato = pila->tope->dato;
    return true;
}

// Destruye la pila
void pila_destruir(Pila *pila) {
    while (!pila_vacia(pila)) {
        int dato;
        pila_desapilar(pila, &dato);
    }
    free(pila);
}

// Imprime la pila
void pila_imprimir(const Pila *pila) {
    printf("Pila (tope -> base): ");
    Nodo *actual = pila->tope;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("(tamaño: %d)\n", pila->tamano);
}

int main(void) {
    Pila *mi_pila = pila_crear();
    if (mi_pila == NULL) {
        fprintf(stderr, "Error al crear la pila\n");
        return 1;
    }
    
    printf("Pila creada\n");
    pila_imprimir(mi_pila);
    
    // Apilar elementos
    printf("\nApilando: 10, 20, 30\n");
    pila_apilar(mi_pila, 10);
    pila_apilar(mi_pila, 20);
    pila_apilar(mi_pila, 30);
    pila_imprimir(mi_pila);
    
    // Ver el tope
    int tope;
    if (pila_tope(mi_pila, &tope)) {
        printf("\nElemento en el tope: %d\n", tope);
    }
    
    // Desapilar
    int dato;
    printf("\nDesapilando elementos:\n");
    while (pila_desapilar(mi_pila, &dato)) {
        printf("Desapilado: %d\n", dato);
        pila_imprimir(mi_pila);
    }
    
    pila_destruir(mi_pila);
    return 0;
}
