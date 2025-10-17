---
title: Pilas, Colas y Más Allá
short_title: 14 - Estructuras
subtitle: Estructuras lineales especializadas y panorama general
---

## Introducción

Las **pilas** y **colas** son Tipos de Datos Abstractos (TADs) que restringen el acceso a los elementos de una colección siguiendo políticas específicas. A diferencia de las secuencias generales, donde podés acceder a cualquier elemento, estas estructuras imponen reglas sobre qué elementos pueden ser accedidos y en qué orden.

Estas restricciones no son limitaciones arbitrarias, sino que reflejan patrones de uso muy comunes en programación y sistemas de computación. Al modelar explícitamente estos patrones mediante TADs especializados, el código se vuelve más claro y menos propenso a errores.

:::{important}
Tanto pilas como colas pueden implementarse usando las estructuras que ya conocemos (listas enlazadas o arreglos), demostrando nuevamente el poder de la abstracción: diferentes TADs pueden compartir implementaciones subyacentes.
:::

## Pilas (Stacks)

Una **pila** es una estructura de datos lineal que sigue el principio **LIFO** (*Last In, First Out*): el último elemento en entrar es el primero en salir. Es análogo a una pila de platos donde solo podés agregar o quitar platos desde la parte superior.

```{figure} 14/pila_stack.svg
:label: fig-pila
:align: center

Estructura de pila con operaciones push (apilar) y pop (desapilar). El acceso es únicamente por el tope.
```

### Operaciones Fundamentales

- **push(elemento):** Agrega un elemento al tope de la pila.
- **pop():** Extrae y retorna el elemento del tope.
- **peek() o top():** Retorna el elemento del tope sin extraerlo.
- **es_vacia():** Verifica si la pila está vacía.

### Implementación con Lista Enlazada

```{figure} 14/pila_lista_enlazada.svg
:label: fig-pila-lista
:align: center

Representación en memoria de una pila implementada con lista enlazada. El tope apunta al primer nodo de la lista.
```

```c
typedef struct nodo_pila
{
    int dato;
    struct nodo_pila *siguiente;
} nodo_pila_t;

typedef struct pila
{
    nodo_pila_t *tope;
    size_t tamanio;
} pila_t;
```

#### Creación de una Pila

```c
pila_t *crear_pila(void)
{
    pila_t *pila = NULL;
    
    pila = malloc(sizeof(pila_t));
    
    if (pila == NULL)
    {
        return NULL;
    }
    
    pila->tope = NULL;
    pila->tamanio = 0;
    
    return pila;
}
```

#### Apilar (Push)

```c
bool push(pila_t *pila, int dato)
{
    nodo_pila_t *nuevo = NULL;
    
    if (pila == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_pila_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->tamanio++;
    
    return true;
}
```

:::{note}
La operación `push` es idéntica a insertar al inicio en una lista enlazada. Esto es porque el tope de la pila es el primer elemento de la lista.
:::

#### Desapilar (Pop)

```c
bool pop(pila_t *pila, int *dato)
{
    nodo_pila_t *nodo_a_eliminar = NULL;
    
    if (pila == NULL || pila->tope == NULL)
    {
        return false;
    }
    
    nodo_a_eliminar = pila->tope;
    *dato = nodo_a_eliminar->dato;
    
    pila->tope = pila->tope->siguiente;
    free(nodo_a_eliminar);
    nodo_a_eliminar = NULL;
    pila->tamanio--;
    
    return true;
}
```

:::{important}
La función `pop` retorna el dato mediante un parámetro de salida (puntero) y usa el valor de retorno para indicar éxito o fracaso. Esta es una práctica común en C para manejar errores.
:::

#### Ver el Tope (Peek)

```c
bool peek(const pila_t *pila, int *dato)
{
    if (pila == NULL || pila->tope == NULL)
    {
        return false;
    }
    
    *dato = pila->tope->dato;
    
    return true;
}
```

#### Verificar si está Vacía

```c
bool es_vacia_pila(const pila_t *pila)
{
    return pila == NULL || pila->tope == NULL;
}
```

#### Destruir la Pila

```c
void destruir_pila(pila_t *pila)
{
    nodo_pila_t *siguiente = NULL;
    
    if (pila == NULL)
    {
        return;
    }
    
    while (pila->tope != NULL)
    {
        siguiente = pila->tope->siguiente;
        free(pila->tope);
        pila->tope = siguiente;
    }
    
    free(pila);
    pila = NULL;
}
```

:::{note} Patrón de Liberación
El mismo patrón de liberación que usamos en las listas se aplica aquí: guardamos el siguiente antes de liberar el actual. Este patrón es universal en estructuras enlazadas. Para profundizar en este y otros patrones de gestión de memoria, consultá {ref}`memoria-buenas-practicas`.
:::

### Aplicaciones de las Pilas

Las pilas son fundamentales en múltiples áreas de la programación:

1. **Evaluación de expresiones:** Conversión de notación infija a postfija y su evaluación.
2. **Función de llamadas:** El stack de llamadas del programa es una pila. Para entender cómo el sistema operativo usa el stack para gestionar llamadas a funciones, consultá {ref}`memoria-stack-funcionamiento`.
3. **Backtracking:** Algoritmos que exploran opciones y retroceden (laberintos, sudoku).
4. **Deshacer/Rehacer:** Editores de texto y aplicaciones gráficas.
5. **Navegación:** Historial de navegación en navegadores web.
6. **Parsing:** Análisis sintáctico de lenguajes de programación.

