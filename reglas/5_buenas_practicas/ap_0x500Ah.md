---
title: "Antipatrón AP-0x500Ah: Macro con argumentos evaluados múltiples veces"
short_title: "AP-0x500Ah"
subtitle: "Compilación, Buenas Prácticas y Seguridad (0x50XX)"
---

(ap_0x500Ah)=
(0x500Ah_ap)=
# Antipatrón AP-0x500Ah: Macro con argumentos evaluados múltiples veces

:::{admonition} Regla de Estilo Asociada: 0x500Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x500Ah: Protección obligatoria de parámetros en macros funcionales mediante paréntesis](0x500Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x500Ah` | Categoría: Compilación, Buenas Prácticas y Seguridad (0x50XX)
```


## Diagnóstico
Si el cliente invoca la macro pasando una expresión con efecto colateral (ej. MAX(x++, y)), el argumento se evaluará repetidas veces.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x500Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Reemplazá la macro por una función inline o protegé las evaluaciones.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

### Código Idiomático Refactorizado (Correcto)
```c
static inline int max(int a, int b) { return a > b ? a : b; }
```
