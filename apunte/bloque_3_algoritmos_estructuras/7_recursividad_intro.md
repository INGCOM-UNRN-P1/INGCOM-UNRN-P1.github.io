---
title: Introducción a la Recursividad
short_title: 'Recursividad'
description: Conceptos básicos de recursión, casos base, pasos recursivos y el funcionamiento del stack frame de llamadas en C.
---

(capitulo-recursividad-basica)=
# Introducción a la recursividad

> **Prerrequisitos**: funciones, condicionales, parámetros por valor y stack
> frame. Debés poder trazar una llamada y reconocer cuándo una variable local
> deja de existir.
>
> **Objetivo**: diseñar un caso base alcanzable y demostrar que cada llamada se
> acerca a él.
>
> **Comprobación de salida**: señalá el caso base y la medida que decrece en una función recursiva propuesta.

## Introducción

La recursividad es una técnica de programación fundamental en la que una función
se llama a sí misma para resolver un problema. Este enfoque se basa en la idea
de descomponer un problema complejo en subproblemas más pequeños y de la misma
naturaleza.

---

## Desarrollo

(definicion-matematica)=
### Definición Matemática

Desde una perspectiva matemática, una definición recursiva tiene dos partes
esenciales:

1.  **Caso Base:** Es una o más condiciones terminales que no requieren de una
    nueva llamada a la función para ser resueltas. Es la solución explícita para
    el caso más simple del problema.
2.  **Paso Recursivo (o Relación de Recurrencia):** Es la regla que reduce el
    problema a una versión más simple de sí mismo. Define cómo se resuelve el
    problema para un caso `n` en términos de uno o más casos "menores" (por
    ejemplo, `n-1`).

Un ejemplo clásico es la función factorial, $n!$, que se define de la siguiente
manera:

$$
n! = \begin{cases} 
1 & \text{si } n = 0 \text{ (Caso Base)} \\
n \times (n-1)! & \text{si } n > 0 \text{ (Paso Recursivo)}
\end{cases} 
$$

Esta definición establece que el factorial de 0 es 1 (caso base) y que el
factorial de cualquier otro número natural `n` es `n` multiplicado por el
factorial de `n-1`.

(construccion-de-algoritmos-recursivos-en-c)=
### Construcción de Algoritmos Recursivos en C

Para implementar un algoritmo recursivo en C, debés seguir la estructura de la
definición matemática.

#### Componentes Clave

Un algoritmo recursivo siempre debe tener:

*   **Caso Base:** Una estructura condicional (normalmente un `if`) que verifica
    si se ha alcanzado la condición de parada. Sin un caso base, la función se
    llamaría a sí misma infinitamente, resultando en un error de desbordamiento
    de pila (*stack overflow*).
*   **Paso Recursivo:** La parte del código donde la función se invoca a sí
    misma, pero con argumentos que la acercan progresivamente al caso base. Es
    crucial que cada llamada recursiva opere sobre un subproblema más pequeño.

#### Ejemplo: Función Factorial en C

Veamos cómo se traduce la definición matemática del factorial a una función en
C.

:::{code-block} c
:linenos:
#include <stdio.h>
// Declaración de la función factorial
long int factorial(int n);
int main(void)
{
    int numero = 5;
    long int resultado = factorial(numero);
    if (resultado == -1)
    {
        printf("Error: no se puede calcular el factorial de un número
        negativo.\n");
    }
    else
    {
        printf("El factorial de %d es %ld\n", numero, resultado);
    }
    return 0;
}
// Definición de la función recursiva
long int factorial(int n)
{
    // Validación de precondición (robustez ante valores inválidos, regla
    {
        ref
    }`0x2001h`)
    if (n < 0)
    {
        return -1;
    }
    // Caso Base: si n es 0, el factorial es 1.
    if (n == 0)
    {
        return 1;
    }
    // Paso Recursivo: n * factorial(n-1)
    return n * factorial(n - 1);
}

:::
<!-- {code-block} c -->

##### Análisis del Código

