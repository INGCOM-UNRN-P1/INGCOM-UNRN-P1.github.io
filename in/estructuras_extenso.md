---
title: "Estructuras y Uniones en C — Apunte Extendido y Laboratorio"
short_title: "Structs avanzado"
subtitle: "Inspección, empaquetado, aliasing y ejemplos prácticos"
numbering:
  code: true
---

# Objetivo

Este apunte extiende **completamente** el material sobre `struct` y `union` en C.
Incluye: teoría profunda (alineación, padding, aliasing, bit-fields, flexible
array members), patrones seguros (uniones etiquetadas, asignación dinámica),
ejemplos completos, y **llamadas a programas** y comandos para inspeccionar el
comportamiento en tiempo de ejecución y en el binario. Los ejemplos están
listos para compilar y ejecutar en un sistema Linux con herramientas
habituales (`gcc`, `gdb`, `hexdump/xxd`, `objdump`, `valgrind`, `pahole` opcional).

> **Advertencia:** Muchos detalles son **dependientes de la plataforma**
> (endianness, tamaño de tipos, alineaciones). Los ejemplos asumen una
> arquitectura **little-endian** típica (x86_64). Verificá siempre tus
> resultados en tu plataforma.

## Reglas de estilo aplicadas

- Nombres de tipos con sufijo `_t`. {ref}`0x001Eh`.
- Documentación con `@param` y `@returns`. {ref}`0x000Ah`.
- No variables globales innecesarias. {ref}`0x000Bh`.
- Indentación: 4 espacios. {ref}`0x0013h`.
- Inicialización explícita de estructuras. {ref}`0x0003h`.

---

# 1. Lista de conceptos cubiertos (rápido)

- Declaración y typedef de `struct`
- Inicializadores (posicionales y designados)
- `offsetof` y `sizeof`
- Alineación (`alignof`, `_Alignof`, `stdalign.h`)
- Padding y empaquetado (`#pragma pack`, `__attribute__((packed))`)
- Uniones y uniones etiquetadas (tagged unions)
- Bit-fields: orden y portabilidad
- Flexible array member (FAM)
- Type punning, strict aliasing y `memcpy`
- Inspección en binario: `hexdump` / `xxd`
- Depuración con `gdb` (mostrar bytes, obtener offsets)
- Herramientas de análisis: `valgrind`, `pahole`, `objdump`

---

# 2. Herramientas necesarias (sugeridas)

```bash
sudo apt update
sudo apt install -y build-essential gdb valgrind xxd binutils dwarves
```

- `gcc` / `clang` — compilación.
- `gdb` — inspección en tiempo de ejecución.
- `hexdump` o `xxd` — ver bytes del fichero/estructura.
- `objdump`, `readelf` — inspección del binario.
- `valgrind` — detección de fugas y uso de memoria no inicializada.
- `pahole` (paquete `dwarves`) — visualizar "holes" (agujeros) en `struct`.
  *Opcional pero muy útil para ver padding.*

---

# 3. Ejemplos prácticos y laboratorio paso a paso

A continuación hay programas completos. Cada ejemplo incluye instrucciones
de compilación y los comandos para inspección con `xxd`, `gdb` y `valgrind`.
Copiá cada archivo a tu máquina, compilalo y ejecutalo para explorar.

## 3.1. Inspección de layout: `layout_inspect.c`

Este ejemplo muestra `sizeof`, `offsetof`, direcciones de miembros, y genera
un volcado binario que podés inspeccionar con `xxd` o `hexdump`.

