---
title: 'Estructuras opacas y encapsulación'
short_title: 'Estructuras opacas'
---

> **Prerrequisitos**: `7_estructuras.md`, punteros y ownership.

# Estructuras opacas

Un encabezado puede declarar `typedef struct objeto objeto_t;` y exponer solo
constructores, operaciones y destructor. La definición completa queda en el
`.c`, preservando invariantes y permitiendo cambiar la representación sin
recompilar clientes. La API debe documentar quién libera cada resultado y qué
ocurre ante fallos parciales.
