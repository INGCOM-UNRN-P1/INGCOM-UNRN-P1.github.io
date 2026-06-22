---
title: "Matrices"
short_title: "6 - Matrices"
subtitle: "The matrix has you..."
---

## Matrices (Arreglos Bidimensionales)

En el ámbito de la programación, una **matriz** se define como una estructura de datos que facilita el almacenamiento de un conjunto homogéneo de elementos, organizados en una disposición bidimensional de filas y columnas. En el lenguaje de programación C, esta abstracción se materializa mediante la implementación de **arreglos bidimensionales** (2D), los cuales pueden ser conceptualizados como arreglos cuyos elementos son, a su vez, otros arreglos.

:::{note} Prerequisitos
Este capítulo asume que ya dominás los conceptos de arreglos unidimensionales presentados en el [](4_secuencias). Si necesitás repasar cómo funcionan los arreglos básicos, su declaración, inicialización y recorrido, consultá ese capítulo primero.
:::

Las matrices son fundamentales en numerosas aplicaciones: desde operaciones matemáticas básicas hasta algoritmos complejos de procesamiento de imágenes, simulaciones físicas, análisis de datos, representación de grafos, implementación de juegos como el tres en raya o ajedrez, y sistemas de coordenadas bidimensionales. Su comprensión es esencial para el desarrollo de software eficiente y estructurado.

### Relación con el álgebra lineal
Las matrices en programación están íntimamente relacionadas con el concepto matemático de matriz del álgebra lineal. Esto permite aplicar directamente teoremas y algoritmos matemáticos en implementaciones de software, especialmente en campos como gráficos por computadora, machine learning, y simulaciones científicas.


###  Extensión a múltiples dimensiones
Técnicamente, no están limitadas a dos dimensiones. Podés tener arreglos
tridimensionales (`int cubo[3][4][5]`) o de mayor dimensionalidad. Sin embargo,
las aplicaciones prácticas se vuelven menos claras y la complejidad de manejo
aumenta considerablemente. Todos los conceptos presentados aquí se extienden
naturalmente a estas dimensiones superiores.

## Declaración

La declaración de una matriz requiere la especificación del tipo de dato de sus
elementos, un identificador único y las dimensiones correspondientes al número
de filas y columnas.

Sintaxis

```{code-block}c
tipo_dato nombre_matriz[CANTIDAD_FILAS][CANTIDAD_COLUMNAS];
```

:::{warning} Uso de ALV/VLA

Es muy importante destacar que las matrices **deben** ser de dimensiones
constantes en tiempo de compilación, ya sea con el número literal, o un macro de
preprocesador, como lo exige la regla de estilo {ref}`0x000Eh`.

Los problemas de utilizar ALV/VLA son mayores aquí que con los arreglos. Cuando
veamos memoria dinámica, vamos a liberarnos de estas restricciones y ver por qué
usar esta técnica es riesgoso.

:::

Ejemplo

