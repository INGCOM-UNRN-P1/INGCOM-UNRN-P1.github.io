---
title: Análisis de Complejidad Algorítmica
short_title: 12 - Complejidad
subtitle: Fundamentos matemáticos del análisis asintótico
---

## Introducción

El **análisis de complejidad algorítmica** es una herramienta fundamental en ciencias de la computación que permite evaluar y comparar la eficiencia de algoritmos de manera rigurosa y matemática. A diferencia de medir tiempos de ejecución concretos (que dependen del hardware, compilador, y otros factores variables), el análisis asintótico caracteriza el comportamiento de un algoritmo en función del tamaño de su entrada, proporcionando garantías independientes de la implementación específica.

:::{important} Objetivos del Análisis
El análisis de complejidad busca responder tres preguntas fundamentales:

1. **¿Cómo crece el tiempo de ejecución cuando aumenta el tamaño de entrada?**
2. **¿Cuánta memoria requiere el algoritmo para diferentes tamaños de entrada?**
3. **¿Es posible mejorar la eficiencia del algoritmo?**
:::

Este enfoque matemático permite tomar decisiones informadas sobre qué algoritmo usar en cada situación, predecir si un algoritmo será viable para grandes volúmenes de datos, y establecer límites teóricos sobre lo que es computacionalmente posible.

## Fundamentos Matemáticos

### El Modelo RAM (Random Access Machine)

Para analizar algoritmos de forma rigurosa, necesitamos un modelo abstracto de computación. El modelo **RAM** asume:

1. **Operaciones básicas** (suma, resta, comparación, asignación, acceso a memoria) toman **tiempo constante** $O(1)$.
2. La memoria es ilimitada y el acceso a cualquier posición toma tiempo constante.
3. Las operaciones se ejecutan secuencialmente (no hay paralelismo).

:::{note} Simplificación vs Realidad
Aunque este modelo simplifica la arquitectura real de las computadoras (que tienen jerarquías de caché, pipelines, etc.), proporciona predicciones precisas del comportamiento asintótico para la mayoría de algoritmos prácticos.
:::

### Función de Complejidad

Para un algoritmo $A$ y una entrada de tamaño $n$, definimos:

- $T(n)$: **Tiempo de ejecución** (número de operaciones básicas) en función de $n$
- $S(n)$: **Espacio utilizado** (cantidad de memoria) en función de $n$

Estas funciones pueden analizarse en tres casos:

1. **Peor caso**: $T_{\text{worst}}(n) = \max\{T(I) : |I| = n\}$
2. **Mejor caso**: $T_{\text{best}}(n) = \min\{T(I) : |I| = n\}$
3. **Caso promedio**: $T_{\text{avg}}(n) = \mathbb{E}[T(I) : |I| = n]$

```{figure} 12/casos_complejidad.svg
:label: fig-casos
:align: center

Visualización de los tres casos de análisis para un algoritmo, mostrando cómo diferentes entradas del mismo tamaño pueden resultar en tiempos distintos.
```

:::{important} Foco en el Peor Caso
En la práctica, el análisis del **peor caso** es el más utilizado porque:
- Proporciona **garantías** sobre el rendimiento máximo
- Es más fácil de calcular que el caso promedio
- Evita sorpresas desagradables en producción
:::

## Notación Asintótica

La notación asintótica describe el comportamiento de funciones para valores grandes de $n$, ignorando constantes multiplicativas y términos de orden inferior.

### Notación Big-O (Cota Superior)

**Definición formal**: $f(n) \in O(g(n))$ si y solo si existen constantes positivas $c$ y $n_0$ tales que:

$$
0 \leq f(n) \leq c \cdot g(n) \quad \forall n \geq n_0
$$

**Interpretación**: $f$ no crece más rápido que $g$ (salvo por una constante multiplicativa).

```{figure} 12/big_o_definition.svg
:label: fig-big-o
:align: center

Representación gráfica de la definición de Big-O. La función $f(n)$ queda acotada superiormente por $c \cdot g(n)$ para $n \geq n_0$.
```

**Ejemplos**:
- $3n + 5 \in O(n)$ porque $3n + 5 \leq 4n$ para $n \geq 5$ (tomando $c=4, n_0=5$)
- $n^2 + 100n \in O(n^2)$ porque $n^2 + 100n \leq 101n^2$ para $n \geq 100$
- $\log(n) \in O(n)$ porque el logaritmo crece más lento que lineal

