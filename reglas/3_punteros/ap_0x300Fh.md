---
title: "Antipatrón AP-0x300Fh: Uso de sizeof(puntero) en reserva dinámica"
short_title: "AP-0x300Fh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Fh)=
(0x300Fh_ap)=
# Antipatrón AP-0x300Fh: Uso de sizeof(puntero) en reserva dinámica

:::{admonition} Regla de Estilo Asociada: 0x300Fh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Fh: Liberá la memoria en el orden inverso a su asignación](0x300Fh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Fh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
'sizeof(ptr)' devuelve el tamaño del puntero (4 u 8 bytes) en lugar del tamaño de la estructura apuntada, provocando reservas insuficientes.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x300Fh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Escribí 'malloc(sizeof(*ptr) * n)' o 'malloc(sizeof(struct tipo))'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
nodo_t *n = malloc(sizeof(n));
```

### Código Idiomático Refactorizado (Correcto)
```c
nodo_t *n = malloc(sizeof(*n));
```
