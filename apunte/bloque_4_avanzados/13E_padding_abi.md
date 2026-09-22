---
title: 'Padding, alineación y ABI'
short_title: 'Padding y ABI'
---

> **Prerrequisitos**: `7_estructuras.md` y `offsetof`.

# Padding y ABI

El estándar garantiza el orden de miembros, no un layout universal. El ABI
concreto decide alineación, padding intermedio y padding final. Usá
`sizeof`, `offsetof` y, cuando esté disponible, `alignof` para inspeccionar una
implementación; no serialices una estructura suponiendo que otro compilador
usará el mismo layout.
