---
title: Biblioteca Estándar de C
short_title: "A - stdlib"
subtitle: Referencia completa de las bibliotecas estándar de C organizadas por header.
---

## Introducción a la Biblioteca Estándar de C

La biblioteca estándar de C (Standard Library) es un conjunto de funciones, macros y tipos definidos que proporcionan servicios esenciales para el desarrollo de programas en C. Estos componentes están estandarizados por ISO/IEC 9899 y están disponibles en cualquier implementación conforme al estándar.

La biblioteca está organizada en **archivos de cabecera** (headers), cada uno dedicado a un dominio específico de funcionalidad. Incluir un header mediante la directiva `#include` da acceso a las declaraciones de funciones, constantes y tipos definidos en ese módulo.

### Principios de la Biblioteca Estándar

- **Portabilidad**: El código que usa solo la biblioteca estándar puede compilarse en cualquier sistema que tenga un compilador C conforme al estándar.
- **Minimalismo**: La biblioteca provee las funciones fundamentales; funcionalidad más especializada se deja a bibliotecas externas.
- **Eficiencia**: Las implementaciones están optimizadas para el rendimiento.
- **Consistencia**: Los patrones de diseño (como manejo de errores) son uniformes.

:::{note} Estándares de C

La biblioteca estándar ha evolucionado con las versiones del lenguaje:
- **ANSI C (C89/C90)**: Primera estandarización.
- **C99**: Añadió `<stdint.h>`, `<stdbool.h>`, `<complex.h>`, entre otros.
- **C11**: Agregó `<threads.h>`, `<stdatomic.h>`, funciones seguras opcionales.
- **C17/C18**: Correcciones sin cambios significativos en la biblioteca.
- **C23**: Última versión con mejoras adicionales.

Este apunte cubre primordialmente C99 y C11, que son los estándares más ampliamente soportados.
:::

---

## `<assert.h>` - Diagnóstico y Aserciones

El header `<assert.h>` proporciona la macro `assert()` para verificar suposiciones durante el desarrollo. Las aserciones ayudan a detectar errores de lógica de forma temprana.

### Macro `assert`

```c
void assert(scalar expression);
```

**Comportamiento:**
- Si `expression` es falsa (0), `assert()` imprime un mensaje de diagnóstico en `stderr` y aborta el programa llamando a `abort()`.
- Si `expression` es verdadera (no-cero), no hace nada.
- Si se define la macro `NDEBUG` antes de incluir `<assert.h>`, todas las aserciones se desactivan.

**Ejemplo:**

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>

int dividir(int a, int b)
{
    assert(b != 0);  // Precondición: divisor no puede ser cero
    return a / b;
}

int main(void)
{
    int resultado = dividir(10, 2);
    printf("10 / 2 = %d\n", resultado);
    
    // La siguiente línea abortará el programa en modo debug
    // resultado = dividir(10, 0);
    
    return 0;
}
```

**Mensaje de error típico:**
```
Assertion failed: (b != 0), function dividir, file programa.c, line 5.
Abort trap: 6
```

**Compilación con aserciones desactivadas:**
```bash
gcc -DNDEBUG programa.c -o programa
```

:::{important} Regla {ref}`0x0038h`

Las aserciones deben usarse para verificar invariantes y precondiciones durante el desarrollo, NO para validar entrada del usuario o condiciones de runtime en producción.
:::

---

## `<ctype.h>` - Clasificación y Transformación de Caracteres

El header `<ctype.h>` proporciona funciones para clasificar y transformar caracteres individuales. Todas estas funciones aceptan un `int` (representando un `unsigned char` o `EOF`) y devuelven un `int`.

### Funciones de Clasificación

Retornan un valor no-cero (verdadero) si el carácter cumple la condición, 0 en caso contrario.

#### `isalnum` - Alfanumérico

```c
int isalnum(int c);
```

Verifica si `c` es una letra (`a-z`, `A-Z`) o un dígito (`0-9`).

La función `isalnum()` es extremadamente útil para validar entradas que deben contener solo caracteres alfanuméricos, como nombres de usuario, identificadores o códigos. Su implementación considera la configuración regional actual del sistema (locale), lo que significa que puede reconocer caracteres acentuados como válidos en ciertos idiomas. Esta función es fundamental en el procesamiento de texto y validación de datos, especialmente cuando se necesita filtrar caracteres especiales o espacios en blanco de una cadena de entrada.

```c
isalnum('a');  // → no-cero (verdadero)
isalnum('5');  // → no-cero (verdadero)
isalnum('!');  // → 0 (falso)
```

#### `isalpha` - Alfabético

```c
int isalpha(int c);
```

Verifica si `c` es una letra del alfabeto.

Esta función es esencial para el análisis léxico y el procesamiento de texto. `isalpha()` identifica únicamente las letras del alfabeto, excluyendo dígitos, espacios y caracteres especiales. Es particularmente útil en parsers, analizadores de código, y funciones que necesitan distinguir entre contenido textual y otros tipos de caracteres. Al igual que otras funciones de `<ctype.h>`, considera la configuración regional, permitiendo el reconocimiento de caracteres específicos del idioma como ñ, ç, ü, etc., dependiendo del locale configurado en el sistema.

```c
isalpha('A');  // → verdadero
isalpha('z');  // → verdadero
isalpha('3');  // → falso
```

#### `isdigit` - Dígito Decimal

```c
int isdigit(int c);
```

Verifica si `c` es un dígito decimal (`0-9`).

`isdigit()` es una función fundamental para la validación numérica y el parsing de números en cadenas de texto. A diferencia de `isalnum()`, esta función se limita estrictamente a los dígitos decimales del 0 al 9, sin considerar caracteres alfabéticos. Es especialmente valiosa en funciones que convierten cadenas a números, validadores de entrada numérica, y en algoritmos que procesan datos mixtos donde se necesita separar contenido numérico del textual. Su comportamiento es independiente del locale, garantizando consistencia en diferentes configuraciones regionales.

```c
isdigit('7');  // → verdadero
isdigit('a');  // → falso
```

#### `isxdigit` - Dígito Hexadecimal

```c
int isxdigit(int c);
```

Verifica si `c` es un dígito hexadecimal (`0-9`, `a-f`, `A-F`).

Esta función es indispensable en aplicaciones que manejan representaciones hexadecimales de datos, como parsers de colores HTML, convertidores de formato numérico, y herramientas que procesan direcciones de memoria o valores hash. `isxdigit()` reconoce tanto dígitos decimales como las letras a-f (y A-F), que representan los valores 10-15 en hexadecimal. Es crucial en sistemas que requieren conversión entre bases numéricas y en el procesamiento de datos binarios representados como texto hexadecimal.

```c
isxdigit('F');  // → verdadero
isxdigit('g');  // → falso
```

#### `islower` y `isupper` - Mayúsculas y Minúsculas

```c
int islower(int c);
int isupper(int c);
```

Verifican si `c` es una letra minúscula o mayúscula, respectivamente.

Estas funciones son fundamentales para el procesamiento de texto que requiere análisis de capitalización. `islower()` identifica letras en minúscula, mientras que `isupper()` identifica letras en mayúscula. Son especialmente útiles en algoritmos de normalización de texto, validadores de formato de identificadores (como CamelCase o snake_case), y en sistemas que implementan reglas específicas de capitalización. Ambas funciones consideran la configuración regional, por lo que pueden manejar apropiadamente caracteres acentuados y específicos del idioma, como distinguir entre 'á' y 'Á' según el locale configurado.

```c
islower('a');  // → verdadero
isupper('A');  // → verdadero
islower('A');  // → falso
```

#### `isspace` - Espacio en Blanco

```c
int isspace(int c);
```

Verifica si `c` es un carácter de espacio en blanco: espacio (`' '`), tabulador (`'\t'`), nueva línea (`'\n'`), retorno de carro (`'\r'`), avance de página (`'\f'`), tabulador vertical (`'\v'`).

`isspace()` es una función crucial para el parsing y tokenización de texto, ya que permite identificar todos los tipos de caracteres de espacio en blanco que separan palabras y elementos en un documento. Esta función es más completa que una simple comparación con espacio, ya que reconoce múltiples tipos de separadores invisibles que pueden aparecer en texto procesado desde diferentes fuentes y sistemas operativos. Es especialmente valiosa en analizadores léxicos, funciones que eliminan espacios en blanco (trim), y en algoritmos que procesan entrada de usuario donde los espacios deben ser manejados apropiadamente.

```c
isspace(' ');   // → verdadero
isspace('\n');  // → verdadero
isspace('a');   // → falso
```

#### `isprint` y `isgraph` - Imprimibles

```c
int isprint(int c);
int isgraph(int c);
```

- `isprint()`: Verdadero si `c` es imprimible (incluyendo el espacio).
- `isgraph()`: Verdadero si `c` es imprimible excluyendo el espacio.

Estas funciones son esenciales para validar y filtrar caracteres en aplicaciones que manejan entrada de usuario o procesan texto de fuentes externas. `isprint()` identifica caracteres que pueden ser mostrados visualmente, incluyendo el espacio, lo que la convierte en un filtro efectivo contra caracteres de control que podrían causar problemas de visualización o seguridad. `isgraph()` es más restrictiva, excluyendo el espacio, y es útil cuando se necesita identificar únicamente caracteres "gráficos" verdaderos. Ambas son fundamentales en sistemas que validan contenido textual, escapan caracteres especiales, o preparan texto para visualización segura en interfaces de usuario.

```c
isprint('A');   // → verdadero
isprint(' ');   // → verdadero
isgraph(' ');   // → falso
```

#### `iscntrl` y `ispunct` - Control y Puntuación

```c
int iscntrl(int c);
int ispunct(int c);
```

- `iscntrl()`: Verdadero si `c` es un carácter de control.
- `ispunct()`: Verdadero si `c` es un carácter de puntuación.

`iscntrl()` identifica caracteres de control, que son caracteres no imprimibles utilizados para control de formato o comunicación (como '\n', '\t', '\0', etc.). Esta función es crucial en aplicaciones que procesan texto crudo o datos de comunicación, donde los caracteres de control deben ser manejados de forma especial o filtrados. `ispunct()` reconoce caracteres de puntuación como '.', ',', '!', '?', ';', etc., siendo esencial en analizadores de texto, procesadores de lenguaje natural, y sistemas que necesitan separar puntuación del contenido alfabético. Ambas funciones son fundamentales para la limpieza y categorización de datos textuales.

### Funciones de Transformación

#### `tolower` y `toupper` - Conversión de Caso

```c
int tolower(int c);
int toupper(int c);
```

Convierten un carácter a minúscula o mayúscula. Si el carácter no tiene equivalente (ej. un dígito), lo devuelven sin cambios.

Estas funciones son pilares de la manipulación de texto en C, permitiendo normalización de casos para comparaciones insensibles a mayúsculas, generación de identificadores consistentes, y formateo de salida. `toupper()` convierte letras minúsculas a mayúsculas, mientras que `tolower()` hace lo contrario. Ambas funciones son "seguras" en el sentido de que no alteran caracteres que no son letras, devolviendo el carácter original sin modificación. Son especialmente útiles en sistemas de búsqueda, validación de entrada de usuario, y algoritmos que requieren comparación de texto independiente del caso. Su comportamiento depende del locale configurado, permitiendo manejo apropiado de caracteres internacionales.

```c
toupper('a');  // → 'A'
tolower('Z');  // → 'z'
tolower('3');  // → '3' (sin cambio)
```

**Ejemplo completo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char cadena[] = "Hola123!";
    
    printf("Análisis de caracteres:\n");
    for (size_t i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        printf("'%c': ", c);
        
        if (isalpha(c)) printf("alfa ");
        if (isdigit(c)) printf("dígito ");
        if (isspace(c)) printf("espacio ");
        if (ispunct(c)) printf("puntuación ");
        
        printf("\n");
    }
    
    return 0;
}
```

