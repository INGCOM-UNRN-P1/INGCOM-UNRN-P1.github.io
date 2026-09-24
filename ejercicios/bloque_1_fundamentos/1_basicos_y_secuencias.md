---
title: Ejercicios Básicos y Secuencias
short_title: 1. Básicos
---

# Ejercicios Básicos y Secuencias

## Acerca de

Estos ejercicios están diseñados para afianzar los conceptos más fundamentales
de la programación en C. A través de ellos, se practicará el uso de variables,
la entrada y salida por consola, y la implementación de estructuras de control
básicas (lazos y condicionales) para resolver problemas simples y generar
secuencias numéricas.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-fundamentos-computacion`
- {ref}`capitulo-introduccion-c`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Estructura básica de un programa en C11: función `main(void)` y valor de retorno ({ref}`capitulo-introduccion-c`).
2. Declaración, inicialización y ámbito de variables de tipos primitivos escalares (`int`, `double`).
3. Estructuras de control iterativas: sintaxis y semántica de lazos `for` y `while`.
4. Salida por consola formateada mediante `printf` y pruebas unitarias con aserciones (`assert`).

### Cuestiones de Estilo Aplicables
- **Resolución mediante funciones:** Según la {ref}`0x2008h`, la lógica principal que
  resuelve cada enunciado debe estar contenida en una función, incluso si no se
  especifica de forma explícitamente.
- **Separación de entrada/salida:** De acuerdo con la {ref}`0x2002h`, las funciones no deben contener
  `printf` o `scanf`, a menos que su propósito explícito sea interactuar con el
  usuario.
- **Uso de llaves:** Toda estructura de control debe utilizar llaves (`{}`)
  según la {ref}`0x1001h`.
- **Lazos:** Según la {ref}`0x1003h`, se
  debe preferir el uso de lazos `for` para iteraciones con rango o contador
  definido, y `while` para lazos controlados por condiciones lógicas.

---

## Primeros Pasos y Salida Básica

(ej_b1_c01_01)=
### Ejercicio 1.01.01 - Cuenta regresiva ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c01_01_cuenta_regresiva

Implementá una función pura que calcule la cantidad de pasos de una cuenta regresiva desde $N$ hasta $1$ y la suma acumulada de los valores emitidos:
- `int calcular_pasos_regresiva(int n)`: retorna la cantidad de números emitidos si $n \ge 1$, o `0` si $n \le 0$.
- `long long suma_cuenta_regresiva(int n)`: retorna la suma de los enteros de $1$ a $n$, o `0` si $n \le 0$.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Valor $N$ | Pasos Retornados | Suma Acumulada |
| :--- | :--- | :--- | :--- |
| Escalar 5 | `5` | `5` | `15` ($5+4+3+2+1$) |
| Unitario | `1` | `1` | `1` |
| Nulo | `0` | `0` | `0` |
| Negativo | `-4` | `0` | `0` |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

int calcular_pasos_regresiva(int n) {
    if (n <= 0) {
        return 0;
    }
    int pasos = 0;
    for (int i = n; i >= 1; --i) {
        pasos++;
    }
    return pasos;
}

long long suma_cuenta_regresiva(int n) {
    if (n <= 0) {
        return 0;
    }
    long long suma = 0;
    for (int i = n; i >= 1; --i) {
        suma += i;
    }
    return suma;
}

int main(void) {
    assert(calcular_pasos_regresiva(5) == 5);
    assert(calcular_pasos_regresiva(1) == 1);
    assert(calcular_pasos_regresiva(0) == 0);
    assert(calcular_pasos_regresiva(-4) == 0);

    assert(suma_cuenta_regresiva(5) == 15);
    assert(suma_cuenta_regresiva(1) == 1);
    assert(suma_cuenta_regresiva(0) == 0);
    assert(suma_cuenta_regresiva(-10) == 0);

    return 0;
}
```
::::
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
ALGORITMO cuenta_regresiva
ENTRADA: numero_inicio (entero)

INICIO
    PARA i DESDE numero_inicio HASTA 1 CON PASO -1 HACER
        ESCRIBIR i, "..."
        ESPERAR 1 segundo
    FIN PARA

    ESCRIBIR "¡Lanzamiento!"
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_02)=
### Ejercicio 1.01.02 - ¡Hola mundo! ⭐⭐☆☆☆

El "Hola, mundo!" es el primer paso tradicional en el aprendizaje de un nuevo
lenguaje de programación. El objetivo es escribir el programa más simple posible
que produzca una salida visible en la pantalla, confirmando que el compilador y
el entorno de desarrollo están configurados y funcionando correctamente.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Este programa no requiere ninguna entrada del usuario.
-   **Proceso:** Se utiliza una función de la biblioteca estándar para enviar
-   **Salida:** El programa debe imprimir la cadena de texto "Hola, mundo!"
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO hola_mundo

INICIO
    ESCRIBIR "Hola, mundo!"
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_03)=
### Ejercicio 1.01.03 - Saludador ⭐⭐☆☆☆

Este ejercicio amplía el "Hola, mundo!" para que el programa interactúe con el
usuario. Debe solicitarle su nombre y luego mostrar un saludo personalizado que
lo incluya. Sirve para practicar la lectura de datos desde la entrada estándar.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable para almacenar el nombre del usuario.
-   **Entrada:** El programa debe primero mostrar un mensaje pidiendo al usuario su nombre.
-   **Funciones de Lectura:** Se puede usar `scanf()` o `fgets()` para leer la entrada del usuario.
-   **Salida:** Finalmente, el programa debe imprimir el saludo personalizado incluyendo el nombre.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO saludador

VARIABLES:
    nombre (cadena)

INICIO
    ESCRIBIR "Por favor, ingresa tu nombre:"
    LEER nombre
    ESCRIBIR "Hola mundo, ", nombre, "!"
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Rangos y Secuencias

(ej_b1_c01_04)=
### Ejercicio 1.01.04 - Pares en un rango ⭐⭐⭐☆☆

El programa debe ser capaz de identificar y mostrar todos los números pares que
existen dentro de un intervalo cerrado `[n, m]`, donde los límites `n` y `m` son
proporcionados por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se deben leer dos números enteros, `n` (inicio del rango) y `m`
-   **Proceso:** Se utiliza un lazo `for` que recorra cada número `i` desde `n`
-   **Condición de Paridad:** Dentro del lazo, para cada número `i`, se debe verificar si `i % 2 == 0`.
-   **Salida:** Si la condición de paridad se cumple, el número `i` se imprime
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO pares_en_rango
ENTRADA: n, m (enteros)

INICIO
    PARA i DESDE n HASTA m HACER
        SI i MOD 2 == 0 ENTONCES
            ESCRIBIR i
        FIN SI
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_05)=
### Ejercicio 1.01.05 - Primeros N Impares ⭐⭐☆☆☆

Este ejercicio consiste en generar una secuencia de números impares, comenzando
desde 1, hasta alcanzar un total de $N$ términos, donde $N$ es un número
proporcionado por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se debe leer un número entero $N$ que representa la cantidad de números impares a generar.
-   **Proceso:** Se puede abordar de dos maneras:
-   **Salida:** Se imprime la secuencia de los primeros $N$ números impares.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO primeros_n_impares
ENTRADA: n_terminos (entero)

