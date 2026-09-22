---
title: 'Uniones y tagged unions'
short_title: '`union`'
---

> **Prerrequisitos**: `struct`, `enum` y ownership.

# Uniones

Una unión comparte una región de almacenamiento. Su tamaño puede incluir
padding. Una tagged union combina una etiqueta y una unión; la etiqueta debe
validarse antes de leer el miembro seleccionado. La interpretación de otro
miembro puede depender de la implementación y no es una conversión portable de
bits.

```c
#include <stdio.h>

typedef enum { VAL_INT, VAL_DOUBLE } tipo_t;
typedef struct {
    tipo_t tipo;
    union { int i; double d; } valor;
} valor_t;

valor_t v = { VAL_INT, { .i = 7 } };
if (v.tipo == VAL_INT) printf("%d\n", v.valor.i);
```

La etiqueta y la unión deben actualizarse juntas. Para serializar una unión no
es suficiente escribir sus bytes: hay que definir formato, tamaño y
representación de cada alternativa.
