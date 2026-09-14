---
title: "Antipatrones de Buenas Prácticas y Preprocesador"
short_title: "Buenas Prácticas"
subtitle: "Macros ofuscadas, números mágicos no documentados, divisiones enteras silenciosas y variables no inicializadas."
---

# Antipatrones de Buenas Prácticas y Preprocesador

Macros ofuscadas, números mágicos no documentados, divisiones enteras silenciosas y variables no inicializadas.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [AP013](ap013_5004.md) | Uso de funciones inseguras de manipulación de cadenas (strcpy/sprintf) |
| [AP017](ap017_500A.md) | Macro con argumentos evaluados múltiples veces |
| [AP019](ap019_5008.md) | Invocación de la función prohibida gets() |
| [AP020](ap020_5004.md) | Comparación directa de cadenas con == o != |
| [AP022](ap022_0003.md) | Declaración de variable mezclada tras sentencias ejecutables |
| [AP028](ap028_5009.md) | División entera silenciosa asignada a flotante |
| [AP030](ap030_0004.md) | Lectura de variable local no inicializada |
| [AP034](ap034_0039.md) | Macro que ofusca sintaxis fundamental de C |
| [AP054](ap054_500B.md) | Redefinición de identificadores de funciones estándar de la biblioteca C |
