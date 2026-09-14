---
title: 'Estructuras y Tipos Compuestos'
short_title: Estructuras
subtitle: 'struct, union y campos de bits en C'
---

(capitulo-estructuras)=
## Introducción

En C, las **estructuras (`struct`)**, **uniones (`union`)** y **campos de bits
(bit-fields)** son las herramientas fundamentales que nos permiten ir más allá
de los tipos de datos básicos. Nos dan el poder de modelar entidades complejas
del mundo real, optimizar el uso de la memoria hasta el nivel del bit y
construir cualquier otra estructura de datos imaginable.

Dominar estos conceptos es crucial. Implica entender no solo la sintaxis, sino
cómo C organiza los datos en la memoria, un conocimiento que separa a un
programador novato de uno que puede escribir código eficiente, portable y
robusto.

Este apunte es un laboratorio práctico. No solo explica la teoría, sino que
proporciona ejemplos completos y los comandos para que puedas compilar, ejecutar
e inspeccionar el comportamiento de la memoria en tu propio sistema.

:::{warning}

Muchos detalles de bajo nivel, como el `padding` y el orden de los bits, son
**dependientes de la implementación**. Los ejemplos asumen una arquitectura
común (x86_64, little-endian), pero siempre debés verificar en tu plataforma.

:::
<!-- {warning} -->

(estructuras-struct-agrupando-datos)=

## Desarrollo

Los Ladrillos de la memoria

### Estructuras (`struct`): Agrupando Datos

Una `struct` es una colección de variables (miembros) de diferentes tipos,
agrupadas bajo un solo nombre.

:::{figure} 7/struct_memory_layout.svg
:name: fig-struct-memory-layout
:alt: Organización de estructuras en memoria
:align: center

Las estructuras agrupan datos relacionados en memoria. El compilador puede
añadir padding entre campos para optimizar el acceso.

:::
<!-- {figure} 4/struct_memory_layout.svg -->

(declaracion-y-typedef)=
#### Declaración y `typedef`

La práctica estándar, como indica la regla {ref}`0x3004h`, es usar `typedef`
para crear un alias de tipo con el sufijo `_t`.

:::{code-block}c
:linenos:
typedef struct
{
    char inicial;
    int legajo;
    float promedio;
} estudiante_t;
// Inicialización con inicializadores designados (preferido)
estudiante_t estudiante1 = {.inicial = 'J', .legajo = 12345, .promedio = 8.5f};
:::
<!-- {code-block}c -->

(acceso-a-miembros-vs)=
#### Acceso a Miembros: `.` vs `->`

- **Operador Punto (`.`):** Para acceder a miembros de una variable `struct`.
- **Operador Flecha (`->`):** Para acceder a miembros a través de un **puntero**
  a una `struct`.

:::{code-block}c
:linenos:
estudiante_t est;
estudiante_t *p_est = &est;
est.legajo = 54321;     // Acceso directo
p_est->promedio = 9.0f; // Acceso mediante puntero
:::
<!-- {code-block}c -->

El acceso `->` es equivalente a usar `(*p_est).promedio`, se prefiere la flecha
para simplificar este uso.

(estructuras-y-memoria-alineacion-y-relleno-padding)=
#### Estructuras y Memoria: Alineación y Relleno (Padding)

El compilador de C inserta bytes de relleno invisibles (denominados **padding**)
entre los miembros de un `struct` para que cada uno quede alineado en
direcciones de memoria que sean múltiplos de su respectivo tamaño (por ejemplo,
los enteros `int` en direcciones múltiplos de 4, los enteros `short` en
múltiplos de 2, etc.).

La razón detrás de este comportamiento radica en la eficiencia del hardware: la
CPU no accede a la RAM física byte a byte, sino en **palabras de memoria** de 32
o 64 bits a través de su bus de datos. Si un entero de 4 bytes se encuentra en
una dirección desalineada (por ejemplo, una dirección impar como `0x01`), la CPU
se vería obligada a realizar dos transferencias físicas por el bus de datos y
operaciones lógicas de shift para rearmar el valor, degradando la performance
del sistema.

:::{figure} 7/alineamiento_struct.svg
:label: fig-alineamiento-struct
:align: center
:width: 90%

Disposición física de una estructura mixta en RAM. El compilador inserta bytes
de relleno (*pad*) para garantizar que el entero `b` inicie en una dirección
múltiplo de 4, incrementando el `sizeof` total de 7 a 12 bytes.

:::
<!-- {figure} 4/alineamiento_struct.svg -->

El problema con esto es que en algunos casos (como en protocolos de red o
controladores de hardware) necesitamos un control exacto de los bits y de la
disposición exacta en memoria de cada byte de la estructura.

##### El "operador" `offsetof`

`offsetof` es una macro definida en el archivo de cabecera `<stddef.h>`. Su
propósito es calcular el **desplazamiento en bytes** de un miembro específico
dentro de una estructura (`struct`) o unión (`union`), desde el inicio de la
misma.

En otras palabras, te dice cuántos bytes hay entre el comienzo de la estructura
y el comienzo de uno de sus miembros.

###### ¿Para qué sirve?

Su principal utilidad reside en situaciones donde necesitas conocer la posición
exacta de un miembro dentro de una estructura sin tener una instancia de esa
estructura. Esto es común en programación de bajo nivel, {term}`serialización`
de datos y al trabajar con _buffers_ de memoria genéricos.

(sintaxis)=
#### Sintaxis

La sintaxis es la siguiente:

:::{code-block}c
:linenos:
size_t offsetof(type, member);
:::
<!-- {code-block}c -->

- `type`: Es el nombre del tipo de la estructura (ej. `struct MiEstructura`).
- `member`: Es el nombre del miembro de la estructura del cual querés saber el
  desplazamiento.

La macro devuelve un valor de tipo `size_t`, que es un tipo entero sin signo
capaz de representar el tamaño de cualquier objeto en memoria.

---

(ejemplo-practico)=
#### Ejemplo Práctico

Imagina que tienes la siguiente estructura:

