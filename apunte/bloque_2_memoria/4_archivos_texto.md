---
title: 'Archivos de Texto'
short_title: Archivos (de texto)
description: 'Apertura, lectura, escritura y control de errores al trabajar con archivos de texto.'
---

> **Prerrequisitos**: cadenas, funciones, control de errores y terminal.
>
> **Objetivos**: 1. Abrir, leer o escribir un archivo de texto comprobando errores. 2. Cerrar cada `FILE *` adquirido.
>
> **Comprobación de salida**: enumerá los caminos de salida de un programa y verificá que todos cierren el archivo abierto.

(trabajando-con-archivos-de-texto-en-c)=
# Trabajando con archivos (de texto) en C

El manejo de archivos es una capacidad fundamental en la mayoría de las
aplicaciones. En C, la librería estándar de E/S (`stdio.h`) provee un conjunto
robusto y de bajo nivel para interactuar con el sistema de archivos. Este apunte
amplía el manejo de archivos de texto, cubriendo no solo las operaciones básicas
sino también el posicionamiento dentro del archivo y, de manera crucial, una
gestión de errores detallada y profesional.

:::{figure} 4/file_operations_flow.svg
:name: fig-file-operations-flow
:alt: Flujo completo de operaciones con archivos
:align: center
:width: 85%

Ciclo de vida físico en el manejo de archivos: Apertura, Operación y Cierre.

:::
<!-- {figure} 4/file_operations_flow.svg -->

## Desarrollo

(el-file-la-conexion-con-el-archivo)=
### El `FILE`, la conexión con el archivo


Toda operación sobre archivos en C se realiza a través de un puntero a una
estructura especial y opaca llamada `FILE`. Esta estructura, definida en la
biblioteca estándar `<stdio.h>`, actúa como un intermediario que contiene toda
la información de estado necesaria para gestionar el flujo de datos ( _stream_ )
hacia y desde el archivo.

:::{figure} 4/file_pointer_concept.svg
:name: fig-file-pointer-concept
:alt: Concepto del puntero FILE* como intermediario
:align: center
:width: 80%

El cursor de lectura/escritura (`FILE *`) apuntando al stream físico en disco.

:::
<!-- {figure} 4/file_pointer_concept.svg -->

Dentro de esta estructura, el sistema operativo y la biblioteca estándar de C
manejan los detalles como:

- El **descriptor de archivo** a bajo nivel y en el sistema operativo.
- La ubicación del **búfer de E/S** en memoria para optimizar lecturas y
  escrituras.
- **Indicadores de estado**, como los flags de error y de fin de archivo (EOF).
- La **posición actual** del cursor dentro del archivo.

Al ser una **estructura opaca**, vos no necesitás conocer ni manipular sus
miembros internos directamente. En su lugar, interactuás con el archivo a través
de funciones que reciben un puntero a esta estructura.

Para declarar un puntero a `FILE`, la sintaxis es simple:

:::{code-block}c

FILE *puntero_archivo;

:::
<!-- {code-block}c -->

:::{note} Punteros: Direcciones de Memoria

Esta variable utiliza el asterisco (`*`) como declarador para indicar que
`puntero_archivo` es un tipo de dato derivado: un "puntero a `FILE`". Un puntero
almacena la dirección de memoria de un objeto (en este caso, la estructura
`FILE`). Si necesitás repasar qué son los punteros, cómo se declaran y cómo
funcionan las direcciones de memoria, consultá el {ref}`capitulo-punteros` donde
se explica este concepto en detalle.

:::
<!-- {note} Punteros: Direcciones de Memoria -->

Este puntero, una vez que la función `fopen()` lo inicializa exitosamente, se
convierte
en tu identificador único para interactuar con ese archivo específico hasta que
lo cierres con `fclose()`.

(una-analogia-con-arreglos-y-punteros)=
#### Una Analogía con Arreglos y Punteros

La idea de usar un puntero para manejar una entidad compleja les debe resultar
familiar, ya que hemos trabajado con arreglos. El concepto es similar y se
relaciona directamente con el manejo de punteros:

- En un **arreglo**, el nombre del arreglo es el identificador de un bloque de
  memoria contiguo, pero decae automáticamente a un puntero a su primer elemento
  (es decir, evalúa su dirección) en la mayoría de las expresiones. Esto te
  proporciona el punto de acceso para recorrer la secuencia contigua.
- De manera análoga, un puntero `FILE *` no es el archivo en sí. Es un puntero a
  una estructura en memoria que "sabe" todo sobre el archivo y cómo comunicarse
  con él.

:::{seealso} El Rol de los Punteros

El manejo de punteros es un pilar en la programación en C. Próximamente,
profundizaremos en cómo los punteros nos permiten manipular direcciones de
memoria directamente, lo cual es la base para entender cómo funcionan los
arreglos, la gestión de memoria dinámica y, como vimos aquí, la interacción con
sistemas externos como el sistema de archivos.

:::
<!-- {seealso} El Rol de los Punteros -->

Por ahora, es suficiente que entiendas que `puntero_archivo` es tu "manija" o
"handle" para leer, escribir y manipular el archivo que abriste.

Otro detalle importante: los argumentos de tipo cadena suelen declararse con la
notación `char *modo` (puntero a carácter). Aunque a nivel de acceso podamos
indexarlos de forma similar a un arreglo, **no hay equivalencia de identidad**:
una declaración como `char *modo = "r"` crea un puntero a un literal de cadena
almacenado en una región de memoria de solo lectura, mientras que `char modo[] =
"r"` define un arreglo mutable en la pila que se inicializa con una copia de
dicho texto. Debemos ser conscientes de esto al manipular cadenas para evitar
accesos inválidos o intentos de escritura sobre literales.








(apertura-de-archivos-fopen)=
### Apertura de Archivos: `fopen()`


La función `fopen()` es el punto de entrada crucial para cualquier operación de
archivo. Actúa como un puente entre tu programa y el sistema de archivos del
sistema operativo. Su tarea es solicitar el acceso a un archivo específico en un
modo determinado.

Si el sistema operativo concede el acceso, `fopen()` reserva los recursos
necesarios, inicializa la estructura `FILE` con la información pertinente y te
devuelve un puntero a dicha estructura. Si por alguna razón la operación falla
(el archivo no existe, no tenés permisos, etc.), la función te devolverá `NULL`.

:::{important} ¡La verificación con `NULL` es obligatoria!

Nunca asumas que `fopen()` tendrá éxito. Una de las fuentes más comunes de
errores y caídas inesperadas en programas de C es no verificar si el puntero
devuelto es `NULL` antes de intentar usarlo, una práctica exigida por la regla
de estilo {ref}`0x4001h`.

Esta función puede fallar de muchas formas y que no dependen de nuestro
programa, con situaciones como, problemas de permisos, si el archivo existe (o
no) , o algún fallo en el medio de almacenamiento en sí.

:::
<!-- {important} ¡La verificación con `NULL` es obligatoria! -->

La sintaxis, definida en `<stdio.h>`, es la siguiente:

:::{code-block}c
:caption: Sintaxis de fopen()
:label: fopen-syntax
FILE *fopen(const char *pathname, const char *mode);

:::
<!-- {code-block}c -->

- `const char *pathname`: Es una cadena de caracteres que representa la ruta al
  archivo. Puede ser una ruta relativa (ej. `"datos.txt"`) o absoluta (ej.
  `"/home/usuario/documentos/datos.txt"`).
- `const char *mode`: Es una cadena corta que especifica el modo de acceso,
definiendo qué operaciones estarán permitidas sobre el archivo.

(modos-de-apertura)=
#### Modos de apertura

Elegir el modo correcto es fundamental, ya que determina el comportamiento del
puntero del archivo y lo que sucede con el contenido que ya estaba en el
archivo.

:::{figure} 4/fopen_modes.svg
:name: fig-fopen-modes
:alt: Modos de apertura de archivos con fopen()
:align: center
:width: 85%

Modos de apertura física con `fopen`: lectura, escritura y agregado.

:::
<!-- {figure} 4/fopen_modes.svg -->

:::{list-table}
:header-rows: 1
:label: table-fopen-modes

* - Modo
  - Descripción
  - Si el archivo no existe
  - Si el archivo existe
  - Caso de Uso Típico
* - `"r"`
  - **Lectura (Read)**: Abre un archivo de texto para leer.
  - Falla (devuelve `NULL`).
  - El puntero se posiciona al inicio.
  - Leer un archivo de configuración, procesar datos de entrada.
* - `"w"`
  - **Escritura (Write)**: Abre un archivo de texto para escribir.
  - Se crea un archivo nuevo.
  - **El contenido se borra (trunca a cero)**.
  - Guardar un nuevo documento, generar un archivo de log desde cero.
* - `"a"`
  - **Añadir (Append)**: Abre un archivo de texto para escribir al final.
  - Se crea un archivo nuevo.
  - El puntero se posiciona al final. Los datos existentes se conservan.
  - Añadir eventos a un archivo de log existente.
