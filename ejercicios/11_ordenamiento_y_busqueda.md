---
title: "Ejercicios: Ordenamiento y Búsqueda"
short_title: "11. Ordenamiento y Búsqueda"
---

## Acerca de

Estos ejercicios se centran en la implementación de algoritmos fundamentales de
búsqueda y ordenamiento. Comprender su funcionamiento interno y sus diferencias
en eficiencia es clave para escribir código performante. Para cada algoritmo de
ordenamiento, se recomienda implementar una función
`void ordenar(int arreglo[], size_t n)` que modifique el arreglo _in-place_.

## 1: Algoritmos de Búsqueda

### 1.1: Búsqueda Lineal

#### Descripción

Implementar una función que busque un elemento en un arreglo recorriéndolo
secuencialmente desde el primer hasta el último elemento. Es el método de
búsqueda más simple y no requiere que el arreglo esté ordenado.

:::{hint} Lógica y Consideraciones

- **Proceso**: Iterar a través del arreglo con un índice `i` desde 0 hasta
  `n-1`. En cada paso, comparar `arreglo[i]` con el valor buscado.
- **Salida**: Si se encuentra el elemento, devolver su índice `i`. Si el bucle
  termina sin encontrarlo, devolver `-1`.
- **Complejidad Temporal**: $O(n)$.

:::

### 1.2: Búsqueda Binaria

#### Descripción

Implementar una función de búsqueda binaria, un algoritmo mucho más eficiente
que requiere que el arreglo esté **previamente ordenado**. Funciona dividiendo
repetidamente el intervalo de búsqueda por la mitad.

:::{hint} Lógica y Consideraciones

- **Proceso**:
  1. Mantener dos índices, `izquierda = 0` y `derecha = n-1`.
  2. Mientras `izquierda <= derecha`, calcular el índice del medio:
     `medio = izquierda + (derecha - izquierda) / 2`.
  3. Comparar el valor buscado con `arreglo[medio]`. Si son iguales, se
     encontró. Si es menor, ajustar `derecha = medio - 1`. Si es mayor, ajustar
     `izquierda = medio + 1`.
- **Salida**: Devolver el índice si se encuentra, o `-1` si el intervalo de
  búsqueda se vacía.
- **Complejidad Temporal**: $O(\log n)$.

:::

## 2: Algoritmos de Ordenamiento Cuadráticos ($O(n^2)$)

### 2.1: Ordenamiento de Burbuja (Bubble Sort)

#### Descripción

Implementar el ordenamiento de burbuja. Este método recorre repetidamente la
lista, compara elementos adyacentes y los intercambia si están en el orden
incorrecto. Las pasadas a través de la lista se repiten hasta que no se
necesiten más intercambios.

:::{hint} Lógica y Consideraciones

- **Proceso**: Usar dos bucles anidados. El bucle exterior controla el número de
  pasadas. El bucle interior recorre los elementos, "burbujeando" el elemento
  más grande de la sección no ordenada hacia su posición final en cada pasada.
- **Optimización**: Se puede agregar una bandera para detectar si en una pasada
  completa no se realizó ningún intercambio, en cuyo caso el arreglo ya está
  ordenado y el algoritmo puede terminar antes.

:::

### 2.2: Ordenamiento por Selección (Selection Sort)

#### Descripción

Implementar el ordenamiento por selección. Este algoritmo divide el arreglo en
una parte ordenada y una desordenada. En cada iteración, encuentra el elemento
más pequeño de la parte desordenada y lo intercambia con el primer elemento de
esta, moviendo así el límite entre ambas partes.

:::{hint} Lógica y Consideraciones

- **Proceso**: El bucle exterior itera desde `i = 0` hasta `n-2`. En cada
  iteración, el bucle interior (de `j = i+1` a `n-1`) busca el índice del
  elemento mínimo en el resto del arreglo. Finalmente, se intercambia el
  elemento en `i` con el mínimo encontrado.

:::

### 2.3: Ordenamiento por Inserción (Insertion Sort)

#### Descripción

Implementar el ordenamiento por inserción. Este método construye el arreglo
ordenado final un elemento a la vez. Es muy eficiente para arreglos pequeños o
que ya están casi ordenados.

:::{hint} Lógica y Consideraciones

- **Proceso**: Iterar desde el segundo elemento (`i=1`) hasta el final. En cada
  iteración, tomar el elemento actual (`clave`) y compararlo con los elementos a
  su izquierda. Desplazar los elementos mayores que la `clave` una posición
  hacia la derecha para hacer espacio e insertar la `clave` en su posición
  correcta.

:::

## 3: Algoritmos de Ordenamiento Avanzados ($O(n \log n)$)

### 3.1: Ordenamiento por Fusión (Merge Sort)

#### Descripción

Implementar Merge Sort, un algoritmo eficiente basado en la técnica "Divide y
Vencerás".

:::{hint} Lógica y Consideraciones

- **Proceso**:
  1. **Dividir**: Si el arreglo tiene más de un elemento, dividirlo en dos
     mitades.
  2. **Vencer**: Llamar recursivamente a `merge_sort` para cada mitad.
  3. **Combinar**: Implementar una función `merge` que tome las dos mitades ya
     ordenadas y las fusione en un único arreglo ordenado. Este paso requiere un
     arreglo auxiliar.

:::

### 3.2: Ordenamiento Rápido (Quick Sort)

#### Descripción

Implementar Quick Sort, otro algoritmo "Divide y Vencerás" muy eficiente en la
práctica.

:::{hint} Lógica y Consideraciones

- **Proceso**:
  1. **Elegir Pivote**: Seleccionar un elemento del arreglo como pivote (puede
     ser el último, el primero, uno aleatorio, etc.).
  2. **Particionar**: Reorganizar el arreglo de modo que todos los elementos
     menores que el pivote queden a su izquierda y todos los mayores a su
     derecha. El pivote queda en su posición final ordenada. La función de
     partición devuelve el índice del pivote.
  3. **Vencer**: Llamar recursivamente a `quick_sort` para los sub-arreglos a la
     izquierda y a la derecha del pivote.

:::
