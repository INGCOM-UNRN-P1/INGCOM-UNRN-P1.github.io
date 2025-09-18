---
title: "Matrices"
short_title: "6 - Matrices"
subtitle: "The matrix has you..."
---

## Matrices (Arreglos Bidimensionales)

En el ámbito de la programación, una **matriz** se define como una estructura de
datos que facilita el almacenamiento de un conjunto homogéneo de elementos,
organizados en una disposición bidimensional de filas y columnas. En el lenguaje
de programación C, esta abstracción se materializa mediante la implementación de
**arreglos bidimensionales** (2D), los cuales pueden ser conceptualizados como
arreglos cuyos elementos son, a su vez, otros arreglos.

Técnicamente, no están limitadas a dos dimensiones, pero las aplicaciones
prácticas son menos claras. Pero todos los conceptos que están aquí presentes,
aplican.

## Declaración

La declaración de una matriz requiere la especificación del tipo de dato de sus
elementos, un identificador único y las dimensiones correspondientes al número
de filas y columnas.

Sintaxis

```{code-block} c
tipo_dato nombre_matriz[CANTIDAD_FILAS][CANTIDAD_COLUMNAS];
```

:::{warning} Uso de ALV/VLA

Es muy importante destacar que las matrices **deben** ser de dimensiones
constantes en tiempo de compilación, ya sea con el número literal, o un macro de
preprocesador.

Los problemas de utilizar ALV/VLA son mayores aquí que con los arreglos. Cuando
veamos memoria dinámica, vamos a liberarnos de estas restricciones y ver por qué
usar esta técnica es riesgoso.

:::

Ejemplo

```{code-block} c
int miMatriz[3][4]; // Matriz de 3 filas y 4 columnas
```

:::{note} Almacenamiento en memoria

A nivel de memoria, el lenguaje C asigna un bloque único y contiguo para el
almacenamiento de la matriz. La disposición de los elementos sigue el criterio
de **orden de fila principal (row-major order)**, lo que implica que los
elementos de la primera fila se almacenan de forma consecutiva, seguidos por los
elementos de la segunda fila, y así sucesivamente.

Para la matriz `mi_matriz[3][4]`, la memoria contendría los 12 enteros en
secuencia, como un arreglo: `[f0c0, f0c1, f0c2, f0c3, f1c0, f1c1, ...]`.

:::

## Inicialización

Podemos inicializar nuestras matrices, esencialmente, de dos formas diferentes,
con un inicializador como con los arreglos, o con código.

### Inicialización completa

Este proceso se realiza mediante el uso de llaves anidadas, donde cada conjunto
de llaves interno corresponde a una fila de la matriz.

```{code-block} c
:linenos:
int matriz[2][3] = {
    {1, 2, 3},  // Fila 0
    {4, 5, 6}   // Fila 1
};
```

### Inicialización con declaración implícita

```{code-block} c
:linenos:
int matriz[][] = {
    {1, 2, 3},  // Fila 0
    {4, 5, 6}   // Fila 1
};
```

Esta forma no es recomendable porque obtener las dimensiones de la matriz es un
incordio de varias llamadas a `sizeof`, y sin perder de vista que en una
función, las matrices también se degradan a dirección de memoria, no dejan de
ser _arreglos multidimensionales_

### Inicialización manual

Constituye un método más flexible y programático. Utilizar macros para las
dimensiones de la matriz es muy recomendable para ayudar a entender que lazo
hace qué, ya que necesitamos dos contadores, que probablemente se terminen
llamando `i` y `j`.

```{code-block} c
:caption: Asignación de valores mediante bucles anidados

#define FILAS 3
#define COLUMNAS 4

int matriz[FILAS][COLUMNAS];
for (size_t i = 0; i < FILAS; i++) {
    for (size_t j = 0; j < COLUMNAS; j++) {
        matriz[i][j] = i * 10 + j;
    }
}
```

## Acceso a los Elementos

El acceso a un elemento específico de la matriz se realiza mediante la
especificación de sus índices de fila y columna, los cuales son de **base
cero**.

Sintaxis

```{code-block} c
nombre_matriz[indice_fila][indice_columna];
```

Ejemplo de L-Value y R-Value

```{code-block} c
matriz[0][1] = 100; // Asigna 100 al elemento en la fila 0, columna 1.
int valor = matriz[2][3]; // Toma el valor del elemento en la fila 2, columna 3.
```

