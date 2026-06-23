---
title: Cuestiones de estilo
short_title: Índice
subtitle: Pautas para la organización y prolijidad del código.
---

## Introducción

Este documento establece un conjunto de reglas de estilo, diseñadas para que su código en C sea más claro, legible y menos propenso a errores. La programación en C ofrece una gran flexibilidad, pero ello también facilita la adopción de malas prácticas que pueden conducir a errores de difícil detección. Por este motivo, la adhesión a un conjunto de reglas claras es fundamental para mantener el código ordenado y seguro.

La idea detrás de estas reglas es que un código de calidad no solo debe ser funcional, sino también comprensible para cualquier profesional que deba leerlo, ya sea vos mismo en el futuro o un colega que se incorpore al proyecto. Un código limpio y bien organizará facilita la colaboración, ahorra tiempo en la fase de corrección y previene complicaciones durante la depuración o actualización del software.

Estas reglas abarcan desde la nomenclatura de variables y funciones hasta la estructuración de condicionales y lazos. Su observancia no solo contribuye a la coherencia del proyecto, sino que también resulta en un código más robusto y mantenible a largo plazo.

Al comenzar, la aplicación de reglas estrictas en un lenguaje flexible como C te proporciona un marco sólido. A medida que tu comprensión del lenguaje se profundice, podés adaptar estas reglas para desarrollar un estilo propio.

## Apertura a Sugerencias y Debate

Estamos abiertos a debatir todas las reglas. Para ello, solo tenés que abrir un hilo en Discussions o un ticket en el Issue Tracker. Aceptamos propuestas de nuevas reglas, clasificaciones, explicaciones y potenciales excepciones.

## Principios Clave

- **Claridad:** El código debe ser fácil de leer.
- **Mantenibilidad:** Debe ser sencillo de modificar y extender.
- **Consistencia:** El uso de un estilo uniforme optimiza la colaboración.
- **Eficiencia:** Se debe optimizar el rendimiento sin sacrificar la legibilidad.

---

## Estructura de Clasificación de Reglas (Máscara de Bits)

Para facilitar la referencia cruzada y el análisis estático de las pautas de estilo, las reglas se encuentran organizadas en secciones temáticas progresivas bajo un esquema de máscara de bits de 16 bits (`0xXXXX`):

1.  **Sintaxis Básica y Nomenclatura (`0x00XX`):** Reglas visuales, espaciado, indentación y pautas de nombrado de variables y constantes.
2.  **Estructuras de Control y Lazos (`0x10XX`):** Bloques condicionales, estructuras de iteración y flujos de ejecución de sentencias.
3.  **Funciones y Modularización (`0x20XX`):** Diseño de interfaces de funciones, documentación de contratos, alcance y responsabilidades.
4.  **Punteros y Gestión de Memoria (`0x30XX`):** Uso de indirecciones, alocación en el heap, gestión de punteros nulos y liberación segura de recursos.
5.  **Gestión de Archivos y Errores (`0x40XX`):** Apertura/cierre de flujos de archivos, validación de E/S, gestión de errno y diagnóstico del sistema.
6.  **Compilación y Buenas Prácticas de Ingeniería (`0x50XX`):** Configuración de alertas, guardas de cabeceras, robustez y estructuras de código estándar.

