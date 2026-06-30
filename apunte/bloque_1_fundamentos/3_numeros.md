---
title: Representación de Números y Aritmética
short_title: '2a - Números'
subtitle: 'Tipos de datos numéricos en C, límites físicos, desbordamientos e imprecisión de reales'
---

(capitulo-aritmetica-numeros)=

## Introducción

En el lenguaje C, a diferencia de la matemática pura donde los conjuntos numéricos son infinitos, los números se representan físicamente utilizando una cantidad finita de bits en la memoria RAM del sistema. Esto significa que cada tipo de dato numérico posee un rango de representación estrictamente limitado por el hardware del procesador.

El estándar C clasifica los tipos numéricos en dos grandes familias: **enteros** (con y sin signo) y **números reales** (o de punto flotante).

---

## Desarrollo

(numeros-capitulo)=

### Números Enteros y Portabilidad

El estándar C define varios tipos enteros básicos: `char` (usualmente 8 bits), `short` (mínimo 16 bits), `int` (mínimo 16 bits, usualmente 32 bits en plataformas modernas) y `long` (mínimo 32 bits).

:::{warning} Tamaños Dependientes de la Arquitectura
El estándar de C **no** define un tamaño fijo en bytes para los tipos básicos, sino relaciones de tamaño mínimo. 
* En una computadora de escritorio (arquitectura de 64 bits), un `int` suele ocupar 4 bytes (32 bits).
* En microcontroladores embebidos o sistemas antiguos, un `int` puede ocupar únicamente 2 bytes (16 bits), reduciendo su rango de representación de $[-2.147.483.648, 2.147.483.647]$ a $[-32.768, 32.767]$.
:::

#### Tipos de Ancho Fijo (`<stdint.h>`)

Para solucionar este problema de portabilidad y evitar comportamientos erráticos al compilar en diferentes procesadores, el estándar C99 introdujo la biblioteca `<stdint.h>`. Esta define tipos de datos con tamaños fijos y explícitos:

:::{table} Tipos de datos de ancho fijo de stdint.h
:label: tbl-stdint-types

| Tipo con Signo | Tipo sin Signo | Tamaño en Bits | Rango Aproximado |
| :--- | :--- | :---: | :--- |
| `int8_t` | `uint8_t` | 8 bits | $\pm 127$ / $0$ a $255$ |
| `int16_t` | `uint16_t` | 16 bits | $\pm 32.767$ / $0$ a $65.535$ |
| `int32_t` | `uint32_t` | 32 bits | $\pm 2.147.483.647$ / $0$ a $4.294.967.295$ |
| `int64_t` | `uint64_t` | 64 bits | $\pm 9 \times 10^{18}$ |
:::

Como regla general de la cátedra (ver regla {ref}`0x3010h`), debés utilizar siempre `size_t` para almacenar tamaños de memoria, índices de arreglos o conteos de elementos, ya que es el tipo sin signo garantizado por el sistema para representar el tamaño de cualquier objeto en memoria.

### Desbordamientos (Overflow y Underflow)

El desbordamiento ocurre cuando el resultado de una operación aritmética produce un valor numérico que supera los límites físicos que el tipo de dato asignado puede representar.

#### Enteros Sin Signo (`unsigned`): Comportamiento Cíclico

El estándar C especifica de forma estricta que los enteros sin signo operan bajo **aritmética modular** (módulo $2^w$, donde $w$ es el ancho en bits). Si se supera el límite superior, el valor "da la vuelta" y comienza cíclicamente desde cero de manera predecible.

```c
#include <stdio.h>
#include <stdint.h>

void demo_overflow_unsigned(void) {
    uint8_t numero = 255;  // Valor máximo almacenable en 8 bits
    numero = numero + 1;   // Produce 0 de forma garantizada por el estándar C
    printf("Valor: %u\n", numero);
}
```

#### Enteros Con Signo: Comportamiento Indefinido (UB)

A diferencia de los tipos sin signo, el desbordamiento de un entero con signo (ej: `int` o `int32_t`) constituye un **Comportamiento Indefinido** (*Undefined Behavior* o *UB*) según el estándar ISO de C.