:::{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>
struct Usuario
{
    int id;
    char inicial;
    double salario;
};
int main()
{
    size_t desplazamiento_id = offsetof(struct Usuario, id);
    size_t desplazamiento_inicial = offsetof(struct Usuario, inicial);
    size_t desplazamiento_salario = offsetof(struct Usuario, salario);
    printf("Desplazamiento de 'id': %zu bytes\n", desplazamiento_id);
    printf("Desplazamiento de 'inicial': %zu bytes\n", desplazamiento_inicial);
    printf("Desplazamiento de 'salario': %zu bytes\n", desplazamiento_salario);
    return 0;
}
:::
<!-- {code-block}c -->

(posible-salida)=
#### Posible Salida

La salida de este código podría ser:

```
Desplazamiento de 'id': 0 bytes
Desplazamiento de 'inicial': 4 bytes
Desplazamiento de 'salario': 8 bytes
```

**¿Qué nos dice esta salida?**

1.  **`id`**: Está al puro inicio de la estructura, por lo que su desplazamiento
    es **0**.
2.  **`inicial`**: Comienza en el byte 4. Esto se debe a que el `int` (`id`)
    ocupa 4 bytes, y el compilador puede añadir _relleno_ (padding) para alinear
    los datos en memoria y optimizar el acceso.
3.  **`salario`**: Empieza en el byte 8. Después del `char` (`inicial`), que
    ocupa 1 byte, el compilador ha añadido 3 bytes de relleno antes de `salario`
    para que este `double` (que suele ocupar 8 bytes) comience en una dirección
    de memoria múltiplo de 8, lo cual es más eficiente para el procesador.

---

(casos-de-uso-comunes)=
#### Casos de Uso Comunes

1.  **Cálculos de Punteros**: Es fundamental en la "aritmética de punteros"
    avanzada. Por ejemplo, si tienes un puntero a un miembro de una estructura y
    quieres obtener un puntero a la estructura contenedora completa. Una macro
    común para esto es `container_of` en el kernel de Linux, que depende
    internamente de `offsetof`.

2.  **Serialización/Deserialización**: Cuando necesitas guardar una estructura
    en un archivo o enviarla a través de una red, a menudo se convierte a un
    arreglo de bytes. `offsetof` ayuda a saber dónde empieza cada campo en ese
    _buffer_ de bytes.

3.  **Interfaces con otros lenguajes**: Al interactuar con código ensamblador u
    otros lenguajes de bajo nivel, a veces necesitas pasar la ubicación exacta
    de los campos de una estructura.

En resumen, **`offsetof`** es una herramienta poderosa y necesaria en la
programación de sistemas en C para manipular la memoria a un nivel muy preciso,
permitiendo interactuar directamente con la disposición de los datos en las
estructuras.

---

##### Laboratorio 1: Inspección de Layout

Vamos a analizar el layout de una estructura para visualizar el padding.

**`layout_inspect.c`**

:::{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>
typedef struct
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
} ejemplo_padding_t;
int main(void)
{
    printf("sizeof(char) = %zu, sizeof(int) = %zu\n", sizeof(char),
           sizeof(int));
    printf("sizeof(ejemplo_padding_t) = %zu\n\n", sizeof(ejemplo_padding_t));
    printf("offsetof(a) = %zu\n", offsetof(ejemplo_padding_t, a));
    printf("offsetof(b) = %zu\n", offsetof(ejemplo_padding_t, b));
    printf("offsetof(c) = %zu\n", offsetof(ejemplo_padding_t, c));
}
:::
<!-- {code-block}c -->

**Compilación y Ejecución:**

``` bash
gcc -Wextra -Wall -g layout_inspect.c -o layout_inspect
./layout_inspect
```
<!-- bash -->

**Salida Esperada:**

```
sizeof(char) = 1, sizeof(int) = 4
sizeof(ejemplo_padding_t) = 12

offsetof(a) = 0
offsetof(b) = 4
offsetof(c) = 8
```

**Análisis:**

- El tamaño total es 12 bytes, no 6 (1+4+1).
- `b` está en el offset 4, no 1. El compilador insertó 3 bytes de padding
  después de `a`.
- `c` está en el offset 8.
- Se añaden 3 bytes de padding al final para que el tamaño total (12) sea
  múltiplo del miembro más grande (4), asegurando la alineación en arreglos.

:::{exercise}
:label: ejer-layout-1
**Optimización de Padding**

Reordená los miembros de `ejemplo_padding_t` para minimizar su tamaño total.
Verificá tu resultado con `sizeof`. ¿Cuál es el orden óptimo y por qué?

:::
<!-- {exercise} -->

::::{solution} ejer-layout-1
:class: dropdown
El orden óptimo es ordenar los miembros de mayor a menor tamaño: `int b; char a;
char c;`.

:::{code-block}c
:linenos:
typedef struct
{
    int b;  // 4 bytes
    char a; // 1 byte
    char c; // 1 byte
    // 2 bytes de padding al final para alinear la estructura completa
} ejemplo_optimizado_t;
// sizeof será 8
:::
<!-- {code-block}c -->
Aunque el orden `char a; char c; int b;` también reduce el tamaño a 8 bytes, la
regla generalizable y recomendada para estructuras con múltiples tipos complejos
es ordenar los miembros siempre **de mayor a menor tamaño**. Esto minimiza el
padding de alineación de forma consistente sin importar la cantidad o el tipo de
los datos adicionales, como se detalla en la Regla de Oro.

::::
<!-- {solution} ejer-layout-1 -->

---








---

(documentacion-de-estructuras)=
#### Documentación de Estructuras

La documentación clara y detallada de las estructuras es fundamental para
mantener código comprensible y mantenible. Una buena documentación explica no
solo qué es cada campo, sino también su propósito, restricciones y relaciones
con otros miembros. Existen dos enfoques principales para documentar
estructuras, cada uno con sus ventajas según el contexto.

##### Enfoque 1: Bloque de Documentación Único

Este enfoque utiliza un único bloque de comentario antes de la definición de la
estructura para describir su propósito general y documentar todos sus miembros.
Es ideal para estructuras simples o cuando los miembros requieren explicaciones
breves.

:::{code-block}c
:linenos:
/**
 * Representa un punto en el espacio tridimensional.
 *
 * Esta estructura almacena las coordenadas cartesianas (x, y, z)
 * de un punto en el espacio 3D. Todas las coordenadas se expresan
 * en unidades del sistema internacional (metros).
 *
 * Miembros:
 *   - x: Coordenada en el eje X (horizontal)
 *   - y: Coordenada en el eje Y (profundidad)
 *   - z: Coordenada en el eje Z (altura)
 */
typedef struct
{
    double x;
    double y;
    double z;
} punto_3d_t;
:::
<!-- {code-block}c -->

**Ventajas:**
- Proporciona una visión general cohesiva de la estructura.
- Facilita la explicación de relaciones entre miembros.
- Mantiene la definición de la estructura visualmente limpia.

**Desventajas:**
- Puede volverse difícil de mantener si la estructura crece.
- La separación entre documentación y código puede dificultar actualizaciones.

##### Enfoque 2: Documentación Distribuida

Este enfoque combina un bloque de comentario que describe el propósito general
de la estructura con comentarios de línea individuales para cada miembro. Es
preferible para estructuras complejas con muchos campos o cuando cada miembro
requiere explicación detallada.

:::{code-block}c
:linenos:
/**
 * Representa la configuración de una conexión de red.
 *
 * Esta estructura almacena todos los parámetros necesarios para
 * establecer y mantener una conexión de red TCP/IP. Los valores
 * deben ser inicializados antes de llamar a conectar_red().
 */
typedef struct
{
    char direccion_ip[16];   // Dirección IP en formato "xxx.xxx.xxx.xxx"
    unsigned short puerto;   // Puerto de destino (1-65535)
    int timeout_ms;          // Tiempo de espera en milisegundos para la
    conexión bool usar_tls;  // true si se requiere conexión segura (TLS/SSL)
    unsigned int reintentos; // Número máximo de intentos de reconexión
    void *contexto_usuario;  // Puntero opaco para datos del usuario (puede
    ser NULL)
} configuracion_red_t;
:::
<!-- {code-block}c -->

**Ventajas:**
- Cada campo tiene su documentación adyacente, facilitando actualizaciones.
- La estructura es autodocumentada al leerla linealmente.
- Ideal para estructuras con campos que requieren explicaciones específicas.

**Desventajas:**
- Puede hacer la definición visualmente más extensa.
- Las relaciones entre campos pueden ser menos evidentes.

(ejemplo-completo-estructura-compleja)=
#### Ejemplo Completo: Estructura Compleja

Para estructuras complejas que involucran múltiples conceptos, el enfoque
distribuido suele ser más efectivo:

:::{code-block}c
:linenos:
/**
 * Representa el estado completo de una transacción bancaria.
 *
 * Esta estructura almacena toda la información necesaria para
 * procesar, validar y auditar una transacción financiera.
 * Todos los montos están expresados en la menor unidad de la
 * moneda (centavos para ARS, USD, etc.).
 *
 * Invariantes:
 *   - monto debe ser > 0
 *   - numero_cuenta_origen y numero_cuenta_destino deben ser distintos
 *   - timestamp debe ser válido (verificar con validar_timestamp())
 */
typedef struct
{
    char id_transaccion[37]; // UUID único de la transacción (formato RFC
    4122)
    long long monto;                // Monto en la menor unidad de la moneda
    char numero_cuenta_origen[21];  // Número de cuenta origen (máx. 20 dígitos
    + '\0')
    char numero_cuenta_destino[21]; // Número de cuenta destino (máx. 20 dígitos
    + '\0')
    time_t timestamp;               // Momento exacto de la transacción (UNIX
    epoch)
    enum tipo_transaccion tipo;     // Tipo: TRANSFERENCIA, DEPOSITO, RETIRO,
    etc.char descripcion[256];      // Descripción proporcionada por el usuario
    bool procesada;                 // true si la transacción ya fue procesada
    int codigo_resultado;           // 0 = éxito, != 0 = código de error
    específico char firma_digital[65]; // Hash SHA-256 de la transacción (64
    caracteres hex + '\0')
} transaccion_bancaria_t;
:::
<!-- {code-block}c -->

(recomendaciones-generales)=
#### Recomendaciones Generales

1. **Consistencia:** Elegí un enfoque y mantenélo en todo el proyecto. Si usás
   el enfoque distribuido, todos los miembros deben tener comentarios.

2. **Información Útil:** Documentá restricciones, rangos válidos, unidades de
   medida y valores especiales (como NULL para punteros opcionales).

3. **Invariantes:** Si la estructura tiene invariantes o precondiciones,
   documentalas claramente en el bloque general.

4. **Actualizaciones:** Cuando modifiques la estructura, actualizá la
   documentación inmediatamente. La documentación desactualizada es peor que la
   falta de documentación.

5. **Relaciones:** Si los campos tienen dependencias entre sí, explicá estas
   relaciones claramente.

Para más detalles sobre el estilo de comentarios y documentación, consultá la
regla {ref}`0x0201h` sobre cómo escribir comentarios que expliquen el
"porqué" y no el "qué".

---

(consideraciones-de-uso-y-diseno-new)=
#### Consideraciones de Uso y Diseño \[new\]

El diseño de estructuras va más allá de simplemente agrupar datos relacionados.
Las decisiones sobre cómo organizar los miembros impactan directamente en la
claridad del código, el rendimiento, la mantenibilidad y la corrección del
programa. Esta sección explora principios y patrones de diseño fundamentales
para crear estructuras efectivas.

:::{warning} ¿Entra en el parcial?

Este tema salió de una pregunta de discussions y aunque es importante ver por
que y los efectos que tiene
_no entra_ en el parcial.

Lo que sí entra, es el hecho de utilizar, _la sintaxis intuitiva_ {ref}`AoS`, en
lugar de {ref}`SoA`.

:::
<!-- {warning} ¿Entra en el parcial? -->

##### Arreglo de Estructuras vs Estructura de Arreglos

Una de las decisiones más importantes al diseñar estructuras es elegir entre
**arreglo de estructuras (AoS)** o **estructura de arreglos (SoA)**. Ambos
enfoques tienen trade-offs significativos en términos de claridad, rendimiento y
facilidad de uso.

:::{figure} 7/aos_vs_soa.svg
:name: fig-aos-vs-soa
:align: center
:width: 100%

Comparación visual entre AoS y SoA mostrando cómo se organizan los datos en
memoria y el impacto en el uso de caché.

:::
<!-- {figure} 4/aos_vs_soa.svg -->
(AoS)=
###### Arreglo de Estructuras (Array of Structures - AoS)

