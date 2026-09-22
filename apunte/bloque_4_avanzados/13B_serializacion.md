---
title: 'Serialización y representación externa'
short_title: 'Serialización'
---

> **Prerrequisitos**: `7_estructuras.md`, `4A_archivos_avanzados.md`.

# Serialización

Una representación externa debe fijar versión, tamaños, endianness y límites.
No escribas una `struct` completa: puede contener padding, punteros y tipos cuyo
tamaño cambia entre plataformas. Serializá cada campo y validá longitudes antes
de reservar memoria al leer.
