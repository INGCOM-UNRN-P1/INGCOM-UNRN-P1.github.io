---
title: "Introducción a las Estructuras de Datos"
short_title: "Estructuras de Datos"
subtitle: "Organizando la información para resolver problemas eficientemente."
---

## ¿Qué es una Estructura de Datos?

Una **estructura de datos** es una forma particular de organizar, gestionar y almacenar datos en la memoria de una computadora para que puedan ser accedidos y modificados de manera eficiente. No se trata solo de guardar datos, sino de establecer relaciones lógicas entre ellos, lo que facilita el diseño de algoritmos complejos.

La elección de la estructura de datos correcta es una de las decisiones más críticas en el diseño de software. Esta elección siempre implica un **trade-off**, un balance entre distintos factores, principalmente:

-   **Complejidad Temporal**: ¿Cuán rápido se ejecutan las operaciones (acceso, inserción, borrado, búsqueda)?
-   **Complejidad Espacial**: ¿Cuánta memoria se necesita para almacenar la estructura?

En un lenguaje de bajo nivel como C, que no provee estas estructuras de forma nativa (a diferencia de Python o Java), comprender cómo construirlas desde cero es una habilidad fundamental.

### TAD vs. Estructura de Datos

Es crucial diferenciar entre un Tipo de Dato Abstracto (TAD) y una Estructura de Datos:

-   **TAD**: Es un modelo matemático, una **especificación** de comportamiento. Define un conjunto de valores y un conjunto de operaciones (el "qué"), pero no dice nada sobre cómo se implementa.
-   **Estructura de Datos**: Es una **implementación** concreta de un TAD. Es la organización física y lógica de los datos en memoria (el "cómo").

Por ejemplo, una **Pila** es un TAD con operaciones `push` y `pop`. Se puede implementar con distintas estructuras de datos, como un arreglo o una lista enlazada.

## Clasificación de Estructuras de Datos

Las estructuras de datos se pueden clasificar de varias maneras, pero una de las más comunes es según su organización:

1.  **Lineales**: Los elementos se organizan en una secuencia. Cada elemento tiene un predecesor y un sucesor (excepto el primero y el último).
2.  **No Lineales**: Los elementos se organizan de forma jerárquica o en red. Un elemento puede estar conectado a varios otros.

## 1. Estructuras de Datos Lineales

### Arreglos (Arrays)

-   **Concepto**: Una colección de elementos del mismo tipo almacenados en una **ubicación de memoria contigua**. Esta contigüidad es su mayor fortaleza y debilidad.
-   **Trade-offs**:
    -   **Ventaja**: Acceso a elementos por índice en tiempo constante, $O(1)$, porque la dirección de `A[i]` se puede calcular directamente como `direccion_base + i * tamaño_del_elemento`.
    -   **Desventaja**: La inserción y el borrado de elementos son lentos, $O(n)$, porque requieren desplazar todos los elementos subsiguientes.
-   **Alineación con C**: En C, los arreglos son la estructura más fundamental. Los **arreglos estáticos** (`int arr[10];`) tienen un tamaño fijo en tiempo de compilación. Para flexibilidad, se implementan **arreglos dinámicos** (vectores) con un puntero y gestión manual de memoria (`malloc`, `realloc`, `free`), manteniendo un registro separado para el tamaño y la capacidad.

#### Algoritmos Clave (Pseudocódigo)

```
// Inserción en un arreglo (O(n))
procedimiento insertar(arreglo A, tamaño n, capacidad cap, indice i, valor x):
  si n >= cap:
    retornar ERROR // No hay espacio
  
  // Desplazar elementos a la derecha
  para j desde n-1 hasta i:
    A[j+1] = A[j]
  
  A[i] = x
  n = n + 1

// Búsqueda Binaria (O(log n)) - ¡Requiere un arreglo ordenado!
función busquedaBinaria(arreglo A, tamaño n, valor x):
  bajo = 0, alto = n - 1
  mientras bajo <= alto:
    medio = bajo + (alto - bajo) / 2
    si A[medio] == x:
      retornar medio
    si A[medio] < x:
      bajo = medio + 1
    sino:
      alto = medio - 1
  retornar -1 // No encontrado
```

