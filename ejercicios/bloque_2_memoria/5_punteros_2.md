---
title: Ejercicios de Memoria Dinámica Avanzada
short_title: 2. Punteros II
---

# Ejercicios de Memoria Dinámica Avanzada

## Acerca de

Estos ejercicios abordan la gestión avanzada de recursos en el Heap, abarcando
estructuras anidadas, matrices dinámicas (dentadas y contiguas) y el tratamiento
defensivo de errores en tiempo de ejecución.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-aritmetica-punteros`

### Cuestiones de Estilo Aplicables
- **Manejo seguro de punteros:** Es mandatorio liberar en el orden inverso a la
  asignación (de adentro hacia afuera) y establecer los punteros en `NULL` tras
  su liberación para prevenir dangling pointers (ver {ref}`0x3002h`).
- **Verificación de malloc:** Siempre se debe validar el resultado de las
  llamadas a `malloc`, `calloc` y `realloc` antes de realizar operaciones de
  lectura o escritura.

---

## Estructuras con Punteros

### Ejercicio 2.1 - Creación de Persona

Implementar un constructor para la estructura `persona_t`:

```{code-block} c
:linenos:
typedef struct {
    char* nombre;
    char* apellido;
    int edad;
} persona_t;

persona_t* persona_crear(const char* nombre, const char* apellido, int edad);

```
<!-- {code-block} c -->

**Requisitos:**
- Verificar que los parámetros no sean nulos.
- Manejar fallos de `malloc` en cualquier etapa, liberando memoria ya asignada.
- Retornar `NULL` si alguna asignación falla.
- Inicializar todos los campos correctamente.

### Ejercicio 2.2 - Destrucción de Persona

Implementar el destructor correspondiente:

``` c
void persona_destruir(persona_t** ptr_persona);
```
<!-- c -->

**Requisitos:**
- Liberar en el orden correcto (de adentro hacia afuera).
- Verificar que el puntero no sea `NULL`.
- Poner el puntero en `NULL` después de liberar.
- Manejar correctamente el doble puntero.

### Ejercicio 2.3 - Clonación Profunda

Implementar una función que cree una copia completamente independiente de una
persona:

``` c
persona_t* persona_clonar(const persona_t* original);
```
<!-- c -->

La copia debe tener su propia memoria asignada para `nombre` y `apellido`, no
compartir punteros con el original.

### Ejercicio 2.4 - Estructura con Múltiples Niveles

Implementar constructor y destructor para esta estructura anidada:

```{code-block} c
:linenos:
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
<!-- {code-block} c -->

**Desafío:** Manejar correctamente tres niveles de asignación: la estructura
principal, la dirección anidada, y el array dinámico de cadenas.

---

## Manejo de Errores en Cadena

### Ejercicio 2.5 - Rollback Completo

Escribir una función que asigne memoria para una estructura de estudiante con
cursos:

```{code-block} c
:linenos:
typedef struct {
    char* nombre;
    char** cursos;
    int* notas;
    size_t n_cursos;
} estudiante_t;

```
<!-- {code-block} c -->

Si la asignación de `notas` falla después de haber asignado `nombre` y `cursos`,
la función debe liberar `nombre` y `cursos` antes de retornar `NULL` para evitar
fugas de memoria.

### Ejercicio 2.6 - Alternativa con Goto

Implementar la función del ejercicio anterior estructurando la liberación de
recursos en una sección de limpieza al final de la función mediante `goto`, como
se describe en las buenas prácticas de la cátedra.

---

## Matrices Dinámicas

### Ejercicio 2.7 - Matriz Dentada (Array de Punteros)

Implementar funciones para crear y liberar una matriz dentada donde cada fila se
aloja como un bloque independiente.

``` c
int** crear_matriz_dentada(size_t filas, size_t columnas);
void liberar_matriz_dentada(int*** ptr_matriz, size_t filas);
```
<!-- c -->

### Ejercicio 2.8 - Matriz de Bloque Único (Contigua)

Implementar funciones para crear y liberar una matriz contigua en memoria,
reservando un único bloque para todos los datos y configurando el array de
punteros a filas.

