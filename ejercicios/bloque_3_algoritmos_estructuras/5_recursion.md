---
title: Ejercicios de Recursividad
short_title: 8. Recursividad
---

# Ejercicios de Recursividad

## Acerca de

Estos ejercicios tienen como fin practicar la recursión como alternativa al
control de lazos explícitos. La recursión consiste en estructurar la lógica de
un subprograma de forma que se llame a sí mismo con un subproblema de tamaño
reducido, hasta converger en un caso base.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-recursividad-basica`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Pila de llamadas en memoria (*Stack Frames*) y paso de argumentos por valor y referencia ({ref}`capitulo-memoria-stack`).
2. Condición de corte y convergencia del caso base inductivo ({ref}`capitulo-recursividad-basica`).
3. Aritmética de punteros para segmentación de sub-arreglos y cadenas (`ptr + 1`, `len - 1`).
4. Prevención de recursión infinita y desbordamiento de pila (*Stack Overflow*).

### Cuestiones de Estilo Aplicables
- **Casos base explícitos:** Asegurate de definir de forma inequívoca el caso de
  corte en la primera instrucción de la función recursiva.
- **Punteros y arreglos:** Al pasar arreglos a funciones recursivas, utilizá la
  aritmética de punteros para desplazar la dirección base del sub-arreglo en
  cada llamada (ver reglas de estilo en {ref}`0x2008h`).

---

## Matemática Recursiva

(ej_b3_c07_01)=
### Ejercicio 3.07.01 - Factorial ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_01_factorial

Implementá el cálculo de factorial $n!$ de forma recursiva bajo la firma:

```c
unsigned long long factorial_rec(unsigned int n);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada `n` | Salida Esperada |
| :--- | :--- | :--- |
| Caso base cero | `0` | `1ULL` |
| Caso base uno | `1` | `1ULL` |
| Valor intermedio | `5` | `120ULL` |
| Valor mayor | `10` | `3628800ULL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned long long factorial_rec(unsigned int n) {
    if (n <= 1) {
        return 1ULL;
    }
    return (unsigned long long)n * factorial_rec(n - 1);
}

int main(void) {
    assert(factorial_rec(0) == 1ULL);
    assert(factorial_rec(1) == 1ULL);
    assert(factorial_rec(2) == 2ULL);
    assert(factorial_rec(5) == 120ULL);
    assert(factorial_rec(10) == 3628800ULL);
    return 0;
}
```
::::
:::

(ej_b3_c07_02)=
### Ejercicio 3.07.02 - Suma Recursiva ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_02_suma

Implementá la suma de dos enteros no negativos $a + b$ decrementando el segundo
operando hasta converger al caso base $b = 0$.

```c
unsigned int suma_rec(unsigned int a, unsigned int b);
```

**Tabla de Vectores de Prueba:**

| Operandos (`a`, `b`) | Salida Esperada |
| :--- | :--- |
| `a = 5, b = 0` | `5` |
| `a = 0, b = 7` | `7` |
| `a = 12, b = 8` | `20` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned int suma_rec(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    return suma_rec(a + 1, b - 1);
}

int main(void) {
    assert(suma_rec(5, 0) == 5);
    assert(suma_rec(0, 7) == 7);
    assert(suma_rec(12, 8) == 20);
    assert(suma_rec(0, 0) == 0);
    return 0;
}
```
::::
:::

(ej_b3_c07_03)=
### Ejercicio 3.07.03 - Producto por Sumas Sucesivas ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_03_producto

Implementá la multiplicación recursiva de dos enteros no negativos $a \times b$
mediante acumulaciones sucesivas.

```c
unsigned int producto_rec(unsigned int a, unsigned int b);
```

**Tabla de Vectores de Prueba:**

| Operandos (`a`, `b`) | Salida Esperada |
| :--- | :--- |
| `a = 4, b = 0` | `0` |
| `a = 6, b = 1` | `6` |
| `a = 7, b = 5` | `35` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned int producto_rec(unsigned int a, unsigned int b) {
    if (b == 0) {
        return 0;
    }
    return a + producto_rec(a, b - 1);
}

int main(void) {
    assert(producto_rec(4, 0) == 0);
    assert(producto_rec(0, 9) == 0);
    assert(producto_rec(6, 1) == 6);
    assert(producto_rec(7, 5) == 35);
    return 0;
}
```
::::
:::

