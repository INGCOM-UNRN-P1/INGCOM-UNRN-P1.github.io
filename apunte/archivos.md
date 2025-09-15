---
title: Archivos
description: Una guía exhaustiva sobre cómo abrir, leer, escribir, posicionar y gestionar errores de forma robusta al trabajar con archivos de texto en el lenguaje de programación C.
---

# Trabajo con Archivos de Texto en C: Guía Exhaustiva

El manejo de archivos es una capacidad fundamental en la mayoría de las aplicaciones. En C, la librería estándar de E/S (`stdio.h`) provee un conjunto robusto y de bajo nivel para interactuar con el sistema de archivos. Este apunte amplía el manejo de archivos de texto, cubriendo no solo las operaciones básicas sino también el posicionamiento dentro del archivo y, de manera crucial, una gestión de errores detallada y profesional.

## El Puntero `FILE`: Tu Conexión al Archivo

Toda operación sobre archivos en C se realiza a través de un puntero a una estructura especial y opaca llamada `FILE`. Esta estructura, definida en la biblioteca estándar `<stdio.h>`, actúa como un intermediario que contiene toda la información de estado necesaria para gestionar el flujo de datos ( _stream_ ) hacia y desde el archivo.

Dentro de esta estructura, el sistema operativo y la biblioteca estándar de C manejan los detalles como:
- El **descriptor de archivo** a bajo nivel y en el sistema operativo.
- La ubicación del **búfer de E/S** en memoria para optimizar lecturas y escrituras.
- **Indicadores de estado**, como los flags de error y de fin de archivo (EOF).
- La **posición actual** del cursor dentro del archivo.

Al ser una **estructura opaca**, vos no necesitás conocer ni manipular sus miembros internos directamente. En su lugar, interactuás con el archivo a través de funciones que reciben un puntero a esta estructura.

Para declarar un puntero a `FILE`, la sintaxis es simple:

```c
FILE *puntero_archivo;
```

Este puntero, una vez que la función `fopen()` lo inicializa exitosamente, se convierte en tu identificador único para interactuar con ese archivo específico hasta que lo cierres con `fclose()`.

### Una Analogía con Arreglos y Punteros

La idea de usar un puntero para manejar una entidad compleja puede resultarte familiar si ya trabajaste con arreglos. De hecho, el concepto es bastante similar y se relaciona directamente con el manejo de punteros, un tema fundamental que exploraremos en detalle más adelante.

- En un **arreglo**, el nombre del arreglo actúa como un puntero a la dirección de memoria de su primer elemento. No contiene todos los datos, sino que te da el punto de acceso para empezar a recorrerlos.
- De manera análoga, un puntero `FILE *` no es el archivo en sí. Es un puntero a una estructura en memoria que "sabe" todo sobre el archivo y cómo comunicarse con él.

:::{seealso} El Rol de los Punteros

El manejo de punteros es un pilar en la programación en C. Próximamente, profundizaremos en cómo los punteros nos permiten manipular direcciones de memoria directamente, lo cual es la base para entender cómo funcionan los arreglos, la gestión de memoria dinámica y, como vimos aquí, la interacción con sistemas externos como el sistema de archivos.

:::

Por ahora, es suficiente que entiendas que `puntero_archivo` es tu "manija" o "handle" para leer, escribir y manipular el archivo que abriste.

## Apertura de Archivos: `fopen()`

La función `fopen()` es el punto de entrada crucial para cualquier operación de archivo. Actúa como un puente entre tu programa y el sistema de archivos del sistema operativo. Su tarea es solicitar el acceso a un archivo específico en un modo determinado.

Si el sistema operativo concede el acceso, `fopen()` reserva los recursos necesarios, inicializa la estructura `FILE` con la información pertinente y te devuelve un puntero a dicha estructura. Si por alguna razón la operación falla (el archivo no existe, no tenés permisos, etc.), la función te devolverá `NULL`.

