---
title: "Ejercicios de Cadenas"
short_title: "4. Cadenas"
---

# Ejercicios de Cadenas

## Acerca de

La manipulación de cadenas es una de las tareas más comunes y, en C, una de las
más propensas a errores. Estos ejercicios están diseñados para construir una
base sólida en el manejo de cadenas de caracteres (estilo C, terminadas en
nulo `\0`), enfocándose en la implementación de algoritmos comunes desde cero. Es
crucial que al resolverlos, se apliquen los principios de manejo de "cadenas
seguras" ({ref}`0x5003h`), pasando siempre la capacidad del búfer para evitar
desbordamientos.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-cadenas`
- {ref}`capitulo-arreglos`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Representación contigua en memoria de cadenas terminadas en byte nulo (`'\0'`).
2. Calificador `const char *` para cadenas de solo lectura y prevención de mutación de literales.
3. Diferencia entre longitud de texto (`strlen`) y capacidad física del búfer receptor.
4. Funciones de clasificación y conversión de caracteres (`<ctype.h>`: `tolower`, `isalpha`).

### Cuestiones de Estilo Aplicables
- **Seguridad en Búferes:** Al escribir sobre una cadena de destino, la función
  debe recibir explícitamente el parámetro `size_t capacidad_maxima` y garantizar
  la terminación en `\0` bajo cualquier circunstancia ({ref}`0x5003h`).
- **Punteros de lectura const:** Toda cadena fuente que no deba modificarse debe
  ser calificada como `const char *str`.

---

## Análisis de Cadenas

(ej_b2_c03b_01)=
### Ejercicio 2.03b.01 - Contar Vocales ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c03b_01_vocales

Escribí una función pura que cuente el número total de vocales (`'a'`, `'e'`,
`'i'`, `'o'`, `'u'`) en una cadena ASCII, sin distinguir entre mayúsculas y
minúsculas.

```c
size_t contar_vocales(const char *cadena);
```

**Tabla de Vectores de Prueba:**

| Cadena de Entrada | Salida Esperada | Comentario |
| :--- | :--- | :--- |
| `"Hola Mundo"` | `4` | Coincidencias: 'o', 'a', 'u', 'o' |
| `"AEIOU aeiou"` | `10` | Mayúsculas y minúsculas indistintas |
| `"Rhythm & Crypts"` | `0` | Cero vocales en el texto |
| `""` | `0` | Cadena vacía inmediata |
| `NULL` | `0` | Puntero nulo seguro |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <assert.h>

size_t contar_vocales(const char *cadena) {
    if (cadena == NULL) {
        return 0;
    }
    size_t contador = 0;
    for (size_t i = 0; cadena[i] != '\0'; ++i) {
        char c = (char)tolower((unsigned char)cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

int main(void) {
    assert(contar_vocales("Hola Mundo") == 4);
    assert(contar_vocales("AEIOU aeiou") == 10);
    assert(contar_vocales("Rhythm & Crypts") == 0);
    assert(contar_vocales("") == 0);
    assert(contar_vocales(NULL) == 0);
    return 0;
}
```
::::
:::

(ej_b2_c03b_02)=
### Ejercicio 2.03b.02 - Contabilizador de Caracteres y Frecuencia ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c03b_02_contabilizador

Implementá una función pura que compute el histograma de frecuencias de caracteres ASCII en una cadena:
```c
void contar_frecuencias_ascii(const char *cadena, size_t frecuencias[256]);
```

**Tabla de Vectores de Prueba:**

| Cadena de Entrada | Consulta de Frecuencia | Resultado Esperado |
| :--- | :--- | :--- |
| `"banana"` | `'a'`, `'n'`, `'b'` | `'a'=3, 'n'=2, 'b'=1` |
| `""` (vacía) | Cualquier carácter | `0` para todas las entradas |
| `NULL` | Cualquier carácter | Seguro ante `NULL`, sin alteraciones |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

void contar_frecuencias_ascii(const char *cadena, size_t frecuencias[256]) {
    if (frecuencias == NULL) {
        return;
    }
    memset(frecuencias, 0, 256 * sizeof(size_t));
    if (cadena == NULL) {
        return;
    }
    for (size_t i = 0; cadena[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)cadena[i];
        frecuencias[c]++;
    }
}

