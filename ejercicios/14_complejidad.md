---
title: Ejercicios de Análisis de Complejidad Algorítmica
short_title: 14. Complejidad
---

## Acerca de

Estos ejercicios profundizan en el análisis asintótico de algoritmos, cubriendo las notaciones Big-O, Omega y Theta, análisis de lazos y recursión, el Teorema Maestro, límites inferiores, y técnicas de optimización. El objetivo es desarrollar la capacidad de analizar formalmente la eficiencia de algoritmos y tomar decisiones informadas sobre diseño de software.

## 1: Fundamentos de Notación Asintótica

### 1.1: Simplificación de Funciones

Para cada función de costo, determinar su clasificación en notación Big-O (ignorando constantes y términos de menor orden):

a) $T(n) = 5n^3 + 2n^2 + 100$  
b) $T(n) = 3n \log n + 2n + 50$  
c) $T(n) = 2^n + n^3 + 1000n$  
d) $T(n) = \log(n^2) + \sqrt{n}$  
e) $T(n) = n! + 2^n + n^{10}$

**Objetivo:** Identificar el término dominante en cada expresión.

### 1.2: Comparación de Funciones

Ordenar las siguientes funciones de menor a mayor tasa de crecimiento asintótico:

$$\log n, \quad n^2, \quad 2^n, \quad n!, \quad n \log n, \quad \sqrt{n}, \quad n^3, \quad 1, \quad n \log^2 n, \quad 2^{2n}$$

### 1.3: Verdadero o Falso

Determinar si las siguientes afirmaciones son verdaderas o falsas. Justificar.

a) $n^2 + n = O(n^2)$  
b) $n^2 = O(n^3)$  
c) $n^3 = O(n^2)$  
d) $2^n = O(3^n)$  
e) $3^n = O(2^n)$  
f) $\log_2 n = O(\log_{10} n)$  
g) $n \log n = O(n^2)$  
h) $n^2 = \Omega(n \log n)$

:::{tip} Cambio de Base en Logaritmos
Recordá que $\log_a n = \frac{\log_b n}{\log_b a}$, por lo que logaritmos en diferentes bases difieren solo por una constante multiplicativa, siendo todas $\Theta(\log n)$.
:::

### 1.4: Demostración Formal de Big-O

Demostrar formalmente que $f(n) = 3n^2 + 5n + 2$ es $O(n^2)$ encontrando constantes $c$ y $n_0$ que satisfagan la definición.

**Recordatorio de la definición:** $f(n) = O(g(n))$ si existen $c > 0$ y $n_0 \geq 0$ tales que $0 \leq f(n) \leq c \cdot g(n)$ para todo $n \geq n_0$.

## 2: Análisis de Lazos Simples

### 2.1: Lazo Simple

Analizar la complejidad temporal de este código:

```c
int suma = 0;
for (int i = 0; i < n; i++) {
    suma += i;
}
```

**Preguntas:**
- ¿Cuántas veces se ejecuta el cuerpo del lazo?
- ¿Cuál es la complejidad temporal?

### 2.2: Lazo con Incremento Variable

Analizar la complejidad de:

```c
int suma = 0;
for (int i = 0; i < n; i += 2) {
    suma += i;
}
```

¿Cómo cambia la complejidad comparada con el ejercicio anterior?

### 2.3: Lazo con Multiplicación

Analizar la complejidad de:

```c
int contador = 0;
for (int i = 1; i < n; i *= 2) {
    contador++;
}
```

**Pista:** Pensar en cuántas veces se puede duplicar 1 hasta alcanzar $n$.

### 2.4: Lazo con División

Analizar la complejidad de:

```c
int contador = 0;
for (int i = n; i > 0; i /= 2) {
    contador++;
}
```

¿Es diferente al ejercicio anterior?

## 3: Análisis de Lazos Anidados

### 3.1: Dos Lazos Dependientes

Analizar la complejidad:

```c
int suma = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        suma += i * j;
    }
}
```

**Preguntas:**
- ¿Cuántas veces se ejecuta el cuerpo interno?
- ¿Cuál es la complejidad total?

### 3.2: Lazo Triangular

Analizar la complejidad:

