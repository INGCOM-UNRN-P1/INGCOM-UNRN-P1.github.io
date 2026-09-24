---
title: "Ejercicios de matrices"
short_title: "7. Matrices"
---

# Ejercicios de matrices

## Acerca de

Ejercicios para trabajar con arreglos bidimensionales (matrices) en C11, tanto
estáticas en Stack como planas y contiguas en Heap.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-matrices`
- {ref}`capitulo-arreglos`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Indexación bidimensional y orden de almacenamiento por filas (*row-major order*).
2. Aplanamiento unidimensional de matrices contiguas: dirección del elemento $(f, c)$ como `f * cols + c`.
3. Paso de matrices como punteros y dimensiones (`const int *mat, size_t filas, size_t cols`).
4. Lazos anidados y análisis de complejidad $O(\text{filas} \times \text{columnas})$.

### Cuestiones de Estilo Aplicables
- **Calificador const:** Toda matriz de entrada cuyos valores no deban modificarse
  debe calificarse como `const int *matriz` o `const int mat[][COLS]`.
- **Dimensiones size_t:** Las filas y columnas deben expresarse con `size_t`.

---

## Operaciones Básicas

(ej_b3_c01_01)=
### Ejercicio 3.01.01 - Formateo de Matriz Plana ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c01_01_mostrar_matriz

Implementá una función pura que formatee una matriz plana contigua de enteros en
un búfer de caracteres, fila por fila entre corchetes, separada por saltos de línea.
Retorna `true` si el búfer tuvo capacidad suficiente, o `false` si se truncó.

```c
bool formatear_matriz(const int *mat, size_t filas, size_t cols, char *buf, size_t cap);
```

**Tabla de Vectores de Prueba:**

| Matriz ($F \times C$) | Datos Planos | Capacidad Búfer | Retorno | Salida Formateada |
| :--- | :--- | :--- | :--- | :--- |
| $2 \times 3$ | `[1, 2, 3, 4, 5, 6]` | `128` | `true` | `"[ 1, 2, 3 ]\n[ 4, 5, 6 ]"` |
| $1 \times 2$ | `[10, 20]` | `64` | `true` | `"[ 10, 20 ]"` |
| $0 \times 0$ | `NULL` | `16` | `true` | `""` |
| $2 \times 2$ | `[1, 2, 3, 4]` | `5` | `false` | Búfer protegido de desbordamiento |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool formatear_matriz(const int *mat, size_t filas, size_t cols, char *buf, size_t cap) {
    if (buf == NULL || cap == 0) {
        return false;
    }
    if (mat == NULL || filas == 0 || cols == 0) {
        buf[0] = '\0';
        return true;
    }
    size_t off = 0;
    for (size_t f = 0; f < filas; ++f) {
        int esc = snprintf(buf + off, cap - off, "%s[ ", (f > 0) ? "\n" : "");
        if (esc < 0 || (size_t)esc >= cap - off) return false;
        off += (size_t)esc;

        for (size_t c = 0; c < cols; ++c) {
            esc = snprintf(buf + off, cap - off, "%d%s", mat[f * cols + c], (c + 1 < cols) ? ", " : " ]");
            if (esc < 0 || (size_t)esc >= cap - off) return false;
            off += (size_t)esc;
        }
    }
    return true;
}

int main(void) {
    char buffer[128] = {0};
    int m2x3[6] = {1, 2, 3, 4, 5, 6};

    assert(formatear_matriz(m2x3, 2, 3, buffer, sizeof(buffer)));
    assert(strcmp(buffer, "[ 1, 2, 3 ]\n[ 4, 5, 6 ]") == 0);

    int m1x2[2] = {10, 20};
    assert(formatear_matriz(m1x2, 1, 2, buffer, sizeof(buffer)));
    assert(strcmp(buffer, "[ 10, 20 ]") == 0);

    assert(formatear_matriz(NULL, 0, 0, buffer, sizeof(buffer)));
    assert(strcmp(buffer, "") == 0);

    /* Capacidad deficiente */
    char corto[5] = {0};
    assert(!formatear_matriz(m2x3, 2, 3, corto, sizeof(corto)));

    return 0;
}
```
::::
:::

(ej_b3_c01_02)=
### Ejercicio 3.01.02 - Multiplicación por un Escalar in-place ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c01_02_escalar

Implementá una función que multiplique cada componente de una matriz plana
por un entero escalar dado, modificando el arreglo en memoria (*in-place*).

```c
void matriz_multiplicar_escalar(int *mat, size_t filas, size_t cols, int escalar);
```

**Tabla de Vectores de Prueba:**

| Matriz Inicial ($2 \times 2$) | Escalar | Matriz Resultante |
| :--- | :--- | :--- |
| `[1, 2, 3, 4]` | `5` | `[5, 10, 15, 20]` |
| `[10, -2, 0, 8]` | `-1` | `[-10, 2, 0, -8]` |
| `[5, 10]` | `0` | `[0, 0]` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void matriz_multiplicar_escalar(int *mat, size_t filas, size_t cols, int escalar) {
    if (mat == NULL) {
        return;
    }
    size_t total = filas * cols;
    for (size_t i = 0; i < total; ++i) {
        mat[i] *= escalar;
    }
}

int main(void) {
    int m[4] = {1, 2, 3, 4};
    matriz_multiplicar_escalar(m, 2, 2, 5);
    assert(m[0] == 5 && m[1] == 10 && m[2] == 15 && m[3] == 20);

    int m2[4] = {10, -2, 0, 8};
    matriz_multiplicar_escalar(m2, 2, 2, -1);
    assert(m2[0] == -10 && m2[1] == 2 && m2[2] == 0 && m2[3] == -8);

    matriz_multiplicar_escalar(m, 2, 2, 0);
    for (size_t i = 0; i < 4; ++i) assert(m[i] == 0);

    return 0;
}
```
::::
:::

## Aritmética Matricial

(ej_b3_c01_03)=
### Ejercicio 3.01.03 - Suma de matrices ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c01_03_suma_matrices

Implementá una función que sume dos matrices planas contiguas de enteros, `a` y `b`,
almacenando el resultado en una tercera matriz de destino `c` de idénticas dimensiones:

```c
void matriz_sumar(const int *a, const int *b, int *c, size_t filas, size_t cols);
```

**Tabla de Vectores de Prueba:**

| Dimensiones | Matriz A | Matriz B | Matriz C (Salida) |
| :--- | :--- | :--- | :--- |
| $2 \times 2$ | `[1, 2, 3, 4]` | `[5, 6, 7, 8]` | `[6, 8, 10, 12]` |
| $1 \times 3$ | `[10, -5, 0]` | `[-10, 5, 42]` | `[0, 0, 42]` |
| $0 \times 0$ | `NULL` | `NULL` | Sin modificaciones |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void matriz_sumar(const int *a, const int *b, int *c, size_t filas, size_t cols) {
    if (a == NULL || b == NULL || c == NULL) {
        return;
    }
    size_t total = filas * cols;
    for (size_t i = 0; i < total; ++i) {
        c[i] = a[i] + b[i];
    }
}

int main(void) {
    int a[4] = {1, 2, 3, 4};
    int b[4] = {5, 6, 7, 8};
    int c[4] = {0};

    matriz_sumar(a, b, c, 2, 2);
    assert(c[0] == 6 && c[1] == 8 && c[2] == 10 && c[3] == 12);

    int a2[3] = {10, -5, 0};
    int b2[3] = {-10, 5, 42};
    int c2[3] = {0};

    matriz_sumar(a2, b2, c2, 1, 3);
    assert(c2[0] == 0 && c2[1] == 0 && c2[2] == 42);

    matriz_sumar(NULL, NULL, NULL, 0, 0);

    return 0;
}
```
::::
:::

