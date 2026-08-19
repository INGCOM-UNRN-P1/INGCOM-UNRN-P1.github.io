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

### Cuestiones de Estilo Aplicables
- **Resolución mediante funciones:** Según la [Regla
  0x2009h](../../reglas/2_funciones.md#0x2009h), la lógica principal que
  resuelve cada enunciado debe estar contenida en una función, incluso si no se
  especifica de forma explícitamente.
- **Separación de entrada/salida:** De acuerdo con la [Regla
  0x2002h](../../reglas/2_funciones.md#0x2002h), las funciones no deben contener
  `printf` o `scanf`, a menos que su propósito explícito sea interactuar con el
  usuario.
- **Uso de llaves:** Toda estructura de control debe utilizar llaves (`{}`)
  según la [Regla 0x1001h](../../reglas/1_control.md#0x1001h).
- **Lazos:** Según la [Regla 0x1003h](../../reglas/1_control.md#0x1003h), se
  debe preferir el uso de lazos `for` para iteraciones con rango o contador
  definido, y `while` para lazos controlados por condiciones lógicas.

---

## Primeros Pasos y Salida Básica
(ejercicio_1_1)=
### Ejercicio 1.1 - Cuenta regresiva ⭐⭐☆☆☆


Este ejercicio consiste en implementar un programa que realice una cuenta
regresiva desde un número entero positivo $N$ hasta $1$, para finalmente imprimir
un mensaje de "¡Lanzamiento!". El objetivo es practicar el uso de lazos y la
gestión de tiempos de ejecución simples.

Para que la cuenta no sea instantánea y se pueda percibir en tiempo real, se
debe introducir una pausa de 1 segundo entre cada número impreso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** El programa debe solicitar al usuario un número entero positivo
-   **Proceso:** Se debe utilizar un lazo que itere desde $N$ hacia abajo, hasta
-   **Pausa:** Dentro del lazo, después de imprimir cada número, el programa
-   **Salida:** Tras finalizar el lazo, se debe imprimir el mensaje final

-   **[*plus ultra*]:** Validar que el número inicial N sea estrictamente positivo antes de comenzar la cuenta.
-   **[*plus ultra*]:** Permitir al usuario configurar el tiempo de pausa entre cada número.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_2)=
### Ejercicio 1.2 - ¡Hola mundo! ⭐⭐☆☆☆


El "Hola, mundo!" es el primer paso tradicional en el aprendizaje de un nuevo
lenguaje de programación. El objetivo es escribir el programa más simple posible
que produzca una salida visible en la pantalla, confirmando que el compilador y
el entorno de desarrollo están configurados y funcionando correctamente.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Este programa no requiere ninguna entrada del usuario.
-   **Proceso:** Se utiliza una función de la biblioteca estándar para enviar
-   **Salida:** El programa debe imprimir la cadena de texto "Hola, mundo!"

-   **[*plus ultra*]:** Imprimir un marco decorativo alrededor del saludo usando caracteres ASCII estándar.
-   **[*plus ultra*]:** Modularizar la impresión dentro de una función con una firma clara.

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
(ejercicio_1_3)=
### Ejercicio 1.3 - Saludador ⭐⭐☆☆☆


Este ejercicio amplía el "Hola, mundo!" para que el programa interactúe con el
usuario. Debe solicitarle su nombre y luego mostrar un saludo personalizado que
lo incluya. Sirve para practicar la lectura de datos desde la entrada estándar.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable para almacenar el nombre del
-   **Entrada:** El programa debe primero mostrar un mensaje pidiendo al usuario
-   **Funciones de Lectura:** Se puede usar `scanf()` para leer la entrada, pero
-   **Salida:** Finalmente, el programa debe imprimir el saludo personalizado,

-   **[*plus ultra*]:** Validar que el nombre ingresado no sea una cadena vacía ni contenga solo espacios.
-   **[*plus ultra*]:** Personalizar el saludo según la hora del día ingresada por el usuario.

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
(ejercicio_1_4)=
### Ejercicio 1.4 - Pares en un rango ⭐⭐⭐☆☆


El programa debe ser capaz de identificar y mostrar todos los números pares que
existen dentro de un intervalo cerrado `[n, m]`, donde los límites `n` y `m` son
proporcionados por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se deben leer dos números enteros, `n` (inicio del rango) y `m`
-   **Proceso:** Se utiliza un lazo `for` que recorra cada número `i` desde `n`
-   **Condición de Paridad:** Dentro del lazo, para cada número `i`, se debe
-   **Salida:** Si la condición de paridad se cumple, el número `i` se imprime

-   **[*plus ultra*]:** Permitir que el usuario ingrese el intervalo en cualquier orden (si n > m, intercambiar automáticamente los límites).
-   **[*plus ultra*]:** Contar la cantidad total de pares encontrados y mostrar el resultado al finalizar.

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
(ejercicio_1_5)=
### Ejercicio 1.5 - Primeros N Impares ⭐⭐☆☆☆


Este ejercicio consiste en generar una secuencia de números impares, comenzando
desde 1, hasta alcanzar un total de $N$ términos, donde $N$ es un número
proporcionado por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se debe leer un número entero $N$ que representa la cantidad de
-   **Proceso:** Se puede abordar de dos maneras:
-   **Salida:** Se imprime la secuencia de los primeros $N$ números impares.

-   **[*plus ultra*]:** Validar que N sea un entero mayor a cero; de lo contrario, volver a solicitarlo.
-   **[*plus ultra*]:** Mostrar la suma acumulada de los primeros N impares y verificar que sea igual a N².

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
(ejercicio_1_6)=
### Ejercicio 1.6 - Secuencia Ascendente ⭐⭐☆☆☆


El objetivo es mostrar una secuencia de números enteros que comienza en un
número `n` y termina justo antes de un número `m`. Esto corresponde al intervalo
matemático `[n, m)`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe
-   **Salida:** En cada iteración del lazo, imprimir el valor actual del

-   **[*plus ultra*]:** Manejar el caso donde n >= m informando al usuario que el rango es vacío.
-   **[*plus ultra*]:** Permitir al usuario ingresar un paso de incremento distinto de 1.

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
(ejercicio_1_7)=
### Ejercicio 1.7 - Secuencia Descendente ⭐⭐☆☆☆


Similar al anterior, pero esta vez la secuencia debe ir en orden descendente. Se
parte de un número `n` y se retrocede hasta un número `m`, sin incluirlo. Esto
corresponde al intervalo `(m, n]`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe
-   **Salida:** Imprimir el valor del contador en cada iteración.

-   **[*plus ultra*]:** Validar que n > m para que la secuencia descendente tenga al menos un elemento.
-   **[*plus ultra*]:** Permitir al usuario ingresar un paso de decremento personalizado.

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
(ejercicio_1_8)=
### Ejercicio 1.8 - Sumatoria ⭐⭐☆☆☆


Calcular la suma de todos los números enteros en un rango cerrado `[n, m]`. Esto
es equivalente a la operación matemática $\sum_{i=n}^{m} i$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable `acumulador` (o `suma`),
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere desde `n` hasta `m`. En cada
-   **Salida:** Después de que el lazo termine, imprimir el valor final del

-   **[*plus ultra*]:** Validar que n <= m y calcular la sumatoria tanto mediante un lazo como con la fórmula de Gauss para comparar resultados.
-   **[*plus ultra*]:** Usar el tipo long long para prevenir desbordamientos en rangos grandes.

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
(ejercicio_1_9)=
### Ejercicio 1.9 - Suma de Cuadrados ⭐⭐☆☆☆


Calcular la suma de los cuadrados de todos los números enteros en un rango
cerrado `[n, m]`. La operación es $\sum_{i=n}^{m} i^2$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita un `acumulador` inicializado en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere de `n` a `m`. En cada iteración,
-   **Salida:** Al final, imprimir el valor del `acumulador`.

-   **[*plus ultra*]:** Usar tipos enteros amplios como long long para soportar sumas de cuadrados elevadas.
-   **[*plus ultra*]:** Comparar el resultado del lazo con la fórmula matemática n*(n+1)*(2n+1)/6.

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
(ejercicio_1_10)=
### Ejercicio 1.10 - Par o Impar ⭐⭐☆☆☆


Este es un ejercicio fundamental de lógica condicional. El programa debe
solicitar un número entero al usuario y determinar si es par (divisible por 2) o
impar.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un único número entero.
-   **Proceso:** La propiedad matemática clave es que un número entero es par si
-   **Condición:** Se utiliza una estructura `if-else`. Si `numero % 2 == 0`, el
-   **Salida:** Imprimir un mensaje claro que indique el resultado, como "El

-   **[*plus ultra*]:** Validar que el valor ingresado sea un número entero válido comprobando el retorno de scanf.
-   **[*plus ultra*]:** Encapsular la lógica en una función bool es_par(int n) que no realice operaciones de E/S.

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
(ejercicio_1_11)=
### Ejercicio 1.11 - Signo de un Número ⭐⭐☆☆☆


El programa debe clasificar un número real (de punto flotante) ingresado por el
usuario en una de tres categorías: positivo, negativo o cero.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número que puede tener decimales (tipo `float` o
-   **Proceso:** Utilizar una estructura de condicionales anidados o `if-else
-   **Condiciones:**
-   **Salida:** Imprimir el mensaje correspondiente a la categoría.

-   **[*plus ultra*]:** Encapsular la clasificación en una función que retorne 1 (positivo), -1 (negativo) o 0 (cero).
-   **[*plus ultra*]:** Manejar valores muy cercanos a cero dentro de un margen de tolerancia (epsilon) si se usan reales.

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
(ejercicio_1_12)=
### Ejercicio 1.12 - Área de Triángulo (Base y Altura) ⭐⭐☆☆☆


Calcular el área de un triángulo a partir de las longitudes de su base y su
altura. La fórmula es $A = \frac{1}{2} b \cdot h$.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario dos valores: la base (`b`) y la altura
-   **Proceso:** Aplicar la fórmula matemática directamente. En C, esto se
-   **Salida:** Mostrar el área calculada.

-   **[*plus ultra*]:** Validar que tanto la base como la altura sean valores estrictamente mayores a cero.
-   **[*plus ultra*]:** Modularizar el cálculo en una función pura double calcular_area_triangulo(double base, double altura).

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
(ejercicio_1_13)=
### Ejercicio 1.13 - Área de Triángulo (Fórmula de Herón) ⭐⭐☆☆☆


Calcular el área de un triángulo conociendo únicamente la longitud de sus tres
lados (`a`, `b`, `c`). Para esto se utiliza la fórmula de Herón.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario las longitudes de los tres lados.
-   **Proceso:**
-   **Validación:** Antes de calcular, es importante verificar si los lados

-   **[*plus ultra*]:** Validar la desigualdad triangular (la suma de dos lados cualesquiera debe superar al tercero) antes del cálculo.
-   **[*plus ultra*]:** Retornar un valor de error (-1.0) si los lados no pueden formar un triángulo geométrico válido.

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
(ejercicio_1_14)=
### Ejercicio 1.14 - Círculo ⭐⭐☆☆☆


Calcular el área y la circunferencia (perímetro) de un círculo a partir de su
radio.

:::{hint} Lógica y Consideraciones
-   **Constantes:** Se necesita el valor de $\pi$. Se puede definir como una
-   **Entrada:** Solicitar al usuario el valor del radio (`r`).
-   **Proceso:**
-   **Salida:** Mostrar ambos resultados de forma clara.

-   **[*plus ultra*]:** Validar que el radio sea positivo y definir PI como una constante con precisión de double.
-   **[*plus ultra*]:** Calcular también el área del sector circular para un ángulo ingresado por el usuario.

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
(ejercicio_1_15)=
### Ejercicio 1.15 - Trapecio ⭐⭐☆☆☆


Calcular el área de un trapecio dadas las longitudes de sus dos bases paralelas
y su altura.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario tres valores: la base mayor (`B`), la base
-   **Proceso:** Aplicar la fórmula del área del trapecio: $A = \frac{B+b}{2}
-   **Salida:** Mostrar el área calculada.

-   **[*plus ultra*]:** Validar que ambas bases y la altura sean estrictamente positivas y que la base mayor sea mayor que la menor.
-   **[*plus ultra*]:** Modularizar la operación en una función independiente.

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
(ejercicio_1_16)=
### Ejercicio 1.16 - Polígono Regular ⭐⭐☆☆☆


Calcular el área de un polígono regular (lados y ángulos iguales) a partir del
número de lados, la longitud de un lado y la apotema.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el número de lados (`n`), la longitud de un lado
-   **Proceso:**
-   **Salida:** Mostrar el área calculada.

-   **[*plus ultra*]:** Validar que el número de lados sea al menos 3 y que las longitudes sean positivas.
-   **[*plus ultra*]:** Calcular también el ángulo interior de cada vértice del polígono regular.

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
(ejercicio_1_17)=
### Ejercicio 1.17 - Rectángulo ⭐⭐☆☆☆


Calcular el área y el perímetro de un rectángulo dadas las longitudes de su
largo y su ancho.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el largo (`l`) y el ancho (`w`).
-   **Proceso:**
-   **Salida:** Mostrar ambos resultados.

-   **[*plus ultra*]:** Validar que ancho y alto sean positivos y determinar si la figura es un caso especial (cuadrado).
-   **[*plus ultra*]:** Modularizar las funciones para calcular área y perímetro por separado.

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
(ejercicio_1_18)=
### Ejercicio 1.18 - Temperaturas ⭐⭐☆☆☆


Crear un programa que pueda convertir temperaturas entre las escalas Celsius,
Fahrenheit y Kelvin.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario el valor de la temperatura y la escala
-   **Proceso:** Aplicar la fórmula de conversión correspondiente:
    -   **Celsius a Fahrenheit**: $F = (C \times 9/5) + 32$
    -   **Fahrenheit a Celsius**: $C = (F - 32) \times 5/9$
    -   **Celsius a Kelvin**: $K = C + 273.15$
-   **Precisión:** Al trabajar con divisiones como 9/5, es importante usar

-   **[*plus ultra*]:** Validar que la temperatura en Celsius no sea inferior al cero absoluto (-273.15 °C).
-   **[*plus ultra*]:** Presentar una tabla comparativa de temperaturas en pasos de 10 grados dentro de un rango.

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
(ejercicio_1_19)=
### Ejercicio 1.19 - Ángulos a Segundos ⭐⭐☆☆☆


Convertir una medida de ángulo dada en formato sexagesimal (grados, minutos y
segundos) a su valor total equivalente en segundos.

:::{hint} Lógica y Consideraciones
-   **Relaciones:** Recordar que 1 grado = 60 minutos y 1 minuto = 60 segundos.
-   **Entrada:** Solicitar al usuario tres valores enteros: grados, minutos y
-   **Proceso:** Aplicar la fórmula de conversión: $total = (grados \times 3600)
-   **Salida:** Mostrar el total de segundos.

-   **[*plus ultra*]:** Validar que los minutos y segundos estén en el rango [0, 59].
-   **[*plus ultra*]:** Implementar la operación inversa: convertir segundos totales a grados, minutos y segundos.

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
(ejercicio_1_20)=
### Ejercicio 1.20 - Tabla de Multiplicar ⭐⭐☆☆☆


El programa debe solicitar un número entero al usuario y mostrar su tabla de
multiplicar, desde el 1 hasta el 10.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero, que será la base de la tabla.
-   **Proceso:** Utilizar un lazo `for` que itere desde 1 hasta 10. En cada
-   **Salida:** Dentro del lazo, imprimir la operación y su resultado en un

-   **[*plus ultra*]:** Formatear la tabla con columnas alineadas usando especificadores de ancho en printf.
-   **[*plus ultra*]:** Permitir al usuario elegir hasta qué múltiplo generar la tabla (por defecto 10).

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
(ejercicio_1_21)=
### Ejercicio 1.21 - Patrón de Asteriscos (Triángulo) ⭐⭐☆☆☆


Implementar un programa que pida un número `n` e imprima un triángulo rectángulo
de `n` filas de altura, construido con asteriscos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos aninados.
-   **Salida:** Después de que el lazo interior complete sus iteraciones para

-   **[*plus ultra*]:** Parametrizar el carácter de dibujo permitiendo al usuario elegir el símbolo.
-   **[*plus ultra*]:** Validar que la altura sea un entero positivo mayor o igual a 1.

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
(ejercicio_1_22)=
### Ejercicio 1.22 - Calculadora Básica ⭐⭐☆☆☆


Crear un programa que funcione como una calculadora simple. Debe solicitar al
usuario dos números y un carácter que represente la operación aritmética a
realizar (+, -, *, /).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer dos números (pueden ser `double` para mayor flexibilidad)
-   **Proceso:** Utilizar una estructura `switch` (o `if-else if`) para
-   **Caso Especial:** Manejar la división por cero. Si el operador es `/` y el
-   **Salida:** Mostrar el resultado de la operación o el mensaje de error.

-   **[*plus ultra*]:** Manejar adecuadamente el error de división por cero mostrando un mensaje descriptivo.
-   **[*plus ultra*]:** Permitir la ejecución continua de operaciones dentro de un lazo hasta que el usuario elija salir.

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
(ejercicio_1_23)=
### Ejercicio 1.23 - Adivina el Número ⭐⭐☆☆☆


Desarrollar un juego simple donde el programa genera un número secreto aleatorio
y el usuario debe adivinarlo. El programa proporciona pistas para guiar al
usuario.

:::{hint} Lógica y Consideraciones
-   **Generación Aleatoria:**
-   **Proceso:** Usar un lazo `do-while` o `while` que se repita hasta que el
-   **Entrada:** Dentro del lazo, solicitar al usuario que ingrese su intento.
-   **Condiciones:** Comparar el intento con el número secreto y dar una pista:

-   **[*plus ultra*]:** Limitar el número máximo de intentos disponibles y mostrar un mensaje de fin de juego si se agotan.
-   **[*plus ultra*]:** Llevar un registro del puntaje basado en la rapidez con la que se adivina el número.

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
(ejercicio_1_24)=
### Ejercicio 1.24 - Serie de Fibonacci (Iterativa) ⭐⭐☆☆☆


Generar y mostrar los primeros `n` términos de la serie de Fibonacci. En esta
serie, cada número es la suma de los dos anteriores, comenzando con 0 y 1.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan al menos tres variables para mantener el estado:
-   **Casos Base:** Los primeros dos términos (para n=0 y n=1) son fijos (0 y
-   **Proceso:**

-   **[*plus ultra*]:** Usar tipos enteros sin signo o long long para calcular términos más altos sin desbordamiento.
-   **[*plus ultra*]:** Calcular el cociente entre términos consecutivos para observar la convergencia al número áureo.

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
(ejercicio_1_25)=
### Ejercicio 1.25 - Cálculo de Interés Simple ⭐☆☆☆☆


Implementar una función que calcule el monto final y el interés simple ganado a
partir de un capital inicial, una tasa de interés anual y un período de tiempo
en años.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar tres valores: capital (`P`), tasa de interés anual
-   **Proceso:**
-   **Salida:** Mostrar tanto el interés ganado como el monto total acumulado.

-   **[*plus ultra*]:** Validar que capital, tasa y tiempo sean valores numéricos positivos.
-   **[*plus ultra*]:** Mostrar el desglose anual del interés acumulado en cada período.

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
(ejercicio_1_26)=
### Ejercicio 1.26 - Índice de Masa Corporal (IMC) ⭐⭐☆☆☆


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

-   **[*plus ultra*]:** Validar que peso y altura sean estrictamente positivos.
-   **[*plus ultra*]:** Modularizar la clasificación en una función independiente que retorne la categoría de IMC.

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
(ejercicio_1_27)=
### Ejercicio 1.27 - Días del Mes ⭐⭐☆☆☆


Crear un programa que, dado un mes (como número del 1 al 12) y un año, determine
y muestre cuántos días tiene ese mes. Este ejercicio requiere manejar el caso
especial de febrero en los años bisiestos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer el mes y el año como números enteros.
-   **Proceso:**
-   **Año Bisiesto:** Un año es bisiesto si es divisible por 4, excepto los años
-   **Salida:** Imprimir el número de días.

-   **[*plus ultra*]:** Verificar si el año es bisiesto para determinar correctamente los días del mes de febrero.
-   **[*plus ultra*]:** Validar que el número de mes esté estrictamente comprendido entre 1 y 12.

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
(ejercicio_1_28)=
### Ejercicio 1.28 - Máximo de Tres Números ⭐⭐☆☆☆


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

-   **[*plus ultra*]:** Encapsular la comparación en una función int maximo_de_tres(int a, int b, int c).
-   **[*plus ultra*]:** Extender el programa para identificar si los tres números son iguales entre sí.

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
(ejercicio_1_29)=
### Ejercicio 1.29 - Clasificación de Triángulo ⭐⭐☆☆☆


Dados los largos de tres lados, el programa debe determinar si pueden formar un
triángulo válido y, en caso afirmativo, clasificarlo como equilátero (todos los
lados iguales), isósceles (dos lados iguales) o escaleno (todos los lados
diferentes).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer las longitudes de los tres lados (`a`, `b`, `c`).
-   **Validación (Desigualdad Triangular):** Antes de clasificar, es crucial
-   **Clasificación:**

-   **[*plus ultra*]:** Validar la desigualdad triangular antes de clasificar el triángulo.
-   **[*plus ultra*]:** Determinar además si el triángulo es rectángulo aplicando el teorema de Pitágoras.

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
(ejercicio_1_30)=
### Ejercicio 1.30 - Desglose de Billetes ⭐⭐☆☆☆


Dado un monto de dinero entero, el programa debe calcular la cantidad mínima de
billetes de distintas denominaciones para representar dicho monto.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un monto entero.
-   **Denominaciones:** Definir las denominaciones de billetes disponibles en un
-   **Proceso:** Utilizar divisiones y el operador módulo para calcular cuántos

-   **[*plus ultra*]:** Validar que el monto sea positivo y múltiplo de la denominación mínima.
-   **[*plus ultra*]:** Permitir configurar las denominaciones disponibles mediante constantes.

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
(ejercicio_1_31)=
### Ejercicio 1.31 - Piedra, Papel o Tijera ⭐⭐☆☆☆


Implementar el clásico juego de Piedra, Papel o Tijera para que un usuario
juegue una partida contra la computadora.

:::{hint} Lógica y Consideraciones
-   **Entrada del Usuario:** Pedir al usuario que elija una opción (ej.
-   **Elección de la Computadora:** Generar un número aleatorio entre 1 y 3 para
-   **Reglas del Juego:**
    -   Piedra vence a Tijera.
    -   Tijera vence a Papel.
    -   Papel vence a Piedra.
-   **Proceso:** Comparar la elección del usuario con la de la computadora

-   **[*plus ultra*]:** Validar que la opción elegida por el usuario sea válida (1, 2 o 3).
-   **[*plus ultra*]:** Llevar un marcador de victorias, derrotas y empates a lo largo de múltiples rondas.

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
(ejercicio_1_32)=
### Ejercicio 1.32 - Patrón de Pirámide ⭐⭐☆☆☆


Implementar un programa que pida un número `n` e imprima un triángulo de `n`
filas de altura, construido con asteriscos, centrado como una pirámide.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos aninados.
        -   El primer lazo interior imprime los espacios en blanco necesarios
        -   El segundo lazo interior imprime los asteriscos. En la fila `i`, se
-   **Salida:** Después de cada fila, imprimir un salto de línea.

-   **[*plus ultra*]:** Validar que la altura ingresada esté en un rango razonable (ej. entre 1 y 25).
-   **[*plus ultra*]:** Permitir al usuario elegir entre pirámide sólida o hueca.

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
(ejercicio_1_33)=
### Ejercicio 1.33 - Validación de Contraseña Simple ⭐☆☆☆☆


Crear un programa que solicite una contraseña al usuario y no le permita
continuar hasta que ingrese la contraseña correcta. Este ejercicio practica el
uso de lazos `do-while` y la comparación de cadenas.

:::{hint} Lógica y Consideraciones
-   **Contraseña Secreta:** Definir una contraseña correcta como una cadena
-   **Entrada:** Dentro de un lazo, solicitar al usuario que ingrese la
-   **Proceso:** Usar un lazo `do-while` es ideal aquí, ya que la solicitud debe
-   **Comparación de Cadenas:** En C, las cadenas no se pueden comparar con

-   **[*plus ultra*]:** Limitar la cantidad de intentos fallidos antes de bloquear temporalmente el acceso.
-   **[*plus ultra*]:** Ocultar los caracteres ingresados si la terminal lo permite.

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
(ejercicio_1_34)=
### Ejercicio 1.34 - Cajero Automático (Menú) ⭐⭐☆☆☆


Simular la interfaz de un menú de cajero automático. El programa debe mostrar
una lista de opciones y ejecutar una acción simple según la elección del
usuario, repitiendo el proceso hasta que el usuario decida salir.

:::{hint} Lógica y Consideraciones
-   **Estado:** Mantener una variable para el saldo de la cuenta.
-   **Proceso:** Usar un lazo `do-while` que se ejecute mientras la opción
-   **Menú:** Dentro del lazo, imprimir las opciones (1. Consultar, 2.
-   **Entrada:** Leer la opción del usuario.
-   **Selección:** Usar una estructura `switch` para manejar las diferentes

-   **[*plus ultra*]:** Mantener el saldo actualizado entre operaciones y validar que no se extraiga más dinero del disponible.
-   **[*plus ultra*]:** Implementar la opción de consultar los últimos movimientos o transferencias.

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
(ejercicio_1_35)=
### Ejercicio 1.35 - Patrón de Rombo ⭐⭐☆☆☆


Implementar un programa que pida un número impar `n` e imprima un rombo de
asteriscos de `n` filas de altura.

:::{hint} Lógica y Consideraciones
-   **Estructura:** Un rombo puede verse como una pirámide seguida de una
-   **Entrada:** Leer un entero impar `n`.
-   **Proceso:**

-   **[*plus ultra*]:** Validar que el tamaño del rombo sea un número impar positivo.
-   **[*plus ultra*]:** Generar el rombo con bordes decorativos personalizados.

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
(ejercicio_1_36)=
### Ejercicio 1.36 - Promedio de N Números ⭐⭐☆☆☆


Escribir un programa que sea flexible en la cantidad de números a promediar.
Primero debe preguntar al usuario cuántos números va a ingresar y luego calcular
el promedio de esa cantidad de números.

:::{hint} Lógica y Consideraciones
-   **Entrada Inicial:** Leer la cantidad de números a promediar ($N$).
-   **Variables:** Se necesita un `acumulador` para la suma y un contador.
-   **Proceso:**
-   **Salida:** Mostrar el promedio calculado.

-   **[*plus ultra*]:** Validar que la cantidad N de datos sea mayor a cero para evitar división por cero.
-   **[*plus ultra*]:** Calcular en el mismo recorrido el valor máximo y mínimo del conjunto.

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
(ejercicio_1_37)=
### Ejercicio 1.37 - Contador de Dígitos ⭐⭐⭐☆☆


Crear una función que reciba un número entero y devuelva la cantidad de dígitos
que lo componen.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** La forma más simple es usar la división entera por 10
-   **Caso Especial:** Si el número de entrada es 0, tiene 1 dígito. El lazo

-   **[*plus ultra*]:** Manejar correctamente números negativos y el caso especial del número 0.
-   **[*plus ultra*]:** Modularizar el conteo en una función recursiva o iterativa pura.

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
(ejercicio_1_38)=
### Ejercicio 1.38 - Invertir un Número Entero ⭐⭐☆☆☆


Implementar una función que tome un número entero y devuelva otro número con los
dígitos en orden inverso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** Se puede construir el número invertido dígito por dígito.
-   **Salida:** Devolver el número `invertido`.

-   **[*plus ultra*]:** Manejar correctamente números que terminan en cero y valores negativos.
-   **[*plus ultra*]:** Detectar si el número original es capicúa (palíndromo numérico).

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
(ejercicio_1_39)=
### Ejercicio 1.39 - Potencia con Lazos ⭐⭐☆☆☆


Escribir una función que calcule `base^exponente` sin usar la función `pow()` de
la biblioteca `math.h`. Debe funcionar para exponentes enteros no negativos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Una base y un exponente (entero no negativo).
-   **Variables:** Se necesita una variable `resultado` inicializada en 1.
-   **Proceso:**
-   **Salida:** Devolver el `resultado`.

-   **[*plus ultra*]:** Validar que el exponente sea un entero no negativo o manejar exponentes negativos retornando un double.
-   **[*plus ultra*]:** Comparar el rendimiento contra la función pow() de math.h.

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
(ejercicio_1_40)=
### Ejercicio 1.40 - Menú de Conversiones ⭐⭐☆☆☆


Crear un programa robusto que presente al usuario un menú con varias opciones de
conversión de unidades (ej. Celsius a Fahrenheit, Metros a Pies, Kilogramos a
Libras). El programa debe repetir el menú hasta que el usuario elija la opción
de salir.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Similar al ejercicio del cajero automático. Usar un lazo
-   **Modularidad:** Es una buena práctica crear una función separada para cada

-   **[*plus ultra*]:** Implementar un lazo interactivo para que el usuario pueda realizar múltiples conversiones consecutivas.
-   **[*plus ultra*]:** Validar rigurosamente las opciones del menú con un caso default.

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
(ejercicio_1_41)=
### Ejercicio 1.41 - Validación de Fecha ⭐⭐☆☆☆


Crear una función que valide si una combinación de día, mes y año corresponde a
una fecha real en el calendario gregoriano.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Tres enteros: `dia`, `mes`, `anio`.
-   **Proceso:** Realizar una serie de verificaciones en orden lógico:
-   **Salida:** Devolver un valor booleano (`true` si es válida, `false` si no).

-   **[*plus ultra*]:** Validar años bisiestos para febrero y el número correcto de días según cada mes (1-31).
-   **[*plus ultra*]:** Calcular el día de la semana correspondiente a la fecha ingresada.

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
(ejercicio_1_42)=
### Ejercicio 1.42 - Dibujar un Cuadrado Hueco ⭐⭐☆☆☆


Pedir al usuario un número `n` y dibujar el contorno de un cuadrado de `n x n`
utilizando asteriscos. El interior del cuadrado debe estar vacío.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n`.
-   **Proceso:** Usar lazos aninados. El lazo exterior para las filas y el
-   **Condición:** Dentro del lazo interior, se debe decidir si imprimir un
    -   Es la primera o la última fila (`fila == 1` o `fila == n`).
    -   Es la primera o la última columna (`columna == 1` o `columna == n`).
-   En cualquier otro caso, se imprime un espacio.

-   **[*plus ultra*]:** Validar que el lado del cuadrado sea mayor o igual a 2.
-   **[*plus ultra*]:** Permitir elegir un carácter diferente para el borde y para el relleno.

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
(ejercicio_1_43)=
### Ejercicio 1.43 - Suma Separada de Pares e Impares ⭐⭐☆☆☆


Dado un rango de números `[n, m]`, el programa debe calcular la suma de todos
los números pares y la suma de todos los números impares de forma independiente
y mostrar ambos resultados.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan dos acumuladores: `suma_pares` y `suma_impares`,
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:**
-   **Salida:** Mostrar los valores finales de ambas sumas.

-   **[*plus ultra*]:** Permitir definir los límites del rango de manera dinámica mediante entrada por consola.
-   **[*plus ultra*]:** Calcular también la cantidad de pares e impares encontrados en el intervalo.

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
(ejercicio_1_44)=
### Ejercicio 1.44 - Número de la Suerte ⭐⭐☆☆☆


Un número de la suerte es un entero con una cantidad par de dígitos, donde la
suma de los dígitos de la primera mitad es igual a la suma de los dígitos de la
segunda mitad. El programa debe verificar si un número dado es de la suerte.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero.
-   **Proceso:**

-   **[*plus ultra*]:** Validar que la fecha contenga valores válidos de día, mes y año.
-   **[*plus ultra*]:** Modularizar la suma sucesiva de dígitos en una función auxiliar pura.

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
(ejercicio_1_45)=
## Ejercicio 1.45 - Hola Mundo Personalizado ⭐☆☆☆☆

Escribí un programa que solicite tu nombre y te salude personalmente.

**Ejemplo de ejecución:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el nombre ingresado contenga caracteres legibles y no esté vacío.
-   **[*plus ultra*]:** Dar formato especial a la salida con marcos en la terminal.

:::
<!-- {hint} Lógica y Consideraciones -->

```
Ingresá tu nombre: Juan
¡Hola, Juan! Bienvenido a la programación en C.
```

**Orientación:**
- Usá `printf()` para mostrar mensajes
- Usá `scanf()` para leer el nombre (máximo 50 caracteres)
- Recordá incluir `<stdio.h>`

---
(ejercicio_1_46)=
## Ejercicio 1.46 - Calculadora Simple ⭐⭐☆☆☆

Escribí un programa que lea dos números enteros y muestre su suma, resta,
producto y división.

**Ejemplo de ejecución:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el segundo número no sea cero antes de calcular el cociente.
-   **[*plus ultra*]:** Modularizar cada operación aritmética en su propia función.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_47)=
## Ejercicio 1.47 - Conversor de Temperatura ⭐⭐☆☆☆

Creá un programa que convierta temperatura de Celsius a Fahrenheit y Kelvin.

**Fórmulas:**
- Fahrenheit = Celsius × 9/5 + 32
- Kelvin = Celsius + 273.15

**Orientación:**
- Usá `double` para almacenar temperaturas
- Aplicá las fórmulas de conversión
- Mostrá resultados con dos decimales


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que las temperaturas no estén por debajo del cero absoluto.
-   **[*plus ultra*]:** Modularizar las fórmulas en funciones con contratos y pruebas unitarias.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_48)=
## Ejercicio 1.48 - Área y Perímetro ⭐⭐☆☆☆

Escribí un programa que calcule el área y perímetro de un rectángulo dados su
ancho y alto.

**Orientación:**
- Área = ancho × alto
- Perímetro = 2 × (ancho + alto)
- Usá `double` para las medidas
- Verificá que ancho y alto sean positivos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que ancho y alto sean positivos antes de calcular.
-   **[*plus ultra*]:** Modularizar el cálculo en funciones independientes para área y perímetro.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_49)=
## Ejercicio 1.49 - Promedio de Tres Números ⭐⭐☆☆☆

Calculá el promedio de tres números decimales ingresados por el usuario.

**Orientación:**
- Leé tres números con `scanf("%lf", ...)`
- Promedio = (a + b + c) / 3.0
- Mostrá el resultado con dos decimales


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar los datos ingresados verificando el retorno de scanf.
-   **[*plus ultra*]:** Modularizar el promedio en una función double calcular_promedio(double a, double b, double c).

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_50)=
## Ejercicio 1.50 - Intercambio de Variables ⭐⭐☆☆☆

