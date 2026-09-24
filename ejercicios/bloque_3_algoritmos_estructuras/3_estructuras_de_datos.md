---
title: "Ejercicios: Estructuras de Datos"
short_title: "7. Estructuras de Datos"
---

# Ejercicios de Estructuras de Datos Lineales

## Acerca de

Estos ejercicios tienen como propósito ejercitar la construcción e
implementación concreta de estructuras de datos lineales (listas enlazadas,
pilas, colas) y no lineales (árboles binarios, tablas hash) en C11.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-tad-pilas-colas`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Punteros y aritmética básica de direcciones ({ref}`capitulo-punteros`).
2. Asignación dinámica de memoria en Heap con `malloc` y `free` ({ref}`capitulo-memoria-dinamica`).
3. Estructuras heterogéneas (`struct`) y operador de indirección `->` ({ref}`capitulo-structs`).
4. Doble indirección con punteros dobles (`nodo_t **`) para mutación de raíces o cabezas.

### Cuestiones de Estilo Aplicables
- **Liberación iterativa:** Al destruir una estructura que contiene
  nodos enlazados, asegurá la liberación de cada nodo de forma secuencial antes
  de perder la referencia a la cabeza.
- **Punteros dobles:** Empleá punteros dobles (`nodo_t **`) para modificar de
  forma directa la dirección física a la que apunta la cabeza de una estructura
  lineal sin retornar el nuevo puntero (ver reglas en {ref}`0x2008h`).

---

## Lista Enlazada Simple

Una lista enlazada es una colección de nodos donde cada nodo contiene un dato y
un puntero al siguiente nodo de la secuencia.

```c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;
```

(ej_b3_c03_01)=
### Ejercicio 3.03.01 - Crear y Destruir ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_01_nodo

Implementá las funciones primitivas para la gestión de ciclo de vida de un nodo y
una lista enlazada simple de enteros:
1. `nodo_t *crear_nodo(int dato)`: reserva memoria dinámica en el Heap para un
   nodo, asigna el valor recibido y establece el puntero `siguiente` en `NULL`.
   Retorna `NULL` si `malloc` falla.
2. `void liberar_lista(nodo_t *cabeza)`: recorre la lista completa y libera la
   memoria de cada nodo secuencialmente sin incurrir en lecturas después de
   liberar (*use-after-free*).

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada | Comportamiento Esperado |
| :--- | :--- | :--- |
| Creación estándar | `dato = 42` | Retorna puntero no nulo, `nodo->dato == 42`, `nodo->siguiente == NULL` |
| Liberación de lista vacía | `cabeza = NULL` | Retorno inmediato sin desreferenciar punteros |
| Liberación de lista con nodos | `cabeza -> 10 -> 20 -> NULL` | Todos los nodos liberados sin fuga de memoria |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

nodo_t *crear_nodo(int dato) {
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

void liberar_lista(nodo_t *cabeza) {
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        nodo_t *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main(void) {
    /* 1. Creación individual */
    nodo_t *n1 = crear_nodo(42);
    assert(n1 != NULL);
    assert(n1->dato == 42);
    assert(n1->siguiente == NULL);

    /* 2. Enlace manual de dos nodos */
    nodo_t *n2 = crear_nodo(99);
    assert(n2 != NULL);
    n1->siguiente = n2;
    assert(n1->siguiente->dato == 99);

    /* 3. Liberación de lista compuesta */
    liberar_lista(n1);

    /* 4. Liberación segura de puntero NULL */
    liberar_lista(NULL);

    return 0;
}
```
::::
:::

(ej_b3_c03_02)=
### Ejercicio 3.03.02 - Inserción al Inicio y al Final ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_02_insercion

Implementá las siguientes operaciones fundamentales de inserción sobre una lista:
1. `bool insertar_al_principio(nodo_t **cabeza, int dato)`: crea un nuevo nodo y lo
   antepone como nueva cabeza de la lista, modificando el puntero del llamador
   mediante doble indirección. Retorna `false` si falla la asignación de memoria.
