---
title: "Antipatrón AP-0x301Fh: Asignación de retorno de malloc() a variable no puntero"
short_title: "AP-0x301Fh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Fh)=
# Antipatrón AP-0x301Fh: Asignación de retorno de malloc() a variable no puntero

:::{admonition} Regla de Estilo Asociada: 0x3001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x3001h: Siempre verificá la asignación exitosa de memoria dinámica](0x3001h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Fh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

El resultado de `malloc` se guarda en una variable entera:

```c
int addr = malloc(sizeof(int));
```

El identificador no lleva asterisco y su tipo es `int`, mientras que `malloc`
retorna una dirección.

## Diagnóstico

### Mecanismo del defecto

`malloc` devuelve `void *`. Asignarlo a un `int` sin cast viola las
restricciones de la asignación (§6.5.16.1): un puntero no es una expresión
aritmética. El compilador está obligado a emitir un diagnóstico; GCC y Clang lo
hacen con `-Wint-conversion`, que suele venir activado por `-Wall`.

Cuando el estudiante "arregla" el diagnóstico agregando un cast
(`int addr = (int)malloc(...)`), el problema se vuelve peor pero silencioso: en
una arquitectura de 64 bits la dirección tiene 64 bits y el `int`, 32. La
conversión **trunca** los 32 bits altos. `addr` guarda una dirección corrupta
que, al volver a convertirse en puntero, apunta a cualquier lado.

### Consecuencia observable

- Advertencia del compilador (ignorada con frecuencia).
- Dirección truncada en 64 bits: el puntero reconstruido es inválido.
- `SIGSEGV` al desreferenciar, lejos del origen del error.
- Si `int` resulta del mismo ancho que el puntero en una plataforma, "funciona"
  y oculta el defecto, que reaparece al portar el código.

## Fundamento en el estándar C11

- C11 §6.5.16.1: solo se pueden asignar punteros a punteros compatibles o a
  `void *`; asignar a un entero requiere cast explícito.
- C11 §6.3.2.3p5: la conversión entre puntero e entero es
  *implementation-defined*; el estándar no promete que preserve la dirección si
  el entero es más chico.
- C11 §7.22.3p1: `malloc` retorna `void *`, nunca un entero.
- La regla 0x3001h refuerza que el valor de retorno debe guardarse como puntero
  y verificarse.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int addr = malloc(sizeof(int));
*(int *)addr = 42;   /* dirección truncada y cast forzado */
```

### ✅ Código refactorizado

```c
int *ptr = malloc(sizeof(*ptr));
if (ptr == NULL) {
    return NULL;
}
*ptr = 42;
```

### ✅ Si de verdad se necesita una dirección numérica

```c
#include <stdint.h>

int *ptr = malloc(sizeof(*ptr));
if (ptr == NULL) {
    return NULL;
}
uintptr_t direccion = (uintptr_t)ptr;   /* tipo capaz de contener un puntero */
```

`uintptr_t` es el único entero garantizado para almacenar una dirección; aun
así, en la cátedra solo se admite con una justificación explícita.

### ⚠️ Casos límite

- `sizeof(int)` puede coincidir con `sizeof(void *)` en sistemas de 32 bits;
  eso no hace válida la conversión, solo la disimula.
- Guardar el retorno en `long` tampoco es portable: en Windows 64 bits `long`
  sigue siendo de 32 bits; `intptr_t`/`uintptr_t` sí.
- El cast a `int` no elimina la advertencia en todos los compiladores; en Clang
  moderno el aviso por truncamiento se mantiene.

## Errores típicos al compilar o ejecutar

```text
$ gcc -Wall -Wextra -std=c11 programa.c
programa.c:3:15: warning: initialization of 'int' from 'void *' makes integer
 from pointer without a cast [-Wint-conversion]
    3 |     int addr = malloc(sizeof(int));

$ ./programa
Segmentation fault (core dumped)
```

## Checklist de verificación

- [ ] ¿Toda variable que recibe el retorno de `malloc` es un puntero?
- [ ] ¿El compilador no emite `-Wint-conversion`?
- [ ] ¿Nunca descarté una dirección con un cast a `int`?
- [ ] ¿Si necesito un entero para una dirección usé `uintptr_t`?

## Reglas relacionadas

* {ref}`0x3001h` — guardar y verificar el retorno como puntero.
* {ref}`0x300Ah` — conversiones de punteros explícitas.
* {ref}`0x300Bh` — `sizeof(*ptr)` en la reserva.
* [AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros](ap_0x302Ah.md) — el camino inverso y simétrico.