:::{important} ¡La verificación con `NULL` es obligatoria!

Nunca asumas que `fopen()` tendrá éxito. Una de las fuentes más comunes de errores y caídas inesperadas en programas de C es no verificar si el puntero devuelto es `NULL` antes de intentar usarlo.

Esta función puede fallar de muchas formas y que no dependen de nuestro programa, con situaciones como, problemas de permisos, si el archivo existe (o no)
, o algún fallo en el medio de almacenamiento en sí.

:::

La sintaxis, definida en `<stdio.h>`, es la siguiente:

```c
:caption: Sintaxis de fopen()
:label: fopen-syntax

FILE *fopen(const char *pathname, const char *mode);
```

- `const char *pathname`: Es una cadena de caracteres que representa la ruta al archivo. Puede ser una ruta relativa (ej. `"datos.txt"`) o absoluta (ej. `"/home/usuario/documentos/datos.txt"`).
- `const char *mode`: Es una cadena corta que especifica el modo de acceso, definiendo qué operaciones estarán permitidas sobre el archivo.

### Modos de apertura

Elegir el modo correcto es fundamental, ya que determina el comportamiento del puntero del archivo y lo que sucede con el contenido que ya estaba en el archivo.

```{list-table} Modos de apertura de archivos
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

Cuando `fopen()` devuelve `NULL`, la variable global `errno` (definida en `<errno.h>`) se establece con un código de error específico del sistema. Para mostrar un mensaje de error legible por humanos, podés usar la función `perror()`.

```c
:caption: Verificación de errores al abrir un archivo
:label: fopen-error-handling

#include <stdio.h>
#include <errno.h> // Necesario para perror()

int main() {
    FILE *pArchivo;
    pArchivo = fopen("archivo_inexistente.txt", "r");

    if (pArchivo == NULL) {
        // Imprime un mensaje descriptivo del último error ocurrido
        perror("Error al intentar abrir el archivo");
        return 1; // Termina el programa con un código de error
    }

    printf("Archivo abierto con éxito.\n");
    // ... operaciones con el archivo ...
    fclose(pArchivo);

    return 0;
}
```
Si ejecutaras este código, `perror()` probablemente imprimiría algo como: `Error al intentar abrir el archivo: No such file or directory`.

### Binario vs. Texto

Por defecto, los modos listados arriba operan en **modo texto**. Esto implica que el sistema puede realizar conversiones automáticas de los finales de línea para adaptarse a la convención de la plataforma (por ejemplo, convertir `\n` a `\r\n` en Windows).

Para trabajar con archivos binarios —como imágenes, audio, ejecutables o cualquier archivo donde cada byte importa—, es crucial evitar estas traducciones. Para ello, simplemente agregá una `b` al final del modo (ej. `"rb"`, `"wb+"`, `"ab"`).

:::{warning} Corrupción de Datos

Abrir un archivo no textual en modo texto puede corromper irreversiblemente los datos, ya que secuencias de bytes que casualmente coincidan con caracteres especiales (como el de fin de línea) serán alteradas. Usá siempre el modo binario para archivos no textuales.

:::

Trabajar con archivos binarios es importante, pero complejo y requiere de un par de cosas más que no hemos visto del lenguaje. Para quienes deseen chusmear como se hace, en la sección extra, hay un apunte referido a como trabajar de esta forma los archivos.

### Descomposición del Código de Ejemplo

Analicemos en detalle el código de ejemplo y las herramientas que utiliza. Cada componente juega un rol específico para crear un programa robusto y que informe adecuadamente sobre los problemas que encuentre.

El bloque de código presentado es un paradigma de cómo se debe gestionar la apertura de archivos. Vamos a desglosarlo línea por línea.

```c
// Inclusiones de cabeceras necesarias
#include <stdio.h>   // Para FILE, fopen, fprintf, perror, stderr
#include <stdlib.h>  // Para EXIT_FAILURE, EXIT_SUCCESS
#include <errno.h>   // Para la variable global 'errno'
#include <string.h>  // Para la función strerror()

