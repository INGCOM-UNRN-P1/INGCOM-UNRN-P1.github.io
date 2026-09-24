---
title: Ejercicios Matemáticos
short_title: 3. Matemáticos
---

# Ejercicios Matemáticos

## Prerrequisitos y Entorno Requerido
Para abordar y verificar las soluciones de este módulo, se requiere:
1. **Entorno de Compilación:** Compilador GCC 9+ o Clang bajo estándar estricto **ISO C11** (`-std=c11 -Wall -Wextra -Werror -pedantic`).
2. **Aritmética y Rango de Tipos:** Representación entera (`int`, `long long`, `unsigned int`), prevención de desbordamientos (*integer overflow*) y conversión explícita de tipos (*type casting*) en divisiones con punto flotante (`2.0`).
3. **Control de Flujo Iterativo:** Lazos secuenciales, condiciones de parada bien fundamentadas y funciones puras libres de efectos colaterales.

## Acerca de

Estos ejercicios están centrados en algoritmos de teoría de números y
operaciones matemáticas en C11. Te permitirán comprender cómo se implementan los
cálculos matemáticos de forma iterativa y condicional, y cómo manejar las
limitaciones de precisión de las variables.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-aritmetica-numeros`
- {ref}`capitulo-conversiones-casts`

---

## Aritmética Lenta

(ej_b1_c03_01)=
### Ejercicio 1.03.01 - Suma Lenta por Incrementos Sucesivos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03_01_suma_lenta

Implementá una función que sume dos números enteros `n` y `m` utilizando
únicamente operaciones de incremento o decremento unitario (`+1`, `-1`).

```c
int suma_lenta(int n, int m);
```

**Tabla de Vectores de Prueba:**

| Entrada (`n`, `m`) | Salida Esperada | Comentario |
| :--- | :--- | :--- |
| `n = 5, m = 3` | `8` | 3 incrementos |
| `n = 5, m = -2` | `3` | 2 decrementos |
| `n = 10, m = 0` | `10` | 0 iteraciones |
| `n = -4, m = -3` | `-7` | Valores negativos |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int suma_lenta(int n, int m) {
    int res = n;
    if (m > 0) {
        for (int i = 0; i < m; ++i) {
            res++;
        }
    } else {
        int veces = -m;
        for (int i = 0; i < veces; ++i) {
            res--;
        }
    }
    return res;
}

int main(void) {
    assert(suma_lenta(5, 3) == 8);
    assert(suma_lenta(5, -2) == 3);
    assert(suma_lenta(10, 0) == 10);
    assert(suma_lenta(-4, -3) == -7);
    assert(suma_lenta(0, 0) == 0);
    return 0;
}
```
::::
:::

(ej_b1_c03_02)=
### Ejercicio 1.03.02 - División Lenta por Restas Sucesivas ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03_02_division_lenta

Implementá la división entera no negativa mediante restas sucesivas, retornando
el cociente y el resto por parámetros de salida. Retorna `false` si el divisor es cero.

```c
bool division_lenta(unsigned int a, unsigned int b, unsigned int *cociente, unsigned int *resto);
```

**Tabla de Vectores de Prueba:**

| Dividendo `a` | Divisor `b` | Retorno | Cociente | Resto |
| :--- | :--- | :--- | :--- | :--- |
| `14` | `4` | `true` | `3` | `2` |
| `20` | `5` | `true` | `4` | `0` |
| `3` | `8` | `true` | `0` | `3` |
| `10` | `0` | `false` | Inalterado | Inalterado |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool division_lenta(unsigned int a, unsigned int b, unsigned int *cociente, unsigned int *resto) {
    if (b == 0 || cociente == NULL || resto == NULL) {
        return false;
    }
    unsigned int q = 0;
    unsigned int r = a;
    while (r >= b) {
        r -= b;
        q++;
    }
    *cociente = q;
    *resto = r;
    return true;
}

