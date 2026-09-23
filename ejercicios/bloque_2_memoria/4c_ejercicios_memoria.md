---
title: 'Ejercicios Resueltos: Memoria Dinámica'
short_title: '14b - Ejercicios Memoria'
subtitle: 'Problemas y soluciones detalladas sobre gestión de memoria en C'
---

(memoria-ejercicios-unidad)=

# Ejercicios Resueltos: Memoria Dinámica

## Acerca de

Este archivo contiene problemas y soluciones detalladas sobre la gestión de
memoria dinámica en C, con foco en el uso de `malloc`, `calloc`, `realloc` y
`free`.

Para más detalles teóricos sobre estos conceptos, consultá [el capítulo de
Memoria
Dinámica](../../apunte/bloque_2_memoria/5_memoria_dinamica.md) del
apunte. Asegurate de seguir la regla de estilo {ref}`0x3002h` para la liberación
adecuada de recursos y prevención de punteros colgantes.
(ejercicio_16_1)=
## Ejercicio 16.1 - s Resueltos ⭐⭐☆☆☆

:::{exercise} Ejercicio 1c.1 - Asignación Básica
:label: ej-memoria-basico

Escribí un programa que:

1. Solicite al usuario la cantidad de números que desea ingresar.
2. Reserve memoria dinámica para un arreglo de enteros de ese tamaño.
3. Permita al usuario ingresar los números.
4. Calcule e imprima el promedio de los números.
5. Libere correctamente la memoria.

Asegurate de verificar todas las asignaciones de memoria y manejar los errores
apropiadamente.

:::
<!-- {exercise} Ejercicio 1c.1 - Asignación Básica -->

::::{solution} ej-memoria-basico
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#define ERROR_MEMORIA 1
#define ERROR_ENTRADA 2
int main()
{
    int *numeros = NULL;
    size_t cantidad = 0;
    int suma = 0;
    printf("¿Cuántos números deseas ingresar? ");
    if (scanf("%zu", &cantidad) != 1 || cantidad == 0)
    {
        fprintf(stderr, "Error: Entrada inválida.\n");
        return ERROR_ENTRADA;
    }
    // Asignar memoria
    numeros = malloc(cantidad * sizeof(*numeros));
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return ERROR_MEMORIA;
    }
    // Leer números
    printf("Ingresa %zu números:\n", cantidad);
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("Número %zu: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1)
        {
            fprintf(stderr, "Error: Entrada inválida.\n");
            free(numeros);
            numeros = NULL;
            return ERROR_ENTRADA;
        }
        suma = suma + numeros[i];
    }
    // Calcular promedio
    double promedio = (double)suma / (double)cantidad;
    printf("El promedio es: %.2f\n", promedio);
    // Liberar memoria
    free(numeros);
    numeros = NULL;
    return 0;
}
```
<!-- {code-block} c -->

::::
<!-- {solution} ej-memoria-basico -->

:::{exercise} Ejercicio 1c.2 - Cadena Dinámica
:label: ej-memoria-cadena

Implementá una función `duplicar_cadena` que reciba una cadena de caracteres y
devuelva una copia exacta de ella en memoria dinámica. La función debe tener la
siguiente firma:

``` c
char *duplicar_cadena(const char *original);
```
<!-- c -->

La función debe:

1. Calcular el tamaño necesario (incluyendo el terminador nulo `\0`).
2. Reservar memoria dinámica para la copia.
3. Copiar el contenido caracter por caracter.
4. Retornar un puntero a la nueva cadena, o `NULL` si hay un error.

Luego, escribí un programa principal que use esta función para duplicar una
cadena ingresada por el usuario.

:::
<!-- {exercise} Ejercicio 1c.2 - Cadena Dinámica -->

:::{warning} Precondición de Seguridad en Copias de Cadenas

Al trabajar con cadenas de caracteres en C, funciones como `strlen` y `strcpy`
asumen de forma estricta que los búferes de entrada están correctamente
finalizados con el carácter nulo (`\0`). Si se recibe una secuencia de bytes que
carece de este terminador (por ejemplo, debido a una lectura parcial o desborde
anterior), la función continuará leyendo o escribiendo en memoria de forma
indefinida, provocando violaciones de acceso o corrupción silenciosa del heap.
Siempre garantizá la correcta inicialización y terminación en nulo del búfer
origen antes de cualquier copia.

:::
<!-- {warning} Precondición de Seguridad en Copias de Cadenas -->

::::{solution} ej-memoria-cadena
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Duplica una cadena en memoria dinámica.
 * @param original Cadena a duplicar (no debe ser NULL y debe estar terminada
 * en \0).
 * @returns Un puntero a la nueva cadena. El llamador es responsable
 *          de liberar esta memoria con free().
 *          Retorna NULL si original es NULL o no hay memoria disponible.
 */
char *duplicar_cadena(const char *original)
{
    if (original == NULL)
    {
        return NULL;
    }
    size_t longitud = strlen(original);
    char *copia = malloc(longitud + 1);
    if (copia == NULL)
    {
        return NULL;
    }
    strcpy(copia, original);
    return copia;
}
int main()
{
    char original[100] = {0};
    printf("Ingresa una cadena (máximo 99 caracteres): ");
    if (fgets(original, sizeof(original), stdin) == NULL)
    {
        fprintf(stderr, "Error: No se pudo leer la cadena.\n");
        return 1;
    }
    // Remover el salto de línea si existe
    original[strcspn(original, "\n")] = '\0';
    char *copia = duplicar_cadena(original);
    if (copia == NULL)
    {
        fprintf(stderr, "Error: No se pudo duplicar la cadena.\n");
        return 1;
    }
    printf("Original: \"%s\"\n", original);
    printf("Copia: \"%s\"\n", copia);
    free(copia);
    copia = NULL;
    return 0;
}
```
<!-- {code-block} c -->

