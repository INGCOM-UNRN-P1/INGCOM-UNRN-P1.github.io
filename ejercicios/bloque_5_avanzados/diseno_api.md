---
title: Ejercicios de Diseño de Interfaces y Librerías en C
short_title: Diseño de APIs
---

## Acerca de

Estos ejercicios profundizan en los principios de diseño de interfaces (APIs) en C, cubriendo claridad, encapsulamiento, manejo de errores, tipos opacos, contratos de interfaz, versionado y evolución de APIs. El objetivo es desarrollar la capacidad de crear módulos robustos, mantenibles y fáciles de usar, aplicando los principios profesionales del diseño de software.

## 1: Principios de Nomenclatura y Claridad

### 1.1: Crítica de Nombres

Analizar estos nombres de funciones y proponer mejoras siguiendo las reglas de estilo:

```c
// Biblioteca de procesamiento de imágenes
void process(img *i);
int calc(img *i, int x, int y);
void update(img *i, void *d);
int check(img *i);
void fix(img *i);
```

**Tareas:**
1. Identificar qué está mal con cada nombre
2. Proponer nombres descriptivos con prefijo apropiado
3. Agregar documentación de contrato para cada función

:::{tip} Nombres Descriptivos
Como se menciona en {ref}`api-claridad`, los nombres deben comunicar claramente la acción que realizan. Usar verbos específicos en lugar de genéricos como "process" o "update".
:::

### 1.2: Diseño de Prefijos

Diseñar esquemas de prefijos para estas librerías:

a) **Librería de gestión de base de datos**  
b) **Librería de compresión de archivos**  
c) **Librería de validación de entrada**  
d) **Librería de parseo JSON**

Para cada una:
- Proponer un prefijo corto pero descriptivo
- Listar 5 funciones típicas con el prefijo aplicado
- Justificar la elección del prefijo

**Ejemplo:**
```c
// Librería de parseo JSON - prefijo: json_
json_parser_t* json_parser_crear(void);
json_value_t* json_parser_parse_string(json_parser_t* parser, const char* str);
bool json_value_es_objeto(const json_value_t* value);
```

### 1.3: Consistencia en Familias de Funciones

Completar estas familias de funciones con nombres consistentes:

```c
// Familia de funciones para manejo de archivos de configuración
config_t* config_crear_vacio(void);
config_t* config_???_desde_archivo(const char* ruta);  // Cargar
bool config_???_a_archivo(const config_t* cfg, const char* ruta);  // Guardar
???  // Obtener valor de clave
???  // Establecer valor de clave
???  // Verificar si existe una clave
void config_destruir(config_t** ptr_config);
```

### 1.4: Nombres que Reflejan Comportamiento

Renombrar estas funciones para reflejar mejor su comportamiento real:

```c
// La función busca y reemplaza, no solo busca
char* buscar_texto(char* str, const char* patron, const char* reemplazo);

// La función no solo valida, también normaliza
bool validar_email(char* email);

// La función no solo obtiene, calcula en tiempo real
double obtener_promedio(const int* calificaciones, size_t n);

// La función no agrega, inserta ordenadamente
void agregar_elemento(lista_t* lista, int elemento);
```

## 2: Tipos Opacos y Encapsulamiento

### 2.1: Implementación de Tipo Opaco Básico

Implementar un stack usando tipo opaco completo:

**`stack.h`** (interfaz pública):
```c
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct stack stack_t;  // Declaración adelantada

stack_t* stack_crear(size_t capacidad_inicial);
void stack_destruir(stack_t** ptr_stack);

bool stack_push(stack_t* stack, int valor);
bool stack_pop(stack_t* stack, int* valor);
bool stack_peek(const stack_t* stack, int* valor);

size_t stack_tamano(const stack_t* stack);
bool stack_esta_vacio(const stack_t* stack);

#endif
```

**Tareas:**
1. Implementar `stack.c` con la estructura completa
2. Garantizar que el usuario no pueda acceder a campos internos
3. Manejar correctamente los errores (stack vacío, memoria agotada)

### 2.2: Ventajas del Tipo Opaco

Comparar dos versiones de una estructura:

**Versión A: Estructura expuesta**
```c
// vector.h
typedef struct {
    int* datos;
    size_t tamano;
    size_t capacidad;
} vector_t;

void vector_init(vector_t* vec);
```

**Versión B: Tipo opaco**
```c
// vector.h
typedef struct vector vector_t;

vector_t* vector_crear(void);
```

**Preguntas conceptuales:**
1. ¿Qué puede hacer el usuario con la versión A que no puede con la B?
2. ¿Qué ventajas tiene B para el mantenedor de la librería?
3. Si querés agregar un campo `version` a la estructura, ¿cuál versión permite hacerlo sin romper compatibilidad?
4. ¿Cuál es más eficiente en memoria? ¿Por qué?

### 2.3: Patrón Handle

Implementar un tipo opaco usando el patrón handle (identificador):

```c
// archivo.h
typedef int archivo_handle_t;
#define ARCHIVO_HANDLE_INVALIDO (-1)

archivo_handle_t archivo_abrir(const char* ruta, const char* modo);
bool archivo_escribir(archivo_handle_t handle, const void* datos, size_t bytes);
bool archivo_leer(archivo_handle_t handle, void* buffer, size_t bytes);
void archivo_cerrar(archivo_handle_t handle);
```

**Tareas:**
1. Implementar la tabla interna de handles
2. Validar handles en cada operación
3. Manejar reutilización de handles cerrados

### 2.4: Acceso Controlado con Getters

Diseñar getters para exponer información sin romper encapsulamiento:

```c
typedef struct producto producto_t;

// Implementar:
const char* producto_obtener_nombre(const producto_t* p);
double producto_obtener_precio(const producto_t* p);
int producto_obtener_stock(const producto_t* p);

// ¿Cómo exponer una fecha sin exponer la implementación interna?
// ¿Debería retornar un puntero a la estructura interna?
??? producto_obtener_fecha_vencimiento(const producto_t* p);
```

**Pregunta:** ¿Por qué retornar `const char*` en lugar de `char*`?

## 3: Contratos de Interfaz y Precondiciones

### 3.1: Documentación de Contratos

Documentar completamente el contrato de estas funciones:

```c
/**
 * [COMPLETAR DOCUMENTACIÓN]
 */
double vector_producto_punto(const double* v1, const double* v2, size_t n);

/**
 * [COMPLETAR DOCUMENTACIÓN]
 */
int* arreglo_buscar_binario(int* arr, size_t n, int target);

/**
 * [COMPLETAR DOCUMENTACIÓN]
 */
void cadena_dividir(const char* str, char delim, char*** resultado, size_t* count);
```

Para cada función, especificar:
- **Propósito:** ¿Qué hace la función?
- **Precondiciones:** ¿Qué debe garantizar el llamador?
- **Poscondiciones:** ¿Qué garantiza la función al retornar?
- **Parámetros:** Descripción de cada parámetro
- **Retorno:** Qué representa el valor de retorno
- **Notas:** Responsabilidad de memoria, complejidad, etc.

### 3.2: Validación de Precondiciones

Para cada función, decidir si debe validar precondiciones o asumirlas:

```c
// Opción 1: Asumir precondiciones (más rápido, menos seguro)
double promedio(const int* arr, size_t n) {
    // ¿Verificar arr != NULL y n > 0?
    int suma = 0;
    for (size_t i = 0; i < n; i++) {
        suma += arr[i];
    }
    return (double)suma / n;
}

// Opción 2: Validar precondiciones (más lento, más seguro)
double promedio_seguro(const int* arr, size_t n, double* resultado) {
    if (arr == NULL || n == 0) {
        return false;
    }
    // ...
    return true;
}
```

**Preguntas:**
1. ¿Cuándo elegir una sobre la otra?
2. ¿Cómo documentar la decisión?
3. ¿Qué hacer en funciones críticas de performance?

### 3.3: Invariantes de Estructura

Definir e implementar una función de verificación de invariantes:

```c
typedef struct {
    int* datos;
    size_t tamano;
    size_t capacidad;
} vector_t;

/**
 * Verifica los invariantes del vector.
 * Invariantes:
 * 1. Si capacidad > 0, entonces datos != NULL
 * 2. tamano <= capacidad
 * 3. [AGREGAR MÁS]
 */
bool vector_verificar_invariantes(const vector_t* vec);
```

Usar esta función en modo debug:
```c
#ifdef DEBUG
#define VERIFICAR_INVARIANTES(vec) assert(vector_verificar_invariantes(vec))
#else
#define VERIFICAR_INVARIANTES(vec) ((void)0)
#endif
```

### 3.4: Contratos con Aliasing

Analizar problemas de aliasing en contratos:

```c
/**
 * Copia n bytes de src a dest.
 * 
 * PRECONDICIÓN: ???
 * ¿Qué pasa si src y dest se solapan?
 */
void mi_memcpy(void* dest, const void* src, size_t n);

/**
 * Mueve n bytes de src a dest, manejando solapamiento.
 * 
 * PRECONDICIÓN: ???
 * ¿Cómo especificar que puede manejar solapamiento?
 */
void mi_memmove(void* dest, const void* src, size_t n);
```

## 4: Manejo de Errores

### 4.1: Comparación de Estrategias

Implementar la misma funcionalidad con tres estrategias de error:

**Estrategia 1: Valor especial de retorno**
```c
int lista_buscar_indice(const lista_t* lista, int valor) {
    // Retornar -1 si no se encuentra
    // ¿Qué pasa si la búsqueda falla por lista == NULL?
}
```

**Estrategia 2: Código de error + parámetro de salida**
```c
typedef enum {
    LISTA_OK,
    LISTA_ERROR_NULL,
    LISTA_ERROR_NO_ENCONTRADO
} lista_error_t;

lista_error_t lista_buscar_indice_v2(const lista_t* lista, int valor, size_t* indice);
```

**Estrategia 3: errno global**
```c
extern int lista_errno;

#define LISTA_EXITO 0
#define LISTA_EPTR 1
#define LISTA_ENOTFOUND 2

int lista_buscar_indice_v3(const lista_t* lista, int valor);
```

**Análisis:**
- Ventajas y desventajas de cada enfoque
- ¿Cuál es thread-safe?
- ¿Cuál es más compatible con código existente?

### 4.2: Diseño de Enum de Errores

Diseñar un enum completo de códigos de error para una librería de archivos:

```c
typedef enum {
    ARCHIVO_OK = 0,         // Éxito siempre debe ser 0
    ARCHIVO_ERROR_MEMORIA,  // malloc falló
    // [COMPLETAR: agregar al menos 10 códigos más]
} archivo_error_t;

/**
 * Convierte código de error a cadena descriptiva.
 */
const char* archivo_error_str(archivo_error_t error);
```

**Requisitos:**
- Cubrir todos los casos de error posibles
- Nombres claros y con prefijo
- Documentar cuándo ocurre cada error

### 4.3: Propagación de Errores

Implementar una función que llama a otras y debe propagar errores:

```c
typedef enum {
    DB_OK = 0,
    DB_ERROR_CONEXION,
    DB_ERROR_CONSULTA,
    DB_ERROR_NO_ENCONTRADO,
    DB_ERROR_MEMORIA
} db_error_t;

/**
 * Busca un usuario por ID, actualiza su email y guarda cambios.
 * 
 * Esta función puede fallar en múltiples puntos:
 * 1. Buscar el usuario
 * 2. Validar el email
 * 3. Guardar cambios
 * 
 * ¿Cómo propagar cada error al caller?
 */
db_error_t db_usuario_actualizar_email(db_t* db, int user_id, const char* nuevo_email);
```

### 4.4: Logging de Errores

Implementar un sistema de logging interno que registre errores sin afectar la API pública:

```c
// Función interna, no expuesta en el .h
static void log_error_interno(const char* funcion, const char* mensaje);

// Uso:
lista_error_t lista_agregar(lista_t* lista, int valor) {
    if (lista == NULL) {
        log_error_interno(__func__, "puntero NULL recibido");
        return LISTA_ERROR_NULL;
    }
    // ...
}
```

**Pregunta:** ¿Cómo permitir que el usuario configure el nivel de logging sin modificar la API?

## 5: Gestión de Memoria en APIs

### 5.1: Quién Libera Qué

Analizar y documentar la responsabilidad de memoria en estas funciones:

