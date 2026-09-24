---
title: Ejercicios de Análisis de Complejidad Algorítmica
short_title: 10. Complejidad
---

# Ejercicios de Análisis de Complejidad Algorítmica

## Prerrequisitos y Entorno de Ejecución Requerido

Para compilar y verificar las soluciones de este módulo bajo el estándar C11 estricto de cátedra, se requiere:
- **Compilador C11:** GCC 9+ o Clang 11+ configurado con flags `-Wall -Wextra -Werror -pedantic -std=c11`.
- **Entorno POSIX:** Linux o WSL con utilidades estándar, soporte de medición temporal y estructuras de control.
- **Herramientas de Verificación:** Valgrind (memcheck) y AddressSanitizer (`-fsanitize=address,undefined`) para garantizar la ausencia de desbordamientos y verificar instrumentaciones empíricas.
- **Conocimientos Previos:** Notación asintótica Big-O, $\Omega$ y $\Theta$, conteo de pasos en lazos iterativos y llamadas recursivas, y estructuras de datos básicas.

## Objetivos Pedagógicos y Competencias (Taxonomía de Bloom)

- **Nivel 2 (Comprensión):** Clasificar algoritmos según su orden asintótico y comparar funciones de crecimiento temporal y espacial.
- **Nivel 3 (Aplicación):** Instrumentar empíricamente algoritmos en C11 para contrastar conteo de pasos teóricos vs reales.
- **Nivel 4 (Análisis):** Evaluar complejidades en mejor, peor y caso promedio en algoritmos de búsqueda, ordenamiento y recursión.
- **Andamiaje Progresivo:** Ejercicios andamiados con contratos formales (precondiciones/postcondiciones), tablas de vectores de prueba y suites ejecutables con `assert()`.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-complejidad`

### Cuestiones de Estilo Aplicables
- **Medición e instrumentación:** Al implementar análisis empíricos, utilizá la biblioteca `<time.h>` o contadores enteros explícitos para auditar iteraciones sin alterar la estructura algorítmica principal del código evaluado.

---

## Fundamentos de Notación Asintótica

(ej_b3_c06_01)=
### Ejercicio 3.06.01 - Simplificación de Funciones ⭐⭐☆☆☆

Para cada función de costo, determinar su clasificación en notación Big-O
(ignorando constantes y términos de menor orden):
a) $T(n) = 5n^3 + 2n^2 + 100$  
b) $T(n) = 3n \log n + 2n + 50$  
c) $T(n) = 2^n + n^3 + 1000n$  
d) $T(n) = \log(n^2) + \sqrt{n}$  
e) $T(n) = n! + 2^n + n^{10}$

(ej_b3_c06_02)=
### Ejercicio 3.06.02 - Comparación de Funciones ⭐⭐☆☆☆

Ordenar las siguientes funciones de menor a mayor tasa de crecimiento
asintótico:
$$\log n, \quad n^2, \quad 2^n, \quad n!, \quad n \log n, \quad \sqrt{n}, \quad n^3, \quad 1, \quad n \log^2 n, \quad 2^{2n}$$

(ej_b3_c06_03)=
### Ejercicio 3.06.03 - Verdadero o Falso ⭐⭐☆☆☆

Determinar si las siguientes afirmaciones son verdaderas o falsas. Justificar.
a) $n^2 + n = O(n^2)$  
b) $n^2 = O(n^3)$  
c) $n^3 = O(n^2)$  
d) $2^n = O(3^n)$  
e) $3^n = O(2^n)$  
f) $\log_2 n = O(\log_{10} n)$  
g) $n \log n = O(n^2)$  
h) $n^2 = \Omega(n \log n)$

(ej_b3_c06_04)=
### Ejercicio 3.06.04 - Demostración Formal de Big-O ⭐⭐☆☆☆

Demostrar formalmente que $f(n) = 3n^2 + 5n + 2$ es $O(n^2)$ encontrando
constantes $c$ y $n_0$ que satisfagan la definición.

---

## Análisis de Lazos Simples

(ej_b3_c06_05)=
### Ejercicio 3.06.05 - Instrumentación de Lazo Lineal y Logarítmico ⭐☆☆☆☆

:::{exercise}
:label: ej_b3_c06_05_instrumentacion_lazos

Implementá funciones instrumentadas que midan exactamente el número de iteraciones ejecutadas:
1. `size_t iteraciones_lazo_lineal(size_t n)`: ejecuta un lazo `for (size_t i = 0; i < n; i++)` y retorna el conteo ($O(n)$).
2. `size_t iteraciones_lazo_logaritmico(size_t n)`: ejecuta un lazo `for (size_t i = 1; i < n; i *= 2)` y retorna el conteo ($O(\log n)$).

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Valor $n$ | `iteraciones_lazo_lineal` | `iteraciones_lazo_logaritmico` |
| :--- | :--- | :--- | :--- |
| Nulo | `0` | `0` | `0` |
| Unitario | `1` | `1` | `0` |
| Potencia de 2 | `8` | `8` | `3` (i=1,2,4) |
| Potencia de 2 | `16` | `16` | `4` (i=1,2,4,8) |
| Escalar 1000 | `1000` | `1000` | `10` ($2^9 < 1000 \le 2^{10}$) |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t iteraciones_lazo_lineal(size_t n) {
    size_t contador = 0;
    for (size_t i = 0; i < n; ++i) {
        contador++;
    }
    return contador;
}

size_t iteraciones_lazo_logaritmico(size_t n) {
    if (n <= 1) {
        return 0;
    }
    size_t contador = 0;
    for (size_t i = 1; i < n; i *= 2) {
        contador++;
    }
    return contador;
}

int main(void) {
    assert(iteraciones_lazo_lineal(0) == 0);
    assert(iteraciones_lazo_lineal(1) == 1);
    assert(iteraciones_lazo_lineal(8) == 8);
    assert(iteraciones_lazo_lineal(1000) == 1000);

    assert(iteraciones_lazo_logaritmico(0) == 0);
    assert(iteraciones_lazo_logaritmico(1) == 0);
    assert(iteraciones_lazo_logaritmico(8) == 3);
    assert(iteraciones_lazo_logaritmico(16) == 4);
    assert(iteraciones_lazo_logaritmico(1000) == 10);

    return 0;
}
```
::::
:::

