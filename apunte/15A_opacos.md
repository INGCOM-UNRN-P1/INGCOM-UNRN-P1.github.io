---
title: Punteros Opacos y Encapsulamiento en C
short_title: 15A - Punteros Opacos
subtitle: Técnicas de ocultamiento de información y diseño modular
---

## Introducción

Los **punteros opacos** (opaque pointers) son una técnica fundamental en C para implementar **encapsulamiento** y **ocultamiento de información** (information hiding). Esta técnica permite ocultar la implementación interna de una estructura de datos, exponiendo solo una interfaz pública al usuario, similar a como funcionan las clases privadas en lenguajes orientados a objetos.

El concepto de puntero opaco es esencial para construir **APIs robustas** y **bibliotecas mantenibles**, donde los detalles de implementación pueden cambiar sin romper el código cliente que las utiliza.

:::{important} Conexión con TADs
Los punteros opacos son la técnica central para implementar Tipos de Datos Abstractos (TADs) en C. Todo lo aprendido sobre TADs en {ref}`apunte/13_tad.md` se basa en esta técnica de encapsulamiento.
:::

---

## Motivación: El Problema del Acceso Directo

Considerá una implementación ingenua de una pila donde la estructura está completamente expuesta:

```c
// pila_mala.h - NO USAR: Implementación expuesta
typedef struct {
    int *datos;
    size_t tope;
    size_t capacidad;
} pila_t;

// Funciones públicas
pila_t *crear_pila(size_t capacidad);
bool apilar(pila_t *pila, int dato);
```

### Problemas de Esta Aproximación

**1. Violación del encapsulamiento:**
```c
pila_t *p = crear_pila(10);
// El usuario puede acceder directamente a los campos internos
p->tope = 100;  // ¡Rompe los invariantes!
p->datos[20] = 5;  // ¡Buffer overflow!
```

**2. Imposibilidad de cambiar la implementación:**
Si querés cambiar de arreglo a lista enlazada, **todo el código cliente se rompe** porque depende de los campos específicos de la estructura.

**3. Falta de control sobre invariantes:**
No hay forma de garantizar que `tope < capacidad` o que `datos` apunte a memoria válida, porque el usuario puede modificar cualquier campo.

:::{danger} Anti-patrón
Exponer la definición completa de una estructura en el archivo de cabecera es un **anti-patrón** que destruye la abstracción y crea dependencias frágiles.
:::

---

## La Solución: Punteros Opacos

La técnica de punteros opacos consiste en **declarar la estructura en el archivo de cabecera pero definirla en el archivo de implementación**.

### Estructura del Patrón

#### Archivo de Cabecera (`.h`) - Interfaz Pública

```c
// pila.h - Interfaz pública
#ifndef PILA_H
#define PILA_H

#include <stdbool.h>
#include <stddef.h>

// Declaración OPACA: el usuario solo ve que existe una estructura
typedef struct pila pila_t;

// Funciones públicas - la interfaz del TAD
pila_t *crear_pila(size_t capacidad);
void destruir_pila(pila_t *pila);

bool apilar(pila_t *pila, int dato);
bool desapilar(pila_t *pila, int *dato);
bool ver_tope(const pila_t *pila, int *dato);
bool esta_vacia(const pila_t *pila);
size_t obtener_tamanio(const pila_t *pila);

#endif  // PILA_H
```

#### Archivo de Implementación (`.c`) - Detalles Privados

