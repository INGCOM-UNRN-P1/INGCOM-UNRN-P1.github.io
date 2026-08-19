---
title: "Ejercicios de matrices"
short_title: "7. Matrices"
---

# Ejercicios de matrices

## Acerca de

Ejercicios para trabajar con arreglos bidimensionales (matrices), tanto
estáticas como dinámicas.

Para profundizar en los conceptos teóricos, podés consultar el siguiente
capítulo del apunte:
- [Matrices](../../apunte/bloque_4_dinamica_indireccion/3_matrices.md)

## Operaciones Básicas
(ejercicio_21_1)=
### Ejercicio 21.1 - Mostrar matriz ⭐⭐⭐☆☆

#### Descripción
Escribir una función que reciba una matriz (un arreglo 2D), sus dimensiones
(filas y columnas), y la imprima en la consola de una forma clara y ordenada,
fila por fila.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Una matriz 2x3: 
[[1, 2, 3], [4, 5, 6]]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Matriz (2x3):
[ 1, 2, 3 ]
[ 4, 5, 6 ]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones

-   **Proceso:** Se necesitan dos lazos `for` anidados para recorrer la matriz.
-   El lazo exterior itera sobre las filas (desde `0` hasta `filas-1`).
-   El lazo interior itera sobre las columnas de la fila actual (desde `0` hasta
    `columnas-1`).
-   Dentro del lazo interior, se imprime cada elemento `matriz[fila][columna]`.
-   Después de que el lazo interior termina (al final de cada fila), se debe
    imprimir un carácter de nueva línea (`\n`) para pasar a la siguiente fila.

:::
<!-- {hint} Lógica y Consideraciones -->

::::{hint} Diagrama
:class: dropdown

:::{mermaid}

flowchart TD
    A["Inicio"] --> B["fila = 0"]
    B --> C{"fila < num_filas?"}
    C -- Sí --> D["Imprimir '['"]
    D --> E["col = 0"]
    E --> F{"col < num_cols?"}
    F -- Sí --> G["Imprimir mat[fila][col]"]
    G --> H["col = col + 1"]
    H --> F
    F -- No --> I["Imprimir ']' y Salto de Línea"]
    I --> J["fila = fila + 1"]
    J --> C
    C -- No --> K["Fin"]

:::
<!-- {mermaid} -->

::::
<!-- {hint} Diagrama -->

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

```{code-block} pseudocode
:linenos:
PROCEDIMIENTO mostrar_matriz(matriz, filas, columnas)
INICIO
    PARA f DESDE 0 HASTA filas-1 HACER
        ESCRIBIR "[ " SIN SALTO DE LÍNEA
        PARA c DESDE 0 HASTA columnas-1 HACER
            ESCRIBIR matriz[f][c]
            SI c < columnas-1 ENTONCES
                ESCRIBIR ", " SIN SALTO DE LÍNEA
            FIN SI
        FIN PARA
        ESCRIBIR " ]" CON SALTO DE LÍNEA
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_2)=
### Ejercicio 21.2 - Multiplicación por un escalar ⭐⭐☆☆☆

#### Descripción
Implementar una función que multiplique cada elemento de una matriz por un
número escalar dado. La operación modifica la matriz original (_in-place_).

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Matriz: [[1, 2], [3, 4]]
Escalar: 5
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Matriz modificada: [[5, 10], [15, 20]]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones

-   **Fórmula:** Para cada elemento $a_{ij}$ de la matriz $A$, el nuevo elemento
    es $b_{ij} = k \cdot a_{ij}$.
-   **Proceso:** Se utilizan dos lazos anidados para recorrer cada elemento de
    la matriz.
-   En el cuerpo del lazo interior, se multiplica el elemento
    `matriz[fila][columna]` por el escalar y se guarda el resultado en la misma
    posición.

:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

```{code-block} pseudocode
:linenos:
PROCEDIMIENTO multiplicar_por_escalar(REF matriz, filas, columnas, escalar)
INICIO
    PARA f DESDE 0 HASTA filas-1 HACER
        PARA c DESDE 0 HASTA columnas-1 HACER
            matriz[f][c] = matriz[f][c] * escalar
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->