:::{danger} Comportamiento no definido

Es imperativo señalar que el acceso a un índice que excede los límites definidos
para la matriz invoca un **comportamiento indefinido** según el estándar de C,
lo cual puede manifestarse en fallos de ejecución (`segmentation fault`) o
corrupción de datos.

:::

## Recorriendo una matriz

El procesamiento sistemático de todos los elementos de una matriz se hace
comúnmente a través de bucles `for` anidados. Por convención, el bucle externo
itera sobre el índice de las filas, mientras que el bucle interno itera sobre el
de las columnas.

```{code-block} c
:caption: Impresión de una matriz en formato tabular
:linenos:

for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 4; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n"); // Salto de línea para una visualización clara de las filas
}
```

## Pasando matrices a funciones (Método Clásico)

Al pasar una matriz como argumento a una función, el estándar de C requiere que
se especifiquen explícitamente **todas las dimensiones, a excepción de la
primera**.

```{code-block} c
:linenos:
#define COLUMNAS 4

void imprimir_matriz(int mat[][COLUMNAS], size_t filas, size_t columnas) {
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
           printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
```

¿Acaso las `columnas` _no están ya en el macro_ `COLUMNAS`? Para garantizar la
consistencia y minimizar los efectos secundarios en las funciones que operan con
matrices, es fundamental ser explícito con el contexto en el que deben trabajar.

En este caso, las columnas como argumento evita que nuestro código dependa de un
valor que es esencialmente externo a la misma y aunque funciona perfectamente
sin él, en el momento en que veamos memoria dinámica, el código no funcionará
sin mayores cambios.

### Cálculo de Desplazamiento de Memoria

Dicha información es indispensable para que el compilador pueda calcular
correctamente el desplazamiento de memoria necesario para localizar cualquier
elemento `matriz[i][j]`, utilizando una fórmula análoga a:

```{math}
\text{direccionbase} + (i \times \text{COLUMNAS} + j) \times \text{sizeof(int)}
```

### Pasando matrices a funciones (Método ALV)

La utilización de ALV's facilita la creación de funciones genéricas capaces de
operar sobre matrices de dimensiones arbitrarias.

:::{important} Orden de los Parámetros

Resulta crucial observar que, en la firma de la función, los parámetros que
definen las dimensiones de la matriz deben estar antes que el parámetro de la
matriz misma.

:::

```{code-block} c
// Correcto: filas y cols se conocen antes de que el compilador procese matriz[filas][cols]
void procesar_matriz(size_t filas, size_t cols, int matriz[filas][cols]) {
    printf("\nProcesando matriz de %zu x %zu\n", filas, cols);
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < cols; j++) {
            matriz[i][j] *= 2; // Ejemplo: duplicar cada valor
        }
    }
}
```

## Matrices Multidimensionales

El lenguaje C no impone un límite de dos dimensiones para los arreglos; es
posible declarar arreglos multidimensionales. Un arreglo tridimensional, por
ejemplo, puede conceptualizarse como un cubo de datos.

```{code-block} c
:caption: Declaración y recorrido de un arreglo 3D
// Arreglo tridimensional: 2 capas, 3 filas, y 4 columnas.
int cubo[2][3][4];

// Acceso a un elemento
cubo[1][0][2] = 99;

// Recorrido con tres bucles anidados
for (size_t i = 0; i < 2; i++) {       // Capas
    for (size_t j = 0; j < 3; j++) {   // Filas
        for (size_t k = 0; k < 4; k++) { // Columnas
            cubo[i][j][k] = i + j + k;
        }
    }
}
```

## Consideraciones de Rendimiento: Localidad de Caché

El método empleado para iterar sobre los elementos de una matriz posee un
impacto significativo sobre el rendimiento computacional. Este fenómeno se
atribuye a la arquitectura de memoria jerárquica de los procesadores modernos,
los cuales utilizan una memoria caché de alta velocidad como intermediaria entre
la CPU y la memoria principal (RAM).

### Recorrido Óptimo (Cache-Friendly)

La iteración por filas en el bucle externo y por columnas en el interno produce
un patrón de acceso secuencial a la memoria. Esto maximiza la probabilidad de
aciertos de caché (cache hits), ya que al solicitar un elemento, un bloque
contiguo de memoria que incluye los elementos subsiguientes de la misma fila es
transferido a la caché.

