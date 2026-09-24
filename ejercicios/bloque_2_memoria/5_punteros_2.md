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
- {ref}`introduccion_aritmetica_punteros`

### Prerrequisitos Conceptuales
Antes de abordar estos ejercicios, el estudiante debe dominar:
1. Ciclo de vida dinámico en Heap (`malloc`, `calloc`, `realloc`, `free`) ({ref}`capitulo-memoria-dinamica`).
2. Punteros simples y dobles (`T *`, `T **`) para pasaje por referencia y modificación de punteros ({ref}`capitulo-punteros`).
3. Estructuras de datos heterogéneas (`struct`, `typedef`) ({ref}`capitulo-estructuras`).
4. Duplicación profunda (*deep copy*) versus copia superficial (*shallow copy*).
5. Protocolos de limpieza simétrica y prevención de fugas ante fallas de asignación intermedia (*rollback*).

### Cuestiones de Estilo Aplicables
- **Manejo seguro de punteros:** Es mandatorio liberar en el orden inverso a la
  asignación (de adentro hacia afuera) y establecer los punteros en `NULL` tras
  su liberación para prevenir dangling pointers (ver {ref}`0x3002h`).
- **Verificación de malloc:** Siempre se debe validar el resultado de las
  llamadas a `malloc`, `calloc` y `realloc` antes de realizar operaciones de
  lectura o escritura.

---

## Estructuras con Punteros

(ej_b2_c06_01)=
### Ejercicio 2.06.01 - Creación y Destrucción de Persona ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c06_01_persona_lifecycle

Implementá un constructor y destructor defensivo para la estructura `persona_t`:

```c
typedef struct {
    char *nombre;
    char *apellido;
    int edad;
} persona_t;

persona_t *persona_crear(const char *nombre, const char *apellido, int edad);
void persona_destruir(persona_t **ptr_persona);
```

**Requisitos:**
- Si `nombre` o `apellido` son nulos, o `edad < 0`, retornar `NULL`.
- Manejar fallos de `malloc` en cualquier etapa, liberando memoria asignada previamente (rollback total).
- El destructor debe liberar campos internos, liberar la estructura y colocar el puntero original en `NULL`.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Parámetros Entrada | Retorno Esperado | Post-Condición Destructor |
| :--- | :--- | :--- | :--- |
| Creación válida | `"Alan", "Turing", 41` | Puntero no nulo | `*ptr_persona == NULL` |
| Nombre nulo | `NULL, "Turing", 30` | `NULL` | N/A |
| Apellido nulo | `"Alan", NULL, 30` | `NULL` | N/A |
| Edad negativa | `"Alan", "Turing", -1` | `NULL` | N/A |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    char *nombre;
    char *apellido;
    int edad;
} persona_t;

persona_t *persona_crear(const char *nombre, const char *apellido, int edad) {
    if (nombre == NULL || apellido == NULL || edad < 0) {
        return NULL;
    }

    persona_t *p = (persona_t *)malloc(sizeof(persona_t));
    if (p == NULL) {
        return NULL;
    }

    p->nombre = (char *)malloc(strlen(nombre) + 1);
    if (p->nombre == NULL) {
        free(p);
        return NULL;
    }
    strcpy(p->nombre, nombre);

    p->apellido = (char *)malloc(strlen(apellido) + 1);
    if (p->apellido == NULL) {
        free(p->nombre);
        free(p);
        return NULL;
    }
    strcpy(p->apellido, apellido);

    p->edad = edad;
    return p;
}

void persona_destruir(persona_t **ptr_persona) {
    if (ptr_persona == NULL || *ptr_persona == NULL) {
        return;
    }
    persona_t *p = *ptr_persona;
    free(p->nombre);
    free(p->apellido);
    free(p);
    *ptr_persona = NULL;
}