## Aritmética Matricial
(ejercicio_21_3)=
### Ejercicio 21.3 - Suma de matrices ⭐⭐⭐☆☆

#### Descripción
Implementar una función que sume dos matrices, `A` y `B`, y almacene el
resultado en una tercera matriz, `C`. La suma de matrices solo es posible si
ambas tienen las mismas dimensiones.

::::{tab-set}

:::{tab-item} Entrada
:sync: tab1
``` text
Matriz A: [[1, 2], [3, 4]]
Matriz B: [[5, 6], [7, 8]]
```
<!-- text -->

:::
<!-- {tab-item} Entrada -->
:::{tab-item} Salida
:sync: tab2
``` text
Matriz C: [[6, 8], [10, 12]]
```
<!-- text -->

:::
<!-- {tab-item} Salida -->

::::
<!-- {tab-set} -->

:::{hint} Lógica y Consideraciones

-   **Fórmula:** La suma se realiza elemento a elemento: $c_{ij} = a_{ij} +
    b_{ij}$.
-   **Precondición:** Las dimensiones de la Matriz A y la Matriz B deben ser
    idénticas.
-   **Proceso:** Recorrer las matrices con lazos anidados. En cada posición `(f,
    c)`, calcular `C[f][c] = A[f][c] + B[f][c]`.

:::
<!-- {hint} Lógica y Consideraciones -->

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

