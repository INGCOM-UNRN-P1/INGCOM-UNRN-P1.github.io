---
title: Ejercicios de Memoria Dinámica
short_title: 6. Memoria Dinámica
---

# Ejercicios de Memoria Dinámica

## Acerca de

A diferencia de la memoria estática (stack), la memoria dinámica (heap) nos
permite solicitar y liberar bloques de memoria en tiempo de ejecución en C11, cuyo
tamaño puede no ser conocido al momento de compilar. Estos ejercicios se centran
en el uso correcto de `malloc`, `calloc`, `realloc` y `free` para gestionar el
ciclo de vida de arreglos, cadenas y matrices.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-memoria-dinamica`
- {ref}`capitulo-punteros`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Memoria Heap frente a memoria Stack: ciclo de vida manual vs automático ({ref}`capitulo-memoria-dinamica`).
2. Funciones de asignación (`malloc`, `calloc`, `realloc`) y verificación de puntero nulo (`NULL`).
3. Liberación simétrica y completa con `free` y anulación de puntero (*dangling pointer prevention*).
4. Detección de fugas de memoria (*memory leaks*) y accesos inválidos (*use-after-free*).

### Cuestiones de Estilo Aplicables
- **Verificación de Retorno:** Siempre se debe comprobar que el retorno de
  `malloc` o `realloc` sea distinto de `NULL` antes de desreferenciarlo ({ref}`0x3001h`).
- **Liberación Segura:** Tras liberar un bloque con `free(ptr)`, asigná `ptr = NULL`
  para mitigar referencias colgantes ({ref}`0x3002h`).

---

## Arreglos Dinámicos

(ej_b2_c05_01)=
### Ejercicio 2.05.01 - Ciclo de Vida de Arreglo Dinámico ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c05_01_ciclo_vida

Implementá un par de funciones para la gestión del ciclo de vida de un arreglo dinámico:
1. `int *crear_arreglo_dinamico(size_t n)`: reserva memoria contigua inicializada
   en cero para `n` enteros usando `calloc`. Retorna `NULL` ante fallos de memoria.
2. `void destruir_arreglo_dinamico(int **arr)`: libera el bloque y asigna `NULL`
   al puntero del llamador para prevenir punteros colgantes.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Tamaño `n` | Retorno | Estado Post-Destrucción |
| :--- | :--- | :--- | :--- |
| Creación exitosa | `5` | Puntero válido no nulo, valores en 0 | `*arr == NULL` |
| Tamaño cero | `0` | Puntero o `NULL` manejado sin error | `*arr == NULL` |
| Puntero nulo | - | No produce caída (*graceful return*) | Inalterado |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *crear_arreglo_dinamico(size_t n) {
    if (n == 0) {
        return NULL;
    }
    return (int *)calloc(n, sizeof(int));
}

void destruir_arreglo_dinamico(int **arr) {
    if (arr != NULL && *arr != NULL) {
        free(*arr);
        *arr = NULL;
    }
}

int main(void) {
    int *arr = crear_arreglo_dinamico(5);
    assert(arr != NULL);
    for (size_t i = 0; i < 5; ++i) {
        assert(arr[i] == 0);
        arr[i] = (int)(i * 10);
    }
    assert(arr[4] == 40);

    destruir_arreglo_dinamico(&arr);
    assert(arr == NULL);

    /* Destrucción redundante segura */
    destruir_arreglo_dinamico(&arr);
    destruir_arreglo_dinamico(NULL);

    return 0;
}
```
::::
:::

(ej_b2_c05_02)=
### Ejercicio 2.05.02 - Duplicación de Arreglo en Heap ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c05_02_duplicar

Implementá una función que cree una copia exacta e independiente en memoria dinámica
de un arreglo recibido.

```c
int *duplicar_arreglo_dinamico(const int *origen, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo Origen | `n` | Copia Retornada | Comportamiento |
| :--- | :--- | :--- | :--- |
| `[10, 20, 30]` | `3` | Puntero a nuevo bloque con `[10, 20, 30]` | Memoria independiente |
| `NULL` o vacío | `0` | `NULL` | Retorno seguro |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *duplicar_arreglo_dinamico(const int *origen, size_t n) {
    if (origen == NULL || n == 0) {
        return NULL;
    }
    int *copia = (int *)malloc(n * sizeof(int));
    if (copia == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < n; ++i) {
        copia[i] = origen[i];
    }
    return copia;
}

int main(void) {
    int orig[] = {10, 20, 30};
    int *clon = duplicar_arreglo_dinamico(orig, 3);
    assert(clon != NULL);
    assert(clon != orig);
    for (size_t i = 0; i < 3; ++i) {
        assert(clon[i] == orig[i]);
    }

    clon[0] = 999;
    assert(orig[0] == 10); /* Verificación de independencia */

    free(clon);
    assert(duplicar_arreglo_dinamico(NULL, 5) == NULL);
    return 0;
}
```
::::
:::

