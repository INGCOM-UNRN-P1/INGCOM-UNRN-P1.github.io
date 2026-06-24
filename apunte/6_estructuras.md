---
title: 'Estructuras y Tipos Compuestos'
short_title: '6 - Estructuras'
subtitle: 'struct, union y campos de bits en C'
---

(estructuras-capitulo)=
## Los Ladrillos de la memoria

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

## Estructuras (`struct`): Agrupando Datos

Una `struct` es una colección de variables (miembros) de diferentes tipos,
agrupadas bajo un solo nombre.

```{figure} 6/struct_memory_layout.svg
:name: fig-struct-memory-layout
:alt: Organización de estructuras en memoria
:align: center

Las estructuras agrupan datos relacionados en memoria. El compilador puede añadir padding entre campos para optimizar el acceso.
```

### Declaración y `typedef`

La práctica estándar, como indica la regla {ref}`0x3004h`, es usar `typedef`
para crear un alias de tipo con el sufijo `_t`.

```c
typedef struct {
    char inicial;
    int legajo;
    float promedio;
} estudiante_t;

// Inicialización con inicializadores designados (preferido)
estudiante_t estudiante1 = { .inicial = 'J', .legajo = 12345, .promedio = 8.5f };
```

### Acceso a Miembros: `.` vs `->`

- **Operador Punto (`.`):** Para acceder a miembros de una variable `struct`.
- **Operador Flecha (`->`):** Para acceder a miembros a través de un **puntero**
  a una `struct`.

```c
estudiante_t est;
estudiante_t *p_est = &est;

est.legajo = 54321;      // Acceso directo
p_est->promedio = 9.0f;  // Acceso mediante puntero
```

El acceso `->` es equivalente a usar `(*p_est).promedio`, se prefiere la flecha
para simplificar este uso.

### Estructuras y Memoria: Alineación y Relleno (Padding)

El compilador a puede insertar bytes de relleno (padding), que son invisibles al
programador dentro de las `struct` para alinear los miembros en direcciones de
memoria que sean múltiplos de su tamaño. Esto optimiza la velocidad de acceso de
la CPU.

El problema con esto, es que en algunos casos necesitamos un control exacto de
los bits.

#### El "operador" `offsetof`

`offsetof` es una macro definida en el archivo de cabecera `<stddef.h>`. Su
propósito es calcular el **desplazamiento en bytes** de un miembro específico
dentro de una estructura (`struct`) o unión (`union`), desde el inicio de la
misma.

En otras palabras, te dice cuántos bytes hay entre el comienzo de la estructura
y el comienzo de uno de sus miembros.

##### ¿Para qué sirve?

Su principal utilidad reside en situaciones donde necesitas conocer la posición
exacta de un miembro dentro de una estructura sin tener una instancia de esa
estructura. Esto es común en programación de bajo nivel, {term}`serialización`
de datos y al trabajar con _buffers_ de memoria genéricos.

### Sintaxis

La sintaxis es la siguiente:

```c
size_t offsetof(type, member);
```

- `type`: Es el nombre del tipo de la estructura (ej. `struct MiEstructura`).
- `member`: Es el nombre del miembro de la estructura del cual querés saber el
  desplazamiento.

La macro devuelve un valor de tipo `size_t`, que es un tipo entero sin signo
capaz de representar el tamaño de cualquier objeto en memoria.

---

### Ejemplo Práctico

Imagina que tienes la siguiente estructura:

```c
#include <stdio.h>
#include <stddef.h>

struct Usuario {
    int id;
    char inicial;
    double salario;
};

int main() {
    size_t desplazamiento_id = offsetof(struct Usuario, id);
    size_t desplazamiento_inicial = offsetof(struct Usuario, inicial);
    size_t desplazamiento_salario = offsetof(struct Usuario, salario);

    printf("Desplazamiento de 'id': %zu bytes\n", desplazamiento_id);
    printf("Desplazamiento de 'inicial': %zu bytes\n", desplazamiento_inicial);
    printf("Desplazamiento de 'salario': %zu bytes\n", desplazamiento_salario);

    return 0;
}
```

### Posible Salida

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

### Casos de Uso Comunes

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

#### Laboratorio 1: Inspección de Layout

Vamos a analizar el layout de una estructura para visualizar el padding.

**`layout_inspect.c`**

```c
#include <stdio.h>
#include <stddef.h>

typedef struct {
    char a;     // 1 byte
    int  b;     // 4 bytes
    char c;     // 1 byte
} ejemplo_padding_t;

int main(void) {
    printf("sizeof(char) = %zu, sizeof(int) = %zu\n", sizeof(char), sizeof(int));
    printf("sizeof(ejemplo_padding_t) = %zu\n\n", sizeof(ejemplo_padding_t));

    printf("offsetof(a) = %zu\n", offsetof(ejemplo_padding_t, a));
    printf("offsetof(b) = %zu\n", offsetof(ejemplo_padding_t, b));
    printf("offsetof(c) = %zu\n", offsetof(ejemplo_padding_t, c));
}
```

**Compilación y Ejecución:**

```bash
gcc -Wextra -Wall -g layout_inspect.c -o layout_inspect
./layout_inspect
```

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

```{exercise}
:label: ejer-layout-1
**Optimización de Padding**

Reordená los miembros de `ejemplo_padding_t` para minimizar su tamaño total. Verificá tu resultado con `sizeof`. ¿Cuál es el orden óptimo y por qué?
```

````{solution} ejer-layout-1
:class: dropdown
El orden óptimo es ordenar los miembros de mayor a menor tamaño: `int b; char a; char c;`.

```c
typedef struct {
    int  b;     // 4 bytes
    char a;     // 1 byte
    char c;     // 1 byte
    // 2 bytes de padding al final para alinear la estructura completa
} ejemplo_optimizado_t;
// sizeof será 8
```
Aunque el orden `char a; char c; int b;` también reduce el tamaño a 8 bytes, la regla generalizable y recomendada para estructuras con múltiples tipos complejos es ordenar los miembros siempre **de mayor a menor tamaño**. Esto minimiza el padding de alineación de forma consistente sin importar la cantidad o el tipo de los datos adicionales, como se detalla en la Regla de Oro.
````

---

### Documentación de Estructuras

La documentación clara y detallada de las estructuras es fundamental para mantener código comprensible y mantenible. Una buena documentación explica no solo qué es cada campo, sino también su propósito, restricciones y relaciones con otros miembros. Existen dos enfoques principales para documentar estructuras, cada uno con sus ventajas según el contexto.

#### Enfoque 1: Bloque de Documentación Único

Este enfoque utiliza un único bloque de comentario antes de la definición de la estructura para describir su propósito general y documentar todos sus miembros. Es ideal para estructuras simples o cuando los miembros requieren explicaciones breves.

```c
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
typedef struct {
    double x;
    double y;
    double z;
} punto_3d_t;
```

**Ventajas:**
- Proporciona una visión general cohesiva de la estructura.
- Facilita la explicación de relaciones entre miembros.
- Mantiene la definición de la estructura visualmente limpia.

**Desventajas:**
- Puede volverse difícil de mantener si la estructura crece.
- La separación entre documentación y código puede dificultar actualizaciones.

#### Enfoque 2: Documentación Distribuida

Este enfoque combina un bloque de comentario que describe el propósito general de la estructura con comentarios de línea individuales para cada miembro. Es preferible para estructuras complejas con muchos campos o cuando cada miembro requiere explicación detallada.

```c
/**
 * Representa la configuración de una conexión de red.
 * 
 * Esta estructura almacena todos los parámetros necesarios para
 * establecer y mantener una conexión de red TCP/IP. Los valores
 * deben ser inicializados antes de llamar a conectar_red().
 */
typedef struct {
    char direccion_ip[16];      // Dirección IP en formato "xxx.xxx.xxx.xxx"
    unsigned short puerto;      // Puerto de destino (1-65535)
    int timeout_ms;             // Tiempo de espera en milisegundos para la conexión
    bool usar_tls;              // true si se requiere conexión segura (TLS/SSL)
    unsigned int reintentos;    // Número máximo de intentos de reconexión
    void *contexto_usuario;     // Puntero opaco para datos del usuario (puede ser NULL)
} configuracion_red_t;
```

**Ventajas:**
- Cada campo tiene su documentación adyacente, facilitando actualizaciones.
- La estructura es autodocumentada al leerla linealmente.
- Ideal para estructuras con campos que requieren explicaciones específicas.

**Desventajas:**
- Puede hacer la definición visualmente más extensa.
- Las relaciones entre campos pueden ser menos evidentes.

### Ejemplo Completo: Estructura Compleja

Para estructuras complejas que involucran múltiples conceptos, el enfoque distribuido suele ser más efectivo:

```c
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
typedef struct {
    char id_transaccion[37];        // UUID único de la transacción (formato RFC 4122)
    long long monto;                // Monto en la menor unidad de la moneda
    char numero_cuenta_origen[21];  // Número de cuenta origen (máx. 20 dígitos + '\0')
    char numero_cuenta_destino[21]; // Número de cuenta destino (máx. 20 dígitos + '\0')
    time_t timestamp;               // Momento exacto de la transacción (UNIX epoch)
    enum tipo_transaccion tipo;     // Tipo: TRANSFERENCIA, DEPOSITO, RETIRO, etc.
    char descripcion[256];          // Descripción proporcionada por el usuario
    bool procesada;                 // true si la transacción ya fue procesada
    int codigo_resultado;           // 0 = éxito, != 0 = código de error específico
    char firma_digital[65];         // Hash SHA-256 de la transacción (64 caracteres hex + '\0')
} transaccion_bancaria_t;
```

### Recomendaciones Generales

1. **Consistencia:** Elegí un enfoque y mantenélo en todo el proyecto. Si usás el enfoque distribuido, todos los miembros deben tener comentarios.

