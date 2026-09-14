---
title: "Antipatrón AP-0x500Bh: Redefinición de identificadores de funciones estándar de la biblioteca C"
short_title: "AP-0x500Bh"
subtitle: "Compilación, Buenas Prácticas y Seguridad (0x50XX)"
---

(ap_0x500Bh)=
# Antipatrón AP-0x500Bh: Redefinición de identificadores de funciones estándar de la biblioteca C

:::{admonition} Regla de Estilo Asociada: 0x500Bh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x500Bh: Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C](0x500Bh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x500Bh` | Categoría: Compilación, Buenas Prácticas y Seguridad (0x50XX)
:::

## Síntoma en el código del estudiante

El estudiante define funciones con el mismo nombre que otras de la
biblioteca estándar, creyendo que su versión es la única:

```c
int abs(int x) { return x < 0 ? -x : x; }
int max(int a, int b) { return a > b ? a : b; }
void *memcpy(void *d, const void *s, size_t n) { ... }
```

O usa como identificador propio un nombre reservado: `free`, `time`,
`index`, `div`, o un `#define printf`.

## Diagnóstico

### Mecanismo del defecto

El estándar reserva los identificadores con enlace externo que declaran las
cabeceras estándar para uso exclusivo de la implementación (C11 §7.1.3p1):
la libc puede reclamarlos como funciones, macros o atributos especiales.
Cuando el programa define `abs` y además incluye `<stdlib.h>`, el compilador
ve dos declaraciones incompatibles del mismo nombre externo y la unidad de
traducción no compila. Si no incluye la cabecera, la definición propia
queda con una firma que en el enlace compite contra el símbolo de la libc:
el enlazador informa "multiple definition" o, si la firma coincide, el
símbolo propio **reemplaza** al de la biblioteca de forma silenciosa y
cambia el comportamiento de todo el programa.

También están reservados, para uso futuro, los nombres que empiezan con
`str` o `mem` (C11 §7.31.13) y con `is` o `to` (C11 §7.31.2). Adoptarlos
expone a colisiones con funciones que el estándar agregue más adelante.

### Consecuencia observable

- `error: conflicting types for 'abs'` al incluir la cabecera correcta.
- `multiple definition of 'abs'` / `undefined reference` en el enlace.
- Si el compilador no reclama, el programa llama a la función equivocada:
  un `min` propio puede pisar una macro de la plataforma y devolver
  resultados inesperados sin ningún aviso.

## Fundamento en el estándar C11

La regla 0x500Bh exige incluir explícitamente la cabecera de cada función de
biblioteca. Esa inclusión es justamente la que revela la colisión: al
declarar `abs` en `<stdlib.h>` y en el fuente, el compilador detecta el
choque de firmas (C11 §6.2.7 y §6.5.2.2). La solución no es esconder la
cabecera, sino nombrar los identificadores propios con precisión, tal como
piden {ref}`0x0001h` y {ref}`0x000Eh`.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
#include <stdlib.h>

int abs(int x)
{
    return x < 0 ? -x : x;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
```

### ✅ Código refactorizado

```c
#include <stdlib.h>

static int valor_absoluto(int x)
{
    return x < 0 ? -x : x;
}

static int maximo(int a, int b)
{
    return a > b ? a : b;
}
```

Los nombres propios describen el rol y no invaden el espacio reservado. El
calificador `static` restringe además el enlace al archivo, lo que evita
colisiones y aplica el ámbito mínimo de {ref}`0x2007h`.

## Errores típicos al compilar o ejecutar

```text
aviso.c:6:5: error: conflicting types for 'abs'; have 'int(int)'
In file included from aviso.c:1:
/usr/include/stdlib.h:845:12: note: previous declaration of 'abs' with type 'int abs(int)'
```

Y en el enlace, si se evitó la cabecera:

```text
/usr/bin/ld: aviso.o: in function `abs':
aviso.c:(.text+0x0): multiple definition of `abs'; .../libc.a(abs.o): first defined here
collect2: error: ld returned 1 exit status
```

## Checklist de verificación

- [ ] ¿Algún nombre definido coincide con una función estándar (`abs`, `max`, `memcpy`, `strlen`)?
- [ ] ¿Usé identificadores propios con prefijo o nombre de dominio claro?
- [ ] ¿Toda función interna es `static`?
- [ ] ¿Incluí la cabecera estándar antes de sospechar de una colisión?
- [ ] ¿Compilé con `-Wall -Wextra` y revisé advertencias de declaración?

## Reglas relacionadas

* {ref}`0x500Bh` — inclusión explícita de la cabecera de cada función estándar.
* {ref}`0x0001h` — los identificadores deben ser descriptivos.
* {ref}`0x000Eh` — los nombres de funciones en `snake_case` propio del módulo.