1.  **Caso Base:** La línea `if (n == 0)` comprueba la condición de parada. Si
    `n` es 0, la función retorna `1` y la cadena de llamadas recursivas comienza
    a resolverse.
2.  **Paso Recursivo:** En la última sentencia, la función retorna el resultado
    de `n` multiplicado por el valor devuelto por la llamada a `factorial(n -
    1)`. Esta llamada opera sobre un subproblema de menor tamaño (`n-1`),
    garantizando la convergencia hacia el caso base.

:::{important} Pila de llamadas (Call Stack) y Anatomía del Stack Frame

Cada vez que un programa invoca una función, se reserva un espacio de memoria
física en la pila del sistema (*call stack*) denominado **marco de pila** o
*stack frame*. En una arquitectura moderna típica (como x86_64), un marco de
pila contiene los siguientes elementos esenciales:

1. **Dirección de Retorno:** La dirección de la instrucción en la función
   llamadora a la que debe retornar el control del flujo del procesador una vez
   que finalice la ejecución de la función actual.
2. **Parámetros de Entrada:** Los argumentos provistos a la función.
3. **Puntero de Marco Anterior (Saved Frame Pointer):** La dirección de base
   (`rbp`) del marco de la función que la invocó.
4. **Variables Locales:** Espacio reservado para almacenar los datos definidos
   internamente en la función durante su ciclo de vida.

En la recursividad, cada llamada consecutiva apila un nuevo marco. Estos marcos
se acumulan hasta alcanzar el caso base, punto en el cual se inicia la fase de
resolución y retorno ("desapilado") en orden inverso al de la llamada (LIFO:
*Last In, First Out*).

:::
<!-- {important} Pila de llamadas (Call Stack) y Anatomía del Stack Frame -->

A continuación se muestra de forma gráfica y formal la distribución física en
memoria del *Call Stack* durante el cálculo recursivo de `factorial(3)` hasta
alcanzar el caso base, ilustrando las direcciones físicas de memoria en la pila
y las direcciones lógicas de retorno de código:

:::{figure} 7/pila_factorial.svg
:label: fig-pila-factorial-stack
:align: center
:width: 85%

Crecimiento y colapso de los marcos de pila en la recursión de `factorial(3)`.
Cada llamada apila un nuevo marco temporal consumiendo espacio físico de memoria
RAM.

:::
<!-- {figure} 7/pila_factorial.svg -->
<!-- {figure} 6/pila_factorial.svg -->

Como se observa en el diagrama, cada llamada suspendida (`factorial(3)` y
`factorial(2)`) mantiene su estado completo en una dirección de memoria
diferente de la RAM. Solo cuando `factorial(1)` retorna su valor constante $1$ a
la dirección de retorno de su llamador, el marco superior se destruye (se
desplaza el puntero de pila `rsp`) y se reanuda la evaluación aritmética en el
marco inmediatamente inferior.

(el-peligro-de-la-recursividad-stack-overflow-y-la-paradoja-del-factorial)=
### El Peligro de la Recursividad: Stack Overflow y la Paradoja del Factorial

El tamaño total disponible para la pila de llamadas (*call stack*) es finito
(típicamente entre 1 y 8 megabytes en sistemas Unix/Linux). Si el consumo de
pila excede dicho límite físico, se produce un desbordamiento catastrófico de
pila o **stack overflow**, lo cual interrumpe inmediatamente el programa con un
fallo de segmentación.

Las causas principales de este fallo son:
1. **Ausencia o fallo en el Caso Base (Recursión Infinita):** Si la condición de
   parada no se cumple o los parámetros no convergen al caso base.
2. **Recursión Demasiado Profunda:** Aún si el algoritmo es lógicamente
   correcto, si la profundidad de llamadas es excesiva, la pila se agotará.

#### La Paradoja del Factorial: Límites del Tipo de Dato vs. Límites de la Pila

:::{note} Contraste Cuantitativo

El factorial es el ejemplo introductorio por excelencia de la recursividad, pero
presenta una severa deficiencia didáctica si se analiza con rigor de ingeniería
de software.

