---
title: 2 - Introducción a la programación en C
subtitle: La sintaxis y programas básicos.
---

# Clase 2: Introducción a la Programación en C

Este apunte resume los conceptos fundamentales del lenguaje de programación C,
su historia, sus características principales y los elementos básicos de su
sintaxis, tal como se presentaron en la clase.

## ¿Por qué aprender C?

El lenguaje C fue creado en 1972 por **Dennis Ritchie** y **Brian Kernighan** en
los Bell Labs. A pesar de tener más de 50 años de existencia, se sigue
utilizando ampliamente debido a sus características fundamentales:

- **Simplicidad**: Tiene una sintaxis reducida que facilita entender cómo se
  relacionan las instrucciones con el hardware.

- **Eficiencia**: El código compilado en C es muy rápido, cercano al rendimiento
  del lenguaje ensamblador.

- **Portabilidad**: Permite escribir programas que pueden ejecutarse en distintos
  sistemas operativos con mínimas modificaciones.

- **Historia y Origen:** Nació de la necesidad de tener un lenguaje eficiente
  y portable para desarrollar el sistema operativo UNIX.

- **Evolución y Estandarización:** Lejos de ser un lenguaje estático, C ha
  estado en constante revisión y mejora. Ha sido estandarizado por organismos como
  ANSI e ISO (norma ISO/IEC 9899), con revisiones importantes en 1989 (C89/ANSI C),
  1999 (C99), 2011 (C11) y posteriores. Esto garantiza su vigencia y compatibilidad.

  - **C89/C90** (ANSI/ISO)
  - **C99**
  - **C11**
  - **C18**
  - **C24**, la versión mas nueva.

- **Influencia:** C ha servido como base o inspiración para muchos de los
  lenguajes más utilizados hoy en día, incluyendo C++, C#, Java, JavaScript,
  Objective-C y PHP. Aprender C te da una base sólida para entender cómo funcionan
  muchos otros lenguajes.

- **Popularidad**: Figura entre los lenguajes más usados según el índice TIOBE
  (actualmente en el puesto 3).

## Características Principales de C

### Nivel de Abstracción

C es considerado un lenguaje de **nivel medio**. Cuando fue creado, era de
"alto nivel" en comparación con el lenguaje ensamblador. Hoy en día, se sitúa
entre los lenguajes de bajo nivel (ensamblador) y los de alto nivel (como Python).
Esto le da un balance único:

- Permite un control muy cercano al hardware del sistema (gestión de memoria,
  registros, etc.).
- Ofrece construcciones de programación estructurada que facilitan el desarrollo
  de algoritmos complejos.

Esta característica está ligada a que C es un lenguaje **compilado**. El código
fuente se traduce directamente a código máquina antes de ejecutarse, a
diferencia de los lenguajes **interpretados** (como Python) que son traducidos
línea por línea en tiempo de ejecución.

### Atributos Clave

- **Compilado** un programa es convertido a código de máquina de forma completa
  antes de ser ejecutado por otro programa, llamado compilador.
- **Imperativo y Estructurado:**
  - **Imperativo:** Un programa consiste en una secuencia de instrucciones que
    modifican el estado (las variables) del programa.
  - **Estructurado:** El código se organiza en bloques lógicos y funciones, lo
    que promueve la claridad y la reutilización.

## El lenguaje en sí, el "Hola Mundo" de C

El primer paso en cualquier lenguaje es el "Hola Mundo". Este simple programa
nos permite entender la estructura básica, la sintaxis y la gramática.

.

```C
#include <stdio.h>              // directiva al preprocesador

int main()                      // punto de entrada del programa
{                               // inicio de un bloque de código
    printf("Hola mundo C.\n");  // llamada a la instruccion de salida
    return 0;                   // finalización del programa
}                               // fin del bloque de código
```

### Piezas Básicas

1. `#include <stdio.h>`: Es una **directiva del preprocesador**. Le indica al
   compilador que incluya la librería estándar de entrada/salida (`stdio.h`), que
   contiene la definición de la función `printf`.

2. `int main()`: Es el **punto de entrada** del programa. Todo programa en C
   comienza su ejecución aquí. La palabra `int` indica que la función devolverá un
   número entero.

3. `{ ... }`: Las llaves definen un **bloque de código**. Todo lo que está
   dentro de las llaves pertenece a la función `main`.

4. `printf("Hola mundo C.\n");`: Es una **instrucción** que llama a la función
   `printf` para imprimir el texto en la consola. `\n` es un carácter especial que
   representa un salto de línea.

