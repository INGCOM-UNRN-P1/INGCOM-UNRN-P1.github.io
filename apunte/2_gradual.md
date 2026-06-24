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

## Las herramientas del aprendiz

### Preparación del entorno

Para los usuarios de Windows, la cátedra ha preparado un programa para simplificar la instalación de las herramientas necesarias para editar, compilar y ejecutar los programas.

[INGCOM-UNRN-P1/entorno](https://github.com/INGCOM-UNRN-P1/entorno)

Esencialmente, instala `clang`, `VSCode`, `git` y una terminal, tambien podes instalar manualmente todo siguiendo la guía: [compilador](../guias/compilador)

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

## El Algoritmo: pensar antes de escribir

### Mentalidad de programador

1. **Leé el problema. Comprendelo. Diseñalo.**
2. **Dividilo en pasos simples e inequívocos** en papel o pseudocódigo.
3. **Escribí el código en C** basándote únicamente en el algoritmo diseñado.

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
    printf("Ingresá dos números: ");
    scanf("%d %d", &a, &b);
    printf("La suma es: %d\n", a + b);
    return 0;
}
```

---

## Sobre las reglas de estilo

El uso de reglas de estilo es fundamental para garantizar la consistencia y legibilidad del código. Al adherirse a normas uniformes (como nomenclatura, indentación y posición de llaves), se facilita la colaboración y el mantenimiento del software. Para más detalles, consultá la regla {ref}`0x0000h`.

---

## Sintaxis y Semántica Básica

La **sintaxis** es el conjunto de reglas formales que definen cómo debe escribirse el código para que sea válido para el compilador.
La **semántica** determina el significado lógico, la estructura y el comportamiento real que tiene el código durante su ejecución. Un código puede ser sintácticamente correcto pero semánticamente erróneo.

### Identificadores y Palabras Reservadas

**Identificadores:** Son los nombres que asignamos a variables, constantes y funciones. Deben comenzar obligatoriamente con una letra o guion bajo (`_`) y pueden contener letras, dígitos y guiones bajos. C distingue entre mayúsculas y minúsculas (`suma` es un identificador distinto de `Suma`). No pueden coincidir con palabras reservadas del lenguaje.

**Palabras Reservadas:** Son palabras clave del lenguaje C que poseen un significado sintáctico especial predefinido y no pueden ser utilizadas como identificadores (ej: `int`, `float`, `char`, `if`, `else`, `while`, `return`).

Nuestros identificadores deben respetar las pautas de estilo (ver {ref}`0x0001h`).

---


(estado-programa)=
## Estado de un Programa

El **estado de un programa** (del inglés, _program state_) en un instante de
tiempo $t$ es la colección completa y precisa de toda la información mutable que
define al programa en ese momento. Es una instantánea (snapshot) que, si se
pudiera capturar y restaurar, permitiría que la ejecución del programa
continuara desde ese punto exacto sin ninguna diferencia observable.

Comprender el estado es fundamental para el debugging, la concurrencia y el
análisis del comportamiento del programa. Se compone de varios elementos
distribuidos en la memoria y en los registros del procesador.

### Componentes Principales del Estado

El estado de un programa en C se almacena principalmente en las siguientes áreas
de memoria y registros de la CPU:

#### 1\. **La Pila (Stack)**

Es una región de memoria gestionada por el compilador bajo un modelo LIFO
(Last-In, First-Out). Cada vez que se invoca una función, se crea un nuevo
**marco de pila** (_stack frame_) que se apila sobre el anterior.

El _stack frame_ de una función contiene:

- **Variables locales:** Todas las variables declaradas dentro del ámbito de la
  función que no son estáticas.
- **Parámetros de la función:** Las copias de los argumentos pasados a la
  función.
- **Dirección de retorno:** La dirección de la instrucción en el código a la que
  el programa debe volver cuando la función actual finalice.
- **Información de estado de la pila anterior:** Un puntero al _stack frame_ de
  la función que la llamó (el llamador o _caller_).

El estado en la pila es **volátil y efímero**; se crea al entrar en una función
y se destruye al salir de ella.

#### 2\. **El Montículo (Heap)**

Es una región de memoria para la **asignación dinámica**. A diferencia de la
pila, su gestión es explícita y responsabilidad del programador mediante el uso
de funciones de la biblioteca estándar como `malloc()`, `calloc()`, `realloc()`
y `free()`.

El estado en el montículo incluye todos los bloques de memoria reservados que no
han sido liberados. El acceso a estos bloques se realiza a través de punteros,
los cuales pueden residir en la pila, en el segmento de datos, o incluso en otro
bloque del propio montículo. La gestión incorrecta del heap (e.g., no liberar
memoria con `free()`) conduce a **fugas de memoria** (_memory leaks_).

#### 3\. **Segmentos de Datos Estáticos**

Estas áreas de memoria se asignan cuando el programa se carga y persisten
durante toda su ejecución. Se dividen principalmente en dos:

- **Segmento `.data`:** Contiene las **variables globales y estáticas** que son
  explícitamente inicializadas por el programador. Por ejemplo:
  `int contador_global = 10;`.
- **Segmento `.bss` (Block Started by Symbol):** Contiene las **variables
  globales y estáticas** que no son inicializadas explícitamente. El sistema
  operativo se encarga de inicializar esta memoria a cero antes de que comience
  la ejecución del programa. Por ejemplo: `static int buffer_interno;`.

El contenido de estas variables forma una parte persistente del estado del
programa.

#### 4\. **Contexto de Ejecución (CPU)**

El estado no reside únicamente en la memoria RAM, sino también en los registros
internos de la CPU.

- **Contador de Programa (Program Counter - PC):** Es el registro más crítico.
  Contiene la dirección de memoria de la próxima instrucción que se va a
  ejecutar. Su valor define el punto exacto de la ejecución dentro del segmento
  de código (`.text`).
- **Registros de Propósito General:** Almacenan operandos y resultados
  intermedios de operaciones aritméticas, lógicas y de transferencia de datos.
  El contenido de estos registros es una parte muy volátil pero esencial del
  estado en un instante preciso.

#### 5\. **Estado Externo**

Un programa interactúa con el sistema operativo y otros sistemas. Este estado
incluye:

- **Descriptores de archivo (File Descriptors):** Enteros que representan
  archivos abiertos, sockets de red, pipes, etc. El estado incluye qué archivos
  están abiertos y la posición actual del cursor de lectura/escritura en cada
  uno.
- **Buffers de E/S (I/O Buffers):** Datos que han sido escritos por el programa
  pero aún no han sido vaciados (_flushed_) al disco o a la red, y viceversa.

### Ejemplo Práctico Detallado

Analicemos el estado en un punto específico del siguiente programa en C:

```c
#include <stdio.h>
#include <stdlib.h>

