---
title: Compilación
short_title: 5 - Compilación
subtitle: Haciendonos entender por la computadora.
---

## Proceso de compilación en C

Cuando ejecutás en tu terminal el comando:

```{code-block} sh
$> gcc -o mi_programa programa.c
```

No solo estás invocando un programa, sino que desencadenás un sofisticado proceso de transformación. A simple vista, es una única instrucción que convierte tu código fuente, escrito en un lenguaje comprensible para vos, en un archivo ejecutable que la máquina puede interpretar directamente.

:::{note} Prerequisitos
Este capítulo asume que ya escribiste y ejecutaste programas básicos en C como los presentados en el {doc}`2_gradual`. También es útil tener familiaridad con el concepto de funciones ({doc}`3_funciones`) ya que se mencionan prototipos y definiciones en el contexto de compilación de múltiples archivos.
:::

Sin embargo, detrás de esa aparente simplicidad, el compilador `gcc` (GNU Compiler Collection) actúa como un director de orquesta, coordinando una secuencia de herramientas especializadas que trabajan en conjunto. Cada una de estas herramientas se encarga de una fase específica, traduciendo progresivamente el código hasta su forma final.

Comprender esta transformación del código, desde `programa.c` hasta `mi_programa`, es una habilidad fundamental para cualquier desarrollador de C. Te proporciona las bases para diagnosticar errores de compilación complejos, optimizar el rendimiento de tus aplicaciones y gestionar eficientemente proyectos que se componen de múltiples archivos fuente.

### Diagrama del Proceso

El flujo de transformación desde tu código fuente hasta un programa ejecutable
se puede visualizar de la siguiente manera:

```{mermaid}
graph TD
    A[programa.c] --> B{1. Preprocesador};
    B --> C[programa.i];
    C --> D{2. Compilador};
    D --> E[programa.s];
    E --> F{3. Ensamblador};
    F --> G[programa.o];
    G --> H{4. Enlazador};
    H --> I[mi_programa];

    style A fill:#f9f,stroke:#333,stroke-width:2px
    style C fill:#f9f,stroke:#333,stroke-width:2px
    style E fill:#f9f,stroke:#333,stroke-width:2px
    style G fill:#f9f,stroke:#333,stroke-width:2px
    style I fill:#ccf,stroke:#333,stroke-width:2px
```

### Fase 1: Preprocesado (Preprocessing)

Esta es la etapa inicial del proceso de compilación. Su función es transformar
tu código fuente antes de que el compilador propiamente dicho comience su
análisis. El preprocesador opera a un nivel textual: no comprende la sintaxis o
la semántica de C, sino que se limita a interpretar y ejecutar directivas, que
son instrucciones especiales identificadas por el carácter inicial `#`.

Podés pensar en el preprocesador como un asistente que prepara y limpia el
código, resolviendo inclusiones de archivos, expandiendo abreviaturas (macros) y
seleccionando fragmentos de código según ciertas condiciones, antes de
entregárselo al compilador.

#### Tareas del preprocesador

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

:::{warning} Cuidado con las Macros
Las macros realizan una sustitución de texto literal, lo que puede llevar a
errores inesperados si no se usan paréntesis adecuadamente para proteger el
orden de las operaciones.
:::

##### Compilación Condicional **Directivas:** `#if`, `#ifdef`,

`#ifndef`, `#else`, `#elif`, `#endif`

Estas directivas permiten que el preprocesador incluya o excluya porciones de
código del archivo fuente final que se pasará al compilador. Son extremadamente
útiles para:

- **Portabilidad**: Escribir código que se compila de manera diferente según el
  sistema operativo o la arquitectura.
- **Depuración**: Incluir código de depuración (por ejemplo, impresiones en
  consola) solo cuando se define una macro específica como `DEBUG`.
- **Guardas de cabecera**: Evitar la doble inclusión de archivos de cabecera, un
  problema común en proyectos grandes, utilizando una estructura como la que exige la regla {ref}`0x002Dh`:

  ```{code-block} c
  #ifndef MI_CABECERA_H
  #define MI_CABECERA_H

  // Contenido de la cabecera...

  #endif // MI_CABECERA_H
  ```

##### Eliminación de Comentarios

El preprocesador también se encarga de una tarea de limpieza fundamental:
eliminar todo el texto que se encuentre dentro de los bloques de comentarios
`/* ... */` y todo lo que siga aun comentario de una sola línea `//`. Esto
reduce el "ruido" y entrega al compilador únicamente el código que debe
analizar.

#### ¿Cómo verlo en acción?

Para aislar y examinar el resultado de esta fase, podés indicarle a `gcc` que se
detenga justo después del preprocesado. Esto se logra con la opción `-E`. El
resultado es el código fuente "expandido", que normalmente se redirige a un
archivo con extensión `.i`.

