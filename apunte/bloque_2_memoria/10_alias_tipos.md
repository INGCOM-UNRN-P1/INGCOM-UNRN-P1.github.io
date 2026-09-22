---
title: 'Definición de Tipos y Alias'
short_title: 'Alias de Tipos'
subtitle: 'Typedef y su aplicación en la abstracción de tipos en C'
---

(capitulo-alias-tipos)=
> **Prerrequisitos**: declaraciones de variables, punteros, `struct` y archivos de cabecera.
>
> **Objetivos**: 1. Crear un alias con `typedef`. 2. Distinguir un alias de la creación de un tipo nuevo.
>
> **Comprobación de salida**: reescribí una declaración de puntero usando un alias y explicá qué tipo sigue representando.

# Definición de Tipos y Alias

## Introducción

En C, el mecanismo nativo para crear nombres alternativos o **alias** de tipos
de datos es la palabra clave `typedef`. A diferencia de lo que ocurre en otros
lenguajes, `typedef` no introduce un nuevo tipo de dato físicamente diferente
para el compilador; simplemente asocia un identificador secundario a un tipo
existente (primitivo, puntero, estructura o enumeración) para simplificar la
escritura o mejorar la abstracción conceptual del código.

## Desarrollo

### Alias de Tipos con `typedef`

La declaración se asemeja a la de una variable estándar, pero precedida por
`typedef`:

``` c
typedef tipo_existente nuevo_nombre_t;
```
<!-- c -->

Por ejemplo, si necesitás trabajar con enteros que representen distancias en
metros y querés que el código exprese con claridad esa unidad:

``` c
typedef double metros_t;
// Ahora podés usar 'metros_t' como un tipo estándar
metros_t distancia_casa = 1500.50;
metros_t altura_edificio = 45.2;
```
<!-- c -->

Físicamente, `distancia_casa` es un `double`. El compilador simplemente
reemplazará sintácticamente `metros_t` por `double` durante el análisis
semántico.

### Abstracción de Plataforma

Uno de los usos más rigurosos de `typedef` es garantizar la portabilidad e
independencia del hardware. Tipos de datos como `int` o `long` pueden variar su
tamaño en bytes dependiendo de la arquitectura de la CPU (16, 32 o 64 bits).

Mediante `typedef`, se pueden definir alias que denoten explícitamente el ancho
físico del tipo de dato, facilitando la compilación del mismo código en
múltiples plataformas:

``` c
// Definiciones basadas en la arquitectura del compilador
typedef signed char entero8_t;
typedef short int entero16_t;
typedef int entero32_t;
typedef long long int entero64_t;
```
<!-- c -->

*(Nota: En el C estándar moderno, estas definiciones ya se encuentran
normalizadas en la cabecera estándar `<stdint.h>` mediante los tipos `int8_t`,
`int16_t`, `int32_t` e `int64_t`)*.

### Regla de Estilo de la Cátedra: El sufijo `_t`

Para mantener la claridad y coherencia en el código desarrollado, la cátedra
impone la regla **{ref}`0x3004h`**, la cual establece que **todo alias de tipo
creado mediante `typedef` debe finalizar de forma obligatoria con el sufijo
`_t`** (por ejemplo, `metros_t`, `velocidad_t`, `nodo_t`). Esto permite
distinguir instantáneamente los tipos personalizados de las variables y
constantes en cualquier bloque de código.

A lo largo de este apunte le iremos dando uso a este concepto de manera gradual,
particularmente para simplificar la declaración de estructuras complejas (Bloque
3) y la definición de Tipos de Datos Abstractos (Bloque 4).

### Enumeraciones en C

Las **enumeraciones** (`enum`) se utilizan para representar conjuntos finitos y
discretos de constantes enteras nombradas.

Para un análisis detallado de la sintaxis de enumerativos, la asignación de
valores, las colisiones en espacios de nombres y las validaciones de rango con
switch defensivo, consultá el capítulo específico de
{ref}`capitulo-enums`.

(typedef-de-structs-y-arreglos)=
### Typedef de Structs y Arreglos

El patrón más frecuente en C no aplica `typedef` a un tipo ya declarado, sino
que combina la declaración de una `struct` (o un arreglo) con su alias en una
única sentencia:

``` c
typedef struct
{
    double x;
    double y;
} punto_t;

punto_t origen = {0.0, 0.0};
```
<!-- c -->

