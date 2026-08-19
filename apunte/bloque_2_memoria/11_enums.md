---
title: Tipos Enumerativos (enum)
short_title: ' Enumeraciones'
subtitle: 'Declaración de constantes nombradas, espacios de nombres y validación segura en C'
---

(capitulo-enums)=
## Introducción

Las **enumeraciones** (`enum`) constituyen un mecanismo fundamental en el
lenguaje C para la definición de tipos de datos que representan un **conjunto
finito y discreto** de valores con nombres simbólicos. A diferencia de usar
valores literales o constantes dispersas en el código, las enumeraciones
proporcionan una abstracción semántica que mejora considerablemente la
legibilidad, mantenibilidad y robustez del programa.

Desde una perspectiva técnica, las enumeraciones son esencialmente **constantes
enteras nombradas** que el compilador traduce en tiempo de compilación. Sin
embargo, permiten modelar de forma explícitamente legible conjuntos limitados de
valores, estados o categorías.

## Desarrollo

### 1. `enum` vs. `const` vs. `#define`

Aunque es posible definir constantes enteras con `#define` o una serie de
variables `const`, el uso de `enum` es la práctica superior y más segura para
agrupar constantes relacionadas.

A diferencia de las macros de preprocesador (`#define`), que carecen de tipo y
pueden contaminar el espacio de nombres global mediante simples reemplazos
textuales, `enum` crea un **tipo de dato distinto**. Esto mejora la seguridad de
tipos y permite que el compilador detecte errores lógicos.

Además, los `enum` **auto-numeran** sus miembros secuencialmente (empezando por
defecto desde 0), reduciendo la posibilidad de errores manuales de duplicación.
Esta agrupación lógica no solo hace el código más legible y auto-documentado,
sino que también es reconocida por los depuradores (como GDB), que muestran los
nombres simbólicos de las constantes en lugar de simples números mágicos.

:::{figure} 11/enum_concept.svg
:name: fig-enum-concept
:alt: Concepto de enumeraciones vs números mágicos
:align: center

Las enumeraciones proporcionan nombres simbólicos a valores enteros,
transformando números mágicos en código legible y mantenible.

:::
<!-- {figure} 4/enum_concept.svg -->

### 2. Sintaxis y Espacios de Nombres (Namespaces)

La sintaxis fundamental para declarar una enumeración sigue la estructura típica
de C:

```{code-block} c
:linenos:
enum estado_conexion
{
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    ERROR_CONEXION
};
// Uso para declarar variables
enum estado_conexion estado_actual = DESCONECTADO;
```
<!-- {code-block} c -->

#### El Problema de la Contaminación del Namespace

:::{important} Espacios de Nombres en el Estándar C

Conforme al apartado 6.2.3 del estándar ISO/IEC 9899, C clasifica los
identificadores de un mismo ámbito en cuatro categorías independientes de
espacios de nombres para evitar colisiones cruzadas:
1.  **Etiquetas de sentencias (label names):** Identificadores para `goto`.
2.  **Etiquetas de tipos (tags):** Los nombres precedidos por las palabras clave
    `struct`, `union` o `enum`.
3.  **Miembros de estructuras o uniones (members):** Encapsulados dentro de su
    respectivo contenedor.
4.  **Identificadores ordinarios (ordinary identifiers):** Comprende variables,
    funciones, alias con `typedef` y las constantes lógicas declaradas en un
    `enum`.

:::
<!-- {important} Espacios de Nombres en el Estándar C -->

Dado que las constantes de un `enum` residen en el espacio de nombres de los
**identificadores ordinarios**, no están encapsuladas dentro del tipo `enum` al
que pertenecen. Por lo tanto, entran en conflicto directo con cualquier otra
variable o constante del mismo ámbito que posea el mismo nombre.

#### Solución mediante Prefijos

Para evitar colisiones de nombres, se deben utilizar prefijos consistentes:

```{code-block} c
:linenos:
enum motor_estado
{
    MOTOR_APAGADO,
    MOTOR_ENCENDIDO,
    MOTOR_ERROR
};
enum luz_estado
{
    LUZ_APAGADA,
    LUZ_PRENDIDA,
    LUZ_PARPADEANDO
};
```
<!-- {code-block} c -->

### 3. Asignación de Valores y Definición de Tipos

#### Asignación Explícita
Podés especificar valores explícitos para cualquier constante. Los valores no
especificados continuarán la secuencia desde el último valor asignado:

```{code-block} c
:linenos:
enum codigo_error
{
    EXITO = 0,
    ERROR_ARCHIVO = 100,
    ERROR_MEMORIA,  // Toma el valor 101 automáticamente
    ERROR_PERMISOS, // Toma el valor 102 automáticamente
    ERROR_CRITICO = 500,
    ERROR_FATAL // Toma el valor 501 automáticamente
};
```
<!-- {code-block} c -->

