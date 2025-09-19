---
title: Ejercicios Matemáticos
short_title: 2. Matemáticos
---

# Ejercicios Matemáticos

Ejercicios centrados en algoritmos de teoría de números y operaciones
matemáticas.

## 1: Aritmética Lenta

### 1.1: Suma lenta

Implementar una función que calcule la suma de dos enteros, $n+m$, utilizando
únicamente operaciones de incremento (`+1`) o decremento (`-1`).

### 1.2: División lenta

Implementar la división entera para obtener el cociente y el resto de $a / b$
utilizando únicamente restas.

**Algoritmo:** Se resta repetidamente el divisor (`b`) del dividendo (`a`) hasta
que el dividendo sea menor que el divisor. El número de restas realizadas es el
cociente, y el valor final del dividendo es el resto.

- **Ejemplo**: `13 / 5`
  1. `13 - 5 = 8` (1 resta)
  2. `8 - 5 = 3` (2 restas)
  3. Como `3 < 5`, el proceso termina. **Cociente = 2**, **Resto = 3**.

La obtención del resto, debiera de ser implementada en una función separada.

### 1.3: División egipcia

Implementar la división usando el método egipcio, que se basa en duplicación,
suma y resta.

**Algoritmo Resumido:**

1.  **Tabla de duplicación**: Crear una tabla con dos columnas. La primera
    empieza en 1 y la segunda en el divisor. Duplicar los valores de cada fila
    hasta que el valor en la segunda columna supere al dividendo.
2.  **Búsqueda y suma**: Empezando desde la fila más alta de la tabla, encontrar
    la combinación de números en la columna del divisor que sumen la mayor
    cantidad posible sin exceder el dividendo.
3.  **Resultado**: El cociente es la suma de los números correspondientes en la
    primera columna. El resto es el dividendo original menos la suma de los
    divisores seleccionados.

## 2: Divisibilidad y Factores

### 2.1: Divisibilidad

Determinar si un entero $a$ es divisible por un entero $b$. Esto se cumple si el
resto de la división entera es cero, es decir, $a \pmod b = 0$.

### 2.2: Factorial

Calcular el factorial de un número entero no negativo $n$, que se define como el
producto de todos los enteros positivos desde 1 hasta $n$.

$$ n! = \prod\_{k=1}^{n} k = 1 \times 2 \times \dots \times n $$

Por convención, $0! = 1$.

### 2.3: MCD y MCM

- **Máximo Común Divisor (MCD)**: Calcular el MCD de dos enteros $a$ y $b$
  usando el
  [algoritmo de Euclides](https://es.wikipedia.org/wiki/Algoritmo_de_Euclides).
  Mientras $b$ no sea cero, se reemplaza $a$ por $b$ y $b$ por $a \pmod b$. El
  MCD es el último valor no nulo de $a$.
- **Mínimo Común Múltiplo (MCM)**: Se puede calcular eficientemente usando el
  MCD con la fórmula: $$ MCM(a, b) = \frac{|a \times b|}{MCD(a, b)} $$

## 3: Propiedades de los Números

### 3.1: Suma de dígitos

Calcular la suma de los dígitos de un número entero. El algoritmo consiste en
obtener y sumar el último dígito con el operador módulo (`n % 10`) y luego
eliminarlo con una división entera (`n / 10`), repitiendo hasta que el número
sea cero.

### 3.2: Invertir un número

Invertir el orden de los dígitos de un número. Se puede construir el número
invertido iterativamente: `invertido = (invertido * 10) + (n % 10)`.

### 3.3: Capicúas

Verificar si un número es capicúa (palíndromo), es decir, si se lee igual de
izquierda a derecha que de derecha a izquierda. El método consiste en invertir
el número y compararlo con el original.

### 3.4: Números Primos

Un número $p > 1$ es primo si sus únicos divisores son 1 y él mismo. Para
verificar si un número $n$ es primo, es suficiente comprobar si es divisible por
algún número desde 2 hasta $\sqrt{n}$.

### 3.5: Números Perfectos

Un número es perfecto si es igual a la suma de sus divisores propios
(excluyéndose a sí mismo). Formalmente, usando la función suma de divisores
$\sigma(n)$, un número es perfecto si $\sigma(n) = 2n$. Ejemplo:
$28 = 1+2+4+7+14$.

### 3.6: Números Amigos

Dos números $a$ y $b$ son amigos si la suma de los divisores propios de $a$ es
igual a $b$, y la suma de los divisores propios de $b$ es igual a $a$.
Formalmente, $\sigma^*(a) = b$ y $\sigma^*(b) = a$, donde
$\sigma^*(n) = \sigma(n) - n$.

### 3.7: Números Abundantes

Un número es abundante si la suma de sus divisores propios es mayor que el
propio número. Formalmente, $\sigma^*(n) > n$. Ejemplo: $12 < 1+2+3+4+6=16$.

### 3.8: Conjetura de Collatz

Implementar la secuencia de Collatz, que para un número $n$ dado, aplica
repetidamente la función:

$$
 f(n) =
 \begin{cases}
 n/2 & \text{si } n \text{ es par} \\
 3n+1 & \text{si } n \text{ es impar}
 \end{cases}
$$

La conjetura afirma que esta secuencia siempre llegará a 1. Ejemplo para n=6:
`6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1`.

### 3.9: Números de Armstrong

Un número de $k$ dígitos es un número de Armstrong si es igual a la suma de sus
dígitos elevados a la potencia $k$. Ejemplo: $153 = 1^3 + 5^3 + 3^3$.

### 3.10: Números Felices

Un número es feliz si el proceso de reemplazarlo por la suma de los cuadrados de
sus dígitos, repetido sucesivamente, termina en 1. Si el proceso entra en un
ciclo que no incluye el 1, el número no es feliz. Ejemplo:
$19 \rightarrow 1^2+9^2=82 \rightarrow 8^2+2^2=68 \rightarrow \dots \rightarrow 1$.