```{code-block} pseudocode
:linenos:
PROCEDIMIENTO sumar_matrices(A, B, REF C, filas, columnas)
INICIO
    PARA f DESDE 0 HASTA filas-1 HACER
        PARA c DESDE 0 HASTA columnas-1 HACER
            C[f][c] = A[f][c] + B[f][c]
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_4)=
### Ejercicio 21.4 - Multiplicación de matrices ⭐⭐⭐☆☆

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

::::{hint} Diagrama
:class: dropdown

:::{mermaid}

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->

## Manipulación
(ejercicio_21_5)=
### Ejercicio 21.5 - Transposición ⭐⭐☆☆☆

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_6)=
### Ejercicio 21.6 - Suma de diagonales ⭐⭐☆☆☆

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->

## Generación
(ejercicio_21_7)=
### Ejercicio 21.7 - Matriz identidad ⭐⭐⭐☆☆

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_8)=
## Ejercicio 21.8 - s Adicionales de Matrices ⭐⭐⭐☆☆

(ejercicio_21_9)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.9 - Matriz simétrica ⭐⭐⭐☆☆

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

::::{hint} Diagrama
:class: dropdown
El diagrama muestra los pares de elementos que deben ser iguales. Solo es
necesario verificar una mitad del triángulo (excluyendo la diagonal).

:::{mermaid}

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_10)=
### Ejercicio 21.10 - Suma por Filas y Columnas ⭐⭐☆☆☆

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

:::{hint} Ayuda (Pseudocódigo Eficiente)
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

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo Eficiente) -->
(ejercicio_21_11)=
### Ejercicio 21.11 - Elemento "Silla" ⭐⭐☆☆☆

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->
(ejercicio_21_12)=
## Ejercicio 21.12 - s de Matrices Dinámicas ⭐⭐⭐☆☆

(ejercicio_21_13)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar el retorno de asignación de memoria y
    garantizar la liberación total de recursos en caso de error.
-   **[*plus ultra*]:** Verificar la ausencia de fugas de memoria (*memory
    leaks*) mediante Valgrind o AddressSanitizer.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.13 - Crear y llenar matriz dinámica ⭐⭐⭐☆☆

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

:::{hint} Ayuda (Pseudocódigo)
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

-   **[*plus ultra*]:** Verificar el retorno de asignación de memoria y
    garantizar la liberación total de recursos en caso de error.
-   **[*plus ultra*]:** Verificar la ausencia de fugas de memoria (*memory
    leaks*) mediante Valgrind o AddressSanitizer.

:::
<!-- {hint} Ayuda (Pseudocódigo) -->

## Más Algoritmos con Matrices
(ejercicio_21_14)=
### Ejercicio 21.14 - Reflejar matriz ⭐⭐⭐☆☆

Implementar dos funciones: una que refleje una matriz horizontalmente (la
primera fila se intercambia con la última, la segunda con la penúltima, etc.) y
otra que la refleje verticalmente (la primera columna con la última, etc.).
(ejercicio_21_15)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.15 - Intercambiar filas o columnas ⭐⭐☆☆☆

Crear funciones `intercambiar_filas(mat, f1, f2)` e `intercambiar_columnas(mat,
c1, c2)` que modifiquen la matriz intercambiando los elementos de las filas o
columnas especificadas.
(ejercicio_21_16)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.16 - Búsqueda de submatriz ⭐⭐⭐☆☆

Escribir una función que determine si una matriz pequeña `B` (de `k x l`) se
encuentra dentro de una matriz más grande `A` (de `m x n`). La función debe
devolver las coordenadas de la esquina superior izquierda de la primera
ocurrencia, o `(-1, -1)` si no se encuentra.
(ejercicio_21_17)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.17 - Determinante de matriz 3x3 ⭐⭐⭐☆☆

Calcular el determinante de una matriz 3x3 utilizando la Regla de Sarrus.
(ejercicio_21_18)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.18 - Suavizado de matriz (Filtro de caja) ⭐⭐⭐☆☆

Implementar un filtro de "suavizado" o "blur". Para cada elemento de la matriz,
su nuevo valor será el promedio de sus 8 vecinos y él mismo. Los elementos en
los bordes requerirán un manejo especial.
(ejercicio_21_19)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.19 - Detección de bordes (Operador de Sobel) ⭐⭐☆☆☆

Aplicar un operador de Sobel simple para la detección de bordes. Esto implica
"convolucionar" la matriz con un `kernel` (otra matriz pequeña, ej. 3x3) para
resaltar las diferencias de intensidad, como los bordes.
(ejercicio_21_20)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.20 - Matriz de permutación ⭐⭐⭐☆☆

Verificar si una matriz cuadrada es una matriz de permutación. Esta es una
matriz binaria (solo 0s y 1s) que tiene exactamente un `1` en cada fila y en
cada columna.
(ejercicio_21_21)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.21 - Producto de Hadamard ⭐⭐☆☆☆

Implementar el producto de Hadamard (o producto elemento a elemento) de dos
matrices `A` y `B` de las mismas dimensiones. La matriz resultante `C` se define
como $c_{ij} = a_{ij} \cdot b_{ij}$.
(ejercicio_21_22)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.22 - Rellenar con triángulo de Pascal ⭐⭐☆☆☆

Escribir una función que llene una matriz `N x N` con los valores del Triángulo
de Pascal. El elemento `(i, j)` debe ser $\binom{i}{j}$.
(ejercicio_21_23)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.23 - Matriz antisimétrica ⭐⭐⭐☆☆

Verificar si una matriz cuadrada es antisimétrica. Una matriz `A` es
antisimétrica si su transpuesta es igual a su negativa, es decir, $A^T = -A$.
Esto implica que $a_{ij} = -a_{ji}$ y que todos los elementos de la diagonal
principal deben ser cero.

## Operaciones Avanzadas con Matrices
(ejercicio_21_24)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.24 - Norma de matriz ⭐⭐⭐☆☆

Implementar funciones que calculen diferentes normas de una matriz.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_21_25)=
### Ejercicio 21.25 - Traza de matriz ⭐⭐⭐☆☆

Calcular la traza de una matriz cuadrada (suma de elementos de la diagonal
principal).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double traza(double **matriz, int n);
```
<!-- c -->

