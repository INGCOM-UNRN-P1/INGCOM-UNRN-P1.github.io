---
title: Diseño por Contratos Formal y Verificación
short_title: 'Contratos Formales'
subtitle: 'Lógica de primer orden, tripletas de Hoare, invariantes de TADs y cálculo de wp en C'
---

(capitulo-contratos-formales)=
# 3. Contratos de Estructuras de Datos e Invariantes de Clase

## Introducción

(contratos-formales-capitulo)=

## Desarrollo

### Fundamentos Matemáticos del Diseño por Contratos


Para sistemas de software de alta integridad o complejidad (como al implementar
las estructuras dinámicas internas de un Tipo de Dato Abstracto), las
especificaciones en lenguaje natural o aserciones en tiempo de ejecución
resultan insuficientes. Se requiere un marco formal sustentado en la lógica
matemática para probar de forma rigurosa la correctitud y coherencia de las
rutinas de software.

---


### 1. Fundamentos de Lógica de Primer Orden


La **Lógica de Primer Orden** (First-Order Logic, FOL) extiende la lógica
proposicional clásica introduciendo cuantificadores sobre elementos individuales
del dominio de discurso.

#### Sintaxis y Alfabeto de la LPO

Un lenguaje en Lógica de Primer Orden consta de:
*   **Variables:** Letras que representan elementos genéricos (ej: $x, y, i,
    j$).
*   **Conectores lógicos:** Negación ($\neg$), conjunción ($\land$), disyunción
    ($\lor$), implicación ($\rightarrow$), equivalencia ($\leftrightarrow$).
*   **Cuantificadores:** Universal ($\forall$, "para todo") y Existencial
    ($\exists$, "existe al menos uno").
*   **Constantes y Funciones:** Elementos fijos (ej: $0, 1$) o mapeos
    funcionales (ej: $\text{length}(\text{arr})$).
*   **Predicados:** Relaciones lógicas que evalúan a verdadero o falso (ej:
    $\text{sorted}(\text{arr})$ o la comparación física de orden $x < y$).

#### Variables Libres y Ligadas

Una ocurrencia de una variable en una fórmula está **ligada** si se encuentra
dentro del alcance directo de un cuantificador ($\forall x$ o $\exists x$). De
lo contrario, se considera una variable **libre**. Una fórmula que carece de
variables libres se denomina **sentencia**.

La operación de **sustitución** $\phi[t/x]$ representa el reemplazo de todas las
ocurrencias libres de la variable $x$ en la fórmula $\phi$ por el término $t$,
previniendo la colisión de identificadores.







---


### 2. Lógica de Hoare y Cálculo de Precondición Más Débil ($wp$)


La **Lógica de Hoare** provee un sistema axiomático formal para razonar sobre la
corrección de algoritmos imperativos mediante el uso de **Tripletas de Hoare**:

$$\{P\}\ S\ \{Q\}$$

Donde:
*   $P$ representa la **precondición** (aserción sobre el estado antes del
    programa).
*   $S$ representa la secuencia física de instrucciones del **programa**.
*   $Q$ representa la **postcondición** (aserción que se garantiza verdadera
    tras la ejecución exitosa de $S$).

#### Regla de la Asignación
La regla de asignación calcula analíticamente la precondición mínima requerida
para asegurar una postcondición $Q$ tras asignar una expresión $E$ a la variable
$x$:

$$\frac{}{\{Q[E/x]\}\ x := E\ \{Q\}}$$

#### Precondición Más Débil (Weakest Precondition - $wp$)
La precondición más débil $wp(S, Q)$ describe la condición más general (menos
restrictiva) sobre el estado inicial del sistema que garantiza que la ejecución
de $S$ finalice en un estado que satisfaga la postcondición $Q$.

$$wp(\texttt{x := E}, Q) \equiv Q[E/x]$$







---


### 3. Contratos de Estructuras de Datos e Invariantes de Clase


En el diseño de Tipos Datos Abstractos (TADs), un **invariante de clase** o de
estructura es una propiedad lógica fundamental que describe la validez interna
de la representación física de los datos. Debe ser verdadera tras la
construcción del objeto y preservarse antes y después de cada llamada a métodos
o funciones públicas del TAD.

```{code-block} c
:linenos:
typedef struct {
    int *elementos;
    int tope;
    int capacidad;
} pila_t;

// Invariante de estructura Pila:
// elementos != NULL ∧ capacidad > 0 ∧ 0 <= tope <= capacidad

```
<!-- {code-block} c -->

#### ACSL (ANSI/ISO C Specification Language)

ACSL permite escribir anotaciones formales directamente en los comentarios del
código de C para su verificación estática mediante analizadores como Frama-C:

```{code-block} c
:linenos:
/*@ predicate pila_valida(pila_t *p) =
        \valid(p) &&
        p->elementos != NULL &&
        p->capacidad > 0 &&
        0 <= p->tope <= p->capacidad &&
        \valid(p->elementos + (0..p->capacidad-1));
  */

/*@ requires pila_valida(p);
    requires p->tope < p->capacidad;
    assigns p->tope, p->elementos[p->tope];
    ensures pila_valida(p);
    ensures p->tope == \old(p->tope) + 1;
    ensures p->elementos[p->tope - 1] == dato;
  */
void push(pila_t *p, int dato);

```
<!-- {code-block} c -->

#### El Frame Problem y la directiva `assigns`

El **Frame Problem** consiste en la dificultad de especificar formalmente qué
partes del estado del sistema **no cambian** durante la ejecución de una
función. Sin una solución, las especificaciones deberían listar exhaustivamente
cada variable del programa que permanece igual.

En ACSL, esto se resuelve mediante la directiva **`assigns`**, la cual
especifica con exactitud las únicas variables o posiciones de memoria que la
función tiene permitido modificar. El analizador formal asume de manera
automática que todo lo que no figure en dicha cláusula permanece inalterado.

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-contrato-lpo-cuantificador
Traducí a una fórmula matemática formal en Lógica de Primer Orden la siguiente
proposición: "Todos los elementos del arreglo `arr` de tamaño `n` comprendidos
entre los índices `0` y `limit` inclusive son mayores que la constante entera
`K`".

:::
<!-- {exercise} -->

:::{solution} ej-contrato-lpo-cuantificador
:class: dropdown
La fórmula en LPO utilizando cuantificación universal es:
$$\forall i.\ (0 \leq i \leq \text{limit} < n) \rightarrow (\text{arr}[i] > K)$$

:::
<!-- {solution} ej-contrato-lpo-cuantificador -->

:::{exercise}
:label: ej-contrato-lpo-free-bound
Dada la fórmula $\forall x.\ (x < y) \rightarrow \exists z.\ (x + z = y)$,
identificá de forma precisa cuáles variables tienen ocurrencias ligadas y cuáles
libres en la expresión.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-lpo-free-bound
:class: dropdown
*   **Ligadas:** Las variables $x$ y $z$ son variables ligadas debido a que sus
    ocurrencias se encuentran bajo el alcance directo de los cuantificadores
    universal $\forall x$ y existencial $\exists z$ respectivamente.
*   **Libres:** La variable $y$ es libre porque no se encuentra bajo el alcance
    de ningún cuantificador lógico en la fórmula.

:::
<!-- {solution} ej-contrato-lpo-free-bound -->

:::{exercise}
:label: ej-contrato-lpo-substitution
Realizá el cálculo de la sustitución del término `w+2` en la variable `x` para
la fórmula lógica $(\exists y.\ x * y > 10)[w+2/x]$.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-lpo-substitution
:class: dropdown
La sustitución reemplaza la ocurrencia libre de $x$ por el término sin alterar
la estructura ligada de $y$:
$$(\exists y.\ x * y > 10)[w+2/x] \equiv \exists y.\ (w + 2) * y > 10$$

:::
<!-- {solution} ej-contrato-lpo-substitution -->

:::{exercise}
:label: ej-hoare-triple-swap
Demostrá mediante el uso de la regla de asignación de Hoare que la terna lógica
$\{y = B \land x = A\}\ t := x; x := y; y := t\ \{x = B \land y = A\}$ es
parcialmente correcta.

:::
<!-- {exercise} -->

:::{solution} ej-hoare-triple-swap
:class: dropdown
Aplicamos la regla de asignación de Hoare de atrás hacia adelante:
1. Para la última instrucción $y := t$ con postcondición $Q = (x = B \land y =
   A)$:
   $$Q[t/y] \equiv (x = B \land t = A)$$
2. Para la instrucción anterior $x := y$ sobre la condición anterior:
   $$(x = B \land t = A)[y/x] \equiv (y = B \land t = A)$$
3. Para la primera instrucción $t := x$:
   $$(y = B \land t = A)[x/t] \equiv (y = B \land x = A)$$

La precondición obtenida de forma analítica es exactamente $\{y = B \land x =
A\}$, lo cual demuestra la corrección de la terna.

:::
<!-- {solution} ej-hoare-triple-swap -->

:::{exercise}
:label: ej-hoare-weakest-pre
Calculá analíticamente la precondición más débil ($wp$) de la instrucción `x :=
x * 2` con respecto a la postcondición `x > 10`.

:::
<!-- {exercise} -->

:::{solution} ej-hoare-weakest-pre
:class: dropdown
Utilizando la regla de la precondición más débil para la asignación:
$$wp(\texttt{x := x * 2}, x > 10) \equiv (x * 2 > 10) \equiv (x > 5)$$

:::
<!-- {solution} ej-hoare-weakest-pre -->

:::{exercise}
:label: ej-hoare-rule-consequence
Explicá el funcionamiento y propósito de la Regla de Consecuencia en la Lógica
de Hoare, detallando qué significa "debilitar la precondición" y "fortalecer la
postcondición".

:::
<!-- {exercise} -->