int main(void) {
    // 1. Definición del objetivo
    const char *nombreArchivo = "/ruta/protegida/no_existe.txt";

    // 2. Intento de operación
    FILE *archivo = fopen(nombreArchivo, "r");

    // 3. Verificación y manejo del error
    if (archivo == NULL) {
        // 3a. Informar el contexto del error
        fprintf(stderr, "Error al abrir el archivo '%s'.\n", nombreArchivo);

        // 3b. Informar el código de error numérico (útil para debugging)
        fprintf(stderr, "Código de error (errno): %d\n", errno);

        // 3c. Mostrar el error legible (Opción 1: simple)
        perror("Razón (usando perror)");

        // 3d. Mostrar el error legible (Opción 2: flexible)
        fprintf(stderr, "Razón (usando strerror): %s\n", strerror(errno));

        // 3e. Terminar el programa con un estado de fallo
        return EXIT_FAILURE;
    }

    // 4. Código que se ejecuta en caso de éxito
    printf("Archivo '%s' abierto correctamente. Procediendo a cerrarlo.\n", nombreArchivo);
    fclose(archivo);
    return EXIT_SUCCESS;
}
```

1.  **Definición del objetivo**: Se declara una cadena con la ruta del archivo. Usar una ruta deliberadamente incorrecta o inaccesible es una buena forma de probar el código de manejo de errores.
2.  **Intento de operación**: Se llama a `fopen()`. Aquí es donde el sistema operativo intenta realizar la acción solicitada. Si falla, `archivo` será `NULL` y `errno` se establecerá.
3.  **Verificación y manejo del error**: Este es el bloque crucial. El `if (archivo == NULL)` captura el fallo.
    * **3a y 3b**: Usando `fprintf` con `stderr`, informamos al usuario qué estábamos intentando hacer y cuál es el código de error interno. Esto es vital para el diagnóstico.
    * **3c y 3d**: Se demuestran las dos formas de traducir `errno` a un mensaje humano.
    * **3e**: El programa termina, pero informando al sistema operativo (y a cualquier script que lo haya llamado) que la ejecución no fue exitosa.
4.  **Éxito**: Si el `if` no se ejecuta, significa que `fopen()` tuvo éxito y podemos proceder con las operaciones sobre el archivo.


### Funciones y variables para la gestión de errores

#### `stderr`: El Flujo de Error Estándar

En C, tenés tres flujos de comunicación estándar:
- `stdin` (entrada estándar): Generalmente el teclado.
- `stdout` (salida estándar): Generalmente la pantalla.
- `stderr` (error estándar): También, generalmente la pantalla.

**¿Por qué separar `stdout` de `stderr`?** Para poder redirigir la salida. Imaginate que ejecutás tu programa y guardás el resultado en un archivo:
`./mi_programa > salida.txt`

Si usaras `printf` (que escribe en `stdout`) para los errores, estos quedarían mezclados con los datos correctos en `salida.txt`, haciendo difícil su detección. Al usar `fprintf(stderr, ...)` o `perror()`, los mensajes de error se imprimen en la consola por separado, permitiéndote ver los problemas incluso cuando la salida "buena" está siendo redirigida.

**Uso general**: Siempre utilizá `stderr` para mensajes de error, diagnósticos o advertencias.

#### `errno`: El Código del Último Error

`errno` es una variable global (técnicamente, una macro que se expande a una expresión modificable) definida en `<errno.h>`. Las funciones de sistema y de la biblioteca estándar de C la utilizan para comunicar *qué* salió mal cuando fallan.

- **No lo reinicies**: Nunca asignes `errno = 0;` manualmente. Su valor solo es válido inmediatamente después de que una función falle.
- **No lo verifiques si la función tuvo éxito**: Si `fopen()` no devuelve `NULL`, el valor de `errno` es irrelevante y podría contener un valor "viejo" de un error anterior.

**Uso general**: Consultá `errno` solo después de haber detectado que una función ha fallado (por ejemplo, verificando un retorno `NULL` o `-1`).

#### `perror(const char *s)`: El informador directo

`perror` es la forma más sencilla de reportar un error. Hace dos cosas:
1.  Imprime la cadena que le pasaste como argumento.
2.  Inmediatamente después, imprime dos puntos (`:`) y la descripción textual correspondiente al valor actual de `errno`.

**Situación de uso**: Ideal para herramientas de línea de comandos o scripts donde necesitás un mensaje de error rápido, estándar y sin formato complejo. Es menos flexible pero muy conveniente.

```c
// Si errno es 2 ("No such file or directory")
perror("Error al leer el archivo de configuración");
// Salida en stderr:
// Error al leer el archivo de configuración: No such file or directory
```

#### `strerror(int errnum)`: El traductor flexible

`strerror` te da más control. Toma un número de error (casi siempre le pasarás `errno`) y devuelve un puntero a una cadena de caracteres (`char *`) con la descripción del error. Vos sos responsable de cómo y dónde imprimir esa cadena.

**Situación de uso**: Imprescindible cuando necesitás:
- **Formatear el mensaje de error** de una manera específica.
- **Enviar el mensaje de error a un destino diferente** a `stderr`, como un archivo de log, un cuadro de diálogo en una GUI, o a través de la red.
- **Internacionalización**, donde podrías querer traducir el mensaje de error a diferentes idiomas.

```c
// Si errno es 13 ("Permission denied")
fprintf(stderr, "[FATAL] Imposible acceder al recurso. Razón: %s\n", strerror(errno));
// Salida en stderr:
// [FATAL] Imposible acceder al recurso. Razón: Permission denied
```
## Escritura en Archivos: Creando Contenido

### Escritura con y sin Formato

* **`fputc(int c, FILE *stream)`**: Escribe un solo carácter. Devuelve el carácter escrito o `EOF` en caso de error.
* **`fputs(const char *s, FILE *stream)`**: Escribe una cadena. **No añade** el carácter de nueva línea (`\n`) automáticamente. Devuelve un valor no negativo si tiene éxito, o `EOF` en caso de error.
* **`fprintf(FILE *stream, const char *format, ...)`**: La más versátil. Escribe datos con formato, análogamente a `printf()`. Devuelve el número de caracteres escritos, o un valor negativo si ocurre un error.

### Ejemplo completo

```{code-block} c
:caption: Ejemplo de escritura y gestión de errores
:label: file-writing-example-advanced

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    FILE *salida = fopen("factura.txt", "w");
    if (salida == NULL) {
        perror("No se pudo crear 'factura.txt'");
        return EXIT_FAILURE;
    }

    if (fputs("--- Encabezado de Factura ---\n", salida) == EOF) {
        perror("Error escribiendo el encabezado");
        fclose(salida);
        return EXIT_FAILURE;
    }

    const char *item = "Placa de Video";
    int cantidad = 2;
    double precio = 850000.50;

    int chars_escritos = fprintf(salida, "Item: %s, Cantidad: %d, Precio: %.2f ARS\n", item, cantidad, precio);

    if (chars_escritos < 0) {
        perror("Error al formatear y escribir el item");
        fclose(salida);
        return EXIT_FAILURE;
    }

    printf("Se escribieron %d caracteres en la factura.\n", chars_escritos);

    // Es crucial cerrar el archivo para asegurar que los búferes se escriban en disco.
    if (fclose(salida) != 0) {
        perror("Error al cerrar el archivo de factura");
        return EXIT_FAILURE;
    }

    printf("Archivo 'factura.txt' creado y cerrado exitosamente.\n");
    return EXIT_SUCCESS;
}
```

:::{important} Búferes y `fflush()`

La E/S de archivos en C está _bufferizada_ por defecto para mejorar el rendimiento. Los datos no se escriben al disco inmediatamente, sino que se acumulan en un búfer. `fclose()` vacía (hace _flush_) este búfer automáticamente. Si necesitás forzar la escritura sin cerrar el archivo, podés usar `fflush(FILE *stream)`.

:::

### Lectura de archivos robusta

El código de ejemplo es una demostración de cómo leer un archivo de texto de manera segura y eficiente en C. La estrategia principal es **separar la entrada/salida (E/S) del procesamiento de datos**. En lugar de intentar interpretar los datos directamente desde el archivo con `fscanf()`, lee el archivo línea por línea en un espacio de memoria temporal (un búfer) y luego analiza esa línea. Este enfoque es más resiliente a errores de formato.

A continuación, se descompone el código sección por sección.

#### 1. Inclusiones y definiciones (`#include` y `#define`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 512
#define NOMBRE_ARCHIVO "factura.txt"