int main(void) {
    unsigned int coc = 0;
    unsigned int res = 0;

    assert(division_lenta(14, 4, &coc, &res) && coc == 3 && res == 2);
    assert(division_lenta(20, 5, &coc, &res) && coc == 4 && res == 0);
    assert(division_lenta(3, 8, &coc, &res) && coc == 0 && res == 3);
    assert(!division_lenta(10, 0, &coc, &res));
    return 0;
}
```
::::
:::
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_03)=
### Ejercicio 1.03.03 - División Egipcia por Duplicaciones ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03_03_division_egipcia

Implementá el algoritmo histórico de división egipcia utilizando duplicaciones binarias y sustracciones, sin usar el operador de división `/`:
- `bool division_egipcia(unsigned int dividendo, unsigned int divisor, unsigned int *cociente, unsigned int *resto);`
- Retorna `false` si `divisor == 0` o si los punteros son `NULL`.
- Retorna `true` y carga el cociente y resto calculados.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Dividendo | Divisor | Retorno | `*cociente` | `*resto` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Exacta | `24` | `6` | `true` | `4` | `0` |
| Inexacta | `45` | `7` | `true` | `6` | `3` ($6 \times 7 + 3 = 45$) |
| Menor al divisor | `5` | `12` | `true` | `0` | `5` |
| Divisor cero | `10` | `0` | `false` | Inalterado | Inalterado |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool division_egipcia(unsigned int dividendo, unsigned int divisor, unsigned int *cociente, unsigned int *resto) {
    if (divisor == 0 || cociente == NULL || resto == NULL) {
        return false;
    }

    if (dividendo < divisor) {
        *cociente = 0;
        *resto = dividendo;
        return true;
    }

    unsigned int potencias[64];
    unsigned int multiplos[64];
    size_t k = 0;

    potencias[0] = 1;
    multiplos[0] = divisor;

    while (multiplos[k] <= dividendo && multiplos[k] <= (dividendo >> 1)) {
        potencias[k + 1] = potencias[k] << 1;
        multiplos[k + 1] = multiplos[k] << 1;
        k++;
    }

    unsigned int q = 0;
    unsigned int r = dividendo;

    for (size_t i = k + 1; i > 0; --i) {
        size_t idx = i - 1;
        if (multiplos[idx] <= r) {
            r -= multiplos[idx];
            q += potencias[idx];
        }
    }

    *cociente = q;
    *resto = r;
    return true;
}

int main(void) {
    unsigned int coc = 0;
    unsigned int res = 0;

    assert(division_egipcia(24, 6, &coc, &res) && coc == 4 && res == 0);
    assert(division_egipcia(45, 7, &coc, &res) && coc == 6 && res == 3);
    assert(division_egipcia(5, 12, &coc, &res) && coc == 0 && res == 5);
    assert(!division_egipcia(10, 0, &coc, &res));
    assert(!division_egipcia(10, 2, NULL, &res));

    return 0;
}
```
::::
:::

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Divisibilidad y Factores

(ej_b1_c03_04)=
### Ejercicio 1.03.04 - Divisibilidad ⭐⭐☆☆☆

#### Descripción
Determinar si un número entero `a` es divisible de forma exacta por otro entero
`b`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Dos enteros, `a` y `b`.
-   **Proceso:** La divisibilidad se comprueba con el operador módulo (`%`). Si
    el resto de la división `a % b` es 0, entonces `a` es divisible por `b`.
-   **Caso Especial:** Asegurarse de que `b` no sea cero para evitar un error de
    división por cero.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
END FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_05)=
### Ejercicio 1.03.05 - Factorial ⭐⭐☆☆☆

#### Descripción
Calcular el factorial de un número entero no negativo `n`, denotado como `n!`.
El factorial es el producto de todos los enteros positivos desde 1 hasta `n`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero no negativo `n`.
-   **Casos Base:** Por definición, `0! = 1`. El factorial de 1 es 1.
-   **Proceso:** Se utiliza un lazo que itera desde 2 hasta `n`. Se necesita una
    variable `resultado` (de tipo `long long` para evitar desbordamiento rápido)
    inicializada en 1. En cada iteración, se multiplica `resultado` por el
    número actual del lazo.
-   **Desbordamiento:** Los factoriales crecen muy rápido. Usar un tipo de dato
    grande como `unsigned long long` es crucial.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_06)=
### Ejercicio 1.03.06 - MCD y MCM ⭐⭐☆☆☆

#### Descripción
Implementar funciones para calcular el Máximo Común Divisor (MCD) y el Mínimo
Común Múltiplo (MCM) de dos números enteros.

:::{hint} Lógica y Consideraciones
-   **MCD (Algoritmo de Euclides):** Es el método más eficiente. Mientras `b` no
    sea cero, se calcula el resto `r = a % b`, luego se actualiza `a = b` y `b =
    r`. El MCD es el último valor no nulo de `a`.
-   **MCM:** Se puede calcular fácilmente una vez que se tiene el MCD, usando la
    fórmula: $MCM(a, b) = \frac{|a \cdot b|}{MCD(a, b)}$.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Propiedades de los Números