En este enfoque, cada elemento del arreglo es una estructura completa que
contiene todos los atributos de una entidad.

:::{code-block}c
:linenos:
typedef struct
{
    double x;
    double y;
    double z;
    double masa;
    double velocidad_x;
    double velocidad_y;
    double velocidad_z;
} particula_t;
// Arreglo de 1000 partículas
particula_t particulas[1000];
:::
<!-- {code-block}c -->

**Ventajas:**
- **Claridad conceptual:** Cada elemento del arreglo representa una entidad
  completa e independiente.
- **Facilidad de uso:** Acceder a todos los atributos de una partícula es
  intuitivo: `particulas[i].x`, `particulas[i].y`, etc.
- **Gestión de memoria simple:** Una sola asignación para todo el arreglo.
- **Localidad espacial por entidad:** Todos los datos de una entidad están
  contiguos en memoria.
- **Ideal para operaciones por entidad:** Si procesás cada entidad
  individualmente con todos sus atributos.

**Desventajas:**
- **Caché poco eficiente en operaciones vectoriales:** Si solo necesitás un
  atributo (ej: solo las posiciones `x`), el procesador carga en caché datos
  innecesarios (masa, velocidades, etc.).
- **Penalización en SIMD:** Las instrucciones vectoriales modernas (SSE, AVX)
  prefieren datos contiguos del mismo tipo.

**Ejemplo de Uso:**

:::{code-block}c
:linenos:
void actualizar_posiciones_aos(particula_t particulas[], size_t n, double dt)
{
    for (size_t i = 0; i < n; i++)
    {
        // Acceso intuitivo, todos los datos de una partícula juntos
        particulas[i].x += particulas[i].velocidad_x * dt;
        particulas[i].y += particulas[i].velocidad_y * dt;
        particulas[i].z += particulas[i].velocidad_z * dt;
    }
}
:::
<!-- {code-block}c -->
(SoA)=
###### Estructura de Arreglos (Structure of Arrays - SoA)

En este enfoque, cada atributo se almacena en su propio arreglo, y la estructura
contiene estos arreglos.

:::{code-block}c
:linenos:
typedef struct
{
    double *x;
    double *y;
    double *z;
    double *masa;
    double *velocidad_x;
    double *velocidad_y;
    double *velocidad_z;
    size_t cantidad;
    size_t capacidad;
} sistema_particulas_t;
:::
<!-- {code-block}c -->

**Ventajas:**
- **Eficiencia de caché:** Al procesar un solo atributo (ej: todas las
  posiciones `x`), accedés a memoria contigua sin datos irrelevantes.
- **Optimización SIMD:** Procesadores modernos pueden aplicar la misma operación
  a múltiples elementos simultáneamente.
- **Menos desperdicio de ancho de banda:** Solo cargás los datos que realmente
  necesitás.

**Desventajas:**
- **Complejidad de gestión:** Múltiples asignaciones de memoria, más propenso a
  errores.
- **Sintaxis menos intuitiva:** `sistema.x[i]` vs `particulas[i].x`.
- **Consistencia manual:** Debés garantizar que todos los arreglos tengan el
  mismo tamaño.
- **Mayor overhead en operaciones por entidad:** Si necesitás todos los
  atributos de una entidad, accedés a múltiples arreglos.

**Ejemplo de Uso:**

:::{code-block}c
:linenos:
void actualizar_posiciones_soa(sistema_particulas_t *sistema, double dt)
{
    // Acceso optimizado para procesamiento vectorial
    for (size_t i = 0; i < sistema->cantidad; i++)
    {
        sistema->x[i] += sistema->velocidad_x[i] * dt;
        sistema->y[i] += sistema->velocidad_y[i] * dt;
        sistema->z[i] += sistema->velocidad_z[i] * dt;
    }
}
:::
<!-- {code-block}c -->

Este código es más fácil de vectorizar automáticamente por el compilador, ya que
cada lazo procesa un arreglo contiguo de un solo tipo.

###### Implementación Completa: Gestión de Memoria en SoA

:::{code-block}c
:linenos:
sistema_particulas_t *crear_sistema(size_t capacidad_inicial)
{
    sistema_particulas_t *sistema = NULL;
    sistema = malloc(sizeof(sistema_particulas_t));
    if (sistema == NULL)
    {
        return NULL;
    }
    // Asignación de cada arreglo individual
    sistema->x = malloc(capacidad_inicial * sizeof(double));
    sistema->y = malloc(capacidad_inicial * sizeof(double));
    sistema->z = malloc(capacidad_inicial * sizeof(double));
    sistema->masa = malloc(capacidad_inicial * sizeof(double));
    sistema->velocidad_x = malloc(capacidad_inicial * sizeof(double));
    sistema->velocidad_y = malloc(capacidad_inicial * sizeof(double));
    sistema->velocidad_z = malloc(capacidad_inicial * sizeof(double));
    // Verificación exhaustiva
    if (sistema->x == NULL || sistema->y == NULL || sistema->z == NULL ||
        sistema->masa == NULL || sistema->velocidad_x == NULL ||
        sistema->velocidad_y == NULL || sistema->velocidad_z == NULL)
    {
        // Liberar todo lo asignado antes del error
        free(sistema->x);
        free(sistema->y);
        free(sistema->z);
        free(sistema->masa);
        free(sistema->velocidad_x);
        free(sistema->velocidad_y);
        free(sistema->velocidad_z);
        free(sistema);
        return NULL;
    }
    sistema->cantidad = 0;
    sistema->capacidad = capacidad_inicial;
    return sistema;
}
void destruir_sistema(sistema_particulas_t *sistema)
{
    if (sistema == NULL)
    {
        return;
    }
    // Liberar cada arreglo
    free(sistema->x);
    free(sistema->y);
    free(sistema->z);
    free(sistema->masa);
    free(sistema->velocidad_x);
    free(sistema->velocidad_y);
    free(sistema->velocidad_z);
    // Finalmente la estructura principal
    free(sistema);
}
:::
<!-- {code-block}c -->

:::{important} Gestión de Errores en SoA

Notá cómo la función `crear_sistema` debe verificar **todas** las asignaciones
y, en caso de error, liberar **todas** las asignaciones previas antes de
retornar. Esto añade complejidad pero es esencial para evitar fugas de memoria.

:::
<!-- {important} Gestión de Errores en SoA -->

###### ¿Cuándo Usar Cada Enfoque?

**Usá Arreglo de Estructuras (AoS) cuando:**
- La claridad y simplicidad del código es prioritaria
- Procesás entidades completas de forma individual
- Las estructuras no son extremadamente grandes
- No hay cuellos de botella de rendimiento identificados
- El código es más legible y mantenible para tu equipo

**Usá Estructura de Arreglos (SoA) cuando:**
- El rendimiento es crítico y hay análisis de perfilado que lo justifica
- Procesás frecuentemente un solo atributo de muchas entidades
- Trabajás con procesamiento masivo de datos (física, gráficos, simulaciones)
- Querés aprovechar instrucciones SIMD del procesador
- El dominio del problema es naturalmente "columnar"

:::{tip} Principio de Diseño

Empezá con AoS (arreglo de estructuras) por defecto. Es más simple, más claro y
menos propenso a errores. Solo considerá SoA (estructura de arreglos) si el
perfilado muestra que el acceso a memoria es un cuello de botella y el patrón de
acceso lo justifica.

La optimización prematura es la raíz de todo mal. Priorizá código claro y
correcto primero, optimizá después si es necesario.

:::
<!-- {tip} Principio de Diseño -->

###### Ejemplo Comparativo: Búsqueda de Máximo

**AoS:**
:::{code-block}c
:linenos:
// Encontrar la partícula con mayor masa
particula_t *encontrar_mas_masiva_aos(particula_t particulas[], size_t n)
{
    if (n == 0)
    {
        return NULL;
    }
    particula_t *mas_masiva = &particulas[0];
    for (size_t i = 1; i < n; i++)
    {
        if (particulas[i].masa > mas_masiva->masa)
        {
            mas_masiva = &particulas[i];
        }
    }
    return mas_masiva;
}
:::
<!-- {code-block}c -->

**SoA:**
:::{code-block}c
:linenos:
// Encontrar el índice de la partícula con mayor masa
size_t encontrar_mas_masiva_soa(const sistema_particulas_t *sistema)
{
    if (sistema->cantidad == 0)
    {
        return SIZE_MAX; // Indicador de error
    }
    size_t indice_max = 0;
    double masa_max = sistema->masa[0];
    // Acceso contiguo a memoria, ideal para vectorización
    for (size_t i = 1; i < sistema->cantidad; i++)
    {
        if (sistema->masa[i] > masa_max)
        {
            masa_max = sistema->masa[i];
            indice_max = i;
        }
    }
    return indice_max;
}
:::
<!-- {code-block}c -->

En el caso de SoA, el lazo accede únicamente al arreglo `masa`, lo cual es
óptimo para el caché. Sin embargo, notá que la función retorna un índice, no un
puntero, lo que puede ser menos conveniente para el usuario.

##### Encapsulación de Invariantes

Las estructuras deben diseñarse de modo que sea imposible o difícil crear
instancias inválidas. Esto se logra mediante:

1. **Constructores:** Funciones que inicializan correctamente la estructura.
2. **Validadores:** Funciones que verifican invariantes.
3. **Punteros opacos:** Ocultar la implementación interna.

