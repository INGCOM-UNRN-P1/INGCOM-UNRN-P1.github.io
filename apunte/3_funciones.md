---
title: Funciones y descomposición funcional
short_title: 3 - Funciones
subtitle: Dividiendo problemas en partes más chicas.
---

## Funciones

Ya vimos cómo darle instrucciones en C a la computadora, pero ahora, vamos a
crear nuestras propias para hacer de nuestros programas, no solo más útiles sino
también, con menos código duplicado.

### Definición intuitiva

Pensá en las funciones como una oficina: recibe información (documentos o
tareas), las procesa con sus empleados y recursos, y luego te devuelve un
resultado o un informe (un valor nuevo). En la programación, y particularmente
en C, estas «oficinas» son bloques de código reutilizables diseñados para
realizar una tarea específica. Son como pequeños departamentos dentro de una
empresa que nos permiten organizar y simplificar la creación de software.

#### ¿Por qué son tan útiles estas «oficinas» en C?

Las funciones son un pilar fundamental de la programación estructurada en C.
Permiten dividir un programa grande y complejo en partes más pequeñas y
manejables, lo que trae varios beneficios:

- **Modularidad**: Cada función se encarga de una tarea concreta, haciendo que
  el diseño, desarrollo y corrección de errores del programa sea mucho más
  sencillo. Si algo no funciona, es más fácil saber en qué «departamento» de la
  oficina buscar el problema.

- **Reusabilidad de código**: Una vez que creas una función para una tarea,
  podés «encargarle» esa tarea cuantas veces necesites, en distintas partes de
  tu programa o incluso en otros proyectos, sin tener que escribir el mismo
  código una y otra vez. Esto te ahorra tiempo y reduce la posibilidad de
  errores.

- **Abstracción**: Podés usar una función sin necesidad de saber exactamente
  cómo opera por dentro. Solo necesitás entender qué hace, qué tipo de
  información espera como entrada y qué tipo de información te devolverá como
  salida. Esto simplifica el código principal de tu programa, que solo
  interactúa con la «oficina» sin preocuparse por sus procesos internos.

- **Mantenibilidad**: Si necesitás cambiar o mejorar cómo se realiza una tarea,
  solo tenés que modificar el interior de la función correspondiente. Sin
  afectar el resto de tu programa.

### Una definición más formal

En C, una **función** es un bloque de código reutilizable diseñado para realizar
una tarea específica. Recibe uno o más valores de entrada, llamados
_parámetros_, ejecuta un conjunto de instrucciones y produce un único valor de
salida. Su propósito principal es actuar como un procesador de datos: recibe el
contexto necesario, lo transforma mediante operaciones definidas y devuelve un
resultado.

De forma análoga a las funciones matemáticas, podemos pensar en ella como una
relación $ f(x) = y $, donde cada conjunto de valores de entrada genera
exactamente un resultado. En C, una función solo puede devolver un valor
directamente. (existen técnicas para sortear esta limitación, que se estudiarán
más adelante)

Otra observación importante es que en esta definición asumimos la presencia de
al menos un argumento, ya que, sin parámetros, la función no cuenta con
información externa para variar su comportamiento, salvo que utilice valores
internos predefinidos ingresos directos del usuario o variables globales.

Esta observación nos lleva a la definición de **función pura**. Estas son
aquellas que, dados los mismos parámetros de entrada, siempre devuelven el mismo
resultado y no producen un {term}`efecto secundario`, es decir, no modifica
variables externas ni interactúa con elementos fuera de su propio ámbito (como
archivos o la pantalla). Esto, en términos matemáticos, es hacer que se comporte
exactamente como lo haría una función $ f(x) $ tradicional.

Aunque su uso no aplica a todos los casos, este concepto, simplifica el
comportamiento de un programa, al delimitar la interacción de nuestro código con
el estado del programa. Y de regalo, es mucho más fácil asegurarnos de que el
programa hace lo que debe, esto es algo que veremos más adelante.

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

