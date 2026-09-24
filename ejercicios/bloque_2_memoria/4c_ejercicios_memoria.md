---
title: 'Ejercicios Resueltos: Memoria Dinámica'
short_title: '14b - Ejercicios Memoria'
subtitle: 'Problemas y soluciones detalladas sobre gestión de memoria en C'
---

# Ejercicios Resueltos: Memoria Dinámica

## Prerrequisitos y Entorno Requerido
Para abordar y verificar las soluciones de este módulo, se requiere:
1. **Entorno de Compilación:** Compilador GCC 9+ o Clang bajo estándar estricto **ISO C11** (`-std=c11 -Wall -Wextra -Werror -pedantic`).
2. **Primitivas de Heap:** Asignación dinámica (`malloc`, `calloc`, `realloc`), dimensionamiento seguro con `sizeof(*p)` y desasignación simétrica estricta con `free`.
3. **Manejo Defensivo y Fugas:** Comprobación sistemática de punteros `NULL` ante fallos de alocación y validación dinámica de invariantes con AddressSanitizer (`-fsanitize=address,undefined`).

## Acerca de

Este archivo contiene problemas prácticos y soluciones canónicas sobre la gestión de
memoria dinámica en el heap utilizando `malloc`, `calloc`, `realloc` y `free` en C11.

### Capítulos de Apunte Correspondientes
- [Memoria Dinámica](../../apunte/bloque_2_memoria/5_memoria_dinamica.md)

---

(ej_b2_c05c_01)=
### Ejercicio 2.05c.01 - Asignación Dinámica de Arreglo y Promedio ⭐⭐☆☆☆

:::{exercise}
:label: ej-memoria-basico
:enumerator: memoria-1

Implementá una función `double *crear_arreglo_reales(size_t cantidad, double valor_inicial)`
que reserve memoria dinámica para un arreglo de números reales (`double`) y lo inicialice con
`valor_inicial`. Implementá además una función `double calcular_promedio(const double *arreglo, size_t cantidad)`
que retorne el promedio de los elementos.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `malloc`, `sizeof(*p)`, inicialización, aritmética de punteros, `free`.  
**Techo conceptual:** Prohibido el uso de memoria no inicializada sin verificar `NULL`.

#### Contrato de la Función
- **Firma:** `double *crear_arreglo_reales(size_t cantidad, double valor_inicial);`
- **Firma:** `double calcular_promedio(const double *arreglo, size_t cantidad);`
- **Precondiciones:** `cantidad > 0` para promedio; el llamador es responsable de liberar el arreglo devuelto.
- **Postcondiciones:** Retorna puntero a bloque en heap o `NULL` si falla. El promedio es $\frac{1}{n} \sum x_i$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`cantidad`, `valor`) | Retorno Promedio | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `n = 4`, `{10.0, 20.0, 30.0, 40.0}` | `25.0` | Promedio estándar de positivos |
| **Borde (Unitario)** | `n = 1`, `{42.5}` | `42.5` | Arreglo de un solo elemento |
| **Borde (Cero)** | `n = 0` en creación | `NULL` | Tamaño cero no admisible |
| **Normal (Negativos)**| `n = 2`, `{-10.0, 10.0}` | `0.0` | Cancelación simétrica |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-basico
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

double *crear_arreglo_reales(size_t cantidad, double valor_inicial)
{
    if (cantidad == 0)
    {
        return NULL;
    }

    double *arr = malloc(cantidad * sizeof(*arr));
    if (arr == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        arr[i] = valor_inicial;
    }

    return arr;
}

double calcular_promedio(const double *arreglo, size_t cantidad)
{
    assert(arreglo != NULL);
    assert(cantidad > 0);

    double suma = 0.0;
    for (size_t i = 0; i < cantidad; i++)
    {
        suma += arreglo[i];
    }
    return suma / (double)cantidad;
}