INICIO
    PARA k DESDE 1 HASTA n_terminos HACER
        impar = 2 * k - 1
        ESCRIBIR impar
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Operaciones con Rangos Numéricos

(ej_b1_c01_06)=
### Ejercicio 1.01.06 - Secuencia Ascendente ⭐⭐☆☆☆

El objetivo es mostrar una secuencia de números enteros que comienza en un
número `n` y termina justo antes de un número `m`. Esto corresponde al intervalo
matemático `[n, m)`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe
-   **Salida:** En cada iteración del lazo, imprimir el valor actual del contador de la secuencia.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO secuencia_ascendente
ENTRADA: n, m (enteros)

INICIO
    PARA i DESDE n HASTA m-1 HACER
        ESCRIBIR i
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_07)=
### Ejercicio 1.01.07 - Secuencia Descendente ⭐⭐☆☆☆

Similar al anterior, pero esta vez la secuencia debe ir en orden descendente. Se
parte de un número `n` y se retrocede hasta un número `m`, sin incluirlo. Esto
corresponde al intervalo `(m, n]`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe
-   **Salida:** Imprimir el valor del contador en cada iteración.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO secuencia_descendente
ENTRADA: n, m (enteros)

INICIO
    PARA i DESDE n HASTA m+1 CON PASO -1 HACER
        ESCRIBIR i
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_08)=
### Ejercicio 1.01.08 - Sumatoria ⭐⭐☆☆☆

Calcular la suma de todos los números enteros en un rango cerrado `[n, m]`. Esto
es equivalente a la operación matemática $\sum_{i=n}^{m} i$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable `acumulador` (o `suma`), inicializada en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere desde `n` hasta `m`. En cada
-   **Salida:** Después de que el lazo termine, imprimir el valor final del acumulador.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO sumatoria_rango
ENTRADA: n, m (enteros)
VARIABLES:
    suma (entero)

INICIO
    suma = 0
    PARA i DESDE n HASTA m HACER
        suma = suma + i
    FIN PARA
    ESCRIBIR "La suma es: ", suma
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_09)=
### Ejercicio 1.01.09 - Suma de Cuadrados ⭐⭐☆☆☆

Calcular la suma de los cuadrados de todos los números enteros en un rango
cerrado `[n, m]`. La operación es $\sum_{i=n}^{m} i^2$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita un `acumulador` inicializado en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere de `n` a `m`. En cada iteración, sumar `i * i` al acumulador.
-   **Salida:** Al final, imprimir el valor del `acumulador`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO suma_cuadrados_rango
ENTRADA: n, m (enteros)
VARIABLES:
    suma_cuadrados (entero)

INICIO
    suma_cuadrados = 0
    PARA i DESDE n HASTA m HACER
        suma_cuadrados = suma_cuadrados + (i * i)
    FIN PARA
    ESCRIBIR "La suma de cuadrados es: ", suma_cuadrados
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Estructuras Condicionales

(ej_b1_c01_10)=
### Ejercicio 1.01.10 - Par o Impar ⭐⭐☆☆☆

Este es un ejercicio fundamental de lógica condicional. El programa debe
solicitar un número entero al usuario y determinar si es par (divisible por 2) o
impar.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un único número entero.
-   **Proceso:** La propiedad matemática clave es que un número entero es par si
-   **Condición:** Se utiliza una estructura `if-else`. Si `numero % 2 == 0`, el número es par; de lo contrario, es impar.
-   **Salida:** Imprimir un mensaje claro que indique el resultado, como "El número es par" o "El número es impar".
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO verificar_par_impar
ENTRADA: numero (entero)

INICIO
    LEER numero
    SI numero MOD 2 == 0 ENTONCES
        ESCRIBIR "El número ", numero, " es Par."
    SINO
        ESCRIBIR "El número ", numero, " es Impar."
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_11)=
### Ejercicio 1.01.11 - Signo de un Número ⭐⭐☆☆☆

El programa debe clasificar un número real (de punto flotante) ingresado por el
usuario en una de tres categorías: positivo, negativo o cero.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número que puede tener decimales (tipo `float` o `double`).
-   **Proceso:** Utilizar una estructura de condicionales anidados o `if-else
-   **Condiciones:**
-   **Salida:** Imprimir el mensaje correspondiente a la categoría.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO clasificar_signo
ENTRADA: numero (real)

INICIO
    LEER numero
    SI numero > 0 ENTONCES
        ESCRIBIR "El número es Positivo."
    SINO SI numero < 0 ENTONCES
        ESCRIBIR "El número es Negativo."
    SINO
        ESCRIBIR "El número es Cero."
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Fórmulas Geométricas

(ej_b1_c01_12)=
### Ejercicio 1.01.12 - Área de Triángulo (Base y Altura) ⭐⭐☆☆☆

Calcular el área de un triángulo a partir de las longitudes de su base y su
altura. La fórmula es $A = \frac{1}{2} b \cdot h$.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario dos valores: la base (`b`) y la altura
-   **Proceso:** Aplicar la fórmula matemática directamente. En C, esto se calcula como `(base * altura) / 2.0`.
-   **Salida:** Mostrar el área calculada.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO area_triangulo_base_altura
ENTRADA: base, altura (reales)
VARIABLES:
    area (real)

INICIO
    LEER base
    LEER altura
    area = (base * altura) / 2
    ESCRIBIR "El área del triángulo es: ", area
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_13)=
### Ejercicio 1.01.13 - Área de Triángulo (Fórmula de Herón) ⭐⭐☆☆☆

Calcular el área de un triángulo conociendo únicamente la longitud de sus tres
lados (`a`, `b`, `c`). Para esto se utiliza la fórmula de Herón.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario las longitudes de los tres lados.
-   **Proceso:**
-   **Validación:** Antes de calcular, es importante verificar si los lados
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO area_triangulo_heron
ENTRADA: lado1, lado2, lado3 (reales)
VARIABLES:
    s, area (reales)

INICIO
    LEER lado1, lado2, lado3
    // Opcional: Validar desigualdad triangular
    s = (lado1 + lado2 + lado3) / 2
    area = RAIZ_CUADRADA(s * (s - lado1) * (s - lado2) * (s - lado3))
    ESCRIBIR "El área del triángulo es: ", area
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_14)=
### Ejercicio 1.01.14 - Círculo ⭐⭐☆☆☆

Calcular el área y la circunferencia (perímetro) de un círculo a partir de su
radio.

:::{hint} Lógica y Consideraciones
-   **Constantes:** Se necesita el valor de $\pi$. Se puede definir como una macro con `#define PI 3.14159265` o `const double`.
-   **Entrada:** Solicitar al usuario el valor del radio (`r`).
-   **Proceso:**
-   **Salida:** Mostrar ambos resultados de forma clara.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO circulo_calculos
ENTRADA: radio (real)
CONSTANTES:
    PI = 3.14159