$$\text{tr}(A) = \sum_{i=1}^n a_{ii}$$
(ejercicio_21_26)=
### Ejercicio 21.26 - Rango de matriz ⭐⭐⭐☆☆

Implementar un algoritmo para calcular el rango de una matriz usando eliminación
gaussiana.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
int calcular_rango(double **matriz, int filas, int cols);
```
<!-- c -->

**Estrategia:** Reducir la matriz a forma escalonada y contar filas no nulas.
(ejercicio_21_27)=
### Ejercicio 21.27 - Matriz de cofactores ⭐⭐⭐☆☆

Calcular la matriz de cofactores para una matriz cuadrada.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_cofactores(double **matriz, int n);
```
<!-- c -->

El cofactor $C_{ij}$ se calcula como: $C_{ij} = (-1)^{i+j} M_{ij}$ donde
$M_{ij}$ es el menor de la matriz (determinante de la submatriz obtenida
eliminando fila $i$ y columna $j$).
(ejercicio_21_28)=
### Ejercicio 21.28 - Matriz inversa ⭐⭐⭐☆☆

Implementar el cálculo de la inversa de una matriz usando el método de
Gauss-Jordan.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_inversa(double **matriz, int n, bool *invertible);
```
<!-- c -->

**Algoritmo:**
1. Crear matriz aumentada $[A | I]$
2. Aplicar eliminación Gauss-Jordan
3. Si se obtiene $[I | A^{-1}]$, retornar $A^{-1}$
4. Si no es posible, la matriz no es invertible
(ejercicio_21_29)=
### Ejercicio 21.29 - Potencia de matriz ⭐⭐⭐☆☆

Calcular $A^n$ para una matriz cuadrada $A$ y un exponente entero $n$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **potencia_matriz(double **matriz, int tam, int exponente);
```
<!-- c -->

**Optimización:** Usar exponenciación rápida para $O(\log n)$ multiplicaciones.
(ejercicio_21_30)=
### Ejercicio 21.30 - Descomposición LU ⭐⭐☆☆☆

Implementar la descomposición LU de una matriz: $A = LU$ donde $L$ es triangular
inferior y $U$ es triangular superior.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool descomposicion_lu(double **A, int n, double **L, double **U);
```
<!-- c -->

**Aplicación:** Resolver sistemas de ecuaciones lineales eficientemente.
(ejercicio_21_31)=
### Ejercicio 21.31 - Valores propios (Power Method) ⭐⭐☆☆☆

Implementar el método de la potencia para calcular el valor propio dominante de
una matriz.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double valor_propio_dominante(double **matriz, int n, double tolerancia);
```
<!-- c -->

**Algoritmo:**
1. Comenzar con vector aleatorio $v$
2. Iterar: $v_{k+1} = \frac{Av_k}{||Av_k||}$
3. El valor propio es $\lambda = v^T A v$
(ejercicio_21_32)=
### Ejercicio 21.32 - Matriz de rotación ⭐⭐⭐☆☆

Implementar funciones para crear y aplicar matrices de rotación 2D y 3D.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_21_33)=
### Ejercicio 21.33 - Matriz de proyección ⭐⭐⭐☆☆

Crear matriz de proyección ortogonal sobre un vector.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_proyeccion(double *vector, int n);
```
<!-- c -->

**Fórmula:** $P = \frac{vv^T}{v^Tv}$

## Algoritmos de Procesamiento de Imágenes

Considerar una matriz como una imagen en escala de grises donde cada elemento
representa la intensidad de un píxel.
(ejercicio_21_34)=
### Ejercicio 21.34 - Umbralización (Thresholding) ⭐⭐☆☆☆

Convertir una imagen en escala de grises a binaria (solo 0 y 255) usando un
umbral.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void umbralizar(int **imagen, int filas, int cols, int umbral);
```
<!-- c -->