``` c
int** crear_matriz_contigua(size_t filas, size_t columnas);
void liberar_matriz_contigua(int*** ptr_matriz);
```
<!-- c -->

### Ejercicio 2.9 - Conversión de Array Plano a Matriz

Implementar una función que reciba un arreglo plano (`int*`) de tamaño $N \times
M$ y retorne una estructura de punteros a filas (`int**`) que permita acceder al
mismo usando la notación `matriz[i][j]`.

---

## Optimización y Casos Prácticos

### Ejercicio 2.10 - Vector Redimensionable con Crecimiento

Implementar un vector dinámico de enteros que duplique su capacidad
automáticamente al llenarse, asegurando un manejo correcto del valor de retorno
de `realloc` mediante un puntero intermedio temporal.

### Ejercicio 2.11 - Reducción Dinámica de Capacidad (Shrinking)

Modificar el vector del ejercicio anterior para reducir su capacidad a la mitad
si la cantidad de elementos en uso cae por debajo de 1/4 de su capacidad máxima.

### Ejercicio 2.12 - Gestión de Memoria en el Parser JSON

Diseñar las funciones de reserva y liberación para un nodo AST de un parser JSON
que representa objetos y arreglos anidados mediante punteros dinámicos.

### Ejercicio 2.13 - Heap Buffer Overflow

Escribir un fragmento de código que produzca un desbordamiento de búfer en el
Heap y explicar cómo AddressSanitizer reporta dicho error.

---

## Ejercicios Adicionales (Práctica Intensiva)

## Ejercicio 1: Matriz Dinámica Dentada

**Dificultad:** ⭐⭐☆☆☆

Creá matriz donde cada fila tiene diferente cantidad de columnas.

**Orientación:**
```c
int filas = 3;
int cols[] = {2, 4, 3};

int **matriz = malloc(filas * sizeof(int*));
for (int i = 0; i < filas; i++) {
    matriz[i] = malloc(cols[i] * sizeof(int));
}
```
- Liberación: cada fila primero, luego array de punteros

---

## Ejercicio 2: Matriz Dinámica en Bloque

**Dificultad:** ⭐⭐⭐☆☆

Creá matriz contigua en memoria (un solo `malloc` para datos).

**Orientación:**
```c
int **crear_matriz(int filas, int cols) {
    int **matriz = malloc(filas * sizeof(int*));
    int *datos = malloc(filas * cols * sizeof(int));
    
    for (int i = 0; i < filas; i++) {
        matriz[i] = datos + i * cols;
    }
    return matriz;
}
```
- Ventaja: mejor localidad de caché
- Liberación: liberar datos, luego array de punteros

---

## Ejercicio 3: Matriz con Cast (ALV)

**Dificultad:** ⭐⭐⭐☆☆

Implementá acceso a matriz unidimensional como bidimensional.

**Orientación:**
```c
int *matriz = malloc(filas * cols * sizeof(int));
// Acceso: matriz[i * cols + j]

// O macro:
#define MAT(m, i, j, cols) ((m)[(i) * (cols) + (j)])
MAT(matriz, 2, 3, cols) = 42;
```
- Un solo `malloc` y `free`
- Menos flexible pero más eficiente

---

## Ejercicio 4: Redimensionar Array Dinámico

**Dificultad:** ⭐⭐⭐☆☆

Implementá función para redimensionar array preservando datos.

**Orientación:**
```c
int *redimensionar(int *arr, int tam_actual, int tam_nuevo) {
    int *nuevo = realloc(arr, tam_nuevo * sizeof(int));
    if (nuevo == NULL) {
        // Manejar error, NO liberar arr
        return NULL;
    }
    // Si tam_nuevo > tam_actual, nuevos elementos sin inicializar
    return nuevo;
}
```

---

## Ejercicio 5: Array de Strings Dinámico

**Dificultad:** ⭐⭐⭐☆☆

Creá array dinámico de strings donde cada string también es dinámico.

**Orientación:**
```c
char **strings = malloc(n * sizeof(char*));
for (int i = 0; i < n; i++) {
    strings[i] = malloc((strlen(input) + 1) * sizeof(char));
    strcpy(strings[i], input);
}

// Liberación:
for (int i = 0; i < n; i++) {
    free(strings[i]);
}
free(strings);
```

