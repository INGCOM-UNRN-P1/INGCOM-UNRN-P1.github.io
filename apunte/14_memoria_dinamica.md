---
title: 'Memoria Dinámica'
short_title: '14 - Memoria Dinámica'
description: 'Gestión y alocación en el Heap utilizando malloc, calloc, realloc y free.'
---

(memoria-dinamica-capitulo)=
## Funciones de Gestión de Memoria (`<stdlib.h>`)

Las funciones de gestión de memoria dinámica están declaradas en el archivo de
cabecera `<stdlib.h>`. Estas funciones permiten solicitar y liberar bloques de
memoria del heap durante la ejecución del programa.

(memoria-malloc)=
### `malloc` (Memory Allocation)

#### Sintaxis

```c
void *malloc(size_t size);
```

#### Propósito

Reserva un bloque contiguo de `size` bytes en el heap. La memoria reservada **no está inicializada** y contiene valores indeterminados (basura). Esto significa que los bytes asignados pueden contener cualquier valor que haya quedado de un uso previo de esa región de memoria.

La función retorna un puntero de tipo `void *`, que es un puntero genérico que puede convertirse implícitamente a cualquier tipo de puntero en C. Esto permite usar `malloc` para asignar memoria para cualquier tipo de dato.

#### Valor de Retorno

- Un puntero de tipo `void *` a la primera dirección del bloque reservado si la operación es exitosa.
- `NULL` si no hay suficiente memoria disponible o si `size` es 0 (comportamiento dependiente de la implementación).

#### ¿Por qué la memoria no está inicializada?

Por razones de eficiencia. Inicializar la memoria tiene un costo computacional, y en muchos casos el programador va a sobrescribir inmediatamente esos valores con datos útiles. Si necesitás memoria inicializada a cero, usá `calloc` en su lugar.

#### Uso Correcto

Según la {ref}`0x3001h`, siempre debés verificar que la asignación de memoria fue exitosa. Además, la {ref}`0x300Bh` establece que debés usar `sizeof` para calcular el tamaño necesario en lugar de valores literales, y preferir `sizeof(*puntero)` sobre `sizeof(tipo)` para evitar errores si el tipo cambia.

La {ref}`0x3003h` indica que no debés mezclar operaciones de asignación y comparación en una sola línea.

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros = NULL;
    size_t cantidad = 5;

    // Asignación de memoria
    numeros = malloc(cantidad * sizeof(*numeros));

    // Verificación del resultado
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Uso de la memoria
    for (size_t i = 0; i < cantidad; i++)
    {
        numeros[i] = (int)i * 10;
    }

    // Liberación de la memoria
    free(numeros);
    numeros = NULL;

    return 0;
}
```

:::{tip} ¿Por qué verificar si `malloc` retorna `NULL`? 
La asignación de memoria puede fallar por varias razones: memoria insuficiente en el sistema, límites de proceso, fragmentación extrema del heap. Si no verificás el retorno de `malloc` e intentás usar un puntero `NULL`, el programa experimentará una violación de segmento (_segmentation fault_) inmediata, o peor aún, comportamiento indefinido.

Verificar el retorno de `malloc` permite que tu programa:

- Maneje el error de forma elegante (por ejemplo, mostrando un mensaje al usuario).
- Libere otros recursos antes de terminar.
- Intente estrategias alternativas (reducir el tamaño solicitado, usar un archivo temporal, etc.). 
:::

:::{note} Cast Explícito
En C, no es necesario hacer cast del puntero `void *` retornado por `malloc` a otro tipo de puntero, ya que la conversión es implícita. Sin embargo, algunos programadores prefieren el cast explícito por claridad o para compatibilidad con C++. La {ref}`0x300Ah` recomienda usar cast explícito al convertir tipos de punteros por claridad. 
:::

(memoria-calloc)=
### `calloc` (Contiguous Allocation)

#### Sintaxis

```c
void *calloc(size_t num_elements, size_t element_size);
```

#### Propósito

Reserva memoria para un arreglo de `num_elements` elementos, cada uno de tamaño `element_size` bytes. La diferencia fundamental con `malloc` es que `calloc` **inicializa todos los bytes a cero**.

El tamaño total reservado es `num_elements * element_size` bytes. La función realiza esta multiplicación internamente, lo que puede ser más seguro que calcularla manualmente con `malloc`, ya que algunas implementaciones de `calloc` verifican el desbordamiento (_overflow_) en esta multiplicación.

#### Ventajas

- Inicialización automática: útil cuando necesitás garantizar que la memoria comienza en un estado conocido.
- Claridad semántica: el nombre y los parámetros indican que estás creando un arreglo.
- Seguridad: la separación de los parámetros hace explícita la intención y puede ayudar a prevenir errores de cálculo de tamaño.

#### ¿Cuándo usar `calloc` vs `malloc`?

Usá `calloc` cuando:

- Necesitás que la memoria esté inicializada a cero.
- Estás creando un arreglo y querés que tu código sea más claro.
- Trabajás con estructuras que contienen punteros que deben ser `NULL` inicialmente.

Usá `malloc` cuando:

- Vas a sobrescribir inmediatamente todos los valores.
- Querés máxima eficiencia y no necesitás inicialización.
- Estás asignando memoria para un único elemento (no un arreglo).

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t cantidad = 5;
    int *arreglo = calloc(cantidad, sizeof(*arreglo));

    if (arreglo == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Todos los elementos están inicializados en 0
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("arreglo[%zu] = %d\n", i, arreglo[i]);
    }

    free(arreglo);
    arreglo = NULL;

    return 0;
}
```

