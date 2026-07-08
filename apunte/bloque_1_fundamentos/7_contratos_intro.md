---
title: Introducción al Diseño por Contrato
short_title: 'Intro contratos'
subtitle: 'Documentación estructurada, precondiciones, postcondiciones e invariantes informales'
---

(capitulo-contratos-invariantes)=
## Introducción

El **Diseño por Contrato** (*Design by Contract*, DbC) es una metodología de
desarrollo de software formalizada por Bertrand Meyer. Propone que la
interacción entre diferentes partes de un sistema (por ejemplo, el código que
llama a una función y la función misma) se debe modelar como un **contrato
formal** entre clientes y proveedores.

Un contrato establece derechos y obligaciones mutuas. En el contexto de las
funciones, los componentes clave de este acuerdo son las **precondiciones**,
**postcondiciones** e **invariantes**.

---

## Desarrollo

(contratos-intro-capitulo)=
### Precondiciones y Postcondiciones Informales

#### Precondiciones (El Derecho del Proveedor, Obligación del Cliente)

Una **precondición** especifica las condiciones que deben ser obligatoriamente
verdaderas *antes* de que una función comience su ejecución.

*   **Obligación del Cliente:** El código que llama a la función es responsable
    de garantizar que los argumentos y el estado del sistema cumplan la
    precondición.
*   **Derecho del Proveedor:** El programador que implementa la función puede
    asumir libremente que la precondición se cumple. No tiene la obligación de
    verificarla ni de manejar situaciones donde no sea verdadera.
*   **Consecuencia de Violación:** Si la precondición se viola, el
    comportamiento del programa es **indefinido** (*undefined behavior*). El
    programa puede fallar catastróficamente, corromper memoria o retornar
    resultados absurdos.

``` c
// Precondición: 'b' no debe ser cero.
int dividir(int a, int b) {
    // Si b es cero, la división por cero provocará un fallo físico en el hardware.
    return a / b;
}
```
<!-- c -->

#### Postcondiciones (El Derecho del Cliente, Obligación del Proveedor)

Una **postcondición** describe las garantías lógicas que la función promete
cumplir *después* de terminar su ejecución, siempre y cuando la precondición
haya sido satisfecha al inicio.

*   **Obligación del Proveedor:** La función debe garantizar que el valor
    devuelto y las modificaciones de estado cumplan la postcondición.
*   **Derecho del Cliente:** El código llamador puede asumir con total certeza
    que el resultado es válido y proceder en consecuencia.

``` c
// Precondición: 'radicando' >= 0
// Postcondición: El valor retornado es 'r' tal que r * r <= radicando y (r+1)*(r+1) > radicando
int raiz_entera(int radicando) {
    // Implementación del algoritmo
}
```
<!-- c -->

### Verificación Dinámica de Contratos en C

En el lenguaje C, el contrato se documenta formalmente en la cabecera de la función de acuerdo con la regla {ref}`0x2003h` (que exige documentar precondiciones y postcondiciones de manera estructurada). Sin embargo, además de documentarse de forma textual, es una excelente práctica de diseño defensivo verificar dinámicamente las precondiciones usando la macro `assert()` de `<assert.h>`.

Por ejemplo, la función `raiz_entera` puede implementarse validando su precondición:

```c
#include <assert.h>

/**
 * @brief Calcula la raíz cuadrada entera de un número.
 * @pre radicando >= 0 (Regla 0x2003h)
 * @post retorna 'r' tal que r * r <= radicando y (r+1)*(r+1) > radicando
 */
int raiz_entera(int radicando) {
    // Verificación dinámica de la precondición
    assert(radicando >= 0);

    int r = 0;
    while ((r + 1) * (r + 1) <= radicando) {
        r++;
    }
    return r;
}
```

:::{note} Compilación y la macro NDEBUG
Las aserciones se utilizan exclusivamente durante la fase de desarrollo y depuración para atrapar errores lógicos del programador (el cliente que invoca mal la función). En producción, para evitar el impacto en la velocidad de ejecución provocado por estas validaciones continuas, se define la macro `NDEBUG` al compilar (ej: `gcc -DNDEBUG -O2 main.c`), lo cual remueve físicamente todas las líneas de `assert()` del ejecutable de forma automática.
:::

### Invariantes Elementales e Invariantes de Lazo

#### Invariantes de Lazo (Loop Invariants)

Un **invariante de lazo** es una condición lógica (una afirmación sobre las
variables del programa) que es verdadera:
1.  Antes de ingresar al lazo de control.
2.  Antes y después de cada iteración individual del lazo.
3.  Inmediatamente después de salir del lazo de control.

Los invariantes de lazo son la herramienta didáctica fundamental para razonar
lógicamente sobre la correctitud de los algoritmos iterativos. Nos permiten
verificar de forma inductiva que un lazo de control realmente cumple su objetivo
paso a paso.

