---
title: "Antipatrones de E/S y Gestión de Archivos"
short_title: "Entrada y Salida"
subtitle: "Control de fin de archivo erróneo, desajustes de especificadores de formato, fflush sobre stdin y fugas de FILE*."
---

# Antipatrones de E/S y Gestión de Archivos

Control de fin de archivo erróneo, desajustes de especificadores de formato, fflush sobre stdin y fugas de FILE*.

```{tableofcontents}
```

## Antipatrones Catalogados

| Código | Título |
| :--- | :--- |
| [AP002](ap002_4002.md) | Control de lectura con while(!feof()) |
| [AP007](ap007_4006.md) | Uso de fflush(stdin) para limpiar buffer |
| [AP025](ap025_4008.md) | Desajuste de especificadores de formato en printf/scanf |
| [AP032](ap032_4009.md) | Retorno prematuro con fuga de recursos de archivo |
| [AP049](ap049_400A.md) | Lectura de cadenas con scanf() sin límite de ancho en buffer fijo |
| [AP059](ap059_400B.md) | Omisión de verificación de retorno NULL en fopen() |
