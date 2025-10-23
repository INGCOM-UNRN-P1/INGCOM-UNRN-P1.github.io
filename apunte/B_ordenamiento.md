---
title: "Decálogo de Algoritmos de Busqueda y Ordenamiento"
short_title: "B - Algoritmos"
subtitle: "Compendio completo de métodos de ordenamiento y búsqueda"
---

Un **algoritmo de ordenamiento** es un procedimiento computacional que toma un conjunto de datos de entrada (como un arreglo) y produce una permutación de esos datos que los organiza según una relación de orden específica (generalmente, ascendente o descendente). El ordenamiento es una de las operaciones más fundamentales en la informática, crucial para optimizar la eficiencia de otros algoritmos, como los de búsqueda.

Este documento presenta un compendio exhaustivo de los principales algoritmos de ordenamiento, clasificados por su naturaleza y características. Para evaluar la eficiencia de estos algoritmos, se utilizan dos métricas clave: la complejidad temporal y la complejidad espacial.

## Conceptos Fundamentales de Complejidad

Al analizar un algoritmo, no solo nos interesa que funcione, sino cuán eficientemente lo hace. La complejidad algorítmica es el estudio formal de los recursos que un algoritmo consume. Lo interesante de esta técnica de análisis es la separación concreta con el hardware que lleva a cabo la tarea y el algoritmo en sí.

:::{note} Fundamentos teóricos
Para un tratamiento completo y riguroso del análisis asintótico, las notaciones Big-O, Omega y Theta, así como técnicas avanzadas de resolución de recurrencias, consultá el [capítulo sobre Análisis de Complejidad Algorítmica](14_complejidad.md).
:::

### Complejidad Temporal

La **complejidad temporal** es una medida de cuánto tiempo tarda un algoritmo en ejecutarse en función del tamaño de su entrada, denotado comúnmente como **$n$**. No se mide en segundos o milisegundos, ya que eso depende del hardware. En su lugar, se cuantifica el número de operaciones elementales (comparaciones, asignaciones, operaciones aritméticas) que el algoritmo realiza.

El objetivo es entender cómo crece el tiempo de ejecución a medida que crece el tamaño de la entrada. Para expresar esta relación, se utiliza la **notación Big O (Gran O)**:

- **$O(1)$ (Constante)**: El tiempo de ejecución no depende del tamaño de la entrada.
- **$O(\log n)$ (Logarítmica)**: El tiempo aumenta muy lentamente. Común en algoritmos que dividen el problema en partes más pequeñas, como la búsqueda binaria.
- **$O(n)$ (Lineal)**: El tiempo de ejecución es directamente proporcional al tamaño de la entrada.
- **$O(n \log n)$ (Linealítmica)**: Combinación de lineal y logarítmica. Es el límite teórico óptimo para algoritmos de ordenamiento basados en comparación.
- **$O(n^2)$ (Cuadrática)**: El tiempo de ejecución crece con el cuadrado del tamaño de la entrada. Es típico de algoritmos que usan lazos anidados, como el ordenamiento de burbuja.

### Complejidad Espacial (Memoria)

La **complejidad espacial** mide la cantidad total de memoria o espacio de almacenamiento que un algoritmo necesita para ejecutarse, también en función del tamaño de la entrada **$n$**. Este análisis incluye tanto el espacio ocupado por los datos de entrada como cualquier memoria adicional (espacio auxiliar) que el algoritmo utilice.

- **Espacio de Entrada**: La memoria necesaria para almacenar los datos iniciales.
- **Espacio Auxiliar**: La memoria extra que el algoritmo crea, como variables temporales o nuevas estructuras de datos.

La complejidad espacial también se expresa con la notación Big O. Un algoritmo que modifica la entrada sin requerir memoria adicional significativa se denomina **"in-place"** y tiene una complejidad espacial auxiliar de **$O(1)$**.

## Algoritmos de Búsqueda

Mientras que los algoritmos de ordenamiento reorganizan una colección de datos, los **algoritmos de búsqueda** están diseñados para encontrar uno o más elementos específicos dentro de una estructura de datos. La eficiencia de un algoritmo de búsqueda a menudo depende de si la estructura de datos subyacente está ordenada.

### Búsqueda Lineal (Linear Search)

Es el método de búsqueda más simple. Consiste en recorrer una colección de datos (por ejemplo, un arreglo) elemento por elemento desde el principio hasta el final, comparando cada uno con el valor buscado. La búsqueda termina cuando se encuentra el elemento o cuando se ha recorrido toda la colección sin éxito.

**Análisis de Complejidad:**
- **Complejidad Temporal**: $O(n)$ en el peor caso y caso promedio. El mejor caso es $O(1)$ cuando el elemento buscado es el primero del arreglo.
- **Complejidad Espacial**: $O(1)$.

**Pseudocódigo:**

```
procedimiento linearSearch(arreglo A, tamaño n, valorBuscado x)
  para i desde 0 hasta n-1
    si A[i] es igual a x
      retornar i
    fin si
  fin para
  retornar -1
fin procedimiento
```

### Búsqueda Binaria (Binary Search)