En sistemas de 64 bits modernos, un entero de tipo `long int` de C ocupa 8
bytes, permitiendo almacenar valores en el rango:

$$-2^{63} \leq \text{long int} \leq 2^{63} - 1 \quad (\approx 9.22 \times 10^{18})$$

* El factorial de 20 es $20! \approx 2.43 \times 10^{18}$ (entra dentro de los
  límites del tipo).
* El factorial de 21 es $21! \approx 5.10 \times 10^{19}$ (supera la capacidad
  máxima del tipo `long int` y produce un **desbordamiento aritmético**).

Por lo tanto, la implementación de `factorial(n)` recursiva en C fallará y
devolverá valores matemáticamente erróneos para $n \geq 21$. Sin embargo, para
provocar un *stack overflow* físico en una pila de 8 MB con marcos de 32 bytes,
se requerirían aproximadamente:

$$\frac{8 \times 10^6 \text{ bytes}}{32 \text{ bytes/marco}} \approx 250.000 
\text{ llamadas recursivas}$$

Esto significa que **el desbordamiento aritmético ocurre en $n=21$, mucho antes
de comprometer la estabilidad física del stack**. El estudiante no ve el límite
del stack en este ejemplo clásico, sino el límite físico de almacenamiento del
tipo de dato binario.

:::
<!-- {note} Contraste Cuantitativo -->

---

## Ejercicios de Autoevaluación

### Definición Matemática

:::{exercise}
:label: ej-def-mat-fibonacci
Escribí la definición matemática formal (usando notación por casos) para la
sucesión de Fibonacci, indicando claramente cuáles son los casos base y cuál es
el paso recursivo. Luego, explicá por qué esta definición resulta recursiva.

:::
<!-- {exercise} -->

:::{solution} ej-def-mat-fibonacci
:class: dropdown
La sucesión de Fibonacci $F(n)$ para un entero $n \geq 0$ se define
matemáticamente como:

$$
F(n) = \begin{cases} 
0 & \text{si } n = 0 \text{ (Caso Base 1)} \\
1 & \text{si } n = 1 \text{ (Caso Base 2)} \\
F(n-1) + F(n-2) & \text{si } n > 1 \text{ (Paso Recursivo)}
\end{cases} 
$$

Esta definición es recursiva porque el valor de la función para un caso $n > 1$
se expresa en términos de la misma función evaluada en instancias menores ($n-1$
y $n-2$). Los dos casos base garantizan que el desglose de llamadas finalice y
retorne valores conocidos y definidos de manera directa.

:::
<!-- {solution} ej-def-mat-fibonacci -->

:::{exercise}
:label: ej-def-mat-multiplicacion
Definí matemáticamente de forma recursiva la multiplicación de dos números
enteros no negativos, $a$ y $b$, utilizando únicamente la suma aritmética y la
resta (decremento).

:::
<!-- {exercise} -->

:::{solution} ej-def-mat-multiplicacion
:class: dropdown
La multiplicación $a \times b$ se puede definir de manera recursiva acumulando
sumas del primer término $a$ y decrementando el segundo término $b$:

$$
a \times b = \begin{cases} 
0 & \text{si } b = 0 \text{ (Caso Base)} \\
a + a \times (b-1) & \text{si } b > 0 \text{ (Paso Recursivo)}
\end{cases} 
$$

En cada paso recursivo se acumula $a$ y se reduce el multiplicador $b$ en una
unidad, convergiendo linealmente hacia el caso base ($b = 0$).

:::
<!-- {solution} ej-def-mat-multiplicacion -->

:::{exercise}
:label: ej-def-mat-cantidad-digitos
Proponé una definición matemática recursiva para calcular la cantidad de dígitos
$D(n)$ de un número entero positivo $n$ en base 10 utilizando la función piso
($\lfloor x \rfloor$) para denotar la división entera.

:::
<!-- {exercise} -->

