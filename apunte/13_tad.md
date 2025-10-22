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

Separación entre interfaz e implementación en un TAD. La barrera de abstracción protege los detalles internos.
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

#### Conexión con la Programación Orientada a Objetos

Los conceptos de TAD, encapsulamiento y abstracción que estamos estudiando en C son los **mismos principios fundamentales** de la **Programación Orientada a Objetos (POO)**. De hecho, los TADs son el precursor histórico de las clases en lenguajes orientados a objetos.

**Comparación TAD en C vs Clase en POO:**

| Concepto POO | Equivalente en TAD (C) | Propósito |
|--------------|------------------------|-----------|
| **Clase** | Tipo definido (struct + funciones) | Plantilla para crear objetos/instancias |
| **Objeto** | Instancia del TAD (puntero a struct) | Dato concreto en memoria |
| **Atributos privados** | Campos de struct (ocultos en .c) | Estado interno encapsulado |
| **Métodos públicos** | Funciones en .h | Interfaz pública |
| **Constructor** | Función `crear_*()` | Inicialización |
| **Destructor** | Función `destruir_*()` | Liberación de recursos |
| **Encapsulamiento** | Punteros opacos + separación .h/.c | Ocultamiento de implementación |

**Ejemplo conceptual:**

En **Java/C++/Python**, escribirías:
```python
class Lista:
    def __init__(self):
        self._inicio = None       # Atributo privado
        self._tamanio = 0
    
    def insertar(self, dato):     # Método público
        # implementación...
        pass
    
    def __del__(self):
        # liberación...
        pass
```

En **C con TAD**, el equivalente es:
```c
// lista.h - Interfaz pública (como la declaración de clase)
typedef struct lista lista_t;  // Declaración opaca

lista_t *crear_lista(void);           // Constructor
bool insertar_al_inicio(lista_t *lista, int dato);  // Método
void destruir_lista(lista_t *lista);  // Destructor

// lista.c - Implementación privada (como el cuerpo de la clase)
struct lista {
    nodo_t *inicio;
    size_t tamanio;
};
```

:::{note} Pilares de la POO en TADs

Los **4 pilares de la POO** ya están presentes en los TADs bien diseñados:

1. **Encapsulamiento:** Ocultamos los detalles de implementación (struct en .c, solo puntero opaco en .h)
2. **Abstracción:** Exponemos solo las operaciones necesarias (funciones en .h)
3. **Modularidad:** Separación clara entre interfaz (.h) e implementación (.c)
4. **Polimorfismo:** En C se logra mediante punteros a función (aunque no lo usamos en esta introducción)

La **herencia** es el único pilar que C no soporta directamente, aunque puede simularse con composición.
:::

#### Por qué es importante esta conexión

Comprender TADs en C te prepara para entender POO en cualquier lenguaje porque:

1. **Los conceptos son idénticos:** Solo cambia la sintaxis, no los principios
2. **Pensás en términos de interfaz vs implementación:** Habilidad esencial en diseño de software
3. **Apreciás el valor del encapsulamiento:** Independientemente del lenguaje
4. **Entendés el costo real:** En C ves explícitamente la gestión de memoria que los lenguajes OO ocultan

:::{tip} De C a POO

Cuando luego aprendas lenguajes orientados a objetos (Java, C++, Python), reconocerás que las clases son esencialmente TADs con sintaxis más conveniente y características adicionales como herencia y polimorfismo. El conocimiento de TADs te da una ventaja: entendés qué hace el lenguaje "por debajo" cuando creás objetos.
:::

## TAD vs. Estructura de Datos

- **TAD**: Es un concepto lógico, una **especificación** de comportamiento (el "qué").
- **Estructura de Datos**: Es una implementación concreta, una **organización** de datos en memoria (el "cómo").

---

# Ejemplos Clásicos de Tipos de Datos Abstractos

- **Lista (List)**: Colección ordenada y posicionada de elementos.
- **Pila (Stack)**: Colección LIFO (Last-In, First-Out).
- **Cola (Queue)**: Colección FIFO (First-In, First-Out).
- **Cola de Prioridad (Priority Queue)**: Los elementos se extraen según su prioridad.
- **Mapa (Map / Diccionario)**: Colección de pares clave-valor únicos.