Es un algoritmo de búsqueda mucho más eficiente, pero con un requisito fundamental: **la colección de datos debe estar previamente ordenada**. Funciona bajo el principio de "Divide y Vencerás".

El algoritmo compara el elemento buscado con el elemento central del arreglo. Si coinciden, la búsqueda termina. Si el elemento buscado es menor que el central, la búsqueda continúa en la mitad inferior del arreglo. Si es mayor, continúa en la mitad superior. Este proceso se repite, descartando la mitad del espacio de búsqueda en cada iteración.

:::{tip} Paradigma Divide y Vencerás
La búsqueda binaria es un ejemplo clásico del paradigma de divide y conquista, que se analiza en profundidad en el [capítulo sobre Recursividad y Divide y Vencerás](15_recursividad.md). Este paradigma es fundamental para entender muchos de los algoritmos de ordenamiento presentados en este documento.
:::

**Análisis de Complejidad:**
- **Complejidad Temporal**: $O(\log n)$. El espacio de búsqueda se reduce a la mitad en cada paso.
- **Complejidad Espacial**: $O(1)$ para la implementación iterativa. $O(\log n)$ para la recursiva (debido a la pila de llamadas).

**Pseudocódigo (Iterativo):**

```
procedimiento binarySearch(arreglo A, tamaño n, valorBuscado x)
  bajo = 0
  alto = n - 1
  mientras bajo <= alto
    medio = bajo + (alto - bajo) / 2
    si A[medio] == x
      retornar medio
    si A[medio] < x
      bajo = medio + 1
    sino
      alto = medio - 1
  fin mientras
  retornar -1
fin procedimiento
```

## Decálogo de Algoritmos de Ordenamiento

### Clasificación Principal

Los algoritmos de ordenamiento se pueden clasificar en dos grandes categorías:

1. **Algoritmos basados en comparación**: Determinan el orden de los elementos comparándolos entre sí.
2. **Algoritmos no basados en comparación**: Utilizan propiedades específicas de los datos (como ser enteros en un rango limitado) para ordenarlos sin comparaciones directas.

---

## I. Ordenamiento de Burbuja (Bubble Sort)

### Concepto y Funcionamiento

El ordenamiento de burbuja es uno de los algoritmos de ordenamiento más simples conceptualmente. Su mecanismo consiste en revisar repetidamente el arreglo, comparando cada par de elementos adyacentes y permutándolos si no están en el orden correcto. El nombre proviene de la forma en que los elementos más grandes "burbujean" hacia el final del arreglo en cada pasada.

En cada iteración completa del arreglo, el elemento más grande de la porción no ordenada se mueve a su posición final. Esto significa que después de $k$ pasadas, los últimos $k$ elementos ya están en su posición correcta.

### Análisis de Complejidad

- **Complejidad Temporal**:
  - Peor Caso: $O(n^2)$ cuando el arreglo está en orden inverso.
  - Caso Promedio: $O(n^2)$.
  - Mejor Caso: $O(n)$ con optimización (cuando el arreglo ya está ordenado y se detecta).
- **Complejidad Espacial**: $O(1)$. Es un algoritmo "in-place", no requiere espacio adicional.

### Características

- **Estable**: Mantiene el orden relativo de elementos iguales.
- **In-place**: No requiere memoria auxiliar significativa.
- **Simplicidad**: Muy fácil de implementar y entender.
- **Ineficiencia**: No es práctico para conjuntos de datos grandes debido a su complejidad cuadrática.

### Pseudocódigo

```
procedimiento bubbleSort(arreglo A, tamaño n)
  para i desde 0 hasta n-2
    para j desde 0 hasta n-i-2
      si A[j] > A[j+1]
        intercambiar(A[j], A[j+1])
      fin si
    fin para
  fin para
fin procedimiento
```

:::{tip} Optimización
Se puede optimizar agregando una bandera que detecte si no hubo intercambios en una pasada completa, lo que indicaría que el arreglo ya está ordenado y se puede terminar anticipadamente.
:::

---

## II. Ordenamiento por Selección (Selection Sort)

### Concepto y Funcionamiento

El ordenamiento por selección divide conceptualmente el arreglo en dos partes: una sublista ordenada (inicialmente vacía) y una sublista desordenada (que contiene todos los elementos). En cada iteración, el algoritmo encuentra el elemento de menor valor en la sublista desordenada y lo intercambia con el primer elemento de esa misma sublista, expandiendo así la porción ordenada.

El proceso se repite hasta que toda la sublista desordenada se ha agotado y todos los elementos están en la sublista ordenada. A diferencia del ordenamiento de burbuja, este algoritmo realiza un número mínimo de intercambios (exactamente $n-1$ intercambios).

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n^2)$ en todos los casos (peor, promedio y mejor). Siempre realiza el mismo número de comparaciones.
- **Complejidad Espacial**: $O(1)$. Es "in-place".

### Características

- **No estable**: Puede alterar el orden relativo de elementos iguales en su forma básica.
- **In-place**: No requiere memoria adicional.
- **Número mínimo de intercambios**: Realiza exactamente $n-1$ intercambios, lo que puede ser ventajoso cuando el costo de escribir en memoria es muy alto.
- **Rendimiento predecible**: Siempre realiza el mismo número de comparaciones, independientemente del orden inicial de los datos.

