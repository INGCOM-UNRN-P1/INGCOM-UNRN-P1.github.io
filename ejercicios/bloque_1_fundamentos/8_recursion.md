---
title: Ejercicios de Recursividad
short_title: 8. Recursividad
---

# Ejercicios de Recursividad

## Acerca de

Estos ejercicios tienen como fin practicar la recursión como alternativa al control de lazos explícitos. La recursión consiste en estructurar la lógica de un subprograma de forma que se llame a sí mismo con un subproblema de tamaño reducido, hasta converger en un caso base.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-recursividad-basica`

### Cuestiones de Estilo Aplicables
- **Casos base explícitos:** Asegurate de definir de forma inequívoca el caso de corte en la primera instrucción de la función recursiva.
- **Punteros y arreglos:** Al pasar arreglos a funciones recursivas, utilizá la aritmética de punteros para desplazar la dirección base del sub-arreglo en cada llamada (ver reglas de estilo en {ref}`0x2009h`).

---

## Matemática Recursiva

### Ejercicio 8.1 - Factorial

El factorial de un entero no negativo $n$, denotado como $n!$, es el producto de todos los enteros positivos menores o iguales a $n$.

$$ n! = n \times (n-1) \times (n-2) \times \dots \times 1 $$

La definición recursiva es:

$$ 
factorial(n) = 
\begin{cases}
1 & \text{si } n = 0 \\
n \times factorial(n-1) & \text{si } n > 0
\end{cases}
$$ 

### Ejercicio 8.2 - Suma

Definir la suma de $a+b$ de forma recursiva. La idea es decrementar uno de los operandos hasta llegar a un caso base.

$$ 
suma(a, b) = 
\begin{cases}
a & \text{si } b = 0 \\
suma(a+1, b-1) & \text{si } b > 0
\end{cases}
$$ 

### Ejercicio 8.3 - Producto

Definir el producto $a \times b$ usando sumas y recursividad.

$$ 
producto(a, b) = 
\begin{cases}
0 & \text{si } b = 0 \\
a + producto(a, b-1) & \text{si } b > 0
\end{cases}
$$ 

### Ejercicio 8.4 - Potencia

Definir la potencia $base^{exp}$ usando productos y recursividad.

$$ 
potencia(base, exp) = 
\begin{cases}
1 & \text{si } exp = 0 \\
base \times potencia(base, exp-1) & \text{si } exp > 0
\end{cases}
$$ 

---

## Series Recursivas

### Ejercicio 8.5 - Fibonacci

Implementar una función que calcule el n-ésimo término de la serie de Fibonacci, definida por la relación de recurrencia:

$$ 
fib(n) = 
\begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
fib(n-1) + fib(n-2) & \text{si } n > 1
\end{cases}
$$ 

---

## Arreglos Recursivos

### Ejercicio 8.6 - Mostrar arreglo

Imprimir el primer elemento y luego llamar a la función con el resto del arreglo.

### Ejercicio 8.7 - Mostrar arreglo invertido

Llamar a la función con el resto del arreglo y luego imprimir el primer elemento.

### Ejercicio 8.8 - Suma de valores

Sumar el primer elemento con el resultado de llamar a la función sobre el resto del arreglo.

---

## Cadenas Recursivas

### Ejercicio 8.9 - Palíndromo

Implementar una función recursiva que determine si una cadena es un palíndromo. Un palíndromo se lee igual en ambos sentidos.

**Lógica recursiva:** Una cadena es un palíndromo si:
1. Su primer y último carácter son iguales, Y
2. La subcadena entre ellos también es un palíndromo.

**Caso Base:** Una cadena vacía o de un solo carácter es un palíndromo.

**Ejemplo:** `neuquen`
- `es_palindromo("neuquen")` es verdadero.