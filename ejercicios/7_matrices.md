---
title: Ejercicios de matrices
short_title: 7. Matrices
---

Ejercicios para trabajar con arreglos bidimensionales (matrices), tanto
estáticas como dinámicas.

---

## 1: Operaciones Básicas

### 1.1: Mostrar Matriz

#### Descripción
Escribir una función que reciba una matriz (un arreglo 2D), sus dimensiones (filas y columnas), y la imprima en la consola de una forma clara y ordenada, fila por fila.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Una matriz 2x3: 
[[1, 2, 3], [4, 5, 6]]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Matriz (2x3):
[ 1, 2, 3 ]
[ 4, 5, 6 ]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Proceso:** Se necesitan dos lazos `for` anidados para recorrer la matriz.
-   El lazo exterior itera sobre las filas (desde `0` hasta `filas-1`).
-   El lazo interior itera sobre las columnas de la fila actual (desde `0` hasta `columnas-1`).
-   Dentro del lazo interior, se imprime cada elemento `matriz[fila][columna]`.
-   Después de que el lazo interior termina (al final de cada fila), se debe imprimir un carácter de nueva línea (`\n`) para pasar a la siguiente fila.
:::

:::{hint} Diagrama
:class: dropdown

````{mermaid}
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
````
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
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
````
:::

### 1.2: Multiplicación por un escalar

#### Descripción
Implementar una función que multiplique cada elemento de una matriz por un número escalar dado. La operación modifica la matriz original (_in-place_).

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Matriz: [[1, 2], [3, 4]]
Escalar: 5
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Matriz modificada: [[5, 10], [15, 20]]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Fórmula:** Para cada elemento $a_{ij}$ de la matriz $A$, el nuevo elemento es $b_{ij} = k \cdot a_{ij}$.
-   **Proceso:** Se utilizan dos lazos anidados para recorrer cada elemento de la matriz.
-   En el cuerpo del lazo interior, se multiplica el elemento `matriz[fila][columna]` por el escalar y se guarda el resultado en la misma posición.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
PROCEDIMIENTO multiplicar_por_escalar(REF matriz, filas, columnas, escalar)
INICIO
    PARA f DESDE 0 HASTA filas-1 HACER
        PARA c DESDE 0 HASTA columnas-1 HACER
            matriz[f][c] = matriz[f][c] * escalar
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
````
:::

---

## 2: Aritmética Matricial

### 2.1: Suma de matrices