### Pseudocódigo

```
procedimiento selectionSort(arreglo A, tamaño n)
  para i desde 0 hasta n-2
    indiceMin = i
    para j desde i+1 hasta n-1
      si A[j] < A[indiceMin]
        indiceMin = j
      fin si
    fin para
    si indiceMin != i
      intercambiar(A[i], A[indiceMin])
    fin si
  fin para
fin procedimiento
```

---

## III. Ordenamiento por Inserción (Insertion Sort)

### Concepto y Funcionamiento

El ordenamiento por inserción funciona de manera similar a como una persona ordena una mano de cartas. Los elementos de la parte no ordenada se toman uno por uno y se colocan en su posición correcta dentro de la parte ordenada. El algoritmo mantiene una sublista ordenada en la parte inferior del arreglo y va insertando los elementos restantes uno a uno en su posición correcta.

Para cada elemento, se compara con los elementos de la sublista ordenada (de derecha a izquierda) y se desplazan los elementos mayores una posición hacia la derecha hasta encontrar la posición correcta para el nuevo elemento.

### Análisis de Complejidad

- **Complejidad Temporal**:
  - Peor Caso: $O(n^2)$ cuando el arreglo está en orden inverso.
  - Caso Promedio: $O(n^2)$.
  - Mejor Caso: $O(n)$ cuando el arreglo ya está ordenado.
- **Complejidad Espacial**: $O(1)$. Es "in-place".

### Características

- **Estable**: Mantiene el orden relativo de elementos iguales.
- **In-place**: No requiere memoria adicional.
- **Eficiente para arreglos pequeños**: Es uno de los algoritmos más rápidos para conjuntos de datos pequeños o casi ordenados.
- **Adaptativo**: Su rendimiento mejora significativamente si el arreglo ya está parcialmente ordenado.
- **Online**: Puede ordenar un arreglo a medida que recibe los elementos.

### Pseudocódigo

```
procedimiento insertionSort(arreglo A, tamaño n)
  para i desde 1 hasta n-1
    clave = A[i]
    j = i - 1
    mientras j >= 0 y A[j] > clave
      A[j + 1] = A[j]
      j = j - 1
    fin mientras
    A[j + 1] = clave
  fin para
fin procedimiento
```

:::{note} Aplicación práctica
El ordenamiento por inserción es frecuentemente utilizado como subrutina en algoritmos de ordenamiento más complejos, como Timsort, debido a su eficiencia en arreglos pequeños o parcialmente ordenados.
:::

---

## IV. Ordenamiento por Fusión (Merge Sort)

### Concepto y Funcionamiento

El ordenamiento por fusión es un algoritmo de tipo **"Divide y Vencerás"**. Divide el arreglo en dos mitades, se llama a sí mismo para ordenar las dos mitades de forma recursiva y, finalmente, fusiona (merge) las dos mitades ordenadas en un único arreglo ordenado.

:::{seealso} Paradigma Divide y Vencerás
Merge Sort es el ejemplo canónico del paradigma de divide y conquista. Para entender en profundidad cómo funcionan estos algoritmos y su análisis mediante relaciones de recurrencia, consultá el [capítulo sobre Recursividad y Divide y Vencerás](15_recursividad.md), donde se presenta este algoritmo con implementación completa en C.
:::

El proceso de fusión es clave: toma dos subarreglos ordenados y los combina en un solo arreglo ordenado, comparando los elementos menores de cada subarreglo y colocándolos en orden en un arreglo auxiliar.

La recursión continúa hasta que los subarreglos tienen un solo elemento (que por definición ya está ordenado). Luego, la fase de combinación reconstruye el arreglo ordenado desde estos elementos individuales.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n \log n)$ en todos los casos (peor, promedio y mejor). Es uno de los algoritmos de ordenamiento más eficientes y predecibles.
- **Complejidad Espacial**: $O(n)$. Requiere espacio adicional para almacenar los subarreglos temporales durante la fusión.

