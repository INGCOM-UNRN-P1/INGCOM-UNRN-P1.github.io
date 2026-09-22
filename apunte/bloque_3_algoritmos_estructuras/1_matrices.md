---
title: "Matrices"
short_title: Matrices
subtitle: "The matrix has you..."
---

(capitulo-matrices)=
# Matrices

> **Prerrequisitos**: arreglos unidimensionales, lazos anidados, `sizeof` y paso de parámetros a funciones.
>
> **Objetivos**: 1. Declarar y recorrer una matriz respetando filas y columnas. 2. Explicar el orden row-major y su efecto en el acceso.
>
> **Comprobación de salida**: trazá los índices visitados por dos lazos anidados y determiná cuál recorre una fila completa.

:::{note} Puente con memoria dinámica

La representación y liberación de matrices dinámicas se introduce en
[`1A_matrices_dinamicas.md`](1A_matrices_dinamicas.md). Este capítulo se enfoca
en declaración, recorridos, operaciones y localidad.

:::

## Introducción

En el ámbito de la programación, una **matriz** se define como una estructura de
datos que facilita el almacenamiento de un conjunto homogéneo de elementos,
organizados en una disposición bidimensional de filas y columnas. En el lenguaje
de programación C, esta abstracción se materializa mediante la implementación de
**arreglos bidimensionales** (2D), los cuales pueden ser conceptualizados como
arreglos cuyos elementos son, a su vez, otros arreglos.

:::{note} Prerequisitos

Este capítulo asume que ya dominás los conceptos de arreglos unidimensionales
presentados en el [Secuencias y arreglos](2_secuencias.md). Si necesitás repasar
cómo funcionan los arreglos básicos, su declaración, inicialización y recorrido,
consultá ese capítulo primero.

:::
<!-- {note} Prerequisitos -->

Las matrices son fundamentales en numerosas aplicaciones: desde operaciones
matemáticas básicas hasta algoritmos complejos de procesamiento de imágenes,
simulaciones físicas, análisis de datos, representación de grafos,
implementación de juegos como el tres en raya o ajedrez, y sistemas de
coordenadas bidimensionales. Su comprensión es esencial para el desarrollo de
software eficiente y estructurado.



## Desarrollo

Matrices (Arreglos Bidimensionales)

(relacion-con-el-algebra-lineal)=
### Relación con el álgebra lineal
Las matrices en programación están íntimamente relacionadas con el concepto
matemático de matriz del álgebra lineal. Esto permite aplicar directamente
teoremas y algoritmos matemáticos en implementaciones de software, especialmente
en campos como gráficos por computadora, machine learning, y simulaciones
científicas.


(extension-a-multiples-dimensiones)=
### Extensión a múltiples dimensiones
Técnicamente, no están limitadas a dos dimensiones. Podés tener arreglos
tridimensionales (`int cubo[3][4][5]`) o de mayor dimensionalidad. Sin embargo,
las aplicaciones prácticas se vuelven menos claras y la complejidad de manejo
aumenta considerablemente. Todos los conceptos presentados aquí se extienden
naturalmente a estas dimensiones superiores.

(declaracion)=
### Declaración

La declaración de una matriz requiere la especificación del tipo de dato de sus
elementos, un identificador único y las dimensiones correspondientes al número
de filas y columnas.

Sintaxis

:::{code-block} c

tipo_dato nombre_matriz[CANTIDAD_FILAS][CANTIDAD_COLUMNAS];

:::
<!-- {code-block} c -->

:::{warning} Uso de ALV/VLA

Es muy importante destacar que los Arreglos de Longitud Variable (ALV/VLA) están
estrictamente prohibidos para la declaración de matrices en la pila (stack)
debido al grave riesgo de desborde de pila (stack overflow) ante dimensiones no
controladas, cumpliendo con la regla de estilo {ref}`0x5001h`.

Sin embargo, el estándar C99 admite y habilita el uso de la sintaxis ALV en las
firmas de funciones para permitir el pasaje de matrices con dimensiones
dinámicas (donde las dimensiones se pasan como parámetros previos), facilitando
el cálculo de desplazamientos de memoria en tiempo de ejecución de manera
genérica y segura.

:::
<!-- {warning} Uso de ALV/VLA -->

Ejemplo

:::{code-block} c

int miMatriz[3][4]; // Matriz de 3 filas y 4 columnas

:::
<!-- {code-block} c -->

:::{note} Almacenamiento en memoria

A nivel de memoria, el lenguaje C asigna un bloque único y contiguo para el
almacenamiento de la matriz. La disposición de los elementos sigue el criterio
de **orden de fila principal (row-major order)**, lo que implica que los
elementos de la primera fila se almacenan de forma consecutiva, seguidos por los
elementos de la segunda fila, y así sucesivamente.

Para la matriz `mi_matriz[3][4]`, la memoria contendría los 12 enteros en
secuencia, como un arreglo: `[f0c0, f0c1, f0c2, f0c3, f1c0, f1c1, ...]`.

:::
<!-- {note} Almacenamiento en memoria -->

:::{figure} 1/matriz_2d_memoria.svg
:label: fig-matriz-2d-memoria
:align: center
:width: 85%

Disposición física contigua de una matriz 2D en memoria RAM (*Row-Major order*).

:::
<!-- {figure} 1/matriz_2d_memoria.svg -->


---

(inicializacion)=
### Inicialización

Podemos inicializar nuestras matrices, esencialmente, de dos formas diferentes,
con un inicializador como con los arreglos, o con código.

:::{figure} 1/inicializacion_matriz.svg
:label: fig-inicializacion-matriz
:align: center
:width: 85%

Inicialización por filas de una matriz bidimensional.

:::
<!-- {figure} 1/inicializacion_matriz.svg -->

(inicializacion-completa)=
#### Inicialización completa

Este proceso se realiza mediante el uso de llaves anidadas, donde cada conjunto
de llaves interno corresponde a una fila de la matriz.

:::{code-block} c
:linenos:
int matriz[2][3] = {
    {1, 2, 3}, // Fila 0
    {4, 5, 6}  // Fila 1
};

:::
<!-- {code-block} c -->

(inicializacion-con-declaracion-implicita)=
#### Inicialización con declaración implícita

En C, es posible omitir la primera dimensión (filas) durante la inicialización,
pero **todas las dimensiones subsecuentes deben ser especificadas
explícitamente**. Esto se debe a que el compilador necesita conocer el tamaño de
cada "sub-arreglo" para calcular las posiciones de memoria.