2. **Información Útil:** Documentá restricciones, rangos válidos, unidades de medida y valores especiales (como NULL para punteros opcionales).

3. **Invariantes:** Si la estructura tiene invariantes o precondiciones, documentalas claramente en el bloque general.

4. **Actualizaciones:** Cuando modifiques la estructura, actualizá la documentación inmediatamente. La documentación desactualizada es peor que la falta de documentación.

5. **Relaciones:** Si los campos tienen dependencias entre sí, explicá estas relaciones claramente.

Para más detalles sobre el estilo de comentarios y documentación, consultá la {ref}`regla 0x0032h  <0x000Ah>` sobre cómo escribir comentarios que expliquen el "porqué" y no el "qué".

---

### Consideraciones de Uso y Diseño \[new\]

El diseño de estructuras va más allá de simplemente agrupar datos relacionados. Las decisiones sobre cómo organizar los miembros impactan directamente en la claridad del código, el rendimiento, la mantenibilidad y la corrección del programa. Esta sección explora principios y patrones de diseño fundamentales para crear estructuras efectivas.

:::{warning} ¿Entra en el parcial?

Este tema salió de una pregunta de discussions y aunque es importante ver por que y los efectos que tiene
_no entra_ en el parcial.

Lo que sí entra, es el hecho de utilizar, _la sintaxis intuitiva_ {ref}`AoS`, en lugar de {ref}`SoA`.

:::

#### Arreglo de Estructuras vs Estructura de Arreglos

Una de las decisiones más importantes al diseñar estructuras es elegir entre **arreglo de estructuras (AoS)** o **estructura de arreglos (SoA)**. Ambos enfoques tienen trade-offs significativos en términos de claridad, rendimiento y facilidad de uso.

```{figure} 6/aos_vs_soa.svg
:name: fig-aos-vs-soa
:align: center
:width: 100%

Comparación visual entre AoS y SoA mostrando cómo se organizan los datos en memoria y el impacto en el uso de caché.
```
(AoS)=
##### Arreglo de Estructuras (Array of Structures - AoS)

En este enfoque, cada elemento del arreglo es una estructura completa que contiene todos los atributos de una entidad.

```c
typedef struct {
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
```

**Ventajas:**
- **Claridad conceptual:** Cada elemento del arreglo representa una entidad completa e independiente.
- **Facilidad de uso:** Acceder a todos los atributos de una partícula es intuitivo: `particulas[i].x`, `particulas[i].y`, etc.
- **Gestión de memoria simple:** Una sola asignación para todo el arreglo.
- **Localidad espacial por entidad:** Todos los datos de una entidad están contiguos en memoria.
- **Ideal para operaciones por entidad:** Si procesás cada entidad individualmente con todos sus atributos.

**Desventajas:**
- **Caché poco eficiente en operaciones vectoriales:** Si solo necesitás un atributo (ej: solo las posiciones `x`), el procesador carga en caché datos innecesarios (masa, velocidades, etc.).
- **Penalización en SIMD:** Las instrucciones vectoriales modernas (SSE, AVX) prefieren datos contiguos del mismo tipo.

**Ejemplo de Uso:**

```c
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
```
(SoA)=
##### Estructura de Arreglos (Structure of Arrays - SoA)

En este enfoque, cada atributo se almacena en su propio arreglo, y la estructura contiene estos arreglos.

```c
typedef struct {
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
```

**Ventajas:**
- **Eficiencia de caché:** Al procesar un solo atributo (ej: todas las posiciones `x`), accedés a memoria contigua sin datos irrelevantes.
- **Optimización SIMD:** Procesadores modernos pueden aplicar la misma operación a múltiples elementos simultáneamente.
- **Menos desperdicio de ancho de banda:** Solo cargás los datos que realmente necesitás.

**Desventajas:**
- **Complejidad de gestión:** Múltiples asignaciones de memoria, más propenso a errores.
- **Sintaxis menos intuitiva:** `sistema.x[i]` vs `particulas[i].x`.
- **Consistencia manual:** Debés garantizar que todos los arreglos tengan el mismo tamaño.
- **Mayor overhead en operaciones por entidad:** Si necesitás todos los atributos de una entidad, accedés a múltiples arreglos.

**Ejemplo de Uso:**

```c
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
```

Este código es más fácil de vectorizar automáticamente por el compilador, ya que cada lazo procesa un arreglo contiguo de un solo tipo.

##### Implementación Completa: Gestión de Memoria en SoA

```c
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
```

:::{important} Gestión de Errores en SoA

Notá cómo la función `crear_sistema` debe verificar **todas** las asignaciones y, en caso de error, liberar **todas** las asignaciones previas antes de retornar. Esto añade complejidad pero es esencial para evitar fugas de memoria.
:::

##### ¿Cuándo Usar Cada Enfoque?

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

Empezá con AoS (arreglo de estructuras) por defecto. Es más simple, más claro y menos propenso a errores. Solo considerá SoA (estructura de arreglos) si el perfilado muestra que el acceso a memoria es un cuello de botella y el patrón de acceso lo justifica.

La optimización prematura es la raíz de todo mal. Priorizá código claro y correcto primero, optimizá después si es necesario.
:::

##### Ejemplo Comparativo: Búsqueda de Máximo

**AoS:**
```c
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
```

**SoA:**
```c
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
```

En el caso de SoA, el lazo accede únicamente al arreglo `masa`, lo cual es óptimo para el caché. Sin embargo, notá que la función retorna un índice, no un puntero, lo que puede ser menos conveniente para el usuario.

#### Encapsulación de Invariantes

Las estructuras deben diseñarse de modo que sea imposible o difícil crear instancias inválidas. Esto se logra mediante:

1. **Constructores:** Funciones que inicializan correctamente la estructura.
2. **Validadores:** Funciones que verifican invariantes.
3. **Punteros opacos:** Ocultar la implementación interna.

```c
/**
 * Representa un rectángulo con lados paralelos a los ejes.
 * 
 * Invariantes:
 *   - ancho debe ser > 0
 *   - alto debe ser > 0
 */
typedef struct {
    double x;        // Coordenada X de la esquina inferior izquierda
    double y;        // Coordenada Y de la esquina inferior izquierda
    double ancho;    // Ancho del rectángulo (debe ser > 0)
    double alto;     // Alto del rectángulo (debe ser > 0)
} rectangulo_t;

// Constructor que garantiza invariantes
rectangulo_t crear_rectangulo(double x, double y, double ancho, double alto)
{
    rectangulo_t rect = {0};
    
    // Validación de precondiciones
    if (ancho <= 0.0 || alto <= 0.0)
    {
        fprintf(stderr, "Error: dimensiones de rectángulo deben ser positivas\n");
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
```

:::{note} Defensa contra Uso Incorrecto

Al proporcionar un constructor, reducís la probabilidad de que los usuarios creen rectángulos con dimensiones inválidas. Sin embargo, C no puede forzar el uso del constructor, por lo que la documentación clara es esencial.
:::

#### Minimización de Padding

Ordenar los miembros de mayor a menor tamaño reduce el padding y el tamaño total de la estructura:

```{figure} 6/padding_optimization.svg
:name: fig-padding-optimization
:align: center
:width: 90%

Optimización de estructuras ordenando miembros por tamaño. El diseño subóptimo desperdicia 50% del espacio, mientras que el optimizado solo 25%.
```

```c
// Diseño subóptimo (12 bytes en x86-64) - Equivalente a ejemplo_padding_t del Laboratorio 1
// (Ver offsetof y padding detallados en el Laboratorio 1)

// Diseño optimizado (8 bytes en x86-64) - Aplicando la regla de ordenamiento mayor a menor
typedef struct {
    int b;        // 4 bytes
    char a;       // 1 byte
    char c;       // 1 byte (2 bytes de padding después)
} optimizada_t;
```

:::{tip} Regla de Oro: Mayor a Menor

Ordená los miembros de la estructura de mayor a menor tamaño. Los tipos más grandes primero (`double`, `long`), luego intermedios (`int`, `float`), y finalmente los más pequeños (`char`, `bool`). Esto minimiza el padding automático insertado por el compilador.
:::

#### Uso de Estructuras Anidadas

Las estructuras anidadas permiten organizar conceptos complejos de forma jerárquica:

```c
typedef struct {
    double x;
    double y;
} punto_2d_t;

typedef struct {
    punto_2d_t posicion;
    punto_2d_t velocidad;
    double masa;
    double radio;
} cuerpo_2d_t;

// Uso
cuerpo_2d_t planeta = {
    .posicion = {.x = 0.0, .y = 0.0},
    .velocidad = {.x = 10.0, .y = 5.0},
    .masa = 5.97e24,
    .radio = 6.371e6
};

// Acceso
double distancia_al_origen = sqrt(planeta.posicion.x * planeta.posicion.x +
                                  planeta.posicion.y * planeta.posicion.y);
```

**Ventajas:**
- Reutilización de tipos comunes (`punto_2d_t` usado para posición y velocidad)
- Organización lógica clara
- Facilita la creación de funciones genéricas (ej: `calcular_distancia` que opera sobre `punto_2d_t`)

#### Punteros a Funciones como Miembros

Para comportamiento polimórfico en estructuras:

```c
typedef struct figura figura_t;

typedef double (*calcular_area_fn)(const figura_t *);
typedef void (*dibujar_fn)(const figura_t *);

struct figura {
    calcular_area_fn calcular_area;
    dibujar_fn dibujar;
    void *datos;  // Puntero opaco a datos específicos de cada tipo de figura
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
            .calcular_area = NULL,
            .dibujar = NULL,
            .datos = NULL
        };
        return fig_nula;
    }
    *radio_heap = radio;
    
    figura_t fig = {
        .calcular_area = calcular_area_circulo,
        .dibujar = dibujar_circulo,
        .datos = radio_heap
    };
    
    return fig;
}
```

