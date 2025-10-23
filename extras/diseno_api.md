---
title: Diseño de Interfaces y Librerías en C
short_title: Diseño de APIs
subtitle: Principios para crear código modular, reutilizable y robusto.
---

## Introducción: El Arte de Diseñar Contratos

Más allá de escribir algoritmos que funcionen, un programador profesional debe saber cómo construir **módulos de software** que otros puedan utilizar de manera fácil, segura y predecible. En C, la puerta de entrada a un módulo es su **interfaz pública** o **API** (Application Programming Interface), definida casi siempre en un archivo de cabecera (`.h`).

Una API es un contrato formal. Define qué funcionalidades ofrece un módulo, qué datos necesita y qué resultados garantiza. Un buen diseño de interfaz es la diferencia entre una librería que es un placer utilizar y una que es una fuente constante de errores y frustración. Este contrato no es solo a nivel de código fuente (API), sino también a nivel binario (ABI - Application Binary Interface), determinando cómo el código compilado interactúa con otro.

La noción de "contrato" fue formalizada por Bertrand Meyer en su metodología de **Diseño por Contrato** (*Design by Contract*) [@meyer1988], donde las precondiciones, poscondiciones e invariantes definen obligaciones y garantías entre el cliente y el proveedor de un servicio. Aunque Meyer desarrolló esta metodología en el contexto de Eiffel, sus principios son universalmente aplicables y particularmente valiosos en C, donde la falta de mecanismos de seguridad del lenguaje hace que los contratos explícitos sean aún más críticos.

Este apunte establece los lineamientos para diseñar interfaces de alta calidad en C, aplicando los principios de la descomposición funcional y las reglas de estilo para crear código que no solo es correcto, sino también elegante y mantenible.

### El Desafío del Diseño en C

C es un lenguaje minimalista que delega gran parte de la responsabilidad de seguridad y corrección al programador. A diferencia de lenguajes modernos con sistemas de tipos más ricos, manejo automático de memoria o espacios de nombres modulares, C ofrece pocas herramientas para encapsulamiento y abstracción. Esta aparente limitación es también su fortaleza: la simplicidad y el control directo que brinda C son la razón por la cual sigue siendo el lenguaje de elección para sistemas operativos, drivers, sistemas embebidos y software de alto rendimiento [@kernighan1988].

El diseño de APIs en C requiere disciplina y conocimiento profundo de los patrones idiomáticos del lenguaje. Como señalan Spinellis y Gousios [@spinellis2009], el código bien diseñado no es accidental; es el resultado de decisiones conscientes y la aplicación sistemática de principios de ingeniería de software.

## Principios Fundamentales del Diseño de Interfaces

Un buen diseño de API se rige por un conjunto de principios que buscan maximizar la claridad, la seguridad y la facilidad de uso.

(api-claridad)= 
### 1. Claridad y Expresividad

Una interfaz debe ser auto-documentada en la medida de lo posible. El código debe comunicar su intención de forma clara y directa. Como observa Martin [@martin2008], "el código se lee muchas más veces de las que se escribe", por lo que invertir en claridad es una optimización fundamental.

- **Nombres Descriptivos**: Los nombres de las funciones deben ser verbos que describan la acción que realizan. Los nombres de los tipos y parámetros deben ser sustantivos claros. Esto sigue la regla {ref}`0x0001h`.

  :::{code-block} c
  // Malo: Nombres ambiguos y poco informativos.
  void process_list(list *l, int d);

  // Bueno: Nombres claros, específicos y con prefijo.
  lista_t *lista_crear(void);
  bool lista_agregar_al_final(lista_t *lista, int dato);
  :::

  La elección de nombres tiene consecuencias cognitivas profundas. Un estudio de Lawrie et al. [@lawrie2006] demostró empíricamente que los nombres más largos y descriptivos mejoran significativamente la comprensibilidad del código, reduciendo el tiempo necesario para entender su propósito y funcionamiento.

- **Consistencia en la Nomenclatura**: Adoptá un prefijo común para todas las funciones y tipos públicos de tu librería (ej. `lista_`). En C, todos los símbolos públicos comparten un único espacio de nombres global. El uso de prefijos previene **colisiones de nombres** con otras librerías o con el propio código del usuario, un problema que puede generar errores de enlazado (`linker`) muy difíciles de diagnosticar.

  Este patrón es usado universalmente en la biblioteca estándar de C (todas las funciones de cadenas comienzan con `str`, las de entrada/salida con variantes de `f` o `printf`, etc.) y en librerías profesionales como GTK+ (prefijo `gtk_` y `g_`), OpenSSL (prefijo `SSL_` y `EVP_`), y SQLite (prefijo `sqlite3_`).

- **Documentación Rigurosa**: Cada función pública debe estar documentada siguiendo la regla {ref}`0x000Ah`. El contrato, definido por las precondiciones y poscondiciones, debe ser explícito. Esto no es mera formalidad; es una especificación del comportamiento esperado, crucial para la depuración y la verificación formal.

  La especificación formal de interfaces mediante contratos permite aplicar técnicas de verificación estática y testing basado en propiedades (*property-based testing*) [@claessen2000], aumentando drásticamente la confiabilidad del software.

(api-sorpresa)= 
### 2. Principio de Mínima Sorpresa

Una función o librería debe comportarse de la manera que un programador esperaría razonablemente. Evitá la "magia" y los comportamientos inesperados que obligan al usuario a leer la implementación para entender qué está pasando.

El *Principio de Mínima Sorpresa* (también conocido como *Principle of Least Astonishment*) fue popularizado por la filosofía de diseño Unix [@raymond2003] y establece que el sistema debe comportarse de la manera que la mayoría de los usuarios esperaría. En el contexto de APIs, esto significa que las funciones deben ser consistentes con convenciones establecidas y con el comportamiento de funciones similares.

Bloch [@bloch2006] enfatiza que una buena API debe ser "fácil de usar y difícil de usar mal". Esto se logra cuando el comportamiento predeterminado es el más común y seguro, y cuando las operaciones peligrosas requieren pasos explícitos que alertan al programador sobre lo que está haciendo.

Por ejemplo, si una función modifica sus argumentos, esto debe ser evidente desde su firma y nombre. La biblioteca estándar de C lo hace consistentemente: `strcpy` copia cadenas y modifica el destino (el primer parámetro es siempre el destino), mientras que `strlen` solo lee y no modifica nada. Cuando una interfaz viola las expectativas del usuario, la carga cognitiva aumenta, introduciendo errores y frustraciones evitables.

- **Simetría**: Las operaciones deben tener contrapartes lógicas. Si tenés una función `recurso_crear()`, debés proveer una `recurso_destruir()`. Esta simetría, mencionada en la regla {ref}`0x001Ah`, es una manifestación del patrón **RAII (Resource Acquisition Is Initialization)**, aunque adaptado a C. Ayuda a gestionar el ciclo de vida de los recursos de forma predecible, previniendo fugas de memoria (`memory leaks`).

  En lenguajes como C++, RAII es automático mediante constructores y destructores. En C, debe implementarse manualmente mediante pares de funciones simétricas. La biblioteca estándar de C demuestra este patrón consistentemente: `fopen`/`fclose`, `malloc`/`free`, `pthread_create`/`pthread_join`, etc.

  :::{important}
  **Gestión de Recursos y Fugas de Memoria**

  Las fugas de memoria (*memory leaks*) son uno de los problemas más comunes y peligrosos en programas C. Un estudio de Li y Zhou [@li2005] sobre bugs en sistemas operativos encontró que los errores de manejo de memoria representan aproximadamente el 40% de los fallos críticos. El diseño simétrico de APIs ayuda a prevenir estos errores haciendo explícita la responsabilidad de liberación de recursos.
  :::

- **Efectos Secundarios Claros**: Si una función modifica el estado de uno de sus argumentos (un efecto secundario), esto debe ser evidente en su nombre y estar claramente documentado. Es preferible devolver resultados a modificar parámetros de salida (`out-parameters`), ya que esto último puede hacer el flujo de datos más difícil de seguir. Cuando un parámetro de salida es inevitable, su propósito debe ser inequívoco.

  :::{code-block} c
  // El nombre deja claro que la cadena será modificada "in-place".
  void cadena_convertir_a_mayusculas(char *cadena);

  // Un parámetro de salida. El nombre indica qué se obtendrá.
  bool obtener_temperatura_sensor(sensor_t *sensor, double *temperatura_out);
  :::

  La programación funcional, con su énfasis en funciones puras sin efectos secundarios, ha demostrado ventajas significativas en razonamiento y testing [@hughes1989]. Aunque C no es un lenguaje funcional, minimizar y hacer explícitos los efectos secundarios acerca el código a estas ventajas.

(api-ocultamiento)= 
### 3. Encapsulamiento y Ocultamiento de Información

El usuario de tu librería no necesita (y no debe) conocer los detalles internos de su implementación. La interfaz pública (`.h`) debe exponer el **qué** (la capacidad), mientras que la implementación (`.c`) oculta el **cómo** (los detalles).

El mecanismo más potente para lograr esto en C es el uso de **punteros opacos** (opaque pointers), que permiten una verdadera abstracción de datos.

#### Punteros Opacos: La Clave de la Abstracción en C

Un puntero opaco es un puntero a un tipo de estructura cuya definición está incompleta en el archivo de cabecera. El usuario sabe que existe un tipo `mi_tipo_t`, pero no conoce sus campos internos, su tamaño, ni su organización en memoria.

Este patrón, también conocido como **PIMPL** (*Pointer to IMPLementation*) o **Tipo Abstracto de Datos** (TAD), es la forma idiomática en C de lograr encapsulamiento real. Aunque el concepto de tipos abstractos de datos fue formalizado por Liskov y Zilles [@liskov1974], su implementación en C mediante punteros opacos se popularizó en los años 80 y es hoy una práctica estándar en todas las librerías C profesionales.