#### Definición de Tipos con `typedef`
Para simplificar la declaración de variables y evitar escribir repetidamente la
palabra clave `enum`, es una buena práctica definir alias de tipo utilizando
`typedef` (siguiendo la regla de estilo {ref}`0x3004h`):

```{code-block} c
:linenos:
typedef enum
{
    OPERACION_SUMA,
    OPERACION_RESTA,
    OPERACION_MULTIPLICACION,
    OPERACION_DIVISION
} operacion_t;
// Declaración directa
operacion_t operacion_actual = OPERACION_SUMA;
```
<!-- {code-block} c -->

### 4. Representación Interna, Promoción Entera y Switch Defensivo

Desde el punto de vista de la arquitectura subyacente, **los tipos enumerativos
en C no constituyen un sistema de tipos fuertes**. El estándar de C establece
que los miembros de un `enum` son constantes de tipo `int`. Por lo tanto, el
compilador realiza una promoción entera automática y permite la coerción
implícita sin generar advertencias (*warnings*):

```{code-block} c
:linenos:
typedef enum
{
    MODO_LECTURA,
    MODO_ESCRITURA
} modo_t;
modo_t modo = MODO_LECTURA;
modo = 100; // Compila sin advertencias, a pesar de que 100 no está en la
            // enumeración
int valor_entero = MODO_ESCRITURA; // Promoción implícita: valor_entero = 1
```
<!-- {code-block} c -->

Este comportamiento expone al sistema a fallos si un dato externo (leído de un
archivo, sensor o red) es mapeado directamente a un enum sin validar su rango
físico. Por ello, es mandatorio aplicar programación defensiva.

#### Patrón de Validación Centinela
Podés agregar una constante centinela (típicamente al final) para validar que un
entero externo pertenezca al rango de la enumeración:

```{code-block} c
:linenos:
typedef enum
{
    ESTADO_INICIAL,
    ESTADO_PROCESANDO,
    ESTADO_COMPLETADO,
    ESTADO_MAX // Centinela que determina el límite del rango
} estado_t;
bool es_estado_valido(int valor)
{
    return (valor >= ESTADO_INICIAL && valor < ESTADO_MAX);
}
```
<!-- {code-block} c -->

#### Patrón de Switch Defensivo
Toda evaluación de una enumeración mediante una estructura `switch` debe
incorporar un caso `default` para atrapar e informar posibles corrupciones de
estado (ver regla de estilo {ref}`0x1008h`):

```{code-block} c
:linenos:
const char *obtener_nombre_estado(estado_t estado)
{
    switch (estado)
    {
    case ESTADO_INICIAL:
        return "Inicial";
    case ESTADO_PROCESANDO:
        return "Procesando";
    case ESTADO_COMPLETADO:
        return "Completado";
    default:
        // Switch defensivo para atrapar desbordamientos
            fprintf(stderr, "Error: estado inválido %d
", estado);
            return "Desconocido";
    }
}
```
<!-- {code-block} c -->

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-enum-namespace-colision
Explicá por qué el siguiente fragmento de código genera un error en tiempo de
compilación y reescribilo aplicando la solución recomendada por buenas
prácticas:
``` c
enum estado_conexion
{
    APAGADO,
    CONECTANDO,
    ACTIVO
};
enum estado_alarma
{
    APAGADO,
    ALERTA,
    DISPARADO
};
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-enum-namespace-colision
:class: dropdown
El error se debe a que las constantes de enumeración residen en el namespace de
los identificadores ordinarios. Las etiquetas `APAGADO` de ambas enumeraciones
colisionan en el mismo ámbito global, provocando un error de redefinición de
símbolo.

La solución consiste en añadir **prefijos únicos** a los miembros de cada
enumeración para evitar colisiones:
``` c
enum estado_conexion
{
    CON_APAGADO,
    CON_CONECTANDO,
    CON_ACTIVO
};
enum estado_alarma
{
    ALA_APAGADA,
    ALA_ALERTA,
    ALA_DISPARADA
};
```
<!-- c -->

:::
<!-- {solution} ej-enum-namespace-colision -->

:::{exercise}
:label: ej-enum-sintaxis-declaracion
Declará una enumeración para representar los niveles de severidad de un error de
sistema (`SEV_BAJA`, `SEV_MEDIA`, `SEV_ALTA`, `SEV_CRITICA`). Luego, mostrá la
sintaxis necesaria para declarar una variable de este tipo e inicializarla con
la constante de severidad alta.

:::
<!-- {exercise} -->

:::{solution} ej-enum-sintaxis-declaracion
:class: dropdown
```{code-block} c
:linenos:
// Declaración de la enumeración
enum nivel_severidad
{
    SEV_BAJA,
    SEV_MEDIA,
    SEV_ALTA,
    SEV_CRITICA
};
// Declaración e inicialización de la variable
enum nivel_severidad severidad_actual = SEV_ALTA;
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-enum-sintaxis-declaracion -->

