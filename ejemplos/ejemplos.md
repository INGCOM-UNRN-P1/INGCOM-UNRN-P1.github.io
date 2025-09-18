---
title: Ejemplos
short_title: ejemplos
subtitle: Ejemplos de las cuestiones vistas
---

## Archivos

### [`archivo/archivos.c`](archivo/archivos.c)

Este ejemplo muestra cómo abrir y leer un archivo carácter por carácter. Además, demuestra el uso de `perror` y `errno` para un manejo robusto de archivos.

### [`archivo/archivos1.c`](archivo/archivos1.c)

Este ejemplo demuestra cómo abrir un archivo en modo escritura, interactuando con el usuario para recibir datos. Incluye un manejo de errores para `fopen`, mostrando cómo asegurar que el archivo se abra correctamente.

### [`archivo/archivos2.c`](archivo/archivos2.c)

Este ejemplo ilustra el comportamiento del sistema de archivos al intentar escribir en un archivo de solo lectura. Demuestra cómo `errno` y `strerror` pueden usarse para obtener información detallada sobre el estado de las operaciones.

### [`archivo/archivos3.c`](archivo/archivos3.c)

Este ejemplo abre un archivo en modo escritura y escribe un mensaje en él. Incluye manejo de errores tanto para la apertura como para la escritura en el archivo.

## Argumentos

### [`args/argumentos_base.c`](args/argumentos_base.c)

Este es un ejemplo básico de cómo acceder a los argumentos de la línea de comandos. Itera sobre `argv` y muestra cada argumento.

### [`args/argumentos.c`](args/argumentos.c)

Un ejemplo más avanzado de manejo de argumentos. Muestra cómo convertir un argumento de cadena a un número usando `strtol`, e incluye validación de la conversión. También demuestra una función `implacable` que procesa una cadena.

### [`args/bandera.c`](args/bandera.c)

Este ejemplo muestra cómo implementar una bandera simple, en este caso `--help`. El programa revisa los argumentos y si encuentra `--help`, muestra un mensaje de ayuda y termina.

### [`args/environ.c`](args/environ.c)

Este ejemplo enseña cómo acceder a las variables de entorno del sistema. Itera sobre el arreglo `envp` y muestra todas las variables de entorno.

### [`args/muestra.c`](args/muestra.c)

Un ejemplo simple que muestra el número total de argumentos pasados al programa y luego los lista.

## Varios

### [`verificacion.c`](verificacion.c)

Este ejemplo contiene una función para sumar la diagonal principal de una matriz cuadrada. La función `sumar_diagonal_principal` toma una matriz y su dimensión como entrada y devuelve la suma de los elementos de la diagonal.

## Arreglos

### [`args/numeros.c`](args/numeros.c)

Este ejemplo toma dos números como argumentos de línea de comandos, los convierte a enteros usando `atoi`, los suma y muestra el resultado. Incluye manejo de errores para la cantidad de argumentos.

### [`arreglos/alv.c`](arreglos/alv.c) y [`arreglos/alv_2.c`](arreglos/alv_2.c)

Estos ejemplos muestran el uso de "Arreglos de Longitud Variable" (Variable Length Arrays o VLAs), una característica de C99. El tamaño del arreglo se determina en tiempo de ejecución a partir de la entrada del usuario. Luego, imprime el tamaño del arreglo en bytes.

### [`arreglos/arreglo_size.c`](arreglos/arreglo_size.c) y [`arreglos/cadenas.c`](arreglos/cadenas.c)

Estos ejemplos muestran una función que ordena una cadena de caracteres alfabéticamente. La función `ordena_caracteres` toma un arreglo de caracteres y lo ordena en el lugar. El `main` demuestra cómo usar la función y también explora el comportamiento al pasar un literal de cadena a una función que lo modifica. TODO: REVISAR

### [`arreglos/decay.c`](arreglos/decay.c)