Leé dos números enteros y mostralos intercambiados (sin usar una tercera
variable).

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar una función que reciba dos variables y muestre sus valores antes y después de operar.
-   **[*plus ultra*]:** Verificar que el intercambio funcione correctamente para números negativos y cero.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_51)=
## Ejercicio 1.51 - Conversión de Unidades ⭐⭐☆☆☆

Convertí una distancia en metros a kilómetros, centímetros y milímetros.

**Orientación:**
- 1 metro = 0.001 km = 100 cm = 1000 mm
- Usá constantes para los factores de conversión
- Mostrá todas las conversiones


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Modularizar cada conversión en funciones puras independientes.
-   **[*plus ultra*]:** Formatear las unidades en una tabla comparativa alineada.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_52)=
## Ejercicio 1.52 - Cálculo de IMC ⭐⭐⭐☆☆

Calculá el Índice de Masa Corporal (IMC) dados peso (kg) y altura (m).

**Fórmula:** IMC = peso / (altura × altura)

**Orientación:**
- Verificá que altura sea mayor que 0
- Mostrá el IMC con dos decimales
- Opcionalmente, mostrá la categoría (bajo peso, normal, sobrepeso)


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que peso y altura sean mayores a cero y clasificar según la tabla oficial de la OMS.
-   **[*plus ultra*]:** Modularizar el cálculo en una función libre de operaciones de E/S.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_53)=
## Ejercicio 1.53 - Cantidad de Billetes ⭐⭐⭐☆☆