5. `return 0;`: Es la instrucción que **finaliza la función `main`** y devuelve
   un valor al sistema operativo. Por convención, `0` significa que el programa
   terminó sin errores.

### Compilación y Ejecución

Para ejecutar un programa en C, primero hay que compilarlo. Esto se hace desde
la terminal con un compilador como `gcc`:

```sh
# Compila el archivo hola.c y crea un ejecutable llamado a.out
# (en Linux/macOS) o a.exe (en Windows)
$> gcc hola.c

# Ejecuta el programa
$> ./a.out
```

## Sintaxis Básica

La **sintaxis** es el conjunto de reglas que definen cómo debe escribirse el
código para ser considerado válido.

Mientras que la **gramática** determina si el código tiene sentido lógico y
estructural. Es posible que algo sea sintácticamente válido pero gramaticalmente
incorrecto.

### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que damos a variables y funciones. Deben
empezar con una letra o un guion bajo (`_`) y pueden contener letras, números y
guiones bajos. C distingue entre mayúsculas y minúsculas (`suma` es diferente de
`Suma`).

- Comienzan con letra o guion bajo: `azAZ_`
- Pueden incluir números después: `0-9`
- Pueden utilizar guiones bajos: `_`
- No pueden ser palabras reservadas.

**Palabras Reservadas:** Son palabras con un significado especial en C y no
pueden ser usadas como identificadores (ej: `int`, `if`, `else`, `while`, `return`).

#### Ejemplos

- Correctos: `sumaTotal`, `valor_maximo`
- Incorrectos: `2variable`, `var-uno`, `int`

Es importante tener en cuenta que hay una forma especifica para cada tipo de
identificador, esto lo iremos viendo a lo largo del curso y esta resumido en las
cuestiones de estilo.

### Variables y Tipos de Datos

En C, todas las variables deben ser declaradas con un tipo de dato específico
antes de ser usadas.

- **Declaración:** `tipo nombre_variable;`
- **Inicialización:** `tipo nombre_variable = valor;`

> **Cuestión de Estilo:** Es una buena práctica declarar una sola variable por
> línea e inicializarla siempre a un valor conocido para evitar comportamientos
> inesperados. `int contador = 0;`

#### Tipos de Datos Primitivos

- **Números Enteros:**

  - `int`: El entero estándar (usualmente 32 bits).
  - `short`: Entero corto.
  - `long`: Entero largo.
  - Pueden ser `signed` (con signo, por defecto) o `unsigned` (sin signo, solo positivos).
  - La librería `<stdint.h>` define tipos con tamaño específico como `int32_t`
    o `uint8_t`.

- **Números Reales (Punto Flotante):**

  - `float`: Precisión simple (4 bytes).
  - `double`: Precisión doble (8 bytes).

- **Caracteres:**

  - `char`: Almacena un único carácter (ej: `'a'`). Se encierra entre comillas simples.

- **Lógicos (Booleanos):**
  - `bool`: Almacena `true` o `false`. Requiere incluir la librería `<stdbool.h>`
    (estándar desde C99).

> **Nota:** C no tiene un tipo de dato `string` nativo. Las cadenas de texto se
> manejan como arreglos de caracteres, un tema que se verá más adelante.

#### Literales numéricos

Al momento de que nuestro código tenga algún valor numérico concreto, lo podemos
indicar de forma "literal"

- Números enteros
  - Decimal: `1234`
  - Binario: `0b1010`
  - Octal: `0173`
  - Hexadecimal: `0xCAFE`
- Números reales
  - Flotantes: `3.14f;`
  - Double: `3.14;`
- Caracteres: `'A'`
- Lógicos: `true` / `false`

### Salida y Entrada por Consola

#### `printf` (salida)

`printf("cadena de formato", var1, var2, ...);`

Usa códigos de formato para imprimir variables: `%d` para `int`, `%f` para
`double`/`float`, `%c` para `char`. Se pueden imprimir multiples variables
en una única llamada a `printf`.

```c
printf("numero: %d\n caracter:%c", 123, 'a');
```

(En este ejemplo se usan valores literales, que es correcto pero no muy útil)

Marcadores de formato comunes

- `%d`, `%i`: int
- `%f`: float
- `%u`: unsigned int
- `%c`: char

#### `scanf` (entrada)

`scanf("%d", &variable);`
Lee un valor desde la consola y lo guarda en la dirección de memoria de una
variable. El `&` es fundamental y se explicará para que está en detalle más
adelante.

Utiliza los mismos marcadores de formato que `printf`.

```C
int edad;
scanf("%d", &edad);
```

