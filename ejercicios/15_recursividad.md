---
title: "Ejercicios: Recursividad y Divide y Vencerás"
short_title: "15. Recursividad"
---

Ejercicios para dominar la recursividad y el paradigma de divide y vencerás, desde conceptos fundamentales hasta algoritmos avanzados de ordenamiento y búsqueda. Estos ejercicios refuerzan el pensamiento recursivo y el análisis de complejidad.

## 1: Fundamentos de Recursividad

### 1.1: Factorial

Implementar la función factorial de forma recursiva siguiendo la definición matemática.

```c
long int factorial(int n);
```

**Definición recursiva:**

$$
n! = \begin{cases} 
1 & \text{si } n = 0 \\
n \times (n-1)! & \text{si } n > 0
\end{cases}
$$

**Casos de prueba:**
- `factorial(0)` → 1
- `factorial(5)` → 120
- `factorial(10)` → 3628800

### 1.2: Suma de Enteros

Implementar suma de dos enteros positivos usando solo recursividad (sin operador `+` en el paso recursivo).

```c
int suma_recursiva(int a, int b);
```

**Estrategia:** Decrementar `b` e incrementar `a` hasta que `b` sea 0.

$$
suma(a, b) = \begin{cases}
a & \text{si } b = 0 \\
suma(a + 1, b - 1) & \text{si } b > 0
\end{cases}
$$

### 1.3: Producto por Sumas Recursivas

Implementar multiplicación usando solo sumas recursivas.

```c
int producto_recursivo(int a, int b);
```

$$
a \times b = \begin{cases}
0 & \text{si } b = 0 \\
a + producto(a, b - 1) & \text{si } b > 0
\end{cases}
$$

**Complejidad:** $O(b)$ en tiempo.

### 1.4: Potencia

Implementar $base^{exponente}$ de forma recursiva.

```c
long int potencia(int base, int exponente);
```

**Versión básica:** $O(n)$ en tiempo.

$$
base^{exp} = \begin{cases}
1 & \text{si } exp = 0 \\
base \times potencia(base, exp - 1) & \text{si } exp > 0
\end{cases}
$$

**Desafío:** Implementar versión optimizada usando exponenciación rápida (divide y vencerás) con complejidad $O(\log n)$.

$$
base^{exp} = \begin{cases}
1 & \text{si } exp = 0 \\
\left(base^{exp/2}\right)^2 & \text{si } exp \text{ es par} \\
base \times \left(base^{(exp-1)/2}\right)^2 & \text{si } exp \text{ es impar}
\end{cases}
$$

## 2: Series Numéricas Recursivas

### 2.1: Fibonacci Básico

Implementar la secuencia de Fibonacci recursivamente.

```c
long int fibonacci(int n);
```

$$
fib(n) = \begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
fib(n-1) + fib(n-2) & \text{si } n > 1
\end{cases}
$$

**Advertencia:** Esta implementación tiene complejidad exponencial $O(2^n)$ debido a recálculos redundantes.

**Secuencia:** 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

### 2.2: Fibonacci con Memoización

Optimizar Fibonacci usando un arreglo para almacenar resultados ya calculados (programación dinámica).

```c
long int fibonacci_memo(int n, long int memo[]);
```

**Algoritmo:**
1. Si `memo[n]` ya está calculado, retornarlo
2. Si no, calcular recursivamente y guardar en `memo[n]`

**Complejidad mejorada:** $O(n)$ en tiempo, $O(n)$ en espacio.

### 2.3: Tribonacci

Generalizar Fibonacci: cada término es la suma de los tres anteriores.

```c
long int tribonacci(int n);
```

$$
trib(n) = \begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
1 & \text{si } n = 2 \\
trib(n-1) + trib(n-2) + trib(n-3) & \text{si } n > 2
\end{cases}
$$

**Secuencia:** 0, 1, 1, 2, 4, 7, 13, 24, 44, 81...

### 2.4: Suma de Dígitos

Calcular la suma de los dígitos de un número usando recursividad.

```c
int suma_digitos(int n);
```

**Estrategia:**
- Caso base: `n < 10` retorna `n`
- Paso recursivo: `(n % 10) + suma_digitos(n / 10)`

**Ejemplos:**
- `suma_digitos(123)` → 6
- `suma_digitos(9875)` → 29

## 3: Operaciones sobre Arreglos

### 3.1: Suma de Elementos

Implementar suma de elementos de un arreglo recursivamente.

