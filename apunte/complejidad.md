---
title: "Complejidad"
short_title: "8 - Algoritmos II"
subtitle: "Ordenando y comparando métodos"
---

---

title: "Análisis de Algoritmos: Un Estudio Profundo de la Complejidad"
description: "Un apunte detallado que explora los principios del análisis de
algoritmos, desde la notación asintótica y el cálculo práctico de la complejidad
hasta conceptos avanzados como el análisis amortizado y una introducción a P vs.
NP."

---

# Análisis de Complejidad de Algoritmos: El Estudio de la Eficiencia

El **análisis de algoritmos** es una disciplina fundamental en la ciencia de la
computación que se enfoca en cuantificar los recursos que un algoritmo consume.
Su propósito es predecir, de manera formal y rigurosa, cómo se comportará un
algoritmo en términos de tiempo de ejecución y uso de memoria a medida que el
tamaño de la entrada de datos crece.

El objetivo principal no es obtener tiempos exactos en segundos —una métrica
volátil que depende del hardware, el compilador y el sistema operativo— sino
establecer una base teórica para:

1.  **Comparar algoritmos**: Determinar objetivamente cuál de dos algoritmos es
    más eficiente para resolver un mismo problema.
2.  **Predecir la escalabilidad**: Entender si un algoritmo seguirá siendo
    viable cuando el volumen de datos aumente de miles a millones o miles de
    millones de registros.
3.  **Optimizar el código**: Identificar los cuellos de botella y las partes
    críticas de un programa que más impactan en su rendimiento.

Para lograr esto, la herramienta central es el **análisis asintótico**.

## Análisis Asintótico: Enfocándose en lo que Importa

El análisis asintótico es una metodología matemática que describe el
comportamiento de una función en su límite, es decir, cuando el tamaño de la
entrada ($n$) se vuelve arbitrariamente grande (tiende al infinito). Este
enfoque nos permite abstraernos de los detalles de la implementación y del
hardware, y concentrarnos en la **tasa de crecimiento** intrínseca del
algoritmo.

Al analizar una función de costo como $T(n) = 3n^2 + 100n + 500$, observamos que
para valores grandes de $n$, el término $3n^2$ domina a los demás. El análisis
asintótico nos permite simplificar esta expresión a su orden de crecimiento, que
es $n^2$, ignorando constantes multiplicativas ($3$) y términos de menor orden
($100n + 500$).

## Las Notaciones Asintóticas: O, Ω, y Θ

Para formalizar este análisis, utilizamos un conjunto de notaciones que
describen los límites del crecimiento de la función de costo de un algoritmo.

### 1. Notación Big O (O) - Cota Superior (Peor Caso)

La notación **Big O** es la más utilizada en la práctica, ya que describe una
**cota superior asintótica**. Nos ofrece una garantía sobre el rendimiento del
algoritmo: nunca será peor que esta cota.

- **Definición Intuïtiva**: Una función $f(n)$ es $O(g(n))$ si su tasa de
  crecimiento es **igual o más lenta** que la de $g(n)$ para entradas
  suficientemente grandes.