El trabajo seminal de Liskov y Zilles sobre TADs estableció que un tipo de datos debe definirse por sus operaciones y sus propiedades algebraicas, no por su representación interna. En C, los punteros opacos son la herramienta fundamental para lograr esta separación entre interfaz e implementación, permitiendo lo que Parnas [@parnas1972] llamó *information hiding* (ocultamiento de información): el principio de que los módulos deben revelar lo mínimo indispensable sobre su funcionamiento interno.

- **En el archivo de cabecera (`mi_libreria.h`):** 
  :::{code-block} c
  // 1. Declaración adelantada (forward declaration) de la estructura.
  // El compilador sabe que "struct mi_tipo" es un tipo, pero no conoce su contenido.
  struct mi_tipo;

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
  struct mi_tipo {
      int valor_secreto;
      void *otro_dato_interno;
  };

  // 5. Implementación de las funciones.
  mi_tipo_t *mi_tipo_crear(int valor_inicial) {
      // Aquí sí podemos usar sizeof, porque la definición completa es visible.
      mi_tipo_t *nuevo = malloc(sizeof(struct mi_tipo));
      if (nuevo != NULL) {
          nuevo->valor_secreto = valor_inicial;
      }
      return nuevo;
  }
  // ... resto de implementaciones ...
  :::

**Ventajas Técnicas:**
- **Abstracción Total**: El usuario no puede acceder a `valor_secreto` directamente (ej. `objeto->valor_secreto` fallaría al compilar). La única forma de interactuar es a través de la API, lo que garantiza que los invariantes de la estructura se mantengan.

- **Estabilidad del ABI (Application Binary Interface)**: Esta es la ventaja más importante desde el punto de vista de la ingeniería de software a gran escala. Si la definición de la `struct` estuviera en el `.h`, cualquier cambio (agregar un campo, reordenarlos) modificaría el tamaño y el layout de la estructura. Esto **rompería la compatibilidad binaria**, obligando a todos los programas que usan la librería a ser recompilados. Con un puntero opaco, podés modificar la estructura interna libremente; mientras la firma de las funciones públicas no cambie, la librería puede ser actualizada sin necesidad de recompilar el software cliente.

  La estabilidad del ABI es crítica en sistemas operativos y bibliotecas compartidas. Como documenta Drepper [@drepper2011] en su guía sobre el desarrollo de bibliotecas dinámicas, la ruptura del ABI puede causar fallos catastróficos en sistemas en producción, donde múltiples aplicaciones dependen de una versión específica de una biblioteca. Los punteros opacos son la técnica principal para mantener esta estabilidad.

- **Flexibilidad de Implementación**: Podés cambiar completamente la representación interna sin afectar al código cliente. Por ejemplo, podés empezar con una implementación basada en arrays y luego cambiar a una basada en árboles para mejorar el rendimiento, sin que ningún usuario de la API necesite modificar su código.

- **Soporte para Múltiples Implementaciones**: Es posible tener diferentes implementaciones del mismo TAD (por ejemplo, una optimizada para memoria y otra para velocidad) que comparten la misma interfaz pública, permitiendo al usuario elegir en tiempo de compilación o enlace.

(api-propiedad)= 
### 4. Gestión de Recursos y Propiedad (Ownership)

Una de las mayores fuentes de errores en C es la gestión de memoria. Tu API debe ser explícita sobre quién es el responsable (`owner`) de asignar y liberar cada recurso.

El concepto de *ownership* (propiedad) es fundamental en la programación de sistemas. Aunque lenguajes modernos como Rust lo formalizan en el sistema de tipos, en C debe ser documentado explícitamente y seguido disciplinadamente. La falta de claridad sobre la propiedad de los recursos es una causa principal de fugas de memoria (*memory leaks*), dobles liberaciones (*double free*) y accesos a memoria liberada (*use-after-free*) [@serebryany2012].

Un estudio de Lu et al. [@lu2008] sobre bugs en sistemas de código abierto encontró que los errores de manejo de memoria y concurrencia representan más del 60% de los bugs críticos que causan crashes y vulnerabilidades de seguridad. El diseño cuidadoso de APIs con semánticas claras de propiedad puede prevenir una gran proporción de estos errores.

- **Documentar la Propiedad**: Como exige la regla {ref}`0x020Fh`, la documentación de cada función debe indicar claramente quién es el dueño de la memoria. Si una función devuelve un puntero a memoria recién asignada, el comentario debe decir que el llamador es responsable de liberarla. Definí un modelo de propiedad claro:
    - **Propiedad del Llamador (Caller-owned)**: El llamador aloja y libera la memoria. La función solo opera sobre ella. Es común para búferes que la función debe llenar.
    - **Propiedad de la Librería (Callee-owned)**: La librería gestiona el ciclo de vida. `mi_libreria_crear()` aloja la memoria y `mi_libreria_destruir()` la libera. Este es el modelo preferido para punteros opacos.
    - **Propiedad Transferida**: La función toma posesión del recurso pasado como argumento y es responsable de liberarlo. Esto debe ser extremadamente explícito en la documentación.
    - **Propiedad Compartida**: Múltiples partes del código mantienen referencias al mismo recurso. En C puro, esto usualmente requiere conteo de referencias manual (como en `fopen`/`fclose`, donde múltiples handles pueden apuntar al mismo recurso del sistema operativo).

:::{important}
**Semánticas de Movimiento vs. Copia**

Cuando una función recibe un puntero a una estructura compleja, debe ser claro si la función hace una copia interna del dato o simplemente guarda el puntero. Si guarda el puntero, el llamador debe asegurarse de que la memoria permanezca válida durante toda la vida útil del objeto. Esta distinción entre *shallow copy* (copia superficial) y *deep copy* (copia profunda) es crítica y debe estar documentada explícitamente.
:::

- **Uso de `const` para Clarificar Intenciones**: Utilizá `const` para indicar que una función no modificará los datos apuntados por un puntero (regla {ref}`0x0021h`). Esto no solo previene efectos secundarios no deseados, sino que permite al compilador realizar optimizaciones y le da confianza al usuario.

  El uso correcto de `const` es más que una convención de estilo; es una forma de documentación ejecutable que el compilador puede verificar. Como señala Meyers [@meyers2005], `const` debe usarse siempre que sea semánticamente correcto, ya que comunica intención y permite al compilador detectar errores.

  :::{code-block} c
  // La función promete no modificar ni la estructura de la lista
  // ni el dato que se le pasa para buscar.
  bool lista_contiene(const lista_t *lista, const char *dato);
  :::

(api-errores)= 
### 5. Manejo de Errores Robusto y Consistente

Una librería no debe terminar el programa abruptamente (ej. con `exit()`). Debe reportar los errores al llamador para que este decida cómo proceder.

- **Establecer un Mecanismo de Error Consistente**: Sé predecible. Si tus funciones devuelven punteros, `NULL` es el indicador de error universal. Si devuelven enteros, usá un valor específico como `-1` o, mejor aún, un tipo enumerado (`enum`) o constantes definidas con `#define` para los códigos de error (regla {ref}`0x0012h`).

  :::{code-block} c
  typedef enum {
      LISTA_OK = 0,
      LISTA_ERROR_NO_ENCONTRADO = -1,
      LISTA_ERROR_MEMORIA = -2
  } lista_error_t;
  :::

- **Evitar `printf` y `exit`**: Una librería es un componente, no un programa completo. No debe asumir que tiene control sobre la consola o el ciclo de vida del proceso. Su única responsabilidad es ejecutar su tarea e informar el resultado (éxito o fracaso).

- **Proveer Información Adicional**: Para APIs complejas, es útil ofrecer una función que permita obtener una descripción textual del último error ocurrido. Esto es más flexible que `perror`, ya que el llamador puede decidir si mostrar el mensaje, guardarlo en un log, etc.

  :::{code-block} c
  const char *mi_libreria_ultimo_error_str(void);
  :::

(api-minimalismo)= 
### 6. Simplicidad y Minimalismo

Una buena interfaz es aquella que es lo más pequeña posible, pero no más. Cada función expuesta públicamente aumenta la "superficie de ataque" (potenciales bugs y vulnerabilidades) y la carga de mantenimiento.

- **Exponer solo lo necesario (Internal Linkage)**: Si una función es una ayuda interna para otras funciones de la librería, declarala como `static` en el archivo `.c`. Esto le da "enlace interno" (`internal linkage`), haciéndola invisible para el enlazador fuera de esa unidad de compilación.

- **Ortogonalidad**: Diseñá un conjunto de funciones primitivas y ortogonales (independientes) que puedan ser combinadas de formas potentes. Es preferible tener `lista_agregar()` y `lista_ordenar()` que una única y monolítica `lista_agregar_y_ordenar()`.

- **Evitar la Complejidad Prematura**: No agregues funcionalidades que "podrían ser útiles en el futuro". Diseñá una API que resuelva el problema actual de forma elegante. Es más fácil agregar funciones después que quitarlas, ya que quitar una función rompe la compatibilidad con versiones anteriores.

## Ejemplos Prácticos de Diseño de APIs

Los principios anteriores cobran vida cuando se aplican a problemas reales. A continuación se presentan ejemplos concretos que ilustran cómo diseñar interfaces robustas y mantenibles en C.

(api-ejemplo-lista)= 
### Ejemplo 1: Diseño de una Lista Enlazada

Una lista enlazada es una estructura de datos fundamental que ejemplifica perfectamente los principios de diseño de APIs. El objetivo es ofrecer una interfaz que oculte la complejidad interna de la gestión de nodos y memoria.

#### Archivo de Cabecera (`lista.h`)

:::{code-block} c
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
 * @post Todos los nodos internos son liberados. El puntero lista queda inválido.
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
:::

**Análisis del Diseño:**