```c
// Caso 1: ¿Quién libera el string retornado?
char* persona_obtener_nombre_completo(const persona_t* p);

// Caso 2: ¿Quién libera el arreglo? ¿Y los strings dentro?
char** archivo_leer_lineas(const char* ruta, size_t* num_lineas);

// Caso 3: ¿La función toma ownership del buffer?
void logger_set_buffer(logger_t* log, char* buffer, size_t tamano);

// Caso 4: ¿El caller debe pre-alojar? ¿Cuánto espacio necesita?
bool fecha_formatear(const fecha_t* f, char* buffer, size_t buffer_size);
```

Para cada caso, especificar claramente en la documentación quién es responsable de liberar memoria.

### 5.2: Patrón de Constructor/Destructor

Implementar el par constructor/destructor para una estructura compleja:

```c
typedef struct biblioteca biblioteca_t;

/**
 * Crea una biblioteca vacía.
 * 
 * @return Puntero a biblioteca, o NULL si falla la asignación.
 * 
 * RESPONSABILIDAD: El caller debe liberar con biblioteca_destruir().
 */
biblioteca_t* biblioteca_crear(void);

/**
 * Destruye una biblioteca y libera toda la memoria asociada.
 * 
 * Incluye:
 * - Todos los libros agregados
 * - Todas las categorías
 * - Índices internos
 * 
 * @param ptr_bib Puntero a puntero. Se pondrá en NULL después de liberar.
 * 
 * PRECONDICIÓN: ptr_bib != NULL
 * POSCONDICIÓN: *ptr_bib == NULL
 */
void biblioteca_destruir(biblioteca_t** ptr_bib);
```

**Implementación:** Crear un módulo completo con varios niveles de memoria dinámica.

### 5.3: Buffers Pre-alocados vs. Asignación Interna

Comparar dos diseños para una función de serialización:

**Diseño A: Caller provee buffer**
```c
/**
 * Serializa un objeto a JSON en el buffer provisto.
 * 
 * @param buffer Buffer pre-alocado por el caller
 * @param buffer_size Tamaño del buffer
 * @param bytes_escritos Número de bytes escritos (puede ser NULL)
 * @return true si exitoso, false si el buffer es muy pequeño
 */
bool objeto_a_json(const objeto_t* obj, char* buffer, size_t buffer_size, 
                   size_t* bytes_escritos);
```

**Diseño B: Función aloja memoria**
```c
/**
 * Serializa un objeto a JSON, asignando memoria dinámicamente.
 * 
 * @return String JSON asignado dinámicamente, o NULL si falla.
 * 
 * RESPONSABILIDAD: El caller debe liberar con free().
 */
char* objeto_a_json_alloc(const objeto_t* obj);
```

**Análisis:**
- ¿Cuándo usar cada diseño?
- ¿Impacto en performance?
- ¿Facilidad de uso?

### 5.4: Pool de Memoria

Diseñar una API que use un pool de memoria personalizado:

```c
typedef struct arena arena_t;

// API del arena
arena_t* arena_crear(size_t tamano_inicial);
void* arena_alloc(arena_t* arena, size_t bytes);
void arena_reset(arena_t* arena);  // Libera todo de golpe
void arena_destruir(arena_t* arena);

// API que usa el arena
typedef struct parser parser_t;

parser_t* parser_crear_con_arena(arena_t* arena);
nodo_ast_t* parser_parse(parser_t* p, const char* codigo);
// Todos los nodos del AST se alojan en el arena
```

**Ventaja:** Liberación masiva en $O(1)$ sin memory leaks.

## 6: Evolución y Versionado de APIs

### 6.1: Versionado Semántico

Clasificar estos cambios según SemVer (mayor.menor.parche):

a) Agregar un nuevo parámetro opcional al final de una función  
b) Cambiar el tipo de retorno de `int` a `long`  
c) Corregir un bug que causaba crash  
d) Agregar una nueva función a la API  
e) Cambiar el significado de un código de error  
f) Optimizar una función sin cambiar comportamiento  
g) Renombrar un parámetro (solo en el .h)  
h) Deprecar una función pero mantenerla funcional

**Respuestas:**
- ¿Cuáles requieren incrementar versión MAJOR?
- ¿Cuáles solo MINOR?
- ¿Cuáles solo PATCH?

### 6.2: Compatibilidad Binaria (ABI)

Analizar qué cambios rompen compatibilidad binaria (ABI):

```c
// Versión 1.0
typedef struct {
    int x;
    int y;
} punto_t;

void punto_imprimir(punto_t p);
```

**Cambios propuestos:**
```c
// Cambio A: Agregar campo al final
typedef struct {
    int x;
    int y;
    int z;  // NUEVO
} punto_t;

// Cambio B: Cambiar orden de campos
typedef struct {
    int y;  // Intercambiado
    int x;  // Intercambiado
} punto_t;

// Cambio C: Cambiar firma de función
void punto_imprimir(punto_t p, bool con_formato);  // Parámetro nuevo

// Cambio D: Cambiar de valor a puntero
void punto_imprimir(punto_t* p);  // Ahora puntero
```

**Pregunta:** ¿Cuáles rompen ABI? ¿Por qué?

### 6.3: Deprecación Gradual

Implementar la deprecación de una función antigua:

```c
// viejo_api.h (versión 1.x)
void config_load(const char* filename);  // Versión antigua

// nuevo_api.h (versión 2.x)
typedef enum {
    CONFIG_OK,
    CONFIG_ERROR_IO,
    CONFIG_ERROR_PARSE
} config_error_t;

config_error_t config_cargar_desde_archivo(const char* ruta);

// Wrapper de compatibilidad
#ifdef CONFIG_DEPRECATION_WARNINGS
#warning "config_load está deprecada, usar config_cargar_desde_archivo"
#endif

static inline void config_load(const char* filename) {
    config_cargar_desde_archivo(filename);
    // Ignora errores para mantener comportamiento original
}
```

### 6.4: Feature Flags

Diseñar un sistema de feature flags para habilitar funcionalidad experimental:

```c
// compilar con -DCONFIG_FEATURE_X para habilitar

#ifdef CONFIG_FEATURE_EXPERIMENTAL_CACHE
/**
 * [EXPERIMENTAL] Habilita caché de resultados.
 * Esta función puede cambiar o ser removida en futuras versiones.
 */
void lista_habilitar_cache(lista_t* lista);
#endif
```