int main(void) {
    size_t f[256];
    contar_frecuencias_ascii("banana", f);
    assert(f[(unsigned char)'a'] == 3);
    assert(f[(unsigned char)'n'] == 2);
    assert(f[(unsigned char)'b'] == 1);
    assert(f[(unsigned char)'z'] == 0);

    contar_frecuencias_ascii("", f);
    for (size_t i = 0; i < 256; ++i) {
        assert(f[i] == 0);
    }

    contar_frecuencias_ascii(NULL, f);
    for (size_t i = 0; i < 256; ++i) {
        assert(f[i] == 0);
    }

    return 0;
}
```
::::
:::

(ej_b2_c03b_03)=
### Ejercicio 2.03b.03 - b.3 - ¿Es un número válido? ⭐⭐☆☆☆

#### Descripción
Desarrollar una función que verifique si una cadena de texto representa un
número de punto flotante válido. La validación debe seguir un conjunto de reglas
específicas.

:::{tip} Lógica y Consideraciones

-   **Reglas de Validación:**
    1.  Puede tener un signo opcional (`+` o `-`) únicamente al principio.
    2.  Debe contener al menos un dígito.
    3.  Puede contener como máximo un punto decimal (`.`).
    4.  Todos los demás caracteres deben ser dígitos (`0`-`9`).
-   **Proceso:**
    1.  Recorrer la cadena carácter por carácter.
    2.  Usar banderas (variables booleanas) para llevar un registro de si ya se
        encontró un punto decimal.
    3.  Manejar el signo solo en la primera posición.
    4.  Verificar que cada carácter sea un dígito o un punto (en la posición
        correcta).

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_numero_valido(cadena)
VARIABLES:
    tiene_punto (booleano)
    tiene_digito (booleano)
    i (entero)
INICIO
    tiene_punto = FALSO, tiene_digito = FALSO
    i = 0

    // Comprobar signo opcional
    SI cadena[0] == '+' O cadena[0] == '-' ENTONCES
        i = 1
    FIN SI

    // Recorrer el resto de la cadena
    MIENTRAS cadena[i] != FIN_DE_CADENA HACER
        SI es_digito(cadena[i]) ENTONCES
            tiene_digito = VERDADERO
        SINO SI cadena[i] == '.' ENTONCES
            SI tiene_punto ENTONCES RETORNAR FALSO // Más de un punto
            tiene_punto = VERDADERO
        SINO
            RETORNAR FALSO // Carácter no válido
        FIN SI
        i = i + 1
    FIN MIENTRAS

    RETORNAR tiene_digito // Debe tener al menos un dígito
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_04)=
### Ejercicio 2.03b.04 - b.4 - ¿Es alfabética? ⭐⭐☆☆☆

#### Descripción
Crear una función que determine si una cadena contiene únicamente caracteres
alfabéticos (de la 'a' a la 'z', mayúsculas o minúsculas).

:::{tip} Lógica y Consideraciones

-   **Proceso:** Recorrer la cadena. Para cada carácter, verificar si está
    dentro del rango de 'a' a 'z' o de 'A' a 'Z'.
-   **Funciones de Biblioteca:** La biblioteca `ctype.h` proporciona la función
    `isalpha()`, que simplifica enormemente esta comprobación.
-   **Condición de Salida:** Si se encuentra un carácter que no es alfabético,
    la función puede retornar `falso` inmediatamente. Si el lazo termina,
    significa que todos los caracteres son alfabéticos.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_alfabetica(cadena)
INICIO
    PARA cada caracter c en cadena HACER
        SI NO es_letra(c) ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Propiedades de Cadenas

(ej_b2_c03b_05)=
### Ejercicio 2.03b.05 - b.5 - Palíndromo ⭐⭐☆☆☆

#### Descripción
Implementar una función que verifique si una cadena es un palíndromo, es decir,
si se lee igual de izquierda a derecha que de derecha a izquierda. La
verificación debe ignorar espacios en blanco y no debe ser sensible a
mayúsculas/minúsculas.

:::{tip} Lógica y Consideraciones

-   **Entrada:** Una cadena de caracteres.
-   **Proceso (dos punteros/índices):**
    1.  Usar dos índices: `izquierda` al inicio de la cadena y `derecha` al
        final.
    2.  En un lazo `while (izquierda < derecha)`:
        a. Mover `izquierda` hacia la derecha hasta que apunte a un carácter
        alfabético.
        b. Mover `derecha` hacia la izquierda hasta que apunte a un carácter
        alfabético.
        c. Comparar los caracteres en `izquierda` y `derecha` (convertidos a
        minúsculas). Si son diferentes, la cadena no es un palíndromo y se puede
        retornar `falso`.
        d. Si son iguales, mover ambos punteros hacia el centro (`izquierda++`,
        `derecha--`).
-   **Salida:** Si el lazo termina, significa que todos los caracteres
    coincidieron, por lo que es un palíndromo y se retorna `verdadero`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_palindromo_complejo(cadena)
VARIABLES:
    izquierda, derecha (enteros)
INICIO
    izquierda = 0, derecha = LONGITUD(cadena) - 1
    MIENTRAS izquierda < derecha HACER
        MIENTRAS NO es_alfabetico(cadena[izquierda]) Y izquierda < derecha HACER
            izquierda = izquierda + 1
        FIN MIENTRAS
        MIENTRAS NO es_alfabetico(cadena[derecha]) Y izquierda < derecha HACER
            derecha = derecha - 1
        FIN MIENTRAS

        SI convertir_a_minuscula(cadena[izquierda]) != convertir_a_minuscula(cadena[derecha]) ENTONCES
            RETORNAR FALSO
        FIN SI
        izquierda = izquierda + 1
        derecha = derecha - 1
    FIN MIENTRAS
    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_06)=
### Ejercicio 2.03b.06 - b.6 - Anagrama ⭐⭐☆☆☆

#### Descripción
Escribir una función que determine si una cadena es un anagrama de otra (es
decir, si ambas tienen los mismos caracteres con la misma frecuencia), ignorando
mayúsculas/minúsculas y espacios.

:::{tip} Lógica y Consideraciones

-   **Proceso (Arreglo de Frecuencias):**
    1.  Crear un arreglo de contadores de 26 posiciones (para el alfabeto),
        inicializado en cero.
    2.  Recorrer la primera cadena. Para cada carácter alfabético, incrementar
        el contador correspondiente (ej. para 'c', `contadores[2]++`).
    3.  Recorrer la segunda cadena. Para cada carácter alfabético, decrementar
        el contador correspondiente.
    4.  Finalmente, recorrer el arreglo de contadores. Si todos los contadores
        son cero, las cadenas son anagramas.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION son_anagramas(cadena1, cadena2)
VARIABLES:
    frecuencias (arreglo de 26 enteros)
INICIO
    INICIALIZAR frecuencias con ceros

    PARA cada caracter c en cadena1 HACER
        SI es_alfabetico(c) ENTONCES
            frecuencias[posicion_alfabeto(c)]++
        FIN SI
    FIN PARA

    PARA cada caracter c en cadena2 HACER
        SI es_alfabetico(c) ENTONCES
            frecuencias[posicion_alfabeto(c)]--
        FIN SI
    FIN PARA

    PARA i DESDE 0 HASTA 25 HACER
        SI frecuencias[i] != 0 RETORNAR FALSO
    FIN PARA

    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_07)=
### Ejercicio 2.03b.07 - b.7 - Pangrama ⭐⭐☆☆☆

#### Descripción
Verificar si una cadena es un pangrama, es decir, si contiene todas las letras
del alfabeto inglés al menos una vez. La verificación debe ser insensible a
mayúsculas/minúsculas.

:::{tip} Lógica y Consideraciones

-   **Estructura de Datos:** Un arreglo booleano de 26 posiciones
    (`letras_vistas`) es perfecto para este fin.
-   **Proceso:**
    1.  Inicializar el arreglo `letras_vistas` en `falso`.
    2.  Recorrer la cadena. Para cada carácter, si es una letra, marcar la
        posición correspondiente en el arreglo como `verdadero`.
    3.  Después de recorrer la cadena, verificar si todas las posiciones del
        arreglo `letras_vistas` son `verdadero`. Si es así, es un pangrama.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_pangrama(cadena)
VARIABLES:
    letras_vistas (arreglo booleano de 26 posiciones)
INICIO
    INICIALIZAR letras_vistas con FALSO

    PARA cada caracter c en cadena HACER
        SI es_alfabetico(c) ENTONCES
            letras_vistas[posicion_alfabeto(c)] = VERDADERO
        FIN SI
    FIN PARA

    PARA i DESDE 0 HASTA 25 HACER
        SI letras_vistas[i] == FALSO RETORNAR FALSO
    FIN PARA

    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Manipulación y Transformación

(ej_b2_c03b_08)=
### Ejercicio 2.03b.08 - b.8 - Tokenización ⭐⭐☆☆☆

#### Descripción
Dividir una cadena en una secuencia de "tokens" (subcadenas) basándose en un
carácter delimitador. La función `strtok` de C es un ejemplo clásico de esto.

:::{tip} Lógica y Consideraciones

-   **Modificación _in-place_:** `strtok` funciona modificando la cadena
    original. Reemplaza el delimitador encontrado por un carácter nulo (`\0`),
    terminando así el token actual, y guarda un puntero interno para saber dónde
    continuar la próxima vez.
-   **Proceso (simplificado):**
    1.  En la primera llamada, se pasa la cadena. La función busca el primer
        delimitador.
    2.  Reemplaza el delimitador por `\0`.
    3.  Guarda la posición siguiente al `\0` en un puntero estático.
    4.  Devuelve el puntero al inicio del token.
    5.  En llamadas subsiguientes con `NULL`, la función usa el puntero estático
        para continuar desde donde se quedó.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION mi_strtok(cadena, delimitador)
VARIABLES ESTATICAS:
    ultimo_puntero
INICIO
    SI cadena != NULL ENTONCES
        ultimo_puntero = cadena
    FIN SI

    SI *ultimo_puntero == FIN_DE_CADENA RETORNAR NULL

    token_inicio = ultimo_puntero
    MIENTRAS *ultimo_puntero != delimitador Y *ultimo_puntero != FIN_DE_CADENA HACER
        ultimo_puntero++
    FIN MIENTRAS

    SI *ultimo_puntero != FIN_DE_CADENA ENTONCES
        *ultimo_puntero = '\0'
        ultimo_puntero++
    FIN SI

    RETORNAR token_inicio
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_09)=
### Ejercicio 2.03b.09 - b.9 - Compresión RLE (Run-Length Encoding) ⭐⭐☆☆☆

#### Descripción
Implementar una forma simple de compresión de cadenas llamada Run-Length
Encoding. Esta técnica compacta una cadena reemplazando secuencias de caracteres
idénticos por el número de repeticiones seguido del carácter.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Mantener un `contador` para el carácter actual.
    3.  Si el siguiente carácter es diferente o se llega al final de la cadena,
        se añade el `contador` y el carácter actual a la cadena de resultado.
    4.  Reiniciar el `contador` y continuar.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION comprimir_rle(cadena)
VARIABLES:
    resultado (cadena)
    contador, i (enteros)
INICIO
    i = 0
    MIENTRAS i < LONGITUD(cadena) HACER
        contador = 1
        MIENTRAS i+1 < LONGITUD(cadena) Y cadena[i] == cadena[i+1] HACER
            contador++, i++
        FIN MIENTRAS
        AÑADIR numero_a_cadena(contador) a resultado
        AÑADIR cadena[i] a resultado
        i++
    FIN MIENTRAS
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_10)=
### Ejercicio 2.03b.10 - b.10 - Desduplicador ⭐⭐☆☆☆

#### Descripción
Escribir una función que elimine los caracteres duplicados de una cadena,
conservando únicamente la primera aparición de cada carácter. La modificación
puede ser _in-place_.

:::{tip} Lógica y Consideraciones

-   **Estructura de Datos:** Se necesita una forma de registrar los caracteres
    que ya se han visto. Un arreglo booleano de 256 posiciones (`vistos`) es
    ideal para esto, donde cada índice corresponde a un código ASCII.
-   **Proceso (in-place):**
    1.  Utilizar dos punteros o índices: `puntero_lectura` y
        `puntero_escritura`, ambos comenzando al inicio de la cadena.
    2.  Recorrer la cadena con `puntero_lectura`.
    3.  Para cada carácter `c` leído:
        a. Verificar en el arreglo `vistos` si ya ha aparecido
        (`vistos[(int)c]`).
        b. Si no ha sido visto, copiarlo a la posición de `puntero_escritura`,
        marcarlo como visto (`vistos[(int)c] = VERDADERO`), y avanzar
        `puntero_escritura`.
    4.  Al final, colocar el carácter nulo `\0` en la posición de
        `puntero_escritura`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO desduplicar(REF cadena)
VARIABLES:
    vistos (arreglo booleano de 256)
    p_lectura, p_escritura (enteros)
INICIO
    INICIALIZAR vistos con FALSO
    p_lectura = 0, p_escritura = 0

    MIENTRAS cadena[p_lectura] != FIN_DE_CADENA HACER
        caracter_actual = cadena[p_lectura]
        SI vistos[CODIGO_ASCII(caracter_actual)] == FALSO ENTONCES
            vistos[CODIGO_ASCII(caracter_actual)] = VERDADERO
            cadena[p_escritura] = caracter_actual
            p_escritura++
        FIN SI
        p_lectura++
    FIN MIENTRAS
    cadena[p_escritura] = FIN_DE_CADENA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_11)=
### Ejercicio 2.03b.11 - b.11 - Número a cadena con formato ⭐⭐⭐☆☆

#### Descripción
Transformar un número entero largo en una cadena de texto, insertando
separadores de miles (puntos o comas) para mejorar la legibilidad.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Convertir el número a una cadena simple primero (usando `sprintf` o un
        algoritmo manual).
    2.  Calcular cuántos separadores se necesitan.
    3.  Crear una nueva cadena con el tamaño suficiente para albergar los
        dígitos y los separadores.
    4.  Copiar los dígitos de la cadena original a la nueva, insertando los
        separadores en las posiciones correctas. Es más fácil hacerlo de derecha
        a izquierda.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION formatear_numero(numero)
VARIABLES:
    cadena_simple, cadena_formateada (cadenas)
    longitud, num_separadores, j (enteros)
INICIO
    cadena_simple = convertir_a_cadena(numero)
    longitud = LONGITUD(cadena_simple)
    // ... calcular num_separadores ...
    // ... reservar memoria para cadena_formateada ...

    j = 0
    PARA i DESDE 0 HASTA longitud-1 HACER
        // Lógica para insertar separador cada 3 dígitos desde la derecha
        // ...
        AÑADIR cadena_simple[i] a cadena_formateada
    FIN PARA

    RETORNAR cadena_formateada
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_12)=
### Ejercicio 2.03b.12 - b.12 - Búsqueda de subcadena ⭐⭐⭐☆☆

#### Descripción
Implementar una función que busque la primera ocurrencia de una subcadena
(`needle` o aguja) dentro de una cadena principal (`haystack` o pajar). Es una
reimplementación de la función `strstr`.

:::{tip} Lógica y Consideraciones

-   **Proceso (Fuerza Bruta):**
    1.  Usar un lazo exterior para recorrer la cadena `haystack` con un índice
        `i`.
    2.  En cada posición `i`, usar un lazo interior para comparar la subcadena
        de `haystack` que empieza en `i` con la cadena `needle`.
    3.  Si todos los caracteres de `needle` coinciden, devolver la posición `i`
        (o un puntero a `haystack[i]`).
    4.  Si el lazo exterior termina, la subcadena no se encontró.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION buscar_subcadena(haystack, needle)
VARIABLES:
    n, m, i, j (enteros)
INICIO
    n = LONGITUD(haystack)
    m = LONGITUD(needle)

    PARA i DESDE 0 HASTA n - m HACER
        j = 0
        MIENTRAS j < m Y haystack[i+j] == needle[j] HACER
            j = j + 1
        FIN MIENTRAS

        SI j == m ENTONCES
            RETORNAR i // Subcadena encontrada en el índice i
        FIN SI
    FIN PARA

    RETORNAR -1 // No encontrada
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Conversión de Base Numérica

(ej_b2_c03b_13)=
### Ejercicio 2.03b.13 - b.13 - Binario a decimal ⭐⭐⭐⭐☆

#### Descripción
Convertir una cadena que representa un número en formato binario (compuesta de
'0's y '1's) a su valor entero decimal correspondiente.

:::{tip} Lógica y Consideraciones

-   **Proceso:** Recorrer la cadena binaria. Para cada dígito, multiplicar el
    valor acumulado por 2 y sumar el valor del dígito actual (0 o 1).
-   $D = \sum_{i=0}^{n-1} b_i \cdot 2^{n-1-i}$

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION binario_a_decimal(cadena_binaria)
VARIABLES:
    decimal (entero)
INICIO
    decimal = 0
    PARA cada caracter c en cadena_binaria HACER
        decimal = (decimal * 2) + (c - '0')
    FIN PARA
    RETORNAR decimal
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_14)=
### Ejercicio 2.03b.14 - b.14 - Hexadecimal a decimal ⭐⭐☆☆☆

#### Descripción
Convertir una cadena que representa un número en formato hexadecimal (dígitos
0-9 y letras A-F, insensibles a mayúsculas) a su valor entero decimal.

:::{tip} Lógica y Consideraciones

-   **Proceso:** Similar a la conversión de binario, pero la base es 16.
-   **Conversión de Dígitos:** Se necesita una lógica para convertir los
    caracteres 'A'- 'F' a sus valores numéricos (10-15).

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION hexadecimal_a_decimal(cadena_hex)
VARIABLES:
    decimal (entero)
    valor_digito (entero)
INICIO
    decimal = 0
    PARA cada caracter c en cadena_hex HACER
        SI c >= '0' Y c <= '9' ENTONCES
            valor_digito = c - '0'
        SINO SI c >= 'a' Y c <= 'f' ENTONCES
            valor_digito = c - 'a' + 10
        SINO SI c >= 'A' Y c <= 'F' ENTONCES
            valor_digito = c - 'A' + 10
        FIN SI
        decimal = (decimal * 16) + valor_digito
    FIN PARA
    RETORNAR decimal
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_15)=
### Ejercicio 2.03b.15 - b.15 - Decimal a binario ⭐⭐⭐⭐☆

#### Descripción
Convertir un número entero decimal a su representación en una cadena de texto
binaria.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Usar divisiones sucesivas por 2. El resto de cada división (`n % 2`) es
        el siguiente dígito binario.
    2.  Guardar estos dígitos en un arreglo o cadena.
    3.  Como los dígitos se generan en orden inverso, la cadena resultante debe
        ser invertida al final.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION decimal_a_binario(n)
VARIABLES:
    cadena_inversa, cadena_final (cadenas)
INICIO
    SI n == 0 RETORNAR "0"

    MIENTRAS n > 0 HACER
        resto = n MOD 2
        AÑADIR caracter(resto) a cadena_inversa
        n = n / 2
    FIN MIENTRAS

    cadena_final = invertir_cadena(cadena_inversa)
    RETORNAR cadena_final
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_16)=
### Ejercicio 2.03b.16 - b.16 - Decimal a hexadecimal ⭐⭐☆☆☆

#### Descripción
Convertir un número entero decimal a su representación en una cadena de texto
hexadecimal.

:::{tip} Lógica y Consideraciones

-   **Proceso:** Similar a la conversión a binario, pero usando 16 como base.
-   **Conversión de Dígitos:** Los restos entre 10 y 15 deben ser mapeados a los
    caracteres 'A' a 'F'.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION decimal_a_hexadecimal(n)
VARIABLES:
    cadena_inversa, cadena_final (cadenas)
    mapa_hex = "0123456789ABCDEF"
INICIO
    SI n == 0 RETORNAR "0"

    MIENTRAS n > 0 HACER
        resto = n MOD 16
        AÑADIR mapa_hex[resto] a cadena_inversa
        n = n / 16
    FIN MIENTRAS

    cadena_final = invertir_cadena(cadena_inversa)
    RETORNAR cadena_final
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Más Ejercicios de Cadenas

(ej_b2_c03b_17)=
### Ejercicio 2.03b.17 - b.17 - Invertir palabras en una frase ⭐⭐☆☆☆

#### Descripción
Escribir una función que tome una frase y la modifique de tal manera que cada
palabra individual quede invertida, pero el orden de las palabras en la frase se
mantenga intacto.

:::{tip} Lógica y Consideraciones

-   **Entrada:** Una cadena de caracteres que representa una frase.
-   **Proceso:**
    1.  Recorrer la cadena para identificar los límites de cada palabra. Las
        palabras suelen estar separadas por espacios o signos de puntuación.
    2.  Para cada palabra encontrada, se necesita una función auxiliar que pueda
        invertir una subcadena. Esta función tomaría punteros o índices al
        inicio y al final de la palabra.
    3.  La función de inversión de subcadena usaría la técnica de dos punteros
        (uno al inicio y otro al final de la palabra) que se mueven hacia el
        centro, intercambiando caracteres en cada paso.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO invertir_subcadena(REF cadena, inicio, fin)
    MIENTRAS inicio < fin HACER
        INTERCAMBIAR(cadena[inicio], cadena[fin])
        inicio++, fin--
    FIN MIENTRAS
FIN PROCEDIMIENTO

PROCEDIMIENTO invertir_palabras(REF frase)
VARIABLES:
    inicio_palabra, i (enteros)
INICIO
    inicio_palabra = 0
    PARA i DESDE 0 HASTA LONGITUD(frase) HACER
        SI frase[i] == ' ' O frase[i] == FIN_DE_CADENA ENTONCES
            // Se encontró el final de una palabra
            invertir_subcadena(frase, inicio_palabra, i - 1)
            inicio_palabra = i + 1
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_18)=
### Ejercicio 2.03b.18 - b.18 - Invertir orden de las palabras ⭐⭐☆☆☆

#### Descripción
Escribir una función que invierta el orden de las palabras en una frase. Por
ejemplo, "Hola Mundo desde C" se convertiría en "C desde Mundo Hola".

:::{tip} Lógica y Consideraciones

-   **Proceso (dos pasos):**
    1.  Invertir la cadena de caracteres completa. ("Hola Mundo desde C" -> "C
        edsed odnuM aloH").
    2.  Recorrer la nueva cadena e invertir cada palabra individualmente (usando
        la lógica del ejercicio 5.1). ("C" -> "C", "edsed" -> "desde", etc.).

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO invertir_orden_palabras(REF frase)
INICIO
    // Paso 1: Invertir toda la frase
    invertir_subcadena(frase, 0, LONGITUD(frase) - 1)

    // Paso 2: Invertir cada palabra individualmente
    invertir_palabras(frase)
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_19)=
### Ejercicio 2.03b.19 - b.19 - Capitalización (Title Case) ⭐⭐⭐⭐☆

#### Descripción
Implementar una función que convierta una cadena a "Title Case", donde la
primera letra de cada palabra está en mayúscula y el resto de las letras de la
palabra están en minúscula.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Convertir toda la cadena a minúsculas para empezar desde un estado base
        consistente.
    2.  Capitalizar el primer carácter de la cadena (si es una letra).
    3.  Recorrer la cadena. Si se encuentra un espacio (u otro delimitador de
        palabra), capitalizar el siguiente carácter si es una letra.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO a_title_case(REF cadena)
INICIO
    convertir_a_minuscula_toda_la_cadena(cadena)
    capitalizar(cadena[0])

    PARA i DESDE 1 HASTA LONGITUD(cadena)-1 HACER
        SI cadena[i-1] == ' ' ENTONCES
            capitalizar(cadena[i])
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_20)=
### Ejercicio 2.03b.20 - b.20 - Contar palabras ⭐⭐☆☆☆

#### Descripción
Desarrollar una función que cuente el número de palabras en una cadena. Se puede
considerar que las palabras están separadas por uno o más espacios.

:::{tip} Lógica y Consideraciones

-   **Máquina de Estados:** Una forma robusta de hacerlo es con una máquina de
    estados simple con dos estados: `DENTRO_DE_PALABRA` y `FUERA_DE_PALABRA`.
-   **Proceso:**
    1.  Inicializar `contador_palabras = 0` y `estado = FUERA_DE_PALABRA`.
    2.  Recorrer la cadena. Si se está `FUERA_DE_PALABRA` y se encuentra un
        carácter que no es un espacio, se ha encontrado el inicio de una nueva
        palabra. Incrementar `contador_palabras` y cambiar a `estado =
        DENTRO_DE_PALABRA`.
    3.  Si se está `DENTRO_DE_PALABRA` y se encuentra un espacio, cambiar a
        `estado = FUERA_DE_PALABRA`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION contar_palabras(cadena)
VARIABLES:
    contador, estado (enteros)
INICIO
    contador = 0
    estado = FUERA_DE_PALABRA

    PARA cada caracter c en cadena HACER
        SI c == ' ' O c == '\n' O c == '\t' ENTONCES
            estado = FUERA_DE_PALABRA
        SINO SI estado == FUERA_DE_PALABRA ENTONCES
            estado = DENTRO_DE_PALABRA
            contador = contador + 1
        FIN SI
    FIN PARA
    RETORNAR contador
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_21)=
### Ejercicio 2.03b.21 - b.21 - Eliminar espacios extra ⭐⭐☆☆☆

#### Descripción
Crear una función que elimine los espacios en blanco redundantes de una cadena:
espacios al principio, al final y múltiples espacios entre palabras, dejando
solo un espacio entre cada palabra.

:::{tip} Lógica y Consideraciones

-   **Proceso (in-place con dos punteros):**
    1.  Usar un `puntero_lectura` y un `puntero_escritura`.
    2.  Recorrer la cadena con `puntero_lectura`.
    3.  Copiar un carácter de lectura a escritura solo si no es un espacio
        redundante. La condición para copiar podría ser: `si el carácter actual
        no es un espacio, O si el carácter anterior copiado no fue un espacio`.
    4.  Manejar los espacios al principio como un caso especial.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO eliminar_espacios_extra(REF cadena)
VARIABLES:
    p_lectura, p_escritura (enteros)
INICIO
    p_lectura = 0, p_escritura = 0
    MIENTRAS cadena[p_lectura] != FIN_DE_CADENA HACER
        // Copiar caracteres que no son espacios
        MIENTRAS cadena[p_lectura] != ' ' Y cadena[p_lectura] != FIN_DE_CADENA HACER
            cadena[p_escritura++] = cadena[p_lectura++]
        FIN MIENTRAS
        // Omitir múltiples espacios
        MIENTRAS cadena[p_lectura] == ' ' HACER
            p_lectura++
        FIN MIENTRAS
        // Añadir un solo espacio si no estamos al final
        SI cadena[p_lectura] != FIN_DE_CADENA ENTONCES
            cadena[p_escritura++] = ' '
        FIN SI
    FIN MIENTRAS
    cadena[p_escritura] = FIN_DE_CADENA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_22)=
### Ejercicio 2.03b.22 - b.22 - Recorte de cadena (Trim) ⭐⭐⭐☆☆

#### Descripción
Implementar una función `trim` que modifique una cadena para eliminar todos los
espacios en blanco (o cualquier otro carácter de espaciado como tabuladores o
saltos de línea) que se encuentren al principio y al final de la misma.

:::{tip} Lógica y Consideraciones

-   **Proceso (dos etapas):**
    1.  **Eliminar espacios del final:** Recorrer la cadena desde el final hacia
        el principio. Mientras se encuentren espacios, reemplazarlos por el
        carácter nulo `\0`.
    2.  **Eliminar espacios del principio:** Encontrar el puntero al primer
        carácter que no sea un espacio. Luego, mover todo el bloque de la cadena
        (incluyendo el terminador nulo) a la posición inicial usando `memmove`.
-   **Funciones de Biblioteca:** `isspace()` de `ctype.h` es útil para detectar
    cualquier tipo de carácter de espaciado.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO trim(REF cadena)
VARIABLES:
    longitud, i, inicio (enteros)
INICIO
    longitud = LONGITUD(cadena)

    // Recortar final
    i = longitud - 1
    MIENTRAS i >= 0 Y es_espacio(cadena[i]) HACER
        i--
    FIN MIENTRAS
    cadena[i + 1] = FIN_DE_CADENA

    // Recortar inicio
    inicio = 0
    MIENTRAS cadena[inicio] != FIN_DE_CADENA Y es_espacio(cadena[inicio]) HACER
        inicio++
    FIN MIENTRAS

    // Mover la cadena si es necesario
    SI inicio > 0 ENTONCES
        mover_bloque_memoria(cadena, cadena + inicio, LONGITUD(cadena) - inicio + 1)
    FIN SI
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_23)=
### Ejercicio 2.03b.23 - b.23 - Reemplazar subcadena ⭐⭐⭐☆☆

#### Descripción
Escribir una función que reemplace todas las ocurrencias de una subcadena por
otra dentro de una cadena principal. La función debe manejar cambios en la
longitud de la cadena, lo que usualmente requiere memoria dinámica.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Contar cuántas veces aparece la subcadena a buscar para calcular el
        tamaño final de la nueva cadena.
    2.  Reservar memoria (`malloc`) para la nueva cadena.
    3.  Recorrer la cadena original. Cuando se encuentre una ocurrencia de la
        subcadena a buscar, copiar la cadena de reemplazo a la nueva cadena. Si
        no, copiar el carácter actual.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION reemplazar_subcadena(original, buscar, reemplazar)
VARIABLES:
    nueva_cadena (cadena)
    i, j (enteros)
INICIO
    // ... calcular tamaño de nueva_cadena y reservar memoria ...
    i = 0, j = 0
    MIENTRAS i < LONGITUD(original) HACER
        SI subcadena_en(original, i) == buscar ENTONCES
            COPIAR reemplazar en nueva_cadena en la posición j
            i = i + LONGITUD(buscar)
            j = j + LONGITUD(reemplazar)
        SINO
            nueva_cadena[j] = original[i]
            i++, j++
        FIN SI
    FIN MIENTRAS
    nueva_cadena[j] = FIN_DE_CADENA
    RETORNAR nueva_cadena
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_24)=
### Ejercicio 2.03b.24 - b.24 - Validación de email (Simple) ⭐☆☆☆☆

#### Descripción
Crear una función que verifique si una cadena tiene un formato de correo
electrónico básico. No busca ser exhaustiva (lo cual es muy complejo), sino
validar una estructura mínima.

:::{tip} Lógica y Consideraciones

-   **Reglas Mínimas:**
    1.  Debe contener exactamente un carácter `@`.
    2.  El `@` no puede ser el primer ni el último carácter.
    3.  Debe contener al menos un `.` después del `@`.
    4.  El `.` no puede estar inmediatamente después del `@`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_email_simple_valido(email)
VARIABLES:
    pos_arroba, pos_ultimo_punto (enteros)
INICIO
    pos_arroba = encontrar_caracter(email, '@')
    SI pos_arroba == NO_ENCONTRADO O pos_arroba == 0 ENTONCES
        RETORNAR FALSO
    FIN SI

    // Verificar que no haya más de un @
    // ...

    pos_ultimo_punto = encontrar_ultima_posicion(email, '.')
    SI pos_ultimo_punto == NO_ENCONTRADO O pos_ultimo_punto < pos_arroba + 2 ENTONCES
        RETORNAR FALSO
    FIN SI

    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_25)=
### Ejercicio 2.03b.25 - b.25 - Cifrado César ⭐⭐☆☆☆

#### Descripción
Implementar el Cifrado César, un tipo de cifrado por sustitución en el que cada
letra en el texto original es reemplazada por una letra un número fijo de
posiciones más adelante en el alfabeto, de forma circular.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Para cada carácter, si es una letra, aplicar el desplazamiento.
    3.  El desplazamiento es circular. Si al desplazar 'y' 3 posiciones se pasa
        de 'z', se debe volver al principio del alfabeto. Esto se logra con el
        operador módulo (`%`).
    4.  Ejemplo para una letra minúscula `c`: `'a' + (c - 'a' + desplazamiento)
        % 26`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION cifrado_cesar(cadena, desplazamiento)
VARIABLES:
    resultado (cadena)
INICIO
    PARA cada caracter c en cadena HACER
        SI es_letra_minuscula(c) ENTONCES
            nuevo_car = 'a' + (c - 'a' + desplazamiento) MOD 26
            AÑADIR nuevo_car a resultado
        SINO SI es_letra_mayuscula(c) ENTONCES
            nuevo_car = 'A' + (c - 'A' + desplazamiento) MOD 26
            AÑADIR nuevo_car a resultado
        SINO
            AÑADIR c a resultado
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_26)=
### Ejercicio 2.03b.26 - b.26 - Descifrado César ⭐⭐☆☆☆

#### Descripción
Escribir la función complementaria que descifre un mensaje cifrado con el
Cifrado César, conociendo el desplazamiento. Es la operación inversa al
ejercicio anterior.

:::{tip} Lógica y Consideraciones

-   **Proceso:** Es idéntico al cifrado, pero en lugar de sumar el
    desplazamiento, se resta. Para manejar el wraparound negativo, la fórmula
    puede ser `'a' + (c - 'a' - desplazamiento + 26) % 26`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION descifrado_cesar(cadena, desplazamiento)
INICIO
    // La lógica es la misma que el cifrado, pero con -desplazamiento
    RETORNAR cifrado_cesar(cadena, 26 - desplazamiento)
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_27)=
### Ejercicio 2.03b.27 - b.27 - Encontrar el carácter más frecuente ⭐⭐☆☆☆

#### Descripción
Desarrollar una función que encuentre y devuelva el carácter que aparece con más
frecuencia en una cadena. Si hay empates, puede devolver cualquiera de los más
frecuentes.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Usar un arreglo de frecuencias de 256 enteros, como en el ejercicio 1.2.
    2.  Llenar el arreglo de frecuencias recorriendo la cadena.
    3.  Recorrer el arreglo de frecuencias para encontrar el índice que tiene el
        valor más alto. Ese índice es el código ASCII del carácter más
        frecuente.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION caracter_mas_frecuente(cadena)
VARIABLES:
    frecuencias (arreglo de 256 enteros)
    max_frecuencia, char_mas_frecuente (enteros)
INICIO
    // ... llenar arreglo de frecuencias ...

    max_frecuencia = -1
    PARA i DESDE 0 HASTA 255 HACER
        SI frecuencias[i] > max_frecuencia ENTONCES
            max_frecuencia = frecuencias[i]
            char_mas_frecuente = i
        FIN SI
    FIN PARA
    RETORNAR CARACTER(char_mas_frecuente)
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_28)=
### Ejercicio 2.03b.28 - b.28 - Comparación de cadenas (Ignorando mayúsculas) ⭐⭐⭐☆☆

#### Descripción
Implementar su propia versión de la función `strcasecmp`, que compara dos
cadenas sin diferenciar entre mayúsculas y minúsculas.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer ambas cadenas simultáneamente con un lazo `while`.
    2.  En cada paso, comparar las versiones en minúscula (o mayúscula) de los
        caracteres actuales.
    3.  Si son diferentes, devolver la diferencia.
    4.  Si una cadena termina antes que la otra, son diferentes.
    5.  Si ambas terminan al mismo tiempo, son iguales.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION comparar_sin_caso(s1, s2)
INICIO
    MIENTRAS *s1 != FIN_DE_CADENA Y *s2 != FIN_DE_CADENA HACER
        c1 = convertir_a_minuscula(*s1)
        c2 = convertir_a_minuscula(*s2)
        SI c1 != c2 ENTONCES
            RETORNAR c1 - c2
        FIN SI
        s1++, s2++
    FIN MIENTRAS
    RETORNAR convertir_a_minuscula(*s1) - convertir_a_minuscula(*s2)
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_29)=
### Ejercicio 2.03b.29 - b.29 - Extraer subcadena ⭐⭐⭐☆☆

#### Descripción
Crear una función que extraiga una porción de una cadena. La función debe
recibir la cadena original, una posición de inicio y una longitud, y devolver
una nueva cadena con la subcadena extraída.

:::{tip} Lógica y Consideraciones

-   **Memoria:** La función debe reservar memoria para la nueva cadena.
-   **Proceso:**
    1.  Calcular la longitud de la subcadena y reservar memoria (longitud + 1
        para el `\0`).
    2.  Copiar los caracteres desde la posición de inicio de la cadena original
        a la nueva cadena.
    3.  Añadir el terminador nulo `\0` al final de la nueva cadena.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION extraer_subcadena(cadena, inicio, longitud)
VARIABLES:
    subcadena (cadena)
INICIO
    // ... reservar memoria para subcadena ...
    COPIAR_MEMORIA(subcadena, cadena + inicio, longitud)
    subcadena[longitud] = FIN_DE_CADENA
    RETORNAR subcadena
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_30)=
### Ejercicio 2.03b.30 - b.30 - Justificar texto (Simple) ⭐☆☆☆☆

#### Descripción
Implementar una función que justifique una línea de texto a un ancho específico,
insertando espacios adicionales entre las palabras de la manera más uniforme
posible.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Contar el número de palabras y el número total de caracteres (sin
        espacios).
    2.  Calcular el número total de espacios a insertar: `ancho_total -
        num_caracteres`.
    3.  Calcular el número de espacios a poner en cada hueco entre palabras.
    4.  Construir la nueva cadena añadiendo las palabras y el número calculado
        de espacios entre ellas.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION justificar_texto(linea, ancho)
VARIABLES:
    num_palabras, num_espacios, espacios_por_hueco, espacios_extra
INICIO
    // ... contar palabras y caracteres ...
    // ... calcular espacios a insertar ...

    // ... construir la nueva cadena ...
    RETORNAR cadena_justificada
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_31)=
### Ejercicio 2.03b.31 - b.31 - Acrónimo ⭐⭐☆☆☆

#### Descripción
Escribir una función que genere un acrónimo a partir de una frase, tomando la
primera letra de cada palabra.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena.
    2.  Usar una bandera o estado para saber si el carácter actual es el inicio
        de una nueva palabra.
    3.  Si es el inicio de una palabra y es una letra, añadirla (en mayúscula) a
        la cadena de resultado.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION generar_acronimo(frase)
VARIABLES:
    acronimo (cadena)
    es_inicio_de_palabra (booleano)
INICIO
    acronimo = ""
    es_inicio_de_palabra = VERDADERO

    PARA cada caracter c en frase HACER
        SI es_letra(c) Y es_inicio_de_palabra ENTONCES
            AÑADIR convertir_a_mayuscula(c) a acronimo
            es_inicio_de_palabra = FALSO
        SINO SI c == ' ' ENTONCES
            es_inicio_de_palabra = VERDADERO
        FIN SI
    FIN PARA
    RETORNAR acronimo
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Cadenas y Algoritmos

(ej_b2_c03b_32)=
### Ejercicio 2.03b.32 - b.32 - Distancia de Hamming ⭐⭐☆☆☆

#### Descripción
Implementar una función que calcule la distancia de Hamming entre dos cadenas de
igual longitud. Esta distancia es el número de posiciones en las que los
caracteres correspondientes son diferentes.

:::{tip} Lógica y Consideraciones

-   **Precondición:** Las cadenas deben tener la misma longitud.
-   **Proceso:**
    1.  Inicializar un `contador` en 0.
    2.  Recorrer ambas cadenas simultáneamente con un lazo `for`.
    3.  En cada posición `i`, si `cadena1[i] != cadena2[i]`, incrementar el
        `contador`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION distancia_hamming(cadena1, cadena2)
VARIABLES:
    distancia (entero)
INICIO
    SI LONGITUD(cadena1) != LONGITUD(cadena2) RETORNAR -1 // Error

    distancia = 0
    PARA i DESDE 0 HASTA LONGITUD(cadena1)-1 HACER
        SI cadena1[i] != cadena2[i] ENTONCES
            distancia++
        FIN SI
    FIN PARA
    RETORNAR distancia
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_33)=
### Ejercicio 2.03b.33 - b.33 - Subsecuencia común más larga (LCS) ⭐⭐☆☆☆

#### Descripción
Escribir una función que encuentre la longitud de la subsecuencia común más
larga (LCS) entre dos cadenas. Una subsecuencia no tiene por qué ser contigua.

:::{tip} Lógica y Consideraciones

-   **Algoritmo:** Este es un problema clásico de programación dinámica.
-   **Proceso:**
    1.  Crear una matriz 2D `dp` de tamaño `(longitud1+1) x (longitud2+1)`.
    2.  `dp[i][j]` almacenará la longitud de la LCS de `cadena1[0..i-1]` y
        `cadena2[0..j-1]`.
    3.  Llenar la matriz usando la recurrencia:
        -   Si `cadena1[i-1] == cadena2[j-1]`, entonces `dp[i][j] = 1 +
            dp[i-1][j-1]`.
        -   Si no, `dp[i][j] = MAXIMO(dp[i-1][j], dp[i][j-1])`.
-   **Salida:** El resultado es el valor en `dp[longitud1][longitud2]`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION lcs(cadena1, cadena2)
VARIABLES:
    dp (matriz 2D)
INICIO
    // ... inicializar y llenar la matriz dp ...
    RETORNAR dp[LONGITUD(cadena1)][LONGITUD(cadena2)]
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_34)=
### Ejercicio 2.03b.34 - b.34 - Validación de IP simple ⭐☆☆☆☆

#### Descripción
Crear una función que verifique si una cadena representa una dirección IPv4
válida. Debe consistir en cuatro números entre 0 y 255, separados por puntos.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Usar `strtok` o una función similar para dividir la cadena por el
        delimitador `.`.
    2.  Contar el número de tokens. Deben ser exactamente 4.
    3.  Para cada token, convertirlo a entero (usando `atoi` o `sscanf`).
    4.  Verificar que el número esté en el rango [0, 255].

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_ipv4_valida(cadena)
VARIABLES:
    tokens (arreglo de cadenas)
    num (entero)
INICIO
    tokens = dividir_cadena(cadena, '.')
    SI LONGITUD(tokens) != 4 RETORNAR FALSO

    PARA cada token en tokens HACER
        SI token está vacío O NO es_numero(token) RETORNAR FALSO
        num = convertir_a_entero(token)
        SI num < 0 O num > 255 RETORNAR FALSO
    FIN PARA

    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_35)=
### Ejercicio 2.03b.35 - b.35 - Convertir a `snake_case` ⭐⭐☆☆☆

#### Descripción
Implementar una función que convierta una cadena en `camelCase` o `PascalCase` a
`snake_case`. Esto implica insertar un guion bajo antes de cada letra mayúscula
y convertir toda la cadena a minúsculas.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Si se encuentra una letra mayúscula (y no es el primer carácter), añadir
        un `_` a la cadena de resultado antes de añadir la letra.
    3.  Convertir cada carácter a minúscula antes de añadirlo a la cadena de
        resultado.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION a_snake_case(cadena)
VARIABLES:
    resultado (cadena)
INICIO
    PARA cada caracter c en cadena HACER
        SI es_mayuscula(c) Y resultado NO está vacío ENTONCES
            AÑADIR '_' a resultado
        FIN SI
        AÑADIR convertir_a_minuscula(c) a resultado
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_36)=
### Ejercicio 2.03b.36 - b.36 - Convertir a `camelCase` ⭐⭐☆☆☆

#### Descripción
Implementar una función que convierta una cadena en `snake_case` a `camelCase`.
Esto implica eliminar los guiones bajos y poner en mayúscula la letra que les
seguía.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Usar una bandera `capitalizar_siguiente`.
    3.  Si el carácter actual es `_`, poner `capitalizar_siguiente` a
        `verdadero` y no añadir nada al resultado.
    4.  Si no es `_`, y `capitalizar_siguiente` es `verdadero`, convertir el
        carácter a mayúscula, añadirlo al resultado y poner la bandera a
        `falso`. Si no, simplemente añadirlo.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION a_camel_case(cadena)
VARIABLES:
    resultado (cadena)
    capitalizar (booleano)
INICIO
    capitalizar = FALSO
    PARA cada caracter c en cadena HACER
        SI c == '_' ENTONCES
            capitalizar = VERDADERO
        SINO SI capitalizar ENTONCES
            AÑADIR convertir_a_mayuscula(c) a resultado
            capitalizar = FALSO
        SINO
            AÑADIR c a resultado
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_37)=
### Ejercicio 2.03b.37 - b.37 - Rotación de cadena ⭐⭐⭐☆☆

#### Descripción
Escribir una función que determine si una cadena `s2` es una rotación de otra
cadena `s1`.

:::{tip} Lógica y Consideraciones

-   **Propiedad Clave:** `s2` es una rotación de `s1` si y solo si `s2` es una
    subcadena de `s1` concatenado consigo mismo (`s1s1`).
-   **Proceso:**
    1.  Verificar que `s1` y `s2` tengan la misma longitud. Si no, no pueden ser
        rotaciones.
    2.  Crear una nueva cadena `temp` que sea `s1 + s1`.
    3.  Buscar si `s2` es una subcadena de `temp`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_rotacion(s1, s2)
INICIO
    SI LONGITUD(s1) != LONGITUD(s2) RETORNAR FALSO

    temp = s1 + s1 // Concatenación
    SI buscar_subcadena(temp, s2) != NO_ENCONTRADO ENTONCES
        RETORNAR VERDADERO
    SINO
        RETORNAR FALSO
    FIN SI
    FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_38)=
### Ejercicio 2.03b.38 - b.38 - Eliminar comentarios ⭐⭐☆☆☆

#### Descripción
Crear una función que reciba una cadena (que puede representar una o más líneas
de código) y elimine los comentarios de estilo C (`//...` hasta el final de la
línea y `/*...*/` incluyendo el contenido).