```c
int suma_arreglo(int arr[], int n);
```

**Estrategia:**
- Caso base: `n == 0` retorna 0
- Paso recursivo: `arr[0] + suma_arreglo(arr + 1, n - 1)`

Alternativamente, usar índices:

```c
int suma_arreglo_idx(int arr[], int inicio, int fin);
```

### 3.2: Encontrar Máximo

Encontrar el elemento máximo de un arreglo recursivamente.

```c
int maximo_arreglo(int arr[], int n);
```

**Algoritmo:**
- Caso base: `n == 1` retorna `arr[0]`
- Paso recursivo: comparar `arr[0]` con `maximo_arreglo(arr + 1, n - 1)`

### 3.3: Búsqueda Lineal Recursiva

Buscar un elemento en un arreglo no ordenado.

```c
int buscar_recursivo(int arr[], int n, int objetivo);
```

**Retorno:** índice del elemento o -1 si no se encuentra.

**Algoritmo:**
- Caso base: `n == 0` retorna -1 (no encontrado)
- Si `arr[0] == objetivo`, retorna 0
- Sino, buscar en el resto: resultado de `buscar_recursivo(arr + 1, n - 1, objetivo)` más 1

### 3.4: Invertir Arreglo

Invertir un arreglo in-place usando recursividad.

```c
void invertir_arreglo(int arr[], int inicio, int fin);
```

**Algoritmo:**
- Caso base: `inicio >= fin` (se cruzaron los índices)
- Intercambiar `arr[inicio]` con `arr[fin]`
- Llamar recursivamente con `inicio + 1` y `fin - 1`

## 4: Operaciones sobre Cadenas

### 4.1: Longitud de Cadena

Calcular la longitud de una cadena sin usar `strlen`.

```c
size_t longitud_recursiva(const char* str);
```

**Algoritmo:**
- Caso base: `*str == '\0'` retorna 0
- Paso recursivo: `1 + longitud_recursiva(str + 1)`

### 4.2: Verificar Palíndromo

Determinar si una cadena es un palíndromo.

```c
bool es_palindromo(const char* str, int inicio, int fin);
```

**Algoritmo:**
- Caso base: `inicio >= fin` retorna `true` (cadena vacía o un carácter)
- Si `str[inicio] != str[fin]`, retorna `false`
- Sino, verificar recursivamente `es_palindromo(str, inicio + 1, fin - 1)`

**Ejemplos:**
- `"neuquen"` → `true`
- `"reconocer"` → `true`
- `"hola"` → `false`

### 4.3: Contar Vocales

Contar el número de vocales en una cadena.

```c
int contar_vocales(const char* str);
```

**Algoritmo:**
- Caso base: `*str == '\0'` retorna 0
- Si `*str` es vocal, retorna `1 + contar_vocales(str + 1)`
- Sino, retorna `contar_vocales(str + 1)`

### 4.4: Invertir Cadena

Invertir una cadena in-place recursivamente.

```c
void invertir_cadena(char* str, int inicio, int fin);
```

Similar al algoritmo de invertir arreglo.

## 5: Búsqueda Binaria

Implementar búsqueda binaria recursiva en un arreglo ordenado.

```c
int busqueda_binaria(int arr[], int inicio, int fin, int objetivo);
```

**Algoritmo:**
1. Caso base: `inicio > fin` retorna -1 (no encontrado)
2. Calcular punto medio: `medio = inicio + (fin - inicio) / 2`
3. Si `arr[medio] == objetivo`, retornar `medio`
4. Si `arr[medio] > objetivo`, buscar en mitad izquierda: `busqueda_binaria(arr, inicio, medio - 1, objetivo)`
5. Sino, buscar en mitad derecha: `busqueda_binaria(arr, medio + 1, fin, objetivo)`

**Complejidad:** $O(\log n)$

### 5.1: Encontrar Primera Ocurrencia

Modificar búsqueda binaria para encontrar la primera ocurrencia de un elemento (puede haber duplicados).

```c
int primera_ocurrencia(int arr[], int inicio, int fin, int objetivo);
```

**Estrategia:** Cuando se encuentra el elemento, continuar buscando en la mitad izquierda para ver si hay ocurrencias anteriores.

### 5.2: Encontrar Última Ocurrencia

Similar al anterior, pero continuar buscando en la mitad derecha.

```c
int ultima_ocurrencia(int arr[], int inicio, int fin, int objetivo);
```