## 7: Testing de APIs

### 7.1: Diseñar para Testabilidad

Refactorizar este código difícil de testear:

```c
// Difícil de testear: lee directamente de stdin
void procesar_comandos(void) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        ejecutar_comando(buffer);
    }
}
```

**Refactorización testeable:**
```c
// Inyección de dependencia: acepta FILE*
void procesar_comandos_desde(FILE* stream) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), stream)) {
        ejecutar_comando(buffer);
    }
}

// Wrapper conveniente para el caso común
static inline void procesar_comandos(void) {
    procesar_comandos_desde(stdin);
}
```

**Test:**
```c
void test_procesar_comandos(void) {
    FILE* test_input = fopen("test_input.txt", "r");
    procesar_comandos_desde(test_input);
    fclose(test_input);
    // Verificar resultados
}
```

### 7.2: Mock Objects

Diseñar una interfaz que permita inyectar mocks para testing:

```c
// Interfaz de operaciones de archivo
typedef struct {
    void* (*abrir)(const char* ruta);
    int (*leer)(void* handle, void* buffer, size_t bytes);
    void (*cerrar)(void* handle);
} archivo_ops_t;

// API principal acepta operaciones personalizadas
typedef struct procesador procesador_t;

procesador_t* procesador_crear(const archivo_ops_t* ops);

// Implementación real
extern const archivo_ops_t archivo_ops_real;

// Mock para testing
extern const archivo_ops_t archivo_ops_mock;
```

### 7.3: Tests de Contrato

Escribir tests que verifiquen el contrato de esta función:

```c
/**
 * Busca un elemento en un arreglo ordenado.
 * 
 * PRECONDICIÓN: arr ordenado ascendentemente
 * POSCONDICIÓN: Si retorna i >= 0, entonces arr[i] == target
 * 
 * @return Índice del elemento, o -1 si no se encuentra
 */
int buscar_binario(const int* arr, size_t n, int target);
```

**Tests a implementar:**
```c
void test_buscar_binario_elemento_presente(void);
void test_buscar_binario_elemento_ausente(void);
void test_buscar_binario_arreglo_vacio(void);
void test_buscar_binario_primer_elemento(void);
void test_buscar_binario_ultimo_elemento(void);
// ¿Qué otros casos?
```

### 7.4: Property-Based Testing

Definir propiedades que deben cumplirse siempre:

```c
// Propiedad: ordenar es idempotente
void property_ordenar_idempotente(void) {
    int arr[100];
    generar_arreglo_aleatorio(arr, 100);
    
    int copia1[100], copia2[100];
    memcpy(copia1, arr, sizeof(arr));
    memcpy(copia2, arr, sizeof(arr));
    
    ordenar(copia1, 100);
    ordenar(copia2, 100);
    
    // Propiedad: ordenar dos veces da mismo resultado que una vez
    assert(memcmp(copia1, copia2, sizeof(arr)) == 0);
}

// Propiedad: buscar después de insertar debe encontrar el elemento
void property_insertar_buscar(void) {
    lista_t* lista = lista_crear();
    int valor_aleatorio = rand();
    
    lista_insertar(lista, valor_aleatorio);
    
    assert(lista_contiene(lista, valor_aleatorio));
    
    lista_destruir(&lista);
}
```

## 8: Patrones de Diseño de APIs

### 8.1: Patrón Builder

Implementar el patrón builder para configuración compleja:

```c
typedef struct http_request_builder http_request_builder_t;
typedef struct http_request http_request_t;

// API fluida (cada función retorna el builder)
http_request_builder_t* http_request_builder_crear(void);
http_request_builder_t* http_request_builder_metodo(http_request_builder_t* b, const char* metodo);
http_request_builder_t* http_request_builder_url(http_request_builder_t* b, const char* url);
http_request_builder_t* http_request_builder_header(http_request_builder_t* b, const char* clave, const char* valor);
http_request_builder_t* http_request_builder_body(http_request_builder_t* b, const char* body);

// Construir el request final
http_request_t* http_request_builder_build(http_request_builder_t* b);

// Uso:
// http_request_t* req = http_request_builder_crear()
//     ->metodo("POST")
//     ->url("http://example.com")
//     ->header("Content-Type", "application/json")
//     ->build();
```

### 8.2: Patrón Iterator

Diseñar un iterador genérico para una colección:

```c
typedef struct lista lista_t;
typedef struct lista_iter lista_iter_t;

// API del iterador
lista_iter_t* lista_iter_crear(const lista_t* lista);
bool lista_iter_tiene_siguiente(const lista_iter_t* iter);
int lista_iter_siguiente(lista_iter_t* iter);
void lista_iter_destruir(lista_iter_t* iter);

// Uso:
lista_iter_t* iter = lista_iter_crear(lista);
while (lista_iter_tiene_siguiente(iter)) {
    int valor = lista_iter_siguiente(iter);
    printf("%d\n", valor);
}
lista_iter_destruir(iter);
```

**Pregunta:** ¿Qué pasa si la lista se modifica durante la iteración?

### 8.3: Patrón Factory

Implementar una factory para crear diferentes tipos de objetos:

```c
typedef enum {
    PARSER_JSON,
    PARSER_XML,
    PARSER_YAML
} parser_tipo_t;

typedef struct parser parser_t;

// Factory
parser_t* parser_crear(parser_tipo_t tipo);

// Interfaz común
bool parser_parse_string(parser_t* p, const char* str);
valor_t* parser_obtener_valor(parser_t* p, const char* clave);
void parser_destruir(parser_t* p);
```

**Implementación:** Usar punteros a funciones internamente para polimorfismo.

### 8.4: Patrón Callback

Diseñar una API con callbacks para procesamiento asíncrono:

```c
typedef void (*evento_callback_t)(void* contexto, const evento_t* evento);

typedef struct event_loop event_loop_t;

event_loop_t* event_loop_crear(void);
void event_loop_registrar_callback(event_loop_t* loop, 
                                    evento_tipo_t tipo,
                                    evento_callback_t callback,
                                    void* contexto);
void event_loop_ejecutar(event_loop_t* loop);
void event_loop_detener(event_loop_t* loop);
void event_loop_destruir(event_loop_t* loop);
```

## 9: APIs Thread-Safe

### 9.1: Análisis de Thread-Safety