#### Descripción
Implementar una función que sume dos matrices, `A` y `B`, y almacene el resultado en una tercera matriz, `C`. La suma de matrices solo es posible si ambas tienen las mismas dimensiones.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Matriz A: [[1, 2], [3, 4]]
Matriz B: [[5, 6], [7, 8]]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Matriz C: [[6, 8], [10, 12]]
```text
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Fórmula:** La suma se realiza elemento a elemento: $c_{ij} = a_{ij} + b_{ij}$.
-   **Precondición:** Las dimensiones de la Matriz A y la Matriz B deben ser idénticas.
-   **Proceso:** Recorrer las matrices con lazos anidados. En cada posición `(f, c)`, calcular `C[f][c] = A[f][c] + B[f][c]`.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
PROCEDIMIENTO sumar_matrices(A, B, REF C, filas, columnas)
INICIO
    PARA f DESDE 0 HASTA filas-1 HACER
        PARA c DESDE 0 HASTA columnas-1 HACER
            C[f][c] = A[f][c] + B[f][c]
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
````
:::

### 2.2: Multiplicación de matrices

#### Descripción
Implementar la multiplicación de dos matrices, `A` (de $m \times n$) y `B` (de $n \times p$), cuyo resultado es una nueva matriz `C` (de $m \times p$).

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Matriz A (2x3): [[1, 2, 3], [4, 5, 6]]
Matriz B (3x2): [[7, 8], [9, 10], [11, 12]]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Matriz C (2x2): [[58, 64], [139, 154]]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Precondición:** El número de columnas de la matriz `A` debe ser igual al número de filas de la matriz `B`.
-   **Fórmula:** Cada elemento $c_{ij}$ de la matriz resultado se calcula como el producto punto de la fila `i` de `A` y la columna `j` de `B`: $c_{ij} = \sum_{k=0}^{n-1} a_{ik} \cdot b_{kj}$.
-   **Proceso:** Se necesitan tres lazos anidados:
    1.  Lazo para las filas de `C` (y `A`), de `i=0` a `m-1`.
    2.  Lazo para las columnas de `C` (y `B`), de `j=0` a `p-1`.
    3.  Lazo para la suma del producto punto, de `k=0` a `n-1`.
:::

:::{hint} Diagrama
:class: dropdown

````{mermaid}
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
````
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
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
````
:::

---

## 3: Manipulación

### 3.1: Transposición

#### Descripción
Calcular la transpuesta $A^T$ de una matriz $A$. La transposición se obtiene intercambiando las filas por las columnas.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Matriz A (2x3): `[[1, 2, 3], [4, 5, 6]]`
```
:::
:::{tab-item} Salida
:sync: tab2
Matriz $A^T$ (3x2):
```text
[ 1, 4 ]
[ 2, 5 ]
[ 3, 6 ]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Fórmula:** $(A^T)_{ij} = A_{ji}$.
-   **Dimensiones:** Si la matriz original es $m \times n$, su transpuesta será $n \times m$.
-   **Proceso:** Recorrer la matriz original `A` con lazos anidados. En cada posición `(i, j)`, copiar el elemento `A[i][j]` a la posición `(j, i)` de la nueva matriz transpuesta.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
PROCEDIMIENTO transponer_matriz(A, filas, columnas, REF A_T)
INICIO
    PARA i DESDE 0 HASTA filas-1 HACER
        PARA j DESDE 0 HASTA columnas-1 HACER
            A_T[j][i] = A[i][j]
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
````
:::

### 3.2: Suma de diagonales

#### Descripción
Para una matriz cuadrada, calcular la suma de los elementos de sus dos diagonales: la principal y la secundaria.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
```text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Suma Diagonal Principal: `1 + 5 + 9 = 15`
Suma Diagonal Secundaria: `3 + 5 + 7 = 15`
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Diagonal Principal:** Los elementos de la diagonal principal son aquellos donde el índice de fila es igual al índice de columna (`i == j`).
-   **Diagonal Secundaria:** Los elementos de la diagonal secundaria en una matriz de tamaño `n x n` son aquellos donde `i + j == n - 1`.
-   **Proceso:** Usar un solo lazo de `i=0` a `n-1`. En cada iteración, sumar `matriz[i][i]` a la suma principal y `matriz[i][n-1-i]` a la suma secundaria.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
PROCEDIMIENTO sumar_diagonales(matriz, n, REF suma_princ, REF suma_sec)
INICIO
    suma_princ = 0
    suma_sec = 0
    PARA i DESDE 0 HASTA n-1 HACER
        suma_princ = suma_princ + matriz[i][i]
        suma_sec = suma_sec + matriz[i][n-1-i]
    FIN PARA
FIN PROCEDIMIENTO
````
:::

---

## 4: Generación

### 4.1: Matriz Identidad

#### Descripción
Generar una matriz identidad de tamaño `n x n`. La matriz identidad es una matriz cuadrada con unos en la diagonal principal y ceros en todas las demás posiciones.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
```text
Tamaño n = 3
```
:::
:::{tab-item} Salida
:sync: tab2
```text
[ 1, 0, 0 ]
[ 0, 1, 0 ]
[ 0, 0, 1 ]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Proceso:** Recorrer la matriz `n x n` con lazos anidados.
-   **Condición:** Para cada elemento en la posición `(i, j)`:
    -   Si `i == j`, el valor es 1.
    -   Si `i != j`, el valor es 0.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
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
````
:::

---

## 5: Ejercicios Adicionales de Matrices

### 5.1: Matriz Simétrica

#### Descripción
Escribir una función que verifique si una matriz cuadrada es simétrica. Una matriz es simétrica si es igual a su propia transpuesta, lo que significa que el elemento en la fila `i`, columna `j` es igual al elemento en la fila `j`, columna `i`.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
```text
[ 1, 7, 3 ]
[ 7, 4, 5 ]
[ 3, 5, 6 ]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
La matriz es simétrica.
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Fórmula:** Una matriz `A` es simétrica si $A_{ij} = A_{ji}$ para todos los `i`, `j`.
-   **Proceso:**
    1.  Recorrer solo la mitad superior (o inferior) de la matriz es suficiente. Por ejemplo, con lazos anidados donde el lazo interior para `j` comienza en `i+1`.
    2.  En cada paso, comparar `matriz[i][j]` con `matriz[j][i]`.
    3.  Si en algón momento no son iguales, la matriz no es simétrica y la función puede devolver `falso` inmediatamente.
