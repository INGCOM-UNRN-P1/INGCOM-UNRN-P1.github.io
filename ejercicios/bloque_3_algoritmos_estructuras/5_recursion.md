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

### Cuestiones de Estilo Aplicables
- **Casos base explícitos:** Asegurate de definir de forma inequívoca el caso de
  corte en la primera instrucción de la función recursiva.
- **Punteros y arreglos:** Al pasar arreglos a funciones recursivas, utilizá la
  aritmética de punteros para desplazar la dirección base del sub-arreglo en
  cada llamada (ver reglas de estilo en {ref}`0x2009h`).

---

## Matemática Recursiva
(ejercicio_25_1)=
### Ejercicio 25.1 - Factorial ⭐⭐☆☆☆

El factorial de un entero no negativo $n$, denotado como $n!$, es el producto de
todos los enteros positivos menores o iguales a $n$.

$$ n! = n \times (n-1) \times (n-2) \times \dots \times 1 $$

La definición recursiva es:

$$ 
factorial(n) = 
\begin{cases}
1 & \text{si } n = 0 \\
n \times factorial(n-1) & \text{si } n > 0
\end{cases}
$$ 
(ejercicio_25_2)=
### Ejercicio 25.2 - Suma ⭐⭐☆☆☆

Definir la suma de $a+b$ de forma recursiva. La idea es decrementar uno de los
operandos hasta llegar a un caso base.

$$ 
suma(a, b) = 
\begin{cases}
a & \text{si } b = 0 \\
suma(a+1, b-1) & \text{si } b > 0
\end{cases}
$$ 
(ejercicio_25_3)=
### Ejercicio 25.3 - Producto ⭐⭐☆☆☆

Definir el producto $a \times b$ usando sumas y recursividad.

$$ 
producto(a, b) = 
\begin{cases}
0 & \text{si } b = 0 \\
a + producto(a, b-1) & \text{si } b > 0
\end{cases}
$$ 
(ejercicio_25_4)=
### Ejercicio 25.4 - Potencia ⭐⭐☆☆☆

Definir la potencia $base^{exp}$ usando productos y recursividad.

$$ 
potencia(base, exp) = 
\begin{cases}
1 & \text{si } exp = 0 \\
base \times potencia(base, exp-1) & \text{si } exp > 0
\end{cases}
$$ 

---

## Series Recursivas
(ejercicio_25_5)=
### Ejercicio 25.5 - Fibonacci ⭐⭐☆☆☆

Implementar una función que calcule el n-ésimo término de la serie de Fibonacci,
definida por la relación de recurrencia:

$$ 
fib(n) = 
\begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
fib(n-1) + fib(n-2) & \text{si } n > 1
\end{cases}
$$ 

---

## Arreglos Recursivos
(ejercicio_25_6)=
### Ejercicio 25.6 - Mostrar arreglo ⭐⭐⭐☆☆

Imprimir el primer elemento y luego llamar a la función con el resto del
arreglo.
(ejercicio_25_7)=
### Ejercicio 25.7 - Mostrar arreglo invertido ⭐⭐⭐☆☆

Llamar a la función con el resto del arreglo y luego imprimir el primer
elemento.
(ejercicio_25_8)=
### Ejercicio 25.8 - Suma de valores ⭐⭐☆☆☆

Sumar el primer elemento con el resultado de llamar a la función sobre el resto
del arreglo.

---

## Cadenas Recursivas
(ejercicio_25_9)=
### Ejercicio 25.9 - Palíndromo ⭐⭐☆☆☆

Implementar una función recursiva que determine si una cadena es un palíndromo.
Un palíndromo se lee igual en ambos sentidos.

**Lógica recursiva:** Una cadena es un palíndromo si:
1. Su primer y último carácter son iguales, Y
2. La subcadena entre ellos también es un palíndromo.

**Caso Base:** Una cadena vacía o de un solo carácter es un palíndromo.

**Ejemplo:** `neuquen`
- `es_palindromo("neuquen")` es verdadero.
(ejercicio_25_10)=
## Ejercicio 25.10 - Factorial Recursivo ⭐☆☆☆☆

Implementá factorial de forma recursiva.

**Orientación:**
- Caso base: `n <= 1` retorna 1
- Caso recursivo: `n * factorial(n-1)`
- Limitación: rápido overflow para n grande

---
(ejercicio_25_11)=
## Ejercicio 25.11 - Potencia Recursiva ⭐⭐☆☆☆

Calculá base^exponente recursivamente.

**Orientación:**
- Caso base: `exp == 0` retorna 1
- Caso recursivo: `base * potencia(base, exp-1)`
- Versión mejorada (siguiente ejercicio)

---
(ejercicio_25_12)=
## Ejercicio 25.12 - Potencia Rápida ⭐⭐⭐☆☆

