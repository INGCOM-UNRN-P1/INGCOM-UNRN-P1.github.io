---
title: "Gestión de Archivos y Errores (0x40XX)"
short_title: "Archivos y E/S"
subtitle: "Reglas y antipatrones para manejo de flujos de archivos, descriptores, reporte de errores y E/S."
---

# Gestión de Archivos y Errores (0x40XX)

Reglas y antipatrones para manejo de flujos de archivos, descriptores, reporte de errores y E/S.

```{tableofcontents}
```

## Tabla Comparativa: Regla de Estilo ↔ Antipatrón Didáctico

La tabla siguiente unifica las directivas prescriptivas de estilo y los antipatrones detectados:

| Regla de Estilo | Título de la Norma | Antipatrón Didáctico | Código Antipatrón |
| :--- | :--- | :--- | :--- |
| [0x4001h](0x4001h.md) | Manejá correctamente la apertura y cierre de archivos | [Omisión de verificación de retorno NULL en fopen()](ap_0x400Bh.md) | `AP-0x400Bh` |
| [0x4002h](0x4002h.md) | Validá los retornos de las operaciones de lectura y escritura de archivos | [Control de lectura con while(!feof())](ap_0x4002h.md) | `AP-0x4002h` |
| [0x4003h](0x4003h.md) | Utilizá errno, perror y strerror para reportar fallos del sistema operativo de manera precisa | *(Sin antipatrón específico)* | — |
| [0x4004h](0x4004h.md) | mantené la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción | *(Sin antipatrón específico)* | — |
| [0x4005h](0x4005h.md) | Prescindí del uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones | *(Sin antipatrón específico)* | — |
| [0x4006h](0x4006h.md) | Prohibición del antipatrón while (!feof(f)) para control de fin de archivo | [Uso de fflush(stdin) para limpiar buffer](ap_0x4006h.md) | `AP-0x4006h` |
| [0x4007h](0x4007h.md) | Prohibición de rutas absolutas hardcodeadas en llamadas de archivo | *(Sin antipatrón específico)* | — |
| [0x4008h](0x4008h.md) | Validación obligatoria del valor de retorno de fclose() en modo escritura | [Desajuste de especificadores de formato en printf/scanf](ap_0x4008h.md) | `AP-0x4008h` |
| | | [Vulnerabilidad de formato variable (Format String) en printf()](ap_0x4008b.md) | `AP-0x4008b` |
| [0x4009h](0x4009h.md) | Prohibición de anidar llamadas a fopen() directamente dentro de funciones de E/S | [Retorno prematuro con fuga de recursos de archivo](ap_0x4009h.md) | `AP-0x4009h` |
| [0x400Ah](0x400Ah.md) | Prohibición de operar sobre flujos de archivo tras haber invocado fclose() (use-after-close) | [Lectura de cadenas con scanf() sin límite de ancho en buffer fijo](ap_0x400Ah.md) | `AP-0x400Ah` |
