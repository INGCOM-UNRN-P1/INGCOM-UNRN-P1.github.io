---
title: Ejercicios de Memoria Dinámica Avanzada
short_title: 12. Punteros II
---

## Acerca de

Estos ejercicios profundizan en patrones avanzados de memoria dinámica, incluyendo estructuras con punteros anidados, gestión de errores en múltiples niveles, matrices dinámicas con diferentes enfoques, y técnicas de optimización de memoria. Se construye sobre los fundamentos de gestión básica de memoria dinámica.

## 1: Estructuras con Punteros

### 1.1: Creación de Persona

Implementar un constructor para la estructura `persona_t`:

```c
typedef struct {
    char* nombre;
    char* apellido;
    int edad;
} persona_t;

persona_t* persona_crear(const char* nombre, const char* apellido, int edad);
```

**Requisitos:**
- Verificar que los parámetros no sean nulos
- Manejar fallos de `malloc` en cualquier etapa, liberando memoria ya asignada
- Retornar `NULL` si alguna asignación falla
- Inicializar todos los campos correctamente

### 1.2: Destrucción de Persona

Implementar el destructor correspondiente:

```c
void persona_destruir(persona_t** ptr_persona);
```

**Requisitos:**
- Liberar en el orden correcto (de adentro hacia afuera)
- Verificar que el puntero no sea `NULL`
- Poner el puntero en `NULL` después de liberar
- Manejar correctamente el doble puntero

:::{tip} Buena Práctica
Como se explica en {ref}`punteros2-destruccion`, siempre liberá los miembros internos antes de liberar la estructura contenedora.
:::

### 1.3: Clonación Profunda

Implementar una función que cree una copia completamente independiente de una persona:

```c
persona_t* persona_clonar(const persona_t* original);
```

La copia debe tener su propia memoria asignada para `nombre` y `apellido`, no compartir punteros con el original.

### 1.4: Estructura con Múltiples Niveles

Implementar constructor y destructor para esta estructura anidada:

```c
typedef struct {
    char* calle;
    char* ciudad;
    int codigo_postal;
} direccion_t;

typedef struct {
    char* nombre;
    direccion_t* direccion;
    char** telefonos;  // Array de cadenas
    size_t n_telefonos;
} contacto_t;

contacto_t* contacto_crear(const char* nombre, 
                           const char* calle, 
                           const char* ciudad,
                           int codigo_postal);
void contacto_destruir(contacto_t** ptr_contacto);
```

**Desafío:** Manejar correctamente tres niveles de asignación: la estructura principal, la dirección anidada, y el array dinámico de cadenas.

## 2: Manejo de Errores en Cadena

### 2.1: Rollback Completo

Escribir una función que asigne memoria para una estructura de estudiante con cursos:

```c
typedef struct {
    char* nombre;
    char** cursos;
    int* notas;
    size_t n_cursos;
} estudiante_t;
```

Si cualquier asignación falla, la función debe:
1. Liberar toda la memoria previamente asignada
2. Retornar `NULL`
3. No causar memory leaks

### 2.2: Macro de Verificación

Crear una macro que simplifique la verificación de `malloc`:

```c
#define VERIFICAR_MALLOC(ptr, cleanup_label) \
    do { \
        if ((ptr) == NULL) { \
            goto cleanup_label; \
        } \
    } while(0)
```

Usar esta macro en una función que asigne múltiples recursos y use `goto` para cleanup.

### 2.3: Función con Múltiples Salidas de Error

Implementar esta función que debe manejar varios puntos de fallo:

```c
int procesar_datos(const char* archivo_entrada, 
                   const char* archivo_salida,
                   char** resultado);
```

La función debe:
- Abrir ambos archivos (manejo de `FILE*`)
- Alojar buffers dinámicos
- Procesar datos
- Garantizar que todos los recursos se liberan/cierran en cualquier punto de fallo
- Retornar códigos de error apropiados

## 3: Problemas Comunes de Gestión de Memoria

### 3.1: Detectar Puntero Colgante

