---
title: "Antipatrón AP-0x100Ah: Asignación accidental en condición lógica (if (x = 5))"
short_title: "AP-0x100Ah"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Ah)=
# Antipatrón AP-0x100Ah: Asignación accidental en condición lógica (if (x = 5))

:::{admonition} Regla de Estilo Asociada: 0x100Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x100Ah: Prohibición de asignaciones simples dentro de condiciones lógicas](0x100Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Ah` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

La condición de un `if` o `while` usa `=` en lugar de `==`, y la variable
aparenta compararse pero en realidad se sobrescribe:

```c
if (x = 5)
{
    procesar();
}
```

## Diagnóstico

### Mecanismo del defecto

En C la asignación es una expresión que devuelve el valor asignado
(ISO/IEC 9899:2011 §6.5.16). El `if` evalúa ese valor: `x = 5` asigna 5 y la
condición resulta verdadera. La variable queda modificada de forma lateral, sin
que ninguna línea lo anuncie.

### Consecuencia observable

El `if` siempre entra (si el valor asignado no es cero) y `x` cambia de valor.
En un `while`, el lazo puede no terminar nunca o terminar antes de tiempo. El
compilador no distingue la intención: compila sin error y, a lo sumo, avisa de
la asignación usada como valor de verdad si se activa `-Wparentheses`.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.5.16 define la asignación como expresión con valor, y
§6.8.4.1 permite cualquier expresión escalar como condición. El estándar no
prohíbe el patrón; la cátedra sí, porque su historial como causa de bugs es
extenso. La prohibición es de la regla `0x100Ah`.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
if (x = 5)
{
    procesar();
}

while (valor = siguiente())
{
    acumular(valor);
}
```

### ✅ Código refactorizado

```c
if (x == 5)
{
    procesar();
}

valor = siguiente();
while (valor != 0)
{
    acumular(valor);
    valor = siguiente();
}
```

La comparación usa `==` y la asignación se separa de la condición. El `while`
expone su corte comparando contra `0` y el avance es explícito.

## Errores típicos al compilar o ejecutar

```text
Con -Wparentheses (incluida en -Wall):
warning: suggest parentheses around assignment used as truth value
[-Wparentheses]

Sin advertencias: el programa compila y entra siempre a la rama,
o el while nunca termina si el valor asignado nunca llega a cero.
```

## Checklist de verificación

- [ ] ¿Cada comparación usa `==` o `!=` en lugar de `=`?
- [ ] ¿Hay asignaciones dentro de `if` o `while`?
- [ ] ¿Separé la lectura o el cómputo de la comparación?
- [ ] ¿Compilé con `-Wparentheses` y revisé los avisos?

## Reglas relacionadas

* {ref}`0x100Ah` — norma este antipatrón.
* {ref}`0x1014h` — prohíbe también la asignación comparada embebida.
* {ref}`0x3003h` — no mezclar asignación y comparación en una línea.
