---
title: 'Aritmética de punteros y matrices dinámicas'
short_title: 'Punteros II - aritmética'
description: 'Indirecciones múltiples, punteros a arrays, aritmética pura y matrices en memoria dinámica.'
---

(capitulo-aritmetica-punteros)=
# Referencias y Lecturas Complementarias

## Introducción



## Desarrollo

(introduccion_aritmetica_punteros)=
### Introducción


Este apunte explora conceptos avanzados de memoria dinámica en C, construyendo sobre las bases presentadas en {ref}`Modelo de Memoria <capitulo-modelo-memoria>` y {ref}`Punteros <capitulo-punteros>`. Aquí profundizamos en el manejo de {ref}`Estructuras <capitulo-estructuras>` que contienen punteros, problemas comunes de gestión de memoria, y técnicas para trabajar con matrices dinámicas.


(punteros-a-estructuras)=
### Punteros a Estructuras


Cuando una estructura (`struct`) contiene punteros a otros datos, debemos gestionar la memoria en **múltiples niveles**. Como vimos en {ref}`el-monton-heap`, cada llamada a `malloc` reserva memoria en el heap que debe ser liberada explícitamente. Con estructuras anidadas, este principio se aplica recursivamente.

(creacion-de-estructuras-dinamicas)=
#### Creación de Estructuras Dinámicas

Para crear una instancia de una estructura que contiene punteros (como `char* nombre`), se requieren múltiples asignaciones de memoria. Consideremos una estructura `persona_t`:

```{code-block}c
typedef struct {
    char *nombre;
    int edad;
} persona_t;
```

El proceso de creación involucra **tres pasos fundamentales**:

##### Paso 1: Asignar la Estructura Contenedora

Primero, reservamos memoria para la estructura en sí:

```{code-block}c
:linenos:
persona_t *nuevo = malloc(sizeof(persona_t));
if (nuevo == NULL) {
    // Manejar error de asignación
    return NULL;
}
```

:::{tip} Buena Práctica: Siempre Verificar `malloc`
Como se detalla en {ref}`verificar-asignaciones`, **nunca** asumas que `malloc` tiene éxito. Siempre verificá que el puntero retornado no sea `NULL` antes de usarlo.
:::

##### Paso 2: Asignar Miembros Internos

Luego, reservamos memoria para cada puntero dentro de la estructura:

```{code-block}c
:linenos:
// +1 para el carácter nulo '\0'
nuevo->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
if (nuevo->nombre == NULL) {
    free(nuevo);  // Liberar lo ya asignado
    return NULL;
}
```

:::{warning} Cuidado con el Orden de Liberación
Si la segunda asignación falla, debemos liberar la primera antes de retornar. De lo contrario, causamos un **memory leak** (fuga de memoria).
:::

##### Paso 3: Copiar Datos

Finalmente, copiamos los datos a la memoria recién asignada:

```{code-block}c
:linenos:
strcpy(nuevo->nombre, nombre);
nuevo->edad = edad;
```

(operador-flecha)=
#### Operador Flecha (`->`)

El operador `->` es un **atajo sintáctico** para acceder a miembros de una estructura a través de un puntero. Como se explica en {ref}`Punteros <capitulo-punteros>`, este operador combina la desreferencia y el acceso a miembro en una sola operación.

**Equivalencia:**
```{code-block}c
:linenos:
puntero->miembro  ≡  (*puntero).miembro
```

**Ejemplo comparativo:**

```{code-block}c
:linenos:
persona_t *p = /* ... */;

// Usando ->
p->edad = 30;
p->nombre[0] = 'J';

// Equivalente sin ->
(*p).edad = 30;
(*p).nombre[0] = 'J';
```

La notación con `->` es más legible y es la **forma idiomática** en C para trabajar con punteros a estructuras.

(destruccion-de-estructuras-dinamicas)=
#### Destrucción de Estructuras Dinámicas

La liberación de memoria debe seguir el **orden inverso** al de la creación. Este patrón se conoce como **"de adentro hacia afuera"** o **LIFO** (Last In, First Out).

##### Orden Correcto de Liberación

```{code-block}c
:linenos:
void persona_destruir(persona_t *persona) {
    if (persona == NULL) {
        return;  // Nada que hacer
    }
    
    // 1. Liberar miembros internos primero
    free(persona->nombre);
    
    // 2. Liberar la estructura contenedora
    free(persona);
}
```

##### ¿Por Qué Este Orden?

Si liberás `persona` primero, **perdés el puntero** a `persona->nombre`. Una vez que `free(persona)` se ejecuta, acceder a `persona->nombre` es **comportamiento indefinido** (ver {ref}`dangling-pointer-puntero-colgante`). Esto resulta en un **memory leak** porque la memoria de `nombre` queda asignada pero inaccesible.

```{figure} 2/destruccion_orden.svg
:label: fig-destruccion-orden
:align: center
:width: 85%

Orden correcto vs incorrecto de liberación de memoria en estructuras anidadas.
```

:::{danger} Error Común: Orden Incorrecto
```{code-block}c
:linenos:
// INCORRECTO
free(persona);          // Ahora persona->nombre es inaccesible
free(persona->nombre);  // ¡Comportamiento indefinido!
```

Una vez que `persona` se libera, acceder a cualquiera de sus miembros (incluyendo `nombre`) invoca **undefined behavior**.
:::

##### Generalización: Estructuras con Múltiples Punteros

Para estructuras con varios niveles de punteros, aplicá el mismo principio recursivamente:

```{code-block}c
:linenos:
typedef struct {
    char *nombre;
    char *apellido;
    int *calificaciones;  // Array dinámico
} estudiante_t;

void estudiante_destruir(estudiante_t *est) {
    if (est == NULL) return;
    
    free(est->calificaciones);  // Nivel más profundo primero
    free(est->apellido);
    free(est->nombre);
    free(est);                  // Contenedor al final
}
```

(ejercicios-de-autoevaluacion-punteros-a-estructuras)=
#### Ejercicios de Autoevaluación (Punteros a Estructuras)







---


(problemas-comunes-de-memoria-dinamica)=
### Problemas Comunes de Memoria Dinámica


Esta sección detalla errores frecuentes en la gestión de memoria dinámica y sus soluciones. Estos problemas se amplían en {ref}`errores-comunes-y-peligros`.

(fragmentacion-del-heap)=
#### Fragmentación del Heap

La **fragmentación externa** ocurre cuando la memoria libre se divide en bloques pequeños y no contiguos, aunque la suma total de memoria libre sea suficiente para una solicitud.

##### Escenario Ilustrativo

```{figure} 2/fragmentacion_heap.svg
:label: fig-fragmentacion-heap
:align: center
:width: 90%

Proceso de fragmentación del heap: bloques libres no contiguos impiden asignaciones grandes.
```

**Problema:** Aunque hay 150 KB libres (100 + 50), no podés asignar un bloque contiguo de 120 KB.

##### Soluciones

