---
title: "Ordenamiento"
short_title: "7 - Algoritmos I"
subtitle: "Ordenando y comparando métodos"
---

# Métodos de Ordenamiento

Un **algoritmo de ordenamiento** es un procedimiento computacional que toma un
conjunto de datos de entrada (como un arreglo) y produce una permutación de esos
datos que los organiza según una relación de orden específica (generalmente,
ascendente o descendente). El ordenamiento es una de las operaciones más
fundamentales en la informática, crucial para optimizar la eficiencia de otros
algoritmos, como los de búsqueda.

Para evaluar la eficiencia de estos algoritmos, se utilizan dos métricas clave:
la complejidad temporal y la complejidad espacial.

# Conceptos Fundamentales de Complejidad

Al analizar un algoritmo, no solo nos interesa que funcione, sino cuán
eficientemente lo hace. La complejidad algorítmica es el estudio formal de los
recursos que un algoritmo consume.

Lo interesante de esta técnica de análisis, es la separación concreta con el
hardware que lleva a cabo la tarea y el algoritmo en sí.

## Complejidad Temporal

La **complejidad temporal** es una medida de cuánto tiempo tarda un algoritmo en
ejecutarse en función del tamaño de su entrada, denotado comúnmente como
**$n$**. No se mide en segundos o milisegundos, ya que eso depende del hardware.
En su lugar, se cuantifica el número de operaciones elementales (comparaciones,
asignaciones, operaciones aritméticas) que el algoritmo realiza.

El objetivo es entender cómo crece el tiempo de ejecución a medida que crece el
tamaño de la entrada. Para expresar esta relación, se utiliza la **notación Big
O (Gran O)**.

- **$O(1)$ (Constante)**: El tiempo de ejecución no depende del tamaño de la
  entrada.
- **$O(\log n)$ (Logarítmica)**: El tiempo aumenta muy lentamente. Común en
  algoritmos que dividen el problema en partes más pequeñas, como la búsqueda
  binaria.
- **$O(n)$ (Lineal)**: El tiempo de ejecución es directamente proporcional al
  tamaño de la entrada.
- **$O(n^2)$ (Cuadrática)**: El tiempo de ejecución crece exponencialmente con
  el cuadrado del tamaño de la entrada. Es típico de algoritmos que usan bucles
  anidados, como el ordenamiento de burbuja.

## Complejidad Espacial (Memoria)

La **complejidad espacial** mide la cantidad total de memoria o espacio de
almacenamiento que un algoritmo necesita para ejecutarse, también en función del
tamaño de la entrada **$n$**. Este análisis incluye tanto el espacio ocupado por
los datos de entrada como cualquier memoria adicional (espacio auxiliar) que el
algoritmo utilice.

- **Espacio de Entrada**: La memoria necesaria para almacenar los datos
  iniciales.
- **Espacio Auxiliar**: La memoria extra que el algoritmo crea, como variables
  temporales o nuevas estructuras de datos.

La complejidad espacial también se expresa con la notación Big O. Un algoritmo
que modifica la entrada sin requerir memoria adicional significativa se denomina
**"in-place"** y tiene una complejidad espacial auxiliar de **$O(1)$**.

# Algoritmos de Búsqueda

Mientras que los algoritmos de ordenamiento reorganizan una colección de datos,
los **algoritmos de búsqueda** están diseñados para encontrar uno o más
elementos específicos dentro de una estructura de datos. La eficiencia de un
algoritmo de búsqueda a menudo depende de si la estructura de datos subyacente
está ordenada.

## Búsqueda Lineal (Linear Search)

Es el método de búsqueda más simple. Consiste en recorrer una colección de datos
(por ejemplo, un arreglo) elemento por elemento desde el principio hasta el
final, comparando cada uno con el valor buscado. La búsqueda termina cuando se
encuentra el elemento o cuando se ha recorrido toda la colección sin éxito.

### Análisis de Complejidad

- **Complejidad Temporal**:
  - Peor Caso y Caso Promedio: $O(n)$. En el peor caso, el elemento no se
    encuentra o está en la última posición, requiriendo $n$ comparaciones.
  - Mejor Caso: $O(1)$, cuando el elemento buscado es el primero del arreglo.
- **Complejidad Espacial**: $O(1)$.

### Pseudocódigo

```
procedimiento linearSearch(arreglo A, tamaño n, valorBuscado x)
  para i desde 0 hasta n-1
    si A[i] es igual a x
      retornar i // Se encontró el elemento, retornar su índice
    fin si
  fin para
  retornar -1 // El elemento no se encuentra en el arreglo
fin procedimiento
```

## Búsqueda Binaria (Binary Search)

Es un algoritmo de búsqueda mucho más eficiente, pero con un requisito
fundamental: **la colección de datos debe estar previamente ordenada**. Funciona
bajo el principio de "Divide y Vencerás".

1.  Compara el elemento buscado con el elemento central del arreglo.
2.  Si coinciden, la búsqueda termina.
3.  Si el elemento buscado es menor que el central, la búsqueda continúa en la
    mitad inferior del arreglo.