:::{tip} Lógica y Consideraciones

-   **Máquina de Estados:** Este problema se resuelve mejor con una máquina de
    estados para rastrear si el procesador está en modo `NORMAL`,
    `DENTRO_DE_COMENTARIO_LINEA`, o `DENTRO_DE_COMENTARIO_BLOQUE`.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION eliminar_comentarios(codigo)
VARIABLES:
    resultado (cadena)
    estado (entero)
INICIO
    estado = NORMAL
    PARA i DESDE 0 HASTA LONGITUD(codigo)-1 HACER
        SI estado == NORMAL Y codigo[i] == '/' Y codigo[i+1] == '/' ENTONCES
            estado = DENTRO_DE_COMENTARIO_LINEA
        SINO SI estado == NORMAL Y codigo[i] == '/' Y codigo[i+1] == '*' ENTONCES
            estado = DENTRO_DE_COMENTARIO_BLOQUE
        SINO SI estado == DENTRO_DE_COMENTARIO_LINEA Y codigo[i] == '\n' ENTONCES
            estado = NORMAL
            AÑADIR '\n' a resultado
        SINO SI estado == DENTRO_DE_COMENTARIO_BLOQUE Y codigo[i] == '*' Y codigo[i+1] == '/' ENTONCES
            estado = NORMAL
            i++ // Saltar el '/'
        SINO SI estado == NORMAL ENTONCES
            AÑADIR codigo[i] a resultado
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_39)=
### Ejercicio 2.03b.39 - b.39 - Análisis de URL simple ⭐☆☆☆☆

