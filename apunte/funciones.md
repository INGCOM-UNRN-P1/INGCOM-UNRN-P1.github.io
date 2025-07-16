---
title: 3 - Funciones y descomposición funcional
subtitle: Dividiendo problemas en partes mas chicas.
---

## Funciones

Ya vimos como darle instrucciones a la computadora, pero ahora, vamos a crear nuestras propias instrucciones para hacer
de nuestros programas, no solo más útiles sinó tambien, con menos código duplicado.

Pensá en las funciones como una oficina: recibe información (documentos o tareas), la procesa con sus empleados y recursos, y luego te devuelve un resultado o un informe (un valor nuevo). En la programación, y particularmente en C, estas "oficinas" son bloques de código reutilizables diseñados para realizar una tarea específica. Son como pequeños departamentos dentro de una empresa que nos permiten organizar y simplificar la creación de software.

### ¿Por qué son tan útiles estas "oficinas" en C?

Las funciones son un pilar fundamental de la programación estructurada en C. Permiten dividir un programa grande y complejo en partes más pequeñas y manejables, lo que trae varios beneficios:

- **Modularidad**: Cada función se encarga de una tarea concreta, haciendo que el diseño, desarrollo y corrección de errores del programa sea mucho más sencillo. Si algo no funciona, es más fácil saber en qué "departamento" de la oficina buscar el problema.

- **Reusabilidad de código**: Una vez que creas una función para una tarea, podés "encargarle" esa tarea cuantas veces necesites, en distintas partes de tu programa o incluso en otros proyectos, sin tener que escribir el mismo código una y otra vez. Esto te ahorra tiempo y reduce la posibilidad de errores.

- **Abstracción**: Podés usar una función sin necesidad de saber exactamente cómo opera por dentro. Solo necesitás entender qué hace, qué tipo de información espera como entrada y qué tipo de información te devolverá como salida. Esto simplifica el código principal de tu programa, que solo interactúa con la "oficina" sin preocuparse por sus procesos internos.

- **Mantenibilidad**: Si necesitás cambiar o mejorar cómo se realiza una tarea, solo tenés que modificar el interior de la función correspondiente, sin afectar el resto de tu programa.

## Divide y vencerás

Los grandes programadores no resuelven problemas gigantes de un solo golpe. En lugar de eso, **dividen el problema en piezas pequeñas**, comprensibles y resolubles.

Este proceso se llama **decomposición funcional**. Cada parte se convierte en una función.

Una función es un pequeño módulo con una misión específica. Cuando todas las piezas están listas, las ensamblás en el `main()` para contar la historia completa del programa.

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

## ¿Qué es una función en C?

Una función en C es un bloque de código que:

- Tiene un **nombre identificador**.
- Recibe cero o más **parámetros** como entrada.
- Devuelve (o no) un **valor de salida**.
- Ejecuta un **conjunto de instrucciones**.

### Sintaxis básica:

```c
<tipo> <nombre>(<tipo parámetro1>, <tipo parámetro2>) {
    // instrucciones
    return valor;
}
```

Ejemplo:

```c
int sumar(int a, int b) {
    return a + b;
}
```

Esto se puede usar desde `main()` u otra función:

```c
int resultado = sumar(5, 3);
printf("Resultado: %d\n", resultado);
```

**Ventajas de usar funciones:**

- Mejor organización del código.
- Reutilización.
- Lectura y depuración más fácil.
- Separación de responsabilidades.

---

## Ejemplo práctico: Calcular el área de un rectángulo

### Paso 1: Entender el problema

Queremos un programa que pida dos números (base y altura), calcule el área (base \* altura), y la muestre.

### Paso 2: Dividir en tareas

1. Leer la base del usuario.
2. Leer la altura del usuario.
3. Calcular el área.
4. Mostrar el resultado.

### Paso 3: Escribir las funciones

