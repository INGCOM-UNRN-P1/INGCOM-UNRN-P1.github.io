---
title: Archivos
short_title: "8 - Archivos"
description: >
  Una guía exhaustiva sobre cómo abrir, leer, escribir, posicionar y gestionar
  errores de forma robusta al trabajar con archivos de texto en el lenguaje de
  programación C.
---

# Trabajando con archivos (de texto) en C

El manejo de archivos es una capacidad fundamental en la mayoría de las
aplicaciones. En C, la librería estándar de E/S (`stdio.h`) provee un conjunto
robusto y de bajo nivel para interactuar con el sistema de archivos. Este apunte
amplía el manejo de archivos de texto, cubriendo no solo las operaciones básicas
sino también el posicionamiento dentro del archivo y, de manera crucial, una
gestión de errores detallada y profesional.

:::{figure} 8/file_operations_flow.svg
:name: fig-file-operations-flow
:alt: Flujo completo de operaciones con archivos

Diagrama de flujo que muestra la secuencia completa de operaciones al trabajar con archivos: abrir, verificar NULL, realizar operaciones, verificar errores y cerrar.
:::

## El `FILE`, la conexión con el archivo

Toda operación sobre archivos en C se realiza a través de un puntero a una estructura especial y opaca llamada `FILE`. Esta estructura, definida en la biblioteca estándar `<stdio.h>`, actúa como un intermediario que contiene toda la información de estado necesaria para gestionar el flujo de datos ( _stream_ ) hacia y desde el archivo.

:::{figure} 8/file_pointer_concept.svg
:name: fig-file-pointer-concept
:alt: Concepto del puntero FILE* como intermediario

El puntero `FILE*` actúa como "manija" o "handle" que conecta tu programa con el archivo físico en disco. La estructura FILE contiene toda la información necesaria para gestionar las operaciones.
:::

Dentro de esta estructura, el sistema operativo y la biblioteca estándar de C manejan los detalles como:

- El **descriptor de archivo** a bajo nivel y en el sistema operativo.
- La ubicación del **búfer de E/S** en memoria para optimizar lecturas y escrituras.
- **Indicadores de estado**, como los flags de error y de fin de archivo (EOF).
- La **posición actual** del cursor dentro del archivo.

Al ser una **estructura opaca**, vos no necesitás conocer ni manipular sus miembros internos directamente. En su lugar, interactuás con el archivo a través de funciones que reciben un puntero a esta estructura.

Para declarar un puntero a `FILE`, la sintaxis es simple:

```{code-block}c
FILE *puntero_archivo;
```

:::{note} Punteros: Direcciones de Memoria
Esta variable tiene un carácter extra, el `*`, que indica que `puntero_archivo` es de tipo "puntero a `FILE`". Un puntero almacena la dirección de memoria donde se encuentra el objeto (en este caso, la estructura FILE). Si necesitás repasar qué son los punteros, cómo se declaran, y cómo funcionan las direcciones de memoria, consultá el [](7_punteros) donde se explica este concepto fundamental en detalle.
:::

Este puntero, una vez que la función `fopen()` lo inicializa exitosamente, se convierte
en tu identificador único para interactuar con ese archivo específico hasta que
lo cierres con `fclose()`.

### Una Analogía con Arreglos y Punteros

La idea de usar un puntero para manejar una entidad compleja les debe resultar
familiar, ya que hemos trabajado con arreglos. En sí, el concepto es bastante
similar y se relaciona directamente con el manejo de punteros, un tema
fundamental que exploraremos en detalle más adelante.

- En un **arreglo**, el nombre del arreglo actúa como un puntero a la dirección
  de memoria de su primer elemento. No contiene todos los datos, sino que te da
  el punto de acceso para empezar a recorrerlos.
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

Por ahora, es suficiente que entiendas que `puntero_archivo` es tu "manija" o
"handle" para leer, escribir y manipular el archivo que abriste.

Otro detalle importante, los argumentos de tipo cadena, se expresan utilizando
esta notación, por lo que donde vean algo como `char *modo`, interprétenlo que
es equivalente a `char mode[]`

## Apertura de Archivos: `fopen()`

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
devuelto es `NULL` antes de intentar usarlo, una práctica exigida por la regla de estilo {ref}`0x001Dh`.

Esta función puede fallar de muchas formas y que no dependen de nuestro
programa, con situaciones como, problemas de permisos, si el archivo existe (o
no) , o algún fallo en el medio de almacenamiento en sí.
:::

La sintaxis, definida en `<stdio.h>`, es la siguiente:

```{code-block}c
:caption: Sintaxis de fopen()
:label: fopen-syntax

FILE *fopen(const char *pathname, const char *mode);
```

- `const char *pathname`: Es una cadena de caracteres que representa la ruta al
  archivo. Puede ser una ruta relativa (ej. `"datos.txt"`) o absoluta (ej.
  `"/home/usuario/documentos/datos.txt"`).
- `const char *mode`: Es una cadena corta que especifica el modo de acceso,
definiendo qué operaciones estarán permitidas sobre el archivo.

### Modos de apertura

Elegir el modo correcto es fundamental, ya que determina el comportamiento del
puntero del archivo y lo que sucede con el contenido que ya estaba en el
archivo.

