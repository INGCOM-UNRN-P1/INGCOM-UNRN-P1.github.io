---
title: "Antipatrón AP-0x301Bh: Desreferencia inmediata tras realloc"
short_title: "AP-0x301Bh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Bh)=
# Antipatrón AP-0x301Bh: Desreferencia inmediata tras realloc

:::{admonition} Regla de Estilo Asociada: 0x3001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x3001h: Siempre verificá la asignación exitosa de memoria dinámica](0x3001h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Bh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

El resultado de `realloc` se usa enseguida, sin preguntar si la reasignación
tuvo éxito:

```c
ptr = realloc(ptr, nuevo_tam);
ptr[0] = 42;
```

El acceso sigue en la línea inmediatamente posterior, sin ningún `if`.

## Diagnóstico

### Mecanismo del defecto

`realloc` comparte con `malloc` el contrato de retorno: devuelve `NULL` cuando
no puede satisfacer el nuevo tamaño. En esa línea, `ptr` recibe el puntero nulo
y la desreferencia siguiente (`ptr[0] = 42`) actúa sobre `NULL`: comportamiento
indefinido y, en la práctica, caída por `SIGSEGV`.

El defecto se agrava porque combina dos problemas: además de desreferenciar el
nulo, se perdió la referencia al bloque original (el `realloc` devolvió `NULL` y
el bloque viejo sigue vivo pero inaccesible), es decir, una fuga. Ese aspecto de
propiedad lo cubre `AP-0x3015h`.

### Consecuencia observable

- Caída con `Segmentation fault` en la línea siguiente al `realloc`.
- Fuga del bloque original si la reasignación falló.
- Ninguna posibilidad de recuperarse: el error se materializa en el acto.

## Fundamento en el estándar C11

- C11 §7.22.3.5p3: `realloc` devuelve un puntero nulo si la asignación falla;
  el bloque previo no se libera.
- C11 §6.5.3.2p4: desreferenciar un puntero nulo es comportamiento indefinido.
- La regla 0x3001h exige comprobar el retorno de toda asignación dinámica,
  incluida `realloc`, antes de usarla.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int *agregar(int *ptr, size_t n)
{
    ptr = realloc(ptr, n * sizeof(*ptr));
    ptr[0] = 42;
    return ptr;
}
```

### ✅ Código refactorizado

```c
int *agregar(int *ptr, size_t n)
{
    int *tmp = realloc(ptr, n * sizeof(*tmp));
    if (tmp == NULL) {
        return ptr;   /* conserva el bloque original */
    }
    ptr = tmp;
    ptr[0] = 42;
    return ptr;
}
```

### ✅ Guarda explícita del caso nulo

```c
int *tmp = realloc(ptr, n * sizeof(*tmp));
if (!tmp) {
    return NULL;
}
ptr = tmp;
ptr[0] = 42;
```

### ⚠️ Casos límite

- No confundir `realloc(ptr, 0)` con un fallo: puede devolver `NULL` porque el
  bloque se liberó, no porque no hubiera memoria.
- Si se decide abortar ante el fallo, hay que liberar `ptr` explícitamente (o
  devolverlo) para no filtrarlo.
- La verificación de `NULL` debe ir **antes** del primer uso; después ya no
  sirve (ver `AP-0x3023h`).

## Errores típicos al compilar o ejecutar

```text
$ ./programa
Segmentation fault (core dumped)

# Con AddressSanitizer:
ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000
#0 0x... in agregar programa.c:3
```

## Checklist de verificación

- [ ] ¿Cada `realloc` tiene una comprobación de `NULL` antes del primer uso?
- [ ] ¿Usé una variable temporal para no perder el bloque original?
- [ ] ¿Si falla, libero o devuelvo el bloque previo?
- [ ] ¿El primer acceso al puntero viene después de la guarda?

## Reglas relacionadas

* {ref}`0x3001h` — verificar el retorno de la asignación dinámica.
* {ref}`0x3015h` — no sobreescribir el puntero original en `realloc`.
* {ref}`0x3009h` — documentar el retorno `NULL`.
* [AP-0x3015h: Sobreescritura directa de puntero en realloc](ap_0x3015h.md) — la fuga asociada.
* [AP-0x3029h: Desreferencia directa tras retorno de realloc sin asignación temporal](ap_0x3029h.md) — variante en una sola expresión.