int main(void) {
    persona_t *p = persona_crear("Alan", "Turing", 41);
    assert(p != NULL);
    assert(strcmp(p->nombre, "Alan") == 0);
    assert(strcmp(p->apellido, "Turing") == 0);
    assert(p->edad == 41);

    persona_destruir(&p);
    assert(p == NULL);

    /* Casos defensivos */
    assert(persona_crear(NULL, "Turing", 30) == NULL);
    assert(persona_crear("Alan", NULL, 30) == NULL);
    assert(persona_crear("Alan", "Turing", -1) == NULL);

    persona_destruir(&p);
    persona_destruir(NULL);

    return 0;
}
```
::::
:::

(ej_b2_c06_03)=
### Ejercicio 2.06.03 - Clonación Profunda ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c06_03_clonacion_profunda

Implementá una función que cree una copia completamente independiente de una
persona:

```c
persona_t *persona_clonar(const persona_t *original);
```

La copia debe tener su propia memoria asignada para `nombre` y `apellido`, sin
compartir punteros con el original.

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    char *nombre;
    char *apellido;
    int edad;
} persona_t;

persona_t *persona_crear(const char *nombre, const char *apellido, int edad) {
    if (nombre == NULL || apellido == NULL || edad < 0) return NULL;
    persona_t *p = (persona_t *)malloc(sizeof(persona_t));
    if (p == NULL) return NULL;
    p->nombre = (char *)malloc(strlen(nombre) + 1);
    if (p->nombre == NULL) { free(p); return NULL; }
    strcpy(p->nombre, nombre);
    p->apellido = (char *)malloc(strlen(apellido) + 1);
    if (p->apellido == NULL) { free(p->nombre); free(p); return NULL; }
    strcpy(p->apellido, apellido);
    p->edad = edad;
    return p;
}

void persona_destruir(persona_t **ptr_persona) {
    if (ptr_persona == NULL || *ptr_persona == NULL) return;
    free((*ptr_persona)->nombre);
    free((*ptr_persona)->apellido);
    free(*ptr_persona);
    *ptr_persona = NULL;
}

persona_t *persona_clonar(const persona_t *original) {
    if (original == NULL) {
        return NULL;
    }
    return persona_crear(original->nombre, original->apellido, original->edad);
}

int main(void) {
    persona_t *p1 = persona_crear("Ada", "Lovelace", 36);
    assert(p1 != NULL);

    persona_t *p2 = persona_clonar(p1);
    assert(p2 != NULL);
    assert(p2 != p1);
    assert(p2->nombre != p1->nombre);
    assert(p2->apellido != p1->apellido);
    assert(strcmp(p2->nombre, p1->nombre) == 0);
    assert(strcmp(p2->apellido, p1->apellido) == 0);
    assert(p2->edad == p1->edad);

    persona_destruir(&p1);
    assert(p1 == NULL);

    /* p2 debe seguir intacto tras la destrucción de p1 */
    assert(strcmp(p2->nombre, "Ada") == 0);
    persona_destruir(&p2);
    assert(p2 == NULL);

    assert(persona_clonar(NULL) == NULL);

    return 0;
}
```
::::
:::

(ej_b2_c06_04)=
### Ejercicio 2.06.04 - Estructura con Múltiples Niveles ⭐⭐⭐☆☆

Implementar constructor y destructor para esta estructura anidada:

```{code-block} c
:linenos:
typedef struct
{
    char *calle;
    char *ciudad;
    int codigo_postal;
} direccion_t;
typedef struct
{
    char *nombre;
    direccion_t *direccion;
    char **telefonos; // Array de cadenas
    size_t n_telefonos;
} contacto_t;
contacto_t *contacto_crear(const char *nombre, const char *calle,
                           const char *ciudad, int codigo_postal);
void contacto_destruir(contacto_t **ptr_contacto);
```
<!-- {code-block} c -->

**Desafío:** Manejar correctamente tres niveles de asignación: la estructura
principal, la dirección anidada, y el array dinámico de cadenas.

---

## Manejo de Errores en Cadena

(ej_b2_c06_05)=
### Ejercicio 2.06.05 - Rollback Completo ⭐⭐☆☆☆

Escribir una función que asigne memoria para una estructura de estudiante con
cursos:

```{code-block} c
:linenos:
typedef struct
{
    char *nombre;
    char **cursos;
    int *notas;
    size_t n_cursos;
} estudiante_t;
```
<!-- {code-block} c -->

Si la asignación de `notas` falla después de haber asignado `nombre` y `cursos`,
la función debe liberar `nombre` y `cursos` antes de retornar `NULL` para evitar
fugas de memoria.

(ej_b2_c06_06)=
### Ejercicio 2.06.06 - Alternativa con Goto ⭐⭐☆☆☆

Implementar la función del ejercicio anterior estructurando la liberación de
recursos en una sección de limpieza al final de la función mediante `goto`, como
se describe en las buenas prácticas de la cátedra.

---

## Matrices Dinámicas

(ej_b2_c06_07)=
### Ejercicio 2.06.07 - Matriz Dentada (Array de Punteros) ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c06_07_matriz_dentada

Implementá funciones para crear y liberar una matriz dentada donde cada fila se
aloja como un bloque independiente:

```c
int **crear_matriz_dentada(size_t filas, size_t columnas);
void liberar_matriz_dentada(int ***ptr_matriz, size_t filas);
```