int accesos_totales = 0; // Segmento .data (inicializado)
char* puntero_global;   // Segmento .bss (no inicializado, será NULL)

void procesar(int factor) {
    int i; // En la pila (stack)
    for (i = 0; i < factor; i++) {
        accesos_totales++;
    }
    char* buffer_local = malloc(10 * sizeof(char)); // Puntero 'buffer_local' en la pila.
                                                    // El bloque de 10 bytes está en el montículo (heap).
    // PUNTO DE ANÁLISIS DEL ESTADO
    sprintf(buffer_local, "Hola");
    puntero_global = buffer_local;
}

int main() {
    procesar(5);
    printf("%s\n", puntero_global);
    free(puntero_global); // Liberamos la memoria del montículo.
    return 0;
}
```

### Tipos de operadores

- Aritméticos: `+ - * / %`
- Unarios: `++ -- -`
- Relacionales: `> < >= <= == !=`
- Lógicos: `! && ||`

Importante:

- El resultado de una comparación (`x < 3`) es `int` (1 si es verdadera, 0 si es
  falsa).
- Cualquier número distinto de 0 se considera **verdadero**.**Snapshot del
  Estado en el "PUNTO DE ANÁLISIS" (dentro de `procesar`):**
- **Pila (Stack):**

  - **Marco de `main()`:** (En la base de la pila, más abajo) Contiene su propia
    información, incluyendo la dirección de retorno después de la llamada a
    `procesar()`.

  - **Marco de `procesar()`:** (En la cima de la pila)
    - Parámetro `factor`: su valor es `5`.
    - Variable local `i`: su valor es `5` (valor final tras el bucle `for`).
    - Variable local `buffer_local`: es un puntero. Contiene la **dirección de
      memoria** del primer byte del bloque de 10 bytes que `malloc` asignó en el
      montículo.
    - Dirección de retorno: apunta a la instrucción `printf` en `main`.

- **Montículo (Heap):**

  - Existe un bloque de **10 bytes** de memoria reservada. La dirección de este
    bloque es el valor almacenado en `buffer_local`. Justo antes de `sprintf`,
    su contenido es indeterminado. Justo después, sus primeros 5 bytes
    contendrán los caracteres `'H'`, `'o'`, `'l'`, `'a'`, `'\0'`.

- **Segmento de Datos:**

  - **`.data`:** La variable `accesos_totales` tiene el valor `5`.
  - **`.bss`:** La variable `puntero_global` todavía tiene su valor inicial
    `NULL` (cero), ya que la asignación `puntero_global = buffer_local;` aún no
    se ha ejecutado.

- **Contexto de la CPU:**
  - **Contador de Programa (PC):** Apunta a la dirección de memoria de la
    instrucción correspondiente a la línea `sprintf(buffer_local, "Hola");`.
  - **Registros:** Contendrán valores intermedios. Por ejemplo, un registro
    probablemente contenga la dirección de `buffer_local` y otro la dirección de
    la cadena literal `"Hola"`, listos para ser usados como argumentos para
    `sprintf`.

### Transiciones de Estado

El programa es una máquina que transita de un estado a otro. Cada instrucción
ejecutada modifica el estado:

- Una asignación (`x = 10;`) modifica la memoria donde reside `x`.
- Una llamada a función (`procesar(5);`) crea un nuevo marco en la pila y cambia
  el `PC`.
- Un `return` destruye el marco de pila actual y restaura el `PC` a la dirección
  de retorno.
- `malloc()` modifica el estado del montículo.
- Una operación de E/S (`printf()`) puede modificar un buffer interno y
  eventualmente el estado de un dispositivo externo (la consola).

Dominar el concepto de estado es pasar de "escribir código que funciona" a
"entender por qué y cómo funciona", lo cual es indispensable para la
programación de sistemas de bajo nivel.

De acuerdo. A continuación, una ampliación del concepto que generaliza la idea
de estado más allá de su implementación técnica en C, enfocándose en su rol como
información unificada.

---

### Ampliación: El Estado como Información y Potencialidad

Si nos abstraemos de la implementación física (pila, montículo, registros),
podemos entender el **estado del programa** desde una perspectiva teórica más
amplia, como un concepto de la teoría de la información y de los sistemas
dinámicos.

#### El Programa como una Trayectoria en un Espacio de Estados

Imaginemos un vasto universo multidimensional donde cada punto representa un
único estado posible que el programa podría adoptar. Este universo es el
**Espacio de Estados** (_State Space_) del programa. Cada variable, cada byte en
el montículo, cada registro de la CPU, es una dimensión de este espacio.

La ejecución de un programa no es más que una **trayectoria** o un camino a
través de este espacio. Cada instrucción de la CPU es un pequeño paso que mueve
al programa de un punto (estado $S_t$) a otro punto muy cercano (estado
$S_{t+1}$).

- **Punto de Origen:** El estado inicial del programa (variables globales en
  cero o sus valores iniciales, pila vacía excepto por el marco de `main`,
  etc.).
- **Trayectoria:** La secuencia de estados por los que pasa el programa.
- **Punto Final:** El estado terminal, cuando `main` retorna o se invoca
  `exit()`.

Desde esta óptica, el estado en su conjunto es la **coordenada exacta del
programa dentro de su universo de posibilidades** en un instante dado.

#### Determinismo y la Flecha del Tiempo del Programa

Un sistema es **determinista** si su estado futuro está completamente
determinado por su estado actual y sus entradas. Gran parte de un programa en C
es determinista: si el estado en $t$ es conocido, el resultado de `x = y + z;`
es predecible y llevará a un único estado $t+1$.

Sin embargo, los programas interactúan con el exterior, introduciendo
**no-determinismo**. El estado del programa se ve afectado por eventos cuyo
tiempo y contenido no están bajo el control del código:

- **Entrada del usuario:** El próximo estado depende de qué tecla se presione y
  cuándo.
- **Concurrencia:** La intercalación de hilos (_thread scheduling_) por el
  sistema operativo es no-determinista. Dos ejecuciones idénticas pueden tener
  trayectorias diferentes en el espacio de estados.
- **Datos de red o archivos:** El contenido recibido de un socket o leído de un
  disco.

El estado, por lo tanto, es el registro de la historia única de la trayectoria
del programa, incluyendo cómo resolvió las bifurcaciones no-deterministas que
encontró.

#### El Estado como Información y Potencialidad

En su nivel más fundamental, el estado es la **encarnación de la información**
que el programa ha acumulado. Es su memoria. Contiene todo lo que el programa
"sabe" sobre su ejecución pasada y sobre las interacciones con su entorno.

Pero más importante aún, el estado define la **potencialidad** del programa. El
estado actual no solo describe el "ahora", sino que **restringe drásticamente el
conjunto de estados futuros posibles**.

- Si un puntero en el estado es `NULL`, cualquier trayectoria futura que intente
  desreferenciarlo es inválida (resultará en un _segmentation fault_). El estado
  `puntero = NULL` elimina una vasta cantidad de futuros posibles.
- Si una variable `autenticado` es `false`, las ramas del código que requieren
  autenticación son inaccesibles. La trayectoria del programa está constreñida a
  otras partes del espacio de estados.

En resumen, la detallada distribución del estado en la pila, el montículo y los
registros es el **sustrato físico** donde se almacena esta información
abstracta. El estado en su conjunto es lo que da **identidad y continuidad al
proceso en ejecución**, diferenciándolo del código estático y muerto (`.text`)
del cual se originó. Es la suma de su memoria y la definición de su potencial
futuro.


---

(roles-variables)=
## Roles de las Variables

# Roles de Variables en Programación

¡Hola a todos! Hoy vamos a sumergirnos en un concepto fundamental en
programación que nos ayudará a entender mejor cómo las variables no solo
almacenan valores, sino que cumplen **roles específicos** dentro de nuestros
programas. A menudo, cuando empezamos a programar, pensamos en las variables
simplemente como "cajas" para guardar datos. Sin embargo, si profundizamos un
poco más, veremos que muchas de ellas tienen un propósito particular, casi como
si tuvieran una "función" o un "papel" en el algoritmo.

---

## El "Rol" de una Variable

En programación, el **rol de una variable** se refiere a la función o propósito
específico que una variable desempeña dentro de un algoritmo. No es solo lo que
la variable _contiene_, sino para _qué_ la usamos. Identificar el rol de una
variable nos permite diseñar algoritmos más claros, eficientes y fáciles de
depurar. Es como asignar una tarea a cada miembro de un equipo; cada uno tiene
su función y sabe qué hacer.

Vamos a explorar algunos de los roles más comunes que encontramos en la
programación, usando ejemplos en **C**.

---

### Acumulador

Un **acumulador** es una variable que se utiliza para **sumar o acumular
valores** a lo largo de un proceso. Generalmente, se inicializa en cero antes de
que comience el proceso de acumulación.

---

### Ejemplo de Acumulador en C

Imaginemos que queremos calcular la suma de los primeros N números enteros.

```c
#include <stdio.h>

