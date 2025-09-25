---
title: Argumentos de la Línea de Comandos en C
short_title: 9 - Argumentos y librería
---

## Los parámetros `main(int argc, char *argv[])`

Cuando ejecutás un programa en C desde la terminal, tenés la posibilidad de
pasarle información directamente en la línea de comandos. Esta información,
conocida como "argumentos", es recibida por la función `main` a través de dos
parámetros especiales: `argc` y `argv`.

Entender cómo manipular estos parámetros es fundamental para crear
herramientas de línea de comandos flexibles y potentes. Y aunque es opcional,
entender como funciona la terminal termina siendo importante para lograr que
nuestros programas se integren a la perfección.

La signatura estándar de la función `main` que acepta argumentos es la
siguiente:

```c
int main(int argc, char *argv[]) {
    // Tu código aquí
    return EXIT_SUCCESS;
}
```

Estos dos parámetros contienen toda la información que se pasa al programa en el
momento de su ejecución.

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

```c
:caption: "Programa que itera e imprime sus argumentos."
:label: "c-print-args"

#include <stdio.h>

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
$> ./mi_programa Número total de argumentos: 4
```

```text
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
esperás. La función `strcmp` de la biblioteca `string.h` es ideal para esto.

```c
:caption: "Detección de una opción `-h` para mostrar ayuda."
:label: "c-options-help"

#include <stdio.h>
#include <string.h> // Necesario para strcmp

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
`atoi`, `atol` y `strtol`.

```c
:caption: "Programa que suma los números pasados como argumentos."
:label: "c-sum-numbers"

#include <stdio.h>
#include <stdlib.h> // Necesario para atoi

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

La función `atoi` ("ASCII to integer") es simple, pero tiene una limitación
importante: si la cadena no puede ser convertida (ej. "hola"), retorna `0` sin
indicar el error.

Para un código más robusto, es preferible usar `strtol` ("string to long"), que
ofrece un mecanismo para detectar si la conversión fue exitosa.

:::

## Funciones de la librería estándar

### Funciones de Conversión (`<stdlib.h>`)

#### `atoi`

Convierte una cadena de caracteres a un entero (`int`). Su nombre viene de
"ASCII to integer".

- **Prototipo:** `int atoi(const char *str);`
- **Descripción:** Es una forma rápida y simple de obtener un valor numérico a
  partir de un argumento.

:::{warning} Limitaciones de `atoi` `atoi`

Estas funciones no tienenn un mecanismo para informar errores. Si la cadena no
contiene un número válido (ej. "hola"), simplemente devuelve `0`. Esto es
problemático porque "0" también es un número válido, y no podés distinguir un
error de una entrada legítima de cero.

:::

```c
:caption: "Conversión simple con `atoi`."
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // No tenemos los argumentos necesarios
        return EXIT_FAILURE;
    }
    int edad = atoi(argv[1]);
    printf("El próximo año tendrás %d años.\n", edad + 1);
    return EXIT_SUCCESS;
}
```

#### `strtol`

Convierte una cadena a un entero largo (`long int`), proporcionando un control
de errores robusto. Su nombre viene de "string to long".

- **Prototipo:** `long int strtol(const char *str, char **endptr, int base);`
- **Descripción:** Es la alternativa recomendada a `atoi` para código de
  producción.
  - `str`: La cadena a convertir.
  - `endptr`: Un puntero a un `char*`. Después de la ejecución, apuntará al
    primer carácter de la cadena que no formó parte del número. Si la conversión
    fue exitosa y consumió toda la cadena, `*endptr` será el carácter nulo
    (`\0`).
  - `base`: La base numérica a utilizar (ej. `10` para decimal, `16` para
    hexadecimal, `0` para autodetectar por prefijos como `0x`).
- **Retorno:** El número convertido. Si no se pudo realizar la conversión,
  devuelve `0` y `errno` se establece a un valor de error.

:::{tip} ¿Por qué usar `strtol`?

Al verificar el valor de `*endptr` después de llamar a `strtol`, podés saber
exactamente si la conversión fue exitosa y cuántos caracteres de la cadena se
utilizaron. Esto te permite detectar entradas inválidas como `"42abc"`.

:::

```c
:caption: "Uso robusto de `strtol` para validación."
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // No tenemos los argumentos necesarios
        return EXIT_FAILURE;
    }

    char *endptr;
    long numero = strtol(argv[1], &endptr, 10);

    // Verificamos si hubo un error de conversión
    // 1. ¿endptr apunta al inicio? -> No se encontró ningún número
    // 2. ¿*endptr no es el final de la cadena? -> Había caracteres extra
    if (endptr == argv[1] || *endptr != '\0') {
        fprintf(stderr, "Error: '%s' no es un número entero válido.\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("El doble del número es: %ld\n", numero * 2);
    return EXIT_SUCCESS;
}
```

### Control del Programa - `exit` y `system`

Estas funciones te permiten controlar el flujo de terminación de tu programa e
interactuar con el sistema operativo.

#### `exit`

Termina la ejecución del programa de forma inmediata.

- **Prototipo:** `void exit(int status);`
- **Descripción:** Finaliza el programa, sin importar desde qué función se la
  llame. El `status` que se le pasa es devuelto al sistema operativo, donde
  `EXIT_SUCCESS` (usualmente 0) indica éxito y `EXIT_FAILURE` (usualmente 1)
  indica un error. Realiza una limpieza normal de los flujos de salida antes de
  terminar.

#### `system`

Ejecuta un comando del sistema operativo.

- **Prototipo:** `int system(const char *command);`
- **Descripción:** Pasa la cadena `command` al intérprete de comandos del
  sistema para que la ejecute. Es una forma simple de interactuar con el SO (ej.
  "ls -l", "cls").
- **Retorno:** Depende del sistema, pero generalmente devuelve 0 si el comando
  se ejecutó correctamente.

:::{warning} Riesgos de Seguridad

Usar `system` Usar `system` con entradas que provienen del usuario es
extremadamente peligroso, ya que puede permitir la inyección de comandos
maliciosos. Usala con precaución y solo con comandos fijos o después de una
validación muy rigurosa de la entrada.

:::

```c
:caption: "Uso de `exit` y `system`."
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Listando archivos del directorio actual:\n");
    // En sistemas POSIX (Linux, macOS) se usa "ls", en Windows es "dir".
    #ifdef _WIN32
        system("dir");
    #else
        system("ls -l");
    #endif

    int divisor = 0;
    if (divisor == 0) {
        fprintf(stderr, "Error crítico: intento de división por cero. Saliendo...\n");
        exit(EXIT_FAILURE); // Termina el programa inmediatamente
    }

    // Este código nunca se ejecuta
    printf("Esto no se imprimirá.\n");
    return EXIT_SUCCESS;
}
```


### Números Pseudoaleatorios - `srand` y `rand`

`stdlib.h` provee un generador de números pseudoaleatorios simple (PRNG).

- **`void srand(unsigned int seed);`**: Inicializa el generador con una
  "semilla" (`seed`). Para obtener secuencias de números diferentes en cada
  ejecución, la semilla debe ser diferente. Una práctica común es usar la hora
  actual.
- **`int rand(void);`**: Devuelve un número entero pseudoaleatorio entre 0 y
  `RAND_MAX` (una constante definida en `stdlib.h`).

```c
:caption: "Generando 5 números aleatorios entre 1 y 100."
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necesario para time()

