---
title: Ejercicios Básicos y Secuencias
short_title: 1. Básicos
---

## Acerca de

Estos ejercicios están diseñados para afianzar los conceptos más fundamentales
de la programación en C. A través de ellos, practicarás el uso de variables, la
entrada y salida por consola, y la implementación de estructuras de control
básicas como lazos y condicionales para resolver problemas simples y generar
secuencias numéricas.

### Consideraciones Generales

1.  **Función Principal**: La lógica principal que resuelve cada enunciado debe
    estar contenida en una función, incluso si no se especifica explícitamente.
2.  **Estilo**: Todo el código debe adherirse a la
    [guía de estilo](../apunte/0_estilo.md) de la cátedra.
3.  **Entrada y Salida**: Separá la lógica de tu programa de las operaciones de
    entrada/salida. Las funciones principales no deben interactuar directamente
    con el usuario, a menos que ese sea su propósito específico.


## 1.1: Cuenta regresiva

### Descripción
Este ejercicio consiste en implementar un programa que realice una cuenta regresiva desde un número entero positivo `N` hasta 1, para finalmente imprimir un mensaje de "¡Lanzamiento!". El objetivo es practicar el uso de lazos (bucles) y la gestión de tiempos de ejecución simples.

Para que la cuenta no sea instantánea y se pueda percibir en tiempo real, se debe introducir una pausa de 1 segundo entre cada número impreso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** El programa debe solicitar al usuario un número entero positivo `N` que servirá como punto de inicio de la cuenta regresiva.
-   **Proceso:** Se debe utilizar un lazo que itere desde `N` hacia abajo, hasta llegar a 1. En cada iteración, el programa imprimirá el número actual.
-   **Pausa:** Dentro del lazo, después de imprimir cada número, el programa debe detener su ejecución durante 1 segundo. En C, esto se puede lograr con la función `sleep(1)`, que se encuentra en la cabecera `<unistd.h>` en sistemas POSIX (Linux, macOS).
-   **Salida:** Tras finalizar el lazo, se debe imprimir el mensaje final "¡Lanzamiento!".
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::

## 1.2: ¡Hola mundo!

### Descripción
El "Hola, mundo!" es el primer paso tradicional en el aprendizaje de un nuevo lenguaje de programación. El objetivo es escribir el programa más simple posible que produzca una salida visible en la pantalla, confirmando que el compilador y el entorno de desarrollo están configurados y funcionando correctamente.
:::{hint} Lógica y Consideraciones
-   **Entrada:** Este programa no requiere ninguna entrada del usuario.
-   **Proceso:** Se utiliza una función de la biblioteca estándar para enviar texto a la salida estándar (la consola). En C, la función más común para esto es `printf()`.
-   **Salida:** El programa debe imprimir la cadena de texto "Hola, mundo!" seguida de un salto de línea para asegurar que el cursor de la terminal se mueva a la siguiente línea.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO hola_mundo

INICIO
    ESCRIBIR "Hola, mundo!"
FIN
```
:::

## 1.3: Saludador

### Descripción
Este ejercicio amplía el "Hola, mundo!" para que el programa interactúe con el usuario. Debe solicitarle su nombre y luego mostrar un saludo personalizado que lo incluya. Sirve para practicar la lectura de datos desde la entrada estándar.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable para almacenar el nombre del usuario. En C, esto se hace comúnmente con un arreglo de caracteres (`char`).
-   **Entrada:** El programa debe primero mostrar un mensaje pidiendo al usuario que ingrese su nombre. Luego, debe leer la entrada del teclado y almacenarla en la variable.
-   **Funciones de Lectura:** Se puede usar `scanf()` para leer la entrada, pero hay que tener en cuenta que `scanf("%s", ...)` dejará de leer al encontrar un espacio. Una alternativa más robusta es `fgets()`, que puede leer líneas completas.
-   **Salida:** Finalmente, el programa debe imprimir el saludo personalizado, combinando una cadena de texto fija con el nombre almacenado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO saludador

VARIABLES:
    nombre (cadena)

INICIO
    ESCRIBIR "Por favor, ingresa tu nombre:"
    LEER nombre
    ESCRIBIR "Hola mundo, ", nombre, "!"
FIN
```
:::

