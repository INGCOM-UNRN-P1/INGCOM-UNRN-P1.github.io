---
title: Ejercicios de Cadenas
short_title: 4. Cadenas
---

## Acerca de

La manipulación de cadenas es una de las tareas más comunes y, en C, una de las
más propensas a errores. Estos ejercicios están diseñados para construir una
base sólida en el manejo de cadenas de caracteres (estilo C, terminadas en
nulo), enfocándose en la implementación de algoritmos comunes desde cero. Es
crucial que al resolverlos, se apliquen los principios de manejo de "cadenas
seguras" ({ref}`0x0030h`), pasando siempre la capacidad del búfer para evitar
desbordamientos.

---

## 1: Análisis de Cadenas

### 1.1: Contar vocales

#### Descripción
Escribir una función que cuente el número total de vocales (a, e, i, o, u) en una cadena de texto. La función no debe distinguir entre mayúsculas y minúsculas.

:::{tip} Lógica y Consideraciones
-   **Entrada:** Una cadena de caracteres.
-   **Proceso:**
    1.  Inicializar un `contador` en 0.
    2.  Recorrer la cadena carácter por carácter con un lazo hasta encontrar el terminador nulo `\0`.
    3.  Para cada carácter, es conveniente convertirlo a minúscula para simplificar la comparación (usando `tolower()` de `ctype.h`).
    4.  Verificar si el carácter es una de las cinco vocales (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`).
    5.  Si es una vocal, incrementar el `contador`.
-   **Salida:** Devolver el valor final del `contador`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION contar_vocales(cadena)
VARIABLES:
    contador (entero)
    caracter_actual (caracter)
INICIO
    contador = 0
    PARA cada caracter_actual en cadena HACER
        c = convertir_a_minuscula(caracter_actual)
        SI c == 'a' O c == 'e' O c == 'i' O c == 'o' O c == 'u' ENTONCES
            contador = contador + 1
        FIN SI
    FIN PARA
    RETORNAR contador
FIN FUNCION
```
:::

### 1.2: Contabilizador de caracteres

#### Descripción
Implementar una función que calcule la frecuencia de aparición de cada carácter dentro de una cadena y muestre el resultado para aquellos caracteres que aparecen al menos una vez.

:::{tip} Lógica y Consideraciones
-   **Estructura de Datos:** Un arreglo de contadores es ideal para esto. Dado que los caracteres ASCII se pueden representar como enteros (de 0 a 255), se puede usar un arreglo de tamaño 256, donde el índice del arreglo corresponde al código ASCII del carácter.
-   **Proceso:**
    1.  Crear un arreglo `frecuencias` de 256 enteros, inicializado completamente en 0.
    2.  Recorrer la cadena de entrada. Para cada carácter `c`, incrementar el contador en la posición correspondiente a su valor ASCII: `frecuencias[(int)c]++`.
    3.  Después de recorrer toda la cadena, iterar sobre el arreglo `frecuencias` desde 0 a 255. Si `frecuencias[i]` es mayor que 0, significa que el carácter con código ASCII `i` apareció, y se imprime junto con su frecuencia.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO contabilizar_caracteres(cadena)
VARIABLES:
    frecuencias (arreglo de 256 enteros)
INICIO
    INICIALIZAR frecuencias con ceros

    PARA cada caracter c en cadena HACER
        frecuencias[CODIGO_ASCII(c)] = frecuencias[CODIGO_ASCII(c)] + 1
    FIN PARA

    PARA i DESDE 0 HASTA 255 HACER
        SI frecuencias[i] > 0 ENTONCES
            ESCRIBIR "Carácter '", CARACTER(i), "': ", frecuencias[i], " veces"
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 1.3: ¿Es un número válido?

#### Descripción
Desarrollar una función que verifique si una cadena de texto representa un número de punto flotante válido. La validación debe seguir un conjunto de reglas específicas.

:::{tip} Lógica y Consideraciones
-   **Reglas de Validación:**
    1.  Puede tener un signo opcional (`+` o `-`) únicamente al principio.
    2.  Debe contener al menos un dígito.
    3.  Puede contener como máximo un punto decimal (`.`).
    4.  Todos los demás caracteres deben ser dígitos (`0`-`9`).
-   **Proceso:**
    1.  Recorrer la cadena carácter por carácter.
    2.  Usar banderas (variables booleanas) para llevar un registro de si ya se encontró un punto decimal.
    3.  Manejar el signo solo en la primera posición.
    4.  Verificar que cada carácter sea un dígito o un punto (en la posición correcta).
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::

### 1.4: ¿Es alfabética?

#### Descripción
Crear una función que determine si una cadena contiene únicamente caracteres alfabéticos (de la 'a' a la 'z', mayúsculas o minúsculas).

:::{tip} Lógica y Consideraciones
-   **Proceso:** Recorrer la cadena. Para cada carácter, verificar si está dentro del rango de 'a' a 'z' o de 'A' a 'Z'.
-   **Funciones de Biblioteca:** La biblioteca `ctype.h` proporciona la función `isalpha()`, que simplifica enormemente esta comprobación.
-   **Condición de Salida:** Si se encuentra un carácter que no es alfabético, la función puede retornar `falso` inmediatamente. Si el lazo termina, significa que todos los caracteres son alfabéticos.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
---

## 2: Propiedades de Cadenas

### 2.1: Palíndromo

#### Descripción
Implementar una función que verifique si una cadena es un palíndromo, es decir, si se lee igual de izquierda a derecha que de derecha a izquierda. La verificación debe ignorar espacios en blanco y no debe ser sensible a mayúsculas/minúsculas.

:::{tip} Lógica y Consideraciones
-   **Entrada:** Una cadena de caracteres.
-   **Proceso (dos punteros/índices):**
    1.  Usar dos índices: `izquierda` al inicio de la cadena y `derecha` al final.
    2.  En un lazo `while (izquierda < derecha)`:
        a. Mover `izquierda` hacia la derecha hasta que apunte a un carácter alfabético.
        b. Mover `derecha` hacia la izquierda hasta que apunte a un carácter alfabético.
        c. Comparar los caracteres en `izquierda` y `derecha` (convertidos a minúsculas). Si son diferentes, la cadena no es un palíndromo y se puede retornar `falso`.
        d. Si son iguales, mover ambos punteros hacia el centro (`izquierda++`, `derecha--`).
-   **Salida:** Si el lazo termina, significa que todos los caracteres coincidieron, por lo que es un palíndromo y se retorna `verdadero`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 2.2: Anagrama

#### Descripción
Escribir una función que determine si una cadena es un anagrama de otra (es decir, si ambas tienen los mismos caracteres con la misma frecuencia), ignorando mayúsculas/minúsculas y espacios.

:::{tip} Lógica y Consideraciones
-   **Proceso (Arreglo de Frecuencias):**
    1.  Crear un arreglo de contadores de 26 posiciones (para el alfabeto), inicializado en cero.
    2.  Recorrer la primera cadena. Para cada carácter alfabético, incrementar el contador correspondiente (ej. para 'c', `contadores[2]++`).
    3.  Recorrer la segunda cadena. Para cada carácter alfabético, decrementar el contador correspondiente.
    4.  Finalmente, recorrer el arreglo de contadores. Si todos los contadores son cero, las cadenas son anagramas.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 2.3: Pangrama

#### Descripción
Verificar si una cadena es un pangrama, es decir, si contiene todas las letras del alfabeto inglés al menos una vez. La verificación debe ser insensible a mayúsculas/minúsculas.

:::{tip} Lógica y Consideraciones
-   **Estructura de Datos:** Un arreglo booleano de 26 posiciones (`letras_vistas`) es perfecto para este fin.
-   **Proceso:**
    1.  Inicializar el arreglo `letras_vistas` en `falso`.
    2.  Recorrer la cadena. Para cada carácter, si es una letra, marcar la posición correspondiente en el arreglo como `verdadero`.
    3.  Después de recorrer la cadena, verificar si todas las posiciones del arreglo `letras_vistas` son `verdadero`. Si es así, es un pangrama.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
---

## 3: Manipulación y Transformación

### 3.1: Tokenización

#### Descripción
Dividir una cadena en una secuencia de "tokens" (subcadenas) basándose en un carácter delimitador. La función `strtok` de C es un ejemplo clásico de esto.

:::{tip} Lógica y Consideraciones
-   **Modificación _in-place_:** `strtok` funciona modificando la cadena original. Reemplaza el delimitador encontrado por un carácter nulo (`\0`), terminando así el token actual, y guarda un puntero interno para saber dónde continuar la próxima vez.
-   **Proceso (simplificado):**
    1.  En la primera llamada, se pasa la cadena. La función busca el primer delimitador.
    2.  Reemplaza el delimitador por `\0`.
    3.  Guarda la posición siguiente al `\0` en un puntero estático.
    4.  Devuelve el puntero al inicio del token.
    5.  En llamadas subsiguientes con `NULL`, la función usa el puntero estático para continuar desde donde se quedó.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 3.2: Compresión RLE (Run-Length Encoding)

#### Descripción
Implementar una forma simple de compresión de cadenas llamada Run-Length Encoding. Esta técnica compacta una cadena reemplazando secuencias de caracteres idénticos por el número de repeticiones seguido del carácter.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Mantener un `contador` para el carácter actual.
    3.  Si el siguiente carácter es diferente o se llega al final de la cadena, se añade el `contador` y el carácter actual a la cadena de resultado.
    4.  Reiniciar el `contador` y continuar.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 3.3: Desduplicador

#### Descripción
Escribir una función que elimine los caracteres duplicados de una cadena, conservando únicamente la primera aparición de cada carácter. La modificación puede ser _in-place_.

:::{tip} Lógica y Consideraciones
-   **Estructura de Datos:** Se necesita una forma de registrar los caracteres que ya se han visto. Un arreglo booleano de 256 posiciones (`vistos`) es ideal para esto, donde cada índice corresponde a un código ASCII.
-   **Proceso (in-place):**
    1.  Utilizar dos punteros o índices: `puntero_lectura` y `puntero_escritura`, ambos comenzando al inicio de la cadena.
    2.  Recorrer la cadena con `puntero_lectura`.
    3.  Para cada carácter `c` leído:
        a. Verificar en el arreglo `vistos` si ya ha aparecido (`vistos[(int)c]`).
        b. Si no ha sido visto, copiarlo a la posición de `puntero_escritura`, marcarlo como visto (`vistos[(int)c] = VERDADERO`), y avanzar `puntero_escritura`.
    4.  Al final, colocar el carácter nulo `\0` en la posición de `puntero_escritura`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 3.4: Número a cadena con formato

#### Descripción
Transformar un número entero largo en una cadena de texto, insertando separadores de miles (puntos o comas) para mejorar la legibilidad.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Convertir el número a una cadena simple primero (usando `sprintf` o un algoritmo manual).
    2.  Calcular cuántos separadores se necesitan.
    3.  Crear una nueva cadena con el tamaño suficiente para albergar los dígitos y los separadores.
    4.  Copiar los dígitos de la cadena original a la nueva, insertando los separadores en las posiciones correctas. Es más fácil hacerlo de derecha a izquierda.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 3.5: Búsqueda de Subcadena

#### Descripción
Implementar una función que busque la primera ocurrencia de una subcadena (`needle` o aguja) dentro de una cadena principal (`haystack` o pajar). Es una reimplementación de la función `strstr`.

:::{tip} Lógica y Consideraciones
-   **Proceso (Fuerza Bruta):**
    1.  Usar un lazo exterior para recorrer la cadena `haystack` con un índice `i`.
    2.  En cada posición `i`, usar un lazo interior para comparar la subcadena de `haystack` que empieza en `i` con la cadena `needle`.
    3.  Si todos los caracteres de `needle` coinciden, devolver la posición `i` (o un puntero a `haystack[i]`).
    4.  Si el lazo exterior termina, la subcadena no se encontró.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
---

## 4: Conversión de Base Numérica

### 4.1: Binario a Decimal

#### Descripción
Convertir una cadena que representa un número en formato binario (compuesta de '0's y '1's) a su valor entero decimal correspondiente.

:::{tip} Lógica y Consideraciones
-   **Proceso:** Recorrer la cadena binaria. Para cada dígito, multiplicar el valor acumulado por 2 y sumar el valor del dígito actual (0 o 1).
-   $D = \sum_{i=0}^{n-1} b_i \cdot 2^{n-1-i}$
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 4.2: Hexadecimal a Decimal

#### Descripción
Convertir una cadena que representa un número en formato hexadecimal (dígitos 0-9 y letras A-F, insensibles a mayúsculas) a su valor entero decimal.

:::{tip} Lógica y Consideraciones
-   **Proceso:** Similar a la conversión de binario, pero la base es 16.
-   **Conversión de Dígitos:** Se necesita una lógica para convertir los caracteres 'A'- 'F' a sus valores numéricos (10-15).
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 4.3: Decimal a Binario

#### Descripción
Convertir un número entero decimal a su representación en una cadena de texto binaria.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Usar divisiones sucesivas por 2. El resto de cada división (`n % 2`) es el siguiente dígito binario.
    2.  Guardar estos dígitos en un arreglo o cadena.
    3.  Como los dígitos se generan en orden inverso, la cadena resultante debe ser invertida al final.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 4.4: Decimal a Hexadecimal

#### Descripción
Convertir un número entero decimal a su representación en una cadena de texto hexadecimal.

:::{tip} Lógica y Consideraciones
-   **Proceso:** Similar a la conversión a binario, pero usando 16 como base.
-   **Conversión de Dígitos:** Los restos entre 10 y 15 deben ser mapeados a los caracteres 'A' a 'F'.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
---

## 5: Más Ejercicios de Cadenas

### 5.1: Invertir Palabras en una Frase

#### Descripción
Escribir una función que tome una frase y la modifique de tal manera que cada palabra individual quede invertida, pero el orden de las palabras en la frase se mantenga intacto.

:::{tip} Lógica y Consideraciones
-   **Entrada:** Una cadena de caracteres que representa una frase.
-   **Proceso:**
    1.  Recorrer la cadena para identificar los límites de cada palabra. Las palabras suelen estar separadas por espacios o signos de puntuación.
    2.  Para cada palabra encontrada, se necesita una función auxiliar que pueda invertir una subcadena. Esta función tomaría punteros o índices al inicio y al final de la palabra.
    3.  La función de inversión de subcadena usaría la técnica de dos punteros (uno al inicio y otro al final de la palabra) que se mueven hacia el centro, intercambiando caracteres en cada paso.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.2: Invertir Orden de las Palabras

#### Descripción
Escribir una función que invierta el orden de las palabras en una frase. Por ejemplo, "Hola Mundo desde C" se convertiría en "C desde Mundo Hola".

:::{tip} Lógica y Consideraciones
-   **Proceso (dos pasos):**
    1.  Invertir la cadena de caracteres completa. ("Hola Mundo desde C" -> "C edsed odnuM aloH").
    2.  Recorrer la nueva cadena e invertir cada palabra individualmente (usando la lógica del ejercicio 5.1). ("C" -> "C", "edsed" -> "desde", etc.).
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO invertir_orden_palabras(REF frase)
INICIO
    // Paso 1: Invertir toda la frase
    invertir_subcadena(frase, 0, LONGITUD(frase) - 1)

    // Paso 2: Invertir cada palabra individualmente
    invertir_palabras(frase)
FIN PROCEDIMIENTO
```
:::
### 5.3: Capitalización (Title Case)

#### Descripción
Implementar una función que convierta una cadena a "Title Case", donde la primera letra de cada palabra está en mayúscula y el resto de las letras de la palabra están en minúscula.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Convertir toda la cadena a minúsculas para empezar desde un estado base consistente.
    2.  Capitalizar el primer carácter de la cadena (si es una letra).
    3.  Recorrer la cadena. Si se encuentra un espacio (u otro delimitador de palabra), capitalizar el siguiente carácter si es una letra.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.4: Contar Palabras

#### Descripción
Desarrollar una función que cuente el número de palabras en una cadena. Se puede considerar que las palabras están separadas por uno o más espacios.

:::{tip} Lógica y Consideraciones
-   **Máquina de Estados:** Una forma robusta de hacerlo es con una máquina de estados simple con dos estados: `DENTRO_DE_PALABRA` y `FUERA_DE_PALABRA`.
-   **Proceso:**
    1.  Inicializar `contador_palabras = 0` y `estado = FUERA_DE_PALABRA`.
    2.  Recorrer la cadena. Si se está `FUERA_DE_PALABRA` y se encuentra un carácter que no es un espacio, se ha encontrado el inicio de una nueva palabra. Incrementar `contador_palabras` y cambiar a `estado = DENTRO_DE_PALABRA`.
    3.  Si se está `DENTRO_DE_PALABRA` y se encuentra un espacio, cambiar a `estado = FUERA_DE_PALABRA`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.5: Eliminar Espacios Extra

#### Descripción
Crear una función que elimine los espacios en blanco redundantes de una cadena: espacios al principio, al final y múltiples espacios entre palabras, dejando solo un espacio entre cada palabra.

:::{tip} Lógica y Consideraciones
-   **Proceso (in-place con dos punteros):**
    1.  Usar un `puntero_lectura` y un `puntero_escritura`.
    2.  Recorrer la cadena con `puntero_lectura`.
    3.  Copiar un carácter de lectura a escritura solo si no es un espacio redundante. La condición para copiar podría ser: `si el carácter actual no es un espacio, O si el carácter anterior copiado no fue un espacio`.
    4.  Manejar los espacios al principio como un caso especial.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.6: Recorte de Cadena (Trim)

#### Descripción
Implementar una función `trim` que modifique una cadena para eliminar todos los espacios en blanco (o cualquier otro carácter de espaciado como tabuladores o saltos de línea) que se encuentren al principio y al final de la misma.

:::{tip} Lógica y Consideraciones
-   **Proceso (dos etapas):**
    1.  **Eliminar espacios del final:** Recorrer la cadena desde el final hacia el principio. Mientras se encuentren espacios, reemplazarlos por el carácter nulo `\0`.
    2.  **Eliminar espacios del principio:** Encontrar el puntero al primer carácter que no sea un espacio. Luego, mover todo el bloque de la cadena (incluyendo el terminador nulo) a la posición inicial usando `memmove`.
-   **Funciones de Biblioteca:** `isspace()` de `ctype.h` es útil para detectar cualquier tipo de carácter de espaciado.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.7: Reemplazar Subcadena

#### Descripción
Escribir una función que reemplace todas las ocurrencias de una subcadena por otra dentro de una cadena principal. La función debe manejar cambios en la longitud de la cadena, lo que usualmente requiere memoria dinámica.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Contar cuántas veces aparece la subcadena a buscar para calcular el tamaño final de la nueva cadena.
    2.  Reservar memoria (`malloc`) para la nueva cadena.
    3.  Recorrer la cadena original. Cuando se encuentre una ocurrencia de la subcadena a buscar, copiar la cadena de reemplazo a la nueva cadena. Si no, copiar el carácter actual.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.8: Validación de Email (Simple)

#### Descripción
Crear una función que verifique si una cadena tiene un formato de correo electrónico básico. No busca ser exhaustiva (lo cual es muy complejo), sino validar una estructura mínima.

:::{tip} Lógica y Consideraciones
-   **Reglas Mínimas:**
    1.  Debe contener exactamente un carácter `@`.
    2.  El `@` no puede ser el primer ni el último carácter.
    3.  Debe contener al menos un `.` después del `@`.
    4.  El `.` no puede estar inmediatamente después del `@`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.9: Cifrado César

#### Descripción
Implementar el Cifrado César, un tipo de cifrado por sustitución en el que cada letra en el texto original es reemplazada por una letra un número fijo de posiciones más adelante en el alfabeto, de forma circular.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Para cada carácter, si es una letra, aplicar el desplazamiento.
    3.  El desplazamiento es circular. Si al desplazar 'y' 3 posiciones se pasa de 'z', se debe volver al principio del alfabeto. Esto se logra con el operador módulo (`%`).
    4.  Ejemplo para una letra minúscula `c`: `'a' + (c - 'a' + desplazamiento) % 26`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.10: Descifrado César

#### Descripción
Escribir la función complementaria que descifre un mensaje cifrado con el Cifrado César, conociendo el desplazamiento. Es la operación inversa al ejercicio anterior.

:::{tip} Lógica y Consideraciones
-   **Proceso:** Es idéntico al cifrado, pero en lugar de sumar el desplazamiento, se resta. Para manejar el wraparound negativo, la fórmula puede ser `'a' + (c - 'a' - desplazamiento + 26) % 26`.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION descifrado_cesar(cadena, desplazamiento)
INICIO
    // La lógica es la misma que el cifrado, pero con -desplazamiento
    RETORNAR cifrado_cesar(cadena, 26 - desplazamiento)
FIN FUNCION
```
:::
### 5.11: Encontrar el Carácter Más Frecuente

#### Descripción
Desarrollar una función que encuentre y devuelva el carácter que aparece con más frecuencia en una cadena. Si hay empates, puede devolver cualquiera de los más frecuentes.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Usar un arreglo de frecuencias de 256 enteros, como en el ejercicio 1.2.
    2.  Llenar el arreglo de frecuencias recorriendo la cadena.
    3.  Recorrer el arreglo de frecuencias para encontrar el índice que tiene el valor más alto. Ese índice es el código ASCII del carácter más frecuente.
:::
:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.12: Comparación de Cadenas (Ignorando Mayúsculas)

#### Descripción
Implementar su propia versión de la función `strcasecmp`, que compara dos cadenas sin diferenciar entre mayúsculas y minúsculas.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer ambas cadenas simultáneamente con un lazo `while`.
    2.  En cada paso, comparar las versiones en minúscula (o mayúscula) de los caracteres actuales.
    3.  Si son diferentes, devolver la diferencia.
    4.  Si una cadena termina antes que la otra, son diferentes.
    5.  Si ambas terminan al mismo tiempo, son iguales.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.13: Extraer Subcadena

#### Descripción
Crear una función que extraiga una porción de una cadena. La función debe recibir la cadena original, una posición de inicio y una longitud, y devolver una nueva cadena con la subcadena extraída.

:::{tip} Lógica y Consideraciones
-   **Memoria:** La función debe reservar memoria para la nueva cadena.
-   **Proceso:**
    1.  Calcular la longitud de la subcadena y reservar memoria (longitud + 1 para el `\0`).
    2.  Copiar los caracteres desde la posición de inicio de la cadena original a la nueva cadena.
    3.  Añadir el terminador nulo `\0` al final de la nueva cadena.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.14: Justificar Texto (Simple)

#### Descripción
Implementar una función que justifique una línea de texto a un ancho específico, insertando espacios adicionales entre las palabras de la manera más uniforme posible.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Contar el número de palabras y el número total de caracteres (sin espacios).
    2.  Calcular el número total de espacios a insertar: `ancho_total - num_caracteres`.
    3.  Calcular el número de espacios a poner en cada hueco entre palabras.
    4.  Construir la nueva cadena añadiendo las palabras y el número calculado de espacios entre ellas.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 5.15: Acrónimo

#### Descripción
Escribir una función que genere un acrónimo a partir de una frase, tomando la primera letra de cada palabra.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena.
    2.  Usar una bandera o estado para saber si el carácter actual es el inicio de una nueva palabra.
    3.  Si es el inicio de una palabra y es una letra, añadirla (en mayúscula) a la cadena de resultado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
---

## 6: Cadenas y Algoritmos

### 6.1: Distancia de Hamming

#### Descripción
Implementar una función que calcule la distancia de Hamming entre dos cadenas de igual longitud. Esta distancia es el número de posiciones en las que los caracteres correspondientes son diferentes.

:::{tip} Lógica y Consideraciones
-   **Precondición:** Las cadenas deben tener la misma longitud.
-   **Proceso:**
    1.  Inicializar un `contador` en 0.
    2.  Recorrer ambas cadenas simultáneamente con un lazo `for`.
    3.  En cada posición `i`, si `cadena1[i] != cadena2[i]`, incrementar el `contador`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.2: Subsecuencia Común Más Larga (LCS)

#### Descripción
Escribir una función que encuentre la longitud de la subsecuencia común más larga (LCS) entre dos cadenas. Una subsecuencia no tiene por qué ser contigua.

:::{tip} Lógica y Consideraciones
-   **Algoritmo:** Este es un problema clásico de programación dinámica.
-   **Proceso:**
    1.  Crear una matriz 2D `dp` de tamaño `(longitud1+1) x (longitud2+1)`.
    2.  `dp[i][j]` almacenará la longitud de la LCS de `cadena1[0..i-1]` y `cadena2[0..j-1]`.
    3.  Llenar la matriz usando la recurrencia:
        -   Si `cadena1[i-1] == cadena2[j-1]`, entonces `dp[i][j] = 1 + dp[i-1][j-1]`.
        -   Si no, `dp[i][j] = MAXIMO(dp[i-1][j], dp[i][j-1])`.
-   **Salida:** El resultado es el valor en `dp[longitud1][longitud2]`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION lcs(cadena1, cadena2)
VARIABLES:
    dp (matriz 2D)
INICIO
    // ... inicializar y llenar la matriz dp ...
    RETORNAR dp[LONGITUD(cadena1)][LONGITUD(cadena2)]
FIN FUNCION
```
:::
### 6.3: Validación de IP Simple

#### Descripción
Crear una función que verifique si una cadena representa una dirección IPv4 válida. Debe consistir en cuatro números entre 0 y 255, separados por puntos.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Usar `strtok` o una función similar para dividir la cadena por el delimitador `.`.
    2.  Contar el número de tokens. Deben ser exactamente 4.
    3.  Para cada token, convertirlo a entero (usando `atoi` o `sscanf`).
    4.  Verificar que el número esté en el rango [0, 255].
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.4: Convertir a `snake_case`

#### Descripción
Implementar una función que convierta una cadena en `camelCase` o `PascalCase` a `snake_case`. Esto implica insertar un guion bajo antes de cada letra mayúscula y convertir toda la cadena a minúsculas.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Si se encuentra una letra mayúscula (y no es el primer carácter), añadir un `_` a la cadena de resultado antes de añadir la letra.
    3.  Convertir cada carácter a minúscula antes de añadirlo a la cadena de resultado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.5: Convertir a `camelCase`

#### Descripción
Implementar una función que convierta una cadena en `snake_case` a `camelCase`. Esto implica eliminar los guiones bajos y poner en mayúscula la letra que les seguía.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Usar una bandera `capitalizar_siguiente`.
    3.  Si el carácter actual es `_`, poner `capitalizar_siguiente` a `verdadero` y no añadir nada al resultado.
    4.  Si no es `_`, y `capitalizar_siguiente` es `verdadero`, convertir el carácter a mayúscula, añadirlo al resultado y poner la bandera a `falso`. Si no, simplemente añadirlo.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.6: Rotación de Cadena

#### Descripción
Escribir una función que determine si una cadena `s2` es una rotación de otra cadena `s1`.

:::{tip} Lógica y Consideraciones
-   **Propiedad Clave:** `s2` es una rotación de `s1` si y solo si `s2` es una subcadena de `s1` concatenado consigo mismo (`s1s1`).
-   **Proceso:**
    1.  Verificar que `s1` y `s2` tengan la misma longitud. Si no, no pueden ser rotaciones.
    2.  Crear una nueva cadena `temp` que sea `s1 + s1`.
    3.  Buscar si `s2` es una subcadena de `temp`.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.7: Eliminar Comentarios

#### Descripción
Crear una función que reciba una cadena (que puede representar una o más líneas de código) y elimine los comentarios de estilo C (`//...` hasta el final de la línea y `/*...*/` incluyendo el contenido).

:::{tip} Lógica y Consideraciones
-   **Máquina de Estados:** Este problema se resuelve mejor con una máquina de estados para rastrear si el procesador está en modo `NORMAL`, `DENTRO_DE_COMENTARIO_LINEA`, o `DENTRO_DE_COMENTARIO_BLOQUE`.
:::


:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.8: Análisis de URL Simple

#### Descripción
Dada una URL en formato de cadena, escribir una función que la analice y extraiga sus componentes principales: protocolo, host y ruta.

:::{tip} Lógica y Consideraciones
-   **Proceso:** Usar funciones de búsqueda de caracteres (`:`, `/`) para encontrar los delimitadores y luego extraer las subcadenas correspondientes.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO analizar_url(url, REF protocolo, REF host, REF ruta)
VARIABLES:
    pos_protocolo, pos_host_inicio, pos_ruta_inicio (enteros)
INICIO
    pos_protocolo = encontrar_caracter(url, ':')
    protocolo = extraer_subcadena(url, 0, pos_protocolo)

    // ... lógica similar para host y ruta ...
FIN PROCEDIMIENTO
```
:::

### 6.9: Generador de "Slugs"

#### Descripción
Un "slug" es una versión de una cadena amigable para URLs. Escribir una función que convierta un título en un slug: debe estar en minúsculas, los espacios deben ser reemplazados por guiones y se deben eliminar todos los caracteres no alfanuméricos.

:::{tip} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer la cadena de entrada.
    2.  Para cada carácter, convertirlo a minúscula.
    3.  Si es una letra o un número, añadirlo a la cadena de resultado.
    4.  Si es un espacio, y el último carácter añadido al resultado no fue un guion, añadir un guion.
    5.  Ignorar todos los demás caracteres.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
### 6.10: Primer Carácter No Repetido

#### Descripción
Implementar una función que encuentre y devuelva el primer carácter en una cadena que no se repite en el resto de la cadena.

:::{tip} Lógica y Consideraciones
-   **Proceso (dos pasadas):**
    1.  **Primera pasada:** Usar un arreglo de frecuencias para contar las apariciones de cada carácter (como en el ejercicio 1.2).
    2.  **Segunda pasada:** Recorrer la cadena de entrada original. El primer carácter para el cual su contador en el arreglo de frecuencias sea 1, es el resultado.
:::

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
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
:::