:::{note} Resolución de recurrencias
La complejidad $O(n \log n)$ de Merge Sort se obtiene resolviendo la relación de recurrencia $T(n) = 2T(n/2) + O(n)$. Esta recurrencia puede resolverse usando el Teorema Maestro o el método del árbol de recursión, técnicas explicadas en detalle en el [capítulo sobre Análisis de Complejidad](14_complejidad.md#teorema-maestro).
:::

### Características

- **Estable**: Mantiene el orden relativo de elementos iguales.
- **No in-place**: Requiere memoria auxiliar proporcional al tamaño del arreglo.
- **Rendimiento predecible**: Siempre tiene complejidad $O(n \log n)$, independientemente del orden inicial de los datos.
- **Divide y Vencerás**: Excelente ejemplo de este paradigma algorítmico.
- **Paralelizable**: Las dos mitades pueden ordenarse en paralelo.

### Pseudocódigo

```
procedimiento mergeSort(arreglo A, izquierda, derecha)
  si izquierda < derecha
    medio = izquierda + (derecha - izquierda) / 2
    mergeSort(A, izquierda, medio)
    mergeSort(A, medio + 1, derecha)
    merge(A, izquierda, medio, derecha)
  fin si
fin procedimiento

procedimiento merge(arreglo A, izq, med, der)
  n1 = med - izq + 1
  n2 = der - med
  crear arreglos temporales L[n1] y R[n2]
  
  copiar A[izq..med] en L[]
  copiar A[med+1..der] en R[]
  
  i = 0, j = 0, k = izq
  mientras i < n1 y j < n2
    si L[i] <= R[j]
      A[k] = L[i]
      i++
    sino
      A[k] = R[j]
      j++
    fin si
    k++
  fin mientras
  
  copiar elementos restantes de L[] si los hay
  copiar elementos restantes de R[] si los hay
fin procedimiento
```

---

## V. Ordenamiento Rápido (Quick Sort)

### Concepto y Funcionamiento

El ordenamiento rápido también aplica el paradigma **"Divide y Vencerás"**, pero de una manera diferente a Merge Sort. Selecciona un elemento llamado **pivote** y particiona los demás elementos en dos subarreglos: aquellos menores o iguales que el pivote y aquellos mayores. Luego, ordena los subarreglos de forma recursiva.

:::{important} Recursividad y casos base
Al igual que Merge Sort, Quick Sort es fundamentalmente recursivo. Cada llamada recursiva trabaja sobre un subarreglo más pequeño hasta alcanzar el caso base (subarreglos de tamaño 0 o 1). La correcta identificación de casos base es crucial para evitar desbordamientos de pila. Para profundizar en el diseño de algoritmos recursivos, consultá el [capítulo sobre Recursividad](15_recursividad.md).
:::

La clave del algoritmo está en la función de partición, que reorganiza el arreglo de tal manera que el pivote quede en su posición final correcta, con todos los elementos menores a su izquierda y todos los mayores a su derecha.

La elección del pivote puede hacerse de varias formas: primer elemento, último elemento, elemento del medio, elemento aleatorio o mediante la "mediana de tres" (que toma la mediana del primer, medio y último elemento).

### Análisis de Complejidad

- **Complejidad Temporal**:
  - Peor Caso: $O(n^2)$ cuando el pivote elegido es siempre el elemento más pequeño o más grande (por ejemplo, en un arreglo ya ordenado con pivote al inicio).
  - Caso Promedio: $O(n \log n)$ con una buena elección del pivote.
  - Mejor Caso: $O(n \log n)$ cuando el pivote divide el arreglo en dos partes aproximadamente iguales.
- **Complejidad Espacial**: $O(\log n)$ debido a la pila de recursión en el caso promedio. $O(n)$ en el peor caso.

:::{note} Análisis de casos
La diferencia entre el mejor caso $O(n \log n)$ y el peor caso $O(n^2)$ ilustra la importancia del análisis asintótico completo. El [capítulo sobre Complejidad](14_complejidad.md) explica en detalle las notaciones Big-O, Omega y Theta para caracterizar estos comportamientos, así como el análisis amortizado para entender el comportamiento promedio.
:::

### Características

- **No estable**: Puede alterar el orden relativo de elementos iguales en su forma básica.
- **In-place**: Requiere solo un pequeño espacio auxiliar (para la pila de recursión).
- **Muy eficiente en la práctica**: A pesar de su peor caso cuadrático, es típicamente más rápido que Merge Sort y Heap Sort en la práctica debido a su eficiencia de caché y constantes pequeñas.
- **Elección del pivote crucial**: El rendimiento depende fuertemente de la estrategia de selección del pivote.

### Pseudocódigo

```
procedimiento quickSort(arreglo A, bajo, alto)
  si bajo < alto
    pi = partition(A, bajo, alto)
    quickSort(A, bajo, pi - 1)
    quickSort(A, pi + 1, alto)
  fin si
fin procedimiento

procedimiento partition(arreglo A, bajo, alto)
  pivote = A[alto]
  i = bajo - 1
  para j desde bajo hasta alto - 1
    si A[j] <= pivote
      i++
      intercambiar(A[i], A[j])
    fin si
  fin para
  intercambiar(A[i + 1], A[alto])
  retornar i + 1
fin procedimiento
```

:::{important} Optimizaciones
Para evitar el peor caso de $O(n^2)$, se recomienda usar estrategias como la selección aleatoria del pivote o la "mediana de tres". También es común usar Insertion Sort para subarreglos pequeños (típicamente menores a 10 elementos).
:::

---

## VI. Ordenamiento por Montículos (Heap Sort)

### Concepto y Funcionamiento

El ordenamiento por montículos utiliza una estructura de datos de **montículo binario (binary heap)**. Un montículo es un árbol binario completo donde cada nodo padre satisface una propiedad de orden con respecto a sus hijos: en un montículo máximo (max-heap), cada padre es mayor o igual que sus hijos; en un montículo mínimo (min-heap), cada padre es menor o igual que sus hijos.

El algoritmo funciona en dos fases:

1. **Construcción del montículo**: Convierte el arreglo en un montículo máximo.
2. **Extracción ordenada**: Extrae repetidamente el elemento máximo (la raíz del montículo), lo coloca al final del arreglo, reduce el tamaño del montículo y reordena el montículo restante (operación llamada *heapify*).

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n \log n)$ en todos los casos (peor, promedio y mejor).
- **Complejidad Espacial**: $O(1)$. Es un algoritmo "in-place".