int main() {
    int n;
    int suma = 0; // Aquí, 'suma' es nuestro acumulador
    printf("Ingrese un numero entero N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        suma = suma + i; // Se acumulan los valores en cada iteración
    }

    printf("La suma de los primeros %d numeros es: %d\n", n, suma);
    return 0;
}
```

En este ejemplo, la variable `suma` tiene el rol de **acumulador**. En cada
iteración del bucle `for`, se le suma el valor actual de `i`, acumulando así la
suma total.

---

### Contador

Un **contador** es una variable que se utiliza para **contar la ocurrencia de un
evento** o para **llevar un registro del número de iteraciones** en un bucle. Se
incrementa o decrementa en un valor fijo (usualmente 1) cada vez que el evento
ocurre.

---

### Ejemplo de Contador en C

Supongamos que queremos contar cuántos números pares hay en un rango dado.

```c
#include <stdio.h>

int main() {
    int inicio, fin;
    int contadorPares = 0; // Aquí, 'contadorPares' es nuestro contador

    printf("Ingrese el inicio del rango: ");
    scanf("%d", &inicio);
    printf("Ingrese el fin del rango: ");
    scanf("%d", &fin);

    for (int i = inicio; i <= fin; i++) {
        if (i % 2 == 0) {
            contadorPares++; // Se incrementa el contador si el número es par
        }
    }

    printf("En el rango de %d a %d, hay %d numeros pares.\n", inicio, fin, contadorPares);
    return 0;
}
```

En este caso, `contadorPares` tiene el rol de **contador**. Cada vez que
encontramos un número par, incrementamos su valor en 1.

---

### Bandera (o Flag)

Una **bandera** (o _flag_) es una variable booleana (o entera que simula un
booleano, como 0 o 1) que se utiliza para **señalizar una condición o estado**.
Su valor cambia para indicar que un evento ha ocurrido o que una determinada
situación es verdadera o falsa.

---

### Ejemplo de Bandera en C

Vamos a buscar si un número específico está presente en un array.

```c
#include <stdio.h>
#include <stdbool.h> // Para usar el tipo de dato bool