:::{figure} 8/fopen_modes.svg
:name: fig-fopen-modes
:alt: Modos de apertura de archivos con fopen()

Guía visual de los diferentes modos de apertura y un diagrama de decisión para elegir el modo correcto según tus necesidades.
:::

```{list-table}
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
  - **Añadir y Lectura**: Abre para actualizar, posicionando la escritura al final.
  - Se crea un archivo nuevo.
  - El puntero se posiciona al final para escribir, pero podés moverlo para leer.
  - Leer datos de un log y luego añadir nuevos eventos al final.
```

### Manejo de Errores en la Apertura

Cuando `fopen()` devuelve `NULL`, la variable global `errno` (definida en
`<errno.h>`) se establece con un código de error específico del sistema. Para
mostrar un mensaje de error legible por humanos, podés usar la función
`perror()`.

```{code-block}c
:caption: Verificación de errores al abrir un archivo
:label: fopen-error-handling

#include <stdio.h>
#include <errno.h> // Necesario para perror()

int main() {
    FILE *p_archivo;
    p_archivo = fopen("archivo_inexistente.txt", "r");

    if (p_archivo == NULL) {
        // Imprime un mensaje descriptivo del último error ocurrido
        perror("Error al intentar abrir el archivo");
        return 1; // Termina el programa con un código de error
    }

    printf("Archivo abierto con éxito.\n");
    // ... operaciones con el archivo ...
    fclose(p_archivo);

    return 0;
}
```

Al ejecutar este código, `perror()` probablemente imprimiría algo como:

```text
Error al intentar abrir el archivo: No such file or directory`
```

### Binario vs. Texto

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

Trabajar con archivos binarios es importante, pero complejo y requiere de un par
de cosas más que no hemos visto del lenguaje. Para quienes deseen chusmear como
se hace, en la sección extra, hay un [apunte](../extras/binarios.md) referido a
como trabajar de esta forma los archivos.

## Escribiendo

Existen tres funciones para escribir en archivos, que van desde caracteres
individuales, cadenas, y terminando en cadenas con formato.

### `fputc`

La función `fputc` se utiliza para escribir un único carácter en un flujo de
archivo (_file stream_). Es una herramienta fundamental para la manipulación de
archivos a bajo nivel en C.

```{code-block}c
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
```

### `fputs`

Escribe una cadena. **No añade** el carácter de nueva línea (`\n`)
automáticamente. Devuelve un valor no negativo si tiene éxito, o `EOF` en caso
de error.

```{code-block}c
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
```

### `fprintf`

La opción más versátil. Escribe datos con formato, análogamente a `printf()`.
Devuelve el número de caracteres escritos, o un valor negativo si ocurre un
error.

```{code-block}c
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
 * @return Si la operación es exitosa, devuelve el número total de caracteres escritos.
 *         Si ocurre un error de escritura, devuelve un número negativo.
 */
