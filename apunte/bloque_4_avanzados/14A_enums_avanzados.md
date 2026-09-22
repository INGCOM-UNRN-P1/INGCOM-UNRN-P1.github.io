---
title: 'Enumeraciones avanzadas'
short_title: 'Enums avanzados'
---

> **Prerrequisitos**: `11_enums.md` y `switch`.

# Enumeraciones avanzadas

Ampliación sobre máquinas de estados, validación de entradas externas,
sentinelas, flags y compatibilidad entre enumeraciones y enteros.

Una enumeración recibida desde un archivo o la red debe validarse antes de
usarla como índice o selector. Para flags, usá una máscara de tipo entero y
documentá qué combinaciones son válidas; un `enum` no impide por sí solo que
una conversión produzca un valor fuera de sus enumeradores.

```c
typedef enum { ESPERA, ACTIVA, TERMINADA } estado_t;
bool estado_valido(int x) { return x >= ESPERA && x <= TERMINADA; }
```

Las máquinas de estados son más fáciles de revisar cuando cada transición
indica estado de entrada, evento y estado de salida.
