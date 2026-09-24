---
title: "Ejercicios: Operaciones de Bits"
short_title: "12. Operaciones de Bits"
---

# Ejercicios: Operaciones de Bits

## Acerca de

La manipulación de bits es una competencia esencial en C11 para la programación de bajo nivel,
el diseño de controladores de hardware, sistemas embebidos y algoritmos de compresión y criptografía.
Estos ejercicios ejercitan los operadores a nivel de bits (`&`, `|`, `^`, `~`, `<<`, `>>`),
el uso de enteros sin signo de ancho fijo (`<stdint.h>`) y el diseño de máscaras booleanas.

### Capítulos de Apunte Correspondientes
- [Modelo de Memoria](../../apunte/bloque_2_memoria/1_modelo_memoria.md)

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Representación binaria posicional y enteros sin signo de ancho fijo (`<stdint.h>`).
2. Operadores a nivel de bit en C11: AND (`&`), OR (`|`), XOR (`^`), NOT (`~`), y desplazamientos (`<<`, `>>`).
3. Construcción y aplicación de máscaras booleanas de bits (`(1U << n)`).
4. Precedencia de operadores en C y uso estricto de paréntesis defensivos.

### Cuestiones de Estilo Aplicables
- **Tipos de ancho fijo:** Utilizá tipos sin signo como `uint32_t` o `uint8_t` de `<stdint.h>`
  para evitar comportamientos dependientes de signo o plataforma en desplazamientos a la derecha.
- **Paréntesis explícitos:** Dado que los operadores de bits tienen menor precedencia que los
  operadores relacionales y aritméticos, agrupá siempre las operaciones entre paréntesis (ej. `(n & (1U << pos)) != 0`).
- **Constantes sin signo:** Empleá literales con sufijo `U` (ej. `1U << n`) para evitar desbordamientos de enteros con signo.

---

## Manipulación de Bits Individuales

(ej_b4_c05_01)=
### Ejercicio 4.05.01 - Lectura del N-ésimo Bit ⭐⭐⭐⭐☆

:::{exercise}
:label: get_bit
:enumerator: bits-1

Implementá una función pura `uint8_t obtener_bit(uint32_t valor, uint8_t n)` que devuelva
el estado binario (`0` o `1`) del bit en la posición `n` (0-indexado desde el bit menos significativo).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Máscara de bits `(1U << n)`, operador AND bitwise `&`, tipos `<stdint.h>`.  
**Techo conceptual:** Prohibido el uso de divisiones o módulos aritméticos.

#### Contrato de la Función
- **Firma:** `uint8_t obtener_bit(uint32_t valor, uint8_t n);`
- **Precondiciones:** `n < 32`.
- **Postcondiciones:** Retorna `1` si el bit en la posición `n` está encendido; de lo contrario retorna `0`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`valor`, `n`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `valor = 5 (0b101)`, `n = 0` | `1` | Bit 0 encendido |
| **Normal** | `valor = 5 (0b101)`, `n = 1` | `0` | Bit 1 apagado |
| **Normal** | `valor = 5 (0b101)`, `n = 2` | `1` | Bit 2 encendido |
| **Borde (MSB)** | `valor = 0x80000000`, `n = 31`| `1` | Bit más significativo (MSB) |
| **Borde (Cero)** | `valor = 0`, `n = 15` | `0` | Todos los bits apagados |

:::
<!-- {exercise} -->

::::{solution} get_bit
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdint.h>

uint8_t obtener_bit(uint32_t valor, uint8_t n)
{
    assert(n < 32);
    return (uint8_t)((valor >> n) & 1U);
}

int main(void)
{
    assert(obtener_bit(5U, 0) == 1);
    assert(obtener_bit(5U, 1) == 0);
    assert(obtener_bit(5U, 2) == 1);
    assert(obtener_bit(0x80000000U, 31) == 1);
    assert(obtener_bit(0U, 15) == 0);
    return 0;
}
```

::::
<!-- {solution} get_bit -->

---

(ej_b4_c05_02)=
### Ejercicio 4.05.02 - Encendido del N-ésimo Bit (Set Bit) ⭐⭐⭐⭐☆

:::{exercise}
:label: set_bit
:enumerator: bits-2

Implementá una función `uint32_t encender_bit(uint32_t valor, uint8_t n)` que encienda
(asigne a 1) el bit en la posición `n` preservando intactos todos los demás bits.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Operador OR bitwise `|`, máscara desplazada `(1U << n)`.  
**Techo conceptual:** Prohibido el uso de lazos iterativos.

#### Contrato de la Función
- **Firma:** `uint32_t encender_bit(uint32_t valor, uint8_t n);`
- **Precondiciones:** `n < 32`.
- **Postcondiciones:** Retorna `valor | (1U << n)`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`valor`, `n`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `valor = 0`, `n = 3` | `8` (`0b1000`) | Encendido de un bit en entero nulo |
| **Normal (Idempotente)**| `valor = 8`, `n = 3` | `8` | Bit ya encendido permanece inalterado |
| **Borde (LSB)** | `valor = 0`, `n = 0` | `1` | Encendido del bit menos significativo |
| **Borde (MSB)** | `valor = 0`, `n = 31` | `0x80000000` | Encendido del bit más significativo |

:::
<!-- {exercise} -->

::::{solution} set_bit
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdint.h>

uint32_t encender_bit(uint32_t valor, uint8_t n)
{
    assert(n < 32);
    return valor | (1U << n);
}

int main(void)
{
    assert(encender_bit(0U, 3) == 8U);
    assert(encender_bit(8U, 3) == 8U);
    assert(encender_bit(0U, 0) == 1U);
    assert(encender_bit(0U, 31) == 0x80000000U);
    return 0;
}
```