Asimismo, una función en C, puede no retornar valores y esto se hace con la
palabra reservada `void` (vacío en inglés).

### Ejemplos

En este ejemplo comentado, podemos ver un ejemplo de función que recibe un par de números y devuelve uno.

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

```{figure} ./3/function_call_flow.svg
:name: fig-function-call-flow
:width: 100%

Flujo de llamada y retorno de una función: (1) main() llama a sumar() pasando argumentos, (2) sumar() recibe copias de los valores y ejecuta, (3) sumar() retorna el resultado y main() continúa con ese valor. Los parámetros son copias, por lo que cambios internos no afectan las variables originales.
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
Esta función, que no tuvo un retorno al programa, dio lugar a un
{term}`efecto secundario`; el enviar caracteres por la consola.

Cuando una función no tiene retorno, se dice que es un «Procedimiento», esta
distinción es para separar conceptualmente del código que da resultados
explícitos al programa.
:::

### Prototipos de función

Son una declaración anticipada que informa al compilador sobre el nombre, tipo de retorno y lista de parámetros de una función **antes** de que sea utilizada en el código. Su propósito es permitir que el compilador verifique la coherencia de las llamadas a la función, garantizando que el número y el tipo de argumentos coincidan con su definición. Un prototipo no contiene el cuerpo de la función, sino únicamente su firma, y suele colocarse al inicio del archivo fuente.

```{figure} ./3/function_prototype_flow.svg
:name: fig-function-prototype-flow
:width: 100%

Comparación entre código sin prototipo (que genera error de compilación) y código con prototipo (que compila exitosamente). El compilador lee el código de arriba hacia abajo en una sola pasada, por lo que los prototipos son esenciales para informarle sobre funciones que se definirán más adelante.
```

El funcionamiento del compilador es limitado a pasar una sola vez por el archivo
del programa lo que hace que si se llega a una llamada a función que no fue
declarada, no se podrá continuar con la compilación porque este no tiene la
información necesaria para garantizar que los argumentos y retornos sean los
indicados.

Pueden ver esto, si cambian la definición de las funciones debajo del `main`.
Como el compilador ve una llamada a función, antes de su declaración, la
compilación fallará.

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

Para que este código funcione, se necesita saber cuál es la forma que tiene la
función, si el código no está en ese lugar, no importa (en ese momento)

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

Los prototipos de función se utilizan cuando una función usa a otra, y no
podemos arreglarnos reordenando funciones.

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

No importa en qué orden dejemos las funciones de este ejemplo, el código no
compilará.

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

## Alcances (Scopes)

En C, el alcance (o scope en inglés) de una variable determina en qué partes de tu programa puedes acceder y modificar esa variable. Es como definir el "territorio" donde una variable existe y es reconocida. Entender los alcances es fundamental para escribir código organizado, legible y libre de errores.

```{figure} ./3/scopes_hierarchy.svg
:name: fig-scopes-hierarchy
:width: 100%

Jerarquía de alcances en C mostrando el scope global (nivel 0), scopes de función (nivel 1) y scopes de bloque (nivel 2). Las variables pueden acceder a scopes superiores, pero no a scopes paralelos o inferiores.
```

En particular, porque las funciones deben recibir y devolver valores de forma explícita.

### Variables Globales

Las variables globales se declaran fuera de cualquier función. Su principal
característica es que son accesibles desde cualquier función en todo el
programa. Una vez declarada, cualquier parte de tu código puede leerla y
modificarla.

```c
#include <stdio.h>

int variableGlobal = 10; // Declarada fuera de todas las funciones

void miFuncion()
{
    printf("Desde miFuncion: %d\n", variableGlobal); // Acceso permitido
    variableGlobal = 20; // Modificación permitida
}

