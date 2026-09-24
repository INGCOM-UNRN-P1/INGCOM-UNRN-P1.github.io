---
title: "Ejercicios: Punteros Avanzados y Genericidad"
short_title: "4. Punteros Avanzados"
---

# Ejercicios de Punteros Avanzados y Genericidad

## Acerca de

Estos ejercicios tienen como fin dominar la indirección múltiple mediante punteros dobles (`**`)
y la abstracción procedimental mediante punteros a funciones (`callback`) para implementar
polimorfismo y genericidad en C11.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros-funciones`

### Prerrequisitos Conceptuales
Antes de abordar estos ejercicios, el estudiante debe dominar:
1. Punteros simples y operadores de indirección (`*`, `&`) ({ref}`capitulo-punteros`).
2. Indirección múltiple (`T **`) para mutación de punteros por referencia ({ref}`capitulo-punteros`).
3. Asignación dinámica y liberación segura en Heap (`malloc`, `free`) ({ref}`capitulo-memoria-dinamica`).
4. Punteros a funciones (`callback`) y genericidad basada en bloques opacos de bytes `void *` ({ref}`capitulo-punteros-funciones`).

### Cuestiones de Estilo Aplicables
- **Uso de aserciones en punteros:** Validá siempre que los punteros dobles y de
  función no sean `NULL` antes de desreferenciarlos o invocarlos (ver {ref}`0x2008h`).
- **Definición de alias:** Empleá `typedef` para declarar firmas de punteros a
  funciones legibles en tus programas (ver reglas en {ref}`0x0101h`).
- **Punteros genéricos (`void *`):** Al manipular bloques de memoria genéricos,
  realizá la aritmética sobre punteros a bytes (`char *` o `uint8_t *`) multiplicando
  por el tamaño de cada elemento.

---

## Indirección Múltiple: Punteros Dobles (`**`)

(ej_b4_c02_01)=
### Ejercicio 4.02.01 - Asignación de Memoria por Referencia con Puntero Doble ⭐⭐☆☆☆

:::{exercise}
:label: alocar_cadena_doble
:enumerator: punteros-adv-1

Implementá una función `bool alocar_cadena(char **puntero_a_cadena, const char *valor_inicial)`
que reciba un puntero doble. La función debe reservar dinámicamente la memoria necesaria en el heap
para contener la cadena `valor_inicial` (incluyendo `\0`), copiar sus bytes y hacer que la
variable apuntada por `puntero_a_cadena` en el llamador apunte a esta nueva memoria.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Punteros a punteros (`char **`), `malloc`, copia de memoria.  
**Techo conceptual:** Prohibido el uso de variables globales.

#### Contrato de la Función
- **Firma:** `bool alocar_cadena(char **puntero_a_cadena, const char *valor_inicial);`
- **Precondiciones:** `puntero_a_cadena != NULL`, `valor_inicial != NULL`.
- **Postcondiciones:** Retorna `true` y `*puntero_a_cadena` apunta a la nueva cadena en heap; si falla `malloc`, retorna `false` y `*puntero_a_cadena = NULL`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`valor_inicial`) | Retorno Booleano | Contenido de `*puntero_a_cadena` | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `"Hola Mundo"` | `true` | `"Hola Mundo"` | Reserva y copia estándar en heap |
| **Borde (Cadena Vacía)**| `""` | `true` | `""` (1 byte `\0`) | Reserva mínima de 1 byte |
| **Error (Puntero Nulo)**| `NULL` | `false` | Inalterado | Validación defensiva de precondición |

:::
<!-- {exercise} -->

::::{solution} alocar_cadena_doble
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool alocar_cadena(char **puntero_a_cadena, const char *valor_inicial)
{
    if (puntero_a_cadena == NULL || valor_inicial == NULL)
    {
        return false;
    }

    size_t len = strlen(valor_inicial);
    char *nueva = malloc(len + 1);
    if (nueva == NULL)
    {
        *puntero_a_cadena = NULL;
        return false;
    }

    memcpy(nueva, valor_inicial, len + 1);
    *puntero_a_cadena = nueva;
    return true;
}

int main(void)
{
    char *texto = NULL;

    assert(alocar_cadena(&texto, "Hola Mundo") == true);
    assert(texto != NULL);
    assert(strcmp(texto, "Hola Mundo") == 0);
    free(texto);
    texto = NULL;

    assert(alocar_cadena(&texto, "") == true);
    assert(texto != NULL);
    assert(strcmp(texto, "") == 0);
    free(texto);
    texto = NULL;

    assert(alocar_cadena(NULL, "Test") == false);
    assert(alocar_cadena(&texto, NULL) == false);

    return 0;
}
```