* - `"r+"`
  - **Lectura y Escritura**: Abre para actualizar.
  - Falla (devuelve `NULL`).
  - El puntero se posiciona al inicio. Permite leer y sobreescribir.
  - Modificar un registro específico en un archivo de datos.
* - `"w+"`
  - **Escritura y Lectura**: Abre para actualizar, borrando el contenido.
  - Se crea un archivo nuevo.
  - **El contenido se borra**. Permite escribir y luego leer desde el inicio.
  - Archivos temporales que necesitás escribir y luego releer.
* - `"a+"`
  - **Añadir y Lectura**: Abre para actualizar, posicionando la escritura al
    final.
  - Se crea un archivo nuevo.
  - El puntero se posiciona al final para escribir, pero podés moverlo para
    leer.
  - Leer datos de un log y luego añadir nuevos eventos al final.

:::
<!-- {list-table} -->

(manejo-de-errores-en-la-apertura)=
#### Manejo de Errores en la Apertura

Cuando `fopen()` devuelve `NULL`, la variable global `errno` (definida en
`<errno.h>`) se establece con un código de error específico del sistema. Para
mostrar un mensaje de error legible por humanos, podés usar la función
`perror()`.

:::{code-block}c
:caption: Verificación de errores al abrir un archivo
:label: fopen-error-handling
:linenos:
#include <errno.h> // Necesario para perror()
#include <stdio.h>
int main()
{
    FILE *p_archivo;
    p_archivo = fopen("archivo_inexistente.txt", "r");
    if (p_archivo == NULL)
    {
        // Imprime un mensaje descriptivo del último error ocurrido
        perror("Error al intentar abrir el archivo");
        return 1; // Termina el programa con un código de error
    }
    printf("Archivo abierto con éxito.\n");
    // ... operaciones con el archivo ...
    fclose(p_archivo);
    return 0;
}

:::
<!-- {code-block}c -->

Al ejecutar este código, `perror()` probablemente imprimiría algo como:

``` text
Error al intentar abrir el archivo: No such file or directory`
```
<!-- text -->

(binario-vs-texto)=
#### Binario vs. Texto

Por defecto, los modos listados arriba operan en **modo texto**. Esto implica
que el sistema puede realizar conversiones automáticas de los finales de línea
para adaptarse a la convención de la plataforma (por ejemplo, convertir `\n` a
`\r\n` en Windows).

Para trabajar con archivos binarios —como imágenes, audio, ejecutables o
cualquier archivo donde cada byte importa—, es crucial evitar estas
traducciones. Para ello, simplemente agregá una `b` al final del modo (ej.
`"rb"`, `"wb+"`, `"ab"`).

:::{warning} Corrupción de Datos

Abrir un archivo no textual en modo texto puede corromper irreversiblemente los
datos, ya que secuencias de bytes que casualmente coincidan con caracteres
especiales (como el de fin de línea) serán alteradas. Usá siempre el modo
binario para archivos no textuales.

:::
<!-- {warning} Corrupción de Datos -->

Trabajar con archivos binarios es importante, pero complejo y requiere de un par
de cosas más que no hemos visto del lenguaje. Para quienes deseen chusmear como
se hace, en la sección extra, hay un [apunte](../extras/binarios.md) referido a
como trabajar de esta forma los archivos.








(escribiendo)=
### Escribiendo


Existen tres funciones para escribir en archivos, que van desde caracteres
individuales, cadenas, y terminando en cadenas con formato.

(fputc)=
#### `fputc`

La función `fputc` se utiliza para escribir un único carácter en un flujo de
archivo (_file stream_). Es una herramienta fundamental para la manipulación de
archivos a bajo nivel en C.

:::{code-block}c
:linenos:
/**
 * Escribe un carácter en un flujo de archivo.
 *
 * @param character a escribir. Se pasa como un `int` pero
 *               se convierte internamente a `unsigned char`.
 * @param stream Puntero al objeto `FILE` que identifica el
 *               flujo donde se escribirá el carácter.
 *
 * @return Si la operación es exitosa, devuelve el mismo
 *               carácter que se escribió (promocionado a `int`).
 *         Si ocurre un error, devuelve la constante `EOF`
 *               y activa el indicador de error del flujo.
 */
int fputc(int character, FILE *stream);

:::
<!-- {code-block}c -->

(fputs)=
#### `fputs`

Escribe una cadena. **No añade** el carácter de nueva línea (`\n`)
automáticamente. Devuelve un valor no negativo si tiene éxito, o `EOF` en caso
de error.

:::{code-block}c
:linenos:
/**
 * Escribe una cadena de caracteres en un flujo de archivo.
 *
 * @param cadena de caracteres terminada en nulo que se va a escribir.
 * @param stream Puntero al objeto `FILE` que identifica el flujo de salida.
 *
 * @return Devuelve un valor no negativo si la operación es exitosa.
 *         Devuelve la constante `EOF` para indicar un error.
 */
int fputs(const char *cadena, FILE *stream);

:::
<!-- {code-block}c -->

(fprintf)=
#### `fprintf`

La opción más versátil. Escribe datos con formato, análogamente a `printf()`.
Devuelve el número de caracteres escritos, o un valor negativo si ocurre un
error.

:::{code-block}c
:linenos:
/**
 * @brief Escribe datos con formato en un flujo de archivo.
 *
 * @param stream Puntero al objeto `FILE` que identifica el
 *                   flujo de salida.
 * @param formato Cadena de caracteres que contiene el texto
 *                   a escribir. Puede contener especificadores
 *                   de formato (ej. %d, %f, %s) que serán reemplazados
 *                   por los argumentos subsiguientes.
 * @param ... Lista variable de argumentos. Debe haber un argumento
 *               por cada especificador de formato en la cadena `format`.
 *
 * @return Si la operación es exitosa, devuelve el número total de caracteres
 *         escritos. Si ocurre un error de escritura, devuelve un número
           negativo.
 */
int fprintf(FILE *stream, const char *formato, ...);

:::
<!-- {code-block}c -->

(ejemplo-de-escritura-completo)=
#### Ejemplo de escritura completo

:::{code-block}c
:caption: Ejemplo de escritura y gestión de errores
:label: file-writing-example-advanced
:linenos:
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 1. Abrir el archivo en modo escritura ("w").
    FILE *salida = fopen("factura_completa.txt", "w");
    if (salida == NULL)
    {
        perror("Error al abrir el archivo 'factura_completa.txt'");
        return EXIT_FAILURE;
    }

    // 2. Escribir un encabezado usando fputs()
    const char *encabezado = "--- Documento de Factura ---\n\n";
    if (fputs(encabezado, salida) == EOF)
    {
        perror("Error escribiendo el encabezado con fputs()");
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 3. Escribir datos formateados usando fprintf()
    // fprintf() permite escribir datos con formato (como printf, pero a un
    // archivo).
    const char *item_1 = "Placa de Video RTX 4080";
    int cantidad_1 = 1;
    double precio_1 = 1200000.75;
    int chars_escritos_1 =
        fprintf(salida, "Item: %s\nCantidad: %d\nPrecio: %.2f ARS\n\n", item_1,
                cantidad_1, precio_1);
    if (chars_escritos_1 < 0)
    {
        perror("Error al formatear y escribir el item 1 con fprintf()");
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 4. Escribir un separador de línea usando fputc()
    // fputc() escribe un solo carácter en el archivo.
    int i;
    for (i = 0; i < 30; i++)
    {
        if (fputc('-', salida) == EOF)
        {
            perror("Error escribiendo separador con fputc()");
            fclose(salida);
            return EXIT_FAILURE;
        }
    }
    if (fputc('\n', salida) == EOF)
    {
        perror("Error escribiendo nueva linea con fputc()");
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 5. Escribir otro item usando una combinación de las tres funciones.
    const char *item_2 = "Memoria RAM DDR5 32GB";
    int cantidad_2 = 2;
    double precio_2 = 180000.00;
    if (fputs("Detalle del Item 2:\n", salida) == EOF)
    {
        perror("Error escribiendo detalle del item 2 con fputs()");
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Nombre: %s\n", item_2) < 0)
    {
        perror("Error escribiendo nombre del item 2 con fprintf()");
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Unidades: %d\n", cantidad_2) < 0)
    {
        perror("Error escribiendo unidades del item 2 con fprintf()");
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Valor Unitario: %.2f ARS\n", precio_2) < 0)
    {
        perror("Error escribiendo valor unitario del item 2 con fprintf()");
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 6. Cerrar el archivo. Es crucial para asegurar que todos los datos en el
    // búfer se guarden en el disco.
    if (fclose(salida) != 0)
    {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }
    printf("Archivo 'factura_completa.txt' creado y cerrado exitosamente.\n");
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

:::{important} Búferes y `fflush()`

La E/S de archivos en C está _bufferizada_ por defecto para mejorar el
rendimiento. Los datos no se escriben al disco inmediatamente, sino que se
acumulan en un búfer. `fclose()` vacía (hace _flush_) este búfer
automáticamente. Si necesitás forzar la escritura sin cerrar el archivo, podés
usar `fflush(FILE *stream)`.

:::
<!-- {important} Búferes y `fflush()` -->








(leyendo)=
### Leyendo


(fgetc)=
#### `fgetc`

La función `fgetc` se utiliza para leer un único carácter desde un flujo de
archivo. Es la contraparte directa de `fputc`.

:::{code-block}c
:linenos:
/**
 * @brief Lee un carácter desde un flujo de archivo.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo de entrada.
 *
 * @return Si la operación es exitosa, devuelve el carácter leído (promocionado
   a `int`).
 * @return Si se alcanza el final del archivo o si ocurre un error, devuelve
   `EOF`.
 */
int fgetc(FILE *stream);

:::
<!-- {code-block}c -->

(fgets)=
#### `fgets`

La función `fgets` se utiliza para leer una línea o una cadena de caracteres
desde un flujo de archivo. Es más segura que la antigua función `gets` porque
permite especificar un tamaño máximo para el búfer, evitando desbordamientos,
una práctica recomendada por la regla {ref}`0x5006h`.

:::{code-block}c
:linenos:
/**
 * @brief Lee una cadena de caracteres desde un flujo de archivo.
 *
 * La lectura se detiene cuando se encuentra un carácter de nueva línea (`\n`),
 * cuando se alcanza el final del archivo (EOF), o después de que se hayan
 * leído (num - 1) caracteres. El carácter de nueva línea, si es leído,
 * se incluye en la cadena. Se añade un carácter nulo (`\0`) al final.
 *
 * @param cadena de caracteres donde se almacenará la cadena leída.
 * @param numero máximo de caracteres a ser leídos (incluyendo el carácter nulo
   final).
 * @param stream Puntero al objeto `FILE` que identifica el flujo de entrada.
 *
 * @return En caso de éxito, devuelve el puntero `str`.
 *         Si se alcanza el final del archivo antes de leer algún carácter,
                o si ocurre un error, devuelve `NULL`.
 */
char *fgets(char *cadena, int numero, FILE *stream);

:::
<!-- {code-block}c -->

:::{warning} `numero` y `str`

El argumento `numero` debe ser igual o menor a la capacidad de la `cadena`, ya
que de otra forma
la función provocará comportamiento no definido al escribir fuera del espacio de
memoria de la `cadena`.

:::
<!-- {warning} `numero` y `str` -->

(fscanf)=
#### `fscanf`

La función `fscanf` se utiliza para leer datos con formato desde un flujo de
archivo. Funciona de manera análoga a `scanf`, pero operando sobre un archivo en
lugar de la entrada estándar.

:::{code-block}c
:linenos:
/**
 * @brief Lee datos con formato desde un flujo de archivo.
 *
 * @param[in] stream Puntero al objeto `FILE` que identifica el flujo de
   entrada.
 * @param[in] format Cadena de caracteres que especifica cómo interpretar los
   datos leídos.
 * @param[out] ... Lista variable de punteros a las variables donde se
   almacenarán los datos leídos.
 *
 * @return Devuelve el número de elementos de entrada asignados exitosamente.
 * @return Puede devolver `EOF` si se encuentra el final del archivo o ocurre
 un error antes de la primera asignación.
 */
int fscanf(FILE *stream, const char *format, ...);

:::
<!-- {code-block}c -->

(leyendo-un-archivo-paso-a-paso)=
#### Leyendo un archivo, paso a paso

El código de ejemplo es una demostración de cómo leer un archivo de texto de
manera segura y eficiente en C. La estrategia principal es **separar la
entrada/salida (E/S) del procesamiento de datos**. En lugar de intentar
interpretar los datos directamente desde el archivo con `fscanf()`, lee el
archivo línea por línea en un espacio de memoria temporal (un búfer) y luego
analiza esa línea. Este enfoque es más resiliente a errores de formato.

A continuación, se descompone el código sección por sección.

##### 1. Inclusiones y definiciones (`#include` y `#define`)

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINEA 512
#define NOMBRE_ARCHIVO "factura.txt"