### Notación Big-Omega (Cota Inferior)

**Definición formal**: $f(n) \in \Omega(g(n))$ si y solo si existen constantes positivas $c$ y $n_0$ tales que:

$$
0 \leq c \cdot g(n) \leq f(n) \quad \forall n \geq n_0
$$

**Interpretación**: $f$ crece al menos tan rápido como $g$.

**Ejemplos**:
- $5n^2 \in \Omega(n^2)$ y también $\Omega(n)$ y $\Omega(\log n)$
- Si un algoritmo es $\Omega(n \log n)$, entonces requiere al menos ese tiempo en el peor caso

### Notación Big-Theta (Cota Ajustada)

**Definición formal**: $f(n) \in \Theta(g(n))$ si y solo si $f(n) \in O(g(n))$ y $f(n) \in \Omega(g(n))$.

Equivalentemente, existen constantes $c_1, c_2, n_0 > 0$ tales que:

$$
0 \leq c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n) \quad \forall n \geq n_0
$$

**Interpretación**: $f$ y $g$ crecen al mismo ritmo (salvo constantes).

```{figure} 12/big_theta_definition.svg
:label: fig-big-theta
:align: center

Representación gráfica de Big-Theta. La función $f(n)$ queda acotada superior e inferiormente por múltiplos de $g(n)$.
```

**Ejemplos**:
- $3n^2 + 5n + 2 \in \Theta(n^2)$
- $\frac{n \log n}{2} \in \Theta(n \log n)$

### Notaciones Menos Comunes

#### Little-o (Límite Asintótico Estricto)

$f(n) \in o(g(n))$ si para toda constante $c > 0$, existe $n_0$ tal que:

$$
0 \leq f(n) < c \cdot g(n) \quad \forall n \geq n_0
$$

Equivalentemente: $\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$

**Ejemplo**: $n \in o(n^2)$ pero $n \notin o(n)$

#### Little-omega (Límite Inferior Estricto)

$f(n) \in \omega(g(n))$ si para toda constante $c > 0$, existe $n_0$ tal que:

$$
0 \leq c \cdot g(n) < f(n) \quad \forall n \geq n_0
$$

### Propiedades Algebraicas

Las notaciones asintóticas tienen propiedades útiles:

1. **Transitividad**: Si $f \in O(g)$ y $g \in O(h)$, entonces $f \in O(h)$
2. **Reflexividad**: $f \in \Theta(f)$
3. **Simetría**: Si $f \in \Theta(g)$, entonces $g \in \Theta(f)$
4. **Suma**: $O(f) + O(g) = O(\max(f, g))$
5. **Producto**: $O(f) \cdot O(g) = O(f \cdot g)$

## Jerarquía de Complejidades

```{figure} 12/complexity_hierarchy.svg
:label: fig-hierarchy
:align: center
:width: 100%

Jerarquía de las clases de complejidad más comunes, ordenadas de más eficiente a menos eficiente.
```

### Clasificación Detallada

#### Constante: $O(1)$

**Características**:
- El tiempo no depende del tamaño de entrada
- Más eficiente posible
- Ejemplo: acceso a un elemento de arreglo, operaciones aritméticas

**Código ejemplo**:
```c
int obtener_primero(int arr[], int n) {
    return arr[0];  // O(1): una operación, independiente de n
}
```

#### Logarítmica: $O(\log n)$

**Características**:
- Crece muy lentamente
- Típica de algoritmos que dividen el problema a la mitad en cada paso
- Base del logaritmo irrelevante asintóticamente: $\log_2 n \in \Theta(\log_{10} n)$

**Ejemplos**: búsqueda binaria, operaciones en árboles balanceados

**Código ejemplo**:
```c
// Búsqueda binaria: O(log n)
int busqueda_binaria(int arr[], int n, int clave) {
    int izq = 0, der = n - 1;
    
    while (izq <= der) {  // Se reduce a la mitad en cada iteración
        int medio = izq + (der - izq) / 2;
        
        if (arr[medio] == clave) {
            return medio;
        }
        
        if (arr[medio] < clave) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    
    return -1;
}
```

**Análisis**: En cada iteración, el espacio de búsqueda se reduce a la mitad. Si inicialmente hay $n$ elementos, después de $k$ iteraciones quedan $\frac{n}{2^k}$. El algoritmo termina cuando $\frac{n}{2^k} = 1$, es decir, $k = \log_2 n$.

