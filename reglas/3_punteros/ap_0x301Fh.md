---
title: "Antipatrón AP-0x301Fh: Asignación de retorno de malloc() a variable no puntero"
short_title: "AP-0x301Fh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Fh)=
# Antipatrón AP-0x301Fh: Asignación de retorno de malloc() a variable no puntero

:::{admonition} Regla de Estilo Asociada: 0x3001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x3001h: Siempre verificá la asignación exitosa de memoria dinámica](0x3001h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Fh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
```


## Diagnóstico
Los punteros en arquitecturas modernas tienen 64 bits de ancho. Asignarlos a un entero nativo trunca la dirección y corrompe el puntero.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x301Fh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Declará la variable como puntero ('tipo *ptr = malloc(...)').

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
int addr = malloc(sizeof(int));
```

### Código Idiomático Refactorizado (Correcto)
```c
int *ptr = malloc(sizeof(int));
```