int main()
{
    printf("Desde main (antes): %d\n", variableGlobal);
    miFuncion();
    printf("Desde main (después): %d\n", variableGlobal);
    return 0;
}
```

Salida:

```
Desde main (antes): 10
Desde miFuncion: 10
Desde main (después): 20
```

Aunque las variables globales pueden parecer una forma fácil de compartir datos
entre funciones, su uso rompe con la expectativa de que una función recibe su
contexto de los argumentos y devuelve valor en el retorno.

Cualquier función puede modificar una variable global. Esto crea dependencias
ocultas entre partes del código que no deberían estar relacionadas. Si cambias
el valor de una variable global en una función, podrías romper inesperadamente
otra función que también la usa. Es difícil rastrear quién y cuándo la modificó.

También, cuando una variable global tiene un valor incorrecto, tienes que buscar
en todo el código para encontrar la causa del problema. En un programa grande,
esto es una pesadilla. Con variables locales, el error está contenido dentro de
una única función.

Las funciones que dependen de variables globales no son autónomas. No puedes
simplemente copiar y pegar una función en otro proyecto, porque necesitarías
llevarte también todas las variables globales de las que depende. El código
modular y reutilizable se basa en funciones que reciben entradas (argumentos) y
producen salidas (valor de retorno), sin depender del estado externo.

Por estas razones, existe la regla
[`0x000Bh`](./estilo.md#0x000Bh)

### Argumentos de Función (Parámetros)

Estas son las variables que se declaran en la definición de una función. Su
alcance está limitado exclusivamente a esa función. Actúan como variables
locales que se inicializan con los valores que se les pasan cuando se llama a la
función.

Aunque su comportamiento es idéntico a una variable declarada dentro de la
función, la inicialización se hace con los valores con la que la función es
llamada.

```c
#include <stdio.h>

void suma(int a, int b)  // 'a' y 'b' son argumentos
{
    int suma = a + b; // 'a' y 'b' solo existen dentro de calcularSuma
    printf("La suma es: %d\n", suma);
}

int main() {
    suma(5, 3);
    // printf("%d", a); // ERROR: 'a' no está declarada en este alcance
    return 0;
}
```

En este caso, `a` y `b` solo son visibles y utilizables dentro de la función
`suma`.

### Variables locales

Las variables locales se declaran dentro de una función, pero fuera de cualquier bloque de código (como un `if` o un `for`). Su alcance se limita a la función en la que fueron declaradas. Se "destruyen" de la memoria cuando la función termina su ejecución.

:::{tip} Gestión Automática de Memoria
Las variables locales se almacenan en el **stack** (pila), una región de memoria gestionada automáticamente por el sistema. Cuando una función se llama, se crea un marco de pila (stack frame) con todas sus variables locales; cuando termina, ese marco se libera automáticamente. Para entender en profundidad cómo funciona este mecanismo y cómo se organiza la memoria de un programa, consultá el [](11_memoria), donde se explica detalladamente el stack, heap y la gestión de memoria dinámica.
:::

```c
#include <stdio.h>

void miFuncion() {
    int variableLocal = 5; // 'variableLocal' solo existe aquí
    printf("Variable local: %d\n", variableLocal);
}

int main() {
    miFuncion();
    // printf("%d", variableLocal); // ERROR: 'variableLocal' no existe en main
    return 0;
}
```

La `variableLocal` solo es accesible desde `miFuncion`.

### Variable de bloque

Son variables declaradas dentro de un bloque de código específico, que se
delimita por llaves `{}`. Su alcance es aún más restringido: solo existen desde
el punto de su declaración hasta el final de ese bloque. Son comunes en bucles
`for`, sentencias `if`, `while`, etc.

```c
#include <stdio.h>