## 1.4: Secuencias de Pares e Impares

### 1.4.1: Pares en un rango

#### Descripción
El programa debe ser capaz de identificar y mostrar todos los números pares que existen dentro de un intervalo cerrado `[n, m]`, donde los límites `n` y `m` son proporcionados por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se deben leer dos números enteros, `n` (inicio del rango) y `m` (fin del rango).
-   **Proceso:** Se utiliza un lazo `for` que recorra cada número `i` desde `n` hasta `m`.
-   **Condición de Paridad:** Dentro del lazo, para cada número `i`, se debe verificar si es par. Un número es par si el resto de su división por 2 es igual a 0. Esta operación se realiza con el operador módulo (`%`).
-   **Salida:** Si la condición de paridad se cumple, el número `i` se imprime en la pantalla.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.4.2: Primeros N Impares

#### Descripción
Este ejercicio consiste en generar una secuencia de números impares, comenzando desde 1, hasta alcanzar un total de `N` términos, donde `N` es un número proporcionado por el usuario.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Se debe leer un número entero `N` que representa la cantidad de números impares a mostrar.
-   **Proceso:** Se puede abordar de dos maneras:
    1.  **Iterando y contando:** Usar un lazo que genere números (1, 2, 3, ...) y, para cada uno, verificar si es impar. Si lo es, se imprime y se incrementa un contador hasta llegar a `N`.
    2.  **Fórmula matemática:** Los números impares siguen la fórmula `2*k - 1` para `k = 1, 2, 3, ...`. Se puede usar un lazo que itere `N` veces (de `k=1` a `N`) y en cada paso calcule e imprima `2*k - 1`.
-   **Salida:** Se imprime la secuencia de los primeros `N` números impares.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO primeros_n_impares
ENTRADA: n_terminos (entero)

INICIO
    PARA k DESDE 1 HASTA n_terminos HACER
        impar = 2 * k - 1
        ESCRIBIR impar
    FIN PARA
FIN
```
:::

## 1.5: Operaciones con Rangos Numéricos

### 1.5.1: Secuencia Ascendente

#### Descripción
El objetivo es mostrar una secuencia de números enteros que comienza en un número `n` y termina justo antes de un número `m`. Esto corresponde al intervalo matemático `[n, m)`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe mientras el contador sea menor que `m`.
-   **Salida:** En cada iteración del lazo, imprimir el valor actual del contador.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO secuencia_ascendente
ENTRADA: n, m (enteros)

INICIO
    PARA i DESDE n HASTA m-1 HACER
        ESCRIBIR i
    FIN PARA
FIN
```
:::

### 1.5.2: Secuencia Descendente

#### Descripción
Similar al anterior, pero esta vez la secuencia debe ir en orden descendente. Se parte de un número `n` y se retrocede hasta un número `m`, sin incluirlo. Esto corresponde al intervalo `(m, n]`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer los enteros `n` (inclusive) y `m` (exclusive).
-   **Proceso:** Utilizar un lazo `for` que se inicialice en `n` y continúe mientras el contador sea mayor que `m`, decrementando el contador en cada paso.
-   **Salida:** Imprimir el valor del contador en cada iteración.

:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

ALGORITMO secuencia_descendente
ENTRADA: n, m (enteros)

INICIO
    PARA i DESDE n HASTA m+1 CON PASO -1 HACER
        ESCRIBIR i
    FIN PARA
