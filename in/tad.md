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

### Ejemplo Práctico: El TAD Pila (Stack) en C

Vamos a ilustrar el concepto completo con la implementación del TAD Pila.

#### 1. La Interfaz Pública (`stack.h`)
Este archivo define el tipo `Stack` como un puntero opaco y declara las operaciones que se pueden realizar sobre él.

```c
// stack.h

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * Declaración del tipo incompleto. El cliente solo sabe que existe un "stack_t",
 * pero no cómo está implementado.
 */
struct stack;
typedef struct stack stack_t;

/**
 * Crea y devuelve una nueva pila vacía.
 * 
 * Retorna: Puntero a la nueva pila, o NULL en caso de error de memoria.
 */
stack_t* stack_create(void);

/**
 * Destruye una pila y libera su memoria.
 * 
 * Parámetros:
 *   s - Puntero a la pila a destruir.
 */
void stack_destroy(stack_t* s);

/**
 * Añade un elemento al tope de la pila.
 * 
 * Parámetros:
 *   s - Puntero a la pila.
 *   value - Valor a añadir al tope.
 * 
 * Retorna: 0 si la operación fue exitosa, -1 si la pila está llena.
 */
int stack_push(stack_t* s, int value);

/**
 * Elimina y devuelve el elemento del tope.
 * 
 * Parámetros:
 *   s - Puntero a la pila.
 * 
 * Precondición: la pila no debe estar vacía.
 * 
 * Retorna: El valor extraído del tope.
 */
int stack_pop(stack_t* s);

/**
 * Devuelve el elemento del tope sin eliminarlo.
 * 
 * Parámetros:
 *   s - Puntero a la pila.
 * 
 * Precondición: la pila no debe estar vacía.
 * 
 * Retorna: El valor del elemento en el tope.
 */
int stack_peek(stack_t* s);

/**
 * Verifica si la pila está vacía.
 * 
 * Parámetros:
 *   s - Puntero a la pila.
 * 
 * Retorna: true si la pila está vacía, false en caso contrario.
 */
bool stack_is_empty(stack_t* s);

#endif
```

#### 2. La Implementación Privada (`stack.c`)
Aquí se define la estructura de datos (un arreglo dinámico) y se implementa la lógica de las funciones.

```c
// stack.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INITIAL_CAPACITY 10
#define EXITO 0
#define ERROR_MEMORIA -1

/**
 * Definición completa y privada del struct.
 * Solo es visible dentro de este archivo.
 */
struct stack
{
    int* items;
    int top;
    int capacity;
};

/**
 * Crea y devuelve una nueva pila vacía.
 * Devuelve NULL en caso de error de asignación de memoria.
 */
stack_t* stack_create()
{
    stack_t* s = NULL;
    int* items_temp = NULL;
    
    s = (stack_t*) malloc(sizeof(stack_t));
    
    if (s == NULL)
    {
        return NULL;
    }
    
    items_temp = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    
    if (items_temp == NULL)
    {
        free(s);
        s = NULL;
        return NULL;
    }
    
    s->items = items_temp;
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    
    return s;
}

/**
 * Destruye una pila y libera su memoria.
 */
void stack_destroy(stack_t* s)
{
    if (s != NULL)
    {
        free(s->items);
        free(s);
    }
}

/**
 * Añade un elemento al tope de la pila.
 * Devuelve EXITO si la operación fue exitosa, ERROR_MEMORIA si la pila está llena.
 */
int stack_push(stack_t* s, int value)
{
    int resultado = ERROR_MEMORIA;
    
    if (s->top < s->capacity - 1)
    {
        s->top = s->top + 1;
        s->items[s->top] = value;
        resultado = EXITO;
    }
    
    return resultado;
}

/**
 * Elimina y devuelve el elemento del tope.
 * Precondición: la pila no debe estar vacía.
 * Devuelve el valor extraído, o termina el programa si la pila está vacía.
 */
int stack_pop(stack_t* s)
{
    int value = 0;
    bool pila_vacia = false;
    
    pila_vacia = stack_is_empty(s);
    
    if (pila_vacia == false)
    {
        value = s->items[s->top];
        s->top = s->top - 1;
    }
    else
    {
        fprintf(stderr, "Error: pop en una pila vacía.\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

/**
 * Devuelve el elemento del tope sin eliminarlo.
 * Precondición: la pila no debe estar vacía.
 * Devuelve el valor del tope, o termina el programa si la pila está vacía.
 */
int stack_peek(stack_t* s)
{
    int value = 0;
    bool pila_vacia = false;
    
    pila_vacia = stack_is_empty(s);
    
    if (pila_vacia == false)
    {
        value = s->items[s->top];
    }
    else
    {
        fprintf(stderr, "Error: peek en una pila vacía.\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

/**
 * Verifica si la pila está vacía.
 * Devuelve true si está vacía, false en caso contrario.
 */
bool stack_is_empty(stack_t* s)
{
    bool esta_vacia = false;
    
    if (s->top == -1)
    {
        esta_vacia = true;
    }
    
    return esta_vacia;
}
```

#### 3. El Código Cliente (`main.c`)
El cliente utiliza la pila a través de su interfaz pública sin conocer ningún detalle de la implementación.

```c
// main.c
#include <stdio.h>
#include "stack.h"

int main(void)
{
    stack_t* mi_pila = NULL;
    int valor = 0;
    int tope = 0;
    int resultado_push = 0;
    
    mi_pila = stack_create();
    
    /**
     * El cliente NO PUEDE hacer esto, resultaría en un error de compilación:
     * mi_pila->top = 5;
     * ERROR: tipo 'stack_t' {aka 'struct stack'} incompleto
     */
    
    resultado_push = stack_push(mi_pila, 10);
    resultado_push = stack_push(mi_pila, 20);
    
    tope = stack_peek(mi_pila);
    printf("El tope de la pila es: %d\n", tope);
    
    valor = stack_pop(mi_pila);
    printf("Valor extraído: %d\n", valor);
    
    tope = stack_peek(mi_pila);
    printf("El nuevo tope es: %d\n", tope);
    
    stack_destroy(mi_pila);
    
    return 0;
}
```

Este enfoque disciplinado permite que C, a pesar de ser un lenguaje procedural, se beneficie de los mismos principios de diseño de software robusto que los TAD promueven en otros paradigmas.


