---
title: "Antipatrón AP-0x300Ah: Casteo redundante de malloc()"
short_title: "AP-0x300Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Ah)=
# Antipatrón AP-0x300Ah: Casteo redundante de malloc()

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

Toda reserva viene precedida por un molde de tipo sobre `malloc`, `calloc` o
`realloc`:

```c
int *p = (int *)malloc(sizeof(int) * 10);
nodo_t *n = (nodo_t *)malloc(sizeof(nodo_t));
```

El casteo se copia por inercia, muchas veces heredado de ejemplos de C++ o de
materiales antiguos.

## Diagnóstico

### Mecanismo del defecto

En C, `void *` se convierte **implícitamente** a cualquier puntero a objeto y
viceversa (§6.3.2.3p1). El cast no agrega ninguna conversión necesaria: repite
la que el compilador ya haría. Peor aún, si falta `#include <stdlib.h>`, C89 y
C99 asumen que `malloc` retorna `int`; el cast explícito **silencia** la
advertencia del compilador y en una arquitectura de 64 bits trunca la dirección
a 32 bits, corrompiendo el puntero.

Es decir: el cast no solo es redundante, es activamente peligroso porque tapa
el síntoma (la declaración implícita) que debería delatar un `#include`
faltante.

### Consecuencia observable

- Código ruidoso que sugiere una conversión que no existe.
- Pérdida de la advertencia `implicit declaration of function 'malloc'`.
- En sistemas de 64 bits, punteros truncados y corrupción de heap al usar el
  resultado (ver `AP-0x3028h`).

## Fundamento en el estándar C11

- C11 §6.3.2.3p1: un puntero a `void` puede convertirse a puntero a objeto y
  viceversa sin cast; el resultado compara igual al original.
- C11 §7.22.3p1: `malloc` retorna `void *`; no hay tipo concreto que castear.
- La regla 0x300Ah exige **cast explícito cuando la conversión es entre tipos de
  puntero incompatibles** (por ejemplo `char *` a `struct T *`), no cuando el
  origen ya es `void *`. La cátedra adopta `sizeof(*ptr)` como forma canónica
  (regla 0x300Bh) justamente para no repetir el tipo.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int *p = (int *)malloc(sizeof(int) * 10);
if (p == NULL) {
    return NULL;
}
```

### ✅ Código refactorizado

```c
int *p = malloc(10 * sizeof(*p));
if (p == NULL) {
    return NULL;
}
```

### ✅ Cast que sí corresponde — conversión entre tipos incompatibles

```c
void *generico = obtener_bloque();
nodo_t *n = (nodo_t *)generico;
```

Acá el cast documenta una conversión real entre tipos de objeto distintos y es
el caso que la regla 0x300Ah sí exige.

### ⚠️ Casos límite

- Compilar como C++ no es excusa: la cátedra es C11 y el cast de `malloc` en C++
  es obligatorio por otras razones; no se traslada a C.
- El cast no reemplaza la verificación de `NULL` ni el uso de `sizeof(*ptr)`.
- Castear el retorno de `realloc` tiene el riesgo adicional de perder el puntero
  original (ver `AP-0x3015h`).

## Errores típicos al compilar o ejecutar

```text
# Sin <stdlib.h> y con cast, el compilador no avisa:
$ gcc -Wall -Wextra -std=c11 programa.c
programa.c:5:14: warning: implicit declaration of function 'malloc'
 # el cast (int *) silencia el aviso en compiladores permisivos

$ ./programa
# posible truncamiento en 64 bits: puntero inválido
Segmentation fault (core dumped)
```

## Checklist de verificación

- [ ] ¿Eliminé los `(tipo *)` delante de `malloc`, `calloc` y `realloc`?
- [ ] ¿El código incluye `<stdlib.h>`?
- [ ] ¿Uso `sizeof(*ptr)` en lugar de repetir el tipo?
- [ ] ¿Reservo el cast explícito para conversiones reales entre punteros
      incompatibles?

## Reglas relacionadas

* {ref}`0x300Ah` — cast explícito solo cuando la conversión lo requiere.
* {ref}`0x300Bh` — preferir `sizeof(*ptr)` en la reserva.
* {ref}`0x500Bh` — inclusión obligatoria de cabeceras estándar.
* [AP-0x3028h: Casteo de retorno de malloc() con omisión de include stdlib.h](ap_0x3028h.md) — el caso peligroso.
* [AP-0x301Ch: Casteo redundante en invocación de free()](ap_0x301Ch.md) — mismo vicio en `free`.