---

# Metodología para el Diseño de un TAD Propio

Crear un TAD es un ejercicio de diseño centrado en la abstracción. Seguir un proceso metodológico asegura que el resultado sea robusto, claro y útil.

1. **Conceptualización**: Identificar la entidad a modelar, sus datos y sus reglas.
2. **Definición de la Interfaz Pública**: Listar las operaciones, definir sus firmas (parámetros, retorno) y documentar su comportamiento (precondiciones, poscondiciones).
3. **Especificación Formal (Opcional)**: Definir axiomas que describan cómo interactúan las operaciones.
4. **Elección de la Estructura de Datos**: Evaluar candidatos (arreglos, listas, árboles) y analizar su complejidad para cada operación de la interfaz.
5. **Implementación**: Escribir el código, encapsulando la estructura de datos interna y exponiendo solo la interfaz pública.

---

## Asignación de Memoria: Estática vs. Dinámica

Antes de implementar estructuras de datos dinámicas, es crucial comprender la diferencia entre memoria estática y dinámica. Esta sección presenta un resumen de los conceptos fundamentales; para un tratamiento exhaustivo, consultá el apunte sobre {ref}`memoria-introduccion`.

```{figure} 13/memoria_estatica_dinamica.svg
:label: fig-memoria-estatica-dinamica
:align: center

Comparación entre asignación de memoria estática (en el stack) y dinámica (en el heap).
```

### Memoria Estática

La memoria estática se asigna en el **stack** (pila de llamadas) durante la compilación o al momento de declarar una variable. Para profundizar en el funcionamiento del stack, consultá {ref}`memoria-stack`. Sus características son:

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

La memoria dinámica se asigna en el **heap** (montículo) durante la ejecución del programa mediante funciones como `malloc`, `calloc` o `realloc`. Para detalles sobre el funcionamiento del heap y técnicas avanzadas, consultá {ref}`memoria-heap`. Sus características son:

- **Tamaño flexible:** Puede determinarse en tiempo de ejecución.
- **Duración:** Persiste hasta que se libere explícitamente con `free`.
- **Liberación manual:** El programador es responsable de liberar la memoria.
- **Mayor capacidad:** El heap es mucho más grande que el stack.
- **Acceso mediante punteros:** Se requieren punteros para acceder a la memoria asignada.

```c
void procesar_datos(int cantidad)
{
    int *numeros = NULL;
    
    numeros = malloc(cantidad * sizeof(int));
    
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria\n");
        return;
    }
    
    // Usar el arreglo...
    
    // IMPORTANTE: Liberar la memoria cuando ya no se necesita
    free(numeros);
    numeros = NULL;
}
```

:::{warning}
No liberar la memoria dinámica asignada produce **fugas de memoria** (*memory leaks*), donde la memoria se pierde hasta que el programa termine. Esto puede agotar los recursos del sistema. Para más información sobre errores comunes y cómo detectarlos, consultá {ref}`memoria-errores`.
:::

### ¿Cuándo usar cada tipo?

- **Memoria estática:** Cuando el tamaño es conocido, pequeño y constante.
- **Memoria dinámica:** Cuando el tamaño depende de la entrada del usuario, es grande, o varía durante la ejecución.

Para una discusión más profunda sobre las implicaciones de rendimiento de estas decisiones, consultá {ref}`memoria-modelo-costos`.

:::{tip} Aplicación de {ref}`0x0003h` y {ref}`0x0036h`

Siempre debés inicializar los punteros, preferentemente a `NULL` (regla {ref}`0x0003h`), y verificar que `malloc` no retorne `NULL` antes de usar la memoria asignada. Además, después de liberar memoria con `free`, asignále `NULL` al puntero (regla {ref}`0x0036h`) para evitar punteros colgantes. Para buenas prácticas adicionales sobre gestión de memoria, consultá {ref}`memoria-buenas-practicas`.
:::

## El TAD Secuencia

