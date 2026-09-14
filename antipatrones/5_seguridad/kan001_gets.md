---
title: "KAN001: Uso de la función prohibida 'gets()'"
short_title: "KAN001"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan001_gets)=
# KAN001: Uso de la función prohibida 'gets()'

```{admonition} Severidad: CRÍTICO
:class: warning
Código de auditoría: `KAN001`
```

## Diagnóstico
'gets()' no verifica los límites del búfer destino y es intrínsecamente vulnerable a desbordamientos de búfer (Buffer Overflow).

## Justificación Pedagógica y de Estándar C
La función `gets()` fue declarada obsoleta en ISO C99 y formalmente removida del estándar ISO C11. Debido a que no recibe la capacidad del búfer receptor, cualquier entrada que exceda su tamaño sobreescribe la memoria adyacente del Stack Frame, corrompiendo la dirección de retorno.

## Sugerencia de Refactorización
Reemplazá 'gets(buf)' por 'fgets(buf, sizeof(buf), stdin)'.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <stdio.h>

void leer_usuario(void)
{
    char buffer[64];
    /* PELIGRO: buffer overflow inevitable si la entrada > 63 chars */
    gets(buffer);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>

void leer_usuario(void)
{
    char buffer[64];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        /* Lectura acotada a los 64 bytes de buffer */
    }
}
```