::::
<!-- {solution} set_bit -->

---

(ej_b4_c05_03)=
### Ejercicio 4.05.03 - Apagado del N-ésimo Bit (Clear Bit) ⭐⭐⭐⭐☆

:::{exercise}
:label: clear_bit
:enumerator: bits-3

Implementá una función `uint32_t apagar_bit(uint32_t valor, uint8_t n)` que apague
(asigne a 0) el bit en la posición `n` preservando el estado de todos los demás bits.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Operador NOT bitwise `~`, operador AND bitwise `&`.  
**Techo conceptual:** Prohibido el uso de lazos iterativos.

#### Contrato de la Función
- **Firma:** `uint32_t apagar_bit(uint32_t valor, uint8_t n);`
- **Precondiciones:** `n < 32`.
- **Postcondiciones:** Retorna `valor & ~(1U << n)`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`valor`, `n`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `valor = 15 (0b1111)`, `n = 1` | `13 (0b1101)` | Apagado selectivo del bit 1 |
| **Normal (Idempotente)**| `valor = 13 (0b1101)`, `n = 1` | `13 (0b1101)` | Bit ya apagado permanece inalterado |
| **Borde (LSB)** | `valor = 1`, `n = 0` | `0` | Apagado del LSB a cero |

:::
<!-- {exercise} -->

::::{solution} clear_bit
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdint.h>

uint32_t apagar_bit(uint32_t valor, uint8_t n)
{
    assert(n < 32);
    return valor & ~(1U << n);
}

int main(void)
{
    assert(apagar_bit(15U, 1) == 13U);
    assert(apagar_bit(13U, 1) == 13U);
    assert(apagar_bit(1U, 0) == 0U);
    assert(apagar_bit(0xFFFFFFFFU, 31) == 0x7FFFFFFFU);
    return 0;
}
```

::::
<!-- {solution} clear_bit -->

---

(ej_b4_c05_04)=
### Ejercicio 4.05.04 - Inversión del N-ésimo Bit (Toggle Bit) ⭐⭐⭐⭐☆

:::{exercise}
:label: toggle_bit
:enumerator: bits-4

Implementá una función `uint32_t conmutar_bit(uint32_t valor, uint8_t n)` que invierta
el estado del bit en la posición `n` (de 0 a 1, o de 1 a 0) mediante el operador XOR.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Operador XOR bitwise `^`, máscara `(1U << n)`.  
**Techo conceptual:** Prohibido el uso de sentencias condicionales `if-else`.

#### Contrato de la Función
- **Firma:** `uint32_t conmutar_bit(uint32_t valor, uint8_t n);`
- **Precondiciones:** `n < 32`.
- **Postcondiciones:** Retorna `valor ^ (1U << n)`. Conmutar dos veces retorna el valor original.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`valor`, `n`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal (0 a 1)** | `valor = 0`, `n = 2` | `4` | Conmutación de 0 a 1 |
| **Normal (1 a 0)** | `valor = 4`, `n = 2` | `0` | Conmutación de 1 a 0 |
| **Involución** | `valor = 42`, `n = 5` dos veces | `42` | $x \oplus m \oplus m = x$ |

:::
<!-- {exercise} -->

::::{solution} toggle_bit
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdint.h>

uint32_t conmutar_bit(uint32_t valor, uint8_t n)
{
    assert(n < 32);
    return valor ^ (1U << n);
}

int main(void)
{
    assert(conmutar_bit(0U, 2) == 4U);
    assert(conmutar_bit(4U, 2) == 0U);
    assert(conmutar_bit(conmutar_bit(42U, 5), 5) == 42U);
    return 0;
}
```

::::
<!-- {solution} toggle_bit -->

---

## Algoritmos con Bits