Una **secuencia** es una colección ordenada de elementos donde cada elemento tiene una posición definida. Es uno de los TADs más fundamentales en programación, ya que representa la idea abstracta de "una serie de cosas en orden".

### Interfaz del TAD Secuencia

El TAD Secuencia define las siguientes operaciones esenciales:

- **crear():** Crea una secuencia vacía.
- **insertar_al_inicio(secuencia, elemento):** Agrega un elemento al principio.
- **insertar_al_final(secuencia, elemento):** Agrega un elemento al final.
- **insertar_en_posicion(secuencia, posicion, elemento):** Inserta un elemento en una posición específica.
- **eliminar(secuencia, elemento):** Elimina la primera ocurrencia de un elemento.
- **buscar(secuencia, elemento):** Busca un elemento y retorna su posición o indicador de no encontrado.
- **obtener(secuencia, posicion):** Retorna el elemento en una posición dada.
- **tamanio(secuencia):** Retorna la cantidad de elementos.
- **es_vacia(secuencia):** Verifica si la secuencia está vacía.
- **destruir(secuencia):** Libera todos los recursos asociados.

### Múltiples Implementaciones

Lo poderoso de un TAD es que esta misma interfaz puede implementarse de diferentes maneras, cada una con sus ventajas y desventajas. Las dos implementaciones más comunes de una secuencia son:

1. **Implementación con arreglo:** Los elementos se almacenan en posiciones contiguas de memoria.
2. **Implementación con lista enlazada:** Los elementos se almacenan en nodos dispersos, conectados mediante punteros.

:::{note}
La misma interfaz de secuencia puede implementarse con arreglos (memoria contigua) o con listas enlazadas (nodos dispersos), cada una con diferentes características de rendimiento.
:::

:::{important} Poder de la Abstracción

El código que usa una secuencia no necesita saber si está implementada con arreglos o listas enlazadas. Esto permite cambiar la implementación sin modificar el código cliente, eligiendo la mejor opción según las necesidades de rendimiento.
:::

### Comparación de Implementaciones

| Aspecto | Arreglo | Lista Enlazada |
|---------|---------|----------------|
| **Acceso aleatorio** | $O(1)$ directo por índice | $O(n)$ requiere recorrido |
| **Insertar al inicio** | $O(n)$ desplazamiento | $O(1)$ ajustar punteros |
| **Insertar al final** | $O(1)$ si hay espacio* | $O(1)$ o $O(n)$** |
| **Búsqueda** | $O(n)$ recorrido | $O(n)$ recorrido |
| **Memoria** | Contigua, eficiente caché | Dispersa, overhead de punteros |
| **Tamaño** | Fijo o costoso redimensionar | Dinámico, crece según necesidad |

* Si el arreglo está lleno, requiere $O(n)$ para redimensionar.  
** $O(1)$ si se mantiene puntero al final, $O(n)$ si no.

## Listas Enlazadas: Implementación de Secuencia

Una **lista enlazada** es una implementación del TAD Secuencia donde los elementos se almacenan en nodos individuales conectados mediante punteros. A diferencia de los arreglos, los nodos no necesitan estar en posiciones contiguas de memoria, lo que permite inserciones y eliminaciones eficientes al inicio.

Esta es una de las estructuras de datos dinámicas más fundamentales y sirve como base para implementar otros TADs como pilas y colas.

### Ventajas de las Listas Enlazadas

- **Tamaño dinámico:** Crece y decrece según las necesidades sin redimensionamiento.
- **Inserción y eliminación eficientes:** $O(1)$ si tenemos la referencia al nodo.
- **No requiere reorganización:** Al insertar o eliminar elementos intermedios.

### Desventajas de las Listas Enlazadas

- **Acceso secuencial:** No hay acceso directo por índice ($O(n)$).
- **Mayor uso de memoria:** Cada nodo requiere espacio adicional para punteros.
- **Menos eficiente en caché:** La no contigüidad en memoria reduce el rendimiento.

:::{note} Implementando la Interfaz de Secuencia

Las operaciones de la lista enlazada implementan directamente las operaciones del TAD Secuencia. Por ejemplo, `insertar_al_inicio` de la lista corresponde a la operación abstracta de la secuencia.
:::

