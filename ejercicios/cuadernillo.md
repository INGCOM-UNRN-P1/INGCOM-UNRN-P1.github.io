---
title: Repositorio de enunciados
short_title: Cuadernillo 1
subtitle: Los primeros ejercicios
---

## Acerca de

El (__primer__) gran repositorio de enunciados de programación, 
y aunque esté pensado para la cátedra Programación 1 en la que 
utilizamos C, pero son aplicables a (casi) cualquier lenguaje.

### Consideraciones generales

A seguir siempre y cuando no esté indicada otra cosa:

1.  Resuelvan todos los ejercicios de manera iterativa, a no ser que
    esté indicado puntualmente.
2. Los números son números enteros, estos incluyen al cero y los
    negativos.
3. El nombre del archivo debe ser, el número del ejercicio
    reemplazando el punto por un guion y su apellido, por ejemplo\
    *1-1_vilugron.c*
4. Apliquen y completen la plantilla de resolución de ejercicios que
    está a continuación, en la misma, copien el título y consigna del
    ejercicio primero. Y luego completen con sus datos.
5.  Lo que 'resuelve' el enunciado, debe de estar en una función.
    Incluso si no hay una indicada explicitamente.
6. El código debe seguir la [guía de estilo](../apunte/estilo.md).
7. Los ejercicios marcados como \[*plus ultra*\] son variaciones
    del ejercicio, con otras formas para ir «más allá» de la consigna
    original.

```{note}
"Más allá" Frase en latín utilizada por Carlos I, durante la
    época de Colón.
    
[Wikipedia - Plus_ultra_(lema)](https://es.wikipedia.org/wiki/Plus_ultra_(lema))
```

### Plantilla de archivo

En un archivo llamado

```{code}c
:label: c_template
:filename: 1-1_apellido.c
:caption: Para tener todo ordenado
/*
Ejercicio 1.1 – Hola Mundo
Porque hay que empezar por algún lado, escribir un programa que 
imprima "Hola, mundo!" en la pantalla.
Este ejercicio nos permitirá verificar el que el entorno de 
programación funciona.
-----------------
Nombre y Apellido
Usuario Github
*/
```

A pesar de que varios de los ejercicios son combinables, es mejor
hacerlo cuando veamos funciones, cosa de simplificar las cosas.

## 1.1 - ¡Hola mundo!

Porque hay que empezar por algún lado, escribir un programa que imprima
\"Hola, mundo!\" en la pantalla.

Este ejercicio nos permitirá verificar el que el entorno de programación
funciona.


```{code}
:caption: El indispensable Hola Mundo!
:filename: salida

Hola mundo!

```

### 1.1.A - Saludador \[*plus ultra*\]

Escribir un programa que salude por nombre.

```{code}
:filename: entrada

Martin

```

```{code}
:caption: El indispensable Hola Mundo!
:filename: salida

Hola mundo, Martin!

```

### 1.1.B - Tipografías ASCII art \[*plus ultra*\]

