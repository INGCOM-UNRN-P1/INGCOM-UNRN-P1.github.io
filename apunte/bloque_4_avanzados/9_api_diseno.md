---
title: Diseño de Interfaces y APIs en C
short_title: 'Diseño de APIs'
description: 'Principios para crear interfaces modulares, reutilizables y robustas en C: encapsulamiento, gestión de recursos, manejo de errores y patrones de diseño.'
numbering:
  code: true
---

(diseno-api-capitulo)=

> **Prerrequisitos**: TAD, contratos, punteros opacos, manejo de errores y
> compilación modular con `.h` y `.c`.
>
> **Objetivo**: definir una interfaz pequeña con propiedad de recursos,
> precondiciones y errores documentados antes de implementar sus detalles.
>
> **Comprobación de salida**: redactá el contrato de una función pública indicando propiedad, error y responsabilidad de liberación.

Para el marco formal de contratos que sustenta el diseño de interfaces, ver
{ref}`capitulo-contratos-formales`. Para el patrón de punteros opacos que
implementa
el encapsulamiento, ver el capítulo [17_opacos](17_opacos).

(introduccion-el-arte-de-disenar-contratos)=
## Introducción: El Arte de Diseñar Contratos

Más allá de escribir algoritmos que funcionen, un programador profesional debe
saber cómo construir **módulos de software** que otros puedan utilizar de manera
fácil, segura y predecible. En C, la puerta de entrada a un módulo es su
**interfaz pública** o **API** (Application Programming Interface), definida
casi siempre en un archivo de cabecera (`.h`).

Una API es un contrato formal. Define qué funcionalidades ofrece un módulo, qué
datos necesita y qué resultados garantiza. Un buen diseño de interfaz es la
diferencia entre una librería que es un placer utilizar y una que es una fuente
constante de errores y frustración. Este contrato no es solo a nivel de código
fuente (API), sino también a nivel binario (ABI - Application Binary Interface),
determinando cómo el código compilado interactúa con otro.

La noción de "contrato" fue formalizada por Bertrand Meyer en su metodología de
**Diseño por Contrato** (*Design by Contract*) [@meyer1988], donde las
precondiciones, poscondiciones e invariantes definen obligaciones y garantías
entre el cliente y el proveedor de un servicio. Aunque Meyer desarrolló esta
metodología en el contexto de Eiffel, sus principios son universalmente
aplicables y particularmente valiosos en C, donde la falta de mecanismos de
seguridad del lenguaje hace que los contratos explícitos sean aún más críticos.

Este apunte establece los lineamientos para diseñar interfaces de alta calidad
en C, aplicando los principios de la descomposición funcional y las reglas de
estilo para crear código que no solo es correcto, sino también elegante y
mantenible.

(el-desafio-del-diseno-en-c)=
### El Desafío del Diseño en C

C es un lenguaje minimalista que delega gran parte de la responsabilidad de
seguridad y corrección al programador. A diferencia de lenguajes modernos con
sistemas de tipos más ricos, manejo automático de memoria o espacios de nombres
modulares, C ofrece pocas herramientas para encapsulamiento y abstracción. Esta
aparente limitación es también su fortaleza: la simplicidad y el control directo
que brinda C son la razón por la cual sigue siendo el lenguaje de elección para
sistemas operativos, drivers, sistemas embebidos y software de alto rendimiento
[@kernighan1988].

El diseño de APIs en C requiere disciplina y conocimiento profundo de los
patrones idiomáticos del lenguaje. Como señalan Spinellis y Gousios
[@spinellis2009], el código bien diseñado no es accidental; es el resultado de
decisiones conscientes y la aplicación sistemática de principios de ingeniería
de software.

(principios-fundamentales-del-diseno-de-interfaces)=
## Principios Fundamentales del Diseño de Interfaces

Un buen diseño de API se rige por un conjunto de principios que buscan maximizar
la claridad, la seguridad y la facilidad de uso.

(1-claridad-y-expresividad)=
### 1. Claridad y Expresividad

Una interfaz debe ser auto-documentada en la medida de lo posible. El código
debe comunicar su intención de forma clara y directa. Como observa Martin
[@martin2008], "el código se lee muchas más veces de las que se escribe", por lo
que invertir en claridad es una optimización fundamental.

- **Nombres Descriptivos**: Los nombres de las funciones deben ser verbos que
  describan la acción que realizan. Los nombres de los tipos y parámetros deben
  ser sustantivos claros. Esto sigue la regla {ref}`0x0101h`.

  :::{code-block} c
  // Malo: Nombres ambiguos y poco informativos.
  void process_list(list *l, int d);
  // Bueno: Nombres claros, específicos y con prefijo.
  lista_t *lista_crear(void);
  bool lista_agregar_al_final(lista_t *lista, int dato);
  :::

  La elección de nombres tiene consecuencias cognitivas profundas. Un estudio de
  Lawrie et al. [@lawrie2006] demostró empíricamente que los nombres más largos
  y descriptivos mejoran significativamente la comprensibilidad del código,
  reduciendo el tiempo necesario para entender su propósito y funcionamiento.

- **Consistencia en la Nomenclatura**: Adoptá un prefijo común para todas las
  funciones y tipos públicos de tu librería (ej. `lista_`). En C, todos los
  símbolos públicos comparten un único espacio de nombres global. El uso de
  prefijos previene **colisiones de nombres** con otras librerías o con el
  propio código del usuario, un problema que puede generar errores de enlazado
  (`linker`) muy difíciles de diagnosticar.

  Este patrón es usado universalmente en la biblioteca estándar de C (todas las
  funciones de cadenas comienzan con `str`, las de entrada/salida con variantes
  de `f` o `printf`, etc.) y en librerías profesionales como GTK+ (prefijo
  `gtk_` y `g_`), OpenSSL (prefijo `SSL_` y `EVP_`), y SQLite (prefijo
  `sqlite3_`).