---

## Ejercicio 6: Estructura con Arrays Dinámicos

**Dificultad:** ⭐⭐⭐☆☆

Creá estructura que contenga arrays dinámicos.

**Orientación:**
```c
typedef struct {
    int *datos;
    size_t tamanio;
    size_t capacidad;
} vector_t;

vector_t *crear_vector(size_t cap_inicial) {
    vector_t *v = malloc(sizeof(vector_t));
    v->datos = malloc(cap_inicial * sizeof(int));
    v->tamanio = 0;
    v->capacidad = cap_inicial;
    return v;
}

void destruir_vector(vector_t *v) {
    free(v->datos);  // Primero datos
    free(v);         // Luego estructura
}
```

---

## Ejercicio 7: Lista Enlazada con Strings

**Dificultad:** ⭐⭐⭐⭐☆

Implementá lista donde cada nodo contiene un string dinámico.

**Orientación:**
```c
typedef struct nodo {
    char *str;  // String dinámico
    struct nodo *siguiente;
} nodo_t;

nodo_t *crear_nodo(const char *str) {
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    nuevo->str = malloc(strlen(str) + 1);
    strcpy(nuevo->str, str);
    nuevo->siguiente = NULL;
    return nuevo;
}

void liberar_nodo(nodo_t *nodo) {
    free(nodo->str);  // Primero el string
    free(nodo);       // Luego el nodo
}
```

---

## Ejercicio 8: Árbol con Datos Dinámicos

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá árbol binario donde cada nodo tiene string dinámico.

**Orientación:**
```c
typedef struct nodo_arbol {
    char *clave;  // Dinámico
    int valor;
    struct nodo_arbol *izq, *der;
} nodo_arbol_t;

void liberar_arbol(nodo_arbol_t *raiz) {
    if (raiz == NULL) return;
    liberar_arbol(raiz->izq);    // Postorden
    liberar_arbol(raiz->der);
    free(raiz->clave);
    free(raiz);
}
```

---

## Ejercicio 9: Matriz Triangular

**Dificultad:** ⭐⭐⭐⭐☆

Implementá matriz triangular inferior (solo almacená elementos <= diagonal).

**Orientación:**
- Fila i tiene i+1 elementos
- Total elementos: n(n+1)/2
```c
int **matriz = malloc(n * sizeof(int*));
for (int i = 0; i < n; i++) {
    matriz[i] = malloc((i + 1) * sizeof(int));
}
```

---

## Ejercicio 10: Copiar Estructura Profunda

**Dificultad:** ⭐⭐⭐⭐☆

Implementá copia profunda de estructura con punteros.

**Orientación:**
```c
typedef struct {
    char *nombre;
    int *calificaciones;
    size_t num_calificaciones;
} estudiante_t;

estudiante_t *copiar(const estudiante_t *orig) {
    estudiante_t *copia = malloc(sizeof(estudiante_t));
    copia->nombre = strdup(orig->nombre);  // O malloc+strcpy
    copia->num_calificaciones = orig->num_calificaciones;
    copia->calificaciones = malloc(orig->num_calificaciones * sizeof(int));
    memcpy(copia->calificaciones, orig->calificaciones, 
           orig->num_calificaciones * sizeof(int));
    return copia;
}
```

---

## Ejercicio 11: Grafo con Matriz de Adyacencia Dinámica

**Dificultad:** ⭐⭐⭐⭐⭐

Creá grafo con matriz de adyacencia dinámica.

**Orientación:**
```c
typedef struct {
    int **adj;  // Matriz NxN
    int vertices;
} grafo_t;

grafo_t *crear_grafo(int n) {
    grafo_t *g = malloc(sizeof(grafo_t));
    g->vertices = n;
    g->adj = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adj[i] = calloc(n, sizeof(int));  // Inicializado a 0
    }
    return g;
}
```

---

## Ejercicio 12: Array de Estructuras con Punteros

**Dificultad:** ⭐⭐⭐⭐☆

Creá array dinámico de estructuras que contienen punteros.

