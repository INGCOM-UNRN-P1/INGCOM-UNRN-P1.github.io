---
title: "Antipatrones de Seguridad y Vulnerabilidades"
short_title: "Seguridad"
subtitle: "Llamadas a funciones intrínsecamente vulnerables, desbordamientos de búfer en pila y vectores de inyección."
---

# Antipatrones de Seguridad y Vulnerabilidades

Llamadas a funciones intrínsecamente vulnerables, desbordamientos de búfer en pila y vectores de inyección.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [KAN001](kan001_gets.md) | Uso de la función prohibida 'gets()' |
| [KAN002](kan002_strcpy.md) | Copia insegura de cadenas con 'strcpy()' o 'strcat()' |
| [KAN003](kan003_sprintf.md) | Formateo inseguro con 'sprintf()' |
| [KAN004](kan004_scanf.md) | Lectura sin límite en 'scanf("%s")' |
| [KAN005](kan005_format_string.md) | Vulnerabilidad de cadena de formato (Format String) |
| [KAN006](kan006_system.md) | Invocación al intérprete de comandos con 'system()' o 'popen()' |
| [KAN007](kan007_syscalls.md) | Llamada a sistema restringida fuera de consigna |