## [](0_sintaxis)
  * [Sintaxis Básica y Nomenclatura (`0x00XX`)](0_sintaxis.md#0x00xxh)
    * [Regla `0x0000h`: La claridad y prolijidad son de máxima importancia](0_sintaxis.md#0x0000h)
    * [Regla `0x0001h`: Los identificadores deben ser descriptivos](0_sintaxis.md#0x0001h)
    * [Regla `0x0002h`: Una declaración de variable por línea](0_sintaxis.md#0x0002h)
    * [Regla `0x0003h`: Siempre debés inicializar las variables a un valor conocido](0_sintaxis.md#0x0003h)
    * [Regla `0x0004h`: Un espacio antes y después de cada operador binario](0_sintaxis.md#0x0004h)
    * [Regla `0x0005h`: Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves](0_sintaxis.md#0x0005h)
    * [Regla `0x0006h`: El asterisco de los punteros debe declararse junto al identificador](0_sintaxis.md#0x0006h)
    * [Regla `0x0007h`: Los argumentos de función y las variables locales deben usar `snake_case` en minúsculas](0_sintaxis.md#0x0007h)
    * [Regla `0x0008h`: Las constantes (`const` o `#define`) deben nombrarse en `MAYUSCULAS_SNAKE_CASE`](0_sintaxis.md#0x0008h)
    * [Regla `0x0009h`: Las líneas de código no deben exceder los 79 caracteres](0_sintaxis.md#0x0009h)
    * [Regla `0x000Ah`: Escribí comentarios que expliquen el "porqué", no el "qué"](0_sintaxis.md#0x000ah)

## [](1_control)
  * [Estructuras de Control y Lazos (`0x10XX`)](1_control.md#0x10xxh)
    * [Regla `0x1001h`: Todas las estructuras de control deben utilizar llaves](1_control.md#0x1001h)
    * [Regla `0x1002h`: Evitá el uso descontrolado de `break` y `continue`; preferí lazos con bandera de control](1_control.md#0x1002h)
    * [Regla `0x1003h`: Utilizá el lazo `for` para iteraciones con rango o contador definido y `while` para lazos controlados por condiciones lógicas](1_control.md#0x1003h)
    * [Regla `0x1004h`: Las condiciones complejas deben ser simplificadas o comentadas](1_control.md)
    * [Regla `0x1005h`: Evitá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato](1_control.md#0x1005h)
    * [Regla `0x1006h`: No utilizar la instrucción `goto`](1_control.md#0x1006h)
    * [Regla `0x1007h`: No utilizar el operador condicional (ternario) `?:`](1_control.md#0x1007h)
    * [Regla `0x1008h`: Toda instrucción `switch` debe incluir un caso `default`](1_control.md#0x1008h)

## [](2_funciones)
  * [Funciones y Modularización (`0x20XX`)](2_funciones.md#0x20xxh)
    * [Regla `0x2001h`: Las funciones deben usar cláusulas de guarda y retornos anticipados para evitar la anidación profunda](2_funciones.md#0x2001h)
    * [Regla `0x2002h`: Las funciones no deben contener `printf` o `scanf`, a menos que ese sea su propósito explícito](2_funciones.md#0x2002h)
    * [Regla `0x2003h`: Todas las funciones deben incluir documentación completa y estructurada](2_funciones.md#0x2003h)
    * [Regla `0x2004h`: No se permite el uso de variables globales](2_funciones.md#0x2004h)
    * [Regla `0x2005h`: Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única)](2_funciones.md#0x2005h)
    * [Regla `0x2006h`: Una aserción por cada función de prueba](2_funciones.md#0x2006h)
    * [Regla `0x2007h`: Mantené el alcance de las variables al mínimo posible](2_funciones.md#0x2007h)
    * [Regla `0x2008h`: Los valores de retorno numéricos deben definirse como constantes de preprocesador o `enum`s](2_funciones.md#0x2008h)
    * [Regla `0x2009h`: Los ejercicios deben ser resueltos mediante funciones](2_funciones.md#0x2009h)
    * [Regla `0x200Ah`: Los nombres de funciones y procedimientos deben usar `snake_case` en minúsculas](2_funciones.md#0x200ah)

## [](3_punteros)
  * [Punteros y Gestión de Memoria (`0x30XX`)](3_punteros.md#0x30xxh)
    * [Regla `0x3001h`: Siempre verificá la asignación exitosa de memoria dinámica](3_punteros.md#0x3001h)
    * [Regla `0x3002h`: Liberá siempre la memoria dinámica y asigná `NULL` al puntero para evitar punteros colgantes](3_punteros.md#0x3002h)
    * [Regla `0x3003h`: No mezcles operaciones de asignación y comparación en una sola línea](3_punteros.md#0x3003h)
    * [Regla `0x3004h`: Utilizá `typedef` para definir tipos de estructuras con el sufijo `_t`](3_punteros.md#0x3004h)
    * [Regla `0x3005h`: Minimizá el uso de múltiples niveles de indirección (punteros a punteros)](3_punteros.md#0x3005h)
    * [Regla `0x3006h`: Documentá la propiedad de los recursos al utilizar punteros](3_punteros.md#0x3006h)
    * [Regla `0x3007h`: Los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique](3_punteros.md#0x3007h)
    * [Regla `0x3008h`: Los punteros nulos deben ser inicializados y comparados con `NULL`, no con `0`](3_punteros.md#0x3008h)
    * [Regla `0x3009h`: Documentá explícitamente los casos en que una función puede retornar `NULL`](3_punteros.md#0x3009h)
    * [Regla `0x300Ah`: Utilizá `cast` explícito al convertir tipos de punteros](3_punteros.md#0x300ah)
    * [Regla `0x300Bh`: Usá siempre `sizeof` en las asignaciones de memoria dinámica, prefiriendo `sizeof(*ptr)`](3_punteros.md#0x300bh)
    * [Regla `0x300Ch`: Verificá siempre los límites de los arreglos antes de acceder a sus elementos](3_punteros.md#0x300ch)
    * [Regla `0x300Dh`: Utilizá `enum` en lugar de "números mágicos" para conjuntos de estados y valores constantes](3_punteros.md#0x300dh)
    * [Regla `0x300Eh`: Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos](3_punteros.md#0x300eh)
    * [Regla `0x300Fh`: Liberá la memoria en el orden inverso a su asignación](3_punteros.md#0x300fh)
    * [Regla `0x3010h`: Las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`](3_punteros.md#0x3010h)
    * [Regla `0x3011h`: Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar `const void*`](3_punteros.md#0x3011h)
    * [Regla `0x0035h`: Diseñá los Tipos de Datos Abstractos utilizando punteros opacos](3_punteros.md#0x0035h)
    * [Regla `0x0036h`: Asigná `NULL` al puntero tras liberar un recurso opaco en el ámbito del cliente](3_punteros.md#0x0036h)

## [](4_archivos)
  * [Gestión de Archivos y Errores (`0x40XX`)](4_archivos.md#0x40xxh)
    * [Regla `0x4001h`: Manejá correctamente la apertura y cierre de archivos](4_archivos.md#0x4001h)
    * [Regla `0x4002h`: Validá los retornos de las operaciones de lectura y escritura de archivos](4_archivos.md#0x4002h)
    * [Regla `0x4003h`: Utilizá `errno`, `perror` y `strerror` para reportar fallos del sistema operativo de manera precisa](4_archivos.md#0x4003h)
    * [Regla `0x4004h`: Asegurá la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción](4_archivos.md#0x4004h)
    * [Regla `0x4005h`: Evitá el uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones](4_archivos.md#0x4005h)

## [](5_buenas_practicas)
  * [Compilación y Buenas Prácticas de Ingeniería (`0x50XX`)](5_buenas_practicas.md#0x50xxh)
    * [Regla `0x5001h`: Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación](5_buenas_practicas.md#0x5001h)
    * [Regla `0x5002h`: Desarrollá y compilá siempre con todas las advertencias del compilador activadas](5_buenas_practicas.md#0x5002h)
    * [Regla `0x5003h`: Utilizá guardas de inclusión en todos los archivos de cabecera](5_buenas_practicas.md#0x5003h)
    * [Regla `0x5004h`: Todas las operaciones con cadenas deben ser seguras](5_buenas_practicas.md#0x5004h)
    * [Regla `0x5005h`: Organizá la estructura de tus archivos `.c` de forma estándar](5_buenas_practicas.md#0x5005h)
    * [Regla `0x5006h`: Preferí `fgets` sobre `gets` y `scanf` para leer cadenas](5_buenas_practicas.md#0x5006h)