```{code-block} sh
$> gcc -E programa.c > programa.i
```

El archivo `programa.i` es un archivo de texto plano que contiene tu código
original, pero con todas las cabeceras incluidas, las macros expandidas, los
comentarios eliminados y las condiciones resueltas. Revisar este archivo es una
técnica de depuración excelente cuando sospechás que un error se origina en una
macro mal definida o en una inclusión de archivo incorrecta.

### Etapa 2: Compilación

Esta es la fase central del proceso, donde el compilador (como `gcc`) toma el
código C preprocesado y lo traduce a un lenguaje de mucho más bajo nivel: el
lenguaje ensamblador (Assembly). Este lenguaje no es universal; es específico
para la arquitectura del procesador de destino (por ejemplo, x86-64, ARM,
RISC-V).

El compilador no solo traduce, sino que también analiza y optimiza el código.
Este proceso se puede descomponer en varias sub-fases:

```{mermaid}
flowchart TD
 subgraph subGraph0["Frontend del Compilador"]
        B{"Análisis Léxico"}
        C{"Análisis Sintáctico"}
        D{"Análisis Semántico"}
  end
 subgraph subGraph1["Backend del Compilador"]
        E{"Generación de Código Intermedio"}
        F{"Optimización"}
        G["Código Ensamblador"]
  end
    A["Código C Preprocesado"] --> B
    B --> C
    C --> D
    D --> E
    E --> F
    F --> G

```

#### Análisis Léxico y Sintáctico

El compilador primero descompone el código fuente en tokens (palabras clave,
identificadores, operadores) y luego verifica que la secuencia de estos tokens
siga las reglas gramaticales del lenguaje C, construyendo una estructura de
árbol conocida como Árbol de Sintaxis Abstracta (AST). Si olvidás un punto y
coma, las llaves no coinciden o una instrucción está mal formada, el proceso
falla aquí.

#### Análisis Semántico

Una vez que la sintaxis es correcta, el compilador verifica la coherencia
semántica. Se asegura de que las variables estén declaradas antes de usarse, que
los tipos de datos sean compatibles en las operaciones (no podés sumar un número
a una `struct`, por ejemplo) y que las llamadas a funciones coincidan con sus
declaraciones.

#### Optimización

Esta es una de las tareas más importantes del compilador. Transforma el código
para que sea más eficiente o más pequeño en tamaño, sin cambiar su
comportamiento. Las optimizaciones pueden incluir la eliminación de código
muerto, el desenrollado de bucles (loop unrolling) o la inserción de funciones
en línea (inlining).

#### Generación de Código

Finalmente, el código optimizado se traduce a las instrucciones específicas del
lenguaje ensamblador para la arquitectura de destino. Cada línea de código C se
convierte en una o más instrucciones de ensamblador que el procesador puede
entender.

````{admonition} ¿Cómo verlo en acción?
:class: tip, dropdown

Podés instruir a `gcc` para que se detenga después de la fase de compilación con
la opción `-S`. Esto generará un archivo de texto con la extensión `.s` que contiene
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

Al ejecutar el comando:

```{code-block} bash
gcc -S programa.c
```