int main(void)
{
    // Creación normal
    double *datos = crear_arreglo_reales(4, 10.0);
    assert(datos != NULL);
    datos[1] = 20.0;
    datos[2] = 30.0;
    datos[3] = 40.0;
    assert(fabs(calcular_promedio(datos, 4) - 25.0) < 0.001);
    free(datos);
    datos = NULL;

    // Caso tamaño cero
    assert(crear_arreglo_reales(0, 1.0) == NULL);

    // Caso un elemento
    double *unit = crear_arreglo_reales(1, 42.5);
    assert(unit != NULL);
    assert(fabs(calcular_promedio(unit, 1) - 42.5) < 0.001);
    free(unit);
    unit = NULL;

    return 0;
}
```

::::
<!-- {solution} ej-memoria-basico -->

---

(ej_b2_c05c_02)=
### Ejercicio 2.05c.02 - Duplicación de Cadenas en Memoria Dinámica ⭐⭐☆☆☆

:::{exercise}
:label: ej-memoria-cadena
:enumerator: memoria-2

Implementá una función `char *duplicar_cadena(const char *original)` que reciba una
cadena inmutable y retorne una copia exacta alojada en memoria dinámica (equivalente a `strdup`).
La función debe calcular la longitud con precisión, solicitar la memoria necesaria (incluyendo
el byte nulo terminador `\0`) y copiar el contenido sin recurrir a funciones auxiliares de `<string.h>`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `malloc`, aritmética de punteros en cadenas, terminador `\0`.  
**Techo conceptual:** Prohibido el uso de buffers estáticos o variables globales.

#### Contrato de la Función
- **Firma:** `char *duplicar_cadena(const char *original);`
- **Precondiciones:** `original != NULL`.
- **Postcondiciones:** Retorna puntero a nueva cadena en heap idéntica a `original`. Retorna `NULL` si falla `malloc`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `original` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `"Estructura de Datos"` | `"Estructura de Datos"` | Copia con espacios y caracteres alfanuméricos |
| **Borde (Vacía)** | `""` | `""` (1 byte con `\0`) | Cadena vacía válida |
| **Borde (1 Char)** | `"A"` | `"A"` (2 bytes) | Cadena unitaria |
| **Error (Nulo)** | `NULL` | `NULL` | Verificación defensiva |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-cadena
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *duplicar_cadena(const char *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    size_t len = 0;
    while (original[len] != '\0')
    {
        len++;
    }

    char *copia = malloc(len + 1);
    if (copia == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i <= len; i++)
    {
        copia[i] = original[i];
    }

    return copia;
}

int main(void)
{
    // Caso normal
    char *c1 = duplicar_cadena("Estructura de Datos");
    assert(c1 != NULL);
    assert(strcmp(c1, "Estructura de Datos") == 0);
    free(c1);

    // Caso vacía
    char *c2 = duplicar_cadena("");
    assert(c2 != NULL);
    assert(strcmp(c2, "") == 0);
    free(c2);

    // Caso nulo
    assert(duplicar_cadena(NULL) == NULL);

    return 0;
}
```

::::
<!-- {solution} ej-memoria-cadena -->

---

(ej_b2_c05c_03)=
### Ejercicio 2.05c.03 - Búsqueda y Conteo en Arreglo Dinámico ⭐⭐☆☆☆

:::{exercise}
:label: ej-memoria-busqueda
:enumerator: memoria-3

Implementá las siguientes operaciones sobre arreglos dinámicos:
- `int *crear_arreglo_inicializado(size_t tamano, int valor_inicial)`: Asigna memoria para `tamano` enteros con valor `valor_inicial`.
- `int buscar_elemento(const int *arreglo, size_t tamano, int valor)`: Retorna el índice de la primera ocurrencia o `-1`.
- `size_t contar_ocurrencias(const int *arreglo, size_t tamano, int valor)`: Retorna la cantidad de veces que aparece `valor`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Búsqueda lineal, punteros constantes, asignación dinámica.  
**Techo conceptual:** Prohibido el uso de memoria dinámica dentro de las funciones de búsqueda.

#### Contrato de la Función
- **Firma:** `int *crear_arreglo_inicializado(size_t tamano, int valor_inicial);`
- **Firma:** `int buscar_elemento(const int *arreglo, size_t tamano, int valor);`
- **Firma:** `size_t contar_ocurrencias(const int *arreglo, size_t tamano, int valor);`
- **Precondiciones:** `arreglo != NULL` (si `tamano > 0`).
- **Postcondiciones:** `buscar_elemento` retorna índice $\ge 0$ o `-1`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Arreglo ($n$) | Búsqueda | Índice Retornado | Ocurrencias | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | `{5, 5, 10, 5, 20}`, $n=5$ | $10$ | `2` | `1` | Elemento presente una vez |
| **Normal (Múltiple)**| `{5, 5, 10, 5, 20}`, $n=5$ | $5$ | `0` | `3` | Primera posición y conteo repetido |
| **Borde (Ausente)** | `{1, 2, 3}`, $n=3$ | $99$ | `-1` | `0` | Elemento no perteneciente |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-busqueda
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

