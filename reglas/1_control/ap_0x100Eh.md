---
title: "Antipatrón AP-0x100Eh: Expresión booleana tautológica o contradictoria"
short_title: "AP-0x100Eh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Eh)=
# Antipatrón AP-0x100Eh: Expresión booleana tautológica o contradictoria

:::{admonition} Regla de Estilo Asociada: 0x100Eh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x100Eh: Espaciado obligatorio alrededor de operadores ternarios ('? :')](0x100Eh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Eh` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

La condición combina una variable consigo misma de forma que el resultado es
siempre verdadero o siempre falso:

```c
if (x && !x)
{
    marcar_error();
}

if (activo || !activo)
{
    registrar();
}
```

## Diagnóstico

### Mecanismo del defecto

Por álgebra booleana, `x && !x` es siempre falso y `x || !x` es siempre
verdadero, para cualquier valor de `x`. El compilador puede doblar la rama
muerta, pero la intención del autor queda sepultada. Estos patrones suelen
aparecer cuando se agregan términos sin revisar la condición completa.

### Consecuencia observable

La rama inalcanzable (`x && !x`) nunca se ejecuta y el autor cree que sí; la
rama tautológica (`x || !x`) se ejecuta siempre. En cualquiera de los dos casos
el programa "hace algo" y no hay error, lo que convierte al defecto en un bug
silencioso de lógica.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.8.4.1 define la evaluación de condiciones y §6.5.13–6.5.14
la semántica de `&&` y `||`. El estándar no considera estas expresiones
inválidas; son lógicamente degeneradas. La cátedra las trata como señal de
error de razonamiento y pide simplificarlas o eliminarlas.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
if (x && !x)
{
    marcar_error();
}

if (activo || !activo)
{
    registrar();
}
```

### ✅ Código refactorizado

```c
/* la primera rama es inalcanzable: se elimina */

if (activo)
{
    registrar();
}
```

Si la intención era detectar algo imposible, la condición debe reescribirse.
Si era una tautología, sobra la condición y queda la sentencia directa.

## Errores típicos al compilar o ejecutar

```text
Con -Wall y optimización:
warning: logical 'and' of mutually exclusive expressions is always false
warning: logical 'or' of collectively exhaustive expressions is always true

La rama marcar_error() nunca se ejecuta; la rama registrar() se ejecuta
siempre, con independencia de activo.
```

## Checklist de verificación

- [ ] ¿Alguna condición usa la misma variable dos veces con signos opuestos?
- [ ] ¿El resultado de la expresión depende realmente de algún dato?
- [ ] ¿La rama que escribí es alcanzable?
- [ ] ¿Simplifiqué la expresión o la dejé con un comentario?

## Reglas relacionadas

* {ref}`0x1004h` — simplificar condiciones complejas con variables auxiliares.
* {ref}`0x1016h` — paréntesis al mezclar `&&` y `||`.
* {ref}`0x100Eh` — regla asociada a este antipatrón.
