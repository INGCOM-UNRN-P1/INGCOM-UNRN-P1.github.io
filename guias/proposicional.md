---
title: Lógica Proposicional para Programación
short_title: Lógica Proposicional
subtitle: Conceptos lógicos fundamentales aplicados a contratos, aserciones y verificación de código
---

# Lógica Proposicional para Programación

La lógica proposicional es la herramienta formal que permite razonar sobre la
veracidad o falsedad de afirmaciones dentro del software. En programación, su
aplicación es directa: desde la escritura de estructuras condicionales simples
hasta la especificación y verificación formal de programas mediante
**contratos** (precondiciones, postcondiciones e invariantes).

Esta guía introduce los conectivos lógicos, las equivalencias fundamentales y su
correlato con las aserciones en el código.

---

## 1. Proposiciones y conectivos lógicos

Una **proposición** es una afirmación declarativa que puede ser únicamente
**verdadera (V)** o **falsa (F)**. En código, una proposición se representa
típicamente mediante expresiones booleanas o variables de tipo `bool` (en C,
`#include <stdbool.h>`).

### Conectivos lógicos fundamentales

Los conectivos lógicos permiten combinar proposiciones atómicas para formar
proposiciones compuestas. A continuación se presentan los conectivos
principales, su notación lógica y su traducción al lenguaje C:

| Conectivo | Símbolo lógico | Operador en C | Definición informal |
| :--- | :---: | :---: | :--- |
| **Negación** | $\neg P$ | `!P` | Es verdadera si y solo si $P$ es falsa. |
| **Conjunción** | $P \land Q$ | `P && Q` | Es verdadera si y solo si tanto $P$ como $Q$ son verdaderas. |
| **Disyunción** | $P \lor Q$ | `P \|\| Q` | Es verdadera si al menos una de las dos proposiciones es verdadera. |
| **Condicional (Implicación)** | $P \implies Q$ | *(No nativo)* | Representa "Si ocurre $P$, entonces se cumple $Q$". |
| **Bicondicional (Equivalencia)** | $P \iff Q$ | `P == Q` | Es verdadera si ambas tienen el mismo valor de verdad. |

---

## 2. La Implicación Lógica ($P \implies Q$) y su rol en Contratos

El condicional o implicación, denotado por $P \implies Q$, es el bloque
constructivo de las **precondiciones** y **postcondiciones** en el diseño por
contrato.

### Tabla de verdad de la implicación

La implicación $P \implies Q$ solo es falsa cuando el antecedente ($P$) es
verdadero y el consecuente ($Q$) es falso. En cualquier otro caso, la
implicación es verdadera:

| $P$ | $Q$ | $P \implies Q$ | Comentario pedagógico |
| :---: | :---: | :---: | :--- |
| **V** | **V** | **V** | El antecedente se cumple y la promesa se respeta. |
| **V** | **F** | **F** | El antecedente se cumple pero la promesa falla (violación del contrato). |
| **F** | **V** | **V** | El antecedente no se cumple; no hay obligación (cumplimiento por vacuidad). |
| **F** | **F** | **V** | El antecedente no se cumple; no hay obligación (cumplimiento por vacuidad). |

### Equivalencia lógica fundamental: Implicación Material

Dado que en C/C++ y Java no existe un operador nativo para la implicación
lógica, debés traducirla utilizando conectivos elementales. La ley de
**implicación material** establece la siguiente equivalencia:

$$P \implies Q \equiv \neg P \lor Q$$

En código, esta equivalencia se traduce de la siguiente manera:

``` c
// Para verificar formalmente que P implica Q:
assert(!P || Q);
```
<!-- c -->

:::{important}

Si la precondición $P$ es falsa, la expresión `!P || Q` evalúa a `true`
inmediatamente debido a la evaluación por cortocircuito. Esto es lógicamente
correcto: si el llamador de una función no cumple con la precondición, la
función no está obligada a garantizar la postcondición $Q$.

:::
<!-- {important} -->

---

## 3. Leyes lógicas esenciales y simplificación de código

El uso de equivalencias lógicas permite reescribir condiciones complejas en el
código de forma más legible y eficiente, reduciendo la carga cognitiva.

### Leyes de De Morgan

Estas leyes describen cómo distribuir la negación sobre una conjunción o una
disyunción:

1.  **Negación de una conjunción:**
    $$\neg(P \land Q) \equiv \neg P \lor \neg Q$$
    En C: `!(P && Q)` es lógicamente equivalente a `!P || !Q`.

2.  **Negación de una disyunción:**
    $$\neg(P \lor Q) \equiv \neg P \land \neg Q$$
    En C: `!(P || Q)` es lógicamente equivalente a `!P && !Q`.

#### Ejemplo de refactorización de código

Considerá el siguiente bloque condicional que valida si un puntero no es nulo y
el valor de su nodo es válido:

``` c
// Condición compleja y redundante
if (!(ptr != NULL && ptr->valor > 0)) {
    // Manejo de error
}
```
<!-- c -->

Aplicando la primera Ley de De Morgan, podés reescribir la condición eliminando
la negación externa:

$$\neg(\text{ptr} \neq \text{NULL} \land \text{ptr->valor} > 0) \equiv \neg(\text{ptr} \neq \text{NULL}) \lor \neg(\text{ptr->valor} > 0)$$

Lo cual equivale a:

$$\text{ptr} == \text{NULL} \lor \text{ptr->valor} \le 0$$

Refactorizando el código:

``` c
if (ptr == NULL || ptr->valor <= 0) {
    // Manejo de error
}
```
<!-- c -->

:::{tip}

La versión refactorizada no solo es más legible, sino que además aprovecha la
evaluación por cortocircuito de C: si `ptr` es `NULL`, la ejecución no evalúa
`ptr->valor <= 0`, evitando una desreferenciación nula.

:::
<!-- {tip} -->

---

## 4. Ejercicios

Poné a prueba tu comprensión de la lógica proposicional aplicada al código con
los siguientes ejercicios.

:::{exercise}
:label: ej-implicacion-c
Traducí la siguiente afirmación formal en una instrucción `assert` de C:

> "Si el arreglo no es nulo y su longitud es mayor a cero, entonces el puntero
  al primer elemento debe ser no nulo".

Definí las variables booleanas asociadas:

- $P$: `arreglo != NULL`
- $Q$: `largo > 0`
- $R$: `arreglo->datos != NULL`

:::
<!-- {exercise} -->

:::{solution} ej-implicacion-c
:class: dropdown

La estructura formal de la afirmación es $(P \land Q) \implies R$.
Aplicando la equivalencia de implicación material:
$$(P \land Q) \implies R \equiv \neg(P \land Q) \lor R$$
Y aplicando De Morgan a la negación izquierda:
$$\neg P \lor \neg Q \lor R$$

En código C, la aserción correspondiente es:
``` c
assert(arreglo == NULL || largo <= 0 || arreglo->datos != NULL);
```
<!-- c -->
O de forma equivalente usando el paso de implicación material directo sobre la
conjunción:
``` c
assert(!(arreglo != NULL && largo > 0) || arreglo->datos != NULL);
```
<!-- c -->

:::
<!-- {solution} ej-implicacion-c -->

:::{exercise}
:label: ej-demorgan-lazo
Durante la ejecución de un lazo de búsqueda, la condición de permanencia es:

``` c
while (i < tamano && arreglo[i] != objetivo)
```
<!-- c -->

¿Cuál es la proposición lógica que describe la condición de salida del lazo? 
Expresá el resultado aplicando las Leyes de De Morgan.

:::
<!-- {exercise} -->

:::{solution} ej-demorgan-lazo
:class: dropdown

La condición de permanencia del lazo tiene la forma $P \land Q$, donde:
- $P$: `i < tamano`
- $Q$: `arreglo[i] != objetivo`

El lazo finaliza cuando la condición de permanencia se vuelve falsa, es decir,
cuando ocurre $\neg(P \land Q)$.
Aplicando la primera Ley de De Morgan:
$$\neg(P \land Q) \equiv \neg P \lor \neg Q$$
Traduciendo al lenguaje natural y a expresiones condicionales de C:
- $\neg P$: `i >= tamano` (se llegó al final del arreglo).
- $\neg Q$: `arreglo[i] == objetivo` (se encontró el elemento buscado).

Por lo tanto, la condición de salida es:
`i >= tamano || arreglo[i] == objetivo`
Esto demuestra que al salir del lazo, o bien se agotaron los elementos, o bien
se encontró el objetivo.

:::
<!-- {solution} ej-demorgan-lazo -->

:::{exercise}
:label: ej-invariante-pila
En una estructura de tipo Pila de capacidad fija $N$, el número de elementos
guardados se almacena en la variable `tope`.
Queremos establecer la invariante de la estructura. Definí la proposición lógica
de la invariante sabiendo que:
- La cantidad de elementos no puede ser negativa.
- La cantidad de elementos no puede superar la capacidad $N$.

:::
<!-- {exercise} -->

:::{solution} ej-invariante-pila
:class: dropdown

La invariante debe cumplirse antes y después de cualquier operación pública de
la pila.
Definimos las proposiciones:
- $P$: `tope >= 0`
- $Q$: `tope <= N`

La invariante del TDA es la conjunción de ambas condiciones:
$$P \land Q \equiv 0 \le \text{tope} \le N$$
En C, la aserción de verificación del estado interno de la pila se escribe:
``` c
assert(pila->tope >= 0 && pila->tope <= pila->capacidad);
```
<!-- c -->

:::
<!-- {solution} ej-invariante-pila -->
