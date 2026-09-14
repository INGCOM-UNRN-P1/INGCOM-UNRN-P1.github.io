---
title: "Antipatrón AP-0x100Eh: Expresión booleana tautológica o contradictoria"
short_title: "AP-0x100Eh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Eh)=
# Antipatrón AP-0x100Eh: Expresión booleana tautológica o contradictoria

:::{admonition} Regla de Estilo Asociada: 0x100Eh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x100Eh: Espaciado obligatorio alrededor de operadores ternarios ('? :')](0x100Eh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Eh` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Las expresiones tautológicas representan lógica redundante o errores graves de razonamiento en la condición.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x100Eh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Simplificá la expresión lógica removiendo términos redundantes o contradictorios.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
if (x && !x) { ... }
```

### Código Idiomático Refactorizado (Correcto)
```c
if (x) { ... }
```