```

-   **`#include <stdio.h>`**: Incluye la biblioteca estándar de entrada/salida. Es fundamental porque nos da acceso a funciones como `fopen()`, `fgets()`, `printf()`, `perror()`, `fclose()`, `ferror()` y `feof()`.

-   **`#include <stdlib.h>`**: Proporciona acceso a utilidades generales, incluyendo las macros `EXIT_SUCCESS` y `EXIT_FAILURE`, que son una forma estándar y portable de indicar si el programa terminó con o sin errores.

-   **`#include <string.h>`**: Incluye la biblioteca para manipulación de cadenas de caracteres. La usamos aquí para la función `strncmp()`.

-   **`#define MAX_LINEA 512`**: Define una constante para el tamaño máximo de línea que esperamos leer. Usar una constante hace que el código sea más legible y fácil de mantener. Si necesitáramos cambiar el tamaño del búfer, solo lo hacemos acá. El valor de 512 bytes es una elección común y razonable para muchas aplicaciones.

-   **`#define NOMBRE_ARCHIVO "factura.txt"`**: Define el nombre del archivo que vamos a leer. Al igual que con `MAX_LINEA`, esto centraliza la configuración y mejora la mantenibilidad del código.

#### 2\. Apertura del archivo y manejo de errores

```c
FILE *entrada = fopen(NOMBRE_ARCHIVO, "r");
if (!entrada) {
    perror("No se pudo abrir 'factura.txt' para lectura");
    return EXIT_FAILURE;
}

```