### Implementación Alternativa: Pila con Arreglo

Así como las secuencias pueden implementarse con arreglos, las pilas también. Esta implementación ofrece mejor localidad de caché pero requiere manejar capacidad fija o redimensionamiento.

```c
#define CAPACIDAD_INICIAL_PILA 10

typedef struct pila_arreglo
{
    int *elementos;
    size_t tope;
    size_t capacidad;
} pila_arreglo_t;
```

#### Operaciones Básicas

```c
pila_arreglo_t *crear_pila_arreglo(void)
{
    pila_arreglo_t *pila = NULL;
    
    pila = malloc(sizeof(pila_arreglo_t));
    
    if (pila == NULL)
    {
        return NULL;
    }
    
    pila->elementos = malloc(CAPACIDAD_INICIAL_PILA * sizeof(int));
    
    if (pila->elementos == NULL)
    {
        free(pila);
        return NULL;
    }
    
    pila->tope = 0;
    pila->capacidad = CAPACIDAD_INICIAL_PILA;
    
    return pila;
}

bool push_arreglo(pila_arreglo_t *pila, int dato)
{
    if (pila == NULL)
    {
        return false;
    }
    
    if (pila->tope >= pila->capacidad)
    {
        size_t nueva_capacidad = pila->capacidad * 2;
        int *nuevo_arreglo = realloc(pila->elementos, nueva_capacidad * sizeof(int));
        
        if (nuevo_arreglo == NULL)
        {
            return false;
        }
        
        pila->elementos = nuevo_arreglo;
        pila->capacidad = nueva_capacidad;
    }
    
    pila->elementos[pila->tope] = dato;
    pila->tope++;
    
    return true;
}

bool pop_arreglo(pila_arreglo_t *pila, int *dato)
{
    if (pila == NULL || pila->tope == 0)
    {
        return false;
    }
    
    pila->tope--;
    *dato = pila->elementos[pila->tope];
    
    return true;
}
```

#### Comparación: Lista vs Arreglo para Pilas

| Aspecto | Pila con Lista | Pila con Arreglo |
|---------|----------------|------------------|
| Push | $O(1)$ siempre | $O(1)$ amortizado* |
| Pop | $O(1)$ | $O(1)$ |
| Memoria | Overhead por punteros | Contigua, mejor caché |
| Redimensionamiento | No necesario | Ocasionalmente $O(n)$ |
| Localidad | Pobre (nodos dispersos) | Excelente (contiguo) |

\* $O(1)$ en promedio, pero $O(n)$ cuando se redimensiona.

:::{tip}
Para pilas donde se conoce un límite superior del tamaño, la implementación con arreglo es generalmente superior por su mejor rendimiento de caché y simplicidad.
:::

### Ejemplo: Verificación de Paréntesis Balanceados

```c
bool parentesis_balanceados(const char *expresion)
{
    pila_t *pila = NULL;
    bool balanceado = true;
    int tope = 0;
    
    pila = crear_pila();
    
    if (pila == NULL)
    {
        return false;
    }
    
    for (size_t i = 0; expresion[i] != '\0'; i++)
    {
        char c = expresion[i];
        bool coincide = false;
        
        if (c == '(' || c == '[' || c == '{')
        {
            if (!push(pila, c))
            {
                balanceado = false;
                break;
            }
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (es_vacia_pila(pila))
            {
                balanceado = false;
                break;
            }
            
            pop(pila, &tope);
            
            coincide = (c == ')' && tope == '(') ||
                      (c == ']' && tope == '[') ||
                      (c == '}' && tope == '{');
            
            if (!coincide)
            {
                balanceado = false;
                break;
            }
        }
    }
    
    if (balanceado && !es_vacia_pila(pila))
    {
        balanceado = false;
    }
    
    destruir_pila(pila);
    
    return balanceado;
}
```

## Colas (Queues)

Una **cola** es una estructura de datos lineal que sigue el principio **FIFO** (*First In, First Out*): el primer elemento en entrar es el primero en salir. Es análogo a una fila de personas esperando, donde el primero en llegar es el primero en ser atendido.

```{figure} 14/cola_queue.svg
:label: fig-cola
:align: center

Estructura de cola con operaciones encolar (inserción al final) y desencolar (extracción del frente).
```

### Operaciones Fundamentales

- **encolar(elemento):** Agrega un elemento al final de la cola.
- **desencolar():** Extrae y retorna el elemento del frente.
- **frente():** Retorna el elemento del frente sin extraerlo.
- **es_vacia():** Verifica si la cola está vacía.

### Implementación con Lista Enlazada

```{figure} 14/cola_lista_enlazada.svg
:label: fig-cola-lista
:align: center

Representación en memoria de una cola implementada con lista enlazada. Se mantienen punteros al frente y al final para operaciones O(1).
```

```c
typedef struct nodo_cola
{
    int dato;
    struct nodo_cola *siguiente;
} nodo_cola_t;

typedef struct cola
{
    nodo_cola_t *frente;
    nodo_cola_t *final;
    size_t tamanio;
} cola_t;
```

