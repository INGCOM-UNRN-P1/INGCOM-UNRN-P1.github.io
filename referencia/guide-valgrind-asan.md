---
title: Diagnóstico de Memoria Dinámica con Valgrind y AddressSanitizer
short_title: Guía Valgrind / ASan
subtitle: Manual de referencia sobre detección, análisis y resolución de fugas de memoria y accesos inválidos en lenguaje C
---

## Introducción

La gestión manual de memoria en C permite optimizar el uso de recursos, pero
introduce el riesgo de errores complejos de detectar como fugas de memoria
(*memory leaks*), accesos fuera de límites (*buffer overflows*), desreferencia
de punteros liberados (*use-after-free*) y lecturas de memoria no inicializada.

Para garantizar la estabilidad y seguridad de las aplicaciones, existen dos
herramientas fundamentales en la industria y el ámbito académico:

1. **Valgrind (Memcheck)**: Un entorno de simulación que analiza el ejecutable
   en tiempo de ejecución mediante instrumentación binaria sin necesidad de
   recompilar el fuente.
2. **AddressSanitizer (ASan)**: Un instrumentalizador integrado directamente en
   los compiladores `gcc` y `clang` que inserta chequeos en el código objeto,
   ofreciendo ejecuciones a velocidad casi nativa e informes de error
   detallados.

---

## Comparativa Técnica: Valgrind vs. AddressSanitizer

| Característica | Valgrind (Memcheck) | AddressSanitizer (ASan) |
| :--- | :--- | :--- |
| **Mecanismo** | Traducción dinámica de código binario. | Instrumentalización en tiempo de compilación. |
| **Recompilación** | No requerida (se recomienda `-g`). | Requerida (`-fsanitize=address -g`). |
| **Penalización de Velocidad** | 20x a 50x más lento. | 2x a 3x más lento (apto para pruebas complejas). |
| **Detección de Stack Overflow** | Limitada. | Excelente (detecta límites en Stack y Globales). |
| **Uso de Memoria** | Moderado a alto. | Requiere espacio de sombra (*shadow memory*). |

---

## Valgrind: Manual de Uso e Interpretación

### Compilación y Lanzamiento

Para obtener números de línea exactos en los reportes de Valgrind, se debe
compilar el programa con símbolos de depuración (`-g`):

``` bash
gcc -g -Wall -Wextra -std=c99 main.c -o programa
```
<!-- bash -->

La invocación estándar recomendada para análisis completo de memoria es:

``` bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./programa
```
<!-- bash -->

#### Banderas Principales de Valgrind

* `--leak-check=full`: Realiza un análisis exhaustivo mostrando el bloque de
  código exacto donde se asignó cada bloque no liberado.
* `--show-leak-kinds=all`: Clasifica y detalla todos los tipos de fugas
  (`definitely lost`, `indirectly lost`, `possibly lost`, `still reachable`).
* `--track-origins=yes`: Rastrea el origen exacto de valores y variables no
  inicializados (incurre en una leve penalización adicional de rendimiento).
* `--log-file=valgrind_report.txt`: Redirige la salida de Valgrind a un archivo
  de texto plano en lugar de la consola.

---

### Clasificación de Fugas de Memoria en Valgrind

Valgrind clasifica la memoria no liberada en cuatro categorías principales
dentro del bloque `LEAK SUMMARY`:

``` text
==12345== LEAK SUMMARY:
==12345==    definitely lost: 64 bytes in 1 blocks
==12345==    indirectly lost: 32 bytes in 1 blocks
==12345==    possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 128 bytes in 2 blocks
```
<!-- text -->

1. **`definitely lost` (Definitivamente perdida)**:
   * *Diagnóstico*: Memoria reservada con `malloc`/`calloc`/`realloc` para la
     cual **ya no existe ningún puntero** que apunte a ella (ni al inicio ni al
     interior del bloque). Debe corregirse invocando `free()`.
2. **`indirectly lost` (Indirectamente perdida)**:
   * *Diagnóstico*: Ocurre en estructuras complejas (listas enlazadas, árboles,
     grafos). Ocurre cuando se pierde el puntero al nodo raíz/cabeza, haciendo
     que los nodos hijos queden inaccesibles aunque sus punteros internos sigan
     existiendo.
