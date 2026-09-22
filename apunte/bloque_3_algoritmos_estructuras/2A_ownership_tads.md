---
title: 'Ownership, estructuras opacas y TADs'
short_title: 'Ownership y TADs'
subtitle: 'Puente entre memoria dinámica y abstracciones de datos'
---

(capitulo-ownership-tads)=
> **Prerrequisitos**: memoria dinámica, `struct`, doble indirección y
> `2_tad.md`.

# Ownership, estructuras opacas y TADs

Este es el destino de los patrones de creación/destrucción que aparecen en el
Bloque 2. En un TAD no basta con saber usar `malloc`: la interfaz debe declarar
quién posee cada recurso, cuándo se transfiere la propiedad y qué ocurre ante
un fallo parcial.

## Separación de responsabilidades

- Bloque 2: reserva, liberación y composición concreta de objetos.
- Bloque 3: interfaz pública, representación oculta, invariantes y varias
  implementaciones de una misma abstracción.

## Patrón mínimo

```c
typedef struct secuencia secuencia_t;

secuencia_t *secuencia_crear(void);
void secuencia_destruir(secuencia_t **secuencia);
```

El destructor recibe doble puntero cuando debe anular la variable del cliente.
Los callbacks de destrucción, comparación y visita se estudian junto con la
genericidad del TAD, no en el capítulo introductorio de `struct`.
