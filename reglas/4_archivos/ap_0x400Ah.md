---
title: "Antipatrón AP-0x400Ah: Lectura de cadenas con scanf() sin límite de ancho en buffer fijo"
short_title: "AP-0x400Ah"
subtitle: "Gestión de Archivos y Errores (0x40XX)"
---

(ap_0x400Ah)=
(0x400Ah_ap)=
# Antipatrón AP-0x400Ah: Lectura de cadenas con scanf() sin límite de ancho en buffer fijo

:::{admonition} Regla de Estilo Asociada: 0x400Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x400Ah: Prohibición de operar sobre flujos de archivo tras haber invocado fclose() (use-after-close)](0x400Ah.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x400Ah` | Categoría: Gestión de Archivos y Errores (0x40XX)
```


## Diagnóstico
'%s' lee hasta encontrar un espacio en blanco sin verificar el tamaño del buffer destino, permitiendo desbordamientos de buffer (buffer overflow).

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x400Ah` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Especificá el ancho máximo restando el byte nulo terminador (ej. '%9s' para un buffer de 10 bytes) o utilizá fgets().

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
char buf[10];
scanf("%s", buf);
```

### Código Idiomático Refactorizado (Correcto)
```c
char buf[10];
scanf("%9s", buf);
```