---

## `<errno.h>` - Reporte de Errores

El header `<errno.h>` define la variable global `errno` y constantes para códigos de error. Muchas funciones de la biblioteca estándar establecen `errno` cuando fallan.

### Variable `errno`

```c
extern int errno;
```

Esta variable global almacena el código del último error ocurrido. No se resetea automáticamente; el programador debe establecerla a 0 antes de llamar a funciones que puedan modificarla.

La variable `errno` es el mecanismo estándar de reporte de errores en C, funcionando como un canal de comunicación entre las funciones de biblioteca y el código de aplicación. Su diseño global permite que cualquier función de biblioteca indique errores sin necesidad de cambiar su interfaz de retorno. Es fundamental entender que `errno` mantiene su valor hasta que otra función lo modifique, por lo que debe ser explícitamente inicializada a 0 antes de llamar funciones que puedan fallar. Este enfoque permite distinguir entre fallas reales y valores de retorno que podrían ser ambiguos (como cuando `malloc()` retorna `NULL` o `strtol()` retorna 0).

**Códigos de error comunes (macro constantes):**

- `EDOM`: Error de dominio matemático (ej. `sqrt(-1)`)
- `ERANGE`: Error de rango (resultado fuera del rango representable)
- `EILSEQ`: Secuencia de bytes ilegal en conversión multibyte
- Y otros específicos de la implementación (POSIX define muchos más)

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(void)
{
    errno = 0;  // Resetear antes de la operación
    
    double resultado = sqrt(-1.0);
    
    if (errno == EDOM) {
        fprintf(stderr, "Error de dominio: %s\n", strerror(errno));
    }
    
    return 0;
}
```

### Función `strerror`

Aunque está definida en `<string.h>`, se usa comúnmente con `errno`:

```c
char *strerror(int errnum);
```

Retorna un puntero a una cadena que describe el código de error `errnum`.

```c
fprintf(stderr, "Error: %s\n", strerror(errno));
```

---

## `<float.h>` - Límites de Tipos de Punto Flotante

El header `<float.h>` define constantes que caracterizan la implementación de los tipos de punto flotante (`float`, `double`, `long double`).

### Macros Principales

#### Precisión y Dígitos

- `FLT_DIG`, `DBL_DIG`, `LDBL_DIG`: Número de dígitos decimales de precisión.
- `FLT_MANT_DIG`, `DBL_MANT_DIG`: Número de dígitos en la mantisa (base del sistema).

#### Rangos

- `FLT_MIN`, `DBL_MIN`, `LDBL_MIN`: Valor positivo normalizado más pequeño.
- `FLT_MAX`, `DBL_MAX`, `LDBL_MAX`: Valor finito más grande representable.

#### Epsilon

- `FLT_EPSILON`, `DBL_EPSILON`, `LDBL_EPSILON`: Diferencia entre 1.0 y el siguiente valor representable.

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <float.h>

int main(void)
{
    printf("Límites de float:\n");
    printf("  Precisión: %d dígitos decimales\n", FLT_DIG);
    printf("  Mínimo: %e\n", FLT_MIN);
    printf("  Máximo: %e\n", FLT_MAX);
    printf("  Epsilon: %e\n", FLT_EPSILON);
    
    printf("\nLímites de double:\n");
    printf("  Precisión: %d dígitos decimales\n", DBL_DIG);
    printf("  Epsilon: %e\n", DBL_EPSILON);
    
    return 0;
}
```

**Salida típica:**
```
Límites de float:
  Precisión: 6 dígitos decimales
  Mínimo: 1.175494e-38
  Máximo: 3.402823e+38
  Epsilon: 1.192093e-07
```

---

## `<limits.h>` - Límites de Tipos Enteros

El header `<limits.h>` define constantes que especifican los límites de los tipos enteros en la implementación actual.

### Macros de Límites para Tipos Enteros

#### Char

- `CHAR_BIT`: Número de bits en un `char` (típicamente 8)
- `CHAR_MIN`, `CHAR_MAX`: Rango de `char`
- `SCHAR_MIN`, `SCHAR_MAX`: Rango de `signed char`
- `UCHAR_MAX`: Máximo de `unsigned char`