### Listas Enlazadas (Linked Lists)

-   **Concepto**: Una colección de "nodos" donde cada uno contiene datos y un **puntero** al siguiente nodo de la secuencia. A diferencia de los arreglos, los nodos no están necesariamente en ubicaciones de memoria contiguas, lo que les da gran flexibilidad en tamaño.

    ```{mermaid}
    graph LR
        A[Dato|*sig] --> B(Dato|*sig);
        B --> C(Dato|NULL);
    ```

-   **Trade-offs**:
    -   **Ventaja**: Inserción y borrado en tiempo constante, $O(1)$, si se tiene un puntero al nodo relevante (ej. la cabeza de la lista o el nodo anterior al de la operación).
    -   **Desventaja**: Acceso y búsqueda son lentos, $O(n)$, ya que se debe recorrer la lista desde el principio. Tienen una sobrecarga de memoria por cada puntero almacenado.
-   **Alineación con C**: Se implementan de forma natural con `struct` para los nodos. Cada `struct` contiene los datos y un puntero a otro `struct` del mismo tipo.

    ```c
    struct Nodo {
        int dato;
        struct Nodo* siguiente;
    };
    ```
-   **Variantes**:
    -   **Doblemente Enlazada**: Cada nodo tiene un puntero al siguiente (`siguiente`) y al anterior (`previo`). Facilita el recorrido en ambas direcciones y el borrado de un nodo en $O(1)$ si se tiene un puntero a él.
    -   **Circular**: El último nodo apunta al primero, útil para estructuras rotativas como un carrusel de turnos.

#### Algoritmos Clave (Pseudocódigo)

```
// Recorrido de la lista (O(n))
procedimiento recorrer(cabeza):
  actual = cabeza
  mientras actual != NULO:
    procesar(actual.dato)
    actual = actual.siguiente

// Inserción en una posición específica (O(n))
procedimiento insertarEnPosicion(cabeza, valor, pos):
  si pos == 0:
    insertarAlPrincipio(cabeza, valor)
    retornar
  
  nuevoNodo = crearNodo(valor)
  actual = cabeza
  para i desde 0 hasta pos-2:
    si actual == NULO: retornar ERROR_POS_INVALIDA
    actual = actual.siguiente
  
  si actual != NULO:
    nuevoNodo.siguiente = actual.siguiente
    actual.siguiente = nuevoNodo
```

### Pilas (Stacks)

-   **Concepto**: Estructura **LIFO (Last-In, First-Out)**. El último elemento añadido es el primero en ser eliminado. Es como una pila de platos. Sus aplicaciones son cruciales en computación, como la gestión del **Call Stack** para llamadas a funciones, la evaluación de expresiones matemáticas (notación polaca inversa) y algoritmos de backtracking (como la salida de un laberinto).
-   **Alineación con C**: Puede implementarse de dos formas principales:
    1.  **Sobre un arreglo dinámico**: Muy rápido y eficiente en uso de memoria (buena localidad de caché). Las operaciones `push` y `pop` simplemente modifican un índice `tope`. Su desventaja es que puede requerir una costosa operación de `realloc` si se llena.
    2.  **Sobre una lista enlazada**: Más flexible, ya que su tamaño solo está limitado por la memoria disponible. Las operaciones `push` y `pop` se implementan como inserciones y borrados en la cabeza de la lista, siendo ambas $O(1)$.

#### Algoritmos Clave (Pseudocódigo) - Todas las operaciones son $O(1)$

```
// Implementación con Arreglo
procedimiento push_arreglo(pila P, valor x):
  si P.tope == P.capacidad - 1: redimensionar(P)
  P.tope = P.tope + 1
  P.datos[P.tope] = x

función pop_arreglo(pila P):
  si P.tope == -1: retornar ERROR_VACIA
  valor = P.datos[P.tope]
  P.tope = P.tope - 1
  retornar valor

// Implementación con Lista Enlazada
procedimiento push_lista(pila P, valor x):
  nuevoNodo = crearNodo(valor)
  nuevoNodo.siguiente = P.cabeza
  P.cabeza = nuevoNodo

función pop_lista(pila P):
  si P.cabeza == NULO: retornar ERROR_VACIA
  nodo_a_borrar = P.cabeza
  valor = nodo_a_borrar.dato
  P.cabeza = P.cabeza.siguiente
  liberar(nodo_a_borrar)
  retornar valor
```