::::
<!-- {solution} alocar_cadena_doble -->

---

(ej_b4_c02_02)=
### Ejercicio 4.02.02 - Desasignación Segura de Arreglo de Punteros ⭐⭐⭐☆☆

:::{exercise}
:label: liberar_tokens_matriz
:enumerator: punteros-adv-2

Implementá una función `void liberar_tokens(char **tokens, size_t cantidad)` que libere
cada cadena apuntada por `tokens[i]` y finalmente libere el bloque contenedor de punteros `tokens`.
Implementá además una función `char **crear_arreglo_cadenas(size_t cantidad)` que inicialice
el vector de punteros a `NULL`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Punteros dobles, desasignación multinivel en heap.  
**Techo conceptual:** Prohibido liberar el bloque contenedor antes de sus elementos.

#### Contrato de la Función
- **Firma:** `void liberar_tokens(char **tokens, size_t cantidad);`
- **Precondiciones:** Ninguna (maneja `tokens == NULL`).
- **Postcondiciones:** Toda la memoria en heap referenciada por `tokens` y sus elementos es liberada.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`cantidad`, elementos) | Efecto Observable | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `3` cadenas dinámicas | Memoria liberada limpiamente | Desasignación completa multinivel |
| **Borde (Elementos NULL)**| Elementos intercalados `NULL` | Liberación segura sin crash | Manejo defensivo en bucle de free |
| **Borde (Vector NULL)** | `tokens = NULL` | Retorno inmediato sin acción | Caso trivial base |

:::
<!-- {exercise} -->

::::{solution} liberar_tokens_matriz
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **crear_arreglo_cadenas(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }

    char **arr = calloc(cantidad, sizeof(*arr));
    return arr;
}