:::
<!-- {code-block}c -->

- **`#include <stdio.h>`**: Incluye la biblioteca estándar de entrada/salida. Es
  fundamental porque nos da acceso a funciones como `fopen()`, `fgets()`,
  `printf()`, `perror()`, `fclose()`, `ferror()` y `feof()`.

- **`#include <stdlib.h>`**: Proporciona acceso a utilidades generales,
  incluyendo las macros `EXIT_SUCCESS` y `EXIT_FAILURE`, que son una forma
  estándar y portable de indicar si el programa terminó con o sin errores.

- **`#include <string.h>`**: Incluye la biblioteca para manipulación de cadenas
  de caracteres. La usamos aquí para la función `strncmp()`.

- **`#define MAX_LINEA 512`**: Define una constante para el tamaño máximo de
  línea que esperamos leer. Usar una constante hace que el código sea más
  legible y fácil de mantener. Si necesitáramos cambiar el tamaño del búfer,
  solo lo hacemos acá. El valor de 512 bytes es una elección común y razonable
  para muchas aplicaciones.

- **`#define NOMBRE_ARCHIVO "factura.txt"`**: Define el nombre del archivo que
  vamos a leer. Al igual que con `MAX_LINEA`, esto centraliza la configuración y
  mejora la mantenibilidad del código.

##### 2. Apertura del archivo y manejo de errores

:::{code-block}c
:linenos:
FILE *entrada = fopen(NOMBRE_ARCHIVO, "r");
if (!entrada)
{
    perror("No se pudo abrir 'factura.txt' para lectura");
    return EXIT_FAILURE;
}

:::
<!-- {code-block}c -->

- **`FILE *entrada = fopen(NOMBRE_ARCHIVO, "r");`**: Esta línea intenta abrir el
  archivo especificado por `NOMBRE_ARCHIVO` en modo lectura (`"r"`). Si tiene
  éxito, `fopen()` devuelve un puntero a una estructura `FILE`, que es un
  _handle_ o manejador que representa el flujo de datos (el _stream_). Si falla
  (por ejemplo, porque el archivo no existe o no tenemos permisos de lectura),
  devuelve `NULL`.

- **`if (!entrada) { ... }`**: Esta es la comprobación de errores **crítica**.
  _Nunca_ debés asumir que `fopen()` funcionó. Si `entrada` es `NULL` (lo que
  `!entrada` evalúa como verdadero), el programa no puede continuar.

- **`perror(...)`**: Es una función muy útil para reportar errores. Imprime en
  la salida de error estándar (`stderr`) el mensaje que le pasás como argumento,
  seguido de dos puntos y una descripción textual del último error ocurrido en
  el sistema. Por ejemplo, si el archivo no existe, podría imprimir:
  `No se pudo abrir 'factura.txt' para lectura: No such file or directory`.

- **`return EXIT_FAILURE;`**: Termina el programa indicando al sistema operativo
  que ocurrió un error.

##### 3. Lazo principal de lectura

:::{code-block}c
:linenos:
char buffer[MAX_LINEA];
int numero_linea = 0;
while (fgets(buffer, sizeof(buffer), entrada) != NULL)
{
    numero_linea++;
    // ... procesamiento de la línea ...
}

:::
<!-- {code-block}c -->

- **`char buffer[MAX_LINEA];`**: Declara el búfer, un array de caracteres donde
  `fgets()` almacenará cada línea leída del archivo.
- **`while (fgets(...) != NULL)`**: Este es el corazón del programa.
  - **`fgets(buffer, sizeof(buffer), entrada)`**: Intenta leer una línea del
    flujo `entrada`.
    - `buffer`: El destino donde se guardará la línea.
    - `sizeof(buffer)`: El tamaño máximo a leer (en este caso, 512). `fgets()`
      es segura porque nunca escribirá más allá de este límite, previniendo
      desbordamientos de búfer. Leerá hasta `sizeof(buffer) - 1` caracteres y
      agregará un `\0` al final.
    - `entrada`: El flujo de archivo del cual leer.
  - La función `fgets()` devuelve `NULL` cuando llega al final del archivo o si
    ocurre un error de lectura. Mientras no devuelva `NULL`, el lazo `while`
    continúa ejecutándose, procesando una línea en cada iteración.

##### 4. Procesamiento y análisis de cada línea (Parsing)

:::{code-block}c
:linenos:
if (strncmp(buffer, "Item:", 5) == 0)
{
    char item_nombre[100];
    int cantidad;
    double precio;
    int campos_leidos = sscanf(buffer,
                               "Item: %99[^,], Cantidad: %d, Precio: %lf
                               ARS ",
                               item_nombre,
                               &cantidad, &precio);
    if (campos_leidos == 3)
    {
        // ... éxito ...
    }
    else
    {
        // ... fallo ...
    }
}