(ej_b2_c05_03)=
### Ejercicio 2.05.03 - Fusión de Arreglos Ordenados en Heap ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c05_03_fusion

Implementá una función que tome dos arreglos ordenados ascendentemente y retorne
un nuevo bloque dinámico conteniendo todos los elementos fusionados en orden.

```c
int *fusionar_arreglos_ordenados(const int *a1, size_t n1, const int *a2, size_t n2);
```

**Tabla de Vectores de Prueba:**

| Arreglo 1 | Arreglo 2 | Resultado Fusionado |
| :--- | :--- | :--- |
| `[1, 5, 9]` | `[2, 4, 8, 10]` | `[1, 2, 4, 5, 8, 9, 10]` |
| `[10, 20]` | `[]` | `[10, 20]` |
| `[]` | `[3, 7]` | `[3, 7]` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *fusionar_arreglos_ordenados(const int *a1, size_t n1, const int *a2, size_t n2) {
    size_t total = n1 + n2;
    if (total == 0) {
        return NULL;
    }
    int *res = (int *)malloc(total * sizeof(int));
    if (res == NULL) {
        return NULL;
    }
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            res[k++] = a1[i++];
        } else {
            res[k++] = a2[j++];
        }
    }
    while (i < n1) {
        res[k++] = a1[i++];
    }
    while (j < n2) {
        res[k++] = a2[j++];
    }
    return res;
}

int main(void) {
    int a1[] = {1, 5, 9};
    int a2[] = {2, 4, 8, 10};
    int *fus = fusionar_arreglos_ordenados(a1, 3, a2, 4);
    assert(fus != NULL);
    int esp[] = {1, 2, 4, 5, 8, 9, 10};
    for (size_t idx = 0; idx < 7; ++idx) {
        assert(fus[idx] == esp[idx]);
    }
    free(fus);

    int *fus2 = fusionar_arreglos_ordenados(a1, 3, NULL, 0);
    assert(fus2 != NULL && fus2[0] == 1 && fus2[1] == 5 && fus2[2] == 9);
    free(fus2);

    return 0;
}
```
::::
:::

(ej_b2_c05_04)=
### Ejercicio 2.05.04 - Inserción Dinámica Defensiva con Realloc ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c05_04_insercion_dinamica
:enumerator: memoria-dinamica-4

Implementá una función defensiva que inserte un nuevo elemento en cualquier posición de un arreglo en el heap, redimensionándolo dinámicamente:
```c
bool arreglo_dinamico_insertar(int **arr, size_t *tam, size_t pos, int valor);
```
Debés:
1. Validar que los punteros sean válidos y que `pos <= *tam`.
2. Asignar un nuevo búfer con `realloc` utilizando una variable temporal para no perder la referencia previa en caso de fallo.
3. Desplazar los elementos existentes desde `pos` hacia la derecha utilizando `memmove` (evitando solapamientos no definidos).
4. Escribir `valor` en la posición `pos` e incrementar `*tam`.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Puntero doble `int **`, realocación defensiva sin fugas de memoria, `memmove` para regiones superpuestas.  
**Techo conceptual:** Prohibido reasignar directamente el puntero original con `*arr = realloc(*arr, ...)` sin validar el retorno.

#### Contrato de la Función
- **Firma:** `bool arreglo_dinamico_insertar(int **arr, size_t *tam, size_t pos, int valor);`
- **Precondiciones:** `arr != NULL`, `tam != NULL`, `pos <= *tam`.
- **Postcondiciones:** Retorna `true` y actualiza el arreglo; si falla la asignación o los parámetros son inválidos retorna `false` y preserva la memoria original intacta.

#### Tabla de Vectores de Prueba

| Estado Inicial | Posición / Valor | Retorno | Arreglo Resultante | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| `[10, 30]`, tam=2 | `pos=1, val=20` | `true` | `[10, 20, 30]`, tam=3 | Inserción en posición intermedia |
| `[10, 20]`, tam=2 | `pos=0, val=5` | `true` | `[5, 10, 20]`, tam=3 | Inserción al inicio con desplazamiento completo |
| `[10, 20]`, tam=2 | `pos=2, val=99` | `true` | `[10, 20, 99]`, tam=3 | Inserción al final sin desplazamiento |
| `NULL`, tam=0 | `pos=0, val=42` | `true` | `[42]`, tam=1 | Inserción inicial en arreglo vacío |
| `[10]`, tam=1 | `pos=5, val=100` | `false` | `[10]`, tam=1 | Rechazo seguro de posición fuera de rango |

:::

::::{solution} ej_b2_c05_04_insercion_dinamica
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool arreglo_dinamico_insertar(int **arr, size_t *tam, size_t pos, int valor)
{
    if (arr == NULL || tam == NULL || pos > *tam)
    {
        return false;
    }

    size_t nuevo_tam = *tam + 1;
    int *nuevo_bloque = (int *)realloc(*arr, nuevo_tam * sizeof(int));
    if (nuevo_bloque == NULL)
    {
        return false;
    }

    *arr = nuevo_bloque;

    // Desplazar elementos desde 'pos' hacia la derecha si no se inserta al final
    if (pos < *tam)
    {
        size_t elementos_a_mover = *tam - pos;
        memmove(&(*arr)[pos + 1], &(*arr)[pos], elementos_a_mover * sizeof(int));
    }

    (*arr)[pos] = valor;
    *tam = nuevo_tam;
    return true;
}

int main(void)
{
    int *arr = NULL;
    size_t tam = 0;

    // Inserción en vacío
    assert(arreglo_dinamico_insertar(&arr, &tam, 0, 10) == true);
    assert(tam == 1 && arr[0] == 10);

    // Inserción al final
    assert(arreglo_dinamico_insertar(&arr, &tam, 1, 30) == true);
    assert(tam == 2 && arr[0] == 10 && arr[1] == 30);

    // Inserción en el medio
    assert(arreglo_dinamico_insertar(&arr, &tam, 1, 20) == true);
    assert(tam == 3 && arr[0] == 10 && arr[1] == 20 && arr[2] == 30);

    // Inserción al inicio
    assert(arreglo_dinamico_insertar(&arr, &tam, 0, 5) == true);
    assert(tam == 4 && arr[0] == 5 && arr[1] == 10 && arr[2] == 20 && arr[3] == 30);

    // Caso inválido: posición fuera de rango
    assert(arreglo_dinamico_insertar(&arr, &tam, 99, 100) == false);
    assert(tam == 4);

    free(arr);
    return 0;
}
```

