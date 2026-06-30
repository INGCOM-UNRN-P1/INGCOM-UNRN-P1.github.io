---
title: Análisis de Complejidad Algorítmica
short_title: Complejidad
subtitle: Fundamentos matemáticos del análisis asintótico
---

(capitulo-complejidad)=
# Referencias y Lecturas Complementarias

## Introducción



## Desarrollo

(introduccion-el-estudio-de-la-eficiencia)=
### Introducción: El Estudio de la Eficiencia


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
El análisis de complejidad es esencial para comparar diferentes implementaciones de Tipos de Datos Abstractos. Por ejemplo, ¿cuándo conviene usar una lista enlazada vs. un arreglo? ¿Una pila con arreglo o con nodos? Estas decisiones se fundamentan en análisis de complejidad. Para ver aplicaciones concretas de estos conceptos a estructuras de datos fundamentales, consultá el apunte sobre [TAD, Pilas y Colas](6_tad.md).
:::


(analisis-asintotico-enfocandose-en-lo-que-importa)=
### Análisis Asintótico: Enfocándose en lo que Importa


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


(las-notaciones-asintoticas-o-y)=
### Las Notaciones Asintóticas: O, Ω, y Θ


Para formalizar este análisis, utilizamos un conjunto de notaciones que
describen los límites del crecimiento de la función de costo de un algoritmo.

(1-notacion-big-o-o-cota-superior-peor-caso)=
#### 1. Notación Big O (O) - Cota Superior (Peor Caso)

La notación **Big O** es la más utilizada en la práctica, ya que describe una
**cota superior asintótica**. Nos ofrece una garantía sobre el rendimiento del
algoritmo: nunca será peor que esta cota.

- **Definición Intuitiva**: Una función $f(n)$ pertenece a $O(g(n))$ si su tasa de
  crecimiento es **igual o más lenta** que la de $g(n)$ para entradas
  suficientemente grandes.