:::
<!-- {code-block}c -->

- **`if (strncmp(buffer, "Item:", 5) == 0)`**: Antes de intentar un análisis
  costoso, se realiza una verificación rápida y eficiente. `strncmp()` compara
  los primeros `5` caracteres del `buffer` con la cadena `"Item:"`. Si son
  iguales, la función devuelve `0`, y procedemos a analizar la línea. Esto nos
  permite ignorar líneas en blanco o comentarios de forma eficiente.
- **`sscanf(buffer, "...", ...)`**: Esta es la función clave para el _parsing_.
A diferencia de `fscanf()`, que lee desde un archivo, `sscanf()` lee desde una
cadena de caracteres que ya está en memoria (el `buffer`).
  - **La cadena de formato**: Es la plantilla que `sscanf()` usa para
    interpretar los datos.
    - `"Item: "` y `", Cantidad: "` y `", Precio: "` y `" ARS"`: Son caracteres
      literales. La cadena en el búfer debe coincidir exactamente con estos
      literales (incluyendo los espacios).
    - **`%99[^,]`**: Este es un especificador de formato avanzado y muy seguro.
      - `%[...]`: Indica que se debe leer un conjunto de caracteres (un
        _scanset_).
      - `^,`: El `^` niega el conjunto. Esto significa "leer todos los
        caracteres _excepto_ la coma".
      - `99`: Es un limitador de ancho. Le dice a `sscanf()` que lea como máximo
        99 caracteres para este campo. Esto previene un desbordamiento del búfer
        `item_nombre` (que tiene tamaño 100, dejando espacio para el `\0`).
    - **`%d`**: Lee un número entero decimal.
    - **`%lf`**: Lee un número de punto flotante de tipo `double` (la `l` es de
      `long float`, que significa `double`).
- **`int campos_leidos = sscanf(...)`**: `sscanf()` devuelve el número de campos
  que pudo asignar con éxito. Guardamos este valor.
- **`if (campos_leidos == 3)`**: Comprobamos si `sscanf()` pudo leer y asignar
  los 3 campos que esperábamos (`item_nombre`, `cantidad` y `precio`). Si es
  así, el _parsing_ fue exitoso. Si no, la línea no tenía el formato correcto y
  lo informamos como una advertencia.

##### 5. Verificación post-lazo

:::{code-block}c
:linenos:
if (ferror(entrada))
{
    perror("Ocurrió un error de lectura en el archivo");
}
else if (feof(entrada))
{
    printf("\nProcesamiento completado. Se llegó al final del archivo.\n");
}

:::
<!-- {code-block}c -->

- Cuando el lazo `while (fgets(...) != NULL)` termina, hay dos posibles
  razones: se alcanzó el final del archivo (lo normal) o ocurrió un error de E/S
  (raro, pero posible). Es crucial distinguir entre ambos casos.
- **`ferror(entrada)`**: Esta función devuelve un valor verdadero si el
  indicador de error del _stream_ `entrada` está activado. Esto podría pasar si,
  por ejemplo, el disco duro falla o se desconecta una unidad USB a mitad de la
  lectura.
- **`feof(entrada)`**: Devuelve un valor verdadero si el indicador de fin de
  archivo (_End-Of-File_) del _stream_ está activado. Esta es la condición de
  salida normal y esperada del lazo.

##### 6. Limpieza y cierre

:::{code-block}c
:linenos:
clearerr(entrada);
fclose(entrada);
return EXIT_SUCCESS;

:::
<!-- {code-block}c -->

- **`clearerr(entrada)`**: Limpia los indicadores de error y de fin de archivo
  del _stream_. Es una buena práctica, aunque en este caso el programa está a
  punto de terminar y no es estrictamente necesario.
- **`fclose(entrada)`**: Cierra el archivo. Esto es **fundamental**. Libera los
  recursos que el sistema operativo había asignado para manejar el archivo, como
  el puntero a `FILE` y los búferes internos. No cerrar un archivo puede llevar
  a la pérdida de datos (especialmente en escritura) y al agotamiento de
  recursos del sistema.
- **`return EXIT_SUCCESS;`**: Informa al sistema operativo que el programa
  terminó exitosamente.








(cierre-de-archivos-fclose-el-paso-final)=
### Cierre de Archivos: `fclose()`, el Paso Final


`fclose(FILE *stream)` disocia el archivo del puntero `FILE`. Es una operación
crítica que:

1.  **Vacía el búfer de salida**: Asegura que todos los datos escritos con
    funciones como `fprintf` o `fputs` se escriban físicamente en el disco.
2.  **Libera recursos del sistema**: El sistema operativo tiene un límite en la
    cantidad de archivos que un proceso puede tener abiertos simultáneamente.

Devuelve `0` si tiene éxito y `EOF` si ocurre un error.

:::{important} Cerrar lo abierto

Siempre tenés que cerrar el archivo que abriste. No hacerlo puede resultar en
pérdida de datos, corrupción de archivos y agotamiento de recursos del sistema.
Es una de las causas más comunes de errores sutiles en programas que manejan
archivos y una violación de la regla de estilo {ref}`0x4001h`.

:::
<!-- {important} Cerrar lo abierto -->

Aunque parezca una simple formalidad, la llamada a `fclose()` también puede
fallar. Esto es particularmente cierto al escribir archivos: si el disco se
llena o el medio de almacenamiento se desconecta, el vaciado final del búfer (el
_flush_) fallará. Ignorar el valor de retorno de `fclose()` podría hacerte creer
que la operación fue exitosa cuando en realidad los últimos datos se perdieron.
La única forma de estar 100% seguro de que toda la información se guardó
correctamente es verificar el resultado del cierre.

:::{code-block}c
:caption: Verificación del cierre de un archivo
:label: fclose-example
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *log_file = fopen("app.log", "a");
    if (log_file == NULL)
    {
        perror("No se pudo abrir el log");
        return EXIT_FAILURE;
    }
    fprintf(log_file, "El programa inició una operación crítica.\n");
    // ... el resto del programa ...
    fprintf(log_file, "La operación crítica finalizó.\n");
    // Cerramos el archivo y VERIFICAMOS el resultado.
    if (fclose(log_file) != 0)
    {
        // Si fclose falla, el error queda registrado en errno.
        perror("FALLO CRÍTICO al cerrar el archivo de log");
        // En un programa real, esto podría requerir una acción de emergencia,
        // ya que los últimos datos podrían no haberse guardado.
        return EXIT_FAILURE;
    }
    printf("Log escrito y cerrado correctamente.\n");
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->








(funciones-y-variables-para-la-gestion-de-errores)=
### Funciones y variables para la gestión de errores


(stderr-el-flujo-de-error-estandar)=
#### `stderr`: El flujo de error estándar

En C, tenés tres flujos de comunicación estándar:

- `stdin` (entrada estándar): Generalmente el teclado.
- `stdout` (salida estándar): Generalmente la pantalla.
- `stderr` (error estándar): También, generalmente la pantalla.

**¿Por qué separar `stdout` de `stderr`?** Para poder redirigir la salida. 
Imaginate que ejecutás tu programa y guardás el resultado en un archivo:
`./mi_programa > salida.txt`

Si usaras `printf` (que escribe en `stdout`) para los errores, estos quedarían
mezclados con los datos correctos en `salida.txt`, haciendo difícil su
detección. Al usar `fprintf(stderr, ...)` o `perror()`, los mensajes de error se
imprimen en la consola por separado, permitiéndote ver los problemas incluso
cuando la salida "buena" está siendo redirigida.

**Uso general**: Se utilizá `stderr` para mensajes de error, diagnósticos o
advertencias.

(errno-el-codigo-del-ultimo-error)=
#### `errno`: El código del último error

`errno` es una variable global (técnicamente, una macro que se expande a una
expresión modificable) definida en `<errno.h>`. Las funciones de sistema y de la
biblioteca estándar de C la utilizan para comunicar _qué_ salió mal cuando
fallan.

- **No lo reinicies**: Nunca asignes `errno = 0;` manualmente. Su valor solo es
  válido inmediatamente después de que una función falle.
- **No lo verifiques si la función tuvo éxito**: Si `fopen()` no devuelve
  `NULL`, el valor de `errno` es irrelevante y podría contener un valor "viejo"
de un error anterior.

**Uso general**: Consultá `errno` solo después de haber detectado que una
función ha fallado (por ejemplo, verificando un retorno `NULL` o `-1`).

(perror-const-char-s-el-informador-directo)=
#### `perror(const char *s)`: El informador directo

`perror` es la forma más sencilla de reportar un error. Hace dos cosas:

1.  Imprime la cadena que le pasaste como argumento.
2.  Inmediatamente después, imprime dos puntos (`:`) y la descripción textual
    correspondiente al valor actual de `errno`.

