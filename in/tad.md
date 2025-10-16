---
title: "Tipos de Datos Abstractos (TAD): El Pilar de la Abstracción en Software"
description:
  "Un apunte exhaustivo que explora qué son los TAD, su diferencia con las
  estructuras de datos, ejemplos clásicos, una metodología para diseñarlos y su
  relación con la POO."
---

# Tipos de Datos Abstractos (TAD): El Pilar de la Abstracción

En la ingeniería de software, uno de los desafíos más grandes es gestionar la
complejidad. Los **Tipos de Datos Abstractos (TAD)** son un concepto fundamental
que nos permite lograrlo a través de la **abstracción**, separando el "qué" del
"cómo".

Un TAD es un **modelo matemático** de un tipo de dato. Se define por:

1.  Un **conjunto de valores** que el tipo de dato puede representar.
2.  Un **conjunto de operaciones** que se pueden realizar sobre esos valores.

La característica crucial de un TAD es que define una **interfaz** (las
operaciones permitidas) sin especificar absolutamente nada sobre su
**implementación** (cómo se almacenan los datos o cómo se ejecutan esas
operaciones).

:::{tip} Analogía: El Control Remoto de un Televisor

Pensá en un control remoto. Su interfaz son los botones: `encender()`,
`subirVolumen()`, `cambiarCanal(numero)`. Sabés **qué** hace cada botón, y podés
usarlos sin necesidad de entender los circuitos internos. El control remoto es
el TAD; la electrónica interna es la implementación.

:::

## El Principio Fundamental: Separación de Interfaz e Implementación

Este es el corazón de un TAD. El "usuario" o "cliente" del TAD solo necesita
conocer la interfaz pública para interactuar con el dato. La implementación
interna está oculta, un principio conocido como **encapsulamiento** o
**ocultamiento de la información**.

```{mermaid}
graph TD
    subgraph Cliente (Usuario del TAD)
        A[Programa Principal]
    end
    subgraph "Interfaz Pública (El 'Qué')"
        B(Operación 1)
        C(Operación 2)
        D(Operación 3)
    end
    subgraph "Implementación Privada (El 'Cómo')"
        E{Estructura de Datos}
        F{Lógica de Operaciones}
    end
    A --> B; A --> C; A --> D
    B & C & D -.-> F --> E
    style "Implementación Privada (El 'Cómo')" fill:#f9f,stroke:#333,stroke-width:2px,stroke-dasharray: 5 5
```

Este desacoplamiento nos brinda enormes beneficios: modularidad, reutilización,
flexibilidad y reducción de la complejidad.

## TAD vs. Estructura de Datos

- **TAD**: Es un concepto lógico, una **especificación** de comportamiento (el
  "qué").
- **Estructura de Datos**: Es una implementación concreta, una **organización**
  de datos en memoria (el "cómo").

---

# Ejemplos Clásicos de Tipos de Datos Abstractos

- **Lista (List)**: Colección ordenada y posicionada de elementos.
- **Pila (Stack)**: Colección LIFO (Last-In, First-Out).
- **Cola (Queue)**: Colección FIFO (First-In, First-Out).
- **Cola de Prioridad (Priority Queue)**: Los elementos se extraen según su
  prioridad.
- **Mapa (Map / Diccionario)**: Colección de pares clave-valor únicos.

---

# Metodología para el Diseño de un TAD Propio

Crear un TAD es un ejercicio de diseño centrado en la abstracción. Seguir un
proceso metodológico asegura que el resultado sea robusto, claro y útil.

1.  **Conceptualización**: Identificar la entidad a modelar, sus datos y sus
    reglas.
2.  **Definición de la Interfaz Pública**: Listar las operaciones, definir sus
    firmas (parámetros, retorno) y documentar su comportamiento (precondiciones,
    postcondiciones).
3.  **Especificación Formal (Opcional)**: Definir axiomas que describan cómo
    interactúan las operaciones.
4.  **Elección de la Estructura de Datos**: Evaluar candidatos (arreglos,
    listas, árboles) y analizar su complejidad para cada operación de la
    interfaz.
5.  **Implementación**: Escribir el código, encapsulando la estructura de datos
    interna y exponiendo solo la interfaz pública.