- **Definición Formal**: $f(n) \in O(g(n))$ si existen constantes positivas $c$ y
  $n_0$ tales que $0 \le f(n) \le c \cdot g(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **peor caso** de ejecución de un algoritmo.

```{figure} 10/big_o_definition.svg
:label: fig-big-o-definition
:align: center
:width: 85%

Representación gráfica de la cota superior asintótica $f(n) \in O(g(n))$. A partir de $n_0$, la función $c \cdot g(n)$ es siempre mayor o igual a $f(n)$.
```

:::{note} Pertenencia vs. Igualdad
Aunque tradicionalmente en computación se escribe $f(n) = O(g(n))$ como un abuso de lenguaje, la notación matemáticamente rigurosa desde la teoría de conjuntos establece que $O(g(n))$ es un conjunto de funciones. Por lo tanto, se utiliza la relación de pertenencia: $f(n) \in O(g(n))$. En este apunte priorizamos la notación de conjuntos por su rigor conceptual.
:::

(2-notacion-omega-cota-inferior-mejor-caso)=
#### 2. Notación Omega (Ω) - Cota Inferior (Mejor Caso)

La notación **Omega** describe una **cota inferior asintótica**. Nos garantiza
que el rendimiento del algoritmo nunca será mejor que esta cota.

- **Definición Intuitiva**: Una función $f(n)$ pertenece a $\Omega(g(n))$ si su tasa de
  crecimiento es **igual o más rápida** que la de $g(n)$.
- **Definición Formal**: $f(n) \in \Omega(g(n))$ si existen constantes positivas
  $c$ y $n_0$ tales que $0 \le c \cdot g(n) \le f(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **mejor caso** de ejecución.

(3-notacion-theta-cota-ajustada-caso-exacto)=
#### 3. Notación Theta (Θ) - Cota Ajustada (Caso Exacto)

La notación **Theta** proporciona la descripción más precisa del comportamiento
de un algoritmo, acotándolo tanto por arriba como por abajo.

- **Definición Intuitiva**: Una función $f(n)$ pertenece a $\Theta(g(n))$ si su tasa de
  crecimiento es **exactamente la misma** que la de $g(n)$.
- **Relación**: $f(n) \in \Theta(g(n))$ si y solo si $f(n) \in O(g(n))$ y
  $f(n) \in \Omega(g(n))$.
- **Uso Práctico**: Describe el comportamiento del algoritmo de forma ajustada,
  a menudo representando el **caso promedio** o un escenario donde el mejor y el
  peor caso coinciden.

```{figure} 10/big_theta_definition.svg
:label: fig-big-theta-definition
:align: center
:width: 85%

Representación gráfica de la cota ajustada asintótica $f(n) \in \Theta(g(n))$. La función $f(n)$ queda atrapada entre las cotas $c_1 \cdot g(n)$ y $c_2 \cdot g(n)$ para todo $n \ge n_0$.
```

(notaciones-menos-comunes)=
#### Notaciones Menos Comunes

##### Little-o (Límite Asintótico Estricto)

$f(n) \in o(g(n))$ si para toda constante $c > 0$, existe $n_0$ tal que:

$$
0 \leq f(n) < c \cdot g(n) \quad \forall n \geq n_0
$$

Equivalentemente: $\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$

**Ejemplo**: $n \in o(n^2)$ pero $n \notin o(n)$

##### Little-omega (Límite Inferior Estricto)

$f(n) \in \omega(g(n))$ si para toda constante $c > 0$, existe $n_0$ tal que:

$$
0 \leq c \cdot g(n) < f(n) \quad \forall n \geq n_0
$$

(propiedades-algebraicas)=
#### Propiedades Algebraicas

Las notaciones asintóticas tienen propiedades útiles:

1. **Transitividad**: Si $f \in O(g)$ y $g \in O(h)$, entonces $f \in O(h)$
2. **Reflexividad**: $f \in \Theta(f)$
3. **Simetría**: Si $f \in \Theta(g)$, entonces $g \in \Theta(f)$
4. **Suma**: $O(f) + O(g) = O(\max(f, g))$
5. **Producto**: $O(f) \cdot O(g) = O(f \cdot g)$

(ejercicios-de-notaciones-asintoticas)=
#### Ejercicios de Notaciones Asintóticas








(jerarquia-de-complejidades)=
### Jerarquía de Complejidades


```{figure} 10/complexity_hierarchy.svg
:label: fig-hierarchy
:align: center
:width: 100%

Jerarquía de las clases de complejidad más comunes, ordenadas de más eficiente a menos eficiente.
```

(clasificacion-detallada)=
#### Clasificación Detallada

##### Constante: $O(1)$

**Características**:
- El tiempo no depende del tamaño de entrada
- Más eficiente posible
- Ejemplo: acceso a un elemento de arreglo, operaciones aritméticas

**Código ejemplo**:
```{code-block}c
:linenos:
int obtener_primero(int arr[], int n) {
    return arr[0];  // O(1): una operación, independiente de n
}
```

:::{note} Estructuras de Datos con Acceso $O(1)$
Los arreglos proporcionan acceso por índice en tiempo constante, una de sus ventajas principales. En contraste, las listas enlazadas requieren $O(n)$ para acceder a un elemento arbitrario. Esta diferencia fundamental se analiza en detalle en el apunte sobre [TAD, Pilas y Colas](6_tad.md).
:::

##### Logarítmica: $O(\log n)$

**Características**:
- Crece muy lentamente
- Típica de algoritmos que dividen el problema a la mitad en cada paso
- **Base del logaritmo irrelevante asintóticamente**: la base del logaritmo no afecta a la clase de complejidad porque cambiar de base equivale a multiplicar por una constante.
  Si aplicamos la fórmula de cambio de base:
  $$
  \log_a n = \frac{\log_b n}{\log_b a} = \left(\frac{1}{\log_b a}\right) \log_b n
  $$
  Dado que $\frac{1}{\log_b a}$ es una constante para bases fijas $a$ y $b$, por definición asintótica se cumple que $\log_a n \in \Theta(\log_b n)$ (por ejemplo, $\log_2 n \in \Theta(\log_{10} n)$).

**Ejemplos**: búsqueda binaria, operaciones en árboles balanceados

**Código ejemplo**:
```{code-block}c
:linenos:
// Búsqueda binaria: O(log n)
// Precondición: el arreglo 'arr' debe estar ordenado de menor a mayor.
int busqueda_binaria(int arr[], int n, int clave) {
    int izq = 0, der = n - 1;
    
    while (izq <= der) {  // Se reduce a la mitad en cada lazo
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

**Análisis**:
:::{important}
La búsqueda binaria asume como precondición fundamental que el arreglo de entrada se encuentra estrictamente ordenado (regla {ref}`0x2003h`). Si esta precondición no se cumple, el algoritmo no es correcto y su comportamiento es impredecible.
:::

En cada iteración del lazo, el espacio de búsqueda se reduce a la mitad. Si inicialmente hay $n$ elementos, después de $k$ lazos quedan $\frac{n}{2^k}$. El algoritmo termina cuando $\frac{n}{2^k} = 1$, es decir, $k = \log_2 n$.

##### Lineal: $O(n)$

**Características**:
- Tiempo proporcional al tamaño de entrada
- Óptimo para problemas que requieren examinar todos los datos
- Duplicar la entrada duplica el tiempo

**Ejemplos**: búsqueda secuencial, recorrer un arreglo, suma de elementos

**Código ejemplo**:
```{code-block}c
:linenos:
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
La búsqueda lineal $O(n)$ es necesaria en estructuras sin orden, como listas enlazadas o arreglos no ordenados. Esta es una operación fundamental en muchos TADs. Para comparar las complejidades de búsqueda en diferentes estructuras (pilas, colas, listas), consultá [TAD, Pilas y Colas](6_tad.md).
:::

##### Log-Lineal: $O(n \log n)$

**Características**:
- Complejidad de algoritmos óptimos de ordenamiento por comparación
- Crece más que lineal pero menos que cuadrático
- Muy eficiente en la práctica

**Ejemplos**: Merge Sort, Heap Sort, Quick Sort (promedio)

**Código ejemplo (Merge Sort)**:
```{code-block}c
:linenos:
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

##### Cuadrática: $O(n^2)$

**Características**:
- Típica de algoritmos con dos lazos anidados
- Duplicar la entrada cuadruplica el tiempo
- Práctica para $n$ pequeño, inviable para $n$ grande

**Ejemplos**: Bubble Sort, Selection Sort, Insertion Sort

**Código ejemplo**:
```{code-block}c
:linenos:
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

##### Cúbica: $O(n^3)$

**Características**:
- Tres lazos anidados o algoritmos con subcubos
- Viable solo para $n$ pequeño

**Ejemplos**: multiplicación ingenua de matrices, algunos algoritmos de grafos

**Código ejemplo**:
```{code-block}c
:linenos:
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

##### Exponencial: $O(2^n)$

**Características**:
- Crece extremadamente rápido
- Inviable para $n > 30$ en la mayoría de casos
- Común en algoritmos de fuerza bruta

**Ejemplos**: subconjuntos de un conjunto, Torre de Hanoi, algunos problemas NP-completos

**Código ejemplo**:
```{code-block}c
:linenos:
// Fibonacci recursivo ingenuo: O(2^n)
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Dos llamadas recursivas
}
```

**Análisis**: La relación de recurrencia para el tiempo de ejecución es $T(n) = T(n-1) + T(n-2) + O(1)$. Para resolver la parte homogénea de esta ecuación de diferencias, $T(n) - T(n-1) - T(n-2) = 0$, proponemos una solución de la forma $T(n) = r^n$. Al sustituir, obtenemos la **ecuación característica**:
$$
r^2 - r - 1 = 0
$$
cuyas raíces son $r_1 = \frac{1+\sqrt{5}}{2} = \phi \approx 1.618$ (la razón áurea) y $r_2 = \frac{1-\sqrt{5}}{2} \approx -0.618$. La solución general de la recurrencia es una combinación lineal de ambas potencias, dominada asintóticamente por la raíz de mayor magnitud, por lo que $T(n) \in \Theta(\phi^n)$.

##### Factorial: $O(n!)$

**Características**:
- La complejidad más ineficiente de las comunes
- Solo viable para $n < 15$ aproximadamente
- Aparece en problemas de permutaciones

**Ejemplos**: generar todas las permutaciones, problema del viajante (fuerza bruta)

**Código ejemplo**:
```{code-block}c
:linenos:
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

```{figure} 10/growth_comparison.svg
:label: fig-growth
:align: center
:width: 100%

Comparación del crecimiento de diferentes funciones de complejidad para valores de $n$ hasta 100.
```

(tabla-comparativa-de-crecimiento)=
#### Tabla Comparativa de Crecimiento

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

(ejercicios-de-jerarquia-de-complejidades)=
#### Ejercicios de Jerarquía de Complejidades








(tecnicas-de-analisis)=
### Técnicas de Análisis


(analisis-de-lazos)=
#### Análisis de Lazos

##### Lazo Simple

```{code-block}c
:linenos:
for (int i = 0; i < n; i++) {
    // Operación O(1)
}
```

**Análisis**: $\sum_{i=0}^{n-1} O(1) = O(n)$

##### Lazos Anidados

```{code-block}c
:linenos:
for (int i = 0; i < n; i++) {       // n iteraciones
    for (int j = 0; j < n; j++) {   // n iteraciones
        // Operación O(1)
    }
}
```

**Análisis**: $\sum_{i=0}^{n-1} \sum_{j=0}^{n-1} O(1) = n \cdot n \cdot O(1) = O(n^2)$

##### Lazos con Dependencia

```{code-block}c
:linenos:
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

##### Lazo Logarítmico

```{code-block}c
:linenos:
for (int i = 1; i < n; i *= 2) {
    // Operación O(1)
}
```

**Análisis**: Si $i$ comienza en 1 y se duplica cada iteración, el lazo ejecuta $k$ veces donde $2^k = n$, es decir, $k = \log_2 n$. Por tanto, $O(\log n)$.

(analisis-de-recursion)=
#### Análisis de Recursión

##### Método de Sustitución

El **método de sustitución** (o método de inducción matemática) se utiliza para resolver recurrencias mediante dos etapas:
1. **Expandir (desarrollar) la relación de recurrencia** para adivinar el patrón de la solución.
2. **Probar la solución por inducción matemática** para verificar su exactitud formal.

**Ejemplo de desarrollo paso a paso:**
Consideremos la recurrencia $T(n) = T(n-1) + c$, donde $c$ es el costo constante de la operación básica ($O(1)$), con el caso base $T(1) = d$ (donde $d$ es otra constante).

1. **Expansión por sustitución sucesiva:**
   Comenzamos sustituyendo recursivamente la fórmula:
   * Paso 1: $T(n) = T(n-1) + c$
   * Paso 2: Sustituimos $T(n-1)$ usando la misma definición: $T(n-1) = T(n-2) + c$.
     $$T(n) = (T(n-2) + c) + c = T(n-2) + 2c$$
   * Paso 3: Sustituimos $T(n-2) = T(n-3) + c$:
     $$T(n) = (T(n-3) + c) + 2c = T(n-3) + 3c$$

2. **Generalización del patrón:**
   Podemos generalizar la expresión para el paso $k$:
   $$T(n) = T(n-k) + k \cdot c$$

3. **Aplicación del caso base:**
   Deseamos alcanzar el caso base $T(1)$. Para ello, definimos $n - k = 1$, lo que implica $k = n - 1$.
   Sustituyendo $k$ en nuestra ecuación generalizada:
   $$T(n) = T(1) + (n-1) \cdot c$$
   $$T(n) = d + c \cdot n - c$$
   $$T(n) = c \cdot n + (d - c)$$

Dado que $c$ y $d$ son constantes, la función de costo se reduce a una ecuación lineal:
$$T(n) \in \Theta(n)$$

##### Método del Árbol de Recursión

Antes de enunciar el Teorema Maestro, es fundamental visualizar cómo se distribuye el trabajo en un algoritmo recursivo de tipo divide y vencerás. El **árbol de recursión** es una herramienta gráfica donde:
- Cada nodo representa una llamada recursiva.
- El costo etiquetado en cada nodo es el trabajo no recursivo realizado en esa llamada específica.
- La suma del trabajo de todos los nodos en todos los niveles del árbol determina el costo total del algoritmo.

```{figure} 10/master_theorem.svg
:label: fig-master
:align: center

Árbol de recursión ilustrando el Teorema Maestro y cómo se distribuye el trabajo en cada nivel del árbol.
```

**Ejemplo de análisis con árbol**: Consideremos la recurrencia $T(n) = 2T(n/2) + n$ (con caso base $T(1) = O(1)$):

```
Nivel 0:                n              → costo: n
                       / \
Nivel 1:            n/2   n/2          → costo: n
                     / \   / \
Nivel 2:         n/4 n/4 n/4 n/4       → costo: n
                  ...
```
- **Cantidad de subproblemas por nivel**: En el nivel $j$, tenemos $2^j$ subproblemas.
- **Tamaño de cada subproblema**: En el nivel $j$, cada subproblema tiene tamaño $n/2^j$.
- **Costo del trabajo no recursivo por nivel**: En cada nivel $j$, la suma del trabajo es $2^j \times (n/2^j) = n$.
- **Altura del árbol (número de niveles)**: Dado que el tamaño del problema se divide por 2 en cada paso, el proceso finaliza cuando $n/2^j = 1$, es decir, tras $j = \log_2 n$ niveles.
- **Costo total**: Sumando todos los niveles, el costo total es $n \times \log_2 n$, lo que equivale a $\Theta(n \log n)$.

##### Teorema Maestro

El Teorema Maestro es una receta matemática que sistematiza este análisis para recurrencias de la forma general:
$$
T(n) = aT\left(\frac{n}{b}\right) + f(n)
$$
donde:
- $a \geq 1$ es la cantidad de subproblemas recursivos creados.
- $b > 1$ es el factor por el cual se divide el tamaño del problema original.
- $f(n)$ es una función asintóticamente positiva que representa el costo de la división y combinación del trabajo en el nivel actual.

Al comparar el trabajo en las hojas del árbol (que es $\Theta(n^{\log_b a})$) con el trabajo no recursivo en la raíz ($f(n)$), el Teorema Maestro determina cuál de los dos domina la complejidad asintótica:

**Caso 1 (Dominan las hojas)**: Si $f(n) \in O(n^{\log_b a - \epsilon})$ para algún $\epsilon > 0$, entonces:
$$
T(n) \in \Theta(n^{\log_b a})
$$

**Caso 2 (Trabajo balanceado)**: Si $f(n) \in \Theta(n^{\log_b a} \log^k n)$ para algún $k \geq 0$, entonces:
$$
T(n) \in \Theta(n^{\log_b a} \log^{k+1} n)
$$

**Caso 3 (Domina la raíz)**: Si $f(n) \in \Omega(n^{\log_b a + \epsilon})$ para algún $\epsilon > 0$, y se cumple la **condición de regularidad** ($a f(n/b) \leq c f(n)$ para alguna constante $c < 1$ y $n$ suficientemente grande), entonces:
$$
T(n) \in \Theta(f(n))
$$

La **condición de regularidad** garantiza que la tasa de trabajo no recursivo decrezca geométricamente a medida que se desciende en el árbol de recursión. Si no se satisface esta condición, no se puede aplicar el Caso 3 del Teorema Maestro.

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


(analisis-amortizado)=
#### Análisis Amortizado

El **análisis amortizado** considera el costo promedio de una secuencia de operaciones, permitiendo que algunas operaciones sean costosas si la mayoría son baratas.

##### Método del Agregado

**Ejemplo**: Arreglo dinámico redimensionable en C.

Supongamos que implementamos un arreglo dinámico en C mediante una estructura que almacena un puntero, el tamaño actual y la capacidad máxima de almacenamiento. Cuando el arreglo alcanza su capacidad límite, duplicamos su tamaño utilizando `realloc`:

```{code-block}c
:linenos:
typedef struct {
    int *datos;
    size_t tamaño;
    size_t capacidad;
} arreglo_dinamico_t;

bool insertar_arreglo(arreglo_dinamico_t *arr, int valor) {
    if (arr->tamaño >= arr->capacidad) {
        size_t nueva_capacidad = arr->capacidad * 2;
        int *nuevo_espacio = realloc(arr->datos, nueva_capacidad * sizeof(int));
        if (nuevo_espacio == NULL) {
            return false;
        }
        arr->datos = nuevo_espacio;
        arr->capacidad = nueva_capacidad;
    }
    arr->datos[arr->tamaño] = valor;
    arr->tamaño++;
    return true;
}
```

Analicemos el costo de una secuencia de $n$ inserciones consecutivas en el lazo de carga, comenzando con una capacidad inicial de 1:
- Si la inserción no requiere redimensionamiento, toma tiempo constante: $1$ operación.
- Si requiere redimensionamiento, requiere reasignar memoria y copiar los elementos existentes, tomando $i$ operaciones (donde $i$ es el tamaño en ese momento).

Para $n$ inserciones (donde $n$ es una potencia de 2), el costo total acumulado es la suma de los accesos normales y los costos de copia por redimensionamiento:
$$
\text{Costo Total} = n + \sum_{j=0}^{\log_2 n} 2^j = n + (2^{\log_2 n + 1} - 1) = n + 2n - 1 < 3n
$$

**Costo amortizado**: Al dividir el costo total por la cantidad de operaciones, obtenemos $\frac{3n}{n} = O(1)$ por cada inserción individual.

:::{tip} Análisis Amortizado en Pilas y Colas
Este mismo análisis se aplica a las pilas implementadas con arreglos dinámicos. Para ver ejemplos concretos de cómo el análisis amortizado justifica la eficiencia de las operaciones `push` en pilas con arreglos, consultá la sección sobre pilas en el apunte de [TAD, Pilas y Colas](6_tad.md).
:::

##### Método del Potencial

El **método del potencial** analiza la complejidad amortizada definiendo una función potencial $\Phi$ sobre los estados de la estructura de datos. Esta función asocia un número real no negativo $\Phi(D_i)$ a la estructura tras la operación $i$.

El **costo amortizado** $\hat{c}_i$ de la $i$-ésima operación se define como:
$$\hat{c}_i = c_i + \Phi(D_i) - \Phi(D_{i-1})$$
donde $c_i$ es el costo real de la operación y $\Delta\Phi_i = \Phi(D_i) - \Phi(D_{i-1})$ es el cambio en el potencial.

###### Análisis del Arreglo Dinámico
Para un arreglo dinámico, definimos la función potencial después de la operación $i$ como:
$$\Phi_i = 2 \cdot t_i - c_i$$
donde $t_i$ es el tamaño actual (número de elementos) y $c_i$ es la capacidad actual. 

*Precondición de validez*: Como la capacidad es a lo sumo el doble del tamaño y al menos igual, tenemos que $\Phi_i \ge 0$. Inicialmente, con un arreglo vacío, $t_0 = 0$ y $c_0 = 0$, por lo que $\Phi_0 = 0$.

Analicemos los dos escenarios posibles para la $i$-ésima inserción:

####### Escenario 1: Inserción sin Redimensionamiento
El arreglo tiene espacio libre ($t_{i-1} < c_{i-1}$).
1. El **costo real** es constante: $c_i = 1$ (copiar el elemento en el arreglo).
2. El tamaño aumenta en uno ($t_i = t_{i-1} + 1$), y la capacidad permanece constante ($c_i = c_{i-1}$).
3. El cambio en el potencial es:
   $$\Delta\Phi_i = \Phi_i - \Phi_{i-1} = (2 \cdot t_i - c_i) - (2 \cdot t_{i-1} - c_{i-1})$$
   $$\Delta\Phi_i = (2(t_{i-1} + 1) - c_{i-1}) - (2 \cdot t_{i-1} - c_{i-1}) = 2$$
4. El **costo amortizado** calculado es:
   $$\hat{c}_i = c_i + \Delta\Phi_i = 1 + 2 = 3$$

####### Escenario 2: Inserción con Redimensionamiento
El arreglo está lleno ($t_{i-1} = c_{i-1}$). Para insertar, se debe duplicar la capacidad: $c_i = 2 \cdot c_{i-1}$.
1. El **costo real** de esta inserción implica alocar nueva memoria y copiar todos los elementos existentes más el nuevo: $c_i = t_{i-1} + 1$.
2. El tamaño aumenta en uno ($t_i = t_{i-1} + 1$), y la capacidad se duplica ($c_i = 2 \cdot t_{i-1}$).
3. Calculamos la variación del potencial $\Delta\Phi_i$:
   $$\Phi_{i-1} = 2 \cdot t_{i-1} - c_{i-1} = 2 \cdot t_{i-1} - t_{i-1} = t_{i-1}$$
   $$\Phi_i = 2 \cdot t_i - c_i = 2(t_{i-1} + 1) - 2 \cdot t_{i-1} = 2$$
   $$\Delta\Phi_i = \Phi_i - \Phi_{i-1} = 2 - t_{i-1}$$
4. El **costo amortizado** calculado es:
   $$\hat{c}_i = c_i + \Delta\Phi_i = (t_{i-1} + 1) + (2 - t_{i-1}) = 3$$

###### Conclusión
En ambos escenarios (con o sin redimensionamiento), el costo amortizado de una inserción en el arreglo dinámico es exactamente $3$, lo que demuestra formalmente que la operación de inserción tiene una complejidad de amortización constante:
$$\hat{c}_i \in \Theta(1)$$

(ejercicios-de-tecnicas-de-analisis)=
#### Ejercicios de Técnicas de Análisis








(complejidad-espacial)=
### Complejidad Espacial


La **complejidad espacial** mide la cantidad de memoria adicional que un algoritmo requiere.

(clasificacion)=
#### Clasificación

- **$O(1)$**: Espacio constante, independiente de la entrada
- **$O(\log n)$**: Típico de algoritmos recursivos que dividen el problema
- **$O(n)$**: Espacio lineal, como copiar un arreglo
- **$O(n^2)$**: Matrices cuadradas

(recursion-y-pila-de-llamadas)=
#### Recursión y Pila de Llamadas

Cada llamada recursiva ocupa espacio en la pila. La profundidad máxima de recursión determina la complejidad espacial.

**Ejemplo**: Fibonacci recursivo
```{code-block}c
:linenos:
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

- **Complejidad temporal**: $O(2^n)$
- **Complejidad espacial**: $O(n)$ (profundidad máxima de la pila)

(trade-off-tiempo-espacio)=
#### Trade-off Tiempo-Espacio

A menudo es posible reducir tiempo usando más espacio (memoización) o viceversa.

**Ejemplo**: Fibonacci con memoización
```{code-block}c
:linenos:
int fibonacci_memo(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}
```

- **Complejidad temporal**: $O(n)$ (cada valor se calcula una vez)
- **Complejidad espacial**: $O(n)$ (arreglo de memoización + pila)

```{figure} 10/time_space_tradeoff.svg
:label: fig-tradeoff
:align: center

Ilustración del trade-off entre tiempo y espacio en el problema de Fibonacci.
```

(ejercicios-de-complejidad-espacial)=
#### Ejercicios de Complejidad Espacial








(limites-inferiores-y-optimalidad)=
### Límites Inferiores y Óptimalidad


(limites-inferiores-basados-en-informacion)=
#### Límites Inferiores Basados en Información

Un **límite inferior** establece que ningún algoritmo puede resolver un problema más rápido que cierta complejidad.

##### Teorema: Ordenamiento por Comparación

**Enunciado**: Cualquier algoritmo que ordene $n$ elementos mediante comparaciones requiere al menos $\Omega(n \log n)$ comparaciones en el peor caso.

**Demostración** (árbol de decisión):

1. Un algoritmo de ordenamiento por comparación puede modelarse como un árbol binario de decisión.
2. Cada hoja representa una permutación posible de los $n$ elementos de entrada.
3. Hay $n!$ permutaciones posibles, por tanto, el árbol debe tener al menos $n!$ hojas.
4. Un árbol binario de altura $h$ tiene como máximo $2^h$ hojas.
5. Para que el árbol pueda representar todas las salidas válidas, se requiere que $2^h \geq n!$, lo que implica $h \geq \log_2(n!)$.
6. Demostramos la cota inferior de $\log_2(n!)$ expandiendo la sumatoria y acotándola inferiormente desde su término medio:
   $$
   \log_2(n!) = \sum_{i=1}^n \log_2 i \geq \sum_{i=n/2}^n \log_2 i \geq \sum_{i=n/2}^n \log_2(n/2) = \frac{n}{2} \log_2(n/2) = \frac{n}{2} (\log_2 n - 1) \in \Omega(n \log n)
   $$

**Conclusión**: Cualquier algoritmo basado en comparaciones requiere al menos $\Omega(n \log n)$ comparaciones en el peor caso. Algoritmos como Merge Sort y Heap Sort son, por lo tanto, **óptimos**.

(algoritmos-optimos)=
#### Algoritmos Óptimos

Un algoritmo es **asintóticamente óptimo** si su complejidad coincide con el límite inferior teórico del problema.

**Ejemplos**:
- **Búsqueda en arreglo no ordenado**: $\Theta(n)$ (deben revisarse todos los elementos)
- **Multiplicación de matrices**: $O(n^{2.376})$ (algoritmo de Coppersmith-Winograd), límite inferior $\Omega(n^2)$


(mas-alla-una-introduccion-a-la-teoria-de-la-complejidad-p-vs-np)=
### Más Allá: Una Introducción a la Teoría de la Complejidad (P vs. NP)


Mientras que el análisis de algoritmos se enfoca en determinar la eficiencia de
una solución específica, la **teoría de la complejidad** aborda una pregunta más
fundamental: ¿cuál es la dificultad _inherente_ de un problema? No se pregunta
"¿cuán rápido es mi algoritmo para ordenar?", sino "¿cuán rápido _puede ser_
cualquier algoritmo que ordene?".

Esta disciplina clasifica los problemas computacionales en **clases de
complejidad** basadas en los recursos (tiempo y memoria) que se requieren para
resolverlos en el peor de los casos, independientemente del algoritmo específico
utilizado.


(conceptos-de-complejidad-intratabilidad-y-las-clases-p-y-np)=
### Conceptos de Complejidad: Intratabilidad y las Clases P y NP


En el análisis de algoritmos, no solo nos interesa determinar la complejidad asintótica exacta, sino también clasificar los problemas según si son resolubles de forma eficiente en la práctica. Esta distinción introduce la noción de **intratabilidad**.

(problemas-tratables-vs-intratables)=
#### Problemas Tratables vs. Intratables
- **Problemas Tratables**: Son aquellos para los cuales existe un algoritmo que los resuelve en tiempo polinomial en el peor de los casos (es decir, $O(n^k)$ para alguna constante $k$). Cuando la entrada crece, el tiempo requerido aumenta de forma manejable por el hardware.
  *Ejemplos*: Ordenar una lista, buscar un elemento en un arreglo, encontrar el camino más corto en un grafo.
- **Problemas Intratables**: Son problemas de gran complejidad computacional para los cuales no se conocen algoritmos polinomiales que garanticen una solución óptima en el peor de los casos. Sus mejores algoritmos conocidos requieren tiempo exponencial (ej. $O(2^n)$) o factorial (ej. $O(n!)$), volviéndolos imposibles de computar para tamaños de entrada moderados.

(las-clases-p-y-np)=
#### Las Clases P y NP
Para formalizar esta clasificación, la teoría de la complejidad define conjuntos de problemas llamados clases de complejidad:

- **La Clase P**: Contiene a todos los problemas de decisión (cuya respuesta es "sí" o "no") que pueden ser **resueltos** eficientemente en tiempo polinomial.
- **La Clase NP (Tiempo Polinomial No Determinista)**: Contiene a los problemas de decisión para los cuales, si bien encontrar una solución puede ser computacionalmente difícil, es posible **verificar** la validez de una solución propuesta (un certificado) en tiempo polinomial.
  *Ejemplo (Satisfacibilidad Booleana - SAT)*: Evaluar si existe una asignación de variables lógicas que haga verdadera una fórmula booleana. Encontrar la combinación exacta puede requerir probar exponencialmente muchas opciones ($2^n$), pero verificar si una asignación dada satisface la fórmula toma tiempo lineal en el tamaño de la fórmula. Por lo tanto, SAT pertenece a la clase NP.

(la-cuestion-p-neq-np-y-los-problemas-np-completos)=
#### La Cuestión $P \neq NP$ y los Problemas NP-Completos
La relación entre estas clases plantea uno de los interrogantes abiertos más importantes de la ciencia de la computación: **¿Es $P = NP$?**
Es decir: si la solución a un problema se puede verificar eficientemente, ¿se puede también encontrar de forma eficiente?

El consenso científico generalizado es que **$P \neq NP$**, lo que significa que verificar soluciones es fundamentalmente más sencillo que crearlas.

Dentro de la clase NP, existen problemas denominados **NP-Completos**. Estos problemas representan los elementos más difíciles de NP. Tienen la propiedad de que si se encontrara un algoritmo eficiente (polinomial) para resolver cualquiera de ellos, ese algoritmo podría adaptarse inmediatamente para resolver **todos** los problemas de la clase NP en tiempo polinomial, demostrando que $P = NP$.

*Ejemplos clásicos*:
- El problema del Viajante (TSP) en su versión de decisión.
- Coloreado de grafos.

(visualizacion-de-las-clases-de-complejidad)=
#### Visualización de las Clases de Complejidad

Asumiendo que P ≠ NP, la relación entre estas clases se puede visualizar de la siguiente manera:

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

Frente a la intratabilidad de los problemas NP-Completos, en el desarrollo práctico de software se emplean algoritmos de aproximación, heurísticas o restricciones del dominio para hallar soluciones aceptables en tiempos razonables, sabiendo que una solución óptima general y rápida no es viable.

(ejercicios-de-clases-de-complejidad)=
#### Ejercicios de Clases de Complejidad








(ejemplos-detallados-de-analisis)=
### Ejemplos Detallados de Análisis


(ejemplo-1-busqueda-del-maximo)=
#### Ejemplo 1: Búsqueda del Máximo

```{code-block}c
:linenos:
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

(ejemplo-2-busqueda-de-duplicados)=
#### Ejemplo 2: Búsqueda de Duplicados

```{code-block}c
:linenos:
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

```{code-block}c
:linenos:
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

(ejemplo-3-torres-de-hanoi)=
#### Ejemplo 3: Torres de Hanoi

```{code-block}c
:linenos:
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
T(n) &= 2T(n-1) + 1 \\
T(1) &= 1
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

## Ejercicios de Autoevaluación

:::{exercise}
:label: ejer-notaciones-theta
Demostrá formalmente que $f(n) = 3n^2 + 5n + 2 \in \Theta(n^2)$ utilizando la definición formal de Big-Theta (encontrando constantes adecuadas $c_1, c_2$ y $n_0$).
:::

:::{solution} ejer-notaciones-theta
:class: dropdown
Debemos encontrar constantes $c_1, c_2, n_0 > 0$ tales que:
$$c_1 n^2 \leq 3n^2 + 5n + 2 \leq c_2 n^2 \quad \forall n \geq n_0$$

**Cota inferior** ($c_1 n^2 \leq 3n^2 + 5n + 2$):
- Tomemos $c_1 = 3$.
- Para $n \geq 1$: $3n^2 \leq 3n^2 + 5n + 2$ es verdadero ya que $5n + 2 > 0$.

**Cota superior** ($3n^2 + 5n + 2 \leq c_2 n^2$):
- Necesitamos un $c_2$ tal que la desigualdad se mantenga.
- Para $n \geq 1$, se cumple que $5n \leq 5n^2$ y $2 \leq 2n^2$.
- Entonces: $3n^2 + 5n + 2 \leq 3n^2 + 5n^2 + 2n^2 = 10n^2$.
- Tomemos $c_2 = 10$.

**Conclusión**: Con $c_1 = 3$, $c_2 = 10$ y $n_0 = 1$, se cumple:
$$3n^2 \leq 3n^2 + 5n + 2 \leq 10n^2 \quad \forall n \geq 1$$

Por lo tanto, por definición formal, $f(n) \in \Theta(n^2)$.
:::

:::{exercise}
:label: ejer-notaciones-log
Demostrá que para cualquier par de bases constantes $a, b > 1$, se cumple que $\log_a n \in \Theta(\log_b n)$.
:::

:::{solution} ejer-notaciones-log
:class: dropdown
Utilizando la fórmula de cambio de base para logaritmos, sabemos que:
$$\log_a n = \frac{\log_b n}{\log_b a} = \left(\frac{1}{\log_b a}\right) \log_b n$$

Dado que $a$ y $b$ son constantes mayores que 1, el término $k = \frac{1}{\log_b a}$ es una constante positiva fija.

Por definición de Big-Theta, una función $f(n) \in \Theta(g(n))$ si existen constantes $c_1, c_2, n_0 > 0$ tales que:
$$c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \forall n \ge n_0$$

Si elegimos $c_1 = k$, $c_2 = k$ y $n_0 = 1$, se cumple la igualdad:
$$k \cdot \log_b n \le k \cdot \log_b n \le k \cdot \log_b n \quad \forall n \ge 1$$

Lo que demuestra formalmente que $\log_a n \in \Theta(\log_b n)$. Por ende, en el análisis asintótico la base del logaritmo no afecta a la clase de complejidad y se escribe simplemente $O(\log n)$.
:::

:::{exercise}
:label: ejer-notaciones-little-o
Determiná si la relación $n \log n \in o(n^2)$ es verdadera o falsa, y justificalo aplicando la definición del límite.
:::

:::{solution} ejer-notaciones-little-o
:class: dropdown
La relación es verdadera.

Por definición, $f(n) \in o(g(n))$ si el límite del cociente de ambas funciones tiende a cero cuando $n$ tiende a infinito:
$$\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$$

Sustituyendo las funciones correspondientes:
$$\lim_{n \to \infty} \frac{n \log n}{n^2} = \lim_{n \to \infty} \frac{\log n}{n}$$

Aplicando la regla de L'Hôpital (derivando numerador y denominador respecto a $n$):
$$\lim_{n \to \infty} \frac{\frac{1}{n}}{1} = \lim_{n \to \infty} \frac{1}{n} = 0$$

Como el límite es $0$, se cumple formalmente que $n \log n \in o(n^2)$, lo que significa que $n \log n$ crece estrictamente más lento que $n^2$.
:::

:::{exercise}
:label: ejer-jerarquia-ordenar
Ordená las siguientes funciones de acuerdo con su tasa de crecimiento asintótico, de menor a mayor eficiencia (es decir, de la que crece más rápido a la que crece más lento):
$$2^n, \quad n \log n, \quad 1000, \quad n!, \quad n^3, \quad \sqrt{n}, \quad n^2$$
:::

:::{solution} ejer-jerarquia-ordenar
:class: dropdown
El orden de crecimiento asintótico de menor eficiencia (crecimiento más rápido) a mayor eficiencia (crecimiento más lento) es:
$$n! > 2^n > n^3 > n^2 > n \log n > \sqrt{n} > 1000$$

- **$n!$**: Crecimiento factorial (inviable para $n > 15$).
- **$2^n$**: Crecimiento exponencial (inviable para $n > 30$).
- **$n^3$**: Crecimiento cúbico.
- **$n^2$**: Crecimiento cuadrático.
- **$n \log n$**: Crecimiento log-lineal.
- **$\sqrt{n}$**: Crecimiento sublineal ($n^{0.5}$).
- **$1000$**: Crecimiento constante ($O(1)$).
:::

:::{exercise}
:label: ejer-jerarquia-identificar
Asociá cada uno de los siguientes fragmentos de código con su clase de complejidad correspondiente en la jerarquía ($O(1)$, $O(\log n)$, $O(n)$, $O(n^2)$):
- a) Un lazo que recorre un arreglo de tamaño $n$ para imprimir sus elementos.
- b) Un acceso directo a la posición `arr[i]` de un arreglo de tamaño $n$.
- c) Un algoritmo de búsqueda binaria sobre un arreglo ordenado de tamaño $n$.
- d) Dos lazos anidados que realizan comparaciones sobre una matriz de tamaño $n \times n$.
:::