**Situación de uso**: Ideal para herramientas de línea de comandos o scripts
donde necesitás un mensaje de error rápido, estándar y sin formato complejo. Es
menos flexible pero muy conveniente.

:::{code-block}c

// Si errno es 2 ("No such file or directory")
perror("Error al leer el archivo de configuración");
// Salida en stderr:
// Error al leer el archivo de configuración: No such file or directory

:::
<!-- {code-block}c -->

(strerror-int-errnum-el-traductor-flexible)=
#### `strerror(int errnum)`: El traductor flexible

`strerror` te da más control. Toma un número de error (casi siempre le pasarás
`errno`) y devuelve un puntero a una cadena de caracteres (`char *`) con la
descripción del error. Vos sos responsable de cómo y dónde imprimir esa cadena.

**Situación de uso**: Imprescindible cuando necesitás:

- **Formatear el mensaje de error** de una manera específica.
- **Enviar el mensaje de error a un destino diferente** a `stderr`, como un
  archivo de log, un cuadro de diálogo en una GUI, o a través de la red.
- **Internacionalización**, donde podrías querer traducir el mensaje de error a
  diferentes idiomas.

:::{code-block}c

// Si errno es 13 ("Permission denied")
fprintf(stderr, "[FATAL] Imposible acceder al recurso. Razón: %s\n",
        strerror(errno));
// Salida en stderr:
// [FATAL] Imposible acceder al recurso. Razón: Permission denied

:::
<!-- {code-block}c -->








(posicionamiento-en-archivos-acceso-aleatorio)=
### Posicionamiento en Archivos: Acceso Aleatorio


No siempre querés leer un archivo secuencialmente. Las funciones de
posicionamiento te permiten moverte a cualquier punto del archivo.

(ftell)=
#### `ftell`

La función `ftell` se utiliza para obtener la posición actual del indicador de
posición del fichero (el "cursor") dentro de un flujo. Devuelve esta posición
como un número de bytes desde el inicio del archivo.

:::{code-block}c
:linenos:
/**
 * @brief Obtiene la posición actual del indicador de posición del fichero.
 *
 * @param[in] stream Puntero al objeto `FILE` que identifica el flujo.
 *
 * @return Si es exitoso, devuelve el valor actual del indicador de posición.
 * @return En caso de error, devuelve -1L y la variable global `errno` se
   establece a un valor positivo.
 */
long int ftell(FILE *stream);

:::
<!-- {code-block}c -->

(fseek)=
#### `fseek`

La función `fseek` es la herramienta principal para mover el indicador de
posición del fichero a una ubicación específica dentro del flujo. Permite un
control preciso, moviendo el cursor un número determinado de bytes (`offset`)
desde un punto de origen (`origin`).

:::{code-block}c
:linenos:
/**
 * @brief Establece el indicador de posición del fichero a una nueva posición.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo.
 * @param offset Desplazamiento en bytes relativo al parámetro `origin`.
 * @param origin Posición desde donde se calcula el desplazamiento. Los valores
   pueden ser:
 * - `SEEK_SET`: Inicio del archivo.
 * - `SEEK_CUR`: Posición actual.
 * - `SEEK_END`: Final del archivo.
 *
 * @return Devuelve 0 si la operación es exitosa.
 *         Devuelve un valor distinto de cero en caso de error.
 */
int fseek(FILE *stream, long int offset, int origin);

:::
<!-- {code-block}c -->

(rewind)=
#### `rewind`

La función `rewind` es un caso especial y simplificado de `fseek`. Su única
función es mover el indicador de posición del fichero de vuelta al inicio del
archivo. Además, limpia cualquier indicador de error que pudiera tener el flujo.

:::{code-block}c
:linenos:
/**
 * Reposiciona el indicador de posición del fichero al inicio del flujo.
 *
 * Esta función es funcionalmente equivalente a fseek(stream, 0L, SEEK_SET),
 * pero además borra el indicador de error del flujo.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo.
 */
void rewind(FILE *stream);

:::
<!-- {code-block}c -->

(ejemplo-de-uso)=
#### Ejemplo de uso

