---
title: Argumentos de la Línea de Comandos en C
short_title: 9 - Interacción con la terminal
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

```{list-table} Descripción de los parámetros
:header-rows: 1
:label: tabla-argc-argv

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

---

## Interacción con el Shell

:::{note} Temas opcionales

Los temas de aquí en adelante en esta página del apunte, no forman parte de lo que vemos en clases o que entre en los temas de la materia.

Sin embargo, hacen al desarrollo de buenas aplicaciones _de consola_.

:::

Cuando ejecutás un programa desde la línea de comandos, tu programa no existe en aislamiento sino que forma parte de un ecosistema más amplio: el shell o intérprete de comandos (como `bash`, `zsh`, o `sh`). El shell proporciona mecanismos poderosos para conectar programas entre sí y controlar el flujo de datos, lo que convierte a los programas C en herramientas componibles dentro de un sistema más grande.

### Códigos de Salida

Cada programa retorna un **código de salida** (o _exit status_) al shell cuando termina su ejecución. Por convención en Unix y Linux:

- `0` indica éxito (`EXIT_SUCCESS`)
- Cualquier valor distinto de cero indica un error (`EXIT_FAILURE` generalmente es `1`)

Este código es fundamental para que el shell y otros programas sepan si tu programa funcionó correctamente.

```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: falta un argumento\n");
        return EXIT_FAILURE; // Retornamos 1 al shell
    }
    
    printf("Procesando: %s\n", argv[1]);
    return EXIT_SUCCESS; // Retornamos 0 al shell
}
```

Desde el shell, podés inspeccionar el código de salida del último programa ejecutado:

```bash
./mi_programa argumento
echo $?  # Imprime el código de salida (0 si éxito)
```

### Variables de Entorno

El shell mantiene un conjunto de **variables de entorno** que los programas pueden leer. Estas variables configuran el comportamiento del sistema y almacenan información útil como rutas de búsqueda, configuraciones del usuario, etc.

La función {ref}`getenv <stdlib-getenv>` permite leer estas variables:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *home = getenv("HOME");
    char *usuario = getenv("USER");
    
    if (home != NULL) {
        printf("Directorio home: %s\n", home);
    }
    
    if (usuario != NULL) {
        printf("Usuario actual: %s\n", usuario);
    }
    
    return EXIT_SUCCESS;
}
```

Variables comunes incluyen `PATH` (rutas de búsqueda de ejecutables), `HOME` (directorio del usuario), `USER` (nombre del usuario), y `LANG` (configuración de idioma).

## Redirecciones

Una característica fundamental del shell es su capacidad de **redirigir** la entrada y salida de los programas. Esto permite cambiar de dónde un programa lee datos y hacia dónde escribe sus resultados, sin modificar el código del programa.

### Salida Estándar y Error Estándar

Todo programa en Unix/Linux tiene tres flujos de datos estándar abiertos automáticamente:

- **Entrada estándar** (`stdin`, descriptor 0): De dónde el programa lee datos
- **Salida estándar** (`stdout`, descriptor 1): Donde el programa escribe su salida normal
- **Error estándar** (`stderr`, descriptor 2): Donde el programa escribe mensajes de error

En C, estos flujos están disponibles como:

```c
#include <stdio.h>

// stdin  - entrada estándar (teclado por defecto)
// stdout - salida estándar (pantalla por defecto)
// stderr - error estándar (pantalla por defecto)

int main(void) {
    fprintf(stdout, "Esto es salida normal\n");
    fprintf(stderr, "Esto es un mensaje de error\n");
    
    // printf escribe a stdout por defecto
    printf("Salida normal\n");
    
    return EXIT_SUCCESS;
}
```

:::{important} Separación de Salida y Error

Es una buena práctica escribir la salida normal del programa a `stdout` usando `printf`, y los mensajes de error o advertencia a `stderr` usando `fprintf(stderr, ...)`. Esto permite que el shell y el usuario manejen cada tipo de información de forma independiente.

:::

### Redirección de Salida

El shell puede redirigir hacia dónde va la salida de un programa usando el operador `>`:

```bash
# Redirige stdout a un archivo (sobrescribe)
./mi_programa > salida.txt

# Redirige stdout a un archivo (agrega al final)
./mi_programa >> salida.txt

# Redirige stderr a un archivo
./mi_programa 2> errores.txt

# Redirige ambos stdout y stderr al mismo archivo
./mi_programa > todo.txt 2>&1
```

Desde el punto de vista del programa en C, no necesitás hacer nada especial: simplemente usá `printf` (para stdout) y `fprintf(stderr, ...)` (para stderr) normalmente. El shell se encarga de la redirección.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Esto puede ir a pantalla o a un archivo según el shell lo redirija
    printf("Línea 1 de salida\n");
    printf("Línea 2 de salida\n");
    
    // Los errores se mantienen separados
    fprintf(stderr, "Advertencia: algo ocurrió\n");
    
    return EXIT_SUCCESS;
}
```

```bash
# Ejecuta y guarda solo la salida normal en archivo.txt
./mi_programa > archivo.txt
# Los errores aún aparecen en pantalla

# Para capturar solo los errores
./mi_programa 2> errores.txt
```

### Redirección de Entrada

De forma similar, el shell puede cambiar de dónde un programa lee su entrada usando el operador `<`:

```bash
# Lee stdin desde un archivo en lugar del teclado
./mi_programa < datos.txt
```

Cualquier lectura que tu programa haga desde `stdin` (usando `scanf`, `fgets`, `getchar`, etc.) leerá del archivo especificado:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char linea[256];
    
    // Lee líneas de stdin (puede ser teclado o archivo redirigido)
    while (fgets(linea, sizeof(linea), stdin) != NULL) {
        printf("Leí: %s", linea);
    }
    
    return EXIT_SUCCESS;
}
```

```bash
# Si ejecutás directamente, lee del teclado
./mi_programa

# Con redirección, lee del archivo
./mi_programa < datos.txt
```

## Canalizaciones (Pipes)

Las **canalizaciones** o _pipes_ son uno de los conceptos más poderosos del shell Unix. Permiten conectar la salida de un programa directamente con la entrada de otro, creando cadenas de procesamiento de datos.

El operador `|` (pipe) conecta `stdout` del primer programa con `stdin` del segundo:

```bash
# La salida de programa1 se convierte en la entrada de programa2
programa1 | programa2

# Ejemplo real: cuenta las líneas de salida de ls
ls -l | wc -l
```

### Filosofía Unix: Hacer Una Cosa Bien

Las canalizaciones promueven la **filosofía Unix**: escribir programas pequeños que hagan una cosa muy bien, y combinarlos para tareas complejas. Tu programa C puede ser un eslabón en esta cadena.

#### Ejemplo: Filtro de Números Pares

```c
// filtro_pares.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numero;
    
    // Lee números de stdin, uno por línea
    while (scanf("%d", &numero) == 1) {
        // Solo imprime los pares
        if (numero % 2 == 0) {
            printf("%d\n", numero);
        }
    }
    
    return EXIT_SUCCESS;
}
```

Este programa se convierte en un filtro reutilizable:

```bash
# Genera números del 1 al 10 y filtra solo los pares
seq 1 10 | ./filtro_pares
# Salida: 2, 4, 6, 8, 10

# Combina con otros programas
seq 1 100 | ./filtro_pares | wc -l  # Cuenta cuántos pares hay
```

### Canalizaciones Complejas

Podés encadenar múltiples programas:

```bash
# Genera números, filtra pares, suma los primeros 5
seq 1 100 | ./filtro_pares | head -5 | ./sumador
```

Cada programa en la cadena:
1. Lee de `stdin`
2. Procesa los datos
3. Escribe a `stdout`
4. El shell conecta todo automáticamente

### Consideraciones de Diseño

Para que tu programa funcione bien en canalizaciones:

1. **Lee de `stdin` si no hay archivo especificado**: Permite que el programa reciba datos por pipe o por archivo
2. **Escribe resultados a `stdout`**: La salida normal va a `stdout`
3. **Mensajes de error a `stderr`**: No contamines `stdout` con errores
4. **Maneja EOF correctamente**: Detectá cuando la entrada termina (`fgets` retorna `NULL`, `scanf` retorna `EOF`)

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *entrada = stdin;  // Por defecto, stdin
    
    // Si hay un argumento, abre ese archivo
    if (argc > 1) {
        entrada = fopen(argv[1], "r");
        if (entrada == NULL) {
            fprintf(stderr, "Error: no se pudo abrir %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    
    char linea[256];
    // Lee líneas (de stdin o del archivo)
    while (fgets(linea, sizeof(linea), entrada) != NULL) {
        // Procesa y escribe a stdout
        printf("Procesado: %s", linea);
    }
    
    if (entrada != stdin) {
        fclose(entrada);
    }
    
    return EXIT_SUCCESS;
}
```

Este diseño permite flexibilidad total:

```bash
# Lee del archivo directamente
./mi_programa datos.txt

# Lee de stdin (teclado)
./mi_programa

# Lee de stdin vía redirección
./mi_programa < datos.txt

# Lee de stdin vía canalización
cat datos.txt | ./mi_programa
```

:::{tip} Programas Componibles

Un programa bien diseñado para la línea de comandos es como una pieza de LEGO: pequeño, con una función clara, y que se puede combinar con otros programas para construir sistemas complejos. Esta composibilidad es la esencia del diseño Unix.

:::

### Ejemplo Completo: Conversor de Temperatura

Veamos un ejemplo que integra todos estos conceptos:

```c
// temp_converter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_ayuda(const char *programa) {
    fprintf(stderr, "Uso: %s [-c|-f] [archivo]\n", programa);
    fprintf(stderr, "  -c : Convierte de Fahrenheit a Celsius\n");
    fprintf(stderr, "  -f : Convierte de Celsius a Fahrenheit\n");
    fprintf(stderr, "Si no se especifica archivo, lee de stdin\n");
}

int main(int argc, char *argv[]) {
    FILE *entrada = stdin;
    char modo = 'c';  // Por defecto: F->C
    
    // Procesa opciones
    int archivo_idx = 1;
    if (argc > 1 && argv[1][0] == '-') {
        if (strcmp(argv[1], "-c") == 0) {
            modo = 'c';
            archivo_idx = 2;
        } else if (strcmp(argv[1], "-f") == 0) {
            modo = 'f';
            archivo_idx = 2;
        } else if (strcmp(argv[1], "-h") == 0) {
            mostrar_ayuda(argv[0]);
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Error: opción desconocida %s\n", argv[1]);
            mostrar_ayuda(argv[0]);
            return EXIT_FAILURE;
        }
    }
    
    // Abre archivo si se especificó
    if (argc > archivo_idx) {
        entrada = fopen(argv[archivo_idx], "r");
        if (entrada == NULL) {
            fprintf(stderr, "Error: no se pudo abrir %s\n", argv[archivo_idx]);
            return EXIT_FAILURE;
        }
    }
    
    // Procesa entrada línea por línea
    double temp;
    while (fscanf(entrada, "%lf", &temp) == 1) {
        double resultado;
        if (modo == 'c') {
            // Fahrenheit a Celsius
            resultado = (temp - 32.0) * 5.0 / 9.0;
            printf("%.2f°F = %.2f°C\n", temp, resultado);
        } else {
            // Celsius a Fahrenheit
            resultado = temp * 9.0 / 5.0 + 32.0;
            printf("%.2f°C = %.2f°F\n", temp, resultado);
        }
    }
    
    if (entrada != stdin) {
        fclose(entrada);
    }
    
    return EXIT_SUCCESS;
}
```

Este programa puede usarse de múltiples formas:

```bash
# Uso interactivo
./temp_converter -c
32
212

# Desde archivo
echo -e "32\n98.6\n212" > temps.txt
./temp_converter -c temps.txt

# Con redirección
./temp_converter -c < temps.txt

# Con canalización
echo "100" | ./temp_converter -f

# Encadenado con otros comandos
seq 0 10 100 | ./temp_converter -f | grep "°C"
```

La separación entre `stdout` (resultados) y `stderr` (mensajes de error y ayuda) permite que el programa funcione correctamente en canalizaciones sin contaminar los datos con mensajes no deseados.