:::{solution} ejer-jerarquia-identificar
:class: dropdown
- **a) $O(n)$ (Lineal)**: El lazo visita cada uno de los $n$ elementos exactamente una vez.
- **b) $O(1)$ (Constante)**: El acceso por índice calcula la dirección de memoria en tiempo fijo, independientemente del tamaño $n$.
- **c) $O(\log n)$ (Logarítmica)**: En cada iteración del lazo se descarta la mitad de los elementos restantes.
- **d) $O(n^2)$ (Cuadrática)**: El lazo interno se ejecuta $n$ veces por cada iteración del lazo externo, acumulando $n^2$ operaciones.
:::

:::{exercise}
:label: ejer-jerarquia-exponencial
Un algoritmo de fuerza bruta tarda 1 milisegundo en resolver un problema para una entrada de tamaño $n = 10$. Si la complejidad del algoritmo es $O(2^n)$, estimá cuánto tiempo tardará en resolver el mismo problema para una entrada de tamaño $n = 40$ (expresá el resultado en la unidad de tiempo más adecuada).
:::

:::{solution} ejer-jerarquia-exponencial
:class: dropdown
El tiempo de ejecución $T(n)$ se puede modelar como $T(n) = k \cdot 2^n$ para alguna constante $k$.

Sabemos que para $n = 10$:
$$T(10) = k \cdot 2^{10} = 1 \text{ ms} \implies k = \frac{1}{1024} \text{ ms}$$