---

# La Relación Intrínseca con la Programación Orientada a Objetos (POO)

El paradigma de la Programación Orientada a Objetos no solo se alinea con los
principios de los TAD, sino que puede considerarse su **implementación natural y
evolución lógica**. La POO proporciona las herramientas lingüísticas y
estructurales para llevar el concepto teórico de un TAD a una realidad práctica
y robusta en el código.

La conexión se establece a través de los siguientes conceptos clave:

### 1. Clase como Implementación de un TAD

Una **clase** en POO es la materialización directa de un TAD.

- **El estado del TAD** (su conjunto de valores) se representa mediante los
  **atributos** o **miembros de datos** de la clase.
- **Las operaciones del TAD** se implementan como los **métodos** de la clase.

Una clase agrupa datos y las operaciones que los manipulan en una única unidad
lógica, exactamente como lo especifica un TAD.

### 2. Encapsulamiento y Ocultamiento de la Información

El principio más importante de un TAD es la separación entre interfaz e
implementación. La POO lo refuerza mediante **modificadores de acceso**.

- **Atributos Privados (`private`)**: Al declarar los datos internos como
  privados, se impide el acceso directo y no controlado desde fuera de la clase.
  Esto protege los **invariantes** del TAD (las reglas que siempre deben
  cumplirse). El estado interno solo puede ser modificado a través de los
  métodos públicos.
- **Métodos Públicos (`public`)**: Estos métodos forman la **interfaz pública**
  del TAD, el contrato que la clase ofrece al mundo exterior. Son la única
  puerta de entrada para interactuar con el objeto.

### 3. Abstracción a través de Interfaces y Clases Abstractas

La POO lleva la abstracción un paso más allá.