(ej_b1_c03_07)=
### Ejercicio 1.03.07 - Suma de dígitos ⭐⭐☆☆☆

#### Descripción
Calcular la suma de los dígitos individuales de un número entero positivo.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Se utiliza un lazo que se repite mientras `n` sea mayor que 0.
    1.  **Obtener último dígito:** `digito = n % 10`.
    2.  **Sumar dígito:** `suma = suma + digito`.
    3.  **Eliminar último dígito:** `n = n / 10` (división entera).
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_08)=
### Ejercicio 1.03.08 - Invertir un número ⭐⭐☆☆☆

#### Descripción
Tomar un número entero y devolver otro número con sus dígitos en orden inverso.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a la suma de dígitos, pero en lugar de sumar, se
    construye un nuevo número.
    1.  Inicializar `invertido = 0`.
    2.  En un lazo, mientras `n > 0`:
        a. `invertido = (invertido * 10) + (n % 10)`.
        b. `n = n / 10`.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_09)=
### Ejercicio 1.03.09 - Capicúas ⭐⭐⭐⭐☆

#### Descripción
Verificar si un número es capicúa (o palíndromo), es decir, si se lee igual de
izquierda a derecha que de derecha a izquierda.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** La forma más sencilla es utilizar la función del ejercicio
    anterior para invertir el número y luego comparar el número invertido con el
    original.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_capicua(n)
INICIO
    SI n == invertir_numero(n) ENTONCES
        RETORNAR VERDADERO
    SINO
        RETORNAR FALSO
    FIN SI
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_10)=
### Ejercicio 1.03.10 - Números Primos ⭐⭐☆☆☆

#### Descripción
Verificar si un número entero mayor que 1 es un número primo. Un número es primo
si solo es divisible por 1 y por sí mismo.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Casos Base:** Números menores o iguales a 1 no son primos. 2 es el único
    primo par.
-   **Proceso:** Para verificar si `n` es primo, basta con comprobar si es
    divisible por algún número desde 2 hasta la raíz cuadrada de `n`
    ($\sqrt{n}$). Si se encuentra un divisor en ese rango, el número no es
    primo.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_11)=
### Ejercicio 1.03.11 - Números Perfectos ⭐⭐☆☆☆

#### Descripción
Determinar si un número es un "número perfecto". Un número perfecto es un entero
positivo que es igual a la suma de sus divisores propios positivos (todos sus
divisores excepto él mismo).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Calcular la suma de los divisores propios de `n`. Para ello, iterar
        desde 1 hasta `n/2`.
    2.  En cada iteración, si el iterador `i` es un divisor de `n` (`n % i ==
        0`), se suma `i` a un acumulador.
    3.  Finalmente, comparar la suma obtenida con el número original `n`.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_12)=
### Ejercicio 1.03.12 - Números Amigos ⭐⭐☆☆☆

#### Descripción
Verificar si dos números enteros positivos, `a` y `b`, son "números amigos". Dos
números son amigos si la suma de los divisores propios de `a` es igual a `b`, y
viceversa.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Dos enteros positivos, `a` y `b`.
-   **Reutilización de Código:** Este problema se simplifica si ya se tiene una
    función que calcula la suma de los divisores propios de un número (como la
    usada en el ejercicio de "Números Perfectos").
-   **Proceso:** 
    1.  Calcular la suma de los divisores propios de `a`. Llamémosla
        `suma_div_a`.
    2.  Calcular la suma de los divisores propios de `b`. Llamémosla
        `suma_div_b`.
    3.  Verificar si se cumplen las dos condiciones: `suma_div_a == b` Y
        `suma_div_b == a`.
-   **Caso Especial:** Asegurarse de que `a` y `b` no sean el mismo número (un
    número perfecto es amigo de sí mismo, lo que a veces se excluye de la
    definición de números amigos).
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_13)=
### Ejercicio 1.03.13 - Números Abundantes ⭐⭐☆☆☆

#### Descripción
Determinar si un número es "abundante". Un número es abundante si la suma de sus
divisores propios es mayor que el propio número.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Es casi idéntico al de los números perfectos. Se calcula la
    suma de los divisores propios y, en lugar de comparar si es igual a `n`, se
    compara si es mayor que `n`.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_14)=
### Ejercicio 1.03.14 - Conjetura de Collatz ⭐⭐☆☆☆