- **Documentación Rigurosa**: Cada función pública debe estar documentada
  siguiendo la regla {ref}`0x0201h`. El contrato, definido por las
  precondiciones y poscondiciones, debe ser explícito. Esto no es mera
  formalidad; es una especificación del comportamiento esperado, crucial para la
  depuración y la verificación formal.

  La especificación formal de interfaces mediante contratos permite aplicar
  técnicas de verificación estática y testing basado en propiedades
  (*property-based testing*) [@claessen2000], aumentando drásticamente la
  confiabilidad del software.

(2-principio-de-minima-sorpresa)=
### 2. Principio de Mínima Sorpresa

Una función o librería debe comportarse de la manera que un programador
esperaría razonablemente. Evitá la "magia" y los comportamientos inesperados que
obligan al usuario a leer la implementación para entender qué está pasando.

El *Principio de Mínima Sorpresa* (también conocido como *Principle of Least
Astonishment*) fue popularizado por la filosofía de diseño Unix [@raymond2003] y
establece que el sistema debe comportarse de la manera que la mayoría de los
usuarios esperaría. En el contexto de APIs, esto significa que las funciones
deben ser consistentes con convenciones establecidas y con el comportamiento de
funciones similares.

Bloch [@bloch2006] enfatiza que una buena API debe ser "fácil de usar y difícil
de usar mal". Esto se logra cuando el comportamiento predeterminado es el más
común y seguro, y cuando las operaciones peligrosas requieren pasos explícitos
que alertan al programador sobre lo que está haciendo.

Por ejemplo, si una función modifica sus argumentos, esto debe ser evidente
desde su firma y nombre. La biblioteca estándar de C lo hace consistentemente:
`strcpy` copia cadenas y modifica el destino (el primer parámetro es siempre el
destino), mientras que `strlen` solo lee y no modifica nada. Cuando una interfaz
viola las expectativas del usuario, la carga cognitiva aumenta, introduciendo
errores y frustraciones evitables.

- **Simetría**: Las operaciones deben tener contrapartes lógicas. Si tenés una
  función `recurso_crear()`, debés proveer una `recurso_destruir()`. Esta
  simetría, mencionada en la regla {ref}`0x3002h`, es una manifestación del
  patrón **RAII (Resource Acquisition Is Initialization)**, aunque adaptado a C.
  Ayuda a gestionar el ciclo de vida de los recursos de forma predecible,
  previniendo fugas de memoria (`memory leaks`).

  En lenguajes como C++, RAII es automático mediante constructores y
  destructores. En C, debe implementarse manualmente mediante pares de funciones
  simétricas. La biblioteca estándar de C demuestra este patrón
  consistentemente: `fopen`/`fclose`, `malloc`/`free`,
  `pthread_create`/`pthread_join`, etc.

  :::{important}
  **Gestión de Recursos y Fugas de Memoria**

  Las fugas de memoria (*memory leaks*) son uno de los problemas más comunes y
  peligrosos en programas C. Un estudio de Li y Zhou [@li2005] sobre bugs en
  sistemas operativos encontró que los errores de manejo de memoria representan
  aproximadamente el 40% de los fallos críticos. El diseño simétrico de APIs
  ayuda a prevenir estos errores haciendo explícita la responsabilidad de
  liberación de recursos.
  :::

- **Efectos Secundarios Claros**: Si una función modifica el estado de uno de
  sus argumentos (un efecto secundario), esto debe ser evidente en su nombre y
  estar claramente documentado. Es preferible devolver resultados a modificar
  parámetros de salida (`out-parameters`), ya que esto último puede hacer el
  flujo de datos más difícil de seguir. Cuando un parámetro de salida es
  inevitable, su propósito debe ser inequívoco.

  :::{code-block} c
  // El nombre deja claro que la cadena será modificada "in-place".
  void cadena_convertir_a_mayusculas(char *cadena);
  // Un parámetro de salida. El nombre indica qué se obtendrá.
  bool obtener_temperatura_sensor(sensor_t *sensor, double *temperatura_out);
  :::

  La programación funcional, con su énfasis en funciones puras sin efectos
  secundarios, ha demostrado ventajas significativas en razonamiento y testing
  [@hughes1989]. Aunque C no es un lenguaje funcional, minimizar y hacer
  explícitos los efectos secundarios acerca el código a estas ventajas.

(3-encapsulamiento-y-ocultamiento-de-informacion)=
### 3. Encapsulamiento y Ocultamiento de Información

El usuario de tu librería no necesita (y no debe) conocer los detalles internos
de su implementación. La interfaz pública (`.h`) debe exponer el **qué** (la
capacidad), mientras que la implementación (`.c`) oculta el **cómo** (los
detalles).

El mecanismo más potente para lograr esto en C es el uso de **punteros opacos**
(opaque pointers), que permiten una verdadera abstracción de datos.

#### Punteros Opacos: La Clave de la Abstracción en C

Un puntero opaco es un puntero a un tipo de estructura cuya definición está
incompleta en el archivo de cabecera. El usuario sabe que existe un tipo
`mi_tipo_t`, pero no conoce sus campos internos, su tamaño, ni su organización
en memoria.