Para $n = 40$:
$$T(40) = k \cdot 2^{40} = \frac{1}{2^{10}} \cdot 2^{40} \text{ ms} = 2^{30} \text{ ms}$$

Realizamos la conversión a unidades más comprensibles:
- $2^{30} \text{ ms} = 1.073.741.824 \text{ ms}$
- En segundos: $\frac{2^{30}}{1000} \approx 1.073.741 \text{ s}$
- En horas: $\frac{1.073.741}{3600} \approx 298.26 \text{ h}$
- En días: $\frac{298.26}{24} \approx 12.4 \text{ días}$

Por lo tanto, resolver el problema para $n = 40$ tomará aproximadamente **12,4 días**, lo cual ilustra la intratabilidad práctica de los algoritmos de complejidad exponencial.
:::

:::{exercise}
:label: ejer-tecnicas-lazos-anidados
Determiná la complejidad temporal del siguiente fragmento de código analizando la cantidad de ejecuciones del lazo interno:

```{code-block}c
:linenos:
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        printf("%d ", i * j);
    }
}
```
:::

:::{solution} ejer-tecnicas-lazos-anidados
:class: dropdown
- El lazo externo ejecuta $n$ iteraciones, con la variable $i$ tomando valores de $0$ a $n-1$.
- Para cada iteración del lazo externo, el lazo interno se ejecuta exactamente $i$ veces (con $j$ desde $0$ hasta $i-1$).
- El número total de ejecuciones del cuerpo del lazo interno se calcula mediante la sumatoria:
$$\sum_{i=0}^{n-1} i = 0 + 1 + 2 + \dots + (n-1) = \frac{(n-1)n}{2} = \frac{n^2 - n}{2}$$
- Al descartar las constantes multiplicativas y los términos de menor orden, la complejidad temporal resultante es $O(n^2)$.
:::