Si lo quieren complicar, pueden aplicar un poco de [ASCII
art](https://en.wikipedia.org/wiki/ASCII_art).

Salida

```{code}
:caption: El indispensable Hola Mundo!
:filename: salida
  _   _           _                                             _           _ 
 | | | |   ___   | |   __ _     _ __ ___    _   _   _ __     __| |   ___   | |
 | |_| |  / _ \  | |  / _` |   | '_ ` _ \  | | | | | '_ \   / _` |  / _ \  | |
 |  _  | | (_) | | | | (_| |   | | | | | | | |_| | | | | | | (_| | | (_) | |_|
 |_| |_|  \___/  |_|  \__,_|   |_| |_| |_|  \__,_| |_| |_|  \__,_|  \___/  (_)
                                                                              
```

## 1.2 - Geometría

### 1.2.1 - Área de triángulos

**Calcular el área de un triángulo con una base y altura dadas.**

El área de un triángulo se puede calcular como la mitad del producto de su base por su altura.

$$A = \frac{1}{2} \cdot b \cdot h$$

Donde:
-   $A$ es el área.
-   $b$ es la longitud de la base.
-   $h$ es la altura perpendicular a la base.

**Calcular el área de un triángulo utilizando la fórmula de Herón.**

La fórmula de Herón permite calcular el área de un triángulo conociendo la longitud de sus tres lados.

$$A = \sqrt{s(s-a)(s-b)(s-c)}$$

Primero, se calcula el semiperímetro $s$:

$$s = \frac{a+b+c}{2}$$

Donde:
-   $a$, $b$, y $c$ son las longitudes de los lados del triángulo.


### 1.2.2 - Círculos

**Calcular el área y la circunferencia de un círculo.**

El **área** de un círculo es proporcional al cuadrado de su radio.

$$A = \pi \cdot r^2$$

La **circunferencia** es la distancia alrededor del círculo.

$$C = 2 \cdot \pi \cdot r$$

Donde:
-   $r$ es el radio del círculo.
-   $\pi$ (pi) es una constante aproximadamente igual a 3.14159.


### 1.2.3 - Trapecios

**Calcular el área de un trapecio.**

El área de un trapecio se calcula multiplicando la semisuma de sus bases (los lados paralelos) por su altura.

$$A = \frac{a+b}{2} \cdot h$$

Donde:
-   $a$ y $b$ son las longitudes de las bases paralelas.
-   $h$ es la altura perpendicular a las bases.


### 1.2.4 - Polígonos

**Calcular el área de un polígono regular.**

El área de un polígono regular se puede calcular multiplicando la mitad de su perímetro por la longitud de su apotema.

$$A = \frac{P \cdot a}{2}$$

Donde:
-   $P$ es el perímetro del polígono (suma de la longitud de sus lados).
-   $a$ es la apotema (la distancia desde el centro del polígono al punto medio de uno de sus lados).

---

### 1.2.5 - Rectángulos

**Calcular el área de un rectángulo con longitud y ancho dados.**

El área de un rectángulo es el producto de su longitud por su ancho.

$$A = l \cdot w$$

Donde:
-   $l$ es la longitud.
-   $w$ es el ancho.


## 1.3 - Conversiones

```{note} [](../apunte/estilo#0x0001h)

No olviden utilizar identificadores descriptivos.

```

### 1.3.1 - Temperaturas

Revisen los resultados que las operaciones matematicas en C, con números decimales
pueden dar resultados erroneos cuando se utilizan de forma inapropiada.

#### 1.3.1.1 - Convertir grados Celsius a Kelvin

Escribe un programa que solicite al usuario un valor en grados Celsius y 
lo convierta a grados Kelvin.

Para convertir una temperatura de grados Celsius ($C$) a Kelvin ($K$), se 
utiliza la fórmula $K=C+273.15$. 

#### 1.3.1.2 - Convertir grados Kelvin a Celsius

Escribe un programa que solicite al usuario un valor en grados Kelvin y
lo convierta a grados Celsius.

La conversión de Kelvin ($K$) a grados Celsius ($C$) se realiza con la fórmula 
$C=K−273.15$.

#### 1.3.1.3 - Convertir grados Celsius a grados Fahrenheit

Escribe un programa que pida un valor en grados Celsius y lo transforme a
grados Fahrenheit.  

La fórmula para convertir de grados Celsius ($C$) a Fahrenheit ($F$) es 
$F=(C×59​)+32$. 

#### 1.3.1.4 - Convertir grados Fahrenheit a Celsius

Escribe un programa que reciba un valor en grados Fahrenheit y lo convierta a grados Celsius.  

Para transformar grados Fahrenheit ($F$) a Celsius ($C$), la fórmula es $C=(F−32)×95​$.

#### 1.3.1.5 - Conversiones \[*plus ultra*\]

Considerando la consignas de conversion, modifica tu implementación para que la
misma se realice utilizando exclusivamente aritmética de números enteros.

Los resultados tambien deben ser un número entero.

Agrega un comentario en el código que explique las implicaciones de esta restricción
en la precisión del resultado.

### 1.3.2 - Ángulos a segundos

Convertir un número ingresado como grados, minutos y segundos a
segundos.

En donde un grado son 60 minutos y un minuto son 60 segundos.

```{code}
:filename: entrada

1
2
3

```


```{code}
:filename: salida

1 grado, 2 minutos y 3 segundos son 3723 segundos

```

#### 1.3.2.1 - Con vueltas \[*plus ultra*\]

Una vuelta son 360 grados.

```{code}
:filename: entrada

1
2
3
4

```


```{code}
:filename: salida

1 vuelta, 2 grados, 3 minutos y 4 segundos son 372378203040 segundos

```

## 1.4 - Matemáticos

### 1.4.1 - Suma lenta

Implementar una suma entre números enteros $n+m$; en la que no se puede
sumar directamente $n$ con $m$.


```{code}
:filename: entrada

10
6

```


```{code}
:filename: salida

10 + 6 = 16

```

Lo importante en este ejercicio, es que el resultado se obtiene con
sumas o restas de uno en uno.

En el ejemplo anterior, los cálculos empleados terminan siendo:

$$
10+1+1+1+1+1+1=16
$$

Mientras que para un número negativo, sería:

```{code}
:filename: entrada

10
-6

```

```{code}
:filename: salida

10 + -6 = 4

```

En donde los cálculos aplicados terminan siendo:

$$
10−1−1−1−1−1−1=4
$$

Recuerden tener en cuenta las cuatro combinaciones posibles de signos.

### 1.4.2 - División lenta

Implementar la división entera de dos números enteros solo utilizando
restas.

```{code}
:filename: entrada

10
2

```

```{code}
:filename: salida

10 / 2 = 5

```


En donde los cálculos aplicados terminan siendo:

$$
12−2−2−2−2−2 = 0
$$

Recuerden tener en cuenta las cuatro combinaciones posibles de signos.

### 1.4.3 - Resto lento

Implementar el resto de la división entera de dos números enteros solo
utilizando restas.


```{code}
:filename: entrada

13
2

```

```{code}
:filename: salida

13 % 2 = 1

```

En donde los cálculos aplicados terminan siendo:

$$
13−2−2−2−2−2 = 1
$$

Recuerden tener en cuenta las cuatro combinaciones posibles de signos.

### 1.4.5 - División egipcia

El método de división egipcia es un antiguo algoritmo que permite dividir dos números 
utilizando únicamente operaciones de duplicación, suma y resta, sin necesidad de realizar 
la división de forma directa. Se basa en la idea de encontrar qué múltiplos del divisor
(obtenidos por duplicación) suman el dividendo.

Pasos del método

1.  **Crear dos columnas:** En la primera columna se escribe el número $1$. En la segunda, el divisor.
2.  **Duplicar los valores:** Se duplican los valores de ambas columnas en cada fila subsiguiente. Se detiene cuando el siguiente número en la columna del divisor superaría al dividendo.
3.  **Encontrar la combinación:** Se buscan en la columna del divisor (de abajo hacia arriba) los números que, sumados, se acerquen lo más posible al dividendo sin pasarse.
4.  **Calcular el cociente:** Se suman los números de la primera columna que corresponden a las filas de los números elegidos en el paso anterior. El resultado es el cociente de la división.
5.  **Calcular el resto:** Se resta la suma de los números elegidos en la columna del divisor al dividendo original. El resultado es el resto.

 
**Ejemplo**: Calcular $37 ÷ 6$

1.  **Construir la tabla:** Se crean dos columnas. La primera empieza en $1$ y la segunda en el divisor ($6$). Ambas se duplican en cada paso.

    | Columna 1 | Columna 2 (Divisor: $6$) |
    | :--- | :--- |
    | $1$ | $6$ |
    | $2$ | $12$ |
    | $4$ | $24$ |
    | $8$ | $48$ *(se detiene porque $48 > 37$)* |

2.  **Buscar la suma:** Se buscan los números en la **Columna 2** que sumen $37$ (o lo más cercano por debajo), empezando por el más grande.
    -   Se toma el **24**. (Queda por sumar: $37 - 24 = 13$).
    -   Se busca el siguiente número que quepa en 13. Se toma el **12**. (Queda por sumar: 13 - 12 = 1).
    -   El siguiente número es 6, pero no se puede tomar porque 6 > 1.
    -   Los números seleccionados de la Columna 2 son **24** y **12**.

3.  **Obtener el resultado:**
    -   **Cociente:** Se suman los números correspondientes de la **Columna 1**: $4 + 2 = 6$.
    -   **Resto:** Se resta la suma de los números seleccionados (24 + 12 = 36) del dividendo original: $37 - 36 = 1 $.

El resultado final es: 

```
Cociente = 6 y Resto = 1.
```

### 1.4.6 - Divisibilidad

Determinar si un número es divisible por otro.


```{code}
:filename: entrada

10
2

```


```{code}
:filename: salida

10 es divisible por 2

```

### 1.4.7 - Al cuadrado

Calcular la potencia de dos de un número dado.

$$
n^2
$$

```{code}
:filename: entrada

10

```

```{code}
:filename: salida

10 ^ 2 = 100

```

### 1.4.8 - Factorial

Calcular el factorial de un número. Esta operación se define como el
producto de todos los números enteros positivos desde 1 hasta el número.

La operación solo puede ser aplicada a valores positivos

$$n{! = {\prod\limits_{k = 1}^{n}k}}$$

Por ejemplo:

$5! = 1×2×3×4×5 = 120$

```{code}
:filename: entrada

5

```

```{code}
:filename: salida

5! = 120

```

### 1.4.8 - Dígitos

Calcular la suma de los dígitos de un número entero de manera
aritmética.


```{code}
:filename: entrada

1234

```


```{code}
:filename: salida

10

```

El cálculo esperado es: $4+3+2+1 = 10$.

### 1.4.9 - Dígitos de factorial

Crear un programa que calcule e imprima la suma de los dígitos de un
número factorial.

```{code}
:filename: entrada

5

```

```{code}
:filename: salida

5! = 120 -> 3

```


### 1.4.10 - MCD

Escribir un programa que determine el máximo común divisor (MCD) entre
dos números ingresados por teclado (m y n)

El algoritmo de MCD iterativo plantea que para cada iteración:

* Si $(n \le m)$ y $(m \pmod n) = 0$, entonces el MCD es $n$.
* Si $m < n$, se intercambian los valores: $m \leftrightarrow n$.
* Si $m > n$ y $(m \pmod n) \ne 0$, entonces $m = m \pmod n$, y se intercambian los valores: $m \leftrightarrow n$.

### 1.4.11 - MCM

Calcular el mínimo común múltiplo (MCM) de dos números.

El **Mínimo Común Múltiplo** de dos números enteros positivos $n$ y $m$ es 
un valor $c$ entero y positivo tal que al dividir $c/n$ y $c/m$, el resto 
es $0$, y además no existe otro número menor que $c$ que cumpla esta condición.

### 1.4.11 - Capicúas

Verificar si un número es capicúa de manera aritmética.

**Ejemplo capicua**

```{code}
:filename: entrada

1001

```

```{code}
:filename: salida

1001 es capicua

```

**Ejemplo no capicua**

```{code}
:filename: entrada

1234

```

```{code}
:filename: salida

1234 no es capicua

```

### 1.4.12 - Capicúas entre

Imprimir todos los números capicúa en un rango $(n,m)$ dado.

```{code}
:filename: entrada

100
200
```

```{code}
:filename: salida

Entre 100 y 200, los numeros capicua son:
101

```


### 1.4.13 - Números amigos

Solicitar dos números enteros positivos y determinar si son números 
amigos. Dos números son amigos si la suma de los divisores propios 
de cada uno es igual al otro número.

Por ejemplo, $220$ y $284$ son amigos.

### 1.4.14 - Invertir un número entero

Pedir un número entero positivo y mostrarlo con sus dígitos en orden inverso, sin usar arreglos ni cadenas de caracteres.  

```{code}
:filename: entrada
12345
```


```{code}
:filename: salida
54321
```

## 1.5 - Secuencias

Los ejercicios de secuencias no requieren que guardemos los valores
intermedios, ejercicios que si lo requieren están en la categoría
[Arreglos](!).

### 1.5.1 - Cuenta regresiva

Imprimir una cuenta regresiva de diez, pueden usar `sleep(1)` de
`stdlib.h` para que la cuenta no sea instantánea.

```{code}
:filename: salida

10
9
8
...
3
2
1
Lanzamiento!
```

#### 1.5.1.A - Cuenta regresiva ajustable \[*plus ultra*\]
Lo mismo que el ejercicio anterior, pero con conteo 
seleccionable por el usuario

```{code}
:filename: entrada

3

```


```{code}
:filename: salida

3
2
1
Lanzamiento!

```

### 1.5.2 - Pares

Imprimir la secuencia de números pares entre $n$ y $m$.

```{code}
:filename: entrada

10
15

```


```{code}
:filename: salida

10
12
14

```

### 1.5.3 - Ascendente

Mostrar los números entre $n$ y $m$ de forma ascendente siendo $n ≥ i < m$

```{code}
:filename: entrada

2
5

```


```{code}
:filename: salida

El intervalo [2; 5) es:
2
3
4

```

### 1.5.4 - Suma en rango

Sumar los números entre n y m según:

$$
\sum\limits_{i = n}^{m}i
$$

```{code}
:filename: entrada
3
5
```

```{code}
:filename: salida
La suma entre 3 y 5 es 12
```

### 1.5.5 - Cuadrados ascendentes

Obtener al suma de los cuadrados entre n y m.

$$
\sum\limits_{i = n}^{m}i^{2}
$$


```{code}
:filename: entrada
3
5
```

```{code}
:filename: salida
Los cuadrados ascendentes entre 3 y 5 es = 50
```

### 1.5.6 - Descendente

Imprimir los números entre $n$ y $m$ de forma descendente. ($n ≥ i < m$)

```{code}
:filename: entrada
10
7
```


```{code}
:filename: salida
10
9
8
```

### 1.5.7 - n-impares

Imprimir la secuencia de números impares del 1 hasta n.


```{code}
:filename: entrada
10
```

```{code}
:filename: salida
1
3
5
7
9
```

### 1.5.8 - n-esimos numeros sumados

Calcular la suma de los primeros n números naturales de manera iterativa.
Sin usar simetría de las progresiones aritméticas, o lo que descubrió Gauss.

$$
\sum_{k=1}^{n} k
$$

```{code}
:filename: entrada
10
```


```{code}
:filename: salida
La suma de los primeros 10 numeros es 55
```


### 1.5.9 - i-fibonacci'esimo

Imprimir el i-esimo termino de la serie de Fibonacci.

La serie de Fibonacci está definida por:

$$
f(i) = \begin{cases}
0 & \text{si } i = 0 \\
1 & \text{si } i = 1 \\
f(i-1) + f(i-2) & \text{si } i > 1
\end{cases}
$$

La secuencia para el octavo termino queda como

$$
8 = (0, 1, 1, 2, 3, 5, 8, 13)
$$


```{code}
:filename: entrada
8
```

```{code}
:filename: salida
El termino 8 es 13
```

```{note} Sobre los terminos

En la literatura también se encuentra el primer término como $1$,
    esto solo desplaza en uno la serie. El resultado en sí no cambia.

```

### 1.5.10 - Dígitos de Fibonacci

Obtener la suma de los dígitos del i-esimo termino de las serie de
Fibonacci.

Siendo el octavo termino $13$, la suma de sus dígitos es $4$; $1+3$

```{code}
:filename: entrada
8
```

```{code}
:filename: salida
4
```

## 1.6 - Condicionales

### 1.6.1 - Par o Impar
Dado un número entero, determinar si es par o impar.

Un número entero $n$ se considera **par** si es un múltiplo de 2, es decir, si existe un entero $k$ tal que:

$$
n = 2k
$$

Si un número no es par, se considera **impar**. Esto se puede expresar matemáticamente como la existencia de un entero $k$ tal que:

$$
n = 2k + 1
$$


### 1.6.2 - Signo de un Número

Dado un número real $x$, clasificarlo como positivo, negativo o cero. La clasificación se basa en las siguientes propiedades:

$$
S(n) = \begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
S(n-1) + n & \text{si } n > 1
\end{cases}
$$

## 1.7 - Primos

Un número natural $p > 1$ se considera **primo** si sus únicos divisores positivos son $1$ y él mismo. Cualquier número entero mayor que $1$ que no es primo se denomina **número compuesto**.

### 1.7.1 - ¿Es primo?

Determinar si un número es primo o compuesto.

### 1.7.2 - Varios primos

Escribir un programa que genere y muestre los primeros $n$ números primos, donde $n$ es un valor proporcionado por el usuario.

## 1.8 - Fechas

### 1.8.1 - Es bisiesto?

Determinar si un año dado es bisiesto. 

Un año es **bisiesto** si cumple una de las siguientes reglas del calendario gregoriano:

1. Es divisible por 4, pero no es divisible por 100.
2. Es divisible por 400.