## 6: Ordenamiento por Fusión (Merge Sort)

Implementar Merge Sort, el algoritmo clásico de divide y vencerás.

### 6.1: Función Merge

Implementar la función que fusiona dos sub-arreglos ordenados.

```c
void merge(int arr[], int inicio, int medio, int fin);
```

**Algoritmo:**
1. Crear arreglos temporales para las dos mitades
2. Copiar datos a los arreglos temporales
3. Fusionar comparando elementos y copiando el menor
4. Copiar elementos restantes si los hay

### 6.2: Función Merge Sort

Implementar la función recursiva principal.

```c
void merge_sort(int arr[], int inicio, int fin);
```

**Algoritmo:**
1. Caso base: `inicio >= fin` (un solo elemento o vacío)
2. Calcular punto medio: `medio = inicio + (fin - inicio) / 2`
3. Ordenar mitad izquierda: `merge_sort(arr, inicio, medio)`
4. Ordenar mitad derecha: `merge_sort(arr, medio + 1, fin)`
5. Fusionar las mitades: `merge(arr, inicio, medio, fin)`

**Complejidad:** $O(n \log n)$ en tiempo, $O(n)$ en espacio.

**Relación de recurrencia:** $T(n) = 2T(n/2) + O(n)$

### 6.3: Contar Inversiones

Modificar Merge Sort para contar el número de inversiones en un arreglo (pares de índices `i < j` donde `arr[i] > arr[j]`).

```c
long int contar_inversiones(int arr[], int inicio, int fin);
```

**Aplicación:** Medir cuán desordenado está un arreglo.

## 7: Quick Sort

Implementar Quick Sort, otro algoritmo de divide y vencerás.

### 7.1: Función Partition

Implementar la función que particiona el arreglo alrededor de un pivote.

```c
int partition(int arr[], int bajo, int alto);
```

**Algoritmo (Lomuto):**
1. Elegir `arr[alto]` como pivote
2. Mantener índice `i` de elementos menores al pivote
3. Recorrer de `bajo` a `alto - 1`:
   - Si `arr[j] < pivote`, intercambiar `arr[i]` con `arr[j]` e incrementar `i`
4. Colocar pivote en su posición final: intercambiar `arr[i]` con `arr[alto]`
5. Retornar `i` (posición final del pivote)

### 7.2: Función Quick Sort

Implementar la función recursiva principal.

```c
void quick_sort(int arr[], int bajo, int alto);
```

**Algoritmo:**
1. Caso base: `bajo >= alto`
2. Particionar: `pivote = partition(arr, bajo, alto)`
3. Ordenar recursivamente la parte izquierda: `quick_sort(arr, bajo, pivote - 1)`
4. Ordenar recursivamente la parte derecha: `quick_sort(arr, pivote + 1, alto)`

**Complejidad:**
- Mejor/promedio: $O(n \log n)$
- Peor caso: $O(n^2)$ (arreglo ya ordenado con pivote malo)

### 7.3: Quick Sort con Pivote Aleatorio

Mejorar Quick Sort eligiendo el pivote aleatoriamente para evitar el peor caso.

```c
int partition_aleatorio(int arr[], int bajo, int alto);
```

**Estrategia:** Elegir índice aleatorio entre `bajo` y `alto`, intercambiarlo con `arr[alto]`, y luego aplicar partition normal.

## 8: Torres de Hanoi

Resolver el problema clásico de las Torres de Hanoi.

```c
void hanoi(int n, char origen, char destino, char auxiliar);
```

**Reglas:**
1. Mover un solo disco a la vez
2. Un disco más grande nunca puede estar sobre uno más pequeño
3. Solo se puede mover el disco superior de cada torre

**Algoritmo recursivo:**
1. Caso base: `n == 1`, mover disco de origen a destino
2. Mover `n-1` discos de origen a auxiliar (usando destino como auxiliar)
3. Mover disco `n` de origen a destino
4. Mover `n-1` discos de auxiliar a destino (usando origen como auxiliar)

**Complejidad:** $O(2^n)$ movimientos.

**Número de movimientos:** $2^n - 1$

### 8.1: Contar Movimientos

Modificar la función para que retorne el número de movimientos realizados.

```c
int hanoi_contar(int n, char origen, char destino, char auxiliar);
```

## 9: Generación de Combinaciones

### 9.1: Subconjuntos (Power Set)

Generar todos los subconjuntos de un conjunto usando recursividad.