(ej_b3_c01_04)=
### Ejercicio 3.01.04 - Multiplicación de matrices ⭐⭐⭐☆☆

#### Descripción
Implementar la multiplicación de dos matrices, `A` (de $m \times n$) y `B` (de
$n \times p$), cuyo resultado es una nueva matriz `C` (de $m \times p$).

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Matriz A (2x3): [[1, 2, 3], [4, 5, 6]]
Matriz B (3x2): [[7, 8], [9, 10], [11, 12]]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Matriz C (2x2): [[58, 64], [139, 154]]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Precondición:** El número de columnas de la matriz `A` debe ser igual al
    número de filas de la matriz `B`.
-   **Fórmula:** Cada elemento $c_{ij}$ de la matriz resultado se calcula como
    el producto punto de la fila `i` de `A` y la columna `j` de `B`: $c_{ij} =
    \sum_{k=0}^{n-1} a_{ik} \cdot b_{kj}$.
-   **Proceso:** Se necesitan tres lazos anidados:
    1.  Lazo para las filas de `C` (y `A`), de `i=0` a `m-1`.
    2.  Lazo para las columnas de `C` (y `B`), de `j=0` a `p-1`.
    3.  Lazo para la suma del producto punto, de `k=0` a `n-1`.
:::
<!-- {hint} Lógica y Consideraciones -->

::::{hint} Lógica y Consideraciones
:class: dropdown
:::
<!-- {hint} Lógica y Consideraciones -->{mermaid}

flowchart TD
    A["Inicio"] --> B["i = 0..m-1"]
    B --> C["j = 0..p-1"]
    C --> D["suma = 0"]
    D --> E["k = 0..n-1"]
    E --> F["suma += A[i][k] * B[k][j]"]
    F --> E
    E -- "Fin del lazo k" --> G["C[i][j] = suma"]
    G --> C
    C -- "Fin del lazo j" --> B
    B -- "Fin del lazo i" --> H["Fin"]

:::
<!-- {mermaid} -->

::::
<!-- {hint} Diagrama -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO multiplicar_matrices(A, m, n, B, p, REF C)
INICIO
    // Asumiendo que n == p
    PARA i DESDE 0 HASTA m-1 HACER
        PARA j DESDE 0 HASTA p-1 HACER
            suma = 0
            PARA k DESDE 0 HASTA n-1 HACER
                suma = suma + A[i][k] * B[k][j]
            FIN PARA
            C[i][j] = suma
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

## Manipulación

(ej_b3_c01_05)=
### Ejercicio 3.01.05 - Transposición ⭐⭐☆☆☆

#### Descripción
Calcular la transpuesta $A^T$ de una matriz $A$. La transposición se obtiene
intercambiando las filas por las columnas.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Matriz A (2x3): `[[1, 2, 3], [4, 5, 6]]`
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
Matriz $A^T$ (3x2):
``` text
[ 1, 4 ]
[ 2, 5 ]
[ 3, 6 ]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Fórmula:** $(A^T)_{ij} = A_{ji}$.
-   **Dimensiones:** Si la matriz original es $m \times n$, su transpuesta será
    $n \times m$.
-   **Proceso:** Recorrer la matriz original `A` con lazos anidados. En cada
    posición `(i, j)`, copiar el elemento `A[i][j]` a la posición `(j, i)` de la
    nueva matriz transpuesta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO transponer_matriz(A, filas, columnas, REF A_T)
INICIO
    PARA i DESDE 0 HASTA filas-1 HACER
        PARA j DESDE 0 HASTA columnas-1 HACER
            A_T[j][i] = A[i][j]
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b3_c01_06)=
### Ejercicio 3.01.06 - Suma de diagonales ⭐⭐☆☆☆

#### Descripción
Para una matriz cuadrada, calcular la suma de los elementos de sus dos
diagonales: la principal y la secundaria.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
``` text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Suma Diagonal Principal: `1 + 5 + 9 = 15`
Suma Diagonal Secundaria: `3 + 5 + 7 = 15`
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Diagonal Principal:** Los elementos de la diagonal principal son aquellos
    donde el índice de fila es igual al índice de columna (`i == j`).
-   **Diagonal Secundaria:** Los elementos de la diagonal secundaria en una
    matriz de tamaño `n x n` son aquellos donde `i + j == n - 1`.
-   **Proceso:** Usar un solo lazo de `i=0` a `n-1`. En cada iteración, sumar
    `matriz[i][i]` a la suma principal y `matriz[i][n-1-i]` a la suma
    secundaria.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO sumar_diagonales(matriz, n, REF suma_princ, REF suma_sec)
INICIO
    suma_princ = 0
    suma_sec = 0
    PARA i DESDE 0 HASTA n-1 HACER
        suma_princ = suma_princ + matriz[i][i]
        suma_sec = suma_sec + matriz[i][n-1-i]
    FIN PARA
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

## Generación

(ej_b3_c01_07)=
### Ejercicio 3.01.07 - Matriz identidad ⭐⭐⭐☆☆

#### Descripción
Generar una matriz identidad de tamaño `n x n`. La matriz identidad es una
matriz cuadrada con unos en la diagonal principal y ceros en todas las demás
posiciones.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Tamaño n = 3
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
[ 1, 0, 0 ]
[ 0, 1, 0 ]
[ 0, 0, 1 ]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Proceso:** Recorrer la matriz `n x n` con lazos anidados.
-   **Condición:** Para cada elemento en la posición `(i, j)`:
    -   Si `i == j`, el valor es 1.
    -   Si `i != j`, el valor es 0.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO generar_identidad(REF matriz, n)