void liberar_tokens(char **tokens, size_t cantidad)
{
    if (tokens == NULL)
    {
        return;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}

int main(void)
{
    char **tokens = crear_arreglo_cadenas(3);
    assert(tokens != NULL);

    tokens[0] = malloc(10);
    strcpy(tokens[0], "Token1");

    tokens[1] = NULL; // Elemento nulo defensivo

    tokens[2] = malloc(10);
    strcpy(tokens[2], "Token3");

    liberar_tokens(tokens, 3);
    liberar_tokens(NULL, 0); // No debe fallar

    return 0;
}
```

::::
<!-- {solution} liberar_tokens_matriz -->

---

## Punteros a Función: Callbacks y Genericidad

(ej_b4_c02_03)=
### Ejercicio 4.02.03 - Orden Superior: Calculadora Parametrizada ⭐⭐☆☆☆

:::{exercise}
:label: calculadora_callback
:enumerator: punteros-adv-3

Definí el alias de tipo para puntero a función:
```c
typedef int (*operacion_aritmetica_t)(int, int);
```
Implementá una función de orden superior `int ejecutar_operacion(int a, int b, operacion_aritmetica_t op)`
que invoque dinámicamente la operación aritmética pasada por argumento.
Probala con funciones puras `sumar(a, b)` y `multiplicar(a, b)`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `typedef` de punteros a función, invocación indirecta.  
**Techo conceptual:** Prohibido el uso de sentencias `switch` para elegir la operación.

#### Contrato de la Función
- **Firma:** `int ejecutar_operacion(int a, int b, operacion_aritmetica_t op);`
- **Precondiciones:** `op != NULL`.
- **Postcondiciones:** Retorna el resultado de invocar `op(a, b)`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Operación | Entrada (`a, b`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `sumar` | `10, 5` | `15` | Ejecución de callback aditivo |
| **Normal** | `multiplicar` | `10, 5` | `50` | Ejecución de callback multiplicativo |
| **Normal** | `restar` | `10, 5` | `5` | Ejecución de callback sustractivo |

:::
<!-- {exercise} -->

::::{solution} calculadora_callback
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

typedef int (*operacion_aritmetica_t)(int, int);

int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }

int ejecutar_operacion(int a, int b, operacion_aritmetica_t op)
{
    assert(op != NULL);
    return op(a, b);
}

int main(void)
{
    assert(ejecutar_operacion(10, 5, sumar) == 15);
    assert(ejecutar_operacion(10, 5, restar) == 5);
    assert(ejecutar_operacion(10, 5, multiplicar) == 50);
    return 0;
}
```

::::
<!-- {solution} calculadora_callback -->

---

(ej_b4_c02_04)=
### Ejercicio 4.02.04 - Tabla de Despacho (Dispatch Table) ⭐⭐⭐☆☆

:::{exercise}
:label: dispatch_table
:enumerator: punteros-adv-4

Diseñá una tabla de despacho basada en un arreglo estático inmutable de punteros a función:
`operacion_aritmetica_t operaciones[4]`.
Implementá una función `bool despachar_operacion(size_t codigo, int a, int b, int *resultado)`
que resuelva la operación en tiempo constante $O(1)$ indexando el arreglo, sin usar condicionales `if-else` encadenados.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Arreglos de punteros a función, indexación directa $O(1)$, desacoplamiento arquitectónico.  
**Techo conceptual:** Prohibido el uso de `switch` o `if-else` para la selección de la función.

#### Contrato de la Función
- **Firma:** `bool despachar_operacion(size_t codigo, int a, int b, int *resultado);`
- **Precondiciones:** `resultado != NULL`.
- **Postcondiciones:** Retorna `true` y almacena el resultado si `codigo < 4`; de lo contrario retorna `false`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Código ($0=\text{suma}, 1=\text{resta}, 2=\text{mult}$) | Entrada (`a, b`) | Retorno Booleano | Resultado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | `0` (Suma) | `20, 10` | `true` | `30` | Indexación en posición 0 |
| **Normal** | `1` (Resta) | `20, 10` | `true` | `10` | Indexación en posición 1 |
| **Normal** | `2` (Producto) | `20, 10` | `true` | `200` | Indexación en posición 2 |
| **Error (Fuera de Rango)**| `99` | `20, 10` | `false` | Inalterado | Rechazo seguro de índice inválido |

:::
<!-- {exercise} -->

::::{solution} dispatch_table
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

typedef int (*operacion_aritmetica_t)(int, int);

static int op_sumar(int a, int b) { return a + b; }
static int op_restar(int a, int b) { return a - b; }
static int op_multiplicar(int a, int b) { return a * b; }

static const operacion_aritmetica_t TABLA_DESPACHO[] = {
    op_sumar,
    op_restar,
    op_multiplicar
};

#define CANTIDAD_OPERACIONES (sizeof(TABLA_DESPACHO) / sizeof(TABLA_DESPACHO[0]))

bool despachar_operacion(size_t codigo, int a, int b, int *resultado)
{
    if (resultado == NULL || codigo >= CANTIDAD_OPERACIONES)
    {
        return false;
    }

    *resultado = TABLA_DESPACHO[codigo](a, b);
    return true;
}

int main(void)
{
    int res = 0;

    assert(despachar_operacion(0, 20, 10, &res) == true && res == 30);
    assert(despachar_operacion(1, 20, 10, &res) == true && res == 10);
    assert(despachar_operacion(2, 20, 10, &res) == true && res == 200);

    // Caso fuera de rango
    assert(despachar_operacion(99, 20, 10, &res) == false);

    return 0;
}
```

::::
<!-- {solution} dispatch_table -->

---

(ej_b4_c02_05)=
### Ejercicio 4.02.05 - Mapeo Funcional In-Place sobre Arreglos ⭐⭐⭐☆☆

:::{exercise}
:label: map_inplace_callback
:enumerator: punteros-adv-5

Implementá una función `void mapear_arreglo(int *arr, size_t n, int (*transformar)(int))`
que aplique la función pura `transformar` a cada elemento del arreglo modificándolo in-place.
Probala con funciones como `duplicar` y `cambiar_signo`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Callbacks unarios, iteración con función transformadora.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `void mapear_arreglo(int *arr, size_t n, int (*transformar)(int));`
- **Precondiciones:** `transformar != NULL`. Si `n > 0`, `arr != NULL`.
- **Postcondiciones:** Cada elemento `arr[i]` almacena `transformar(arr[i])`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Arreglo Inicial | Callback | Arreglo Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `{1, 2, 3}`, $n=3$ | `duplicar` | `{2, 4, 6}` | Transformación lineal |
| **Normal** | `{5, -10, 0}`, $n=3$ | `cambiar_signo` | `{-5, 10, 0}` | Inversión de signo |
| **Borde (Vacío)** | $n=0$ | `duplicar` | Sin modificación | Arreglo de 0 elementos |

:::
<!-- {exercise} -->

::::{solution} map_inplace_callback
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

static int transformar_duplicar(int x) { return x * 2; }
static int transformar_signo(int x) { return -x; }

void mapear_arreglo(int *arr, size_t n, int (*transformar)(int))
{
    assert(transformar != NULL);
    if (arr == NULL || n == 0)
    {
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = transformar(arr[i]);
    }
}

int main(void)
{
    int arr1[3] = {1, 2, 3};
    mapear_arreglo(arr1, 3, transformar_duplicar);
    assert(arr1[0] == 2 && arr1[1] == 4 && arr1[2] == 6);

    int arr2[3] = {5, -10, 0};
    mapear_arreglo(arr2, 3, transformar_signo);
    assert(arr2[0] == -5 && arr2[1] == 10 && arr2[2] == 0);

    return 0;
}
```

::::
<!-- {solution} map_inplace_callback -->

---

(ej_b4_c02_06)=
### Ejercicio 4.02.06 - Ordenamiento Genérico con Comparador (Tipo `qsort`) ⭐⭐⭐⭐☆

:::{exercise}
:label: ordenar_generico
:enumerator: punteros-adv-6

Implementá una función de ordenamiento genérico burbuja in-place:
```c
typedef int (*comparador_t)(const void *, const void *);
void ordenar_generico(void *base, size_t n, size_t tam_elem, comparador_t cmp);
```
La función debe poder ordenar un arreglo de cualquier tipo de dato (`int`, `double`, estructuras)
utilizando el comparador provisto por el llamador e intercambiando bloques de memoria mediante `memcpy`.

**Nivel de Bloom:** Nivel 4 (Análisis) y Nivel 5 (Evaluación).  
**Conceptos requeridos:** Punteros `void *`, aritmética sobre `char *`, intercambio de bytes con memoria dinámica o buffer temporal, interfaz tipo POSIX/C11 `qsort`.  
**Techo conceptual:** Prohibido asumir el tipo de dato subyacente.

#### Contrato de la Función
- **Firma:** `void ordenar_generico(void *base, size_t n, size_t tam_elem, comparador_t cmp);`
- **Precondiciones:** `cmp != NULL`, `tam_elem > 0`. Si `n > 0`, `base != NULL`.
- **Postcondiciones:** Los elementos del arreglo quedan ordenados según el orden inducido por `cmp`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Tipo de Datos | Entrada | Comparador | Salida Ordenada | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal (Enteros)** | `int` | `{5, 1, 4, 2}` | Ascendente `int` | `{1, 2, 4, 5}` | Ordenamiento genérico escalar |
| **Normal (Reales)** | `double` | `{3.5, 1.2, 9.8}` | Ascendente `double`| `{1.2, 3.5, 9.8}`| Ordenamiento de flotantes de 8 bytes |
| **Borde (1 Elemento)**| `int` | `{42}` | Ascendente | `{42}` | Caso unitario |

:::
<!-- {exercise} -->

::::{solution} ordenar_generico
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int (*comparador_t)(const void *, const void *);

void ordenar_generico(void *base, size_t n, size_t tam_elem, comparador_t cmp)
{
    assert(cmp != NULL);
    assert(tam_elem > 0);

    if (base == NULL || n < 2)
    {
        return;
    }

    char *bytes = (char *)base;
    void *temp = malloc(tam_elem);
    if (temp == NULL)
    {
        return;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            char *elem_a = bytes + (j * tam_elem);
            char *elem_b = bytes + ((j + 1) * tam_elem);

            if (cmp(elem_a, elem_b) > 0)
            {
                memcpy(temp, elem_a, tam_elem);
                memcpy(elem_a, elem_b, tam_elem);
                memcpy(elem_b, temp, tam_elem);
            }
        }
    }

    free(temp);
}