Analizar si estas funciones son thread-safe:

```c
// Función 1: Variable estática
int contador_global(void) {
    static int count = 0;
    return count++;
}

// Función 2: errno global
int archivo_leer_linea(FILE* f, char* buffer, size_t size) {
    if (fgets(buffer, size, f) == NULL) {
        archivo_errno = ARCHIVO_ERROR_IO;
        return -1;
    }
    return 0;
}

// Función 3: Solo lectura
int arreglo_buscar(const int* arr, size_t n, int target) {
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Función 4: Mutex interno
void log_mensaje(const char* msg) {
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    fprintf(log_file, "%s\n", msg);
    pthread_mutex_unlock(&mutex);
}
```

### 9.2: Diseño Thread-Safe

Convertir esta API no thread-safe a thread-safe:

```c
// Versión NO thread-safe
typedef struct cache cache_t;

cache_t* cache_crear(void);
void cache_insertar(cache_t* c, const char* clave, const char* valor);
const char* cache_buscar(cache_t* c, const char* clave);
void cache_destruir(cache_t* c);
```

**Opciones de diseño:**
1. Mutex interno (transparente pero menos flexible)
2. Lock/unlock explícito (más control para el usuario)
3. Estructuras inmutables (lock-free)

### 9.3: Thread-Local Storage

Usar TLS para error handling thread-safe:

```c
// En lugar de errno global
__thread int mi_lib_errno = 0;

#define mi_lib_get_error() (mi_lib_errno)
#define mi_lib_set_error(err) (mi_lib_errno = (err))

// Uso en funciones
int mi_funcion(void) {
    if (error) {
        mi_lib_set_error(MI_LIB_ERROR_XYZ);
        return -1;
    }
    return 0;
}
```

### 9.4: Documentar Garantías de Concurrencia

Documentar las garantías de thread-safety:

```c
/**
 * [THREAD-SAFE] Puede ser llamada concurrentemente desde múltiples threads.
 * Usa locking interno.
 */
void logger_log(logger_t* logger, const char* mensaje);

/**
 * [NOT THREAD-SAFE] El caller debe sincronizar accesos.
 * Esta función modifica estado compartido sin locking.
 */
void cache_limpiar(cache_t* cache);

/**
 * [REENTRANT] Puede ser llamada recursivamente de forma segura.
 * No usa variables estáticas ni globales.
 */
int factorial(int n);
```

## 10: Performance y Optimización

### 10.1: API Zero-Copy

Diseñar una API que minimice copias de datos:

```c
// Malo: múltiples copias
char* archivo_leer_todo(const char* ruta);  // Copia 1: archivo → buffer interno
char* procesar_texto(const char* texto);    // Copia 2: buffer → nuevo buffer

// Bueno: zero-copy con buffer compartido
typedef struct buffer buffer_t;

buffer_t* buffer_desde_archivo(const char* ruta);  // Mapea archivo
const char* buffer_obtener_datos(const buffer_t* b);  // Acceso directo, sin copia
size_t buffer_obtener_tamano(const buffer_t* b);
void buffer_liberar(buffer_t* b);
```

### 10.2: API para Operaciones Batch

Diseñar API que permita operaciones en lote para mejor performance:

```c
// Ineficiente: múltiples llamadas
for (int i = 0; i < n; i++) {
    db_insertar(db, &registros[i]);  // Overhead por llamada
}

// Eficiente: operación batch
db_insertar_batch(db, registros, n);  // Una sola transacción
```

Implementar:
```c
typedef struct db db_t;
typedef struct registro registro_t;

// Operaciones individuales
bool db_insertar(db_t* db, const registro_t* reg);
bool db_actualizar(db_t* db, int id, const registro_t* reg);
bool db_eliminar(db_t* db, int id);

// Operaciones batch
bool db_insertar_batch(db_t* db, const registro_t* registros, size_t count);
bool db_eliminar_batch(db_t* db, const int* ids, size_t count);
```

### 10.3: Lazy Evaluation

Implementar evaluación perezosa en una API:

```c
typedef struct consulta consulta_t;
typedef struct resultado resultado_t;

// Construir consulta (sin ejecutar)
consulta_t* consulta_crear(db_t* db, const char* tabla);
consulta_t* consulta_filtrar(consulta_t* q, const char* campo, const char* valor);
consulta_t* consulta_ordenar(consulta_t* q, const char* campo);
consulta_t* consulta_limitar(consulta_t* q, size_t limite);

// Ejecutar solo cuando se necesita
resultado_t* consulta_ejecutar(consulta_t* q);  // Aquí ocurre el trabajo real

// Uso:
resultado_t* res = consulta_crear(db, "usuarios")
    ->filtrar("edad", "> 18")
    ->ordenar("nombre")
    ->limitar(10)
    ->ejecutar();  // Solo aquí se ejecuta la consulta
```

### 10.4: Profiling-Friendly API

Diseñar puntos de instrumentación en la API:

```c
typedef struct stats stats_t;

// API con estadísticas opcionales
cache_t* cache_crear_con_stats(size_t capacidad, stats_t* stats);

// Si stats != NULL, la cache registra métricas
typedef struct {
    uint64_t hits;
    uint64_t misses;
    uint64_t evictions;
    double hit_rate;
} cache_stats_t;

void cache_obtener_stats(const cache_t* c, cache_stats_t* stats);
void cache_resetear_stats(cache_t* c);
```

## 11: Internacionalización y Localización

### 11.1: Mensajes de Error Localizables

Diseñar un sistema de mensajes de error localizables:

```c
typedef enum {
    MSG_ERROR_MEMORIA,
    MSG_ERROR_ARCHIVO_NO_ENCONTRADO,
    MSG_ERROR_PERMISO_DENEGADO,
    // ...
} mensaje_id_t;

// Configurar idioma
void set_locale(const char* locale);  // "es_AR", "en_US", etc.

// Obtener mensaje traducido
const char* obtener_mensaje(mensaje_id_t id);

// Uso en API
int archivo_abrir(const char* ruta) {
    if (acceso_denegado) {
        fprintf(stderr, "%s: %s\n", 
                obtener_mensaje(MSG_ERROR_PERMISO_DENEGADO),
                ruta);
        return -1;
    }
}
```

### 11.2: Separación de Lógica y Presentación

