---
title: Compilación
short_title: Compilación
subtitle: Haciendonos entender por la computadora.
---

(capitulo-compilacion)=
## Introducción

Cuando ejecutás en tu terminal el comando:

```{code-block} sh

$> gcc -o mi_programa programa.c

```
<!-- {code-block} sh -->

No solo estás invocando un programa, sino que desencadenás un sofisticado
proceso de transformación. A simple vista, es una única instrucción que
convierte tu código fuente, escrito en un lenguaje comprensible para vos, en un
archivo ejecutable que la máquina puede interpretar directamente.

:::{note} Prerequisitos

Este capítulo asume que ya escribiste y ejecutaste programas básicos en C como
los presentados en el [](../bloque_1_fundamentos/2_gradual.md). También es útil tener familiaridad con
el concepto de funciones ([](../bloque_1_fundamentos/4_funciones.md)) ya que se mencionan prototipos y
definiciones en el contexto de compilación de múltiples archivos.

:::
<!-- {note} Prerequisitos -->

Sin embargo, detrás de esa aparente simplicidad, el compilador `gcc` (GNU
Compiler Collection) actúa como un director de orquesta, coordinando una
secuencia de herramientas especializadas que trabajan en conjunto. Cada una de
estas herramientas se encarga de una fase específica, traduciendo
progresivamente el código hasta su forma final.

Comprender esta transformación del código, desde `programa.c` hasta
`mi_programa`, es una habilidad fundamental para cualquier desarrollador de C.
Te proporciona las bases para diagnosticar errores de compilación complejos,
optimizar el rendimiento de tus aplicaciones y gestionar eficientemente
proyectos que se componen de múltiples archivos fuente.

(diagrama-del-proceso)=

## Desarrollo

(proceso-de-compilacion-en-c)=
### Proceso de compilación en C
#### Diagrama del Proceso

El flujo de transformación desde tu código fuente hasta un programa ejecutable
se puede visualizar de la siguiente manera:


```{figure} 1/proceso_compilacion.svg
:label: fig-proceso-compilacion
:align: center
:width: 90%

Fases físicas del proceso de compilación separada. Se muestra la transformación desde archivos fuente independientes `.c` y cabeceras `.h` hacia código objeto `.o` y su posterior unión en el binario ejecutable final por el Linker.
```

(fase-1-preprocesado-preprocessing)=
#### Fase 1: Preprocesado (Preprocessing)

Esta es la etapa inicial del proceso de compilación. Su función es transformar
tu código fuente antes de que el compilador propiamente dicho comience su
análisis. El preprocesador opera a un nivel textual: no comprende la sintaxis o
la semántica de C, sino que se limita a interpretar y ejecutar directivas, que
son instrucciones especiales identificadas por el carácter inicial `#`.

Podés pensar en el preprocesador como un asistente que prepara y limpia el
código, resolviendo inclusiones de archivos, expandiendo abreviaturas (macros) y
seleccionando fragmentos de código según ciertas condiciones, antes de
entregárselo al compilador.

##### Tareas del preprocesador

##### Inclusión de Cabeceras **Directiva:** `#include`

Esta directiva le ordena al preprocesador que reemplace la línea
`#include <archivo.h>` o `#include "archivo.h"` por el contenido íntegro del
archivo de cabecera especificado. Es el mecanismo fundamental para incorporar
bibliotecas estándar (como `stdio.h` para funciones de entrada/salida como
`printf`) o tus propios módulos de código.

- `#include <archivo.h>`: Busca el archivo en los directorios de inclusión
  estándar del sistema.
- `#include "archivo.h"`: Busca primero en el directorio actual y luego en los
  directorios estándar.

##### Expansión de Macros **Directiva:** `#define`

Permite definir "macros", que son fragmentos de texto o código que se sustituyen
en el fuente antes de la compilación. Es una herramienta poderosa para definir
constantes o pequeñas funciones "inline".

- **Constantes simbólicas**: Si definís `#define PI 3.14159`, cada vez que
  aparezca `PI` en el código, el preprocesador lo reemplazará textualmente por
  `3.14159`.
- **Macros con parámetros**: Podés crear macros que se asemejan a funciones,
  como `#define SUMA(a, b) ((a) + (b))`.

:::{warning} Efectos Colaterales en Macros

Las macros realizan una sustitución de texto literal. Esto genera dos peligros
principales:
1. **Orden de operaciones**: Si no se usan paréntesis para proteger los
   argumentos y la expresión completa, el orden de evaluación puede verse
   alterado.
2. **Evaluación múltiple (efectos colaterales)**: Si un parámetro se evalúa más
   de una vez dentro de la macro, pasar expresiones con efectos secundarios
   (como `x++`) provocará un comportamiento incorrecto. Por ejemplo, con una
   macro `MAX(a, b)` definida como `((a) > (b) ? (a) : (b))`, la llamada
   `MAX(x++, y)` incrementará `x` dos veces si `x > y`.

:::
<!-- {warning} Efectos Colaterales en Macros -->

###### Compilación Condicional **Directivas:** `#if`, `#ifdef`,

`#ifndef`, `#else`, `#elif`, `#endif`

Estas directivas permiten que el preprocesador incluya o excluya porciones de
código del archivo fuente final que se pasará al compilador. Son extremadamente
útiles para:

- **Portabilidad**: Escribir código que se compila de manera diferente según el
  sistema operativo o la arquitectura.
- **Depuración**: Incluir código de depuración (por ejemplo, impresiones en
  consola) solo cuando se define una macro específica como `DEBUG`.
- **Guardas de cabecera**: Evitar la doble inclusión de archivos de cabecera, un
  problema común en proyectos grandes, utilizando una estructura como la que
  exige la regla {ref}`0x300Fh`:

  ```{code-block} c
  #ifndef MI_CABECERA_H
  #define MI_CABECERA_H

  // Contenido de la cabecera...

  #endif // MI_CABECERA_H
  ```

###### Eliminación de Comentarios

El preprocesador también se encarga de una tarea de limpieza fundamental:
eliminar todo el texto que se encuentre dentro de los bloques de comentarios
`/* ... */` y todo lo que siga aun comentario de una sola línea `//`. Esto
reduce el "ruido" y entrega al compilador únicamente el código que debe
analizar.

##### ¿Cómo verlo en acción?

Para aislar y examinar el resultado de esta fase, podés indicarle a `gcc` que se
detenga justo después del preprocesado. Esto se logra con la opción `-E`. El
resultado es el código fuente "expandido", que normalmente se redirige a un
archivo con extensión `.i`.

```{code-block} sh

$> gcc -E programa.c > programa.i

```
<!-- {code-block} sh -->

El archivo `programa.i` es un archivo de texto plano que contiene tu código
original, pero con todas las cabeceras incluidas, las macros expandidas, los
comentarios eliminados y las condiciones resueltas. Revisar este archivo es una
técnica de depuración excelente cuando sospechás que un error se origina en una
macro mal definida o en una inclusión de archivo incorrecta.

(etapa-2-compilacion)=
#### Etapa 2: Compilación

Esta es la fase central del proceso, donde el compilador (como `gcc`) toma el
código C preprocesado y lo traduce a un lenguaje de mucho más bajo nivel: el
lenguaje ensamblador (Assembly). Este lenguaje no es universal; es específico
para la arquitectura del procesador de destino (por ejemplo, x86-64, ARM,
RISC-V).

El compilador no solo traduce, sino que también analiza y optimiza el código.
Este proceso se puede descomponer en varias sub-fases:

:::{figure} 1/fases_compilador.svg
:name: fig-fases-compilador
:width: 90%

Fases del compilador divididas en Frontend (análisis léxico, sintáctico y
semántico) y Backend (generación de código intermedio, optimización y código
ensamblador).

:::
<!-- {figure} 1/fases_compilador.svg -->

##### Análisis Léxico y Sintáctico

El compilador primero descompone el código fuente en tokens (palabras clave,
identificadores, operadores) y luego verifica que la secuencia de estos tokens
siga las reglas gramaticales del lenguaje C, construyendo una estructura de
árbol conocida como Árbol de Sintaxis Abstracta (AST). Si olvidás un punto y
coma, las llaves no coinciden o una instrucción está mal formada, el proceso
falla aquí.

##### Análisis Semántico

Una vez que la sintaxis es correcta, el compilador verifica la coherencia
semántica. Se asegura de que las variables estén declaradas antes de usarse, que
los tipos de datos sean compatibles en las operaciones (no podés sumar un número
a una `struct`, por ejemplo) y que las llamadas a funciones coincidan con sus
declaraciones.

##### Optimización

Esta es una de las tareas más importantes del compilador. Transforma el código
para que sea más eficiente o más pequeño en tamaño, sin cambiar su
comportamiento. Las optimizaciones pueden incluir la eliminación de código
muerto, el desenrollado de lazos (loop unrolling) o la inserción de funciones
en línea (inlining).

##### Generación de Código

Finalmente, el código optimizado se traduce a las instrucciones específicas del
lenguaje ensamblador para la arquitectura de destino. Cada línea de código C se
convierte en una o más instrucciones de ensamblador que el procesador puede
entender.

::::{tip} ¿Cómo verlo en acción?
:class: dropdown

Podés instruir a `gcc` para que se detenga después de la fase de compilación con
la opción `-S`. Esto generará un archivo de texto con la extensión `.s` que
contiene
el código ensamblador correspondiente.