```c
int suma = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        suma += i * j;
    }
}
```

**Análisis detallado:**
- Cuando $i = 0$: el lazo interno ejecuta 0 veces
- Cuando $i = 1$: el lazo interno ejecuta 1 vez
- Cuando $i = 2$: el lazo interno ejecuta 2 veces
- ...
- Total: $0 + 1 + 2 + \ldots + (n-1) = \frac{n(n-1)}{2}$

### 3.3: Triple Lazo Anidado

Analizar la complejidad:

```c
int contador = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            contador++;
        }
    }
}
```

### 3.4: Lazos con Diferentes Límites

Analizar la complejidad:

```c
int suma = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        suma += i + j;
    }
}
```

¿Cómo expresar la complejidad en términos de $n$ y $m$?

## 4: Lazos Logarítmicos

### 4.1: Búsqueda Binaria

Analizar la complejidad de la búsqueda binaria:

```c
int busqueda_binaria(int arr[], int n, int target) {
    int izq = 0, der = n - 1;
    
    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        
        if (arr[medio] == target) {
            return medio;
        } else if (arr[medio] < target) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    
    return -1;
}
```

**Preguntas:**
- ¿Cuántas iteraciones se ejecutan en el peor caso?
- ¿Por qué es $O(\log n)$?

### 4.2: Potenciación Rápida

Analizar la complejidad del algoritmo de exponenciación rápida:

```c
long long potencia_rapida(long long base, int exponente) {
    if (exponente == 0) return 1;
    
    long long mitad = potencia_rapida(base, exponente / 2);
    
    if (exponente % 2 == 0) {
        return mitad * mitad;
    } else {
        return base * mitad * mitad;
    }
}
```

### 4.3: Encontrar el Bit Más Significativo

Analizar la complejidad:

```c
int bit_mas_significativo(int n) {
    int contador = 0;
    while (n > 0) {
        n >>= 1;  // División entera por 2
        contador++;
    }
    return contador;
}
```

## 5: Análisis de Recursión

### 5.1: Factorial Recursivo

Analizar la complejidad temporal y espacial:

```c
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

**Preguntas:**
- ¿Cuántas llamadas recursivas se realizan?
- ¿Cuál es la profundidad de la recursión?
- ¿Cuál es la complejidad espacial (memoria del stack)?

### 5.2: Fibonacci Recursivo Ingenuo

Analizar la complejidad:

```c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

**Análisis del árbol de recursión:**
- Cada llamada genera dos llamadas más
- La profundidad es aproximadamente $n$
- ¿Cuántos nodos hay en el árbol?

:::{warning} Fibonacci Recursivo es Ineficiente
Este algoritmo tiene complejidad exponencial $O(2^n)$. Para $n = 40$ realiza más de mil millones de llamadas. La versión iterativa o con memoización es $O(n)$.
:::

### 5.3: Suma de Arreglo Recursiva

Analizar la complejidad:

```c
int suma_recursiva(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + suma_recursiva(arr, n - 1);
}
```

### 5.4: Torres de Hanoi

Analizar la complejidad del problema clásico:

```c
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco de %c a %c\n", origen, destino);
        return;
    }
    
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco de %c a %c\n", origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}
```

**Recurrencia:** $T(n) = 2T(n-1) + O(1)$

## 6: Teorema Maestro

### 6.1: Aplicación Directa

Para cada recurrencia, aplicar el Teorema Maestro y determinar la complejidad:

**Recordatorio:** Para $T(n) = aT(n/b) + f(n)$ donde $f(n) = \Theta(n^d)$:
- Caso 1: Si $d < \log_b a$, entonces $T(n) = \Theta(n^{\log_b a})$
- Caso 2: Si $d = \log_b a$, entonces $T(n) = \Theta(n^d \log n)$
- Caso 3: Si $d > \log_b a$, entonces $T(n) = \Theta(n^d)$

a) $T(n) = 2T(n/2) + O(n)$ (Merge Sort)  
b) $T(n) = 2T(n/2) + O(1)$ (Búsqueda binaria en árbol)  
c) $T(n) = 4T(n/2) + O(n)$ (Multiplicación de Strassen simplificada)  
d) $T(n) = 3T(n/2) + O(n^2)$  
e) $T(n) = T(n/2) + O(1)$ (Búsqueda binaria)  
f) $T(n) = 2T(n/2) + O(n^2)$

