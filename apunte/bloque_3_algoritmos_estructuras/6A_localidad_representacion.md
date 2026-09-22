---
title: 'Localidad, AoS/SoA y representación'
short_title: 'Localidad y representación'
subtitle: 'Trade-offs de memoria para algoritmos y estructuras'
---

(capitulo-localidad-representacion)=
> **Prerrequisitos**: `6_complejidad.md`, matrices, `struct` y medición básica.

# Localidad, AoS/SoA y representación

AoS y SoA no son contenidos necesarios para aprender la sintaxis de `struct`.
Aquí se estudian como decisiones de diseño junto con complejidad espacial,
localidad de caché, fragmentación y trade-offs tiempo–espacio.

- **AoS** favorece procesar una entidad completa.
- **SoA** favorece recorrer un atributo de muchas entidades.
- Ninguna representación es universalmente mejor: hay que justificarla por el
  patrón de acceso y medirla.

Las afirmaciones de rendimiento deben indicar compilador, arquitectura, tamaño
de entrada y método de medición.