#### Descripción
Implementar la secuencia de Collatz para un número inicial `n`. La secuencia se
genera aplicando repetidamente una regla: si el número actual es par, se divide
por 2; si es impar, se multiplica por 3 y se le suma 1. La conjetura (no
probada) es que esta secuencia siempre llega a 1.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Usar un lazo `while` que se ejecute mientras `n` sea diferente
    de 1. Dentro del lazo, aplicar la regla correspondiente y actualizar el
    valor de `n`. Imprimir el valor de `n` en cada paso para ver la secuencia.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
    ESCRIBIR 1 // El último término de la secuencia
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_15)=
### Ejercicio 1.03.15 - Números de Armstrong ⭐⭐☆☆☆

#### Descripción
Verificar si un número es un número de Armstrong (o narcisista). Un número de
`k` dígitos es de Armstrong si es igual a la suma de sus propios dígitos
elevados a la potencia `k`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Contar el número de dígitos (`k`) del número `n`.
    2.  Inicializar un acumulador `suma` en 0.
    3.  Recorrer los dígitos de `n` (usando `% 10` y `/ 10`). Para cada dígito,
        calcular `digito^k` y añadirlo a la `suma`.
    4.  Comparar la `suma` final con el número original `n`.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:

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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_16)=
### Ejercicio 1.03.16 - Números Felices ⭐⭐☆☆☆

#### Descripción
Determinar si un número es un "número feliz". El proceso consiste en reemplazar
el número por la suma de los cuadrados de sus dígitos repetidamente. Si el
proceso llega a 1, el número es feliz. Si entra en un ciclo que no incluye el 1
(notablemente el ciclo `4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4`), no es
feliz.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero positivo `n`.
-   **Proceso:** Usar un lazo `while`. En cada iteración, calcular la suma de
    los cuadrados de los dígitos del número actual. El lazo debe terminar si el
    número se convierte en 1 (feliz) o si se detecta un ciclo (no feliz). Para
    detectar ciclos, se puede guardar los números ya vistos en un arreglo o
    simplemente detectar si se llega al número 4.
    filas (*row-major order*) para mejorar el uso de caché.
    estrictamente dentro de los límites del contenedor.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Algoritmos Numéricos Avanzados

(ej_b1_c03_17)=
### Ejercicio 1.03.17 - Criba de Eratóstenes ⭐⭐☆☆☆

#### Descripción
Implementar la Criba de Eratóstenes, un algoritmo altamente eficiente para
encontrar todos los números primos hasta un límite superior $N$ especificado.

:::{hint} Lógica y Consideraciones
-   **Estructura de Datos:** Se necesita un arreglo booleano (o de enteros)
    `es_primo` de tamaño `N+1`. `es_primo[i]` será verdadero si `i` es primo y
    falso en caso contrario.
-   **Inicialización:** Se inicializa todo el arreglo a `verdadero`, asumiendo
    que todos los números son primos al principio. Luego, se marcan 0 y 1 como
    no primos.
-   **Proceso:** 
    1.  Se itera con un número `p` desde 2 hasta $\sqrt{N}$.
    2.  Si `p` sigue marcado como primo (`es_primo[p]` es verdadero):
        a. Se itera a través de todos los múltiplos de `p` (comenzando desde
        `p*p`) y se marcan como no primos (`es_primo[multiplo] = falso`). Se
        empieza en `p*p` porque los múltiplos menores ya habrán sido marcados
        por primos más pequeños.
-   **Salida:** Al final, se recorre el arreglo `es_primo` y se imprimen todos
    los índices `i` para los cuales `es_primo[i]` es verdadero.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO criba_eratostenes(N)
VARIABLES:
    es_primo (arreglo booleano de tamaño N+1)

INICIO
    // Inicialización
    PARA i DESDE 0 HASTA N HACER
        es_primo[i] = VERDADERO
    FIN PARA
    es_primo[0] = FALSO, es_primo[1] = FALSO

    // Marcado de múltiplos
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_18)=
### Ejercicio 1.03.18 - Descomposición en Factores Primos ⭐⭐☆☆☆

#### Descripción
Dado un número entero, encontrar y mostrar su descomposición en factores primos.
Por ejemplo, para 360, la salida sería `2^3 * 3^2 * 5`.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Se itera con un divisor `d` comenzando en 2.
    2.  Mientras `d*d <= n`, se verifica si `d` divide a `n`.
    3.  Si `d` divide a `n`, se cuenta cuántas veces lo divide, se imprime el
        factor y su potencia, y se actualiza `n` dividiéndolo por `d` esa
        cantidad de veces.
    4.  Si al final del lazo `n` es mayor que 1, ese `n` restante es también un
        factor primo.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_19)=
### Ejercicio 1.03.19 - Números de Catalan ⭐⭐☆☆☆