:::{code-block}c
:linenos:
/**
 * Representa un rectángulo con lados paralelos a los ejes.
 *
 * Invariantes:
 *   - ancho debe ser > 0
 *   - alto debe ser > 0
 */
typedef struct
{
    double x;     // Coordenada X de la esquina inferior izquierda
    double y;     // Coordenada Y de la esquina inferior izquierda
    double ancho; // Ancho del rectángulo (debe ser > 0)
    double alto;  // Alto del rectángulo (debe ser > 0)
} rectangulo_t;
// Constructor que garantiza invariantes
rectangulo_t crear_rectangulo(double x, double y, double ancho, double alto)
{
    rectangulo_t rect = {0};
    // Validación de precondiciones
    if (ancho <= 0.0 || alto <= 0.0)
    {
        fprintf(stderr, "Error: dimensiones de rectángulo deben ser
        positivas\n");
        rect.ancho = 1.0;  // Valores seguros por defecto
        rect.alto = 1.0;
    }
    else
    {
        rect.x = x;
        rect.y = y;
        rect.ancho = ancho;
        rect.alto = alto;
    }
    return rect;
}
bool es_rectangulo_valido(const rectangulo_t *rect)
{
    return rect != NULL && rect->ancho > 0.0 && rect->alto > 0.0;
}
:::
<!-- {code-block}c -->

:::{note} Defensa contra Uso Incorrecto

Al proporcionar un constructor, reducís la probabilidad de que los usuarios
creen rectángulos con dimensiones inválidas. Sin embargo, C no puede forzar el
uso del constructor, por lo que la documentación clara es esencial.

:::
<!-- {note} Defensa contra Uso Incorrecto -->

##### Minimización de Padding

Ordenar los miembros de mayor a menor tamaño reduce el padding y el tamaño total
de la estructura:

:::{figure} 7/padding_optimization.svg
:name: fig-padding-optimization
:align: center
:width: 90%

Optimización de estructuras ordenando miembros por tamaño. El diseño subóptimo
desperdicia 50% del espacio, mientras que el optimizado solo 25%.

:::
<!-- {figure} 4/padding_optimization.svg -->

:::{code-block}c
:linenos:
// Diseño subóptimo (12 bytes en x86-64) - Equivalente a ejemplo_padding_t del
Laboratorio 1
    // (Ver offsetof y padding detallados en el Laboratorio 1)
    // Diseño optimizado (8 bytes en x86-64) - Aplicando la regla de
    // ordenamiento
    mayor a menor typedef struct
{
    int b;  // 4 bytes
    char a; // 1 byte
    char c; // 1 byte (2 bytes de padding después)
} optimizada_t;
:::
<!-- {code-block}c -->

:::{tip} Regla de Oro: Mayor a Menor

Ordená los miembros de la estructura de mayor a menor tamaño. Los tipos más
grandes primero (`double`, `long`), luego intermedios (`int`, `float`), y
finalmente los más pequeños (`char`, `bool`). Esto minimiza el padding
automático insertado por el compilador.

:::
<!-- {tip} Regla de Oro: Mayor a Menor -->

##### Uso de Estructuras Anidadas

Las estructuras anidadas permiten organizar conceptos complejos de forma
jerárquica:

:::{code-block}c
:linenos:
typedef struct
{
    double x;
    double y;
} punto_2d_t;
typedef struct
{
    punto_2d_t posicion;
    punto_2d_t velocidad;
    double masa;
    double radio;
} cuerpo_2d_t;
// Uso
cuerpo_2d_t planeta = {.posicion = {.x = 0.0, .y = 0.0},
                       .velocidad = {.x = 10.0, .y = 5.0},
                       .masa = 5.97e24,
                       .radio = 6.371e6};
// Acceso
double distancia_al_origen = sqrt(planeta.posicion.x * planeta.posicion.x +
                                  planeta.posicion.y * planeta.posicion.y);
:::
<!-- {code-block}c -->

**Ventajas:**
- Reutilización de tipos comunes (`punto_2d_t` usado para posición y velocidad)
- Organización lógica clara
- Facilita la creación de funciones genéricas (ej: `calcular_distancia` que
  opera sobre `punto_2d_t`)

##### Punteros a Funciones como Miembros

Para comportamiento polimórfico en estructuras:

:::{code-block}c
:linenos:
typedef struct figura figura_t;
typedef double (*calcular_area_fn)(const figura_t *);
typedef void (*dibujar_fn)(const figura_t *);
struct figura
{
    calcular_area_fn calcular_area;
    dibujar_fn dibujar;
    void *datos; // Puntero opaco a datos específicos de cada tipo de figura
};
// Implementación para círculo
double calcular_area_circulo(const figura_t *f)
{
    double *radio = f->datos;
    return 3.14159 * (*radio) * (*radio);
}
void dibujar_circulo(const figura_t *f)
{
    printf("Dibujando un círculo...\n");
}
// Creación de una figura específica
figura_t crear_figura_circulo(double radio)
{
    double *radio_heap = malloc(sizeof(double));
    if (radio_heap == NULL)
    {
        perror("Error al asignar memoria para la figura círculo");
        figura_t fig_nula = {
            .calcular_area = NULL, .dibujar = NULL, .datos = NULL};
        return fig_nula;
    }
    *radio_heap = radio;
    figura_t fig = {.calcular_area = calcular_area_circulo,
                    .dibujar = dibujar_circulo,
                    .datos = radio_heap};
    return fig;
}
:::
<!-- {code-block}c -->

Este patrón permite un estilo de programación orientada a objetos rudimentario
en C, donde diferentes "tipos" de figuras comparten la misma interfaz pero
tienen comportamientos distintos.

:::{warning} Gestión de Memoria con Punteros Opacos

Cuando usás `void *datos` para almacenar información específica del tipo, debés
documentar claramente quién es responsable de liberar esa memoria y proporcionar
funciones destructoras adecuadas.

:::
<!-- {warning} Gestión de Memoria con Punteros Opacos -->

##### Estructuras Auto-descriptivas

Incluir metadatos en la estructura facilita la depuración y la serialización:

:::{code-block}c
:linenos:
typedef enum
{
    TIPO_ENTERO,
    TIPO_FLOTANTE,
    TIPO_CADENA
} tipo_dato_t;
typedef struct
{
    tipo_dato_t tipo;
    union
    {
        int entero;
        double flotante;
        char *cadena;
    } valor;
} dato_generico_t;
void imprimir_dato(const dato_generico_t *dato)
{
    switch (dato->tipo)
    {
    case TIPO_ENTERO:
        printf("Entero: %d\n", dato->valor.entero);
        break;
    case TIPO_FLOTANTE:
        printf("Flotante: %.2f\n", dato->valor.flotante);
        break;
    case TIPO_CADENA:
        printf("Cadena: %s\n", dato->valor.cadena);
        break;
    }
}
:::
<!-- {code-block}c -->

Este patrón (estructura con un `enum` que indica el tipo y un `union` que
contiene los datos) se llama **tagged union** y es fundamental para representar
datos heterogéneos de forma segura.

---








---

(uniones-union-un-espacio-para-multiples-propositos)=
### Uniones (`union`): Un Espacio para Múltiples Propósitos

Una `union` permite que varios miembros compartan la **misma ubicación de
memoria**. Su tamaño es el de su miembro más grande. Solo un miembro puede estar
"activo" a la vez.

:::{figure} 7/union_vs_struct.svg
:name: fig-union-vs-struct
:alt: Diferencias entre struct y union
:align: center

Comparación visual entre estructuras (todos los miembros en memoria separada) y
uniones (todos comparten el mismo espacio de memoria).

:::
<!-- {figure} 4/union_vs_struct.svg -->

##### El Patrón de Unión Etiquetada (Tagged Union)

Por sí mismas, las `union` tienen usos muy limitados ya que no es posible saber
como tenemos que interpretar la información contenida, para esto, se utiliza una
**unión etiquetada**: una `struct` que contiene un `enum` (la etiqueta) y una
`union` (el valor).

**`tagged_union.c`**

:::{code-block}c
:linenos:
#include <stdio.h>
typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_TEXTO
} tipo_dato_t;
typedef struct
{
    tipo_dato_t tipo;
    union
    {
        int i;
        float f;
        const char *s;
    } valor;
} variante_t;
void imprimir_variante(const variante_t *v)
{
    switch (v->tipo)
    {
    case TIPO_INT:
        printf("Entero: %d\n", v->valor.i);
        break;
    case TIPO_FLOAT:
        printf("Flotante: %.2f\n", v->valor.f);
        break;
    case TIPO_TEXTO:
        printf("Texto: \"%s\"\n", v->valor.s);
        break;
    }
}
int main()
{
    variante_t v1 = {.tipo = TIPO_INT, .valor.i = 100};
    variante_t v2 = {.tipo = TIPO_FLOAT, .valor.f = 3.14f};
    variante_t v3 = {.tipo = TIPO_TEXTO, .valor.s = "Hola"};
    imprimir_variante(&v1);
    imprimir_variante(&v2);
    imprimir_variante(&v3);
    return 0;
}
:::
<!-- {code-block}c -->

Este patrón es la base para implementar tipos de datos polimórficos en C.

---

(documentacion-de-uniones)=
#### Documentación de Uniones