:::{code-block}c
:caption: Uso de fseek() y ftell() para leer el último carácter
:label: fseek-example
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *archivo = fopen("factura.txt", "r");
    if (!archivo)
    {
        perror("No se pudo abrir el archivo");
        return EXIT_FAILURE;
    }
    // Moverse al final del archivo
    if (fseek(archivo, 0, SEEK_END) != 0)
    {
        perror("Error en fseek a SEEK_END");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    // Obtener la posición actual, que es el tamaño del archivo
    long tamano = ftell(archivo);
    if (tamano == -1L)
    {
        perror("Error en ftell");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    printf("El archivo tiene %ld bytes.\n", tamano);
    // Moverse a la posición ANTERIOR al último byte para leerlo.
    // Si el archivo termina con \n, esto leerá el carácter previo.
    if (tamano > 1 && fseek(archivo, -2L, SEEK_END) != 0)
    {
        perror("Error en fseek para leer el último carácter");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    int ultimo_caracter = fgetc(archivo);
    if (ultimo_caracter != EOF)
    {
        printf("El último carácter imprimible del archivo es: \x27%c\x27\n",
               (char)ultimo_caracter);
    }
    // Volver al principio
    rewind(archivo);
    printf("Después de \x27rewind\x27, la posición es: %ld\n", ftell(archivo));
    fclose(archivo);
    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->








(glosario_archivos_texto)=
### Glosario


:::{glossary}

Búfer
: En el contexto de la programación y los sistemas operativos, un **búfer** (del
  inglés _buffer_) es una región de memoria física (generalmente en la `RAM`)
  que se utiliza para almacenar datos de forma temporal mientras se
  transfieren de un lugar a otro.

    El objetivo principal de un búfer es optimizar el rendimiento y gestionar
    las diferencias de velocidad entre dos procesos o dispositivos. Por ejemplo,
    en las operaciones de entrada/salida (`I/O`), los datos se acumulan en un
    búfer antes de ser procesados o escritos en un dispositivo físico como un
    disco duro. Esto permite que el sistema realice menos operaciones de
    escritura/lectura, pero de mayor tamaño, lo cual es significativamente más
    eficiente.

    Pensá en el proceso de escribir en un archivo como si fuera enviar una
    carta. Escribir carácter por carácter directamente al disco (sin búfer)
    sería como llevar cada letra individualmente hasta el correo. Es ineficiente
    y lento.

    Usar un búfer es como escribir la carta completa en una hoja de papel (el
    búfer en la memoria). Una vez que terminaste la carta (el búfer se llenó o
    cerraste el archivo), la llevás al correo en un solo viaje. Este método es
    mucho más rápido y organizado.

    ```{figure} 4/buffer_concept.svg
    :name: fig-buffer-concept
    :alt: Concepto de búfer en operaciones de archivos
    :align: center

    Comparación entre operaciones sin búfer (ineficientes) y con búfer
    (eficientes), mostrando cómo el búfer optimiza las operaciones de E/S.
    ```

:::
<!-- {glossary} -->

## Ejercicios de Autoevaluación

:::{exercise}
:label: file-conexion-miembros
Explicá por qué no se debe intentar acceder a los miembros internos de la
estructura `FILE` directamente en tu código y qué ventajas ofrece que sea
tratada como una estructura opaca.

:::
<!-- {exercise} -->

:::{solution} file-conexion-miembros
:class: dropdown
La estructura `FILE` es opaca porque sus detalles de implementación dependen de
la biblioteca estándar del compilador y del sistema operativo subyacente. Si
accedés directamente a sus miembros (como el descriptor de archivo, la posición
del búfer o los flags de error):
1. Perdés la portabilidad: un código que compila en un sistema podría fallar en
   otro donde la estructura `FILE` tenga campos diferentes.
2. Podés corromper el estado interno del flujo de datos (stream) al eludir las
   funciones estandarizadas de E/S (`fopen`, `fread`, `fwrite`, etc.) que
   controlan la sincronización del búfer y el cursor.

Al tratarla como opaca, el estándar garantiza una interfaz uniforme e
independiente de la plataforma a través de punteros (`FILE *`).

:::
<!-- {solution} file-conexion-miembros -->

:::{exercise}
:label: file-conexion-puntero-invalido
Analizá el siguiente código e identificá el error de concepto respecto al manejo
de la variable `archivo`:

```{code-block} c
:linenos:
#include <stdio.h>
int main(void)
{
    FILE archivo;
    archivo = fopen("datos.txt", "r");
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} file-conexion-puntero-invalido
:class: dropdown
El error radica en que se declaró `archivo` como una variable de tipo `FILE` en
lugar de un puntero a `FILE` (`FILE *`).
1. La función `fopen` devuelve un puntero (`FILE *`), no la estructura en sí.
2. Como `FILE` es una estructura opaca, el compilador usualmente no conoce su
   tamaño completo o no permite instanciarla directamente en la pila, lo que
   provoca un error de compilación.
La declaración correcta debe ser `FILE *archivo;`.

:::
<!-- {solution} file-conexion-puntero-invalido -->

:::{exercise}
:label: file-conexion-multiples
Supongamos que tu aplicación necesita procesar de forma simultánea tres archivos
de entrada diferentes. Explicá cómo debés declarar e inicializar las conexiones
correspondientes utilizando la estructura `FILE *` y qué sucede si intentás
reutilizar un único puntero sin cerrar las conexiones previas.

:::
<!-- {exercise} -->

:::{solution} file-conexion-multiples
:class: dropdown
Para procesar tres archivos en forma simultánea, debés declarar tres punteros
`FILE *` independientes (por ejemplo, `FILE *f1, *f2, *f3;`) e invocar `fopen`
para cada uno de ellos.

Si intentás reutilizar una única variable de tipo puntero (por ejemplo, `f1 =
fopen("a.txt", "r"); f1 = fopen("b.txt", "r");`) sin cerrar la primera con
`fclose`:
1. Pérdida del handle: Perdés la dirección de memoria de la estructura `FILE`
   del primer archivo. Ya no podrás leer de él ni cerrarlo correctamente, lo que
   provoca una fuga de recursos (resource leak) en el sistema operativo.
2. Comportamiento indefinido: El descriptor del primer archivo queda abierto en
   el sistema hasta que finalice el programa.

:::
<!-- {solution} file-conexion-multiples -->

:::{exercise}
:label: fopen-lectura-segura
Escribí un fragmento de código en C que intente abrir el archivo `"config.json"`
en modo de solo lectura. Si el archivo no existe o no se puede abrir, debés
informar el error correspondiente utilizando `perror` de forma clara y finalizar
la ejecución con un estado de error.

:::
<!-- {exercise} -->

:::{solution} fopen-lectura-segura
:class: dropdown
El siguiente código abre el archivo y realiza la verificación obligatoria del
puntero devuelto (`{ref}0x4001h`):

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *archivo = fopen("config.json", "r");
    if (archivo == NULL)
    {
        perror("Error al intentar abrir 'config.json'");
        return EXIT_FAILURE;
    }
    // Aquí irían las operaciones con el archivo...
    fclose(archivo);
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} fopen-lectura-segura -->

:::{exercise}
:label: fopen-modos-seleccion
Un sistema requiere leer la configuración de un archivo llamado
`"historial.log"`. Si el archivo ya contiene información, el programa debe
conservar todos los datos y añadir nuevos registros al final del archivo. Si el
archivo no existe, el programa debe crearlo. Determiná cuál es el modo de
apertura de `fopen` que debés utilizar y justificá tu respuesta.

:::
<!-- {exercise} -->

:::{solution} fopen-modos-seleccion
:class: dropdown
El modo de apertura adecuado es `"a"` (añadir/append) o `"a+"` (si además
necesitás realizar operaciones de lectura).

Justificación:
1. Si el archivo existe: El cursor se posiciona automáticamente al final del
   archivo y cualquier escritura se agregará allí, protegiendo y conservando la
   información que ya estaba en el archivo.
2. Si el archivo no existe: El sistema operativo crea el archivo de forma
   automática.
Si hubieras utilizado `"w"`, el archivo existente se habría truncado a cero
bytes, perdiendo toda la información previa.

:::
<!-- {solution} fopen-modos-seleccion -->

:::{exercise}
:label: abrir_para_escribir_seguro
Diseñá una función en C llamada `abrir_para_escribir_seguro` que reciba el
nombre de un archivo. La función debe intentar abrir el archivo en modo lectura
`"r"` primero para verificar si ya existe. Si existe, debe retornar `NULL` (para
evitar sobreescribirlo accidentalmente). Si no existe, debe abrirlo en modo
escritura `"w"`, creándolo, y retornar el puntero `FILE *` obtenido.

:::
<!-- {exercise} -->

:::{solution} abrir_para_escribir_seguro
:class: dropdown
La función implementa una estrategia de validación previa:

```{code-block} c
:linenos:
#include <stdio.h>
FILE *abrir_para_escribir_seguro(const char *nombre_archivo)
{
    FILE *archivo_existente = fopen(nombre_archivo, "r");
    if (archivo_existente != NULL)
    {
        // El archivo ya existe, lo cerramos y retornamos NULL
        fclose(archivo_existente);
        return NULL;
    }
    // Si no existe, fopen("...", "r") devolvió NULL.
    // Ahora es seguro abrirlo con "w".
    return fopen(nombre_archivo, "w");
}

```
<!-- {code-block} c -->

:::
<!-- {solution} abrir_para_escribir_seguro -->

:::{exercise}
:label: escribiendo-abecedario-fputc
Escribí un programa en C que cree el archivo `"alfabeto.txt"` y escriba en él
todas las letras mayúsculas de la `'A'` a la `'Z'`, separadas por un espacio en
blanco, utilizando un lazo y la función `fputc`. Recordá realizar el control de
errores de apertura y cierre del archivo.

:::
<!-- {exercise} -->

:::{solution} escribiendo-abecedario-fputc
:class: dropdown
El programa utiliza un lazo para recorrer los caracteres ASCII y los escribe uno
a uno:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *archivo = fopen("alfabeto.txt", "w");
    if (archivo == NULL)
    {
        perror("Error al crear el archivo");
        return EXIT_FAILURE;
    }
    // Se recorren los caracteres ASCII de la 'A' a la 'Z' usando un lazo
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (fputc(c, archivo) == EOF)
        {
            perror("Error al escribir el caracter");
            fclose(archivo);
            return EXIT_FAILURE;
        }
        if (c != 'Z')
        {
            if (fputc(' ', archivo) == EOF)
            {
                perror("Error al escribir el espacio");
                fclose(archivo);
                return EXIT_FAILURE;
            }
        }
    }
    if (fclose(archivo) != 0)
    {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} escribiendo-abecedario-fputc -->

:::{exercise}
:label: escribiendo-matriz-fprintf
Escribí una función en C llamada `guardar_matriz` que reciba un puntero `FILE
*salida`, una matriz bidimensional de enteros `int matriz[3][3]` y sus
dimensiones. La función debe guardar la matriz en el archivo con un formato
alineado de filas y columnas (por ejemplo, tres números por línea separados por
tabuladores). La función debe validar el puntero al archivo y retornar `-1` si
ocurre un error de escritura o `0` si tiene éxito.

:::
<!-- {exercise} -->

:::{solution} escribiendo-matriz-fprintf
:class: dropdown
La función utiliza `fprintf` y valida los valores de retorno para asegurar que
la escritura fue correcta:

```{code-block} c
:linenos:
#include <stdio.h>
int guardar_matriz(FILE *salida, int matriz[3][3], int filas, int columnas)
{
    if (salida == NULL)
    {
        return -1;
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // Escribimos cada elemento formateado con un tabulador
            if (fprintf(salida, "%d\t", matriz[i][j]) < 0)
            {
                return -1; // Error en fprintf
            }
        }
        // Agregamos un salto de línea al final de cada fila
        if (fputc('\n', salida) == EOF)
        {
            return -1; // Error en fputc
        }
    }
    return 0; // Éxito
}

```
<!-- {code-block} c -->

:::
<!-- {solution} escribiendo-matriz-fprintf -->

:::{exercise}
:label: escribiendo-fputs-vs-fprintf
Analizá el rendimiento y la complejidad de las funciones `fputs` y `fprintf`.
Explicá en qué situación es más adecuado usar `fputs` en lugar de `fprintf` y
por qué.

:::
<!-- {exercise} -->

:::{solution} escribiendo-fputs-vs-fprintf
:class: dropdown
`fputs` es una función diseñada exclusivamente para escribir cadenas de
caracteres literales en un archivo, sin realizar ninguna interpretación ni
procesamiento de formato.

Por otro lado, `fprintf` debe analizar la cadena de formato (buscando los `%`),
evaluar los tipos de datos de los argumentos variables pasados al final y
convertirlos a texto en tiempo de ejecución.

Por ende:
1. **Rendimiento**: `fputs` es significativamente más rápida porque no tiene el
   costo computacional de análisis y conversión de formato.
2. **Simplicidad**: Para cadenas fijas (ej. un encabezado como `"--- Fin de
   reporte ---\n"`), `fputs` es más directa y segura.
Debés elegir `fprintf` solo cuando necesites concatenar o formatear variables
(como enteros, reales, etc.) en una cadena textual en el archivo.

:::
<!-- {solution} escribiendo-fputs-vs-fprintf -->

:::{exercise}
:label: leyendo-imprimir-fgetc
Escribí una función en C llamada `mostrar_archivo` que reciba una cadena con el
nombre de un archivo y muestre todo su contenido en la salida estándar
(`stdout`) carácter por carácter, utilizando la función `fgetc`. Asegurá el
correcto tratamiento del final de archivo (`EOF`) y el manejo de errores al
abrir el archivo.

:::
<!-- {exercise} -->

:::{solution} leyendo-imprimir-fgetc
:class: dropdown
La función abre el archivo en modo de lectura y utiliza un lazo `while` para
leer y mostrar cada carácter hasta llegar a `EOF`:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
void mostrar_archivo(const char *nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        perror("No se pudo abrir el archivo para mostrar su contenido");
        return;
    }
    int caracter; // Debe ser int para almacenar EOF correctamente
    while ((caracter = fgetc(archivo)) != EOF)
    {
        putchar(caracter); // Imprime en la salida estándar
    }
    if (ferror(archivo))
    {
        perror("Ocurrió un error de lectura en el archivo");
    }
    fclose(archivo);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} leyendo-imprimir-fgetc -->

:::{exercise}
:label: leyendo-contar-lineas-fgets
Escribí una función en C llamada `contar_lineas` que reciba el puntero a un
archivo abierto para lectura. La función debe recorrer el archivo utilizando
`fgets` con un búfer seguro de 256 bytes y retornar la cantidad de líneas
encontradas. Asegurate de manejar correctamente el caso en que una línea exceda
el tamaño del búfer.

:::
<!-- {exercise} -->

:::{solution} leyendo-contar-lineas-fgets
:class: dropdown
Cuando una línea excede el tamaño del búfer de `fgets`, la función lee la línea
en "fragmentos". Solo debemos contar una nueva línea cuando encontremos el
carácter de salto de línea `\n` al final del búfer, o cuando la lectura termine
y hayamos leído caracteres en la última línea:

```{code-block} c
:linenos:
#include <stdio.h>
#include <string.h>
int contar_lineas(FILE *archivo)
{
    if (archivo == NULL)
    {
        return -1;
    }
    char buffer[256];
    int lineas = 0;
    int en_linea = 0; // Flag para rastrear si estamos dentro de una línea
    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        en_linea = 1;
        size_t len = strlen(buffer);
        // Si el último carácter es un salto de línea, se completa una línea
        // entera
        if (len > 0 && buffer[len - 1] == '\n')
        {
            lineas++;
            en_linea = 0;
        }
    }
    // Si terminó el archivo pero la última línea no terminaba con '\n'
    if (en_linea)
    {
        lineas++;
    }
    return lineas;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} leyendo-contar-lineas-fgets -->

:::{exercise}
:label: leyendo-sscanf-parsing
Un archivo de texto `"estudiantes.txt"` contiene registros con el formato
`"Nombre,Nota1,Nota2"`. Escribí un fragmento de código que lea este archivo
línea por línea de manera segura utilizando `fgets` y, mediante `sscanf`,
extraiga el nombre del estudiante y sus dos notas (enteros) para calcular y
mostrar su promedio.

:::
<!-- {exercise} -->

:::{solution} leyendo-sscanf-parsing
:class: dropdown
El código implementa la recomendación de separar la lectura del parsing,
utilizando un búfer de línea y `sscanf` con validación de campos:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#define MAX_L 256
int main(void)
{
    FILE *archivo = fopen("estudiantes.txt", "r");
    if (archivo == NULL)
    {
        perror("Error al abrir 'estudiantes.txt'");
        return EXIT_FAILURE;
    }
    char buffer[MAX_L];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        char nombre[100];
        int nota1, nota2;
        // sscanf lee desde el buffer en memoria.
        // %99[^,] lee hasta 99 caracteres que no sean comas.
        int campos = sscanf(buffer, "%99[^,],%d,%d", nombre, &nota1, &nota2);
        if (campos == 3)
        {
            double promedio = (nota1 + nota2) / 2.0;
            printf("Estudiante: %s | Promedio: %.2f\n", nombre, promedio);
        }
        else
        {
            fprintf(stderr, "Advertencia: línea con formato incorrecto.\n");
        }
    }
    fclose(archivo);
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} leyendo-sscanf-parsing -->

:::{exercise}
:label: fclose-descriptores-leak
Explicá qué es una fuga de descriptores de archivo (file descriptor leak), cómo
se produce en C y por qué este problema puede provocar el colapso de un servidor
que debe permanecer encendido en producción por varios meses.

:::
<!-- {exercise} -->

:::{solution} fclose-descriptores-leak
:class: dropdown
Una fuga de descriptores de archivo ocurre cuando un programa abre un archivo
usando `fopen` (u otras llamadas del sistema) pero nunca lo cierra mediante
`fclose` antes de perder la referencia al puntero `FILE *`.

Consecuencias:
1. El sistema operativo asigna un identificador único (un número entero de bajo
   nivel) a cada archivo abierto y tiene un límite estricto de cuántos
   descriptores puede abrir un único proceso simultáneamente.
2. Si un servidor abre archivos de configuración o logs en cada conexión
   entrante de clientes y olvida cerrarlos, irá agotando este límite de forma
   gradual.
3. Una vez alcanzado el límite máximo, cualquier intento posterior de abrir
   archivos (o incluso sockets de red) fallará con un error, haciendo que el
   servidor no pueda responder o colapse por completo.

:::
<!-- {solution} fclose-descriptores-leak -->

:::{exercise}
:label: fclose-retorno-validacion
Escribí un código en C donde crees un archivo de log llamado `"critico.txt"`,
escribas una cadena formateada con datos de una transacción y verifiques el
código de retorno tanto al escribir como al realizar el cierre (`fclose`).
Justificá por qué esta verificación de error al cerrar es tan importante en
operaciones de escritura.

:::
<!-- {exercise} -->

:::{solution} fclose-retorno-validacion
:class: dropdown
La verificación en el cierre es indispensable porque `fclose` fuerza la
escritura física de los datos acumulados en los búferes de memoria del sistema
operativo:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *archivo = fopen("critico.txt", "w");
    if (archivo == NULL)
    {
        perror("Error al abrir");
        return EXIT_FAILURE;
    }
    if (fprintf(archivo, "Transaccion ID: %d, Monto: %.2f\n", 1024, 45000.50) <
        0)
    {
        perror("Error en escritura");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    // Verificamos el cierre del archivo
    if (fclose(archivo) != 0)
    {
        perror(
            "Error al cerrar el archivo. Los datos pudieron haberse perdido");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

Justificación: Para evitar operaciones lentas, el sistema operativo almacena
temporalmente los datos en la memoria RAM (el búfer). Cuando llamás a `fclose`,
estos datos se transfieren al disco rígido. Si el disco se llenó o el medio se
desconectó en ese instante, la escritura final fallará y la única forma de
enterarte es evaluando el retorno de `fclose`.

:::
<!-- {solution} fclose-retorno-validacion -->

:::{exercise}
:label: fclose-doble-cierre
Analizá el siguiente fragmento de código e identificá los riesgos asociados con
la ejecución de `fclose`:

```{code-block} c
:linenos:
#include <stdio.h>
void liberar_recursos(FILE *f)
{
    fclose(f);
}
int main(void)
{
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo)
    {
        liberar_recursos(archivo);
        fclose(archivo);
    }
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} fclose-doble-cierre
:class: dropdown
El fragmento de código presenta dos problemas de seguridad graves:
1. **Doble cierre (Double Close)**: Se llama a `fclose` sobre el mismo puntero
   `archivo` dos veces consecutivas (una dentro de `liberar_recursos` y otra en
   el `main`). Esto produce un comportamiento indefinido. En sistemas reales,
   puede causar accesos inválidos de memoria o cerrar accidentalmente otro
   archivo que haya sido abierto por el sistema en el mismo hilo y al que se le
   haya asignado el mismo descriptor.
