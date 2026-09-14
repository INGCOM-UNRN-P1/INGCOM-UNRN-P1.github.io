---
title: "Antipatrones de Funciones y Alcance"
short_title: "Funciones y Alcance"
subtitle: "Vicios de modularización, exceso de parámetros, variables locales muertas y recursión infinita."
---

# Antipatrones de Funciones y Alcance

Vicios de modularización, exceso de parámetros, variables locales muertas y recursión infinita.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [AP012](ap012_2007.md) | Variable local declarada pero no utilizada |
| [AP015](ap015_200B.md) | Función con excesiva cantidad de parámetros (> 5) |
| [AP018](ap018_2009.md) | Llamada recursiva sin caso base explícito |
| [AP033](ap033_2011.md) | Recursión mutua o cíclica sin caso base |
| [AP035](ap035_2012.md) | Comparador de qsort con resta directa sujeta a overflow |
| [AP051](ap051_2013.md) | Descarte del valor retornado por funciones de conversión numérica |