-   **`FILE *entrada = fopen(NOMBRE_ARCHIVO, "r");`**: Esta línea intenta abrir el archivo especificado por `NOMBRE_ARCHIVO` en modo lectura (`"r"`). Si tiene éxito, `fopen()` devuelve un puntero a una estructura `FILE`, que es un *handle* o manejador que representa el flujo de datos (el *stream*). Si falla (por ejemplo, porque el archivo no existe o no tenemos permisos de lectura), devuelve `NULL`.

-   **`if (!entrada) { ... }`**: Esta es la comprobación de errores **crítica**. *Nunca* debés asumir que `fopen()` funcionó. Si `entrada` es `NULL` (lo que `!entrada` evalúa como verdadero), el programa no puede continuar.

-   **`perror(...)`**: Es una función muy útil para reportar errores. Imprime en la salida de error estándar (`stderr`) el mensaje que le pasás como argumento, seguido de dos puntos y una descripción textual del último error ocurrido en el sistema. Por ejemplo, si el archivo no existe, podría imprimir: `No se pudo abrir 'factura.txt' para lectura: No such file or directory`.

-   **`return EXIT_FAILURE;`**: Termina el programa indicando al sistema operativo que ocurrió un error.

#### 3\. Bucle principal de lectura

```c
char buffer[MAX_LINEA];
int numero_linea = 0;

while (fgets(buffer, sizeof(buffer), entrada) != NULL) {
    numero_linea++;
    // ... procesamiento de la línea ...
}

```