:::{important} ¿Qué implica el Comportamiento Indefinido?
Cuando ocurre un comportamiento indefinido, el estándar de C no garantiza absolutamente nada. El compilador es libre de asumir que el desbordamiento **nunca** va a ocurrir y optimizar el código binario eliminando condicionales críticos de validación, lo cual puede provocar fallas lógicas silenciosas o vulnerabilidades graves de seguridad en ejecución.
:::

```c
#include <stdint.h>

void demo_overflow_signed(void) {
    int8_t numero = 127;  // Valor máximo en 8 bits con signo
    numero = numero + 1;  // ¡COMPORTAMIENTO INDEFINIDO! No asumas que dará -128.
}
```

### División de Enteros vs. División Real

En C, los operadores aritméticos cambian su semántica según el tipo de datos de sus operandos. Esto es especialmente crítico en la división (`/`):

*   **División de Enteros:** Si ambos operandos son enteros, C realiza una división entera truncada hacia cero, descartando por completo la parte fraccionaria sin realizar redondeos.
*   **División Real:** Si al menos uno de los operandos es un tipo flotante (`float` o `double`), C realiza una división real conservando los decimales.

```c
int a = 5;
int b = 2;

int resultado_entero = a / b;     // Produce 2 (se descarta la parte fraccional)
float resultado_real = (float)a / b; // Produce 2.5 (conversión explícita o cast)
```

Para mayor detalle de cómo el compilador convierte implícitamente estos tipos durante operaciones aritméticas, consultá el capítulo de {ref}`casts-capitulo`.

### Imprecisión de Reales (IEEE 754)

Los procesadores modernos representan los números reales en binario siguiendo el estándar **IEEE 754**. Dado que no es posible representar un número infinito de valores reales utilizando una cantidad finita de bits (como los 32 bits de un `float`), la gran mayoría de los números fraccionarios experimentan un redondeo o truncamiento físico en memoria.

#### Demostración de la Periodicidad Binaria de $0.1$

El número decimal $0.1_{10}$ parece simple, pero en base binaria es un número periódico infinito. Para convertir la parte fraccionaria, multiplicamos sucesivamente por 2 y tomamos la parte entera resultante como el bit correspondiente:

1. $0.1 \times 2 = 0.2 \rightarrow \text{bit } 0$ (resto $0.2$)
2. $0.2 \times 2 = 0.4 \rightarrow \text{bit } 0$ (resto $0.4$)
3. $0.4 \times 2 = 0.8 \rightarrow \text{bit } 0$ (resto $0.8$)
4. $0.8 \times 2 = 1.6 \rightarrow \text{bit } 1$ (resto $0.6$)
5. $0.6 \times 2 = 1.2 \rightarrow \text{bit } 1$ (resto $0.2$)
6. $0.2 \times 2 = 0.4 \rightarrow \text{bit } 0$ (se repite la secuencia de restos...)

Como el resto vuelve a ser $0.2$ en el paso 6, el patrón se repite infinitamente:
$$0.1_{10} = 0.000110011001100110011\dots_2 = 0.0\overline{0011}_2$$

Dado que un `float` reserva únicamente 23 bits para la mantisa, esta secuencia se corta físicamente en memoria, almacenando la aproximación:
$$0.100000001490116119384765625$$

#### Comparación Segura mediante Épsilon

Due a esta imprecisión acumulada, nunca debés comparar dos números reales utilizando el operador de igualdad directa `==`. En su lugar, debés verificar que la diferencia absoluta entre ambos sea menor que un margen de tolerancia sumamente pequeño denominado **épsilon** ($\epsilon$):

```c
#include <math.h>
#include <stdbool.h>

#define EPSILON 0.00001f

bool reales_casi_iguales(float a, float b) {
    // Retorna verdadero si la diferencia absoluta es menor al margen de error
    return fabsf(a - b) < EPSILON;
}
```

---

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-num-overflow-unsigned
Dada la variable `uint16_t x = 65535;`, ¿qué valor lógico se almacenará en la variable tras ejecutar la instrucción `x = x + 2;` en C? Justificá tu respuesta en base al estándar.
:::

:::{solution} ej-num-overflow-unsigned
:class: dropdown
El tipo `uint16_t` es un entero sin signo de 16 bits, lo que limita su valor máximo almacenable a $2^{16} - 1 = 65535$. 

