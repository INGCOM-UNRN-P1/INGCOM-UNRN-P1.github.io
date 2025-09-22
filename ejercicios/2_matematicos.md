---
title: Ejercicios Matemáticos
short_title: 2. Matemáticos
---

# Ejercicios Matemáticos

Ejercicios centrados en algoritmos de teoría de números y operaciones
matemáticas.

---

## 1: Aritmética Lenta

### 1.1: Suma lenta

#### Descripción
Implementar una función que simule la adición de dos números enteros, `n` y `m`, utilizando ñicamente las operaciones más básicas de la unidad aritmético-lógica: sumar o restar 1. Este ejercicio ayuda a comprender la suma como una serie de incrementos o decrementos sucesivos.

#### Lógica y Consideraciones
-   **Entrada:** Dos números enteros, `n` y `m`.
-   **Proceso:** El objetivo es llegar desde `n` al resultado `n+m` aplicando la operación de incremento `m` veces (si `m` es positivo) o la operación de decremento `|m|` veces (si `m` es negativo).
-   Se puede usar un lazo que se repita `abs(m)` veces (el valor absoluto de `m`).
-   Dentro del lazo, se verifica el signo de `m`. Si `m > 0`, se incrementa el resultado. Si `m < 0`, se decrementa.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION suma_lenta(n, m)
VARIABLES:
    resultado (entero)
INICIO
    resultado = n
    SI m > 0 ENTONCES
        PARA i DESDE 1 HASTA m HACER
            resultado = resultado + 1
        FIN PARA
    SINO
        PARA i DESDE 1 HASTA VALOR_ABSOLUTO(m) HACER
            resultado = resultado - 1
        FIN PARA
    FIN SI
    RETORNAR resultado
FIN FUNCION
```
:::
### 1.2: División lenta

#### Descripción
Implementar la división entera para obtener el cociente y el resto de `a / b` utilizando ñicamente restas sucesivas. Este método emula cómo se podría realizar una división de forma manual o en hardware muy simple.

#### Lógica y Consideraciones
-   **Entrada:** Dos enteros positivos, `dividendo` y `divisor`.
-   **Proceso:** Se resta el `divisor` del `dividendo` de forma repetida hasta que el `dividendo` sea menor que el `divisor`. Se necesita un contador (`cociente`) que se incrementa en cada resta exitosa.
-   El lazo (preferiblemente `while`) se ejecuta mientras `dividendo >= divisor`.
-   **Salida:** El valor final del contador es el cociente, y el valor final del `dividendo` (lo que sobra) es el resto.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO division_lenta(dividendo, divisor, REF cociente, REF resto)
INICIO
    cociente = 0
    MIENTRAS dividendo >= divisor HACER
        dividendo = dividendo - divisor
        cociente = cociente + 1
    FIN MIENTRAS
    resto = dividendo
FIN PROCEDIMIENTO
```
:::
### 1.3: División egipcia

#### Descripción
Implementar el antiguo método de división egipcio, que no requiere tablas de multiplicar ni operaciones de división directa. Se basa en duplicar el divisor, encontrar qué duplicaciones suman el dividendo y sumar los factores de duplicación correspondientes.

#### Lógica y Consideraciones
-   **Entrada:** Un dividendo y un divisor.
-   **Proceso:** 
    1.  **Tabla de Duplicación:** Crear dos columnas. La primera empieza en 1 y la segunda en el `divisor`. En cada paso, duplicar el valor de la fila anterior en ambas columnas. Detenerse cuando el siguiente valor en la columna del divisor supere al `dividendo`.
    2.  **Básqueda y Suma:** Recorrer la tabla de abajo hacia arriba. Para cada fila, si el valor en la columna del divisor es menor o igual al `dividendo` restante, se resta ese valor del `dividendo` y se suma el valor correspondiente de la primera columna al `cociente`.
-   **Salida:** El `cociente` acumulado y el `dividendo` final (que es el resto).

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO division_egipcia(dividendo, divisor, REF cociente, REF resto)
VARIABLES:
    col1, col2 (arreglos)
    i (entero)
INICIO
    // 1. Crear tabla
    col1[0] = 1, col2[0] = divisor
    i = 0
    MIENTRAS col2[i] <= dividendo HACER
        i = i + 1
        col1[i] = col1[i-1] * 2
        col2[i] = col2[i-1] * 2
    FIN MIENTRAS

    // 2. Buscar y sumar
    cociente = 0
    PARA j DESDE i-1 HASTA 0 CON PASO -1 HACER
        SI col2[j] <= dividendo ENTONCES
            dividendo = dividendo - col2[j]
            cociente = cociente + col1[j]
        FIN SI
    FIN PARA
    resto = dividendo
FIN PROCEDIMIENTO
```
:::
---

## 2: Divisibilidad y Factores

### 2.1: Divisibilidad

#### Descripción
Determinar si un número entero `a` es divisible de forma exacta por otro entero `b`.

#### Lógica y Consideraciones
-   **Entrada:** Dos enteros, `a` y `b`.
-   **Proceso:** La divisibilidad se comprueba con el operador módulo (`%`). Si el resto de la división `a % b` es 0, entonces `a` es divisible por `b`.
-   **Caso Especial:** Asegurarse de que `b` no sea cero para evitar un error de división por cero.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_divisible(a, b)
INICIO
    SI b == 0 ENTONCES
        RETORNAR FALSO // O manejar como error
    FIN SI
    SI a MOD b == 0 ENTONCES
        RETORNAR VERDADERO
    SINO
        RETORNAR FALSO
    FIN SI
FIN FUNCION
```

### 2.2: Factorial

#### Descripción
Calcular el factorial de un número entero no negativo `n`, denotado como `n!`. El factorial es el producto de todos los enteros positivos desde 1 hasta `n`.