2. **Puntero huérfano**: Tras el primer `fclose`, la variable `archivo` sigue
   apuntando a la dirección de memoria de la estructura `FILE` que ya fue
   liberada.
Para solucionarlo, se debe evitar el doble llamado o asignar `archivo = NULL;`
inmediatamente después de un cierre exitoso, permitiendo realizar una
verificación previa.

:::
<!-- {solution} fclose-doble-cierre -->

:::{exercise}
:label: errores-stdout-vs-stderr
Escribí una función en C llamada `registrar_log` que reciba un entero con el
nivel de gravedad (`0` para información general, `1` para error crítico) y un
mensaje. La función debe dirigir el mensaje al flujo estándar adecuado (`stdout`
o `stderr`) según corresponda. Explicá cómo permite esto redireccionar los
errores por separado en la terminal.

:::
<!-- {exercise} -->

:::{solution} errores-stdout-vs-stderr
:class: dropdown
La función implementa la separación de flujos estándar:

```{code-block} c
:linenos:
#include <stdio.h>
void registrar_log(int gravedad, const char *mensaje)
{
    if (gravedad == 0)
    {
        // Mensaje ordinario de información
        fprintf(stdout, "[INFO] %s\n", mensaje);
    }
    else if (gravedad == 1)
    {
        // Mensaje de error crítico
        fprintf(stderr, "[ERROR] %s\n", mensaje);
    }
}

```
<!-- {code-block} c -->