```c
void generar_subconjuntos(int conjunto[], int n, int subconjunto[], int tam_sub, int indice);
```

**Algoritmo:**
- En cada paso, decidir si incluir o no el elemento actual
- Caso base: procesar todos los elementos

**Número de subconjuntos:** $2^n$

**Ejemplo con `{1, 2, 3}`:**
- `{}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}`

### 9.2: Permutaciones

Generar todas las permutaciones de un arreglo.

```c
void generar_permutaciones(int arr[], int inicio, int fin);
```

**Algoritmo (backtracking):**
1. Caso base: `inicio == fin`, imprimir permutación
2. Para cada `i` de `inicio` a `fin`:
   - Intercambiar `arr[inicio]` con `arr[i]`
   - Generar permutaciones del resto: `generar_permutaciones(arr, inicio + 1, fin)`
   - Deshacer intercambio (backtrack)

**Número de permutaciones:** $n!$

### 9.3: Combinaciones de Tamaño k

Generar todas las combinaciones de tamaño `k` de un conjunto de `n` elementos.

```c
void combinaciones(int arr[], int n, int k, int combinacion[], int indice, int inicio);
```

**Número de combinaciones:** $\binom{n}{k} = \frac{n!}{k!(n-k)!}$

## 10: Backtracking - N-Reinas

Resolver el problema de las N-Reinas: colocar N reinas en un tablero de NxN sin que se ataquen.

```c
bool resolver_n_reinas(int tablero[][MAX], int n, int col);
bool es_seguro(int tablero[][MAX], int n, int fila, int col);
```

**Algoritmo (backtracking):**
1. Caso base: `col >= n`, se colocaron todas las reinas
2. Para cada fila de 0 a n-1:
   - Si es seguro colocar reina en `(fila, col)`:
     - Colocar reina
     - Recursivamente intentar colocar en `col + 1`
     - Si tiene éxito, retornar `true`
     - Sino, quitar reina (backtrack)
3. Si ninguna fila funciona, retornar `false`

**Función auxiliar `es_seguro`:** Verificar que no haya reinas en la misma fila, columna o diagonales.

### 10.1: Contar Soluciones

Modificar para contar todas las soluciones posibles en lugar de encontrar solo una.

```c
int contar_soluciones_n_reinas(int tablero[][MAX], int n, int col);
```

## 11: Máximo Común Divisor (MCD)

Implementar el algoritmo de Euclides recursivamente.

```c
int mcd(int a, int b);
```

**Algoritmo de Euclides:**

$$
mcd(a, b) = \begin{cases}
a & \text{si } b = 0 \\
mcd(b, a \mod b) & \text{si } b \neq 0
\end{cases}
$$

**Ejemplos:**
- `mcd(48, 18)` → 6
- `mcd(100, 35)` → 5

**Complejidad:** $O(\log \min(a, b))$

### 11.1: Mínimo Común Múltiplo

Usar el MCD para calcular el MCM.

```c
int mcm(int a, int b);
```

**Relación:** $mcm(a, b) = \frac{a \times b}{mcd(a, b)}$

## 12: Recursividad en Estructuras de Datos

### 12.1: Búsqueda en Lista Enlazada

Buscar un elemento en una lista enlazada recursivamente.

```c
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo_t;

bool buscar_lista(nodo_t* nodo, int objetivo);
```

**Algoritmo:**
- Caso base: `nodo == NULL` retorna `false`
- Si `nodo->dato == objetivo`, retorna `true`
- Sino, buscar en el resto: `buscar_lista(nodo->siguiente, objetivo)`

### 12.2: Longitud de Lista Enlazada

Calcular la longitud de una lista enlazada recursivamente.

```c
size_t longitud_lista(nodo_t* nodo);
```

### 12.3: Imprimir Lista al Revés

Imprimir los elementos de una lista enlazada en orden inverso sin modificar la lista.

```c
void imprimir_reversa(nodo_t* nodo);
```

**Estrategia:** Primero hacer la llamada recursiva, luego imprimir el dato.

### 12.4: Suma de Árbol Binario

Calcular la suma de todos los nodos de un árbol binario.

```c
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol* izq;
    struct nodo_arbol* der;
} nodo_arbol_t;

int suma_arbol(nodo_arbol_t* raiz);
```

**Algoritmo:**
- Caso base: `raiz == NULL` retorna 0
- Retornar `raiz->dato + suma_arbol(raiz->izq) + suma_arbol(raiz->der)`