#### Short

- `SHRT_MIN`, `SHRT_MAX`: Rango de `short int`
- `USHRT_MAX`: Máximo de `unsigned short int`

#### Int

- `INT_MIN`, `INT_MAX`: Rango de `int`
- `UINT_MAX`: Máximo de `unsigned int`

#### Long

- `LONG_MIN`, `LONG_MAX`: Rango de `long int`
- `ULONG_MAX`: Máximo de `unsigned long int`

#### Long Long (C99)

- `LLONG_MIN`, `LLONG_MAX`: Rango de `long long int`
- `ULLONG_MAX`: Máximo de `unsigned long long int`

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Límites de tipos enteros:\n");
    printf("CHAR_BIT: %d bits\n", CHAR_BIT);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);
    
    return 0;
}
```

---

## `<math.h>` - Funciones Matemáticas

El header `<math.h>` proporciona funciones matemáticas comunes. La mayoría opera sobre `double`, pero C99 añadió versiones para `float` (sufijo `f`) y `long double` (sufijo `l`).

**Para compilar programas que usan `<math.h>`, típicamente se debe enlazar con la biblioteca matemática:**
```bash
gcc programa.c -o programa -lm
```

(math-trig)=
### Funciones Trigonométricas

```c
double sin(double x);    // Seno (x en radianes)
double cos(double x);    // Coseno
double tan(double x);    // Tangente

double asin(double x);   // Arco seno
double acos(double x);   // Arco coseno
double atan(double x);   // Arco tangente
double atan2(double y, double x);  // Arco tangente de y/x
```

Las funciones trigonométricas son fundamentales en aplicaciones científicas, gráficos por computadora, simulaciones físicas y procesamiento de señales. `sin()`, `cos()` y `tan()` calculan las funciones trigonométricas básicas, recibiendo ángulos en radianes (no en grados). Sus contrapartes inversas `asin()`, `acos()` y `atan()` calculan el ángulo correspondiente dado el valor de la función trigonométrica. `atan2(y, x)` es especialmente útil porque calcula el arco tangente de y/x considerando el cuadrante, evitando problemas de división por cero y proporcionando el ángulo correcto en el rango [-π, π]. Esta función es esencial en conversiones de coordenadas cartesianas a polares y en cálculos de orientación en gráficos 2D.

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    double angulo_grados = 45.0;
    double angulo_radianes = angulo_grados * PI / 180.0;
    
    printf("seno(45°) = %.4f\n", sin(angulo_radianes));
    printf("coseno(45°) = %.4f\n", cos(angulo_radianes));
    printf("tangente(45°) = %.4f\n", tan(angulo_radianes));
    
    return 0;
}
```

(math-pow-sqrt)=
### Funciones Exponenciales y Logarítmicas

```c
double exp(double x);     // e^x
double log(double x);     // Logaritmo natural (base e)
double log10(double x);   // Logaritmo base 10
double pow(double x, double y);  // x^y
double sqrt(double x);    // Raíz cuadrada
```

Las funciones exponenciales y logarítmicas son esenciales en análisis matemático, algoritmos de crecimiento, y modelado científico. `exp(x)` calcula e elevado a la potencia x, siendo fundamental en cálculos de crecimiento exponencial, distribuciones estadísticas y transformadas de Fourier. `log(x)` y `log10(x)` calculan logaritmos naturales y base 10 respectivamente, útiles en algoritmos de complejidad, escalas logarítmicas y compresión de datos. `pow(x, y)` es una función de potenciación general que calcula x^y, manejando casos especiales como exponentes fraccionarios y negativos. `sqrt(x)` calcula la raíz cuadrada, optimizada para ser más rápida que `pow(x, 0.5)` y esencial en cálculos geométricos, algoritmos de distancia y normalización de vectores.

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("e^2 = %.4f\n", exp(2.0));
    printf("log(10) = %.4f\n", log(10.0));
    printf("log10(100) = %.4f\n", log10(100.0));
    printf("2^8 = %.0f\n", pow(2.0, 8.0));
    printf("√16 = %.0f\n", sqrt(16.0));
    
    return 0;
}
```

(math-rounding)=
### Funciones de Redondeo

```c
double ceil(double x);    // Redondea hacia arriba
double floor(double x);   // Redondea hacia abajo
double round(double x);   // Redondea al entero más cercano (C99)
double trunc(double x);   // Trunca la parte decimal (C99)
```

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <math.h>

int main(void)
{
    double valor = 3.7;
    
    printf("ceil(%.1f) = %.0f\n", valor, ceil(valor));      // 4
    printf("floor(%.1f) = %.0f\n", valor, floor(valor));    // 3
    printf("round(%.1f) = %.0f\n", valor, round(valor));    // 4
    printf("trunc(%.1f) = %.0f\n", valor, trunc(valor));    // 3
    
    return 0;
}
```

(math-abs)=
### Valor Absoluto y Resto

```c
double fabs(double x);    // Valor absoluto
double fmod(double x, double y);  // Resto de x/y
```

`fabs()` calcula el valor absoluto de un número de punto flotante. `fmod()` calcula el resto de la división de punto flotante `x/y`.

```{code-block} c
:caption: "Uso de fabs y fmod."
:linenos:
#include <stdio.h>
#include <math.h>

int main() {
    printf("fabs(-5.5) = %.1f\n", fabs(-5.5));
    printf("fmod(10.5, 3.0) = %.1f\n", fmod(10.5, 3.0)); // 10.5 = 3 * 3.0 + 1.5
    return 0;
}
```

### Funciones Hiperbólicas

```c
double sinh(double x);    // Seno hiperbólico
double cosh(double x);    // Coseno hiperbólico
double tanh(double x);    // Tangente hiperbólica
```

Calculan las funciones trigonométricas hiperbólicas, que son análogas a las trigonométricas ordinarias pero definidas usando la hipérbola en lugar del círculo. Son fundamentales en cálculo, física e ingeniería.

```{code-block} c
:caption: "Cálculo de funciones hiperbólicas."
:linenos:
#include <stdio.h>
#include <math.h>

int main() {
    double x = 1.0;
    printf("sinh(%.1f) = %f\n", x, sinh(x));
    printf("cosh(%.1f) = %f\n", x, cosh(x));
    printf("tanh(%.1f) = %f\n", x, tanh(x));
    return 0;
}
```

### Constantes Útiles

Aunque no están en el estándar, muchas implementaciones definen:

```c
#define M_PI    3.14159265358979323846   // π
#define M_E     2.71828182845904523536   // e
```

:::{note} Verificación de errores

Las funciones matemáticas pueden establecer `errno` a `EDOM` (error de dominio) o `ERANGE` (error de rango). Además, C99 introdujo macros para verificar errores de punto flotante más detalladamente.
:::

---

## `<stdbool.h>` - Tipo Booleano (C99)

El header `<stdbool.h>`, introducido en C99, define el tipo `bool` y las constantes `true` y `false`, facilitando el uso de lógica booleana de forma más expresiva.

### Definiciones

```c
#define bool  _Bool
#define true  1
#define false 0
```

El tipo subyacente es `_Bool`, que puede almacenar 0 o 1.

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>

bool es_par(int n)
{
    return n % 2 == 0;
}