```c
/* layout_inspect.c
 *
 * Ejemplo: inspección de padding y layout en memoria.
 *
 * Compilar:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g layout_inspect.c -o layout_inspect
 *
 * Ejecutar:
 *   ./layout_inspect
 *   xxd -g 1 struct_dump.bin | sed -n '1,3p'   # o hexdump -C struct_dump.bin
 */

#include <stdio.h>
#include <stddef.h>  /* offsetof */
#include <stdint.h>
#include <inttypes.h>

typedef struct {
    char a;     /* 1 byte */
    int  b;     /* 4 bytes (posible alineación) */
    char c;     /* 1 byte */
} ejemplo_padding_t;

/**
 * Imprime información de layout usando sizeof y offsetof.
 */
int main(void)
{
    ejemplo_padding_t s = { .a = 'a', .b = 0x11223344, .c = 'z' };
    FILE *fp = NULL;

    printf("sizeof(ejemplo_padding_t) = %zu\n", sizeof(ejemplo_padding_t));
    printf("offsetof(a) = %zu\n", offsetof(ejemplo_padding_t, a));
    printf("offsetof(b) = %zu\n", offsetof(ejemplo_padding_t, b));
    printf("offsetof(c) = %zu\n", offsetof(ejemplo_padding_t, c));

    printf("\\nDirecciones (en este run):\n");
    printf("  &s       = %p\n", (void *)&s);
    printf("  &s.a     = %p\n", (void *)&s.a);
    printf("  &s.b     = %p\n", (void *)&s.b);
    printf("  &s.c     = %p\n", (void *)&s.c);

    /* Volcar la estructura en un fichero binario para inspección byte a byte. */
    fp = fopen("struct_dump.bin", "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    if (fwrite(&s, sizeof(s), 1, fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return 1;
    }
    fclose(fp);

    printf("\\nVolcado creado: struct_dump.bin (usa xxd o hexdump para verlo)\\n");
    return 0;
}
```

### Qué observar

- `sizeof` probablemente sea mayor que la suma de los tamaños de los miembros.
- El `xxd` mostrará bytes de padding entre `a` y `b`, y quizá después de `c`.
- En **little-endian**, `0x11223344` se almacena como `44 33 22 11` en bytes.

**Comandos de inspección recomendados**

```bash
# compilar
gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g layout_inspect.c -o layout_inspect

# ejecutar y crear volcado
./layout_inspect

# ver bytes (salida típica esperada en x86_64 little-endian):
hexdump -C struct_dump.bin
# 00000000  61 00 00 00 44 33 22 11  7a 00 00 00              |a...D3"..z...|

# o con xxd
xxd -g 1 struct_dump.bin
```

:::{note}
Los bytes de padding suelen ser `0x00` cuando inicializás la estructura con ceros
explícitos o con inicializadores definidos. No confíes en valores residuales.
:::

## 3.2. Uniones y type punning: `union_punning.c`

```c
/* union_punning.c
 *
 * Demostración de cómo una union comparte memoria entre sus miembros.
 *
 * Compilar:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g union_punning.c -o union_punning
 *
 * Ejecutar:
 *   ./union_punning
 */

#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t u32;
    float    f;
    char     bytes[4];
} dato_t;

/**
 * Muestra el mismo bloque de memoria interpretado de tres formas.
 */
int main(void)
{
    dato_t d = { .bytes = { 'A', 'B', 'C', 'D' } };

    printf("bytes: %c %c %c %c\\n", d.bytes[0], d.bytes[1], d.bytes[2], d.bytes[3]);
    printf("u32   : 0x%08" PRIx32 "\\n", d.u32);
    printf("float : %f  (interpretación como float, depende del patrón de bits)\\n", d.f);

    /* Ahora escribimos un entero y leemos bytes */
    d.u32 = 0x61626364u; /* ASCII 'a','b','c','d' => en little-endian será 64 63 62 61 */
    printf("\\nTras asignar u32 = 0x61626364:\\n");
    printf("bytes: %02x %02x %02x %02x\\n",
           (unsigned char)d.bytes[0], (unsigned char)d.bytes[1],
           (unsigned char)d.bytes[2], (unsigned char)d.bytes[3]);
    return 0;
}
```

### Qué aprender

- La `union` permite ver la misma memoria desde distintas interpretaciones.
- El valor impreso para `u32` y los bytes depende del **endianness**.
- El uso de `union` para type-punning es **común**, pero su comportamiento exacto
  puede ser *implementation-defined*; la alternativa totalmente portable es
  `memcpy` desde/ hacia una variable de distinto tipo.

## 3.3. Flexible array member y asignación dinámica: `fam_example.c`