```{code-block} c
:linenos:
// ALTO RENDIMIENTO: Aprovecha la localidad de datos espaciales.
for (size_t i = 0; i < FILAS; i++) {
    for (size_t j = 0; j < COLUMNAS; j++) {
        suma += matriz[i][j];
    }
}
```

### Recorrido Ineficiente (Cache-Unfriendly)

La inversión de los bucles de iteración genera un patrón de acceso no contiguo a
la memoria. Cada acceso salta a una dirección de memoria distante, lo que reduce
la eficacia de la caché y provoca constantes fallos de caché (cache misses).
Cada fallo obliga a la CPU a esperar la recuperación de datos desde la lenta
memoria principal, degradando sustancialmente el rendimiento.

```{code-block} c
:linenos:
// BAJO RENDIMIENTO: Genera fallos de caché frecuentes.
for (size_t j = 0; j < COLUMNAS; j++) {
    for (size_t i = 0; i < FILAS; i++) {
        suma += matriz[i][j];
    }
}
```

# Operaciones Matemáticas con Matrices

En el ámbito de la programación en $C$ y otras áreas de la computación, el
manejo de matrices es fundamental. $A$ continuación, te presento los algoritmos y
las expresiones matemáticas para las operaciones básicas entre matrices.

## Suma de Matrices

La suma de dos matrices, $A$ y $B$, de las mismas dimensiones (m x n), da como
resultado una matriz $C$ de la misma dimensión. Cada elemento de $C$ es la suma
de los elementos correspondientes en $A$ y $B$.

### Expresión Matemática

Para dos matrices $A$ y $B$ de tamaño $𝑚×𝑛$, la matriz resultante $C$ se
define como:

```{math}
:label: eq-suma-matrices
C_{i,j} = A_{i,j} + B_{i,j}
```

donde $𝑖$ representa la fila y $𝑗$ la columna.

### Expansión Matemática

Visualmente, la suma de dos matrices de 2x2 se vería así:

$$
\begin{pmatrix}
A_{1,1} & A_{1,2} \\
A_{2,1} & A_{2,2}
\end{pmatrix}
+
\begin{pmatrix}
B_{1,1} & B_{1,2} \\
B_{2,1} & B_{2,2}
\end{pmatrix}
=
\begin{pmatrix}
A_{1,1} + B_{1,1} & A_{1,2} + B_{1,2} \\
A_{2,1} + B_{2,1} & A_{2,2} + B_{2,2}
\end{pmatrix}
$$

### Algoritmo en Pseudocódigo

El algoritmo recorre ambas matrices y suma los elementos en la misma posición.

```{code} pseudocode
:caption: Algoritmo para la suma de dos matrices $A$ y $B$.
:linenos:

FUNCIÓN sumar_matrices(A, B, m, n)
  // A y B son matrices de dimensión m x n
  CREAR matriz C de tamaño m x n

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      C[i][j] = A[i][j] + B[i][j]
    FIN PARA
  FIN PARA

  RETORNAR C
FIN FUNCIÓN
```

---

## Resta de Matrices

De manera análoga a la suma, la resta de dos matrices $A$ y $B$ de idénticas
dimensiones resulta en una matriz $C$ donde cada elemento es la diferencia de
los elementos correspondientes.

### Expresión Matemática

Para dos matrices $A$ y $B$ de tamaño $𝑚×𝑛$, la matriz resultante $C$ se
define como:

```{math}
:label: eq-resta-matrices
C_{i,j} = A_{i,j} - B_{i,j}
```

### Algoritmo en Pseudocódigo

El procedimiento es idéntico al de la suma, pero se realiza una resta.

```{code} pseudocode
:caption: Algoritmo para la resta de dos matrices $A$ y $B$.
:linenos:

FUNCIÓN restar_matrices(A, B, m, n)
  // A y B son matrices de dimensión m x n
  CREAR matriz C de tamaño m x n

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      C[i][j] = A[i][j] - B[i][j]
    FIN PARA
  FIN PARA

  RETORNAR C
FIN FUNCIÓN
```

---

## Multiplicación de Matrices

La multiplicación de una matriz $A$ de dimensión $𝑚×𝑝$ por una matriz $B$ de
dimensión $𝑝×𝑛$ produce una matriz $C$ de dimensión $𝑚×𝑛$. Es crucial que el
número de columnas de $A$ sea igual al número de filas de $B$.