::::
<!-- {solution} ej_b2_c05_04_insercion_dinamica -->

## Cadenas Dinámicas

(ej_b2_c05_05)=
### Ejercicio 2.05.05 - Concatenación dinámica ⭐⭐⭐☆☆

Implementar `char* concatenar(const char *s1, const char *s2)`. **Algoritmo:**

1.  Calcular la longitud total necesaria: `strlen(s1) + strlen(s2) + 1` (para el
    `\0`).
2.  Reservar memoria con `malloc` para este tamaño.
3.  Copiar la primera cadena (`s1`) al nuevo bloque.
4.  Concatenar la segunda cadena (`s2`) al final.

(ej_b2_c05_06)=
### Ejercicio 2.05.06 - Deduplicador ⭐⭐☆☆☆

Implementar `char* deduplicar(const char *s)`. Como el tamaño final es
desconocido, una estrategia de dos pasadas es robusta:

1.  **Primera pasada**: Recorrer la cadena `s` con un arreglo auxiliar de
    contadores para determinar el número de caracteres únicos y, por lo tanto,
    el tamaño de la cadena resultante.
2.  **Segunda pasada**: Reservar memoria del tamaño exacto y construir la nueva
    cadena solo con los caracteres únicos.

(ej_b2_c05_07)=
### Ejercicio 2.05.07 - Fraccionador (Tokenizer) ⭐⭐☆☆☆

Implementar `char** dividir_cadena(const char *s, int *n_palabras)`. Esta
función devuelve un arreglo de punteros, donde cada puntero apunta a una palabra
alojada dinámicamente.

:::{mermaid}

flowchart TD
    subgraph Heap
        H["Hola"]
        M["Mundo"]
    end
    subgraph "Arreglo de Punteros"
        P1["ptr[0]"]
        P2["ptr[1]"]
        P3["ptr[2]"]
    end
    Main["char** resultado"] --> P1
    P1 --> H
    P2 --> M
    P3 --> NUL["NULL"]

:::
<!-- {mermaid} -->

**Algoritmo:**

1.  Contar el número de palabras para saber el tamaño del arreglo `char**`.
2.  Reservar memoria para este arreglo de punteros.
3.  Volver a recorrer la cadena original. Por cada palabra encontrada: a.
    Calcular su longitud. b. Reservar memoria para esa palabra. c. Copiar los
    caracteres de la palabra. d. Asignar el puntero a la nueva palabra en el
    arreglo de punteros.
4.  Terminar el arreglo de punteros con un `NULL` para facilitar su recorrido.

## Matrices Dinámicas