```{list-table} Estrategias contra Fragmentación
:header-rows: 1
:name: tbl-fragmentacion

* - Estrategia
  - Descripción
  - Cuándo Usar
* - Asignación en bloque
  - Pedir memoria en bloques grandes, subdividir internamente
  - Arrays redimensionables, pools de objetos
* - Memory pools
  - Pre-asignar conjunto de objetos del mismo tamaño
  - Asignaciones/liberaciones frecuentes del mismo tipo
* - Compactación
  - Reorganizar bloques para unir espacios libres
  - Raramente posible en C (requiere actualizar punteros)
```

:::{tip} Práctica Recomendada
En lugar de asignar cada elemento de una lista por separado, asigná un array de elementos y gestioná el crecimiento con `realloc` (ver {ref}`realloc-re-allocation`).
:::

(punteros-colgantes-dangling-pointers)=
#### Punteros Colgantes (Dangling Pointers)

Un **puntero colgante** (_dangling pointer_) es un puntero que apunta a memoria que ya ha sido liberada con `free`. Este es uno de los errores más peligrosos en C (ver {ref}`dangling-pointer-puntero-colgante` para más detalles).

##### Causa

Cuando llamás `free(puntero)`, la memoria se libera pero **la variable `puntero` no cambia**. Sigue conteniendo la dirección antigua, que ahora es inválida.

```{code-block}c
:linenos:
int *datos = malloc(sizeof(int) * 10);
// ... usar datos ...
free(datos);
// En este punto, 'datos' sigue apuntando a la dirección antigua
// pero esa memoria puede estar siendo usada por otra parte del programa
```

##### Riesgo: Comportamiento Indefinido

Usar un puntero colgante (leer o escribir) invoca **undefined behavior**. El programa puede:
- Aparentar funcionar correctamente (el peor caso, porque oculta el error)
- Crashear inmediatamente
- Corromper otros datos silenciosamente
- Comportarse de forma impredecible

```{code-block}c
:linenos:
free(datos);
datos[0] = 42;  // UNDEFINED BEHAVIOR
```

##### Solución: Poner en `NULL` Después de `free`

```{code-block}c
:linenos:
free(puntero);
puntero = NULL;  // Ahora es seguro verificar con if (puntero != NULL)
```

:::{important} Patrón Idiomático
Poner punteros en `NULL` después de `free` tiene dos ventajas:
1. `free(NULL)` es una operación segura (no hace nada)
2. Podés verificar si el puntero es válido antes de usarlo
:::

:::{tip} Concepto Avanzado: Liberación Defensiva con Doble Puntero
Para evitar repetir manualmente la asignación a `NULL` tras cada llamada a `free`, se puede encapsular la liberación en una función auxiliar que reciba la dirección de la variable puntero (un doble puntero). Esto permite modificar el puntero original de la función invocadora.

```{code-block}c
:linenos:
void datos_liberar(int **ptr) {
    if (ptr == NULL) {
        return;  // Evita desreferenciar si se pasa un puntero inválido
    }
    
    free(*ptr);   // free(NULL) es seguro por estándar y no hace nada
    *ptr = NULL;  // Modifica el puntero original del llamador
}

// Uso:
int *datos = malloc(sizeof(int) * 10);
datos_liberar(&datos);  // Pasa la dirección de la variable puntero
// Ahora datos == NULL
```
:::

(liberar-memoria-no-dinamica)=
#### Liberar Memoria No Dinámica

Intentar liberar memoria que **no fue asignada dinámicamente** es un error grave que resulta en **undefined behavior**.

##### Regla Fundamental

:::{danger} Regla de Oro de `free`
Solo podés liberar memoria que fue obtenida de `malloc`, `calloc` o `realloc`. Nada más.
:::

##### Errores Comunes

**1. Liberar variables del stack:**

```{code-block}c
:linenos:
int main() {
    char automatica[] = "hola mundo";  // En el stack
    free(automatica);  // ERROR: undefined behavior
}
```

Como se explica en {ref}`la-pila-stack`, las variables automáticas se gestionan automáticamente en el stack. No necesitan (ni deben) ser liberadas manualmente.

**2. Liberar literales de cadena:**

```{code-block}c
:linenos:
char *mensaje = "Hola";  // Literal en .rodata (read-only data)
free(mensaje);  // ERROR: undefined behavior
```

Los literales de cadena residen en el segmento `.rodata` (ver {ref}`segmentacion-de-la-memoria`) y son de solo lectura.

**3. Liberar variables globales:**

```{code-block}c
:linenos:
int global_arr[100];  // Segmento .bss o .data

void funcion() {
    free(global_arr);  // ERROR: undefined behavior
}
```

(ejercicios-de-autoevaluacion-problemas-de-memoria)=
#### Ejercicios de Autoevaluación (Problemas de Memoria)







---


(funciones-adicionales-de-gestion-de-memoria)=
### Funciones Adicionales de Gestión de Memoria


Más allá de `malloc` y `free`, C proporciona funciones adicionales para manipular memoria dinámica. Estas se detallan completamente en {ref}`capitulo-memoria-dinamica`.

(calloc-asignacion-con-inicializacion)=
#### `calloc`: Asignación con Inicialización

```{code-block}c
:linenos:
void *calloc(size_t cantidad, size_t tamaño);
```

Asigna memoria para un **arreglo** de `cantidad` elementos, cada uno de `tamaño` bytes. Crucialmente, **inicializa toda la memoria a cero**.

**Comparación con `malloc`:**

```{code-block}c
:linenos:
// Usando malloc
int *arr1 = malloc(10 * sizeof(int));
// arr1[i] contiene basura

// Usando calloc
int *arr2 = calloc(10, sizeof(int));
// arr2[i] == 0 para todo i
:::

:::{tip} Cuándo Usar `calloc`
- Cuando necesitás memoria inicializada a cero
- Para arreglos dinámicos que requieren estado inicial limpio
- En estructuras donde campos en cero representan estado "vacío"
:::

(realloc-redimensionar-bloques)=
#### `realloc`: Redimensionar Bloques

```{code-block}c
:linenos:
void *realloc(void *bloque, size_t nuevo_tamaño);
```

Cambia el tamaño de un bloque de memoria existente. Esta función es fundamental para implementar arrays redimensionables.

##### Comportamiento de `realloc`

:::{list-table} Casos de `realloc`
:header-rows: 1
:name: tbl-realloc

* - Condición
  - Comportamiento
  - Notas
* - `bloque == NULL`
  - Equivalente a `malloc(nuevo_tamaño)`
  - Útil para simplificar código
* - `nuevo_tamaño == 0`
  - Equivalente a `free(bloque)`
  - Devuelve `NULL`
* - `nuevo_tamaño > tamaño_original`
  - Expande el bloque
  - Memoria adicional **no inicializada**
* - `nuevo_tamaño < tamaño_original`
  - Reduce el bloque
  - Datos más allá de `nuevo_tamaño` se pierden

:::

##### Uso Correcto de `realloc`

:::{danger} Patrón Incorrecto Común
```{code-block}c
:linenos:
// INCORRECTO: Pierde el puntero si realloc falla
arr = realloc(arr, nuevo_tamaño * sizeof(int));
```

Si `realloc` falla, retorna `NULL` pero el bloque original **no se libera**. Asignar `NULL` a `arr` directamente causa un memory leak.
:::

**Patrón correcto:**

```{code-block}c
:linenos:
int *temp = realloc(arr, nuevo_tamaño * sizeof(int));
if (temp == NULL) {
    // realloc falló, arr sigue válido
    // Manejar error (liberar arr si es necesario)
    return ERROR;
}
arr = temp;  // Éxito: actualizar puntero
```

##### ¿Por Qué `realloc` Puede Mover el Bloque?

Si no hay espacio contiguo para expandir el bloque en su ubicación actual, `realloc`:

1. Asigna un nuevo bloque más grande en otra ubicación
2. Copia los datos del bloque original al nuevo
3. Libera el bloque original
4. Retorna la dirección del nuevo bloque

```{figure} 2/realloc_movimiento.svg
:label: fig-realloc-movimiento
:align: center
:width: 90%

