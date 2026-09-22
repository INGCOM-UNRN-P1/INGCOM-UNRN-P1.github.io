---
title: 'Rendimiento y fragmentación de memoria'
short_title: 'Rendimiento de memoria'
---

> **Prerrequisitos**: `5_memoria_dinamica.md` y medición experimental.

# Rendimiento y fragmentación

La comparación algorítmica de localidad, AoS/SoA y trade-offs tiempo–espacio se
continúa en [`6A_localidad_representacion.md`](../bloque_3_algoritmos_estructuras/6A_localidad_representacion.md).
Este apunte queda limitado a observaciones del allocator y mediciones de
asignaciones.

Ampliación opcional sobre costo de muchas asignaciones, pools, bloques
contiguos, localidad de caché y medición. Las afirmaciones de rendimiento deben
respaldarse con un benchmark reproducible; no se presentan como garantías del
estándar C.

Compará siempre una hipótesis con mediciones y documentá compilador, flags,
arquitectura y tamaño de entrada.

## Experimento mínimo

Compará un arreglo contiguo con mil reservas pequeñas manteniendo el mismo
número de elementos. Repetí varias veces, calentá la entrada y reportá mediana,
dispersión y memoria utilizada. El objetivo es formular una hipótesis (por
ejemplo, menos llamadas al allocator) y no memorizar una cifra. Conservá la
optimización solo si mantiene claridad y propiedad explícita de cada bloque.