-   **`char buffer[MAX_LINEA];`**: Declara el búfer, un array de caracteres donde `fgets()` almacenará cada línea leída del archivo.
-   **`while (fgets(...) != NULL)`**: Este es el corazón del programa.
    -   **`fgets(buffer, sizeof(buffer), entrada)`**: Intenta leer una línea del flujo `entrada`.
        -   `buffer`: El destino donde se guardará la línea.
        -   `sizeof(buffer)`: El tamaño máximo a leer (en este caso, 512). `fgets()` es segura porque nunca escribirá más allá de este límite, previniendo desbordamientos de búfer. Leerá hasta `sizeof(buffer) - 1` caracteres y agregará un `\0` al final.
        -   `entrada`: El flujo de archivo del cual leer.
    -   La función `fgets()` devuelve `NULL` cuando llega al final del archivo o si ocurre un error de lectura. Mientras no devuelva `NULL`, el bucle `while` continúa ejecutándose, procesando una línea en cada iteración.

#### 4\. Procesamiento y análisis de cada línea (Parsing)

```c
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

-   **`if (strncmp(buffer, "Item:", 5) == 0)`**: Antes de intentar un análisis costoso, se realiza una verificación rápida y eficiente. `strncmp()` compara los primeros `5` caracteres del `buffer` con la cadena `"Item:"`. Si son iguales, la función devuelve `0`, y procedemos a analizar la línea. Esto nos permite ignorar líneas en blanco o comentarios de forma eficiente.
-   **`sscanf(buffer, "...", ...)`**: Esta es la función clave para el *parsing*. A diferencia de `fscanf()`, que lee desde un archivo, `sscanf()` lee desde una cadena de caracteres que ya está en memoria (el `buffer`).
    -   **La cadena de formato**: Es la plantilla que `sscanf()` usa para interpretar los datos.
        -   `"Item: "` y `", Cantidad: "` y `", Precio: "` y `" ARS"`: Son caracteres literales. La cadena en el búfer debe coincidir exactamente con estos literales (incluyendo los espacios).
        -   **`%99[^,]`**: Este es un especificador de formato avanzado y muy seguro.
            -   `%[...]`: Indica que se debe leer un conjunto de caracteres (un *scanset*).
            -   `^,`: El `^` niega el conjunto. Esto significa "leer todos los caracteres *excepto* la coma".
            -   `99`: Es un limitador de ancho. Le dice a `sscanf()` que lea como máximo 99 caracteres para este campo. Esto previene un desbordamiento del búfer `item_nombre` (que tiene tamaño 100, dejando espacio para el `\0`).
        -   **`%d`**: Lee un número entero decimal.
        -   **`%lf`**: Lee un número de punto flotante de tipo `double` (la `l` es de `long float`, que significa `double`).
-   **`int campos_leidos = sscanf(...)`**: `sscanf()` devuelve el número de campos que pudo asignar con éxito. Guardamos este valor.
-   **`if (campos_leidos == 3)`**: Comprobamos si `sscanf()` pudo leer y asignar los 3 campos que esperábamos (`item_nombre`, `cantidad` y `precio`). Si es así, el *parsing* fue exitoso. Si no, la línea no tenía el formato correcto y lo informamos como una advertencia.

#### 5\. Verificación post-lazo

```c
if (ferror(entrada)) {
    perror("Ocurrió un error de lectura en el archivo");
} else if (feof(entrada)) {
    printf("\nProcesamiento completado. Se llegó al final del archivo.\n");
}

```

-   Cuando el bucle `while (fgets(...) != NULL)` termina, hay dos posibles razones: se alcanzó el final del archivo (lo normal) o ocurrió un error de E/S (raro, pero posible). Es crucial distinguir entre ambos casos.
-   **`ferror(entrada)`**: Esta función devuelve un valor verdadero si el indicador de error del *stream* `entrada` está activado. Esto podría pasar si, por ejemplo, el disco duro falla o se desconecta una unidad USB a mitad de la lectura.
-   **`feof(entrada)`**: Devuelve un valor verdadero si el indicador de fin de archivo (*End-Of-File*) del *stream* está activado. Esta es la condición de salida normal y esperada del bucle.

#### 6\. Limpieza y cierre

```c
clearerr(entrada);
fclose(entrada);
return EXIT_SUCCESS;