#### Lógica y Consideraciones
-   **Entrada:** Un entero no negativo `n`.
-   **Casos Base:** Por definición, `0! = 1`. El factorial de 1 es 1.
-   **Proceso:** Se utiliza un lazo que itera desde 2 hasta `n`. Se necesita una variable `resultado` (de tipo `long long` para evitar desbordamiento rápido) inicializada en 1. En cada iteración, se multiplica `resultado` por el número actual del lazo.
-   **Desbordamiento:** Los factoriales crecen muy rápido. Usar un tipo de dato grande como `unsigned long long` es crucial.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION factorial(n)
VARIABLES:
    resultado (entero largo)
INICIO
    SI n < 0 ENTONCES
        RETORNAR -1 // Error
    FIN SI
    SI n == 0 ENTONCES
        RETORNAR 1
    FIN SI

    resultado = 1
    PARA i DESDE 2 HASTA n HACER
        resultado = resultado * i
    FIN PARA
    RETORNAR resultado
FIN FUNCION
```
:::

### 2.3: MCD y MCM

#### Descripción
Implementar funciones para calcular el Máximo Comón Divisor (MCD) y el Mínimo Comón Móltiplo (MCM) de dos números enteros.

#### Lógica y Consideraciones
-   **MCD (Algoritmo de Euclides):** Es el método más eficiente. Mientras `b` no sea cero, se calcula el resto `r = a % b`, luego se actualiza `a = b` y `b = r`. El MCD es el óltimo valor no nulo de `a`.
-   **MCM:** Se puede calcular fácilmente una vez que se tiene el MCD, usando la fórmula: $MCM(a, b) = \frac{|a \cdot b|}{MCD(a, b)}$. 

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION mcd(a, b)
VARIABLES:
    temporal (entero)
INICIO
    MIENTRAS b != 0 HACER
        temporal = b
        b = a MOD b
        a = temporal
    FIN MIENTRAS
    RETORNAR a
FIN FUNCION
```
:::
---

## 3: Propiedades de los Números

### 3.1: Suma de dígitos

#### Descripción
Calcular la suma de los dígitos individuales de un número entero positivo.

#### Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Se utiliza un lazo que se repite mientras `n` sea mayor que 0.
    1.  **Obtener óltimo dígito:** `digito = n % 10`.
    2.  **Sumar dígito:** `suma = suma + digito`.
    3.  **Eliminar óltimo dígito:** `n = n / 10` (división entera).

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION sumar_digitos(n)
VARIABLES:
    suma (entero)
INICIO
    suma = 0
    MIENTRAS n > 0 HACER
        suma = suma + (n MOD 10)
        n = n / 10
    FIN MIENTRAS
    RETORNAR suma
FIN FUNCION
```
:::

### 3.2: Invertir un número

#### Descripción
Tomar un número entero y devolver otro número con sus dígitos en orden inverso.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a la suma de dígitos, pero en lugar de sumar, se construye un nuevo número.
    1.  Inicializar `invertido = 0`.
    2.  En un lazo, mientras `n > 0`:
        a. `invertido = (invertido * 10) + (n % 10)`.
        b. `n = n / 10`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION invertir_numero(n)
VARIABLES:
    invertido (entero)
INICIO
    invertido = 0
    MIENTRAS n > 0 HACER
        invertido = (invertido * 10) + (n MOD 10)
        n = n / 10
    FIN MIENTRAS
    RETORNAR invertido
FIN FUNCION
```
:::

### 3.3: Capicúas

#### Descripción
Verificar si un número es capicúa (o palíndromo), es decir, si se lee igual de izquierda a derecha que de derecha a izquierda.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** La forma más sencilla es utilizar la función del ejercicio anterior para invertir el número y luego comparar el número invertido con el original.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_capicua(n)
INICIO
    SI n == invertir_numero(n) ENTONCES
        RETORNAR VERDADERO
    SINO
        RETORNAR FALSO
    FIN SI
FIN FUNCION
```

### 3.4: Números Primos

#### Descripción
Verificar si un número entero mayor que 1 es un número primo. Un número es primo si solo es divisible por 1 y por sí mismo.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Casos Base:** Números menores o iguales a 1 no son primos. 2 es el ónico primo par.
-   **Proceso:** Para verificar si `n` es primo, basta con comprobar si es divisible por algón número desde 2 hasta la raíz cuadrada de `n` ($\sqrt{n}$). Si se encuentra un divisor en ese rango, el número no es primo.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_primo(n)
INICIO
    SI n <= 1 ENTONCES RETORNAR FALSO
    PARA i DESDE 2 HASTA RAIZ_CUADRADA(n) HACER
        SI n MOD i == 0 ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION
```
:::

### 3.5: Números Perfectos

#### Descripción
Determinar si un número es un "número perfecto". Un número perfecto es un entero positivo que es igual a la suma de sus divisores propios positivos (todos sus divisores excepto él mismo).

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Calcular la suma de los divisores propios de `n`. Para ello, iterar desde 1 hasta `n/2`.
    2.  En cada iteración, si el iterador `i` es un divisor de `n` (`n % i == 0`), se suma `i` a un acumulador.
    3.  Finalmente, comparar la suma obtenida con el número original `n`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_perfecto(n)
VARIABLES:
    suma_divisores (entero)
INICIO
    suma_divisores = 0
    PARA i DESDE 1 HASTA n-1 HACER
        SI n MOD i == 0 ENTONCES
            suma_divisores = suma_divisores + i
        FIN SI
    FIN PARA
    RETORNAR (suma_divisores == n)