#### Lineal: $O(n)$

**Características**:
- Tiempo proporcional al tamaño de entrada
- Óptimo para problemas que requieren examinar todos los datos
- Duplicar la entrada duplica el tiempo

**Ejemplos**: búsqueda secuencial, recorrer un arreglo, suma de elementos

**Código ejemplo**:
```c
// Suma de elementos: O(n)
int sumar_elementos(int arr[], int n) {
    int suma = 0;
    
    for (int i = 0; i < n; i++) {  // n iteraciones
        suma += arr[i];  // O(1) por iteración
    }
    
    return suma;
}
```

#### Log-Lineal: $O(n \log n)$

**Características**:
- Complejidad de algoritmos óptimos de ordenamiento por comparación
- Crece más que lineal pero menos que cuadrático
- Muy eficiente en la práctica

**Ejemplos**: Merge Sort, Heap Sort, Quick Sort (promedio)

**Código ejemplo (Merge Sort)**:
```c
// Merge Sort: O(n log n)
void merge_sort(int arr[], int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        
        merge_sort(arr, izq, medio);      // T(n/2)
        merge_sort(arr, medio + 1, der);  // T(n/2)
        merge(arr, izq, medio, der);      // O(n)
    }
}
```

**Análisis**: La recurrencia es $T(n) = 2T(n/2) + O(n)$, que resuelve a $T(n) = O(n \log n)$ por el Teorema Maestro.

#### Cuadrática: $O(n^2)$

**Características**:
- Típica de algoritmos con dos lazos anidados
- Duplicar la entrada cuadruplica el tiempo
- Práctica para $n$ pequeño, inviable para $n$ grande

**Ejemplos**: Bubble Sort, Selection Sort, Insertion Sort

**Código ejemplo**:
```c
// Bubble Sort: O(n²)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // n iteraciones
        for (int j = 0; j < n - i - 1; j++) {   // n-i iteraciones
            if (arr[j] > arr[j + 1]) {
                intercambiar(&arr[j], &arr[j + 1]);  // O(1)
            }
        }
    }
}
```

**Análisis**: Total de comparaciones = $\sum_{i=0}^{n-1} (n-i) = \frac{n(n-1)}{2} \in \Theta(n^2)$

#### Cúbica: $O(n^3)$

**Características**:
- Tres lazos anidados o algoritmos con subcubos
- Viable solo para $n$ pequeño

**Ejemplos**: multiplicación ingenua de matrices, algunos algoritmos de grafos

**Código ejemplo**:
```c
// Multiplicación de matrices: O(n³)
void multiplicar_matrices(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++) {         // n iteraciones
        for (int j = 0; j < n; j++) {     // n iteraciones
            C[i][j] = 0;
            for (int k = 0; k < n; k++) { // n iteraciones
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

#### Exponencial: $O(2^n)$

**Características**:
- Crece extremadamente rápido
- Inviable para $n > 30$ en la mayoría de casos
- Común en algoritmos de fuerza bruta

**Ejemplos**: subconjuntos de un conjunto, Torre de Hanoi, algunos problemas NP-completos

**Código ejemplo**:
```c
// Fibonacci recursivo ingenuo: O(2^n)
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Dos llamadas recursivas
}
```

**Análisis**: La recurrencia $T(n) = T(n-1) + T(n-2) + O(1)$ tiene solución $T(n) \in \Theta(\phi^n)$ donde $\phi = \frac{1+\sqrt{5}}{2} \approx 1.618$ (razón áurea).

#### Factorial: $O(n!)$

**Características**:
- La complejidad más ineficiente de las comunes
- Solo viable para $n < 15$ aproximadamente
- Aparece en problemas de permutaciones

**Ejemplos**: generar todas las permutaciones, problema del viajante (fuerza bruta)

**Código ejemplo**:
```c
// Generar permutaciones: O(n!)
void generar_permutaciones(int arr[], int inicio, int fin) {
    if (inicio == fin) {
        imprimir(arr, fin + 1);
        return;
    }
    
    for (int i = inicio; i <= fin; i++) {
        intercambiar(&arr[inicio], &arr[i]);
        generar_permutaciones(arr, inicio + 1, fin);  // (n-1)! llamadas
        intercambiar(&arr[inicio], &arr[i]);
    }
}
```

```{figure} 12/growth_comparison.svg
:label: fig-growth
:align: center
:width: 100%