FIN
```
:::

### 1.5.3: Sumatoria

#### Descripción
Calcular la suma de todos los números enteros en un rango cerrado `[n, m]`. Esto es equivalente a la operación matemática $\sum_{i=n}^{m} i$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita una variable `acumulador` (o `suma`), inicializada en 0, para guardar la suma.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere desde `n` hasta `m`. En cada iteración, añadir el valor del contador al `acumulador`.
-   **Salida:** Después de que el lazo termine, imprimir el valor final del `acumulador`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.5.4: Suma de Cuadrados

#### Descripción
Calcular la suma de los cuadrados de todos los números enteros en un rango cerrado `[n, m]`. La operación es $\sum_{i=n}^{m} i^2$.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesita un `acumulador` inicializado en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:** Usar un lazo `for` que itere de `n` a `m`. En cada iteración, calcular el cuadrado del número actual (`i*i`) y añadirlo al `acumulador`.
-   **Salida:** Al final, imprimir el valor del `acumulador`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.6: Par o Impar

### Descripción
Este es un ejercicio fundamental de lógica condicional. El programa debe solicitar un número entero al usuario y determinar si es par (divisible por 2) o impar.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un único número entero.
-   **Proceso:** La propiedad matemática clave es que un número entero es par si el resto de su división por 2 es exactamente 0. En C, el operador módulo (`%`) se usa para obtener este resto.
-   **Condición:** Se utiliza una estructura `if-else`. Si `numero % 2 == 0`, el número es par. En caso contrario, es impar.
-   **Salida:** Imprimir un mensaje claro que indique el resultado, como "El número X es Par" o "El número X es Impar".
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.7: Signo de un Número

### Descripción
El programa debe clasificar un número real (de punto flotante) ingresado por el usuario en una de tres categorías: positivo, negativo o cero.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número que puede tener decimales (tipo `float` o `double` en C).
-   **Proceso:** Utilizar una estructura de condicionales anidados o `if-else if-else`.
-   **Condiciones:**
    1.  Primero, verificar si el número es igual a 0.
    2.  Si no es cero, verificar si es mayor que 0 (positivo).
    3.  Si no es ninguna de las anteriores, por descarte, es negativo.
-   **Salida:** Imprimir el mensaje correspondiente a la categoría.


:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.8: Fórmulas Geométricas

### 1.8.1: Área de Triángulo (Base y Altura)

#### Descripción
Calcular el área de un triángulo a partir de las longitudes de su base y su altura. La fórmula es $A = \frac{1}{2} b \cdot h$.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario dos valores: la base (`b`) y la altura (`h`). Pueden ser números con decimales.
-   **Proceso:** Aplicar la fórmula matemática directamente. En C, esto se traduce como `(base * altura) / 2.0`.
-   **Salida:** Mostrar el área calculada.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.8.2: Área de Triángulo (Fórmula de Herón)

#### Descripción
Calcular el área de un triángulo conociendo únicamente la longitud de sus tres lados (`a`, `b`, `c`). Para esto se utiliza la fórmula de Herón.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario las longitudes de los tres lados.
-   **Proceso:**
    1.  Calcular el semiperímetro (`s`): $s = \frac{a+b+c}{2}$.
    2.  Aplicar la fórmula de Herón: $A = \sqrt{s(s-a)(s-b)(s-c)}$. Para la raíz cuadrada, se usa la función `sqrt()` de la biblioteca `math.h`.
-   **Validación:** Antes de calcular, es importante verificar si los lados pueden formar un triángulo (la suma de dos lados cualquiera debe ser mayor que el tercero).
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.8.3: Círculo

#### Descripción
Calcular el área y la circunferencia (perímetro) de un círculo a partir de su radio.

:::{hint} Lógica y Consideraciones
-   **Constantes:** Se necesita el valor de $\pi$. Se puede definir como una constante (`#define M_PI` en `math.h` o `const double PI = 3.14159;`).
-   **Entrada:** Solicitar al usuario el valor del radio (`r`).
-   **Proceso:**
    1.  Calcular el área: $A = \pi \cdot r^2$.
    2.  Calcular la circunferencia: $C = 2 \cdot \pi \cdot r$.
-   **Salida:** Mostrar ambos resultados de forma clara.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.8.4: Trapecio

#### Descripción
Calcular el área de un trapecio dadas las longitudes de sus dos bases paralelas y su altura.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario tres valores: la base mayor (`B`), la base menor (`b`) y la altura (`h`).
-   **Proceso:** Aplicar la fórmula del área del trapecio: $A = \frac{B+b}{2} h$.
-   **Salida:** Mostrar el área calculada.

:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.8.5: Polígono Regular

#### Descripción
Calcular el área de un polígono regular (lados y ángulos iguales) a partir del número de lados, la longitud de un lado y la apotema.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el número de lados (`n`), la longitud de un lado (`l`) y la longitud de la apotema (`a`).
-   **Proceso:**
    1.  Calcular el perímetro (`P`): $P = n \cdot l$.
    2.  Aplicar la fórmula del área: $A = \frac{P \cdot a}{2}$.