:::{note}
Mantener punteros tanto al frente como al final permite que tanto `encolar` como `desencolar` sean operaciones $O(1)$.
:::

#### Creación de una Cola

```c
cola_t *crear_cola(void)
{
    cola_t *cola = NULL;
    
    cola = malloc(sizeof(cola_t));
    
    if (cola == NULL)
    {
        return NULL;
    }
    
    cola->frente = NULL;
    cola->final = NULL;
    cola->tamanio = 0;
    
    return cola;
}
```

#### Encolar (Enqueue)

```c
bool encolar(cola_t *cola, int dato)
{
    nodo_cola_t *nuevo = NULL;
    
    if (cola == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_cola_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (cola->final == NULL)
    {
        cola->frente = nuevo;
        cola->final = nuevo;
    }
    else
    {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    
    cola->tamanio++;
    
    return true;
}
```

#### Desencolar (Dequeue)

```c
bool desencolar(cola_t *cola, int *dato)
{
    nodo_cola_t *nodo_a_eliminar = NULL;
    
    if (cola == NULL || cola->frente == NULL)
    {
        return false;
    }
    
    nodo_a_eliminar = cola->frente;
    *dato = nodo_a_eliminar->dato;
    
    cola->frente = cola->frente->siguiente;
    
    if (cola->frente == NULL)
    {
        cola->final = NULL;
    }
    
    free(nodo_a_eliminar);
    nodo_a_eliminar = NULL;
    cola->tamanio--;
    
    return true;
}
```

:::{important}
Es crucial actualizar `cola->final` a `NULL` cuando la cola queda vacía para mantener la consistencia de la estructura.
:::

#### Ver el Frente

```c
bool ver_frente(const cola_t *cola, int *dato)
{
    if (cola == NULL || cola->frente == NULL)
    {
        return false;
    }
    
    *dato = cola->frente->dato;
    return true;
}
```

#### Verificar si está Vacía

```c
bool es_vacia_cola(const cola_t *cola)
{
    return cola == NULL || cola->frente == NULL;
}
```

#### Destruir la Cola

```c
void destruir_cola(cola_t *cola)
{
    nodo_cola_t *siguiente = NULL;
    
    if (cola == NULL)
    {
        return;
    }
    
    while (cola->frente != NULL)
    {
        siguiente = cola->frente->siguiente;
        free(cola->frente);
        cola->frente = siguiente;
    }
    
    free(cola);
    cola = NULL;
}
```

### Aplicaciones de las Colas

Las colas son fundamentales en sistemas que requieren procesamiento en orden de llegada:

1. **Sistemas operativos:** Gestión de procesos (scheduling), colas de impresión.
2. **Redes:** Buffers de paquetes, enrutamiento de mensajes.
3. **Simulaciones:** Modelado de sistemas de espera (bancos, supermercados).
4. **Búsqueda en anchura (BFS):** Algoritmo de grafos para exploración nivel por nivel.
5. **Asincronía:** Colas de tareas en programación concurrente.

### Implementación Alternativa: Cola con Arreglo Circular

La implementación con arreglo circular es muy eficiente para colas, evitando el desperdicio de espacio que ocurriría con un arreglo simple.

```{figure} 14/cola_circular.svg
:label: fig-cola-circular
:align: center

Arreglo circular mostrando cómo los índices se "envuelven" usando el operador módulo. Los elementos ocupan posiciones no contiguas del arreglo.
```

```c
#define CAPACIDAD_MAXIMA 100

typedef struct cola_circular
{
    int elementos[CAPACIDAD_MAXIMA];
    int frente;
    int final;
    int tamanio;
} cola_circular_t;
```

#### Operaciones con Arreglo Circular

```c
cola_circular_t *crear_cola_circular(void)
{
    cola_circular_t *cola = NULL;
    
    cola = malloc(sizeof(cola_circular_t));
    
    if (cola == NULL)
    {
        return NULL;
    }
    
    cola->frente = 0;
    cola->final = 0;
    cola->tamanio = 0;
    
    return cola;
}

bool encolar_circular(cola_circular_t *cola, int dato)
{
    if (cola == NULL || cola->tamanio >= CAPACIDAD_MAXIMA)
    {
        return false;
    }
    
    cola->elementos[cola->final] = dato;
    cola->final = (cola->final + 1) % CAPACIDAD_MAXIMA;
    cola->tamanio++;
    
    return true;
}

bool desencolar_circular(cola_circular_t *cola, int *dato)
{
    if (cola == NULL || cola->tamanio == 0)
    {
        return false;
    }
    
    *dato = cola->elementos[cola->frente];
    cola->frente = (cola->frente + 1) % CAPACIDAD_MAXIMA;
    cola->tamanio--;
    
    return true;
}
```

:::{note} Operador Módulo para Envolvimiento

El operador módulo `%` permite que los índices "envuelvan" al inicio del arreglo cuando llegan al final, creando el comportamiento circular. Por ejemplo, si `CAPACIDAD_MAXIMA` es 10 y `final` es 9, entonces `(9 + 1) % 10 = 0`, volviendo al inicio.
:::

#### Comparación: Lista vs Arreglo para Colas

