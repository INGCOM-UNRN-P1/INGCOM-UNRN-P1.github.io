---
title: Conversión de Tipos (Casts) en C
short_title: 'Conversiones'
subtitle: 'Promoción, coerción implícita y conversión explícita de tipos de datos'
---

(capitulo-conversiones-casts)=
## Introducción

En C, las variables poseen un tipo estático y rígido asignado en su declaración.
Sin embargo, en la práctica es extremadamente común necesitar operar con
variables de distintos tipos en una misma expresión (por ejemplo, sumar un
entero de tipo `int` con un valor de punto flotante de tipo `double`).

Para resolver estas situaciones, el compilador aplica reglas automáticas de
conversión, o bien nos permite forzar la conversión de manera explícita.
Comprender cómo funciona físicamente la conversión de tipos en el hardware es
fundamental para evitar pérdidas de precisión silenciosas, desbordamientos
(*overflows*) o comportamientos indefinidos.

---

## Desarrollo

(conversiones-capitulo)=
### Conversiones Implícitas (Promoción y Coerción)

Las conversiones implícitas son aquellas que el compilador de C realiza de forma
automática, sin intervención explícita del programador, al evaluar expresiones
mixtas o al realizar asignaciones.

#### Promoción Entera (Integer Promotion)

Antes de realizar cualquier operación aritmética, C promueve automáticamente los
tipos enteros de menor rango (como `char`, `short` o tipos enumerados) a `int`
(o a `unsigned int` si el rango original no cabe en un entero signado). Esto se
realiza porque las unidades aritmético-lógicas (ALU) de la CPU operan de forma
más eficiente con el tamaño nativo de palabra del procesador.

``` c
char a = 10;
char b = 20;
// 'a' y 'b' se promueven internamente a 'int' antes de realizar la suma
int c = a + b;
```
<!-- c -->

#### Conversiones Aritméticas Habituales

Cuando operandos de tipos diferentes interactúan en una expresión aritmética
(como `+`, `-`, `*`, `/`), el compilador promueve el operando de "menor rango"
al tipo del operando de "mayor rango". El orden general de jerarquía de tipos
(de menor a mayor) es:

$$\text{int} < \text{unsigned int} < \text{long} < \text{unsigned long} <
\text{float} < \text{double} < \text{long double}$$

Si operás un `int` con un `double`, el `int` se convertirá automáticamente a
`double` antes de computar el resultado en punto flotante.

``` c
int base = 5;
double factor = 1.5;
// 'base' se promueve a double (5.0) y la operación retorna un double (7.5)
double resultado = base * factor;
```
<!-- c -->

#### Coerción y Truncamiento ("Democión" de Tipos)

El peligro real de las conversiones implícitas ocurre al asignar un tipo de
mayor rango a uno de menor rango. En este caso, el compilador realiza una
coerción hacia abajo (democión), lo que puede provocar:

1.  **Pérdida de Precisión:** Al asignar un `float` o `double` a un `int`, la
    parte decimal se descarta por completo (se trunca hacia cero, no se
    redondea).
2.  **Desbordamiento (Overflow):** Si el valor del tipo mayor excede la
    capacidad del tipo menor, el comportamiento depende de si el tipo de destino
    es signado o no. En tipos no signados (`unsigned`), el valor se reduce
    módulo el tamaño del tipo. En tipos signados, el resultado es
    **comportamiento indefinido** (*undefined behavior*), aunque físicamente
    suele ocurrir un truncamiento de bits que altera el signo del número.

``` c
double pi = 3.14159;
int pi_entero = pi; // pi_entero tomará el valor 3 (truncamiento implícito)
int grande = 300;
char chico =
    grande; // Truncamiento de bits: 300 (0x012C) se reduce a 0x2C (44)
```
<!-- c -->

### Conversiones Explícitas (El Operador Cast)

Un **cast** (o conversión explícita) es una instrucción directa del programador
al compilador para forzar la conversión de una expresión a un tipo de dato
específico.

#### Sintaxis

La sintaxis del operador cast antepone el tipo de destino entre paréntesis a la
expresión a convertir:

``` c
(tipo_destino) expresion
```
<!-- c -->

El operador cast tiene una precedencia muy alta (operador unario), por lo que se
evalúa antes que la mayoría de los operadores aritméticos a menos que utilices
paréntesis agrupadores.

#### Casos de Uso Comunes

