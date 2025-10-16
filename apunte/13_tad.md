---
title: Tipos de Datos Abstractos
short_title: 13 - TAD
subtitle: Estructuras de datos dinámicas y su implementación en C
---

## Introducción

Un **Tipo de Dato Abstracto** (TAD, del inglés *Abstract Data Type*, ADT) es un modelo matemático que define un conjunto de datos junto con las operaciones que pueden realizarse sobre ellos, ocultando los detalles de su implementación. El concepto de TAD es fundamental en la ciencia de la computación porque establece una separación clara entre **qué** hace una estructura de datos (su interfaz) y **cómo** lo hace (su implementación).

Esta abstracción permite que el usuario de la estructura se concentre en resolver problemas de alto nivel sin preocuparse por los detalles internos de cómo se almacenan o manipulan los datos. Al mismo tiempo, el implementador tiene la libertad de optimizar o modificar la representación interna sin afectar al código que utiliza el TAD, siempre que mantenga la misma interfaz pública.

```{figure} 13/tad_concepto.svg
:label: fig-tad-concepto
:align: center

Separación entre interfaz y implementación en un TAD. La barrera de abstracción protege los detalles internos.
```

### Características de un TAD

Un TAD se caracteriza por tres componentes esenciales:

1. **Representación de datos:** Estructura interna que almacena la información (oculta al usuario).
2. **Operaciones:** Conjunto de funciones que manipulan los datos de manera controlada.
3. **Axiomas o invariantes:** Propiedades que deben cumplirse en todo momento para garantizar la coherencia de la estructura.

### Encapsulamiento y Abstracción

El principio de **encapsulamiento** implica que los datos internos de un TAD no deben ser accesibles directamente desde el exterior. En C, esto se logra mediante el uso de punteros opacos y la separación entre archivos de cabecera (`.h`) que exponen la interfaz, y archivos de implementación (`.c`) que contienen los detalles internos.

:::{important}
La abstracción no es solo ocultar información, sino proporcionar una interfaz clara y coherente que permita utilizar la estructura de datos de manera intuitiva y segura.
:::

## Asignación de Memoria: Estática vs. Dinámica

Antes de implementar estructuras de datos dinámicas, es crucial comprender la diferencia entre memoria estática y dinámica, ya que las estructuras que estudiaremos requieren asignación dinámica.

```{figure} 13/memoria_estatica_dinamica.svg
:label: fig-memoria-estatica-dinamica
:align: center

Comparación entre asignación de memoria estática (en el stack) y dinámica (en el heap).
```

### Memoria Estática

La memoria estática se asigna en el **stack** (pila de llamadas) durante la compilación o al momento de declarar una variable. Sus características son:

- **Tamaño fijo:** Debe conocerse en tiempo de compilación.
- **Duración:** Existe mientras el ámbito de la variable esté activo.
- **Liberación automática:** Se libera al salir del ámbito.
- **Rápida:** El acceso es directo y eficiente.
- **Limitada:** El stack tiene un tamaño máximo (típicamente 1-8 MB).

```c
void funcion(void)
{
    int numeros[100];        // 400 bytes en el stack
    char nombre[50];         // 50 bytes en el stack
    
    // Al finalizar la función, la memoria se libera automáticamente
}
```

### Memoria Dinámica

La memoria dinámica se asigna en el **heap** (montículo) durante la ejecución del programa mediante funciones como `malloc`, `calloc` o `realloc`. Sus características son:

- **Tamaño flexible:** Puede determinarse en tiempo de ejecución.
- **Duración:** Persiste hasta que se libere explícitamente con `free`.
- **Liberación manual:** El programador es responsable de liberar la memoria.
- **Mayor capacidad:** El heap es mucho más grande que el stack.
- **Acceso mediante punteros:** Se requieren punteros para acceder a la memoria asignada.

```c
void procesar_datos(int cantidad)
{
    // Asignar memoria dinámica según cantidad
    int* numeros = malloc(cantidad * sizeof(int));
    
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria\n");
        return;
    }
    
    // Usar el arreglo...
    
    // IMPORTANTE: Liberar la memoria cuando ya no se necesita
    free(numeros);
    numeros = NULL;  // Buena práctica: evitar punteros colgantes
}
```

