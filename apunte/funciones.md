---
title: Funciones y descomposición funcional
short_title: 3 - Funciones
subtitle: Dividiendo problemas en partes más chicas.
---

## Funciones

Ya vimos cómo darle instrucciones en C a la computadora, pero ahora, vamos a crear nuestras propias para hacer de nuestros programas, no solo más útiles sino también, con menos código duplicado.

### Definición intuitiva

Pensá en las funciones como una oficina: recibe información (documentos o tareas), las procesa con sus empleados y recursos, y luego te devuelve un resultado o un informe (un valor nuevo). En la programación, y particularmente en C, estas «oficinas» son bloques de código reutilizables diseñados para realizar una tarea específica. Son como pequeños departamentos dentro de una empresa que nos permiten organizar y simplificar la creación de software.

#### ¿Por qué son tan útiles estas «oficinas» en C?

Las funciones son un pilar fundamental de la programación estructurada en C. Permiten dividir un programa grande y complejo en partes más pequeñas y manejables, lo que trae varios beneficios:

- **Modularidad**: Cada función se encarga de una tarea concreta, haciendo que el diseño, desarrollo y corrección de errores del programa sea mucho más sencillo. Si algo no funciona, es más fácil saber en qué «departamento» de la oficina buscar el problema.

- **Reusabilidad de código**: Una vez que creas una función para una tarea, podés «encargarle» esa tarea cuantas veces necesites, en distintas partes de tu programa o incluso en otros proyectos, sin tener que escribir el mismo código una y otra vez. Esto te ahorra tiempo y reduce la posibilidad de errores.

- **Abstracción**: Podés usar una función sin necesidad de saber exactamente
  cómo opera por dentro. Solo necesitás entender qué hace, qué tipo de información espera como entrada y qué tipo de información te devolverá como salida. Esto simplifica el código principal de tu programa, que solo interactúa con la «oficina» sin preocuparse por sus procesos internos.

- **Mantenibilidad**: Si necesitás cambiar o mejorar cómo se realiza una tarea, solo tenés que modificar el interior de la función correspondiente. Sin afectar el resto de tu programa.

### Una definición más formal

En C, una **función** es un bloque de código reutilizable diseñado para realizar una tarea específica. Recibe uno o más valores de entrada, llamados _parámetros_, ejecuta un conjunto de instrucciones y produce un único valor de salida. Su propósito principal es actuar como un procesador de datos: recibe el contexto necesario, lo transforma mediante operaciones definidas y devuelve un resultado.

De forma análoga a las funciones matemáticas, podemos pensar en ella como una relación $ f(x) = y $, donde cada conjunto de valores de entrada genera exactamente un resultado. En C, una función solo puede devolver un valor directamente. (existen técnicas para sortear esta limitación, que se estudiarán más adelante)

Otra observación importante, es que en esta definición asumimos la presencia de al menos un argumento, ya que, sin parámetros, la función no cuenta con información externa para variar su comportamiento, salvo que utilice valores internos predefinidos ingresos directos del usuario o variables globales.

Esta observación nos lleva a la definición de **función pura**. Estas son aquellas que, dados los mismos parámetros de entrada, siempre devuelven el mismo resultado y no producen un {term}`efecto secundario`, es decir, no modifica variables externas ni interactúa con elementos fuera de su propio ámbito (como archivos o la pantalla). Esto, en términos matemáticos, es hacer que se comporte exactamente como lo haría una función $ f(x) $ tradicional.

Aunque su uso no aplica a todos los casos, este concepto, simplifica el comportamiento de un programa, al delimitar la interacción de nuestro código con el estado del programa. Y de regalo, es mucho más fácil asegurarnos de que el programa hace lo que debe, esto es algo que veremos más adelante.

## ¿Qué es una función en C?

Una función en C es un bloque de código que:

- Tiene un **identificador**.
- Recibe cero o más **parámetros** como entrada.
- Puede devolver un **valor de salida**.
- Contiene un **conjunto de instrucciones**.

**Sintaxis básica**

```c
<tipo> <nombre>(<tipo parámetro1>, <tipo parámetro2>, ...)
{
    // instrucciones
    return valor;
}
```