El cast explícito se utiliza principalmente en tres escenarios didácticos y de
ingeniería:

##### 1. Evitar la División Entera
En C, si dividís dos enteros, el resultado es una división entera que descarta
los decimales. Si necesitás la precisión decimal, debés castear al menos uno de
los operandos a un tipo de punto flotante para forzar la promoción del otro
operando.

``` c
int leidos = 3;
int total = 4;
// Sin cast, leidos / total retornaría 0 (división entera)
double porcentaje = (double)leidos / total; // Retorna 0.75
```
<!-- c -->

##### 2. Documentar la Pérdida Intencional de Precisión
Castear explícitamente al asignar un tipo grande a uno chico le comunica al
compilador (y a futuros desarrolladores) que el truncamiento de datos es
intencional, evitando que el compilador emita advertencias (*warnings*).

``` c
double medicion = 99.987;
int parte_entera =
    (int)medicion; // Claridad de diseño: descarta decimales voluntariamente
```
<!-- c -->

##### 3. Trabajar con Interfaces Genéricas
Aunque se abordará en profundidad en capítulos avanzados, el cast explícito es
fundamental al manipular punteros genéricos (`void*`) para reinterpretar la
dirección física de la memoria.

### Conversiones y Representación en Memoria

Las conversiones de tipos no son meramente lógicas; tienen un impacto físico
directo en cómo la CPU manipula los bits de las variables en la memoria RAM.

#### Cast Aritmético vs. Cast de Reinterpretación

Es fundamental diferenciar conceptualmente entre dos tipos de transformaciones:

*   **Conversión de Valor (Cast Aritmético):** Modifica la representación física
    de los bits para preservar el valor matemático del dato original en el tipo
    de destino. Por ejemplo, al convertir `int a = 5` a `float`, el procesador
    traduce la codificación entera tradicional (complemento a 2) a la
    representación de punto flotante de precisión simple estándar IEEE 754. Los
    patrones de bits de `5` y `5.0f` son completamente distintos en memoria,
    pero representan el mismo valor numérico.
*   **Reinterpretación de Bits (Cast de Punteros):** No altera los bits de la
    memoria, sino que le indica al compilador que lea la misma dirección de
    memoria física bajo las reglas de otro tipo de dato. Esto se realiza
    únicamente a través del casteo de punteros (lo que se analizará en detalle
    en el capítulo de Aritmética de Punteros).

#### Conversión entre Signed y Unsigned (Complemento a 2)

Al castear entre enteros signados y no signados del mismo tamaño (por ejemplo,
de `int` a `unsigned int`), los bits en memoria **no se modifican en absoluto**.
La CPU simplemente reinterpreta el bit más significativo (el bit de signo en
complemento a 2) como parte del valor numérico absoluto.

``` c
int negativo = -1; // En memoria (32 bits): 0xFFFFFFFF
unsigned int positivo =
    (unsigned int)negativo; // Reinterpretado como 4294967295 (0xFFFFFFFF)
```
<!-- c -->

Este tipo de conversiones implícitas o explícitas mal controladas son el origen
de graves problemas de seguridad y lazos infinitos cuando se comparan índices de
tamaño en expresiones mixtas.

---

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-conversion-implicita-aritmetica
Analizá el siguiente fragmento de código y deducí el valor final almacenado en
la variable `resultado` y su tipo lógico de representación:

``` c
int a = 5;
double b = 2.0;
int resultado = a / b;
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-conversion-implicita-aritmetica
:class: dropdown
El proceso de evaluación ocurre en dos pasos físicos:
1.  **Operación aritmética mixta:** Al evaluar `a / b`, el operando `a` (tipo
    `int`, valor `5`) se promueve implícitamente a `double` (`5.0`) por la regla
    de conversión aritmética habitual, ya que `double` tiene mayor jerarquía. La
    división `5.0 / 2.0` se computa en punto flotante y retorna un valor de tipo
    `double` equivalente a `2.5`.
2.  **Asignación de tipos:** El valor resultante (`2.5` de tipo `double`) se
    asigna a la variable `resultado` de tipo `int`. Dado que se asigna un tipo
    de mayor jerarquía a uno menor, ocurre una coerción implícita hacia abajo
    que trunca la parte fraccionaria.

Por lo tanto, la variable `resultado` almacena el valor entero `2`.

:::
<!-- {solution} ej-conversion-implicita-aritmetica -->

:::{exercise}
:label: ej-cast-division-entera
Identificá el error de diseño en el siguiente fragmento de código y explicalo
desde la perspectiva de la precedencia de operadores y la conversión de tipos:

``` c
int total_horas = 5;
int dias = 2;
double promedio = (double)(total_horas / dias);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-cast-division-entera
:class: dropdown
El error reside en la colocación de los paréntesis de agrupación, lo que anula
el efecto del cast:
1.  Debido a los paréntesis `(total_horas / dias)`, la división se evalúa
    primero. Como `total_horas` y `dias` son de tipo `int`, se realiza una
    división entera: `5 / 2` que resulta en `2`.