Dado un monto en pesos, calculá cuántos billetes de cada denominación (1000,
500, 200, 100, 50, 20, 10) se necesitan.

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el monto sea un número entero no negativo.
-   **[*plus ultra*]:** Permitir configurar las denominaciones de billetes en orden decreciente.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_54)=
## Ejercicio 1.54 - Segundos a Horas, Minutos y Segundos ⭐⭐⭐☆☆

Convertí una cantidad de segundos a formato HH:MM:SS.

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que la cantidad de segundos no sea negativa.
-   **[*plus ultra*]:** Permitir incluir días si los segundos superan las 24 horas.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_55)=
## Ejercicio 1.55 - Dígitos de un Número ⭐⭐⭐☆☆

Leé un número de tres dígitos y mostrá cada dígito por separado.

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el número ingresado esté exactamente en el rango [100, 999].
-   **[*plus ultra*]:** Extender el algoritmo para números de cantidad variable de dígitos usando un lazo.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_56)=
## Ejercicio 1.56 - Precio con Descuento ⭐⭐⭐☆☆

Calculá el precio final de un producto aplicando un descuento porcentual.

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el porcentaje de descuento esté en el rango [0, 100].
-   **[*plus ultra*]:** Mostrar el desglose del ahorro total obtenido junto con el precio final.

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_57)=
## Ejercicio 1.57 - División Entera y Resto ⭐⭐☆☆☆