```c
#include <stdio.h>

int leer_entero(char mensaje[]);
int calcular_area(int base, int altura);
void mostrar_area(int area);

int main() {
    int base = leer_entero("Ingrese la base: ");
    int altura = leer_entero("Ingrese la altura: ");
    int area = calcular_area(base, altura);
    mostrar_area(area);
    return 0;
}

int leer_entero(char mensaje[]) {
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    return valor;
}

int calcular_area(int base, int altura) {
    return base * altura;
}

void mostrar_area(int area) {
    printf("El área es: %d\n", area);
}
```

> Fijate que `main()` se lee como una receta; eso es lo que buscamos.

::::{tip} Tips mentales para construir algoritmos desde cero

- **Pensá en pasos.** No escribas código directamente. Primero, papel y lápiz.
- **Usá nombres descriptivos.** `leer_entero()` es mejor que `func1()`, `base` en lugar de `a`.
- **Pensá en entradas y salidas.** ¿Qué necesita la función? ¿Qué devuelve?
- **Separá cálculo de entrada/salida.** No mezcles lectura con lógica.
- **Probá cada función por separado.** Imprimí resultados intermedios.
  ::::

## Errores comunes

- Escribir todo en `main()` sin usar funciones.
- Hacer funciones gigantes con más de una responsabilidad.
- No usar parámetros cuando deberían usarse.
- No retornar valores, y usar `printf()` adentro de funciones de cálculo.
- No probar cada parte por separado.

**Consejo:** Hacé commits al código cuando funcione algo. No sigas sumando cosas sin chequear que lo anterior funcione.

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

Como para dejar impresos


## Factorización y simplificación de funciones *casi* duplicadas

Una de las habilidades clave en la programación es **reconocer patrones repetidos** y simplificarlos. Así como en álgebra factorizamos términos comunes para escribir expresiones más simples y elegantes, en programación podemos **factorizar comportamiento común en una única función**.

### El paralelismo con la matemática

En matemática:

```math
:label: Factorización de terminos
ab + ac = a(b + c)
```

Extraemos el término común `a` para simplificar la expresión.

¿Y esto, como se aplica a la programación?

Si tenemos dos funciones que repiten el mismo bloque de código, ese bloque puede **extraerse a una función aparte**. Esa función luego puede ser llamada desde ambas funciones originales o incluso reemplazarlas completamente.

### Ejemplo de duplicaciones

```c
void mostrar_bienvenida() {
    printf("Bienvenido al sistema.\n");
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_despedida() {
    printf("Gracias por usar el sistema.\n");
    printf("Por favor ingrese sus datos.\n");
}

int main() {
    mostrar_bienvenida();
    mostrar_despedida();
}
```

Ambas funciones tienen una línea en común. Podemos factorizar esa parte:

```c
void solicitar_datos() {
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_bienvenida() {
    printf("Bienvenido al sistema.\n");
    solicitar_datos();
}

void mostrar_despedida() {
    printf("Gracias por usar el sistema.\n");
    solicitar_datos();
}

int main() {
    mostrar_bienvenida();
    mostrar_despedida();
}
```

Sin embargo, hay una parte que sigue siendo común, y que podemos volver a factorizar:

```c
void solicitar_datos() {
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_saludo(char[] mensaje) {
    printf("Bienvenido al sistema.\n");
    solicitar_datos();
}

int main() {
    mostrar_saludo("Bienvenido al sistema.\n");
    mostrar_saludo("Gracias por usar el sistema.\n")
}
```

### ¿Por qué esto es importante?

- **Evitás repetir código.** Si hay que cambiar un mensaje, lo hacés en un solo lugar.
- **Dás nombres más precisos a cada parte.** Cada función tiene una misión clara.
- **Mejorás la legibilidad.** Se vuelve más fácil entender el flujo general.
- **Fomentás la reutilización.** Una vez creada, una función puede usarse en otros contextos.

### Otro ejemplo más concreto:

Supongamos dos funciones que imprimen menús distintos, pero ambas tienen una línea que imprime una línea separadora:

```c
void menu_principal() {
    printf("=== Menú Principal ===\n");
    printf("1. Iniciar\n2. Salir\n");
    printf("------------------------\n");
}

void menu_configuracion() {
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
void menu_principal() {
    printf("=== Menú Principal ===\n");
    printf("1. Iniciar\n2. Salir\n");
    imprimir_separador();
}

void menu_configuracion() {
    printf("=== Configuración ===\n");
    printf("1. Audio\n2. Video\n");
    imprimir_separador();
}
```

---

### Cómo aplicar esta idea:

1. **Leé tu código buscando repeticiones.**
2. **Aislá la parte repetida.**
3. **Dale un nombre significativo.**
4. **Reemplazá las repeticiones por una llamada a la nueva función.**

> La programación, como la matemática, es arte de **reconocer patrones** y **simplificarlos inteligentemente**.


## Responsabilidades de las funciones

Uno de los principios más importantes al escribir funciones y aplicar la descomposición funcional es que **cada función debe tener una única responsabilidad**. Este principio se conoce como **Single Responsibility Principle** y es fundamental para lograr código claro, mantenible y fácil de testear.

### ¿Qué significa una única responsabilidad?

Una función debe encargarse de hacer **una sola cosa**, y hacerla bien. Si una función hace más de una tarea, se vuelve difícil de entender, probar y modificar.

Por ejemplo:

- Una función que **calcula un valor** no debería también **imprimirlo**.
- Una función que **lee datos del usuario** no debería **procesarlos** al mismo tiempo.

### Señales de alerta

- La función tiene un nombre vago o genérico (como `procesar()` o `gestionar()`).
- La función tiene muchas líneas de código (más de 10-15 puede ser una señal).
- La función hace cosas de diferentes niveles de abstracción (ej. imprime y calcula).
- Hay comentarios dentro que indican “ahora hacemos esto… luego hacemos esto otro”.

### Ejemplo malo:

```c
void calcular_y_mostrar_area() {
    int base, altura;
    printf("Ingrese base y altura: ");
    scanf("%d %d", &base, &altura);
    int area = base * altura;
    printf("Área: %d\n", area);
}
```

Esta función **rompe con el principio de responsabilidad única**. Hace:

- Entrada (leer datos con `scanf`),
- Cálculo (área),
- Salida (mostrar resultado).

### Ejemplo bueno:

```c
int calcular_area(int base, int altura) {
    return base * altura;
}

void mostrar_area(int area) {
    printf("Área: %d\n", area);
}
```

Y en `main()`:

```c
int base = leer_entero("Base: ");
int altura = leer_entero("Altura: ");
int area = calcular_area(base, altura);
mostrar_area(area);
```

Cada función tiene una **tarea clara, definida y limitada**, igual que antes, como una receta.

### ¿Por qué esto es tan importante?

- **Facilita la lectura**: entendés qué hace la función sin leer todo su cuerpo.
- **Facilita el testeo**: podés probar funciones individuales con distintos datos.
- **Facilita el mantenimiento**: si hay un bug, sabés en qué parte buscar.
- **Facilita el reuso**: podés usar la misma función en distintos programas.

::::{tip}
Una buena función se puede describir en una frase corta. Si necesitás una oración compuesta, probablemente estás metiendo dos responsabilidades en una.
::::

## Precondiciones, Poscondiciones e Invariantes

Al escribir funciones, no solo importa el código que contienen, sino también las **expectativas** que tienen sobre sus entradas y los **compromisos** que deben cumplir al salir. Para pensar correctamente en términos de responsabilidad y confiabilidad, conviene conocer tres conceptos clave: **precondiciones**, **poscondiciones** e **invariantes**.

### Precondiciones

Una **precondición** es una **condición que debe cumplirse antes de ejecutar la función** para que funcione correctamente.

Las precondiciones son responsabilidad de quien **llama a la función**, no de la función misma.

#### Ejemplos:

- En una función `dividir(int a, int b)`, la precondición es que `b != 0`.
- En `calcular_raiz_cuadrada(float x)`, una posible precondición es `x >= 0`.