**Algoritmo:** Si `pixel >= umbral`, asignar 255, sino asignar 0.
(ejercicio_21_35)=
### Ejercicio 21.35 - Histograma de Imagen ⭐⭐☆☆☆

Calcular el histograma de una imagen (frecuencia de cada nivel de intensidad).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void calcular_histograma(int **imagen, int filas, int cols, int *histograma);
```
<!-- c -->

El histograma tiene 256 posiciones (0-255) que cuentan la frecuencia de cada
intensidad.
(ejercicio_21_36)=
### Ejercicio 21.36 - Ecualización de Histograma ⭐⭐☆☆☆

Mejorar el contraste de una imagen mediante ecualización de histograma.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void ecualizar_histograma(int **imagen, int filas, int cols);
```
<!-- c -->

**Algoritmo:**
1. Calcular histograma
2. Calcular función de distribución acumulativa (CDF)
3. Normalizar CDF y aplicar transformación a cada píxel
(ejercicio_21_37)=
### Ejercicio 21.37 - Filtro gaussiano ⭐⭐☆☆☆

Implementar un filtro gaussiano para suavizado de imagen.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void filtro_gaussiano(double **imagen, int filas, int cols, double sigma);
```
<!-- c -->

**Kernel gaussiano 3x3:**
$$K = \frac{1}{16}\begin{pmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{pmatrix}$$
(ejercicio_21_38)=
### Ejercicio 21.38 - Detección de bordes (Laplaciano) ⭐⭐☆☆☆

Aplicar el operador Laplaciano para detectar bordes.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void detectar_bordes_laplaciano(int **imagen, int filas, int cols,
                                int **resultado);
```
<!-- c -->

