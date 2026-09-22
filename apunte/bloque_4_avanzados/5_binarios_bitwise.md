---
title: 'Campos de Bits y Operaciones Bitwise'
short_title: 'Bitwise'
subtitle: 'Operadores a nivel de bits y máscaras en C'
---

(bitwise-capitulo)=
# Campos de Bits y Operaciones Bitwise

> **Prerrequisitos**: representación binaria de enteros, operadores lógicos, `uint32_t` y máscaras.
>
> **Objetivos**: 1. Construir una máscara para consultar o modificar un bit. 2. Diferenciar campos de bits de una representación binaria portable.
>
> **Comprobación de salida**: calculá una máscara, aplicala a un valor y justificá qué bits cambian.

---

(campos-de-bits-bit-fields-ahorro-extremo-de-memoria)=
## Campos de Bits (Bit-fields): Ahorro Extremo de Memoria

Los bit-fields permiten definir miembros de una `struct` con un ancho en bits
exacto, ideal para empaquetar flags o valores pequeños.

(sintaxis-y-ejemplo)=
### Sintaxis y Ejemplo

```{code-block} c
:linenos:
typedef struct
{
    unsigned int activo : 1;    // 1 bit
    unsigned int modo_op : 3;   // 3 bits (valores 0-7)
    unsigned int prioridad : 4; // 4 bits (valores 0-15)
} config_t;

```
<!-- {code-block} c -->

El compilador empaquetará estos 8 bits en un solo byte (si es posible).

(acceso-y-type-punning-seguro)=
### Acceso y Type Punning Seguro

Cuando se trabaja con estructuras de campos de bits o representaciones de bajo
nivel, suele ser necesario interpretar una estructura empaquetada como una
secuencia cruda de bytes (por ejemplo, para transmitirla por red) o viceversa.

Un error común para lograr esto es castear la dirección de la estructura
directamente:
``` c
packed_byte_t data;
uint8_t byte_crudo = *(uint8_t *)&data; // ¡ERROR! Violación de strict aliasing
```
<!-- c -->

Esta técnica, llamada *type punning* mediante casteo de punteros, está prohibida
en C moderno. El compilador asume que dos punteros de tipos incompatibles no
apuntan al mismo objeto en memoria (regla de ***strict aliasing***). Optimizar
el código bajo este supuesto permite mejoras de rendimiento significativas, pero
si violamos la regla, el compilador puede reorganizar los accesos y producir un
comportamiento indefinido.

Existen dos formas válidas y seguras de realizar *type punning* en C:
1. **El uso de uniones (`union`)**: En C estándar, escribir en un miembro de una
   unión y leer de otro diferente es un comportamiento bien definido y el método
   preferido para reinterpretación de datos.
2. **Uso de `memcpy`**: Copiar los bytes mediante `memcpy` es seguro y los
   optimizadores modernos suelen eliminar la llamada física a la función,
   generando código máquina óptimo.

(laboratorio-2-inspeccion-de-bit-fields-con-uniones)=
### Laboratorio 2: Inspección de Bit-fields con Uniones

**`bitfield_inspect.c`**

```{code-block} c
:linenos:
#include <stdint.h>
#include <stdio.h>
typedef struct
{
    uint8_t a : 2;
    uint8_t b : 3;
    uint8_t c : 3;
} packed_byte_t;
typedef union
{
    packed_byte_t campos;
    uint8_t valor_raw;
} packed_byte_u;
int main()
{
    packed_byte_u data;
    data.campos.a = 3; // 11b
    data.campos.b = 5; // 101b
    data.campos.c = 7; // 111b
    // Imprimimos la estructura de forma segura respetando el strict aliasing
    printf("sizeof(packed_byte_t) = %zu\n", sizeof(packed_byte_t));
    printf("Byte resultante: 0x%02X\n", data.valor_raw);
    return 0;
}

```
<!-- {code-block} c -->

**Compilación y Ejecución:**

``` bash
gcc -Wextra -Wall bitfield_inspect.c -o bitfield_inspect
./bitfield_inspect
```
<!-- bash -->

**Análisis:** La salida `0xFD` (o `11111101` en binario) puede parecer
sorprendente. El orden en que el compilador asigna los bits dentro del byte es
**implementation-defined**. No asumas un orden específico si necesitás
portabilidad.

:::{exercise}
:label: ejer-bitfield-2
**Decodificador de Paquetes**

Un protocolo de red envía un byte de estado con la siguiente estructura de bits:
- Bit 0: `es_ack` (1=ACK, 0=NACK)
- Bit 1: `es_fin` (1=Fin de transmisión)
- Bits 2-4: `tipo_paquete` (un número de 0 a 7)
- Bits 5-7: `checksum` (un número de 0 a 7)

Creá una `struct` con bit-fields para representar este byte. Escribí una función
que reciba un `unsigned char` y lo imprima de forma legible usando la
estructura.

:::
<!-- {exercise} -->

::::{solution} ejer-bitfield-2
:class: dropdown
```{code-block} c
:linenos:
#include <stdint.h>
#include <stdio.h>
typedef struct
{
    uint8_t es_ack : 1;
    uint8_t es_fin : 1;
    uint8_t tipo_paquete : 3;
    uint8_t checksum : 3;
} estado_paquete_t;
typedef union
{
    estado_paquete_t campos;
    uint8_t byte_completo;
} paquete_decoder_t;
void imprimir_estado_paquete(uint8_t byte_estado)
{
    paquete_decoder_t decoder;
    decoder.byte_completo = byte_estado;
    printf("--- Estado del Paquete (0x%02X) ---\n", byte_estado);
    printf("  ACK: %s\n", decoder.campos.es_ack ? "Sí" : "No");
    printf("  FIN: %s\n", decoder.campos.es_fin ? "Sí" : "No");
    printf("  Tipo: %u\n", decoder.campos.tipo_paquete);
    printf("  Checksum: %u\n", decoder.campos.checksum);
    printf("----------------------------------\n");
}
int main()
{
    // Ejemplo: ACK=1, FIN=0, Tipo=5 (101b), Checksum=3 (011b)
    // Binario: 011 101 0 1 -> 0xDA
    uint8_t paquete = 0b01110101;
    imprimir_estado_paquete(paquete);
    return 0;
}

```
<!-- {code-block} c -->

