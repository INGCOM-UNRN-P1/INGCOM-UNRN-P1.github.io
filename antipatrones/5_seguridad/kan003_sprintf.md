---
title: "KAN003: Formateo inseguro con 'sprintf()'"
short_title: "KAN003"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan003_sprintf)=
# KAN003: Formateo inseguro con 'sprintf()'

```{admonition} Severidad: ALTO
:class: warning
Código de auditoría: `KAN003`
```

## Diagnóstico
'sprintf' no verifica el tamaño del búfer destino.

## Justificación Pedagógica y de Estándar C
Al formatear cadenas con `sprintf()`, no se provee información sobre la dimensión del destino. Valores numéricos de gran magnitud o cadenas de longitud variable pueden sobrepasar la capacidad asignada.

## Sugerencia de Refactorización
Reemplazá 'sprintf(buf, ...)' por 'snprintf(buf, sizeof(buf), ...)'.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <stdio.h>

void formatear_mensaje(const char *id, int codigo)
{
    char salida[32];
    /* Desborde si la concatenación excede 31 caracteres */
    sprintf(salida, "ID: %s, Cod: %d", id, codigo);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>

void formatear_mensaje(const char *id, int codigo)
{
    char salida[32];
    /* Acotado a sizeof(salida) */
    snprintf(salida, sizeof(salida), "ID: %s, Cod: %d", id, codigo);
}
```