#### Descripción
Implementar una función que calcule el n-ésimo número de Catalan, $C_n$. Estos
números forman una secuencia de números naturales que aparece en varios
problemas de conteo en combinatoria.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero no negativo `n`.
-   **Fórmula:** La fórmula más directa es $C_n = \frac{1}{n+1} \binom{2n}{n}$.
    Para calcularla, se necesita una función para el coeficiente binomial
    $\binom{n}{k}$.
-   **Coeficiente Binomial:** $\binom{n}{k}$ se puede calcular como
    $\frac{n!}{k!(n-k)!}$. Sin embargo, calcular los factoriales directamente
    puede causar desbordamiento muy rápido. Una forma más segura es calcularlo
    iterativamente: $\binom{n}{k} = \prod_{i=1}^{k} \frac{n-i+1}{i}$.
-   **Proceso:** 
    1.  Implementar una función `coeficiente_binomial(n, k)`.
    2.  La función `numero_catalan(n)` llamará a `coeficiente_binomial(2*n, n)`
        y dividirá el resultado por `n+1`.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_20)=
### Ejercicio 1.03.20 - Coeficiente Binomial ⭐⭐☆☆☆

#### Descripción
Calcular el coeficiente binomial "n en k", denotado como $C(n, k)$ o
$\binom{n}{k}$, que representa el número de formas de elegir `k` elementos de un
conjunto de `n` elementos sin importar el orden.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Dos enteros no negativos, `n` y `k`.
-   **Proceso:** Como se mencionó en el ejercicio anterior, calcularlo mediante
    la fórmula iterativa $\prod_{i=1}^{k} \frac{n-i+1}{i}$ es numéricamente más
    estable que usar factoriales. Es importante realizar la multiplicación antes
    de la división en cada paso para mantener la precisión y evitar divisiones
    prematuras.
-   **Optimización:** Dado que $\binom{n}{k} = \binom{n}{n-k}$, se puede elegir
    el valor más pequeño entre `k` y `n-k` para reducir el número de
    iteraciones.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_21)=
### Ejercicio 1.03.21 - Raíz Cuadrada Entera (Método Babilónico) ⭐⭐☆☆☆

#### Descripción
Implementar un algoritmo para calcular la parte entera de la raíz cuadrada de un
número `n` utilizando el método babilónico (o de Herón), que es un método
iterativo eficiente.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número no negativo `n`.
-   **Proceso:** Es un algoritmo de aproximaciones sucesivas.
    1.  Se elige una estimación inicial `x` (por ejemplo, `x = n`).
    2.  Se repite un número fijo de veces o hasta que la estimación converja: `x
        = (x + n / x) / 2`.
-   **Salida:** El resultado es la parte entera de la estimación final `x`.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_22)=
### Ejercicio 1.03.22 - Números Triangulares ⭐⭐☆☆☆

#### Descripción
Un número triangular es la suma de los `n` primeros números naturales. Por
ejemplo, el 4º número triangular es 1+2+3+4=10. El objetivo es escribir una
función que determine si un número entero dado es un número triangular.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero positivo `num`.
-   **Proceso:** Hay dos enfoques principales:
    1.  **Iterativo:** Generar números triangulares sumando 1, 2, 3, ... en un
        acumulador. En cada paso, comparar el acumulador con `num`. Si son
        iguales, es triangular. Si el acumulador supera a `num`, no lo es.
    2.  **Matemático:** Un número `x` es triangular si y solo si $8x+1$ es un
        cuadrado perfecto. Se puede calcular $8x+1$, obtener su raíz cuadrada, y
        verificar si es un entero.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_23)=
### Ejercicio 1.03.23 - Conjetura de Goldbach ⭐⭐☆☆☆

#### Descripción
La conjetura de Goldbach (aún no probada) establece que todo número par mayor
que 2 puede expresarse como la suma de dos números primos. Escribir un programa
que, dado un número par, encuentre un par de números primos que lo sumen.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número entero par `n` > 2.
-   **Proceso:** 
    1.  Se necesita una función `es_primo(x)`.
    2.  Iterar con un número `p` desde 2 hasta `n/2`.
    3.  En cada iteración, si `p` es primo, verificar si `n-p` también es primo.
    4.  Si ambos lo son, se ha encontrado un par y se puede terminar.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_24)=
### Ejercicio 1.03.24 - Primos Gemelos ⭐⭐☆☆☆