int main() {
    int x = 10;

    if (x == 10)
    {
        int variableBloque = 25; // Solo existe dentro de este if
        printf("Dentro del bloque if: %d\n", variableBloque);
    }

    // printf("%d", variableBloque); // ERROR: La variable no existe aquí

    for (int i = 0; i < 3; i++) // 'i' es una variable de bloque
    {
        printf("Iteración: %d\n", i);
    }
    // printf("%d", i); // ERROR: 'i' ya no existe

    return 0;
}
```

La `variableBloque` solo es accesible dentro de las llaves del `if`, y la
variable `i` solo existe dentro del bucle `for`.

Tengan en cuenta que pueden crear bloques sueltos, sin que estén asociados a una
estructura de control.

### Delimitación de variables

Los alcances nos llevan a que la información no viaja 'mágicamente' entre
funciones, es necesario pasar y recibir los valores explícitamente. (ya vimos
porque es una mala idea usar variables globales)

El principal efecto de los alcances, tiene que ver con que un mismo nombre en
dos alcances del mismo nivel, que serían paralelos, pueden tener los mismos
identificadores y tener (tipos y) valores completamente diferentes.

```c
// Global, scope de nivel cero.
int main()
{
    // La función, establecen un scope local de nivel 1
    int variable_local = 20;
    printf("La variable local vale %d\n", variable_local);
    return 0;
}

void procedimiento()
{
    // Este es otro scope local de nivel 1.
    printf("La variable_local no existe acá %d\n", variable_local);
    //ERROR, no esta definida la 'variable_local'
}
```

Es otra cosa cuando el mismo identificador se usa en alcances anidados, como
veremos a continuación.

### Ocultamiento de variables (Shadowing)

El _shadowing_ ocurre cuando declaras una variable en un alcance interno (por ejemplo, local a una función o en un bloque) con el mismo nombre que una variable en un alcance externo (por ejemplo, una variable global).

Cuando esto sucede, la variable del alcance más interno "oculta" o le hace "sombra" (shadow) a la del alcance más externo. Dentro de ese bloque interno, cualquier referencia a ese nombre de variable se resolverá a la variable más cercana (la interna), haciendo que la externa sea _temporalmente_ inaccesible por su nombre.

```{figure} ./3/shadowing.svg
:name: fig-shadowing
:width: 100%

Visualización del ocultamiento de variables (shadowing): la variable 'i' del scope externo (valor 10) es temporalmente ocultada por la 'i' del for loop (valores 5,4,3,2,1). Al salir del for, la 'i' externa vuelve a ser visible con su valor original.
```

Existen ejemplos más elaborados, utilizando una combinación de variables globales, locales y de bloque, pero este es uno que puede darse con gran facilidad porque en definitiva, es por redefinir `i` dentro del lazo.

```c
#include <stdio.h>

int main()
{
    int i = 10; // Variable local en main.

    printf("En main, 'valor' es: %d\n", i); // Imprime 50

    for (int i = 5; i > 0; i--) // i del bloque, 'tapa' la local
    {
        printf("Dentro del for, 'i' es: %d\n", i); // Imprime la cuenta desde 15
    }

    printf("Fuera del for, 'i' es de nuevo: %d\n", i); // Imprime 10

    return 0;
}
```

Y la salida, queda como:

```
En main, 'valor' es: 10
Dentro del for, 'i' es: 5
Dentro del for, 'i' es: 4
Dentro del for, 'i' es: 3
Dentro del for, 'i' es: 2
Dentro del for, 'i' es: 1
Fuera del for, 'i' es de nuevo: 10
```

## Valores `static` en funciones

Cuando se declara una variable local dentro de una función, esta se destruye
cuando la función termina por lo que su valor no se conserva entre llamadas.

C con el calificador `static` en la declaración de una variable local a función,
nos permite evitar que esta no se destruya y conserve su valor entre las
distintas llamadas, el comportamiento es similar a una variable global, pero
delimitada a la función.

Una variable con este calificador, se inicializa una única vez en la primera
llamada a la función, para evitar destruir el valor entre llamadas a la función.

Pero lo más importante, conserva su valor entre sucesivas llamadas a la función
y preserva su alcance.

```c
#include <stdio.h>

void contadorNormal()
{
    int contador = 0;
    contador++;
    printf("Contador Normal: %d\n", contador);
}

void contadorStatic()
{
    static int contador = 0; // 'static' hace la diferencia
    contador++;
    printf("Contador Static: %d\n", contador);
}

