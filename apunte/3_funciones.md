---
title: Funciones y descomposición funcional
short_title: 3 - Funciones
subtitle: Dividiendo problemas en partes más chicas.
---

## Funciones

Ya vimos cómo darle instrucciones en C a la computadora, pero ahora vamos a crear nuestras propias funciones para hacer de nuestros programas no solo más útiles, sino también con menos código duplicado.

### Definición intuitiva

En la programación estructurada en C, las **funciones** constituyen los bloques modulares fundamentales de construcción de software. Un programa se descompone jerárquicamente en módulos independientes que cooperan para resolver un problema complejo. Cada función representa un flujo de control aislado que recibe parámetros de entrada, ejecuta una secuencia de instrucciones en su propio ámbito y opcionalmente retorna un resultado al flujo invocador.

#### Beneficios Didácticos y Técnicos de la Descomposición Funcional

- **Modularidad y Control de Flujo**: Dividir un programa grande en partes pequeñas y autónomas facilita el razonamiento lógico, el testeo y la depuración del código.
- **Reusabilidad**: Permite invocar la misma lógica repetidas veces desde distintos puntos del programa sin duplicar código en memoria.
- **Abstracción**: Permite al programador concentrarse en la interfaz de la función (qué datos requiere y qué retorna) sin necesidad de mantener en la memoria de trabajo los detalles de su implementación interna.
- **Registros de Activación (Stack Frames)**: Al invocar una función, el procesador suspende temporalmente el flujo actual y reserva dinámicamente una porción de memoria en la pila de ejecución física del programa (denominada *registro de activación* o *stack frame*). Este espacio aloja los parámetros, las variables locales y la dirección de retorno de la instrucción del invocador. Al finalizar la ejecución de la función y ejecutarse la sentencia `return`, su registro de activación se libera (destruyendo todas sus variables locales) y el flujo de control se reanuda inmediatamente en la instrucción posterior a la llamada.

### Una definición más formal

En C, una **función** es un bloque de código reutilizable diseñado para realizar una tarea específica. Recibe uno o más valores de entrada, llamados *parámetros*, ejecuta un conjunto de instrucciones y produce un único valor de salida. Su propósito principal es actuar como un procesador de datos: recibe el contexto necesario, lo transforma mediante operaciones definidas y devuelve un resultado.

De forma análoga a las funciones matemáticas, podemos pensar en ella como una relación $ f(x) = y $, donde cada conjunto de valores de entrada genera exactamente un resultado. En C, una función solo puede devolver un valor directamente (existen técnicas para sortear esta limitación, que se estudiarán más adelante).

Otra observación importante es que en esta definición asumimos la presencia de al menos un parámetro, ya que, sin parámetros, la función no cuenta con información externa para variar su comportamiento, salvo que reciba ingresos directos del usuario.

Esta observación nos lleva a la definición de **función pura**. Estas son aquellas que, dados los mismos parámetros de entrada, siempre devuelven el mismo resultado y no producen un {term}`efecto secundario`, es decir, no modifican variables externas ni interactúan con elementos fuera de su propio ámbito (como archivos o la pantalla). Esto, en términos matemáticos, es hacer que se comporte exactamente como lo haría una función $ f(x) $ tradicional.

Aunque su uso no aplica a todos los casos, este concepto simplifica el comportamiento de un programa al delimitar la interacción de nuestro código con el estado del programa. Y de regalo, es mucho más fácil asegurarnos de que el programa hace lo que debe.

---

## ¿Qué es una función en C?

Una función en C es un bloque de código que:

- Tiene un **identificador**.
- Recibe cero o más **parámetros** como entrada.
- Puede devolver un **valor de salida**.
- Contiene un **conjunto de instrucciones**.

**Sintaxis básica**

```c
<tipo> <nombre>(<tipo parámetro1> <nombre parámetro1>, <tipo parámetro2> <nombre parámetro2>, ...) {
    // instrucciones
    return valor;
}
```

De esta sintaxis básica, es posible crear una función que no reciba argumentos; solo tenemos que dejar vacía la lista de parámetros.
Asimismo, una función en C puede no retornar valores y esto se hace con la palabra reservada `void` (vacío en inglés).

### Ejemplos

En este ejemplo comentado, podemos ver una función que recibe un par de números y devuelve su suma:

```c
// retorno de tipo int, identificador sumar y dos int como argumentos
int sumar(int a, int b) {
    int retorno = a + b; // instrucciones que completan el objetivo de la función
    return retorno;      // instrucción que devuelve el valor calculado
}
```