```{code-block}c
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

:::{figure} 6/matriz_2d_memoria.svg
:label: fig-matriz-memoria
:width: 100%

Representación de una matriz bidimensional en memoria. Los elementos se
almacenan de forma contigua siguiendo el orden row-major, donde cada fila se
almacena completa antes de pasar a la siguiente.
:::

## Inicialización

Podemos inicializar nuestras matrices, esencialmente, de dos formas diferentes,
con un inicializador como con los arreglos, o con código.

:::{figure} 6/inicializacion_matriz.svg
:label: fig-inicializacion-matriz
:width: 100%

Tres métodos de inicialización de matrices: con inicializador completo, con
declaración implícita de la primera dimensión, y programáticamente mediante
lazos.
:::

### Inicialización completa

Este proceso se realiza mediante el uso de llaves anidadas, donde cada conjunto
de llaves interno corresponde a una fila de la matriz.

```{code-block}c
:linenos:
int matriz[2][3] = {
    {1, 2, 3},  // Fila 0
    {4, 5, 6}   // Fila 1
};
```

### Inicialización con declaración implícita

En C, es posible omitir la primera dimensión (filas) durante la inicialización,
pero **todas las dimensiones subsecuentes deben ser especificadas
explícitamente**. Esto se debe a que el compilador necesita conocer el tamaño de
cada "sub-arreglo" para calcular las posiciones de memoria.

```{code-block}c
:linenos:
// Válido: el compilador infiere 2 filas basándose en el inicializador.
int matriz[][3] = {
    {1, 2, 3},  // Fila 0
    {4, 5, 6}   // Fila 1
};
```

La forma `int matriz[][]` es **inválida** y no compilará, ya que el compilador
no tendría forma de saber dónde termina una fila y empieza la siguiente.

### Inicialización manual

Constituye un método más flexible y programático. El uso de macros en mayúsculas
para las dimensiones ({ref}`0x002Fh`) y de `size_t` para los índices
({ref}`0x002Eh`) son buenas prácticas que mejoran la legibilidad y portabilidad.

```{code-block}c
:caption: Asignación de valores mediante lazo anidados

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

```{code-block}c
nombre_matriz[indice_fila][indice_columna];
```

Ejemplo de L-Value y R-Value

```{code-block}c
matriz[0][1] = 100; // Asigna 100 al elemento en la fila 0, columna 1.
int valor = matriz[2][3]; // Toma el valor del elemento en la fila 2, columna 3.
```

:::{danger} Comportamiento no definido
Es imperativo señalar que el acceso a un índice que excede los límites definidos
para la matriz invoca un **comportamiento indefinido** según el estándar de C,
lo cual puede manifestarse en fallos de ejecución (`segmentation fault`) o
corrupción de datos, violando la regla de estilo {ref}`0x0027h`.
:::

## Patrones de Recorrido de Matrices

El procesamiento sistemático de todos los elementos de una matriz requiere el
uso de **lazos anidados**. La comprensión de los diferentes patrones de acceso
es crucial tanto para la corrección del algoritmo como para el rendimiento del
programa.

### Recorrido por Filas (Row-Major)

El patrón más común y eficiente es el recorrido por filas, donde se accede a
todos los elementos de una fila antes de pasar a la siguiente. Este patrón
aprovecha la {term}`localidad espacial <memoria caché>` y optimiza el uso de la
memoria caché ({ref}`0x0000h`).

```{code-block}c
:caption: Recorrido fila por fila - patrón recomendado
:linenos:

// Lazo externo: filas (i)
for (size_t i = 0; i < FILAS; i++) {
    // Lazo interno: columnas (j)
    for (size_t j = 0; j < COLUMNAS; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n"); // Salto de línea al final de cada fila
}
```

### Recorrido por Columnas (Column-Major)

En ocasiones específicas, puede ser necesario procesar los elementos columna por
columna. Este patrón es menos eficiente en términos de caché, pero puede ser
requerido por la lógica del algoritmo.

```{code-block}c
:caption: Recorrido columna por columna

// Lazo externo: columnas (j)
for (size_t j = 0; j < COLUMNAS; j++) {
    // Lazo interno: filas (i)
    for (size_t i = 0; i < FILAS; i++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n"); // Nueva línea al final de cada columna
}
```

:::{figure} 6/recorrido_filas_columnas.svg
:label: fig-recorrido-matrices
:width: 100%

Comparación entre el recorrido por filas (row-major) y por columnas
(column-major). El recorrido por filas accede a elementos contiguos en memoria,
aprovechando la caché. El recorrido por columnas genera saltos en memoria,
causando más fallos de caché.
:::

### Recorrido Diagonal

Para matrices cuadradas, es común necesitar acceder a las diagonales.