INICIO
    PARA i DESDE 0 HASTA n-1 HACER
        PARA j DESDE 0 HASTA n-1 HACER
            SI i == j ENTONCES
                matriz[i][j] = 1
            SINO
                matriz[i][j] = 0
            FIN SI
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b3_c01_08)=
## Ejercicio 3.01.08 - s Adicionales de Matrices ⭐⭐⭐☆☆

(ej_b3_c01_09)=
### Ejercicio 3.01.09 - Matriz simétrica ⭐⭐⭐☆☆

#### Descripción
Escribir una función que verifique si una matriz cuadrada es simétrica. Una
matriz es simétrica si es igual a su propia transpuesta, lo que significa que el
elemento en la fila `i`, columna `j` es igual al elemento en la fila `j`,
columna `i`.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
``` text
[ 1, 7, 3 ]
[ 7, 4, 5 ]
[ 3, 5, 6 ]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
La matriz es simétrica.
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Fórmula:** Una matriz `A` es simétrica si $A_{ij} = A_{ji}$ para todos los
    `i`, `j`.
-   **Proceso:**
    1.  Recorrer solo la mitad superior (o inferior) de la matriz es suficiente.
        Por ejemplo, con lazos anidados donde el lazo interior para `j` comienza
        en `i+1`.
    2.  En cada paso, comparar `matriz[i][j]` con `matriz[j][i]`.
    3.  Si en algún momento no son iguales, la matriz no es simétrica y la
        función puede devolver `falso` inmediatamente.
-   **Salida:** Si los lazos se completan sin encontrar diferencias, la matriz
    es simétrica.
:::
<!-- {hint} Lógica y Consideraciones -->

::::{hint} Lógica y Consideraciones
:class: dropdown
El diagrama muestra los pares de elementos que deben ser iguales. Solo es
necesario verificar una mitad del triángulo (excluyendo la diagonal).
:::
<!-- {hint} Lógica y Consideraciones -->{mermaid}

flowchart TD
    subgraph Matriz
        A11["a11"]
        A12["a12"]
        A13["a13"]
        A21["a21"]
        A22["a22"]
        A23["a23"]
        A31["a31"]
        A32["a32"]
        A33["a33"]
    end
    A12 <-.-> A21
    A13 <-.-> A31
    A23 <-.-> A32

:::
<!-- {mermaid} -->

::::
<!-- {hint} Diagrama -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_simetrica(matriz, n)
INICIO
    PARA i DESDE 0 HASTA n-1 HACER
        PARA j DESDE i+1 HASTA n-1 HACER
            SI matriz[i][j] != matriz[j][i] ENTONCES
                RETORNAR FALSO
            FIN SI
        FIN PARA
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b3_c01_10)=
### Ejercicio 3.01.10 - Suma por Filas y Columnas ⭐⭐☆☆☆

#### Descripción
Crear un programa que, dada una matriz, calcule dos arreglos: uno que contenga
la suma de los elementos de cada fila y otro que contenga la suma de los
elementos de cada columna.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
Matriz (2x3):
``` text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Suma de filas: [6, 15]
Suma de columnas: [5, 7, 9]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Suma de Filas:**
    -   Recorrer cada fila con un lazo exterior.
    -   Para cada fila, inicializar una `suma_fila` en 0.
    -   Con un lazo interior, recorrer las columnas de esa fila y acumular los
        valores en `suma_fila`.
    -   Guardar el resultado en el arreglo de sumas de filas.
-   **Suma de Columnas:**
    -   El proceso es inverso. El lazo exterior recorre las columnas.
    -   El lazo interior recorre las filas de esa columna.
-   **Eficiencia:** Se pueden calcular ambas sumas en un solo par de lazos
    anidados. Al procesar el elemento `matriz[i][j]`, se añade a `suma_filas[i]`
    y a `suma_columnas[j]`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO sumar_filas_y_columnas(matriz, filas, cols, REF sumas_filas, REF sumas_cols)
INICIO
    // Inicializar arreglos de suma en 0
    PARA i DESDE 0 HASTA filas-1 HACER
        sumas_filas[i] = 0
    FIN PARA
    PARA j DESDE 0 HASTA cols-1 HACER
        sumas_cols[j] = 0
    FIN PARA
    // Calcular ambas sumas en una sola pasada
    PARA i DESDE 0 HASTA filas-1 HACER
        PARA j DESDE 0 HASTA cols-1 HACER
            sumas_filas[i] = sumas_filas[i] + matriz[i][j]
            sumas_cols[j] = sumas_cols[j] + matriz[i][j]
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b3_c01_11)=
### Ejercicio 3.01.11 - Elemento "Silla" ⭐⭐☆☆☆