Explicación:
En los sistemas operativos modernos, podés redirigir la salida estándar del
programa a un archivo usando `./programa > salida.txt`. Al usar `stderr` para
los errores, estos no se mezclan en `salida.txt` y se siguen visualizando
directamente en la terminal. También podés redirigir únicamente los errores a un
archivo de log específico mediante `./programa 2> errores.log`.

:::
<!-- {solution} errores-stdout-vs-stderr -->

:::{exercise}
:label: errores-errno-strerror
Escribí un fragmento de código que intente abrir un archivo de configuración en
un directorio inexistente (lo cual forzará un error). Al detectar que `fopen`
retornó `NULL`, debés utilizar la variable global `errno` junto con `strerror`
para imprimir en `stderr` un mensaje de error personalizado con la fecha del
sistema simulada y la causa exacta.

:::
<!-- {exercise} -->

:::{solution} errores-errno-strerror
:class: dropdown
El código requiere incluir los encabezados `<errno.h>` y `<string.h>` para
realizar el formateo del error:

```{code-block} c
:linenos:
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    FILE *conf = fopen("/carpeta_inexistente/config.json", "r");
    if (conf == NULL)
    {
        // Obtenemos la causa textual del error a partir del código numérico en
        // errno
        const char *causa = strerror(errno);
        fprintf(stderr,
                "[LOG_ERROR] Fallo al iniciar el sistema. Causa: %s (Codigo: "
                "%d)\n",
                causa, errno);
        return EXIT_FAILURE;
    }
    fclose(conf);
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} errores-errno-strerror -->

:::{exercise}
:label: errores-perror-vs-strerror
Analizá las diferencias de flexibilidad entre `perror` y `strerror`. Proponé un
caso concreto en el que `perror` sea insuficiente y sea obligatorio emplear
`strerror`.

:::
<!-- {exercise} -->

:::{solution} errores-perror-vs-strerror
:class: dropdown
`perror` es una función simple y rígida: siempre imprime el mensaje provisto,
seguido de `: ` y el error del sistema en el flujo `stderr`.

`strerror` es una función de conversión: recibe el código de error y devuelve
una cadena de caracteres (`char *`). Esto la hace mucho más flexible por tres
motivos:
1. **Destino alternativo**: Si querés registrar el error en un archivo físico en
   lugar de mostrarlo por consola (por ejemplo, escribiéndolo en un archivo de
   log con `fprintf(archivo_log, "%s", strerror(errno))`), `perror` no te sirve
   porque escribe directamente en `stderr`.
2. **Formateo**: Si necesitás incrustar el mensaje en medio de una frase
   compleja (ej: `"[Transaccion fallida] - Codigo: %d - Detalle: %s\n"`),
   `strerror` es obligatoria.
3. **Internacionalización**: Si tu software debe mostrar los errores adaptados a
   diferentes lenguajes o a una interfaz gráfica de usuario (GUI), debés usar
   `strerror` para tomar el texto y pasárselo a la ventana de tu aplicación.

:::
<!-- {solution} errores-perror-vs-strerror -->

:::{exercise}
:label: posicionamiento-tamano-bytes
Escribí una función en C llamada `obtener_tamano` que reciba el nombre de un
archivo, determine su tamaño exacto en bytes utilizando `fseek` y `ftell` sin
alterar su contenido, y devuelva ese tamaño como un valor de tipo `long`.
Asegurate de controlar todos los posibles errores de posicionamiento y de dejar
el archivo debidamente cerrado.

:::
<!-- {exercise} -->

:::{solution} posicionamiento-tamano-bytes
:class: dropdown
El proceso requiere posicionar el cursor al final del archivo para consultar la
distancia en bytes al origen:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
long obtener_tamano(const char *nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        perror("No se pudo abrir el archivo");
        return -1;
    }
    // Desplazamos el cursor 0 bytes relativos al final del archivo (SEEK_END)
    if (fseek(archivo, 0L, SEEK_END) != 0)
    {
        perror("Error de posicionamiento en fseek");
        fclose(archivo);
        return -1;
    }
    // ftell nos da la posición actual del cursor (que equivale al tamaño del
    // archivo en bytes)
    long tamano = ftell(archivo);
    if (tamano == -1L)
    {
        perror("Error al obtener la posicion con ftell");
        fclose(archivo);
        return -1;
    }
    fclose(archivo);
    return tamano;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} posicionamiento-tamano-bytes -->

:::{exercise}
:label: posicionamiento-reemplazo-caracter
Escribí un programa en C que abra un archivo llamado `"datos.txt"` en modo
lectura/escritura (sin borrar su contenido previo). Si el archivo tiene al menos
5 bytes, debés posicionar el cursor sobre el quinto byte (índice 4 en base 0) y
reemplazar dicho carácter por una `'X'`. Recordá validar el resultado de cada
llamada.

:::
<!-- {exercise} -->

:::{solution} posicionamiento-reemplazo-caracter
:class: dropdown
El programa debe utilizar el modo `"r+"` que permite lectura y escritura
simultáneas sin truncar el archivo a cero bytes:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // Abrimos el archivo en modo actualizacion (r+)
    FILE *archivo = fopen("datos.txt", "r+");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo en modo r+");
        return EXIT_FAILURE;
    }
    // Movemos el cursor al quinto byte (desplazamiento de 4 desde el inicio)
    if (fseek(archivo, 4L, SEEK_SET) != 0)
    {
        perror("El archivo no tiene suficientes bytes para posicionarse");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    // Sobreescribimos el carácter
    if (fputc('X', archivo) == EOF)
    {
        perror("Error al intentar sobreescribir el caracter");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    if (fclose(archivo) != 0)
    {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} posicionamiento-reemplazo-caracter -->

:::{exercise}
:label: posicionamiento-rewind-vs-fseek
Explicá de forma detallada la diferencia de comportamiento entre llamar a
`rewind(stream)` y ejecutar la instrucción `fseek(stream, 0L, SEEK_SET)`. ¿En
qué circunstancias la llamada a `rewind` simplifica el control de errores?

:::
<!-- {exercise} -->

:::{solution} posicionamiento-rewind-vs-fseek
:class: dropdown
Aunque ambas operaciones mueven el indicador de posición (el cursor) de vuelta
al principio del archivo (byte 0), existen diferencias fundamentales:

1. **Indicador de error**: `rewind` borra automáticamente el indicador de error
   del flujo (como si invocaras `clearerr`), mientras que `fseek` no lo altera.
   Si el archivo tenía activo un flag de error de lectura previo, `fseek`
   mantendrá ese flag encendido, impidiendo operaciones futuras, mientras que
   `rewind` lo restablecerá a un estado limpio.
2. **Valor de retorno**: `fseek` devuelve un entero (`0` si tiene éxito o un
   valor distinto en caso de error), lo que te obliga a validar la llamada. En
   cambio, `rewind` no devuelve ningún valor (`void`).
3. **Simplicidad**: `rewind` simplifica el control de errores al agrupar la
   limpieza de flags y el posicionamiento en un solo paso, eliminando la
   necesidad de escribir una cláusula condicional `if (fseek(...) != 0)`.

:::
<!-- {solution} posicionamiento-rewind-vs-fseek -->

## Glosario

:::{glossary}

Stream (Flujo)
: Abstracción que representa un canal de comunicación para E/S.

FILE
: Estructura de C que encapsula la información de control de un stream.

EOF (End of File)
: Constante que representa el fin de un archivo.

Buffer
: Área de almacenamiento temporal para optimizar transferencias de E/S.

:::
<!-- {glossary} -->

## Síntesis y Resumen

En este apunte se han presentado los conceptos fundamentales del tema.

(referencias-lecturas-archivos-texto)=
## Referencias y Lecturas Complementarias

- **Kernighan, B. W. y Ritchie, D. M.** [@kernighan_c_2014]. *The C Programming
  Language* (2.ª edición). Prentice Hall.
  - Consultá el **Capítulo 7: Input and Output**, donde se detalla el diseño de
    la biblioteca estándar de E/S, la manipulación de archivos y los
    descriptores del sistema.
- **King, K. N.** [@king_c_2008]. *C Programming: A Modern Approach* (2.ª
  edición). W. W. Norton & Company.
  - Revisá el **Capítulo 22: Input/Output** para un estudio pormenorizado de los
    flujos de texto, las diferencias entre E/S con y sin buffer, y el manejo de
    errores con `feof` y `ferror`.
- **Gustedt, J.** [@gustedt_modern_2019]. *Modern C*. Manning Publications.
  - Estudiá el **Nivel 2 (Refine)**, sección de entrada/salida de la biblioteca
    estándar, donde se analiza la interacción de streams con el sistema
    operativo y la portabilidad del código.