int main(void)
{
    bool activo = true;
    bool deshabilitado = false;
    
    if (activo) {
        printf("El sistema está activo.\n");
    }
    
    if (es_par(10)) {
        printf("10 es par.\n");
    }
    
    return 0;
}
```

:::{tip} Regla {ref}`0x0010h`

Aunque `bool` simplifica el código, evitá comparaciones ambiguas basadas en "veracidad". Sé explícito: `if (puntero != NULL)` en lugar de `if (puntero)`.
:::

---

## `<stddef.h>` - Definiciones Estándar

El header `<stddef.h>` define tipos y macros fundamentales que son utilizados ampliamente en otros headers.

### Tipos Definidos

#### `size_t`

```c
typedef /* implementation-defined */ size_t;
```

Tipo entero sin signo que representa el tamaño de un objeto en bytes. Es el tipo de retorno de `sizeof` y se usa para índices de arreglos y tamaños de bloques de memoria.

```c
size_t longitud = strlen("hola");
char buffer[100];
size_t tamano_buffer = sizeof(buffer);
```

#### `ptrdiff_t`

```c
typedef /* implementation-defined */ ptrdiff_t;
```

Tipo entero con signo que representa la diferencia entre dos punteros.

```c
int arr[10];
int *p1 = &arr[8];
int *p2 = &arr[3];
ptrdiff_t diferencia = p1 - p2;  // 5
```

#### `wchar_t`

```c
typedef /* implementation-defined */ wchar_t;
```

Tipo entero para representar caracteres anchos (wide characters), usado en internacionalización.

### Macro `NULL`

```c
#define NULL ((void*)0)
```

Constante de puntero nulo. Representa un puntero que no apunta a ningún objeto válido.

```c
int *ptr = NULL;
if (ptr == NULL) {
    printf("Puntero nulo\n");
}
```

:::{important} Regla {ref}`0x0022h`

Siempre usa `NULL` para punteros nulos en lugar de `0`, para claridad semántica.
:::

### Macro `offsetof`

```c
size_t offsetof(type, member);
```

Calcula el desplazamiento en bytes de un miembro dentro de una estructura.

```{code-block} c
:linenos:
#include <stdio.h>
#include <stddef.h>

struct Datos {
    char c;
    int i;
    double d;
};

int main(void)
{
    printf("Desplazamiento de 'c': %zu bytes\n", offsetof(struct Datos, c));
    printf("Desplazamiento de 'i': %zu bytes\n", offsetof(struct Datos, i));
    printf("Desplazamiento de 'd': %zu bytes\n", offsetof(struct Datos, d));
    
    return 0;
}
```

**Salida típica (puede variar por padding):**
```
Desplazamiento de 'c': 0 bytes
Desplazamiento de 'i': 4 bytes
Desplazamiento de 'd': 8 bytes
```

---

## `<stdint.h>` - Tipos Enteros de Ancho Fijo (C99)

El header `<stdint.h>`, introducido en C99, resuelve un problema fundamental de la portabilidad en C: el tamaño de los tipos enteros como `int` o `long` no está garantizado entre diferentes arquitecturas. En un sistema, un `int` puede tener 32 bits, y en otro, 64. Esto puede romper el código que depende de un tamaño específico, especialmente en áreas como la programación de sistemas, protocolos de red, formatos de archivo o criptografía.

`<stdint.h>` soluciona esto proveyendo un conjunto de tipos de datos enteros cuyo tamaño en bits es explícito y garantizado.

### Tipos de Ancho Exacto

Estos son los tipos más comunes y útiles del header. Tienen exactamente el número de bits especificado. Su uso es obligatorio si el sistema los soporta y tu código depende de un tamaño exacto.

```c
int8_t, int16_t, int32_t, int64_t       // Enteros con signo
uint8_t, uint16_t, uint32_t, uint64_t   // Enteros sin signo
```

**Ejemplo:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int8_t   byte = 127;            // -128 a 127
    uint8_t  ubyte = 255;           // 0 a 255
    int16_t  palabra = 32767;       // -32768 a 32767
    uint32_t doble_palabra = 4000000000u;
    int64_t  grande = 9223372036854775807LL;
    
    printf("int8_t: %d\n", byte);
    printf("uint8_t: %u\n", ubyte);
    printf("int16_t: %d\n", palabra);
    printf("uint32_t: %u\n", doble_palabra);
    printf("int64_t: %lld\n", grande);
    
    return 0;
}
```

### Tipos de Ancho Mínimo

Garantizan *al menos* el número de bits especificado. Son más portables que los de ancho exacto, ya que se garantiza su existencia en todas las plataformas conformes.

```c
int_least8_t, int_least16_t, int_least32_t, int_least64_t
uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t
```
**Uso:** Utilizalos cuando necesites un rango mínimo, pero no te importe si el tipo es más grande, y la portabilidad a sistemas exóticos es una prioridad.

### Tipos Más Rápidos

Son los tipos enteros que tienen *al menos* el ancho especificado y son los más rápidos de procesar en la arquitectura de destino.

```c
int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t
uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t
```
**Uso:** Ideales para contadores de bucles o cálculos donde el rendimiento es crítico y solo se necesita un rango mínimo.

### Tipos de Máximo Ancho

Representan los tipos enteros más grandes que la implementación puede manejar.

```c
intmax_t    // Tipo entero con signo de mayor ancho
uintmax_t   // Tipo entero sin signo de mayor ancho
```

### Tipos para Punteros

Tipos enteros garantizados para poder almacenar un puntero a `void` sin pérdida de información.

```c
intptr_t    // Entero con signo capaz de contener un puntero
uintptr_t   // Entero sin signo capaz de contener un puntero
```
**Uso:** Útiles para aritmética de punteros de bajo nivel o para conversiones (casts) entre punteros y enteros.

### Macros de Límites y Constantes

Para cada tipo, hay macros que definen sus límites (`INT8_MIN`, `INT8_MAX`, `UINT8_MAX`, etc.) y macros para definir literales de estos tipos (`INT8_C(123)`, `UINT64_C(0x123...)`).

```c
INT8_MIN, INT8_MAX, UINT8_MAX
INT16_MIN, INT16_MAX, UINT16_MAX
INT32_MIN, INT32_MAX, UINT32_MAX
INT64_MIN, INT64_MAX, UINT64_MAX
INTMAX_MIN, INTMAX_MAX, UINTMAX_MAX
```

### Ejemplo Práctico: Cabecera de un Paquete de Red

Imaginá que estás definiendo la estructura para un paquete de red. El protocolo exige tamaños de campo exactos para que cualquier sistema pueda leerlo.

```{code-block} c
:linenos:
:caption: "Uso de stdint.h para portabilidad en un protocolo."
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h> // Para macros de formato como PRId64

// Definimos una cabecera de paquete con tamaños fijos
typedef struct {
    uint16_t source_port;      // Puerto de origen (16 bits)
    uint16_t dest_port;        // Puerto de destino (16 bits)
    uint32_t sequence_number;  // Número de secuencia (32 bits)
    uint8_t  flags;            // Banderas (8 bits)
    uint8_t  protocol_version; // Versión (8 bits)
    int64_t  timestamp_ns;     // Marca de tiempo en nanosegundos (64 bits)
} PacketHeader;

int main(void)
{
    PacketHeader header = {
        .source_port = 49152,
        .dest_port = 80,
        .sequence_number = 1234567890,
        .flags = 0x10, // SYN flag
        .protocol_version = 4,
        .timestamp_ns = 1665789000123456789LL
    };

    // El tamaño es predecible en cualquier arquitectura
    printf("El tamaño de la cabecera del paquete es: %zu bytes\n", sizeof(PacketHeader));

    // Usamos macros de <inttypes.h> para imprimir de forma portable
    printf("Timestamp: %" PRId64 " ns\n", header.timestamp_ns);
    
    return 0;
}
```

:::{important} Regla {ref}`0x003Ch`

Para código que requiere portabilidad o interactúa con hardware/protocolos, preferí los tipos de `<stdint.h>` sobre `int`, `long`, etc.
:::

---


## `<stdio.h>` - Entrada/Salida Estándar

El header `<stdio.h>` (de "standard input/output") es uno de los más importantes y utilizados de C. Proporciona un conjunto de herramientas cohesivo y potente para interactuar con el exterior del programa, ya sea la consola, archivos en disco u otros dispositivos.

### El Concepto de Flujo (Stream)