Este ejemplo ilustra el concepto de "degradación de arreglos" (array decay). Cuando un arreglo se pasa a una función, se "degrada" a un puntero al primer elemento. Esto significa que `sizeof` dentro de la función devuelve el tamaño de un puntero, no el tamaño total del arreglo.

### [`arreglos/degradacion.c`](arreglos/degradacion.c)

Otro ejemplo de degradación de arreglos. La función `generador` recibe un arreglo de caracteres y al imprimir su `sizeof` se observa que es el tamaño de un puntero. La función modifica el primer carácter del arreglo, demostrando que el cambio se refleja en el `main`.

### [`arreglos/imprimidor.c`](arreglos/imprimidor.c)

Este ejemplo muestra una función `imprimidor` que imprime los caracteres de una cadena junto con su índice, hasta que encuentra el carácter nulo.

### [`arreglos/limites.c`](arreglos/limites.c)

Este ejemplo explora el comportamiento de los arreglos cuando se accede a índices fuera de sus límites definidos. El bucle `for` itera más allá del tamaño del arreglo para mostrar la importancia de un manejo cuidadoso de los límites. TODO: REVISAR

### [`arreglos/side.c`](arreglos/side.c)

Este ejemplo presenta una función `maximo` que, además de encontrar el valor máximo en un arreglo, utiliza el primer elemento del mismo para almacenar dicho máximo. El `main` muestra el estado del arreglo antes y después de la llamada para ilustrar este interesante efecto secundario.

### [`arreglos/size_of.c`](arreglos/size_of.c)

Este ejemplo imprime el tamaño en bytes de varios tipos de datos fundamentales en C: `char`, `int`, `float`, `double` y `long long`. Es útil para entender cómo se almacena cada tipo en la memoria.

## Base

### [`base/for.c`](base/for.c)

Este archivo muestra cuatro ejemplos diferentes de bucles `for`: un bucle básico, un bucle con múltiples variables de control, un bucle `for` sin cuerpo y un bucle infinito con una condición de ruptura.

### [`base/hola.c`](base/hola.c)

El clásico "Hola Mundo" en C. Simplemente imprime "Hola mundo C." en la consola.

### [`base/main.c`](base/main.c)

Otro "Hola Mundo", pero este muestra el uso de las macros `EXIT_SUCCESS` y `EXIT_FAILURE` para los valores de retorno de `main`.

## Benchmark

### [`benchmark.c`](benchmark.c)

Este es un programa de benchmark simple. Realiza un cálculo intensivo en un bucle anidado para medir el rendimiento. Toma un número de la línea de comandos y lo usa en los cálculos.

## Cadenas

### [`cadenas/cadenas.c`](cadenas/cadenas.c)

Este archivo contiene varios fragmentos de código que operan sobre cadenas y arreglos. Cuenta las ocurrencias de un carácter en una cadena, modifica un arreglo de enteros y demuestra el resultado de una asignación dentro de una condición `if`.

## Compilación

### [`compilacion/hola.c`](compilacion/hola.c)

Una versión modificada de "Hola Mundo" donde la llamada a `printf` está comentada. Se utiliza para mostrar cómo el compilador puede generar un ejecutable que realiza operaciones internas sin producir salida visible.

### [`compilacion/maradona.c`](compilacion/maradona.c)

Un ejemplo de código ofuscado en C. Usa macros `#define` para reemplazar palabras clave de C con la letra "e" repetida, mostrando las capacidades del preprocesador de una forma creativa.

### [`compilacion/preproc.c`](compilacion/preproc.c)

Este archivo muestra la salida del preprocesador de C. Las directivas `#` al principio indican el archivo original y el número de línea.

## Construcción

### [`construccion/hola.c`](construccion/hola.c)

Otro "Hola Mundo", probablemente utilizado en conjunto con un `Makefile` para demostrar el proceso de construcción.

## Memoria Dinámica

### [`dyn/maloco.c`](dyn/maloco.c)