(ej_b2_c05_08)=
### Ejercicio 2.05.08 - Ciclo de vida ⭐⭐☆☆☆

Implementar funciones para reservar y liberar una matriz `m x n` usando un
arreglo de punteros.

- **Reserva**: Se realiza en dos etapas. Primero se reserva el arreglo de
  punteros a las filas, y luego, en un lazo, se reserva la memoria para cada
  fila individual.
- **Liberación**: Debe seguir el orden inverso. Primero, en un lazo, se libera
  la memoria de cada fila, y finalmente se libera el arreglo que contenía los
  punteros a las filas.

(ej_b2_c05_09)=
### Ejercicio 2.05.09 - Multiplicación ⭐⭐☆☆☆

Implementar `int** multiplicar(int **A, int m, int n, int **B, int p, int q)`.
**Algoritmo:**

1.  Verificar que la multiplicación sea posible ($n$ debe ser igual a $p$). 
2.  Reservar memoria para una nueva matriz `C` de dimensiones $m \times q$.
3.  Aplicar el algoritmo de multiplicación de matrices para calcular cada
    elemento $c_{ij}$ y almacenarlo en la nueva matriz. $$ c_{ij} =
    \sum_{k=1}^{n} a_{ik} \cdot b_{kj} $$
4.  Retornar el puntero a la matriz `C`.

(ej_b2_c05_10)=
## Ejercicio 2.05.10 - s Adicionales ⭐⭐☆☆☆

(ej_b2_c05_11)=
### Ejercicio 2.05.11 - Redimensionar Arreglo ⭐⭐⭐☆☆

Implementar una función `int* redimensionar_arreglo(int* arr, size_t
nuevo_tamano)` que utilice `realloc` para cambiar el tamaño de un arreglo
dinámico. La función debe manejar tanto la expansión como la contracción del
arreglo y gestionar posibles fallos de `realloc`.

(ej_b2_c05_12)=
### Ejercicio 2.05.12 - Vector de Crecimiento Dinámico ⭐⭐⭐☆☆

Implementar una estructura `vector_t` que simule un `std::vector` de C++. Debe
contener un puntero a los datos, un tamaño (`size`) y una capacidad
(`capacity`). Crear funciones para:
- `vector_crear()`: Inicializa un vector vacío.
- `vector_push_back(vector_t* v, int dato)`: Añade un elemento al final. Si
  `size == capacity`, debe duplicar la capacidad usando `realloc`.
- `vector_destruir(vector_t* v)`: Libera toda la memoria.

(ej_b2_c05_13)=
### Ejercicio 2.05.13 - Leer Archivo a Cadena Dinámica ⭐⭐⭐☆☆

Escribir una función `char* leer_archivo_completo(const char* ruta)` que lea
todo el contenido de un archivo de texto y lo devuelva en una única cadena
alojada dinámicamente. El tamaño del archivo no se conoce de antemano.

(ej_b2_c05_14)=
### Ejercicio 2.05.14 - Matriz Triangular Dinámica ⭐⭐⭐☆☆

Crear una función que reserve memoria para una matriz triangular inferior. Cada
fila `i` debe tener `i+1` columnas. La función debe devolver un `int**` y se
debe implementar su correspondiente función de liberación.

(ej_b2_c05_15)=
### Ejercicio 2.05.15 - strdup Propio ⭐⭐☆☆☆

Implementar su propia versión de la función no estándar `strdup`, que recibe una
cadena y devuelve un puntero a una nueva cadena en memoria dinámica con el mismo
contenido.

`char* mi_strdup(const char* s);`

(ej_b2_c05_16)=
### Ejercicio 2.05.16 - calloc vs. malloc ⭐⭐☆☆☆

Escribir un programa que reserve dos arreglos de enteros del mismo tamaño, uno
con `malloc` y otro con `calloc`. Imprimir el contenido de ambos arreglos
inmediatamente después de la reserva para demostrar que `calloc` inicializa la
memoria a cero.

(ej_b2_c05_17)=
### Ejercicio 2.05.17 - Concatenar Múltiples Cadenas ⭐⭐⭐☆☆

Escribir una función `char* concatenar_muchas(char** cadenas, int n_cadenas)`
que reciba un arreglo de cadenas y las una todas en una sola cadena dinámica,
separadas por un espacio.

(ej_b2_c05_18)=
### Ejercicio 2.05.18 - Clonación Profunda de Struct ⭐⭐⭐☆☆

Definir una `struct` que contenga miembros de tipo puntero (ej. `char* nombre`,
`int* notas`). Escribir una función de "clonación profunda" que cree una copia
completamente nueva e independiente de la `struct`, incluyendo la reserva de
nueva memoria para los datos a los que apuntan los punteros.