int main() {
    // Usamos la hora actual como semilla. Esto solo se hace UNA VEZ por programa.
    srand(time(NULL));

    printf("5 números aleatorios entre 1 y 100:\n");
    for (int i = 0; i < 5; i++) {
        // rand() % 100 -> número entre 0 y 99
        // + 1          -> número entre 1 y 100
        int numero_aleatorio = (rand() % 100) + 1;
        printf("%d\n", numero_aleatorio);
    }

    return EXIT_SUCCESS;
}
```

:::{note} La Naturaleza de ` rand()`: Pseudoaleatorio, no Aleatorio

Es crucial entender que funciones como ` rand()` no generan números
verdaderamente aleatorios, sino **pseudoaleatorios**. Esto significa que los
números se calculan mediante un algoritmo determinista. Si iniciás el generador
con la misma **semilla** (_seed_) usando ` srand()`, la secuencia de números que
obtendrás con llamadas sucesivas a ` rand()` será siempre idéntica. Por eso,
para simular aleatoriedad en cada ejecución, se usa una semilla que cambie
constantemente, como la hora del sistema obtenida con ` time(NULL)`.

Entender esto es importante, sinó, preguntenlé a
[Sony con la PS3](https://media.ccc.de/v/27c3-4087-en-console_hacking_2010)

:::

### Interacción con el Entorno - `getenv`

Tu programa no se ejecuta en el vacío. A menudo necesita obtener información del
entorno en el que se está ejecutando, como el nombre del usuario actual o la
ruta de su directorio personal.

Con `getenv`, podemos obtener el valor de una variable de entorno.

- **Prototipo:** `char* getenv(const char *name);`
- **Descripción:** Busca en la lista de variables de entorno del proceso actual
  una cadena que coincida con `name`.
- **Retorno:** Devuelve un puntero a la cadena que contiene el valor de la
  variable. Si la variable no existe, devuelve `NULL`.

:::{warning} Cuidado

La cadena devuelta por `getenv` es propiedad del sistema y no debe ser
modificada por tu programa. Si necesitás alterarla, primero debés copiarla a un
nuevo bloque de memoria.

:::

```c
:caption: "Leyendo las variables de entorno `USER` y `PATH`."
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Intentamos obtener la variable de entorno 'USER' (común en Linux/macOS)
    // o 'USERNAME' (común en Windows).
    char *usuario = getenv("USER");
    if (usuario == NULL) {
        usuario = getenv("USERNAME");
    }

    if (usuario != NULL) {
        printf("Hola, %s!\n", usuario);
    } else {
        printf("No se pudo determinar el nombre de usuario.\n");
    }

    char *path = getenv("PATH");
    if (path != NULL) {
        printf("\nLa variable PATH del sistema es:\n%s\n", path);
    }

    return EXIT_SUCCESS;
}
```

### Funciones matemáticas en `<math.h>`

Mientras que `stdlib.h` provee funciones matemáticas para enteros, la biblioteca
`<math.h>` es el estándar en C para operaciones matemáticas de punto flotante
(`float`, `double`). Esta biblioteca es indispensable para aplicaciones
científicas, de ingeniería, gráficas o cualquier tarea que requiera más que
aritmética básica.

:::{note}Sobre los tipos de las funciones:

La mayoría de las funciones en `<math.h>` operan con el tipo de dato `double`.
Existen versiones para `float` y `long double` que se identifican con los
sufijos `f` y `l` respectivamente (ej. `sinf()`, `sinl()`). Por simplicidad,
aquí nos enfocaremos en las versiones `double`.

:::


#### Valor absoluto - `abs`, `labs`, `llabs`

Calculan el valor absoluto de un número entero.

- **Prototipos:**
  - `int abs(int j);`
  - `long int labs(long int j);`
  - `long long int llabs(long long int j);`
- **Descripción:** Devuelven el valor absoluto del número `j`. Es importante
  usar la versión correcta según el tipo de dato para evitar desbordamientos
  (`overflow`).

#### División entera - `div`, `ldiv`, `lldiv`

Realizan la división entera, devolviendo el cociente y el resto en una única
operación.

- **Prototipos:**
  - `div_t div(int numer, int denom);`
  - `ldiv_t ldiv(long int numer, long int denom);`
  - `lldiv_t lldiv(long long int numer, long long int denom);`
- **Descripción:** Calculan `numer / denom`. Devuelven una estructura (`div_t`,
  `ldiv_t` o `lldiv_t`) que contiene dos miembros:
  - `quot`: El cociente de la división.
  - `rem`: El resto (residuo) de la división.

```c
:caption: "Uso de funciones de valor absoluto y división."
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = -150;
    printf("El valor absoluto de %d es %d.\n", numero, abs(numero));

    int dividendo = 17;
    int divisor = 5;

    // Usamos la función div para obtener cociente y resto.
    div_t resultado = div(dividendo, divisor);

    printf("\nAl dividir %d entre %d:\n", dividendo, divisor);
    printf("  - Cociente: %d\n", resultado.quot); // Equivalente a 17 / 5
    printf("  - Resto: %d\n", resultado.rem);   // Equivalente a 17 % 5

    return EXIT_SUCCESS;
}
```

#### Funciones trigonométricas

Las funciones trigonométricas en C, al igual que en la mayoría de los lenguajes
de programación, operan con **radianes**, no con grados.

##### `sin`, `cos`, `tan`

Calculan el seno, coseno y tangente de un ángulo.

- **Prototipos:**
  - `double sin(double x);`
  - `double cos(double x);`
  - `double tan(double x);`

##### `asin`, `acos`, `atan`, `atan2`

Calculan los arcos (funciones inversas) correspondientes.

- `atan2(y, x)` es particularmente útil. Calcula el arco tangente de `y / x`,
  pero utiliza los signos de ambos argumentos para determinar el cuadrante
  correcto del ángulo resultante, devolviendo un valor en el rango
  $[-\pi, +\pi]$.

```c
:caption: "Calculando seno y coseno de 45 grados."
#include <stdio.h>
#include <math.h> // Necesario para funciones matemáticas
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double grados = 45.0;

    // 1. Convertimos grados a radianes
    double radianes = grados * (M_PI / 180.0);

    // 2. Calculamos las funciones trigonométricas
    double seno = sin(radianes);
    double coseno = cos(radianes);

    printf("Para un ángulo de %.1f grados (%.4f rad):\n", grados, radianes);
    printf("  - Seno: %f\n", seno);
    printf("  - Coseno: %f\n", coseno);

    // Usando atan2 para recuperar el ángulo original (en radianes)
    double angulo_recuperado = atan2(seno, coseno);
    printf("\nÁngulo recuperado con atan2(seno, coseno): %.4f rad\n", angulo_recuperado);

    return EXIT_SUCCESS;
}
```

#### Potencias, raíces y logaritmos

Estas funciones cubren operaciones exponenciales.

##### `pow`, `sqrt`

- `double pow(double base, double exponent);`: Calcula `base` elevado a la
  potencia `exponent`.
- `double sqrt(double x);`: Calcula la raíz cuadrada no negativa de `x`.

##### `exp`, `log`, `log10`

- `double exp(double x);`: Calcula el número $e$ elevado a la potencia `x`.
- `double log(double x);`: Calcula el logaritmo natural (base $e$) de `x`.
- `double log10(double x);`: Calcula el logaritmo en base 10 de `x`.

```c
:caption: "Uso de funciones exponenciales."
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Potencia y raíz
    printf("2 elevado a la 8 es %.1f\n", pow(2.0, 8.0));
    printf("La raíz cuadrada de 144 es %.1f\n", sqrt(144.0));

    // Logaritmos
    double numero = 1000.0;
    printf("\nPara el número %.1f:\n", numero);
    printf("  - Logaritmo en base 10 (log10): %.1f\n", log10(numero));
    printf("  - Logaritmo natural (log): %f\n", log(numero));

    return EXIT_SUCCESS;
}
```


### Funciones de redondeo y manipulación

#### `ceil`, `floor`, `round`

- `double ceil(double x);`: **Ceiling (techo)**. Redondea `x` al entero más
  pequeño que no sea menor que `x` (redondea hacia arriba).
- `double floor(double x);`: **Floor (piso)**. Redondea `x` al entero más grande
  que no sea mayor que `x` (redondea hacia abajo).
- `double round(double x);`: Redondea `x` al entero más cercano. Si está
  exactamente a la mitad, redondea alejándose de cero. (Nota: `round` fue
  estandarizado en C99).

#### `fabs`

- `double fabs(double x);`: Calcula el valor absoluto de un número de punto
  flotante `x`. Es el análogo de `abs` para `double`.

```c
:caption: "Comparando los distintos tipos de redondeo."
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_redondeo(double num) {
    printf("Para el número %.2f:\n", num);
    printf("  - floor (hacia abajo): %.1f\n", floor(num));
    printf("  - ceil (hacia arriba): %.1f\n", ceil(num));
    printf("  - round (al más cercano): %.1f\n", round(num));
    printf("  - fabs (valor absoluto): %.2f\n", fabs(num));
    printf("------------------------\n");
}