#### Descripción
Dos números primos `p` y `q` son gemelos si `q = p + 2`. El programa debe
encontrar todos los pares de primos gemelos hasta un límite $N$.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un límite superior $N$.
-   **Proceso:** 
    1.  Iterar con un número `p` desde 2 hasta `N-2`.
    2.  En cada iteración, verificar si tanto `p` como `p+2` son primos.
    3.  Si ambos lo son, se ha encontrado un par de primos gemelos.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO primos_gemelos(N)
INICIO
    PARA p DESDE 2 HASTA N - 2 HACER
        SI es_primo(p) Y es_primo(p + 2) ENTONCES
            ESCRIBIR "(", p, ", ", p + 2, ")"
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_25)=
### Ejercicio 1.03.25 - Identidad de Bézout ⭐⭐☆☆☆

#### Descripción
Extender el Algoritmo de Euclides para encontrar no solo el MCD de dos enteros
`a` y `b`, sino también dos enteros `x` e `y` que satisfacen la identidad de
Bézout: $ax + by = mcd(a, b)$.

:::{hint} Lógica y Consideraciones
-   **Algoritmo Extendido de Euclides:** Es una modificación del algoritmo de
    Euclides que mantiene un registro de los coeficientes `x` e `y` en cada
    paso. Es inherentemente recursivo.
-   **Proceso:** La implementación recursiva es más intuitiva. La llamada
    recursiva devuelve el MCD y los coeficientes para los números más pequeños,
    y la llamada actual los ajusta para los números originales.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_26)=
### Ejercicio 1.03.26 - Cálculo de Pi (Serie de Leibniz) ⭐⭐☆☆☆

#### Descripción
Aproximar el valor de $\pi$ utilizando la serie de Leibniz. La función debe
recibir el número de términos a utilizar para la aproximación.

:::{hint} Lógica y Consideraciones
-   **Fórmula:** $\pi = 4 \sum_{k=0}^{\infty} \frac{(-1)^k}{2k+1} = 4 (1 -
    \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \dots)$
-   **Proceso:** 
    1.  Inicializar una variable `suma` a 0.
    2.  Iterar `k` desde 0 hasta el número de términos deseado.
    3.  En cada iteración, calcular el término $\frac{(-1)^k}{2k+1}$ y añadirlo
        a `suma`.
    4.  El resultado final es `4 * suma`.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_27)=
### Ejercicio 1.03.27 - Números de Lucas ⭐⭐☆☆☆

#### Descripción
Generar los primeros `n` términos de la secuencia de Lucas. Es una secuencia
similar a la de Fibonacci, pero comienza con 2 y 1.

:::{hint} Lógica y Consideraciones
-   **Definición:** $L_n = L_{n-1} + L_{n-2}$ con $L_0 = 2$ y $L_1 = 1$.
-   **Proceso:** La implementación es casi idéntica a la de Fibonacci, solo
    cambian los valores iniciales.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_28)=
### Ejercicio 1.03.28 - Números de Mersenne ⭐⭐☆☆☆

#### Descripción
Un número de Mersenne es un número de la forma $M_p = 2^p - 1$, donde `p` es un
número primo. El programa debe generar números de Mersenne y verificar si son a
su vez primos (primos de Mersenne).

:::{hint} Lógica y Consideraciones
-   **Proceso:** 
    1.  Generar números primos `p` (usando la criba o la función `es_primo`).
    2.  Para cada primo `p`, calcular $M_p = 2^p - 1$.
    3.  Verificar si el $M_p$ resultante es también primo.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_29)=
### Ejercicio 1.03.29 - Test de Primalidad de Miller-Rabin ⭐⭐☆☆☆

#### Descripción
Implementar una versión simplificada del test de primalidad de Miller-Rabin. Es
un test probabilístico que, a diferencia de la división por tentativa, es
eficiente para números grandes.

:::{hint} Lógica y Consideraciones
-   **Teorema:** Se basa en propiedades de los números primos relacionadas con
    el Pequeño Teorema de Fermat. Es más complejo que los algoritmos anteriores.
-   **Proceso Simplificado:** 
    1.  Dado un número `n` a probar, se eligen varias bases aleatorias `a` <
        `n`.
    2.  Para cada base `a`, se comprueba si satisface ciertas congruencias. Si
        para alguna base no las satisface, `n` es compuesto. Si las satisface
        para todas las bases, es "probablemente primo".
-   **Nota:** La implementación completa es avanzada. Un ejercicio más simple
    puede ser implementarlo para una sola base fija.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_30)=
### Ejercicio 1.03.30 - Números Vampiro ⭐⭐☆☆☆

