---
title: "Antipatrón AP-0x101Ah: Comparación lógica invertida con strcmp() en condicional"
short_title: "AP-0x101Ah"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x101Ah)=
# Antipatrón AP-0x101Ah: Comparación lógica invertida con strcmp() en condicional

:::{admonition} Regla de Estilo Asociada: 0x1005h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x1005h: no uses las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato](0x1005h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x101Ah` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
'strcmp()' retorna 0 cuando ambas cadenas son idénticas. Evaluar 'if (strcmp(a, b))' ejecuta la rama cuando son DIFERENTES.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x101Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Escribí explícitamente 'if (strcmp(a, b) == 0)' para verificar igualdad o '!= 0' para desigualdad.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
if (strcmp(nombre, "admin")) {
    dar_acceso();
}
```

### Código Idiomático Refactorizado (Correcto)
```c
if (strcmp(nombre, "admin") == 0) {
    dar_acceso();
}
```