Si partimos de un archivo `programa.c` simple:

```{code-block} c

// programa.c
int suma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = suma(5, 3);
    return 0;
}

```
<!-- {code-block} c -->

Al ejecutar el comando especificando la sintaxis Intel (para coincidir con el
ejemplo):

```{code-block} bash

gcc -S -masm=intel programa.c

```
<!-- {code-block} bash -->

Se creará un archivo `programa.s`. Su contenido en sintaxis Intel será similar a
este (puede
variar según el compilador y la arquitectura):

```{code-block} assembler

; programa.s (ejemplo para x86-64)
suma:
    push    rbp
    mov     rbp, rsp
    mov     DWORD PTR [rbp-4], edi  ; Mueve el primer parámetro (a) a la pila
    mov     DWORD PTR [rbp-8], esi  ; Mueve el segundo parámetro (b) a la pila
    mov     edx, DWORD PTR [rbp-4]
    mov     eax, DWORD PTR [rbp-8]
    add     eax, edx                ; Suma los dos valores
    pop     rbp
    ret                             ; Retorna el resultado (en el registro eax)

main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    mov     esi, 3                  ; Prepara el segundo argumento para suma()
    mov     edi, 5                  ; Prepara el primer argumento para suma()
    call    suma                    ; Llama a la función suma
    mov     DWORD PTR [rbp-4], eax  ; Guarda el resultado
    mov     eax, 0                  ; Valor de retorno para main
    leave
    ret

```
<!-- {code-block} assembler -->

Analizar este archivo es una excelente manera de entender cómo tus
construcciones de C se traducen a operaciones de bajo nivel y cómo el compilador
aplica las convenciones de llamadas de la arquitectura.

::::
<!-- {tip} ¿Cómo verlo en acción? -->

En el ejemplo x86-64 anterior bajo Linux, se observa la aplicación de la
convención de llamadas estándar **System V AMD64 ABI**:
1. **Paso de parámetros por registros:** A diferencia de las arquitecturas
   antiguas de 32 bits que transferían los parámetros mediante la pila, aquí los
   primeros argumentos de tipo entero se transmiten a través de registros de la
   CPU: `edi` alberga el primer parámetro (`a`) y `esi` alberga el segundo
   (`b`).
2. **Reserva y gestión del Marco de Pila (Stack Frame):**
   - En la función `suma`, la secuencia `push rbp` y `mov rbp, rsp` resguarda el
     puntero base del invocador y establece la base del marco actual (`rbp`),
     sirviendo como referencia para direccionar variables locales y parámetros
     respaldados (`[rbp-4]` y `[rbp-8]`).
   - En `main`, la instrucción `sub rsp, 16` desplaza el puntero de pila (`rsp`)
     reservando 16 bytes de espacio local, manteniendo a su vez la alineación de
     pila requerida por la ABI antes de realizar una llamada a función.
3. **Retorno de resultados:** Por convención, el valor de retorno de la función
   se deposita en el registro acumulador `eax`, de donde `main` lo recupera tras
   ejecutarse la instrucción `ret` (retorno).








---

(archivos-de-cabecera-h-en-c)=
### Archivos de Cabecera (`.h`) en C

Un archivo de cabecera (o `header`) en C actúa como un contrato o una interfaz
pública para un módulo de código. Su función principal es declarar los elementos
(como funciones y _tipos de datos_) que estarán disponibles para otros archivos
fuente que lo incluyan, sin exponer los detalles de su implementación.

(propositos-fundamentales)=
#### Propósitos Fundamentales

Los archivos de cabecera son cruciales para un desarrollo de software
estructurado y modular en C. Sus principales beneficios son:

- Organización del código

Agrupan declaraciones relacionadas, facilitando la navegación y comprensión de
la arquitectura de un proyecto. Por ejemplo, todas las funciones para manejar
una estructura de datos específica se declaran en un mismo `header`.

- Reutilización

Permiten que un mismo conjunto de funciones y tipos de datos sea utilizado en
múltiples partes de un programa (o en diferentes programas) simplemente
incluyendo el archivo `.h` correspondiente. Esto evita la duplicación de código.

- Separación de interfaz e implementación

Este es uno de los principios más importantes. El archivo `.h` define _qué_ hace
un módulo (la interfaz), mientras que el archivo `.c` correspondiente define
_cómo_ lo hace (la implementación). Esto permite modificar la implementación sin
que los archivos que utilizan el módulo necesiten ser cambiados, siempre y
cuando la interfaz (el `.h`) permanezca constante.

(que-suelen-contener)=
#### ¿Qué suelen contener?

Un archivo de cabecera puede contener varias clases de declaraciones, pero nunca
debería contener definiciones de funciones (cuerpos de código) o
definiciones/inicializaciones de variables globales.

Esto se debe a la **Regla de Definición Única** (*One Definition Rule* o *ODR*).
Si definís una función o una variable global en un archivo `.h`, y luego incluís
ese encabezado en múltiples archivos fuente `.c` (que compilan por separado para
generar distintos archivos de objeto `.o`), la misma función o variable se
definirá físicamente en múltiples unidades de traducción. Al final del proceso,
el enlazador (*linker*) fallará con un error del tipo `multiple definition
of...` o `symbol redefined`, ya que el sistema es incapaz de decidir a cuál de
todas las definiciones idénticas enlazar el programa. En su lugar, el archivo
`.h` solo debe declarar la existencia de los elementos (por ejemplo, mediante
prototipos de funciones o variables con el calificador `extern`), y el archivo
`.c` correspondiente debe definirlos una única vez.

##### Prototipos de Funciones

Es el contenido más común. Se declara la firma de la función (tipo de retorno,
nombre y parámetros) para que el compilador conozca su existencia antes de que
sea utilizada. Una buena documentación, como la que pide la regla
{ref}`0x000Ah`, es fundamental.

```{code-block} c
:caption: Documentación de prototipos con estilo Doxygen
/**
 * @brief Calcula la suma de dos números enteros.
 *
 * Esta función recibe dos enteros como entrada y devuelve
 * el resultado de su adición.
 *
 * @param n El primer sumando.
 * @param m El segundo sumando.
 * @return La suma de n y m.
 */
int suma(int n, int m);

```
<!-- {code-block} c -->

##### Definiciones de Macros

Se utilizan para definir constantes simbólicas o pequeñas porciones de código
que se expanden durante el preprocesamiento.

```{code-block} c
:caption: Definición de constantes y macros

// Constante matemática documentada.
#define PI 3.1415926535

```
<!-- {code-block} c -->

##### Definiciones de Tipos y Estructuras

Es el lugar ideal para declarar `struct`, `enum` y `typedef`, ya que estos tipos
de datos a menudo necesitan ser compartidos entre varios archivos. El uso del
sufijo `_t` para los tipos definidos con `typedef` sigue la regla
{ref}`0x3004h`.

_(Estos conceptos serán tratados más adelante en la cátedra.)_

```{code-block} c
:caption: Declaración de un nuevo tipo de dato

// Define una estructura para representar un punto en 2D.
typedef struct {
    float x;
    float y;
} punto2D_t;

// Enum para representar los días de la semana.
typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
} DiaDeLaSemana;

```
<!-- {code-block} c -->

##### Declaraciones de Variables Globales

Si necesitás compartir una variable global entre varios archivos, la declarás en
el `.h` usando la palabra clave `extern` y la definís (le das un valor inicial)
en _un único_ archivo `.c`. Esta práctica está desaconsejada por la regla
{ref}`0x2004h`.

```{code-block} c
:caption: Declaración de una variable global externa
:emphasize-lines: 3

// Declara que la variable 'errno' existe en alguna parte del programa.
// La definición real se encuentra en la biblioteca estándar.
extern int errno;

```
<!-- {code-block} c -->

(guardas-de-inclusion)=
#### Guardas de Inclusión

Para evitar errores de "redefinición" que ocurren cuando un mismo archivo de
cabecera es incluido más de una vez en la misma unidad de compilación (archivo
`.c`), se utilizan las "guardas de inclusión", una técnica exigida por la regla
de estilo {ref}`0x5003h`.

:::{warning} Prohibición de Definiciones en Cabeceras

El archivo de cabecera `.h` actúa como un **contrato de interfaz pública** y solo debe contener declaraciones (firmas de funciones, prototipos, macros y definiciones de tipos). Está estrictamente prohibido definir variables (por ejemplo, `int mi_global = 10;`) o cuerpos de funciones ejecutables en una cabecera. Si violás esta directiva, cuando múltiples archivos `.c` incluyan ese `.h`, el compilador generará múltiples copias físicas de la función o variable en cada archivo objeto `.o`. Al final, el enlazador (Linker) fallará con un error del tipo `multiple definition of...` debido a la violación de la regla de definición única (*One Definition Rule*).

:::

La técnica estándar utiliza directivas del preprocesador para verificar si un
símbolo único ya fue definido. Si no lo fue, define el símbolo e incluye el
contenido del archivo.

```{code-block} c
:caption: Estructura de una guarda de inclusión
:label: inclusion-guard

// 1. Verifica si MATH_OPERATIONS_H NO ha sido definido.
#ifndef MATH_OPERATIONS_H
// 2. Si no fue definido, se define ahora.
#define MATH_OPERATIONS_H

// ----------------------------------------------------
// Aquí va todo el contenido del archivo de cabecera:
// prototipos documentados, macros, typedefs, etc.

#define PI 3.14159

int suma(int n, int m);

// ----------------------------------------------------

// 3. Fin del bloque condicional.
#endif // MATH_OPERATIONS_H

```
<!-- {code-block} c -->

