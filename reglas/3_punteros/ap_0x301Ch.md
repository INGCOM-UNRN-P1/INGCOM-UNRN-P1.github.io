---
title: "Antipatrón AP-0x301Ch: Casteo redundante en invocación de free()"
short_title: "AP-0x301Ch"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Ch)=
(0x301Ch_ap)=
# Antipatrón AP-0x301Ch: Casteo redundante en invocación de free()

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Ch` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
'free()' recibe 'void*', por lo que cualquier tipo de puntero se convierte implícitamente sin necesidad de cast.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Ch` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Invocá 'free(p);' directamente sin casteo de tipo.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
free((void *)ptr);
```

### Código Idiomático Refactorizado (Correcto)
```c
free(ptr);
```