-   **Salida:** Mostrar el área calculada.

:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.8.6: Rectángulo

#### Descripción
Calcular el área y el perímetro de un rectángulo dadas las longitudes de su largo y su ancho.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el largo (`l`) y el ancho (`w`).
-   **Proceso:**
    1.  Calcular el área: $A = l \cdot w$.
    2.  Calcular el perímetro: $P = 2l + 2w$.
-   **Salida:** Mostrar ambos resultados.

:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.9: Conversiones de Unidades

### 1.9.1: Temperaturas

#### Descripción
Crear un programa que pueda convertir temperaturas entre las escalas Celsius, Fahrenheit y Kelvin.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar al usuario el valor de la temperatura y la escala original.
-   **Proceso:** Aplicar la fórmula de conversión correspondiente:
    -   **Celsius a Fahrenheit**: $F = (C \times 9/5) + 32$
    -   **Fahrenheit a Celsius**: $C = (F - 32) \times 5/9$
    -   **Celsius a Kelvin**: $K = C + 273.15$
-   **Precisión:** Al trabajar con divisiones como 9/5, es importante usar números de punto flotante (ej. `9.0/5.0`) para evitar la división entera que truncaría el resultado.
:::

:::{tip} Ayuda (pseudocódigo) para celsius a fahrenheit.
:class: dropdown
```{code-block} pseudocode

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
:::

### 1.9.2: Ángulos a Segundos

#### Descripción
Convertir una medida de ángulo dada en formato sexagesimal (grados, minutos y segundos) a su valor total equivalente en segundos.

:::{hint} Lógica y Consideraciones
-   **Relaciones:** Recordar que 1 grado = 60 minutos y 1 minuto = 60 segundos. Por lo tanto, 1 grado = 3600 segundos.
-   **Entrada:** Solicitar al usuario tres valores enteros: grados, minutos y segundos.
-   **Proceso:** Aplicar la fórmula de conversión: $total = (grados \times 3600) + (minutos \times 60) + segundos$.
-   **Salida:** Mostrar el total de segundos.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.10: Tabla de Multiplicar

### Descripción
El programa debe solicitar un número entero al usuario y mostrar su tabla de multiplicar, desde el 1 hasta el 10.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero, que será la base de la tabla.
-   **Proceso:** Utilizar un lazo `for` que itere desde 1 hasta 10. En cada iteración, el contador del lazo (`i`) se multiplicará por el número base.
-   **Salida:** Dentro del lazo, imprimir la operación y su resultado en un formato claro, como `base x i = resultado`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.11: Patrón de Asteriscos (Triángulo)

### Descripción
Implementar un programa que pida un número `n` e imprima un triángulo rectángulo de `n` filas de altura, construido con asteriscos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos anidados.
    1.  El lazo exterior controlará las filas, iterando desde 1 hasta `n`.
    2.  El lazo interior controlará las columnas (los asteriscos a imprimir en cada fila). Este lazo debe iterar desde 1 hasta el número de la fila actual (la variable del lazo exterior).
-   **Salida:** Después de que el lazo interior complete sus iteraciones para una fila, se debe imprimir un salto de línea para pasar a la siguiente.


:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.12: Calculadora Básica

### Descripción
Crear un programa que funcione como una calculadora simple. Debe solicitar al usuario dos números y un carácter que represente la operación aritmética a realizar (+, -, *, /).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer dos números (pueden ser `double` para mayor flexibilidad) y un carácter para el operador.
-   **Proceso:** Utilizar una estructura `switch` (o `if-else if`) para seleccionar la operación a realizar basándose en el carácter del operador.
-   **Caso Especial:** Manejar la división por cero. Si el operador es `/` y el segundo número es 0, se debe mostrar un mensaje de error en lugar de realizar la operación.
-   **Salida:** Mostrar el resultado de la operación o el mensaje de error.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.13: Adivina el Número

### Descripción
Desarrollar un juego simple donde el programa genera un número secreto aleatorio y el usuario debe adivinarlo. El programa proporciona pistas para guiar al usuario.

:::{hint} Lógica y Consideraciones
-   **Generación Aleatoria:**
    1.  Incluir la cabecera `stdlib.h` para `rand()` y `srand()`, y `time.h` para `time()`.
    2.  Inicializar la semilla del generador de números aleatorios una sola vez al principio del programa: `srand(time(NULL))`.
    3.  Generar el número secreto en un rango (ej. 1 a 100): `secreto = rand() % 100 + 1;`
-   **Proceso:** Usar un lazo `do-while` o `while` que se repita hasta que el número del usuario sea igual al número secreto.
-   **Entrada:** Dentro del lazo, solicitar al usuario que ingrese su intento.
-   **Condiciones:** Comparar el intento con el número secreto y dar una pista: "Muy alto", "Muy bajo" o "¡Correcto!".
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.14: Serie de Fibonacci (Iterativa)

### Descripción
Generar y mostrar los primeros `n` términos de la serie de Fibonacci. En esta serie, cada número es la suma de los dos anteriores, comenzando con 0 y 1.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan al menos tres variables para mantener el estado: los dos números anteriores de la serie (`a` y `b`) y el término actual (`siguiente`).
-   **Casos Base:** Los primeros dos términos (para n=0 y n=1) son fijos (0 y 1).
-   **Proceso:**
    1.  Inicializar `a = 0` y `b = 1`.
    2.  Imprimir los primeros términos según sea necesario.
    3.  Usar un lazo que se repita `n-2` veces para calcular los términos restantes.
    4.  En cada iteración: `siguiente = a + b`, imprimir `siguiente`, y luego actualizar `a = b` y `b = siguiente`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.15: Cálculo de Interés Simple

### Descripción
Implementar una función que calcule el monto final y el interés simple ganado a partir de un capital inicial, una tasa de interés anual y un período de tiempo en años.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar tres valores: capital (`P`), tasa de interés anual (`r`) y tiempo en años (`t`). La tasa de interés debe manejarse como un valor decimal (ej. 5% es 0.05).
-   **Proceso:**
    1.  Calcular el interés ganado: $I = P \cdot r \cdot t$.
    2.  Calcular el monto final: $A = P + I$.
-   **Salida:** Mostrar tanto el interés ganado como el monto total acumulado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.16: Índice de Masa Corporal (IMC)

### Descripción
Escribir un programa que calcule el Índice de Masa Corporal (IMC) de una persona y lo clasifique según las categorías de la OMS.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Solicitar el peso en kilogramos (kg) y la altura en metros (m).
-   **Proceso:**
    1.  Calcular el IMC usando la fórmula: $IMC = \frac{peso}{altura^2}$.
    2.  Usar una serie de condicionales `if-else if` para clasificar el resultado.
-   **Clasificación (ejemplo):**
    -   IMC < 18.5: Bajo peso
    -   18.5 <= IMC < 25: Normal
    -   25 <= IMC < 30: Sobrepeso
    -   IMC >= 30: Obesidad
-   **Salida:** Mostrar el valor del IMC y la categoría de peso correspondiente.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.17: Días del Mes

### Descripción
Crear un programa que, dado un mes (como número del 1 al 12) y un año, determine y muestre cuántos días tiene ese mes. Este ejercicio requiere manejar el caso especial de febrero en los años bisiestos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer el mes y el año como números enteros.
-   **Proceso:**
    1.  Usar una estructura `switch` o `if-else if` para determinar los días según el mes.
    2.  Meses con 31 días: 1, 3, 5, 7, 8, 10, 12.
    3.  Meses con 30 días: 4, 6, 9, 11.
    4.  Febrero (mes 2): requiere una lógica adicional para verificar si el año es bisiesto.
-   **Año Bisiesto:** Un año es bisiesto si es divisible por 4, excepto los años que son divisibles por 100 pero no por 400. La condición es: `(anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)`.
-   **Salida:** Imprimir el número de días.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.18: Máximo de Tres Números

### Descripción
El objetivo es encontrar el valor más grande entre tres números enteros proporcionados por el usuario. Este ejercicio se centra en el uso de condicionales anidados o operadores lógicos para realizar comparaciones múltiples.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer tres números enteros distintos (`a`, `b`, `c`).
-   **Proceso:** Se puede resolver de varias maneras:
    1.  **Condicionales anidados:** Comparar `a` con `b`. Si `a` es mayor, compararlo con `c`. El que resulte mayor es el máximo. Si `b` es mayor que `a`, compararlo con `c` para encontrar el máximo.
    2.  **Operadores lógicos:** Usar `if-else if-else`.
        -   `SI (a >= b Y a >= c) ENTONCES a es el máximo.`
        -   `SINO SI (b >= a Y b >= c) ENTONCES b es el máximo.`
        -   `SINO c es el máximo.`
    3.  **Variable auxiliar:** Asumir que el primero es el máximo y luego actualizar esta suposición si se encuentra uno mayor.
-   **Salida:** Imprimir el número que resultó ser el mayor.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.19: Clasificación de Triángulo

### Descripción
Dados los largos de tres lados, el programa debe determinar si pueden formar un triángulo válido y, en caso afirmativo, clasificarlo como equilátero (todos los lados iguales), isósceles (dos lados iguales) o escaleno (todos los lados diferentes).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer las longitudes de los tres lados (`a`, `b`, `c`).
-   **Validación (Desigualdad Triangular):** Antes de clasificar, es crucial verificar si los lados pueden formar un triángulo. La suma de las longitudes de dos lados cualesquiera debe ser siempre mayor que la longitud del tercer lado (`a+b > c`, `a+c > b`, `b+c > a`). Si no se cumple, no es un triángulo.
-   **Clasificación:**
    1.  Si `a == b` y `b == c`, es **equilátero**.
    2.  Si no es equilátero, verificar si dos lados son iguales (ej. `a == b` o `b == c` o `a == c`). Si es así, es **isósceles**.
    3.  Si ninguna de las condiciones anteriores se cumple, es **escaleno**.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.20: Desglose de Billetes

### Descripción
Dado un monto de dinero entero, el programa debe calcular la cantidad mínima de billetes de distintas denominaciones para representar dicho monto.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un monto entero.
-   **Denominaciones:** Definir las denominaciones de billetes disponibles en un orden descendente (ej. 1000, 500, 200, 100, 50, 20, 10).
-   **Proceso:** Utilizar divisiones y el operador módulo para calcular cuántos billetes de cada denominación se necesitan.
    1.  Para la denominación más alta, `cantidad = monto / denominacion`.
    2.  Actualizar el monto restante: `monto = monto % denominacion`.
    3.  Repetir el proceso para la siguiente denominación más baja.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.21: Piedra, Papel o Tijera

### Descripción
Implementar el clásico juego de Piedra, Papel o Tijera para que un usuario juegue una partida contra la computadora.

:::{hint} Lógica y Consideraciones
-   **Entrada del Usuario:** Pedir al usuario que elija una opción (ej. ingresando 1 para Piedra, 2 para Papel, 3 para Tijera).
-   **Elección de la Computadora:** Generar un número aleatorio entre 1 y 3 para simular la elección de la computadora.
-   **Reglas del Juego:**
    -   Piedra vence a Tijera.
    -   Tijera vence a Papel.
    -   Papel vence a Piedra.
-   **Proceso:** Comparar la elección del usuario con la de la computadora usando condicionales para determinar el ganador o si hay un empate.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.22: Patrón de Pirámide

### Descripción
Implementar un programa que pida un número `n` e imprima un triángulo rectángulo de `n` filas de altura, construido con asteriscos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n` para la altura del triángulo.
-   **Proceso:** Se necesitan dos lazos anidados.
    1.  El lazo exterior itera `n` veces, una por cada fila.
    2.  Se necesitan dos lazos interiores dentro del exterior:
        -   El primer lazo interior imprime los espacios en blanco necesarios para centrar la pirámide. En la fila `i`, se necesitan `n-i` espacios.
        -   El segundo lazo interior imprime los asteriscos. En la fila `i`, se necesitan `2*i - 1` asteriscos.