(ej_b3_c07_04)=
### Ejercicio 3.07.04 - Potencia Entera ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_04_potencia

Calculá $base^{exp}$ para un exponente entero no negativo de manera recursiva.

```c
long long potencia_rec(long long base, unsigned int exp);
```

**Tabla de Vectores de Prueba:**

| Entrada (`base`, `exp`) | Salida Esperada |
| :--- | :--- |
| `base = 5, exp = 0` | `1LL` |
| `base = 2, exp = 8` | `256LL` |
| `base = -3, exp = 3` | `-27LL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

long long potencia_rec(long long base, unsigned int exp) {
    if (exp == 0) {
        return 1LL;
    }
    return base * potencia_rec(base, exp - 1);
}

int main(void) {
    assert(potencia_rec(5, 0) == 1LL);
    assert(potencia_rec(2, 8) == 256LL);
    assert(potencia_rec(-3, 3) == -27LL);
    assert(potencia_rec(-3, 2) == 9LL);
    return 0;
}
```
::::
:::

---

## Series Recursivas

(ej_b3_c07_05)=
### Ejercicio 3.07.05 - Fibonacci ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_05_fibonacci

Calculá el n-ésimo término de Fibonacci respetando:
$F(0) = 0$, $F(1) = 1$, $F(n) = F(n-1) + F(n-2)$.

```c
unsigned long long fibonacci_rec(unsigned int n);
```

**Tabla de Vectores de Prueba:**

| Índice `n` | Fibonacci Esperado |
| :--- | :--- |
| `0` | `0ULL` |
| `1` | `1ULL` |
| `6` | `8ULL` |
| `10` | `55ULL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned long long fibonacci_rec(unsigned int n) {
    if (n == 0) {
        return 0ULL;
    }
    if (n == 1) {
        return 1ULL;
    }
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main(void) {
    assert(fibonacci_rec(0) == 0ULL);
    assert(fibonacci_rec(1) == 1ULL);
    assert(fibonacci_rec(2) == 1ULL);
    assert(fibonacci_rec(6) == 8ULL);
    assert(fibonacci_rec(10) == 55ULL);
    return 0;
}
```
::::
:::

---

## Arreglos Recursivos

(ej_b3_c07_06)=
### Ejercicio 3.07.06 - Copiar Arreglo Recursivo ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c07_06_copiar_arr

Copiá los elementos de un arreglo a un búfer destino en el mismo orden usando
recursión y aritmética de punteros.

```c
void copiar_arreglo_rec(const int *origen, int *destino, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo Origen | `n` | Arreglo Destino Resultante |
| :--- | :--- | :--- |
| `[10, 20, 30]` | `3` | `[10, 20, 30]` |
| `[]` | `0` | Sin modificaciones |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

void copiar_arreglo_rec(const int *origen, int *destino, size_t n) {
    if (n == 0) {
        return;
    }
    *destino = *origen;
    copiar_arreglo_rec(origen + 1, destino + 1, n - 1);
}

int main(void) {
    int orig[] = {10, 20, 30, 40};
    int dest[4] = {0};

    copiar_arreglo_rec(orig, dest, 4);
    assert(dest[0] == 10 && dest[1] == 20 && dest[2] == 30 && dest[3] == 40);

    /* Caso de longitud cero */
    int vacio[2] = {99, 99};
    copiar_arreglo_rec(orig, vacio, 0);
    assert(vacio[0] == 99 && vacio[1] == 99);

    return 0;
}
```
::::
:::

(ej_b3_c07_07)=
### Ejercicio 3.07.07 - Invertir Arreglo Recursivo ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c07_07_invertir_arr

Copiá los elementos de un arreglo a un búfer destino en orden inverso usando recursión.

```c
void invertir_arreglo_rec(const int *origen, int *destino, size_t n);
```

**Tabla de Vectores de Prueba:**