3. **`possibly lost` (Posiblemente perdida)**:
   * *Diagnóstico*: Todavía existen punteros apuntando al interior del bloque de
     memoria, pero no al inicio. A menudo sucede al realizar aritmética de
     punteros.
4. **`still reachable` (Todavía alcanzable)**:
   * *Diagnóstico*: El programa finalizó sin liberar estos bloques, pero al
     momento de la salida **todavía existían punteros válidos** apuntando a
     ellos. Ocurre con frecuencia si se confía en que el sistema operativo
     liberará la memoria al terminar el proceso. En buenas prácticas de C, debe
     ser 0.

---

### Análisis de Errores Comunes en Valgrind

#### 1. Lectura / Escritura Inválida (`Invalid read / Invalid write`)

Ocurre cuando el programa intenta leer o escribir en una dirección de memoria
fuera de los límites asignados o en un bloque ya liberado.

``` text
==12345== Invalid write of size 4
==12345==    at 0x401142: main (main.c:15)
==12345==  Address 0x5204044 is 0 bytes after a block of size 40 alloc'd
==12345==    at 0x401110: main (main.c:10)
```
<!-- text -->

* *Lectura del Reporte*: En la línea 15 de `main.c`, se intentó escribir 4 bytes
  (un `int`) justo 0 bytes después del final de un bloque de 40 bytes (reservado
  en la línea 10).
* *Causa*: Desbordamiento de arreglo (*out-of-bounds* / *off-by-one*).

#### 2. Salto Condicional Dependiente de Valor No Inicializado

``` text
==12345== Conditional jump or move depends on uninitialised value(s)
==12345==    at 0x401178: procesar (main.c:22)
==12345==  Uninitialised value was created by a stack allocation
==12345==    at 0x401150: main (main.c:18)
```
<!-- text -->

* *Lectura del Reporte*: Se evaluó una estructura condicional (`if`, `while`)
  utilizando el valor de una variable creada en la pila en `main.c:18` a la que
  nunca se le asignó un valor inicial.

#### 3. Liberación Inválida o Doble Liberación (`Invalid free / Double free`)

```{code-block} text
:linenos:
==12345== Invalid free() / delete / delete[] / realloc()
==12345==    at 0x4c30d3b: free (vg_replace_malloc.c:540)
==12345==    by 0x4011A5: liberar_nodo (main.c:30)
==12345==  Address 0x5204040 is 0 bytes inside a block of size 40 free'd
==12345==    at 0x4c30d3b: free (vg_replace_malloc.c:540)
==12345==    by 0x401180: liberar_nodo (main.c:28)

```
<!-- {code-block} text -->

* *Diagnóstico*: Se intentó ejecutar `free()` sobre una dirección que ya había
  sido liberada previamente en la línea 28.

---

## AddressSanitizer (ASan): Manual de Uso e Interpretación

AddressSanitizer está integrado directamente en el compilador. Modifica las
instrucciones de acceso a memoria y administra una región de memoria "sombra"
(*shadow memory*) para registrar qué bytes son válidos para lectura/escritura.

### Compilación con ASan

Para compilar con ASan es indispensable incluir las banderas
`-fsanitize=address` y `-g`:

``` bash
gcc -fsanitize=address -g -Wall -Wextra -std=c99 main.c -o programa_asan
```
<!-- bash -->

:::{note}

Para detectar fugas de memoria en entornos Linux, ASan activa automáticamente
**LSan (LeakSanitizer)** al finalizar la ejecución del programa.

:::
<!-- {note} -->

---

### Análisis de Reportes Comunes en AddressSanitizer

Al ocurrir un fallo de memoria, ASan interrumpe inmediatamente la ejecución del
programa y emite un informe estructurado en color por consola.

#### 1. Heap-Buffer-Overflow (Desbordamiento en el Heap)

```{code-block} text
:linenos:
=================================================================
==54321==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000028 at pc 0x000000401290 bp 0x7fff5fbff700 sp 0x7fff5fbff6f8
WRITE of size 4 at 0x602000000028 thread T0
    #0 0x40128f in main /proyecto/main.c:14
allocated by thread T0 here:
    #0 0x7f9999 in malloc (/lib64/libasan.so.5+0xedab0)
    #1 0x4011fe in main /proyecto/main.c:10

```
<!-- {code-block} text -->

