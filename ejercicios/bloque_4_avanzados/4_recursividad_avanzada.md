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

---

(ej_b4_c07_06)=
### Ejercicio 4.07.06 - Búsqueda Binaria Recursiva (Divide y Vencerás) ⭐⭐☆☆☆

:::{exercise}
:label: ej_b4_c07_06_busqueda_binaria_rec

Implementá el algoritmo de búsqueda binaria sobre un arreglo ordenado de enteros utilizando recursión y la estrategia de divide y conquista:

```c
int busqueda_binaria_rec(const int *arr, int inicio, int fin, int objetivo);
```

Retorna el índice donde se encuentra `objetivo` dentro del rango `[inicio, fin]`, o `-1` si no existe.

**Tabla de Vectores de Prueba:**

| Arreglo | Rango `[inicio, fin]` | Objetivo | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| `[10, 20, 30, 40, 50]` | `[0, 4]` | `30` | `2` (Posición central) |
| `[10, 20, 30, 40, 50]` | `[0, 4]` | `10` | `0` (Extremo izquierdo) |
| `[10, 20, 30, 40, 50]` | `[0, 4]` | `50` | `4` (Extremo derecho) |
| `[10, 20, 30, 40, 50]` | `[0, 4]` | `99` | `-1` (No presente) |
| `[]` | `[0, -1]` | `5` | `-1` (Rango vacío) |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

int busqueda_binaria_rec(const int *arr, int inicio, int fin, int objetivo) {
    if (arr == NULL || inicio > fin) {
        return -1;
    }
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio] == objetivo) {
        return medio;
    }
    if (arr[medio] > objetivo) {
        return busqueda_binaria_rec(arr, inicio, medio - 1, objetivo);
    }
    return busqueda_binaria_rec(arr, medio + 1, fin, objetivo);
}

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    assert(busqueda_binaria_rec(arr, 0, 4, 30) == 2);
    assert(busqueda_binaria_rec(arr, 0, 4, 10) == 0);
    assert(busqueda_binaria_rec(arr, 0, 4, 50) == 4);
    assert(busqueda_binaria_rec(arr, 0, 4, 99) == -1);
    assert(busqueda_binaria_rec(arr, 0, 4, 5) == -1);
    assert(busqueda_binaria_rec(NULL, 0, 0, 10) == -1);
    assert(busqueda_binaria_rec(arr, 2, 1, 10) == -1);
    return 0;
}
```
::::
:::

---

(ej_b4_c07_07)=
### Ejercicio 4.07.07 - Caminos Únicos en Grilla Bidimensional ⭐⭐⭐☆☆

:::{exercise}
:label: caminos_grilla_rec
:enumerator: recursividad-adv-7

Dada una cuadrícula de $m$ filas por $n$ columnas, un robot situado en la esquina superior izquierda $(0, 0)$ necesita alcanzar la esquina inferior derecha $(m-1, n-1)$.
En cada paso, el robot solo puede desplazarse una casilla hacia la derecha o una casilla hacia abajo.

Implementá una función puramente recursiva:
```c
size_t caminos_grilla_rec(size_t m, size_t n);
```
que calcule la cantidad total de caminos únicos posibles sin utilizar estructuras iterativas ni variables estáticas.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Recursión ramificada, caso base de frontera unitaria ($m=1$ o $n=1$), árbol de llamadas recursivas.  
**Techo conceptual:** Prohibido el uso de lazos `for` / `while` o fórmulas cerradas analíticas con factoriales (debe demostrar descomposición por subproblemas).

#### Contrato de la Función
- **Firma:** `size_t caminos_grilla_rec(size_t m, size_t n);`
- **Precondiciones:** $m \ge 0, n \ge 0$.
- **Postcondiciones:** Si $m == 0$ o $n == 0$, retorna $0$. Si $m == 1$ o $n == 1$, retorna $1$. En caso general retorna `caminos_grilla_rec(m - 1, n) + caminos_grilla_rec(m, n - 1)`.

#### Tabla de Vectores de Prueba Obligatorios

| Dimensiones ($m \times n$) | Caminos Esperados | Justificación Técnica |
| :--- | :--- | :--- |
| $3 \times 3$ | `6` | 6 permutaciones de 2 pasos abajo y 2 derecha |
| $3 \times 2$ | `3` | Permutaciones: `{DDA, DAD, ADD}` |
| $1 \times 5$ | `1` | Solo existe la trayectoria recta hacia la derecha |
| $5 \times 1$ | `1` | Solo existe la trayectoria recta hacia abajo |
| $0 \times 4$ | `0` | Dimensión degenerada sin camino posible |

:::
<!-- {exercise} -->

::::{solution} caminos_grilla_rec
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

size_t caminos_grilla_rec(size_t m, size_t n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 || n == 1)
    {
        return 1;
    }

    return caminos_grilla_rec(m - 1, n) + caminos_grilla_rec(m, n - 1);
}

int main(void)
{
    // Grilla 3x3
    assert(caminos_grilla_rec(3, 3) == 6);

    // Grilla 3x2
    assert(caminos_grilla_rec(3, 2) == 3);

    // Grillas unidimensionales
    assert(caminos_grilla_rec(1, 5) == 1);
    assert(caminos_grilla_rec(5, 1) == 1);

    // Casos degenerados
    assert(caminos_grilla_rec(0, 4) == 0);
    assert(caminos_grilla_rec(4, 0) == 0);
    assert(caminos_grilla_rec(0, 0) == 0);

    return 0;
}
```

