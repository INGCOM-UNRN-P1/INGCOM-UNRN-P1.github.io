# Índice global de Reglas de Estilo

## Sintaxis y formato visual (0x00XX)

Reglas de estilo visual, espaciado, indentación, llaves y formato en C.

 * [0x0001h](0x0001h.md): La claridad y prolijidad son de máxima importancia
 * [0x0002h](0x0002h.md): Una declaración de variable por línea
 * [0x0003h](0x0003h.md): Un espacio antes y después de cada operador binario
 * [0x0004h](0x0004h.md): Cada bloque debe tener una indentación de cuatro
   espacios respecto a su contenedor y llaves
 * [0x0005h](0x0005h.md): El asterisco de los punteros debe declararse junto al
   identificador
 * [0x0006h](0x0006h.md): Las líneas de código no deben exceder los 79
   caracteres
 * [0x0007h](0x0007h.md): Las llaves deben ubicarse en líneas independientes
   según el estilo Allman
 * [0x0008h](0x0008h.md): Alineación vertical consistente en asignaciones y
   declaraciones consecutivas
 * [0x0009h](0x0009h.md): Espaciado consistente en declaraciones de doble
   puntero (tipo `**var`)
 * [0x000Ah](0x000Ah.md): Prohibición de espacios en blanco antes de separadores
   de sintaxis (`;` y `,`)
 * [0x000Bh](0x000Bh.md): Prohibición de espacios en blanco alrededor de
   operadores de acceso a miembros (`->` y `.`)
 * [0x000Ch](0x000Ch.md): Prohibición de espacios en blanco entre operadores
   unarios (`++`, `--`, `!`) y su operando
 * [0x000Dh](0x000Dh.md): Espacio en blanco obligatorio tras la coma separadora
   en listas y argumentos
 * [0x000Eh](0x000Eh.md): Prohibición de espacios en blanco internos
   inmediatamente tras '`(`' o antes de '`)`'
 * [0x000Fh](0x000Fh.md): Prohibición de múltiples espacios en blanco
   consecutivos dentro de una línea de código
 * [0x0010h](0x0010h.md): Prohibición de llaves redundantes en inicialización de
   tipos escalares
 * [0x0011h](0x0011h.md): Validador de espaciado estricto en sentencias de
   control
 * [0x0012h](0x0012h.md): Validador de formato canónico en firmas de punteros a
   función
 * [0x0013h](0x0013h.md): Detector de etiquetas de salto `goto` no alineadas al
   margen izquierdo
 * [0x0014h](0x0014h.md): Auditor de inicialización de arreglos unidimensionales
   con exceso de elementos
 * [0x0015h](0x0015h.md): Validador de espaciado en listas de argumentos y
   llamadas a funciones
 * [0x0016h](0x0016h.md): Validador de espaciado en operadores unarios
 * [0x0017h](0x0017h.md): Agrupá sentencias relacionadas y separá bloques
   lógicos

## Nomenclatura e identificadores (0x01XX)

Reglas de nombrado de identificadores, constantes, archivos y símbolos.

* [0x0101h](0x0101h.md): Los identificadores deben ser descriptivos
* [0x0102h](0x0102h.md): Los argumentos de función y las variables locales deben
  usar `snake_case` en minúsculas
* [0x0103h](0x0103h.md): Las constantes (`const` o `#define`) deben nombrarse en
  `MAYUSCULAS_SNAKE_CASE`
* [0x0104h](0x0104h.md): Los nombres de los archivos deben usar `snake_case` en
  minúsculas (sin espacios)
* [0x0105h](0x0105h.md): Los nombres de funciones deben usar `snake_case`
  estricto en minúsculas
* [0x0106h](0x0106h.md): Las variables globales deben ser declaradas como
  `static` o usar prefijo `g_`
* [0x0107h](0x0107h.md): Las macros `#define` deben nombrarse en
  `MAYUSCULAS_SNAKE_CASE`
* [0x0108h](0x0108h.md): Prohibición de identificadores con caracteres no ASCII
  (acentos, `ñ`)
* [0x0109h](0x0109h.md): Prohibición de identificadores que colisionen con
  palabras clave o tipos estándar
* [0x010Ah](0x010Ah.md): Prohibición de identificadores con prefijos reservados
  para el compilador (`__` o `_[A-Z]`)
* [0x010Bh](0x010Bh.md): Proporcionalidad en longitud de identificadores según
  su alcance
