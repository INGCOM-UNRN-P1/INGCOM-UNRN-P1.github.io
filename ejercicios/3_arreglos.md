---
title: Ejercicios de Arreglos (Estáticos)
short_title: 3. Arreglos
---

Ejercicios para practicar la manipulación de arreglos de tamaño fijo. Un arreglo
es una colección de elementos del mismo tipo almacenados en ubicaciones de
memoria contiguas.

## 1: Operaciones Básicas

### 1.1: Carga y Muestra

Escribir dos funciones separadas: una para llenar un arreglo con valores
ingresados por el usuario (`cargar_arreglo`) y otra para imprimir su contenido
en un formato legible (`mostrar_arreglo`).

- **Ejemplo `mostrar_arreglo`**: `[10, 20, -5, 8]`

### 1.2: Suma

Calcular la suma de todos los elementos de un arreglo $A$ de tamaño $n$. El
algoritmo debe iterar a través de todos los elementos y acumular sus valores.

$$ S = \sum\_{i=0}^{n-1} A_i $$

- **Ejemplo**: Para `A = [1, 2, 3, 4]`, la suma es `10`.

### 1.3: Promedio

Calcular el valor promedio (media aritmética) de los elementos de un arreglo.
Esto se logra dividiendo la suma total de los elementos por la cantidad de
elementos.

$$ \bar{x} = \frac{1}{n} \sum\_{i=0}^{n-1} A_i $$

- **Ejemplo**: Para `A = [1, 2, 3, 4]`, el promedio es `2.5`.

### 1.4: Productoria

Calcular el producto de todos los elementos de un arreglo. El algoritmo es
similar a la suma, pero utiliza la multiplicación como operación acumulativa.

$$ P = \prod\_{i=0}^{n-1} A_i $$

- **Ejemplo**: Para `A = [1, 2, 3, 4]`, el producto es `24`.

## 2: Búsqueda y Estadísticas

### 2.1: Máximo y Mínimo

Encontrar el valor más grande y el más pequeño dentro de un arreglo. El
algoritmo típico inicializa `max` y `min` con el primer elemento del arreglo y
luego itera desde el segundo elemento, actualizando los valores cada vez que
encuentra un elemento mayor o menor, respectivamente.

- **Ejemplo**: En `[10, 20, -5, 8]`, el máximo es `20` y el mínimo es `-5`.

### 2.2: Casi Máximo

Encontrar el segundo elemento más grande en un arreglo. Un enfoque es mantener
dos variables, `maximo` y `segundo_maximo`, e iterar a través del arreglo
actualizándolas según corresponda.

- **Ejemplo**: En `[10, 20, -5, 8]`, el segundo más grande es `10`.

### 2.3: Búsqueda de Elemento

Implementar una búsqueda lineal para encontrar la primera ocurrencia de un
elemento específico. La función debe recorrer el arreglo y devolver el índice de
la primera coincidencia. Si el elemento no se encuentra, debe devolver un valor
especial, como `-1`.

- **Ejemplo**: En `[10, 20, -5, 8]`, buscar `-5` debe devolver la posición `2`.

### 2.4: Contar Repeticiones

Contar cuántas veces aparece un número específico en un arreglo. Se inicializa
un contador en cero y se recorre el arreglo, incrementando el contador cada vez
que se encuentra el número.

- **Ejemplo**: En `[1, 2, 2, 3, 2]`, el número `2` aparece 3 veces.

### 2.5: Elemento más Cercano

Dado un valor de referencia, encontrar el elemento en el arreglo que tiene la
menor diferencia absoluta con dicho valor.

- **Ejemplo**: En `[10, 20, 35]`, el elemento más cercano a `22` es `20`.

## 3: Manipulación de Arreglos

### 3.1: Inversión

Invertir el orden de los elementos en un arreglo _in-place_ (sin crear un
arreglo auxiliar). El algoritmo utiliza dos índices (o punteros), uno al inicio
y otro al final, intercambiando los elementos y moviendo los índices hacia el
centro hasta que se crucen.

- **Entrada**: `[1, 2, 3, 4, 5]`
- **Salida**: `[5, 4, 3, 2, 1]`

### 3.2: Copia

Copiar los elementos de un arreglo de origen a un arreglo de destino. Se debe
asegurar que el arreglo de destino tenga suficiente capacidad.

### 3.3: Deduplicación

Eliminar elementos duplicados de un arreglo. Una estrategia es mantener un
"índice de escritura" que solo avanza cuando se encuentra un elemento único. La
función debe devolver el nuevo tamaño lógico del arreglo.

- **Entrada**: `[1, 2, 2, 3, 2]`
- **Salida**: `[1, 2, 3]` (nuevo tamaño lógico: 3)

## 4: Verificación

### 4.1: ¿Está ordenado?

Verificar si un arreglo está ordenado de forma ascendente. El algoritmo debe
iterar desde el segundo elemento, comparando cada elemento `A[i]` con su
predecesor `A[i-1]`. Si en algún momento `A[i] < A[i-1]`, el arreglo no está
ordenado.

- **Ejemplo**: `[1, 5, 10, 20]` -> Verdadero.

### 4.2: Solo Positivos

Verificar si todos los elementos de un arreglo son números positivos. La función
debe devolver falso tan pronto como encuentre un elemento menor o igual a cero.

- **Ejemplo**: `[1, 5, -10, 20]` -> Falso.