(memoria-realloc)=
### `realloc` (Re-allocation)

#### Sintaxis

```c
void *realloc(void *ptr, size_t new_size);
```

#### Propósito

Cambia el tamaño de un bloque de memoria previamente asignado.

- `ptr`: Puntero al bloque de memoria original. Si es `NULL`, `realloc` se comporta como `malloc(new_size)`.
- `new_size`: Nuevo tamaño en bytes.

#### Comportamiento

1.  **Si `new_size` es mayor que el tamaño original:**
    -   Intenta expandir el bloque actual si hay espacio contiguo.
    -   Si no es posible, busca un nuevo bloque de memoria lo suficientemente grande, copia el contenido del bloque antiguo al nuevo, y libera el bloque antiguo.
    -   La memoria adicional no se inicializa.

2.  **Si `new_size` es menor que el tamaño original:**
    -   El bloque se trunca. Los datos al final se pierden.

3.  **Si `new_size` es 0:**
    -   **¡Evitar!** En estándares modernos (C17/C23), llamar a `realloc(ptr, 0)` está formalmente declarado como comportamiento indefinido u obsoleto. No debe usarse bajo ninguna circunstancia como sustituto de `free()`. Para liberar memoria, utilizá siempre la función `free()`.

#### Valor de Retorno

- Un puntero al bloque de memoria redimensionado (que puede ser la misma dirección o una nueva).
- `NULL` si la operación falla. En este caso, el bloque de memoria original **no se libera** y sigue siendo válido.

(punteros2-realloc-seguro)=
#### Uso Seguro

El error más común con `realloc` es perder la referencia al bloque original si la función falla por lo que es necesario un puntero temporal para manejar `realloc` de forma segura.

**Incorrecto:**

```c
// ¡PELIGRO! Si realloc falla, se pierde el puntero original
ptr = realloc(ptr, nuevo_tamano);
if (ptr == NULL) {
    // Fuga de memoria: el bloque original se perdió
}
```

**Correcto:**

```c
#include <stdlib.h>

int *numeros = malloc(5 * sizeof(*numeros));
// ...

size_t nuevo_tamano = 10;
int *temp = realloc(numeros, nuevo_tamano * sizeof(*temp));

if (temp == NULL) {
    // realloc falló, pero 'numeros' sigue siendo válido
    fprintf(stderr, "Error: No se pudo redimensionar la memoria.\n");
    free(numeros); // Liberar el bloque original
    return 1;
}

// Éxito: ahora 'numeros' puede apuntar al nuevo bloque
numeros = temp;
```

(memoria-free)=
### `free` (Liberación)

#### Sintaxis

```c
void free(void *ptr);
```

#### Propósito

Libera un bloque de memoria previamente reservado, devolviéndolo al sistema operativo para que pueda ser reutilizado.

#### Reglas Fundamentales

Según la {ref}`0x3002h`, debés:

1. Liberar siempre la memoria dinámica que asignaste.
2. Asignar `NULL` al puntero inmediatamente después de liberarlo para prevenir punteros colgantes.

Es seguro llamar a `free(NULL)`, la función simplemente no hace nada.

```c
free(ptr);
ptr = NULL;  // Previene el uso accidental del puntero colgante
```

:::{important} Simetría en la Gestión de Recursos
La {ref}`0x3002h` también enfatiza la simetría: si creaste una función `crear_recurso()` para encapsular la asignación, debés crear una función `liberar_recurso()` correspondiente para su liberación. Esto mantiene el nivel de abstracción consistente y facilita el mantenimiento.
:::

(memoria-heap-allocator)=
### El Allocator: Gestión Interna del Heap

Cuando llamás a `malloc` o `calloc`, no estás interactuando directamente con el sistema operativo en cada llamada. En cambio, estas funciones son parte de un subsistema llamado **allocator** (asignador de memoria) que gestiona el heap de tu proceso.

**¿Cómo funciona el allocator?**

El allocator mantiene su propia estructura de datos para rastrear qué bloques del heap están libres y cuáles están ocupados. Existen varias estrategias de implementación, pero todas deben resolver dos problemas fundamentales:

1. **Al asignar:** ¿Qué bloque libre usar cuando hay varios disponibles?
2. **Al liberar:** ¿Cómo marcar el bloque como libre y potencialmente fusionarlo con bloques adyacentes?

**Estructura típica de un bloque de memoria:**

```{figure} 14/heap_allocator.svg
:name: fig-heap-allocator
:width: 80%

Estructura de un bloque de memoria en el heap, mostrando el header con metadata, el área de datos del usuario, y el footer opcional.
```

El header típicamente contiene:

- **Tamaño del bloque** (en bytes)
- **Flag de ocupado/libre** (típicamente en el bit menos significativo del tamaño)
- **Punteros a bloques adyacentes** (en implementaciones de lista enlazada)