Las uniones (`union`) requieren documentación particularmente cuidadosa debido a
que múltiples miembros comparten la misma ubicación de memoria. Es fundamental
documentar cuándo y cómo debe accederse a cada miembro para evitar
comportamiento indefinido.

##### Enfoque 1: Bloque de Documentación Único

Para uniones simples, un único bloque de comentario puede ser suficiente si se
explica claramente el propósito y las restricciones de uso.

:::{code-block}c
:linenos:
/**
 * Permite interpretar un valor de 32 bits de múltiples formas.
 *
 * Esta unión facilita la conversión entre representaciones enteras
 * y de punto flotante de 32 bits sin necesidad de casting explícito.
 *
 * ADVERTENCIA: Solo el último miembro asignado contiene un valor
 * válido. Leer un miembro distinto al último escrito resulta en
 * comportamiento indefinido según el estándar C.
 *
 * Miembros:
 *   - como_int: Interpreta los 32 bits como entero con signo
 *   - como_uint: Interpreta los 32 bits como entero sin signo
 *   - como_float: Interpreta los 32 bits como número de punto flotante
 *   - como_bytes: Acceso a los 4 bytes individuales
 */
typedef union
{
    int32_t como_int;
    uint32_t como_uint;
    float como_float;
    uint8_t como_bytes[4];
} valor_32bits_t;
:::
<!-- {code-block}c -->

**Ventajas:**
- Proporciona una visión completa del propósito de la unión.
- Facilita explicar las restricciones de uso compartido de memoria.
- Mantiene la definición visualmente limpia.

**Desventajas:**
- Puede ser difícil de mantener si la unión crece.
- La separación entre documentación y miembros puede causar desincronización.

##### Enfoque 2: Documentación Distribuida

Para uniones más complejas o uniones etiquetadas, el enfoque distribuido es
preferible, especialmente cuando cada miembro tiene propósitos o restricciones
específicas.

:::{code-block}c
:linenos:
/**
 * Representa los datos específicos de diferentes tipos de mensajes de red.
 *
 * Esta unión debe usarse ÚNICAMENTE dentro de una estructura que incluya
 * un campo tipo (enum tipo_mensaje_t) para identificar qué miembro es válido.
 *
 * IMPORTANTE: El tamaño de esta unión es el del miembro más grande
 * (mensaje_archivo). Considerá las implicaciones de memoria al usarla
 * en arreglos o estructuras embebidas.
 */
typedef union
{
    struct
    {                        // Válido cuando tipo == MSG_TEXTO
        char contenido[256]; // Mensaje de texto (máx. 255 chars + '\0')
        size_t longitud;     // Longitud real del mensaje
    } mensaje_texto;
    struct
    {                    // Válido cuando tipo == MSG_NUMERO
        int64_t valor;   // Valor numérico a transmitir
        bool es_firmado; // true si el valor es con signo
    } mensaje_numero;
    struct
    {                      // Válido cuando tipo == MSG_ARCHIVO
        char nombre[128];  // Nombre del archivo
        size_t tamano;     // Tamaño en bytes
        uint32_t checksum; // Checksum CRC32 para verificación
        void *datos;       // Puntero a los datos del archivo
    } mensaje_archivo;
} datos_mensaje_t;
:::
<!-- {code-block}c -->

**Ventajas:**
- Cada miembro tiene su documentación adyacente.
- Facilita documentar estructuras anidadas dentro de la unión.
- Ideal para uniones etiquetadas con miembros complejos.

**Desventajas:**
- La definición puede volverse visualmente extensa.
- Requiere disciplina para documentar todos los miembros consistentemente.

##### Documentación de Uniones para Manipulación de Bits

Para uniones usadas en programación de bajo nivel, la documentación debe ser
especialmente detallada:

:::{code-block}c
:linenos:
/**
 * Permite manipular y acceder a un valor de 64 bits en diferentes
   granularidades.
 *
 * Esta unión es útil para operaciones de bajo nivel que requieren acceso
 * tanto al valor completo como a sus partes individuales (mitades, bytes,
   bits).
 *
 * NOTA DE PORTABILIDAD: El orden de los bytes (endianness) afecta cómo se
 * interpretan los campos byte[]. En sistemas little-endian, byte[0] es el
 * byte menos significativo. En big-endian, es el más significativo.
 *
 * Uso típico: Conversión de protocolos de red, serialización, depuración.
 */
typedef union
{
    uint64_t completo; // Acceso al valor completo de 64 bits
    struct
    {                  // Acceso a mitades de 32 bits
        uint32_t bajo; // 32 bits inferiores
        uint32_t alto; // 32 bits superiores
    } mitades;
    uint16_t palabras[4]; // Acceso como 4 palabras de 16 bits
    uint8_t bytes[8];     // Acceso individual a los 8 bytes
} registro_64bits_t;
:::
<!-- {code-block}c -->

(ejemplo-completo-union-etiquetada-con-documentacion-exhaustiva)=
#### Ejemplo Completo: Unión Etiquetada con Documentación Exhaustiva

Para uniones etiquetadas (el patrón más común y seguro), la documentación debe
cubrir tanto la unión como la estructura contenedora:

:::{code-block}c
:linenos:
/**
 * Tipo de dato polimórfico que puede contener diferentes tipos de valores.
 *
 * Este tipo implementa el patrón de unión etiquetada (tagged union),
 * permitiendo almacenar y operar con diferentes tipos de datos de forma
 * segura. El campo 'tipo' SIEMPRE indica qué miembro de la unión 'datos'
 * contiene información válida.
 *
 * Uso correcto:
 *   valor_t v = {.tipo = TIPO_ENTERO, .datos.entero = 42};
 *   if (v.tipo == TIPO_ENTERO) {
 *       printf("%d\n", v.datos.entero);  // ¡Seguro!
 *   }
 *
 * Uso INCORRECTO:
 *   valor_t v = {.tipo = TIPO_ENTERO, .datos.entero = 42};
 *   printf("%f\n", v.datos.flotante);  // ¡Comportamiento indefinido!
 *
 * INVARIANTE: El campo 'tipo' debe ser siempre consistente con el
 * miembro de 'datos' que contiene información válida.
 */
typedef struct
{
    /**
     * Identifica qué tipo de dato está almacenado actualmente.
     * Este campo DEBE actualizarse cada vez que se modifica 'datos'.
     */
    enum {
        TIPO_VACIO,      // Ningún valor almacenado (estado inicial)
        TIPO_ENTERO,     // datos.entero es válido
        TIPO_FLOTANTE,   // datos.flotante es válido
        TIPO_CADENA,     // datos.cadena es válido (debe liberarse si se asignó
        dinámicamente)
        TIPO_PUNTERO     // datos.puntero es válido
    } tipo;
    /**
     * Almacenamiento para el valor actual.
     * Solo el miembro correspondiente a 'tipo' contiene datos válidos.
     */
    union
    {
        int64_t entero;  // Entero de 64 bits con signo
        double flotante; // Número de punto flotante de precisión doble
        char *cadena;    // Puntero a cadena (responsabilidad del usuario
        liberar)
        void *puntero;          // Puntero genérico para tipos personalizados
    } datos;
} valor_t;
/**
 * Crea un valor de tipo entero.
 *
 * @param entero Valor entero a almacenar
 * @return Nuevo valor_t inicializado con el entero proporcionado
 */
valor_t crear_valor_entero(int64_t entero)
{
    return (valor_t){.tipo = TIPO_ENTERO, .datos.entero = entero};
}
:::
<!-- {code-block}c -->

(recomendaciones-generales-para-uniones)=
#### Recomendaciones Generales para Uniones

1. **Advertencias de seguridad:** Siempre documentá que solo un miembro es
   válido a la vez y que leer el miembro incorrecto causa comportamiento
   indefinido.

2. **Uniones etiquetadas:** Si la unión se usa con una etiqueta (enum),
   documentá claramente la relación entre el valor de la etiqueta y el miembro
   válido.

3. **Tamaño en memoria:** Mencioná el tamaño de la unión (determinado por su
   miembro más grande) si esto tiene implicaciones para el uso.

4. **Consideraciones de portabilidad:** Si la unión depende de representaciones
   específicas (endianness, tamaño de tipos), documentá estas dependencias.

5. **Gestión de memoria:** Si algún miembro contiene punteros que deben
   liberarse, documentá claramente la responsabilidad de gestión de memoria.

6. **Casos de uso:** Explicá para qué situaciones está diseñada la unión y
   cuándo debería (o no) usarse.

Para más detalles sobre el estilo de comentarios, consultá la regla
{ref}`0x0201h` sobre cómo escribir comentarios que expliquen el "porqué" y
no el "qué".

(ejercicio)=
#### Ejercicio

:::{exercise}
:label: ejer-tagged-union-2
**Procesador de Eventos**

Diseñá una unión etiquetada `evento_t` para un sistema simple. Un evento puede
ser:
1.  `EVENTO_TECLA_PRESIONADA`: contiene el código de la tecla (`char`).
2.  `EVENTO_CLICK_MOUSE`: contiene las coordenadas `x` e `y` (`int`).
3.  `EVENTO_SALIR`: no contiene datos adicionales.

Escribí una función `void procesar_evento(const evento_t *evento)` que imprima
un mensaje descriptivo según el tipo de evento.

:::
<!-- {exercise} -->