2. `bool insertar_al_final(nodo_t **cabeza, int dato)`: agrega un nuevo nodo al
   extremo posterior de la lista. Si la lista está vacía, el nuevo nodo pasa a ser
   la cabeza. Retorna `false` ante fallos de memoria.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Operación | Lista Resultante |
| :--- | :--- | :--- |
| Inserción al inicio en vacía | `insertar_al_principio(&c, 10)` | `[10]` |
| Inserción al inicio repetida | `insertar_al_principio(&c, 5)` | `[5, 10]` |
| Inserción al final en existente | `insertar_al_final(&c, 20)` | `[5, 10, 20]` |
| Inserción al final en vacía | `c = NULL; insertar_al_final(&c, 1)` | `[1]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

static nodo_t *crear_nodo(int dato) {
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

static void liberar_lista(nodo_t *cabeza) {
    while (cabeza != NULL) {
        nodo_t *sig = cabeza->siguiente;
        free(cabeza);
        cabeza = sig;
    }
}

bool insertar_al_principio(nodo_t **cabeza, int dato) {
    if (cabeza == NULL) {
        return false;
    }
    nodo_t *nuevo = crear_nodo(dato);
    if (nuevo == NULL) {
        return false;
    }
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    return true;
}

bool insertar_al_final(nodo_t **cabeza, int dato) {
    if (cabeza == NULL) {
        return false;
    }
    nodo_t *nuevo = crear_nodo(dato);
    if (nuevo == NULL) {
        return false;
    }
    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return true;
    }
    nodo_t *actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    return true;
}

int main(void) {
    nodo_t *lista = NULL;

    assert(insertar_al_principio(&lista, 10));
    assert(lista != NULL && lista->dato == 10);

    assert(insertar_al_principio(&lista, 5));
    assert(lista->dato == 5 && lista->siguiente->dato == 10);

    assert(insertar_al_final(&lista, 20));
    assert(lista->siguiente->siguiente->dato == 20);
    assert(lista->siguiente->siguiente->siguiente == NULL);

    liberar_lista(lista);

    nodo_t *otra = NULL;
    assert(insertar_al_final(&otra, 100));
    assert(otra != NULL && otra->dato == 100 && otra->siguiente == NULL);
    liberar_lista(otra);

    return 0;
}
```
::::
:::

(ej_b3_c03_03)=
### Ejercicio 3.03.03 - Eliminación y Búsqueda ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_03_busqueda_elim

Implementá las operaciones de consulta y remoción por valor en listas enlazadas:
1. `nodo_t *buscar_nodo(nodo_t *cabeza, int dato)`: recorre la secuencia y retorna
   un puntero al primer nodo coincidente, o `NULL` si el valor no existe.
2. `bool eliminar_por_valor(nodo_t **cabeza, int dato)`: localiza la primera
   ocurrencia de `dato`, reconecta los enlaces adyacentes y libera la memoria del
   nodo. Retorna `true` si el elemento fue eliminado, o `false` si no se encontró.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Valor | Retorno | Lista Final |