```c
/* fam_example.c
 *
 * Ejemplo de Flexible Array Member (FAM) para crear buffers de tamaño variable.
 *
 * Compilar:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g fam_example.c -o fam_example
 *
 * Ejecutar:
 *   ./fam_example
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t len;
    char   data[]; /* Flexible Array Member (C99) */
} buffer_t;

/**
 * Crea un buffer con 'len' bytes y lo inicializa con un patrón.
 * @param len Cantidad de bytes a asignar.
 * @returns Puntero al buffer creado (el llamador debe liberar con free()).
 */
buffer_t *crear_buffer(size_t len)
{
    buffer_t *b = malloc(sizeof(buffer_t) + len * sizeof(char));
    if (b == NULL) {
        return NULL;
    }
    b->len = len;
    memset(b->data, 0x41, len); /* 'A' */
    return b;
}

int main(void)
{
    buffer_t *buf = crear_buffer(13);
    if (!buf) {
        perror("malloc");
        return 1;
    }
    printf("Buffer en %p, len = %zu, primeros bytes: ", (void *)buf, buf->len);
    for (size_t i = 0; i < buf->len; i++) {
        putchar(buf->data[i]);
    }
    putchar('\\n');
    free(buf);
    return 0;
}
```

### Observaciones

- El `buffer_t` se asigna en **una sola llamada** a `malloc`, por lo que los
  datos están contiguos con la cabecera.
- Evitá acceder fuera del rango `data[0]..data[len-1]`. El tamaño total
  usado en `malloc` debe ser `sizeof(buffer_t) + len * sizeof(elemento)`.

## 3.4. Bit-fields: `bitfields_portable.c`

Los bit-fields permiten empaquetar campos en menos de un entero. **Importante**:
el orden de los bits dentro de una palabra y el signo del bit-field pueden ser
*implementation-defined* (depende del compilador y la ABI). Usalos con cuidado
cuando la interoperabilidad binaria es esencial (protocolos, hardware).

```c
/* bitfields_portable.c
 *
 * Mostrar comportamiento de bit-fields. No confíes en layout para protocolos.
 *
 * Compilar:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g bitfields_portable.c -o bitfields_portable
 */

#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned int low  : 4;
    unsigned int mid  : 6;
    unsigned int high : 22;
} campos_t;

int main(void)
{
    campos_t c = { .low = 0xA, .mid = 0x2A, .high = 0x12345 };
    printf("sizeof(campos_t) = %zu\\n", sizeof(campos_t));
    printf("low  = %u\\n", c.low);
    printf("mid  = %u\\n", c.mid);
    printf("high = %u\\n", c.high);
    return 0;
}
```

:::{warning}
Si necesitás un formato binario preciso para comunicación, **no** uses
bit-fields. Implementá funciones que empaqueten bits explícitamente (más
portables y controlables). {ref}`0x0030h`.
:::

## 3.5. Type punning seguro con `memcpy`

Evitar violar la regla de aliasing estricto (strict aliasing) es buena práctica.
La forma portable de reinterpretar bytes es usar `memcpy`:

```c
/* punning_memcpy.c
 *
 * Usa memcpy para reinterpretar un float como uint32_t (portable).
 *
 * Compilar:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g punning_memcpy.c -o punning_memcpy
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    float f = 3.1415926f;
    uint32_t u = 0;
    memcpy(&u, &f, sizeof(u)); /* Portable: copia bytes */
    printf("float: %f -> bits: 0x%08x\\n", f, u);
    return 0;
}
```

---

# 4. Depuración y herramientas: comandos prácticos

A continuación se enumeran comandos que vas a usar para inspeccionar lo explicado.

## 4.1. Compilación con símbolos de depuración

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -O0 -g archivo.c -o programa
```

- `-g` agrega información de depuración para `gdb` y `pahole` (DWARF).
- `-O0` evita optimizaciones que podrían reordenar variables y complicar la
  inspección en tiempo de ejecución.

## 4.2. Ver bytes escritos en fichero

```bash
# ver bytes en hexadecimal y ASCII
hexdump -C struct_dump.bin | sed -n '1,4p'