Acá `typedef` no le da nombre a la `struct` en sí (que queda anónima), sino al
tipo resultante de esa declaración. Es equivalente, aunque menos común, dar un
nombre de etiqueta (*tag*) a la `struct` y asignarle el alias por separado:

``` c
struct punto { double x; double y; };
typedef struct punto punto_t;
```
<!-- c -->

La primera forma es la que vas a ver a lo largo de todo este apunte
(empezando por `7_estructuras.md`): evita repetir la palabra `struct` en cada
declaración de variable y es la forma idiomática recomendada por la cátedra.

`typedef` también puede nombrar un tipo arreglo completo, incluyendo su
tamaño:

``` c
typedef int vector3_t[3];

vector3_t velocidad = {1, 0, -1};   // equivale a: int velocidad[3]
```
<!-- c -->

:::{warning} El tamaño queda fijo en el alias

A diferencia de un `typedef` de `struct`, un `typedef` de arreglo esconde el
tamaño dentro del tipo. Si necesitás arreglos de tamaños distintos, no podés
reutilizar el mismo alias con otro tamaño: `vector3_t` siempre representa
`int[3]`. Esto hace que los `typedef` de arreglos se usen mucho menos que los
de `struct` en código real.

:::

(typedef-de-punteros-a-funcion)=
### Typedef de Punteros a Función

La sintaxis de un puntero a función es una de las más difíciles de leer en C.
Comparalos:

``` c
// Sin alias: hay que leer "de adentro hacia afuera"
int (*operacion)(int, int);

// Con alias: el tipo se lee como cualquier otra declaración
typedef int (*operacion_t)(int, int);
operacion_t operacion;
```
<!-- c -->

`operacion_t` es un alias para "puntero a función que recibe dos `int` y
retorna `int`". Una vez declarado, se usa como cualquier otro tipo: como
parámetro de función (para recibir un *callback*), como campo de una
`struct`, o como tipo de una variable local.

``` c
typedef int (*comparador_t)(const void *a, const void *b);

void ordenar(void *base, size_t n, size_t tam, comparador_t comparar)
{
    qsort(base, n, tam, comparar);
}
```
<!-- c -->

Sin el alias, la misma firma de `ordenar` se escribiría
`void ordenar(void *base, size_t n, size_t tam, int (*comparar)(const void *, const void *))`
— válida, pero mucho más difícil de leer y de repetir consistentemente en
`.h` y `.c`. El uso de punteros a función como parámetro se retoma en
profundidad en el Bloque 4, al estudiar callbacks y genericidad.

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-typedef-metros-velocidad
Escribí tres declaraciones `typedef` de acuerdo con la regla de la cátedra
{ref}`0x3004h`: `distancia_t` y `tiempo_t` como alias de `double`, y
`velocidad_t` como alias de `double`. Luego, escribí una pequeña función que
reciba una distancia y un tiempo, y retorne la velocidad correspondiente
utilizando dichos alias.

:::
<!-- {exercise} -->