## 13: Altura de Árbol Binario

Calcular la altura (máxima profundidad) de un árbol binario.

```c
int altura_arbol(nodo_arbol_t* raiz);
```

**Algoritmo:**
- Caso base: `raiz == NULL` retorna 0
- Retornar `1 + max(altura_arbol(raiz->izq), altura_arbol(raiz->der))`

### 13.1: Árbol Balanceado

Determinar si un árbol binario está balanceado (la diferencia de altura entre subárboles izquierdo y derecho no excede 1 para cada nodo).

```c
bool es_balanceado(nodo_arbol_t* raiz);
```

### 13.2: Recorridos de Árbol

Implementar los tres recorridos estándar recursivamente:

```c
void preorden(nodo_arbol_t* raiz);   // Raíz, Izq, Der
void inorden(nodo_arbol_t* raiz);    // Izq, Raíz, Der
void postorden(nodo_arbol_t* raiz);  // Izq, Der, Raíz
```

**Aplicación de inorden:** En un árbol de búsqueda binaria, imprime los elementos ordenados.

## 14: Operaciones Avanzadas sobre Cadenas

### 14.1: Eliminar Espacios

Eliminar todos los espacios de una cadena recursivamente.

```c
void eliminar_espacios(char* str, int indice);
```

**Estrategia:** Si encuentra espacio, desplazar todos los caracteres siguientes una posición a la izquierda.

### 14.2: Conversión a Mayúsculas/Minúsculas

Convertir una cadena a mayúsculas o minúsculas recursivamente.

```c
void a_mayusculas_rec(char* str);
void a_minusculas_rec(char* str);
```

### 14.3: Subcadenas Palindrómicas

Encontrar todas las subcadenas que son palíndromos.

```c
void encontrar_palindromos(const char* str, int inicio, int fin);
```

## 15: Problema del Cambio de Monedas

Calcular el número de formas de dar cambio para una cantidad usando un conjunto de denominaciones.

```c
int contar_formas_cambio(int cantidad, int denominaciones[], int n);
```

**Algoritmo:**
- Caso base: 
  - Si `cantidad == 0`, retornar 1 (una forma: no usar monedas)
  - Si `cantidad < 0` o `n == 0`, retornar 0 (sin solución)
- Recursión: sumar dos casos:
  - Usar al menos una moneda de `denominaciones[n-1]`: `contar_formas_cambio(cantidad - denominaciones[n-1], denominaciones, n)`
  - No usar esa denominación: `contar_formas_cambio(cantidad, denominaciones, n-1)`

**Ejemplo:** Para $10$ con monedas `{1, 2, 5}`:
- Posibles formas: `{1,1,1,1,1,1,1,1,1,1}`, `{2,2,2,2,2}`, `{5,5}`, `{5,2,2,1}`, etc.

### 15.1: Cambio con Mínimas Monedas

Variante: encontrar el número mínimo de monedas para dar el cambio.

```c
int min_monedas(int cantidad, int denominaciones[], int n);
```

## 16: Laberinto (Pathfinding)

Encontrar un camino en un laberinto usando backtracking.

```c
bool resolver_laberinto(int laberinto[][MAX], int x, int y, int solucion[][MAX], int n);
```

**Representación:**
- `0`: camino libre
- `1`: pared
- Destino: `(n-1, n-1)` (esquina inferior derecha)

**Algoritmo (backtracking):**
1. Caso base: si `(x, y)` es destino, retornar `true`
2. Si `(x, y)` es válido (dentro de límites, no pared, no visitado):
   - Marcar como parte de la solución
   - Intentar mover en las 4 direcciones: derecha, abajo, izquierda, arriba
   - Si alguno tiene éxito, retornar `true`
   - Sino, desmarcar (backtrack) y retornar `false`

### 16.1: Contar Todos los Caminos

Modificar para contar todos los caminos posibles del origen al destino.

```c
int contar_caminos(int laberinto[][MAX], int x, int y, bool visitado[][MAX], int n);
```

## 17: Problema de la Mochila (0/1 Knapsack)

Dado un conjunto de objetos con peso y valor, determinar el máximo valor que se puede llevar en una mochila de capacidad limitada.

```c
int mochila_01(int pesos[], int valores[], int n, int capacidad);
```

**Algoritmo recursivo:**
- Caso base: 
  - Si `n == 0` o `capacidad == 0`, retornar 0
