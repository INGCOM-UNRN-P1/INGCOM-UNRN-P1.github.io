---
title: Análisis de Complejidad Algorítmica
short_title: 14 - Complejidad
subtitle: Fundamentos matemáticos del análisis asintótico
---

(complejidad-introduccion)=
## Introducción: El Estudio de la Eficiencia

El **análisis de algoritmos** es una disciplina fundamental en la ciencia de la
computación que se enfoca en cuantificar los recursos que un algoritmo consume.
Su propósito es predecir, de manera formal y rigurosa, cómo se comportará un
algoritmo en términos de tiempo de ejecución y uso de memoria a medida que el
tamaño de la entrada de datos crece.

El objetivo principal no es obtener tiempos exactos en segundos —una métrica
volátil que depende del hardware, el compilador y el sistema operativo— sino
establecer una base teórica para:

1.  **Comparar algoritmos**: Determinar objetivamente cuál de dos algoritmos es
    más eficiente para resolver un mismo problema.
2.  **Predecir la escalabilidad**: Entender si un algoritmo seguirá siendo
    viable cuando el volumen de datos aumente de miles a millones o miles de
    millones de registros.
3.  **Optimizar el código**: Identificar los cuellos de botella y las partes
    críticas de un programa que más impactan en su rendimiento.

Para lograr esto, la herramienta central es el **análisis asintótico**.

:::{tip} Aplicación a Estructuras de Datos
El análisis de complejidad es esencial para comparar diferentes implementaciones de Tipos de Datos Abstractos. Por ejemplo, ¿cuándo conviene usar una lista enlazada vs. un arreglo? ¿Una pila con arreglo o con nodos? Estas decisiones se fundamentan en análisis de complejidad. Para ver aplicaciones concretas de estos conceptos a estructuras de datos fundamentales, consultá el apunte sobre {ref}`TAD, Pilas y Colas <apunte/13_tad.md>`.
:::

## Análisis Asintótico: Enfocándose en lo que Importa

El análisis asintótico es una metodología matemática que describe el
comportamiento de una función en su límite, es decir, cuando el tamaño de la
entrada ($n$) se vuelve arbitrariamente grande (tiende al infinito). Este
enfoque nos permite abstraernos de los detalles de la implementación y del
hardware, y concentrarnos en la **tasa de crecimiento** intrínseca del
algoritmo.

Al analizar una función de costo como $T(n) = 3n^2 + 100n + 500$, observamos que
para valores grandes de $n$, el término $3n^2$ domina a los demás. El análisis
asintótico nos permite simplificar esta expresión a su orden de crecimiento, que
es $n^2$, ignorando constantes multiplicativas ($3$) y términos de menor orden
($100n + 500$).

## Las Notaciones Asintóticas: O, Ω, y Θ

Para formalizar este análisis, utilizamos un conjunto de notaciones que
describen los límites del crecimiento de la función de costo de un algoritmo.

### 1. Notación Big O (O) - Cota Superior (Peor Caso)

La notación **Big O** es la más utilizada en la práctica, ya que describe una
**cota superior asintótica**. Nos ofrece una garantía sobre el rendimiento del
algoritmo: nunca será peor que esta cota.

- **Definición Intuïtiva**: Una función $f(n)$ es $O(g(n))$ si su tasa de
  crecimiento es **igual o más lenta** que la de $g(n)$ para entradas
  suficientemente grandes.