Este código tiene un bug. Identificarlo y corregirlo:

```c
char* obtener_saludo() {
    char saludo[50] = "Hola, mundo";
    return saludo;  // ¿Qué problema hay aquí?
}
```

**Pregunta:** ¿Por qué este código produce comportamiento indefinido?

### 3.2: Compartir vs. Copiar

Escribir dos versiones de una función que asigna un nombre a una persona:

```c
// Versión 1: comparte el puntero (shallow copy)
void persona_set_nombre_shallow(persona_t* p, char* nombre);

// Versión 2: copia la cadena (deep copy)
void persona_set_nombre_deep(persona_t* p, const char* nombre);
```

Explicar las diferencias, ventajas y desventajas de cada enfoque.

### 3.3: Memory Leak Sutil

Este código tiene un leak. Encontrarlo y corregirlo:

```c
void procesar_lista(char** lista, size_t n) {
    for (size_t i = 0; i < n; i++) {
        lista[i] = malloc(100);
        if (lista[i] == NULL) {
            return;  // ¿Qué pasa con las asignaciones anteriores?
        }
        strcpy(lista[i], "datos");
    }
}
```

### 3.4: Double Free

Identificar por qué este código puede causar double free:

```c
typedef struct {
    int* datos;
    size_t tamano;
} buffer_t;

void buffer_destruir(buffer_t* buf) {
    free(buf->datos);
    free(buf);
}

int main() {
    buffer_t* buf = malloc(sizeof(buffer_t));
    buf->datos = malloc(10 * sizeof(int));
    
    buffer_destruir(buf);
    free(buf);  // ¿Problema?
    
    return 0;
}
```

## 4: Operador Flecha y Precedencia

### 4.1: Equivalencias

Para cada expresión con `->`, escribir su equivalente usando `*` y `.`:

```c
typedef struct nodo {
    int valor;
    struct nodo* siguiente;
} nodo_t;

nodo_t* n = /* ... */;

// Expresión con ->      | Equivalente sin ->
n->valor                 // ?
n->siguiente->valor      // ?
(*n->siguiente).valor    // ?
```

### 4.2: Precedencia de Operadores

Predecir el resultado de estas expresiones (sin compilar):

```c
typedef struct {
    int* datos;
    size_t tamano;
} vector_t;

vector_t* v = /* vector con datos asignados */;

// ¿Qué hace cada expresión?
*v->datos           // ?
*(v->datos)         // ?
(*v).datos          // ?
v->datos[0]         // ?
*(v->datos + 1)     // ?
```

### 4.3: Punteros a Funciones en Structs

Implementar una estructura que contiene punteros a funciones:

```c
typedef struct {
    char* nombre;
    void (*procesar)(void* datos);
    void (*destruir)(void* datos);
} tarea_t;

tarea_t* tarea_crear(const char* nombre,
                     void (*procesar)(void*),
                     void (*destruir)(void*));
```

Luego usar esta estructura para crear tareas con diferentes comportamientos.

## 5: Matrices Dinámicas - Enfoque Dentado

### 5.1: Matriz Rectangular Dentada

Implementar las funciones de creación y destrucción para una matriz `filas x cols`:

```c
int** matriz_crear(size_t filas, size_t cols);
void matriz_destruir(int** matriz, size_t filas);
```

**Requisitos:**
- Verificar cada asignación
- Liberar en orden correcto si alguna falla
- En el destructor, iterar sobre todas las filas

### 5.2: Matriz Triangular Inferior

Crear una matriz triangular donde la fila `i` tiene `i+1` elementos:

```c
int** matriz_triangular_crear(size_t n);
```

**Ejemplo** para `n=4`:
```
fila 0: [x]
fila 1: [x][x]
fila 2: [x][x][x]
fila 3: [x][x][x][x]
```

### 5.3: Redimensionar Matriz Dentada

Implementar una función que agregue una fila a una matriz dentada existente:

```c
int** matriz_agregar_fila(int** matriz, size_t* filas, size_t cols);
```

Usar `realloc` para expandir el array de punteros. Manejar el caso donde `realloc` falla.

