---
title: 'Guía editorial para ejercicios'
short_title: 'Editorialización de ejercicios'
subtitle: 'Consignas graduadas, criterios de corrección y retroalimentación'
---

# Guía editorial para ejercicios

Un ejercicio debe evaluar una decisión o habilidad identificable. La dificultad
debe provenir del concepto, no de una consigna ambigua o de datos innecesarios.

## Plantilla mínima

- objetivo y nivel de dificultad;
- consigna autónoma, con entradas, salidas y restricciones;
- formato de entrega o criterio de observación;
- pista opcional que no revele la solución;
- solución o criterio de corrección;
- casos límite y errores esperables.

La consigna debe indicar ownership, convenciones de índices, tolerancias,
complejidad o comportamiento ante error cuando sean parte de la evaluación.

## Progresión

Ordenar actividades de reconocimiento, aplicación, modificación y diseño. Cada
ejercicio nuevo debe reutilizar como máximo una dificultad importante no
introducida. Alternar ejemplos normales con bordes (`0`, vacío, `NULL`, máximo,
fallo de asignación) y explicar qué aprendizaje verifica cada borde.

## Soluciones y feedback

La solución debe mostrar invariantes y decisiones, no solo el código final.
Incluir una prueba mínima y señalar por qué las alternativas incorrectas fallan.
No exigir una implementación que contradiga el contrato enseñado en el apunte.
Cuando haya varias soluciones válidas, corregir por propiedades observables y
no por coincidencia textual.