static int cmp_enteros(const void *a, const void *b)
{
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    return (val_a > val_b) - (val_a < val_b);
}

static int cmp_doubles(const void *a, const void *b)
{
    double val_a = *(const double *)a;
    double val_b = *(const double *)b;
    return (val_a > val_b) - (val_a < val_b);
}

int main(void)
{
    int arr_int[4] = {5, 1, 4, 2};
    ordenar_generico(arr_int, 4, sizeof(int), cmp_enteros);
    assert(arr_int[0] == 1 && arr_int[1] == 2 && arr_int[2] == 4 && arr_int[3] == 5);

    double arr_dbl[3] = {3.5, 1.2, 9.8};
    ordenar_generico(arr_dbl, 3, sizeof(double), cmp_doubles);
    assert(arr_dbl[0] == 1.2 && arr_dbl[1] == 3.5 && arr_dbl[2] == 9.8);

    return 0;
}
```

::::
<!-- {solution} ordenar_generico -->

---

(ej_b4_c02_07)=
### Ejercicio 4.02.07 - Reducción Funcional Genérica (Fold / Reduce) ⭐⭐⭐⭐☆

:::{exercise}
:label: reducir_generico
:enumerator: punteros-adv-7

Implementá una función de reducción o plegado (*fold*) genérico sobre un arreglo de datos contiguos:
```c
typedef void (*reductor_t)(void *acumulador, const void *elemento);
void reducir_generico(const void *base, size_t n, size_t tam_elem,
                      reductor_t f, void *acumulador);