Comparación del crecimiento de diferentes funciones de complejidad para valores de $n$ hasta 100.
```

### Tabla Comparativa de Crecimiento

| $n$ | $\log n$ | $n$ | $n \log n$ | $n^2$ | $n^3$ | $2^n$ | $n!$ |
|-----|----------|-----|------------|-------|-------|-------|------|
| 10  | 3        | 10  | 33         | 100   | 1K    | 1K    | 3.6M |
| 20  | 4        | 20  | 86         | 400   | 8K    | 1M    | $2.4 \times 10^{18}$ |
| 30  | 5        | 30  | 147        | 900   | 27K   | 1B    | $2.7 \times 10^{32}$ |
| 100 | 7        | 100 | 664        | 10K   | 1M    | $1.3 \times 10^{30}$ | $9.3 \times 10^{157}$ |
| 1000| 10       | 1K  | 9.9K       | 1M    | 1B    | — | — |

:::{note} Viabilidad Práctica
- **$O(\log n), O(n), O(n \log n)$**: Viables para cualquier tamaño razonable
- **$O(n^2)$**: Viable hasta $n \approx 10^6$
- **$O(n^3)$**: Viable hasta $n \approx 1000$
- **$O(2^n)$**: Viable solo hasta $n \approx 25$
- **$O(n!)$**: Viable solo hasta $n \approx 12$
:::

## Técnicas de Análisis

### Análisis de Lazos

#### Lazo Simple

```c
for (int i = 0; i < n; i++) {
    // Operación O(1)
}
```

**Análisis**: $\sum_{i=0}^{n-1} O(1) = O(n)$

#### Lazos Anidados

```c
for (int i = 0; i < n; i++) {       // n iteraciones
    for (int j = 0; j < n; j++) {   // n iteraciones
        // Operación O(1)
    }
}
```

**Análisis**: $\sum_{i=0}^{n-1} \sum_{j=0}^{n-1} O(1) = n \cdot n \cdot O(1) = O(n^2)$

#### Lazos con Dependencia

```c
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {  // Depende de i
        // Operación O(1)
    }
}
```

**Análisis**:
$$
\sum_{i=0}^{n-1} \sum_{j=i}^{n-1} O(1) = \sum_{i=0}^{n-1} (n-i) = \sum_{k=1}^{n} k = \frac{n(n+1)}{2} \in O(n^2)
$$

#### Lazo Logarítmico

```c
for (int i = 1; i < n; i *= 2) {
    // Operación O(1)
}
```

**Análisis**: Si $i$ comienza en 1 y se duplica cada iteración, el lazo ejecuta $k$ veces donde $2^k = n$, es decir, $k = \log_2 n$. Por tanto, $O(\log n)$.

### Análisis de Recursión

#### Método de Sustitución

**Ejemplo**: $T(n) = T(n-1) + O(1)$ con $T(1) = O(1)$

**Solución**:
$$
\begin{align}
T(n) &= T(n-1) + c \\
     &= T(n-2) + c + c = T(n-2) + 2c \\
     &= T(n-3) + 3c \\
     &\vdots \\
     &= T(1) + (n-1)c \\
     &= O(1) + O(n) = O(n)
\end{align}
$$

#### Teorema Maestro

Para recurrencias de la forma:
$$
T(n) = aT\left(\frac{n}{b}\right) + f(n)
$$

donde $a \geq 1$, $b > 1$ y $f(n)$ es asintóticamente positiva, el Teorema Maestro proporciona la solución:

**Caso 1**: Si $f(n) \in O(n^{\log_b a - \epsilon})$ para algún $\epsilon > 0$, entonces:
$$
T(n) \in \Theta(n^{\log_b a})
$$

**Caso 2**: Si $f(n) \in \Theta(n^{\log_b a} \log^k n)$ para algún $k \geq 0$, entonces:
$$
T(n) \in \Theta(n^{\log_b a} \log^{k+1} n)
$$

**Caso 3**: Si $f(n) \in \Omega(n^{\log_b a + \epsilon})$ para algún $\epsilon > 0$, y $af(n/b) \leq cf(n)$ para algún $c < 1$ y $n$ suficientemente grande, entonces:
$$
T(n) \in \Theta(f(n))
$$

```{figure} 12/master_theorem.svg
:label: fig-master
:align: center

