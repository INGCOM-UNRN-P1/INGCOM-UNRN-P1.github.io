---
title: "Funciones y Modularización (0x20XX)"
short_title: "Funciones y Modularización"
subtitle: "Reglas y antipatrones para diseño de interfaces, firmas, contratos, modularidad y alcance."
---

# Funciones y Modularización (0x20XX)

Reglas y antipatrones para diseño de interfaces, firmas, contratos, modularidad y alcance.

```{tableofcontents}
```

## Tabla Comparativa: Regla de Estilo ↔ Antipatrón Didáctico

La tabla siguiente unifica las directivas prescriptivas de estilo y los antipatrones detectados:

| Regla de Estilo | Título de la Norma | Antipatrón Didáctico | Código Antipatrón |
| :--- | :--- | :--- | :--- |
| [0x2001h](0x2001h.md) | Las funciones deben usar cláusulas de guarda y retornos anticipados para mitigar la anidación profunda | *(Sin antipatrón específico)* | — |
| [0x2002h](0x2002h.md) | Las funciones no deben contener printf o scanf, a menos que ese sea su propósito explícito | *(Sin antipatrón específico)* | — |
| [0x2003h](0x2003h.md) | Todas las funciones deben incluir documentación completa y estructurada | *(Sin antipatrón específico)* | — |
| [0x2004h](0x2004h.md) | No se permite el uso de variables globales | *(Sin antipatrón específico)* | — |
| [0x2005h](0x2005h.md) | Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única) | *(Sin antipatrón específico)* | — |
| [0x2006h](0x2006h.md) | Una aserción por cada función de prueba | *(Sin antipatrón específico)* | — |
| [0x2007h](0x2007h.md) | Mantené el alcance de las variables al mínimo posible | [Variable local declarada pero no utilizada](ap_0x2007h.md) | `AP-0x2007h` |
| [0x2008h](0x2008h.md) | Los valores de retorno numéricos deben definirse como constantes de preprocesador o enums | *(Sin antipatrón específico)* | — |
| [0x2009h](0x2009h.md) | Los ejercicios deben ser resueltos mediante funciones | [Llamada recursiva sin caso base explícito](ap_0x2009h.md) | `AP-0x2009h` |
| [0x200Ah](0x200Ah.md) | Los nombres de funciones y procedimientos deben usar snake_case en minúsculas | *(Sin antipatrón específico)* | — |
| [0x200Bh](0x200Bh.md) | Modularización: una función no debe exceder 4 parámetros de entrada | [Función con excesiva cantidad de parámetros (> 5)](ap_0x200Bh.md) | `AP-0x200Bh` |
| [0x200Ch](0x200Ch.md) | Prohibición de retornar la dirección de una variable local de stack | *(Sin antipatrón específico)* | — |
| [0x200Dh](0x200Dh.md) | Cada función debe tener a lo sumo un return | *(Sin antipatrón específico)* | — |
| [0x200Eh](0x200Eh.md) | Comentarios de cierre explicativos en bloques de control extensos (> 25 líneas) | *(Sin antipatrón específico)* | — |
| [0x200Fh](0x200Fh.md) | Uso obligatorio de 'void' explícito en funciones sin parámetros | *(Sin antipatrón específico)* | — |
| [0x2010h](0x2010h.md) | Prohibición de paréntesis superfluos en sentencia return | *(Sin antipatrón específico)* | — |
| [0x2011h](0x2011h.md) | Prohibición de reasignar o modificar parámetros recibidos por valor dentro de la función | [Recursión mutua o cíclica sin caso base](ap_0x2011h.md) | `AP-0x2011h` |
| [0x2012h](0x2012h.md) | Prohibición de asignaciones múltiples a una variable sin lectura intermedia (dead store) | [Comparador de qsort con resta directa sujeta a overflow](ap_0x2012h.md) | `AP-0x2012h` |
| [0x2013h](0x2013h.md) | Tipo de retorno obligatorio 'int' en la función main() | [Descarte del valor retornado por funciones de conversión numérica](ap_0x2013h.md) | `AP-0x2013h` |
| [0x2016h](0x2016h.md) | Detector de bloques else superfluos tras sentencias terminales | *(Sin antipatrón específico)* | — |