VARIABLES:
    area, circunferencia (reales)

INICIO
    LEER radio
    area = PI * radio * radio
    circunferencia = 2 * PI * radio
    ESCRIBIR "Área: ", area
    ESCRIBIR "Circunferencia: ", circunferencia
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_15)=
### Ejercicio 1.01.15 - Trapecio ⭐⭐☆☆☆

Calcular el área de un trapecio dadas las longitudes de sus dos bases paralelas
y su altura.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario tres valores: la base mayor (`B`), la base
-   **Proceso:** Aplicar la fórmula del área del trapecio: $A = \frac{B+b}{2}
-   **Salida:** Mostrar el área calculada.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO area_trapecio
ENTRADA: base_mayor, base_menor, altura (reales)
VARIABLES:
    area (real)

INICIO
    LEER base_mayor, base_menor, altura
    area = ((base_mayor + base_menor) / 2) * altura
    ESCRIBIR "El área del trapecio es: ", area
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_16)=
### Ejercicio 1.01.16 - Polígono Regular ⭐⭐☆☆☆

Calcular el área de un polígono regular (lados y ángulos iguales) a partir del
número de lados, la longitud de un lado y la apotema.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el número de lados (`n`), la longitud de un lado
-   **Proceso:**
-   **Salida:** Mostrar el área calculada.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO area_poligono_regular
ENTRADA: num_lados (entero), long_lado, apotema (reales)
VARIABLES:
    perimetro, area (reales)

INICIO
    LEER num_lados, long_lado, apotema
    perimetro = num_lados * long_lado
    area = (perimetro * apotema) / 2
    ESCRIBIR "El área del polígono es: ", area
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_17)=
### Ejercicio 1.01.17 - Rectángulo ⭐⭐☆☆☆

Calcular el área y el perímetro de un rectángulo dadas las longitudes de su
largo y su ancho.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el largo (`l`) y el ancho (`w`).
-   **Proceso:**
-   **Salida:** Mostrar ambos resultados.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO rectangulo_calculos
ENTRADA: largo, ancho (reales)
VARIABLES:
    area, perimetro (reales)

INICIO
    LEER largo, ancho
    area = largo * ancho
    perimetro = 2 * (largo + ancho)
    ESCRIBIR "Área: ", area
    ESCRIBIR "Perímetro: ", perimetro
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Conversiones de Unidades

(ej_b1_c01_18)=
### Ejercicio 1.01.18 - Temperaturas ⭐⭐☆☆☆

Crear un programa que pueda convertir temperaturas entre las escalas Celsius,
Fahrenheit y Kelvin.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario el valor de la temperatura y la escala
-   **Proceso:** Aplicar la fórmula de conversión correspondiente:
    -   **Celsius a Fahrenheit**: $F = (C \times 9/5) + 32$
    -   **Fahrenheit a Celsius**: $C = (F - 32) \times 5/9$
    -   **Celsius a Kelvin**: $K = C + 273.15$
-   **Precisión:** Al trabajar con divisiones como 9/5, es importante usar
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo) para celsius a fahrenheit.
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO convertir_c_a_f
ENTRADA: grados_celsius (real)
VARIABLES:
    grados_fahrenheit (real)

INICIO
    LEER grados_celsius
    grados_fahrenheit = (grados_celsius * 9.0 / 5.0) + 32
    ESCRIBIR grados_celsius, "°C son ", grados_fahrenheit, "°F"
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) para celsius a fahrenheit. -->

(ej_b1_c01_19)=
### Ejercicio 1.01.19 - Ángulos a Segundos ⭐⭐☆☆☆

Convertir una medida de ángulo dada en formato sexagesimal (grados, minutos y
segundos) a su valor total equivalente en segundos.

:::{hint} Lógica y Consideraciones
-   **Relaciones:** Recordar que 1 grado = 60 minutos y 1 minuto = 60 segundos.
-   **Entrada:** Solicitar al usuario tres valores enteros: grados, minutos y segundos.
-   **Proceso:** Aplicar la fórmula de conversión: $total = (grados \times 3600)
-   **Salida:** Mostrar el total de segundos.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO angulo_a_segundos
ENTRADA: grados, minutos, segundos (enteros)
VARIABLES:
    total_segundos (entero)

INICIO
    LEER grados, minutos, segundos
    total_segundos = (grados * 3600) + (minutos * 60) + segundos
    ESCRIBIR "El total en segundos es: ", total_segundos
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Control de Flujo Avanzado

(ej_b1_c01_20)=
### Ejercicio 1.01.20 - Tabla de Multiplicar ⭐⭐☆☆☆

El programa debe solicitar un número entero al usuario y mostrar su tabla de
multiplicar, desde el 1 hasta el 10.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero, que será la base de la tabla.
-   **Proceso:** Utilizar un lazo `for` que itere desde 1 hasta 10. En cada
-   **Salida:** Dentro del lazo, imprimir la operación y su resultado en una línea por iteración.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO tabla_de_multiplicar
ENTRADA: numero_base (entero)

INICIO
    LEER numero_base
    PARA i DESDE 1 HASTA 10 HACER
        resultado = numero_base * i
        ESCRIBIR numero_base, " x ", i, " = ", resultado
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_21)=
### Ejercicio 1.01.21 - Patrón de Asteriscos (Triángulo) ⭐⭐☆☆☆

Implementar un programa que pida un número `n` e imprima un triángulo rectángulo
de `n` filas de altura, construido con asteriscos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos aninados.
-   **Salida:** Después de que el lazo interior complete sus iteraciones para la fila actual, imprimir un salto de línea.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO triangulo_asteriscos
ENTRADA: n (entero)

INICIO
    PARA fila DESDE 1 HASTA n HACER
        PARA columna DESDE 1 HASTA fila HACER
            ESCRIBIR "*" SIN SALTO DE LÍNEA
        FIN PARA
        ESCRIBIR SALTO DE LÍNEA
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_22)=
### Ejercicio 1.01.22 - Calculadora Básica ⭐⭐☆☆☆

Crear un programa que funcione como una calculadora simple. Debe solicitar al
usuario dos números y un carácter que represente la operación aritmética a
realizar (+, -, *, /).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer dos números (pueden ser `double` para mayor flexibilidad)
-   **Proceso:** Utilizar una estructura `switch` (o `if-else if`) para seleccionar la operación según el operador ingresado.
-   **Caso Especial:** Manejar la división por cero. Si el operador es `/` y el divisor es 0, informar error al usuario.
-   **Salida:** Mostrar el resultado de la operación o el mensaje de error.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO calculadora
ENTRADA: num1, num2 (reales), operador (caracter)
VARIABLES:
    resultado (real)

INICIO
    LEER num1, operador, num2
    SEGUN operador HACER
        CASO '+': resultado = num1 + num2
        CASO '-': resultado = num1 - num2
        CASO '*': resultado = num1 * num2
        CASO '/': 
            SI num2 != 0 ENTONCES
                resultado = num1 / num2
            SINO
                ESCRIBIR "Error: División por cero."
                TERMINAR
            FIN SI
        CASO CONTRARIO:
            ESCRIBIR "Error: Operador no válido."
            TERMINAR
    FIN SEGUN
    ESCRIBIR "Resultado: ", resultado
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_23)=
### Ejercicio 1.01.23 - Adivina el Número ⭐⭐☆☆☆

