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

- **Definición Intuitiva**: Una función $f(n)$ es $O(g(n))$ si su tasa de
  crecimiento es **igual o más lenta** que la de $g(n)$ para entradas
  suficientemente grandes.
- **Definición Formal**: $f(n) = O(g(n))$ si existen constantes positivas $c$ y
  $n_0$ tales que $0 \le f(n) \le c \cdot g(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **peor caso** de ejecución de un algoritmo.

### 2. Notación Omega (Ω) - Cota Inferior (Mejor Caso)

La notación **Omega** describe una **cota inferior asintótica**. Nos garantiza
que el rendimiento del algoritmo nunca será mejor que esta cota.

- **Definición Intuitiva**: Una función $f(n)$ es $\Omega(g(n))$ si su tasa de
  crecimiento es **igual o más rápida** que la de $g(n)$.
- **Definición Formal**: $f(n) = \Omega(g(n))$ si existen constantes positivas
  $c$ y $n_0$ tales que $0 \le c \cdot g(n) \le f(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **mejor caso** de ejecución.

### 3. Notación Theta (Θ) - Cota Ajustada (Caso Exacto)

La notación **Theta** proporciona la descripción más precisa del comportamiento
de un algoritmo, acotándolo tanto por arriba como por abajo.

- **Definición Intuitiva**: Una función $f(n)$ es $\Theta(g(n))$ si su tasa de
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
- **Base del logaritmo irrelevante asintóticamente**: la base del logaritmo no afecta a la clase de complejidad porque cambiar de base equivale a multiplicar por una constante.
  Si aplicamos la fórmula de cambio de base:
  $$
  \log_a n = \frac{\log_b n}{\log_b a} = \left(\frac{1}{\log_b a}\right) \log_b n
  $$
  Dado que $\frac{1}{\log_b a}$ es una constante para bases fijas $a$ y $b$, por definición asintótica se cumple que $\log_a n \in \Theta(\log_b n)$ (por ejemplo, $\log_2 n \in \Theta(\log_{10} n)$).

**Ejemplos**: búsqueda binaria, operaciones en árboles balanceados

**Código ejemplo**:
```c
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
La búsqueda binaria asume como precondición fundamental que el arreglo de entrada se encuentra estrictamente ordenado (regla {ref}`0x0035h`). Si esta precondición no se cumple, el algoritmo no es correcto y su comportamiento es impredecible.
:::

En cada iteración del lazo, el espacio de búsqueda se reduce a la mitad. Si inicialmente hay $n$ elementos, después de $k$ lazos quedan $\frac{n}{2^k}$. El algoritmo termina cuando $\frac{n}{2^k} = 1$, es decir, $k = \log_2 n$.

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

**Análisis**: La relación de recurrencia para el tiempo de ejecución es $T(n) = T(n-1) + T(n-2) + O(1)$. Para resolver la parte homogénea de esta ecuación de diferencias, $T(n) - T(n-1) - T(n-2) = 0$, proponemos una solución de la forma $T(n) = r^n$. Al sustituir, obtenemos la **ecuación característica**:
$$
r^2 - r - 1 = 0
$$
cuyas raíces son $r_1 = \frac{1+\sqrt{5}}{2} = \phi \approx 1.618$ (la razón áurea) y $r_2 = \frac{1-\sqrt{5}}{2} \approx -0.618$. La solución general de la recurrencia es una combinación lineal de ambas potencias, dominada asintóticamente por la raíz de mayor magnitud, por lo que $T(n) \in \Theta(\phi^n)$.

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

#### Método del Árbol de Recursión

Antes de enunciar el Teorema Maestro, es fundamental visualizar cómo se distribuye el trabajo en un algoritmo recursivo de tipo divide y vencerás. El **árbol de recursión** es una herramienta gráfica donde:
- Cada nodo representa una llamada recursiva.
- El costo etiquetado en cada nodo es el trabajo no recursivo realizado en esa llamada específica.
- La suma del trabajo de todos los nodos en todos los niveles del árbol determina el costo total del algoritmo.

```{figure} 14/master_theorem.svg
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

#### Teorema Maestro

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
   - **Solución**: $T(n) \in \Theta(n^{\log_2 3}) \approx \Theta(n^{1.585})$1:            n/2   n/2          → costo: n


### Análisis Amortizado

El **análisis amortizado** considera el costo promedio de una secuencia de operaciones, permitiendo que algunas operaciones sean costosas si la mayoría son baratas.

#### Método del Agregado

**Ejemplo**: Arreglo dinámico redimensionable en C.

Supongamos que implementamos un arreglo dinámico en C mediante una estructura que almacena un puntero, el tamaño actual y la capacidad máxima de almacenamiento. Cuando el arreglo alcanza su capacidad límite, duplicamos su tamaño utilizando `realloc`:

```c
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

## Conceptos de Complejidad: Intratabilidad y las Clases P y NP

En el análisis de algoritmos, no solo nos interesa determinar la complejidad asintótica exacta, sino también clasificar los problemas según si son resolubles de forma eficiente en la práctica. Esta distinción introduce la noción de **intratabilidad**.

### Problemas Tratables vs. Intratables
- **Problemas Tratables**: Son aquellos para los cuales existe un algoritmo que los resuelve en tiempo polinomial en el peor de los casos (es decir, $O(n^k)$ para alguna constante $k$). Cuando la entrada crece, el tiempo requerido aumenta de forma manejable por el hardware.
  *Ejemplos*: Ordenar una lista, buscar un elemento en un arreglo, encontrar el camino más corto en un grafo.
- **Problemas Intratables**: Son problemas de gran complejidad computacional para los cuales no se conocen algoritmos polinomiales que garanticen una solución óptima en el peor de los casos. Sus mejores algoritmos conocidos requieren tiempo exponencial (ej. $O(2^n)$) o factorial (ej. $O(n!)$), volviéndolos imposibles de computar para tamaños de entrada moderados.

### Las Clases P y NP
Para formalizar esta clasificación, la teoría de la complejidad define conjuntos de problemas llamados clases de complejidad:

- **La Clase P**: Contiene a todos los problemas de decisión (cuya respuesta es "sí" o "no") que pueden ser **resueltos** eficientemente en tiempo polinomial.
- **La Clase NP (Tiempo Polinomial No Determinista)**: Contiene a los problemas de decisión para los cuales, si bien encontrar una solución puede ser computacionalmente difícil, es posible **verificar** la validez de una solución propuesta (un certificado) en tiempo polinomial.
  *Ejemplo (Satisfacibilidad Booleana - SAT)*: Evaluar si existe una asignación de variables lógicas que haga verdadera una fórmula booleana. Encontrar la combinación exacta puede requerir probar exponencialmente muchas opciones ($2^n$), pero verificar si una asignación dada satisface la fórmula toma tiempo lineal en el tamaño de la fórmula. Por lo tanto, SAT pertenece a la clase NP.

### La Cuestión $P \neq NP$ y los Problemas NP-Completos
La relación entre estas clases plantea uno de los interrogantes abiertos más importantes de la ciencia de la computación: **¿Es $P = NP$?**
Es decir: si la solución a un problema se puede verificar eficientemente, ¿se puede también encontrar de forma eficiente?

El consenso científico generalizado es que **$P \neq NP$**, lo que significa que verificar soluciones es fundamentalmente más sencillo que crearlas.

Dentro de la clase NP, existen problemas denominados **NP-Completos**. Estos problemas representan los elementos más difíciles de NP. Tienen la propiedad de que si se encontrara un algoritmo eficiente (polinomial) para resolver cualquiera de ellos, ese algoritmo podría adaptarse inmediatamente para resolver **todos** los problemas de la clase NP en tiempo polinomial, demostrando que $P = NP$.

*Ejemplos clásicos*:
- El problema del Viajante (TSP) en su versión de decisión.
- Coloreado de grafos.

### Visualización de las Clases de Complejidad

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