::::
<!-- {solution} ejer-bitfield-2 -->



---

(operadores-a-nivel-de-bits)=
## Operadores a Nivel de Bits

Los Campos de Bits del apartado anterior operan físicamente con bits
individuales. Para manipularlos de forma explícita en código, C provee un
conjunto de operadores bitwise que actúan sobre la representación binaria de los
enteros.

(introduccion-el-poder-a-nivel-de-bit)=
## Introducción: El Poder a Nivel de Bit

En el corazón de cada operación que realiza una computadora se encuentran los
bits. La **manipulación de bits** es el conjunto de técnicas que nos permite
interactuar directamente con esta representación binaria de los datos. En C,
dominar estas técnicas es una habilidad práctica y poderosa para optimizar el
rendimiento, ahorrar memoria e interactuar con hardware.

(representacion-binaria)=
## Representación Binaria

Todos los tipos de datos en C se almacenan como una secuencia de bits. Un
`unsigned char` (1 byte) que representa el número 200, en binario es `11001000`.

``` text
Bit:      7   6   5   4   3   2   1   0
Valor:  128  64  32  16   8   4   2   1
-----------------------------------------
Binario:  1   1   0   0   1   0   0   0
Suma:   128 + 64+ 0 + 0 + 8 + 0 + 0 + 0 = 200
```
<!-- text -->

(endianness)=
### Endianness

El **endianness** define el orden en que se almacenan en memoria los bytes que
componen un tipo de dato multi-byte (como `int` o `double`). Es un detalle de la
arquitectura del procesador que puede ser crucial en programación de sistemas,
redes o al trabajar con formatos de archivo binarios.

- **Little-endian**: El byte **menos** significativo se almacena en la dirección
  de memoria más baja. Es la arquitectura dominante hoy en día (Intel x86,
  AMD64, Apple Silicon).
- **Big-endian**: El byte **más** significativo se almacena en la dirección de
  memoria más baja. Era común en arquitecturas más antiguas (Motorola 68k,
  SPARC) y se sigue usando como el orden estándar en redes (Network Byte Order).

**Ejemplo con el valor `0x1A2B3C4D` (un `int` de 32 bits):**

| Dirección | Little-endian | Big-endian |
| :--- | :---: | :---: |
| `0x100` | `4D` | `1A` |
| `0x101` | `3C` | `2B` |
| `0x102` | `2B` | `3C` |
| `0x103` | `1A` | `4D` |

**¿Por qué es importante?**

Si escribís un `int` a un archivo en una máquina little-endian y lo leés en una
big-endian, el valor será incorrecto.

**Cómo detectar el endianness en C:**

```{code-block} c
:linenos:
#include <stdint.h>
#include <stdio.h>
int main(void)
{
    uint32_t i = 1;
    char *c = (char *)&i;
    if (*c)
    {
        printf("Little-endian\n");
    }
    else
    {
        printf("Big-endian\n");
    }
    return 0;
}

```
<!-- {code-block} c -->

Este código funciona porque si es little-endian, el byte `01` se almacena en la
primera dirección, y `*c` será `1`. Si es big-endian, el primer byte será `00`,
y `*c` será `0`.

(los-operadores-a-nivel-de-bits)=
## Los Operadores a Nivel de Bits

(1-and-a-nivel-de-bits)=
### 1. AND a nivel de bits (`&`)

El bit del resultado es `1` solo si ambos bits correspondientes en los operandos
son `1`. Su uso principal es para **verificar** o **apagar** bits.

:::{exercise} espar
:label: espar
¿Es un número par?

Un número es par si su bit menos significativo (LSB, bit 0) es 0. Escribí una
función que use el operador `&` para determinar si un número es par.

:::
<!-- {exercise} espar -->

::::{solution} espar
:class: dropdown

:::{code-block} c

#include <stdbool.h>
bool es_par(int numero)
{
    // La máscara 1 (00000001) aísla el último bit.
    // Si el resultado de (numero & 1) es 0, el bit era 0.
    return (numero & 1) == 0;
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} espar -->

(2-or-a-nivel-de-bits)=
### 2. OR a nivel de bits (`|`)

El bit del resultado es `1` si al menos uno de los bits correspondientes es `1`.
Su uso principal es para **encender** bits.

:::{exercise} activar
:label: activar

Encender un Flag Dado un `unsigned char` que representa un
conjunto de 8 flags, escribí una función que encienda el 4to bit (bit en la
posición 3) sin modificar los demás.

:::
<!-- {exercise} activar -->

:::{solution} activar
:class: dropdown

