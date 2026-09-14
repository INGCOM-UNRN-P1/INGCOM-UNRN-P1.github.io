---
title: "Antipatrón AP-0x200Bh: Función con excesiva cantidad de parámetros (> 5)"
short_title: "AP-0x200Bh"
subtitle: "Funciones y Modularización (0x20XX)"
---

(ap_0x200Bh)=
# Antipatrón AP-0x200Bh: Función con excesiva cantidad de parámetros (> 5)

:::{admonition} Regla de Estilo Asociada: 0x200Bh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x200Bh: Modularización: una función no debe exceder 4 parámetros de entrada](0x200Bh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x200Bh` | Categoría: Funciones y Modularización (0x20XX)
```


## Diagnóstico
Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x200Bh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Agrupá los parámetros relacionados en una estructura 'struct params_t'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
void config(int a, int b, int c, int d, int e, int f);
```

### Código Idiomático Refactorizado (Correcto)
```c
void config(const struct config_t *cfg);
```