- **Puntero Opaco ({ref}`api-ocultamiento`)**: La estructura `lista_t` es completamente opaca. El usuario no puede acceder directamente a los nodos internos, lo que permite cambiar la implementación sin romper el código cliente.

- **Gestión de Recursos Explícita ({ref}`api-propiedad`)**: Las funciones `lista_crear()` y `lista_destruir()` forman un par simétrico, siguiendo la regla {ref}`0x001Ah`. La documentación especifica claramente que el llamador es responsable de llamar a `lista_destruir()`.

- **Uso de `const` ({ref}`0x0021h`)**: `lista_largo()` y `lista_contiene()` reciben `const lista_t *`, indicando que no modificarán la lista. Esto permite al compilador optimizar y comunica la intención al usuario.

- **Manejo de Errores Consistente ({ref}`api-errores`)**: Las funciones que pueden fallar (como `lista_crear()` y `lista_agregar()`) devuelven un valor que indica éxito o fracaso (`NULL` o `bool`). No hay `printf` ni `exit` en la librería.

- **Prefijo Consistente ({ref}`api-claridad`)**: Todas las funciones públicas usan el prefijo `lista_`, evitando colisiones de nombres en el espacio de nombres global de C.

(api-ejemplo-calculadora)= 
### Ejemplo 2: Módulo de Operaciones Matemáticas Seguras

Un módulo que realiza operaciones matemáticas básicas con manejo de errores robusto demuestra cómo diseñar una API que reporta errores sin terminar el programa.

#### Archivo de Cabecera (`matematica.h`)

:::{code-block} c
:linenos:
#ifndef MATEMATICA_H
#define MATEMATICA_H

#include <stdbool.h>

/**
 * Códigos de error para operaciones matemáticas.
 */
