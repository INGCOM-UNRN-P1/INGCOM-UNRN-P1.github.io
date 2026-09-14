---
title: "Antipatrón AP-0x101Bh: Comparación entre tipos enteros con y sin signo en condición"
short_title: "AP-0x101Bh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x101Bh)=
# Antipatrón AP-0x101Bh: Comparación entre tipos enteros con y sin signo en condición

:::{admonition} Regla de Estilo Asociada: 0x1005h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x1005h: Reemplazá las condiciones ambiguas basadas en la "veracidad" del tipo de dato](0x1005h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x101Bh` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

Se compara un entero con signo contra uno sin signo (por ejemplo `int` contra
`size_t`) sin controlar la conversión:

```c
int i = -1;
size_t n = 10;
if (i < n)
{
    procesar(i);
}
```

## Diagnóstico

### Mecanismo del defecto

Cuando un operando con signo se compara contra uno sin signo de rango igual o
mayor, el valor con signo se convierte implícitamente a sin signo
(ISO/IEC 9899:2011 §6.3.1.8). `-1` se convierte en el mayor valor del tipo
`size_t` (`SIZE_MAX`), que es enorme. La comparación `i < n` resulta entonces
falsa, al revés de lo esperado.

### Consecuencia observable

El `if` no entra aunque `i` sea negativo y menor que `n`; o bien un lazo que
recorre hacia atrás se desborda. También aparece al recorrer un arreglo con un
índice `int` que se vuelve negativo: se convierte a un índice gigantesco y
provoca un acceso fuera de rango.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.3.1.8 define las conversiones aritméticas usuales: si el
tipo sin signo tiene rango mayor o igual, el operando con signo se convierte a
sin signo. La cátedra exige tipos consistentes y `size_t` para índices
(regla `0x3010h`), evitando la conversión accidental (regla `0x1005h`).

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int i = -1;
size_t n = 10;
if (i < n)
{
    procesar(i);
}
```

### ✅ Código refactorizado

```c
size_t i = 0;
size_t n = 10;
if (i < n)
{
    procesar(i);
}
```

Ambos operandos son del mismo tipo sin signo y la comparación es segura. Si el
valor con signo debe conservarse, se valida primero: `if (i >= 0 && (size_t)i < n)`.

## Errores típicos al compilar o ejecutar

```text
Con -Wsign-compare (incluida en -Wextra):
warning: comparison of integer expressions of different signedness:
'int' and 'size_t' {aka 'long unsigned int'} [-Wsign-compare]

En ejecución, i = -1 se convierte a 18446744073709551615 y la condición
es falsa. Con un índice negativo, el acceso desborda el arreglo.
```

## Checklist de verificación

- [ ] ¿Comparo tipos con signo y sin signo?
- [ ] ¿El operando con signo puede ser negativo?
- [ ] ¿Unifiqué los tipos o convertí de forma controlada?
- [ ] ¿Usé `size_t` para índices y tamaños?

## Reglas relacionadas

* {ref}`0x1005h` — norma este antipatrón: comparaciones explícitas y coherentes.
* {ref}`0x3010h` — índices y tamaños de arreglos con `size_t`.
* {ref}`0x300Ch` — verificar límites antes de acceder a un arreglo.