#### Descripción
Un número vampiro es un número de `2k` dígitos que puede ser factorizado en dos
números de `k` dígitos (los "colmillos"), donde los dígitos de los colmillos,
concatenados, son una permutación de los dígitos del número original.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un número `n` de 4 dígitos.
-   **Proceso:** 
    1.  Iterar a través de todos los posibles pares de "colmillos" de 2 dígitos
        (`i` y `j`).
    2.  Verificar si `i * j == n`.
    3.  Si es así, obtener los 4 dígitos de `n` y los 4 dígitos de `i` y `j`.
    4.  Verificar si los dos conjuntos de dígitos son permutaciones el uno del
        otro (ej. ordenándolos y comparando).
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_31)=
### Ejercicio 1.03.31 - Cuadrado Mágico ⭐⭐☆☆☆

#### Descripción
Verificar si una matriz cuadrada `n x n` de números es un cuadrado mágico. Un
cuadrado mágico es una matriz donde la suma de los números de cada fila, cada
columna y ambas diagonales principales es la misma ("constante mágica").

:::{hint} Lógica y Consideraciones
-   **Entrada:** Una matriz `n x n`.
-   **Proceso:** 
    1.  Calcular la suma de la primera fila y guardarla como la
        `constante_magica` de referencia.
    2.  Iterar por las demás filas, calculando su suma y comparándola con la
        `constante_magica`.
    3.  Iterar por todas las columnas, calculando su suma y comparándola.
    4.  Calcular la suma de la diagonal principal y la diagonal secundaria y
        compararlas.
-   Si todas las sumas son iguales, es un cuadrado mágico.
    filas (*row-major order*) para mejorar el uso de caché.
    estrictamente dentro de los límites del contenedor.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

## Más Teoría de Números y Algoritmos

(ej_b1_c03_32)=
### Ejercicio 1.03.32 - Números de Smith ⭐⭐☆☆☆

#### Descripción
Un número de Smith es un número compuesto cuya suma de dígitos es igual a la
suma de los dígitos de sus factores primos. El programa debe verificar si un
número dado es un número de Smith.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** 
    1.  Verificar que `n` no sea primo.
    2.  Calcular la suma de los dígitos de `n`.
    3.  Obtener los factores primos de `n`.
    4.  Calcular la suma de los dígitos de todos los factores primos. Si un
        factor tiene más de un dígito (ej. 13), se deben sumar sus dígitos
        individuales (1+3).
    5.  Comparar las dos sumas.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_33)=
### Ejercicio 1.03.33 - Primos de Sophie Germain ⭐⭐☆☆☆

#### Descripción
Un número primo `p` es un primo de Sophie Germain si `2p + 1` también es un
número primo. El programa debe encontrar todos los primos de Sophie Germain
hasta un límite $N$.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un límite superior $N$.
-   **Proceso:** 
    1.  Iterar con un número `p` desde 2 hasta $N$.
    2.  En cada iteración, verificar si `p` es primo.
    3.  Si `p` es primo, calcular `q = 2*p + 1` y verificar si `q` también es
        primo.
    4.  Si ambos son primos, `p` es un primo de Sophie Germain.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO primos_sophie_germain(N)
INICIO
    PARA p DESDE 2 HASTA N HACER
        SI es_primo(p) Y es_primo(2*p + 1) ENTONCES
            ESCRIBIR p
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_34)=
### Ejercicio 1.03.34 - Función φ de Euler (Totient) ⭐⭐☆☆☆

#### Descripción
Implementar una función que calcule el Totient de Euler, `φ(n)`. Esta función
cuenta el número de enteros positivos hasta `n` que son coprimos con `n` (es
decir, `mcd(k, n) = 1` para `1 <= k <= n`).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso (simple):** Iterar `k` desde 1 hasta `n` y contar cuántas veces
    `mcd(k, n) == 1`.
-   **Proceso (eficiente):** Usar la fórmula basada en los factores primos de
    `n`: $\phi(n) = n \prod_{p|n, p \text{ es primo}} (1 - \frac{1}{p})$.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_35)=
### Ejercicio 1.03.35 - Radical de un Número ⭐⭐☆☆☆

#### Descripción
Calcular el radical de un número `n`, denotado como `rad(n)`, que es el producto
de sus factores primos distintos.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a la descomposición en factores primos, pero en lugar
    de contar potencias, simplemente se multiplica cada factor primo distinto
    encontrado a una variable `resultado`.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_36)=
### Ejercicio 1.03.36 - Secuencia de Tribonacci ⭐⭐☆☆☆