:::{note} Overhead de Memoria
Cada asignación tiene un costo en memoria adicional (overhead) para almacenar los metadatos. Típicamente entre 8 y 16 bytes por bloque. Por eso, muchas asignaciones pequeñas desperdician más memoria que pocas asignaciones grandes.
:::

**Estrategias de asignación:**

1. **First Fit (Primer ajuste):**
   - Busca desde el inicio del heap hasta encontrar el primer bloque libre suficientemente grande.
   - **Ventaja:** Rápido (termina apenas encuentra un bloque).
   - **Desventaja:** Tiende a fragmentar la parte inicial del heap.

2. **Best Fit (Mejor ajuste):**
   - Busca en todo el heap el bloque libre más pequeño que satisfaga la solicitud.
   - **Ventaja:** Minimiza el desperdicio de memoria.
   - **Desventaja:** Lento (debe recorrer toda la lista) y crea muchos bloques diminutos inutilizables.

3. **Next Fit (Siguiente ajuste):**
   - Como First Fit, pero continúa desde donde terminó la última búsqueda.
   - **Ventaja:** Distribuye mejor las asignaciones por todo el heap.
   - **Desventaja:** Aún puede fragmentar.

4. **Segregated Free Lists (Listas libres segregadas):**
   - Mantiene listas separadas para bloques de diferentes tamaños.
   - **Ventaja:** Muy eficiente para patrones de asignación predecibles.
   - **Desventaja:** Más complejo de implementar y mantener.

**Interacción con el sistema operativo:**

El allocator solicita memoria al sistema operativo en grandes cantidades (típicamente mediante `sbrk()` o `mmap()` en Unix/Linux) y luego la subdivide según las necesidades del programa. Esto reduce enormemente el número de llamadas al sistema, que son costosas.

```{figure} 14/allocator_flow.svg
:name: fig-allocator-flow
:width: 100%

Flujo de interacción entre el programa, las funciones de memoria (malloc/calloc/free), el allocator interno que mantiene un pool de memoria, y ocasionalmente el sistema operativo que proporciona acceso a la RAM física.
```

**Coalescing (Fusión de bloques):**

Cuando liberás un bloque con `free()`, el allocator intenta fusionarlo con bloques libres adyacentes para crear bloques más grandes. Esto ayuda a combatir la fragmentación externa.

```{figure} 14/coalescing.svg
:name: fig-coalescing
:width: 100%

Proceso de coalescing (fusión) donde bloques libres adyacentes (LIBRE-B y LIBRE-C) se combinan en un único bloque más grande (LIBRE-BC fusionado).
```

:::{tip} Implicaciones para el Programador
Aunque no implementés tu propio allocator, comprender su funcionamiento explica varios fenómenos:

1. **Por qué muchas asignaciones pequeñas son ineficientes:** Cada una tiene overhead de metadatos y sobrecarga de búsqueda.
2. **Por qué el patrón de asignación importa:** Asignar y liberar en patrones impredecibles causa fragmentación.
3. **Por qué `free()` es rápido:** Solo marca el bloque como libre y potencialmente fusiona; no devuelve memoria al SO inmediatamente.
4. **Por qué el heap puede crecer pero no decrecer fácilmente:** El allocator solo puede devolver memoria al SO si los bloques al final del heap están libres. 
:::

(memoria-errores)=
## Errores Comunes y Peligros

La gestión manual de memoria es una fuente frecuente de errores en C. Comprender estos errores y cómo prevenirlos es fundamental para escribir código robusto.

:::{note} Errores Básicos de Punteros
Los errores discutidos en esta sección son específicos de la gestión de memoria dinámica. Para errores básicos con punteros (como punteros salvajes, desreferencia de `NULL`, y problemas de inicialización), consultá primero el [](9_punteros), que cubre los conceptos fundamentales necesarios para trabajar con punteros de forma segura.
:::

(memoria-memory-leak)=
### Memory Leak (Fuga de Memoria)

Una fuga de memoria ocurre cuando se pierde la referencia a un bloque de memoria reservado sin haberlo liberado con `free`. La memoria queda inutilizable para el programa hasta que este termina.

#### Ejemplo Problemático

```c
#include <stdlib.h>

void funcion_con_fuga()
{
    int *datos = malloc(100 * sizeof(*datos));

    // Se realizan operaciones...

    // ERROR: La función termina sin liberar 'datos'
    // El bloque de memoria se pierde
}
```

#### Solución

Asegurate de que cada asignación tenga su correspondiente liberación, siguiendo la {ref}`0x3002h`.

```c
void funcion_sin_fuga()
{
    int *datos = malloc(100 * sizeof(*datos));

    if (datos == NULL)
    {
        return;
    }

    // Operaciones...

    free(datos);
    datos = NULL;
}
```

(memoria-dangling-pointer)=
### Dangling Pointer (Puntero Colgante)

Un puntero colgante es un puntero que apunta a una dirección de memoria que ya ha sido liberada con `free`. Intentar acceder a través de él produce comportamiento indefinido.

#### Ejemplo Problemático

```c
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = malloc(sizeof(*ptr));
    *ptr = 42;

    free(ptr);
    // ERROR: 'ptr' aún contiene la dirección liberada

    printf("%d\n", *ptr);  // Comportamiento indefinido

    return 0;
}
```

#### Solución