:::{warning}
No liberar la memoria dinámica asignada produce **fugas de memoria** (*memory leaks*), donde la memoria se pierde hasta que el programa termine. Esto puede agotar los recursos del sistema.
:::

### ¿Cuándo usar cada tipo?

- **Memoria estática:** Cuando el tamaño es conocido, pequeño y constante.
- **Memoria dinámica:** Cuando el tamaño depende de la entrada del usuario, es grande, o varía durante la ejecución.

:::{tip} Aplicación de {ref}`(0x0003h)`

Siempre debés inicializar los punteros, preferentemente a `NULL`, y verificar que `malloc` no retorne `NULL` antes de usar la memoria asignada.
:::

## Listas Enlazadas

Una **lista enlazada** es una estructura de datos lineal donde cada elemento (nodo) contiene un dato y una referencia (puntero) al siguiente elemento. A diferencia de los arreglos, los nodos de una lista enlazada no necesitan estar almacenados en posiciones contiguas de memoria, lo que permite inserciones y eliminaciones eficientes.

### Ventajas y Desventajas

**Ventajas:**
- Tamaño dinámico: crece y decrece según las necesidades.
- Inserción y eliminación eficientes ($O(1)$ si tenemos la referencia al nodo).
- No requiere reorganización al insertar o eliminar elementos.

**Desventajas:**
- Acceso secuencial: no hay acceso directo por índice ($O(n)$).
- Mayor uso de memoria por los punteros adicionales.
- Menos eficiente en caché debido a la no contigüidad en memoria.

### Lista Enlazada Simple

En una lista enlazada simple, cada nodo apunta únicamente al siguiente nodo de la secuencia. El último nodo apunta a `NULL`, indicando el final de la lista.

```{figure} 13/lista_enlazada_simple.svg
:label: fig-lista-simple
:align: center

Estructura de una lista enlazada simple. Cada nodo contiene datos y un puntero al siguiente nodo.
```

#### Estructura de un Nodo

```c
typedef struct Nodo
{
    int dato;              // Campo de datos (puede ser cualquier tipo)
    struct Nodo* siguiente; // Puntero al siguiente nodo
} Nodo;

typedef struct Lista
{
    Nodo* inicio;          // Puntero al primer nodo
    size_t tamanio;        // Cantidad de elementos (opcional, pero útil)
} Lista;
```

:::{note}
Observá el uso de `struct Nodo*` dentro de la definición de `Nodo`. Esto es válido porque el compilador solo necesita saber que `siguiente` es un puntero, cuyo tamaño es conocido independientemente del tipo completo de `Nodo`.
:::

#### Creación de una Lista Vacía

```c
Lista* crear_lista(void)
{
    Lista* lista = malloc(sizeof(Lista));
    
    if (lista == NULL)
    {
        return NULL;
    }
    
    lista->inicio = NULL;
    lista->tamanio = 0;
    
    return lista;
}
```

:::{tip} Aplicación de {ref}`(0x0001h)`

El nombre `crear_lista` es descriptivo y refleja claramente la operación que realiza. Evitar nombres genéricos como `crear` o `nueva`.
:::

#### Inserción al Inicio

La inserción al inicio es una operación $O(1)$ porque no requiere recorrer la lista.

```c
bool insertar_al_inicio(Lista* lista, int dato)
{
    if (lista == NULL)
    {
        return false;
    }
    
    // Crear el nuevo nodo
    Nodo* nuevo = malloc(sizeof(Nodo));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    // Configurar el nuevo nodo
    nuevo->dato = dato;
    nuevo->siguiente = lista->inicio;
    
    // Actualizar el inicio de la lista
    lista->inicio = nuevo;
    lista->tamanio++;
    
    return true;
}
```

#### Inserción al Final

La inserción al final requiere recorrer toda la lista para encontrar el último nodo ($O(n)$).

```c
bool insertar_al_final(Lista* lista, int dato)
{
    if (lista == NULL)
    {
        return false;
    }
    
    // Crear el nuevo nodo
    Nodo* nuevo = malloc(sizeof(Nodo));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    // Si la lista está vacía, el nuevo nodo es el inicio
    if (lista->inicio == NULL)
    {
        lista->inicio = nuevo;
    }
    else
    {
        // Recorrer hasta el último nodo
        Nodo* actual = lista->inicio;
        
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        
        actual->siguiente = nuevo;
    }
    
    lista->tamanio++;
    return true;
}
```