| Aspecto | Cola con Lista | Cola con Arreglo Circular |
|---------|----------------|---------------------------|
| Encolar | $O(1)$ | $O(1)$ |
| Desencolar | $O(1)$ | $O(1)$ |
| Memoria | Overhead por punteros | Sin overhead, fija |
| Capacidad | Ilimitada (heap) | Fija (predeterminada) |
| Localidad | Pobre | Excelente |
| Complejidad | Más simple | Lógica de envolvimiento |

:::{important}
La cola circular con arreglo es ideal cuando conocés el límite superior de elementos. Para colas de tamaño impredecible, la implementación con lista es más flexible.
:::

### Cola Circular con Redimensionamiento Dinámico

Para combinar lo mejor de ambos mundos, podés implementar una cola circular con arreglo dinámico que se redimensiona cuando es necesario:

```c
typedef struct cola_dinamica
{
    int *elementos;
    size_t frente;
    size_t final;
    size_t tamanio;
    size_t capacidad;
} cola_dinamica_t;
```

Esta implementación mantiene $O(1)$ amortizado en todas las operaciones y crece según la demanda, similar a como lo hace un arreglo dinámico para secuencias.

### Cola Circular Original

Una **cola circular** es una optimización que utiliza un arreglo donde el índice del final "envuelve" al inicio cuando alcanza el límite del arreglo. Esto permite reutilizar el espacio liberado por elementos desencolados.

#### Ventajas de las Colas Circulares

- Uso eficiente de memoria: no requiere desplazar elementos.
- Operaciones $O(1)$ tanto para encolar como desencolar.
- Implementación simple y predecible.

#### Desventajas de las Colas Circulares

- Capacidad fija (a menos que se implemente redimensionamiento).
- Mayor complejidad en la lógica de envolvimiento.
- Desperdicio de memoria si la capacidad es muy grande.

## Más Allá de las Estructuras Lineales

Las pilas y colas son estructuras **lineales** donde los elementos tienen un predecesor y un sucesor claro (excepto el primero y el último). Sin embargo, muchos problemas del mundo real requieren estructuras más complejas para representar relaciones entre datos.

### Diccionarios (Tablas Hash)

Un **diccionario** o **mapa** es un TAD que asocia **claves únicas** con **valores**. A diferencia de las secuencias donde accedés por posición, en un diccionario accedés por una clave específica.

**Operaciones fundamentales:**
- `insertar(clave, valor)`: Asocia un valor con una clave
- `buscar(clave)`: Retorna el valor asociado a la clave
- `eliminar(clave)`: Elimina la asociación clave-valor
- `contiene(clave)`: Verifica si existe una clave

**Implementación típica:** Tabla hash con función de hash y manejo de colisiones.

**Complejidad:** $O(1)$ promedio para todas las operaciones.

**Aplicaciones prácticas:**
- Caché de datos
- Índices de bases de datos
- Contadores (frecuencia de palabras)
- Diccionarios de lenguaje natural
- Mapeo de identificadores

:::{note}
Los diccionarios rompen con la restricción de acceso secuencial, permitiendo acceso directo por clave. Son una de las estructuras más utilizadas en programación moderna.
:::

### Árboles

Un **árbol** es una estructura **jerárquica** donde cada elemento (nodo) puede tener múltiples hijos, pero solo un padre (excepto la raíz). A diferencia de las estructuras lineales, los árboles modelan relaciones de **contención** o **jerarquía**.

**Conceptos clave:**
- **Raíz:** Nodo superior sin padre
- **Hoja:** Nodo sin hijos
- **Altura:** Distancia máxima desde la raíz a una hoja
- **Subárbol:** Árbol formado por un nodo y todos sus descendientes

**Tipos importantes:**
- **Árbol Binario:** Cada nodo tiene como máximo 2 hijos
- **Árbol Binario de Búsqueda (BST):** Árbol binario con propiedad de orden
- **Árbol AVL/Rojinegro:** BST auto-balanceado
- **Heap:** Árbol binario completo con propiedad de orden especial
- **Árbol B:** Árbol multiway usado en bases de datos

**Aplicaciones prácticas:**
- Sistemas de archivos (jerarquía de directorios)
- DOM (Document Object Model) en navegadores web
- Expresiones aritméticas (árbol sintáctico)
- Bases de datos (índices B-tree)
- Compresión de datos (árboles de Huffman)
- Inteligencia artificial (árboles de decisión)

**Complejidad en BST balanceado:**
- Búsqueda: $O(\log n)$
- Inserción: $O(\log n)$
- Eliminación: $O(\log n)$

:::{important}
Los árboles son fundamentales porque muchas relaciones del mundo real son naturalmente jerárquicas. Además, ofrecen búsquedas mucho más rápidas que las estructuras lineales.
:::

### Grafos

Un **grafo** es la estructura más general: un conjunto de **vértices** (nodos) conectados por **aristas** (enlaces). A diferencia de los árboles, los grafos pueden tener ciclos y múltiples caminos entre nodos.

**Tipos de grafos:**
- **Dirigido vs No dirigido:** Las aristas tienen dirección o no
- **Ponderado vs No ponderado:** Las aristas tienen pesos/costos o no
- **Conexo vs Disconexo:** Todos los nodos alcanzables o no
- **Cíclico vs Acíclico:** Contiene ciclos o no (DAG)

**Representaciones comunes:**
- **Matriz de adyacencia:** Arreglo 2D indicando conexiones
- **Lista de adyacencia:** Para cada vértice, lista de vecinos

