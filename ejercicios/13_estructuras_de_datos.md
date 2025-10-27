---
title: "Ejercicios: Estructuras de Datos"
short_title: "13. Estructuras de Datos"
---

## Acerca de

Estos ejercicios se enfocan en la implementación de estructuras de datos
dinámicas fundamentales utilizando punteros y `struct`. El objetivo es
comprender cómo se construyen y manipulan estas estructuras en memoria,
gestionando las relaciones entre nodos.

## 1: Lista Enlazada Simple

Una lista enlazada es una colección de nodos donde cada nodo contiene un dato y
un puntero al siguiente nodo de la secuencia.

```c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;
```

### 1.1: Crear y Destruir

- **`nodo_t* crear_nodo(int dato)`**: Reserva memoria para un nuevo nodo, le
  asigna el dato y establece su puntero `siguiente` a `NULL`.
- **`void liberar_lista(nodo_t *cabeza)`**: Recorre la lista y libera la memoria
  de cada nodo uno por uno para evitar fugas de memoria.

### 1.2: Inserción

- **`void insertar_al_principio(nodo_t **cabeza, int dato)`**: Crea un nuevo nodo y 
  lo convierte en la nueva cabeza de la lista. Requiere un puntero doble para modificar el puntero `cabeza`
  original.
- **`void insertar_al_final(nodo_t *cabeza, int dato)`**: Recorre la lista hasta
  el último nodo y enlaza el nuevo nodo al final.

### 1.3: Eliminación y Búsqueda

- **`nodo_t* buscar_nodo(nodo_t *cabeza, int dato)`**: Recorre la lista y
  devuelve un puntero al primer nodo que contenga el dato, o `NULL` si no se
  encuentra.
- **`void eliminar_por_valor(nodo_t **cabeza, int dato)`\*\*: Busca un nodo con
  el dato especificado y lo elimina de la lista, re-enlazando el nodo anterior
  con el siguiente.

## 2: Pila (Stack) - LIFO

Una pila sigue el principio LIFO (Last-In, First-Out). Se puede implementar
eficientemente usando una lista enlazada como estructura subyacente.

### 2.1: Implementación con Lista Enlazada

- **`void push(nodo_t **cabeza, int
  dato)`**: Es idéntico a `insertar_al_principio` en una lista enlazada.
- **`int pop(nodo_t **cabeza)`\*\*: Elimina el primer nodo (la cima de la pila),
  devuelve su dato y actualiza la cabeza de la lista.
- **`int peek(nodo_t *cabeza)`**: Devuelve el dato del primer nodo sin modificar
  la pila.

## 3: Cola (Queue) - FIFO

Una cola sigue el principio FIFO (First-In, First-Out). Para una implementación
eficiente con listas enlazadas, se requiere mantener punteros tanto a la cabeza
(`frente`) como a la cola (`final`) de la lista.

```c
typedef struct {
    nodo_t *frente;
    nodo_t *final;
} cola_t;
```

### 3.1: Implementación con Lista Enlazada

- **`void encolar(cola_t *cola, int dato)`**: Crea un nuevo nodo y lo añade al
  final de la lista, actualizando el puntero `final`.
- **`int desencolar(cola_t *cola)`**: Elimina el nodo del frente de la lista,
  devuelve su dato y actualiza el puntero `frente`.

## 4: Estructuras de Datos Avanzadas (Opcional)

### 4.1: Árbol de Búsqueda Binaria (BST)

Un árbol binario de búsqueda es una estructura de datos basada en nodos donde
cada nodo tiene un valor, un puntero a un sub-árbol izquierdo (con valores
menores) y un puntero a un sub-árbol derecho (con valores mayores).

- **`nodo_arbol_t* insertar_en_bst(nodo_arbol_t *raiz, int dato)`**: Función
  recursiva que encuentra la posición correcta e inserta un nuevo nodo.
- **`void imprimir_en_orden(nodo_arbol_t *raiz)`**: Recorrido recursivo
  (izquierdo, raíz, derecho) que imprime los elementos de forma ordenada.

### 4.2: Tabla Hash (Encadenamiento Separado)

Una tabla hash utiliza una función para convertir una clave en un índice de un
arreglo. Las colisiones (cuando dos claves mapean al mismo índice) se manejan
almacenando los elementos en una lista enlazada en esa posición del arreglo.

- **`unsigned int hash(char *clave)`**: Función que convierte una cadena en un
  índice.