:::{important} Cuestión de estilo

Aunque un archivo contenga únicamente prototipos de funciones (cuya
redeclaración no es un error), es una **buena práctica universal** y un
**requisito de la cátedra** es que **todos** los archivos de cabecera que
ustedes creen incluyan guardas de inclusión. Esto asegura consistencia,
prolijidad y previene errores futuros si el contenido del archivo cambia.

:::
<!-- {important} Cuestión de estilo -->









---

(fase-3-ensamblado-assembly)=
### Fase 3: Ensamblado (Assembly)

Esta fase actúa como el traductor final entre un lenguaje simbólico de bajo
nivel y el lenguaje nativo de la máquina. El **ensamblador** toma el código en
lenguaje ensamblador, que todavía utiliza mnemónicos legibles por humanos (como
`mov`, `add`, `jmp`), y lo convierte en **código máquina**: las instrucciones
binarias puras que el procesador puede ejecutar directamente.

Cada arquitectura de procesador (como x86-64, ARM, MIPS) tiene su propio y único
conjunto de instrucciones de máquina. Por lo tanto, el código ensamblador
generado en la fase anterior es específico para la arquitectura de destino, y el
ensamblador realiza la traducción final para esa plataforma concreta.

##### Tareas Principales del Ensamblador

El ensamblador, invocado internamente por `gcc`, realiza una tarea fundamental:

- **Traducción de Mnemónicos a Opcodes**: Convierte cada instrucción del
  lenguaje ensamblador a su correspondiente **código de operación** (opcode)
  binario. Por ejemplo, la instrucción `movq %rax, %rbx` se traduce en una
  secuencia específica de bytes que el CPU interpreta como "copiar el contenido
  del registro RAX al registro RBX".

- **Resolución de Direcciones Simbólicas**: Reemplaza las etiquetas y nombres de
  variables dentro del archivo (`.s`) por sus direcciones de memoria relativas
  dentro del archivo de salida.

- **Generación del Archivo Objeto**: El resultado de este proceso se empaqueta y
  guarda en un **archivo objeto**, que por convención tiene la extensión `.o`.

##### El Archivo Objeto: Más que solo Código Máquina

Un error común es pensar que un archivo `.o` es simplemente un volcado del
código binario. En realidad, es un archivo con una estructura bien definida
(comúnmente en formato **ELF**, _Executable and Linkable Format_, en sistemas
Linux) que contiene varias piezas de información cruciales para la siguiente y
última fase:

- **Sección de Texto (`.text`)**: Contiene las instrucciones de máquina
  compiladas de tu código.
- **Sección de Datos (`.data` y `.bss`)**: Almacena las variables globales y
  estáticas. La sección `.data` guarda las variables inicializadas
  explícitamente y consume espacio en el archivo en disco. Por el contrario, la
  sección `.bss` se reserva para las variables no inicializadas (o inicializadas
  a cero) y **no ocupa espacio real en el archivo objeto ELF en disco**, sino
  que solo registra el tamaño requerido para que el cargador reserve la memoria
  correspondiente al momento de la ejecución.
- **Tabla de Símbolos**: Un índice de todas las funciones y variables globales
  que el archivo define y que pueden ser utilizadas por otros archivos objeto
  (símbolos "exportados"), así como una lista de los símbolos que utiliza, pero
  que no define (como `printf`), los cuales espera que otro archivo objeto o
  biblioteca le proporcione (símbolos "importados" o "externos").
- **Información de Reubicación**: Datos que indican al enlazador (linker) cómo
  modificar el código máquina para que las llamadas a funciones y el acceso a
  variables apunten a las direcciones de memoria correctas una vez que todos los
  archivos objeto se combinen.

Por esta razón, un archivo objeto no es ejecutable por sí mismo. Es un módulo de
código máquina autocontenido, pero con "huecos" o "referencias sin resolver" que
deben ser completados por el enlazador.

##### ¿Cómo verlo en acción?

La opción `-c` de `gcc` es una de las más importantes en el desarrollo de
software, ya que detiene el proceso de compilación justo después de la fase de
ensamblado, generando únicamente el archivo objeto.

```{code-block} sh

$> gcc -c programa.c

```
<!-- {code-block} sh -->

Este comando creará el archivo `programa.o` en el mismo directorio.

::::{tip} La Importancia de la Compilación Separada

En proyectos que constan de múltiples archivos fuente (`modulo1.c`, `modulo2.c`,
`main.c`), no se compila todo el proyecto de una sola vez. En su lugar, se
compila cada archivo `.c` por separado para generar su correspondiente archivo
`.o`:

```{code-block} sh

$> gcc -c modulo1.c   # Genera modulo1.o
$> gcc -c modulo2.c   # Genera modulo2.o
$> gcc -c main.c      # Genera main.o

```
<!-- {code-block} sh -->

Si luego modificás solo `modulo1.c`, únicamente necesitás recompilar ese archivo
para generar un nuevo `modulo1.o`. Los demás archivos objeto no se tocan. El
paso final consiste en enlazar todos los `.o` (el nuevo y los antiguos) para
crear el ejecutable. Este principio de **compilación separada** es la base de
los sistemas de construcción como `make` y ahorra una cantidad inmensa de tiempo
en proyectos grandes.

::::
<!-- {tip} La Importancia de la Compilación Separada -->

(fase-4-enlazado-linking)=
### Fase 4: Enlazado (Linking)

Esta es la culminación del proceso de compilación, la fase donde todas las
piezas de código máquina, previamente compiladas de forma aislada, se ensamblan
para formar un único archivo ejecutable. El programa responsable de esta tarea
es el **enlazador** (o _linker_), invocado por `gcc` bajo el nombre de `ld`.

El enlazador toma uno o más archivos objeto (`.o`) y las bibliotecas de código
necesarias, y los combina para producir el archivo final que el sistema
operativo puede cargar en memoria y ejecutar. Su misión principal es resolver
las referencias cruzadas entre los distintos módulos de código.

#### Tareas Principales del Enlazador

##### Resolución de Símbolos

Esta es la tarea más crítica del enlazador. Cada archivo objeto tiene una "tabla
de símbolos" que lista las funciones y variables que define (símbolos
exportados) y aquellas que utiliza, pero que están definidas en otro lugar
(símbolos importados o externos).

El enlazador recorre los archivos objeto y:

1.  Identifica todos los símbolos externos (por ejemplo, una llamada a `printf`
    en `main.o`).
2.  Busca la definición de esos símbolos en los otros archivos objeto o en las
    bibliotecas que se le proporcionen (como la biblioteca estándar de C,
    `libc`).
3.  Una vez que encuentra la definición, reemplaza la referencia simbólica en el
    código máquina con la dirección de memoria real donde residirá esa función o
    variable. Si no puede encontrar la definición de un símbolo referenciado, el
    proceso de enlazado falla con un error de "símbolo no definido" (_undefined
    symbol_).

##### Combinación y Reubicación

El enlazador fusiona las secciones del mismo tipo de todos los archivos objeto
de entrada. Por ejemplo, combina todas las secciones `.text` (código máquina) en
una única sección `.text` en el archivo ejecutable final. Lo mismo ocurre con
las secciones `.data` (datos inicializados) y `.bss` (datos no inicializados).

Durante este proceso, ajusta las direcciones de memoria en el código para que
apunten a las ubicaciones finales correctas dentro del ejecutable. Este ajuste
se conoce como **reubicación**.

#### Enlazado Estático vs. Dinámico

El enlazador puede incorporar el código de las bibliotecas de dos maneras:

- **Enlazado Estático**: El código máquina de las funciones de la biblioteca
  (como `printf`) se copia directamente desde la biblioteca estática (`.a`) y se
  integra en el archivo ejecutable final. Esto crea un ejecutable más grande
  pero completamente autocontenido, que no depende de que las bibliotecas
  existan en el sistema donde se ejecuta.

- **Enlazado Dinámico (por defecto)**: En lugar de copiar el código, el
  enlazador simplemente deja una referencia en el ejecutable a la biblioteca
  compartida (`.so` en Linux, `.dll` en Windows). Cuando el sistema operativo
  carga el programa, también carga las bibliotecas compartidas necesarias en
  memoria y resuelve los símbolos en tiempo de ejecución. Esto produce
  ejecutables más pequeños y permite que múltiples programas compartan la misma
  copia de una biblioteca en memoria, ahorrando recursos.

(como-verlo-en-accion)=
#### ¿Cómo verlo en acción?

El enlazado es el paso final y automático que `gcc` realiza si no se le indica
que se detenga antes con las opciones `-E`, `-S` o `-c`.

Si ya tenés un archivo objeto compilado, podés invocar explícitamente la fase de
enlazado de la siguiente manera:

```{code-block} sh

# Asumiendo que ya existe programa.o
$> gcc -o mi_programa programa.o

```
<!-- {code-block} sh -->

Este comando le dice a `gcc` que use `programa.o` como entrada para el
enlazador, resuelva cualquier símbolo externo (buscando en la biblioteca
estándar de C por defecto) y genere el ejecutable `mi_programa`.