**Operaciones típicas:**
- Búsqueda en anchura (BFS)
- Búsqueda en profundidad (DFS)
- Camino más corto (Dijkstra, Bellman-Ford)
- Árbol de expansión mínima (Kruskal, Prim)
- Ordenamiento topológico

**Aplicaciones prácticas:**
- Redes sociales (conexiones entre personas)
- Mapas y navegación GPS (ciudades y rutas)
- Redes de computadoras (topología de red)
- Dependencias de paquetes en software
- Análisis de circuitos eléctricos
- Planificación de tareas con dependencias
- Compiladores (grafos de flujo de control)

**Complejidad típica:**
- BFS/DFS: $O(V + E)$ donde V=vértices, E=aristas
- Dijkstra: $O((V + E) \log V)$ con heap
- Bellman-Ford: $O(VE)$

:::{note} Generalidad de los Grafos

Los grafos son la estructura más general: los árboles son grafos sin ciclos, las listas son árboles degenerados (un solo camino), y las pilas/colas son listas con restricciones. Comprender grafos te da las herramientas para modelar prácticamente cualquier relación entre datos.
:::

### Conjuntos (Sets)

Un **conjunto** es una colección de elementos únicos, sin orden específico y sin duplicados. Es la implementación computacional del concepto matemático de conjunto.

**Operaciones fundamentales:**
- `agregar(elemento)`: Añade un elemento si no existe
- `contiene(elemento)`: Verifica si un elemento pertenece al conjunto
- `eliminar(elemento)`: Remueve un elemento
- `union(otro_conjunto)`: Retorna la unión de dos conjuntos
- `interseccion(otro_conjunto)`: Retorna la intersección
- `diferencia(otro_conjunto)`: Retorna la diferencia

**Implementaciones comunes:**
- Tabla hash: $O(1)$ promedio para operaciones básicas
- Árbol balanceado: $O(\log n)$ pero mantiene orden
- Bitmap (para conjuntos pequeños): $O(1)$ con memoria compacta

**Aplicaciones prácticas:**
- Verificación de unicidad (emails registrados)
- Operaciones matemáticas sobre grupos
- Filtrado de duplicados
- Análisis de pertenencia
- Algoritmos de grafos (conjunto de visitados)

:::{tip}
Los conjuntos son útiles cuando el orden no importa pero la unicidad sí. En C, podés implementarlos con tablas hash o árboles BST según tus necesidades de orden.
:::

### Colas de Prioridad (Priority Queues)

Una **cola de prioridad** es una estructura donde cada elemento tiene una prioridad asociada, y los elementos se extraen según su prioridad, no según el orden de llegada.

**Operaciones fundamentales:**
- `insertar(elemento, prioridad)`: Agrega con prioridad
- `extraer_min()` o `extraer_max()`: Extrae el de mayor/menor prioridad
- `peek()`: Ve el siguiente sin extraer
- `cambiar_prioridad(elemento, nueva_prioridad)`: Actualiza prioridad

**Implementación típica:** Heap binario (min-heap o max-heap)

**Complejidad con heap:**
- Inserción: $O(\log n)$
- Extracción: $O(\log n)$
- Peek: $O(1)$

**Aplicaciones prácticas:**
- Algoritmo de Dijkstra (caminos más cortos)
- Scheduling de procesos con prioridades
- Simulación de eventos discretos
- Algoritmo A* en videojuegos
- Compresión de datos (Huffman coding)
- Manejo de interrupciones en sistemas operativos

:::{important}
A diferencia de una cola normal (FIFO), la cola de prioridad extrae basándose en la **prioridad**, no en el orden temporal. Es fundamental para algoritmos que requieren procesar primero los elementos "más importantes".
:::

### Listas Doblemente Enlazadas con Cabeza/Cola (Deques)

Un **deque** (*double-ended queue*, cola de doble extremo) permite inserción y eliminación eficiente en ambos extremos. Es una generalización tanto de pilas como de colas.

**Operaciones fundamentales:**
- `insertar_al_inicio(elemento)`: $O(1)$
- `insertar_al_final(elemento)`: $O(1)$
- `eliminar_del_inicio()`: $O(1)$
- `eliminar_del_final()`: $O(1)$

**Implementaciones:**
- Lista doblemente enlazada: Operaciones $O(1)$ reales
- Arreglo circular: Operaciones $O(1)$ con mejor caché

**Aplicaciones prácticas:**
- Ventanas deslizantes en algoritmos
- Caché LRU (Least Recently Used)
- Algoritmos de búsqueda bidireccional
- Palíndromos y operaciones simétricas
- Deshacer/Rehacer con límite de memoria

:::{note}
Un deque puede comportarse como pila (usando un extremo) o como cola (usando ambos extremos para FIFO), lo que lo hace muy versátil.
:::

### Multiconjuntos (Multisets o Bags)

Un **multiconjunto** es como un conjunto pero permite elementos duplicados, manteniendo el conteo de cada uno.

**Operaciones fundamentales:**
- `agregar(elemento)`: Incrementa el conteo
- `eliminar(elemento)`: Decrementa el conteo
- `conteo(elemento)`: Retorna cuántas veces aparece
- `contiene(elemento)`: Verifica presencia