Se creará un archivo `programa.s`. Su contenido será similar a este (puede
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

Analizar este archivo es una excelente manera de entender cómo tus
construcciones de C se traducen a operaciones de bajo nivel y cómo el compilador
aplica optimizaciones.
````

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

#### Tareas Principales del Ensamblador

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

#### El Archivo Objeto: Más que solo Código Máquina

Un error común es pensar que un archivo `.o` es simplemente un volcado del
código binario. En realidad, es un archivo con una estructura bien definida
(comúnmente en formato **ELF**, _Executable and Linkable Format_, en sistemas
Linux) que contiene varias piezas de información cruciales para la siguiente y
última fase:

- **Sección de Texto (`.text`)**: Contiene las instrucciones de máquina
  compiladas de tu código.
- **Sección de Datos (`.data` y `.bss`)**: Almacena las variables globales y
  estáticas. `.data` para las inicializadas y `.bss` para las no inicializadas.
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

#### ¿Cómo verlo en acción?

La opción `-c` de `gcc` es una de las más importantes en el desarrollo de
software, ya que detiene el proceso de compilación justo después de la fase de
ensamblado, generando únicamente el archivo objeto.

```{code-block} sh
$> gcc -c programa.c
```

Este comando creará el archivo `programa.o` en el mismo directorio.

:::{tip} La Importancia de la Compilación Separada
En proyectos que constan de múltiples archivos fuente (`modulo1.c`, `modulo2.c`,
`main.c`), no se compila todo el proyecto de una sola vez. En su lugar, se
compila cada archivo `.c` por separado para generar su correspondiente archivo
`.o`:

```{code-block} sh
$> gcc -c modulo1.c   # Genera modulo1.o
$> gcc -c modulo2.c   # Genera modulo2.o
$> gcc -c main.c      # Genera main.o
```

Si luego modificás solo `modulo1.c`, únicamente necesitás recompilar ese archivo
para generar un nuevo `modulo1.o`. Los demás archivos objeto no se tocan. El
paso final consiste en enlazar todos los `.o` (el nuevo y los antiguos) para
crear el ejecutable. Este principio de **compilación separada** es la base de
los sistemas de construcción como `make` y ahorra una cantidad inmensa de tiempo
en proyectos grandes.
:::

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

### ¿Cómo verlo en acción?

El enlazado es el paso final y automático que `gcc` realiza si no se le indica
que se detenga antes con las opciones `-E`, `-S` o `-c`.

Si ya tenés un archivo objeto compilado, podés invocar explícitamente la fase de
enlazado de la siguiente manera:

```{code-block} sh
# Asumiendo que ya existe programa.o
$> gcc -o mi_programa programa.o
```

Este comando le dice a `gcc` que use `programa.o` como entrada para el
enlazador, resuelva cualquier símbolo externo (buscando en la biblioteca
estándar de C por defecto) y genere el ejecutable `mi_programa`.

Por supuesto, el comando original que inicia todo el proceso desde el principio
también realiza este paso al final:

```{code-block} sh
# El comando completo que ejecuta las cuatro fases en secuencia
$> gcc -o mi_programa programa.c
```

## Opciones del Compilador Recomendadas

Usar `gcc` sin opciones es desaprovechar su potencial para ayudarte a escribir
mejor código. Las siguientes opciones, exigidas por la regla {ref}`0x002Ch`, son altamente recomendadas en un entorno
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
  un compilador, pero también se puede usar para ver si el código compilaría en
  versiones más antiguas del estándar.
- `-g`: Incluye información de depuración en el ejecutable. Es **esencial** para
  poder usar un depurador como `gdb` y analizar tu programa paso a paso.
- `-O2`: Activa un alto nivel de optimización de código. No se recomienda usarlo
  mientras desarrollas o depuras, ya que el proceso de mejorar la velocidad del
  código puede reorganizar el código y hacer la depuración confusa, pero sí es
  recomendabel para la versión final de tu programa. Mientras trabajamos en
  desarrollar nuestros programas, es mejor usar `-O0`, que la desactiva.
- `-fanalizer`: Activa un analizador estático más avanzado integrado en `gcc`.
  Puede detectar problemas más complejos que las advertencias normales, como
  posibles fugas de memoria, dobles liberaciones de memoria (double free) o el
  uso de punteros nulos. Es una herramienta muy potente para mejorar la robustez
  del código.

Un comando de compilación robusto para desarrollo se vería así:

```{code-block} shell
$> gcc -Wall -Wextra -Werror -std=c23 -g -o mi_programa programa.c
```

Aunque es un montón, a continuación, vamos a ver como hacer que esto sea más
simple y no dependa de que nos acordemos este conjunto de opciones _cada vez_
que sea necesario compilar un programa.

### Documentación Oficial

[Manual en línea de GCC](https://gcc.gnu.org/onlinedocs/). La fuente definitiva
sobre todas las opciones y el funcionamiento del compilador.

## Archivos de Cabecera (`.h`) en C

Un archivo de cabecera (o `header`) en C actúa como un contrato o una interfaz
pública para un módulo de código. Su función principal es declarar los elementos
(como funciones y _tipos de datos_) que estarán disponibles para otros archivos
fuente que lo incluyan, sin exponer los detalles de su implementación.

### Propósitos Fundamentales

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

### ¿Que suelen contener?

Un archivo de cabecera puede contener varias clases de declaraciones, pero nunca
debería contener definiciones de funciones o inicializaciones de variables
globales.

#### Prototipos de Funciones

Es el contenido más común. Se declara la firma de la función (tipo de retorno,
nombre y parámetros) para que el compilador conozca su existencia antes de que
sea utilizada. Una buena documentación, como la que pide la regla {ref}`0x000Ah`, es fundamental.

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

#### Definiciones de Macros

Se utilizan para definir constantes simbólicas o pequeñas porciones de código
que se expanden durante el preprocesamiento.

```{code-block} c
:caption: Definición de constantes y macros

// Constante matemática documentada.
#define PI 3.1415926535
```

#### Definiciones de Tipos y Estructuras

Es el lugar ideal para declarar `struct`, `enum` y `typedef`, ya que estos tipos
de datos a menudo necesitan ser compartidos entre varios archivos. El uso del sufijo `_t` para los tipos definidos con `typedef` sigue la regla {ref}`0x001Eh`.

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

#### Declaraciones de Variables Globales

Si necesitás compartir una variable global entre varios archivos, la declarás en
el `.h` usando la palabra clave `extern` y la definís (le das un valor inicial)
en _un único_ archivo `.c`. Esta práctica está desaconsejada por la regla {ref}`0x000Bh`.

```{code-block} c
:caption: Declaración de una variable global externa
:emphasize-lines: 3

// Declara que la variable 'errno' existe en alguna parte del programa.
// La definición real se encuentra en la biblioteca estándar.
extern int errno;
```

### Guardas de Inclusión

Para evitar errores de "redefinición" que ocurren cuando un mismo archivo de
cabecera es incluido más de una vez en la misma unidad de compilación (archivo
`.c`), se utilizan las "guardas de inclusión", una técnica exigida por la regla de estilo {ref}`0x002Dh`.

El problema surge en escenarios como este: `main.c` incluye a `a.h` y `b.h`,
pero a su vez `a.h` también incluye a `b.h`. Sin una guarda, el contenido de
`b.h` se insertaría dos veces en `main.c`, causando un error.

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

:::{important} Cuestión de estilo
Aunque un archivo contenga únicamente prototipos de funciones (cuya
redeclaración no es un error), es una **buena práctica universal** y un
**requisito de la cátedra** es que **todos** los archivos de cabecera que
ustedes creen incluyan guardas de inclusión. Esto asegura consistencia,
prolijidad y previene errores futuros si el contenido del archivo cambia.
:::

## Makefiles

Hay una guia mucho más detallada para quienes quieran entender como funcionan
los [makefiles](../extras/makefiles).

### ¿Qué es un Makefile?

`make` es una utilidad que automatiza el proceso de compilación de un programa a
partir de su código fuente. Funciona leyendo un archivo especial llamado
`Makefile` que contiene un conjunto de reglas. Su principal ventaja es la
**compilación incremental**: `make` determina qué archivos han sido modificados
desde la última compilación y recompila únicamente lo necesario, ahorrando una
cantidad significativa de tiempo en proyectos grandes.

La herramienta se utiliza indicando que necesitamos para lograr un determinado
objetivo, qué ingredientes hay que preparar antes.

En este ejemplo, para crear el programa ejecutable `programa`, es necesario
`main.c` y `funciones.c`.

```{code-block} makefile
# Variables para el compilador, flags y archivos
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c23 -g
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

:::{attention} Indentación
Los _Makefiles_ deben ser indentados con tabulaciones, ya que si usamos espacios,
fallará.
:::

### Estructura básica de un TP con proyecto

Como aprender a crear Makefiles no es parte de los temas críticos de la cátedra,
hemos construido una estructura de proyecto que los utiliza y que nos permite
desarrollar las prácticas de una forma más profesional.

- `make`: compila todo
- `make clean`: limpia todos los archivos generados
- `make test`: compila y ejecuta pruebas en `prueba.c`
- `make run`: compila y ejecuta el programa en `mainc`

La tarea del Makefile de la raíz del proyecto, es conectar a todos los de los
diferentes ejercicios.

Y la estructura de un ejercicio individual está pensada para separar el `main`
de las funciones que resuelven el ejercicio en sí.

Cuando hacen `make test` allí, `make` ejecutará el objetivo `test` en todos los
subproyectos.

```{code-block} text
├── Makefile
├── libcadenas
│   ├── cadenas.c
│   ├── cadenas.h
│   ├── Makefile
│   └── prueba.c
├── ejercicio1
│   ├── ejercicio.c
│   ├── ejercicio.h
│   ├── main.c
│   ├── Makefile
│   └── prueba.c
└── ejercicio2
    ├── ejercicio.c
    ├── ejercicio.h
    ├── main.c
    ├── Makefile
    └── prueba.c
```

Pero, para trabajar específicamente en uno de los ejercicios, y en particular,
para no ver la salida de todos los otros ejercicios, la opción más simple es
ubicar nuestra consola en el ejercicio que estamos desarrollando.

Como verán, ¡hay un Makefile por directorio!. Esto es para que podamos compilar
por separado los ejercicios, que estarían en subdirectorios

Las primeras prácticas no contarán con el lugar para "librerías", pero la mecánica
es casi la misma, esencialmente, estas no tienen un `main.c`, solo `pruebas.c`.
Estos directorios estarán para alojar funciones comunes como las necesarias para
 `cadenas_seguras` o `arreglos`.