Asigná `NULL` al puntero inmediatamente después de llamar a `free`, como exige la {ref}`0x3002h`.

```c
int main()
{
    int *ptr = malloc(sizeof(*ptr));
    *ptr = 42;

    free(ptr);
    ptr = NULL;  // Previene el uso del puntero colgante

    // Intentar desreferenciar ptr ahora causará un error inmediato
    // en lugar de comportamiento indefinido silencioso

    return 0;
}
```

(memoria-double-free)=
### Double Free (Doble Liberación)

Intentar liberar el mismo bloque de memoria dos veces causa comportamiento indefinido y puede corromper la gestión de memoria del heap.

#### Ejemplo Problemático

```c
#include <stdlib.h>

int main()
{
    int *ptr = malloc(sizeof(*ptr));

    free(ptr);
    free(ptr);  // ERROR: Doble liberación

    return 0;
}
```

#### Solución

Asignar `NULL` después de cada `free` previene este problema, ya que `free(NULL)` es una operación segura que no hace nada.

```c
int main()
{
    int *ptr = malloc(sizeof(*ptr));

    free(ptr);
    ptr = NULL;

    free(ptr);  // Seguro: free(NULL) no hace nada

    return 0;
}
```

(memoria-acceso-invalido)=
### Acceso Fuera de Límites

Leer o escribir fuera de los límites del bloque de memoria reservado corrompe datos adyacentes y causa comportamiento impredecible.

#### Ejemplo Problemático

```c
#include <stdlib.h>

int main()
{
    int *arreglo = malloc(5 * sizeof(*arreglo));

    if (arreglo == NULL)
    {
        return 1;
    }

    // ERROR: Acceso fuera de límites
    for (size_t i = 0; i <= 5; i++)  // Debería ser i < 5
    {
        arreglo[i] = (int)i;
    }

    free(arreglo);
    arreglo = NULL;

    return 0;
}
```

#### Solución

La {ref}`0x300Ch` exige verificar siempre los límites de los arreglos antes de acceder a sus elementos. La {ref}`0x3010h` establece que las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`.

```c
int main()
{
    size_t tamano = 5;
    int *arreglo = malloc(tamano * sizeof(*arreglo));

    if (arreglo == NULL)
    {
        return 1;
    }

    // Correcto: i < tamano previene el acceso fuera de límites
    for (size_t i = 0; i < tamano; i++)
    {
        arreglo[i] = (int)i;
    }

    free(arreglo);
    arreglo = NULL;

    return 0;
}
```

(memoria-uso-despues-free)=
### Uso de Memoria Después de `free`

Acceder a memoria después de liberarla es un error similar al puntero colgante.

#### Ejemplo Problemático

```c
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = malloc(sizeof(*ptr));
    *ptr = 100;

    free(ptr);

    // ERROR: Uso de memoria liberada
    printf("%d\n", *ptr);

    return 0;
}
```

#### Solución

Asegurate de no usar el puntero después de liberarlo, y asigná `NULL` para detectar errores fácilmente.

:::{tip} Herramientas de Detección
Herramientas como **Valgrind** pueden detectar automáticamente fugas de memoria, accesos inválidos y otros errores relacionados con la gestión de memoria. Su uso es altamente recomendable durante el desarrollo. 
:::

(memoria-seguridad-conceptual)=
## Seguridad de Memoria: Una Perspectiva Profunda

La seguridad de memoria (memory safety) es uno de los desafíos más importantes en programación de sistemas. Comprender por qué los errores de memoria son tan peligrosos requiere entender qué significa "comportamiento indefinido" y cómo puede ser explotado.

(memoria-comportamiento-indefinido)=
### Comportamiento Indefinido (Undefined Behavior)

Cuando el estándar de C dice que una operación tiene "comportamiento indefinido" (UB), significa que **absolutamente cualquier cosa puede pasar**. El compilador no está obligado a hacer nada razonable.

**¿Por qué existe el UB?**

El comportamiento indefinido existe por dos razones principales:

1. **Rendimiento:** Verificar todos los accesos a memoria en tiempo de ejecución sería prohibitivamente lento. C delega la responsabilidad al programador para mantener la máxima velocidad.

2. **Flexibilidad del compilador:** El compilador puede hacer optimizaciones agresivas asumiendo que tu código no tiene UB. Si tenés UB, esas optimizaciones pueden hacer que tu programa haga cosas completamente inesperadas.

**Ejemplos de UB en gestión de memoria:**

```c
// UB #1: Desreferenciar puntero NULL
int *ptr = NULL;
*ptr = 42;  // Crash probable, pero no garantizado

// UB #2: Uso después de free
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 42;  // Puede parecer funcionar, pero es UB

// UB #3: Doble free
free(ptr);
free(ptr);  // Puede corromper el heap

// UB #4: Acceso fuera de límites
int arr[10];
arr[15] = 42;  // Puede sobrescribir otras variables

