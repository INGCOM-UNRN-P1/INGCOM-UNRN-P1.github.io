---
title: Compilación y Buenas Prácticas de Ingeniería
short_title: Buenas Prácticas
subtitle: Reglas de estilo para la compilación robusta y buenas prácticas de ingeniería en C
---

(0x50XXh)=
# Compilación y Buenas Prácticas de Ingeniería (`0x50XX`)

(0x5001h)=
## Regla `0x5001h`: Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación

Los Arreglos de Longitud Variable (ALV / VLA) están prohibidos debido a los
riesgos de desbordamiento incontrolado de la pila. Deben definirse con una
constante en tiempo de compilación.

``` diff
- int n = 10;
- int numeros[n]; // ALV prohibido
+ #define TAMANO_NUMEROS 10
+ int numeros[TAMANO_NUMEROS];
```
<!-- diff -->

(0x5002h)=
## Regla `0x5002h`: Desarrollá y compilá siempre con todas las advertencias del compilador activadas

Debés activar las advertencias de compilación para la detección temprana de
errores lógicos. Usá al menos las siguientes banderas con `gcc` o `clang`:

``` make
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs
```
<!-- make -->

(0x5003h)=
## Regla `0x5003h`: Utilizá guardas de inclusión en todos los archivos de cabecera

Todos los archivos de cabecera (`.h`) deben incluir guardas de preprocesador
para evitar problemas de redefinición múltiple.

``` c
#ifndef MI_MODULO_H
#define MI_MODULO_H
// Declaraciones...
#endif // MI_MODULO_H
```
<!-- c -->

Añadí comentarios en las directivas `#include` de cabeceras de terceros o del
proyecto para documentar la provisión de símbolos, y evitá cabeceras unificadas
que importen todo un módulo innecesariamente.

(0x5004h)=
## Regla `0x5004h`: Todas las operaciones con cadenas deben ser seguras

Utilizá funciones que controlen los límites de tamaño máximo del buffer de
destino (`strncpy`, `snprintf`, `strncat`) para prevenir desbordamientos.

- **Incorrecto (inseguro):**
  ```c
  void concatenar_saludo(char *destino, const char *nombre)
  {
      strcpy(destino, "Hola, ");
      strcat(destino, nombre);
  }
  ```
- **Correcto (seguro):**
  ```c
  void concatenar_saludo_seguro(char *destino, size_t tam_destino,
                                const char *nombre)
  {
      snprintf(destino, tam_destino, "Hola, %s", nombre);
  }
  ```

(0x5005h)=
## Regla `0x5005h`: Organizá la estructura de tus archivos `.c` de forma estándar

Mantené la estructura de archivo ordenada en secciones progresivas para mejorar
su predictibilidad:

1.  Inclusiones de bibliotecas estándar (`<stdio.h>`).
2.  Inclusiones de bibliotecas de terceros.
3.  Inclusiones de cabeceras del proyecto (`"modulo.h"`).
4.  Definición de macros y constantes (`#define`).
5.  Definiciones de tipos (`typedef`, `struct`, `enum`).
6.  Prototipos de funciones privadas (`static`).
7.  Función `main` (si aplica).
8.  Implementación de funciones públicas.
9.  Implementación de funciones privadas (`static`).

(0x5006h)=
## Regla `0x5006h`: Preferí `fgets` sobre `gets` y `scanf` para leer cadenas

`fgets` previene el desbordamiento de búfer de entrada de forma automática
mediante la validación de tamaño del buffer de entrada.

- **Incorrecto:**
  ```c
  char buffer[50];
  scanf("%s", buffer);
  ```
- **Correcto:**
  ```c
  char buffer[50];
  fgets(buffer, sizeof(buffer), stdin);
  ```