Optimizá potencia usando divide y conquista.

**Algoritmo:**
- Si exp es par: `potencia(base, exp) = potencia(base*base, exp/2)`
- Si exp es impar: `potencia(base, exp) = base * potencia(base, exp-1)`

**Orientación:**
- Complejidad: O(log n) en lugar de O(n)
- Mucho más eficiente para exponentes grandes

---
(ejercicio_25_13)=
## Ejercicio 25.13 - Suma de Dígitos ⭐⭐☆☆☆

Sumá los dígitos de un número recursivamente.

**Orientación:**
- Caso base: `n < 10` retorna n
- Caso recursivo: `(n % 10) + suma_digitos(n / 10)`

---
(ejercicio_25_14)=
## Ejercicio 25.14 - Invertir String ⭐⭐☆☆☆

Invertí un string recursivamente.

**Orientación:**
- Caso base: string vacío o de 1 carácter
- Caso recursivo: último carácter + invertir(resto)
- Pensá en índices: `invertir(str, inicio, fin)`

---
(ejercicio_25_15)=
## Ejercicio 25.15 - Fibonacci Recursivo ⭐⭐⭐☆☆

Calculá el n-ésimo número de Fibonacci.

**Orientación:**
- Caso base: `n <= 1` retorna n
- Caso recursivo: `fib(n-1) + fib(n-2)`
- **Advertencia:** Muy ineficiente (exponencial) para n grande

---
(ejercicio_25_16)=
## Ejercicio 25.16 - Fibonacci con Memoización ⭐⭐⭐⭐☆

Optimizá Fibonacci usando memoización (caché de resultados).

**Orientación:**
- Array global `memo[MAX]` inicializado en -1
- Antes de calcular: `if (memo[n] != -1) return memo[n]`
- Después de calcular: `memo[n] = resultado`
- Complejidad: de O(2^n) a O(n)

---
(ejercicio_25_17)=
## Ejercicio 25.17 - Suma de Array ⭐⭐☆☆☆

Sumá elementos de un array recursivamente.

**Orientación:**
- Caso base: array vacío (`n == 0`) retorna 0
- Caso recursivo: `arr[0] + suma(arr+1, n-1)`
- O con índices: `arr[i] + suma(arr, i+1, n)`

---
(ejercicio_25_18)=
## Ejercicio 25.18 - Búsqueda Binaria Recursiva ⭐⭐⭐☆☆

Implementá búsqueda binaria de forma recursiva.

**Orientación:**
- Caso base: rango vacío (`inicio > fin`) retorna -1
- Calcular `medio = (inicio + fin) / 2`
- Si `arr[medio] == objetivo`: retornar medio
- Si `arr[medio] > objetivo`: buscar en mitad izquierda
- Si `arr[medio] < objetivo`: buscar en mitad derecha

---
(ejercicio_25_19)=
## Ejercicio 25.19 - Máximo en Array ⭐⭐⭐☆☆

Encontrá el máximo de un array recursivamente.

**Orientación:**
- Caso base: array de 1 elemento retorna ese elemento
- Caso recursivo: `max(arr[0], maximo(arr+1, n-1))`
- Divide y conquista: dividir en mitades y comparar máximos

---
(ejercicio_25_20)=
## Ejercicio 25.20 - Palíndromo Recursivo ⭐⭐⭐☆☆

Verificá si un string es palíndromo recursivamente.

**Orientación:**
- Caso base: string vacío o de 1 carácter: true
- Comparar primer y último carácter
- Si iguales: recursión en substring sin extremos
- Si diferentes: false

---
(ejercicio_25_21)=
## Ejercicio 25.21 - Torre de Hanoi ⭐⭐⭐⭐☆

Resolvé el problema de la Torre de Hanoi.

**Reglas:**
- Mover N discos de origen a destino usando auxiliar
- Solo un disco a la vez
- Nunca poner disco grande sobre uno pequeño

**Orientación:**
```{code-block} c
:linenos:
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        mover(origen, destino);
    } else {
        hanoi(n-1, origen, auxiliar, destino);
        mover(origen, destino);
        hanoi(n-1, auxiliar, destino, origen);
    }
}

```
<!-- {code-block} c -->

---
(ejercicio_25_22)=
## Ejercicio 25.22 - Permutaciones ⭐⭐⭐⭐⭐

Generá todas las permutaciones de un string.

**Orientación:**
- Para cada posición, probá cada carácter restante
- Intercambiá carácter actual con cada uno de los siguientes
- Recursión en resto del string
- Al retornar, deshacé el intercambio (backtracking)

---
(ejercicio_25_23)=
## Ejercicio 25.23 - Subconjuntos (Power Set) ⭐⭐⭐⭐⭐

Generá todos los subconjuntos de un conjunto.