---

(alineacion-de-miembros-y-relleno-en-estructuras-padding)=
### Alineación de Miembros y Relleno en Estructuras (Padding)

En el desarrollo de software en C estándar, la disposición de los datos en la
memoria física no siempre es contigua ni directa. Los procesadores modernos
acceden a la memoria física mediante **palabras de máquina** (típicamente de 32
o 64 bits, es decir, 4 u 8 bytes). Para optimizar el rendimiento de las
operaciones de lectura y escritura en el bus de datos, el hardware impone
restricciones de alineación.

La **alineación natural** establece que una variable de tamaño $T$ bytes debe
almacenarse en una dirección de memoria que sea múltiplo de $T$. Si un dato no
se encuentra alineado, el procesador requerirá múltiples accesos a memoria para
leer un único valor, degradando el rendimiento del sistema o, en ciertas
arquitecturas, provocando una excepción de hardware (*bus error*).

Para cumplir con estas restricciones sin intervención del programador, el
compilador introduce automáticamente bytes de relleno denominados **padding**
entre los miembros de una estructura.

(impacto-en-el-consumo-de-memoria-fisica)=
#### Impacto en el Consumo de Memoria Física

Considerá la estructura `ejemplo_padding_t` presentada y analizada en el
Laboratorio 1:

:::{code-block}c
:linenos:
typedef struct
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
} ejemplo_padding_t;
:::
<!-- {code-block}c -->

A primera vista, se podría calcular que el tamaño físico de esta estructura es
la suma de sus partes: $1 \text{ byte} + 4 \text{ bytes} + 1 \text{ byte} = 6
\text{ bytes}$. Sin embargo, al evaluar `sizeof(ejemplo_padding_t)`, el
resultado en una arquitectura de 32 o 64 bits es **12 bytes**, como se demostró
empíricamente en el Laboratorio 1.

El compilador reorganiza el espacio aplicando las siguientes reglas:

1. **Alineación de miembros**: Cada miembro debe alinearse a una dirección
   múltiplo de su propio tamaño. `tipo` se ubica en el desplazamiento (*offset*)
   0. `id` requiere un offset múltiplo de 4; por ende, se añaden 3 bytes de
   relleno (*padding*) en los desplazamientos 1, 2 y 3, ubicando a `id` en el
   offset 4 (ocupando los bytes 4, 5, 6 y 7). `estado` se coloca en el offset 8.
2. **Alineación de la estructura completa**: El tamaño total de la estructura
   debe ser un múltiplo de la alineación de su miembro más restrictivo (el que
   requiera la mayor alineación). En este caso, el miembro más restrictivo es
   `id` (4 bytes). La estructura finaliza en el byte 8 (después de ocupar 9
   bytes en total). Para redondear al siguiente múltiplo de 4, el compilador
   inserta 3 bytes de relleno al final de la estructura, totalizando 12 bytes.

:::{table} Disposición de memoria física para `sensor_desoptimizado_t` (12 bytes)
:label: tbl-padding-desoptimizado

| Offset | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| :--- | :---: | :---: | :---: | :---: |
| **0** | `tipo` (1B) | *Padding* | *Padding* | *Padding* |
| **4** | `id` (B0) | `id` (B1) | `id` (B2) | `id` (B3) |
| **8** | `estado` (1B) | *Padding* | *Padding* | *Padding* |

:::
<!-- {table} Disposición de memoria física para `sensor_desoptimizado_t` (12 bytes) -->

(estrategia-de-optimizacion-reordenamiento-por-tamano)=
#### Estrategia de Optimización: Reordenamiento por Tamaño

Para mitigar el desperdicio de memoria física (que en el ejemplo anterior
asciende al $50\%$), se debe declarar los miembros de la estructura en orden
descendente de tamaño (o de restricción de alineación). Esto permite que los
tipos de menor tamaño aprovechen los huecos naturales de alineación de los tipos
más grandes.

Reescribiendo la estructura anterior:

:::{code-block}c
:linenos:
typedef struct
{
    int id;      // 4 bytes (offset 0-3)
    char tipo;   // 1 byte  (offset 4)
    char estado; // 1 byte  (offset 5)
    // 2 bytes de padding al final para completar múltiplo de 4
} sensor_optimizado_t;
:::
<!-- {code-block}c -->

El tamaño físico de `sensor_optimizado_t` es de **8 bytes**. Se logró reducir el
consumo de memoria en un $33\%$ simplemente alterando el orden de declaración.

:::{table} Disposición de memoria física para `sensor_optimizado_t` (8 bytes)
:label: tbl-padding-optimizado

| Offset | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| :--- | :---: | :---: | :---: | :---: |
| **0** | `id` (B0) | `id` (B1) | `id` (B2) | `id` (B3) |
| **4** | `tipo` (1B) | `estado` (1B) | *Padding* | *Padding* |

:::
<!-- {table} Disposición de memoria física para `sensor_optimizado_t` (8 bytes) -->

:::{important} Impacto en el Desarrollo a Gran Escala

Si bien una diferencia de 4 bytes puede parecer insignificante en sistemas
modernos, este impacto se magnifica exponencialmente al trabajar con arreglos
dinámicos de estructuras o buffers de red que almacenan millones de registros,
afectando directamente la tasa de aciertos en la memoria caché del procesador.

:::
<!-- {important} Impacto en el Desarrollo a Gran Escala -->

(inspeccion-de-desplazamientos-con-offsetof)=
#### Inspección de Desplazamientos con `offsetof`

La biblioteca estándar `<stddef.h>` proporciona la macro `offsetof`, que permite
obtener el desplazamiento en bytes de un miembro respecto al inicio de la
estructura.

:::{code-block}c
:linenos:
#include <stddef.h>
#include <stdio.h>
typedef struct
{
    char tipo;
    int id;
    char estado;
} sensor_desoptimizado_t;
int main(void)
{
    printf("Tamaño total: %zu bytes\n", sizeof(sensor_desoptimizado_t));
    printf("Offset de tipo: %zu\n", offsetof(sensor_desoptimizado_t, tipo));
    printf("Offset de id: %zu\n", offsetof(sensor_desoptimizado_t, id));
    printf("Offset de estado: %zu\n",
           offsetof(sensor_desoptimizado_t, estado));
    return 0;
}
:::
<!-- {code-block}c -->

:::{tip} Estilo

Al declarar variables o tipos estructurados, recordá seguir la regla
{ref}`0x0101h` que exige identificadores descriptivos, y usá el sufijo `_t` para
los alias definidos con `typedef` de acuerdo a la buena práctica del proyecto.

:::
<!-- {tip} Estilo -->

---








---

(5_estructuras-textos-fundamentales)=
#### Textos Fundamentales

- {cite:t}`kernighan_c_2014`. Sección 2.3: Constants y Apéndice A8.4:
  Enumeration Constants.

- {cite:t}`king_c_2008`. Capítulo 16: Structures, Unions, and Enumerations.

- {cite:t}`gustedt_modern_2019`. Level 1, Takeaway 1.6.2: Enumerations.

(estructuras-y-uniones)=
#### Estructuras y Uniones

- {cite:t}`harbison_c_2002`. Capítulo 5: Types. Referencia exhaustiva de enums,
  structs y unions.

- {cite:t}`van_der_linden_expert_1994`. Capítulo 5: Thinking of Linking y
  Capítulo 6: Poetry in Motion.

(patrones-de-diseno-con-enums)=
#### Patrones de Diseño con Enums

- {cite:t}`hanson_c_1996`. Técnicas para crear interfaces limpias usando
  enumeraciones.

- {cite:t}`lakos_large_1996`. Capítulo 2: Ground Rules. Enumeraciones para
  legibilidad.

(bit-fields-y-optimizacion)=
#### Bit-fields y Optimización

- {cite:t}`warren_hackers_2012`. Capítulo 2: Basics. Manipulación de bits y
  flags.

- **Fog, A.** *Optimizing Software in C++*. Technical University of Denmark.
  - Disponible en: https://www.agner.org/optimize/
  - Sección sobre layout de memoria y bit-fields.

(estandares-y-especificaciones)=
#### Estándares y Especificaciones

- **ISO/IEC 9899:2018 - C18 Standard**
  - Section 6.7.2.2: Enumeration specifiers. Definición formal.
  - Draft gratuito: http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2310.pdf

- **MISRA C:2012**. *Guidelines for the Use of the C Language in Critical
  Systems*.
  - Reglas específicas para enumeraciones en sistemas críticos.
  - Rule 10.3: Value of enumeration constant shall be used only in appropriate
    context.

(5_estructuras-recursos-en-linea)=
#### Recursos en Línea

- **C Enumerations** - https://en.cppreference.com/w/c/language/enum
  - Referencia técnica completa con ejemplos.

- **Enum Best Practices** - https://stackoverflow.com/questions/tagged/enums+c
  - Discusiones de la comunidad sobre patrones y anti-patrones.

(5_estructuras-herramientas)=
#### Herramientas

- **Doxygen** - https://www.doxygen.nl/manual/commands.html#cmddef
  - Documentación de enumeraciones con `@enum`.

- **Cppcheck** - http://cppcheck.net/
  - Análisis estático que detecta uso incorrecto de enums.

## Ejercicios de Autoevaluación

### Sintaxis y offsetof