(ej_b4_c05_05)=
### Ejercicio 4.05.05 - Conteo de Bits Encendidos (Hamming Weight) ⭐⭐⭐⭐☆

:::{exercise}
:label: hamming_weight
:enumerator: bits-5

Implementá una función `uint8_t contar_bits_encendidos(uint32_t n)` que devuelva la cantidad
de bits en 1 en la representación binaria de `n`, implementando el algoritmo óptimo de
Brian Kernighan: en cada iteración se aplica `n = n & (n - 1)`, apagando el bit encendido menos significativo.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Algoritmo de Brian Kernighan, complejidad proporcional al número de bits encendidos $O(k)$.  
**Techo conceptual:** Prohibido iterar 32 veces incondicionalmente.

#### Contrato de la Función
- **Firma:** `uint8_t contar_bits_encendidos(uint32_t n);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna el peso de Hamming $0 \le k \le 32$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `n` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `7 (0b0111)` | `3` | Tres bits encendidos |
| **Normal** | `10 (0b1010)` | `2` | Dos bits encendidos alternados |
| **Borde (Cero)** | `0` | `0` | Cero iteraciones en bucle |
| **Borde (Todos 1)** | `0xFFFFFFFF` | `32` | Máximo conteo en entero de 32 bits |

:::
<!-- {exercise} -->

::::{solution} hamming_weight
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdint.h>

uint8_t contar_bits_encendidos(uint32_t n)
{
    uint8_t cuenta = 0;
    while (n != 0)
    {
        n &= (n - 1U);
        cuenta++;
    }
    return cuenta;
}

int main(void)
{
    assert(contar_bits_encendidos(7U) == 3);
    assert(contar_bits_encendidos(10U) == 2);
    assert(contar_bits_encendidos(0U) == 0);
    assert(contar_bits_encendidos(0xFFFFFFFFU) == 32);
    assert(contar_bits_encendidos(1U) == 1);
    return 0;
}
```

::::
<!-- {solution} hamming_weight -->

---

(ej_b4_c05_06)=
### Ejercicio 4.05.06 - Verificación de Potencia de Dos ⭐⭐☆☆☆

:::{exercise}
:label: es_potencia_de_dos
:enumerator: bits-6

Implementá una función `bool es_potencia_de_dos(uint32_t n)` que determine en tiempo constante $O(1)$
si un número entero es una potencia de dos ($1, 2, 4, 8, 16, \dots$).
Aprovechá la propiedad binaria: todo número potencia de dos posee un único bit encendido,
por lo que `(n & (n - 1)) == 0` para todo `n > 0`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Aritmética de complemento, operaciones bitwise $O(1)$.  
**Techo conceptual:** Prohibido el uso de lazos o funciones trigonométricas/logarítmicas de `<math.h>`.

#### Contrato de la Función
- **Firma:** `bool es_potencia_de_dos(uint32_t n);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna `true` si existe $k \ge 0$ tal que $n = 2^k$; de lo contrario retorna `false`. El número `0` debe retornar `false`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `n` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `16` | `true` | $2^4 = 16$ |
| **Normal (No potencia)**| `18` | `false` | $18 = 16 + 2$ (dos bits encendidos) |
| **Borde (Uno)** | `1` | `true` | $2^0 = 1$ |
| **Borde (Cero)** | `0` | `false` | Cero no es potencia de dos |
| **Borde (Extremo)** | `0x80000000` | `true` | $2^{31}$ |

:::
<!-- {exercise} -->

::::{solution} es_potencia_de_dos
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

bool es_potencia_de_dos(uint32_t n)
{
    return (n > 0) && ((n & (n - 1U)) == 0);
}

int main(void)
{
    assert(es_potencia_de_dos(16U) == true);
    assert(es_potencia_de_dos(18U) == false);
    assert(es_potencia_de_dos(1U) == true);
    assert(es_potencia_de_dos(0U) == false);
    assert(es_potencia_de_dos(0x80000000U) == true);
    assert(es_potencia_de_dos(0x7FFFFFFFU) == false);
    return 0;
}
```

::::
<!-- {solution} es_potencia_de_dos -->

---

(ej_b4_c05_07)=
### Ejercicio 4.05.07 - Intercambio de Variables sin Memoria Auxiliar (XOR Swap) ⭐⭐☆☆☆

:::{exercise}
:label: xor_swap
:enumerator: bits-7

Implementá un procedimiento `void intercambiar_xor(uint32_t *a, uint32_t *b)` que intercambie
el contenido de dos posiciones de memoria utilizando exclusivamente la propiedad involutiva del operador XOR,
sin declarar variables temporales auxiliares.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Álgebra de Boole ($x \oplus x = 0$, $x \oplus 0 = x$), prevención de aliasing.  
**Techo conceptual:** Si `a == b` (mismo puntero), la función no debe poner la variable a cero.

