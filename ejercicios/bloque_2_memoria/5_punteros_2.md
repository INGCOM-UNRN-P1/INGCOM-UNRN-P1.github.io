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
