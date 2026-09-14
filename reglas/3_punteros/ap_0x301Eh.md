---
title: "Antipatrón AP-0x301Eh: Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo"
short_title: "AP-0x301Eh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Eh)=
# Antipatrón AP-0x301Eh: Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo

:::{admonition} Regla de Estilo Asociada: 0x300Bh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Bh: Usá siempre sizeof en las asignaciones de memoria dinámica, prefiriendo sizeof(*ptr)](0x300Bh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Eh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
strlen() cuenta solo los caracteres visibles. Copiar la cadena en un bloque de strlen(s) bytes provoca un buffer overflow de un byte (off-by-one).

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Eh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Sumá 1 byte al tamaño asignado: 'malloc(strlen(s) + 1)'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
char *dup = malloc(strlen(s));
```

### Código Idiomático Refactorizado (Correcto)
```c
char *dup = malloc(strlen(s) + 1);
```