-   **Salida:** Después de cada fila, imprimir un salto de línea.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::


## 1.23: Validación de Contraseña Simple

### Descripción
Crear un programa que solicite una contraseña al usuario y no le permita continuar hasta que ingrese la contraseña correcta. Este ejercicio practica el uso de lazos `do-while` y la comparación de cadenas.

:::{hint} Lógica y Consideraciones
-   **Contraseña Secreta:** Definir una contraseña correcta como una cadena constante en el programa (ej. `"password123"`).
-   **Entrada:** Dentro de un lazo, solicitar al usuario que ingrese la contraseña.
-   **Proceso:** Usar un lazo `do-while` es ideal aquí, ya que la solicitud debe hacerse al menos una vez. La condición del lazo debe ser que la cadena ingresada por el usuario no sea igual a la contraseña secreta.
-   **Comparación de Cadenas:** En C, las cadenas no se pueden comparar con `==`. Se debe usar la función `strcmp()` de la biblioteca `string.h`. `strcmp(s1, s2)` devuelve 0 si las cadenas son idénticas.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.24: Cajero Automático (Menú)

### Descripción
Simular la interfaz de un menú de cajero automático. El programa debe mostrar una lista de opciones y ejecutar una acción simple según la elección del usuario, repitiendo el proceso hasta que el usuario decida salir.