### Características

- **No estable**: No mantiene el orden relativo de elementos iguales.
- **In-place**: No requiere memoria auxiliar significativa.
- **Rendimiento garantizado**: Siempre $O(n \log n)$, sin el peor caso cuadrático de Quick Sort.
- **No adaptativo**: Su rendimiento no mejora si el arreglo ya está parcialmente ordenado.
- **Localidad de caché limitada**: Debido a los saltos en el árbol, tiene menor eficiencia de caché que Quick Sort.

:::{note} Estructura de datos del montículo
El montículo binario (heap) es una estructura de datos completa que se representa eficientemente en un arreglo. La relación entre índices de padres e hijos ($\text{padre}(i) = \lfloor (i-1)/2 \rfloor$, $\text{hijo\_izq}(i) = 2i + 1$, $\text{hijo\_der}(i) = 2i + 2$) permite implementar el heap sin punteros adicionales, logrando complejidad espacial $O(1)$. Esta representación es un ejemplo de cómo la elección de la estructura de datos impacta directamente en la complejidad espacial del algoritmo.
:::

### Pseudocódigo

```
procedimiento heapSort(arreglo A, tamaño n)
  // Construir un montículo máximo
  para i desde n / 2 - 1 hasta 0
    heapify(A, n, i)
  fin para
  
  // Extraer elementos uno por uno del montículo
  para i desde n - 1 hasta 0
    intercambiar(A[0], A[i])
    heapify(A, i, 0)
  fin para
fin procedimiento

procedimiento heapify(arreglo A, tamaño n, índice i)
  masGrande = i
  izquierda = 2 * i + 1
  derecha = 2 * i + 2
  
  si izquierda < n y A[izquierda] > A[masGrande]
    masGrande = izquierda
  fin si
  
  si derecha < n y A[derecha] > A[masGrande]
    masGrande = derecha
  fin si
  
  si masGrande != i
    intercambiar(A[i], A[masGrande])
    heapify(A, n, masGrande)
  fin si
fin procedimiento
```

---

## VII. Ordenamiento Shell (Shell Sort)

### Concepto y Funcionamiento

El ordenamiento Shell es una mejora del ordenamiento por inserción diseñada por Donald Shell en 1959. La idea fundamental es permitir el intercambio de elementos que están lejos uno del otro, superando una de las principales limitaciones del ordenamiento por inserción.

El algoritmo comienza usando un "salto" (*gap*) grande para ordenar elementos distantes y progresivamente reduce el salto. En cada pasada con un salto dado, se realiza efectivamente un ordenamiento por inserción en sublistas donde los elementos están separados por ese salto. La última pasada, con un salto de 1, es un ordenamiento por inserción simple, pero se aplica sobre un arreglo que ya está casi ordenado, por lo que es muy eficiente.

### Análisis de Complejidad

- **Complejidad Temporal**: Depende mucho de la secuencia de saltos elegida:
  - Con secuencia de Shell original ($n/2, n/4, ..., 1$): $O(n^2)$ en el peor caso.
  - Con secuencias optimizadas (Knuth, Sedgewick): puede alcanzar $O(n^{3/2})$ o incluso $O(n \log^2 n)$.
- **Complejidad Espacial**: $O(1)$. Es "in-place".

:::{note} Análisis complejo de secuencias
La complejidad de Shell Sort depende críticamente de la secuencia de saltos utilizada, y su análisis es notablemente más difícil que otros algoritmos de ordenamiento. No existe una fórmula cerrada para todas las secuencias, y algunas conjeturas sobre complejidades óptimas aún no están demostradas. Este es un ejemplo de cómo el análisis de complejidad puede ser un problema abierto en la investigación algorítmica. Para técnicas avanzadas de análisis de recurrencias y cotas superiores, consultá el [capítulo sobre Complejidad](14_complejidad.md).
:::

### Características

- **No estable**: No mantiene el orden relativo de elementos iguales.
- **In-place**: No requiere memoria adicional.
- **Adaptativo**: Su rendimiento mejora con arreglos parcialmente ordenados.
- **Dependiente de la secuencia**: El rendimiento varía significativamente según la secuencia de saltos elegida.
- **Bueno para arreglos medianos**: Es más eficiente que algoritmos simples como Insertion Sort, pero menos que $O(n \log n)$ para grandes conjuntos de datos.

### Pseudocódigo

```
procedimiento shellSort(arreglo A, tamaño n)
  // Secuencia de saltos (ejemplo con Shell original)
  para salto desde n/2 hasta 1 con paso /2
    // Ordenamiento por inserción con saltos
    para i desde salto hasta n-1
      temp = A[i]
      j = i
      mientras j >= salto y A[j - salto] > temp
        A[j] = A[j - salto]
        j = j - salto
      fin mientras
      A[j] = temp
    fin para
  fin para
fin procedimiento
```