| Entrada | `n` | Salida Invertida |
| :--- | :--- | :--- |
| `[1, 2, 3, 4]` | `4` | `[4, 3, 2, 1]` |
| `[42]` | `1` | `[42]` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

void invertir_arreglo_rec(const int *origen, int *destino, size_t n) {
    if (n == 0) {
        return;
    }
    destino[n - 1] = *origen;
    invertir_arreglo_rec(origen + 1, destino, n - 1);
}

int main(void) {
    int orig[] = {1, 2, 3, 4};
    int dest[4] = {0};

    invertir_arreglo_rec(orig, dest, 4);
    assert(dest[0] == 4 && dest[1] == 3 && dest[2] == 2 && dest[3] == 1);

    int uno[] = {42};
    int dest_uno[1] = {0};
    invertir_arreglo_rec(uno, dest_uno, 1);
    assert(dest_uno[0] == 42);

    return 0;
}
```
::::
:::

(ej_b3_c07_08)=
### Ejercicio 3.07.08 - Suma de Elementos de un Arreglo ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_08_suma_arr

Sumá todos los enteros de un arreglo de forma recursiva.

```c
long long suma_arreglo_rec(const int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Suma Esperada |
| :--- | :--- | :--- |
| `[1, 2, 3, 4, 5]` | `5` | `15LL` |
| `[-5, 10, -3]` | `3` | `2LL` |
| `[]` | `0` | `0LL` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

long long suma_arreglo_rec(const int *arr, size_t n) {
    if (n == 0) {
        return 0LL;
    }
    return (long long)*arr + suma_arreglo_rec(arr + 1, n - 1);
}

int main(void) {
    int a1[] = {1, 2, 3, 4, 5};
    assert(suma_arreglo_rec(a1, 5) == 15LL);

    int a2[] = {-5, 10, -3};
    assert(suma_arreglo_rec(a2, 3) == 2LL);

    assert(suma_arreglo_rec(a1, 0) == 0LL);
    return 0;
}
```
::::
:::

---

## Cadenas Recursivas

(ej_b3_c07_09)=
### Ejercicio 3.07.09 - Palíndromo ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_09_palindromo

Determiná si una secuencia de caracteres es un palíndromo comprobando los
extremos y llamando recursivamente al segmento interno.

```c
bool es_palindromo_rec(const char *inicio, const char *fin);
```

**Tabla de Vectores de Prueba:**

| Cadena | `inicio` / `fin` | Resultado Esperado |
| :--- | :--- | :--- |
| `"neuquen"` | Punteros a `'n'` y `'n'` | `true` |
| `"radar"` | Punteros a `'r'` y `'r'` | `true` |
| `"caterpillar"` | Punteros a `'c'` y `'r'` | `false` |
| `""` | `inicio > fin` | `true` |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool es_palindromo_rec(const char *inicio, const char *fin) {
    if (inicio >= fin) {
        return true;
    }
    if (*inicio != *fin) {
        return false;
    }
    return es_palindromo_rec(inicio + 1, fin - 1);
}

static bool verificar_palindromo(const char *str) {
    size_t len = strlen(str);
    if (len == 0) {
        return true;
    }
    return es_palindromo_rec(str, str + len - 1);
}

int main(void) {
    assert(verificar_palindromo(""));
    assert(verificar_palindromo("a"));
    assert(verificar_palindromo("neuquen"));
    assert(verificar_palindromo("radar"));
    assert(!verificar_palindromo("caterpillar"));
    assert(!verificar_palindromo("hola"));
    return 0;
}
```
::::
:::

(ej_b3_c07_10)=
## Ejercicio 3.07.10 - Factorial Recursivo ⭐☆☆☆☆

Implementá factorial de forma recursiva.

**Orientación:**
- Caso base: `n <= 1` retorna 1
- Caso recursivo: `n * factorial(n-1)`
- Limitación: rápido overflow para n grande

---

(ej_b3_c07_11)=
## Ejercicio 3.07.11 - Potencia Recursiva ⭐⭐☆☆☆

Calculá base^exponente recursivamente.

**Orientación:**
- Caso base: `exp == 0` retorna 1
- Caso recursivo: `base * potencia(base, exp-1)`
- Versión mejorada (siguiente ejercicio)

---

(ej_b3_c07_12)=
### Ejercicio 3.07.12 - Potencia Rápida por Divide y Vencerás ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c07_12_potencia_rapida

Optimizá el cómputo de la potencia entera aplicando el paradigma de divide y conquista:
- Si el exponente `exp == 0`, el resultado es `1ULL`.
- Si `exp` es par: `potencia_rapida(base, exp) = potencia_rapida(base * base, exp / 2)`.
- Si `exp` es impar: `potencia_rapida(base, exp) = base * potencia_rapida(base, exp - 1)`.

```c
unsigned long long potencia_rapida_rec(unsigned long long base, unsigned int exp);
```

La complejidad temporal resultante es $O(\log_2 \text{exp})$ en lugar de $O(\text{exp})$.

**Tabla de Vectores de Prueba:**

| Base | Exponente | Salida Esperada | Justificación |
| :--- | :--- | :--- | :--- |
| `2` | `0` | `1ULL` | Caso base exponente 0 |
| `2` | `10` | `1024ULL` | $2^{10} = 1024$ |
| `3` | `5` | `243ULL` | $3^5 = 243$ |
| `10` | `4` | `10000ULL` | $10^4 = 10000$ |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned long long potencia_rapida_rec(unsigned long long base, unsigned int exp) {
    if (exp == 0) {
        return 1ULL;
    }
    if (exp % 2 == 0) {
        return potencia_rapida_rec(base * base, exp / 2);
    }
    return base * potencia_rapida_rec(base, exp - 1);
}

int main(void) {
    assert(potencia_rapida_rec(2, 0) == 1ULL);
    assert(potencia_rapida_rec(5, 1) == 5ULL);
    assert(potencia_rapida_rec(2, 10) == 1024ULL);
    assert(potencia_rapida_rec(3, 5) == 243ULL);
    assert(potencia_rapida_rec(10, 4) == 10000ULL);
    return 0;
}
```
::::
:::

(ej_b3_c07_13)=
### Ejercicio 3.07.13 - Suma Recursiva de Dígitos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c07_13_suma_digitos

Implementá una función pura que sume los dígitos de un entero no negativo de forma recursiva:
- Caso base: si $n < 10$, retorna $n$.
- Paso recursivo: $(n \pmod{10}) + \text{suma\_digitos\_rec}(n / 10)$.

```c
unsigned int suma_digitos_rec(unsigned long long n);
```

**Tabla de Vectores de Prueba:**

| Entrada $n$ | Descomposición | Retorno Esperado |
| :--- | :--- | :--- |
| `0` | Caso base | `0` |
| `7` | Caso base | `7` |
| `12345` | $5 + 4 + 3 + 2 + 1$ | `15` |
| `999` | $9 + 9 + 9$ | `27` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

unsigned int suma_digitos_rec(unsigned long long n) {
    if (n < 10ULL) {
        return (unsigned int)n;
    }
    return (unsigned int)(n % 10ULL) + suma_digitos_rec(n / 10ULL);
}

int main(void) {
    assert(suma_digitos_rec(0) == 0);
    assert(suma_digitos_rec(7) == 7);
    assert(suma_digitos_rec(12345) == 15);
    assert(suma_digitos_rec(999) == 27);
    return 0;
}
```
::::
:::

(ej_b3_c07_14)=
## Ejercicio 3.07.14 - Invertir String ⭐⭐☆☆☆

Invertí un string recursivamente.

**Orientación:**
- Caso base: string vacío o de 1 carácter
- Caso recursivo: último carácter + invertir(resto)
- Pensá en índices: `invertir(str, inicio, fin)`

---

(ej_b3_c07_15)=
## Ejercicio 3.07.15 - Fibonacci Recursivo ⭐⭐⭐☆☆

Calculá el n-ésimo número de Fibonacci.

**Orientación:**
- Caso base: `n <= 1` retorna n
- Caso recursivo: `fib(n-1) + fib(n-2)`
- **Advertencia:** Muy ineficiente (exponencial) para n grande

---

(ej_b3_c07_16)=
## Ejercicio 3.07.16 - Fibonacci con Memoización ⭐⭐⭐⭐☆

Optimizá Fibonacci usando memoización (caché de resultados).

**Orientación:**
- Array global `memo[MAX]` inicializado en -1
- Antes de calcular: `if (memo[n] != -1) return memo[n]`
- Después de calcular: `memo[n] = resultado`
- Complejidad: de O(2^n) a O(n)

---

(ej_b3_c07_17)=
## Ejercicio 3.07.17 - Suma de Array ⭐⭐☆☆☆

Sumá elementos de un array recursivamente.

**Orientación:**
- Caso base: array vacío (`n == 0`) retorna 0
- Caso recursivo: `arr[0] + suma(arr+1, n-1)`
- O con índices: `arr[i] + suma(arr, i+1, n)`

---

(ej_b3_c07_18)=
## Ejercicio 3.07.18 - Búsqueda Binaria Recursiva ⭐⭐⭐☆☆

Implementá búsqueda binaria de forma recursiva.

**Orientación:**
- Caso base: rango vacío (`inicio > fin`) retorna -1
- Calcular `medio = (inicio + fin) / 2`
- Si `arr[medio] == objetivo`: retornar medio
- Si `arr[medio] > objetivo`: buscar en mitad izquierda
- Si `arr[medio] < objetivo`: buscar en mitad derecha

---

(ej_b3_c07_19)=
## Ejercicio 3.07.19 - Máximo en Array ⭐⭐⭐☆☆

Encontrá el máximo de un array recursivamente.

**Orientación:**
- Caso base: array de 1 elemento retorna ese elemento
- Caso recursivo: `max(arr[0], maximo(arr+1, n-1))`
- Divide y conquista: dividir en mitades y comparar máximos

---

(ej_b3_c07_20)=
## Ejercicio 3.07.20 - Palíndromo Recursivo ⭐⭐⭐☆☆

Verificá si un string es palíndromo recursivamente.

**Orientación:**
- Caso base: string vacío o de 1 carácter: true
- Comparar primer y último carácter
- Si iguales: recursión en substring sin extremos
- Si diferentes: false

---

(ej_b3_c07_21)=
## Ejercicio 3.07.21 - Torre de Hanoi ⭐⭐⭐⭐☆

Resolvé el problema de la Torre de Hanoi.

**Reglas:**
- Mover N discos de origen a destino usando auxiliar
- Solo un disco a la vez
- Nunca poner disco grande sobre uno pequeño

**Orientación:**

```{code-block} c
:linenos:
void hanoi(int n, char origen, char destino, char auxiliar)
{
    if (n == 1)
    {
        mover(origen, destino);
    }
    else
    {
        hanoi(n - 1, origen, auxiliar, destino);
        mover(origen, destino);
        hanoi(n - 1, auxiliar, destino, origen);
    }
}
```
<!-- {code-block} c -->

---

(ej_b3_c07_22)=
## Ejercicio 3.07.22 - Permutaciones ⭐⭐⭐⭐⭐

Generá todas las permutaciones de un string.

**Orientación:**
- Para cada posición, probá cada carácter restante
- Intercambiá carácter actual con cada uno de los siguientes
- Recursión en resto del string
- Al retornar, deshacé el intercambio (backtracking)

---

(ej_b3_c07_23)=
## Ejercicio 3.07.23 - Subconjuntos (Power Set) ⭐⭐⭐⭐⭐

Generá todos los subconjuntos de un conjunto.

**Orientación:**
- Para cada elemento: está o no está en el subconjunto
- Dos llamadas recursivas: con elemento y sin elemento
- Caso base: conjunto vacío
- Total: 2^n subconjuntos

---

(ej_b3_c07_24)=
## Ejercicio 3.07.24 - MergeSort ⭐⭐⭐⭐⭐

Implementá ordenamiento MergeSort.

**Algoritmo:**
1. Dividir array en dos mitades
2. Ordenar recursivamente cada mitad
3. Fusionar (merge) las mitades ordenadas

**Orientación:**
- Caso base: array de 0 o 1 elemento
- Función auxiliar `merge` para fusionar
- Complejidad: O(n log n)

---

(ej_b3_c07_25)=
## Ejercicio 3.07.25 - QuickSort ⭐⭐⭐⭐⭐

Implementá ordenamiento QuickSort.

**Algoritmo:**
1. Elegir pivote
2. Particionar: menores a izquierda, mayores a derecha
3. Ordenar recursivamente cada partición

**Orientación:**
- Caso base: array de 0 o 1 elemento
- Función `particionar` retorna posición del pivote
- Complejidad promedio: O(n log n)

---

(ej_b3_c07_26)=
## Ejercicio 3.07.26 - N Reinas ⭐⭐⭐⭐⭐

Resolvé el problema de las N reinas (colocar N reinas en tablero N×N sin que se
ataquen).

**Orientación:**
- Colocá reina fila por fila
- Para cada fila, probá cada columna
- Verificá si la posición es segura (no ataca a otras)
- Si llegás a la última fila: solución encontrada
- Backtracking si no hay posición válida

---

(ej_b3_c07_27)=
## Ejercicio 3.07.27 - Laberinto (Path Finding) ⭐⭐⭐⭐⭐

Encontrá camino en un laberinto desde inicio a fin.

**Orientación:**
- Matriz de 0s (libre) y 1s (pared)
- Desde posición actual, probá 4 direcciones (arriba, abajo, izq, der)
- Marcá visitados para evitar ciclos
- Si llegás a destino: true
- Backtracking: desmarcá visitado al retornar

---

(ej_b3_c07_28)=
## Ejercicio 3.07.28 - Combinaciones (n choose k) ⭐⭐⭐⭐⭐

Generá todas las combinaciones de k elementos de un conjunto de n.

**Orientación:**
- Elegir elemento actual o no elegirlo
- Si elegís: k-1 elementos restantes
- Si no elegís: k elementos de n-1 restantes
- Caso base: k==0 (solución completa) o n<k (imposible)

---

(ej_b3_c07_29)=
## Ejercicio 3.07.29 - Sudoku Solver ⭐⭐⭐⭐⭐

Resolvé un Sudoku usando backtracking.

**Orientación:**
- Encontrá primera celda vacía
- Probá números del 1 al 9
- Para cada número, verificá si es válido (fila, columna, subcuadro 3×3)
- Si válido: colocá número, recursión en siguiente celda
- Si recursión falla: deshacé (backtracking), probá siguiente número
- Caso base: no hay celdas vacías (solución encontrada)

---

(ej_b3_c07_30)=
## Ejercicio 3.07.30 - s Adicionales ⭐⭐☆☆☆

(ej_b3_c07_31)=
### Ejercicio 3.07.31 - Coeficiente Binomial ⭐⭐⭐☆☆

Calculá C(n,k) = n! / (k! × (n-k)!) recursivamente.

**Orientación:**
- Identidad de Pascal: `C(n,k) = C(n-1,k-1) + C(n-1,k)`
- Casos base: `C(n,0) = 1`, `C(n,n) = 1`

---

(ej_b3_c07_32)=
### Ejercicio 3.07.32 - GCD (MCD) Recursivo ⭐⭐☆☆☆

Implementá algoritmo de Euclides recursivamente.

**Orientación:**
- Caso base: `b == 0` retorna a
- Caso recursivo: `gcd(b, a % b)`

---

(ej_b3_c07_33)=
### Ejercicio 3.07.33 - Árbol de Expresión ⭐⭐⭐⭐⭐

Evaluá una expresión matemática representada como árbol binario.

**Orientación:**
- Nodos hoja: números
- Nodos internos: operadores (+, -, *, /)
- Evaluación postorden: evaluar izquierdo, derecho, aplicar operador

---

## Notas Finales

:::{tip} Anatomía de una Función Recursiva

1. **Caso(s) Base:** Condición de terminación
2. **Caso Recursivo:** Llamada a sí misma con problema más pequeño
3. **Convergencia:** Cada llamada debe acercar al caso base

```{code-block} c
:linenos:
int funcion_recursiva(parametros)
{
    // 1. Caso base
    if (condicion_terminacion)
    {
        return valor_base;
    }
    // 2. Caso recursivo
    // Procesar actual
    // Llamada recursiva con problema reducido
    return combinar(procesar_actual, funcion_recursiva(problema_mas_pequeno));
}
```
<!-- {code-block} c -->

:::
<!-- {tip} Anatomía de una Función Recursiva -->

:::{warning} Peligros de la Recursión

1. **Stack Overflow:**
   - Recursión muy profunda consume toda la pila
   - Límite típico: ~1000-10000 llamadas
   - Solución: iteración o tail recursion

2. **Duplicación de Trabajo:**
   - Fibonacci naive: recalcula subproblemas
   - Solución: memoización o programación dinámica

3. **Overhead:**
   - Cada llamada tiene costo (guardar estado)
   - Para problemas simples, iteración es más eficiente

4. **Difícil de Debuggear:**
   - Stack trace largo y confuso
   - Usá prints para ver qué está pasando

:::
<!-- {warning} Peligros de la Recursión -->

:::{note} Tipos de Recursión

**Recursión Simple:**
``` c
int suma(int n)
{
    if (n == 0)
        return 0;
    return n + suma(n - 1); // Una llamada recursiva
}
```
<!-- c -->

**Recursión Múltiple:**
``` c
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // Dos llamadas
}
```
<!-- c -->

**Recursión de Cola (Tail Recursion):**
``` c
int suma_tail(int n, int acumulador)
{
    if (n == 0)
        return acumulador;
    return suma_tail(n - 1, acumulador + n); // Llamada al final
}
// Puede optimizarse a lazo por el compilador
```
<!-- c -->

**Recursión Mutua:**
```{code-block} c
:linenos:
bool es_par(int n);
bool es_impar(int n);
bool es_par(int n)
{
    if (n == 0)
        return true;
    return es_impar(n - 1);
}
bool es_impar(int n)
{
    if (n == 0)
        return false;
    return es_par(n - 1);
}
```
<!-- {code-block} c -->

:::
<!-- {note} Tipos de Recursión -->

:::{tip} Divide y Conquista

Patrón común en recursión:

1. **Divide:** Partir problema en subproblemas
2. **Conquista:** Resolver subproblemas recursivamente
3. **Combina:** Unir soluciones de subproblemas

**Ejemplos:**
- MergeSort: dividir array, ordenar mitades, fusionar
- QuickSort: particionar, ordenar particiones
- Búsqueda binaria: dividir rango, buscar en mitad apropiada

**Complejidad típica:** O(n log n) para n elementos

:::
<!-- {tip} Divide y Conquista -->

:::{note} Recursión vs Iteración

| Aspecto | Recursión | Iteración |
|---------|-----------|-----------|
| Claridad | Más natural para problemas recursivos | Puede ser más verbosa |
| Memoria | Usa stack (limitado) | Usa variables locales |
| Velocidad | Overhead de llamadas | Generalmente más rápida |
| Debugging | Más difícil | Más fácil |

**Cuándo usar recursión:**
- Problema naturalmente recursivo (árboles, grafos)
- Código más claro y conciso
- Profundidad manejable

**Cuándo usar iteración:**
- Muchas iteraciones (riesgo de stack overflow)
- Performance crítica
- Problema naturalmente iterativo

:::
<!-- {note} Recursión vs Iteración -->

:::{tip} Optimización con Memoización

**Patrón:**
```{code-block} c
:linenos:
#define MAX 1000
int memo[MAX];
void inicializar()
{
    for (int i = 0; i < MAX; i++)
        memo[i] = -1;
}
int funcion(int n)
{
    if (n <= caso_base)
        return valor_base;
    if (memo[n] != -1)
        return memo[n];    // Ya calculado
    memo[n] = calcular(n); // Calcular y cachear
    return memo[n];
}
```
<!-- {code-block} c -->

**Ventaja:** Evita recalcular subproblemas
**Ejemplo:** Fibonacci de O(2^n) a O(n)

:::
<!-- {tip} Optimización con Memoización -->

Estas consignas cubren desde recursión básica hasta algoritmos avanzados de
backtracking y divide y conquista, desarrollando pensamiento recursivo esencial.