(ej_b2_c05_19)=
### Ejercicio 2.05.19 - Particionar Arreglo Dinámicamente ⭐⭐⭐☆☆

Escribir una función que reciba un arreglo dinámico y lo divida en dos nuevos
arreglos dinámicos: uno con los números pares y otro con los impares. La función
debe devolver estos dos nuevos arreglos (por ejemplo, a través de punteros por
referencia).

(ej_b2_c05_20)=
### Ejercicio 2.05.20 - Historial de Comandos ⭐⭐☆☆☆

Crear un programa que lea líneas de texto desde la entrada estándar y las
almacene en un "historial" (un arreglo dinámico de cadenas `char**`). El
historial debe crecer dinámicamente a medida que se añaden comandos.

(ej_b2_c05_21)=
### Ejercicio 2.05.21 - Matriz Irregular (Ragged Array) ⭐⭐⭐☆☆

Reservar memoria para una matriz dinámica donde cada fila puede tener un número
diferente de columnas. Las dimensiones (número de columnas de cada fila) se
deben leer de un arreglo de configuración.

(ej_b2_c05_22)=
### Ejercicio 2.05.22 - Liberación Profunda ⭐⭐☆☆☆

Escribir una función `void liberar_historial(char** historial, int n_comandos)`
que libere correctamente toda la memoria utilizada por la estructura del
ejercicio 1.19: primero la memoria de cada cadena individual y luego la memoria
del arreglo de punteros.

(ej_b2_c05_23)=
### Ejercicio 2.05.23 - Buffer de Lectura Dinámico ⭐⭐⭐☆☆

Crear una función que lea una línea completa desde `stdin` (hasta el salto de
línea), alojando dinámicamente la memoria necesaria para la línea sin imponer un
límite de tamaño predefinido. La función podría empezar con un buffer pequeño y
usar `realloc` para agrandarlo según sea necesario.

(ej_b2_c05_24)=
### Ejercicio 2.05.24 - Lista de Compras Dinámica ⭐⭐⭐☆☆

Crear un programa interactivo que permita al usuario gestionar una lista de
compras. Las opciones deben ser:
1. Añadir producto (cadena dinámica).
2. Eliminar producto.
3. Mostrar lista.
La lista debe ser un arreglo de `char*` que se ajuste dinámicamente.

(ej_b2_c05_25)=
### Ejercicio 2.05.25 - Manejo de Errores de malloc ⭐⭐☆☆☆

Modificar uno de los ejercicios anteriores (ej. 1.2, Duplicadora) para que, si
`malloc` o `realloc` devuelven `NULL`, el programa lo notifique con un mensaje
de error claro a `stderr` y termine de forma controlada (ej.
`exit(EXIT_FAILURE)`), en lugar de fallar por desreferenciar un puntero nulo.

## Más Ejercicios de Memoria Dinámica

(ej_b2_c05_26)=
### Ejercicio 2.05.26 - Filtro de Arreglo Dinámico ⭐⭐⭐☆☆

Crear una función que reciba un arreglo dinámico, su tamaño y un puntero a una
función "predicado" (`bool (*pred)(int)`). La función debe devolver un **nuevo**
arreglo dinámico que contenga únicamente los elementos del arreglo original para
los cuales el predicado devuelve `true`.

(ej_b2_c05_27)=
### Ejercicio 2.05.27 - Mapa Simple (Clave-Valor) ⭐☆☆☆☆

Implementar una estructura para un mapa simple (diccionario) que almacene pares
clave-valor (`char*`-`int`). El mapa debe usar un arreglo dinámico de `struct
par {char* clave; int valor;}`. La tabla debe crecer usando `realloc` cuando se
quede sin espacio.

(ej_b2_c05_28)=
### Ejercicio 2.05.28 - Unir Líneas de Archivo ⭐⭐☆☆☆

Escribir un programa que lea todas las líneas de un archivo y las almacene en un
arreglo dinámico de cadenas (`char**`). Luego, crear una función que una todas
estas cadenas en una sola, separadas por un espacio, y la devuelva como una
nueva cadena dinámica.

(ej_b2_c05_29)=
### Ejercicio 2.05.29 - Sub-arreglo Dinámico ⭐⭐⭐☆☆

Crear una función `int* sub_arreglo(const int* arr, size_t inicio, size_t fin)`
que devuelva un nuevo arreglo dinámico conteniendo una copia de los elementos
del arreglo original desde el índice `inicio` hasta `fin-1`.

(ej_b2_c05_30)=
### Ejercicio 2.05.30 - Matriz Dinámica en Bloque Contiguo ⭐⭐⭐☆☆

