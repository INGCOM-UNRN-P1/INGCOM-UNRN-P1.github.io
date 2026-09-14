---
title: "Funciones y Modularización (0x20XX)"
short_title: "Funciones y Modularización"
subtitle: "Reglas para diseño de interfaces, firmas, contratos, modularidad y alcance de variables."
---

(2_funciones)=
# Funciones y Modularización (0x20XX)

Reglas para diseño de interfaces, firmas, contratos, modularidad y alcance de variables.

```{tableofcontents}
```

## Reglas de esta Categoría

| Código | Regla |
| :--- | :--- |
| [0x2001h](2_funciones/0x2001h.md) | Las funciones deben usar cláusulas de guarda y retornos anticipados para reducir la anidación profunda |
| [0x2002h](2_funciones/0x2002h.md) | Las funciones no deben contener printf o scanf, a menos que ese sea su propósito explícito |
| [0x2003h](2_funciones/0x2003h.md) | Todas las funciones deben incluir documentación completa y estructurada |
| [0x2004h](2_funciones/0x2004h.md) | No se permite el uso de variables globales |
| [0x2005h](2_funciones/0x2005h.md) | Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única) |
| [0x2006h](2_funciones/0x2006h.md) | Una aserción por cada función de prueba |
| [0x2007h](2_funciones/0x2007h.md) | Mantené el alcance de las variables al mínimo posible |
| [0x2008h](2_funciones/0x2008h.md) | Los valores de retorno numéricos deben definirse como constantes de preprocesador o enums |
| [0x2009h](2_funciones/0x2009h.md) | Los ejercicios deben ser resueltos mediante funciones |
| [0x200Ah](2_funciones/0x200Ah.md) | Los nombres de funciones y procedimientos deben usar snake_case en minúsculas |
| [0x200Bh](2_funciones/0x200Bh.md) | Modularización: una función no debe exceder 4 parámetros de entrada |
| [0x200Ch](2_funciones/0x200Ch.md) | Prohibición de retornar la dirección de una variable local de stack |
| [0x200Dh](2_funciones/0x200Dh.md) | Cada función debe tener a lo sumo un return |
| [0x200Eh](2_funciones/0x200Eh.md) | Comentarios de cierre explicativos en bloques de control extensos (> 25 líneas) |
| [0x200Fh](2_funciones/0x200Fh.md) | Uso obligatorio de 'void' explícito en funciones sin parámetros |
| [0x2010h](2_funciones/0x2010h.md) | Prohibición de paréntesis superfluos en sentencia return |
| [0x2011h](2_funciones/0x2011h.md) | Prohibición de reasignar o modificar parámetros recibidos por valor dentro de la función |
| [0x2012h](2_funciones/0x2012h.md) | Prohibición de asignaciones múltiples a una variable sin lectura intermedia (dead store) |
| [0x2013h](2_funciones/0x2013h.md) | Tipo de retorno obligatorio 'int' en la función main() |
| [0x2016h](2_funciones/0x2016h.md) | Detector de bloques else superfluos tras sentencias terminales |