**Kernel Laplaciano:**
$$K = \begin{pmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{pmatrix}$$

## Matrices Especiales
(ejercicio_21_39)=
### Ejercicio 21.39 - Matriz de Vandermonde ⭐⭐⭐☆☆

Generar una matriz de Vandermonde a partir de un vector.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_vandermonde(double *x, int n, int m);
```
<!-- c -->

**Definición:** $V_{ij} = x_i^{j-1}$

**Ejemplo con $x = [1, 2, 3]$ y $m = 4$:**
$$V = \begin{pmatrix} 1 & 1 & 1 & 1 \\ 1 & 2 & 4 & 8 \\ 1 & 3 & 9 & 27 \end{pmatrix}$$
(ejercicio_21_40)=
### Ejercicio 21.40 - Matriz de Hilbert ⭐⭐⭐☆☆

Generar una matriz de Hilbert de orden $n$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_hilbert(int n);
```
<!-- c -->

**Definición:** $H_{ij} = \frac{1}{i+j-1}$

**Nota:** Las matrices de Hilbert son notoriamente mal condicionadas para
inversión.
(ejercicio_21_41)=
### Ejercicio 21.41 - Matriz de Toeplitz ⭐⭐⭐☆☆

Verificar si una matriz es de Toeplitz (cada diagonal descendente de izquierda a
derecha tiene valores constantes).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool es_toeplitz(int **matriz, int filas, int cols);
```
<!-- c -->

**Propiedad:** $a_{i,j} = a_{i+1,j+1}$
(ejercicio_21_42)=
### Ejercicio 21.42 - Matriz circulante ⭐⭐⭐☆☆

Generar una matriz circulante a partir de su primera fila.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
int **matriz_circulante(int *primera_fila, int n);
```
<!-- c -->

**Ejemplo con primera fila $[1, 2, 3, 4]$:**
$$C = \begin{pmatrix} 1 & 2 & 3 & 4 \\ 4 & 1 & 2 & 3 \\ 3 & 4 & 1 & 2 \\ 2 & 3 & 4 & 1 \end{pmatrix}$$
(ejercicio_21_43)=
### Ejercicio 21.43 - Matriz de Hankel ⭐⭐⭐☆☆

Generar una matriz de Hankel (opuesta a Toeplitz: diagonales de arriba-derecha a
abajo-izquierda son constantes).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **matriz_hankel(double *c, double *r, int n);
```
<!-- c -->

## Resolución de Sistemas de Ecuaciones
(ejercicio_21_44)=
### Ejercicio 21.44 - Sustitución hacia adelante ⭐⭐☆☆☆

Resolver un sistema triangular inferior $Lx = b$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double *sustitucion_adelante(double **L, double *b, int n);
```
<!-- c -->

**Algoritmo:** Resolver de arriba hacia abajo.
(ejercicio_21_45)=
### Ejercicio 21.45 - Sustitución hacia atrás ⭐⭐☆☆☆

Resolver un sistema triangular superior $Ux = b$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double *sustitucion_atras(double **U, double *b, int n);
```
<!-- c -->

**Algoritmo:** Resolver de abajo hacia arriba.
(ejercicio_21_46)=
### Ejercicio 21.46 - Eliminación gaussiana completa ⭐⭐☆☆☆

Implementar eliminación gaussiana con pivoteo completo para resolver $Ax = b$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double *resolver_sistema(double **A, double *b, int n);
```
<!-- c -->
(ejercicio_21_47)=
### Ejercicio 21.47 - Método de Jacobi ⭐⭐☆☆☆

Resolver $Ax = b$ iterativamente usando el método de Jacobi.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double *metodo_jacobi(double **A, double *b, int n, double tolerancia,
                      int max_iter);
```
<!-- c -->

**Fórmula de iteración:**
$$x_i^{(k+1)} = \frac{1}{a_{ii}}\left(b_i - \sum_{j \neq i} a_{ij}x_j^{(k)}\right)$$
(ejercicio_21_48)=
### Ejercicio 21.48 - Método de Gauss-Seidel ⭐⭐☆☆☆

Similar a Jacobi pero usa valores actualizados inmediatamente.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double *metodo_gauss_seidel(double **A, double *b, int n, double tolerancia,
                            int max_iter);
```
<!-- c -->

**Converge más rápido que Jacobi** para matrices con diagonal dominante.

## Operaciones Matriciales con Bloques
(ejercicio_21_49)=
### Ejercicio 21.49 - Multiplicación por bloques ⭐⭐☆☆☆

Implementar multiplicación de matrices usando el algoritmo por bloques (más
eficiente para matrices grandes por mejor uso de caché).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **multiplicar_bloques(double **A, double **B, int n, int tam_bloque);
```
<!-- c -->
(ejercicio_21_50)=
### Ejercicio 21.50 - Transpuesta por bloques ⭐⭐☆☆☆

Implementar transpuesta usando bloques para mejor localidad de caché.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void transponer_bloques(double **matriz, int n, int tam_bloque);
```
<!-- c -->
(ejercicio_21_51)=
### Ejercicio 21.51 - Strassen para matrices grandes ⭐⭐⭐☆☆

Implementar el algoritmo de Strassen para multiplicación rápida de matrices
grandes.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double **strassen(double **A, double **B, int n);
```
<!-- c -->

**Complejidad:** $O(n^{2.807})$ vs $O(n^3)$ del método tradicional.
(ejercicio_21_52)=
## Ejercicio 21.52 - Inicializar y Mostrar Matriz ⭐☆☆☆☆

Creá una matriz 3×3, inicializala con valores del 1 al 9, y mostrala.

**Orientación:**
- `int matriz[3][3];`
- Lazos anidados para llenar: `matriz[i][j] = contador++`
- Lazos anidados para mostrar con formato


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_53)=
## Ejercicio 21.53 - Suma de Elementos ⭐☆☆☆☆

Calculá la suma de todos los elementos de una matriz.

**Orientación:**
- Recorré con lazos anidados
- Acumulá suma en variable
- `suma += matriz[i][j]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_54)=
## Ejercicio 21.54 - Máximo y Mínimo ⭐⭐☆☆☆

Encontrá el elemento mayor y menor de una matriz, junto con sus posiciones.

