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
Los errores discutidos en esta sección son específicos de la gestión de memoria dinámica. Para errores básicos con punteros (como punteros salvajes, desreferencia de `NULL`, y problemas de inicialización), consultá primero el [](5_punteros), que cubre los conceptos fundamentales necesarios para trabajar con punteros de forma segura.
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

(memoria-ejercicios)=
## Ejercicios

```{exercise} Asignación Básica
:label: ej-memoria-basico

Escribí un programa que:

1. Solicite al usuario la cantidad de números que desea ingresar.
2. Reserve memoria dinámica para un arreglo de enteros de ese tamaño.
3. Permita al usuario ingresar los números.
4. Calcule e imprima el promedio de los números.
5. Libere correctamente la memoria.

Asegurate de verificar todas las asignaciones de memoria y manejar los errores apropiadamente.
```

````{solution} ej-memoria-basico
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>

#define ERROR_MEMORIA 1
#define ERROR_ENTRADA 2

int main()
{
    int *numeros = NULL;
    size_t cantidad = 0;
    int suma = 0;

    printf("¿Cuántos números deseas ingresar? ");
    if (scanf("%zu", &cantidad) != 1 || cantidad == 0)
    {
        fprintf(stderr, "Error: Entrada inválida.\n");
        return ERROR_ENTRADA;
    }

    // Asignar memoria
    numeros = malloc(cantidad * sizeof(*numeros));
    if (numeros == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return ERROR_MEMORIA;
    }

    // Leer números
    printf("Ingresa %zu números:\n", cantidad);
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("Número %zu: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1)
        {
            fprintf(stderr, "Error: Entrada inválida.\n");
            free(numeros);
            numeros = NULL;
            return ERROR_ENTRADA;
        }
        suma = suma + numeros[i];
    }

    // Calcular promedio
    double promedio = (double)suma / (double)cantidad;
    printf("El promedio es: %.2f\n", promedio);

    // Liberar memoria
    free(numeros);
    numeros = NULL;

    return 0;
}
````

````

```{exercise} Cadena Dinámica
:label: ej-memoria-cadena

Implementá una función `duplicar_cadena` que reciba una cadena de caracteres y devuelva una copia exacta de ella en memoria dinámica. La función debe tener la siguiente firma:

```c
char *duplicar_cadena(const char *original);
````

La función debe:

1. Calcular el tamaño necesario (incluyendo el terminador nulo `\0`).
2. Reservar memoria dinámica para la copia.
3. Copiar el contenido caracter por caracter.
4. Retornar un puntero a la nueva cadena, o `NULL` si hay un error.

Luego, escribí un programa principal que use esta función para duplicar una cadena ingresada por el usuario.

````

:::{warning} Precondición de Seguridad en Copias de Cadenas
Al trabajar con cadenas de caracteres en C, funciones como `strlen` y `strcpy` asumen de forma estricta que los búferes de entrada están correctamente finalizados con el carácter nulo (`\0`). Si se recibe una secuencia de bytes que carece de este terminador (por ejemplo, debido a una lectura parcial o desborde anterior), la función continuará leyendo o escribiendo en memoria de forma indefinida, provocando violaciones de acceso o corrupción silenciosa del heap. Siempre garantizá la correcta inicialización y terminación en nulo del búfer origen antes de cualquier copia.
:::

````{solution} ej-memoria-cadena
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Duplica una cadena en memoria dinámica.
 * @param original Cadena a duplicar (no debe ser NULL y debe estar terminada en \0).
 * @returns Un puntero a la nueva cadena. El llamador es responsable
 *          de liberar esta memoria con free().
 *          Retorna NULL si original es NULL o no hay memoria disponible.
 */
char *duplicar_cadena(const char *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    size_t longitud = strlen(original);
    char *copia = malloc(longitud + 1);
    if (copia == NULL)
    {
        return NULL;
    }

    strcpy(copia, original);
    return copia;
}

int main()
{
    char original[100] = {0};

    printf("Ingresa una cadena (máximo 99 caracteres): ");
    if (fgets(original, sizeof(original), stdin) == NULL)
    {
        fprintf(stderr, "Error: No se pudo leer la cadena.\n");
        return 1;
    }

    // Remover el salto de línea si existe
    original[strcspn(original, "\n")] = '\0';

    char *copia = duplicar_cadena(original);
    if (copia == NULL)
    {
        fprintf(stderr, "Error: No se pudo duplicar la cadena.\n");
        return 1;
    }

    printf("Original: \"%s\"\n", original);
    printf("Copia: \"%s\"\n", copia);

    free(copia);
    copia = NULL;

    return 0;
}
````

