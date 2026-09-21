---
title: "Estructuras de control y flujo (0x10XX)"
short_title: "Control de flujo"
subtitle: "Reglas sobre condicionales, lazos, bifurcaciones y flujo de ejecucion."
---

# Estructuras de control y flujo (0x10XX)

Reglas sobre condicionales, lazos, bifurcaciones y flujo de ejecucion.

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x1001h](0x1001h.md) | Todas las estructuras de control deben utilizar llaves | `AP-0x1001h`, `AP-0x1018h` |
| [0x1002h](0x1002h.md) | Restringí el uso de break y continue; preferí lazos con bandera de control | `AP-0x101Ch` |
| [0x1003h](0x1003h.md) | Utilizá el lazo for para iteraciones con rango o contador definido y while para lazos controlados por condiciones lógicas | `AP-0x1015h` |
| [0x1004h](0x1004h.md) | Las condiciones complejas deben simplificarse o comentarse | — |
| [0x1005h](0x1005h.md) | Reemplazá las condiciones ambiguas basadas en la 'veracidad' (truthiness) del tipo de dato | `AP-0x1005h`, `AP-0x101Ah`, `AP-0x101Bh` |
| [0x1006h](0x1006h.md) | No utilizar la instrucción goto | `AP-0x1019h` |
| [0x1007h](0x1007h.md) | No utilizar el operador condicional (ternario) ?: | — |
| [0x1008h](0x1008h.md) | Toda instrucción switch debe incluir un caso default | `AP-0x100Ch` |
| [0x1009h](0x1009h.md) | Prohibición de asignaciones simples dentro de condiciones lógicas | `AP-0x100Ah` |
| [0x100Ah](0x100Ah.md) | Prohibición de estructuras de control con cuerpo vacío (if (...);) | — |
| [0x100Bh](0x100Bh.md) | No utilices comparaciones en estilo Yoda ('CONST == variable') | — |
| [0x100Ch](0x100Ch.md) | Espaciado obligatorio alrededor de operadores ternarios ('? :') | — |
| [0x100Dh](0x100Dh.md) | Prohibición de condiciones de parada compuestas complejas en lazos for | `AP-0x100Fh`, `AP-0x1014h` |
| [0x100Eh](0x100Eh.md) | Delimitación obligatoria con bloque de llaves en lazos do-while | — |
| [0x100Fh](0x100Fh.md) | Prohibición de cláusula else redundante tras sentencia de retorno anticipado | — |
| [0x1010h](0x1010h.md) | Prohibición de comparaciones encadenadas no idiomáticas en C (a < b < c) | — |
| [0x1011h](0x1011h.md) | Prohibición de saltos no estructurados goto fuera del patrón canónico de liberación de recursos | — |
| [0x1012h](0x1012h.md) | Prohibición de expresiones de asignación dentro de estructuras de control | `AP-0x1010h` |
| [0x1013h](0x1013h.md) | Detector de expresiones booleanas complejas sin paréntesis aclaratorios | `AP-0x100Eh`, `AP-0x1016h` |
| [0x1014h](0x1014h.md) | Detector de operadores de incremento o decremento múltiples en una misma expresión | — |
| [0x1015h](0x1015h.md) | Limitá la profundidad de anidación a tres niveles | — |
| [0x1016h](0x1016h.md) | Documentá el invariante de cada lazo | — |
| [0x1017h](0x1017h.md) | Escribí condiciones afirmativas y directas | — |
| [0x1018h](0x1018h.md) | No uses variables de punto flotante como control de lazo | *(regla promovida de antipatrón)* |