```{code-block}c
:caption: Acceso a diagonal principal y secundaria

#define DIM 4
int matriz_cuadrada[DIM][DIM];

// Diagonal principal (i == j)
printf("Diagonal principal: ");
for (size_t i = 0; i < DIM; i++) {
    printf("%d ", matriz_cuadrada[i][i]);
}
printf("\n");

// Diagonal secundaria (i + j == DIM - 1)
printf("Diagonal secundaria: ");
for (size_t i = 0; i < DIM; i++) {
    printf("%d ", matriz_cuadrada[i][DIM - 1 - i]);
}
printf("\n");
```

:::{figure} 6/diagonales_matriz.svg
:label: fig-diagonales
:width: 100%

Las diagonales principal y secundaria en una matriz cuadrada. La diagonal
principal cumple la condición `i == j`, mientras que la secundaria cumple
`i + j == DIM - 1`.
:::

:::{important} Eficiencia y localidad de memoria
El orden de recorrido por filas es generalmente más eficiente debido a cómo C
almacena las matrices en memoria. Cada acceso secuencial por fila mantiene los
datos en la {term}`memoria caché`, mientras que el acceso por columnas puede
generar más fallos de caché y, en consecuencia, un rendimiento inferior.

Para matrices grandes, esta diferencia puede ser significativa. Siempre que sea
posible, diseñá tus algoritmos para seguir el patrón row-major.
:::

## Pasando matrices a funciones (Método Clásico)

Al pasar una matriz como argumento a una función, el estándar de C requiere que
se especifiquen explícitamente **todas las dimensiones, a excepción de la
primera**. Esto es necesario para que el compilador pueda calcular el
desplazamiento en memoria de cada elemento.

```{code-block}c
:linenos:
#define COLUMNAS 4

// Es crucial pasar las dimensiones para cumplir con la regla {ref}`0x0027h`.
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

:::{important} Límite de control vs. Direccionamiento en memoria
Es crucial notar que en la firma `void imprimir_matriz(int mat[][COLUMNAS], size_t filas, size_t columnas)`, el parámetro `columnas` sirve únicamente como límite de control para el lazo interno de impresión (`j < columnas`). El compilador de C utiliza exclusivamente el valor constante `COLUMNAS` del tipo de dato (`int mat[][COLUMNAS]`) para realizar el cálculo de desplazamiento de memoria al evaluar `mat[i][j]`. Pasar `columnas` no altera en absoluto cómo el compilador direcciona físicamente los elementos en la memoria contigua.
:::

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

```{code-block}c
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

:::{figure} 6/matriz_3d.svg
:label: fig-matriz-3d
:width: 100%

Arreglo tridimensional representado como capas de matrices bidimensionales. Cada
capa contiene una matriz completa, y el acceso requiere tres índices: capa,
fila y columna.
:::

```{code-block}c
:caption: Declaración y recorrido de un arreglo 3D
// Arreglo tridimensional: 2 capas, 3 filas, y 4 columnas.
int cubo[2][3][4];

// Acceso a un elemento
cubo[1][0][2] = 99;

// Recorrido con tres lazos anidados
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

:::{figure} 6/cache_localidad.svg
:label: fig-cache-localidad
:width: 100%

Impacto del orden de acceso en el rendimiento. El acceso row-major aprovecha la
localidad espacial, cargando elementos contiguos en la caché. El acceso
column-major genera saltos que causan múltiples fallos de caché.
:::

### Recorrido Óptimo (Cache-Friendly)

La iteración por filas en el lazo externo y por columnas en el interno produce
un patrón de acceso secuencial a la memoria. Esto maximiza la probabilidad de
aciertos de caché (cache hits), ya que al solicitar un elemento, un bloque
contiguo de memoria que incluye los elementos subsiguientes de la misma fila es
transferido a la caché.

```{code-block}c
:linenos:
// ALTO RENDIMIENTO: Aprovecha la localidad de datos espaciales.
for (size_t i = 0; i < FILAS; i++) {
    for (size_t j = 0; j < COLUMNAS; j++) {
        suma += matriz[i][j];
    }
}
```

### Recorrido Ineficiente (Cache-Unfriendly)

La inversión de los lazos de iteración genera un patrón de acceso no contiguo a
la memoria. Cada acceso salta a una dirección de memoria distante, lo que reduce
la eficacia de la caché y provoca constantes fallos de caché (cache misses).
Cada fallo obliga a la CPU a esperar la recuperación de datos desde la lenta
memoria principal, degradando sustancialmente el rendimiento.

```{code-block}c
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
manejo de matrices es fundamental. $A$ continuación, te presento los algoritmos
y las expresiones matemáticas para las operaciones básicas entre matrices.

