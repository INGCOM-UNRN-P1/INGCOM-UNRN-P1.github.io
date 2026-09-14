---
title: "Antipatrón AP-0x301Ah: Tamaño insuficiente en memset con sizeof(ptr)"
short_title: "AP-0x301Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Ah)=
# Antipatrón AP-0x301Ah: Tamaño insuficiente en memset con sizeof(ptr)

:::{admonition} Regla de Estilo Asociada: 0x301Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x301Ah: Validador de uso idiomático de tipos booleanos estándar](0x301Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
Usar sizeof(ptr) solo limpia el tamaño del puntero (4 u 8 bytes) dejando el resto de la estructura o buffer sin inicializar.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Usá 'sizeof(*ptr)' o el tamaño real del búfer.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
struct nodo_t *n = malloc(sizeof(*n));
memset(n, 0, sizeof(n));
```

### Código Idiomático Refactorizado (Correcto)
```c
memset(n, 0, sizeof(*n));
```
