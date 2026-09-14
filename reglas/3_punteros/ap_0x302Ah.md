---
title: "Antipatrón AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros"
short_title: "AP-0x302Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x302Ah)=
# Antipatrón AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x302Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

Se fabrica un puntero a partir de un entero literal:

```c
int *p = (int *)0x1000;
*p = 42;
```

El número pretende ser una dirección de memoria "conocida", tomada de un
ejemplo, de una dirección de hardware o de la imaginación.

## Diagnóstico

### Mecanismo del defecto

Un entero y un puntero pertenecen a dominios distintos. Convertir un entero a
puntero es posible con cast, pero el estándar lo declara
*implementation-defined*: cada plataforma decide qué significa, y el resultado
puede no ser una dirección válida ni conservar el valor numérico.

El problema se materializa al desreferenciar. En un sistema con memoria virtual,
la dirección `0x1000` (4096) rara vez está mapeada para el proceso. El acceso
genera una falla de página y `SIGSEGV`. Elegir "de memoria" 0x1000 es
especialmente desafortunado: cae en la primera página, deliberadamente no
mapeada para detectar desreferencias nulas.

Escribir en una dirección fija solo tiene sentido en código de muy bajo nivel
—un arranque de kernel, un registro mapeado en memoria— con documentación y
mapeo explícito. Fuera de ese contexto es un error de portabilidad y una caída
segura.

### Consecuencia observable

- `SIGSEGV` al desreferenciar la dirección inventada.
- El código deja de compilar o cambia de significado en otra plataforma.
- Si la dirección coincide con memoria válida por casualidad, corrompe datos
  ajenos.
- El compilador puede advertir con `-Wint-to-pointer-cast` según la constancia.

## Fundamento en el estándar C11

- C11 §6.3.2.3p5: la conversión de entero a puntero es *implementation-defined*;
  el resultado puede no estar alineado ni ser utilizable.
- C11 §6.5.3.2p4: desreferenciar un puntero que no apunta a un objeto es
  comportamiento indefinido.
- C11 §6.3.2.3p3: la única constante entera que se convierte en puntero nulo es
  `0`; `NULL` es la forma canónica y `0x1000` no es un puntero nulo.
- La regla 0x300Ah regula las conversiones entre punteros, no habilita inventar
  direcciones.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int *p = (int *)0x1000;
*p = 42;
```

### ✅ Código refactorizado — obtener la dirección de un objeto real

```c
int valor = 0;
int *p = &valor;
*p = 42;
```

### ✅ Memoria dinámica

```c
int *p = malloc(sizeof(*p));
if (p == NULL) {
    return NULL;
}
*p = 42;
free(p);
p = NULL;
```

### ✅ Puntero nulo cuando corresponde

```c
int *p = NULL;   /* no (int *)0 */
```

`NULL` expresa "sin objeto"; un literal como `0x1000` expresa una dirección
concreta que probablemente no exista.

### ⚠️ Casos límite

- `(void *)0` es una constante de puntero nulo válida, pero en C la cátedra
  prefiere `NULL` (regla 0x3008h).
- En entornos embebidos con registros mapeados, `volatile` y una dirección fija
  pueden ser legítimos; requieren justificación y quedan fuera del alcance de la
  materia.
- Si de verdad se necesita una dirección en un entero, el tipo correcto es
  `uintptr_t` (`<stdint.h>`), no un `int`.

## Errores típicos al compilar o ejecutar

```text
$ gcc -Wall -Wextra -std=c11 programa.c
programa.c:1:9: warning: cast to pointer from integer of different size
 [-Wint-to-pointer-cast]
    1 | int *p = (int *)0x1000;

$ ./programa
Segmentation fault (core dumped)
```

## Checklist de verificación

- [ ] ¿Todo puntero proviene de `malloc`/`calloc`/`realloc` o de `&objeto`?
- [ ] ¿Eliminé los literales enteros casteados a puntero?
- [ ] ¿Uso `NULL` y no `(tipo *)0` para indicar ausencia de objeto?
- [ ] ¿Si necesito una dirección en un entero uso `uintptr_t`?

## Reglas relacionadas

* {ref}`0x300Ah` — conversiones de punteros explícitas y legítimas.
* {ref}`0x3008h` — `NULL` para punteros, no literales.
* {ref}`0x3001h` — verificar el retorno de la reserva.
* [AP-0x301Fh: Asignación de retorno de malloc() a variable no puntero](ap_0x301Fh.md) — la conversión inversa, igualmente peligrosa.