typedef enum {
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
 * @returns MAT_OK si la operación fue exitosa, MAT_ERROR_DIVISION_CERO en caso contrario.
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
:::

#### Ejemplo de Implementación (`matematica.c`)

:::{code-block} c
:linenos:
#include "matematica.h"
#include <math.h>

mat_error_t mat_dividir(int dividendo, int divisor, int *resultado)
{
    if (divisor == 0) {
        return MAT_ERROR_DIVISION_CERO;
    }
    *resultado = dividendo / divisor;
    return MAT_OK;
}

mat_error_t mat_raiz_cuadrada(int n, int *resultado)
{
    if (n < 0) {
        return MAT_ERROR_RAIZ_NEGATIVA;
    }
    *resultado = (int)sqrt(n);
    return MAT_OK;
}

const char *mat_error_str(mat_error_t error)
{
    switch (error) {
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
:::

#### Ejemplo de Uso

:::{code-block} c
:linenos:
#include <stdio.h>
#include "matematica.h"

int main(void)
{
    int resultado = 0;
    mat_error_t error = MAT_OK;

    // División segura
    error = mat_dividir(10, 2, &resultado);
    if (error == MAT_OK) {
        printf("10 / 2 = %d\n", resultado);
    } else {
        printf("Error: %s\n", mat_error_str(error));
    }

    // Intento de división por cero
    error = mat_dividir(10, 0, &resultado);
    if (error != MAT_OK) {
        printf("Error detectado: %s\n", mat_error_str(error));
    }

    return 0;
}
:::

**Análisis del Diseño:**

- **Tipo Enumerado para Errores ({ref}`0x0012h`)**: El uso de `mat_error_t` hace que los códigos de error sean legibles y auto-documentados, superior a valores mágicos como `-1`.

- **Parámetros de Salida Explícitos**: El resultado se devuelve a través de un puntero, mientras que el valor de retorno de la función indica el éxito o fracaso. Esto sigue el patrón estándar de muchas APIs de C (similar a `scanf`).

- **No Modificación en Caso de Error**: Las poscondiciones garantizan que si una función falla, no modifica el parámetro de salida. Esto previene el uso de datos no inicializados.

- **Función Auxiliar para Mensajes**: `mat_error_str()` permite al llamador decidir cómo manejar los mensajes de error (mostrarlos, guardarlos en un log, etc.), sin que la librería asuma control sobre la salida.

(api-ejemplo-archivo-config)= 
### Ejemplo 3: Lector de Archivos de Configuración

Un módulo que lee archivos de configuración simple (formato clave=valor) ilustra cómo diseñar APIs que gestionan recursos del sistema de forma segura.

#### Archivo de Cabecera (`config.h`)

:::{code-block} c
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
const char *config_obtener_cadena(const config_t *config,
                                   const char *clave,
                                   const char *valor_defecto);

/**
 * Obtiene un valor de configuración como entero.
 *
 * @param config Configuración a consultar.
 * @param clave Nombre de la clave a buscar.
 * @param valor_defecto Valor a retornar si la clave no existe o no es un entero válido.
 * @returns El valor entero asociado a la clave, o valor_defecto.
 * @pre config != NULL, clave != NULL
 */
int config_obtener_entero(const config_t *config,
                          const char *clave,
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
:::

**Análisis del Diseño:**

- **Valores por Defecto**: Las funciones de consulta permiten especificar un valor por defecto, haciendo que el código cliente sea más simple y robusto.

- **Propiedad de Memoria Clara**: La documentación especifica que las cadenas retornadas son propiedad de la librería. El llamador no debe intentar liberarlas ni modificarlas.

- **Ortogonalidad ({ref}`api-minimalismo`)**: Hay funciones específicas para cada tipo de dato (`config_obtener_cadena`, `config_obtener_entero`), en lugar de una única función genérica compleja.

- **Uso Consistente de `const`**: Los parámetros que no son modificados están marcados como `const`, tanto los punteros a estructuras opacas como las cadenas.

## Patrones Comunes de Diseño en C

Además de los principios fundamentales, existen patrones de diseño que han demostrado ser efectivos en el desarrollo de APIs en C.

(api-patron-constructor-destructor)= 
### Patrón Constructor/Destructor

Este patrón garantiza que cada recurso tenga un ciclo de vida bien definido. Para cada función `X_crear()`, debe existir una `X_destruir()` correspondiente, como exige la regla {ref}`0x001Ah`.

:::{code-block} c
// Constructor: reserva memoria y la inicializa
recurso_t *recurso_crear(void);

// Destructor: libera memoria y recursos del sistema
void recurso_destruir(recurso_t *recurso);
:::

**Ventajas:**
- Previene fugas de memoria (_memory leaks_).
- Hace explícito el ciclo de vida de los recursos.
- Facilita la gestión de recursos del sistema (archivos, sockets, etc.).

(api-patron-init-finalize)= 
### Patrón Init/Finalize

Cuando el usuario provee la memoria (por ejemplo, una variable en el stack), se utiliza un par de funciones de inicialización y finalización.

:::{code-block} c
typedef struct buffer {
    char datos[1024];
    size_t usado;
} buffer_t;

// Inicializa un buffer provisto por el usuario
void buffer_init(buffer_t *buffer);

// Limpia los recursos internos, pero no libera buffer
void buffer_finalize(buffer_t *buffer);
:::

**Uso:**
:::{code-block} c
buffer_t mi_buffer;  // En el stack
buffer_init(&mi_buffer);
// ... usar el buffer ...
buffer_finalize(&mi_buffer);
:::

Este patrón es útil cuando se quiere evitar asignaciones dinámicas o cuando el tamaño del objeto es conocido en tiempo de compilación. También es preferible en sistemas embebidos donde la asignación dinámica puede no estar disponible o es indeseable por razones de determinismo temporal.

:::{note}
**Init/Finalize vs Create/Destroy**

La elección entre estos patrones depende del contexto de uso:

- **Create/Destroy**: Apropiado cuando el tamaño del objeto puede variar o cuando se necesita gestión dinámica de múltiples instancias. La librería tiene control total sobre la memoria.

- **Init/Finalize**: Apropiado para objetos de tamaño fijo que pueden vivir en el stack, arrays estáticos, o cuando se requiere control preciso sobre la ubicación de la memoria (por ejemplo, en memoria compartida o regiones de memoria específicas del hardware).

Muchas APIs profesionales ofrecen ambas alternativas para máxima flexibilidad. Por ejemplo, `pthread_mutex_t` de POSIX puede ser inicializado estáticamente o dinámicamente [@ieee2018].
:::

(api-patron-getter-setter)= 
### Patrón Getter/Setter

Para estructuras opacas, se proveen funciones de acceso que mantienen la encapsulación.

:::{code-block} c
// Getter: obtiene un valor (no modifica la estructura)
int punto_obtener_x(const punto_t *punto);

// Setter: modifica un valor
void punto_establecer_x(punto_t *punto, int nuevo_x);
:::

**Ventajas:**
- Permite validación antes de asignar valores, manteniendo los invariantes del tipo abstracto.
- Facilita el mantenimiento de invariantes y la verificación de contratos.
- Permite agregar logging, debugging, o instrumentación sin cambiar la API pública.
- Habilita la implementación de estrategias de copia-en-escritura (*copy-on-write*) o caching transparente.

**Consideraciones de Performance:**

El patrón getter/setter introduce una indirección adicional (una llamada a función) comparado con el acceso directo a campos. En código crítico de rendimiento, esto puede ser una preocupación. Sin embargo:

1. Los compiladores modernos con optimización activada pueden realizar *inlining* de funciones getter/setter simples, eliminando el overhead.
2. En la mayoría de los programas, el costo de la abstracción es despreciable comparado con los beneficios de mantenibilidad y evolución del código.
3. Como enfatiza Knuth [@knuth1974]: "La optimización prematura es la raíz de todos los males". Optimizá solo después de medir y cuando sea realmente necesario.

## Antipatrones: Qué Evitar

Tan importante como saber qué hacer es saber qué NO hacer. Los siguientes son errores comunes en el diseño de APIs en C.

(api-antipatron-magic-numbers)= 
### Antipatrón 1: Números Mágicos en la Interfaz

:::{code-block} c
// MALO: ¿Qué significa 0? ¿Qué significa 1?
int archivo_abrir(const char *nombre, int modo);

// Uso poco claro
archivo_abrir("datos.txt", 1);
:::

:::{code-block} c
// BUENO: Usar constantes o enumerados
typedef enum {
    ARCHIVO_LECTURA = 0,
    ARCHIVO_ESCRITURA = 1,
    ARCHIVO_LECTURA_ESCRITURA = 2
} archivo_modo_t;

int archivo_abrir(const char *nombre, archivo_modo_t modo);

// Uso claro
archivo_abrir("datos.txt", ARCHIVO_ESCRITURA);
:::

Este antipatrón viola la regla {ref}`0x0012h`, que exige usar constantes simbólicas para valores especiales.

(api-antipatron-funciones-globales)= 
### Antipatrón 2: Estado Global Oculto

:::{code-block} c
// MALO: Estado interno global no visible
void motor_inicializar(void);
void motor_procesar(void);  // ¿Sobre qué datos opera?
:::

El uso de estado global hace que la API sea difícil de testear, imposible de usar de forma concurrente (múltiples hilos) y viola el principio de encapsulamiento. El estado global es una de las principales fuentes de acoplamiento en sistemas de software [@parnas1972], dificultando la comprensión, el testing y la evolución del código.

:::{important}
**Estado Global y Concurrencia**

En programas multi-hilo, el estado global compartido es una fuente primaria de *race conditions* y comportamiento no determinista. Un estudio de Lu et al. [@lu2008] encontró que más del 30% de los bugs de concurrencia en sistemas de código abierto están relacionados con estado global mal sincronizado. 

El diseño de APIs sin estado global no solo mejora la testabilidad, sino que también facilita la escritura de código concurrente correcto, ya que cada instancia del objeto puede ser usada independientemente por diferentes hilos sin necesidad de sincronización adicional.
:::

:::{code-block} c
// BUENO: El estado es explícito
motor_t *motor_crear(void);
void motor_procesar(motor_t *motor);
void motor_destruir(motor_t *motor);
:::

(api-antipatron-boolean-trap)= 
### Antipatrón 3: Trampa Booleana (_Boolean Trap_)

:::{code-block} c
// MALO: ¿Qué significa true? ¿Qué significa false?
void ventana_crear(int ancho, int alto, bool visible, bool modal);

// Uso confuso
ventana_crear(800, 600, true, false);  // ¿Qué hace cada bool?
:::

Este antipatrón, identificado por Reddy [@reddy2011] como uno de los errores más comunes en diseño de APIs, surge cuando se usan parámetros booleanos cuyo significado no es evidente en el punto de llamada. El problema se agrava cuando hay múltiples parámetros booleanos consecutivos, ya que es fácil confundir su orden.

:::{code-block} c
// BUENO: Usar enums con nombres descriptivos
typedef enum { VENTANA_OCULTA, VENTANA_VISIBLE } ventana_visibilidad_t;
typedef enum { VENTANA_NO_MODAL, VENTANA_MODAL } ventana_modalidad_t;

void ventana_crear(int ancho, int alto, 
                   ventana_visibilidad_t visibilidad,
                   ventana_modalidad_t modalidad);

// Uso claro
ventana_crear(800, 600, VENTANA_VISIBLE, VENTANA_NO_MODAL);
:::

La solución es reemplazar los booleanos por tipos enumerados que hagan explícito el significado de cada valor. Esto mejora dramáticamente la legibilidad y previene errores sutiles causados por invertir accidentalmente el orden de los argumentos.

(api-antipatron-out-params)= 
### Antipatrón 4: Abuso de Parámetros de Salida

:::{code-block} c
// MALO: Demasiados parámetros de salida
void parsear_fecha(const char *cadena, int *dia, int *mes, int *anio, bool *valida);

// Uso tedioso y propenso a errores
int d = 0, m = 0, a = 0;
bool ok = false;
parsear_fecha("2024-03-15", &d, &m, &a, &ok);
:::

:::{code-block} c
// BUENO: Retornar una estructura
typedef struct {
    int dia;
    int mes;
    int anio;
} fecha_t;

bool parsear_fecha(const char *cadena, fecha_t *resultado);

// Uso más limpio
fecha_t fecha = {0};
if (parsear_fecha("2024-03-15", &fecha)) {
    // usar fecha.dia, fecha.mes, fecha.anio
}
:::

## Versionado y Compatibilidad

Un aspecto crítico del diseño de APIs profesionales es la gestión de versiones y la compatibilidad hacia atrás (_backwards compatibility_).

### Versionado Semántico

Se recomienda seguir el esquema **MAJOR.MINOR.PATCH** propuesto por Preston-Werner [@preston2013]:

- **MAJOR**: Cambios incompatibles en la API (rompen código existente). Ejemplo: eliminar una función pública, cambiar la firma de una función, modificar el comportamiento documentado de forma incompatible.
- **MINOR**: Nuevas funcionalidades compatibles hacia atrás. Ejemplo: agregar nuevas funciones, agregar parámetros opcionales con valores predeterminados, agregar nuevos valores a enumeraciones existentes (con cuidado).
- **PATCH**: Correcciones de bugs compatibles hacia atrás. Ejemplo: corregir fugas de memoria, corregir comportamiento que no coincide con la documentación, mejorar performance sin cambiar la API.

El versionado semántico comunica explícitamente el impacto de actualizar una dependencia. Un cambio de versión `1.2.3` a `1.2.4` garantiza que es seguro actualizar sin revisar código, mientras que un cambio a `2.0.0` indica que se requiere revisión y posiblemente modificaciones.

:::{tip}
**Estabilidad del ABI**

El versionado semántico se aplica típicamente a la API (interfaz a nivel de código fuente). Sin embargo, en bibliotecas dinámicas (`.so` en Linux, `.dll` en Windows), también es crucial mantener la estabilidad del ABI (Application Binary Interface). Cambios que preservan la API pero rompen el ABI incluyen: modificar el tamaño de estructuras públicas, reordenar campos, cambiar convenciones de llamada, etc.

Para bibliotecas que deben mantener estabilidad del ABI, el uso de punteros opacos como se describe en {ref}`api-ocultamiento` es esencial.
:::

### Estrategias de Evolución

Cuando es necesario cambiar una función existente:

1. **Deprecación Gradual**: Mantener la función antigua, marcarla como obsoleta, y ofrecer una alternativa.

:::{code-block} c
// Función antigua (deprecada)
// DEPRECADO: Usar lista_agregar_v2() en su lugar
bool lista_agregar(lista_t *lista, int dato);

// Nueva función
bool lista_agregar_v2(lista_t *lista, int dato, size_t *indice_out);
:::

2. **Sobrecarga por Nombre**: Dado que C no soporta sobrecarga de funciones, se usan nombres distintos.

:::{code-block} c
void dibujar_rectangulo(int x, int y, int ancho, int alto);
void dibujar_rectangulo_ex(int x, int y, int ancho, int alto, color_t color);
:::

3. **Uso de Estructuras de Opciones**: Para funciones con muchos parámetros opcionales, se puede usar una estructura de configuración.

:::{code-block} c
typedef struct {
    int ancho;
    int alto;
    color_t color;
    bool borde;
    int grosor_borde;
} rectangulo_config_t;

// Configuración por defecto
rectangulo_config_t rectangulo_config_defecto(void);

// Función que acepta configuración
void dibujar_rectangulo_config(int x, int y, const rectangulo_config_t *config);
:::

## Ejercicios sobre Diseño de APIs

```{exercise}
:label: api_pila_basica
:enumerator: api-1

Diseñá la interfaz (archivo `.h`) para una pila (_stack_) de enteros. La pila debe soportar las operaciones básicas: crear, destruir, apilar (_push_), desapilar (_pop_), y consultar el tope sin desapilar (_peek_). Incluí documentación completa con precondiciones y poscondiciones para cada función.

**Requisitos:**
- Usar un tipo opaco `pila_t`.
- Seguir el patrón constructor/destructor.
- Especificar claramente la gestión de memoria.
- Indicar cómo se reportan los errores (ej. pila vacía al desapilar).
```

````{solution} api_pila_basica
:class: dropdown

```{code-block} c
:linenos:
#ifndef PILA_H
#define PILA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Tipo opaco que representa una pila de enteros.
 */
typedef struct pila pila_t;

/**
 * Crea una nueva pila vacía.
 *
 * @returns Puntero a la nueva pila, o NULL si falla la asignación de memoria.
 * @post El llamador debe liberar la memoria con pila_destruir().
 */
pila_t *pila_crear(void);

/**
 * Destruye una pila y libera toda la memoria asociada.
 *
 * @param pila Puntero a la pila a destruir.
 * @post Todos los elementos son liberados. El puntero pila queda inválido.
 */
void pila_destruir(pila_t *pila);

/**
 * Apila un elemento en el tope de la pila.
 *
 * @param pila Pila donde apilar el elemento.
 * @param dato Valor entero a apilar.
 * @returns true si se apiló exitosamente, false si falló la asignación.
 * @pre pila != NULL
 */
bool pila_apilar(pila_t *pila, int dato);

/**
 * Desapila y retorna el elemento del tope de la pila.
 *
 * @param pila Pila de donde desapilar.
 * @param dato Puntero donde almacenar el elemento desapilado.
 * @returns true si se desapiló exitosamente, false si la pila estaba vacía.
 * @pre pila != NULL, dato != NULL
 * @post Si retorna true, *dato contiene el valor desapilado.
 */
bool pila_desapilar(pila_t *pila, int *dato);

/**
 * Consulta el elemento en el tope de la pila sin desapilarlo.
 *
 * @param pila Pila a consultar.
 * @param dato Puntero donde almacenar el elemento del tope.
 * @returns true si hay un elemento, false si la pila está vacía.
 * @pre pila != NULL, dato != NULL
 */
bool pila_peek(const pila_t *pila, int *dato);

/**
 * Verifica si la pila está vacía.
 *
 * @param pila Pila a verificar.
 * @returns true si la pila está vacía, false en caso contrario.
 * @pre pila != NULL
 */
bool pila_esta_vacia(const pila_t *pila);

/**
 * Obtiene el número de elementos en la pila.
 *
 * @param pila Pila a consultar.
 * @returns Cantidad de elementos en la pila.
 * @pre pila != NULL
 */
size_t pila_tamano(const pila_t *pila);

#endif // PILA_H
```
````

```{exercise}
:label: api_calculadora_mejorada
:enumerator: api-2

Extendé el módulo `matematica.h` del {ref}`api-ejemplo-calculadora` para incluir operaciones de multiplicación y suma, ambas con detección de desbordamiento (_overflow_). Implementá las funciones y un programa de ejemplo que demuestre el manejo de errores.

**Pistas:**
- Para detectar desbordamiento en la suma: verificar si `a + b < a` (para números sin signo) o usar límites de `INT_MAX`.
- Para la multiplicación: verificar si `a * b / a != b` cuando `a != 0`.
```

````{solution} api_calculadora_mejorada
:class: dropdown

```{code-block} c
:linenos:
// Adiciones a matematica.h

#include <limits.h>  // Para INT_MAX, INT_MIN

/**
 * Suma dos enteros con detección de desbordamiento.
 *
 * @param a Primer sumando.
 * @param b Segundo sumando.
 * @param resultado Puntero donde almacenar el resultado.
 * @returns MAT_OK si la suma es válida, MAT_ERROR_DESBORDAMIENTO en caso contrario.
 * @pre resultado != NULL
 * @post Si retorna MAT_OK, *resultado = a + b.
 */
mat_error_t mat_sumar(int a, int b, int *resultado);

/**
 * Multiplica dos enteros con detección de desbordamiento.
 *
 * @param a Primer factor.
 * @param b Segundo factor.
 * @param resultado Puntero donde almacenar el resultado.
 * @returns MAT_OK si la multiplicación es válida, 
 *          MAT_ERROR_DESBORDAMIENTO en caso contrario.
 * @pre resultado != NULL
 */
mat_error_t mat_multiplicar(int a, int b, int *resultado);
```

```{code-block} c
:linenos:
// Implementación en matematica.c

mat_error_t mat_sumar(int a, int b, int *resultado)
{
    // Detectar desbordamiento positivo
    if (b > 0 && a > INT_MAX - b) {
        return MAT_ERROR_DESBORDAMIENTO;
    }
    // Detectar desbordamiento negativo
    if (b < 0 && a < INT_MIN - b) {
        return MAT_ERROR_DESBORDAMIENTO;
    }
    *resultado = a + b;
    return MAT_OK;
}

mat_error_t mat_multiplicar(int a, int b, int *resultado)
{
    // Casos especiales
    if (a == 0 || b == 0) {
        *resultado = 0;
        return MAT_OK;
    }
    
    // Detectar desbordamiento
    if (a > 0) {
        if (b > 0 && a > INT_MAX / b) {
            return MAT_ERROR_DESBORDAMIENTO;
        }
        if (b < 0 && b < INT_MIN / a) {
            return MAT_ERROR_DESBORDAMIENTO;
        }
    } else { // a < 0
        if (b > 0 && a < INT_MIN / b) {
            return MAT_ERROR_DESBORDAMIENTO;
        }
        if (b < 0 && a < INT_MAX / b) { // a < 0, b < 0
            return MAT_ERROR_DESBORDAMIENTO;
        }
    }
    
    *resultado = a * b;
    return MAT_OK;
}
```

```{code-block} c
:linenos:
// Programa de prueba
#include <stdio.h>
#include "matematica.h"
#include <limits.h>

int main(void)
{
    int resultado = 0;
    mat_error_t error = MAT_OK;

    // Prueba de suma normal
    error = mat_sumar(100, 200, &resultado);
    if (error == MAT_OK) {
        printf("100 + 200 = %d\n", resultado);
    }

    // Prueba de desbordamiento en suma
    error = mat_sumar(INT_MAX, 1, &resultado);
    if (error != MAT_OK) {
        printf("Desbordamiento detectado: %s\n", mat_error_str(error));
    }

    // Prueba de multiplicación con desbordamiento
    error = mat_multiplicar(INT_MAX / 2, 3, &resultado);
    if (error != MAT_OK) {
        printf("Desbordamiento en multiplicación: %s\n", mat_error_str(error));
    }

    return 0;
}
```
````

```{exercise}
:label: api_buffer_circular
:enumerator: api-3

Diseñá e implementá una API para un buffer circular de tamaño fijo. El buffer debe permitir escribir y leer bytes, y debe reportar cuando esté lleno o vacío. Usá el patrón Init/Finalize del {ref}`api-patron-init-finalize`, de forma que el usuario pueda declarar el buffer en el stack.

**Operaciones requeridas:**
- `buffer_init()`: Inicializa un buffer con capacidad especificada.
- `buffer_finalize()`: Limpia recursos internos.
- `buffer_escribir()`: Escribe datos en el buffer.
- `buffer_leer()`: Lee datos del buffer.
- `buffer_disponible()`: Consulta cuántos bytes hay disponibles para leer.
- `buffer_espacio_libre()`: Consulta cuánto espacio hay para escribir.
```

````{solution} api_buffer_circular
:class: dropdown

```{code-block} c
:linenos:
#ifndef BUFFER_CIRCULAR_H
#define BUFFER_CIRCULAR_H

#include <stddef.h>
#include <stdbool.h>

#define BUFFER_CAPACIDAD_MAXIMA 1024

/**
 * Estructura de buffer circular de tamaño fijo.
 * El usuario puede declararlo en el stack.
 */
typedef struct {
    unsigned char datos[BUFFER_CAPACIDAD_MAXIMA];
    size_t capacidad;
    size_t inicio;    // Índice de lectura
    size_t fin;       // Índice de escritura
    size_t cantidad;  // Número de bytes almacenados
} buffer_circular_t;

/**
 * Inicializa un buffer circular.
 *
 * @param buffer Puntero al buffer a inicializar.
 * @param capacidad Capacidad del buffer (máximo BUFFER_CAPACIDAD_MAXIMA).
 * @returns true si se inicializó correctamente, false si capacidad es inválida.
 * @pre buffer != NULL
 * @post El buffer queda vacío y listo para usar.
 */
bool buffer_init(buffer_circular_t *buffer, size_t capacidad);

/**
 * Limpia un buffer circular.
 *
 * @param buffer Puntero al buffer a limpiar.
 * @pre buffer != NULL
 * @post El buffer queda vacío.
 */
void buffer_finalize(buffer_circular_t *buffer);

/**
 * Escribe datos en el buffer.
 *
 * @param buffer Buffer donde escribir.
 * @param datos Puntero a los datos a escribir.
 * @param longitud Número de bytes a escribir.
 * @returns Número de bytes efectivamente escritos (puede ser menor que longitud
 *          si el buffer está casi lleno).
 * @pre buffer != NULL, datos != NULL
 */
size_t buffer_escribir(buffer_circular_t *buffer, 
                       const unsigned char *datos,
                       size_t longitud);

/**
 * Lee datos del buffer.
 *
 * @param buffer Buffer de donde leer.
 * @param datos Puntero al buffer de destino.
 * @param longitud Número máximo de bytes a leer.
 * @returns Número de bytes efectivamente leídos (puede ser menor que longitud
 *          si hay menos datos disponibles).
 * @pre buffer != NULL, datos != NULL
 */
size_t buffer_leer(buffer_circular_t *buffer,
                   unsigned char *datos,
                   size_t longitud);

/**
 * Consulta cuántos bytes hay disponibles para leer.
 *
 * @param buffer Buffer a consultar.
 * @returns Número de bytes disponibles.
 * @pre buffer != NULL
 */
size_t buffer_disponible(const buffer_circular_t *buffer);

/**
 * Consulta cuánto espacio libre hay para escribir.
 *
 * @param buffer Buffer a consultar.
 * @returns Número de bytes libres.
 * @pre buffer != NULL
 */
size_t buffer_espacio_libre(const buffer_circular_t *buffer);

/**
 * Verifica si el buffer está vacío.
 */
bool buffer_esta_vacio(const buffer_circular_t *buffer);

/**
 * Verifica si el buffer está lleno.
 */
bool buffer_esta_lleno(const buffer_circular_t *buffer);

#endif // BUFFER_CIRCULAR_H
```

```{code-block} c
:linenos:
// Implementación buffer_circular.c
#include "buffer_circular.h"
#include <string.h>

bool buffer_init(buffer_circular_t *buffer, size_t capacidad)
{
    if (capacidad == 0 || capacidad > BUFFER_CAPACIDAD_MAXIMA) {
        return false;
    }
    buffer->capacidad = capacidad;
    buffer->inicio = 0;
    buffer->fin = 0;
    buffer->cantidad = 0;
    return true;
}

void buffer_finalize(buffer_circular_t *buffer)
{
    buffer->inicio = 0;
    buffer->fin = 0;
    buffer->cantidad = 0;
}

size_t buffer_escribir(buffer_circular_t *buffer,
                       const unsigned char *datos,
                       size_t longitud)
{
    size_t espacio = buffer->capacidad - buffer->cantidad;
    size_t a_escribir = (longitud < espacio) ? longitud : espacio;
    
    for (size_t i = 0; i < a_escribir; i++) {
        buffer->datos[buffer->fin] = datos[i];
        buffer->fin = (buffer->fin + 1) % buffer->capacidad;
        buffer->cantidad++;
    }
    
    return a_escribir;
}

size_t buffer_leer(buffer_circular_t *buffer,
                   unsigned char *datos,
                   size_t longitud)
{
    size_t a_leer = (longitud < buffer->cantidad) ? longitud : buffer->cantidad;
    
    for (size_t i = 0; i < a_leer; i++) {
        datos[i] = buffer->datos[buffer->inicio];
        buffer->inicio = (buffer->inicio + 1) % buffer->capacidad;
        buffer->cantidad--;
    }
    
    return a_leer;
}

size_t buffer_disponible(const buffer_circular_t *buffer)
{
    return buffer->cantidad;
}

size_t buffer_espacio_libre(const buffer_circular_t *buffer)
{
    return buffer->capacidad - buffer->cantidad;
}

bool buffer_esta_vacio(const buffer_circular_t *buffer)
{
    return buffer->cantidad == 0;
}

bool buffer_esta_lleno(const buffer_circular_t *buffer)
{
    return buffer->cantidad == buffer->capacidad;
}
```
````

```{exercise}
:label: api_parser_cli
:enumerator: api-4

Diseñá una API para parsear argumentos de línea de comandos. La API debe soportar opciones booleanas (flags como `-v` para verbose), opciones con valores (como `-o archivo.txt`), y argumentos posicionales. Implementá solo la interfaz (archivo `.h`) con documentación completa.

**Ejemplo de uso esperado:**
```c
parser_t *parser = parser_crear("Mi Programa", "1.0");
parser_agregar_flag(parser, 'v', "verbose", "Modo verbose");
parser_agregar_opcion(parser, 'o', "output", "Archivo de salida", "stdout");
parser_parsear(parser, argc, argv);
bool verbose = parser_obtener_flag(parser, "verbose");
const char *salida = parser_obtener_opcion(parser, "output");
```
```

````{solution} api_parser_cli
:class: dropdown

```{code-block} c
:linenos:
#ifndef PARSER_CLI_H
#define PARSER_CLI_H

#include <stdbool.h>

/**
 * Tipo opaco que representa un parseador de argumentos de línea de comandos.
 */
typedef struct parser parser_t;

/**
 * Crea un nuevo parseador de argumentos.
 *
 * @param nombre_programa Nombre del programa (para mensajes de ayuda).
 * @param version Versión del programa.
 * @returns Puntero al parseador creado, o NULL si falla.
 * @pre nombre_programa != NULL, version != NULL
 * @post El llamador debe liberar con parser_destruir().
 */
parser_t *parser_crear(const char *nombre_programa, const char *version);

/**
 * Destruye un parseador y libera sus recursos.
 *
 * @param parser Parseador a destruir.
 * @post El puntero parser queda inválido.
 */
void parser_destruir(parser_t *parser);

/**
 * Agrega una opción booleana (flag) al parseador.
 *
 * @param parser Parseador al cual agregar el flag.
 * @param corto Carácter para la forma corta (ej. 'v' para -v).
 * @param largo Cadena para la forma larga (ej. "verbose" para --verbose).
 * @param descripcion Descripción para el mensaje de ayuda.
 * @returns true si se agregó exitosamente, false en caso de error.
 * @pre parser != NULL, largo != NULL
 */
bool parser_agregar_flag(parser_t *parser,
                         char corto,
                         const char *largo,
                         const char *descripcion);

/**
 * Agrega una opción con valor al parseador.
 *
 * @param parser Parseador al cual agregar la opción.
 * @param corto Carácter para la forma corta (ej. 'o' para -o).
 * @param largo Cadena para la forma larga (ej. "output" para --output).
 * @param descripcion Descripción para el mensaje de ayuda.
 * @param valor_defecto Valor por defecto si la opción no es especificada.
 * @returns true si se agregó exitosamente, false en caso de error.
 * @pre parser != NULL, largo != NULL
 */
bool parser_agregar_opcion(parser_t *parser,
                           char corto,
                           const char *largo,
                           const char *descripcion,
                           const char *valor_defecto);

/**
 * Parsea los argumentos de línea de comandos.
 *
 * @param parser Parseador a utilizar.
 * @param argc Número de argumentos (desde main).
 * @param argv Vector de argumentos (desde main).
 * @returns true si el parseo fue exitoso, false si hubo errores.
 * @pre parser != NULL, argv != NULL, argc >= 1
 * @post Si retorna false, usar parser_obtener_error() para obtener detalles.
 */
bool parser_parsear(parser_t *parser, int argc, char *argv[]);

/**
 * Obtiene el valor de un flag booleano.
 *
 * @param parser Parseador a consultar.
 * @param nombre Nombre largo del flag.
 * @returns true si el flag fue especificado, false en caso contrario.
 * @pre parser != NULL, nombre != NULL
 * @pre parser_parsear() debe haber sido llamado previamente.
 */
bool parser_obtener_flag(const parser_t *parser, const char *nombre);

/**
 * Obtiene el valor de una opción.
 *
 * @param parser Parseador a consultar.
 * @param nombre Nombre largo de la opción.
 * @returns Valor de la opción, o el valor por defecto si no fue especificada.
 * @pre parser != NULL, nombre != NULL
 * @pre parser_parsear() debe haber sido llamado previamente.
 * @post La cadena retornada es propiedad del parser y válida hasta
 *       que parser_destruir() sea llamado.
 */
const char *parser_obtener_opcion(const parser_t *parser, const char *nombre);

/**
 * Obtiene los argumentos posicionales (no opciones).
 *
 * @param parser Parseador a consultar.
 * @param cantidad Puntero donde almacenar el número de argumentos posicionales.
 * @returns Vector de cadenas con los argumentos posicionales.
 * @pre parser != NULL, cantidad != NULL
 * @post El vector retornado es propiedad del parser.
 */
const char **parser_obtener_argumentos(const parser_t *parser, int *cantidad);

/**
 * Muestra el mensaje de ayuda en la salida estándar.
 *
 * @param parser Parseador con las opciones definidas.
 * @pre parser != NULL
 */
void parser_mostrar_ayuda(const parser_t *parser);

/**
 * Obtiene el mensaje de error del último parseo fallido.
 *
 * @param parser Parseador a consultar.
 * @returns Cadena con el mensaje de error, o NULL si no hubo error.
 * @pre parser != NULL
 * @post La cadena retornada es propiedad del parser.
 */
const char *parser_obtener_error(const parser_t *parser);

#endif // PARSER_CLI_H
```
````

```{exercise}
:label: api_json_simple
:enumerator: api-5

Diseñá una API minimalista para leer archivos JSON simples (solo objetos con pares clave-valor donde los valores son cadenas o números). La API debe permitir cargar un archivo JSON y consultar valores por clave. Aplicá todos los principios de diseño vistos: tipo opaco, manejo de errores consistente, documentación completa, y uso de `const` apropiado.
```

````{solution} api_json_simple
:class: dropdown

```{code-block} c
:linenos:
#ifndef JSON_SIMPLE_H
#define JSON_SIMPLE_H

#include <stdbool.h>

/**
 * Tipo opaco que representa un objeto JSON parseado.
 */
typedef struct json json_t;

/**
 * Tipos de valores JSON soportados.
 */
typedef enum {
    JSON_TIPO_CADENA,
    JSON_TIPO_NUMERO,
    JSON_TIPO_INVALIDO
} json_tipo_t;

/**
 * Carga y parsea un archivo JSON.
 *
 * @param ruta_archivo Ruta al archivo JSON a cargar.
 * @returns Puntero al objeto JSON parseado, o NULL si falla.
 * @pre ruta_archivo != NULL
 * @post El llamador debe liberar con json_destruir().
 *       Si retorna NULL, usar json_obtener_error() para detalles.
 */
json_t *json_cargar(const char *ruta_archivo);

/**
 * Parsea una cadena JSON.
 *
 * @param contenido Cadena con el contenido JSON.
 * @returns Puntero al objeto JSON parseado, o NULL si falla.
 * @pre contenido != NULL
 * @post El llamador debe liberar con json_destruir().
 */
json_t *json_parsear(const char *contenido);

/**
 * Destruye un objeto JSON y libera sus recursos.
 *
 * @param json Objeto JSON a destruir.
 * @post El puntero json queda inválido.
 */
void json_destruir(json_t *json);

/**
 * Verifica si una clave existe en el objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave a buscar.
 * @returns true si la clave existe, false en caso contrario.
 * @pre json != NULL, clave != NULL
 */
bool json_existe(const json_t *json, const char *clave);

/**
 * Obtiene el tipo de valor asociado a una clave.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @returns Tipo del valor, o JSON_TIPO_INVALIDO si la clave no existe.
 * @pre json != NULL, clave != NULL
 */
json_tipo_t json_obtener_tipo(const json_t *json, const char *clave);

/**
 * Obtiene un valor de cadena del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @param valor_defecto Valor a retornar si la clave no existe o no es cadena.
 * @returns Valor de la clave como cadena, o valor_defecto.
 * @pre json != NULL, clave != NULL
 * @post La cadena retornada es propiedad del objeto JSON.
 */
const char *json_obtener_cadena(const json_t *json,
                                const char *clave,
                                const char *valor_defecto);

/**
 * Obtiene un valor numérico del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @param valor_defecto Valor a retornar si la clave no existe o no es número.
 * @returns Valor de la clave como double, o valor_defecto.
 * @pre json != NULL, clave != NULL
 */
double json_obtener_numero(const json_t *json,
                           const char *clave,
                           double valor_defecto);

/**
 * Obtiene el número de pares clave-valor en el objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @returns Número de claves en el objeto.
 * @pre json != NULL
 */
size_t json_obtener_num_claves(const json_t *json);

/**
 * Obtiene todas las claves del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @returns Vector de cadenas con las claves, terminado en NULL.
 * @pre json != NULL
 * @post El vector retornado es propiedad del objeto JSON.
 */
const char **json_obtener_claves(const json_t *json);

/**
 * Obtiene el mensaje del último error de parseo.
 *
 * @returns Cadena con el mensaje de error, o NULL si no hubo error.
 * @post La cadena es propiedad de la librería y válida hasta la
 *       próxima operación que pueda generar error.
 */
const char *json_obtener_error(void);

#endif // JSON_SIMPLE_H
```

**Notas sobre el diseño:**

- Se usa `json_obtener_error()` como función global para obtener errores, similar a `errno` en la biblioteca estándar de C.
- Los valores por defecto permiten un uso simple sin necesidad de verificar siempre si una clave existe.
- El uso consistente de `const` indica qué funciones modifican el objeto y qué datos son propiedad de la librería.
- La API es minimalista pero extensible: se podrían agregar funciones para soportar arrays, booleanos, y null en futuras versiones.
````

## Performance y APIs: El Costo de la Abstracción

Una preocupación legítima al diseñar APIs con múltiples capas de abstracción es el impacto en el rendimiento. ¿Cuánto cuesta la llamada a función indirecta? ¿Vale la pena el overhead?

### El Mito de la Abstracción Costosa

En sistemas modernos, el costo de una llamada a función bien diseñada es despreciable en la vasta mayoría de los casos. Knuth [@knuth1974] famosamente advirtió: "La optimización prematura es la raíz de todos los males" (*"premature optimization is the root of all evil"*). Esta observación, basada en décadas de experiencia, enfatiza que el tiempo de desarrollo debe invertirse en claridad y corrección antes que en optimizaciones especulativas.

El compilador moderno realiza optimizaciones agresivas que eliminan gran parte del overhead de la abstracción, incluyendo:

- **Inlining**: Funciones pequeñas y frecuentemente llamadas se insertan directamente en el sitio de llamada, eliminando completamente el overhead de la llamada a función. Los compiladores modernos con optimización `-O2` o superior realizan inlining automático basado en heurísticas de costo-beneficio.

- **Link-Time Optimization (LTO)**: Optimizaciones entre unidades de compilación, permitiendo inlining incluso de funciones definidas en otros archivos objeto. LTO permite al compilador tener una visión global del programa y tomar decisiones de optimización más informadas.

- **Constant Propagation y Dead Code Elimination**: El compilador puede propagar constantes a través de llamadas a función y eliminar código que nunca se ejecuta, reduciendo dramáticamente el tamaño y mejorando la localidad del cache.

Un estudio de Mytkowicz et al. [@mytkowicz2009] demostró que diferencias en performance son frecuentemente atribuidas incorrectamente a causas obvias (como llamadas a función), cuando en realidad factores como la alineación de código en memoria, el estado del cache, y efectos del layout de memoria tienen impactos más significativos. Este estudio es una advertencia sobre la importancia de medir, no asumir.

:::{important}
**Regla de Oro: Medir, No Asumir**

Antes de sacrificar claridad por performance:

1. **Perfilá** (*profile*) tu código con herramientas como `gprof`, `perf`, o Valgrind/Callgrind [@nethercote2007].
2. **Identificá** los verdaderos cuellos de botella (*hotspots*). Típicamente, el 90% del tiempo se gasta en el 10% del código.
3. **Optimizá** solo ese 10%, manteniendo el resto del código claro y mantenible.
4. **Verificá** que la optimización realmente mejoró el rendimiento de forma significativa.

Como observa Martin [@martin2008], "El código limpio es más fácil de optimizar que el código sucio", porque es más fácil identificar y modificar las partes críticas cuando el código es comprensible.
:::

### Cuándo Preocuparse por Performance

La performance sí importa en contextos específicos:

1. **Lazos Internos Críticos (_Hot Paths_)**: Código que se ejecuta millones o miles de millones de veces por segundo, como kernels de procesamiento de señales, codecs de video/audio, motores de rendering 3D, o algoritmos criptográficos. En estos casos, incluso el overhead de una única instrucción puede acumularse significativamente.

2. **Sistemas de Tiempo Real Duro**: Donde límites temporales estrictos (*deadlines*) son obligatorios y su incumplimiento puede tener consecuencias catastróficas (sistemas de control industrial, aviación, dispositivos médicos). En estos sistemas, no solo importa la performance promedio, sino también la varianza y el peor caso (*worst-case execution time*, WCET).

3. **Sistemas Embebidos con Recursos Limitados**: Microcontroladores con kilobytes de RAM y megahertz de clock, donde cada byte de código y cada ciclo de CPU cuenta. En estos entornos, las asignaciones dinámicas pueden estar completamente prohibidas.

4. **Algoritmos de Complejidad Crítica**: Cuando la elección de estructura de datos o algoritmo afecta la complejidad asintótica (por ejemplo, $O(n)$ vs. $O(n^2)$), el diseño de la API debe facilitar el uso eficiente, no obstaculizarlo.

En estos casos, las APIs pueden exponer versiones "unsafe" optimizadas junto a versiones "safe" con verificaciones completas:

:::{code-block} c
// Versión con verificaciones completas: segura pero más lenta
bool lista_insertar(lista_t *lista, size_t pos, void *elem);

// Versión sin verificaciones para lazos críticos: rápida pero peligrosa
// PRECONDICIÓN: pos < lista->tamanio, lista != NULL, elem != NULL
// El incumplimiento de las precondiciones resulta en comportamiento indefinido
void lista_insertar_unsafe(lista_t *lista, size_t pos, void *elem);
:::

Esta estrategia es común en bibliotecas de sistemas. Por ejemplo, la librería estándar de C ofrece `strcpy` (rápida pero peligrosa) y `strncpy` (más segura pero requiere especificar tamaño). Bibliotecas modernas como OpenSSL exponen APIs de alto nivel simples para casos comunes y APIs de bajo nivel complejas para casos que requieren máximo control.

### Testing de APIs: Validación del Contrato

El testing de una API no solo verifica que el código funciona, sino que valida que el *contrato* se cumple. Beck [@beck2002] popularizó el desarrollo guiado por tests (*Test-Driven Development*, TDD), donde los tests se escriben antes que el código de producción, sirviendo como especificación ejecutable.

**Niveles de testing para APIs:**

1. **Tests de Contrato**: Verifican que las precondiciones, poscondiciones e invariantes documentados se cumplen. Por ejemplo, si la documentación dice que `lista_crear()` retorna `NULL` en caso de fallo, debe haber un test que verifique este comportamiento.

2. **Tests de Casos Límite**: Proban comportamiento en fronteras (listas vacías, tamaño máximo, valores nulos, etc.). Muchos bugs se esconden en estos casos extremos.

3. **Tests de Estrés**: Crean miles de objetos, realizan millones de operaciones, buscan fugas de memoria con Valgrind [@nethercote2007].

4. **Tests de Uso Incorrecto**: Verifican que la API se comporta razonablemente (idealmente, falla de forma predecible) cuando se usa incorrectamente. Por ejemplo, pasar `NULL` donde no está permitido debería causar un `assert` en modo debug, no un crash silencioso.

:::{code-block} c
// Ejemplo de test de contrato
void test_lista_agregar_retorna_true_en_exito(void) {
    lista_t *lista = lista_crear();
    assert(lista != NULL);
    
    // Postcondición: agregar elemento debe retornar true
    bool resultado = lista_agregar(lista, 42);
    assert(resultado == true);
    
    // Invariante: el tamaño debe incrementarse
    assert(lista_largo(lista) == 1);
    
    lista_destruir(lista);
}
:::

**Property-Based Testing:**

Una técnica avanzada, popularizada por QuickCheck [@claessen2000], genera automáticamente cientos de casos de test basados en propiedades declaradas. Por ejemplo, para una lista: "agregar N elementos y luego consultar el largo debe retornar N".

## Documentación de APIs: El Contrato Escrito

La documentación no es opcional; es parte integral del contrato entre la API y sus usuarios. Una función sin documentación es una función cuyo comportamiento es indefinido desde la perspectiva del usuario.

### Elementos Esenciales de Documentación

Cada función pública debe documentar:

1. **Propósito**: ¿Qué hace la función en términos de alto nivel?
2. **Parámetros**: Significado, unidades, restricciones de cada parámetro.
3. **Valor de Retorno**: Qué representa, qué valores son posibles.
4. **Precondiciones**: Qué debe ser verdadero antes de llamar la función.
5. **Poscondiciones**: Qué será verdadero después de que la función retorne exitosamente.
6. **Efectos Secundarios**: ¿Modifica argumentos? ¿Accede a recursos externos?
7. **Gestión de Memoria**: ¿Quién aloja? ¿Quién libera?
8. **Manejo de Errores**: ¿Cómo reporta errores? ¿Qué errores son posibles?
9. **Thread-Safety**: ¿Es seguro llamar desde múltiples hilos concurrentemente?
10. **Complejidad**: Si es relevante, complejidad temporal y espacial ($O(n)$, etc.).

### Formato de Documentación: Doxygen

Doxygen [@doxygen2023] es el estándar de facto para documentación de APIs en C/C++. Usa comentarios especialmente formateados que pueden ser procesados para generar HTML, PDF, y man pages.

:::{code-block} c
/**
 * @brief Busca un elemento en una lista ordenada usando búsqueda binaria.
 *
 * Esta función implementa el algoritmo de búsqueda binaria, que requiere
 * que la lista esté ordenada en orden ascendente.
 *
 * @param lista Lista donde buscar. Debe estar ordenada.
 * @param elemento Elemento a buscar.
 * @param[out] indice_out Si no es NULL y se encuentra el elemento,
 *                        se almacena aquí el índice donde fue encontrado.
 * 
 * @return true si el elemento fue encontrado, false en caso contrario.
 * 
 * @pre lista != NULL
 * @pre La lista debe estar ordenada en orden ascendente.
 * @post Si retorna true, *indice_out contiene el índice del elemento.
 * @post La lista no es modificada.
 * 
 * @note Complejidad: O(log n) donde n es el tamaño de la lista.
 * @note Thread-safe: Sí, siempre que no se modifique la lista concurrentemente.
 * 
 * @see lista_ordenar() para ordenar una lista antes de buscar.
 */
bool lista_buscar_binaria(const lista_t *lista, 
                         int elemento,
                         size_t *indice_out);
:::

Esta documentación es exhaustiva pero necesaria. Comunica el contrato completo y permite al usuario de la API trabajar con confianza.

## Estudio de Caso: APIs Exitosas en la Práctica

Analizar APIs exitosas y ampliamente adoptadas revela patrones comunes y lecciones valiosas.

### POSIX: El Estándar de Facto

POSIX (Portable Operating System Interface) [@ieee2018] es quizás el ejemplo más exitoso de diseño de API en C. Define interfaces estándar para interacción con el sistema operativo (archivos, procesos, hilos, señales, etc.) que han sido adoptadas por prácticamente todos los sistemas Unix-like y muchos otros.

**Principios de diseño de POSIX:**

- **Simplicidad Conceptual**: Las abstracciones son pocas pero poderosas. "Everything is a file" permite unificar E/S de archivos, dispositivos, pipes y sockets bajo una interfaz común (`open`, `read`, `write`, `close`).

- **Composabilidad**: Los programas POSIX están diseñados para ser combinados mediante pipes y redirección. Esta filosofía, heredada de Unix [@raymond2003], enfatiza hacer una cosa y hacerla bien.

- **Gestión Explícita de Errores**: Todas las funciones que pueden fallar retornan valores que indican éxito o fracaso, y establecen la variable global `errno` con detalles del error. Aunque el uso de una variable global para errores es controversial (viola el principio de estado explícito), ha probado ser práctico en contexto de llamadas al sistema.

- **Estabilidad a Largo Plazo**: POSIX ha mantenido compatibilidad hacia atrás por décadas. Código escrito para POSIX en los 80s frecuentemente compila y ejecuta sin cambios en sistemas modernos.

**Lecciones:**

- La estabilidad y compatibilidad a largo plazo son más valiosas que la perfección teórica. Una API "suficientemente buena" que se mantiene estable es preferible a una API "perfecta" que cambia constantemente.

- Las abstracciones simples y uniformes (como el descriptor de archivo) pueden aplicarse a dominios inesperados, aumentando la utilidad de la API más allá de sus casos de uso originales.

La API POSIX [@ieee2018] define interfaces para sistemas Unix-like y ha sobrevivido décadas. Sus lecciones:

- **Simplicidad**: Funciones hacen una cosa y la hacen bien (`fopen`, `read`, `write`).
- **Composabilidad**: Funciones pequeñas se combinan para crear funcionalidad compleja.
- **Consistencia**: Patrones repetidos (descriptores de archivo, códigos de error) facilitan el aprendizaje.

### SQLite: La Librería más Deployada del Mundo

SQLite [@hipp2020] es probablemente la librería C más ampliamente desplegada en el planeta. Se encuentra en miles de millones de dispositivos: smartphones, navegadores web, sistemas operativos, aviones, y prácticamente cualquier sistema que necesite almacenar datos estructurados localmente. Su éxito se debe en gran parte a decisiones de diseño deliberadas:

**Principios de diseño de SQLite:**

- **Zero Configuration**: No requiere instalación, configuración ni administración de servidor. La librería es completamente autocontenida.

- **Single File Database**: Toda la base de datos (tablas, índices, schema, datos) reside en un único archivo del sistema operativo, facilitando backup, transferencia y versionado.

- **API Minimalista pero Poderosa**: Pocas funciones esenciales (`sqlite3_open`, `sqlite3_exec`, `sqlite3_prepare_v2`, `sqlite3_step`, `sqlite3_finalize`) permiten realizar operaciones SQL completas. La API es fácil de aprender pero suficientemente expresiva para casos de uso avanzados.

- **Backward Compatibility Extrema**: SQLite mantiene un compromiso de compatibilidad hacia atrás virtualmente infinito. Bases de datos creadas hace 20 años pueden ser leídas por versiones modernas sin conversión. Este compromiso es posible gracias al uso de punteros opacos y al diseño cuidadoso de la ABI.

- **Testing Exhaustivo**: SQLite tiene una cobertura de testing que excede el 100% del código (más líneas de test que de código producto), incluyendo testing de errores de hardware y condiciones excepcionales [@hipp2020].

Richard Hipp, creador de SQLite, enfatiza que "SQLite es software embebido, no un producto con clientes". Esta filosofía de diseño como componente reutilizable, no como servicio independiente, informa cada decisión de API. El objetivo es que SQLite "simplemente funcione" sin que el usuario tenga que pensar en ella.

### Git: Porcelain vs Plumbing

Git [@chacon2014] es el sistema de control de versiones más utilizado del mundo. Su diseño de API es notable por la separación explícita en dos niveles de abstracción:

**Arquitectura de dos niveles:**

- **Plumbing (Fontanería)**: Comandos de bajo nivel, estables y diseñados para scripting y automatización. Ejemplos: `git hash-object`, `git cat-file`, `git update-index`. Estos comandos exponen directamente los objetos internos de Git (blobs, trees, commits) y garantizan estabilidad de interfaz a largo plazo.

- **Porcelain (Porcelana)**: Comandos de alto nivel, user-friendly, diseñados para uso humano. Ejemplos: `git add`, `git commit`, `git push`. Estos comandos pueden cambiar su comportamiento o flags en nuevas versiones para mejorar la experiencia de usuario.

**Lecciones de diseño:**

Esta separación es brillante porque permite:

1. **Evolución de UX**: Los comandos de alto nivel pueden mejorar (mejor mensajes de error, nuevos flags, comportamiento más intuitivo) sin romper scripts y herramientas que dependen de Git.

2. **Estabilidad para Automatización**: Scripts y herramientas de terceros pueden confiar en que los comandos de *plumbing* mantendrán su comportamiento indefinidamente.

3. **Acceso a Primitivas**: Usuarios avanzados y herramientas pueden construir funcionalidad compleja combinando comandos de bajo nivel.

El diseño de Git demuestra que no es necesario elegir entre simplicidad para principiantes y poder para expertos. Una API puede ofrecer ambos mediante niveles de abstracción apropiados, cada uno con su propio contrato de estabilidad.

## Conclusión: Diseñar para el Usuario

El diseño de una buena interfaz en C es un ejercicio de empatía y disciplina. Requiere que te pongas en el lugar del programador que utilizará tu código. ¿Es la interfaz clara? ¿Es predecible? ¿Es segura? ¿Oculta la complejidad innecesaria?

Al aplicar estos principios y las reglas de estilo, no solo estarás creando funciones, sino componentes de software robustos, modulares y profesionales. Estarás construyendo "contratos" en los que otros desarrolladores pueden confiar, asegurando la mantenibilidad y longevidad de tu código.

Como observa Stroustrup [@stroustrup2012], diseñador de C++: "El diseño de bibliotecas es el diseño de lenguajes". Una buena API extiende el lenguaje con un vocabulario nuevo, expresivo y coherente para resolver problemas de un dominio específico.

### Principios Clave a Recordar

1. **Claridad sobre Cleverness**: Un código claro y simple es superior a uno "inteligente" pero difícil de entender. Como dice la regla {ref}`0x0000h`, la claridad y prolijidad son fundamentales.

2. **Contratos Explícitos**: Las precondiciones y poscondiciones no son decoración, son especificaciones formales del comportamiento esperado.

3. **Encapsulamiento Riguroso**: La información que no necesita ser pública, no debe serlo. Los tipos opacos son tu herramienta principal para lograr esto.

4. **Errores sin Sorpresas**: Los errores deben ser reportados de manera predecible y consistente. El usuario de tu API debe poder manejarlos de forma adecuada a su contexto.

5. **Evolución Controlada**: Una API bien diseñada puede evolucionar sin romper código existente, mediante deprecación gradual y versionado semántico.

6. **Testing como Diseño**: Los tests no solo verifican corrección; informan y validan el diseño desde la perspectiva del usuario.

7. **Performance Consciente pero no Obsesiva**: Optimizá lo que importa, después de medir. La claridad y corrección primero, optimización después.

El dominio de estos principios te diferencia de un programador amateur de uno profesional. Es la diferencia entre escribir código que funciona hoy y escribir código que seguirá siendo valioso dentro de años.

## Referencias Adicionales y Lecturas Recomendadas

Para profundizar en los temas tratados, se recomiendan las siguientes lecturas:

- **"The C Programming Language"** [@kernighan1988]: El libro definitivo sobre C, escrito por los creadores del lenguaje.
- **"Expert C Programming: Deep C Secrets"** [@linden1994]: Discute sutilezas y patrones idiomáticos avanzados de C.
- **"Large-Scale C++ Software Design"** [@lakos1996]: Aunque enfocado en C++, muchos principios aplican directamente a C, especialmente sobre diseño modular y gestión de dependencias.
- **"The Art of Unix Programming"** [@raymond2003]: Filosofía y principios de diseño de software Unix, altamente relevante para APIs en C.
- **"API Design for C++"** [@reddy2011]: Exhaustivo tratamiento de diseño de APIs, con muchos principios aplicables a C.
- **"Code Complete"** [@mcconnell_code_2004]: Guía comprensiva de construcción de software de alta calidad.
- **"Clean Code"** [@martin2008]: Principios de código limpio y mantenible.

---

:::{tip} Estilo
En este apunte se aplicaron los principios de diseño de APIs descriptos en las reglas {ref}`0x0000h` (claridad y prolijidad), {ref}`0x0001h` (nomenclatura), {ref}`0x000Ah` (documentación), y {ref}`0x001Ah` (gestión de memoria), demostrando su aplicación práctica en el diseño de interfaces profesionales.
:::