````

```{exercise} Búsqueda en Arreglo Dinámico
:label: ej-memoria-busqueda

Implementá las siguientes funciones para trabajar con un arreglo dinámico de enteros:

```c
int *crear_arreglo_inicializado(size_t tamano, int valor_inicial);
int buscar_elemento(const int *arreglo, size_t tamano, int valor);
int contar_ocurrencias(const int *arreglo, size_t tamano, int valor);
````

- `crear_arreglo_inicializado`: Crea un arreglo dinámico donde todos los elementos tienen el valor `valor_inicial`.
- `buscar_elemento`: Retorna el índice de la primera ocurrencia de `valor` en el arreglo, o -1 si no se encuentra.
- `contar_ocurrencias`: Retorna cuántas veces aparece `valor` en el arreglo.

Escribí un programa principal que use estas funciones para crear un arreglo, inicializarlo, modificar algunos elementos, y luego buscar y contar ocurrencias de valores específicos.

````

```{solution} ej-memoria-busqueda
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea un arreglo dinámico inicializado con un valor específico.
 * @param tamano Tamaño del arreglo (debe ser mayor que 0).
 * @param valor_inicial Valor con el que se inicializará cada elemento.
 * @returns Un puntero al arreglo creado. El llamador es responsable
 *          de liberar esta memoria con free().
 *          Retorna NULL si tamano es 0 o no hay memoria disponible.
 */
int *crear_arreglo_inicializado(size_t tamano, int valor_inicial)
{
    if (tamano == 0)
    {
        return NULL;
    }

    int *arreglo = malloc(tamano * sizeof(*arreglo));
    if (arreglo == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        arreglo[i] = valor_inicial;
    }

    return arreglo;
}

/**
 * Busca la primera ocurrencia de un valor en el arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 * @param valor Valor a buscar.
 * @returns El índice de la primera ocurrencia, o -1 si no se encuentra.
 */
int buscar_elemento(const int *arreglo, size_t tamano, int valor)
{
    if (arreglo == NULL)
    {
        return -1;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            return (int)i;
        }
    }

    return -1;
}

/**
 * Cuenta cuántas veces aparece un valor en el arreglo.
 * @param arreglo Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 * @param valor Valor a contar.
 * @returns El número de ocurrencias del valor.
 */
int contar_ocurrencias(const int *arreglo, size_t tamano, int valor)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    int contador = 0;
    for (size_t i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            contador = contador + 1;
        }
    }

    return contador;
}

int main()
{
    size_t tamano = 10;
    int valor_inicial = 5;

    int *arreglo = crear_arreglo_inicializado(tamano, valor_inicial);
    if (arreglo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el arreglo.\n");
        return 1;
    }

    printf("Arreglo inicial (todos %d): ", valor_inicial);
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Modificar algunos elementos
    arreglo[2] = 10;
    arreglo[5] = 10;
    arreglo[7] = 15;

    printf("Arreglo modificado: ");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Buscar valores
    int buscar = 10;
    int indice = buscar_elemento(arreglo, tamano, buscar);
    if (indice != -1)
    {
        printf("Primera ocurrencia de %d: índice %d\n", buscar, indice);
    }
    else
    {
        printf("No se encontró %d en el arreglo\n", buscar);
    }

    // Contar ocurrencias
    int ocurrencias = contar_ocurrencias(arreglo, tamano, buscar);
    printf("El valor %d aparece %d veces\n", buscar, ocurrencias);

    ocurrencias = contar_ocurrencias(arreglo, tamano, valor_inicial);
    printf("El valor %d aparece %d veces\n", valor_inicial, ocurrencias);

    free(arreglo);
    arreglo = NULL;

    return 0;
}
````

````

```{exercise} Matriz Dinámica
:label: ej-memoria-matriz

Implementá funciones para crear y manipular una matriz dinámica de enteros de tamaño $m \times n$:

```c
int **crear_matriz(size_t filas, size_t columnas);
void liberar_matriz(int **matriz, size_t filas);
void imprimir_matriz(int **matriz, size_t filas, size_t columnas);
````

Asegurate de:

- Liberar la memoria en el orden correcto ({ref}`0x3009h`).
- Verificar todas las asignaciones.
- Manejar errores apropiadamente.

````

```{solution} ej-memoria-matriz
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea una matriz dinámica de enteros.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @returns Un puntero a la matriz creada. El llamador es responsable
 *          de liberar esta memoria con liberar_matriz().
 *          Retorna NULL si no hay memoria disponible.
 */
int **crear_matriz(size_t filas, size_t columnas)
{
    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = malloc(columnas * sizeof(*(matriz[i])));
        if (matriz[i] == NULL)
        {
            // Liberar las filas ya asignadas
            for (size_t j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }

        // Inicializar la fila en 0
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

/**
 * Libera una matriz dinámica.
 * @param matriz Puntero a la matriz. Puede ser NULL.
 * @param filas Número de filas de la matriz.
 */
void liberar_matriz(int **matriz, size_t filas)
{
    if (matriz == NULL)
    {
        return;
    }

    // Liberar en orden inverso: primero las filas, luego el arreglo
    for (size_t i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

/**
 * Imprime una matriz.
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @pre matriz no debe ser NULL.
 */
void imprimir_matriz(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    size_t filas = 3;
    size_t columnas = 4;

    int **matriz = crear_matriz(filas, columnas);
    if (matriz == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la matriz.\n");
        return 1;
    }

    // Llenar la matriz con valores
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = (int)(i * columnas + j);
        }
    }

    printf("Matriz %zu x %zu:\n", filas, columnas);
    imprimir_matriz(matriz, filas, columnas);

    liberar_matriz(matriz, filas);

    return 0;
}
````

````

```{exercise} Estructura con Memoria Dinámica
:label: ej-memoria-estructura

Implementá un tipo de dato `persona_t` que almacene información de una persona:

```c
typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;
````

Implementá las siguientes funciones:

```c
persona_t *crear_persona(const char *nombre, const char *apellido, int edad);
void destruir_persona(persona_t *persona);
void imprimir_persona(const persona_t *persona);
```

- `crear_persona`: Debe reservar memoria para la estructura y para las cadenas de nombre y apellido (copiándolas).
- `destruir_persona`: Debe liberar toda la memoria asociada, incluyendo las cadenas internas.
- `imprimir_persona`: Debe mostrar los datos de la persona.

Recordá seguir el principio de simetría ({ref}`0x3002h`) y verificar todas las asignaciones de memoria.

````

````{solution} ej-memoria-estructura
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
} persona_t;

/**
 * Duplica una cadena en memoria dinámica verificando la precondición de terminación en nulo.
 */
char *duplicar_cadena(const char *cadena)
{
    if (cadena == NULL)
    {
        return NULL;
    }

    size_t longitud = strlen(cadena);
    char *copia = malloc(longitud + 1);

    if (copia == NULL)
    {
        return NULL;
    }

    strcpy(copia, cadena);
    return copia;
}

/**
 * Crea una nueva persona.
 * @param nombre Nombre de la persona (no debe ser NULL).
 * @param apellido Apellido de la persona (no debe ser NULL).
 * @param edad Edad de la persona.
 * @returns Un puntero a la persona creada. El llamador es responsable
 *          de liberar esta memoria con destruir_persona().
 *          Retorna NULL si hay un error.
 */
persona_t *crear_persona(const char *nombre, const char *apellido, int edad)
{
    if (nombre == NULL || apellido == NULL)
    {
        return NULL;
    }

    persona_t *persona = malloc(sizeof(*persona));
    if (persona == NULL)
    {
        return NULL;
    }

    persona->nombre = duplicar_cadena(nombre);
    if (persona->nombre == NULL)
    {
        free(persona);
        return NULL;
    }

    persona->apellido = duplicar_cadena(apellido);
    if (persona->apellido == NULL)
    {
        free(persona->nombre);
        free(persona);
        return NULL;
    }

    persona->edad = edad;

    return persona;
}

/**
 * Destruye una persona y libera toda su memoria.
 * @param persona Puntero a la persona a destruir. Puede ser NULL.
 */
void destruir_persona(persona_t *persona)
{
    if (persona != NULL)
    {
        if (persona->nombre != NULL)
        {
            free(persona->nombre);
        }
        if (persona->apellido != NULL)
        {
            free(persona->apellido);
        }
        free(persona);
    }
}

/**
 * Imprime los datos de una persona.
 * @param persona Puntero a la persona (no debe ser NULL).
 */
void imprimir_persona(const persona_t *persona)
{
    if (persona == NULL)
    {
        return;
    }

    printf("Nombre: %s %s\n", persona->nombre, persona->apellido);
    printf("Edad: %d años\n", persona->edad);
}

int main()
{
    persona_t *p1 = crear_persona("Juan", "Pérez", 30);

    if (p1 == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la persona.\n");
        return 1;
    }

    imprimir_persona(p1);
    destruir_persona(p1);

    return 0;
}
````

````

```{exercise} Detección de Errores de Memoria
:label: ej-memoria-errores

El siguiente programa contiene varios errores relacionados con la gestión de memoria. Identificá todos los errores, explicá por qué son problemáticos, y corregílos.

```c
#include <stdio.h>
#include <stdlib.h>

int *crear_arreglo(int tamano)
{
    int *arr = malloc(tamano * sizeof(int));
    for (int i = 0; i <= tamano; i++)
    {
        arr[i] = i;
    }
    return arr;
}

void procesar_arreglo(int *arr, int tamano)
{
    free(arr);
    printf("Procesando arreglo...\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *numeros = crear_arreglo(5);
    procesar_arreglo(numeros, 5);

    int valor = numeros[0];
    printf("Primer valor: %d\n", valor);

    free(numeros);

    return 0;
}
````

````

```{solution} ej-memoria-errores
:class: dropdown

**Errores identificados:**

1. **En `crear_arreglo`:** No se verifica si `malloc` retornó `NULL`.
2. **En `crear_arreglo`:** Acceso fuera de límites en el lazo (`i <= tamano` debería ser `i < tamano`).
3. **En `crear_arreglo`:** Falta usar `sizeof(*arr)` en lugar de `sizeof(int)` para mayor robustez.
4. **En `crear_arreglo`:** Se debería usar `size_t` para `tamano` en lugar de `int`.
5. **En `procesar_arreglo`:** Se libera la memoria al principio y luego se intenta acceder a ella (uso después de `free`).
6. **En `main`:** Se accede a `numeros` después de que fue liberado en `procesar_arreglo` (puntero colgante).
7. **En `main`:** Doble liberación: se llama a `free(numeros)` dos veces (una en `procesar_arreglo` y otra en `main`).
8. **En `main`:** No se establece `numeros = NULL` después de liberar.

**Código corregido:**

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea un arreglo dinámico inicializado con valores secuenciales.
 * @param tamano Tamaño del arreglo (debe ser mayor que 0).
 * @returns Un puntero al arreglo creado, o NULL si hay un error.
 */
int *crear_arreglo(size_t tamano)
{
    if (tamano == 0)
    {
        return NULL;
    }

    int *arr = malloc(tamano * sizeof(*arr));
    if (arr == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < tamano; i++)
    {
        arr[i] = (int)i;
    }

    return arr;
}

/**
 * Procesa un arreglo imprimiendo sus elementos.
 * @param arr Puntero al arreglo (no debe ser NULL).
 * @param tamano Tamaño del arreglo.
 */
void procesar_arreglo(const int *arr, size_t tamano)
{
    if (arr == NULL)
    {
        return;
    }

    printf("Procesando arreglo...\n");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    size_t tamano = 5;
    int *numeros = crear_arreglo(tamano);

    if (numeros == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el arreglo.\n");
        return 1;
    }

    procesar_arreglo(numeros, tamano);

    int valor = numeros[0];
    printf("Primer valor: %d\n", valor);

    free(numeros);
    numeros = NULL;

    return 0;
}
````

**Cambios realizados:**

- Se agregó verificación de `malloc`.
- Se corrigió el lazo para evitar acceso fuera de límites.
- Se cambió `int` por `size_t` para tamaños.
- Se usó `sizeof(*arr)` en lugar de `sizeof(int)`.
- Se removió el `free` de `procesar_arreglo` (violaba el principio de responsabilidad única).
- Se marcó el parámetro de `procesar_arreglo` como `const` para indicar que no modifica el arreglo.
- Se agregó `numeros = NULL` después de liberar.
- Se agregó verificación de que `numeros` no es `NULL` antes de usarlo.

```

```

````{exercise} Matriz Contígua con Puntero a Array
:label: ej-memoria-puntero-array

Implementá funciones para crear y manipular una matriz dinámica contigua usando un puntero plano (`int *`):

```c
// Crear matriz de N filas y M columnas (contígua en memoria)
int *crear_matriz_contigua(size_t filas, size_t columnas);

// Llenar la matriz con un patrón: matriz[i * columnas + j] = i * columnas + j
void llenar_matriz(int *matriz, size_t filas, size_t columnas);

// Imprimir la matriz
void imprimir_matriz_contigua(const int *matriz, size_t filas, size_t columnas);

// Transponer la matriz in-place (solo para matrices cuadradas)
void transponer_cuadrada(int *matriz, size_t n);
```

Requisitos:

- Toda la memoria debe asignarse en un solo bloque contiguo en el heap.
- Debe liberarse con una sola llamada a `free`.
- El acceso a los elementos en la fila `i` y columna `j` debe realizarse mediante cálculo manual de índices: `i * columnas + j`.
- La función `transponer_cuadrada` debe intercambiar el elemento en `(i, j)` con el de `(j, i)`.

Escribí un programa principal que:

1. Cree una matriz 4×4 contígua.
2. La llene con valores.
3. La imprima.
4. La transponga.
5. La imprima nuevamente.
6. Libere correctamente la memoria.

````

````{solution} ej-memoria-puntero-array
:class: dropdown

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea una matriz dinámica contigua usando un puntero plano.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @returns Un puntero plano que apunta a la matriz, o NULL si hay error.
 */
int *crear_matriz_contigua(size_t filas, size_t columnas)
{
    // Asignar memoria contígua para todos los elementos (filas * columnas)
    int *matriz = malloc(filas * columnas * sizeof(*matriz));

    if (matriz == NULL)
    {
        return NULL;
    }

    // Inicializar a cero
    for (size_t i = 0; i < filas * columnas; i++)
    {
        matriz[i] = 0;
    }

    return matriz;
}

/**
 * Llena la matriz con el patrón: matriz[i * columnas + j] = i * columnas + j
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 */
void llenar_matriz(int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i * columnas + j] = (int)(i * columnas + j);
        }
    }
}

/**
 * Imprime la matriz.
 * @param matriz Puntero a la matriz (no debe ser NULL).
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 */
void imprimir_matriz_contigua(const int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL)
    {
        return;
    }

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i * columnas + j]);
        }
        printf("\n");
    }
}

/**
 * Transpone una matriz cuadrada in-place.
 * @param matriz Puntero a la matriz cuadrada (no debe ser NULL).
 * @param n Tamaño de la matriz (n×n).
 */
void transponer_cuadrada(int *matriz, size_t n)
{
    if (matriz == NULL)
    {
        return;
    }

    // Intercambiar matriz[i * n + j] con matriz[j * n + i]
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            int temp = matriz[i * n + j];
            matriz[i * n + j] = matriz[j * n + i];
            matriz[j * n + i] = temp;
        }
    }
}

int main()
{
    size_t n = 4;  // Matriz 4×4

    // Crear matriz contígua
    int *matriz = crear_matriz_contigua(n, n);

    if (matriz == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la matriz.\n");
        return 1;
    }

    // Llenar con patrón
    llenar_matriz(matriz, n, n);

    printf("Matriz original %zu×%zu:\n", n, n);
    imprimir_matriz_contigua(matriz, n, n);

    // Transponer
    transponer_cuadrada(matriz, n);

    printf("\nMatriz transpuesta:\n");
    imprimir_matriz_contigua(matriz, n, n);

    // Verificar la transposición
    printf("\nVerificación:\n");
    printf("Elemento [0][1] (era 1, ahora debe ser 4): %d\n", matriz[0 * n + 1]);
    printf("Elemento [1][0] (era 4, ahora debe ser 1): %d\n", mocesar_heap()
{
    int *datos = malloc(1000 * sizeof(int));  // Llamada a función

    if (datos == NULL) return;

    // Posiblemente más cache misses:
    for (int i = 0; i < 1000; i++)
    {
        datos[i] = i * 2;  // Menos predecible para el hardware
    }

    free(datos);  // Otra llamada a función
}
```

En un benchmark real, la versión stack podría ser 2-5 veces más rápida, especialmente para arreglos pequeños que caben completamente en caché.

:::{note} Optimización 
Práctica Comprender el caché te permite optimizar código:

```c
// Malo: Recorrer matriz por columnas (pobre localidad)
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        matriz[i][j] = 0;  // Saltos grandes en memoria

// Bueno: Recorrer por filas (buena localidad)
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        matriz[i][j] = 0;  // Acceso secuencial
```

La segunda versión puede ser 10-50 veces más rápida para matrices grandes, simplemente porque usa mejor el caché. 
:::

(memoria-fragmentacion)=
### Fragmentación de Memoria

La fragmentación es un fenómeno que ocurre cuando el heap contiene bloques libres pequeños dispersos que no pueden satisfacer solicitudes de memoria más grandes, incluso si la suma total de memoria libre sería suficiente.

Imaginá que tenés un estante con espacios libres dispersos de diferentes tamaños. Aunque la suma total de espacio libre sea grande, si necesitás colocar un libro grande y solo tenés espacios pequeños separados, no podrás hacerlo. Lo mismo ocurre con la memoria.

**Fragmentación Externa:** Espacios libres entre bloques asignados que son demasiado pequeños para ser útiles individualmente. Ocurre cuando asignás y liberás bloques de memoria de diferentes tamaños en un orden arbitrario, dejando "huecos" entre bloques ocupados.

**Ejemplo conceptual:**

```{figure} 14/fragmentacion_externa.svg
:name: fig-fragmentacion-externa
:width: 100%

Proceso de fragmentación externa: se asignan tres bloques (A, B, C), luego se libera B dejando un hueco. Ahora hay dos bloques libres separados, pero ninguno puede satisfacer una solicitud del tamaño de A+B.
```

Ahora hay dos bloques libres, pero si necesitás un bloque del tamaño de A+B, no podés usar el espacio libre entre A y C.

**Fragmentación Interna:** Desperdicio de memoria dentro de un bloque asignado cuando se solicita menos de lo que el sistema asigna. Algunos sistemas asignan memoria en múltiplos de cierto tamaño (por ejemplo, bloques de 16 bytes), entonces si pedís 10 bytes, te dan 16 y los 6 extra se desperdician.

**Cómo minimizar la fragmentación:**

- Liberá memoria en el orden inverso al que la asignaste cuando sea posible.
- Usá tamaños consistentes para asignaciones frecuentes.
- Considerá usar memory pools para objetos de tamaño fijo (tema avanzado).

(memoria-alineacion)=
### Alineación de Memoria

La alineación de memoria es un concepto fundamental que afecta tanto el rendimiento como la corrección de los programas. Comprender por qué existe y cómo funciona te permite escribir código más eficiente.

**¿Qué es la alineación?**

Un dato está **alineado** cuando su dirección de memoria es un múltiplo de su tamaño. Por ejemplo:

- Un `char` (1 byte) puede estar en cualquier dirección.
- Un `short` (2 bytes) debería estar en direcciones múltiplo de 2.
- Un `int` (4 bytes) debería estar en direcciones múltiplo de 4.
- Un `double` (8 bytes) debería estar en direcciones múltiplo de 8.

```{figure} 14/memory_alignment.svg
:name: fig-memory-alignment
:width: 100%

Comparación entre memoria bien alineada (donde cada int comienza en un múltiplo de 4) y mal alineada (causando penalización de rendimiento). El acceso alineado requiere una sola lectura del CPU, mientras que el desalineado requiere múltiples lecturas y manipulación de bits.
```

**¿Por qué importa la alineación?**

Los procesadores modernos leen memoria en bloques (palabras) de tamaño fijo, típicamente 4 u 8 bytes a la vez. Si un dato no está alineado:

1. **Penalización de rendimiento:** El CPU debe hacer múltiples lecturas y combinarlas con operaciones de bits. Una lectura alineada toma 1 operación, mientras que una desalineada puede tomar 2 operaciones más manipulación adicional (2-3x más lento).

2. **En algunas arquitecturas, causa errores:** ARM en modo estricto y algunos procesadores RISC generan excepciones de alineación.

3. **Operaciones atómicas:** Muchas instrucciones atómicas (necesarias para multithreading) requieren alineación natural.

**Alineación en estructuras:**

El compilador inserta "padding" (bytes de relleno) para mantener la alineación:

```c
struct ejemplo {
    char a;      // 1 byte
    // 3 bytes de padding insertados automáticamente
    int b;       // 4 bytes (debe estar en múltiplo de 4)
    char c;      // 1 byte
    // 3 bytes de padding al final para el arreglo
};

// sizeof(struct ejemplo) = 12, no 6
```

**Visualización:**

```{figure} 14/struct_padding.svg
:name: fig-struct-padding
:width: 100%

Comparación entre una estructura sin padding (incorrecta con desalineación) y con padding (correcta con alineación apropiada). El compilador inserta bytes de relleno para mantener la alineación de los campos.
```

**Optimizar estructuras:**

Podés minimizar el padding ordenando los campos de mayor a menor:

```c
// Desperdicia espacio (16 bytes):
struct ineficiente {
    char a;      // 1 byte
    int b;       // 4 bytes (+ 3 padding antes)
    char c;      // 1 byte (+ 3 padding después)
};

// Más eficiente (8 bytes):
struct eficiente {
    int b;       // 4 bytes
    char a;      // 1 byte
    char c;      // 1 byte
    // 2 bytes padding al final (menos que antes)
};
```

**Verificar alineación:**

```c
#include <stdio.h>
#include <stddef.h>

struct prueba {
    char a;
    int b;
    char c;
};

int main()
{
    printf("Tamaño de struct: %zu\n", sizeof(struct prueba));
    printf("Offset de 'a': %zu\n", offsetof(struct prueba, a));
    printf("Offset de 'b': %zu\n", offsetof(struct prueba, b));
    printf("Offset de 'c': %zu\n", offsetof(struct prueba, c));

    return 0;
}
```

**malloc y alineación:**

Las funciones de asignación de memoria (`malloc` y `calloc`) garantizan que la memoria devuelta está adecuadamente alineada para cualquier tipo de dato estándar. Típicamente retornan direcciones alineadas a 8 o 16 bytes, lo cual satisface los requisitos de todos los tipos básicos.

```c
int *p = malloc(sizeof(int));
// p está garantizado como alineado para 'int'

struct grande {
    double d;  // Necesita alineación de 8 bytes
    long l;
};
struct grande *s = malloc(sizeof(*s));
// s está garantizado como alineado para todos los campos
```

:::{note} Packed Structures
Podés forzar al compilador a no insertar padding usando atributos específicos del compilador:

```c
struct __attribute__((packed)) sin_padding {
    char a;
    int b;      // Puede estar desalineado
    char c;
};
// sizeof = 6, pero acceso más lento a 'b'
```

Esto es útil para formatos de archivos binarios o protocolos de red, pero reduce el rendimiento. Usalo solo cuando la compatibilidad binaria es más importante que la velocidad.
:::

(memoria-valgrind)=

### Herramientas de Depuración: Valgrind

Valgrind es una herramienta fundamental para detectar errores de memoria en programas C y C++. Funciona ejecutando tu programa en un entorno virtualizado donde puede monitorear cada acceso a memoria y operación de asignación/liberación.

**Tipos de errores que detecta:**

- **Fugas de memoria (memory leaks):** Bloques de memoria asignados que nunca fueron liberados.
- **Accesos a memoria no inicializada:** Leer valores de memoria que nunca fueron escritos.
- **Accesos fuera de límites:** Leer o escribir más allá de los límites de un bloque asignado.
- **Dobles liberaciones:** Intentar liberar el mismo bloque dos veces.
- **Uso de memoria después de `free`:** Acceder a memoria que ya fue liberada.
- **Desajustes entre asignación y liberación:** Por ejemplo, asignar con `malloc` y liberar con `delete` (en C++).

**Uso básico:**

```bash
# Compilar con símbolos de depuración
gcc -g -o programa programa.c

# Ejecutar con Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./programa
```

**Opciones útiles:**

- `--leak-check=full`: Muestra detalles completos de las fugas de memoria.
- `--show-leak-kinds=all`: Muestra todos los tipos de fugas.
- `--track-origins=yes`: Rastrea el origen de valores no inicializados (más lento pero útil).
- `--verbose`: Muestra información adicional de depuración.

**Interpretando la salida:**

Cuando Valgrind detecta un error, muestra:

- El tipo de error
- La ubicación en el código (archivo y línea)
- El stack trace (secuencia de llamadas que llevó al error)
- Para fugas de memoria: dónde se asignó el bloque que no fue liberado

**Ejemplo de salida:**

```
==12345== Invalid write of size 4
==12345==    at 0x108A: main (programa.c:15)
==12345==  Address 0x522d068 is 0 bytes after a block of size 40 alloc'd
```

Esto indica que se intentó escribir 4 bytes fuera de un bloque de 40 bytes asignado, en la línea 15 del archivo `programa.c`.

:::{important} Desarrollo Profesional
En un entorno profesional, es inaceptable entregar código con errores de memoria. El uso de herramientas como Valgrind durante el desarrollo no es opcional, es una práctica estándar de la industria. Acostumbrate a ejecutar Valgrind regularmente durante el desarrollo, no solo cuando sospechás que hay un problema. 
:::



La segunda versión puede ser 10-100 veces más rápida.

**2. La localidad de acceso importa enormemente:**

```c
// Malo: Acceso aleatorio (muchos cache misses)
for (int i = 0; i < n; i++)
{
    int idx = random_index();
    data[idx] = process(data[idx]);  // Impredecible para el caché
}

// Bueno: Acceso secuencial (cache hits)
for (int i = 0; i < n; i++)
{
    data[i] = process(data[i]);  // Predecible, alta localidad
}
```

**3. El tamaño de la estructura de datos importa:**

```c
// Si tu estructura cabe en caché L1 (32 KB):
struct pequena datos[1000];  // 4 KB total, cabe en L1
// Acceso muy rápido, todo en caché

// Si excede la caché L3 (8 MB):
struct grande datos[1000000];  // 100 MB, no cabe
// Muchos accesos a RAM, más lento
```

**4. El costo de la indirección:**

```c
// Un nivel de indirección:
int *ptr = malloc(sizeof(int));
*ptr = 42;  // Lee ptr, luego lee *ptr (2 accesos potenciales a RAM)

// Dos niveles de indirección:
int **ptr2 = malloc(sizeof(int *));
*ptr2 = malloc(sizeof(int));
**ptr2 = 42;  // Lee ptr2, luego *ptr2, luego **ptr2 (3 accesos)

// Directo (sin indirección):
int valor = 42;  // Puede estar en registro, cero accesos a memoria
```

**Ejemplo cuantitativo:**

Considerá procesar un millón de elementos:

```c
// Opción A: Arreglo continuo (stack o heap)
int arreglo[1000000];
for (int i = 0; i < 1000000; i++)
{
    arreglo[i] = i * 2;
}
// Costo: ~1 millón de escrituras secuenciales
// Cache: Muy efectivo (prefetching automático)
// Tiempo: ~1-2 ms en un CPU moderno

// Opción B: Lista enlazada (heap)
struct nodo *lista = crear_lista(1000000);
struct nodo *actual = lista;
int i = 0;
while (actual != NULL)
{
    actual->valor = i * 2;
    actual = actual->siguiente;  // Sigue puntero (indirección)
    i++;
}
// Costo: ~1 millón de escrituras + 1 millón de lecturas de punteros
// Cache: Malo (los nodos están dispersos)
// Tiempo: ~5-20 ms (3-10x más lento)
```

**Estrategias de optimización basadas en el modelo de costos:**

1. **Minimizá asignaciones dinámicas:** Usá stack cuando sea posible, o pooling de memoria.

2. **Maximizá localidad:** Mantené datos relacionados físicamente juntos.

3. **Reducí indirección:** Preferí arreglos sobre listas enlazadas cuando el acceso aleatorio es importante.

4. **Batch operations:** Procesá múltiples elementos antes de saltar a otra región de memoria.

5. **Considerá el cache line size:** Operá en bloques de ~64 bytes cuando sea posible.

:::{important} Profiling sobre Intuición
Aunque este modelo proporciona intuición valiosa, siempre **medí** antes de optimizar. Usa herramientas de profiling como `perf`, `gprof`, o `Valgrind --tool=cachegrind` para identificar cuellos de botella reales. La optimización prematura basada en intuición puede hacer el código más complejo sin beneficios reales. 
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