::::
<!-- {solution} ej-memoria-cadena -->

:::{exercise} Ejercicio 1c.3 - Búsqueda en Arreglo Dinámico
:label: ej-memoria-busqueda

Implementá las siguientes funciones para trabajar con un arreglo dinámico de
enteros:

``` c
int *crear_arreglo_inicializado(size_t tamano, int valor_inicial);
int buscar_elemento(const int *arreglo, size_t tamano, int valor);
int contar_ocurrencias(const int *arreglo, size_t tamano, int valor);
```
<!-- c -->

- `crear_arreglo_inicializado`: Crea un arreglo dinámico donde todos los
  elementos tienen el valor `valor_inicial`.
- `buscar_elemento`: Retorna el índice de la primera ocurrencia de `valor` en el
  arreglo, o -1 si no se encuentra.
- `contar_ocurrencias`: Retorna cuántas veces aparece `valor` en el arreglo.

Escribí un programa principal que use estas funciones para crear un arreglo,
inicializarlo, modificar algunos elementos, y luego buscar y contar ocurrencias
de valores específicos.

:::
<!-- {exercise} Ejercicio 1c.3 - Búsqueda en Arreglo Dinámico -->

:::{solution} ej-memoria-busqueda
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
/**
 * Crea un arreglo dinámico inicializado con un valor específico.
 * @param tamano Tamaño del arreglo (debe ser mayor que 0).
 * @param valor_inicial Valor con el que se inicializará cada elemento.
 * @returns Un puntero al arreglo creado. El llamador es responsable
 *          de liberar esta memoria con free().
 *          Retorna NULL si tamano es 0 o no hay memoria disponible.
 */
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
/**
 * Busca la primera ocurrencia de un valor en el arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 * @param valor Valor a buscar.
 * @returns El índice de la primera ocurrencia, o -1 si no se encuentra.
 */
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
/**
 * Cuenta cuántas veces aparece un valor en el arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 * @param valor Valor a contar.
 * @returns El número de ocurrencias del valor.
 */
