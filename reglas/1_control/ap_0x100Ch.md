---
title: "Antipatrón AP-0x100Ch: Caso de switch sin break (Fallthrough no intencional)"
short_title: "AP-0x100Ch"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Ch)=
# Antipatrón AP-0x100Ch: Caso de switch sin break (Fallthrough no intencional)

:::{admonition} Regla de Estilo Asociada: 0x100Ch
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x100Ch: mitigar comparaciones en estilo Yoda ('CONST == variable')](0x100Ch.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Ch` | Categoría: Estructuras de Control y Lazos (0x10XX)
```


## Diagnóstico
Omitir el 'break' provoca que la ejecución caiga directamente al caso siguiente (fallthrough), usualmente un error no deseado.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x100Ch` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Agregá 'break;' al final del caso o documentá explícitamente '// fallthrough'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
switch (op) {
case 1:
    hacer_1();
case 2:
    hacer_2();
    break;
}
```

### Código Idiomático Refactorizado (Correcto)
```c
switch (op) {
case 1:
    hacer_1();
    break;
case 2:
    hacer_2();
    break;
}
```