:::{solution} ej-def-mat-cantidad-digitos
:class: dropdown
La cantidad de dígitos $D(n)$ de un entero $n > 0$ se define de forma recursiva
como:

$$
D(n) = \begin{cases} 
1 & \text{si } n < 10 \text{ (Caso Base)} \\
1 + D(\lfloor n / 10 \rfloor) & \text{si } n \geq 10 \text{ (Paso Recursivo)}
\end{cases} 
$$

Cada paso recursivo realiza la división entera por 10 (eliminando el último
dígito del número) y suma 1 al contador acumulado, repitiendo el proceso hasta
que el número sea menor que 10, donde se alcanza el caso base.

:::
<!-- {solution} ej-def-mat-cantidad-digitos -->

### Construcción de Algoritmos en C

:::{exercise}
:label: ej-alg-c-potencia
Escribí una función recursiva en C para calcular la potencia de un número
($a^b$, con $b \geq 0$). Luego, implementá su equivalente versión iterativa
utilizando lazos de control (`while` o `for`).

:::
<!-- {exercise} -->

::::{solution} ej-alg-c-potencia
:class: dropdown
**Versión Recursiva:**

Aplica la regla de robustez {ref}`0x2001h` para validar precondiciones y el uso
de llaves:

:::{code-block} c
:linenos:
double potencia_recursiva(double a, int b)
{
    if (b < 0)
    {
        return -1.0;
    }
    // Caso Base
    if (b == 0)
    {
        return 1.0;
    }
    // Paso Recursivo
    return a * potencia_recursiva(a, b - 1);
}

:::
<!-- {code-block} c -->

**Versión Iterativa (con lazo for):**