### Expresión Matemática

El elemento $(𝑖,𝑗)$ de la matriz resultante $C$ se calcula como la suma de los
productos de los elementos de la fila 𝑖 de $A$ por los elementos de la columna
𝑗 de $B$.

$$
C_{i,j} = \sum_{k=1}^{p} A_{i,k} \cdot B_{k,j}
$$ (eq-mult-matrices)

### Expansión Matemática

Cada elemento $C_{i,j}$ de la matriz resultante se calcula realizando el producto escalar del vector fila $𝑖$ de la matriz $A$ con el vector columna 𝑗 de la matriz $B$.

Dadas las matrices:


$$
A = \begin{pmatrix} A*{1,1} & \cdots & A*{1,p} \\ \vdots & \ddots & \vdots \\
\color{blue}A*{i,1} & \color{blue}\cdots & \color{blue}A*{i,p} \\ \vdots &
\ddots & \vdots \\ A*{m,1} & \cdots & A*{m,p} \end{pmatrix} \quad B =
\begin{pmatrix} B*{1,1} & \cdots & \color{red}B*{1,j} & \cdots & B*{1,n} \\
\vdots & \ddots & \color{red}\vdots & \ddots & \vdots \\ B*{p,1} & \cdots &
\color{red}B*{p,j} & \cdots & B*{p,n} \end{pmatrix}
$$

El elemento $C_{i,j}$ se calcula como:


$$
C*{i,j} = (\color{blue}A*{i,1} \cdot \color{red}B*{1,j}) + (\color{blue}A*{i,2}
\cdot \color{red}B*{2,j}) + \cdots + (\color{blue}A*{i,p} \cdot
\color{red}B*{p,j}) = \sum*{k=1}^{p} A*{i,k} \cdot B*{k,j}
$$

Por ejemplo, para calcular el elemento $C_{1,1}$ de una multiplicación de matrices de 2x2:


$$
\begin{pmatrix} \color{blue}A*{1,1} & \color{blue}A*{1,2} \\ A*{2,1} & A*{2,2}
\end{pmatrix} \times \begin{pmatrix} \color{red}B*{1,1} & B*{1,2} \\
\color{red}B*{2,1} & B*{2,2} \end{pmatrix} = \begin{pmatrix} C*{1,1} & C*{1,2}
\\ C*{2,1} & C*{2,2} \end{pmatrix}
$$

Donde $C_{1,1} = (\color{blue}A_{1,1} \cdot \color{red}B_{1,1}) + (\color{blue}A_{1,2} \cdot \color{red}B_{2,1})$.

### Algoritmo en Pseudocódigo

Este algoritmo requiere tres bucles anidados para calcular el producto escalar de cada fila de $A$ con cada columna de $B$.

```{code} pseudocode
:caption: Algoritmo para la multiplicación de una matriz A (m x p) por una matriz B (p x n).
:linenos:

FUNCIÓN multiplicar_matrices(A, B, m, p, n)
  // A es una matriz de m x p
  // B es una matriz de p x n
  CREAR matriz C de tamaño m x n

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      suma = 0
      PARA k DESDE 0 HASTA p - 1
        suma = suma + (A[i][k] * B[k][j])
      FIN PARA
      C[i][j] = suma
    FIN PARA
  FIN PARA

  RETORNAR C
FIN FUNCIÓN
```
## Cálculo de Determinantes

El determinante es un valor escalar que se puede calcular para toda **matriz cuadrada**. Este valor encapsula propiedades importantes de la matriz, como la invertibilidad. Se denota como $det(A)$ o $|A|$.

### Definición Matemática

Para una matriz de 2x2, el cálculo es directo:


$$
\det(A) = \begin{vmatrix} a & b \\ c & d \end{vmatrix} = ad - bc
$$

Para matrices de mayor tamaño $(n x n)$, un método común es la **expansión por cofactores**. El determinante se calcula expandiendo a lo largo de una fila o columna. Usando la primera fila, la fórmula es:


$$
\det(A) = \sum*{j=1}^{n} (-1)^{1+j} \cdot A*{1,j} \cdot \det(M\_{1,j})
$$(eq-determinante)

