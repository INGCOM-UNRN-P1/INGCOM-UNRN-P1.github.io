---
title: 'Estructuras opacas e invariantes'
short_title: 'Estructuras opacas'
---

> **Prerrequisitos**: estructuras dinámicas, doble indirección y contratos.

# Estructuras opacas

La versión canónica de este tema está en
[`2A_ownership_tads.md`](../bloque_3_algoritmos_estructuras/2A_ownership_tads.md),
donde se estudian interfaz, ownership, invariantes y múltiples
implementaciones. En este bloque solo se conserva la mecánica de liberar una
estructura concreta.

Una interfaz puede ocultar la definición de una estructura en un `.c` y exponer
solo un tipo incompleto en el header. Las funciones crear/destruir deben
documentar ownership, errores parciales e invariantes.