Este patrón, también conocido como **PIMPL** (*Pointer to IMPLementation*) o
**Tipo Abstracto de Datos** (TAD), es la forma idiomática en C de lograr
encapsulamiento real. Aunque el concepto de tipos abstractos de datos fue
formalizado por Liskov y Zilles [@liskov1974], su implementación en C mediante
punteros opacos se popularizó en los años 80 y es hoy una práctica estándar en
todas las librerías C profesionales.

El trabajo seminal de Liskov y Zilles sobre TADs estableció que un tipo de datos
debe definirse por sus operaciones y sus propiedades algebraicas, no por su
representación interna. En C, los punteros opacos son la herramienta fundamental
para lograr esta separación entre interfaz e implementación, permitiendo lo que
Parnas [@parnas1972] llamó *information hiding* (ocultamiento de información):
el principio de que los módulos deben revelar lo mínimo indispensable sobre su
funcionamiento interno.

- **En el archivo de cabecera (`mi_libreria.h`):** 
  :::{code-block} c
  // 1. Declaración adelantada (forward declaration) de la estructura.
  // El compilador sabe que "struct mi_tipo" es un tipo, pero no conoce su
  contenido.struct mi_tipo;
  // 2. Creación de un alias de tipo para el puntero a la estructura.
  typedef struct mi_tipo mi_tipo_t;
  // 3. Funciones públicas que operan sobre el puntero opaco.
  mi_tipo_t *mi_tipo_crear(int valor_inicial);
  void mi_tipo_destruir(mi_tipo_t *objeto);
  int mi_tipo_obtener_valor(const mi_tipo_t *objeto);
  :::

- **En el archivo de implementación (`mi_libreria.c`):** 
  :::{code-block} c
  #include "mi_libreria.h"
  #include <stdlib.h>
  // 4. Definición completa de la estructura. Esta definición es privada
  // y solo visible dentro de este archivo .c.
  struct mi_tipo
  {
      int valor_secreto;
      void *otro_dato_interno;
  };
  // 5. Implementación de las funciones.
  mi_tipo_t *mi_tipo_crear(int valor_inicial)
  {
      // Aquí sí podemos usar sizeof, porque la definición completa es visible.
      mi_tipo_t *nuevo = malloc(sizeof(struct mi_tipo));
      if (nuevo != NULL)
      {
          nuevo->valor_secreto = valor_inicial;
      }
      return nuevo;
  }
  // ... resto de implementaciones ...
  :::

**Ventajas Técnicas:**
- **Abstracción Total**: El usuario no puede acceder a `valor_secreto`
  directamente (ej. `objeto->valor_secreto` fallaría al compilar). La única
  forma de interactuar es a través de la API, lo que garantiza que los
  invariantes de la estructura se mantengan.

- **Estabilidad del ABI (Application Binary Interface)**: Esta es la ventaja más
  importante desde el punto de vista de la ingeniería de software a gran escala.
  Si la definición de la `struct` estuviera en el `.h`, cualquier cambio
  (agregar un campo, reordenarlos) modificaría el tamaño y el layout de la
  estructura. Esto **rompería la compatibilidad binaria**, obligando a todos los
  programas que usan la librería a ser recompilados. Con un puntero opaco, podés
  modificar la estructura interna libremente; mientras la firma de las funciones
  públicas no cambie, la librería puede ser actualizada sin necesidad de
  recompilar el software cliente.

  La estabilidad del ABI es crítica en sistemas operativos y bibliotecas
  compartidas. Como documenta Drepper [@drepper2011] en su guía sobre el
  desarrollo de bibliotecas dinámicas, la ruptura del ABI puede causar fallos
  catastróficos en sistemas en producción, donde múltiples aplicaciones dependen
  de una versión específica de una biblioteca. Los punteros opacos son la
  técnica principal para mantener esta estabilidad.

- **Flexibilidad de Implementación**: Podés cambiar completamente la
  representación interna sin afectar al código cliente. Por ejemplo, podés
  empezar con una implementación basada en arrays y luego cambiar a una basada
  en árboles para mejorar el rendimiento, sin que ningún usuario de la API
  necesite modificar su código.

- **Soporte para Múltiples Implementaciones**: Es posible tener diferentes
  implementaciones del mismo TAD (por ejemplo, una optimizada para memoria y
  otra para velocidad) que comparten la misma interfaz pública, permitiendo al
  usuario elegir en tiempo de compilación o enlace.

(4-gestion-de-recursos-y-propiedad-ownership)=
### 4. Gestión de Recursos y Propiedad (Ownership)

Una de las mayores fuentes de errores en C es la gestión de memoria. Tu API debe
ser explícita sobre quién es el responsable (`owner`) de asignar y liberar cada
recurso.

El concepto de *ownership* (propiedad) es fundamental en la programación de
sistemas. Aunque lenguajes modernos como Rust lo formalizan en el sistema de
tipos, en C debe ser documentado explícitamente y seguido disciplinadamente. La
falta de claridad sobre la propiedad de los recursos es una causa principal de
fugas de memoria (*memory leaks*), dobles liberaciones (*double free*) y accesos
a memoria liberada (*use-after-free*) [@serebryany2012].

Un estudio de Lu et al. [@lu2008] sobre bugs en sistemas de código abierto
encontró que los errores de manejo de memoria y concurrencia representan más del
60% de los bugs críticos que causan crashes y vulnerabilidades de seguridad. El
diseño cuidadoso de APIs con semánticas claras de propiedad puede prevenir una
gran proporción de estos errores.