### 5.4: Matriz Irregular (Ragged Array)

Crear una matriz donde cada fila tiene un tamaño diferente especificado por un array:

```c
int** matriz_irregular_crear(size_t n_filas, const size_t* tamanos);
```

**Ejemplo:**
```c
size_t tamanos[] = {3, 5, 2, 8};
int** m = matriz_irregular_crear(4, tamanos);
// m[0] tiene 3 elementos
// m[1] tiene 5 elementos
// m[2] tiene 2 elementos
// m[3] tiene 8 elementos
```

## 6: Matrices Dinámicas - Bloque Único

### 6.1: Matriz como Bloque Contiguo

Implementar matriz usando un solo `malloc`:

```c
int* matriz_bloque_crear(size_t filas, size_t cols);
int matriz_bloque_get(const int* matriz, size_t filas, size_t cols, 
                      size_t i, size_t j);
void matriz_bloque_set(int* matriz, size_t filas, size_t cols,
                       size_t i, size_t j, int valor);
```

La función `get` debe calcular el índice como `i * cols + j` (row-major order).

### 6.2: Comparación de Performance

Escribir un programa que compare el tiempo de acceso de:
- Matriz dentada (`int**`)
- Matriz bloque único (`int*`)

Realizar 10 millones de accesos aleatorios y medir con `clock()`.

**Hipótesis:** La matriz en bloque único será más rápida debido a mejor cache locality.

### 6.3: Matriz 3D en Bloque Único

Implementar una matriz tridimensional usando un solo bloque de memoria:

```c
int* matriz3d_crear(size_t x, size_t y, size_t z);
int matriz3d_get(const int* m, size_t x, size_t y, size_t z,
                 size_t i, size_t j, size_t k);
```

El índice se calcula como: `i * (y * z) + j * z + k`

## 7: Matrices Dinámicas - Cast Avanzado

### 7.1: Matriz con Sintaxis Natural

Implementar el enfoque 3 del apunte usando un bloque contiguo pero con sintaxis `matriz[i][j]`:

```c
typedef struct {
    int** punteros;
    int* datos;
    size_t filas;
    size_t cols;
} matriz_t;

matriz_t* matriz_crear_cast(size_t filas, size_t cols);
void matriz_destruir_cast(matriz_t* matriz);
```

El truco es que `punteros[i]` apunta a `&datos[i * cols]`.

### 7.2: Generalización a Tipo Genérico

Extender el enfoque anterior para trabajar con cualquier tipo usando `void*`:

```c
typedef struct {
    void** punteros;
    void* datos;
    size_t filas;
    size_t cols;
    size_t tamano_elemento;
} matriz_generica_t;
```

Implementar funciones de creación, acceso y destrucción.

### 7.3: Macro para Acceso Tipado

Crear una macro que permita acceder a la matriz genérica con type-safety:

```c
#define MATRIZ_GET(mat, tipo, i, j) \
    (((tipo*)(mat)->datos)[(i) * (mat)->cols + (j)])
```

Ejemplo de uso:
```c
matriz_generica_t* m = /* ... */;
int valor = MATRIZ_GET(m, int, 2, 3);
```

## 8: Funciones Avanzadas de Memoria

### 8.1: Uso de `calloc` vs `malloc`

Escribir dos funciones que creen un array de enteros:

```c
int* array_crear_malloc(size_t n);  // Usando malloc
int* array_crear_calloc(size_t n);  // Usando calloc
```

Imprimir el contenido inmediatamente después de crear para ver la diferencia (malloc contiene basura, calloc contiene ceros).

### 8.2: Redimensionamiento con `realloc`

Implementar un array dinámico que crece automáticamente:

```c
typedef struct {
    int* datos;
    size_t tamano;
    size_t capacidad;
} array_dinamico_t;

bool array_push(array_dinamico_t* arr, int valor);
```

Cuando `tamano == capacidad`, duplicar la capacidad usando `realloc`.