La idea central de `<stdio.h>` es el **flujo** (representado por el tipo opaco `FILE`), una abstracción que unifica la manera en que se manejan las operaciones de entrada y salida. Un flujo es una secuencia de bytes que fluyen desde una fuente (como el teclado o un archivo) hacia el programa, o desde el programa hacia un destino (como la pantalla o un archivo). Gracias a esta abstracción, las mismas funciones (`fgetc`, `fprintf`, etc.) pueden usarse para leer de la consola o de un archivo, cambiando únicamente el flujo de origen.

Por defecto, tres flujos estándar están disponibles en todo programa:

- `stdin`: Flujo de entrada estándar, usualmente conectado al teclado.
- `stdout`: Flujo de salida estándar, usualmente conectado a la pantalla. Esta salida está, por lo general, "bufferizada por línea", lo que significa que los datos se envían realmente cuando se imprime un salto de línea (`\n`) o cuando el buffer se llena.
- `stderr`: Flujo de salida de error estándar, también conectado a la pantalla. A diferencia de `stdout`, `stderr` no suele estar bufferizado, para asegurar que los mensajes de error se muestren de inmediato.

### Operaciones con Archivos

#### `fopen` - Abrir Archivo

```c
FILE *fopen(const char *filename, const char *mode);
```

Abre un archivo y retorna un puntero a `FILE`, o `NULL` si falla. El `mode` especifica cómo se interactuará con el archivo.

**Modos comunes:**
- `"r"`: Lectura (el archivo debe existir).
- `"w"`: Escritura (crea un archivo nuevo o lo trunca si ya existe).
- `"a"`: Añadir (escribe al final del archivo; lo crea si no existe).
- `"r+"`: Lectura y escritura (el archivo debe existir).
- `"w+"`: Lectura y escritura (crea o trunca).
- `"a+"`: Lectura y añadir.

Se puede añadir una `b` al modo (ej. `"rb"`, `"wb"`) para operaciones en **modo binario**, que evita cualquier tipo de procesamiento o conversión de los bytes (como la conversión de finales de línea `\n` a `\r\n` en Windows).

```{code-block} c
:linenos:
#include <stdio.h>

int main(void)
{
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    // Usar el archivo...
    
    fclose(archivo);
    return 0;
}
```

#### `fclose` - Cerrar Archivo

```c
int fclose(FILE *stream);
```

Cierra el archivo asociado al flujo, asegurando que todos los datos en el buffer se escriban al disco. Retorna 0 si tiene éxito, `EOF` si hay error.

:::{important} Regla {ref}`0x001Dh`

Siempre cierra los archivos que abras. No hacerlo puede resultar en pérdida de datos o en agotar los descriptores de archivo disponibles para el programa.
:::

#### `fflush` - Vaciar Buffer

```c
int fflush(FILE *stream);
```

Fuerza la escritura de datos del buffer de salida al archivo sin tener que cerrarlo. Es útil cuando se necesita garantizar que los datos se guarden en un punto crítico. Retorna 0 si tiene éxito, `EOF` si hay error.


:::{seealso} Ejercicios Prácticos
Para aplicar estos conceptos, consultá la guía de {doc}`../../ejercicios/8_archivos`.
:::

### Funciones de Salida con Formato

#### `printf`, `fprintf`, `snprintf`

```c
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int snprintf(char *s, size_t n, const char *format, ...);
```

La familia de funciones `printf` escribe datos formateados a un flujo (`stdout` por defecto para `printf`) o a una cadena de caracteres (`snprintf`). Retornan el número de caracteres escritos.

:::{seealso} Guía Completa de `printf`
La cadena de formato es un mini-lenguaje en sí mismo. Para una referencia detallada de todos los especificadores, anchos, precisiones y opciones, consultá el apunte dedicado: {doc}`../../extras/guide-printf`.
:::

```{code-block} c
:linenos:
:caption: "Uso de snprintf para construcción segura de cadenas"
#include <stdio.h>

int main(void)
{
    char buffer[50];
    int edad = 25;
    const char* nombre = "Ana";
    
    int escritos = snprintf(buffer, sizeof(buffer), 
                            "%s tiene %d años", nombre, edad);
    
    if (escritos >= 0 && (size_t)escritos < sizeof(buffer)) {
        printf("Cadena construida: %s\n", buffer);
    }
    
    return 0;
}
```
### Funciones de Entrada con Formato

#### `scanf` y `fscanf`

```c
int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
```

Leen datos formateados desde `stdin` o un flujo, interpretando el texto según la cadena de formato. Retornan el número de conversiones exitosas, o `EOF` si se alcanza el fin del archivo o hay un error.

:::{danger} Peligro con `scanf`
`scanf("%s", ...)` es extremadamente inseguro porque no tiene forma de limitar cuántos caracteres lee, llevando fácilmente a desbordamientos de buffer. Siempre especificá un ancho máximo: `scanf("%49s", ...)` para un buffer de 50 caracteres.
:::

### Entrada y Salida de Caracteres y Líneas

#### `getchar`, `fgetc`, `fgets`

```c
int getchar(void); // Lee de stdin
int fgetc(FILE *stream); // Lee de un flujo
char *fgets(char *s, int n, FILE *stream); // Lee una línea completa
```

Estas funciones son más seguras y a menudo más simples para leer datos textuales que `scanf`.

- `getchar()` y `fgetc()` leen un solo carácter y lo devuelven como un `int` (o `EOF` en caso de error/fin de archivo).
- `fgets()` es la forma recomendada para leer líneas completas de texto. Lee hasta `n-1` caracteres, hasta encontrar un `\n`, o hasta el fin de archivo. Siempre almacena un terminador nulo `\0` y, a diferencia de `gets` (que nunca debe usarse), es segura contra desbordamientos.

```{code-block} c
:linenos:
:caption: "Lectura segura de una línea con fgets"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char linea[100];
    
    printf("Ingrese una línea: ");
    if (fgets(linea, sizeof(linea), stdin) != NULL) {
        // fgets incluye el '\n' si hay espacio, lo eliminamos.
        linea[strcspn(linea, "\n")] = '\0';
        
        printf("Leíste: \"%s\"\n", linea);
    }
    
    return 0;
}
```



### Posicionamiento en Archivos

#### `fseek`, `ftell` y `rewind`

```c
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);
```

Permiten el acceso aleatorio a los contenidos de un archivo. `fseek()` mueve el cursor de lectura/escritura, `ftell()` informa la posición actual y `rewind()` lo regresa al inicio.

```{code-block} c
:caption: "Uso de fseek, ftell y rewind para acceso aleatorio."
:linenos:
#include <stdio.h>

int main() {
    FILE *archivo = fopen("ejemplo.txt", "w+");
    if (archivo == NULL) {
        perror("Error al crear archivo");
        return 1;
    }

    fputs("Hola Mundo", archivo);

    // Obtener el tamaño del archivo usando fseek y ftell
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    printf("El archivo tiene %ld bytes.\n", tamano);

    // Volver al inicio del archivo
    rewind(archivo);

    // Leer el primer carácter
    char c = fgetc(archivo);
    printf("Primer carácter: %c\n", c);

    // Moverse 5 bytes desde el inicio y leer
    fseek(archivo, 5, SEEK_SET);
    char buffer[10];
    fgets(buffer, sizeof(buffer), archivo);
    printf("Desde la posición 5: %s\n", buffer);

    fclose(archivo);
    return 0;
}
```

### Manejo de Errores en Flujos

#### `feof`, `ferror` y `perror`

```c
int feof(FILE *stream);
int ferror(FILE *stream);
void perror(const char *s);
```

`feof()` verifica fin de archivo. `ferror()` verifica errores. `perror()` imprime un mensaje de error descriptivo.

