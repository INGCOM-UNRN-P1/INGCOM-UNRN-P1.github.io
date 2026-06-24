---
title: Introducción a la programación en C
short_title: 2 - C base
subtitle: La sintaxis y programas básicos.
---

## Introducción

Antes de iniciar el estudio de la programación en C, es fundamental comprender que programar no consiste únicamente en aprender un lenguaje, sino en desarrollar una forma de pensar. El lenguaje es la herramienta, pero el verdadero arte reside en la construcción de instrucciones lógicas para resolver problemas.

:::{note} Prerrequisito: Fundamentos de Algoritmos
Este capítulo asume que ya comprendés los conceptos fundamentales de algoritmos, variables, tipos de datos, estructuras de control (if, while, for) y funciones que se presentaron en el [](1_base). Si necesitás repasar estos conceptos, consultá ese capítulo primero para entender la lógica antes de enfocarte en la sintaxis de C.
:::

Programar es el acto de proporcionar instrucciones precisas a una computadora para que realice una tarea específica. Una diferencia clave con la comunicación humana es que la computadora **no interpreta ambigüedades**. No comprende conceptos como «más o menos». Cada paso debe estar perfectamente definido. En este sentido, C presenta ciertas ambigüedades que pueden conducir a resultados inesperados.

Durante la programación, la omisión de un solo detalle puede provocar que el programa no funcione. Por ello, es necesario aprender a **pensar como una máquina**, pero también a **estructurar el pensamiento como un ser humano inteligente**.

En C, no existen atajos, lo cual es una ventaja, ya que obliga a pensar de forma clara y lógica.

---

## ¿Por qué aprender C?

El lenguaje C fue creado en 1972 por **Dennis Ritchie** y **Brian Kernighan** en los Bell Labs. A pesar de tener más de 50 años de existencia, se sigue utilizando ampliamente debido a sus características fundamentales:

- **Simplicidad**: Tiene una sintaxis reducida que facilita entender cómo se relacionan las instrucciones con el hardware.
- **Eficiencia**: El código compilado en C es muy rápido, cercano al rendimiento del lenguaje ensamblador.
- **Portabilidad**: Permite escribir programas que pueden ejecutarse en distintos sistemas operativos con mínimas modificaciones.
- **Historia y origen:** Nació de la necesidad de tener un lenguaje eficiente y portable para desarrollar el sistema operativo UNIX.
- **Evolución y estandarización:** C ha estado en constante revisión y mejora. Ha sido estandarizado primero por el {abbr}`ANSI (Instituto Nacional Estadounidense de Estándares)` y luego por la {abbr}`ISO (Organización Internacional de Normalización)` e {abbr}`IEC (Comisión Electrotécnica Internacional)`. Para mantener la vigencia del lenguaje y su compatibilidad entre implementaciones, se han publicado revisiones periódicas:
  - [ANSI X3.159-1989](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub160.pdf)
  - [ISO/IEC 9899:1990](https://www.iso.org/standard/17782.html)
  - [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html)
  - [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html)
  - [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html)
  - [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
- **Influencia:** C ha servido como base e inspiración para muchos de los lenguajes más utilizados hoy en día (C++, C#, Java, JavaScript, PHP). Aprender C proporciona una base sólida para entender cómo funcionan muchos otros lenguajes.
- **Popularidad**: Figura entre los lenguajes más usados según el [índice TIOBE](https://www.tiobe.com/tiobe-index/c/), que mide el interés en los diferentes lenguajes.

---

## Características Principales de C

### Nivel de Abstracción

Aunque C es considerado un lenguaje de **nivel medio**, en el momento en el que fue creado se lo consideraba de alto nivel en comparación con el {term}`Lenguaje Ensamblador`.

Hoy en día, y teniendo en cuenta que pasaron _solo_ 50 años desde que fue creado, se lo sitúa en un nivel superior a los de bajo nivel, pero inferior a los que actualmente son considerados de alto nivel como Python o Java.

Esto le da un balance único:
- Permite un control muy cercano al hardware del sistema (gestión de memoria, registros, etc.).
- Ofrece construcciones de programación estructurada que facilitan el desarrollo de algoritmos complejos.

C es un lenguaje **compilado**. El código fuente se traduce directamente a código máquina integramente antes de ejecutarse mediante un compilador, a diferencia de los lenguajes **interpretados** que son traducidos línea por línea en tiempo de ejecución.

### Atributos Clave

- **Compilado:** El código fuente se traduce por completo a instrucciones nativas de CPU antes de su ejecución.
- **Imperativo:** Un programa consiste en una secuencia de instrucciones que modifican el estado (las variables) del programa.
- **Estructurado:** El código se organiza en bloques lógicos y funciones, lo que promueve la claridad y la reutilización.

---

### Fortalezas del Lenguaje C

#### Acceso a conceptos de bajo nivel
C provee acceso a conceptos directamente relacionados con el hardware. Conceptos como el tamaño de la memoria, punteros y direccionamiento físico de memoria son muy similares a los que la CPU utiliza, de forma que los programas sean lo más rápidos posible.

#### C es un lenguaje pequeño
El lenguaje C posee un núcleo sintáctico y un conjunto de palabras clave reducido. Todo lo demás provisto por el entorno se cubre mediante la biblioteca estándar de C y funciones auxiliares.

#### C es un lenguaje permisivo
El lenguaje asume que el programador sabe lo que está haciendo, por lo que permite un control absoluto sobre el sistema, reduciendo las capas de validación del compilador, para bien y para mal.

---

### Debilidades del Lenguaje C

#### Los programas en C pueden ser propensos a errores
La gran flexibilidad y permisividad de C facilitan la introducción de fallas de lógica o memoria que no siempre son detectadas por el compilador en tiempo de traducción. La mayoría de los errores de memoria (como el acceso fuera de límites o desreferencia de punteros nulos) se detectan recién en tiempo de ejecución.

#### Los programas en C pueden ser difíciles de entender
Debido a su diseño conciso e histórico (creado en una época donde la entrada de texto por consola era lenta), C utiliza una sintaxis compacta y operadores que pueden combinarse de forma críptica, exigiendo un cuidado extremo para mantener la legibilidad.

#### Los programas en C pueden ser difíciles de modificar
Los programas grandes escritos en C pueden ser difíciles de mantener si no se diseñan con cuidado. A diferencia de lenguajes orientados a objetos, C carece de conceptos como clases o paquetes integrados, delegando la modularidad a la estructuración de archivos del desarrollador.

---

## La caja de herramientas

### Preparación del entorno

Para los usuarios de Windows, la cátedra ha preparado un programa para simplificar la instalación de las herramientas necesarias para editar, compilar y ejecutar los programas.

[INGCOM-UNRN-P1/entorno](https://github.com/INGCOM-UNRN-P1/entorno)

Esencialmente, instala `gcc`, `VSCode`, `git` y una terminal, también podés instalar manualmente todo siguiendo la guía: [compilador](../guias/compilador).

En sistemas basados en Debian/Ubuntu:

```bash
sudo apt install build-essential
```

:::{warning} ¡Importante!
Si surgen problemas o dificultades en la instalación del entorno, consultá inmediatamente en las clases prácticas o en el espacio de [Discussions](https://github.com/orgs/INGCOM-UNRN-P1/discussions).
:::

### Primer programa: el «Hola Mundo» en C

```{code-block} c
:label: holamundo
:caption: El indispensable Hola Mundo!
:linenos:
:filename: hola.c

#include <stdio.h>              // directiva del preprocesador

int main()                      // punto de entrada del programa
{                               // inicio de un bloque de código
    printf("Hola mundo C.\n");  // llamada a función de biblioteca para salida
    return 0;                   // finalización del programa
}                               // fin del bloque de código
```

#### Compilación y Ejecución

Para ejecutar un programa en C, primero hay que compilarlo. Esto se realiza desde la terminal traduciendo el código fuente en un ejecutable de código máquina.

:::{figure} 2/compilation_process.svg
:name: fig-compilation-process
:alt: Proceso de compilación en C

El proceso de compilación transforma el código fuente en un ejecutable que la máquina puede ejecutar directamente.
:::

```{code-block} sh
:label: salidamundo
:caption: La salida por la terminal.

# Compila el archivo hola.c y crea un ejecutable por defecto llamado a.out (a.exe en Windows)
$> gcc hola.c

# Ejecuta el programa
$> ./a.out
Hola mundo C.
$>
```

En la función `printf`, el carácter especial `\n` es una secuencia de control que indica un salto de línea en la consola de salida.

_Más adelante, vamos a ver detalles de la compilación para crear programas más complejos._

#### Pieza por pieza

1. `#include <stdio.h>`: Es una **directiva del preprocesador**. Le indica al preprocesador que inserte el contenido de la cabecera de la biblioteca estándar de entrada/salida (`stdio.h`), que contiene la declaración de la función `printf`.
2. `int main()`: Es la definición de la función principal y el **punto de entrada** del programa. Todo ejecutable en C comienza su ejecución en esta función. `int` indica que devolverá un valor numérico entero al sistema operativo.
3. `{ ... }`: Las llaves delimitan el **bloque de código** del cuerpo de la función.
4. `printf("Hola mundo C.\n");`: Es una **llamada a función de biblioteca para salida** que imprime la cadena en pantalla.
5. `return 0;`: Finaliza la ejecución de la función `main` devolviendo el estado `0` al entorno. Por convención, un retorno de `0` significa finalización exitosa.

---
:::{warning} Atención
Si no ves el mensaje que está dentro de la instrucción `printf`, hay algún problema que es **fundamental** solucionar. No se debe detener en este punto, ya que es un bloqueante para todos los temas siguientes.
:::

## De la Idea al Código en C

En el capítulo {doc}`1_base` se estudiaron los fundamentos lógicos y el diseño de algoritmos en pseudocódigo. Ahora daremos el paso crucial: **traducir ese diseño abstracto a un programa real en C**.

### La Mentalidad del Programador

1. **Leé el problema, comprendelo y diseñalo.**
2. **Dividilo en pasos simples e inequívocos** (en papel o pseudocódigo) antes de tipear una sola línea.
3. **Escribí el código en C** basándote estrictamente en el algoritmo diseñado, no en la improvisación.

:::{figure} ./2/think.jpg
:alt: Roll Safe thinking
:align: center

_Pensar es más importante que escribir._
:::

### Ejemplo: Sumar dos números enteros

Diseño algorítmico:
1. Declarar variables para almacenar dos números.
2. Solicitar y leer los números.
3. Calcular la suma y asignarla a un destino.
4. Mostrar el resultado de la suma por pantalla.

```c
#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int resultado = 0;
    printf("Ingresá dos números: ");
    scanf("%d %d", &a, &b);
    resultado = a + b
    printf("La suma es: %d\n", resultado);
    return 0;
}
```

## Sobre las reglas de estilo

El uso de reglas de estilo es fundamental para garantizar la consistencia y legibilidad del código. Al adherirse a normas uniformes (como nomenclatura, indentación y posición de llaves), se facilita la colaboración y el mantenimiento del software. Para más detalles, consultá la regla {ref}`0x0000h`.

Y cuando nos referimos a colaboración, esto incluye al profesor que tiene que leer su código.

## Sintaxis y Semántica Básica

La **sintaxis** es el conjunto de reglas formales que definen cómo debe escribirse el código para que sea válido para el compilador.
La **semántica** determina el significado lógico, la estructura y el comportamiento real que tiene el código durante su ejecución. Un código puede ser sintácticamente correcto pero semánticamente erróneo.

### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que asignamos a variables, constantes y funciones. Deben comenzar obligatoriamente con una letra o guion bajo (`_`) y pueden contener letras, dígitos y guiones bajos. C distingue entre mayúsculas y minúsculas (`suma` es un identificador distinto de `Suma`). No pueden coincidir con palabras reservadas del lenguaje.

**Palabras Reservadas:** Son palabras clave del lenguaje C que poseen un significado sintáctico especial predefinido y no pueden ser utilizadas como identificadores (ej: `int`, `float`, `char`, `if`, `else`, `while`, `return`).

Nuestros identificadores deben respetar las pautas de estilo (ver {ref}`0x0001h`).

### Tipos de operadores

Los operadores son símbolos que le indican al compilador realizar manipulaciones matemáticas o lógicas específicas sobre las variables. En C se clasifican según su función y la cantidad de operandos que requieren:

*   **Aritméticos (Binarios):** Operan sobre dos valores numéricos.
    *   Suma (`+`), Resta (`-`), Multiplicación (`*`), División (`/`).
    *   Módulo (`%`): Devuelve el resto de la división entera (ej: `7 % 3` da `1`).
*   **Unarios:** Requieren un único operando.
    *   Incremento (`++`) y Decremento (`--`): Suman o restan uno a una variable (ej: `contador++`).
    *   Negación aritmética (`-`): Cambia el signo de un valor.
*   **Relacionales o de Comparación:** Comparan dos operandos y devuelven un valor lógico (`true` o `false`).
    *   Mayor que (`>`), Menor que (`<`), Mayor o igual (`>=`), Menor o igual (`<=`).
    *   Igualdad (`==`) y Diferencia (`!=`).
*   **Lógicos (Booleanos):** Permiten combinar o negar condiciones lógicas.
    *   Conjunción (`&&`): Verdadero si ambos operandos son verdaderos (AND).
    *   Disyunción (`||`): Verdadero si al menos uno de los operandos es verdadero (OR).
    *   Negación lógica (`!`): Invierte el valor lógico (NOT).

:::{warning} Confusión entre Operadores Lógicos y de bits (Bitwise)
Es fundamental no confundir los operadores lógicos booleanos (`&&` y `||`) con sus equivalentes a nivel de bits (`&` y `|`).
*   `&&` y `||` evalúan expresiones lógicas y aplican cortocircuito (si el primer operando de `&&` es falso, el segundo no se evalúa).
*   `&` y `|` son operadores a nivel de bits que manipulan la representación binaria física de los datos. Usar `&` en un condicional lógico en lugar de `&&` es un error semántico que puede producir comportamientos imprevistos.
:::

:::{warning} Cuidado con el operador de asignación
No confundas el operador de asignación simple `=` (que guarda un valor en una variable) con el operador de comparación `==` (que verifica igualdad). Este es uno de los errores semánticos más comunes en C.
:::


---

## Variables y Tipos de Datos

### ¿Qué es una variable?

Una variable es un identificador asociado a una dirección física de memoria RAM que almacena un dato de un tipo específico.

:::{figure} 2/variable_memory_concept.svg
:name: fig-variable-memory
:alt: Variables y memoria

Las variables abstraen ubicaciones físicas de memoria. Cada una tiene una dirección de memoria, un nombre y un tipo.
:::

### Tipos básicos de datos en C

- `int`: Representa números enteros (ej. `42`, `-5`).
- `float`: Representa números reales con punto flotante (ej. `3.1415`).
- `char`: Representa un único carácter o símbolo (ej. `'A'`).
- `bool`: Tipo de dato lógico que admite únicamente `true` o `false`. Requiere la inclusión de la cabecera `<stdbool.h>` (estándar C99).

:::{figure} 2/data_types_overview.svg
:name: fig-data-types
:alt: Tipos de datos en C

Especificadores de formato de tipos básicos en C.
:::

:::{important} Tamaños dependientes de la arquitectura
El estándar de C no define tamaños fijos en bytes para los tipos básicos, sino únicamente rangos mínimos y relaciones de tamaño (ej. un `long` debe ser al menos tan grande como un `int`).
*   En arquitecturas de escritorio modernas de 32 o 64 bits (x86_64, ARM64), un `int` suele ocupar 4 bytes (32 bits).
*   En microcontroladores embebidos pequeños de 8 o 16 bits (como en sistemas de automatización), un `int` puede ocupar únicamente 2 bytes (16 bits), reduciendo a la mitad su rango máximo (de $\pm 2.147.483.647$ a $\pm 32.767$).

Para garantizar la portabilidad y evitar desbordamientos accidentales al cambiar de plataforma, el estándar C99 introdujo la cabecera `<stdint.h>`, la cual proporciona tipos con tamaños fijos y explícitos en bits, como `int8_t`, `int16_t`, `int32_t` y sus variantes sin signo (`uint8_t`, `uint32_t`).
:::

### Declaración e Inicialización

Toda variable debe declararse antes de ser usada, indicando su tipo y su nombre:

```c
#include <stdbool.h>

int edad = 42;
float pi = 3.14f;
char inicial = 'A';
bool activo = true;
```

Si declarás una variable sin inicializarla, su contenido inicial en memoria física es indeterminado ("basura"). **Siempre inicializá tus variables** a un valor conocido antes de utilizarlas (ver regla de estilo {ref}`0x0003h`).


(roles-variables)=
### Roles de las Variables

En programación, el **rol de una variable** se refiere al propósito específico que una variable desempeña dentro de un algoritmo. No es solo lo que la variable _contiene_, sino para _qué_ la usamos. Identificar el rol de una variable nos permite diseñar algoritmos más claros, eficientes y fáciles de depurar. Es como asignar una tarea a cada miembro de un equipo; cada uno tiene su función y sabe qué hacer.

Establecer el rol, nos ayuda a elegir un buen identificador y salir de nombres como `a`, `b` y `c` y pasar a `sumador`, `promedio` y `bandera`. Por poner un ejemplo.

---

#### Rol de variable Auxiliar o Temporal

Una **variable auxiliar o temporal** se usa para almacenar un valor de forma
transitoria, generalmente para facilitar una operación que requiere conservar un
dato mientras se manipulan otros. El caso más común es el intercambio de valores
entre dos variables sin perder ninguno.

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int auxiliar; // 'temp' es nuestra variable auxiliar

    printf("Antes del intercambio: a = %d, b = %d\n", a, b);

    auxiliar = a; // Guarda el valor de 'a'
    a = b;    // 'a' toma el valor de 'b'
    b = auxiliar; // 'b' recupera el valor original de 'a' desde 'auxiliar'

    printf("Despues del intercambio: a = %d, b = %d\n", a, b);
    return 0;
}
```

Acá, `auxiliar` es crucial para no perder el valor original de `a` cuando se lo
asignamos a `b`.


### La Importancia de los Roles

Entender estos roles te da una perspectiva más rica sobre cómo funcionan tus
programas. No se trata solo de saber qué tipo de dato almacena una variable,
sino **para qué la estás usando**. Reconocer estos patrones te ayudará a:

- **Escribir código más limpio y legible.**
- **Depurar errores más fácilmente.**
- **Diseñar algoritmos más eficientes y comprensibles.**

Vamos a ir viendo más roles a medida que vamos aprendiendo las diferentes cosas que podemos hacer con C.


### L-Values y R-Values (Asignación y Expresiones)

Para comprender cómo el compilador evalúa y almacena los datos durante una asignación, tenés que conocer las dos categorías de expresiones en C: **L-values** y **R-values**, según lo define formalmente el estándar del lenguaje.

#### L-Values (locator values / object locators)
Un **L-value** es una expresión que identifica o localiza un objeto persistente en memoria (es decir, una celda física de memoria direccionable).
- Pensalo como una ubicación o "contenedor" que posee una dirección física en memoria lógica.
- Puede aparecer tanto a la izquierda como a la derecha de un operador de asignación (`=`).
- Son obligatorios para ciertos operadores fundamentales:
  - El operador de dirección (`&`), ya que solo se puede obtener la dirección en memoria de un objeto con ubicación física.
  - Los operadores de incremento (`++`) y decremento (`--`), porque requieren leer y reescribir sobre una posición de memoria persistente.
- Ejemplo: en `int x = 10;`, la expresión `x` es un L-value ya que referencia a una celda física de memoria asignada por el sistema.

#### R-Values (value of an expression)
Un **R-value** representa simplemente el valor de una expresión. No posee una ubicación de memoria direccionable de almacenamiento persistente; es un valor transitorio.
- Solo pueden aparecer en el lado derecho de un operador de asignación.
- No es posible aplicarles el operador de dirección `&` ni los operadores `++`/`--`.
- Ejemplos comunes de R-values:
  - Literales numéricos o caracteres (`10`, `3.14f`, `'A'`).
  - Resultados de expresiones matemáticas o lógicas (`a + b`, `x * 5`).
  - Valores de retorno temporales de funciones.

#### Restricciones del compilador
Intentar realizar asignaciones sobre un R-value producirá un error inmediato en tiempo de compilación.

```c
int x = 10;
int y = 20;

x = 50;          // VÁLIDO: 'x' es un L-value (ubicación modificable).
y = x + 5;       // VÁLIDO: 'y' es un L-value, 'x + 5' evalúa a un R-value.

// Asignaciones inválidas que causan ERROR DE COMPILACIÓN:
// 100 = x;      // ERROR: el literal '100' es un R-value, no podés asignarle nada.
// (x + y) = 15; // ERROR: la expresión 'x + y' es un R-value temporal sin dirección física.
// &x = &y;      // ERROR: la expresión de la izquierda no es un L-value asignable.
// &(x + 5);     // ERROR: el operador de dirección (&) requiere un L-value.
```

---

## Entrada y Salida Básica

### `printf()` - Salida Formateada

Se utiliza para imprimir texto y valores de variables formateados en la salida estándar de consola.
Podés consultar el [apunte más detallado del tema](../extras/printf).

```c
printf("Tiene %d años\n", edad);
```

El par de símbolos `\n` se usan para indicar el 'salto de línea', para que no
quede todo junto en una sola. Específicamente, cada vez que se ve una `\`, se
indica que el siguiente carácter tiene un significado diferente del que se ve;
esto se llama [secuencias de escape](../extras/printf#escape).


#### Especificadores de formato de tipos básicos

- `%d` o `%i` para enteros (`int`).
- `%f` para flotantes (`float`).
- `%c` para caracteres individuales (`char`).
- `%s` para cadenas de caracteres (arreglos de caracteres).

#### Rol de variable de Salida

Las **variables de salida** se utilizan para almacenar los resultados finales de
un cálculo o proceso, los cuales serán mostrados al usuario o guardados en algún
medio (como un archivo).

```c
#include <stdio.h>

int main() {
    float radio = 5.0;
    float area = 0.0; // 'area' es una variable de salida (resultado)

    // Calculamos el área del círculo
    area = 3.14159 * radio * radio;

    printf("El area del circulo con radio %.2f es: %.2f\n", radio, area); // Se muestra el valor de 'area'
    return 0;
}
```

Aquí, `area` guarda el resultado del cálculo y luego se imprime.


### `scanf()` - Entrada Formateada

Permite leer datos de entrada ingresados por teclado en la entrada estándar (`stdin`). 
Requiere pasar la dirección de la variable de destino anteponiendo el operador de dirección `&` 
(vamos a ver más adelante que significa).

```c
int edad = 0;
printf("Ingrese su edad: ");
scanf("%d", &edad);
```

#### Rol de variable de Entrada

Una **variable de entrada** es aquella que se utiliza para almacenar datos que
provienen de una fuente externa al programa, como la entrada del usuario a
través del teclado, la lectura de un archivo o datos recibidos de una red.

```c
#include <stdio.h>

int main() {
    int edad = -1; // 'edad' es una variable de entrada

    printf("Por favor, ingresa tu edad: ");
    scanf("%d", &edad); // Aquí, el valor ingresado se guarda en 'edad'

    printf("Tu edad es: %d años.\n", edad);
    return 0;
}
```

En este ejemplo, `edad` toma el valor que el usuario introduce.

#### El Buffer de Entrada y la Lectura de Caracteres

Al presionar "Enter" para enviar datos en la consola, se agrega un carácter de salto de línea (`\n`) en el buffer de entrada `stdin`. Si la siguiente instrucción lee un carácter (`scanf("%c")`), leerá ese `\n` residual en lugar de la entrada esperada. Para evitar esto, se debe anteponer un espacio en blanco en el especificador (`" %c"`), lo cual instruye a `scanf` a descartar los espacios en blanco y saltos de línea residuales del buffer.

```c
char inicial = ' ';
printf("Ingrese su inicial: ");
scanf(" %c", &inicial); // El espacio antes de %c limpia el buffer de stdin
```



## Resumen de Fundamentos

En esta unidad introductoria hemos cubierto:
- La historia y filosofía del lenguaje C.
- El concepto de estado de un programa.
- Los roles de las variables y el ciclo de vida de los datos.
- Entrada y salida elemental mediante `printf` y `scanf`.

Para continuar con el control de flujo condicional y los lazos iterativos, consultá {ref}`control-flujo-capitulo`.