:::{figure} 6/operaciones_basicas.svg
:label: fig-operaciones-basicas
:width: 100%

Operaciones básicas con matrices: suma, resta y transposición. Cada operación
requiere validar que las dimensiones sean compatibles antes de proceder.
:::

## Suma de Matrices

La suma de dos matrices, A y B, de las mismas dimensiones ($m \times n$), guarda el resultado en una matriz C de la misma dimensión. Cada elemento de C es la suma de los elementos correspondientes en A y B.

### Expresión Matemática

Para dos matrices A y B de tamaño $m \times n$, la matriz resultante C se define
como:

```{math}
:label: eq-suma-matrices
C_{i,j} = A_{i,j} + B_{i,j}
```

donde $i$ representa la fila y $j$ la columna.

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

```{code-block}pseudocode
:caption: Algoritmo para la suma de dos matrices A y B.
:linenos:

PROCEDIMIENTO sumar_matrices(A, B, C, m, n)
  // A y B son matrices de dimensión m x n de entrada
  // C es la de dimensión m x n de salida (por referencia)

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      C[i][j] = A[i][j] + B[i][j]
    FIN PARA
  FIN PARA
FIN PROCEDIMIENTO
```

---

## Resta de Matrices

De manera análoga a la suma, la resta de dos matrices A y B de idénticas
dimensiones guarda el resultado en una matriz C donde cada elemento es la diferencia de
los elementos correspondientes.

### Expresión Matemática

Para dos matrices A y B de tamaño $m \times n$, la matriz resultante C se define
como:

```{math}
:label: eq-resta-matrices
C_{i,j} = A_{i,j} - B_{i,j}
```

### Algoritmo en Pseudocódigo

El procedimiento es idéntico al de la suma, pero se realiza una resta.

```{code-block}pseudocode
:caption: Algoritmo para la resta de dos matrices A y B.
:linenos:

PROCEDIMIENTO restar_matrices(A, B, C, m, n)
  // A y B son matrices de dimensión m x n de entrada
  // C es la de dimensión m x n de salida (por referencia)

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      C[i][j] = A[i][j] - B[i][j]
    FIN PARA
  FIN PARA
FIN PROCEDIMIENTO
```

---

## Multiplicación de Matrices

La multiplicación de una matriz A de dimensión $m \times p$ por una matriz B de
dimensión $p \times n$ guarda el resultado en una matriz C de dimensión $m \times n$. Es crucial que el
número de columnas de A sea igual al número de filas de B.

:::{figure} 6/multiplicacion_matrices.svg
:label: fig-multiplicacion-matrices
:width: 100%

Proceso de multiplicación de matrices. Cada elemento C[i][j] se calcula como el
producto escalar de la fila i de A con la columna j de B, sumando los productos
elemento por elemento.
:::

### Expresión Matemática

El elemento $(i,j)$ de la matriz resultante C se calcula como la suma de los
productos de los elementos de la fila $i$ de A por los elementos de la columna $j$
de B.

```{math}
:label: eq-mult-matrices
C_{i,j} = \sum_{k=1}^{p} A_{i,k} \cdot B_{k,j}
```

### Expansión Matemática

Cada elemento $C_{i,j}$ de la matriz resultante se calcula realizando el
producto escalar del vector fila $i$ de la matriz A con el vector columna $j$ de
la matriz B.

Dadas las matrices:

$$ A = \begin{pmatrix} A_{1,1} & \cdots & A_{1,p} \\ \vdots & \ddots & \vdots \\
\color{blue}A_{i,1} & \color{blue}\cdots & \color{blue}A_{i,p} \\ \vdots &
\ddots & \vdots \\ A_{m,1} & \cdots & A_{m,p} \end{pmatrix} \quad B =
\begin{pmatrix} B_{1,1} & \cdots & \color{red}B_{1,j} & \cdots & B_{1,n} \\
\vdots & \ddots & \color{red}\vdots & \ddots & \vdots \\ B_{p,1} & \cdots &
\color{red}B_{p,j} & \cdots & B_{p,n} \end{pmatrix} $$

El elemento $C_{i,j}$ se calcula como:

$$
C_{i,j} = (\color{blue}A_{i,1} \cdot \color{red}B_{1,j}) + (\color{blue}A_{i,2}
\cdot \color{red}B_{2,j}) + \cdots + (\color{blue}A_{i,p} \cdot
\color{red}B_{p,j}) = \sum_{k=1}^{p} A_{i,k} \cdot B_{k,j}
$$

Por ejemplo, para calcular el elemento $C_{1,1}$ de una multiplicación de
matrices de 2x2:

$$
\begin{pmatrix} \color{blue}A_{1,1} & \color{blue}A_{1,2} \\ A_{2,1} & A_{2,2} \end{pmatrix} \times \begin{pmatrix} \color{red}B_{1,1} & B_{1,2} \\ \color{red}B_{2,1} & B_{2,2} \end{pmatrix} = \begin{pmatrix} C_{1,1} & C_{1,2}
\\ C_{2,1} & C_{2,2} \end{pmatrix}
$$

Donde
$C_{1,1} = (\color{blue}A_{1,1} \cdot \color{red}B_{1,1}) + (\color{blue}A_{1,2} \cdot \color{red}B_{2,1})$.

### Algoritmo en Pseudocódigo

Este algoritmo requiere tres lazos anidados para calcular el producto escalar de
cada fila de A con cada columna de B.

```{code-block}pseudocode
:caption: Algoritmo para la multiplicación de una matriz A (m x p) por una matriz B (p x n).
:linenos:

PROCEDIMIENTO multiplicar_matrices(A, B, C, m, p, n)
  // A es una matriz de m x p de entrada
  // B es una matriz de p x n de entrada
  // C es la de dimensión m x n de salida (por referencia)

  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      suma = 0
      PARA k DESDE 0 HASTA p - 1
        suma = suma + (A[i][k] * B[k][j])
      FIN PARA
      C[i][j] = suma
    FIN PARA
  FIN PARA
FIN PROCEDIMIENTO
```

## Validación y Manejo de Errores

En aplicaciones robustas, es fundamental implementar validaciones para prevenir
accesos fuera de límites y operaciones inválidas. Esto es especialmente crítico
en C, donde no existe verificación automática de límites ({ref}`0x0027h`).

:::{figure} 6/validacion_dimensiones.svg
:label: fig-validacion-dimensiones
:width: 100%

Validación de dimensiones para operaciones con matrices. La suma y resta
requieren dimensiones idénticas, mientras que la multiplicación requiere que las
columnas de A sean igual a las filas de B.
:::

### Validación de Índices

```{code-block}c
:caption: Función para validar acceso seguro a matriz
:linenos:

#include <stdbool.h>
#include <stdio.h>

#define MAX_COLUMNAS 100

bool indice_valido(size_t fila, size_t columna,
                   size_t max_filas, size_t max_columnas) {
    return (fila < max_filas && columna < max_columnas);
}

int acceso_seguro_matriz(int matriz[][MAX_COLUMNAS],
                        size_t fila, size_t columna,
                        size_t filas, size_t columnas) {
    if (!indice_valido(fila, columna, filas, columnas)) {
        fprintf(stderr, "Error: Índices fuera de límites (%zu, %zu)\n",
                fila, columna);
        return -1; // Valor de error
    }

    return matriz[fila][columna];
}
```