### 6.2: Merge Sort

El algoritmo Merge Sort divide el arreglo en dos mitades, ordena cada mitad recursivamente, y luego las fusiona:

```c
void merge_sort(int arr[], int n) {
    if (n <= 1) return;
    
    int mitad = n / 2;
    merge_sort(arr, mitad);
    merge_sort(arr + mitad, n - mitad);
    merge(arr, mitad, n);  // O(n)
}
```

**Recurrencia:** $T(n) = 2T(n/2) + O(n)$

Aplicar el Teorema Maestro y demostrar que $T(n) = O(n \log n)$.

### 6.3: Búsqueda de Máximo y Mínimo Simultánea

Analizar este algoritmo divide-y-conquista:

```c
void max_min(int arr[], int izq, int der, int* max, int* min) {
    if (izq == der) {
        *max = *min = arr[izq];
        return;
    }
    
    if (der == izq + 1) {
        if (arr[izq] > arr[der]) {
            *max = arr[izq];
            *min = arr[der];
        } else {
            *max = arr[der];
            *min = arr[izq];
        }
        return;
    }
    
    int medio = (izq + der) / 2;
    int max1, min1, max2, min2;
    
    max_min(arr, izq, medio, &max1, &min1);
    max_min(arr, medio + 1, der, &max2, &min2);
    
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}
```

## 7: Jerarquía de Complejidades

### 7.1: Tiempo de Ejecución Estimado

Dada una computadora que ejecuta $10^8$ operaciones por segundo, estimar el tiempo de ejecución para diferentes complejidades y tamaños de entrada:

| Complejidad | n = 10 | n = 100 | n = 1000 | n = 10⁶ |
|-------------|--------|---------|----------|---------|
| $O(1)$      | ?      | ?       | ?        | ?       |
| $O(\log n)$ | ?      | ?       | ?        | ?       |
| $O(n)$      | ?      | ?       | ?        | ?       |
| $O(n \log n)$ | ?    | ?       | ?        | ?       |
| $O(n^2)$    | ?      | ?       | ?        | ?       |
| $O(2^n)$    | ?      | ?       | ?        | N/A     |

**Ejemplo de cálculo:** Para $O(n^2)$ con $n = 1000$:
- Operaciones: $1000^2 = 10^6$
- Tiempo: $10^6 / 10^8 = 0.01$ segundos

### 7.2: Límite Práctico

Para cada complejidad, determinar el tamaño máximo de entrada que puede procesarse en 1 segundo (asumiendo $10^8$ operaciones/segundo):

a) $O(n)$  
b) $O(n \log n)$  
c) $O(n^2)$  
d) $O(n^3)$  
e) $O(2^n)$  
f) $O(n!)$

### 7.3: Comparación de Algoritmos

Tenés dos algoritmos para el mismo problema:
- Algoritmo A: $T_A(n) = 100n$
- Algoritmo B: $T_B(n) = 2n^2$

**Preguntas:**
1. ¿Para qué valores de $n$ es mejor el algoritmo A?
2. ¿Para qué valores es mejor el algoritmo B?
3. ¿Cuál es asintóticamente mejor?

## 8: Análisis de Algoritmos de Búsqueda

### 8.1: Búsqueda Lineal

Analizar los tres casos (mejor, peor, promedio):

```c
int busqueda_lineal(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
```

**Casos:**
- **Mejor caso:** ¿Cuándo ocurre? ¿Complejidad?
- **Peor caso:** ¿Cuándo ocurre? ¿Complejidad?
- **Caso promedio:** Asumiendo distribución uniforme

### 8.2: Búsqueda del Mínimo

Analizar la complejidad:

```c
int encontrar_minimo(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
```

**Pregunta:** ¿Hay diferencia entre mejor y peor caso? ¿Por qué?

### 8.3: Búsqueda de Duplicados

Analizar dos versiones:

**Versión 1: Fuerza bruta**
```c
bool tiene_duplicados_v1(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
```