- Una **interfaz** (en lenguajes como Java o C#) o una **clase base abstracta**
  (en C++) permite definir un TAD de forma pura: se especifican las firmas de
  los métodos (las operaciones) sin proporcionar _ninguna_ implementación.
- Esto permite que múltiples clases, cada una con una estructura de datos
  interna diferente, implementen el mismo TAD. Por ejemplo, tanto una clase
  `ArrayList` (basada en un arreglo) como una clase `LinkedList` (basada en una
  lista enlazada) pueden implementar la interfaz `List`. Para el cliente, ambas
  son "Listas" intercambiables, un concepto conocido como **polimorfismo**.

### Mapeo de Conceptos: TAD <-> POO

| Concepto del Tipo de Dato Abstracto (TAD) | Herramienta en Programación Orientada a Objetos (POO)        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Tipo de Dato (el concepto)                | Clase o Interfaz                                             |
| Un valor/instancia del tipo               | Un Objeto (instancia de la clase)                            |
| Conjunto de operaciones                   | Métodos Públicos                                             |
| Estado interno / Datos                    | Atributos Privados                                           |
| Ocultamiento de la información            | Modificador de acceso `private`                              |
| Interfaz / Contrato                       | Interfaz Pública de la Clase / Definición de una `interface` |

En resumen, la Programación Orientada a Objetos no es solo "una forma" de
implementar TADs; es el paradigma que fue diseñado en gran parte para formalizar
y aplicar estos principios de abstracción y encapsulamiento de manera
sistemática y segura en el desarrollo de software a gran escala.

---
title: "Implementación de Tipos de Datos Abstractos (TAD) en Lenguaje C"
description: "Un análisis sobre cómo implementar el concepto de Tipos de Datos Abstractos en un lenguaje procedural como C, utilizando punteros opacos y una separación clara entre interfaz e implementación."
---

# Implementación de Tipos de Datos Abstractos (TAD) en Lenguaje C

El lenguaje C, al ser un lenguaje de programación **procedural** y no orientado a objetos, carece de construcciones nativas como las clases para implementar Tipos de Datos Abstractos (TAD) de forma directa. Sin embargo, C proporciona todos los mecanismos necesarios para emular los principios fundamentales de un TAD —abstracción, encapsulamiento y ocultamiento de la información— de una manera robusta y modular.

La estrategia en C se basa en una disciplina de diseño que separa rigurosamente la **interfaz pública** de la **implementación privada** utilizando archivos de cabecera y de código fuente.

## Los Componentes Clave en C

1.  **El Archivo de Cabecera (`.h`): La Interfaz Pública**
    -   Este archivo es el **contrato** del TAD. Es lo único que el "cliente" (otro módulo del programa) necesita incluir para usar el tipo de dato.
    -   Contiene las declaraciones de las funciones que operan sobre el dato (la interfaz del TAD).
    -   Contiene la declaración del tipo de dato, pero de una manera que oculta su estructura interna.

2.  **El Archivo de Código Fuente (`.c`): La Implementación Privada**
    -   Este archivo contiene el "secreto" del TAD.
    -   Aquí se define la **estructura de datos** concreta (el `struct`) que almacena la información.
    -   Aquí se escribe el código de las funciones declaradas en el archivo de cabecera.
    -   Esta parte es completamente invisible para el cliente.

## Simulando Encapsulamiento con Punteros Opacos

El mecanismo más poderoso en C para lograr el ocultamiento de la información es el uso de un **puntero opaco** (opaque pointer) o **tipo incompleto** (incomplete type).

La técnica funciona así:

1.  En el archivo de cabecera (`.h`), se declara un `struct` y se le da un alias con `typedef`, pero **no se define su contenido**.
    ```c
    // mi_tad.h
    struct mi_tad; // Declaración incompleta
    typedef struct mi_tad mi_tad_t;
    ```
    Para el compilador, `mi_tad_t` es ahora un tipo de dato conocido, pero de tamaño desconocido. Debido a esto, no se pueden crear variables de tipo `mi_tad_t` directamente en la pila, pero sí se pueden crear **punteros** a él (`mi_tad_t*`), ya que el tamaño de un puntero es siempre conocido.

2.  En el archivo de código fuente (`.c`), se proporciona la definición completa del `struct`.
    ```c
    // mi_tad.c
    #include "mi_tad.h"
    
    struct mi_tad
    {
        int dato1;
        char* dato2;
    };
    ```
    Solo el código dentro de `mi_tad.c` conoce la estructura interna de `mi_tad_t` y puede acceder a sus miembros (`dato1`, `dato2`). El cliente, que solo incluye `mi_tad.h`, no puede hacerlo, logrando así un encapsulamiento efectivo.

### Ejemplo Práctico: El TAD Secuencia (Sequence) en C

Vamos a ilustrar el concepto completo con la implementación del TAD Secuencia. Este ejemplo es particularmente instructivo porque demuestra cómo un mismo comportamiento puede implementarse de distintas maneras.

Una **secuencia** es una colección ordenada de elementos que permite acceso posicional: insertar, eliminar y consultar elementos en cualquier posición.

#### 1. La Interfaz Pública (`sequence.h`)
Este archivo define el tipo `sequence_t` como un puntero opaco y declara las operaciones fundamentales sobre él.

```c
// sequence.h

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Declaración del tipo incompleto. El cliente solo sabe que existe una "sequence_t",
 * pero no cómo está implementada internamente.
 */
struct sequence;
typedef struct sequence sequence_t;

/**
 * Crea y devuelve una nueva secuencia vacía.
 * 
 * Retorna: Puntero a la nueva secuencia, o NULL en caso de error de memoria.
 */
sequence_t* sequence_create(void);

/**
 * Destruye una secuencia y libera su memoria.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia a destruir.
 */
void sequence_destroy(sequence_t* seq);

/**
 * Inserta un elemento en la posición especificada de la secuencia.
 * Los elementos desde la posición hasta el final se desplazan una posición hacia la derecha.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 *   pos - Posición donde insertar (0 <= pos <= tamaño actual).
 *   value - Valor a insertar.
 * 
 * Retorna: 0 si la operación fue exitosa, -1 en caso de error (posición inválida o falta de memoria).
 */
int sequence_insert(sequence_t* seq, size_t pos, int value);

/**
 * Elimina el elemento en la posición especificada.
 * Los elementos posteriores se desplazan una posición hacia la izquierda.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 *   pos - Posición del elemento a eliminar.
 * 
 * Precondición: la posición debe ser válida (0 <= pos < tamaño).
 * 
 * Retorna: El valor del elemento eliminado, o termina el programa si la posición es inválida.
 */
int sequence_remove(sequence_t* seq, size_t pos);

/**
 * Obtiene el valor del elemento en la posición especificada sin eliminarlo.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 *   pos - Posición del elemento a consultar.
 * 
 * Precondición: la posición debe ser válida (0 <= pos < tamaño).
 * 
 * Retorna: El valor del elemento en la posición, o termina el programa si la posición es inválida.
 */
int sequence_get(sequence_t* seq, size_t pos);

/**
 * Modifica el valor del elemento en la posición especificada.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 *   pos - Posición del elemento a modificar.
 *   value - Nuevo valor para el elemento.
 * 
 * Precondición: la posición debe ser válida (0 <= pos < tamaño).
 * 
 * Retorna: 0 si la operación fue exitosa, -1 si la posición es inválida.
 */
int sequence_set(sequence_t* seq, size_t pos, int value);

/**
 * Devuelve la cantidad de elementos en la secuencia.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 * 
 * Retorna: Número de elementos en la secuencia.
 */
size_t sequence_size(sequence_t* seq);

/**
 * Verifica si la secuencia está vacía.
 * 
 * Parámetros:
 *   seq - Puntero a la secuencia.
 * 
 * Retorna: true si la secuencia está vacía, false en caso contrario.
 */
bool sequence_is_empty(sequence_t* seq);

#endif
```

#### 2. La Implementación Privada con Lista Enlazada (`sequence.c`)

Esta implementación utiliza una **lista enlazada simple** como estructura de datos interna. La elección de esta estructura demuestra el principio clave de un TAD: la interfaz pública permanece invariable, pero la implementación interna puede ser completamente diferente.

```c
// sequence.c
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

#define EXITO 0
#define ERROR_MEMORIA -1
#define ERROR_POSICION_INVALIDA -1

/**
 * Nodo de la lista enlazada.
 * Esta estructura es completamente privada.
 */
struct node
{
    int data;
    struct node* next;
};

typedef struct node node_t;

/**
 * Definición completa y privada de la secuencia.
 * Implementada como una lista enlazada simple.
 * Solo es visible dentro de este archivo.
 */
struct sequence
{
    node_t* head;
    size_t size;
};

/**
 * Crea y devuelve una nueva secuencia vacía.
 * Devuelve NULL en caso de error de asignación de memoria.
 */
sequence_t* sequence_create(void)
{
    sequence_t* seq = NULL;
    
    seq = (sequence_t*) malloc(sizeof(sequence_t));
    
    if (seq == NULL)
    {
        return NULL;
    }
    
    seq->head = NULL;
    seq->size = 0;
    
    return seq;
}

/**
 * Destruye una secuencia y libera toda su memoria.
 */
void sequence_destroy(sequence_t* seq)
{
    node_t* current = NULL;
    node_t* next = NULL;
    
    if (seq != NULL)
    {
        current = seq->head;
        
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
        
        free(seq);
    }
}

/**
 * Inserta un elemento en la posición especificada.
 * Devuelve EXITO si la operación fue exitosa, ERROR_MEMORIA o ERROR_POSICION_INVALIDA en caso de error.
 */
int sequence_insert(sequence_t* seq, size_t pos, int value)
{
    node_t* new_node = NULL;
    node_t* current = NULL;
    size_t i = 0;
    
    if (pos > seq->size)
    {
        return ERROR_POSICION_INVALIDA;
    }
    
    new_node = (node_t*) malloc(sizeof(node_t));
    
    if (new_node == NULL)
    {
        return ERROR_MEMORIA;
    }
    
    new_node->data = value;
    new_node->next = NULL;
    
    if (pos == 0)
    {
        new_node->next = seq->head;
        seq->head = new_node;
    }
    else
    {
        current = seq->head;
        
        for (i = 0; i < pos - 1; i = i + 1)
        {
            current = current->next;
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
    
    seq->size = seq->size + 1;
    
    return EXITO;
}

/**
 * Elimina el elemento en la posición especificada.
 * Precondición: la posición debe ser válida.
 * Devuelve el valor extraído, o termina el programa si la posición es inválida.
 */
int sequence_remove(sequence_t* seq, size_t pos)
{
    node_t* to_remove = NULL;
    node_t* current = NULL;
    size_t i = 0;
    int value = 0;
    
    if (pos >= seq->size)
    {
        fprintf(stderr, "Error: posición inválida en sequence_remove.\n");
        exit(EXIT_FAILURE);
    }
    
    if (pos == 0)
    {
        to_remove = seq->head;
        seq->head = seq->head->next;
    }
    else
    {
        current = seq->head;
        
        for (i = 0; i < pos - 1; i = i + 1)
        {
            current = current->next;
        }
        
        to_remove = current->next;
        current->next = to_remove->next;
    }
    
    value = to_remove->data;
    free(to_remove);
    seq->size = seq->size - 1;
    
    return value;
}

/**
 * Obtiene el valor del elemento en la posición especificada.
 * Precondición: la posición debe ser válida.
 * Devuelve el valor del elemento, o termina el programa si la posición es inválida.
 */
int sequence_get(sequence_t* seq, size_t pos)
{
    node_t* current = NULL;
    size_t i = 0;
    int value = 0;
    
    if (pos >= seq->size)
    {
        fprintf(stderr, "Error: posición inválida en sequence_get.\n");
        exit(EXIT_FAILURE);
    }
    
    current = seq->head;
    
    for (i = 0; i < pos; i = i + 1)
    {
        current = current->next;
    }
    
    value = current->data;
    
    return value;
}

/**
 * Modifica el valor del elemento en la posición especificada.
 * Devuelve EXITO si la operación fue exitosa, ERROR_POSICION_INVALIDA si la posición es inválida.
 */
int sequence_set(sequence_t* seq, size_t pos, int value)
{
    node_t* current = NULL;
    size_t i = 0;
    
    if (pos >= seq->size)
    {
        return ERROR_POSICION_INVALIDA;
    }
    
    current = seq->head;
    
    for (i = 0; i < pos; i = i + 1)
    {
        current = current->next;
    }
    
    current->data = value;
    
    return EXITO;
}

/**
 * Devuelve la cantidad de elementos en la secuencia.
 */
size_t sequence_size(sequence_t* seq)
{
    return seq->size;
}

/**
 * Verifica si la secuencia está vacía.
 * Devuelve true si está vacía, false en caso contrario.
 */
bool sequence_is_empty(sequence_t* seq)
{
    bool esta_vacia = false;
    
    if (seq->size == 0)
    {
        esta_vacia = true;
    }
    
    return esta_vacia;
}
```

#### 3. El Código Cliente (`main.c`)

El cliente utiliza la secuencia a través de su interfaz pública sin tener conocimiento alguno de la lista enlazada interna.

```c
// main.c
#include <stdio.h>
#include "sequence.h"

int main(void)
{
    sequence_t* mi_secuencia = NULL;
    int valor = 0;
    size_t tam = 0;
    int resultado = 0;
    
    mi_secuencia = sequence_create();
    
    /**
     * El cliente NO PUEDE hacer esto, resultaría en un error de compilación:
     * mi_secuencia->head = NULL;
     * ERROR: tipo 'sequence_t' {aka 'struct sequence'} incompleto
     */
    
    resultado = sequence_insert(mi_secuencia, 0, 10);
    resultado = sequence_insert(mi_secuencia, 1, 20);
    resultado = sequence_insert(mi_secuencia, 1, 15);
    
    tam = sequence_size(mi_secuencia);
    printf("Tamaño de la secuencia: %zu\n", tam);
    
    valor = sequence_get(mi_secuencia, 0);
    printf("Elemento en posición 0: %d\n", valor);
    
    valor = sequence_get(mi_secuencia, 1);
    printf("Elemento en posición 1: %d\n", valor);
    
    valor = sequence_get(mi_secuencia, 2);
    printf("Elemento en posición 2: %d\n", valor);
    
    valor = sequence_remove(mi_secuencia, 1);
    printf("Elemento eliminado en posición 1: %d\n", valor);
    
    tam = sequence_size(mi_secuencia);
    printf("Nuevo tamaño: %zu\n", tam);
    
    sequence_destroy(mi_secuencia);
    
    return 0;
}
```

### La Abstracción en Acción: Distintas Implementaciones, Mismo Comportamiento

El ejemplo anterior demuestra uno de los principios más poderosos de los TAD: **la separación total entre interfaz e implementación**. La secuencia se implementó usando una lista enlazada simple, pero la interfaz pública (`sequence.h`) no revela este detalle en absoluto.

Esto significa que podríamos reimplementar completamente el archivo `sequence.c` usando una estructura de datos diferente —como un arreglo dinámico, una lista doblemente enlazada o incluso un árbol B— y **el código cliente no requeriría ninguna modificación**. Mientras la nueva implementación respete el contrato definido por la interfaz (las firmas de las funciones y su comportamiento documentado), el cambio es completamente transparente.

#### Otras Estrategias de Implementación de Secuencias

La elección de la estructura de datos interna tiene implicaciones directas en el rendimiento de las operaciones. A continuación se presentan algunas alternativas comunes:

**1. Arreglo Dinámico (Dynamic Array)**
   - **Ventajas**: Acceso aleatorio en tiempo constante O(1) para `sequence_get()` y `sequence_set()`. Buena localidad de caché.
   - **Desventajas**: Inserción y eliminación en posiciones arbitrarias requiere desplazar elementos O(n). Puede requerir redimensionamiento (costoso, aunque amortizado O(1) si se dobla la capacidad).
   - **Uso ideal**: Cuando predominan las operaciones de acceso posicional y las inserciones/eliminaciones son raras o al final de la secuencia.

**2. Lista Enlazada Simple (Singly Linked List)** *(implementación mostrada)*
   - **Ventajas**: Inserción y eliminación en el frente de la secuencia en tiempo constante O(1). No requiere redimensionamiento.
   - **Desventajas**: Acceso aleatorio requiere recorrido lineal O(n). Mayor uso de memoria por los punteros.
   - **Uso ideal**: Cuando predominan las inserciones al inicio o se recorre la secuencia secuencialmente.

**3. Lista Doblemente Enlazada (Doubly Linked List)**
   - **Ventajas**: Permite recorrido bidireccional. Inserción y eliminación eficientes en ambos extremos O(1). Eliminación de un nodo dado (si se tiene el puntero) en O(1).
   - **Desventajas**: Mayor uso de memoria que la lista simple. Acceso aleatorio sigue siendo O(n).
   - **Uso ideal**: Cuando se requiere recorrido en ambas direcciones o eliminación eficiente de elementos conocidos.

**4. Arreglo con Hueco (Gap Buffer)**
   - **Ventajas**: Optimizado para operaciones concentradas en una "región de edición". Común en editores de texto.
   - **Desventajas**: Rendimiento degradado si las operaciones saltan entre posiciones distantes.
   - **Uso ideal**: Aplicaciones donde las modificaciones se concentran en una región local que se mueve gradualmente (ej. cursor de editor).

**5. Lista con Índice Auxiliar (Skip List o árbol de índices)**
   - **Ventajas**: Combina las ventajas de listas (inserción eficiente) con acceso aleatorio más rápido (O(log n) en lugar de O(n)).
   - **Desventajas**: Mayor complejidad de implementación y uso de memoria.
   - **Uso ideal**: Cuando se necesita un balance entre acceso aleatorio e inserciones/eliminaciones frecuentes.

:::{important} El Poder de la Abstracción

El TAD Secuencia define **qué** operaciones están disponibles (insertar, eliminar, obtener), pero no **cómo** se realizan internamente. Esta separación permite:

- **Flexibilidad**: Cambiar la implementación sin modificar el código cliente.
- **Optimización contextual**: Elegir la estructura de datos óptima según el patrón de uso de la aplicación.
- **Evolución del software**: Mejorar el rendimiento o la funcionalidad interna sin romper código existente.

La elección de la implementación debe basarse en el **perfil de uso** de la secuencia en el contexto específico de la aplicación.

:::

Este enfoque disciplinado permite que C, a pesar de ser un lenguaje procedural, se beneficie de los mismos principios de diseño de software robusto que los TAD promueven en otros paradigmas.


