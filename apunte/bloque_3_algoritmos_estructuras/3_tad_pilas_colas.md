---
title: 'Pilas, Colas y Estructuras Lineales Restringidas'
short_title: 'Pilas y Colas'
subtitle: 'TAD Pila, Cola y Deque'
---

(capitulo-tad-pilas-colas)=
# Referencias y Lecturas Complementarias

## Introducción



## Desarrollo

(pilas-stacks)=
### Pilas (Stacks)


Una **pila** es una estructura de datos lineal que sigue el principio **LIFO**
(*Last In, First Out*): el último elemento en entrar es el primero en salir. Es
análogo a una pila de platos donde solo podés agregar o quitar platos desde la
parte superior.

:::{figure} 4/pila_stack.svg
:label: fig-pila-stack
:align: center

Operaciones de apilado (push) and desapilado (pop) en una Pila.

:::
<!-- {figure} 4/pila_stack.svg -->

(operaciones-fundamentales)=
#### Operaciones Fundamentales

- **push(elemento):** Agrega un elemento al tope de la pila.
- **pop():** Extrae y retorna el elemento del tope.
- **peek() o top():** Retorna el elemento del tope sin extraerlo.
- **es_vacia():** Verifica si la pila está vacía.

(implementacion-con-lista-enlazada)=
#### Implementación con Lista Enlazada

:::{figure} 4/pila_lista_enlazada.svg
:label: fig-pila-lista-enlazada
:align: center

Estructura de una Pila implementada dinámicamente mediante nodos enlazados en el
heap.

:::
<!-- {figure} 4/pila_lista_enlazada.svg -->

##### Estructura de Datos

:::{code-block}c
:linenos:
typedef struct nodo {
    void *dato;
    struct nodo *siguiente;
} nodo_t;

struct pila {
    nodo_t *tope;
    size_t tamanio;
};

:::
<!-- {code-block}c -->

##### Creación de una Pila

:::{code-block}c
:linenos:
pila_t *pila_crear(void)
{
    pila_t *pila = malloc(sizeof(*pila));
    if (pila == NULL)
    {
        return NULL;
    }
    pila->tope = NULL;
    pila->tamanio = 0;
    return pila;
}

:::
<!-- {code-block}c -->

##### Apilar (Push)