## Expresiones y Operadores

---

- **Asignación (`=`):** Asigna el valor de la derecha (R-VALUE) a la variable de
  la izquierda (L-VALUE).

- **Aritméticos:** `+`, `-`, `*`, `/`, `%` (módulo/resto).

- **Relacionales:** `==` (igual a), `!=` (distinto de), `>`, `<`, `>=`, `<=`.
  Devuelven `1` (verdadero) o `0` (falso).

- **Lógicos:** `&&` (Y lógico), `||` (O lógico), `!` (NO lógico).

> En C, cualquier valor numérico distinto de cero se considera **verdadero** en
> un contexto lógico, mientras que cero se considera **falso**. Esto se lo
> llama "truthyness" y depender de ello, no ayuda a la legibilidad del código.

## Estructuras de Control

---

Permiten alterar el flujo secuencial de un programa.

> **Cuestión de Estilo:** Las llaves `{}` que definen un bloque de código deben
> ir en su propia línea para mejorar la legibilidad.

### Condicional `if-else`

```C
if (condicion) {
    // Bloque si es verdadero
} else if (otra_condicion) {
    // Bloque alternativo
} else {
    // Bloque si todo lo anterior es falso
}

```

Un ejemplo un poco mas concreto:

```c
if (x > 0) {
    printf("Positivo\n");
} else if (x == 0) {
    printf("Cero\n");
} else {
    printf("Negativo\n");
}
```

### Selección Múltiple `switch`

Útil para comparar una variable con múltiples valores constantes.

```C
switch (expresion) {
    case valor1:
        // sentencias
        break;
    case valor2:
        // sentencias
        break;
    default:
        // sentencias si no coincide ningún caso
}
```

Es importante destacar que la instrucción `break` es opcional, y puede ser utilizada
para agrupar "casos".

```c
switch (x) {
    case 1:
    case 2:
    case 3:
        printf("Entre 1 y 3\n");
        break;
    default:
        printf("Otro valor\n");
}
```

### Bucles (Lazos)

#### `for`: Lazo definido

Ideal cuando se conoce el número de iteraciones.
`for (inicio; condicion; incremento) { ... }`

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

#### `while`: Lazo indefinido

Se ejecuta mientras la condición sea verdadera.
La condición se evalúa al principio. `while (condicion) { ... }`

```c
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

#### `do-while`: Lazo indefinido invertido

Se ejecuta al menos una vez y luego evalúa la
condición al final. `do { ... } while (condicion);`

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 10);
```

#### Control de flujo dentro de bucles

- `break`: sale del bucle.

- `continue`: salta a la siguiente iteración.

TODO: Agregar ejemplos y detalles

## Funciones

Son bloques de código reutilizables que realizan una tarea específica. Son la
base de la programación estructurada.

### Definición:

```C
/**
    * Comentario de documentación explicando qué hace la función.
    * @param parametro1 Descripción del primer parámetro.
    * @return Descripción de lo que retorna.
    */
tipo_retorno nombre_funcion(tipo_param1 nombre_param1) {
    // Cuerpo de la función
    return valor;
}
```

```c
int sumar(int a, int b) {
    return a + b;
}
```

### Llamada (o invocación)

`variable = nombre_funcion(argumento1);`

```c
int resultado = sumar(3, 4);
```

> **Cuestiones de Estilo:** TODO: VINCULAR LAS REGLAS PUNTUALES
>
> - Una función debe tener un único punto de salida (`return`).
>
> - Las funciones no deben interactuar directamente con el usuario (usando
>   `printf` o `scanf`), sino recibir datos a través de sus parámetros y devolver
>   resultados con `return`. Su propósito es procesar, no interactuar.
>
> - Toda función debe tener un comentario de documentación explicando su
>   propósito, parámetros y valor de retorno.

Ejemplo completo de una función con su documentación

```c
/**
 * Suma dos enteros.
 * @param a Primer número
 * @param b Segundo número
 * @return Resultado de la suma
 */
int sumar(int a, int b) {
    return a + b;
}
```

## Bibliografía y Recursos Adicionales

- **Libros Clásicos:**

  - Kernighan, B. W., & Ritchie, D. M. (1988). _The C Programming Language
    (2nd ed.)_. Prentice Hall. (El libro de referencia por los creadores del
    lenguaje, también conocido como "K&R").

  - King, K. N. (2008). _C Programming: A Modern Approach (2nd ed.)_. W. W.
    Norton & Company. (Una excelente alternativa moderna, muy detallada y con
    buenos ejemplos).