(ej_b3_c06_08)=
### Ejercicio 3.06.08 - Lazo con División Sucesiva ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c06_08_lazo_division

Implementá una función que simule y cuantifique el número de iteraciones realizadas por un lazo con reducción por división entera a la mitad:

```c
size_t contar_divisiones_sucesivas(size_t n);
```

El lazo inicializa `i = n` y en cada paso efectúa `i /= 2` mientras `i > 1`.
Determiná formalmente su complejidad asintótica ($O(\log_2 n)$).

**Tabla de Vectores de Prueba:**

| Entrada $n$ | Secuencia de Valores de $i$ | Conteo de Iteraciones |
| :--- | :--- | :--- |
| `0` | Ninguno ($n \le 1$) | `0` |
| `1` | Ninguno ($n \le 1$) | `0` |
| `2` | $i=2$ | `1` |
| `16` | $i=16, 8, 4, 2$ | `4` |
| `32` | $i=32, 16, 8, 4, 2$ | `5` |
| `1024` | $i=1024, \dots, 2$ | `10` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t contar_divisiones_sucesivas(size_t n) {
    size_t contador = 0;
    for (size_t i = n; i > 1; i /= 2) {
        contador++;
    }
    return contador;
}

int main(void) {
    assert(contar_divisiones_sucesivas(0) == 0);
    assert(contar_divisiones_sucesivas(1) == 0);
    assert(contar_divisiones_sucesivas(2) == 1);
    assert(contar_divisiones_sucesivas(16) == 4);
    assert(contar_divisiones_sucesivas(32) == 5);
    assert(contar_divisiones_sucesivas(1024) == 10);
    return 0;
}
```
::::
:::

(ej_b3_c06_09)=
## Ejercicio 3.06.09 - Contar Operaciones ⭐☆☆☆☆

Contá cuántas operaciones ejecuta este código:

``` c
int suma = 0;
for (int i = 0; i < n; i++)
{
    suma += i;
}
```
<!-- c -->

**Orientación:**
- Inicialización: 1
- Comparación en lazo: n+1
- Incremento: n
- Suma: n
- Total: ~3n + 2 operaciones
- **Complejidad:** O(n)

---

(ej_b3_c06_10)=
### Ejercicio 3.06.10 - Instrumentación de Lazo Anidado Cuadrático ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c06_10_lazo_cuadratico

Implementá una función que instrumente y verifique empíricamente el conteo total de pasos de un lazo doblemente anidado:
```c
size_t contar_iteraciones_cuadraticas(size_t n);
```
El lazo recorre $i$ de $0$ a $n-1$ y $j$ de $0$ a $n-1$, demostrando que la complejidad es $O(n^2)$.

**Tabla de Vectores de Prueba:**

| Valor $n$ | Total de Pasos ($n \times n$) | Complejidad |
| :--- | :--- | :--- |
| `0` | `0` | Caso nulo |
| `1` | `1` | $1^2 = 1$ |
| `5` | `25` | $5^2 = 25$ |
| `100` | `10000` | $100^2 = 10000$ |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t contar_iteraciones_cuadraticas(size_t n) {
    size_t pasos = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            pasos++;
        }
    }
    return pasos;
}

int main(void) {
    assert(contar_iteraciones_cuadraticas(0) == 0);
    assert(contar_iteraciones_cuadraticas(1) == 1);
    assert(contar_iteraciones_cuadraticas(5) == 25);
    assert(contar_iteraciones_cuadraticas(100) == 10000);
    return 0;
}
```
::::
:::