# o con xxd
xxd struct_dump.bin | sed -n '1,4p'
```

## 4.3. Inspección con gdb

Ejemplo de sesión para `layout_inspect`:

```bash
gdb -q layout_inspect
# Dentro de gdb:
# (gdb) break main
# (gdb) run
# (gdb) p sizeof(ejemplo_padding_t)
# (gdb) p (size_t) &((ejemplo_padding_t*)0)->b     # calcula el offset de 'b'
# (gdb) x/12xb &s                                 # volcado en bytes de la estructura 's'
# (gdb) p s.a; p s.b; p s.c
# (gdb) quit
```

- `x/12xb <addr>` muestra 12 bytes a partir de `addr` en formato hexadecimal.
- `(size_t) &((tipo*)0)->miembro` es una técnica para obtener `offsetof` en gdb.

## 4.4. Visualizar "holes" con pahole (opcional)

```bash
# Generar binario con DWARF (-g)
gcc -g layout_inspect.c -o layout_inspect
pahole layout_inspect
```

`pahole` muestra dónde existen huecos de padding y su tamaño, ayudando a planear
reordenamientos de campos para reducir memoria.

## 4.5. Revisar fugas y errores de memoria con valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all ./fam_example
```

Esto detectará fugas, accesos a memoria no inicializada y otros errores comunes.

---

# 5. Patrones y recomendaciones (resumidas)

- **Ordená los miembros para reducir padding**: colocar los miembros de mayor
  alineación primero suele reducir el padding interno. Ejemplo: `double, int, char`.
- **Usá `offsetof` y `sizeof` para documentar y validar tus suposiciones.**
- **Evita type-punning por cast directo**; preferí `memcpy` o un patrón claro.
- **Para interfaces binarias (sockets, archivos)**: no dependas de `struct` tal
  cual —serializá explicitamente (endian-safe, tamaño fijo).
- **Si necesitás packing estricto**: usá `#pragma pack(push,1)` / `#pragma pack(pop)`
  o `__attribute__((packed))` —con cautela y documentá la razón.
- **Usá `pahole` para optimizar layout** cuando el tamaño de las estructuras sea
  crítico (embebidos, kernels, ALTO rendimiento).

:::{important}
Si tu código debe interoperar entre arquitecturas (endianness distinta) o con
otro lenguaje, **no** uses la disposición física de `struct` sin un protocolo de
serialización explícito. Esto evita errores sutiles y costosos.
:::

---

# 6. Ejercicios propuestos (con soluciones)

```exercise
:label: ejer-layout-1
Escribí un programa que construya una estructura con campos de distinto tamaño,
la inicialice con valores distintos, la vuelque a un fichero binario y muestre
la salida de hexdump. Identificá los bytes de padding y explicá su presencia.
```

```solution
:for: ejer-layout-1
```c
/* Solución (resumida): usar layout_inspect.c del apunte y analizar hexdump. */
```
```

```exercise
:label: ejer-fam-1
Implementá una función que cree un arreglo dinámico de `persona_t` usando
`malloc` y devuelva un puntero. La función debe recibir `n` y asignar memoria
correctamente; luego imprimí las direcciones para verificar que los elementos
están contiguos.
```

```solution
:for: ejer-fam-1
```c
/* Idea: typedef persona_t { char nombre[32]; int edad; };
 * persona_t *crear_personas(size_t n) {
 *   persona_t *p = malloc(n * sizeof(persona_t));
 *   return p; // verificar NULL
 * }
 */
```
---

# 7. Lecturas y temas avanzados (para profundizar)

- Strict aliasing: cómo las optimizaciones pueden asumir que tipos distintos no
  se solapan y qué consecuencias tiene.
- ABI y sus reglas de alineación: revisar la ABI de tu plataforma objetivo.
- Serialización portable: protocol buffers, flatbuffers, o formatos propios con
  especificación de endianness y tamaños de campo.
- Optimización de memoria en estructuras grandes: técnicas de packing y uso de
  `pahole` para análisis.

---

# 8. Conclusión

Con estos ejemplos y comandos tenés un **laboratorio reproducible** para inspeccionar
en detalle cómo C organiza tus `struct` y `union` en memoria. Ejecutá los
programas con `-g -O0` y usá `gdb` / `xxd` / `pahole` / `valgrind` para verificar
las afirmaciones teóricas y observar el comportamiento real en tu sistema.

Recordá siempre seguir las reglas de estilo y seguridad (inicializar, documentar,
liberar la memoria) cuando pases de ejemplos educativos a código productivo.