Proceso de realloc cuando debe mover el bloque a una nueva ubicación.
```

:::{important} Invalidación de Punteros
Cuando `realloc` mueve un bloque, **todos los punteros** al bloque original quedan inválidos. Debés actualizar cualquier referencia.
:::

(memset-relleno-de-memoria)=
#### `memset`: Relleno de Memoria

```{code-block}c
:linenos:
void *memset(void *destino, int valor, size_t count);
```

Rellena los primeros `count` bytes de `destino` con `valor` (convertido a `unsigned char`).

**Usos comunes:**

```{code-block}c
:linenos:
// Inicializar array a cero
int arr[100];
memset(arr, 0, sizeof(arr));

// Limpiar buffer sensible
char password[64];
// ... usar password ...
memset(password, 0, sizeof(password));  // Borrar rastros
```

:::{warning} Limitación de `memset`
`memset` trabaja **byte a byte**. Para inicializar arrays de tipos más grandes a valores distintos de cero, usá un lazo o `calloc`.

```{code-block}c
:linenos:
int arr[10];
memset(arr, 1, sizeof(arr));  // NO inicializa a 1
// Cada byte es 1, entonces cada int es 0x01010101
```
:::

(memcpy-copia-de-memoria)=
#### `memcpy`: Copia de Memoria

```{code-block}c
:linenos:
void *memcpy(void *destino, const void *origen, size_t count);
```

Copia `count` bytes desde `origen` a `destino`. **Las regiones no deben solaparse**.

**Ejemplo:**

```{code-block}c
:linenos:
int src[5] = {1, 2, 3, 4, 5};
int dst[5];
memcpy(dst, src, sizeof(src));
// dst == {1, 2, 3, 4, 5}
```

:::{danger} Solapamiento
Si las regiones de memoria se solapan, el comportamiento es indefinido. Para copias con solapamiento, usá `memmove`.

```{code-block}c
:linenos:
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// Mover elementos 3 posiciones a la derecha
memmove(&arr[3], &arr[0], 7 * sizeof(int));  // Correcto
memcpy(&arr[3], &arr[0], 7 * sizeof(int));   // Indefinido
```
:::


(arreglos-de-largo-variable-vla)=
### Arreglos de Largo Variable (VLA)


Los **VLA** (_Variable Length Arrays_) son arreglos cuyo tamaño se determina en tiempo de ejecución, no en compilación.

```{code-block}c
:linenos:
void funcion(int cantidad) {
    int arreglo[cantidad];  // <-- VLA: tamaño determinado en runtime
}
```

:::{danger} VLAs Prohibidos en Esta Materia
Los VLAs están **explícitamente prohibidos** en este curso. Usá memoria dinámica (`malloc`) en su lugar.
:::

(por-que-prohibimos-vlas)=
#### ¿Por Qué Prohibimos VLAs?

##### 1. Asignación en el Stack

Los VLAs se crean en el **stack**, no en el heap (ver {ref}`comparacion-stack-vs-heap`). El stack tiene tamaño limitado (típicamente 1-8 MB).

```{code-block}c
:linenos:
void procesar(int n) {
    int datos[n];  // VLA en el stack
    
    // Si n es grande (por ejemplo, 1,000,000), esto causa stack overflow
}
```

##### 2. No Hay Mecanismo de Error

A diferencia de `malloc`, que retorna `NULL` si falla, un VLA cuya dimensión excede la capacidad del stack en tiempo de ejecución simplemente **provoca un desbordamiento del stack (stack overflow) y crashea el programa** de manera irrecuperable:

```{code-block}c
:linenos:
int *heap_arr = malloc(n * sizeof(int));
if (heap_arr == NULL) {
    // Podemos manejar el error
    fprintf(stderr, "Memoria insuficiente\n");
    return ERROR;
}

// vs

void procesar_con_vla(int n) {
    int stack_arr[n];  // VLA: Si n es muy grande, el programa abortará sin que podamos interceptar el fallo.
}
```

##### 3. Problemas de Portabilidad

El límite del stack varía entre plataformas y configuraciones. Código que funciona en una máquina puede crashear en otra.

(alternativa-correcta-memoria-dinamica)=
#### Alternativa Correcta: Memoria Dinámica

```{code-block}c
:linenos:
void funcion(int cantidad) {
    int *arreglo = malloc(cantidad * sizeof(int));
    if (arreglo == NULL) {
        // Manejar error
        return;
    }
    
    // Usar arreglo...
    
    free(arreglo);
}
```

:::{tip} Ventajas de `malloc` sobre VLA
- **Tamaño ilimitado** (solo limitado por RAM disponible)
- **Detección de errores** (retorna `NULL` si falla)
- Control explícito del ciclo de vida
- Portabilidad garantizada
:::

(ejercicios-de-autoevaluacion-funciones-de-gestion-y-vlas)=
#### Ejercicios de Autoevaluación (Funciones de Gestión y VLAs)







---


(doble-indireccion-puntero-a-puntero)=
### Doble Indirección (Puntero a Puntero)


Una variable puntero es un tipo de dato que almacena una dirección de memoria. Sin embargo, al ser una variable en sí misma, también reside en una dirección de memoria física específica del sistema. La **doble indirección** consiste en utilizar un puntero que almacena la dirección de otra variable puntero, declarándose mediante el operador de doble asterisco (`**`).

```{code-block}c
:linenos:
int valor = 42;
int *p = &valor;    // Puntero simple (indirección simple)
int **pp = &p;      // Doble puntero (doble indirección)
```

En este esquema:
- `valor` almacena el entero `42`.
- `p` almacena la dirección de memoria de `valor`.
- `pp` almacena la dirección de memoria de la variable `p`.

Desreferenciar `pp` una vez (`*pp`) evalúa al puntero `p` (obteniendo la dirección de `valor`). Desreferenciar `pp` dos veces (`**pp`) accede directamente al contenido de `valor` (`42`).

```{figure} 2/doble_indireccion.svg
:label: fig-doble-indireccion
:align: center
:width: 85%