Este patrón permite un estilo de programación orientada a objetos rudimentario en C, donde diferentes "tipos" de figuras comparten la misma interfaz pero tienen comportamientos distintos.

:::{warning} Gestión de Memoria con Punteros Opacos

Cuando usás `void *datos` para almacenar información específica del tipo, debés documentar claramente quién es responsable de liberar esa memoria y proporcionar funciones destructoras adecuadas.
:::

#### Estructuras Auto-descriptivas

Incluir metadatos en la estructura facilita la depuración y la serialización:

```c
typedef enum {
    TIPO_ENTERO,
    TIPO_FLOTANTE,
    TIPO_CADENA
} tipo_dato_t;

typedef struct {
    tipo_dato_t tipo;
    union {
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
```

Este patrón (estructura con un `enum` que indica el tipo y un `union` que contiene los datos) se llama **tagged union** y es fundamental para representar datos heterogéneos de forma segura.

---

## Uniones (`union`): Un Espacio para Múltiples Propósitos

Una `union` permite que varios miembros compartan la **misma ubicación de
memoria**. Su tamaño es el de su miembro más grande. Solo un miembro puede estar
"activo" a la vez.

```{figure} 6/union_vs_struct.svg
:name: fig-union-vs-struct
:alt: Diferencias entre struct y union
:align: center

Comparación visual entre estructuras (todos los miembros en memoria separada) y uniones (todos comparten el mismo espacio de memoria).
```

#### El Patrón de Unión Etiquetada (Tagged Union)

Por sí mismas, las `union` tienen usos muy limitados ya que no es posible saber
como tenemos que interpretar la información contenida, para esto, se utiliza una
**unión etiquetada**: una `struct` que contiene un `enum` (la etiqueta) y una
`union` (el valor).

**`tagged_union.c`**

```c
#include <stdio.h>

typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_TEXTO
} tipo_dato_t;

typedef struct {
    tipo_dato_t tipo;
    union {
        int i;
        float f;
        const char *s;
    } valor;
} variante_t;

void imprimir_variante(const variante_t *v) {
    switch (v->tipo) {
        case TIPO_INT: printf("Entero: %d\n", v->valor.i); break;
        case TIPO_FLOAT: printf("Flotante: %.2f\n", v->valor.f); break;
        case TIPO_TEXTO: printf("Texto: \"%s\"\n", v->valor.s); break;
    }
}

int main() {
    variante_t v1 = { .tipo = TIPO_INT, .valor.i = 100 };
    variante_t v2 = { .tipo = TIPO_FLOAT, .valor.f = 3.14f };
    variante_t v3 = { .tipo = TIPO_TEXTO, .valor.s = "Hola" };

    imprimir_variante(&v1);
    imprimir_variante(&v2);
    imprimir_variante(&v3);
    return 0;
}
```

Este patrón es la base para implementar tipos de datos polimórficos en C.

---

### Documentación de Uniones

Las uniones (`union`) requieren documentación particularmente cuidadosa debido a que múltiples miembros comparten la misma ubicación de memoria. Es fundamental documentar cuándo y cómo debe accederse a cada miembro para evitar comportamiento indefinido.

#### Enfoque 1: Bloque de Documentación Único

Para uniones simples, un único bloque de comentario puede ser suficiente si se explica claramente el propósito y las restricciones de uso.

```c
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
typedef union {
    int32_t como_int;
    uint32_t como_uint;
    float como_float;
    uint8_t como_bytes[4];
} valor_32bits_t;
```

**Ventajas:**
- Proporciona una visión completa del propósito de la unión.
- Facilita explicar las restricciones de uso compartido de memoria.
- Mantiene la definición visualmente limpia.

**Desventajas:**
- Puede ser difícil de mantener si la unión crece.
- La separación entre documentación y miembros puede causar desincronización.

#### Enfoque 2: Documentación Distribuida

Para uniones más complejas o uniones etiquetadas, el enfoque distribuido es preferible, especialmente cuando cada miembro tiene propósitos o restricciones específicas.

```c
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
typedef union {
    struct {                        // Válido cuando tipo == MSG_TEXTO
        char contenido[256];        // Mensaje de texto (máx. 255 chars + '\0')
        size_t longitud;            // Longitud real del mensaje
    } mensaje_texto;
    
    struct {                        // Válido cuando tipo == MSG_NUMERO
        int64_t valor;              // Valor numérico a transmitir
        bool es_firmado;            // true si el valor es con signo
    } mensaje_numero;
    
    struct {                        // Válido cuando tipo == MSG_ARCHIVO
        char nombre[128];           // Nombre del archivo
        size_t tamano;              // Tamaño en bytes
        uint32_t checksum;          // Checksum CRC32 para verificación
        void *datos;                // Puntero a los datos del archivo
    } mensaje_archivo;
} datos_mensaje_t;
```

**Ventajas:**
- Cada miembro tiene su documentación adyacente.
- Facilita documentar estructuras anidadas dentro de la unión.
- Ideal para uniones etiquetadas con miembros complejos.

**Desventajas:**
- La definición puede volverse visualmente extensa.
- Requiere disciplina para documentar todos los miembros consistentemente.

#### Documentación de Uniones para Manipulación de Bits

Para uniones usadas en programación de bajo nivel, la documentación debe ser especialmente detallada:

```c
/**
 * Permite manipular y acceder a un valor de 64 bits en diferentes granularidades.
 * 
 * Esta unión es útil para operaciones de bajo nivel que requieren acceso
 * tanto al valor completo como a sus partes individuales (mitades, bytes, bits).
 * 
 * NOTA DE PORTABILIDAD: El orden de los bytes (endianness) afecta cómo se
 * interpretan los campos byte[]. En sistemas little-endian, byte[0] es el
 * byte menos significativo. En big-endian, es el más significativo.
 * 
 * Uso típico: Conversión de protocolos de red, serialización, depuración.
 */
typedef union {
    uint64_t completo;          // Acceso al valor completo de 64 bits
    
    struct {                    // Acceso a mitades de 32 bits
        uint32_t bajo;          // 32 bits inferiores
        uint32_t alto;          // 32 bits superiores
    } mitades;
    
    uint16_t palabras[4];       // Acceso como 4 palabras de 16 bits
    uint8_t bytes[8];           // Acceso individual a los 8 bytes
} registro_64bits_t;
```

### Ejemplo Completo: Unión Etiquetada con Documentación Exhaustiva

Para uniones etiquetadas (el patrón más común y seguro), la documentación debe cubrir tanto la unión como la estructura contenedora:

```c
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
typedef struct {
    /**
     * Identifica qué tipo de dato está almacenado actualmente.
     * Este campo DEBE actualizarse cada vez que se modifica 'datos'.
     */
    enum {
        TIPO_VACIO,      // Ningún valor almacenado (estado inicial)
        TIPO_ENTERO,     // datos.entero es válido
        TIPO_FLOTANTE,   // datos.flotante es válido
        TIPO_CADENA,     // datos.cadena es válido (debe liberarse si se asignó dinámicamente)
        TIPO_PUNTERO     // datos.puntero es válido
    } tipo;
    
    /**
     * Almacenamiento para el valor actual.
     * Solo el miembro correspondiente a 'tipo' contiene datos válidos.
     */
    union {
        int64_t entero;         // Entero de 64 bits con signo
        double flotante;        // Número de punto flotante de precisión doble
        char *cadena;           // Puntero a cadena (responsabilidad del usuario liberar)
        void *puntero;          // Puntero genérico para tipos personalizados
    } datos;
} valor_t;

/**
 * Crea un valor de tipo entero.
 * 
 * @param entero Valor entero a almacenar
 * @return Nuevo valor_t inicializado con el entero proporcionado
 */
valor_t crear_valor_entero(int64_t entero) {
    return (valor_t){
        .tipo = TIPO_ENTERO,
        .datos.entero = entero
    };
}
```

### Recomendaciones Generales para Uniones

1. **Advertencias de seguridad:** Siempre documentá que solo un miembro es válido a la vez y que leer el miembro incorrecto causa comportamiento indefinido.

2. **Uniones etiquetadas:** Si la unión se usa con una etiqueta (enum), documentá claramente la relación entre el valor de la etiqueta y el miembro válido.

3. **Tamaño en memoria:** Mencioná el tamaño de la unión (determinado por su miembro más grande) si esto tiene implicaciones para el uso.

4. **Consideraciones de portabilidad:** Si la unión depende de representaciones específicas (endianness, tamaño de tipos), documentá estas dependencias.

5. **Gestión de memoria:** Si algún miembro contiene punteros que deben liberarse, documentá claramente la responsabilidad de gestión de memoria.

6. **Casos de uso:** Explicá para qué situaciones está diseñada la unión y cuándo debería (o no) usarse.

Para más detalles sobre el estilo de comentarios, consultá la {ref}`regla 0x0032h  <0x000Ah>` sobre cómo escribir comentarios que expliquen el "porqué" y no el "qué".

### Ejercicio

```{exercise}
:label: ejer-tagged-union-2
**Procesador de Eventos**

Diseñá una unión etiquetada `evento_t` para un sistema simple. Un evento puede ser:
1.  `EVENTO_TECLA_PRESIONADA`: contiene el código de la tecla (`char`).
2.  `EVENTO_CLICK_MOUSE`: contiene las coordenadas `x` e `y` (`int`).
3.  `EVENTO_SALIR`: no contiene datos adicionales.

Escribí una función `void procesar_evento(const evento_t *evento)` que imprima un mensaje descriptivo según el tipo de evento.
```

