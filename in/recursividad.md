---
title: Recursividad en C
description: Una introducción a la definición matemática y la construcción de algoritmos recursivos.
---

La recursividad es una técnica de programación fundamental en la que una función se llama a sí misma para resolver un problema. Este enfoque se basa en la idea de descomponer un problema complejo en subproblemas más pequeños y de la misma naturaleza.

## Definición Matemática

Desde una perspectiva matemática, una definición recursiva tiene dos partes esenciales:

1.  **Caso Base:** Es una o más condiciones terminales que no requieren de una nueva llamada a la función para ser resueltas. Es la solución explícita para el caso más simple del problema.
2.  **Paso Recursivo (o Relación de Recurrencia):** Es la regla que reduce el problema a una versión más simple de sí mismo. Define cómo se resuelve el problema para un caso `n` en términos de uno o más casos "menores" (por ejemplo, `n-1`).

Un ejemplo clásico es la función factorial, $n!$, que se define de la siguiente manera:

$$
n! = \begin{cases} 
1 & \text{si } n = 0 \text{ (Caso Base)} \\
n \times (n-1)! & \text{si } n > 0 \text{ (Paso Recursivo)}
\end{cases}
$$

Esta definición establece que el factorial de 0 es 1 (caso base) y que el factorial de cualquier otro número natural `n` es `n` multiplicado por el factorial de `n-1`.

## Construcción de Algoritmos Recursivos en C

Para implementar un algoritmo recursivo en C (o en cualquier otro lenguaje de programación), debés seguir la estructura de la definición matemática.

### Componentes Clave

Un algoritmo recursivo siempre debe tener:

* **Caso Base:** Una estructura condicional (normalmente un `if`) que verifica si se ha alcanzado la condición de parada. Sin un caso base, la función se llamaría a sí misma infinitamente, resultando en un error de desbordamiento de pila (*stack overflow*).
* **Paso Recursivo:** La parte del código donde la función se invoca a sí misma, pero con argumentos que la acercan progresivamente al caso base. Es crucial que cada llamada recursiva opere sobre un subproblema más pequeño.

### Ejemplo: Función Factorial en C

Veamos cómo se traduce la definición matemática del factorial a una función en C.

```{code} c
:caption: Implementación recursiva de la función factorial
:label: factorial-c

#include <stdio.h>

// Declaración de la función factorial
long int factorial(int n);

int main() {
    int numero = 5;
    printf("El factorial de %d es %ld\n", numero, factorial(numero));
    return 0;
}

// Definición de la función recursiva
long int factorial(int n) {
    // Caso Base: si n es 0, el factorial es 1.
    if (n == 0) {
        return 1;
    } 
    // Paso Recursivo: n * factorial(n-1)
    else {
        return n * factorial(n - 1);
    }
}
```

#### Análisis del Código

1.  **Caso Base:** La línea `if (n == 0)` comprueba la condición de parada. Si `n` es 0, la función retorna `1` y la cadena de llamadas recursivas comienza a resolverse.
2.  **Paso Recursivo:** En la sección `else`, la función retorna el resultado de `n` multiplicado por el valor devuelto por la llamada a `factorial(n - 1)`. Esta llamada es con un problema más pequeño (`n-1`), lo que garantiza que eventualmente se alcanzará el caso base (`n=0`).

:::{important} Pila de llamadas (Call Stack)
Cada vez que una función es llamada (incluyendo las llamadas recursivas), se crea un nuevo marco de pila (*stack frame*) en la memoria para almacenar sus variables locales y el punto de retorno. En la recursividad, estas llamadas se apilan hasta que se alcanza el caso base. Luego, los resultados se "desapilan" y se calculan en orden inverso al de las llamadas.
:::