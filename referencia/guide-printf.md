---
title: La función printf
short_title: Guía printf
subtitle: Guía de referencia sobre el formateo de salida de datos en lenguaje C.
---

## Introducción

La función `printf` (cuyo nombre proviene de *print formatted*) permite imprimir
mensajes por la salida estándar (normalmente la terminal) utilizando una
**cadena de formato**. Esta cadena de control describe de manera exacta cómo
deben formatearse y representarse los argumentos adicionales pasados a la
función.

`printf` es una función especial y potente de la biblioteca estándar `<stdio.h>`
porque es **variádica**, lo que significa que recibe un número variable de
parámetros.

El primer parámetro es fijo: la cadena de formato. Dentro de ella se intercalan
texto literal y **especificadores de formato** (comenzando con `%`). `printf`
procesará la cadena y reemplazará cada especificador con el valor de la variable
o argumento correspondiente, respetando el orden secuencial de aparición:

``` c
printf("El valor del contador es %d.\n", contador);
```
<!-- c -->

:::{warning} Comportamiento Indeterminado

El estándar de C no obliga a verificar en tiempo de compilación que la cantidad
y los tipos de los argumentos coincidan de manera exacta con los especificadores
de la cadena de formato. Si se proporcionan menos argumentos de los requeridos o
si se pasan tipos incompatibles, el comportamiento resultante es
**indeterminado** (*undefined behavior*).

:::
<!-- {warning} Comportamiento Indeterminado -->

---

## Anatomía de un Especificador de Formato

Cualquier especificador de formato que se inserte en la cadena de control debe
respetar la siguiente estructura jerárquica (donde los componentes entre
corchetes son opcionales):

``` c
%[parámetro][banderas][ancho][.precisión][largo]tipo
```
<!-- c -->

Para comprender en detalle cada uno de estos componentes, a continuación se
presentan divididos en tablas temáticas según su función.

### 1. Especificadores de Tipo (Obligatorio)

Determinan cómo se interpretará y mostrará el argumento correspondiente en
memoria.

:::{table} Especificadores de Tipo comunes
:label: tbl-especificadores-tipo

| Especificador | Tipo esperado | Descripción | Ejemplo de salida |
| :--- | :--- | :--- | :--- |
| `%d` o `%i` | `int` | Entero con signo en base 10. | `42` o `-42` |
| `%u` | `unsigned int` | Entero sin signo en base 10. | `3000000000` |
| `%f` o `%F` | `double` | Representación decimal tradicional (coma flotante). | `3.141593` |
| `%e` o `%E` | `double` | Coma flotante en notación científica (exponencial). | `3.141593e+00` |
| `%g` o `%G` | `double` | Utiliza la representación más compacta entre `%f` y `%e`. | `3.1416` |
| `%c` | `int` / `char` | Imprime el carácter ASCII correspondiente. | `'A'` |
| `%s` | `char*` | Cadena de caracteres (debe finalizar con el carácter nulo `\0`). | `"Hola"` |
| `%x` o `%X` | `unsigned int` | Representación hexadecimal (base 16) en minúsculas o mayúsculas. | `2a` o `2A` |
| `%o` | `unsigned int` | Representación octal (base 8). | `52` |
| `%p` | `void*` | Dirección de memoria (representación de puntero). | `0x7ffee3bf8a10` |
| `%%` | Ninguno | Imprime el símbolo `%` literal. No consume ningún argumento. | `%` |

:::
<!-- {table} Especificadores de Tipo comunes -->

### 2. Banderas u Opciones (Opcional)

Modifican aspectos de la alineación, signos matemáticos y relleno de la salida.

:::{table} Banderas de formato
:label: tbl-banderas-formato

| Bandera | Descripción | Ejemplo | Salida resultante |
| :--- | :--- | :--- | :--- |
| `-` | Justifica a la izquierda (por defecto se justifica a la derecha). | `printf("%-5d!", 42);` | `"42   !"` |
| `+` | Fuerza la visualización del signo (tanto `+` como `-`). | `printf("%+d", 42);` | `"+42"` |
| ` ` (espacio) | Agrega un espacio inicial si el número es positivo; útil para alinear con números negativos. | `printf("% d", 42);` | `" 42"` |
| `0` | Rellena con ceros a la izquierda en lugar de espacios en blanco. | `printf("%05d", 42);` | `"00042"` |
| `#` | Representación alternativa: agrega prefijo (`0x` para `%X`, `0` para `%o`) o mantiene el punto decimal en decimales vacíos. | `printf("%#X", 255);` | `"0XFF"` |

:::
<!-- {table} Banderas de formato -->

### 3. Ancho y Precisión (Opcional)

Controlan de forma exacta el espacio reservado para la salida y el redondeo o
recorte de valores.

:::{table} Control de Ancho y Precisión
:label: tbl-ancho-precision

| Componente | Sintaxis | Descripción | Ejemplo | Salida |
| :--- | :--- | :--- | :--- | :--- |
| **Ancho fijo** | Un número (ej. `5`) | Ancho mínimo del campo. Rellena con espacios si el dato es más corto. | `printf("%5d", 42);` | `"   42"` |
| **Ancho dinámico** | `*` | El ancho se lee de un argumento entero previo. | `printf("%*d", 5, 42);` | `"   42"` |
| **Precisión fija** | `.número` (ej. `.2`) | **Reales**: Cantidad de decimales. **Enteros**: Dígitos mínimos a mostrar. **Cadenas**: Longitud máxima de caracteres. | `printf("%.2f", 3.1415);` | `"3.14"` |
| **Precisión dinámica** | `.*` | La precisión se lee de un argumento entero previo. | `printf("%.*s", 3, "Frutas");` | `"Fru"` |