-   **Salida:** Si los lazos se completan sin encontrar diferencias, la matriz es simétrica.
:::

:::{hint} Diagrama
:class: dropdown
El diagrama muestra los pares de elementos que deben ser iguales. Solo es necesario verificar una mitad del triángulo (excluyendo la diagonal).

````{mermaid}
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
````
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
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
````
:::

### 5.2: Suma por Filas y Columnas

#### Descripción
Crear un programa que, dada una matriz, calcule dos arreglos: uno que contenga la suma de los elementos de cada fila y otro que contenga la suma de los elementos de cada columna.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
Matriz (2x3):
```text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Suma de filas: [6, 15]
Suma de columnas: [5, 7, 9]
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Suma de Filas:**
    -   Recorrer cada fila con un lazo exterior.
    -   Para cada fila, inicializar una `suma_fila` en 0.
    -   Con un lazo interior, recorrer las columnas de esa fila y acumular los valores en `suma_fila`.
    -   Guardar el resultado en el arreglo de sumas de filas.
-   **Suma de Columnas:**
    -   El proceso es inverso. El lazo exterior recorre las columnas.
    -   El lazo interior recorre las filas de esa columna.
-   **Eficiencia:** Se pueden calcular ambas sumas en un solo par de lazos anidados. Al procesar el elemento `matriz[i][j]`, se añade a `suma_filas[i]` y a `suma_columnas[j]`.

:::

:::{hint} Ayuda (Pseudocódigo Eficiente)
:class: dropdown
````{code-block} pseudocode
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
````
:::

### 5.3: Elemento "Silla"

#### Descripción
Encontrar un "punto de silla" en una matriz. Un punto de silla es un elemento que es simultáneamente el valor mínimo en su fila y el valor máximo en su columna.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
Matriz (3x3):
```text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]
```
:::
:::{tab-item} Salida
:sync: tab2
```text
Punto de silla encontrado en (2, 0) con valor 7.
```
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Iterar a través de cada fila `i` de la matriz.
    2.  En cada fila, encontrar el valor mínimo y su índice de columna `min_col_idx`.
    3.  Una vez encontrado el candidato (el mínimo de la fila), verificar si este elemento es también el máximo de su columna (`min_col_idx`).
    4.  Para ello, iterar a través de la columna `min_col_idx` y comparar el candidato con todos los demás elementos de esa columna.
    5.  Si el candidato es el mayor de su columna, se ha encontrado un punto de silla.

:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown
````{code-block} pseudocode
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
````
:::

---

## 6: Ejercicios de Matrices Dinámicas

### 6.1: Crear y Llenar Matriz Dinámica

#### Descripción
Escribir una función que solicite al usuario las dimensiones (filas y columnas) y luego los elementos de una matriz, para finalmente imprimirla.

::::{tab-set}
:::{tab-item} Entrada
:sync: tab1
Se le pedirá al usuario que ingrese el número de filas y columnas, y luego cada uno de los elementos.
:::
:::{tab-item} Salida
:sync: tab2
La matriz ingresada por el usuario, impresa de forma ordenada.
:::
:::::

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se debe usar una función para leer la entrada del usuario para las dimensiones y los elementos.
-   **Proceso:**
    1.  Solicitar el número de filas (`filas`).
    2.  Solicitar el número de columnas (`columnas`).
    3.  Crear una matriz vacía con las dimensiones especificadas.
    4.  Usar dos lazos anidados para recorrer la matriz y solicitar cada elemento al usuario, asignándolo a la posición correspondiente.
    5.  Finalmente, llamar a la función `mostrar_matriz` (del ejercicio 1.1) para imprimir la matriz creada.
:::

:::{hint} Ayuda (Pseudocódigo)
:class: dropdown

````{code-block} pseudocode
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
````
:::

## 6: Más Algoritmos con Matrices

### 7.1: Reflejar Matriz

Implementar dos funciones: una que refleje una matriz horizontalmente (la primera fila se intercambia con la última, la segunda con la penúltima, etc.) y otra que la refleje verticalmente (la primera columna con la última, etc.).

### 7.2: Intercambiar Filas o Columnas

Crear funciones `intercambiar_filas(mat, f1, f2)` e `intercambiar_columnas(mat, c1, c2)` que modifiquen la matriz intercambiando los elementos de las filas o columnas especificadas.

### 7.3: Búsqueda de Submatriz

Escribir una función que determine si una matriz pequeña `B` (de `k x l`) se encuentra dentro de una matriz más grande `A` (de `m x n`). La función debe devolver las coordenadas de la esquina superior izquierda de la primera ocurrencia, o `(-1, -1)` si no se encuentra.

### 7.4: Determinante de Matriz 3x3

Calcular el determinante de una matriz 3x3 utilizando la Regla de Sarrus.

### 7.5: Suavizado de Matriz (Filtro de Caja)

Implementar un filtro de "suavizado" o "blur". Para cada elemento de la matriz, su nuevo valor será el promedio de sus 8 vecinos y él mismo. Los elementos en los bordes requerirán un manejo especial.

### 7.6: Detección de Bordes (Operador de Sobel)

Aplicar un operador de Sobel simple para la detección de bordes. Esto implica "convolucionar" la matriz con un `kernel` (otra matriz pequeña, ej. 3x3) para resaltar las diferencias de intensidad, como los bordes.

### 7.7: Matriz de Permutación

Verificar si una matriz cuadrada es una matriz de permutación. Esta es una matriz binaria (solo 0s y 1s) que tiene exactamente un `1` en cada fila y en cada columna.

### 7.8: Producto de Hadamard

Implementar el producto de Hadamard (o producto elemento a elemento) de dos matrices `A` y `B` de las mismas dimensiones. La matriz resultante `C` se define como $c_{ij} = a_{ij} \cdot b_{ij}$.

### 7.9: Rellenar con Triángulo de Pascal

Escribir una función que llene una matriz `N x N` con los valores del Triángulo de Pascal. El elemento `(i, j)` debe ser $\binom{i}{j}$.

### 7.10: Matriz Antisimétrica

Verificar si una matriz cuadrada es antisimétrica. Una matriz `A` es antisimétrica si su transpuesta es igual a su negativa, es decir, $A^T = -A$. Esto implica que $a_{ij} = -a_{ji}$ y que todos los elementos de la diagonal principal deben ser cero.

## 8: Operaciones Avanzadas con Matrices

### 8.1: Norma de Matriz

Implementar funciones que calculen diferentes normas de una matriz.

```c
double norma_frobenius(double** matriz, int filas, int cols);
double norma_maxima(double** matriz, int filas, int cols);
double norma_uno(double** matriz, int filas, int cols);
```

**Norma de Frobenius:** $||A||_F = \sqrt{\sum_{i,j} a_{ij}^2}$

**Norma máxima:** $||A||_{\infty} = \max_i \sum_j |a_{ij}|$ (máxima suma de fila)

**Norma uno:** $||A||_1 = \max_j \sum_i |a_{ij}|$ (máxima suma de columna)

### 8.2: Traza de Matriz

Calcular la traza de una matriz cuadrada (suma de elementos de la diagonal principal).

```c
double traza(double** matriz, int n);
```

$$\text{tr}(A) = \sum_{i=1}^n a_{ii}$$

### 8.3: Rango de Matriz

Implementar un algoritmo para calcular el rango de una matriz usando eliminación gaussiana.

```c
int calcular_rango(double** matriz, int filas, int cols);
```

**Estrategia:** Reducir la matriz a forma escalonada y contar filas no nulas.

### 8.4: Matriz de Cofactores

Calcular la matriz de cofactores para una matriz cuadrada.

```c
double** matriz_cofactores(double** matriz, int n);
```

El cofactor $C_{ij}$ se calcula como: $C_{ij} = (-1)^{i+j} M_{ij}$ donde $M_{ij}$ es el menor de la matriz (determinante de la submatriz obtenida eliminando fila $i$ y columna $j$).

### 8.5: Matriz Inversa

Implementar el cálculo de la inversa de una matriz usando el método de Gauss-Jordan.

```c
double** matriz_inversa(double** matriz, int n, bool* invertible);
```

**Algoritmo:**
1. Crear matriz aumentada $[A | I]$
2. Aplicar eliminación Gauss-Jordan
3. Si se obtiene $[I | A^{-1}]$, retornar $A^{-1}$
4. Si no es posible, la matriz no es invertible

### 8.6: Potencia de Matriz

Calcular $A^n$ para una matriz cuadrada $A$ y un exponente entero $n$.

```c
double** potencia_matriz(double** matriz, int tam, int exponente);
```

**Optimización:** Usar exponenciación rápida para $O(\log n)$ multiplicaciones.

### 8.7: Descomposición LU

Implementar la descomposición LU de una matriz: $A = LU$ donde $L$ es triangular inferior y $U$ es triangular superior.

```c
bool descomposicion_lu(double** A, int n, double** L, double** U);
```

**Aplicación:** Resolver sistemas de ecuaciones lineales eficientemente.

### 8.8: Valores Propios (Power Method)

Implementar el método de la potencia para calcular el valor propio dominante de una matriz.

```c
double valor_propio_dominante(double** matriz, int n, double tolerancia);
```

**Algoritmo:**
1. Comenzar con vector aleatorio $v$
2. Iterar: $v_{k+1} = \frac{Av_k}{||Av_k||}$
3. El valor propio es $\lambda = v^T A v$

### 8.9: Matriz de Rotación

Implementar funciones para crear y aplicar matrices de rotación 2D y 3D.

```c
double** matriz_rotacion_2d(double angulo);
double** matriz_rotacion_3d_x(double angulo);
double** matriz_rotacion_3d_y(double angulo);
double** matriz_rotacion_3d_z(double angulo);
```

**Matriz de rotación 2D:**

$$
R(\theta) = \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}
$$

### 8.10: Matriz de Proyección

Crear matriz de proyección ortogonal sobre un vector.

```c
double** matriz_proyeccion(double* vector, int n);
```

**Fórmula:** $P = \frac{vv^T}{v^Tv}$

## 9: Algoritmos de Procesamiento de Imágenes

Considerar una matriz como una imagen en escala de grises donde cada elemento representa la intensidad de un píxel.

### 9.1: Umbralización (Thresholding)

Convertir una imagen en escala de grises a binaria (solo 0 y 255) usando un umbral.

```c
void umbralizar(int** imagen, int filas, int cols, int umbral);
```

**Algoritmo:** Si `pixel >= umbral`, asignar 255, sino asignar 0.

### 9.2: Histograma de Imagen

Calcular el histograma de una imagen (frecuencia de cada nivel de intensidad).

```c
void calcular_histograma(int** imagen, int filas, int cols, int* histograma);
```

El histograma tiene 256 posiciones (0-255) que cuentan la frecuencia de cada intensidad.

### 9.3: Ecualización de Histograma

Mejorar el contraste de una imagen mediante ecualización de histograma.

```c
void ecualizar_histograma(int** imagen, int filas, int cols);
```

**Algoritmo:**
1. Calcular histograma
2. Calcular función de distribución acumulativa (CDF)
3. Normalizar CDF y aplicar transformación a cada píxel

### 9.4: Filtro Gaussiano

Implementar un filtro gaussiano para suavizado de imagen.

```c
void filtro_gaussiano(double** imagen, int filas, int cols, double sigma);
```

**Kernel gaussiano 3x3:**
$$K = \frac{1}{16}\begin{pmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{pmatrix}$$

### 9.5: Detección de Bordes (Laplaciano)

Aplicar el operador Laplaciano para detectar bordes.

```c
void detectar_bordes_laplaciano(int** imagen, int filas, int cols, int** resultado);
```

**Kernel Laplaciano:**
$$K = \begin{pmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{pmatrix}$$

## 10: Matrices Especiales

### 10.1: Matriz de Vandermonde

Generar una matriz de Vandermonde a partir de un vector.

```c
double** matriz_vandermonde(double* x, int n, int m);
```

**Definición:** $V_{ij} = x_i^{j-1}$

**Ejemplo con $x = [1, 2, 3]$ y $m = 4$:**
$$V = \begin{pmatrix} 1 & 1 & 1 & 1 \\ 1 & 2 & 4 & 8 \\ 1 & 3 & 9 & 27 \end{pmatrix}$$

### 10.2: Matriz de Hilbert

Generar una matriz de Hilbert de orden $n$.

```c
double** matriz_hilbert(int n);
```

**Definición:** $H_{ij} = \frac{1}{i+j-1}$

**Nota:** Las matrices de Hilbert son notoriamente mal condicionadas para inversión.

### 10.3: Matriz de Toeplitz

Verificar si una matriz es de Toeplitz (cada diagonal descendente de izquierda a derecha tiene valores constantes).

```c
bool es_toeplitz(int** matriz, int filas, int cols);
```

**Propiedad:** $a_{i,j} = a_{i+1,j+1}$

### 10.4: Matriz Circulante

Generar una matriz circulante a partir de su primera fila.

```c
int** matriz_circulante(int* primera_fila, int n);
```

**Ejemplo con primera fila $[1, 2, 3, 4]$:**
$$C = \begin{pmatrix} 1 & 2 & 3 & 4 \\ 4 & 1 & 2 & 3 \\ 3 & 4 & 1 & 2 \\ 2 & 3 & 4 & 1 \end{pmatrix}$$

### 10.5: Matriz de Hankel

Generar una matriz de Hankel (opuesta a Toeplitz: diagonales de arriba-derecha a abajo-izquierda son constantes).

```c
double** matriz_hankel(double* c, double* r, int n);
```

## 11: Resolución de Sistemas de Ecuaciones

### 11.1: Sustitución Hacia Adelante

Resolver un sistema triangular inferior $Lx = b$.

```c
double* sustitucion_adelante(double** L, double* b, int n);
```

**Algoritmo:** Resolver de arriba hacia abajo.

### 11.2: Sustitución Hacia Atrás

Resolver un sistema triangular superior $Ux = b$.

```c
double* sustitucion_atras(double** U, double* b, int n);
```

**Algoritmo:** Resolver de abajo hacia arriba.

### 11.3: Eliminación Gaussiana Completa

Implementar eliminación gaussiana con pivoteo completo para resolver $Ax = b$.

```c
double* resolver_sistema(double** A, double* b, int n);
```

### 11.4: Método de Jacobi

Resolver $Ax = b$ iterativamente usando el método de Jacobi.

```c
double* metodo_jacobi(double** A, double* b, int n, double tolerancia, int max_iter);
```

**Fórmula de iteración:**
$$x_i^{(k+1)} = \frac{1}{a_{ii}}\left(b_i - \sum_{j \neq i} a_{ij}x_j^{(k)}\right)$$

### 11.5: Método de Gauss-Seidel

Similar a Jacobi pero usa valores actualizados inmediatamente.

```c
double* metodo_gauss_seidel(double** A, double* b, int n, double tolerancia, int max_iter);
```

**Converge más rápido que Jacobi** para matrices con diagonal dominante.

## 12: Operaciones Matriciales con Bloques

### 12.1: Multiplicación por Bloques

Implementar multiplicación de matrices usando el algoritmo por bloques (más eficiente para matrices grandes por mejor uso de caché).

```c
double** multiplicar_bloques(double** A, double** B, int n, int tam_bloque);
```

### 12.2: Transpuesta por Bloques

Implementar transpuesta usando bloques para mejor localidad de caché.

```c
void transponer_bloques(double** matriz, int n, int tam_bloque);
```

### 12.3: Strassen para Matrices Grandes

Implementar el algoritmo de Strassen para multiplicación rápida de matrices grandes.

```c
double** strassen(double** A, double** B, int n);
```

**Complejidad:** $O(n^{2.807})$ vs $O(n^3)$ del método tradicional.