Árbol de recursión ilustrando el Teorema Maestro y cómo se distribuye el trabajo en cada nivel.
```

**Ejemplos de aplicación**:

1. **Merge Sort**: $T(n) = 2T(n/2) + O(n)$
   - $a=2, b=2, f(n)=n$
   - $\log_b a = \log_2 2 = 1$
   - $f(n) = n \in \Theta(n^1)$ → **Caso 2** con $k=0$
   - **Solución**: $T(n) \in \Theta(n \log n)$

2. **Búsqueda Binaria**: $T(n) = T(n/2) + O(1)$
   - $a=1, b=2, f(n)=1$
   - $\log_b a = 0$
   - $f(n) = 1 \in \Theta(n^0)$ → **Caso 2** con $k=0$
   - **Solución**: $T(n) \in \Theta(\log n)$

3. **Multiplicación de Karatsuba**: $T(n) = 3T(n/2) + O(n)$
   - $a=3, b=2, f(n)=n$
   - $\log_b a = \log_2 3 \approx 1.585$
   - $f(n) = n \in O(n^{1.585-\epsilon})$ → **Caso 1**
   - **Solución**: $T(n) \in \Theta(n^{\log_2 3}) \approx \Theta(n^{1.585})$

#### Método del Árbol de Recursión

Visualiza la recursión como un árbol donde:
- Cada nodo representa una llamada recursiva
- El costo en cada nodo es el trabajo no recursivo
- La suma de todos los nodos es el costo total

**Ejemplo**: $T(n) = 2T(n/2) + n$

```
Nivel 0:                n              → costo: n
                       / \
Nivel 1:            n/2   n/2          → costo: n
                    / \   / \
Nivel 2:         n/4 n/4 n/4 n/4       → costo: n
                  ...

Altura del árbol: log n
Costo por nivel: n
Costo total: n × log n = O(n log n)
```

### Análisis Amortizado

El **análisis amortizado** considera el costo promedio de una secuencia de operaciones, permitiendo que algunas operaciones sean costosas si la mayoría son baratas.

#### Método del Agregado

**Ejemplo**: Arreglo dinámico (como `std::vector` de C++)

Operación `push_back`:
- Caso normal: $O(1)$ (insertar al final)
- Caso de redimensionamiento: $O(n)$ (copiar todos los elementos)

Si el arreglo duplica su tamaño cuando se llena, el costo de $n$ inserciones es:
$$
\sum_{i=0}^{\log n} 2^i = 2^{\log n + 1} - 1 < 2n
$$

**Costo amortizado**: $\frac{2n}{n} = O(1)$ por operación.

#### Método del Potencial

Define una función potencial $\Phi$ que representa "energía almacenada" en la estructura:

$$
\text{Costo amortizado} = \text{Costo real} + \Delta\Phi
$$

Para arreglo dinámico: $\Phi = 2 \times \text{tamaño} - \text{capacidad}$

## Complejidad Espacial

La **complejidad espacial** mide la cantidad de memoria adicional que un algoritmo requiere.

### Clasificación

- **$O(1)$**: Espacio constante, independiente de la entrada
- **$O(\log n)$**: Típico de algoritmos recursivos que dividen el problema
- **$O(n)$**: Espacio lineal, como copiar un arreglo
- **$O(n^2)$**: Matrices cuadradas

### Recursión y Pila de Llamadas

Cada llamada recursiva ocupa espacio en la pila. La profundidad máxima de recursión determina la complejidad espacial.

**Ejemplo**: Fibonacci recursivo
```c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

- **Complejidad temporal**: $O(2^n)$
- **Complejidad espacial**: $O(n)$ (profundidad máxima de la pila)

### Trade-off Tiempo-Espacio

A menudo es posible reducir tiempo usando más espacio (memoización) o viceversa.

**Ejemplo**: Fibonacci con memoización
```c
int fibonacci_memo(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}
```

- **Complejidad temporal**: $O(n)$ (cada valor se calcula una vez)
- **Complejidad espacial**: $O(n)$ (arreglo de memoización + pila)

```{figure} 12/time_space_tradeoff.svg
:label: fig-tradeoff
:align: center

Ilustración del trade-off entre tiempo y espacio en el problema de Fibonacci.
```

## Límites Inferiores y Óptimalidad

### Límites Inferiores Basados en Información

Un **límite inferior** establece que ningún algoritmo puede resolver un problema más rápido que cierta complejidad.