```

-   **`clearerr(entrada)`**: Limpia los indicadores de error y de fin de archivo del *stream*. Es una buena práctica, aunque en este caso el programa está a punto de terminar y no es estrictamente necesario.
-   **`fclose(entrada)`**: Cierra el archivo. Esto es **fundamental**. Libera los recursos que el sistema operativo había asignado para manejar el archivo, como el puntero a `FILE` y los búferes internos. No cerrar un archivo puede llevar a la pérdida de datos (especialmente en escritura) y al agotamiento de recursos del sistema.
-   **`return EXIT_SUCCESS;`**: Informa al sistema operativo que el programa terminó exitosamente.

## Posicionamiento en Archivos: Acceso Aleatorio

No siempre querés leer un archivo secuencialmente. Las funciones de posicionamiento te permiten moverte a cualquier punto del archivo.

* **`ftell(FILE *stream)`**: Devuelve la posición actual del puntero en el archivo (como un `long int`).
* **`rewind(FILE *stream)`**: Mueve el puntero al inicio del archivo. Es equivalente a `fseek(stream, 0L, SEEK_SET)`, pero también limpia el indicador de error.
* **`fseek(FILE *stream, long int offset, int whence)`**: La función principal para moverse. Mueve el puntero a una nueva posición.
    * `offset`: El número de bytes a moverse.
    * `whence`: El punto de origen desde donde se cuenta el `offset`. Puede ser:
        * `SEEK_SET`: Desde el inicio del archivo.
        * `SEEK_CUR`: Desde la posición actual.
        * `SEEK_END`: Desde el final del archivo.

```{code-block} c
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

    // Moverse a la posición ANTERIOR al último byte (recordar el carácter nulo en algunos casos)
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

`fclose(FILE *stream)` disocia el archivo del puntero `FILE`. Es una operación crítica que:
1.  **Vacía el búfer de salida**: Asegura que todos los datos escritos con funciones como `fprintf` o `fputs` se escriban físicamente en el disco.
2.  **Libera recursos del sistema**: El sistema operativo tiene un límite en la cantidad de archivos que un proceso puede tener abiertos simultáneamente.

Devuelve `0` si tiene éxito y `EOF` si ocurre un error.

```{important}
Siempre tenés que cerrar el archivo que abriste. No hacerlo puede resultar en pérdida de datos, corrupción de archivos y agotamiento de recursos del sistema. Es una de las causas más comunes de errores sutiles en programas que manejan archivos.
```

Aunque parezca una simple formalidad, la llamada a `fclose()` también puede fallar. Esto es particularmente cierto al escribir archivos: si el disco se llena o el medio de almacenamiento se desconecta, el vaciado final del búfer (el _flush_) fallará. Ignorar el valor de retorno de `fclose()` podría hacerte creer que la operación fue exitosa cuando en realidad los últimos datos se perdieron. La única forma de estar 100% seguro de que toda la información se guardó correctamente es verificar el resultado del cierre.