(ej_b3_c06_11)=
### Ejercicio 3.06.11 - Comparación Empírica de Pasos: Búsqueda Lineal vs Binaria ⭐⭐☆☆☆

:::{exercise}
:label: ej_b3_c06_11_comparar_busquedas
:enumerator: complejidad-11

Implementá una función instrumentada que compare la cantidad de comparaciones elementales efectuadas por una búsqueda lineal frente a una búsqueda binaria sobre un mismo arreglo ordenado:
```c
typedef struct {
    size_t pasos_lineal;
    size_t pasos_binaria;
} comparacion_busqueda_t;

comparacion_busqueda_t comparar_pasos_busqueda(const int *arr, size_t n, int objetivo);
```
- **Búsqueda lineal:** Recorre secuencialmente desde el índice $0$; por cada elemento compara si es igual al objetivo e incrementa `pasos_lineal`. Si coincide o si `arr[i] > objetivo` (cortocircuito para arreglo ordenado), se detiene.
- **Búsqueda binaria:** Inicializa ventana `[izq, der]`. En cada iteración donde `izq <= der`, incrementa `pasos_binaria`, calcula `medio` y compara con `objetivo`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Conteo de operaciones clave, divergencia asintótica $O(N)$ vs $O(\log_2 N)$.  
**Techo conceptual:** El arreglo debe estar estrictamente ordenado de menor a mayor.

#### Contrato de la Función
- **Firma:** `comparacion_busqueda_t comparar_pasos_busqueda(const int *arr, size_t n, int objetivo);`
- **Precondiciones:** Arreglo ordenado. Si $n > 0$, `arr != NULL`.
- **Postcondiciones:** Retorna una estructura con el total de comparaciones realizadas por ambos algoritmos.

#### Tabla de Vectores de Prueba

| Arreglo ($n=16$) | Objetivo | Pasos Lineal | Pasos Binaria | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| `0, 1, 2, ..., 15` | `0` | `1` | $\le 4$ | Mejor caso para búsqueda lineal |
| `0, 1, 2, ..., 15` | `15` | `16` | $\le 4$ | Peor caso lineal ($O(N)$) vs acotado logarítmico |
| `0, 1, 2, ..., 15` | `99` (ausente) | `16` | $\le 5$ | Ausencia demostrada con ratio $N / \log_2 N$ |
| Vacío ($n=0$) | `42` | `0` | `0` | Caso base sin ejecuciones |

:::

::::{solution} ej_b3_c06_11_comparar_busquedas
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

typedef struct
{
    size_t pasos_lineal;
    size_t pasos_binaria;
} comparacion_busqueda_t;

comparacion_busqueda_t comparar_pasos_busqueda(const int *arr, size_t n, int objetivo)
{
    comparacion_busqueda_t resultado = {0, 0};
    if (arr == NULL || n == 0)
    {
        return resultado;
    }

    // 1. Conteo en búsqueda lineal (con poda por orden)
    for (size_t i = 0; i < n; i++)
    {
        resultado.pasos_lineal++;
        if (arr[i] >= objetivo)
        {
            break;
        }
    }

    // 2. Conteo en búsqueda binaria
    size_t izq = 0;
    size_t der = n - 1;

    while (izq <= der)
    {
        resultado.pasos_binaria++;
        size_t medio = izq + (der - izq) / 2;

        if (arr[medio] == objetivo)
        {
            break;
        }
        if (arr[medio] < objetivo)
        {
            izq = medio + 1;
        }
        else
        {
            if (medio == 0)
            {
                break;
            }
            der = medio - 1;
        }
    }

    return resultado;
}