:::{exercise}
:label: ej-enum-const-define
Mencioná al menos dos ventajas importantes que presenta el uso de enumeraciones
(`enum`) en comparación con el uso de macros del preprocesador (`#define`) para
establecer conjuntos de constantes relacionadas.

:::
<!-- {exercise} -->

:::{solution} ej-enum-const-define
:class: dropdown
1.  **Seguridad y Tipado:** `enum` crea un tipo de dato identificable por el
    compilador, lo que permite realizar comprobaciones de tipo y advertir si
    pasamos un valor incoherente, a diferencia de `#define` que realiza un
    reemplazo de texto literal sin validación semántica.
2.  **Numeración Automática:** El compilador asigna valores de forma secuencial
    y automática, reduciendo la posibilidad de asignar manualmente valores
    duplicados en el conjunto.
3.  **Depuración:** Los depuradores (como GDB) retienen los nombres simbólicos
    de las constantes de una enumeración, facilitando la inspección del estado
    de variables en memoria.

:::
<!-- {solution} ej-enum-const-define -->

:::{exercise}
:label: ej-enum-valores-secuencia
Dada la enumeración:
`enum control { PAUSA = 5, REPRODUCIR, PARAR = 10, GRABAR };`
Deducí el valor entero asignado por el compilador a cada una de las constantes
del conjunto.

:::
<!-- {exercise} -->

:::{solution} ej-enum-valores-secuencia
:class: dropdown
El compilador realiza las siguientes asignaciones:
- `PAUSA`: Toma el valor explícito `5`.
- `REPRODUCIR`: Toma el valor siguiente en secuencia, es decir, `6`.
- `PARAR`: Toma el valor explícito `10`.
- `GRABAR`: Toma el valor siguiente en secuencia desde el último definido, es
  decir, `11`.

:::
<!-- {solution} ej-enum-valores-secuencia -->

:::{exercise}
:label: ej-enum-switch-defensivo
Escribí una función en C que tome como parámetro una variable de tipo `estado_t`
y retorne una cadena de caracteres constante (`const char *`) con el nombre
textual del estado, aplicando un diseño defensivo con un caso `default`.

:::
<!-- {exercise} -->

:::{solution} ej-enum-switch-defensivo
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
const char *obtener_nombre_estado(estado_t estado)
{
    switch (estado)
    {
    case ESTADO_INICIAL:
        return "Inicial";
    case ESTADO_PROCESANDO:
        return "Procesando";
    case ESTADO_COMPLETADO:
        return "Completado";
    default:
        // Switch defensivo obligatorio (Regla 0x1008h)
            fprintf(stderr, "Error: estado inválido: %d
", estado);
            return "Desconocido";
    }
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-enum-switch-defensivo -->

:::{exercise}
:label: ej-enum-bit-flags
Declará una enumeración `permisos_t` utilizando potencias de 2 (representación
en bits) para representar los permisos de `LECTURA`, `ESCRITURA` y `EJECUCION`.
Luego, escribí una expresión en C que combine los permisos de `LECTURA` y
`ESCRITURA` en una única variable mediante operadores lógicos binarios.

:::
<!-- {exercise} -->

:::{solution} ej-enum-bit-flags
:class: dropdown
```{code-block} c
:linenos:
typedef enum
{
    PERM_NINGUNO = 0,
    PERM_LECTURA = 1,   // 0b0001
    PERM_ESCRITURA = 2, // 0b0010
    PERM_EJECUCION = 4  // 0b0100
} permisos_t;
// Combinación de permisos mediante operador OR a nivel de bits (|)
permisos_t mis_permisos =
    PERM_LECTURA | PERM_ESCRITURA; // Resulta en 3 (0b0011)
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-enum-bit-flags -->

## Glosario

:::{glossary}

Tipo enumerativo (enum)
: Tipo de dato que consiste en un conjunto de constantes enteras nombradas.

Namespace (Espacio de nombres)
: Ámbito lógico que agrupa identificadores para evitar conflictos de nombres.

Programación defensiva
: Filosofía de diseño de software que previene fallos mediante validación
exhaustiva de rangos y casos no esperados.

:::
<!-- {glossary} -->

## Síntesis y Resumen

Las enumeraciones (`enum`) agrupan constantes enteras relacionadas en C,
ofreciendo mayor seguridad y autoliteralidad que las macros del preprocesador.
Dado que sus miembros se ubican en el espacio de nombres de los identificadores
ordinarios, se deben usar prefijos para evitar colisiones. Es una buena práctica
usar `typedef` con el sufijo `_t` y validar rangos defensivamente en sentencias
`switch` mediante un caso `default`.

## Referencias y Lecturas Complementarias

- {cite:t}`kernighan_c_2014`. Capítulo 6: Structures (sección `fields`).
- {cite:t}`king_c_2008`. Capítulo 16: Structures, Unions, and Enumerations.