**Orientación:**
- Inicializá `max` y `min` con `matriz[0][0]`
- Recorré comparando
- Guardá posiciones (i, j) cuando actualizás max/min


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_55)=
## Ejercicio 21.55 - Matriz Identidad ⭐⭐☆☆☆

Generá una matriz identidad de tamaño N×N (1s en diagonal, 0s en el resto).

**Orientación:**
- `matriz[i][j] = (i == j) ? 1 : 0;`
- O con `if`: `matriz[i][j] = 1` si `i == j`, sino 0


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_56)=
## Ejercicio 21.56 - Transpuesta ⭐⭐⭐☆☆

Calculá la transpuesta de una matriz (intercambiar filas por columnas).

**Orientación:**
- Matriz original: M×N
- Transpuesta: N×M
- `transpuesta[j][i] = original[i][j]`
- Creá nueva matriz para el resultado


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_57)=
## Ejercicio 21.57 - Diagonal Principal ⭐⭐☆☆☆

Mostrá y sumá los elementos de la diagonal principal de una matriz cuadrada.

**Orientación:**
- Diagonal principal: elementos donde `i == j`
- Lazo de 0 a N-1: `suma += matriz[i][i]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_58)=
## Ejercicio 21.58 - Diagonal Secundaria ⭐⭐☆☆☆

Mostrá y sumá los elementos de la diagonal secundaria.

**Orientación:**
- Diagonal secundaria: elementos donde `i + j == N - 1`
- O directamente: `matriz[i][N-1-i]` para i de 0 a N-1


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_59)=
## Ejercicio 21.59 - Matriz Simétrica ⭐⭐⭐☆☆

Verificá si una matriz es simétrica (igual a su transpuesta).

**Orientación:**
- Matriz simétrica: `matriz[i][j] == matriz[j][i]` para todo i, j
- Solo necesitás verificar una mitad (triángulo superior vs inferior)
- Si encontrás diferencia, `return false` inmediatamente


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_60)=
## Ejercicio 21.60 - Suma de Matrices ⭐⭐⭐☆☆

Sumá dos matrices del mismo tamaño.

**Orientación:**
- Verificá que tengan las mismas dimensiones
- `resultado[i][j] = A[i][j] + B[i][j]`
- Creá matriz resultado


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_61)=
## Ejercicio 21.61 - Multiplicación por Escalar ⭐⭐⭐☆☆

Multiplicá todos los elementos de una matriz por un escalar.

**Orientación:**
- Leé el escalar
- `resultado[i][j] = matriz[i][j] * escalar`
- Podés modificar in-place o crear nueva matriz


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_62)=
## Ejercicio 21.62 - Buscar Elemento ⭐⭐⭐☆☆

Buscá un valor en la matriz. Si lo encontrás, mostrá su posición (fila,
columna).

**Orientación:**
- Recorré con lazos anidados
- Al encontrar: guardá posición, `break` del lazo interno
- Usá flag para `break` del lazo externo también


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_63)=
## Ejercicio 21.63 - Suma por Filas y Columnas ⭐⭐⭐☆☆

Calculá la suma de cada fila y la suma de cada columna.

**Orientación:**
- Array para sumas de filas: `suma_filas[M]`
- Array para sumas de columnas: `suma_cols[N]`
- Lazo por filas: suma cada fila
- Lazo por columnas: suma cada columna


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_64)=
## Ejercicio 21.64 - Borde de la Matriz ⭐⭐⭐☆☆

Mostrá solo los elementos del borde de una matriz.

**Orientación:**
- Primera fila completa: `i == 0`
- Última fila completa: `i == M-1`
- Primera columna: `j == 0`
- Última columna: `j == N-1`
- Usá condición: `if (i == 0 || i == M-1 || j == 0 || j == N-1)`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_65)=
## Ejercicio 21.65 - Rotar Matriz 90 Grados ⭐⭐⭐⭐☆

Rotá una matriz cuadrada 90° en sentido horario.

**Orientación:**
- Para matriz N×N:
- Transponer primero: `temp[j][i] = matriz[i][j]`
- Luego invertir cada fila: `resultado[i][j] = temp[i][N-1-j]`
- O directamente: `resultado[j][N-1-i] = matriz[i][j]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_66)=
## Ejercicio 21.66 - Multiplicación de Matrices ⭐⭐⭐⭐⭐

