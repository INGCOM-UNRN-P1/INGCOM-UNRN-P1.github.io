---
title: "Estructuras de Control y Lazos (0x10XX)"
short_title: "Control de Flujo"
subtitle: "Reglas y antipatrones para sentencias condicionales, lazos de iteración, llaves y flujo de ejecución."
---

# Estructuras de Control y Lazos (0x10XX)

Reglas y antipatrones para sentencias condicionales, lazos de iteración, llaves y flujo de ejecución.

```{tableofcontents}
```

## Tabla Comparativa: Regla de Estilo ↔ Antipatrón Didáctico

La tabla siguiente unifica las directivas prescriptivas de estilo y los antipatrones detectados:

| Regla de Estilo | Título de la Norma | Antipatrón Didáctico | Código Antipatrón |
| :--- | :--- | :--- | :--- |
| [0x1001h](0x1001h.md) | Todas las estructuras de control deben utilizar llaves | [Punto y coma accidental tras condición de control](ap_0x1001h.md) | `AP-0x1001h` |
| | | [Ambigüedad sintáctica por omisión de llaves en condicional anidado (Dangling Else)](ap_0x1018h.md) | `AP-0x1018h` |
| [0x1002h](0x1002h.md) | Restringí el uso de break y continue; preferí lazos con bandera de control | [Bucle infinito con salida condicionada exclusivamente por exit()](ap_0x101Ch.md) | `AP-0x101Ch` |
| [0x1003h](0x1003h.md) | Utilizá el lazo for para iteraciones con rango o contador definido y while para lazos controlados por condiciones lógicas | [Modificación de variable de control dentro del cuerpo del for](ap_0x1015h.md) | `AP-0x1015h` |
| [0x1004h](0x1004h.md) | Las condiciones complejas deben simplificarse o comentarse | *(Sin antipatrón específico)* | — |
| [0x1005h](0x1005h.md) | Reemplazá las condiciones ambiguas basadas en la 'veracidad' (truthiness) del tipo de dato | [Comparación booleana explícita redundante](ap_0x1005h.md) | `AP-0x1005h` |
| | | [Comparación lógica invertida con strcmp() en condicional](ap_0x101Ah.md) | `AP-0x101Ah` |
| | | [Comparación entre tipos enteros con y sin signo en condición](ap_0x101Bh.md) | `AP-0x101Bh` |
| [0x1006h](0x1006h.md) | No utilizar la instrucción goto | [Uso de salto goto hacia atrás vulnerando programación estructurada](ap_0x1019h.md) | `AP-0x1019h` |
| [0x1007h](0x1007h.md) | No utilizar el operador condicional (ternario) ?: | *(Sin antipatrón específico)* | — |
| [0x1008h](0x1008h.md) | Toda instrucción switch debe incluir un caso default | *(Sin antipatrón específico)* | — |
| [0x100Ah](0x100Ah.md) | Prohibición de asignaciones simples dentro de condiciones lógicas | [Asignación accidental en condición lógica (if (x = 5))](ap_0x100Ah.md) | `AP-0x100Ah` |
| [0x100Bh](0x100Bh.md) | Prohibición de estructuras de control con cuerpo vacío (if (...);) | *(Sin antipatrón específico)* | — |
| [0x100Ch](0x100Ch.md) | No utilices comparaciones en estilo Yoda ('CONST == variable') | [Caso de switch sin break (Fallthrough no intencional)](ap_0x100Ch.md) | `AP-0x100Ch` |
| [0x100Dh](0x100Dh.md) | Prohibición de casts de tipo innecesarios o redundantes | [Variable float o double utilizada como contador de bucle](ap_0x100Dh.md) | `AP-0x100Dh` |
| [0x100Eh](0x100Eh.md) | Espaciado obligatorio alrededor de operadores ternarios ('? :') | [Expresión booleana tautológica o contradictoria](ap_0x100Eh.md) | `AP-0x100Eh` |
| [0x100Fh](0x100Fh.md) | Prohibición de condiciones de parada compuestas complejas en lazos for | [Posible error off-by-one en condición de parada de bucle](ap_0x100Fh.md) | `AP-0x100Fh` |
| [0x1010h](0x1010h.md) | Delimitación obligatoria con bloque de llaves en lazos do-while | [Precedencia errónea entre asignación y comparación](ap_0x1010h.md) | `AP-0x1010h` |
| [0x1011h](0x1011h.md) | Prohibición de cláusula else redundante tras sentencia de retorno anticipado | [Comparación de igualdad estricta en punto flotante](ap_0x1011h.md) | `AP-0x1011h` |
| [0x1012h](0x1012h.md) | Prohibición de comparaciones encadenadas no idiomáticas en C (a < b < c) | *(Sin antipatrón específico)* | — |
| [0x1013h](0x1013h.md) | Prohibición de saltos no estructurados goto fuera del patrón canónico de liberación de recursos | *(Sin antipatrón específico)* | — |
| [0x1014h](0x1014h.md) | Prohibición de expresiones de asignación dentro de estructuras de control | [Invocación a strlen() en condición de parada de bucle for](ap_0x1014h.md) | `AP-0x1014h` |
| [0x1016h](0x1016h.md) | Detector de expresiones booleanas complejas sin paréntesis aclaratorios | [Uso de operador bit a bit (&, |) en condición lógica en lugar de booleano (&&, ||)](ap_0x1016h.md) | `AP-0x1016h` |
| [0x1017h](0x1017h.md) | Detector de operadores de incremento o decremento múltiples en una misma expresión | [Ramas idénticas duplicadas en bifurcación if-else](ap_0x1017h.md) | `AP-0x1017h` |