### Colas (Queues)

-   **Concepto**: Estructura **FIFO (First-In, First-Out)**. El primer elemento añadido es el primero en ser eliminado. Como una fila en el supermercado. Se usan en planificadores de tareas (schedulers), búferes de red, sistemas de impresión y algoritmos de recorrido de grafos como BFS.
-   **Alineación con C**:
    1.  **Sobre una Lista Enlazada**: Es la implementación más intuitiva. Se necesitan punteros tanto al `frente` (cabeza) como al `final` (cola) de la lista para que tanto `enqueue` (añadir al final) como `dequeue` (quitar del frente) sean operaciones $O(1)$.
    2.  **Sobre un Arreglo Circular**: Una implementación con un arreglo simple es ineficiente, ya que al desencolar, habría que desplazar todos los elementos ($O(n)$). La solución es un **arreglo circular**, que usa dos índices (`frente` y `final`) que se mueven y "envuelven" al llegar al final del arreglo usando el operador módulo (`%`). Esto hace que ambas operaciones sean $O(1)$.

#### Algoritmos Clave (Pseudocódigo) - Todas $O(1)$

```
// Implementación con Lista Enlazada
procedimiento enqueue_lista(cola Q, valor x):
  nuevoNodo = crearNodo(valor)
  si Q.final != NULO:
    Q.final.siguiente = nuevoNodo
  Q.final = nuevoNodo
  si Q.frente == NULO:
    Q.frente = nuevoNodo

función dequeue_lista(cola Q):
  si Q.frente == NULO: retornar ERROR_VACIA
  nodo_a_borrar = Q.frente
  valor = nodo_a_borrar.dato
  Q.frente = Q.frente.siguiente
  si Q.frente == NULO:
    Q.final = NULO
  liberar(nodo_a_borrar)
  retornar valor

// Implementación con Arreglo Circular
procedimiento enqueue_arreglo(cola Q, valor x):
  si (Q.final + 1) % Q.capacidad == Q.frente: retornar ERROR_LLENA
  Q.datos[Q.final] = x
  Q.final = (Q.final + 1) % Q.capacidad

función dequeue_arreglo(cola Q):
  si Q.frente == Q.final: retornar ERROR_VACIA
  valor = Q.datos[Q.frente]
  Q.frente = (Q.frente + 1) % Q.capacidad
  retornar valor
```

## 2. Estructuras de Datos No Lineales

### Árboles (Trees)

#### Árbol Binario de Búsqueda (Binary Search Tree - BST)

-   **Concepto**: Un árbol binario donde cada nodo tiene como máximo dos hijos. Cumple la propiedad de BST: para cualquier nodo, todos los valores en su subárbol izquierdo son **menores** y todos los del subárbol derecho son **mayores**. Esto permite búsquedas muy eficientes.
-   **Alineación con C**: Se implementa con un `struct` para el nodo que contiene los datos y dos punteros: `izquierda` y `derecha`.
-   **Complejidad**: Las operaciones son $O(\log n)$ en un árbol balanceado, pero degeneran a $O(n)$ en el peor caso (un árbol que parece una lista enlazada).

#### Algoritmos Clave (Pseudocódigo)