:::{solution} ej-hoare-rule-consequence
:class: dropdown
La Regla de Consecuencia permite adaptar tripletas de Hoare preexistentes a
contextos más estrictos o específicos.

$$\frac{P' \rightarrow P \quad \{P\}\ S\ \{Q\} \quad Q \rightarrow Q'}{\{P'\}\
S\ \{Q'\}}$$

*   **Debilitar la precondición ($P' \rightarrow P$):** Reemplazar la
    precondición $P$ por una condición $P'$ que es más restrictiva. Si el
    programa funciona asumiendo una precondición débil, seguirá siendo correcto
    con una más fuerte.
*   **Fortalecer la postcondición ($Q \rightarrow Q'$):** Reemplazar la
    postcondición $Q$ por una condición $Q'$ que sea menos restrictiva,
    garantizando más de lo inicialmente especificado.

:::
<!-- {solution} ej-hoare-rule-consequence -->

:::{exercise}
:label: ej-contrato-frame-assigns
Explicá qué es el *Frame Problem* en la especificación formal de software y de
qué forma la directiva `assigns` en ACSL permite solucionarlo para los
analizadores estáticos.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-frame-assigns
:class: dropdown
El *Frame Problem* es la dificultad de expresar formalmente qué variables y
recursos del sistema **no se modifican** tras la ejecución de una rutina sin
tener que listar explícitamente el infinito número de variables inalteradas.

La directiva `assigns` soluciona esto en ACSL permitiendo declarar un marco
delimitado de variables de escritura. El analizador estático (como Frama-C)
asume automáticamente que cualquier variable o celda del heap que no esté
listada de forma explícita en la directiva `assigns` permanece inalterada, lo
que simplifica drásticamente el cálculo de las condiciones de verificación.

:::
<!-- {solution} ej-contrato-frame-assigns -->

:::{exercise}
:label: ej-contrato-acsl-valid
Escribí la cabecera anotada con especificaciones formales de ACSL para una
función `void resetear(int *ptr)` que requiera que el puntero sea de escritura
válido y garantice que el valor apuntado tras la llamada es `0`.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-acsl-valid
:class: dropdown
``` c
/*@ requires \valid(ptr);
    assigns *ptr;
    ensures *ptr == 0;
 */
void resetear(int *ptr);
```
<!-- c -->

:::
<!-- {solution} ej-contrato-acsl-valid -->

:::{exercise}
:label: ej-contrato-lsp-violation
Explicá por qué la redefinición del comportamiento de un subtipo `Cuadrado`
derivado de `Rectangulo` en estructuras mutables viola el Principio de
Sustitución de Liskov (LSP) de acuerdo con la fuerza de las precondiciones y
postcondiciones de sus operaciones de redimensionamiento.

:::
<!-- {exercise} -->

:::{solution} ej-contrato-lsp-violation
:class: dropdown
En un `Rectangulo` mutable, la operación `set_ancho(w)` tiene la postcondición
de que el ancho se actualiza a `w` y el alto permanece inalterado.

Si `Cuadrado` es un subtipo, para mantener su invariante de estructura (`ancho
== alto`), la operación `set_ancho(w)` debe forzosamente alterar el alto
también. Esto viola la postcondición heredada de `Rectangulo` (que garantiza que
el alto no se modifica), rompiendo el Principio de Sustitución de Liskov ya que
un código cliente diseñado para `Rectangulo` fallaría si se le pasa un objeto de
tipo `Cuadrado`.

:::
<!-- {solution} ej-contrato-lsp-violation -->

## Glosario

:::{glossary}
Precondición
: Condición que debe cumplirse antes de invocar una función.

Postcondición
: Garantía que ofrece una función al finalizar si se cumplieron sus precondiciones.

Invariante
: Propiedad que debe permanecer verdadera durante el ciclo de vida de un objeto o ejecución.

Invariante de lazo (Loop Invariant)
: Condición o propiedad lógica asociada a una estructura iterativa que permanece
verdadera antes de ingresar al lazo, antes y después de cada vuelta, y al salir
de este.
:::

## Síntesis y Resumen

En este apunte se han presentado los conceptos fundamentales del tema.

(referencias-lecturas-contratos-formales)=
## Referencias y Lecturas Complementarias

- **Meyer, B.** [@meyer1988]. *Design by Contract*. Prentice Hall.
  - El ensayo original que define e introduce la metodología de Diseño por Contrato en la construcción de software robusto.
- **Meyer, B.** [@meyer1992]. *Applying "Design by Contract"*. IEEE Computer.
  - Artículo clásico que analiza de forma compacta y pragmática el uso de precondiciones, postcondiciones e invariantes para el control de errores en tiempo de ejecución.
- **Meyer, B.** [@meyer_object_1997]. *Object-Oriented Software Construction* (2.ª edición). Prentice Hall.
  - Consultá los capítulos dedicados a la teoría de contratos, herencia y correctitud de algoritmos, que sientan las bases formales del modelado de invariantes de representación.