### Validación de Operaciones

Para operaciones matemáticas entre matrices, debemos verificar la compatibilidad
de dimensiones antes de proceder.

```{code-block}c
:caption: Validación para operaciones con matrices
:linenos:

typedef enum {
    MATRIZ_OK,
    MATRIZ_ERROR_DIMENSIONES,
    MATRIZ_ERROR_MEMORIA,
    MATRIZ_ERROR_SINGULAR
} resultado_matriz_t;

resultado_matriz_t validar_suma(size_t filas_a, size_t columnas_a,
                               size_t filas_b, size_t columnas_b) {
    if (filas_a != filas_b || columnas_a != columnas_b) {
        return MATRIZ_ERROR_DIMENSIONES;
    }
    return MATRIZ_OK;
}

resultado_matriz_t validar_multiplicacion(size_t filas_a, size_t columnas_a,
                                        size_t filas_b, size_t columnas_b) {
    if (columnas_a != filas_b) {
        return MATRIZ_ERROR_DIMENSIONES;
    }
    return MATRIZ_OK;
}
```

:::{warning} Responsabilidad del programador
En C, la validación de límites es responsabilidad del programador. El lenguaje 
no proporciona verificaciones automáticas, por lo que debés implementar estas 
validaciones de forma explícita. El no hacerlo puede resultar en comportamiento 
indefinido, violando la regla de estilo {ref}`0x0000h` sobre claridad y prolijidad 
del código. 
:::

## Mejores Prácticas y Optimizaciones

### Uso de Macros para Dimensiones

Utilizá siempre macros para definir las dimensiones de tus matrices, siguiendo
la regla de estilo {ref}`0x002Fh`. Esto facilita el mantenimiento y la
modificación del código.

```{code-block}c
:caption: Definición de dimensiones con macros

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

int matriz[MAX_FILAS][MAX_COLUMNAS];
```

### Optimización de Acceso a Memoria

Para matrices grandes, considerá el orden de acceso para optimizar el uso de la
caché. El patrón row-major es generalmente más eficiente:

```{code-block}c
:caption: Optimización para el acceso a memoria
:linenos:

// Preferible - acceso secuencial por filas
for (size_t i = 0; i < FILAS; i++) {
    for (size_t j = 0; j < COLUMNAS; j++) {
        procesar_elemento(matriz[i][j]);
    }
}

// Menos eficiente - acceso por columnas
// Usar solo cuando sea necesario por la lógica del algoritmo
for (size_t j = 0; j < COLUMNAS; j++) {
    for (size_t i = 0; i < FILAS; i++) {
        procesar_elemento(matriz[i][j]);
    }
}
```

### Funciones Auxiliares

Creá funciones auxiliares para operaciones comunes, siguiendo la regla de
claridad {ref}`0x0000h`:

```{code-block}c
:caption: Funciones auxiliares para matrices
:linenos:

void imprimir_matriz(int matriz[][MAX_COLS], size_t filas, size_t columnas) {
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void inicializar_con_ceros(int matriz[][MAX_COLS], size_t filas, size_t columnas) {
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
}

bool son_matrices_iguales(int a[][MAX_COLS], int b[][MAX_COLS],
                         int filas, int columnas) {
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}
```

## Glosario