#### Descripción
Encontrar un "punto de silla" en una matriz. Un punto de silla es un elemento
que es simultáneamente el valor mínimo en su fila y el valor máximo en su
columna.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
``` text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Punto de silla encontrado en (2, 0) con valor 7.
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Iterar a través de cada fila `i` de la matriz.
    2.  En cada fila, encontrar el valor mínimo y su índice de columna
        `min_col_idx`.
    3.  Una vez encontrado el candidato (el mínimo de la fila), verificar si
        este elemento es también el máximo de su columna (`min_col_idx`).
    4.  Para ello, iterar a través de la columna `min_col_idx` y comparar el
        candidato con todos los demás elementos de esa columna.
    5.  Si el candidato es el mayor de su columna, se ha encontrado un punto de
        silla.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO encontrar_punto_silla(matriz, filas, cols)
INICIO
    PARA i DESDE 0 HASTA filas-1 HACER
        // Encontrar el mínimo en la fila i
        min_fila = matriz[i][0]
        min_col_idx = 0
        PARA j DESDE 1 HASTA cols-1 HACER
            SI matriz[i][j] < min_fila ENTONCES
                min_fila = matriz[i][j]
                min_col_idx = j
            FIN SI
        FIN PARA
        // Verificar si es el máximo en su columna
        es_max_columna = VERDADERO
        PARA k DESDE 0 HASTA filas-1 HACER
            SI matriz[k][min_col_idx] > min_fila ENTONCES
                es_max_columna = FALSO
                SALIR DEL LAZO // break
            FIN SI
        FIN PARA
        SI es_max_columna ENTONCES
            ESCRIBIR "Punto de silla en (", i, ", ", min_col_idx, ") con valor ", min_fila
            RETORNAR
        FIN SI
    FIN PARA
    ESCRIBIR "No se encontraron puntos de silla."
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b3_c01_12)=
## Ejercicio 3.01.12 - s de Matrices Dinámicas ⭐⭐⭐☆☆

(ej_b3_c01_13)=
### Ejercicio 3.01.13 - Crear y llenar matriz dinámica ⭐⭐⭐☆☆

#### Descripción
Escribir una función que solicite al usuario las dimensiones (filas y columnas)
y luego los elementos de una matriz, para finalmente imprimirla.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
Se le pedirá al usuario que ingrese el número de filas y columnas, y luego cada
uno de los elementos.

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
La matriz ingresada por el usuario, impresa de forma ordenada.

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se debe usar una función para leer la entrada del usuario para
    las dimensiones y los elementos.
-   **Proceso:**
    1.  Solicitar el número de filas (`filas`).
    2.  Solicitar el número de columnas (`columnas`).
    3.  Crear una matriz vacía con las dimensiones especificadas.
    4.  Usar dos lazos anidados para recorrer la matriz y solicitar cada
        elemento al usuario, asignándolo a la posición correspondiente.
    5.  Finalmente, llamar a la función `mostrar_matriz` (del ejercicio 1.1)
        para imprimir la matriz creada.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Lógica y Consideraciones
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO crear_y_llenar_matriz_dinamica()
INICIO
    ESCRIBIR "Ingrese el número de filas: " SIN SALTO DE LÍNEA
    LEER filas
    ESCRIBIR "Ingrese el número de columnas: " SIN SALTO DE LÍNEA
    LEER columnas
    // Crear una matriz de 'filas' x 'columnas'
    CREAR matriz[filas][columnas]
    ESCRIBIR "Ingrese los elementos de la matriz:"
    PARA i DESDE 0 HASTA filas-1 HACER
        PARA j DESDE 0 HASTA columnas-1 HACER
            ESCRIBIR "Elemento [", i, "][ ", j, "]: " SIN SALTO DE LÍNEA
            LEER matriz[i][j]
        FIN PARA
    FIN PARA
    // Asumiendo que la función mostrar_matriz está definida
    mostrar_matriz(matriz, filas, columnas)
FIN PROCEDIMIENTO
```
<!-- {code-block} pseudocode -->
:::
<!-- {hint} Lógica y Consideraciones -->

## Más Algoritmos con Matrices

(ej_b3_c01_14)=
### Ejercicio 3.01.14 - Reflejar matriz ⭐⭐⭐☆☆

Implementar dos funciones: una que refleje una matriz horizontalmente (la
primera fila se intercambia con la última, la segunda con la penúltima, etc.) y
otra que la refleje verticalmente (la primera columna con la última, etc.).

(ej_b3_c01_15)=
### Ejercicio 3.01.15 - Intercambiar filas o columnas ⭐⭐☆☆☆

Crear funciones `intercambiar_filas(mat, f1, f2)` e `intercambiar_columnas(mat,
c1, c2)` que modifiquen la matriz intercambiando los elementos de las filas o
columnas especificadas.

(ej_b3_c01_16)=
### Ejercicio 3.01.16 - Búsqueda de submatriz ⭐⭐⭐☆☆

Escribir una función que determine si una matriz pequeña `B` (de `k x l`) se
encuentra dentro de una matriz más grande `A` (de `m x n`). La función debe
devolver las coordenadas de la esquina superior izquierda de la primera
ocurrencia, o `(-1, -1)` si no se encuentra.

(ej_b3_c01_17)=
### Ejercicio 3.01.17 - Determinante de matriz 3x3 ⭐⭐⭐☆☆

Calcular el determinante de una matriz 3x3 utilizando la Regla de Sarrus.

(ej_b3_c01_18)=
### Ejercicio 3.01.18 - Suavizado de matriz (Filtro de caja) ⭐⭐⭐☆☆

Implementar un filtro de "suavizado" o "blur". Para cada elemento de la matriz,
su nuevo valor será el promedio de sus 8 vecinos y él mismo. Los elementos en
los bordes requerirán un manejo especial.

(ej_b3_c01_19)=
### Ejercicio 3.01.19 - Detección de bordes (Operador de Sobel) ⭐⭐☆☆☆

Aplicar un operador de Sobel simple para la detección de bordes. Esto implica
"convolucionar" la matriz con un `kernel` (otra matriz pequeña, ej. 3x3) para
resaltar las diferencias de intensidad, como los bordes.

(ej_b3_c01_20)=
### Ejercicio 3.01.20 - Matriz de permutación ⭐⭐⭐☆☆

Verificar si una matriz cuadrada es una matriz de permutación. Esta es una
matriz binaria (solo 0s y 1s) que tiene exactamente un `1` en cada fila y en
cada columna.

(ej_b3_c01_21)=
### Ejercicio 3.01.21 - Producto de Hadamard ⭐⭐☆☆☆

Implementar el producto de Hadamard (o producto elemento a elemento) de dos
matrices `A` y `B` de las mismas dimensiones. La matriz resultante `C` se define
como $c_{ij} = a_{ij} \cdot b_{ij}$.

(ej_b3_c01_22)=
### Ejercicio 3.01.22 - Rellenar con triángulo de Pascal ⭐⭐☆☆☆

Escribir una función que llene una matriz `N x N` con los valores del Triángulo
de Pascal. El elemento `(i, j)` debe ser $\binom{i}{j}$.

(ej_b3_c01_23)=
### Ejercicio 3.01.23 - Matriz antisimétrica ⭐⭐⭐☆☆

Verificar si una matriz cuadrada es antisimétrica. Una matriz `A` es
antisimétrica si su transpuesta es igual a su negativa, es decir, $A^T = -A$.
Esto implica que $a_{ij} = -a_{ji}$ y que todos los elementos de la diagonal
principal deben ser cero.

## Operaciones Avanzadas con Matrices

(ej_b3_c01_24)=
### Ejercicio 3.01.24 - Norma de matriz ⭐⭐⭐☆☆

Implementar funciones que calculen diferentes normas de una matriz.

``` c
double norma_frobenius(double **matriz, int filas, int cols);
double norma_maxima(double **matriz, int filas, int cols);
double norma_uno(double **matriz, int filas, int cols);
```
<!-- c -->

**Norma de Frobenius:** $||A||_F = \sqrt{\sum_{i,j} a_{ij}^2}$

**Norma máxima:** $||A||_{\infty} = \max_i \sum_j |a_{ij}|$ (máxima suma de
fila)