:::{exercise}
:label: ejer-tecnicas-lazo-multiplicativo
Determiná la complejidad temporal del siguiente fragmento de código:

```{code-block}c
:linenos:
for (int i = 1; i < n; i *= 3) {
    for (int j = 0; j < n; j++) {
        printf("%d ", i + j);
    }
}
```
:::

:::{solution} ejer-tecnicas-lazo-multiplicativo
:class: dropdown
- **Lazo externo**: La variable de control $i$ se triplica en cada iteración ($1, 3, 9, 27, \dots$). El lazo finaliza cuando $3^k \ge n$, lo que implica que realiza $k = \lceil \log_3 n \rceil$ iteraciones. Su complejidad es $O(\log n)$.
- **Lazo interno**: Para cada iteración del lazo externo, este lazo se ejecuta de forma lineal exactamente $n$ veces, realizando una operación elemental de tiempo constante $O(1)$.
- **Complejidad total**: Dado que los lazos están anidados de forma independiente, multiplicamos el costo de ambos:
$$T(n) = \log_3 n \cdot n \in O(n \log n)$$
:::

:::{exercise}
:label: ejer-tecnicas-recursividad-maestro
Determiná la complejidad temporal de la siguiente función recursiva aplicando el Teorema Maestro:

```{code-block}c
:linenos:
void misterio(int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    misterio(n / 3);
    misterio(n / 3);
}
```
:::

