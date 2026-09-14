---
title: "Registro de Renumeración del Catálogo"
short_title: "Registro de renumeración"
subtitle: "Mapeo de códigos viejos a nuevos para la refactorización de gaff"
---

(registro-renumeracion)=
# Registro de Renumeración del Catálogo

Este documento registra **todos** los cambios de numeración del catálogo de reglas.
Su consumidor es la herramienta `gaff`: cada código viejo que la herramienta emite
debe reemplazarse por el código nuevo, y cada `AP-0xXXXXh` debe pasar a ser el
código de la regla que lo absorbe. La versión machine-readable es
[`renumeracion.json`](renumeracion.json).

## Categorías y prefijos

| Prefijo | Categoría | Directorio | Reglas |
| :--- | :--- | :--- | :--- |
| `0x00XX` | Sintaxis y formato visual | `reglas/00_formato/` | 23 |
| `0x01XX` | Nomenclatura e identificadores | `reglas/01_nomenclatura/` | 18 |
| `0x02XX` | Comentarios, documentacion y organizacion de archivos | `reglas/02_documentacion/` | 6 |
| `0x10XX` | Estructuras de control y flujo | `reglas/10_control/` | 24 |
| `0x20XX` | Funciones, contratos y modularizacion | `reglas/20_funciones/` | 24 |
| `0x30XX` | Memoria, punteros y tipos | `reglas/30_memoria/` | 31 |
| `0x40XX` | Archivos y E/S | `reglas/40_archivos/` | 12 |
| `0x50XX` | Compilacion, preprocesador y seguridad | `reglas/50_seguridad/` | 21 |
| `0x60XX` | Proceso, diseno y construccion sistematica | `reglas/60_proceso/` | 5 |
| `0x70XX` | Robustez y manejo de errores | `reglas/70_robustez/` | 7 |
| `0x80XX` | Verificacion, testing y depuracion | `reglas/80_verificacion/` | 4 |

## Renumeración de reglas

