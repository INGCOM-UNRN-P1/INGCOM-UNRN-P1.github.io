---
title: "Antipatrón AP-0x300Dh: Número mágico literal en condición lógica"
short_title: "AP-0x300Dh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Dh)=
# Antipatrón AP-0x300Dh: Número mágico literal en condición lógica

:::{admonition} Regla de Estilo Asociada: 0x300Dh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Dh: Utilizá enum en lugar de "números mágicos" para conjuntos de estados y valores constantes](0x300Dh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Dh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
Los números mágicos oscurecen el significado del algoritmo e impiden la mantenibilidad del código.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x300Dh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Declarale un nombre significativo mediante una constante '#define' o 'enum'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
if (estado == 404) { ... }
```

### Código Idiomático Refactorizado (Correcto)
```c
#define ESTADO_NOT_FOUND 404
if (estado == ESTADO_NOT_FOUND) { ... }
```