- **Definición Formal**: $f(n) = O(g(n))$ si existen constantes positivas $c$ y
  $n_0$ tales que $0 \le f(n) \le c \cdot g(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **peor caso** de ejecución de un algoritmo.

### 2. Notación Omega (Ω) - Cota Inferior (Mejor Caso)

La notación **Omega** describe una **cota inferior asintótica**. Nos garantiza
que el rendimiento del algoritmo nunca será mejor que esta cota.

- **Definición Intuïtiva**: Una función $f(n)$ es $\Omega(g(n))$ si su tasa de
  crecimiento es **igual o más rápida** que la de $g(n)$.
- **Definición Formal**: $f(n) = \Omega(g(n))$ si existen constantes positivas
  $c$ y $n_0$ tales que $0 \le c \cdot g(n) \le f(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **mejor caso** de ejecución.

### 3. Notación Theta (Θ) - Cota Ajustada (Caso Exacto)

La notación **Theta** proporciona la descripción más precisa del comportamiento
de un algoritmo, acotándolo tanto por arriba como por abajo.

- **Definición Intuïtiva**: Una función $f(n)$ es $\Theta(g(n))$ si su tasa de
  crecimiento es **exactamente la misma** que la de $g(n)$.
- **Relación**: $f(n) = \Theta(g(n))$ si y solo si $f(n) = O(g(n))$ y
  $f(n) = \Omega(g(n))$.
- **Uso Práctico**: Describe el comportamiento del algoritmo de forma ajustada,
  a menudo representando el **caso promedio** o un escenario donde el mejor y el
  peor caso coinciden.

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

```{figure} 14/complexity_hierarchy.svg
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

:::{note} Estructuras de Datos con Acceso $O(1)$
Los arreglos proporcionan acceso por índice en tiempo constante, una de sus ventajas principales. En contraste, las listas enlazadas requieren $O(n)$ para acceder a un elemento arbitrario. Esta diferencia fundamental se analiza en detalle en el apunte sobre {ref}`TAD, Pilas y Colas <apunte/13_tad.md>`.
:::

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

:::{note} Búsqueda en Estructuras de Datos
La búsqueda lineal $O(n)$ es necesaria en estructuras sin orden, como listas enlazadas o arreglos no ordenados. Esta es una operación fundamental en muchos TADs. Para comparar las complejidades de búsqueda en diferentes estructuras (pilas, colas, listas), consultá {ref}`TAD, Pilas y Colas <apunte/13_tad.md>`.
:::

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

```{figure} 14/growth_comparison.svg
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

```{figure} 14/master_theorem.svg
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

:::{tip} Análisis Amortizado en Pilas y Colas
Este mismo análisis se aplica a las pilas implementadas con arreglos dinámicos. Para ver ejemplos concretos de cómo el análisis amortizado justifica la eficiencia de las operaciones `push` en pilas con arreglos, consultá la sección sobre pilas en el apunte de {ref}`TAD, Pilas y Colas <apunte/13_tad.md>`.
:::

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

```{figure} 14/time_space_tradeoff.svg
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

## Más Allá: Una Introducción a la Teoría de la Complejidad (P vs. NP)

Mientras que el análisis de algoritmos se enfoca en determinar la eficiencia de
una solución específica, la **teoría de la complejidad** aborda una pregunta más
fundamental: ¿cuál es la dificultad _inherente_ de un problema? No se pregunta
"¿cuán rápido es mi algoritmo para ordenar?", sino "¿cuán rápido _puede ser_
cualquier algoritmo que ordene?".

Esta disciplina clasifica los problemas computacionales en **clases de
complejidad** basadas en los recursos (tiempo y memoria) que se requieren para
resolverlos en el peor de los casos, independientemente del algoritmo específico
utilizado.

## Problemas de Decisión y el Modelo de Cómputo

Para formalizar el estudio, la teoría se centra en los **problemas de
decisión**: aquellos que pueden ser respondidos con un simple "sí" o "no".
Aunque parece limitante, muchos problemas más complejos (como los de
optimización) pueden reformularse como una serie de problemas de decisión.

- **Ejemplo de Optimización**: "¿Cuál es la ruta más corta que visita todas
  estas ciudades?"
- **Ejemplo de Decisión**: "Dadas estas ciudades, ¿existe una ruta que las
  visite a todas y cuya longitud total sea menor que $K$ kilómetros?"

El modelo formal de cómputo utilizado para definir estas clases es la **Máquina
de Turing**, un autómata teórico que puede simular la lógica de cualquier
algoritmo computacional.

## La Clase P (Tiempo Polinomial)

La clase **P** contiene todos los problemas de decisión que pueden ser
**resueltos** por una Máquina de Turing determinista en **tiempo polinomial**.

- **Tiempo Polinomial**: Significa que el tiempo de ejecución del peor caso está
  acotado por una función polinómica del tamaño de la entrada $n$, es decir,
  $O(n^k)$ para alguna constante $k$.
- **Significado Intuïtivo**: La clase P representa el conjunto de problemas que
  consideramos "eficientemente resolubles" o "**tratables**". A medida que la
  entrada crece, el tiempo de ejecución aumenta a una tasa manejable.

**Ejemplos de problemas en P**:

- Ordenamiento de una lista.
- Búsqueda de un elemento en un arreglo.
- Determinar si un número es primo.
- Encontrar el camino más corto en un grafo (Algoritmo de Dijkstra).

## La Clase NP (Tiempo Polinomial No Determinista)

Aquí es donde surge una de las mayores confusiones en la informática. **NP**
_no_ significa "No Polinomial". Significa **Tiempo Polinomial No Determinista**.

Existen dos definiciones equivalentes y muy importantes:

1.  **Definición Formal**: La clase NP es el conjunto de problemas de decisión
    que pueden ser resueltos por una **Máquina de Turing no determinista** en
    tiempo polinomial. (Una máquina no determinista puede explorar múltiples
    caminos de cómputo simultáneamente).
2.  **Definición Práctica (y más útil)**: La clase NP es el conjunto de
    problemas de decisión para los cuales, si se nos proporciona una posible
    solución (un "certificado" o "testigo"), podemos **verificar** si es
    correcta en tiempo polinomial.

- **Significado Intuïtivo**: NP es la clase de problemas cuyas soluciones son
  "fáciles de verificar", aunque encontrarlas pueda ser muy difícil.

**Ejemplo Clásico: El Problema de Satisfacibilidad Booleana (SAT)**

- **Problema**: Dada una fórmula lógica booleana, ¿existe una asignación de
  valores de verdad (verdadero/falso) a sus variables que haga que toda la
  fórmula sea verdadera?
- **Encontrar la solución**: Puede ser extremadamente difícil. Con $n$
  variables, hay $2^n$ posibles asignaciones que probar (fuerza bruta).
- **Verificar una solución**: Si alguien te da una asignación concreta (ej:
  $x_1$=V, $x_2$=F, ...), es trivialmente fácil y rápido (tiempo polinomial)
  sustituir esos valores en la fórmula y comprobar si el resultado es verdadero.

Por lo tanto, SAT está en NP.

## La Pregunta del Millón de Dólares: ¿P = NP?

Claramente, si un problema puede ser resuelto rápidamente (está en P), entonces
su solución también puede ser verificada rápidamente. Esto significa que **la
clase P está contenida dentro de la clase NP**.

La pregunta fundamental, uno de los siete Problemas del Milenio del Instituto
Clay de Matemáticas, es: **¿Son estas dos clases realmente la misma? ¿Es P igual
a NP?**

- **Traducción**: "Si una solución a un problema puede ser verificada
  eficientemente, ¿puede esa solución también ser encontrada eficientemente?"

Nadie ha sido capaz de probarlo en ninguna de las dos direcciones. Sin embargo,
el consenso abrumador entre los científicos de la computación es que **P ≠ NP**.

### Implicaciones de la Respuesta

- **Si P = NP**: Sería una revolución. Problemas que hoy consideramos
  intratables (en logística, criptografía, investigación de proteínas, IA)
  tendrían soluciones eficientes. La creatividad podría ser automatizada, ya que
  verificar la "belleza" de una prueba matemática o una composición musical es a
  menudo más fácil que crearla.
- **Si P ≠ NP**: Confirma que existen problemas fundamentalmente "duros" que no
  pueden ser resueltos eficientemente. Para estos problemas, debemos confiar en
  algoritmos de aproximación, heurísticas o soluciones para casos específicos,
  sabiendo que una solución general y rápida no es posible.

## Reducciones y la Noción de "El Problema más Difícil"

Para clasificar la dificultad relativa de los problemas dentro de NP, se utiliza
el concepto de **reducción en tiempo polinomial**. Un problema A se "reduce" a
un problema B si podemos transformar cualquier instancia de A en una instancia
de B de tal manera que la solución para B nos da la solución para A, y esta
transformación toma tiempo polinomial.

- **Significado**: Si A se reduce a B, entonces A "no es más difícil que" B.

### NP-Hard y NP-Completo

- **NP-Hard (NP-Duro)**: Un problema es NP-Hard si **todo problema en NP** se
  puede reducir a él en tiempo polinomial. Estos son los problemas que son "al
  menos tan difíciles como" cualquier problema en NP.
- **NP-Completo (NPC)**: Un problema es NP-Completo si cumple dos condiciones:
  1.  Está en NP (sus soluciones son verificables en tiempo polinomial).
  2.  Es NP-Hard.

Los problemas NP-Completos son, en esencia, los **problemas más difíciles de la
clase NP**.

El **Teorema de Cook-Levin (1971)** fue el hito que demostró que el problema
**SAT** es NP-Completo. Desde entonces, se ha demostrado que miles de otros
problemas importantes también lo son, mediante reducciones a partir de SAT u
otros problemas NPC conocidos.

**Ejemplos de Problemas NP-Completos**:

- Problema del Viajante (versión de decisión).
- Coloreado de Grafos.
- El juego Sudoku (generalizado a un tablero de $n^2 \times n^2$).

La importancia de los problemas NPC es inmensa: si se encontrara un algoritmo de
tiempo polinomial para _un solo_ problema NP-Completo, automáticamente
tendríamos un algoritmo eficiente para _todos_ los problemas en NP, lo que
probaría que **P = NP**.

### Visualización de las Clases de Complejidad

Asumiendo que P ≠ NP, la relación entre estas clases se puede visualizar de la
siguiente manera:

```{mermaid}
graph TD
    subgraph NP
        subgraph P
            A[Ordenamiento]
            B[Búsqueda Binaria]
        end
        subgraph "NP-Completo (NPC)"
            C[SAT]
            D[Viajante]
            E[Sudoku]
        end
        F[Factorización de Enteros]
    end
    subgraph "NP-Hard"
        G[Problema de Parada]
    end

    P --> F
    F --> C
    NPC --> G

    style P fill:#cde4ff,stroke:#333
    style NPC fill:#ffcdd2,stroke:#333
    style NP fill:#fff9c4,stroke:#666,stroke-dasharray: 5 5
    style NPHard fill:#e1bee7,stroke:#666,stroke-dasharray: 5 5
```

Este diagrama ilustra que P y NPC son subconjuntos de NP. Los problemas NP-Hard
pueden estar dentro o fuera de NP. El problema de la **Factorización de
Enteros**, en el que se basa gran parte de la criptografía moderna, es un
ejemplo fascinante: está en NP, pero no se sabe si es NP-Completo o si está en
P.


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
