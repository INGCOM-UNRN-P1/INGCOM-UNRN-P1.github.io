---
title: "KAN006: Invocación al intérprete de comandos con 'system()' o 'popen()'"
short_title: "KAN006"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan006_system)=
# KAN006: Invocación al intérprete de comandos con 'system()' o 'popen()'

```{admonition} Severidad: CRÍTICO
:class: warning
Código de auditoría: `KAN006`
```

## Diagnóstico
Ejecutar comandos del shell mediante 'system()' es vulnerable a inyección de comandos y está desaconsejado en la cátedra.

## Justificación Pedagógica y de Estándar C
`system()` invoca a `/bin/sh -c`, introduciendo vulnerabilidades de inyección si la cadena de comando incluye entradas no saneadas. Además introduce sobrecarga innecesaria al crear subprocesos del intérprete.

## Sugerencia de Refactorización
Utilizá funciones nativas de la biblioteca estándar de C o APIs del sistema en lugar de llamar al shell.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <stdlib.h>

void pausar_consola(void)
{
    /* Invocación costosa e insegura al intérprete */
    system("pause");
}
```

### Código Idiomático Refactorizado (Correcto)
```c
#include <stdio.h>

void pausar_consola(void)
{
    /* Primitiva estándar de E/S en C */
    getchar();
}
```
