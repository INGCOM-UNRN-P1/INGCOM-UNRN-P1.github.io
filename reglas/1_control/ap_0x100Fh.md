---
title: "Antipatrón AP-0x100Fh: Posible error off-by-one en condición de parada de bucle"
short_title: "AP-0x100Fh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Fh)=
# Antipatrón AP-0x100Fh: Posible error off-by-one en condición de parada de bucle

:::{admonition} Regla de Estilo Asociada: 0x100Fh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x100Fh: Prohibición de condiciones de parada compuestas complejas en lazos for](0x100Fh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Fh` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Un arreglo de tamaño N tiene índices válidos de 0 a N-1. Usar '<= N' intenta acceder al elemento N que cae fuera de rango.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x100Fh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Utilizá el operador estricto '< N' en la condición de terminación.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
int arr[10];
for (int i = 0; i <= 10; i++) arr[i] = 0;
```

### Código Idiomático Refactorizado (Correcto)
```c
int arr[10];
for (int i = 0; i < 10; i++) arr[i] = 0;
```
