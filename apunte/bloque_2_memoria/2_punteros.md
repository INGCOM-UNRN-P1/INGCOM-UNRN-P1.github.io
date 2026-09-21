---
title: "Punteros"
short_title: Punteros
subtitle: "Control directo de memoria en sistemas integrados"
---

(capitulo-punteros)=
## Introducción

Para profundizar en cómo funcionan estructuras como los arreglos y para ganar un
control más directo y eficiente sobre los recursos de tu programa, es
fundamental entender los **punteros**. Los punteros son la herramienta que nos
permite pasar de trabajar solo con los _valores_ de las variables a trabajar con
sus _ubicaciones_ en la memoria.


## Desarrollo

Introducción a los Punteros y la Memoria

(que-es-una-direccion-de-memoria-y-un-puntero)=
#### ¿Qué es una Dirección de Memoria y un Puntero?

Cada vez que declarás una variable, el entorno de ejecución y el sistema
operativo le asignan un bloque de espacio en la memoria del programa. En los
sistemas operativos modernos con soporte de hardware para paginación (a través
de la MMU o *Memory Management Unit*), los programas de usuario no acceden
directamente a las direcciones de la memoria RAM física. En su lugar, trabajan
dentro de un espacio de **direcciones virtuales (memoria lógica)**. El sistema
operativo se encarga de mapear de forma transparente estas direcciones lógicas a
direcciones físicas reales de la memoria RAM o incluso a disco (memoria de
intercambio o *swap*). Este mecanismo de abstracción proporciona seguridad y
aislamiento entre los diferentes procesos que se ejecutan simultáneamente en la
máquina.

Desde la perspectiva del programador en C, esta memoria lógica se organiza como
una secuencia de celdas contiguas de 1 byte (u octeto), donde cada celda posee
una dirección única representada comúnmente en formato hexadecimal (por ejemplo,
`0x7ffee390a1bc`).

Un **puntero** es simplemente otra variable cuyo contenido es, precisamente, una
de estas direcciones de memoria lógica.

Para visualizarlo, consideremos la siguiente organización en memoria de un
entero `numero` (de 4 bytes) almacenado en la dirección `0x7ffd` y un puntero
`ptr` almacenado en la dirección `0x8004` que apunta a él:

:::{table} Representación de variables en celdas de memoria contiguas
:label: tbl-representacion-memoria

| Dirección de Memoria | Nombre Variable | Tipo | Contenido (Valor) |
| :--- | :--- | :--- | :--- |
| `0x7ffd` | `numero` | `int` | `42` |
| `0x7ffe` | *(contiguo)* | - | *(parte de numero)* |
| `0x7fff` | *(contiguo)* | - | *(parte de numero)* |
| `0x8000` | *(contiguo)* | - | *(parte de numero)* |
| `0x8004` | `ptr` | `int*` | `0x7ffd` |

:::
<!-- {table} Representación de variables en celdas de memoria contiguas -->

Como se observa en la tabla, el valor almacenado en `ptr` (`0x7ffd`) coincide
exactamente con la dirección donde inicia la variable `numero`. Al
desreferenciar `ptr` (usando `*ptr`), accedemos al valor `42`.

:::{figure} 2/concepto_puntero.svg
:label: fig-concepto-puntero
:align: center

Concepto básico de un puntero. La variable `ptr` almacena la dirección física de
`numero` en la RAM.

:::
<!-- {figure} 2/concepto_puntero.svg -->

(declaracion-de-punteros)=
### Declaración de punteros

Para declarar un puntero, debés especificar el tipo de dato al que va a apuntar,
seguido de un asterisco (`*`) y el nombre de la variable. La regla de estilo
{ref}`0x0005h` indica que el asterisco debe ir junto al nombre de la variable.

:::{code-block}c
:linenos:
int *ptr_entero;
double *ptr_double;
char *ptr_char;

:::
<!-- {code-block}c -->

Una vez declarado, un puntero debe ser inicializado para que apunte a una
dirección de memoria específica y válida. No hacerlo es una fuente común de
errores graves. Tenés principalmente dos formas de inicializar un puntero:

(asignacion-a-una-direccion-especifica)=
#### Asignación a una dirección específica

Para que un puntero sea útil, generalmente lo hacés apuntar a una variable
existente. Esto se logra utilizando el operador de dirección `&` (ampersand), el
cual obtiene la dirección de memoria de dicha variable.

:::{code-block}c
:linenos:
int numero = 42;
int *ptr_numero =
    &numero; // ptr_numero ahora almacena la dirección de 'numero'

:::
<!-- {code-block}c -->

(inicializar-a-nulo-null)=
#### Inicializar a Nulo (`NULL`)

Si al momento de declarar un puntero no tenés una dirección de memoria válida
para asignarle, es **fundamental** inicializarlo a un estado seguro y conocido.
Para esto se utiliza la macro `NULL`.

:::{tip} Estilo: Inicialización Segura

La regla {ref}`0x7001h` (siempre inicializar variables) es especialmente crítica
para los punteros. Un puntero no inicializado es un "puntero salvaje" que apunta
a una dirección de memoria aleatoria. Adicionalmente, la regla {ref}`0x3008h`
indica que se debe usar `NULL` en lugar de `0` para esta inicialización, ya que
`NULL` expresa semánticamente la intención de que el puntero no apunta a ningún
objeto válido.

:::
<!-- {tip} Estilo: Inicialización Segura -->

`NULL` es una constante de preprocesador, que se encuentra definida en el
encabezado `<stddef.h>` y representa la dirección a «ningún lado».

:::{code-block}c
:linenos:
#include <stddef.h> // Necesario para NULL
int *puntero_seguro = NULL;

:::
<!-- {code-block}c -->

Es una práctica habitual en C que las funciones que devuelven punteros retornen
`NULL` para indicar un error o la ausencia de un resultado. Siempre debés
comprobar si un puntero es `NULL` antes de intentar desreferenciarlo (usar el
operador `*` sobre él).

:::{figure} 2/punteros_null.svg
:label: fig-punteros-null
:align: center

Representación de un puntero nulo y la verificación antes de desreferenciar.

:::
<!-- {figure} 2/punteros_null.svg -->

:::{danger} Peligro: Punteros No Inicializados (Punteros Salvajes)

Un puntero que ha sido declarado, pero no inicializado se conoce como "puntero
salvaje" (_wild pointer_). Contiene una dirección de memoria basura, es decir,
un valor aleatorio que podría apuntar a cualquier parte: a código del programa,
a datos del sistema operativo o a una zona no permitida.

Intentar leer o escribir en la dirección de un puntero salvaje es una operación
de alto riesgo que conduce a un **comportamiento indefinido**. Tu programa
podría fallar inmediatamente, corromper datos silenciosamente o crear
vulnerabilidades de seguridad.

:::
<!-- {danger} Peligro: Punteros No Inicializados (Punteros Salvajes) -->

**Regla de oro:** Siempre inicializá tus punteros, ya sea con la dirección de
una variable válida o con `NULL`.

:::{important} Aniquilación Post-Free (Evitando Punteros Colgantes)

Al trabajar con memoria asignada de forma dinámica, la llamada a `free(ptr)`
libera el bloque en el heap, pero la variable `ptr` sigue reteniendo la
dirección de memoria de la celda liberada. Para evitar desreferenciar
accidentalmente esta dirección física inválida (punteros colgantes o *dangling
pointers*), se debe aniquilar el puntero asignándolo inmediatamente a `NULL`
(ej: `free(ptr); ptr = NULL;`).

:::
<!-- {important} Aniquilación Post-Free (Evitando Punteros Colgantes) -->


(variable-de-referencia-o-puntero)=
#### Variable de Referencia (o Puntero)

*(Para comprender el marco pedagógico de los roles de variables, podés consultar
la introducción en la sección {ref}`roles-de-las-variables` del capítulo
[el capítulo del lenguaje C](../bloque_1_fundamentos/2_gradual.md))*.

Un puntero es una variable cuyo valor es una dirección de memoria física. En
términos didácticos, asume el **rol de variable de referencia**: su propósito no
es almacenar datos para operaciones directas, sino "apuntar" a otra variable,
facilitando un acceso y una manipulación indirecta sobre la misma.

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int numero = 100;
    int *ptrNumero; // 'ptrNumero' es un puntero, su rol es referenciar a
    'numero' ptrNumero =
        &numero; // 'ptrNumero' ahora apunta a la dirección de 'numero'
    printf("Valor de numero: %d\n", numero);
    printf("Direccion de numero: %p\n", (void *)&numero);
    printf("Valor al que apunta ptrNumero: %d\n", *ptrNumero); // Desreferencia
    el puntero printf("Valor de ptrNumero (direccion): %p\n",
                      (void *)ptrNumero);
    // Modificando 'numero' a traves del puntero
    *ptrNumero = 200;
    printf("Nuevo valor de numero (modificado via puntero): %d\n", numero);
    return 0;
}

:::
<!-- {code-block}c -->

El rol de `ptrNumero` es el de una **variable de referencia**, permitiendo
interactuar con `numero` de forma indirecta.