::::
<!-- {solution} caminos_grilla_rec -->

---

(ej_b4_c07_08)=
### Ejercicio 4.07.08 - Conteo Recursivo de Subconjuntos con Suma Objetivo (Backtracking) ⭐⭐⭐☆☆

:::{exercise}
:label: conteo_subconjuntos_suma
:enumerator: recursividad-8

El problema de la suma de subconjuntos (*Subset Sum*) es un pilar fundamental en algoritmia y complejidad computacional. Dado un conjunto de números enteros y un valor objetivo (*target*), se busca determinar cuántos subconjuntos distintos suman exactamente dicho valor.

Implementá la función recursiva:
```c
size_t contar_subconjuntos_suma(const int conjunto[], size_t n, size_t indice, int suma_acumulada, int objetivo);
```

- **Estrategia recursiva (Backtracking binario):**
  - Para cada elemento en la posición `indice`, existen exactamente dos ramas de decisión ortogonales:
    1. **Incluir** el elemento en la suma acumulada: `suma_acumulada + conjunto[indice]`.
    2. **Excluir** el elemento de la suma acumulada: `suma_acumulada`.
  - **Caso Base:** Al alcanzar el final del arreglo (`indice == n`), si `suma_acumulada == objetivo` se contabiliza un subconjunto válido (`1`), en caso contrario `0`.
- **Precondiciones:** `conjunto != NULL` (si `n > 0`).

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Conjunto ($n$) | Objetivo | Subconjuntos Válidos | Conteo Esperado |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `{1, 2, 3, 4}`, $n=4$ | `5` | `{1, 4}`, `{2, 3}` | `2` |
| **Elemento Cero** | `{0, 5, -5}`, $n=3$ | `0` | `{}`, `{0}`, `{5, -5}`, `{0, 5, -5}` | `4` |
| **Suma Inalcanzable**| `{2, 4, 6}`, $n=3$ | `5` | Ninguno | `0` |
| **Conjunto Vacío** | `{}`, $n=0$ | `0` | `{}` (subconjunto vacío suma 0) | `1` |

:::
<!-- {exercise} conteo_subconjuntos_suma -->

::::{solution} conteo_subconjuntos_suma
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t contar_subconjuntos_suma(const int conjunto[], size_t n, size_t indice, int suma_acumulada, int objetivo) {
    if (indice == n) {
        return (suma_acumulada == objetivo) ? 1 : 0;
    }

    // Rama 1: Incluir el elemento conjunto[indice]
    size_t incluir = contar_subconjuntos_suma(conjunto, n, indice + 1, suma_acumulada + conjunto[indice], objetivo);

    // Rama 2: Excluir el elemento conjunto[indice]
    size_t excluir = contar_subconjuntos_suma(conjunto, n, indice + 1, suma_acumulada, objetivo);

    return incluir + excluir;
}

int main(void) {
    // Caso 1: {1, 2, 3, 4}, objetivo 5 -> {1,4}, {2,3}
    int c1[4] = {1, 2, 3, 4};
    assert(contar_subconjuntos_suma(c1, 4, 0, 0, 5) == 2);

    // Caso 2: {0, 5, -5}, objetivo 0 -> {}, {0}, {5,-5}, {0, 5, -5}
    int c2[3] = {0, 5, -5};
    assert(contar_subconjuntos_suma(c2, 3, 0, 0, 0) == 4);

    // Caso 3: Imposible
    int c3[3] = {2, 4, 6};
    assert(contar_subconjuntos_suma(c3, 3, 0, 0, 5) == 0);

    // Caso 4: Conjunto vacío con objetivo 0 -> el conjunto vacío suma 0
    assert(contar_subconjuntos_suma(NULL, 0, 0, 0, 0) == 1);

    // Caso 5: Conjunto vacío con objetivo distinto de 0
    assert(contar_subconjuntos_suma(NULL, 0, 0, 0, 10) == 0);

    return 0;
}
```

::::
<!-- {solution} conteo_subconjuntos_suma -->

