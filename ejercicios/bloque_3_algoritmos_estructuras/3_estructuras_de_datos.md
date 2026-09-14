---
title: "Ejercicios: Estructuras de Datos"
short_title: "7. Estructuras de Datos"
---

# Ejercicios de Estructuras de Datos Lineales

## Acerca de

Estos ejercicios tienen como propósito ejercitar la construcción e
implementación concreta de estructuras de datos lineales (listas enlazadas,
pilas, colas) y no lineales (árboles binarios, tablas hash) en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-tad-pilas-colas`

### Cuestiones de Estilo Aplicables
- **Liberación recursiva o iterativa:** Al destruir una estructura que contiene
  nodos enlazados, asegurá la liberación de cada nodo de forma secuencial antes
  de perder la referencia a la cabeza.
- **Punteros dobles:** Empleá punteros dobles (`nodo_t **`) para modificar de
  forma directa la dirección física a la que apunta la cabeza de una estructura
  lineal sin retornar el nuevo puntero (ver reglas en {ref}`0x2008h`).

---

## Lista Enlazada Simple

Una lista enlazada es una colección de nodos donde cada nodo contiene un dato y
un puntero al siguiente nodo de la secuencia.

``` c
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} nodo_t;
```
<!-- c -->
(ejercicio_23_1)=
### Ejercicio 23.1 - Crear y Destruir ⭐⭐☆☆☆

- **`nodo_t* crear_nodo(int dato)`**: Reserva memoria para un nuevo nodo, le
  asigna el dato y establece su puntero `siguiente` a `NULL`.
- **`void liberar_lista(nodo_t *cabeza)`**: Recorre la lista y libera la memoria
  de cada nodo uno por uno para evitar fugas de memoria.
(ejercicio_23_2)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 23.2 - Inserción ⭐⭐☆☆☆

- **`void insertar_al_principio(nodo_t **cabeza, int dato)`**: Crea un nuevo
  nodo y lo convierte en la nueva cabeza de la lista. Requiere un puntero doble
  para modificar el puntero `cabeza` original.
- **`void insertar_al_final(nodo_t *cabeza, int dato)`**: Recorre la lista hasta
  el último nodo y enlaza el nuevo nodo al final.
(ejercicio_23_3)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 23.3 - Eliminación y Búsqueda ⭐⭐☆☆☆

- **`nodo_t* buscar_nodo(nodo_t *cabeza, int dato)`**: Recorre la lista y
  devuelve un puntero al primer nodo que contenga el dato, o `NULL` si no se
  encuentra.
- **`void eliminar_por_valor(nodo_t **cabeza, int dato)`**: Busca un nodo con el
  dato especificado y lo elimina de la lista, re-enlazando el nodo anterior con
  el siguiente.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Pila (Stack) - LIFO

Una pila sigue el principio LIFO (Last-In, First-Out). Se puede implementar
eficientemente usando una lista enlazada como estructura subyacente.
(ejercicio_23_4)=
### Ejercicio 23.4 - Implementación con Lista Enlazada ⭐⭐☆☆☆

- **`void push(nodo_t **cabeza, int dato)`**: Es idéntico a
  `insertar_al_principio` en una lista enlazada.
- **`int pop(nodo_t **cabeza)`**: Elimina el primer nodo (la cima de la pila),
  devuelve su dato y actualiza la cabeza de la lista.
- **`int peek(nodo_t *cabeza)`**: Devuelve el dato del primer nodo sin modificar
  la pila.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Cola (Queue) - FIFO

Una cola sigue el principio FIFO (First-In, First-Out). Para una implementación
eficiente con listas enlazadas, se requiere mantener punteros tanto a la cabeza
(`frente`) como a la cola (`final`) de la lista.

``` c
typedef struct
{
    nodo_t *frente;
    nodo_t *final;
} cola_t;
```
<!-- c -->
(ejercicio_23_5)=
### Ejercicio 23.5 - Implementación con Lista Enlazada ⭐⭐☆☆☆

- **`void encolar(cola_t *cola, int dato)`**: Crea un nuevo nodo y lo añade al
  final de la lista, actualizando el puntero `final`.
- **`int desencolar(cola_t *cola)`**: Elimina el nodo del frente de la lista,
  devuelve su dato y actualiza el puntero `frente`.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Estructuras de Datos Avanzadas (Opcional)
(ejercicio_23_6)=
### Ejercicio 23.6 - Árbol de Búsqueda Binaria (BST) ⭐⭐☆☆☆

Un árbol binario de búsqueda es una estructura de datos basada en nodos donde
cada nodo tiene un valor, un puntero a un sub-árbol izquierdo (con valores
menores) y un puntero a un sub-árbol derecho (con valores mayores).

- **`nodo_arbol_t* insertar_en_bst(nodo_arbol_t *raiz, int dato)`**: Función
  recursiva que encuentra la posición correcta e inserta un nuevo nodo.
- **`void imprimir_en_orden(nodo_arbol_t *raiz)`**: Recorrido recursivo
  (izquierdo, raíz, derecho) que imprime los elementos de forma ordenada.
(ejercicio_23_7)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 23.7 - Tabla Hash (Encadenamiento Separado) ⭐⭐⭐☆☆

Una tabla hash utiliza una función para convertir una clave en un índice de un
arreglo. Las colisiones (cuando dos claves mapean al mismo índice) se manejan
almacenando los elementos en una lista enlazada en esa posición del arreglo.

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