int main(void)
{
    int arr[16];
    for (int i = 0; i < 16; i++)
    {
        arr[i] = i * 2; // {0, 2, 4, ..., 30}
    }

    // Primer elemento: lineal 1 paso
    comparacion_busqueda_t c1 = comparar_pasos_busqueda(arr, 16, 0);
    assert(c1.pasos_lineal == 1);
    assert(c1.pasos_binaria <= 4);

    // Último elemento: lineal 16 pasos, binaria <= 4
    comparacion_busqueda_t c2 = comparar_pasos_busqueda(arr, 16, 30);
    assert(c2.pasos_lineal == 16);
    assert(c2.pasos_binaria <= 5);

    // Elemento ausente grande
    comparacion_busqueda_t c3 = comparar_pasos_busqueda(arr, 16, 99);
    assert(c3.pasos_lineal == 16);
    assert(c3.pasos_binaria <= 5);

    // Arreglo vacío
    comparacion_busqueda_t c_vacio = comparar_pasos_busqueda(NULL, 0, 10);
    assert(c_vacio.pasos_lineal == 0 && c_vacio.pasos_binaria == 0);

    return 0;
}
```

::::
<!-- {solution} ej_b3_c06_11_comparar_busquedas -->

---

(ej_b3_c06_29)=
### Ejercicio 3.06.29 - Comparación Empírica de Pasos: Inserción vs Selección ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c06_29_comparar_ordenamientos

A diferencia de la notación asintótica abstracta, la instrumentación empírica permite verificar por qué ciertos algoritmos con la misma complejidad en el peor caso ($O(n^2)$) exhiben eficiencias drásticamente dispares según el estado inicial de los datos.

Definí la estructura:
```c
typedef struct {
    size_t comparaciones;
    size_t movimientos; // Asignaciones o intercambios de elementos
} metricas_sort_t;
```

Implementá dos algoritmos de ordenamiento instrumentados:
1. `metricas_sort_t sort_seleccion_instrumentado(int arr[], size_t n)`:
   - Ordena por Selección contando cada comparación entre elementos y cada swap.
2. `metricas_sort_t sort_insercion_instrumentado(int arr[], size_t n)`:
   - Ordena por Inserción contando cada comparación y cada desplazamiento de elemento hacia la derecha.

Verificá analíticamente y con aserciones que sobre un arreglo **ya ordenado** de tamaño $N=10$:
- Selección realiza exactamente $\frac{10 \times 9}{2} = 45$ comparaciones ($\Theta(n^2)$ incondicional).
- Inserción realiza exactamente $N - 1 = 9$ comparaciones y $0$ desplazamientos ($O(n)$ en el mejor caso).

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Arreglo Inicial ($N=5$) | Algoritmo | Comparaciones | Movimientos / Swaps | Complejidad Observable |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Mejor Caso** | `{1, 2, 3, 4, 5}` | Selección | 10 | 0 | $\Theta(n^2)$ |
| **Mejor Caso** | `{1, 2, 3, 4, 5}` | Inserción | 4 | 0 | $O(n)$ |
| **Peor Caso** | `{5, 4, 3, 2, 1}` | Selección | 10 | 2 | $\Theta(n^2)$ |
| **Peor Caso** | `{5, 4, 3, 2, 1}` | Inserción | 10 | 10 | $O(n^2)$ |

:::
<!-- {exercise} ej_b3_c06_29_comparar_ordenamientos -->

::::{solution} ej_b3_c06_29_comparar_ordenamientos
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

typedef struct {
    size_t comparaciones;
    size_t movimientos;
} metricas_sort_t;

metricas_sort_t sort_seleccion_instrumentado(int arr[], size_t n) {
    metricas_sort_t m = {0, 0};
    if (arr == NULL || n <= 1) {
        return m;
    }

    for (size_t i = 0; i < n - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            m.comparaciones++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
            m.movimientos++;
        }
    }
    return m;
}

metricas_sort_t sort_insercion_instrumentado(int arr[], size_t n) {
    metricas_sort_t m = {0, 0};
    if (arr == NULL || n <= 1) {
        return m;
    }

    for (size_t i = 1; i < n; i++) {
        int clave = arr[i];
        size_t j = i;
        while (j > 0) {
            m.comparaciones++;
            if (arr[j - 1] > clave) {
                arr[j] = arr[j - 1];
                m.movimientos++;
                j--;
            } else {
                break;
            }
        }
        arr[j] = clave;
    }
    return m;
}

int main(void) {
    int ordenado_sel[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ordenado_ins[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    metricas_sort_t m_sel = sort_seleccion_instrumentado(ordenado_sel, 10);
    metricas_sort_t m_ins = sort_insercion_instrumentado(ordenado_ins, 10);

    // Selección en mejor caso es O(n^2): 10 * 9 / 2 = 45 comparaciones
    assert(m_sel.comparaciones == 45);
    assert(m_sel.movimientos == 0);

    // Inserción en mejor caso es O(n): n - 1 = 9 comparaciones y 0 movimientos
    assert(m_ins.comparaciones == 9);
    assert(m_ins.movimientos == 0);

    // Peor caso: arreglo invertido
    int invertido_sel[5] = {5, 4, 3, 2, 1};
    int invertido_ins[5] = {5, 4, 3, 2, 1};

    metricas_sort_t p_sel = sort_seleccion_instrumentado(invertido_sel, 5);
    metricas_sort_t p_ins = sort_insercion_instrumentado(invertido_ins, 5);

    assert(p_sel.comparaciones == 10); // 4 + 3 + 2 + 1
    assert(p_ins.comparaciones == 10);
    assert(p_ins.movimientos == 10);

    // Verificación de estabilidad y orden final
    for (size_t i = 0; i < 4; i++) {
        assert(invertido_sel[i] <= invertido_sel[i + 1]);
        assert(invertido_ins[i] <= invertido_ins[i + 1]);
    }

    return 0;
}
```