int main() {
    int numeros[] = {10, 25, 4, 30, 8, 15};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    int numeroBuscado = 8;
    bool encontrado = false; // Aquí, 'encontrado' es nuestra bandera

    for (int i = 0; i < tamano; i++) {
        if (numeros[i] == numeroBuscado) {
            encontrado = true; // La bandera se activa si encontramos el número
            break; // Podemos salir del bucle una vez que lo encontramos
        }
    }

    if (encontrado) {
        printf("El numero %d fue encontrado en el array.\n", numeroBuscado);
    } else {
        printf("El numero %d NO fue encontrado en el array.\n", numeroBuscado);
    }

    return 0;
}
```

La variable `encontrado` es una **bandera**. Se inicializa en `false` y se
cambia a `true` si el `numeroBuscado` es hallado en el array. Luego, podemos
usar el estado de esta bandera para tomar una decisión.

---

## Otros Roles de Variables

Además de los acumuladores, contadores y banderas, las variables pueden adoptar
una variedad de roles, algunos más específicos o que surgen en contextos
particulares.

---

### Variable de Control de Bucle (o Iterador)

Este es un rol que a menudo usamos sin siquiera pensarlo. La **variable de
control de bucle** es la que se encarga de controlar las repeticiones de un
ciclo, generalmente incrementándose o decrementándose en cada iteración hasta
que se cumple una condición de finalización.

```c
#include <stdio.h>

int main() {
    // 'i' es la variable de control de bucle
    for (int i = 0; i < 5; i++) {
        printf("Iteracion numero: %d\n", i);
    }
    return 0;
}
```

En este caso, `i` controla cuántas veces se ejecuta el bucle `for` y en qué
punto debe detenerse.

---

### Variable Auxiliar o Temporal

Una **variable auxiliar o temporal** se usa para almacenar un valor de forma
transitoria, generalmente para facilitar una operación que requiere conservar un
dato mientras se manipulan otros. El caso más común es el intercambio de valores
entre dos variables sin perder ninguno.

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int temp; // 'temp' es nuestra variable auxiliar

    printf("Antes del intercambio: a = %d, b = %d\n", a, b);

    temp = a; // Guarda el valor de 'a'
    a = b;    // 'a' toma el valor de 'b'
    b = temp; // 'b' recupera el valor original de 'a' desde 'temp'

    printf("Despues del intercambio: a = %d, b = %d\n", a, b);
    return 0;
}
```

Aquí, `temp` es crucial para no perder el valor original de `a` cuando se lo
asignamos a `b`.

---

### Variable de Estado

Similar a una bandera, pero una **variable de estado** puede tener más de dos
valores, representando diferentes fases, modos o condiciones dentro de un
programa o sistema. Piensa en un semáforo que puede estar en rojo, amarillo o
verde.

```c
#include <stdio.h>

// Definimos constantes para los estados
#define ESTADO_INICIANDO 0
#define ESTADO_PROCESANDO 1
#define ESTADO_FINALIZADO 2

int main() {
    int estadoActual = ESTADO_INICIANDO; // 'estadoActual' es nuestra variable de estado

    printf("Estado actual: %d\n", estadoActual);

    // Simulamos un cambio de estado
    estadoActual = ESTADO_PROCESANDO;
    printf("Nuevo estado: %d\n", estadoActual);

    // Simulamos otro cambio de estado
    estadoActual = ESTADO_FINALIZADO;
    printf("Estado final: %d\n", estadoActual);

    return 0;
}
```

La variable `estadoActual` cambia para indicar la fase en la que se encuentra el
proceso.

---

### Variable de Entrada

Una **variable de entrada** es aquella que se utiliza para almacenar datos que
provienen de una fuente externa al programa, como la entrada del usuario a
través del teclado, la lectura de un archivo o datos recibidos de una red.

```c
#include <stdio.h>

int main() {
    int edad; // 'edad' es una variable de entrada

    printf("Por favor, ingresa tu edad: ");
    scanf("%d", &edad); // Aquí, el valor ingresado se guarda en 'edad'

    printf("Tu edad es: %d años.\n", edad);
    return 0;
}
```

En este ejemplo, `edad` toma el valor que el usuario introduce.

---

### Variable de Salida

Las **variables de salida** se utilizan para almacenar los resultados finales de
un cálculo o proceso, los cuales serán mostrados al usuario o guardados en algún
medio (como un archivo).

```c
#include <stdio.h>

int main() {
    float radio = 5.0;
    float area; // 'area' es una variable de salida (resultado)

    // Calculamos el área del círculo
    area = 3.14159 * radio * radio;

    printf("El area del circulo con radio %.2f es: %.2f\n", radio, area); // Se muestra el valor de 'area'
    return 0;
}
```

Aquí, `area` guarda el resultado del cálculo y luego se imprime.

---

### Variable de Referencia (o Puntero)

Aunque en C los punteros son un concepto más avanzado, un puntero es una
variable que almacena la **dirección de memoria** de otra variable. Su rol es
"apuntar" a datos, permitiendo un acceso y manipulación indirecta de la memoria.

```c
#include <stdio.h>

int main() {
    int numero = 100;
    int *ptrNumero; // 'ptrNumero' es un puntero, su rol es referenciar a 'numero'

    ptrNumero = &numero; // 'ptrNumero' ahora apunta a la dirección de 'numero'

    printf("Valor de numero: %d\n", numero);
    printf("Direccion de numero: %p\n", (void*)&numero);
    printf("Valor al que apunta ptrNumero: %d\n", *ptrNumero); // Desreferencia el puntero
    printf("Valor de ptrNumero (direccion): %p\n", (void*)ptrNumero);

    // Modificando 'numero' a traves del puntero
    *ptrNumero = 200;
    printf("Nuevo valor de numero (modificado via puntero): %d\n", numero);

    return 0;
}
```

El rol de `ptrNumero` es el de una **variable de referencia**, permitiendo
interactuar con `numero` de forma indirecta.

---

## Roles de Variables y Parámetros Útiles en Funciones

Cuando hablamos de funciones, las variables internas y, crucialmente, los
**parámetros** (que son variables que reciben valores cuando se llama a la
función) también asumen roles distintivos:

---

### Parámetro de Entrada

Un **parámetro de entrada** es una variable que recibe un valor de la parte que
llama a la función (el "código invocador"). Su rol es **proporcionar a la
función los datos necesarios** para que realice su tarea. La función usa este
valor, pero generalmente no lo modifica de forma que el llamador vea ese cambio
(a menos que se pase por referencia).

```c
#include <stdio.h>

// 'num1' y 'num2' son parámetros de entrada
int sumar(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

int main() {
    int a = 5;
    int b = 3;
    int sumaTotal;

    // 'a' y 'b' se pasan como argumentos a los parámetros de entrada 'num1' y 'num2'
    sumaTotal = sumar(a, b);
    printf("La suma es: %d\n", sumaTotal);
    return 0;
}
```

En la función `sumar`, `num1` y `num2` son **parámetros de entrada**. Reciben
los valores `5` y `3` respectivamente, y la función los usa para realizar la
suma.

---

### Parámetro de Salida (a través de Punteros)

En C, como los parámetros se pasan "por valor" por defecto (lo que significa que
la función recibe una copia del valor y los cambios internos no afectan al
original), para que una función pueda **modificar una variable del llamador y
"devolver" un resultado a través de ella**, necesitamos usar **punteros**. Un
parámetro que es un puntero y se usa con este fin se convierte en un **parámetro
de salida**.

```c
#include <stdio.h>

// 'resultado' es un parámetro de salida (puntero)
void dividir(int dividendo, int divisor, int *cociente, int *resto) {
    if (divisor != 0) {
        *cociente = dividendo / divisor; // Modifica el valor apuntado por 'cociente'
        *resto = dividendo % divisor;   // Modifica el valor apuntado por 'resto'
    } else {
        printf("Error: Division por cero.\n");
        // Podríamos asignar valores especiales o manejar el error de otra forma
        *cociente = 0;
        *resto = 0;
    }
}

int main() {
    int num1 = 17;
    int num2 = 5;
    int miCociente;
    int miResto;

    // Pasamos las direcciones de 'miCociente' y 'miResto'
    dividir(num1, num2, &miCociente, &miResto);

    printf("%d dividido por %d es: Cociente = %d, Resto = %d\n", num1, num2, miCociente, miResto);
    return 0;
}
```

Aquí, `cociente` y `resto` son **parámetros de salida**. La función `dividir`
escribe directamente en las ubicaciones de memoria de `miCociente` y `miResto`
en la función `main` a través de sus punteros, permitiendo que `main` acceda a
los resultados de la división.

---

### Parámetro de Entrada/Salida (a través de Punteros)

Similar al parámetro de salida, un **parámetro de entrada/salida** es un puntero
que permite a la función **leer un valor inicial del llamador y luego
modificarlo**, devolviendo el valor modificado al llamador. Su rol es tanto
recibir datos como devolver datos alterados.

```c
#include <stdio.h>

// 'contador' es un parámetro de entrada/salida
void incrementarContador(int *contador) {
    printf("Valor del contador al entrar a la funcion: %d\n", *contador);
    (*contador)++; // Incrementa el valor apuntado por 'contador'
    printf("Valor del contador al salir de la funcion: %d\n", *contador);
}

int main() {
    int miVariableContador = 10;

    printf("Valor inicial de miVariableContador: %d\n", miVariableContador);

    // Pasamos la dirección de 'miVariableContador'
    incrementarContador(&miVariableContador);

    printf("Valor final de miVariableContador: %d\n", miVariableContador);
    return 0;
}
```

En este caso, `contador` en `incrementarContador` es un **parámetro de
entrada/salida**. La función lee el valor inicial de `miVariableContador`
(`10`), lo incrementa a `11`, y ese cambio se refleja directamente en
`miVariableContador` en `main`.

---

### Variable Local Temporal (en funciones)

Dentro de una función, las variables locales a menudo asumen roles temporales
similares a la variable auxiliar que vimos antes. Su alcance se limita a la
función, y su rol es **servir como espacio de trabajo para cálculos
intermedios** que no necesitan ser devueltos directamente.

```c
#include <stdio.h>

float calcularPromedio(int a, int b, int c) {
    // 'sumaTemporal' es una variable local temporal
    int sumaTemporal = a + b + c;
    float promedio = (float)sumaTemporal / 3.0; // 'promedio' es una variable de salida local
    return promedio;
}

int main() {
    float resultadoPromedio = calcularPromedio(10, 20, 30);
    printf("El promedio es: %.2f\n", resultadoPromedio);
    return 0;
}
```

Aquí, `sumaTemporal` es una **variable local temporal** dentro de
`calcularPromedio`. Su único propósito es almacenar la suma intermedia antes de
calcular el promedio final.

---

### La Importancia de los Roles

Entender estos roles te da una perspectiva más rica sobre cómo funcionan tus
programas. No se trata solo de saber qué tipo de dato almacena una variable,
sino **para qué la estás usando**. Reconocer estos patrones te ayudará a:

- **Escribir código más limpio y legible.**
- **Depurar errores más fácilmente.**
- **Diseñar algoritmos más eficientes y comprensibles.**

Comprender estos roles, especialmente la distinción entre pasar por valor y
pasar por referencia (con punteros) para lograr parámetros de salida o
entrada/salida, es **crucial para diseñar funciones robustas y predecibles en
C**. Te ayuda a definir claramente la "interfaz" de tu función: qué necesita
para trabajar y qué tipo de resultados puede ofrecer de vuelta al código que la
llama.

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


### Ejercicio 1

:::{exercise}
:label: Mostrando valores
:enumerator: Valores
Escribí un programa en C que declare e inicialice variables para tu edad, tu altura en metros y tu inicial de nombre, y muestre sus valores en la consola.
:::

:::{solution} Mostrando valores
:class: dropdown

```{code-block} c
:linenos:

#include <stdio.h>

int main() {
    int edad = 20;
    float altura = 1.82f;
    char inicial = 'J';

    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}
```
:::

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