**Requisitos:**
- Si `filas == 0` o `columnas == 0`, retornar `NULL`.
- En caso de fallo de `malloc` en una fila intermedia, liberar las filas previas y el array de punteros (*rollback* completo).
- `liberar_matriz_dentada` debe poner el puntero original en `NULL`.

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **crear_matriz_dentada(size_t filas, size_t columnas) {
    if (filas == 0 || columnas == 0) {
        return NULL;
    }

    int **m = (int **)malloc(filas * sizeof(int *));
    if (m == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < filas; ++i) {
        m[i] = (int *)malloc(columnas * sizeof(int));
        if (m[i] == NULL) {
            /* Rollback de filas previas */
            for (size_t j = 0; j < i; ++j) {
                free(m[j]);
            }
            free(m);
            return NULL;
        }
    }
    return m;
}

void liberar_matriz_dentada(int ***ptr_matriz, size_t filas) {
    if (ptr_matriz == NULL || *ptr_matriz == NULL) {
        return;
    }
    int **m = *ptr_matriz;
    for (size_t i = 0; i < filas; ++i) {
        free(m[i]);
    }
    free(m);
    *ptr_matriz = NULL;
}

int main(void) {
    size_t filas = 3;
    size_t cols = 4;
    int **m = crear_matriz_dentada(filas, cols);
    assert(m != NULL);

    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            m[i][j] = (int)(i * 10 + j);
        }
    }

    assert(m[0][0] == 0);
    assert(m[1][2] == 12);
    assert(m[2][3] == 23);

    liberar_matriz_dentada(&m, filas);
    assert(m == NULL);

    /* Casos límite */
    assert(crear_matriz_dentada(0, 5) == NULL);
    assert(crear_matriz_dentada(5, 0) == NULL);
    liberar_matriz_dentada(&m, 0);
    liberar_matriz_dentada(NULL, 5);

    return 0;
}
```
::::
:::

(ej_b2_c06_08)=
### Ejercicio 2.06.08 - Matriz de Bloque Único (Contigua) ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c06_08_matriz_contigua

Implementá funciones para crear y liberar una matriz contigua en memoria,
reservando un bloque único para los datos y configurando el array de punteros a filas:

```c
int **crear_matriz_contigua(size_t filas, size_t columnas);
void liberar_matriz_contigua(int ***ptr_matriz);
```

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **crear_matriz_contigua(size_t filas, size_t columnas) {
    if (filas == 0 || columnas == 0) {
        return NULL;
    }

    int **m = (int **)malloc(filas * sizeof(int *));
    if (m == NULL) {
        return NULL;
    }

    int *datos = (int *)malloc(filas * columnas * sizeof(int));
    if (datos == NULL) {
        free(m);
        return NULL;
    }

    for (size_t i = 0; i < filas; ++i) {
        m[i] = datos + (i * columnas);
    }
    return m;
}

void liberar_matriz_contigua(int ***ptr_matriz) {
    if (ptr_matriz == NULL || *ptr_matriz == NULL) {
        return;
    }
    int **m = *ptr_matriz;
    /* Liberar bloque de datos contiguo indexado en fila 0 */
    free(m[0]);
    /* Liberar arreglo de punteros */
    free(m);
    *ptr_matriz = NULL;
}

int main(void) {
    size_t filas = 4;
    size_t cols = 5;
    int **m = crear_matriz_contigua(filas, cols);
    assert(m != NULL);

    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            m[i][j] = (int)(i + j);
        }
    }

    assert(m[0][0] == 0);
    assert(m[3][4] == 7);
    /* Verificar contigüidad en memoria: m[1][0] debe ser m[0][0] + cols */
    assert(&m[1][0] == &m[0][cols]);

    liberar_matriz_contigua(&m);
    assert(m == NULL);

    assert(crear_matriz_contigua(0, 5) == NULL);
    assert(crear_matriz_contigua(5, 0) == NULL);
    liberar_matriz_contigua(NULL);

    return 0;
}
```
::::
:::

(ej_b2_c06_09)=
### Ejercicio 2.06.09 - Conversión de Array Plano a Matriz ⭐⭐⭐☆☆

Implementar una función que reciba un arreglo plano (`int*`) de tamaño $N \times
M$ y retorne una estructura de punteros a filas (`int**`) que permita acceder al
mismo usando la notación `matriz[i][j]`.

---

## Optimización y Casos Prácticos

(ej_b2_c06_10)=
### Ejercicio 2.06.10 - Vector Dinámico Redimensionable con Crecimiento Seguro ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c06_10_vector_dinamico
:enumerator: punteros2-10

