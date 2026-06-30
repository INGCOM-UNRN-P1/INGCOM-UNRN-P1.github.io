---
title: Recursividad y Divide y Vencerás en C
short_title: Recursividad
description: Una introducción a la recursividad, su definición matemática, construcción de algoritmos recursivos y el paradigma de divide y conquista con ejemplos prácticos.
---

La recursividad es una técnica de programación fundamental en la que una función se llama a sí misma para resolver un problema. Este enfoque se basa en la idea de descomponer un problema complejo en subproblemas más pequeños y de la misma naturaleza.

(definicion-matematica)=
## Definición Matemática

Desde una perspectiva matemática, una definición recursiva tiene dos partes esenciales:

1.  **Caso Base:** Es una o más condiciones terminales que no requieren de una nueva llamada a la función para ser resueltas. Es la solución explícita para el caso más simple del problema.
2.  **Paso Recursivo (o Relación de Recurrencia):** Es la regla que reduce el problema a una versión más simple de sí mismo. Define cómo se resuelve el problema para un caso `n` en términos de uno o más casos "menores" (por ejemplo, `n-1`).

Un ejemplo clásico es la función factorial, $n!$, que se define de la siguiente manera:

$$
n! = \begin{cases} 
1 & \text{si } n = 0 \text{ (Caso Base)} \\
n \times (n-1)! & \text{si } n > 0 \text{ (Paso Recursivo)}
\end{cases} 
$$

Esta definición establece que el factorial de 0 es 1 (caso base) y que el factorial de cualquier otro número natural `n` es `n` multiplicado por el factorial de `n-1`.

:::{exercise}
:label: ej-def-mat-fibonacci
Escribí la definición matemática formal (usando notación por casos) para la sucesión de Fibonacci, indicando claramente cuáles son los casos base y cuál es el paso recursivo. Luego, explicá por qué esta definición resulta recursiva.
:::

:::{solution} ej-def-mat-fibonacci
:class: dropdown
La sucesión de Fibonacci $F(n)$ para un entero $n \geq 0$ se define matemáticamente como:

$$
F(n) = \begin{cases} 
0 & \text{si } n = 0 \text{ (Caso Base 1)} \\
1 & \text{si } n = 1 \text{ (Caso Base 2)} \\
F(n-1) + F(n-2) & \text{si } n > 1 \text{ (Paso Recursivo)}
\end{cases} 
$$

Esta definición es recursiva porque el valor de la función para un caso $n > 1$ se expresa en términos de la misma función evaluada en instancias menores ($n-1$ y $n-2$). Los dos casos base garantizan que el desglose de llamadas finalice y retorne valores conocidos y definidos de manera directa.
:::

:::{exercise}
:label: ej-def-mat-multiplicacion
Definí matemáticamente de forma recursiva la multiplicación de dos números enteros no negativos, $a$ y $b$, utilizando únicamente la suma aritmética y la resta (decremento).
:::

:::{solution} ej-def-mat-multiplicacion
:class: dropdown
La multiplicación $a \times b$ se puede definir de manera recursiva acumulando sumas del primer término $a$ y decrementando el segundo término $b$:

$$
a \times b = \begin{cases} 
0 & \text{si } b = 0 \text{ (Caso Base)} \\
a + a \times (b-1) & \text{si } b > 0 \text{ (Paso Recursivo)}
\end{cases} 
$$

En cada paso recursivo se acumula $a$ y se reduce el multiplicador $b$ en una unidad, convergiendo linealmente hacia el caso base ($b = 0$).
:::

:::{exercise}
:label: ej-def-mat-cantidad-digitos
Proponé una definición matemática recursiva para calcular la cantidad de dígitos $D(n)$ de un número entero positivo $n$ en base 10 utilizando la función piso ($\lfloor x \rfloor$) para denotar la división entera.
:::

:::{solution} ej-def-mat-cantidad-digitos
:class: dropdown
La cantidad de dígitos $D(n)$ de un entero $n > 0$ se define de forma recursiva como:

$$
D(n) = \begin{cases} 
1 & \text{si } n < 10 \text{ (Caso Base)} \\
1 + D(\lfloor n / 10 \rfloor) & \text{si } n \geq 10 \text{ (Paso Recursivo)}
\end{cases} 
$$

Cada paso recursivo realiza la división entera por 10 (eliminando el último dígito del número) y suma 1 al contador acumulado, repitiendo el proceso hasta que el número sea menor que 10, donde se alcanza el caso base.
:::

(construccion-de-algoritmos-recursivos-en-c)=
## Construcción de Algoritmos Recursivos en C

Para implementar un algoritmo recursivo en C (o en cualquier otro lenguaje de programación), debés seguir la estructura de la definición matemática.

(componentes-clave)=
### Componentes Clave

Un algoritmo recursivo siempre debe tener:

*   **Caso Base:** Una estructura condicional (normalmente un `if`) que verifica si se ha alcanzado la condición de parada. Sin un caso base, la función se llamaría a sí misma infinitamente, resultando en un error de desbordamiento de pila (*stack overflow*).
*   **Paso Recursivo:** La parte del código donde la función se invoca a sí misma, pero con argumentos que la acercan progresivamente al caso base. Es crucial que cada llamada recursiva opere sobre un subproblema más pequeño.

(ejemplo-funcion-factorial-en-c)=
### Ejemplo: Función Factorial en C

Veamos cómo se traduce la definición matemática del factorial a una función en C.