**Versión 2: Con ordenamiento**
```c
bool tiene_duplicados_v2(int arr[], int n) {
    // Asumir que quick_sort es O(n log n)
    quick_sort(arr, n);
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}
```

¿Cuál es más eficiente asintóticamente?

## 9: Análisis de Algoritmos de Ordenamiento

### 9.1: Bubble Sort

Analizar la complejidad en mejor y peor caso:

```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Optimización
    }
}
```

**Preguntas:**
- **Mejor caso:** Arreglo ya ordenado, ¿cuántas comparaciones?
- **Peor caso:** Arreglo en orden inverso, ¿cuántas comparaciones?

### 9.2: Selection Sort

Analizar la complejidad:

```c
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}
```

**Pregunta:** ¿Hay diferencia entre mejor y peor caso?

### 9.3: Insertion Sort

Analizar la complejidad:

```c
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = clave;
    }
}
```

**Casos:**
- **Mejor caso:** Arreglo ya ordenado
- **Peor caso:** Arreglo en orden inverso

### 9.4: Quick Sort

Analizar la complejidad del Quick Sort:

**Mejor/Promedio caso:** El pivote divide el arreglo en dos mitades iguales
- Recurrencia: $T(n) = 2T(n/2) + O(n)$
- Resultado: $O(n \log n)$

**Peor caso:** El pivote siempre es el menor o mayor elemento
- Recurrencia: $T(n) = T(n-1) + O(n)$
- Resultado: $O(n^2)$

**Pregunta:** ¿Qué estrategias existen para evitar el peor caso?

## 10: Complejidad Espacial

### 10.1: Merge Sort - Espacio Auxiliar

Analizar la complejidad espacial del Merge Sort:

```c
void merge(int arr[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    
    int* L = malloc(n1 * sizeof(int));  // Espacio auxiliar
    int* R = malloc(n2 * sizeof(int));  // Espacio auxiliar
    
    // ... copiar y fusionar ...
    
    free(L);
    free(R);
}
```

**Preguntas:**
- ¿Cuánta memoria auxiliar se usa en cada nivel de recursión?
- ¿Cuál es la complejidad espacial total?

### 10.2: Quick Sort In-Place

El Quick Sort se implementa típicamente in-place:

```c
void quick_sort(int arr[], int izq, int der) {
    if (izq < der) {
        int pivote = partition(arr, izq, der);
        quick_sort(arr, izq, pivote - 1);
        quick_sort(arr, pivote + 1, der);
    }
}
```

**Preguntas:**
- ¿Usa memoria auxiliar para los datos?
- ¿Qué espacio usa para el call stack?
- ¿Cuál es la complejidad espacial en mejor y peor caso?

### 10.3: Fibonacci - Comparación de Enfoques

Comparar la complejidad temporal y espacial de tres implementaciones:

**Recursivo ingenuo:**
```c
int fib_recursivo(int n) {
    if (n <= 1) return n;
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}
// Tiempo: O(2^n), Espacio: O(n) [stack]
```

**Iterativo:**
```c
int fib_iterativo(int n) {
    if (n <= 1) return n;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}
// Tiempo: O(n), Espacio: O(1)
```

**Con memoización:**
```c
int fib_memo(int n, int* memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}
// Tiempo: O(n), Espacio: O(n)
```

## 11: Trade-offs Tiempo vs. Espacio

### 11.1: Tabla de Búsqueda vs. Cálculo

Comparar dos enfoques para calcular factoriales:

**Enfoque 1: Calcular cada vez**
```c
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
// Tiempo: O(n), Espacio: O(1)
```

**Enfoque 2: Tabla precalculada**
```c
long long factoriales[21] = {1, 1, 2, 6, 24, /* ... */};

long long factorial(int n) {
    return factoriales[n];
}
// Tiempo: O(1), Espacio: O(k) donde k es el tamaño de la tabla
```

**Pregunta:** ¿Cuándo conviene cada enfoque?

### 11.2: Contar Bits Activados

Comparar dos implementaciones:

**Enfoque 1: Lazo**
```c
int contar_bits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
// Tiempo: O(log n) = O(32) = O(1)
```

