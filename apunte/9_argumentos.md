---
title: Argumentos de la Línea de Comandos en C
short_title: 9 - Argumentos y librería
---

## Los parámetros `main(int argc, char *argv[])`

Cuando ejecutás un programa en C desde la terminal, tenés la posibilidad de pasarle información directamente en la línea de comandos. Esta información, conocida como "argumentos", es recibida por la función `main` a través de dos parámetros especiales: `argc` y `argv`.

:::{note} Prerequisitos

Este capítulo asume conocimiento de arreglos ({doc}`4_secuencias`) y punteros ({doc}`7_punteros`), ya que `argv` es un arreglo de punteros a cadenas (`char *argv[]`). Si estos conceptos no están claros, repasalos antes de continuar.

:::

Entender cómo manipular estos parámetros es fundamental para crear herramientas de línea de comandos flexibles y potentes. Y aunque es opcional, entender como funciona la terminal termina siendo importante para lograr que nuestros programas se integren a la perfección.

La signatura estándar de la función `main` que acepta argumentos es la siguiente:

```c
int main(int argc, char *argv[]) {
    // Tu código aquí
    return EXIT_SUCCESS;
}
```

Estos dos parámetros contienen toda la información que se pasa al programa en el momento de su ejecución.

```list-table
:header-rows: 1
:label: tabla-argc-argv
:caption: Descripción de los parámetros de `main`

* - Parámetro
  - Tipo
  - Descripción
* - `argc`
  - `int`
  - **Argument Count**: Es un entero que contiene el número total de argumentos pasados al programa. Su valor es siempre al menos 1, ya que el primer argumento es el propio nombre del ejecutable.
* - `argv`
  - `char *[]`
  - **Argument Values**: Es un array de punteros a cadenas de caracteres (strings). Cada elemento del array apunta a uno de los argumentos.
    - `argv[0]` es el nombre con el que se invocó el programa.
    - `argv[1]` es el primer argumento real.
    - ...
    - `argv[argc - 1]` es el último argumento.
    - `argv[argc]` es un puntero nulo (`NULL`), garantizado por el estándar de C.
```

## Ejemplo Básico: Imprimir Todos los Argumentos

El programa más simple para entender su funcionamiento es uno que recorre los
valores en `argv` e imprime cada uno de sus elementos.

```{code-block} c
:caption: "Programa que itera e imprime sus argumentos."
:label: "c-print-args"

#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS

int main(int argc, char *argv[]) {
    printf("El programa se ejecutó con el nombre: %s\n", argv[0]);
    printf("Número total de argumentos: %d\n", argc);
    printf("----------------------------------------\n");

    // Iteramos desde el argumento 1, ya que el 0 es el nombre del programa
    if (argc > 1) {
        printf("Los argumentos proporcionados son:\n");
        for (int i = 1; i < argc; i++) {
            printf("  Argumento %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No se proporcionaron argumentos adicionales.\n");
    }

    return EXIT_SUCCESS;
}
```

### Compilación y ejecución

Si guardás el código anterior como `main_args.c` y lo compilás, podés ver la
salida al ejecutarlo con distintos argumentos.

```bash
# Compilamos el programa
gcc main_args.c -o mi_programa

# Ejecutamos sin argumentos
./mi_programa

# Ejecutamos con varios argumentos
./mi_programa hola "mundo con espacios" 42
```

**Salida de la segunda ejecución:**

```
$> ./mi_programa hola "mundo con espacios" 42
El programa se ejecutó con el nombre: ./mi_programa
Número total de argumentos: 4
----------------------------------------
Los argumentos proporcionados son:
  Argumento 1: hola
  Argumento 2: mundo con espacios
  Argumento 3: 42
```

:::{note} Sobre los espacios

Observá que "mundo con espacios" se trata como un solo argumento (`argv[2]`)
porque está entre comillas. Sin las comillas, hubieran sido dos argumentos
separados.

:::

## Procesamiento de opciones

Las opciones (también llamadas _flags_ o _switches_) son argumentos especiales
que modifican el comportamiento de un programa. Usualmente comienzan con un
guion (`-`) o dos (`--`), como `-h` o `--help`.

Para detectarlas, necesitás comparar las cadenas de `argv` con los valores que
esperás. La función `strcmp` (ver {ref}`string-strcmp`) de la biblioteca `string.h` es ideal para esto.

```{code-block}c
:caption: "Detección de una opción `-h` para mostrar ayuda."
:label: "c-options-help"

#include <stdio.h>
#include <string.h> // Necesario para strcmp
#include <stdlib.h> // Para EXIT_SUCCESS

int main(int argc, char *argv[]) {
    // Verificamos si el primer argumento es -h o --help
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        printf("Uso: %s [opciones] [argumentos]\n", argv[0]);
        printf("Este es un programa de ejemplo para mostrar ayuda.\n");
        return EXIT_SUCCESS; // Terminamos la ejecución después de mostrar la ayuda
    }

    printf("Programa ejecutándose normalmente.\n");
    // ... resto de la lógica del programa ...

    return EXIT_SUCCESS;
}
```

