---
title: "Manipulación de bits"
short_title: "Bits"
subtitle: "Controlando los unos y ceros"
numbering:
  code: true
---

## Introducción: El Poder a Nivel de Bit

En el corazón de cada operación que realiza una computadora se encuentran los
bits. La **manipulación de bits** es el conjunto de técnicas que nos permite
interactuar directamente con esta representación binaria de los datos. En C,
dominar estas técnicas es una habilidad práctica y poderosa para optimizar el
rendimiento, ahorrar memoria e interactuar con hardware.

## Representación Binaria

Todos los tipos de datos en C se almacenan como una secuencia de bits. Un
`unsigned char` (1 byte) que representa el número 200, en binario es `11001000`.

```text
Bit:      7   6   5   4   3   2   1   0
Valor:  128  64  32  16   8   4   2   1
-----------------------------------------
Binario:  1   1   0   0   1   0   0   0
Suma:   128 + 64+ 0 + 0 + 8 + 0 + 0 + 0 = 200
```

## Los Operadores a Nivel de Bits

### 1. AND a nivel de bits (`&`)

El bit del resultado es `1` solo si ambos bits correspondientes en los operandos
son `1`. Su uso principal es para **verificar** o **apagar** bits.

:::{exercise}
:label: espar
¿Es un número par?

Un número es par si su bit menos significativo (LSB, bit 0) es 0. Escribí una
función que use el operador `&` para determinar si un número es par.

:::

:::{solution}
:for: espar
:class: dropdown

```{code-block}c
#include <stdbool.h>

bool es_par(int numero) {
    // La máscara 1 (00000001) aísla el último bit.
    // Si el resultado de (numero & 1) es 0, el bit era 0.
    return (numero & 1) == 0;
}
```

:::

### 2. OR a nivel de bits (`|`)

El bit del resultado es `1` si al menos uno de los bits correspondientes es `1`.
Su uso principal es para **encender** bits.

:::{exercise}
:label: activar

Encender un Flag Dado un `unsigned char` que representa un
conjunto de 8 flags, escribí una función que encienda el 4to bit (bit en la
posición 3) sin modificar los demás. :::

:::{solution}
:for: activar
:class: dropdown

```{code-block} c
void activar_flag_4(unsigned char *estado) {
    // La máscara (1 << 3) es 8 (00001000).
    // El OR encenderá ese bit sin tocar los otros.
    *estado = *estado | (1 << 3);
}
```

:::

### 3. XOR a nivel de bits (`^`)

El bit del resultado es `1` solo si los bits correspondientes son
**diferentes**. Su uso principal es para **alternar (toggle)** bits.

:::{exercise}
:label: intercambio

Intercambio con XOR Escribí una función que intercambie los
valores de dos variables enteras **sin usar una variable temporal**, utilizando
únicamente el operador XOR. :::

:::{solution}
:for: intercambio
:class: dropdown

```{code-block} c
void swap_xor(int *a, int *b) {
    if (a != b) { // Previene que se anulen si apuntan al mismo lugar
        *a = *a ^ *b;
        *b = *a ^ *b; // *b se convierte en el valor original de *a
        *a = *a ^ *b; // *a se convierte en el valor original de *b
    }
}
```

:::

### 4. NOT a nivel de bits (`~`)

El operador NOT (complemento a uno) invierte todos los bits de su operando. `0`
se convierte en `1` y `1` en `0`.

:::{exercise}
:label: mask

Crear una Máscara para Apagar Escribí una expresión que cree una
máscara para apagar el 2do bit (posición 1) de un `char`, sin afectar a los
demás. 

::: 

:::{solution}
:for: mask
:class: dropdown

```{code-block} c
// Máscara para el 2do bit: (1 << 1) -> 00000010
// Máscara invertida: ~(1 << 1) -> 11111101
unsigned char mascara_apagado = ~(1 << 1);
```

:::

### 5. Desplazamientos (`<<` y `>>`)

- `<<`: Desplaza los bits a la izquierda. Equivale a multiplicar por potencias
  de 2.

  **Ejemplo:** `5 << 2`

  ```text
  00000101 (5) << 2  -->  00010100 (20)
  ```

