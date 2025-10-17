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