### `scanf()` - Entrada Formateada

Permite leer datos de entrada ingresados por teclado en la entrada estándar (`stdin`). Requiere pasar la dirección de la variable de destino anteponiendo el operador de dirección `&`.

```c
int edad = 0;
printf("Ingrese su edad: ");
scanf("%d", &edad);
```

#### El Buffer de Entrada y la Lectura de Caracteres

Al presionar "Enter" para enviar datos en la consola, se agrega un carácter de salto de línea (`\n`) en el buffer de entrada `stdin`. Si la siguiente instrucción lee un carácter (`scanf("%c")`), leerá ese `\n` residual en lugar de la entrada esperada. Para evitar esto, se debe anteponer un espacio en blanco en el especificador (`" %c"`), lo cual instruye a `scanf` a descartar los espacios en blanco y saltos de línea residuales del buffer.

```c
char inicial = ' ';
printf("Ingrese su inicial: ");
scanf(" %c", &inicial); // El espacio antes de %c limpia el buffer de stdin
```

### Ejercicio 2

:::{exercise}
:label: entrada-1
Pedí al usuario que ingrese su inicial de nombre, edad y calificación promedio, y mostralos formateados en pantalla.
:::

:::{solution} entrada-1
:class: dropdown
```{code-block} c
:linenos:

#include <stdio.h>

int main() {
    char inicial = ' ';
    int edad = 0;
    float promedio = 0.0f;

    printf("Ingrese su inicial: ");
    scanf(" %c", &inicial);

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su promedio: ");
    scanf("%f", &promedio);

    printf("Inicial: %c, Edad: %d, Promedio: %.2f\n", inicial, edad, promedio);
    return 0;
}
```
:::


## Decisiones Condicionales

Las decisiones permiten que el flujo de ejecución tome distintos caminos con base en condiciones lógicas booleanas.

:::{figure} 2/if_else_flow.svg
:name: fig-if-else-flow
:alt: Flujo de control con if/else

El programa evalúa condiciones lógicas y ejecuta el bloque de instrucciones correspondiente.
:::

### Estructura `if...else if...else`

```c
if (condicion) {
    // Bloque ejecutado si la condición es verdadera
} else if (otra_condicion) {
    // Bloque ejecutado si la condición anterior fue falsa y esta es verdadera
} else {
    // Bloque ejecutado si ninguna condición fue verdadera
}
```

Las condiciones evaluadas deben ser expresiones de comparación explícitas (ver regla de estilo {ref}`0x1005h`). Recuerde que en esta cátedra **es obligatorio el uso de llaves** para delimitar el bloque de toda estructura de control (ver regla {ref}`0x0005h`).

:::{note} «Veracidad»
Para C, los valores lógicos no forman parte del lenguaje original y el mismo
considera cualquier valor entero en `0` como falso y cualquier otro como
verdadero. Esto se conoce como "veracidad" ({ref}`0x1005h`) y su uso no
está permitido, ya que puede generar confusión.
:::

### Operadores de comparación y lógicos
- `==` (Igualdad), `!=` (Desigualdad), `>`, `<`, `>=`, `<=`
- `&&` (Y lógico), `||` (O lógico), `!` (Negación lógica)

```c
if (edad >= 18) {
    printf("Mayor de edad\n");
} else {
    printf("Menor de edad\n");
}
```

### Ejercicio 3

:::{exercise}
:label: entrada-2
:enumerator: entrada-2

Pedí al usuario que ingrese su nota final (entera) e imprimí su condición:
- "Promociona" si la nota es mayor o igual a 6.
- "Aprueba" si la nota es mayor o igual a 4 pero menor a 6.
- "Desaprueba" si la nota es menor a 4.
:::

:::{solution} entrada-2
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    int nota = 0;
    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    if (nota >= 6) {
        printf("Promociona\n");
    } else if (nota >= 4) {
        printf("Aprueba\n");
    } else {
        printf("Desaprueba\n");
    }
    return 0;
}
```
:::

### Bifurcación Múltiple con `switch`

Permite comparar el valor de una variable entera contra múltiples constantes de forma directa:

```c
switch (opcion) {
    case 1:
        // Código para opción 1
        break;
    case 2:
        // Código para opción 2
        break;
    default:
        // Código si no coincide con ningún caso anterior (obligatorio)
        break;
}
```

---

## Estructuras de Repetición (Lazos)

Un **lazo** es una estructura lógica que repite un bloque de instrucciones mientras se verifique una condición de permanencia.

Hay tres construcciones principales de lazos en C:
- `while`: Evalúa la condición antes de ejecutar cada iteración.
- `for`: Lazo estructurado controlado por un contador o rango definido.
- `do...while`: Ejecuta el bloque de código al menos una vez antes de evaluar la condición.

### `while` — Iteración condicional

El bloque de código interno se ejecuta mientras la condición lógica sea verdadera.

```c
int i = 0;
while (i < 5) {
    printf("i vale %d\n", i);
    i = i + 1;
}
```

:::{figure} 2/while_loop_flow.svg
:name: fig-while-flow
:alt: Flujo del lazo while

Diagrama de flujo del lazo while: evalúa la condición, ejecuta el bloque si es verdadera, y repite hasta que la condición sea falsa.
:::

### Ejercicio 4

:::{exercise}
:label: lazo_while 
:enumerator: while

Escribí un programa en C que imprima los números del 10 al 1 de forma descendente usando un lazo `while`.
:::

:::{solution} lazo_while
:label: solucion-lazo_while
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int i = 10;
    while (i >= 1) {
        printf("%d\n", i);
        i = i - 1;
    }
    return 0;
}
```
:::

### `for` — Iteración controlada por contador

Es la estructura recomendada para repeticiones de rango conocido. Su sintaxis concentra el control de la iteración:

```c
for (inicialización; condición; incremento)
{
    // Bloque de instrucciones
}
```

:::{admonition} Las partes del `for`
`for (inicio; condición; paso) { bloque }`

