---
title: "Antipatrón AP-0x301Ah: Tamaño insuficiente en memset con sizeof(ptr)"
short_title: "AP-0x301Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Ah)=
# Antipatrón AP-0x301Ah: Tamaño insuficiente en memset con sizeof(ptr)

:::{admonition} Regla de Estilo Asociada: 0x301Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x301Ah: Validador de uso idiomático de tipos booleanos estándar](0x301Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

Después de reservar una estructura, se inicializa con `memset` pero el tamaño
sale de `sizeof` sobre el puntero:

```c
struct nodo_t *n = malloc(sizeof(*n));
memset(n, 0, sizeof(n));
```

El tercer argumento repite el error de `AP-0x300Fh`: `n` es un puntero.

## Diagnóstico

### Mecanismo del defecto

`memset(destino, valor, cantidad)` escribe exactamente `cantidad` bytes a partir
de `destino`. Si `cantidad` es `sizeof(n)` —el tamaño del puntero, 8 bytes— solo
se limpian los primeros 8 bytes del bloque, sin importar cuántos mida la
estructura. Los campos que caen más allá del byte 8 quedan con **basura**.

Ese resto sin inicializar es el peor de los casos: contiene valores residuales
del heap (direcciones viejas, contadores, longitudes). Al usarlos como índices o
punteros, el programa se comporta de manera impredecible. El error es
silencioso porque `memset` no puede saber cuánta memoria había reservada.

### Consecuencia observable

- Campos de la estructura con valores basura.
- Fallos erráticos al leer esos campos, a veces con `SIGSEGV` al usar un puntero
  residual inválido.
- Con `-fsanitize=memory` (MSan) o Valgrind se reporta el uso de memoria no
  inicializada.

## Fundamento en el estándar C11

- C11 §7.24.6.1p2: `memset` copia `n` caracteres; el resultado depende del valor
  exacto de `n`.
- C11 §6.5.3.4: `sizeof(n)` sobre un puntero da el tamaño del puntero.
- La cátedra prefiere la inicialización idiomática de agregados con `{0}` en la
  declaración (regla 0x3018h) antes que un `memset` posterior.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
struct nodo_t *n = malloc(sizeof(*n));
if (n == NULL) {
    return NULL;
}
memset(n, 0, sizeof(n));   /* limpia solo 8 bytes */
```

### ✅ Código refactorizado — `sizeof(*n)`

```c
struct nodo_t *n = malloc(sizeof(*n));
if (n == NULL) {
    return NULL;
}
memset(n, 0, sizeof(*n));
```

### ✅ Alternativa idiomática — inicialización con `{0}`

```c
struct nodo_t *n = malloc(sizeof(*n));
if (n == NULL) {
    return NULL;
}
*n = (struct nodo_t){0};
```

La regla 0x3018h prefiere `{0}` para agregados declarados; aplicada a memoria
dinámica, la asignación compuesta evita depender de un `sizeof` repetido.

### ⚠️ Casos límite

- `calloc(n, sizeof(*p))` ya entrega el bloque en cero; en ese caso el `memset`
  es redundante.
- `memset` para poner un patrón distinto de cero (por ejemplo `0xFF`) sí es
  legítimo, pero el tamaño sigue siendo `sizeof(*p)`.
- Limpiar un arreglo: `memset(v, 0, n * sizeof(*v))`, nunca `sizeof(v)`.

## Errores típicos al compilar o ejecutar

```text
# Sin sanitizadores el error es invisible:
$ ./programa
# el campo n->sig contiene basura y el recorrido cae lejos del origen
Segmentation fault (core dumped)

$ valgrind ./programa
==1234== Conditional jump or move depends on uninitialised value(s)
```

## Checklist de verificación

- [ ] ¿El tercer argumento de `memset` es `sizeof(*ptr)`, no `sizeof(ptr)`?
- [ ] ¿En arreglos usé `n * sizeof(*v)`?
- [ ] ¿Consideré `calloc` o `{0}` en lugar de `memset`?
- [ ] ¿Verifié el bloque con un sanitizador de memoria?

## Reglas relacionadas

* {ref}`0x300Bh` — `sizeof(*ptr)` en la reserva.
* {ref}`0x3013h` — `sizeof` sobre el puntero en lugar del tipo apuntado.
* {ref}`0x3018h` — inicialización idiomática con `{0}`.
* [AP-0x300Fh: Uso de sizeof(puntero) en reserva dinámica](ap_0x300Fh.md) — mismo error en `malloc`.
