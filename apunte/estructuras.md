---
title: "Guía de Estructuras de Datos para Implementación en C"
description: "Un apunte exhaustivo sobre las estructuras de datos fundamentales (arreglos, listas, pilas, colas, árboles, tablas de hash y grafos), con algoritmos en pseudocódigo y consideraciones para su implementación en C."
---

# Guía de Estructuras de Datos para Implementación en C

Una **estructura de datos** es una forma organizada de almacenar y gestionar datos en la memoria de una computadora para que puedan ser utilizados de manera eficiente. En un lenguaje de bajo nivel como C, que no provee estas estructuras de forma nativa (a diferencia de Python o Java), comprender cómo construirlas desde cero es una habilidad fundamental.

La elección de la estructura de datos correcta es crucial y siempre implica un **trade-off**, principalmente entre:
-   **Complejidad Temporal**: Cuán rápido se ejecutan las operaciones (acceso, inserción, borrado, búsqueda).
-   **Complejidad Espacial**: Cuánta memoria adicional se necesita.

Este apunte explora las estructuras de datos más importantes, con algoritmos en pseudocódigo y notas sobre su implementación en C.

## 1. Estructuras de Datos Lineales

Los datos se organizan en una secuencia.

### Arreglos (Arrays)

-   **Concepto**: Una colección de elementos del mismo tipo almacenados en una ubicación de memoria contigua. El acceso a cualquier elemento es instantáneo si se conoce su índice.
-   **Implementación en C**:
    -   **Estáticos**: `int arr[10];`. El tamaño es fijo en tiempo de compilación.
    -   **Dinámicos (Vectores)**: Se implementan con un puntero y gestión de memoria manual (`malloc`, `realloc`, `free`). Se necesita llevar un registro del tamaño actual y la capacidad.

#### Algoritmos (Pseudocódigo)
```
// Acceso (O(1))
función acceder(arreglo A, indice i):
  retornar A[i]

// Búsqueda Lineal (O(n))
función buscar(arreglo A, tamaño n, valor x):
  para i desde 0 hasta n-1:
    si A[i] == x:
      retornar i
  retornar -1

// Inserción en Arreglo Dinámico (O(n) en promedio)
procedimiento insertar(vector V, indice i, valor x):
  si V.tamaño == V.capacidad:
    // Duplicar capacidad
    redimensionar(V, V.capacidad * 2)
  
  // Desplazar elementos a la derecha
  para j desde V.tamaño-1 hasta i:
    V.datos[j+1] = V.datos[j]
  
  V.datos[i] = x
  V.tamaño = V.tamaño + 1
```

### Listas Enlazadas (Linked Lists)
-   **Concepto**: Una colección de elementos ("nodos") donde cada uno contiene datos y un puntero al siguiente nodo de la secuencia. No requieren memoria contigua.
-   **Implementación en C**: Se usa un `struct Node` que se contiene a sí mismo a través de un puntero.
    ```c
    struct Node {
        int data;
        struct Node* next;
    };
    ```
-   **Variantes**:
    -   **Doblemente Enlazada**: Cada nodo tiene un puntero al siguiente y al anterior, facilitando el recorrido en ambas direcciones.
    -   **Circular**: El último nodo apunta al primero.



#### Algoritmos (Pseudocódigo para Lista Simplemente Enlazada)
```
// Inserción al principio (O(1))
procedimiento insertarAlPrincipio(cabeza, valor):
  nuevoNodo = crearNodo(valor)
  nuevoNodo.siguiente = cabeza
  cabeza = nuevoNodo

// Borrado (O(n) para buscar, O(1) para borrar si el nodo es conocido)
procedimiento borrar(cabeza, valor):
  si cabeza.dato == valor:
    cabeza = cabeza.siguiente
    retornar
  
  actual = cabeza
  mientras actual.siguiente != NULO y actual.siguiente.dato != valor:
    actual = actual.siguiente
  
  si actual.siguiente != NULO:
    actual.siguiente = actual.siguiente.siguiente
```

### Pilas (Stacks)
-   **Concepto**: Estructura LIFO (Last-In, First-Out). El último elemento añadido es el primero en ser eliminado.
-   **Implementación en C**: Puede construirse sobre un arreglo dinámico (muy eficiente) o una lista enlazada (más flexible).

#### Algoritmos (Pseudocódigo) - Todas las operaciones son O(1)
```
procedimiento push(pila P, valor x): // Apilar
  // Lógica para añadir al tope

función pop(pila P): // Desapilar
  // Lógica para quitar y retornar del tope

función peek(pila P): // Ver tope
  // Lógica para retornar el tope sin quitarlo
```

### Colas (Queues)
-   **Concepto**: Estructura FIFO (First-In, First-Out). El primer elemento añadido es el primero en ser eliminado.
-   **Implementación en C**: Una lista enlazada (con punteros a la cabeza y la cola) es la implementación más intuitiva. Una implementación con arreglos requiere una gestión circular para ser eficiente.