- **`void hash_insertar(tabla_hash_t *tabla, char *clave, int valor)`**: Calcula
  el hash de la clave e inserta el par clave-valor en la lista enlazada
  correspondiente.

## 5: Lista Circular

### 5.1: Implementación Básica

Implementar una lista circular enlazada simple donde el último nodo apunta al primero.

```c
typedef struct nodo_circular {
    int dato;
    struct nodo_circular* siguiente;
} nodo_circular_t;

typedef struct {
    nodo_circular_t* ultimo;  // Puntero al último nodo
    size_t cantidad;
} lista_circular_t;
```

**Funciones a implementar:**
- `lista_circular_t* crear_lista_circular(void)`
- `bool insertar_circular(lista_circular_t* lista, int dato)`
- `bool esta_vacia_circular(const lista_circular_t* lista)`
- `void mostrar_circular(const lista_circular_t* lista)`

### 5.2: Rotar Lista Circular

Implementar una función que "rote" la lista circular moviendo el puntero del último.

```c
void rotar_circular(lista_circular_t* lista);
```

Esta operación tiene complejidad $O(1)$.

### 5.3: Problema de Josephus

Usar una lista circular para resolver el problema de Josephus: eliminar cada k-ésimo elemento hasta que quede uno solo.

```c
int josephus(int n, int k);
```

## 6: Lista Doblemente Enlazada

### 6.1: Implementación Completa

Implementar una lista doblemente enlazada con centinelas (nodos ficticios al inicio y al final).

```c
typedef struct nodo_doble {
    int dato;
    struct nodo_doble* anterior;
    struct nodo_doble* siguiente;
} nodo_doble_t;

typedef struct {
    nodo_doble_t* centinela;
    size_t cantidad;
} lista_doble_t;
```

**Ventajas:** Las operaciones en ambos extremos son $O(1)$, incluyendo eliminar el último.

### 6.2: Iterador Bidireccional

Implementar un iterador que permita recorrer la lista en ambas direcciones.

```c
typedef struct {
    nodo_doble_t* actual;
    lista_doble_t* lista;
} iterador_doble_t;

iterador_doble_t* crear_iterador(lista_doble_t* lista);
bool avanzar(iterador_doble_t* iter);
bool retroceder(iterador_doble_t* iter);
```

## 7: Deque (Double-Ended Queue)

### 7.1: Implementación con Lista Doble

Implementar un deque usando lista doblemente enlazada.

```c
typedef struct deque deque_t;

deque_t* deque_crear(void);
bool deque_insertar_primero(deque_t* d, int dato);
bool deque_insertar_ultimo(deque_t* d, int dato);
bool deque_remover_primero(deque_t* d, int* dato);
bool deque_remover_ultimo(deque_t* d, int* dato);
```

Todas las operaciones deben ser $O(1)$.

### 7.2: Aplicación - Ventana Deslizante

Usar un deque para resolver el problema del máximo en ventana deslizante.

## 8: Árbol Binario de Búsqueda (BST)

### 8.1: Operaciones Básicas

Implementar las operaciones fundamentales de un BST.

```c
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol* izq;
    struct nodo_arbol* der;
} nodo_arbol_t;

nodo_arbol_t* insertar_bst(nodo_arbol_t* raiz, int dato);
nodo_arbol_t* buscar_bst(nodo_arbol_t* raiz, int dato);
nodo_arbol_t* eliminar_bst(nodo_arbol_t* raiz, int dato);
```

### 8.2: Recorridos de Árbol

Implementar los tres recorridos estándar:

```c
void preorden(nodo_arbol_t* raiz);   // Raíz → Izq → Der
void inorden(nodo_arbol_t* raiz);    // Izq → Raíz → Der (ordenado)
void postorden(nodo_arbol_t* raiz);  // Izq → Der → Raíz
```

### 8.3: Propiedades del Árbol

Implementar funciones que calculen propiedades del árbol:

```c
int altura(nodo_arbol_t* raiz);
int cantidad_nodos(nodo_arbol_t* raiz);
bool es_balanceado(nodo_arbol_t* raiz);
```

## 9: Heap (Montículo)

### 9.1: Min-Heap con Arreglo

Implementar un min-heap usando un arreglo.

```c
typedef struct {
    int* datos;
    size_t cantidad;
    size_t capacidad;
} heap_t;

heap_t* heap_crear(size_t capacidad);
bool heap_insertar(heap_t* heap, int dato);
bool heap_extraer_min(heap_t* heap, int* dato);
```