Implementá una estructura de datos `vector_dinamico_t` que gestione un búfer continuo de enteros en el Heap, duplicando su capacidad de manera segura cuando se sature:

```c
typedef struct {
    int *datos;
    size_t cantidad;
    size_t capacidad;
} vector_dinamico_t;

vector_dinamico_t *vector_crear(size_t capacidad_inicial);
bool vector_agregar(vector_dinamico_t *v, int elemento);
bool vector_obtener(const vector_dinamico_t *v, size_t indice, int *salida);
void vector_destruir(vector_dinamico_t *v);
```

**Reglas de gestión de memoria y contratos:**
1. **Inicialización:** `vector_crear` debe asignar tanto la cabecera como el búfer subyacente. Si `capacidad_inicial == 0`, se asigna por defecto una capacidad inicial mínima de 4 elementos.
2. **Crecimiento geométrico seguro:** Cuando `cantidad == capacidad`, `vector_agregar` debe redimensionar al doble (`capacidad * 2`) usando obligatoriamente un puntero temporal intermedio para capturar el retorno de `realloc`. Si `realloc` falla, el vector debe conservar sus datos previos intactos y retornar `false`.
3. **Acceso indexado:** `vector_obtener` debe verificar que `indice < cantidad`. Si es válido, almacena el valor en `*salida` y retorna `true`; ante accesos fuera de rango o punteros nulos, retorna `false`.
4. **Destrucción limpia:** `vector_destruir` debe liberar el búfer `datos` y luego la estructura principal, tolerando llamadas defensivas con `NULL`.

#### Tabla de Vectores de Prueba Obligatorios

| Operación / Secuencia | Estado Inicial $(N / C)$ | Elemento | Retorno | Estado Final $(N / C)$ | Justificación |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `vector_crear(2)` | - | - | Válido | `0 / 2` | Reserva inicial de 2 slots |
| `vector_agregar(10)` | `0 / 2` | `10` | `true` | `1 / 2` | Inserción sin reasignación |
| `vector_agregar(20)` | `1 / 2` | `20` | `true` | `2 / 2` | Saturación del búfer inicial |
| `vector_agregar(30)` | `2 / 2` | `30` | `true` | `3 / 4` | Crecimiento geométrico al doble |
| `vector_obtener(1)` | `3 / 4` | `idx=1` | `true` (`*salida=20`) | Inalterado | Lectura indexada válida |
| `vector_obtener(5)` | `3 / 4` | `idx=5` | `false` | Inalterado | Rechazo defensivo fuera de rango |

:::

::::{solution} ej_b2_c06_10_vector_dinamico
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int *datos;
    size_t cantidad;
    size_t capacidad;
} vector_dinamico_t;

#define VECTOR_CAPACIDAD_DEFECTO 4

vector_dinamico_t *vector_crear(size_t capacidad_inicial)
{
    if (capacidad_inicial == 0)
    {
        capacidad_inicial = VECTOR_CAPACIDAD_DEFECTO;
    }

    vector_dinamico_t *v = (vector_dinamico_t *)malloc(sizeof(vector_dinamico_t));
    if (v == NULL)
    {
        return NULL;
    }

    v->datos = (int *)malloc(capacidad_inicial * sizeof(int));
    if (v->datos == NULL)
    {
        free(v);
        return NULL;
    }

    v->cantidad = 0;
    v->capacidad = capacidad_inicial;
    return v;
}

bool vector_agregar(vector_dinamico_t *v, int elemento)
{
    if (v == NULL)
    {
        return false;
    }

    if (v->cantidad >= v->capacidad)
    {
        size_t nueva_cap = v->capacidad * 2;
        int *temporal = (int *)realloc(v->datos, nueva_cap * sizeof(int));
        if (temporal == NULL)
        {
            return false;
        }
        v->datos = temporal;
        v->capacidad = nueva_cap;
    }

    v->datos[v->cantidad++] = elemento;
    return true;
}

bool vector_obtener(const vector_dinamico_t *v, size_t indice, int *salida)
{
    if (v == NULL || salida == NULL || indice >= v->cantidad)
    {
        return false;
    }

    *salida = v->datos[indice];
    return true;
}

void vector_destruir(vector_dinamico_t *v)
{
    if (v == NULL)
    {
        return;
    }

    free(v->datos);
    free(v);
}