FIN FUNCION
```
:::

### 3.6: Números Amigos

#### Descripción
Verificar si dos números enteros positivos, `a` y `b`, son "números amigos". Dos números son amigos si la suma de los divisores propios de `a` es igual a `b`, y viceversa.

#### Lógica y Consideraciones
-   **Entrada:** Dos enteros positivos, `a` y `b`.
-   **Reutilización de Código:** Este problema se simplifica si ya se tiene una función que calcula la suma de los divisores propios de un número (como la usada en el ejercicio de "Números Perfectos").
-   **Proceso:** 
    1.  Calcular la suma de los divisores propios de `a`. Llamémosla `suma_div_a`.
    2.  Calcular la suma de los divisores propios de `b`. Llamémosla `suma_div_b`.
    3.  Verificar si se cumplen las dos condiciones: `suma_div_a == b` Y `suma_div_b == a`.
-   **Caso Especial:** Asegurarse de que `a` y `b` no sean el mismo número (un número perfecto es amigo de sí mismo, lo que a veces se excluye de la definición de números amigos).

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION suma_divisores_propios(n)
    // ... implementación como en el ejercicio de Números Perfectos ...
FIN FUNCION

FUNCION son_amigos(a, b)
INICIO
    // Opcional: excluir números perfectos
    SI a == b ENTONCES
        RETORNAR FALSO
    FIN SI

    suma_a = suma_divisores_propios(a)
    suma_b = suma_divisores_propios(b)

    SI suma_a == b Y suma_b == a ENTONCES
        RETORNAR VERDADERO
    SINO
        RETORNAR FALSO
    FIN SI
FIN FUNCION
```
:::
### 3.7: Números Abundantes

#### Descripción
Determinar si un número es "abundante". Un número es abundante si la suma de sus divisores propios es mayor que el propio número.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Es casi idéntico al de los números perfectos. Se calcula la suma de los divisores propios y, en lugar de comparar si es igual a `n`, se compara si es mayor que `n`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_abundante(n)
VARIABLES:
    suma_divisores (entero)
INICIO
    suma_divisores = 0
    PARA i DESDE 1 HASTA n-1 HACER
        SI n MOD i == 0 ENTONCES
            suma_divisores = suma_divisores + i
        FIN SI
    FIN PARA
    RETORNAR (suma_divisores > n)
FIN FUNCION
```
:::
### 3.8: Conjetura de Collatz

#### Descripción
Implementar la secuencia de Collatz para un número inicial `n`. La secuencia se genera aplicando repetidamente una regla: si el número actual es par, se divide por 2; si es impar, se multiplica por 3 y se le suma 1. La conjetura (no probada) es que esta secuencia siempre llega a 1.

#### Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Usar un lazo `while` que se ejecute mientras `n` sea diferente de 1. Dentro del lazo, aplicar la regla correspondiente y actualizar el valor de `n`. Imprimir el valor de `n` en cada paso para ver la secuencia.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO secuencia_collatz(n)
INICIO
    MIENTRAS n != 1 HACER
        ESCRIBIR n
        SI n MOD 2 == 0 ENTONCES
            n = n / 2
        SINO
            n = 3 * n + 1
        FIN SI
    FIN MIENTRAS
    ESCRIBIR 1 // El óltimo término de la secuencia
FIN PROCEDIMIENTO
```
:::

### 3.9: Números de Armstrong

#### Descripción
Verificar si un número es un número de Armstrong (o narcisista). Un número de `k` dígitos es de Armstrong si es igual a la suma de sus propios dígitos elevados a la potencia `k`.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Contar el número de dígitos (`k`) del número `n`.
    2.  Inicializar un acumulador `suma` en 0.
    3.  Recorrer los dígitos de `n` (usando `% 10` y `/ 10`). Para cada dígito, calcular `digito^k` y añadirlo a la `suma`.
    4.  Comparar la `suma` final con el número original `n`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode

FUNCION es_armstrong(n)
VARIABLES:
    k, suma, temp, digito (enteros)
INICIO
    k = contar_digitos(n)
    suma = 0
    temp = n

    MIENTRAS temp > 0 HACER
        digito = temp MOD 10
        suma = suma + potencia(digito, k)
        temp = temp / 10
    FIN MIENTRAS

    RETORNAR (suma == n)
FIN FUNCION
```
:::
### 3.10: Números Felices

#### Descripción
Determinar si un número es un "número feliz". El proceso consiste en reemplazar el número por la suma de los cuadrados de sus dígitos repetidamente. Si el proceso llega a 1, el número es feliz. Si entra en un ciclo que no incluye el 1 (notablemente el ciclo `4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4`), no es feliz.

#### Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Usar un lazo `while`. En cada iteración, calcular la suma de los cuadrados de los dígitos del número actual. El lazo debe terminar si el número se convierte en 1 (feliz) o si se detecta un ciclo (no feliz). Para detectar ciclos, se puede guardar los números ya vistos en un arreglo o simplemente detectar si se llega al número 4.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_feliz(n)
INICIO
    MIENTRAS n != 1 Y n != 4 HACER
        suma_cuadrados = 0
        temp = n
        MIENTRAS temp > 0 HACER
            digito = temp MOD 10
            suma_cuadrados = suma_cuadrados + digito * digito
            temp = temp / 10
        FIN MIENTRAS
        n = suma_cuadrados
    FIN MIENTRAS

    RETORNAR (n == 1)
FIN FUNCION
```
:::
---

## 4: Algoritmos Numéricos Avanzados

### 4.1: Criba de Eratóstenes

#### Descripción
Implementar la Criba de Eratóstenes, un algoritmo altamente eficiente para encontrar todos los números primos hasta un límite superior `N` especificado.