**Norma uno:** $||A||_1 = \max_j \sum_i |a_{ij}|$ (máxima suma de columna)

(ej_b3_c01_25)=
### Ejercicio 3.01.25 - Traza de matriz ⭐⭐⭐☆☆

Calcular la traza de una matriz cuadrada (suma de elementos de la diagonal
principal).

``` c
double traza(double **matriz, int n);
```
<!-- c -->

$$\text{tr}(A) = \sum_{i=1}^n a_{ii}$$

(ej_b3_c01_26)=
### Ejercicio 3.01.26 - Rango de matriz ⭐⭐⭐☆☆

Implementar un algoritmo para calcular el rango de una matriz usando eliminación
gaussiana.

``` c
int calcular_rango(double **matriz, int filas, int cols);
```
<!-- c -->

**Estrategia:** Reducir la matriz a forma escalonada y contar filas no nulas.

(ej_b3_c01_27)=
### Ejercicio 3.01.27 - Matriz de cofactores ⭐⭐⭐☆☆

Calcular la matriz de cofactores para una matriz cuadrada.

``` c
double **matriz_cofactores(double **matriz, int n);
```
<!-- c -->

El cofactor $C_{ij}$ se calcula como: $C_{ij} = (-1)^{i+j} M_{ij}$ donde
$M_{ij}$ es el menor de la matriz (determinante de la submatriz obtenida
eliminando fila $i$ y columna $j$).

(ej_b3_c01_28)=
### Ejercicio 3.01.28 - Matriz inversa ⭐⭐⭐☆☆

Implementar el cálculo de la inversa de una matriz usando el método de
Gauss-Jordan.

``` c
double **matriz_inversa(double **matriz, int n, bool *invertible);
```
<!-- c -->

**Algoritmo:**
1. Crear matriz aumentada $[A | I]$
2. Aplicar eliminación Gauss-Jordan
3. Si se obtiene $[I | A^{-1}]$, retornar $A^{-1}$
4. Si no es posible, la matriz no es invertible

(ej_b3_c01_29)=
### Ejercicio 3.01.29 - Potencia de matriz ⭐⭐⭐☆☆

Calcular $A^n$ para una matriz cuadrada $A$ y un exponente entero $n$.

``` c
double **potencia_matriz(double **matriz, int tam, int exponente);
```
<!-- c -->

**Optimización:** Usar exponenciación rápida para $O(\log n)$ multiplicaciones.

(ej_b3_c01_30)=
### Ejercicio 3.01.30 - Descomposición LU ⭐⭐☆☆☆

Implementar la descomposición LU de una matriz: $A = LU$ donde $L$ es triangular
inferior y $U$ es triangular superior.

``` c
bool descomposicion_lu(double **A, int n, double **L, double **U);
```
<!-- c -->

**Aplicación:** Resolver sistemas de ecuaciones lineales eficientemente.

(ej_b3_c01_31)=
### Ejercicio 3.01.31 - Valores propios (Power Method) ⭐⭐☆☆☆

Implementar el método de la potencia para calcular el valor propio dominante de
una matriz.

``` c
double valor_propio_dominante(double **matriz, int n, double tolerancia);
```
<!-- c -->

**Algoritmo:**
1. Comenzar con vector aleatorio $v$
2. Iterar: $v_{k+1} = \frac{Av_k}{||Av_k||}$
3. El valor propio es $\lambda = v^T A v$

(ej_b3_c01_32)=
### Ejercicio 3.01.32 - Matriz de rotación ⭐⭐⭐☆☆

Implementar funciones para crear y aplicar matrices de rotación 2D y 3D.

``` c
double **matriz_rotacion_2d(double angulo);
double **matriz_rotacion_3d_x(double angulo);
double **matriz_rotacion_3d_y(double angulo);
double **matriz_rotacion_3d_z(double angulo);
```
<!-- c -->

**Matriz de rotación 2D:**

$$
R(\theta) = \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}
$$

(ej_b3_c01_33)=
### Ejercicio 3.01.33 - Matriz de proyección ⭐⭐⭐☆☆

Crear matriz de proyección ortogonal sobre un vector.

``` c
double **matriz_proyeccion(double *vector, int n);
```
<!-- c -->

**Fórmula:** $P = \frac{vv^T}{v^Tv}$

## Algoritmos de Procesamiento de Imágenes

Considerar una matriz como una imagen en escala de grises donde cada elemento
representa la intensidad de un píxel.

(ej_b3_c01_34)=
### Ejercicio 3.01.34 - Umbralización (Thresholding) ⭐⭐☆☆☆

Convertir una imagen en escala de grises a binaria (solo 0 y 255) usando un
umbral.

``` c
void umbralizar(int **imagen, int filas, int cols, int umbral);
```
<!-- c -->

**Algoritmo:** Si `pixel >= umbral`, asignar 255, sino asignar 0.

(ej_b3_c01_35)=
### Ejercicio 3.01.35 - Histograma de Imagen ⭐⭐☆☆☆

Calcular el histograma de una imagen (frecuencia de cada nivel de intensidad).

``` c
void calcular_histograma(int **imagen, int filas, int cols, int *histograma);
```
<!-- c -->

El histograma tiene 256 posiciones (0-255) que cuentan la frecuencia de cada
intensidad.

(ej_b3_c01_36)=
### Ejercicio 3.01.36 - Ecualización de Histograma ⭐⭐☆☆☆

Mejorar el contraste de una imagen mediante ecualización de histograma.

``` c
void ecualizar_histograma(int **imagen, int filas, int cols);
```
<!-- c -->

**Algoritmo:**
1. Calcular histograma
2. Calcular función de distribución acumulativa (CDF)
3. Normalizar CDF y aplicar transformación a cada píxel

(ej_b3_c01_37)=
### Ejercicio 3.01.37 - Filtro gaussiano ⭐⭐☆☆☆

Implementar un filtro gaussiano para suavizado de imagen.

``` c
void filtro_gaussiano(double **imagen, int filas, int cols, double sigma);
```
<!-- c -->

