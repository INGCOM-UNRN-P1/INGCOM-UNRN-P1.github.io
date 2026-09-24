---
title: "Ejercicios: Tipos de Datos Abstractos"
short_title: "6. TAD"
---

# Ejercicios de Tipos de Datos Abstractos

## Acerca de

Estos ejercicios tienen como propósito dominar el diseño e implementación de
Tipos de Datos Abstractos (TAD) en C11, aplicando un encapsulamiento estricto
mediante punteros opacos y la manipulación de estructuras de datos dinámicas.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-tad`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Punteros y operadores de indirección (`*`, `->`) ({ref}`capitulo-punteros`).
2. Asignación y liberación de memoria en Heap (`malloc`, `free`) ({ref}`capitulo-memoria-dinamica`).
3. Declaración de tipos incompletos y punteros opacos en archivos de cabecera (`.h`).
4. Invariantes de representación y preservación del encapsulamiento ({ref}`capitulo-tad`).

### Cuestiones de Estilo Aplicables
- **Encapsulamiento estricto:** La estructura del nodo y de la lista debe
  definirse únicamente en el archivo de implementación `.c`, exponiendo al
  llamador solo el tipo incompleto (`typedef struct lista lista_t;`) en el `.h`
  (ver {ref}`0x3002h`).
- **Gestión de memoria:** El destructor del TAD debe encargarse de recorrer
  y liberar de forma segura cada nodo individual en el Heap antes de liberar la
  estructura de control envolvente.

---

## Lista Enlazada Simple - Operaciones Básicas

(ej_b3_c02_01)=
### Ejercicio 3.02.01 - Inserción al Inicio ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_01_insercion_inicio

Implementá la operación de insertar un elemento al principio de una lista enlazada
encapsulada en el TAD `lista_t`. La operación debe ejecutarse en tiempo $O(1)$.

```c
bool lista_insertar_inicio(lista_t *lista, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Elemento | Retorno | Lista Resultante |
| :--- | :--- | :--- | :--- | :--- |
| Inserción en vacía | `[]` | `42` | `true` | `[42]` |
| Inserciones sucesivas | `[42]` | `99` | `true` | `[99, 42]` |
| Puntero nulo | `NULL` | `10` | `false` | Inalterado |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};

typedef struct lista lista_t;

lista_t *lista_crear(void) {
    lista_t *l = (lista_t *)malloc(sizeof(lista_t));
    if (l == NULL) {
        return NULL;
    }
    l->primero = NULL;
    l->longitud = 0;
    return l;
}

void lista_destruir(lista_t *lista) {
    if (lista == NULL) {
        return;
    }
    nodo_t *act = lista->primero;
    while (act != NULL) {
        nodo_t *sig = act->siguiente;
        free(act);
        act = sig;
    }
    free(lista);
}

bool lista_insertar_inicio(lista_t *lista, int dato) {
    if (lista == NULL) {
        return false;
    }
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    nuevo->dato = dato;
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    lista->longitud++;
    return true;
}

