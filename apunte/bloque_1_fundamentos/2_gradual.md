---
title: Introducción a la programación en C
short_title: Sintaxis base
subtitle: La sintaxis y programas básicos.
---

(capitulo-introduccion-c)=

## Introducción

Antes de iniciar el estudio de la programación en C, es fundamental comprender
que programar no consiste únicamente en aprender un lenguaje, sino en
desarrollar una forma de pensar. El lenguaje es la herramienta, pero el
verdadero arte reside en la construcción de instrucciones lógicas para resolver
problemas.

:::{note} Prerrequisito: Fundamentos de Algoritmos

Este capítulo asume que ya comprendés los conceptos fundamentales de algoritmos,
variables, tipos de datos, estructuras de control (`if`, `while`, `for`) y 
funciones que se presentaron en el [](1_base). Si necesitás repasar estos 
conceptos, consultá ese capítulo primero para entender la lógica antes de 
enfocarte en la sintaxis de C.

:::
<!-- {note} Prerrequisito: Fundamentos de Algoritmos -->

Programar es el acto de proporcionar instrucciones precisas a una computadora
para que realice una tarea específica. Una diferencia clave con la comunicación
humana es que la computadora **no interpreta ambigüedades**. No comprende
conceptos como «más o menos». Cada paso debe estar perfectamente definido. En
este sentido, C presenta ciertas ambigüedades que pueden conducir a resultados
inesperados.

Durante la programación, la omisión de un solo detalle puede provocar que el
programa no funcione. Por ello, es necesario aprender a **pensar como una
máquina**, pero también a **estructurar el pensamiento como un ser humano
inteligente**.

En C, no existen atajos, lo cual es una ventaja, ya que obliga a pensar de forma
clara y lógica.

---

## Desarrollo

(por-que-aprender-c)=
### ¿Por qué aprender C?

El lenguaje C fue creado en 1972 por **Dennis Ritchie** y **Brian Kernighan** en
los Bell Labs. A pesar de tener más de 50 años de existencia, se sigue
utilizando ampliamente debido a sus características fundamentales:

- **Simplicidad**: Tiene una sintaxis reducida que facilita entender cómo se
  relacionan las instrucciones con el hardware.
- **Eficiencia**: El código compilado en C es muy rápido, cercano al rendimiento
  del lenguaje ensamblador.
- **Portabilidad**: Permite escribir programas que pueden ejecutarse en
  distintos sistemas operativos con mínimas modificaciones.
- **Historia y origen:** Nació de la necesidad de tener un lenguaje eficiente y
  portable para desarrollar el sistema operativo UNIX.