:::{glossary}
memoria caché 
: Una **memoria caché** (del francés _cacher_,
  "esconder") es un componente de hardware o software que almacena datos para que
  las futuras solicitudes de esos datos puedan ser atendidas más rápidamente. Se
  trata de una memoria auxiliar, de alta velocidad y menor capacidad, situada
  entre la unidad central de procesamiento (CPU) y la memoria de acceso aleatorio
  (RAM).
  
  El objetivo principal de una caché es **acelerar el acceso a los datos** que se
  utilizan con mayor frecuencia. Cuando la CPU necesita leer o escribir datos,
  primero busca en la caché. Si los datos se encuentran allí (lo que se conoce
  como un **acierto de caché** o _cache hit_), se accede a ellos de forma casi
  inmediata, evitando el acceso mucho más lento a la memoria principal. Si los
  datos no están en la caché (**fallo de caché** o _cache miss_), se deben
  recuperar de la RAM y, por lo general, se copian en la caché para futuros
  accesos.
  
  Existen diferentes **niveles de caché** (L1, L2, L3), que se diferencian por su
  tamaño, velocidad y proximidad a los núcleos de la CPU. La caché L1 es la más
  pequeña y rápida, mientras que la L3 es la más grande y lenta de las tres.
  
  ¿Pero por que no todo es memoria caché? La relación costo capacidad. Las
  memorias mas cercanas al procesador y las mas rápidas, son las mas caras, tengan
  en cuenta que una computadora moderna tiene algunos kilobytes de memoria L1 y
  unos pocos megabytes en L3.

localidad espacial 
: Un principio fundamental en el diseño de sistemas de
memoria que establece que si un programa accede a una ubicación de memoria, es
muy probable que también acceda a ubicaciones cercanas en un futuro próximo.
Este principio es especialmente relevante para las matrices almacenadas en
**row-major order**, donde los elementos de una fila son adyacentes en memoria.
Al acceder secuencialmente por filas, se aprovecha esta localidad y se optimiza
el uso de la caché.

localidad temporal 
: Principio que indica que si un programa accede a una
ubicación de memoria, es probable que vuelva a acceder a la misma ubicación en
un futuro cercano. En el contexto de matrices, esto se aprovecha cuando se
realizan múltiples operaciones sobre los mismos elementos o cuando se recorren
matrices varias veces con diferentes propósitos.

row-major order 
: Método de almacenamiento de matrices en memoria donde los
elementos se disponen fila por fila de forma consecutiva. En una matriz de 3×4,
los elementos se almacenan como: [matriz[0][0], matriz[0][1], matriz[0][2],
matriz[0][3], matriz[1][0], ...]. Este es el orden usado por C, C++, Python
(NumPy) y Java, entre otros.

column-major order 
: Método alternativo de almacenamiento donde los elementos se
almacenan columna por columna. Usado por lenguajes como Fortran y MATLAB. En una
matriz de 3×4, el orden sería: [matriz[0][0], matriz[1][0], matriz[2][0],
matriz[0][1], ...]. Es importante conocer este concepto al interoperar con
código de otros lenguajes.

matriz singular 
: Una matriz cuadrada cuyo determinante es igual a cero. Las
matrices singulares no tienen inversa y representan transformaciones que
"colapsan" el espacio, reduciendo su dimensionalidad. En términos geométricos,
una matriz singular proyecta vectores de dimensión n en un subespacio de menor
dimensión.

determinante 
: Un valor escalar que se puede calcular para cualquier matriz
cuadrada. Proporciona información importante sobre las propiedades de la matriz:
si es cero, la matriz es singular; si es positivo o negativo, indica
orientación; y su magnitud representa el factor de escalamiento del volumen en
transformaciones lineales.

matriz identidad 
: Una matriz cuadrada especial donde todos los elementos de la
diagonal principal son 1 y todos los demás elementos son 0. Actúa como el
elemento neutro en la multiplicación de matrices: A × I = I × A = A. Es
fundamental en operaciones como la inversión de matrices. 
:::

## Ejercicios

```{exercise}
:label: imprimir_matriz
:enumerator: matrices-1

Escribí un programa que inicialice una matriz de enteros de 3x3 con valores 
predefinidos. Luego, recorrela utilizando lazos anidados para imprimir sus 
elementos en la consola, manteniendo el formato de filas y columnas.
```

````{solution} imprimir_matriz
:class: dropdown