int main()
{
    printf("Llamando a las funciones 3 veces:\n");

    contadorNormal();
    contadorStatic();
    printf("---\n");

    contadorNormal();
    contadorStatic();
    printf("---\n");

    contadorNormal();
    contadorStatic();

    return 0;
}
```

De este ejemplo, contador normal, es un procedimiento simple que declara e
inicializa una variable en `0`, este es el comportamiento tradicional de una
función en C. Mientras que la segunda, hace uso del calificador `static`.

```
Llamando a las funciones 3 veces:
Contador Normal: 1
Contador Static: 1
---
Contador Normal: 1
Contador Static: 2
---
Contador Normal: 1
Contador Static: 3
```

Aquí, el `contadorNormal` se reinicia a `0` en cada llamada, por lo que su
salida es siempre `1`. Pero el `contadorStatic` se inicializa a `0` solo la
primera vez. En las llamadas siguientes, retiene su valor anterior (`1`, luego
`2`), por lo que sigue incrementándose.

:::{warning} Limiten su uso
El gran problema de este calificador, es que oculta el estado de la función que
de otra forma debiera de ser un argumento explícito, lo que en definitiva, hace
que la función no sea predecible, y dependerá de algo interno que solo es
accesible por la función misma.
:::

## Divide y vencerás

Los grandes programadores no resuelven problemas gigantescos de un solo golpe.
En lugar de eso, **dividen el problema en piezas pequeñas**, comprensibles y más
fáciles de encarar.

Este proceso se llama **descomposición funcional**. Cada parte se convierte en
una función.

Una función es un pequeño módulo con una misión específica. Cuando todas las
piezas están listas, se ensamblan en el `main()` para contar la historia
completa del programa.

> Pensá en tu programa como una obra de teatro. `main()` es el director que da
> las órdenes, y cada función es un actor especializado.

## Pensar como un programador: el método top-down

El método top-down (de arriba hacia abajo) es una forma de resolver problemas
desde lo general hacia lo específico. Así se programa con claridad y orden.

### Etapas del método:

1. **Analizá el problema global.** ¿Qué debe hacer el programa, en líneas
   generales?
2. **Dividilo en subtareas lógicas.** Por ejemplo: leer datos, procesar
   información, mostrar resultados.
3. **Asigná una función a cada subtarea.** Cada una debería tener nombre,
   parámetros y un valor de retorno claro.
4. **Codificá las funciones de abajo hacia arriba.** Primero las funciones más
   simples (leer, calcular, etc.).
5. **Integrá todo en el `main()` de forma que quede como una receta paso a
   paso.**

Este enfoque permite **testear partes** antes de armar el todo, y hace que tu
programa sea mucho más fácil de entender.

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
3. Programa una conversión de Celsius a Fahrenheit. Separá en: leer, convertir,
   mostrar.
4. Escribí un programa que determine si un número es par o impar.
5. Escribí un programa que lea tres notas, calcule el promedio y lo muestre.
6. Hacé una función que devuelva el cuadrado de un número.
7. Componé funciones que, encadenadas, lean dos valores, sumen, resten y
   muestren resultados.

## Mantras de la descomposición funcional

- “Si algo se repite → función.”
- “Si algo es confuso → dividilo.”
- “`main()` es el guion, no el drama.”
- “Una función, una responsabilidad.”
- “Código limpio, mente limpia.”

Como para dejar impreso por ahí.

## Factorización y simplificación de funciones _casi_ duplicadas

Una de las habilidades clave en la programación es **reconocer patrones
repetidos** y simplificarlos. Así como en álgebra factorizamos términos comunes
para escribir expresiones más simples y elegantes, en programación podemos
**factorizar comportamiento común en una única función**.

### El paralelismo con la matemática

En matemática:

```{math}
:label: Factorización de terminos
ab + ac = a(b + c)
```

En la factorización de términos, extraemos el término común `a` para simplificar
la expresión.

¿Y esto, cómo se aplica a la programación?

Si tenemos dos funciones que repiten el mismo bloque de código, ese bloque puede
**extraerse a una función aparte**. Esa función luego puede ser llamada desde
ambas funciones originales o incluso reemplazarlas completamente.

:::{note} ¿Solo para código idéntico?
Si podemos identificar qué es lo que cambia, y reemplazarlo por un argumento,
estamos factorizando de una forma aún mejor.
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

void mostrar_saludo(char mensaje[])
{
    printf("%s\n", mensaje);
    solicitar_datos();
}

int main()
{
    mostrar_saludo("Bienvenido al sistema.");
    mostrar_saludo("Gracias por usar el sistema.");
    return 0;
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

En la sección anterior, se menciona algo sobre 'responsabilidades', este es uno
de los principios más importantes al escribir funciones y aplicar la
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

La función tiene una **tarea clara, definida y limitada**. Y aunque podemos
extender el concepto a la ‘toma de datos’ y a ‘mostrar el resultado’, con
quedarnos en lo que hace el trabajo estamos más que bien.

::::{tip}
Una buena función se puede describir en una frase corta. Si necesitás una
oración compuesta, probablemente estás metiendo dos responsabilidades en una.

::::
## Documentación de funciones

La documentación es una herramienta clave en la programación. Ayuda a que otras
personas (y vos mismo, en el futuro) puedan entender rápidamente qué hace cada
parte del programa sin tener que leer todo el código.

### Comentarios

Los comentarios son texto libre que podemos agregar a nuestros programas sin que
este sea procesado por el compilador. Lo podemos pensar como anotaciones y
observaciones del código que escribamos.

Durante la cursada, les vamos a exigir que completen comentarios específicos
llamados documentación, los cuales deben tener una forma específica. Y aunque
esto no es estrictamente necesario para el funcionamiento del programa, los
ayudará a entender mejor el problema que están resolviendo al ponerlo en sus
propias palabras.

Este es un comentario de una sola línea, que pueden usar para reforzar alguna
explicación de algo que vean flojo (pero puntual)

```c
// este es un comentario de una única linea, todo lo que esta a la derecha es ignorado
```

Y este es un comentario de bloque, que se usa para documentar funciones, pero
también lo pueden usar para desactivar una parte del programa:

```c
/*
Este es un comentario de bloque, todo lo que esta dentro del bloque es
ignorado, y este, a diferencia del otro, puede abarcar múltiples lineas.
*/
```

### ¿Por qué documentar funciones?

Una buena razón para documentar, y hacerlo antes de empezar a programar, es para
poner en nuestras propias palabras que es lo que el código que estamos
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

Los comentarios de documentación que les pediremos que completen, tienen esta
forma, la misma no es casual. Está pensada para una herramienta que toma estos
comentarios y construye un manual del código que, si nos da el tiempo, la
veremos, [Doxygen](https://doxygen.nl/).

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

- Te obligan a **pensar antes de programar**.
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
## Glosario

:::{glossary}
efecto secundario
: En la programación, un efecto secundario es cualquier cambio
de estado que ocurre fuera del ámbito de una función. En otras palabras, una
función tiene efectos secundarios cuando modifica algo más allá de simplemente
devolver un valor. En C, esto a menudo se refiere a la modificación de variables
globales o datos a los que se accede a través de punteros.
:::

## Ejercicios sobre funciones

```{exercise}
:label: funcion_doble
:enumerator: funciones-1