Esto se puede usar desde `main()` u otra función:

```c
int resultado = sumar(5, 3);
printf("Resultado: %d\n", resultado);
```

```{figure} 3/function_call_flow.svg
:name: fig-function-call-flow
:width: 100%

Flujo de llamada y retorno de una función. Los parámetros son copias, por lo que cambios internos no afectan las variables originales.
```

Y también un ejemplo de función que no recibe argumentos y simultáneamente no devuelve valores:

```c
// sin retorno de valor, identificador saludar y sin argumentos
void saludar() {
    printf("Hola Mundo!\n");
}
```

:::{note} Procedimiento
Esta función, que no tuvo un retorno al programa, dio lugar a un {term}`efecto secundario`: enviar caracteres por la consola.
Cuando una función no tiene retorno, se dice que es un «Procedimiento», esta distinción es para separar conceptualmente del código que da resultados explícitos al programa.
:::

### Prototipos de función

Son una declaración anticipada que informa al compilador sobre el nombre, tipo de retorno y lista de parámetros de una función **antes** de que sea utilizada en el código. Su propósito es permitir que el compilador verifique la coherencia de las llamadas a la función, garantizando que el número y el tipo de argumentos coincidan con su definición. Un prototipo no contiene el cuerpo de la función, sino únicamente su firma, y suele colocarse al inicio del archivo fuente.

```{figure} 3/function_prototype_flow.svg
:name: fig-function-prototype-flow
:width: 100%

Comparación entre código sin prototipo y código con prototipo. El compilador lee el código de arriba hacia abajo en una sola pasada.
```

El funcionamiento del compilador está limitado a pasar una sola vez por el archivo del programa, lo que hace que si se llega a una llamada a función que no fue declarada, no se podrá continuar con la compilación porque no se tiene la información necesaria para garantizar que los argumentos y retornos sean los indicados.

Podés ver esto si ubicás la definición de las funciones debajo del `main`. Como el compilador ve una llamada a la función antes de su declaración, la compilación fallará:

```c
int main() {
    printf("%f\n", areaCirculo(10.0));
    return 0;
}

double areaCirculo(double radio) {
    return 3.14159 * radio * radio;
}
```

Para que este código funcione, se necesita declarar el prototipo de la función al principio del archivo:

```c
// prototipo de la función
double areaCirculo(double radio);

int main() {
    printf("%f\n", areaCirculo(10.0));
    return 0;
}

double areaCirculo(double radio) {
    return 3.14159 * radio * radio;
}
```

Los prototipos de función se utilizan obligatoriamente cuando dos funciones se llaman mutuamente (mutua recursión), y no podemos organizarlas simplemente reordenándolas:

```c
// Declaraciones de prototipos para resolver la mutua recursión
int funcion_uno();
int funcion_dos();

int funcion_uno() {
    // Lógica que requiere llamar a funcion_dos
    funcion_dos();
    return 0;
}

int funcion_dos() {
    // Lógica que requiere llamar a funcion_uno
    funcion_uno();
    return 0;
}
```

---

## Alcance (Scope) y Tiempo de Vida (Lifetime) de Variables

Para programar de forma modular en C, tenés que dominar cómo se relacionan el **alcance (ámbito o scope)** de una variable —en qué regiones del código es visible y accesible su identificador— y su **tiempo de vida (lifetime)** —duración y ubicación física de su almacenamiento en memoria—.

La tabla {numref}`tbl-ambitos-y-tiempos` resume de forma estructurada las diferencias conceptuales entre las variables locales, globales y locales estáticas:

:::{table} Comparación de ámbitos, tiempos de vida y almacenamiento
:label: tbl-ambitos-y-tiempos

| Tipo de Variable | Ámbito (Scope) | Tiempo de Vida (Lifetime) | Región de Memoria | Directiva de la Cátedra |
| :--- | :--- | :--- | :--- | :--- |
| **Local (Automática)** | De bloque o función | Duración del bloque/función | Stack (Pila) | {ref}`0x2007h` (Reducir el alcance) |
| **Global** | Todo el archivo / programa | Toda la ejecución del programa | Segmento de datos | {ref}`0x2004h` (Prohibición absoluta) |
| **Local Estática (`static`)** | Local al bloque/función | Toda la ejecución del programa | Segmento de datos | Usar con moderación |
:::

```{figure} 3/scopes_hierarchy.svg
:label: fig-scopes-hierarchy
:width: 100%

Jerarquía de alcances en C mostrando el scope global, de función y de bloque.
```