:::{solution} ej-typedef-metros-velocidad
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
// Definición de alias con el sufijo _t obligatorio
typedef double distancia_t;
typedef double tiempo_t;
typedef double velocidad_t;
velocidad_t calcular_velocidad(distancia_t d, tiempo_t t)
{
    if (t <= 0.0)
    {
        return 0.0;
    }
    return d / t;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-typedef-metros-velocidad -->

:::{exercise}
:label: ej-typedef-portabilidad
Implementá la declaración de tres alias de tipo (`u8_t`, `u16_t`, `u32_t`) que
representen de forma explícita enteros sin signo de 8, 16 y 32 bits en una
arquitectura donde `char` tiene 8 bits, `short` tiene 16 bits e `int` tiene 32
bits.

:::
<!-- {exercise} -->

:::{solution} ej-typedef-portabilidad
:class: dropdown
``` c
typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
```
<!-- c -->
Estas declaraciones garantizan la portabilidad porque si el código se porta a un
microcontrolador donde `int` ocupa 16 bits, solo es necesario redefinir el alias
`u32_t` a `unsigned long` en un único archivo centralizado, sin alterar las
declaraciones de variables a lo largo de todo el proyecto.

:::
<!-- {solution} ej-typedef-portabilidad -->

:::{exercise}
:label: ej-typedef-alias-redundante
Explicá de forma conceptual si la expresión `typedef float real_t;` define un
tipo de dato físicamente diferente para el compilador y si es válido realizar
asignaciones directas sin conversión de tipo entre variables `float` y `real_t`.

:::
<!-- {exercise} -->

:::{solution} ej-typedef-alias-redundante
:class: dropdown
No define un nuevo tipo de dato físicamente diferente.

`typedef` introduce únicamente un **sinónimo o alias sintáctico** en la tabla de
símbolos del compilador. Físicamente, el compilador trata a las variables
`real_t` como variables de tipo `float` estándar. Por lo tanto, realizar la
asignación directa entre variables de ambos tipos es totalmente válido y no
requiere ningún moldeo de tipo (*cast*), ya que no existe incompatibilidad
alguna.

:::
<!-- {solution} ej-typedef-alias-redundante -->

:::{exercise}
:label: ej-typedef-struct-anonima
Declará, en una única sentencia `typedef`, un alias `rectangulo_t` para una
`struct` anónima con dos campos `double` (`ancho` y `alto`). Escribí una
función `double area(rectangulo_t r)` que calcule su área.

:::
<!-- {exercise} -->

:::{solution} ej-typedef-struct-anonima
:class: dropdown
```{code-block} c
:linenos:
typedef struct
{
    double ancho;
    double alto;
} rectangulo_t;

double area(rectangulo_t r)
{
    return r.ancho * r.alto;
}

```
<!-- {code-block} c -->

La `struct` no necesita un nombre de etiqueta propio porque nunca se la
referencia como `struct algo`: todo el código posterior usa el alias
`rectangulo_t`.

:::
<!-- {solution} ej-typedef-struct-anonima -->

:::{exercise}
:label: ej-typedef-puntero-funcion
Declará un alias `validador_t` para un puntero a función que reciba un `int`
y retorne `bool`. Luego escribí una función `bool es_par(int n)` compatible
con ese alias, y una función `contar_que_cumplen` que reciba un arreglo de
enteros, su tamaño, y un `validador_t`, y retorne cuántos elementos cumplen
la condición.

:::
<!-- {exercise} -->

:::{solution} ej-typedef-puntero-funcion
:class: dropdown
```{code-block} c
:linenos:
#include <stdbool.h>
#include <stddef.h>
typedef bool (*validador_t)(int);

bool es_par(int n)
{
    return n % 2 == 0;
}

size_t contar_que_cumplen(const int *arreglo, size_t n, validador_t validar)
{
    size_t contador = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (validar(arreglo[i]))
        {
            contador++;
        }
    }
    return contador;
}

```
<!-- {code-block} c -->

`contar_que_cumplen` no conoce de antemano qué condición va a evaluar: recibe
esa lógica como un parámetro más, mediante `validador_t`. Esto le permite
reutilizarse con cualquier función que cumpla la firma `bool (*)(int)`, sin
modificar su propio código.

:::
<!-- {solution} ej-typedef-puntero-funcion -->

## Glosario

:::{glossary}

Alias de tipo (typedef)
: Nombre alternativo asignado a un tipo de dato existente para mejorar la
legibilidad y abstracción.

Portabilidad
: Capacidad de un código para compilar y ejecutarse correctamente en diferentes
arquitecturas de CPU sin cambios mayores.

Puntero a función
: Variable que almacena la dirección de una función, con un tipo que
codifica su firma (parámetros y retorno). Permite pasar comportamiento como
parámetro (*callback*).

:::
<!-- {glossary} -->

## Síntesis y Resumen

La directiva `typedef` se emplea para crear alias de tipos en C sin generar
nuevos tipos físicos. Su uso facilita la abstracción y la portabilidad del
código entre arquitecturas con diferentes tamaños de datos, y es el mecanismo
estándar para nombrar `struct` anónimas y punteros a función, dos patrones
que aparecen en todo el resto del libro. Por normas de la cátedra, todo alias
definido con `typedef` debe utilizar obligatoriamente el sufijo `_t`.

## Referencias y Lecturas Complementarias

- {cite:t}`kernighan_c_2014`. Capítulo 5: Pointers and Arrays y Capítulo 6:
  Structures (sección `typedef`).
- {cite:t}`king_c_2008`. Capítulo 14: The Preprocessor (secciones de tipos).