#### Lógica y Consideraciones
-   **Estructura de Datos:** Se necesita un arreglo booleano (o de enteros) `es_primo` de tamaño `N+1`. `es_primo[i]` será verdadero si `i` es primo y falso en caso contrario.
-   **Inicialización:** Se inicializa todo el arreglo a `verdadero`, asumiendo que todos los números son primos al principio. Luego, se marcan 0 y 1 como no primos.
-   **Proceso:** 
    1.  Se itera con un número `p` desde 2 hasta $\sqrt{N}$.
    2.  Si `p` sigue marcado como primo (`es_primo[p]` es verdadero):
        a. Se itera a través de todos los móltiplos de `p` (comenzando desde `p*p`) y se marcan como no primos (`es_primo[multiplo] = falso`). Se empieza en `p*p` porque los móltiplos menores ya habrán sido marcados por primos más pequeños.
-   **Salida:** Al final, se recorre el arreglo `es_primo` y se imprimen todos los índices `i` para los cuales `es_primo[i]` es verdadero.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO criba_eratostenes(N)
VARIABLES:
    es_primo (arreglo booleano de tamaño N+1)

INICIO
    // Inicialización
    PARA i DESDE 0 HASTA N HACER
        es_primo[i] = VERDADERO
    FIN PARA
    es_primo[0] = FALSO, es_primo[1] = FALSO

    // Marcado de móltiplos
    PARA p DESDE 2 HASTA RAIZ_CUADRADA(N) HACER
        SI es_primo[p] == VERDADERO ENTONCES
            PARA i DESDE p*p HASTA N CON PASO p HACER
                es_primo[i] = FALSO
            FIN PARA
        FIN SI
    FIN PARA

    // Imprimir resultados
    ESCRIBIR "Números primos hasta ", N, ":"
    PARA i DESDE 2 HASTA N HACER
        SI es_primo[i] == VERDADERO ENTONCES
            ESCRIBIR i
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::
### 4.2: Descomposición en Factores Primos

#### Descripción
Dado un número entero, encontrar y mostrar su descomposición en factores primos. Por ejemplo, para 360, la salida sería `2^3 * 3^2 * 5`.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Se itera con un divisor `d` comenzando en 2.
    2.  Mientras `d*d <= n`, se verifica si `d` divide a `n`.
    3.  Si `d` divide a `n`, se cuenta cuántas veces lo divide, se imprime el factor y su potencia, y se actualiza `n` dividiéndolo por `d` esa cantidad de veces.
    4.  Si al final del lazo `n` es mayor que 1, ese `n` restante es también un factor primo.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO factores_primos(n)
VARIABLES:
    contador (entero)
INICIO
    // Manejar el factor 2
    contador = 0
    MIENTRAS n MOD 2 == 0 HACER
        contador = contador + 1
        n = n / 2
    FIN MIENTRAS
    SI contador > 0 ENTONCES ESCRIBIR "2^", contador

    // Manejar factores impares
    PARA i DESDE 3 HASTA RAIZ_CUADRADA(n) CON PASO 2 HACER
        contador = 0
        MIENTRAS n MOD i == 0 HACER
            contador = contador + 1
            n = n / i
        FIN MIENTRAS
        SI contador > 0 ENTONCES ESCRIBIR i, "^", contador
    FIN PARA

    // Si n es primo > 2
    SI n > 2 ENTONCES
        ESCRIBIR n, "^1"
    FIN SI
FIN PROCEDIMIENTO
```
:::
### 4.3: Números de Catalan

#### Descripción
Implementar una función que calcule el n- ésimo número de Catalan, $C_n$. Estos números forman una secuencia de números naturales que aparece en varios problemas de conteo en combinatoria.

#### Lógica y Consideraciones
-   **Entrada:** Un entero no negativo `n`.
-   **Fórmula:** La fórmula más directa es $C_n = \frac{1}{n+1} \binom{2n}{n}$. Para calcularla, se necesita una función para el coeficiente binomial $\binom{n}{k}$.
-   **Coeficiente Binomial:** $\binom{n}{k}$ se puede calcular como $\frac{n!}{k!(n-k)!}$. Sin embargo, calcular los factoriales directamente puede causar desbordamiento muy rápido. Una forma más segura es calcularlo iterativamente: $\binom{n}{k} = \prod_{i=1}^{k} \frac{n-i+1}{i}$.
-   **Proceso:** 
    1.  Implementar una función `coeficiente_binomial(n, k)`.
    2.  La función `numero_catalan(n)` llamará a `coeficiente_binomial(2*n, n)` y dividirá el resultado por `n+1`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION coeficiente_binomial(n, k)
    SI k < 0 O k > n ENTONCES
        RETORNAR 0
    FIN SI
    SI k == 0 O k == n ENTONCES
        RETORNAR 1
    FIN SI
    SI k > n / 2 ENTONCES
        k = n - k
    FIN SI

    resultado = 1
    PARA i DESDE 1 HASTA k HACER
        resultado = resultado * (n - i + 1) / i
    FIN PARA
    RETORNAR resultado
FIN FUNCION

FUNCION numero_catalan(n)
INICIO
    // C_n = C(2n, n) / (n+1)
    c = coeficiente_binomial(2 * n, n)
    RETORNAR c / (n + 1)
FIN FUNCION
```
:::
### 4.4: Coeficiente Binomial

#### Descripción
Calcular el coeficiente binomial "n en k", denotado como $C(n, k)$ o $\binom{n}{k}$, que representa el número de formas de elegir `k` elementos de un conjunto de `n` elementos sin importar el orden.