::::
<!-- {solution} ej_b3_c06_29_comparar_ordenamientos -->

---

(ej_b3_c06_12)=
## Ejercicio 3.06.12 - Identificar Complejidad ⭐⭐☆☆☆

Determiná la complejidad de cada fragmento:

**a)**

``` c
int suma = 0;
for (int i = 0; i < 100; i++)
{
    suma += i;
}
```
<!-- c -->

**b)**
``` c
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        printf("%d ", i * j);
    }
}
```
<!-- c -->

**c)**
``` c
int i = n;
while (i > 0)
{
    printf("%d ", i);
    i = i / 2;
}
```
<!-- c -->

**Orientación:**
- **a)** O(1) - cantidad fija de iteraciones
- **b)** O(n × m) - depende de dos variables
- **c)** O(log n) - divide por 2 cada vez

---

(ej_b3_c06_13)=
## Ejercicio 3.06.13 - Suma de Matriz ⭐⭐⭐☆☆

Analizá la complejidad de sumar todos los elementos de una matriz n×m.

**Orientación:**

```{code-block} c
:linenos:
int suma = 0;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        suma += matriz[i][j];
    }
}
```
<!-- {code-block} c -->
- Visita cada elemento una vez
- n × m elementos
- **Complejidad:** O(n × m)
- Si n = m: O(n²)

---

(ej_b3_c06_14)=
## Ejercicio 3.06.14 - Fibonacci Naive vs Optimizado ⭐⭐⭐☆☆

Compará complejidad de Fibonacci recursivo vs iterativo.

**Orientación:**
- **Recursivo:**
  ```c
  int fib(int n)
  {
      if (n <= 1)
          return n;
      return fib(n - 1) + fib(n - 2);
  }
  ```
  - Complejidad: O(2ⁿ) - exponencial
  - Árbol de recursión crece exponencialmente

- **Iterativo:**
  ```c
  int fib(int n)
  {
      int a = 0, b = 1, temp;
      for (int i = 0; i < n; i++)
      {
          temp = a + b;
          a = b;
          b = temp;
      }
      return a;
  }
  ```
  - Complejidad: O(n) - lineal

---

(ej_b3_c06_15)=
## Ejercicio 3.06.15 - Búsqueda del Máximo ⭐⭐☆☆☆

Implementá función para encontrar el máximo de un array y analizá su
complejidad.

**Orientación:**

```{code-block} c
:linenos:
int maximo(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
```
<!-- {code-block} c -->
- Recorre array una vez
- **Tiempo:** O(n)
- **Espacio:** O(1) - solo una variable

---

(ej_b3_c06_16)=
### Ejercicio 3.06.16 - Detección de Duplicados: Fuerza Bruta Cuadrática vs Ordenamiento Linealítmico ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b3_c06_16_duplicados

Compará analítica y empíricamente dos paradigmas para determinar si un arreglo contiene elementos repetidos:
1. **Fuerza bruta ($O(n^2)$):** Compara cada elemento con todos los subsiguientes. En ausencia de duplicados (peor caso), realiza exactamente $\frac{n(n-1)}{2}$ comparaciones.
2. **Ordenamiento previo ($O(n \log n)$):** Ordena el arreglo con `qsort` y luego verifica adyacentes en una única pasada lineal de $n-1$ comparaciones.

