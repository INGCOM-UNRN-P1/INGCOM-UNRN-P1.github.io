---
title: Ejercicios de recusión
short_title: 10. Recursividad
---

Ejercicios para practicar el pensamiento recursivo y la implementación de
algoritmos sin el uso de lazos explícitos. La recursión es una técnica donde una
función se llama a sí misma para resolver subproblemas más pequeños.

## 1: Matemática Recursiva

Implementar las siguientes operaciones matemáticas para enteros positivos de
manera recursiva.

### 1.1: Factorial

El factorial de un entero no negativo $n$, denotado como $n!$, es el producto de
todos los enteros positivos menores o iguales a $n$.

$$ n! = n \times (n-1) \times (n-2) \times \dots \times 1 $$

La definición recursiva es:

$$ 
factorial(n) = 
\begin{cases}
1 & \text{si } n = 0 \\
n \times factorial(n-1) & \text{si } n > 0
\end{cases}
$$ 

### 1.2: Suma

Definir la suma de $a+b$ de forma recursiva. La idea es decrementar uno de los
operandos hasta llegar a un caso base.

$$ 
suma(a, b) = 
\begin{cases}
a & \text{si } b = 0 \\
suma(a+1, b-1) & \text{si } b > 0
\end{cases}
$$ 

### 1.3: Producto

Definir el producto $a \times b$ usando sumas y recursividad.

$$ 
producto(a, b) = 
\begin{cases}
0 & \text{si } b = 0 \\
a + producto(a, b-1) & \text{si } b > 0
\end{cases}
$$ 

### 1.4: Potencia

Definir la potencia $base^{exp}$ usando productos y recursividad.

$$ 
potencia(base, exp) = 
\begin{cases}
1 & \text{si } exp = 0 \\
base \times potencia(base, exp-1) & \text{si } exp > 0
\end{cases}
$$ 

## 2: Series Recursivas

### 2.1: Fibonacci

Implementar una función que calcule el n-ésimo término de la serie de Fibonacci,
definida por la relación de recurrencia:

$$ 
fib(n) = 
\begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
fib(n-1) + fib(n-2) & \text{si } n > 1
\end{cases}
$$ 

## 3: Arreglos Recursivos

Implementar las siguientes funciones sobre arreglos usando recursividad. La
clave es pasar un sub-arreglo más pequeño en cada llamada, usualmente
incrementando el puntero de inicio.

### 3.1: Mostrar arreglo

Imprimir el primer elemento y luego llamar a la función con el resto del
arreglo.

### 3.2: Mostrar arreglo invertido

Llamar a la función con el resto del arreglo y luego imprimir el primer
elemento.

### 3.3: Suma de valores

Sumar el primer elemento con el resultado de llamar a la función sobre el resto
del arreglo.

## 4: Cadenas Recursivas

### 4.1: Palíndromo

Implementar una función recursiva que determine si una cadena es un palíndromo.
Un palíndromo se lee igual en ambos sentidos.

**Lógica recursiva:** Una cadena es un palíndromo si:

1.  Su primer y último carácter son iguales, Y
2.  La subcadena entre ellos también es un palíndromo.

**Caso Base:** Una cadena vacía o de un solo carácter es un palíndromo.

**Ejemplo:** `neuquen`

- `es_palindromo(