(operadores-de-punteros)=
### Operadores de Punteros

El trabajo con punteros se basa principalmente en dos operadores fundamentales:

- **Operador de Dirección `&` (Ampersand / "dirección de")**: Obtiene la
  dirección de memoria de una variable. Por ejemplo, `&numero` evalúa a la
  dirección física donde está guardada la variable `numero`. Esta dirección de
  memoria es un valor de solo lectura; no podés asignarle un valor a la
  dirección directamente (`&numero = 100` es inválido).

- **Operador de Indirección o Desreferencia `*` (Asterisco / "valor apuntado
  por")**: Permite acceder al contenido de la celda de memoria cuya dirección
  está guardada en el puntero. Este operador funciona tanto para leer como para
  escribir el valor apuntado, según dónde se lo ubique:
  - **Escritura (Modificación)**: Si usás `*ptr` a la izquierda de una
    asignación (por ejemplo, `*ptr = 150`), le estás indicando a la computadora
    que guarde el valor `150` en la dirección de memoria apuntada por `ptr`.
  - **Lectura (Acceso)**: Si usás `*ptr` en una expresión o a la derecha de una
    asignación (por ejemplo, `valor = *ptr` o dentro de un `printf`), estás
    pidiendo el valor contenido dentro del casillero al que apunta `ptr`.

:::{figure} 2/operadores_punteros.svg
:label: fig-operadores-punteros
:align: center

Funcionamiento de los operadores `&` (dirección de) y `*` (desreferencia).

:::
<!-- {figure} 2/operadores_punteros.svg -->

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int numero = 99;
    int *puntero = &numero; // '&numero' obtiene la dirección de memoria de la
    variable
        // Leemos el valor apuntado (lectura)
        // La expresión *puntero accede al valor contenido en 'numero'
        printf("El valor de 'numero' es: %d\n", *puntero); // Imprime 99
    // Modificamos el valor apuntado (escritura)
    // La expresión *puntero modifica el contenido en 'numero'
    *puntero = 150;
    printf("El nuevo valor de 'numero' es: %d\n", numero); // Imprime 150
    return 0;
}

:::
<!-- {code-block}c -->

Esta dualidad del operador de desreferencia es lo que hace a los punteros tan
poderosos, ya que nos permiten tanto leer como modificar datos de forma
indirecta.

(punteros-y-arreglos)=
#### Punteros y arreglos

El nombre de un arreglo no es un puntero, sino el identificador de un bloque de
memoria contiguo. Sin embargo, como se analizó en
el capítulo de [Secuencias](2_secuencias.md) (ver [decaimiento de
arreglos](#el-mecanismo-de-paso-a-funciones-paso-por-referencia-simulado)), al
evaluarse en la mayoría de las expresiones
de C este decae (se degrada) automáticamente a un puntero al primer elemento de
la secuencia (`&arreglo[0]`).

Esta relación nos permite usar punteros para acceder y manipular los elementos
de la secuencia de forma indirecta, lo cual nos lleva directamente a la
aritmética de punteros.








---

(aritmetica-de-punteros)=
### Aritmética de punteros

La aritmética de punteros permite realizar operaciones matemáticas sobre las
direcciones de memoria. A diferencia de las operaciones aritméticas
tradicionales, el compilador ajusta automáticamente los cálculos según el tamaño
físico del tipo de dato al que se apunta.

Si tenés un puntero `ptr` a un tipo de dato `T` que ocupa `sizeof(T)` bytes, al
hacer `ptr + 1`, la dirección de memoria física no se incrementa en 1, sino en
`sizeof(T)`. Este mecanismo es el fundamento del acceso indexado y el cálculo de
desplazamientos bidimensionales en memoria contigua que estudiamos en
{ref}`calculo-de-desplazamiento-de-memoria`. Esto permite "saltar" de un
elemento a otro
en un arreglo de forma eficiente.

:::{figure} 2/aritmetica_punteros.svg
:label: fig-aritmetica-punteros
:align: center

Aritmética de punteros: el incremento de un puntero depende del tamaño en bytes
del tipo de dato apuntado.

:::
<!-- {figure} 2/aritmetica_punteros.svg -->

(incremento-y-decremento)=
#### Incremento (`++`) y decremento (`--`)

Podés incrementar un puntero para que apunte al siguiente elemento de un arreglo
o decrementarlo para que apunte al anterior.

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;                               // ptr apunta a arr[0]
    ptr++;                                        // Ahora ptr apunta a arr[1]
    printf("El segundo elemento es: %d\n", *ptr); // Imprime 20
    ptr++;                                        // Ahora ptr apunta a arr[2]
    printf("El tercer elemento es: %d\n", *ptr);  // Imprime 30
    ptr--;                                        // Vuelve a apuntar a arr[1]
    printf("El segundo elemento de nuevo: %d\n", *ptr); // Imprime 20
    return 0;
}

:::
<!-- {code-block}c -->

(suma-y-resta)=
#### Suma (`+`) y resta (`-`)

Podés sumar o restar un valor entero a un puntero para desplazarte varias
posiciones dentro de un arreglo.

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr apunta a arr[0]
    // Acceder al cuarto elemento (índice 3)
    int *ptr_cuarto = ptr + 3;
    printf("El cuarto elemento es: %d\n", *ptr_cuarto);       // Imprime 40
    printf("También se puede acceder así: %d\n", *(ptr + 3)); // Imprime 40
    return 0;
}

:::
<!-- {code-block}c -->

(un-detalle-sobre-la-resta-en-punteros)=
#### Un detalle sobre la resta en punteros

Podés restar dos punteros que apunten a elementos del mismo arreglo. El
resultado no es una dirección de memoria, sino la cantidad de elementos que hay
entre ellos.

:::{code-block}c
:linenos:
#include <stddef.h> // Necesario para ptrdiff_t
#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[4];
    ptrdiff_t diferencia = ptr2 - ptr1;
    printf("Hay %td elementos entre ptr1 y ptr2.\n", diferencia); // Imprime 3
    return 0;
}

:::
<!-- {code-block}c -->

:::{note} ¿Qué es `ptrdiff_t`?