:::{important} Manejo Correcto de `realloc`
Nunca hagas `ptr = realloc(ptr, size)`. Si falla, perdés el puntero original. Usá un temporal como se muestra en {ref}`punteros2-realloc-seguro`.
:::

### 8.3: Copiar con `memcpy` vs Lazo Manual

Comparar el rendimiento de copiar un array grande usando:
1. Lazo manual: `for (i = 0; i < n; i++) dest[i] = src[i];`
2. `memcpy(dest, src, n * sizeof(int));`

Medir con `clock()` y arrays de 100 millones de elementos.

### 8.4: Inicialización con `memset`

Implementar una función que cree una matriz y la inicialice con un valor específico:

```c
int* matriz_inicializada(size_t filas, size_t cols, int valor);
```

Usar `memset` para valores byte-uniformes (0, -1) y lazo manual para otros valores.

## 9: Fragmentación de Memoria

### 9.1: Demostración de Fragmentación Externa

Escribir un programa que:
1. Aloje 1000 bloques de 64 bytes
2. Libere los bloques en posiciones pares (0, 2, 4, ...)
3. Intente alojar un bloque de 32KB
4. Observe si falla debido a fragmentación (memoria suficiente pero no contigua)

### 9.2: Medición de Fragmentación Interna

Usar `malloc_usable_size()` (glibc) para medir cuánta memoria extra asigna malloc:

```c
void* ptr = malloc(33);
size_t usable = malloc_usable_size(ptr);
printf("Solicitado: 33, Obtenido: %zu, Desperdicio: %zu\n",
       usable, usable - 33);
```

Probar con diferentes tamaños y observar el patrón.

### 9.3: Memory Pool Simple

Implementar un allocator personalizado que preasigne un bloque grande y distribuya bloques fijos:

```c
typedef struct {
    char* memoria;
    size_t bloque_tamano;
    size_t num_bloques;
    bool* libre;  // bitmap
} pool_t;

pool_t* pool_crear(size_t num_bloques, size_t bloque_tamano);
void* pool_alloc(pool_t* pool);
void pool_free(pool_t* pool, void* ptr);
```

**Ventaja:** Elimina fragmentación para objetos de tamaño fijo.

## 10: Listas Enlazadas con Memoria Dinámica

### 10.1: Lista Simplemente Enlazada

Implementar las operaciones básicas:

```c
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo_t;

typedef struct {
    nodo_t* cabeza;
    size_t tamano;
} lista_t;

lista_t* lista_crear(void);
void lista_agregar_inicio(lista_t* lista, int dato);
void lista_agregar_final(lista_t* lista, int dato);
void lista_destruir(lista_t** ptr_lista);
```

### 10.2: Inserción Ordenada

Implementar inserción en una lista ordenada manteniendo el orden:

```c
void lista_insertar_ordenado(lista_t* lista, int dato);
```

### 10.3: Eliminación por Valor

Implementar función que elimine la primera ocurrencia de un valor:

```c
bool lista_eliminar(lista_t* lista, int dato);
```

**Desafío:** Manejar correctamente los casos:
- Eliminar la cabeza
- Eliminar un elemento intermedio
- Eliminar el último elemento
- Elemento no encontrado

### 10.4: Inversión In-Place

Invertir una lista enlazada sin usar memoria adicional (solo modificar los punteros):

```c
void lista_invertir(lista_t* lista);
```

**Algoritmo:** Usar tres punteros (anterior, actual, siguiente) y recorrer la lista invirtiendo los enlaces.

## 11: Árboles Binarios con Memoria Dinámica

### 11.1: Árbol Binario de Búsqueda

Implementar la estructura y operaciones básicas:

```c
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol* izquierdo;
    struct nodo_arbol* derecho;
} nodo_arbol_t;

nodo_arbol_t* arbol_insertar(nodo_arbol_t* raiz, int dato);
bool arbol_buscar(nodo_arbol_t* raiz, int dato);
void arbol_destruir(nodo_arbol_t** ptr_raiz);
```

### 11.2: Recorridos del Árbol

Implementar los tres recorridos clásicos:

```c
void arbol_inorden(nodo_arbol_t* raiz, void (*visitar)(int));
void arbol_preorden(nodo_arbol_t* raiz, void (*visitar)(int));
void arbol_postorden(nodo_arbol_t* raiz, void (*visitar)(int));
```

:::{note} Orden de Liberación
Para destruir un árbol, el recorrido postorden es el único correcto: liberar hijos antes que el padre.
:::

### 11.3: Altura del Árbol

Calcular la altura de un árbol recursivamente:

```c
int arbol_altura(nodo_arbol_t* raiz);
```

Un árbol vacío tiene altura -1, un nodo solo tiene altura 0.

### 11.4: Árbol Balanceado

Verificar si un árbol está balanceado (la diferencia de alturas entre subárboles no excede 1):

```c
bool arbol_es_balanceado(nodo_arbol_t* raiz);
```

## 12: Grafos y Estructuras Complejas

### 12.1: Grafo con Lista de Adyacencia

Implementar un grafo dirigido usando listas enlazadas:

```c
typedef struct arista {
    int destino;
    int peso;
    struct arista* siguiente;
} arista_t;

typedef struct {
    arista_t** listas;  // Array de listas de adyacencia
    size_t num_vertices;
} grafo_t;

grafo_t* grafo_crear(size_t num_vertices);
void grafo_agregar_arista(grafo_t* g, int origen, int destino, int peso);
void grafo_destruir(grafo_t** ptr_grafo);
```

### 12.2: Tabla Hash con Encadenamiento

Implementar una tabla hash simple:

```c
typedef struct entrada {
    char* clave;
    int valor;
    struct entrada* siguiente;
} entrada_t;

typedef struct {
    entrada_t** tabla;
    size_t capacidad;
    size_t tamano;
} hash_t;

hash_t* hash_crear(size_t capacidad);
void hash_insertar(hash_t* h, const char* clave, int valor);
bool hash_buscar(hash_t* h, const char* clave, int* valor);
void hash_destruir(hash_t** ptr_hash);
```

Usar una función hash simple: `hash = suma_ascii % capacidad`

### 12.3: Árbol N-ario

Implementar un árbol donde cada nodo puede tener un número arbitrario de hijos:

```c
typedef struct nodo_n {
    int dato;
    struct nodo_n** hijos;
    size_t num_hijos;
    size_t capacidad_hijos;
} nodo_n_t;

nodo_n_t* nodo_crear(int dato);
void nodo_agregar_hijo(nodo_n_t* padre, nodo_n_t* hijo);
void nodo_destruir(nodo_n_t** ptr_nodo);
```

## 13: Optimización y Performance

### 13.1: Alineación de Memoria

Medir el tamaño de estas estructuras y explicar el padding:

```c
struct sin_optimizar {
    char a;
    int b;
    char c;
    double d;
};

struct optimizada {
    double d;
    int b;
    char a;
    char c;
};
```

Usar `sizeof()` y `offsetof()` para visualizar el layout.

### 13.2: Cache Locality - Matrix Multiplication

Implementar multiplicación de matrices de dos formas:

```c
// Versión 1: acceso cache-friendly
void multiplicar_v1(int** A, int** B, int** C, size_t n);

// Versión 2: acceso cache-unfriendly (intercambiar lazos)
void multiplicar_v2(int** A, int** B, int** C, size_t n);
```

Comparar tiempos para matrices 1000x1000.

### 13.3: Memory-Mapped vs. Array Acccess

Comparar el rendimiento de acceder datos desde:
1. Un array normal en memoria
2. Un archivo mapeado en memoria con `mmap()`

```c
// Crear archivo grande
// Opción A: leer con fread() tradicional
// Opción B: mapear con mmap() y acceder como array
```

## 14: Debugging y Herramientas

### 14.1: Uso de Valgrind

Escribir un programa con varios errores de memoria y analizarlo con Valgrind:

```bash
gcc -g programa.c -o programa
valgrind --leak-check=full --show-leak-kinds=all ./programa
```