// UB #5: Retornar dirección de variable local
int *funcion() {
    int x = 42;
    return &x;  // x desaparece al retornar
}
```

**Consecuencias del UB:**

El comportamiento indefinido no solo causa crashes. Puede:

1. **Parecer funcionar:** El programa parece correr bien en tu máquina, pero falla en producción.

2. **Funcionar hasta que cambies algo no relacionado:** Agregar una línea de código en otro lado hace que el programa crashee, porque cambió el layout de memoria.

3. **Ser explotado por atacantes:** Los buffer overflows son la base de muchas vulnerabilidades de seguridad.

4. **Ser "optimizado" por el compilador de forma sorprendente:**

   ```c
   // El programador escribe:
   if (ptr != NULL) {
       *ptr = 42;
   }

   // Pero si el compilador ve *ptr antes del if,
   // puede asumir que ptr nunca es NULL (porque desreferenciarlo
   // cuando es NULL sería UB), y eliminar la verificación.
   ```

(memoria-vulnerabilidades)=
### Vulnerabilidades Comunes

Los errores de memoria no son solo bugs: son vulnerabilidades de seguridad. Comprender los ataques comunes te ayuda a escribir código más defensivo.

**Buffer Overflow:**

Un buffer overflow ocurre cuando escribís más datos de los que un buffer puede contener, sobrescribiendo memoria adyacente.

```c
void vulnerable()
{
    char buffer[10];
    char *datos_importantes = "SECRETO";

    // Un atacante puede escribir más de 10 bytes:
    strcpy(buffer, datos_maliciosos_largos);
    // Ahora datos_importantes puede haber sido sobrescrito
}
```

En el stack, un atacante puede sobrescribir la dirección de retorno para ejecutar código arbitrario:

```{figure} 14/buffer_overflow.svg
:name: fig-buffer-overflow
:width: 100%

Visualización de buffer overflow en el stack: antes del overflow el buffer tiene su espacio asignado y la dirección de retorno está protegida; después del overflow, datos excesivos (representados como 'A') sobrescriben el buffer, los datos intermedios, y finalmente corrompen la dirección de retorno, permitiendo potencialmente la ejecución de código malicioso.
```

**Use-After-Free (UAF):**

Usar memoria después de liberarla puede permitir que un atacante controle datos críticos:

```c
struct usuario {
    char nombre[50];
    int es_admin;
};

struct usuario *usr = malloc(sizeof(*usr));
usr->es_admin = 0;  // Usuario normal
free(usr);

// ... código intermedio ...

// Otro código asigna memoria que reutiliza el mismo espacio:
char *buffer = malloc(100);
strcpy(buffer, datos_del_atacante);

// Ahora usr apunta a memoria controlada por el atacante:
if (usr->es_admin) {  // ⚠️ UAF: usa memoria liberada
    // El atacante pudo sobrescribir es_admin a 1
    dar_privilegios_admin();
}
```

**Double Free:**

Liberar memoria dos veces puede corromper las estructuras internas del allocator, permitiendo ataques sofisticados:

```c
free(ptr);
// ... código ...
free(ptr);  // Corrompe la lista de bloques libres

// Asignaciones posteriores pueden retornar direcciones sobrepuestas:
int *a = malloc(100);
int *b = malloc(100);
// Ahora 'a' y 'b' podrían apuntar a la misma memoria!
```

(memoria-estrategias-defensivas)=
### Estrategias Defensivas

**1. Principio de mínimo privilegio:** No uses más memoria de la que necesitás, y no la mantengas asignada más tiempo del necesario.

**2. Verificación exhaustiva:**

```c
// No solo verificar malloc:
if (ptr == NULL) { /* error */ }

// También verificar límites:
if (indice >= tamano) { /* error */ }

// Y validar punteros recibidos:
if (ptr_entrada == NULL) { /* error */ }
```

**3. Inicialización defensiva:**

```c
// Inicializar punteros:
int *ptr = NULL;

// Después de free, anular:
free(ptr);
ptr = NULL;

// Inicializar estructuras completamente:
struct datos d = {0};  // Todos los campos en cero
```

**4. Encapsulación:** Ocultá la gestión de memoria detrás de funciones:

```c
// En lugar de exponer punteros directamente:
recurso_t *crear_recurso(void);
void usar_recurso(recurso_t *r);
void destruir_recurso(recurso_t *r);

// Los usuarios nunca ven malloc/free directamente
```

**5. Usar funciones seguras:**

```c
// En lugar de:
strcpy(dest, src);  // No verifica límites

// Usar:
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';