El tipo de dato del resultado de la resta de punteros es
[`ptrdiff_t`](https://en.cppreference.com/w/c/types/ptrdiff_t.html), un tipo
entero con signo definido en la cabecera `<stddef.h>`. Para imprimirlo
correctamente con `printf`, se utiliza el especificador de formato `%td`.

:::
<!-- {note} ¿Qué es `ptrdiff_t`? -->








---

(punteros-en-funciones-y-efectos-secundarios)=
### Punteros en funciones y efectos secundarios

:::{important} Pasaje por Valor de Punteros

C no dispone de pasaje por referencia nativo. Cuando pasas un puntero a una
función (por ejemplo, `void duplicar(int *ptr)`), el compilador realiza una
copia por valor de la dirección de memoria almacenada. Como la dirección de
copia sigue apuntando a la misma celda de memoria RAM del llamador, cualquier
acceso mediante el operador de desreferencia `*ptr` modificará el valor
original.

:::
<!-- {important} Pasaje por Valor de Punteros -->

Esta simulación de pasaje por referencia también se aplica a los arreglos (ver
{ref}`el-mecanismo-de-paso-a-funciones-paso-por-referencia-simulado`). Al pasar
la dirección de memoria de una variable por valor, aunque la dirección en sí se
copia en el registro de activación (*stack frame*), la desreferencia de este
puntero permite interactuar directamente con la celda de memoria original del
invocador (efecto secundario).

(justificacion-de-diseno-eficiencia-y-rendimiento-en-sistemas)=
#### Justificación de Diseño: Eficiencia y Rendimiento en Sistemas

La simulación de referencia mediante indirección no es únicamente una
herramienta para permitir la
modificación de variables (efectos secundarios). En el desarrollo de software de
sistemas, es un mecanismo indispensable por razones de rendimiento.

Cuando pasamos un dato por valor, todo su contenido debe copiarse en el marco de
pila de la función invocada. Si el argumento es un tipo de dato básico (como un
`int` de 4 bytes o un `char` de 1 byte), el costo de la copia es insignificante.
Sin embargo, en C trabajamos frecuentemente con estructuras de datos complejas
(`struct`) que pueden agrupar arreglos y múltiples miembros, ocupando cientos o
miles de bytes. Copiar estructuras de gran tamaño de manera repetida consume
tiempo de procesamiento de la CPU (operaciones de copia en memoria) y agota
rápidamente el espacio limitado del *stack* del programa (pudiendo provocar un
desbordamiento de pila o *stack overflow*).

Al pasar un puntero a dicha estructura:
1. **Consumo de memoria mínimo**: Se copia únicamente la dirección de memoria,
   cuyo tamaño es fijo y pequeño (4 bytes en arquitecturas de 32 bits, 8 bytes
   en arquitecturas de 64 bits).
2. **Tiempo de ejecución constante**: La transmisión de una dirección de memoria
   es una operación de bajo costo a nivel de registros de la CPU, independiente
   del tamaño real del objeto apuntado.

Para garantizar que esta optimización no vulnere la seguridad de los datos (es
decir, evitar que la función modifique accidentalmente la estructura que solo
queríamos leer), debemos calificar el parámetro con `const`. Esto crea un
contrato inmutable: el compilador rechazará cualquier intento de escritura sobre
la estructura, logrando la máxima eficiencia de rendimiento con la seguridad de
la inmutabilidad del paso por valor clásico.

:::{figure} 2/paso_por_referencia.svg
:label: fig-paso-por-referencia
:align: center

Diferencia entre el paso por valor y la simulación de referencia mediante
punteros.

:::
<!-- {figure} 2/paso_por_referencia.svg -->

:::{code-block}c
:linenos:
#include <stdio.h>
// La función recibe dos punteros a enteros
void intercambiar(int *a, int *b)
{
    int temporal = *a; // Guardamos el valor al que apunta 'a'
    *a = *b;           // Asignamos al valor de 'a' el valor de 'b'
    *b = temporal;     // Asignamos al valor de 'b' el valor guardado
}
int main()
{
    int x = 10;
    int y = 20;
    printf("Valores originales: x = %d, y = %d\n", x, y);
    // Pasamos las direcciones de memoria de 'x' e 'y'
    intercambiar(&x, &y);
    printf("Valores intercambiados: x = %d, y = %d\n", x, y);
    return 0;
}

:::
<!-- {code-block}c -->

(parametro-de-salida-a-traves-de-punteros)=
#### Parámetro de Salida (a través de Punteros)

*(Este rol extiende el pasaje de datos entre ámbitos; para más contexto
conceptual, podés revisar la sección {ref}`roles-de-las-variables` de [el
capítulo del lenguaje C](../bloque_1_fundamentos/2_gradual.md))*.

Dado que en C todo pasaje de argumentos es estrictamente por valor (la función
trabaja sobre copias en su propio stack frame), para permitir que una función
altere variables del llamador y "retorne" resultados de manera indirecta,
debemos emplear punteros en el rol de **parámetros de salida**.

:::{code-block}c
:linenos:
#include <stdio.h>
// 'resultado' es un parámetro de salida (puntero)
void dividir(int dividendo, int divisor, int *cociente, int *resto)
{
    if (divisor != 0)
    {
        *cociente = dividendo / divisor; // Modifica el valor apuntado por
        'cociente' *resto =
            dividendo % divisor; // Modifica el valor apuntado por
        'resto'
    }
    else
    {
        printf("Error: Division por cero.\n");
        // Podríamos asignar valores especiales o manejar el error de otra
        // forma
        *cociente = 0;
        *resto = 0;
    }
}
int main()
{
    int num1 = 17;
    int num2 = 5;
    int miCociente;
    int miResto;
    // Pasamos las direcciones de 'miCociente' y 'miResto'
    dividir(num1, num2, &miCociente, &miResto);
    printf("%d dividido por %d es: Cociente = %d, Resto = %d\n", num1, num2,
           miCociente, miResto);
    return 0;
}

:::
<!-- {code-block}c -->

Aquí, `cociente` y `resto` son **parámetros de salida**. La función `dividir`
escribe directamente en las ubicaciones de memoria de `miCociente` y `miResto`
en la función `main` a través de sus punteros, permitiendo que `main` acceda a
los resultados de la división.

(parametro-de-entrada-salida-a-traves-de-punteros)=
#### Parámetro de Entrada/Salida (a través de Punteros)

*(Esta especialización semántica complementa los roles analizados en la sección
{ref}`roles-de-las-variables` de [el capítulo del lenguaje
C](../bloque_1_fundamentos/2_gradual.md))*.

Similar al parámetro de salida, un **parámetro de entrada/salida** utiliza un
puntero para permitir que la función lea un valor inicial proporcionado por el
invocador (entrada) y, tras procesarlo, modifique ese mismo espacio de memoria
física (salida), reintegrando el valor alterado al ámbito original.

:::{code-block}c
:linenos:
#include <stdio.h>
// 'contador' es un parámetro de entrada/salida
void incrementarContador(int *contador)
{
    printf("Valor del contador al entrar a la funcion: %d\n", *contador);
    (*contador)++; // Incrementa el valor apuntado por 'contador'
    printf("Valor del contador al salir de la funcion: %d\n", *contador);
}
int main()
{
    int miVariableContador = 10;
    printf("Valor inicial de miVariableContador: %d\n", miVariableContador);
    // Pasamos la dirección de 'miVariableContador'
    incrementarContador(&miVariableContador);
    printf("Valor final de miVariableContador: %d\n", miVariableContador);
    return 0;
}

:::
<!-- {code-block}c -->

La variable `contador` de `incrementarContador` tiene el rol de **parámetro de
entrada/salida**. La función lee el valor inicial de `miVariableContador`
(`10`), lo incrementa a `11`, y ese cambio se refleja directamente en
`miVariableContador` en `main`.

(el-impacto-en-los-efectos-secundarios)=
#### El impacto en los efectos secundarios

Esta capacidad para modificar variables externas al ámbito de la función
constituye un efecto secundario (side effect) análogo al que estudiamos con la
modificación de arreglos en [el capítulo de Secuencias](2_secuencias.md).

Si bien los efectos secundarios son indispensables para la eficiencia y para
permitir la salida de múltiples resultados, incrementan la complejidad del flujo
lógico del programa. El programador debe rastrear minuciosamente qué variables
del invocador pueden cambiar tras la ejecución de la función, razón por la cual
es obligatorio documentar sus poscondiciones y restringir las mutaciones no
deseadas mediante `const` (ver regla de estilo {ref}`0x3007h`).

(el-calificador-const-el-ancla-de-seguridad-con-punteros)=
### El Calificador `const`: el ancla de seguridad con punteros

El calificador `const` es una de las herramientas más importantes en C para
escribir código seguro, predecible y fácil de entender. Actúa como un "contrato"
que le dice al compilador y a otros programadores qué se supone que no debe
cambiar. Cuando lo usás con punteros, como lo exige la regla {ref}`0x3007h`, te
permite "bloquear" o bien el dato apuntado, el puntero en sí, o ambos.

`const` nos permite poner reglas sobre qué se puede modificar, _potencialmente_,
limitando los efectos secundarios productos de pasar el puntero a la función.

:::{figure} 2/const_punteros.svg
:label: fig-const-punteros
:align: center

Modificador const aplicado a punteros: diferencia entre puntero constante y
datos apuntados constantes.

:::
<!-- {figure} 2/const_punteros.svg -->

(1-puntero-a-un-dato-constante-no-podes-cambiar-el-valor)=
#### 1. Puntero a un Dato Constante (No podés cambiar el VALOR)

Esta es la forma más común. La nota adhesiva es normal (podés borrar el número y
escribir otro), pero el casillero al que apunta está cerrado con llave. No podés
cambiar su contenido a través de este puntero.

- **Sintaxis:** `const T *puntero`.
- **Regla:** El **valor** apuntado es constante. El **puntero** es variable.

:::{code-block}c
:linenos:
#include <stdio.h>
void imprimir(const char *mensaje)
{
    // mensaje[0] = 'X'; // ERROR DE COMPILACIÓN: intentás modificar un dato
    constante.printf("El mensaje es: %s\n", mensaje);
}
int main()
{
    char saludo[] = "Hola";
    char despedida[] = "Chau";
    const char *ptr = saludo;
    // *ptr = 'h'; // ERROR DE COMPILACIÓN: no se puede modificar el contenido.
    ptr = despedida; // VÁLIDO: el puntero puede apuntar a otra dirección.
    imprimir(ptr);   // Imprime "Chau"
    return 0;
}

:::
<!-- {code-block}c -->

**¿Cuándo usarlo?:** Siempre que pases un puntero a una función que solo
necesita leer los datos, pero no modificarlos. Esto previene efectos secundarios
_accidentales_.

(2-puntero-constante-a-un-dato-no-podes-cambiar-la-direccion)=
#### 2. Puntero Constante a un Dato (No podés cambiar la dirección)

En este caso, la nota adhesiva está escrita con tinta imborrable: siempre
apuntará al mismo casillero. Sin embargo, el casillero en sí no tiene llave, por
lo que podés cambiar su contenido libremente.

- **Sintaxis:** `T * const puntero`.
- **Regla:** El puntero es constante. El valor apuntado es variable.

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int valor_a = 10;
    int valor_b = 20;
    // El puntero debe inicializarse en la declaración, ya que no se puede
    cambiar después.int *const ptr = &valor_a;
    *ptr = 50; // VÁLIDO: podés modificar el valor en la dirección apuntada.
               // Ahora, 'valor_a' es 50.
    // ptr = &valor_b; // ERROR DE COMPILACIÓN: no se puede reasignar un
    // puntero
    constante.printf("El valor de A es: %d\n", valor_a); // Imprime 50
    return 0;
}

:::
<!-- {code-block}c -->

**Cuándo usarlo:** Cuando necesitás que un puntero se refiera siempre a la misma
ubicación de memoria, como un búfer fijo o una dirección de hardware específica.

