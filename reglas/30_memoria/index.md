---
title: "Memoria, punteros y tipos (0x30XX)"
short_title: "Memoria y punteros"
subtitle: "Reglas sobre punteros, memoria dinamica, tipos, const y TADs."
---

# Memoria, punteros y tipos (0x30XX)

Reglas sobre punteros, memoria dinamica, tipos, const y TADs.

```{tableofcontents}
```

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x3001h](0x3001h.md) | Siempre verificá la asignación exitosa de memoria dinámica | `AP-0x3001h`, `AP-0x301Bh`, `AP-0x301Fh`, `AP-0x3023h`, `AP-0x3024h`, `AP-0x3026h`, `AP-0x3029h` |
| [0x3002h](0x3002h.md) | Liberá siempre la memoria dinámica y asigná NULL al puntero para mitigar punteros colgantes | `AP-0x3002b`, `AP-0x3002h`, `AP-0x3021h`, `AP-0x3022h`, `AP-0x3025h` |
| [0x3003h](0x3003h.md) | No mezcles operaciones de asignación y comparación en una sola línea | — |
| [0x3004h](0x3004h.md) | Utilizá typedef para definir tipos de estructuras con el sufijo _t | — |
| [0x3005h](0x3005h.md) | Minimizá el uso de múltiples niveles de indirección (punteros a punteros) | — |
| [0x3006h](0x3006h.md) | Documentá la propiedad de los recursos al utilizar punteros | — |
| [0x3007h](0x3007h.md) | Los argumentos de tipo puntero deben ser const siempre que la función no los modifique | — |
| [0x3008h](0x3008h.md) | Los punteros nulos deben ser inicializados y comparados con NULL, no con 0 | `AP-0x3008h`, `AP-0x301Dh` |
| [0x3009h](0x3009h.md) | Documentá explícitamente los casos en que una función puede retornar NULL | — |
| [0x300Ah](0x300Ah.md) | Utilizá cast explícito al convertir tipos de punteros | `AP-0x300Ah`, `AP-0x301Ch`, `AP-0x3020h`, `AP-0x3028h`, `AP-0x302Ah` |
| [0x300Bh](0x300Bh.md) | Usá siempre sizeof en las asignaciones de memoria dinámica, prefiriendo sizeof(*ptr) | `AP-0x3019h`, `AP-0x301Eh`, `AP-0x3027h` |
| [0x300Ch](0x300Ch.md) | Verificá siempre los límites de los arreglos antes de acceder a sus elementos | — |
| [0x300Dh](0x300Dh.md) | Utilizá enum en lugar de 'números mágicos' para conjuntos de estados y valores constantes | `AP-0x300Dh` |
| [0x300Eh](0x300Eh.md) | Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos | — |
| [0x300Fh](0x300Fh.md) | Liberá la memoria en el orden inverso a su asignación | — |
| [0x3010h](0x3010h.md) | Las variables que representan tamaños o índices de arreglos deben ser de tipo size_t | — |
| [0x3011h](0x3011h.md) | Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar const void* | — |
| [0x3012h](0x3012h.md) | Prohibición de aritmética de punteros sobre void* | — |
| [0x3013h](0x3013h.md) | Asignación de memoria con sizeof sobre puntero en lugar del tipo apuntado | `AP-0x300Fh` |
| [0x3014h](0x3014h.md) | Prohibición de doble liberación de memoria (double free) sobre el mismo puntero | — |
| [0x3015h](0x3015h.md) | Reallocación segura: no sobreescribir el puntero original directamente | `AP-0x3015h` |
| [0x3016h](0x3016h.md) | Orden incorrecto o sospechoso de argumentos en llamadas a memset | `AP-0x301Ah` |
| [0x3017h](0x3017h.md) | Orden canónico de calificadores: 'const tipo' en lugar de 'tipo const' | — |
| [0x3018h](0x3018h.md) | Inicialización idiomática de agregados con {0} en lugar de memset inmediato | — |
| [0x3019h](0x3019h.md) | Prohibición de comparar punteros contra constantes numéricas distintas de NULL o cero | — |
| [0x301Ah](0x301Ah.md) | Validador de uso idiomático de tipos booleanos estándar | — |
| [0x301Bh](0x301Bh.md) | Prohibición de casts de tipo innecesarios o redundantes | — |
| [0x301Ch](0x301Ch.md) | Detector de variables locales no inicializadas con modificador const | — |
| [0x301Dh](0x301Dh.md) | Diseñá los Tipos de Datos Abstractos utilizando punteros opacos | — |
| [0x301Eh](0x301Eh.md) | Asigná NULL al puntero tras liberar un recurso opaco en el ámbito del cliente | — |
| [0x301Fh](0x301Fh.md) | No compares numeros de punto flotante con igualdad exacta | *(regla promovida de antipatrón)* |
