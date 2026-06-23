---
title: Tipos de Datos Abstractos, Pilas y Colas
short_title: 13 - TAD, Pilas y Colas
subtitle: Estructuras de datos dinámicas y especializadas
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

#### Encapsulamiento mediante Punteros Opacos en C

Para garantizar el ocultamiento de la representación interna, C permite declarar tipos incompletos en el archivo de cabecera (`.h`) y definir su estructura en el archivo de implementación (`.c`). Esto se conoce como **puntero opaco**.

**Ejemplo de interfaz pública (`lista.h`):**
```c
#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stddef.h>

// Declaración incompleta (puntero opaco)
typedef struct lista lista_t;

// Operaciones públicas
lista_t *lista_crear(void);
bool lista_insertar(lista_t *lista, int dato);
void lista_destruir(lista_t *lista);

#endif // LISTA_H
```

**Ejemplo de implementación interna (`lista.c`):**
```c
#include "lista.h"
#include <stdlib.h>

// Definición completa de la estructura
struct lista {
    int *elementos;
    size_t cantidad;
    size_t capacidad;
};

lista_t *lista_crear(void)
{
    lista_t *l = malloc(sizeof(*l));
    if (l == NULL)
    {
        return NULL;
    }
    l->elementos = NULL;
    l->cantidad = 0;
    l->capacidad = 0;
    return l;
}
```

Con este esquema, cualquier archivo que incluya `lista.h` no podrá acceder a los campos `elementos`, `cantidad` o `capacidad` de manera directa (por ejemplo, haciendo `lista->cantidad`), ya que el compilador desconoce el tamaño y los campos de `struct lista`. Esto previene el acoplamiento y asegura que toda interacción se realice exclusivamente a través de las funciones de la interfaz.

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

El diseño e implementación de Tipos de Datos Abstractos en C requiere una gestión rigurosa de la memoria. La elección entre el ciclo de vida automático en el *stack* (memoria estática) o el ciclo de vida dinámico en el *heap* (memoria dinámica) define cómo se almacenan, acceden y destruyen los elementos del TAD.

Para un análisis detallado sobre el funcionamiento del stack, consultá la sección {ref}`memoria-stack` en el apunte correspondiente. Asimismo, los detalles operativos de la asignación dinámica, el uso del heap y la gestión de errores mediante `malloc`, `realloc` y `free` se abordan en profundidad en {ref}`memoria-heap` y {ref}`memoria-errores`.

:::{important}
En este apunte se utiliza prioritariamente la asignación dinámica de memoria en el heap para permitir que las estructuras de datos tengan un tamaño variable y flexible en tiempo de ejecución. Recordá aplicar siempre las buenas prácticas de inicialización y liberación de punteros documentadas en {ref}`memoria-buenas-practicas` (reglas {ref}`0x0003h` y {ref}`0x0036h`).
:::

## Tipificación de Acciones

Cuando diseñamos un TAD, las operaciones que lo componen no son arbitrarias. Cada función cumple un **rol específico** en la manipulación de la estructura de datos. Clasificar estas operaciones según su propósito permite crear interfaces coherentes y predecibles, facilitando tanto la implementación como el uso del TAD.

A continuación se presentan las **siete categorías fundamentales** de operaciones que típicamente conforman un TAD bien diseñado:

### 1. Constructor

**Propósito:** "Prepara el terreno".

**Función:** Se encarga de la asignación de memoria e inicialización de la estructura. El constructor establece el estado inicial válido del TAD, reservando los recursos necesarios y configurando los invariantes básicos.

**Ejemplos:**
```c
int** crear_matriz(int filas, int col);
int* crear_arreglo(int largo);
pila_t* crear_pila(void);
lista_t* crear_lista(void);
```

:::{note}
En C, los constructores siempre devuelven un puntero a la estructura recién creada, o `NULL` si la creación falla (por ejemplo, por falta de memoria). El llamador es responsable de verificar el resultado antes de usar la estructura.
:::

### 2. Selector

**Propósito:** "Recupera información".