**Orientación:**
```c
typedef struct {
    char *titulo;
    int *capitulos;
    int num_caps;
} libro_t;

libro_t *libros = malloc(n * sizeof(libro_t));

// Liberación compleja: cada campo de cada estructura
for (int i = 0; i < n; i++) {
    free(libros[i].titulo);
    free(libros[i].capitulos);
}
free(libros);
```

---

## Ejercicio 13: Tabla Hash Dinámica

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá tabla hash con encadenamiento y redimensionamiento.

**Orientación:**
```c
typedef struct entrada {
    char *clave;
    void *valor;
    struct entrada *siguiente;
} entrada_t;

typedef struct {
    entrada_t **tabla;
    size_t tamanio;
    size_t num_elementos;
} hash_t;

void redimensionar(hash_t *h) {
    size_t nuevo_tam = h->tamanio * 2;
    entrada_t **nueva_tabla = calloc(nuevo_tam, sizeof(entrada_t*));
    // Rehash: mover elementos de tabla vieja a nueva
    // Liberar tabla vieja
}
```

---

## Ejercicio 14: Matriz Dispersa (Sparse Matrix)

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá matriz dispersa con lista de triplas (fila, col, valor).

**Orientación:**
```c
typedef struct {
    int fila, col;
    double valor;
} tripla_t;

typedef struct {
    tripla_t *elementos;
    size_t num_elementos;
    size_t capacidad;
    int filas, cols;
} matriz_dispersa_t;
```
- Solo almacená elementos != 0
- Búsqueda lineal o binaria para acceso

---

## Ejercicio 15: Buffer Circular Dinámico

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá buffer circular con redimensionamiento.

**Orientación:**
```c
typedef struct {
    void **datos;
    size_t capacidad;
    size_t inicio, fin;
    size_t tamanio;
} buffer_circular_t;

void redimensionar_buffer(buffer_circular_t *b) {
    size_t nueva_cap = b->capacidad * 2;
    void **nuevo = malloc(nueva_cap * sizeof(void*));
    
    // Copiar elementos en orden
    size_t idx = b->inicio;
    for (size_t i = 0; i < b->tamanio; i++) {
        nuevo[i] = b->datos[idx];
        idx = (idx + 1) % b->capacidad;
    }
    
    free(b->datos);
    b->datos = nuevo;
    b->inicio = 0;
    b->fin = b->tamanio;
    b->capacidad = nueva_cap;
}
```

---

## Ejercicio 16: Punteros a Punteros para Modificar

**Dificultad:** ⭐⭐⭐⭐☆

Implementá función que modifica puntero pasado como argumento.

**Orientación:**
```c
void insertar_inicio(nodo_t **cabeza, int valor) {
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;  // Modifica el puntero original
}

// Uso:
nodo_t *lista = NULL;
insertar_inicio(&lista, 42);  // Pasa dirección del puntero
```

---

## Ejercicio 17: Array 3D Dinámico

**Dificultad:** ⭐⭐⭐⭐⭐

Creá array tridimensional dinámico.

**Orientación:**
```c
int ***crear_array_3d(int x, int y, int z) {
    int ***arr = malloc(x * sizeof(int**));
    for (int i = 0; i < x; i++) {
        arr[i] = malloc(y * sizeof(int*));
        for (int j = 0; j < y; j++) {
            arr[i][j] = malloc(z * sizeof(int));
        }
    }
    return arr;
}

void liberar_array_3d(int ***arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(arr[i][j]);  // Nivel más profundo primero
        }
        free(arr[i]);
    }
    free(arr);
}
```

---

## Ejercicio 18: Pool de Objetos

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá pool de objetos para evitar malloc/free frecuentes.

**Orientación:**
```c
typedef struct {
    void *bloques;
    size_t tam_objeto;
    size_t capacidad;
    void **libres;  // Stack de objetos libres
    size_t num_libres;
} pool_t;

void *pool_alloc(pool_t *p) {
    if (p->num_libres == 0) return NULL;
    return p->libres[--p->num_libres];
}

void pool_free(pool_t *p, void *obj) {
    p->libres[p->num_libres++] = obj;
}
```