Representación en stack y heap de la doble indirección con `pp`, `p` y `valor`.
```

(paso-de-punteros-por-referencia)=
#### Paso de Punteros por Referencia

En el lenguaje C, todos los argumentos de una función se transmiten **estrictamente por valor** (copia). Esto significa que la función trabaja con copias locales de los parámetros recibidos. 

Si necesitás que una función modifique un tipo de dato básico (como un `int`), debés pasar un puntero a esa variable (`int *`) para simular un paso por referencia. De forma análoga, si una función necesita **modificar una variable puntero** (por ejemplo, para asignarle memoria dinámica o reubicarla), se debe pasar la dirección del puntero, lo que requiere un **doble puntero** (`int **`).

##### El Error Común: Pasar un Puntero Simple

Considerá la siguiente función que intenta asignar memoria para un entero:

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

// Intento incorrecto de asignar memoria
void inicializar_incorrecto(int *ptr) {
    ptr = malloc(sizeof(int));  // Modifica la copia local
    if (ptr != NULL) {
        *ptr = 10;
    }
}

int main(void) {
    int *mi_puntero = NULL;
    inicializar_incorrecto(mi_puntero);
    
    // ERROR: mi_puntero sigue siendo NULL en main
    // Además, se generó un memory leak de la memoria asignada en la función.
    return 0;
}
```

Al invocar `inicializar_incorrecto(mi_puntero)`, el valor de `mi_puntero` (que es `NULL`) se copia en el parámetro local `ptr`. Cuando la función ejecuta `malloc`, almacena la dirección de la memoria reservada en la variable local `ptr`. Al retornar la función, `ptr` se destruye en el stack y `mi_puntero` en `main` permanece inalterado, provocando una fuga de memoria física.

##### La Solución: Doble Indirección

Para modificar el puntero original de la función invocadora, se debe enviar su dirección de memoria (`&mi_puntero`). La función receptora utilizará un parámetro de doble indirección para acceder y modificar el puntero original mediante desreferencia:

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

// Forma correcta utilizando doble indirección
void inicializar_correcto(int **ptr) {
    if (ptr == NULL || *ptr != NULL) {
        return; // Cláusula de guarda para evitar desreferenciar un puntero nulo o reasignar memoria
    }
    
    *ptr = malloc(sizeof(int)); // Desreferencia para modificar el puntero original
    if (*ptr != NULL) {
        **ptr = 42; // Modifica el valor entero apuntado
    }
}

int main(void) {
    int *mi_puntero = NULL;
    
    // Pasamos la dirección del puntero
    inicializar_correcto(&mi_puntero);
    
    if (mi_puntero != NULL) {
        printf("Valor asignado: %d\n", *mi_puntero);
        free(mi_puntero);
        mi_puntero = NULL;
    }
    
    return 0;
}
```

:::{important} Análisis de la Desreferencia en la Doble Indirección

Es fundamental comprender la diferencia entre operar sobre el doble puntero o sobre su desreferencia dentro de la función `inicializar_correcto(int **ptr)`:
- `ptr`: Es la dirección del puntero del llamador (tipo `int **`).
- `*ptr`: Es el puntero del llamador en sí (tipo `int *`). Al asignarle memoria (`*ptr = malloc(...)`), se modifica directamente la variable en la función invocadora.
- `**ptr`: Es el entero en el heap al que apunta el puntero modificado (tipo `int`).
:::

(patron-practico-creacion-y-destruccion-modular)=
#### Patrón Práctico: Creación y Destrucción Modular

Este enfoque es el estándar en C para construir interfaces limpias de Tipos Abstractos de Datos (TAD), garantizando que las funciones que modifican la estructura interna o el estado de los punteros del cliente lo hagan de forma segura y controlada.

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nombre;
    int id;
} recurso_t;

typedef enum {
    RECURSO_EXITO = 0,
    RECURSO_ERR_PARAMETROS,
    RECURSO_ERR_MEMORIA,
    RECURSO_ERR_PRECONDICION
} recurso_status_t;

// Constructor que inicializa el puntero del llamador
recurso_status_t recurso_crear(recurso_t **recurso_out, const char *nombre, int id) {
    if (recurso_out == NULL || nombre == NULL) {
        return RECURSO_ERR_PARAMETROS;
    }
    if (*recurso_out != NULL) {
        return RECURSO_ERR_PRECONDICION; // Evita fugas de memoria si ya tiene memoria asignada
    }
    
    recurso_t *nuevo = malloc(sizeof(recurso_t));
    if (nuevo == NULL) {
        return RECURSO_ERR_MEMORIA;
    }
    
    nuevo->nombre = malloc(strlen(nombre) + 1);
    if (nuevo->nombre == NULL) {
        free(nuevo);
        return RECURSO_ERR_MEMORIA;
    }
    
    strcpy(nuevo->nombre, nombre);
    nuevo->id = id;
    
    *recurso_out = nuevo; // Retornamos el recurso creado por referencia
    return RECURSO_EXITO;
}

// Destructor defensivo que libera memoria y pone el puntero en NULL
void recurso_destruir(recurso_t **recurso_out) {
    if (recurso_out == NULL || *recurso_out == NULL) {
        return;
    }
    
    free((*recurso_out)->nombre);
    free(*recurso_out);
    *recurso_out = NULL; // Evita punteros colgantes en el llamador
}
```

:::{tip} Estilo
Declarar los asteriscos junto al identificador de la variable (por ejemplo, `recurso_t **recurso_out`) y verificar siempre los retornos de asignación de memoria dinámica para cumplir con la regla {ref}`0x0006h` y las directivas de robustez del apunte.
:::


(matrices-dinamicas)=
### Matrices Dinámicas


Una **matriz** (arreglo bidimensional) puede implementarse de varias formas en memoria dinámica. Cada enfoque tiene trade-offs en complejidad, eficiencia de memoria y acceso.

Como se explica en {ref}`el-monton-heap`, la memoria dinámica nos permite crear estructuras de tamaño arbitrario. Las matrices dinámicas extienden este concepto a dos dimensiones.

(enfoque-1-matriz-dentada-array-de-punteros)=
#### Enfoque 1: Matriz "Dentada" (Array de Punteros)

Este enfoque crea un **arreglo de punteros**, donde cada puntero apunta a una fila (otro arreglo). Se llama "dentada" (_jagged array_) porque cada fila puede tener largo diferente (aunque típicamente usamos filas del mismo tamaño).

```{figure} 2/matriz_dentada.svg
:label: fig-matriz-dentada
:align: center
:width: 85%

Representación de una matriz dentada: array de punteros a arrays.
```

##### Asignación

```{code-block}c
:linenos:
int **matriz;
int filas = 3, columnas = 4;

// Paso 1: Array de punteros a filas
matriz = malloc(filas * sizeof(int *));
if (matriz == NULL) {
    return NULL;
}

// Paso 2: Cada fila
for (int i = 0; i < filas; i++) {
    matriz[i] = malloc(columnas * sizeof(int));
    if (matriz[i] == NULL) {
        // Error: liberar lo ya asignado
        for (int j = 0; j < i; j++) {
            free(matriz[j]);
        }
        free(matriz);
        return NULL;
    }
}
```

##### Acceso

El acceso es natural con la sintaxis estándar de C:

```{code-block}c
:linenos:
matriz[i][j] = 42;
int valor = matriz[i][j];
```

:::{note} Cómo Funciona el Acceso
`matriz[i][j]` se evalúa como:
1. `matriz[i]` → puntero a la fila `i`
2. `(matriz[i])[j]` → elemento `j` de esa fila
:::

##### Liberación

Siguiendo el principio "de adentro hacia afuera" ({ref}`destruccion-de-estructuras-dinamicas`):

```{code-block}c
:linenos:
// 1. Liberar cada fila
for (int i = 0; i < filas; i++) {
    free(matriz[i]);
}

// 2. Liberar el array de punteros
free(matriz);
```

##### Ventajas y Desventajas

**Ventajas:**
- Sintaxis natural `matriz[i][j]`
- Filas pueden tener tamaños diferentes
- Fácil de entender conceptualmente

**Desventajas:**
- **Fragmentación:** Cada fila es un bloque separado en el heap
- **Overhead de memoria:** Punteros adicionales para cada fila
- **Cache-unfriendly:** Filas no están contiguas en memoria (ver {ref}`jerarquia-de-memoria-y-cache`)

(enfoque-2-bloque-unico-simulacion-manual)=
#### Enfoque 2: Bloque Único (Simulación Manual)

Este enfoque asigna toda la matriz como **un único bloque contiguo** en memoria. Es más eficiente pero requiere calcular índices manualmente.

```{figure} 2/matriz_bloque.svg
:label: fig-matriz-bloque
:align: center
:width: 85%

Matriz almacenada como bloque contiguo: todas las filas consecutivas en memoria.
```

##### Asignación

```{code-block}c
:linenos:
int *matriz;
int filas = 3, columnas = 4;

matriz = malloc(filas * columnas * sizeof(int));
if (matriz == NULL) {
    return NULL;
}
```

##### Acceso Manual

No podés usar `matriz[i][j]` directamente porque `matriz` es `int *`, no `int **`. Debés calcular el índice lineal:

```{code-block}c
:linenos:
// Acceso: fila i, columna j
int valor = matriz[i * columnas + j];

// Asignación
matriz[i * columnas + j] = 42;
```

**Explicación del cálculo:**
- Cada fila tiene `columnas` elementos
- Para llegar a la fila `i`, saltamos `i * columnas` elementos
- Luego avanzamos `j` columnas dentro de esa fila

```{figure} 2/matriz_mapeo.svg
:label: fig-matriz-mapeo
:align: center
:width: 90%

Mapeo entre la representación lógica 2D y la memoria lineal contigua.
```

##### Liberación

Solo una llamada a `free`:

```{code-block}c
:linenos:
free(matriz);
```

##### Función de Acceso Helper

Para mejorar la legibilidad, podés crear una función:

```{code-block}c
:linenos:
static inline int matriz_get(int *matriz, int fila, int col, int num_cols) {
    return matriz[fila * num_cols + col];
}

static inline void matriz_set(int *matriz, int fila, int col, int num_cols, int valor) {
    matriz[fila * num_cols + col] = valor;
}

// Uso:
matriz_set(matriz, i, j, columnas, 42);
int val = matriz_get(matriz, i, j, columnas);
```

##### Ventajas y Desventajas

**Ventajas:**
- **Memoria contigua:** Excelente localidad de cache (ver {ref}`jerarquia-de-memoria-y-cache`)
- **Solo una asignación:** Más eficiente, menos fragmentación
- **Menos overhead:** No hay punteros intermedios

**Desventajas:**
- Sintaxis de acceso menos intuitiva
- Todas las filas deben tener el mismo tamaño
- Fácil cometer errores en el cálculo de índices

(enfoque-3-bloque-unico-con-cast-avanzado)=
#### Enfoque 3: Bloque Único con Cast Avanzado

Este enfoque combina lo mejor de ambos mundos: **memoria contigua** del Enfoque 2 con la **sintaxis natural** del Enfoque 1, mediante un cast especial del puntero constante. Es fundamental aclarar que, para evitar la definición de tipos modificados dinámicamente en tiempo de ejecución (que constituyen una forma de VLA prohibida), las dimensiones de las columnas deben ser constantes conocidas en tiempo de compilación.

##### Asignación con Puntero a Array

```{code-block}c
:linenos:
#define COLUMNAS 4

int filas = 3;

// Puntero a un array de 'COLUMNAS' enteros (tamaño constante)
int (*matriz)[COLUMNAS] = malloc(
    sizeof(int) * COLUMNAS * filas
);

if (matriz == NULL) {
    return NULL;
}
```

:::{note} Sintaxis Compleja
`int (*matriz)[columnas]` se lee:
- `(*matriz)`: "puntero llamado matriz"
- `[columnas]`: "a un array de `columnas` elementos"
- `int`: "de tipo `int`"

Es decir, `matriz` es un puntero a un array de `columnas` enteros.
:::

##### Acceso Natural

Ahora podés usar la sintaxis estándar:

```{code-block}c
:linenos:
matriz[i][j] = 42;
int valor = matriz[i][j];
```

##### Aritmética de Punteros en el Direccionamiento Bidimensional

Para comprender cómo el compilador desreferencia la sintaxis `matriz[i][j]` en el Enfoque 3, debemos analizarla desde la aritmética de punteros. 

Si declaramos `int (*matriz)[COLUMNAS]`, el tipo de `matriz` es "puntero a un array de `COLUMNAS` enteros". Por lo tanto, el tamaño del elemento al que apunta es $\text{sizeof}(int) \times \text{COLUMNAS}$ bytes.

El acceso `matriz[i][j]` es equivalente a `*(*(matriz + i) + j)`. El compilador realiza el cálculo de la dirección física de la siguiente manera:

1. **Desplazamiento de Fila (`matriz + i`):**
   Al sumar `i` al puntero `matriz`, el compilador avanza `i` elementos del tipo apuntado. La dirección resultante es:
   $$\text{Dir}(matriz[i]) = \text{Dir}(matriz) + i \times \text{COLUMNAS} \times \text{sizeof}(int)$$

2. **Desplazamiento de Columna (`*(matriz + i) + j`):**
   La expresión `*(matriz + i)` evalúa al array de la fila `i`. Por la regla de decaimiento (*array decay*), este decae a un puntero al primer entero de dicha fila (tipo `int *`). Al sumar `j`, avanzamos `j` enteros:
   $$\text{Dir}(matriz[i][j]) = \text{Dir}(matriz[i]) + j \times \text{sizeof}(int)$$

3. **Dirección Final Combinada:**
   Sustituyendo la primera ecuación en la segunda, la dirección de memoria exacta del elemento es:
   $$\text{Dir}(matriz[i][j]) = \text{Dir}(matriz) + (i \times \text{COLUMNAS} + j) \times \text{sizeof}(int)$$

Este cálculo de desplazamiento en bytes coincide exactamente con la simulación manual del Enfoque 2, con la ventaja de que el compilador realiza la multiplicación y escala los índices de forma transparente y eficiente.

##### Liberación

Solo un `free`:

```{code-block}c
:linenos:
free(matriz);
```