| :--- | :--- | :--- | :--- | :--- |
| Búsqueda de elemento presente | `[10, 20, 30]` | `20` | Puntero a `20` | `[10, 20, 30]` |
| Búsqueda de elemento ausente | `[10, 20, 30]` | `99` | `NULL` | `[10, 20, 30]` |
| Eliminar cabeza | `[10, 20, 30]` | `10` | `true` | `[20, 30]` |
| Eliminar nodo intermedio | `[20, 30]` | `30` | `true` | `[20]` |
| Eliminar en lista vacía | `[]` | `5` | `false` | `[]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

static nodo_t *crear_nodo(int dato) {
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo != NULL) {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

static void liberar_lista(nodo_t *cabeza) {
    while (cabeza != NULL) {
        nodo_t *sig = cabeza->siguiente;
        free(cabeza);
        cabeza = sig;
    }
}

nodo_t *buscar_nodo(nodo_t *cabeza, int dato) {
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

bool eliminar_por_valor(nodo_t **cabeza, int dato) {
    if (cabeza == NULL || *cabeza == NULL) {
        return false;
    }

    nodo_t *actual = *cabeza;
    nodo_t *anterior = NULL;

    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        return false;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    return true;
}

int main(void) {
    nodo_t *n3 = crear_nodo(30);
    nodo_t *n2 = crear_nodo(20);
    nodo_t *n1 = crear_nodo(10);
    assert(n1 != NULL && n2 != NULL && n3 != NULL);

    n1->siguiente = n2;
    n2->siguiente = n3;
    nodo_t *lista = n1;

    /* 1. Búsquedas */
    assert(buscar_nodo(lista, 20) == n2);
    assert(buscar_nodo(lista, 99) == NULL);

    /* 2. Eliminar nodo intermedio */
    assert(eliminar_por_valor(&lista, 20));
    assert(buscar_nodo(lista, 20) == NULL);
    assert(lista->siguiente == n3);

    /* 3. Eliminar cabeza */
    assert(eliminar_por_valor(&lista, 10));
    assert(lista == n3);

    /* 4. Eliminar único nodo restante */
    assert(eliminar_por_valor(&lista, 30));
    assert(lista == NULL);

    /* 5. Eliminar en vacía */
    assert(!eliminar_por_valor(&lista, 42));

    liberar_lista(lista);
    return 0;
}
```
::::
:::

---

## Pila (Stack) - LIFO

Una pila sigue el principio LIFO (Last-In, First-Out). Se implementa de forma
óptima usando una lista enlazada como estructura subyacente.

(ej_b3_c03_04)=
### Ejercicio 3.03.04 - Pila Dinámica con Lista Enlazada ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_04_pila

Diseñá e implementá una pila dinámica basada en nodos enlazados con las
siguientes primitivas:
- `bool push(nodo_t **tope, int dato)`: inserta un nuevo valor en el tope ($O(1)$).
- `bool pop(nodo_t **tope, int *valor_extraido)`: remueve el elemento en el tope,
  asigna su valor al puntero provisto y libera el nodo. Retorna `false` si la pila
  está vacía.
- `bool peek(const nodo_t *tope, int *valor_cima)`: inspecciona el valor del tope
  sin desapilarlo. Retorna `false` si la pila está vacía.
- `void destruir_pila(nodo_t **tope)`: vacía y libera todos los nodos remanentes.

**Tabla de Vectores de Prueba:**

| Operación | Estado de Pila | Salida Retornada | Valor Extraído |
| :--- | :--- | :--- | :--- |
| `peek(&p, &v)` | Pila vacía | `false` | Inalterado |
| `push(&p, 100)` | `[100]` | `true` | - |
| `push(&p, 200)` | `[200, 100]` | `true` | - |
| `peek(p, &v)` | `[200, 100]` | `true` | `v = 200` |
| `pop(&p, &v)` | `[100]` | `true` | `v = 200` |
| `pop(&p, &v)` | `[]` | `true` | `v = 100` |
| `pop(&p, &v)` | Pila vacía | `false` | Inalterado |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

bool push(nodo_t **tope, int dato) {
    if (tope == NULL) {
        return false;
    }
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    nuevo->dato = dato;
    nuevo->siguiente = *tope;
    *tope = nuevo;
    return true;
}

bool pop(nodo_t **tope, int *valor_extraido) {
    if (tope == NULL || *tope == NULL) {
        return false;
    }
    nodo_t *nodo_a_borrar = *tope;
    if (valor_extraido != NULL) {
        *valor_extraido = nodo_a_borrar->dato;
    }
    *tope = nodo_a_borrar->siguiente;
    free(nodo_a_borrar);
    return true;
}

bool peek(const nodo_t *tope, int *valor_cima) {
    if (tope == NULL) {
        return false;
    }
    if (valor_cima != NULL) {
        *valor_cima = tope->dato;
    }
    return true;
}