Desarrollar un juego simple donde el programa genera un número secreto aleatorio
y el usuario debe adivinarlo. El programa proporciona pistas para guiar al
usuario.

:::{hint} Lógica y Consideraciones
-   **Generación Aleatoria:**
-   **Proceso:** Usar un lazo `do-while` o `while` que se repita hasta que el usuario adivine el número secreto.
-   **Entrada:** Dentro del lazo, solicitar al usuario que ingrese su intento.
-   **Condiciones:** Comparar el intento con el número secreto y dar una pista:
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO adivina_el_numero
VARIABLES:
    numero_secreto, intento_usuario (enteros)

INICIO
    numero_secreto = generar_aleatorio(1, 100)
    HACER
        ESCRIBIR "Adivina el número (1-100):"
        LEER intento_usuario
        SI intento_usuario > numero_secreto ENTONCES
            ESCRIBIR "Muy alto."
        SINO SI intento_usuario < numero_secreto ENTONCES
            ESCRIBIR "Muy bajo."
        FIN SI
    MIENTRAS intento_usuario != numero_secreto

    ESCRIBIR "¡Felicidades! Adivinaste el número."
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_24)=
### Ejercicio 1.01.24 - Serie de Fibonacci (Iterativa) ⭐⭐☆☆☆

Generar y mostrar los primeros `n` términos de la serie de Fibonacci. En esta
serie, cada número es la suma de los dos anteriores, comenzando con 0 y 1.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan al menos tres variables para mantener el estado:
-   **Casos Base:** Los primeros dos términos (para n=0 y n=1) son fijos (0 y 1 respectivamente).
-   **Proceso:**
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO fibonacci_iterativo
ENTRADA: n (entero)
VARIABLES:
    a, b, siguiente, i (enteros)

INICIO
    SI n >= 1 ENTONCES ESCRIBIR 0
    SI n >= 2 ENTONCES ESCRIBIR 1

    a = 0
    b = 1

    PARA i DESDE 3 HASTA n HACER
        siguiente = a + b
        ESCRIBIR siguiente
        a = b
        b = siguiente
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_25)=
### Ejercicio 1.01.25 - Cálculo de Interés Simple ⭐☆☆☆☆

Implementar una función que calcule el monto final y el interés simple ganado a
partir de un capital inicial, una tasa de interés anual y un período de tiempo
en años.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar tres valores: capital (`P`), tasa de interés anual
-   **Proceso:**
-   **Salida:** Mostrar tanto el interés ganado como el monto total acumulado.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO interes_simple
ENTRADA: capital, tasa_anual, anios (reales)
VARIABLES:
    interes_ganado, monto_final (reales)

INICIO
    LEER capital, tasa_anual, anios
    // Asegurarse que la tasa esté en formato decimal
    tasa_decimal = tasa_anual / 100
    interes_ganado = capital * tasa_decimal * anios
    monto_final = capital + interes_ganado

    ESCRIBIR "Interés ganado: ", interes_ganado
    ESCRIBIR "Monto final: ", monto_final
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_26)=
### Ejercicio 1.01.26 - Índice de Masa Corporal (IMC) ⭐⭐☆☆☆

Escribir un programa que calcule el Índice de Masa Corporal (IMC) de una persona
y lo clasifique según las categorías de la OMS.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el peso en kilogramos (kg) y la altura en metros (m).
-   **Proceso:**
-   **Clasificación (ejemplo):**
    -   IMC < 18.5: Bajo peso
    -   18.5 <= IMC < 25: Normal
    -   25 <= IMC < 30: Sobrepeso
    -   IMC >= 30: Obesidad
-   **Salida:** Mostrar el valor del IMC y la categoría de peso correspondiente.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO calcular_imc
ENTRADA: peso_kg, altura_m (reales)
VARIABLES:
    imc (real)

INICIO
    LEER peso_kg, altura_m
    imc = peso_kg / (altura_m * altura_m)
    ESCRIBIR "Su IMC es: ", imc

    SI imc < 18.5 ENTONCES
        ESCRIBIR "Categoría: Bajo peso"
    SINO SI imc < 25 ENTONCES
        ESCRIBIR "Categoría: Normal"
    SINO SI imc < 30 ENTONCES
        ESCRIBIR "Categoría: Sobrepeso"
    SINO
        ESCRIBIR "Categoría: Obesidad"
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_27)=
### Ejercicio 1.01.27 - Días del Mes ⭐⭐☆☆☆

Crear un programa que, dado un mes (como número del 1 al 12) y un año, determine
y muestre cuántos días tiene ese mes. Este ejercicio requiere manejar el caso
especial de febrero en los años bisiestos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer el mes y el año como números enteros.
-   **Proceso:**
-   **Año Bisiesto:** Un año es bisiesto si es divisible por 4, excepto los años
-   **Salida:** Imprimir el número de días.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO dias_del_mes
ENTRADA: mes, anio (enteros)
VARIABLES:
    es_bisiesto (booleano)

INICIO
    LEER mes, anio

    es_bisiesto = (anio MOD 4 == 0 Y anio MOD 100 != 0) O (anio MOD 400 == 0)

    SEGUN mes HACER
        CASO 1, 3, 5, 7, 8, 10, 12:
            ESCRIBIR "31 días"
        CASO 4, 6, 9, 11:
            ESCRIBIR "30 días"
        CASO 2:
            SI es_bisiesto ENTONCES
                ESCRIBIR "29 días"
            SINO
                ESCRIBIR "28 días"
            FIN SI
        CASO CONTRARIO:
            ESCRIBIR "Mes no válido."
    FIN SEGUN
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_28)=
### Ejercicio 1.01.28 - Máximo de Tres Números ⭐⭐☆☆☆

El objetivo es encontrar el valor más grande entre tres números enteros
proporcionados por el usuario. Este ejercicio se centra en el uso de
condicionales anidados o operadores lógicos para realizar comparaciones
múltiples.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer tres números enteros distintos (`a`, `b`, `c`).
-   **Proceso:** Se puede resolver de varias maneras:
        -   `SI (a >= b Y a >= c) ENTONCES a es el máximo.`
        -   `SINO SI (b >= a Y b >= c) ENTONCES b es el máximo.`
        -   `SINO c es el máximo.`
-   **Salida:** Imprimir el número que resultó ser el mayor.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO maximo_de_tres
ENTRADA: a, b, c (enteros)
VARIABLES:
    maximo (entero)

INICIO
    LEER a, b, c
    maximo = a
    SI b > maximo ENTONCES
        maximo = b
    FIN SI
    SI c > maximo ENTONCES
        maximo = c
    FIN SI
    ESCRIBIR "El número más grande es: ", maximo
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_29)=
### Ejercicio 1.01.29 - Clasificación de Triángulo ⭐⭐☆☆☆

