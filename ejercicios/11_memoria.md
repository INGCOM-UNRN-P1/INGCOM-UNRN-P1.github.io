---
title: Ejercicios de Gestión de Memoria Dinámica
short_title: 11. Memoria Dinámica
---

## Acerca de

Estos ejercicios profundizan en la gestión de memoria dinámica, cubriendo temas avanzados como la relación stack-heap, el modelo de memoria de procesos, patrones de gestión de memoria, y la detección de errores comunes mediante herramientas de análisis.

## 1: Modelo de Memoria

### 1.1: Exploración del Layout de Memoria

Escribir un programa que imprima las direcciones de memoria de:
- Una variable local (stack)
- Un parámetro de función (stack)
- Una variable global (.data)
- Una variable estática (.bss)
- Una constante de cadena (.rodata)
- Memoria asignada con `malloc` (heap)

**Objetivo:** Visualizar las diferentes regiones de memoria y confirmar el layout típico: stack (altas direcciones) → heap (bajas direcciones) → data/bss → text.

### 1.2: Dirección de Crecimiento del Stack

Escribir una función recursiva que imprima la dirección de una variable local en cada llamada. Observar si el stack crece hacia direcciones más altas o más bajas.

```c
void explorar_stack(int nivel) {
    int variable_local;
    printf("Nivel %d: direccion = %p\n", nivel, (void*)&variable_local);
    if (nivel < 5) {
        explorar_stack(nivel + 1);
    }
}
```

### 1.3: Tamaño de Página del Sistema

Escribir un programa que use `sysconf(_SC_PAGESIZE)` (en sistemas POSIX) para obtener el tamaño de página del sistema. Luego, alojar varios bloques de memoria de diferentes tamaños y analizar cuánta memoria física se está usando realmente.

:::{note} Memoria Virtual
Recordá que el sistema operativo asigna memoria en múltiplos del tamaño de página, típicamente 4 KB. Una asignación de 100 bytes puede consumir 4 KB de memoria física.
:::

## 2: Patrones de Gestión de Memoria

### 2.1: Inicialización Consistente

Implementar una función `struct producto_t* crear_producto(const char* nombre, double precio)` que:
1. Verifique que los parámetros sean válidos (nombre no nulo, precio positivo)
2. Aloje memoria para el struct
3. Aloje memoria para la cadena `nombre` y la copie
4. Inicialice todos los campos
5. Retorne `NULL` si alguna asignación falla

Implementar también `void destruir_producto(struct producto_t** ptr_producto)` que libere toda la memoria y ponga el puntero en `NULL`.

:::{tip} Buena Práctica
Aquí aplica la regla de {ref}`regla-null-freed-pointers`: siempre poner punteros en `NULL` después de liberar para evitar dangling pointers.
:::

### 2.2: Manejo de Errores en Cadena

Escribir una función que aloje múltiples estructuras anidadas:

```c
struct persona_t {
    char* nombre;
    char* apellido;
    struct direccion_t* direccion;
};

struct direccion_t {
    char* calle;
    char* ciudad;
};
```

La función debe manejar correctamente fallos de `malloc` en cualquier paso, liberando todo lo previamente asignado antes de retornar `NULL`.

### 2.3: Pool de Memoria Simple

Implementar un pool de memoria básico que preasigne un bloque grande y distribuya bloques pequeños de tamaño fijo desde él.

```c
typedef struct {
    void* bloque_base;
    size_t tamano_total;
    size_t tamano_bloque;
    size_t bloques_usados;
    bool* mapa_uso;
} pool_t;

pool_t* pool_crear(size_t n_bloques, size_t tamano_bloque);
void* pool_alojar(pool_t* pool);
void pool_liberar(pool_t* pool, void* ptr);
void pool_destruir(pool_t* pool);
```

**Ventaja:** Reduce la fragmentación y overhead de múltiples `malloc`/`free`.

## 3: Errores Comunes y Detección

### 3.1: Double Free

Escribir un programa que deliberadamente cometa el error de double free:

```c
int main() {
    int* ptr = malloc(sizeof(int) * 10);
    *ptr = 42;
    
    free(ptr);
    free(ptr);  // ERROR: double free
    
    return 0;
}
```

Compilar con AddressSanitizer (`gcc -fsanitize=address`) y observar el error detectado.

### 3.2: Use After Free

Crear un programa que cometa use-after-free:

```c
int main() {
    int* arr = malloc(sizeof(int) * 5);
    arr[0] = 100;
    
    free(arr);
    
    printf("%d\n", arr[0]);  // ERROR: use after free
    
    return 0;
}
```

Ejecutar con Valgrind: `valgrind --leak-check=full ./programa`

### 3.3: Memory Leak Complejo

Crear un programa con un leak no trivial:

```c
struct nodo_t {
    int dato;
    struct nodo_t* siguiente;
};

void agregar_nodo(struct nodo_t** cabeza, int valor) {
    struct nodo_t* nuevo = malloc(sizeof(struct nodo_t));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

int main() {
    struct nodo_t* lista = NULL;
    
    for (int i = 0; i < 100; i++) {
        agregar_nodo(&lista, i);
    }
    
    // FALTA: liberar todos los nodos
    return 0;
}
```

Detectar con Valgrind el leak de 100 nodos. Luego implementar una función `liberar_lista` que corrija el problema.

### 3.4: Buffer Overflow en Heap

Demostrar un buffer overflow en memoria dinámica:

```c
int main() {
    char* buffer = malloc(10);
    strcpy(buffer, "Esta cadena es mucho más larga que 10 bytes");  // OVERFLOW
    
    printf("%s\n", buffer);
    free(buffer);
    
    return 0;
}
```

Compilar con `-fsanitize=address` y observar la detección del heap-buffer-overflow.

## 4: Estrategias de Realocación

### 4.1: Vector con Estrategia de Crecimiento

Implementar un vector dinámico con diferentes estrategias de crecimiento:
- **Lineal**: incrementar en un valor fijo (ej. +10)
- **Geométrico**: duplicar la capacidad (factor 2)
- **Fibonacci**: crecer según la secuencia de Fibonacci

Comparar el número de `realloc` realizados al insertar 10,000 elementos.

### 4.2: Shrinking Inteligente

Implementar un vector que no solo crece, sino que también reduce su capacidad cuando el tamaño cae por debajo de 1/4 de la capacidad. Esto evita el overhead de memoria manteniendo estabilidad.

```c
void vector_pop(vector_t* v) {
    if (v->size == 0) return;
    
    v->size--;
    
    // Si size < capacity/4 y capacity > MIN_CAPACITY, reducir a la mitad
    if (v->size > 0 && v->size < v->capacity / 4 && v->capacity > 16) {
        v->capacity /= 2;
        v->datos = realloc(v->datos, v->capacity * sizeof(int));
    }
}
```

### 4.3: Realloc Fallido

Escribir una función que maneje correctamente el fallo de `realloc`:

```c
bool vector_push(vector_t* v, int dato) {
    if (v->size == v->capacity) {
        size_t nueva_capacidad = v->capacity * 2;
        int* nuevo_bloque = realloc(v->datos, nueva_capacidad * sizeof(int));
        
        if (nuevo_bloque == NULL) {
            return false;  // Fallo, pero v->datos sigue válido
        }
        
        v->datos = nuevo_bloque;
        v->capacity = nueva_capacidad;
    }
    
    v->datos[v->size++] = dato;
    return true;
}
```

:::{important} Manejo de `realloc`
Nunca asignés directamente `ptr = realloc(ptr, size)`. Si falla, perdés el puntero original y tenés un leak. Usá un puntero temporal como en el ejemplo.
:::

## 5: Análisis de Rendimiento y Fragmentación

### 5.1: Fragmentación Externa

Escribir un programa que demuestre fragmentación externa:

```c
#define N 1000

int main() {
    void* ptrs[N];
    
    // Alojar muchos bloques pequeños
    for (int i = 0; i < N; i++) {
        ptrs[i] = malloc(64);
    }
    
    // Liberar bloques alternados
    for (int i = 0; i < N; i += 2) {
        free(ptrs[i]);
        ptrs[i] = NULL;
    }
    
    // Intentar alojar un bloque grande
    void* grande = malloc(64 * (N / 2));
    if (grande == NULL) {
        printf("No se pudo alojar bloque grande debido a fragmentación\n");
    } else {
        printf("Bloque grande asignado exitosamente\n");
        free(grande);
    }
    
    // Liberar bloques restantes
    for (int i = 1; i < N; i += 2) {
        free(ptrs[i]);
    }
    
    return 0;
}
```

### 5.2: Medición de Overhead de `malloc`

Escribir un programa que mida el overhead de `malloc` comparando el tamaño solicitado vs. el espacio realmente consumido (usando herramientas como `malloc_usable_size` en glibc):

```c
#include <malloc.h>

int main() {
    size_t tamaños[] = {1, 8, 16, 32, 64, 100, 128, 256, 512, 1024};
    
    for (size_t i = 0; i < sizeof(tamaños) / sizeof(tamaños[0]); i++) {
        void* ptr = malloc(tamaños[i]);
        size_t real = malloc_usable_size(ptr);
        
        printf("Solicitado: %5zu bytes -> Real: %5zu bytes (%.1f%% overhead)\n",
               tamaños[i], real, 100.0 * (real - tamaños[i]) / tamaños[i]);
        
        free(ptr);
    }
    
    return 0;
}
```