:::{code-block} c
:linenos:
double potencia_iterativa(double a, int b)
{
    if (b < 0)
    {
        return -1.0;
    }
    double resultado = 1.0;
    for (int i = 0; i < b; i++)
    {
        resultado *= a;
    }
    return resultado;
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ej-alg-c-potencia -->

:::{exercise}
:label: ej-alg-c-conteo-caracteres
Escribí una función recursiva en C con la firma `size_t contar_caracter(const
char *cadena, char c)` que devuelva la cantidad de veces que el carácter `c`
aparece en la cadena dada.

:::
<!-- {exercise} -->

::::{solution} ej-alg-c-conteo-caracteres
:class: dropdown
Siguiendo las buenas prácticas, la cadena de entrada se declara como constante
(`const char *`) según la regla {ref}`0x3007h` y se retorna el tipo `size_t` de
acuerdo a la regla {ref}`0x3010h`:

:::{code-block} c
:linenos:
#include <stddef.h>
size_t contar_caracter(const char *cadena, char c)
{
    if (*cadena == '\0')
    {
        return 0;
    }
    size_t coincide = (*cadena == c) ? 1 : 0;
    return coincide + contar_caracter(cadena + 1, c);
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ej-alg-c-conteo-caracteres -->

:::{exercise}
:label: ej-alg-c-invertir-arreglo
Implementá una función recursiva en C que invierta los elementos de un arreglo
de enteros. La función debe modificar el arreglo original y tener la siguiente
firma: `void invertir_arreglo(int arr[], size_t ini, size_t fin)`.

:::
<!-- {exercise} -->

::::{solution} ej-alg-c-invertir-arreglo
:class: dropdown
Para cumplir con las directivas de tipo, los índices se manejan con `size_t`
(regla {ref}`0x3010h`):

:::{code-block} c
:linenos:
#include <stddef.h>
void invertir_arreglo(int arr[], size_t ini, size_t fin)
{
    if (ini >= fin)
    {
        return;
    }
    int aux = arr[ini];
    arr[ini] = arr[fin];
    arr[fin] = aux;
    invertir_arreglo(arr, ini + 1, fin - 1);
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ej-alg-c-invertir-arreglo -->

### Diagnóstico y Estabilidad

::::{exercise}
:label: ej-peligro-parada
Analizá la siguiente función recursiva en C y determiná por qué se produce un
error de desbordamiento de pila (*stack overflow*) para ciertos valores de
entrada enteros. ¿Cuál es el error en la condición de parada (caso base)?

:::{code-block} c
:linenos:
int sumar_hasta_cero(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumar_hasta_cero(n - 1);
}

:::
<!-- {code-block} c -->

::::
<!-- {exercise} -->

::::{solution} ej-peligro-parada
:class: dropdown
El error reside en que la condición de parada `if (n == 0)` solo se alcanza si
el argumento inicial `n` es un entero no negativo. Si la función se invoca con
un valor negativo (por ejemplo, `sumar_hasta_cero(-1)`), la llamada recursiva
realiza `n - 1`, decrementando el valor hacia $-\infty$ (`-2`, `-3`, `-4`,
etc.). Como nunca se cumple la condición `n == 0`, la función continúa apilando
marcos de pila en el *Call Stack* de forma infinita hasta agotar el límite
físico de memoria del stack, provocando un *stack overflow*.

Para resolver esta vulnerabilidad de parada, de acuerdo a la regla de robustez
{ref}`0x2001h`, la guarda del caso base debe generalizarse para cubrir todos los
números menores o iguales a cero:

:::{code-block} c
:linenos:
int sumar_hasta_cero_robusta(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return n + sumar_hasta_cero_robusta(n - 1);
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ej-peligro-parada -->

::::{exercise}
:label: ej-peligro-stackframe
Considerando la siguiente función recursiva en C:

:::{code-block} c
:linenos:
long int calcular_suma_recursiva(int n)
{
    long int variables_locales[4] = {0};
    if (n <= 0)
    {
        return 0;
    }
    variables_locales[0] = n;
    return variables_locales[0] + calcular_suma_recursiva(n - 1);
}

:::
<!-- {code-block} c -->

Estimá el tamaño mínimo teórico de su marco de pila (*stack frame*) en una
arquitectura típica de 64 bits (donde `sizeof(int) == 4` y `sizeof(long int) ==
8`), asumiendo que el compilador no realiza optimizaciones de llamada de cola.
Estimá la profundidad de recursión teórica y el número máximo de llamadas antes
de producir un desbordamiento físico de la pila (*stack overflow*) si el límite
de la pila del sistema operativo es de $8 \text{ MB}$.

::::
<!-- {exercise} -->

:::{solution} ej-peligro-stackframe
:class: dropdown
Para estimar el tamaño mínimo de un marco de pila en la arquitectura x86_64 bajo
el estándar de llamada System V AMD64 ABI, se analiza cada componente del
registro del marco:

1. **Dirección de Retorno:** Requiere 8 bytes para almacenar el puntero de
   instrucción del llamador.
2. **Puntero de Marco Anterior (Saved Frame Pointer):** Almacena el registro
   `rbp` previo, consumiendo 8 bytes.
3. **Variables Locales:** El arreglo `long int variables_locales[4]` ocupa $4
   \times 8 \text{ bytes} = 32 \text{ bytes}$.
4. **Parámetros de Entrada:** El argumento `int n` (4 bytes) inicialmente se
   transfiere vía registro (`edi`). Sin embargo, el compilador debe respaldarlo
   en la pila para preservar su valor a lo largo de las activaciones sucesivas.
   Por cuestiones de alineación en arquitectura de 64 bits, este campo consume 8
   bytes.

Sumando los componentes:
$$\text{Tamaño del marco} = 8\text{ B (retorno)} + 8\text{ B (frame pointer
anterior)} + 32\text{ B (variables locales)} + 8\text{ B (parámetro alineado)} =
56 \text{ bytes}$$

Bajo la convención x86_64 ABI, la pila debe estar alineada a límites de 16
bytes. Por lo tanto, el compilador redondea el tamaño de este marco a un
múltiplo de 16, resultando en un tamaño real de **64 bytes** por marco.

Para calcular el límite teórico de llamadas:
* El límite de la pila del sistema operativo es de $8 \text{ MB} = 8.388.608
  \text{ bytes}$.
* Número máximo de marcos permitidos:
  $$\text{Profundidad Máxima} = \frac{8.388.608 \text{ bytes}}{64 \text{
  bytes/marco}} = 131.072 \text{ llamadas}$$

:::
<!-- {solution} ej-peligro-stackframe -->

:::{exercise}
:label: ej-peligro-desbordamiento-aritmetico
Si implementás la función de Fibonacci recursiva tradicional en C usando el tipo
`unsigned long long`, determiná cuál es el menor valor de $n$ para el cual
ocurre un desbordamiento aritmético en la representación del tipo. Justificá si
el programa fallará por desbordamiento de pila (*stack overflow*) o por error de
representación antes. (Asumí un tipo `unsigned long long` de 8 bytes y una pila
del sistema de 8 MB).

:::
<!-- {exercise} -->

:::{solution} ej-peligro-desbordamiento-aritmetico
:class: dropdown
Un entero `unsigned long long` en C (64 bits) tiene un valor máximo
representable de $2^{64} - 1 \approx 1.84 \times 10^{19}$.

1. **Desbordamiento aritmético:** El número de Fibonacci $F(93) =
   12.200.160.415.121.876.738$ entra dentro del límite. Sin embargo, $F(94) =
   19.740.274.219.868.223.167 > 2^{64}-1$, por lo cual el desbordamiento
   aritmético ocurre en $n = 94$.
2. **Desbordamiento de pila (Stack Overflow):** La profundidad máxima de la pila
   para la versión de Fibonacci con recursión doble $F(n) = F(n-1) + F(n-2)$ es
   lineal respecto de $n$ (la profundidad máxima es $n$). Para $n = 94$, la pila
   albergará como máximo 94 marcos activos simultáneamente en la rama más
   profunda, consumiendo menos de $6 \text{ KB}$ de memoria, lo cual es
   despreciable.

Por lo tanto, la implementación de Fibonacci fallará primero debido a un
desbordamiento aritmético en $n = 94$ mucho antes de aproximarse a un *stack
overflow*.

:::
<!-- {solution} ej-peligro-desbordamiento-aritmetico -->

---

## Glosario

:::{glossary}

Recursión
: Técnica de programación y diseño algorítmico donde una función se define e
invoca en términos de sí misma.

Caso base
: Condición lógica terminal en un algoritmo recursivo que detiene la recursión y
retorna un resultado de forma directa sin realizar nuevas llamadas.

Paso recursivo
: Sentencia lógica en una función recursiva donde se realiza una nueva
invocación a la propia función sobre un subproblema de menor tamaño.

Stack Overflow
: Desbordamiento físico de la pila de llamadas del sistema provocado por el
consumo excesivo de memoria física asignada al stack.

Desbordamiento aritmético
: Situación física en la cual el resultado numérico de una operación excede los
límites representables por el tipo de dato físico de la variable.

:::
<!-- {glossary} -->

---

## Síntesis y Resumen

En este capítulo analizaste los principios de la recursión y su comportamiento
en memoria:
- **Estructuración recursiva**: Todo algoritmo recursivo requiere al menos de un
  caso base (para detener la ejecución) y un paso recursivo que reduzca el
  problema de forma convergente.
- **Funcionamiento en hardware**: Cada invocación apila un marco de pila (*stack
  frame*) con su propia copia de parámetros y variables locales automáticas en
  el *Call Stack*.
- **Riesgos y límites**: La recursión mal controlada o excesivamente profunda
  provoca fallas de segmentación (*stack overflow*). Sin embargo, en ciertos
  algoritmos el desbordamiento numérico del tipo de dato se alcanza mucho antes
  de saturar físicamente la pila.

---

## Referencias y Lecturas Complementarias

- Roberts, E. (2006). *Thinking Recursively in C*. Wiley.
- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).
  *Introduction to Algorithms* (3rd ed.). MIT Press. Chapter 4:
  Divide-and-Conquer.
- ISO/IEC 9899 Language Standard Section 6.5.2.2: Function calls.
