---
title: "Ejercicios: Recursividad y Divide y Vencerás"
short_title: "5. Recursividad"
---

# Ejercicios de Recursividad y Divide y Vencerás

## Acerca de

Estos ejercicios tienen como propósito dominar la recursividad de control y el
paradigma de diseño "Divide y Vencerás" en C11, profundizando en optimizaciones
de complejidad temporal y análisis de marcos de pila.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-recursividad-basica`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Pila de llamadas en memoria (*Stack Frames*) y paso por valor ({ref}`capitulo-memoria-stack`).
2. Deducción de relaciones de recurrencia y condiciones de corte inductivo.
3. Técnicas divide y conquista para reducir la complejidad temporal de $O(n)$ a $O(\log n)$.
4. Análisis de costo espacial en memoria por profundidad de pila.

### Cuestiones de Estilo Aplicables
- **Casos de corte explícitos:** Definí el caso base al inicio de la función
  recursiva para evitar lazos de llamada infinitos y desbordamientos de stack
  frame (ver {ref}`0x2008h`).
- **Optimización divide y conquista:** En operaciones aritméticas recursivas,
  bifurcá el problema en subproblemas de tamaño $n/2$ cuando sea matemáticamente
  viable.

---

## Fundamentos de Recursividad

(ej_b4_c07_01)=
### Ejercicio 4.07.01 - Factorial con Tipos de Rango Amplio ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c07_01_factorial

Implementá la función factorial recursiva utilizando enteros de 64 bits sin signo
para mitigar desbordamientos tempranos.

```c
unsigned long long factorial_avanzado(unsigned int n);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada `n` | Salida Esperada |
| :--- | :--- | :--- |
| Caso base cero | `0` | `1ULL` |
| Caso base uno | `1` | `1ULL` |
| Valor intermedio | `5` | `120ULL` |
| Valor elevado | `12` | `479001600ULL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned long long factorial_avanzado(unsigned int n) {
    if (n <= 1) {
        return 1ULL;
    }
    return (unsigned long long)n * factorial_avanzado(n - 1);
}

int main(void) {
    assert(factorial_avanzado(0) == 1ULL);
    assert(factorial_avanzado(1) == 1ULL);
    assert(factorial_avanzado(5) == 120ULL);
    assert(factorial_avanzado(12) == 479001600ULL);
    return 0;
}
```
::::
:::

(ej_b4_c07_02)=
### Ejercicio 4.07.02 - Suma de Enteros por Desplazamiento Unitario ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c07_02_suma

Implementá la suma recursiva sin utilizar el operador binario `+` en el llamado
recursivo, decrementando `b` e incrementando `a`.

```c
int suma_recursiva(int a, int b);
```

**Tabla de Vectores de Prueba:**

| Operandos (`a`, `b`) | Salida Esperada |
| :--- | :--- |
| `a = 15, b = 0` | `15` |
| `a = 0, b = 25` | `25` |
| `a = 10, b = 30` | `40` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

int suma_recursiva(int a, int b) {
    if (b == 0) {
        return a;
    }
    return suma_recursiva(a + 1, b - 1);
}

int main(void) {
    assert(suma_recursiva(15, 0) == 15);
    assert(suma_recursiva(0, 25) == 25);
    assert(suma_recursiva(10, 30) == 40);
    return 0;
}
```
::::
:::

(ej_b4_c07_03)=
### Ejercicio 4.07.03 - Producto por Sumas Recursivas ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c07_03_producto

Implementá la multiplicación entera recursiva en tiempo $O(b)$.

```c
long long producto_recursivo(long long a, unsigned int b);
```

**Tabla de Vectores de Prueba:**

| Operandos (`a`, `b`) | Salida Esperada |
| :--- | :--- |
| `a = 50, b = 0` | `0LL` |
| `a = 7, b = 8` | `56LL` |
| `a = -12, b = 4` | `-48LL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

long long producto_recursivo(long long a, unsigned int b) {
    if (b == 0) {
        return 0LL;
    }
    return a + producto_recursivo(a, b - 1);
}

int main(void) {
    assert(producto_recursivo(50, 0) == 0LL);
    assert(producto_recursivo(7, 8) == 56LL);
    assert(producto_recursivo(-12, 4) == -48LL);
    return 0;
}
```
::::
:::

(ej_b4_c07_04)=
### Ejercicio 4.07.04 - Exponenciación Rápida (Divide y Vencerás) ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c07_04_potencia_rapida

Implementá la función de potencia optimizada que reduzca la complejidad de
$O(n)$ a $O(\log n)$ mediante la regla de exponenciación binaria:
si $exp$ es par, $base^{exp} = (base^{exp/2})^2$; si es impar, $base \times base^{exp-1}$.

```c
long long potencia_rapida(long long base, unsigned int exp);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Base | Exponente | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| Exponente cero | `42` | `0` | `1LL` |
| Exponente par | `2` | `10` | `1024LL` |
| Exponente impar | `3` | `5` | `243LL` |
| Base negativa par | `-2` | `4` | `16LL` |
| Base negativa impar | `-2` | `5` | `-32LL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

long long potencia_rapida(long long base, unsigned int exp) {
    if (exp == 0) {
        return 1LL;
    }
    if (exp % 2 == 0) {
        long long mitad = potencia_rapida(base, exp / 2);
        return mitad * mitad;
    }
    return base * potencia_rapida(base, exp - 1);
}

int main(void) {
    assert(potencia_rapida(42, 0) == 1LL);
    assert(potencia_rapida(2, 10) == 1024LL);
    assert(potencia_rapida(3, 5) == 243LL);
    assert(potencia_rapida(-2, 4) == 16LL);
    assert(potencia_rapida(-2, 5) == -32LL);
    return 0;
}
```
::::
:::

---

## Series Numéricas Recursivas

(ej_b4_c07_05)=
### Ejercicio 4.07.05 - Fibonacci Básico y de Cola ⭐☆☆☆☆

:::{exercise}
:label: ej_b4_c07_05_fibonacci_avanzado

Implementá Fibonacci recursivo con recursión de cola (*tail recursion*) para
permitir que el compilador optimice los marcos de pila en $O(n)$ tiempo y $O(1)$ espacio auxiliar.

```c
unsigned long long fibonacci_tail(unsigned int n, unsigned long long a, unsigned long long b);
```

**Tabla de Vectores de Prueba:**

| Índice `n` | Llamada Inicial (`a=0, b=1`) | Salida Esperada |
| :--- | :--- | :--- |
| `0` | `fibonacci_tail(0, 0, 1)` | `0ULL` |
| `1` | `fibonacci_tail(1, 0, 1)` | `1ULL` |
| `7` | `fibonacci_tail(7, 0, 1)` | `13ULL` |
| `20` | `fibonacci_tail(20, 0, 1)` | `6765ULL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned long long fibonacci_tail(unsigned int n, unsigned long long a, unsigned long long b) {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    return fibonacci_tail(n - 1, b, a + b);
}

static unsigned long long fibonacci(unsigned int n) {
    return fibonacci_tail(n, 0ULL, 1ULL);
}

int main(void) {
    assert(fibonacci(0) == 0ULL);
    assert(fibonacci(1) == 1ULL);
    assert(fibonacci(2) == 1ULL);
    assert(fibonacci(3) == 2ULL);
    assert(fibonacci(7) == 13ULL);
    assert(fibonacci(20) == 6765ULL);
    return 0;
}
```
::::
:::