// O mejor aún, alocar dinámicamente con el tamaño correcto
```

:::{important} La Seguridad No Es Opcional
En el desarrollo profesional, los errores de memoria no son solo bugs molestos: son **vulnerabilidades de seguridad** que pueden ser explotadas. Cada uno de los errores discutidos (buffer overflow, UAF, double free) ha sido la base de ataques reales en sistemas de producción.

Escribir código memory-safe no es solo seguir buenas prácticas: es una responsabilidad ética. Tu código podría procesar datos sensibles, ejecutarse en infraestructura crítica, o estar expuesto a atacantes motivados. La seguridad debe ser parte del diseño desde el principio, no un añadido posterior.
:::

(memoria-buenas-practicas)=
## Resumen de Buenas Prácticas

La gestión segura de memoria dinámica requiere disciplina y adherencia a un conjunto de prácticas probadas. Este resumen consolida las reglas fundamentales.

(memoria-bp-inicializar)=
### Inicializar Punteros

Siempre inicializá los punteros a `NULL` al declararlos si no tenés una dirección válida para asignarles inmediatamente. Esto está codificado en la {ref}`0x0003h` y la {ref}`0x3008h`.

```c
int *ptr = NULL;
```

(memoria-bp-verificar)=
### Verificar Asignaciones

Siempre comprobá si el valor devuelto por `malloc` o `calloc` es `NULL` antes de usar el puntero. La {ref}`0x3001h` lo exige explícitamente.

```c
ptr = malloc(tamano);
if (ptr == NULL)
{
    // Manejo de error
    fprintf(stderr, "Error: No se pudo asignar memoria.\n");
    return ERROR_MEMORIA;
}
```

(memoria-bp-liberar)=
### Liberar Memoria

Por cada asignación exitosa con `malloc` o `calloc`, debe haber una llamada correspondiente a `free`. La {ref}`0x3002h` establece esta simetría como obligatoria.

```c
free(ptr);
```

(memoria-bp-anular)=
### Anular Punteros Después de Liberar

Después de llamar a `free(puntero)`, asigná `puntero = NULL` para evitar punteros colgantes. La {ref}`0x3002h` lo exige.

```c
free(ptr);
ptr = NULL;
```

(memoria-bp-simetria)=
### Mantener Simetría

Intentá que la función que reserva la memoria sea también responsable de liberarla, o que haya una correspondencia clara, como `crear_estructura()` y `destruir_estructura()`. Esta práctica está documentada en la {ref}`0x3002h`.

```c
recurso_t *crear_recurso()
{
    recurso_t *r = malloc(sizeof(*r));
    if (r == NULL)
    {
        return NULL;
    }
    // Inicialización...
    return r;
}

void destruir_recurso(recurso_t *r)
{
    if (r != NULL)
    {
        // Liberación de recursos internos...
        free(r);
    }
}
```

(memoria-bp-documentar)=
### Documentar Propiedad

La {ref}`0x3006h` exige que documentes claramente quién es el responsable de liberar la memoria cuando una función recibe o devuelve un puntero a memoria dinámica.

```c
/**
 * Crea un nuevo nodo de lista.
 * @param valor El valor a almacenar en el nodo.
 * @returns Un puntero al nuevo nodo. El llamador es responsable
 *          de liberar esta memoria con destruir_nodo().
 *          Retorna NULL si no hay memoria disponible.
 */