:::{solution} ejer-tecnicas-recursividad-maestro
:class: dropdown
Planteamos la relación de recurrencia para el tiempo de ejecución:
$$T(n) = 2T(n/3) + f(n)$$

Donde:
- $a = 2$: Se realizan dos llamadas recursivas por nivel.
- $b = 3$: El tamaño de la entrada se divide por 3 en cada llamada.
- $f(n) = O(n)$: El lazo `for` realiza $n$ iteraciones de costo constante.

Comparamos $f(n)$ con $n^{\log_b a}$:
$$n^{\log_3 2} \approx n^{0.63}$$

Dado que $f(n) = n^1$ y $1 > 0.63$, el trabajo no recursivo en la raíz del árbol domina la complejidad.

Verificamos la condición de regularidad: $a f(n/b) \le c f(n)$ para algún $c < 1$.
$$2 \cdot \frac{n}{3} = \frac{2}{3} n \le c \cdot n$$
Esta desigualdad se satisface para cualquier $c \ge 2/3$.

Por lo tanto, aplicando el **Caso 3** del Teorema Maestro, la complejidad es:
$$T(n) \in \Theta(f(n)) = \Theta(n)$$
:::

:::{exercise}
:label: ejer-espacial-fibonacci
Compará la complejidad espacial de las dos implementaciones de Fibonacci dadas en esta sección: la versión recursiva ingenua y la versión recursiva con memoización.
:::