:::{note} Secuencias de saltos
Las secuencias de saltos más populares incluyen:
- Shell: $n/2, n/4, ..., 1$
- Knuth: $(3^k - 1)/2$, por ejemplo $1, 4, 13, 40, 121, ...$
- Sedgewick: $4^k + 3 \cdot 2^{k-1} + 1$ o $9 \cdot 4^k - 9 \cdot 2^k + 1$
:::

---

## VIII. Ordenamiento por Cuentas (Counting Sort)

### Concepto y Funcionamiento

El ordenamiento por cuentas es el primero de los algoritmos **no basados en comparación** que presentamos. Funciona contando el número de ocurrencias de cada elemento distinto en el arreglo de entrada. Esta información se usa para calcular las posiciones de cada elemento en el arreglo de salida y colocarlos directamente.

El algoritmo requiere conocer de antemano el rango de valores posibles de los elementos (desde un mínimo hasta un máximo). Crea un arreglo auxiliar de "cuentas" donde cada índice representa un posible valor y el contenido es cuántas veces aparece ese valor.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n + k)$, donde $n$ es el número de elementos y $k$ es el rango de los valores de entrada (diferencia entre el máximo y el mínimo).
- **Complejidad Espacial**: $O(k)$ para el arreglo de cuentas, más $O(n)$ para el arreglo de salida.

### Características

- **Estable**: Puede mantener el orden relativo de elementos iguales si se implementa correctamente.
- **No basado en comparación**: No compara elementos entre sí.
- **Muy eficiente cuando $k = O(n)$**: Es lineal si el rango de valores es comparable al número de elementos.
- **Limitado por el rango**: No es práctico cuando el rango de valores es mucho mayor que el número de elementos.
- **Solo para enteros o valores discretos**: No funciona directamente con números de punto flotante u otros tipos arbitrarios.

### Pseudocódigo

```
procedimiento countingSort(arreglo A, tamaño n, valorMin, valorMax)
  k = valorMax - valorMin + 1
  crear arreglo de cuentas C de tamaño k, inicializado a 0
  crear arreglo de salida B de tamaño n
  
  // Contar ocurrencias de cada valor
  para j desde 0 hasta n-1
    indice = A[j] - valorMin
    C[indice] = C[indice] + 1
  fin para
  
  // Calcular posiciones acumuladas
  para i desde 1 hasta k-1
    C[i] = C[i] + C[i-1]
  fin para
  
  // Construir el arreglo de salida (de derecha a izquierda para estabilidad)
  para j desde n-1 hasta 0
    indice = A[j] - valorMin
    B[C[indice] - 1] = A[j]
    C[indice] = C[indice] - 1
  fin para
  
  // Copiar el resultado de vuelta a A
  copiar B en A
fin procedimiento
```

:::{important} Aplicación práctica
Counting Sort es frecuentemente utilizado como subrutina en Radix Sort y es ideal cuando se necesita ordenar enteros en un rango conocido y limitado.
:::

---

## IX. Ordenamiento Radix (Radix Sort)

### Concepto y Funcionamiento

El ordenamiento Radix es otro algoritmo **no basado en comparación** que ordena enteros procesando sus dígitos individuales. Puede procesar los dígitos desde el menos significativo (LSD - Least Significant Digit) hasta el más significativo (MSD - Most Significant Digit), o viceversa.

La versión LSD comienza desde el dígito menos significativo (el de las unidades) y procede hacia los dígitos más significativos. En cada pasada, utiliza un algoritmo de ordenamiento estable (típicamente Counting Sort) para ordenar la lista de números según el dígito actual.

La clave es que el algoritmo de ordenamiento utilizado en cada pasada debe ser estable, de modo que el orden establecido por los dígitos menos significativos se preserve cuando se ordenan los dígitos más significativos.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(d \cdot (n + b))$, donde $d$ es el número de dígitos en el número más grande, $n$ es el número de elementos y $b$ es la base numérica (usualmente 10 para decimales).
- **Complejidad Espacial**: $O(n + b)$ si se usa Counting Sort como subrutina.

:::{tip} Superando el límite $O(n \log n)$
Radix Sort es un ejemplo de algoritmo que supera el límite teórico $\Omega(n \log n)$ de los algoritmos de ordenamiento basados en comparación. Esto es posible porque no compara elementos directamente, sino que explota la estructura de los datos (representación por dígitos). Cuando $d$ es constante (números con un número fijo de dígitos), la complejidad se reduce a $O(n)$, logrando ordenamiento lineal. Este concepto de explotar propiedades específicas del dominio del problema se analiza en el contexto de límites inferiores en el [capítulo sobre Complejidad](14_complejidad.md).
:::

### Características

- **Estable**: Mantiene el orden relativo de elementos iguales (si el algoritmo de ordenamiento por dígito es estable).
- **No basado en comparación**: No compara elementos entre sí.
- **Eficiente para números con pocos dígitos**: Cuando $d$ es pequeño y constante, la complejidad se aproxima a $O(n)$.
- **Versátil**: Puede adaptarse para ordenar strings y otros tipos de datos con representación por dígitos/caracteres.
- **Dependiente de la base**: El rendimiento puede optimizarse eligiendo una base apropiada (no necesariamente 10).

