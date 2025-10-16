---
title: Pilas y Colas
short_title: 14 - Pilas y Colas
subtitle: Estructuras de datos lineales con restricciones de acceso
---

## Introducción

Las **pilas** y **colas** son Tipos de Datos Abstractos (TADs) que restringen el acceso a los elementos de una colección siguiendo políticas específicas. A diferencia de las secuencias generales, donde podés acceder a cualquier elemento, estas estructuras imponen reglas sobre qué elementos pueden ser accedidos y en qué orden.

Estas restricciones no son limitaciones arbitrarias, sino que reflejan patrones de uso muy comunes en programación y sistemas de computación. Al modelar explícitamente estos patrones mediante TADs especializados, el código se vuelve más claro y menos propenso a errores.

:::{important}
Tanto pilas como colas pueden implementarse usando las estructuras que ya conocemos (listas enlazadas o arreglos), demostrando nuevamente el poder de la abstracción: diferentes TADs pueden compartir implementaciones subyacentes.
:::

## Pilas (Stacks)

Una **pila** es una estructura de datos lineal que sigue el principio **LIFO** (*Last In, First Out*): el último elemento en entrar es el primero en salir. Es análogo a una pila de platos donde solo podés agregar o quitar platos desde la parte superior.

```{figure} 13/pila_stack.svg
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

```{figure} 13/cola_queue.svg
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

#### Ventajas

- Uso eficiente de memoria: no requiere desplazar elementos.
- Operaciones $O(1)$ tanto para encolar como desencolar.

#### Desventajas

- Capacidad fija (a menos que se implemente redimensionamiento).
- Mayor complejidad en la lógica de envolvimiento.

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

Para aspectos de implementación y gestión de memoria:

- {ref}`memoria-introduccion` para entender el modelo de memoria completo.
- {ref}`memoria-buenas-practicas` para patrones seguros de manejo de memoria dinámica.

## Resumen

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

:::{important} Implementación como Abstracción

Tanto pilas como colas pueden implementarse usando listas enlazadas o arreglos, demostrando que son abstracciones independientes de la implementación subyacente. La elección de implementación depende de las necesidades específicas del sistema.
:::

Estas estructuras son fundamentales para construir sistemas más complejos y aparecen constantemente en algoritmos y aplicaciones del mundo real.