Este ejemplo muestra el uso de `calloc` y `realloc` para manejar memoria dinámica. Se reserva memoria para un arreglo, se rellena con valores, se imprime, y luego se redimensiona con `realloc` a un tamaño mayor y menor.

### [`dyn/reloco.c`](dyn/reloco.c)

Este ejemplo contiene varias demostraciones sobre el manejo de memoria. Incluye un bucle que explora la escritura en la memoria, una función recursiva para observar el comportamiento de la pila, y un bloque que demuestra el uso de `malloc`, `memcpy` y `memset`. TODO: REVISAR

### [`dyn/void.c`](dyn/void.c)

Este ejemplo demuestra el uso de punteros `void` con `malloc` para una gestión de memoria genérica. Ilustra cómo se puede reservar memoria, convertirla a un tipo específico para su uso, y explora el comportamiento de `free` al ser llamado con un puntero desplazado. TODO: REVISAR

## Punteros a Funciones

### [`fun_ptr/puntero.c`](fun_ptr/puntero.c)

Un ejemplo de punteros a funciones. Define un tipo `f_operacion_t` para un puntero a una función que toma dos enteros y devuelve un entero. La función `selectora` devuelve un puntero a `suma` o `resta` según el carácter de entrada.

### [`fun_ptr/puntero2.c`](fun_ptr/puntero2.c)

Un ejemplo más simple de puntero a función. Un puntero a función se asigna directamente a la dirección de la función `resta` y luego se usa para llamar a la función.

### [`fun_ptr/qsort.c`](fun_ptr/qsort.c)

Este ejemplo muestra cómo usar la función `qsort` de la biblioteca estándar para ordenar un arreglo. Se definen dos funciones de comparación, `compara_menor_mayor` y `compara_mayor_menor`, que se pasan a `qsort` para controlar el orden.

### [`fun_ptr/senales.c`](fun_ptr/senales.c)

Este ejemplo demuestra el manejo de señales en C. La función `signal` se usa para registrar un "manejador" (`handler`) para la señal `SIGUSR1`. El programa entra en un bucle infinito y cuando recibe la señal `SIGUSR1`, se ejecuta el manejador.

## Funciones

### [`funciones/estatico.c`](funciones/estatico.c)

Este ejemplo ilustra el uso de variables estáticas dentro de una función. La variable `veces` se declara como `static`, por lo que conserva su valor entre llamadas a la función `incremento`.

## Make

### [`make_base/main.c`](make_base/main.c)

Un "Hola Mundo" simple, probablemente parte de un ejemplo básico de `Makefile`.

### [`make_mid/funciones.c`](make_mid/funciones.c)

Una función `saludar` simple, diseñada para ser compilada por separado y enlazada con un `main` como parte de un ejemplo de `Makefile` de complejidad media.

### [`make_mid/main.c`](make_mid/main.c)

El `main` correspondiente a `make_mid/funciones.c`. Incluye `funciones.h` y llama a la función `saludar`.

### [`make_tp/ejercicio.c`](make_tp/ejercicio.c)

Contiene la función `suma_lenta`, que suma dos números usando bucles `while` en lugar del operador `+`. Es parte de un ejemplo de `Makefile` para un trabajo práctico.

### [`make_tp/main.c`](make_tp/main.c)

El `main` para el ejemplo del trabajo práctico. Llama a `suma_lenta` con diferentes valores para probar su funcionamiento.

### [`make_tp/prueba.c`](make_tp/prueba.c)

Otro `main` para el trabajo práctico, que llama a `suma_lenta` con un solo par de valores.

## Matrices

### [`matrices/aritmetica.c`](matrices/aritmetica.c)

Este ejemplo muestra cómo acceder a los elementos de una matriz utilizando aritmética de punteros en lugar de la sintaxis de corchetes `[][]`.

### [`matrices/matri.c`](matrices/matri.c)

Un ejemplo simple que inicializa una matriz de 3x3 con valores del 0 al 8 y luego la imprime en la consola.