#### Descripción
Dada una URL en formato de cadena, escribir una función que la analice y
extraiga sus componentes principales: protocolo, host y ruta.

:::{tip} Lógica y Consideraciones

-   **Proceso:** Usar funciones de búsqueda de caracteres (`:`, `/`) para
    encontrar los delimitadores y luego extraer las subcadenas correspondientes.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO analizar_url(url, REF protocolo, REF host, REF ruta)
VARIABLES:
    pos_protocolo, pos_host_inicio, pos_ruta_inicio (enteros)
INICIO
    pos_protocolo = encontrar_caracter(url, ':')
    protocolo = extraer_subcadena(url, 0, pos_protocolo)

    // ... lógica similar para host y ruta ...
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_40)=
### Ejercicio 2.03b.40 - b.40 - Generador de "Slugs" ⭐⭐☆☆☆

#### Descripción
Un "slug" es una versión de una cadena amigable para URLs. Escribir una función
que convierta un título en un slug: debe estar en minúsculas, los espacios deben
ser reemplazados por guiones y se deben eliminar todos los caracteres no
alfanuméricos.

:::{tip} Lógica y Consideraciones

-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Para cada carácter, convertirlo a minúscula.
    3.  Si es una letra o un número, añadirlo a la cadena de resultado.
    4.  Si es un espacio, y el último carácter añadido al resultado no fue un
        guion, añadir un guion.
    5.  Ignorar todos los demás caracteres.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION generar_slug(titulo)