**Enfoque 2: Tabla lookup**
```c
int tabla_bits[256] = { /* precalculado */ };

int contar_bits(unsigned int n) {
    return tabla_bits[n & 0xFF] +
           tabla_bits[(n >> 8) & 0xFF] +
           tabla_bits[(n >> 16) & 0xFF] +
           tabla_bits[(n >> 24) & 0xFF];
}
// Tiempo: O(1), Espacio: O(256)
```

## 12: Límites Inferiores

### 12.1: Límite Inferior del Ordenamiento

Demostrar por qué cualquier algoritmo de ordenamiento basado en comparaciones requiere al menos $\Omega(n \log n)$ comparaciones.

**Pistas:**
- El árbol de decisión tiene $n!$ hojas (posibles permutaciones)
- Un árbol binario de altura $h$ tiene a lo sumo $2^h$ hojas
- Por tanto: $2^h \geq n!$

:::{note} Límite Teórico
Este límite inferior es **óptimo**: algoritmos como Merge Sort y Heap Sort lo alcanzan. No se puede hacer mejor que $O(n \log n)$ con comparaciones.
:::

### 12.2: Buscar en Arreglo No Ordenado

**Pregunta:** ¿Cuál es el límite inferior para buscar un elemento en un arreglo no ordenado?

**Respuesta:** $\Omega(n)$, porque en el peor caso debemos examinar todos los elementos.

### 12.3: Encontrar el Máximo

Demostrar que encontrar el máximo de $n$ elementos requiere al menos $n - 1$ comparaciones.

**Pista:** Cada elemento excepto el máximo debe "perder" al menos una comparación.

## 13: Análisis Amortizado

### 13.1: Array Dinámico - Costo Amortizado

Considerar un array dinámico que duplica su capacidad cuando se llena:

```c
typedef struct {
    int* datos;
    int tamano;
    int capacidad;
} array_dinamico_t;

void array_push(array_dinamico_t* arr, int valor) {
    if (arr->tamano == arr->capacidad) {
        arr->capacidad *= 2;
        arr->datos = realloc(arr->datos, arr->capacidad * sizeof(int));
    }
    arr->datos[arr->tamano++] = valor;
}
```

**Análisis:**
- Inserción típica: $O(1)$
- Inserción que causa resize: $O(n)$
- ¿Costo amortizado por operación?

**Demostración:** Insertar $n$ elementos:
- Resizes en posiciones: 1, 2, 4, 8, 16, ..., hasta $n$
- Costo total: $n + (1 + 2 + 4 + 8 + \ldots) < n + 2n = 3n$
- Costo amortizado: $O(3n) / n = O(1)$

### 13.2: Contador Binario

Analizar el costo amortizado de incrementar un contador binario:

```c
void incrementar(int bits[], int k) {
    int i = 0;
    while (i < k && bits[i] == 1) {
        bits[i] = 0;
        i++;
    }
    if (i < k) {
        bits[i] = 1;
    }
}
```

**Pregunta:** Si incrementamos $n$ veces, ¿cuál es el costo amortizado por incremento?

### 13.3: Stack con Multiop

Un stack con operación especial `multipop(k)` que desapila $k$ elementos:

```c
void multipop(stack_t* s, int k) {
    while (!stack_vacio(s) && k > 0) {
        stack_pop(s);
        k--;
    }
}
```

**Análisis amortizado:** Aunque `multipop` es $O(k)$, el costo amortizado considerando una secuencia de operaciones es $O(1)$ por operación.

## 14: Optimización de Algoritmos

### 14.1: Suma de Subarray Máxima

Comparar tres algoritmos para encontrar la suma máxima de un subarray contiguo:

**Algoritmo 1: Fuerza bruta - $O(n^3)$**
```c
int max_subarray_v1(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int suma = 0;
            for (int k = i; k <= j; k++) {
                suma += arr[k];
            }
            if (suma > max) max = suma;
        }
    }
    return max;
}
```

**Algoritmo 2: Mejorado - $O(n^2)$**
```c
int max_subarray_v2(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = i; j < n; j++) {
            suma += arr[j];
            if (suma > max) max = suma;
        }
    }
    return max;
}
```