### 5.3: Cache Locality

Comparar el rendimiento de acceso secuencial vs. aleatorio en un arreglo grande:

```c
#define SIZE (100 * 1024 * 1024)  // 100M enteros

int main() {
    int* arr = malloc(SIZE * sizeof(int));
    
    // Secuencial
    clock_t inicio = clock();
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    clock_t fin = clock();
    printf("Secuencial: %.3f ms\n", 1000.0 * (fin - inicio) / CLOCKS_PER_SEC);
    
    // Aleatorio
    inicio = clock();
    for (size_t i = 0; i < SIZE; i++) {
        size_t idx = rand() % SIZE;
        arr[idx] = i;
    }
    fin = clock();
    printf("Aleatorio: %.3f ms\n", 1000.0 * (fin - inicio) / CLOCKS_PER_SEC);
    
    free(arr);
    return 0;
}
```

**Observación esperada:** El acceso secuencial será significativamente más rápido debido a mejor locality y uso del caché.

## 6: Alineación de Memoria

### 6.1: Visualizar Alineación

Escribir un programa que demuestre la alineación de memoria en structs:

```c
struct sin_padding {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
    double d;   // 8 bytes
};

struct con_padding {
    char a;     // 1 byte + 3 padding
    int b;      // 4 bytes
    char c;     // 1 byte + 7 padding
    double d;   // 8 bytes
};

int main() {
    printf("Tamaño sin optimizar: %zu bytes\n", sizeof(struct sin_padding));
    printf("Tamaño con padding: %zu bytes\n", sizeof(struct con_padding));
    
    // Imprimir offsets de cada campo
    struct con_padding s;
    printf("Offset de 'a': %zu\n", offsetof(struct con_padding, a));
    printf("Offset de 'b': %zu\n", offsetof(struct con_padding, b));
    printf("Offset de 'c': %zu\n", offsetof(struct con_padding, c));
    printf("Offset de 'd': %zu\n", offsetof(struct con_padding, d));
    
    return 0;
}
```

### 6.2: Alineación Manual

Implementar una función que aloje memoria alineada a un límite específico (ej. 64 bytes para optimización de caché):

```c
void* malloc_alineado(size_t size, size_t alineacion) {
    void* ptr = NULL;
    
    // posix_memalign requiere que alineacion sea potencia de 2
    if (posix_memalign(&ptr, alineacion, size) != 0) {
        return NULL;
    }
    
    return ptr;
}
```

## 7: Integración con Herramientas

### 7.1: Script de Análisis con Valgrind

Crear un Makefile que incluya targets para análisis automático:

```makefile
.PHONY: valgrind
valgrind: programa
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --verbose \
	         ./programa

.PHONY: asan
asan:
	$(CC) -fsanitize=address -g -o programa programa.c
	./programa
```

### 7.2: Supresor de Falsos Positivos

Crear un archivo de supresión para Valgrind que ignore leaks conocidos de bibliotecas del sistema:

```
{
   leak_ignorado_libc
   Memcheck:Leak
   ...
   obj:/lib/x86_64-linux-gnu/libc-*.so
}
```

Usar con: `valgrind --suppressions=mi_supresion.supp ./programa`

### 7.3: Wrapper de `malloc` para Debugging

Implementar wrappers de las funciones de memoria que agreguen logging:

```c
void* debug_malloc(size_t size, const char* archivo, int linea) {
    void* ptr = malloc(size);
    printf("[MALLOC] %zu bytes en %p (%s:%d)\n", size, ptr, archivo, linea);
    return ptr;
}

void debug_free(void* ptr, const char* archivo, int linea) {
    printf("[FREE] %p (%s:%d)\n", ptr, archivo, linea);
    free(ptr);
}

#define malloc(size) debug_malloc(size, __FILE__, __LINE__)
#define free(ptr) debug_free(ptr, __FILE__, __LINE__)
```

## 8: Casos Especiales

### 8.1: Memoria Compartida entre Funciones

Implementar un patrón donde una función asigna memoria y otra la libera, documentando claramente la responsabilidad:

```c
// El llamador es responsable de liberar la memoria retornada
char* construir_mensaje(const char* usuario) {
    size_t len = strlen("Hola, ") + strlen(usuario) + 2;
    char* msg = malloc(len);
    
    if (msg == NULL) {
        return NULL;
    }
    
    snprintf(msg, len, "Hola, %s", usuario);
    return msg;
}

int main() {
    char* mensaje = construir_mensaje("Alumno");
    if (mensaje != NULL) {
        printf("%s\n", mensaje);
        free(mensaje);  // ¡El main debe liberar!
    }
    return 0;
}
```