Leé dos números enteros `dividendo` y `divisor`. Mostrá el cociente entero, el
resto de la división (módulo) y el resultado de la división real (con decimales).

**Orientación:**
- Verificá que el divisor sea distinto de cero antes de realizar la operación
- Usá `/` para la división entera y `%` para el resto
- Convertí uno de los operandos a `double` mediante `(double)` para obtener el cociente con decimales

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el divisor sea distinto de cero informando un mensaje de error descriptivo por consola.
-   **[*plus ultra*]:** Modularizar el cálculo en una función pura que retorne el cociente y verifique la validez matemática.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_58)=
## Ejercicio 1.58 - Conversión de Base ⭐⭐⭐⭐☆

Convertí un número decimal a binario, octal y hexadecimal.

**Orientación:**
- Usá especificadores de formato: `%d`, `%o`, `%x`
- Mostrá el número en las cuatro bases
- Opcionalmente, implementá conversión manual con divisiones sucesivas


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el número decimal ingresado sea no negativo.
-   **[*plus ultra*]:** Modularizar la conversión a binario mediante divisiones sucesivas por 2 en un lazo.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_59)=
## Ejercicio 1.59 - Área de Triángulo (Herón) ⭐⭐⭐⭐☆

Calculá el área de un triángulo usando la fórmula de Herón dados los tres lados.