int fprintf(FILE *stream, const char *formato, ...);
```

### Ejemplo de escritura completo

```{code-block}c
:caption: Ejemplo de escritura y gestión de errores
:label: file-writing-example-advanced

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    // 1. Abrir el archivo en modo escritura ("w").
    FILE *salida = fopen("factura_completa.txt", "w");
    if (salida == NULL) {
        perror("Error al abrir el archivo 'factura_completa.txt'");
        return EXIT_FAILURE;
    }

    // 2. Escribir un encabezado usando fputs()
    // fputs() escribe una cadena de caracteres en el archivo.
    const char *encabezado = "--- Documento de Factura ---\n\n";
    if (fputs(encabezado, salida) == EOF) {
        perror("Error escribiendo el encabezado con fputs()")
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 3. Escribir datos formateados usando fprintf()
    // fprintf() permite escribir datos con formato (como printf, pero a un archivo).
    const char *item_1 = "Placa de Video RTX 4080";
    int cantidad_1 = 1;
    double precio_1 = 1200000.75;
    int chars_escritos_1 = fprintf(salida, "Item: %s\nCantidad: %d\nPrecio: %.2f ARS\n\n", item_1, cantidad_1, precio_1);
    if (chars_escritos_1 < 0) {
        perror("Error al formatear y escribir el item 1 con fprintf()")
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 4. Escribir un separador de línea usando fputc()
    // fputc() escribe un solo carácter en el archivo.
    int i;
    for (i = 0; i < 30; i++) {
        if (fputc('-', salida) == EOF) {
            perror("Error escribiendo separador con fputc()")
            fclose(salida);
            return EXIT_FAILURE;
        }
    }
    if (fputc('\n', salida) == EOF) {
        perror("Error escribiendo nueva linea con fputc()")
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 5. Escribir otro item usando una combinación de las tres funciones.
    const char *item_2 = "Memoria RAM DDR5 32GB";
    int cantidad_2 = 2;
    double precio_2 = 180000.00;

    if (fputs("Detalle del Item 2:\n", salida) == EOF) {
        perror("Error escribiendo detalle del item 2 con fputs()")
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Nombre: %s\n", item_2) < 0) {
        perror("Error escribiendo nombre del item 2 con fprintf()")
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Unidades: %d\n", cantidad_2) < 0) {
        perror("Error escribiendo unidades del item 2 con fprintf()")
        fclose(salida);
        return EXIT_FAILURE;
    }
    if (fprintf(salida, "  Valor Unitario: %.2f ARS\n", precio_2) < 0) {
        perror("Error escribiendo valor unitario del item 2 con fprintf()")
        fclose(salida);
        return EXIT_FAILURE;
    }

    // 6. Cerrar el archivo. Es crucial para asegurar que todos los datos en el búfer se guarden en el disco.
    if (fclose(salida) != 0) {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }

    printf("Archivo 'factura_completa.txt' creado y cerrado exitosamente.\n");
    return EXIT_SUCCESS;
}

```

:::{important} Búferes y `fflush()`
La E/S de archivos en C está _bufferizada_ por defecto para mejorar el
rendimiento. Los datos no se escriben al disco inmediatamente, sino que se
acumulan en un búfer. `fclose()` vacía (hace _flush_) este búfer
automáticamente. Si necesitás forzar la escritura sin cerrar el archivo, podés
usar `fflush(FILE *stream)`.
::: 

## Leyendo

### `fgetc`

La función `fgetc` se utiliza para leer un único carácter desde un flujo de archivo. Es la contraparte directa de `fputc`.

```{code-block}c
/**
 * @brief Lee un carácter desde un flujo de archivo.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo de entrada.
 *
 * @return Si la operación es exitosa, devuelve el carácter leído (promocionado a `int`).
 * @return Si se alcanza el final del archivo o si ocurre un error, devuelve `EOF`.
 */
int fgetc(FILE *stream);
```

### `fgets`

La función `fgets` se utiliza para leer una línea o una cadena de caracteres desde un flujo de archivo. Es más segura que la antigua función `gets` porque permite especificar un tamaño máximo para el búfer, evitando desbordamientos, una práctica recomendada por la regla {ref}`0x001Ch`.

```{code-block}c
/**
 * @brief Lee una cadena de caracteres desde un flujo de archivo.
 *
 * La lectura se detiene cuando se encuentra un carácter de nueva línea (`\n`),
 * cuando se alcanza el final del archivo (EOF), o después de que se hayan
 * leído (num - 1) caracteres. El carácter de nueva línea, si es leído,
 * se incluye en la cadena. Se añade un carácter nulo (`\0`) al final.
 *
 * @param cadena de caracteres donde se almacenará la cadena leída.
 * @param numero máximo de caracteres a ser leídos (incluyendo el carácter nulo final).
 * @param stream Puntero al objeto `FILE` que identifica el flujo de entrada.
 *
 * @return En caso de éxito, devuelve el puntero `str`.
 *         Si se alcanza el final del archivo antes de leer algún carácter, 
                o si ocurre un error, devuelve `NULL`.
 */
char *fgets(char *cadena, int numero, FILE *stream);
```

:::{warning} `numero` y `str`
El argumento `numero` debe ser igual o menor a la capacidad de la `cadena`, ya que de otra forma
la función provocará comportamiento no definido al escribir fuera del espacio de
memoria de la `cadena`.
:::

### `fscanf`

La función `fscanf` se utiliza para leer datos con formato desde un flujo de archivo. Funciona de manera análoga a `scanf`, pero operando sobre un archivo en lugar de la entrada estándar.

```{code-block}c
/**
 * @brief Lee datos con formato desde un flujo de archivo.
 *
 * @param[in] stream Puntero al objeto `FILE` que identifica el flujo de entrada.
 * @param[in] format Cadena de caracteres que especifica cómo interpretar los datos leídos.
 * @param[out] ... Lista variable de punteros a las variables donde se almacenarán los datos leídos.
 *
 * @return Devuelve el número de elementos de entrada asignados exitosamente.
 * @return Puede devolver `EOF` si se encuentra el final del archivo o ocurre un error antes de la primera asignación.
 */
int fscanf(FILE *stream, const char *format, ...);
```

### Leyendo un archivo, paso a paso

El código de ejemplo es una demostración de cómo leer un archivo de texto de
manera segura y eficiente en C. La estrategia principal es **separar la
entrada/salida (E/S) del procesamiento de datos**. En lugar de intentar
interpretar los datos directamente desde el archivo con `fscanf()`, lee el
archivo línea por línea en un espacio de memoria temporal (un búfer) y luego
analiza esa línea. Este enfoque es más resiliente a errores de formato.

A continuación, se descompone el código sección por sección.

#### 1. Inclusiones y definiciones (`#include` y `#define`)

```{code-block}c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 512
#define NOMBRE_ARCHIVO "factura.txt"

```

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

#### 2. Apertura del archivo y manejo de errores

```{code-block}c
FILE *entrada = fopen(NOMBRE_ARCHIVO, "r");
if (!entrada) {
    perror("No se pudo abrir 'factura.txt' para lectura");
    return EXIT_FAILURE;
}

```

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

#### 3. Bucle principal de lectura

```{code-block}c
char buffer[MAX_LINEA];
int numero_linea = 0;

while (fgets(buffer, sizeof(buffer), entrada) != NULL) {
    numero_linea++;
    // ... procesamiento de la línea ...
}

```

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
    ocurre un error de lectura. Mientras no devuelva `NULL`, el bucle `while`
    continúa ejecutándose, procesando una línea en cada iteración.

#### 4. Procesamiento y análisis de cada línea (Parsing)

```{code-block}c
if (strncmp(buffer, "Item:", 5) == 0) {
    char item_nombre[100];
    int cantidad;
    double precio;

    int campos_leidos = sscanf(buffer, "Item: %99[^,], Cantidad: %d, Precio: %lf ARS",
                               item_nombre, &cantidad, &precio);

    if (campos_leidos == 3) {
        // ... éxito ...
    } else {
        // ... fallo ...
    }
}

```

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

#### 5. Verificación post-lazo

```{code-block}c
if (ferror(entrada)) {
    perror("Ocurrió un error de lectura en el archivo");
} else if (feof(entrada)) {
    printf("\nProcesamiento completado. Se llegó al final del archivo.\n");
}

```

- Cuando el bucle `while (fgets(...) != NULL)` termina, hay dos posibles
  razones: se alcanzó el final del archivo (lo normal) o ocurrió un error de E/S
  (raro, pero posible). Es crucial distinguir entre ambos casos.
- **`ferror(entrada)`**: Esta función devuelve un valor verdadero si el
  indicador de error del _stream_ `entrada` está activado. Esto podría pasar si, 
  por ejemplo, el disco duro falla o se desconecta una unidad USB a mitad de la
  lectura.
- **`feof(entrada)`**: Devuelve un valor verdadero si el indicador de fin de
  archivo (_End-Of-File_) del _stream_ está activado. Esta es la condición de
  salida normal y esperada del bucle.

#### 6. Limpieza y cierre

```{code-block}c
clearerr(entrada);
fclose(entrada);
return EXIT_SUCCESS;

```

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

## Posicionamiento en Archivos: Acceso Aleatorio

No siempre querés leer un archivo secuencialmente. Las funciones de
posicionamiento te permiten moverte a cualquier punto del archivo.

### `ftell`

La función `ftell` se utiliza para obtener la posición actual del indicador de posición del fichero (el "cursor") dentro de un flujo. Devuelve esta posición como un número de bytes desde el inicio del archivo.

```{code-block}c
/**
 * @brief Obtiene la posición actual del indicador de posición del fichero.
 *
 * @param[in] stream Puntero al objeto `FILE` que identifica el flujo.
 *
 * @return Si es exitoso, devuelve el valor actual del indicador de posición.
 * @return En caso de error, devuelve -1L y la variable global `errno` se establece a un valor positivo.
 */
long int ftell(FILE *stream);
```

### `fseek`

La función `fseek` es la herramienta principal para mover el indicador de posición del fichero a una ubicación específica dentro del flujo. Permite un control preciso, moviendo el cursor un número determinado de bytes (`offset`) desde un punto de origen (`origin`).

```{code-block}c
/**
 * @brief Establece el indicador de posición del fichero a una nueva posición.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo.
 * @param offset Desplazamiento en bytes relativo al parámetro `origin`.
 * @param origin Posición desde donde se calcula el desplazamiento. Los valores pueden ser:
 * - `SEEK_SET`: Inicio del archivo.
 * - `SEEK_CUR`: Posición actual.
 * - `SEEK_END`: Final del archivo.
 *
 * @return Devuelve 0 si la operación es exitosa.
 *         Devuelve un valor distinto de cero en caso de error.
 */
int fseek(FILE *stream, long int offset, int origin);
```

### `rewind`

La función `rewind` es un caso especial y simplificado de `fseek`. Su única función es mover el indicador de posición del fichero de vuelta al inicio del archivo. Además, limpia cualquier indicador de error que pudiera tener el flujo.

```{code-block}c
/**
 * Reposiciona el indicador de posición del fichero al inicio del flujo.
 *
 * Esta función es funcionalmente equivalente a fseek(stream, 0L, SEEK_SET),
 * pero además borra el indicador de error del flujo.
 *
 * @param stream Puntero al objeto `FILE` que identifica el flujo.
 */
void rewind(FILE *stream);
```

### Ejemplo de uso

```{code-block}c
:caption: Uso de fseek() y ftell() para leer el último carácter
:label: fseek-example

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *archivo = fopen("factura.txt", "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return EXIT_FAILURE;
    }

    // Moverse al final del archivo
    if (fseek(archivo, 0, SEEK_END) != 0) {
        perror("Error en fseek a SEEK_END");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    // Obtener la posición actual, que es el tamaño del archivo
    long tamano = ftell(archivo);
    if (tamano == -1L) {
        perror("Error en ftell");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    printf("El archivo tiene %ld bytes.\n", tamano);

    // Moverse a la posición ANTERIOR al último byte para leerlo.
    // Si el archivo termina con \n, esto leerá el carácter previo.
    if (tamano > 1 && fseek(archivo, -2L, SEEK_END) != 0) {
        perror("Error en fseek para leer el último carácter");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    int ultimo_caracter = fgetc(archivo);
    if (ultimo_caracter != EOF) {
        printf("El último carácter imprimible del archivo es: '%c'\n", (char)ultimo_caracter);
    }

    // Volver al principio
    rewind(archivo);
    printf("Después de 'rewind', la posición es: %ld\n", ftell(archivo));

    fclose(archivo);
    return EXIT_SUCCESS;
}
```

## Cierre de Archivos: `fclose()`, el Paso Final

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
archivos y una violación de la regla de estilo {ref}`0x001Dh`.
::: 

Aunque parezca una simple formalidad, la llamada a `fclose()` también puede
fallar. Esto es particularmente cierto al escribir archivos: si el disco se
llena o el medio de almacenamiento se desconecta, el vaciado final del búfer (el
_flush_) fallará. Ignorar el valor de retorno de `fclose()` podría hacerte creer
que la operación fue exitosa cuando en realidad los últimos datos se perdieron.
La única forma de estar 100% seguro de que toda la información se guardó
correctamente es verificar el resultado del cierre.

```{code-block}c
:caption: Verificación del cierre de un archivo
:label: fclose-example

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *log_file = fopen("app.log", "a");
    if (log_file == NULL) {
        perror("No se pudo abrir el log");
        return EXIT_FAILURE;
    }

    fprintf(log_file, "El programa inició una operación crítica.\n");

    // ... el resto del programa ...

    fprintf(log_file, "La operación crítica finalizó.\n");

    // Cerramos el archivo y VERIFICAMOS el resultado.
    if (fclose(log_file) != 0) {
        // Si fclose falla, el error queda registrado en errno.
        perror("FALLO CRÍTICO al cerrar el archivo de log");
        // En un programa real, esto podría requerir una acción de emergencia,
        // ya que los últimos datos podrían no haberse guardado.
        return EXIT_FAILURE;
    }

    printf("Log escrito y cerrado correctamente.\n");
    return EXIT_SUCCESS;
}
```

## Funciones y variables para la gestión de errores

### `stderr`: El flujo de error estándar

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

### `errno`: El código del último error

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

### `perror(const char *s)`: El informador directo

`perror` es la forma más sencilla de reportar un error. Hace dos cosas:

1.  Imprime la cadena que le pasaste como argumento.
2.  Inmediatamente después, imprime dos puntos (`:`) y la descripción textual
    correspondiente al valor actual de `errno`.

**Situación de uso**: Ideal para herramientas de línea de comandos o scripts
donde necesitás un mensaje de error rápido, estándar y sin formato complejo. Es
menos flexible pero muy conveniente.

```{code-block}c
// Si errno es 2 ("No such file or directory")
perror("Error al leer el archivo de configuración");
// Salida en stderr:
// Error al leer el archivo de configuración: No such file or directory
```

### `strerror(int errnum)`: El traductor flexible

`strerror` te da más control. Toma un número de error (casi siempre le pasarás
`errno`) y devuelve un puntero a una cadena de caracteres (`char *`) con la
descripción del error. Vos sos responsable de cómo y dónde imprimir esa cadena.

**Situación de uso**: Imprescindible cuando necesitás:

- **Formatear el mensaje de error** de una manera específica.
- **Enviar el mensaje de error a un destino diferente** a `stderr`, como un
  archivo de log, un cuadro de diálogo en una GUI, o a través de la red.
- **Internacionalización**, donde podrías querer traducir el mensaje de error a
  diferentes idiomas.

```{code-block}c
// Si errno es 13 ("Permission denied")
fprintf(stderr, "[FATAL] Imposible acceder al recurso. Razón: %s\n", strerror(errno));
// Salida en stderr:
// [FATAL] Imposible acceder al recurso. Razón: Permission denied
```

## Ejercicios Propuestos

```{exercise}
:label: ejercicio_archivos_1
:enumerator: 1

**Escribir un diario personal**

Creá una función que reciba el nombre de un archivo y una cadena de texto. La función debe abrir el archivo en modo "append" (añadir) y escribir la cadena de texto seguida de un salto de línea. Asegurate de manejar todos los posibles errores de apertura, escritura y cierre.
```

````{solution} ejercicio_archivos_1
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR -1

/**
 * Agrega una entrada de texto a un archivo de diario.
 *
 * @param nombre_archivo La ruta del archivo de diario.
 *      #PRE: No puede ser NULL.
 * @param entrada El texto a agregar en el diario.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si la entrada se escribió correctamente, ERROR en caso contrario.
 *
 * @post El archivo especificado por nombre_archivo contendrá la nueva entrada
 *       al final del mismo, seguida de un salto de línea.
 */
int agregar_entrada_diario(const char *nombre_archivo, const char *entrada)
{
    int resultado_operacion = EXITO;
    FILE *p_archivo = NULL;

    // 1. Abrir el archivo en modo "append" (añadir)
    p_archivo = fopen(nombre_archivo, "a");
    if (p_archivo == NULL)
    {
        perror("Error al abrir el diario");
        resultado_operacion = ERROR;
    }

    // 2. Escribir la entrada y un salto de línea si la apertura fue exitosa
    if (resultado_operacion == EXITO)
    {
        if (fputs(entrada, p_archivo) == EOF)
        {
            perror("Error al escribir la entrada en el diario");
            resultado_operacion = ERROR;
        }
    }

    if (resultado_operacion == EXITO)
    {
        if (fputc('\n', p_archivo) == EOF)
        {
            perror("Error al escribir el salto de línea");
            resultado_operacion = ERROR;
        }
    }

    // 3. Cerrar el archivo, incluso si la escritura falló
    if (p_archivo != NULL)
    {
        if (fclose(p_archivo) != 0)
        {
            perror("Error al cerrar el diario");
            // Si ya había un error, se mantiene. Si no, se establece ahora.
            if (resultado_operacion == EXITO)
            {
                resultado_operacion = ERROR;
            }
        }
    }

    return resultado_operacion;
}

int main(void)
{
    const char *MI_DIARIO = "diario.txt";
    int resultado = 0;

    printf("Escribiendo primera entrada...\n");
    resultado = agregar_entrada_diario(MI_DIARIO, "Hoy fue un día soleado.");
    if (resultado == ERROR)
    {
        fprintf(stderr, "No se pudo escribir la primera entrada.\n");
        return EXIT_FAILURE;
    }

    printf("Escribiendo segunda entrada...\n");
    resultado = agregar_entrada_diario(MI_DIARIO, "Aprendí a manejar archivos en C.");
    if (resultado == ERROR)
    {
        fprintf(stderr, "No se pudo escribir la segunda entrada.\n");
        return EXIT_FAILURE;
    }

    printf("Entradas agregadas al diario '%s' con éxito.\n", MI_DIARIO);

    return EXIT_SUCCESS;
}

```
````

```{exercise}
:label: ejercicio_archivos_2
:enumerator: 2

**Contador de líneas**

Escribí una función que reciba el nombre de un archivo, lo lea y devuelva la cantidad de líneas que contiene. Una línea se define como una secuencia de caracteres terminada por un `\n`. La función debe devolver un número negativo en caso de error.
```

````{solution} ejercicio_archivos_2
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define MAX_LONGITUD_LINEA 1024
#define ERROR_APERTURA -1
#define ERROR_LECTURA -2

/**
 * Cuenta el número de líneas en un archivo de texto.
 *
 * @param nombre_archivo La ruta del archivo a leer.
 *      #PRE: No puede ser NULL.
 *
 * @returns El número de líneas contadas si la operación es exitosa.
 *          Retorna ERROR_APERTURA si el archivo no puede abrirse.
 *          Retorna ERROR_LECTURA si ocurre un error durante la lectura.
 *
 * @post El archivo no es modificado.
 */
int contar_lineas(const char *nombre_archivo)
{
    int cantidad_lineas = 0;
    FILE *p_archivo = NULL;
    char buffer[MAX_LONGITUD_LINEA];

    p_archivo = fopen(nombre_archivo, "r");
    if (p_archivo == NULL)
    {
        perror("Error al abrir el archivo para contar líneas");
        return ERROR_APERTURA;
    }

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        cantidad_lineas++;
    }

    // Después del bucle, verificar si salimos por error o por fin de archivo
    if (ferror(p_archivo))
    {
        perror("Error de lectura mientras se contaban las líneas");
        cantidad_lineas = ERROR_LECTURA; // Sobrescribimos el conteo con un código de error
    }

    if (fclose(p_archivo) != 0)
    {
        perror("Error al cerrar el archivo después de contar");
        if (cantidad_lineas >= 0) // No sobrescribir un error de lectura previo
        {
            cantidad_lineas = ERROR_APERTURA; // Reutilizamos código de error
        }
    }

    return cantidad_lineas;
}

int main(void)
{
    const char *NOMBRE_ARCHIVO = "diario.txt";
    // Crear un archivo de prueba primero
    FILE *p_archivo_prueba = fopen(NOMBRE_ARCHIVO, "w");
    if (p_archivo_prueba != NULL)
    {
        fputs("Primera línea.\n", p_archivo_prueba);
        fputs("Segunda línea.\n", p_archivo_prueba);
        fputs("Tercera línea.\n", p_archivo_prueba);
        fclose(p_archivo_prueba);
    }

    printf("Contando líneas en el archivo '%s'...\n", NOMBRE_ARCHIVO);
    int lineas = contar_lineas(NOMBRE_ARCHIVO);

    if (lineas >= 0)
    {
        printf("El archivo contiene %d líneas.\n", lineas);
    }
    else
    {
        fprintf(stderr, "Ocurrió un error al procesar el archivo (código: %d).\n", lineas);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```
````

```{exercise}
:label: ejercicio_archivos_3
:enumerator: 3

**Copiar un archivo de texto**

Implementá una función que copie el contenido de un archivo de origen a un archivo de destino. La función debe leer el archivo de origen línea por línea y escribir cada línea en el archivo de destino. Debe manejar errores para ambos archivos (apertura, lectura, escritura y cierre).
```

````{solution} ejercicio_archivos_3
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXITO 0
#define ERROR -1
#define MAX_BUFFER 4096

/**
 * Copia el contenido de un archivo de texto a otro.
 *
 * @param ruta_origen La ruta del archivo a leer.
 *      #PRE: No puede ser NULL.
 * @param ruta_destino La ruta del archivo donde se escribirá el contenido.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si la copia fue completamente exitosa, ERROR si ocurrió algún fallo.
 *
 * @post Si la operación es exitosa, el archivo en ruta_destino tendrá el mismo
 *       contenido que el de ruta_origen.
 */
int copiar_archivo(const char *ruta_origen, const char *ruta_destino)
{
    int estado_operacion = EXITO;
    FILE *p_origen = NULL;
    FILE *p_destino = NULL;
    char buffer[MAX_BUFFER];
    bool continuar_bucle = true;

    p_origen = fopen(ruta_origen, "r");
    if (p_origen == NULL)
    {
        perror("Error al abrir el archivo de origen");
        estado_operacion = ERROR;
    }

    if (estado_operacion == EXITO)
    {
        p_destino = fopen(ruta_destino, "w");
        if (p_destino == NULL)
        {
            perror("Error al abrir el archivo de destino");
            estado_operacion = ERROR;
        }
    }

    while (estado_operacion == EXITO && continuar_bucle)
    {
        if (fgets(buffer, sizeof(buffer), p_origen) != NULL)
        {
            if (fputs(buffer, p_destino) == EOF)
            {
                perror("Error al escribir en el archivo de destino");
                estado_operacion = ERROR;
            }
        }
        else
        {
            continuar_bucle = false; // Se terminó de leer o hubo un error
        }
    }

    // Verificar si el bucle terminó por un error de lectura
    if (p_origen != NULL && ferror(p_origen))
    {
        perror("Error de lectura en el archivo de origen");
        estado_operacion = ERROR;
    }

    // Cerrar ambos archivos, verificando errores en cada cierre
    if (p_origen != NULL && fclose(p_origen) != 0)
    {
        perror("Error al cerrar el archivo de origen");
        estado_operacion = ERROR;
    }
    if (p_destino != NULL && fclose(p_destino) != 0)
    {
        perror("Error al cerrar el archivo de destino");
        estado_operacion = ERROR;
    }

    return estado_operacion;
}

int main(void)
{
    const char *ARCHIVO_ORIGEN = "original.txt";
    const char *ARCHIVO_COPIA = "copia.txt";

    // Crear archivo original de prueba
    FILE *p_temp = fopen(ARCHIVO_ORIGEN, "w");
    if (p_temp != NULL)
    {
        fprintf(p_temp, "Línea 1 del original.\n");
        fprintf(p_temp, "Línea 2 con algunos caracteres especiales: áéíóú.\n");
        fprintf(p_temp, "Fin del archivo original.\n");
        fclose(p_temp);
    }

    printf("Copiando '%s' a '%s'...\n", ARCHIVO_ORIGEN, ARCHIVO_COPIA);
    if (copiar_archivo(ARCHIVO_ORIGEN, ARCHIVO_COPIA) == EXITO)
    {
        printf("Archivo copiado con éxito.\n");
    }
    else
    {
        fprintf(stderr, "La copia del archivo falló.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```
````

```{exercise}
:label: ejercicio_archivos_4
:enumerator: 4

**Registrar eventos en un log**

Crea una función `registrar_evento` que reciba un mensaje y lo añada a un archivo llamado `eventos.log`. La función debe asegurarse de que cada mensaje nuevo se agregue al final del archivo, sin borrar el contenido anterior. Por simplicidad, no es necesario agregar una marca de tiempo.
```

````{solution} ejercicio_archivos_4
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR -1
#define ARCHIVO_LOG "eventos.log"

/**
 * Registra un mensaje de evento en un archivo de log.
 *
 * @param mensaje El mensaje a registrar.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si el evento se registró correctamente, ERROR en caso contrario.
 *
 * @post El archivo de log contendrá el nuevo mensaje al final.
 */
int registrar_evento(const char *mensaje)
{
    int resultado = EXITO;
    FILE *p_log = fopen(ARCHIVO_LOG, "a");

    if (p_log == NULL)
    {
        perror("Error al abrir el archivo de log");
        resultado = ERROR;
    }
    else
    {
        // Escribir el mensaje y un salto de línea
        if (fprintf(p_log, "%s\n", mensaje) < 0)
        {
            perror("Error al escribir en el archivo de log");
            resultado = ERROR;
        }

        // Cerrar el archivo
        if (fclose(p_log) != 0)
        {
            perror("Error al cerrar el archivo de log");
            resultado = ERROR;
        }
    }

    return resultado;
}

int main(void)
{
    printf("Registrando eventos...\n");

    if (registrar_evento("[INFO] El sistema ha iniciado.") != EXITO)
    {
        fprintf(stderr, "Fallo al registrar el primer evento.\n");
        return EXIT_FAILURE;
    }

    if (registrar_evento("[WARN] El disco está casi lleno.") != EXITO)
    {
        fprintf(stderr, "Fallo al registrar el segundo evento.\n");
        return EXIT_FAILURE;
    }

    if (registrar_evento("[FATAL] No se pudo conectar a la base de datos.") != EXITO)
    {
        fprintf(stderr, "Fallo al registrar el tercer evento.\n");
        return EXIT_FAILURE;
    }

    printf("Eventos registrados en '%s'.\n", ARCHIVO_LOG);

    return EXIT_SUCCESS;
}
```
````

```{exercise}
:label: ejercicio_archivos_5
:enumerator: 5

**Procesar un archivo CSV de ventas**

Escribí una función que lea un archivo `ventas.csv` con el formato `producto,precio,cantidad`. Por cada línea, debe calcular el total (precio * cantidad) y mostrarlo en pantalla. La función debe ignorar líneas mal formadas o vacías.

**Ejemplo de `ventas.csv`:**
```csv
Teclado Mecanico,150.50,2
Mouse Gamer,75.00,5
Monitor 24 pulgadas,300.25,1
# Esto es un comentario, debe ser ignorado
Webcam,no_es_un_precio,3
```

````{solution} ejercicio_archivos_5
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1
#define MAX_LINEA 256
#define MAX_PRODUCTO 100

/**
 * Procesa un archivo CSV de ventas, calculando e imprimiendo el total por línea.
 *
 * @param nombre_archivo La ruta del archivo CSV a procesar.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si el archivo se procesó (incluso si algunas líneas fallaron),
 *          ERROR si no se pudo abrir el archivo o hubo un error de lectura irrecuperable.
 *
 * @post Se imprimirán en la salida estándar los totales de las líneas bien formadas.
 */
int procesar_ventas(const char *nombre_archivo)
{
    int estado_general = EXITO;
    FILE *p_archivo = fopen(nombre_archivo, "r");
    char buffer[MAX_LINEA];
    size_t numero_linea = 0;

    if (p_archivo == NULL)
    {
        perror("No se pudo abrir el archivo de ventas");
        return ERROR;
    }

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        numero_linea++;

        // Ignorar líneas vacías o que son comentarios
        if (buffer[0] == '\n' || buffer[0] == '#')
        {
            continue; // Esta es una excepción permitida a la regla 0x0006h
        }

        char nombre_producto[MAX_PRODUCTO];
        double precio = 0.0;
        int cantidad = 0;

        // Usar sscanf para parsear la línea. Formato: string-hasta-coma,double,int
        int campos_leidos = sscanf(buffer, "%99[^,],%lf,%d", nombre_producto, &precio, &cantidad);

        if (campos_leidos == 3)
        {
            double total_linea = precio * (double)cantidad;
            printf("Línea %zu: Producto '%s', Total: %.2f\n", numero_linea, nombre_producto, total_linea);
        }
        else
        {
            fprintf(stderr, "[Advertencia] Línea %zu mal formada: %s", numero_linea, buffer);
        }
    }

    if (ferror(p_archivo))
    {
        perror("Ocurrió un error de lectura");
        estado_general = ERROR;
    }

    if (fclose(p_archivo) != 0)
    {
        perror("Error al cerrar el archivo de ventas");
        estado_general = ERROR;
    }

    return estado_general;
}

int main(void)
{
    const char *ARCHIVO_VENTAS = "ventas.csv";

    // Crear archivo de ventas de prueba
    FILE *p_temp = fopen(ARCHIVO_VENTAS, "w");
    if (p_temp != NULL)
    {
        fprintf(p_temp, "Teclado Mecanico,150.50,2\n");
        fprintf(p_temp, "Mouse Gamer,75.00,5\n");
        fprintf(p_temp, "\n"); // Línea vacía
        fprintf(p_temp, "Monitor 24 pulgadas,300.25,1\n");
        fprintf(p_temp, "# Esto es un comentario, debe ser ignorado\n");
        fprintf(p_temp, "Webcam,no_es_un_precio,3\n"); // Línea mal formada
        fclose(p_temp);
    }

    printf("Procesando archivo '%s'...\n", ARCHIVO_VENTAS);
    if (procesar_ventas(ARCHIVO_VENTAS) == ERROR)
    {
        fprintf(stderr, "No se pudo completar el procesamiento del archivo.\n");
        return EXIT_FAILURE;
    }

    printf("\nProcesamiento finalizado.\n");
    return EXIT_SUCCESS;
}

```

:::{note} Excepción a la regla `0x0006h`
En la solución del ejercicio 5, se utiliza `continue` para saltar líneas vacías o comentarios. Si bien la regla de estilo general es evitar `break` y `continue`, este es un caso de uso común y aceptado donde su aplicación simplifica la lógica y mejora la legibilidad, al evitar un nivel de anidamiento (`if`) para el resto del código del bucle. Es una excepción pragmática a la regla.
:::

````

## Glosario

:::{glossary}
Búfer
: En el contexto de la programación y los sistemas operativos, un **búfer** (del
  inglés _buffer_) es una región de memoria física (generalmente en la `RAM`) que
  se utiliza para almacenar datos de forma temporal mientras se transfieren de un
  lugar a otro.

    El objetivo principal de un búfer es optimizar el rendimiento y gestionar las diferencias de velocidad entre dos procesos o dispositivos. Por ejemplo, en las operaciones de entrada/salida (`I/O`), los datos se acumulan en un búfer antes de ser procesados o escritos en un dispositivo físico como un disco duro. Esto permite que el sistema realice menos operaciones de escritura/lectura, pero de mayor tamaño, lo cual es significativamente más eficiente.

    Pensá en el proceso de escribir en un archivo como si fuera enviar una carta. Escribir carácter por carácter directamente al disco (sin búfer) sería como llevar cada letra individualmente hasta el correo. Es ineficiente y lento.

    Usar un búfer es como escribir la carta completa en una hoja de papel (el búfer en la memoria). Una vez que terminaste la carta (el búfer se llenó o cerraste el archivo), la llevás al correo en un solo viaje. Este método es mucho más rápido y organizado.

    :::{figure} 8/buffer_concept.svg
    :name: fig-buffer-concept
    :alt: Concepto de búfer en operaciones de archivos

    Comparación entre operaciones sin búfer (ineficientes) y con búfer (eficientes), mostrando cómo el búfer optimiza las operaciones de E/S.
    :::
:::