```{code} c
:caption: Implementación recursiva de la función factorial
:label: factorial-c

#include <stdio.h>

// Declaración de la función factorial
long int factorial(int n);

int main() {
    int numero = 5;
    long int resultado = factorial(numero);
    if (resultado == -1) {
        printf("Error: no se puede calcular el factorial de un número negativo.\n");
    } else {
        printf("El factorial de %d es %ld\n", numero, resultado);
    }
    return 0;
}

// Definición de la función recursiva
long int factorial(int n) {
    // Validación de precondición (robustez ante valores inválidos, regla {ref}`0x2001h`)
    if (n < 0) {
        return -1;
    }
    // Caso Base: si n es 0, el factorial es 1.
    if (n == 0) {
        return 1;
    } 
    // Paso Recursivo: n * factorial(n-1)
    return n * factorial(n - 1);
}
```

#### Análisis del Código

1.  **Caso Base:** La línea `if (n == 0)` comprueba la condición de parada. Si `n` es 0, la función retorna `1` y la cadena de llamadas recursivas comienza a resolverse.
2.  **Paso Recursivo:** En la última sentencia, la función retorna el resultado de `n` multiplicado por el valor devuelto por la llamada a `factorial(n - 1)`. Esta llamada opera sobre un subproblema de menor tamaño (`n-1`), garantizando la convergencia hacia el caso base.

::: {important} Pila de llamadas (Call Stack) y Anatomía del Stack Frame
Cada vez que un programa invoca una función, se reserva un espacio de memoria física en la pila del sistema (*call stack*) denominado **marco de pila** o *stack frame*. En una arquitectura moderna típica (como x86_64 bajo la convención de llamadas System V AMD64 ABI), un marco de pila contiene los siguientes elementos esenciales:

1. **Dirección de Retorno:** La dirección de la instrucción en la función llamadora a la que debe retornar el control del flujo del procesador una vez que finalice la ejecución de la función actual.
2. **Parámetros de Entrada:** Los argumentos provistos a la función. Si bien la convención System V ABI los transfiere inicialmente en registros (como `rdi`, `rsi`, `rdx`), el compilador suele respaldarlos en la pila si su dirección es requerida o si se realizan llamadas sucesivas.
3. **Puntero de Marco Anterior (Saved Frame Pointer):** La dirección de base (`rbp`) del marco de la función que la invocó. Esto permite restaurar el contexto de registros del llamador al concluir la función actual.
4. **Variables Locales:** Espacio reservado para almacenar los datos definidos internamente en la función durante su ciclo de vida.

En la recursividad, cada llamada consecutiva apila un nuevo marco. Estos marcos se acumulan hasta alcanzar el caso base, punto en el cual se inicia la fase de resolución y retorno ("desapilado") en orden inverso al de la llamada (LIFO: *Last In, First Out*).

Para un análisis detallado sobre el manejo de memoria en el stack y su relación con el ciclo de vida de variables locales, podés consultar {ref}`memoria-stack`.
:::

A continuación se muestra de forma gráfica el estado del *Call Stack* durante el cálculo recursivo de `factorial(3)` hasta alcanzar el caso base, y cómo se desapilan los marcos de pila para resolver la multiplicación:

```{figure} 12/pila_llamadas.svg
:label: fig-pila-llamadas
:align: center
:width: 85%

Evolución del Call Stack en la ejecución recursiva de `factorial(3)`. Los marcos se apilan secuencialmente hasta el caso base y se desapilan propagando el resultado.
```

:::{exercise}
:label: ej-alg-c-potencia
Escribí una función recursiva en C para calcular la potencia de un número ($a^b$, con $b \geq 0$). Luego, implementá su equivalente versión iterativa utilizando lazos de control (`while` o `for`).
:::

:::{solution} ej-alg-c-potencia
:class: dropdown
**Versión Recursiva:**

Aplica la regla de robustez {ref}`0x2001h` para validar precondiciones y el uso obligatorio de llaves {ref}`0x1001h`:

```c
double potencia_recursiva(double a, int b) {
    // Guarda de robustez ante exponentes negativos
    if (b < 0) {
        return -1.0; 
    }
    // Caso Base
    if (b == 0) {
        return 1.0;
    }
    // Paso Recursivo
    return a * potencia_recursiva(a, b - 1);
}
```

**Versión Iterativa (con lazo for):**

```c
double potencia_iterativa(double a, int b) {
    if (b < 0) {
        return -1.0;
    }
    double resultado = 1.0;
    for (int i = 0; i < b; i++) {
        resultado *= a;
    }
    return resultado;
}
```
:::

:::{exercise}
:label: ej-alg-c-conteo-caracteres
Escribí una función recursiva en C con la firma `size_t contar_caracter(const char *cadena, char c)` que devuelva la cantidad de veces que el carácter `c` aparece en la cadena dada.
:::

:::{solution} ej-alg-c-conteo-caracteres
:class: dropdown
Siguiendo las buenas prácticas, la cadena de entrada se declara como constante (`const char *`) según la regla {ref}`0x3007h` y se retorna el tipo `size_t` de acuerdo a la regla {ref}`0x3010h`:

```c
#include <stddef.h>

size_t contar_caracter(const char *cadena, char c) {
    // Caso Base: alcanzamos el fin de la cadena (carácter nulo)
    if (*cadena == '\0') {
        return 0;
    }
    
    // Paso Recursivo: evalúa el carácter actual y procesa el resto
    size_t coincide = (*cadena == c) ? 1 : 0;
    return coincide + contar_caracter(cadena + 1, c);
}
```
:::