Dados los largos de tres lados, el programa debe determinar si pueden formar un
triángulo válido y, en caso afirmativo, clasificarlo como equilátero (todos los
lados iguales), isósceles (dos lados iguales) o escaleno (todos los lados
diferentes).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer las longitudes de los tres lados (`a`, `b`, `c`).
-   **Validación (Desigualdad Triangular):** Antes de clasificar, es crucial
-   **Clasificación:**
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO clasificar_triangulo
ENTRADA: a, b, c (reales)

INICIO
    LEER a, b, c
    SI (a+b > c) Y (a+c > b) Y (b+c > a) ENTONCES
        SI a == b Y b == c ENTONCES
            ESCRIBIR "Es un triángulo Equilátero."
        SINO SI a == b O b == c O a == c ENTONCES
            ESCRIBIR "Es un triángulo Isósceles."
        SINO
            ESCRIBIR "Es un triángulo Escaleno."
        FIN SI
    SINO
        ESCRIBIR "Los lados no forman un triángulo válido."
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_30)=
### Ejercicio 1.01.30 - Desglose de Billetes ⭐⭐☆☆☆

Dado un monto de dinero entero, el programa debe calcular la cantidad mínima de
billetes de distintas denominaciones para representar dicho monto.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un monto entero.
-   **Denominaciones:** Definir las denominaciones de billetes disponibles en un arreglo o mediante divisiones enteras sucesivas.
-   **Proceso:** Utilizar divisiones y el operador módulo para calcular cuántos
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO desglose_billetes
ENTRADA: monto (entero)
VARIABLES:
    cantidad_billetes (entero)

INICIO
    LEER monto
    denominaciones = [1000, 500, 200, 100, 50, 20, 10]

    PARA cada d EN denominaciones HACER
        cantidad_billetes = monto / d
        SI cantidad_billetes > 0 ENTONCES
            ESCRIBIR cantidad_billetes, " billete(s) de ", d
        FIN SI
        monto = monto MOD d
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_31)=
### Ejercicio 1.01.31 - Piedra, Papel o Tijera ⭐⭐☆☆☆

Implementar el clásico juego de Piedra, Papel o Tijera para que un usuario
juegue una partida contra la computadora.

:::{hint} Lógica y Consideraciones
-   **Entrada del Usuario:** Pedir al usuario que elija una opción (ej.
-   **Elección de la Computadora:** Generar un número aleatorio entre 1 y 3 para representar la jugada de la máquina.
-   **Reglas del Juego:**
    -   Piedra vence a Tijera.
    -   Tijera vence a Papel.
    -   Papel vence a Piedra.
-   **Proceso:** Comparar la elección del usuario con la de la computadora
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO piedra_papel_tijera
VARIABLES:
    eleccion_usuario, eleccion_pc (entero)

INICIO
    ESCRIBIR "Elige: 1-Piedra, 2-Papel, 3-Tijera"
    LEER eleccion_usuario
    eleccion_pc = generar_aleatorio(1, 3)

    SI eleccion_usuario == eleccion_pc ENTONCES
        ESCRIBIR "Empate."
    SINO SI (eleccion_usuario == 1 Y eleccion_pc == 3) O \
            (eleccion_usuario == 2 Y eleccion_pc == 1) O \
            (eleccion_usuario == 3 Y eleccion_pc == 2) ENTONCES
        ESCRIBIR "¡Ganaste!"
    SINO
        ESCRIBIR "Perdiste."
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_32)=
### Ejercicio 1.01.32 - Patrón de Pirámide ⭐⭐☆☆☆

Implementar un programa que pida un número `n` e imprima un triángulo de `n`
filas de altura, construido con asteriscos, centrado como una pirámide.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos aninados.
        -   El primer lazo interior imprime los espacios en blanco necesarios
        -   El segundo lazo interior imprime los asteriscos. En la fila `i`, se imprimen `2 * i - 1` asteriscos.
-   **Salida:** Después de cada fila, imprimir un salto de línea.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO piramide_asteriscos
ENTRADA: n (entero)

INICIO
    PARA fila DESDE 1 HASTA n HACER
        // Imprimir espacios
        PARA espacio DESDE 1 HASTA n - fila HACER
            ESCRIBIR " " SIN SALTO DE LÍNEA
        FIN PARA

        // Imprimir asteriscos
        PARA asterisco DESDE 1 HASTA 2 * fila - 1 HACER
            ESCRIBIR "*" SIN SALTO DE LÍNEA
        FIN PARA

        ESCRIBIR SALTO DE LÍNEA
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_33)=
### Ejercicio 1.01.33 - Validación de Contraseña Simple ⭐☆☆☆☆

Crear un programa que solicite una contraseña al usuario y no le permita
continuar hasta que ingrese la contraseña correcta. Este ejercicio practica el
uso de lazos `do-while` y la comparación de cadenas.

:::{hint} Lógica y Consideraciones
-   **Contraseña Secreta:** Definir una contraseña correcta como una cadena
-   **Entrada:** Dentro de un lazo, solicitar al usuario que ingrese la contraseña por consola.
-   **Proceso:** Usar un lazo `do-while` es ideal aquí, ya que la solicitud debe
-   **Comparación de Cadenas:** En C, las cadenas no se pueden comparar con `==`; se debe utilizar la función `strcmp()`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO validar_contrasena
CONSTANTES:
    CLAVE_SECRETA = "password123"
VARIABLES:
    intento (cadena)

INICIO
    HACER
        ESCRIBIR "Ingrese la contraseña:"
        LEER intento
    MIENTRAS intento != CLAVE_SECRETA

    ESCRIBIR "Acceso concedido."
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_34)=
### Ejercicio 1.01.34 - Cajero Automático (Menú) ⭐⭐☆☆☆

Simular la interfaz de un menú de cajero automático. El programa debe mostrar
una lista de opciones y ejecutar una acción simple según la elección del
usuario, repitiendo el proceso hasta que el usuario decida salir.

:::{hint} Lógica y Consideraciones
-   **Estado:** Mantener una variable para el saldo de la cuenta.
-   **Proceso:** Usar un lazo `do-while` que se ejecute mientras la opción
-   **Menú:** Dentro del lazo, imprimir las opciones (1. Consultar, 2.
-   **Entrada:** Leer la opción del usuario.
-   **Selección:** Usar una estructura `switch` para manejar las diferentes
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO cajero_automatico
VARIABLES:
    saldo (real)
    opcion, monto (entero)

INICIO
    saldo = 1000.0
    HACER
        ESCRIBIR "1. Consultar Saldo"
        ESCRIBIR "2. Depositar"
        ESCRIBIR "3. Retirar"
        ESCRIBIR "4. Salir"
        LEER opcion

        SEGUN opcion HACER
            CASO 1: ESCRIBIR "Su saldo es: ", saldo
            CASO 2: 
                ESCRIBIR "Ingrese monto a depositar:"
                LEER monto
                saldo = saldo + monto
            CASO 3:
                ESCRIBIR "Ingrese monto a retirar:"
                LEER monto
                SI monto <= saldo ENTONCES
                    saldo = saldo - monto
                SINO
                    ESCRIBIR "Saldo insuficiente."
                FIN SI
        FIN SEGUN
    MIENTRAS opcion != 4
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_35)=
### Ejercicio 1.01.35 - Patrón de Rombo ⭐⭐☆☆☆