```{code-block} c
:linenos:
void activar_flag_4(unsigned char *estado)
{
    // La máscara (1 << 3) es 8 (00001000).
    // El OR encenderá ese bit sin tocar los otros.
    *estado = *estado | (1 << 3);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} activar -->

(3-xor-a-nivel-de-bits)=
### 3. XOR a nivel de bits (`^`)

El bit del resultado es `1` solo si los bits correspondientes son
**diferentes**. Su uso principal es para **alternar (toggle)** bits.

:::{exercise} intercambio
:label: intercambio

Intercambio con XOR Escribí una función que intercambie los
valores de dos variables enteras **sin usar una variable temporal**, utilizando
únicamente el operador XOR.

:::
<!-- {exercise} intercambio -->

:::{solution} intercambio
:class: dropdown

```{code-block} c
:linenos:
void swap_xor(int *a, int *b)
{
    if (a != b)
    { // Previene que se anulen si apuntan al mismo lugar
        *a = *a ^ *b;
        *b = *a ^ *b; // *b se convierte en el valor original de *a
        *a = *a ^ *b; // *a se convierte en el valor original de *b
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} intercambio -->

(4-not-a-nivel-de-bits)=
### 4. NOT a nivel de bits (`~`)

El operador NOT (complemento a uno) invierte todos los bits de su operando. `0`
se convierte en `1` y `1` en `0`.

:::{exercise} mask
:label: mask

Crear una Máscara para Apagar Escribí una expresión que cree una
máscara para apagar el 2do bit (posición 1) de un `char`, sin afectar a los
demás. 

:::
<!-- {exercise} mask -->

:::{solution} mask
:class: dropdown

```{code-block} c
// Máscara para el 2do bit: (1 << 1) -> 00000010
// Máscara invertida: ~(1 << 1) -> 11111101
unsigned char mascara_apagado = ~(1 << 1);

```
<!-- {code-block} c -->

:::
<!-- {solution} mask -->

(5-desplazamientos-y)=
### 5. Desplazamientos (`<<` y `>>`)

- `<<`: Desplaza los bits a la izquierda. Equivale a multiplicar por potencias
  de 2.

  **Ejemplo:** `5 << 2`

  ```text
  00000101 (5) << 2  -->  00010100 (20)
  ```

- `>>`: Desplaza los bits a la derecha. Equivale a dividir por potencias de 2.

  **Ejemplo:** `20 >> 2`

  ```text
  00010100 (20) >> 2  -->  00000101 (5)
  ```

:::{exercise} multiplicacion
:label: multiplicacion

Multiplicación y División Rápida Escribí dos macros,
`MULT_POR_8(x)` y `DIV_POR_4(x)`, que usen operadores de desplazamiento para
realizar las operaciones.

:::
<!-- {exercise} multiplicacion -->

:::{solution} multiplicacion
:class: dropdown

```{code-block} c
#define MULT_POR_8(x) ((x) << 3) // 2^3 = 8
#define DIV_POR_4(x) ((x) >> 2)  // 2^2 = 4

```
<!-- {code-block} c -->

:::
<!-- {solution} multiplicacion -->

(ejercicios-de-aplicacion-recetario)=
## Ejercicios de Aplicación (Recetario)

(1-obtener-el-n-esimo-bit)=
### 1. Obtener el N-ésimo Bit

:::{exercise} get_bit
:label: get_bit

Escribí una función `int get_bit(int numero, int n)` que devuelva
el valor (0 o 1) del bit en la posición `n`.

:::
<!-- {exercise} get_bit -->

:::{solution} get_bit
:class: dropdown

```{code-block} c
int get_bit(int numero, int n)
{
    // Desplaza el bit n a la posición 0 y usa AND con 1 para aislarlo.
    return (numero >> n) & 1;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} get_bit -->

(2-establecer-el-n-esimo-bit)=
### 2. Establecer el N-ésimo Bit

:::{exercise} set_bit
:label: set_bit

Escribí una función `void set_bit(int *numero, int n)` que
encienda el bit en la posición `n`.

:::
<!-- {exercise} set_bit -->

:::{solution} set_bit
:class: dropdown

```{code-block} c
void set_bit(int *numero, int n)
{
    // Crea una máscara con el bit n encendido (ej: 00001000) y aplica OR.
    *numero |= (1 << n);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} set_bit -->

(3-limpiar-el-n-esimo-bit)=
### 3. Limpiar el N-ésimo Bit

:::{exercise} clear_bit
:label: clear_bit

Escribí una función `void clear_bit(int *numero, int n)` que
apague el bit en la posición `n`.

:::
<!-- {exercise} clear_bit -->

:::{solution} clear_bit
:class: dropdown

```{code-block} c
void clear_bit(int *numero, int n)
{
    // Crea una máscara con el bit n en 0 y el resto en 1, y aplica AND.
    *numero &= ~(1 << n);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} clear_bit -->

(4-contar-bits-encendidos-hamming-weight)=
### 4. Contar Bits Encendidos (Hamming Weight)

:::{exercise} kernighan
:label: kernighan

Implementar una función que cuente el número de bits que están en
`1` en la representación binaria de un número, usando el algoritmo de Brian
Kernighan. 

:::
<!-- {exercise} kernighan -->

:::{solution} kernighan
:class: dropdown

 **Algoritmo de Brian Kernighan**: La operación
`n & (n - 1)` apaga el bit encendido menos significativo. El número de veces que
se puede hacer esta operación antes de que `n` sea 0 es el número de bits
encendidos.

```{code-block} c
:linenos:
int contar_bits_encendidos(int n)
{
    int contador = 0;
    while (n > 0)
    {
        n = n & (n - 1); // Apaga el bit '1' de más a la derecha
        contador++;
    }
    return contador;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} kernighan -->

(5-verificar-si-es-potencia-de-dos)=
### 5. Verificar si es Potencia de Dos

:::{exercise} potencia
:label: potencia

Escribí una función que determine si un número entero positivo es
una potencia de dos (2, 4, 8, 16...).

:::
<!-- {exercise} potencia -->

:::{solution} potencia
:class: dropdown

**Propiedad**: Un número que es potencia de dos
tiene exactamente un bit encendido en su representación binaria (ej. 8 es
`1000`). El número `n-1` tendrá todos los bits a la derecha de ese bit
encendidos (ej. 7 es `0111`). Por lo tanto, `n & (n - 1)` será siempre cero.

```{code-block} c
:linenos:
#include <stdbool.h>
bool es_potencia_de_dos(int n)
{
    // n > 0 asegura que no se incluya el 0.
    // (n & (n - 1)) == 0 verifica que solo haya un bit encendido.
    return (n > 0) && ((n & (n - 1)) == 0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} potencia -->

(glosario_bitwise)=
## Glosario

:::{glossary}

Máscara de Bits (Bitmask)
: Un valor numérico utilizado para seleccionar,
modificar o consultar bits específicos de otro valor mediante operaciones a
nivel de bits como AND, OR y XOR.

Endianness
: Se refiere al orden en que se almacenan en memoria los bytes que
componen un tipo de dato multibyte. Es una consideración crucial para la
portabilidad de datos binarios.

:::
<!-- {glossary} -->


---

(bitmasks-para-errores-multiples)=
## Bitmasks para Errores Múltiples

Una aplicación directa de los operadores bitwise en ingeniería de sistemas es la
codificación de múltiples errores en un único entero mediante *bitmasks*. Este
patrón es ubicuo en drivers, sistemas embebidos y APIs de bajo nivel.

(introduccion_bitmasks_errores)=
## Introducción

En muchas situaciones reales, una operación puede fallar por múltiples razones
simultáneas. Por ejemplo, al validar datos de un formulario, pueden existir
varios campos inválidos al mismo tiempo. Reportar solo el primer error obliga al
usuario a corregir y reintentar múltiples veces. Una mejor solución es reportar
**todas** las causas de error simultáneamente.

Este apunte presenta técnicas para manejar múltiples códigos de error usando
**bitmasks con enumeraciones**, permitiendo representar y comunicar
combinaciones de errores de forma eficiente y expresiva.

:::{important} Errores Compuestos

Cuando múltiples validaciones pueden fallar independientemente, es más útil
reportar todas las fallas simultáneamente en lugar de forzar al usuario a
corregir de a uno. Las bitmasks permiten representar combinaciones de errores en
un solo valor entero.

:::
<!-- {important} Errores Compuestos -->

(problema-un-solo-codigo-de-error)=
## Problema: Un Solo Código de Error

(enfoque-tradicional-un-error)=
### Enfoque Tradicional (Un Error)

```{code-block} c
:linenos:
typedef enum
{
    ERROR_NINGUNO = 0,
    ERROR_NOMBRE_VACIO,
    ERROR_EMAIL_INVALIDO,
    ERROR_EDAD_FUERA_RANGO,
    ERROR_TELEFONO_INVALIDO
} error_validacion_t;
error_validacion_t validar_usuario(const usuario_t *usuario)
{
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0)
    {
        return ERROR_NOMBRE_VACIO; // Retorna solo el primero
    }
    if (!es_email_valido(usuario->email))
    {
        return ERROR_EMAIL_INVALIDO; // Nunca llega aquí si nombre falla
    }
    if (usuario->edad < 18 || usuario->edad > 120)
    {
        return ERROR_EDAD_FUERA_RANGO;
    }
    if (!es_telefono_valido(usuario->telefono))
    {
        return ERROR_TELEFONO_INVALIDO;
    }
    return ERROR_NINGUNO;
}