#### Lógica y Consideraciones
-   **Entrada:** Dos enteros no negativos, `n` y `k`.
-   **Proceso:** Como se mencionó en el ejercicio anterior, calcularlo mediante la fórmula iterativa $\prod_{i=1}^{k} \frac{n-i+1}{i}$ es numéricamente más estable que usar factoriales. Es importante realizar la multiplicación antes de la división en cada paso para mantener la precisión y evitar divisiones prematuras.
-   **Optimización:** Dado que $\binom{n}{k} = \binom{n}{n-k}$, se puede elegir el valor más pequeño entre `k` y `n-k` para reducir el número de iteraciones.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION coeficiente_binomial(n, k)
    SI k < 0 O k > n ENTONCES
        RETORNAR 0
    FIN SI
    SI k == 0 O k == n ENTONCES
        RETORNAR 1
    FIN SI
    // Optimización
    SI k > n / 2 ENTONCES
        k = n - k
    FIN SI

    resultado = 1
    PARA i DESDE 1 HASTA k HACER
        resultado = resultado * (n - i + 1) / i
    FIN PARA
    RETORNAR resultado
FIN FUNCION
```
:::
### 4.5: Raíz Cuadrada Entera (Método Babilónico)

#### Descripción
Implementar un algoritmo para calcular la parte entera de la raíz cuadrada de un número `n` utilizando el método babilónico (o de Herón), que es un método iterativo eficiente.

#### Lógica y Consideraciones
-   **Entrada:** Un número no negativo `n`.
-   **Proceso:** Es un algoritmo de aproximaciones sucesivas.
    1.  Se elige una estimación inicial `x` (por ejemplo, `x = n`).
    2.  Se repite un número fijo de veces o hasta que la estimación converja: `x = (x + n / x) / 2`.
-   **Salida:** El resultado es la parte entera de la estimación final `x`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION raiz_cuadrada_entera(n)
VARIABLES:
    x (real)
INICIO
    SI n < 0 RETORNAR -1 // Error
    SI n == 0 RETORNAR 0

    x = n
    // Iterar un número fijo de veces para aproximar
    PARA i DESDE 1 HASTA 10 HACER
        x = (x + n / x) / 2
    FIN PARA

    RETORNAR PARTE_ENTERA(x)
FIN FUNCION
```
:::
### 4.6: Números Triangulares

#### Descripción
Un número triangular es la suma de los `n` primeros números naturales. Por ejemplo, el 4ó número triangular es 1+2+3+4=10. El objetivo es escribir una función que determine si un número entero dado es un número triangular.

#### Lógica y Consideraciones
-   **Entrada:** Un entero positivo `num`.
-   **Proceso:** Hay dos enfoques principales:
    1.  **Iterativo:** Generar números triangulares sumando 1, 2, 3, ... en un acumulador. En cada paso, comparar el acumulador con `num`. Si son iguales, es triangular. Si el acumulador supera a `num`, no lo es.
    2.  **Matemático:** Un número `x` es triangular si y solo si $8x+1$ es un cuadrado perfecto. Se puede calcular $8x+1$, obtener su raíz cuadrada, y verificar si es un entero.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_triangular(num)
VARIABLES:
    suma, i (enteros)
INICIO
    SI num < 0 RETORNAR FALSO

    suma = 0
    i = 1
    MIENTRAS suma < num HACER
        suma = suma + i
        i = i + 1
    FIN MIENTRAS

    RETORNAR (suma == num)
FIN FUNCION
```
:::
### 4.7: Conjetura de Goldbach

#### Descripción
La conjetura de Goldbach (aùn no probada) establece que todo número par mayor que 2 puede expresarse como la suma de dos números primos. Escribir un programa que, dado un número par, encuentre un par de números primos que lo sumen.

#### Lógica y Consideraciones
-   **Entrada:** Un número entero par `n` > 2.
-   **Proceso:** 
    1.  Se necesita una función `es_primo(x)`.
    2.  Iterar con un número `p` desde 2 hasta `n/2`.
    3.  En cada iteración, si `p` es primo, verificar si `n-p` también es primo.
    4.  Si ambos lo son, se ha encontrado un par y se puede terminar.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO encontrar_par_goldbach(n)
INICIO
    PARA p DESDE 2 HASTA n / 2 HACER
        SI es_primo(p) Y es_primo(n - p) ENTONCES
            ESCRIBIR n, " = ", p, " + ", n - p
            TERMINAR
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 4.8: Primos Gemelos

#### Descripción
Dos números primos `p` y `q` son gemelos si `q = p + 2`. El programa debe encontrar todos los pares de primos gemelos hasta un límite `N`.

#### Lógica y Consideraciones
-   **Entrada:** Un límite superior `N`.
-   **Proceso:** 
    1.  Iterar con un número `p` desde 2 hasta `N-2`.
    2.  En cada iteración, verificar si tanto `p` como `p+2` son primos.
    3.  Si ambos lo son, se ha encontrado un par de primos gemelos.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO primos_gemelos(N)
INICIO
    PARA p DESDE 2 HASTA N - 2 HACER
        SI es_primo(p) Y es_primo(p + 2) ENTONCES
            ESCRIBIR "(", p, ", ", p + 2, ")"
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 4.9: Identidad de Bézout

#### Descripción
Extender el Algoritmo de Euclides para encontrar no solo el MCD de dos enteros `a` y `b`, sino también dos enteros `x` e `y` que satisfacen la identidad de Bézout: $ax + by = mcd(a, b)$.

#### Lógica y Consideraciones
-   **Algoritmo Extendido de Euclides:** Es una modificación del algoritmo de Euclides que mantiene un registro de los coeficientes `x` e `y` en cada paso. Es inherentemente recursivo.
-   **Proceso:** La implementación recursiva es más intuitiva. La llamada recursiva devuelve el MCD y los coeficientes para los números más pequeños, y la llamada actual los ajusta para los números originales.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION mcd_extendido(a, b, REF x, REF y)
INICIO
    SI a == 0 ENTONCES
        x = 0
        y = 1
        RETORNAR b
    FIN SI

    x1, y1 (enteros)
    mcd = mcd_extendido(b MOD a, a, REF x1, REF y1)

    x = y1 - (b / a) * x1
    y = x1

    RETORNAR mcd
FIN FUNCION
```
:::