##### Comparación de Declaraciones

```{code-block}c
:linenos:
// Enfoque 1: Array de punteros
int **matriz1;           // Puntero a puntero a int

// Enfoque 2: Puntero simple
int *matriz2;            // Puntero a int

// Enfoque 3: Puntero a array
int (*matriz3)[COLUMNAS];  // Puntero a array de COLUMNAS ints
```

##### El Enfoque 3 y la Prohibición de VLAs

:::{important} Prohibición Absoluta de VLAs
Cuando se declara `int (*matriz)[columnas]` con `columnas` como una variable evaluada en tiempo de ejecución, se define un **puntero a un tipo modificado de forma variable** (puntero a VLA). Aunque esta asignación se realice en el heap, la sintaxis involucra un tipo VLA en runtime.

En esta cátedra, **los VLAs están estrictamente prohibidos en todas sus formas**, incluyendo punteros a arrays de tamaño variable en tiempo de ejecución. Por lo tanto, el Enfoque 3 solo es admisible si las dimensiones son constantes conocidas en tiempo de compilación (como `#define COLUMNAS 4`).
:::

Para C89 y para cumplir las directivas de la materia se utiliza:

```{code-block}c
:linenos:
#define COLUMNAS 4
int (*matriz)[COLUMNAS] = malloc(sizeof(int) * COLUMNAS * filas);
```

##### Ventajas y Desventajas

**Ventajas:**
- Sintaxis natural `matriz[i][j]`
- Memoria contigua (buena localidad de cache)
- Solo una asignación/liberación

**Desventajas:**
- Sintaxis de declaración compleja
- En C89, requiere tamaño de columnas constante
- Menos portable que los otros enfoques

(comparacion-de-enfoques)=
#### Comparación de Enfoques

```{list-table} Comparación de Implementaciones de Matrices
:header-rows: 1
:name: tbl-comparacion-matrices

* - Aspecto
  - Enfoque 1 (Dentada)
  - Enfoque 2 (Bloque Manual)
  - Enfoque 3 (Bloque + Cast)
* - Sintaxis de acceso
  - `matriz[i][j]` ✅
  - `matriz[i*cols + j]` ⚠️
  - `matriz[i][j]` ✅
* - Asignaciones `malloc`
  - `filas + 1` ⚠️
  - `1` ✅
  - `1` ✅
* - Overhead de memoria
  - `filas * sizeof(int*)` ⚠️
  - `0` ✅
  - `0` ✅
* - Localidad de cache
  - Baja ⚠️
  - Alta ✅
  - Alta ✅
* - Fragmentación
  - Alta ⚠️
  - Ninguna ✅
  - Ninguna ✅
* - Filas de tamaño variable
  - Sí ✅
  - No ⚠️
  - No ⚠️
* - Complejidad código
  - Media
  - Media
  - Alta ⚠️
```

:::{tip} Recomendación
- Para matrices pequeñas o con filas de tamaño variable: **Enfoque 1**
- Para matrices grandes con acceso frecuente: **Enfoque 2** (mejor performance)
- Si necesitás sintaxis natural + performance: **Enfoque 3** (si la complejidad no es problema)
:::

---

(ejercicios-de-autoevaluacion-doble-indireccion-y-matrices)=
#### Ejercicios de Autoevaluación (Doble Indirección y Matrices)







---


(2_aritmetica-conexion-con-el-siguiente-tema)=
### Conexión con el Siguiente Tema


Dominando la gestión avanzada de memoria dinámica, tenés las herramientas para implementar estructuras de datos complejas: listas enlazadas, árboles, grafos, hash tables. Pero construir estas estructuras correctamente requiere algo más que conocimiento técnico de punteros.

El apunte {ref}`TAD, Pilas y Colas <capitulo-tad>` introduce el concepto de **Tipos Abstractos de Datos** (TADs):

- **Encapsulación:** Ocultar detalles de implementación
- **Interfaces limpias:** Separar "qué hace" de "cómo lo hace"
- **Invariantes:** Propiedades que siempre deben cumplirse
- **Patrones de diseño:** crear/destruir, getters/setters, iteradores

Un TAD bien diseñado permite cambiar completamente la implementación interna (por ejemplo, de matriz dentada a bloque único) sin afectar al código cliente. Esta separación de concerns es fundamental para escribir software mantenible y escalable.

Los punteros y la memoria dinámica son las herramientas de bajo nivel; los TADs son los principios arquitecturales que guían su uso profesional.

**Pregunta puente**: Una lista enlazada y un array dinámico implementan la misma interfaz abstracta (secuencia de elementos). ¿Cómo decidir cuál usar? ¿Cómo diseñar la interfaz para que sea independiente de la implementación? El análisis de TADs responde estas preguntas.

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-ptr-struct-crear-copia
Implementá una función constructora `recurso_crear` que reserve memoria en el heap para una estructura `recurso_t` que contenga un miembro entero `id` y un puntero a caracteres `nombre`. La función debe asignar memoria para copiar dinámicamente la cadena de entrada `nombre` y controlar de forma exhaustiva las fallas de asignación de memoria sin producir fugas (memory leaks).
:::

:::{solution} ej-ptr-struct-crear-copia
:class: dropdown
```c
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nombre;
    int id;
} recurso_t;

recurso_t *recurso_crear(const char *nombre, int id) {
    if (nombre == NULL) return NULL;

    // Paso 1: Asignar estructura contenedora
    recurso_t *nuevo = malloc(sizeof(recurso_t));
    if (nuevo == NULL) return NULL;

    // Paso 2: Asignar miembro interno (+1 para '\0')
    nuevo->nombre = malloc(strlen(nombre) + 1);
    if (nuevo->nombre == NULL) {
        free(nuevo); // Liberar contenedor previo para evitar leak
        return NULL;
    }

    // Paso 3: Copiar datos
    strcpy(nuevo->nombre, nombre);
    nuevo->id = id;

    return nuevo;
}
```
:::

:::{exercise}
:label: ej-ptr-struct-flecha-equivalencia
Explicá de manera teórica la equivalencia semántica entre el operador punto `.` combinado con desreferencia y el operador flecha `->` en C, y justificá por qué la cátedra promueve el uso de este último en el apunte.
:::

:::{solution} ej-ptr-struct-flecha-equivalencia
:class: dropdown
La expresión `p->miembro` es un atajo sintáctico exacto de `(*p).miembro`.
En C, el operador de acceso a miembro punto `.` posee mayor precedencia que el operador de desreferencia asterisco `*`. Por lo tanto, escribir `*p.miembro` se interpretaría como desreferenciar el campo `p.miembro` (lo cual es un error si `p` es el puntero). Para desreferenciar primero el puntero y luego acceder al miembro, se requiere forzar la prioridad con paréntesis: `(*p).miembro`.
El operador `->` elimina la necesidad de escribir paréntesis redundantes, haciendo que el código sea más limpio, legible e intuitivo para el programador.
:::