:::{code-block} c
:linenos:
// Válido: el compilador infiere 2 filas basándose en el inicializador.
int matriz[][3] = {
    {1, 2, 3}, // Fila 0
    {4, 5, 6}  // Fila 1
};

:::
<!-- {code-block} c -->

La forma `int matriz[][]` es **inválida** y no compilará, ya que el compilador
no tendría forma de saber dónde termina una fila y empieza la siguiente.

(inicializacion-manual)=
#### Inicialización manual

Constituye un método más flexible y programático. El uso de macros en mayúsculas
para las dimensiones ({ref}`0x3011h`) y de `size_t` para los índices
({ref}`0x3010h`) son buenas prácticas que mejoran la legibilidad y portabilidad.

:::{code-block} c
:caption: Asignación de valores mediante lazo anidados
#define FILAS 3
#define COLUMNAS 4
int matriz[FILAS][COLUMNAS];
for (size_t i = 0; i < FILAS; i++)
{
    for (size_t j = 0; j < COLUMNAS; j++)
    {
        matriz[i][j] = i * 10 + j;
    }
}

:::
<!-- {code-block} c -->

(acceso-a-los-elementos)=
### Acceso a los Elementos

El acceso a un elemento específico de la matriz se realiza mediante la
especificación de sus índices de fila y columna, los cuales son de **base
cero**.

Sintaxis

:::{code-block} c

nombre_matriz[indice_fila][indice_columna];

:::
<!-- {code-block} c -->

Ejemplo de L-Value y R-Value

:::{code-block} c

matriz[0][1] = 100; // Asigna 100 al elemento en la fila 0, columna 1.
int valor =
    matriz[2][3]; // Toma el valor del elemento en la fila 2, columna 3.

:::
<!-- {code-block} c -->

:::{danger} Comportamiento no definido

Es imperativo señalar que el acceso a un índice que excede los límites definidos
para la matriz invoca un **comportamiento indefinido** según el estándar de C,
lo cual puede manifestarse en fallos de ejecución (`segmentation fault`) o
corrupción de datos, violando la regla de estilo {ref}`0x300Ch`.

:::
<!-- {danger} Comportamiento no definido -->

---

(patrones-de-recorrido-y-localidad-de-memoria-cache)=
### Patrones de Recorrido y Localidad de Memoria (Caché)

El procesamiento sistemático de todos los elementos de una matriz requiere el
uso de **lazos anidados**. La comprensión de la relación entre el almacenamiento
en memoria y el hardware de la CPU es crucial tanto para la corrección del
algoritmo como para el rendimiento del programa.

A nivel físico, la memoria RAM es unidimensional. Para almacenar una matriz
bidimensional, C utiliza el esquema **Row-Major Order** (ordenación por filas),
disponiendo los elementos de la fila 0 de forma consecutiva, seguidos
inmediatamente por los de la fila 1, y así sucesivamente.

Cuando el programa solicita un elemento de la matriz, la CPU no lee una única
variable directamente desde la RAM. En su lugar, el hardware lee un bloque
contiguo completo de datos (línea de caché) y lo transfiere a la **memoria
caché** del procesador. Este mecanismo responde al principio de **localidad
espacial**: si accedés a un dato, es altamente probable que necesités los datos
adyacentes a la brevedad.

(recorrido-por-filas-row-major-alto-rendimiento)=
#### Recorrido por Filas (Row-Major): Alto Rendimiento

El patrón más común y eficiente es el recorrido por filas, donde se accede a
todos los elementos de una fila antes de pasar a la siguiente.

Si recorrés la matriz fila por fila (lazo externo en filas `i`, lazo interno en
columnas `j`), el orden de acceso del programa coincide exactamente con la
disposición lineal en el hardware. Los elementos contiguos ya se encontrarán
precargados en la caché, generando un **acierto de caché (cache hit)** y
agilizando notablemente el procesamiento, respetando la regla de estilo
{ref}`0x0001h`.

:::{code-block} c
:caption: Recorrido fila por fila (Cache-Friendly) - patrón recomendado
:linenos:
// Lazo externo: filas (i)
for (size_t i = 0; i < FILAS; i++)
{
    // Lazo interno: columnas (j)
    for (size_t j = 0; j < COLUMNAS; j++)
    {
        printf("%d ", matriz[i][j]); // Acceso lineal contiguo
    }
    printf("\n"); // Salto de línea al final de cada fila
}

:::
<!-- {code-block} c -->

(recorrido-por-columnas-column-major-bajo-rendimiento)=
#### Recorrido por Columnas (Column-Major): Bajo Rendimiento

Si recorrés la matriz columna por columna (lazo externo en columnas `j`, lazo
interno en filas `i`), forzás al procesador a realizar "saltos" en memoria
física. Cada incremento de `i` requiere avanzar una distancia de `COLUMNAS *
sizeof(tipo)` bytes.

Esto invalida la caché constantemente, produciendo un **fallo de caché (cache
miss)** en cada paso, obligando a la CPU a suspender momentáneamente la
ejecución para esperar lecturas de la lenta memoria principal (RAM).

:::{code-block} c
:caption: Recorrido columna por columna (Cache-Unfriendly)
// Lazo externo: columnas (j)
for (size_t j = 0; j < COLUMNAS; j++)
{
    // Lazo interno: filas (i)
    for (size_t i = 0; i < FILAS; i++)
    {
        printf("%d ", matriz[i][j]); // Salto de fila en cada paso
    }
    printf("\n"); // Nueva línea al final de cada columna
}

:::
<!-- {code-block} c -->

:::{figure} 1/recorrido_filas_columnas.svg
:label: fig-recorrido-filas-columnas
:align: center
:width: 80%

Recorrido por filas vs. recorrido por columnas.

:::
<!-- {figure} 1/recorrido_filas_columnas.svg -->
<!-- {figure} 3/recorrido_filas_columnas.svg -->

:::{figure} 1/cache_localidad.svg
:label: fig-cache-localidad
:align: center
:width: 85%

Acceso a memoria y fallos de caché según el orden del lazo.

:::
<!-- {figure} 1/cache_localidad.svg -->

:::{important} Impacto en la Práctica

En matrices de gran tamaño (por ejemplo, procesamiento de imágenes o
simulaciones), el recorrido ineficiente puede degradar el rendimiento por un
factor de hasta 10 veces o más. Siempre estructurá los lazos anidados de forma
que el lazo más interno avance en la dimensión contigua en memoria (las
columnas, en el caso de C).