| Código viejo | Código nuevo | Tipo | Título |
| :--- | :--- | :--- | :--- |
| `0x0000h` | `0x0001h` | renumerada | La claridad y prolijidad son de máxima importancia |
| `0x0002h` | `0x0002h` | renumerada | Una declaración de variable por línea |
| `0x0004h` | `0x0003h` | renumerada | Un espacio antes y después de cada operador binario |
| `0x0005h` | `0x0004h` | renumerada | Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves |
| `0x0006h` | `0x0005h` | renumerada | El asterisco de los punteros debe declararse junto al identificador |
| `0x0009h` | `0x0006h` | renumerada | Las líneas de código no deben exceder los 79 caracteres |
| `0x000Bh` | `0x0007h` | renumerada | Las llaves deben ubicarse en líneas independientes según el estilo Allman |
| `0x0015h` | `0x0008h` | renumerada | Alineación vertical consistente en asignaciones y declaraciones consecutivas |
| `0x0017h` | `0x0009h` | renumerada | Espaciado consistente en declaraciones de doble puntero (tipo **var) |
| `0x0019h` | `0x000Ah` | renumerada | Prohibición de espacios en blanco antes de separadores de sintaxis (; y ,) |
| `0x001Ah` | `0x000Bh` | renumerada | Prohibición de espacios en blanco alrededor de operadores de acceso a miembros (-> y .) |
| `0x001Bh` | `0x000Ch` | renumerada | Prohibición de espacios en blanco entre operadores unarios (++, --, !) y su operando |
| `0x001Ch` | `0x000Dh` | renumerada | Espacio en blanco obligatorio tras la coma separadora en listas y argumentos |
| `0x001Dh` | `0x000Eh` | renumerada | Prohibición de espacios en blanco internos inmediatamente tras '(' o antes de ')' |
| `0x001Eh` | `0x000Fh` | renumerada | Prohibición de múltiples espacios en blanco consecutivos dentro de una línea de código |
| `0x001Fh` | `0x0010h` | renumerada | Prohibición de llaves redundantes en inicialización de tipos escalares |
| `0x0022h` | `0x0011h` | renumerada | Validador de espaciado estricto en sentencias de control |
| `0x0025h` | `0x0012h` | renumerada | Validador de formato canónico en firmas de punteros a función |
| `0x0028h` | `0x0013h` | renumerada | Detector de etiquetas de salto goto no alineadas al margen izquierdo |
| `0x0029h` | `0x0014h` | renumerada | Auditor de inicialización de arreglos unidimensionales con exceso de elementos |
| `0x002Bh` | `0x0015h` | renumerada | Validador de espaciado en listas de argumentos y llamadas a funciones |
| `0x002Dh` | `0x0016h` | renumerada | Validador de espaciado en operadores unarios |
| `0x600Eh` | `0x0017h` | propuesta-integrada | Agrupá sentencias relacionadas y separá bloques lógicos |
| `0x0001h` | `0x0101h` | renumerada | Los identificadores deben ser descriptivos |
| `0x0007h` | `0x0102h` | renumerada | Los argumentos de función y las variables locales deben usar snake_case en minúsculas |
| `0x0008h` | `0x0103h` | renumerada | Las constantes (const o #define) deben nombrarse en MAYUSCULAS_SNAKE_CASE |
| `0x000Ch` | `0x0104h` | renumerada | Los nombres de los archivos deben usar snake_case en minúsculas (sin espacios) |
| `0x000Eh` | `0x0105h` | renumerada | Los nombres de funciones deben usar snake_case estricto en minúsculas |
| `0x0012h` | `0x0106h` | renumerada | Las variables globales deben ser declaradas como static o usar prefijo g_ |
| `0x0013h` | `0x0107h` | renumerada | Las macros #define deben nombrarse en MAYUSCULAS_SNAKE_CASE |
| `0x0014h` | `0x0108h` | renumerada | Prohibición de identificadores con caracteres no ASCII (acentos, ñ) |
| `0x0016h` | `0x0109h` | renumerada | Prohibición de identificadores que colisionen con palabras clave o tipos estándar |
| `0x0018h` | `0x010Ah` | renumerada | Prohibición de identificadores con prefijos reservados para el compilador (__ o _[A-Z]) |
| `0x0020h` | `0x010Bh` | renumerada | Proporcionalidad en longitud de identificadores según su alcance |
| `0x0026h` | `0x010Ch` | renumerada | Auditor de identificadores reservados con doble guion bajo o guion bajo inicial |
| `0x002Ch` | `0x010Dh` | renumerada | Auditor de consistencia en nombres de constantes simbólicas |
| `0x0037h` | `0x010Eh` | renumerada | Prescindí de identificadores genéricos con sufijo numérico o afijos (numero1, num_1, n_a, a_n) |
| `0x0038h` | `0x010Fh` | renumerada | Prohibición de constantes numéricas mágicas en índices de arreglos |
| `0x6009h` | `0x0110h` | propuesta-integrada | Los booleanos se nombran con prefijo interrogativo |
| `0x600Ah` | `0x0111h` | propuesta-integrada | Nombrá en positivo y evitá las dobles negaciones |
| `0x600Bh` | `0x0112h` | propuesta-integrada | Usá constantes simbólicas para todo literal con significado |
| `0x000Ah` | `0x0201h` | renumerada | Escribí comentarios que expliquen el 'porqué', no el 'qué' |
| `0x000Dh` | `0x0202h` | renumerada | No dejes código comentado (dead code) en los archivos fuente |
| `0x000Fh` | `0x0203h` | renumerada | Prescindí de comentarios obvios, redundantes o vacíos |
| `0x0010h` | `0x0204h` | renumerada | Control de longitud máxima de archivos de código (máx 500 líneas) |
| `0x0011h` | `0x0205h` | renumerada | En archivos .c la inclusión de la cabecera propia debe figurar en primer lugar |
| `0x0027h` | `0x0206h` | renumerada | Validador de presencia de cabecera de documentación obligatoria por archivo |
| `0x1001h` | `0x1001h` | renumerada | Todas las estructuras de control deben utilizar llaves |
| `0x1002h` | `0x1002h` | renumerada | Restringí el uso de break y continue; preferí lazos con bandera de control |
| `0x1003h` | `0x1003h` | renumerada | Utilizá el lazo for para iteraciones con rango o contador definido y while para lazos controlados por condiciones lógicas |
| `0x1004h` | `0x1004h` | renumerada | Las condiciones complejas deben simplificarse o comentarse |
| `0x1005h` | `0x1005h` | renumerada | Reemplazá las condiciones ambiguas basadas en la 'veracidad' (truthiness) del tipo de dato |
| `0x1006h` | `0x1006h` | renumerada | No utilizar la instrucción goto |
| `0x1007h` | `0x1007h` | renumerada | No utilizar el operador condicional (ternario) ?: |
| `0x1008h` | `0x1008h` | renumerada | Toda instrucción switch debe incluir un caso default |
| `0x100Ah` | `0x1009h` | renumerada | Prohibición de asignaciones simples dentro de condiciones lógicas |
| `0x100Bh` | `0x100Ah` | renumerada | Prohibición de estructuras de control con cuerpo vacío (if (...);) |
| `0x100Ch` | `0x100Bh` | renumerada | No utilices comparaciones en estilo Yoda ('CONST == variable') |
| `0x100Eh` | `0x100Ch` | renumerada | Espaciado obligatorio alrededor de operadores ternarios ('? :') |
| `0x100Fh` | `0x100Dh` | renumerada | Prohibición de condiciones de parada compuestas complejas en lazos for |
| `0x1010h` | `0x100Eh` | renumerada | Delimitación obligatoria con bloque de llaves en lazos do-while |
| `0x1011h` | `0x100Fh` | renumerada | Prohibición de cláusula else redundante tras sentencia de retorno anticipado |
| `0x1012h` | `0x1010h` | renumerada | Prohibición de comparaciones encadenadas no idiomáticas en C (a < b < c) |
| `0x1013h` | `0x1011h` | renumerada | Prohibición de saltos no estructurados goto fuera del patrón canónico de liberación de recursos |
| `0x1014h` | `0x1012h` | renumerada | Prohibición de expresiones de asignación dentro de estructuras de control |
| `0x1016h` | `0x1013h` | renumerada | Detector de expresiones booleanas complejas sin paréntesis aclaratorios |
| `0x1017h` | `0x1014h` | renumerada | Detector de operadores de incremento o decremento múltiples en una misma expresión |
| `0x6004h` | `0x1015h` | propuesta-integrada | Limitá la profundidad de anidación a tres niveles |
| `0x600Ch` | `0x1016h` | propuesta-integrada | Documentá el invariante de cada lazo |
| `0x600Dh` | `0x1017h` | propuesta-integrada | Escribí condiciones afirmativas y directas |
| `0x1018h` | `0x1018h` | promovida | No uses variables de punto flotante como control de lazo |
| `0x2001h` | `0x2001h` | renumerada | Las funciones deben usar cláusulas de guarda y retornos anticipados para reducir la anidación profunda |
| `0x2002h` | `0x2002h` | renumerada | Las funciones no deben contener printf o scanf, a menos que ese sea su propósito explícito |
| `0x2003h` | `0x2003h` | renumerada | Todas las funciones deben incluir documentación completa y estructurada |
| `0x2004h` | `0x2004h` | renumerada | No se permite el uso de variables globales |
| `0x2005h` | `0x2005h` | renumerada | Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única) |
| `0x2007h` | `0x2006h` | renumerada | Mantené el alcance de las variables al mínimo posible |
| `0x2008h` | `0x2007h` | renumerada | Los valores de retorno numéricos deben definirse como constantes de preprocesador o enums |
| `0x2009h` | `0x2008h` | renumerada | Los ejercicios deben ser resueltos mediante funciones |
| `0x200Ah` | `0x2009h` | renumerada | Los nombres de funciones y procedimientos deben usar snake_case en minúsculas |
| `0x200Bh` | `0x200Ah` | renumerada | Modularización: una función no debe exceder 4 parámetros de entrada |
| `0x200Ch` | `0x200Bh` | renumerada | Prohibición de retornar la dirección de una variable local de stack |
| `0x200Dh` | `0x200Ch` | renumerada | Cada función debe tener a lo sumo un return |
| `0x200Eh` | `0x200Dh` | renumerada | Comentarios de cierre explicativos en bloques de control extensos (> 25 líneas) |
| `0x200Fh` | `0x200Eh` | renumerada | Uso obligatorio de 'void' explícito en funciones sin parámetros |
| `0x2010h` | `0x200Fh` | renumerada | Prohibición de paréntesis superfluos en sentencia return |
| `0x2011h` | `0x2010h` | renumerada | Prohibición de reasignar o modificar parámetros recibidos por valor dentro de la función |
| `0x2012h` | `0x2011h` | renumerada | Prohibición de asignaciones múltiples a una variable sin lectura intermedia (dead store) |
| `0x2013h` | `0x2012h` | renumerada | Tipo de retorno obligatorio 'int' en la función main() |
| `0x2016h` | `0x2013h` | renumerada | Detector de bloques else superfluos tras sentencias terminales |
| `0x6003h` | `0x2014h` | propuesta-integrada | Cada función debe caber en una sola idea y en 25 líneas |
| `0x6007h` | `0x2015h` | propuesta-integrada | No dupliques lógica: extraé una función |
| `0x6008h` | `0x2016h` | propuesta-integrada | Escribí el contrato de la función antes de implementarla |
| `0x2017h` | `0x2017h` | promovida | Toda funcion recursiva debe tener un caso base explicito |
| `0x2018h` | `0x2018h` | promovida | Los comparadores no deben usar resta sujeta a desbordamiento |
| `0x3001h` | `0x3001h` | renumerada | Siempre verificá la asignación exitosa de memoria dinámica |
| `0x3002h` | `0x3002h` | renumerada | Liberá siempre la memoria dinámica y asigná NULL al puntero para mitigar punteros colgantes |
| `0x3003h` | `0x3003h` | renumerada | No mezcles operaciones de asignación y comparación en una sola línea |
| `0x3004h` | `0x3004h` | renumerada | Utilizá typedef para definir tipos de estructuras con el sufijo _t |
| `0x3005h` | `0x3005h` | renumerada | Minimizá el uso de múltiples niveles de indirección (punteros a punteros) |
| `0x3006h` | `0x3006h` | renumerada | Documentá la propiedad de los recursos al utilizar punteros |
| `0x3007h` | `0x3007h` | renumerada | Los argumentos de tipo puntero deben ser const siempre que la función no los modifique |
| `0x3008h` | `0x3008h` | renumerada | Los punteros nulos deben ser inicializados y comparados con NULL, no con 0 |
| `0x3009h` | `0x3009h` | renumerada | Documentá explícitamente los casos en que una función puede retornar NULL |
| `0x300Ah` | `0x300Ah` | renumerada | Utilizá cast explícito al convertir tipos de punteros |
| `0x300Bh` | `0x300Bh` | renumerada | Usá siempre sizeof en las asignaciones de memoria dinámica, prefiriendo sizeof(*ptr) |
| `0x300Ch` | `0x300Ch` | renumerada | Verificá siempre los límites de los arreglos antes de acceder a sus elementos |
| `0x300Dh` | `0x300Dh` | renumerada | Utilizá enum en lugar de 'números mágicos' para conjuntos de estados y valores constantes |
| `0x300Eh` | `0x300Eh` | renumerada | Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos |
| `0x300Fh` | `0x300Fh` | renumerada | Liberá la memoria en el orden inverso a su asignación |
| `0x3010h` | `0x3010h` | renumerada | Las variables que representan tamaños o índices de arreglos deben ser de tipo size_t |
| `0x3011h` | `0x3011h` | renumerada | Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar const void* |
| `0x3012h` | `0x3012h` | renumerada | Prohibición de aritmética de punteros sobre void* |
| `0x3013h` | `0x3013h` | renumerada | Asignación de memoria con sizeof sobre puntero en lugar del tipo apuntado |
| `0x3014h` | `0x3014h` | renumerada | Prohibición de doble liberación de memoria (double free) sobre el mismo puntero |
| `0x3015h` | `0x3015h` | renumerada | Reallocación segura: no sobreescribir el puntero original directamente |
| `0x3016h` | `0x3016h` | renumerada | Orden incorrecto o sospechoso de argumentos en llamadas a memset |
| `0x3017h` | `0x3017h` | renumerada | Orden canónico de calificadores: 'const tipo' en lugar de 'tipo const' |
| `0x3018h` | `0x3018h` | renumerada | Inicialización idiomática de agregados con {0} en lugar de memset inmediato |
| `0x3019h` | `0x3019h` | renumerada | Prohibición de comparar punteros contra constantes numéricas distintas de NULL o cero |
| `0x301Ah` | `0x301Ah` | renumerada | Validador de uso idiomático de tipos booleanos estándar |
| `0x100Dh` | `0x301Bh` | renumerada | Prohibición de casts de tipo innecesarios o redundantes |
| `0x0023h` | `0x301Ch` | renumerada | Detector de variables locales no inicializadas con modificador const |
| `0x0035h` | `0x301Dh` | renumerada | Diseñá los Tipos de Datos Abstractos utilizando punteros opacos |
| `0x0036h` | `0x301Eh` | renumerada | Asigná NULL al puntero tras liberar un recurso opaco en el ámbito del cliente |
| `0x301Fh` | `0x301Fh` | promovida | No compares numeros de punto flotante con igualdad exacta |
| `0x4001h` | `0x4001h` | renumerada | Manejá correctamente la apertura y cierre de archivos |
| `0x4002h` | `0x4002h` | renumerada | Validá los retornos de las operaciones de lectura y escritura de archivos |
| `0x4003h` | `0x4003h` | renumerada | Utilizá errno, perror y strerror para reportar fallos del sistema operativo de manera precisa |
| `0x4004h` | `0x4004h` | renumerada | Mantené la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción |
| `0x4005h` | `0x4005h` | renumerada | Prescindí del uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones |
| `0x4006h` | `0x4006h` | renumerada | Prohibición del antipatrón while (!feof(f)) para control de fin de archivo |
| `0x4007h` | `0x4007h` | renumerada | Prohibición de rutas absolutas hardcodeadas en llamadas de archivo |
| `0x4008h` | `0x4008h` | renumerada | Validación obligatoria del valor de retorno de fclose() en modo escritura |
| `0x4009h` | `0x4009h` | renumerada | Prohibición de anidar llamadas a fopen() directamente dentro de funciones de E/S |
| `0x400Ah` | `0x400Ah` | renumerada | Prohibición de operar sobre flujos de archivo tras haber invocado fclose() (use-after-close) |
| `0x400Bh` | `0x400Bh` | promovida | No uses fflush(stdin); consumi el buffer con getchar() |
| `0x400Ch` | `0x400Ch` | promovida | Los formatos de printf/scanf deben coincidir y no ser variables |
| `0x5001h` | `0x5001h` | renumerada | Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación |
| `0x5002h` | `0x5002h` | renumerada | Desarrollá y compilá siempre con todas las advertencias del compilador activadas |
| `0x5003h` | `0x5003h` | renumerada | Utilizá guardas de inclusión en todos los archivos de cabecera |
| `0x5004h` | `0x5004h` | renumerada | Todas las operaciones con cadenas deben ser seguras |
| `0x5005h` | `0x5005h` | renumerada | Organizá la estructura de tus archivos .c de forma estándar |
| `0x5006h` | `0x5006h` | renumerada | Preferí fgets sobre gets y scanf para leer cadenas |
| `0x5007h` | `0x5007h` | renumerada | Inclusiones redundantes o duplicadas de la misma cabecera #include |
| `0x5008h` | `0x5008h` | renumerada | Prohibición de funciones obsoletas o inseguras (gets, atoi) |
| `0x5009h` | `0x5009h` | renumerada | Prohibición de división entera no intencional asignada a flotantes |
| `0x500Ah` | `0x500Ah` | renumerada | Protección obligatoria de parámetros en macros funcionales mediante paréntesis |
| `0x500Bh` | `0x500Bh` | renumerada | Inclusión obligatoria de cabeceras estándar para funciones de la biblioteca C |
| `0x500Ch` | `0x500Ch` | renumerada | Prohibición de inclusión directa de archivos de código fuente C (.c) |
| `0x500Dh` | `0x500Dh` | renumerada | Prohibición de redefinir palabras clave o tipos primitivos de C con #define |
| `0x500Eh` | `0x500Eh` | renumerada | Prohibición de la biblioteca obsoleta y no estándar <conio.h> (getch, clrscr) |
| `0x5011h` | `0x500Fh` | renumerada | Colisión de nombres de macroguardas entre archivos de cabecera distintos |
| `0x5012h` | `0x5010h` | renumerada | Prohibición de directivas #pragma no estándar o privativas |
| `0x5013h` | `0x5011h` | renumerada | Prohibición de declaraciones extern en archivos de implementación (.c) |
| `0x5014h` | `0x5012h` | renumerada | Detección de inclusiones cíclicas entre archivos de cabecera |
| `0x5015h` | `0x5013h` | renumerada | Protección obligatoria con paréntesis envolventes en expresiones de macroconstantes (#define) |
| `0x5016h` | `0x5014h` | renumerada | Inclusión explícita obligatoria de cabeceras para funciones de biblioteca estándar |
| `0x5015h` | `0x5015h` | promovida | No invoques el interprete de comandos con system() o popen() |
| `0x6001h` | `0x6001h` | propuesta-integrada | Diseñá el algoritmo antes de escribir código en C |
| `0x6002h` | `0x6002h` | propuesta-integrada | Compilá con frecuencia y resolvé el primer error antes de continuar |
| `0x6005h` | `0x6003h` | propuesta-integrada | Declará cada variable lo más cerca posible de su primer uso |
| `0x6006h` | `0x6004h` | propuesta-integrada | No reutilices una variable para propósitos distintos |
| `0x600Fh` | `0x6005h` | propuesta-integrada | No optimices prematuramente |
| `0x0003h` | `0x7001h` | renumerada | Siempre debés inicializar las variables a un valor conocido |
| `0x6010h` | `0x7002h` | propuesta-integrada | Validá los datos en la frontera del programa |
| `0x6011h` | `0x7003h` | propuesta-integrada | No ignores valores de retorno que pueden indicar fallo |
| `0x6012h` | `0x7004h` | propuesta-integrada | No llamés exit() en funciones de biblioteca: propagá el error |
| `0x6013h` | `0x7005h` | propuesta-integrada | Inicializá todos los campos de estructuras y arreglos |
| `0x6014h` | `0x7006h` | propuesta-integrada | Probá explícitamente los casos borde |
| `0x6015h` | `0x7007h` | propuesta-integrada | Evitá los parámetros bandera de tipo bool |
| `0x2006h` | `0x8001h` | renumerada | Una aserción por cada función de prueba |
| `0x6016h` | `0x8002h` | propuesta-integrada | Escribí al menos una prueba por cláusula del contrato |
| `0x6017h` | `0x8003h` | propuesta-integrada | Verificá con gcc, gdb y valgrind antes de entregar |
| `0x6018h` | `0x8004h` | propuesta-integrada | Ejecutá la lista de verificación de calidad antes de entregar |

## Antipatrones integrados

Cada antipatrón deja de tener código propio y pasa a documentarse dentro de la regla
indicada. `gaff` debe emitir el código nuevo de esa regla.

| Código AP viejo | Regla nueva | Acción |
| :--- | :--- | :--- |
| `AP-0x0003b` | `0x7001h` | integrado |
| `AP-0x0004b` | `0x7001h` | integrado |
| `AP-0x0039h` | `0x500Dh` | integrado |
| `AP-0x1001h` | `0x1001h` | integrado |
| `AP-0x1005h` | `0x1005h` | integrado |
| `AP-0x100Ah` | `0x1009h` | integrado |
| `AP-0x100Ch` | `0x1008h` | integrado |
| `AP-0x100Dh` | `0x1018h` | promovido-a-regla |
| `AP-0x100Eh` | `0x1013h` | integrado |
| `AP-0x100Fh` | `0x100Dh` | integrado |
| `AP-0x1010h` | `0x1012h` | integrado |
| `AP-0x1011h` | `0x301Fh` | promovido-a-regla |
| `AP-0x1014h` | `0x100Dh` | integrado |
| `AP-0x1015h` | `0x1003h` | integrado |
| `AP-0x1016h` | `0x1013h` | integrado |
| `AP-0x1017h` | `0x2015h` | integrado |
| `AP-0x1018h` | `0x1001h` | integrado |
| `AP-0x1019h` | `0x1006h` | integrado |
| `AP-0x101Ah` | `0x1005h` | integrado |
| `AP-0x101Bh` | `0x1005h` | integrado |
| `AP-0x101Ch` | `0x1002h` | integrado |
| `AP-0x2007h` | `0x2006h` | integrado |
| `AP-0x2009h` | `0x2017h` | promovido-a-regla |
| `AP-0x200Bh` | `0x200Ah` | integrado |
| `AP-0x2011h` | `0x2017h` | promovido-a-regla |
| `AP-0x2012h` | `0x2018h` | promovido-a-regla |
| `AP-0x2013h` | `0x7003h` | integrado |
| `AP-0x3001h` | `0x3001h` | integrado |
| `AP-0x3002b` | `0x3002h` | integrado |
| `AP-0x3002h` | `0x3002h` | integrado |
| `AP-0x3008h` | `0x3008h` | integrado |
| `AP-0x300Ah` | `0x300Ah` | integrado |
| `AP-0x300Dh` | `0x300Dh` | integrado |
| `AP-0x300Fh` | `0x3013h` | integrado |
| `AP-0x3015h` | `0x3015h` | integrado |
| `AP-0x3019h` | `0x300Bh` | integrado |
| `AP-0x301Ah` | `0x3016h` | integrado |
| `AP-0x301Bh` | `0x3001h` | integrado |
| `AP-0x301Ch` | `0x300Ah` | integrado |
| `AP-0x301Dh` | `0x3008h` | integrado |
| `AP-0x301Eh` | `0x300Bh` | integrado |
| `AP-0x301Fh` | `0x3001h` | integrado |
| `AP-0x3020h` | `0x300Ah` | integrado |
| `AP-0x3021h` | `0x3002h` | integrado |
| `AP-0x3022h` | `0x3002h` | integrado |
| `AP-0x3023h` | `0x3001h` | integrado |
| `AP-0x3024h` | `0x3001h` | integrado |
| `AP-0x3025h` | `0x3002h` | integrado |
| `AP-0x3026h` | `0x3001h` | integrado |
| `AP-0x3027h` | `0x300Bh` | integrado |
| `AP-0x3028h` | `0x300Ah` | integrado |
| `AP-0x3029h` | `0x3001h` | integrado |
| `AP-0x302Ah` | `0x300Ah` | integrado |
| `AP-0x4002h` | `0x4006h` | integrado |
| `AP-0x4006h` | `0x400Bh` | promovido-a-regla |
| `AP-0x4008b` | `0x400Ch` | promovido-a-regla |
| `AP-0x4008h` | `0x400Ch` | promovido-a-regla |
| `AP-0x4009h` | `0x4004h` | integrado |
| `AP-0x400Ah` | `0x5006h` | integrado |
| `AP-0x400Bh` | `0x4001h` | integrado |
| `AP-0x5004b` | `0x5004h` | integrado |
| `AP-0x5004c` | `0x5004h` | integrado |
| `AP-0x5004h` | `0x5004h` | integrado |
| `AP-0x5008h` | `0x5008h` | integrado |
| `AP-0x5009h` | `0x5009h` | integrado |
| `AP-0x500Ah` | `0x500Ah` | integrado |
| `AP-0x500Bh` | `0x500Dh` | integrado |
| `AP-0x5014h` | `0x5015h` | promovido-a-regla |
| `AP-0x5016h` | `0x5015h` | promovido-a-regla |