```{code-block} c
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



## ¿Cómo Saben las Funciones a Qué Archivo Escribir?

Cuando trabajás con archivos en C, es común tener más de uno abierto al mismo tiempo. Podrías estar leyendo datos de un archivo de entrada, escribiendo resultados en otro y registrando mensajes de error en un tercer archivo de log. Esto plantea una pregunta fundamental: si llamás a una función como `fprintf()`, ¿cómo sabe a cuál de todos esos archivos abiertos debe enviar el texto?

La respuesta está en el primer argumento que le pasás a estas funciones.

### El "Identificador" de Archivo: La Clave de la Operación

Cuando abrís un archivo con `fopen()`, el sistema operativo te devuelve un **identificador único** para esa conexión específica. Podés pensar en este identificador como una credencial o un "manejador" (`handle`) que representa a tu archivo abierto. No es el nombre del archivo, sino una referencia interna que tu programa usa mientras el archivo esté abierto.

La variable donde guardás este identificador es de tipo `FILE`.

```c
// Abrimos un archivo y guardamos su identificador único
FILE *identificador_de_mi_archivo;
identificador_de_mi_archivo = fopen("salida.txt", "w");
```

A partir de este momento, `identificador_de_mi_archivo` es la forma en que te referís a `salida.txt` dentro de tu código.

### Pasando el Identificador como Argumento

La mayoría de las funciones que operan sobre archivos están diseñadas para recibir este identificador como su primer parámetro. De esta manera, les indicás explícitamente sobre qué archivo deben actuar.

Observá la firma de `fprintf()`:

```c
int fprintf(FILE *identificador, const char *formato, ...);
```

El primer parámetro, llamado convencionalmente `stream` o en nuestro caso `identificador`, es el lugar donde le decís a la función "quiero que escribas esto **en el archivo que corresponde a este identificador**".

#### Ejemplo Práctico: Escribiendo en Múltiples Archivos

Imaginá que necesitás procesar unos datos y, al mismo tiempo, generar un registro de lo que vas haciendo. Para esto, abrís dos archivos: `datos.csv` para los resultados y `proceso.log` para el registro.

```{code-block} c
:caption: Dirigiendo la salida a diferentes archivos
:label: file-argument-passing

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. Obtenemos identificadores para cada archivo que abrimos.
    FILE *archivo_csv = fopen("datos.csv", "w");
    FILE *archivo_log = fopen("proceso.log", "w");

    // Verificación de errores (esencial, aunque simplificada aquí).
    if (archivo_csv == NULL || archivo_log == NULL) {
        fprintf(stderr, "Error: No se pudo abrir uno de los archivos.\n");
        return EXIT_FAILURE;
    }

    // 2. Usamos el identificador 'archivo_log' para escribir en el log.
    fprintf(archivo_log, "INFO: Archivos abiertos correctamente.\n");
    fprintf(archivo_log, "INFO: Iniciando procesamiento de datos.\n");

    // 3. Usamos el identificador 'archivo_csv' para escribir los datos.
    fprintf(archivo_csv, "Nombre,Edad,Ciudad\n"); // Encabezado del CSV
    fprintf(archivo_csv, "Juan Perez,34,Bariloche\n");
    fprintf(archivo_csv, "Ana Gomez,28,Buenos Aires\n");

    fprintf(archivo_log, "INFO: Se escribieron 2 registros en el CSV.\n");
    fprintf(archivo_log, "INFO: Proceso finalizado. Cerrando archivos.\n");

    // 4. Cerramos cada archivo usando su respectivo identificador.
    fclose(archivo_csv);
    fclose(archivo_log);

    printf("Proceso completado. Revisa 'datos.csv' y 'proceso.log'.\n");

    return EXIT_SUCCESS;
}
```

Como ves en el ejemplo, la misma función `fprintf()` se comporta de manera diferente según el identificador que le pases. Al pasarle `archivo_log`, escribe en `proceso.log`. Al pasarle `archivo_csv`, escribe en `datos.csv`.

:::{important} Descriptores de archivo estándar

Tu programa siempre empieza con tres descriptores ya abiertos por defecto:
- `stdin`: La entrada estándar (usualmente, el teclado).
- `stdout`: La salida estándar (normalmente a la terminal).
- `stderr`: La salida de errores estándar (también, a la terminal).

La función `printf("hola")` que usás comúnmente es, en realidad, un atajo para `fprintf(stdout, "hola")`. Simplemente escribe en el "archivo" de la terminal por defecto.

:::


