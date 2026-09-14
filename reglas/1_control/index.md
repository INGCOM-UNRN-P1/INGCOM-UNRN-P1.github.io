---
title: "Estructuras de Control y Lazos (0x10XX)"
short_title: "Control de Flujo"
subtitle: "Reglas para sentencias condicionales, lazos de iteración, llaves y flujo de ejecución."
---

# Estructuras de Control y Lazos (0x10XX)

Reglas para sentencias condicionales, lazos de iteración, llaves y flujo de ejecución.

```{tableofcontents}
```

## Catálogo de Reglas

| Regla | Descripción |
| :--- | :--- |
| [0x1001h](0x1001h.md) | Todas las estructuras de control deben utilizar llaves |
| [0x1002h](0x1002h.md) | Restringí el uso de break y continue; preferí lazos con bandera de control |
| [0x1003h](0x1003h.md) | Utilizá el lazo for para iteraciones con rango o contador definido y while para lazos controlados por condiciones lógicas |
| [0x1004h](0x1004h.md) | Las condiciones complejas deben ser simplificadas o comentadas Si una |
| [0x1005h](0x1005h.md) | Reemplazá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato |
| [0x1006h](0x1006h.md) | No utilizar la instrucción goto |
| [0x1007h](0x1007h.md) | No utilizar el operador condicional (ternario) ?: |
| [0x1008h](0x1008h.md) | Toda instrucción switch debe incluir un caso default |
| [0x100Ah](0x100Ah.md) | Prohibición de asignaciones simples dentro de condiciones lógicas |
| [0x100Bh](0x100Bh.md) | Prohibición de estructuras de control con cuerpo vacío (if (...);) |
| [0x100Ch](0x100Ch.md) | No utilices comparaciones en estilo Yoda ('CONST == variable') |
| [0x100Dh](0x100Dh.md) | Prohibición de casts de tipo innecesarios o redundantes |
| [0x100Eh](0x100Eh.md) | Espaciado obligatorio alrededor de operadores ternarios ('? :') |
| [0x100Fh](0x100Fh.md) | Prohibición de condiciones de parada compuestas complejas en lazos for |
| [0x1010h](0x1010h.md) | Delimitación obligatoria con bloque de llaves en lazos do-while |
| [0x1011h](0x1011h.md) | Prohibición de cláusula else redundante tras sentencia de retorno anticipado |
| [0x1012h](0x1012h.md) | Prohibición de comparaciones encadenadas no idiomáticas en C (a < b < c) |
| [0x1013h](0x1013h.md) | Prohibición de saltos no estructurados goto fuera del patrón canónico de liberación de recursos |
| [0x1014h](0x1014h.md) | Prohibición de expresiones de asignación dentro de estructuras de control |
| [0x1016h](0x1016h.md) | Detector de expresiones booleanas complejas sin paréntesis aclaratorios |
| [0x1017h](0x1017h.md) | Detector de operadores de incremento o decremento múltiples en una misma expresión |
