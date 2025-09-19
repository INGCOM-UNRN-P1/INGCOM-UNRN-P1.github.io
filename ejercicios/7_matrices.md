---
title: Ejercicios de matrices
short_title: 7. Matrices
---

Ejercicios para trabajar con arreglos bidimensionales (matrices), tanto
estáticas como dinámicas.

## 1: Operaciones Básicas

### 1.1: Mostrar Matriz

Imprimir una matriz en un formato legible. **Ejemplo Salida (matriz 2x3):**

```text
Matriz (2x3):
[ 1, 2, 3 ]
[ 4, 5, 6 ]
```

### 1.2: Multiplicación por un escalar

Multiplicar cada elemento de la matriz por un número dado. $$ B = k \cdot A
\implies b*{ij} = k \cdot a*{ij} $$

## 2: Aritmética Matricial

### 2.1: Suma de matrices

Sumar dos matrices de las mismas dimensiones.
$C = A + B \implies c_{ij} = a_{ij} + b_{ij}$.

$$
\begin{pmatrix} 1 & 2 \\ 3 & 4
\end{pmatrix} +
\begin{pmatrix} 5 & 6 \\ 7 & 8
\end{pmatrix} =
\begin{pmatrix} 6 & 8 \\ 10 & 12
\end{pmatrix}
$$

### 2.2: Multiplicación de matrices

Si A es $m \times n$ y B es $n \times p$, entonces $C = A \cdot B$ es
$m \times p$. El elemento $c_{ij}$ se calcula como: $$ c*{ij} = \sum*{k=1}^{n}
a*{ik} \cdot b*{kj} $$

## 3: Manipulación

### 3.1: Transposición

La transpuesta $A^T$ de una matriz $A$ se obtiene intercambiando filas por
columnas. $(A^T)_{ij} = A_{ji}$.

$$
A = \begin{pmatrix} 1 & 2 \\ 3 & 4 \\ 5 & 6
\end{pmatrix},
A^T = \begin{pmatrix} 1 & 3 & 5 \\ 2 & 4 & 6
\end{pmatrix}
$$

### 3.2: Suma de diagonales

Para una matriz cuadrada, sumar los elementos donde $i=j$ (principal) y donde
$i+j = n-1$ (secundaria).

## 4: Generación

### 4.1: Matriz Identidad

Una matriz cuadrada $I_n$ con unos en la diagonal principal y ceros en el resto.

$$
I_3 = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1
\end{pmatrix}
$$