### Variables Globales

Las variables globales se declaran fuera de cualquier función. Su principal característica es que son accesibles desde cualquier función en todo el programa. Una vez declarada, cualquier parte de tu código puede leerla y modificarla.

```c
#include <stdio.h>

int variableGlobal = 10; // Declarada fuera de todas las funciones

void miFuncion() {
    printf("Desde miFuncion: %d\n", variableGlobal); // Acceso permitido
    variableGlobal = 20; // Modificación permitida
}

int main() {
    printf("Desde main (antes): %d\n", variableGlobal);
    miFuncion();
    printf("Desde main (después): %d\n", variableGlobal);
    return 0;
}
```

Aunque las variables globales pueden parecer una forma fácil de compartir datos, su uso rompe con la expectativa de que una función recibe su contexto de los argumentos y devuelve valor en el retorno. Cualquier función puede modificar una variable global, lo que crea dependencias ocultas y hace el código muy difícil de depurar y mantener.

Por estas razones, la cátedra prohíbe el uso de variables globales (ver [Regla 0x2004h](0_estilo.md#0x2004h)).

### Argumentos de Función (Parámetros)

Estas son las variables que se declaran en la definición de una función. Su alcance está limitado exclusivamente a esa función. Actúan como variables locales que se inicializan con los valores que se les pasan cuando se llama a la función.

```c
#include <stdio.h>

void suma(int a, int b) { // 'a' y 'b' son argumentos
    int resultado = a + b; // 'a' y 'b' solo existen dentro de la función suma
    printf("La suma es: %d\n", resultado);
}

int main() {
    suma(5, 3);
    // printf("%d", a); // ERROR: 'a' no existe en este alcance
    return 0;
}
```

### Variables Locales (Automáticas)

Las variables locales se declaran dentro de una función, pero fuera de cualquier bloque de código interno (como un `if` o un `for`). Su alcance se limita a la función en la que fueron declaradas. Se liberan de la memoria automáticamente cuando la función termina su ejecución.

:::{tip} Gestión Automática de Memoria
Las variables locales se almacenan en el **stack** (pila), una región de memoria gestionada automáticamente por el sistema. Cuando una función se llama, se crea un marco de pila (stack frame) con todas sus variables locales; cuando termina, ese marco se libera automáticamente. Para entender en profundidad cómo funciona este mecanismo, consultá el [Memoria Dinámica](14_memoria_dinamica).
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

### Variables de Bloque

Son variables declaradas dentro de un bloque de código específico, que se delimita por llaves `{}`. Su alcance es aún más restringido: solo existen desde el punto de su declaración hasta el final de ese bloque. Son comunes en lazos y condicionales.

```c
#include <stdio.h>

int main() {
    int x = 10;

    if (x == 10) {
        int variableBloque = 25; // Solo existe dentro de este if
        printf("Dentro del bloque if: %d\n", variableBloque);
    }

    // printf("%d", variableBloque); // ERROR: La variable no existe aquí

    for (int i = 0; i < 3; i++) { // 'i' es una variable de bloque
        printf("Iteración: %d\n", i);
    }
    // printf("%d", i); // ERROR: 'i' ya no existe en este alcance

    return 0;
}
```

La `variableBloque` solo es accesible dentro de las llaves del `if`, y la variable `i` solo existe dentro del lazo `for`.

### El Modificador de Almacenamiento `static`

Cuando aplicás el modificador `static` a una variable local, alterás su tiempo de vida sin modificar su ámbito de visibilidad. La variable persistirá en el segmento de datos durante toda la ejecución del programa, inicializándose una única vez al comenzar. Sin embargo, su visibilidad permanece restringida únicamente al bloque de la función donde fue declarada.

Analizá el comportamiento con este ejemplo comparativo:

```c
#include <stdio.h>

void contador_normal() {
    int contador = 0; // Local automática: se inicializa y destruye en cada llamada
    contador++;
    printf("Contador Normal: %d\n", contador);
}

void contador_static() {
    static int contador = 0; // Local estática: se inicializa una sola vez y persiste
    contador++;
    printf("Contador Static: %d\n", contador);
}

int main(void) {
    contador_normal();
    contador_static();
    printf("---\n");
    contador_normal();
    contador_static();
    return 0;
}
```

Salida del programa:
```
Contador Normal: 1
Contador Static: 1
---
Contador Normal: 1
Contador Static: 2
```

En este fragmento, `contador_normal` se reinicia a `0` en cada invocación porque su espacio en el stack se libera al retornar. En contraste, `contador_static` retiene su valor anterior entre ejecuciones porque reside de forma permanente en el segmento de datos.

:::{warning} Efecto Secundario y Pureza
El uso de `static` conserva el estado de la variable local entre ejecuciones de la función. Esto rompe la noción de función pura y puede dificultar las pruebas unitarias al hacer que el resultado de una llamada dependa de las ejecuciones anteriores. Utilizalo solo cuando el diseño técnico lo requiera expresamente.
:::

### Ocultamiento de variables (Shadowing)

El *shadowing* ocurre cuando declarás una variable en un alcance interno (por ejemplo, en un lazo o un bloque) con el mismo nombre que una variable en un alcance externo. La variable del alcance más interno "oculta" a la del alcance más externo dentro de su bloque.

Cuando esto sucede, la variable del alcance más interno "oculta" o le hace "sombra" (shadow) a la del alcance más externo. Dentro de ese bloque interno, cualquier referencia a ese nombre de variable se resolverá a la variable más cercana (la interna), haciendo que la externa sea _temporalmente_ inaccesible por su nombre.

```{figure} 3/shadowing.svg
:name: fig-shadowing
:width: 100%

Visualización del ocultamiento de variables (shadowing).
```

```c
#include <stdio.h>

int main() {
    int i = 10; // Variable local en main

    printf("En main, 'i' es: %d\n", i); // Imprime 10

    for (int i = 5; i > 0; i--) { // La variable 'i' de bloque oculta la local de main
        printf("Dentro del for, 'i' es: %d\n", i); // Imprime la cuenta regresiva desde 5 hasta 1
    }

    printf("Fuera del for, 'i' es de nuevo: %d\n", i); // Imprime 10
    return 0;
}
```

Y la salida, queda como:

```
En main, 'i' es: 10
Dentro del for, 'i' es: 5
Dentro del for, 'i' es: 4
Dentro del for, 'i' es: 3
Dentro del for, 'i' es: 2
Dentro del for, 'i' es: 1
Fuera del for, 'i' es de nuevo: 10
```


## Descomposición Funcional

El proceso de dividir un problema complejo en piezas pequeñas, comprensibles y fáciles de encarar se conoce como **descomposición funcional**. Cada parte se convierte en una función especializada con una única responsabilidad.

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

## Ejemplo Completo: Calcular el área de un rectángulo

### Paso 1: Entender el problema
Queremos un programa que solicite dos números (base y altura), calcule el área (base \* altura) y la muestre en pantalla.

### Paso 2: Dividir en tareas y responsabilidades
1.  Leer un valor entero validando la entrada.
2.  Calcular el área de forma pura.
3.  Mostrar el resultado en la salida estándar.

```c
#include <stdio.h>

int leer_entero(const char *mensaje);
int calcular_area(int base, int altura);

int main() {
    int base = leer_entero("Ingrese la base: ");
    int altura = leer_entero("Ingrese la altura: ");
    int area = calcular_area(base, altura);

    printf("El área es: %d\n", area);
    return 0;
}

int leer_entero(const char *mensaje) {
    int valor = 0;
    printf("%s", mensaje);
    scanf("%d", &valor);
    return valor;
}

int calcular_area(int base, int altura) {
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

---

## Factorización de Funciones Duplicadas

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


### Ejemplo de factorización:

```c
#include <stdio.h>

void solicitar_datos() {
    printf("Por favor ingrese sus datos.\n");
}

void mostrar_saludo(const char *mensaje) {
    printf("%s\n", mensaje);
    solicitar_datos();
}

int main() {
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

La función tiene una **tarea clara, definida y limitada**. Y aunque podemos
extender el concepto a la ‘toma de datos’ y a ‘mostrar el resultado’, con
quedarnos en lo que hace el trabajo estamos más que bien.

::::{tip}
Una buena función se puede describir en una frase corta. Si necesitás una
oración compuesta, probablemente estás metiendo dos responsabilidades en una.
::::

---

## Documentación de Funciones y Contratos

La documentación define las especificaciones formales que debe cumplir el código. En esta cátedra se utiliza el formato estructurado compatible con **Doxygen** para detallar precondiciones y poscondiciones.

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

### Precondiciones, Poscondiciones e Invariantes

En el contexto del diseño y verificación de software, estos conceptos forman
parte de la noción de **contrato** entre una función y su entorno. Estos
elementos permiten especificar, de manera formal y verificable, qué se espera
antes de ejecutar una operación, qué se garantiza después de ejecutarla y qué
propiedades deben mantenerse constantes durante su funcionamiento. En conjunto,
estos conceptos fortalecen la robustez, legibilidad y mantenibilidad del código,
al definir claramente las responsabilidades y limitaciones de cada parte del
sistema.

Más adelante, veremos detalles sobre este tema, por ahora, alcanza por plantear
los valores que no funcionan con el código y una descripción general del resultado
obtenido.

-   **Precondición (`#PRE`):** Condición lógica que debe cumplirse obligatoriamente antes de ejecutar la función. Es responsabilidad del llamador garantizarla.
-   **Poscondición (`#POST`):** Promesa que la función garantiza cumplir al finalizar su ejecución, siempre que se hayan respetado las precondiciones.
-   **Invariante:** Propiedad que permanece verdadera a lo largo de toda la ejecución del módulo o algoritmo.

### Ejemplo:

```c
#define DIV_CERO -99999

/**
 * Calcula el cociente entero entre dos números de forma segura.
 *
 * @param dividendo El número que será dividido (numerador).
 * @param divisor El número por el cual se dividirá (denominador).
 * @return El resultado de dividir dividendo por divisor, o el código de error
 *         DIV_CERO si el divisor es 0.
 *      #POST Si el divisor es 0 se retorna DIV_CERO. De lo contrario, se 
 *            retorna la división exacta entera.
 */
int dividir(int dividendo, int divisor) {
    if (divisor == 0) {
        return DIV_CERO;
    }
    return dividendo / divisor;
}
```

---



---

(contratos-funciones)=
## Contratos de Función: Precondiciones, Poscondiciones e Invariantes

Al diseñar funciones, la Regla {ref}`0x2003h` exige documentación estructurada. Una forma rigurosa de hacerlo es mediante contratos: especificaciones formales de qué garantiza el cliente (precondiciones) y qué garantiza la función (poscondiciones), junto con propiedades que deben mantenerse siempre (invariantes).

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
de operaciones o dentro de estructuras de control (como un lazo).

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

## Ejercicios sobre funciones

(funcion_doble)=
```exercise
:label: funcion_doble
Escribí una función que reciba un número entero y devuelva su doble. Probala desde `main()` con distintos valores.
```

:::{solution} funcion_doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int doble(int n) {
    return 2 * n;
}

int main() {
    printf("Doble de 5: %d\n", doble(5));
    printf("Doble de 12: %d\n", doble(12));
    return 0;
}
```
:::

:::exercise}
:label: funcion_mayor
:enumerator: funciones-2

Programá una función que reciba dos números enteros y retorne el mayor de ellos.
```

:::{solution} funcion_mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int mayor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 10;
    int y = 7;
    printf("El mayor es: %d\n", mayor(x, y));
    return 0;
}
```
:::

(funcion_par_impar)=
```exercise
:label: funcion_par_impar
Definí una función que indique si un número es par o impar. Mostrá el resultado llamando a la función desde `main()`.
```

:::{solution} funcion_par_impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

void par_impar(int n) {
    if (n % 2 == 0) {
        printf("%d es par\n", n);
    } else {
        printf("%d es impar\n", n);
    }
}

int main() {
    par_impar(7);
    par_impar(12);
    return 0;
}
```
:::

:::{exercise}
:label: funcion_promedio
:enumerator: funciones-4
Escribí una función que reciba tres notas enteras y devuelva el promedio en punto flotante. Mostrá el resultado en `main()`.
:::

:::{solution} funcion_promedio
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

float promedio(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

int main() {
    printf("Promedio: %.2f\n", promedio(7, 8, 10));
    return 0;
}
```
:::

:::{exercise}
:label: funcion_area
Implementá una función `area_rectangulo` que reciba base y altura, y devuelva el área.
:::

:::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int area_rectangulo(int base, int altura) {
    return base * altura;
}

int main() {
    printf("Área: %d\n", area_rectangulo(5, 4));
    return 0;
}
```
:::



## Glosario

:::{glossary}
efecto secundario
: Cualquier modificación de estado que ocurre fuera del ámbito de una función (ej: modificar variables globales o archivos).
:::

---

## Referencias y Lecturas Complementarias

- {cite:t}`kernighan_c_2014`. Capítulo 4: Functions and Program Structure.
- {cite:t}`king_c_2008`. Capítulo 9: Functions.
- {cite:t}`mcconnell_code_2004`. Capítulo 7: High-Quality Routines.
