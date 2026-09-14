---
title: "Catálogo de Antipatrones Didácticos y Seguridad"
short_title: "Índice de Antipatrones"
subtitle: "Detección de patrones viciosos en C11 auditados por Spunkmeyer y Kaneda"
---

(antipatrones-indice)=
# Catálogo de Antipatrones Didácticos y Seguridad

Un antipatrón didáctico es un patrón de código común en estudiantes que compila sin errores sintácticos inmediatos pero produce comportamiento indefinido, fugas de memoria o vulnerabilidades de ejecución.

```{tableofcontents}
```

## Antipatrones por Categoría

### [Antipatrones de Memoria y Punteros](1_memoria/index.md)

* [AP001: Casteo redundante de malloc()](1_memoria/ap001_300A.md)
* [AP003: Retorno de puntero a variable local (Dangling Stack Pointer)](1_memoria/ap003_3002.md)
* [AP004: Chequeo innecesario antes de free()](1_memoria/ap004_3008.md)
* [AP008: Uso de sizeof(puntero) en reserva dinámica](1_memoria/ap008_300F.md)
* [AP010: Uso de memoria dinámica sin validar retorno a NULL](1_memoria/ap010_3001.md)
* [AP011: Puntero colgante sin asignar NULL tras free()](1_memoria/ap011_3002.md)
* [AP014: Número mágico literal en condición lógica](1_memoria/ap014_300D.md)
* [AP024: Sobreescritura directa de puntero en realloc](1_memoria/ap024_3015.md)
* [AP026: Pointer decay en sizeof de arreglo parámetro](1_memoria/ap026_3019.md)
* [AP036: Tamaño insuficiente en memset con sizeof(ptr)](1_memoria/ap036_301A.md)
* [AP037: Desreferencia inmediata tras realloc](1_memoria/ap037_301B.md)
* [AP038: Casteo redundante en invocación de free()](1_memoria/ap038_301C.md)
* [AP041: Comparación sintáctica errónea de puntero con carácter nulo '\0'](1_memoria/ap041_301D.md)
* [AP042: Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo](1_memoria/ap042_301E.md)
* [AP046: Asignación de retorno de malloc() a variable no puntero](1_memoria/ap046_301F.md)
* [AP047: Casteo forzado entre punteros de tipos incompatibles (Violación de Strict Aliasing)](1_memoria/ap047_3020.md)
* [AP053: Invocación a free() sobre memoria estática o variables automáticas de pila](1_memoria/ap053_3021.md)
* [AP055: Asignación de punteros a arreglos locales en parámetros de salida](1_memoria/ap055_3022.md)
* [AP056: Comprobación de puntero nulo posterior a su desreferencia](1_memoria/ap056_3023.md)
* [AP057: Asignación múltiple a malloc en bucle sin liberación ante fallos parciales](1_memoria/ap057_3024.md)
* [AP058: Modificación directa del puntero base asignado por malloc()](1_memoria/ap058_3025.md)
* [AP060: Desreferencia condicional de puntero local sin inicializar](1_memoria/ap060_3026.md)
* [AP061: Cálculo erróneo de tamaño para struct dinámico con miembro flexible](1_memoria/ap061_3027.md)
* [AP063: Casteo de retorno de malloc() con omisión de include stdlib.h](1_memoria/ap063_3028.md)
* [AP070: Desreferencia directa tras retorno de realloc sin asignación temporal](1_memoria/ap070_3029.md)
* [AP073: Casteo forzado de tipos numéricos o literales enteros a punteros](1_memoria/ap073_302A.md)

### [Antipatrones de Control de Flujo e Iteración](2_control/index.md)