**Algoritmo 3: Kadane - $O(n)$**
```c
int max_subarray_v3(int arr[], int n) {
    int max_hasta_aqui = arr[0];
    int max_global = arr[0];
    
    for (int i = 1; i < n; i++) {
        max_hasta_aqui = (arr[i] > max_hasta_aqui + arr[i]) ? 
                         arr[i] : max_hasta_aqui + arr[i];
        if (max_hasta_aqui > max_global) {
            max_global = max_hasta_aqui;
        }
    }
    return max_global;
}
```

**Tarea:** Medir empíricamente para $n = 1000, 5000, 10000$.

### 14.2: Dos Elementos que Suman Target

Dado un arreglo y un valor target, encontrar dos elementos que sumen ese valor.

**Enfoque 1: Fuerza bruta - $O(n^2)$**
```c
bool dos_suma_v1(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}
```

**Enfoque 2: Con ordenamiento - $O(n \log n)$**
```c
bool dos_suma_v2(int arr[], int n, int target) {
    quick_sort(arr, n);  // O(n log n)
    
    int izq = 0, der = n - 1;
    while (izq < der) {
        int suma = arr[izq] + arr[der];
        if (suma == target) return true;
        else if (suma < target) izq++;
        else der--;
    }
    return false;
}
```

**Enfoque 3: Con hash table - $O(n)$**
```c
bool dos_suma_v3(int arr[], int n, int target) {
    hash_set_t* set = hash_set_crear();
    
    for (int i = 0; i < n; i++) {
        int complemento = target - arr[i];
        if (hash_set_contiene(set, complemento)) {
            hash_set_destruir(set);
            return true;
        }
        hash_set_agregar(set, arr[i]);
    }
    
    hash_set_destruir(set);
    return false;
}
```

### 14.3: Multiplicación de Matrices

Comparar:
- **Algoritmo ingenuo:** $O(n^3)$
- **Algoritmo de Strassen:** $O(n^{2.807})$
- **Mejor algoritmo conocido:** $O(n^{2.373})$ (Coppersmith-Winograd mejorado)

**Pregunta:** ¿Por qué Strassen no se usa siempre en la práctica?

## 15: Problemas Clásicos

### 15.1: Problema de la Mochila (0-1 Knapsack)

Analizar la complejidad de la solución con programación dinámica:

```c
int knapsack(int pesos[], int valores[], int n, int capacidad) {
    int dp[n + 1][capacidad + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidad; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (pesos[i - 1] <= w) {
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacidad];
}
```

**Complejidad:** Tiempo $O(n \cdot W)$, Espacio $O(n \cdot W)$

**Pregunta:** ¿Es esto $O(n^2)$? ¿Por qué se considera pseudo-polinomial?

### 15.2: Subsequencia Común Más Larga (LCS)

Analizar la complejidad:

```c
int lcs(char* X, char* Y, int m, int n) {
    int dp[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}
```

**Complejidad:** $O(m \cdot n)$ en tiempo y espacio.

### 15.3: Problema del Viajante (TSP)

Comparar enfoques:

1. **Fuerza bruta:** Probar todas las permutaciones - $O(n!)$
2. **Programación dinámica (Held-Karp):** $O(n^2 \cdot 2^n)$
3. **Heurísticas (nearest neighbor):** $O(n^2)$ pero no garantiza óptimo

**Pregunta:** ¿Por qué TSP es NP-completo? ¿Qué significa esto en la práctica?

## 16: Estructuras de Datos y su Complejidad

### 16.1: Comparación de Estructuras

Completar la siguiente tabla con las complejidades temporales:

| Operación | Array | Lista Enlazada | BST (promedio) | Hash Table |
|-----------|-------|----------------|----------------|------------|
| Acceso    | ?     | ?              | ?              | ?          |
| Búsqueda  | ?     | ?              | ?              | ?          |
| Inserción | ?     | ?              | ?              | ?          |
| Eliminación | ?   | ?              | ?              | ?          |

### 16.2: Elección de Estructura

Para cada escenario, elegir la estructura más apropiada:

a) Necesitás acceso aleatorio rápido por índice  
b) Insertás frecuentemente al inicio de la secuencia  
c) Buscás elementos por clave de forma frecuente  
d) Necesitás mantener elementos ordenados  
e) Hacés muchas inserciones/eliminaciones en el medio

### 16.3: Heap vs. BST

Comparar las complejidades de operaciones en un Min-Heap y un BST:

| Operación | Min-Heap | BST (balanceado) |
|-----------|----------|------------------|
| Encontrar mínimo | ? | ? |
| Extraer mínimo | ? | ? |
| Insertar | ? | ? |
| Buscar elemento | ? | ? |

## 17: Algoritmos de Grafos

### 17.1: BFS y DFS

Analizar la complejidad temporal y espacial:

**BFS (Breadth-First Search):**
```c
void bfs(grafo_t* g, int inicio) {
    bool* visitado = calloc(g->num_vertices, sizeof(bool));
    cola_t* cola = cola_crear();
    
    cola_encolar(cola, inicio);
    visitado[inicio] = true;
    
    while (!cola_vacia(cola)) {
        int v = cola_desencolar(cola);
        procesar(v);
        
        for (nodo_t* adj = g->adyacentes[v]; adj; adj = adj->siguiente) {
            if (!visitado[adj->destino]) {
                cola_encolar(cola, adj->destino);
                visitado[adj->destino] = true;
            }
        }
    }
    
    free(visitado);
    cola_destruir(cola);
}
```

**Complejidad:** $O(V + E)$ donde $V$ = vértices, $E$ = aristas

### 17.2: Dijkstra

Analizar la complejidad del algoritmo de Dijkstra con diferentes implementaciones:

- **Con array simple:** $O(V^2)$
- **Con min-heap binario:** $O((V + E) \log V)$
- **Con Fibonacci heap:** $O(E + V \log V)$

**Pregunta:** ¿Para qué tipo de grafos es mejor cada implementación?

### 17.3: Floyd-Warshall

Analizar el algoritmo de caminos más cortos entre todos los pares:

```c
void floyd_warshall(int grafo[][V], int dist[][V]) {
    // Inicialización: O(V^2)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = grafo[i][j];
        }
    }
    
    // Tres lazos anidados: O(V^3)
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
```

**Complejidad:** $O(V^3)$ en tiempo, $O(V^2)$ en espacio.

## 18: Técnicas Avanzadas

### 18.1: Sliding Window

Analizar la técnica de ventana deslizante para encontrar la suma máxima de $k$ elementos consecutivos:

**Enfoque ingenuo: $O(n \cdot k)$**
```c
int max_suma_k_ingenuo(int arr[], int n, int k) {
    int max = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int suma = 0;
        for (int j = i; j < i + k; j++) {
            suma += arr[j];
        }
        if (suma > max) max = suma;
    }
    return max;
}
```

**Enfoque optimizado: $O(n)$**
```c
int max_suma_k_optimizado(int arr[], int n, int k) {
    int suma_ventana = 0;
    for (int i = 0; i < k; i++) {
        suma_ventana += arr[i];
    }
    
    int max = suma_ventana;
    for (int i = k; i < n; i++) {
        suma_ventana += arr[i] - arr[i - k];
        if (suma_ventana > max) max = suma_ventana;
    }
    
    return max;
}
```

### 18.2: Two Pointers

Analizar la técnica de dos punteros para eliminar duplicados de un arreglo ordenado:

```c
int eliminar_duplicados(int arr[], int n) {
    if (n == 0) return 0;
    
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    
    return j + 1;
}
```

**Complejidad:** $O(n)$ con $O(1)$ de espacio adicional.

### 18.3: Divide y Conquista - Inversiones

Contar el número de inversiones en un arreglo (pares $(i, j)$ donde $i < j$ pero $arr[i] > arr[j]$):

**Enfoque ingenuo:** $O(n^2)$ - comparar todos los pares

**Enfoque divide-y-conquista:** $O(n \log n)$ - modificar merge sort para contar inversiones durante la fusión

## 19: Casos Prácticos

### 19.1: Sistema de Recomendaciones

Diseñar un sistema que recomiende productos a usuarios:

**Datos:**
- 1 millón de usuarios
- 100,000 productos
- 10 millones de calificaciones