Estas funciones son cruciales para el manejo robusto de errores en operaciones de E/S. `feof()` determina si se ha alcanzado el final del archivo, diferenciando entre una lectura fallida y el final legítimo de los datos. Es esencial en bucles de lectura para terminar apropiadamente sin generar errores espurios. `ferror()` detecta si ha ocurrido un error de E/S en el flujo, como problemas de hardware, permisos insuficientes, o espacio en disco agotado. Ambas funciones mantienen estado interno hasta que se llame a `clearerr()`. `perror()` es invaluable para debugging, imprimiendo un mensaje descriptivo del último error basado en `errno`, precedido por el texto proporcionado. Juntas, estas funciones permiten distinguir entre diferentes condiciones de terminación y proporcionar retroalimentación significativa al usuario sobre problemas de E/O.
```{code-block} c
:caption: "Manejo de fin de archivo y errores de lectura."
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir datos.txt");
        return 1;
    }

    // Leemos el archivo carácter por carácter
    while (1) {
        int c = fgetc(archivo);

        if (feof(archivo)) { // Verificamos si llegamos al final
            printf("\nFin del archivo alcanzado.\n");
            break;
        }
        if (ferror(archivo)) { // Verificamos si hubo un error de lectura
            fprintf(stderr, "Error de lectura en el archivo.\n");
            break;
        }

        putchar(c); // Imprimimos el carácter leído
    }

    fclose(archivo);
    return 0;
}
```

---


## `<stdlib.h>` - Utilidades Generales

El header `<stdlib.h>` proporciona funciones para gestión de memoria dinámica, conversión de cadenas, generación de números aleatorios, control de programa y más.

### Gestión de Memoria Dinámica

#### `malloc`, `calloc`, `realloc` y `free`

```c
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
```

`malloc()` asigna memoria sin inicializar. `calloc()` asigna e inicializa a cero. `realloc()` redimensiona. `free()` libera memoria.

Estas cuatro funciones constituyen el núcleo de la gestión de memoria dinámica en C, permitiendo a los programas solicitar y liberar memoria en tiempo de ejecución. `malloc(size)` reserva un bloque contiguo de `size` bytes sin inicializar, siendo la función más básica y eficiente para asignación. `calloc(nmemb, size)` no solo asigna memoria sino que garantiza que todos los bytes estén inicializados a cero, útil cuando se necesita memoria limpia para estructuras o arreglos. `realloc(ptr, size)` redimensiona un bloque previamente asignado, pudiendo expandirlo o contraerlo, y maneja automáticamente la copia de datos cuando es necesario mover el bloque. `free(ptr)` devuelve la memoria al sistema, siendo crucial para prevenir fugas de memoria. El uso correcto de estas funciones es fundamental para crear programas robustos y eficientes en memoria.

```{code-block} c
:linenos:
:caption: "Uso básico de malloc y free"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *numeros = malloc(10 * sizeof(int));
    if (numeros == NULL) {
        fprintf(stderr, "Error: fallo al asignar memoria\n");
        return 1;
    }
    
    // Usar la memoria...
    for (int i = 0; i < 10; i++) {
        numeros[i] = i * 2;
    }
    
    free(numeros);
    return 0;
}
```

:::{important} Reglas {ref}`0x0019h` y {ref}`0x001Ah`

Siempre verificá que `malloc()` no retorne `NULL`. Toda memoria asignada debe ser liberada.
:::

### Conversión de Cadenas

(stdlib-strtol)=
#### `atoi`, `atol` y `strtol`, `strtod`

```c
int atoi(const char *nptr);
long strtol(const char *nptr, char **endptr, int base);
double strtod(const char *nptr, char **endptr);
```

`atoi()` es simple pero sin manejo de errores. `strtol()` y `strtod()` permiten detectar errores.

Las funciones de conversión de cadenas son esenciales para el procesamiento de entrada de usuario y datos textuales. `atoi()` (ASCII to Integer) es la función más simple, convirtiendo cadenas a enteros, pero carece de mecanismos robustos de detección de errores, lo que la hace inadecuada para aplicaciones críticas. `strtol()` (String to Long) es mucho más sofisticada, permitiendo especificar la base numérica (2-36), detectar errores de conversión y obtener un puntero al primer carácter no convertido. `strtod()` (String to Double) proporciona capacidades similares para números de punto flotante. Estas funciones "str" son fundamentales en parsers, interfaces de línea de comandos y cualquier aplicación que necesite conversión robusta entre representaciones textuales y numéricas de datos.

:::{warning} Limitaciones de `atoi`
La función `atoi` no tiene un mecanismo para informar errores. Si la cadena no contiene un número válido (ej. "hola"), simplemente devuelve `0`. Esto es problemático porque "0" también es un número válido, y no podés distinguir un error de una entrada legítima de cero.
:::

```{code-block} c
:caption: "Uso robusto de `strtol` para validación."
:linenos:
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
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

### Números Aleatorios

(stdlib-rand)=
#### `rand` y `srand`

```c
int rand(void);
void srand(unsigned int seed);
```

`rand()` genera números pseudoaleatorios entre 0 y `RAND_MAX`. `srand()` inicializa el generador.

El sistema de generación de números aleatorios de C está basado en algoritmos deterministas que producen secuencias pseudoaleatorias reproducibles. `rand()` utiliza un generador de congruencia lineal que produce números en el rango [0, RAND_MAX], donde RAND_MAX es al menos 32767. `srand(seed)` inicializa el estado interno del generador con una semilla, permitiendo control sobre la reproducibilidad: la misma semilla siempre produce la misma secuencia. Es crucial llamar a `srand()` una sola vez al inicio del programa, típicamente con `time(NULL)` para obtener secuencias diferentes en cada ejecución.

```{code-block} c
:linenos:
:caption: "Generando 5 números aleatorios entre 1 y 100."
#include <stdlib.h>
#include <stdio.h>
#include <time.h> // Necesario para time()

int main(void)
{
    // Usamos la hora actual como semilla. Esto solo se hace UNA VEZ por programa.
    srand((unsigned)time(NULL));
    
    printf("5 números aleatorios entre 1 y 100:\n");
    for (int i = 0; i < 5; i++) {
        // rand() % 100 -> número entre 0 y 99
        // + 1          -> número entre 1 y 100
        int numero_aleatorio = (rand() % 100) + 1;
        printf("%d\n", numero_aleatorio);
    }
    
    return 0;
}
```

:::{note} La Naturaleza de `rand()`: Pseudoaleatorio, no Aleatorio
Es crucial entender que funciones como `rand()` no generan números verdaderamente aleatorios, sino **pseudoaleatorios**. Esto significa que los números se calculan mediante un algoritmo determinista. Si iniciás el generador con la misma **semilla** (_seed_) usando `srand()`, la secuencia de números que obtendrás con llamadas sucesivas a `rand()` será siempre idéntica. Por eso, para simular aleatoriedad en cada ejecución, se usa una semilla que cambie constantemente, como la hora del sistema obtenida con `time(NULL)`.
:::

### Búsqueda y Ordenamiento

#### `qsort` y `bsearch`

```c
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
void *bsearch(const void *key, const void *base, size_t nmemb,
              size_t size, int (*compar)(const void *, const void *));
```

`qsort()` ordena un arreglo. `bsearch()` busca en un arreglo ordenado.

Estas funciones implementan algoritmos fundamentales de ciencias de la computación con interfaces genéricas y eficientes. `qsort()` utiliza una variante del algoritmo quicksort para ordenar arreglos de cualquier tipo de datos, requiriendo una función de comparación definida por el usuario que determina el orden. Su complejidad promedio es $O(n log n)$, siendo uno de los algoritmos de ordenamiento más eficientes para uso general. `bsearch()` implementa búsqueda binaria en arreglos previamente ordenados (típicamente por `qsort()`), con complejidad $O(log n)$, muchísimo más rápida que búsqueda lineal para datos grandes. Ambas funciones usan punteros genéricos (`void*`) y funciones de comparación, permitiendo trabajar con cualquier tipo de datos. Son pilares fundamentales para aplicaciones que manejan grandes volúmenes de datos, bases de datos en memoria, y algoritmos que requieren acceso eficiente a información ordenada.

### Aritmética de Enteros

(stdlib-abs)=
#### `abs`, `labs`, `llabs`

Calculan el valor absoluto de un número entero.

- **Prototipos:**
  - `int abs(int j);`
  - `long int labs(long int j);`
  - `long long int llabs(long long int j);`
- **Descripción:** Devuelven el valor absoluto del número `j`. Es importante usar la versión correcta según el tipo de dato para evitar desbordamientos.

(stdlib-div)=
#### `div`, `ldiv`, `lldiv`

Realizan la división entera, devolviendo el cociente y el resto en una única operación.

- **Prototipos:**
  - `div_t div(int numer, int denom);`
  - `ldiv_t ldiv(long int numer, long int denom);`
  - `lldiv_t lldiv(long long int numer, long long int denom);`
- **Descripción:** Devuelven una estructura (`div_t`, `ldiv_t` o `lldiv_t`) que contiene los miembros `quot` (cociente) y `rem` (resto).

```{code-block} c
:caption: "Uso de funciones de valor absoluto y división."
:linenos:
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