**Relaciones en el arreglo:**
- Padre de `i`: `(i-1)/2`
- Hijo izquierdo de `i`: `2*i + 1`
- Hijo derecho de `i`: `2*i + 2`

### 9.2: Heapify y Heap Sort

Implementar la operación `heapify` para convertir un arreglo en un heap.

```c
void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);
```

## 10: Grafo con Lista de Adyacencia

### 10.1: Representación

Implementar un grafo dirigido usando listas de adyacencia.

```c
typedef struct nodo_grafo {
    int vertice;
    struct nodo_grafo* siguiente;
} nodo_grafo_t;

typedef struct {
    nodo_grafo_t** adyacencias;  // Arreglo de listas
    int num_vertices;
} grafo_t;
```

### 10.2: BFS (Recorrido en Anchura)

Implementar BFS usando una cola.

```c
void bfs(grafo_t* grafo, int inicio);
```

### 10.3: DFS (Recorrido en Profundidad)

Implementar DFS usando recursión o una pila.

```c
void dfs(grafo_t* grafo, int inicio);
```

## 11: Trie (Árbol de Prefijos)

### 11.1: Implementación Básica

Implementar un trie para almacenar palabras.

```c
typedef struct nodo_trie {
    struct nodo_trie* hijos[26];  // Solo letras minúsculas
    bool es_fin_palabra;
} nodo_trie_t;

nodo_trie_t* trie_crear(void);
void trie_insertar(nodo_trie_t* raiz, const char* palabra);
bool trie_buscar(nodo_trie_t* raiz, const char* palabra);
bool trie_tiene_prefijo(nodo_trie_t* raiz, const char* prefijo);
```

### 11.2: Autocompletado

Implementar una función que sugiera palabras dado un prefijo.

```c
void trie_autocompletar(nodo_trie_t* raiz, const char* prefijo, char*** sugerencias, int* n);
```

## 12: Set (Conjunto) con Hash

### 12.1: Implementación

Implementar un conjunto usando tabla hash abierta (open addressing).

```c
typedef struct {
    int* datos;
    bool* ocupado;
    size_t capacidad;
    size_t cantidad;
} set_t;

set_t* set_crear(size_t capacidad);
bool set_insertar(set_t* set, int dato);
bool set_pertenece(set_t* set, int dato);
bool set_eliminar(set_t* set, int dato);
```

### 12.2: Operaciones de Conjuntos

Implementar operaciones matemáticas de conjuntos:

```c
set_t* set_union(set_t* a, set_t* b);
set_t* set_interseccion(set_t* a, set_t* b);
set_t* set_diferencia(set_t* a, set_t* b);
```

## 13: Skip List

### 13.1: Implementación

Implementar una skip list para búsqueda logarítmica en lista ordenada.

```c
#define MAX_NIVEL 16

typedef struct nodo_skip {
    int dato;
    struct nodo_skip** siguiente;  // Arreglo de punteros
} nodo_skip_t;

typedef struct {
    nodo_skip_t* cabeza;
    int nivel_max_actual;
} skip_list_t;
```

**Complejidad promedio:** $O(\log n)$ para búsqueda, inserción y eliminación.

## 14: Union-Find (Disjoint Set)

### 14.1: Implementación con Compresión de Caminos

Implementar union-find para detectar ciclos o componentes conexas.

```c
typedef struct {
    int* padre;
    int* rango;
    int n;
} union_find_t;

union_find_t* uf_crear(int n);
int uf_encontrar(union_find_t* uf, int x);
void uf_unir(union_find_t* uf, int x, int y);
```

**Aplicación:** Algoritmo de Kruskal para árbol de expansión mínima.

## 15: LRU Cache

### 15.1: Implementación

Implementar una caché LRU (Least Recently Used) usando lista doble + tabla hash.

```c
typedef struct nodo_cache {
    int clave;
    int valor;
    struct nodo_cache* anterior;
    struct nodo_cache* siguiente;
} nodo_cache_t;

typedef struct {
    nodo_cache_t* cabeza;
    nodo_cache_t* cola;
    // Tabla hash para acceso O(1)
    size_t capacidad;
    size_t cantidad;
} lru_cache_t;

int lru_get(lru_cache_t* cache, int clave);
void lru_put(lru_cache_t* cache, int clave, int valor);
```

**Complejidad:** $O(1)$ para ambas operaciones.