### 4.10: Cálculo de Pi (Serie de Leibniz)

#### Descripción
Aproximar el valor de $\pi$ utilizando la serie de Leibniz. La función debe recibir el número de términos a utilizar para la aproximación.

#### Lógica y Consideraciones
-   **Fórmula:** $\pi = 4 \sum_{k=0}^{\infty} \frac{(-1)^k}{2k+1} = 4 (1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \dots)$
-   **Proceso:** 
    1.  Inicializar una variable `suma` a 0.
    2.  Iterar `k` desde 0 hasta el número de términos deseado.
    3.  En cada iteración, calcular el término $\frac{(-1)^k}{2k+1}$ y añadirlo a `suma`.
    4.  El resultado final es `4 * suma`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION aproximar_pi(n_terminos)
VARIABLES:
    suma (real)
INICIO
    suma = 0.0
    PARA k DESDE 0 HASTA n_terminos - 1 HACER
        termino = potencia(-1, k) / (2.0 * k + 1.0)
        suma = suma + termino
    FIN PARA
    RETORNAR 4.0 * suma
FIN FUNCION
```
:::
### 4.11: Números de Lucas

#### Descripción
Generar los primeros `n` términos de la secuencia de Lucas. Es una secuencia similar a la de Fibonacci, pero comienza con 2 y 1.

#### Lógica y Consideraciones
-   **Definición:** $L_n = L_{n-1} + L_{n-2}$ con $L_0 = 2$ y $L_1 = 1$.
-   **Proceso:** La implementación es casi idéntica a la de Fibonacci, solo cambian los valores iniciales.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO secuencia_lucas(n)
VARIABLES:
    a, b, siguiente (enteros)
INICIO
    SI n >= 1 ENTONCES ESCRIBIR 2
    SI n >= 2 ENTONCES ESCRIBIR 1

    a = 2, b = 1
    PARA i DESDE 3 HASTA n HACER
        siguiente = a + b
        ESCRIBIR siguiente
        a = b
        b = siguiente
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 4.12: Números de Mersenne

#### Descripción
Un número de Mersenne es un número de la forma $M_p = 2^p - 1$, donde `p` es un número primo. El programa debe generar números de Mersenne y verificar si son a su vez primos (primos de Mersenne).

#### Lógica y Consideraciones
-   **Proceso:** 
    1.  Generar números primos `p` (usando la criba o la función `es_primo`).
    2.  Para cada primo `p`, calcular $M_p = 2^p - 1$.
    3.  Verificar si el $M_p$ resultante es también primo.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO primos_de_mersenne(limite_p)
INICIO
    PARA p DESDE 2 HASTA limite_p HACER
        SI es_primo(p) ENTONCES
            m = potencia(2, p) - 1
            SI es_primo(m) ENTONCES
                ESCRIBIR "M(", p, ") = ", m, " es un primo de Mersenne."
            FIN SI
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 4.13: Test de Primalidad de Miller-Rabin

#### Descripción
Implementar una versión simplificada del test de primalidad de Miller-Rabin. Es un test probabilístico que, a diferencia de la división por tentativa, es eficiente para números grandes.

#### Lógica y Consideraciones
-   **Teorema:** Se basa en propiedades de los números primos relacionadas con el Pequeño Teorema de Fermat. Es más complejo que los algoritmos anteriores.
-   **Proceso Simplificado:** 
    1.  Dado un número `n` a probar, se eligen varias bases aleatorias `a` < `n`.
    2.  Para cada base `a`, se comprueba si satisface ciertas congruencias. Si para alguna base no las satisface, `n` es compuesto. Si las satisface para todas las bases, es "probablemente primo".
-   **Nota:** La implementación completa es avanzada. Un ejercicio más simple puede ser implementarlo para una sola base fija.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_probablemente_primo(n, k_iteraciones)
INICIO
    // ... Lógica compleja del test de Miller-Rabin ...
    // Descomponer n-1 en d * 2^s
    // Repetir k veces:
    //   Elegir 'a' aleatorio en [2, n-2]
    //   Calcular x = a^d mod n
    //   Si x == 1 o x == n-1, continuar
    //   ... (lazo para s-1) ...
    // Si no pasa las pruebas, RETORNAR FALSO
    RETORNAR VERDADERO
FIN FUNCION
```
:::

### 4.14: Números Vampiro

#### Descripción
Un número vampiro es un número de `2k` dígitos que puede ser factorizado en dos números de `k` dígitos (los "colmillos"), donde los dígitos de los colmillos, concatenados, son una permutación de los dígitos del número original.

#### Lógica y Consideraciones
-   **Entrada:** Un número `n` de 4 dígitos.
-   **Proceso:** 
    1.  Iterar a través de todos los posibles pares de "colmillos" de 2 dígitos (`i` y `j`).
    2.  Verificar si `i * j == n`.
    3.  Si es así, obtener los 4 dígitos de `n` y los 4 dígitos de `i` y `j`.
    4.  Verificar si los dos conjuntos de dígitos son permutaciones el uno del otro (ej. ordenándolos y comparando).

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_vampiro_4_digitos(n)
INICIO
    PARA i DESDE 10 HASTA 99 HACER
        PARA j DESDE i HASTA 99 HACER
            SI i * j == n ENTONCES
                digitos_n = obtener_digitos_ordenados(n)
                digitos_colmillos = obtener_digitos_ordenados(i, j)
                SI digitos_n == digitos_colmillos ENTONCES
                    RETORNAR VERDADERO
                FIN SI
            FIN SI
        FIN PARA
    FIN PARA
    RETORNAR FALSO