```c
// pila.c - Implementación privada
#include "pila.h"
#include <stdlib.h>

// Definición COMPLETA de la estructura - solo visible aquí
struct pila {
    int *datos;
    size_t tope;
    size_t capacidad;
};

// Implementación de las funciones
pila_t *crear_pila(size_t capacidad) {
    if (capacidad == 0) {
        return NULL;
    }
    
    pila_t *pila = malloc(sizeof(pila_t));
    if (pila == NULL) {
        return NULL;
    }
    
    pila->datos = malloc(sizeof(int) * capacidad);
    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }
    
    pila->tope = 0;
    pila->capacidad = capacidad;
    return pila;
}

void destruir_pila(pila_t *pila) {
    if (pila == NULL) {
        return;
    }
    free(pila->datos);
    free(pila);
}

bool apilar(pila_t *pila, int dato) {
    if (pila == NULL || pila->tope >= pila->capacidad) {
        return false;
    }
    
    pila->datos[pila->tope] = dato;
    pila->tope++;
    return true;
}

bool desapilar(pila_t *pila, int *dato) {
    if (pila == NULL || pila->tope == 0 || dato == NULL) {
        return false;
    }
    
    pila->tope--;
    *dato = pila->datos[pila->tope];
    return true;
}

bool ver_tope(const pila_t *pila, int *dato) {
    if (pila == NULL || pila->tope == 0 || dato == NULL) {
        return false;
    }
    
    *dato = pila->datos[pila->tope - 1];
    return true;
}

bool esta_vacia(const pila_t *pila) {
    return pila == NULL || pila->tope == 0;
}

size_t obtener_tamanio(const pila_t *pila) {
    if (pila == NULL) {
        return 0;
    }
    return pila->tope;
}
```

#### Código Cliente

```c
// main.c - Usuario del TAD
#include <stdio.h>
#include "pila.h"

int main(void) {
    pila_t *p = crear_pila(100);
    if (p == NULL) {
        fprintf(stderr, "Error al crear la pila\n");
        return 1;
    }
    
    // El usuario SOLO puede usar la interfaz pública
    apilar(p, 10);
    apilar(p, 20);
    apilar(p, 30);
    
    // Esto NO COMPILA: el usuario no puede acceder a los campos internos
    // p->tope = 5;  // ERROR: incomplete type 'struct pila'
    // p->datos[0] = 100;  // ERROR: incomplete type 'struct pila'
    
    int dato;
    while (!esta_vacia(p)) {
        if (desapilar(p, &dato)) {
            printf("Desapilado: %d\n", dato);
        }
    }
    
    destruir_pila(p);
    return 0;
}
```

---

## Análisis Técnico: ¿Cómo Funciona?

### Tipo Incompleto (Incomplete Type)

Cuando declarás:
```c
typedef struct pila pila_t;
```

Sin dar la definición completa, creás un **tipo incompleto** (*incomplete type*). El compilador sabe que existe una estructura llamada `pila`, pero no conoce su contenido ni tamaño.

### Restricciones del Tipo Incompleto

Con un tipo incompleto, el código cliente **solo puede**:

1. **Declarar punteros** al tipo:
   ```c
   pila_t *p;  // ✅ Permitido
   ```

2. **Pasar punteros** a funciones:
   ```c
   apilar(p, 10);  // ✅ Permitido
   ```

3. **Usar punteros** en expresiones que no requieran el tamaño:
   ```c
   if (p == NULL) { ... }  // ✅ Permitido
   ```

### Operaciones Prohibidas

El código cliente **NO puede**:

1. **Declarar instancias** por valor:
   ```c
   pila_t p;  // ❌ ERROR: incomplete type
   ```

2. **Acceder a miembros**:
   ```c
   p->tope = 5;  // ❌ ERROR: incomplete type
   ```

3. **Usar sizeof**:
   ```c
   sizeof(pila_t);  // ❌ ERROR: incomplete type
   ```

4. **Desreferenciar**:
   ```c
   pila_t copia = *p;  // ❌ ERROR: incomplete type
   ```

:::{note} Tamaño del Puntero
Aunque el tipo es incompleto, el **puntero** tiene tamaño conocido (típicamente 8 bytes en sistemas de 64 bits), porque todos los punteros tienen el mismo tamaño independientemente del tipo al que apuntan.
:::

---

## Ventajas de los Punteros Opacos

### 1. Encapsulamiento Fuerte

La implementación está **completamente oculta**. El código cliente no puede (ni accidentalmente) acceder o modificar los campos internos.

```c
// Esto NO compila - el compilador protege los detalles internos
pila_t *p = crear_pila(10);
p->tope = 100;  // ERROR en tiempo de compilación
```

### 2. Flexibilidad de Implementación

Podés cambiar completamente la implementación interna sin afectar al código cliente:

```c
// pila.c - Versión con lista enlazada (cambio de implementación)
struct pila {
    nodo_t *tope;
    size_t cantidad;
};
```

El código cliente que usa `pila.h` **no necesita recompilarse** porque la interfaz no cambió.

### 3. Mantenimiento de Invariantes

Solo las funciones del módulo pueden modificar la estructura, garantizando que los invariantes se cumplan siempre:

```c
bool apilar(pila_t *pila, int dato) {
    // Garantiza que tope < capacidad SIEMPRE
    if (pila == NULL || pila->tope >= pila->capacidad) {
        return false;
    }
    // ... resto de la implementación
}
```

### 4. Compatibilidad Binaria (ABI)

Si la interfaz pública no cambia, podés actualizar la biblioteca compilada (`.so` o `.dll`) sin recompilar las aplicaciones que la usan. Esto es crucial para bibliotecas del sistema.

### 5. Reducción de Dependencias

Los archivos que incluyen `pila.h` no necesitan incluir las dependencias internas de `pila.c`, reduciendo tiempos de compilación y acoplamiento.

---

## Patrones de Uso Comunes

### Patrón Constructor/Destructor

Toda estructura opaca debe tener funciones para crear y destruir instancias:

```c
// Convención de nombres: tipo_accion
tipo_t *crear_tipo(parametros);
void destruir_tipo(tipo_t *instancia);
```

**Ejemplo:**
```c
lista_t *lista = crear_lista();
// ... usar la lista ...
destruir_lista(lista);
```

### Patrón Getter/Setter

Para acceder a propiedades sin exponer los campos:

```c
// Getter - solo lectura
size_t pila_obtener_tamanio(const pila_t *pila);
bool pila_esta_vacia(const pila_t *pila);

// Setter - modificación controlada (si es necesario)
bool pila_establecer_capacidad(pila_t *pila, size_t nueva_capacidad);
```

:::{tip} Uso de `const`
Usá `const pila_t *pila` en funciones que solo leen, no modifican. Esto documenta la intención y permite al compilador optimizar.
:::

### Patrón de Verificación

Siempre verificá punteros nulos y condiciones de error:

```c
bool desapilar(pila_t *pila, int *dato) {
    // Verificaciones defensivas
    if (pila == NULL || dato == NULL) {
        return false;
    }
    if (esta_vacia(pila)) {
        return false;
    }
    
    // Operación segura
    pila->tope--;
    *dato = pila->datos[pila->tope];
    return true;
}
```

---

## Comparación con Otras Técnicas

### vs. Estructuras Expuestas

```{list-table}
:header-rows: 1

* - Aspecto
  - Puntero Opaco
  - Estructura Expuesta
* - Encapsulamiento
  - ✅ Fuerte
  - ❌ Ninguno
* - Cambios de implementación
  - ✅ No rompen código cliente
  - ❌ Rompen todo
* - Protección de invariantes
  - ✅ Garantizada
  - ❌ Imposible
* - Performance
  - ✅ Igual (solo punteros)
  - ✅ Igual
* - Debugging
  - ⚠️ Más difícil
  - ✅ Más fácil
* - Overhead
  - ✅ Ninguno
  - ✅ Ninguno
```

### vs. Void Pointers

```c
// Opción 1: Puntero opaco (RECOMENDADO)
typedef struct pila pila_t;
void apilar(pila_t *pila, int dato);

// Opción 2: Void pointer (EVITAR)
void apilar(void *pila, int dato);
```

**Problemas de void pointers:**
- Pérdida de type safety (podés pasar cualquier puntero)
- No hay verificación de tipos en tiempo de compilación
- Requiere casts explícitos
- Más propenso a errores

:::{danger} Anti-patrón: Void Pointers para Opacos
Aunque `void *` también oculta la implementación, **no es la forma idiomática** en C. Usá punteros opacos con tipos específicos para mantener type safety.
:::

---

## Ejemplo Completo: Lista Enlazada Opaca

### Interfaz Pública (`lista.h`)