```
La función debe recorrer los $n$ elementos de tamaño `tam_elem` y llamar a `f(acumulador, elem)`
por cada elemento, mutando el contenido del acumulador. Probala acumulando la suma de enteros
y calculando el valor máximo de un arreglo de flotantes (`double`).

**Nivel de Bloom:** Nivel 4 (Análisis) y Nivel 5 (Evaluación).  
**Conceptos requeridos:** Punteros genéricos `void *`, aritmética sobre `const char *`, callbacks de mutación con acumulador.  
**Techo conceptual:** Prohibido asumir tipos de datos específicos o realizar castings a punteros no compatibles con la alineación.

#### Contrato de la Función
- **Firma:** `void reducir_generico(const void *base, size_t n, size_t tam_elem, reductor_t f, void *acumulador);`
- **Precondiciones:** `f != NULL`, `acumulador != NULL`, `tam_elem > 0`. Si `n > 0`, `base != NULL`.
- **Postcondiciones:** El acumulador queda con el resultado de componer iterativamente la operación `f`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Tipo de Datos | Entrada | Acumulador Inicial | Operación `f` | Acumulador Final | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | `int` | `{10, 20, 30}` | `0` | Suma de enteros | `60` | Reducción sumatoria clásica |
| **Normal** | `double` | `{1.5, 9.2, 4.3}` | `-INFINITY` | Máximo double | `9.2` | Búsqueda de extremo con reductor |
| **Borde (Vacío)**| `int` | `n = 0` | `100` | Suma de enteros | `100` | Arreglo vacío preserva neutro |

:::
<!-- {exercise} -->

::::{solution} reducir_generico
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stddef.h>

typedef void (*reductor_t)(void *acumulador, const void *elemento);

void reducir_generico(const void *base, size_t n, size_t tam_elem,
                      reductor_t f, void *acumulador)
{
    assert(f != NULL);
    assert(acumulador != NULL);
    assert(tam_elem > 0);

    if (base == NULL || n == 0)
    {
        return;
    }

    const char *bytes = (const char *)base;
    for (size_t i = 0; i < n; i++)
    {
        const void *elem = bytes + (i * tam_elem);
        f(acumulador, elem);
    }
}

static void sumar_enteros(void *acum, const void *elem)
{
    int *total = (int *)acum;
    const int *val = (const int *)elem;
    *total += *val;
}

static void maximo_doubles(void *acum, const void *elem)
{
    double *max_val = (double *)acum;
    const double *val = (const double *)elem;
    if (*val > *max_val)
    {
        *max_val = *val;
    }
}

int main(void)
{
    int arr_int[3] = {10, 20, 30};
    int suma = 0;
    reducir_generico(arr_int, 3, sizeof(int), sumar_enteros, &suma);
    assert(suma == 60);

    double arr_dbl[3] = {1.5, 9.2, 4.3};
    double maximo = -HUGE_VAL;
    reducir_generico(arr_dbl, 3, sizeof(double), maximo_doubles, &maximo);
    assert(maximo == 9.2);

    int preservado = 100;
    reducir_generico(NULL, 0, sizeof(int), sumar_enteros, &preservado);
    assert(preservado == 100);

    return 0;
}
```