```
<!-- {code-block} c -->

**Problema:** Si el nombre está vacío Y el email es inválido, el usuario solo
sabrá del nombre. Deberá corregir y volver a intentar para descubrir el
siguiente error.

(solucion-codigos-de-error-con-bitmasks)=
## Solución: Códigos de Error con Bitmasks

(definicion-con-potencias-de-2)=
### Definición con Potencias de 2

Para representar múltiples errores simultáneamente, cada código de error debe
ser una potencia de 2 (un único bit activado):

```{code-block} c
:linenos:
typedef enum
{
    ERROR_NINGUNO = 0,                // 0b00000000
    ERROR_NOMBRE_VACIO = 1 << 0,      // 0b00000001
    ERROR_EMAIL_INVALIDO = 1 << 1,    // 0b00000010
    ERROR_EDAD_FUERA_RANGO = 1 << 2,  // 0b00000100
    ERROR_TELEFONO_INVALIDO = 1 << 3, // 0b00001000
    ERROR_DNI_INVALIDO = 1 << 4,      // 0b00010000
    ERROR_DIRECCION_VACIA = 1 << 5,   // 0b00100000
    ERROR_CIUDAD_INVALIDA = 1 << 6    // 0b01000000
} errores_validacion_t;
// Tipo para almacenar combinaciones
typedef unsigned int errores_t;

```
<!-- {code-block} c -->

(acumular-multiples-errores)=
### Acumular Múltiples Errores

```{code-block} c
:linenos:
errores_t validar_usuario(const usuario_t *usuario)
{
    errores_t errores = ERROR_NINGUNO;
    // Validar cada campo independientemente
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0)
    {
        errores |= ERROR_NOMBRE_VACIO; // OR para acumular
    }
    if (!es_email_valido(usuario->email))
    {
        errores |= ERROR_EMAIL_INVALIDO;
    }
    if (usuario->edad < 18 || usuario->edad > 120)
    {
        errores |= ERROR_EDAD_FUERA_RANGO;
    }
    if (!es_telefono_valido(usuario->telefono))
    {
        errores |= ERROR_TELEFONO_INVALIDO;
    }
    if (!es_dni_valido(usuario->dni))
    {
        errores |= ERROR_DNI_INVALIDO;
    }
    return errores;
}