Refactorizar para separar lógica de UI:

```c
// Malo: mezcla lógica con presentación
void procesar_pedido(pedido_t* p) {
    if (validar_pedido(p)) {
        printf("Pedido válido!\n");  // ¡Hardcoded en español!
        guardar_pedido(p);
    } else {
        printf("Error: pedido inválido\n");
    }
}

// Bueno: retornar código, caller decide cómo presentar
typedef enum {
    PEDIDO_OK,
    PEDIDO_ERROR_VALIDACION,
    PEDIDO_ERROR_BD
} pedido_resultado_t;

pedido_resultado_t procesar_pedido(pedido_t* p);

// Caller decide presentación
pedido_resultado_t res = procesar_pedido(pedido);
if (res == PEDIDO_OK) {
    ui_mostrar_mensaje(MSG_PEDIDO_EXITOSO);
} else {
    ui_mostrar_error(mensaje_para_resultado(res));
}
```

## 12: Documentación de APIs

### 12.1: Documentación Completa

Escribir documentación completa para este módulo:

```c
/**
 * @file cola.h
 * @brief [COMPLETAR]
 * 
 * [COMPLETAR: Descripción general del módulo]
 * 
 * Ejemplo de uso:
 * @code
 * [AGREGAR EJEMPLO]
 * @endcode
 * 
 * @author [Tu nombre]
 * @version 1.0
 * @date 2024-10-24
 */

#ifndef COLA_H
#define COLA_H

/**
 * @brief [COMPLETAR]
 */
typedef struct cola cola_t;

/**
 * @brief [COMPLETAR]
 * 
 * @return [COMPLETAR]
 * 
 * @pre [COMPLETAR]
 * @post [COMPLETAR]
 * 
 * @note [COMPLETAR]
 */
cola_t* cola_crear(void);

// [COMPLETAR DOCUMENTACIÓN DE TODAS LAS FUNCIONES]

#endif
```

### 12.2: README y Guía de Uso

Escribir un README completo para tu librería:

**Secciones a incluir:**
1. Descripción y propósito
2. Instalación
3. Quick start con ejemplo mínimo
4. Referencia completa de API
5. Ejemplos avanzados
6. FAQ
7. Changelog
8. Licencia

### 12.3: Documentación Inline

Agregar comentarios inline útiles (no obvios):

```c
// Malo: comentario obvio
i++;  // Incrementar i

// Bueno: explica decisión no obvia
// Usamos búsqueda lineal en lugar de binaria porque 
// el arreglo tiene < 10 elementos típicamente, y 
// benchmark muestra que es más rápido por overhead reducido
for (int i = 0; i < n; i++) {
    if (arr[i] == target) return i;
}

// Bueno: advierte sobre caso especial
// IMPORTANTE: buffer debe tener al menos MAX_PATH + 1 bytes
// para incluir el null terminator
obtener_ruta_absoluta(archivo, buffer);
```

## 13: Casos de Estudio

### 13.1: Análisis de API Real - `fopen`

Analizar el diseño de `fopen`:

```c
FILE* fopen(const char* filename, const char* mode);
```

**Preguntas:**
1. ¿Por qué retornar puntero opaco en lugar de estructura?
2. ¿Por qué `mode` es string y no enum?
3. ¿Cómo reporta errores?
4. ¿Es thread-safe?
5. ¿Qué ventajas tiene este diseño?
6. ¿Qué desventajas?
7. Si pudieras rediseñarla hoy, ¿qué cambiarías?

### 13.2: Análisis de API Real - `malloc`

Analizar el diseño de `malloc`:

```c
void* malloc(size_t size);
void free(void* ptr);
```

**Preguntas:**
1. ¿Por qué retornar `void*`?
2. ¿Por qué `free` no retorna código de error?
3. ¿Qué pasa si llamo `free(NULL)`?
4. ¿Por qué no hay `malloc_safe` que inicializa a cero?
5. Comparar con `calloc` y `realloc`

### 13.3: Rediseño de API Problemática

Esta API tiene varios problemas. Identificarlos y proponer mejoras:

```c
// api_problematica.h
struct datos {  // ¿Por qué no typedef?
    int* array;
    int size;
    int capacity;
};

void init(struct datos* d);  // ¿Malloc o no?
int add(struct datos* d, int x);  // ¿Qué significa el int retornado?
void process();  // ¿Dónde están los parámetros?
char* get_result();  // ¿Quién libera?
```

**Tareas:**
1. Listar todos los problemas
2. Proponer API mejorada
3. Justificar cada cambio

### 13.4: Comparación SQLite vs. MySQL

Comparar las APIs de estas dos librerías de base de datos:

**SQLite (todo en uno):**
```c
sqlite3* db;
sqlite3_open("db.sqlite", &db);
sqlite3_exec(db, "SELECT * FROM users", callback, NULL, NULL);
sqlite3_close(db);
```

**MySQL (orientada a objetos):**
```c
MYSQL* conn = mysql_init(NULL);
mysql_real_connect(conn, host, user, pass, db, 0, NULL, 0);
MYSQL_RES* result = mysql_query(conn, "SELECT * FROM users");
mysql_free_result(result);
mysql_close(conn);
```

**Análisis:**
- Ventajas y desventajas de cada estilo
- ¿Cuál es más fácil de usar?
- ¿Cuál es más flexible?
- ¿Cuál maneja errores mejor?

## 14: Ejercicios Integradores

### 14.1: Diseñar Librería Completa

Diseñar una librería completa de manejo de grafos con:

**Requisitos:**
1. Tipos opacos para grafos y nodos
2. Soporte para grafos dirigidos y no dirigidos
3. Operaciones básicas (agregar nodo, agregar arista, eliminar, buscar)
4. Algoritmos (BFS, DFS, camino más corto)
5. Manejo de errores consistente
6. Documentación completa
7. Tests unitarios

**Entregables:**
- `grafo.h` (interfaz pública)
- `grafo.c` (implementación)
- `test_grafo.c` (tests)
- `README.md` (documentación)

### 14.2: Refactorizar Código Legacy

Dado este código legacy, refactorizar aplicando todos los principios:

```c
// legacy_code.c
int data[MAX];
int count = 0;

void add(int x) {
    data[count++] = x;
}

int get(int i) {
    return data[i];
}

void print() {
    for (int i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
}
```