**Kernel gaussiano 3x3:**
$$K = \frac{1}{16}\begin{pmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{pmatrix}$$

(ej_b3_c01_38)=
### Ejercicio 3.01.38 - Detección de bordes (Laplaciano) ⭐⭐☆☆☆

Aplicar el operador Laplaciano para detectar bordes.

``` c
void detectar_bordes_laplaciano(int **imagen, int filas, int cols,
                                int **resultado);
```
<!-- c -->

**Kernel Laplaciano:**
$$K = \begin{pmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{pmatrix}$$

## Matrices Especiales

(ej_b3_c01_39)=
### Ejercicio 3.01.39 - Matriz de Vandermonde ⭐⭐⭐☆☆

Generar una matriz de Vandermonde a partir de un vector.

``` c
double **matriz_vandermonde(double *x, int n, int m);
```
<!-- c -->

**Definición:** $V_{ij} = x_i^{j-1}$

**Ejemplo con $x = [1, 2, 3]$ y $m = 4$:**
$$V = \begin{pmatrix} 1 & 1 & 1 & 1 \\ 1 & 2 & 4 & 8 \\ 1 & 3 & 9 & 27 \end{pmatrix}$$

(ej_b3_c01_40)=
### Ejercicio 3.01.40 - Matriz de Hilbert ⭐⭐⭐☆☆

Generar una matriz de Hilbert de orden $n$.

``` c
double **matriz_hilbert(int n);
```
<!-- c -->

**Definición:** $H_{ij} = \frac{1}{i+j-1}$

**Nota:** Las matrices de Hilbert son notoriamente mal condicionadas para
inversión.

(ej_b3_c01_41)=
### Ejercicio 3.01.41 - Matriz de Toeplitz ⭐⭐⭐☆☆

Verificar si una matriz es de Toeplitz (cada diagonal descendente de izquierda a
derecha tiene valores constantes).

``` c
bool es_toeplitz(int **matriz, int filas, int cols);
```
<!-- c -->

**Propiedad:** $a_{i,j} = a_{i+1,j+1}$

(ej_b3_c01_42)=
### Ejercicio 3.01.42 - Matriz circulante ⭐⭐⭐☆☆

Generar una matriz circulante a partir de su primera fila.

``` c
int **matriz_circulante(int *primera_fila, int n);
```
<!-- c -->

**Ejemplo con primera fila $[1, 2, 3, 4]$:**
$$C = \begin{pmatrix} 1 & 2 & 3 & 4 \\ 4 & 1 & 2 & 3 \\ 3 & 4 & 1 & 2 \\ 2 & 3 & 4 & 1 \end{pmatrix}$$

(ej_b3_c01_43)=
### Ejercicio 3.01.43 - Matriz de Hankel ⭐⭐⭐☆☆

Generar una matriz de Hankel (opuesta a Toeplitz: diagonales de arriba-derecha a
abajo-izquierda son constantes).

``` c
double **matriz_hankel(double *c, double *r, int n);
```
<!-- c -->

## Resolución de Sistemas de Ecuaciones

(ej_b3_c01_44)=
### Ejercicio 3.01.44 - Sustitución hacia adelante ⭐⭐☆☆☆

Resolver un sistema triangular inferior $Lx = b$.

``` c
double *sustitucion_adelante(double **L, double *b, int n);
```
<!-- c -->

**Algoritmo:** Resolver de arriba hacia abajo.

(ej_b3_c01_45)=
### Ejercicio 3.01.45 - Sustitución hacia atrás ⭐⭐☆☆☆

Resolver un sistema triangular superior $Ux = b$.

``` c
double *sustitucion_atras(double **U, double *b, int n);
```
<!-- c -->

**Algoritmo:** Resolver de abajo hacia arriba.

(ej_b3_c01_46)=
### Ejercicio 3.01.46 - Eliminación gaussiana completa ⭐⭐☆☆☆

Implementar eliminación gaussiana con pivoteo completo para resolver $Ax = b$.

``` c
double *resolver_sistema(double **A, double *b, int n);
```
<!-- c -->

(ej_b3_c01_47)=
### Ejercicio 3.01.47 - Método de Jacobi ⭐⭐☆☆☆

Resolver $Ax = b$ iterativamente usando el método de Jacobi.

``` c
double *metodo_jacobi(double **A, double *b, int n, double tolerancia,
                      int max_iter);
```
<!-- c -->

**Fórmula de iteración:**
$$x_i^{(k+1)} = \frac{1}{a_{ii}}\left(b_i - \sum_{j \neq i} a_{ij}x_j^{(k)}\right)$$

(ej_b3_c01_48)=
### Ejercicio 3.01.48 - Método de Gauss-Seidel ⭐⭐☆☆☆

Similar a Jacobi pero usa valores actualizados inmediatamente.

``` c
double *metodo_gauss_seidel(double **A, double *b, int n, double tolerancia,
                            int max_iter);
```
<!-- c -->

**Converge más rápido que Jacobi** para matrices con diagonal dominante.

## Operaciones Matriciales con Bloques

(ej_b3_c01_49)=
### Ejercicio 3.01.49 - Multiplicación por bloques ⭐⭐☆☆☆

Implementar multiplicación de matrices usando el algoritmo por bloques (más
eficiente para matrices grandes por mejor uso de caché).

``` c
double **multiplicar_bloques(double **A, double **B, int n, int tam_bloque);
```
<!-- c -->

(ej_b3_c01_50)=
### Ejercicio 3.01.50 - Transpuesta por bloques ⭐⭐☆☆☆

Implementar transpuesta usando bloques para mejor localidad de caché.

``` c
void transponer_bloques(double **matriz, int n, int tam_bloque);
```
<!-- c -->

(ej_b3_c01_51)=
### Ejercicio 3.01.51 - Strassen para matrices grandes ⭐⭐⭐☆☆

Implementar el algoritmo de Strassen para multiplicación rápida de matrices
grandes.

``` c
double **strassen(double **A, double **B, int n);
```
<!-- c -->

**Complejidad:** $O(n^{2.807})$ vs $O(n^3)$ del método tradicional.

(ej_b3_c01_52)=
## Ejercicio 3.01.52 - Inicializar y Mostrar Matriz ⭐☆☆☆☆

Creá una matriz 3×3, inicializala con valores del 1 al 9, y mostrala.

**Orientación:**
- `int matriz[3][3];`
- Lazos anidados para llenar: `matriz[i][j] = contador++`
- Lazos anidados para mostrar con formato

---

(ej_b3_c01_53)=
## Ejercicio 3.01.53 - Suma de Elementos ⭐☆☆☆☆

Calculá la suma de todos los elementos de una matriz.

**Orientación:**
- Recorré con lazos anidados
- Acumulá suma en variable
- `suma += matriz[i][j]`

---

(ej_b3_c01_54)=
## Ejercicio 3.01.54 - Máximo y Mínimo ⭐⭐☆☆☆

Encontrá el elemento mayor y menor de una matriz, junto con sus posiciones.

**Orientación:**
- Inicializá `max` y `min` con `matriz[0][0]`
- Recorré comparando
- Guardá posiciones (i, j) cuando actualizás max/min

---

(ej_b3_c01_55)=
## Ejercicio 3.01.55 - Matriz Identidad ⭐⭐☆☆☆

Generá una matriz identidad de tamaño N×N (1s en diagonal, 0s en el resto).

**Orientación:**
- `matriz[i][j] = (i == j) ? 1 : 0;`
- O con `if`: `matriz[i][j] = 1` si `i == j`, sino 0

---

(ej_b3_c01_56)=
## Ejercicio 3.01.56 - Transpuesta ⭐⭐⭐☆☆

Calculá la transpuesta de una matriz (intercambiar filas por columnas).

**Orientación:**
- Matriz original: M×N
- Transpuesta: N×M
- `transpuesta[j][i] = original[i][j]`
- Creá nueva matriz para el resultado

---

(ej_b3_c01_57)=
## Ejercicio 3.01.57 - Diagonal Principal ⭐⭐☆☆☆

Mostrá y sumá los elementos de la diagonal principal de una matriz cuadrada.

**Orientación:**
- Diagonal principal: elementos donde `i == j`
- Lazo de 0 a N-1: `suma += matriz[i][i]`

---

(ej_b3_c01_58)=
## Ejercicio 3.01.58 - Diagonal Secundaria ⭐⭐☆☆☆

Mostrá y sumá los elementos de la diagonal secundaria.

**Orientación:**
- Diagonal secundaria: elementos donde `i + j == N - 1`
- O directamente: `matriz[i][N-1-i]` para i de 0 a N-1

---

(ej_b3_c01_59)=
## Ejercicio 3.01.59 - Matriz Simétrica ⭐⭐⭐☆☆

Verificá si una matriz es simétrica (igual a su transpuesta).

**Orientación:**
- Matriz simétrica: `matriz[i][j] == matriz[j][i]` para todo i, j
- Solo necesitás verificar una mitad (triángulo superior vs inferior)
- Si encontrás diferencia, `return false` inmediatamente

---

(ej_b3_c01_60)=
## Ejercicio 3.01.60 - Suma de Matrices ⭐⭐⭐☆☆

Sumá dos matrices del mismo tamaño.

**Orientación:**
- Verificá que tengan las mismas dimensiones
- `resultado[i][j] = A[i][j] + B[i][j]`
- Creá matriz resultado

---

(ej_b3_c01_61)=
## Ejercicio 3.01.61 - Multiplicación por Escalar ⭐⭐⭐☆☆

Multiplicá todos los elementos de una matriz por un escalar.

**Orientación:**
- Leé el escalar
- `resultado[i][j] = matriz[i][j] * escalar`
- Podés modificar in-place o crear nueva matriz

---

(ej_b3_c01_62)=
## Ejercicio 3.01.62 - Buscar Elemento ⭐⭐⭐☆☆

Buscá un valor en la matriz. Si lo encontrás, mostrá su posición (fila,
columna).

**Orientación:**
- Recorré con lazos anidados
- Al encontrar: guardá posición, `break` del lazo interno
- Usá flag para `break` del lazo externo también

---

(ej_b3_c01_63)=
## Ejercicio 3.01.63 - Suma por Filas y Columnas ⭐⭐⭐☆☆

Calculá la suma de cada fila y la suma de cada columna.

**Orientación:**
- Array para sumas de filas: `suma_filas[M]`
- Array para sumas de columnas: `suma_cols[N]`
- Lazo por filas: suma cada fila
- Lazo por columnas: suma cada columna

---

(ej_b3_c01_64)=
## Ejercicio 3.01.64 - Borde de la Matriz ⭐⭐⭐☆☆

Mostrá solo los elementos del borde de una matriz.

**Orientación:**
- Primera fila completa: `i == 0`
- Última fila completa: `i == M-1`
- Primera columna: `j == 0`
- Última columna: `j == N-1`
- Usá condición: `if (i == 0 || i == M-1 || j == 0 || j == N-1)`

---

(ej_b3_c01_65)=
## Ejercicio 3.01.65 - Rotar Matriz 90 Grados ⭐⭐⭐⭐☆

Rotá una matriz cuadrada 90° en sentido horario.

**Orientación:**
- Para matriz N×N:
- Transponer primero: `temp[j][i] = matriz[i][j]`
- Luego invertir cada fila: `resultado[i][j] = temp[i][N-1-j]`
- O directamente: `resultado[j][N-1-i] = matriz[i][j]`

---

(ej_b3_c01_66)=
## Ejercicio 3.01.66 - Multiplicación de Matrices ⭐⭐⭐⭐⭐

Multiplicá dos matrices (A de M×N y B de N×P, resultado M×P).

**Algoritmo:**

```
C[i][j] = suma de A[i][k] * B[k][j] para k = 0..N-1
```

**Orientación:**
- Tres lazos anidados:
  - i: filas de A
  - j: columnas de B
  - k: suma de productos
- Verificá dimensiones compatibles (columnas de A = filas de B)

---

(ej_b3_c01_67)=
## Ejercicio 3.01.67 - Matriz en Espiral ⭐⭐⭐⭐⭐

Llenó una matriz en forma de espiral (desde afuera hacia adentro).

**Ejemplo 4×4:**

```
 1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7
```

**Orientación:**
- Usá cuatro límites: arriba, abajo, izquierda, derecha
- Recorré en orden: derecha, abajo, izquierda, arriba
- Ajustá límites después de cada lado
- Repetí hasta llenar todos los elementos

---

(ej_b3_c01_68)=
## Ejercicio 3.01.68 - Sudoku - Validador de Fila ⭐⭐⭐⭐☆

Verificá si una fila de un Sudoku es válida (números 1-9 sin repetir).

**Orientación:**
- Array booleano `visto[10]` (índices 1-9)
- Recorré la fila
- Si `visto[numero]` es true: número repetido, inválido
- Marca `visto[numero] = true`
- Al final, todos los 1-9 deben estar vistos

---

(ej_b3_c01_69)=
## Ejercicio 3.01.69 - Matriz Traspuesta In-Place ⭐⭐⭐⭐☆

Transponé una matriz cuadrada sin usar matriz auxiliar completa.

**Orientación:**
- Solo intercambiá elementos por encima de la diagonal
- `for (i = 0; i < N; i++)`
  - `for (j = i+1; j < N; j++)`
    - Intercambiá `matriz[i][j]` con `matriz[j][i]`

---

(ej_b3_c01_70)=
## Ejercicio 3.01.70 - Matriz de Distancias ⭐⭐⭐⭐⭐

Dadas N ciudades con coordenadas (x, y), calculá matriz de distancias entre
todas.

**Orientación:**
- Matriz de distancias D[i][j] = distancia de ciudad i a ciudad j
- Distancia euclidiana: `sqrt((x2-x1)² + (y2-y1)²)`
- Diagonal es 0 (distancia de ciudad a sí misma)
- Matriz es simétrica: `D[i][j] = D[j][i]`

---

(ej_b3_c01_71)=
## Ejercicio 3.01.71 - Juego de la Vida (Conway) ⭐⭐⭐⭐⭐

Implementá una generación del Juego de la Vida de Conway.

**Reglas:**
1. Celda viva con 2-3 vecinos vivos: sobrevive
2. Celda muerta con exactamente 3 vecinos vivos: nace
3. Otras: muere o permanece muerta

**Orientación:**
- Matriz actual y matriz siguiente
- Función para contar vecinos vivos (8 direcciones)
- Aplicá reglas para cada celda
- Copiá matriz siguiente a actual para próxima generación
- Vecinos: (i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j),
  (i+1,j+1)
- Cuidado con bordes

---

(ej_b3_c01_72)=
## Ejercicio 3.01.72 - s Adicionales ⭐⭐☆☆☆

(ej_b3_c01_73)=
### Ejercicio 3.01.73 - Matriz Pascal (Triángulo de Pascal) ⭐⭐⭐⭐☆

Generá el triángulo de Pascal como matriz.

**Orientación:**
- `matriz[i][0] = 1` (primera columna)
- `matriz[i][i] = 1` (diagonal)
- `matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j]` (resto)

---

(ej_b3_c01_74)=
### Ejercicio 3.01.74 - Matriz Antisimétrica ⭐⭐⭐⭐☆

Verificá si una matriz es antisimétrica (`A[i][j] = -A[j][i]`).

**Orientación:**
- Diagonal debe ser cero: `A[i][i] = 0`
- Verificá: `matriz[i][j] == -matriz[j][i]`

---

(ej_b3_c01_75)=
### Ejercicio 3.01.75 - Submatriz Mayor Suma ⭐⭐⭐⭐⭐

Encontrá la submatriz 2×2 con mayor suma dentro de una matriz más grande.

**Orientación:**
- Recorré todas las posiciones posibles para submatriz 2×2
- Para cada posición, sumá los 4 elementos
- Guardá máximo y posición

---

(ej_b3_c01_76)=
### Ejercicio 3.01.76 - Matriz Dispersa (Sparse) ⭐⭐⭐⭐⭐

Representá una matriz dispersa (muchos ceros) eficientemente.

**Orientación:**
- Estructura: `{fila, columna, valor}` solo para elementos != 0
- Array de estructuras
- Funciones: `asignar(f, c, val)`, `obtener(f, c)`, `mostrar()`

---

## Notas Finales

:::{tip} Patrones de Recorrido

**Por Filas (Row-Major):**
``` c
for (int i = 0; i < filas; i++)
{
    for (int j = 0; j < cols; j++)
    {
        // procesar matriz[i][j]
    }
}
```
<!-- c -->

**Por Columnas (Column-Major):**
``` c
for (int j = 0; j < cols; j++)
{
    for (int i = 0; i < filas; i++)
    {
        // procesar matriz[i][j]
    }
}
```
<!-- c -->

**Diagonal Principal:**
``` c
for (int i = 0; i < N; i++)
{
    // procesar matriz[i][i]
}
```
<!-- c -->

**Triangular Superior:**
``` c
for (int i = 0; i < N; i++)
{
    for (int j = i; j < N; j++)
    {
        // procesar matriz[i][j]
    }
}
```
<!-- c -->

**Triangular Inferior:**
``` c
for (int i = 0; i < N; i++)
{
    for (int j = 0; j <= i; j++)
    {
        // procesar matriz[i][j]
    }
}
```
<!-- c -->

:::
<!-- {tip} Patrones de Recorrido -->

:::{warning} Errores Comunes

1. **Confundir filas con columnas**
   ```c
   // MAL: intercambiado
   for (int i = 0; i < N; i++)
       for (int j = 0; j < M; j++)
           matriz[j][i] = ...; // Índices al revés
   ```

2. **Límites incorrectos**
   ```c
   // MAL: <= en lugar de <
   for (int i = 0; i <= filas; i++) // Acceso fuera de límites
   ```

3. **Olvidar inicializar**
   ```c
   int matriz[3][3]; // Sin inicializar, contiene basura
   // BIEN:
   int matriz[3][3] = {0}; // Todo en cero
   ```

4. **Modificar matriz mientras se recorre para copiar**
   ```c
   // MAL: corrompe datos
   for (int i = 0; i < N; i++)
       for (int j = 0; j < N; j++)
           matriz[i][j] = matriz[j][i]; // Transponer in-place mal hecho
   ```

:::
<!-- {warning} Errores Comunes -->

:::{note} Inicialización de Matrices

**Todo en cero:**
``` c
int matriz[3][4] = {0};
```
<!-- c -->

**Valores específicos:**
``` c
int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
```
<!-- c -->

**Parcial (resto en cero):**
``` c
int matriz[3][3] = {{1}, {2}, {3}}; // Primera columna con valores
```
<!-- c -->

:::
<!-- {note} Inicialización de Matrices -->

:::{tip} Eficiencia y Cache

- **Row-major es más eficiente en C:** Las matrices se almacenan por filas
- **Acceso secuencial:** `matriz[i][j++]` es más rápido que `matriz[i++][j]`
- **Localidad espacial:** Elementos consecutivos están cerca en memoria

``` c
// MÁS RÁPIDO (row-major)
for (i...)
    for (j...)
matriz[i][j]
    // MÁS LENTO (column-major)
    for (j...) for (i...) matriz[i][j]
```
<!-- c -->

:::
<!-- {tip} Eficiencia y Cache -->

:::{note} Matrices como Parámetros

```{code-block} c
:linenos:
// Opción 1: Tamaño fijo
void procesar(int matriz[3][4])
{
}
// Opción 2: VLA (C99)
void procesar(int filas, int cols, int matriz[filas][cols])
{
}
// Opción 3: Puntero con dimensiones
void procesar(int filas, int cols, int (*matriz)[cols])
{
}
```
<!-- {code-block} c -->

:::
<!-- {note} Matrices como Parámetros -->

Estas consignas cubren arrays bidimensionales desde operaciones básicas hasta
algoritmos complejos, preparando para trabajar con matrices dinámicas en apuntes
posteriores.