:::{hint} Lógica y Consideraciones
-   **Estado:** Mantener una variable para el saldo de la cuenta.
-   **Proceso:** Usar un lazo `do-while` que se ejecute mientras la opción elegida por el usuario no sea la de "Salir".
-   **Menú:** Dentro del lazo, imprimir las opciones (1. Consultar, 2. Depositar, 3. Retirar, 4. Salir).
-   **Entrada:** Leer la opción del usuario.
-   **Selección:** Usar una estructura `switch` para manejar las diferentes opciones. Cada caso llamará a una función simple o ejecutará el código correspondiente (ej. pedir un monto para depositar y sumarlo al saldo).
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.25: Patrón de Rombo

### Descripción
Implementar un programa que pida un número impar `n` e imprima un rombo de asteriscos de `n` filas de altura.

:::{hint} Lógica y Consideraciones
-   **Estructura:** Un rombo puede verse como una pirámide seguida de una pirámide invertida.
-   **Entrada:** Leer un entero impar `n`.
-   **Proceso:**
    1.  **Parte Superior:** Usar la lógica del ejercicio de la pirámide para imprimir la mitad superior del rombo, con una altura de `(n/2) + 1`.
    2.  **Parte Inferior:** Usar un segundo conjunto de lazos anidados para imprimir la pirámide invertida. El lazo exterior iterará desde `n/2` hacia abajo hasta 1.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.26: Promedio de N Números