````{solution} ejer-tagged-union-2
:class: dropdown
```c
#include <stdio.h>

typedef enum {
    EVENTO_TECLA_PRESIONADA,
    EVENTO_CLICK_MOUSE,
    EVENTO_SALIR
} tipo_evento_t;

typedef struct {
    int x;
    int y;
} pos_mouse_t;

typedef struct {
    tipo_evento_t tipo;
    union {
        char tecla;
        pos_mouse_t pos;
    } datos;
} evento_t;

void procesar_evento(const evento_t *evento) {
    switch (evento->tipo) {
        case EVENTO_TECLA_PRESIONADA:
            printf("Tecla presionada: '%c'\n", evento->datos.tecla);
            break;
        case EVENTO_CLICK_MOUSE:
            printf("Click de mouse en (%d, %d)\n", evento->datos.pos.x, evento->datos.pos.y);
            break;
        case EVENTO_SALIR:
            printf("Evento de salida recibido.\n");
            break;
    }
}

int main() {
    evento_t ev1 = { .tipo = EVENTO_TECLA_PRESIONADA, .datos.tecla = 'q' };
    evento_t ev2 = { .tipo = EVENTO_CLICK_MOUSE, .datos.pos = {120, 80} };
    evento_t ev3 = { .tipo = EVENTO_SALIR };

    procesar_evento(&ev1);
    procesar_evento(&ev2);
    procesar_evento(&ev3);
    return 0;
}
```
````

---

## Campos de Bits (Bit-fields): Ahorro Extremo de Memoria

Los bit-fields permiten definir miembros de una `struct` con un ancho en bits
exacto, ideal para empaquetar flags o valores pequeños.

### Sintaxis y Ejemplo

```c
typedef struct {
    unsigned int activo      : 1; // 1 bit
    unsigned int modo_op     : 3; // 3 bits (valores 0-7)
    unsigned int prioridad   : 4; // 4 bits (valores 0-15)
} config_t;
```

El compilador empaquetará estos 8 bits en un solo byte (si es posible).

### Acceso y Type Punning Seguro

Cuando se trabaja con estructuras de campos de bits o representaciones de bajo nivel, suele ser necesario interpretar una estructura empaquetada como una secuencia cruda de bytes (por ejemplo, para transmitirla por red) o viceversa.

Un error común para lograr esto es castear la dirección de la estructura directamente:
```c
packed_byte_t data;
uint8_t byte_crudo = *(uint8_t*)&data; // ¡ERROR! Violación de strict aliasing
```

Esta técnica, llamada *type punning* mediante casteo de punteros, está prohibida en C moderno. El compilador asume que dos punteros de tipos incompatibles no apuntan al mismo objeto en memoria (regla de ***strict aliasing***). Optimizar el código bajo este supuesto permite mejoras de rendimiento significativas, pero si violamos la regla, el compilador puede reorganizar los accesos y producir un comportamiento indefinido.

Existen dos formas válidas y seguras de realizar *type punning* en C:
1. **El uso de uniones (`union`)**: En C estándar, escribir en un miembro de una unión y leer de otro diferente es un comportamiento bien definido y el método preferido para reinterpretación de datos.
2. **Uso de `memcpy`**: Copiar los bytes mediante `memcpy` es seguro y los optimizadores modernos suelen eliminar la llamada física a la función, generando código máquina óptimo.

### Laboratorio 2: Inspección de Bit-fields con Uniones

**`bitfield_inspect.c`**

```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t a : 2;
    uint8_t b : 3;
    uint8_t c : 3;
} packed_byte_t;

typedef union {
    packed_byte_t campos;
    uint8_t valor_raw;
} packed_byte_u;

int main() {
    packed_byte_u data;
    data.campos.a = 3; // 11b
    data.campos.b = 5; // 101b
    data.campos.c = 7; // 111b

    // Imprimimos la estructura de forma segura respetando el strict aliasing
    printf("sizeof(packed_byte_t) = %zu\n", sizeof(packed_byte_t));
    printf("Byte resultante: 0x%02X\n", data.valor_raw);
    return 0;
}
```

**Compilación y Ejecución:**

```bash
gcc -Wextra -Wall bitfield_inspect.c -o bitfield_inspect
./bitfield_inspect
```

**Análisis:** La salida `0xFD` (o `11111101` en binario) puede parecer
sorprendente. El orden en que el compilador asigna los bits dentro del byte es
**implementation-defined**. No asumas un orden específico si necesitás
portabilidad.

```{exercise}
:label: ejer-bitfield-2
**Decodificador de Paquetes**

Un protocolo de red envía un byte de estado con la siguiente estructura de bits:
- Bit 0: `es_ack` (1=ACK, 0=NACK)
- Bit 1: `es_fin` (1=Fin de transmisión)
- Bits 2-4: `tipo_paquete` (un número de 0 a 7)
- Bits 5-7: `checksum` (un número de 0 a 7)

Creá una `struct` con bit-fields para representar este byte. Escribí una función que reciba un `unsigned char` y lo imprima de forma legible usando la estructura.
```

````{solution} ejer-bitfield-2
:class: dropdown
```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t es_ack : 1;
    uint8_t es_fin : 1;
    uint8_t tipo_paquete : 3;
    uint8_t checksum : 3;
} estado_paquete_t;

typedef union {
    estado_paquete_t campos;
    uint8_t byte_completo;
} paquete_decoder_t;

void imprimir_estado_paquete(uint8_t byte_estado) {
    paquete_decoder_t decoder;
    decoder.byte_completo = byte_estado;

    printf("--- Estado del Paquete (0x%02X) ---\n", byte_estado);
    printf("  ACK: %s\n", decoder.campos.es_ack ? "Sí" : "No");
    printf("  FIN: %s\n", decoder.campos.es_fin ? "Sí" : "No");
    printf("  Tipo: %u\n", decoder.campos.tipo_paquete);
    printf("  Checksum: %u\n", decoder.campos.checksum);
    printf("----------------------------------\n");
}

int main() {
    // Ejemplo: ACK=1, FIN=0, Tipo=5 (101b), Checksum=3 (011b)
    // Binario: 011 101 0 1 -> 0xDA
    uint8_t paquete = 0b01110101;
    imprimir_estado_paquete(paquete);
    return 0;
}
```
````



---

(operadores-bitwise)=
## Operadores a Nivel de Bits

Los Campos de Bits del apartado anterior operan físicamente con bits individuales. Para manipularlos de forma explícita en código, C provee un conjunto de operadores bitwise que actúan sobre la representación binaria de los enteros.

## Introducción: El Poder a Nivel de Bit

En el corazón de cada operación que realiza una computadora se encuentran los
bits. La **manipulación de bits** es el conjunto de técnicas que nos permite
interactuar directamente con esta representación binaria de los datos. En C,
dominar estas técnicas es una habilidad práctica y poderosa para optimizar el
rendimiento, ahorrar memoria e interactuar con hardware.

## Representación Binaria

Todos los tipos de datos en C se almacenan como una secuencia de bits. Un
`unsigned char` (1 byte) que representa el número 200, en binario es `11001000`.

```text
Bit:      7   6   5   4   3   2   1   0
Valor:  128  64  32  16   8   4   2   1
-----------------------------------------
Binario:  1   1   0   0   1   0   0   0
Suma:   128 + 64+ 0 + 0 + 8 + 0 + 0 + 0 = 200
```

(memoria-endianness)=
### Endianness

El **endianness** define el orden en que se almacenan en memoria los bytes que componen un tipo de dato multi-byte (como `int` o `double`). Es un detalle de la arquitectura del procesador que puede ser crucial en programación de sistemas, redes o al trabajar con formatos de archivo binarios.

- **Little-endian**: El byte **menos** significativo se almacena en la dirección de memoria más baja. Es la arquitectura dominante hoy en día (Intel x86, AMD64, Apple Silicon).
- **Big-endian**: El byte **más** significativo se almacena en la dirección de memoria más baja. Era común en arquitecturas más antiguas (Motorola 68k, SPARC) y se sigue usando como el orden estándar en redes (Network Byte Order).

**Ejemplo con el valor `0x1A2B3C4D` (un `int` de 32 bits):**

| Dirección | Little-endian | Big-endian |
| :--- | :---: | :---: |
| `0x100` | `4D` | `1A` |
| `0x101` | `3C` | `2B` |
| `0x102` | `2B` | `3C` |
| `0x103` | `1A` | `4D` |

**¿Por qué es importante?**

Si escribís un `int` a un archivo en una máquina little-endian y lo leés en una big-endian, el valor será incorrecto.

**Cómo detectar el endianness en C:**

```c
#include <stdio.h> 
#include <stdint.h> 

int main(void) {
    uint32_t i = 1;
    char *c = (char*)&i;

    if (*c) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }

    return 0;
}
```

Este código funciona porque si es little-endian, el byte `01` se almacena en la primera dirección, y `*c` será `1`. Si es big-endian, el primer byte será `00`, y `*c` será `0`.

## Los Operadores a Nivel de Bits

### 1. AND a nivel de bits (`&`)

El bit del resultado es `1` solo si ambos bits correspondientes en los operandos
son `1`. Su uso principal es para **verificar** o **apagar** bits.

:::{exercise} espar
:label: espar
¿Es un número par?

Un número es par si su bit menos significativo (LSB, bit 0) es 0. Escribí una
función que use el operador `&` para determinar si un número es par.

:::

:::{solution} espar
:class: dropdown

```{code-block}c
#include <stdbool.h>

bool es_par(int numero) {
    // La máscara 1 (00000001) aísla el último bit.
    // Si el resultado de (numero & 1) es 0, el bit era 0.
    return (numero & 1) == 0;
}
```

:::

### 2. OR a nivel de bits (`|`)

El bit del resultado es `1` si al menos uno de los bits correspondientes es `1`.
Su uso principal es para **encender** bits.

:::{exercise} activar
:label: activar

Encender un Flag Dado un `unsigned char` que representa un
conjunto de 8 flags, escribí una función que encienda el 4to bit (bit en la
posición 3) sin modificar los demás. :::

:::{solution} activar
:class: dropdown

```{code-block} c
void activar_flag_4(unsigned char *estado) {
    // La máscara (1 << 3) es 8 (00001000).
    // El OR encenderá ese bit sin tocar los otros.
    *estado = *estado | (1 << 3);
}
```