**Implementación típica:** Diccionario donde la clave es el elemento y el valor es el conteo.

**Aplicaciones prácticas:**
- Análisis de frecuencias (palabras en texto)
- Estadísticas y conteo
- Histogramas
- Algoritmos de anagramas
- Inventarios con cantidades

### Tries (Árboles de Prefijos)

Un **trie** es un árbol especializado para almacenar cadenas de caracteres, donde cada nodo representa un carácter y los caminos representan palabras.

**Características:**
- Búsqueda de palabras: $O(m)$ donde m es la longitud de la palabra
- Búsqueda de prefijos muy eficiente
- Todas las palabras con un prefijo común comparten nodos

**Aplicaciones prácticas:**
- Autocompletado en motores de búsqueda
- Correctores ortográficos
- Diccionarios de idiomas
- Enrutamiento IP (prefix matching)
- T9 en teléfonos móviles

:::{tip}
Los tries son excelentes cuando necesitás buscar por prefijos o trabajar con grandes conjuntos de cadenas con prefijos comunes. El espacio puede optimizarse con compressed tries (Patricia trees).
:::

### Árboles de Segmentos (Segment Trees)

Un **árbol de segmentos** permite consultas y actualizaciones eficientes sobre rangos en un arreglo.

**Operaciones típicas:**
- Consulta de rango (suma, mínimo, máximo): $O(\log n)$
- Actualización puntual: $O(\log n)$
- Actualización de rango (lazy propagation): $O(\log n)$

**Aplicaciones prácticas:**
- Consultas de rangos en bases de datos
- Procesamiento de señales
- Problemas de geometría computacional
- Competencias de programación

### Union-Find (Disjoint Set)

**Union-Find** (o Disjoint Set Union, DSU) es una estructura para manejar conjuntos disjuntos con operaciones de unión y búsqueda.

**Operaciones fundamentales:**
- `find(elemento)`: Encuentra el representante del conjunto
- `union(conjunto1, conjunto2)`: Une dos conjuntos

**Complejidad con optimizaciones:** Casi $O(1)$ amortizado (función inversa de Ackermann)

**Aplicaciones prácticas:**
- Algoritmo de Kruskal (árbol de expansión mínima)
- Detección de componentes conexos en grafos
- Análisis de redes sociales (comunidades)
- Percolación y análisis de conectividad
- Algoritmos de unificación en compiladores

:::{important}
Union-Find es sorprendentemente simple de implementar pero extremadamente poderoso. Con path compression y union by rank, tiene complejidad casi constante.
:::

### Filtros de Bloom

Un **filtro de Bloom** es una estructura probabilística que indica si un elemento **definitivamente no está** o **probablemente está** en un conjunto.

**Características:**
- Muy eficiente en espacio
- Permite falsos positivos, pero no falsos negativos
- Consulta: $O(k)$ donde k es el número de funciones hash

**Aplicaciones prácticas:**
- Caché de bases de datos (evitar consultas inútiles)
- Detección de URLs maliciosas en navegadores
- Sistemas de archivos distribuidos
- Detección de spam
- Bases de datos NoSQL (evitar lecturas de disco)

:::{note}
Los filtros de Bloom sacrifican precisión por eficiencia de espacio. Son perfectos cuando un pequeño porcentaje de falsos positivos es aceptable.
:::

### Skip Lists

Una **skip list** es una estructura probabilística que funciona como un BST balanceado pero con implementación más simple.

**Características:**
- Búsqueda, inserción, eliminación: $O(\log n)$ esperado
- Implementación más simple que árboles AVL o rojinegros
- Múltiples niveles de "autopistas" para saltar nodos

**Aplicaciones prácticas:**
- Implementación de conjuntos y mapas ordenados
- Redis (servidor de caché) usa skip lists
- Alternativa a árboles balanceados cuando la simplicidad importa

:::{tip}
Las skip lists son una excelente alternativa a los árboles balanceados cuando preferís simplicidad de implementación sobre garantías determinísticas.
:::

### Eligiendo la Estructura Correcta

La elección de la estructura de datos adecuada depende de:

1. **Patrón de acceso:** ¿Secuencial, aleatorio, por clave, por relación?
2. **Operaciones frecuentes:** ¿Inserción, búsqueda, eliminación?
3. **Restricciones de orden:** ¿LIFO, FIFO, ordenado, sin restricción?
4. **Relaciones entre datos:** ¿Lineal, jerárquica, red compleja?
5. **Requerimientos de rendimiento:** ¿Tiempo, espacio, predicibilidad?

| Necesidad | Estructura Recomendada |
|-----------|------------------------|
| Acceso secuencial simple | Lista enlazada |
| Acceso por índice frecuente | Arreglo dinámico |
| Último en entrar, primero en salir | Pila |
| Primero en entrar, primero en salir | Cola |
| Acceso por ambos extremos | Deque |
| Búsqueda rápida por clave | Diccionario (Hash) |
| Búsqueda en rango ordenado | Árbol BST |
| Búsqueda por prefijo de cadenas | Trie |
| Consultas de rango en arreglo | Árbol de Segmentos |
| Elementos únicos sin orden | Conjunto (Set) |
| Elementos con conteo/frecuencia | Multiconjunto (Bag) |
| Procesar por prioridad | Cola de Prioridad (Heap) |
| Conjuntos disjuntos dinámicos | Union-Find |
| Verificación probabilística rápida | Filtro de Bloom |
| Relaciones jerárquicas | Árbol general |
| Relaciones complejas/redes | Grafo |

