---
title: "Punteros y Gestión de Memoria (0x30XX)"
short_title: "Punteros y Memoria"
subtitle: "Reglas y antipatrones para manipulación de punteros, memoria dinámica, punteros opacos y heap."
---

# Punteros y Gestión de Memoria (0x30XX)

Reglas y antipatrones para manipulación de punteros, memoria dinámica, punteros opacos y heap.

```{tableofcontents}
```

## Tabla Comparativa: Regla de Estilo ↔ Antipatrón Didáctico

La tabla siguiente unifica las directivas prescriptivas de estilo y los antipatrones detectados:

| Regla de Estilo | Título de la Norma | Antipatrón Didáctico | Código Antipatrón |
| :--- | :--- | :--- | :--- |
| [0x0035h](0x0035h.md) | Diseñá los Tipos de Datos Abstractos utilizando punteros opacos | *(Sin antipatrón específico)* | — |
| [0x0036h](0x0036h.md) | Asigná NULL al puntero tras liberar un recurso opaco en el ámbito del cliente | *(Sin antipatrón específico)* | — |
| [0x3001h](0x3001h.md) | Siempre verificá la asignación exitosa de memoria dinámica | [Uso de memoria dinámica sin validar retorno a NULL](ap_0x3001h.md) | `AP-0x3001h` |
| | | [Desreferencia inmediata tras realloc](ap_0x301Bh.md) | `AP-0x301Bh` |
| | | [Asignación de retorno de malloc() a variable no puntero](ap_0x301Fh.md) | `AP-0x301Fh` |
| | | [Comprobación de puntero nulo posterior a su desreferencia](ap_0x3023h.md) | `AP-0x3023h` |
| | | [Asignación múltiple a malloc en bucle sin liberación ante fallos parciales](ap_0x3024h.md) | `AP-0x3024h` |
| | | [Desreferencia condicional de puntero local sin inicializar](ap_0x3026h.md) | `AP-0x3026h` |
| | | [Desreferencia directa tras retorno de realloc sin asignación temporal](ap_0x3029h.md) | `AP-0x3029h` |
| [0x3002h](0x3002h.md) | Liberá siempre la memoria dinámica y asigná NULL al puntero para mitigar punteros colgantes | [Retorno de puntero a variable local (Dangling Stack Pointer)](ap_0x3002h.md) | `AP-0x3002h` |
| | | [Puntero colgante sin asignar NULL tras free()](ap_0x3002b.md) | `AP-0x3002b` |
| | | [Invocación a free() sobre memoria estática o variables automáticas de pila](ap_0x3021h.md) | `AP-0x3021h` |
| | | [Asignación de punteros a arreglos locales en parámetros de salida](ap_0x3022h.md) | `AP-0x3022h` |
| | | [Modificación directa del puntero base asignado por malloc()](ap_0x3025h.md) | `AP-0x3025h` |
| [0x3003h](0x3003h.md) | No mezcles operaciones de asignación y comparación en una sola línea | *(Sin antipatrón específico)* | — |
| [0x3004h](0x3004h.md) | Utilizá typedef para definir tipos de estructuras con el sufijo _t | *(Sin antipatrón específico)* | — |
| [0x3005h](0x3005h.md) | Minimizá el uso de múltiples niveles de indirección (punteros a punteros) | *(Sin antipatrón específico)* | — |
| [0x3006h](0x3006h.md) | Documentá la propiedad de los recursos al utilizar punteros | *(Sin antipatrón específico)* | — |
| [0x3007h](0x3007h.md) | Los argumentos de tipo puntero deben ser const siempre que la función no los modifique | *(Sin antipatrón específico)* | — |
| [0x3008h](0x3008h.md) | Los punteros nulos deben ser inicializados y comparados con NULL, no con 0 | [Chequeo innecesario antes de free()](ap_0x3008h.md) | `AP-0x3008h` |
| | | [Comparación sintáctica errónea de puntero con carácter nulo '\0'](ap_0x301Dh.md) | `AP-0x301Dh` |
| [0x3009h](0x3009h.md) | Documentá explícitamente los casos en que una función puede retornar NULL | *(Sin antipatrón específico)* | — |
| [0x300Ah](0x300Ah.md) | Utilizá cast explícito al convertir tipos de punteros | [Casteo redundante de malloc()](ap_0x300Ah.md) | `AP-0x300Ah` |
| | | [Casteo redundante en invocación de free()](ap_0x301Ch.md) | `AP-0x301Ch` |
| | | [Casteo forzado entre punteros de tipos incompatibles (Violación de Strict Aliasing)](ap_0x3020h.md) | `AP-0x3020h` |
| | | [Casteo de retorno de malloc() con omisión de include stdlib.h](ap_0x3028h.md) | `AP-0x3028h` |
| | | [Casteo forzado de tipos numéricos o literales enteros a punteros](ap_0x302Ah.md) | `AP-0x302Ah` |
| [0x300Bh](0x300Bh.md) | Usá siempre sizeof en las asignaciones de memoria dinámica, prefiriendo sizeof(*ptr) | [Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo](ap_0x301Eh.md) | `AP-0x301Eh` |
| | | [Cálculo erróneo de tamaño para struct dinámico con miembro flexible](ap_0x3027h.md) | `AP-0x3027h` |
| [0x300Ch](0x300Ch.md) | Verificá siempre los límites de los arreglos antes de acceder a sus elementos | *(Sin antipatrón específico)* | — |
| [0x300Dh](0x300Dh.md) | Utilizá enum en lugar de "números mágicos" para conjuntos de estados y valores constantes | [Número mágico literal en condición lógica](ap_0x300Dh.md) | `AP-0x300Dh` |
| [0x300Eh](0x300Eh.md) | Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos | *(Sin antipatrón específico)* | — |
| [0x300Fh](0x300Fh.md) | Liberá la memoria en el orden inverso a su asignación | [Uso de sizeof(puntero) en reserva dinámica](ap_0x300Fh.md) | `AP-0x300Fh` |
| [0x3010h](0x3010h.md) | Las variables que representan tamaños o índices de arreglos deben ser de tipo size_t | *(Sin antipatrón específico)* | — |
| [0x3011h](0x3011h.md) | Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar const void* | *(Sin antipatrón específico)* | — |
| [0x3012h](0x3012h.md) | Prohibición de aritmética de punteros sobre void* | *(Sin antipatrón específico)* | — |
| [0x3013h](0x3013h.md) | Asignación de memoria con sizeof sobre puntero en lugar del tipo apuntado | *(Sin antipatrón específico)* | — |
| [0x3014h](0x3014h.md) | Prohibición de doble liberación de memoria (double free) sobre el mismo puntero | *(Sin antipatrón específico)* | — |
| [0x3015h](0x3015h.md) | Reallocación segura: no sobreescribir el puntero original directamente | [Sobreescritura directa de puntero en realloc](ap_0x3015h.md) | `AP-0x3015h` |
| [0x3016h](0x3016h.md) | Orden incorrecto o sospechoso de argumentos en llamadas a memset | *(Sin antipatrón específico)* | — |
| [0x3017h](0x3017h.md) | Orden canónico de calificadores: 'const tipo' en lugar de 'tipo const' | *(Sin antipatrón específico)* | — |
| [0x3018h](0x3018h.md) | Inicialización idiomática de agregados con {0} en lugar de memset inmediato | *(Sin antipatrón específico)* | — |
| [0x3019h](0x3019h.md) | Prohibición de comparar punteros contra constantes numéricas distintas de NULL o cero | [Pointer decay en sizeof de arreglo parámetro](ap_0x3019h.md) | `AP-0x3019h` |
| [0x301Ah](0x301Ah.md) | Validador de uso idiomático de tipos booleanos estándar | [Tamaño insuficiente en memset con sizeof(ptr)](ap_0x301Ah.md) | `AP-0x301Ah` |