:::{solution} ejer-espacial-fibonacci
:class: dropdown
1. **Versión recursiva ingenua**:
   - Aunque realiza un número exponencial de llamadas en total ($O(2^n)$), la pila del sistema solo almacena una rama del árbol de llamadas a la vez.
   - La profundidad máxima de la pila es $n$ marcos de activación. Por lo tanto, su complejidad espacial es $O(n)$.
2. **Versión con memoización**:
   - Requiere un arreglo auxiliar de tamaño $n + 1$ para almacenar los resultados previamente computados.
   - La profundidad máxima de la pila de llamadas también es $n$.
   - En consecuencia, consume $O(n)$ de memoria para el arreglo de memoización y $O(n)$ en la pila de ejecución, lo que totaliza una complejidad espacial de $O(n)$.

Ambas versiones requieren espacio lineal $O(n)$, pero la versión con memoización reduce la complejidad temporal de exponencial a lineal ($O(n)$) a cambio de un uso explícito de memoria.
:::

:::{exercise}
:label: ejer-espacial-iterativo-recursivo
Considerá una función iterativa que calcula el factorial de un número y una recursiva. Determiná la complejidad espacial de ambas.
:::

:::{solution} ejer-espacial-iterativo-recursivo
:class: dropdown
1. **Versión iterativa**:
   ```c
   long long factorial_iterativo(int n) {
       long long resultado = 1;
       for (int i = 2; i <= n; i++) {
           resultado *= i;
       }
       return resultado;
   }
   ```
   Esta función solo requiere almacenar las variables locales de control (`resultado`, `i`), cuyo tamaño en memoria es constante e independiente de la entrada $n$. Su complejidad espacial es **$O(1)$**.

2. **Versión recursiva**:
   ```c
   long long factorial_recursivo(int n) {
       if (n <= 1) return 1;
       return n * factorial_recursivo(n - 1);
   }
   ```
   Cada llamada recursiva introduce un nuevo marco de activación en la pila del sistema para guardar el parámetro `n` y la dirección de retorno. Como se realizan $n$ llamadas recursivas anidadas consecutivas antes de alcanzar el caso base, la pila crece linealmente. Su complejidad espacial es **$O(n)$**.
:::

:::{exercise}
:label: ejer-espacial-matriz
Un programador decide implementar un algoritmo para procesar un conjunto de $n$ registros numéricos. Para ello, crea una matriz dinámica de tamaño $n \times n$ en la que guarda las diferencias relativas de cada registro con respecto a todos los demás. Determiná la complejidad espacial de esta solución y evaluá su viabilidad si $n = 100.000$ (asumiendo que cada elemento es un entero de 4 bytes).
:::

:::{solution} ejer-espacial-matriz
:class: dropdown
- La matriz de tamaño $n \times n$ tiene un total de $n^2$ celdas. Como el espacio crece cuadráticamente respecto al tamaño de la entrada, la complejidad espacial es **$O(n^2)$**.
- Evaluamos la viabilidad para $n = 100.000$:
$$\text{Cantidad de celdas} = n^2 = (10^5)^2 = 10^{10} \text{ enteros}$$
- Multiplicando por el tamaño de un entero (4 bytes):
$$10^{10} \times 4 \text{ bytes} = 4 \times 10^{10} \text{ bytes} \approx 40 \text{ GB}$$
- **Conclusión**: Esta solución es inviable en computadoras hogareñas estándar, ya que supera ampliamente la capacidad promedio de memoria RAM, provocando un desbordamiento o fallo por falta de memoria (out of memory).
:::