* [0x010Ch](0x010Ch.md): Auditor de identificadores reservados con doble guion
  bajo o guion bajo inicial
* [0x010Dh](0x010Dh.md): Auditor de consistencia en nombres de constantes
  simbólicas
* [0x010Eh](0x010Eh.md): Prescindí de identificadores genéricos con sufijo
  numérico o afijos (`numero1`, `num_1`, `n_a`, `a_n`)
* [0x010Fh](0x010Fh.md): Prohibición de constantes numéricas mágicas en índices
  de arreglos
* [0x0110h](0x0110h.md): Los booleanos se nombran con prefijo interrogativo
  (`es_`, `puede_`, etc)
* [0x0111h](0x0111h.md): Nombrá en positivo y evitá las dobles negaciones
* [0x0112h](0x0112h.md): Usá constantes simbólicas para todo literal con
  significado

## Comentarios, documentacion y organizacion de archivos (0x02XX)

Reglas de comentarios, documentación de archivos y organización del código.

* [0x0201h](0x0201h.md): Escribí comentarios que expliquen el 'porqué', no el
  'qué'
* [0x0202h](0x0202h.md): No dejes código comentado (dead code) en los archivos
  fuente
* [0x0203h](0x0203h.md): Prescindí de comentarios obvios, redundantes o vacíos
* [0x0204h](0x0204h.md): Control de longitud máxima de archivos de código (máx
  500 líneas)
* [0x0205h](0x0205h.md): En archivos `.c` la inclusión de la cabecera propia
  debe figurar en primer lugar
* [0x0206h](0x0206h.md): Validador de presencia de cabecera de documentación
  obligatoria por archivo


## Estructuras de control y flujo (0x10XX)