:::
<!-- {table} Control de Ancho y Precisión -->

### 4. Modificadores de Largo o Tamaño (Opcional)

Adaptan el tipo básico esperado a otros tamaños de variables.

:::{table} Modificadores de largo
:label: tbl-modificadores-largo

| Modificador | Tipo entero compatible | Tipo real compatible | Descripción | Ejemplo de uso |
| :--- | :--- | :--- | :--- | :--- |
| `hh` | `char` / `unsigned char` | - | Imprime como tipo entero de 8 bits. | `printf("%hhd", variable_char);` |
| `h` | `short` / `unsigned short` | - | Imprime como tipo entero corto de 16 bits. | `printf("%hd", variable_short);` |
| `l` | `long` / `unsigned long` | - | Imprime enteros largos. | `printf("%ld", 1234567890L);` |
| `ll` | `long long` / `unsigned long long` | - | Imprime enteros extra largos de 64 bits. | `printf("%lld", 123456789012LL);` |
| `z` | `size_t` | - | **Obligatorio para tamaños de variables y llamadas a `sizeof`**. | `printf("%zu bytes", sizeof(double));` |
| `L` | - | `long double` | Modificador para coma flotante de precisión extendida. | `printf("%Lf", variable_long_double);` |

:::
<!-- {table} Modificadores de largo -->

---

## Ejemplos Detallados de Formateo

A continuación se presentan una serie de ejemplos interactivos organizados por
caso de uso práctico.

### Alineación y Columnas en Tablas

Cuando se imprimen listados en la consola, formatear los anchos de campo evita
que el texto se desalinee.

```{code-block} c
:linenos:
#include <stdio.h>

int main(void) {
    char *prod1 = "Manzanas";
    char *prod2 = "Pan";
    int cant1 = 15;
    int cant2 = 2;
    double precio1 = 150.50;
    double precio2 = 45.00;

    // Encabezado
    printf("%-15s %8s %10s\n", "Producto", "Cantidad", "Precio");
    printf("-----------------------------------------\n");
    // Filas alineadas
    printf("%-15s %8d %10.2f\n", prod1, cant1, precio1);
    printf("%-15s %8d %10.2f\n", prod2, cant2, precio2);

    return 0;
}

```
<!-- {code-block} c -->

**Salida en consola:**
``` text
Producto        Cantidad     Precio↵
-----------------------------------------↵
Manzanas              15     150.50↵
Pan                    2      45.00↵
```
<!-- text -->

### Formato de Números Decimales y Redondeo

El uso de la precisión permite recortar decimales de variables de tipo `double`
y `float`. Observar cómo se aplica el redondeo aritmético convencional:

``` c
double pi = 3.1415926535;

printf("Sin formato: %f\n", pi);          // Muestra 6 decimales por defecto
printf("Dos decimales: %.2f\n", pi);       // "3.14"
printf("Cuatro decimales: %.4f\n", pi);    // "3.1416" (Redondea el último dígito)
printf("Notación científica: %e\n", pi);   // "3.141593e+00"
```
<!-- c -->

### Ancho y Precisión Dinámica

Podemos evitar codificar valores rígidos dentro de la cadena de formato
pasándolos como parámetros dinámicos mediante el asterisco (`*`):

```{code-block} c
:linenos:
int ancho = 10;
int precision = 3;
double valor = 12.345678;

// El primer asterisco consume 'ancho' (10) y el segundo 'precision' (3)
printf("Dinámico: '%*.*f'\n", ancho, precision, valor);
// Salida: '    12.346'↵

```
<!-- {code-block} c -->

### Uso de Ceros a la Izquierda

Común al mostrar fechas, horas o códigos de barras que requieren tamaños de
campo fijos:

``` c
int dia = 9;
int mes = 4;
int anio = 2026;

printf("Fecha: %02d/%02d/%04d\n", dia, mes, anio);
// Salida: Fecha: 09/04/2026↵
```
<!-- c -->

---

## Secuencias de Escape

Las secuencias de escape permiten incluir caracteres no imprimibles o con un
comportamiento sintáctico especial en la cadena de salida. Todas inician con una
barra invertida (`\`).

:::{table} Secuencias de escape comunes
:label: tbl-secuencias-escape

| Secuencia | Nombre | Descripción |
| :--- | :--- | :--- |
| `\n` | Nueva línea | Mueve el cursor al inicio de la línea siguiente (salto de línea `↵`). |
| `\t` | Tabulación | Desplaza el cursor al siguiente punto de tabulación horizontal. |
| `\0` | Byte Nulo | Indica el fin lógico de una cadena de caracteres en C. |
| `\\` | Barra invertida | Imprime un carácter literal de barra invertida (`\`). |
| `\"` | Comillas dobles | Permite escribir comillas dentro de un literal delimitado por comillas. |
| `\'` | Comilla simple | Permite representar comillas simples dentro de literales de caracteres. |

:::
<!-- {table} Secuencias de escape comunes -->

### Ejemplo práctico de secuencias de escape

``` c
printf("Ruta del archivo: C:\\Program Files\\app\\bin\\\n");
printf("El docente dijo: \"Recuerden validar los punteros con NULL\"\n");
```
<!-- c -->

**Salida en consola:**
``` text
Ruta del archivo: C:\Program Files\app\bin\↵
El docente dijo: "Recuerden validar los punteros con NULL"↵
```
<!-- text -->