int main(void) {
    assert(!lista_insertar_inicio(NULL, 10));

    lista_t *l = lista_crear();
    assert(l != NULL);
    assert(l->longitud == 0);

    assert(lista_insertar_inicio(l, 42));
    assert(l->longitud == 1);
    assert(l->primero->dato == 42);

    assert(lista_insertar_inicio(l, 99));
    assert(l->longitud == 2);
    assert(l->primero->dato == 99);
    assert(l->primero->siguiente->dato == 42);

    lista_destruir(l);
    return 0;
}
```
::::
:::

(ej_b3_c02_02)=
### Ejercicio 3.02.02 - Inserción al Final ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_02_insercion_final

Implementá la operación de insertar un elemento al final de la lista.

```c
bool lista_insertar_final(lista_t *lista, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Elemento | Retorno | Lista Resultante |
| :--- | :--- | :--- | :--- | :--- |
| Inserción en vacía | `[]` | `10` | `true` | `[10]` |
| Inserción al final existente | `[10]` | `20` | `true` | `[10, 20]` |
| Inserción múltiple | `[10, 20]` | `30` | `true` | `[10, 20, 30]` |

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

struct lista {
    nodo_t *primero;
    nodo_t *ultimo;
    size_t longitud;
};
typedef struct lista lista_t;

lista_t *lista_crear(void) {
    lista_t *l = (lista_t *)malloc(sizeof(lista_t));
    if (l != NULL) {
        l->primero = NULL;
        l->ultimo = NULL;
        l->longitud = 0;
    }
    return l;
}

void lista_destruir(lista_t *l) {
    if (l == NULL) return;
    nodo_t *act = l->primero;
    while (act != NULL) {
        nodo_t *sig = act->siguiente;
        free(act);
        act = sig;
    }
    free(l);
}

bool lista_insertar_final(lista_t *lista, int dato) {
    if (lista == NULL) {
        return false;
    }
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (lista->primero == NULL) {
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    } else {
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
    lista->longitud++;
    return true;
}

int main(void) {
    lista_t *l = lista_crear();
    assert(l != NULL);

    assert(lista_insertar_final(l, 10));
    assert(lista_insertar_final(l, 20));
    assert(lista_insertar_final(l, 30));

    assert(l->longitud == 3);
    assert(l->primero->dato == 10);
    assert(l->ultimo->dato == 30);

    lista_destruir(l);
    return 0;
}
```
::::
:::

(ej_b3_c02_03)=
### Ejercicio 3.02.03 - Ver Primero y Último ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_03_ver_extremos

Implementá funciones para consultar el primer y último valor de la lista sin mutarla.

```c
bool ver_primero(const lista_t *lista, int *dato);
bool ver_ultimo(const lista_t *lista, int *dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista | Función | Retorno | Salida (`*dato`) |
| :--- | :--- | :--- | :--- | :--- |
| Lista vacía | `[]` | `ver_primero` | `false` | Inalterado |
| Lista con 1 elemento | `[55]` | `ver_primero` y `ver_ultimo` | `true` | `55` en ambos |
| Lista con 3 elementos | `[10, 20, 30]` | `ver_primero` | `true` | `10` |
| Lista con 3 elementos | `[10, 20, 30]` | `ver_ultimo` | `true` | `30` |

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

struct lista {
    nodo_t *primero;
    nodo_t *ultimo;
    size_t longitud;
};
typedef struct lista lista_t;

bool ver_primero(const lista_t *lista, int *dato) {
    if (lista == NULL || lista->primero == NULL || dato == NULL) {
        return false;
    }
    *dato = lista->primero->dato;
    return true;
}

bool ver_ultimo(const lista_t *lista, int *dato) {
    if (lista == NULL || lista->ultimo == NULL || dato == NULL) {
        return false;
    }
    *dato = lista->ultimo->dato;
    return true;
}

int main(void) {
    int val = 0;
    assert(!ver_primero(NULL, &val));

    nodo_t n2 = {20, NULL};
    nodo_t n1 = {10, &n2};
    lista_t l = {&n1, &n2, 2};

    assert(ver_primero(&l, &val) && val == 10);
    assert(ver_ultimo(&l, &val) && val == 20);

    lista_t vacia = {NULL, NULL, 0};
    assert(!ver_primero(&vacia, &val));
    assert(!ver_ultimo(&vacia, &val));

    return 0;
}
```
::::
:::

(ej_b3_c02_04)=
### Ejercicio 3.02.04 - Borrar Primero ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_04_borrar_primero

Implementá la remoción del nodo frontal en tiempo $O(1)$ retornando el valor extraído.

```c
bool borrar_primero(lista_t *lista, int *dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Retorno | `*dato` | Lista Final |
| :--- | :--- | :--- | :--- | :--- |
| Lista vacía | `[]` | `false` | Inalterado | `[]` |
| Lista de 1 elemento | `[100]` | `true` | `100` | `[]` |
| Lista de varios elementos | `[1, 2, 3]` | `true` | `1` | `[2, 3]` |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

bool borrar_primero(lista_t *lista, int *dato) {
    if (lista == NULL || lista->primero == NULL) {
        return false;
    }
    nodo_t *nodo_a_eliminar = lista->primero;
    if (dato != NULL) {
        *dato = nodo_a_eliminar->dato;
    }
    lista->primero = nodo_a_eliminar->siguiente;
    lista->longitud--;
    free(nodo_a_eliminar);
    return true;
}

int main(void) {
    int extraido = 0;
    assert(!borrar_primero(NULL, &extraido));

    lista_t l = {NULL, 0};
    assert(!borrar_primero(&l, &extraido));

    nodo_t *n1 = (nodo_t *)malloc(sizeof(nodo_t));
    assert(n1 != NULL);
    n1->dato = 100;
    n1->siguiente = NULL;
    l.primero = n1;
    l.longitud = 1;

    assert(borrar_primero(&l, &extraido) && extraido == 100);
    assert(l.primero == NULL && l.longitud == 0);

    return 0;
}
```
::::
:::

---

## Lista Enlazada - Operaciones de Búsqueda

(ej_b3_c02_05)=
### Ejercicio 3.02.05 - Buscar Elemento ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_05_pertenece

Verificá la presencia de un elemento dentro de la lista en tiempo $O(n)$.

```c
bool lista_pertenece(const lista_t *lista, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista | Elemento Buscado | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| Elemento intermedio | `[5, 10, 15]` | `10` | `true` |
| Elemento inexistente | `[5, 10, 15]` | `99` | `false` |
| Lista vacía | `[]` | `5` | `false` |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

bool lista_pertenece(const lista_t *lista, int dato) {
    if (lista == NULL) {
        return false;
    }
    const nodo_t *actual = lista->primero;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

int main(void) {
    assert(!lista_pertenece(NULL, 10));

    nodo_t n3 = {15, NULL};
    nodo_t n2 = {10, &n3};
    nodo_t n1 = {5, &n2};
    lista_t l = {&n1, 3};

    assert(lista_pertenece(&l, 10));
    assert(lista_pertenece(&l, 5));
    assert(lista_pertenece(&l, 15));
    assert(!lista_pertenece(&l, 99));

    lista_t vacia = {NULL, 0};
    assert(!lista_pertenece(&vacia, 5));
    return 0;
}
```
::::
:::

(ej_b3_c02_06)=
### Ejercicio 3.02.06 - Obtener Elemento en Posición ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_06_obtener_pos

Implementá la consulta por índice (0-based) retornando `false` si el índice excede el límite.

```c
bool lista_obtener(const lista_t *lista, size_t posicion, int *dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista | Posición | Retorno | `*dato` |
| :--- | :--- | :--- | :--- | :--- |
| Índice inicial 0 | `[10, 20, 30]` | `0` | `true` | `10` |
| Índice intermedio | `[10, 20, 30]` | `1` | `true` | `20` |
| Índice fuera de rango | `[10, 20, 30]` | `5` | `false` | Inalterado |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

bool lista_obtener(const lista_t *lista, size_t posicion, int *dato) {
    if (lista == NULL || dato == NULL || posicion >= lista->longitud) {
        return false;
    }
    const nodo_t *actual = lista->primero;
    for (size_t i = 0; i < posicion; ++i) {
        if (actual == NULL) {
            return false;
        }
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        return false;
    }
    *dato = actual->dato;
    return true;
}

int main(void) {
    nodo_t n3 = {30, NULL};
    nodo_t n2 = {20, &n3};
    nodo_t n1 = {10, &n2};
    lista_t l = {&n1, 3};

    int valor = 0;
    assert(lista_obtener(&l, 0, &valor) && valor == 10);
    assert(lista_obtener(&l, 1, &valor) && valor == 20);
    assert(lista_obtener(&l, 2, &valor) && valor == 30);
    assert(!lista_obtener(&l, 3, &valor));
    assert(!lista_obtener(&l, 99, &valor));

    return 0;
}
```
::::
:::

(ej_b3_c02_07)=
### Ejercicio 3.02.07 - Contar Ocurrencias ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_07_contar

Contá cuántas veces aparece un entero dado dentro de la lista.

```c
size_t lista_contar(const lista_t *lista, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista | Elemento | Ocurrencias Esperadas |
| :--- | :--- | :--- | :--- |
| Elementos repetidos | `[7, 3, 7, 7, 2]` | `7` | `3` |
| Elemento ausente | `[1, 2, 3]` | `9` | `0` |
| Lista vacía | `[]` | `4` | `0` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

size_t lista_contar(const lista_t *lista, int dato) {
    if (lista == NULL) {
        return 0;
    }
    size_t cuenta = 0;
    const nodo_t *actual = lista->primero;
    while (actual != NULL) {
        if (actual->dato == dato) {
            cuenta++;
        }
        actual = actual->siguiente;
    }
    return cuenta;
}

int main(void) {
    assert(lista_contar(NULL, 5) == 0);

    nodo_t n5 = {2, NULL};
    nodo_t n4 = {7, &n5};
    nodo_t n3 = {7, &n4};
    nodo_t n2 = {3, &n3};
    nodo_t n1 = {7, &n2};
    lista_t l = {&n1, 5};

    assert(lista_contar(&l, 7) == 3);
    assert(lista_contar(&l, 3) == 1);
    assert(lista_contar(&l, 99) == 0);

    return 0;
}
```
::::
:::

---

## Lista Enlazada - Operaciones Avanzadas

(ej_b3_c02_08)=
### Ejercicio 3.02.08 - Insertar en Posición Arbitraria ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_08_insertar_en

Insertá un nuevo nodo en un índice arbitrario (`0 <= pos <= longitud`).

```c
bool lista_insertar_en(lista_t *lista, size_t posicion, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Posición | Dato | Lista Final |
| :--- | :--- | :--- | :--- | :--- |
| En cabeza (`pos == 0`) | `[10, 20]` | `0` | `5` | `[5, 10, 20]` |
| En medio (`pos == 1`) | `[5, 20]` | `1` | `15` | `[5, 15, 20]` |
| Al final (`pos == longitud`) | `[5, 15, 20]` | `3` | `30` | `[5, 15, 20, 30]` |
| Fuera de rango (`pos > longitud`) | `[5]` | `99` | `1` | Retorna `false` |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

bool lista_insertar_en(lista_t *lista, size_t posicion, int dato) {
    if (lista == NULL || posicion > lista->longitud) {
        return false;
    }
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    nuevo->dato = dato;

    if (posicion == 0) {
        nuevo->siguiente = lista->primero;
        lista->primero = nuevo;
    } else {
        nodo_t *ant = lista->primero;
        for (size_t i = 0; i < posicion - 1; ++i) {
            ant = ant->siguiente;
        }
        nuevo->siguiente = ant->siguiente;
        ant->siguiente = nuevo;
    }
    lista->longitud++;
    return true;
}

int main(void) {
    lista_t l = {NULL, 0};

    assert(lista_insertar_en(&l, 0, 20));
    assert(lista_insertar_en(&l, 0, 10));
    assert(lista_insertar_en(&l, 2, 30));
    assert(lista_insertar_en(&l, 1, 15));
    assert(!lista_insertar_en(&l, 10, 99));

    assert(l.longitud == 4);
    assert(l.primero->dato == 10);
    assert(l.primero->siguiente->dato == 15);
    assert(l.primero->siguiente->siguiente->dato == 20);
    assert(l.primero->siguiente->siguiente->siguiente->dato == 30);

    /* Liberación */
    nodo_t *act = l.primero;
    while (act != NULL) {
        nodo_t *sig = act->siguiente;
        free(act);
        act = sig;
    }
    return 0;
}
```
::::
:::

(ej_b3_c02_09)=
### Ejercicio 3.02.09 - Eliminar por Valor ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_09_eliminar_valor

Eliminá todas las ocurrencias del valor provisto y liberá la memoria de sus nodos.

```c
bool lista_eliminar(lista_t *lista, int dato);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Lista Inicial | Valor | Retorno | Lista Resultante |
| :--- | :--- | :--- | :--- | :--- |
| Elemento único | `[10, 20, 30]` | `20` | `true` | `[10, 30]` |
| Elementos repetidos | `[5, 5, 2, 5]` | `5` | `true` | `[2]` |
| Elemento inexistente | `[1, 2]` | `99` | `false` | `[1, 2]` |

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

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

bool lista_eliminar(lista_t *lista, int dato) {
    if (lista == NULL || lista->primero == NULL) {
        return false;
    }
    bool eliminado = false;

    /* Eliminar coincidencias en la cabeza */
    while (lista->primero != NULL && lista->primero->dato == dato) {
        nodo_t *borrar = lista->primero;
        lista->primero = borrar->siguiente;
        free(borrar);
        lista->longitud--;
        eliminado = true;
    }

    /* Eliminar coincidencias internas */
    nodo_t *actual = lista->primero;
    while (actual != NULL && actual->siguiente != NULL) {
        if (actual->siguiente->dato == dato) {
            nodo_t *borrar = actual->siguiente;
            actual->siguiente = borrar->siguiente;
            free(borrar);
            lista->longitud--;
            eliminado = true;
        } else {
            actual = actual->siguiente;
        }
    }
    return eliminado;
}

int main(void) {
    /* Lista con repetidos [5, 5, 2, 5] */
    nodo_t *n4 = (nodo_t *)malloc(sizeof(nodo_t));
    nodo_t *n3 = (nodo_t *)malloc(sizeof(nodo_t));
    nodo_t *n2 = (nodo_t *)malloc(sizeof(nodo_t));
    nodo_t *n1 = (nodo_t *)malloc(sizeof(nodo_t));
    assert(n1 && n2 && n3 && n4);

    n1->dato = 5; n1->siguiente = n2;
    n2->dato = 5; n2->siguiente = n3;
    n3->dato = 2; n3->siguiente = n4;
    n4->dato = 5; n4->siguiente = NULL;

    lista_t l = {n1, 4};
    assert(lista_eliminar(&l, 5));
    assert(l.longitud == 1);
    assert(l.primero->dato == 2);
    assert(l.primero->siguiente == NULL);

    assert(!lista_eliminar(&l, 99));

    free(l.primero);
    return 0;
}
```
::::
:::

(ej_b3_c02_10)=
### Ejercicio 3.02.10 - Invertir Lista in-place ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_10_invertir

Reordená destructivamente los punteros de los nodos de la lista para invertirla
in-place con complejidad temporal $O(n)$ y memoria auxiliar $O(1)$.

```c
void lista_invertir(lista_t *lista);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada | Salida |
| :--- | :--- | :--- |
| Lista de 3 elementos | `[1, 2, 3]` | `[3, 2, 1]` |
| Lista de 1 elemento | `[42]` | `[42]` |
| Lista vacía | `[]` | `[]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

void lista_invertir(lista_t *lista) {
    if (lista == NULL || lista->primero == NULL) {
        return;
    }
    nodo_t *prev = NULL;
    nodo_t *act = lista->primero;
    while (act != NULL) {
        nodo_t *sig = act->siguiente;
        act->siguiente = prev;
        prev = act;
        act = sig;
    }
    lista->primero = prev;
}

int main(void) {
    lista_invertir(NULL);

    nodo_t n3 = {3, NULL};
    nodo_t n2 = {2, &n3};
    nodo_t n1 = {1, &n2};
    lista_t l = {&n1, 3};

    lista_invertir(&l);
    assert(l.primero == &n3);
    assert(l.primero->siguiente == &n2);
    assert(l.primero->siguiente->siguiente == &n1);
    assert(l.primero->siguiente->siguiente->siguiente == NULL);

    return 0;
}
```
::::
:::

(ej_b3_c02_11)=
### Ejercicio 3.02.11 - Concatenar Listas ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c02_11_concatenar

Anexá todos los nodos de la lista `origen` al final de `destino`, dejando a `origen` vacía.

```c
void lista_concatenar(lista_t *destino, lista_t *origen);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Destino Inicial | Origen Inicial | Destino Final | Origen Final |
| :--- | :--- | :--- | :--- | :--- |
| Dos listas no vacías | `[1, 2]` | `[3, 4]` | `[1, 2, 3, 4]` | `[]` |
| Destino vacío | `[]` | `[10]` | `[10]` | `[]` |
| Origen vacío | `[10]` | `[]` | `[10]` | `[]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

struct lista {
    nodo_t *primero;
    size_t longitud;
};
typedef struct lista lista_t;

void lista_concatenar(lista_t *destino, lista_t *origen) {
    if (destino == NULL || origen == NULL || origen->primero == NULL) {
        return;
    }
    if (destino->primero == NULL) {
        destino->primero = origen->primero;
    } else {
        nodo_t *act = destino->primero;
        while (act->siguiente != NULL) {
            act = act->siguiente;
        }
        act->siguiente = origen->primero;
    }
    destino->longitud += origen->longitud;
    origen->primero = NULL;
    origen->longitud = 0;
}

int main(void) {
    nodo_t b2 = {4, NULL};
    nodo_t b1 = {3, &b2};
    lista_t l2 = {&b1, 2};

    nodo_t a2 = {2, NULL};
    nodo_t a1 = {1, &a2};
    lista_t l1 = {&a1, 2};

    lista_concatenar(&l1, &l2);
    assert(l1.longitud == 4);
    assert(l2.longitud == 0 && l2.primero == NULL);
    assert(l1.primero->dato == 1);
    assert(l1.primero->siguiente->dato == 2);
    assert(l1.primero->siguiente->siguiente->dato == 3);
    assert(l1.primero->siguiente->siguiente->siguiente->dato == 4);

    return 0;
}
```
::::
:::

(ej_b3_c02_12)=
### Ejercicio 3.02.12 - TAD Contador Encapsulado ⭐☆☆☆☆

:::{exercise}
:label: ej_b3_c02_12_tad_contador

Implementá un Tipo de Dato Abstracto (TAD) de un contador entero con encapsulamiento estricto:
- `contador_t *contador_crear(int valor_inicial)`: asigna dinámicamente un contador en el Heap o retorna `NULL` si falla.
- `void contador_incrementar(contador_t *c)`: incrementa el valor en 1.
- `void contador_decrementar(contador_t *c)`: decrementa el valor en 1.
- `int contador_obtener_valor(const contador_t *c)`: retorna el valor actual (o 0 si `c == NULL`).
- `void contador_destruir(contador_t *c)`: libera de forma segura la memoria del Heap.

**Tabla de Vectores de Prueba:**

| Secuencia de Operaciones | Valor Esperado | Estado de Memoria |
| :--- | :--- | :--- |
| `crear(10) -> inc() -> inc()` | `12` | Asignado en Heap |
| `dec() -> dec() -> dec()` | `9` | Asignado en Heap |
| `destruir()` | N/A | Memoria liberada |
| Operación sobre puntero nulo | `0` | Seguro ante `NULL` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct contador {
    int valor;
};
typedef struct contador contador_t;

contador_t *contador_crear(int valor_inicial) {
    contador_t *c = malloc(sizeof(contador_t));
    if (c == NULL) {
        return NULL;
    }
    c->valor = valor_inicial;
    return c;
}

void contador_incrementar(contador_t *c) {
    if (c != NULL) {
        c->valor++;
    }
}

void contador_decrementar(contador_t *c) {
    if (c != NULL) {
        c->valor--;
    }
}

int contador_obtener_valor(const contador_t *c) {
    if (c == NULL) {
        return 0;
    }
    return c->valor;
}

void contador_destruir(contador_t *c) {
    free(c);
}

int main(void) {
    contador_t *c = contador_crear(10);
    assert(c != NULL);
    assert(contador_obtener_valor(c) == 10);

    contador_incrementar(c);
    contador_incrementar(c);
    assert(contador_obtener_valor(c) == 12);

    contador_decrementar(c);
    contador_decrementar(c);
    contador_decrementar(c);
    assert(contador_obtener_valor(c) == 9);

    /* Casos con puntero nulo */
    contador_incrementar(NULL);
    contador_decrementar(NULL);
    assert(contador_obtener_valor(NULL) == 0);

    contador_destruir(c);
    contador_destruir(NULL);

    return 0;
}
```
::::
:::

(ej_b3_c02_13)=
## Ejercicio 3.02.13 - TAD Pila (Stack) ⭐⭐☆☆☆

Implementá pila con array estático de tamaño fijo:
- `pila_t *crear_pila(int capacidad)`
- `bool apilar(pila_t *p, int dato)`
- `bool desapilar(pila_t *p, int *dato)`
- `bool ver_tope(const pila_t *p, int *dato)`
- `bool esta_vacia(const pila_t *p)`
- `void destruir_pila(pila_t *p)`

**Orientación:**
- Estructura interna: `int *datos; int tope; int capacidad;`
- `apilar` verifica que no esté llena
- `desapilar` y `ver_tope` retornan `false` si está vacía

---

(ej_b3_c02_14)=
## Ejercicio 3.02.14 - TAD Cola (Queue) ⭐⭐⭐☆☆

Implementá cola FIFO con lista enlazada:
- `cola_t *crear_cola()`
- `bool encolar(cola_t *c, int dato)`
- `bool desencolar(cola_t *c, int *dato)`
- `bool ver_frente(const cola_t *c, int *dato)`
- `bool esta_vacia(const cola_t *c)`
- `size_t obtener_tamanio(const cola_t *c)`
- `void destruir_cola(cola_t *c)`

**Orientación:**
- Estructura interna: `nodo_t *primero; nodo_t *ultimo; size_t tamanio;`
- `encolar` agrega al final
- `desencolar` quita del frente

---

(ej_b3_c02_15)=
## Ejercicio 3.02.15 - TAD Lista Enlazada ⭐⭐⭐☆☆

Implementá lista enlazada simple:
- `lista_t *crear_lista()`
- `bool insertar_inicio(lista_t *l, int dato)`
- `bool insertar_final(lista_t *l, int dato)`
- `bool eliminar_primero(lista_t *l, int *dato)`
- `bool buscar(const lista_t *l, int dato)`
- `size_t obtener_largo(const lista_t *l)`
- `void destruir_lista(lista_t *l)`

**Orientación:**
- Mantené puntero a primero y último para inserción eficiente
- Mantené contador de tamaño

---

(ej_b3_c02_16)=
## Ejercicio 3.02.16 - TAD Conjunto (Set) ⭐⭐⭐⭐☆

Implementá conjunto sin elementos repetidos:
- `conjunto_t *crear_conjunto()`
- `bool agregar(conjunto_t *c, int elem)`
- `bool contiene(const conjunto_t *c, int elem)`
- `bool eliminar(conjunto_t *c, int elem)`
- `size_t obtener_cardinalidad(const conjunto_t *c)`
- `conjunto_t *union_conjuntos(const conjunto_t *a, const conjunto_t *b)`
- `conjunto_t *interseccion(const conjunto_t *a, const conjunto_t *b)`
- `void destruir_conjunto(conjunto_t *c)`

**Orientación:**
- Usá array dinámico o lista
- `agregar` solo inserta si no existe
- Operaciones de conjuntos crean nuevos conjuntos

---

(ej_b3_c02_17)=
## Ejercicio 3.02.17 - TAD Diccionario (Map) ⭐⭐⭐⭐☆

Implementá diccionario clave-valor (strings a enteros):
- `diccionario_t *crear_diccionario()`
- `bool insertar(diccionario_t *d, const char *clave, int valor)`
- `bool obtener(const diccionario_t *d, const char *clave, int *valor)`
- `bool actualizar(diccionario_t *d, const char *clave, int valor)`
- `bool eliminar(diccionario_t *d, const char *clave)`
- `bool contiene_clave(const diccionario_t *d, const char *clave)`
- `void destruir_diccionario(diccionario_t *d)`

**Orientación:**
- Array de pares `{char *clave; int valor}`
- Duplicá claves con `strdup` (o `malloc + strcpy`)
- Liberá claves al eliminar/destruir

---

(ej_b3_c02_18)=
## Ejercicio 3.02.18 - TAD Pila Genérica ⭐⭐⭐⭐☆

Pila que almacena `void *` (cualquier tipo):
- `pila_t *crear_pila()`
- `bool apilar(pila_t *p, void *dato)`
- `bool desapilar(pila_t *p, void **dato)`
- `void destruir_pila(pila_t *p, void (*destruir_dato)(void *))`

**Orientación:**
- Almacená `void *` en lugar de `int`
- Usuario pasa callback para destruir datos si son dinámicos
- Usuario responsable de castear datos al tipo correcto

---

(ej_b3_c02_19)=
## Ejercicio 3.02.19 - TAD Cola de Prioridad ⭐⭐⭐⭐⭐

Cola donde elementos con mayor prioridad salen primero:
- `cola_prioridad_t *crear_cola_prioridad()`
- `bool encolar(cola_prioridad_t *c, int dato, int prioridad)`
- `bool desencolar(cola_prioridad_t *c, int *dato)`
- `void destruir_cola_prioridad(cola_prioridad_t *c)`

**Orientación:**
- Implementá con heap binario (array)
- Mantené invariante de heap al insertar/extraer
- Prioridad mayor = sube en el heap

---

(ej_b3_c02_20)=
## Ejercicio 3.02.20 - TAD Árbol Binario de Búsqueda ⭐⭐⭐⭐⭐

ABB con operaciones estándar:
- `abb_t *crear_abb()`
- `bool insertar(abb_t *arbol, int dato)`
- `bool buscar(const abb_t *arbol, int dato)`
- `bool eliminar(abb_t *arbol, int dato)`
- `void recorrer_inorden(const abb_t *arbol, void (*visitar)(int))`
- `int altura(const abb_t *arbol)`
- `void destruir_abb(abb_t *arbol)`

**Orientación:**
- Estructura opaca oculta raíz
- Eliminación: 3 casos (sin hijos, 1 hijo, 2 hijos)
- Recorrido inorden: izquierdo, raíz, derecho

---

(ej_b3_c02_21)=
## Ejercicio 3.02.21 - TAD Grafo ⭐⭐⭐⭐⭐

Grafo dirigido con listas de adyacencia:
- `grafo_t *crear_grafo(int vertices)`
- `bool agregar_arista(grafo_t *g, int origen, int destino)`
- `bool existe_arista(const grafo_t *g, int origen, int destino)`
- `int *obtener_vecinos(const grafo_t *g, int vertice, int *cantidad)`
- `void destruir_grafo(grafo_t *g)`

**Orientación:**
- Array de listas de adyacencia
- Validá índices de vértices
- `obtener_vecinos` retorna array dinámico (caller libera)

---

(ej_b3_c02_22)=
## Ejercicio 3.02.22 - TAD Matriz Dispersa ⭐⭐⭐⭐⭐

Matriz que solo almacena elementos no cero:
- `matriz_t *crear_matriz(int filas, int cols)`
- `bool asignar(matriz_t *m, int fila, int col, double valor)`
- `double obtener(const matriz_t *m, int fila, int col)`
- `void destruir_matriz(matriz_t *m)`

**Orientación:**
- Usá hash o lista de triplas `(fila, col, valor)`
- Solo almacená valores != 0
- `obtener` retorna 0 si no está almacenado

---

(ej_b3_c02_23)=
## Ejercicio 3.02.23 - TAD Cadena Dinámica ⭐⭐⭐⭐☆

String que crece automáticamente:
- `cadena_t *crear_cadena(const char *inicial)`
- `void concatenar(cadena_t *c, const char *str)`
- `void insertar(cadena_t *c, size_t pos, const char *str)`
- `void eliminar(cadena_t *c, size_t inicio, size_t fin)`
- `const char *obtener_cstr(const cadena_t *c)`
- `size_t longitud(const cadena_t *c)`
- `void destruir_cadena(cadena_t *c)`

**Orientación:**
- Internamente: `char *datos; size_t longitud; size_t capacidad;`
- Redimensioná automáticamente con `realloc`

---

(ej_b3_c02_24)=
## Ejercicio 3.02.24 - TAD Tabla Hash ⭐⭐⭐⭐⭐

Hash table con manejo de colisiones:
- `hash_t *crear_hash(size_t tamanio_inicial)`
- `bool insertar(hash_t *h, const char *clave, void *valor)`
- `void *obtener(const hash_t *h, const char *clave)`
- `bool eliminar(hash_t *h, const char *clave)`
- `void destruir_hash(hash_t *h, void (*destruir_dato)(void *))`

**Orientación:**
- Encadenamiento para colisiones
- Redimensioná cuando factor de carga > 0.75
- Función hash: suma de caracteres módulo tamaño

---

(ej_b3_c02_25)=
## Ejercicio 3.02.25 - TAD Buffer Circular ⭐⭐⭐⭐☆

Buffer circular para comunicación productor-consumidor:
- `buffer_t *crear_buffer(size_t capacidad)`
- `bool escribir(buffer_t *b, int dato)`
- `bool leer(buffer_t *b, int *dato)`
- `bool esta_lleno(const buffer_t *b)`
- `size_t espacios_libres(const buffer_t *b)`
- `void destruir_buffer(buffer_t *b)`

**Orientación:**
- Array circular con índices `inicio` y `fin`
- Cuando `fin` alcanza `capacidad`, vuelve a 0
- Lleno cuando `(fin + 1) % capacidad == inicio`

---

(ej_b3_c02_26)=
## Ejercicio 3.02.26 - TAD Iterador ⭐⭐⭐⭐⭐

Iterador externo para lista:
- `iterador_t *crear_iterador(const lista_t *lista)`
- `bool tiene_siguiente(const iterador_t *it)`
- `int siguiente(iterador_t *it)`
- `void reiniciar(iterador_t *it)`
- `void destruir_iterador(iterador_t *it)`

**Orientación:**
- Mantené puntero al nodo actual
- `siguiente` avanza y retorna valor
- Permite recorrer sin exponer estructura interna

---

(ej_b3_c02_27)=
## Ejercicio 3.02.27 - TAD Árbol AVL ⭐⭐⭐⭐⭐

Árbol auto-balanceado:
- Misma interfaz que ABB
- Mantené balance en cada nodo
- Rotaciones para rebalancear después de insertar/eliminar

**Orientación:**
- Factor de balance = altura(izq) - altura(der)
- Balance en rango [-1, 1]
- 4 tipos de rotación: LL, RR, LR, RL

---

(ej_b3_c02_28)=
## Ejercicio 3.02.28 - TAD Heap (Min/Max) ⭐⭐⭐⭐⭐

Heap binario genérico:
- `heap_t *crear_heap(bool es_max, int (*comparar)(int, int))`
- `bool insertar(heap_t *h, int dato)`
- `bool extraer_raiz(heap_t *h, int *dato)`
- `int ver_raiz(const heap_t *h)`
- `void destruir_heap(heap_t *h)`

**Orientación:**
- Array dinámico como estructura subyacente
- `insertar`: añadir al final, subir (heapify-up)
- `extraer`: quitar raíz, poner último, bajar (heapify-down)

---

(ej_b3_c02_29)=
## Ejercicio 3.02.29 - TAD Cache LRU ⭐⭐⭐⭐⭐

Cache con política Least Recently Used:
- `cache_t *crear_cache(size_t capacidad)`
- `bool insertar(cache_t *c, const char *clave, void *valor)`
- `void *obtener(cache_t *c, const char *clave)`
- `void destruir_cache(cache_t *c, void (*destruir_dato)(void *))`

**Orientación:**
- Combina hash + lista doblemente enlazada
- `obtener` mueve elemento al frente (más reciente)
- Al insertar con capacidad llena, elimina último (menos reciente)

---

(ej_b3_c02_30)=
## Ejercicio 3.02.30 - TAD Multi-Conjunto (Bag) ⭐⭐⭐⭐⭐

Permite elementos repetidos con conteo:
- `bag_t *crear_bag()`
- `void agregar(bag_t *b, int elem, int cantidad)`
- `int obtener_cantidad(const bag_t *b, int elem)`
- `void eliminar(bag_t *b, int elem, int cantidad)`
- `void destruir_bag(bag_t *b)`

**Orientación:**
- Hash de elemento a contador
- Permite múltiples copias del mismo elemento

---

(ej_b3_c02_31)=
## Ejercicio 3.02.31 - Sistema de TADs Interconectados ⭐⭐⭐⭐⭐

Sistema completo: Biblioteca de libros usando múltiples TADs:
- `libro_t` (TAD básico)
- `biblioteca_t` (contiene conjunto de libros)
- `usuario_t` (con lista de préstamos)
- `sistema_t` (gestiona biblioteca y usuarios)

Operaciones:
- Agregar/eliminar libros
- Registrar/eliminar usuarios
- Prestar/devolver libros
- Buscar libros por título/autor
- Historial de préstamos

**Orientación:**
- Cada TAD en archivos separados
- TADs se componen entre sí
- `sistema_t` orquesta todas las operaciones
- Manejo robusto de errores

---

## Notas Finales

:::{tip} Principios de Diseño de TADs

1. **Encapsulamiento:** Ocultar detalles de implementación
2. **Interfaz mínima:** Solo exponer lo necesario
3. **Invariantes:** Mantener estructura consistente siempre
4. **Error handling:** Retornar códigos de error o usar convenciones (NULL,
   false)
5. **Documentación:** Especificar precondiciones, postcondiciones y complejidad

:::
<!-- {tip} Principios de Diseño de TADs -->

:::{note} Estructura de Archivos

```
tad/
├── pila.h          # Interfaz pública
├── pila.c          # Implementación privada
├── test_pila.c     # Pruebas unitarias
└── Makefile        # Compilación
```

Compilar:
``` bash
gcc -c pila.c -o pila.o
gcc -c test_pila.c -o test_pila.o
gcc pila.o test_pila.o -o test_pila
```
<!-- bash -->

:::
<!-- {note} Estructura de Archivos -->

Estas consignas cubren el diseño e implementación de TADs desde básicos hasta
complejos, enfatizando encapsulamiento, modularidad y reutilización.

