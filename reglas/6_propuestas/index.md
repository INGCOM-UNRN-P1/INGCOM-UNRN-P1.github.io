---
title: "Propuestas: Disciplina de Construcción Sistemática (0x60XX)"
short_title: "Propuestas de nuevas reglas"
subtitle: "Conjunto de reglas propuestas para que un principiante construya código de alta calidad de forma metódica"
---

(reglas-propuestas-0x60xx)=
# Propuestas: Disciplina de Construcción Sistemática (0x60XX)

Este directorio reúne **reglas propuestas** para ampliar el catálogo de
cátedra. A diferencia de las categorías `0x00XX`–`0x50XX`, que prescriben
*formas* concretas del código, el eje `0x60XX` prescribe **el método de
trabajo**: la secuencia de decisiones que lleva a un principiante desde el
enunciado hasta una entrega correcta, legible y verificable.

La premisa es simple: un estudiante no escribe código de calidad por
inspiración, sino por **hábito sistemático**. Estas reglas ordenan ese hábito
en cuatro momentos.

## Cómo leer estas propuestas

Cada ficha sigue el formato editorial completo del catálogo (enunciado
normativo, fundamentación, ejemplos exhaustivos, casos límite, detección y
checklist). Las reglas se numeran `0x6001h`–`0x6018h` y son **complementarias**
de las ya vigentes: no las reemplazan, las ponen en secuencia.

```{tableofcontents}
```

## Cuadro general de propuestas

| Regla | Título | Momento | Regla vigente que amplía |
| :--- | :--- | :--- | :--- |
| [0x6001h](0x6001h.md) | Diseñá el algoritmo antes de escribir código en C | Diseño | {ref}`0x0000h` |
| [0x6002h](0x6002h.md) | Compilá con frecuencia y resolvé el primer error antes de continuar | Diseño | {ref}`0x5002h` |
| [0x6003h](0x6003h.md) | Cada función debe caber en una sola idea y en 25 líneas | Diseño | {ref}`0x2005h` |
| [0x6004h](0x6004h.md) | Limitá la profundidad de anidación a tres niveles | Diseño | {ref}`0x2001h` |
| [0x6005h](0x6005h.md) | Declará cada variable lo más cerca posible de su primer uso | Diseño | {ref}`0x2007h` |
| [0x6006h](0x6006h.md) | No reutilices una variable para propósitos distintos | Diseño | {ref}`0x0001h` |
| [0x6007h](0x6007h.md) | No dupliques lógica: extraé una función | Diseño | {ref}`0x2009h` |
| [0x6008h](0x6008h.md) | Escribí el contrato de la función antes de implementarla | Diseño | {ref}`0x2003h` |
| [0x6009h](0x6009h.md) | Los booleanos se nombran con prefijo interrogativo | Legibilidad | {ref}`0x0001h` |
| [0x600Ah](0x600Ah.md) | Nombrá en positivo y evitá las dobles negaciones | Legibilidad | {ref}`0x0001h` |
| [0x600Bh](0x600Bh.md) | Usá constantes simbólicas para todo literal con significado | Legibilidad | {ref}`0x500Ah` |
| [0x600Ch](0x600Ch.md) | Documentá el invariante de cada lazo | Legibilidad | {ref}`0x1003h` |
| [0x600Dh](0x600Dh.md) | Escribí condiciones afirmativas y directas | Legibilidad | {ref}`0x1004h` |
| [0x600Eh](0x600Eh.md) | Agrupá sentencias relacionadas y separá bloques lógicos | Legibilidad | {ref}`0x0000h` |
| [0x600Fh](0x600Fh.md) | No optimices prematuramente | Legibilidad | {ref}`0x0000h` |
| [0x6010h](0x6010h.md) | Validá los datos en la frontera del programa | Robustez | {ref}`0x300Ch` |
| [0x6011h](0x6011h.md) | No ignores valores de retorno que pueden indicar fallo | Robustez | {ref}`0x4002h` |
| [0x6012h](0x6012h.md) | No llamés exit() en funciones de biblioteca: propagá el error | Robustez | {ref}`0x4003h` |
| [0x6013h](0x6013h.md) | Inicializá todos los campos de estructuras y arreglos | Robustez | {ref}`0x0003h` |
| [0x6014h](0x6014h.md) | Probá explícitamente los casos borde | Robustez | {ref}`0x6008h` |
| [0x6015h](0x6015h.md) | Evitá los parámetros bandera de tipo bool | Robustez | {ref}`0x1005h` |
| [0x6016h](0x6016h.md) | Escribí al menos una prueba por cláusula del contrato | Verificación | {ref}`0x2006h` |
| [0x6017h](0x6017h.md) | Verificá con gcc, gdb y valgrind antes de entregar | Verificación | {ref}`0x5002h` |
| [0x6018h](0x6018h.md) | Ejecutá la lista de verificación de calidad antes de entregar | Verificación | — |

## Justificación de la propuesta

Las categorías vigentes responden a la pregunta *«¿cómo debe verse el
código?»*. El eje `0x60XX` responde a *«¿en qué orden y con qué controles un
principiante llega a ese código?»*. Ambas dimensiones son necesarias:

- Sin reglas de forma (`0x00XX`–`0x50XX`), el método no tiene destino.
- Sin reglas de método (`0x60XX`), la forma se aplica tarde, de memoria y sin
  comprensión, y el estudiante la abandona en cuanto el problema se complica.

La secuencia recomendada de aplicación es **diseñar → escribir legible →
hacer robusto → verificar**, que es exactamente el orden en que se presentan
las propuestas.

:::{note} Estado de estas reglas
Estas fichas son **propuestas** y no están instrumentadas todavía en `gaff`.
Cuando se aprueben, deberían migrar a una categoría definitiva con códigos
propios y verificadores automáticos donde sea posible.
:::