:::{exercise}
:label: ej-alg-c-invertir-arreglo
Implementá una función recursiva en C que invierta los elementos de un arreglo de enteros. La función debe modificar el arreglo original y tener la siguiente firma: `void invertir_arreglo(int arr[], size_t ini, size_t fin)`.
:::

:::{solution} ej-alg-c-invertir-arreglo
:class: dropdown
Para cumplir con las directivas de tipo, los índices se manejan con `size_t` (regla {ref}`0x3010h`):

```c
#include <stddef.h>

void invertir_arreglo(int arr[], size_t ini, size_t fin) {
    // Caso Base: cuando los índices se cruzan o son iguales
    if (ini >= fin) {
        return;
    }
    
    // Paso Recursivo: intercambiar extremos y achicar el rango
    int aux = arr[ini];
    arr[ini] = arr[fin];
    arr[fin] = aux;
    
    // Llamada recursiva con el subrango interno
    invertir_arreglo(arr, ini + 1, fin - 1);
}
```
:::

(el-peligro-de-la-recursividad-stack-overflow-y-la-paradoja-del-factorial)=
## El Peligro de la Recursividad: Stack Overflow y la Paradoja del Factorial

El tamaño total disponible para la pila de llamadas (*call stack*) es finito, preconfigurado por el sistema operativo o el entorno de ejecución (típicamente entre 1 y 8 megabytes en sistemas Unix/Linux). Si el consumo de pila excede dicho límite físico, se produce un desbordamiento catastrófico de pila o **stack overflow**, lo cual interrumpe inmediatamente el programa con un fallo de segmentación (*segmentation fault*).

Las causas principales de este fallo son:
1. **Ausencia o fallo en el Caso Base (Recursión Infinita):** Si la condición de parada no se cumple o los parámetros no convergen al caso base.
2. **Recursión Demasiado Profunda:** Aún si el algoritmo es lógicamente correcto, si la profundidad de llamadas es excesiva, la pila se agotará.

(la-paradoja-del-factorial-limites-del-tipo-de-dato-vs-limites-de-la-pila)=
### La Paradoja del Factorial: Límites del Tipo de Dato vs. Límites de la Pila

:::{note} Contraste Cuantitativo
El factorial es el ejemplo introductorio por excelencia de la recursividad, pero presenta una severa deficiencia didáctica si se analiza con rigor de ingeniería de software.

En sistemas de 64 bits modernos (con arquitectura LP64), un entero de tipo `long int` de C ocupa 8 bytes, permitiendo almacenar valores en el rango:

$$-2^{63} \leq \text{long int} \leq 2^{63} - 1 \quad (\approx 9.22 \times 10^{18})$$

* El factorial de 20 es $20! \approx 2.43 \times 10^{18}$ (entra dentro de los límites del tipo).
* El factorial de 21 es $21! \approx 5.10 \times 10^{19}$ (supera la capacidad máxima del tipo `long int` y produce un **desbordamiento aritmético**).

Por lo tanto, la implementación de `factorial(n)` recursiva en C fallará y devolverá valores matemáticamente erróneos para $n \geq 21$. Sin embargo, para provocar un *stack overflow* físico en una pila de 8 MB con marcos de 32 bytes, se requerirían aproximadamente:

$$\frac{8 \times 10^6 \text{ bytes}}{32 \text{ bytes/marco}} \approx 250.000 \text{ llamadas recursivas}$$

Esto significa que **el desbordamiento aritmético ocurre en $n=21$, mucho antes de comprometer la estabilidad física del stack**. El estudiante no ve el límite del stack en este ejemplo clásico, sino el límite físico de almacenamiento del tipo de dato binario.
:::

:::{exercise}
:label: ej-peligro-parada
Analizá la siguiente función recursiva en C y determiná por qué se produce un error de desbordamiento de pila (*stack overflow*) para ciertos valores de entrada enteros. ¿Cuál es el error en la condición de parada (caso base)?

```c
int sumar_hasta_cero(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumar_hasta_cero(n - 1);
}
```
:::

:::{solution} ej-peligro-parada
:class: dropdown
El error reside en que la condición de parada `if (n == 0)` solo se alcanza si el argumento inicial `n` es un entero no negativo. Si la función se invoca con un valor negativo (por ejemplo, `sumar_hasta_cero(-1)`), la llamada recursiva realiza `n - 1`, decrementando el valor hacia $-\infty$ (`-2`, `-3`, `-4`, etc.). Como nunca se cumple la condición `n == 0`, la función continúa apilando marcos de pila en el *Call Stack* de forma infinita hasta agotar el límite físico de memoria del stack, provocando un *stack overflow*.

Para resolver esta vulnerabilidad de parada, de acuerdo a la regla de robustez {ref}`0x2001h`, la guarda del caso base debe generalizarse para cubrir todos los números menores o iguales a cero:

```c
int sumar_hasta_cero_robusta(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumar_hasta_cero_robusta(n - 1);
}
```
:::

:::{exercise}
:label: ej-peligro-stackframe
Considerando la siguiente función recursiva en C:

```c
long int calcular_suma_recursiva(int n) {
    long int variables_locales[4] = {0};
    if (n <= 0) {
        return 0;
    }
    variables_locales[0] = n;
    return variables_locales[0] + calcular_suma_recursiva(n - 1);
}
```

