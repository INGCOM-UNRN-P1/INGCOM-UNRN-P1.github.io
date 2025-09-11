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
int matriz[2][3] = {
    {1, 2, 3},  // Fila 0
    {4, 5, 6}   // Fila 1
};
```

### Inicialización con declaración implícita

```{code-block} c
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
int valor = matriz[2][3]; // Lee el valor del elemento en la fila 2, columna 3.
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
#define COLUMNAS 4

void imprimirMatriz(int mat[][COLUMNAS], size_t filas, size_t columnas) {
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
valor que es esencialmente externo a la misma y aunque funciona perfectamente sin él,
en el momento en que veamos memoria dinámica, el código no funcionará sin mayores
cambios.

### Cálculo de Desplazamiento de Memoria

Dicha información es indispensable para que el compilador pueda calcular
correctamente el desplazamiento de memoria necesario para localizar cualquier
elemento `matriz[i][j]`, utilizando una fórmula análoga a:

```{math}
\text{direccion_base} + (i \times \text{COLUMNAS} + j) \times \text{sizeof(int)}
```

### Pasando matrices a funciones (Método ALV)

La utilización de ALV's facilita la creación de funciones genéricas capaces de
operar sobre matrices de dimensiones arbitrarias.

:::{important} Orden de los Parámetros : class: important

Resulta crucial observar que, en la firma de la función, los parámetros que
definen las dimensiones de la matriz deben estar antes que el parámetro de la
matriz misma.

:::

```{code-block} c
// Correcto: filas y cols se conocen antes de que el compilador procese matriz[filas][cols]
void procesarMatriz(size_t filas, size_t cols, int matriz[filas][cols]) {
    printf("\nProcesando matriz de %zu x %zu\n", filas, cols);
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < cols; j++) {
            matriz[i][j] *= 2; // Ejemplo: duplicar cada valor
        }
    }
}
```

## 7. Matrices Multidimensionales

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

## 8. Consideraciones de Rendimiento: Localidad de Caché

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
// BAJO RENDIMIENTO: Genera fallos de caché frecuentes.
for (size_t j = 0; j < COLUMNAS; j++) {
    for (size_t i = 0; i < FILAS; i++) {
        suma += matriz[i][j];
    }
}

```