#### Algoritmos (Pseudocódigo) - Todas las operaciones son O(1)
```
procedimiento enqueue(cola Q, valor x): // Encolar
  // Lógica para añadir al final

función dequeue(cola Q): // Desencolar
  // Lógica para quitar y retornar del frente
```

## 2. Estructuras de Datos No Lineales

Los datos se organizan de forma jerárquica o en red.

### Árboles (Trees)

-   **Árbol Binario de Búsqueda (Binary Search Tree - BST)**
    -   **Concepto**: Un árbol donde cada nodo tiene como máximo dos hijos. Para cualquier nodo, todos los valores en su subárbol izquierdo son menores y todos los del subárbol derecho son mayores.
    -   **Implementación en C**: Similar a una lista enlazada, pero con dos punteros (`left` y `right`).
    -   **Complejidad**: Las operaciones son $O(\log n)$ en un árbol balanceado, pero degeneran a $O(n)$ en el peor caso (un árbol desbalanceado que parece una lista).



```{mermaid}
graph TD
    A(8) --> B(3)
    A --> C(10)
    B --> D(1)
    B --> E(6)
    C --> F(14)
    E --> G(4)
    E --> H(7)
    F --> I(13)

    style A fill:#ffcdd2,stroke:#333
    style B fill:#cde4ff,stroke:#333
    style C fill:#cde4ff,stroke:#333
    style D fill:#fff9c4,stroke:#333
    style E fill:#fff9c4,stroke:#333
    style F fill:#fff9c4,stroke:#333
    style G fill:#dcedc8,stroke:#333
    style H fill:#dcedc8,stroke:#333
    style I fill:#dcedc8,stroke:#333
```


#### Algoritmos (Pseudocódigo)
```
// Búsqueda (O(log n) en promedio)
función buscar(nodo, valor):
  si nodo == NULO o nodo.dato == valor:
    retornar nodo
  
  si valor < nodo.dato:
    retornar buscar(nodo.izquierda, valor)
  sino:
    retornar buscar(nodo.derecha, valor)

// Inserción (O(log n) en promedio)
función insertar(nodo, valor):
  si nodo == NULO:
    retornar crearNodo(valor)
  
  si valor < nodo.dato:
    nodo.izquierda = insertar(nodo.izquierda, valor)
  sino si valor > nodo.dato:
    nodo.derecha = insertar(nodo.derecha, valor)
  
  retornar nodo
```

### Tablas de Hash (Hash Tables)
-   **Concepto**: Estructura que mapea claves a valores para búsquedas de alta velocidad. Usa una **función de hash** para calcular un índice en un arreglo a partir de una clave. Las **colisiones** (cuando dos claves generan el mismo índice) son inevitables y deben gestionarse.
-   **Implementación en C**: Un arreglo de punteros. Cada puntero es la cabeza de una lista enlazada (técnica de **encadenamiento separado** para resolver colisiones).



#### Algoritmos (Pseudocódigo)
```
// Inserción (O(1) en promedio, O(n) en el peor caso)
procedimiento insertar(tabla T, clave k, valor v):
  indice = funcion_hash(k) % T.capacidad
  
  // Buscar en la lista enlazada en T[indice] si la clave ya existe
  para cada elemento en la lista T[indice]:
    si elemento.clave == k:
      elemento.valor = v // Actualizar
      retornar
  
  // Si no existe, añadir a la lista enlazada
  insertarAlPrincipio(T[indice], crearPar(k, v))
```

### Grafos (Graphs)
-   **Concepto**: Un conjunto de vértices (nodos) conectados por aristas (ejes). Pueden ser dirigidos o no dirigidos, con peso en las aristas o sin él.
-   **Implementación en C**:
    -   **Matriz de Adyacencia**: Una matriz 2D donde `M[i][j] = 1` si hay una arista entre el vértice `i` y `j`. Eficiente para grafos densos.
    -   **Lista de Adyacencia**: Un arreglo de listas enlazadas. Cada posición `A[i]` contiene una lista de los vecinos del vértice `i`. Eficiente para grafos dispersos.



[Image of a graph diagram]


#### Algoritmos (Pseudocódigo)
```
// Búsqueda en Anchura (BFS) - Usa una cola
procedimiento BFS(grafo G, nodoInicial s):
  crear una cola Q
  marcar s como visitado
  Q.encolar(s)

  mientras Q no esté vacía:
    u = Q.desencolar()
    // Procesar u
    
    para cada vecino v de u:
      si v no ha sido visitado:
        marcar v como visitado
        Q.encolar(v)

// Búsqueda en Profundidad (DFS) - Usa una pila (recursión)
procedimiento DFS(grafo G, nodoActual u):
  marcar u como visitado
  // Procesar u

  para cada vecino v de u:
    si v no ha sido visitado:
      DFS(G, v)
```