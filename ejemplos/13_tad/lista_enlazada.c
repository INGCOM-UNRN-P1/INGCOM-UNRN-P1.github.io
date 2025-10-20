// TAD Lista Enlazada Simple
// Estructura de datos dinámica básica

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Nodo de la lista
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Lista enlazada
typedef struct {
    Nodo *cabeza;
    int longitud;
} Lista;

// Crea una lista vacía
Lista *lista_crear(void) {
    Lista *lista = malloc(sizeof(Lista));
    if (lista == NULL) {
        return NULL;
    }
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

// Agrega un elemento al inicio
bool lista_agregar_inicio(Lista *lista, int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = lista->cabeza;
    lista->cabeza = nuevo;
    lista->longitud++;
    return true;
}

// Agrega un elemento al final
bool lista_agregar_final(Lista *lista, int dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (lista->cabeza == NULL) {
        lista->cabeza = nuevo;
    } else {
        Nodo *actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    
    lista->longitud++;
    return true;
}

// Elimina el primer elemento
bool lista_eliminar_inicio(Lista *lista) {
    if (lista->cabeza == NULL) {
        return false;
    }
    
    Nodo *a_eliminar = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;
    free(a_eliminar);
    lista->longitud--;
    return true;
}

// Imprime la lista
void lista_imprimir(const Lista *lista) {
    Nodo *actual = lista->cabeza;
    printf("[");
    while (actual != NULL) {
        printf("%d", actual->dato);
        if (actual->siguiente != NULL) {
            printf(" -> ");
        }
        actual = actual->siguiente;
    }
    printf("] (longitud: %d)\n", lista->longitud);
}

// Destruye la lista completa
void lista_destruir(Lista *lista) {
    while (lista->cabeza != NULL) {
        lista_eliminar_inicio(lista);
    }
    free(lista);
}

int main(void) {
    Lista *mi_lista = lista_crear();
    if (mi_lista == NULL) {
        fprintf(stderr, "Error al crear la lista\n");
        return 1;
    }
    
    printf("Agregando al inicio: 30, 20, 10\n");
    lista_agregar_inicio(mi_lista, 30);
    lista_agregar_inicio(mi_lista, 20);
    lista_agregar_inicio(mi_lista, 10);
    lista_imprimir(mi_lista);
    
    printf("\nAgregando al final: 40, 50\n");
    lista_agregar_final(mi_lista, 40);
    lista_agregar_final(mi_lista, 50);
    lista_imprimir(mi_lista);
    
    printf("\nEliminando el primero\n");
    lista_eliminar_inicio(mi_lista);
    lista_imprimir(mi_lista);
    
    lista_destruir(mi_lista);
    return 0;
}