:::{exercise}
:label: ej-struct-acceso-puntero
Declarás una estructura llamada `persona_t` con un arreglo de caracteres
`nombre` de tamaño 50 y un entero `edad`. Escribí una función en C llamada
`cumplir_anos` que reciba un puntero a `persona_t` e incremente su miembro
`edad` en `1` utilizando el operador de flecha `->`.

:::
<!-- {exercise} -->

:::{solution} ej-struct-acceso-puntero
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
typedef struct
{
    char nombre[50];
    int edad;
} persona_t;
// La función recibe el puntero a la estructura
void cumplir_anos(persona_t *persona)
{
    if (persona != NULL)
    {
        // Acceso indirecto mediante el operador ->
        persona->edad++;
    }
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-struct-acceso-puntero -->

:::{exercise}
:label: ej-struct-offsetof-manual
Dada la estructura:
``` c
struct Contenedor
{
    char c;
    int i;
    char d;
};
```
<!-- c -->
Calculá de forma matemática los desplazamientos (*offsets*) en bytes de los
miembros `c`, `i` y `d` en un sistema de 32 bits con alineación natural de 4
bytes, y mostrá cómo imprimirlos usando la macro `offsetof`.

:::
<!-- {exercise} -->

:::{solution} ej-struct-offsetof-manual
:class: dropdown
En una arquitectura con alineación natural de 4 bytes:
1. `c`: Se ubica al inicio de la estructura (desplazamiento 0).
2. `i`: Siendo un `int` de 4 bytes, requiere un desplazamiento múltiplo de 4.
   Como `c` ocupa 1 byte, el compilador inserta 3 bytes de padding. Por lo
   tanto, `i` se ubica en el desplazamiento 4.
3. `d`: Se coloca inmediatamente después de `i`, que ocupa los bytes 4 al 7. Por
   ende, `d` se ubica en el desplazamiento 8.
*(Nota: El tamaño total de la estructura será 12 bytes, ya que se insertan 3
bytes de padding al final para completar un múltiplo de 4 bytes).*

Código para imprimir los desplazamientos:
```{code-block} c
:linenos:
#include <stddef.h>
#include <stdio.h>
int main()
{
    printf("Offset de c: %zu\n", offsetof(struct Contenedor, c)); // Imprime 0
    printf("Offset de i: %zu\n", offsetof(struct Contenedor, i)); // Imprime 4
    printf("Offset de d: %zu\n", offsetof(struct Contenedor, d)); // Imprime 8
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-struct-offsetof-manual -->

:::{exercise}
:label: ej-struct-init-designados
Declará una estructura `punto_t` con miembros reales `x`, `y` y un puntero a
caracter `etiqueta`. Escribí la inicialización correcta de una instancia de esta
estructura utilizando **inicializadores designados** (de acuerdo con las buenas
prácticas recomendadas por la cátedra).

:::
<!-- {exercise} -->

:::{solution} ej-struct-init-designados
:class: dropdown
```{code-block} c
:linenos:
typedef struct
{
    double x;
    double y;
    const char *etiqueta;
} punto_t;
int main()
{
    // Inicialización explícita utilizando inicializadores designados
    punto_t origen = {.x = 0.0, .y = 0.0, .etiqueta = "Origen de Coordenadas"};
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-struct-init-designados -->


### AoS, SoA y Diseño

:::{exercise}
:label: ej-struct-aos-vs-soa-simd
Explicá de forma conceptual por qué la organización de datos en Estructura de
Arreglos (SoA) is computacionalmente más eficiente para optimizaciones de
paralelismo vectorial (SIMD) en la CPU cuando procesamos masivamente un solo
miembro (por ejemplo, el promedio de masas de miles de partículas) en
comparación con un Arreglo de Estructuras (AoS).

:::
<!-- {exercise} -->

:::{solution} ej-struct-aos-vs-soa-simd
:class: dropdown
- **AoS (Arreglo de Estructuras)**: Organiza la memoria disponiendo cada
  partícula contigua con todos sus atributos (`x`, `y`, `z`, `masa`, etc.). Al
  recorrer el arreglo para leer únicamente `masa`, la CPU carga líneas de caché
  completas que contienen datos adyacentes irrelevantes para este cómputo (como
  las posiciones y velocidades), resultando en desperdicio de ancho de banda y
  fallos de caché.
- **SoA (Estructura de Arreglos)**: Dispone todas las masas de forma contigua en
  un arreglo unidimensional único en memoria física. Esto permite a la CPU
  realizar lecturas lineales continuas y optimizar el uso de registros SIMD
  precargando múltiples masas contiguas sin ningún dato residual, maximizando la
  localidad espacial.

:::
<!-- {solution} ej-struct-aos-vs-soa-simd -->

:::{exercise}
:label: ej-struct-invariante-rectangulo
Diseñá una estructura `circulo_t` con un miembro real `radio` y otro miembro
`centro` (de tipo `punto_2d_t`). Implementá una función constructora
`crear_circulo` que valide la invariante de que el radio debe ser mayor a cero,
asignando un valor por defecto seguro en caso contrario.

:::
<!-- {exercise} -->

:::{solution} ej-struct-invariante-rectangulo
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
typedef struct
{
    double x;
    double y;
} punto_2d_t;
typedef struct
{
    punto_2d_t centro;
    double radio;
} circulo_t;
// Constructor con validación de invariante
circulo_t crear_circulo(double cx, double cy, double r)
{
    circulo_t circ;
    circ.centro.x = cx;
    circ.centro.y = cy;
    if (r <= 0.0)
    {
        fprintf(stderr, "Error: El radio debe ser mayor a cero. Asignando 1.0 "
                        "por seguridad.\n");
        circ.radio = 1.0;
    }
    else
    {
        circ.radio = r;
    }
    return circ;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-struct-invariante-rectangulo -->

:::{exercise}
:label: ej-struct-funcion-miembro
Implementá una estructura en C llamada `operacion_t` que contenga una constante
de caracteres `nombre` y un miembro de tipo puntero a función capaz de recibir
dos números enteros y retornar un entero. Mostrá cómo instanciar la estructura,
asignarle una función de suma e invocarla a través del puntero a función.

:::
<!-- {exercise} -->

:::{solution} ej-struct-funcion-miembro
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
// Definición del tipo de puntero a función
typedef int (*operacion_fn)(int, int);
typedef struct
{
    const char *nombre;
    operacion_fn ejecutar;
} operacion_t;
// Función compatible
int sumar(int a, int b)
{
    return a + b;
}
int main()
{
    // Instanciación
    operacion_t op_suma = {.nombre = "Suma Aritmética", .ejecutar = sumar};
    // Invocación indirecta a través de la estructura
    int resultado = op_suma.ejecutar(15, 25);
    printf("Operación: %s | Resultado: %d\n", op_suma.nombre,
           resultado); // Imprime 40
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-struct-funcion-miembro -->

:::{solution} ejer-tagged-union-2
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
typedef enum
{
    EVENTO_TECLA_PRESIONADA,
    EVENTO_CLICK_MOUSE,
    EVENTO_SALIR
} tipo_evento_t;
typedef struct
{
    int x;
    int y;
} pos_mouse_t;
typedef struct
{
    tipo_evento_t tipo;
    union
    {
        char tecla;
        pos_mouse_t pos;
    } datos;
} evento_t;
void procesar_evento(const evento_t *evento)
{
    switch (evento->tipo)
    {
    case EVENTO_TECLA_PRESIONADA:
        printf("Tecla presionada: '%c'\n", evento->datos.tecla);
        break;
    case EVENTO_CLICK_MOUSE:
        printf("Click de mouse en (%d, %d)\n", evento->datos.pos.x,
               evento->datos.pos.y);
        break;
    case EVENTO_SALIR:
        printf("Evento de salida recibido.\n");
        break;
    }
}
int main()
{
    evento_t ev1 = {.tipo = EVENTO_TECLA_PRESIONADA, .datos.tecla = 'q'};
    evento_t ev2 = {.tipo = EVENTO_CLICK_MOUSE, .datos.pos = {120, 80}};
    evento_t ev3 = {.tipo = EVENTO_SALIR};
    procesar_evento(&ev1);
    procesar_evento(&ev2);
    procesar_evento(&ev3);
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ejer-tagged-union-2 -->


### Uniones y Tagged Unions

:::{exercise}
:label: ej-union-size-calculation

Dadas las declaraciones:
```{code-block} c
:linenos:
union A
{
    char c;
    int i;
};
union B
{
    char buffer[20];
    double d;
};
```
<!-- {code-block} c -->
Calculá el tamaño exacto en bytes de cada una de estas uniones en un compilador
estándar donde `char` es 1 byte, `int` es 4 bytes y `double` es 8 bytes.

:::
<!-- {exercise} -->

:::{solution} ej-union-size-calculation
:class: dropdown

El tamaño de una `union` está determinado por el tamaño de su miembro más
grande, con alineación ajustada a su miembro con restricciones más fuertes:
- **`union A`**: El miembro más grande es `int i` (4 bytes). Por lo tanto, el
  tamaño total es de **4 bytes** (donde los 1 byte del `char c` comparten la
  misma ubicación física).
- **`union B`**: El miembro más grande es `char buffer[20]` (20 bytes). Sin
  embargo, el miembro con restricción de alineación más fuerte es `double d` (8
  bytes), lo que obliga a que el tamaño de la unión sea un múltiplo de 8 bytes.
  Para alinear correctamente la unión, el compilador redondea el tamaño a 24
  bytes. Por ende, el tamaño total es de **24 bytes**.

:::
<!-- {solution} ej-union-size-calculation -->

:::{exercise}
:label: ej-union-bit-granularidad

Diseñá una unión en C llamada `registro_t` que permita acceder a un valor entero
sin signo de 16 bits completo llamado `valor`, o de forma individual a sus bytes
superior (`alto`) e inferior (`bajo`) utilizando una estructura anidada.

:::
<!-- {exercise} -->

:::{solution} ej-union-bit-granularidad
:class: dropdown

```{code-block} c
:linenos:
#include <stdint.h>
typedef union
{
    uint16_t valor; // Acceso completo de 16 bits
    struct
    {
        uint8_t bajo; // Byte menos significativo (en little-endian)
        uint8_t alto; // Byte más significativo (en little-endian)
    } bytes;
} registro_t;
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-union-bit-granularidad -->

:::{exercise}
:label: ej-union-tagged-shape

Diseñá una unión etiquetada (tagged union) llamada `figura_t` que pueda
representar un círculo (radio real) o un rectángulo (ancho y alto reales).
Implementá una función `calcular_area` que retorne el área de la figura según su
tipo.

:::
<!-- {exercise} -->

:::{solution} ej-union-tagged-shape
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
typedef enum
{
    FIGURA_CIRCULO,
    FIGURA_RECTANGULO
} tipo_figura_t;
typedef struct
{
    tipo_figura_t tipo;
    union
    {
        struct
        {
            double radio;
        } circulo;
        struct
        {
            double ancho;
            double alto;
        } rectangulo;
    } datos;
} figura_t;
double calcular_area(const figura_t *figura)
{
    if (figura == NULL)
    {
        return 0.0;
    }
    switch (figura->tipo)
    {
    case FIGURA_CIRCULO:
        return 3.14159265 * figura->datos.circulo.radio *
               figura->datos.circulo.radio;
    case FIGURA_RECTANGULO:
        return figura->datos.rectangulo.ancho * figura->datos.rectangulo.alto;
    default:
        return 0.0;
    }
}
```
<!-- {code-block} c -->

:::
<!-- {solution} ej-union-tagged-shape -->


### Alineación y Padding

:::{exercise}
:label: ej-struct-padding-waste

Dada la estructura:
``` c
struct Suboptimo
{
    char c1;
    double d;
    char c2;
};
```
<!-- c -->
Calculá el tamaño total en bytes de esta estructura en una arquitectura x86_64 y
reescribila reordenando sus miembros para minimizar el consumo de memoria física
(padding).

:::
<!-- {exercise} -->

:::{solution} ej-struct-padding-waste
:class: dropdown

En una arquitectura x86_64 de 64 bits:
- `c1` ocupa 1 byte (offset 0).
- `d` (8 bytes) requiere estar alineado a una dirección múltiplo de 8. Por ende,
  se insertan 7 bytes de padding (offsets 1 al 7), ubicando a `d` en el offset
  8.
- `c2` ocupa 1 byte (offset 16).
- Para alinear la estructura completa a múltiplos de 8 (el tamaño de `double`),
  el compilador añade 7 bytes de padding al final (del offset 17 al 23).
El tamaño de `struct Suboptimo` es de **24 bytes**, desperdiciando 14 bytes en
padding.

La versión optimizada ordenando los miembros de mayor a menor tamaño es:
```{code-block} c
:linenos:
struct Optimizado
{
    double d; // 8 bytes (offset 0)
    char c1;  // 1 byte  (offset 8)
    char c2;  // 1 byte  (offset 9)
    // 6 bytes de padding al final para completar el múltiplo de 8
};
```
<!-- {code-block} c -->
El tamaño de `struct Optimizado` se reduce a **16 bytes**.

:::
<!-- {solution} ej-struct-padding-waste -->

:::{exercise}
:label: ej-struct-padding-array

Explicá detalladamente por qué el compilador debe insertar bytes de relleno
(*padding*) al final de una estructura (e.g., después del último miembro) y no
únicamente en el espacio intermedio entre miembros.

:::
<!-- {exercise} -->

:::{solution} ej-struct-padding-array
:class: dropdown

El padding final se inserta para garantizar la correcta alineación de todos los
elementos cuando la estructura se utiliza dentro de un **arreglo**.
En un arreglo, los elementos se disponen de forma contigua en memoria virtual.
Si no se agregaran bytes de relleno al final de la estructura para completar un
múltiplo del tamaño del miembro más restrictivo, el segundo elemento del arreglo
(ubicado en la dirección `dirección_base + sizeof(estructura)`) tendría sus
miembros desalineados. Por ejemplo, en una estructura que contiene un `int` y un
`char` en ese orden, el padding final de 3 bytes tras el `char` asegura que el
siguiente `int` en el arreglo inicie en una dirección múltiplo de 4.

:::
<!-- {solution} ej-struct-padding-array -->

:::{exercise}
:label: ej-struct-alignas-custom

Explicá qué es la restricción de "alineación natural" en procesadores de
hardware modernos y qué impacto tiene en la eficiencia del bus de datos de la
CPU que una variable se encuentre en una dirección no alineada.

:::
<!-- {exercise} -->

:::{solution} ej-struct-alignas-custom
:class: dropdown
Los procesadores modernos leen de la memoria RAM principal a través de palabras
físicas (bloques de 4 u 8 bytes). La alineación natural establece que un dato de
tamaño $T$ debe residir en una dirección que sea divisible por $T$.
Si un dato de 4 bytes se almacena en una dirección no alineada (por ejemplo,
dividida entre dos palabras de memoria), el controlador de memoria se ve
obligado a realizar **dos lecturas de bus de datos**, aplicar operaciones de
desplazamiento de bits (*shifting*) y máscaras lógicas para unir los fragmentos
del dato. Esto duplica el tiempo de acceso al bus de datos y degrada la
velocidad de ejecución. En algunas arquitecturas embebidas y RISC estrictas, el
acceso no alineado no está soportado y produce una interrupción por fallo de
alineación de hardware.

:::
<!-- {solution} ej-struct-alignas-custom -->



## Glosario

:::{glossary}

enumeración 
: Un tipo de dato en C que define un conjunto de constantes enteras
nombradas. Permite asociar nombres simbólicos significativos a valores
numéricos, mejorando la legibilidad del código y reduciendo errores relacionados
con el uso de "números mágicos".

constante enumerada 
: Cada uno de los identificadores definidos dentro de una
enumeración. Por defecto, reciben valores enteros consecutivos comenzando desde
0, pero pueden tener valores explícitos asignados por el programador.

máquina de estados finita 
: Un modelo computacional que consiste en un número
finito de estados, transiciones entre esos estados, y acciones. Las
enumeraciones son ideales para representar los estados posibles en este tipo de
sistemas.

flag de bits 
: Una técnica donde se usan valores que son potencias de 2 para
representar opciones que pueden combinarse usando operadores bitwise. Cada bit
en la representación binaria representa una opción específica que puede estar
activada o desactivada.

valor centinela 
: Un valor especial que marca el final o límite de un conjunto
de valores válidos. En enumeraciones, se usa frecuentemente un elemento
adicional (como `ENUM_MAX`) para facilitar la validación de rangos y iteración.

:::
<!-- {glossary} -->

## Síntesis y Resumen

Las estructuras (`struct`) agrupan tipos de datos heterogéneos bajo un mismo
nombre, ordenándose secuencialmente en memoria con posibles rellenos de
alineación (*padding*). Las uniones (`union`) comparten el mismo espacio físico
de memoria para todos sus miembros, permitiendo representar datos alternativos
eficientemente (por ejemplo, en uniones etiquetadas). Los campos de bits
optimizan el espacio agrupando datos al nivel de bits individuales.

(referencias-lecturas-estructuras)=
## Referencias y Lecturas Complementarias

- **Kernighan, B. W. y Ritchie, D. M.** [@kernighan_c_2014]. *The C Programming
  Language* (2.ª edición). Prentice Hall.
  - Consultá el **Capítulo 6: Structures**, que expone la base histórica de las
    estructuras en C, la anidación de tipos, el pasaje de estructuras a
    funciones y el direccionamiento mediante punteros de tipo struct.
- **King, K. N.** [@king_c_2008]. *C Programming: A Modern Approach* (2.ª
  edición). W. W. Norton & Company.
  - Revisá el **Capítulo 16: Structures, Unions, and Enumerations** para un
    análisis pedagógico brillante sobre la inicialización de estructuras
    (incluyendo inicializadores designados de C99), el uso seguro de uniones y
    la modelización de uniones etiquetadas (*tagged unions*).
- **Gustedt, J.** [@gustedt_modern_2019]. *Modern C*. Manning Publications.
  - Estudiá las secciones correspondientes al almacenamiento y alineación de
    datos estructurados, donde se detalla el comportamiento del alineamiento
    natural de las variables y el cálculo preciso de los bytes de relleno
    (*padding*).
- **Sommers, J.** [@sommers_jsommers/cbook_2025]. *jsommers/cbook*.
  - Consultá los capítulos referidos a estructuras y campos de bits para ver
    ejemplos prácticos de cómo empaquetar información y optimizar la utilización
    de la memoria RAM.