:::{important}
Una optimización común es mantener un puntero adicional `fin` en la estructura `Lista` que apunte al último nodo, reduciendo la inserción al final a $O(1)$.
:::

#### Búsqueda

```c
Nodo* buscar(const Lista* lista, int dato)
{
    if (lista == NULL)
    {
        return NULL;
    }
    
    Nodo* actual = lista->inicio;
    
    while (actual != NULL)
    {
        if (actual->dato == dato)
        {
            return actual;
        }
        
        actual = actual->siguiente;
    }
    
    return NULL;  // No encontrado
}
```

:::{tip} Aplicación de {ref}`(0x0000h)`

El uso de `const Lista*` indica que la función no modifica la lista, mejorando la claridad del código.
:::

#### Eliminación

La eliminación de un nodo requiere mantener una referencia al nodo anterior para poder actualizar su puntero `siguiente`.

```c
bool eliminar(Lista* lista, int dato)
{
    if (lista == NULL || lista->inicio == NULL)
    {
        return false;
    }
    
    Nodo* actual = lista->inicio;
    Nodo* anterior = NULL;
    
    // Buscar el nodo a eliminar
    while (actual != NULL && actual->dato != dato)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Si no se encontró el nodo
    if (actual == NULL)
    {
        return false;
    }
    
    // Si el nodo a eliminar es el primero
    if (anterior == NULL)
    {
        lista->inicio = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
    lista->tamanio--;
    
    return true;
}
```

#### Recorrido

```c
void imprimir_lista(const Lista* lista)
{
    if (lista == NULL)
    {
        return;
    }
    
    Nodo* actual = lista->inicio;
    
    printf("Lista: ");
    
    while (actual != NULL)
    {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    
    printf("\n");
}
```

#### Destrucción de la Lista

Es fundamental liberar toda la memoria asignada para evitar fugas.

```c
void destruir_lista(Lista* lista)
{
    if (lista == NULL)
    {
        return;
    }
    
    Nodo* actual = lista->inicio;
    
    while (actual != NULL)
    {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
}
```

:::{warning}
Nunca accedas a un nodo después de haberlo liberado con `free`. Por eso guardamos `siguiente` antes de liberar `actual`.
:::

```{figure} 13/lista_operaciones.svg
:label: fig-lista-operaciones
:align: center

Operaciones fundamentales en listas enlazadas: inserción, eliminación, búsqueda y recorrido.
```

### Lista Doblemente Enlazada

Una lista doblemente enlazada extiende la lista simple agregando un puntero adicional en cada nodo que apunta al nodo anterior. Esto permite el recorrido bidireccional de la lista.

```{figure} 13/lista_enlazada_doble.svg
:label: fig-lista-doble
:align: center

Lista doblemente enlazada con punteros tanto al siguiente como al anterior nodo.
```

#### Estructura

```c
typedef struct NodoDoble
{
    int dato;
    struct NodoDoble* anterior;
    struct NodoDoble* siguiente;
} NodoDoble;

typedef struct ListaDoble
{
    NodoDoble* inicio;
    NodoDoble* fin;      // Puntero al último nodo para inserción $O(1)$
    size_t tamanio;
} ListaDoble;
```

#### Ventajas sobre la Lista Simple

- **Recorrido bidireccional:** Se puede recorrer en ambas direcciones.
- **Eliminación más eficiente:** Si tenemos un puntero al nodo, podemos eliminarlo sin necesidad de buscar el nodo anterior.
- **Inserción antes de un nodo:** Podemos insertar antes de un nodo dado sin recorrer la lista.

#### Desventajas

- **Mayor uso de memoria:** Cada nodo requiere un puntero adicional.
- **Mayor complejidad:** Más punteros que actualizar en cada operación.

#### Inserción al Inicio

```c
bool insertar_al_inicio_doble(ListaDoble* lista, int dato)
{
    if (lista == NULL)
    {
        return false;
    }
    
    NodoDoble* nuevo = malloc(sizeof(NodoDoble));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = lista->inicio;
    
    // Si la lista no está vacía, actualizar el anterior del primer nodo
    if (lista->inicio != NULL)
    {
        lista->inicio->anterior = nuevo;
    }
    else
    {
        // Si la lista estaba vacía, fin también apunta al nuevo nodo
        lista->fin = nuevo;
    }
    
    lista->inicio = nuevo;
    lista->tamanio++;
    
    return true;
}
```