FIN FUNCION
```
:::
### 4.15: Cuadrado Mágico

#### Descripción
Verificar si una matriz cuadrada `n x n` de números es un cuadrado mágico. Un cuadrado mágico es una matriz donde la suma de los números de cada fila, cada columna y ambas diagonales principales es la misma ("constante mágica").

#### Lógica y Consideraciones
-   **Entrada:** Una matriz `n x n`.
-   **Proceso:** 
    1.  Calcular la suma de la primera fila y guardarla como la `constante_magica` de referencia.
    2.  Iterar por las demás filas, calculando su suma y comparándola con la `constante_magica`.
    3.  Iterar por todas las columnas, calculando su suma y comparándola.
    4.  Calcular la suma de la diagonal principal y la diagonal secundaria y compararlas.
-   Si todas las sumas son iguales, es un cuadrado mágico.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_cuadrado_magico(matriz, n)
VARIABLES:
    constante_magica, suma_actual (entero)
INICIO
    // Calcular constante de referencia
    constante_magica = suma_fila(matriz, 0)

    // Verificar filas y columnas
    PARA i DESDE 1 HASTA n-1 HACER
        SI suma_fila(matriz, i) != constante_magica RETORNAR FALSO
        SI suma_columna(matriz, i) != constante_magica RETORNAR FALSO
    FIN PARA

    // Verificar diagonales
    SI suma_diagonal_principal(matriz) != constante_magica RETORNAR FALSO
    SI suma_diagonal_secundaria(matriz) != constante_magica RETORNAR FALSO

    RETORNAR VERDADERO
FIN FUNCION
```
:::
---

## 5: Más Teoría de Números y Algoritmos

### 5.1: Números de Smith

#### Descripción
Un número de Smith es un número compuesto cuya suma de dígitos es igual a la suma de los dígitos de sus factores primos. El programa debe verificar si un número dado es un número de Smith.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Verificar que `n` no sea primo.
    2.  Calcular la suma de los dígitos de `n`.
    3.  Obtener los factores primos de `n`.
    4.  Calcular la suma de los dígitos de todos los factores primos. Si un factor tiene más de un dígito (ej. 13), se deben sumar sus dígitos individuales (1+3).
    5.  Comparar las dos sumas.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_numero_smith(n)
INICIO
    SI es_primo(n) RETORNAR FALSO

    suma_digitos_n = sumar_digitos(n)
    suma_digitos_factores = 0
    temp_n = n

    // Lógica para obtener factores primos y sumar sus dígitos
    // ... (similar a la descomposición en factores primos)

    RETORNAR (suma_digitos_n == suma_digitos_factores)
FIN FUNCION
```
:::

### 5.2: Primos de Sophie Germain

#### Descripción
Un número primo `p` es un primo de Sophie Germain si `2p + 1` también es un número primo. El programa debe encontrar todos los primos de Sophie Germain hasta un límite `N`.

#### Lógica y Consideraciones
-   **Entrada:** Un límite superior `N`.
-   **Proceso:** 
    1.  Iterar con un número `p` desde 2 hasta `N`.
    2.  En cada iteración, verificar si `p` es primo.
    3.  Si `p` es primo, calcular `q = 2*p + 1` y verificar si `q` también es primo.
    4.  Si ambos son primos, `p` es un primo de Sophie Germain.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO primos_sophie_germain(N)
INICIO
    PARA p DESDE 2 HASTA N HACER
        SI es_primo(p) Y es_primo(2*p + 1) ENTONCES
            ESCRIBIR p
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.3: Función φ de Euler (Totient)

#### Descripción
Implementar una función que calcule el Totient de Euler, `φ(n)`. Esta función cuenta el número de enteros positivos hasta `n` que son coprimos con `n` (es decir, `mcd(k, n) = 1` para `1 <= k <= n`).

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso (simple):** Iterar `k` desde 1 hasta `n` y contar cuántas veces `mcd(k, n) == 1`.
-   **Proceso (eficiente):** Usar la fórmula basada en los factores primos de `n`: $\phi(n) = n \prod_{p|n, p \text{ es primo}} (1 - \frac{1}{p})$.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION phi_euler(n)
VARIABLES:
    resultado (real)
INICIO
    resultado = n
    p = 2
    temp_n = n
    MIENTRAS p*p <= temp_n HACER
        SI temp_n MOD p == 0 ENTONCES
            MIENTRAS temp_n MOD p == 0 HACER
                temp_n = temp_n / p
            FIN MIENTRAS
            resultado = resultado * (1.0 - (1.0 / p))
        FIN SI
        p = p + 1
    FIN MIENTRAS
    SI temp_n > 1 ENTONCES
        resultado = resultado * (1.0 - (1.0 / temp_n))
    FIN SI
    RETORNAR PARTE_ENTERA(resultado)
FIN FUNCION
```
:::
### 5.4: Radical de un Número

#### Descripción
Calcular el radical de un número `n`, denotado como `rad(n)`, que es el producto de sus factores primos distintos.

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a la descomposición en factores primos, pero en lugar de contar potencias, simplemente se multiplica cada factor primo distinto encontrado a una variable `resultado`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION radical(n)
VARIABLES:
    resultado (entero)
INICIO
    resultado = 1
    // Lógica para encontrar factores primos distintos y multiplicarlos
    // ...
    RETORNAR resultado