:::{exercise}
:label: ejer-teoria-p-np
Explicá la diferencia fundamental entre la clase P y la clase NP, y mencioná por qué el problema de la factorización de enteros es de especial interés en esta clasificación.
:::

:::{solution} ejer-teoria-p-np
:class: dropdown
- La clase **P** agrupa a los problemas de decisión que se pueden **resolver** de forma eficiente en tiempo polinomial (por ejemplo, determinar si un elemento pertenece a un arreglo).
- La clase **NP** agrupa a los problemas de decisión para los cuales, dada una posible solución (certificado), se puede **verificar** su validez en tiempo polinomial, aunque encontrarla inicialmente pueda requerir tiempo exponencial.
- El problema de **factorización de enteros** (dado un entero $N$, hallar sus factores primos) es de gran interés porque:
  1. Pertenece a la clase NP (es trivial verificar si un conjunto de factores es correcto simplemente multiplicándolos en tiempo polinomial).
  2. No se conoce ningún algoritmo eficiente en computación clásica para resolverlo en tiempo polinomial.
  3. No se ha demostrado que sea NP-Completo, situándose en una categoría intermedia (NP-Intermedio) bajo la hipótesis de que $P \neq NP$.
:::

:::{exercise}
:label: ejer-teoria-np-completo
Definí qué es un problema **NP-Completo** y explicá las implicaciones que tendría encontrar un algoritmo de tiempo polinomial para resolver uno de ellos.
:::

:::{solution} ejer-teoria-np-completo
:class: dropdown
- Un problema es **NP-Completo** si cumple con dos condiciones:
  1. Pertenece a la clase NP (es verificable en tiempo polinomial).
  2. Es al menos tan difícil como cualquier otro problema en NP. Esto significa que cualquier problema en NP puede reducirse polinomialmente a él.
- Si se encontrara un algoritmo que resolviera un único problema NP-Completo en tiempo polinomial, todos los demás problemas de la clase NP también podrían resolverse en tiempo polinomial mediante su correspondiente reducción.
- Esto demostraría matemáticamente la igualdad **$P = NP$**, colapsando la jerarquía de complejidad. Tendría consecuencias masivas, rompiendo la seguridad de la criptografía moderna de clave pública y permitiendo optimizaciones óptimas inmediatas en logística y diseño de chips.
:::

:::{exercise}
:label: ejer-teoria-tsp-verificacion
Considerá el problema del Viajante (TSP) en su versión de decisión: dado un conjunto de ciudades, las distancias entre ellas y un límite $D$, ¿existe un recorrido que visite todas las ciudades exactamente una vez y regrese al inicio con un costo total menor o igual a $D$? Describí cómo se realiza la verificación en tiempo polinomial de una solución propuesta.
:::

:::{solution} ejer-teoria-tsp-verificacion
:class: dropdown
Para verificar un recorrido propuesto (el certificado) en tiempo polinomial, se realiza el siguiente algoritmo:
1. **Certificado**: La solución propuesta consiste en una secuencia ordenada de ciudades: $C_1, C_2, \dots, C_n$.
2. **Validación de ciudades**: Se verifica que la secuencia contenga exactamente todas las ciudades del problema sin repeticiones (a excepción del retorno a la primera ciudad). Esto toma $O(n)$ tiempo.
3. **Cálculo de distancias**: Se recorre la secuencia y se suman las distancias entre elementos consecutivos de la matriz de distancias:
   $$\text{Costo} = \sum_{i=1}^{n-1} \text{distancia}(C_i, C_{i+1}) + \text{distancia}(C_n, C_1)$$
   Dado que acceder a cada celda de la matriz toma $O(1)$ tiempo, la sumatoria toma $O(n)$ operaciones.
4. **Comparación**: Se comprueba si el $\text{Costo} \leq D$, lo cual toma $O(1)$ tiempo.

Dado que todos los pasos de verificación descritos se ejecutan en tiempo lineal $O(n)$, el problema pertenece a la clase NP.
:::

## Glosario

- **Complejidad Algorítmica**: Medida del crecimiento de recursos (tiempo/espacio) respecto al tamaño de entrada.
- **Notación Big-O**: Notación matemática que describe el límite superior del crecimiento de una función.
- **Análisis Asintótico**: Método para describir el comportamiento de algoritmos cuando la entrada tiende a infinito.

## Síntesis y Resumen

(resumen)=
### Resumen


El análisis de complejidad es fundamental para:

1. **Predecir rendimiento**: Saber si un algoritmo será viable para el tamaño de entrada esperado
2. **Comparar algoritmos**: Elegir el más eficiente para cada situación
3. **Identificar cuellos de botella**: Localizar partes del código que necesitan optimización
4. **Establecer límites teóricos**: Determinar si un algoritmo es óptimo o puede mejorarse

(puntos-clave)=
#### Puntos Clave

:::{important} Ideas Centrales

1. **Notación asintótica** ignora constantes y términos menores, enfocándose en el comportamiento para $n$ grande
2. **Big-O** da cota superior, **Omega** cota inferior, **Theta** cota ajustada
3. **Jerarquía**: $O(1) < O(\log n) < O(n) < O(n \log n) < O(n^2) < O(n^3) < O(2^n) < O(n!)$
4. **Teorema Maestro** resuelve recurrencias divide-y-conquista
5. **Límites inferiores** establecen qué es imposible mejorar (ej: $\Omega(n \log n)$ para ordenamiento)
6. **Trade-offs** entre tiempo y espacio son comunes
7. **Análisis amortizado** considera costo promedio en secuencias de operaciones
:::

(guia-practica-de-decision)=
#### Guía Práctica de Decisión

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

## Referencias y Lecturas Complementarias

(referencias-y-lecturas-complementarias)=
### Referencias y Lecturas Complementarias


(textos-fundamentales)=
#### Textos Fundamentales

- **{cite:t}`cormen_introduction_2009`**. Capítulos 3 y 4: Growth of Functions y Divide-and-Conquer.
  
- **{cite:t}`sedgewick_algorithms_2011`**. Tratamiento exhaustivo del análisis de algoritmos y estructuras básicas.

- **{cite:t}`knuth1974`**. Análisis matemático de algoritmos de control de flujo y su estructuración.

(recursos-complementarios)=
#### Recursos Complementarios

- **{cite:t}`bentley_programming_1999`**. *Programming Pearls*. Excelente para el diseño y optimización práctica de algoritmos en el mundo real.

- **{cite:t}`bryant_computer_2015`**. Capítulo 6: La jerarquía de memoria y su impacto directo en la complejidad real del hardware.

(recursos-en-linea)=
#### Recursos en Línea

- **MIT OpenCourseWare**: 6.006 Introduction to Algorithms
- **Khan Academy**: Algoritmos y Análisis Asintótico
- **Big-O Cheat Sheet**: https://www.bigocheatsheet.com/