```c
#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stddef.h>

// Tipo opaco
typedef struct lista lista_t;

// Tipo de función para iterar
typedef void (*lista_visitar_fn)(void *dato, void *extra);

// Constructor/Destructor
lista_t *crear_lista(void);
void destruir_lista(lista_t *lista);

// Operaciones básicas
bool insertar_al_inicio(lista_t *lista, void *dato);
bool insertar_al_final(lista_t *lista, void *dato);
bool eliminar_primero(lista_t *lista, void **dato);
void *ver_primero(const lista_t *lista);

// Consultas
bool esta_vacia(const lista_t *lista);
size_t obtener_largo(const lista_t *lista);

// Iteración
void iterar(lista_t *lista, lista_visitar_fn funcion, void *extra);

#endif  // LISTA_H
```

### Implementación (`lista.c`)

```c
#include "lista.h"
#include <stdlib.h>

// Nodo interno - completamente privado
typedef struct nodo {
    void *dato;
    struct nodo *siguiente;
} nodo_t;

// Definición completa de la lista - solo visible aquí
struct lista {
    nodo_t *primero;
    nodo_t *ultimo;
    size_t largo;
};

// Implementaciones
lista_t *crear_lista(void) {
    lista_t *lista = malloc(sizeof(lista_t));
    if (lista == NULL) {
        return NULL;
    }
    
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->largo = 0;
    return lista;
}

void destruir_lista(lista_t *lista) {
    if (lista == NULL) {
        return;
    }
    
    nodo_t *actual = lista->primero;
    while (actual != NULL) {
        nodo_t *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

bool insertar_al_inicio(lista_t *lista, void *dato) {
    if (lista == NULL) {
        return false;
    }
    
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    
    if (lista->ultimo == NULL) {
        lista->ultimo = nuevo;
    }
    
    lista->largo++;
    return true;
}

bool insertar_al_final(lista_t *lista, void *dato) {
    if (lista == NULL) {
        return false;
    }
    
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    if (nuevo == NULL) {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (lista->ultimo == NULL) {
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    } else {
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
    
    lista->largo++;
    return true;
}

bool eliminar_primero(lista_t *lista, void **dato) {
    if (lista == NULL || lista->primero == NULL || dato == NULL) {
        return false;
    }
    
    nodo_t *primero = lista->primero;
    *dato = primero->dato;
    
    lista->primero = primero->siguiente;
    if (lista->primero == NULL) {
        lista->ultimo = NULL;
    }
    
    free(primero);
    lista->largo--;
    return true;
}

void *ver_primero(const lista_t *lista) {
    if (lista == NULL || lista->primero == NULL) {
        return NULL;
    }
    return lista->primero->dato;
}

bool esta_vacia(const lista_t *lista) {
    return lista == NULL || lista->primero == NULL;
}

size_t obtener_largo(const lista_t *lista) {
    if (lista == NULL) {
        return 0;
    }
    return lista->largo;
}

void iterar(lista_t *lista, lista_visitar_fn funcion, void *extra) {
    if (lista == NULL || funcion == NULL) {
        return;
    }
    
    nodo_t *actual = lista->primero;
    while (actual != NULL) {
        funcion(actual->dato, extra);
        actual = actual->siguiente;
    }
}
```

### Uso del Cliente

```c
#include <stdio.h>
#include "lista.h"

void imprimir_entero(void *dato, void *extra) {
    int *num = (int *)dato;
    printf("%d ", *num);
}

int main(void) {
    lista_t *lista = crear_lista();
    
    int a = 10, b = 20, c = 30;
    insertar_al_final(lista, &a);
    insertar_al_final(lista, &b);
    insertar_al_final(lista, &c);
    
    printf("Lista: ");
    iterar(lista, imprimir_entero, NULL);
    printf("\n");
    
    printf("Largo: %zu\n", obtener_largo(lista));
    
    destruir_lista(lista);
    return 0;
}
```

---

## Punteros Opacos en Bibliotecas Estándar

Muchas bibliotecas conocidas usan punteros opacos:

### POSIX: FILE

```c
// stdio.h
typedef struct _IO_FILE FILE;

FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);
```