### Descripción
Escribir un programa que sea flexible en la cantidad de números a promediar. Primero debe preguntar al usuario cuántos números va a ingresar y luego calcular el promedio de esa cantidad de números.

:::{hint} Lógica y Consideraciones
-   **Entrada Inicial:** Leer la cantidad de números a promediar (`N`).
-   **Variables:** Se necesita un `acumulador` para la suma y un contador.
-   **Proceso:**
    1.  Usar un lazo `for` que se repita `N` veces.
    2.  Dentro del lazo, solicitar al usuario que ingrese un número y añadirlo al `acumulador`.
    3.  Después del lazo, calcular el promedio: `promedio = acumulador / N`.
-   **Salida:** Mostrar el promedio calculado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.27: Contador de Dígitos

### Descripción
Crear una función que reciba un número entero y devuelva la cantidad de dígitos que lo componen.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** La forma más simple es usar la división entera por 10 repetidamente en un lazo. Cada división elimina el último dígito del número. Se cuenta cuántas divisiones se pueden hacer hasta que el número se convierta en 0.
-   **Caso Especial:** Si el número de entrada es 0, tiene 1 dígito. El lazo simple no funcionaría, por lo que se debe manejar como un caso especial.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.28: Invertir un Número Entero

### Descripción
Implementar una función que tome un número entero y devuelva otro número con los dígitos en orden inverso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero.
-   **Proceso:** Se puede construir el número invertido dígito por dígito.
    1.  Inicializar una variable `invertido` a 0.
    2.  En un lazo, mientras el número original no sea 0:
        a. Obtener el último dígito: `digito = numero % 10`.
        b. Añadir el dígito al número invertido: `invertido = (invertido * 10) + digito`.
        c. Eliminar el último dígito del número original: `numero = numero / 10`.
-   **Salida:** Devolver el número `invertido`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.29: Potencia con Lazos