```
<!-- {code-block} c -->

(verificar-presencia-de-errores)=
### Verificar Presencia de Errores

```{code-block} c
:linenos:
// Verificar si hay algún error
bool hay_errores(errores_t errores)
{
    return errores != ERROR_NINGUNO;
}
// Verificar un error específico
bool tiene_error(errores_t errores, errores_validacion_t error_especifico)
{
    return (errores & error_especifico) != 0;
}
// Uso
errores_t resultado = validar_usuario(&usuario);
if (hay_errores(resultado))
{
    if (tiene_error(resultado, ERROR_NOMBRE_VACIO))
    {
        printf("Error: El nombre no puede estar vacío\n");
    }
    if (tiene_error(resultado, ERROR_EMAIL_INVALIDO))
    {
        printf("Error: El formato del email es inválido\n");
    }
    if (tiene_error(resultado, ERROR_EDAD_FUERA_RANGO))
    {
        printf("Error: La edad debe estar entre 18 y 120\n");
    }
}

```
<!-- {code-block} c -->

(operaciones-con-bitmasks-de-error)=
## Operaciones con Bitmasks de Error

(agregar-errores)=
### Agregar Errores

``` c
errores_t errores = ERROR_NINGUNO;
// Agregar un error
errores |= ERROR_NOMBRE_VACIO;
// Agregar múltiples errores a la vez
errores |= (ERROR_EMAIL_INVALIDO | ERROR_EDAD_FUERA_RANGO);
```
<!-- c -->

(remover-errores)=
### Remover Errores

``` c
// Remover un error específico
errores &= ~ERROR_EMAIL_INVALIDO;
// Remover múltiples errores
errores &= ~(ERROR_NOMBRE_VACIO | ERROR_DNI_INVALIDO);
```
<!-- c -->

(alternar-toggle-errores)=
### Alternar (Toggle) Errores

``` c
// Alternar un error (si está, lo quita; si no está, lo agrega)
errores ^= ERROR_TELEFONO_INVALIDO;
```
<!-- c -->

(verificar-todos-o-alguno)=
### Verificar Todos o Alguno

```{code-block} c
:linenos:
// Verificar si TODOS los errores especificados están presentes
bool tiene_todos(errores_t errores, errores_t conjunto)
{
    return (errores & conjunto) == conjunto;
}
// Verificar si ALGUNO de los errores está presente
bool tiene_alguno(errores_t errores, errores_t conjunto)
{
    return (errores & conjunto) != 0;
}
// Uso
if (tiene_todos(resultado, ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO))
{
    printf("Faltan tanto nombre como email\n");
}
if (tiene_alguno(resultado, ERROR_EDAD_FUERA_RANGO | ERROR_DNI_INVALIDO))
{
    printf("Problema con edad o DNI\n");
}

```
<!-- {code-block} c -->

(contar-errores)=
### Contar Errores

```{code-block} c
:linenos:
int contar_errores(errores_t errores)
{
    int contador = 0;
    // Contar bits activados
    while (errores)
    {
        contador += errores & 1;
        errores >>= 1;
    }
    return contador;
}
// Alternativa más eficiente (GCC builtin)
int contar_errores_rapido(errores_t errores)
{
    return __builtin_popcount(errores);
}

```
<!-- {code-block} c -->

(casos-practicos)=
## Casos Prácticos

(caso-1-validacion-de-formulario-web)=
### Caso 1: Validación de Formulario Web

```{code-block} c
:linenos:
typedef enum
{
    ERROR_FORM_NINGUNO = 0,
    ERROR_FORM_USUARIO_VACIO = 1 << 0,
    ERROR_FORM_PASSWORD_CORTO = 1 << 1,
    ERROR_FORM_PASSWORD_DEBIL = 1 << 2,
    ERROR_FORM_EMAIL_INVALIDO = 1 << 3,
    ERROR_FORM_EDAD_INVALIDA = 1 << 4,
    ERROR_FORM_TERMINOS_NO_ACEPTADOS = 1 << 5
} errores_formulario_t;
errores_t validar_registro(const formulario_registro_t *form)
{
    errores_t errores = ERROR_FORM_NINGUNO;
    if (form->usuario == NULL || strlen(form->usuario) < 3)
    {
        errores |= ERROR_FORM_USUARIO_VACIO;
    }
    if (form->password == NULL || strlen(form->password) < 8)
    {
        errores |= ERROR_FORM_PASSWORD_CORTO;
    }
    else if (!password_es_fuerte(form->password))
    {
        errores |= ERROR_FORM_PASSWORD_DEBIL;
    }
    if (!es_email_valido(form->email))
    {
        errores |= ERROR_FORM_EMAIL_INVALIDO;
    }
    if (form->edad < 13)
    {
        errores |= ERROR_FORM_EDAD_INVALIDA;
    }
    if (!form->acepta_terminos)
    {
        errores |= ERROR_FORM_TERMINOS_NO_ACEPTADOS;
    }
    return errores;
}
void mostrar_errores_formulario(errores_t errores)
{
    if (errores == ERROR_FORM_NINGUNO)
    {
        printf("Formulario válido\n");
        return;
    }
    printf("Errores en el formulario:\n");
    if (errores & ERROR_FORM_USUARIO_VACIO)
    {
        printf("  - El nombre de usuario debe tener al menos 3 caracteres\n");
    }
    if (errores & ERROR_FORM_PASSWORD_CORTO)
    {
        printf("  - La contraseña debe tener al menos 8 caracteres\n");
    }
    if (errores & ERROR_FORM_PASSWORD_DEBIL)
    {
        printf("  - La contraseña debe contener mayúsculas, minúsculas y "
               "números\n");
    }
    if (errores & ERROR_FORM_EMAIL_INVALIDO)
    {
        printf("  - El formato del email es inválido\n");
    }
    if (errores & ERROR_FORM_EDAD_INVALIDA)
    {
        printf("  - Debe ser mayor de 13 años para registrarse\n");
    }
    if (errores & ERROR_FORM_TERMINOS_NO_ACEPTADOS)
    {
        printf("  - Debe aceptar los términos y condiciones\n");
    }
}