int *crear_arreglo_inicializado(size_t tamano, int valor_inicial)
{
    if (tamano == 0)
    {
        return NULL;
    }

    int *arreglo = malloc(tamano * sizeof(*arreglo));
    if (arreglo == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        arreglo[i] = valor_inicial;
    }

    return arreglo;
}

int buscar_elemento(const int *arreglo, size_t tamano, int valor)
{
    if (arreglo == NULL)
    {
        return -1;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            return (int)i;
        }
    }
    return -1;
}

size_t contar_ocurrencias(const int *arreglo, size_t tamano, int valor)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    size_t contador = 0;
    for (size_t i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            contador++;
        }
    }
    return contador;
}

int main(void)
{
    size_t n = 5;
    int *arr = crear_arreglo_inicializado(n, 5);
    assert(arr != NULL);

    arr[2] = 10;
    arr[4] = 20;

    assert(buscar_elemento(arr, n, 10) == 2);
    assert(contar_ocurrencias(arr, n, 10) == 1);

    assert(buscar_elemento(arr, n, 5) == 0);
    assert(contar_ocurrencias(arr, n, 5) == 3);

    assert(buscar_elemento(arr, n, 99) == -1);
    assert(contar_ocurrencias(arr, n, 99) == 0);

    free(arr);
    return 0;
}
```

::::
<!-- {solution} ej-memoria-busqueda -->

---

(ej_b2_c05c_04)=
### Ejercicio 2.05c.04 - Creación y Liberación de Matriz Dinámica $M \times N$ ⭐⭐⭐☆☆

:::{exercise}
:label: ej-memoria-matriz
:enumerator: memoria-4

Implementá las funciones canónicas para gestionar una matriz bidimensional asignada dinámicamente
mediante un vector de punteros a filas (`int **`):
- `int **crear_matriz(size_t filas, size_t columnas)`: Reserva memoria para el vector de punteros y para cada fila individual. Si alguna asignación falla, debe liberar todo lo asignado previamente y retornar `NULL` (garantía de no fuga).
- `void liberar_matriz(int **matriz, size_t filas)`: Libera cada fila y finalmente el vector principal.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Punteros dobles (`int **`), desasignación en reversa ante fallas parciales de `malloc`.  
**Techo conceptual:** Prohibido dejar punteros huérfanos sin liberar.

#### Contrato de la Función
- **Firma:** `int **crear_matriz(size_t filas, size_t columnas);`
- **Firma:** `void liberar_matriz(int **matriz, size_t filas);`
- **Precondiciones:** `filas > 0`, `columnas > 0`.
- **Postcondiciones:** Retorna `int **` válido con todos sus elementos accesibles vía `matriz[i][j]`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`filas`, `columnas`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `filas = 3, columnas = 4` | Puntero no nulo | Matriz rectangular estándar |
| **Borde (Cuadrada)** | `filas = 2, columnas = 2` | Puntero no nulo | Matriz cuadrada mínima |
| **Borde (Cero)** | `filas = 0` o `columnas = 0` | `NULL` | Dimensiones nulas rechazadas |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-matriz
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

int **crear_matriz(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }

    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = malloc(columnas * sizeof(**matriz));
        if (matriz[i] == NULL)
        {
            // Desasignar filas previas en caso de falla intermedia
            for (size_t k = 0; k < i; k++)
            {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void liberar_matriz(int **matriz, size_t filas)
{
    if (matriz == NULL)
    {
        return;
    }

    for (size_t i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main(void)
{
    size_t f = 3;
    size_t c = 4;
    int **m = crear_matriz(f, c);
    assert(m != NULL);

    for (size_t i = 0; i < f; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            m[i][j] = (int)(i * c + j);
        }
    }

    assert(m[0][0] == 0);
    assert(m[2][3] == 11);

    liberar_matriz(m, f);

    assert(crear_matriz(0, 5) == NULL);
    assert(crear_matriz(5, 0) == NULL);

    return 0;
}
```

::::
<!-- {solution} ej-memoria-matriz -->

---

(ej_b2_c05c_05)=
### Ejercicio 2.05c.05 - Gestión de Estructura con Miembros Dinámicos ⭐⭐⭐☆☆