VARIABLES:
    slug (cadena)
INICIO
    PARA cada caracter c en titulo HACER
        c_min = convertir_a_minuscula(c)
        SI es_alfanumerico(c_min) ENTONCES
            AÑADIR c_min a slug
        SINO SI es_espacio(c_min) Y ultimo_char(slug) != '-' ENTONCES
            AÑADIR '-' a slug
        FIN SI
    FIN PARA
    RETORNAR slug
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03b_41)=
### Ejercicio 2.03b.41 - b.41 - Primer carácter no repetido ⭐⭐☆☆☆

#### Descripción
Implementar una función que encuentre y devuelva el primer carácter en una
cadena que no se repite en el resto de la cadena.

:::{tip} Lógica y Consideraciones

-   **Proceso (dos pasadas):**
    1.  **Primera pasada:** Usar un arreglo de frecuencias para contar las
        apariciones de cada carácter (como en el ejercicio 1.2).
    2.  **Segunda pasada:** Recorrer la cadena de entrada original. El primer
        carácter para el cual su contador en el arreglo de frecuencias sea 1, es
        el resultado.

:::
<!-- {tip} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION primer_no_repetido(cadena)
VARIABLES:
    frecuencias (arreglo de 256 enteros)
INICIO
    // ... llenar arreglo de frecuencias ...

    PARA cada caracter c en cadena HACER
        SI frecuencias[CODIGO_ASCII(c)] == 1 ENTONCES
            RETORNAR c
        FIN SI
    FIN PARA

    RETORNAR CARACTER_NULO // No se encontró ninguno
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