:::
<!-- {important} Impacto en la Práctica -->

(recorrido-diagonal)=
#### Recorrido Diagonal

Para matrices cuadradas, es común necesitar acceder a las diagonales.

:::{code-block} c
:caption: Acceso a diagonal principal y secundaria
#define DIM 4
int matriz_cuadrada[DIM][DIM];
// Diagonal principal (i == j)
printf("Diagonal principal: ");
for (size_t i = 0; i < DIM; i++)
{
    printf("%d ", matriz_cuadrada[i][i]);
}
printf("\n");
// Diagonal secundaria (i + j == DIM - 1)
printf("Diagonal secundaria: ");
for (size_t i = 0; i < DIM; i++)
{
    printf("%d ", matriz_cuadrada[i][DIM - 1 - i]);
}
printf("\n");

:::
<!-- {code-block} c -->

:::{figure} 1/diagonales_matriz.svg
:label: fig-diagonales-matriz
:align: center
:width: 75%

Diagonal principal e inversa en una matriz cuadrada.

:::
<!-- {figure} 1/diagonales_matriz.svg -->


---

(pasando-matrices-a-funciones-metodo-clasico)=
### Pasando matrices a funciones (Método Clásico)

Al pasar una matriz como argumento a una función, el estándar de C requiere que
se especifiquen explícitamente **todas las dimensiones, a excepción de la
primera**. Esto es necesario para que el compilador pueda calcular el
desplazamiento en memoria de cada elemento.

:::{code-block} c
:linenos:
#define COLUMNAS 4
// Es crucial pasar las dimensiones para cumplir con la regla {ref}`0x300Ch`.
void imprimir_matriz(int mat[][COLUMNAS], size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

:::
<!-- {code-block} c -->

¿Acaso las `columnas` _no están ya en el macro_ `COLUMNAS`? Para garantizar la
consistencia y minimizar los efectos secundarios en las funciones que operan con
matrices, es fundamental ser explícito con el contexto en el que deben trabajar.

En este caso, las columnas como argumento evita que nuestro código dependa de un
valor que es esencialmente externo a la misma y aunque funciona perfectamente
sin él, en el momento en que veamos memoria dinámica, el código no funcionará
sin mayores cambios.

:::{important} Límite de control vs. Direccionamiento en memoria

Es crucial notar que en la firma `void imprimir_matriz(int mat[][COLUMNAS],
size_t filas, size_t columnas)`, el parámetro `columnas` sirve únicamente como
límite de control para el lazo interno de impresión (`j < columnas`). El
compilador de C utiliza exclusivamente el valor constante `COLUMNAS` del tipo de
dato (`int mat[][COLUMNAS]`) para realizar el cálculo de desplazamiento de
memoria al evaluar `mat[i][j]`. Pasar `columnas` no altera en absoluto cómo el
compilador direcciona físicamente los elementos en la memoria contigua.

:::
<!-- {important} Límite de control vs. Direccionamiento en memoria -->

(calculo-de-desplazamiento-de-memoria)=
#### Cálculo de Desplazamiento de Memoria

Dicha información es indispensable para que el compilador pueda calcular
correctamente el desplazamiento de memoria necesario para localizar cualquier
elemento `matriz[i][j]`, utilizando una fórmula análoga a:

:::{math}

\text{direccionbase} + (i \times \text{COLUMNAS} + j) \times \text{sizeof(int)}

:::
<!-- {math} -->

(pasando-matrices-a-funciones-metodo-alv)=
#### Pasando matrices a funciones (Método ALV)

Aunque el uso de ALV en el stack está estrictamente prohibido por seguridad
(riesgo de desborde de pila), la sintaxis de parámetros ALV en firmas de
funciones (introducida en el estándar C99) es una herramienta sumamente útil y
segura para crear funciones genéricas capaces de operar sobre matrices de
dimensiones arbitrarias sin recurrir a macros estáticas.

Al declarar la matriz en los parámetros de la función utilizando variables
previamente declaradas como dimensiones, el compilador puede generar código para
calcular el desplazamiento de memoria de manera dinámica y precisa.

:::{important} Orden de los Parámetros

Resulta crucial observar que, en la firma de la función, los parámetros que
definen las dimensiones de la matriz deben estar antes que el parámetro de la
matriz misma. Esto se debe a que el compilador debe conocer el tamaño de `filas`
y `cols` antes de interpretar la declaración de `matriz[filas][cols]`.

:::
<!-- {important} Orden de los Parámetros -->

:::{code-block} c

// Correcto: filas y cols se conocen antes de que el compilador procese
matriz[filas][cols] void procesar_matriz(size_t filas, size_t cols,
                                         int matriz[filas][cols])
{
    printf("\nProcesando matriz de %zu x %zu\n", filas, cols);
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matriz[i][j] *= 2; // Ejemplo: duplicar cada valor
        }
    }
}

:::
<!-- {code-block} c -->

(matrices-multidimensionales)=
### Matrices Multidimensionales

El lenguaje C no impone un límite de dos dimensiones para los arreglos; es
posible declarar arreglos multidimensionales. Un arreglo tridimensional, por
ejemplo, puede conceptualizarse como un cubo de datos.

:::{figure} 1/matriz_3d.svg
:label: fig-matriz-3d
:align: center
:width: 80%

Representación lógica y orden de almacenamiento de una matriz tridimensional.

:::
<!-- {figure} 1/matriz_3d.svg -->

:::{code-block} c
:caption: Declaración y recorrido de un arreglo 3D
// Arreglo tridimensional: 2 capas, 3 filas, y 4 columnas.
int cubo[2][3][4];
// Acceso a un elemento
cubo[1][0][2] = 99;
// Recorrido con tres lazos anidados
for (size_t i = 0; i < 2; i++)
{ // Capas
    for (size_t j = 0; j < 3; j++)
    { // Filas
        for (size_t k = 0; k < 4; k++)
        { // Columnas
            cubo[i][j][k] = i + j + k;
        }
    }
}

:::
<!-- {code-block} c -->



(operaciones-matematicas-con-matrices)=
## Operaciones Matemáticas con Matrices

En el ámbito de la programación en C y otras áreas de la computación, el manejo
de matrices es fundamental. A continuación, se presentan los algoritmos y las
expresiones matemáticas para las operaciones básicas entre matrices.

:::{figure} 1/operaciones_basicas.svg
:label: fig-operaciones-basicas
:align: center
:width: 85%

Suma y transposición lógica de matrices.