* [AP005: Comparación booleana explícita redundante](2_control/ap005_1005.md)
* [AP006: Punto y coma accidental tras condición de control](2_control/ap006_1001.md)
* [AP009: Variable float o double utilizada como contador de bucle](2_control/ap009_100D.md)
* [AP016: Asignación accidental en condición lógica (if (x = 5))](2_control/ap016_100A.md)
* [AP021: Caso de switch sin break (Fallthrough no intencional)](2_control/ap021_100C.md)
* [AP023: Expresión booleana tautológica o contradictoria](2_control/ap023_100E.md)
* [AP027: Posible error off-by-one en condición de parada de bucle](2_control/ap027_100F.md)
* [AP029: Precedencia errónea entre asignación y comparación](2_control/ap029_1010.md)
* [AP031: Comparación de igualdad estricta en punto flotante](2_control/ap031_1011.md)
* [AP039: Invocación a strlen() en condición de parada de bucle for](2_control/ap039_1014.md)
* [AP040: Modificación de variable de control dentro del cuerpo del for](2_control/ap040_1015.md)
* [AP043: Uso de operador bit a bit (&, |) en condición lógica en lugar de booleano (&&, ||)](2_control/ap043_1016.md)
* [AP044: Ramas idénticas duplicadas en bifurcación if-else](2_control/ap044_1017.md)
* [AP045: Ambigüedad sintáctica por omisión de llaves en condicional anidado (Dangling Else)](2_control/ap045_1018.md)
* [AP048: Uso de salto goto hacia atrás vulnerando programación estructurada](2_control/ap048_1019.md)
* [AP050: Comparación lógica invertida con strcmp() en condicional](2_control/ap050_101A.md)
* [AP052: Comparación entre tipos enteros con y sin signo en condición](2_control/ap052_101B.md)
* [AP062: Bucle infinito con salida condicionada exclusivamente por exit()](2_control/ap062_101C.md)

### [Antipatrones de Funciones y Alcance](3_funciones/index.md)

* [AP012: Variable local declarada pero no utilizada](3_funciones/ap012_2007.md)
* [AP015: Función con excesiva cantidad de parámetros (> 5)](3_funciones/ap015_200B.md)
* [AP018: Llamada recursiva sin caso base explícito](3_funciones/ap018_2009.md)
* [AP033: Recursión mutua o cíclica sin caso base](3_funciones/ap033_2011.md)
* [AP035: Comparador de qsort con resta directa sujeta a overflow](3_funciones/ap035_2012.md)
* [AP051: Descarte del valor retornado por funciones de conversión numérica](3_funciones/ap051_2013.md)

### [Antipatrones de E/S y Gestión de Archivos](4_archivos/index.md)

* [AP002: Control de lectura con while(!feof())](4_archivos/ap002_4002.md)
* [AP007: Uso de fflush(stdin) para limpiar buffer](4_archivos/ap007_4006.md)
* [AP025: Desajuste de especificadores de formato en printf/scanf](4_archivos/ap025_4008.md)
* [AP032: Retorno prematuro con fuga de recursos de archivo](4_archivos/ap032_4009.md)
* [AP049: Lectura de cadenas con scanf() sin límite de ancho en buffer fijo](4_archivos/ap049_400A.md)
* [AP059: Omisión de verificación de retorno NULL en fopen()](4_archivos/ap059_400B.md)

### [Antipatrones de Seguridad y Vulnerabilidades](5_seguridad/index.md)

* [KAN001: Uso de la función prohibida 'gets()'](5_seguridad/kan001_gets.md)
* [KAN002: Copia insegura de cadenas con 'strcpy()' o 'strcat()'](5_seguridad/kan002_strcpy.md)
* [KAN003: Formateo inseguro con 'sprintf()'](5_seguridad/kan003_sprintf.md)
* [KAN004: Lectura sin límite en 'scanf("%s")'](5_seguridad/kan004_scanf.md)
* [KAN005: Vulnerabilidad de cadena de formato (Format String)](5_seguridad/kan005_format_string.md)
* [KAN006: Invocación al intérprete de comandos con 'system()' o 'popen()'](5_seguridad/kan006_system.md)
* [KAN007: Llamada a sistema restringida fuera de consigna](5_seguridad/kan007_syscalls.md)

### [Antipatrones de Buenas Prácticas y Preprocesador](6_practicas/index.md)

* [AP013: Uso de funciones inseguras de manipulación de cadenas (strcpy/sprintf)](6_practicas/ap013_5004.md)
* [AP017: Macro con argumentos evaluados múltiples veces](6_practicas/ap017_500A.md)
* [AP019: Invocación de la función prohibida gets()](6_practicas/ap019_5008.md)
* [AP020: Comparación directa de cadenas con == o !=](6_practicas/ap020_5004.md)
* [AP022: Declaración de variable mezclada tras sentencias ejecutables](6_practicas/ap022_0003.md)
* [AP028: División entera silenciosa asignada a flotante](6_practicas/ap028_5009.md)
* [AP030: Lectura de variable local no inicializada](6_practicas/ap030_0004.md)
* [AP034: Macro que ofusca sintaxis fundamental de C](6_practicas/ap034_0039.md)
* [AP054: Redefinición de identificadores de funciones estándar de la biblioteca C](6_practicas/ap054_500B.md)