### Lista Enlazada Simple

En una lista enlazada simple, cada nodo apunta únicamente al siguiente nodo de la secuencia. El último nodo apunta a `NULL`, indicando el final de la lista.

```{figure} 13/lista_enlazada_simple.svg
:label: fig-lista-simple
:align: center

Estructura de una lista enlazada simple. Cada nodo contiene datos y un puntero al siguiente nodo.
```

#### Estructura de un Nodo

```c
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} nodo_t;

typedef struct lista
{
    nodo_t *inicio;
    size_t tamanio;
} lista_t;
```

:::{note}
Observá el uso de `struct nodo *` dentro de la definición de `nodo`. Esto es válido porque el compilador solo necesita saber que `siguiente` es un puntero, cuyo tamaño es conocido independientemente del tipo completo de `nodo`.
:::

:::{tip} Aplicación de {ref}`0x0004h`

Notá el uso de espacios alrededor del operador `*` en las declaraciones de punteros. Según la regla {ref}`0x0004h`, debe haber un espacio antes y después de cada operador, lo que incluye el asterisco en declaraciones de punteros. Además, usamos el sufijo `_t` para todos los tipos definidos mediante `typedef`, siguiendo las convenciones de C estándar.
:::

#### Creación de una Lista Vacía

```c
lista_t *crear_lista(void)
{
    lista_t *lista = NULL;
    
    lista = malloc(sizeof(lista_t));
    
    if (lista == NULL)
    {
        return NULL;
    }
    
    lista->inicio = NULL;
    lista->tamanio = 0;
    
    return lista;
}
```

:::{tip} Aplicación de {ref}`0x0001h` y {ref}`0x0003h`

El nombre `crear_lista` es descriptivo y refleja claramente la operación que realiza (regla {ref}`0x0001h`). Evitar nombres genéricos como `crear` o `nueva`. Además, inicializamos el puntero `lista` a `NULL` antes de asignarle memoria (regla {ref}`0x0003h`).
:::

:::{note} Verificación de Asignación

Siempre verificamos que `malloc` no retorne `NULL` antes de usar la memoria asignada. Este patrón es esencial para escribir código robusto. Para más detalles sobre manejo de errores en asignación dinámica, consultá {ref}`memoria-malloc`.
:::

#### Inserción al Inicio

La inserción al inicio es una operación $O(1)$ porque no requiere recorrer la lista.

```c
bool insertar_al_inicio(lista_t *lista, int dato)
{
    nodo_t *nuevo = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = lista->inicio;
    
    lista->inicio = nuevo;
    lista->tamanio++;
    
    return true;
}
```

#### Inserción al Final

La inserción al final requiere recorrer toda la lista para encontrar el último nodo ($O(n)$).

