---
title: "Antipatrón AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros"
short_title: "AP-0x302Ah"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x302Ah)=
(0x302Ah_ap)=
# Antipatrón AP-0x302Ah: Casteo forzado de tipos numéricos o literales enteros a punteros

:::{admonition} Regla de Estilo Asociada: 0x300Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x300Ah: Utilizá cast explícito al convertir tipos de punteros](0x300Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x302Ah` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
En arquitecturas modernas con memoria virtual, acceder a direcciones fijas arbitrarias sin mapeo causa violación de segmento inmediata y anula la portabilidad.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x302Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Obtené punteros mediante asignadores dinámicos ('malloc') o el operador de dirección ('&') sobre objetos válidos.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
int *p = (int *)0x1000;
```

### Código Idiomático Refactorizado (Correcto)
```c
int *p = malloc(sizeof(int));
```