De esta sintaxis básica, es posible crear una función que no reciba argumentos
solo tenemos que dejar vacía la lista de parámetros.

Asimismo, una función en C, puede no retornar valores y esto se hace con la palabra reservada `void` (vacío en inglés).

### Ejemplos

En este ejemplo comentado, podemos ver un ejemplo de función que recibe un
par de números y devuelve uno.

```c
// retorno de tipo int, identificador sumar y dos int como argumentos
int sumar(int a, int b)
{
    int retorno = a + b; // instrucciones que completan el objetivo de la función.
    return retorno;      // instrucción que devuelve el valor calculado
}
```

Esto se puede usar desde `main()` u otra función.

```c
int resultado = sumar(5, 3);
printf("Resultado: %d\n", resultado);
```

Y también, un ejemplo de funciones que no reciben argumentos y simultáneamente, no devuelve valores.

```c
// sin retorno de valor, identificador saludar y sin argumentos.
void saludar()
{
    printf("Hola Mundo!\n");
}
```

:::{note} Procedimiento

Esta función, que no tuvo un retorno al programa, dio lugar a un {term}`efecto secundario`; el enviar caracteres por la consola.

Cuando una función no tiene retorno, se dice que es un «Procedimiento», esta distinción es para separar conceptualmente del código que da resultados explícitos al programa.

:::

### Prototipos de función

Son una declaración anticipada que informa al compilador sobre el nombre, tipo de retorno y lista de parámetros de una función **antes** de que sea utilizada en el código. Su propósito es permitir que el compilador verifique la coherencia de las llamadas a la función, garantizando que el número y el tipo de argumentos coincidan con su definición. Un prototipo no contiene el cuerpo de la función, sino únicamente su firma, y suele colocarse al inicio del archivo fuente.

El funcionamiento del compilador es limitado a pasar una sola vez por el archivo del programa lo que hace que si se llega a una llamada a función que no fue declarada, no se podrá continuar con la compilación porque este no tiene la información necesaria para garantizar que los argumentos y retornos sean los indicados.

Pueden ver esto, si cambian la definición de las funciones debajo del `main`. Como el compilador ve una llamada a función, antes de su declaración, la compilación fallará.

```c
int main()
{

    printf("%f\n", areaCirculo(10.0));
}

double areaCirculo(double radio)
{
    ...
}
```

Para que este código funcione, se necesita saber cual es la forma que tiene la función,
si el código no esta en ese lugar, no importa (en ese momento)

```c
//prototipo de la función
double areaCirculo(double radio);

int main()
{

    printf("%f\n", areaCirculo(10.0));
}

double areaCirculo(double radio)
{
    ...
}
```

Los prototipos de función se utilizan cuando una función usa a otra, y no podemos
arreglarnos reordenando funciones.

```c
int funcion_uno()
{
    ...
    funcion_dos();
    ...
}

int funcion_dos()
{
    ...
    funcion_uno()
    ...
}
```

No importa en qué orden dejemos las funciones de este ejemplo, el código no compilará.

Cosa que podemos resolver agregando un prototipo de función.

```c

int funcion_dos();

int funcion_uno()
{
    ...
    funcion_dos();
    ...
}

int funcion_dos()
{
    ...
    funcion_uno()
    ...
}
```

## Divide y vencerás

Los grandes programadores no resuelven problemas gigantescos de un solo golpe. En lugar de eso, **dividen el problema en piezas pequeñas**, comprensibles y más fáciles de encarar.

Este proceso se llama **descomposición funcional**. Cada parte se convierte en
una función.

Una función es un pequeño módulo con una misión específica. Cuando todas las piezas están listas, se ensamblan en el `main()` para contar la historia completa del programa.

> Pensá en tu programa como una obra de teatro. `main()` es el director que da las órdenes, y cada función es un actor especializado.

## Pensar como un programador: el método top-down

El método top-down (de arriba hacia abajo) es una forma de resolver problemas desde lo general hacia lo específico. Así se programa con claridad y orden.

### Etapas del método:

1. **Analizá el problema global.** ¿Qué debe hacer el programa, en líneas generales?
2. **Dividilo en subtareas lógicas.** Por ejemplo: leer datos, procesar información, mostrar resultados.
3. **Asigná una función a cada subtarea.** Cada una debería tener nombre, parámetros y un valor de retorno claro.
4. **Codificá las funciones de abajo hacia arriba.** Primero las funciones más simples (leer, calcular, etc.).
5. **Integrá todo en el `main()` de forma que quede como una receta paso a paso.**

Este enfoque permite **testear partes** antes de armar el todo, y hace que tu programa sea mucho más fácil de entender.

## Ejemplo completo: Calcular el área de un rectángulo

### Paso 1: Entender el problema

Queremos un programa que pida dos números (base y altura), calcule el área
(base \* altura), y la muestre.

### Paso 2: Dividir en tareas

1. Leer la base del usuario.
2. Leer la altura del usuario.
3. Calcular el área.
4. Mostrar el resultado.

### Paso 3: Escribir las funciones

```c
#include <stdio.h>

int calcular_area(int base, int altura);

int main()
{
    int base = leer_entero();
    int altura = leer_entero("Ingrese la altura: ");

    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("\nIngrese la altura: ");
    scanf("%d", &altura);

    int area = calcular_area(base, altura);

    printf("El área es: %d\n", area);
    return 0;
}

int calcular_area(int base, int altura)
{
    return base * altura;
}
```

> Fijate que `main()` se lee como una receta; eso es lo que buscamos.

::::{tip} Tips mentales para construir algoritmos desde cero

- **Pensá en pasos.** No escribas código directamente. Primero, papel y lápiz.
- **Usá nombres descriptivos.** `leer_entero()` es mejor que `func1()`, `base`
  en lugar de `a`.
- **Pensá en entradas y salidas.** ¿Qué necesita la función? ¿Qué devuelve?
- **Separá cálculo de entrada/salida.** No mezcles lectura con lógica.
- **Probá cada función por separado.** Imprimí resultados intermedios.

::::

## Ejercicios propuestos

1. Escribí una función que reciba un número y devuelva el doble.
2. Escribí una función que reciba dos números y devuelva el mayor.
3. Programa una conversión de Celsius a Fahrenheit. Separá en: leer, convertir, mostrar.
4. Escribí un programa que determine si un número es par o impar.
5. Escribí un programa que lea tres notas, calcule el promedio y lo muestre.
6. Hacé una función que devuelva el cuadrado de un número.
7. Componé funciones que, encadenadas, lean dos valores, sumen, resten y muestren resultados.

## Mantras de la descomposición funcional

- “Si algo se repite → función.”
- “Si algo es confuso → dividilo.”
- “`main()` es el guion, no el drama.”
- “Una función, una responsabilidad.”
- “Código limpio, mente limpia.”

Como para dejar impreso por ahí.

## Factorización y simplificación de funciones _casi_ duplicadas

Una de las habilidades clave en la programación es **reconocer patrones
repetidos** y simplificarlos. Así como en álgebra factorizamos términos comunes para escribir expresiones más simples y elegantes, en programación podemos **factorizar comportamiento común en una única función**.

### El paralelismo con la matemática

En matemática:

```{math}
:label: Factorización de terminos
ab + ac = a(b + c)
```

En la factorización de términos, extraemos el término común `a` para simplificar la expresión.

¿Y esto, cómo se aplica a la programación?

Si tenemos dos funciones que repiten el mismo bloque de código, ese bloque puede
**extraerse a una función aparte**. Esa función luego puede ser llamada desde
ambas funciones originales o incluso reemplazarlas completamente.

:::{note} ¿Solo para código idéntico?

Si podemos identificar qué es lo que cambia, y reemplazarlo por un argumento, estamos factorizando de una forma aún mejor.

:::

### Ejemplo de duplicaciones

```c
void mostrar_bienvenida()
{
    printf("Bienvenido al sistema.\n");
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_despedida()
{
    printf("Gracias por usar el sistema.\n");
    printf("Por favor ingrese sus datos.\n");
}

int main()
{
    mostrar_bienvenida();
    mostrar_despedida();
}
```

Ambas funciones tienen una línea en común. Podemos factorizar esa parte:

```c
void solicitar_datos()
{
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_bienvenida()
{
    printf("Bienvenido al sistema.\n");
    solicitar_datos();
}

void mostrar_despedida()
{
    printf("Gracias por usar el sistema.\n");
    solicitar_datos();
}

int main()
{
    mostrar_bienvenida();
    mostrar_despedida();
}
```

Sin embargo, hay una parte que sigue siendo común, y que podemos volver a
factorizar:

```c
void solicitar_datos()
{
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_saludo(char[] mensaje)
{
    printf("Bienvenido al sistema.\n");
    solicitar_datos();
}

int main()
{
    mostrar_saludo("Bienvenido al sistema.\n");
    mostrar_saludo("Gracias por usar el sistema.\n")
}
```

### ¿Por qué esto es importante?

- **Evitás repetir código.** Si hay que cambiar un mensaje, lo hacés en un solo
  lugar.
- **Dás nombres más precisos a cada parte.** Cada función tiene una misión
  clara.
- **Mejorás la legibilidad.** Se vuelve más fácil entender el flujo general.
- **Fomentás la reutilización.** Una vez creada, una función puede usarse en
  otros contextos.

### Otro ejemplo más concreto:

Supongamos dos funciones que imprimen menús distintos, pero ambas tienen una
línea que imprime una línea separadora:

```c
void menu_principal()
{
    printf("=== Menú Principal ===\n");
    printf("1. Iniciar\n2. Salir\n");
    printf("------------------------\n");
}

void menu_configuracion()
{
    printf("=== Configuración ===\n");
    printf("1. Audio\n2. Video\n");
    printf("------------------------\n");
}
```

La línea:

```c
printf("------------------------\n");
```

es candidata para factorizar:

```c
void imprimir_separador() {
    printf("------------------------\n");
}
```

Y ahora:

```c
void menu_principal()
{
    printf("=== Menú Principal ===\n");
    printf("1. Iniciar\n2. Salir\n");
    imprimir_separador();
}

void menu_configuracion()
{
    printf("=== Configuración ===\n");
    printf("1. Audio\n2. Video\n");
    imprimir_separador();
}
```

### Cómo aplicar esta idea:

1. Leé tu código buscando repeticiones.
2. Aislá la parte repetida.
3. Dale un nombre significativo.
4. Reemplazá las repeticiones por una llamada a la nueva función.

:::{tip}

> La programación, como la matemática, es arte de **reconocer patrones** y
> **simplificarlos inteligentemente**.

:::

## Responsabilidades de las funciones

En la sección anterior, se menciona algo sobre 'responsabilidades', este es
uno de los principios más importantes al escribir funciones y aplicar la
descomposición funcional.

Consiste en que **cada función debe tener una única responsabilidad** y es
fundamental para lograr código claro, mantenible y fácil de testear.

### ¿Qué significa una única responsabilidad?

Una función debe encargarse de hacer **una sola cosa**, y hacerla bien. Si una
función hace más de una tarea, se vuelve más difícil de entender, probar y
modificar.

Por ejemplo:

- Una función que **calcula un valor** no debería también **imprimirlo**.
- Una función que **lee datos del usuario** no debería **procesarlos** al mismo
  tiempo.

### Señales de alerta

- La función tiene un nombre vago o genérico (como `procesar()` o
  `gestionar()`).
- La función tiene muchas líneas de código (más de 10-15 puede ser una señal).
- La función hace cosas de diferentes niveles de abstracción (ej. imprime y
  calcula).
- Hay comentarios dentro que indican “ahora hacemos esto… luego hacemos esto
  otro”.

### Ejemplo malo:

Este ejemplo usa funciones, pero termina _mandando todo adentro_.

```c
void calcular_y_mostrar_area()
{
    int base, altura;
    printf("Ingrese base y altura: ");
    scanf("%d %d", &base, &altura);
    int area = base * altura;
    printf("Área: %d\n", area);
}
```

Esta función tiene múltiples responsabilidades:

- Entrada (leer datos con `scanf`),
- Cálculo (área),
- Salida (mostrar resultado).

### Ejemplo bueno:

```c
int calcular_area(int base, int altura)
{
    return base * altura;
}
```

Y en `main()`:

```c
int main()
{
    int base = 0;
    int altura = 0;
    printf("Base: ");
    scanf("%d", &base);
    printf("\nAltura: ");
    scanf("%d", &altura);
    int area = calcular_area(base, altura);
    printf("Área: %d\n", area);
}
```