:::
<!-- {figure} 1/operaciones_basicas.svg -->

(suma-de-matrices)=
### Suma de Matrices

La suma de dos matrices, A y B, de las mismas dimensiones ($m \times n$), guarda
el resultado en una matriz C de la misma dimensión. Cada elemento de C es la
suma de los elementos correspondientes en A y B.

(expresion-matematica-suma-matrices)=
#### Expresión de Suma de Matrices

Para dos matrices A y B de tamaño $m \times n$, la matriz resultante C se define
como:

:::{math}
:label: eq-suma-matrices
C_{i,j} = A_{i,j} + B_{i,j}

:::
<!-- {math} -->

donde $i$ representa la fila y $j$ la columna.

(expansion-matematica-suma-matrices)=
#### Expansión de Suma de Matrices

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

(algoritmo-en-pseudocodigo-suma-matrices)=
#### Algoritmo de Suma de Matrices en Pseudocódigo

El algoritmo recorre ambas matrices y suma los elementos en la misma posición.

:::{code-block}pseudocode
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

:::
<!-- {code-block}pseudocode -->

---

(resta-de-matrices)=
### Resta de Matrices

De manera análoga a la suma, la resta de dos matrices A y B de idénticas
dimensiones guarda el resultado en una matriz C donde cada elemento es la
diferencia de
los elementos correspondientes.

(expresion-matematica-resta-matrices)=
#### Expresión de Resta de Matrices

Para dos matrices A y B de tamaño $m \times n$, la matriz resultante C se define
como:

:::{math}
:label: eq-resta-matrices
C_{i,j} = A_{i,j} - B_{i,j}

:::
<!-- {math} -->

(algoritmo-en-pseudocodigo-resta-matrices)=
#### Algoritmo de Resta de Matrices en Pseudocódigo

El procedimiento es idéntico al de la suma, pero se realiza una resta.

:::{code-block}pseudocode
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

:::
<!-- {code-block}pseudocode -->

---

(multiplicacion-de-matrices)=
### Multiplicación de Matrices

La multiplicación de una matriz A de dimensión $m \times p$ por una matriz B de
dimensión $p \times n$ guarda el resultado en una matriz C de dimensión $m
\times n$. Es crucial que el
número de columnas de A sea igual al número de filas de B.

:::{figure} 1/multiplicacion_matrices.svg
:label: fig-multiplicacion-matrices
:align: center
:width: 90%

Proceso físico de multiplicación de matrices (fila por columna).

:::
<!-- {figure} 1/multiplicacion_matrices.svg -->

(expresion-matematica-multiplicacion-matrices)=
#### Expresión de Multiplicación de Matrices

El elemento $(i,j)$ de la matriz resultante C se calcula como la suma de los
productos de los elementos de la fila $i$ de A por los elementos de la columna
$j$
de B.

:::{math}
:label: eq-mult-matrices
C_{i,j} = \sum_{k=1}^{p} A_{i,k} \cdot B_{k,j}

:::
<!-- {math} -->

(expansion-matematica-multiplicacion-matrices)=
#### Expansión de Multiplicación de Matrices

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
\begin{pmatrix} \color{blue}A_{1,1} & \color{blue}A_{1,2} \\ A_{2,1} & A_{2,2}
\end{pmatrix} \times \begin{pmatrix} \color{red}B_{1,1} & B_{1,2} \\
\color{red}B_{2,1} & B_{2,2} \end{pmatrix} = \begin{pmatrix} C_{1,1} & C_{1,2}
\\ C_{2,1} & C_{2,2} \end{pmatrix}
$$

Donde
$C_{1,1} = (\color{blue}A_{1,1} \cdot \color{red}B_{1,1}) + (\color{blue}A_{1,2}
\cdot \color{red}B_{2,1})$.

(algoritmo-en-pseudocodigo-multiplicacion-matrices)=
#### Algoritmo de Multiplicación de Matrices en Pseudocódigo

Este algoritmo requiere tres lazos anidados para calcular el producto escalar de
cada fila de A con cada columna de B.

(algoritmo-en-pseudocodigo-optimizado-cache-friendly)=
#### Algoritmo en Pseudocódigo Optimizado (Cache-Friendly)

Para realizar la multiplicación minimizando los fallos de caché, es conveniente
reordenar los lazos del algoritmo clásico ($i, j, k$) al orden optimizado ($i,
k, j$). De esta forma, el lazo más interno recorre consecutivamente las columnas
de las matrices en memoria principal, garantizando localidad espacial.

:::{code-block}pseudocode
:caption: Algoritmo optimizado para la multiplicación de una matriz A (m x p) por una matriz B (p x n) en orden i-k-j.
:linenos:

PROCEDIMIENTO multiplicar_matrices(A, B, C, m, p, n)
  // A es una matriz de m x p de entrada
  // B es una matriz de p x n de entrada
  // C es la de dimensión m x n de salida (por referencia). Se asume
  inicializada en 0.
  
  // Inicializar la matriz de resultados C en cero
  PARA i DESDE 0 HASTA m - 1
    PARA j DESDE 0 HASTA n - 1
      C[i][j] = 0
    FIN PARA
  FIN PARA

  // Multiplicación en orden i, k, j para optimizar el acceso a caché
  PARA i DESDE 0 HASTA m - 1
    PARA k DESDE 0 HASTA p - 1
      factor = A[i][k]
      PARA j DESDE 0 HASTA n - 1
        C[i][j] = C[i][j] + (factor * B[k][j])
      FIN PARA
    FIN PARA
  FIN PARA
FIN PROCEDIMIENTO

:::
<!-- {code-block}pseudocode -->

:::{tip} ¿Por qué el orden $i, k, j$?

En la implementación clásica ($i, j, k$), el lazo más interno recorre `k`,
accediendo a `B[k][j]`. Como `k` varía y `j` es constante, saltamos filas de la
matriz `B` en memoria física, provocando constantes fallos de caché (*cache
misses*). En cambio, al usar el orden ($i, k, j$), el lazo más interno recorre
`j` (las columnas). Tanto `C[i][j]` como `B[k][j]` se acceden de forma contigua
en memoria, maximizando el rendimiento del hardware y aprovechando la línea de
caché.

:::
<!-- {tip} ¿Por qué el orden $i, k, j$? -->

(validacion-y-manejo-de-errores)=
### Validación y Manejo de Errores

En aplicaciones robustas, es fundamental implementar validaciones para prevenir
accesos fuera de límites y operaciones inválidas. Esto es especialmente crítico
en C, donde no existe verificación automática de límites ({ref}`0x300Ch`).