Implementá ambas funciones instrumentando el conteo de comparaciones:
- `bool tiene_duplicados_cuadratico(const int arr[], size_t n, size_t *comps);`
- `bool tiene_duplicados_ordenado(int arr[], size_t n, size_t *comps);`

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Arreglo ($n=5$) | Duplicados | Comparaciones Fuerza Bruta | Complejidad Observada |
| :--- | :--- | :--- | :--- | :--- |
| **Peor Caso (Sin Duplicados)** | `{10, 20, 30, 40, 50}` | `false` | Exactamente $10$ ($5 \times 4 / 2$) | $\Theta(n^2)$ |
| **Mejor Caso (Duplicado al inicio)**| `{10, 10, 20, 30, 40}` | `true` | Exactamente $1$ | $O(1)$ |
| **Duplicado al final** | `{1, 2, 3, 4, 4}` | `true` | Exactamente $10$ | $\Theta(n^2)$ |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool tiene_duplicados_cuadratico(const int arr[], size_t n, size_t *comps) {
    if (comps != NULL) {
        *comps = 0;
    }
    if (arr == NULL || n <= 1) {
        return false;
    }

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (comps != NULL) {
                (*comps)++;
            }
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

static int comp_enteros(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    return (val_a > val_b) - (val_a < val_b);
}

bool tiene_duplicados_ordenado(int arr[], size_t n, size_t *comps) {
    if (comps != NULL) {
        *comps = 0;
    }
    if (arr == NULL || n <= 1) {
        return false;
    }

    qsort(arr, n, sizeof(int), comp_enteros);

    for (size_t i = 0; i < n - 1; i++) {
        if (comps != NULL) {
            (*comps)++;
        }
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main(void) {
    size_t c = 0;

    // Peor caso: sin duplicados
    int sin_dup[5] = {10, 20, 30, 40, 50};
    assert(tiene_duplicados_cuadratico(sin_dup, 5, &c) == false);
    assert(c == 10); // 4 + 3 + 2 + 1 = 10

    // Mejor caso cuadrático: duplicado inmediato
    int dup_inicio[5] = {10, 10, 20, 30, 40};
    assert(tiene_duplicados_cuadratico(dup_inicio, 5, &c) == true);
    assert(c == 1);

    // Método con ordenamiento previo
    int desordenado[5] = {50, 20, 10, 40, 20};
    assert(tiene_duplicados_ordenado(desordenado, 5, &c) == true);
    assert(c > 0);

    // Arreglo vacío o unitario
    assert(tiene_duplicados_cuadratico(NULL, 0, &c) == false);
    assert(c == 0);

    return 0;
}
```
::::
:::

---

(ej_b3_c06_17)=
## Ejercicio 3.06.17 - Ordenamiento Burbuja ⭐⭐⭐☆☆

Analizá complejidad del ordenamiento burbuja.

**Orientación:**

```{code-block} c
:linenos:
void burbuja(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                intercambiar(&arr[j], &arr[j + 1]);
            }
        }
    }
}
```
<!-- {code-block} c -->
- **Peor caso:** O(n²) - array invertido
- **Mejor caso:** O(n²) - incluso si ya está ordenado (sin optimizar)
- **Optimización:** Agregar flag para detectar si hubo swaps

---

(ej_b3_c06_18)=
## Ejercicio 3.06.18 - Complejidad Espacial ⭐⭐⭐☆☆

Analizá memoria usada por MergeSort.

**Orientación:**

```{code-block} c
:linenos:
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r); // Usa array temporal
    }
}
```
<!-- {code-block} c -->
- Profundidad de recursión: O(log n)
- Array temporal en merge: O(n)
- **Espacio:** O(n) para array + O(log n) para stack de recursión = O(n)

---

(ej_b3_c06_19)=
## Ejercicio 3.06.19 - Suma de Pares ⭐⭐⭐⭐☆

Encontrá dos números en array que sumen un objetivo.

**Método 1:** Fuerza bruta

```{code-block} c
:linenos:
bool suma_objetivo_1(int arr[], int n, int objetivo)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == objetivo)
                return true;
        }
    }
    return false;
}
```
<!-- {code-block} c -->

**Método 2:** Con tabla hash
```{code-block} c
:linenos:
bool suma_objetivo_2(int arr[], int n, int objetivo)
{
    hash_set_t *set = crear_set();
    for (int i = 0; i < n; i++)
    {
        if (contiene(set, objetivo - arr[i]))
        {
            return true;
        }
        insertar(set, arr[i]);
    }
    return false;
}
```
<!-- {code-block} c -->

**Orientación:**
- **Método 1:** O(n²) tiempo, O(1) espacio
- **Método 2:** O(n) tiempo promedio, O(n) espacio
- Trade-off: tiempo por espacio

---

(ej_b3_c06_20)=
## Ejercicio 3.06.20 - Números Primos hasta N ⭐⭐⭐⭐☆

Compará verificar primos uno por uno vs Criba de Eratóstenes.

**Método 1:** Verificar cada número

``` c
// Para cada i de 2 a N:
//   Si es_primo(i): contar
// es_primo: O(√n) por cada número
// Total: O(N × √N)
```
<!-- c -->

**Método 2:** Criba
```{code-block} c
:linenos:
bool *criba(int n)
{
    bool *es_primo = malloc((n + 1) * sizeof(bool));
    // Inicializar todo en true
    for (int i = 2; i * i <= n; i++)
    {
        if (es_primo[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                es_primo[j] = false;
            }
        }
    }
    return es_primo;
}
```
<!-- {code-block} c -->

**Orientación:**
- **Criba:** O(n log log n) tiempo, O(n) espacio
- Mucho más eficiente para rangos grandes

---

(ej_b3_c06_21)=
## Ejercicio 3.06.21 - Subsecuencia Común Más Larga (LCS) ⭐⭐⭐⭐⭐

Analizá complejidad de LCS con programación dinámica.

**Orientación:**

```{code-block} c
:linenos:
int lcs(char *X, char *Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
```
<!-- {code-block} c -->
- **Tiempo:** O(m × n) - llena tabla m×n
- **Espacio:** O(m × n) - tabla DP
- Optimización espacial: O(min(m, n)) con dos filas

---

(ej_b3_c06_22)=
## Ejercicio 3.06.22 - Multiplicación de Matrices ⭐⭐⭐⭐☆

Analizá complejidad de multiplicar dos matrices n×n.

**Orientación:**

```{code-block} c
:linenos:
void multiplicar(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```
<!-- {code-block} c -->
- Tres lazos anidados: n × n × n
- **Complejidad:** O(n³)
- Algoritmos más eficientes existen (Strassen: O(n^2.807))

---

(ej_b3_c06_23)=
## Ejercicio 3.06.23 - Torres de Hanoi ⭐⭐⭐⭐☆

Analizá complejidad de Torres de Hanoi.

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
- Recurrencia: T(n) = 2T(n-1) + 1
- Solución: T(n) = 2ⁿ - 1
- **Complejidad:** O(2ⁿ) - exponencial
- Cantidad mínima de movimientos

---

(ej_b3_c06_24)=
## Ejercicio 3.06.24 - Análisis Amortizado ⭐⭐⭐⭐⭐

Analizá costo amortizado de inserción en vector dinámico con duplicación.

**Orientación:**

```{code-block} c
:linenos:
void agregar(vector_t *v, int elem)
{
    if (v->tamanio == v->capacidad)
    {
        redimensionar(v, v->capacidad * 2); // O(n)
    }
    v->datos[v->tamanio++] = elem; // O(1)
}
```
<!-- {code-block} c -->
- Inserción simple: O(1)
- Redimensionamiento: O(n)
- ¿Cuánto cuesta en promedio?
- **Análisis:** Redimensionar en potencias de 2: n/2 + n/4 + n/8 + ... < n
- **Costo amortizado:** O(1) por inserción

---

(ej_b3_c06_25)=
## Ejercicio 3.06.25 - Comparar Estructuras de Datos ⭐⭐⭐⭐☆

Compará complejidad de operaciones en diferentes estructuras:

| Estructura | Búsqueda | Inserción | Eliminación |
|------------|----------|-----------|-------------|
| Array no ordenado | O(n) | O(1) al final | O(n) |
| Array ordenado | O(log n) | O(n) | O(n) |
| Lista enlazada | O(n) | O(1) al inicio | O(1) con puntero |
| ABB balanceado | O(log n) | O(log n) | O(log n) |
| Hash table | O(1) promedio | O(1) promedio | O(1) promedio |

**Orientación:**
- Elegir estructura según operaciones más frecuentes
- Trade-offs entre tiempo y espacio

---

(ej_b3_c06_26)=
## Ejercicio 3.06.26 - Problema del Viajante (TSP) ⭐⭐⭐⭐⭐

Analizá complejidad de soluciones al TSP.

**Fuerza Bruta:**

``` c
// Probar todas las permutaciones de ciudades
// Cantidad de permutaciones: n!
// Complejidad: O(n!)
```
<!-- c -->

**Programación Dinámica (Held-Karp):**
``` c
// Estado: (ciudades visitadas, ciudad actual)
// Estados: 2ⁿ × n
// Complejidad: O(n² × 2ⁿ)
```
<!-- c -->

**Orientación:**
- Problema NP-completo
- O(n²2ⁿ) sigue siendo exponencial, pero mejor que O(n!)
- Para n=20: 20! ≈ 10¹⁸, 20²·2²⁰ ≈ 10⁹

---

(ej_b3_c06_27)=
## Ejercicio 3.06.27 - Optimización de Caché ⭐⭐⭐⭐⭐

Compará estos dos códigos para sumar matriz:

**Versión 1:**

``` c
for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        suma += M[i][j];
```
<!-- c -->

**Versión 2:**
``` c
for (j = 0; j < N; j++)
    for (i = 0; i < N; i++)
        suma += M[i][j];
```
<!-- c -->

**Orientación:**
- Ambos: O(N²) operaciones
- **Pero:** Versión 1 es más rápida en la práctica
- Razón: Localidad espacial (row-major order en C)
- Versión 1: cache misses ~N²/L
- Versión 2: cache misses ~N²
- L = tamaño de línea de caché

---

(ej_b3_c06_28)=
## Ejercicio 3.06.28 - Medir Empíricamente ⭐⭐⭐⭐⭐

Implementá framework para medir tiempos y validar análisis teórico.

**Orientación:**

```{code-block} c
:linenos:
#include <time.h>
double medir_tiempo(void (*funcion)(int *, int), int *arr, int n)
{
    clock_t inicio = clock();
    funcion(arr, n);
    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}
// Probar con diferentes tamaños
for (int n = 1000; n <= 100000; n *= 2)
{
    double tiempo = medir_tiempo(burbuja, arr, n);
    printf("n=%d, tiempo=%.4f\n", n, tiempo);
}
```
<!-- {code-block} c -->
- Graficar tiempo vs n
- Verificar si crece como n, n log n, n², etc.

---

## Notas Finales

:::{tip} Jerarquía de Complejidades

De mejor a peor:

1. **O(1)** - Constante: acceso a array por índice
2. **O(log n)** - Logarítmica: búsqueda binaria
3. **O(n)** - Lineal: recorrer array
4. **O(n log n)** - Linealítmica: mergesort, quicksort
5. **O(n²)** - Cuadrática: burbuja, selección, dos lazos anidados
6. **O(n³)** - Cúbica: multiplicación de matrices naive
7. **O(2ⁿ)** - Exponencial: subconjuntos, fibonacci naive
8. **O(n!)** - Factorial: permutaciones, TSP brute force

**Escalabilidad:**
- Para n=1,000,000:
  - O(1): 1 operación
  - O(log n): ~20
  - O(n): ~1M
  - O(n log n): ~20M
  - O(n²): ~1T (inmanejable)

:::
<!-- {tip} Jerarquía de Complejidades -->

:::{note} Reglas de Análisis

**Sumar complejidades consecutivas:**
``` c
// O(n) + O(n²) = O(n²)
for (i...)
{
} // O(n)
for (i...) // O(n²)
    for (j...)
    {
    }
```
<!-- c -->

**Multiplicar complejidades anidadas:**
``` c
// O(n) × O(log n) = O(n log n)
for (i...)
{                       // O(n)
    busqueda_binaria(); // O(log n)
}
```
<!-- c -->

**Ignorar constantes y términos menores:**
``` c
// 3n² + 5n + 10 = O(n²)
// n log n + n = O(n log n)
```
<!-- c -->

**Peor caso vs caso promedio:**
- QuickSort: O(n²) peor, O(n log n) promedio
- Hash table: O(n) peor, O(1) promedio

:::
<!-- {note} Reglas de Análisis -->

:::{warning} Errores de Análisis

1. **Olvidar operaciones costosas dentro de lazos:**
   ```c
   for (i...)
   {
       strcpy(dest, src); // O(longitud) no O(1)
   }
   ```

2. **Confundir tiempo con espacio:**
   - Recursión usa espacio en stack
   - Arrays temporales cuentan en espacio

3. **Ignorar constantes ocultas:**
   - O(n) con constante 1000 puede ser peor que O(n²) con constante 0.001 para n
     pequeño

4. **No considerar caso promedio:**
   - QuickSort es O(n²) peor caso pero casi siempre O(n log n)

:::
<!-- {warning} Errores de Análisis -->

Estas consignas desarrollan capacidad de analizar y comparar algoritmos teórica
y empíricamente, esencial para diseñar soluciones eficientes.

