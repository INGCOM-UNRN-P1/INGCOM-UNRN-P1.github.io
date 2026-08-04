---
title: "Ejercicios: Recursividad y Divide y Vencerás"
short_title: "5. Recursividad"
---

# Ejercicios de Recursividad y Divide y Vencerás

## Acerca de

Estos ejercicios tienen como propósito dominar la recursividad de control y el
paradigma de diseño "Divide y Vencerás" en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-recursividad-basica`

### Cuestiones de Estilo Aplicables
- **Casos de corte explícitos:** Definí el caso base al inicio de la función
  recursiva para evitar lazo de llamada infinitos y desbordamientos de stack
  frame (ver {ref}`0x2009h`).
- **Uso de recursión de cola:** Cuando sea posible, estructurá las funciones
  recursivas utilizando parámetros acumuladores para permitir la optimización
  por parte del compilador.

---

## Fundamentos de Recursividad

### Ejercicio 5.12 - Factorial

Implementar la función factorial de forma recursiva siguiendo la definición
matemática.

``` c
long int factorial(int n);
```
<!-- c -->

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

### Ejercicio 5.13 - Suma de Enteros

Implementar suma de dos enteros positivos usando solo recursividad (sin operador
`+` en el paso recursivo).

``` c
int suma_recursiva(int a, int b);
```
<!-- c -->

**Estrategia:** Decrementar `b` e incrementar `a` hasta que `b` sea 0.

$$
suma(a, b) = \begin{cases}
a & \text{si } b = 0 \\
suma(a + 1, b - 1) & \text{si } b > 0
\end{cases}
$$

### Ejercicio 5.14 - Producto por Sumas Recursivas

Implementar multiplicación usando solo sumas recursivas.

``` c
int producto_recursivo(int a, int b);
```
<!-- c -->

$$
a \times b = \begin{cases}
0 & \text{si } b = 0 \\
a + producto(a, b - 1) & \text{si } b > 0
\end{cases}
$$

**Complejidad:** $O(b)$ en tiempo.

### Ejercicio 5.15 - Potencia

Implementar $base^{exponente}$ de forma recursiva.

``` c
long int potencia(int base, int exponente);
```
<!-- c -->

**Versión básica:** $O(n)$ en tiempo.

$$
base^{exp} = \begin{cases}
1 & \text{si } exp = 0 \\
base \times potencia(base, exp - 1) & \text{si } exp > 0
\end{cases}
$$

**Desafío:** Implementar versión optimizada usando exponenciación rápida (divide
y vencerás) con complejidad $O(\log n)$.

$$
base^{exp} = \begin{cases}
1 & \text{si } exp = 0 \\
\left(base^{exp/2}\right)^2 & \text{si } exp \text{ es par} \\
base \times \left(base^{(exp-1)/2}\right)^2 & \text{si } exp \text{ es impar}
\end{cases}
$$

---

## Series Numéricas Recursivas

### Ejercicio 5.16 - Fibonacci Básico

Implementar la secuencia de Fibonacci recursivamente.

``` c
long int fibonacci(int n);
```
<!-- c -->

**Ecuación de recurrencia:**

$$
F(n) = \begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
F(n-1) + F(n-2) & \text{si } n > 1
\end{cases}
$$