int main() {
    test_redondeo(3.14);
    test_redondeo(3.89);
    test_redondeo(-2.71);
    test_redondeo(-2.5);

    return EXIT_SUCCESS;
}
```

:::{important} ¡Necesitás enlazar la biblioteca matemática!

A diferencia de `stdlib.h` o `stdio.h`, la biblioteca matemática a menudo no se
vincula (enlaza) por defecto durante la compilación. Si obtenés errores como
"undefined reference to `sin`", necesitás indicarle explícitamente al compilador
que la use con la bandera `-lm`.

**Comando de compilación correcto:**

```bash
gcc mi_programa.c -o mi_programa -lm
```

El `-l` le dice al enlazador que use una biblioteca, y la `m` es el nombre de la
biblioteca matemática.

:::

### Funciones sobre cadenas

#### Copia y concatenación

Estas funciones se utilizan para copiar o unir cadenas.

##### `strcpy` y `strncpy`

Copian una cadena en otra.

- `char* strcpy(char *dest, const char *src);`: Copia la cadena `src`
  (incluyendo el `\0`) en el búfer `dest`.
- `char* strncpy(char *dest, const char *src, size_t n);`: Copia como máximo `n`
  caracteres de `src` a `dest`.

:::{danger} ¡Peligro con `strcpy`!

La función `strcpy` no verifica si el búfer de destino (`dest`) tiene suficiente
espacio para albergar la cadena de origen (`src`). Si `src` es más larga que
`dest`, se producirá un **desbordamiento de búfer**, sobrescribiendo memoria
adyacente. **Evitá `strcpy` en favor de `strncpy` o alternativas más seguras.**

`strncpy` es más segura, pero tené cuidado: si la longitud de `src` es `n` o
más, el resultado en `dest` **no estará terminado en nulo**. Siempre debés
asegurarte de agregar el `\0` manualmente.

:::

##### `strcat` y `strncat`

Concatenan (unen) una cadena al final de otra.

- `char* strcat(char *dest, const char *src);`: Añade la cadena `src` al final
  de la cadena `dest`.
- `char* strncat(char *dest, const char *src, size_t n);`: Añade como máximo `n`
  caracteres de `src` al final de `dest` y siempre añade un carácter nulo.

:::{warning} Cuestiones de seguridad

Al igual que `strcpy`, `strcat` es insegura y propensa a desbordamientos de
búfer. `strncat` es la alternativa recomendada.

:::

```c
:caption: "Uso seguro de `strncpy` y `strncat`."
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char destino[20]; // Un búfer con espacio para 19 chars + '\0'
    char origen[] = "¡Hola Mundo!";

    // Copia segura con strncpy
    strncpy(destino, origen, sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0'; // Aseguramos la terminación nula

    printf("Después de strncpy: %s\n", destino);

    // Concatenación segura con strncat
    strncat(destino, " Adiós.", 3); // Solo añadimos " Ad"

    printf("Después de strncat: %s\n", destino);

    return EXIT_SUCCESS;
}
```

#### Comparación y longitud

##### `strcmp` y `strncmp`

Comparan dos cadenas de caracteres lexicográficamente.

- `int strcmp(const char *s1, const char *s2);`: Compara `s1` y `s2`.
- `int strncmp(const char *s1, const char *s2, size_t n);`: Compara como máximo
  los primeros `n` caracteres de `s1` y `s2`.

**Valor de Retorno:**

- **< 0**: si `s1` es menor que `s2`.
- **0**: si `s1` es igual a `s2`.
- **> 0**: si `s1` es mayor que `s2`.

```c
:caption: "Verificando una opción `--version`."
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "--version") == 0) {
        printf("Versión del programa: 1.0\n");
    } else {
        printf("Opción desconocida. Usá --version para ver la versión.\n");
    }
    return EXIT_SUCCESS;
}
```

##### `strlen`

- `size_t strlen(const char *s);`: Devuelve la longitud de la cadena `s`, **sin
  incluir** el carácter nulo terminador `\0`.

```c
:caption: "Comparando cadenas y obteniendo su longitud."
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[] = "manzana";
    char str2[] = "mancha";
    char str3[] = "manzana";

    printf("Longitud de '%s': %zu\n", str1, strlen(str1));

    if (strcmp(str1, str3) == 0) {
        printf("'%s' y '%s' son iguales.\n", str1, str3);
    }

    // Comparamos los primeros 3 caracteres
    if (strncmp(str1, str2, 3) == 0) {
        printf("Los primeros 3 caracteres de '%s' y '%s' son iguales ('man').\n", str1, str2);
    }

    return EXIT_SUCCESS;
}
```


#### Búsqueda

Estas funciones te permiten encontrar caracteres o subcadenas dentro de una
cadena.

##### `strchr` y `strrchr`

Buscan la primera o la última ocurrencia de un carácter.

- `char* strchr(const char *s, int c);`: Devuelve un puntero a la primera
  aparición del carácter `c` en la cadena `s`, o `NULL` si no se encuentra.
- `char* strrchr(const char *s, int c);`: Devuelve un puntero a la última
  aparición del carácter `c`.

#### `strstr`

Busca la primera ocurrencia de una subcadena completa.

- `char* strstr(const char *haystack, const char *needle);`: Devuelve un puntero
  a la primera aparición de la subcadena `needle` (aguja) dentro de la cadena
  `haystack` (pajar), o `NULL` si no se encuentra.

```c
:caption: "Buscando caracteres y subcadenas."
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char frase[] = "El zorro marrón rápido salta sobre el perro perezoso.";
    char *subcadena;
    char letra = 'p';

    // Buscamos la subcadena "rápido"
    subcadena = strstr(frase, "rápido");
    if (subcadena != NULL) {
        printf("Subcadena encontrada: %s\n", subcadena);
    }

    // Buscamos la primera 'p'
    char* primera_p = strchr(frase, letra);
    if(primera_p != NULL){
        printf("La primera '%c' está en la posición: %ld\n", letra, primera_p - frase);
    }

    // Buscamos la última 'p'
    char* ultima_p = strrchr(frase, letra);
    if(ultima_p != NULL){
        printf("La última '%c' está en la posición: %ld\n", letra, ultima_p - frase);
    }

    return EXIT_SUCCESS;
}
```