```c
bool insertar_al_final(lista_t *lista, int dato)
{
    nodo_t *nuevo = NULL;
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (lista->inicio == NULL)
    {
        lista->inicio = nuevo;
    }
    else
    {
        actual = lista->inicio;
        
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
Una optimización común es mantener un puntero adicional `fin` en la estructura `lista_t` que apunte al último nodo, reduciendo la inserción al final a $O(1)$.
:::

#### Búsqueda

```c
nodo_t *buscar(const lista_t *lista, int dato)
{
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return NULL;
    }
    
    actual = lista->inicio;
    
    while (actual != NULL)
    {
        if (actual->dato == dato)
        {
            return actual;
        }
        
        actual = actual->siguiente;
    }
    
    return NULL;
}
```

:::{tip} Aplicación de {ref}`0x0000h` y {ref}`0x0035h`

El uso de `const lista_t *` indica que la función no modifica la lista, mejorando la claridad del código (regla {ref}`0x0000h`). Además, seguimos la convención de espaciado de la regla {ref}`0x0004h` con el operador `*`.
:::

#### Eliminación

La eliminación de un nodo requiere mantener una referencia al nodo anterior para poder actualizar su puntero `siguiente`.

```c
bool eliminar(lista_t *lista, int dato)
{
    nodo_t *actual = NULL;
    nodo_t *anterior = NULL;
    
    if (lista == NULL || lista->inicio == NULL)
    {
        return false;
    }
    
    actual = lista->inicio;
    anterior = NULL;
    
    while (actual != NULL && actual->dato != dato)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if (actual == NULL)
    {
        return false;
    }
    
    if (anterior == NULL)
    {
        lista->inicio = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
    actual = NULL;
    lista->tamanio--;
    
    return true;
}
```

:::{tip} Aplicación de {ref}`0x0036h`

Observá que después de `free(actual)`, asignamos `NULL` al puntero para prevenir su uso accidental. Aunque en este caso el puntero está a punto de salir de ámbito, es una buena práctica que previene errores.
:::

#### Recorrido

```c
void imprimir_lista(const lista_t *lista)
{
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return;
    }
    
    actual = lista->inicio;
    
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
void destruir_lista(lista_t *lista)
{
    nodo_t *actual = NULL;
    nodo_t *siguiente = NULL;
    
    if (lista == NULL)
    {
        return;
    }
    
    actual = lista->inicio;
    
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
    lista = NULL;
}
```

:::{warning}
Nunca accedas a un nodo después de haberlo liberado con `free`. Por eso guardamos `siguiente` antes de liberar `actual`. Este es un error común que puede causar comportamiento indefinido. Para más información sobre este y otros errores relacionados con memoria, consultá {ref}`memoria-errores`.
:::

:::{important} Gestión de Memoria en TADs

La destrucción apropiada de estructuras de datos es crítica para evitar fugas de memoria. Observá el patrón: primero liberamos todos los nodos recursivamente, y finalmente liberamos la estructura contenedora. Para más detalles sobre patrones de liberación y técnicas avanzadas, consultá {ref}`memoria-buenas-practicas`.
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
typedef struct nodo_doble
{
    int dato;
    struct nodo_doble *anterior;
    struct nodo_doble *siguiente;
} nodo_doble_t;

typedef struct lista_doble
{
    nodo_doble_t *inicio;
    nodo_doble_t *fin;
    size_t tamanio;
} lista_doble_t;
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
bool insertar_al_inicio_doble(lista_doble_t *lista, int dato)
{
    nodo_doble_t *nuevo = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_doble_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = lista->inicio;
    
    if (lista->inicio != NULL)
    {
        lista->inicio->anterior = nuevo;
    }
    else
    {
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
bool eliminar_nodo_doble(lista_doble_t *lista, nodo_doble_t *nodo)
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

:::{tip} Aplicación de {ref}`0x0000h`

Observá cómo la estructura del código refleja claramente la lógica: primero se actualizan los punteros de los nodos adyacentes, luego se libera el nodo. Esta organización facilita la comprensión.
:::

### Lista Circular

Una **lista circular** es una variante donde el último nodo apunta de nuevo al primero, formando un ciclo. Puede ser simple o doblemente enlazada. Son útiles en aplicaciones que requieren procesamiento cíclico, como buffers circulares o sistemas round-robin.


## Arreglos: Implementación Alternativa de Secuencia

Para demostrar el poder de la abstracción del TAD, presentamos ahora una implementación alternativa del TAD Secuencia utilizando arreglos en lugar de listas enlazadas. Esta implementación ofrece diferentes características de rendimiento, pero mantiene la misma interfaz conceptual.

### Secuencia con Arreglo Dinámico

Un arreglo dinámico combina las ventajas del acceso aleatorio de los arreglos con la flexibilidad de tamaño de las estructuras dinámicas.

```c
typedef struct secuencia_arreglo
{
    int *elementos;
    size_t tamanio;
    size_t capacidad;
} secuencia_arreglo_t;
```

:::{note} Campos de la Estructura

- `elementos`: Puntero al arreglo dinámico que almacena los datos.
- `tamanio`: Cantidad actual de elementos en la secuencia.
- `capacidad`: Espacio total asignado (puede ser mayor que `tamanio`).
:::

#### Creación de una Secuencia con Arreglo

```c
#define CAPACIDAD_INICIAL 10

secuencia_arreglo_t *crear_secuencia_arreglo(void)
{
    secuencia_arreglo_t *sec = NULL;
    
    sec = malloc(sizeof(secuencia_arreglo_t));
    
    if (sec == NULL)
    {
        return NULL;
    }
    
    sec->elementos = malloc(CAPACIDAD_INICIAL * sizeof(int));
    
    if (sec->elementos == NULL)
    {
        free(sec);
        return NULL;
    }
    
    sec->tamanio = 0;
    sec->capacidad = CAPACIDAD_INICIAL;
    
    return sec;
}
```

#### Redimensionamiento Automático

Cuando la capacidad se agota, el arreglo debe redimensionarse. Una estrategia común es duplicar la capacidad:

```c
bool redimensionar(secuencia_arreglo_t *sec)
{
    size_t nueva_capacidad = 0;
    int *nuevo_arreglo = NULL;
    
    if (sec == NULL)
    {
        return false;
    }
    
    nueva_capacidad = sec->capacidad * 2;
    nuevo_arreglo = realloc(sec->elementos, nueva_capacidad * sizeof(int));
    
    if (nuevo_arreglo == NULL)
    {
        return false;
    }
    
    sec->elementos = nuevo_arreglo;
    sec->capacidad = nueva_capacidad;
    
    return true;
}
```

#### Insertar al Final

```c
bool insertar_al_final_arreglo(secuencia_arreglo_t *sec, int dato)
{
    if (sec == NULL)
    {
        return false;
    }
    
    if (sec->tamanio >= sec->capacidad)
    {
        if (!redimensionar(sec))
        {
            return false;
        }
    }
    
    sec->elementos[sec->tamanio] = dato;
    sec->tamanio++;
    
    return true;
}
```

#### Acceso por Índice

Esta es la operación donde los arreglos brillan: acceso $O(1)$.

```c
bool obtener_elemento(const secuencia_arreglo_t *sec, size_t indice, int *dato)
{
    if (sec == NULL || dato == NULL || indice >= sec->tamanio)
    {
        return false;
    }
    
    *dato = sec->elementos[indice];
    
    return true;
}
```

#### Insertar en Posición Específica

Requiere desplazar elementos, resultando en $O(n)$.

```c
bool insertar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos, int dato)
{
    size_t i = 0;
    
    if (sec == NULL || pos > sec->tamanio)
    {
        return false;
    }
    
    if (sec->tamanio >= sec->capacidad)
    {
        if (!redimensionar(sec))
        {
            return false;
        }
    }
    
    for (i = sec->tamanio; i > pos; i--)
    {
        sec->elementos[i] = sec->elementos[i - 1];
    }
    
    sec->elementos[pos] = dato;
    sec->tamanio++;
    
    return true;
}
```

#### Destruir la Secuencia

```c
void destruir_secuencia_arreglo(secuencia_arreglo_t *sec)
{
    if (sec == NULL)
    {
        return;
    }
    
    free(sec->elementos);
    sec->elementos = NULL;
    free(sec);
}
```

### Comparación: Arreglo vs Lista Enlazada como Secuencia

Ahora que hemos visto ambas implementaciones del TAD Secuencia, podemos compararlas directamente:

| Operación | Secuencia con Arreglo | Secuencia con Lista |
|-----------|----------------------|---------------------|
| `obtener(posicion)` | $O(1)$ | $O(n)$ |
| `insertar_al_inicio(dato)` | $O(n)$ | $O(1)$ |
| `insertar_al_final(dato)` | $O(1)$ amortizado* | $O(1)$ o $O(n)$** |
| `insertar_en_posicion(pos, dato)` | $O(n)$ | $O(n)$ |
| `buscar(dato)` | $O(n)$ | $O(n)$ |
| `eliminar(dato)` | $O(n)$ | $O(n)$ |

* $O(1)$ en promedio, pero ocasionalmente $O(n)$ cuando se redimensiona.  
** $O(1)$ si se mantiene puntero al final, $O(n)$ si no.

:::{important} Eligiendo la Implementación Correcta

- **Usá arreglos** cuando necesitás acceso aleatorio frecuente o querés aprovechar la localidad de caché.
- **Usá listas enlazadas** cuando las inserciones/eliminaciones al inicio sean frecuentes o el tamaño varíe mucho.
- **Ambas son válidas** implementaciones del mismo TAD Secuencia, demostrando el poder de la abstracción.
:::

:::{tip} El Patrón Strategy

Esta separación entre interfaz e implementación es un ejemplo del patrón de diseño **Strategy**. El código cliente puede trabajar con "secuencias" sin importar la implementación subyacente, permitiendo optimizar según el caso de uso.
:::

## Consideraciones de Implementación

### Manejo de Errores

En C no existen excepciones nativas, por lo que el manejo de errores debe realizarse mediante códigos de retorno o valores especiales. Las convenciones comunes incluyen:

- Retornar `bool` para indicar éxito (`true`) o fracaso (`false`).
- Retornar punteros: `NULL` indica error.
- Usar parámetros de salida para retornar datos cuando el valor de retorno se usa para el estado.

:::{tip} Aplicación de {ref}`0x0035h` y {ref}`0x0036h`

Documentá exhaustivamente la interfaz pública de tu TAD, especificando el comportamiento ante casos de error, condiciones previas y posteriores de cada función.
:::

### Invariantes

Un **invariante** es una propiedad que siempre debe ser verdadera en una estructura de datos bien formada. Por ejemplo:

- En una lista: si `inicio == NULL`, entonces `tamanio == 0`.
- En una secuencia con arreglo: `tamanio <= capacidad`.

Mantener estos invariantes es responsabilidad de las funciones de manipulación del TAD.

### Seguridad y Robustez

```c
bool operacion_segura(estructura_t *est, int dato)
{
    if (est == NULL)
    {
        fprintf(stderr, "Error: estructura NULL en operacion_segura\n");
        return false;
    }
    
    return true;
}
```

:::{warning}
La programación defensiva es especialmente importante en TADs porque el usuario no puede ver la implementación interna. Cada función pública debe validar sus precondiciones.
:::

:::{note} Validación y Depuración

Para técnicas avanzadas de validación y depuración de errores relacionados con memoria en estructuras dinámicas, consultá {ref}`memoria-valgrind`. Herramientas como Valgrind son invaluables para detectar fugas de memoria y accesos inválidos en TADs complejos.
:::

## Complejidad Temporal

La eficiencia de las operaciones es un criterio fundamental al elegir una estructura de datos:

| Operación | Lista Simple | Lista Doble |
|-----------|--------------|-------------|
| Insertar al inicio | $O(1)$ | $O(1)$ |
| Insertar al final | $O(n)$ o $O(1)$* | $O(1)$ |
| Eliminar al inicio | $O(1)$ | $O(1)$ |
| Eliminar al final | $O(n)$ | $O(1)$ |
| Buscar elemento | $O(n)$ | $O(n)$ |
| Acceso por índice | $O(n)$ | $O(n)$ |

* $O(1)$ si se mantiene un puntero al final.

:::{important}
La notación Big-O describe el comportamiento asintótico en el peor caso. En casos promedio o con estructuras auxiliares, las complejidades pueden variar.
:::

:::{note}
Para ver la complejidad de pilas y colas, consultá el apunte sobre [](14_estructuras.md).
:::

## Comparación: Arreglos vs. Listas Enlazadas como Secuencias

Ya hemos visto en detalle cómo tanto los arreglos dinámicos como las listas enlazadas pueden implementar el TAD Secuencia. Esta tabla resume las diferencias clave entre ambas implementaciones:

| Característica | Arreglos Dinámicos | Listas Enlazadas |
|----------------|-------------------|------------------|
| Tamaño | Redimensionable (costo amortizado) | Dinámico sin redimensionamiento |
| Acceso por índice | $O(1)$ | $O(n)$ |
| Inserción al inicio | $O(n)$ (desplazamiento) | $O(1)$ |
| Inserción al final | $O(1)$ amortizado | $O(1)$ o $O(n)$ |
| Uso de memoria | Contiguo, eficiente en caché | Disperso, overhead por punteros |
| Fragmentación | No sufre | Puede fragmentar el heap |
| Mejor caso de uso | Acceso aleatorio frecuente | Inserciones/eliminaciones frecuentes |

:::{note} Consideraciones de Rendimiento

La elección entre arreglos y listas enlazadas tiene profundas implicaciones de rendimiento más allá de la complejidad algorítmica. Los arreglos tienen mejor localidad de memoria, lo que resulta en mejor uso del caché del procesador. Las listas enlazadas, al tener nodos dispersos en memoria, sufren más penalizaciones por accesos a memoria. Para un análisis detallado del impacto del caché y la localidad de memoria, consultá {ref}`memoria-modelo-costos`.

Para ver implementaciones concretas de ambas aproximaciones, consultá las secciones anteriores sobre "Listas Enlazadas: Implementación de Secuencia" y "Arreglos: Implementación Alternativa de Secuencia".
:::

:::{important} El Poder de la Abstracción

El concepto clave aquí es que **ambas estructuras implementan el mismo TAD Secuencia**. El código que utiliza una secuencia puede ser escrito de forma genérica, permitiendo cambiar entre implementaciones según las necesidades de rendimiento específicas sin reescribir la lógica de negocio.
:::

## Ejercicios

### Ejercicio 1: Fusionar Listas Ordenadas

````{exercise}
:label: ejercicio-fusionar-listas

Dadas dos listas enlazadas ordenadas ascendentemente, escribí una función que las fusione en una nueva lista también ordenada.

```c
lista_t *fusionar_listas(const lista_t *lista1, const lista_t *lista2);
```

Por ejemplo:
- Lista 1: 1 → 3 → 5 → 7
- Lista 2: 2 → 4 → 6 → 8
- Resultado: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
````

### Ejercicio 2: Detectar Ciclo en una Lista

````{exercise}
:label: ejercicio-detectar-ciclo

Escribí una función que detecte si una lista enlazada contiene un ciclo (es decir, si siguiendo los punteros `siguiente` eventualmente volvés a un nodo ya visitado).

```c
bool tiene_ciclo(const lista_t *lista);
```

Sugerencia: Investigá el algoritmo de "la liebre y la tortuga" (Floyd's cycle detection).
````

:::{note}
Para ejercicios sobre pilas y colas, consultá el apunte [](14_estructuras.md).
:::

## Referencias y Lecturas Complementarias

Para profundizar en el estudio de los TADs y estructuras de datos, se recomiendan las siguientes referencias:

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
- Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C* (2nd ed.). Pearson.
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley.

Para aspectos específicos de gestión de memoria y su impacto en la implementación de TADs, consultá:

- {ref}`memoria-introduccion` para entender el modelo de memoria completo.
- {ref}`memoria-buenas-practicas` para patrones seguros de manejo de memoria dinámica.
- {ref}`memoria-valgrind` para técnicas de depuración de estructuras dinámicas.

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
- La diferencia entre **memoria estática y dinámica**, y cuándo usar cada una (para detalles completos, consultá {ref}`memoria-introduccion`).
- **Listas enlazadas** simples, dobles y circulares, con todas sus operaciones fundamentales.
- **Consideraciones de implementación:** manejo de errores, invariantes y seguridad.
- **Análisis de complejidad temporal** de las operaciones en diferentes implementaciones.

:::{important} Lección Clave: Múltiples Implementaciones

El concepto más importante de este apunte es que **un mismo TAD puede tener múltiples implementaciones**, cada una con diferentes características de rendimiento. La elección de la implementación correcta depende del contexto de uso, y el poder de la abstracción permite cambiar entre implementaciones sin reescribir el código cliente.
:::

:::{note}
Para ver otros TADs como pilas y colas, que también demuestran el poder de la abstracción con diferentes implementaciones, consultá el apunte [](14_estructuras.md).
:::

Dominar estas estructuras de datos es esencial para avanzar hacia estructuras más complejas como árboles, grafos y tablas de hash, que se construyen sobre estos fundamentos. La correcta gestión de memoria dinámica, tema central en este apunte, es la base para implementar cualquier estructura de datos compleja de manera segura y eficiente.