- **Documentar la Propiedad**: Como exige la regla {ref}`0x3006h`, la
  documentación de cada función debe indicar claramente quién es el dueño de la
  memoria. Si una función devuelve un puntero a memoria recién asignada, el
  comentario debe decir que el llamador es responsable de liberarla. Definí un
  modelo de propiedad claro:
    - **Propiedad del Llamador (Caller-owned)**: El llamador aloja y libera la
      memoria. La función solo opera sobre ella. Es común para búferes que la
      función debe llenar.
    - **Propiedad de la Librería (Callee-owned)**: La librería gestiona el ciclo
      de vida. `mi_libreria_crear()` aloja la memoria y `mi_libreria_destruir()`
      la libera. Este es el modelo preferido para punteros opacos.
    - **Propiedad Transferida**: La función toma posesión del recurso pasado
      como argumento y es responsable de liberarlo. Esto debe ser extremadamente
      explícito en la documentación.
    - **Propiedad Compartida**: Múltiples partes del código mantienen
      referencias al mismo recurso. En C puro, esto usualmente requiere conteo
      de referencias manual (como en `fopen`/`fclose`, donde múltiples handles
      pueden apuntar al mismo recurso del sistema operativo).

:::{important}

**Semánticas de Movimiento vs. Copia**

Cuando una función recibe un puntero a una estructura compleja, debe ser claro
si la función hace una copia interna del dato o simplemente guarda el puntero.
Si guarda el puntero, el llamador debe asegurarse de que la memoria permanezca
válida durante toda la vida útil del objeto. Esta distinción entre *shallow
copy* (copia superficial) y *deep copy* (copia profunda) es crítica y debe estar
documentada explícitamente.

:::
<!-- {important} -->

- **Uso de `const` para Clarificar Intenciones**: Utilizá `const` para indicar
  que una función no modificará los datos apuntados por un puntero (regla
  {ref}`0x3007h`). Esto no solo previene efectos secundarios no deseados, sino
  que permite al compilador realizar optimizaciones y le da confianza al
  usuario.

  El uso correcto de `const` es más que una convención de estilo; es una forma
  de documentación ejecutable que el compilador puede verificar. Como señala
  Meyers [@meyers2005], `const` debe usarse siempre que sea semánticamente
  correcto, ya que comunica intención y permite al compilador detectar errores.

  :::{code-block} c
  // La función promete no modificar ni la estructura de la lista
  // ni el dato que se le pasa para buscar.
  bool lista_contiene(const lista_t *lista, const char *dato);
  :::

(5-manejo-de-errores-robusto-y-consistente)=
### 5. Manejo de Errores Robusto y Consistente

Una librería no debe terminar el programa abruptamente (ej. con `exit()`). Debe
reportar los errores al llamador para que este decida cómo proceder.

- **Establecer un Mecanismo de Error Consistente**: Sé predecible. Si tus
  funciones devuelven punteros, `NULL` es el indicador de error universal. Si
  devuelven enteros, usá un valor específico como `-1` o, mejor aún, un tipo
  enumerado (`enum`) o constantes definidas con `#define` para los códigos de
  error (regla {ref}`0x2005h`).

  :::{code-block} c
  typedef enum
  {
      LISTA_OK = 0,
      LISTA_ERROR_NO_ENCONTRADO = -1,
      LISTA_ERROR_MEMORIA = -2
  } lista_error_t;
  :::

- **Evitar `printf` y `exit`**: Una librería es un componente, no un programa
  completo. No debe asumir que tiene control sobre la consola o el ciclo de vida
  del proceso. Su única responsabilidad es ejecutar su tarea e informar el
  resultado (éxito o fracaso).

- **Proveer Información Adicional**: Para APIs complejas, es útil ofrecer una
  función que permita obtener una descripción textual del último error ocurrido.
  Esto es más flexible que `perror`, ya que el llamador puede decidir si mostrar
  el mensaje, guardarlo en un log, etc.

  :::{code-block} c
  const char *mi_libreria_ultimo_error_str(void);
  :::

(6-simplicidad-y-minimalismo)=
### 6. Simplicidad y Minimalismo

Una buena interfaz es aquella que es lo más pequeña posible, pero no más. Cada
función expuesta públicamente aumenta la "superficie de ataque" (potenciales
bugs y vulnerabilidades) y la carga de mantenimiento.

- **Exponer solo lo necesario (Internal Linkage)**: Si una función es una ayuda
  interna para otras funciones de la librería, declarala como `static` en el
  archivo `.c`. Esto le da "enlace interno" (`internal linkage`), haciéndola
  invisible para el enlazador fuera de esa unidad de compilación.

- **Ortogonalidad**: Diseñá un conjunto de funciones primitivas y ortogonales
  (independientes) que puedan ser combinadas de formas potentes. Es preferible
  tener `lista_agregar()` y `lista_ordenar()` que una única y monolítica
  `lista_agregar_y_ordenar()`.

- **Evitar la Complejidad Prematura**: No agregues funcionalidades que "podrían
  ser útiles en el futuro". Diseñá una API que resuelva el problema actual de
  forma elegante. Es más fácil agregar funciones después que quitarlas, ya que
  quitar una función rompe la compatibilidad con versiones anteriores.

(ejemplos-practicos-de-diseno-de-apis)=
## Ejemplos Prácticos de Diseño de APIs

Los principios anteriores cobran vida cuando se aplican a problemas reales. A
continuación se presentan ejemplos concretos que ilustran cómo diseñar
interfaces robustas y mantenibles en C.

