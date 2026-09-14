---
title: "Compilación, Buenas Prácticas y Seguridad (0x50XX)"
short_title: "Buenas Prácticas y Seguridad"
subtitle: "Reglas y antipatrones sobre preprocesador, guardas de inclusión, funciones prohibidas y seguridad estática."
---

# Compilación, Buenas Prácticas y Seguridad (0x50XX)

Reglas y antipatrones sobre preprocesador, guardas de inclusión, funciones prohibidas y seguridad estática.

```{tableofcontents}
```

## Tabla Comparativa: Regla de Estilo ↔ Antipatrón Didáctico

La tabla siguiente unifica las directivas prescriptivas de estilo y los antipatrones detectados:

| Regla de Estilo | Título de la Norma | Antipatrón Didáctico | Código Antipatrón |
| :--- | :--- | :--- | :--- |
| [0x5001h](0x5001h.md) | Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación | *(Sin antipatrón específico)* | — |
| [0x5002h](0x5002h.md) | Desarrollá y compilá siempre con todas las advertencias del compilador activadas | *(Sin antipatrón específico)* | — |
| [0x5003h](0x5003h.md) | Utilizá guardas de inclusión en todos los archivos de cabecera | *(Sin antipatrón específico)* | — |
| [0x5004h](0x5004h.md) | Todas las operaciones con cadenas deben ser seguras | [Uso de funciones inseguras de manipulación de cadenas (strcpy/sprintf)](ap_0x5004h.md) | `AP-0x5004h` |
| | | [Comparación directa de cadenas con == o !=](ap_0x5004b.md) | `AP-0x5004b` |
| | | [Formateo inseguro con sprintf() sin comprobación de destino](ap_0x5004c.md) | `AP-0x5004c` |
| [0x5005h](0x5005h.md) | Organizá la estructura de tus archivos .c de forma estándar | *(Sin antipatrón específico)* | — |
| [0x5006h](0x5006h.md) | Preferí fgets sobre gets y scanf para leer cadenas | *(Sin antipatrón específico)* | — |
| [0x5007h](0x5007h.md) | Inclusiones redundantes o duplicadas de la misma cabecera #include | *(Sin antipatrón específico)* | — |
| [0x5008h](0x5008h.md) | Prohibición de funciones obsoletas o inseguras (gets, atoi) | [Invocación de la función prohibida gets()](ap_0x5008h.md) | `AP-0x5008h` |
| [0x5009h](0x5009h.md) | Prohibición de división entera no intencional asignada a flotantes | [División entera silenciosa asignada a flotante](ap_0x5009h.md) | `AP-0x5009h` |
| [0x500Ah](0x500Ah.md) | Protección obligatoria de parámetros en macros funcionales mediante paréntesis | [Macro con argumentos evaluados múltiples veces](ap_0x500Ah.md) | `AP-0x500Ah` |
| [0x500Bh](0x500Bh.md) | Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C | [Redefinición de identificadores de funciones estándar de la biblioteca C](ap_0x500Bh.md) | `AP-0x500Bh` |
| [0x500Ch](0x500Ch.md) | Prohibición de inclusión directa de archivos de código fuente C (.c) | *(Sin antipatrón específico)* | — |
| [0x500Dh](0x500Dh.md) | Prohibición de redefinir palabras clave o tipos primitivos de C con #define | *(Sin antipatrón específico)* | — |
| [0x500Eh](0x500Eh.md) | Prohibición de la biblioteca obsoleta y no estándar <conio.h> (getch, clrscr) | *(Sin antipatrón específico)* | — |
| [0x5011h](0x5011h.md) | Colisión de nombres de macroguardas entre archivos de cabecera distintos | *(Sin antipatrón específico)* | — |
| [0x5012h](0x5012h.md) | Prohibición de directivas #pragma no estándar o privativas | *(Sin antipatrón específico)* | — |
| [0x5013h](0x5013h.md) | Prohibición de declaraciones extern en archivos de implementación (.c) | *(Sin antipatrón específico)* | — |
| [0x5014h](0x5014h.md) | Detección de inclusiones cíclicas entre archivos de cabecera | [Invocación al intérprete de comandos con system() o popen()](ap_0x5014h.md) | `AP-0x5014h` |
| [0x5015h](0x5015h.md) | Protección obligatoria con paréntesis envolventes en expresiones de macroconstantes (#define) | *(Sin antipatrón específico)* | — |
| [0x5016h](0x5016h.md) | Inclusión explícita obligatoria de cabeceras para funciones de biblioteca estándar | [Llamada a sistema restringida fuera de consigna](ap_0x5016h.md) | `AP-0x5016h` |
