---
title: "Antipatrón AP-0x301Bh: Desreferencia inmediata tras realloc"
short_title: "AP-0x301Bh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Bh)=
# Antipatrón AP-0x301Bh: Desreferencia inmediata tras realloc

:::{admonition} Regla de Estilo Asociada: 0x3001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x3001h: Siempre verificá la asignación exitosa de memoria dinámica](0x3001h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Bh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
Si el sistema no puede reubicar o expandir el bloque, realloc devuelve NULL y el acceso inmediato causará SIGSEGV.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Bh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Validá siempre 'if (ptr == NULL)' antes de usar el puntero reubicado.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
ptr = realloc(ptr, nuevo_tam);
ptr[0] = 42; // Riesgo de segfault
```

### Código Idiomático Refactorizado (Correcto)
```c
void *tmp = realloc(ptr, nuevo_tam);
if (!tmp) return NULL;
ptr = tmp;
ptr[0] = 42;
```