Donde:
- $A_{1,j}$ es el elemento en la primera fila y la columna $j$.
- $M_{1,j}$ es la **matriz menor**, que es la submatriz que resulta de eliminar la fila 1 y la columna $j$ de $A$.
- El término $(-1)^{1+j} \cdot \det(M_{1,j})$ se conoce como el **cofactor** del elemento $A_{1,j}$.

### Algoritmo Recursivo (Basado en Cofactores)

Este método matemático se traduce de forma natural en un algoritmo recursivo. La idea es reducir el problema de un determinante $n x n$ al cálculo de varios determinantes $(n-1) x (n-1)$, hasta llegar al caso base de una matriz 2x2.

```{warning} Costo Computacional
:class: dropdown
Este algoritmo es conceptualmente claro, pero computacionalmente ineficiente para matrices grandes, con una complejidad de $O(n!)$. Para aplicaciones de alto rendimiento, se utilizan otros métodos como la descomposición LU.
```

```{code} pseudocode
:caption: Algoritmo recursivo para el cálculo del determinante.
:linenos:

FUNCIÓN calcular_determinante(A, n)
  // A es una matriz cuadrada de dimensión n x n

  SI n == 1 ENTONCES
    RETORNAR A[0][0]
  FIN SI

  SI n == 2 ENTONCES
    RETORNAR (A[0][0] * A[1][1]) - (A[0][1] * A[1][0])
  FIN SI

  determinante_total = 0
  PARA j_actual DESDE 0 HASTA n - 1
    // 1. Crear la submatriz (menor) M
    CREAR submatriz M de tamaño (n-1) x (n-1)
    PARA i DESDE 1 HASTA n - 1
      col_sub = 0
      PARA j DESDE 0 HASTA n - 1
        SI j != j_actual ENTONCES
          M[i-1][col_sub] = A[i][j]
          col_sub = col_sub + 1
        FIN SI
      FIN PARA
    FIN PARA

    // 2. Calcular el signo del cofactor
    signo = (-1)^j_actual // o potencia( -1, j_actual)

    // 3. Suma recursiva
    sub_determinante = calcular_determinante(M, n-1)
    determinante_total = determinante_total + (signo * A[0][j_actual] * sub_determinante)
  FIN PARA

  RETORNAR determinante_total
FIN FUNCIÓN
```

---

## Inversión de Matrices

La inversa de una matriz cuadrada $A$, denotada como $A^{-1}$, es aquella matriz que al multiplicarla por $A$ da como resultado la matriz identidad $I$.


$$
A \cdot A^{-1} = A^{-1} \cdot A = I
$$

### Condiciones para la Inversión

Una matriz es invertible si y solo si cumple dos condiciones:
1.  Es una **matriz cuadrada**.
2.  Su **determinante es distinto de cero**. $A$ las matrices con determinante cero se las llama **singulares** y no tienen inversa.

### Método de la Matriz Adjunta

Un método para encontrar la inversa se basa en el determinante y la **matriz adjunta**. La fórmula es:


$$
A^{-1} = \frac{1}{\det(A)} \cdot \text{adj}(A)
$$(eq-inversa)

Donde $adj(A)$ es la matriz adjunta de $A$, que se define como la **transpuesta de la matriz de cofactores** de $A$.

### Algoritmo (Basado en la Adjunta)

El algoritmo consiste en seguir los pasos de la fórmula matemática.

1.  **Calcular el determinante:** Si es cero, la matriz no es invertible.
2.  **Calcular la matriz de cofactores:** Para cada elemento $A_{i,j}$, su cofactor es $(-1)^{i+j} \det(M_{i,j})$.
3.  **Calcular la matriz adjunta:** Transponer la matriz de cofactores.
4.  **Obtener la inversa:** Multiplicar la matriz adjunta por el escalar $1 / \det(A)$.