(ejemplo-1-diseno-de-una-lista-enlazada)=
### Ejemplo 1: Diseño de una Lista Enlazada

Una lista enlazada es una estructura de datos fundamental que ejemplifica
perfectamente los principios de diseño de APIs. El objetivo es ofrecer una
interfaz que oculte la complejidad interna de la gestión de nodos y memoria.

#### Archivo de Cabecera (`lista.h`)

```{code-block} c
:linenos:
#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
/**
 * Tipo opaco que representa una lista enlazada.
 * Los detalles de implementación están ocultos al usuario.
 */
typedef struct lista lista_t;
/**
 * Crea una nueva lista vacía.
 *
 * @returns Puntero a la nueva lista, o NULL si falla la asignación.
 * @post El llamador es responsable de liberar la memoria con lista_destruir().
 */
lista_t *lista_crear(void);
/**
 * Destruye una lista y libera toda la memoria asociada.
 *
 * @param lista Puntero a la lista a destruir.
 * @pre lista != NULL
 * @post Todos los nodos internos son liberados. El puntero lista queda
 * inválido.
 */
void lista_destruir(lista_t *lista);
/**
 * Agrega un elemento al final de la lista.
 *
 * @param lista Lista donde se agregará el elemento.
 * @param dato Valor entero a agregar.
 * @returns true si se agregó exitosamente, false si falló la asignación.
 * @pre lista != NULL
 */
bool lista_agregar(lista_t *lista, int dato);
/**
 * Obtiene el número de elementos en la lista.
 *
 * @param lista Lista a consultar.
 * @returns Cantidad de elementos. Si lista es NULL, devuelve 0.
 */
size_t lista_largo(const lista_t *lista);
/**
 * Busca un elemento en la lista.
 *
 * @param lista Lista donde buscar.
 * @param dato Valor a buscar.
 * @returns true si el elemento está en la lista, false en caso contrario.
 * @pre lista != NULL
 */
bool lista_contiene(const lista_t *lista, int dato);
#endif // LISTA_H

```
<!-- {code-block} c -->

**Análisis del Diseño:**