**Función:** Obtiene un dato específico que está guardado dentro de la estructura. Los selectores permiten **acceder** al contenido almacenado sin modificarlo. Son operaciones de solo lectura sobre los datos del usuario.

**Ejemplos:**
```c
int valor = arreglo[i];
int item = obtener(arreglo_t, indice);
int dato = ver_tope(pila);
int primero = frente(cola);
```

:::{important}
Los selectores **no modifican** el estado de la estructura. Deben ser operaciones seguras que puedan invocarse múltiples veces sin efectos secundarios. En términos de programación funcional, son funciones puras respecto al estado del TAD.
:::

### 3. Consultor

**Propósito:** "Recupera meta-información".

**Función:** Informa sobre alguna **propiedad intrínseca** de la estructura, no sobre los datos almacenados por el usuario, sino sobre el estado y características de la estructura misma. Los consultores responden preguntas sobre la configuración, capacidad o estado actual del TAD.

**Ejemplos:**
```c
size_t tamanio = sizeof(arreglo);
bool vacia = esta_vacia(pila);
bool encontrado = contiene(lista, valor);
int elementos = largo(lista);
size_t capacidad_actual = capacidad(arreglo_dinamico);
```

**Diferencia con Selectores:**
- **Selector:** Devuelve un dato del usuario almacenado → `ver_tope(pila)` devuelve el elemento en el tope.
- **Consultor:** Devuelve información sobre la estructura → `esta_vacia(pila)` informa si hay elementos o no.

### 4. Iterador

**Propósito:** "Recorre la información".

**Función:** Provee una entidad que permite **procesar los elementos** de la estructura uno por uno, de manera secuencial, sin exponer la representación interna. Los iteradores son fundamentales para abstraer el recorrido de estructuras complejas.

**Ejemplos:**
```c
iterador_t* iter = crear_iterador(lista);
while (tiene_siguiente(iter)) {
    int actual = siguiente(iter);
    // procesar actual
}
destruir_iterador(iter);

// Alternativamente, con callbacks:
void procesar(int dato, void* contexto);
recorrer(lista, procesar, contexto);
```

:::{tip}
Los iteradores son especialmente útiles cuando la estructura de datos tiene múltiples formas de recorrido (por ejemplo, un árbol puede recorrerse en preorden, inorden o postorden). Cada estrategia puede implementarse como un iterador diferente sin cambiar la estructura subyacente.
:::

### 5. Mutador

**Propósito:** "Modifica la información".

**Función:** Cambia el **estado o los datos** contenidos en la estructura. Los mutadores son las operaciones de escritura que alteran el contenido gestionado por el TAD. Deben mantener los invariantes de la estructura.

**Ejemplos:**
```c
arreglo[i] = valor;
bool exito = insertar(lista, val, pos);
bool exito = apilar(pila, dato);
bool exito = encolar(cola, dato);
bool eliminado = remover(conjunto, elemento);
void modificar(matriz, fila, col, nuevo_valor);
```

:::{important}
Los mutadores deben garantizar que la estructura permanece en un estado **válido** después de la operación. Por ejemplo, si una pila tiene un invariante de que `tope < capacidad`, la operación `apilar` debe verificar esta condición antes de agregar un elemento, y devolver `false` o redimensionar la estructura si es necesario.
:::

### 6. Conversor

**Propósito:** "Crea una estructura similar".

**Función:** Genera una **nueva estructura** o representación a partir del contenido de la estructura actual. Los conversores transforman el TAD en otro formato, típicamente para interoperabilidad o presentación.

**Ejemplos:**
```c
char* cadena = a_cadena(arreglo, largo);
int* subconjunto = rebanar(arreglo, desde, hasta);
lista_t* sublista = copiar_sublista(lista, inicio, fin);
arreglo_t* arr = lista_a_arreglo(lista);
char* representacion = serializar(estructura);
```

:::{note}
Los conversores típicamente **asignan memoria nueva** para el resultado. El llamador es responsable de liberar estos recursos cuando ya no los necesite. Esto debe documentarse claramente en la especificación de la función.
:::