#### Contrato de la Función
- **Firma:** `void intercambiar_xor(uint32_t *a, uint32_t *b);`
- **Precondiciones:** `a != NULL`, `b != NULL`.
- **Postcondiciones:** `*a` contendrá el valor previo de `*b`, y `*b` el valor previo de `*a`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`*a, *b`) | Estado Posterior (`*a, *b`) | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `a = 15, b = 99` | `a = 99, b = 15` | Intercambio de enteros distintos |
| **Borde (Aliasing)** | `p = &x (a == b)` | `*p` inalterado | Protección contra auto-anulación a cero |
| **Borde (Ceros)** | `a = 0, b = 0` | `a = 0, b = 0` | Intercambio de valores nulos |

:::
<!-- {exercise} -->

::::{solution} xor_swap
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

void intercambiar_xor(uint32_t *a, uint32_t *b)
{
    assert(a != NULL);
    assert(b != NULL);

    if (a != b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

int main(void)
{
    uint32_t x = 15U;
    uint32_t y = 99U;
    intercambiar_xor(&x, &y);
    assert(x == 99U && y == 15U);

    // Caso aliasing
    uint32_t mismo = 42U;
    intercambiar_xor(&mismo, &mismo);
    assert(mismo == 42U);

    return 0;
}
```

::::
<!-- {solution} xor_swap -->

---

(ej_b4_c05_08)=
### Ejercicio 4.05.08 - Sistema de Permisos de Archivo con Máscaras de Bits ⭐⭐⭐⭐☆

:::{exercise}
:label: permisos_archivo_bits
:enumerator: bits-8

Diseñá un sistema de permisos basado en un entero de 8 bits `uint8_t` utilizando las máscaras:
- `PERM_LECTURA = 1U << 0` (Bit 0)
- `PERM_ESCRITURA = 1U << 1` (Bit 1)
- `PERM_EJECUCION = 1U << 2` (Bit 2)

Implementá las siguientes operaciones puras:
- `uint8_t otorgar_permiso(uint8_t permisos, uint8_t mascara)`
- `uint8_t revocar_permiso(uint8_t permisos, uint8_t mascara)`
- `bool tiene_permiso(uint8_t permisos, uint8_t mascara)`

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Máscaras de bits fijas, combinación de flags con OR, revocación con AND-NOT.  
**Techo conceptual:** Prohibido el uso de arreglos o cadenas para representar permisos.

#### Contrato de la Función
- **Firma:** `uint8_t otorgar_permiso(uint8_t permisos, uint8_t mascara);`
- **Firma:** `uint8_t revocar_permiso(uint8_t permisos, uint8_t mascara);`
- **Firma:** `bool tiene_permiso(uint8_t permisos, uint8_t mascara);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** `tiene_permiso` retorna `true` si y solo si todos los bits de `mascara` están activos en `permisos`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Permisos Iniciales | Operación | Resultado Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `0` (ninguno) | Otorgar `LECTURA \| ESCRITURA` | `0b011` | Combinación de flags |
| **Normal** | `0b011` | Verificar `LECTURA` | `true` | Consulta afirmativa de flag |
| **Normal** | `0b011` | Verificar `EJECUCION` | `false` | Consulta negativa de flag |
| **Normal** | `0b011` | Revocar `ESCRITURA` | `0b001` | Desactivación selectiva |

:::
<!-- {exercise} -->

::::{solution} permisos_archivo_bits
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#define PERM_LECTURA   (1U << 0)
#define PERM_ESCRITURA (1U << 1)
#define PERM_EJECUCION (1U << 2)

uint8_t otorgar_permiso(uint8_t permisos, uint8_t mascara)
{
    return permisos | mascara;
}

uint8_t revocar_permiso(uint8_t permisos, uint8_t mascara)
{
    return permisos & ~mascara;
}

bool tiene_permiso(uint8_t permisos, uint8_t mascara)
{
    return (permisos & mascara) == mascara;
}

int main(void)
{
    uint8_t p = 0;

    p = otorgar_permiso(p, PERM_LECTURA | PERM_ESCRITURA);
    assert(tiene_permiso(p, PERM_LECTURA) == true);
    assert(tiene_permiso(p, PERM_ESCRITURA) == true);
    assert(tiene_permiso(p, PERM_EJECUCION) == false);

    p = revocar_permiso(p, PERM_ESCRITURA);
    assert(tiene_permiso(p, PERM_LECTURA) == true);
    assert(tiene_permiso(p, PERM_ESCRITURA) == false);

    return 0;
}
```

::::
<!-- {solution} permisos_archivo_bits -->