No sabés cómo está implementado `FILE` internamente, pero podés usarlo.

### OpenSSL

```c
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;

SSL_CTX *SSL_CTX_new(const SSL_METHOD *method);
SSL *SSL_new(SSL_CTX *ctx);
```

### GTK+ (GUI)

```c
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;

GtkWidget *gtk_window_new(GtkWindowType type);
```

Todos estos ejemplos siguen el mismo patrón de puntero opaco.

---

## Buenas Prácticas

### 1. Convenciones de Nombres

```c
// Patrón: tipo_t para el tipo, crear_tipo/destruir_tipo para funciones
typedef struct lista lista_t;

lista_t *crear_lista(void);
void destruir_lista(lista_t *lista);
bool lista_insertar(lista_t *lista, void *dato);
```

### 2. Documentación Clara

```c
/**
 * Crea una nueva lista vacía.
 * 
 * @return Puntero a la lista creada, o NULL si falla la asignación.
 */
lista_t *crear_lista(void);

/**
 * Destruye la lista liberando toda la memoria.
 * No libera los datos almacenados (responsabilidad del usuario).
 * 
 * @param lista Lista a destruir. Puede ser NULL.
 */
void destruir_lista(lista_t *lista);
```

### 3. Manejo de Errores Consistente

```c
// Retornar NULL en creación si falla
tipo_t *crear_tipo(void) {
    tipo_t *t = malloc(sizeof(tipo_t));
    if (t == NULL) {
        return NULL;  // Indicación clara de fallo
    }
    // ... inicialización ...
    return t;
}

// Retornar bool en operaciones
bool tipo_operar(tipo_t *t, int dato) {
    if (t == NULL) {
        return false;  // Fallo: puntero inválido
    }
    // ... operación ...
    return true;  // Éxito
}
```

### 4. Tolerancia a NULL

```c
void destruir_tipo(tipo_t *t) {
    // Tolerante a NULL - similar a free()
    if (t == NULL) {
        return;
    }
    // ... liberación ...
}

bool esta_vacia(const tipo_t *t) {
    // Considerar NULL como vacío
    return t == NULL || t->cantidad == 0;
}
```

### 5. Uso de `const` para Intenciones

```c
// Solo lectura - no modifica
size_t obtener_tamanio(const pila_t *pila);

// Modifica la estructura
bool apilar(pila_t *pila, int dato);

// Puntero constante (no se reasigna dentro de la función)
void procesar(pila_t *const pila);
```

---

## Limitaciones y Consideraciones

### 1. Pérdida de Acceso Directo

No podés acceder a los campos para debugging o inspección:

```c
// En GDB:
(gdb) print pila->tope
Cannot access memory at address 0x0: incomplete type
```

**Solución:** Proveer funciones de inspección para debugging:
```c
#ifdef DEBUG
void pila_debug_print(const pila_t *pila);
#endif
```

### 2. No se Puede Alocar en el Stack

```c
// Esto NO compila con puntero opaco
pila_t p;  // ERROR: incomplete type

// Debes usar el heap
pila_t *p = crear_pila(10);
```

**Implicación:** Siempre hay un costo de `malloc/free`.

### 3. Dificultad para Copiar

No podés hacer copia superficial:

```c
pila_t *copia = *original;  // ERROR: incomplete type
```

**Solución:** Proveer función de copia explícita:
```c
pila_t *clonar_pila(const pila_t *original);
```

### 4. Compatibilidad con Análisis Estático

Algunas herramientas de análisis estático tienen dificultades con tipos incompletos. Asegurate de que Valgrind y sanitizers funcionen correctamente.

---

## Ejercicios

```{exercise}
:label: ejercicio-opaco-1

Implementá un TAD `cola_t` (cola FIFO) usando punteros opacos con las siguientes operaciones:

- `crear_cola()`
- `destruir_cola()`
- `encolar(cola, dato)`
- `desencolar(cola, *dato)`
- `ver_frente(cola, *dato)`
- `esta_vacia(cola)`
- `obtener_tamanio(cola)`

Usá una lista enlazada como implementación interna.
```