### [`matrices/matrix_1.c`](matrices/matrix_1.c)

Este ejemplo define una función `imprimir_matriz` que toma una matriz como argumento. Para que funcione, el tamaño de la columna debe ser una constante de preprocesador.

### [`matrices/matrix_2.c`](matrices/matrix_2.c)

Similar a `matrix_1.c`, pero la función `imprimir_matriz` toma el número de columnas como un argumento, lo que es una característica de C99 (arreglos de longitud variable). También muestra una forma alternativa de imprimir la matriz tratándola como un solo arreglo unidimensional.

### [`matrices/sizes.c`](matrices/sizes.c)

Este ejemplo demuestra cómo calcular el número de filas, columnas y elementos totales de una matriz utilizando el operador `sizeof`.

## Memoria

### [`memoria/nuke.c`](memoria/nuke.c)

Este programa demuestra el efecto de la asignación continua de memoria en un bucle. En cada iteración, duplica la cantidad de memoria reservada con `malloc`, mostrando cómo se puede consumir la memoria disponible del sistema.

### [`memoria/stack.c`](memoria/stack.c)

Este ejemplo explora el ciclo de vida de las variables en la pila (stack). La `funcionA` muestra lo que sucede al devolver un puntero a una variable local. Las otras funciones, `funcionB`, `funcionC` y `funcionD`, ilustran el estado de las variables locales no inicializadas. TODO: REVISAR

### [`memoria/stack_2.c`](memoria/stack_2.c)

Este ejemplo explora el uso de variables locales en la pila. Las funciones `func_1` y `func_2` utilizan variables locales en sus cálculos para mostrar cómo el estado de la pila puede influir en los resultados. TODO: REVISAR

## Código Ofuscado

### [`ofuscado/donut.c`](ofuscado/donut.c)

Un ejemplo clásico de código ofuscado. Este programa, a pesar de su apariencia confusa, genera una animación de un donut girando en 3D en la terminal.

### [`ofuscado/donut2.c`](ofuscado/donut2.c)

Otra versión del donut en C, aún más ofuscada y con algunas características adicionales.

## Preprocesador

### [`preprocesador/definir.c`](preprocesador/definir.c)

Este ejemplo muestra el uso de las directivas de preprocesador `#define` y `#ifndef`. Define una constante `MAXIMUS` y luego define `MAX` solo si no ha sido definido antes.

### [`preprocesador/loop.c`](preprocesador/loop.c)

Un ejemplo simple de un bucle que suma los elementos de un arreglo. Se usa para demostrar la diferencia en el código ensamblador generado con y sin optimizaciones del compilador.

### [`preprocesador/optimiza.c`](preprocesador/optimiza.c)

Este ejemplo demuestra el concepto de código inalcanzable. La función `suma` tiene una sentencia `printf` después de la declaración `return`, mostrando que cualquier código después de un `return` en una función no será ejecutado.

### [`preprocesador/proyecto/main.c`](preprocesador/proyecto/main.c), [`preprocesador/proyecto/matematicas.c`](preprocesador/proyecto/matematicas.c) y [`preprocesador/separado.c`](preprocesador/separado.c)

Estos archivos demuestran la importancia de las guardas de inclusión en los archivos de cabecera. Incluyen `guarda.h` (que tiene guardas) y `sin_guarda.h` (que no las tiene) dos veces, lo que permite observar cómo las guardas previenen errores de doble inclusión.

## Punteros

### [`punteros/give.c`](punteros/give.c) y [`punteros/give2.c`](punteros/give2.c)

Estos ejemplos muestran una técnica para "esconder" una cadena de texto dentro de números enteros de 64 bits. Luego, al convertir la dirección de las variables a un puntero a `char`, se puede imprimir la cadena.

### [`punteros/indirecto.c`](punteros/indirecto.c)

Este ejemplo demuestra el uso de punteros dobles para modificar punteros en una función. La función `indirecto` toma dos punteros dobles y hace que el primero apunte a lo que apunta el segundo.