Implementar la creación y liberación de una matriz `M x N` de dos formas:
1.  Como un arreglo de punteros a filas (el método tradicional).
2.  Como un único bloque de memoria contigua de `M*N` elementos, y un arreglo de
    punteros `int**` donde cada puntero `[i]` se calcula para que apunte a la
    fila `i` dentro del bloque contiguo. Comparar la complejidad de liberación
    de ambas.

(ej_b2_c05_31)=
### Ejercicio 2.05.31 - realloc con NULL ⭐⭐☆☆☆

Escribir un pequeño programa que demuestre que `realloc(NULL, n)` se comporta de
manera idéntica a `malloc(n)`. Verificar que la memoria se asigna correctamente.

(ej_b2_c05_32)=
### Ejercicio 2.05.32 - realloc con Tamaño Cero ⭐⭐☆☆☆

Escribir un pequeño programa que demuestre que `realloc(ptr, 0)` se comporta de
manera idéntica a `free(ptr)`. Verificar que el puntero original ya no es válido
después de la operación.

(ej_b2_c05_33)=
### Ejercicio 2.05.33 - Arreglo Dinámico de Structs ⭐⭐⭐☆☆

Alojar dinámicamente un arreglo de `structs` (ej. `producto_t` de un ejercicio
anterior). Implementar funciones para añadir y buscar elementos en este arreglo,
usando `realloc` para expandir el arreglo cuando sea necesario.

(ej_b2_c05_34)=
### Ejercicio 2.05.34 - Implementar getline ⭐⭐☆☆☆

Implementar una versión simplificada de la función `getline` de POSIX. La
función `ssize_t mi_getline(char **lineptr, size_t *n, FILE *stream)` debe leer
una línea de `stream`, almacenarla en un buffer apuntado por `*lineptr` y
expandir dicho buffer con `realloc` si es necesario.

(ej_b2_c05_35)=
### Ejercicio 2.05.35 - Pila (Stack) Dinámica ⭐⭐⭐☆☆

Implementar una Pila (Stack) usando un arreglo dinámico. La estructura debe
tener capacidad y tamaño. Cuando la pila se llena, su capacidad debe duplicarse.
Cuando el tamaño es un cuarto de la capacidad, esta debe reducirse a la mitad.
Implementar `push`, `pop` y `peek`.

(ej_b2_c05_36)=
## Ejercicio 2.05.36 - Array Dinámico Simple ⭐☆☆☆☆

Leé un tamaño `n`, creá un array dinámico de `n` enteros, llenalo, mostralo y
liberalo.

**Orientación:**
- `int *arr = malloc(n * sizeof(int));`
- Verificá: `if (arr == NULL) return 1;`
- Al final: `free(arr);`

---

(ej_b2_c05_37)=
## Ejercicio 2.05.37 - String Dinámico ⭐⭐☆☆☆

Leé un string de tamaño arbitrario (hasta 1000 caracteres), almacenalo
dinámicamente con el tamaño exacto.

**Orientación:**
- Leé en buffer temporal: `char temp[1001];`
- Asigná memoria exacta: `strlen(temp) + 1`
- Copiá con `strcpy`
- Liberá al final

---

(ej_b2_c05_38)=
## Ejercicio 2.05.38 - Redimensionar Array ⭐⭐⭐☆☆

Implementá un programa que permita agregar elementos dinámicamente a un array,
redimensionándolo cuando se llene.

**Orientación:**
- Mantené `capacidad` actual y `tamanio` usado
- Cuando `tamanio == capacidad`, duplicá capacidad con `realloc`
- `arr = realloc(arr, nueva_capacidad * sizeof(int));`
- Verificá que `realloc` no retorne NULL

---

(ej_b2_c05_39)=
## Ejercicio 2.05.39 - Copiar String Dinámicamente ⭐⭐⭐☆☆

Implementá `char *duplicar_string(const char *src)` que retorne una copia
dinámica.

**Orientación:**
- Calculá longitud con `strlen`
- Asigná `strlen + 1` bytes (para '\0')
- Copiá con `strcpy`
- El llamador es responsable de liberar

---

(ej_b2_c05_40)=
## Ejercicio 2.05.40 - Concatenar Strings Dinámicamente ⭐⭐⭐☆☆

Implementá `char *concatenar(const char *s1, const char *s2)` que retorne
concatenación en memoria dinámica.

**Orientación:**
- Longitud total = `strlen(s1) + strlen(s2) + 1`
- Copiá s1 primero, luego s2
- Retorná el nuevo string

---

(ej_b2_c05_41)=
## Ejercicio 2.05.41 - Matriz Dentada ⭐⭐⭐⭐☆

Creá una matriz donde cada fila tiene diferente cantidad de columnas.