### Pseudocódigo

```
procedimiento radixSort(arreglo A, tamaño n)
  // Encontrar el número máximo para saber el número de dígitos
  maximo = encontrarMaximo(A, n)
  
  // Hacer counting sort para cada dígito
  // exp es 10^i donde i es el número del dígito actual
  exp = 1
  mientras maximo / exp > 0
    countingSortPorDigito(A, n, exp)
    exp = exp * 10
  fin mientras
fin procedimiento

procedimiento countingSortPorDigito(arreglo A, tamaño n, exp)
  crear arreglo de salida B de tamaño n
  crear arreglo de cuentas C de tamaño 10, inicializado a 0
  
  // Contar ocurrencias de cada dígito
  para i desde 0 hasta n-1
    digito = (A[i] / exp) % 10
    C[digito] = C[digito] + 1
  fin para
  
  // Calcular posiciones acumuladas
  para i desde 1 hasta 9
    C[i] = C[i] + C[i-1]
  fin para
  
  // Construir el arreglo de salida
  para i desde n-1 hasta 0
    digito = (A[i] / exp) % 10
    B[C[digito] - 1] = A[i]
    C[digito] = C[digito] - 1
  fin para
  
  // Copiar el resultado de vuelta a A
  copiar B en A
fin procedimiento
```

---

## X. Ordenamiento por Cubetas (Bucket Sort)

### Concepto y Funcionamiento

El ordenamiento por cubetas (también llamado Bin Sort) es otro algoritmo **no basado en comparación** que distribuye los elementos en un número de "cubetas" o "contenedores" y luego ordena cada cubeta individualmente, ya sea usando otro algoritmo de ordenamiento o aplicando recursivamente el ordenamiento por cubetas.

El algoritmo funciona mejor cuando los elementos se distribuyen uniformemente en un rango conocido. Los pasos básicos son:

1. **Distribución**: Crear un arreglo de cubetas vacías y distribuir los elementos del arreglo original en las cubetas según su valor.
2. **Ordenamiento individual**: Ordenar cada cubeta individualmente (usando Insertion Sort, Quick Sort u otro algoritmo apropiado).
3. **Concatenación**: Recorrer las cubetas en orden y concatenar los elementos para formar el arreglo ordenado.

### Análisis de Complejidad

- **Complejidad Temporal**:
  - Caso Promedio: $O(n + k)$ cuando los elementos se distribuyen uniformemente, donde $k$ es el número de cubetas.
  - Peor Caso: $O(n^2)$ cuando todos los elementos caen en la misma cubeta y se usa un algoritmo $O(n^2)$ para ordenarla.
- **Complejidad Espacial**: $O(n + k)$ para almacenar las cubetas.

### Características

- **Estabilidad variable**: Puede ser estable si se implementa con cuidado y se usa un algoritmo de ordenamiento estable para las cubetas.
- **Distribución de datos importante**: El rendimiento depende fuertemente de qué tan uniformemente se distribuyen los elementos en las cubetas.
- **Versátil**: Puede adaptarse a diferentes tipos de datos y rangos.
- **Eficiente con distribución uniforme**: Puede alcanzar complejidad lineal $O(n)$ en condiciones ideales.
- **Paralelizable**: Las cubetas pueden ordenarse independientemente en paralelo.

### Pseudocódigo

```
procedimiento bucketSort(arreglo A, tamaño n)
  // Determinar el rango de valores
  min = encontrarMinimo(A, n)
  max = encontrarMaximo(A, n)
  rango = max - min + 1
  
  // Crear cubetas vacías
  numeroCubetas = n
  crear arreglo de cubetas B de tamaño numeroCubetas
  
  // Distribuir elementos en cubetas
  para i desde 0 hasta n-1
    indiceCubeta = ((A[i] - min) * numeroCubetas) / rango
    si indiceCubeta >= numeroCubetas
      indiceCubeta = numeroCubetas - 1
    fin si
    agregar A[i] a B[indiceCubeta]
  fin para
  
  // Ordenar cada cubeta individualmente
  para i desde 0 hasta numeroCubetas-1
    ordenar B[i] usando insertionSort o quickSort
  fin para
  
  // Concatenar todas las cubetas en A
  indice = 0
  para i desde 0 hasta numeroCubetas-1
    para cada elemento e en B[i]
      A[indice] = e
      indice++
    fin para
  fin para
fin procedimiento
```

:::{note} Aplicaciones
Bucket Sort es especialmente útil cuando se trabaja con números de punto flotante uniformemente distribuidos en un rango, o cuando se necesita ordenar datos que naturalmente se agrupan en categorías.
:::

---

## Comparación de Algoritmos de Ordenamiento

La siguiente tabla resume las características principales de los diez algoritmos presentados:

```{list-table}
:header-rows: 1

* - Algoritmo
  - Mejor Caso
  - Caso Promedio
  - Peor Caso
  - Espacio
  - Estable
* - Bubble Sort
  - $O(n)$
  - $O(n^2)$
  - $O(n^2)$
  - $O(1)$
  - Sí
* - Selection Sort
  - $O(n^2)$
  - $O(n^2)$
  - $O(n^2)$
  - $O(1)$
  - No
* - Insertion Sort
  - $O(n)$
  - $O(n^2)$
  - $O(n^2)$
  - $O(1)$
  - Sí
* - Merge Sort
  - $O(n \log n)$
  - $O(n \log n)$
  - $O(n \log n)$
  - $O(n)$
  - Sí
* - Quick Sort
  - $O(n \log n)$
  - $O(n \log n)$
  - $O(n^2)$
  - $O(\log n)$
  - No
* - Heap Sort
  - $O(n \log n)$
  - $O(n \log n)$
  - $O(n \log n)$
  - $O(1)$
  - No
* - Shell Sort
  - $O(n \log n)$
  - $O(n^{4/3})$
  - $O(n^2)$
  - $O(1)$
  - No
* - Counting Sort
  - $O(n + k)$
  - $O(n + k)$
  - $O(n + k)$
  - $O(k)$
  - Sí
* - Radix Sort
  - $O(d(n + b))$
  - $O(d(n + b))$
  - $O(d(n + b))$
  - $O(n + b)$
  - Sí
* - Bucket Sort
  - $O(n + k)$
  - $O(n + k)$
  - $O(n^2)$
  - $O(n + k)$
  - Varía
```

:::{important} Límites teóricos del ordenamiento
Es importante notar que ningún algoritmo de ordenamiento basado en comparación puede tener una complejidad temporal mejor que $\Omega(n \log n)$ en el caso promedio. Este límite inferior teórico se demuestra mediante argumentos de teoría de la información. Los algoritmos no basados en comparación (Counting, Radix, Bucket) pueden superar este límite porque explotan propiedades específicas de los datos. Para la demostración formal de este límite y otros resultados sobre límites inferiores, consultá el [capítulo sobre Complejidad](14_complejidad.md).
:::

## Guía de Selección de Algoritmo

La elección del algoritmo de ordenamiento apropiado depende de varios factores:

**Para conjuntos de datos pequeños (n < 50):**
- **Insertion Sort** es típicamente la mejor opción debido a su simplicidad y eficiencia en arreglos pequeños.

**Para conjuntos de datos medianos (50 < n < 10000):**
- **Quick Sort** con buena selección de pivote suele ser el más rápido.
- **Shell Sort** es una buena alternativa si se necesita un algoritmo in-place sin el peor caso cuadrático de Quick Sort.

**Para conjuntos de datos grandes (n > 10000):**
- **Quick Sort** es típicamente el más rápido en la práctica.
- **Merge Sort** si se necesita estabilidad o rendimiento garantizado $O(n \log n)$.
- **Heap Sort** si se necesita $O(n \log n)$ garantizado y memoria limitada.

**Para casos especiales:**
- **Counting Sort** cuando los elementos son enteros en un rango limitado conocido.
- **Radix Sort** para ordenar enteros o strings con representación por dígitos.
- **Bucket Sort** cuando los datos se distribuyen uniformemente en un rango.
- **Insertion Sort** cuando el arreglo ya está casi ordenado.

**Consideraciones adicionales:**
- Si se requiere **estabilidad**: Merge Sort, Insertion Sort, Bubble Sort, Counting Sort, Radix Sort.
- Si se requiere **in-place** (memoria mínima): Quick Sort, Heap Sort, Shell Sort, Insertion Sort, Selection Sort.
- Si se requiere **rendimiento garantizado** sin peor caso cuadrático: Merge Sort o Heap Sort.
- Si el rendimiento promedio es crítico y el espacio no es limitante: Quick Sort.

:::{important} Algoritmos híbridos
En la práctica, muchas bibliotecas estándar utilizan algoritmos híbridos que combinan las fortalezas de varios algoritmos. Por ejemplo, **Timsort** (usado en Python y Java) combina Merge Sort e Insertion Sort, mientras que **Introsort** (usado en C++) combina Quick Sort, Heap Sort e Insertion Sort. Estos algoritmos aprovechan las características de cada método según el tamaño del subarreglo y el estado de ordenamiento parcial de los datos, optimizando así el rendimiento en la práctica.
:::

## Referencias y Profundización

Este capítulo ha presentado una visión panorámica de los algoritmos de ordenamiento. Para profundizar en los fundamentos teóricos que sustentan estos algoritmos, se recomienda consultar:

- **[Análisis de Complejidad Algorítmica](14_complejidad.md)**: Para entender en detalle el análisis asintótico, notaciones Big-O, Omega y Theta, el Teorema Maestro para resolver recurrencias, límites inferiores teóricos y técnicas avanzadas de análisis.

- **[Recursividad y Divide y Vencerás](15_recursividad.md)**: Para comprender el paradigma de divide y conquista que fundamenta algoritmos como Merge Sort, Quick Sort y Binary Search, con ejemplos de implementación completos en C y análisis detallado de la pila de llamadas recursivas.