```
<!-- {code-block} c -->

(caso-2-verificacion-de-permisos)=
### Caso 2: Verificación de Permisos

```{code-block} c
:linenos:
typedef enum
{
    PERMISO_NINGUNO = 0,
    PERMISO_LEER = 1 << 0,      // 0b00000001
    PERMISO_ESCRIBIR = 1 << 1,  // 0b00000010
    PERMISO_EJECUTAR = 1 << 2,  // 0b00000100
    PERMISO_ELIMINAR = 1 << 3,  // 0b00001000
    PERMISO_COMPARTIR = 1 << 4, // 0b00010000
    PERMISO_ADMIN = 1 << 5      // 0b00100000
} permisos_t;
typedef unsigned int permisos_usuario_t;
// Constantes útiles
const permisos_usuario_t PERMISOS_LECTURA_ESCRITURA =
    PERMISO_LEER | PERMISO_ESCRIBIR;
const permisos_usuario_t PERMISOS_COMPLETOS =
    PERMISO_LEER | PERMISO_ESCRIBIR | PERMISO_EJECUTAR | PERMISO_ELIMINAR |
    PERMISO_COMPARTIR;
bool puede_realizar_accion(permisos_usuario_t permisos_usuario,
                           permisos_t permiso_requerido)
{
    return (permisos_usuario & permiso_requerido) == permiso_requerido;
}
permisos_usuario_t otorgar_permiso(permisos_usuario_t actual,
                                   permisos_t nuevo_permiso)
{
    return actual | nuevo_permiso;
}
permisos_usuario_t revocar_permiso(permisos_usuario_t actual,
                                   permisos_t permiso_a_revocar)
{
    return actual & ~permiso_a_revocar;
}
// Uso
permisos_usuario_t mis_permisos = PERMISO_LEER | PERMISO_ESCRIBIR;
if (puede_realizar_accion(mis_permisos, PERMISO_ELIMINAR))
{
    eliminar_archivo();
}
else
{
    printf("No tienes permiso para eliminar\n");
}
// Otorgar permiso de ejecución
mis_permisos = otorgar_permiso(mis_permisos, PERMISO_EJECUTAR);
// Revocar permiso de escritura
mis_permisos = revocar_permiso(mis_permisos, PERMISO_ESCRIBIR);

```
<!-- {code-block} c -->

(caso-3-estado-de-conexion-de-red)=
### Caso 3: Estado de Conexión de Red

```{code-block} c
:linenos:
typedef enum
{
    RED_OK = 0,
    RED_SIN_CONEXION = 1 << 0,
    RED_TIMEOUT = 1 << 1,
    RED_DNS_FALLO = 1 << 2,
    RED_SSL_ERROR = 1 << 3,
    RED_CERTIFICADO_INVALIDO = 1 << 4,
    RED_PUERTO_BLOQUEADO = 1 << 5,
    RED_PROXY_ERROR = 1 << 6
} errores_red_t;
typedef struct
{
    errores_t errores;
    int codigo_http;
    char *mensaje;
} resultado_conexion_t;
resultado_conexion_t conectar_servidor(const char *url)
{
    resultado_conexion_t resultado = {
        .errores = RED_OK, .codigo_http = 0, .mensaje = NULL};
    // Intentar resolver DNS
    if (!resolver_dns(url))
    {
        resultado.errores |= RED_DNS_FALLO;
    }
    // Verificar conectividad básica
    if (!hay_conexion_internet())
    {
        resultado.errores |= RED_SIN_CONEXION;
    }
    // Intentar conexión
    if (!conectar_con_timeout(url, 5000))
    {
        resultado.errores |= RED_TIMEOUT;
    }
    // Verificar SSL si es HTTPS
    if (es_https(url) && !verificar_ssl(url))
    {
        resultado.errores |= RED_SSL_ERROR;
        if (!certificado_valido(url))
        {
            resultado.errores |= RED_CERTIFICADO_INVALIDO;
        }
    }
    return resultado;
}
void diagnosticar_conexion(const resultado_conexion_t *resultado)
{
    if (resultado->errores == RED_OK)
    {
        printf("Conexión exitosa\n");
        return;
    }
    printf("Problemas detectados:\n");
    if (resultado->errores & RED_SIN_CONEXION)
    {
        printf("  [CRÍTICO] No hay conexión a Internet\n");
    }
    if (resultado->errores & RED_DNS_FALLO)
    {
        printf("  [ERROR] No se pudo resolver el nombre de dominio\n");
    }
    if (resultado->errores & RED_TIMEOUT)
    {
        printf("  [ERROR] Tiempo de espera agotado\n");
    }
    if (resultado->errores & RED_SSL_ERROR)
    {
        printf("  [ADVERTENCIA] Error en la conexión SSL\n");
    }
    if (resultado->errores & RED_CERTIFICADO_INVALIDO)
    {
        printf("  [ADVERTENCIA] El certificado no es válido o ha expirado\n");
    }
    // Sugerencias según la combinación
    if ((resultado->errores & RED_SIN_CONEXION) &&
        (resultado->errores & RED_DNS_FALLO))
    {
        printf("\nSugerencia: Verifica tu conexión de red\n");
    }
    else if (resultado->errores & RED_CERTIFICADO_INVALIDO)
    {
        printf("\nSugerencia: Verifica la fecha del sistema\n");
    }
}