::::
<!-- {solution} reducir_generico -->

---

(ej_b4_c02_08)=
### Ejercicio 4.02.08 - Máquina de Estados Finita (FSM) con Matriz de Callbacks ⭐⭐⭐⭐☆

:::{exercise}
:label: fsm_matriz_callbacks
:enumerator: punteros-adv-8

Implementá una Máquina de Estados Finita (FSM) basada en una matriz bidimensional de punteros a función de transiciones:
$$\text{TABLA\_TRANSICIONES}[\text{estado}][\text{evento}]$$
donde cada celda contiene una función de transición pura con la firma:
```c
typedef estado_t (*transicion_fn)(void);
```
Dadas las definiciones:
```c
typedef enum {
    ESTADO_REPOSO = 0,
    ESTADO_EJECUCION,
    ESTADO_PAUSA,
    CANT_ESTADOS
} estado_t;

typedef enum {
    EVENTO_ARRANCAR = 0,
    EVENTO_PAUSAR,
    EVENTO_DETENER,
    CANT_EVENTOS
} evento_t;
```

Implementá la función de despacho:
```c
estado_t fsm_transicionar(estado_t actual, evento_t evento);
```
Si la transición no está permitida para el par $(actual, evento)$ (la celda es `NULL`), la FSM debe permanecer en el estado `actual` sin efectos adversos. Si alguno de los argumentos está fuera de rango, retorna `actual`.

**Nivel de Bloom:** Nivel 4 (Análisis) y Nivel 5 (Evaluación).  
**Conceptos requeridos:** Matrices de punteros a función, máquinas de estado dirigidas por tablas $O(1)$, desacoplamiento de transiciones sin `switch` anidados.  
**Techo conceptual:** Prohibido el uso de condicionales `if-else` o `switch` para bifurcar estados y eventos.

