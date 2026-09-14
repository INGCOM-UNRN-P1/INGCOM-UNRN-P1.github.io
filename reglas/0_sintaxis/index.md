---
title: "Sintaxis Básica y Nomenclatura (0x00XX)"
short_title: "Sintaxis y Nomenclatura"
subtitle: "Reglas de estilo visual, formato, espaciado, indentación y pautas de nombrado en C."
---

# Sintaxis Básica y Nomenclatura (0x00XX)

Reglas de estilo visual, formato, espaciado, indentación y pautas de nombrado en C.

```{tableofcontents}
```

## Catálogo de Reglas

| Regla | Descripción |
| :--- | :--- |
| [0x0000h](0x0000h.md) | La claridad y prolijidad son de máxima importancia |
| [0x0001h](0x0001h.md) | Los identificadores deben ser descriptivos |
| [0x0002h](0x0002h.md) | Una declaración de variable por línea |
| [0x0003h](0x0003h.md) | Siempre debés inicializar las variables a un valor conocido |
| [0x0004h](0x0004h.md) | Un espacio antes y después de cada operador binario |
| [0x0005h](0x0005h.md) | Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves |
| [0x0006h](0x0006h.md) | El asterisco de los punteros debe declararse junto al identificador |
| [0x0007h](0x0007h.md) | Los argumentos de función y las variables locales deben usar snake_case en minúsculas |
| [0x0008h](0x0008h.md) | Las constantes (const o #define) deben nombrarse en MAYUSCULAS_SNAKE_CASE |
| [0x0009h](0x0009h.md) | Las líneas de código no deben exceder los 79 caracteres |
| [0x000Ah](0x000Ah.md) | Escribí comentarios que expliquen el "porqué", no el "qué" |
| [0x000Bh](0x000Bh.md) | Las llaves deben ubicarse en líneas independientes según el estilo Allman |
| [0x000Ch](0x000Ch.md) | Los nombres de los archivos deben usar snake_case en minúsculas (sin espacios) |
| [0x000Dh](0x000Dh.md) | No dejes código comentado (dead code) en los archivos fuente |
| [0x000Eh](0x000Eh.md) | Los nombres de funciones deben usar snake_case estricto en minúsculas |
| [0x000Fh](0x000Fh.md) | Prescindí de comentarios obvios, redundantes o vacíos |
| [0x0010h](0x0010h.md) | Control de longitud máxima de archivos de código (máx 500 líneas) |
| [0x0011h](0x0011h.md) | En archivos .c la inclusión de la cabecera propia debe figurar en primer lugar |
| [0x0012h](0x0012h.md) | Las variables globales deben ser declaradas como static o usar prefijo g_ |
| [0x0013h](0x0013h.md) | Las macros #define deben nombrarse en MAYUSCULAS_SNAKE_CASE |
| [0x0014h](0x0014h.md) | Prohibición de identificadores con caracteres no ASCII (acentos, ñ) |
| [0x0015h](0x0015h.md) | Alineación vertical consistente en asignaciones y declaraciones consecutivas |
| [0x0016h](0x0016h.md) | Prohibición de identificadores que colisionen con palabras clave o tipos estándar |
| [0x0017h](0x0017h.md) | Espaciado consistente en declaraciones de doble puntero (tipo **var) |
| [0x0018h](0x0018h.md) | Prohibición de identificadores con prefijos reservados para el compilador (__ o _[A-Z]) |
| [0x0019h](0x0019h.md) | Prohibición de espacios en blanco antes de separadores de sintaxis (; y ,) |
| [0x001Ah](0x001Ah.md) | Prohibición de espacios en blanco alrededor de operadores de acceso a miembros (-> y .) |
| [0x001Bh](0x001Bh.md) | Prohibición de espacios en blanco entre operadores unarios (++, --, !) y su operando |
| [0x001Ch](0x001Ch.md) | Espacio en blanco obligatorio tras la coma separadora en listas y argumentos |
| [0x001Dh](0x001Dh.md) | Prohibición de espacios en blanco internos inmediatamente tras '(' o antes de ')' |
| [0x001Eh](0x001Eh.md) | Prohibición de múltiples espacios en blanco consecutivos dentro de una línea de código |
| [0x001Fh](0x001Fh.md) | Prohibición de llaves redundantes en inicialización de tipos escalares |
| [0x0020h](0x0020h.md) | Proporcionalidad en longitud de identificadores según su alcance |
| [0x0022h](0x0022h.md) | Validador de espaciado estricto en sentencias de control |
| [0x0023h](0x0023h.md) | Detector de variables locales no inicializadas con modificador const |
| [0x0025h](0x0025h.md) | Validador de formato canónico en firmas de punteros a función |
| [0x0026h](0x0026h.md) | Auditor de identificadores reservados con doble guion bajo o guion bajo inicial |
| [0x0027h](0x0027h.md) | Validador de presencia de cabecera de documentación obligatoria por archivo |
| [0x0028h](0x0028h.md) | Detector de etiquetas de salto goto no alineadas al margen izquierdo |
| [0x0029h](0x0029h.md) | Auditor de inicialización de arreglos unidimensionales con exceso de elementos |
| [0x002Bh](0x002Bh.md) | Validador de espaciado en listas de argumentos y llamadas a funciones |
| [0x002Ch](0x002Ch.md) | Auditor de consistencia en nombres de constantes simbólicas |
| [0x002Dh](0x002Dh.md) | Validador de espaciado en operadores unarios |
| [0x0037h](0x0037h.md) | Prescindí de identificadores genéricos con sufijo numérico o afijos (numero1, num_1, n_a, a_n) |
| [0x0038h](0x0038h.md) | Prohibición de constantes numéricas mágicas en índices de arreglos |