- **Definición Formal**: $f(n) = O(g(n))$ si existen constantes positivas $c$ y
  $n_0$ tales que $0 \le f(n) \le c \cdot g(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **peor caso** de ejecución de un algoritmo.

### 2. Notación Omega ($\Omega$) - Cota Inferior (Mejor Caso)

La notación **Omega** describe una **cota inferior asintótica**. Nos garantiza
que el rendimiento del algoritmo nunca será mejor que esta cota.

- **Definición Intuïtiva**: Una función $f(n)$ es $\Omega(g(n))$ si su tasa de
  crecimiento es **igual o más rápida** que la de $g(n)$.
- **Definición Formal**: $f(n) = \Omega(g(n))$ si existen constantes positivas
  $c$ y $n_0$ tales que $0 \le c \cdot g(n) \le f(n)$ para todo $n \ge n_0$.
- **Uso Práctico**: Representa el **mejor caso** de ejecución.

### 3. Notación Theta ($\Theta$) - Cota Ajustada (Caso Exacto)

La notación **Theta** proporciona la descripción más precisa del comportamiento
de un algoritmo, acotándolo tanto por arriba como por abajo.

- **Definición Intuïtiva**: Una función $f(n)$ es $\Theta(g(n))$ si su tasa de
  crecimiento es **exactamente la misma** que la de $g(n)$.
- **Relación**: $f(n) = \Theta(g(n))$ si y solo si $f(n) = O(g(n))$ y
  $f(n) = \Omega(g(n))$.
- **Uso Práctico**: Describe el comportamiento del algoritmo de forma ajustada,
  a menudo representando el **caso promedio** o un escenario donde el mejor y el
  peor caso coinciden.

## Análisis Práctico: ¿Cómo Calcular la Complejidad?

Para analizar un fragmento de código, se aplican reglas sistemáticas:

1.  **Operaciones Básicas**: Las operaciones simples (asignación, aritmética,
    acceso a un arreglo) se consideran de tiempo constante, $O(1)$.
2.  **Secuencias de Bloques**: Si un algoritmo consta de dos bloques de código
    ejecutados en secuencia, con complejidades $O(f(n))$ y $O(g(n))$, la
    complejidad total es la del bloque dominante: $O(\max(f(n), g(n)))$.
3.  **Bucles**: La complejidad de un bucle es el producto de su número de
    iteraciones y la complejidad de su cuerpo.
    - Un bucle `for i=0 to n-1` con un cuerpo $O(1)$ tiene complejidad $O(n)$.
4.  **Bucles Anidados**: La complejidad se calcula multiplicando las
    complejidades de todos los bucles.
    - Dos bucles anidados de `0` a `n` resultan en $O(n^2)$.
5.  **Condicionales (`if-else`)**: Se toma la complejidad de la rama que
    represente el peor caso.
6.  **Recursividad**: La complejidad de una función recursiva se describe
    mediante una **relación de recurrencia**. Por ejemplo, para la búsqueda
    binaria, $T(n) = T(n/2) + O(1)$, que se resuelve en $O(\log n)$.

## Tipos de Análisis: Mejor, Peor, Promedio y Amortizado

### Mejor, Peor y Caso Promedio

El rendimiento de un algoritmo puede variar según la entrada. Por ello, se
distingue:

- **Mejor Caso ($\Omega$)**: El escenario más favorable. (Ej: Quick Sort sobre
  un arreglo ya ordenado, si el pivote se elige mal).
- **Peor Caso ($O$)**: El escenario más desfavorable. Es el más importante
  porque ofrece una garantía. (Ej: Quick Sort cuando el pivote es siempre el
  mínimo o máximo).
- **Caso Promedio ($\Theta$)**: El rendimiento esperado sobre todas las entradas
  posibles. Es más realista pero a menudo complejo de calcular matemáticamente.

### Análisis Amortizado

Este tipo de análisis es útil cuando una secuencia de operaciones tiene un costo
promedio bajo, a pesar de que algunas operaciones individuales puedan ser muy
costosas. El costo de las operaciones "caras" se "amortiza" o distribuye entre
las operaciones más baratas.

- **Ejemplo Clásico**: Un arreglo dinámico (como `std::vector` en C++ o
  `ArrayList` en Java). Añadir un elemento es, en general, una operación $O(1)$.
  Sin embargo, cuando el arreglo se llena, es necesario redimensionarlo: crear
  un nuevo arreglo más grande y copiar todos los elementos existentes, una
  operación $O(n)$. El análisis amortizado demuestra que, a lo largo de una
  secuencia de $n$ inserciones, el costo promedio por inserción sigue siendo
  $O(1)$.

## Clases Comunes de Complejidad

- **$O(1)$ — Constante**: Acceder a un elemento de un arreglo por su índice.
- **$O(\log n)$ — Logarítmica**: Búsqueda binaria.
- **$O(n)$ — Lineal**: Recorrer un arreglo.
- **$O(n \log n)$ — Log-lineal**: Algoritmos de ordenamiento eficientes (Merge
  Sort, Heap Sort).
- **$O(n^2)$ — Cuadrática**: Algoritmos de ordenamiento simples (Bubble Sort).
- **$O(2^n)$ — Exponencial**: Algoritmos que exploran todas las combinaciones
  posibles (fuerza bruta).
- **$O(n!)$ — Factorial**: Aún peor que la exponencial (ej: Problema del
  viajante por fuerza bruta).

## Complejidad Espacial: El Costo en Memoria

Además del tiempo, se analiza la **complejidad espacial**: la cantidad de
memoria que un algoritmo necesita. Un algoritmo es **"in-place"** si su espacio
auxiliar es $O(1)$.

- **Espacio $O(1)$**: Bubble Sort (solo necesita una variable temporal).
- **Espacio $O(\log n)$**: Quick Sort (por la pila de recursión en el caso
  promedio).
- **Espacio $O(n)$**: Merge Sort (necesita un arreglo auxiliar del tamaño de la
  entrada).

## Más Allá: Una Introducción a la Teoría de la Complejidad (P vs. NP)

Mientras que el análisis de algoritmos se enfoca en determinar la eficiencia de
una solución específica, la **teoría de la complejidad** aborda una pregunta más
fundamental: ¿cuál es la dificultad _inherente_ de un problema? No se pregunta
"¿cuán rápido es mi algoritmo para ordenar?", sino "¿cuán rápido _puede ser_
cualquier algoritmo que ordene?".

Esta disciplina clasifica los problemas computacionales en **clases de
complejidad** basadas en los recursos (tiempo y memoria) que se requieren para
resolverlos en el peor de los casos, independientemente del algoritmo específico
utilizado.

## Problemas de Decisión y el Modelo de Cómputo

Para formalizar el estudio, la teoría se centra en los **problemas de
decisión**: aquellos que pueden ser respondidos con un simple "sí" o "no".
Aunque parece limitante, muchos problemas más complejos (como los de
optimización) pueden reformularse como una serie de problemas de decisión.

- **Ejemplo de Optimización**: "¿Cuál es la ruta más corta que visita todas
  estas ciudades?"
- **Ejemplo de Decisión**: "Dadas estas ciudades, ¿existe una ruta que las
  visite a todas y cuya longitud total sea menor que $K$ kilómetros?"

El modelo formal de cómputo utilizado para definir estas clases es la **Máquina
de Turing**, un autómata teórico que puede simular la lógica de cualquier
algoritmo computacional.

## La Clase P (Tiempo Polinomial)

La clase **P** contiene todos los problemas de decisión que pueden ser
**resueltos** por una Máquina de Turing determinista en **tiempo polinomial**.

- **Tiempo Polinomial**: Significa que el tiempo de ejecución del peor caso está
  acotado por una función polinómica del tamaño de la entrada $n$, es decir,
  $O(n^k)$ para alguna constante $k$.
- **Significado Intuïtivo**: La clase P representa el conjunto de problemas que
  consideramos "eficientemente resolubles" o "**tratables**". A medida que la
  entrada crece, el tiempo de ejecución aumenta a una tasa manejable.

**Ejemplos de problemas en P**:

- Ordenamiento de una lista.
- Búsqueda de un elemento en un arreglo.
- Determinar si un número es primo.
- Encontrar el camino más corto en un grafo (Algoritmo de Dijkstra).

## La Clase NP (Tiempo Polinomial No Determinista)

Aquí es donde surge una de las mayores confusiones en la informática. **NP**
_no_ significa "No Polinomial". Significa **Tiempo Polinomial No Determinista**.

Existen dos definiciones equivalentes y muy importantes:

1.  **Definición Formal**: La clase NP es el conjunto de problemas de decisión
    que pueden ser resueltos por una **Máquina de Turing no determinista** en
    tiempo polinomial. (Una máquina no determinista puede explorar múltiples
    caminos de cómputo simultáneamente).
2.  **Definición Práctica (y más útil)**: La clase NP es el conjunto de
    problemas de decisión para los cuales, si se nos proporciona una posible
    solución (un "certificado" o "testigo"), podemos **verificar** si es
    correcta en tiempo polinomial.

- **Significado Intuïtivo**: NP es la clase de problemas cuyas soluciones son
  "fáciles de verificar", aunque encontrarlas pueda ser muy difícil.

**Ejemplo Clásico: El Problema de Satisfacibilidad Booleana (SAT)**

- **Problema**: Dada una fórmula lógica booleana, ¿existe una asignación de
  valores de verdad (verdadero/falso) a sus variables que haga que toda la
  fórmula sea verdadera?
- **Encontrar la solución**: Puede ser extremadamente difícil. Con $n$
  variables, hay $2^n$ posibles asignaciones que probar (fuerza bruta).
- **Verificar una solución**: Si alguien te da una asignación concreta (ej:
  $x_1$=V, $x_2$=F, ...), es trivialmente fácil y rápido (tiempo polinomial)
  sustituir esos valores en la fórmula y comprobar si el resultado es verdadero.

Por lo tanto, SAT está en NP.

## La Pregunta del Millón de Dólares: ¿P = NP?

Claramente, si un problema puede ser resuelto rápidamente (está en P), entonces
su solución también puede ser verificada rápidamente. Esto significa que **la
clase P está contenida dentro de la clase NP**.

La pregunta fundamental, uno de los siete Problemas del Milenio del Instituto
Clay de Matemáticas, es: **¿Son estas dos clases realmente la misma? ¿Es P igual
a NP?**

- **Traducción**: "Si una solución a un problema puede ser verificada
  eficientemente, ¿puede esa solución también ser encontrada eficientemente?"

Nadie ha sido capaz de probarlo en ninguna de las dos direcciones. Sin embargo,
el consenso abrumador entre los científicos de la computación es que **P ≠ NP**.

### Implicaciones de la Respuesta

- **Si P = NP**: Sería una revolución. Problemas que hoy consideramos
  intratables (en logística, criptografía, investigación de proteínas, IA)
  tendrían soluciones eficientes. La creatividad podría ser automatizada, ya que
  verificar la "belleza" de una prueba matemática o una composición musical es a
  menudo más fácil que crearla.
- **Si P ≠ NP**: Confirma que existen problemas fundamentalmente "duros" que no
  pueden ser resueltos eficientemente. Para estos problemas, debemos confiar en
  algoritmos de aproximación, heurísticas o soluciones para casos específicos,
  sabiendo que una solución general y rápida no es posible.

## Reducciones y la Noción de "El Problema más Difícil"

Para clasificar la dificultad relativa de los problemas dentro de NP, se utiliza
el concepto de **reducción en tiempo polinomial**. Un problema A se "reduce" a
un problema B si podemos transformar cualquier instancia de A en una instancia
de B de tal manera que la solución para B nos da la solución para A, y esta
transformación toma tiempo polinomial.

- **Significado**: Si A se reduce a B, entonces A "no es más difícil que" B.

### NP-Hard y NP-Completo

- **NP-Hard (NP-Duro)**: Un problema es NP-Hard si **todo problema en NP** se
  puede reducir a él en tiempo polinomial. Estos son los problemas que son "al
  menos tan difíciles como" cualquier problema en NP.
- **NP-Completo (NPC)**: Un problema es NP-Completo si cumple dos condiciones:
  1.  Está en NP (sus soluciones son verificables en tiempo polinomial).
  2.  Es NP-Hard.

Los problemas NP-Completos son, en esencia, los **problemas más difíciles de la
clase NP**.

El **Teorema de Cook-Levin (1971)** fue el hito que demostró que el problema
**SAT** es NP-Completo. Desde entonces, se ha demostrado que miles de otros
problemas importantes también lo son, mediante reducciones a partir de SAT u
otros problemas NPC conocidos.

**Ejemplos de Problemas NP-Completos**:

- Problema del Viajante (versión de decisión).
- Coloreado de Grafos.
- El juego Sudoku (generalizado a un tablero de $n^2 \times n^2$).

La importancia de los problemas NPC es inmensa: si se encontrara un algoritmo de
tiempo polinomial para _un solo_ problema NP-Completo, automáticamente
tendríamos un algoritmo eficiente para _todos_ los problemas en NP, lo que
probaría que **P = NP**.

### Visualización de las Clases de Complejidad

Asumiendo que P ≠ NP, la relación entre estas clases se puede visualizar de la
siguiente manera:

```{mermaid}
graph TD
    subgraph NP
        subgraph P
            A[Ordenamiento]
            B[Búsqueda Binaria]
        end
        subgraph "NP-Completo (NPC)"
            C[SAT]
            D[Viajante]
            E[Sudoku]
        end
        F[Factorización de Enteros]
    end
    subgraph "NP-Hard"
        G[Problema de Parada]
    end

    P --> F
    F --> C
    NPC --> G

    style P fill:#cde4ff,stroke:#333
    style NPC fill:#ffcdd2,stroke:#333
    style NP fill:#fff9c4,stroke:#666,stroke-dasharray: 5 5
    style NPHard fill:#e1bee7,stroke:#666,stroke-dasharray: 5 5
```

Este diagrama ilustra que P y NPC son subconjuntos de NP. Los problemas NP-Hard
pueden estar dentro o fuera de NP. El problema de la **Factorización de
Enteros**, en el que se basa gran parte de la criptografía moderna, es un
ejemplo fascinante: está en NP, pero no se sabe si es NP-Completo o si está en
P.
