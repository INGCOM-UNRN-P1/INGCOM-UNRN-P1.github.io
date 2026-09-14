---
title: "Antipatrón AP-0x101Ch: Bucle infinito con salida condicionada exclusivamente por exit()"
short_title: "AP-0x101Ch"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x101Ch)=
(0x101Ch_ap)=
# Antipatrón AP-0x101Ch: Bucle infinito con salida condicionada exclusivamente por exit()

:::{admonition} Regla de Estilo Asociada: 0x1002h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x1002h: no uses el uso descontrolado de break y continue; preferí lazos con bandera de control](0x1002h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x101Ch` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Terminar la ejecución del proceso mediante 'exit()' dentro de un bucle omite la ejecución del código de limpieza, la liberación de memoria y la preservación de invariantes estructurados.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x101Ch` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Utilizá 'break' o una variable de control booleana para salir limpiamente del bucle y retornar por el flujo natural.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
while (1) {
    if (fin) exit(0);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
while (1) {
    if (fin) break;
}
```