void destruir_pila(nodo_t **tope) {
    if (tope == NULL) {
        return;
    }
    while (*tope != NULL) {
        int dummy;
        pop(tope, &dummy);
    }
}

int main(void) {
    nodo_t *pila = NULL;
    int v = 0;

    assert(!peek(pila, &v));
    assert(!pop(&pila, &v));

    assert(push(&pila, 100));
    assert(push(&pila, 200));

    assert(peek(pila, &v) && v == 200);
    assert(pop(&pila, &v) && v == 200);
    assert(peek(pila, &v) && v == 100);
    assert(pop(&pila, &v) && v == 100);

    assert(!pop(&pila, &v));

    /* Prueba de push múltiple y destrucción */
    assert(push(&pila, 1));
    assert(push(&pila, 2));
    assert(push(&pila, 3));
    destruir_pila(&pila);
    assert(pila == NULL);

    return 0;
}
```
::::
:::

---

## Cola (Queue) - FIFO

Una cola sigue el principio FIFO (First-In, First-Out). Mantiene punteros al
`frente` (desencolado) y al `final` (encolado) para garantizar complejidad $O(1)$.

```c
typedef struct {
    nodo_t *frente;
    nodo_t *final;
} cola_t;
```

(ej_b3_c03_05)=
### Ejercicio 3.03.05 - Cola Dinámica con Doble Puntero ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_05_cola

Implementá una cola con punteros de inicio y fin que ofrezca:
1. `cola_t *crear_cola(void)`: inicializa la cola con `frente` y `final` en `NULL`.
2. `bool encolar(cola_t *cola, int dato)`: agrega un elemento al final ($O(1)$).
3. `bool desencolar(cola_t *cola, int *valor)`: quita el nodo del frente, recupera
   su valor y libera la memoria ($O(1)$). Retorna `false` si la cola está vacía.
4. `void destruir_cola(cola_t *cola)`: desocupa todos los nodos y libera la cola.

**Tabla de Vectores de Prueba:**

| Operación | Estado Frente/Final | Retorno | Valor Extraído |
| :--- | :--- | :--- | :--- |
| Inicialización | `frente=NULL, final=NULL` | Puntero a cola | - |
| Desencolar en vacía | `cola vacia` | `false` | Inalterado |
| Encolar 10 | `[10]` | `true` | - |
| Encolar 20 | `[10, 20]` | `true` | - |
| Desencolar | `[20]` | `true` | `10` |
| Desencolar | `[]` | `true` | `20` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

typedef struct {
    nodo_t *frente;
    nodo_t *final;
} cola_t;

cola_t *crear_cola(void) {
    cola_t *c = (cola_t *)malloc(sizeof(cola_t));
    if (c == NULL) {
        return NULL;
    }
    c->frente = NULL;
    c->final = NULL;
    return c;
}

bool encolar(cola_t *cola, int dato) {
    if (cola == NULL) {
        return false;
    }
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (cola->final == NULL) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    return true;
}

bool desencolar(cola_t *cola, int *valor) {
    if (cola == NULL || cola->frente == NULL) {
        return false;
    }
    nodo_t *nodo_a_borrar = cola->frente;
    if (valor != NULL) {
        *valor = nodo_a_borrar->dato;
    }
    cola->frente = nodo_a_borrar->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(nodo_a_borrar);
    return true;
}

void destruir_cola(cola_t *cola) {
    if (cola == NULL) {
        return;
    }
    while (cola->frente != NULL) {
        int dummy;
        desencolar(cola, &dummy);
    }
    free(cola);
}

int main(void) {
    cola_t *cola = crear_cola();
    assert(cola != NULL);

    int val = 0;
    assert(!desencolar(cola, &val));

    assert(encolar(cola, 10));
    assert(encolar(cola, 20));
    assert(encolar(cola, 30));

    assert(desencolar(cola, &val) && val == 10);
    assert(desencolar(cola, &val) && val == 20);
    assert(desencolar(cola, &val) && val == 30);
    assert(!desencolar(cola, &val));

    destruir_cola(cola);
    return 0;
}
```
::::
:::

---

