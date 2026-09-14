---
title: "Antipatrón AP-0x100Ch: Caso de switch sin break (Fallthrough no intencional)"
short_title: "AP-0x100Ch"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Ch)=
# Antipatrón AP-0x100Ch: Caso de switch sin break (Fallthrough no intencional)

:::{admonition} Regla de Estilo Asociada: 0x100Ch
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x100Ch: No utilices comparaciones en estilo Yoda ('CONST == variable')](0x100Ch.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Ch` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

Un `case` termina sin `break` y la ejecución "cae" al `case` siguiente,
acumulando el trabajo de ambos:

```c
switch (op)
{
    case 1:
        hacer_1();
    case 2:
        hacer_2();
        break;
}
```

`hacer_1()` se ejecuta y luego, sin pausa, `hacer_2()`.

## Diagnóstico

### Mecanismo del defecto

El `switch` en C salta a la etiqueta `case` elegida y **continúa ejecutando**
hasta encontrar un `break` o el final del bloque (ISO/IEC 9899:2011 §6.8.4.2).
El `break` es la única interrupción; sin él, el flujo atraviesa las etiquetas
siguientes.

### Consecuencia observable

La rama `case 1` hace también el trabajo de `case 2`. El error no se ve en el
encabezado y suele descubrirse tarde como "efectos duplicados" o "acciones de
más". Si se reordenan los `case`, el resultado cambia sin tocar el cuerpo.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.8.4.2 describe el `switch` como un salto a la etiqueta y
la ejecución secuencial posterior. El fallthrough es legal; la cátedra exige
que, cuando sea deliberado, se documente con un comentario `// fallthrough`
(regla `0x1008h`). El antipatrón es el fallthrough **no intencional**.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
switch (op)
{
    case 1:
        hacer_1();
    case 2:
        hacer_2();
        break;
}
```

### ✅ Código refactorizado

```c
switch (op)
{
    case 1:
        hacer_1();
        break;
    case 2:
        hacer_2();
        break;
    default:
        reportar_opcion(op);
        break;
}
```

Cada `case` cierra con `break` y el `default` cubre los valores no listados. Si
el fallthrough fuera intencional, se escribiría `// fallthrough` en lugar de
`break`.

## Errores típicos al compilar o ejecutar

```text
Con -Wimplicit-fallthrough (Clang / GCC 7+):
warning: unannotated fall-through between switch labels [-Wimplicit-fallthrough]

En ejecución, con op == 1 el programa llama a hacer_1() y a hacer_2();
el resultado parece un error de lógica sin causa visible.
```

## Checklist de verificación

- [ ] ¿Cada `case` termina en `break`, `return` o comentario `// fallthrough`?
- [ ] ¿El `switch` incluye un `default`?
- [ ] ¿Reordenar los `case` cambiaría el comportamiento? Debería no hacerlo.
- [ ] ¿Compilé con `-Wimplicit-fallthrough`?

## Reglas relacionadas

* {ref}`0x1008h` — todo `switch` debe tener `default` y documentar el fallthrough.
* {ref}`0x1002h` — el `break` de cierre de cada `case` es obligatorio.
* {ref}`0x100Ch` — regla asociada a este antipatrón.