(3-puntero-constante-a-un-dato-constante-no-podes-cambiar-nada)=
#### 3. Puntero Constante a un Dato Constante (No podés cambiar NADA)

Esta es la forma más restrictiva. La nota está escrita con tinta imborrable y el
casillero está cerrado con llave. No podés cambiar ni a dónde apunta el puntero,
ni el contenido del lugar al que apunta.

- **Sintaxis:** `const T * const puntero`.
- **Regla:** Tanto el puntero como el valor apuntado son constantes.

:::{code-block}c
:linenos:
#include <stdio.h>
int main()
{
    int valor_fijo = 100;
    int otro_valor = 200;
    const int *const ptr = &valor_fijo;
    // *ptr = 150;     // ERROR DE COMPILACIÓN: el valor es constante.
    // ptr = &otro_valor; // ERROR DE COMPILACIÓN: el puntero es constante.
    printf("El valor fijo es: %d\n", *ptr); // Imprime 100
    return 0;
}

:::
<!-- {code-block}c -->

**Cuándo usarlo:** Para definir una referencia totalmente inmutable a un dato,
como un puntero a una tabla de configuración o a una constante almacenada en
memoria de solo lectura.

(diferencia-estricta-const-int-p-vs-int-const-p)=
#### Diferencia estricta: `const int *p` vs `int *const p`

Para evitar confusiones al leer declaraciones con el calificador `const`, se
puede aplicar una regla de lectura de derecha a izquierda:

* `const int *p` o `int const *p`: `p` es un puntero a un entero constante
  (`const int`). El valor apuntado no se puede modificar a través del puntero.
* `int *const p`: `p` es un puntero constante (`const`) a un entero (`int`). El
  puntero no puede apuntar a otra dirección de memoria una vez inicializado.

La diferencia en las restricciones del compilador se resume a continuación:

:::{table} Comparación de restricciones con `const`
:label: tbl-comparacion-const-punteros

| Declaración | ¿Se puede reasignar el puntero (`p = &y`)? | ¿Se puede modificar el valor apuntado (`*p = 10`)? |
| :--- | :---: | :---: |
| `const int *p` | Sí | No |
| `int *const p` | No | Sí |

:::
<!-- {table} Comparación de restricciones con `const` -->

Analizá el siguiente comportamiento con este fragmento de código:

:::{code-block}c
:linenos:
int x = 5;
int y = 10;
// Puntero a constante (el valor apuntado no se puede modificar)
const int *p_a_const = &x;
p_a_const = &y; // VÁLIDO: se cambia la dirección almacenada en el
puntero.
    // *p_a_const = 20;   // ERROR DE COMPILACIÓN: el contenido es de solo
    // lectura. Puntero constante (la dirección almacenada no se puede
    // modificar)
    int *const p_const = &x;
*p_const = 20; // VÁLIDO: se modifica el entero al que apunta.
// p_const = &y;      // ERROR DE COMPILACIÓN: el puntero es de solo lectura.

:::
<!-- {code-block}c -->

(documentando-funciones-con-punteros)=
### Documentando funciones con punteros

Cuando una función utiliza punteros como parámetros, especialmente para
modificar datos fuera de su propio ámbito (efectos secundarios), una
documentación clara y precisa es fundamental. La documentación actúa como un
**contrato** entre la función y quien la llama (el "cliente"). Este contrato
establece las responsabilidades de cada parte para garantizar que la función
opere de manera segura y predecible.

Usaremos la función `intercambiar` como ejemplo para ilustrar cómo documentar
este contrato, definiendo el flujo de los datos, las precondiciones, las
poscondiciones y los invariantes.

(direccion-del-flujo-de-informacion)=
#### Dirección del Flujo de Información

Al trabajar con punteros, no solo es importante el tipo de dato, sino también la
"dirección" en la que fluye la información. Se usa una convención simple para
indicarlo:

- **`[in]`**: El puntero se usa solo para **leer** datos. La función no
  modificará el valor al que apunta. **Es obligatorio calificar estos parámetros
  con `const`** para que el compilador garantice esta invariante y prevenga
  efectos secundarios accidentales.
- **`[out]`**: El puntero se usa para **escribir** un resultado. El valor
  inicial al que apunta no es relevante para la función, pero al finalizar,
  contendrá un dato de salida.
- **`[in, out]`**: El puntero se usa tanto para **leer** el valor inicial como
  para **escribir** un nuevo valor. La función modifica el dato original.

---

(contratos-ii-precondiciones-poscondiciones-e-invariantes-con-punteros)=
#### Contratos II: Precondiciones, Poscondiciones e Invariantes con punteros

Recordemos que es cada uno de ellos

- **Precondición**: Es una condición que **debe ser verdadera antes** de que se
  llame a la función. Es **responsabilidad del programador que llama** a la
  función cumplirla. Si no se cumple, la función no garantiza su comportamiento.
- **Poscondición**: Es una condición que la función **garantiza que será
  verdadera después** de que se ejecute exitosamente. Es la promesa o el
  resultado de la función.
- **Invariante**: Es una condición que es verdadera **antes, durante y después**
  de la ejecución de la función. Define propiedades que no cambian a lo largo de
  la operación. Estas son más importantes en las funciones que utilizan punteros
  dado que el código puede cambiar valores de forma indirecta.

Su uso como metodología de documentación es una simplificación de su verdadero
poder, pero nos ayuda a pensar que en términos de lo que entra, lo que sale y lo
que no cambia.

(ejemplo-de-documentacion-completa)=
#### Ejemplo de Documentación Completa

Aplicando estos conceptos, una documentación exhaustiva para la función
`intercambiar` se vería así, siguiendo el estilo creado por la cátedra.

:::{code-block}c
:linenos:
/**
 * Intercambia los valores de dos variables enteras a través de sus punteros.
 * @param[in, out] primero Puntero al primer valor. Su contenido será leído y
   luego
 * sobrescrito con el del segundo.
 * @param[in, out] segundo Puntero al segundo valor. Su contenido será leído y
   luego
 * sobrescrito con el contenido del primero.
 * @pre Ambos punteros no deben ser NULL y apuntar a direcciones de memoria
   válidas y modificables.
 * @post El valor almacenado en la dirección apuntada por 'primero' será el
   valor original
 * que se encontraba en la dirección de 'segundo' y viceversa. No se
   introducirán otros valores por fuera
 * de los que estén referenciados.
 */
void intercambiar(int *primero, int *segundo)
{
    int temporal = *primero;
    *primero = *segundo;
    *segundo = temporal;
}

:::
<!-- {code-block}c -->

De esta forma, eliminamos las ambigüedades, y reducimos los potenciales errores.








---

(la-degradacion-de-arreglos-a-punteros)=
### La "degradación" de arreglos a punteros

Uno de los comportamientos más importantes —y a menudo confusos— en C es que los
**arreglos se "degradan" (decay) a punteros** en la mayoría de los contextos.
Este no es un truco, sino una regla de conversión fundamental del lenguaje que
explica la íntima relación entre ambos conceptos.

(que-significa-realmente-la-degradacion)=
#### ¿Qué significa realmente la "degradación"?

La regla es simple: cuando usás el nombre de un arreglo en una expresión (por
ejemplo, al asignarlo a un puntero o pasarlo a una función), el compilador no
trabaja con el arreglo completo. En su lugar, lo convierte automáticamente en un
**puntero al primer elemento** de ese arreglo.

Por lo tanto, las siguientes dos líneas de código son funcionalmente idénticas:

:::{code-block}c
:linenos:
int numeros[5] = {10, 20, 30, 40, 50};
// La "degradación" ocurre aquí: 'numeros' se convierte en la dirección de
numeros[0] int *p = numeros;
// Esta es la forma explícita y equivalente
int *p_explicito = &numeros[0];
printf("La dirección almacenada en p es: %p\n", (void *)p);
printf("La dirección del primer elemento es: %p\n", (void *)&numeros[0]);

:::
<!-- {code-block}c -->

(consecuencias-practicas-y-cruciales-de-la-degradacion)=
#### Consecuencias Prácticas (y Cruciales) de la Degradación

Entender esta conversión es vital porque tiene implicaciones directas en cómo
escribís tu código, especialmente con funciones y el operador `sizeof`.

Cuando pasás un arreglo a una función, lo que la función recibe en realidad es
una copia del puntero a su primer elemento. La función _nunca_ recibe la copia
del arreglo.

Por eso, estas tres declaraciones de función son absolutamente equivalentes para
el compilador:

:::{code-block}c
:linenos:
void procesar_datos(int arr[10]); // El 10 es ignorado por el compilador
void procesar_datos(int arr[]);   // Notación más común para indicar que se
espera un arreglo void
procesar_datos(int *arr); // La forma más honesta: la función recibe un
puntero

:::
<!-- {code-block}c -->

Debido a esto, la función pierde la información sobre el tamaño original del
arreglo y el tamaño que obtendremos es únicamente el de la dirección de memoria.

$$\text{sizeof}(\text{arreglo decaido}) = \text{sizeof}(\text{puntero})$$