:::

### 3. XOR a nivel de bits (`^`)

El bit del resultado es `1` solo si los bits correspondientes son
**diferentes**. Su uso principal es para **alternar (toggle)** bits.

:::{exercise} intercambio
:label: intercambio

Intercambio con XOR Escribí una función que intercambie los
valores de dos variables enteras **sin usar una variable temporal**, utilizando
únicamente el operador XOR. :::

:::{solution} intercambio
:class: dropdown

```{code-block} c
void swap_xor(int *a, int *b) {
    if (a != b) { // Previene que se anulen si apuntan al mismo lugar
        *a = *a ^ *b;
        *b = *a ^ *b; // *b se convierte en el valor original de *a
        *a = *a ^ *b; // *a se convierte en el valor original de *b
    }
}
```

:::

### 4. NOT a nivel de bits (`~`)

El operador NOT (complemento a uno) invierte todos los bits de su operando. `0`
se convierte en `1` y `1` en `0`.

:::{exercise} mask
:label: mask

Crear una Máscara para Apagar Escribí una expresión que cree una
máscara para apagar el 2do bit (posición 1) de un `char`, sin afectar a los
demás. 

::: 

Crear una Máscara para Apagar Escribí una expresión que cree una
máscara para apagar el 2do bit (posición 1) de un `char`, sin afectar a los
demás. 

::: 

:::{solution} mask
:class: dropdown

```{code-block} c
// Máscara para el 2do bit: (1 << 1) -> 00000010
// Máscara invertida: ~(1 << 1) -> 11111101
unsigned char mascara_apagado = ~(1 << 1);
```

:::

### 5. Desplazamientos (`<<` y `>>`)

- `<<`: Desplaza los bits a la izquierda. Equivale a multiplicar por potencias
  de 2.

  **Ejemplo:** `5 << 2`

  ```text
  00000101 (5) << 2  -->  00010100 (20)
  ```

- `>>`: Desplaza los bits a la derecha. Equivale a dividir por potencias de 2.

  **Ejemplo:** `20 >> 2`

  ```text
  00010100 (20) >> 2  -->  00000101 (5)
  ```

:::{exercise} multiplicacion
:label: multiplicacion

Multiplicación y División Rápida Escribí dos macros,
`MULT_POR_8(x)` y `DIV_POR_4(x)`, que usen operadores de desplazamiento para
realizar las operaciones. :::

:::{solution} multiplicacion
:class: dropdown

```{code-block} c
#define MULT_POR_8(x) ((x) << 3) // 2^3 = 8
#define DIV_POR_4(x)  ((x) >> 2) // 2^2 = 4
```

:::

## Ejercicios de Aplicación (Recetario)

### 1. Obtener el N-ésimo Bit

:::{exercise} get_bit
:label: get_bit

Escribí una función `int get_bit(int numero, int n)` que devuelva
el valor (0 o 1) del bit en la posición `n`. :::

:::{solution} get_bit
:class: dropdown

```{code-block} c
int get_bit(int numero, int n) {
    // Desplaza el bit n a la posición 0 y usa AND con 1 para aislarlo.
    return (numero >> n) & 1;
}
```

:::

### 2. Establecer el N-ésimo Bit

:::{exercise} set_bit
:label: set_bit
Escribí una función `void set_bit(int *numero, int n)` que
encienda el bit en la posición `n`. :::

:::{solution} set_bit
:class: dropdown

```{code-block} c
void set_bit(int *numero, int n) {
    // Crea una máscara con el bit n encendido (ej: 00001000) y aplica OR.
    *numero |= (1 << n);
}
```

:::

### 3. Limpiar el N-ésimo Bit

:::{exercise} clear_bit
:label: clear_bit

Escribí una función `void clear_bit(int *numero, int n)` que
apague el bit en la posición `n`. :::

:::{solution} clear_bit
:class: dropdown

```{code-block} c
void clear_bit(int *numero, int n) {
    // Crea una máscara con el bit n en 0 y el resto en 1, y aplica AND.
    *numero &= ~(1 << n);
}
```

:::

### 4. Contar Bits Encendidos (Hamming Weight)

:::{exercise} kernighan
:label: kernighan

Implementar una función que cuente el número de bits que están en
`1` en la representación binaria de un número, usando el algoritmo de Brian
Kernighan. 

:::

:::{solution} kernighan
:class: dropdown

 **Algoritmo de Brian Kernighan**: La operación
`n & (n - 1)` apaga el bit encendido menos significativo. El número de veces que
se puede hacer esta operación antes de que `n` sea 0 es el número de bits
encendidos.

```{code-block} c
int contar_bits_encendidos(int n) {
    int contador = 0;
    while (n > 0) {
        n = n & (n - 1); // Apaga el bit '1' de más a la derecha
        contador++;
    }
    return contador;
}
```

:::

### 5. Verificar si es Potencia de Dos

:::{exercise} potencia
:label: potencia

Escribí una función que determine si un número entero positivo es
una potencia de dos (2, 4, 8, 16...). :::

:::{solution} potencia
:class: dropdown

**Propiedad**: Un número que es potencia de dos
tiene exactamente un bit encendido en su representación binaria (ej. 8 es
`1000`). El número `n-1` tendrá todos los bits a la derecha de ese bit
encendidos (ej. 7 es `0111`). Por lo tanto, `n & (n - 1)` será siempre cero.

```{code-block} c
#include <stdbool.h>

bool es_potencia_de_dos(int n) {
    // n > 0 asegura que no se incluya el 0.
    // (n & (n - 1)) == 0 verifica que solo haya un bit encendido.
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

:::

## Glosario

:::{glossary}

Máscara de Bits (Bitmask)
: Un valor numérico utilizado para seleccionar,
modificar o consultar bits específicos de otro valor mediante operaciones a
nivel de bits como AND, OR y XOR.

Endianness
: Se refiere al orden en que se almacenan en memoria los bytes que
componen un tipo de dato multibyte. Es una consideración crucial para la
portabilidad de datos binarios.

:::


---

(bitmasks-errores)=
## Bitmasks para Errores Múltiples

Una aplicación directa de los operadores bitwise en ingeniería de sistemas es la codificación de múltiples errores en un único entero mediante *bitmasks*. Este patrón es ubicuo en drivers, sistemas embebidos y APIs de bajo nivel.

## Introducción

En muchas situaciones reales, una operación puede fallar por múltiples razones simultáneas. Por ejemplo, al validar datos de un formulario, pueden existir varios campos inválidos al mismo tiempo. Reportar solo el primer error obliga al usuario a corregir y reintentar múltiples veces. Una mejor solución es reportar **todas** las causas de error simultáneamente.

Este apunte presenta técnicas para manejar múltiples códigos de error usando **bitmasks con enumeraciones**, permitiendo representar y comunicar combinaciones de errores de forma eficiente y expresiva.

:::{important} Errores Compuestos
Cuando múltiples validaciones pueden fallar independientemente, es más útil reportar todas las fallas simultáneamente en lugar de forzar al usuario a corregir de a uno. Las bitmasks permiten representar combinaciones de errores en un solo valor entero.
:::

## Problema: Un Solo Código de Error

### Enfoque Tradicional (Un Error)

```c
typedef enum {
    ERROR_NINGUNO = 0,
    ERROR_NOMBRE_VACIO,
    ERROR_EMAIL_INVALIDO,
    ERROR_EDAD_FUERA_RANGO,
    ERROR_TELEFONO_INVALIDO
} error_validacion_t;

error_validacion_t validar_usuario(const usuario_t* usuario) {
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0) {
        return ERROR_NOMBRE_VACIO;  // Retorna solo el primero
    }
    
    if (!es_email_valido(usuario->email)) {
        return ERROR_EMAIL_INVALIDO;  // Nunca llega aquí si nombre falla
    }
    
    if (usuario->edad < 18 || usuario->edad > 120) {
        return ERROR_EDAD_FUERA_RANGO;
    }
    
    if (!es_telefono_valido(usuario->telefono)) {
        return ERROR_TELEFONO_INVALIDO;
    }
    
    return ERROR_NINGUNO;
}
```

**Problema:** Si el nombre está vacío Y el email es inválido, el usuario solo sabrá del nombre. Deberá corregir y volver a intentar para descubrir el siguiente error.

## Solución: Códigos de Error con Bitmasks

### Definición con Potencias de 2

Para representar múltiples errores simultáneamente, cada código de error debe ser una potencia de 2 (un único bit activado):

```c
typedef enum {
    ERROR_NINGUNO           = 0,      // 0b00000000
    ERROR_NOMBRE_VACIO      = 1 << 0, // 0b00000001
    ERROR_EMAIL_INVALIDO    = 1 << 1, // 0b00000010
    ERROR_EDAD_FUERA_RANGO  = 1 << 2, // 0b00000100
    ERROR_TELEFONO_INVALIDO = 1 << 3, // 0b00001000
    ERROR_DNI_INVALIDO      = 1 << 4, // 0b00010000
    ERROR_DIRECCION_VACIA   = 1 << 5, // 0b00100000
    ERROR_CIUDAD_INVALIDA   = 1 << 6  // 0b01000000
} errores_validacion_t;

// Tipo para almacenar combinaciones
typedef unsigned int errores_t;
```

### Acumular Múltiples Errores

```c
errores_t validar_usuario(const usuario_t* usuario) {
    errores_t errores = ERROR_NINGUNO;
    
    // Validar cada campo independientemente
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0) {
        errores |= ERROR_NOMBRE_VACIO;  // OR para acumular
    }
    
    if (!es_email_valido(usuario->email)) {
        errores |= ERROR_EMAIL_INVALIDO;
    }
    
    if (usuario->edad < 18 || usuario->edad > 120) {
        errores |= ERROR_EDAD_FUERA_RANGO;
    }
    
    if (!es_telefono_valido(usuario->telefono)) {
        errores |= ERROR_TELEFONO_INVALIDO;
    }
    
    if (!es_dni_valido(usuario->dni)) {
        errores |= ERROR_DNI_INVALIDO;
    }
    
    return errores;
}
```

### Verificar Presencia de Errores

```c
// Verificar si hay algún error
bool hay_errores(errores_t errores) {
    return errores != ERROR_NINGUNO;
}