**Diferencia con Selectores:**
- **Selector:** Devuelve una *referencia* a datos existentes → `obtener(arreglo, 5)` devuelve el elemento en posición 5.
- **Conversor:** Crea una *nueva estructura* con datos derivados → `rebanar(arreglo, 2, 5)` crea un nuevo arreglo con copia de elementos 2-5.

### 7. Destructor

**Propósito:** "Libera los recursos".

**Función:** Se encarga de **liberar la memoria** asignada y otros recursos externos (archivos, conexiones, etc.) para evitar fugas (*memory leaks*). El destructor es la operación final en el ciclo de vida de una instancia del TAD.

**Ejemplos:**
```c
void liberar_arreglo(int* arreglo);
void destruir_matriz(int filas, int** matriz);
void destruir_pila(pila_t* pila);
void destruir_lista(lista_t* lista, void (*destruir_dato)(void*));
```

:::{warning} Responsabilidad del Destructor
El destructor debe liberar **recursivamente** toda la memoria asociada con la estructura. Si el TAD almacena punteros a otras estructuras dinámicas, el destructor debe liberarlas también, o bien aceptar una función de destrucción personalizada como parámetro para delegar esa responsabilidad al usuario.
:::

**Patrones comunes:**
```c
// Destructor simple (datos copiados)
void destruir_pila_int(pila_t* pila) {
    if (!pila) return;
    free(pila->elementos);
    free(pila);
}

// Destructor con callback (datos por referencia)
void destruir_lista(lista_t* lista, void (*destruir_dato)(void*)) {
    nodo_t* actual = lista->inicio;
    while (actual) {
        nodo_t* siguiente = actual->siguiente;
        if (destruir_dato)
            destruir_dato(actual->dato);
        free(actual);
        actual = siguiente;
    }
    free(lista);
}
```

### Resumen de Tipificación

La siguiente tabla resume las siete categorías de operaciones:

| Tipo | Propósito | Modifica Estado | Retorna | Ejemplo |
|------|-----------|-----------------|---------|---------|
| **Constructor** | Prepara el terreno | — | Puntero nuevo | `crear_pila()` |
| **Selector** | Recupera información | ✗ | Dato almacenado | `ver_tope(pila)` |
| **Consultor** | Recupera meta-información | ✗ | Propiedad de la estructura | `esta_vacia(pila)` |
| **Iterador** | Recorre la información | ✗* | Elemento siguiente | `siguiente(iter)` |
| **Mutador** | Modifica la información | ✓ | Estado de éxito | `apilar(pila, dato)` |
| **Conversor** | Crea estructura similar | ✗ | Nueva estructura | `pila_a_arreglo(pila)` |
| **Destructor** | Libera recursos | — | `void` | `destruir_pila(pila)` |

*\* El iterador puede mantener estado interno de posición, pero no modifica la estructura recorrida.*

:::{tip} Aplicación Práctica
Cuando diseñes un nuevo TAD, usá esta tipificación como lista de verificación:
1. ¿Tengo un constructor que inicializa correctamente?
2. ¿Qué datos necesito seleccionar?
3. ¿Qué propiedades debo consultar?
4. ¿Cómo se recorrerá la estructura?
5. ¿Qué modificaciones son válidas?
6. ¿A qué otros formatos debo convertir?
7. ¿Liberé todos los recursos en el destructor?

Esta clasificación no solo organiza tu código, sino que comunica claramente la **intención** de cada función a quienes usen tu TAD.
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

:::{tip} Complejidad Asintótica
Las notaciones $O(1)$, $O(n)$, etc., describen el **comportamiento asintótico** del tiempo de ejecución. Para entender en profundidad qué significa la notación Big-O, cómo analizar algoritmos formalmente, y las diferentes notaciones asintóticas (Omega, Theta), consultá {ref}`complejidad-introduccion`.
:::

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