- **Puntero Opaco ([ocultamiento de
  información](#3-encapsulamiento-y-ocultamiento-de-informacion))**: La
  estructura `lista_t` es completamente opaca. El usuario no puede acceder
  directamente a los nodos internos, lo que permite cambiar la implementación
  sin romper el código cliente.

- **Gestión de Recursos Explícita ([gestión de
  recursos](#4-gestion-de-recursos-y-propiedad-ownership))**: Las funciones
  `lista_crear()` y `lista_destruir()` forman un par simétrico, siguiendo la
  regla {ref}`0x3002h`. La documentación especifica claramente que el llamador
  es responsable de llamar a `lista_destruir()`.

- **Uso de `const` ({ref}`0x3007h`)**: `lista_largo()` y `lista_contiene()`
  reciben `const lista_t *`, indicando que no modificarán la lista. Esto permite
  al compilador optimizar y comunica la intención al usuario.

- **Manejo de Errores Consistente ([manejo de
  errores](#5-manejo-de-errores-robusto-y-consistente))**: Las funciones que
  pueden fallar (como `lista_crear()` y `lista_agregar()`) devuelven un valor
  que indica éxito o fracaso (`NULL` o `bool`). No hay `printf` ni `exit` en la
  librería.

- **Prefijo Consistente ([claridad y
  expresividad](#1-claridad-y-expresividad))**: Todas las funciones públicas
  usan el prefijo `lista_`, evitando colisiones de nombres en el espacio de
  nombres global de C.

(ejemplo-2-modulo-de-operaciones-matematicas-seguras)=
### Ejemplo 2: Módulo de Operaciones Matemáticas Seguras

Un módulo que realiza operaciones matemáticas básicas con manejo de errores
robusto demuestra cómo diseñar una API que reporta errores sin terminar el
programa.

#### Archivo de Cabecera (`matematica.h`)

```{code-block} c
:linenos:
#ifndef MATEMATICA_H
#define MATEMATICA_H
#include <stdbool.h>
/**
 * Códigos de error para operaciones matemáticas.
 */
typedef enum
{
    MAT_OK = 0,
    MAT_ERROR_DIVISION_CERO = -1,
    MAT_ERROR_RAIZ_NEGATIVA = -2,
    MAT_ERROR_DESBORDAMIENTO = -3
} mat_error_t;
/**
 * Divide dos números enteros de forma segura.
 *
 * @param dividendo Número a dividir.
 * @param divisor Número por el cual dividir.
 * @param resultado Puntero donde se almacenará el resultado.
 * @returns MAT_OK si la operación fue exitosa, MAT_ERROR_DIVISION_CERO en caso
 * contrario.
 * @pre resultado != NULL
 * @post Si retorna MAT_OK, *resultado contiene dividendo/divisor.
 *       Si retorna error, *resultado no es modificado.
 */
mat_error_t mat_dividir(int dividendo, int divisor, int *resultado);
/**
 * Calcula la raíz cuadrada entera de un número.
 *
 * @param n Número del cual calcular la raíz.
 * @param resultado Puntero donde se almacenará el resultado.
 * @returns MAT_OK si n >= 0, MAT_ERROR_RAIZ_NEGATIVA en caso contrario.
 * @pre resultado != NULL
 * @post Si retorna MAT_OK, *resultado contiene la raíz cuadrada entera de n.
 */
mat_error_t mat_raiz_cuadrada(int n, int *resultado);
/**
 * Obtiene una descripción textual del último error.
 *
 * @param error Código de error a describir.
 * @returns Cadena constante con la descripción del error.
 * @post La cadena retornada es propiedad de la librería, no debe ser liberada.
 */
const char *mat_error_str(mat_error_t error);
#endif // MATEMATICA_H

```
<!-- {code-block} c -->

#### Ejemplo de Implementación (`matematica.c`)

```{code-block} c
:linenos:
#include "matematica.h"
#include <math.h>
mat_error_t mat_dividir(int dividendo, int divisor, int *resultado)
{
    if (divisor == 0)
    {
        return MAT_ERROR_DIVISION_CERO;
    }
    *resultado = dividendo / divisor;
    return MAT_OK;
}
mat_error_t mat_raiz_cuadrada(int n, int *resultado)
{
    if (n < 0)
    {
        return MAT_ERROR_RAIZ_NEGATIVA;
    }
    *resultado = (int)sqrt(n);
    return MAT_OK;
}
const char *mat_error_str(mat_error_t error)
{
    switch (error)
    {
    case MAT_OK:
        return "Operación exitosa";
    case MAT_ERROR_DIVISION_CERO:
        return "Error: División por cero";
    case MAT_ERROR_RAIZ_NEGATIVA:
        return "Error: Raíz cuadrada de número negativo";
    case MAT_ERROR_DESBORDAMIENTO:
        return "Error: Desbordamiento aritmético";
    default:
        return "Error desconocido";
    }
}

```
<!-- {code-block} c -->

#### Ejemplo de Uso

```{code-block} c
:linenos:
#include "matematica.h"
#include <stdio.h>
int main(void)
{
    int resultado = 0;
    mat_error_t error = MAT_OK;
    // División segura
    error = mat_dividir(10, 2, &resultado);
    if (error == MAT_OK)
    {
        printf("10 / 2 = %d\n", resultado);
    }
    else
    {
        printf("Error: %s\n", mat_error_str(error));
    }
    // Intento de división por cero
    error = mat_dividir(10, 0, &resultado);
    if (error != MAT_OK)
    {
        printf("Error detectado: %s\n", mat_error_str(error));
    }
    return 0;
}

```
<!-- {code-block} c -->

**Análisis del Diseño:**

- **Tipo Enumerado para Errores ({ref}`0x2005h`)**: El uso de `mat_error_t` hace
  que los códigos de error sean legibles y auto-documentados, superior a valores
  mágicos como `-1`.

- **Parámetros de Salida Explícitos**: El resultado se devuelve a través de un
  puntero, mientras que el valor de retorno de la función indica el éxito o
  fracaso. Esto sigue el patrón estándar de muchas APIs de C (similar a
  `scanf`).

- **No Modificación en Caso de Error**: Las poscondiciones garantizan que si una
  función falla, no modifica el parámetro de salida. Esto previene el uso de
  datos no inicializados.

- **Función Auxiliar para Mensajes**: `mat_error_str()` permite al llamador
  decidir cómo manejar los mensajes de error (mostrarlos, guardarlos en un log,
  etc.), sin que la librería asuma control sobre la salida.

(ejemplo-3-lector-de-archivos-de-configuracion)=
### Ejemplo 3: Lector de Archivos de Configuración

Un módulo que lee archivos de configuración simple (formato clave=valor) ilustra
cómo diseñar APIs que gestionan recursos del sistema de forma segura.

#### Archivo de Cabecera (`config.h`)

```{code-block} c
:linenos:
#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>
#define CONFIG_MAX_CLAVE 64
#define CONFIG_MAX_VALOR 256
/**
 * Tipo opaco que representa una configuración cargada desde un archivo.
 */
typedef struct config config_t;
/**
 * Carga un archivo de configuración.
 *
 * @param ruta_archivo Ruta al archivo a cargar.
 * @returns Puntero a la configuración cargada, o NULL si falla.
 * @pre ruta_archivo != NULL
 * @post El llamador debe liberar la memoria con config_destruir().
 */
config_t *config_cargar(const char *ruta_archivo);
/**
 * Destruye una configuración y libera toda la memoria asociada.
 *
 * @param config Configuración a destruir.
 * @post El puntero config queda inválido después de esta llamada.
 */
void config_destruir(config_t *config);
/**
 * Obtiene un valor de configuración como cadena.
 *
 * @param config Configuración a consultar.
 * @param clave Nombre de la clave a buscar.
 * @param valor_defecto Valor a retornar si la clave no existe.
 * @returns El valor asociado a la clave, o valor_defecto si no se encuentra.
 * @pre config != NULL, clave != NULL
 * @post La cadena retornada es propiedad de la librería y válida hasta
 *       que config_destruir() sea llamado.
 */
const char *config_obtener_cadena(const config_t *config, const char *clave,
                                  const char *valor_defecto);
/**
 * Obtiene un valor de configuración como entero.
 *
 * @param config Configuración a consultar.
 * @param clave Nombre de la clave a buscar.
 * @param valor_defecto Valor a retornar si la clave no existe o no es un
 * entero válido.
 * @returns El valor entero asociado a la clave, o valor_defecto.
 * @pre config != NULL, clave != NULL
 */
int config_obtener_entero(const config_t *config, const char *clave,
                          int valor_defecto);
/**
 * Verifica si una clave existe en la configuración.
 *
 * @param config Configuración a consultar.
 * @param clave Nombre de la clave a buscar.
 * @returns true si la clave existe, false en caso contrario.
 * @pre config != NULL, clave != NULL
 */
bool config_existe(const config_t *config, const char *clave);
#endif // CONFIG_H

```
<!-- {code-block} c -->

**Análisis del Diseño:**

- **Valores por Defecto**: Las funciones de consulta permiten especificar un
  valor por defecto, haciendo que el código cliente sea más simple y robusto.

- **Propiedad de Memoria Clara**: La documentación especifica que las cadenas
  retornadas son propiedad de la librería. El llamador no debe intentar
  liberarlas ni modificarlas.

- **Ortogonalidad ([simplicidad y minimalismo](#6-simplicidad-y-minimalismo))**:
  Hay funciones específicas para cada tipo de dato (`config_obtener_cadena`,
  `config_obtener_entero`), en lugar de una única función genérica compleja.

- **Uso Consistente de `const`**: Los parámetros que no son modificados están
  marcados como `const`, tanto los punteros a estructuras opacas como las
  cadenas.

(patrones-comunes-de-diseno-en-c)=
## Patrones Comunes de Diseño en C

Además de los principios fundamentales, existen patrones de diseño que han
demostrado ser efectivos en el desarrollo de APIs en C.

(patron-constructor-destructor)=
### Patrón Constructor/Destructor

Este patrón garantiza que cada recurso tenga un ciclo de vida bien definido.
Para cada función `X_crear()`, debe existir una `X_destruir()` correspondiente,
como exige la regla {ref}`0x3002h`.

```{code-block} c
// Constructor: reserva memoria y la inicializa
recurso_t *recurso_crear(void);
// Destructor: libera memoria y recursos del sistema
void recurso_destruir(recurso_t *recurso);

```
<!-- {code-block} c -->

**Ventajas:**
- Previene fugas de memoria (_memory leaks_).
- Hace explícito el ciclo de vida de los recursos.
- Facilita la gestión de recursos del sistema (archivos, sockets, etc.).

(patron-init-finalize)=
### Patrón Init/Finalize

Cuando el usuario provee la memoria (por ejemplo, una variable en el stack), se
utiliza un par de funciones de inicialización y finalización.

```{code-block} c
:linenos:
typedef struct buffer
{
    char datos[1024];
    size_t usado;
} buffer_t;
// Inicializa un buffer provisto por el usuario
void buffer_init(buffer_t *buffer);
// Limpia los recursos internos, pero no libera buffer
void buffer_finalize(buffer_t *buffer);

```
<!-- {code-block} c -->

**Uso:**
```{code-block} c
buffer_t mi_buffer; // En el stack
buffer_init(&mi_buffer);
// ... usar el buffer ...
buffer_finalize(&mi_buffer);

```
<!-- {code-block} c -->

Este patrón es útil cuando se quiere evitar asignaciones dinámicas o cuando el
tamaño del objeto es conocido en tiempo de compilación. También es preferible en
sistemas embebidos donde la asignación dinámica puede no estar disponible o es
indeseable por razones de determinismo temporal.

:::{note}

**Init/Finalize vs Create/Destroy**

La elección entre estos patrones depende del contexto de uso:

- **Create/Destroy**: Apropiado cuando el tamaño del objeto puede variar o
  cuando se necesita gestión dinámica de múltiples instancias. La librería tiene
  control total sobre la memoria.

- **Init/Finalize**: Apropiado para objetos de tamaño fijo que pueden vivir en
  el stack, arrays estáticos, o cuando se requiere control preciso sobre la
  ubicación de la memoria (por ejemplo, en memoria compartida o regiones de
  memoria específicas del hardware).

Muchas APIs profesionales ofrecen ambas alternativas para máxima flexibilidad.
Por ejemplo, `pthread_mutex_t` de POSIX puede ser inicializado estáticamente o
dinámicamente [@ieee2018].

:::
<!-- {note} -->

(patron-getter-setter)=
### Patrón Getter/Setter

Para estructuras opacas, se proveen funciones de acceso que mantienen la
encapsulación.

```{code-block} c
// Getter: obtiene un valor (no modifica la estructura)
int punto_obtener_x(const punto_t *punto);
// Setter: modifica un valor
void punto_establecer_x(punto_t *punto, int nuevo_x);

```
<!-- {code-block} c -->

**Ventajas:**
- Permite validación antes de asignar valores, manteniendo los invariantes del
  tipo abstracto.
- Facilita el mantenimiento de invariantes y la verificación de contratos.
- Permite agregar logging, debugging, o instrumentación sin cambiar la API
  pública.
- Habilita la implementación de estrategias de copia-en-escritura
  (*copy-on-write*) o caching transparente.

**Consideraciones de Performance:**

El patrón getter/setter introduce una indirección adicional (una llamada a
función) comparado con el acceso directo a campos. En código crítico de
rendimiento, esto puede ser una preocupación. Sin embargo:

1. Los compiladores modernos con optimización activada pueden realizar
   *inlining* de funciones getter/setter simples, eliminando el overhead.
2. En la mayoría de los programas, el costo de la abstracción es despreciable
   comparado con los beneficios de mantenibilidad y evolución del código.
3. Como enfatiza Knuth [@knuth1974]: "La optimización prematura es la raíz de
   todos los males". Optimizá solo después de medir y cuando sea realmente
   necesario.

(antipatrones-que-evitar)=
## Antipatrones: Qué Evitar

Tan importante como saber qué hacer es saber qué NO hacer. Los siguientes son
errores comunes en el diseño de APIs en C.

(antipatron-1-numeros-magicos-en-la-interfaz)=
### Antipatrón 1: Números Mágicos en la Interfaz

```{code-block} c
// MALO: ¿Qué significa 0? ¿Qué significa 1?
int archivo_abrir(const char *nombre, int modo);
// Uso poco claro
archivo_abrir("datos.txt", 1);

```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// BUENO: Usar constantes o enumerados
typedef enum
{
    ARCHIVO_LECTURA = 0,
    ARCHIVO_ESCRITURA = 1,
    ARCHIVO_LECTURA_ESCRITURA = 2
} archivo_modo_t;
int archivo_abrir(const char *nombre, archivo_modo_t modo);
// Uso claro
archivo_abrir("datos.txt", ARCHIVO_ESCRITURA);

```
<!-- {code-block} c -->

Este antipatrón viola la regla {ref}`0x2005h`, que exige usar constantes
simbólicas para valores especiales.

(antipatron-2-estado-global-oculto)=
### Antipatrón 2: Estado Global Oculto

```{code-block} c
// MALO: Estado interno global no visible
void motor_inicializar(void);
void motor_procesar(void); // ¿Sobre qué datos opera?

```
<!-- {code-block} c -->

El uso de estado global hace que la API sea difícil de testear, imposible de
usar de forma concurrente (múltiples hilos) y viola el principio de
encapsulamiento. El estado global es una de las principales fuentes de
acoplamiento en sistemas de software [@parnas1972], dificultando la comprensión,
el testing y la evolución del código.

:::{important}

**Estado Global y Concurrencia**

En programas multi-hilo, el estado global compartido es una fuente primaria de
*race conditions* y comportamiento no determinista. Un estudio de Lu et al.
[@lu2008] encontró que más del 30% de los bugs de concurrencia en sistemas de
código abierto están relacionados con estado global mal sincronizado.

El diseño de APIs sin estado global no solo mejora la testabilidad, sino que
también facilita la escritura de código concurrente correcto, ya que cada
instancia del objeto puede ser usada independientemente por diferentes hilos sin
necesidad de sincronización adicional.

:::
<!-- {important} -->

```{code-block} c
// BUENO: El estado es explícito
motor_t *motor_crear(void);
void motor_procesar(motor_t *motor);
void motor_destruir(motor_t *motor);

```
<!-- {code-block} c -->

(antipatron-3-trampa-booleana-boolean-trap)=
### Antipatrón 3: Trampa Booleana (_Boolean Trap_)

```{code-block} c
// MALO: ¿Qué significa true? ¿Qué significa false?
void ventana_crear(int ancho, int alto, bool visible, bool modal);
// Uso confuso
ventana_crear(800, 600, true, false); // ¿Qué hace cada bool?

```
<!-- {code-block} c -->

Este antipatrón, identificado por Reddy [@reddy2011] como uno de los errores más
comunes en diseño de APIs, surge cuando se usan parámetros booleanos cuyo
significado no es evidente en el punto de llamada. El problema se agrava cuando
hay múltiples parámetros booleanos consecutivos, ya que es fácil confundir su
orden.

```{code-block} c
:linenos:
// BUENO: Usar enums con nombres descriptivos
typedef enum
{
    VENTANA_OCULTA,
    VENTANA_VISIBLE
} ventana_visibilidad_t;
typedef enum
{
    VENTANA_NO_MODAL,
    VENTANA_MODAL
} ventana_modalidad_t;
void ventana_crear(int ancho, int alto, ventana_visibilidad_t visibilidad,
                   ventana_modalidad_t modalidad);
// Uso claro
ventana_crear(800, 600, VENTANA_VISIBLE, VENTANA_NO_MODAL);

```
<!-- {code-block} c -->

La solución es reemplazar los booleanos por tipos enumerados que hagan explícito
el significado de cada valor. Esto mejora dramáticamente la legibilidad y
previene errores sutiles causados por invertir accidentalmente el orden de los
argumentos.

(antipatron-4-abuso-de-parametros-de-salida)=
### Antipatrón 4: Abuso de Parámetros de Salida

```{code-block} c
:linenos:
// MALO: Demasiados parámetros de salida
void parsear_fecha(const char *cadena, int *dia, int *mes, int *anio,
                   bool *valida);
// Uso tedioso y propenso a errores
int d = 0, m = 0, a = 0;
bool ok = false;
parsear_fecha("2024-03-15", &d, &m, &a, &ok);

```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// BUENO: Retornar una estructura
typedef struct
{
    int dia;
    int mes;
    int anio;
} fecha_t;
bool parsear_fecha(const char *cadena, fecha_t *resultado);
// Uso más limpio
fecha_t fecha = {0};
if (parsear_fecha("2024-03-15", &fecha))
{
    // usar fecha.dia, fecha.mes, fecha.anio
}

```
<!-- {code-block} c -->



(resumen-del-diseno-de-interfaces)=
## Resumen del Diseño de Interfaces

En este apunte hemos cubierto los fundamentos del diseño de APIs en C:
- **Principios de diseño:** Claridad, consistencia, principio de mínima sorpresa
  y simetría.
- **Ejemplos prácticos:** Diseño de APIs orientadas a objetos/estructuras.
- **Patrones comunes:** Uso de callbacks, inicializadores designados e inyección
  de dependencias.
- **Antipatrones a evitar:** Exposición de representaciones internas, variables
  globales, y APIs prolijas pero complejas.

Para continuar con el versionado, compatibilidad de ABI y optimizaciones
avanzadas de APIs, consultá {ref}`versionado-y-compatibilidad`.