:::{code-block}c
:linenos:
#include <stdio.h>
// La función recibe un puntero, sin importar cómo se declare el parámetro.
void imprimir_tamano(int arr[])
{
    // ¡Peligro! Esto NO mide el tamaño del arreglo original.
    // Mide el tamaño de un puntero en tu sistema (usualmente 4 u 8 bytes).
    printf("Tamaño DENTRO de la función: %zu bytes\n", sizeof(arr));
}

:::
<!-- {code-block}c -->

`sizeof` funciona como es esperado solo cuando su uso se hace en el mismo
alcance de la declaración del arreglo.

Por lo que hacer `sizeof(arreglo)` va a devolver el tamaño total en bytes del
arreglo, de forma que sea (número de elementos \* tamaño del tipo del arreglo).

$$\text{sizeof}(\text{arreglo}) = \text{elementos} \times \text{sizeof}(T)$$

:::{code-block}c
:linenos:
int main()
{
    int mi_arreglo[10] = {0};
    // Aquí 'sizeof' conoce el tamaño real del arreglo.
    printf("Tamaño FUERA de la función: %zu bytes\n", sizeof(mi_arreglo)); //
    Imprimirá 40(10 * 4 bytes) imprimir_tamano(mi_arreglo); // Imprimirá 4 u 8
    return 0;
}

:::
<!-- {code-block}c -->

:::{important} Regla de Oro

Debido a la degradación, **tenés que pasar el tamaño de un arreglo a una función
como un parámetro extra**. La función no tiene otra forma de saber hasta dónde
puede leer o escribir de forma segura. (Y ya que estamos, como un `size_t` para
que todo quede más bonito.)

:::
<!-- {important} Regla de Oro -->


(punteros-dobles-la-indireccion-a-un-nuevo-nivel)=
### Punteros Dobles: La Indirección a un Nuevo Nivel

Un puntero doble es, literalmente, un **puntero que apunta a otro puntero**.
Introduce un nivel adicional de indirección, lo que significa que necesitás
seguir dos direcciones para llegar al dato final.

Si un puntero (`int *p`) es una nota con la dirección de un cofre que contiene
un tesoro (un `int`), un puntero doble (`int **pp`) es una nota con la dirección
de **otra nota**, que a su vez tiene la dirección del cofre del tesoro.

:::{code-block}c
:linenos:
int valor = 100;
int *p = &valor; // p apunta a 'valor'
int **pp = &p;   // pp apunta a 'p'

:::
<!-- {code-block}c -->

Podemos acceder a `valor`, desreferenciando dos veces el puntero `pp`;

:::{code-block}c
:linenos:
printf("%d\n", **pp);

:::
<!-- {code-block}c -->

Esta capacidad de manipular un puntero a través de otro puntero es
extremadamente poderosa y se usa principalmente en dos escenarios cruciales.

Uno de ellos lo veremos aquí, el segundo, lo haremos cuando veamos memoria
dinámica.

(simular-pasaje-por-referencia-para-punteros)=
#### Simulación de Referencia mediante Indirección para Punteros

Recordá que C siempre pasa los argumentos a las funciones **por valor**. Esto
significa que la función recibe una **copia** del argumento. Si pasás un puntero
`int *p`, la función recibe una copia de la dirección que `p` contiene. Podés
usar esa copia para modificar el dato original (`*p = 99`), pero no podés
cambiar a dónde apunta el puntero original.

Para poder modificar el puntero original desde dentro de una función, necesitás
pasar la dirección de ese puntero, es decir, un puntero doble.

:::{code-block}c
:linenos:
#include <stdio.h>
// Función para intercambiar el valor de dos punteros.
// Se utilizan punteros dobles (**), ya que necesitamos modificar
// las direcciones de memoria a las que apuntan los punteros originales.
void intercambiar_punteros(int **puntero1, int **puntero2)
{
    int *temp = *puntero1;
    *puntero1 = *puntero2;
    *puntero2 = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;
    printf("Antes del intercambio:\n");
    printf("ptr_a apunta a %d (direccion: %p)\n", *ptr_a, (void *)ptr_a);
    printf("ptr_b apunta a %d (direccion: %p)\n", *ptr_b, (void *)ptr_b);
    // Llamamos a la función pasando las direcciones de los punteros
    intercambiar_punteros(&ptr_a, &ptr_b);
    printf("\nDespues del intercambio:\n");
    printf("ptr_a apunta a %d (direccion: %p)\n", *ptr_a, (void *)ptr_a);
    printf("ptr_b apunta a %d (direccion: %p)\n", *ptr_b, (void *)ptr_b);
    return 0;
}

:::
<!-- {code-block}c -->

Al desreferenciar `puntero1` y `puntero2`, accedemos directamente a los punteros
originales (`ptr_a` y `ptr_b` en `main`) y podemos modificar las direcciones de
memoria que almacenan.

:::{note} Conversión explícita a `void*` en printf

En este ejemplo, se realiza una conversión explícita `(void*)` al imprimir los
punteros con `%p` para evitar la advertencia de compilación `"warning: format
'%p' expects argument of type 'void *'"`. Esta es la forma estándar recomendada
en C para imprimir direcciones de memoria de manera segura y limpia.

:::
<!-- {note} Conversión explícita a `void*` en printf -->


(manipulando-arreglos-con-aritmetica-de-punteros)=
### Manipulando arreglos con aritmética de punteros

La relación entre arreglos y punteros en C es tan estrecha que se pueden usar de
forma intercambiable en muchos contextos.

(1-recorrido-solo-lectura)=
#### 1. Recorrido solo lectura

La tarea más básica es iterar sobre todos los elementos para leerlos o
imprimirlos. La estrategia consiste en tener un puntero que avanza y un puntero
"límite" que nos indica cuándo detenernos.

**Método:**

1.  Declará un puntero `ptr` que apunte al inicio del arreglo.
2.  Declará otro puntero `fin` que apunte a la dirección de memoria
    **inmediatamente posterior** al último elemento. Esto substituye el 'conteo'
    de posiciónes.
3.  El lazo `while` se ejecuta mientras `ptr` sea menor que `fin`.

:::{code-block}c
:linenos:
#include <stddef.h> // Para size_t
#include <stdio.h>
void imprimir_arreglo(const int *arr, size_t tamano)
{
    const int *ptr = arr;
    const int *fin = arr + tamano; // Puntero al final del arreglo + 1
    printf("Contenido del arreglo: ");
    while (ptr < fin)
    {
        printf("%d ", *ptr); // 1. Leer el valor actual
        ptr++;               // 2. Mover el puntero al siguiente elemento
    }
    printf("\n");
}
int main()
{
    int numeros[] = {10, 20, 30, 40, 50};
    imprimir_arreglo(numeros, 5);
    return 0;
}

:::
<!-- {code-block}c -->

(2-busqueda-de-un-elemento)=
#### 2. Búsqueda de un elemento

Para buscar un valor, recorremos el arreglo y nos detenemos si encontramos una
coincidencia. La función devolverá un puntero al elemento encontrado o `NULL` si
no se encuentra. La comprobación explícita contra `NULL` sigue la regla
{ref}`0x2006h`.

**Método:**

1.  Declará los punteros `ptr` y `fin` como en el ejemplo anterior.
2.  El lazo `while` se ejecuta mientras no lleguemos al final y no hayamos
    encontrado el valor.
3.  Después del lazo, si `ptr != fin`, significa que el lazo se detuvo porque
    encontramos el elemento. Si son iguales, es porque recorrimos todo sin
    éxito.
4.  Si el lazo termina sin encontrar el valor, devolver `NULL`.

:::{code-block}c
:linenos:
#include <stddef.h> // Para NULL y size_t
#include <stdio.h>
// Devuelve un puntero al primer elemento que coincida con 'valor', o NULL si
// no
se encuentra.const int *buscar_valor(const int *arr, size_t tamano, int valor)
{
    const int *ptr = arr;
    const int *fin = arr + tamano;
    const int *resultado = NULL; // Inicializamos con NULL
    // El lazo continúa mientras no hayamos llegado al final
    // Y no hayamos encontrado el valor.
    while (ptr < fin && resultado == NULL)
    {
        if (*ptr == valor)
        {
            resultado = ptr; // Asignamos la dirección si se encuentra
        }
        ptr++;
    }
    return resultado; // Devolvemos el resultado final
}
int main()
{
    int numeros[] = {10, 20, 30, 40, 50};
    int valor_a_buscar = 30;
    const int *encontrado = buscar_valor(numeros, 5, valor_a_buscar);
    if (encontrado != NULL)
    {
        printf("Valor %d encontrado en la dirección de memoria %p\n",
               *encontrado, (void *)encontrado);
    }
    else
    {
        printf("Valor %d no encontrado en el arreglo.\n", valor_a_buscar);
    }
    return 0;
}

:::
<!-- {code-block}c -->

(3-modificando-el-arreglo)=
#### 3. Modificando el arreglo

Para modificar los datos, usamos el operador de desreferencia (`*`) en el lado
izquierdo de una asignación. Esto modifica el valor en la memoria a la que
apunta el puntero.

**Método:**