- **inicio:** una sola vez al comenzar.
- **condición:** se evalúa antes de cada iteración.
- **paso:** se ejecuta al final de cada vuelta.
- **bloque:** las instrucciones ejecutadas mientras la condición sea verdadera.
:::


Este tipo de lazo es ideal cuando se sabe cuántas veces se quiere repetir.
Aunque hace lo mismo que el `while`, este es más estructurado con secciones
específicas para cada acción del lazo.

```c
for (int i = 0; i < 5; i++) {
    printf("i vale %d\n", i);
}
```

### Ejercicio 5

:::{exercise}
:label: lazo_for
:enumerator: for
Usá un lazo `for` para mostrar los números múltiplos de 3 comprendidos en el rango de 0 a 30 inclusive.
:::

:::{solution} lazo_for
:label: solucion-lazo_for
:class: dropdown
```c
#include <stdio.h>

int main() {
    for (int i = 0; i <= 30; i = i + 1) {
        if (i % 3 == 0) {
            printf("%d es múltiplo de 3\n", i);
        }
    }
    return 0;
}
```
:::

### `do...while` — Ejecución obligatoria al menos una vez

Garantiza que el bloque se ejecutará al menos una vez antes de verificar la condición lógica de permanencia.

```{image} ./2/lazos.jpg
:alt: Ejemplo Grafico de lazos
:align: center
```

```c
int clave = 0;
do {
    printf("Ingrese la clave de acceso (1234): ");
    scanf("%d", &clave);
} while (clave != 1234);
```

```mermaid
flowchart TD
    Inicio --> Ejecutar[Ejecutar bloque de código]
    Ejecutar --> Cond{¿Se cumple la condición?}
    Cond -- Sí --> Ejecutar
    Cond -- No --> Fin
```

### Ejercicio 6

:::{exercise}
:label: lazo_repeat
:enumerator: for

Diseñá un programa con un lazo `do...while` que solicite repetidamente una clave de acceso numérica al usuario hasta que ingrese el valor correcto `1234`.
:::

:::{solution} lazo_repeat
:label: solucion-lazo_repeat
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int clave = 0;
    int clave_correcta = 1234;

    do {
        printf("Ingrese la clave: ");
        scanf("%d", &clave);

        if (clave != clave_correcta) {
            printf("Clave incorrecta. Reintente.\n");
        }
    } while (clave != clave_correcta);

    printf("Acceso concedido.\n");
    return 0;
}
```
:::

---

## Control de Flujo Seguro de Lazos

### Atajos en Lazos: `break` y `continue`

C provee dos instrucciones de control para alterar el flujo normal de iteración de los lazos:

#### `break` (Interrupción)
Finaliza la ejecución del lazo de forma inmediata, saltando a la primera instrucción que se encuentre fuera del bloque del ciclo.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break; // Sale inmediatamente del lazo cuando i vale 5
    }
    printf("i = %d\n", i);
}
```

#### `continue` (Salto de iteración)
Omite el resto del bloque de instrucciones del ciclo actual y avanza directamente a evaluar la condición para la siguiente iteración.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue; // Salta al final del bloque e inicia la iteración de i = 4
    }
    printf("i = %d\n", i);
}
```

### Prohibición de `break` y `continue`

**En esta cátedra, el uso de las instrucciones `break` (fuera de un bloque `switch`) y `continue` para modificar el flujo de repetición de los lazos esta prohibidas** (ver regla de estilo {ref}`0x1002h`). 

Esta restricción responde a dos vectores fundamentales del diseño de software:
1.  **Legibilidad y Mantenibilidad:** Crear múltiples puntos de salida invisibles en el cuerpo de un lazo de control oscurece la trazabilidad de la lógica. El código se vuelve difícil de seguir, depurar y verificar matemáticamente.
2.  **Desarrollo del Pensamiento Algorítmico:** Evitar estos atajos obliga al estudiante a diseñar formalmente condiciones de corte coherentes y estructuradas en la cabecera de la iteración.

Para detener un lazo de forma controlada cuando se cumpla una condición anticipada, debés recurrir a la estructuración de lazos con **banderas de control** (`bool`).

### Ejercicio 7 (Refactorización de `break`)

:::{exercise}
:label: lazo_break
:enumerator: break
Modificá el siguiente programa para eliminar la instrucción `break` prohibida, estructurando correctamente el lazo:

```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("valor actual: %d\n", i);
        if (i == 4) {
            break;
        }
    }
    return 0;
}
```
:::

:::{solution} lazo_break
:label: solucion-lazo_break
:class: dropdown
Se reestructura el lazo reemplazando el `for` e implementando un lazo `while` controlado por una bandera lógica booleana (`bool`) del encabezado `<stdbool.h>` que se establece en `false` al alcanzar la condición de parada:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>

int main() {
    int i = 0;
    bool continuar = true;
    while (i < 10 && continuar) {
        printf("valor actual: %d\n", i);
        if (i == 4) {
            continuar = false;
        }
        i++;
    }
    return 0;
}
```
:::

### Ejercicio 8 (Refactorización de `continue`)

