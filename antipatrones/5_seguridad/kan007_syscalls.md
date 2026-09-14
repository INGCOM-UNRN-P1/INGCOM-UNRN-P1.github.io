---
title: "KAN007: Llamada a sistema restringida fuera de consigna"
short_title: "KAN007"
subtitle: "Seguridad y Funciones Vulnerables"
---

(kan007_syscalls)=
# KAN007: Llamada a sistema restringida fuera de consigna

```{admonition} Severidad: ALTO
:class: warning
Código de auditoría: `KAN007`
```

## Diagnóstico
Se detectó el uso de syscalls de control de procesos o red (fork, exec, kill, ptrace, socket) en una práctica donde no están autorizadas.

## Justificación Pedagógica y de Estándar C
El uso de llamadas al sistema avanzadas sin autorización de consigna altera el modelo pedagógico y puede evadir verificaciones en sandboxes automáticos.

## Sugerencia de Refactorización
Resolvé el ejercicio utilizando únicamente las primitivas de E/S y algoritmos solicitados.

## Ejemplos de Código

### Código con Antipatrón (Incorrecto)
```c
#include <unistd.h>

void crear_tarea(void)
{
    /* Syscall restringida fuera del alcance del TP */
    fork();
}
```

### Código Idiomático Refactorizado (Correcto)
```c
void ejecutar_algoritmo(void)
{
    /* Resolución algorítmica canónica de la materia */
}
```