- **Evolución y estandarización:** C ha estado en constante revisión y mejora.
  Ha sido estandarizado primero por el {abbr}`ANSI (Instituto Nacional
  Estadounidense de Estándares)` y luego por la {abbr}`ISO (Organización
  Internacional de Normalización)` e {abbr}`IEC (Comisión Electrotécnica
  Internacional)`. Para mantener la vigencia del lenguaje y su compatibilidad
  entre implementaciones, se han publicado revisiones periódicas:
  - [ANSI
    X3.159-1989](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub160.pdf)
  - [ISO/IEC 9899:1990](https://www.iso.org/standard/17782.html)
  - [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html)
  - [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html)
  - [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html)
  - [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html)
- **Influencia:** C ha servido como base e inspiración para muchos de los
  lenguajes más utilizados hoy en día (C++, C#, Java, JavaScript, PHP). Aprender
  C proporciona una base sólida para entender cómo funcionan muchos otros
  lenguajes.
- **Popularidad**: Figura entre los lenguajes más usados según el [índice
  TIOBE](https://www.tiobe.com/tiobe-index/c/), que mide el interés en los
  diferentes lenguajes.

(caracteristicas-principales-de-c)=
### Características Principales de C

(nivel-de-abstraccion)=
#### Nivel de Abstracción

Aunque C es considerado un lenguaje de **nivel medio**, en el momento en el que
fue creado se lo consideraba de alto nivel en comparación con el lenguaje
ensamblador.

Hoy en día, y teniendo en cuenta que pasaron _solo_ 50 años desde que fue
creado, se lo sitúa en un nivel superior a los de bajo nivel, pero inferior a
los que actualmente son considerados de alto nivel como Python o Java.

Esto le da un balance único:
- Permite un control muy cercano al hardware del sistema (gestión de memoria,
  registros, etc.).
- Ofrece construcciones de programación estructurada que facilitan el desarrollo
  de algoritmos complejos.

C es un lenguaje **compilado**. El código fuente se traduce directamente a
código máquina integramente antes de ejecutarse mediante un compilador, a
diferencia de los lenguajes **interpretados** que son traducidos línea por línea
en tiempo de ejecución.

(atributos-clave)=
#### Atributos Clave

- **Compilado:** El código fuente se traduce por completo a instrucciones
  nativas de CPU antes de su ejecución.
- **Imperativo:** Un programa consiste en una secuencia de instrucciones que
  modifican el estado (las variables) del programa.
- **Estructurado:** El código se organiza en bloques lógicos y funciones, lo que
  promueve la claridad y la reutilización.

(fortalezas-del-lenguaje-c)=
#### Fortalezas del Lenguaje C

##### Acceso a conceptos de bajo nivel
C provee acceso a conceptos directamente relacionados con el hardware. Conceptos
como el tamaño de la memoria, punteros y direccionamiento físico de memoria son
muy similares a los que la CPU utiliza, de forma que los programas sean lo más
rápidos posible.

##### C es un lenguaje pequeño
El lenguaje C posee un núcleo sintáctico y un conjunto de palabras clave
reducido. Todo lo demás provisto por el entorno se cubre mediante la biblioteca
estándar de C y funciones auxiliares.

##### C es un lenguaje permisivo
El lenguaje asume que el programador sabe lo que está haciendo, por lo que
permite un control absoluto sobre el sistema, reduciendo las capas de validación
del compilador, para bien y para mal.

(debitades-del-lenguaje-c)=
#### Debilidades del Lenguaje C

##### Los programas en C pueden ser propensos a errores
La gran flexibilidad y permisividad de C facilitan la introducción de fallas de
lógica o memoria que no siempre son detectadas por el compilador en tiempo de
traducción. La mayoría de los errores de memoria (como el acceso fuera de
límites o desreferencia de punteros nulos) se detectan recién en tiempo de
ejecución.

##### Los programas en C pueden ser difíciles de entender
Debido a su diseño conciso e histórico (creado en una época donde la entrada de
texto por consola era lenta), C utiliza una sintaxis compacta y operadores que
pueden combinarse de forma críptica, exigiendo un cuidado extremo para mantener
la legibilidad.

##### Los programas en C pueden ser difíciles de modificar
Los programas grandes escritos en C pueden ser difíciles de mantener si no se
diseñan con cuidado. A diferencia de lenguajes orientados a objetos, C carece de
conceptos como clases o paquetes integrados, delegando la modularidad a la
estructuración de archivos del desarrollador.

(la-caja-de-herramientas)=
### La caja de herramientas

(preparacion-del-entorno)=
#### Preparación del entorno

Para los usuarios de Windows, la cátedra ha preparado un programa para
simplificar la instalación de las herramientas necesarias para editar, compilar
y ejecutar los programas.

[INGCOM-UNRN-P1/entorno](https://github.com/INGCOM-UNRN-P1/entorno)

Esencialmente, instala `gcc`, `VSCode`, `git` y una terminal, también podés
instalar manualmente todo siguiendo la guía: [compilador](../guias/compilador).

En sistemas basados en Debian/Ubuntu:

``` bash
sudo apt install build-essential
```
<!-- bash -->

:::{warning} ¡Importante!

Si surgen problemas o dificultades en la instalación del entorno, consultá
inmediatamente en las clases prácticas o en el espacio de
[Discussions](https://github.com/orgs/INGCOM-UNRN-P1/discussions).

:::
<!-- {warning} ¡Importante! -->

(primer-programa-el-hola-mundo-en-c)=
#### Primer programa: el «Hola Mundo» en C

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
<!-- {code-block} c -->

##### Compilación y Ejecución

Para ejecutar un programa en C, primero hay que compilarlo. Esto se realiza
desde la terminal traduciendo el código fuente en un ejecutable de código
máquina.

:::{figure} 2/compilation_process.svg
:name: fig-compilation-process
:alt: Proceso de compilación en C

El proceso de compilación transforma el código fuente en un ejecutable que la
máquina puede ejecutar directamente.

:::
<!-- {figure} 2/compilation_process.svg -->

````{code-block} text
:label: salidamundo
:caption: La salida por la terminal.

# Compila el archivo hola.c y crea un ejecutable por defecto llamado a.out (a.exe en Windows)
$> gcc hola.c

(ejecuta-el-programa)=
# Ejecuta el programa
$> ./a.out
Hola mundo C.
$>

````
<!-- {code-block} text -->

En la función `printf`, el carácter especial `\n` es una secuencia de control
que indica un salto de línea en la consola de salida.

_Más adelante, vamos a ver detalles de la compilación para crear programas más
complejos._

##### Pieza por pieza

1. `#include <stdio.h>`: Es una **directiva del preprocesador**. Le indica al
   preprocesador que inserte el contenido de la cabecera de la biblioteca
   estándar de entrada/salida (`stdio.h`), que contiene la declaración de la
   función `printf`.
2. `int main()`: Es la definición de la función principal y el **punto de
   entrada** del programa. Todo ejecutable en C comienza su ejecución en esta
   función. `int` indica que devolverá un valor numérico entero al sistema
   operativo.
3. `{ ... }`: Las llaves delimitan el **bloque de código** del cuerpo de la
   función.
4. `printf("Hola mundo C.\n");`: Es una **llamada a función de biblioteca para
   salida** que imprime la cadena en pantalla.
5. `return 0;`: Finaliza la ejecución de la función `main` devolviendo el estado
   `0` al entorno. Por convención, un retorno de `0` significa finalización
   exitosa.

:::{warning} Atención

Si no ves el mensaje que está dentro de la instrucción `printf`, hay algún
problema que es **fundamental** solucionar. No se debe detener en este punto, ya
que es un bloqueante para todos los temas siguientes.

:::
<!-- {warning} Atención -->

(de-la-idea-al-codigo-en-c)=
### De la Idea al Código en C

En el capítulo {doc}`1_base` se estudiaron los fundamentos lógicos y el diseño
de algoritmos en pseudocódigo. Ahora daremos el paso crucial: **traducir ese
diseño abstracto a un programa real en C**.

(la-mentalidad-del-programador)=
#### La Mentalidad del Programador

1. **Leé el problema, comprendelo y diseñalo.**
2. **Dividilo en pasos simples e inequívocos** (en papel o pseudocódigo) antes
   de tipear una sola línea.
3. **Escribí el código en C** basándote estrictamente en el algoritmo diseñado,
   no en la improvisación.

:::{figure} ./2/think.jpg
:alt: Roll Safe thinking
:align: center

_Pensar es más importante que escribir._

:::
<!-- {figure} ./2/think.jpg -->

(ejemplo-sumar-dos-numeros-enteros)=
#### Ejemplo: Sumar dos números enteros

Diseño algorítmico:
1. Declarar variables para almacenar dos números.
2. Solicitar y leer los números.
3. Calcular la suma y asignarla a un destino.
4. Mostrar el resultado de la suma por pantalla.

:::{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int resultado = 0;
    printf("Ingresá dos números: ");
    scanf("%d %d", &a, &b);
    resultado = a + b;
    printf("La suma es: %d\n", resultado);
    return 0;
}

:::
<!-- {code-block}c -->

(sobre-las-reglas-de-estilo)=
### Sobre las reglas de estilo

El uso de reglas de estilo es fundamental para garantizar la consistencia y
legibilidad del código. Al adherirse a normas uniformes (como nomenclatura,
indentación y posición de llaves), se facilita la colaboración y el
mantenimiento del software. Para más detalles, consultá la regla {ref}`0x0000h`.

Y cuando nos referimos a colaboración, esto incluye al profesor que tiene que
leer su código.

(sintaxis-y-semantica-basica)=
### Sintaxis y Semántica Básica

La **sintaxis** es el conjunto de reglas formales que definen cómo debe
escribirse el código para que sea válido para el compilador.
La **semántica** determina el significado lógico, la estructura y el
comportamiento real que tiene el código durante su ejecución. Un código puede
ser sintácticamente correcto pero semánticamente erróneo.

(identificadores-y-palabras-reservadas)=
#### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que asignamos a variables, constantes y
funciones. Deben comenzar obligatoriamente con una letra o guion bajo (`_`) y
pueden contener letras, dígitos y guiones bajos. C distingue entre mayúsculas y
minúsculas (`suma` es un identificador distinto de `Suma`). No pueden coincidir
con palabras reservadas del lenguaje.

**Palabras Reservadas:** Son palabras clave del lenguaje C que poseen un
significado sintáctico especial predefinido y no pueden ser utilizadas como
identificadores (ej: `int`, `float`, `char`, `if`, `else`, `while`, `return`).

Nuestros identificadores deben respetar las pautas de estilo (ver
{ref}`0x0001h`).

(tipos-de-operadores)=
#### Tipos de operadores

Los operadores son símbolos que le indican al compilador realizar manipulaciones
matemáticas o lógicas específicas sobre las variables. En C se clasifican según
su función y la cantidad de operandos que requieren:

* **Aritméticos (Binarios):** Operan sobre dos valores numéricos.
    * Suma (`+`)
    * Resta (`-`)
    * Multiplicación (`*`)
    * División (`/`).
    * Módulo (`%`) que devuelve el resto de la división entera.
* **Unarios:** Requieren un único operando.
    *   Incremento (`++`) y Decremento (`--`): Suman o restan uno a una variable
        (ej: `contador++`).
    *   Negación aritmética (`-`): Cambia el signo de un valor.
* **Relacionales o de Comparación:** Comparan dos operandos y devuelven un
    valor entero (`int`) `0` o `1` representando valores lógicos falso y  verdadero.
    * Mayor que (`>`)
    * Menor que (`<`)
    * Mayor o igual (`>=`) 
    * Menor o igual (`<=`)
    * Igualdad (`==`) 
    * Diferencia (`!=`)
* **Lógicos (Booleanos):** Permiten combinar o negar condiciones lógicas.
    *   Conjunción (`&&`): Verdadero si ambos operandos son verdaderos (AND).
    *   Disyunción (`||`): Verdadero si al menos uno de los operandos es
        verdadero (OR).
    *   Negación lógica (`!`): Invierte el valor lógico (NOT).

:::{warning} Confusión entre Operadores Lógicos y de bits (Bitwise)

Es fundamental no confundir los operadores lógicos booleanos (`&&` y `||`) con
sus equivalentes a nivel de bits (`&` y `|`).
*   `&&` y `||` evalúan expresiones lógicas y aplican cortocircuito (si el
    primer operando de `&&` es falso, el segundo no se evalúa).
*   `&` y `|` son operadores a nivel de bits que manipulan la representación
    binaria física de los datos. Usar `&` en un condicional lógico en lugar de
    `&&` es un error semántico que puede producir comportamientos imprevistos.

:::
<!-- {warning} Confusión entre Operadores Lógicos y de bits (Bitwise) -->

:::{warning} Cuidado con el operador de asignación

No confundas el operador de asignación simple `=` (que guarda un valor en una
variable) con el operador de comparación `==` (que verifica igualdad). Este es
uno de los errores semánticos más comunes en C.

:::
<!-- {warning} Cuidado con el operador de asignación -->

(variables-y-tipos-de-datos)=
### Variables y Tipos de Datos

(que-es-una-variable)=
#### ¿Qué es una variable?

Una variable es un identificador asociado a una dirección física de memoria RAM
que almacena un dato de un tipo específico.

:::{figure} 2/variable_memory_concept.svg
:name: fig-variable-memory
:alt: Variables y memoria

Las variables abstraen ubicaciones físicas de memoria. Cada una tiene una
dirección de memoria, un nombre y un tipo.

:::
<!-- {figure} 2/variable_memory_concept.svg -->

(tipos-basicos-de-datos-en-c)=
#### Tipos básicos de datos en C

- `int`: Representa números enteros (ej. `42`, `-5`).
- `float`: Representa números reales con punto flotante (ej. `3.1415`).
- `char`: Representa un único carácter o símbolo (ej. `'A'`).
- `bool`: Tipo de dato lógico que admite únicamente `true` o `false`. Requiere
  la inclusión de la cabecera `<stdbool.h>` (estándar C99).

:::{figure} 2/data_types_overview.svg
:name: fig-data-types
:alt: Tipos de datos en C

Especificadores de formato de tipos básicos en C.

:::
<!-- {figure} 2/data_types_overview.svg -->

:::{important} Tamaños dependientes de la arquitectura

El estándar de C no define tamaños fijos en bytes para los tipos básicos, sino
únicamente rangos mínimos y relaciones de tamaño (ej. un `long` debe ser al
menos tan grande como un `int`).
*   En arquitecturas de escritorio modernas de 32 o 64 bits (x86_64, ARM64), un
    `int` suele ocupar 4 bytes (32 bits).
*   En microcontroladores embebidos pequeños de 8 o 16 bits (como en sistemas de
    automatización), un `int` puede ocupar únicamente 2 bytes (16 bits),
    reduciendo a la mitad su rango máximo (de $\pm 2.147.483.647$ a $\pm
    32.767$).

Para garantizar la portabilidad y evitar desbordamientos accidentales al cambiar
de plataforma, el estándar C99 introdujo la cabecera `<stdint.h>`, la cual
proporciona tipos con tamaños fijos y explícitos en bits, como `int8_t`,
`int16_t`, `int32_t` y sus variantes sin signo (`uint8_t`, `uint32_t`).

:::
<!-- {important} Tamaños dependientes de la arquitectura -->

(2_gradual-declaracion-e-inicializacion)=
#### Declaración e Inicialización

Toda variable debe declararse antes de ser usada, indicando su tipo y su nombre:

:::{code-block}c
:linenos:
#include <stdbool.h>

int edad = 42;
float pi = 3.14f;
char inicial = 'A';
bool activo = true;

:::
<!-- {code-block}c -->

Si declarás una variable sin inicializarla, su contenido inicial en memoria
física es indeterminado ("basura"). **Siempre inicializá tus variables** a un
valor conocido antes de utilizarlas (ver regla de estilo {ref}`0x0003h`).

(1-secuencia-incorrecta-de-asignaciones)=
##### Secuencia incorrecta de asignaciones
Las variables deben poseer datos válidos antes de ser leídas o manipuladas en
expresiones o asignaciones.

*   **Incorrecto (Lectura de variables sin inicializar):**
    ```{code-block}c
    :linenos:
    int a;
    int b;
    // a y b no tienen datos definidos en memoria RAM (contienen "basura").
    // La operación sumará valores arbitrarios de la memoria.
    int resultado = a + b; 
    scanf("%d", &a);
    scanf("%d", &b);
    ```
*   **Correcto (Orden lineal lógico y seguro):**
    ```{code-block}c
    :linenos:
    int a = 0;
    int b = 0;
    // Leemos los datos de entrada primero.
    scanf("%d", &a);
    scanf("%d", &b);
    // Operamos una vez que las variables contienen valores válidos.
    int resultado = a + b;
    ```

(roles-de-las-variables)=
#### Roles de las Variables

En programación, el **rol de una variable** se refiere al propósito específico
que una variable desempeña dentro de un algoritmo. No es solo lo que la variable
_contiene_, sino para _qué_ la usamos. Identificar el rol de una variable nos
permite diseñar algoritmos más claros, eficientes y fáciles de depurar. Es como
asignar una tarea a cada miembro de un equipo; cada uno tiene su función y sabe
qué hacer.

Establecer el rol, nos ayuda a elegir un buen identificador y salir de nombres
como `a`, `b` y `c` y pasar a `sumador`, `promedio` y `bandera`. Por poner un
ejemplo.

##### Rol de variable Auxiliar o Temporal

Una **variable auxiliar o temporal** se usa para almacenar un valor de forma
transitoria, generalmente para facilitar una operación que requiere conservar un
dato mientras se manipulan otros. El caso más común es el intercambio de valores
entre dos variables sin perder ninguno.

:::{code-block}c
:linenos:
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

:::
<!-- {code-block}c -->

Acá, `auxiliar` es crucial para no perder el valor original de `a` cuando se lo
asignamos a `b`.

(la-importancia-de-los-roles)=
#### La Importancia de los Roles

Entender estos roles te da una perspectiva más rica sobre cómo funcionan tus
programas. No se trata solo de saber qué tipo de dato almacena una variable,
sino **para qué la estás usando**. Reconocer estos patrones te ayudará a:

- **Escribir código más limpio y legible.**
- **Depurar errores más fácilmente.**
- **Diseñar algoritmos más eficientes y comprensibles.**

Vamos a ir viendo más roles a medida que vamos aprendiendo las diferentes cosas
que podemos hacer con C.

(l-values-y-r-values-asignacion-y-expresiones)=
#### L-Values y R-Values (Asignación y Expresiones)

Para comprender cómo el compilador evalúa y almacena los datos durante una
asignación, tenés que conocer las dos categorías de expresiones en C:
**L-values** y **R-values**, según lo define formalmente el estándar del
lenguaje.

##### L-Values (locator values / object locators)
Un **L-value** es una expresión que identifica o localiza un objeto persistente
en memoria (es decir, una celda física de memoria direccionable).
- Pensalo como una ubicación o "contenedor" que posee una dirección física en
  memoria lógica.
- Puede aparecer tanto a la izquierda como a la derecha de un operador de
  asignación (`=`).
- Son obligatorios para ciertos operadores fundamentales:
  - El operador de dirección (`&`), ya que solo se puede obtener la dirección en
    memoria de un objeto con ubicación física.
  - Los operadores de incremento (`++`) y decremento (`--`), porque requieren
    leer y reescribir sobre una posición de memoria persistente.
- Ejemplo: en `int x = 10;`, la expresión `x` es un L-value ya que referencia a
  una celda física de memoria asignada por el sistema.

##### R-Values (value of an expression)
Un **R-value** representa simplemente el valor de una expresión. No posee una
ubicación de memoria direccionable de almacenamiento persistente; es un valor
transitorio.
- Solo pueden aparecer en el lado derecho de un operador de asignación.
- No es posible aplicarles el operador de dirección `&` ni los operadores
  `++`/`--`.
- Ejemplos comunes de R-values:
  - Literales numéricos o caracteres (`10`, `3.14f`, `'A'`).
  - Resultados de expresiones matemáticas o lógicas (`a + b`, `x * 5`).
  - Valores de retorno temporales de funciones.

##### Restricciones del compilador
Intentar realizar asignaciones sobre un R-value producirá un error inmediato en
tiempo de compilación.

:::{code-block}c
:linenos:
int x = 10;
int y = 20;

x = 50;          // VÁLIDO: 'x' es un L-value (ubicación modificable).
y = x + 5;       // VÁLIDO: 'y' es un L-value, 'x + 5' evalúa a un R-value.

// Asignaciones inválidas que causan ERROR DE COMPILACIÓN:
// 100 = x;      // ERROR: el literal '100' es un R-value, no podés asignarle
nada.
// (x + y) = 15; // ERROR: la expresión 'x + y' es un R-value temporal sin
dirección física.
// &x = &y;      // ERROR: la expresión de la izquierda no es un L-value
asignable.
// &(x + 5);     // ERROR: el operador de dirección (&) requiere un L-value.

:::
<!-- {code-block}c -->

(entrada-y-salida-basica)=
### Entrada y Salida Básica

(printf-salida-formateada)=
#### `printf()` - Salida Formateada

Se utiliza para imprimir texto y valores de variables formateados en la salida
estándar de consola.
Podés consultar el [apunte más detallado del tema](../extras/printf).

:::{code-block}c
:linenos:
printf("Tiene %d años\n", edad);

:::
<!-- {code-block}c -->

El par de símbolos `\n` se usan para indicar el 'salto de línea', para que no
quede todo junto en una sola. Específicamente, cada vez que se ve una `\`, se
indica que el siguiente carácter tiene un significado diferente del que se ve;
esto se llama [secuencias de escape](../extras/printf#escape).

##### Especificadores de formato de tipos básicos

- `%d` o `%i` para enteros (`int`).
- `%f` para flotantes (`float`).
- `%c` para caracteres individuales (`char`).
- `%s` para cadenas de caracteres (arreglos de caracteres).

##### Rol de variable de Salida

Las **variables de salida** se utilizan para almacenar los resultados finales de
un cálculo o proceso, los cuales serán mostrados al usuario o guardados en algún
medio (como un archivo).

:::{code-block}c
:linenos:
#include <stdio.h>

int main() {
    float radio = 5.0;
    float area = 0.0; // 'area' es una variable de salida (resultado)

    // Calculamos el área del círculo
    area = 3.14159 * radio * radio;

    printf("El area del circulo con radio %.2f es: %.2f\n", radio, area); // Se
    muestra el valor de 'area'
    return 0;
}

:::
<!-- {code-block}c -->

Aquí, `area` guarda el resultado del cálculo y luego se imprime.

(scanf-entrada-formateada)=
#### `scanf()` - Entrada Formateada

Permite leer datos de entrada ingresados por teclado en la entrada estándar
(`stdin`).
Requiere pasar la dirección de la variable de destino anteponiendo el operador
de dirección `&`.

:::{code-block}c
:linenos:
int edad = 0;
printf("Ingrese su edad: ");
scanf("%d", &edad);

:::
<!-- {code-block}c -->

##### Rol de variable de Entrada

Una **variable de entrada** es aquella que se utiliza para almacenar datos que
provienen de una fuente externa al programa, como la entrada del usuario a
través del teclado, la lectura de un archivo o datos recibidos de una red.

:::{code-block}c
:linenos:
#include <stdio.h>

int main() {
    int edad = -1; // 'edad' es una variable de entrada

    printf("Por favor, ingresa tu edad: ");
    scanf("%d", &edad); // Aquí, el valor ingresado se guarda en 'edad'

    printf("Tu edad es: %d años.\n", edad);
    return 0;
}

:::
<!-- {code-block}c -->

En este ejemplo, `edad` toma el valor que el usuario introduce.

##### El Buffer de Entrada y la Lectura de Caracteres

Al presionar "Enter" para enviar datos en la consola, se agrega un carácter de
salto de línea (`\n`) en el buffer de entrada `stdin`. Si la siguiente
instrucción lee un carácter (`scanf("%c")`), leerá ese `\n` residual en lugar de
la entrada esperada. Para evitar esto, se debe anteponer un espacio en blanco en
el especificador (`" %c"`), lo cual instruye a `scanf` a descartar los espacios
en blanco y saltos de línea residuales del buffer.

:::{code-block}c
:linenos:
char inicial = ' ';
printf("Ingrese su inicial: ");
scanf(" %c", &inicial); // El espacio antes de %c limpia el buffer de stdin

:::
<!-- {code-block}c -->

---

## Ejercicios de Autoevaluación

(ejercicios-de-autoevaluacion-historia-y-caracteristicas)=
### Historia y Características
:::{exercise}
:label: ej-compilacion-versus
Explicá de forma breve y rigurosa la diferencia de rendimiento entre un lenguaje
compilado (como C) y uno interpretado (como Python) en términos del ciclo de
traducción y ejecución del código.

:::
<!-- {exercise} -->

:::{solution} ej-compilacion-versus
:class: dropdown
La diferencia principal radica en el momento de la traducción y en quién ejecuta
las instrucciones:
- **C (compilado)**: El código fuente se traduce por completo y de antemano a
  código máquina (instrucciones nativas de la CPU) mediante el compilador. La
  CPU del host ejecuta el binario de forma directa y a máxima velocidad, sin
  intermediarios en tiempo de ejecución.
- **Python (interpretado)**: El código fuente se traduce a un código intermedio
  (*bytecode*) y una máquina virtual de software (el intérprete) lo procesa
  línea por línea en tiempo de ejecución. Esto introduce un overhead de
  traducción constante, haciéndolo significativamente más lento pero más
  flexible.

:::
<!-- {solution} ej-compilacion-versus -->

:::{exercise}
:label: ej-tipado-seguridad
C es considerado un lenguaje "permisivo" que prioriza la velocidad sobre la
seguridad de memoria. Da un ejemplo de error común derivado de esta permisividad
que el compilador no pueda detectar en tiempo de compilación.

:::
<!-- {exercise} -->

:::{solution} ej-tipado-seguridad
:class: dropdown
Un ejemplo claro es el **desbordamiento de buffer (buffer overflow)** o el
acceso fuera de los límites de un arreglo. En C, si declarás un arreglo de
tamaño 5 y escribís en la posición 10, el compilador no realiza ninguna
verificación automática en tiempo de compilación para impedirlo. El programa
intentará escribir en esa dirección física de memoria en tiempo de ejecución, lo
que puede sobreescribir otros datos, corromper el estado del programa o provocar
un fallo de segmentación (*Segmentation Fault*).

:::
<!-- {solution} ej-tipado-seguridad -->

(ejercicios-de-autoevaluacion-hola-mundo-y-compilacion)=
### Hola Mundo y Compilación
:::{exercise}
:label: ej-holamundo-syntax
¿Qué ocurre si eliminás la directiva `#include <stdio.h>` en el código del "Hola
Mundo" e intentás compilarlo con `gcc -Wall`? ¿Por qué es una mala práctica de
ingeniería?

:::
<!-- {exercise} -->

:::{solution} ej-holamundo-syntax
:class: dropdown
El programa compilará pero emitirá una advertencia (*warning*) por **declaración
implícita de la función `printf`** (`warning: implicit declaration of function
'printf'`).
Esto ocurre porque, sin la cabecera `<stdio.h>`, el compilador no conoce la
firma de la función (los tipos de sus parámetros y su retorno) al momento de
procesar la llamada. Es una mala práctica de ingeniería porque impide que el
compilador verifique que estás pasando los tipos correctos a la función, lo cual
puede derivar en comportamientos indefinidos en tiempo de ejecución.

:::
<!-- {solution} ej-holamundo-syntax -->

:::{exercise}
:label: ej-compilation-command
Explicá el rol de la opción `-o` en el comando `gcc hola.c -o mi_programa` y qué
ocurriría si omitieras esta opción al compilar.

:::
<!-- {exercise} -->

:::{solution} ej-compilation-command
:class: dropdown
La opción `-o` (output) le indica al compilador el nombre específico que debe
tener el archivo ejecutable binario resultante.
- Con `-o mi_programa`: el compilador genera un binario ejecutable llamado
  `mi_programa` (o `mi_programa.exe` en Windows).
- Si se omite: el compilador genera el ejecutable con el nombre por defecto del
  sistema: `a.out` en sistemas de tipo Unix/Linux y `a.exe` en Windows.

:::
<!-- {solution} ej-compilation-command -->

(ejercicios-de-autoevaluacion-algoritmo-a-codigo)=
### Algoritmo a Código
:::{exercise}
:label: ej-idea-area-rectangulo
Diseñá y escribí un programa completo en C que solicite al usuario el ingreso de
la base y la altura de un rectángulo (como valores reales `float`) y muestre por
pantalla su área.

:::
<!-- {exercise} -->

:::{solution} ej-idea-area-rectangulo
:class: dropdown
El programa completo en C:
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    float base = 0.0f;
    float altura = 0.0f;
    float area = 0.0f;

    printf("Ingresá la base del rectángulo: ");
    scanf("%f", &base);
    printf("Ingresá la altura del rectángulo: ");
    scanf("%f", &altura);

    area = base * altura;

    printf("El área del rectángulo es: %.2f\n", area);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-idea-area-rectangulo -->

:::{exercise}
:label: ej-idea-intercambio
Escribí un programa en C que declare dos variables enteras `x` e `y`
inicializadas con valores arbitrarios, e intercambie sus contenidos **sin
utilizar ninguna variable auxiliar**, utilizando únicamente operaciones
aritméticas de suma y resta.

:::
<!-- {exercise} -->

:::{solution} ej-idea-intercambio
:class: dropdown
Este truco aritmético evita el uso de una variable auxiliar:
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int x = 15;
    int y = 25;

    printf("Antes del intercambio: x = %d, y = %d\n", x, y);

    x = x + y; // x ahora almacena la suma total (40)
    y = x - y; // y toma el valor original de x (40 - 25 = 15)
    x = x - y; // x toma el valor original de y (40 - 15 = 25)

    printf("Después del intercambio: x = %d, y = %d\n", x, y);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-idea-intercambio -->

(ejercicios-de-autoevaluacion-sintaxis-y-operadores)=
### Sintaxis y Operadores
:::{exercise}
:label: ej-operadores-division
Si ejecutás el siguiente código en C:
`printf("%d y %.2f\n", 17 / 3, 17.0 / 3);`
¿Qué valores se imprimirán? Justificá de manera formal la diferencia semántica
entre ambas divisiones.

:::
<!-- {exercise} -->

:::{solution} ej-operadores-division
:class: dropdown
Se imprimirá: `5 y 5.67`
La diferencia semántica radica en el tipo de los operandos:
- `17 / 3`: Ambos operandos son literales enteros (`int`). El compilador realiza
  una **división entera**, descartando la parte decimal y retornando el cociente
  entero `5`.
- `17.0 / 3`: El primer operando es un literal real (`double`). El compilador
  realiza una **promoción implícita** del segundo operando a real y efectúa una
  **división de punto flotante**, resultando en `5.66666...`, que formateado con
  `%.2f` se redondea a `5.67`.

:::
<!-- {solution} ej-operadores-division -->

:::{exercise}
:label: ej-operadores-cortocorticuito
Explicá de qué manera la evaluación de cortocircuito del operador lógico `&&`
evita un fallo de división por cero en la siguiente condición:
`if (denominador != 0 && (numerador / denominador) > 2)`

:::
<!-- {exercise} -->

:::{solution} ej-operadores-cortocorticuito
:class: dropdown
La evaluación por cortocircuito de `&&` establece que si el operando izquierdo
es falso, el resultado de la conjunción es necesariamente falso, por lo que **el
operando derecho no es evaluado**.
Si `denominador` es igual a `0`, la primera subexpresión `denominador != 0`
evalúa a `false`. El compilador aborta la evaluación del `&&` y no ejecuta la
expresión del lado derecho `(numerador / denominador) > 2`, evitando así un
error fatal de división por cero en tiempo de ejecución.

:::
<!-- {solution} ej-operadores-cortocorticuito -->

(ejercicios-de-autoevaluacion-variables-y-tipos)=
### Variables y Tipos
:::{exercise}
:label: ej-lvalue-rvalue-comp
Dadas las declaraciones `int a = 5; int b = 10;`, indicá cuáles de las
siguientes expresiones son L-values y cuáles son R-values. Si alguna de ellas
causa un error de compilación como parte de una asignación, justificá por qué:
1. `a`
2. `a + b`
3. `a = b`
4. `++a`

:::
<!-- {exercise} -->

:::{solution} ej-lvalue-rvalue-comp
:class: dropdown
1. `a`: Es un **L-value**, porque identifica una ubicación de memoria
   direccionable de almacenamiento persistente.
2. `a + b`: Es un **R-value**, porque representa el valor numérico temporal
   resultante de la suma, el cual no tiene una dirección de memoria física
   propia asignada. Intentar hacer `(a + b) = 15;` arroja un error de
   compilación.
3. `a = b`: Es un **L-value** en C, ya que la asignación misma devuelve la
   ubicación del operando izquierdo tras almacenar el valor.
4. `++a`: Es un **L-value** en C++ pero un **R-value** en C estándar (C11). En
   C, el operador de incremento devuelve un valor temporal modificado, por lo
   que no es posible aplicarle el operador de dirección (`&(++a)` es inválido en
   C).

:::
<!-- {solution} ej-lvalue-rvalue-comp -->

:::{exercise}
:label: ej-desbordamiento-int
Si declarás `int maximo = INT_MAX;` (donde `INT_MAX` es la constante del archivo
de cabecera `<limits.h>` con el máximo entero con signo representable) y
realizás `maximo = maximo + 1;`, ¿qué valor tendrá la variable en un sistema de
complemento a dos? ¿Cómo se denomina técnicamente este fenómeno?

:::
<!-- {exercise} -->

:::{solution} ej-desbordamiento-int
:class: dropdown
En un sistema estándar de complemento a dos, el valor pasará a ser el entero
mínimo representable (`INT_MIN`, que típicamente es `-2.147.483.648` para 32
bits).
Este fenómeno se denomina **desbordamiento de enteros con signo (signed integer
overflow)**. Desde el punto de vista del estándar de C, el desbordamiento de
enteros con signo produce un **comportamiento indefinido (undefined behavior)**,
aunque físicamente en la mayoría de las arquitecturas de CPU se comporta
mediante un ciclo de desbordamiento circular hacia los números negativos.

:::
<!-- {solution} ej-desbordamiento-int -->

(ejercicios-de-autoevaluacion-entrada-y-salida)=
### Entrada y Salida
:::{exercise}
:label: ej-scanf-espacio-buffer
Analizá el siguiente bloque de código. Si el usuario ingresa `25` y presiona
Enter, y luego ingresa la letra `S` y presiona Enter, explicá detalladamente el
comportamiento del buffer de entrada y el valor final de la variable `opcion`.
``` c
int edad;
char opcion;
scanf("%d", &edad);
scanf("%c", &opcion);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-scanf-espacio-buffer
:class: dropdown
1. Al ingresar `25` y presionar Enter, se deposita en el buffer de entrada
   `stdin` la secuencia de caracteres `2`, `5` y el salto de línea `\n`.
2. El primer `scanf("%d", &edad)` consume los caracteres numéricos `2` y `5`
   para asignarle `25` a la variable `edad`. El salto de línea `\n` permanece en
   el buffer de entrada.
3. El segundo `scanf("%c", &opcion)` se ejecuta y, dado que `%c` no descarta
   espacios en blanco automáticamente, lee el primer carácter disponible en el
   buffer, que es el salto de línea residual `\n`.
4. La variable `opcion` termina almacenando el valor `'\n'` (salto de línea), y
   la ejecución prosigue sin permitirle al usuario ingresar la letra `S`.

:::
<!-- {solution} ej-scanf-espacio-buffer -->

:::{exercise}
:label: ej-printf-format-real
Escribí una instrucción `printf` en C que tome una variable `float promedio =
8.567f;` y la imprima por pantalla con exactamente dos dígitos decimales,
alineada a la derecha en una columna de un ancho físico mínimo de 8 caracteres.

:::
<!-- {exercise} -->

:::{solution} ej-printf-format-real
:class: dropdown
Para especificar tanto el ancho de campo mínimo como la precisión decimal en
`printf`, debés usar el especificador `%[ancho].[precision]f`.
La instrucción correspondiente es:
``` c
float promedio = 8.567f;
printf("Valor: %8.2f\n", promedio);
```
<!-- c -->
Esto imprimirá el texto `Valor: ` seguido de cuatro espacios en blanco y los
caracteres `8.57` (el redondeo de `8.567`), sumando un ancho total de 8
caracteres.

:::
<!-- {solution} ej-printf-format-real -->

---

## Glosario

:::{glossary}
Compilador
: Herramienta de software que traduce un programa escrito en código fuente de
alto nivel a instrucciones de código máquina nativo.

Sintaxis
: Conjunto de reglas formales y gramaticales que definen la validez estructural
de un programa para el compilador.

Semántica
: Significado lógico y comportamiento operacional de las instrucciones de un
programa en tiempo de ejecución.

L-value
: Expresión que localiza un objeto persistente en memoria física, cuya dirección
puede ser obtenida.

R-value
: Expresión transitoria que representa únicamente un valor y carece de dirección
física de almacenamiento direccionable.

Buffer de entrada
: Área de almacenamiento temporal de memoria donde se retienen las entradas del
usuario hasta ser consumidas por funciones como `scanf`.
:::

---

## Síntesis y Resumen

En esta unidad introductoria de C analizaste los siguientes fundamentos:
- **Filosofía de C**: Lenguaje de nivel medio, imperativo, estructurado y
  altamente eficiente que prioriza el acceso directo al hardware.
- **Ciclo de Traducción**: Compilación explícita que transforma el código fuente
  íntegramente a binarios ejecutables nativos.
- **Declaración y Roles**: La memoria de las variables requiere inicialización
  explícita, existiendo roles funcionales (entrada, salida, auxiliar).
- **Entrada y Salida**: Uso básico de `printf` y `scanf` con especificadores de
  formato, contemplando los efectos colaterales de saltos de línea residuales en
  el buffer.

Para continuar con el control de flujo condicional y los lazos iterativos,
consultá {ref}`capitulo-control-flujo`.

---

## Referencias y Lecturas Complementarias

- Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language* (2nd
  ed.). Prentice Hall.
- ISO/IEC 9899 standard drafts (C99, C11, C18, C2y).
- GCC, GNU Compiler Collection - Command Options
  (https://gcc.gnu.org/onlinedocs/).