#### Eliminación de un Nodo

La ventaja principal es que si tenemos un puntero al nodo a eliminar, podemos hacerlo sin buscar el nodo anterior.

```c
bool eliminar_nodo_doble(ListaDoble* lista, NodoDoble* nodo)
{
    if (lista == NULL || nodo == NULL)
    {
        return false;
    }
    
    // Actualizar el puntero siguiente del nodo anterior
    if (nodo->anterior != NULL)
    {
        nodo->anterior->siguiente = nodo->siguiente;
    }
    else
    {
        // El nodo es el primero
        lista->inicio = nodo->siguiente;
    }
    
    // Actualizar el puntero anterior del nodo siguiente
    if (nodo->siguiente != NULL)
    {
        nodo->siguiente->anterior = nodo->anterior;
    }
    else
    {
        // El nodo es el último
        lista->fin = nodo->anterior;
    }
    
    free(nodo);
    lista->tamanio--;
    
    return true;
}
```

:::{tip} Aplicación de {ref}`(0x0000h)`

Observá cómo la estructura del código refleja claramente la lógica: primero se actualizan los punteros de los nodos adyacentes, luego se libera el nodo. Esta organización facilita la comprensión.
:::

### Lista Circular

Una **lista circular** es una variante donde el último nodo apunta de nuevo al primero, formando un ciclo. Puede ser simple o doblemente enlazada. Son útiles en aplicaciones que requieren procesamiento cíclico, como buffers circulares o sistemas round-robin.

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
typedef struct NodoPila
{
    int dato;
    struct NodoPila* siguiente;
} NodoPila;