**Orientación:**
- `int **matriz = malloc(filas * sizeof(int*));`
- Para cada fila: `matriz[i] = malloc(cols[i] * sizeof(int));`
- Liberá en orden inverso: filas primero, luego array de punteros

---

(ej_b2_c05_42)=
## Ejercicio 2.05.42 - Lista de Strings ⭐⭐⭐⭐☆

Leé N strings y almacenalos en un array dinámico de strings.

**Orientación:**
- `char **strings = malloc(n * sizeof(char*));`
- Para cada string: asigná memoria exacta
- Liberá cada string individualmente, luego el array

---

(ej_b2_c05_43)=
## Ejercicio 2.05.43 - Histograma Dinámico ⭐⭐⭐⭐☆

Leé números hasta EOF y creá un histograma de frecuencias (0-9).

**Orientación:**
- Asigná array dinámico de 10 enteros (inicializado a 0)
- Usá `calloc(10, sizeof(int))` para inicialización automática
- Incrementá contador según el dígito
- Mostrá histograma visual con asteriscos

---

(ej_b2_c05_44)=
## Ejercicio 2.05.44 - Vector Dinámico (Estructura) ⭐⭐⭐⭐☆

Implementá un vector dinámico encapsulado en estructura:

``` c
typedef struct
{
    int *datos;
    size_t tamanio;
    size_t capacidad;
} vector_t;
```
<!-- c -->

Funciones:
- `vector_t *crear_vector()`
- `void agregar(vector_t *v, int valor)`
- `void destruir_vector(vector_t *v)`

**Orientación:**
- `crear_vector` asigna estructura y array inicial
- `agregar` redimensiona si es necesario
- `destruir_vector` libera datos y luego estructura

---

(ej_b2_c05_45)=
## Ejercicio 2.05.45 - Leer Archivo Completo en Memoria ⭐⭐⭐⭐☆

Leé un archivo de texto completo en memoria dinámica.

**Orientación:**
- Obtené tamaño con `fseek` y `ftell`
- Asigná `tamanio + 1` bytes
- Leé todo con `fread`
- Terminá con '\0'
- Liberá memoria al terminar

---

(ej_b2_c05_46)=
## Ejercicio 2.05.46 - Merge de Arrays ⭐⭐⭐⭐☆

Implementá `int *merge(int *arr1, int n1, int *arr2, int n2)` que retorne un
nuevo array con ambos ordenados.

**Orientación:**
- Asigná array de tamaño `n1 + n2`
- Usá dos índices para recorrer ambos arrays
- Copiá el menor en cada paso
- Liberá los arrays originales si ya no se usan

---

(ej_b2_c05_47)=
## Ejercicio 2.05.47 - Lista Enlazada con Memoria Dinámica ⭐⭐⭐⭐⭐

Implementá lista enlazada completamente dinámica:

``` c
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} nodo_t;
```
<!-- c -->

Funciones:
- `nodo_t *crear_nodo(int valor)`
- `void insertar_ordenado(nodo_t **cabeza, int valor)`
- `void eliminar_valor(nodo_t **cabeza, int valor)`
- `void liberar_lista(nodo_t **cabeza)`

**Orientación:**
- Cada nodo se asigna con `malloc`
- `insertar_ordenado` encuentra posición correcta
- `eliminar_valor` busca, reenlaza y libera
- `liberar_lista` recorre y libera todos los nodos

---

(ej_b2_c05_48)=
## Ejercicio 2.05.48 - Árbol Binario de Búsqueda ⭐⭐⭐⭐⭐

Implementá un ABB (Árbol Binario de Búsqueda):

``` c
typedef struct nodo_arbol
{
    int dato;
    struct nodo_arbol *izquierdo;
    struct nodo_arbol *derecho;
} nodo_arbol_t;
```
<!-- c -->

Funciones:
- `nodo_arbol_t *insertar(nodo_arbol_t *raiz, int valor)`
- `bool buscar(nodo_arbol_t *raiz, int valor)`
- `void liberar_arbol(nodo_arbol_t *raiz)`

**Orientación:**
- Inserción recursiva: menor a izquierda, mayor a derecha
- Búsqueda recursiva similar
- Liberación: postorden (izquierdo, derecho, raíz)

---

(ej_b2_c05_49)=
## Ejercicio 2.05.49 - Tabla Hash Simple ⭐⭐⭐⭐⭐

Implementá una tabla hash con encadenamiento:

```{code-block} c
:linenos:
typedef struct entrada
{
    char *clave;
    int valor;
    struct entrada *siguiente;
} entrada_t;
typedef struct
{
    entrada_t **tabla;
    size_t tamanio;
} hash_t;
```
<!-- {code-block} c -->

