---
title: "Antipatrón AP-0x100Fh: Posible error off-by-one en condición de parada de bucle"
short_title: "AP-0x100Fh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Fh)=
# Antipatrón AP-0x100Fh: Posible error off-by-one en condición de parada de bucle

:::{admonition} Regla de Estilo Asociada: 0x100Fh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x100Fh: Prohibición de condiciones de parada compuestas complejas en lazos for](0x100Fh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Fh` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

La condición del `for` usa `<=` sobre un arreglo, o compara contra la dimensión
en lugar de contra el último índice:

```c
int arr[10];
for (int i = 0; i <= 10; i++)
{
    arr[i] = 0;
}
```

## Diagnóstico

### Mecanismo del defecto

Un arreglo de tamaño `N` declarado `int arr[N]` tiene índices válidos de `0` a
`N - 1` (ISO/IEC 9899:2011 §6.5.2.1). La condición `i <= N` incluye `i == N`, que
es exactamente un acceso fuera del arreglo. El error clásico es confundir "la
dimensión" con "el último índice válido".

### Consecuencia observable

El programa escribe (o lee) un elemento más allá del final: corrompe la variable
contigua, falla con `SIGSEGV` o pasa desapercibido según el diseño de memoria.
En arreglos locales suele pisar otra variable; en el heap, los metadatos del
asignador. Es un comportamiento indefinido.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.5.2.1 define la indexación `E1[E2]` como `*((E1)+(E2))` y
§6.5.6 la aritmética de punteros. Acceder a `arr[N]` construye un puntero un
elemento más allá del final del objeto, lo que no está permitido. La cátedra
exige la cota estricta `i < N` y recomienda `size_t` para índices (regla
`0x3010h`).

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int arr[10];
for (int i = 0; i <= 10; i++)
{
    arr[i] = 0;
}
```

### ✅ Código refactorizado

```c
int arr[10];
for (size_t i = 0; i < 10; i++)
{
    arr[i] = 0;
}
```

La cota `i < 10` recorre exactamente los índices `0..9`. Usar `size_t` mantiene
el índice sin signo y permite compararlo contra `sizeof arr / sizeof arr[0]`.

Alternativa robusta:

```c
int arr[10];
size_t n = sizeof(arr) / sizeof(arr[0]);
for (size_t i = 0; i < n; i++)
{
    arr[i] = 0;
}
```

## Errores típicos al compilar o ejecutar

```text
En ejecución, con -fsanitize=address:
ERROR: AddressSanitizer: stack-buffer-overflow on address ... READ of size 4
    #0 in main

Sin sanitizador, el programa "funciona" pero corrompe la memoria contigua;
el fallo aparece luego, lejos de la causa.
```

## Checklist de verificación

- [ ] ¿La condición usa `<` y no `<=` sobre una dimensión?
- [ ] ¿El índice máximo alcanzable es `N - 1`?
- [ ] ¿El tipo del índice es `size_t` cuando recorre un arreglo?
- [ ] ¿Probé con un arreglo de tamaño 1 y con acceso al último elemento?

## Reglas relacionadas

* {ref}`0x100Fh` — norma este antipatrón: cota simple en el `for`.
* {ref}`0x3010h` — índices y tamaños con `size_t`.
* {ref}`0x300Ch` — verificar límites antes de acceder a un arreglo.
