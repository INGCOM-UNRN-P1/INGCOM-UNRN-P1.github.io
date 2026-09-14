---
title: "Antipatrón AP-0x100Dh: Variable float o double utilizada como contador de bucle"
short_title: "AP-0x100Dh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Dh)=
(0x100Dh_ap)=
# Antipatrón AP-0x100Dh: Variable float o double utilizada como contador de bucle

:::{admonition} Regla de Estilo Asociada: 0x100Dh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x100Dh: Prohibición de casts de tipo innecesarios o redundantes](0x100Dh.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Dh` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Los tipos flotantes acumulan errores de redondeo binario IEEE-754 en cada iteración, provocando bucles infinitos o conteos inexactos.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x100Dh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Utilizá un contador entero (int o size_t) y derivá el valor flotante dentro del cuerpo del bucle.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
for (float x = 0.0f; x < 1.0f; x += 0.1f) { ... }
```

### Código Idiomático Refactorizado (Correcto)
```c
for (int i = 0; i < 10; i++) {
    float x = i * 0.1f;
}
```