nodo_t *crear_nodo(int valor);
```

(memoria-bp-const)=
### Usar `const` Apropiadamente

Según la {ref}`0x3007h`, los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique. Esto establece un contrato claro y permite al compilador detectar modificaciones no intencionales.

```c
void imprimir_arreglo(const int *arreglo, size_t tamano)
{
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
```

(memoria-bp-sizeof)=
### Usar `sizeof` Correctamente

La {ref}`0x300Bh` establece que debés usar siempre `sizeof` en las asignaciones de memoria dinámica, y preferir `sizeof(*puntero)` sobre `sizeof(tipo)`.

```c
// Preferido
int *ptr = malloc(n * sizeof(*ptr));

// Evitar
int *ptr = malloc(n * sizeof(int));  // Si el tipo de ptr cambia, esto falla
```

(memoria-bp-tamanos)=
### Usar `size_t` para Tamaños e Índices

La {ref}`0x3010h` exige que las variables que representan tamaños o índices de arreglos sean de tipo `size_t`.

```c
size_t tamano = 10;
int *arreglo = malloc(tamano * sizeof(*arreglo));

for (size_t i = 0; i < tamano; i++)
{
    arreglo[i] = 0;
}
```

(memoria-bp-limites)=
### Verificar Límites

La {ref}`0x300Ch` exige verificar siempre los límites de los arreglos antes de acceder a sus elementos.

````c
void establecer_elemento(int *arreglo, size_t tamano, size_t indice, int valor)
{
    if (indice < tamano)
    {
        arreglo[indice] = valor;
    }
}

(memoria-ejemplo-integrador)=
## Ejemplo Integrador: Arreglo Dinámico de Tamaño Fijo

Este ejemplo demuestra cómo aplicar las buenas prácticas de gestión de memoria en un caso realista: una estructura que encapsula un arreglo dinámico de enteros de tamaño fijo.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_MEMORIA -1
#define ERROR_INDICE -2
#define EXITO 0

typedef struct
{
    int *datos;
    size_t tamano;
} arreglo_t;

/**
 * Crea un nuevo arreglo dinámico de tamaño fijo.
 * @param tamano El tamaño del arreglo (debe ser mayor que 0).
 * @returns Un puntero al arreglo creado. El llamador es responsable
 *          de liberar esta memoria con destruir_arreglo().
 *          Retorna NULL si no hay memoria disponible o si tamano es 0.
 * @post El arreglo está inicializado con todos sus elementos en 0.
 */
arreglo_t *crear_arreglo(size_t tamano)
{
    if (tamano == 0)
    {
        return NULL;
    }

    arreglo_t *arreglo = malloc(sizeof(*arreglo));
    if (arreglo == NULL)
    {
        return NULL;
    }

    arreglo->datos = calloc(tamano, sizeof(*(arreglo->datos)));
    if (arreglo->datos == NULL)
    {
        free(arreglo);
        return NULL;
    }

    arreglo->tamano = tamano;

    return arreglo;
}

/**
 * Establece el valor de un elemento en el arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param indice Índice del elemento a modificar.
 * @param valor Nuevo valor para el elemento.
 * @pre arreglo no debe ser NULL.
 * @pre indice debe ser menor que el tamaño del arreglo.
 * @returns EXITO si el valor se estableció correctamente,
 *          ERROR_INDICE si el índice es inválido.
 */
int establecer_elemento(arreglo_t *arreglo, size_t indice, int valor)
{
    if (arreglo == NULL)
    {
        return ERROR_MEMORIA;
    }

    if (indice >= arreglo->tamano)
    {
        return ERROR_INDICE;
    }

    arreglo->datos[indice] = valor;
    return EXITO;
}

/**
 * Obtiene el valor de un elemento del arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param indice Índice del elemento a obtener.
 * @param valor_out Puntero donde se almacenará el valor (no debe ser NULL).
 * @pre arreglo y valor_out no deben ser NULL.
 * @pre indice debe ser menor que el tamaño del arreglo.
 * @returns true si se obtuvo el elemento, false si algún parámetro es inválido.
 */
bool obtener_elemento(const arreglo_t *arreglo, size_t indice, int *valor_out)
{
    if (arreglo == NULL || valor_out == NULL)
    {
        return false;
    }

    if (indice >= arreglo->tamano)
    {
        return false;
    }

    *valor_out = arreglo->datos[indice];
    return true;
}

/**
 * Calcula la suma de todos los elementos del arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @pre arreglo no debe ser NULL.
 * @returns La suma de todos los elementos, o 0 si el arreglo es NULL.
 */
int sumar_elementos(const arreglo_t *arreglo)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    int suma = 0;
    for (size_t i = 0; i < arreglo->tamano; i++)
    {
        suma = suma + arreglo->datos[i];
    }

    return suma;
}

/**
 * Imprime todos los elementos del arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @pre arreglo no debe ser NULL.
 */
void imprimir_arreglo(const arreglo_t *arreglo)
{
    if (arreglo == NULL)
    {
        return;
    }

    printf("Arreglo [tamaño: %zu]: [", arreglo->tamano);

    for (size_t i = 0; i < arreglo->tamano; i++)
    {
        printf("%d", arreglo->datos[i]);
        if (i < arreglo->tamano - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

/**
 * Destruye un arreglo y libera toda la memoria asociada.
 * @param arreglo Puntero al arreglo a destruir. Puede ser NULL.
 * @post Toda la memoria del arreglo es liberada.
 */
void destruir_arreglo(arreglo_t *arreglo)
{
    if (arreglo != NULL)
    {
        if (arreglo->datos != NULL)
        {
            free(arreglo->datos);
        }
        free(arreglo);
    }
}

int main()
{
    size_t tamano = 8;
    arreglo_t *mi_arreglo = crear_arreglo(tamano);

    if (mi_arreglo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el arreglo.\n");
        return 1;
    }

    // Establecer algunos valores
    for (size_t i = 0; i < tamano; i++)
    {
        if (establecer_elemento(mi_arreglo, i, (int)(i * i)) != EXITO)
        {
            fprintf(stderr, "Error: No se pudo establecer elemento.\n");
            destruir_arreglo(mi_arreglo);
            return 1;
        }
    }

    imprimir_arreglo(mi_arreglo);

    // Obtener y mostrar un elemento específico
    int valor = 0;
    if (obtener_elemento(mi_arreglo, 3, &valor))
    {
        printf("Elemento en índice 3: %d\n", valor);
    }

    // Calcular la suma
    int suma = sumar_elementos(mi_arreglo);
    printf("Suma de todos los elementos: %d\n", suma);

    // Liberar recursos
    destruir_arreglo(mi_arreglo);

    return 0;
}
````

:::{note} Análisis del Ejemplo
Este ejemplo integra múltiples buenas prácticas:

- Inicialización de punteros a `NULL` ({ref}`0x0003h`)
- Verificación de todas las asignaciones de memoria ({ref}`0x3001h`)
- Uso de `calloc` para inicialización automática a cero
- Uso de `sizeof(*puntero)` ({ref}`0x300Bh`)
- Simetría con `crear_arreglo()` y `destruir_arreglo()` ({ref}`0x3002h`)
- Documentación completa de funciones ({ref}`0x000Ah`)
- Uso de `const` para parámetros no modificados ({ref}`0x3007h`)
- Uso de `size_t` para tamaños e índices ({ref}`0x3010h`)
- Verificación de límites antes de acceder a elementos ({ref}`0x300Ch`) 
:::

(memoria-conclusiones)=
## Conclusiones

La gestión de memoria dinámica es una de las características más poderosas y peligrosas de C. Su dominio requiere comprender no solo las funciones y sintaxis, sino también los principios fundamentales de cómo funciona la memoria en un programa.

Las buenas prácticas presentadas en este apunte no son sugerencias opcionales: son requisitos para escribir código C profesional y confiable. Cada regla existe porque previene errores reales que han causado innumerables problemas en sistemas de producción.

A medida que adquirás experiencia, estas prácticas se vuelven segunda naturaleza. Inicialmente pueden parecer restrictivas, pero con el tiempo reconocerás que son liberadoras: te permiten escribir código complejo con confianza, sabiendo que has evitado las trampas más comunes.

(memoria-referencias)=
## Referencias y Lecturas Adicionales

Para profundizar en la gestión de memoria, consultá:

- The C Programming Language, Kernighan & Ritchie (Capítulo 5: Punteros y Arreglos)
- C Programming: A Modern Approach, K. N. King (Capítulo 17: Memoria Dinámica)
- Modern C, Jens Gustedt (Nivel 2: Cognición)
- [Valgrind Documentation](https://valgrind.org/docs/manual/manual.html)

Para las reglas de estilo, consultá el documento {ref}`0x0000h` donde se detallan todas las convenciones utilizadas en este curso.

## Conceptos Clave

Este apunte explora la **gestión de memoria dinámica**, el mecanismo que permite a los programas solicitar y liberar memoria durante la ejecución, habilitando estructuras de datos flexibles y adaptables.

:::{important} Ideas Centrales

**Modelo de Memoria de un Proceso**
- **Stack (pila)**: memoria automática, variables locales, frames de función, LIFO
- **Heap (montículo)**: memoria dinámica, gestionada manualmente con `malloc`/`free`
- **Segmento de datos**: variables globales e estáticas
- **Segmento de código**: instrucciones del programa (read-only)

**Funciones de Gestión de Memoria**
- `malloc(size)`: solicita `size` bytes, retorna puntero o `NULL` si falla
- `calloc(n, size)`: solicita `n * size` bytes inicializados a cero
- `realloc(ptr, new_size)`: redimensiona bloque previamente asignado
- `free(ptr)`: libera memoria, **obligatorio** para evitar memory leaks

**Patrones de Uso Correctos**
- Siempre verificar si `malloc` retornó `NULL`
- Cada `malloc` debe tener exactamente un `free` correspondiente
- Liberar en orden inverso de asignación para estructuras anidadas
- Poner punteros en `NULL` después de `free` para evitar dangling pointers

**Errores Comunes y Graves**
- **Memory leak**: no liberar memoria asignada
- **Double free**: liberar la misma memoria dos veces (undefined behavior)
- **Use after free**: usar memoria ya liberada (dangling pointer)
- **Buffer overflow**: escribir más allá de los límites asignados
- **Fragmentación**: heap fragmentado reduce eficiencia de asignaciones

**Herramientas de Depuración**
- **Valgrind**: detecta leaks, invalid reads/writes, double frees
- **AddressSanitizer**: instrumentación de compilador para detección de errores
- **Análisis estático**: herramientas que detectan problemas sin ejecutar
:::

(memoria-avanzada-asm)=
## Conceptos Avanzados y Rendimiento de Bajo Nivel

En esta sección se presentan detalles técnicos complementarios sobre la ejecución y la jerarquía de hardware, orientados a comprender el rendimiento real de los programas.

### Funcionamiento de la Pila en Ensamblador (x86-64)

A nivel de arquitectura de hardware, la pila se gestiona a través de registros del procesador. En la arquitectura x86-64:
- El registro `rsp` (*Stack Pointer*) apunta al tope actual de la pila.
- El registro `rbp` (*Base Pointer* o *Frame Pointer*) apunta al inicio del marco de pila de la función en ejecución.

A continuación se muestra cómo se ve un prólogo y epílogo típico de una función en código ensamblador simplificado:

```asm
funcion:
    push rbp              ; Guardar frame pointer anterior
    mov rbp, rsp          ; Establecer nuevo frame pointer
    sub rsp, 16           ; Reservar espacio para variables locales

    ; ... cuerpo de la función ...

    mov rsp, rbp          ; Restaurar stack pointer
    pop rbp               ; Restaurar frame pointer anterior
    ret                   ; Retornar
```



## Conexión con el Siguiente Tema

Con memoria dinámica dominada, tenemos las herramientas para implementar cualquier estructura de datos. Pero antes de construir estructuras complejas, necesitamos entender **cómo medir su eficiencia**: ¿cuánto tiempo toma buscar un elemento? ¿Cómo crece el tiempo de ejecución al duplicar el tamaño de entrada?

El apunte {ref}`complejidad-introduccion` introduce el **análisis asintótico** de algoritmos:

- Notación Big-O, Omega, Theta para caracterizar crecimiento
- Análisis de lazos, recursión, y algoritmos complejos
- Jerarquía de complejidades: $O(1), O(\log n), O(n), O(n \log n), O(n^2), \ldots$
- Trade-offs entre tiempo y espacio

El análisis de complejidad es fundamental para tomar decisiones informadas: ¿vale la pena usar una lista enlazada (memoria dinámica, $O(n)$ búsqueda) o un arreglo redimensionable (overhead de copia, $O(1)$ acceso)? Sin complejidad, solo podemos intuir; con ella, podemos **demostrar matemáticamente** qué solución es mejor.

Después, el apunte **{ref}`tad-capitulo`** muestra cómo **encapsular** estructuras con memoria dinámica en Tipos Abstractos de Datos, ocultando detalles de implementación y exponiendo interfaces limpias.

**Pregunta puente**: Una búsqueda lineal en lista enlazada toma $O(n)$ tiempo. ¿Podemos hacer mejor? ¿Cómo cuantificamos "mejor"? La respuesta requiere análisis formal de complejidad algorítmica.