* *Explicación*: Se realizó un acceso de escritura (`WRITE`) no permitido fuera
  de los límites de un bloque asignado con `malloc` en `main.c:10`. La
  infracción ocurrió exactamente en `main.c:14`.

#### 2. Stack-Buffer-Overflow (Desbordamiento en la Pila)

A diferencia de Valgrind, ASan detecta accesos fuera de rango en arreglos
locales declarados en la pila:

``` text
=================================================================
==54321==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffe00112230 at pc 0x0000004011c0 bp 0x7ffe00112200 sp 0x7ffe001121f8
WRITE of size 1 at 0x7ffe00112230 thread T0
    #0 0x4011bf in funcion_auxiliar /proyecto/main.c:8
```
<!-- text -->

* *Explicación*: Se escribió más allá del tamaño reservado para un arreglo local
  dentro de `funcion_auxiliar`.

#### 3. Heap-Use-After-Free (Uso de Memoria Liberada)

```{code-block} text
:linenos:
=================================================================
==54321==ERROR: AddressSanitizer: heap-use-after-free on address 0x602000000010 at pc 0x000000401234 bp 0x7fff5fbff700 sp 0x7fff5fbff6f8
READ of size 4 at 0x602000000010 thread T0
    #0 0x401233 in main /proyecto/main.c:20
freed by thread T0 here:
    #0 0x7f9999 in free (/lib64/libasan.so.5+0xedab0)
    #1 0x4011fe in main /proyecto/main.c:16
previously allocated by thread T0 here:
    #0 0x7f9999 in malloc (/lib64/libasan.so.5+0xedab0)
    #1 0x401100 in main /proyecto/main.c:12

```
<!-- {code-block} text -->

* *Explicación*: El reporte indica la secuencia cronológica completa:
  1. Dónde se asignó la memoria (`main.c:12`).
  2. Dónde se liberó con `free()` (`main.c:16`).
  3. Dónde se intentó volver a leer (`READ`) la memoria ya liberada
     (`main.c:20`).

---

## Patrones de Código Correcto y Estrategias de Prevención

Para asegurar la ausencia de fugas y accesos inválidos, se deben aplicar los
siguientes patrones de diseño en C:

### 1. El Patrón Asignación-Liberación Simétrica

Todo bloque reservado con `malloc` o `calloc` debe poseer una única
responsabilidad de liberación claramente delimitada.

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>

void procesar_datos(void) {
    int *arreglo = malloc(10 * sizeof(*arreglo));
    if (arreglo == NULL) {
        return; /* Manejo de error de asignación */
    }

    /* Uso del arreglo */
    for (int i = 0; i < 10; i++) {
        arreglo[i] = i * 2;
    }

    /* Liberación garantizada antes de salir */
    free(arreglo);
}

```
<!-- {code-block} c -->

### 2. Punteros Dangled y Anulación Post-Free

Para prevenir el fallo *Use-After-Free* y la *Doble Liberación*, se debe asignar
inmediatamente `NULL` a todo puntero liberado:

``` c
free(ptr);
ptr = NULL; /* Al asignar NULL, invocaciones posteriores a free(ptr) son inocuas */
```
<!-- c -->

### 3. Liberación Recursiva de Estructuras Dinámicas (Listas Enlazadas)

En estructuras enlazadas, liberar el puntero cabeza antes que los nodos hijos
genera la fuga `indirectly lost`. La secuencia correcta debe resguardar el
puntero al siguiente nodo antes de liberar el actual:

```{code-block} c
:linenos:
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

void lista_destruir(nodo_t *cabeza) {
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        nodo_t *siguiente = actual->siguiente; /* Resguardo del puntero */
        free(actual);
        actual = siguiente;
    }
}

```
<!-- {code-block} c -->

---

## Resumen de Comandos de Diagnóstico Rápido

| Objetivo | Comando |
| :--- | :--- |
| **Compilar para Valgrind** | `gcc -g -Wall -Wextra -std=c99 main.c -o programa` |
| **Ejecutar Valgrind Completo** | `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./programa` |
| **Compilar con AddressSanitizer** | `gcc -fsanitize=address -g -Wall -Wextra -std=c99 main.c -o programa_asan` |
| **Ejecutar con ASan** | `./programa_asan` |
