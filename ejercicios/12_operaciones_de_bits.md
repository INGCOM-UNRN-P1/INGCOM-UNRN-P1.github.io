---
title: "Ejercicios: Operaciones de Bits"
short_title: "12. Operaciones de Bits"
---

## Acerca de

La manipulación de bits es una habilidad fundamental en la programación en C,
especialmente para el desarrollo de bajo nivel, la optimización y la
programación de sistemas embebidos. Estos ejercicios se centran en el uso de los
operadores a nivel de bits (`&`, `|`, `^`, `~`, `<<`, `>>`) para manipular los
datos de forma directa y eficiente.

## 1: Manipulación de Bits Individuales

### 1.1: Obtener el N-ésimo Bit

Escribir una función `int get_bit(int numero, int n)` que devuelva el valor del
bit en la posición `n` de un número (0 o 1).

:::{hint} Lógica y Consideraciones

- **Proceso**: Crear una máscara desplazando un 1 `n` posiciones a la izquierda
  (`1 << n`). Luego, aplicar un AND a nivel de bits entre el número y la
  máscara. Si el resultado no es cero, el bit estaba encendido.
- `(numero & (1 << n)) != 0`\:::

### 1.2: Establecer el N-ésimo Bit (Set)

Escribir una función `int set_bit(int numero, int n)` que encienda (ponga en 1)
el bit en la posición `n` sin alterar los demás.

:::{hint} Lógica y Consideraciones

- **Proceso**: Crear la misma máscara (`1 << n`) y aplicar un OR a nivel de bits
  entre el número y la máscara.
- `numero = numero | (1 << n);`

:::

### 1.3: Limpiar el N-ésimo Bit (Clear)

Escribir una función `int clear_bit(int numero, int n)` que apague (ponga en 0)
el bit en la posición `n`.

:::{hint} Lógica y Consideraciones

- **Proceso**: Crear la máscara (`1 << n`), invertirla con el operador NOT
  (`~`), y luego aplicar un AND a nivel de bits. La máscara invertida tendrá
  ceros solo en la posición `n`.
- `numero = numero & ~(1 << n);`

:::

### 1.4: Alternar el N-ésimo Bit (Toggle)

Escribir una función `int toggle_bit(int numero, int n)` que invierta el valor
del bit en la posición `n` (de 0 a 1, o de 1 a 0).

:::{hint} Lógica y Consideraciones

- **Proceso**: Crear la máscara (`1 << n`) y aplicar un XOR a nivel de bits. El
  XOR con 1 invierte un bit, mientras que el XOR con 0 lo deja igual.
- `numero = numero ^ (1 << n);`

:::

## 2: Algoritmos con Bits

### 2.1: Contar Bits Encendidos (Hamming Weight)

Implementar una función que cuente el número de bits que están en 1 en la
representación binaria de un número.

:::{hint} Lógica y Consideraciones

- **Algoritmo de Brian Kernighan**: En un bucle, mientras el número no sea cero,
  aplicar la operación `n = n & (n - 1)`. Esta operación apaga el bit encendido
  menos significativo en cada iteración. El número de iteraciones es el número
  de bits encendidos.

:::

### 2.2: Verificar si es Potencia de Dos

Escribir una función que determine si un número entero positivo es una potencia
de dos (ej. 2, 4, 8, 16...).

:::{hint} Lógica y Consideraciones

- **Propiedad**: Un número `n` que es potencia de dos tiene exactamente un bit
  encendido en su representación binaria. El número `n-1` tendrá todos los bits
  a la derecha de ese bit encendidos. Por lo tanto, `n & (n - 1)` será siempre
  cero.
- **Condición**: `n > 0 && (n & (n - 1)) == 0`

:::

### 2.3: Intercambio con XOR

Implementar una función `void swap(int *a, int *b)` que intercambie los valores
de dos variables sin usar una variable temporal, utilizando únicamente el
operador XOR.

:::{hint} Lógica y Consideraciones

- **Proceso**:
  1. `*a = *a ^ *b;`
  2. `*b = *a ^ *b;` // Ahora `b` tiene el valor original de `a`
  3. `*a = *a ^ *b;` // Ahora `a` tiene el valor original de `b`

:::

### 2.4: Uso de Máscaras de Bits para Permisos

Simular un sistema de permisos de archivo (Lectura, Escritura, Ejecución) usando
una sola variable `unsigned char`.

:::{hint} Lógica y Consideraciones

- **Definir Máscaras**: `#define LECTURA 1<<0`, `#define ESCRITURA 1<<1`,
  `#define EJECUCION 1<<2`
- **Añadir Permiso**: `permisos = permisos | ESCRITURA;`
- **Quitar Permiso**: `permisos = permisos & ~EJECUCION;`
- **Verificar Permiso**: `if (permisos & LECTURA) { ... }`

:::