4.  Si es mayor, la búsqueda continúa en la mitad superior.
5.  Este proceso se repite, descartando la mitad del espacio de búsqueda en cada
    iteración.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(\log n)$. Como el espacio de búsqueda se reduce a
  la mitad en cada paso, el número de comparaciones crece logarítmicamente.
- **Complejidad Espacial**: $O(1)$ para la implementación iterativa. $O(\log n)$
  para la recursiva (debido a la pila de llamadas).

### Pseudocódigo (Iterativo)

```
procedimiento binarySearch(arreglo A, valorBuscado x)
  bajo = 0
  alto = tamaño(A) - 1

  mientras bajo <= alto
    medio = bajo + (alto - bajo) / 2

    // Verificar si x está en el medio
    si A[medio] == x
      retornar medio

    // Si x es mayor, ignorar la mitad izquierda
    si A[medio] < x
      bajo = medio + 1
    // Si x es menor, ignorar la mitad derecha
    sino
      alto = medio - 1
  fin mientras

  // Si llegamos aquí, el elemento no estaba presente
  retornar -1
fin procedimiento
```

# Algoritmos de Ordenamiento Basados en Comparación

Estos algoritmos determinan el orden de los elementos comparándolos entre sí.

## Ordenamiento de Burbuja (Bubble Sort)

### Concepto

Su mecanismo consiste en revisar repetidamente el arreglo, comparando cada par
de elementos adyacentes y permutándolos si no están en el orden correcto. Este
proceso se repite hasta que el arreglo está completamente ordenado.

### Implementación en C

```{code} c
:caption: Implementación del Algoritmo de Burbuja en C
:label: bubble-sort-c

#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arreglo[], size_t largo)
{
    for ( i = 0; i < largo-1; i++)
    {
        for (size_tj = 0; j < largo-i-1; j++)
        {
            if (arreglo[j] > arreglo[j+1])
            {
                swap(&arreglo[j], &arreglo[j+1]);
            }
        }
    }
}
```

## Ordenamiento por Selección (Selection Sort)

### Concepto

En cada iteración, encuentra el elemento de menor valor en la sublista
desordenada y lo intercambia con el primer elemento de esa misma sublista,
expandiendo así la porción ordenada.

### Pseudocódigo

```
procedimiento selectionSort(arreglo A, tamaño n)
  para i desde 0 hasta n-2
    indiceMin = i
    para j desde i+1 hasta n-1
      si A[j] < A[indiceMin] entonces indiceMin = j
    intercambiar(A[indiceMin], A[i])
```

## Ordenamiento por Inserción (Insertion Sort)

### Concepto

Funciona de manera similar a como una persona ordena una mano de cartas. Los
elementos de la parte no ordenada se toman uno por uno y se colocan en su
posición correcta dentro de la parte ordenada.

### Pseudocódigo

```
procedimiento insertionSort(arreglo A, tamaño n)
  para i desde 1 hasta n-1
    clave = A[i]
    j = i - 1
    mientras j >= 0 y A[j] > clave
      A[j + 1] = A[j]
      j = j - 1
    A[j + 1] = clave
```

## Ordenamiento por Fusión (Merge Sort)

### Concepto

Es un algoritmo de tipo **"Divide y Vencerás"**. Divide el arreglo en dos
mitades, se llama a sí mismo para ordenar las dos mitades de forma recursiva y,
finalmente, fusiona (merge) las dos mitades ordenadas.

### Pseudocódigo

```
procedimiento mergeSort(arreglo A, izq, der)
  si izq < der
    med = izq + (der - izq) / 2
    mergeSort(A, izq, med)
    mergeSort(A, med + 1, der)
    merge(A, izq, med, der)
```

## Ordenamiento Rápido (Quick Sort)

### Concepto

También de **"Divide y Vencerás"**. Selecciona un elemento como **pivote** y
particiona los demás elementos en dos sub-arreglos según si son menores o
mayores que el pivote. Luego, ordena los sub-arreglos de forma recursiva.

### Pseudocódigo

```
procedimiento quickSort(arreglo A, bajo, alto)
  si bajo < alto
    pi = partition(A, bajo, alto)
    quickSort(A, bajo, pi - 1)
    quickSort(A, pi + 1, alto)
```

## Ordenamiento por Montículos (Heap Sort)

### Concepto

Utiliza una estructura de datos de **montículo binario (binary heap)**. Primero,
convierte el arreglo en un montículo máximo (max-heap), donde cada nodo padre es
mayor o igual que sus hijos. Luego, extrae repetidamente el elemento máximo (la
raíz del montículo), lo coloca al final del arreglo y reordena el montículo.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n \log n)$ en todos los casos.
- **Complejidad Espacial**: $O(1)$. Es un algoritmo "in-place".

### Pseudocódigo