**Orientación:**
- Para cada elemento: está o no está en el subconjunto
- Dos llamadas recursivas: con elemento y sin elemento
- Caso base: conjunto vacío
- Total: 2^n subconjuntos

---
(ejercicio_25_24)=
## Ejercicio 25.24 - MergeSort ⭐⭐⭐⭐⭐

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
(ejercicio_25_25)=
## Ejercicio 25.25 - QuickSort ⭐⭐⭐⭐⭐

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
(ejercicio_25_26)=
## Ejercicio 25.26 - N Reinas ⭐⭐⭐⭐⭐

Resolvé el problema de las N reinas (colocar N reinas en tablero N×N sin que se
ataquen).

**Orientación:**
- Colocá reina fila por fila
- Para cada fila, probá cada columna
- Verificá si la posición es segura (no ataca a otras)
- Si llegás a la última fila: solución encontrada
- Backtracking si no hay posición válida

---
(ejercicio_25_27)=
## Ejercicio 25.27 - Laberinto (Path Finding) ⭐⭐⭐⭐⭐

Encontrá camino en un laberinto desde inicio a fin.

**Orientación:**
- Matriz de 0s (libre) y 1s (pared)
- Desde posición actual, probá 4 direcciones (arriba, abajo, izq, der)
- Marcá visitados para evitar ciclos
- Si llegás a destino: true
- Backtracking: desmarcá visitado al retornar

---
(ejercicio_25_28)=
## Ejercicio 25.28 - Combinaciones (n choose k) ⭐⭐⭐⭐⭐

Generá todas las combinaciones de k elementos de un conjunto de n.

**Orientación:**
- Elegir elemento actual o no elegirlo
- Si elegís: k-1 elementos restantes
- Si no elegís: k elementos de n-1 restantes
- Caso base: k==0 (solución completa) o n<k (imposible)

---
(ejercicio_25_29)=
## Ejercicio 25.29 - Sudoku Solver ⭐⭐⭐⭐⭐

Resolvé un Sudoku usando backtracking.

**Orientación:**
- Encontrá primera celda vacía
- Probá números del 1 al 9
- Para cada número, verificá si es válido (fila, columna, subcuadro 3×3)
- Si válido: colocá número, recursión en siguiente celda
- Si recursión falla: deshacé (backtracking), probá siguiente número
- Caso base: no hay celdas vacías (solución encontrada)

---
(ejercicio_25_30)=
## Ejercicio 25.30 - s Adicionales ⭐⭐☆☆☆

(ejercicio_25_31)=
### Ejercicio 25.31 - Coeficiente Binomial ⭐⭐⭐☆☆

Calculá C(n,k) = n! / (k! × (n-k)!) recursivamente.

**Orientación:**
- Identidad de Pascal: `C(n,k) = C(n-1,k-1) + C(n-1,k)`
- Casos base: `C(n,0) = 1`, `C(n,n) = 1`

---
(ejercicio_25_32)=
### Ejercicio 25.32 - GCD (MCD) Recursivo ⭐⭐☆☆☆

Implementá algoritmo de Euclides recursivamente.

**Orientación:**
- Caso base: `b == 0` retorna a
- Caso recursivo: `gcd(b, a % b)`

---
(ejercicio_25_33)=
### Ejercicio 25.33 - Árbol de Expresión ⭐⭐⭐⭐⭐

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
int funcion_recursiva(parametros) {
    // 1. Caso base
    if (condicion_terminacion) {
        return valor_base;
    }
    
    // 2. Caso recursivo
    // Procesar actual
    // Llamada recursiva con problema reducido
    return combinar(
        procesar_actual,
        funcion_recursiva(problema_mas_pequeno)
    );
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
int suma(int n) {
    if (n == 0) return 0;
    return n + suma(n-1);  // Una llamada recursiva
}
```
<!-- c -->

**Recursión Múltiple:**
``` c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);  // Dos llamadas
}
```
<!-- c -->

**Recursión de Cola (Tail Recursion):**
``` c
int suma_tail(int n, int acumulador) {
    if (n == 0) return acumulador;
    return suma_tail(n-1, acumulador + n);  // Llamada al final
}
// Puede optimizarse a lazo por el compilador
```
<!-- c -->

**Recursión Mutua:**
```{code-block} c
:linenos:
bool es_par(int n);
bool es_impar(int n);

bool es_par(int n) {
    if (n == 0) return true;
    return es_impar(n-1);
}

bool es_impar(int n) {
    if (n == 0) return false;
    return es_par(n-1);
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

void inicializar() {
    for (int i = 0; i < MAX; i++) memo[i] = -1;
}

int funcion(int n) {
    if (n <= caso_base) return valor_base;
    
    if (memo[n] != -1) return memo[n];  // Ya calculado
    
    memo[n] = calcular(n);  // Calcular y cachear
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