### Control del Programa

(stdlib-exit)=
#### `exit`, `abort` y `atexit`

```c
void exit(int status);
void abort(void);
int atexit(void (*func)(void));
```

`exit()` termina el programa normalmente. `abort()` termina abruptamente. `atexit()` registra funciones de limpieza.

Estas funciones controlan el ciclo de vida del programa de maneras fundamentalmente diferentes. `exit()` realiza una terminación ordenada, ejecutando todas las funciones registradas con `atexit()`, vaciando buffers de salida, cerrando archivos abiertos, y devolviendo un código de estado al sistema operativo (típicamente 0 para éxito, no-cero para error). `abort()` causa terminación inmediata y anormal, generalmente produciendo un core dump para debugging y sin ejecutar limpieza. Se usa cuando el programa detecta un estado irrecuperable. `atexit()` permite registrar hasta 32 funciones que se ejecutarán automáticamente en terminación normal, en orden LIFO (último registrado, primero ejecutado). Es esencial para limpieza de recursos, cierre de conexiones, y otras tareas de finalización que garanticen que el programa termine limpiamente.

### Interacción con el Entorno

(stdlib-getenv)=
#### `getenv`

Obtiene el valor de una variable de entorno.

- **Prototipo:** `char* getenv(const char *name);`
- **Descripción:** Busca en la lista de variables de entorno del proceso actual una cadena que coincida con `name`.
- **Retorno:** Devuelve un puntero a la cadena que contiene el valor de la variable. Si la variable no existe, devuelve `NULL`. La cadena devuelta no debe ser modificada.

```{code-block} c
:caption: "Leyendo las variables de entorno `USER` y `PATH`."
:linenos:
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

(stdlib-system)=
#### `system`

Ejecuta un comando del sistema operativo.

- **Prototipo:** `int system(const char *command);`
- **Descripción:** Pasa la cadena `command` al intérprete de comandos del sistema para que la ejecute. Su uso con entradas de usuario es peligroso debido al riesgo de inyección de comandos.
- **Retorno:** Depende del sistema, pero generalmente devuelve 0 si el comando se ejecutó correctamente.

:::{warning} Riesgos de Seguridad con `system`
Usar `system` con entradas que provienen del usuario es extremadamente peligroso, ya que puede permitir la inyección de comandos maliciosos. Usala con precaución y solo con comandos fijos o después de una validación muy rigurosa de la entrada.
:::

```{code-block} c
:caption: "Uso de `exit` y `system`."
:linenos:
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

---

## `<string.h>` - Manipulación de Cadenas y Memoria

El header `<string.h>` proporciona funciones para manipular cadenas (arreglos de caracteres terminados en `'\0'`) y bloques de memoria.

### Longitud y Copia

(string-strlen)=
#### `strlen`, `strcpy` y `strncpy`

```c
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
```

`strlen()` retorna la longitud. `strcpy()` copia sin verificar límites. `strncpy()` copia con límite (pero no garantiza terminación nula).

Estas tres funciones son fundamentales en el manejo de cadenas C, pero requieren uso cuidadoso. `strlen()` recorre la cadena hasta encontrar el carácter nulo '\0', devolviendo el número de caracteres (excluyendo el terminador). Su complejidad O(n) significa que llamarla repetidamente en bucles es ineficiente. `strcpy()` es notoriamente peligrosa porque copia ciegamente desde origen a destino sin verificar límites, siendo una fuente común de vulnerabilidades de buffer overflow. `strncpy()` es más segura al limitar la copia a `n` caracteres, pero tiene la peculiaridad de no garantizar terminación nula si la cadena origen tiene exactamente `n` o más caracteres. Para uso seguro, siempre debe asegurarse manualmente la terminación nula después de usar `strncpy()`.


```{code-block} c
:caption: "Uso seguro de `strncpy` y `strncat`."
:linenos:
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
    // Dejamos espacio para 3 caracteres más y el nulo.
    strncat(destino, " Adiós.", 3); // Solo añadimos " Ad"

    printf("Después de strncat: %s\n", destino);

    return EXIT_SUCCESS;
}
```

### Comparación y Búsqueda

(string-strcmp)=
#### `strcmp`, `strstr` y `strchr`

```c
int strcmp(const char *s1, const char *s2);
char *strstr(const char *haystack, const char *needle);
char *strchr(const char *s, int c);
```

`strcmp()` compara cadenas. `strstr()` busca subcadena. `strchr()` busca carácter.

Estas funciones implementan algoritmos esenciales de búsqueda y comparación de cadenas. `strcmp()` realiza comparación lexicográfica byte por byte, retornando un valor negativo si la primera cadena es "menor", cero si son iguales, o positivo si la primera es "mayor". Es fundamental para ordenamiento y búsquedas que requieren orden alfabético. `strstr()` implementa búsqueda de subcadenas usando algoritmos eficientes, devolviendo un puntero a la primera ocurrencia de la subcadena buscada o NULL si no se encuentra. Es esencial en procesamiento de texto, parsing y filtrado de contenido. `strchr()` busca la primera ocurrencia de un carácter específico, siendo más eficiente que `strstr()` cuando se busca un solo carácter. Estas funciones son pilares de algoritmos de procesamiento de texto y forman la base de sistemas de búsqueda más complejos.

```{code-block} c
:caption: "Buscando caracteres y subcadenas."
:linenos:
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

### Manipulación de Memoria

#### `memcpy`, `memmove`, `memset` y `memcmp`

```c
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
```

`memcpy()` copia bytes (sin solapamiento). `memmove()` copia con solapamiento. `memset()` llena con un valor. `memcmp()` compara bytes.

Las funciones de manipulación de memoria operan a nivel de bytes individuales, siendo más fundamentales que las funciones de cadenas. `memcpy()` es la función de copia más eficiente, transfiriendo `n` bytes desde origen a destino, pero requiere que las regiones de memoria no se solapen. `memmove()` es similar pero maneja correctamente el solapamiento de memoria, copiando a través de un buffer temporal si es necesario, lo que la hace más segura pero potencialmente más lenta. `memset()` es extremadamente útil para inicialización, llenando un bloque de memoria con un valor específico (típicamente 0 para limpiar estructuras). `memcmp()` compara bloques de memoria byte por byte, siendo más rápida que `strcmp()` cuando se conoce la longitud exacta. Estas funciones son fundamentales para manipulación de estructuras, inicialización de arreglos y operaciones de bajo nivel donde se requiere control preciso sobre la memoria.

```{code-block} c
:caption: "Uso de funciones de manipulación de memoria."
:linenos:
#include <stdio.h>
#include <string.h>

struct Punto { int x; int y; };