Escribí una función que reciba un número entero y devuelva su doble. Probala desde `main()` con distintos valores.
```

````{solution} funcion_doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int doble(int n)
{
    return 2 * n;
}

int main()
{
    printf("Doble de 5: %d\n", doble(5));
    printf("Doble de 12: %d\n", doble(12));
    return 0;
}
```
````

```{exercise}
:label: funcion_mayor
:enumerator: funciones-2

Programá una función que reciba dos números enteros y retorne el mayor de ellos.
```

````{solution} funcion_mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int mayor(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int x = 10, y = 7;
    printf("El mayor es: %d\n", mayor(x, y));
    return 0;
}
```
````

```{exercise}
:label: funcion_par_impar
:enumerator: funciones-3

Definí una función que indique si un número es par o impar. Mostrá el resultado llamando a la función desde `main()`.
```

````{solution} funcion_par_impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

void par_impar(int n)
{
    if (n % 2 == 0)
        printf("%d es par\n", n);
    else
        printf("%d es impar\n", n);
}

int main()
{
    par_impar(7);
    par_impar(12);
    return 0;
}
```
````

```{exercise}
:label: funcion_promedio
:enumerator: funciones-4

Escribí una función que reciba tres notas enteras y devuelva el promedio. Mostrá el resultado en `main()`.
```