2.  Posteriormente, se aplica el cast explícito `(double)` sobre el resultado de
    la división entera. El valor entero `2` se convierte a `2.0` de tipo
    `double`.
3.  El promedio almacenado es `2.0` en lugar del valor preciso de `2.5`.

**Solución Correcta:** Aplicar el cast sobre uno de los operandos individuales
antes de la división, permitiendo que la promoción aritmética haga el resto:
``` c
double promedio =
    (double)total_horas / dias; // (double)5.0 / 2 -> 5.0 / 2.0 -> 2.5
```
<!-- c -->

:::
<!-- {solution} ej-cast-division-entera -->

:::{exercise}
:label: ej-cast-signo-comparacion
Explicá por qué el siguiente programa imprime "Indefinido o Inesperado" en lugar
de "Correcto", analizando las reglas de conversión implícita:

```{code-block} c
:linenos:
#include <stdio.h>
int main(void)
{
    int limite = -5;
    unsigned int cantidad = 10;
    if (limite < cantidad)
    {
        printf("Correcto\n");
    }
    else
    {
        printf("Indefinido o Inesperado\n");
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-cast-signo-comparacion
:class: dropdown
El comportamiento inesperado ocurre debido a las **Conversiones Aritméticas
Habituales** de C:
1.  En la comparación `limite < cantidad`, el compilador detecta un operando
    signado (`int limite`) y un operando no signado (`unsigned int cantidad`).
2.  De acuerdo con las reglas de C, el operando signado se promueve
    implícitamente a tipo no signado (`unsigned int`) si ambos tienen el mismo
    tamaño físico.
3.  El valor `-5` (cuya representación de bits en complemento a 2 es
    `0xFFFFFFFB`) se reinterpreta directamente como un entero sin signo
    extremadamente grande: `4294967291`.
4.  La comparación física evaluada es `4294967291 < 10`, la cual resulta falsa.

**Lección de Ingeniería:** Nunca debés realizar comparaciones aritméticas mixtas
entre tipos signados y no signados sin castear previamente de forma explícita y
segura a un tipo común que pueda contener a ambos.

:::
<!-- {solution} ej-cast-signo-comparacion -->

---

## Glosario

:::{glossary}

Cast (Casteo)
: Operación explícita para forzar al compilador a convertir una expresión a un
tipo de dato específico.

Coerción (Coercion)
: Conversión automática o implícita de tipos realizada por el compilador para
compatibilizar operandos en una expresión o asignación.

Promoción Entera
: Regla de C que convierte automáticamente tipos enteros pequeños a `int` o
`unsigned int` antes de evaluarlos.

Democión de Tipos (Truncamiento)
: Conversión de un tipo de mayor jerarquía o rango de representación a uno
menor, usualmente acompañada de pérdida de datos o precisión.

:::
<!-- {glossary} -->

---

## Síntesis y Resumen

En esta unidad cubriste las conversiones de datos en C:
- **Implícitas**: El compilador realiza promociones enteras o conversiones
  aritméticas automáticas ordenadas por jerarquía física de datos.
- **Explícitas**: Mediante el operador cast, forzás la transformación de
  expresiones evitando truncamientos indeseados en divisiones.
- **Consecuencias físicas**: Las conversiones pueden requerir reordenar bits en
  la CPU (ej: entero a real) o simplemente reinterpretar los mismos bits sin
  cambio físico (ej: signed a unsigned), lo que puede causar fallas de lógica si
  no se controlan debidamente.

---

## Referencias y Lecturas Complementarias

- ISO/IEC 9899 Language Standard Section 6.3: Conversions.
- Seacord, R. C. (2013). *Secure Coding in C and C++*. Addison-Wesley
  Professional. Chapter 5: Integer Security.
