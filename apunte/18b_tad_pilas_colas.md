---
title: 'Pilas, Colas y Estructuras Lineales Restringidas'
short_title: '18b - Pilas y Colas'
subtitle: 'TAD Pila, Cola y Deque'
---

(pilas-colas-capitulo)=
## Pilas (Stacks)

Una **pila** es una estructura de datos lineal que sigue el principio **LIFO** (*Last In, First Out*): el último elemento en entrar es el primero en salir. Es análogo a una pila de platos donde solo podés agregar o quitar platos desde la parte superior.

```{figure} 18/pila_stack.svg
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

```{figure} 18/pila_lista_enlazada.svg
:label: fig-pila-lista
:align: center

Representación en memoria de una pila implementada con lista enlazada. El tope apunta al primer nodo de la lista.
```

#### Estructura de Datos

```{code-block}c
:linenos:
typedef struct nodo {
    void *dato;
    struct nodo *siguiente;
} nodo_t;

struct pila {
    nodo_t *tope;
    size_t tamanio;
};
```

#### Creación de una Pila

```{code-block}c
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
```

#### Apilar (Push)

```{code-block}c
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
```

:::{note}
La operación `pila_push` es equivalente a realizar una inserción al inicio en una lista enlazada, siendo el tope de la pila el primer elemento de la lista.
:::

#### Desapilar (Pop)

```{code-block}c
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
```

#### Ver Tope (Peek)

```{code-block}c
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
```

#### Verificar si está Vacía

```{code-block}c
:linenos:
bool pila_es_vacia(const pila_t *pila)
{
    return (pila == NULL) || (pila->tope == NULL);
}
```

#### Destruir Pila

```{code-block}c
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
```

:::{important}
Es fundamental liberar toda la memoria utilizada, recorriendo la lista y liberando cada nodo antes de liberar la estructura de la pila.
:::

### Análisis de Complejidad (Lista Enlazada)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| push | $O(1)$ | $O(1)$ |
| pop | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

### Implementación con Arreglo Dinámico

Una alternativa es implementar la pila usando un arreglo, donde el tope es el último elemento ocupado.

```{figure} 18/pila_arreglo.svg
:label: fig-pila-arreglo
:align: center