Implementar un programa que pida un número impar `n` e imprima un rombo de
asteriscos de `n` filas de altura.

:::{hint} Lógica y Consideraciones
-   **Estructura:** Un rombo puede verse como una pirámide seguida de una pirámide invertida.
-   **Entrada:** Leer un entero impar `n`.
-   **Proceso:**
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO rombo_asteriscos
ENTRADA: n (entero impar)

INICIO
    // Parte superior (pirámide)
    PARA fila DESDE 1 HASTA (n/2) + 1 HACER
        // Imprimir espacios y asteriscos como en el ejercicio de la pirámide
    FIN PARA

    // Parte inferior (pirámide invertida)
    PARA fila DESDE n/2 HASTA 1 CON PASO -1 HACER
        // Imprimir espacios y asteriscos de forma similar pero con el lazo decreciente
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_36)=
### Ejercicio 1.01.36 - Promedio de N Números ⭐⭐☆☆☆

Escribir un programa que sea flexible en la cantidad de números a promediar.
Primero debe preguntar al usuario cuántos números va a ingresar y luego calcular
el promedio de esa cantidad de números.

:::{hint} Lógica y Consideraciones
-   **Entrada Inicial:** Leer la cantidad de números a promediar ($N$).
-   **Variables:** Se necesita un `acumulador` para la suma y un contador.
-   **Proceso:**
-   **Salida:** Mostrar el promedio calculado.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO promedio_n_numeros
VARIABLES:
    cantidad, i (enteros)
    numero, suma, promedio (reales)

INICIO
    ESCRIBIR "¿Cuántos números desea promediar?"
    LEER cantidad
    suma = 0

    PARA i DESDE 1 HASTA cantidad HACER
        ESCRIBIR "Ingrese el número ", i, ":"
        LEER numero
        suma = suma + numero
    FIN PARA

    SI cantidad > 0 ENTONCES
        promedio = suma / cantidad
        ESCRIBIR "El promedio es: ", promedio
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_37)=
### Ejercicio 1.01.37 - Contador de Dígitos ⭐⭐⭐☆☆

Crear una función que reciba un número entero y devuelva la cantidad de dígitos
que lo componen.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** La forma más simple es usar la división entera por 10
-   **Caso Especial:** Si el número de entrada es 0, tiene 1 dígito. El lazo
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO contar_digitos
ENTRADA: numero (entero)
VARIABLES:
    contador (entero)

INICIO
    SI numero == 0 ENTONCES
        RETORNAR 1
    FIN SI

    contador = 0
    // Manejar números negativos
    numero_abs = VALOR_ABSOLUTO(numero)

    MIENTRAS numero_abs > 0 HACER
        numero_abs = numero_abs / 10
        contador = contador + 1
    FIN MIENTRAS

    RETORNAR contador
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_38)=
### Ejercicio 1.01.38 - Invertir un Número Entero ⭐⭐☆☆☆

Implementar una función que tome un número entero y devuelva otro número con los
dígitos en orden inverso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** Se puede construir el número invertido dígito por dígito.
-   **Salida:** Devolver el número `invertido`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO invertir_numero
ENTRADA: numero (entero)
VARIABLES:
    invertido, digito (enteros)

INICIO
    invertido = 0
    MIENTRAS numero != 0 HACER
        digito = numero MOD 10
        invertido = (invertido * 10) + digito
        numero = numero / 10
    FIN MIENTRAS
    RETORNAR invertido
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_39)=
### Ejercicio 1.01.39 - Potencia con Lazos ⭐⭐☆☆☆

Escribir una función que calcule `base^exponente` sin usar la función `pow()` de
la biblioteca `math.h`. Debe funcionar para exponentes enteros no negativos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Una base y un exponente (entero no negativo).
-   **Variables:** Se necesita una variable `resultado` inicializada en 1.
-   **Proceso:**
-   **Salida:** Devolver el `resultado`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO potencia_iterativa
ENTRADA: base (real), exponente (entero)
VARIABLES:
    resultado (real)

INICIO
    resultado = 1.0
    PARA i DESDE 1 HASTA exponente HACER
        resultado = resultado * base
    FIN PARA
    RETORNAR resultado
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_40)=
### Ejercicio 1.01.40 - Menú de Conversiones ⭐⭐☆☆☆

Crear un programa robusto que presente al usuario un menú con varias opciones de
conversión de unidades (ej. Celsius a Fahrenheit, Metros a Pies, Kilogramos a
Libras). El programa debe repetir el menú hasta que el usuario elija la opción
de salir.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Similar al ejercicio del cajero automático. Usar un lazo
-   **Modularidad:** Es una buena práctica crear una función separada para cada
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO menu_conversiones
VARIABLES:
    opcion (entero)

INICIO
    HACER
        ESCRIBIR "1. Celsius a Fahrenheit"
        ESCRIBIR "2. Metros a Pies"
        ESCRIBIR "3. Salir"
        LEER opcion

        SEGUN opcion HACER
            CASO 1: llamar funcion_convertir_c_a_f()
            CASO 2: llamar funcion_convertir_m_a_pies()
        FIN SEGUN
    MIENTRAS opcion != 3
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_41)=
### Ejercicio 1.01.41 - Validación de Fecha ⭐⭐☆☆☆

Crear una función que valide si una combinación de día, mes y año corresponde a
una fecha real en el calendario gregoriano.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Tres enteros: `dia`, `mes`, `anio`.
-   **Proceso:** Realizar una serie de verificaciones en orden lógico:
-   **Salida:** Devolver un valor booleano (`true` si es válida, `false` si no).
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

FUNCION es_fecha_valida(dia, mes, anio)
VARIABLES:
    dias_en_mes (entero)

INICIO
    SI anio < 1 O mes < 1 O mes > 12 O dia < 1 O dia > 31 ENTONCES
        RETORNAR FALSO
    FIN SI

    // Lógica para dias_en_mes (similar al ejercicio 1.17)
    ...

    SI dia > dias_en_mes ENTONCES
        RETORNAR FALSO
    FIN SI

    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_42)=
### Ejercicio 1.01.42 - Dibujar un Cuadrado Hueco ⭐⭐☆☆☆