## Estructuras de Datos Avanzadas

(ej_b3_c03_06)=
### Ejercicio 3.03.06 - Árbol de Búsqueda Binaria (BST) ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c03_06_bst

Un árbol binario de búsqueda mantiene la propiedad de orden: para todo nodo, los
elementos del subárbol izquierdo son menores, y los del subárbol derecho son mayores.
Implementá:
1. `nodo_bst_t *bst_insertar(nodo_bst_t *raiz, int dato)`: inserta recursivamente
   un valor en la posición adecuada respetando la invariante del BST.
2. `bool bst_buscar(const nodo_bst_t *raiz, int dato)`: busca recursivamente si un
   valor está contenido en el árbol.
3. `void bst_destruir(nodo_bst_t *raiz)`: libera en post-orden todos los nodos del árbol.

**Tabla de Vectores de Prueba:**

| Operación | Estado del BST | Retorno / Invariante |
| :--- | :--- | :--- |
| Inserciones sucesivas: 50, 30, 70, 20 | Árbol con raíz 50 | Inserción sin duplicados, nodos ubicados según orden |
| `bst_buscar(raiz, 20)` | Nodos: {20, 30, 50, 70} | `true` |
| `bst_buscar(raiz, 99)` | Nodos: {20, 30, 50, 70} | `false` |
| `bst_destruir(raiz)` | Todo el árbol | Memoria liberada limpiamente |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct nodo_bst {
    int dato;
    struct nodo_bst *izq;
    struct nodo_bst *der;
} nodo_bst_t;

nodo_bst_t *bst_insertar(nodo_bst_t *raiz, int dato) {
    if (raiz == NULL) {
        nodo_bst_t *nuevo = (nodo_bst_t *)malloc(sizeof(nodo_bst_t));
        if (nuevo == NULL) {
            return NULL;
        }
        nuevo->dato = dato;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }
    if (dato < raiz->dato) {
        raiz->izq = bst_insertar(raiz->izq, dato);
    } else if (dato > raiz->dato) {
        raiz->der = bst_insertar(raiz->der, dato);
    }
    return raiz;
}

bool bst_buscar(const nodo_bst_t *raiz, int dato) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->dato == dato) {
        return true;
    }
    if (dato < raiz->dato) {
        return bst_buscar(raiz->izq, dato);
    }
    return bst_buscar(raiz->der, dato);
}

void bst_destruir(nodo_bst_t *raiz) {
    if (raiz == NULL) {
        return;
    }
    bst_destruir(raiz->izq);
    bst_destruir(raiz->der);
    free(raiz);
}

