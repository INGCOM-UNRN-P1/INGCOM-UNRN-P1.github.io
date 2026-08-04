---
title: "Ejercicios: Ordenamiento y Búsqueda"
short_title: "5. Ordenamiento y Búsqueda"
---

# Ejercicios de Ordenamiento y Búsqueda

## Acerca de

Estos ejercicios tienen como propósito comprender, implementar y analizar la
complejidad temporal y espacial de los algoritmos clásicos de búsqueda (lineal,
binaria) y ordenamiento (burbuja, selección, inserción, fusión, rápido) en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-secuencias`
- {ref}`capitulo-complejidad`

### Cuestiones de Estilo Aplicables
- **Genericidad y modularidad:** Separar los algoritmos en funciones modulares
  con firmas estandarizadas e implementar funciones auxiliares de intercambio
  (`void intercambia(int *a, int *b)`) reutilizables (ver reglas en
  {ref}`0x2009h`).

---

## Algoritmos de Búsqueda
(ejercicio_30_1)=
### Ejercicio 30.1 - Búsqueda Lineal ⭐⭐☆☆☆

Implementar una función que busque un elemento en un arreglo recorriéndolo
secuencialmente desde el primer hasta el último elemento. Es el método de
búsqueda más simple y no requiere que el arreglo esté ordenado.

**Lógica y Consideraciones:**
- **Proceso**: Iterar a través del arreglo con un índice `i` desde 0 hasta
  `n-1`. En cada paso, comparar `arreglo[i]` con el valor buscado.
- **Salida**: Si se encuentra el elemento, devolver su índice `i`. Si el lazo
  termina sin encontrarlo, devolver `-1`.
- **Complejidad Temporal**: $O(n)$.
(ejercicio_30_2)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 30.2 - Búsqueda Binaria ⭐⭐☆☆☆

Implementar una función de búsqueda binaria, un algoritmo mucho más eficiente
que requiere que el arreglo esté **previamente ordenado**. Funciona dividiendo
repetidamente el intervalo de búsqueda por la mitad.

**Lógica y Consideraciones:**
- **Proceso**:
  1. Mantener dos índices, `izquierda = 0` y `derecha = n-1`.
  2. Mientras `izquierda <= derecha`, calcular el índice del medio: `medio =
     izquierda + (derecha - izquierda) / 2`.
  3. Comparar el valor buscado con `arreglo[medio]`. Si son iguales, se
     encontró. Si es menor, ajustar `derecha = medio - 1`. Si es mayor, ajustar
     `izquierda = medio + 1`.
- **Salida**: Devolver el índice si se encuentra, o `-1` si el intervalo de
  búsqueda se vacía.
- **Complejidad Temporal**: $O(\log n)$.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Algoritmos de Ordenamiento Cuadráticos ($O(n^2)$)
(ejercicio_30_3)=
### Ejercicio 30.3 - Ordenamiento de Burbuja (Bubble Sort) ⭐⭐☆☆☆

Implementar el ordenamiento de burbuja. Este método recorre repetidamente la
lista, compara elementos adyacentes y los intercambia si están en el orden
incorrecto. Las pasadas a través de la lista se repiten hasta que no se
necesiten más intercambios.

**Lógica y Consideraciones:**
- **Proceso**: Usar dos lazos anidados. El lazo exterior controla el número de
  pasadas. El lazo interior recorre los elementos, "burbujeando" el elemento más
  grande de la sección no ordenada hacia su posición final en cada pasada.
- **Optimización**: Se puede agregar una bandera para detectar si en una pasada
  completa no se realizó ningún intercambio, en cuyo caso el arreglo ya está
  ordenado y el algoritmo puede terminar antes.
(ejercicio_30_4)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 30.4 - Ordenamiento por Selección (Selection Sort) ⭐⭐☆☆☆

Implementar el ordenamiento por selección. Este algoritmo divide el arreglo en
una parte ordenada y una desordenada. En cada iteración, encuentra el elemento
más pequeño de la parte desordenada y lo intercambia con el primer elemento de
esta, moviendo así el límite entre ambas partes.

**Lógica y Consideraciones:**
- **Proceso**: El lazo exterior itera desde `i = 0` hasta `n-2`. En cada
  iteración, el lazo interior (de `j = i+1` a `n-1`) busca el índice del
  elemento mínimo en el resto del arreglo. Finalmente, se intercambia el
  elemento en `i` con el mínimo encontrado.
(ejercicio_30_5)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 30.5 - Ordenamiento por Inserción (Insertion Sort) ⭐⭐☆☆☆

Implementar el ordenamiento por inserción. Este método construye el arreglo
ordenado final un elemento a la vez. Es muy eficiente para arreglos pequeños o
que ya están casi ordenados.

**Lógica y Consideraciones:**
- **Proceso**: Iterar desde el segundo elemento (`i=1`) hasta el final. En cada
  iteración, tomar el elemento actual (`clave`) y compararlo con los elementos a
  su izquierda. Desplazar los elementos mayores que la `clave` una posición
  hacia la derecha para hacer espacio e insertar la `clave` en su posición
  correcta.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Algoritmos de Ordenamiento Avanzados ($O(n \log n)$)
(ejercicio_30_6)=
### Ejercicio 30.6 - Ordenamiento por Fusión (Merge Sort) ⭐⭐☆☆☆

Implementar Merge Sort, un algoritmo eficiente basado en la técnica "Divide y
Vencerás".

**Lógica y Consideraciones:**
- **Proceso**:
  1. **Dividir**: Si el arreglo tiene más de un elemento, dividirlo en dos
     mitades.
  2. **Vencer**: Llamar recursivamente a `merge_sort` para cada mitad.
  3. **Combinar**: Implementar una función `merge` que tome las dos mitades ya
     ordenadas y las fusione en un único arreglo ordenado. Este paso requiere un
     arreglo auxiliar.
(ejercicio_30_7)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 30.7 - Ordenamiento Rápido (Quick Sort) ⭐⭐☆☆☆

Implementar Quick Sort, otro algoritmo "Divide y Vencerás" muy eficiente en la
práctica.

**Lógica y Consideraciones:**
- **Proceso**:
  1. **Elegir Pivote**: Seleccionar un elemento del arreglo como pivote (puede
     ser el último, el primero, uno aleatorio, etc.).
  2. **Particionar**: Reorganizar el arreglo de modo que todos los elementos
     menores que el pivote queden a su izquierda y todos los mayores a su
     derecha. El pivote queda en su posición final ordenada. La función de
     partición devuelve el índice del pivote.
  3. **Vencer**: Llamar recursivamente a `quick_sort` para los sub-arreglos a la
     izquierda y a la derecha del pivote.

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.
-   **[*plus ultra*]:** Validar que los índices ingresados se encuentren estrictamente dentro de los límites del contenedor.

:::
<!-- {hint} Lógica y Consideraciones -->

