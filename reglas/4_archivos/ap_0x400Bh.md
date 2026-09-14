---
title: "Antipatrón AP-0x400Bh: Omisión de verificación de retorno NULL en fopen()"
short_title: "AP-0x400Bh"
subtitle: "Gestión de Archivos y Errores (0x40XX)"
---

(ap_0x400Bh)=
# Antipatrón AP-0x400Bh: Omisión de verificación de retorno NULL en fopen()

:::{admonition} Regla de Estilo Asociada: 0x4001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x4001h: Manejá correctamente la apertura y cierre de archivos](0x4001h.md)**.
:::

```{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x400Bh` | Categoría: Gestión de Archivos y Errores (0x40XX)
```


## Diagnóstico
Si el archivo no existe o no tiene permisos de lectura/escritura, 'fopen()' retorna NULL. Desreferenciarlo en 'fread', 'fgets' o 'fgetc' causa caída inmediata por SIGSEGV.

## Justificación Pedagógica y de Estándar C
El código de diagnóstico `0x400Bh` identifica una práctica desaconsejada en la arquitectura pedagógica de la materia.
Esta transgresión incrementa el acoplamiento, produce comportamiento indefinido o vulnera los invariantes de memoria.

## Sugerencia de Corrección
Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'.

## Ejemplos

### Código con Antipatrón (Incorrecto)
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
```

### Código Idiomático Refactorizado (Correcto)
```c
FILE *f = fopen("datos.txt", "r");
if (f == NULL) return -1;
fread(&elem, sizeof(elem), 1, f);
```