La función tiene una **tarea clara, definida y limitada**. Y aunque podemos extender el concepto a la ‘toma de datos’ y a ‘mostrar el resultado’, con quedarnos en lo que hace el trabajo estamos más que bien.

::::{tip}

Una buena función se puede describir en una frase corta. Si necesitás
una oración compuesta, probablemente estás metiendo dos responsabilidades en
una.

::::

## Documentación de funciones

La documentación es una herramienta clave en la programación. Ayuda a que otras personas (y vos mismo, en el futuro) puedan entender rápidamente qué hace cada parte del programa sin tener que leer todo el código.

### Comentarios

Los comentarios son texto libre que podemos agregar a nuestros programas sin que este sea procesado por el compilador. Lo podemos pensar como anotaciones y observaciones del código que escribamos.

Durante la cursada, les vamos a exigir que completen comentarios específicos llamados documentación, los cuales deben tener una forma específica. Y aunque esto no es estrictamente necesario para el funcionamiento del programa, los ayudará a entender mejor el problema que están resolviendo al ponerlo en sus propias palabras.

Este es un comentario de una sola línea, que pueden usar para reforzar alguna explicación de algo que vean flojo (pero puntual)

```c
// este es un comentario de una única linea, todo lo que esta a la derecha es ignorado
```

Y este es un comentario de bloque, que se usa para documentar funciones, pero también lo pueden usar para desactivar una parte del programa:

```c
/*
Este es un comentario de bloque, todo lo que esta dentro del bloque es
ignorado, y este, a diferencia del otro, puede abarcar múltiples lineas.
*/
```

### ¿Por qué documentar funciones?

Una buena razón para documentar, y hacerlo antes de empezar a programar, es
para poner en nuestras propias palabras que es lo que el código que estamos
implementando tiene que hacer, además de:

- Para aclarar su propósito.
- Para indicar cómo debe usarse (qué espera y qué devuelve).
- Para facilitar el mantenimiento del código.
- Para evitar errores de uso (pasar valores incorrectos, malinterpretar
  comportamientos, etc.).

### Qué incluir en la documentación de una función

Una buena documentación puede colocarse como comentario justo encima de la
función, e incluye:

1. Qué hace la función.
2. Para qué recibe los parámetros que solicita.
3. Como devuelve los valores obtenidos.

### Ejemplo:

Los comentarios de documentación que les pediremos que completen, tienen esta forma, la misma no es casual. Está pensada para una herramienta que toma estos comentarios y construye un manual del código que, si nos da el tiempo, la veremos, [Doxygen](https://doxygen.nl/).

```c
/**
 * Calcula el área de un rectángulo dado su base y altura.
 *
 * @param base Entero positivo que representa la base.
 * @param altura Entero positivo que representa la altura.
 * @return El área calculada (base * altura).
 */
int calcular_area(int base, int altura)
{
    return base * altura;
}
```

## Precondiciones, Poscondiciones e Invariantes

En el contexto del diseño y verificación de software, estos conceptos forman
parte de la noción de **contrato** entre una función y su entorno. Estos elementos permiten especificar, de manera formal y verificable, qué se espera antes de ejecutar una operación, qué se garantiza después de ejecutarla y qué propiedades deben mantenerse constantes durante su funcionamiento. En conjunto, estos conceptos fortalecen la robustez, legibilidad y mantenibilidad del código, al definir claramente las responsabilidades y limitaciones de cada parte del sistema.

Al escribir funciones, no solo importa el código que contienen, sino también las expectativas que tienen sobre sus entradas y los compromisos que deben cumplir al salir. Para pensar correctamente en términos de responsabilidad y confiabilidad, veremos tres conceptos clave: precondiciones, poscondiciones e invariantes.

Este tema es mucho más grande que lo que veremos aquí, que le daremos un
tratamiento intuitivo y coloquial. Pero estos, están basados en lógica de primer
Orden y los tres conceptos están conectados logicamente, de forma que lo pre, vaya hacia lo post, manteniendo lo que no cambia.

### Precondiciones

Una _precondición_ es una afirmación lógica que debe cumplirse **antes** de la ejecución de una función, método o bloque de código para garantizar su correcto funcionamiento. Define las condiciones mínimas y necesarias que los parámetros y el estado del sistema deben cumplir para que el algoritmo pueda ejecutarse sin errores y producir un resultado válido. Si una precondición no se cumple, el comportamiento de la función es indefinido o incorrecto.

Las precondiciones forman parte del contrato que el _llamador_ debe respetar al invocar la función.

**Ejemplos**

- En una función `dividir(int a, int b)`, la precondición es que `b != 0`,
  ya que no es posible dividir por cero
- En `calcular_raiz_cuadrada(float x)`, una posible precondición es `x >= 0`,
  ya que la raiz cuadrada de un número negativo da como resultado un valor
  imaginario, que no es posible representar con los valores convencionales de C.

::::{note} Precondiciones

Si la precondición no se cumple, el resultado puede
ser inválido, o el programa puede fallar (por ejemplo, dividir por cero).

::::

### Poscondiciones

Una _poscondición_ es una afirmación lógica que debe cumplirse **después** de
que una función, método o bloque de código haya finalizado su ejecución, siempre
que se hayan cumplido las precondiciones. Especifica el estado esperado de los
datos de salida y, en algunos casos, del sistema en general.

La poscondición representa la garantía que ofrece la función a su llamador una vez que ha completado su tarea.

**Ejemplos**

- En `sumar(int a, int b)`, la poscondición es que el resultado será igual a
  `a + b`.
- En `leer_entero()`, podríamos establecer como poscondición que el valor
  retornado sea un número válido leído del usuario.

::::{note} Poscondiciones

Las poscondiciones son una promesa. Si las precondiciones se cumplen,
la función debe cumplir lo prometido.

::::

### Invariantes

Un _invariante_ es una condición lógica que permanece **verdadera en todo momento**
durante la ejecución de un programa o, más específicamente, a lo largo de todas
las iteraciones de un ciclo o entre cada llamada a funciones.

En el contexto de funciones simples y lo que aplicaremos inicialmente, esto suele
referirse a propiedades que no cambian durante la ejecución de un conjunto de operaciones o dentro de estructuras de control (como un bucle).

Este concepto aplica también a programas más complejos, donde hay funciones que manipulan un estado que debe ser mantenido entre varias funciones, algo que veremos más adelante, cuando tratemos Estructuras de Datos.

**Ejemplos**

- En un ciclo que cuenta del 1 al 10, la invariante podría ser que
  `i >= 1 && i <= 10`.
- En una función que calcula el máximo de dos números, la invariante puede ser que ninguna de las variables de entrada se modifica dentro de la función.

::::{note} Invariantes

Las invariantes te ayudan a razonar sobre la corrección interna del algoritmo.
Aunque son menos visibles, son fundamentales para asegurar que el comportamiento
del programa sea coherente.

::::

### ¿Por qué son importantes?

- Te obligan a **pensar antes de programar**.
- Facilitan el diseño y la depuración.
- Son la base para escribir funciones seguras y predecibles.
- Mejoran la **legibilidad y el contrato** entre quien implementa y quien usa una función.

### Cómo documentarlas

Incluilas como parte del comentario de documentación de la función:

```c
/**
 * Calcula el cociente entre dos números.
 * Precondición: divisor != 0.
 * Poscondición: retorna el resultado de dividir dividendo por divisor.
 * Invariante: los argumentos no son modificados.
 */
int dividir(int dividendo, int divisor)
{
    return dividendo / divisor;
}
```

Incorporar este tipo de razonamiento te prepara para escribir programas más
robustos, detectar errores antes de que ocurran y construir soluciones más
elegantes.

::::{note} en una frase

> "Las precondiciones te hacen responsable; las poscondiciones te hacen
> confiable; las invariantes te hacen coherente."

::::

## Glosario

:::{glossary}

efecto secundario
: En la programación, un efecto secundario es cualquier cambio de estado que ocurre fuera del ámbito de una función. En otras palabras, una función tiene efectos secundarios cuando modifica algo más allá de simplemente devolver un valor. En C, esto a menudo se refiere a la modificación de variables globales o datos a los que se accede a través de punteros.

:::