:::{code-block}c
:linenos:
bool pila_push(pila_t *pila, void *dato)
{
    if (pila == NULL)
    {
        return false;
    }
    
    nodo_t *nuevo = malloc(sizeof(*nuevo));
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

:::
<!-- {code-block}c -->

:::{note}

La operación `pila_push` es equivalente a realizar una inserción al inicio en
una lista enlazada, siendo el tope de la pila el primer elemento de la lista.

:::
<!-- {note} -->

##### Desapilar (Pop)

:::{code-block}c
:linenos:
bool pila_pop(pila_t *pila, void **dato)
{
    if (pila == NULL || pila->tope == NULL)
    {
        return false;
    }
    
    nodo_t *nodo_a_eliminar = pila->tope;
    if (dato != NULL)
    {
        *dato = nodo_a_eliminar->dato;
    }
    pila->tope = nodo_a_eliminar->siguiente;
    
    free(nodo_a_eliminar);
    pila->tamanio--;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Ver Tope (Peek)

:::{code-block}c
:linenos:
bool pila_peek(const pila_t *pila, void **dato)
{
    if (pila == NULL || pila->tope == NULL)
    {
        return false;
    }
    
    if (dato != NULL)
    {
        *dato = pila->tope->dato;
    }
    return true;
}

:::
<!-- {code-block}c -->

##### Verificar si está Vacía

:::{code-block}c
:linenos:
bool pila_es_vacia(const pila_t *pila)
{
    return (pila == NULL) || (pila->tope == NULL);
}

:::
<!-- {code-block}c -->

##### Destruir Pila

:::{code-block}c
:linenos:
void pila_destruir(pila_t *pila, destruir_dato_fn destruir_dato)
{
    if (pila == NULL)
    {
        return;
    }
    
    while (pila->tope != NULL)
    {
        nodo_t *nodo_actual = pila->tope;
        pila->tope = nodo_actual->siguiente;
        if (destruir_dato != NULL && nodo_actual->dato != NULL)
        {
            destruir_dato(nodo_actual->dato);
        }
        free(nodo_actual);
    }
    
    free(pila);
}

:::
<!-- {code-block}c -->

:::{important}

Es fundamental liberar toda la memoria utilizada, recorriendo la lista y
liberando cada nodo antes de liberar la estructura de la pila.

:::
<!-- {important} -->

(analisis-de-complejidad-pila-lista-enlazada)=
#### Análisis de Complejidad de la Pila (Lista Enlazada)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| push | $O(1)$ | $O(1)$ |
| pop | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

(implementacion-con-arreglo-dinamico)=
#### Implementación con Arreglo Dinámico

Una alternativa es implementar la pila usando un arreglo, donde el tope es el
último elemento ocupado.

:::{figure} 4/pila_arreglo.svg
:label: fig-pila-arreglo
:align: center

Estructura de una Pila implementada estáticamente mediante un arreglo y un
índice de tope.

:::
<!-- {figure} 4/pila_arreglo.svg -->

##### Estructura de Datos

:::{code-block}c
:linenos:
struct pila {
    void **elementos;
    size_t tope;       // Próximo índice libre / Cantidad de elementos
    size_t capacidad;  // Capacidad total del arreglo
};

:::
<!-- {code-block}c -->

##### Creación con Capacidad Inicial

:::{code-block}c
:linenos:
pila_t *pila_crear_arreglo(size_t capacidad_inicial)
{
    if (capacidad_inicial == 0)
    {
        return NULL;
    }
    
    pila_t *pila = malloc(sizeof(*pila));
    if (pila == NULL)
    {
        return NULL;
    }
    
    pila->elementos = malloc(capacidad_inicial * sizeof(*(pila->elementos)));
    if (pila->elementos == NULL)
    {
        free(pila);
        return NULL;
    }
    
    pila->tope = 0;
    pila->capacidad = capacidad_inicial;
    
    return pila;
}

:::
<!-- {code-block}c -->

##### Apilar con Redimensionamiento

:::{code-block}c
:linenos:
static bool pila_redimensionar(pila_t *pila)
{
    size_t nueva_capacidad = pila->capacidad * 2;
    void **nuevo_arreglo = realloc(pila->elementos, nueva_capacidad *
    sizeof(*nuevo_arreglo));
    if (nuevo_arreglo == NULL)
    {
        return false;
    }
    
    pila->elementos = nuevo_arreglo;
    pila->capacidad = nueva_capacidad;
    
    return true;
}

bool pila_push_arreglo(pila_t *pila, void *dato)
{
    if (pila == NULL)
    {
        return false;
    }
    
    if (pila->tope >= pila->capacidad)
    {
        if (!pila_redimensionar(pila))
        {
            return false;
        }
    }
    
    pila->elementos[pila->tope] = dato;
    pila->tope++;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{tip}

El factor de redimensionamiento (comúnmente 2) es importante. Duplicar la
capacidad garantiza que el costo amortizado de `pila_push_arreglo` sea $O(1)$,
aunque un `push` individual pueda ser $O(n)$ cuando requiere redimensionar. Para
entender cómo se calcula formalmente el análisis amortizado usando el método del
banquero o el método del potencial, consultá la sección sobre análisis
amortizado en {ref}`capitulo-complejidad`.

:::
<!-- {tip} -->

##### Desapilar (Arreglo)

:::{code-block}c
:linenos:
bool pila_pop_arreglo(pila_t *pila, void **dato)
{
    if (pila == NULL || pila->tope == 0)
    {
        return false;
    }
    
    pila->tope--;
    if (dato != NULL)
    {
        *dato = pila->elementos[pila->tope];
    }
    
    return true;
}

:::
<!-- {code-block}c -->

(analisis-de-complejidad-arreglo)=
#### Análisis de Complejidad (Arreglo)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| push | $O(1)$ amortizado | $O(1)$ |
| pop | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

:::{note}

Aunque `push` puede ser $O(n)$ cuando requiere redimensionar, el análisis
amortizado muestra que en promedio sigue siendo $O(1)$. Este tipo de análisis es
crucial para estructuras de datos dinámicas y se estudia en profundidad en
{ref}`capitulo-complejidad`.

:::
<!-- {note} -->

(aplicaciones-de-pilas)=
#### Aplicaciones de Pilas

Las pilas aparecen naturalmente en numerosos contextos de programación:

1. **Gestión de llamadas a funciones:** La pila de ejecución (*call stack*)
   mantiene los registros de activación.
2. **Evaluación de expresiones:** Conversión de notación infija a postfija,
   evaluación de expresiones postfijas.
3. **Backtracking:** Algoritmos de búsqueda en profundidad, resolución de
   laberintos.
4. **Deshacer/Rehacer:** Editores de texto mantienen pilas de operaciones.
5. **Parsing:** Análisis sintáctico de lenguajes de programación (verificación
   de paréntesis balanceados).

##### Ejemplo: Verificación de Paréntesis Balanceados

:::{code-block}c
:linenos:
bool parentesis_balanceados(const char *expresion)
{
    if (expresion == NULL)
    {
        return false;
    }
    
    pila_t *pila = pila_crear();
    if (pila == NULL)
    {
        return false;
    }
    
    for (size_t i = 0; expresion[i] != '\0'; i++)
    {
        char caracter = expresion[i];
        if (caracter == '(')
        {
            if (!pila_push(pila, caracter))
            {
                pila_destruir(pila);
                return false;
            }
        }
        else if (caracter == ')')
        {
            if (pila_es_vacia(pila))
            {
                pila_destruir(pila);
                return false;
            }
            int temporal;
            pila_pop(pila, &temporal);
        }
    }
    
    bool resultado = pila_es_vacia(pila);
    pila_destruir(pila);
    return resultado;
}

:::
<!-- {code-block}c -->

(ejercicios-de-pilas)=
#### Ejercicios de Pilas

##### Ejercicio 1: Inversión de una cadena con pila


##### Ejercicio 2: Validar expresiones con múltiples delimitadores


##### Ejercicio 3: Evaluación de expresiones postfijas




(colas-queues)=
### Colas (Queues)


Una **cola** es una estructura de datos lineal que sigue el principio **FIFO**
(*First In, First Out*): el primer elemento en entrar es el primero en salir. Es
análogo a una fila de personas donde quien llega primero es atendido primero.

:::{figure} 4/cola_lista_enlazada.svg
:label: fig-cola-lista-enlazada
:align: center

Estructura de una Cola implementada dinámicamente mediante nodos enlazados en el
heap con punteros a inicio y fin.

:::
<!-- {figure} 4/cola_lista_enlazada.svg -->

##### Estructura de Datos

:::{code-block}c
:linenos:
typedef struct nodo {
    void *dato;
    struct nodo *siguiente;
} nodo_t;

struct cola {
    nodo_t *frente;
    nodo_t *final;
    size_t tamanio;
};

:::
<!-- {code-block}c -->

:::::{note}

A diferencia de la pila que solo requiere de un puntero al tope, la cola utiliza
dos punteros: uno al frente (para `cola_dequeue`) y otro al final (para
`cola_enqueue`). Esto garantiza que ambas operaciones se ejecuten en tiempo
constante $O(1)$.
::::

##### Creación de una Cola

:::{code-block}c
:linenos:
cola_t *cola_crear(void)
{
    cola_t *cola = malloc(sizeof(*cola));
    if (cola == NULL)
    {
        return NULL;
    }
    
    cola->frente = NULL;
    cola->final = NULL;
    cola->tamanio = 0;
    
    return cola;
}

:::
<!-- {code-block}c -->

##### Encolar (Enqueue)

:::{code-block}c
:linenos:
bool cola_enqueue(cola_t *cola, void *dato)
{
    if (cola == NULL)
    {
        return false;
    }
    
    nodo_t *nuevo = malloc(sizeof(*nuevo));
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

:::
<!-- {code-block}c -->

:::{important}

Es indispensable considerar el caso particular de la cola vacía. En tal
situación, tanto el puntero `frente` como el puntero `final` deben referenciar
al nuevo nodo creado.

:::
<!-- {important} -->

##### Desencolar (Dequeue)

:::{code-block}c
:linenos:
bool cola_dequeue(cola_t *cola, void **dato)
{
    if (cola == NULL || cola->frente == NULL)
    {
        return false;
    }
    
    nodo_t *nodo_a_eliminar = cola->frente;
    if (dato != NULL)
    {
        *dato = nodo_a_eliminar->dato;
    }
    cola->frente = nodo_a_eliminar->siguiente;
    
    if (cola->frente == NULL)
    {
        cola->final = NULL;
    }
    
    free(nodo_a_eliminar);
    cola->tamanio--;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{important}

Al extraer el último elemento de la cola, esta queda vacía. En ese escenario,
además de actualizar el puntero `frente` a `NULL`, es necesario establecer el
puntero `final` en `NULL`.

:::
<!-- {important} -->

##### Ver Frente (Peek)

:::{code-block}c
:linenos:
bool cola_peek(const cola_t *cola, void **dato)
{
    if (cola == NULL || cola->frente == NULL)
    {
        return false;
    }
    
    if (dato != NULL)
    {
        *dato = cola->frente->dato;
    }
    return true;
}

:::
<!-- {code-block}c -->

##### Destruir Cola

:::{code-block}c
:linenos:
void cola_destruir(cola_t *cola, destruir_dato_fn destruir_dato)
{
    if (cola == NULL)
    {
        return;
    }
    
    while (cola->frente != NULL)
    {
        nodo_t *nodo_actual = cola->frente;
        cola->frente = nodo_actual->siguiente;
        if (destruir_dato != NULL && nodo_actual->dato != NULL)
        {
            destruir_dato(nodo_actual->dato);
        }
        free(nodo_actual);
    }
    
    free(cola);
}

:::
<!-- {code-block}c -->

(analisis-de-complejidad-cola-lista-enlazada)=
#### Análisis de Complejidad de la Cola (Lista Enlazada)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| enqueue | $O(1)$ | $O(1)$ |
| dequeue | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

(implementacion-con-arreglo-circular)=
#### Implementación con Arreglo Circular

Una implementación eficiente de cola con arreglo usa la técnica de **arreglo
circular**, donde los índices "dan la vuelta" al final del arreglo.

:::{figure} 4/cola_circular.svg
:label: fig-cola-circular
:align: center

Implementación eficiente de Cola sobre un arreglo circular para evitar el
desplazamiento costoso de elementos.

:::
<!-- {figure} 4/cola_circular.svg -->

##### Estructura de Datos

:::{code-block}c
:linenos:
struct cola {
    void **elementos;
    size_t frente;
    size_t final;
    size_t tamanio;
    size_t capacidad;
};

:::
<!-- {code-block}c -->

:::{note}

En esta implementación con arreglo circular, el índice `final` apunta a la
posición **después** del último elemento. Esto simplifica la lógica de detección
de cola vacía o llena.

:::
<!-- {note} -->

##### Creación de Cola Circular

:::{code-block}c
:linenos:
cola_t *cola_crear_circular(size_t capacidad_inicial)
{
    if (capacidad_inicial == 0)
    {
        return NULL;
    }
    
    cola_t *cola = malloc(sizeof(*cola));
    if (cola == NULL)
    {
        return NULL;
    }
    
    cola->elementos = malloc(capacidad_inicial * sizeof(*(cola->elementos)));
    if (cola->elementos == NULL)
    {
        free(cola);
        return NULL;
    }
    
    cola->frente = 0;
    cola->final = 0;
    cola->tamanio = 0;
    cola->capacidad = capacidad_inicial;
    
    return cola;
}

:::
<!-- {code-block}c -->

##### Encolar en Arreglo Circular

:::{code-block}c
:linenos:
static bool cola_redimensionar_circular(cola_t *cola)
{
    size_t nueva_capacidad = cola->capacidad * 2;
    void **nuevo_arreglo = malloc(nueva_capacidad * sizeof(*nuevo_arreglo));
    if (nuevo_arreglo == NULL)
    {
        return false;
    }
    
    for (size_t i = 0; i < cola->tamanio; i++)
    {
        size_t indice = (cola->frente + i) % cola->capacidad;
        nuevo_arreglo[i] = cola->elementos[indice];
    }
    
    free(cola->elementos);
    cola->elementos = nuevo_arreglo;
    cola->frente = 0;
    cola->final = cola->tamanio;
    cola->capacidad = nueva_capacidad;
    
    return true;
}

bool cola_enqueue_circular(cola_t *cola, void *dato)
{
    if (cola == NULL)
    {
        return false;
    }
    
    if (cola->tamanio == cola->capacidad)
    {
        if (!cola_redimensionar_circular(cola))
        {
            return false;
        }
    }
    
    cola->elementos[cola->final] = dato;
    cola->final = (cola->final + 1) % cola->capacidad;
    cola->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{tip}

El operador módulo `%` permite que el índice "dé la vuelta". Por ejemplo, si
`capacidad = 5` y `final = 4`, entonces `(4 + 1) % 5 = 0`, retornando al inicio
del arreglo.

:::
<!-- {tip} -->

##### Desencolar en Arreglo Circular

:::{code-block}c
:linenos:
bool cola_dequeue_circular(cola_t *cola, void **dato)
{
    if (cola == NULL || cola->tamanio == 0)
    {
        return false;
    }
    
    if (dato != NULL)
    {
        *dato = cola->elementos[cola->frente];
    }
    cola->frente = (cola->frente + 1) % cola->capacidad;
    cola->tamanio--;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{important}

Al redimensionar, es crucial copiar los elementos en el orden secuencial
correcto (frente a final), considerando que el frente puede no estar alineado en
la posición 0 del arreglo original.

:::
<!-- {important} -->

(analisis-de-complejidad-arreglo-circular)=
#### Análisis de Complejidad (Arreglo Circular)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| enqueue | $O(1)$ amortizado | $O(1)$ |
| dequeue | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

(aplicaciones-de-colas)=
#### Aplicaciones de Colas

Las colas modelan situaciones donde el orden de llegada importa:

1. **Sistemas operativos:** Scheduling de procesos, colas de impresión.
2. **Redes:** Buffers de transmisión, enrutamiento de paquetes.
3. **Algoritmos de grafos:** Búsqueda en anchura (BFS).
4. **Simulaciones:** Modelado de filas de espera, teoría de colas.
5. **Procesamiento asíncrono:** Cola de tareas, sistemas de mensajería.

(ejercicios-de-colas)=
#### Ejercicios de Colas

##### Ejercicio 1: Simulador de cola de impresión


##### Ejercicio 2: Implementación de cola con dos pilas


##### Ejercicio 3: Invertir los primeros K elementos de una cola



(comparacion-pilas-vs-colas)=
### Comparación: Pilas vs Colas


| Aspecto | Pila (LIFO) | Cola (FIFO) |
|---------|------------|------------|
| **Política** | Last In, First Out | First In, First Out |
| **Analogía** | Pila de platos | Fila de personas |
| **Operaciones** | push, pop, peek | enqueue, dequeue, peek |
| **Complejidad** | $O(1)$ todas | $O(1)$ todas |
| **Aplicación típica** | Backtracking, parsing | Scheduling, BFS |
| **Implementación simple** | Lista (un puntero) | Lista (dos punteros) |
| **Implementación arreglo** | Índice tope | Arreglo circular |

:::{important}

Ambas estructuras son especializaciones del TAD Secuencia con restricciones de
acceso. La restricción no es una limitación, sino una garantía que simplifica el
razonamiento sobre el código.

:::
<!-- {important} -->


(deques-double-ended-queues)=
### Deques (Double-Ended Queues)


Un **deque** (pronunciado "deck") es una generalización que permite insertar y
extraer elementos en ambos extremos.

:::{figure} 4/deque.svg
:label: fig-deque
:align: center

Representación de una Cola de Doble Extremo (Deque), permitiendo inserciones y
eliminaciones por ambos extremos.

:::
<!-- {figure} 4/deque.svg -->

(operaciones)=
#### Operaciones

- **push_front(elemento):** Agrega al frente.
- **push_back(elemento):** Agrega al final.
- **pop_front():** Extrae del frente.
- **pop_back():** Extrae del final.

:::{note}

Un deque puede simular tanto una pila (usando solo un extremo) como una cola
(usando ambos extremos de forma restringida). Es más general pero potencialmente
más difícil de razonar sobre su uso.

:::
<!-- {note} -->

(aplicaciones-de-deques)=
#### Aplicaciones de Deques

- **Algoritmos de ventana deslizante:** Mantener mínimos/máximos en una ventana.
- **Navegación con historial:** Forward/backward en navegadores.
- **Work stealing:** Algoritmos paralelos donde los threads roban tareas de
  ambos extremos.

(ejercicios-de-deques)=
#### Ejercicios de Deques

##### Ejercicio 1: Verificar palíndromo con Deque


##### Ejercicio 2: Simulación de una Pila usando un Deque


##### Ejercicio 3: Máximo en una ventana deslizante



(7_tad_pilas_colas-comparacion-de-implementaciones)=
### Comparación de Implementaciones


(lista-enlazada-vs-arreglo)=
#### Lista Enlazada vs Arreglo

| Criterio | Lista Enlazada | Arreglo (Circular) |
|----------|---------------|-------------------|
| **Memoria** | Overhead por punteros | Compacta, localidad de caché |
| **Tamaño** | Dinámico sin límite | Requiere redimensionamiento |
| **Operaciones** | Siempre $O(1)$ | $O(1)$ amortizado |
| **Complejidad código** | Media | Alta (aritmética modular) |
| **Uso típico** | Tamaño impredecible | Tamaño acotado |

:::{tip}

Para aplicaciones donde el rendimiento es crítico y el tamaño máximo es
conocido, la implementación con arreglo circular es preferible por su mejor
localidad de caché. Para tamaños muy variables o cuando la simplicidad del
código importa más que el rendimiento, la lista enlazada es más apropiada.

:::
<!-- {tip} -->


(panorama-de-estructuras-de-datos)=
### Panorama de Estructuras de Datos


Las pilas y colas son solo el comienzo. Existe un ecosistema rico de estructuras
de datos, cada una optimizada para diferentes patrones de acceso.

(clasificacion-por-restricciones-de-acceso)=
#### Clasificación por Restricciones de Acceso

1. **Acceso Completamente Restringido:**
   - Pilas: solo el tope es accesible
   - Colas: solo frente y final
   
2. **Acceso Parcialmente Restringido:**
   - Deques: ambos extremos
   - Colas de Prioridad: elemento de máxima prioridad

3. **Acceso Indexado:**
   - Arreglos: acceso por índice en $O(1)$
   - Listas: acceso secuencial en $O(n)$

4. **Acceso por Clave:**
   - Tablas Hash: búsqueda en $O(1)$ promedio
   - Árboles Binarios de Búsqueda: búsqueda en $O(\log n)$

(estructuras-avanzadas)=
#### Estructuras Avanzadas

**Árboles:**
- **Heap (Montículo):** Cola de prioridad eficiente, $O(\log n)$
  insert/extract-min
- **BST (Binary Search Tree):** Búsqueda, inserción, eliminación en $O(\log n)$
  promedio
- **AVL/Red-Black:** BST balanceados, garantizan $O(\log n)$ peor caso
- **B-trees:** Árboles de búsqueda para almacenamiento en disco
- **Tries:** Árboles de prefijos para strings

**Grafos:**
- **Matriz de Adyacencia:** Representación densa, $O(1)$ para verificar arista
- **Lista de Adyacencia:** Representación dispersa, eficiente en espacio

**Tablas Hash:**
- **Chaining:** Manejo de colisiones con listas
- **Open Addressing:** Probing para resolver colisiones
- **Rendimiento:** $O(1)$ promedio para insert/search/delete

**Estructuras Especializadas:**
- **Union-Find:** Conjuntos disjuntos dinámicos
- **Filtros de Bloom:** Verificación probabilística de pertenencia
- **Skip Lists:** Estructura probabilística alternativa a BST

:::{note}

Cada estructura de datos representa un compromiso (*trade-off*) entre tiempo de
operaciones, espacio usado y complejidad de implementación. No existe la "mejor"
estructura, solo la más apropiada para cada contexto. Para comprender cómo
comparar formalmente estructuras de datos usando análisis de complejidad,
consultá {ref}`capitulo-complejidad`.

:::
<!-- {note} -->

## Ejercicios de Autoevaluación

:::{exercise}
:label: ejercicio-pila-invertir-cadena

Escribí una función que utilice una pila para invertir una cadena de caracteres
*in-place* (modificando la cadena original).

Firma de la función:
``` c
void invertir_cadena(char *cadena);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-pila-invertir-cadena
:class: dropdown

Una solución eficiente consiste en recorrer la cadena y apilar los caracteres.
Al desapilar, los elementos se obtienen en el orden inverso (LIFO), permitiendo
reescribir la cadena original.

Para no requerir memoria dinámica adicional por cada carácter, se puede castear
el valor de cada carácter directamente al tipo `void*` que recibe la pila.

Implementación en C:

```{code-block} c
:linenos:
#include <stdint.h>
#include "pila.h"

void invertir_cadena(char *cadena)
{
    if (cadena == NULL || *cadena == '\0')
    {
        return;
    }

    pila_t *pila = pila_crear();
    if (pila == NULL)
    {
        return;
    }

    // Apilamos cada carácter. Casteamos a uintptr_t para evitar advertencias del compilador.
    for (size_t i = 0; cadena[i] != '\0'; i++)
    {
        pila_push(pila, (void*)(uintptr_t)cadena[i]);
    }

    // Desapilamos en la cadena original usando un lazo.
    size_t i = 0;
    while (!pila_es_vacia(pila))
    {
        void *dato;
        pila_pop(pila, &dato);
        cadena[i] = (char)(uintptr_t)dato;
        i++;
    }

    pila_destruir(pila, NULL);
}

```
<!-- {code-block} c -->

Este algoritmo tiene una complejidad temporal de $O(n)$ y una complejidad
espacial de $O(n)$ debido al espacio ocupado por los nodos de la pila.

:::
<!-- {solution} ejercicio-pila-invertir-cadena -->

:::{exercise}
:label: ejercicio-pila-validar-delimitadores

Extendé el ejemplo de verificación de paréntesis balanceados para soportar
múltiples tipos de delimitadores: paréntesis `()`, corchetes `[]` y llaves `{}`.
La función debe verificar que cada apertura tenga su cierre correspondiente y
que los cierres ocurran en el orden correcto.

Firma de la función:
``` c
bool delimitadores_balanceados(const char *expresion);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-pila-validar-delimitadores
:class: dropdown

Para validar múltiples delimitadores se utiliza una pila que almacena los
caracteres de apertura. Al encontrarse un carácter de cierre, este debe
emparejarse con el delimitador del tope de la pila.

Implementación en C:

```{code-block} c
:linenos:
#include <stdint.h>
#include "pila.h"

bool delimitadores_balanceados(const char *expresion)
{
    if (expresion == NULL)
    {
        return false;
    }

    pila_t *pila = pila_crear();
    if (pila == NULL)
    {
        return false;
    }

    bool balanceado = true;
    for (size_t i = 0; expresion[i] != '\0' && balanceado; i++)
    {
        char c = expresion[i];
        if (c == '(' || c == '[' || c == '{')
        {
            if (!pila_push(pila, (void*)(uintptr_t)c))
            {
                balanceado = false;
            }
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (pila_es_vacia(pila))
            {
                balanceado = false;
            }
            else
            {
                void *tope_ptr;
                pila_pop(pila, &tope_ptr);
                char tope = (char)(uintptr_t)tope_ptr;
                if ((c == ')' && tope != '(') ||
                    (c == ']' && tope != '[') ||
                    (c == '}' && tope != '{'))
                {
                    balanceado = false;
                }
            }
        }
    }

    if (!pila_es_vacia(pila))
    {
        balanceado = false;
    }

    pila_destruir(pila, NULL);
    return balanceado;
}

```
<!-- {code-block} c -->

La complejidad temporal del algoritmo es $O(n)$ donde $n$ representa la longitud
de la expresión, ya que se recorre la cadena mediante un único lazo. La
complejidad espacial es $O(n)$ en el peor caso de una cadena formada enteramente
por delimitadores de apertura.

:::
<!-- {solution} ejercicio-pila-validar-delimitadores -->

:::{exercise}
:label: ejercicio-pila-evaluar-postfija

Implementá una función que evalúe una expresión en notación postfija (Reverse
Polish Notation) usando una pila. Asumí que la cadena contiene números enteros
de un solo dígito y los operadores básicos `+`, `-`, `*`, `/`, separados por
espacios.

Firma de la función:
``` c
int evaluar_postfija(const char *expresion, bool *error);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-pila-evaluar-postfija
:class: dropdown

El algoritmo recorre la cadena carácter por carácter empleando un lazo. Si el
carácter actual es un número, se lo apila. Si es un operador, se desapilan los
dos operandos superiores, se realiza la operación y se apila el resultado.

Es importante recordar que el primer operando desapilado corresponde al operando
derecho ($b$) y el segundo al operando izquierdo ($a$) en operaciones no
conmutativas como la resta o la división ($a - b$ o $a / b$).

Implementación en C:

```{code-block} c
:linenos:
#include <stdint.h>
#include "pila.h"

int evaluar_postfija(const char *expresion, bool *error)
{
    if (expresion == NULL || error == NULL)
    {
        if (error != NULL) *error = true;
        return 0;
    }

    *error = false;
    pila_t *pila = pila_crear();
    if (pila == NULL)
    {
        *error = true;
        return 0;
    }

    for (size_t i = 0; expresion[i] != '\0'; i++)
    {
        char c = expresion[i];
        if (c == ' ')
        {
            continue;
        }

        if (c >= '0' && c <= '9')
        {
            int valor = c - '0';
            if (!pila_push(pila, (void*)(uintptr_t)valor))
            {
                *error = true;
                pila_destruir(pila, NULL);
                return 0;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (pila_es_vacia(pila))
            {
                *error = true;
                pila_destruir(pila, NULL);
                return 0;
            }
            void *b_ptr;
            pila_pop(pila, &b_ptr);
            int b = (int)(uintptr_t)b_ptr;

            if (pila_es_vacia(pila))
            {
                *error = true;
                pila_destruir(pila, NULL);
                return 0;
            }
            void *a_ptr;
            pila_pop(pila, &a_ptr);
            int a = (int)(uintptr_t)a_ptr;

            int resultado = 0;
            if (c == '+') resultado = a + b;
            else if (c == '-') resultado = a - b;
            else if (c == '*') resultado = a * b;
            else if (c == '/')
            {
                if (b == 0)
                {
                    *error = true;
                    pila_destruir(pila, NULL);
                    return 0;
                }
                resultado = a / b;
            }

            if (!pila_push(pila, (void*)(uintptr_t)resultado))
            {
                *error = true;
                pila_destruir(pila, NULL);
                return 0;
            }
        }
        else
        {
            *error = true;
            pila_destruir(pila, NULL);
            return 0;
        }
    }

    if (pila_es_vacia(pila))
    {
        *error = true;
        pila_destruir(pila, NULL);
        return 0;
    }

    void *resultado_final_ptr;
    pila_pop(pila, &resultado_final_ptr);
    int resultado_final = (int)(uintptr_t)resultado_final_ptr;

    if (!pila_es_vacia(pila))
    {
        *error = true;
    }

    pila_destruir(pila, NULL);
    return resultado_final;
}

```
<!-- {code-block} c -->

La complejidad temporal es lineal $O(n)$ con respecto a la longitud de la
cadena, y la complejidad espacial es $O(n)$ debido a la memoria de la pila.

:::
<!-- {solution} ejercicio-pila-evaluar-postfija -->

:::{exercise}
:label: ejercicio-cola-simulador-impresora

Diseñá un simulador de cola de impresión que procese trabajos en el orden de
llegada (FIFO) y retorne el tiempo total de procesamiento. Cada trabajo de
impresión se define mediante una estructura con su identificador y cantidad de
páginas, asumiendo que procesar una página demora 1 segundo.

Firma de la función y estructura:
``` c
typedef struct {
    int id;
    int paginas;
} trabajo_t;

int simular_impresora(trabajo_t *trabajos, size_t n);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-cola-simulador-impresora
:class: dropdown

El simulador encola todas las referencias a los trabajos del arreglo. A
continuación, mediante un lazo, desencola cada elemento para procesar el trabajo
e incrementar el acumulador de tiempo total según sus páginas.

Implementación en C:

```{code-block} c
:linenos:
#include <stdlib.h>
#include "cola.h"

int simular_impresora(trabajo_t *trabajos, size_t n)
{
    if (trabajos == NULL || n == 0)
    {
        return 0;
    }

    cola_t *cola = cola_crear();
    if (cola == NULL)
    {
        return 0;
    }

    // Encolamos las referencias a los trabajos usando un lazo.
    for (size_t i = 0; i < n; i++)
    {
        cola_enqueue(cola, &trabajos[i]);
    }

    int tiempo_total = 0;
    void *dato;

    // Desencolamos y acumulamos el tiempo en un lazo.
    while (cola_dequeue(cola, &dato))
    {
        trabajo_t *trabajo = (trabajo_t*)dato;
        tiempo_total += trabajo->paginas;
    }

    cola_destruir(cola, NULL);
    return tiempo_total;
}

```
<!-- {code-block} c -->

La complejidad temporal es $O(n)$ debido a que se encolan y desencolan $n$
elementos exactamente una vez. La complejidad espacial es $O(n)$ para mantener
la estructura interna de la cola.

:::
<!-- {solution} ejercicio-cola-simulador-impresora -->

:::{exercise}
:label: ejercicio-cola-dos-pilas

Implementá el TAD Cola utilizando como estructura de almacenamiento subyacente
dos instancias del TAD Pila. La cola debe comportarse de forma FIFO respetando
las firmas de las operaciones fundamentales.

Firma de la estructura y de las funciones:
```{code-block} c
:linenos:
typedef struct {
    pila_t *pila_entrada;
    pila_t *pila_salida;
} cola_pilas_t;

cola_pilas_t *cola_pilas_crear(void);
bool cola_pilas_enqueue(cola_pilas_t *cola, void *dato);
bool cola_pilas_dequeue(cola_pilas_t *cola, void **dato);
void cola_pilas_destruir(cola_pilas_t *cola, destruir_dato_fn destruir_dato);

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-cola-dos-pilas
:class: dropdown

La idea central es utilizar la `pila_entrada` para recibir los nuevos elementos
(`enqueue`). Al solicitar un elemento (`dequeue`), si la `pila_salida` posee
elementos, se extrae el de su tope. Si está vacía, se transfieren todos los
elementos de `pila_entrada` a `pila_salida` usando un lazo. Esta transferencia
invierte el orden LIFO de la primera pila, convirtiéndolo en FIFO en la segunda.

Implementación en C:

```{code-block} c
:linenos:
#include <stdlib.h>
#include "pila.h"

cola_pilas_t *cola_pilas_crear(void)
{
    cola_pilas_t *cola = malloc(sizeof(*cola));
    if (cola == NULL)
    {
        return NULL;
    }

    cola->pila_entrada = pila_crear();
    cola->pila_salida = pila_crear();
    if (cola->pila_entrada == NULL || cola->pila_salida == NULL)
    {
        pila_destruir(cola->pila_entrada, NULL);
        pila_destruir(cola->pila_salida, NULL);
        free(cola);
        return NULL;
    }

    return cola;
}

bool cola_pilas_enqueue(cola_pilas_t *cola, void *dato)
{
    if (cola == NULL)
    {
        return false;
    }
    return pila_push(cola->pila_entrada, dato);
}

bool cola_pilas_dequeue(cola_pilas_t *cola, void **dato)
{
    if (cola == NULL)
    {
        return false;
    }

    if (pila_es_vacia(cola->pila_salida))
    {
        // Transferimos todos los elementos de entrada a salida.
        while (!pila_es_vacia(cola->pila_entrada))
        {
            void *temp;
            pila_pop(cola->pila_entrada, &temp);
            if (!pila_push(cola->pila_salida, temp))
            {
                return false;
            }
        }
    }

    return pila_pop(cola->pila_salida, dato);
}

void cola_pilas_destruir(cola_pilas_t *cola, destruir_dato_fn destruir_dato)
{
    if (cola == NULL)
    {
        return;
    }
    pila_destruir(cola->pila_entrada, destruir_dato);
    pila_destruir(cola->pila_salida, destruir_dato);
    free(cola);
}

```
<!-- {code-block} c -->

La operación `enqueue` tiene un costo temporal de $O(1)$. La operación `dequeue`
tiene un costo temporal amortizado de $O(1)$ porque cada elemento es apilado y
desapilado un número constante de veces a lo largo de su ciclo de vida en la
estructura. La complejidad espacial es $O(n)$ donde $n$ es el número de
elementos contenidos en la cola.

:::
<!-- {solution} ejercicio-cola-dos-pilas -->

:::{exercise}
:label: ejercicio-cola-invertir-k

Escribí una función que reciba una cola y un entero $K$, e invierta el orden de
los primeros $K$ elementos de la cola, preservando el orden relativo del resto
de los elementos.

Firma de la función:
``` c
bool invertir_primeros_k(cola_t *cola, size_t k);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-cola-invertir-k
:class: dropdown

Para invertir los primeros $K$ elementos de la cola se emplea una pila auxiliar.
Primero se desencolan $K$ elementos y se los apila. Luego, se desapilan y se
encolan de nuevo (quedando al final de la cola con el orden invertido).
Finalmente, se desencolan los elementos restantes no invertidos (que ahora están
al frente) y se los encola nuevamente para mantener su posición original
relativa.

Implementación en C:

```{code-block} c
:linenos:
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

bool invertir_primeros_k(cola_t *cola, size_t k)
{
    // Asumimos que cola->tamanio nos da acceso a la cantidad de elementos.
    if (cola == NULL || k == 0 || k > cola->tamanio)
    {
        return false;
    }

    pila_t *pila = pila_crear();
    if (pila == NULL)
    {
        return false;
    }

    // Desencolamos K elementos y los apilamos.
    for (size_t i = 0; i < k; i++)
    {
        void *dato;
        cola_dequeue(cola, &dato);
        pila_push(pila, dato);
    }

    // Desapilamos y volvemos a encolar. Quedan al final con orden invertido.
    while (!pila_es_vacia(pila))
    {
        void *dato;
        pila_pop(pila, &dato);
        cola_enqueue(cola, dato);
    }

    // Reacomodamos los elementos restantes del frente llevándolos al final.
    size_t restantes = cola->tamanio - k;
    for (size_t i = 0; i < restantes; i++)
    {
        void *dato;
        cola_dequeue(cola, &dato);
        cola_enqueue(cola, dato);
    }

    pila_destruir(pila, NULL);
    return true;
}

```
<!-- {code-block} c -->

La complejidad temporal de esta solución es lineal $O(n)$ donde $n$ es la
cantidad de elementos en la cola. La complejidad espacial es $O(k)$ por los
elementos almacenados temporalmente en la pila auxiliar.

:::
<!-- {solution} ejercicio-cola-invertir-k -->

:::{exercise}
:label: ejercicio-deque-palindromo

Escribí una función que determine si una cadena de caracteres es un palíndromo
utilizando un Deque.

Firma de la función:
``` c
bool es_palindromo_deque(const char *cadena);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-deque-palindromo
:class: dropdown

El algoritmo consiste en insertar cada carácter de la cadena en el final del
deque. Luego, utilizando un lazo, se extraen caracteres del frente y del final
simultáneamente y se comparan. Si en algún momento difieren, la cadena no es un
palíndromo.

Implementación en C:

```{code-block} c
:linenos:
#include <string.h>
#include <stdint.h>
#include "deque.h"

bool es_palindromo_deque(const char *cadena)
{
    if (cadena == NULL)
    {
        return false;
    }

    size_t largo = strlen(cadena);
    if (largo <= 1)
    {
        return true;
    }

    deque_t *deque = deque_crear();
    if (deque == NULL)
    {
        return false;
    }

    // Insertamos todos los caracteres en el deque.
    for (size_t i = 0; i < largo; i++)
    {
        deque_push_back(deque, (void*)(uintptr_t)cadena[i]);
    }

    bool palindromo = true;
    // Comparamos el frente y el final usando un lazo.
    while (deque_tamanio(deque) > 1 && palindromo)
    {
        void *frente_ptr, *final_ptr;
        deque_pop_front(deque, &frente_ptr);
        deque_pop_back(deque, &final_ptr);

        char frente = (char)(uintptr_t)frente_ptr;
        char final = (char)(uintptr_t)final_ptr;

        if (frente != final)
        {
            palindromo = false;
        }
    }

    deque_destruir(deque, NULL);
    return palindromo;
}

```
<!-- {code-block} c -->

La complejidad temporal de la verificación es lineal $O(n)$ con respecto a la
longitud de la cadena. La complejidad espacial es $O(n)$ debido al
almacenamiento de los caracteres en el deque.

:::
<!-- {solution} ejercicio-deque-palindromo -->

:::{exercise}
:label: ejercicio-deque-pila

Implementá el TAD Pila utilizando únicamente las operaciones fundamentales
provistas por un Deque.

Firma de la estructura y funciones:
```{code-block} c
:linenos:
typedef struct {
    deque_t *deque;
} pila_deque_t;

pila_deque_t *pila_deque_crear(void);
bool pila_deque_push(pila_deque_t *pila, void *dato);
bool pila_deque_pop(pila_deque_t *pila, void **dato);
void pila_deque_destruir(pila_deque_t *pila, destruir_dato_fn destruir_dato);

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-deque-pila
:class: dropdown

Para emular una pila (LIFO) basta con restringir las operaciones del deque a un
solo extremo de la estructura. En este caso, realizaremos tanto la inserción
como la extracción por el final del deque.

Implementación en C:

```{code-block} c
:linenos:
#include <stdlib.h>
#include "deque.h"

pila_deque_t *pila_deque_crear(void)
{
    pila_deque_t *pila = malloc(sizeof(*pila));
    if (pila == NULL)
    {
        return NULL;
    }
    pila->deque = deque_crear();
    if (pila->deque == NULL)
    {
        free(pila);
        return NULL;
    }
    return pila;
}

bool pila_deque_push(pila_deque_t *pila, void *dato)
{
    if (pila == NULL)
    {
        return false;
    }
    return deque_push_back(pila->deque, dato);
}

bool pila_deque_pop(pila_deque_t *pila, void **dato)
{
    if (pila == NULL)
    {
        return false;
    }
    return deque_pop_back(pila->deque, dato);
}

void pila_deque_destruir(pila_deque_t *pila, destruir_dato_fn destruir_dato)
{
    if (pila == NULL)
    {
        return;
    }
    deque_destruir(pila->deque, destruir_dato);
    free(pila);
}

```
<!-- {code-block} c -->

Tanto `push` como `pop` heredan la complejidad temporal de $O(1)$ del Deque. La
complejidad espacial es $O(n)$ en función del número de elementos contenidos.

:::
<!-- {solution} ejercicio-deque-pila -->

:::{exercise}
:label: ejercicio-deque-ventana-deslizante

Dado un arreglo de enteros y un tamaño de ventana $K$, diseñá una función que
encuentre el valor máximo en cada ventana deslizante de tamaño $K$ a medida que
se desplaza de izquierda a derecha. Utilizá un Deque para almacenar índices de
manera que se logre una complejidad temporal lineal óptima de $O(n)$.

Firma de la función:
``` c
int *maximos_ventana_deslizante(const int *arreglo, size_t n, size_t k, size_t *resultado_tamanio);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-deque-ventana-deslizante
:class: dropdown

El deque mantendrá los índices de los elementos útiles dentro de la ventana
actual. En cada paso del lazo principal, se remueven del frente del deque los
índices de elementos que ya están fuera de la ventana. Luego, se remueven del
final los índices de elementos que son menores o iguales al elemento actual, ya
que no podrán volver a ser el máximo. Finalmente, se inserta el índice actual en
el final del deque y se reporta el elemento del frente como máximo de la
ventana.

Implementación en C:

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdint.h>
#include "deque.h"

int *maximos_ventana_deslizante(const int *arreglo, size_t n, size_t k, size_t *resultado_tamanio)
{
    if (arreglo == NULL || n == 0 || k == 0 || k > n || resultado_tamanio == NULL)
    {
        if (resultado_tamanio != NULL) *resultado_tamanio = 0;
        return NULL;
    }

    *resultado_tamanio = n - k + 1;
    int *resultado = malloc((*resultado_tamanio) * sizeof(*resultado));
    if (resultado == NULL)
    {
        *resultado_tamanio = 0;
        return NULL;
    }

    deque_t *deque = deque_crear();
    if (deque == NULL)
    {
        free(resultado);
        *resultado_tamanio = 0;
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        // 1. Removemos del frente los índices que ya quedaron fuera de la ventana.
        void *frente_ptr;
        while (deque_tamanio(deque) > 0)
        {
            deque_peek_front(deque, &frente_ptr);
            size_t indice_frente = (size_t)(uintptr_t)frente_ptr;
            if (indice_frente <= i - k)
            {
                deque_pop_front(deque, NULL);
            }
            else
            {
                break;
            }
        }

        // 2. Removemos del final elementos menores o iguales al elemento actual.
        void *final_ptr;
        while (deque_tamanio(deque) > 0)
        {
            deque_peek_back(deque, &final_ptr);
            size_t indice_final = (size_t)(uintptr_t)final_ptr;
            if (arreglo[indice_final] <= arreglo[i])
            {
                deque_pop_back(deque, NULL);
            }
            else
            {
                break;
            }
        }

        // 3. Agregamos el índice actual.
        deque_push_back(deque, (void*)(uintptr_t)i);

        // 4. Agregamos el máximo actual a los resultados (el máximo siempre está en el frente del deque).
        if (i >= k - 1)
        {
            void *max_ptr;
            deque_peek_front(deque, &max_ptr);
            size_t max_indice = (size_t)(uintptr_t)max_ptr;
            resultado[i - k + 1] = arreglo[max_indice];
        }
    }

    deque_destruir(deque, NULL);
    return resultado;
}

```
<!-- {code-block} c -->

Dado que cada índice del arreglo se inserta y extrae del deque como máximo una
vez, el tiempo consumido por las operaciones internas del deque a lo largo de
todo el proceso está acotado por $O(n)$, logrando una complejidad temporal
óptima de $O(n)$. La complejidad espacial es $O(k)$ para almacenar los índices
dentro del deque.

:::
<!-- {solution} ejercicio-deque-ventana-deslizante -->

## Glosario

:::{glossary}

TAD (Tipo Abstracto de Datos)
: Modelo matemático para tipos de datos definidos por su comportamiento y
operaciones.

Pila (Stack)
: Estructura de datos LIFO.

Cola (Queue)
: Estructura de datos FIFO.

Encapsulación
: Ocultamiento de la representación de datos del cliente.

:::
<!-- {glossary} -->

## Síntesis y Resumen

(7_tad_pilas_colas-resumen)=
### Resumen


Los Tipos de Datos Abstractos son una herramienta fundamental para construir
software modular y mantenible. En este apunte hemos cubierto:

- **El concepto de TAD** y la separación entre interfaz e implementación.
- **El TAD Secuencia** como abstracción fundamental, demostrando cómo la misma
  interfaz puede implementarse con diferentes estructuras de datos.
- **Dos implementaciones de Secuencia:**
  - Arreglos dinámicos: excelentes para acceso aleatorio y localidad de caché.
  - Listas enlazadas: ideales para inserciones/eliminaciones dinámicas.
- La diferencia entre **memoria estática y dinámica**, y cuándo usar cada una
  (para detalles completos, consultá {ref}`capitulo-memoria-dinamica`).
- **Listas enlazadas** simples, dobles y circulares, con todas sus operaciones
  fundamentales.
- **Pilas (LIFO)** y **Colas (FIFO)** como TADs especializados:
  - Múltiples implementaciones (lista enlazada, arreglo, arreglo circular)
  - Aplicaciones prácticas en sistemas y algoritmos
  - Análisis de complejidad temporal y espacial
- **Consideraciones de implementación:** manejo de errores, invariantes y
  seguridad.
- **Análisis de complejidad temporal** de las operaciones en diferentes
  implementaciones (para el fundamento teórico completo, consultá
  {ref}`capitulo-complejidad`).
- **Panorama general** de estructuras de datos avanzadas y su clasificación.

:::{important} Lección Clave: Múltiples Implementaciones

El concepto más importante de este apunte es que **un mismo TAD puede tener
múltiples implementaciones**, cada una con diferentes características de
rendimiento. La elección de la implementación correcta depende del contexto de
uso, y el poder de la abstracción permite cambiar entre implementaciones sin
reescribir el código cliente.

Las pilas y colas demuestran este principio perfectamente: ambas pueden
implementarse con listas enlazadas o arreglos, y la elección depende de los
requisitos específicos de rendimiento y uso de memoria.

:::
<!-- {important} Lección Clave: Múltiples Implementaciones -->

:::{tip}

Dominar estas estructuras de datos es esencial para avanzar hacia estructuras
más complejas como árboles, grafos y tablas de hash, que se construyen sobre
estos fundamentos. La correcta gestión de memoria dinámica, tema central en este
apunte, es la base para implementar cualquier estructura de datos compleja de
manera segura y eficiente.

:::
<!-- {tip} -->

## Referencias y Lecturas de Pilas y Colas

(referencias-lecturas-pilas-colas)=
### Referencias y Lecturas de Pilas y Colas


Para profundizar en el estudio de los TADs y estructuras de datos, se
recomiendan las siguientes referencias:

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).
  *Introduction to Algorithms* (3rd ed.). MIT Press.
- Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C* (2nd ed.).
  Pearson.
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley.

Para aspectos específicos de gestión de memoria y su impacto en la
implementación de TADs, consultá:

- {ref}`capitulo-memoria-dinamica` para entender el modelo de memoria completo.
- {ref}`resumen-de-buenas-practicas` para patrones seguros de manejo de memoria
  dinámica.
- [Capítulo: Memoria Dinámica — sección Valgrind](1_memoria_dinamica.md) para
  técnicas de depuración de estructuras dinámicas.

:::{tip}

La implementación de TADs es una habilidad fundamental que requiere práctica. Te
recomendamos implementar cada estructura desde cero al menos una vez, probando
exhaustivamente cada operación con casos de prueba variados. Usá herramientas
como Valgrind durante el desarrollo para detectar fugas de memoria
tempranamente.

:::
<!-- {tip} -->