**Errores a incluir:**
- Memory leak
- Use after free
- Invalid read/write

### 14.2: AddressSanitizer

Compilar el mismo programa con ASan y comparar la salida:

```bash
gcc -fsanitize=address -g programa.c -o programa
./programa
```

### 14.3: Custom Allocator con Tracking

Implementar wrappers de malloc/free que registren todas las asignaciones:

```c
typedef struct {
    void* ptr;
    size_t tamano;
    const char* archivo;
    int linea;
} registro_t;

void* mi_malloc(size_t size, const char* archivo, int linea);
void mi_free(void* ptr, const char* archivo, int linea);
void imprimir_leaks(void);

#define malloc(s) mi_malloc(s, __FILE__, __LINE__)
#define free(p) mi_free(p, __FILE__, __LINE__)
```

## 15: Casos Especiales y Edge Cases

### 15.1: Asignación de Tamaño Cero

Investigar el comportamiento de `malloc(0)`:

```c
void* ptr = malloc(0);
printf("malloc(0) retornó: %p\n", ptr);
free(ptr);  // ¿Es seguro?
```

**Pregunta:** ¿Es válido? ¿Qué dice el estándar C?

### 15.2: Alineación Personalizada

Alojar memoria alineada a 64 bytes (tamaño de cache line):

```c
void* ptr;
posix_memalign(&ptr, 64, 1024);
// Verificar que (uintptr_t)ptr % 64 == 0
```

### 15.3: Estructuras Auto-referenciadas

Trabajar con estructuras que se apuntan a sí mismas (grafos cíclicos):

```c
typedef struct nodo_circular {
    int dato;
    struct nodo_circular* siguiente;
} nodo_circular_t;
```

Implementar función de destrucción que detecte ciclos para evitar lazo infinito.

### 15.4: Ownership y Transferencia

Implementar un sistema de ownership explícito:

```c
typedef struct {
    char* datos;
    bool es_propietario;  // ¿Debe liberar al destruirse?
} buffer_t;

buffer_t buffer_from_malloc(char* datos);  // Toma ownership
buffer_t buffer_from_ref(char* datos);     // Solo referencia
void buffer_destruir(buffer_t* buf);       // Libera solo si es propietario
```

## 16: Patrones Avanzados

### 16.1: Object Pool con Free List

Implementar un pool que mantenga una lista de objetos libres:

```c
typedef struct nodo_libre {
    struct nodo_libre* siguiente;
} nodo_libre_t;

typedef struct {
    void* memoria;
    nodo_libre_t* libre_lista;
    size_t tamano_objeto;
    size_t capacidad;
} object_pool_t;
```

### 16.2: Arena Allocator

Implementar un allocator que asigne memoria de un bloque grande y la libere toda de una vez:

```c
typedef struct {
    char* memoria;
    size_t tamano;
    size_t usado;
} arena_t;

arena_t* arena_crear(size_t tamano);
void* arena_alloc(arena_t* arena, size_t size);
void arena_reset(arena_t* arena);  // Libera todo sin free individual
void arena_destruir(arena_t* arena);
```

### 16.3: Copy-on-Write

Implementar un buffer con semántica copy-on-write:

```c
typedef struct {
    int* datos;
    size_t tamano;
    int* refcount;  // Contador de referencias compartido
} buffer_cow_t;

buffer_cow_t buffer_crear(size_t tamano);
buffer_cow_t buffer_copiar(buffer_cow_t* original);  // Copia shallow
void buffer_modificar(buffer_cow_t* buf, size_t idx, int valor);  // Copia si refcount > 1
```

## 17: Integración con Sistema Operativo

### 17.1: Paginación y `sysconf`

Obtener información del sistema sobre memoria:

```c
long page_size = sysconf(_SC_PAGESIZE);
long phys_pages = sysconf(_SC_PHYS_PAGES);
long avail_pages = sysconf(_SC_AVPHYS_PAGES);

printf("Tamaño de página: %ld bytes\n", page_size);
printf("Memoria total: %.2f GB\n", 
       (double)(phys_pages * page_size) / (1024*1024*1024));
```