```{code-block} c
:linenos:
// Precondición: arr != NULL y n >= 0
// Postcondición: retorna la suma de todos los elementos de arr[0] a arr[n-1]
int sumar_arreglo(const int arr[], int n) {
    int suma = 0;
    int i = 0;
    
    // Invariante: suma es la suma acumulada de arr[0] a arr[i-1] AND 0 <= i <= n
    while (i < n) {
        suma += arr[i];
        i++;
    }
    
    return suma;
}

```
<!-- {code-block} c -->

*   **Inicialización (Paso Base):** Antes de la primera iteración, $i = 0$, por
    lo que la suma acumulada de $arr[0]$ a $arr[-1]$ es vacía (valor $0$),
    cumpliéndose el invariante.
*   **Preservación (Paso Inductivo):** Si el invariante se cumple al inicio de
    la iteración $i$, sumar $arr[i]$ e incrementar $i$ a $i+1$ preserva la
    relación lógica de acumular la suma hasta la nueva posición del índice.
*   **Terminación:** Al salir del lazo, la condición $i < n$ es falsa. Como el
    invariante asegura que $i \leq n$, deducimos que $i = n$. Sustituyendo esto
    en el invariante, concluimos que `suma` almacena la suma de $arr[0]$ a
    $arr[n-1]$, lo cual satisface la postcondición de la función.

---

## Ejercicios de Autoevaluación

### Precondiciones y Postcondiciones

:::{exercise}
:label: ej-contrato-dbc-pre-sign
Definí la precondición matemática e informal de la función de división entera
`int dividir(int a, int b)` y explicá detalladamente qué establece el Diseño por
Contratos sobre el comportamiento del sistema si el cliente decide llamar a la
función violando dicha precondición.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-dbc-pre-sign
:class: dropdown
La precondición formal de la función es:
$$\text{Pre} \equiv (b \neq 0)$$

El Diseño por Contratos establece que si el cliente viola la precondición
(llamando a la función con $b = 0$), el proveedor queda completamente liberado
de sus obligaciones de cumplimiento de la postcondición. El comportamiento del
programa pasa a ser indefinido (*undefined behavior*), pudiendo crashearse,
retornar basura o corromper la memoria del sistema.

:::
<!-- {solution} ej-contrato-dbc-pre-sign -->

:::{exercise}
:label: ej-contrato-dbc-post-abs
Escribí la postcondición lógica y matemática para una función `int
valor_absoluto(int x)` que retorne el valor absoluto de $x$.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-dbc-post-abs
:class: dropdown
La postcondición formal asociando el valor de retorno $r$ de la función es:
$$\text{Post}(x, r) \equiv (x \geq 0 \rightarrow r = x) \land (x < 0 \rightarrow
r = -x)$$

:::
<!-- {solution} ej-contrato-dbc-post-abs -->

### Invariantes de Lazo

:::{exercise}
:label: ej-contrato-dbc-inv-lazo-lineal
Dada la siguiente implementación de búsqueda lineal en C, identificá el
invariante de lazo adecuado que permita razonar sobre la corrección del
algoritmo:

```{code-block} c
:linenos:
int buscar_elemento(const int arr[], int n, int elem) {
    int i = 0;
    while (i < n && arr[i] != elem) {
        i++;
    }
    return i < n ? i : -1;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-contrato-dbc-inv-lazo-lineal
:class: dropdown
El invariante de lazo formal para la búsqueda lineal es:
$$I \equiv (0 \leq i \leq n) \land \left(\forall j.\ 0 \leq j < i \rightarrow
\text{arr}[j] \neq \text{elem}\right)$$

Este invariante establece dos condiciones:
1.  El índice de control `i` se mantiene dentro del rango válido de control $[0,
    n]$.
2.  Para cualquier elemento recorrido previamente (índices menores a `i`), su
    valor es diferente al del elemento buscado `elem`.

Al terminar el lazo, si salimos porque `i == n`, el invariante nos garantiza de
forma inductiva que `elem` no se encuentra en ninguna posición del arreglo.

:::
<!-- {solution} ej-contrato-dbc-inv-lazo-lineal -->

---

## Glosario

:::{glossary}
Diseño por Contrato (DbC)
: Metodología de diseño de software que formaliza las interfaces entre
componentes mediante derechos y obligaciones mutuas (contratos lógicos).

:::

---

## Síntesis y Resumen

En esta unidad te introdujiste en el formalismo del Diseño por Contrato y su
aplicación en la verificación de algoritmos:
- **Relación cliente-proveedor**: Documentar precondiciones y poscondiciones
  divide las responsabilidades del control de errores entre el código llamador
  (cliente) y la función llamada (proveedor).
- **Razonamiento inductivo**: El invariante de lazo es la herramienta lógica
  clave para demostrar de forma rigurosa la correctitud de los algoritmos
  iterativos. Funciona de manera análoga a la inducción matemática
  (inicialización, preservación y terminación).

---

## Referencias y Lecturas Complementarias

- Meyer, B. (1997). *Object-Oriented Software Construction* (2nd ed.). Prentice
  Hall. (Capítulo 11: Design by Contract).
- Meyer, B. (1992). *Applying "Design by Contract"*. Computer, 25(10), 40-51.
- Gries, D. (1981). *The Science of Programming*. Springer-Verlag. (Sobre
  correctitud de programas e invariantes).