**Mejoras a implementar:**
- Tipo opaco
- Manejo de errores
- Chequeo de límites
- API clara y documentada
- Thread-safety opcional
- Tests

### 14.3: API REST en C

Diseñar una librería para cliente HTTP REST:

```c
typedef struct http_client http_client_t;
typedef struct http_response http_response_t;

// Crear cliente con configuración
http_client_t* http_client_crear(const char* base_url);
void http_client_set_timeout(http_client_t* client, int segundos);
void http_client_set_header(http_client_t* client, const char* clave, const char* valor);

// Operaciones REST
http_response_t* http_get(http_client_t* client, const char* endpoint);
http_response_t* http_post(http_client_t* client, const char* endpoint, const char* body);
http_response_t* http_put(http_client_t* client, const char* endpoint, const char* body);
http_response_t* http_delete(http_client_t* client, const char* endpoint);

// Acceso a respuesta
int http_response_get_status(const http_response_t* resp);
const char* http_response_get_body(const http_response_t* resp);
const char* http_response_get_header(const http_response_t* resp, const char* clave);

// Limpieza
void http_response_destruir(http_response_t* resp);
void http_client_destruir(http_client_t* client);
```

## 15: Preguntas Conceptuales

### 15.1: Filosofía de Diseño

**Pregunta:** ¿Cuál es mejor diseño y por qué?

**Opción A: Simple pero menos seguro**
```c
void buffer_append(buffer_t* buf, const char* str);
// Asume que buf != NULL, undefined behavior si no
```

**Opción B: Seguro pero más verboso**
```c
bool buffer_append(buffer_t* buf, const char* str) {
    if (buf == NULL || str == NULL) return false;
    // ...
    return true;
}
```

**Respuesta esperada:** Depende del contexto (librería pública vs. código interno, performance crítica vs. no, etc.)

### 15.2: Abstracción vs. Control

**Pregunta:** Una API de alto nivel es fácil de usar pero menos flexible. Una de bajo nivel es potente pero compleja. ¿Cómo resolver este trade-off?

**Respuesta esperada:** Múltiples niveles de API, como hace Git con porcelain/plumbing.

### 15.3: Estabilidad vs. Innovación

**Pregunta:** Mantener compatibilidad hacia atrás limita la evolución de la API. ¿Cómo balancear estabilidad e innovación?

**Respuestas esperadas:**
- Versionado mayor para cambios breaking
- Deprecación gradual
- Nuevas funciones con sufijos `_v2`
- Branches separadas (stable/experimental)

### 15.4: Zero-cost Abstraction

**Pregunta:** ¿Qué significa "zero-cost abstraction"? ¿Es posible en C?

**Respuesta esperada:** Abstracción que no agrega overhead en runtime. En C es posible mediante inline functions y macros.

### 15.5: Defensive Programming

**Pregunta:** ¿Hasta qué punto debe una función ser defensiva validando entrada?

**Contextos diferentes:**
- Librería pública expuesta a usuarios externos
- Código interno dentro de un mismo programa
- Función de performance crítica en un lazo

**Respuesta esperada:** Varía según contexto, documentar asunciones claramente.

## 16: Ejercicios de Código

### 16.1: Implementación Mínima

Implementar la versión más simple posible de:

```c
typedef struct map map_t;

map_t* map_crear(void);
bool map_insertar(map_t* m, const char* clave, int valor);
bool map_buscar(map_t* m, const char* clave, int* valor);
bool map_eliminar(map_t* m, const char* clave);
size_t map_tamano(const map_t* m);
void map_destruir(map_t** ptr_map);
```

**Requisitos mínimos:**
- Tipo opaco
- Manejo de errores básico
- Documentación de contratos
- No memory leaks

### 16.2: Macro Safety

Convertir estas macros inseguras en funciones inline seguras:

```c
// Macro insegura
#define MAX(a, b) ((a) > (b) ? (a) : (b))
// Problema: evalúa argumentos múltiples veces

// Función inline segura
static inline int max_int(int a, int b) {
    return (a > b) ? a : b;
}
```

**Ejercicio:** Hacer lo mismo para:
```c
#define SQUARE(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SWAP(a, b) { int tmp = a; a = b; b = tmp; }
```

### 16.3: Wrapper Generation

Crear un sistema de wrappers automáticos para logging:

```c
// Original
int funcion_original(int x, int y);

// Wrapper generado automáticamente
int funcion_original_logged(int x, int y) {
    LOG_ENTRADA("funcion_original", "x=%d, y=%d", x, y);
    int resultado = funcion_original(x, y);
    LOG_SALIDA("funcion_original", "resultado=%d", resultado);
    return resultado;
}
```

**Tarea:** Crear macros o scripts que generen estos wrappers.

## 17: Auditoría de API

### 17.1: Checklist de Revisión

Crear un checklist completo para revisar una API:

**Nomenclatura:**
- [ ] Todas las funciones tienen prefijo consistente
- [ ] Nombres descriptivos y claros
- [ ] Convención de nombres (snake_case)
- [ ] ...

**Contratos:**
- [ ] Todas las funciones públicas están documentadas
- [ ] Precondiciones especificadas
- [ ] Poscondiciones especificadas
- [ ] ...

**Errores:**
- [ ] Estrategia de errores consistente
- [ ] Códigos de error documentados
- [ ] ...

### 17.2: Revisión de Pares

Intercambiar código con un compañero y revisar mutuamente las APIs diseñadas, usando el checklist del ejercicio anterior.

## 18: Preguntas de Diseño

### 18.1: ¿Puntero o Valor?

Para cada caso, decidir si pasar/retornar por valor o por puntero:

```c
// Estructura pequeña (8 bytes)
typedef struct {
    int x;
    int y;
} punto_t;

// ¿Cuál es mejor?
void punto_trasladar_v1(punto_t p, int dx, int dy);    // Por valor
void punto_trasladar_v2(punto_t* p, int dx, int dy);   // Por puntero

// Estructura grande (>64 bytes)
typedef struct {
    char nombre[256];
    int datos[1000];
} registro_t;

// ¿Cuál es mejor?
void procesar_v1(registro_t reg);        // Por valor
void procesar_v2(const registro_t* reg); // Por puntero
```

### 18.2: ¿Callback o Polling?