:::{figure} 1/validacion_dimensiones.svg
:label: fig-validacion-dimensiones
:align: center
:width: 80%

Validación de dimensiones y coherencia en operaciones con matrices.

:::
<!-- {figure} 1/validacion_dimensiones.svg -->

(validacion-de-indices)=
#### Validación de Índices

:::{code-block} c
:caption: Función para validar acceso seguro a matriz
:linenos:
#include <stdbool.h>
#include <stdio.h>
#define MAX_COLUMNAS 100
bool indice_valido(size_t fila, size_t columna,
                   size_t max_filas, size_t max_columnas)
{
    return (fila < max_filas && columna < max_columnas);
}
int acceso_seguro_matriz(size_t filas, size_t columnas,
                         int matriz[filas][columnas], size_t fila,
                         size_t columna)
{
    if (!indice_valido(fila, columna, filas, columnas))
    {
        fprintf(stderr, "Error: Índices fuera de límites (%zu, %zu)\n", fila,
                columna);
        return -1; // Valor de error
    }
    return matriz[fila][columna];
}

:::
<!-- {code-block} c -->

(validacion-de-operaciones)=
#### Validación de Operaciones

Para operaciones matemáticas entre matrices, debemos verificar la compatibilidad
de dimensiones antes de proceder.

:::{code-block} c
:caption: Validación para operaciones con matrices
:linenos:
typedef enum {
    MATRIZ_OK,
    MATRIZ_ERROR_DIMENSIONES,
    MATRIZ_ERROR_MEMORIA,
    MATRIZ_ERROR_SINGULAR
} resultado_matriz_t;
resultado_matriz_t validar_suma(size_t filas_a, size_t columnas_a,
                                size_t filas_b, size_t columnas_b)
{
    if (filas_a != filas_b || columnas_a != columnas_b)
    {
        return MATRIZ_ERROR_DIMENSIONES;
    }
    return MATRIZ_OK;
}
resultado_matriz_t validar_multiplicacion(size_t filas_a, size_t columnas_a,
                                          size_t filas_b, size_t columnas_b)
{
    if (columnas_a != filas_b)
    {
        return MATRIZ_ERROR_DIMENSIONES;
    }
    return MATRIZ_OK;
}

:::
<!-- {code-block} c -->

:::{warning} Responsabilidad del programador

En C, la validación de límites es responsabilidad del programador. El lenguaje 
no proporciona verificaciones automáticas, por lo que debés implementar estas 
validaciones de forma explícita. El no hacerlo puede resultar en comportamiento 
indefinido, violando la regla de estilo {ref}`0x0001h` sobre claridad y
prolijidad
del código. 

:::
<!-- {warning} Responsabilidad del programador -->

(mejores-practicas-y-optimizaciones)=
### Mejores Prácticas y Optimizaciones

(uso-de-macros-para-dimensiones)=
#### Uso de Macros para Dimensiones

Utilizá siempre macros para definir las dimensiones de tus matrices, siguiendo
la regla de estilo {ref}`0x3011h`. Esto facilita el mantenimiento y la
modificación del código.

:::{code-block} c
:caption: Definición de dimensiones con macros
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
int matriz[MAX_FILAS][MAX_COLUMNAS];

:::
<!-- {code-block} c -->

(funciones-auxiliares)=
#### Funciones Auxiliares

Creá funciones auxiliares para operaciones comunes, siguiendo la regla de
claridad {ref}`0x0001h`:

:::{code-block} c
:caption: Funciones auxiliares para matrices
:linenos:
void imprimir_matriz(int matriz[][MAX_COLUMNAS], size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void inicializar_con_ceros(int matriz[][MAX_COLUMNAS], size_t filas,
                           size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }
}
bool son_matrices_iguales(int a[][MAX_COLUMNAS], int b[][MAX_COLUMNAS],
                          size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

:::
<!-- {code-block} c -->

(apendice-avanzado-operaciones-matriciales-de-algebra-lineal)=
### Apéndice Avanzado: Operaciones Matriciales de Álgebra Lineal

(calculo-de-determinantes)=
#### Cálculo de Determinantes

El determinante es un valor escalar que se puede calcular para toda **matriz
cuadrada**. Este valor encapsula propiedades importantes de la matriz, como la
invertibilidad. Se denota como det(A) o |A|.

##### Definición Matemática

Para una matriz de 2x2, el cálculo es directo:

$$ \det(A) = \begin{vmatrix} a & b \\ c & d \end{vmatrix} = ad - bc $$

Para matrices de mayor tamaño $(n \times n)$, un método común es la **expansión
por
cofactores**. El determinante se calcula expandiendo a lo largo de una fila o
columna. Usando la primera fila, la fórmula es:

:::{math}
:label: eq-determinante
\det(A) = \sum_{j=1}^{n} (-1)^{1+j} \cdot A_{1,j} \cdot \det(M_{1,j})

:::
<!-- {math} -->

Donde:

- $A_{1,j}$ es el elemento en la primera fila y la columna $j$.
- $M_{1,j}$ es la **matriz menor**, que es la submatriz que resulta de eliminar
  la fila 1 y la columna $j$ de A.
- El término $(-1)^{1+j} \cdot \det(M_{1,j})$ se conoce como el **cofactor** del
  elemento $A_{1,j}$.

##### Algoritmo Recursivo (Basado en Cofactores)

Este método matemático se traduce de forma natural en un algoritmo recursivo. La
idea es reducir el problema de un determinante $n \times n$ al cálculo de varios
determinantes $(n-1) \times (n-1)$, hasta llegar al caso base de una matriz 2x2.

:::{warning} Costo Computacional
:class: dropdown
Este algoritmo es conceptualmente claro, pero computacionalmente ineficiente
para matrices grandes, con una complejidad de $O(n!)$. Para aplicaciones de alto
rendimiento, se utilizan otros métodos como la descomposición LU.

:::
<!-- {warning} Costo Computacional -->

:::{code-block}pseudocode
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
    determinante_total = determinante_total + (signo * A[0][j_actual] *
    sub_determinante)
  FIN PARA

  RETORNAR determinante_total
FIN FUNCIÓN

:::
<!-- {code-block}pseudocode -->

---

(inversion-de-matrices)=
#### Inversión de Matrices

La inversa de una matriz cuadrada A, denotada como $A^{-1}$, es aquella matriz
que al multiplicarla por A da como resultado la matriz identidad I.

$$ A \cdot A^{-1} = A^{-1} \cdot A = I $$

##### Condiciones para la Inversión

Una matriz es invertible si y solo si cumple dos condiciones:

1.  Es una **matriz cuadrada**.
2.  Su **determinante es distinto de cero**. A las matrices con determinante
    cero se las llama **singulares** y no tienen inversa.

##### Método de la Matriz Adjunta

Un método para encontrar la inversa se basa en el determinante y la **matriz
adjunta**. La fórmula es:

:::{math}
:label: eq-inversa
A^{-1} = \frac{1}{\det(A)} \cdot \text{adj}(A)

:::
<!-- {math} -->

Donde $adj(A)$ es la matriz adjunta de A, que se define como la **transpuesta
de la matriz de cofactores** de A.

##### Algoritmo (Basado en la Adjunta)

El algoritmo consiste en seguir los pasos de la fórmula matemática.

1.  **Calcular el determinante:** Si es cero, la matriz no es invertible.
2.  **Calcular la matriz de cofactores:** Para cada elemento $A_{i,j}$, su
    cofactor es $(-1)^{i+j} \det(M_{i,j})$.
3.  **Calcular la matriz adjunta:** Transponer la matriz de cofactores.
4.  **Obtener la inversa:** Multiplicar la matriz adjunta por el escalar
    $1 / \det(A)$.

:::{code-block}pseudocode
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

:::
<!-- {code-block}pseudocode -->

### Matrices Dinámicas en el Heap

Cuando las dimensiones de una matriz no se conocen en tiempo de compilación y no
querés incurrir en el riesgo de usar Arreglos de Longitud Variable (ALV/VLA) en
la pila (violando la regla {ref}`0x5001h`), debés recurrir a la asignación de
memoria dinámica en el Heap.

En C, existen dos formas de modelar matrices dinámicas:

#### 1. Modelo de Bloque Único Contiguo (Recomendado para rendimiento)

Consiste en alocar un único bloque unidimensional continuo en el Heap que
contenga todos los elementos de la matriz ($F \times C$). Luego, se calcula el
desplazamiento manualmente para indexar los elementos: `matriz[i * columnas +
j]`.

**Ventajas:**
- **Localidad espacial máxima:** Todos los elementos son físicamente contiguos
  en memoria, lo que optimiza el uso de la memoria caché y reduce drásticamente
  los fallos de caché (*cache misses*).
- **Menor sobrecarga (overhead):** Solo realizás una llamada a
  `malloc`/`calloc`, lo que reduce el costo de metadatos en el Heap y acelera la
  liberación.
- **Evita la fragmentación:** No fragmenta el Heap con múltiples pequeñas
  asignaciones.

**Desventajas:**
- La sintaxis de indexación es manual (`matriz[i * columnas + j]`) y puede ser
  menos intuitiva que `matriz[i][j]`.

Ejemplo de implementación:

:::{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int *crear_matriz_contigua(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    // Alocación de un único bloque físico contiguo
    int *matriz = malloc(filas * columnas * sizeof(*matriz));
    if (matriz == NULL)
    {
        perror("Error al asignar memoria para la matriz contigua");
        return NULL;
    }
    // Inicialización a cero
    for (size_t i = 0; i < filas * columnas; i++)
    {
        matriz[i] = 0;
    }
    return matriz;
}
void destruir_matriz_contigua(int **matriz)
{
    if (matriz == NULL || *matriz == NULL)
    {
        return;
    }
    free(*matriz);
    *matriz = NULL; // Aniquilación del puntero post-free
}

:::
<!-- {code-block} c -->

#### 2. Modelo de Arreglo de Punteros (Matriz Deshilachada o *Jagged Matrix*)

Consiste en alocar un arreglo de punteros (de tamaño $F$) donde cada elemento
del arreglo apunta a una fila alocada de forma independiente en el Heap (de
tamaño $C$). Esto permite la sintaxis nativa `matriz[i][j]`.

**Ventajas:**
- Sintaxis intuitiva idéntica a las matrices estáticas: `matriz[i][j]`.

**Desventajas:**
- **Pérdida de localidad espacial:** Cada fila puede estar alocada en cualquier
  parte del Heap, lo que rompe la contigüidad física e incrementa los fallos de
  caché.
- **Fragmentación física:** Se realizan $F + 1$ llamadas a alocadores, lo que
  introduce un alto overhead de metadatos en el Heap.
- **Complejidad de liberación:** Se requiere un lazo para liberar cada fila
  individualmente antes de liberar el arreglo de punteros.

Ejemplo de implementación:

:::{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int **crear_matriz_punteros(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    // Asignación del arreglo de punteros a filas
    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        perror("Error al asignar el arreglo de filas");
        return NULL;
    }
    // Asignación individual de cada fila
    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = calloc(columnas, sizeof(*(matriz[i])));
        if (matriz[i] == NULL)
        {
            // Lazo de liberación en caso de fallo intermedio
            for (size_t j = 0; j < i; j++)
            {
                free(matriz[j]);
                matriz[j] = NULL;
            }
            free(matriz);
            matriz = NULL;
            return NULL;
        }
    }
    return matriz;
}
void destruir_matriz_punteros(int ***matriz, size_t filas)
{
    if (matriz == NULL || *matriz == NULL)
    {
        return;
    }
    int **m = *matriz;
    for (size_t i = 0; i < filas; i++)
    {
        if (m[i] != NULL)
        {
            free(m[i]);
            m[i] = NULL;
        }
    }
    free(m);
    *matriz = NULL; // Aniquilación del puntero a nivel de cliente
}

:::
<!-- {code-block} c -->

## Ejercicios de Autoevaluación

### Definición y Declaración

:::{exercise}
:label: ej-mat-declaracion-size
Declará una matriz de números reales de punto flotante de precisión simple
(`float`) de 5 filas y 10 columnas. Calculá de forma matemática cuántos bytes
ocupará físicamente en la memoria del programa si el tipo `float` ocupa 4 bytes.

:::
<!-- {exercise} -->

:::{solution} ej-mat-declaracion-size
:class: dropdown
La declaración correspondiente es:
``` c
float temperaturas[5][10];
```
<!-- c -->
El tamaño total en bytes se calcula multiplicando el número de filas por el de
columnas por el tamaño en bytes del tipo básico:
$$\text{Tamaño} = 5 \times 10 \times \text{sizeof(float)} = 50 \times 4\text{
bytes} = 200\text{ bytes}$$

:::
<!-- {solution} ej-mat-declaracion-size -->

:::{exercise}
:label: ej-mat-row-major-layout
Dada la matriz `int M[2][3] = {{10, 20, 30}, {40, 50, 60}};`, escribí la
secuencia lineal exacta de valores en la que se guardarán estos elementos en la
memoria física del computador siguiendo el criterio *Row-Major Order*.

:::
<!-- {exercise} -->

:::{solution} ej-mat-row-major-layout
:class: dropdown
El criterio *Row-Major Order* (orden de fila principal) dispone las filas una
detrás de otra en la memoria contigua. La secuencia física en RAM será:
`[10, 20, 30, 40, 50, 60]`
Físicamente en memoria, el elemento `M[0][2]` (`30`) es inmediatamente adyacente
a `M[1][0]` (`40`).

:::
<!-- {solution} ej-mat-row-major-layout -->

:::{exercise}
:label: ej-mat-multidim-cube
Escribí la declaración de un arreglo tridimensional de enteros llamado
`sensores_3d` que represente lecturas físicas organizadas en 3 niveles de
profundidad, donde cada nivel tiene una cuadrícula de 4 filas y 5 columnas.
Calculá el número total de elementos individuales que se reservan en memoria.

:::
<!-- {exercise} -->

:::{solution} ej-mat-multidim-cube
:class: dropdown
La declaración del arreglo tridimensional es:
``` c
int sensores_3d[3][4][5];
```
<!-- c -->
El número total de celdas de almacenamiento entero reservadas en memoria se
calcula como el producto de todas sus dimensiones:
$$\text{Elementos} = 3 \times 4 \times 5 = 60\text{ celdas}$$

:::
<!-- {solution} ej-mat-multidim-cube -->


### Inicialización y Acceso

:::{exercise}
:label: ej-mat-init-implicita
Explicá por qué la declaración `int M[3][] = {{1, 2}, {3, 4}, {5, 6}};` no es
válida en C y provoca un error de compilación, fundamentando tu respuesta
basándote en la forma en que el compilador direcciona la memoria.

:::
<!-- {exercise} -->

:::{solution} ej-mat-init-implicita
:class: dropdown
Es inválida porque la segunda dimensión (columnas) no está especificada.
En C, para calcular la dirección física del elemento `M[i][j]`, el compilador
requiere saber de forma exacta cuántos elementos contiene cada fila
($\text{CANTIDAD\_COLUMNAS}$). Sin esta dimensión, el compilador es incapaz de
computar la fórmula de direccionamiento $\text{desplazamiento} = i \times
\text{columnas} + j$ en memoria contigua, provocando un error de traducción. La
primera dimensión es la única que puede ser implícita.

:::
<!-- {solution} ej-mat-init-implicita -->

:::{exercise}
:label: ej-mat-init-manual
Implementá un programa en C que declare una matriz de enteros de 4x4 y la
inicialice programáticamente de forma tal que todos los elementos de la diagonal
principal tengan el valor `1` y el resto de los elementos tengan el valor `0`
(matriz identidad).

:::
<!-- {exercise} -->

:::{solution} ej-mat-init-manual
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#define N 4
int main()
{
    int identidad[N][N];
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (i == j)
            {
                identidad[i][j] = 1;
            }
            else
            {
                identidad[i][j] = 0;
            }
        }
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-mat-init-manual -->

:::{exercise}
:label: ej-mat-acceso-indefinido
Explicá por qué intentar leer o escribir en `matriz[FILAS][COLUMNAS]` de una
matriz declarada como `int matriz[FILAS][COLUMNAS]` es un error grave de tipo
"fuera de límites" y qué consecuencias físicas provoca en la memoria.

:::
<!-- {exercise} -->

:::{solution} ej-mat-acceso-indefinido
:class: dropdown
Debido al uso de índices de base cero en C, los rangos válidos son:
- Para filas: de `0` a `FILAS - 1`.
- Para columnas: de `0` a `COLUMNAS - 1`.
El índice `matriz[FILAS][COLUMNAS]` apunta a un elemento situado completamente
fuera de la memoria reservada para el arreglo (específicamente, es la dirección
adyacente a la primera posición de la fila posterior inexistente). Leer o
escribir en esta dirección provoca un **comportamiento indefinido**, el cual
puede resultar en corrupción de variables adyacentes en el stack o en un fallo
de segmentación (*Segmentation Fault*).

:::
<!-- {solution} ej-mat-acceso-indefinido -->


### Recorridos y Memoria

:::{exercise}
:label: ej-mat-recorrido-diagonal-sec
Escribí una función pura en C llamada `sumar_diagonal_secundaria` que reciba una
matriz cuadrada de dimensión fija de $4 \times 4$ y retorne la suma de los
elementos pertenecientes a su diagonal secundaria.

:::
<!-- {exercise} -->

:::{solution} ej-mat-recorrido-diagonal-sec
:class: dropdown
La diagonal secundaria de una matriz cuadrada de orden $N$ cumple que la suma de
sus índices de fila $i$ y columna $j$ es igual a $N - 1$. Por lo tanto, $j = N -
1 - i$.
```{code-block} c
:linenos:
#include <stddef.h>
#define N 4
int sumar_diagonal_secundaria(const int matriz[N][N])
{
    int suma = 0;
    for (size_t i = 0; i < N; i++)
    {
        // Acceso directo a la diagonal secundaria
        suma += matriz[i][N - 1 - i];
    }
    return suma;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-mat-recorrido-diagonal-sec -->

:::{exercise}
:label: ej-mat-cache-performance
Explicá por qué el recorrido de una matriz por columnas (lazo externo en
columnas, interno en filas) produce una degradación notable de velocidad en la
CPU en comparación con el recorrido secuencial por filas.

:::
<!-- {exercise} -->

:::{solution} ej-mat-cache-performance
:class: dropdown
En C, las matrices se disponen linealmente en memoria por filas.
- **Recorrido por filas**: Accede a elementos secuenciales que se encuentran de
  forma adyacente en memoria física. El hardware precarga estos bloques en la
  rápida memoria caché (localidad espacial), resultando en aciertos de caché
  (*cache hits*).
- **Recorrido por columnas**: Provoca saltos en memoria equivalentes al tamaño
  de una fila entera en cada iteración. Esto invalida constantemente los bloques
  cargados en caché, forzando a la CPU a buscar los datos en la memoria RAM
  principal lenta (fallos de caché o *cache misses*), ralentizando el
  procesamiento.

:::
<!-- {solution} ej-mat-cache-performance -->

:::{exercise}
:label: ej-mat-recorrido-bordes
Escribí un fragmento de código en C que recorra una matriz de enteros `M` de
dimensiones `FILAS` x `COLUMNAS` e imprima por pantalla únicamente los elementos
que pertenecen al borde periférico (fila superior, columna derecha, fila
inferior y columna izquierda).

:::
<!-- {exercise} -->

:::{solution} ej-mat-recorrido-bordes
:class: dropdown
```{code-block} c
:linenos:
#define FILAS 4
#define COLUMNAS 5
int M[FILAS][COLUMNAS];
// Recorrido de los bordes periféricos
for (size_t i = 0; i < FILAS; i++)
{
    for (size_t j = 0; j < COLUMNAS; j++)
    {
        // Si pertenece a la primera o última fila, o a la primera o última
        // columna
        if (i == 0 || i == FILAS - 1 || j == 0 || j == COLUMNAS - 1)
        {
            printf("%d\t", M[i][j]);
        }
        else
        {
            printf("\t"); // Espacio para el interior vacío
        }
    }
    printf("\n");
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-mat-recorrido-bordes -->


### Funciones y Operaciones

:::{exercise}
:label: ej-mat-func-vla-param
Implementá una función en C utilizando la sintaxis de parámetros ALV/VLA
(estándar C99) que reciba una matriz de enteros de dimensiones dinámicas y
verifique si es una **matriz simétrica** (aquella que es igual a su transpuesta,
es decir, $M_{i,j} == M_{j,i}$ para toda celda).

:::
<!-- {exercise} -->

:::{solution} ej-mat-func-vla-param
:class: dropdown
Para que una matriz sea simétrica, debe ser necesariamente cuadrada (filas ==
columnas).
```{code-block} c
:linenos:
#include <stdbool.h>
#include <stddef.h>
bool es_matriz_simetrica(size_t n, const int matriz[n][n])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            // Solo verificamos el triángulo superior con el inferior
            if (matriz[i][j] != matriz[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-mat-func-vla-param -->

:::{exercise}
:label: ej-mat-func-desplazamiento
Dada una matriz `int M[3][4]` cuya dirección de memoria base de inicio
(`&M[0][0]`) es `0x1000` en la memoria física y sabiendo que el tipo `int` ocupa
exactamente 4 bytes, deducí el cálculo matemático detallado y la dirección
física resultante en la que el compilador ubicará al elemento `M[2][1]`.

:::
<!-- {exercise} -->

:::{solution} ej-mat-func-desplazamiento
:class: dropdown
El cálculo de desplazamiento para un elemento `M[i][j]` en una matriz de
columnas $C$ es:
$$\text{Dirección} = \text{Dirección Base} + (i \times C + j) \times
\text{sizeof(tipo)}$$
Sustituyendo los valores del problema:
- Dirección Base = `0x1000`
- $i = 2$, $j = 1$
- $C = 4$ columnas
- $\text{sizeof(int)} = 4$ bytes
$$\text{Desplazamiento} = (2 \times 4 + 1) \times 4 = (8 + 1) \times 4 = 9
\times 4 = 36\text{ bytes}$$
En base hexadecimal, $36$ es igual a `0x24`. Por lo tanto:
$$\text{Dirección física} = \text{0x1000} + \text{0x0024} = \text{0x1024}$$

:::
<!-- {solution} ej-mat-func-desplazamiento -->

:::{exercise}
:label: ej-mat-operacion-transpuesta
Escribí un procedimiento en C utilizando parámetros de tamaño variable que tome
una matriz `A` de dimensiones $M \times N$ y guarde su transpuesta en otra
matriz `B` de dimensiones $N \times M$.

:::
<!-- {exercise} -->

:::{solution} ej-mat-operacion-transpuesta
:class: dropdown
```{code-block} c
:linenos:
#include <stddef.h>
void transponer_matriz(size_t filas_a, size_t cols_a,
                       const int A[filas_a][cols_a], int B[cols_a][filas_a])
{
    for (size_t i = 0; i < filas_a; i++)
    {
        for (size_t j = 0; j < cols_a; j++)
        {
            // El elemento A[i][j] se copia en B[j][i]
            B[j][i] = A[i][j];
        }
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-mat-operacion-transpuesta -->



## Glosario

:::{glossary}

memoria caché 
: Una **memoria caché** (del francés _cacher_,
  "esconder") es un componente de hardware o software que almacena datos para
  que
  las futuras solicitudes de esos datos puedan ser atendidas más rápidamente. Se
  trata de una memoria auxiliar, de alta velocidad y menor capacidad, situada
  entre la unidad central de procesamiento (CPU) y la memoria de acceso
  aleatorio
  (RAM).
  
  El objetivo principal de una caché es **acelerar el acceso a los datos** que
  se
  utilizan con mayor frecuencia. Cuando la CPU necesita leer o escribir datos,
  primero busca en la caché. Si los datos se encuentran allí (lo que se conoce
  como un **acierto de caché** o _cache hit_), se accede a ellos de forma casi
  inmediata, evitando el acceso mucho más lento a la memoria principal. Si los
  datos no están en la caché (**fallo de caché** o _cache miss_), se deben
  recuperar de la RAM y, por lo general, se copian en la caché para futuros
  accesos.
  
  Existen diferentes **niveles de caché** (L1, L2, L3), que se diferencian por
  su
  tamaño, velocidad y proximidad a los núcleos de la CPU. La caché L1 es la más
  pequeña y rápida, mientras que la L3 es la más grande y lenta de las tres.
  
  ¿Pero por que no todo es memoria caché? La relación costo capacidad. Las
  memorias mas cercanas al procesador y las mas rápidas, son las mas caras,
  tengan
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
<!-- {glossary} -->








---

## Síntesis y Resumen

Las matrices en C se almacenan de forma contigua en memoria siguiendo un orden
de fila mayor (*row-major*). Recorrer una matriz fila por fila maximiza el uso
del caché de la CPU, mientras que hacerlo por columnas degrada el rendimiento.
Al pasar matrices a funciones, es necesario indicar todas las dimensiones
(excepto opcionalmente la primera) para permitir que el compilador calcule el
desplazamiento físico correcto. Se deben validar rigurosamente los límites de
los índices para evitar accesos fuera de rango.

## Referencias y Lecturas Complementarias

- {cite:t}`kernighan_c_2014`. Capítulo 5: Pointers and Arrays.
- {cite:t}`king_c_2008`. Capítulo 8: Arrays.