```{exercise}
:label: ejercicio-opaco-2

Diseñá un TAD `diccionario_t` que mapee strings a enteros, con puntero opaco. Debe soportar:

- `crear_diccionario()`
- `destruir_diccionario()`
- `insertar(dic, clave, valor)` → retorna `true` si insertó, `false` si la clave ya existía
- `obtener(dic, clave, *valor)` → retorna `true` si encontró, `false` si no
- `eliminar(dic, clave)` → retorna `true` si eliminó, `false` si no existía
- `contiene(dic, clave)` → retorna `true` si la clave existe

Implementación sugerida: arreglo dinámico de estructuras `{char *clave; int valor}`.
```

```{exercise}
:label: ejercicio-opaco-3

Convertí la siguiente estructura expuesta a puntero opaco:

```c
// matriz.h - ANTES (expuesta)
typedef struct {
    int **datos;
    size_t filas;
    size_t columnas;
} matriz_t;

void crear_matriz(matriz_t *m, size_t filas, size_t cols);
int obtener(matriz_t *m, size_t i, size_t j);
```

Rediseñala con puntero opaco y funciones apropiadas.
```

---

## Referencias y Lecturas Complementarias

### Textos Fundamentales

- {cite:t}`hanson_c_1996`. *C Interfaces and Implementations*. Capítulo 1: Interfaces. Tratamiento exhaustivo de punteros opacos y diseño de interfaces.

- {cite:t}`kernighan_c_2014`. *The C Programming Language*. Capítulo 6: Structures. Sección sobre tipos incompletos.

- {cite:t}`king_c_2008`. *C Programming: A Modern Approach*. Capítulo 19: Program Design. Información hiding y modularidad.

### Documentación de Estándares

- **ISO C99 Standard** (6.2.5): Definición formal de tipos incompletos.
- **ISO C11 Standard** (6.7.2.3): Declaraciones de estructuras y tipos opacos.

### Artículos y Recursos

- **"Object-Oriented Programming With ANSI-C"** - Axel-Tobias Schreiner. Uso avanzado de punteros opacos para simular OOP.

- **POSIX API Design Guidelines** - Ejemplos de APIs del sistema que usan punteros opacos extensivamente.

---

## Resumen

Los punteros opacos son una técnica esencial para construir software modular y mantenible en C:

:::{important} Conceptos Clave

**¿Qué es un puntero opaco?**
- Declaración de estructura en `.h` sin definición completa
- Definición completa solo en `.c`
- El usuario solo manipula punteros, no la estructura directamente

**Ventajas:**
1. **Encapsulamiento fuerte:** Imposible acceder a campos internos
2. **Flexibilidad:** Cambiar implementación sin romper código cliente
3. **Invariantes garantizados:** Solo las funciones del módulo modifican la estructura
4. **Compatibilidad binaria:** Actualizar biblioteca sin recompilar aplicaciones

**Patrón típico:**
```c
// tipo.h
typedef struct tipo tipo_t;
tipo_t *crear_tipo(...);
void destruir_tipo(tipo_t *t);
bool tipo_operacion(tipo_t *t, ...);

// tipo.c
struct tipo {
    // Campos privados
};
```

**Conexiones:**
- Fundamental para implementar TADs (ver {ref}`apunte/13_tad.md`)
- Requiere memoria dinámica (ver {ref}`memoria-introduccion`)
- Usado extensivamente en bibliotecas del sistema y APIs públicas
:::

:::{tip} Cuándo Usar Punteros Opacos
**Usar cuando:**
- Diseñás una API pública o biblioteca
- Querés ocultar detalles de implementación
- Necesitás cambiar la implementación sin romper compatibilidad
- Implementás un TAD con invariantes estrictos

**No usar cuando:**
- Estructuras simples sin lógica (ej: `punto2d_t {int x, y;}`)
- Performance crítica requiere acceso directo en línea
- Código interno de un módulo (no expuesto externamente)
:::

Dominar los punteros opacos es esencial para escribir código C profesional, mantenible y robusto. Es la base del diseño modular en C y el equivalente más cercano al encapsulamiento de la programación orientada a objetos.