---

## Ejercicio 19: Reference Counting

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá sistema de conteo de referencias para compartir datos.

**Orientación:**
```c
typedef struct {
    void *datos;
    size_t contador_refs;
} ref_counted_t;

ref_counted_t *crear_ref(void *datos) {
    ref_counted_t *r = malloc(sizeof(ref_counted_t));
    r->datos = datos;
    r->contador_refs = 1;
    return r;
}

void incrementar_ref(ref_counted_t *r) {
    r->contador_refs++;
}

void decrementar_ref(ref_counted_t *r, void (*destruir)(void*)) {
    if (--r->contador_refs == 0) {
        destruir(r->datos);
        free(r);
    }
}
```

---

## Ejercicio 20: Sistema de Memoria con Debug

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá wrapper de malloc/free que registre asignaciones.

**Orientación:**
```c
typedef struct {
    void *ptr;
    size_t tamanio;
    const char *archivo;
    int linea;
} alloc_info_t;

#define MALLOC_DEBUG(size) malloc_debug(size, __FILE__, __LINE__)
#define FREE_DEBUG(ptr) free_debug(ptr, __FILE__, __LINE__)

void *malloc_debug(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    // Registrar en tabla de asignaciones
    return ptr;
}

void mostrar_leaks() {
    // Mostrar asignaciones no liberadas
}
```

---

## Notas Finales

:::{danger} Orden de Liberación

**Regla de Oro:** Liberar en orden inverso a asignación

**Matriz dentada:**
```c
// Asignación:
int **m = malloc(filas * sizeof(int*));      // 1
for (i...) m[i] = malloc(cols * sizeof(int)); // 2

// Liberación:
for (i...) free(m[i]);  // 2 primero
free(m);                // 1 después
```

**Estructura con punteros:**
```c
// Asignación:
persona_t *p = malloc(sizeof(persona_t));    // 1
p->nombre = malloc(100);                      // 2

// Liberación:
free(p->nombre);  // 2 primero
free(p);          // 1 después
```
:::

:::{tip} Estrategias de Matrices Dinámicas

**1. Dentada (Jagged):**
- Ventaja: Filas de diferentes tamaños
- Desventaja: Múltiples malloc, peor localidad

**2. Bloque con Punteros:**
- Ventaja: Datos contiguos, mejor cache
- Desventaja: Dos mallocs, sintaxis M[i][j]

**3. Cast/ALV (Array Lineal Virtual):**
- Ventaja: Un malloc, máxima eficiencia
- Desventaja: Sintaxis M[i*cols+j], menos flexible

**Elección:** Depende de requisitos de performance y flexibilidad
:::

:::{warning} Errores Comunes

1. **Olvidar liberar datos internos:**
   ```c
   typedef struct { char *str; } S;
   S *s = malloc(sizeof(S));
   s->str = malloc(100);
   free(s);  // MAL: leak de s->str
   ```

2. **Orden incorrecto:**
   ```c
   free(m);      // MAL: pierde acceso a m[i]
   free(m[i]);   // Comportamiento indefinido
   ```

3. **Realloc mal usado:**
   ```c
   arr = realloc(arr, nuevo_tam);  // MAL: si falla, pierde arr original
   
   // BIEN:
   int *temp = realloc(arr, nuevo_tam);
   if (temp == NULL) { /* manejar error */ }
   arr = temp;
   ```

4. **Copiar punteros en lugar de datos:**
   ```c
   copia->nombre = orig->nombre;  // MAL: shallow copy
   copia->nombre = strdup(orig->nombre);  // BIEN: deep copy
   ```
:::

:::{note} Herramientas de Debugging

**Valgrind - Memcheck:**
```bash
valgrind --leak-check=full --show-leak-kinds=all ./programa
```

**AddressSanitizer:**
```bash
gcc -fsanitize=address -g programa.c
./programa
```

**Errores detectados:**
- Memory leaks
- Use after free
- Double free
- Buffer overflows
- Uninitialized memory
:::

Estas consignas cubren gestión avanzada de memoria y estructuras dinámicas complejas, esenciales para implementar TADs y aplicaciones de performance crítica.

