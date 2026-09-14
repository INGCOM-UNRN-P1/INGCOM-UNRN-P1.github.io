---
title: "Antipatrón AP-0x300Ah: Casteo redundante de malloc()"
short_title: "AP-0x300Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Ah)=
# Antipatrón AP-0x300Ah: Casteo redundante de malloc()

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x300Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```

### Código Idiomático Refactorizado (Correcto)
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```
