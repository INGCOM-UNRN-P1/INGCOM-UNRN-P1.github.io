---
title: "Reglas de Estilo y Antipatrones de Cátedra"
short_title: "Índice de Reglas"
subtitle: "Catálogo unificado de reglas de estilo, buenas prácticas y errores frecuentes en C11"
---

(reglas-estilo-indice)=
# Reglas de Estilo y Antipatrones de Cátedra

El catálogo unificado de la materia reúne **175 reglas** agrupadas en **11 categorías**.
Cada regla integra en una única ficha su enunciado normativo, su fundamentación,
sus ejemplos exhaustivos y los **antipatrones didácticos** que la violan.

Los antipatrones ya no tienen código propio: se identifican por el código de la regla
que los norman. El registro de la renumeración está en
[`renumeracion.md`](renumeracion.md) y [`renumeracion.json`](renumeracion.json).

```{tableofcontents}
```

## Categorías

- **[Sintaxis y formato visual (0x00XX)](00_formato/index.md)** — 23 reglas. Reglas de estilo visual, espaciado, indentacion, llaves y formato en C.
- **[Nomenclatura e identificadores (0x01XX)](01_nomenclatura/index.md)** — 18 reglas. Reglas de nombrado de identificadores, constantes, archivos y simbolos.
- **[Comentarios, documentacion y organizacion de archivos (0x02XX)](02_documentacion/index.md)** — 6 reglas. Reglas de comentarios, documentacion de archivos y organizacion del codigo.
- **[Estructuras de control y flujo (0x10XX)](10_control/index.md)** — 24 reglas. Reglas sobre condicionales, lazos, bifurcaciones y flujo de ejecucion.
- **[Funciones, contratos y modularizacion (0x20XX)](20_funciones/index.md)** — 24 reglas. Reglas sobre firmas, contratos, responsabilidad unica y modularizacion.
- **[Memoria, punteros y tipos (0x30XX)](30_memoria/index.md)** — 31 reglas. Reglas sobre punteros, memoria dinamica, tipos, const y TADs.
- **[Archivos y E/S (0x40XX)](40_archivos/index.md)** — 12 reglas. Reglas sobre flujos de archivo, lectura/escritura y reporte de errores.
- **[Compilacion, preprocesador y seguridad (0x50XX)](50_seguridad/index.md)** — 21 reglas. Reglas sobre compilacion, preprocesador, cabeceras y seguridad estatica.
- **[Proceso, diseno y construccion sistematica (0x60XX)](60_proceso/index.md)** — 5 reglas. Reglas de metodo: como disenar y construir codigo de calidad paso a paso.
- **[Robustez y manejo de errores (0x70XX)](70_robustez/index.md)** — 7 reglas. Reglas de robustez, validacion e inicializacion defensiva.
- **[Verificacion, testing y depuracion (0x80XX)](80_verificacion/index.md)** — 4 reglas. Reglas de verificacion, testing y depuracion antes de la entrega.

## Categorías y prefijos de código

| Prefijo | Categoría | Directorio | Reglas |
| :--- | :--- | :--- | :--- |
| `0x00XX` | Sintaxis y formato visual | `reglas/00_formato/` | 23 |
| `0x01XX` | Nomenclatura e identificadores | `reglas/01_nomenclatura/` | 18 |
| `0x02XX` | Comentarios, documentacion y organizacion de archivos | `reglas/02_documentacion/` | 6 |
| `0x10XX` | Estructuras de control y flujo | `reglas/10_control/` | 24 |
| `0x20XX` | Funciones, contratos y modularizacion | `reglas/20_funciones/` | 24 |
| `0x30XX` | Memoria, punteros y tipos | `reglas/30_memoria/` | 31 |
| `0x40XX` | Archivos y E/S | `reglas/40_archivos/` | 12 |
| `0x50XX` | Compilacion, preprocesador y seguridad | `reglas/50_seguridad/` | 21 |
| `0x60XX` | Proceso, diseno y construccion sistematica | `reglas/60_proceso/` | 5 |
| `0x70XX` | Robustez y manejo de errores | `reglas/70_robustez/` | 7 |
| `0x80XX` | Verificacion, testing y depuracion | `reglas/80_verificacion/` | 4 |
