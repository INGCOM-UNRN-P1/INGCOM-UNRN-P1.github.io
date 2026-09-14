---
title: "Antipatrón AP-0x300Fh: Uso de sizeof(puntero) en reserva dinámica"
short_title: "AP-0x300Fh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Fh)=
# Antipatrón AP-0x300Fh: Uso de sizeof(puntero) en reserva dinámica

:::{admonition} Regla de Estilo Asociada: 0x300Fh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Fh: Liberá la memoria en el orden inverso a su asignación](0x300Fh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Fh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

La reserva usa `sizeof` sobre la **variable puntero** en lugar del tipo
apuntado:

```c
nodo_t *n = malloc(sizeof(n));
int *v = malloc(10 * sizeof(v));
```

El error se ve a simple vista porque el argumento de `sizeof` es el mismo
identificador que está a la izquierda del `=`.

## Diagnóstico

### Mecanismo del defecto

`sizeof(ptr)` mide el tamaño del **puntero**, no el del objeto apuntado. En una
arquitectura de 64 bits eso son 8 bytes, cualquiera sea el tipo apuntado. Si la
estructura `nodo_t` ocupa 32 bytes, `malloc(sizeof(n))` reserva solo 8: el
bloque es demasiado pequeño.

Escribir `n->dato = x` o `v[i] = x` escribe fuera de los límites del bloque
reservado. Eso es un **desbordamiento de heap** (*heap buffer overflow*): se
pisan los metadatos del asignador o datos de otro bloque. En C no hay
verificación de límites, por lo que el error es silencioso hasta que corrompe lo
suficiente como para caer.

### Consecuencia observable

- Escrituras fuera de rango que corrompen el heap.
- `malloc(): corrupted top size` o `free(): invalid next size (fast)` en `glibc`.
- Caídas erráticas lejos del punto que originó el daño, lo que lo vuelve muy
  difícil de localizar sin un detector.

## Fundamento en el estándar C11

- C11 §6.5.3.4: `sizeof` aplicado a una expresión da el tamaño de **su tipo**;
  `n` tiene tipo `nodo_t *`, así que devuelve el tamaño del puntero.
- C11 §7.22.3p1: `malloc` reserva exactamente la cantidad de bytes pedida; no
  redondea al tamaño del objeto que el programador tenía en mente.
- La forma correcta según la regla 0x300Bh es `sizeof(*ptr)`, que mide el tipo
  apuntado y se adapta a refactorizaciones. Este defecto se solapa con la regla
  0x3013h.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
nodo_t *n = malloc(sizeof(n));
if (n == NULL) {
    return NULL;
}
n->dato = 42;   /* escribe fuera de los 8 bytes reservados */
```

### ✅ Código refactorizado

```c
nodo_t *n = malloc(sizeof(*n));
if (n == NULL) {
    return NULL;
}
n->dato = 42;
```

### ✅ Arreglo con `sizeof(*v)`

```c
int *v = malloc(10 * sizeof(*v));
if (v == NULL) {
    return NULL;
}
for (size_t i = 0; i < 10; i++) {
    v[i] = (int)i;
}
```

### ⚠️ Casos límite

- `char *s = malloc(sizeof(char) * (n + 1))` es válido porque el cast no está
  y el tamaño es explícito; el problema es `sizeof(puntero)`, no `sizeof(tipo)`.
- `malloc(sizeof(n))` donde `n` es un **arreglo** (no un puntero) sí da el
  tamaño total; confundir ambos casos es frecuente al refactorizar parámetros
  (ver `AP-0x3019h`).
- En `calloc(n, sizeof(*p))` el error simétrico es `sizeof(p)`.

## Errores típicos al compilar o ejecutar

```text
$ ./programa
malloc(): corrupted top size
Aborted (core dumped)

# Con AddressSanitizer:
ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...
WRITE of size 8 at 0x... thread T0
```

## Checklist de verificación

- [ ] ¿Toda reserva usa `sizeof(*ptr)` o `sizeof(tipo)`?
- [ ] ¿Ningún `malloc`/`calloc` pasa `sizeof` de la variable puntero?
- [ ] ¿La cantidad de elementos multiplica al tamaño de un elemento?
- [ ] ¿Corrí el programa con AddressSanitizer para descartar desbordes?

## Reglas relacionadas

* {ref}`0x300Bh` — usar `sizeof(*ptr)` en la reserva.
* {ref}`0x3013h` — reserva con `sizeof` sobre el puntero en lugar del tipo.
* {ref}`0x300Fh` — liberar en orden inverso (norma asociada).
* [AP-0x301Ah: Tamaño insuficiente en memset con sizeof(ptr)](ap_0x301Ah.md) — mismo error en `memset`.