:::{exercise}
:label: ej-memoria-estructura
:enumerator: memoria-5

Definí la estructura:
```c
typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;
```
Implementá:
- `persona_t *crear_persona(const char *nombre, const char *apellido, int edad)`: Asigna dinámicamente la estructura y clona dinámicamente cada cadena de texto.
- `void destruir_persona(persona_t *p)`: Libera las cadenas de texto internas y luego la estructura misma.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Agregación de memoria dinámica multinivel, destructores limpios.  
**Techo conceptual:** Prohibido liberar la estructura antes que sus campos referenciados.

#### Contrato de la Función
- **Firma:** `persona_t *crear_persona(const char *nombre, const char *apellido, int edad);`
- **Firma:** `void destruir_persona(persona_t *p);`
- **Precondiciones:** `nombre != NULL`, `apellido != NULL`, `edad >= 0`.
- **Postcondiciones:** Retorna `persona_t *` totalmente inicializado o `NULL` ante error de memoria.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`nombre`, `apellido`, `edad`) | Retorno | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `"Alan"`, `"Turing"`, `41` | Puntero no nulo válido | Clonado multinivel completo |
| **Borde (Cadenas Vacías)**| `""`, `""`, `0` | Puntero no nulo válido | Manejo de cadenas de longitud cero |
| **Error (Nulos)** | `NULL`, `"Pérez"`, `30` | `NULL` | Rechazo seguro de precondición |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-estructura
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;

static char *clonar_texto(const char *src)
{
    if (src == NULL) return NULL;
    size_t len = strlen(src);
    char *dest = malloc(len + 1);
    if (dest != NULL)
    {
        memcpy(dest, src, len + 1);
    }
    return dest;
}

persona_t *crear_persona(const char *nombre, const char *apellido, int edad)
{
    if (nombre == NULL || apellido == NULL || edad < 0)
    {
        return NULL;
    }

    persona_t *p = malloc(sizeof(*p));
    if (p == NULL)
    {
        return NULL;
    }

    p->nombre = clonar_texto(nombre);
    p->apellido = clonar_texto(apellido);
    p->edad = edad;

    if (p->nombre == NULL || p->apellido == NULL)
    {
        free(p->nombre);
        free(p->apellido);
        free(p);
        return NULL;
    }

    return p;
}

void destruir_persona(persona_t *p)
{
    if (p == NULL)
    {
        return;
    }

    free(p->nombre);
    free(p->apellido);
    free(p);
}

int main(void)
{
    persona_t *p = crear_persona("Alan", "Turing", 41);
    assert(p != NULL);
    assert(strcmp(p->nombre, "Alan") == 0);
    assert(strcmp(p->apellido, "Turing") == 0);
    assert(p->edad == 41);
    destruir_persona(p);

    assert(crear_persona(NULL, "Turing", 41) == NULL);
    assert(crear_persona("Alan", NULL, 41) == NULL);

    return 0;
}
```

::::
<!-- {solution} ej-memoria-estructura -->

---

(ej_b2_c05c_06)=
### Ejercicio 2.05c.06 - Diagnóstico y Prevención de Fugas de Memoria ⭐⭐⭐☆☆

:::{exercise}
:label: ej-memoria-errores
:enumerator: memoria-6

Implementá una función `int *crear_arreglo_seguro(size_t tamano)` que reserve un arreglo
de enteros en heap, lo inicialice de manera secuencial (`arr[i] = (int)i`) verificando
estrictamente el retorno de `malloc`, y permitiendo ser consumido por una función de lectura
inmutable `int sumar_elementos(const int *arr, size_t tamano)`. El llamador debe garantizar
la liberación sin incurrir en lecturas tras liberación (*use-after-free*) ni dobles liberaciones (*double free*).

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Ciclo de vida estricto de memoria en heap, prevención de punteros colgantes.  
**Techo conceptual:** Prohibido liberar memoria en funciones consumidoras de lectura.

#### Contrato de la Función
- **Firma:** `int *crear_arreglo_seguro(size_t tamano);`
- **Firma:** `int sumar_elementos(const int *arr, size_t tamano);`
- **Precondiciones:** `tamano > 0`.
- **Postcondiciones:** `sumar_elementos` no modifica ni libera `arr`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Tamaño `n` | Suma Esperada | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | $n = 5$ (`{0, 1, 2, 3, 4}`) | $10$ | Suma aritmética $\frac{4 \times 5}{2}$ |
| **Borde (Unitario)** | $n = 1$ (`{0}`) | $0$ | Arreglo unitario |
| **Borde (Cero)** | $n = 0$ | Retorna `NULL` | Tamaño nulo |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-errores
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

int *crear_arreglo_seguro(size_t tamano)
{
    if (tamano == 0)
    {
        return NULL;
    }

    int *arr = malloc(tamano * sizeof(*arr));
    if (arr == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        arr[i] = (int)i;
    }

    return arr;
}

int sumar_elementos(const int *arr, size_t tamano)
{
    if (arr == NULL)
    {
        return 0;
    }

    int suma = 0;
    for (size_t i = 0; i < tamano; i++)
    {
        suma += arr[i];
    }
    return suma;
}

int main(void)
{
    int *arr = crear_arreglo_seguro(5);
    assert(arr != NULL);
    assert(sumar_elementos(arr, 5) == 10);
    free(arr);
    arr = NULL;

    assert(crear_arreglo_seguro(0) == NULL);

    return 0;
}
```