1.  El recorrido es idéntico al de la lectura.
2.  Dentro del lazo, en lugar de leer, realizamos una asignación:
    `*ptr = nuevo_valor`.

:::{code-block}c
:linenos:
#include <stddef.h> // Para size_t
#include <stdio.h>
// Duplica el valor de cada elemento en el arreglo.
void duplicar_valores(int *arr, size_t tamano)
{
    int *ptr = arr;
    int *fin = arr + tamano;
    while (ptr < fin)
    {
        *ptr = *ptr * 2; // Modifica el valor en la memoria apuntada
        ptr++;
    }
}
int main()
{
    int numeros[] = {1, 2, 3, 4, 5};
    printf("Arreglo original: 1 2 3 4 5\n");
    // (Código para imprimirlo, podemos usar el de la primera sección)
    duplicar_valores(numeros, 5);
    printf("Arreglo modificado: %d %d %d %d %d\n", numeros[0], numeros[1],
           numeros[2], numeros[3], numeros[4]);
    // Salida esperada: 2 4 6 8 10
    return 0;
}

:::
<!-- {code-block}c -->

(4-copiando-un-arreglo)=
#### 4. Copiando un Arreglo

Para copiar un arreglo, necesitamos dos punteros: uno para la fuente (de donde
leemos) y otro para el destino (donde escribimos). Ambos deben avanzar en cada
paso.

**Método:**

1.  Creá un puntero `fuente` para el arreglo original y un puntero `destino`
    para el nuevo.

2.  El lazo se ejecuta mientras el puntero `fuente` no llegue a su final.

3.  Dentro del lazo, copiá el valor y luego incrementá **ambos** punteros.

:::{code-block}c
:linenos:
#include <stddef.h> // Para size_t
#include <stdio.h>
void copiar_arreglo(int *destino, const int *fuente, size_t tamano)
{
    const int *ptr_fuente = fuente;
    int *ptr_destino = destino;
    const int *fin_fuente = fuente + tamano;
    // Lazo principal de copia
    while (ptr_fuente < fin_fuente)
    {
        *ptr_destino = *ptr_fuente;
        ptr_fuente++;
        ptr_destino++;
    }
    // Una forma más compacta pero potencialmente
    // menos legible de escribir lo de arriba:
    // while (ptr_fuente < fin_fuente) {
    //     *ptr_destino++ = *ptr_fuente++;
    // }
}
int main()
{
    int arreglo_a[] = {100, 200, 300};
    int arreglo_b[3]; // Arreglo vacío para recibir la copia
    copiar_arreglo(arreglo_b, arreglo_a, 3);
    printf("Contenido del arreglo copiado: %d %d %d\n", arreglo_b[0],
           arreglo_b[1], arreglo_b[2]);
    // Salida esperada: 100 200 300
    return 0;
}

:::
<!-- {code-block}c -->

:::{warning} Advertencia sobre los límites de los arreglos

Este último ejemplo, debiera de recibir un tamaño para cada arreglo y verificar
que los tamaños de ambos sean 'compatibles' entre sí. La regla de estilo
{ref}`0x300Ch` es crucial aquí.

La mayor ventaja y el mayor peligro de la aritmética de punteros es su libertad.
El lenguaje C no te impedirá incrementar un puntero más allá del final de un
arreglo. Es **tu responsabilidad** como programador asegurarte de que tus lazos
y operaciones se mantengan siempre dentro de los límites válidos del arreglo
para evitar corrupción de memoria y comportamientos indefinidos.

:::
<!-- {warning} Advertencia sobre los límites de los arreglos -->

(5-version-alternativa)=
#### 5. Versión alternativa

Si la función que necesitamos crear, necesita de la posición en la que nos
encontramos, no vamos a escapar de 'contar' posiciones.

En ese caso, lo que podemos hacer, es ir sumando al puntero del arreglo la
`i`-esima posición, en lugar de ir incrementando el puntero mismo.

:::{code-block}c
:linenos:
for (size_t i = 0; i < 5; i++)
{
    printf("%d ", *(p + i));
}

:::
<!-- {code-block}c -->

De esta forma, podemos obtener un código que es más similar al uso tradicional
de arreglos

:::{code-block}c
:linenos:
void imprimir_arreglo(const int *ptr, size_t tamano)
{
    printf("Contenido del arreglo: ");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%zu:%d ", i, *(ptr + i));
    }
    printf("\n");
}

:::
<!-- {code-block}c -->

Prestá atención a los paréntesis en `*(p + i)`, ya que son cruciales para el
orden de las operaciones. Su presencia asegura que primero realicemos la
aritmética de punteros (calculando la nueva dirección `p + i`) y **después**
desreferenciemos esa dirección para obtener el valor que contiene.

Si omitieras los paréntesis y escribieras `*p + i`, el resultado sería
completamente diferente. Debido a la precedencia de operadores, primero se
desreferenciaría `*p` (obteniendo el valor en la dirección actual) y luego se le
sumaría `i` a ese valor, lo cual es una operación matemática, no de punteros.

En resumen:

- `*(p + i)` significa: "Andá `i` lugares más allá y decime qué valor hay allá".
- `*p + i` significa: "Decime qué valor hay acá y sumale `i`".










---

(proximos-pasos-memoria-dinamica)=
### Próximos Pasos: Memoria Dinámica

Los punteros que estudiaste en este capítulo son fundamentales, pero hasta ahora
solo trabajaste con memoria que el compilador gestiona automáticamente
(variables locales y globales). El verdadero poder de los punteros se revela
cuando aprendés a gestionar memoria **dinámicamente** durante la ejecución del
programa.

En el [Memoria Dinámica](../bloque_4_dinamica_interfaces/1_memoria_dinamica.md),
vas a aprender sobre:

- **El heap (montón):** Una región de memoria que podés solicitar y liberar bajo
  demanda.
- **Funciones de asignación dinámica:** Como `malloc` y `calloc`, que te
  permiten crear estructuras de datos de tamaño variable.
- **Gestión manual de memoria:** Cómo y cuándo liberar la memoria que asignaste
  con `free`.
- **Punteros avanzados:** Incluyendo `void *`, casteos complejos, y punteros a
  arrays `(*)[N]`.
- **Errores de memoria:** Memory leaks, dangling pointers, y cómo evitarlos.

Estos conceptos amplían dramáticamente lo que podés hacer en C, permitiéndote
crear programas que adaptan su uso de memoria a las necesidades del momento. Sin
embargo, con este poder viene una gran responsabilidad: la gestión manual de
memoria requiere disciplina y atención a los detalles.

Cuando te sientas cómodo con los conceptos de este capítulo, estás listo para
dar el próximo paso hacia la memoria dinámica.

(4_punteros-conexion-con-el-siguiente-tema)=
### Conexión con el Siguiente Tema

Los punteros que estudiamos operan sobre memoria **estática** (conocida en
compilación) o **automática** (stack, gestionada por el sistema). Pero la
verdadera potencia de los punteros emerge cuando los combinamos con **memoria
dinámica**: la capacidad de solicitar y liberar memoria durante la ejecución
según las necesidades del programa.

El apunte **[Memoria
Dinámica](../bloque_4_dinamica_interfaces/1_memoria_dinamica.md)** introduce la
gestión explícita de memoria mediante:

- **`malloc()`**: solicitar memoria del heap
- **`free()`**: liberar memoria para evitar memory leaks
- **Stack vs Heap**: diferencias conceptuales y de performance
- **Estructuras dinámicas**: listas enlazadas, árboles, grafos

La memoria dinámica permite construir estructuras que crecen y encogen según
necesidad: una lista que se expande al agregar elementos, un grafo que se
construye progresivamente. Sin embargo, introduce responsabilidad total sobre el
ciclo de vida de la memoria: **cada `malloc()` debe tener su `free()`
correspondiente**.

Los punteros son las herramientas; la memoria dinámica es el material sobre el
que trabajan. Juntos, permiten implementar cualquier estructura de datos
imaginable, desde simples listas hasta bases de datos completas.

**Pregunta puente**: Si declaramos `int arr[1000000]` en una función, el
programa probablemente falle con stack overflow. ¿Por qué? ¿Cómo solicitamos
memoria para estructuras arbitrariamente grandes? La respuesta está en la
memoria dinámica y el heap.

(4_punteros-textos-fundamentales)=
#### Textos Fundamentales

- {cite:t}`kernighan_c_2014`. Capítulo 5: Pointers and Arrays. El tratamiento
  definitivo de punteros.

- {cite:t}`king_c_2008`. Capítulo 11: Pointers y Capítulo 12: Pointers and
  Arrays.

- {cite:t}`reek_pointers_1997`. Libro entero dedicado a punteros en C.

(punteros-y-arquitectura)=
#### Punteros y Arquitectura

- {cite:t}`bryant_computer_2015`. Capítulo 3: Machine-Level Representation y
  Capítulo 9: Virtual Memory.

- {cite:t}`patterson_computer_2017`. Capítulo 2: Instructions. Instrucciones de
  carga/almacenamiento que usan direcciones.