Estimá el tamaño mínimo teórico de su marco de pila (*stack frame*) en una arquitectura típica de 64 bits (x86_64, donde `sizeof(int) == 4` y `sizeof(long int) == 8`), asumiendo que el compilador no realiza optimizaciones de llamada de cola. Estimá la profundidad de recursión teórica y el número máximo de llamadas antes de producir un desbordamiento físico de la pila (*stack overflow*) si el límite de la pila del sistema operativo es de $8 \text{ MB}$.
:::

:::{solution} ej-peligro-stackframe
:class: dropdown
Para estimar el tamaño mínimo de un marco de pila en la arquitectura x86_64 bajo el estándar de llamada System V AMD64 ABI, se analiza cada componente del registro del marco:

1. **Dirección de Retorno:** Requiere 8 bytes para almacenar el puntero de instrucción del llamador.
2. **Puntero de Marco Anterior (Saved Frame Pointer):** Almacena el registro `rbp` previo, consumiendo 8 bytes.
3. **Variables Locales:** El arreglo `long int variables_locales[4]` ocupa $4 \times 8 \text{ bytes} = 32 \text{ bytes}$.
4. **Parámetros de Entrada:** El argumento `int n` (4 bytes) inicialmente se transfiere vía registro (`edi`). Sin embargo, al realizarse la llamada recursiva, el compilador debe respaldarlo en la pila para preservar su valor a lo largo de las activaciones sucesivas. Por cuestiones de alineación en arquitectura de 64 bits, este campo consume 8 bytes.

Sumando los componentes:
$$\text{Tamaño del marco} = 8\text{ B (retorno)} + 8\text{ B (frame pointer anterior)} + 32\text{ B (variables locales)} + 8\text{ B (parámetro alineado)} = 56 \text{ bytes}$$

Bajo la convención x86_64 ABI, la pila debe estar alineada a límites de 16 bytes antes de cualquier llamada a función. Por lo tanto, el compilador redondea el tamaño de este marco a un múltiplo de 16, resultando en un tamaño real de **64 bytes** por marco.

Para calcular el límite teórico de llamadas:
* El límite del stack del sistema operativo es de $8 \text{ MB} = 8 \times 1024 \times 1024 \text{ bytes} = 8.388.608 \text{ bytes}$.
* Número máximo de marcos permitidos:
  $$\text{Profundidad Máxima} = \frac{8.388.608 \text{ bytes}}{64 \text{ bytes/marco}} = 131.072 \text{ llamadas}$$

Este ejercicio ilustra cuantitativamente las restricciones del stack frente al heap y refuerza por qué es imperativo acotar o evitar la recursividad lineal para problemas con grandes volúmenes de datos.
:::

:::{exercise}
:label: ej-peligro-desbordamiento-aritmetico
Si implementás la función de Fibonacci recursiva tradicional en C usando el tipo `unsigned long long`, determiná cuál es el menor valor de $n$ para el cual ocurre un desbordamiento aritmético en la representación del tipo. Justificá si el programa fallará por desbordamiento de pila (*stack overflow*) o por error de representación antes. (Asumí un tipo `unsigned long long` de 8 bytes y una pila del sistema de 8 MB).
:::

:::{solution} ej-peligro-desbordamiento-aritmetico
:class: dropdown
Un entero `unsigned long long` en C (64 bits) tiene un valor máximo representable de $2^{64} - 1 \approx 1.84 \times 10^{19}$.

1. **Desbordamiento aritmético:** El número de Fibonacci $F(93) = 12.200.160.415.121.876.738$ entra dentro del límite. Sin embargo, $F(94) = 19.740.274.219.868.223.167 > 2^{64}-1$, por lo cual el desbordamiento aritmético ocurre en $n = 94$.
2. **Desbordamiento de pila (Stack Overflow):** La profundidad máxima de la pila para la versión de Fibonacci con recursión doble $F(n) = F(n-1) + F(n-2)$ es lineal respecto de $n$ (la profundidad máxima es $n$). Para $n = 94$, la pila albergará como máximo 94 marcos de pila activos simultáneamente en la rama más profunda. Un marco de pila típico es de unos 32 a 64 bytes, por lo que 94 llamadas consumen menos de $6 \text{ KB}$ de memoria, una fracción ínfima de los 8 MB de la pila del sistema.

Por lo tanto, la implementación de Fibonacci fallará primero debido a un desbordamiento aritmético en $n = 94$ mucho antes de aproximarse a un *stack overflow*.
:::

(recursion-de-cola-tail-recursion-y-optimizacion-tco)=
## Recursión de Cola (Tail Recursion) y Optimización TCO

Una llamada recursiva se considera **recursiva de cola** (*tail recursive*) si la llamada a sí misma es la última instrucción ejecutada por la función antes de retornar, y su resultado se devuelve directamente sin realizar ninguna operación aritmética o lógica adicional.

Por ejemplo, la función `factorial` tradicional expuesta arriba **no** es recursiva de cola porque, tras el retorno de `factorial(n - 1)`, la función debe realizar la multiplicación por `n`.

Podemos reescribir la función factorial para que sea recursiva de cola utilizando un acumulador:

```c
long int factorial_tail_rec(int n, long int acumulador) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return acumulador;
    }
    // La llamada recursiva es la última operación física.
    return factorial_tail_rec(n - 1, n * acumulador);
}
```

(optimizacion-por-parte-del-compilador-tco)=
### Optimización por parte del compilador (TCO)