- Si `pesos[n-1] > capacidad`, no puede incluirse: retornar `mochila_01(pesos, valores, n-1, capacidad)`
- Sino, tomar el máximo de:
  - Incluir objeto: `valores[n-1] + mochila_01(pesos, valores, n-1, capacidad - pesos[n-1])`
  - No incluirlo: `mochila_01(pesos, valores, n-1, capacidad)`

**Complejidad sin optimización:** $O(2^n)$

**Optimización:** Usar memoización para reducir a $O(n \times capacidad)$.

## 18: Parentización Óptima de Matrices

Determinar el orden óptimo para multiplicar una cadena de matrices minimizando operaciones.

```c
int parentizacion_matrices(int dimensiones[], int i, int j);
```

**Problema:** Dadas matrices $A_1, A_2, \ldots, A_n$ con dimensiones $(d_0 \times d_1), (d_1 \times d_2), \ldots, (d_{n-1} \times d_n)$, encontrar el orden de multiplicación que minimice operaciones escalares.

**Relación de recurrencia:**

$$
m[i,j] = \begin{cases}
0 & \text{si } i = j \\
\min_{i \le k < j} \{m[i,k] + m[k+1,j] + d_{i-1} \cdot d_k \cdot d_j\} & \text{si } i < j
\end{cases}
$$

**Aplicación:** Optimización de consultas en bases de datos.

## 19: Subset Sum Problem

Determinar si existe un subconjunto de un conjunto de enteros que sume exactamente un valor objetivo.

```c
bool existe_suma(int conjunto[], int n, int suma_objetivo);
```

**Algoritmo:**
- Caso base:
  - Si `suma_objetivo == 0`, retornar `true` (subconjunto vacío)
  - Si `n == 0` y `suma_objetivo != 0`, retornar `false`
- Recursión: verificar dos casos:
  - Incluir `conjunto[n-1]`: `existe_suma(conjunto, n-1, suma_objetivo - conjunto[n-1])`
  - No incluirlo: `existe_suma(conjunto, n-1, suma_objetivo)`
- Retornar `true` si alguno de los dos casos es verdadero

**Ejemplo:** `{3, 34, 4, 12, 5, 2}` y objetivo `9` → `true` (usando `{4, 5}`)

### 19.1: Imprimir Subconjunto Solución

Modificar para imprimir el subconjunto que suma el objetivo.

```c
bool imprimir_subconjunto_suma(int conjunto[], int n, int suma_objetivo, int solucion[], int tam_sol);
```

## 20: Análisis de Complejidad Recursiva

### 20.1: Ecuaciones de Recurrencia

Analizar la complejidad temporal de las siguientes funciones recursivas usando el Teorema Maestro o expansión:

**a) Factorial:**
- $T(n) = T(n-1) + O(1)$
- **Solución:** $O(n)$

**b) Fibonacci naive:**
- $T(n) = T(n-1) + T(n-2) + O(1)$
- **Solución:** $O(2^n)$ (exponencial)

**c) Búsqueda Binaria:**
- $T(n) = T(n/2) + O(1)$
- **Solución:** $O(\log n)$

**d) Merge Sort:**
- $T(n) = 2T(n/2) + O(n)$
- **Solución:** $O(n \log n)$

**e) Torres de Hanoi:**
- $T(n) = 2T(n-1) + O(1)$
- **Solución:** $O(2^n)$

### 20.2: Conversión Iterativa

Para cada algoritmo recursivo, analizar:
1. ¿Es posible convertirlo a iterativo?
2. ¿Cuál sería más eficiente en espacio?

**Ejemplos:**
- **Factorial:** Fácilmente convertible a lazo, ahorra espacio de pila
- **Merge Sort:** Posible pero más complejo, recursivo es más elegante
- **Torres de Hanoi:** Difícil de convertir, recursión es natural

### 20.3: Recursión de Cola (Tail Recursion)

Identificar cuáles funciones tienen recursión de cola (la llamada recursiva es la última operación) y pueden ser optimizadas por el compilador.

**Recursión de cola:**
```c
int factorial_tail(int n, int acumulador) {
    if (n == 0) return acumulador;
    return factorial_tail(n - 1, n * acumulador);  // Última operación
}
```

**No es recursión de cola:**
```c
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);  // Multiplicación después de la recursión
}
```

**Ventaja:** El compilador puede optimizar recursión de cola a un lazo, eliminando el overhead de la pila.