### 17.2: Memory Mapping de Archivos

Mapear un archivo en memoria y accederlo como array:

```c
int fd = open("datos.bin", O_RDONLY);
struct stat sb;
fstat(fd, &sb);

int* datos = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
// Acceder datos[i] directamente
munmap(datos, sb.st_size);
```

### 17.3: Memoria Compartida entre Procesos

Crear un segmento de memoria compartida:

```c
int shm_fd = shm_open("/mi_memoria", O_CREAT | O_RDWR, 0666);
ftruncate(shm_fd, sizeof(int) * 100);
int* datos = mmap(NULL, sizeof(int) * 100, PROT_READ | PROT_WRITE,
                  MAP_SHARED, shm_fd, 0);
// Múltiples procesos pueden acceder 'datos'
```

## 18: Ejercicios Integradores

### 18.1: Agenda de Contactos Completa

Crear un sistema de agenda con:
- Lista enlazada de contactos
- Cada contacto tiene nombre, múltiples teléfonos, dirección
- Funciones: agregar, buscar, eliminar, modificar
- Persistencia en archivo
- Manejo robusto de memoria

### 18.2: Sistema de Base de Datos en Memoria

Implementar una mini base de datos con:
- Tabla (array dinámico de registros)
- Índices (hash tables para búsqueda rápida)
- Soporte para múltiples tablas
- Joins simples

### 18.3: Parser y Evaluador de Expresiones

Crear un evaluador de expresiones matemáticas:
- Parser que construye un árbol sintáctico abstracto (AST)
- Cada nodo del árbol es dinámico
- Soportar operadores: +, -, *, /, ^
- Evaluación recursiva del AST
- Liberación correcta de todo el árbol

## 19: Preguntas Conceptuales

### 19.1: Orden de Liberación

**Pregunta:** Dada esta estructura:

```c
typedef struct {
    char* nombre;
    int** matriz;
    size_t filas;
    size_t cols;
} datos_t;
```

Listar en orden todos los `free()` necesarios y explicar por qué ese orden.

### 19.2: `realloc` y Punteros Dangling

**Pregunta:** ¿Por qué este código es peligroso?

```c
int* arr = malloc(10 * sizeof(int));
int* ptr = &arr[5];  // Puntero al quinto elemento

arr = realloc(arr, 20 * sizeof(int));

*ptr = 42;  // ¿Problema?
```

### 19.3: Shallow Copy vs Deep Copy

**Pregunta:** Explicar la diferencia con un ejemplo concreto. ¿Cuándo es apropiado cada uno?

### 19.4: Fragmentación y Rendimiento

**Pregunta:** Si tenés 1GB de RAM libre pero todos los `malloc(1MB)` fallan, ¿qué está pasando? ¿Cómo lo solucionarías?

### 19.5: Stack Overflow por Recursión

**Pregunta:** ¿Por qué una función recursiva puede causar stack overflow pero un árbol de 1 millón de nodos en el heap funciona bien? Explicar la diferencia fundamental entre stack y heap.

## 20: Desafíos Avanzados

### 20.1: Garbage Collector Simple

Implementar un garbage collector básico con mark-and-sweep:
1. Mantener registro de todas las asignaciones
2. Mark: marcar objetos alcanzables desde raíces
3. Sweep: liberar objetos no marcados

### 20.2: Smart Pointers en C

Implementar punteros con conteo de referencias automático:

```c
typedef struct {
    void* ptr;
    size_t* refcount;
    void (*destructor)(void*);
} smart_ptr_t;

smart_ptr_t smart_ptr_crear(void* ptr, void (*destructor)(void*));
smart_ptr_t smart_ptr_copiar(smart_ptr_t* sp);
void smart_ptr_destruir(smart_ptr_t* sp);
```

### 20.3: Serialización de Estructuras

Implementar serialización/deserialización de estructuras con punteros:
- Guardar estructura completa en archivo binario
- Reconstruir estructura con todos sus punteros al cargar
- Manejar punteros circulares

