---
title: 'Definición de Tipos y Alias'
short_title: '8 - Alias de Tipos'
subtitle: 'Typedef y su aplicación en la abstracción de tipos en C'
---

(capitulo-alias-tipos)=
## Introducción

En C, el mecanismo nativo para crear nombres alternativos o **alias** de tipos de datos es la palabra clave `typedef`. A diferencia de lo que ocurre en otros lenguajes, `typedef` no introduce un nuevo tipo de dato físicamente diferente para el compilador; simplemente asocia un identificador secundario a un tipo existente (primitivo, puntero, estructura o enumeración) para simplificar la escritura o mejorar la abstracción conceptual del código.

## Desarrollo

### Alias de Tipos con `typedef`

La declaración se asemeja a la de una variable estándar, pero precedida por `typedef`:

```c
typedef tipo_existente nuevo_nombre_t;
```

Por ejemplo, si necesitás trabajar con enteros que representen distancias en metros y querés que el código exprese con claridad esa unidad:

```c
typedef double metros_t;

// Ahora podés usar 'metros_t' como un tipo estándar
metros_t distancia_casa = 1500.50;
metros_t altura_edificio = 45.2;
```

Físicamente, `distancia_casa` es un `double`. El compilador simplemente reemplazará sintácticamente `metros_t` por `double` durante el análisis semántico.

### Abstracción de Plataforma

Uno de los usos más rigurosos de `typedef` es garantizar la portabilidad e independencia del hardware. Tipos de datos como `int` o `long` pueden variar su tamaño en bytes dependiendo de la arquitectura de la CPU (16, 32 o 64 bits). 

Mediante `typedef`, se pueden definir alias que denoten explícitamente el ancho físico del tipo de dato, facilitando la compilación del mismo código en múltiples plataformas:

```c
// Definiciones basadas en la arquitectura del compilador
typedef signed char        entero8_t;
typedef short int          entero16_t;
typedef int                entero32_t;
typedef long long int      entero64_t;
```

*(Nota: En el C estándar moderno, estas definiciones ya se encuentran normalizadas en la cabecera estándar `<stdint.h>` mediante los tipos `int8_t`, `int16_t`, `int32_t` e `int64_t`)*.

### Regla de Estilo de la Cátedra: El sufijo `_t`

Para mantener la claridad y coherencia en el código desarrollado, la cátedra impone la regla **{ref}`0x3004h`**, la cual establece que **todo alias de tipo creado mediante `typedef` debe finalizar de forma obligatoria con el sufijo `_t`** (por ejemplo, `metros_t`, `velocidad_t`, `nodo_t`). Esto permite distinguir instantáneamente los tipos personalizados de las variables y constantes en cualquier bloque de código.

A lo largo de este apunte le iremos dando uso a este concepto de manera gradual, particularmente para simplificar la declaración de estructuras complejas (Bloque 3) y la definición de Tipos de Datos Abstractos (Bloque 4).

### Enumeraciones en C

Las **enumeraciones** (`enum`) se utilizan para representar conjuntos finitos y discretos de constantes enteras nombradas. 

Para un análisis detallado de la sintaxis de enumerativos, la asignación de valores, las colisiones en espacios de nombres y las validaciones de rango con switch defensivo, consultá el capítulo específico de {ref}`enumeraciones-capitulo`.

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-typedef-metros-velocidad
Escribí tres declaraciones `typedef` de acuerdo con la regla de la cátedra {ref}`0x3004h`: `distancia_t` y `tiempo_t` como alias de `double`, y `velocidad_t` como alias de `double`. Luego, escribí una pequeña función que reciba una distancia y un tiempo, y retorne la velocidad correspondiente utilizando dichos alias.
:::

:::{solution} ej-typedef-metros-velocidad
:class: dropdown
```c
#include <stdio.h>

// Definición de alias con el sufijo _t obligatorio
typedef double distancia_t;
typedef double tiempo_t;
typedef double velocidad_t;

velocidad_t calcular_velocidad(distancia_t d, tiempo_t t) {
    if (t <= 0.0) {
        return 0.0;
    }
    return d / t;
}
```
:::

:::{exercise}
:label: ej-typedef-portabilidad
Implementá la declaración de tres alias de tipo (`u8_t`, `u16_t`, `u32_t`) que representen de forma explícita enteros sin signo de 8, 16 y 32 bits en una arquitectura donde `char` tiene 8 bits, `short` tiene 16 bits e `int` tiene 32 bits.
:::

:::{solution} ej-typedef-portabilidad
:class: dropdown
```c
typedef unsigned char      u8_t;
typedef unsigned short     u16_t;
typedef unsigned int       u32_t;
```
Estas declaraciones garantizan la portabilidad porque si el código se porta a un microcontrolador donde `int` ocupa 16 bits, solo es necesario redefinir el alias `u32_t` a `unsigned long` en un único archivo centralizado, sin alterar las declaraciones de variables a lo largo de todo el proyecto.
:::

:::{exercise}
:label: ej-typedef-alias-redundante
Explicá de forma conceptual si la expresión `typedef float real_t;` define un tipo de dato físicamente diferente para el compilador y si es válido realizar asignaciones directas sin conversión de tipo entre variables `float` y `real_t`.
:::

:::{solution} ej-typedef-alias-redundante
:class: dropdown
No define un nuevo tipo de dato físicamente diferente.

`typedef` introduce únicamente un **sinónimo o alias sintáctico** en la tabla de símbolos del compilador. Físicamente, el compilador trata a las variables `real_t` como variables de tipo `float` estándar. Por lo tanto, realizar la asignación directa entre variables de ambos tipos es totalmente válido y no requiere ningún moldeo de tipo (*cast*), ya que no existe incompatibilidad alguna.
:::

## Glosario

:::{glossary}
Alias de tipo (typedef)
: Nombre alternativo asignado a un tipo de dato existente para mejorar la legibilidad y abstracción.

Portabilidad
: Capacidad de un código para compilar y ejecutarse correctamente en diferentes arquitecturas de CPU sin cambios mayores.
:::

## Síntesis y Resumen

La directiva `typedef` se emplea para crear alias de tipos en C sin generar nuevos tipos físicos. Su uso facilita la abstracción y la portabilidad del código entre arquitecturas con diferentes tamaños de datos. Por normas de la cátedra, todo alias definido con `typedef` debe utilizar obligatoriamente el sufijo `_t`.

## Referencias y Lecturas Complementarias

- {cite:t}`kernighan_c_2014`. Capítulo 5: Pointers and Arrays y Capítulo 6: Structures (sección `typedef`).
- {cite:t}`king_c_2008`. Capítulo 14: The Preprocessor (secciones de tipos).