#### Teorema: Ordenamiento por Comparación

**Enunciado**: Cualquier algoritmo que ordene $n$ elementos mediante comparaciones requiere al menos $\Omega(n \log n)$ comparaciones en el peor caso.

**Demostración** (árbol de decisión):

1. Un algoritmo de ordenamiento por comparación puede modelarse como un árbol binario de decisión
2. Cada hoja representa una permutación posible de los $n$ elementos
3. Hay $n!$ permutaciones posibles, por tanto $n!$ hojas
4. Un árbol binario de altura $h$ tiene a lo más $2^h$ hojas
5. Necesitamos $2^h \geq n!$, es decir, $h \geq \log_2(n!)$

Por la aproximación de Stirling: $\log_2(n!) = \Theta(n \log n)$

**Conclusión**: Merge Sort, Heap Sort son **óptimos** para ordenamiento por comparación.

### Algoritmos Óptimos

Un algoritmo es **asintóticamente óptimo** si su complejidad coincide con el límite inferior teórico del problema.

**Ejemplos**:
- **Búsqueda en arreglo no ordenado**: $\Theta(n)$ (deben revisarse todos los elementos)
- **Multiplicación de matrices**: $O(n^{2.376})$ (algoritmo de Coppersmith-Winograd), límite inferior $\Omega(n^2)$

## Clases de Complejidad

Las **clases de complejidad** agrupan problemas según los recursos necesarios para resolverlos.

```{figure} 12/complexity_classes.svg
:label: fig-classes
:align: center
:width: 100%

Diagrama de las principales clases de complejidad y sus relaciones.
```

### Clase P

**Definición**: Problemas decidibles en tiempo polinomial por una máquina determinista.

$$
\mathbf{P} = \bigcup_{k=1}^{\infty} \mathbf{TIME}(n^k)
$$

**Ejemplos**:
- Ordenamiento
- Búsqueda
- Árboles de expansión mínima
- Camino más corto

### Clase NP

**Definición**: Problemas cuya solución puede **verificarse** en tiempo polinomial.

**Ejemplos**:
- SAT (satisfacibilidad booleana)
- Coloración de grafos
- Problema del viajante
- Subset Sum

### Problemas NP-Completos

Un problema es **NP-Completo** si:
1. Está en NP
2. Todo problema en NP se reduce a él en tiempo polinomial

**Teorema de Cook-Levin**: SAT es NP-Completo.

**Implicación**: Si algún problema NP-Completo tiene solución en P, entonces $\mathbf{P} = \mathbf{NP}$ (uno de los problemas del milenio no resueltos).

### Problemas NP-Hard

Un problema es **NP-Hard** si todo problema NP se reduce a él, pero no necesariamente está en NP.

**Ejemplo**: El problema de la parada (Halting Problem) es indecidible, por tanto NP-Hard pero no en NP.

## Ejemplos Detallados de Análisis

### Ejemplo 1: Búsqueda del Máximo

```c
int buscar_maximo(int arr[], int n) {
    int max = arr[0];          // O(1)
    
    for (int i = 1; i < n; i++) {  // n-1 iteraciones
        if (arr[i] > max) {    // O(1)
            max = arr[i];      // O(1)
        }
    }
    
    return max;  // O(1)
}
```

**Análisis**:
- Inicialización: $O(1)$
- Lazo: $(n-1) \times O(1) = O(n)$
- **Complejidad total**: $T(n) = O(1) + O(n) + O(1) = O(n)$
- **Optimalidad**: Es óptimo porque debemos examinar todos los elementos al menos una vez para garantizar que encontramos el máximo

### Ejemplo 2: Búsqueda de Duplicados

```c
// Versión ingenua: O(n²)
bool tiene_duplicados_ingenuo(int arr[], int n) {
    for (int i = 0; i < n; i++) {           // n iteraciones
        for (int j = i + 1; j < n; j++) {   // (n-i-1) iteraciones
            if (arr[i] == arr[j]) {
                return true;  // O(1)
            }
        }
    }
    return false;
}
```

**Análisis**:
$$
T(n) = \sum_{i=0}^{n-1} \sum_{j=i+1}^{n-1} O(1) = \sum_{i=0}^{n-1} (n-i-1) = \frac{n(n-1)}{2} \in O(n^2)
$$