Multiplicá dos matrices (A de M×N y B de N×P, resultado M×P).

**Algoritmo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_21_67)=
## Ejercicio 21.67 - Matriz en Espiral ⭐⭐⭐⭐⭐

Llenó una matriz en forma de espiral (desde afuera hacia adentro).

**Ejemplo 4×4:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_21_68)=
## Ejercicio 21.68 - Sudoku - Validador de Fila ⭐⭐⭐⭐☆

Verificá si una fila de un Sudoku es válida (números 1-9 sin repetir).

**Orientación:**
- Array booleano `visto[10]` (índices 1-9)
- Recorré la fila
- Si `visto[numero]` es true: número repetido, inválido
- Marca `visto[numero] = true`
- Al final, todos los 1-9 deben estar vistos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_69)=
## Ejercicio 21.69 - Matriz Traspuesta In-Place ⭐⭐⭐⭐☆

Transponé una matriz cuadrada sin usar matriz auxiliar completa.

**Orientación:**
- Solo intercambiá elementos por encima de la diagonal
- `for (i = 0; i < N; i++)`
  - `for (j = i+1; j < N; j++)`
    - Intercambiá `matriz[i][j]` con `matriz[j][i]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_70)=
## Ejercicio 21.70 - Matriz de Distancias ⭐⭐⭐⭐⭐

Dadas N ciudades con coordenadas (x, y), calculá matriz de distancias entre
todas.

**Orientación:**
- Matriz de distancias D[i][j] = distancia de ciudad i a ciudad j
- Distancia euclidiana: `sqrt((x2-x1)² + (y2-y1)²)`
- Diagonal es 0 (distancia de ciudad a sí misma)
- Matriz es simétrica: `D[i][j] = D[j][i]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_71)=
## Ejercicio 21.71 - Juego de la Vida (Conway) ⭐⭐⭐⭐⭐

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


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_72)=
## Ejercicio 21.72 - s Adicionales ⭐⭐☆☆☆

(ejercicio_21_73)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 21.73 - Matriz Pascal (Triángulo de Pascal) ⭐⭐⭐⭐☆

Generá el triángulo de Pascal como matriz.

**Orientación:**
- `matriz[i][0] = 1` (primera columna)
- `matriz[i][i] = 1` (diagonal)
- `matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j]` (resto)


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_74)=
### Ejercicio 21.74 - Matriz Antisimétrica ⭐⭐⭐⭐☆

Verificá si una matriz es antisimétrica (`A[i][j] = -A[j][i]`).

**Orientación:**
- Diagonal debe ser cero: `A[i][i] = 0`
- Verificá: `matriz[i][j] == -matriz[j][i]`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_75)=
### Ejercicio 21.75 - Submatriz Mayor Suma ⭐⭐⭐⭐⭐

Encontrá la submatriz 2×2 con mayor suma dentro de una matriz más grande.

**Orientación:**
- Recorré todas las posiciones posibles para submatriz 2×2
- Para cada posición, sumá los 4 elementos
- Guardá máximo y posición


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por
    filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren
    estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_21_76)=
### Ejercicio 21.76 - Matriz Dispersa (Sparse) ⭐⭐⭐⭐⭐

Representá una matriz dispersa (muchos ceros) eficientemente.

**Orientación:**
- Estructura: `{fila, columna, valor}` solo para elementos != 0
- Array de estructuras
- Funciones: `asignar(f, c, val)`, `obtener(f, c)`, `mostrar()`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

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