Cuando una llamada es recursiva de cola, los compiladores modernos pueden aplicar una optimización llamada **Tail Call Optimization (TCO)**. En lugar de empujar un nuevo marco de pila al *call stack*, el compilador sobrescribe el marco de pila de la función actual y reutiliza sus registros y variables locales, transformando efectivamente la recursión en un salto incondicional (equivalente a un lazo de control). Esto reduce la complejidad espacial auxiliar del algoritmo de $O(n)$ a $O(1)$.

:::{warning} Falta de Garantías en C
El estándar ISO/IEC 9899 (C estándar) **no** garantiza ni exige la optimización TCO. Su aplicación depende exclusivamente del compilador y el nivel de optimización configurado (como `-O2` o `-O3` en GCC o Clang). Confiar en TCO para la estabilidad y robustez de un software crítico en C de producción constituye un antipatrón. Si se requiere un consumo constante de memoria, se debe implementar una versión puramente iterativa utilizando lazos.
:::

:::{warning} Recursión vs. Iteración
Para tareas lineales simples (como recorrer una lista, buscar un elemento o sumar valores de forma consecutiva), la iteración mediante **lazos de control** (`for` o `while`) es infinitamente más segura y eficiente. Los lazos no consumen marcos de pila adicionales por cada repetición. Por lo tanto, reservá la recursividad para estructuras de datos intrínsecamente jerárquicas o ramificadas (como árboles y grafos) o algoritmos basados en *Divide y Vencerás* con profundidad de pila acotada (usualmente $O(\log n)$).
:::

A continuación se presenta una tabla comparativa sobre el uso de recursos entre ambas aproximaciones:

:::{table} Comparación de recursos: Iteración vs. Recursividad
:label: tbl-iter-vs-recur

| Aspecto | Iteración (Lazos) | Recursividad |
| :--- | :--- | :--- |
| **Uso de Memoria en el Stack** | $O(1)$ constante. El mismo marco de pila se reutiliza durante todo el lazo. | $O(d)$ donde $d$ es la profundidad máxima de llamadas (salvo TCO exitoso). |
| **Rendimiento** | Más rápido. Evita la sobrecarga de llamadas y retornos de función. | Más lento por la constante asignación y liberación de marcos de pila. |
| **Límite de Ejecución** | Limitado solo por el tiempo de procesamiento o valores numéricos. | Físicamente limitado por el tamaño máximo del *stack* del sistema. |
:::

:::{exercise}
:label: ej-cola-suma-arreglo
Escribí una función recursiva de cola en C para sumar los elementos de un arreglo de enteros. La función debe recibir un acumulador para permitir la optimización TCO y tener la firma `int sumar_arreglo_cola(const int arr[], size_t size, int acumulador)`.
:::

:::{solution} ej-cola-suma-arreglo
:class: dropdown
Siguiendo las reglas de estilo de la cátedra, el arreglo se declara como `const` ({ref}`0x3007h`) y el tamaño `size` utiliza el tipo `size_t` ({ref}`0x3010h`):

```c
#include <stddef.h>

int sumar_arreglo_cola(const int arr[], size_t size, int acumulador) {
    // Caso Base: no quedan elementos por procesar
    if (size == 0) {
        return acumulador;
    }
    
    // Paso Recursivo de cola: sumamos el primer elemento al acumulador,
    // desplazamos el puntero del arreglo y decrementamos el tamaño
    return sumar_arreglo_cola(arr + 1, size - 1, acumulador + arr[0]);
}
```

Dado que la llamada recursiva es la última instrucción ejecutada y su valor de retorno no se ve afectado por operaciones aritméticas pendientes, los compiladores modernos pueden reutilizar el mismo marco de pila (TCO) reduciendo el uso de stack de $O(n)$ a $O(1)$.
:::

:::{exercise}
:label: ej-cola-fibonacci
La función de Fibonacci recursiva estándar tiene una complejidad temporal exponencial de $O(2^n)$ y no es de cola. Diseñá una versión recursiva de cola en C utilizando acumuladores para lograr una complejidad temporal lineal de $O(n)$ y espacial de $O(1)$ con TCO. La firma sugerida es: `unsigned long fibonacci_cola(size_t n, unsigned long a, unsigned long b)`.
:::

:::{solution} ej-cola-fibonacci
:class: dropdown
Para resolver este ejercicio con recursión de cola, los acumuladores `a` y `b` representarán los dos números consecutivos de Fibonacci $F(i)$ y $F(i+1)$ en cada llamada:

```c
#include <stddef.h>

// Para calcular F(n), la función debe invocarse inicialmente como:
// fibonacci_cola(n, 0, 1)
unsigned long fibonacci_cola(size_t n, unsigned long a, unsigned long b) {
    // Caso Base 1: n == 0 retorna el primer acumulador
    if (n == 0) {
        return a;
    }
    // Caso Base 2: n == 1 retorna el segundo acumulador
    if (n == 1) {
        return b;
    }
    // Paso recursivo de cola: decrementamos n, el acumulador 'a' pasa a ser 'b'
    // y el acumulador 'b' toma el valor de la suma acumulada 'a + b'
    return fibonacci_cola(n - 1, b, a + b);
}
```

Al ser recursiva de cola pura y estar libre de operaciones pendientes tras la invocación recursiva, el compilador puede optimizar esta función reemplazando el marco en pila, logrando un espacio constante de pila.
:::