```
// Recorrido In-Order (imprime los elementos en orden)
procedimiento inOrder(nodo):
  si nodo == NULO: retornar
  inOrder(nodo.izquierda)
  procesar(nodo.dato)
  inOrder(nodo.derecha)

// Borrado de un nodo (el algoritmo más complejo de un BST)
función borrar(nodo, valor):
  si nodo == NULO: retornar NULO

  si valor < nodo.dato:
    nodo.izquierda = borrar(nodo.izquierda, valor)
  sino si valor > nodo.dato:
    nodo.derecha = borrar(nodo.derecha, valor)
  sino: // Encontramos el nodo a borrar
    // Caso 1: Nodo sin hijos o con un solo hijo
    si nodo.izquierda == NULO:
      temp = nodo.derecha
      liberar(nodo)
      retornar temp
    sino si nodo.derecha == NULO:
      temp = nodo.izquierda
      liberar(nodo)
      retornar temp

    // Caso 2: Nodo con dos hijos
    // Encontrar el sucesor in-order (el menor del subárbol derecho)
    temp = encontrarMinimo(nodo.derecha)
    nodo.dato = temp.dato
    nodo.derecha = borrar(nodo.derecha, temp.dato)
  
  retornar nodo
```

### Tablas de Hash (Hash Tables)

-   **Concepto**: Estructura que mapea claves a valores para búsquedas de muy alta velocidad (promedio $O(1)$). Utiliza una **función de hash** para calcular un índice en un arreglo a partir de una clave. Las **colisiones** (cuando dos claves distintas generan el mismo índice) son inevitables y deben gestionarse.
-   **Alineación con C**: La técnica más común para resolver colisiones es el **encadenamiento separado**. Se implementa con un arreglo de punteros, donde cada puntero es la cabeza de una lista enlazada que almacena todos los pares clave-valor que colisionaron en ese índice.

#### Algoritmos Clave (Pseudocódigo)

```
// Búsqueda (O(1) en promedio)
función buscar(tabla T, clave k):
  indice = funcion_hash(k) % T.capacidad
  
  // Recorrer la lista enlazada en ese índice
  para cada elemento en la lista T[indice]:
    si elemento.clave == k:
      retornar elemento.valor
  
  retornar NO_ENCONTRADO
```

### Grafos (Graphs)

-   **Concepto**: Un conjunto de vértices (nodos) conectados por aristas (ejes). Son la estructura más general y pueden representar redes de todo tipo. Pueden ser **dirigidos** o **no dirigidos**, y **con peso** o **sin peso** en las aristas.
-   **Alineación con C**: Las dos representaciones más comunes son:
    1.  **Matriz de Adyacencia**: Una matriz 2D donde `M[i][j] = 1` (o el peso) si hay una arista de `i` a `j`. Rápida para verificar aristas ($O(1)$), pero consume mucha memoria ($O(V^2)$).
    2.  **Lista de Adyacencia**: Un arreglo de listas enlazadas. La posición `A[i]` contiene una lista de todos los vértices vecinos de `i`. Eficiente en memoria para grafos dispersos ($O(V+E)$).

#### Algoritmos Clave (Pseudocódigo)

```
// Búsqueda en Profundidad (DFS) - Usa una pila (recursión)
procedimiento DFS(grafo G, nodoActual u, visitados):
  marcar u como visitado
  procesar(u)

  para cada vecino v de u:
    si v no ha sido visitado:
      DFS(G, v, visitados)

// Algoritmo de Dijkstra (camino más corto desde una fuente)
función dijkstra(grafo G, nodoFuente s):
  crear cola de prioridad Q
  distancias[s] = 0
  para cada vértice v en G:
    si v != s: distancias[v] = INFINITO
    Q.agregar(v, distancias[v])

  mientras Q no esté vacía:
    u = Q.extraerMinimo()
    para cada vecino v de u:
      dist_alternativa = distancias[u] + peso(u, v)
      si dist_alternativa < distancias[v]:
        distancias[v] = dist_alternativa
        Q.actualizarPrioridad(v, dist_alternativa)
  
  retornar distancias
```

## Conclusión

Comprender las estructuras de datos es esencial para cualquier programador serio. En C, esta comprensión es aún más crítica porque el lenguaje te da el poder y la responsabilidad de implementarlas y gestionarlas manualmente. La elección correcta de una estructura de datos, basada en los trade-offs de tiempo y espacio, es a menudo la clave para transformar una solución lenta e ineficiente en una rápida y elegante.