```{code} pseudocode
:caption: Algoritmo para la inversión de una matriz A.
:linenos:

FUNCIÓN invertir_matriz(A, n)
  // 1. Calcular determinante
  determinante = calcular_determinante(A, n)
  SI determinante == 0 ENTONCES
    RETORNAR ERROR "La matriz es singular y no se puede invertir."
  FIN SI

  // 2. Calcular la matriz de cofactores
  CREAR matriz_cofactores de tamaño n x n
  PARA i DESDE 0 HASTA n - 1
    PARA j DESDE 0 HASTA n - 1
      // a. Crear la submatriz menor M(i,j)
      CREAR submatriz M de (n-1) x (n-1) omitiendo fila i y columna j de A

      // b. Calcular el signo y el determinante del menor
      signo = (-1)^(i+j)
      det_menor = calcular_determinante(M, n-1)

      matriz_cofactores[i][j] = signo * det_menor
    FIN PARA
  FIN PARA

  // 3. Calcular la matriz adjunta (transpuesta de la de cofactores)
  CREAR matriz_adjunta de tamaño n x n
  PARA i DESDE 0 HASTA n - 1
    PARA j DESDE 0 HASTA n - 1
      matriz_adjunta[j][i] = matriz_cofactores[i][j]
    FIN PARA
  FIN PARA

  // 4. Calcular la inversa dividiendo la adjunta por el determinante
  CREAR matriz_inversa de tamaño n x n
  factor_inversion = 1.0 / determinante
  PARA i DESDE 0 HASTA n - 1
    PARA j DESDE 0 HASTA n - 1
      matriz_inversa[i][j] = matriz_adjunta[i][j] * factor_inversion
    FIN PARA
  FIN PARA

  RETORNAR matriz_inversa
FIN FUNCIÓN
```


## Glosario

definición

: Una **memoria caché** (del francés *cacher*, "esconder") es un componente de hardware o software que almacena datos para que las futuras solicitudes de esos datos puedan ser atendidas más rápidamente. Se trata de una memoria auxiliar, de alta velocidad y menor capacidad, situada entre la unidad central de procesamiento (CPU) y la memoria de acceso aleatorio (RAM).

  El objetivo principal de una caché es **acelerar el acceso a los datos** que se utilizan con mayor frecuencia. Cuando la CPU necesita leer o escribir datos, primero busca en la caché. Si los datos se encuentran allí (lo que se conoce como un **acierto de caché** o *cache hit*), se accede a ellos de forma casi inmediata, evitando el acceso mucho más lento a la memoria principal. Si los datos no están en la caché (**fallo de caché** o *cache miss*), se deben recuperar de la RAM y, por lo general, se copian en la caché para futuros accesos.

  Existen diferentes **niveles de caché** (L1, L2, L3), que se diferencian por su tamaño, velocidad y proximidad a los núcleos de la CPU. La caché L1 es la más pequeña y rápida, mientras que la L3 es la más grande y lenta de las tres.

  ¿Pero por que no todo es memoria caché? La relación costo capacidad. Las memorias mas cercanas al procesador y las mas rápidas, son las mas caras, tengan en cuenta que una computadora moderna tiene algunos kilobytes de memoria L1 y unos pocos megabytes en L3.



## Ejercicios

```{exercise}
:label: imprimir_matriz
:enumerator: matrices-1

Escribí un programa que inicialice una matriz de enteros de 3x3 con valores predefinidos. Luego, recorrela utilizando bucles anidados para imprimir sus elementos en la consola, manteniendo el formato de filas y columnas.
```

````{solution} imprimir_matriz
:class: dropdown

```{code-block} c
#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main() {
  int mi_matriz[FILAS][COLUMNAS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printf("Contenido de la matriz:\n");
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      printf("%d\t", mi_matriz[i][j]);
    }
    printf("\n"); // Salto de línea al final de cada fila
  }

  return 0;
}
```
````


```{exercise}
:label: sumar_diagonal
:enumerator: funciones-1

Implementá una función `int sumar_diagonal_principal(int matriz[][3], int dimension)` que reciba una matriz cuadrada y su dimensión. La función debe devolver la suma de los elementos de su diagonal principal (donde el índice de fila es igual al de columna).
```

````{solution} sumar_diagonal
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

#define DIM 3

// La función recibe la matriz y su dimensión
int sumar_diagonal_principal(int matriz[][DIM], int dimension) {
  int suma = 0;
  for (int i = 0; i < dimension; i++) {
    suma = suma + matriz[i][i];
    // Accedemos solo a los elementos donde fila == columna
  }
  return suma;
}

int main() {
  int matriz_cuadrada[DIM][DIM] = {{10, 2, 3}, {4, 20, 6}, {7, 8, 30}};

  int suma = sumar_diagonal_principal(matriz_cuadrada, DIM);
  printf("La suma de la diagonal principal es: %d\n", suma);

  return 0;
}
```
````