FIN FUNCION
```
:::
### 5.5: Secuencia de Tribonacci

#### Descripción
Generar los primeros `n` términos de la secuencia de Tribonacci, donde cada término es la suma de los tres anteriores. La secuencia puede comenzar de diferentes formas, una comón es `0, 1, 1, 2, 4, 7, 13, ...`

#### Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a Fibonacci, pero se necesitan tres variables para guardar los tres términos anteriores.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO tribonacci(n)
VARIABLES:
    a, b, c, siguiente (enteros)
INICIO
    a=0, b=1, c=1
    // Imprimir los primeros términos segùn n
    PARA i DESDE 4 HASTA n HACER
        siguiente = a + b + c
        ESCRIBIR siguiente
        a = b, b = c, c = siguiente
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.6: Fracciones Egipcias

#### Descripción
Escribir una función que descomponga una fracción propia `a/b` en una suma de fracciones unitarias distintas (fracciones con numerador 1).

#### Lógica y Consideraciones
-   **Algoritmo Greedy:** Un método comón es encontrar repetidamente la fracción unitaria más grande que sea menor o igual a la fracción restante.
-   **Proceso:** 
    1.  Dada la fracción `num/den`.
    2.  Encontrar el denominador `d` de la siguiente fracción unitaria: `d = techo(den / num)`.
    3.  Imprimir `1/d`.
    4.  Actualizar la fracción restante: `num/den = num/den - 1/d`.
    5.  Repetir hasta que `num` sea 0.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO fracciones_egipcias(num, den)
INICIO
    MIENTRAS num != 0 HACER
        d = TECHO(den / num)
        ESCRIBIR "1/", d
        num = num * d - den
        den = den * d
        // Simplificar fracción num/den
    FIN MIENTRAS
FIN PROCEDIMIENTO
```
:::
### 5.7: Ternas Pitagóricas

#### Descripción
Implementar un programa que genere todas las ternas pitagóricas primitivas (`a^2 + b^2 = c^2`, con `mcd(a,b,c)=1`) hasta un cierto límite para `c`, utilizando la fórmula de Euclides.

#### Lógica y Consideraciones
-   **Fórmula de Euclides:** Todas las ternas primitivas se pueden generar a partir de dos enteros `m > n > 0`, coprimos y de paridad opuesta, usando las fórmulas:
    -   `a = m^2 - n^2`
    -   `b = 2mn`
    -   `c = m^2 + n^2`
-   **Proceso:** Iterar con `m` y `n` bajo las condiciones dadas y generar `a`, `b` y `c`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO ternas_pitagoricas(limite_c)
INICIO
    PARA m DESDE 2 HASTA RAIZ_CUADRADA(limite_c) HACER
        PARA n DESDE 1 HASTA m-1 HACER
            SI (m - n) MOD 2 == 1 Y mcd(m, n) == 1 ENTONCES
                a = m*m - n*n
                b = 2*m*n
                c = m*m + n*n
                SI c <= limite_c ENTONCES
                    ESCRIBIR "(", a, ", ", b, ", ", c, ")"
                FIN SI
            FIN SI
        FIN PARA
    FIN PARA
FIN PROCEDIMIENTO
```
:::
### 5.8: Números de Carmichael

#### Descripción
Un número de Carmichael es un número compuesto `n` que satisface la congruencia $b^{n-1} \equiv 1 \pmod{n}$ para todos los enteros `b` coprimos con `n`. Escribir una función que verifique si un número es un número de Carmichael.

#### Lógica y Consideraciones
-   **Proceso:** 
    1.  Verificar si `n` es compuesto (no es primo).
    2.  Iterar con `b` desde 2 hasta `n-1`.
    3.  Si `mcd(b, n) == 1`, verificar si `potencia_modular(b, n-1, n) != 1`.
    4.  Si se encuentra un `b` que no cumple la condición, `n` no es de Carmichael. Si se prueban todos y la cumplen, sí lo es.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_carmichael(n)
INICIO
    SI es_primo(n) O n MOD 2 == 0 RETORNAR FALSO

    PARA b DESDE 2 HASTA n-1 HACER
        SI mcd(b, n) == 1 ENTONCES
            SI potencia_modular(b, n-1, n) != 1 ENTONCES
                RETORNAR FALSO
            FIN SI
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION
```
:::

### 5.9: Logaritmo Entero

#### Descripción
Calcular el logaritmo entero en base `b` de un número `n`. Es el mayor entero `k` tal que $b^k \le n$. La implementación no debe usar funciones de `math.h`.

#### Lógica y Consideraciones
-   **Proceso:** Se puede resolver con divisiones sucesivas.
    1.  Inicializar `k = 0`.
    2.  Mientras `n >= b`, dividir `n` por `b` e incrementar `k`.
    3.  El valor final de `k` es el resultado.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION logaritmo_entero(n, b)
VARIABLES:
    k (entero)
INICIO
    k = 0
    MIENTRAS n >= b HACER
        n = n / b
        k = k + 1
    FIN MIENTRAS
    RETORNAR k
FIN FUNCION
```
:::

### 5.10: Conversión de Base Numérica

#### Descripción
Escribir una función que convierta un número `n` de una base `b1` a una base `b2`.

#### Lógica y Consideraciones
-   **Proceso en dos pasos:** El método más simple es:
    1.  **Convertir a base 10:** Convertir el número de su base original `b1` a base 10. Si el número está en un arreglo de dígitos, se calcula $\sum digito_i \cdot b1^i$.
    2.  **Convertir de base 10:** Convertir el número de base 10 a la base de destino `b2` usando divisiones sucesivas y guardando los restos.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION convertir_base(numero_original, b1, b2)
INICIO
    // Paso 1: Convertir de b1 a base 10
    valor_base10 = 0
    // ... lazo para calcular el valor en base 10 ...

    // Paso 2: Convertir de base 10 a b2
    resultado_final = ""
    MIENTRAS valor_base10 > 0 HACER
        resto = valor_base10 MOD b2
        resultado_final = caracter(resto) + resultado_final
        valor_base10 = valor_base10 / b2
    FIN MIENTRAS

    RETORNAR resultado_final
FIN FUNCION
```
:::