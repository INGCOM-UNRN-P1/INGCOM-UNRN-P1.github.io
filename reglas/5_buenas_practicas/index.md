---
title: "Compilación y Buenas Prácticas de Ingeniería (0x50XX)"
short_title: "Buenas Prácticas"
subtitle: "Reglas sobre directivas de preprocesador, guardas de inclusión, robustez y configuración de compilador."
---

# Compilación y Buenas Prácticas de Ingeniería (0x50XX)

Reglas sobre directivas de preprocesador, guardas de inclusión, robustez y configuración de compilador.

```{tableofcontents}
```

## Catálogo de Reglas

| Regla | Descripción |
| :--- | :--- |
| [0x5001h](0x5001h.md) | Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación |
| [0x5002h](0x5002h.md) | Desarrollá y compilá siempre con todas las advertencias del compilador activadas |
| [0x5003h](0x5003h.md) | Utilizá guardas de inclusión en todos los archivos de cabecera |
| [0x5004h](0x5004h.md) | Todas las operaciones con cadenas deben ser seguras |
| [0x5005h](0x5005h.md) | Organizá la estructura de tus archivos .c de forma estándar |
| [0x5006h](0x5006h.md) | Preferí fgets sobre gets y scanf para leer cadenas |
| [0x5007h](0x5007h.md) | Inclusiones redundantes o duplicadas de la misma cabecera #include |
| [0x5008h](0x5008h.md) | Prohibición de funciones obsoletas o inseguras (gets, atoi) |
| [0x5009h](0x5009h.md) | Prohibición de división entera no intencional asignada a flotantes |
| [0x500Ah](0x500Ah.md) | Protección obligatoria de parámetros en macros funcionales mediante paréntesis |
| [0x500Bh](0x500Bh.md) | Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C |
| [0x500Ch](0x500Ch.md) | Prohibición de inclusión directa de archivos de código fuente C (.c) |
| [0x500Dh](0x500Dh.md) | Prohibición de redefinir palabras clave o tipos primitivos de C con #define |
| [0x500Eh](0x500Eh.md) | Prohibición de la biblioteca obsoleta y no estándar <conio.h> (getch, clrscr) |
| [0x5011h](0x5011h.md) | Colisión de nombres de macroguardas entre archivos de cabecera distintos |
| [0x5012h](0x5012h.md) | Prohibición de directivas #pragma no estándar o privativas |
| [0x5013h](0x5013h.md) | Prohibición de declaraciones extern en archivos de implementación (.c) |
| [0x5014h](0x5014h.md) | Detección de inclusiones cíclicas entre archivos de cabecera |
| [0x5015h](0x5015h.md) | Protección obligatoria con paréntesis envolventes en expresiones de macroconstantes (#define) |
| [0x5016h](0x5016h.md) | Inclusión explícita obligatoria de cabeceras para funciones de biblioteca estándar |