:::{tip} Principio de Diseño

Empezá con la estructura más simple que cumpla tus requisitos. Podés optimizar después si el análisis de rendimiento lo justifica. La abstracción te permite cambiar la implementación sin reescribir todo el código.
:::

## Complejidad Temporal

| Operación | Pila | Cola |
|-----------|------|------|
| Push/Encolar | $O(1)$ | $O(1)$ |
| Pop/Desencolar | $O(1)$ | $O(1)$ |
| Peek/Ver Frente | $O(1)$ | $O(1)$ |
| Es Vacía | $O(1)$ | $O(1)$ |
| Buscar elemento | $O(n)$ | $O(n)$ |

:::{important}
Todas las operaciones fundamentales de pilas y colas son $O(1)$, lo que las hace muy eficientes para sus casos de uso específicos.
:::

## Ejercicios

### Ejercicio 1: Invertir una Pila

Escribí una función que invierta el contenido de una pila usando únicamente otra pila auxiliar.

````{exercise} invertir-pila
:label: ejercicio-invertir-pila

Implementá la función:
```c
void invertir_pila(pila_t *pila);
```

La función debe invertir el orden de los elementos de la pila. Por ejemplo, si la pila contiene (de tope a fondo): 1, 2, 3, 4, después de invertir debe contener: 4, 3, 2, 1.

Restricción: Podés usar solo una pila auxiliar adicional.
````

````{solution} ejercicio-invertir-pila
:label: solucion-invertir-pila
:class: dropdown

```c
void invertir_pila(pila_t *pila)
{
    pila_t *auxiliar = NULL;
    int dato = 0;
    
    if (pila == NULL || es_vacia_pila(pila))
    {
        return;
    }
    
    auxiliar = crear_pila();
    
    if (auxiliar == NULL)
    {
        return;
    }
    
    while (!es_vacia_pila(pila))
    {
        pop(pila, &dato);
        push(auxiliar, dato);
    }
    
    while (!es_vacia_pila(auxiliar))
    {
        pop(auxiliar, &dato);
        push(pila, dato);
    }
    
    destruir_pila(auxiliar);
}
```

```{note} Observación
Esta solución realiza dos pasadas, por lo que los elementos terminan en el mismo orden. 
Para invertir correctamente, necesitarías dos pilas auxiliares o usar recursión.
```

**Solución correcta con dos pilas:**
```c
void invertir_pila(pila_t *pila)
{
    pila_t *aux1 = NULL;
    pila_t *aux2 = NULL;
    int dato = 0;
    
    if (pila == NULL || es_vacia_pila(pila))
    {
        return;
    }
    
    aux1 = crear_pila();
    aux2 = crear_pila();
    
    while (!es_vacia_pila(pila))
    {
        pop(pila, &dato);
        push(aux1, dato);
    }
    
    while (!es_vacia_pila(aux1))
    {
        pop(aux1, &dato);
        push(aux2, dato);
    }
    
    while (!es_vacia_pila(aux2))
    {
        pop(aux2, &dato);
        push(pila, dato);
    }
    
    destruir_pila(aux1);
    destruir_pila(aux2);
}
```
````

### Ejercicio 2: Palíndromo con Pila y Cola

````{exercise}
:label: ejercicio-palindromo

Escribí una función que determine si una cadena de caracteres es un palíndromo utilizando una pila y una cola.

```c
bool es_palindromo(const char *cadena);
```

Un palíndromo es una palabra que se lee igual de izquierda a derecha que de derecha a izquierda (por ejemplo: "radar", "anilina").

:::{note}
Insertá cada carácter en una pila y en una cola simultáneamente, luego compará los elementos al extraerlos.
:::
````

### Ejercicio 3: Cola con Dos Pilas

````{exercise}
:label: ejercicio-cola-con-pilas

Implementá una cola utilizando únicamente dos pilas. Las operaciones `encolar` y `desencolar` deben mantener el comportamiento FIFO.

```c
typedef struct cola_con_pilas
{
    pila_t *pila_entrada;
    pila_t *pila_salida;
} cola_con_pilas_t;

bool encolar_pilas(cola_con_pilas_t *cola, int dato);
bool desencolar_pilas(cola_con_pilas_t *cola, int *dato);
```

Sugerencia: Usá una pila para las inserciones y otra para las extracciones, transfiriendo elementos entre ellas cuando sea necesario.
````

## Referencias y Lecturas Complementarias

Para profundizar en pilas y colas:

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press. Capítulo 10: Elementary Data Structures.
- Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C* (2nd ed.). Pearson. Capítulo 3: Lists, Stacks, and Queues.

Para estructuras más avanzadas:

- **Tablas Hash:** Cormen et al., Capítulo 11: Hash Tables.
- **Árboles:** Cormen et al., Capítulos 12-13: Binary Search Trees y Red-Black Trees.
- **Grafos:** Cormen et al., Capítulos 22-25: Graph Algorithms.
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley. Excelente cobertura de todas las estructuras con aplicaciones prácticas.

Para aspectos de implementación y gestión de memoria:

- {ref}`memoria-introduccion` para entender el modelo de memoria completo.
- {ref}`memoria-buenas-practicas` para patrones seguros de manejo de memoria dinámica.

Recursos en línea:

- VisualAlgo (https://visualgo.net): Visualización interactiva de estructuras de datos y algoritmos.
- GeeksforGeeks: Tutoriales detallados con implementaciones en múltiples lenguajes.

## Resumen

Este apunte ha cubierto estructuras de datos fundamentales y su lugar en el ecosistema más amplio de estructuras de datos:

### Pilas y Colas

Las pilas y colas son TADs que restringen el acceso a elementos siguiendo políticas específicas:

- **Pilas (LIFO):** El último en entrar es el primero en salir. Ideales para:
  - Evaluación de expresiones
  - Backtracking
  - Gestión de llamadas a funciones
  - Deshacer/Rehacer
  
- **Colas (FIFO):** El primero en entrar es el primero en salir. Ideales para:
  - Procesamiento en orden de llegada
  - Buffers y sistemas de mensajería
  - Scheduling de procesos
  - Algoritmos de búsqueda en anchura

### Implementaciones Múltiples

:::{important} Implementación como Abstracción

Tanto pilas como colas pueden implementarse usando:
- **Listas enlazadas:** Flexibles, sin límite de tamaño
- **Arreglos (fijos o dinámicos):** Mejor localidad de caché, predecibles

La elección de implementación depende de las necesidades específicas del sistema: límites de tamaño conocidos, patrones de acceso, y requisitos de rendimiento.
:::

### Panorama de Estructuras de Datos

Hemos visto cómo las estructuras de datos se organizan en una jerarquía de generalidad y propósito:

```{figure} 14/jerarquia_estructuras.svg
:label: fig-jerarquia
:align: center
:width: 100%

Jerarquía y organización de estructuras de datos desde las más restrictivas (pilas/colas) hasta las más generales (grafos).
```

1. **Estructuras Lineales con Restricciones:**
   - Pilas: Solo acceso por un extremo (LIFO)
   - Colas: Acceso por extremos opuestos (FIFO)
   - Deques: Acceso por ambos extremos

2. **Estructuras Lineales Generales:**
   - Secuencias: Acceso flexible (listas, arreglos)
   
3. **Estructuras de Búsqueda:**
   - Diccionarios: Acceso por clave ($O(1)$ promedio)
   - Árboles BST: Acceso ordenado ($O(\log n)$)
   - Tries: Búsqueda por prefijos
   - Skip Lists: BST probabilístico

4. **Estructuras de Colecciones:**
   - Conjuntos: Elementos únicos
   - Multiconjuntos: Elementos con frecuencia
   - Colas de Prioridad: Elementos ordenados por prioridad

5. **Estructuras Jerárquicas:**
   - Árboles: Relaciones padre-hijo
   - Árboles de Segmentos: Consultas de rangos

6. **Estructuras de Propósito General:**
   - Grafos: Relaciones arbitrarias entre elementos

7. **Estructuras Especializadas:**
   - Union-Find: Conjuntos disjuntos dinámicos
   - Filtros de Bloom: Verificación probabilística

:::{tip} Camino de Aprendizaje

Esta progresión no es arbitraria. Cada tipo de estructura se construye conceptualmente sobre las anteriores:
- Pilas/colas/deques son especializaciones de secuencias
- Árboles son grafos sin ciclos
- Muchas estructuras avanzadas son combinaciones ingeniosas de las básicas
- Comprender las estructuras simples facilita entender las complejas
:::

### Lecciones Clave

1. **Abstracción:** Las mismas operaciones (push, pop) pueden tener múltiples implementaciones.
2. **Trade-offs:** No hay estructura "mejor", solo la más apropiada para cada contexto.
3. **Jerarquía:** Las estructuras más simples son bloques de construcción para las complejas.
4. **Aplicabilidad:** Cada estructura modela un patrón específico de relaciones entre datos.
5. **Especialización:** Muchas estructuras avanzadas son optimizaciones para casos de uso específicos.

### Estructuras Introducidas

Este apunte ha presentado un panorama completo de estructuras de datos:

**Implementadas en detalle:**
- Pilas (lista enlazada y arreglo)
- Colas (lista enlazada y arreglo circular)

**Introducidas conceptualmente:**
- Diccionarios/Tablas Hash
- Árboles (binarios, BST, AVL, Heap, B-tree)
- Grafos (dirigidos, ponderados, representaciones)
- Conjuntos y Multiconjuntos
- Colas de Prioridad
- Deques (colas de doble extremo)
- Tries (árboles de prefijos)
- Árboles de Segmentos
- Union-Find (conjuntos disjuntos)
- Filtros de Bloom
- Skip Lists

:::{note} Estructuras Probabilísticas

Algunas estructuras modernas (Filtros de Bloom, Skip Lists) usan aleatorización para lograr simplicidad o eficiencia de espacio. Representan un enfoque diferente: sacrificar garantías determinísticas por beneficios prácticos.
:::

Estas estructuras son fundamentales para construir sistemas más complejos y aparecen constantemente en algoritmos y aplicaciones del mundo real. El siguiente paso es estudiar cada familia de estructuras más avanzadas en profundidad, comprendiendo sus implementaciones detalladas, análisis de complejidad, y casos de uso específicos.