---

(ej_b2_c03b_42)=
### Ejercicio 2.03b.42 - Extracción Segura de Subcadena ⭐⭐⭐☆☆

:::{exercise}
:label: subcadena_segura

Implementá una función defensiva que extraiga una porción de una cadena de caracteres:
```c
bool subcadena_segura(const char *origen, size_t inicio, size_t longitud,
                      char *destino, size_t cap_destino);
```
La función debe copiar hasta `longitud` caracteres comenzando desde la posición `inicio` de la cadena `origen` hacia el búfer `destino`.
Debe asegurar siempre la terminación en `\0`. Si `inicio` supera la longitud de `origen` o si el búfer de destino no tiene capacidad suficiente para albergar la subcadena y el terminador nulo, debe rechazar la operación retornando `false` y dejando una cadena vacía en `destino` si `cap_destino > 0`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Aritmética de punteros, límites de memoria ({ref}`0x5003h`), validación defensiva contra buffer overruns.  
**Techo conceptual:** Prohibido el uso de `strncpy` o funciones inseguras sin validación de capacidad.

#### Contrato de la Función
- **Firma:** `bool subcadena_segura(const char *origen, size_t inicio, size_t longitud, char *destino, size_t cap_destino);`
- **Precondiciones:** `origen != NULL`, `destino != NULL`, `cap_destino > 0`.
- **Postcondiciones:** Retorna `true` y escribe la subcadena en `destino` garantizando el terminador nulo.