:::{exercise}
:label: lazo_continue
:enumerator: continue
Modificá el siguiente código para eliminar la instrucción `continue` prohibida:

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("i = %d\n", i);
    }
    return 0;
}
```

:::

:::{solution} lazo_continue
:label: solucion-lazo_continue
:class: dropdown
Se reestructura el lazo eliminando la instrucción `continue` y encerrando el cuerpo restante del lazo dentro de una condición positiva que filtra los elementos que se desean procesar (en este caso, los impares):

```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    for (int i = 0; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("i = %d\n", i);
        }
    }
    return 0;
}
```
:::

### Lazos con bandera (`flag`)

Para finalizar un lazo `while` o `do...while` por un evento lógico intermedio, se debe utilizar una variable lógica bandera (definida mediante `<stdbool.h>`). La bandera se inicializa en `true` y se establece en `false` cuando ocurre el evento de parada, controlando el lazo desde su condición formal.

```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool continuar = true;
    int numero = 0;

    while (continuar == true)
    {
        printf("Ingresá un número (0 para salir): ");
        scanf("%d", &numero);

        if (numero == 0)
        {
            continuar = false; // Se apaga la bandera para salir en la próxima condición
        }
        else
        {
            printf("Ingresaste: %d\n", numero);
        }
    }
    return 0;
}
```

### Ejercicio 9 (Lazo de Clave con Bandera)

:::{exercise}
:label: lazo_flag_break
:enumerator: continue

Reescribí el ingreso de clave de acceso del Ejercicio 6 utilizando un lazo controlado por una bandera booleana (`bool`) en lugar de `do...while`.
:::

:::{solution} lazo_flag_break
:label: solucion-lazo_flag_break
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int clave = 0;
    int clave_correcta = 1234;
    bool clave_correcta_ingresada = false;

    while (clave_correcta_ingresada == false) {
        printf("Ingrese la clave de acceso: ");
        scanf("%d", &clave);

        if (clave == clave_correcta) {
            printf("Acceso concedido.\n");
            clave_correcta_ingresada = true; // Se modifica el estado de la bandera
        } else {
            printf("Clave incorrecta. Intente nuevamente.\n");
        }
    }
    return 0;
}
```
:::


## Problemas del Buffer de Entrada (stdin) y su Purgado

Cuando utilizás `scanf` para leer datos numéricos o caracteres, el flujo de entrada `stdin` puede almacenar residuos no deseados que alteran las lecturas posteriores.

### El origen del problema
Al ingresar datos desde la consola (por ejemplo, al escribir un número y presionar Enter), `scanf` lee únicamente el valor numérico correspondiente al formato especificado (como `%d`), dejando el carácter de salto de línea (`\n`) residual dentro de `stdin`.

Si a continuación intentás leer un carácter utilizando `%c` o `getchar()`, esa lectura consumirá inmediatamente el `\n` residual en lugar de esperar la nueva entrada del usuario. Esto da la sensación de que el programa "saltea" la instrucción de lectura.

### Purgado de stdin con un lazo
Para solucionar este comportamiento, debés limpiar o "purgar" el buffer de entrada, consumiendo todos los caracteres residuales hasta llegar al salto de línea inclusive. La manera estándar para lograr esto consiste en implementar un lazo simple de lectura de caracteres.

El siguiente ejemplo demuestra el problema y su solución utilizando `getchar()` dentro de un lazo `while`:

```c
#include <stdio.h>

int main() {
    int edad = 0;
    char inicial = ' ';

    printf("Ingresá tu edad: ");
    scanf("%d", &edad);

    // Purgado del buffer: lee y descarta caracteres hasta el salto de línea.
    // Usamos 'int' y no 'char' porque getchar() retorna un entero para representar EOF (-1).
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lazo vacío: solo consume el buffer residual
    }

    printf("Ingresá tu inicial: ");
    scanf("%c", &inicial); // Ahora lee correctamente sin saltarse

    printf("Edad: %d, Inicial: %c\n", edad, inicial);
    return 0;
}
```

La condición `(c = getchar()) != '\n' && c != EOF` realiza tres acciones: lee un carácter de `stdin`, lo asigna a `c`, y continúa la iteración del lazo mientras no sea un salto de línea ni el fin del archivo (`EOF`). Se declara `c` como `int` porque la macro `EOF` representa habitualmente el valor entero `-1`. En plataformas donde el tipo `char` es `unsigned` (sin signo) por defecto, una variable `char` no podría almacenar un valor negativo, provocando un lazo infinito al comparar contra `EOF`.


## Ejercicios de Práctica

1. Escribí un programa que solicite dos números reales al usuario y muestre cuál es el mayor.
2. Diseñá un programa que imprima en pantalla los números enteros del 1 al 100 utilizando un lazo `for`.
3. Desarrollá un algoritmo que sume los números pares comprendidos en el rango del 1 al 100 inclusive.
4. Escribí un programa que solicite un número entero positivo e indique si es un número primo (divisible únicamente por 1 y por sí mismo).
5. Escribí un programa que pida una calificación (0 a 10) e indique si el estudiante aprobó (calificación mayor o igual a 4).
6. Escribí un programa que solicite repetidamente una contraseña de caracteres al usuario hasta que coincida con un valor establecido de acceso seguro.

---

## Recomendaciones didácticas

Cuando encuentres dificultades al depurar o diseñar un programa:
- Redactá el algoritmo en lenguaje natural de forma secuencial paso a paso.
- Graficá el algoritmo mediante un diagrama de flujo simple para validar bifurcaciones e iteraciones.
- Ejecutá una prueba de escritorio (seguimiento de variables en papel) para validar la lógica del programa.
- Utilizá llamadas a funciones de impresión (`printf`) en puntos estratégicos para examinar el estado de las variables en memoria física.

---

## Próximos Pasos

En los siguientes capítulos avanzaremos en la construcción de software modular en C:
- [](3_funciones) — Modularización y diseño de subprogramas mediante funciones con contratos y parámetros.
- [Secuencias y arreglos](7_secuencias) — Arreglos de memoria estáticos y cadenas de caracteres.
- [Compilación separada](9_compilacion) — Proceso de compilación multi-etapa y Makefile.
- [Punteros](5_punteros) — Punteros y manipulación de memoria.
- [Archivos de texto](10_archivos_texto) — Entrada y salida persistente con archivos.

---

## Bibliografía y Recursos Adicionales

- Kernighan, B. W., & Ritchie, D. M. (1988). _The C Programming Language (2nd ed.)_. Prentice Hall. (El libro de referencia de C, "K&R").
- King, K. N. (2008). _C Programming: A Modern Approach (2nd ed.)_. W. W. Norton & Company. (Libro detallado con abundantes ejercicios).

---

## Glosario

:::{glossary}
Lenguaje Ensamblador
: Lenguaje de bajo nivel que utiliza mnemónicos para representar instrucciones nativas de código máquina de un procesador específico.

Lenguaje de Máquina
: El conjunto de instrucciones binarias directas ejecutable por el circuito físico de la CPU.
:::