(gestion-de-memoria-y-errores)=
#### Gestión de Memoria y Errores

- {cite:t}`seacord_secure_2013`. Capítulo 4: Dynamic Memory Management y
  Capítulo 5: Integer Security.

- {cite:t}`van_der_linden_expert_1994`. Capítulo 4: The Shocking Truth: C Arrays
  and Pointers Are NOT the Same!

(4_punteros-recursos-en-linea)=
#### Recursos en Línea

- **C Pointer Tutorial** - https://www.cprogramming.com/tutorial/c/lesson6.html
  - Tutorial progresivo desde básicos hasta avanzados.

- **Pointer Basics** - http://cslibrary.stanford.edu/106/
  - Nick Parlante (Stanford). Documento excelente sobre punteros.

- **C Pointers and Arrays** - https://en.cppreference.com/w/c/language/pointer
  - Referencia técnica completa de la sintaxis de punteros.

(visualizacion-y-debugging)=
#### Visualización y Debugging

- **Python Tutor (C Support)** - https://pythontutor.com/c.html
  - Visualiza paso a paso la ejecución y el estado de los punteros.

- **GDB Tutorial** - https://www.gdbtutorial.com/
  - Depuración de programas con punteros.

- **Valgrind Manual** - https://valgrind.org/docs/manual/mc-manual.html
  - Memcheck: detección de uso incorrecto de punteros.

(articulos-clasicos)=
#### Artículos Clásicos

- {cite:t}`ritchie_development_1993`. Historia de cómo surgieron los punteros en
  C.

- **Hoare, C. A. R. (2009)**. "Null References: The Billion Dollar Mistake".
  Keynote, QCon London.
  - Reflexión sobre punteros nulos y sus consecuencias.
  - Video:
https://www.infoq.com/presentations/Null-References-The-Billion-Dollar-Mistake-Tony-Hoare/

(4_punteros-ejercicios-y-practica)=
#### Ejercicios y Práctica

- **C Puzzles** - http://www.gowrikumar.com/c/
  - Desafíos específicamente sobre punteros y aritmética.

- **LeetCode - Pointer Problems** - https://leetcode.com/tag/two-pointers/
  - Problemas que requieren manipulación hábil de punteros.

## Ejercicios de Autoevaluación

### Introducción y Operadores

