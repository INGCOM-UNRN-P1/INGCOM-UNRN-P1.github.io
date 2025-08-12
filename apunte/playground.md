# Probando features del MystMD

## Temas pendientes para desarrollar apunte

1. casts (explicitos e implicitos)
2. debugging, tecnicas y ejercicios
3. makefiles for dummies
4. algoritmos (atributos, partes)
5. p vs np
6. estructuras de datos lineales (arreglos/stack/queue)



## Referencias cruzadas

[Documentacion](https://mystmd.org/guide/cross-references)

## Cuestiones de estilo

Este es un parrafo

[`0x0000h`](./estilo.md#regla-0x0000-la-claridad-y-prolijidad-son-muy-importantes)

:::{card} 🪐 Cuestión de estilo
:link: ./estilo.md#regla-0x0000-la-claridad-y-prolijidad-son-muy-importantes
You can use the `{eval}` role to evaluate variables directly inside of your
markdown cells, including widgets, sparklines and other variables.
:::

:::{attention} La claridad y prolijidad son muy importantes
:class: dropdown
👋 This could be a solution to a problem or contain other detailed explanations.
:::

:::{tip} Admonition _title_
Here is an admonition!
:::

:::{attention} Admonition _title_
Here is an admonition!
:::

- 🔵 {note}
- 🔵 {important}
- 🟢 {hint}
- 🟢 {seealso}
- 🟢 {tip}
- 🟠 {attention}
- 🟠 {caution}
- 🟠 {warning}
- 🔴 {danger}
- 🔴 {error}

Este es otro parrafo

## Bibliografía

@kernighan_c_2014

[Mas informacion](https://mystmd.org/guide/citations)

## Ejercicios

```{exercise}
:label: factorial
:enumerator: "10"


Recordando que $n!$ se lee cómo  "$n$ factorial" y se define
$n! = n \times (n - 1) \times \cdots \times 2 \times 1$.

There are functions to compute this in various modules, but let's
write our own version as an exercise.

In particular, write a function `factorial` such that `factorial(n)` returns $n!$
for any positive integer $n$.
```

````{solution} factorial
:label: solucion-factorial
:class: dropdown

Esta es una forma de resolverlo

```{code-block} python
def factorial(n):
    k = 1
    for i in range(n):
        k = k * (i + 1)
    return k

factorial(4)
```
````

## Código con descripcion

Esta con todas las opciones, como para ir regulando

```{code} python
:label: my-program
:caption: Creating a TensorMesh using SimPEG
:linenos:
:emphasize-lines: 2,3
:filename: tensor.py

from discretize import TensorMesh

hx = [(1, 40)]
hy = [(1, 40)]

mesh = TensorMesh([hx, hy])
```

## Codigo desde un archivo

La ruta es relativa a la de este documento.

El `start-at` y `end-before` es una busqueda textual para traer fragmentos.

```{literalinclude} ../myst.yml
:start-at: project
:end-before: references
:linenos:
:lineno-match:
```

## Glosario

De paso tambien, abreviaturas, {abbr}`HR (Heart Rate)`

### Definición

:::{glossary}
MyST
: An amazing markup language that supports glossaries
:::

### Utilización

{term}`MyST` produces MyST

## Diagramas Mermaid

```{mermaid}
flowchart LR
  A[Jupyter Notebook] --> C
  B[MyST Markdown] --> C
  C(mystmd) --> D{AST}
  D <--> E[LaTeX]
  E --> F[PDF]
  D --> G[Word]
  D --> H[React]
  D --> I[HTML]
  D <--> J[JATS]
```
