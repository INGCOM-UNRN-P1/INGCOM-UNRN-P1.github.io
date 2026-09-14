---
title: "Antipatrón AP-0x301Dh: Comparación sintáctica errónea de puntero con carácter nulo '\0'"
short_title: "AP-0x301Dh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Dh)=
(0x301Dh_ap)=
# Antipatrón AP-0x301Dh: Comparación sintáctica errónea de puntero con carácter nulo '\0'

:::{admonition} Regla de Estilo Asociada: 0x3008h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x3008h: Los punteros nulos deben ser inicializados y comparados con NULL, no con 0](0x3008h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Dh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
'str == '\0'' compara la dirección del puntero con 0 (equivalente a str == NULL). Para verificar el carácter terminador debe usarse '*str == '\0''.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Dh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Desreferenciá el puntero: '*str == '\0'' o 'str[0] == '\0''.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
if (str == '\0') { ... }
```

### Código Idiomático Refactorizado (Correcto)
```c
if (*str == '\0') { ... }
```