:::{exercise}
:label: ej-ptr-struct-destruir-lifo
Implementá una función destructora `estudiante_destruir` para la estructura:
```c
typedef struct {
    char *nombre;
    char *apellido;
} estudiante_t;
```
Asegurá que la liberación de memoria se realice de forma LIFO ("de adentro hacia afuera") para evitar dejar campos huérfanos e inaccesibles en el heap.
:::

:::{solution} ej-ptr-struct-destruir-lifo
:class: dropdown
```c
#include <stdlib.h>

void estudiante_destruir(estudiante_t *est) {
    if (est == NULL) {
        return; // Cláusula de guarda
    }

    // 1. Liberar los miembros dinámicos internos primero
    free(est->nombre);
    free(est->apellido);

    // 2. Liberar la estructura contenedora al final
    free(est);
}
```
:::

:::{exercise}
:label: ej-ptr-heap-dangling
Escribí un código en C que asigne un bloque de enteros en el heap, lo libere utilizando `free`, y muestre cómo desactivar de forma segura la variable puntero para evitar que se convierta en un **puntero colgante** (*dangling pointer*).
:::

:::{solution} ej-ptr-heap-dangling
:class: dropdown
```c
#include <stdlib.h>

int main() {
    int *datos = malloc(5 * sizeof(int));
    if (datos == NULL) return 1;

    // ... uso de la memoria ...

    free(datos);    // Se libera el bloque, pero 'datos' sigue guardando la dirección
    datos = NULL;   // Se mitiga el dangling pointer asignando NULL

    // Ahora es seguro realizar comprobaciones como:
    // if (datos != NULL) { ... }
    return 0;
}
```
:::

:::{exercise}
:label: ej-ptr-heap-double-free
Explicá por qué intentar realizar `free(var)` sobre una variable asignada estáticamente en el stack (como `int var = 100;` o `char buffer[10];`) genera un fallo catastrófico en tiempo de ejecución.
:::

:::{solution} ej-ptr-heap-double-free
:class: dropdown
La función `free()` está diseñada exclusivamente para devolver bloques de memoria previamente asignados en el **heap** mediante las rutinas del gestor de memoria (`malloc`, `calloc`, `realloc`).
El stack se gestiona de forma automática mediante registros del procesador (puntero de pila). Si pasamos una dirección del stack a `free()`, el gestor de memoria del heap intentará leer metadatos de control inexistentes antes de esa dirección de memoria, corrompiendo las estructuras de datos de la biblioteca estándar y provocando un comportamiento indefinido inmediato (usualmente un crash del programa con el mensaje `free(): invalid pointer`).
:::

:::{exercise}
:label: ej-ptr-heap-defensive-free
Implementá una función utilitaria en C llamada `free_seguro` que tome un doble puntero a entero (`int **ptr`), libere la memoria asociada y de forma automática establezca el puntero del invocador a `NULL` para implementar un patrón de liberación defensivo.
:::

:::{solution} ej-ptr-heap-defensive-free
:class: dropdown
```c
#include <stdlib.h>

void free_seguro(int **ptr) {
    if (ptr == NULL || *ptr == NULL) {
        return; // Evita doble liberación o desreferencia nula
    }

    free(*ptr);   // Libera el bloque de memoria
    *ptr = NULL;  // Pone el puntero original del invocador en NULL
}

// Ejemplo de uso:
// int *p = malloc(sizeof(int));
// free_seguro(&p);
// En este punto p es NULL de forma automática.
```
:::

:::{exercise}
:label: ej-ptr-calloc-vs-malloc
Explicá la diferencia entre usar `malloc` y `calloc` para reservar memoria para un arreglo de 100 enteros, y justificá en qué casos es preferible utilizar esta última.
:::

:::{solution} ej-ptr-calloc-vs-malloc
:class: dropdown
- **`malloc(100 * sizeof(int))`**: Reserva el bloque de memoria de 400 bytes, pero **no altera su contenido**. La memoria retiene cualquier dato residual (basura) que estuviese previamente en esas celdas físicas.
- **`calloc(100, sizeof(int))`**: Reserva la misma cantidad de memoria y realiza un paso adicional inicializando **todos los bytes en cero**.
Es preferible usar `calloc` cuando los valores iniciales de la estructura o arreglo deben estar limpios por diseño (por ejemplo, contadores en cero, punteros en `NULL` o strings vacíos), evitando errores lógicos por lectura de variables no inicializadas.
:::

:::{exercise}
:label: ej-ptr-realloc-safe-temp
Escribí un fragmento de código en C que redimensione un arreglo de enteros `arr` de capacidad $N$ a una nueva capacidad $2N$ de forma segura. Asegurate de no perder la dirección del bloque original en caso de que la asignación de memoria dinámica falle.
:::

:::{solution} ej-ptr-realloc-safe-temp
:class: dropdown
```c
#include <stdlib.h>
#include <stdio.h>

int redimensionar_arreglo(int **arr, size_t *capacidad) {
    size_t nueva_capacidad = (*capacidad) * 2;

    // Se asigna el retorno en un puntero temporal
    int *temp = realloc(*arr, nueva_capacidad * sizeof(int));
    if (temp == NULL) {
        // En caso de fallo, *arr sigue apuntando al bloque original válido
        fprintf(stderr, "Error: Memoria insuficiente para redimensionar.\n");
        return -1;
    }

    *arr = temp; // Éxito: se actualiza el puntero del invocador
    *capacidad = nueva_capacidad;
    return 0;
}
```
:::

:::{exercise}
:label: ej-ptr-vla-stack-overflow
Explicá por qué declarar arreglos de tamaño variable en el stack (`int arr[n];` con `n` dinámico) es una práctica peligrosa que la cátedra prohíbe, y de qué forma puede resultar en un crasheo irrecuperable del programa.
:::

:::{solution} ej-ptr-vla-stack-overflow
:class: dropdown
Los Arreglos de Longitud Variable (VLA) en el stack reservan espacio dinámicamente en la pila en tiempo de ejecución.
Debido a que el stack de un proceso es limitado (frecuentemente 1 MB o 8 MB según el sistema operativo), si el valor de `n` ingresado por el usuario o calculado es excesivamente grande, la pila se desbordará (*Stack Overflow*). A diferencia de `malloc` (que retorna `NULL` ante la falta de memoria, permitiendo al programa recuperarse y manejar el error), el desbordamiento del stack provocado por un VLA causa una interrupción de hardware inmediata e irrecuperable, abortando el sistema operativo el proceso del programa al instante.
:::

:::{exercise}
:label: ej-ptr-doble-referencia
Implementá una función llamada `inicializar_puntero` que reciba un doble puntero a entero `int **out_ptr` y le asigne memoria dinámica para un entero con el valor `100`. Retorná un código de error de tipo enumeración `status_t`.
:::

:::{solution} ej-ptr-doble-referencia
:class: dropdown
```c
#include <stdlib.h>

typedef enum {
    STATUS_OK = 0,
    STATUS_ERR_PARAM,
    STATUS_ERR_MEMORIA
} status_t;

status_t inicializar_puntero(int **out_ptr) {
    if (out_ptr == NULL) {
        return STATUS_ERR_PARAM;
    }

    // Se asigna memoria desreferenciando una vez
    *out_ptr = malloc(sizeof(int));
    if (*out_ptr == NULL) {
        return STATUS_ERR_MEMORIA;
    }

    // Doble desreferencia para escribir el valor entero en el heap
    **out_ptr = 100;
    return STATUS_OK;
}
```
:::