typedef struct Pila
{
    NodoPila* tope;
    size_t tamanio;
} Pila;
```

#### Creación de una Pila

```c
Pila* crear_pila(void)
{
    Pila* pila = malloc(sizeof(Pila));
    
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
bool push(Pila* pila, int dato)
{
    if (pila == NULL)
    {
        return false;
    }
    
    NodoPila* nuevo = malloc(sizeof(NodoPila));
    
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
bool pop(Pila* pila, int* dato)
{
    if (pila == NULL || pila->tope == NULL)
    {
        return false;
    }
    
    NodoPila* nodo_a_eliminar = pila->tope;
    *dato = nodo_a_eliminar->dato;
    
    pila->tope = pila->tope->siguiente;
    free(nodo_a_eliminar);
    pila->tamanio--;
    
    return true;
}
```

:::{important}
La función `pop` retorna el dato mediante un parámetro de salida (puntero) y usa el valor de retorno para indicar éxito o fracaso. Esta es una práctica común en C para manejar errores.
:::

#### Ver el Tope (Peek)

```c
bool peek(const Pila* pila, int* dato)
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
bool es_vacia_pila(const Pila* pila)
{
    return pila == NULL || pila->tope == NULL;
}
```

#### Destruir la Pila

```c
void destruir_pila(Pila* pila)
{
    if (pila == NULL)
    {
        return;
    }
    
    while (pila->tope != NULL)
    {
        NodoPila* siguiente = pila->tope->siguiente;
        free(pila->tope);
        pila->tope = siguiente;
    }
    
    free(pila);
}
```

### Aplicaciones de las Pilas

Las pilas son fundamentales en múltiples áreas de la programación:

1. **Evaluación de expresiones:** Conversión de notación infija a postfija y su evaluación.
2. **Función de llamadas:** El stack de llamadas del programa es una pila.
3. **Backtracking:** Algoritmos que exploran opciones y retroceden (laberintos, sudoku).
4. **Deshacer/Rehacer:** Editores de texto y aplicaciones gráficas.
5. **Navegación:** Historial de navegación en navegadores web.
6. **Parsing:** Análisis sintáctico de lenguajes de programación.

### Ejemplo: Verificación de Paréntesis Balanceados

```c
bool parentesis_balanceados(const char* expresion)
{
    Pila* pila = crear_pila();
    
    if (pila == NULL)
    {
        return false;
    }
    
    bool balanceado = true;
    
    for (size_t i = 0; expresion[i] != '\0'; i++)
    {
        char c = expresion[i];
        
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
            
            int tope;
            pop(pila, &tope);
            
            // Verificar que coincidan los tipos de paréntesis
            bool coincide = (c == ')' && tope == '(') ||
                           (c == ']' && tope == '[') ||
                           (c == '}' && tope == '{');
            
            if (!coincide)
            {
                balanceado = false;
                break;
            }
        }
    }
    
    // La expresión es balanceada si la pila está vacía al final
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
typedef struct NodoCola
{
    int dato;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct Cola
{
    NodoCola* frente;      // Puntero al primer elemento (salida)
    NodoCola* final;       // Puntero al último elemento (entrada)
    size_t tamanio;
} Cola;
```

:::{note}
Mantener punteros tanto al frente como al final permite que tanto `encolar` como `desencolar` sean operaciones $O(1)$.
:::

#### Creación de una Cola

```c
Cola* crear_cola(void)
{
    Cola* cola = malloc(sizeof(Cola));
    
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
bool encolar(Cola* cola, int dato)
{
    if (cola == NULL)
    {
        return false;
    }
    
    NodoCola* nuevo = malloc(sizeof(NodoCola));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    // Si la cola está vacía, el nuevo nodo es tanto frente como final
    if (cola->final == NULL)
    {
        cola->frente = nuevo;
        cola->final = nuevo;
    }
    else
    {
        // Agregar al final
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    
    cola->tamanio++;
    return true;
}
```

#### Desencolar (Dequeue)

```c
bool desencolar(Cola* cola, int* dato)
{
    if (cola == NULL || cola->frente == NULL)
    {
        return false;
    }
    
    NodoCola* nodo_a_eliminar = cola->frente;
    *dato = nodo_a_eliminar->dato;
    
    cola->frente = cola->frente->siguiente;
    
    // Si la cola quedó vacía, actualizar final también
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
Es crucial actualizar `cola->final` a `NULL` cuando la cola queda vacía para mantener la consistencia de la estructura.
:::

#### Ver el Frente

```c
bool ver_frente(const Cola* cola, int* dato)
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
bool es_vacia_cola(const Cola* cola)
{
    return cola == NULL || cola->frente == NULL;
}
```

#### Destruir la Cola

```c
void destruir_cola(Cola* cola)
{
    if (cola == NULL)
    {
        return;
    }
    
    while (cola->frente != NULL)
    {
        NodoCola* siguiente = cola->frente->siguiente;
        free(cola->frente);
        cola->frente = siguiente;
    }
    
    free(cola);
}
```

### Aplicaciones de las Colas

Las colas son fundamentales en sistemas que requieren procesamiento en orden de llegada:

1. **Sistemas operativos:** Gestión de procesos (scheduling), colas de impresión.
2. **Redes:** Buffers de paquetes, enrutamiento de mensajes.
3. **Simulaciones:** Modelado de sistemas de espera (bancos, supermercados).
4. **Búsqueda en anchura (BFS):** Algoritmo de grafos para exploración nivel por nivel.
5. **Asincronía:** Colas de tareas en programación concurrente.

### Cola Circular

Una **cola circular** es una optimización que utiliza un arreglo donde el índice del final "envuelve" al inicio cuando alcanza el límite del arreglo. Esto permite reutilizar el espacio liberado por elementos desencolados.

```c
#define CAPACIDAD_MAXIMA 100

typedef struct ColaCircular
{
    int elementos[CAPACIDAD_MAXIMA];
    int frente;
    int final;
    int tamanio;
} ColaCircular;
```

#### Ventajas

- Uso eficiente de memoria: no requiere desplazar elementos.
- Operaciones $O(1)$ tanto para encolar como desencolar.

#### Desventajas

- Capacidad fija (a menos que se implemente redimensionamiento).
- Mayor complejidad en la lógica de envolvimiento.

## Consideraciones de Implementación

### Manejo de Errores

En C no existen excepciones nativas, por lo que el manejo de errores debe realizarse mediante códigos de retorno o valores especiales. Las convenciones comunes incluyen:

- Retornar `bool` para indicar éxito (`true`) o fracaso (`false`).
- Retornar punteros: `NULL` indica error.
- Usar parámetros de salida para retornar datos cuando el valor de retorno se usa para el estado.

:::{tip} Aplicación de {ref}`(0x0035h)` y {ref}`(0x0036h)`

Documentá exhaustivamente la interfaz pública de tu TAD, especificando el comportamiento ante casos de error, condiciones previas y posteriores de cada función.
:::

### Invariantes

Un **invariante** es una propiedad que siempre debe ser verdadera en una estructura de datos bien formada. Por ejemplo:

- En una lista: si `inicio == NULL`, entonces `tamanio == 0`.
- En una cola: si `frente == NULL`, entonces `final == NULL`.
- En una pila: `tamanio` coincide con el número de nodos accesibles desde `tope`.

Mantener estos invariantes es responsabilidad de las funciones de manipulación del TAD.

### Seguridad y Robustez

```c
// Siempre validar parámetros de entrada
bool operacion_segura(Estructura* est, int dato)
{
    if (est == NULL)  // Validación defensiva
    {
        fprintf(stderr, "Error: estructura NULL en operacion_segura\n");
        return false;
    }
    
    // Realizar operación...
    return true;
}
```

:::{warning}
La programación defensiva es especialmente importante en TADs porque el usuario no puede ver la implementación interna. Cada función pública debe validar sus precondiciones.
:::

### Genericidad mediante Punteros Void

Para crear TADs genéricos que funcionen con cualquier tipo de dato, podés usar `void*`:

```c
typedef struct NodoGenerico
{
    void* dato;                    // Puntero genérico
    struct NodoGenerico* siguiente;
} NodoGenerico;

typedef void (*FuncionLiberar)(void*);  // Función para liberar el dato

typedef struct ListaGenerica
{
    NodoGenerico* inicio;
    FuncionLiberar liberar_dato;
    size_t tamanio;
} ListaGenerica;
```

Esto permite almacenar cualquier tipo de dato, pero requiere que el usuario proporcione funciones para copiar, comparar y liberar los datos.

## Complejidad Temporal

La eficiencia de las operaciones es un criterio fundamental al elegir una estructura de datos:

| Operación | Lista Simple | Lista Doble | Pila | Cola |
|-----------|--------------|-------------|------|------|
| Insertar al inicio | $O(1)$ | $O(1)$ | $O(1)$ | - |
| Insertar al final | $O(n)$ o $O(1)$* | $O(1)$ | - | $O(1)$ |
| Eliminar al inicio | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| Eliminar al final | $O(n)$ | $O(1)$ | - | - |
| Buscar elemento | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| Acceso por índice | $O(n)$ | $O(n)$ | - | - |

\* $O(1)$ si se mantiene un puntero al final.

:::{important}
La notación Big-O describe el comportamiento asintótico en el peor caso. En casos promedio o con estructuras auxiliares, las complejidades pueden variar.
:::

## Comparación: Arreglos vs. Listas Enlazadas

| Característica | Arreglos | Listas Enlazadas |
|----------------|----------|------------------|
| Tamaño | Fijo (estático) o costoso de redimensionar | Dinámico |
| Acceso por índice | $O(1)$ | $O(n)$ |
| Inserción al inicio | $O(n)$ (desplazamiento) | $O(1)$ |
| Inserción al final | $O(1)$ (si hay espacio) | $O(1)$ o $O(n)$ |
| Uso de memoria | Contiguo, eficiente en caché | Disperso, overhead por punteros |
| Fragmentación | No sufre | Puede fragmentar el heap |

## Ejercicios

### Ejercicio 1: Invertir una Pila

Escribí una función que invierta el contenido de una pila usando únicamente otra pila auxiliar.

````{exercise} invertir-pila
:label: ejercicio-invertir-pila

Implementá la función:
```c
void invertir_pila(Pila* pila);
```

La función debe invertir el orden de los elementos de la pila. Por ejemplo, si la pila contiene (de tope a fondo): 1, 2, 3, 4, después de invertir debe contener: 4, 3, 2, 1.

Restricción: Podés usar solo una pila auxiliar adicional.
````

````{solution} ejercicio-invertir-pila
:label: solucion-invertir-pila
:class: dropdown

```c
void invertir_pila(Pila* pila)
{
    if (pila == NULL || es_vacia_pila(pila))
    {
        return;
    }
    
    Pila* auxiliar = crear_pila();
    
    if (auxiliar == NULL)
    {
        return;
    }
    
    // Pasar todos los elementos a la pila auxiliar
    while (!es_vacia_pila(pila))
    {
        int dato;
        pop(pila, &dato);
        push(auxiliar, dato);
    }
    
    // La pila auxiliar ahora tiene los elementos en orden inverso
    // Copiar de vuelta a la pila original
    while (!es_vacia_pila(auxiliar))
    {
        int dato;
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
void invertir_pila(Pila* pila)
{
    if (pila == NULL || es_vacia_pila(pila))
    {
        return;
    }
    
    Pila* aux1 = crear_pila();
    Pila* aux2 = crear_pila();
    
    // Primera pasada: pila -> aux1
    while (!es_vacia_pila(pila))
    {
        int dato;
        pop(pila, &dato);
        push(aux1, dato);
    }
    
    // Segunda pasada: aux1 -> aux2
    while (!es_vacia_pila(aux1))
    {
        int dato;
        pop(aux1, &dato);
        push(aux2, dato);
    }
    
    // Tercera pasada: aux2 -> pila (ahora invertida)
    while (!es_vacia_pila(aux2))
    {
        int dato;
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
bool es_palindromo(const char* cadena);
```

Un palíndromo es una palabra que se lee igual de izquierda a derecha que de derecha a izquierda (por ejemplo: "radar", "anilina").

:::{note}
Insertá cada carácter en una pila y en una cola simultáneamente, luego compará los elementos al extraerlos.
:::
````

### Ejercicio 3: Fusionar Listas Ordenadas

````{exercise}
:label: ejercicio-fusionar-listas

Dadas dos listas enlazadas ordenadas ascendentemente, escribí una función que las fusione en una nueva lista también ordenada.

```c
Lista* fusionar_listas(const Lista* lista1, const Lista* lista2);
```

Por ejemplo:
- Lista 1: 1 → 3 → 5 → 7
- Lista 2: 2 → 4 → 6 → 8
- Resultado: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
````

### Ejercicio 4: Cola con Dos Pilas

````{exercise}
:label: ejercicio-cola-con-pilas

Implementá una cola utilizando únicamente dos pilas. Las operaciones `encolar` y `desencolar` deben mantener el comportamiento FIFO.

```c
typedef struct ColaConPilas
{
    Pila* pila_entrada;
    Pila* pila_salida;
} ColaConPilas;

bool encolar_pilas(ColaConPilas* cola, int dato);
bool desencolar_pilas(ColaConPilas* cola, int* dato);
```

Sugerencia: Usá una pila para las inserciones y otra para las extracciones, transfiriendo elementos entre ellas cuando sea necesario.
````

### Ejercicio 5: Detectar Ciclo en una Lista

````{exercise}
:label: ejercicio-detectar-ciclo

Escribí una función que detecte si una lista enlazada contiene un ciclo (es decir, si siguiendo los punteros `siguiente` eventualmente volvés a un nodo ya visitado).

```c
bool tiene_ciclo(const Lista* lista);
```

Sugerencia: Investigá el algoritmo de "la liebre y la tortuga" (Floyd's cycle detection).
````

## Referencias y Lecturas Complementarias

Para profundizar en el estudio de los TADs y estructuras de datos, se recomiendan las siguientes referencias:

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
- Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C* (2nd ed.). Pearson.
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley.

:::{tip}
La implementación de TADs es una habilidad fundamental que requiere práctica. Te recomendamos implementar cada estructura desde cero al menos una vez, probando exhaustivamente cada operación con casos de prueba variados.
:::

## Resumen

Los Tipos de Datos Abstractos son una herramienta fundamental para construir software modular y mantenible. En este apunte hemos cubierto:

- El concepto de TAD y la separación entre interfaz e implementación.
- La diferencia entre memoria estática y dinámica, y cuándo usar cada una.
- Listas enlazadas simples y dobles, con todas sus operaciones fundamentales.
- Pilas (LIFO) y sus aplicaciones en programación.
- Colas (FIFO) y su uso en sistemas que procesan en orden de llegada.
- Consideraciones de implementación: manejo de errores, invariantes y seguridad.
- Análisis de complejidad temporal de las operaciones.

Dominar estas estructuras de datos es esencial para avanzar hacia estructuras más complejas como árboles, grafos y tablas hash, que se construyen sobre estos fundamentos.
