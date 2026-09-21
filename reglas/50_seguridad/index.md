---
title: "Compilacion, preprocesador y seguridad (0x50XX)"
short_title: "Compilacion y seguridad"
subtitle: "Reglas sobre compilacion, preprocesador, cabeceras y seguridad estatica."
---

# Compilacion, preprocesador y seguridad (0x50XX)

Reglas sobre compilacion, preprocesador, cabeceras y seguridad estatica.

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x5001h](0x5001h.md) | Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación | — |
| [0x5002h](0x5002h.md) | Desarrollá y compilá siempre con todas las advertencias del compilador activadas | — |
| [0x5003h](0x5003h.md) | Utilizá guardas de inclusión en todos los archivos de cabecera | — |
| [0x5004h](0x5004h.md) | Todas las operaciones con cadenas deben ser seguras | `AP-0x5004b`, `AP-0x5004c`, `AP-0x5004h` |
| [0x5005h](0x5005h.md) | Organizá la estructura de tus archivos .c de forma estándar | — |
| [0x5006h](0x5006h.md) | Preferí fgets sobre gets y scanf para leer cadenas | `AP-0x400Ah` |
| [0x5007h](0x5007h.md) | Inclusiones redundantes o duplicadas de la misma cabecera #include | — |
| [0x5008h](0x5008h.md) | Prohibición de funciones obsoletas o inseguras (gets, atoi) | `AP-0x5008h` |
| [0x5009h](0x5009h.md) | Prohibición de división entera no intencional asignada a flotantes | `AP-0x5009h` |
| [0x500Ah](0x500Ah.md) | Protección obligatoria de parámetros en macros funcionales mediante paréntesis | `AP-0x500Ah` |
| [0x500Bh](0x500Bh.md) | Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C | — |
| [0x500Ch](0x500Ch.md) | Prohibición de inclusión directa de archivos de código fuente C (.c) | — |
| [0x500Dh](0x500Dh.md) | Prohibición de redefinir palabras clave o tipos primitivos de C con #define | `AP-0x0039h`, `AP-0x500Bh` |
| [0x500Eh](0x500Eh.md) | Prohibición de la biblioteca obsoleta y no estándar <conio.h> (getch, clrscr) | — |
| [0x500Fh](0x500Fh.md) | Colisión de nombres de macroguardas entre archivos de cabecera distintos | — |
| [0x5010h](0x5010h.md) | Prohibición de directivas #pragma no estándar o privativas | — |
| [0x5011h](0x5011h.md) | Prohibición de declaraciones extern en archivos de implementación (.c) | — |
| [0x5012h](0x5012h.md) | Detección de inclusiones cíclicas entre archivos de cabecera | — |
| [0x5013h](0x5013h.md) | Protección obligatoria con paréntesis envolventes en expresiones de macroconstantes (#define) | — |
| [0x5014h](0x5014h.md) | Inclusión explícita obligatoria de cabeceras para funciones de biblioteca estándar | — |
| [0x5015h](0x5015h.md) | No invoques el interprete de comandos con system() o popen() | *(regla promovida de antipatrón)* |
