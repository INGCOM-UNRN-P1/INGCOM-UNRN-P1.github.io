---
title: "Antipatrón AP-0x500Bh: Redefinición de identificadores de funciones estándar de la biblioteca C"
short_title: "AP-0x500Bh"
subtitle: "Compilación, Buenas Prácticas y Seguridad (0x50XX)"
---

(ap_0x500Bh)=
# Antipatrón AP-0x500Bh: Redefinición de identificadores de funciones estándar de la biblioteca C

:::{admonition} Regla de Estilo Asociada: 0x500Bh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x500Bh: Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C](0x500Bh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x500Bh` | Categoría: Compilación, Buenas Prácticas y Seguridad (0x50XX)
```


## Diagnóstico
Redefinir identificadores estándar causa colisiones de enlace con la libc o comportamientos indefinidos por interferencia con macros del sistema.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x500Bh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Elegí un identificador con prefijo institucional o descriptivo de tu módulo (ej. 'calcular_abs', 'mi_min').

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
int abs(int x) {
    return x < 0 ? -x : x;
}
```

### Código Idiomático Refactorizado (Correcto)
```c
int valor_absoluto(int x) {
    return x < 0 ? -x : x;
}
```