### [`punteros/mazazo.c`](punteros/mazazo.c)

Este ejemplo explora el acceso a la memoria más allá de los límites reservados con `malloc`. Se reserva un solo byte y luego se itera mucho más allá de ese límite para observar el comportamiento del programa en esta situación. TODO: REVISAR

### [`punteros/ptr.c`](punteros/ptr.c)

Un ejemplo simple de punteros. Muestra cómo declarar un puntero, asignarle la dirección de una variable y cómo modificar el valor de la variable a través del puntero.

### [`punteros/puntero.c`](punteros/puntero.c)

Este ejemplo muestra la declaración de un puntero constante a un entero constante. Ni el puntero ni el valor al que apunta pueden ser modificados. También ilustra la degradación de arreglos.

### [`punteros/swap_generico.c`](punteros/swap_generico.c)

Este ejemplo contiene una función `swap` genérica que puede intercambiar los valores de dos variables de cualquier tipo. Usa `memcpy` y `malloc` para realizar el intercambio. El `main` de este archivo parece no estar relacionado y muestra el alcance de las variables. TODO: REVISAR

## Recursividad

### [`recursividad/ackermann.c`](recursividad/ackermann.c)

Implementación de la función de Ackermann, un ejemplo clásico de una función recursiva que no es primitivamente recursiva. Crece muy rápidamente y es una excelente manera de observar el comportamiento de la pila con recursividad profunda.

### [`recursividad/ejemplo.c`](recursividad/ejemplo.c)

Una función recursiva simple que calcula la suma de los números desde `valor` hasta 1. Imprime mensajes para mostrar el flujo de la recursividad.

### [`recursividad/factorial.c`](recursividad/factorial.c)

Una implementación recursiva de la función factorial.

### [`recursividad/fibonacci.c`](recursividad/fibonacci.c)

Una implementación recursiva para calcular un término de la secuencia de Fibonacci. Es útil para analizar la complejidad y eficiencia de los algoritmos recursivos.

### [`recursividad/suma.c`](recursividad/suma.c)

Contiene dos funciones recursivas: `factorial` y `suma`. El `main` solo usa `factorial`. La función `suma` calcula la suma de los números desde `n` hasta 1 e imprime el flujo de la recursión.

## Ámbito (Scope)

### [`scopes/scopes.c`](scopes/scopes.c)

Este ejemplo muestra cómo las variables declaradas dentro de bloques `{}` tienen un ámbito local a ese bloque. También ilustra el estado de una variable no inicializada.

### [`scopes/scopes_2.c`](scopes/scopes_2.c)

Un ejemplo más complejo de ámbito de variables, que involucra variables globales, locales y estáticas. Muestra cómo el compilador resuelve a qué variable se refiere cada nombre según el ámbito.

### [`scopes/scoping.c`](scopes/scoping.c)

Este ejemplo ilustra el "ocultamiento de nombres" (name hiding). Dentro del bucle `for`, se declara una nueva variable `a` que oculta la `a` del ámbito exterior.

## Estructuras

### [`structs/segura_struct.c`](structs/segura_struct.c)

Este ejemplo define una estructura `cadena_t` para manejar cadenas de forma más segura, almacenando la capacidad junto con el puntero a los datos. También muestra el uso de `enum` para definir tipos enumerados.

## Comportamiento Indefinido

### [`undefinido/side_effects.c`](undefinido/side_effects.c)

Este ejemplo demuestra el concepto de código inalcanzable. La función `suma` tiene una sentencia `printf` después de la declaración `return`, mostrando que cualquier código después de un `return` en una función no será ejecutado.

### [`undefinido/stack2.c`](undefinido/stack2.c)

Similar a `memoria/stack.c`, este ejemplo explora el resultado de devolver un puntero a una variable local. La función `puntero_a_cadena` devuelve un puntero a un arreglo en la pila, ilustrando el ciclo de vida de la memoria de la pila. TODO: REVISAR
