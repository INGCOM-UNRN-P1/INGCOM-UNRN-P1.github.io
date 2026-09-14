---
title: "KAN004: Lectura sin límite en 'scanf("%s")'"
short_title: "KAN004"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan004_scanf)=
# KAN004: Lectura sin límite en 'scanf("%s")'

```{admonition} Severidad: ALTO
:class: warning
Código de auditoría: `KAN004`
```

## Diagnóstico
El especificador '%s' sin ancho máximo en scanf permite escribir más bytes de los reservados.

## Justificación Pedagógica y de Estándar C
El especificador `%s` en `scanf` consume caracteres de manera ilimitada hasta hallar un delimitador de espacio en blanco, constituyendo un riesgo de desbordamiento equivalente al de `gets()`.

## Sugerencia de Refactorización
Especificá el ancho máximo, por ejemplo: 'scanf("%99s", buf)' para un arreglo de 100 chars.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <stdio.h>

void leer_palabra(void)
{
    char palabra[20];
    /* Desborde si el usuario ingresa más de 19 letras */
    scanf("%s", palabra);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>

void leer_palabra(void)
{
    char palabra[20];
    /* Límite explícito de ancho: máx 19 chars + '\0' */
    scanf("%19s", palabra);
}
```