:::{note} Convención de Propiedad
Documentá claramente quién es responsable de liberar cada bloque de memoria. Usá comentarios como "Caller must free" o "Takes ownership".
:::

### 8.2: Retorno de Estructuras con Memoria Dinámica

Implementar una función que retorne un struct que contiene punteros a memoria dinámica:

```c
struct resultado_t {
    int* datos;
    size_t tamano;
};

struct resultado_t procesar_numeros(int* entrada, size_t n) {
    struct resultado_t res = {NULL, 0};
    
    res.datos = malloc(n * sizeof(int));
    if (res.datos == NULL) {
        return res;
    }
    
    for (size_t i = 0; i < n; i++) {
        res.datos[i] = entrada[i] * 2;
    }
    res.tamano = n;
    
    return res;
}
```

### 8.3: Gestión de Recursos con `goto`

Demostrar el uso apropiado de `goto` para cleanup en caso de errores:

```c
int procesar_archivo(const char* ruta) {
    FILE* archivo = NULL;
    char* buffer = NULL;
    int resultado = -1;
    
    archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        goto cleanup;
    }
    
    buffer = malloc(1024);
    if (buffer == NULL) {
        goto cleanup;
    }
    
    // ... procesamiento ...
    resultado = 0;  // éxito
    
cleanup:
    if (buffer != NULL) {
        free(buffer);
    }
    if (archivo != NULL) {
        fclose(archivo);
    }
    
    return resultado;
}
```

## 9: Ejercicios Integradores

### 9.1: Tabla Hash Dinámica

Implementar una tabla hash simple con resolución de colisiones por encadenamiento. La tabla debe:
- Usar un arreglo dinámico de listas enlazadas
- Crecer automáticamente cuando el factor de carga supere 0.75
- Liberar toda la memoria correctamente al destruirse

### 9.2: Árbol Binario con Memoria Dinámica

Implementar un árbol binario de búsqueda donde cada nodo se aloja dinámicamente. Incluir funciones para:
- Inserción
- Búsqueda
- Liberación recursiva (postorder traversal)

### 9.3: Parser de JSON Simplificado

Crear un parser básico de JSON que construya una estructura de datos en memoria dinámica representando el objeto JSON. Manejar cadenas, números, arreglos y objetos anidados.

### 9.4: Sistema de Gestión de Tareas

Implementar un sistema que mantenga una lista de tareas donde cada tarea tiene:
- ID único
- Descripción (cadena dinámica)
- Subtareas (arreglo dinámico de punteros a otras tareas)

El sistema debe permitir agregar, eliminar y buscar tareas, manejando toda la memoria correctamente.

## 10: Preguntas Conceptuales

### 10.1: Stack vs Heap

**Pregunta:** ¿Por qué no podemos simplemente usar el stack para todas las asignaciones de memoria? ¿Qué limitaciones tiene?

**Respuesta esperada:** El stack tiene tamaño limitado (típicamente 1-8 MB), crece automáticamente en cada llamada a función, y su memoria tiene scope limitado al bloque actual. El heap permite asignaciones grandes, persistencia más allá del scope, y tamaño determinado en runtime.

### 10.2: Fragmentación Interna vs Externa

**Pregunta:** Explicar la diferencia entre fragmentación interna y externa. Dar ejemplos de cada una.

**Fragmentación interna:** Espacio desperdiciado dentro de un bloque asignado (ej. `malloc(17)` puede asignar 32 bytes, desperdiciando 15).

**Fragmentación externa:** Espacio libre total suficiente pero dividido en bloques no contiguos (ej. después de liberar bloques alternados).

### 10.3: Costos Ocultos de `malloc`

**Pregunta:** ¿Por qué `malloc` tiene overhead? ¿Qué información necesita guardar el allocator?

**Respuesta esperada:** El allocator guarda metadatos como tamaño del bloque, estado (libre/ocupado), punteros a bloques vecinos para coalescing, información de alineación. Típicamente 8-16 bytes por bloque.

### 10.4: `free(NULL)`

**Pregunta:** ¿Qué hace `free(NULL)`? ¿Es seguro? ¿Por qué esta semántica es útil?

**Respuesta esperada:** `free(NULL)` no hace nada y es completamente seguro según el estándar C. Esto permite código más simple sin necesidad de verificar `if (ptr != NULL) free(ptr)`.

### 10.5: Tiempo de Vida de Memoria

**Pregunta:** Clasificar las siguientes asignaciones según su tiempo de vida:
- Variable local
- Variable `static` local
- Variable global
- Memoria de `malloc`

**Respuestas:**
- Variable local: hasta el final del bloque
- Variable `static` local: toda la ejecución del programa (inicializada una vez)
- Variable global: toda la ejecución del programa
- Memoria de `malloc`: hasta el `free` correspondiente

