---
title: "KAN002: Copia insegura de cadenas con 'strcpy()' o 'strcat()'"
short_title: "KAN002"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan002_strcpy)=
# KAN002: Copia insegura de cadenas con 'strcpy()' o 'strcat()'

```{admonition} Severidad: ALTO
:class: warning
Código de auditoría: `KAN002`
```

## Diagnóstico
'strcpy' y 'strcat' no limitan la cantidad de bytes copiados, provocando corrupción de memoria si la cadena origen excede el búfer.

## Justificación Pedagógica y de Estándar C
Las funciones `strcpy` y `strcat` asumen implícitamente que el búfer receptor cuenta con espacio suficiente para almacenar todos los caracteres de la fuente junto con el byte nulo terminador. Si la cadena origen supera la capacidad del destino, se produce sobreescritura arbitraria de memoria.

## Sugerencia de Refactorización
Usá 'strncpy(dst, src, sizeof(dst) - 1); dst[sizeof(dst)-1] = '\0';' o 'snprintf()'.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <string.h>

void copiar_nombre(const char *origen)
{
    char destino[32];
    /* Vulnerable si origen > 31 bytes */
    strcpy(destino, origen);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>
#include <string.h>

void copiar_nombre(const char *origen)
{
    char destino[32];
    /* Copia acotada al tamaño exacto del destino */
    snprintf(destino, sizeof(destino), "%s", origen);
}
```
