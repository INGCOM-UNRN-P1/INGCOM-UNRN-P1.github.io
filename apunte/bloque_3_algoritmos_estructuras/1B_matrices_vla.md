---
title: 'VLA y tipos modificados variables'
short_title: 'VLA'
---

> **Prerrequisitos**: aritmética de punteros y declaración de arrays.

# VLA y tipos modificados

Los VLA forman parte de C99 en implementaciones que los soportan. La cátedra
los deja fuera del camino principal por portabilidad y control del stack; eso es
una decisión didáctica, no una prohibición universal del estándar.

Un puntero a un array de dimensión variable puede apuntar a almacenamiento del
heap, pero su tipo sigue siendo variably modified y exige que la dimensión esté
disponible en el ámbito correspondiente.
