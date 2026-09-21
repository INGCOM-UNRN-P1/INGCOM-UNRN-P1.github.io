---
title: "Nomenclatura e identificadores (0x01XX)"
short_title: "Nomenclatura"
subtitle: "Reglas de nombrado de identificadores, constantes, archivos y simbolos."
---

# Nomenclatura e identificadores (0x01XX)

Reglas de nombrado de identificadores, constantes, archivos y simbolos.

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x0101h](0x0101h.md) | Los identificadores deben ser descriptivos | — |
| [0x0102h](0x0102h.md) | Los argumentos de función y las variables locales deben usar snake_case en minúsculas | — |
| [0x0103h](0x0103h.md) | Las constantes (const o #define) deben nombrarse en MAYUSCULAS_SNAKE_CASE | — |
| [0x0104h](0x0104h.md) | Los nombres de los archivos deben usar snake_case en minúsculas (sin espacios) | — |
| [0x0105h](0x0105h.md) | Los nombres de funciones deben usar snake_case estricto en minúsculas | — |
| [0x0106h](0x0106h.md) | Las variables globales deben ser declaradas como static o usar prefijo g_ | — |
| [0x0107h](0x0107h.md) | Las macros #define deben nombrarse en MAYUSCULAS_SNAKE_CASE | — |
| [0x0108h](0x0108h.md) | Prohibición de identificadores con caracteres no ASCII (acentos, ñ) | — |
| [0x0109h](0x0109h.md) | Prohibición de identificadores que colisionen con palabras clave o tipos estándar | — |
| [0x010Ah](0x010Ah.md) | Prohibición de identificadores con prefijos reservados para el compilador (__ o _[A-Z]) | — |
| [0x010Bh](0x010Bh.md) | Proporcionalidad en longitud de identificadores según su alcance | — |
| [0x010Ch](0x010Ch.md) | Auditor de identificadores reservados con doble guion bajo o guion bajo inicial | — |
| [0x010Dh](0x010Dh.md) | Auditor de consistencia en nombres de constantes simbólicas | — |
| [0x010Eh](0x010Eh.md) | Prescindí de identificadores genéricos con sufijo numérico o afijos (numero1, num_1, n_a, a_n) | — |
| [0x010Fh](0x010Fh.md) | Prohibición de constantes numéricas mágicas en índices de arreglos | — |
| [0x0110h](0x0110h.md) | Los booleanos se nombran con prefijo interrogativo | — |
| [0x0111h](0x0111h.md) | Nombrá en positivo y evitá las dobles negaciones | — |
| [0x0112h](0x0112h.md) | Usá constantes simbólicas para todo literal con significado | — |