#### Tabla de Vectores de Prueba

| Tipo de Caso | Cadena Origen | Inicio / Longitud | Capacidad Destino | Retorno | Cadena Destino | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | `"Estructura de Datos"` | `inicio=0, len=10` | `16` | `true` | `"Estructura"` | Copia exacta de prefijo |
| **Normal** | `"Programacion"` | `inicio=3, len=4` | `5` | `true` | `"gram"` | Extracción interna con tamaño justo |
| **Borde (Fin de cadena)**| `"UNRN"` | `inicio=2, len=10` | `10` | `true` | `"RN"` | Trunca sanamente al alcanzar `\0` |
| **Error (Fuera de rango)**| `"Hola"` | `inicio=10, len=2` | `8` | `false` | `""` | Índice inicial fuera de los límites |
| **Error (Capacidad escasa)**| `"Algoritmos"` | `inicio=0, len=5` | `5` | `false` | `""` | Búfer insuficiente (necesita 6 con `\0`) |

:::

::::{solution} subcadena_segura
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

bool subcadena_segura(const char *origen, size_t inicio, size_t longitud,
                      char *destino, size_t cap_destino)
{
    if (origen == NULL || destino == NULL || cap_destino == 0)
    {
        return false;
    }

    size_t len_origen = strlen(origen);
    if (inicio > len_origen)
    {
        destino[0] = '\0';
        return false;
    }

    // Determinar cuántos caracteres reales se pueden leer desde 'inicio'
    size_t disponibles = len_origen - inicio;
    size_t a_copiar = (longitud < disponibles) ? longitud : disponibles;

    // Verificar si cabe la subcadena + '\0'
    if (a_copiar + 1 > cap_destino)
    {
        destino[0] = '\0';
        return false;
    }

    for (size_t i = 0; i < a_copiar; i++)
    {
        destino[i] = origen[inicio + i];
    }
    destino[a_copiar] = '\0';

    return true;
}

int main(void)
{
    char buf[32];

    // Caso normal prefijo
    assert(subcadena_segura("Estructura de Datos", 0, 10, buf, sizeof(buf)) == true);
    assert(strcmp(buf, "Estructura") == 0);

    // Caso normal interno con capacidad justa
    char buf_justo[5];
    assert(subcadena_segura("Programacion", 3, 4, buf_justo, sizeof(buf_justo)) == true);
    assert(strcmp(buf_justo, "gram") == 0);

    // Caso borde alcanza fin de cadena
    assert(subcadena_segura("UNRN", 2, 10, buf, sizeof(buf)) == true);
    assert(strcmp(buf, "RN") == 0);

    // Caso error: inicio fuera de rango
    assert(subcadena_segura("Hola", 10, 2, buf, sizeof(buf)) == false);
    assert(buf[0] == '\0');

    // Caso error: capacidad escasa (necesita 6 bytes incluyendo '\0')
    char buf_chico[5];
    assert(subcadena_segura("Algoritmos", 0, 5, buf_chico, sizeof(buf_chico)) == false);
    assert(buf_chico[0] == '\0');

    return 0;
}
```

::::
<!-- {solution} subcadena_segura -->
