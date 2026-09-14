---
title: "Funciones, contratos y modularizacion (0x20XX)"
short_title: "Funciones y modularizacion"
subtitle: "Reglas sobre firmas, contratos, responsabilidad unica y modularizacion."
---

# Funciones, contratos y modularizacion (0x20XX)

Reglas sobre firmas, contratos, responsabilidad unica y modularizacion.

```{tableofcontents}
```

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x2001h](0x2001h.md) | Las funciones deben usar cláusulas de guarda y retornos anticipados para reducir la anidación profunda | — |
| [0x2002h](0x2002h.md) | Las funciones no deben contener printf o scanf, a menos que ese sea su propósito explícito | — |
| [0x2003h](0x2003h.md) | Todas las funciones deben incluir documentación completa y estructurada | — |
| [0x2004h](0x2004h.md) | No se permite el uso de variables globales | — |
| [0x2005h](0x2005h.md) | Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única) | — |
| [0x2006h](0x2006h.md) | Mantené el alcance de las variables al mínimo posible | `AP-0x2007h` |
| [0x2007h](0x2007h.md) | Los valores de retorno numéricos deben definirse como constantes de preprocesador o enums | — |
| [0x2008h](0x2008h.md) | Los ejercicios deben ser resueltos mediante funciones | — |
| [0x2009h](0x2009h.md) | Los nombres de funciones y procedimientos deben usar snake_case en minúsculas | — |
| [0x200Ah](0x200Ah.md) | Modularización: una función no debe exceder 4 parámetros de entrada | `AP-0x200Bh` |
| [0x200Bh](0x200Bh.md) | Prohibición de retornar la dirección de una variable local de stack | — |
| [0x200Ch](0x200Ch.md) | Cada función debe tener a lo sumo un return | — |
| [0x200Dh](0x200Dh.md) | Comentarios de cierre explicativos en bloques de control extensos (> 25 líneas) | — |
| [0x200Eh](0x200Eh.md) | Uso obligatorio de 'void' explícito en funciones sin parámetros | — |
| [0x200Fh](0x200Fh.md) | Prohibición de paréntesis superfluos en sentencia return | — |
| [0x2010h](0x2010h.md) | Prohibición de reasignar o modificar parámetros recibidos por valor dentro de la función | — |
| [0x2011h](0x2011h.md) | Prohibición de asignaciones múltiples a una variable sin lectura intermedia (dead store) | — |
| [0x2012h](0x2012h.md) | Tipo de retorno obligatorio 'int' en la función main() | — |
| [0x2013h](0x2013h.md) | Detector de bloques else superfluos tras sentencias terminales | — |
| [0x2014h](0x2014h.md) | Cada función debe caber en una sola idea y en 25 líneas | — |
| [0x2015h](0x2015h.md) | No dupliques lógica: extraé una función | `AP-0x1017h` |
| [0x2016h](0x2016h.md) | Escribí el contrato de la función antes de implementarla | — |
| [0x2017h](0x2017h.md) | Toda funcion recursiva debe tener un caso base explicito | *(regla promovida de antipatrón)* |
| [0x2018h](0x2018h.md) | Los comparadores no deben usar resta sujeta a desbordamiento | *(regla promovida de antipatrón)* |