// Verificar un error específico
bool tiene_error(errores_t errores, errores_validacion_t error_especifico) {
    return (errores & error_especifico) != 0;
}

// Uso
errores_t resultado = validar_usuario(&usuario);

if (hay_errores(resultado)) {
    if (tiene_error(resultado, ERROR_NOMBRE_VACIO)) {
        printf("Error: El nombre no puede estar vacío\n");
    }
    
    if (tiene_error(resultado, ERROR_EMAIL_INVALIDO)) {
        printf("Error: El formato del email es inválido\n");
    }
    
    if (tiene_error(resultado, ERROR_EDAD_FUERA_RANGO)) {
        printf("Error: La edad debe estar entre 18 y 120\n");
    }
}
```

## Operaciones con Bitmasks de Error

### Agregar Errores

```c
errores_t errores = ERROR_NINGUNO;

// Agregar un error
errores |= ERROR_NOMBRE_VACIO;

// Agregar múltiples errores a la vez
errores |= (ERROR_EMAIL_INVALIDO | ERROR_EDAD_FUERA_RANGO);
```

### Remover Errores

```c
// Remover un error específico
errores &= ~ERROR_EMAIL_INVALIDO;

// Remover múltiples errores
errores &= ~(ERROR_NOMBRE_VACIO | ERROR_DNI_INVALIDO);
```

### Alternar (Toggle) Errores

```c
// Alternar un error (si está, lo quita; si no está, lo agrega)
errores ^= ERROR_TELEFONO_INVALIDO;
```

### Verificar Todos o Alguno

```c
// Verificar si TODOS los errores especificados están presentes
bool tiene_todos(errores_t errores, errores_t conjunto) {
    return (errores & conjunto) == conjunto;
}

// Verificar si ALGUNO de los errores está presente
bool tiene_alguno(errores_t errores, errores_t conjunto) {
    return (errores & conjunto) != 0;
}

// Uso
if (tiene_todos(resultado, ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO)) {
    printf("Faltan tanto nombre como email\n");
}

if (tiene_alguno(resultado, ERROR_EDAD_FUERA_RANGO | ERROR_DNI_INVALIDO)) {
    printf("Problema con edad o DNI\n");
}
```

### Contar Errores

```c
int contar_errores(errores_t errores) {
    int contador = 0;
    
    // Contar bits activados
    while (errores) {
        contador += errores & 1;
        errores >>= 1;
    }
    
    return contador;
}

// Alternativa más eficiente (GCC builtin)
int contar_errores_rapido(errores_t errores) {
    return __builtin_popcount(errores);
}
```

## Casos Prácticos

### Caso 1: Validación de Formulario Web

```c
typedef enum {
    ERROR_FORM_NINGUNO          = 0,
    ERROR_FORM_USUARIO_VACIO    = 1 << 0,
    ERROR_FORM_PASSWORD_CORTO   = 1 << 1,
    ERROR_FORM_PASSWORD_DEBIL   = 1 << 2,
    ERROR_FORM_EMAIL_INVALIDO   = 1 << 3,
    ERROR_FORM_EDAD_INVALIDA    = 1 << 4,
    ERROR_FORM_TERMINOS_NO_ACEPTADOS = 1 << 5
} errores_formulario_t;

errores_t validar_registro(const formulario_registro_t* form) {
    errores_t errores = ERROR_FORM_NINGUNO;
    
    if (form->usuario == NULL || strlen(form->usuario) < 3) {
        errores |= ERROR_FORM_USUARIO_VACIO;
    }
    
    if (form->password == NULL || strlen(form->password) < 8) {
        errores |= ERROR_FORM_PASSWORD_CORTO;
    } else if (!password_es_fuerte(form->password)) {
        errores |= ERROR_FORM_PASSWORD_DEBIL;
    }
    
    if (!es_email_valido(form->email)) {
        errores |= ERROR_FORM_EMAIL_INVALIDO;
    }
    
    if (form->edad < 13) {
        errores |= ERROR_FORM_EDAD_INVALIDA;
    }
    
    if (!form->acepta_terminos) {
        errores |= ERROR_FORM_TERMINOS_NO_ACEPTADOS;
    }
    
    return errores;
}

void mostrar_errores_formulario(errores_t errores) {
    if (errores == ERROR_FORM_NINGUNO) {
        printf("Formulario válido\n");
        return;
    }
    
    printf("Errores en el formulario:\n");
    
    if (errores & ERROR_FORM_USUARIO_VACIO) {
        printf("  - El nombre de usuario debe tener al menos 3 caracteres\n");
    }
    
    if (errores & ERROR_FORM_PASSWORD_CORTO) {
        printf("  - La contraseña debe tener al menos 8 caracteres\n");
    }
    
    if (errores & ERROR_FORM_PASSWORD_DEBIL) {
        printf("  - La contraseña debe contener mayúsculas, minúsculas y números\n");
    }
    
    if (errores & ERROR_FORM_EMAIL_INVALIDO) {
        printf("  - El formato del email es inválido\n");
    }
    
    if (errores & ERROR_FORM_EDAD_INVALIDA) {
        printf("  - Debe ser mayor de 13 años para registrarse\n");
    }
    
    if (errores & ERROR_FORM_TERMINOS_NO_ACEPTADOS) {
        printf("  - Debe aceptar los términos y condiciones\n");
    }
}
```

### Caso 2: Verificación de Permisos

```c
typedef enum {
    PERMISO_NINGUNO      = 0,
    PERMISO_LEER         = 1 << 0,  // 0b00000001
    PERMISO_ESCRIBIR     = 1 << 1,  // 0b00000010
    PERMISO_EJECUTAR     = 1 << 2,  // 0b00000100
    PERMISO_ELIMINAR     = 1 << 3,  // 0b00001000
    PERMISO_COMPARTIR    = 1 << 4,  // 0b00010000
    PERMISO_ADMIN        = 1 << 5   // 0b00100000
} permisos_t;

typedef unsigned int permisos_usuario_t;

// Constantes útiles
const permisos_usuario_t PERMISOS_LECTURA_ESCRITURA = 
    PERMISO_LEER | PERMISO_ESCRIBIR;

const permisos_usuario_t PERMISOS_COMPLETOS = 
    PERMISO_LEER | PERMISO_ESCRIBIR | PERMISO_EJECUTAR | 
    PERMISO_ELIMINAR | PERMISO_COMPARTIR;

bool puede_realizar_accion(permisos_usuario_t permisos_usuario, 
                           permisos_t permiso_requerido) {
    return (permisos_usuario & permiso_requerido) == permiso_requerido;
}

permisos_usuario_t otorgar_permiso(permisos_usuario_t actual, 
                                     permisos_t nuevo_permiso) {
    return actual | nuevo_permiso;
}

permisos_usuario_t revocar_permiso(permisos_usuario_t actual, 
                                     permisos_t permiso_a_revocar) {
    return actual & ~permiso_a_revocar;
}

// Uso
permisos_usuario_t mis_permisos = PERMISO_LEER | PERMISO_ESCRIBIR;

if (puede_realizar_accion(mis_permisos, PERMISO_ELIMINAR)) {
    eliminar_archivo();
} else {
    printf("No tienes permiso para eliminar\n");
}

// Otorgar permiso de ejecución
mis_permisos = otorgar_permiso(mis_permisos, PERMISO_EJECUTAR);

// Revocar permiso de escritura
mis_permisos = revocar_permiso(mis_permisos, PERMISO_ESCRIBIR);
```

### Caso 3: Estado de Conexión de Red

```c
typedef enum {
    RED_OK               = 0,
    RED_SIN_CONEXION     = 1 << 0,
    RED_TIMEOUT          = 1 << 1,
    RED_DNS_FALLO        = 1 << 2,
    RED_SSL_ERROR        = 1 << 3,
    RED_CERTIFICADO_INVALIDO = 1 << 4,
    RED_PUERTO_BLOQUEADO = 1 << 5,
    RED_PROXY_ERROR      = 1 << 6
} errores_red_t;

typedef struct {
    errores_t errores;
    int codigo_http;
    char* mensaje;
} resultado_conexion_t;

resultado_conexion_t conectar_servidor(const char* url) {
    resultado_conexion_t resultado = {
        .errores = RED_OK,
        .codigo_http = 0,
        .mensaje = NULL
    };
    
    // Intentar resolver DNS
    if (!resolver_dns(url)) {
        resultado.errores |= RED_DNS_FALLO;
    }
    
    // Verificar conectividad básica
    if (!hay_conexion_internet()) {
        resultado.errores |= RED_SIN_CONEXION;
    }
    
    // Intentar conexión
    if (!conectar_con_timeout(url, 5000)) {
        resultado.errores |= RED_TIMEOUT;
    }
    
    // Verificar SSL si es HTTPS
    if (es_https(url) && !verificar_ssl(url)) {
        resultado.errores |= RED_SSL_ERROR;
        
        if (!certificado_valido(url)) {
            resultado.errores |= RED_CERTIFICADO_INVALIDO;
        }
    }
    
    return resultado;
}