int main(void)
{
    vector_dinamico_t *v = vector_crear(2);
    assert(v != NULL);
    assert(v->cantidad == 0);
    assert(v->capacidad == 2);

    /* Inserciones y crecimiento */
    assert(vector_agregar(v, 10) == true);
    assert(vector_agregar(v, 20) == true);
    assert(v->cantidad == 2 && v->capacidad == 2);

    /* Forzar realloc a 4 */
    assert(vector_agregar(v, 30) == true);
    assert(v->cantidad == 3 && v->capacidad == 4);

    /* Lecturas indexadas */
    int leido = 0;
    assert(vector_obtener(v, 0, &leido) == true && leido == 10);
    assert(vector_obtener(v, 1, &leido) == true && leido == 20);
    assert(vector_obtener(v, 2, &leido) == true && leido == 30);

    /* Fuera de rango */
    assert(vector_obtener(v, 3, &leido) == false);
    assert(vector_obtener(v, 99, &leido) == false);
    assert(vector_obtener(v, 0, NULL) == false);

    /* Crecimiento continuo */
    assert(vector_agregar(v, 40) == true);
    assert(vector_agregar(v, 50) == true);
    assert(v->cantidad == 5 && v->capacidad == 8);

    vector_destruir(v);
    vector_destruir(NULL);

    /* Capacidad inicial 0 -> defecto */
    vector_dinamico_t *v_def = vector_crear(0);
    assert(v_def != NULL && v_def->capacidad == VECTOR_CAPACIDAD_DEFECTO);
    vector_destruir(v_def);

    return 0;
}
```

::::
<!-- {solution} ej_b2_c06_10_vector_dinamico -->


(ej_b2_c06_11)=
### Ejercicio 2.06.11 - Reducción Dinámica de Capacidad (Shrinking) ⭐⭐⭐☆☆

Modificar el vector del ejercicio anterior para reducir su capacidad a la mitad
si la cantidad de elementos en uso cae por debajo de 1/4 de su capacidad máxima.

(ej_b2_c06_12)=
### Ejercicio 2.06.12 - Gestión de Memoria en el Parser JSON ⭐⭐☆☆☆

Diseñar las funciones de reserva y liberación para un nodo AST de un parser JSON
que representa objetos y arreglos anidados mediante punteros dinámicos.

(ej_b2_c06_13)=
### Ejercicio 2.06.13 - Heap Buffer Overflow ⭐⭐☆☆☆

Escribir un fragmento de código que produzca un desbordamiento de búfer en el
Heap y explicar cómo AddressSanitizer reporta dicho error.

(ej_b2_c06_14)=
## Ejercicio 2.06.14 - Matriz Dinámica Dentada ⭐⭐☆☆☆

Creá matriz donde cada fila tiene diferente cantidad de columnas.

**Orientación:**

```{code-block} c
:linenos:
int filas = 3;
int cols[] = {2, 4, 3};
int **matriz = malloc(filas * sizeof(int *));
for (int i = 0; i < filas; i++)
{
    matriz[i] = malloc(cols[i] * sizeof(int));
}
```
<!-- {code-block} c -->
- Liberación: cada fila primero, luego array de punteros

---

(ej_b2_c06_15)=
## Ejercicio 2.06.15 - Matriz Dinámica en Bloque ⭐⭐⭐☆☆

Creá matriz contigua en memoria (un solo `malloc` para datos).

**Orientación:**

```{code-block} c
:linenos:
int **crear_matriz(int filas, int cols)
{
    int **matriz = malloc(filas * sizeof(int *));
    int *datos = malloc(filas * cols * sizeof(int));
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = datos + i * cols;
    }
    return matriz;
}
```
<!-- {code-block} c -->
- Ventaja: mejor localidad de caché
- Liberación: liberar datos, luego array de punteros

---

(ej_b2_c06_16)=
## Ejercicio 2.06.16 - Matriz con Cast (ALV) ⭐⭐⭐☆☆

Implementá acceso a matriz unidimensional como bidimensional.

**Orientación:**

``` c
int *matriz = malloc(filas * cols * sizeof(int));
// Acceso: matriz[i * cols + j]
// O macro:
#define MAT(m, i, j, cols) ((m)[(i) * (cols) + (j)])
MAT(matriz, 2, 3, cols) = 42;
```
<!-- c -->
- Un solo `malloc` y `free`
- Menos flexible pero más eficiente

---

(ej_b2_c06_17)=
## Ejercicio 2.06.17 - Redimensionar Array Dinámico ⭐⭐⭐☆☆

Implementá función para redimensionar array preservando datos.

**Orientación:**

```{code-block} c
:linenos:
int *redimensionar(int *arr, int tam_actual, int tam_nuevo)
{
    int *nuevo = realloc(arr, tam_nuevo * sizeof(int));
    if (nuevo == NULL)
    {
        // Manejar error, NO liberar arr
        return NULL;
    }
    // Si tam_nuevo > tam_actual, nuevos elementos sin inicializar
    return nuevo;
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_18)=
## Ejercicio 2.06.18 - Array de Strings Dinámico ⭐⭐⭐☆☆