:::{exercise}
:label: ej-cola-conteo-digitos
Transformá la definición recursiva estándar para contar dígitos de un número entero positivo (vista en el ejercicio {ref}`ej-def-mat-cantidad-digitos`) a una función con recursión de cola en C.
:::

:::{solution} ej-cola-conteo-digitos
:class: dropdown
Para estructurar la recursión de cola, implementamos un acumulador que registre la cantidad de dígitos procesados en cada paso recursivo:

```c
#include <stddef.h>

// La función envolvente debe invocarla inicialmente con acumulador = 0
size_t contar_digitos_cola(unsigned long n, size_t acumulador) {
    // Caso Base: si el número es menor a 10, sumamos el último dígito y retornamos
    if (n < 10) {
        return acumulador + 1;
    }
    
    // Paso Recursivo de cola: dividimos el número y sumamos 1 al acumulador
    return contar_digitos_cola(n / 10, acumulador + 1);
}
```
:::

(paradigma-de-divide-y-venceras)=
## Paradigma de Divide y Vencerás

El paradigma de "Divide y Conquista" (Divide and Conquer) es una potente estrategia para el diseño de algoritmos que consiste en resolver un problema complejo descomponiéndolo en subproblemas más pequeños y manejables. Este paradigma aplica naturalmente la recursividad para su implementación. El proceso se puede resumir en tres fases principales:

1.  **Dividir:** Se descompone el problema principal en un número de subproblemas que son instancias más pequeñas del mismo problema.
2.  **Conquistar:** Se resuelven los subproblemas de forma recursiva. Si un subproblema es lo suficientemente pequeño (caso base), se resuelve de manera directa.
3.  **Combinar:** Se combinan las soluciones de los subproblemas para construir la solución del problema original.

Este flujo de trabajo de divide y vencerás se puede visualizar de manera gráfica en el algoritmo de ordenamiento Merge Sort:

```{figure} 12/divide_conquista_merge.svg
:label: fig-divide-conquista
:align: center
:width: 85%

Paradigma de Divide y Vencerás aplicado a la ordenación del arreglo [12, 11, 13, 5] mediante Merge Sort.
```

(ejemplo-1-busqueda-binaria)=
### Ejemplo 1: Búsqueda Binaria

La búsqueda binaria es un algoritmo altamente eficiente para localizar un elemento dentro de un **arreglo ordenado**. Se basa en el paradigma de divide y conquista.

Sin embargo, a menudo se enseña implementado mediante recursividad, lo cual es ineficiente desde la perspectiva del uso de memoria en sistemas reales.

* **Fase de División:** Se compara el elemento buscado con el valor central del subarreglo. El espacio de búsqueda se reduce a la mitad.
* **Fase de Conquista:** Si hay coincidencia, se retorna la posición. De lo contrario, se realiza una llamada recursiva sobre el subarreglo izquierdo o derecho. El caso base ocurre cuando el subarreglo está vacío (índices cruzados).
* **Fase de Combinación:** Es trivial, ya que el resultado encontrado se propaga directamente hacia arriba en la pila.

#### Justificación del Consumo de Pila y Complejidad Espacial

En la versión recursiva, cada paso de división genera un nuevo marco de pila. Como el espacio se reduce a la mitad en cada paso, la profundidad máxima de la pila es de $O(\log n)$. Por ende, consume un espacio auxiliar de $O(\log n)$ marcos de pila en el stack del sistema.

En contraste, la versión iterativa clásica resuelve el mismo problema utilizando un único lazo de control `while` y variables locales reescritas, requiriendo un espacio espacial auxiliar de $O(1)$ (constante) de manera óptima, lo que elimina cualquier riesgo de *stack overflow*.

#### Implementaciones en C

Para cumplir con la regla de uso de variables de tipo `size_t` en índices y tamaños (regla {ref}`0x3010h`), debemos prever y evitar el desbordamiento por decremento bajo cero (ya que `size_t` es un tipo de dato sin signo). Además, declaramos el arreglo de entrada como `const` dado que la función no modifica sus elementos (regla {ref}`0x3007h`).

```{code} c
:caption: Búsqueda Binaria recursiva e iterativa en C
:label: binary-search-c

#include <stdio.h>
#include <stddef.h>

// Búsqueda binaria recursiva
// Retorna 1 si x está presente en arr[l..r] e inyecta la posición en *indice_encontrado.
// Retorna 0 de lo contrario.
int buscar_binario_recursivo(const int arr[], size_t l, size_t r, int x, size_t *indice_encontrado) {
    if (l <= r) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            *indice_encontrado = mid;
            return 1;
        }

        if (arr[mid] > x) {
            // Guarda para evitar desbordamiento inferior de size_t al restar 1
            if (mid > 0) {
                return buscar_binario_recursivo(arr, l, mid - 1, x, indice_encontrado);
            }
        } else {
            return buscar_binario_recursivo(arr, mid + 1, r, x, indice_encontrado);
        }
    }
    return 0; // Caso base: no encontrado
}

// Búsqueda binaria iterativa (espacio O(1) óptimo)
int buscar_binario_iterativo(const int arr[], size_t size, int x, size_t *indice_encontrado) {
    if (size == 0) {
        return 0;
    }
    size_t l = 0;
    size_t r = size - 1;

    while (l <= r) {
        size_t mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            *indice_encontrado = mid;
            return 1;
        }

        if (arr[mid] > x) {
            if (mid == 0) {
                break; // Evita el desbordamiento inferior de size_t al decrementar
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    size_t posicion = 0;

    printf("Probando búsqueda binaria iterativa:\n");
    if (buscar_binario_iterativo(arr, n, x, &posicion) == 1) {
        printf("Elemento %d encontrado en el índice %zu\n", x, posicion);
    } else {
        printf("Elemento %d no está presente en el arreglo\n", x);
    }

    if (buscar_binario_recursivo(arr, 0, n - 1, x, &posicion) == 1) {
        printf("Elemento %d encontrado en el índice %zu\n", x, posicion);
    } else {
        printf("Elemento %d no está presente en el arreglo\n", x);
    }

    return 0;
}
```