:::{note} Análisis de Complejidad
Esta tabla muestra las complejidades temporales en notación Big-O, que describe el **peor caso** del algoritmo. El apunte {ref}`complejidad-introduccion` explica en detalle cómo se derivan estas complejidades, qué significa cada notación, y cómo realizar análisis formal de algoritmos.
:::

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
La notación Big-O describe el comportamiento asintótico en el peor caso. En casos promedio o con estructuras auxiliares, las complejidades pueden variar. Para un análisis formal y riguroso del análisis asintótico, incluyendo las notaciones Omega ($\Omega$) y Theta ($\Theta$), consultá {ref}`complejidad-introduccion`.
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

```{figure} 13/pila_lista_enlazada.svg
:label: fig-pila-lista
:align: center

Representación en memoria de una pila implementada con lista enlazada. El tope apunta al primer nodo de la lista.
```

#### Estructura de Datos

```c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

struct pila {
    nodo_t *tope;
    size_t tamanio;
};
```

#### Creación de una Pila

```c
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

```c
bool pila_push(pila_t *pila, int dato)
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

```c
bool pila_pop(pila_t *pila, int *dato)
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

```c
bool pila_peek(const pila_t *pila, int *dato)
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

```c
bool pila_es_vacia(const pila_t *pila)
{
    return (pila == NULL) || (pila->tope == NULL);
}
```

#### Destruir Pila

```c
void pila_destruir(pila_t *pila)
{
    if (pila == NULL)
    {
        return;
    }
    
    while (pila->tope != NULL)
    {
        nodo_t *nodo_actual = pila->tope;
        pila->tope = nodo_actual->siguiente;
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

```{figure} 13/pila_arreglo.svg
:label: fig-pila-arreglo
:align: center

Pila implementada con arreglo. El índice `tope` indica la posición del último elemento.
```

#### Estructura de Datos

```c
struct pila {
    int *elementos;
    size_t tope;       // Próximo índice libre / Cantidad de elementos
    size_t capacidad;  // Capacidad total del arreglo
};
```

#### Creación con Capacidad Inicial

```c
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

```c
static bool pila_redimensionar(pila_t *pila)
{
    size_t nueva_capacidad = pila->capacidad * 2;
    int *nuevo_arreglo = realloc(pila->elementos, nueva_capacidad * sizeof(*nuevo_arreglo));
    if (nuevo_arreglo == NULL)
    {
        return false;
    }
    
    pila->elementos = nuevo_arreglo;
    pila->capacidad = nueva_capacidad;
    
    return true;
}

bool pila_push_arreglo(pila_t *pila, int dato)
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

```c
bool pila_pop_arreglo(pila_t *pila, int *dato)
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

```c
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

```{figure} 13/cola_queue.svg
:label: fig-cola
:align: center

Estructura de cola con operaciones enqueue (encolar) y dequeue (desencolar). Los elementos entran por el final y salen por el frente.
```

### Operaciones Fundamentales

- **enqueue(elemento):** Agrega un elemento al final de la cola.
- **dequeue():** Extrae y retorna el elemento del frente.
- **peek() o front():** Retorna el elemento del frente sin extraerlo.
- **es_vacia():** Verifica si la cola está vacía.

### Implementación con Lista Enlazada

```{figure} 13/cola_lista_enlazada.svg
:label: fig-cola-lista
:align: center

Representación en memoria de una cola implementada con lista enlazada. Se mantienen punteros al frente y al final.
```

#### Estructura de Datos

```c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

struct cola {
    nodo_t *frente;
    nodo_t *final;
    size_t tamanio;
};
```

:::{note}
A diferencia de la pila que solo requiere de un puntero al tope, la cola utiliza dos punteros: uno al frente (para `cola_dequeue`) y otro al final (para `cola_enqueue`). Esto garantiza que ambas operaciones se ejecuten en tiempo constante $O(1)$.
:::

#### Creación de una Cola

```c
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

```c
bool cola_enqueue(cola_t *cola, int dato)
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

```c
bool cola_dequeue(cola_t *cola, int *dato)
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