int main() {
    struct Punto p1 = {10, 20};
    struct Punto p2;

    // Usar memset para inicializar una estructura a cero
    memset(&p2, 0, sizeof(struct Punto));
    printf("p2 inicializada con memset: x=%d, y=%d\n", p2.x, p2.y);

    // Usar memcpy para copiar una estructura
    memcpy(&p2, &p1, sizeof(struct Punto));
    printf("p2 después de memcpy: x=%d, y=%d\n", p2.x, p2.y);

    // Usar memcmp para comparar dos bloques de memoria
    if (memcmp(&p1, &p2, sizeof(struct Punto)) == 0) {
        printf("p1 y p2 son idénticas.\n");
    }

    // Ejemplo de memmove con solapamiento
    char buffer[] = "123456789";
    printf("\nBuffer original: %s\n", buffer);
    // Mover "12345" tres posiciones a la derecha
    memmove(buffer + 3, buffer, 5);
    printf("Buffer después de memmove: %s\n", buffer);

    return 0;
}
```

---

## `<time.h>` - Manejo de Tiempo y Fecha

El header `<time.h>` proporciona tipos y funciones para manipular tiempo y fecha.

### Tipos y Obtención de Tiempo

#### `time_t`, `struct tm`, `time` y `clock`

```c
typedef /* ... */ time_t;
struct tm { int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, ...; };

time_t time(time_t *tloc);
clock_t clock(void);
```

`time()` retorna el tiempo actual. `clock()` retorna el tiempo de procesador.

Estas funciones proporcionan acceso a diferentes aspectos del tiempo del sistema. `time()` obtiene el tiempo actual como un valor `time_t`, que típicamente representa segundos transcurridos desde el "epoch" Unix (1 enero 1970, 00:00:00 UTC). Es fundamental para timestamping, logging, y cálculos de duración. Si se pasa un puntero no-NULL, también almacena el valor en esa ubicación. `clock()` mide el tiempo de procesador consumido por el programa, retornando un valor `clock_t` que debe dividirse por `CLOCKS_PER_SEC` para obtener segundos. Es esencial para benchmarking y profiling de rendimiento, ya que mide tiempo de CPU real en lugar de tiempo de reloj de pared, ignorando tiempo bloqueado en I/O o esperando otros procesos.

### Conversión y Formateo

#### `localtime`, `strftime` y `difftime`

```c
struct tm *localtime(const time_t *timer);
size_t strftime(char *s, size_t maxsize, const char *format, 
                const struct tm *timeptr);
double difftime(time_t time1, time_t time0);
```

`localtime()` convierte a hora local. `strftime()` formatea según especificadores. `difftime()` calcula diferencia en segundos.

Estas funciones forman el núcleo de conversión y formateo de tiempo en C. `localtime()` descompone un valor `time_t` en una estructura `tm` ajustada a la zona horaria local y horario de verano, siendo esencial para mostrar fechas y horas comprensibles para el usuario. Importante: retorna un puntero a memoria estática que se sobrescribe en llamadas subsecuentes. `strftime()` es extremadamente poderosa para formateo personalizado, usando especificadores como %Y (año), %m (mes), %d (día), permitiendo crear representaciones de fecha/hora en cualquier formato deseado. `difftime()` calcula la diferencia en segundos entre dos valores `time_t`, manejando apropiadamente los casos edge y diferentes representaciones internas de tiempo. Juntas, estas funciones permiten manipulación completa de fechas y horas para logging, interfaces de usuario y cálculos temporales.

```{code-block} c
:linenos:
#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t ahora = time(NULL);
    struct tm *tiempo = localtime(&ahora);
    char buffer[100];
    
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    printf("Fecha: %s\n", buffer);
    
    return 0;
}
```

---

## Headers Adicionales (Resumen)

Otros headers importantes incluyen:

- **`<complex.h>` (C99)**: Aritmética de números complejos
- **`<fenv.h>` (C99)**: Entorno de punto flotante
- **`<inttypes.h>` (C99)**: Extiende `<stdint.h>` con macros de formateo
- **`<locale.h>`**: Internacionalización y localización
- **`<setjmp.h>`**: Saltos no locales
- **`<signal.h>`**: Manejo de señales del sistema
- **`<stdarg.h>`**: Funciones con argumentos variables
- **`<threads.h>` (C11)**: Programación multihilo
- **`<stdatomic.h>` (C11)**: Operaciones atómicas

---

## Conclusión y Buenas Prácticas

La biblioteca estándar de C es esencial para escribir código portable y robusto. Recomendaciones clave:

1. **Siempre verificá valores de retorno** (regla {ref}`0x0037h`)
2. **Usá tipos de `<stdint.h>` cuando el tamaño sea crítico** (regla {ref}`0x003Ch`)
3. **Preferí funciones seguras** como `snprintf()`, `fgets()` (regla {ref}`0x003Eh`)
4. **Inicializá variables y estructuras completamente** (regla {ref}`0x003Dh`)
5. **Gestioná recursos cuidadosamente** (reglas {ref}`0x001Ah`, {ref}`0x0039h`)
6. **Documentá suposiciones** con aserciones (regla {ref}`0x0038h`)

:::{note} Referencias Adicionales

Para información exhaustiva:
- **El estándar ISO C**: Especificación oficial
- **cppreference.com**: Referencia en línea detallada
- **man pages**: En Unix/Linux, `man 3 función`
:::

---

## Glosario de Términos

:::{glossary}

Análisis Léxico (Lexical Analysis)
: Fase inicial de un compilador que convierte una secuencia de caracteres (código fuente) en una secuencia de "tokens" o componentes con significado propio (palabras clave, identificadores, etc.). Es sinónimo de **tokenización**.

Benchmarking
: Proceso de ejecutar pruebas estandarizadas para medir y comparar el rendimiento (velocidad, uso de memoria) de un programa o una función.

Buffer
: Zona de memoria temporal usada para almacenar datos mientras se transfieren de un lugar a otro, optimizando operaciones de entrada/salida.

Buffer Overflow (Desbordamiento de Búfer)
: Error de seguridad que ocurre cuando se escriben datos más allá de los límites de un buffer, sobrescribiendo memoria adyacente y pudiendo causar fallos o vulnerabilidades.

Comparación Lexicográfica
: Comparación de dos cadenas de texto basada en el orden alfabético de sus caracteres, similar al orden de las palabras en un diccionario.

Core Dump
: Archivo que guarda el estado de la memoria de un programa en el momento en que terminó de forma anormal. Se usa para depurar errores complejos post-mortem.

Epoch (Época)
: Un instante de tiempo que sirve como punto de referencia. En sistemas Unix/POSIX, el epoch es el 1 de enero de 1970 a las 00:00:00 UTC. `time_t` suele medir los segundos transcurridos desde ese momento.

Invariante
: Condición o propiedad que debe mantenerse siempre verdadera en un punto específico de la ejecución de un programa. Las aserciones (`assert`) son una forma de verificar invariantes durante el desarrollo.

Locale (Configuración Regional)
: Conjunto de parámetros que definen el idioma, país y otras convenciones culturales (formato de fecha, moneda, separador decimal, codificación de caracteres) para adaptar el comportamiento de un programa.

Macro
: Fragmento de código identificado por un nombre, que es sustituido por su contenido por el preprocesador antes de la compilación. Se definen con la directiva `#define`.

Padding (Relleno)
: Bytes extra que el compilador inserta entre los miembros de una estructura para alinear cada miembro en una dirección de memoria que sea múltiplo de su tamaño. Esto optimiza la velocidad de acceso a la memoria.

Parsing (Análisis Sintáctico)
: Proceso de analizar una secuencia de tokens para determinar su estructura gramatical. El objetivo es construir una representación interna (como un árbol sintáctico) que el programa pueda entender y procesar.

Precondición
: Condición que debe ser verdadera antes de que se llame a una función para que esta pueda operar correctamente. `assert` se usa comúnmente para verificar precondiciones.

Profiling (Perfilado)
: Análisis del comportamiento de un programa en tiempo de ejecución para medir su uso de recursos, como el tiempo de CPU o la memoria utilizada por cada función. Ayuda a identificar cuellos de botella de rendimiento.

Serialización
: Proceso de convertir una estructura de datos en un formato (generalmente una secuencia de bytes) que puede ser almacenado en disco o transmitido por red, para su posterior reconstrucción.

Timestamping (Sellado de Tiempo)
: Acción de registrar la fecha y hora en que ocurre un evento.

Tokenización
: Proceso de dividir una secuencia de texto en "tokens" o unidades léxicas (palabras, números, símbolos). Es el primer paso del análisis léxico.

:::