El estándar C garantiza que las operaciones aritméticas sobre tipos enteros sin signo operan bajo aritmética modular. Al sumar 2, el valor realiza un desbordamiento cíclico ("da la vuelta"):
$$\text{x} = (65535 + 2) \bmod 65536 = 1$$

Por lo tanto, la variable `x` almacenará el valor `1` de manera completamente segura y predecible.
:::

:::{exercise}
:label: ej-num-division-truncation
Explicá de forma detallada qué valor imprimirá por pantalla el siguiente fragmento de código en C y de qué forma se puede solucionar su comportamiento erróneo:

```c
int total_puntos = 15;
int partidas = 4;
float promedio = total_puntos / partidas;
printf("Promedio: %.2f\n", promedio);
```
:::

:::{solution} ej-num-division-truncation
:class: dropdown
El fragmento de código imprimirá `Promedio: 3.00`.

Esto ocurre porque `total_puntos` y `partidas` son variables de tipo `int`. Al aplicar el operador `/`, C realiza primero una **división entera**, truncando el resultado real de $3.75$ a $3$. Luego, este valor entero `3` se convierte implícitamente a flotante (`3.0f`) durante la asignación a la variable `promedio`.

Para solucionar esto y conservar la precisión decimal, se debe realizar una conversión explícita o cast (ver regla de casts) de al menos uno de los operandos a `float` antes de operar:
```c
float promedio = (float)total_puntos / partidas; // Produce 3.75f
```
:::

:::{exercise}
:label: ej-num-epsilon-compare
¿Por qué la expresión condicional `(0.1f + 0.2f == 0.3f)` evalúa como falsa en un sistema informático real? Escribí la estructura lógica condicional en C que permita realizar dicha comparación de forma robusta y segura.
:::

:::{solution} ej-num-epsilon-compare
:class: dropdown
La comparación evalúa como falsa debido a la imprecisión en la representación binaria bajo el estándar IEEE 754. Ni $0.1$ ni $0.2$ tienen representaciones binarias exactas finitas, lo que introduce un pequeño error de redondeo en la mantisa. Al sumarse, los errores se acumulan haciendo que el valor almacenado difiera ligeramente de $0.3f$.

La forma correcta de realizar esta comparación es evaluando la diferencia absoluta contra un épsilon:
```c
#include <math.h>
#include <stdio.h>

#define EPSILON 0.00001f

void comparar(float a, float b) {
    if (fabsf(a - b) < EPSILON) {
        printf("Son equivalentes dentro del margen de error.\n");
    }
}
```
:::

---

## Glosario

::{glossary}
IEEE 754
: Estándar técnico para la representación por hardware de números de punto flotante.

Épsilon (epsilon)
: El menor margen de tolerancia o valor de error aceptado en la comparación de números reales debido a imprecisiones de almacenamiento.

Desbordamiento (Overflow)
: Fenómeno en el cual un cálculo matemático excede los límites superiores representables por el tipo de dato físico.

Comportamiento Indefinido (Undefined Behavior)
: Situación descrita en el estándar de un lenguaje de programación donde no se especifica ninguna restricción sobre lo que el compilador y el entorno pueden hacer.
:::

---

## Síntesis y Resumen

En este capítulo estudiaste cómo se representan numéricamente los datos en hardware y sus consecuencias:
- **Límites de hardware**: La RAM y los registros usan tamaños de bit fijos, lo que limita los rangos de representación a diferencia de las matemáticas abstractas.
- **Portabilidad**: El uso de `<stdint.h>` asegura anchos fijos frente a variaciones de arquitectura.
- **Manejo de Desbordamiento**: Los enteros sin signo tienen comportamiento modular predecible, mientras que con signo caen en comportamiento indefinido.
- **Imprecisión real**: La base periódica binaria para números decimales exige comparaciones robustas basadas en épsilon en lugar de comparaciones lógicas directas.

---

## Referencias y Lecturas Complementarias

- Goldberg, D. (1991). *What every computer scientist should know about floating-point arithmetic*. ACM Computing Surveys (CSUR), 23(1), 5-48.
- ISO/IEC stdint.h Specification.
- IEEE Standard for Floating-Point Arithmetic (IEEE 754).
