---
title: 'Matrices tridimensionales dinámicas'
short_title: 'Matrices 3D'
---

> **Prerrequisitos**: aritmética de punteros y matrices contiguas de 2D.

# Matrices tridimensionales

La versión canónica para el recorrido de algoritmos está en
[`1A_matrices_dinamicas.md`](../bloque_3_algoritmos_estructuras/1A_matrices_dinamicas.md).
Este archivo queda como referencia de representación; los algoritmos,
recorridos y análisis de localidad se estudian en el Bloque 3.

Ampliación opcional. Antes de usar una representación 3D, fijá dimensiones,
layout, ownership y estrategia de liberación. Para un bloque contiguo, el índice
lineal de `[i][j][k]` es `i * filas * columnas + j * columnas + k`.

Controlá overflow en cada multiplicación y documentá el orden de las
dimensiones.