```c
bool cola_peek(const cola_t *cola, int *dato)
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

```c
void cola_destruir(cola_t *cola)
{
    if (cola == NULL)
    {
        return;
    }
    
    while (cola->frente != NULL)
    {
        nodo_t *nodo_actual = cola->frente;
        cola->frente = nodo_actual->siguiente;
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

```{figure} 13/cola_circular.svg
:label: fig-cola-circular
:align: center

Cola implementada como arreglo circular. Los índices se calculan módulo la capacidad.
```

#### Estructura de Datos

```c
struct cola {
    int *elementos;
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

```c
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

```c
static bool cola_redimensionar_circular(cola_t *cola)
{
    size_t nueva_capacidad = cola->capacidad * 2;
    int *nuevo_arreglo = malloc(nueva_capacidad * sizeof(*nuevo_arreglo));
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

bool cola_enqueue_circular(cola_t *cola, int dato)
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

```c
bool cola_dequeue_circular(cola_t *cola, int *dato)
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

```{figure} 13/deque.svg
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

````{exercise}
:label: ejercicio-invertir-cadena

Implementá una función que use una pila para invertir una cadena de caracteres.

```
función invertir_cadena(cadena: cadena) → cadena:
    // Tu implementación aquí
```

Por ejemplo:
- Entrada: "hola"
- Salida: "aloh"
````

### Ejercicio 2: Validar Expresiones con Múltiples Delimitadores

````{exercise}
:label: ejercicio-validar-delimitadores

Extendé el ejemplo de paréntesis balanceados para soportar múltiples tipos de delimitadores: `()`, `[]`, `{}`. La función debe verificar que:
1. Cada apertura tenga su cierre correspondiente
2. Los cierres ocurran en el orden correcto

```
función delimitadores_balanceados(expresion: cadena) → booleano:
    // Tu implementación aquí
```

Por ejemplo:
- `"{[()]}"` → válido
- `"{[(])}"` → inválido (cierre en orden incorrecto)
- `"{[("` → inválido (sin cerrar)
````

### Ejercicio 3: Simulador de Impresora

````{exercise}
:label: ejercicio-simulador-impresora

Implementá un simulador de cola de impresión que:
1. Reciba trabajos con un identificador y cantidad de páginas
2. Procese trabajos en orden FIFO
3. Reporte el tiempo total de procesamiento (asumí 1 segundo por página)

```
Trabajo:
    id: entero
    paginas: entero

función simular_impresora(trabajos: arreglo de Trabajo) → entero:
    // Retorna tiempo total de procesamiento
```
````

### Ejercicio 4: Implementar Cola con Dos Pilas

````{exercise}
:label: ejercicio-cola-dos-pilas

Implementá una cola usando dos pilas. La idea es:
- Una pila para `enqueue` (entrada)
- Una pila para `dequeue` (salida)
- Cuando la pila de salida está vacía, transferir todos los elementos de entrada a salida

```
Cola_con_Pilas:
    pila_entrada: Pila
    pila_salida: Pila

función enqueue_con_pilas(cola: Cola_con_Pilas, dato: entero) → booleano:
    // Tu implementación

función dequeue_con_pilas(cola: Cola_con_Pilas, dato: referencia a entero) → booleano:
    // Tu implementación
```

Analizá la complejidad amortizada de las operaciones.
````

### Ejercicio 5: Evaluación de Expresiones Postfijas

````{exercise}
:label: ejercicio-evaluar-postfija

Implementá un evaluador de expresiones en notación postfija (Reverse Polish Notation) usando una pila.

En notación postfija, los operadores vienen después de los operandos:
- Infija: `(3 + 4) * 5`
- Postfija: `3 4 + 5 *`

Algoritmo:
1. Recorrer la expresión
2. Si es número, apilar
3. Si es operador, desapilar dos operandos, aplicar operación, apilar resultado

```
función evaluar_postfija(expresion: cadena) → entero:
    // Tu implementación
```

Por ejemplo:
- `"3 4 + 5 *"` → 35
- `"15 7 1 1 + - / 3 * 2 1 1 + + -"` → 5
````

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