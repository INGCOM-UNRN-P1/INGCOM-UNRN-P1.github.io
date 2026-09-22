---
title: 'Campos de bits'
short_title: 'Bit-fields'
---

> **Prerrequisitos**: `7_estructuras.md` y operadores bit a bit.

# Campos de bits

Los bit-fields son útiles para describir banderas compactas, pero el orden de
bits, unidad de almacenamiento, padding y posibilidad de tomar su dirección
dependen de la implementación. No son un formato portable de red. Para
serializar usá máscaras sobre enteros de ancho conocido y definí endianness.