Por supuesto, el comando original que inicia todo el proceso desde el principio
también realiza este paso al final:

```{code-block} sh

# El comando completo que ejecuta las cuatro fases en secuencia
$> gcc -o mi_programa programa.c

```
<!-- {code-block} sh -->

(opciones-del-compilador-recomendadas)=
### Opciones del Compilador Recomendadas

Usar `gcc` sin opciones es desaprovechar su potencial para ayudarte a escribir
mejor código. Las siguientes opciones, exigidas por la regla {ref}`0x300Eh`, son
altamente recomendadas en un entorno
académico y profesional:

- `-Wall`: Activa un conjunto de advertencias (_warnings_) comunes y muy útiles.
  Te avisará de cosas como variables no utilizadas o funciones que no retornan
  un valor cuando deberían.
- `-Wextra`: Activa otro conjunto de advertencias que no están incluidas en
  `-Wall`. Es aún más estricto.
- `-Werror`: Convierte todas las advertencias en errores fatales. Esto te obliga
  a solucionar cada problema que el compilador señala, fomentando un código más
  limpio y seguro. Es una práctica estándar en entornos de desarrollo serios.
- `-std=c23`: Especifica la versión del estándar de C que querés usar. Esto
  asegura que tu código sea portable y no dependa de extensiones específicas de
  un compilador. Nota: El flag `-std=c23` exige compiladores modernos (GCC 13+).
  Si tu compilador es más antiguo y no lo soporta, podés usar `-std=c2x` o, en
  su defecto, `-std=c11` como fallback.
- `-g`: Incluye información de depuración en el ejecutable. Es **esencial** para
  poder usar un depurador como `gdb` y analizar tu programa paso a paso.
- `-O2`: Activa un alto nivel de optimización de código. No se recomienda usarlo
  mientras desarrollás o depurás, ya que el proceso de mejorar la velocidad del
  código puede reorganizar las instrucciones y hacer la depuración confusa, pero
  sí es recomendable para la versión final de tu programa. Mientras trabajamos
  en desarrollar nuestros programas, es obligatorio usar `-O0`, que desactiva
  toda optimización.
- `-fanalyzer`: Activa un analizador estático más avanzado integrado en `gcc`.
  Puede detectar problemas más complejos que las advertencias normales, como
  posibles fugas de memoria, dobles liberaciones de memoria (double free) o el
  uso de punteros nulos. Es una herramienta muy potente para mejorar la robustez
  del código.

Un comando de compilación robusto para desarrollo se vería así:

```{code-block} shell

$> gcc -Wall -Wextra -Werror -std=c23 -O0 -g -o mi_programa programa.c

```
<!-- {code-block} shell -->

Aunque es un montón, a continuación, vamos a ver cómo hacer que esto sea más
simple y no dependa de que nos acordemos este conjunto de opciones _cada vez_
que sea necesario compilar un programa.

(documentacion-oficial)=
#### Documentación Oficial