### Descripción
Escribir una función que calcule `base^exponente` sin usar la función `pow()` de la biblioteca `math.h`. Debe funcionar para exponentes enteros no negativos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Una base y un exponente (entero no negativo).
-   **Variables:** Se necesita una variable `resultado` inicializada en 1.
-   **Proceso:**
    1.  Si el exponente es 0, el resultado es 1.
    2.  Si el exponente es mayor que 0, usar un lazo que se repita `exponente` veces. En cada iteración, multiplicar `resultado` por la `base`.
-   **Salida:** Devolver el `resultado`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.30: Menú de Conversiones

### Descripción
Crear un programa robusto que presente al usuario un menú con varias opciones de conversión de unidades (ej. Celsius a Fahrenheit, Metros a Pies, Kilogramos a Libras). El programa debe repetir el menú hasta que el usuario elija la opción de salir.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Similar al ejercicio del cajero automático. Usar un lazo `do-while` para el menú y una estructura `switch` para manejar la selección del usuario.
-   **Modularidad:** Es una buena práctica crear una función separada para cada tipo de conversión. El `switch` simplemente llamaría a la función correspondiente.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.31: Validación de Fecha

### Descripción
Crear una función que valide si una combinación de día, mes y año corresponde a una fecha real en el calendario gregoriano.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Tres enteros: `dia`, `mes`, `anio`.
-   **Proceso:** Realizar una serie de verificaciones en orden lógico:
    1.  Verificar que el año sea razonable (ej. > 0).
    2.  Verificar que el mes esté en el rango [1, 12].
    3.  Verificar que el día esté en el rango [1, 31].
    4.  Verificar los días para meses específicos (30 días para abril, junio, etc.).
    5.  Manejar el caso de febrero, verificando si el año es bisiesto para permitir 29 días.
-   **Salida:** Devolver un valor booleano (`true` si es válida, `false` si no).
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.32: Dibujar un Cuadrado Hueco

### Descripción
Pedir al usuario un número `n` y dibujar el contorno de un cuadrado de `n x n` utilizando asteriscos. El interior del cuadrado debe estar vacío.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un entero `n`.
-   **Proceso:** Usar lazos anidados. El lazo exterior para las filas y el interior para las columnas.
-   **Condición:** Dentro del lazo interior, se debe decidir si imprimir un asterisco o un espacio. Se imprime un asterisco si:
    -   Es la primera o la última fila (`fila == 1` o `fila == n`).
    -   Es la primera o la última columna (`columna == 1` o `columna == n`).
-   En cualquier otro caso, se imprime un espacio.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.33: Suma Separada de Pares e Impares

### Descripción
Dado un rango de números `[n, m]`, el programa debe calcular la suma de todos los números pares y la suma de todos los números impares de forma independiente y mostrar ambos resultados.

:::{hint} Lógica y Consideraciones
-   **Variables:** Se necesitan dos acumuladores: `suma_pares` y `suma_impares`, ambos inicializados en 0.
-   **Entrada:** Leer los enteros `n` y `m`.
-   **Proceso:**
    1.  Usar un lazo `for` que itere desde `n` hasta `m`.
    2.  Dentro del lazo, verificar si el número actual `i` es par (`i % 2 == 0`).
    3.  Si es par, añadirlo a `suma_pares`. Si no, añadirlo a `suma_impares`.
-   **Salida:** Mostrar los valores finales de ambas sumas.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

## 1.34: Número de la Suerte

### Descripción
Un número de la suerte es un entero con una cantidad par de dígitos, donde la suma de los dígitos de la primera mitad es igual a la suma de los dígitos de la segunda mitad. El programa debe verificar si un número dado es de la suerte.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Leer un número entero.
-   **Proceso:**
    1.  Primero, contar el número de dígitos (ver ejercicio 1.27). Si es impar, no es un número de la suerte.
    2.  Si es par, dividir el número en dos mitades. Esto se puede hacer matemáticamente. Por ejemplo, para un número de 4 dígitos, la primera mitad son los dos primeros dígitos y la segunda mitad son los dos últimos.
    3.  Calcular la suma de los dígitos de cada mitad por separado.
    4.  Comparar las dos sumas.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

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
:::

