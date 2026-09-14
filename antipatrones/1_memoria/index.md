---
title: "Antipatrones de Memoria y Punteros"
short_title: "Memoria y Punteros"
subtitle: "Prácticas defectuosas en alocación en el heap, punteros colgantes, fugas de memoria y casteo de tipos."
---

# Antipatrones de Memoria y Punteros

Prácticas defectuosas en alocación en el heap, punteros colgantes, fugas de memoria y casteo de tipos.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [AP001](ap001_300A.md) | Casteo redundante de malloc() |
| [AP003](ap003_3002.md) | Retorno de puntero a variable local (Dangling Stack Pointer) |
| [AP004](ap004_3008.md) | Chequeo innecesario antes de free() |
| [AP008](ap008_300F.md) | Uso de sizeof(puntero) en reserva dinámica |
| [AP010](ap010_3001.md) | Uso de memoria dinámica sin validar retorno a NULL |
| [AP011](ap011_3002.md) | Puntero colgante sin asignar NULL tras free() |
| [AP014](ap014_300D.md) | Número mágico literal en condición lógica |
| [AP024](ap024_3015.md) | Sobreescritura directa de puntero en realloc |
| [AP026](ap026_3019.md) | Pointer decay en sizeof de arreglo parámetro |
| [AP036](ap036_301A.md) | Tamaño insuficiente en memset con sizeof(ptr) |
| [AP037](ap037_301B.md) | Desreferencia inmediata tras realloc |
| [AP038](ap038_301C.md) | Casteo redundante en invocación de free() |
| [AP041](ap041_301D.md) | Comparación sintáctica errónea de puntero con carácter nulo '\0' |
| [AP042](ap042_301E.md) | Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo |
| [AP046](ap046_301F.md) | Asignación de retorno de malloc() a variable no puntero |
| [AP047](ap047_3020.md) | Casteo forzado entre punteros de tipos incompatibles (Violación de Strict Aliasing) |
| [AP053](ap053_3021.md) | Invocación a free() sobre memoria estática o variables automáticas de pila |
| [AP055](ap055_3022.md) | Asignación de punteros a arreglos locales en parámetros de salida |
| [AP056](ap056_3023.md) | Comprobación de puntero nulo posterior a su desreferencia |
| [AP057](ap057_3024.md) | Asignación múltiple a malloc en bucle sin liberación ante fallos parciales |
| [AP058](ap058_3025.md) | Modificación directa del puntero base asignado por malloc() |
| [AP060](ap060_3026.md) | Desreferencia condicional de puntero local sin inicializar |
| [AP061](ap061_3027.md) | Cálculo erróneo de tamaño para struct dinámico con miembro flexible |
| [AP063](ap063_3028.md) | Casteo de retorno de malloc() con omisión de include stdlib.h |
| [AP070](ap070_3029.md) | Desreferencia directa tras retorno de realloc sin asignación temporal |
| [AP073](ap073_302A.md) | Casteo forzado de tipos numéricos o literales enteros a punteros |
