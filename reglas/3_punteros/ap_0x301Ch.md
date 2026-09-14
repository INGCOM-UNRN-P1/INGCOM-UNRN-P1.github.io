---
title: "Antipatrón AP-0x301Ch: Casteo redundante en invocación de free()"
short_title: "AP-0x301Ch"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Ch)=
# Antipatrón AP-0x301Ch: Casteo redundante en invocación de free()

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Ch` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

La llamada a `free` lleva un molde a `void *`:

```c
free((void *)ptr);
```

A veces el cast se escribe a un tipo concreto (`(int *)`, `(nodo_t *)`) y otras
a `void *`. En cualquier caso, es un molde sobre un argumento que ya se
convierte solo.

## Diagnóstico

### Mecanismo del defecto

`free` recibe un `void *`. Al pasarle un puntero a cualquier tipo de objeto, el
compilador aplica la conversión implícita de §6.3.2.3p1: no hace falta cast. El
molde, entonces, no convierte nada: solo agrega ruido y sugiere una operación
que no existe.

Hay un matiz de estilo además: la regla 0x300Ah exige cast explícito para
conversiones **reales** entre tipos de puntero incompatibles. Aquí no hay tal
conversión, porque el destino es `void *`. Escribir `free((int *)ptr)` tampoco
aporta: `free` vuelve a convertir a `void *` inmediatamente.

### Consecuencia observable

- Código más verboso sin ganancia semántica.
- Falsa sensación de que el cast "arregla" algo (por ejemplo, un tipo mal
  declarado), cuando solo lo disimula.
- Inconsistencia con el resto del código, que libera sin cast.

## Fundamento en el estándar C11

- C11 §6.3.2.3p1: conversión implícita entre `void *` y punteros a objeto.
- C11 §7.22.3.3p1: `free` declara su único parámetro como `void *`.
- C11 §6.5.2.2: las restricciones de la llamada permiten el paso sin cast, ya
  que la conversión es válida.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
free((void *)ptr);
free((nodo_t *)nodo);
```

### ✅ Código refactorizado

```c
free(ptr);
ptr = NULL;

free(nodo);
nodo = NULL;
```

Sin cast y con anulación posterior del puntero, según la regla 0x3002h.

### ✅ Cast legítimo de otra operación

```c
void *bloque = malloc(sizeof(nodo_t));
nodo_t *n = (nodo_t *)bloque;   /* conversión real de void* a tipo concreto */
```

Nótese la diferencia: acá el cast documenta el tipo con el que se va a usar el
bloque, no un adorno alrededor de `free`.

### ⚠️ Casos límite

- Castear a `void *` un puntero a función es incorrecto: la conversión entre
  punteros a objeto y punteros a función no está garantizada por el estándar,
  con o sin cast.
- `free` sobre un `const char *` requiere descartar `const`; la cátedra prefiere
  no liberar a través de punteros `const` y mantener la propiedad en el tipo
  original.
- El cast no reemplaza la verificación de que el bloque provenga del heap.

## Errores típicos al compilar o ejecutar

```text
# El cast a void* no genera ninguna advertencia ni error;
# el problema es de estilo:
$ gcc -Wall -Wextra -std=c11 programa.c
# sin diagnóstico por el cast innecesario
```

## Checklist de verificación

- [ ] ¿Eliminé el `(void *)` (y cualquier otro molde) delante de `free`?
- [ ] ¿Anulé el puntero después de liberarlo (regla 0x3002h)?
- [ ] ¿Reservo los casts para conversiones reales entre tipos de objeto?
- [ ] ¿Evité usar `free` sobre punteros a función o con `const`?

## Reglas relacionadas

* {ref}`0x300Ah` — cast explícito solo para conversiones necesarias.
* {ref}`0x3002h` — liberar y anular el puntero.
* [AP-0x300Ah: Casteo redundante de malloc()](ap_0x300Ah.md) — mismo vicio en la reserva.
* [AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros](ap_0x302Ah.md) — el cast peligroso.