#### Descripción
Generar los primeros `n` términos de la secuencia de Tribonacci, donde cada
término es la suma de los tres anteriores. La secuencia puede comenzar de
diferentes formas, una común es `0, 1, 1, 2, 4, 7, 13, ...`

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un entero `n`.
-   **Proceso:** Similar a Fibonacci, pero se necesitan tres variables para
    guardar los tres términos anteriores.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO tribonacci(n)
VARIABLES:
    a, b, c, siguiente (enteros)
INICIO
    a=0, b=1, c=1
    // Imprimir los primeros términos según n
    PARA i DESDE 4 HASTA n HACER
        siguiente = a + b + c
        ESCRIBIR siguiente
        a = b, b = c, c = siguiente
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_37)=
### Ejercicio 1.03.37 - Fracciones Egipcias ⭐⭐☆☆☆

#### Descripción
Escribir una función que descomponga una fracción propia `a/b` en una suma de
fracciones unitarias distintas (fracciones con numerador 1).

:::{hint} Lógica y Consideraciones
-   **Algoritmo Greedy:** Un método común es encontrar repetidamente la fracción
    unitaria más grande que sea menor o igual a la fracción restante.
-   **Proceso:** 
    1.  Dada la fracción `num/den`.
    2.  Encontrar el denominador `d` de la siguiente fracción unitaria: `d =
        techo(den / num)`.
    3.  Imprimir `1/d`.
    4.  Actualizar la fracción restante: `num/den = num/den - 1/d`.
    5.  Repetir hasta que `num` sea 0.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_38)=
### Ejercicio 1.03.38 - Ternas Pitagóricas ⭐⭐☆☆☆

#### Descripción
Implementar un programa que genere todas las ternas pitagóricas primitivas (`a^2
+ b^2 = c^2`, con `mcd(a,b,c)=1`) hasta un cierto límite para `c`, utilizando la
fórmula de Euclides.

:::{hint} Lógica y Consideraciones
-   **Fórmula de Euclides:** Todas las ternas primitivas se pueden generar a
    partir de dos enteros `m > n > 0`, coprimos y de paridad opuesta, usando las
    fórmulas:
    -   `a = m^2 - n^2`
    -   `b = 2mn`
    -   `c = m^2 + n^2`
-   **Proceso:** Iterar con `m` y `n` bajo las condiciones dadas y generar `a`,
    `b` y `c`.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_39)=
### Ejercicio 1.03.39 - Números de Carmichael ⭐⭐☆☆☆

#### Descripción
Un número de Carmichael es un número que satisface la congruencia $b^{n-1}
\equiv 1 \pmod{n}$ para todos los enteros `b` coprimos con `n`. Escribir una
función que verifique si un número es un número de Carmichael.

:::{hint} Lógica y Consideraciones
-   **Proceso:** 
    1.  Verificar si `n` es compuesto (no es primo).
    2.  Iterar con `b` desde 2 hasta `n-1`.
    3.  Si `mcd(b, n) == 1`, verificar si `potencia_modular(b, n-1, n) != 1`.
    4.  Si se encuentra un `b` que no cumple la condición, `n` no es de
        Carmichael. Si se prueban todos y la cumplen, sí lo es.
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_40)=
### Ejercicio 1.03.40 - Logaritmo Entero ⭐⭐☆☆☆

#### Descripción
Calcular el logaritmo entero en base `b` de un número `n`. Es el mayor entero
`k` tal que $b^k \le n$. La implementación no debe usar funciones de `math.h`.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Se puede resolver con divisiones sucesivas.
    1.  Inicializar `k = 0`.
    2.  Mientras `n >= b`, dividir `n` por `b` e incrementar `k`.
    3.  El valor final de `k` es el resultado.
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b1_c03_41)=
### Ejercicio 1.03.41 - Conversión de Base Numérica ⭐⭐☆☆☆

#### Descripción
Escribir una función que convierta un número `n` de una base `b1` a una base
`b2`.

:::{hint} Lógica y Consideraciones
-   **Proceso en dos pasos:** El método más simple es:
    1.  **Convertir a base 10:** Convertir el número de su base original `b1` a
        base 10. Si el número está en un arreglo de dígitos, se calcula $\sum
        digito_i \cdot b1^i$.
    2.  **Convertir de base 10:** Convertir el número de base 10 a la base de
        destino `b2` usando divisiones sucesivas y guardando los restos.
    filas (*row-major order*) para mejorar el uso de caché.
    estrictamente dentro de los límites del contenedor.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
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
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->