**Fórmula:** 
- s = (a + b + c) / 2
- área = √(s × (s-a) × (s-b) × (s-c))

**Orientación:**
- Verificá que los lados formen un triángulo válido (a + b > c, etc.)
- Usá `sqrt()` de `<math.h>`
- Compilá con `-lm` para enlazar la biblioteca matemática


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar la desigualdad triangular antes de aplicar la raíz cuadrada.
-   **[*plus ultra*]:** Modularizar el cálculo del semiperímetro y del área en funciones separadas.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_60)=
## Ejercicio 1.60 - Ecuación Cuadrática ⭐⭐⭐⭐☆

Resolvé una ecuación cuadrática ax² + bx + c = 0, mostrando las raíces reales si
existen.

**Orientación:**
- Calculá el discriminante: Δ = b² - 4ac
- Si Δ < 0: no hay raíces reales
- Si Δ = 0: una raíz: x = -b / (2a)
- Si Δ > 0: dos raíces: x = (-b ± √Δ) / (2a)
- Usá `sqrt()` de `<math.h>`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Manejar los tres casos del discriminante (dos raíces reales, una raíz doble, raíces complejas).
-   **[*plus ultra*]:** Validar que el coeficiente principal a no sea cero (en cuyo caso es una ecuación lineal).

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_61)=
## Ejercicio 1.61 - Interés Compuesto ⭐⭐⭐⭐☆

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


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que el capital, tasa de interés, frecuencia y tiempo sean positivos.
-   **[*plus ultra*]:** Mostrar una tabla período por período con la evolución del capital acumulado.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_62)=
## Ejercicio 1.62 - Conversión RGB a Hexadecimal ⭐⭐⭐⭐☆