Creá array dinámico de strings donde cada string también es dinámico.

**Orientación:**

```{code-block} c
:linenos:
char **strings = malloc(n * sizeof(char *));
for (int i = 0; i < n; i++)
{
    strings[i] = malloc((strlen(input) + 1) * sizeof(char));
    strcpy(strings[i], input);
}
// Liberación:
for (int i = 0; i < n; i++)
{
    free(strings[i]);
}
free(strings);
```
<!-- {code-block} c -->

---

(ej_b2_c06_19)=
## Ejercicio 2.06.19 - Estructura con Arrays Dinámicos ⭐⭐⭐☆☆

Creá estructura que contenga arrays dinámicos.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    int *datos;
    size_t tamanio;
    size_t capacidad;
} vector_t;
vector_t *crear_vector(size_t cap_inicial)
{
    vector_t *v = malloc(sizeof(vector_t));
    v->datos = malloc(cap_inicial * sizeof(int));
    v->tamanio = 0;
    v->capacidad = cap_inicial;
    return v;
}
void destruir_vector(vector_t *v)
{
    free(v->datos); // Primero datos
    free(v);        // Luego estructura
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_20)=
## Ejercicio 2.06.20 - Lista Enlazada con Strings ⭐⭐⭐⭐☆

Implementá lista donde cada nodo contiene un string dinámico.

**Orientación:**

```{code-block} c
:linenos:
typedef struct nodo
{
    char *str; // String dinámico
    struct nodo *siguiente;
} nodo_t;
nodo_t *crear_nodo(const char *str)
{
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    nuevo->str = malloc(strlen(str) + 1);
    strcpy(nuevo->str, str);
    nuevo->siguiente = NULL;
    return nuevo;
}
void liberar_nodo(nodo_t *nodo)
{
    free(nodo->str); // Primero el string
    free(nodo);      // Luego el nodo
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_21)=
## Ejercicio 2.06.21 - Estructura Jerárquica de Categorías con Memoria Dinámica ⭐⭐⭐⭐⭐

Implementá una estructura de categorías donde cada categoría contiene un arreglo dinámico de subcategorías y un nombre dinámico:

**Orientación:**

```{code-block} c
:linenos:
typedef struct categoria
{
    char *nombre;
    struct categoria **hijos;
    size_t num_hijos;
} categoria_t;

categoria_t *crear_categoria(const char *nombre)
{
    categoria_t *c = malloc(sizeof(categoria_t));
    c->nombre = strdup(nombre);
    c->hijos = NULL;
    c->num_hijos = 0;
    return c;
}

void liberar_categoria(categoria_t *c)
{
    if (c == NULL)
    {
        return;
    }
    for (size_t i = 0; i < c->num_hijos; i++)
    {
        liberar_categoria(c->hijos[i]);
    }
    free(c->hijos);
    free(c->nombre);
    free(c);
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_22)=
## Ejercicio 2.06.22 - Matriz Triangular ⭐⭐⭐⭐☆

Implementá matriz triangular inferior (solo almacená elementos <= diagonal).

**Orientación:**
- Fila i tiene i+1 elementos
- Total elementos: n(n+1)/2

``` c
int **matriz = malloc(n * sizeof(int *));
for (int i = 0; i < n; i++)
{
    matriz[i] = malloc((i + 1) * sizeof(int));
}
```
<!-- c -->

---

(ej_b2_c06_23)=
## Ejercicio 2.06.23 - Copiar Estructura Profunda ⭐⭐⭐⭐☆

Implementá copia profunda de estructura con punteros.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    char *nombre;
    int *calificaciones;
    size_t num_calificaciones;
} estudiante_t;
estudiante_t *copiar(const estudiante_t *orig)
{
    estudiante_t *copia = malloc(sizeof(estudiante_t));
    copia->nombre = strdup(orig->nombre); // O malloc+strcpy
    copia->num_calificaciones = orig->num_calificaciones;
    copia->calificaciones = malloc(orig->num_calificaciones * sizeof(int));
    memcpy(copia->calificaciones, orig->calificaciones,
           orig->num_calificaciones * sizeof(int));
    return copia;
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_24)=
## Ejercicio 2.06.24 - Matriz Dinámica de Conectividad NxN ⭐⭐⭐⭐⭐