:::{exercise}
:label: ej-ptr-matriz-dentada-aloc
Escribí los algoritmos completos en C para asignar y liberar de forma correcta una matriz dinámica de tipo `double` usando el **Enfoque 1 (Matriz Dentada)** de dimensiones $F \times C$.
:::

:::{solution} ej-ptr-matriz-dentada-aloc
:class: dropdown
```c
#include <stdlib.h>

// Asignación de la matriz dentada
double **matriz_crear(size_t filas, size_t columnas) {
    double **mat = malloc(filas * sizeof(double *));
    if (mat == NULL) return NULL;

    for (size_t i = 0; i < filas; i++) {
        mat[i] = malloc(columnas * sizeof(double));
        if (mat[i] == NULL) {
            // Liberar lo asignado previamente en caso de fallo (LIFO)
            for (size_t j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }
    return mat;
}

// Liberación de la matriz dentada
void matriz_liberar(double **mat, size_t filas) {
    if (mat == NULL) return;

    for (size_t i = 0; i < filas; i++) {
        free(mat[i]); // Liberar cada fila primero
    }
    free(mat); // Liberar el array de punteros contenedor
}
```
:::

:::{exercise}
:label: ej-ptr-matriz-bloque-index
Dada una matriz dinámica implementada como un bloque contiguo único de memoria (Enfoque 2) de dimensiones `filas` y `columnas`, implementá una función `obtener_celda` que reciba el puntero lineal de la matriz, las dimensiones, y los índices de consulta `f` y `c`, y retorne el valor correspondiente aplicando la aritmética de indexación lineal.
:::

:::{solution} ej-ptr-matriz-bloque-index
:class: dropdown
```c
#include <stdio.h>

int obtener_celda(const int *matriz, int columnas, int f, int c) {
    // Cálculo del índice plano correspondiente a la celda bidimensional
    // Se desplazan f filas completas de ancho 'columnas', y se avanza c elementos
    int indice_lineal = f * columnas + c;
    return matriz[indice_lineal];
}

// Ejemplo de uso:
// int *matriz = malloc(3 * 4 * sizeof(int));
// int valor = obtener_celda(matriz, 4, 2, 1); // Accede a matriz[2][1]
```
:::

## Glosario

- **Aritmética de Punteros**: Operaciones matemáticas realizadas sobre direcciones de memoria.
- **Puntero a Puntero**: Puntero que almacena la dirección de otro puntero.
- **Matriz Dinámica**: Arreglo bidimensional asignado en tiempo de ejecución en el heap.
- **VLA (Arreglo de Largo Variable)**: Arreglo cuyo tamaño se determina en tiempo de ejecución en el stack (no recomendado).

## Síntesis y Resumen

(2_aritmetica-conceptos-clave)=
### Conceptos Clave


Este apunte explora patrones avanzados de memoria dinámica en C, construyendo sobre los fundamentos de {ref}`Modelo de Memoria <capitulo-modelo-memoria>` y {ref}`Punteros <capitulo-punteros>`.

:::{important} Ideas Centrales

**Estructuras con Punteros**
- Requieren asignaciones **multinivel**: estructura + miembros internos
- Liberación en orden inverso: "de adentro hacia afuera"
- Operador `->` para acceso a miembros via punteros
- Cada nivel de anidamiento agrega complejidad de gestión

**Problemas Comunes**
- **Fragmentación del heap:** bloques libres no contiguos reducen eficiencia
- **Punteros colgantes:** apuntan a memoria liberada (undefined behavior)
- **Free de memoria no dinámica:** solo liberar lo asignado con `malloc/calloc/realloc`
- **Orden incorrecto de liberación:** causa memory leaks

**Funciones Avanzadas**
- `calloc`: asignación con inicialización a cero
- `realloc`: redimensionamiento que puede mover el bloque
- `memset`: relleno byte a byte
- `memcpy`: copia rápida (sin solapamiento)

**Matrices Dinámicas**
- **Dentada:** array de punteros, flexible pero fragmentada
- **Bloque único:** contigua, cache-friendly, índice manual
- **Cast avanzado:** contigua con sintaxis natural

**Decisiones de Diseño**
- Trade-off: sintaxis vs performance vs flexibilidad
- Memoria contigua favorece localidad de cache
- Menos asignaciones reducen fragmentación y overhead
:::

## Referencias y Lecturas de Aritmética de Punteros

(referencias-lecturas-aritmetica)=
### Referencias y Lecturas de Aritmética de Punteros


(textos-fundamentales-sobre-memoria-dinamica)=
#### Textos Fundamentales sobre Memoria Dinámica

- {cite:t}`kernighan_c_2014`. Capítulo 8: The UNIX System Interface. Gestión de memoria y estructuras complejas.

- {cite:t}`king_c_2008`. Capítulo 17: Advanced Uses of Pointers. Matrices multidimensionales y estructuras auto-referenciadas.

- {cite:t}`gustedt_modern_2019`. Level 2, Takeaway 2.6.5: Dynamic allocation. Patrones modernos de gestión de memoria.

(gestion-de-memoria-y-debugging)=
#### Gestión de Memoria y Debugging

- {cite:t}`seacord_secure_2013`. Capítulo 4: Dynamic Memory Management. Errores comunes y cómo evitarlos.

- **Valgrind Memcheck Manual** - https://valgrind.org/docs/manual/mc-manual.html
  - Herramienta esencial para detectar leaks y dangling pointers.

(matrices-y-estructuras-multidimensionales)=
#### Matrices y Estructuras Multidimensionales

- {cite:t}`van_der_linden_expert_1994`. Capítulo 4: The Shocking Truth: C Arrays and Pointers Are NOT the Same!

- **Multi-dimensional Arrays in C** - https://www.cs.cmu.edu/~ab/15-123S11/lectures/Lecture%2009%20-%20%20Multidimensional%20Arrays.pdf

(optimizacion-y-performance)=
#### Optimización y Performance

- {cite:t}`bryant_computer_2015`. Capítulo 6: Memory Hierarchy. Localidad de cache y performance de acceso.

- {cite:t}`warren_hackers_2012`. Capítulo 9: Memory. Técnicas de optimización de memoria.

(patrones-de-diseno-con-memoria-dinamica)=
#### Patrones de Diseño con Memoria Dinámica

- {cite:t}`hanson_c_1996`. Interfaces y implementaciones con gestión de memoria robusta.

- {cite:t}`plauger1992`. Implementaciones de la biblioteca estándar que usan memoria dinámica.

(herramientas-de-analisis)=
#### Herramientas de Análisis

- **AddressSanitizer** - https://github.com/google/sanitizers/wiki/AddressSanitizer
  - Detector de errores de memoria integrado en GCC/Clang.

- **Dr. Memory** - https://drmemory.org/
  - Alternativa a Valgrind para Windows.