void diagnosticar_conexion(const resultado_conexion_t* resultado) {
    if (resultado->errores == RED_OK) {
        printf("Conexión exitosa\n");
        return;
    }
    
    printf("Problemas detectados:\n");
    
    if (resultado->errores & RED_SIN_CONEXION) {
        printf("  [CRÍTICO] No hay conexión a Internet\n");
    }
    
    if (resultado->errores & RED_DNS_FALLO) {
        printf("  [ERROR] No se pudo resolver el nombre de dominio\n");
    }
    
    if (resultado->errores & RED_TIMEOUT) {
        printf("  [ERROR] Tiempo de espera agotado\n");
    }
    
    if (resultado->errores & RED_SSL_ERROR) {
        printf("  [ADVERTENCIA] Error en la conexión SSL\n");
    }
    
    if (resultado->errores & RED_CERTIFICADO_INVALIDO) {
        printf("  [ADVERTENCIA] El certificado no es válido o ha expirado\n");
    }
    
    // Sugerencias según la combinación
    if ((resultado->errores & RED_SIN_CONEXION) && 
        (resultado->errores & RED_DNS_FALLO)) {
        printf("\nSugerencia: Verifica tu conexión de red\n");
    } else if (resultado->errores & RED_CERTIFICADO_INVALIDO) {
        printf("\nSugerencia: Verifica la fecha del sistema\n");
    }
}
```

### Caso 4: Validación de Documento

```c
typedef enum {
    DOC_VALIDO               = 0,
    DOC_ENCABEZADO_INVALIDO  = 1 << 0,
    DOC_FORMATO_CORRUPTO     = 1 << 1,
    DOC_VERSION_NO_SOPORTADA = 1 << 2,
    DOC_FIRMA_INVALIDA       = 1 << 3,
    DOC_CHECKSUM_ERROR       = 1 << 4,
    DOC_METADATOS_FALTANTES  = 1 << 5,
    DOC_CONTENIDO_TRUNCADO   = 1 << 6
} errores_documento_t;

errores_t validar_documento(const documento_t* doc) {
    errores_t errores = DOC_VALIDO;
    
    // Validaciones independientes
    if (!validar_encabezado(doc)) {
        errores |= DOC_ENCABEZADO_INVALIDO;
    }
    
    if (!validar_formato(doc)) {
        errores |= DOC_FORMATO_CORRUPTO;
    }
    
    if (doc->version > VERSION_MAX_SOPORTADA) {
        errores |= DOC_VERSION_NO_SOPORTADA;
    }
    
    if (!verificar_firma_digital(doc)) {
        errores |= DOC_FIRMA_INVALIDA;
    }
    
    if (!verificar_checksum(doc)) {
        errores |= DOC_CHECKSUM_ERROR;
    }
    
    if (!tiene_metadatos_requeridos(doc)) {
        errores |= DOC_METADATOS_FALTANTES;
    }
    
    if (doc->tamanio_real < doc->tamanio_esperado) {
        errores |= DOC_CONTENIDO_TRUNCADO;
    }
    
    return errores;
}

bool es_error_critico(errores_t errores) {
    // Errores que impiden procesar el documento
    const errores_t ERRORES_CRITICOS = 
        DOC_FORMATO_CORRUPTO | DOC_CHECKSUM_ERROR | DOC_CONTENIDO_TRUNCADO;
    
    return (errores & ERRORES_CRITICOS) != 0;
}

bool es_error_recuperable(errores_t errores) {
    // Errores que permiten continuar con precaución
    const errores_t ERRORES_RECUPERABLES = 
        DOC_METADATOS_FALTANTES | DOC_VERSION_NO_SOPORTADA;
    
    return (errores & ERRORES_RECUPERABLES) != 0 && !es_error_critico(errores);
}
```

## Funciones Auxiliares Genéricas

### Conversión a Cadenas

```c
typedef struct {
    errores_validacion_t codigo;
    const char* mensaje;
} mapeo_error_t;

const mapeo_error_t MENSAJES_ERROR[] = {
    {ERROR_NOMBRE_VACIO, "El nombre no puede estar vacío"},
    {ERROR_EMAIL_INVALIDO, "Formato de email inválido"},
    {ERROR_EDAD_FUERA_RANGO, "La edad debe estar entre 18 y 120"},
    {ERROR_TELEFONO_INVALIDO, "Formato de teléfono inválido"},
    {ERROR_DNI_INVALIDO, "DNI inválido"},
    {ERROR_DIRECCION_VACIA, "La dirección no puede estar vacía"},
    {ERROR_CIUDAD_INVALIDA, "Ciudad no válida"}
};

void imprimir_errores(errores_t errores) {
    if (errores == ERROR_NINGUNO) {
        printf("Sin errores\n");
        return;
    }
    
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    
    printf("Errores encontrados:\n");
    for (int i = 0; i < num_errores; i++) {
        if (errores & MENSAJES_ERROR[i].codigo) {
            printf("  - %s\n", MENSAJES_ERROR[i].mensaje);
        }
    }
}
```

### Construcción de JSON con Errores

```c
char* errores_a_json(errores_t errores) {
    if (errores == ERROR_NINGUNO) {
        return strdup("{\"errores\": []}");
    }
    
    // Buffer dinámico (simplificado)
    char buffer[1024] = "{\"errores\": [";
    bool primero = true;
    
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    
    for (int i = 0; i < num_errores; i++) {
        if (errores & MENSAJES_ERROR[i].codigo) {
            if (!primero) {
                strcat(buffer, ", ");
            }
            strcat(buffer, "\"");
            strcat(buffer, MENSAJES_ERROR[i].mensaje);
            strcat(buffer, "\"");
            primero = false;
        }
    }
    
    strcat(buffer, "]}");
    return strdup(buffer);
}
```

## Límites y Consideraciones

### Número Máximo de Errores

Con un `unsigned int` (32 bits), podés representar hasta **32 errores diferentes**. Si necesitás más:

```c
// Para 64 errores
typedef unsigned long long errores_extendido_t;

typedef enum {
    ERROR_1  = 1ULL << 0,
    ERROR_2  = 1ULL << 1,
    // ...
    ERROR_64 = 1ULL << 63
} errores_64_t;
```

### Arrays de Bitmasks

Para sistemas muy complejos con cientos de posibles errores:

```c
#define NUM_PALABRAS_ERROR 4  // 4 * 32 = 128 errores posibles

typedef struct {
    unsigned int palabras[NUM_PALABRAS_ERROR];
} errores_multiples_t;

void agregar_error(errores_multiples_t* errores, int numero_error) {
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    
    if (palabra < NUM_PALABRAS_ERROR) {
        errores->palabras[palabra] |= (1U << bit);
    }
}

bool tiene_error_multiples(const errores_multiples_t* errores, int numero_error) {
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    
    if (palabra < NUM_PALABRAS_ERROR) {
        return (errores->palabras[palabra] & (1U << bit)) != 0;
    }
    
    return false;
}
```

## Buenas Prácticas

### 1. Documentar los Códigos

```c
/**
 * Códigos de error para validación de usuarios.
 * Pueden combinarse usando OR bitwise (|).
 * 
 * Ejemplo:
 *   errores_t resultado = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
 */
typedef enum {
    ERROR_NINGUNO           = 0,      ///< Sin errores
    ERROR_NOMBRE_VACIO      = 1 << 0, ///< Nombre NULL o vacío
    ERROR_EMAIL_INVALIDO    = 1 << 1, ///< Formato email inválido
    ERROR_EDAD_FUERA_RANGO  = 1 << 2  ///< Edad < 18 o > 120
} errores_validacion_t;
```

### 2. Usar Nombres Descriptivos

```c
// Bien: nombres claros
ERROR_NOMBRE_VACIO
ERROR_EMAIL_INVALIDO

// Mal: nombres crípticos
ERR_1
ERR_NOM
E_MAIL
```

### 3. Agrupar Errores Relacionados

```c
// Errores de entrada
const errores_t ERRORES_ENTRADA = 
    ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO | ERROR_DNI_INVALIDO;

// Errores de rango
const errores_t ERRORES_RANGO = 
    ERROR_EDAD_FUERA_RANGO | ERROR_FECHA_INVALIDA;

// Verificar grupo
if (errores & ERRORES_ENTRADA) {
    printf("Hay problemas con los datos de entrada\n");
}
```

### 4. Separar Errores de Advertencias

```c
typedef enum {
    // Errores (bits 0-15)
    ERROR_NOMBRE_VACIO      = 1 << 0,
    ERROR_EMAIL_INVALIDO    = 1 << 1,
    
    // Advertencias (bits 16-31)
    WARN_PASSWORD_DEBIL     = 1 << 16,
    WARN_NOMBRE_LARGO       = 1 << 17
} validacion_t;

const validacion_t MASCARA_ERRORES = 0x0000FFFF;
const validacion_t MASCARA_ADVERTENCIAS = 0xFFFF0000;

bool solo_advertencias(validacion_t resultado) {
    return (resultado & MASCARA_ERRORES) == 0 && 
           (resultado & MASCARA_ADVERTENCIAS) != 0;
}
```

## Comparación con Alternativas

### vs. Array de Códigos

**Bitmask:**
```c
errores_t errores = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
// Tamaño: 4 bytes (un int)
// Verificación: O(1)
```

**Array:**
```c
int errores[] = {ERROR_NOMBRE_VACIO, ERROR_EMAIL_INVALIDO};
int num_errores = 2;
// Tamaño: 8+ bytes (dos ints + contador)
// Verificación: O(n)
```

### vs. Lista Enlazada

**Bitmask:**
- Tamaño fijo y predecible
- No requiere memoria dinámica
- Operaciones muy rápidas
- Limitado a número fijo de errores

**Lista:**
- Tamaño variable
- Requiere malloc/free
- Operaciones más lentas
- Ilimitado número de errores

## Integración con Otros Patrones

### Con Único Retorno

```c
errores_t procesar_formulario(const formulario_t* form) {
    errores_t resultado = ERROR_NINGUNO;
    
    // Acumular errores
    resultado |= validar_campos(form);
    resultado |= validar_formato(form);
    resultado |= validar_coherencia(form);
    
    // Único retorno con todos los errores acumulados
    return resultado;
}
```

### Con Códigos de Estado

```c
typedef struct {
    bool exito;
    errores_t errores;
    void* datos;
} resultado_operacion_t;