(ejemplo-2-ordenamiento-por-fusion-merge-sort)=
### Ejemplo 2: Ordenamiento por Fusión (Merge Sort)

Merge Sort representa una aplicación más compleja del paradigma de divide y vencerás que involucra recursión múltiple (dos llamadas recursivas) y una fase de combinación no trivial (la fusión de arreglos ordenados).

* **Dividir:** Se divide el arreglo de $n$ elementos en dos subarreglos de tamaño $n/2$ cada uno.
* **Conquistar:** Se ordena cada subarreglo de forma recursiva. El caso base es un arreglo de longitud menor o igual a 1, que ya se encuentra ordenado.
* **Combinar:** Se fusionan (*merge*) los dos subarreglos ya ordenados para producir el arreglo final ordenado.

Este flujo no lineal de llamadas se puede visualizar detalladamente en la siguiente traza de ejecución:

```{figure} 12/traza_merge_sort.svg
:label: fig-traza-merge-sort
:align: center
:width: 85%

Árbol de llamadas recursivas y secuencia de fusión para Merge Sort con el arreglo inicial [5, 2, 7, 3]. Los números en los círculos indican el orden cronológico de ejecución (DFS).
```

#### Deficiencia del malloc en recursión profunda y optimización de buffer único

:::{important} Evitar Reservas Dinámicas Repetitivas
Una implementación ingenua de Merge Sort reserva memoria dinámica mediante `malloc` dentro de la función `merge` en cada nivel de recursión para crear subarreglos temporales. Esto es una pésima práctica de ingeniería de software. 

Realizar `malloc` y `free` repetidamente en un algoritmo recursivo introduce una enorme sobrecarga debido a las llamadas al sistema (*system calls*) para interactuar con el administrador de memoria del sistema operativo, fragmentando además el heap.

La forma correcta y óptima de resolver esto es preasignar un **único arreglo auxiliar** de tamaño $n$ en la función envolvente (wrapper) y propagarlo mediante punteros a lo largo de las sucesivas llamadas recursivas, eliminando cualquier reserva de memoria intermedia.
:::

#### Implementación Optimizada en C

A continuación se expone la implementación correcta de Merge Sort. En concordancia con las reglas de estilo de la cátedra, todos los bloques y estructuras de control emplean llaves obligatoriamente (regla {ref}`0x1001h`) y los tamaños e índices se definen utilizando el tipo `size_t` (regla {ref}`0x3010h`).

```{code} c
:caption: Implementación optimizada de Merge Sort con búfer temporal único en C
:label: merge-sort-c

#include <stdio.h>
#include <stdlib.h>

// Combina dos mitades ordenadas arr[l..m] y arr[m+1..r] utilizando el búfer auxiliar único aux[]
void fusionar(int arr[], size_t l, size_t m, size_t r, int aux[]) {
    size_t i = l;
    size_t j = m + 1;
    size_t k = l;

    // Copiar el rango relevante al arreglo auxiliar
    for (size_t idx = l; idx <= r; idx++) {
        aux[idx] = arr[idx];
    }

    // Fusionar de aux[] a arr[]
    while ((i <= m) && (j <= r)) {
        if (aux[i] <= aux[j]) {
            arr[k] = aux[i];
            i++;
        } else {
            arr[k] = aux[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de la mitad izquierda (si quedan)
    while (i <= m) {
        arr[k] = aux[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de la mitad derecha (si quedan)
    while (j <= r) {
        arr[k] = aux[j];
        j++;
        k++;
    }
}

// Función recursiva interna
void merge_sort_recursivo(int arr[], size_t l, size_t r, int aux[]) {
    if (l < r) {
        size_t m = l + (r - l) / 2;

        merge_sort_recursivo(arr, l, m, aux);
        merge_sort_recursivo(arr, m + 1, r, aux);
        fusionar(arr, l, m, r, aux);
    }
}

// Función envolvente que preasigna el búfer auxiliar único
int ordenar_merge_sort(int arr[], size_t size) {
    if (size <= 1) {
        return 0; // Ya ordenado
    }

    // Reservar un único búfer auxiliar, utilizando sizeof(*aux) según buena práctica
    int *aux = (int*) malloc(size * sizeof(*aux));

    // Validar asignación de memoria dinámica (regla {ref}`0x3001h`)
    if (aux == NULL) {
        return -1;
    }

    merge_sort_recursivo(arr, 0, size - 1, aux);

    free(aux);
    return 0;
}

void imprimir_arreglo(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6, 7};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: \n");
    imprimir_arreglo(arr, arr_size);

    if (ordenar_merge_sort(arr, arr_size) == 0) {
        printf("\nArreglo ordenado: \n");
        imprimir_arreglo(arr, arr_size);
    } else {
        printf("\nError al ordenar: fallo en asignación de memoria.\n");
    }

    return 0;
}
```