int contar_ocurrencias(const int *arreglo, size_t tamano, int valor)
{
    if (arreglo == NULL)
    {
        return 0;
    }
    int contador = 0;
    for (size_t i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            contador = contador + 1;
        }
    }
    return contador;
}
int main()
{
    size_t tamano = 10;
    int valor_inicial = 5;
    int *arreglo = crear_arreglo_inicializado(tamano, valor_inicial);
    if (arreglo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el arreglo.\n");
        return 1;
    }
    printf("Arreglo inicial (todos %d): ", valor_inicial);
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    // Modificar algunos elementos
    arreglo[2] = 10;
    arreglo[5] = 10;
    arreglo[7] = 15;
    printf("Arreglo modificado: ");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    // Buscar valores
    int buscar = 10;
    int indice = buscar_elemento(arreglo, tamano, buscar);
    if (indice != -1)
    {
        printf("Primera ocurrencia de %d: índice %d\n", buscar, indice);
    }
    else
    {
        printf("No se encontró %d en el arreglo\n", buscar);
    }
    // Contar ocurrencias
    int ocurrencias = contar_ocurrencias(arreglo, tamano, buscar);
    printf("El valor %d aparece %d veces\n", buscar, ocurrencias);
    ocurrencias = contar_ocurrencias(arreglo, tamano, valor_inicial);
    printf("El valor %d aparece %d veces\n", valor_inicial, ocurrencias);
    free(arreglo);
    arreglo = NULL;
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-memoria-busqueda -->

:::{exercise} Ejercicio 1c.4 - Matriz Dinámica
:label: ej-memoria-matriz

Implementá funciones para crear y manipular una matriz dinámica de enteros de
tamaño $m \times n$:

``` c
int **crear_matriz(size_t filas, size_t columnas);
void liberar_matriz(int **matriz, size_t filas);
void imprimir_matriz(int **matriz, size_t filas, size_t columnas);
```
<!-- c -->

Asegurate de:

- Liberar la memoria en el orden correcto ({ref}`0x3009h`).
- Verificar todas las asignaciones.
- Manejar errores apropiadamente.

:::
<!-- {exercise} Ejercicio 1c.4 - Matriz Dinámica -->

:::{solution} ej-memoria-matriz
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
/**
 * Crea una matriz dinámica de enteros.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @returns Un puntero a la matriz creada. El llamador es responsable
 *          de liberar esta memoria con liberar_matriz().
 *          Retorna NULL si no hay memoria disponible.
 */
int **crear_matriz(size_t filas, size_t columnas)
{
    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = malloc(columnas * sizeof(*(matriz[i])));
        if (matriz[i] == NULL)
        {
            // Liberar las filas ya asignadas
            for (size_t j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
        // Inicializar la fila en 0
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}
/**
 * Libera una matriz dinámica.
 * @param matriz Puntero a la matriz. Puede ser NULL.
 * @param filas Número de filas de la matriz.
 */
void liberar_matriz(int **matriz, size_t filas)
{
    if (matriz == NULL)
    {
        return;
    }
    // Liberar en orden inverso: primero las filas, luego el arreglo
    for (size_t i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
/**
 * Imprime una matriz.
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @pre matriz no debe ser NULL.
 */
void imprimir_matriz(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    size_t filas = 3;
    size_t columnas = 4;
    int **matriz = crear_matriz(filas, columnas);
    if (matriz == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la matriz.\n");
        return 1;
    }
    // Llenar la matriz con valores
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = (int)(i * columnas + j);
        }
    }
    printf("Matriz %zu x %zu:\n", filas, columnas);
    imprimir_matriz(matriz, filas, columnas);
    liberar_matriz(matriz, filas);
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-memoria-matriz -->

:::{exercise} Ejercicio 1c.5 - Estructura con Memoria Dinámica
:label: ej-memoria-estructura

Implementá un tipo de dato `persona_t` que almacene información de una persona:

```{code-block} c
:linenos:
typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;
```
<!-- {code-block} c -->

Implementá las siguientes funciones:

``` c
persona_t *crear_persona(const char *nombre, const char *apellido, int edad);
void destruir_persona(persona_t *persona);
void imprimir_persona(const persona_t *persona);
```
<!-- c -->

- `crear_persona`: Debe reservar memoria para la estructura y para las cadenas
  de nombre y apellido (copiándolas).
- `destruir_persona`: Debe liberar toda la memoria asociada, incluyendo las
  cadenas internas.
- `imprimir_persona`: Debe mostrar los datos de la persona.

Recordá seguir el principio de simetría ({ref}`0x3002h`) y verificar todas las
asignaciones de memoria.

:::
<!-- {exercise} Ejercicio 1c.5 - Estructura con Memoria Dinámica -->

::::{solution} ej-memoria-estructura
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;
/**
 * Duplica una cadena en memoria dinámica verificando la precondición de que el puntero origen no sea NULL.
 * terminación en nulo.
 */
char *duplicar_cadena(const char *cadena)
{
    if (cadena == NULL)
    {
        return NULL;
    }
    size_t longitud = strlen(cadena);
    char *copia = malloc(longitud + 1);
    if (copia == NULL)
    {
        return NULL;
    }
    strcpy(copia, cadena);
    return copia;
}
/**
 * Crea una nueva persona.
 * @param nombre Nombre de la persona (no debe ser NULL).
 * @param apellido Apellido de la persona (no debe ser NULL).
 * @param edad Edad de la persona.
 * @returns Un puntero a la persona creada. El llamador es responsable
 *          de liberar esta memoria con destruir_persona().
 *          Retorna NULL si hay un error.
 */
persona_t *crear_persona(const char *nombre, const char *apellido, int edad)
{
    if (nombre == NULL || apellido == NULL)
    {
        return NULL;
    }
    persona_t *persona = malloc(sizeof(*persona));
    if (persona == NULL)
    {
        return NULL;
    }
    persona->nombre = duplicar_cadena(nombre);
    if (persona->nombre == NULL)
    {
        free(persona);
        return NULL;
    }
    persona->apellido = duplicar_cadena(apellido);
    if (persona->apellido == NULL)
    {
        free(persona->nombre);
        free(persona);
        return NULL;
    }
    persona->edad = edad;
    return persona;
}
/**
 * Destruye una persona y libera toda su memoria.
 * @param persona Puntero a la persona a destruir. Puede ser NULL.
 */
void destruir_persona(persona_t *persona)
{
    if (persona != NULL)
    {
        if (persona->nombre != NULL)
        {
            free(persona->nombre);
        }
        if (persona->apellido != NULL)
        {
            free(persona->apellido);
        }
        free(persona);
    }
}
/**
 * Imprime los datos de una persona.
 * @param persona Puntero a la persona (no debe ser NULL).
 */
void imprimir_persona(const persona_t *persona)
{
    if (persona == NULL)
    {
        return;
    }
    printf("Nombre: %s %s\n", persona->nombre, persona->apellido);
    printf("Edad: %d años\n", persona->edad);
}
int main()
{
    persona_t *p1 = crear_persona("Juan", "Pérez", 30);
    if (p1 == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la persona.\n");
        return 1;
    }
    imprimir_persona(p1);
    destruir_persona(p1);
    return 0;
}
```
<!-- {code-block} c -->

::::
<!-- {solution} ej-memoria-estructura -->

:::{exercise} Ejercicio 1c.6 - Detección de Errores de Memoria
:label: ej-memoria-errores

El siguiente programa contiene varios errores relacionados con la gestión de
memoria. Identificá todos los errores, explicá por qué son problemáticos, y
corregílos.

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int *crear_arreglo(int tamano)
{
    int *arr = malloc(tamano * sizeof(int));
    for (int i = 0; i <= tamano; i++)
    {
        arr[i] = i;
    }
    return arr;
}
void procesar_arreglo(int *arr, int tamano)
{
    free(arr);
    printf("Procesando arreglo...\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int *numeros = crear_arreglo(5);
    procesar_arreglo(numeros, 5);
    int valor = numeros[0];
    printf("Primer valor: %d\n", valor);
    free(numeros);
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {exercise} Ejercicio 1c.6 - Detección de Errores de Memoria -->

:::{solution} ej-memoria-errores
:class: dropdown

**Errores identificados:**

1. **En `crear_arreglo`:** No se verifica si `malloc` retornó `NULL`.
2. **En `crear_arreglo`:** Acceso fuera de límites en el lazo (`i <= tamano`
   debería ser `i < tamano`).
3. **En `crear_arreglo`:** Falta usar `sizeof(*arr)` en lugar de `sizeof(int)`
   para mayor robustez.
4. **En `crear_arreglo`:** Se debería usar `size_t` para `tamano` en lugar de
   `int`.
5. **En `procesar_arreglo`:** Se libera la memoria al principio y luego se
   intenta acceder a ella (uso después de `free`).
6. **En `main`:** Se accede a `numeros` después de que fue liberado en
   `procesar_arreglo` (puntero colgante).
7. **En `main`:** Doble liberación: se llama a `free(numeros)` dos veces (una en
   `procesar_arreglo` y otra en `main`).
8. **En `main`:** No se establece `numeros = NULL` después de liberar.

**Código corregido:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
/**
 * Crea un arreglo dinámico inicializado con valores secuenciales.
 * @param tamano Tamaño del arreglo (debe ser mayor que 0).
 * @returns Un puntero al arreglo creado, o NULL si hay un error.
 */
int *crear_arreglo(size_t tamano)
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
/**
 * Procesa un arreglo imprimiendo sus elementos.
 * @param arr Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 */
void procesar_arreglo(const int *arr, size_t tamano)
{
    if (arr == NULL)
    {
        return;
    }
    printf("Procesando arreglo...\n");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    size_t tamano = 5;
    int *numeros = crear_arreglo(tamano);
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el arreglo.\n");
        return 1;
    }
    procesar_arreglo(numeros, tamano);
    int valor = numeros[0];
    printf("Primer valor: %d\n", valor);
    free(numeros);
    numeros = NULL;
    return 0;
}
```
<!-- {code-block} c -->

**Cambios realizados:**

- Se agregó verificación de `malloc`.
- Se corrigió el lazo para evitar acceso fuera de límites.
- Se cambió `int` por `size_t` para tamaños.
- Se usó `sizeof(*arr)` en lugar de `sizeof(int)`.
- Se removió el `free` de `procesar_arreglo` (violaba el principio de
  responsabilidad única).
- Se marcó el parámetro de `procesar_arreglo` como `const` para indicar que no
  modifica el arreglo.
- Se agregó `numeros = NULL` después de liberar.
- Se agregó verificación de que `numeros` no es `NULL` antes de usarlo.

:::
<!-- {solution} ej-memoria-errores -->

```

::::{exercise} Ejercicio 1c.7 - Matriz Contígua con Puntero a Array
:label: ej-memoria-puntero-array

Implementá funciones para crear y manipular una matriz dinámica contigua usando
un puntero plano (`int *`):

````{code-block} c
:linenos:
// Crear matriz de N filas y M columnas (contígua en memoria)
int *crear_matriz_contigua(size_t filas, size_t columnas);
// Llenar la matriz con un patrón: matriz[i * columnas + j] = i * columnas + j
void llenar_matriz(int *matriz, size_t filas, size_t columnas);
// Imprimir la matriz
void imprimir_matriz_contigua(const int *matriz, size_t filas,
                              size_t columnas);
// Transponer la matriz in-place (solo para matrices cuadradas)
void transponer_cuadrada(int *matriz, size_t n);
````
<!-- {code-block} c -->

Requisitos:

- Toda la memoria debe asignarse en un solo bloque contiguo en el heap.
- Debe liberarse con una sola llamada a `free`.
- El acceso a los elementos en la fila `i` y columna `j` debe realizarse
  mediante cálculo manual de índices: `i * columnas + j`.
- La función `transponer_cuadrada` debe intercambiar el elemento en `(i, j)` con
  el de `(j, i)`.

Escribí un programa principal que:

1. Cree una matriz 4×4 contígua.
2. La llene con valores.
3. La imprima.
4. La transponga.
5. La imprima nuevamente.
6. Libere correctamente la memoria.

::::
<!-- {exercise} Ejercicio 1c.7 - Matriz Contígua con Puntero a Array -->

::::{solution} ej-memoria-puntero-array
:class: dropdown

````{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
/**
 * Crea una matriz dinámica contigua usando un puntero plano.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @returns Un puntero plano que apunta a la matriz, o NULL si hay error.
 */
int *crear_matriz_contigua(size_t filas, size_t columnas)
{
    // Asignar memoria contígua para todos los elementos (filas * columnas)
    int *matriz = malloc(filas * columnas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }
    // Inicializar a cero
    for (size_t i = 0; i < filas * columnas; i++)
    {
        matriz[i] = 0;
    }
    return matriz;
}
/**
 * Llena la matriz con el patrón: matriz[i * columnas + j] = i * columnas + j
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 */
void llenar_matriz(int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i * columnas + j] = (int)(i * columnas + j);
        }
    }
}
/**
 * Imprime la matriz.
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 */
void imprimir_matriz_contigua(const int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i * columnas + j]);
        }
        printf("\n");
    }
}
/**
 * Transpone una matriz cuadrada in-place.
 * @param matriz Puntero a la matriz cuadrada (no debe ser NULL).
 * @param n Tamaño de la matriz (n×n).
 */
void transponer_cuadrada(int *matriz, size_t n)
{
    if (matriz == NULL)
    {
        return;
    }
    // Intercambiar matriz[i * n + j] con matriz[j * n + i]
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            int temp = matriz[i * n + j];
            matriz[i * n + j] = matriz[j * n + i];
            matriz[j * n + i] = temp;
        }
    }
}
int main()
{
    size_t n = 4; // Matriz 4×4
    // Crear matriz contígua
    int *matriz = crear_matriz_contigua(n, n);
    if (matriz == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la matriz.\n");
        return 1;
    }
    // Llenar con patrón
    llenar_matriz(matriz, n, n);
    printf("Matriz original %zu×%zu:\n", n, n);
    imprimir_matriz_contigua(matriz, n, n);
    // Transponer
    transponer_cuadrada(matriz, n);
    printf("\nMatriz transpuesta:\n");
    imprimir_matriz_contigua(matriz, n, n);
    // Verificar la transposición
    printf("\nVerificación:\n");
    printf("Elemento [0][1] (era 1, ahora debe ser 4): %d\n",
           matriz[0 * n + 1]);
    printf("Elemento [1][0] (era 4, ahora debe ser 1): %d\n", mocesar_heap()
{
        int *datos = malloc(1000 * sizeof(int)); // Llamada a función
        if (datos == NULL)
            return;
        // Posiblemente más cache misses:
        for (int i = 0; i < 1000; i++)
        {
            datos[i] = i * 2; // Menos predecible para el hardware
        }
        free(datos); // Otra llamada a función
}
````
<!-- {code-block} c -->

En un benchmark real, la versión stack podría ser 2-5 veces más rápida,
especialmente para arreglos pequeños que caben completamente en caché.

:::{note} Optimización

Práctica Comprender el caché te permite optimizar código:

````{code-block} c
:linenos:
// Malo: Recorrer matriz por columnas (pobre localidad)
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        matriz[i][j] = 0; // Saltos grandes en memoria
// Bueno: Recorrer por filas (buena localidad)
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        matriz[i][j] = 0; // Acceso secuencial
````
<!-- {code-block} c -->

La segunda versión puede ser 10-50 veces más rápida para matrices grandes,
simplemente porque usa mejor el caché.

:::
<!-- {note} Optimización -->

(memoria-fragmentacion)=
### Fragmentación de Memoria

La fragmentación es un fenómeno que ocurre cuando el heap contiene bloques
libres pequeños dispersos que no pueden satisfacer solicitudes de memoria más
grandes, incluso si la suma total de memoria libre sería suficiente.

Imaginá que tenés un estante con espacios libres dispersos de diferentes
tamaños. Aunque la suma total de espacio libre sea grande, si necesitás colocar
un libro grande y solo tenés espacios pequeños separados, no podrás hacerlo. Lo
mismo ocurre con la memoria.

**Fragmentación Externa:** Espacios libres entre bloques asignados que son
demasiado pequeños para ser útiles individualmente. Ocurre cuando asignás y
liberás bloques de memoria de diferentes tamaños en un orden arbitrario, dejando
"huecos" entre bloques ocupados.

**Ejemplo conceptual:**

:::{figure} ../../apunte/bloque_2_memoria/5/fragmentacion_externa.svg
:name: fig-fragmentacion-externa
:width: 100%

Proceso de fragmentación externa: se asignan tres bloques (A, B, C), luego se
libera B dejando un hueco. Ahora hay dos bloques libres separados, pero ninguno
puede satisfacer una solicitud del tamaño de A+B.

:::
<!-- {figure} ../../apunte/bloque_2_memoria/5/fragmentacion_externa.svg -->

Ahora hay dos bloques libres, pero si necesitás un bloque del tamaño de A+B, no
podés usar el espacio libre entre A y C.

**Fragmentación Interna:** Desperdicio de memoria dentro de un bloque asignado
cuando se solicita menos de lo que el sistema asigna. Algunos sistemas asignan
memoria en múltiplos de cierto tamaño (por ejemplo, bloques de 16 bytes),
entonces si pedís 10 bytes, te dan 16 y los 6 extra se desperdician.

**Cómo minimizar la fragmentación:**

- Liberá memoria en el orden inverso al que la asignaste cuando sea posible.
- Usá tamaños consistentes para asignaciones frecuentes.
- Considerá usar memory pools para objetos de tamaño fijo (tema avanzado).

(memoria-alineacion)=
### Alineación de Memoria

La alineación de memoria es un concepto fundamental que afecta tanto el
rendimiento como la corrección de los programas. Comprender por qué existe y
cómo funciona te permite escribir código más eficiente.

**¿Qué es la alineación?**

Un dato está **alineado** cuando su dirección de memoria es un múltiplo de su
tamaño. Por ejemplo:

- Un `char` (1 byte) puede estar en cualquier dirección.
- Un `short` (2 bytes) debería estar en direcciones múltiplo de 2.
- Un `int` (4 bytes) debería estar en direcciones múltiplo de 4.
- Un `double` (8 bytes) debería estar en direcciones múltiplo de 8.

:::{figure} ../../apunte/bloque_2_memoria/5/memory_alignment.svg
:name: fig-memory-alignment
:width: 100%

Comparación entre memoria bien alineada (donde cada int comienza en un múltiplo
de 4) y mal alineada (causando penalización de rendimiento). El acceso alineado
requiere una sola lectura del CPU, mientras que el desalineado requiere
múltiples lecturas y manipulación de bits.

:::
<!-- {figure} ../../apunte/bloque_2_memoria/5/memory_alignment.svg -->

**¿Por qué importa la alineación?**

Los procesadores modernos leen memoria en bloques (palabras) de tamaño fijo,
típicamente 4 u 8 bytes a la vez. Si un dato no está alineado:

1. **Penalización de rendimiento:** El CPU debe hacer múltiples lecturas y
   combinarlas con operaciones de bits. Una lectura alineada toma 1 operación,
   mientras que una desalineada puede tomar 2 operaciones más manipulación
   adicional (2-3x más lento).

2. **En algunas arquitecturas, causa errores:** ARM en modo estricto y algunos
   procesadores RISC generan excepciones de alineación.

3. **Operaciones atómicas:** Muchas instrucciones atómicas (necesarias para
   multithreading) requieren alineación natural.

**Alineación en estructuras:**

El compilador inserta "padding" (bytes de relleno) para mantener la alineación:

````{code-block} c
:linenos:
struct ejemplo
{
    char a; // 1 byte
    // 3 bytes de padding insertados automáticamente
    int b;  // 4 bytes (debe estar en múltiplo de 4)
    char c; // 1 byte
    // 3 bytes de padding al final para el arreglo
};
// sizeof(struct ejemplo) = 12, no 6
````
<!-- {code-block} c -->

**Visualización:**

:::{figure} ../../apunte/bloque_2_memoria/5/struct_padding.svg
:name: fig-struct-padding
:width: 100%

Comparación entre una estructura sin padding (incorrecta con desalineación) y
con padding (correcta con alineación apropiada). El compilador inserta bytes de
relleno para mantener la alineación de los campos.

:::
<!-- {figure} ../../apunte/bloque_2_memoria/5/struct_padding.svg -->

**Optimizar estructuras:**

Podés minimizar el padding ordenando los campos de mayor a menor:

````{code-block} c
:linenos:
// Desperdicia espacio (16 bytes):
struct ineficiente
{
    char a; // 1 byte
    int b;  // 4 bytes (+ 3 padding antes)
    char c; // 1 byte (+ 3 padding después)
};
// Más eficiente (8 bytes):
struct eficiente
{
    int b;  // 4 bytes
    char a; // 1 byte
    char c; // 1 byte
    // 2 bytes padding al final (menos que antes)
};
````
<!-- {code-block} c -->

**Verificar alineación:**

````{code-block} c
:linenos:
#include <stddef.h>
#include <stdio.h>
struct prueba
{
    char a;
    int b;
    char c;
};
int main()
{
    printf("Tamaño de struct: %zu\n", sizeof(struct prueba));
    printf("Offset de 'a': %zu\n", offsetof(struct prueba, a));
    printf("Offset de 'b': %zu\n", offsetof(struct prueba, b));
    printf("Offset de 'c': %zu\n", offsetof(struct prueba, c));
    return 0;
}
````
<!-- {code-block} c -->

**malloc y alineación:**

Las funciones de asignación de memoria (`malloc` y `calloc`) garantizan que la
memoria devuelta está adecuadamente alineada para cualquier tipo de dato
estándar. Típicamente retornan direcciones alineadas a 8 o 16 bytes, lo cual
satisface los requisitos de todos los tipos básicos.

````{code-block} c
:linenos:
int *p = malloc(sizeof(int));
// p está garantizado como alineado para 'int'
struct grande
{
    double d; // Necesita alineación de 8 bytes
    long l;
};
struct grande *s = malloc(sizeof(*s));
// s está garantizado como alineado para todos los campos
````
<!-- {code-block} c -->

:::{note} Packed Structures

Podés forzar al compilador a no insertar padding usando atributos específicos
del compilador:

````{code-block} c
:linenos:
struct __attribute__((packed)) sin_padding
{
    char a;
    int b; // Puede estar desalineado
    char c;
};
// sizeof = 6, pero acceso más lento a 'b'
````
<!-- {code-block} c -->

Esto es útil para formatos de archivos binarios o protocolos de red, pero reduce
el rendimiento. Usalo solo cuando la compatibilidad binaria es más importante
que la velocidad.

:::
<!-- {note} Packed Structures -->

(memoria-valgrind)=

### Herramientas de Depuración: Valgrind

Valgrind es una herramienta fundamental para detectar errores de memoria en
programas C y C++. Funciona ejecutando tu programa en un entorno virtualizado
donde puede monitorear cada acceso a memoria y operación de
asignación/liberación.

**Tipos de errores que detecta:**

- **Fugas de memoria (memory leaks):** Bloques de memoria asignados que nunca
  fueron liberados.
- **Accesos a memoria no inicializada:** Leer valores de memoria que nunca
  fueron escritos.
- **Accesos fuera de límites:** Leer o escribir más allá de los límites de un
  bloque asignado.
- **Dobles liberaciones:** Intentar liberar el mismo bloque dos veces.
- **Uso de memoria después de `free`:** Acceder a memoria que ya fue liberada.
- **Desajustes entre asignación y liberación:** Por ejemplo, asignar con
  `malloc` y liberar con `delete` (en C++).

**Uso básico:**

```` bash
# Compilar con símbolos de depuración
gcc -g -o programa programa.c

# Ejecutar con Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./programa
````
<!-- bash -->

**Opciones útiles:**

- `--leak-check=full`: Muestra detalles completos de las fugas de memoria.
- `--show-leak-kinds=all`: Muestra todos los tipos de fugas.
- `--track-origins=yes`: Rastrea el origen de valores no inicializados (más
  lento pero útil).
- `--verbose`: Muestra información adicional de depuración.

**Interpretando la salida:**

Cuando Valgrind detecta un error, muestra:

- El tipo de error
- La ubicación en el código (archivo y línea)
- El stack trace (secuencia de llamadas que llevó al error)
- Para fugas de memoria: dónde se asignó el bloque que no fue liberado

**Ejemplo de salida:**

````
==12345== Invalid write of size 4
==12345==    at 0x108A: main (programa.c:15)
==12345==  Address 0x522d068 is 0 bytes after a block of size 40 alloc'd
````

Esto indica que se intentó escribir 4 bytes fuera de un bloque de 40 bytes
asignado, en la línea 15 del archivo `programa.c`.

:::{important} Desarrollo Profesional

En un entorno profesional, es inaceptable entregar código con errores de
memoria. El uso de herramientas como Valgrind durante el desarrollo no es
opcional, es una práctica estándar de la industria. Acostumbrate a ejecutar
Valgrind regularmente durante el desarrollo, no solo cuando sospechás que hay un
problema.

:::
<!-- {important} Desarrollo Profesional -->

La segunda versión puede ser 10-100 veces más rápida.

**2. La localidad de acceso importa enormemente:**

````{code-block} c
:linenos:
// Malo: Acceso aleatorio (muchos cache misses)
for (int i = 0; i < n; i++)
{
    int idx = random_index();
    data[idx] = process(data[idx]); // Impredecible para el caché
}
// Bueno: Acceso secuencial (cache hits)
for (int i = 0; i < n; i++)
{
    data[i] = process(data[i]); // Predecible, alta localidad
}
````
<!-- {code-block} c -->

**3. El tamaño de la estructura de datos importa:**

````{code-block} c
:linenos:
// Si tu estructura cabe en caché L1 (32 KB):
struct pequena datos[1000]; // 4 KB total, cabe en L1
// Acceso muy rápido, todo en caché
// Si excede la caché L3 (8 MB):
struct grande datos[1000000]; // 100 MB, no cabe
// Muchos accesos a RAM, más lento
````
<!-- {code-block} c -->

**4. El costo de la indirección:**

````{code-block} c
:linenos:
// Un nivel de indirección:
int *ptr = malloc(sizeof(int));
*ptr = 42; // Lee ptr, luego lee *ptr (2 accesos potenciales a RAM)
// Dos niveles de indirección:
int **ptr2 = malloc(sizeof(int *));
*ptr2 = malloc(sizeof(int));
**ptr2 = 42; // Lee ptr2, luego *ptr2, luego **ptr2 (3 accesos)
// Directo (sin indirección):
int valor = 42; // Puede estar en registro, cero accesos a memoria
````
<!-- {code-block} c -->

**Ejemplo cuantitativo:**

Considerá procesar un millón de elementos:

````{code-block} c
:linenos:
// Opción A: Arreglo continuo (stack o heap)
int arreglo[1000000];
for (int i = 0; i < 1000000; i++)
{
    arreglo[i] = i * 2;
}
// Costo: ~1 millón de escrituras secuenciales
// Cache: Muy efectivo (prefetching automático)
// Tiempo: ~1-2 ms en un CPU moderno
// Opción B: Lista enlazada (heap)
struct nodo *lista = crear_lista(1000000);
struct nodo *actual = lista;
int i = 0;
while (actual != NULL)
{
    actual->valor = i * 2;
    actual = actual->siguiente; // Sigue puntero (indirección)
    i++;
}
// Costo: ~1 millón de escrituras + 1 millón de lecturas de punteros
// Cache: Malo (los nodos están dispersos)
// Tiempo: ~5-20 ms (3-10x más lento)
````
<!-- {code-block} c -->

**Estrategias de optimización basadas en el modelo de costos:**

1. **Minimizá asignaciones dinámicas:** Usá stack cuando sea posible, o pooling
   de memoria.

2. **Maximizá localidad:** Mantené datos relacionados físicamente juntos.

3. **Reducí indirección:** Preferí arreglos sobre listas enlazadas cuando el
   acceso aleatorio es importante.

4. **Batch operations:** Procesá múltiples elementos antes de saltar a otra
   región de memoria.

5. **Considerá el cache line size:** Operá en bloques de ~64 bytes cuando sea
   posible.

:::{important} Profiling sobre Intuición

Aunque este modelo proporciona intuición valiosa, siempre **medí** antes de
optimizar. Usa herramientas de profiling como `perf`, `gprof`, o `Valgrind
--tool=cachegrind` para identificar cuellos de botella reales. La optimización
prematura basada en intuición puede hacer el código más complejo sin beneficios
reales.

:::
<!-- {important} Profiling sobre Intuición -->