#### Contrato de la Función
- **Firma:** `estado_t fsm_transicionar(estado_t actual, evento_t evento);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna el nuevo estado tras ejecutar el callback de transición correspondiente, o `actual` si la transición es inválida o nula.

#### Tabla de Vectores de Prueba Obligatorios

| Estado Inicial | Evento | Transición Esperada | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| `ESTADO_REPOSO` | `EVENTO_ARRANCAR` | `ESTADO_EJECUCION` | Arranque del sistema |
| `ESTADO_EJECUCION` | `EVENTO_PAUSAR` | `ESTADO_PAUSA` | Pausa temporal |
| `ESTADO_PAUSA` | `EVENTO_ARRANCAR` | `ESTADO_EJECUCION` | Reanudación desde pausa |
| `ESTADO_REPOSO` | `EVENTO_PAUSAR` | `ESTADO_REPOSO` (sin cambio) | Transición no definida (puntero `NULL`) |
| `ESTADO_EJECUCION` | Evento inválido (`99`) | `ESTADO_EJECUCION` | Rechazo defensivo de evento fuera de rango |

:::
<!-- {exercise} -->

::::{solution} fsm_matriz_callbacks
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

typedef enum
{
    ESTADO_REPOSO = 0,
    ESTADO_EJECUCION,
    ESTADO_PAUSA,
    CANT_ESTADOS
} estado_t;

typedef enum
{
    EVENTO_ARRANCAR = 0,
    EVENTO_PAUSAR,
    EVENTO_DETENER,
    CANT_EVENTOS
} evento_t;

typedef estado_t (*transicion_fn)(void);

static estado_t a_ejecucion(void) { return ESTADO_EJECUCION; }
static estado_t a_pausa(void) { return ESTADO_PAUSA; }
static estado_t a_reposo(void) { return ESTADO_REPOSO; }

static const transicion_fn TABLA_FSM[CANT_ESTADOS][CANT_EVENTOS] = {
    /* ESTADO_REPOSO */
    [ESTADO_REPOSO] = {
        [EVENTO_ARRANCAR] = a_ejecucion,
        [EVENTO_PAUSAR]   = NULL,
        [EVENTO_DETENER]  = NULL
    },
    /* ESTADO_EJECUCION */
    [ESTADO_EJECUCION] = {
        [EVENTO_ARRANCAR] = NULL,
        [EVENTO_PAUSAR]   = a_pausa,
        [EVENTO_DETENER]  = a_reposo
    },
    /* ESTADO_PAUSA */
    [ESTADO_PAUSA] = {
        [EVENTO_ARRANCAR] = a_ejecucion,
        [EVENTO_PAUSAR]   = NULL,
        [EVENTO_DETENER]  = a_reposo
    }
};

estado_t fsm_transicionar(estado_t actual, evento_t evento)
{
    if (actual >= CANT_ESTADOS || evento >= CANT_EVENTOS)
    {
        return actual;
    }

    transicion_fn fn = TABLA_FSM[actual][evento];
    if (fn == NULL)
    {
        return actual;
    }

    return fn();
}

int main(void)
{
    estado_t st = ESTADO_REPOSO;

    // Reposo -> Arrancar -> Ejecución
    st = fsm_transicionar(st, EVENTO_ARRANCAR);
    assert(st == ESTADO_EJECUCION);

    // Ejecución -> Pausar -> Pausa
    st = fsm_transicionar(st, EVENTO_PAUSAR);
    assert(st == ESTADO_PAUSA);

    // Pausa -> Arrancar -> Ejecución
    st = fsm_transicionar(st, EVENTO_ARRANCAR);
    assert(st == ESTADO_EJECUCION);

    // Ejecución -> Detener -> Reposo
    st = fsm_transicionar(st, EVENTO_DETENER);
    assert(st == ESTADO_REPOSO);

    // Transición no permitida: Reposo no puede pausarse
    estado_t mismo = fsm_transicionar(ESTADO_REPOSO, EVENTO_PAUSAR);
    assert(mismo == ESTADO_REPOSO);

    // Evento fuera de rango
    assert(fsm_transicionar(ESTADO_EJECUCION, (evento_t)99) == ESTADO_EJECUCION);
    assert(fsm_transicionar((estado_t)99, EVENTO_ARRANCAR) == (estado_t)99);

    return 0;
}
```

::::
<!-- {solution} fsm_matriz_callbacks -->