```
<!-- {code-block} c -->

(caso-4-validacion-de-documento)=
### Caso 4: Validación de Documento

```{code-block} c
:linenos:
typedef enum
{
    DOC_VALIDO = 0,
    DOC_ENCABEZADO_INVALIDO = 1 << 0,
    DOC_FORMATO_CORRUPTO = 1 << 1,
    DOC_VERSION_NO_SOPORTADA = 1 << 2,
    DOC_FIRMA_INVALIDA = 1 << 3,
    DOC_CHECKSUM_ERROR = 1 << 4,
    DOC_METADATOS_FALTANTES = 1 << 5,
    DOC_CONTENIDO_TRUNCADO = 1 << 6
} errores_documento_t;
errores_t validar_documento(const documento_t *doc)
{
    errores_t errores = DOC_VALIDO;
    // Validaciones independientes
    if (!validar_encabezado(doc))
    {
        errores |= DOC_ENCABEZADO_INVALIDO;
    }
    if (!validar_formato(doc))
    {
        errores |= DOC_FORMATO_CORRUPTO;
    }
    if (doc->version > VERSION_MAX_SOPORTADA)
    {
        errores |= DOC_VERSION_NO_SOPORTADA;
    }
    if (!verificar_firma_digital(doc))
    {
        errores |= DOC_FIRMA_INVALIDA;
    }
    if (!verificar_checksum(doc))
    {
        errores |= DOC_CHECKSUM_ERROR;
    }
    if (!tiene_metadatos_requeridos(doc))
    {
        errores |= DOC_METADATOS_FALTANTES;
    }
    if (doc->tamanio_real < doc->tamanio_esperado)
    {
        errores |= DOC_CONTENIDO_TRUNCADO;
    }
    return errores;
}
bool es_error_critico(errores_t errores)
{
    // Errores que impiden procesar el documento
    const errores_t ERRORES_CRITICOS =
        DOC_FORMATO_CORRUPTO | DOC_CHECKSUM_ERROR | DOC_CONTENIDO_TRUNCADO;
    return (errores & ERRORES_CRITICOS) != 0;
}
bool es_error_recuperable(errores_t errores)
{
    // Errores que permiten continuar con precaución
    const errores_t ERRORES_RECUPERABLES =
        DOC_METADATOS_FALTANTES | DOC_VERSION_NO_SOPORTADA;
    return (errores & ERRORES_RECUPERABLES) != 0 && !es_error_critico(errores);
}

```
<!-- {code-block} c -->

(funciones-auxiliares-genericas)=
## Funciones Auxiliares Genéricas

(conversion-a-cadenas)=
### Conversión a Cadenas

```{code-block} c
:linenos:
typedef struct
{
    errores_validacion_t codigo;
    const char *mensaje;
} mapeo_error_t;
const mapeo_error_t MENSAJES_ERROR[] = {
    {ERROR_NOMBRE_VACIO, "El nombre no puede estar vacío"},
    {ERROR_EMAIL_INVALIDO, "Formato de email inválido"},
    {ERROR_EDAD_FUERA_RANGO, "La edad debe estar entre 18 y 120"},
    {ERROR_TELEFONO_INVALIDO, "Formato de teléfono inválido"},
    {ERROR_DNI_INVALIDO, "DNI inválido"},
    {ERROR_DIRECCION_VACIA, "La dirección no puede estar vacía"},
    {ERROR_CIUDAD_INVALIDA, "Ciudad no válida"}};
void imprimir_errores(errores_t errores)
{
    if (errores == ERROR_NINGUNO)
    {
        printf("Sin errores\n");
        return;
    }
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    printf("Errores encontrados:\n");
    for (int i = 0; i < num_errores; i++)
    {
        if (errores & MENSAJES_ERROR[i].codigo)
        {
            printf("  - %s\n", MENSAJES_ERROR[i].mensaje);
        }
    }
}

```
<!-- {code-block} c -->

(construccion-de-json-con-errores)=
### Construcción de JSON con Errores

```{code-block} c
:linenos:
char *errores_a_json(errores_t errores)
{
    if (errores == ERROR_NINGUNO)
    {
        return strdup("{\"errores\": []}");
    }
    // Buffer dinámico (simplificado)
    char buffer[1024] = "{\"errores\": [";
    bool primero = true;
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    for (int i = 0; i < num_errores; i++)
    {
        if (errores & MENSAJES_ERROR[i].codigo)
        {
            if (!primero)
            {
                strcat(buffer, ", ");
            }
            strcat(buffer, "\"");
            strcat(buffer, MENSAJES_ERROR[i].mensaje);
            strcat(buffer, "\"");
            primero = false;
        }
    }
    strcat(buffer, "]}");
    return strdup(buffer);
}

```
<!-- {code-block} c -->

(limites-y-consideraciones)=
## Límites y Consideraciones

(numero-maximo-de-errores)=
### Número Máximo de Errores

Con un `unsigned int` (32 bits), podés representar hasta **32 errores
diferentes**. Si necesitás más:

```{code-block} c
:linenos:
// Para 64 errores
typedef unsigned long long errores_extendido_t;
typedef enum
{
    ERROR_1 = 1ULL << 0,
    ERROR_2 = 1ULL << 1,
    // ...
    ERROR_64 = 1ULL << 63
} errores_64_t;

```
<!-- {code-block} c -->

(arrays-de-bitmasks)=
### Arrays de Bitmasks

Para sistemas muy complejos con cientos de posibles errores:

```{code-block} c
:linenos:
#define NUM_PALABRAS_ERROR 4 // 4 * 32 = 128 errores posibles
typedef struct
{
    unsigned int palabras[NUM_PALABRAS_ERROR];
} errores_multiples_t;
void agregar_error(errores_multiples_t *errores, int numero_error)
{
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    if (palabra < NUM_PALABRAS_ERROR)
    {
        errores->palabras[palabra] |= (1U << bit);
    }
}
bool tiene_error_multiples(const errores_multiples_t *errores,
                           int numero_error)
{
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    if (palabra < NUM_PALABRAS_ERROR)
    {
        return (errores->palabras[palabra] & (1U << bit)) != 0;
    }
    return false;
}