int main(void) {
    nodo_bst_t *raiz = NULL;

    assert(!bst_buscar(raiz, 50));

    raiz = bst_insertar(raiz, 50);
    raiz = bst_insertar(raiz, 30);
    raiz = bst_insertar(raiz, 70);
    raiz = bst_insertar(raiz, 20);

    assert(bst_buscar(raiz, 50));
    assert(bst_buscar(raiz, 30));
    assert(bst_buscar(raiz, 70));
    assert(bst_buscar(raiz, 20));
    assert(!bst_buscar(raiz, 100));

    bst_destruir(raiz);
    return 0;
}
```
::::
:::

(ej_b3_c03_07)=
### Ejercicio 3.03.07 - Tabla Hash con Encadenamiento Separado ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c03_07_hash

Implementá una tabla hash de tamaño fijo con encadenamiento mediante listas
enlazadas simples para resolver colisiones:
1. `size_t hash_djb2(const char *str, size_t capacidad)`: función hash determinística.
2. `bool hash_insertar(nodo_hash_t **tabla, size_t capacidad, const char *clave, int valor)`:
   inserta un nuevo par o actualiza el valor si la clave ya existe.
3. `bool hash_buscar(nodo_hash_t *const *tabla, size_t capacidad, const char *clave, int *valor_hallado)`:
   localiza una clave y recupera su entero asociado.
4. `void hash_destruir(nodo_hash_t **tabla, size_t capacidad)`: libera todos los
   nodos de todas las cubetas (*buckets*).

**Tabla de Vectores de Prueba:**

| Clave | Valor | Operación | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| `"alfa"` | `100` | Inserción | Retorna `true`, almacenado |
| `"beta"` | `200` | Inserción | Retorna `true`, almacenado |
| `"alfa"` | - | Búsqueda | Hallado, `*valor == 100` |
| `"gamma"` | - | Búsqueda | No hallado, retorna `false` |
| `"alfa"` | `999` | Actualización | Retorna `true`, nuevo valor `999` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define CAPACIDAD_TABLA 16

typedef struct nodo_hash {
    char clave[32];
    int valor;
    struct nodo_hash *siguiente;
} nodo_hash_t;

size_t hash_djb2(const char *str, size_t capacidad) {
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++) != 0) {
        hash = ((hash << 5) + hash) + (unsigned long)c;
    }
    return (size_t)(hash % capacidad);
}

bool hash_insertar(nodo_hash_t **tabla, size_t capacidad, const char *clave, int valor) {
    if (tabla == NULL || clave == NULL || capacidad == 0) {
        return false;
    }
    size_t idx = hash_djb2(clave, capacidad);
    nodo_hash_t *actual = tabla[idx];

    /* Si la clave ya existe, actualizamos su valor */
    while (actual != NULL) {
        if (strcmp(actual->clave, clave) == 0) {
            actual->valor = valor;
            return true;
        }
        actual = actual->siguiente;
    }

    /* Inserción al inicio de la cubeta */
    nodo_hash_t *nuevo = (nodo_hash_t *)malloc(sizeof(nodo_hash_t));
    if (nuevo == NULL) {
        return false;
    }
    strncpy(nuevo->clave, clave, sizeof(nuevo->clave) - 1);
    nuevo->clave[sizeof(nuevo->clave) - 1] = '\0';
    nuevo->valor = valor;
    nuevo->siguiente = tabla[idx];
    tabla[idx] = nuevo;
    return true;
}

bool hash_buscar(nodo_hash_t *const *tabla, size_t capacidad, const char *clave, int *valor_hallado) {
    if (tabla == NULL || clave == NULL || capacidad == 0) {
        return false;
    }
    size_t idx = hash_djb2(clave, capacidad);
    nodo_hash_t *actual = tabla[idx];
    while (actual != NULL) {
        if (strcmp(actual->clave, clave) == 0) {
            if (valor_hallado != NULL) {
                *valor_hallado = actual->valor;
            }
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void hash_destruir(nodo_hash_t **tabla, size_t capacidad) {
    if (tabla == NULL) {
        return;
    }
    for (size_t i = 0; i < capacidad; ++i) {
        nodo_hash_t *actual = tabla[i];
        while (actual != NULL) {
            nodo_hash_t *sig = actual->siguiente;
            free(actual);
            actual = sig;
        }
        tabla[i] = NULL;
    }
}

int main(void) {
    nodo_hash_t *tabla[CAPACIDAD_TABLA] = {NULL};
    int val = 0;

    assert(!hash_buscar(tabla, CAPACIDAD_TABLA, "alfa", &val));

    assert(hash_insertar(tabla, CAPACIDAD_TABLA, "alfa", 100));
    assert(hash_insertar(tabla, CAPACIDAD_TABLA, "beta", 200));

    assert(hash_buscar(tabla, CAPACIDAD_TABLA, "alfa", &val) && val == 100);
    assert(hash_buscar(tabla, CAPACIDAD_TABLA, "beta", &val) && val == 200);
    assert(!hash_buscar(tabla, CAPACIDAD_TABLA, "gamma", &val));

    /* Actualización de clave existente */
    assert(hash_insertar(tabla, CAPACIDAD_TABLA, "alfa", 999));
    assert(hash_buscar(tabla, CAPACIDAD_TABLA, "alfa", &val) && val == 999);

    hash_destruir(tabla, CAPACIDAD_TABLA);
    return 0;
}
```
::::
:::
