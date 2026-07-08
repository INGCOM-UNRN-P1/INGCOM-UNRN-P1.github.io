---
title: Ejercicios de Análisis de Complejidad Algorítmica
short_title: 10. Complejidad
---

# Ejercicios de Análisis de Complejidad Algorítmica

## Acerca de

Estos ejercicios tienen como fin practicar el análisis asintótico de algoritmos, el uso de las notaciones Big-O, Omega y Theta, y el cálculo formal e informal del costo temporal y espacial de subprogramas iterativos y recursivos en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-complejidad`

### Cuestiones de Estilo Aplicables
- **Medición e instrumentación:** Al implementar análisis empíricos, utilizá la biblioteca `<time.h>` para medir tiempos físicos reales sin alterar la estructura algorítmica principal del código evaluado.

---

## Fundamentos de Notación Asintótica

### Ejercicio 10.1 - Simplificación de Funciones

Para cada función de costo, determinar su clasificación en notación Big-O (ignorando constantes y términos de menor orden):
a) $T(n) = 5n^3 + 2n^2 + 100$  
b) $T(n) = 3n \log n + 2n + 50$  
c) $T(n) = 2^n + n^3 + 1000n$  
d) $T(n) = \log(n^2) + \sqrt{n}$  
e) $T(n) = n! + 2^n + n^{10}$

### Ejercicio 10.2 - Comparación de Funciones

Ordenar las siguientes funciones de menor a mayor tasa de crecimiento asintótico:
$$\log n, \quad n^2, \quad 2^n, \quad n!, \quad n \log n, \quad \sqrt{n}, \quad n^3, \quad 1, \quad n \log^2 n, \quad 2^{2n}$$

### Ejercicio 10.3 - Verdadero o Falso

Determinar si las siguientes afirmaciones son verdaderas o falsas. Justificar.
a) $n^2 + n = O(n^2)$  
b) $n^2 = O(n^3)$  
c) $n^3 = O(n^2)$  
d) $2^n = O(3^n)$  
e) $3^n = O(2^n)$  
f) $\log_2 n = O(\log_{10} n)$  
g) $n \log n = O(n^2)$  
h) $n^2 = \Omega(n \log n)$

### Ejercicio 10.4 - Demostración Formal de Big-O

Demostrar formalmente que $f(n) = 3n^2 + 5n + 2$ es $O(n^2)$ encontrando constantes $c$ y $n_0$ que satisfagan la definición.

---

## Análisis de Lazos Simples

### Ejercicio 10.5 - Lazo Simple

Analizar la complejidad temporal de este código:
```c
int suma = 0;
for (int i = 0; i < n; i++) {
    suma += i;
}
```

### Ejercicio 10.6 - Lazo con Incremento Variable

Analizar la complejidad de:
```c
int suma = 0;
for (int i = 0; i < n; i += 2) {
    suma += i;
}
```

### Ejercicio 10.7 - Lazo con Multiplicación

Analizar la complejidad de:
```c
int contador = 0;
for (int i = 1; i < n; i *= 2) {
    contador++;
}
```

### Ejercicio 10.8 - Lazo con División

Analizar la complejidad de:
```c
int contador = 0;
for (int i = n; i > 1; i /= 2) {
    contador++;
}
```