Creá una matriz bidimensional dinámica booleana/entera para registrar conexiones entre $N$ elementos.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    int **matriz; // Matriz NxN
    int dimension;
} red_conexiones_t;

red_conexiones_t *crear_red(int n)
{
    red_conexiones_t *r = malloc(sizeof(red_conexiones_t));
    r->dimension = n;
    r->matriz = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        r->matriz[i] = calloc(n, sizeof(int)); // Inicializado a 0
    }
    return r;
}

void liberar_red(red_conexiones_t *r)
{
    for (int i = 0; i < r->dimension; i++)
    {
        free(r->matriz[i]);
    }
    free(r->matriz);
    free(r);
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_25)=
## Ejercicio 2.06.25 - Array de Estructuras con Punteros ⭐⭐⭐⭐☆

Creá array dinámico de estructuras que contienen punteros.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    char *titulo;
    int *capitulos;
    int num_caps;
} libro_t;
libro_t *libros = malloc(n * sizeof(libro_t));
// Liberación compleja: cada campo de cada estructura
for (int i = 0; i < n; i++)
{
    free(libros[i].titulo);
    free(libros[i].capitulos);
}
free(libros);
```
<!-- {code-block} c -->

---

(ej_b2_c06_26)=
## Ejercicio 2.06.26 - Tabla de Registros con Redimensionamiento Dinámico ⭐⭐⭐⭐⭐

Implementá un contenedor indexado de punteros a estructuras con redimensionamiento dinámico cuando la capacidad se agote.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    char *clave;
    int valor;
} registro_t;

typedef struct
{
    registro_t **items;
    size_t capacidad;
    size_t num_elementos;
} tabla_registros_t;

void redimensionar_tabla(tabla_registros_t *t)
{
    size_t nueva_cap = t->capacidad * 2;
    registro_t **nuevos = realloc(t->items, nueva_cap * sizeof(registro_t *));
    if (nuevos != NULL)
    {
        t->items = nuevos;
        t->capacidad = nueva_cap;
    }
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_27)=
## Ejercicio 2.06.27 - Matriz Dispersa (Sparse Matrix) ⭐⭐⭐⭐⭐

Implementá matriz dispersa con lista de triplas (fila, col, valor).

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    int fila, col;
    double valor;
} tripla_t;
typedef struct
{
    tripla_t *elementos;
    size_t num_elementos;
    size_t capacidad;
    int filas, cols;
} matriz_dispersa_t;
```
<!-- {code-block} c -->
- Solo almacená elementos != 0
- Búsqueda lineal o binaria para acceso

---

(ej_b2_c06_28)=
## Ejercicio 2.06.28 - Buffer Circular Dinámico ⭐⭐⭐⭐⭐