```
<!-- {code-block} c -->

(binarios_bitwise-buenas-practicas)=
## Buenas Prácticas

(1-documentar-los-codigos)=
### 1. Documentar los Códigos

```{code-block} c
:linenos:
/**
 * Códigos de error para validación de usuarios.
 * Pueden combinarse usando OR bitwise (|).
 *
 * Ejemplo:
 *   errores_t resultado = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
 */
typedef enum
{
    ERROR_NINGUNO = 0,              ///< Sin errores
    ERROR_NOMBRE_VACIO = 1 << 0,    ///< Nombre NULL o vacío
    ERROR_EMAIL_INVALIDO = 1 << 1,  ///< Formato email inválido
    ERROR_EDAD_FUERA_RANGO = 1 << 2 ///< Edad < 18 o > 120
} errores_validacion_t;

```
<!-- {code-block} c -->

(2-usar-nombres-descriptivos)=
### 2. Usar Nombres Descriptivos

```{code-block} c
:linenos:
// Bien: nombres claros
ERROR_NOMBRE_VACIO
ERROR_EMAIL_INVALIDO
// Mal: nombres crípticos
ERR_1
ERR_NOM
E_MAIL

```
<!-- {code-block} c -->

(3-agrupar-errores-relacionados)=
### 3. Agrupar Errores Relacionados

```{code-block} c
:linenos:
// Errores de entrada
const errores_t ERRORES_ENTRADA =
    ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO | ERROR_DNI_INVALIDO;
// Errores de rango
const errores_t ERRORES_RANGO = ERROR_EDAD_FUERA_RANGO | ERROR_FECHA_INVALIDA;
// Verificar grupo
if (errores & ERRORES_ENTRADA)
{
    printf("Hay problemas con los datos de entrada\n");
}

```
<!-- {code-block} c -->

(4-separar-errores-de-advertencias)=
### 4. Separar Errores de Advertencias

```{code-block} c
:linenos:
typedef enum
{
    // Errores (bits 0-15)
    ERROR_NOMBRE_VACIO = 1 << 0,
    ERROR_EMAIL_INVALIDO = 1 << 1,
    // Advertencias (bits 16-31)
    WARN_PASSWORD_DEBIL = 1 << 16,
    WARN_NOMBRE_LARGO = 1 << 17
} validacion_t;
const validacion_t MASCARA_ERRORES = 0x0000FFFF;
const validacion_t MASCARA_ADVERTENCIAS = 0xFFFF0000;
bool solo_advertencias(validacion_t resultado)
{
    return (resultado & MASCARA_ERRORES) == 0 &&
           (resultado & MASCARA_ADVERTENCIAS) != 0;
}

```
<!-- {code-block} c -->

(comparacion-con-alternativas)=
## Comparación con Alternativas

(vs-array-de-codigos)=
### vs. Array de Códigos

**Bitmask:**
``` c
errores_t errores = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
// Tamaño: 4 bytes (un int)
// Verificación: O(1)
```
<!-- c -->

**Array:**
``` c
int errores[] = {ERROR_NOMBRE_VACIO, ERROR_EMAIL_INVALIDO};
int num_errores = 2;
// Tamaño: 8+ bytes (dos ints + contador)
// Verificación: O(n)
```
<!-- c -->

(vs-lista-enlazada)=
### vs. Lista Enlazada

**Bitmask:**
- Tamaño fijo y predecible
- No requiere memoria dinámica
- Operaciones muy rápidas
- Limitado a número fijo de errores

**Lista:**
- Tamaño variable
- Requiere malloc/free
- Operaciones más lentas
- Ilimitado número de errores

(integracion-con-otros-patrones)=
## Integración con Otros Patrones

(con-unico-retorno)=
### Con Único Retorno

```{code-block} c
:linenos:
errores_t procesar_formulario(const formulario_t *form)
{
    errores_t resultado = ERROR_NINGUNO;
    // Acumular errores
    resultado |= validar_campos(form);
    resultado |= validar_formato(form);
    resultado |= validar_coherencia(form);
    // Único retorno con todos los errores acumulados
    return resultado;
}

```
<!-- {code-block} c -->

(con-codigos-de-estado)=
### Con Códigos de Estado

```{code-block} c
:linenos:
typedef struct
{
    bool exito;
    errores_t errores;
    void *datos;
} resultado_operacion_t;
resultado_operacion_t realizar_operacion(const datos_t *entrada)
{
    resultado_operacion_t resultado = {
        .exito = false, .errores = ERROR_NINGUNO, .datos = NULL};
    resultado.errores = validar_entrada(entrada);
    if (resultado.errores == ERROR_NINGUNO)
    {
        resultado.datos = procesar(entrada);
        resultado.exito = (resultado.datos != NULL);
    }
    return resultado;
}

```
<!-- {code-block} c -->

(binarios_bitwise-resumen)=
## Resumen

**Ventajas de códigos de error con bitmasks:**

1. **Eficiencia:** Representar múltiples errores en un solo entero
2. **Expresividad:** Operaciones bitwise claras y concisas
3. **Completitud:** Reportar todos los problemas simultáneamente
4. **Flexibilidad:** Combinar, agregar, remover errores fácilmente
5. **Performance:** Operaciones muy rápidas (solo operaciones de bits)

**Cuándo usar:**
- Validaciones con múltiples campos independientes
- Permisos y flags de estado
- Diagnóstico de problemas complejos
- APIs que deben reportar errores detallados

**Cuándo evitar:**
- Si solo hay un posible error a la vez
- Cuando necesitás más de 32-64 códigos diferentes
- Si la información del error es muy compleja (usa estructuras)

Los códigos de error con bitmasks son una herramienta poderosa para mejorar la
usabilidad de APIs y aplicaciones, permitiendo comunicar de forma eficiente y
completa todas las causas de un problema.
