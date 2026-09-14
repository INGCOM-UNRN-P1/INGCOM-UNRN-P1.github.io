---
title: "Gestión de Archivos y Errores (0x40XX)"
short_title: "Archivos y E/S"
subtitle: "Reglas para manejo de flujos de archivos, descriptores, reporte de errores y simetría de recursos."
---

(4_archivos)=
# Gestión de Archivos y Errores (0x40XX)

Reglas para manejo de flujos de archivos, descriptores, reporte de errores y simetría de recursos.

```{tableofcontents}
```

## Reglas de esta Categoría

| Código | Regla |
| :--- | :--- |
| [0x4001h](4_archivos/0x4001h.md) | Manejá correctamente la apertura y cierre de archivos |
| [0x4002h](4_archivos/0x4002h.md) | Validá los retornos de las operaciones de lectura y escritura de archivos |
| [0x4003h](4_archivos/0x4003h.md) | Utilizá errno, perror y strerror para reportar fallos del sistema operativo de manera precisa |
| [0x4004h](4_archivos/0x4004h.md) | Mantené la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción |
| [0x4005h](4_archivos/0x4005h.md) | Prescindí del uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones |
| [0x4006h](4_archivos/0x4006h.md) | Prohibición del antipatrón while (!feof(f)) para control de fin de archivo |
| [0x4007h](4_archivos/0x4007h.md) | Prohibición de rutas absolutas hardcodeadas en llamadas de archivo |
| [0x4008h](4_archivos/0x4008h.md) | Validación obligatoria del valor de retorno de fclose() en modo escritura |
| [0x4009h](4_archivos/0x4009h.md) | Prohibición de anidar llamadas a fopen() directamente dentro de funciones de E/S |
| [0x400Ah](4_archivos/0x400Ah.md) | Prohibición de operar sobre flujos de archivo tras haber invocado fclose() (use-after-close) |