:::{tip} Bibliotecas para el Análisis de Argumentos

Para aplicaciones complejas con muchas opciones, analizar `argv` manualmente
puede volverse tedioso y propenso a errores. Considerá usar bibliotecas estándar
como `getopt` (en sistemas POSIX) que simplifican enormemente este proceso.

:::

## Conversión de Argumentos a Números

Un punto crucial es que **todos los argumentos en `argv` son cadenas de
caracteres**, incluso si parecen números (como `"42"`). Para poder realizar
operaciones matemáticas con ellos, debés convertirlos a un tipo numérico (como
`int` o `double`).

La biblioteca estándar de C (`stdlib.h`) provee funciones para esta tarea, como
`atoi` y, de forma más robusta, {ref}`strtol <stdlib-strtol>`.

```{code-block}c
:caption: "Programa que suma los números pasados como argumentos."
:label: "c-sum-numbers"

#include <stdio.h>
#include <stdlib.h> // Necesario para atoi y EXIT_SUCCESS/FAILURE

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Proporcioná al menos un número para sumar.\n");
        fprintf(stderr, "Uso: %s num1 num2 ...\n", argv[0]);
        return EXIT_FAILURE; // Salimos un código de error
    }

    int suma = 0;
    for (int i = 1; i < argc; i++) {
        // atoi convierte la cadena a un entero
        int numero = atoi(argv[i]);
        suma = suma + numero;
    }

    printf("La suma total es: %d\n", suma);

    return EXIT_SUCCESS;
}
```

### Compilación y Ejecución del Sumador

```bash
# Compilamos
gcc sumador.c -o sumador

# Ejecutamos con números
./sumador 10 20 5
# Salida: La suma total es: 35
```

:::{warning} Manejo de Errores en la Conversión

La función `atoi` es simple, pero tiene una limitación importante: si la cadena no puede ser convertida (ej. "hola"), retorna `0` sin indicar el error.

Para un código más robusto, es preferible usar `strtol` (ver {ref}`stdlib-strtol`), que ofrece un mecanismo para detectar si la conversión fue exitosa.

:::

## Funciones Útiles de la Biblioteca Estándar

Para construir programas de línea de comandos robustos, es indispensable conocer algunas de las herramientas que provee la biblioteca estándar de C. A continuación, se mencionan algunas de las funciones más relevantes en este contexto.

:::{important} Referencia Completa

Este es solo un resumen. Para una descripción detallada de todas las funciones, sus parámetros, valores de retorno y ejemplos de uso, consultá el apunte de referencia: {doc}`A_stdlib`.

:::

### Funciones Clave

- **Conversión de Cadenas (`<stdlib.h>`)**:
  - {ref}`strtol <stdlib-strtol>`: Convierte cadenas a números de forma segura, permitiendo un control de errores robusto.
  - `atof`: Convierte cadenas a `double`.

- **Control del Programa (`<stdlib.h>`)**:
  - {ref}`exit <stdlib-exit>`: Termina el programa y devuelve un código de estado al sistema.
  - {ref}`system <stdlib-system>`: Ejecuta un comando externo del sistema operativo.
  - {ref}`getenv <stdlib-getenv>`: Lee el valor de una variable de entorno.

- **Generación de Números Aleatorios (`<stdlib.h>`)**:
  - {ref}`srand <stdlib-rand>` y {ref}`rand <stdlib-rand>`: Para inicializar y generar secuencias de números pseudoaleatorios.

- **Manipulación de Cadenas (`<string.h>`)**:
  - {ref}`strcmp <string-strcmp>`: Compara dos cadenas, esencial para procesar opciones.
  - {ref}`strlen <string-strlen>`: Obtiene la longitud de una cadena.
  - `strncpy`, `strncat`: Versiones seguras para copiar y concatenar cadenas.
  - `strstr`, `strchr`: Para buscar subcadenas o caracteres.

- **Funciones Matemáticas (`<math.h>`)**:
  - Si tus argumentos son números, probablemente necesites esta biblioteca para operaciones como {ref}`pow <math-pow-sqrt>`, {ref}`sqrt <math-pow-sqrt>`, {ref}`log <math-pow-sqrt>`, o funciones trigonométricas (ver {ref}`math-trig`). No olvides compilar con la bandera `-lm`.

Dominar el uso de `argc` y `argv` junto con estas funciones te permitirá crear aplicaciones de consola complejas y útiles, una habilidad fundamental en el mundo del desarrollo de software.