## Precondiciones, Poscondiciones e Invariantes

En el contexto del diseño y verificación de software, estos conceptos forman
parte de la noción de **contrato** entre una función y su entorno. Estos
elementos permiten especificar, de manera formal y verificable, qué se espera
antes de ejecutar una operación, qué se garantiza después de ejecutarla y qué
propiedades deben mantenerse constantes durante su funcionamiento. En conjunto,
estos conceptos fortalecen la robustez, legibilidad y mantenibilidad del código,
al definir claramente las responsabilidades y limitaciones de cada parte del
sistema.

Al escribir funciones, no solo importa el código que contienen, sino también las
expectativas que tienen sobre sus entradas y los compromisos que deben cumplir
al salir. Para pensar correctamente en términos de responsabilidad y
confiabilidad, veremos tres conceptos clave: precondiciones, poscondiciones e
invariantes.

Este tema es mucho más grande que lo que veremos aquí, que le daremos un
tratamiento intuitivo y coloquial. Pero estos, están basados en lógica de primer
Orden y los tres conceptos están conectados lógicamente, de forma que lo pre,
vaya hacia lo post, manteniendo lo que no cambia.

### Precondiciones

Una _precondición_ es una afirmación lógica que debe cumplirse **antes** de la
ejecución de una función, método o bloque de código para garantizar su correcto
funcionamiento. Define las condiciones mínimas y necesarias que los parámetros y
el estado del sistema deben cumplir para que el algoritmo pueda ejecutarse sin
errores y producir un resultado válido. Si una precondición no se cumple, el
comportamiento de la función es indefinido o incorrecto.

Las precondiciones forman parte del contrato que el _llamador_ debe respetar al
invocar la función.

**Ejemplos**

- En una función `dividir(int a, int b)`, la precondición es que `b != 0`, ya
  que no es posible dividir por cero
- En `calcular_raiz_cuadrada(float x)`, una posible precondición es `x >= 0`, ya
  que la raiz cuadrada de un número negativo da como resultado un valor
  imaginario, que no es posible representar con los valores convencionales de C.

::::{note} Precondiciones
Si la precondición no se cumple, el resultado puede ser inválido, o el programa
puede fallar (por ejemplo, dividir por cero).

::::
### Poscondiciones

Una _poscondición_ es una afirmación lógica que debe cumplirse **después** de
que una función, método o bloque de código haya finalizado su ejecución, siempre
que se hayan cumplido las precondiciones. Especifica el estado esperado de los
datos de salida y, en algunos casos, del sistema en general.

La poscondición representa la garantía que ofrece la función a su llamador una
vez que ha completado su tarea.

**Ejemplos**

- En `sumar(int a, int b)`, la poscondición es que el resultado será igual a
  `a + b`.
- En `leer_entero()`, podríamos establecer como poscondición que el valor
  retornado sea un número válido leído del usuario.

::::{note} Poscondiciones
Las poscondiciones son una promesa. Si las precondiciones se cumplen, la función
debe cumplir lo prometido.

::::
### Invariantes

Un _invariante_ es una condición lógica que permanece **verdadera en todo
momento** durante la ejecución de un programa o, más específicamente, a lo largo
de todas las iteraciones de un ciclo o entre cada llamada a funciones.

En el contexto de funciones simples y lo que aplicaremos inicialmente, esto
suele referirse a propiedades que no cambian durante la ejecución de un conjunto
de operaciones o dentro de estructuras de control (como un bucle).

Este concepto aplica también a programas más complejos, donde hay funciones que
manipulan un estado que debe ser mantenido entre varias funciones, algo que
veremos más adelante, cuando tratemos Estructuras de Datos.

**Ejemplos**

- En un ciclo que cuenta del 1 al 10, la invariante podría ser que
  `i >= 1 && i <= 10`.
- En una función que calcula el máximo de dos números, la invariante puede ser
  que ninguna de las variables de entrada se modifica dentro de la función.

::::{note} Invariantes
Las invariantes te ayudan a razonar sobre la corrección interna del algoritmo.
Aunque son menos visibles, son fundamentales para asegurar que el comportamiento
del programa sea coherente.

::::
### ¿Por qué son importantes?

- Obligan a **pensar antes de programar**.
- Facilitan el diseño y la depuración.
- Son la base para escribir funciones seguras y predecibles.
- Mejoran la **legibilidad y el contrato** entre quien implementa y quien usa
  una función.

### Cómo documentarlas

Incluilas como parte del comentario de documentación de la función:

Una forma es incluirlas como parte de la prosa de la documentación.

```c
/**
 * Calcula el cociente entre dos números.
 *
 * @param dividento es el numero que sera dividido.
 * @param divisor con el que se dividirá dividendo y debe ser distinto a 0.
 * @returns el resultado de dividir dividendo por divisor, o el codigo de error
 *            DIV_CERO
 * Invariante: los argumentos no son modificados.
 */
int dividir(int dividendo, int divisor)
{
    return dividendo / divisor;
}
```

Y otra opción, completamente válida es la de indicar explícitamente que una
frase refiere a una de estas características:

```c
/**
 * Calcula el cociente entre dos números.
 *
 * @param dividento es el numero que sera dividido.
 * @param divisor con el que se dividirá dividendo.
 *      #PRE debe ser distinto a 0, no esta definida la división para este valor.
 * @returns el resultado de dividir dividendo por divisor, o el codigo de error
 *            DIV_CERO
 *      #POST Se retornara un código de error en caso de que la
 *           precondicion no se cumpla.
 * Invariante: los argumentos no son modificados.
 */
int dividir(int dividendo, int divisor);
```

Sea cual fuere la forma en la que incorporen esta información, sumar este tipo
de razonamiento te prepara para escribir programas más robustos, detectar
errores antes de que ocurran y construir soluciones más elegantes.

::::{note} en una frase
> "Las precondiciones te hacen responsable; las poscondiciones te hacen
> confiable; las invariantes te hacen coherente."

::::