```
procedimiento heapSort(arreglo A, tamaño n)
  // Construir un montículo máximo
  para i desde n / 2 - 1 hasta 0
    heapify(A, n, i)

  // Extraer elementos uno por uno del montículo
  para i desde n - 1 hasta 0
    intercambiar(A[0], A[i])
    // Llamar a heapify en el montículo reducido
    heapify(A, i, 0)
fin procedimiento

procedimiento heapify(arreglo A, tamaño n, índice i)
  // Inicializar el más grande como la raíz
  masGrande = i
  izquierda = 2*i + 1
  derecha = 2*i + 2

  // Si el hijo izquierdo es más grande que la raíz
  si izquierda < n y A[izquierda] > A[masGrande]
    masGrande = izquierda

  // Si el hijo derecho es más grande que el más grande hasta ahora
  si derecha < n y A[derecha] > A[masGrande]
    masGrande = derecha

  // Si el más grande no es la raíz
  si masGrande != i
    intercambiar(A[i], A[masGrande])
    // Recursivamente aplicar heapify al sub-árbol afectado
    heapify(A, n, masGrande)
fin procedimiento
```

## Ordenamiento Shell (Shell Sort)

### Concepto

Es una mejora del ordenamiento por inserción. Permite el intercambio de
elementos que están lejos uno del otro. Comienza usando un "salto" (gap) grande
para ordenar elementos distantes y progresivamente reduce el salto. La última
pasada, con un salto de 1, es un ordenamiento por inserción simple, pero para un
arreglo que ya está casi ordenado.

### Análisis de Complejidad

- **Complejidad Temporal**: Depende mucho de la secuencia de saltos. Puede
  variar desde $O(n^2)$ (peor caso) hasta $O(n \log^2 n)$.
- **Complejidad Espacial**: $O(1)$. Es "in-place".

### Pseudocódigo

```
procedimiento shellSort(arreglo A, tamaño n)
  // Iniciar con un salto grande, luego reducirlo
  para salto desde n/2 hasta 1 con paso /2
    // Hacer un ordenamiento por inserción con saltos para este tamaño de salto.
    para i desde salto hasta n-1
      // Añadir A[i] a los elementos que han sido ordenados por salto
      temp = A[i]
      para j = i; j >= salto y A[j - salto] > temp; j = j - salto
        A[j] = A[j - salto]
      fin para
      A[j] = temp
    fin para
  fin para
fin procedimiento
```

# Algoritmos de Ordenamiento No Basados en Comparación

Estos algoritmos no comparan elementos entre sí. En su lugar, se basan en
propiedades de los datos (como ser enteros en un rango específico) para
ordenarlos de manera más eficiente bajo ciertas condiciones.

## Ordenamiento por Cuentas (Counting Sort)

### Concepto

Funciona contando el número de ocurrencias de cada elemento distinto en el
arreglo de entrada. Esta información se usa para calcular las posiciones de cada
elemento en el arreglo de salida y colocarlos directamente.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(n + k)$, donde $n$ es el número de elementos y
  $k$ es el rango de los valores de entrada.
- **Complejidad Espacial**: $O(k)$ para el arreglo de cuentas.

### Pseudocódigo

```
procedimiento countingSort(arreglo A, tamaño n, rango k)
  crear arreglo de salida B de tamaño n
  crear arreglo de cuentas C de tamaño k+1, inicializado a 0

  // Almacenar la cuenta de cada caracter
  para j desde 0 hasta n-1
    C[A[j]] = C[A[j]] + 1

  // Cambiar C[i] para que ahora contenga la posición final de este caracter
  para i desde 1 hasta k
    C[i] = C[i] + C[i-1]

  // Construir el arreglo de salida
  para j desde n-1 hasta 0
    B[C[A[j]] - 1] = A[j]
    C[A[j]] = C[A[j]] - 1

  retornar B
fin procedimiento
```

## Ordenamiento Radix (Radix Sort)

### Concepto

Ordena enteros procesando sus dígitos individuales. Comienza desde el dígito
menos significativo (LSD) hasta el más significativo (MSD). En cada pasada,
utiliza un algoritmo de ordenamiento estable (como Counting Sort) para ordenar
la lista de números según el dígito actual.

### Análisis de Complejidad

- **Complejidad Temporal**: $O(d \cdot (n + b))$, donde $d$ es el número de
  dígitos en el número más grande, $n$ es el número de elementos y $b$ es la
  base numérica (usualmente 10).
- **Complejidad Espacial**: $O(n + b)$ si se usa Counting Sort como subrutina.

### Pseudocódigo

```
procedimiento radixSort(arreglo A, tamaño n)
  // Encontrar el número máximo para saber el número de dígitos
  maximo = encontrarMaximo(A, n)

  // Hacer counting sort para cada dígito.
  // 'exp' es 10^i donde i es el número del dígito actual
  para exp desde 1 hasta que maximo/exp > 0 con paso *10
    countingSortPorDigito(A, n, exp)
fin procedimiento

// Una función para hacer counting sort de A[] según el dígito representado por exp.
procedimiento countingSortPorDigito(arreglo A, tamaño n, exp)
  // (Aquí iría la lógica de Counting Sort, adaptada para
  // ordenar basado en el dígito (A[i]/exp) % 10)
fin procedimiento
```