```{code-block}c
#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main() {
  int mi_matriz[FILAS][COLUMNAS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printf("Contenido de la matriz:\n");
  for (size_t i = 0; i < FILAS; i++) {
    for (size_t j = 0; j < COLUMNAS; j++) {
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

```{code-block}c
:linenos:
#include <stdio.h>

#define DIM 3

// La función recibe la matriz y su dimensión
int sumar_diagonal_principal(int matriz[][DIM], size_t dimension) {
  int suma = 0;
  for (size_t i = 0; i < dimension; i++) {
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

## Apéndice Avanzado: Operaciones Matriciales de Álgebra Lineal

### Cálculo de Determinantes

El determinante es un valor escalar que se puede calcular para toda **matriz
cuadrada**. Este valor encapsula propiedades importantes de la matriz, como la
invertibilidad. Se denota como det(A) o |A|.

#### Definición Matemática

Para una matriz de 2x2, el cálculo es directo:

$$ \det(A) = \begin{vmatrix} a & b \\ c & d \end{vmatrix} = ad - bc $$

Para matrices de mayor tamaño $(n \times n)$, un método común es la **expansión por
cofactores**. El determinante se calcula expandiendo a lo largo de una fila o
columna. Usando la primera fila, la fórmula es:

```{math}
:label: eq-determinante
\det(A) = \sum_{j=1}^{n} (-1)^{1+j} \cdot A_{1,j} \cdot \det(M_{1,j})
```

Donde:

- $A_{1,j}$ es el elemento en la primera fila y la columna $j$.
- $M_{1,j}$ es la **matriz menor**, que es la submatriz que resulta de eliminar
  la fila 1 y la columna $j$ de A.
- El término $(-1)^{1+j} \cdot \det(M_{1,j})$ se conoce como el **cofactor** del
  elemento $A_{1,j}$.

#### Algoritmo Recursivo (Basado en Cofactores)

Este método matemático se traduce de forma natural en un algoritmo recursivo. La
idea es reducir el problema de un determinante $n \times n$ al cálculo de varios
determinantes $(n-1) \times (n-1)$, hasta llegar al caso base de una matriz 2x2.

```{warning} Costo Computacional
:class: dropdown
Este algoritmo es conceptualmente claro, pero computacionalmente ineficiente para matrices grandes, con una complejidad de $O(n!)$. Para aplicaciones de alto rendimiento, se utilizan otros métodos como la descomposición LU.
```

```{code-block}pseudocode
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

### Inversión de Matrices

La inversa de una matriz cuadrada A, denotada como $A^{-1}$, es aquella matriz
que al multiplicarla por A da como resultado la matriz identidad I.

$$ A \cdot A^{-1} = A^{-1} \cdot A = I $$

#### Condiciones para la Inversión

Una matriz es invertible si y solo si cumple dos condiciones:

1.  Es una **matriz cuadrada**.
2.  Su **determinante es distinto de cero**. A las matrices con determinante
    cero se las llama **singulares** y no tienen inversa.

#### Método de la Matriz Adjunta

Un método para encontrar la inversa se basa en el determinante y la **matriz
adjunta**. La fórmula es:

```{math}
:label: eq-inversa
A^{-1} = \frac{1}{\det(A)} \cdot \text{adj}(A)
```

Donde $adj(A)$ es la matriz adjunta de A, que se define como la **transpuesta
de la matriz de cofactores** de A.

#### Algoritmo (Basado en la Adjunta)

El algoritmo consiste en seguir los pasos de la fórmula matemática.

1.  **Calcular el determinante:** Si es cero, la matriz no es invertible.
2.  **Calcular la matriz de cofactores:** Para cada elemento $A_{i,j}$, su
    cofactor es $(-1)^{i+j} \det(M_{i,j})$.
3.  **Calcular la matriz adjunta:** Transponer la matriz de cofactores.
4.  **Obtener la inversa:** Multiplicar la matriz adjunta por el escalar
    $1 / \det(A)$.

```{code-block}pseudocode
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