resultado_operacion_t realizar_operacion(const datos_t* entrada) {
    resultado_operacion_t resultado = {
        .exito = false,
        .errores = ERROR_NINGUNO,
        .datos = NULL
    };
    
    resultado.errores = validar_entrada(entrada);
    
    if (resultado.errores == ERROR_NINGUNO) {
        resultado.datos = procesar(entrada);
        resultado.exito = (resultado.datos != NULL);
    }
    
    return resultado;
}
```

## Resumen

**Ventajas de códigos de error con bitmasks:**

1. **Eficiencia:** Representar múltiples errores en un solo entero
2. **Expresividad:** Operaciones bitwise claras y concisas
3. **Completitud:** Reportar todos los problemas simultáneamente
4. **Flexibilidad:** Combinar, agregar, remover errores fácilmente
5. **Performance:** Operaciones muy rápidas (solo operaciones de bits)

**Cuándo usar:**
- Validaciones con múltiples campos independientes
- Permisos y flags de estado
- Diagnóstico de problemas complejos
- APIs que deben reportar errores detallados

**Cuándo evitar:**
- Si solo hay un posible error a la vez
- Cuando necesitás más de 32-64 códigos diferentes
- Si la información del error es muy compleja (usa estructuras)

Los códigos de error con bitmasks son una herramienta poderosa para mejorar la usabilidad de APIs y aplicaciones, permitiendo comunicar de forma eficiente y completa todas las causas de un problema.

## Alineación de Miembros y Relleno en Estructuras (Padding)

En el desarrollo de software en C estándar, la disposición de los datos en la memoria física no siempre es contigua ni directa. Los procesadores modernos acceden a la memoria física mediante **palabras de máquina** (típicamente de 32 o 64 bits, es decir, 4 u 8 bytes). Para optimizar el rendimiento de las operaciones de lectura y escritura en el bus de datos, el hardware impone restricciones de alineación.

La **alineación natural** establece que una variable de tamaño $T$ bytes debe almacenarse en una dirección de memoria que sea múltiplo de $T$. Si un dato no se encuentra alineado, el procesador requerirá múltiples accesos a memoria para leer un único valor, degradando el rendimiento del sistema o, en ciertas arquitecturas, provocando una excepción de hardware (*bus error*).

Para cumplir con estas restricciones sin intervención del programador, el compilador introduce automáticamente bytes de relleno denominados **padding** entre los miembros de una estructura.

### Impacto en el Consumo de Memoria Física

Considerá la estructura `ejemplo_padding_t` presentada y analizada en el Laboratorio 1:

```c
typedef struct {
    char a;     // 1 byte
    int  b;     // 4 bytes
    char c;     // 1 byte
} ejemplo_padding_t;
```

A primera vista, se podría calcular que el tamaño físico de esta estructura es la suma de sus partes: $1 \text{ byte} + 4 \text{ bytes} + 1 \text{ byte} = 6 \text{ bytes}$. Sin embargo, al evaluar `sizeof(ejemplo_padding_t)`, el resultado en una arquitectura de 32 o 64 bits es **12 bytes**, como se demostró empíricamente en el Laboratorio 1.

El compilador reorganiza el espacio aplicando las siguientes reglas:

1. **Alineación de miembros**: Cada miembro debe alinearse a una dirección múltiplo de su propio tamaño. `tipo` se ubica en el desplazamiento (*offset*) 0. `id` requiere un offset múltiplo de 4; por ende, se añaden 3 bytes de relleno (*padding*) en los desplazamientos 1, 2 y 3, ubicando a `id` en el offset 4 (ocupando los bytes 4, 5, 6 y 7). `estado` se coloca en el offset 8.
2. **Alineación de la estructura completa**: El tamaño total de la estructura debe ser un múltiplo de la alineación de su miembro más restrictivo (el que requiera la mayor alineación). En este caso, el miembro más restrictivo es `id` (4 bytes). La estructura finaliza en el byte 8 (después de ocupar 9 bytes en total). Para redondear al siguiente múltiplo de 4, el compilador inserta 3 bytes de relleno al final de la estructura, totalizando 12 bytes.

:::{table} Disposición de memoria física para `sensor_desoptimizado_t` (12 bytes)
:label: tbl-padding-desoptimizado

| Offset | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| :--- | :---: | :---: | :---: | :---: |
| **0** | `tipo` (1B) | *Padding* | *Padding* | *Padding* |
| **4** | `id` (B0) | `id` (B1) | `id` (B2) | `id` (B3) |
| **8** | `estado` (1B) | *Padding* | *Padding* | *Padding* |
:::

### Estrategia de Optimización: Reordenamiento por Tamaño

Para mitigar el desperdicio de memoria física (que en el ejemplo anterior asciende al $50\%$), se debe declarar los miembros de la estructura en orden descendente de tamaño (o de restricción de alineación). Esto permite que los tipos de menor tamaño aprovechen los huecos naturales de alineación de los tipos más grandes.

Reescribiendo la estructura anterior:

```c
typedef struct {
    int id;             // 4 bytes (offset 0-3)
    char tipo;          // 1 byte  (offset 4)
    char estado;        // 1 byte  (offset 5)
    // 2 bytes de padding al final para completar múltiplo de 4
} sensor_optimizado_t;
```

El tamaño físico de `sensor_optimizado_t` es de **8 bytes**. Se logró reducir el consumo de memoria en un $33\%$ simplemente alterando el orden de declaración.

:::{table} Disposición de memoria física para `sensor_optimizado_t` (8 bytes)
:label: tbl-padding-optimizado

| Offset | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| :--- | :---: | :---: | :---: | :---: |
| **0** | `id` (B0) | `id` (B1) | `id` (B2) | `id` (B3) |
| **4** | `tipo` (1B) | `estado` (1B) | *Padding* | *Padding* |
:::

:::{important} Impacto en el Desarrollo a Gran Escala
Si bien una diferencia de 4 bytes puede parecer insignificante en sistemas modernos, este impacto se magnifica exponencialmente al trabajar con arreglos dinámicos de estructuras o buffers de red que almacenan millones de registros, afectando directamente la tasa de aciertos en la memoria caché del procesador.
:::

### Inspección de Desplazamientos con `offsetof`

La biblioteca estándar `<stddef.h>` proporciona la macro `offsetof`, que permite obtener el desplazamiento en bytes de un miembro respecto al inicio de la estructura.

```c
#include <stdio.h>
#include <stddef.h>

typedef struct {
    char tipo;
    int id;
    char estado;
} sensor_desoptimizado_t;

int main(void) {
    printf("Tamaño total: %zu bytes\n", sizeof(sensor_desoptimizado_t));
    printf("Offset de tipo: %zu\n", offsetof(sensor_desoptimizado_t, tipo));
    printf("Offset de id: %zu\n", offsetof(sensor_desoptimizado_t, id));
    printf("Offset de estado: %zu\n", offsetof(sensor_desoptimizado_t, estado));
    return 0;
}
```

:::{tip} Estilo
Al declarar variables o tipos estructurados, recordá seguir la regla {ref}`0x0001h` que exige identificadores descriptivos, y usá el sufijo `_t` para los alias definidos con `typedef` de acuerdo a la buena práctica del proyecto.
:::

---

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

tipo opaco 
: Un tipo de dato cuya implementación interna está oculta al código
cliente. Las enumeraciones pueden usarse para crear tipos opacos que encapsulan
conjuntos de valores válidos sin exponer su representación numérica subyacente.

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

## Referencias y Lecturas Complementarias

### Textos Fundamentales

- {cite:t}`kernighan_c_2014`. Sección 2.3: Constants y Apéndice A8.4: Enumeration Constants.

- {cite:t}`king_c_2008`. Capítulo 16: Structures, Unions, and Enumerations.

- {cite:t}`gustedt_modern_2019`. Level 1, Takeaway 1.6.2: Enumerations.

### Estructuras y Uniones

- {cite:t}`harbison_c_2002`. Capítulo 5: Types. Referencia exhaustiva de enums, structs y unions.

- {cite:t}`van_der_linden_expert_1994`. Capítulo 5: Thinking of Linking y Capítulo 6: Poetry in Motion.

### Patrones de Diseño con Enums

- {cite:t}`hanson_c_1996`. Técnicas para crear interfaces limpias usando enumeraciones.

- {cite:t}`lakos_large_1996`. Capítulo 2: Ground Rules. Enumeraciones para legibilidad.

### Bit-fields y Optimización

- {cite:t}`warren_hackers_2012`. Capítulo 2: Basics. Manipulación de bits y flags.

- **Fog, A.** *Optimizing Software in C++*. Technical University of Denmark.
  - Disponible en: https://www.agner.org/optimize/
  - Sección sobre layout de memoria y bit-fields.

### Estándares y Especificaciones

- **ISO/IEC 9899:2018 - C18 Standard**
  - Section 6.7.2.2: Enumeration specifiers. Definición formal.
  - Draft gratuito: http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2310.pdf

- **MISRA C:2012**. *Guidelines for the Use of the C Language in Critical Systems*.
  - Reglas específicas para enumeraciones en sistemas críticos.
  - Rule 10.3: Value of enumeration constant shall be used only in appropriate context.

### Recursos en Línea

- **C Enumerations** - https://en.cppreference.com/w/c/language/enum
  - Referencia técnica completa con ejemplos.

- **Enum Best Practices** - https://stackoverflow.com/questions/tagged/enums+c
  - Discusiones de la comunidad sobre patrones y anti-patrones.

### Herramientas

- **Doxygen** - https://www.doxygen.nl/manual/commands.html#cmddef
  - Documentación de enumeraciones con `@enum`.

- **Cppcheck** - http://cppcheck.net/
  - Análisis estático que detecta uso incorrecto de enums.