```c
// Versión optimizada: O(n log n) con ordenamiento previo
bool tiene_duplicados_ordenado(int arr[], int n) {
    qsort(arr, n, sizeof(int), comparar);  // O(n log n)
    
    for (int i = 0; i < n - 1; i++) {      // O(n)
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    
    return false;
}
```

**Análisis**: $T(n) = O(n \log n) + O(n) = O(n \log n)$

### Ejemplo 3: Torres de Hanoi

```c
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}
```

**Análisis mediante recurrencia**:
$$
\begin{align}
T(n) &= 2T(n-1) + O(1) \\
T(1) &= O(1)
\end{align}
$$

**Solución por sustitución**:
$$
\begin{align}
T(n) &= 2T(n-1) + 1 \\
     &= 2(2T(n-2) + 1) + 1 = 4T(n-2) + 2 + 1 \\
     &= 8T(n-3) + 4 + 2 + 1 \\
     &= 2^k T(n-k) + (2^{k-1} + 2^{k-2} + \cdots + 2 + 1) \\
     &= 2^k T(n-k) + (2^k - 1)
\end{align}
$$

Cuando $k = n-1$:
$$
T(n) = 2^{n-1}T(1) + 2^{n-1} - 1 = 2^{n-1} + 2^{n-1} - 1 = 2^n - 1 \in \Theta(2^n)
$$

**Conclusión**: Torres de Hanoi es inherentemente exponencial. No existe solución más eficiente.

## Ejercicios

````{exercise}
:label: ejer-comp-1

Determiná la complejidad temporal de los siguientes fragmentos de código:

a)
```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        printf("%d ", i * j);
    }
}
```

b)
```c
for (int i = 1; i < n; i *= 3) {
    for (int j = 0; j < n; j++) {
        printf("%d ", i + j);
    }
}
```

c)
```c
void misterio(int n) {
    if (n <= 1) return;
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    misterio(n / 3);
    misterio(n / 3);
}
```
````

````{solution} ejer-comp-1
:class: dropdown

a) $O(n^2)$
- Lazo externo: $n$ iteraciones
- Lazo interno: $i$ iteraciones (depende de $i$)
- Total: $\sum_{i=0}^{n-1} i = \frac{n(n-1)}{2} \in O(n^2)$

b) $O(n \log n)$
- Lazo externo: $\log_3 n$ iteraciones (crece multiplicativamente)
- Lazo interno: $n$ iteraciones
- Total: $n \times \log_3 n \in O(n \log n)$

c) $O(n)$
- Recurrencia: $T(n) = 2T(n/3) + O(n)$
- Por Teorema Maestro: $a=2, b=3, f(n)=n$
- $\log_b a = \log_3 2 \approx 0.631 < 1$
- Caso 3: $T(n) \in \Theta(n)$
````

```{exercise}
:label: ejer-comp-2

Demostrá que $f(n) = 3n^2 + 5n + 2 \in \Theta(n^2)$ usando la definición formal de Big-Theta.
```

````{solution} ejer-comp-2
:class: dropdown

Debemos encontrar constantes $c_1, c_2, n_0$ tales que:
$$
c_1 n^2 \leq 3n^2 + 5n + 2 \leq c_2 n^2 \quad \forall n \geq n_0
$$

**Cota inferior** ($c_1 n^2 \leq 3n^2 + 5n + 2$):
- Tomemos $c_1 = 3$
- Para $n \geq 1$: $3n^2 \leq 3n^2 + 5n + 2$ ✓

**Cota superior** ($3n^2 + 5n + 2 \leq c_2 n^2$):
- Necesitamos $c_2$ tal que $3n^2 + 5n + 2 \leq c_2 n^2$
- Para $n \geq 1$: $5n \leq 5n^2$ y $2 \leq 2n^2$
- Entonces: $3n^2 + 5n + 2 \leq 3n^2 + 5n^2 + 2n^2 = 10n^2$
- Tomemos $c_2 = 10$

**Conclusión**: Con $c_1 = 3$, $c_2 = 10$, $n_0 = 1$:
$$
3n^2 \leq 3n^2 + 5n + 2 \leq 10n^2 \quad \forall n \geq 1
$$

Por tanto, $f(n) \in \Theta(n^2)$.
````

```{exercise}
:label: ejer-comp-3

Implementá un algoritmo para encontrar los dos elementos más grandes en un arreglo y analizá su complejidad. Compará tu solución con el enfoque ingenuo de ordenar el arreglo completo.
```

````{solution} ejer-comp-3
:class: dropdown