**Operaciones:**
- Buscar calificaciones de un usuario: ¿Qué complejidad?
- Encontrar usuarios similares: ¿Qué algoritmo?
- Recomendar top 10 productos: ¿Qué estructura de datos?

### 19.2: Motor de Búsqueda

Diseñar las estructuras para un motor de búsqueda:

**Índice invertido:**
- Palabra → Lista de documentos
- ¿Qué complejidad para buscar una palabra?
- ¿Qué complejidad para buscar dos palabras (AND)?

**Ranking:**
- Ordenar resultados por relevancia
- ¿Usar ordenamiento completo o heap parcial?

### 19.3: Red Social

Modelar una red social:

**Operaciones:**
- Verificar si dos usuarios son amigos: $O(?)$
- Encontrar amigos en común: $O(?)$
- Sugerir amigos (amigos de amigos): $O(?)$
- Encontrar camino más corto entre usuarios: ¿Qué algoritmo?

## 20: Ejercicios Integradores

### 20.1: Análisis Completo de un Programa

Analizar la complejidad temporal y espacial de este programa:

```c
int funcion_misteriosa(int arr[], int n) {
    // Paso 1: Ordenar el arreglo
    merge_sort(arr, n);  // O(n log n)
    
    // Paso 2: Eliminar duplicados
    int nuevo_n = eliminar_duplicados(arr, n);  // O(n)
    
    // Paso 3: Buscar pares que suman target
    int count = 0;
    int target = 100;
    
    for (int i = 0; i < nuevo_n; i++) {
        int complemento = target - arr[i];
        if (busqueda_binaria(arr, nuevo_n, complemento) >= 0) {
            count++;
        }
    }
    
    return count;
}
```

**Preguntas:**
1. ¿Cuál es la complejidad temporal de cada paso?
2. ¿Cuál es la complejidad temporal total?
3. ¿Cuál es la complejidad espacial?
4. ¿Se puede optimizar?

### 20.2: Optimización de un Sistema

Tenés un sistema que procesa transacciones:

**Requerimientos:**
- Insertar transacción: debe ser rápido
- Buscar transacción por ID: debe ser instantáneo
- Obtener las 10 transacciones más grandes: frecuente
- Listar transacciones en orden cronológico: poco frecuente

**Tareas:**
1. Proponer estructuras de datos
2. Analizar complejidad de cada operación
3. Justificar las decisiones de diseño
4. Identificar trade-offs

### 20.3: Desafío de Optimización

Optimizar este código que procesa una matriz:

```c
// Versión inicial: calcular suma de cada fila
void procesar_matriz_v1(int matriz[][COLS], int filas) {
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < COLS; j++) {
            suma += matriz[i][j];
        }
        printf("Suma fila %d: %d\n", i, suma);
    }
    
    // Luego calcular suma de cada columna
    for (int j = 0; j < COLS; j++) {
        int suma = 0;
        for (int i = 0; i < filas; i++) {
            suma += matriz[i][j];
        }
        printf("Suma columna %d: %d\n", j, suma);
    }
}
```

**Preguntas:**
1. ¿Cuál es la complejidad actual?
2. ¿Se puede calcular todo en un solo recorrido?
3. ¿Qué consideraciones de cache locality aplicarían?

**Versión optimizada:**
```c
void procesar_matriz_v2(int matriz[][COLS], int filas) {
    int sumas_filas[filas];
    int sumas_cols[COLS];
    
    memset(sumas_filas, 0, sizeof(sumas_filas));
    memset(sumas_cols, 0, sizeof(sumas_cols));
    
    // Un solo recorrido
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < COLS; j++) {
            sumas_filas[i] += matriz[i][j];
            sumas_cols[j] += matriz[i][j];
        }
    }
    
    // Imprimir resultados
    for (int i = 0; i < filas; i++) {
        printf("Suma fila %d: %d\n", i, sumas_filas[i]);
    }
    for (int j = 0; j < COLS; j++) {
        printf("Suma columna %d: %d\n", j, sumas_cols[j]);
    }
}
```

**Trade-off:** Menos iteraciones pero más espacio auxiliar.