Funciones:
- `hash_t *crear_hash(size_t tam)`
- `void insertar(hash_t *h, const char *clave, int valor)`
- `int *buscar(hash_t *h, const char *clave)`
- `void destruir_hash(hash_t *h)`

**Orientación:**
- Función hash simple: suma de caracteres % tamaño
- Encadenamiento para colisiones
- Destruir: libera cadenas, claves, y tabla

---

(ej_b2_c05_50)=
## Ejercicio 2.05.50 - Pool de Memoria ⭐⭐⭐⭐⭐

Implementá un allocator simple que asigna de un pool preasignado.

**Orientación:**
- Asigná bloque grande inicial con `malloc`
- Mantené puntero a espacio libre
- `pool_alloc(size)` retorna puntero y avanza
- `pool_free()` libera todo el pool de una vez
- No soporta liberación individual

---

(ej_b2_c05_51)=
## Ejercicio 2.05.51 - Parser de CSV Dinámico ⭐⭐⭐⭐⭐

Leé un archivo CSV y almacená datos en estructura dinámica.

**Orientación:**
- Leé línea por línea con `fgets`
- Parseá con `strtok` o manualmente
- Almacená en array dinámico de estructuras
- Redimensioná si es necesario
- Liberá todo al terminar

---

(ej_b2_c05_52)=
## Ejercicio 2.05.52 - Búfer Circular Dinámico ⭐⭐⭐⭐⭐

Implementá un búfer circular continuo en memoria dinámica:

**Orientación:**
- Asigná un arreglo continuo dinámico de enteros con `malloc`
- Mantené los índices `inicio`, `fin` y la cantidad de elementos
- Si el búfer se llena, duplicá su capacidad reubicando los elementos en orden contiguo
- Liberá toda la memoria al destruir el búfer

---

(ej_b2_c05_53)=
## Ejercicio 2.05.53 - Arreglo Dinámico de Cadenas de Texto ⭐⭐⭐⭐⭐

Implementá un arreglo dinámico de cadenas de texto (`char **`):

**Orientación:**
- Asigná dinámicamente un arreglo de punteros `char **lineas`
- Cada línea individual debe alojarse dinámicamente según su longitud exacta
- Permití agregar nuevas líneas redimensionando el arreglo de punteros con `realloc`
- En la función de destrucción, liberá cada cadena antes de liberar el arreglo de punteros

---

(ej_b2_c05_54)=
## Ejercicio 2.05.54 - Simulador de Memoria ⭐⭐⭐⭐⭐

Implementá un simulador que registre todas las asignaciones/liberaciones.

**Orientación:**
- Envolvé `malloc` y `free`
- Mantené registro de bloques activos
- Detectá double-free y memory leaks
- Mostrá estadísticas al final

---

(ej_b2_c05_55)=
## Ejercicio 2.05.55 - Sistema de Gestión de Memoria Personalizado ⭐⭐⭐⭐⭐

Implementá tu propio `malloc` y `free` usando `sbrk` o un buffer grande.

**Orientación:**
- Mantené lista de bloques libres/ocupados
- Algoritmo first-fit o best-fit
- Metadata en cada bloque (tamaño, ocupado)
- Coalescencia de bloques libres adyacentes

---

## Notas Finales

:::{danger} Errores Fatales a Evitar

1. **No verificar NULL:** Siempre: `if (ptr == NULL) { handle error; }`
2. **Olvidar free:** Cada `malloc` debe tener su `free` correspondiente
3. **Double free:** Liberar el mismo puntero dos veces
4. **Use after free:** Usar memoria después de liberarla
5. **Memory leak:** Perder referencias sin liberar

:::
<!-- {danger} Errores Fatales a Evitar -->

:::{tip} Herramientas de Debugging

```{code-block} bash
:linenos:
# Valgrind - detecta leaks y accesos inválidos
valgrind --leak-check=full --show-leak-kinds=all ./programa

# AddressSanitizer - más rápido, menos completo
gcc -fsanitize=address -g programa.c -o programa
./programa

# Verificar código de salida de Valgrind
valgrind ./programa
echo $?  # 0 si no hay errores

```
<!-- {code-block} bash -->

:::
<!-- {tip} Herramientas de Debugging -->

:::{note} Patrones Comunes

1. **Siempre liberar en orden inverso a asignación**
2. **Usar `calloc` para inicialización a cero**
3. **Verificar `realloc` antes de reasignar puntero original**
4. **Mantener punteros a NULL después de `free`**
5. **Encapsular estructuras dinámicas en funciones de gestión**

:::
<!-- {note} Patrones Comunes -->

Estas consignas cubren todos los aspectos de memoria dinámica: asignación
básica, redimensionamiento, estructuras complejas, gestión avanzada y prevención
de errores.