Pila implementada con arreglo. El índice `tope` indica la posición del último elemento.
```

#### Estructura de Datos

```{code-block}c
:linenos:
struct pila {
    void **elementos;
    size_t tope;       // Próximo índice libre / Cantidad de elementos
    size_t capacidad;  // Capacidad total del arreglo
};
```

#### Creación con Capacidad Inicial

```{code-block}c
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
```

#### Apilar con Redimensionamiento

```{code-block}c
:linenos:
static bool pila_redimensionar(pila_t *pila)
{
    size_t nueva_capacidad = pila->capacidad * 2;
    void **nuevo_arreglo = realloc(pila->elementos, nueva_capacidad * sizeof(*nuevo_arreglo));
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
```

:::{tip}
El factor de redimensionamiento (comúnmente 2) es importante. Duplicar la capacidad garantiza que el costo amortizado de `pila_push_arreglo` sea $O(1)$, aunque un `push` individual pueda ser $O(n)$ cuando requiere redimensionar. Para entender cómo se calcula formalmente el análisis amortizado usando el método del banquero o el método del potencial, consultá la sección sobre análisis amortizado en {ref}`complejidad-introduccion`.
:::

#### Desapilar (Arreglo)

```{code-block}c
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
```

### Análisis de Complejidad (Arreglo)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| push | $O(1)$ amortizado | $O(1)$ |
| pop | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

:::{note}
Aunque `push` puede ser $O(n)$ cuando requiere redimensionar, el análisis amortizado muestra que en promedio sigue siendo $O(1)$. Este tipo de análisis es crucial para estructuras de datos dinámicas y se estudia en profundidad en {ref}`complejidad-introduccion`.
:::

### Aplicaciones de Pilas

Las pilas aparecen naturalmente en numerosos contextos de programación:

1. **Gestión de llamadas a funciones:** La pila de ejecución (*call stack*) mantiene los registros de activación.
2. **Evaluación de expresiones:** Conversión de notación infija a postfija, evaluación de expresiones postfijas.
3. **Backtracking:** Algoritmos de búsqueda en profundidad, resolución de laberintos.
4. **Deshacer/Rehacer:** Editores de texto mantienen pilas de operaciones.
5. **Parsing:** Análisis sintáctico de lenguajes de programación (verificación de paréntesis balanceados).

#### Ejemplo: Verificación de Paréntesis Balanceados

```{code-block}c
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
```

## Colas (Queues)

Una **cola** es una estructura de datos lineal que sigue el principio **FIFO** (*First In, First Out*): el primer elemento en entrar es el primero en salir. Es análogo a una fila de personas donde quien llega primero es atendido primero.

```{figure} 18/cola_lista_enlazada.svg
:label: fig-cola-lista
:align: center

Representación en memoria de una cola implementada con lista enlazada. Se mantienen punteros al frente y al final.
```

#### Estructura de Datos

```{code-block}c
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
```

::::{note}
A diferencia de la pila que solo requiere de un puntero al tope, la cola utiliza dos punteros: uno al frente (para `cola_dequeue`) y otro al final (para `cola_enqueue`). Esto garantiza que ambas operaciones se ejecuten en tiempo constante $O(1)$.
:::

#### Creación de una Cola

```{code-block}c
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
```

#### Encolar (Enqueue)

```{code-block}c
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
```

:::{important}
Es indispensable considerar el caso particular de la cola vacía. En tal situación, tanto el puntero `frente` como el puntero `final` deben referenciar al nuevo nodo creado.
:::

#### Desencolar (Dequeue)

```{code-block}c
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
```

:::{important}
Al extraer el último elemento de la cola, esta queda vacía. En ese escenario, además de actualizar el puntero `frente` a `NULL`, es necesario establecer el puntero `final` en `NULL`.
:::

#### Ver Frente (Peek)

```{code-block}c
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
```

#### Destruir Cola

```{code-block}c
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
```

### Análisis de Complejidad (Lista Enlazada)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| enqueue | $O(1)$ | $O(1)$ |
| dequeue | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

### Implementación con Arreglo Circular

Una implementación eficiente de cola con arreglo usa la técnica de **arreglo circular**, donde los índices "dan la vuelta" al final del arreglo.

```{figure} 18/cola_circular.svg
:label: fig-cola-circular
:align: center

Cola implementada como arreglo circular. Los índices se calculan módulo la capacidad.
```

#### Estructura de Datos

```{code-block}c
:linenos:
struct cola {
    void **elementos;
    size_t frente;
    size_t final;
    size_t tamanio;
    size_t capacidad;
};
```

:::{note}
En esta implementación con arreglo circular, el índice `final` apunta a la posición **después** del último elemento. Esto simplifica la lógica de detección de cola vacía o llena.
:::

#### Creación de Cola Circular

```{code-block}c
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
```

#### Encolar en Arreglo Circular

```{code-block}c
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
```

:::{tip}
El operador módulo `%` permite que el índice "dé la vuelta". Por ejemplo, si `capacidad = 5` y `final = 4`, entonces `(4 + 1) % 5 = 0`, retornando al inicio del arreglo.
:::

#### Desencolar en Arreglo Circular

```{code-block}c
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
```

:::{important}
Al redimensionar, es crucial copiar los elementos en el orden secuencial correcto (frente a final), considerando que el frente puede no estar alineado en la posición 0 del arreglo original.
:::

### Análisis de Complejidad (Arreglo Circular)

| Operación | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| enqueue | $O(1)$ amortizado | $O(1)$ |
| dequeue | $O(1)$ | $O(1)$ |
| peek | $O(1)$ | $O(1)$ |
| es_vacia | $O(1)$ | $O(1)$ |

### Aplicaciones de Colas

Las colas modelan situaciones donde el orden de llegada importa:

1. **Sistemas operativos:** Scheduling de procesos, colas de impresión.
2. **Redes:** Buffers de transmisión, enrutamiento de paquetes.
3. **Algoritmos de grafos:** Búsqueda en anchura (BFS).
4. **Simulaciones:** Modelado de filas de espera, teoría de colas.
5. **Procesamiento asíncrono:** Cola de tareas, sistemas de mensajería.

## Comparación: Pilas vs Colas

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
Ambas estructuras son especializaciones del TAD Secuencia con restricciones de acceso. La restricción no es una limitación, sino una garantía que simplifica el razonamiento sobre el código.
:::

## Deques (Double-Ended Queues)

Un **deque** (pronunciado "deck") es una generalización que permite insertar y extraer elementos en ambos extremos.

```{figure} 18/deque.svg
:label: fig-deque
:align: center

Deque con operaciones en ambos extremos. Es una generalización de pilas y colas.
```

### Operaciones

- **push_front(elemento):** Agrega al frente.
- **push_back(elemento):** Agrega al final.
- **pop_front():** Extrae del frente.
- **pop_back():** Extrae del final.

:::{note}
Un deque puede simular tanto una pila (usando solo un extremo) como una cola (usando ambos extremos de forma restringida). Es más general pero potencialmente más difícil de razonar sobre su uso.
:::

### Aplicaciones de Deques

- **Algoritmos de ventana deslizante:** Mantener mínimos/máximos en una ventana.
- **Navegación con historial:** Forward/backward en navegadores.
- **Work stealing:** Algoritmos paralelos donde los threads roban tareas de ambos extremos.

## Comparación de Implementaciones

### Lista Enlazada vs Arreglo

| Criterio | Lista Enlazada | Arreglo (Circular) |
|----------|---------------|-------------------|
| **Memoria** | Overhead por punteros | Compacta, localidad de caché |
| **Tamaño** | Dinámico sin límite | Requiere redimensionamiento |
| **Operaciones** | Siempre $O(1)$ | $O(1)$ amortizado |
| **Complejidad código** | Media | Alta (aritmética modular) |
| **Uso típico** | Tamaño impredecible | Tamaño acotado |

:::{tip}
Para aplicaciones donde el rendimiento es crítico y el tamaño máximo es conocido, la implementación con arreglo circular es preferible por su mejor localidad de caché. Para tamaños muy variables o cuando la simplicidad del código importa más que el rendimiento, la lista enlazada es más apropiada.
:::

## Panorama de Estructuras de Datos

Las pilas y colas son solo el comienzo. Existe un ecosistema rico de estructuras de datos, cada una optimizada para diferentes patrones de acceso.

### Clasificación por Restricciones de Acceso

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

### Estructuras Avanzadas

**Árboles:**
- **Heap (Montículo):** Cola de prioridad eficiente, $O(\log n)$ insert/extract-min
- **BST (Binary Search Tree):** Búsqueda, inserción, eliminación en $O(\log n)$ promedio
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
Cada estructura de datos representa un compromiso (*trade-off*) entre tiempo de operaciones, espacio usado y complejidad de implementación. No existe la "mejor" estructura, solo la más apropiada para cada contexto. Para comprender cómo comparar formalmente estructuras de datos usando análisis de complejidad, consultá {ref}`complejidad-introduccion`.
:::

## Ejercicios de Pilas y Colas

### Ejercicio 1: Inversión de una Cadena con Pila

:::{exercise}
:label: ejercicio-invertir-cadena

Implementá una función que use una pila para invertir una cadena de caracteres.

```text
función invertir_cadena(cadena: cadena) → cadena:
    // Tu implementación aquí
```

Por ejemplo:
- Entrada: "hola"
- Salida: "aloh"
:::

### Ejercicio 2: Validar Expresiones con Múltiples Delimitadores

:::{exercise}
:label: ejercicio-validar-delimitadores

Extendé el ejemplo de paréntesis balanceados para soportar múltiples tipos de delimitadores: `()`, `[]`, `{}`. La función debe verificar que:
1. Cada apertura tenga su cierre correspondiente
2. Los cierres ocurran en el orden correcto

```text
función delimitadores_balanceados(expresion: cadena) → booleano:
    // Tu implementación aquí
```

Por ejemplo:
- `"{[()]}"` → válido
- `"{[(])}"` → inválido (cierre en orden incorrecto)
- `"{[("` → inválido (sin cerrar)
:::

### Ejercicio 3: Simulador de Impresora

:::{exercise}
:label: ejercicio-simulador-impresora

Implementá un simulador de cola de impresión que:
1. Reciba trabajos con un identificador y cantidad de páginas
2. Procese trabajos en orden FIFO
3. Reporte el tiempo total de procesamiento (asumí 1 segundo por página)

```text
Trabajo:
    id: entero
    paginas: entero

función simular_impresora(trabajos: arreglo de Trabajo) → entero:
    // Retorna tiempo total de procesamiento
```
:::

### Ejercicio 4: Implementar Cola con Dos Pilas

:::{exercise}
:label: ejercicio-cola-dos-pilas

Implementá una cola usando dos pilas. La idea es:
- Una pila para `enqueue` (entrada)
- Una pila para `dequeue` (salida)
- Cuando la pila de salida está vacía, transferir todos los elementos de entrada a salida

```text
Cola_con_Pilas:
    pila_entrada: Pila
    pila_salida: Pila

función enqueue_con_pilas(cola: Cola_con_Pilas, dato: entero) → booleano:
    // Tu implementación

función dequeue_con_pilas(cola: Cola_con_Pilas, dato: referencia a entero) → booleano:
    // Tu implementación
```

Analizá la complejidad amortizada de las operaciones.
:::

### Ejercicio 5: Evaluación de Expresiones Postfijas

:::{exercise}
:label: ejercicio-evaluar-postfija

Implementá un evaluador de expresiones en notación postfija (Reverse Polish Notation) usando una pila.

En notación postfija, los operadores vienen después de los operandos:
- Infija: `(3 + 4) * 5`
- Postfija: `3 4 + 5 *`

Algoritmo:
1. Recorrer la expresión
2. Si es número, apilar
3. Si es operador, desapilar dos operandos, aplicar operación, apilar resultado

```text
función evaluar_postfija(expresion: cadena) → entero:
    // Tu implementación
```

Por ejemplo:
- `"3 4 + 5 *"` → 35
- `"15 7 1 1 + - / 3 * 2 1 1 + + -"` → 5
:::

## Referencias y Lecturas Complementarias

Para profundizar en el estudio de los TADs y estructuras de datos, se recomiendan las siguientes referencias:

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
- Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C* (2nd ed.). Pearson.
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley.

Para aspectos específicos de gestión de memoria y su impacto en la implementación de TADs, consultá:

- {ref}`memoria-dinamica-capitulo` para entender el modelo de memoria completo.
- {ref}`memoria-buenas-practicas` para patrones seguros de manejo de memoria dinámica.
- [Capítulo: Memoria Dinámica — sección Valgrind](14_memoria_dinamica.md) para técnicas de depuración de estructuras dinámicas.

:::{tip}
La implementación de TADs es una habilidad fundamental que requiere práctica. Te recomendamos implementar cada estructura desde cero al menos una vez, probando exhaustivamente cada operación con casos de prueba variados. Usá herramientas como Valgrind durante el desarrollo para detectar fugas de memoria tempranamente.
:::

## Resumen

Los Tipos de Datos Abstractos son una herramienta fundamental para construir software modular y mantenible. En este apunte hemos cubierto:

- **El concepto de TAD** y la separación entre interfaz e implementación.
- **El TAD Secuencia** como abstracción fundamental, demostrando cómo la misma interfaz puede implementarse con diferentes estructuras de datos.
- **Dos implementaciones de Secuencia:**
  - Arreglos dinámicos: excelentes para acceso aleatorio y localidad de caché.
  - Listas enlazadas: ideales para inserciones/eliminaciones dinámicas.
- La diferencia entre **memoria estática y dinámica**, y cuándo usar cada una (para detalles completos, consultá {ref}`memoria-dinamica-capitulo`).
- **Listas enlazadas** simples, dobles y circulares, con todas sus operaciones fundamentales.
- **Pilas (LIFO)** y **Colas (FIFO)** como TADs especializados:
  - Múltiples implementaciones (lista enlazada, arreglo, arreglo circular)
  - Aplicaciones prácticas en sistemas y algoritmos
  - Análisis de complejidad temporal y espacial
- **Consideraciones de implementación:** manejo de errores, invariantes y seguridad.
- **Análisis de complejidad temporal** de las operaciones en diferentes implementaciones (para el fundamento teórico completo, consultá {ref}`complejidad-introduccion`).
- **Panorama general** de estructuras de datos avanzadas y su clasificación.

:::{important} Lección Clave: Múltiples Implementaciones

El concepto más importante de este apunte es que **un mismo TAD puede tener múltiples implementaciones**, cada una con diferentes características de rendimiento. La elección de la implementación correcta depende del contexto de uso, y el poder de la abstracción permite cambiar entre implementaciones sin reescribir el código cliente.

Las pilas y colas demuestran este principio perfectamente: ambas pueden implementarse con listas enlazadas o arreglos, y la elección depende de los requisitos específicos de rendimiento y uso de memoria.
:::

:::{tip}
Dominar estas estructuras de datos es esencial para avanzar hacia estructuras más complejas como árboles, grafos y tablas de hash, que se construyen sobre estos fundamentos. La correcta gestión de memoria dinámica, tema central en este apunte, es la base para implementar cualquier estructura de datos compleja de manera segura y eficiente.
:::