Diseñar API para operaciones asíncronas: ¿usar callbacks o polling?

**Opción A: Callback**
```c
typedef void (*completado_callback_t)(void* contexto, int resultado);

void operacion_async(int param, completado_callback_t callback, void* contexto);
```

**Opción B: Polling**
```c
typedef struct operacion operacion_t;

operacion_t* operacion_iniciar(int param);
bool operacion_completada(const operacion_t* op);
int operacion_obtener_resultado(operacion_t* op);
```

**Análisis:** Ventajas y desventajas de cada enfoque.

### 18.3: ¿Mutable o Inmutable?

Comparar diseños mutables vs. inmutables:

```c
// Diseño mutable
typedef struct string string_t;

void string_append(string_t* str, const char* texto);
void string_mayuscula(string_t* str);

// Diseño inmutable
string_t* string_append(const string_t* str, const char* texto);
string_t* string_mayuscula(const string_t* str);
// Cada operación retorna nueva string, original sin modificar
```

**Pregunta:** ¿Cuál preferir y cuándo?

### 18.4: ¿Herencia o Composición?

Simular herencia vs. composición en C:

```c
// Herencia (via casting)
typedef struct {
    int tipo;  // "vtable" manual
} figura_t;

typedef struct {
    figura_t base;
    double radio;
} circulo_t;

// Composición
typedef struct {
    punto_t centro;
    double radio;
} circulo_v2_t;
```

## 19: Ejercicios Avanzados

### 19.1: Plugin System

Diseñar un sistema de plugins dinámicos:

```c
typedef struct plugin plugin_t;
typedef struct plugin_api plugin_api_t;

// API que el plugin debe implementar
struct plugin_api {
    const char* nombre;
    const char* version;
    bool (*inicializar)(void);
    void (*procesar)(void* datos);
    void (*finalizar)(void);
};

// Sistema de carga de plugins
plugin_t* plugin_cargar(const char* ruta_so);
const plugin_api_t* plugin_get_api(plugin_t* p);
void plugin_descargar(plugin_t* p);
```

### 19.2: Reflection System

Implementar un sistema básico de reflexión:

```c
// Metadatos de tipos
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_STRUCT
} tipo_id_t;

typedef struct {
    const char* nombre;
    tipo_id_t tipo;
    size_t offset;
    size_t tamano;
} campo_info_t;

typedef struct {
    const char* nombre_struct;
    size_t tamano_total;
    size_t num_campos;
    campo_info_t* campos;
} struct_info_t;

// Usar para serialización genérica
void serializar_struct(const void* instancia, const struct_info_t* info);
```

### 19.3: Expression Builder

Crear un DSL (Domain Specific Language) embebido para construir consultas:

```c
typedef struct query query_t;

// API fluida
query_t* query_from(const char* tabla);
query_t* query_where(query_t* q, const char* condicion);
query_t* query_order_by(query_t* q, const char* campo);
query_t* query_limit(query_t* q, int limite);

char* query_to_sql(query_t* q);  // Genera SQL

// Uso:
query_t* q = query_from("usuarios")
    ->where("edad > 18")
    ->order_by("nombre")
    ->limit(10);

char* sql = query_to_sql(q);
// SELECT * FROM usuarios WHERE edad > 18 ORDER BY nombre LIMIT 10
```

## 20: Documentación de Decisiones

### 20.1: Architecture Decision Records

Documentar una decisión de diseño importante:

```markdown
# ADR-001: Usar Tipo Opaco para Stack

## Estado
Aceptado

## Contexto
Necesitamos decidir si exponer la estructura interna del stack
o usar tipo opaco.

## Decisión
Usaremos tipo opaco completo con puntero a estructura incompleta.

## Consecuencias
### Positivo
- Permite cambiar implementación sin romper ABI
- Previene acceso directo a miembros
- Fuerza uso correcto de la API

### Negativo
- Requiere heap allocation (no puede ser stack-local)
- Indirección adicional en cada operación
- Tamaño del struct desconocido para el usuario
```

**Tarea:** Crear ADRs para decisiones en tus propias librerías.

### 20.2: Changelog Profesional

Escribir un changelog siguiendo convenciones:

```markdown
# Changelog

## [2.0.0] - 2024-10-24

### Breaking Changes
- Cambiado tipo de retorno de `lista_buscar` de int a bool
- Removida función deprecada `lista_add` (usar `lista_agregar`)

### Added
- Nueva función `lista_insertar_ordenado`
- Soporte para iteradores

### Fixed
- Corregido memory leak en `lista_destruir`
- Bug #42: crash con listas vacías

### Deprecated
- `lista_append` está deprecada, usar `lista_agregar_al_final`
```

## 21-25: Casos Prácticos Complejos

### 21.1: Librería de Compresión

Diseñar API completa para compresión/descompresión:
- Múltiples algoritmos (gzip, bzip2, lz4)
- Streaming y block modes
- Configuración de nivel de compresión
- Callbacks para progreso
- Manejo de errores robusto

### 21.2: Motor de Expresiones Regulares

Diseñar API para regex:
- Compilación de patrones
- Búsqueda y matching
- Grupos de captura
- Reemplazo
- Flags (case-insensitive, multiline, etc.)

### 21.3: Sistema de Logging Multinivel

Diseñar sistema completo de logging:
- Múltiples niveles (DEBUG, INFO, WARN, ERROR)
- Múltiples destinos (archivo, syslog, callback)
- Rotación de logs
- Formato configurable
- Thread-safe

### 21.4: Pool de Conexiones

Diseñar un pool de conexiones reutilizables:
- Límite de conexiones concurrentes
- Timeout y reciclaje
- Health checking
- Estadísticas de uso
- Thread-safe

### 21.5: Máquina de Estados

Diseñar API para definir y ejecutar máquinas de estados finitas:
- Definición declarativa de estados y transiciones
- Callbacks para entrar/salir de estados
- Validación de transiciones
- Serialización del estado actual
- Debugging visual

---

:::{tip} Aplicación Práctica
Estos ejercicios están diseñados para ser progresivos. Comenzá con los fundamentos (nomenclatura, tipos opacos) y avanzá hacia diseños más complejos. Cada ejercicio refuerza los principios de {ref}`api-claridad`, {ref}`api-sorpresa` y las reglas de estilo del curso.
:::