:::{exercise}
:label: ej-ptr-declaracion-deref
Escribí un fragmento de código en C que declare una variable entera `var` con el
valor `77` y un puntero `ptr` a dicha variable. Luego, modificá el valor de
`var` asignándole `88` de manera indirecta a través del puntero y verificalo
imprimiendo `var`.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-declaracion-deref
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
int main()
{
    int var = 77;
    int *ptr = &var; // ptr almacena la dirección de var
    *ptr = 88;       // Desreferencia y asigna un nuevo valor en esa celda
    printf("El valor de var es: %d\n", var); // Imprime 88
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-declaracion-deref -->

:::{exercise}
:label: ej-ptr-nulo-seguro
Explicá por qué desreferenciar un puntero que almacena la dirección `NULL` (por
ejemplo, `int *p = NULL; *p = 10;`) genera un fallo de ejecución en sistemas
modernos y escribí un bloque de código defensivo que evite este error.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-nulo-seguro
:class: dropdown
La constante `NULL` representa la dirección de memoria `0x0`. Los sistemas
operativos modernos protegen esta página de direcciones virtuales reservándola
como de acceso no permitido. Si un proceso intenta desreferenciar un puntero
nulo, la MMU de la CPU detecta la infracción y aborta inmediatamente el proceso
enviándole una señal de fallo de segmentación (*Segmentation Fault*).
Para evitarlo, se debe realizar una validación explícita previa:
```{code-block} c
:linenos:
#include <stddef.h>
#include <stdio.h>
void modificar_seguro(int *p)
{
    if (p != NULL)
    {
        *p = 10;
    }
    else
    {
        fprintf(stderr, "Error: Intento de desreferenciar un puntero NULL.\n");
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-nulo-seguro -->

:::{exercise}
:label: ej-ptr-wild-pointer
Definí el concepto de "puntero salvaje" (*wild pointer*), cómo se introduce en
un programa de C y de qué manera la regla de estilo de la cátedra {ref}`0x7001h`
mitiga este riesgo de seguridad.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-wild-pointer
:class: dropdown
Un puntero salvaje es un puntero declarado que no ha sido inicializado a una
dirección válida ni a `NULL`. Al ser una variable automática del stack,
contendrá un valor residual aleatorio (basura) que se interprete como una
dirección de memoria arbitraria. Intentar desreferenciarlo para leer o escribir
puede corromper datos de otras variables en el stack o hacer que el programa
falle de forma impredecible.
La regla de la cátedra {ref}`0x7001h` exige la inicialización obligatoria de
todas las variables en su punto de declaración (asignando una dirección válida o
`NULL`), erradicando la existencia de punteros salvajes.

:::
<!-- {solution} ej-ptr-wild-pointer -->


### Aritmética de Punteros

:::{exercise}
:label: ej-ptr-aritmetica-sizeof
Dado un puntero a reales de doble precisión `double *ptr` que contiene
actualmente la dirección de memoria virtual `0x3000` en una máquina de 64 bits,
calculá la dirección hexadecimal resultante tras evaluar la expresión de
aritmética de punteros `ptr + 3`.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-aritmetica-sizeof
:class: dropdown
La aritmética de punteros escala los desplazamientos según el tamaño físico del
tipo de dato al que apunta:
$$\text{Dirección Resultante} = \text{Dirección Base} + (\text{Desplazamiento}
\times \text{sizeof(tipo)})$$
Sustituyendo los valores:
- Dirección Base = `0x3000`
- Desplazamiento = $3$
- $\text{sizeof(double)} = 8$ bytes
$$\text{Desplazamiento en bytes} = 3 \times 8 = 24\text{ bytes}$$
Convertimos 24 a hexadecimal: $24_{10} = 18_{16}$ (`0x18`). Por lo tanto:
$$\text{Dirección Resultante} = \text{0x3000} + \text{0x0018} = \text{0x3018}$$

:::
<!-- {solution} ej-ptr-aritmetica-sizeof -->

:::{exercise}
:label: ej-ptr-aritmetica-resta
Escribí un programa corto en C que declare un arreglo de enteros `int arr[5]` y
calcule la cantidad de elementos de distancia entre la dirección del último
elemento `&arr[4]` y la dirección del primer elemento `&arr[0]` restando sus
punteros. Mostrá cómo imprimir el resultado de forma portable.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-aritmetica-resta
:class: dropdown
```{code-block} c
:linenos:
#include <stddef.h> // Necesario para ptrdiff_t
#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *inicio = &arr[0];
    int *fin = &arr[4];
    // La resta de punteros devuelve la distancia en elementos de tipo int
    ptrdiff_t distancia = fin - inicio;
    printf("Distancia entre elementos: %td\n", distancia); // Imprime 4
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-aritmetica-resta -->

:::{exercise}
:label: ej-ptr-aritmetica-vla-precedencia
Explicá de forma detallada la diferencia de comportamiento entre las siguientes
dos expresiones de C que combinan el operador de desreferencia y el operador de
incremento:
1. `*ptr++`
2. `(*ptr)++`

:::
<!-- {exercise} -->

:::{solution} ej-ptr-aritmetica-vla-precedencia
:class: dropdown
1. **`*ptr++`**: Debido a que el operador de post-incremento `++` tiene mayor
   precedencia que el operador de desreferencia `*`, el incremento se aplica al
   *puntero* (la dirección). La expresión evalúa al valor almacenado
   originalmente en la dirección apuntada por `ptr` y, como efecto secundario,
   desplaza la dirección de `ptr` al siguiente casillero de memoria.
2. **`(*ptr)++`**: El paréntesis altera el orden de precedencia forzando a que
   se evalúe primero la desreferencia `*ptr`. Por lo tanto, la expresión accede
   al *valor* numérico contenido en la variable a la que apunta `ptr` e
   incrementa ese valor en `1` en la memoria física, dejando la dirección de
   `ptr` inalterada.

:::
<!-- {solution} ej-ptr-aritmetica-vla-precedencia -->


### Funciones, const y Contratos

:::{exercise}
:label: ej-ptr-func-intercambio
Escribí una función pura en C llamada `procesar_datos` que reciba un número
entero `x` por valor, un puntero a entero `entrada_salida` que deba
incrementarse con `x`, y un puntero `salida` en el que se escriba el doble de
`x`. Documentá esta función siguiendo la directiva de la cátedra con
`@param[in]`, `@param[in, out]` y `@param[out]`.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-func-intercambio
:class: dropdown
```{code-block} c
:linenos:
/**
 * @brief Procesa valores numéricos mediante punteros.
 * @param[in] x Valor entero constante a procesar.
 * @param[in, out] entrada_salida Puntero a la variable que acumulará el valor
 * de x.
 * @param[out] salida Puntero donde se escribirá el doble del parámetro x.
 * @pre entrada_salida y salida no deben ser NULL y deben apuntar a memoria
 * válida.
 * @post La variable apuntada por entrada_salida se incrementa en x. La
 * variable apuntada por salida almacena x * 2.
 */
void procesar_datos(int x, int *entrada_salida, int *salida)
{
    if (entrada_salida != NULL && salida != NULL)
    {
        *entrada_salida += x;
        *salida = x * 2;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-func-intercambio -->

:::{exercise}
:label: ej-ptr-const-declaraciones
Escribí las declaraciones de firmas de función correspondientes para los
siguientes tres casos hipotéticos en C, aplicando el calificador `const` donde
corresponda para garantizar máxima robustez del código:
1. Una función `imprimir_mensaje` que reciba una cadena de texto para lectura
   exclusiva.
2. Una función `configurar_puerto` que reciba un puntero constante a un entero
   mutable que representa un registro físico de hardware.
3. Una función `comparar_tablas` que reciba dos punteros constantes a arreglos
   constantes de enteros de lectura exclusiva.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-const-declaraciones
:class: dropdown
Las firmas correspondientes son:
1. `void imprimir_mensaje(const char *mensaje);` (Puntero a datos constantes)
2. `void configurar_puerto(int * const registro);` (Puntero constante a datos
   variables)
3. `void comparar_tablas(const int * const tablaA, const int * const tablaB);`
   (Puntero constante a datos constantes)

:::
<!-- {solution} ej-ptr-const-declaraciones -->

:::{exercise}
:label: ej-ptr-const-diferencia
Analizá el siguiente código en C e indicá en qué línea el compilador arrojará un
error de sintaxis y por qué:
``` c
int x = 10;
int y = 20;
const int *ptr = &x;
ptr = &y;
*ptr = 30;
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-ptr-const-diferencia
:class: dropdown
El error de compilación ocurre en la línea `*ptr = 30;`.
La declaración `const int *ptr` define a `ptr` como un "puntero a entero
constante". Esto significa que el compilador bloquea cualquier intento de
escribir o modificar el valor apuntado a través de dicho puntero. La
reasignación de la dirección del puntero (`ptr = &y;`) es totalmente válida
porque el puntero en sí no es constante.

:::
<!-- {solution} ej-ptr-const-diferencia -->


### Degradación y Indirección Avanzada

:::{exercise}
:label: ej-ptr-decay-sizeof
Explicá de forma rigurosa por qué al declarar un arreglo `int arr[10];` en
`main`, la expresión `sizeof(arr)` devuelve `40` bytes, pero si pasamos ese
arreglo a una función `void procesar(int arr[])`, la llamada a `sizeof(arr)`
dentro de la función devuelve `8` bytes (en una arquitectura de 64 bits).

:::
<!-- {exercise} -->

:::{solution} ej-ptr-decay-sizeof
:class: dropdown
Esto se debe al fenómeno de **degradación de arreglos** (*array decay*):
- En el ámbito donde se declara el arreglo (`main`), el compilador conoce el
  tipo de dato y su tamaño estático completo ($10 \times \text{sizeof(int)} =
  40$ bytes).
- Al pasar el arreglo como parámetro a una función, este decae automáticamente a
  un puntero al primer elemento (`int*`). Por lo tanto, el parámetro formal `int
  arr[]` de la función es interpretado por el compilador exactamente como `int
  *arr`. Al evaluar `sizeof(arr)` dentro de la función, se está calculando el
  tamaño en bytes del tipo puntero, el cual es de 8 bytes en arquitecturas de 64
  bits, perdiendo la dimensión del arreglo.

:::
<!-- {solution} ej-ptr-decay-sizeof -->

:::{exercise}
:label: ej-ptr-doble-indireccion
Implementá un fragmento de código en C que declare una variable entera `numero`
con el valor `500`, un puntero simple `ptr` que apunte a `numero`, y un puntero
doble `ptr_ptr` que apunte a `ptr`. Modificá el valor de `numero` a `999`
utilizando una expresión que involucre al puntero doble `ptr_ptr` e imprimí el
resultado.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-doble-indireccion
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
int main()
{
    int numero = 500;
    int *ptr = &numero;
    int **ptr_ptr = &ptr; // Puntero doble apuntando al puntero simple
    **ptr_ptr = 999; // Doble desreferencia para llegar a la celda de 'numero'
    printf("El valor modificado es: %d\n", numero); // Imprime 999
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-doble-indireccion -->

:::{exercise}
:label: ej-ptr-algoritmo-invertir
Implementá una función llamada `invertir_arreglo` que reciba un arreglo de
enteros y su tamaño, y revierta el orden de sus elementos utilizando
exclusivamente aritmética de punteros con un puntero `izq` inicializado al
primer elemento y otro `der` inicializado al último.

:::
<!-- {exercise} -->

:::{solution} ej-ptr-algoritmo-invertir
:class: dropdown
```{code-block} c
:linenos:
#include <stddef.h>
void invertir_arreglo(int *arr, size_t tamano)
{
    if (arr == NULL || tamano <= 1)
    {
        return;
    }
    int *izq = arr;
    int *der = arr + tamano - 1; // Dirección del último elemento
    while (izq < der)
    {
        // Intercambio de valores desreferenciados
        int temporal = *izq;
        *izq = *der;
        *der = temporal;
        // Desplazamiento de los punteros hacia el centro
        izq++;
        der--;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ptr-algoritmo-invertir -->



## Glosario

::::{glossary}

Puntero
: Variable que almacena la dirección de memoria de otra variable.

Desreferenciación
: Operación (`*`) que permite acceder o modificar el valor almacenado en la
dirección apuntada.

Degradación de arreglos (array decay)
: Pérdida del tamaño de un arreglo al ser pasado a una función, convirtiéndose
en un puntero simple a su primer elemento.

Efecto secundario (side effect)
: Modificación de variables o estado fuera del ámbito local de una función.

::::
<!-- {glossary} -->

## Síntesis y Resumen

Este apunte desmitifica los **punteros**, el concepto más distintivo y poderoso
de C, revelando su naturaleza como simples variables que almacenan direcciones
de memoria.

:::{important} Ideas Centrales

**Punteros como Direcciones**
- Un puntero es una variable que almacena la dirección de memoria de otra
  variable
- Declaración: `int *p` declara un puntero a entero
- Operador `&`: obtiene la dirección de una variable
- Operador `*`: desreferencia un puntero para acceder/modificar el valor
  apuntado

**Relación Punteros-Arreglos**
- Un arreglo decae a un puntero al primer elemento en la mayoría de contextos
- `arr[i]` es equivalente a `*(arr + i)` (notación puntero)
- Aritmética de punteros: sumar $n$ a un puntero avanza $n \times
  \text{sizeof(tipo)}$ bytes
- Esta equivalencia explica por qué los arreglos se pasan por dirección

**Punteros y Funciones**
- Paso por referencia simulado: pasar `&variable` permite que la función la
  modifique
- Los arreglos siempre se pasan como punteros (por eso las modificaciones
  persisten)
- Punteros permiten que funciones "retornen" múltiples valores via parámetros

**Punteros a Punteros**
- `int **pp`: puntero a puntero a entero
- Útil para matrices dinámicas y estructuras complejas
- Cada nivel de indirección agrega una desreferencia

**Seguridad y Errores Comunes**
- **Punteros no inicializados**: contienen "basura", desreferenciarlos es
  undefined behavior
- **Punteros nulos**: `NULL` representa dirección inválida, siempre verificar
  antes de usar
- **Dangling pointers**: punteros que apuntan a memoria ya liberada o fuera de
  scope
- **Desbordamiento**: acceder más allá de los límites de un arreglo via punteros

:::
<!-- {important} Ideas Centrales -->

(referencias-lecturas-punteros)=
## Referencias y Lecturas Complementarias

- **Kernighan, B. W. y Ritchie, D. M.** [@kernighan_c_2014]. *The C Programming
  Language* (2.ª edición). Prentice Hall.
  - Consultá el **Capítulo 5: Pointers and Arrays**, que provee la explicación
    clásica e histórica del modelo de punteros en C, la equivalencia entre
    arreglos y punteros, y la manipulación de memoria de bajo nivel.
- **King, K. N.** [@king_c_2008]. *C Programming: A Modern Approach* (2.ª
  edición). W. W. Norton & Company.
  - Revisá el **Capítulo 11: Pointers** para una introducción didáctica paso a
    paso de las direcciones de memoria y los parámetros de salida, y el
    **Capítulo 12: Pointers and Arrays** para el desglose detallado de la
    aritmética de punteros.
- **Gustedt, J.** [@gustedt_modern_2019]. *Modern C*. Manning Publications.
  - Estudiá el **Nivel 2 (Refine)**, en especial las secciones de punteros y
    estado de los objetos, que analizan en profundidad la seguridad del tipado,
    el puntero `NULL` y los problemas asociados al ciclo de vida de los datos.
- **Sommers, J.** [@sommers_jsommers/cbook_2025]. *jsommers/cbook*.
  - Consultá los capítulos sobre punteros y direccionamiento de memoria para
    explicaciones prácticas sobre el modelo mental de almacenamiento y
    desreferencia de variables.
