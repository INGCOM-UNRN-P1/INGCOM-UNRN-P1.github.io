---
title: "Antipatrones de Control de Flujo e Iteración"
short_title: "Control y Lazos"
subtitle: "Errores de estructuración en lazos, condiciones ambiguas, variables flotantes como contadores y fallthrough no controlado."
---

# Antipatrones de Control de Flujo e Iteración

Errores de estructuración en lazos, condiciones ambiguas, variables flotantes como contadores y fallthrough no controlado.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [AP005](ap005_1005.md) | Comparación booleana explícita redundante |
| [AP006](ap006_1001.md) | Punto y coma accidental tras condición de control |
| [AP009](ap009_100D.md) | Variable float o double utilizada como contador de bucle |
| [AP016](ap016_100A.md) | Asignación accidental en condición lógica (if (x = 5)) |
| [AP021](ap021_100C.md) | Caso de switch sin break (Fallthrough no intencional) |
| [AP023](ap023_100E.md) | Expresión booleana tautológica o contradictoria |
| [AP027](ap027_100F.md) | Posible error off-by-one en condición de parada de bucle |
| [AP029](ap029_1010.md) | Precedencia errónea entre asignación y comparación |
| [AP031](ap031_1011.md) | Comparación de igualdad estricta en punto flotante |
| [AP039](ap039_1014.md) | Invocación a strlen() en condición de parada de bucle for |
| [AP040](ap040_1015.md) | Modificación de variable de control dentro del cuerpo del for |
| [AP043](ap043_1016.md) | Uso de operador bit a bit (&, |) en condición lógica en lugar de booleano (&&, ||) |
| [AP044](ap044_1017.md) | Ramas idénticas duplicadas en bifurcación if-else |
| [AP045](ap045_1018.md) | Ambigüedad sintáctica por omisión de llaves en condicional anidado (Dangling Else) |
| [AP048](ap048_1019.md) | Uso de salto goto hacia atrás vulnerando programación estructurada |
| [AP050](ap050_101A.md) | Comparación lógica invertida con strcmp() en condicional |
| [AP052](ap052_101B.md) | Comparación entre tipos enteros con y sin signo en condición |
| [AP062](ap062_101C.md) | Bucle infinito con salida condicionada exclusivamente por exit() |