Pedir al usuario un número `n` y dibujar el contorno de un cuadrado de `n x n`
utilizando asteriscos. El interior del cuadrado debe estar vacío.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n`.
-   **Proceso:** Usar lazos aninados. El lazo exterior para las filas y el lazo interior para las columnas.
-   **Condición:** Dentro del lazo interior, se debe decidir si imprimir un asterisco en los bordes o un espacio en el interior.
    -   Es la primera o la última fila (`fila == 1` o `fila == n`).
    -   Es la primera o la última columna (`columna == 1` o `columna == n`).
-   En cualquier otro caso, se imprime un espacio.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO cuadrado_hueco
ENTRADA: n (entero)

INICIO
    PARA fila DESDE 1 HASTA n HACER
        PARA columna DESDE 1 HASTA n HACER
            SI fila == 1 O fila == n O columna == 1 O columna == n ENTONCES
                ESCRIBIR "*" SIN SALTO DE LÍNEA
            SINO
                ESCRIBIR " " SIN SALTO DE LÍNEA
            FIN SI
        FIN PARA
        ESCRIBIR SALTO DE LÍNEA
    FIN PARA
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_43)=
### Ejercicio 1.01.43 - Suma Separada de Pares e Impares ⭐⭐☆☆☆

Dado un rango de números `[n, m]`, el programa debe calcular la suma de todos
los números pares y la suma de todos los números impares de forma independiente
y mostrar ambos resultados.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan dos acumuladores: `suma_pares` y `suma_impares`, ambos inicializados en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:**
-   **Salida:** Mostrar los valores finales de ambas sumas.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO suma_pares_impares_rango
ENTRADA: n, m (enteros)
VARIABLES:
    suma_pares, suma_impares (enteros)

INICIO
    suma_pares = 0
    suma_impares = 0
    PARA i DESDE n HASTA m HACER
        SI i MOD 2 == 0 ENTONCES
            suma_pares = suma_pares + i
        SINO
            suma_impares = suma_impares + i
        FIN SI
    FIN PARA
    ESCRIBIR "Suma de pares: ", suma_pares
    ESCRIBIR "Suma de impares: ", suma_impares
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_44)=
### Ejercicio 1.01.44 - Número de la Suerte ⭐⭐☆☆☆

Un número de la suerte es un entero con una cantidad par de dígitos, donde la
suma de los dígitos de la primera mitad es igual a la suma de los dígitos de la
segunda mitad. El programa debe verificar si un número dado es de la suerte.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero.
-   **Proceso:**
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

ALGORITMO numero_de_la_suerte
ENTRADA: numero (entero)
VARIABLES:
    total_digitos, mitad_digitos, i (enteros)
    primera_mitad, segunda_mitad (enteros)
    suma1, suma2 (enteros)

INICIO
    LEER numero
    total_digitos = contar_digitos(numero)

    SI total_digitos MOD 2 != 0 ENTONCES
        ESCRIBIR "No es un número de la suerte (dígitos impares)."
        TERMINAR
    FIN SI

    mitad_digitos = total_digitos / 2
    divisor = potencia(10, mitad_digitos)

    primera_mitad = numero / divisor
    segunda_mitad = numero MOD divisor

    suma1 = sumar_digitos(primera_mitad)
    suma2 = sumar_digitos(segunda_mitad)

    SI suma1 == suma2 ENTONCES
        ESCRIBIR "Es un número de la suerte."
    SINO
        ESCRIBIR "No es un número de la suerte."
    FIN SI
FIN

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c01_45)=
## Ejercicio 1.01.45 - Hola Mundo Personalizado ⭐☆☆☆☆

Escribí un programa que solicite tu nombre y te salude personalmente.

**Ejemplo de ejecución:**

```
Ingresá tu nombre: Juan
¡Hola, Juan! Bienvenido a la programación en C.
```

**Orientación:**
- Usá `printf()` para mostrar mensajes
- Usá `scanf()` para leer el nombre (máximo 50 caracteres)
- Recordá incluir `<stdio.h>`

---

(ej_b1_c01_46)=
## Ejercicio 1.01.46 - Calculadora Simple ⭐⭐☆☆☆

Escribí un programa que lea dos números enteros y muestre su suma, resta,
producto y división.

**Ejemplo de ejecución:**

```
Primer número: 10
Segundo número: 3
Suma: 13
Resta: 7
Producto: 30
División: 3.33
```

**Orientación:**
- Declará variables para los dos números
- Para la división con decimales, convertí al menos uno de los operandos a
  `double`
- Usá `%.2f` para mostrar dos decimales

---

(ej_b1_c01_47)=
## Ejercicio 1.01.47 - Conversor de Temperatura ⭐⭐☆☆☆

Creá un programa que convierta temperatura de Celsius a Fahrenheit y Kelvin.

**Fórmulas:**
- Fahrenheit = Celsius × 9/5 + 32
- Kelvin = Celsius + 273.15

**Orientación:**
- Usá `double` para almacenar temperaturas
- Aplicá las fórmulas de conversión
- Mostrá resultados con dos decimales

---

(ej_b1_c01_48)=
## Ejercicio 1.01.48 - Área y Perímetro ⭐⭐☆☆☆

Escribí un programa que calcule el área y perímetro de un rectángulo dados su
ancho y alto.

**Orientación:**
- Área = ancho × alto
- Perímetro = 2 × (ancho + alto)
- Usá `double` para las medidas
- Verificá que ancho y alto sean positivos

---

(ej_b1_c01_49)=
## Ejercicio 1.01.49 - Promedio de Tres Números ⭐⭐☆☆☆

Calculá el promedio de tres números decimales ingresados por el usuario.

**Orientación:**
- Leé tres números con `scanf("%lf", ...)`
- Promedio = (a + b + c) / 3.0
- Mostrá el resultado con dos decimales

---

(ej_b1_c01_50)=
## Ejercicio 1.01.50 - Intercambio de Variables ⭐⭐☆☆☆

Leé dos números enteros y mostralos intercambiados (sin usar una tercera
variable).

**Ejemplo:**

```
Ingresá a: 5
Ingresá b: 10
Después del intercambio:
a = 10
b = 5
```

**Orientación:**
- Usá operaciones aritméticas para intercambiar:
  - `a = a + b;`
  - `b = a - b;`
  - `a = a - b;`
- Verificá el resultado imprimiendo antes y después del intercambio

---

(ej_b1_c01_51)=
## Ejercicio 1.01.51 - Conversión de Unidades ⭐⭐☆☆☆

Convertí una distancia en metros a kilómetros, centímetros y milímetros.

**Orientación:**
- 1 metro = 0.001 km = 100 cm = 1000 mm
- Usá constantes para los factores de conversión
- Mostrá todas las conversiones

---

(ej_b1_c01_52)=
## Ejercicio 1.01.52 - Cálculo de IMC ⭐⭐⭐☆☆

Calculá el Índice de Masa Corporal (IMC) dados peso (kg) y altura (m).

**Fórmula:** IMC = peso / (altura × altura)

**Orientación:**
- Verificá que altura sea mayor que 0
- Mostrá el IMC con dos decimales
- Opcionalmente, mostrá la categoría (bajo peso, normal, sobrepeso)

---

(ej_b1_c01_53)=
## Ejercicio 1.01.53 - Cantidad de Billetes ⭐⭐⭐☆☆

Dado un monto en pesos, calculá cuántos billetes de cada denominación (1000,
500, 200, 100, 50, 20, 10) se necesitan.

**Ejemplo:**

```
Monto: 1780
1 billete(s) de 1000
1 billete(s) de 500
1 billete(s) de 200
0 billete(s) de 100
1 billete(s) de 50
1 billete(s) de 20
1 billete(s) de 10
```

**Orientación:**
- Usá división entera y módulo
- Empezá por el billete más grande
- Restá el valor usado del monto

---

(ej_b1_c01_54)=
## Ejercicio 1.01.54 - Segundos a Horas, Minutos y Segundos ⭐⭐⭐☆☆

Convertí una cantidad de segundos a formato HH:MM:SS.

**Ejemplo:**

```
Segundos: 3665
Resultado: 1:01:05
```

**Orientación:**
- Horas = segundos / 3600
- Minutos = (segundos % 3600) / 60
- Segundos restantes = segundos % 60
- Mostrá con formato `printf("%d:%02d:%02d", h, m, s)`

---

(ej_b1_c01_55)=
## Ejercicio 1.01.55 - Dígitos de un Número ⭐⭐⭐☆☆

Leé un número de tres dígitos y mostrá cada dígito por separado.

**Ejemplo:**

```
Número: 457
Centenas: 4
Decenas: 5
Unidades: 7
```

**Orientación:**
- Centenas = numero / 100
- Decenas = (numero / 10) % 10
- Unidades = numero % 10

---

(ej_b1_c01_56)=
## Ejercicio 1.01.56 - Precio con Descuento ⭐⭐⭐☆☆

Calculá el precio final de un producto aplicando un descuento porcentual.

**Ejemplo:**

```
Precio original: 1000
Descuento (%): 15
Precio final: 850.00
```

**Orientación:**
- Descuento = precio × (porcentaje / 100.0)
- Precio final = precio - descuento
- Mostrá ambos valores

---

(ej_b1_c01_57)=
## Ejercicio 1.01.57 - División Entera y Resto ⭐⭐☆☆☆

Leé dos números enteros `dividendo` y `divisor`. Mostrá el cociente entero, el
resto de la división (módulo) y el resultado de la división real (con decimales).

**Orientación:**
- Verificá que el divisor sea distinto de cero antes de realizar la operación
- Usá `/` para la división entera y `%` para el resto
- Convertí uno de los operandos a `double` mediante `(double)` para obtener el cociente con decimales

---

(ej_b1_c01_58)=
## Ejercicio 1.01.58 - Conversión de Base ⭐⭐⭐⭐☆

Convertí un número decimal a binario, octal y hexadecimal.

**Orientación:**
- Usá especificadores de formato: `%d`, `%o`, `%x`
- Mostrá el número en las cuatro bases
- Opcionalmente, implementá conversión manual con divisiones sucesivas

---

(ej_b1_c01_59)=
## Ejercicio 1.01.59 - Área de Triángulo (Herón) ⭐⭐⭐⭐☆

Calculá el área de un triángulo usando la fórmula de Herón dados los tres lados.

**Fórmula:** 
- s = (a + b + c) / 2
- área = √(s × (s-a) × (s-b) × (s-c))

**Orientación:**
- Verificá que los lados formen un triángulo válido (a + b > c, etc.)
- Usá `sqrt()` de `<math.h>`
- Compilá con `-lm` para enlazar la biblioteca matemática

---

(ej_b1_c01_60)=
## Ejercicio 1.01.60 - Ecuación Cuadrática ⭐⭐⭐⭐☆

Resolvé una ecuación cuadrática ax² + bx + c = 0, mostrando las raíces reales si
existen.

**Orientación:**
- Calculá el discriminante: Δ = b² - 4ac
- Si Δ < 0: no hay raíces reales
- Si Δ = 0: una raíz: x = -b / (2a)
- Si Δ > 0: dos raíces: x = (-b ± √Δ) / (2a)
- Usá `sqrt()` de `<math.h>`

---

(ej_b1_c01_61)=
## Ejercicio 1.01.61 - Interés Compuesto ⭐⭐⭐⭐☆

Calculá el monto final de una inversión con interés compuesto.

**Fórmula:** A = P × (1 + r/n)^(n×t)

Donde:
- P = capital inicial
- r = tasa de interés anual (decimal)
- n = veces que se capitaliza por año
- t = tiempo en años

**Orientación:**
- Usá `pow()` de `<math.h>`
- Mostrá el monto inicial, final y la ganancia
- Compilá con `-lm`

---

(ej_b1_c01_62)=
## Ejercicio 1.01.62 - Conversión RGB a Hexadecimal ⭐⭐⭐⭐☆

Convertí un color RGB (rojo, verde, azul) a su representación hexadecimal.

**Ejemplo:**

```
Rojo (0-255): 255
Verde (0-255): 127
Azul (0-255): 80
Hexadecimal: #FF7F50
```

**Orientación:**
- Verificá que cada valor esté en rango 0-255
- Usá `printf("%02X", valor)` para formato hexadecimal
- Combiná los tres valores en formato #RRGGBB

---

(ej_b1_c01_63)=
## Ejercicio 1.01.63 - Cálculo de Potencia (sin pow) ⭐⭐⭐⭐⭐

Calculá base^exponente usando solo multiplicaciones (exponente entero positivo).

**Orientación:**
- Leé base (double) y exponente (int positivo)
- Usá un lazo para multiplicar base por sí misma exponente veces
- Considerá el caso especial cuando exponente = 0 (resultado = 1)
- **Spoiler:** Este ejercicio requiere lazos, pero podés usar multiplicaciones
  repetidas en línea

---

(ej_b1_c01_64)=
## Ejercicio 1.01.64 - Calculadora Científica Básica ⭐⭐⭐⭐⭐

Creá una calculadora que realice operaciones avanzadas: potencia, raíz cuadrada,
seno, coseno, tangente, logaritmo.

**Orientación:**
- Mostrá un menú de opciones
- Leé la operación deseada y los operandos necesarios
- Usá funciones de `<math.h>`: `pow()`, `sqrt()`, `sin()`, `cos()`, `tan()`,
  `log()`
- Recordá que funciones trigonométricas usan radianes
- Verificá casos especiales (raíz de negativo, log de 0 o negativo, etc.)
- Compilá con `-lm`

---

## Notas Finales

:::{tip} Consejos Generales

- **Validación:** Siempre verificá entradas inválidas (divisiones por cero,
  valores fuera de rango)
- **Formato:** Usá `printf()` con especificadores apropiados (`%d`, `%f`, `%c`,
  etc.)
- **Constantes:** Definí valores fijos con `#define` o `const`
- **Comentarios:** Documentá qué hace cada sección del código
- **Testing:** Probá con diferentes entradas, incluyendo casos extremos

:::
<!-- {tip} Consejos Generales -->

:::{note} Compilación con Matemáticas

Para ejercicios que usan `<math.h>`, compilá con:
``` bash
gcc -Wall -Wextra -std=c99 programa.c -o programa -lm
```
<!-- bash -->
El flag `-lm` enlaza la biblioteca matemática.

:::
<!-- {note} Compilación con Matemáticas -->

Estas consignas cubren los conceptos fundamentales del Apunte 1: variables,
tipos de datos, operadores aritméticos, relacionales, lógicos, entrada/salida, y uso básico de
bibliotecas estándar.