**Solución óptima**: $O(n)$

```c
void dos_maximos(int arr[], int n, int *max1, int *max2) {
    // Inicializar
    if (arr[0] > arr[1]) {
        *max1 = arr[0];
        *max2 = arr[1];
    } else {
        *max1 = arr[1];
        *max2 = arr[0];
    }
    
    // Un solo recorrido: O(n)
    for (int i = 2; i < n; i++) {
        if (arr[i] > *max1) {
            *max2 = *max1;
            *max1 = arr[i];
        } else if (arr[i] > *max2) {
            *max2 = arr[i];
        }
    }
}
```

**Análisis**:
- Un único recorrido del arreglo: $O(n)$
- Operaciones constantes por elemento
- **Complejidad**: $O(n)$

**Comparación con ordenamiento**:
- Ordenar todo el arreglo: $O(n \log n)$
- Tomar los dos últimos elementos: $O(1)$
- **Complejidad total**: $O(n \log n)$

**Conclusión**: La solución óptima es asintóticamente mejor ($O(n)$ vs $O(n \log n)$).
````

## Referencias y Lecturas Complementarias

### Textos Fundamentales

- Cormen, T. H., Leiserson, C. E., Rivert, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press. Capítulos 3-4: Growth of Functions y Divide-and-Conquer.
  
- Sedgewick, R., & Flajolet, P. (2013). *An Introduction to the Analysis of Algorithms* (2nd ed.). Addison-Wesley.

- Knuth, D. E. (1997). *The Art of Computer Programming, Volume 1: Fundamental Algorithms* (3rd ed.). Addison-Wesley. Sección 1.2: Mathematical Preliminaries.

### Recursos Avanzados

- Graham, R. L., Knuth, D. E., & Patashnik, O. (1994). *Concrete Mathematics* (2nd ed.). Addison-Wesley. Excelente para técnicas de resolución de recurrencias.

- Arora, S., & Barak, B. (2009). *Computational Complexity: A Modern Approach*. Cambridge University Press. Para teoría de complejidad avanzada.

### Recursos en Línea

- MIT OpenCourseWare: 6.006 Introduction to Algorithms
- Khan Academy: Algoritmos y Análisis Asintótico
- Big-O Cheat Sheet: https://www.bigocheatsheet.com/

## Resumen

El análisis de complejidad es fundamental para:

1. **Predecir rendimiento**: Saber si un algoritmo será viable para el tamaño de entrada esperado
2. **Comparar algoritmos**: Elegir el más eficiente para cada situación
3. **Identificar cuellos de botella**: Localizar partes del código que necesitan optimización
4. **Establecer límites teóricos**: Determinar si un algoritmo es óptimo o puede mejorarse

### Puntos Clave

:::{important} Ideas Centrales

1. **Notación asintótica** ignora constantes y términos menores, enfocándose en el comportamiento para $n$ grande
2. **Big-O** da cota superior, **Omega** cota inferior, **Theta** cota ajustada
3. **Jerarquía**: $O(1) < O(\log n) < O(n) < O(n \log n) < O(n^2) < O(n^3) < O(2^n) < O(n!)$
4. **Teorema Maestro** resuelve recurrencias divide-y-conquista
5. **Límites inferiores** establecen qué es imposible mejorar (ej: $\Omega(n \log n)$ para ordenamiento)
6. **Trade-offs** entre tiempo y espacio son comunes
7. **Análisis amortizado** considera costo promedio en secuencias de operaciones
:::

### Guía Práctica de Decisión

Para elegir un algoritmo:

1. **¿Cuál es el tamaño típico de entrada?**
   - Pequeño ($n < 100$): Casi cualquier complejidad funciona
   - Mediano ($n \sim 10^4$): Evitar $O(n^3)$ o peor
   - Grande ($n > 10^6$): Necesario $O(n)$ o $O(n \log n)$

2. **¿Importa más tiempo o espacio?**
   - Tiempo crítico: Considera usar más memoria (memoización, tablas hash)
   - Espacio limitado: Acepta algoritmos más lentos si usan menos memoria

3. **¿Es un problema conocido?**
   - Usa algoritmos estándar óptimos cuando existan
   - Para problemas NP-completos, considera aproximaciones o heurísticas

El análisis de complejidad no reemplaza la medición empírica, pero proporciona garantías teóricas esenciales para el diseño de software robusto y escalable.
