---
title: "Antipatrón AP-0x100Ah: Asignación accidental en condición lógica (if (x = 5))"
short_title: "AP-0x100Ah"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Ah)=
# Antipatrón AP-0x100Ah: Asignación accidental en condición lógica (if (x = 5))

:::{admonition} Regla de Estilo Asociada: 0x100Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x100Ah: Prohibición de asignaciones simples dentro de condiciones lógicas](0x100Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Ah` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Casi con certeza se intentó escribir una comparación '==' en lugar de una asignación que altera la variable.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x100Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Utilizá '==' para comparar o extraé la asignación antes del condicional.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
if (x = 5) { ... }
```

### Código Idiomático Refactorizado (Correcto)
```c
if (x == 5) { ... }
```