````{solution} funcion_promedio
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

float promedio(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

int main()
{
    printf("Promedio: %.2f\n", promedio(7, 8, 10));
    return 0;
}
```
````

```{exercise}
:label: funcion_area
:enumerator: funciones-5

Implementá una función `area_rectangulo` que reciba base y altura, y devuelva el área.
```

````{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int area_rectangulo(int base, int altura)
{
    return base * altura;
}

int main()
{
    printf("Área: %d\n", area_rectangulo(5, 4));
    return 0;
}
```
````

## Conceptos Clave

Este apunte introduce la **descomposición funcional** como metodología fundamental para estructurar programas complejos. Los conceptos esenciales que deben quedar claros son:

:::{important} Ideas Centrales

**Funciones como Unidades de Abstracción**
- Una función encapsula una tarea específica con entradas y salidas bien definidas
- Permiten reutilización, modularidad y mantenibilidad del código
- Representan el primer nivel de abstracción para gestionar complejidad

**Alcances (Scopes)**
- Determinan dónde existe y es accesible una variable
- Jerarquía: global → función → bloque
- El shadowing ocurre cuando se redefine un identificador en un scope anidado
- Las variables locales se gestionan automáticamente en el stack

**Diseño Top-Down**
- Dividir problemas complejos en subtareas más simples
- Cada función debe tener una única responsabilidad
- `main()` actúa como el director que coordina las funciones especializadas

**Contratos de Funciones**
- **Precondiciones**: qué debe ser cierto antes de ejecutar
- **Postcondiciones**: qué garantiza la función al terminar
- **Invariantes**: propiedades que se mantienen constantes
- Estos conceptos fundamentan el razonamiento sobre corrección de código

**Buenas Prácticas**
- Evitar variables globales (ruptura de encapsulación)
- Nombres descriptivos que comunican propósito
- Separar cálculo de entrada/salida
- Documentar expectativas y comportamiento
- Factorizar código repetido
:::

## Conexión con el Siguiente Tema

Las funciones que construimos hasta ahora operan sobre datos individuales (enteros, flotantes, caracteres). Pero la realidad es que los programas útiles necesitan procesar **colecciones de datos**: listas de estudiantes, tablas de productos, series temporales, imágenes, etc.

El próximo apunte, **[](4_secuencias)**, introduce las **secuencias** (arreglos en C) como la primera estructura de datos que permite agrupar múltiples valores relacionados bajo un solo identificador. Allí veremos:

- Cómo declarar y usar arreglos para almacenar colecciones homogéneas
- Paso de arreglos a funciones (¡diferente del paso por valor!)
- Algoritmos fundamentales: búsqueda, ordenamiento, transformaciones
- La relación profunda entre arreglos y punteros que es única de C

Las funciones que dominamos aquí serán las herramientas para **operar sobre secuencias**: una función que suma elementos, otra que busca el máximo, otra que ordena. La descomposición funcional se vuelve aún más poderosa cuando las funciones procesan colecciones completas de datos de forma eficiente y expresiva.

**Pregunta puente**: ¿Cómo escribiríamos una función `calcular_promedio()` para 100 estudiantes sin usar arreglos? ¿Y para 1000? La respuesta natural nos lleva directamente al concepto de secuencia.