:::{warning} Validación de Memoria Dinámica
En C, toda asignación dinámica mediante `malloc` o `calloc` puede fallar si el sistema no dispone de suficiente memoria. Para asegurar la robustez del programa, es obligatorio verificar que los punteros obtenidos no sean `NULL` antes de utilizarlos (regla {ref}`0x3001h`). No realizar esta validación induce a desreferenciación de punteros nulos y comportamiento indefinido.
:::

:::{note} Complejidad
La relación de recurrencia para Merge Sort es $T(n) = 2T(n/2) + O(n)$. Esto se resuelve a una complejidad temporal de $O(n \log n)$, que es muy eficiente. Para un análisis matemático de cómo se resuelve esta recurrencia, consultá la sección de [Teorema Maestro](14_complejidad).
:::

:::{exercise}
:label: ej-divide-maximo
Escribí una función recursiva en C que encuentre el elemento máximo de un arreglo de enteros utilizando el paradigma de Divide y Vencerás (dividiendo el arreglo en dos mitades, buscando el máximo de cada una y luego comparándolos). La firma debe ser `int maximo_divide_y_venceras(const int arr[], size_t ini, size_t fin)`.
:::

:::{solution} ej-divide-maximo
:class: dropdown
De acuerdo a las reglas de estilo, el arreglo es `const` ({ref}`0x3007h`) y los índices son de tipo `size_t` ({ref}`0x3010h`):

```c
#include <stddef.h>

int maximo_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    // Caso Base: un único elemento en el rango
    if (ini == fin) {
        return arr[ini];
    }
    
    // Dividir el rango a la mitad
    size_t mid = ini + (fin - ini) / 2;
    
    // Conquistar: obtener recursivamente el máximo de cada mitad
    int max_izq = maximo_divide_y_venceras(arr, ini, mid);
    int max_der = maximo_divide_y_venceras(arr, mid + 1, fin);
    
    // Combinar: retornar el mayor de ambos
    if (max_izq > max_der) {
        return max_izq;
    } else {
        return max_der;
    }
}
```

La profundidad máxima de la pila de llamadas es logarítmica, de orden $O(\log n)$, lo cual minimiza el riesgo de un desbordamiento de pila en comparación con la recursión lineal.
:::

:::{exercise}
:label: ej-divide-suma
Implementá una función en C para sumar todos los elementos de un arreglo de enteros utilizando el paradigma de Divide y Vencerás. ¿Cuál es la profundidad máxima de la pila de llamadas para un arreglo de tamaño $n$?
:::

:::{solution} ej-divide-suma
:class: dropdown
El algoritmo divide el arreglo en dos mitades hasta llegar a elementos individuales, para luego sumar las respuestas parciales:

```c
#include <stddef.h>

long int sumar_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    // Caso Base: un solo elemento en el rango
    if (ini == fin) {
        return arr[ini];
    }
    
    // Dividir
    size_t mid = ini + (fin - ini) / 2;
    
    // Conquistar y Combinar
    return sumar_divide_y_venceras(arr, ini, mid) + 
           sumar_divide_y_venceras(arr, mid + 1, fin);
}
```

La profundidad máxima del *call stack* es $O(\log n)$ debido a la división binaria del espacio de búsqueda en cada paso.
:::

:::{exercise}
:label: ej-divide-conteo-pares
Diseñá una función en C que determine la cantidad de números pares en un arreglo de enteros utilizando el paradigma de Divide y Vencerás.
:::

:::{solution} ej-divide-conteo-pares
:class: dropdown
La función evalúa los elementos individuales en las hojas de la recursión (caso base) y acumula las cantidades en el paso de combinación:

```c
#include <stddef.h>

size_t contar_pares_divide_y_venceras(const int arr[], size_t ini, size_t fin) {
    // Caso Base: un único elemento
    if (ini == fin) {
        return (arr[ini] % 2 == 0) ? 1 : 0;
    }
    
    // Dividir
    size_t mid = ini + (fin - ini) / 2;
    
    // Conquistar
    size_t pares_izq = contar_pares_divide_y_venceras(arr, ini, mid);
    size_t pares_der = contar_pares_divide_y_venceras(arr, mid + 1, fin);
    
    // Combinar
    return pares_izq + pares_der;
}
```
:::

(ventajas-y-desventajas)=
## Ventajas y Desventajas

```{list-table}
:header-rows: 1

* - Ventajas
  - Desventajas
* - Permite resolver problemas complejos de manera eficiente (por ejemplo, con complejidad $O(n \log n)$).
  - La sobrecarga de la recursividad (llamadas a funciones y uso de la pila) puede hacer que sea más lento que un enfoque iterativo para problemas pequeños.
* - Los algoritmos son naturalmente paralelizables, ya que los subproblemas son independientes.
  - Puede ser más complejo de implementar correctamente que las soluciones iterativas.
* - El código puede ser más elegante y fácil de entender, ya que refleja la estructura matemática del problema.
  - La recursividad profunda puede llevar a un desbordamiento de la pila (*stack overflow*) si no se maneja con cuidado.
```

(lecturas-recomendadas)=
## Lecturas Recomendadas

- **{cite:t}`cormen_introduction_2009`**. Capítulo 4: Divide-and-Conquer.
- **{cite:t}`sedgewick_algorithms_2011`**. Tratamiento de algoritmos recursivos, búsqueda binaria y Merge Sort.
- **{cite:t}`bryant_computer_2015`**. Capítulo 3: Machine-Level Representation of Programs (sección sobre procedimientos y la pila de llamadas).

