---
title: "KAN005: Vulnerabilidad de cadena de formato (Format String)"
short_title: "KAN005"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan005_format_string)=
# KAN005: Vulnerabilidad de cadena de formato (Format String)

```{admonition} Severidad: CRÍTICO
:class: warning
Código de auditoría: `KAN005`
```

## Diagnóstico
Pasar una variable directamente como primer argumento a 'printf(str)' permite leer y escribir memoria arbitraria de la pila mediante especificadores maliciosos.

## Justificación Pedagógica y de Estándar C
Si el primer parámetro de `printf` proviene del usuario, un atacante puede inyectar especificadores como `%x`, `%p` o `%n` para leer datos privados del Stack Frame o escribir valores en direcciones de memoria del proceso.

## Sugerencia de Refactorización
Usá siempre una cadena de formato literal constante: 'printf("%s", str);'.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <stdio.h>

void mostrar_aviso(const char *texto)
{
    /* VULNERABILIDAD CRÍTICA: formato variable */
    printf(texto);
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>

void mostrar_aviso(const char *texto)
{
    /* Formato literal constante */
    printf("%s", texto);
}
```