Implementá buffer circular con redimensionamiento.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    void **datos;
    size_t capacidad;
    size_t inicio, fin;
    size_t tamanio;
} buffer_circular_t;
void redimensionar_buffer(buffer_circular_t *b)
{
    size_t nueva_cap = b->capacidad * 2;
    void **nuevo = malloc(nueva_cap * sizeof(void *));
    // Copiar elementos en orden
    size_t idx = b->inicio;
    for (size_t i = 0; i < b->tamanio; i++)
    {
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
<!-- {code-block} c -->

---

(ej_b2_c06_29)=
## Ejercicio 2.06.29 - Punteros a Punteros para Modificar ⭐⭐⭐⭐☆

Implementá función que modifica puntero pasado como argumento.

**Orientación:**

```{code-block} c
:linenos:
void insertar_inicio(nodo_t **cabeza, int valor)
{
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo; // Modifica el puntero original
}
// Uso:
nodo_t *lista = NULL;
insertar_inicio(&lista, 42); // Pasa dirección del puntero
```
<!-- {code-block} c -->

---

(ej_b2_c06_30)=
## Ejercicio 2.06.30 - Array 3D Dinámico ⭐⭐⭐⭐⭐

Creá array tridimensional dinámico.

**Orientación:**

```{code-block} c
:linenos:
int ***crear_array_3d(int x, int y, int z)
{
    int ***arr = malloc(x * sizeof(int **));
    for (int i = 0; i < x; i++)
    {
        arr[i] = malloc(y * sizeof(int *));
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = malloc(z * sizeof(int));
        }
    }
    return arr;
}
void liberar_array_3d(int ***arr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            free(arr[i][j]); // Nivel más profundo primero
        }
        free(arr[i]);
    }
    free(arr);
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_31)=
## Ejercicio 2.06.31 - Pool de Objetos ⭐⭐⭐⭐⭐

Implementá pool de objetos para evitar malloc/free frecuentes.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    void *bloques;
    size_t tam_objeto;
    size_t capacidad;
    void **libres; // Stack de objetos libres
    size_t num_libres;
} pool_t;
void *pool_alloc(pool_t *p)
{
    if (p->num_libres == 0)
        return NULL;
    return p->libres[--p->num_libres];
}
void pool_free(pool_t *p, void *obj)
{
    p->libres[p->num_libres++] = obj;
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_32)=
## Ejercicio 2.06.32 - Reference Counting ⭐⭐⭐⭐⭐

Implementá sistema de conteo de referencias para compartir datos.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    void *datos;
    size_t contador_refs;
} ref_counted_t;
ref_counted_t *crear_ref(void *datos)
{
    ref_counted_t *r = malloc(sizeof(ref_counted_t));
    r->datos = datos;
    r->contador_refs = 1;
    return r;
}
void incrementar_ref(ref_counted_t *r)
{
    r->contador_refs++;
}
void decrementar_ref(ref_counted_t *r, void (*destruir)(void *))
{
    if (--r->contador_refs == 0)
    {
        destruir(r->datos);
        free(r);
    }
}
```
<!-- {code-block} c -->

---

(ej_b2_c06_33)=
## Ejercicio 2.06.33 - Sistema de Memoria con Debug ⭐⭐⭐⭐⭐

Implementá wrapper de malloc/free que registre asignaciones.

**Orientación:**

```{code-block} c
:linenos:
typedef struct
{
    void *ptr;
    size_t tamanio;
    const char *archivo;
    int linea;
} alloc_info_t;
#define MALLOC_DEBUG(size) malloc_debug(size, __FILE__, __LINE__)
#define FREE_DEBUG(ptr) free_debug(ptr, __FILE__, __LINE__)
void *malloc_debug(size_t size, const char *file, int line)
{
    void *ptr = malloc(size);
    // Registrar en tabla de asignaciones
    return ptr;
}
void mostrar_leaks()
{
    // Mostrar asignaciones no liberadas
}
```
<!-- {code-block} c -->

---

## Notas Finales

:::{danger} Orden de Liberación

**Regla de Oro:** Liberar en orden inverso a asignación

**Matriz dentada:**
```{code-block} c
:linenos:
// Asignación:
int **m = malloc(filas * sizeof(int *)); // 1
for (i...)
    m[i] = malloc(cols * sizeof(int)); // 2
// Liberación:
for (i...)
    free(m[i]); // 2 primero
free(m);        // 1 después
```
<!-- {code-block} c -->

**Estructura con punteros:**
```{code-block} c
:linenos:
// Asignación:
persona_t *p = malloc(sizeof(persona_t)); // 1
p->nombre = malloc(100);                  // 2
// Liberación:
free(p->nombre); // 2 primero
free(p);         // 1 después
```
<!-- {code-block} c -->

:::
<!-- {danger} Orden de Liberación -->

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
<!-- {tip} Estrategias de Matrices Dinámicas -->

:::{warning} Errores Comunes

1. **Olvidar liberar datos internos:**
   ```c
   typedef struct
   {
       char *str;
   } S;
   S *s = malloc(sizeof(S));
   s->str = malloc(100);
   free(s); // MAL: leak de s->str
   ```

2. **Orden incorrecto:**
   ```c
   free(m);    // MAL: pierde acceso a m[i]
   free(m[i]); // Comportamiento indefinido
   ```

3. **Realloc mal usado:**
   ```c
   arr = realloc(arr, nuevo_tam); // MAL: si falla, pierde arr original
   // BIEN:
   int *temp = realloc(arr, nuevo_tam);
   if (temp == NULL)
   { /* manejar error */
   }
   arr = temp;
   ```

4. **Copiar punteros en lugar de datos:**
   ```c
   copia->nombre = orig->nombre;         // MAL: shallow copy
   copia->nombre = strdup(orig->nombre); // BIEN: deep copy
   ```

:::
<!-- {warning} Errores Comunes -->

:::{note} Herramientas de Debugging

**Valgrind - Memcheck:**
``` bash
valgrind --leak-check=full --show-leak-kinds=all ./programa
```
<!-- bash -->

**AddressSanitizer:**
``` bash
gcc -fsanitize=address -g programa.c
./programa
```
<!-- bash -->

**Errores detectados:**
- Memory leaks
- Use after free
- Double free
- Buffer overflows
- Uninitialized memory

:::
<!-- {note} Herramientas de Debugging -->

Estas consignas cubren gestión avanzada de memoria y estructuras dinámicas
complejas, esenciales para implementar TADs y aplicaciones de performance
crítica.

