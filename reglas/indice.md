---
title: Cuestiones de estilo
short_title: 0x0000h - Estilo
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

## {doc}`0_sintaxis`
  * [1. Sintaxis Básica y Nomenclatura (`0x00XX`)](0_sintaxis.md#1-sintaxis-basica-y-nomenclatura-0x00xx)
    * [Regla `0x0000h`: La claridad y prolijidad son de máxima importancia](0_sintaxis.md#regla-0x0000h-la-claridad-y-prolijidad-son-de-maxima-importancia)
    * [Regla `0x0001h`: Los identificadores deben ser descriptivos](0_sintaxis.md#regla-0x0001h-los-identificadores-deben-ser-descriptivos)
    * [Regla `0x0002h`: Una declaración de variable por línea](0_sintaxis.md#regla-0x0002h-una-declaracion-de-variable-por-linea)
    * [Regla `0x0003h`: Siempre debés inicializar las variables a un valor conocido](0_sintaxis.md#regla-0x0003h-siempre-debes-inicializar-las-variables-a-un-valor-conocido)
    * [Regla `0x0004h`: Un espacio antes y después de cada operador binario](0_sintaxis.md#regla-0x0004h-un-espacio-antes-y-despues-de-cada-operador-binario)
    * [Regla `0x0005h`: Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves](0_sintaxis.md#regla-0x0005h-cada-bloque-debe-tener-una-indentacion-de-cuatro-espacios-respecto-a-su-contenedor-y-llaves)
    * [Regla `0x0006h`: El asterisco de los punteros debe declararse junto al identificador](0_sintaxis.md#regla-0x0006h-el-asterisco-de-los-punteros-debe-declararse-junto-al-identificador)
    * [Regla `0x0007h`: Los argumentos de función y las variables locales deben usar `snake_case` en minúsculas](0_sintaxis.md#regla-0x0007h-los-argumentos-de-funcion-y-las-variables-locales-deben-usar-snake-case-en-minusculas)
    * [Regla `0x0008h`: Las constantes (`const` o `#define`) deben nombrarse en `MAYUSCULAS_SNAKE_CASE`](0_sintaxis.md#regla-0x0008h-las-constantes-const-o-define-deben-nombrarse-en-mayusculas-snake-case)
    * [Regla `0x0009h`: Las líneas de código no deben exceder los 79 caracteres](0_sintaxis.md#regla-0x0009h-las-lineas-de-codigo-no-deben-exceder-los-79-caracteres)
    * [Regla `0x000Ah`: Escribí comentarios que expliquen el "porqué", no el "qué"](0_sintaxis.md#regla-0x000ah-escribi-comentarios-que-expliquen-el-porque-no-el-que)

## {doc}`1_control`
  * [2. Estructuras de Control y Lazos (`0x10XX`)](1_control.md#2-estructuras-de-control-y-lazos-0x10xx)
    * [Regla `0x1001h`: Todas las estructuras de control deben utilizar llaves](1_control.md#regla-0x1001h-todas-las-estructuras-de-control-deben-utilizar-llaves)
    * [Regla `0x1002h`: Evitá el uso descontrolado de `break` y `continue`; preferí lazos con bandera de control](1_control.md#regla-0x1002h-evita-el-uso-descontrolado-de-break-y-continue-preferi-lazos-con-bandera-de-control)
    * [Regla `0x1003h`: Utilizá el lazo `for` para iteraciones con rango o contador definido y `while` para lazos controlados por condiciones lógicas](1_control.md#regla-0x1003h-utiliza-el-lazo-for-para-iteraciones-con-rango-o-contador-definido-y-while-para-lazos-controlados-por-condiciones-logicas)
    * [Regla `0x1004h`: Las condiciones complejas deben ser simplificadas o comentadas](1_control.md#regla-0x1004h-las-condiciones-complejas-deben-ser-simplificadas-o-comentadas)
    * [Regla `0x1005h`: Evitá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato](1_control.md#regla-0x1005h-evita-las-condiciones-ambiguas-basadas-en-la-veracidad-truthiness-del-tipo-de-dato)
    * [Regla `0x1006h`: No utilizar la instrucción `goto`](1_control.md#regla-0x1006h-no-utilizar-la-instruccion-goto)
    * [Regla `0x1007h`: No utilizar el operador condicional (ternario) `?:`](1_control.md#regla-0x1007h-no-utilizar-el-operador-condicional-ternario)
    * [Regla `0x1008h`: Toda instrucción `switch` debe incluir un caso `default`](1_control.md#regla-0x1008h-toda-instruccion-switch-debe-incluir-un-caso-default)

## {doc}`2_funciones`
  * [3. Funciones y Modularización (`0x20XX`)](2_funciones.md#3-funciones-y-modularizacion-0x20xx)
    * [Regla `0x2001h`: Las funciones deben usar cláusulas de guarda y retornos anticipados para evitar la anidación profunda](2_funciones.md#regla-0x2001h-las-funciones-deben-usar-clausulas-de-guarda-y-retornos-anticipados-para-evitar-la-anidacion-profunda)
    * [Regla `0x2002h`: Las funciones no deben contener `printf` o `scanf`, a menos que ese sea su propósito explícito](2_funciones.md#regla-0x2002h-las-funciones-no-deben-contener-printf-o-scanf-a-menos-que-ese-sea-su-proposito-explicito)
    * [Regla `0x2003h`: Todas las funciones deben incluir documentación completa y estructurada](2_funciones.md#regla-0x2003h-todas-las-funciones-deben-incluir-documentacion-completa-y-estructurada)
    * [Regla `0x2004h`: No se permite el uso de variables globales](2_funciones.md#regla-0x2004h-no-se-permite-el-uso-de-variables-globales)
    * [Regla `0x2005h`: Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única)](2_funciones.md#regla-0x2005h-cada-funcion-debe-tener-una-unica-responsabilidad-principio-de-responsabilidad-unica)
    * [Regla `0x2006h`: Una aserción por cada función de prueba](2_funciones.md#regla-0x2006h-una-asercion-por-cada-funcion-de-prueba)
    * [Regla `0x2007h`: Mantené el alcance de las variables al mínimo posible](2_funciones.md#regla-0x2007h-mantene-el-alcance-de-las-variables-al-minimo-posible)
    * [Regla `0x2008h`: Los valores de retorno numéricos deben definirse como constantes de preprocesador o `enum`s](2_funciones.md#regla-0x2008h-los-valores-de-retorno-numericos-deben-definirse-como-constantes-de-preprocesador-o-enum-s)
    * [Regla `0x2009h`: Los ejercicios deben ser resueltos mediante funciones](2_funciones.md#regla-0x2009h-los-ejercicios-deben-ser-resueltos-mediante-funciones)
    * [Regla `0x200Ah`: Los nombres de funciones y procedimientos deben usar `snake_case` en minúsculas](2_funciones.md#regla-0x200ah-los-nombres-de-funciones-y-procedimientos-deben-usar-snake-case-en-minusculas)

## {doc}`3_punteros`
  * [4. Punteros y Gestión de Memoria (`0x30XX`)](3_punteros.md#4-punteros-y-gestion-de-memoria-0x30xx)
    * [Regla `0x3001h`: Siempre verificá la asignación exitosa de memoria dinámica](3_punteros.md#regla-0x3001h-siempre-verifica-la-asignacion-exitosa-de-memoria-dinamica)
    * [Regla `0x3002h`: Liberá siempre la memoria dinámica y asigná `NULL` al puntero para evitar punteros colgantes](3_punteros.md#regla-0x3002h-libera-siempre-la-memoria-dinamica-y-asigna-null-al-puntero-para-evitar-punteros-colgantes)
    * [Regla `0x3003h`: No mezcles operaciones de asignación y comparación en una sola línea](3_punteros.md#regla-0x3003h-no-mezcles-operaciones-de-asignacion-y-comparacion-en-una-sola-linea)
    * [Regla `0x3004h`: Utilizá `typedef` para definir tipos de estructuras con el sufijo `_t`](3_punteros.md#regla-0x3004h-utiliza-typedef-para-definir-tipos-de-estructuras-con-el-sufijo-t)
    * [Regla `0x3005h`: Minimizá el uso de múltiples niveles de indirección (punteros a punteros)](3_punteros.md#regla-0x3005h-minimiza-el-uso-de-multiples-niveles-de-indireccion-punteros-a-punteros)
    * [Regla `0x3006h`: Documentá la propiedad de los recursos al utilizar punteros](3_punteros.md#regla-0x3006h-documenta-la-propiedad-de-los-recursos-al-utilizar-punteros)
    * [Regla `0x3007h`: Los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique](3_punteros.md#regla-0x3007h-los-argumentos-de-tipo-puntero-deben-ser-const-siempre-que-la-funcion-no-los-modifique)
    * [Regla `0x3008h`: Los punteros nulos deben ser inicializados y comparados con `NULL`, no con `0`](3_punteros.md#regla-0x3008h-los-punteros-nulos-deben-ser-inicializados-y-comparados-con-null-no-con-0)
    * [Regla `0x3009h`: Documentá explícitamente los casos en que una función puede retornar `NULL`](3_punteros.md#regla-0x3009h-documenta-explicitamente-los-casos-en-que-una-funcion-puede-retornar-null)
    * [Regla `0x300Ah`: Utilizá `cast` explícito al convertir tipos de punteros](3_punteros.md#regla-0x300ah-utiliza-cast-explicito-al-convertir-tipos-de-punteros)
    * [Regla `0x300Bh`: Usá siempre `sizeof` en las asignaciones de memoria dinámica, prefiriendo `sizeof(*ptr)`](3_punteros.md#regla-0x300bh-usa-siempre-sizeof-en-las-asignaciones-de-memoria-dinamica-prefiriendo-sizeof-ptr)
    * [Regla `0x300Ch`: Verificá siempre los límites de los arreglos antes de acceder a sus elementos](3_punteros.md#regla-0x300ch-verifica-siempre-los-limites-de-los-arreglos-antes-de-acceder-a-sus-elementos)
    * [Regla `0x300Dh`: Utilizá `enum` en lugar de "números mágicos" para conjuntos de estados y valores constantes](3_punteros.md#regla-0x300dh-utiliza-enum-en-lugar-de-numeros-magicos-para-conjuntos-de-estados-y-valores-constantes)
    * [Regla `0x300Eh`: Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos](3_punteros.md#regla-0x300eh-documenta-explicitamente-el-comportamiento-de-las-funciones-al-manejar-punteros-nulos-como-argumentos)
    * [Regla `0x300Fh`: Liberá la memoria en el orden inverso a su asignación](3_punteros.md#regla-0x300fh-libera-la-memoria-en-el-orden-inverso-a-su-asignacion)
    * [Regla `0x3010h`: Las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`](3_punteros.md#regla-0x3010h-las-variables-que-representan-tamanos-o-indices-de-arreglos-deben-ser-de-tipo-size-t)
    * [Regla `0x3011h`: Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar `const void*`](3_punteros.md#regla-0x3011h-si-una-funcion-recibe-un-puntero-generico-para-operaciones-de-solo-lectura-la-firma-de-la-funcion-debe-utilizar-const-void)
    * [Regla `0x0035h`: Diseñá los Tipos de Datos Abstractos utilizando punteros opacos](3_punteros.md#regla-0x0035h-disena-los-tipos-de-datos-abstractos-utilizando-punteros-opacos)
    * [Regla `0x0036h`: Asigná `NULL` al puntero tras liberar un recurso opaco en el ámbito del cliente](3_punteros.md#regla-0x0036h-asigna-null-al-puntero-tras-liberar-un-recurso-opaco-en-el-ambito-del-cliente)

## {doc}`4_archivos`
  * [5. Gestión de Archivos y Errores (`0x40XX`)](4_archivos.md#5-gestion-de-archivos-y-errores-0x40xx)
    * [Regla `0x4001h`: Manejá correctamente la apertura y cierre de archivos](4_archivos.md#regla-0x4001h-maneja-correctamente-la-apertura-y-cierre-de-archivos)
    * [Regla `0x4002h`: Validá los retornos de las operaciones de lectura y escritura de archivos](4_archivos.md#regla-0x4002h-valida-los-retornos-de-las-operaciones-de-lectura-y-escritura-de-archivos)
    * [Regla `0x4003h`: Utilizá `errno`, `perror` y `strerror` para reportar fallos del sistema operativo de manera precisa](4_archivos.md#regla-0x4003h-utiliza-errno-perror-y-strerror-para-reportar-fallos-del-sistema-operativo-de-manera-precisa)
    * [Regla `0x4004h`: Asegurá la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción](4_archivos.md#regla-0x4004h-asegura-la-simetria-de-recursos-al-abrir-y-cerrar-archivos-en-el-mismo-nivel-de-abstraccion)
    * [Regla `0x4005h`: Evitá el uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones](4_archivos.md#regla-0x4005h-evita-el-uso-de-offsets-y-posiciones-fijas-codificadas-a-mano-en-archivos-binarios-sin-validar-sus-dimensiones)

## {doc}`5_buenas_practicas`
  * [6. Compilación y Buenas Prácticas de Ingeniería (`0x50XX`)](5_buenas_practicas.md#6-compilacion-y-buenas-practicas-de-ingenieria-0x50xx)
    * [Regla `0x5001h`: Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación](5_buenas_practicas.md#regla-0x5001h-los-arreglos-estaticos-deben-ser-creados-con-un-tamano-fijo-en-tiempo-de-compilacion)
    * [Regla `0x5002h`: Desarrollá y compilá siempre con todas las advertencias del compilador activadas](5_buenas_practicas.md#regla-0x5002h-desarrolla-y-compila-siempre-con-todas-las-advertencias-del-compilador-activadas)
    * [Regla `0x5003h`: Utilizá guardas de inclusión en todos los archivos de cabecera](5_buenas_practicas.md#regla-0x5003h-utiliza-guardas-de-inclusion-en-todos-los-archivos-de-cabecera)
    * [Regla `0x5004h`: Todas las operaciones con cadenas deben ser seguras](5_buenas_practicas.md#regla-0x5004h-todas-las-operaciones-con-cadenas-deben-ser-seguras)
    * [Regla `0x5005h`: Organizá la estructura de tus archivos `.c` de forma estándar](5_buenas_practicas.md#regla-0x5005h-organiza-la-estructura-de-tus-archivos-c-de-forma-estandar)
    * [Regla `0x5006h`: Preferí `fgets` sobre `gets` y `scanf` para leer cadenas](5_buenas_practicas.md#regla-0x5006h-preferi-fgets-sobre-gets-y-scanf-para-leer-cadenas)