- `>>`: Desplaza los bits a la derecha. Equivale a dividir por potencias de 2.

  **Ejemplo:** `20 >> 2`

  ```text
  00010100 (20) >> 2  -->  00000101 (5)
  ```

:::{exercise}
:label: multiplicacion

Multiplicación y División Rápida Escribí dos macros,
`MULT_POR_8(x)` y `DIV_POR_4(x)`, que usen operadores de desplazamiento para
realizar las operaciones. :::

:::{solution}
:for: multiplicacion
:class: dropdown

```{code-block} c
#define MULT_POR_8(x) ((x) << 3) // 2^3 = 8
#define DIV_POR_4(x)  ((x) >> 2) // 2^2 = 4
```

:::

## Ejercicios de Aplicación (Recetario)

### 1. Obtener el N-ésimo Bit

:::{exercise}
:label: get_bit

Escribí una función `int get_bit(int numero, int n)` que devuelva
el valor (0 o 1) del bit en la posición `n`. :::

:::{solution}
:for: get_bit
:class: dropdown

```{code-block} c
int get_bit(int numero, int n) {
    // Desplaza el bit n a la posición 0 y usa AND con 1 para aislarlo.
    return (numero >> n) & 1;
}
```

:::

### 2. Establecer el N-ésimo Bit

:::{exercise}
:label: set_bit
Escribí una función `void set_bit(int *numero, int n)` que
encienda el bit en la posición `n`. :::

:::{solution}
:for: set_bit
:class: dropdown

```{code-block} c
void set_bit(int *numero, int n) {
    // Crea una máscara con el bit n encendido (ej: 00001000) y aplica OR.
    *numero |= (1 << n);
}
```

:::

### 3. Limpiar el N-ésimo Bit

:::{exercise}
:label: clear_bit

Escribí una función `void clear_bit(int *numero, int n)` que
apague el bit en la posición `n`. :::

:::{solution}
:for: clear_bit
:class: dropdown

```{code-block} c
void clear_bit(int *numero, int n) {
    // Crea una máscara con el bit n en 0 y el resto en 1, y aplica AND.
    *numero &= ~(1 << n);
}
```

:::

### 4. Contar Bits Encendidos (Hamming Weight)

:::{exercise}
:label: kernighan

Implementar una función que cuente el número de bits que están en
`1` en la representación binaria de un número, usando el algoritmo de Brian
Kernighan. 

:::

:::{solution}
:for: kernighan
:class: dropdown

 **Algoritmo de Brian Kernighan**: La operación
`n & (n - 1)` apaga el bit encendido menos significativo. El número de veces que
se puede hacer esta operación antes de que `n` sea 0 es el número de bits
encendidos.

```{code-block} c
int contar_bits_encendidos(int n) {
    int contador = 0;
    while (n > 0) {
        n = n & (n - 1); // Apaga el bit '1' de más a la derecha
        contador++;
    }
    return contador;
}
```

:::

### 5. Verificar si es Potencia de Dos

:::{exercise}
:label: potencia

Escribí una función que determine si un número entero positivo es
una potencia de dos (2, 4, 8, 16...). :::

:::{solution}
:for: potencia
:class: dropdown

**Propiedad**: Un número que es potencia de dos
tiene exactamente un bit encendido en su representación binaria (ej. 8 es
`1000`). El número `n-1` tendrá todos los bits a la derecha de ese bit
encendidos (ej. 7 es `0111`). Por lo tanto, `n & (n - 1)` será siempre cero.

```{code-block} c
#include <stdbool.h>

bool es_potencia_de_dos(int n) {
    // n > 0 asegura que no se incluya el 0.
    // (n & (n - 1)) == 0 verifica que solo haya un bit encendido.
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

:::

## Glosario

:::{glossary}

Máscara de Bits (Bitmask)
: Un valor numérico utilizado para seleccionar,
modificar o consultar bits específicos de otro valor mediante operaciones a
nivel de bits como AND, OR y XOR.

Endianness
: Se refiere al orden en que se almacenan en memoria los bytes que
componen un tipo de dato multibyte. Es una consideración crucial para la
portabilidad de datos binarios.

:::