Reglas sobre condicionales, lazos, bifurcaciones y flujo de ejecuciön.

 * [0x1001h](0x1001h.md): Todas las estructuras de control deben utilizar llaves
 * [0x1002h](0x1002h.md): Restringí el uso de `break` y `continue`; preferí
   lazos con bandera de control
 * [0x1003h](0x1003h.md): Utilizá el lazo for para iteraciones con rango o
   contador definido y while para lazos controlados por condiciones lógicas
 * [0x1004h](0x1004h.md): Las condiciones complejas deben simplificarse o
   comentarse
 * [0x1005h](0x1005h.md): Reemplazá las condiciones ambiguas basadas en la
   'veracidad' (truthiness) del tipo de dato
 * [0x1006h](0x1006h.md): No utilizar la instrucción `goto`
 * [0x1007h](0x1007h.md): No utilizar el operador condicional (ternario) `?:`
 * [0x1008h](0x1008h.md): Toda instrucción `switch` debe incluir un caso default
 * [0x1009h](0x1009h.md): Prohibición de asignaciones simples dentro de
   condiciones lógicas
 * [0x100Ah](0x100Ah.md): Prohibición de estructuras de control con cuerpo vacío
   (`if (...);`)
 * [0x100Bh](0x100Bh.md): No utilices comparaciones en estilo Yoda ('`CONST ==
   variable`')
 * [0x100Ch](0x100Ch.md): Espaciado obligatorio alrededor de operadores
   ternarios ('`? :`')
 * [0x100Dh](0x100Dh.md): Prohibición de condiciones de parada compuestas
   complejas en lazos `for`
 * [0x100Eh](0x100Eh.md): Delimitación obligatoria con bloque de llaves en lazos
   do-while
 * [0x100Fh](0x100Fh.md): Prohibición de cláusula `else` redundante tras
   sentencia de retorno anticipado
 * [0x1010h](0x1010h.md): Prohibición de comparaciones encadenadas no
   idiomáticas en C (`a < b < c`)
 * [0x1011h](0x1011h.md): Prohibición de saltos no estructurados `goto` fuera
   del patrón canónico de liberación de recursos
 * [0x1012h](0x1012h.md): Prohibición de expresiones de asignación dentro de
   estructuras de control
 * [0x1013h](0x1013h.md): Detector de expresiones booleanas complejas sin
   paréntesis aclaratorios
 * [0x1014h](0x1014h.md): Detector de operadores de incremento o decremento
   múltiples en una misma expresión
 * [0x1015h](0x1015h.md): Limitá la profundidad de anidación a tres niveles
 * [0x1016h](0x1016h.md): Documentá el invariante de cada lazo
 * [0x1017h](0x1017h.md): Escribí condiciones afirmativas y directas
 * [0x1018h](0x1018h.md): No uses variables de punto flotante como control de
   lazo

## Funciones, contratos y modularizacion (0x20XX)

Reglas sobre firmas, contratos, responsabilidad única y modularización.

 * [0x2001h](0x2001h.md): Las funciones deben usar cláusulas de guarda y
   retornos anticipados para reducir la anidación profunda
 * [0x2002h](0x2002h.md): Las funciones no deben contener `printf` o `scanf`, a
   menos que ese sea su propósito explícito
 * [0x2003h](0x2003h.md): Todas las funciones deben incluir documentación
   completa y estructurada
 * [0x2004h](0x2004h.md): No se permite el uso de variables globales
 * [0x2005h](0x2005h.md): Cada función debe tener una única responsabilidad
   (Principio de Responsabilidad Única)
 * [0x2006h](0x2006h.md): Mantené el alcance de las variables al mínimo posible
 * [0x2007h](0x2007h.md): Los valores de retorno numéricos deben definirse como
   constantes de preprocesador o `enum`s
 * [0x2008h](0x2008h.md): Los ejercicios deben ser resueltos mediante funciones
 * [0x2009h](0x2009h.md): Los nombres de funciones y procedimientos deben usar
   `snake_case` en minúsculas
 * [0x200Ah](0x200Ah.md): Modularización: una función no debe exceder 4
   parámetros de entrada
 * [0x200Bh](0x200Bh.md): Prohibición de retornar la dirección de una variable
   local de stack
 * [0x200Ch](0x200Ch.md): Cada función debe tener a lo sumo un `return`
 * [0x200Dh](0x200Dh.md): Comentarios de cierre explicativos en bloques de
   control extensos (> 25 líneas)
 * [0x200Eh](0x200Eh.md): Uso obligatorio de '`void`' explícito en funciones sin
   parámetros
 * [0x200Fh](0x200Fh.md): Prohibición de paréntesis superfluos en sentencia
   `return`
 * [0x2010h](0x2010h.md): Prohibición de reasignar o modificar parámetros
   recibidos por valor dentro de la función
 * [0x2011h](0x2011h.md): Prohibición de asignaciones múltiples a una variable
   sin lectura intermedia (dead store)
 * [0x2012h](0x2012h.md): Tipo de retorno obligatorio '`int`' en la función
   `main()`
 * [0x2013h](0x2013h.md): Detector de bloques `else` superfluos tras sentencias
   terminales
 * [0x2014h](0x2014h.md): Cada función debe caber en una sola idea y en 25
   líneas
 * [0x2015h](0x2015h.md): No dupliques lógica: extraé una función
 * [0x2016h](0x2016h.md): Escribí el contrato de la función antes de
   implementarla
 * [0x2017h](0x2017h.md): Toda función recursiva debe tener un caso base
   explícito
 * [0x2018h](0x2018h.md): Los comparadores no deben usar resta sujeta a
   desbordamiento


## Memoria, punteros y tipos (0x30XX)

Reglas sobre punteros, memoria dinámica, tipos, const y TADs.

 * [0x3001h](0x3001h.md): Siempre verificá la asignación exitosa de memoria
   dinámica
 * [0x3002h](0x3002h.md): Liberá siempre la memoria dinámica y asigná `NULL` al
   puntero para mitigar punteros colgantes
 * [0x3003h](0x3003h.md): No mezcles operaciones de asignación y comparación en
   una sola línea
 * [0x3004h](0x3004h.md): Utilizá `typedef` para definir tipos de estructuras
   con el sufijo `_t`
 * [0x3005h](0x3005h.md): Minimizá el uso de múltiples niveles de indirección
   (punteros a punteros)
 * [0x3006h](0x3006h.md): Documentá la propiedad de los recursos al utilizar
   punteros
 * [0x3007h](0x3007h.md): Los argumentos de tipo puntero deben ser `const`
   siempre que la función no los modifique
 * [0x3008h](0x3008h.md): Los punteros nulos deben ser inicializados y
   comparados con `NULL`, no con `0`
 * [0x3009h](0x3009h.md): Documentá explícitamente los casos en que una función
   puede retornar `NULL`
 * [0x300Ah](0x300Ah.md): Utilizá cast explícito al convertir tipos de punteros
 * [0x300Bh](0x300Bh.md): Usá siempre `sizeof` en las asignaciones de memoria
   dinámica, prefiriendo `sizeof(*ptr)`
 * [0x300Ch](0x300Ch.md): Verificá siempre los límites de los arreglos antes de
   acceder a sus elementos
 * [0x300Dh](0x300Dh.md): Utilizá `enum` en lugar de 'números mágicos' para
   conjuntos de estados y valores constantes
 * [0x300Eh](0x300Eh.md): Documentá explícitamente el comportamiento de las
   funciones al manejar punteros nulos como argumentos
 * [0x300Fh](0x300Fh.md): Liberá la memoria en el orden inverso a su asignación
 * [0x3010h](0x3010h.md): Las variables que representan tamaños o índices de
   arreglos deben ser de tipo `size_t`
 * [0x3011h](0x3011h.md): Si una función recibe un puntero genérico para
   operaciones de solo lectura, la firma de la función debe utilizar `const
   void*`
 * [0x3012h](0x3012h.md): Prohibición de aritmética de punteros sobre `void*`
 * [0x3013h](0x3013h.md): Asignación de memoria con `sizeof` sobre puntero en
   lugar del tipo apuntado
 * [0x3014h](0x3014h.md): Prohibición de doble liberación de memoria (double
   free) sobre el mismo puntero
 * [0x3015h](0x3015h.md): Reallocación segura: no sobreescribir el puntero
   original directamente
 * [0x3016h](0x3016h.md): Orden incorrecto o sospechoso de argumentos en
   llamadas a `memset`
 * [0x3017h](0x3017h.md): Orden canónico de calificadores: '`const tipo`' en
   lugar de '`tipo const`'
 * [0x3018h](0x3018h.md): Inicialización idiomática de agregados con `{0}` en
   lugar de `memset` inmediato
 * [0x3019h](0x3019h.md): Prohibición de comparar punteros contra constantes
   numéricas distintas de `NULL` o cero
 * [0x301Ah](0x301Ah.md): Validador de uso idiomático de tipos booleanos
   estándar
 * [0x301Bh](0x301Bh.md): Prohibición de casts de tipo innecesarios o
   redundantes
 * [0x301Ch](0x301Ch.md): Detector de variables locales no inicializadas con
   modificador `const`
 * [0x301Dh](0x301Dh.md): Diseñá los Tipos de Datos Abstractos utilizando
   punteros opacos
 * [0x301Eh](0x301Eh.md): Asigná `NULL` al puntero tras liberar un recurso opaco
   en el ámbito del cliente
 * [0x301Fh](0x301Fh.md): No compares números de punto flotante con igualdad
   exacta


## Archivos y E/S (0x40XX)

Reglas sobre flujos de archivo, lectura/escritura y reporte de errores.

* [0x4001h](0x4001h.md): Manejá correctamente la apertura y cierre de archivos
* [0x4002h](0x4002h.md): Validá los retornos de las operaciones de lectura y
  escritura de archivos
* [0x4003h](0x4003h.md): Utilizá `errno`, `perror` y `strerror` para reportar
  fallos del sistema operativo de manera precisa
* [0x4004h](0x4004h.md): Mantené la simetría de recursos al abrir y cerrar
  archivos en el mismo nivel de abstracción
* [0x4005h](0x4005h.md): Prescindí del uso de offsets y posiciones fijas
  codificadas a mano en archivos binarios sin validar sus dimensiones
* [0x4006h](0x4006h.md): Prohibición del antipatrón `while (!feof(f))` para
  control de fin de archivo
* [0x4007h](0x4007h.md): Prohibición de rutas absolutas hardcodeadas en llamadas
  de archivo
* [0x4008h](0x4008h.md): Validación obligatoria del valor de retorno de
  `fclose()` en modo escritura
* [0x4009h](0x4009h.md): Prohibición de anidar llamadas a `fopen()` directamente
  dentro de funciones de E/S
* [0x400Ah](0x400Ah.md): Prohibición de operar sobre flujos de archivos tras
  haber invocado `fclose()` (use-after-close)
* [0x400Bh](0x400Bh.md): No uses `fflush(stdin)`; consumí el buffer con
  `getchar()`
* [0x400Ch](0x400Ch.md): Los formatos de `printf`/`scanf` deben coincidir y no
  ser variables

## Compilacion, preprocesador y seguridad (0x50XX)

Reglas sobre compilación, preprocesador, cabeceras y seguridad estática.

 * [0x5001h](0x5001h.md): Los arreglos estáticos deben ser creados con un tamaño
   fijo en tiempo de compilación
 * [0x5002h](0x5002h.md): Desarrollá y compilá siempre con todas las
   advertencias del compilador activadas
 * [0x5003h](0x5003h.md): Utilizá guardas de inclusión en todos los archivos de
   cabecera
 * [0x5004h](0x5004h.md): Todas las operaciones con cadenas deben ser seguras
 * [0x5005h](0x5005h.md): Organizá la estructura de tus archivos `.c` de forma
   estándar
 * [0x5006h](0x5006h.md): Preferí `fgets` sobre `gets` y `scanf` para leer
   cadenas
 * [0x5007h](0x5007h.md): Inclusiones redundantes o duplicadas de la misma
   cabecera `#include`
 * [0x5008h](0x5008h.md): Prohibición de funciones obsoletas o inseguras
   (`gets`, `atoi`)
 * [0x5009h](0x5009h.md): Prohibición de división entera no intencional asignada
   a flotantes
 * [0x500Ah](0x500Ah.md): Protección obligatoria de parámetros en macros
   funcionales mediante paréntesis
 * [0x500Bh](0x500Bh.md): Inclusión obligatoria de cabeceras estándar para
   funciones de la biblioteca C
 * [0x500Ch](0x500Ch.md): Prohibición de inclusión directa de archivos de código
   fuente C (`.c`)
 * [0x500Dh](0x500Dh.md): Prohibición de redefinir palabras clave o tipos
   primitivos de C con `#define`
 * [0x500Eh](0x500Eh.md): Prohibición de la biblioteca obsoleta y no estándar
   `<conio.h>` (`getch`, `clrscr`)
 * [0x500Fh](0x500Fh.md): Colisión de nombres de macroguardas entre archivos de
   cabecera distintos
 * [0x5010h](0x5010h.md): Prohibición de directivas `#pragma` no estándar o
   privativas
 * [0x5011h](0x5011h.md): Prohibición de declaraciones `extern` en archivos de
   implementación (`.c`)
 * [0x5012h](0x5012h.md): Detección de inclusiones cíclicas entre archivos de
   cabecera
 * [0x5013h](0x5013h.md): Protección obligatoria con paréntesis envolventes en
   expresiones de macroconstantes (`#define`)
 * [0x5014h](0x5014h.md): Inclusión explícita obligatoria de cabeceras para
   funciones de biblioteca estándar
 * [0x5015h](0x5015h.md): No invoques el intérprete de comandos con `system()` o
   `popen()`

## Proceso, diseno y construccion sistematica (0x60XX)

Reglas de método: como diseñar y construir código de calidad paso a paso.

 * [0x6001h](0x6001h.md): Diseñá el algoritmo antes de escribir código en C
 * [0x6002h](0x6002h.md): Compilá con frecuencia y resolvé el primer error antes
   de continuar
 * [0x6003h](0x6003h.md): Declará cada variable lo más cerca posible de su
   primer uso
 * [0x6004h](0x6004h.md): No reutilices una variable para propósitos distintos
 * [0x6005h](0x6005h.md): No optimices prematuramente

## Robustez y manejo de errores (0x70XX)

Reglas de robustez, validación e inicialización defensiva.

 * [0x7001h](0x7001h.md): Siempre debés inicializar las variables a un valor
   conocido
 * [0x7002h](0x7002h.md): Validá los datos en la frontera del programa
 * [0x7003h](0x7003h.md): No ignores valores de retorno que pueden indicar fallo
 * [0x7004h](0x7004h.md): No llamés `exit()` en funciones de biblioteca: propagá
   el error
 * [0x7005h](0x7005h.md): Inicializá todos los campos de estructuras y arreglos
 * [0x7006h](0x7006h.md): Probá explícitamente los casos borde
 * [0x7007h](0x7007h.md): Evitá los parámetros bandera de tipo `bool`

## Verificacion, testing y depuracion (0x80XX)

Reglas de verificacion, testing y depuracion antes de la entrega.

 * [0x8001h](0x8001h.md): Una aserción por cada función de prueba
 * [0x8002h](0x8002h.md): Escribí al menos una prueba por cláusula del contrato
 * [0x8003h](0x8003h.md): Verificá con `gcc`, `gdb` y `valgrind` antes de
   entregar
 * [0x8004h](0x8004h.md): Ejecutá la lista de verificación de calidad antes de
   entregar