::::
<!-- {solution} ej-memoria-errores -->

---

(ej_b2_c05c_07)=
### Ejercicio 2.05c.07 - Matriz Contigua en Memoria Plana y Transposición In-Place ⭐⭐⭐☆☆

:::{exercise}
:label: ej-memoria-puntero-array
:enumerator: memoria-7

Implementá funciones para operar con matrices contiguas en memoria plana (`int *`),
optimizando la localidad espacial de caché y reduciendo las llamadas al sistema operativo a una única asignación:
- `int *crear_matriz_contigua(size_t filas, size_t columnas)`: Asigna un único bloque contiguo de tamaño `filas * columnas * sizeof(int)`.
- `void transponer_cuadrada_contigua(int *matriz, size_t n)`: Transpone in-place una matriz cuadrada $N \times N$ accediendo mediante la fórmula $i \times N + j$.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Mapeo de memoria bidimensional a lineal (`i * cols + j`), transposición in-place con complejidad espacial $O(1)$.  
**Techo conceptual:** Prohibido el uso de matrices auxiliares.

#### Contrato de la Función
- **Firma:** `int *crear_matriz_contigua(size_t filas, size_t columnas);`
- **Firma:** `void transponer_cuadrada_contigua(int *matriz, size_t n);`
- **Precondiciones:** `matriz != NULL`, `filas > 0`, `columnas > 0`.
- **Postcondiciones:** `matriz[i * n + j]` se intercambia con `matriz[j * n + i]` para todo $i < j$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Dimensión ($N$) | Matriz Inicial | Matriz Transpuesta | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | $N = 2$ | `[1, 2; 3, 4]` | `[1, 3; 2, 4]` | Transposición de $2 \times 2$ |
| **Normal ($3 \times 3$)** | $N = 3$ | Matriz secuencial | Reflejo sobre diagonal principal | Diagonal inalterada |
| **Borde (Unitario)** | $N = 1$ | `[42]` | `[42]` | Matriz $1 \times 1$ inalterada |

:::
<!-- {exercise} -->

::::{solution} ej-memoria-puntero-array
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

int *crear_matriz_contigua(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }

    int *matriz = malloc(filas * columnas * sizeof(*matriz));
    return matriz;
}

void transponer_cuadrada_contigua(int *matriz, size_t n)
{
    if (matriz == NULL || n < 2)
    {
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            size_t idx1 = i * n + j;
            size_t idx2 = j * n + i;
            int temp = matriz[idx1];
            matriz[idx1] = matriz[idx2];
            matriz[idx2] = temp;
        }
    }
}

int main(void)
{
    size_t n = 2;
    int *m = crear_matriz_contigua(n, n);
    assert(m != NULL);

    m[0 * n + 0] = 1;
    m[0 * n + 1] = 2;
    m[1 * n + 0] = 3;
    m[1 * n + 1] = 4;

    transponer_cuadrada_contigua(m, n);

    assert(m[0 * n + 0] == 1);
    assert(m[0 * n + 1] == 3);
    assert(m[1 * n + 0] == 2);
    assert(m[1 * n + 1] == 4);

    free(m);
    m = NULL;

    return 0;
}
```

::::
<!-- {solution} ej-memoria-puntero-array -->