::::{note} Precondiciones
Si la precondición no se cumple, el resultado puede ser inválido, o el programa puede fallar (por ejemplo, dividir por cero).
::::

### Poscondiciones

Una **poscondición** es una **condición que la función garantiza después de su ejecución**, siempre que se hayan cumplido las precondiciones.

Es decir, si las entradas eran válidas, la función debe asegurar que las salidas cumplen ciertas propiedades.

#### Ejemplos:

- En `sumar(int a, int b)`, la poscondición es que el resultado será igual a `a + b`.
- En `leer_entero()`, podríamos establecer como poscondición que el valor retornado sea un número válido leído del usuario.

::::{note} Poscondiciones
Las poscondiciones son una promesa. Si las precondiciones se cumplen, la función debe cumplir lo prometido.
::::

### Invariantes

Una **invariante** es una **condición que debe cumplirse siempre**, antes, durante y después de la ejecución del algoritmo.

En el contexto de funciones simples, esto suele referirse a propiedades que **no cambian** durante la ejecución de un conjunto de operaciones o dentro de estructuras de control (como un bucle).

#### Ejemplos:

- En un ciclo que cuenta del 1 al 10, la invariante podría ser que `i >= 1 && i <= 10`.
- En una función que calcula el máximo de dos números, la invariante puede ser que ninguna de las variables de entrada se modifica dentro de la función.

::::{note} Invariantes
Las invariantes te ayudan a razonar sobre la corrección interna del algoritmo. Aunque son menos visibles, son fundamentales para asegurar que el comportamiento del programa sea coherente.
::::

### ¿Por qué son importantes?

- Te obligan a **pensar antes de programar**.
- Facilitan el diseño y la depuración.
- Son la base para escribir funciones seguras y predecibles.
- Mejoran la **legibilidad y el contrato** entre quien implementa y quien usa una función.

### Cómo documentarlas

Podés incluirlas como comentarios antes de la función:

```c
/**
 * Calcula el cociente entre dos números.
 * Precondición: divisor != 0
 * Poscondición: retorna el resultado de dividir dividendo por divisor
 */
int dividir(int dividendo, int divisor) {
    return dividendo / divisor;
}
```

Incorporar este tipo de razonamiento te prepara para escribir programas **más robustos**, detectar errores antes de que ocurran y construir soluciones más elegantes.

::::{note} en una frase
> "Las precondiciones te hacen responsable; las poscondiciones te hacen confiable; las invariantes te hacen coherente."
::::

## Documentación de funciones

La documentación es una herramienta clave en la programación. Ayuda a que otras personas (y vos mismo, en el futuro) puedan entender rápidamente qué hace cada parte del programa sin tener que leer todo el código.

### ¿Por qué documentar funciones?

- Para **aclarar su propósito**.
- Para **indicar cómo debe usarse** (qué espera y qué devuelve).
- Para **facilitar el mantenimiento** del código.
- Para **evitar errores de uso** (pasar valores incorrectos, malinterpretar comportamientos, etc.).

### Qué incluir en la documentación de una función

Una buena documentación puede colocarse como comentario justo encima de la función, e incluye:

- **Qué hace la función.**
- **Qué parámetros recibe.**
- **Qué devuelve.**
- (Opcional) **Precondiciones** o supuestos.

### Ejemplo:

```c
/**
 * Calcula el área de un rectángulo dado su base y altura.
 *
 * @param base Entero positivo que representa la base.
 * @param altura Entero positivo que representa la altura.
 * @return El área calculada (base * altura).
 */
int calcular_area(int base, int altura) {
    return base * altura;
}
```

### Buenas prácticas:

- **Usá frases completas** y claras.
- **Sé preciso**, evitá generalidades como "hace cálculos".
- **Actualizá los comentarios** si cambiás la función.
- Documentá **todas las funciones públicas** (llamadas desde `main()` u otras).

> Un código sin documentación es como un mapa sin leyenda. Podés adivinar el camino, pero probablemente te pierdas.