[Manual en línea de GCC](https://gcc.gnu.org/onlinedocs/). La fuente definitiva
sobre todas las opciones y el funcionamiento del compilador.


(makefiles)=
### Makefiles

Hay una guia mucho más detallada para quienes quieran entender cómo funcionan
los [makefiles](../extras/makefiles).

(que-es-un-makefile)=
#### ¿Qué es un Makefile?

`make` es una utilidad que automatiza el proceso de compilación de un programa a
partir de su código fuente. Funciona modelando el proyecto como un **grafo de
dependencias** (un grafo dirigido donde los nodos representan archivos y las
aristas representan relaciones de dependencia) y leyendo un archivo especial
llamado `Makefile` que define estas reglas. Su principal ventaja es la
**compilación incremental**: a partir del grafo, `make` determina qué archivos
han sido modificados desde la última compilación y recompila únicamente lo
necesario, ahorrando una cantidad significativa de tiempo en proyectos grandes.

La herramienta se utiliza indicando que necesitamos para lograr un determinado
objetivo, qué ingredientes hay que preparar antes.

En este ejemplo, para crear el programa ejecutable `programa`, son necesarios
`main.c` y `funciones.c`.

```{code-block} makefile

# Variables para el compilador, flags y archivos
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c23 -O0 -g
TARGET = programa
OBJS = main.o funciones.o

# Regla por defecto: construye el programa principal
all: $(TARGET)

# Regla de ENLACE (Linking): Crea el ejecutable a partir de los objetos.
# Se ejecuta solo si alguno de los .o es más nuevo que el ejecutable.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Reglas de COMPILACIÓN: Convierten cada .c en un .o
main.o: main.c funciones.h
	$(CC) $(CFLAGS) -c main.c -o main.o

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c -o funciones.o

# Objetivo "phony" para limpieza (no corresponde a un archivo real)
.PHONY: clean all

clean:
	# Elimina los archivos generados para empezar de cero.
	rm -f $(TARGET) $(OBJS)

```
<!-- {code-block} makefile -->

:::{attention} Indentación

Los _Makefiles_ deben ser indentados con tabulaciones, ya que si usamos
espacios,
fallará.

:::
<!-- {attention} Indentación -->

(estructura-basica-de-un-tp-con-proyecto)=
#### Estructura básica de un TP con proyecto

Como aprender a crear Makefiles no es parte de los temas críticos de la cátedra,
hemos construido una estructura de proyecto que los utiliza y que nos permite
desarrollar las prácticas de una forma más profesional.

- `make`: compila todo
- `make clean`: limpia todos los archivos generados
- `make test`: compila y ejecuta pruebas en `prueba.c`
- `make run`: compila y ejecuta el programa en `main.c`

La tarea del Makefile de la raíz del proyecto, es conectar a todos los de los
### Makefiles e Integración

Para proyectos que constan de múltiples archivos fuentes, realizar la
compilación manualmente en la terminal resulta insostenible. Se emplea la
utilidad `make` para automatizar este flujo.

Para un análisis detallado sobre cómo configurar y escribir las reglas de
dependencias de un archivo de configuración para compilar de forma incremental,
consultá el capítulo específico de {ref}`capitulo-makefiles-basico`.

---

(argumentos-de-la-linea-de-comandos)=
### Argumentos de la Línea de Comandos

Una vez que el programa se compila, puede recibir información directamente desde
la terminal a través de los argumentos de `main`. Este mecanismo completa el
ciclo compilación-ejecución visto en este capítulo.

(los-parametros-main-int-argc-char-argv)=
### Los parámetros `main(int argc, char *argv[])`

Cuando ejecutás un programa en C desde la terminal, tenés la posibilidad de
pasarle información directamente en la línea de comandos. Esta información,
conocida como "argumentos", es recibida por la función `main` a través de dos
parámetros especiales: `argc` y `argv`.

:::{note} Prerequisitos

Este capítulo asume conocimiento de arreglos
([](../bloque_3_memoria_estatica/2_secuencias.md)) y punteros
([](../bloque_3_memoria_estatica/4_punteros.md)), ya que `argv` es un arreglo
de punteros a cadenas (`char *argv[]`). Si estos conceptos no están claros,
repasalos antes de continuar.

:::
<!-- {note} Prerequisitos -->

Entender cómo manipular estos parámetros es fundamental para crear herramientas
de línea de comandos flexibles y potentes. Y aunque es opcional, entender como
funciona la terminal termina siendo importante para lograr que nuestros
programas se integren a la perfección.

La signatura estándar de la función `main` que acepta argumentos es la
siguiente:

:::{code-block}c

int main(int argc, char *argv[]) {
    // Tu código aquí
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

Estos dos parámetros contienen toda la información que se pasa al programa en el
momento de su ejecución.

:::{list-table} Descripción de los parámetros
:header-rows: 1
:label: tabla-argc-argv

* - Parámetro
  - Tipo
  - Descripción
* - `argc`
  - `int`
  - **Argument Count**: Es un entero que contiene el número total de argumentos
    pasados al programa. Su valor es siempre al menos 1, ya que el primer
    argumento es el propio nombre del ejecutable.
* - `argv`
  - `char *[]`
  - **Argument Values**: Es un array de punteros a cadenas de caracteres
    (strings). Cada elemento del array apunta a uno de los argumentos.
    - `argv[0]` es el nombre con el que se invocó el programa.
    - `argv[1]` es el primer argumento real.
    - ...
    - `argv[argc - 1]` es el último argumento.
    - `argv[argc]` es un puntero nulo (`NULL`), garantizado por el estándar de
      C.

:::
<!-- {list-table} Descripción de los parámetros -->

:::{figure} 1/argc_argv_estructura.svg
:label: fig-argc-argv-estructura
:align: center

Estructura en memoria de `argc` y `argv[]`. El arreglo `argv` contiene punteros
a cadenas de caracteres (strings), cada una representando un argumento pasado al
programa.

:::
<!-- {figure} 1/argc_argv_estructura.svg -->

(ejemplo-basico-imprimir-todos-los-argumentos)=
### Ejemplo Básico: Imprimir Todos los Argumentos

El programa más simple para entender su funcionamiento es uno que recorre los
valores en `argv` e imprime cada uno de sus elementos.

```{code-block} c
:caption: "Programa que itera e imprime sus argumentos."
:label: "c-print-args"
:linenos:

#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS

int main(int argc, char *argv[]) {
    printf("El programa se ejecutó con el nombre: %s\n", argv[0]);
    printf("Número total de argumentos: %d\n", argc);
    printf("----------------------------------------\n");

    // Iteramos desde el argumento 1, ya que el 0 es el nombre del programa
    if (argc > 1) {
        printf("Los argumentos proporcionados son:\n");
        for (int i = 1; i < argc; i++) {
            printf("  Argumento %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No se proporcionaron argumentos adicionales.\n");
    }

    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

(compilacion-y-ejecucion)=
#### Compilación y ejecución

Si guardás el código anterior como `main_args.c` y lo compilás, podés ver la
salida al ejecutarlo con distintos argumentos.

```{code-block} bash
:linenos:
(compilamos-el-programa)=
# Compilamos el programa
gcc main_args.c -o mi_programa

(ejecutamos-sin-argumentos)=
# Ejecutamos sin argumentos
./mi_programa

(ejecutamos-con-varios-argumentos)=
# Ejecutamos con varios argumentos
./mi_programa hola "mundo con espacios" 42

```
<!-- {code-block} bash -->

**Salida de la segunda ejecución:**

```
$> ./mi_programa hola "mundo con espacios" 42
El programa se ejecutó con el nombre: ./mi_programa
Número total de argumentos: 4
----------------------------------------
Los argumentos proporcionados son:
  Argumento 1: hola
  Argumento 2: mundo con espacios
  Argumento 3: 42
```

:::{note} Sobre los espacios

Observá que "mundo con espacios" se trata como un solo argumento (`argv[2]`)
porque está entre comillas. Sin las comillas, hubieran sido dos argumentos
separados.

:::
<!-- {note} Sobre los espacios -->

(procesamiento-de-opciones)=
### Procesamiento de opciones

Las opciones (también llamadas _flags_ o _switches_) son argumentos especiales
que modifican el comportamiento de un programa. Usualmente comienzan con un
guion (`-`) o dos (`--`), como `-h` o `--help`.

Para detectarlas, necesitás comparar las cadenas de `argv` con los valores que
esperás. La función `strcmp` (ver {ref}`string-strcmp`) de la biblioteca
`string.h` es ideal para esto.

:::{code-block}c
:caption: "Detección de una opción `-h` para mostrar ayuda."
:label: "c-options-help"

#include <stdio.h>
#include <string.h> // Necesario para strcmp
#include <stdlib.h> // Para EXIT_SUCCESS

int main(int argc, char *argv[]) {
    // Verificamos si el primer argumento es -h o --help
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") ==
    0)) {
        printf("Uso: %s [opciones] [argumentos]\n", argv[0]);
        printf("Este es un programa de ejemplo para mostrar ayuda.\n");
        return EXIT_SUCCESS; // Terminamos la ejecución después de mostrar la
        ayuda
    }

    printf("Programa ejecutándose normalmente.\n");
    // ... resto de la lógica del programa ...

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

:::{tip} Bibliotecas para el Análisis de Argumentos

Para aplicaciones complejas con muchas opciones, analizar `argv` manualmente
puede volverse tedioso y propenso a errores. Considerá usar bibliotecas estándar
como `getopt` (en sistemas POSIX) que simplifican enormemente este proceso.

:::
<!-- {tip} Bibliotecas para el Análisis de Argumentos -->

(conversion-de-argumentos-a-numeros)=
### Conversión de Argumentos a Números

Un punto crucial es que **todos los argumentos en `argv` son cadenas de
caracteres**, incluso si parecen números (como `"42"`). Para poder realizar
operaciones matemáticas con ellos, debés convertirlos a un tipo numérico (como
`int` o `double`).

La biblioteca estándar de C (`stdlib.h`) provee funciones para esta tarea, como
`atoi` y, de forma más robusta, {ref}`strtol <stdlib-strtol>`.

:::{code-block}c
:caption: "Programa que suma los números pasados como argumentos."
:label: "c-sum-numbers"

#include <stdio.h>
#include <stdlib.h> // Necesario para atoi y EXIT_SUCCESS/FAILURE

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Proporcioná al menos un número para sumar.\n");
        fprintf(stderr, "Uso: %s num1 num2 ...\n", argv[0]);
        return EXIT_FAILURE; // Salimos un código de error
    }

    int suma = 0;
    for (int i = 1; i < argc; i++) {
        // atoi convierte la cadena a un entero
        int numero = atoi(argv[i]);
        suma = suma + numero;
    }

    printf("La suma total es: %d\n", suma);

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

(compilacion-y-ejecucion-del-sumador)=
#### Compilación y Ejecución del Sumador

```{code-block} bash
:linenos:
(compilamos)=
# Compilamos
gcc sumador.c -o sumador

(ejecutamos-con-numeros)=
# Ejecutamos con números
./sumador 10 20 5
(salida-la-suma-total-es-35)=
# Salida: La suma total es: 35

```
<!-- {code-block} bash -->

:::{warning} Manejo de Errores en la Conversión

La función `atoi` es simple, pero tiene una limitación importante: si la cadena
no puede ser convertida (ej. "hola"), retorna `0` sin indicar el error.

Para un código más robusto, es preferible usar `strtol` (ver
{ref}`stdlib-strtol`), que ofrece un mecanismo para detectar si la conversión
fue exitosa.

:::
<!-- {warning} Manejo de Errores en la Conversión -->

(funciones-utiles-de-la-biblioteca-estandar)=
### Funciones Útiles de la Biblioteca Estándar

Para construir programas de línea de comandos robustos, es indispensable conocer
algunas de las herramientas que provee la biblioteca estándar de C. A
continuación, se mencionan algunas de las funciones más relevantes en este
contexto.

:::{important} Referencia Completa

Este es solo un resumen. Para una descripción detallada de todas las funciones,
sus parámetros, valores de retorno y ejemplos de uso, consultá el apunte de
referencia: [A_stdlib](../../referencia/A_stdlib.md).

:::
<!-- {important} Referencia Completa -->

(funciones-clave)=
#### Funciones Clave

- **Conversión de Cadenas (`<stdlib.h>`)**:
  - {ref}`strtol <stdlib-strtol>`: Convierte cadenas a números de forma segura,
    permitiendo un control de errores robusto.
  - `atof`: Convierte cadenas a `double`.

- **Control del Programa (`<stdlib.h>`)**:
  - {ref}`exit <stdlib-exit>`: Termina el programa y devuelve un código de
    estado al sistema.
  - {ref}`system <stdlib-system>`: Ejecuta un comando externo del sistema
    operativo.
  - {ref}`getenv <stdlib-getenv>`: Lee el valor de una variable de entorno.

- **Generación de Números Aleatorios (`<stdlib.h>`)**:
  - {ref}`srand <stdlib-rand>` y {ref}`rand <stdlib-rand>`: Para inicializar y
    generar secuencias de números pseudoaleatorios.

- **Manipulación de Cadenas (`<string.h>`)**:
  - {ref}`strcmp <string-strcmp>`: Compara dos cadenas, esencial para procesar
    opciones.
  - {ref}`strlen <string-strlen>`: Obtiene la longitud de una cadena.
  - `strncpy`, `strncat`: Versiones seguras para copiar y concatenar cadenas.
  - `strstr`, `strchr`: Para buscar subcadenas o caracteres.

- **Funciones Matemáticas (`<math.h>`)**:
  - Si tus argumentos son números, probablemente necesites esta biblioteca para
    operaciones como {ref}`pow <math-pow-sqrt>`, {ref}`sqrt <math-pow-sqrt>`,
    {ref}`log <math-pow-sqrt>`, o funciones trigonométricas (ver
    {ref}`math-trig`). No olvides compilar con la bandera `-lm`.

Dominar el uso de `argc` y `argv` junto con estas funciones te permitirá crear
aplicaciones de consola complejas y útiles, una habilidad fundamental en el
mundo del desarrollo de software.

---

(interaccion-con-el-shell)=
### Interacción con el Shell

:::{note} Temas opcionales

Los temas de aquí en adelante en esta página del apunte, no forman parte de lo
que vemos en clases o que entre en los temas de la materia.

Sin embargo, hacen al desarrollo de buenas aplicaciones _de consola_.

:::
<!-- {note} Temas opcionales -->

Cuando ejecutás un programa desde la línea de comandos, tu programa no existe en
aislamiento sino que forma parte de un ecosistema más amplio: el shell o
intérprete de comandos (como `bash`, `zsh`, o `sh`). El shell proporciona
mecanismos poderosos para conectar programas entre sí y controlar el flujo de
datos, lo que convierte a los programas C en herramientas componibles dentro de
un sistema más grande.

(codigos-de-salida)=
#### Códigos de Salida

Cada programa retorna un **código de salida** (o _exit status_) al shell cuando
termina su ejecución. Por convención en Unix y Linux:

- `0` indica éxito (`EXIT_SUCCESS`)
- Cualquier valor distinto de cero indica un error (`EXIT_FAILURE` generalmente
  es `1`)

Este código es fundamental para que el shell y otros programas sepan si tu
programa funcionó correctamente.

:::{code-block}c
:linenos:
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: falta un argumento\n");
        return EXIT_FAILURE; // Retornamos 1 al shell
    }
    
    printf("Procesando: %s\n", argv[1]);
    return EXIT_SUCCESS; // Retornamos 0 al shell
}

:::
<!-- {code-block}c -->

Desde el shell, podés inspeccionar el código de salida del último programa
ejecutado:

``` bash
./mi_programa argumento
echo $?  # Imprime el código de salida (0 si éxito)
```
<!-- bash -->

(variables-de-entorno)=
#### Variables de Entorno

El shell mantiene un conjunto de **variables de entorno** que los programas
pueden leer. Estas variables configuran el comportamiento del sistema y
almacenan información útil como rutas de búsqueda, configuraciones del usuario,
etc.

La función {ref}`getenv <stdlib-getenv>` permite leer estas variables:

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *home = getenv("HOME");
    char *usuario = getenv("USER");
    
    if (home != NULL) {
        printf("Directorio home: %s\n", home);
    }
    
    if (usuario != NULL) {
        printf("Usuario actual: %s\n", usuario);
    }
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

Variables comunes incluyen `PATH` (rutas de búsqueda de ejecutables), `HOME`
(directorio del usuario), `USER` (nombre del usuario), y `LANG` (configuración
de idioma).

:::{figure} 1/codigos_salida.svg
:label: fig-codigos-salida
:align: center

Códigos de salida en programas C. El shell usa estos códigos para determinar si
la ejecución fue exitosa (`0`) o falló (distinto de `0`).

:::
<!-- {figure} 1/codigos_salida.svg -->

(redirecciones)=
### Redirecciones

Una característica fundamental del shell es su capacidad de **redirigir** la
entrada y salida de los programas. Esto permite cambiar de dónde un programa lee
datos y hacia dónde escribe sus resultados, sin modificar el código del
programa.

(salida-estandar-y-error-estandar)=
#### Salida Estándar y Error Estándar

Todo programa en Unix/Linux tiene tres flujos de datos estándar abiertos
automáticamente:

- **Entrada estándar** (`stdin`, descriptor 0): De dónde el programa lee datos
- **Salida estándar** (`stdout`, descriptor 1): Donde el programa escribe su
  salida normal
- **Error estándar** (`stderr`, descriptor 2): Donde el programa escribe
  mensajes de error

:::{figure} 1/flujos_estandar.svg
:label: fig-flujos-estandar
:align: center

Los tres flujos de datos estándar en un programa C: `stdin`, `stdout` y
`stderr`. Por defecto, `stdin` lee del teclado mientras que `stdout` y `stderr`
escriben a la pantalla.

:::
<!-- {figure} 1/flujos_estandar.svg -->

En C, estos flujos están disponibles como:

:::{code-block}c
:linenos:
#include <stdio.h>

// stdin  - entrada estándar (teclado por defecto)
// stdout - salida estándar (pantalla por defecto)
// stderr - error estándar (pantalla por defecto)

int main(void) {
    fprintf(stdout, "Esto es salida normal\n");
    fprintf(stderr, "Esto es un mensaje de error\n");
    
    // printf escribe a stdout por defecto
    printf("Salida normal\n");
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

:::{important} Separación de Salida y Error

Es una buena práctica escribir la salida normal del programa a `stdout` usando
`printf`, y los mensajes de error o advertencia a `stderr` usando
`fprintf(stderr, ...)`. Esto permite que el shell y el usuario manejen cada tipo
de información de forma independiente.

:::
<!-- {important} Separación de Salida y Error -->

(redireccion-de-salida)=
#### Redirección de Salida

El shell puede redirigir hacia dónde va la salida de un programa usando el
operador `>`:

```{code-block} bash
:linenos:
(redirige-stdout-a-un-archivo-sobrescribe)=
# Redirige stdout a un archivo (sobrescribe)
./mi_programa > salida.txt

(redirige-stdout-a-un-archivo-agrega-al-final)=
# Redirige stdout a un archivo (agrega al final)
./mi_programa >> salida.txt

(redirige-stderr-a-un-archivo)=
# Redirige stderr a un archivo
./mi_programa 2> errores.txt

(redirige-ambos-stdout-y-stderr-al-mismo-archivo)=
# Redirige ambos stdout y stderr al mismo archivo
./mi_programa > todo.txt 2>&1

```
<!-- {code-block} bash -->

:::{figure} 1/redirecciones.svg
:label: fig-redirecciones
:align: center

Distintas formas de redirección en el shell. El programa no necesita
modificarse, el shell conecta automáticamente los flujos a archivos.

:::
<!-- {figure} 1/redirecciones.svg -->

Desde el punto de vista del programa en C, no necesitás hacer nada especial:
simplemente usá `printf` (para stdout) y `fprintf(stderr, ...)` (para stderr)
normalmente. El shell se encarga de la redirección.

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Esto puede ir a pantalla o a un archivo según el shell lo redirija
    printf("Línea 1 de salida\n");
    printf("Línea 2 de salida\n");
    
    // Los errores se mantienen separados
    fprintf(stderr, "Advertencia: algo ocurrió\n");
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

```{code-block} bash
:linenos:
(ejecuta-y-guarda-solo-la-salida-normal-en-archivo-txt)=
# Ejecuta y guarda solo la salida normal en archivo.txt
./mi_programa > archivo.txt
(los-errores-aun-aparecen-en-pantalla)=
# Los errores aún aparecen en pantalla

(para-capturar-solo-los-errores)=
# Para capturar solo los errores
./mi_programa 2> errores.txt

```
<!-- {code-block} bash -->

(redireccion-de-entrada)=
#### Redirección de Entrada

De forma similar, el shell puede cambiar de dónde un programa lee su entrada
usando el operador `<`:

``` bash
(lee-stdin-desde-un-archivo-en-lugar-del-teclado)=
# Lee stdin desde un archivo en lugar del teclado
./mi_programa < datos.txt
```
<!-- bash -->

Cualquier lectura que tu programa haga desde `stdin` (usando `scanf`, `fgets`,
`getchar`, etc.) leerá del archivo especificado:

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char linea[256];
    
    // Lee líneas de stdin (puede ser teclado o archivo redirigido)
    while (fgets(linea, sizeof(linea), stdin) != NULL) {
        printf("Leí: %s", linea);
    }
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

```{code-block} bash
:linenos:
(si-ejecutas-directamente-lee-del-teclado)=
# Si ejecutás directamente, lee del teclado
./mi_programa

(con-redireccion-lee-del-archivo)=
# Con redirección, lee del archivo
./mi_programa < datos.txt

```
<!-- {code-block} bash -->

(canalizaciones-pipes)=
### Canalizaciones (Pipes)

Las **canalizaciones** o _pipes_ son uno de los conceptos más poderosos del
shell Unix. Permiten conectar la salida de un programa directamente con la
entrada de otro, creando cadenas de procesamiento de datos.

El operador `|` (pipe) conecta `stdout` del primer programa con `stdin` del
segundo:

```{code-block} bash
:linenos:
(la-salida-de-programa1-se-convierte-en-la-entrada-de-programa2)=
# La salida de programa1 se convierte en la entrada de programa2
programa1 | programa2

(ejemplo-real-cuenta-las-lineas-de-salida-de-ls)=
# Ejemplo real: cuenta las líneas de salida de ls
ls -l | wc -l

```
<!-- {code-block} bash -->

:::{figure} 1/pipes_canalizaciones.svg
:label: fig-pipes-canalizaciones
:align: center

Canalizaciones (pipes) en Unix. La salida estándar de un programa se conecta con
la entrada estándar del siguiente, permitiendo construir cadenas de
procesamiento.

:::
<!-- {figure} 1/pipes_canalizaciones.svg -->

(filosofia-unix-hacer-una-cosa-bien)=
#### Filosofía Unix: Hacer Una Cosa Bien

Las canalizaciones promueven la **filosofía Unix**: escribir programas pequeños
que hagan una cosa muy bien, y combinarlos para tareas complejas. Tu programa C
puede ser un eslabón en esta cadena.

##### Ejemplo: Filtro de Números Pares

:::{code-block}c
:linenos:
// filtro_pares.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numero;
    
    // Lee números de stdin, uno por línea
    while (scanf("%d", &numero) == 1) {
        // Solo imprime los pares
        if (numero % 2 == 0) {
            printf("%d\n", numero);
        }
    }
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

Este programa se convierte en un filtro reutilizable:

```{code-block} bash
:linenos:
(genera-numeros-del-1-al-10-y-filtra-solo-los-pares)=
# Genera números del 1 al 10 y filtra solo los pares
seq 1 10 | ./filtro_pares
(salida-2-4-6-8-10)=
# Salida: 2, 4, 6, 8, 10

(combina-con-otros-programas)=
# Combina con otros programas
seq 1 100 | ./filtro_pares | wc -l  # Cuenta cuántos pares hay

```
<!-- {code-block} bash -->

:::{figure} 1/ejemplo_filtro.svg
:label: fig-ejemplo-filtro
:align: center

Flujo de datos en una canalización que genera números, filtra solo los pares y
toma los primeros 5 resultados.

:::
<!-- {figure} 1/ejemplo_filtro.svg -->

(canalizaciones-complejas)=
#### Canalizaciones Complejas

Podés encadenar múltiples programas:

``` bash
(genera-numeros-filtra-pares-suma-los-primeros-5)=
# Genera números, filtra pares, suma los primeros 5
seq 1 100 | ./filtro_pares | head -5 | ./sumador
```
<!-- bash -->

Cada programa en la cadena:
1. Lee de `stdin`
2. Procesa los datos
3. Escribe a `stdout`
4. El shell conecta todo automáticamente

(consideraciones-de-diseno)=
#### Consideraciones de Diseño

Para que tu programa funcione bien en canalizaciones:

1. **Lee de `stdin` si no hay archivo especificado**: Permite que el programa
   reciba datos por pipe o por archivo
2. **Escribe resultados a `stdout`**: La salida normal va a `stdout`
3. **Mensajes de error a `stderr`**: No contamines `stdout` con errores
4. **Maneja EOF correctamente**: Detectá cuando la entrada termina (`fgets`
   retorna `NULL`, `scanf` retorna `EOF`)

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *entrada = stdin;  // Por defecto, stdin
    
    // Si hay un argumento, abre ese archivo
    if (argc > 1) {
        entrada = fopen(argv[1], "r");
        if (entrada == NULL) {
            fprintf(stderr, "Error: no se pudo abrir %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    
    char linea[256];
    // Lee líneas (de stdin o del archivo)
    while (fgets(linea, sizeof(linea), entrada) != NULL) {
        // Procesa y escribe a stdout
        printf("Procesado: %s", linea);
    }
    
    if (entrada != stdin) {
        fclose(entrada);
    }
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

Este diseño permite flexibilidad total:

```{code-block} bash
:linenos:
(lee-del-archivo-directamente)=
# Lee del archivo directamente
./mi_programa datos.txt

(lee-de-stdin-teclado)=
# Lee de stdin (teclado)
./mi_programa

(lee-de-stdin-via-redireccion)=
# Lee de stdin vía redirección
./mi_programa < datos.txt

(lee-de-stdin-via-canalizacion)=
# Lee de stdin vía canalización
cat datos.txt | ./mi_programa

```
<!-- {code-block} bash -->

:::{tip} Programas Componibles

Un programa bien diseñado para la línea de comandos es como una pieza de LEGO:
pequeño, con una función clara, y que se puede combinar con otros programas para
construir sistemas complejos. Esta composibilidad es la esencia del diseño Unix.

:::
<!-- {tip} Programas Componibles -->

(ejemplo-completo-conversor-de-temperatura)=
#### Ejemplo Completo: Conversor de Temperatura

Veamos un ejemplo que integra todos estos conceptos:

:::{code-block}c
:linenos:
// temp_converter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_ayuda(const char *programa) {
    fprintf(stderr, "Uso: %s [-c|-f] [archivo]\n", programa);
    fprintf(stderr, "  -c : Convierte de Fahrenheit a Celsius\n");
    fprintf(stderr, "  -f : Convierte de Celsius a Fahrenheit\n");
    fprintf(stderr, "Si no se especifica archivo, lee de stdin\n");
}

int main(int argc, char *argv[]) {
    FILE *entrada = stdin;
    char modo = 'c';  // Por defecto: F->C
    
    // Procesa opciones
    int archivo_idx = 1;
    if (argc > 1 && argv[1][0] == '-') {
        if (strcmp(argv[1], "-c") == 0) {
            modo = 'c';
            archivo_idx = 2;
        } else if (strcmp(argv[1], "-f") == 0) {
            modo = 'f';
            archivo_idx = 2;
        } else if (strcmp(argv[1], "-h") == 0) {
            mostrar_ayuda(argv[0]);
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Error: opción desconocida %s\n", argv[1]);
            mostrar_ayuda(argv[0]);
            return EXIT_FAILURE;
        }
    }
    
    // Abre archivo si se especificó
    if (argc > archivo_idx) {
        entrada = fopen(argv[archivo_idx], "r");
        if (entrada == NULL) {
            fprintf(stderr, "Error: no se pudo abrir %s\n", argv[archivo_idx]);
            return EXIT_FAILURE;
        }
    }
    
    // Procesa entrada línea por línea
    double temp;
    while (fscanf(entrada, "%lf", &temp) == 1) {
        double resultado;
        if (modo == 'c') {
            // Fahrenheit a Celsius
            resultado = (temp - 32.0) * 5.0 / 9.0;
            printf("%.2f°F = %.2f°C\n", temp, resultado);
        } else {
            // Celsius a Fahrenheit
            resultado = temp * 9.0 / 5.0 + 32.0;
            printf("%.2f°C = %.2f°F\n", temp, resultado);
        }
    }
    
    if (entrada != stdin) {
        fclose(entrada);
    }
    
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

Este programa puede usarse de múltiples formas:

```{code-block} bash
:linenos:
(uso-interactivo)=
# Uso interactivo
./temp_converter -c
32
212

(desde-archivo)=
# Desde archivo
echo -e "32\n98.6\n212" > temps.txt
./temp_converter -c temps.txt

(con-redireccion)=
# Con redirección
./temp_converter -c < temps.txt

(con-canalizacion)=
# Con canalización
echo "100" | ./temp_converter -f

(encadenado-con-otros-comandos)=
# Encadenado con otros comandos
seq 0 10 100 | ./temp_converter -f | grep "°C"

```
<!-- {code-block} bash -->

La separación entre `stdout` (resultados) y `stderr` (mensajes de error y ayuda)
permite que el programa funcione correctamente en canalizaciones sin contaminar
los datos con mensajes no deseados.








---


## Ejercicios de Autoevaluación

### Fases de Compilación

:::{exercise}
:label: ej-comp-fases-ext
Relacioná cada una de las cuatro fases de compilación de C con su
correspondiente archivo intermedio generado por GCC indicando su extensión
habitual y su formato (texto plano o binario).

:::
<!-- {exercise} -->

:::{solution} ej-comp-fases-ext
:class: dropdown
1.  **Preprocesado**: Genera el archivo fuente expandido con extensión `.i`
    (Texto plano).
2.  **Compilación**: Traduce el código C a código ensamblador con extensión `.s`
    (Texto plano específico de la arquitectura).
3.  **Ensamblado**: Genera el archivo objeto con extensión `.o` (Binario en
    formato estructurado, como ELF).
4.  **Enlazado**: Produce el archivo ejecutable binario final (sin extensión en
    Unix/Linux, `.exe` en Windows).

:::
<!-- {solution} ej-comp-fases-ext -->

:::{exercise}
:label: ej-comp-macro-hazard
Explicá detalladamente por qué la macro `#define DUPLICAR(x) x * 2` produce un
resultado incorrecto al evaluarse como `DUPLICAR(5 + 3)`. Proponé la definición
correcta y segura para esta macro.

:::
<!-- {exercise} -->

:::{solution} ej-comp-macro-hazard
:class: dropdown
El preprocesador realiza una sustitución de texto literal sin evaluar
precedencias matemáticas.
- Al expandir `DUPLICAR(5 + 3)`, el texto resultante es `5 + 3 * 2`.
- Siguiendo la precedencia de operadores, la multiplicación se evalúa antes que
  la suma: $5 + (3 \times 2) = 11$. El resultado esperado era $(5 + 3) \times 2
  = 16$.
Para evitar este peligro de orden de operaciones, se deben proteger todos los
parámetros y la expresión completa con paréntesis:
``` c
#define DUPLICAR(x) ((x) * 2)
```
<!-- c -->

:::
<!-- {solution} ej-comp-macro-hazard -->

:::{exercise}
:label: ej-comp-flags-warn
Si compilás un programa utilizando `gcc -Wall -Wextra -Werror main.c` y el
compilador detecta una variable local declarada que nunca se lee ni se utiliza
en el código, ¿cuál es el resultado de la compilación?

:::
<!-- {exercise} -->

:::{solution} ej-comp-flags-warn
:class: dropdown
La compilación fallará y **no se generará el archivo ejecutable**.
- `-Wall` y `-Wextra` hacen que el compilador emita una advertencia (*warning*)
  informando de la variable no utilizada.
- `-Werror` instruye al compilador a tratar todas las advertencias como errores
  fatales, lo que aborta inmediatamente el proceso de compilación impidiendo la
  generación del binario.

:::
<!-- {solution} ej-comp-flags-warn -->


### Cabeceras y Modularidad

:::{exercise}
:label: ej-header-odr-viol
Explicá por qué colocar la definición de una función (por ejemplo, `int
sumar(int a, int b) { return a + b; }`) en un archivo de cabecera
`operaciones.h` incluido por `main.c` y `utilidades.c` viola la regla de
definición única (ODR) y qué error produce.

:::
<!-- {exercise} -->

:::{solution} ej-header-odr-viol
:class: dropdown
Al incluir `operaciones.h` en `main.c` y `utilidades.c`, el preprocesador copia
textualmente el cuerpo de `sumar` en ambas unidades de traducción.
Al compilar por separado, tanto `main.o` como `utilidades.o` contendrán el
código máquina y el símbolo de la función `sumar`. Durante la fase de enlazado,
el linker detectará que el símbolo `sumar` está definido físicamente en más de
un archivo objeto, abortando el proceso con un error del tipo `multiple
definition of 'sumar'`.
Para solucionarlo, solo se debe colocar el prototipo de la función en
`operaciones.h` y su definición en un archivo `operaciones.c`.

:::
<!-- {solution} ej-header-odr-viol -->

:::{exercise}
:label: ej-header-inclusion-guards
Escribí la estructura completa de directivas del preprocesador necesarias para
implementar guardas de inclusión en un archivo de cabecera llamado
`sensor_temperatura.h` de acuerdo con las pautas de estilo.

:::
<!-- {exercise} -->

:::{solution} ej-header-inclusion-guards
:class: dropdown
``` c
#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

// Declaraciones de prototipos y tipos del módulo del sensor
float leer_sensor_celsius(int pin);

#endif // SENSOR_TEMPERATURA_H
```
<!-- c -->

:::
<!-- {solution} ej-header-inclusion-guards -->

:::{exercise}
:label: ej-header-extern-use
Explicá la diferencia de roles entre declarar una variable con `extern int
contador;` en un archivo `.h` y definirla como `int contador = 0;` en un archivo
`.c`.

:::
<!-- {exercise} -->

:::{solution} ej-header-extern-use
:class: dropdown
- **Declaración (`extern int contador;`)**: Le indica al compilador que la
  variable `contador` existe y está alojada físicamente en otra parte del
  programa. No reserva memoria ni inicializa ningún valor; es un anuncio de su
  existencia para permitir que otros archivos compilen sin error.
- **Definición (`int contador = 0;`)**: Reserva el espacio físico real en la
  memoria del segmento de datos e inicializa la variable. Solo debe existir una
  única definición física para evitar colisiones en el linker.

:::
<!-- {solution} ej-header-extern-use -->


### Automatización con Makefiles

:::{exercise}
:label: 1_compilacion-ej-make-incremental
Describí el criterio físico que utiliza la herramienta `make` para decidir si es
necesario reconstruir un archivo objeto (por ejemplo, `funciones.o`) a partir de
su archivo fuente `funciones.c`.

:::
<!-- {exercise} -->

:::{solution} 1_compilacion-ej-make-incremental
:class: dropdown
`make` examina las **marcas de tiempo de modificación (timestamps)** de los
archivos en el disco físico.
Si la fecha de última modificación del archivo de entrada (`funciones.c` o
alguna de sus cabeceras declaradas como dependencias, ej: `funciones.h`) es
**más reciente** que la fecha de última modificación del archivo objeto de
salida (`funciones.o`), `make` deduce que el código fuente cambió y ejecuta la
regla de compilación para reconstruir el objeto. Si el objeto es más nuevo que
sus dependencias, `make` omite su compilación.

:::
<!-- {solution} ej-make-incremental -->

:::{exercise}
:label: 1_compilacion-ej-make-clean-phony
Explicá detalladamente para qué sirve la regla `.PHONY: clean` en un Makefile y
qué problema se produciría si se omitiera esta declaración y existiera en el
directorio un archivo físico llamado `clean`.

:::
<!-- {exercise} -->

:::{solution} 1_compilacion-ej-make-clean-phony
:class: dropdown
La directiva `.PHONY` le indica a `make` que el objetivo indicado no corresponde
a un archivo real que deba ser generado.
Si se omitiera `.PHONY: clean` y en el mismo directorio existiera un archivo
llamado `clean`, al ejecutar `make clean`, la herramienta buscaría dependencias
para el objetivo `clean`. Al no tener dependencias y ver que el archivo `clean`
ya existe físicamente en el disco, `make` reportaría que el objetivo está
actualizado (`make: 'clean' is up to date`) y se negaría a ejecutar el bloque de
comandos para limpiar el proyecto.

:::
<!-- {solution} ej-make-clean-phony -->

:::{exercise}
:label: 1_compilacion-ej-make-escritura
Escribí una regla de Makefile para compilar el archivo objeto `usuario.o` a
partir de sus dependencias `usuario.c` y `usuario.h`. Utilizá variables para el
compilador (`$(CC)`) y banderas (`$(CFLAGS)`), recordando el requisito de
indentación de Makefiles.

:::
<!-- {exercise} -->

:::{solution} 1_compilacion-ej-make-escritura
:class: dropdown
``` makefile
usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c -o usuario.o
```
<!-- makefile -->
*Nota: La línea de comandos de la acción debe estar precedida obligatoriamente
por un carácter de tabulación (Tab).*

:::
<!-- {solution} ej-make-escritura -->


### Argumentos e Interacción

:::{exercise}
:label: ej-cli-argc-argv-val
Si un programa compilado como `servidor` se invoca en la terminal de la
siguiente manera:
`./servidor iniciar puerto 8080`
Indicá el valor de `argc` y el contenido detallado del arreglo de punteros
`argv[]`.

:::
<!-- {exercise} -->

:::{solution} ej-cli-argc-argv-val
:class: dropdown
El valor de `argc` es `4` (el nombre del ejecutable más tres argumentos reales).
El contenido de `argv` es el siguiente:
- `argv[0]`: Apunta a la cadena `"./servidor"`
- `argv[1]`: Apunta a la cadena `"iniciar"`
- `argv[2]`: Apunta a la cadena `"puerto"`
- `argv[3]`: Apunta a la cadena `"8080"`
- `argv[4]`: Es un puntero nulo (`NULL`) garantizado por el estándar.

:::
<!-- {solution} ej-cli-argc-argv-val -->

:::{exercise}
:label: ej-cli-strtol-atoi
Justificá por qué es una mejor práctica de programación usar la función `strtol`
en lugar de `atoi` para convertir argumentos de consola a enteros.

:::
<!-- {exercise} -->

:::{solution} ej-cli-strtol-atoi
:class: dropdown
La función `atoi` carece de mecanismos de reporte de errores: si el usuario
ingresa una cadena no numérica como `"abc"` o `"100x"`, `atoi` devuelve `0` sin
reportar falla alguna, impidiendo distinguir entre el número `0` real y una
conversión fallida. Además, no detecta desbordamientos numéricos.
Por el contrario, `strtol` provee un puntero de retorno (`endptr`) que indica
dónde terminó la conversión (permitiendo validar caracteres extraños) y setea la
variable global `errno` en caso de desbordamiento de enteros.

:::
<!-- {solution} ej-cli-strtol-atoi -->

:::{exercise}
:label: ej-cli-redireccion-pipe
Escribí la instrucción de shell (bash) necesaria para ejecutar un programa
`./productor` y pasar su salida estándar como entrada de `./consumidor`,
asegurando que todos los mensajes de error (`stderr`) que emita `./consumidor`
se guarden en un archivo llamado `log_errores.txt`.

:::
<!-- {exercise} -->

:::{solution} ej-cli-redireccion-pipe
:class: dropdown
La instrucción correspondiente en bash es:
``` bash
./productor | ./consumidor 2> log_errores.txt
```
<!-- bash -->
El operador pipe `|` conecta la salida estándar de `./productor` al canal de
entrada estándar de `./consumidor`, mientras que `2>` desvía el descriptor 2
(error estándar) del segundo comando hacia el archivo indicado.

:::
<!-- {solution} ej-cli-redireccion-pipe -->


## Glosario

::::{glossary}

Compilación
: Proceso de traducción de código fuente escrito en C a instrucciones binarias
ejecutables por el procesador.

Preprocesador
: Herramienta que procesa directivas iniciales (indicadas con `#`) operando a
nivel de texto antes de la compilación propiamente dicha.

Enlazador (Linker)
: Fase final que combina archivos objeto y bibliotecas resolviendo referencias
de símbolos cruzados.

Makefile
: Archivo de configuración que define las dependencias y recetas necesarias para
automatizar la compilación incremental de un proyecto.

Argumentos de línea de comandos
: Parámetros recibidos por la función `main` mediante `argc` y `argv` desde la
terminal.

Canalización (Pipe)
: Operador de shell (`|`) que transfiere la salida estándar de un proceso
directamente a la entrada estándar de otro.

::::
<!-- {glossary} -->

## Síntesis y Resumen

La traducción de código C en un binario ejecutable se compone de cuatro etapas
sucesivas: preprocesado (directivas textuales), compilación (traducción a
ensamblador de la arquitectura), ensamblado (generación de archivos objeto `.o`
en formato binario estructurado como ELF) y enlazado (resolución de símbolos
externos y fusión de segmentos). Para automatizar y optimizar este flujo en
proyectos modulares se utiliza `make`, el cual determina qué archivos recompilar
en función de las marcas de tiempo físicas. Los programas interactúan con la
terminal a través de argumentos de consola (`argc`, `argv`), códigos de salida
(`EXIT_SUCCESS` o `EXIT_FAILURE`), y mecanismos del shell como redirecciones
(`>`, `<`) y canalizaciones (`|`).

## Referencias y Lecturas Complementarias

(proceso-de-compilacion)=
### Proceso de Compilación

- {cite:t}`kernighan_c_2014`. Apéndice A12: Preprocessing y Capítulo 4:
  Functions and Program Structure.

- {cite:t}`levine_linkers_1999`. Libro completo sobre enlazado y carga.

(gcc-y-herramientas)=
### GCC y Herramientas

- **GCC Documentation** - https://gcc.gnu.org/onlinedocs/
  - Manual oficial completo del compilador GCC.
  - Flags, optimizaciones, warnings.

- **Make Manual** - https://www.gnu.org/software/make/manual/
  - Guía completa de GNU Make.
  - Patrones, variables automáticas, funciones.

- {cite:t}`mecklenburg_managing_2004`. Guía práctica de Makefiles complejos.

(1_compilacion-recursos-en-linea)=
### Recursos en Línea

- **An Introduction to GCC** -
  https://www.linuxtopia.org/online_books/an_introduction_to_gcc/
  - Libro online gratuito sobre GCC.
  - Brian Gough, GNU Press.

- **Makefile Tutorial** - https://makefiletutorial.com/
  - Tutorial interactivo progresivo.
  - Ejemplos ejecutables en el navegador.
