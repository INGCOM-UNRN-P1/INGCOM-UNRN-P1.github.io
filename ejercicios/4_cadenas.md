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

## 1: Análisis de Cadenas

### 1.1: Contar vocales

Escribir una función que recorra una cadena y cuente cuántos de sus caracteres
son vocales (a, e, i, o, u). El algoritmo debe ser insensible a mayúsculas y
minúsculas.

- **Ejemplo**: "Hola Mundo" -> 4 vocales.

### 1.2: Contabilizador de caracteres

Implementar una función que calcule la frecuencia de cada carácter en una
cadena.

**Algoritmo Sugerido:**

1.  Crear un arreglo de enteros de tamaño 256 (para cubrir todos los valores
    ASCII) e inicializarlo en cero. `int contadores[256] = {0};
2.  Recorrer la cadena de entrada carácter por carácter.
3.  Para cada carácter `c`, usar su valor ASCII como índice en el arreglo de
    contadores e incrementar la cuenta: `contadores[(int)c]++;`.
4.  Al final, recorrer el arreglo de contadores e imprimir los caracteres cuya
    cuenta sea mayor a cero.

- **Ejemplo**: "casa" -> `c:1, a:2, s:1`.

### 1.3: ¿Es un número válido?

Desarrollar una función que verifique si una cadena representa un número de
punto flotante válido.

**Lógica de Validación:**

1. Puede tener un signo opcional (`+` o `-`) solo al principio.
2. Debe contener al menos un dígito.
3. Puede contener como máximo un punto decimal (`.`).
4. Todos los demás caracteres deben ser dígitos (`0`-`9`).

- **Ejemplo**: "-123.45" es válido, pero "12.34.5" o "12a3" no lo son.

### 1.4: ¿Es alfabética?

Crear una función que determine si una cadena contiene únicamente caracteres
alfabéticos (a-z, A-Z).

- **Ejemplo**: "SoloLetras" es válido, "Con1Numero" no.

## 2: Propiedades de Cadenas

### 2.1: Palíndromo

Implementar una función que verifique si una cadena es un palíndromo (se lee
igual en ambos sentidos), ignorando espacios y mayúsculas/minúsculas.

**Algoritmo Sugerido:**

1. Utilizar dos índices, `izquierda` al inicio y `derecha` al final de la
   cadena.
2. Mientras `izquierda < derecha`: a. Avanzar `izquierda` si el carácter no es
   alfabético. b. Retroceder `derecha` si el carácter no es alfabético. c.
   Comparar los caracteres (convertidos a minúsculas). Si son diferentes, no es
   un palíndromo. d. Mover ambos índices hacia el centro.

- **Ejemplo**: "Anita lava la tina" es un palíndromo.

### 2.2: Anagrama

Escribir una función que determine si una cadena es un anagrama de otra. Un
método eficiente es usar un arreglo de contadores de frecuencia.

**Algoritmo Sugerido:**

1. Crear un arreglo de contadores de 26 posiciones (para el alfabeto)
   inicializado en cero.
2. Recorrer la primera cadena, incrementando el contador para cada letra.
3. Recorrer la segunda cadena, decrementando el contador para cada letra.
4. Si al final todos los contadores en el arreglo son cero, las cadenas son
   anagramas.

- **Ejemplo**: "roma" y "amor" son anagramas.

### 2.3: Pangrama

Verificar si una cadena es un pangrama (contiene todas las letras del alfabeto
inglés al menos una vez).

**Algoritmo Sugerido:**

1. Crear un arreglo booleano de 26 posiciones, inicializado en falso.
2. Recorrer la cadena, y para cada carácter alfabético, marcar la posición
   correspondiente en el arreglo como verdadero.
3. Al final, verificar si todas las posiciones del arreglo son verdaderas.

- **Ejemplo**: "El veloz murciélago hindú comía feliz cardillo y kiwi.".

## 3: Manipulación y Transformación

### 3.1: Tokenización

Dividir una cadena en "tokens" usando un delimitador. La función debe modificar
la cadena original, reemplazando los delimitadores por `'\0'`, y devolver un
arreglo de punteros a cada token.

```mermaid
:caption: "Memoria durante la tokenización de \"Hola,Mundo\""
graph TD
    subgraph Memoria de la Cadena
        H(H) --> o(o) --> l(l) --> a(a) --> coma(,)
    end
    subgraph "Después de strtok"
        H2(H) --> o3(o) --> l2(l) --> a2(a) --> NUL2(\'0\') --> M2(M) --> u2(u) --> n2(n) --> d2(d) --> o4(o) --> NUL3(\'0\')
    end
    subgraph "Arreglo de Punteros (char **)"
        P1(ptr[0]) --> H2;
        P2(ptr[1]) --> M2;
    end
```

### 3.2: Compresión RLE (Run-Length Encoding)

Compactar una cadena reemplazando secuencias de caracteres idénticos por el
número de repeticiones seguido del carácter.

- **Entrada**: "AAABBC"
- **Salida**: "3A2B1C"

### 3.3: Desduplicador

Eliminar caracteres duplicados de una cadena, conservando la primera aparición
de cada uno.

- **Entrada**: "HHolaa Mundo"
- **Salida**: "Hola Mund"

### 3.4: Número a cadena con formato

Transformar un número entero en una cadena, insertando separadores de miles.

- **Entrada**: `1234567`
- **Salida**: "1.234.567"

### 3.5: Búsqueda de Subcadena

Implementar una función que busque la primera ocurrencia de una subcadena
(`needle`) dentro de una cadena principal (`haystack`).

- **Ejemplo**: Buscar "la" en "Hola" debe ser exitoso.

## 4: Conversión de Base Numérica

### 4.1: Binario a Decimal

Convertir una cadena que representa un número binario a su valor decimal. El
valor de un número binario $b_n b_{n-1} ... b_1 b_0$ se calcula como:

$$ D = \sum\_{i=0}^{n} b_i \cdot 2^i $$

- **Ejemplo**: "1101" ->
  $1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 = 13$.

### 4.2: Hexadecimal a Decimal

Convertir una cadena hexadecimal (con dígitos 0-9, A-F) a su valor decimal.

- **Ejemplo**: "1A" -> $1 \cdot 16^1 + 10 \cdot 16^0 = 26$.

### 4.3: Decimal a Binario

Convertir un número decimal a su representación en una cadena binaria. El
algoritmo se basa en divisiones sucesivas por 2, donde los restos forman los
dígitos binarios en orden inverso.

- **Ejemplo**: `13` -> "1101".

### 4.4: Decimal a Hexadecimal

Convertir un número decimal a su representación hexadecimal. Similar al
anterior, pero usando divisiones por 16 y mapeando los restos 10-15 a los
caracteres A-F.

- **Ejemplo**: `26` -> "1A".