Convertí un color RGB (rojo, verde, azul) a su representación hexadecimal.

**Ejemplo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que cada componente RGB esté en el rango [0, 255].
-   **[*plus ultra*]:** Formatear la salida con ceros a la izquierda para asegurar siempre 6 dígitos hexadecimales (#RRGGBB).

:::
<!-- {hint} Lógica y Consideraciones -->

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
(ejercicio_1_63)=
## Ejercicio 1.63 - Cálculo de Potencia (sin pow) ⭐⭐⭐⭐⭐

Calculá base^exponente usando solo multiplicaciones (exponente entero positivo).

**Orientación:**
- Leé base (double) y exponente (int positivo)
- Usá un lazo para multiplicar base por sí misma exponente veces
- Considerá el caso especial cuando exponente = 0 (resultado = 1)
- **Spoiler:** Este ejercicio requiere lazos, pero podés usar multiplicaciones
  repetidas en línea


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Manejar el caso especial de exponente 0 (resultado 1) y base 0 con exponente positivo.
-   **[*plus ultra*]:** Extender la función para aceptar exponentes negativos retornando un double.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_1_64)=
## Ejercicio 1.64 - Calculadora Científica Básica ⭐⭐⭐⭐⭐

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


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar operaciones inválidas como división por cero, logaritmo de no positivos o raíz de negativos.
-   **[*plus ultra*]:** Implementar un menú con lazo que permita realizar cálculos consecutivos hasta salir.

:::
<!-- {hint} Lógica y Consideraciones -->

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

