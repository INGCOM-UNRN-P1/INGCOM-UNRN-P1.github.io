---
title: "Estructuras, Uniones y Campos de Bits: Un Laboratorio de Memoria en C"
short_title: "Structs, Uniones y Bit-fields"
subtitle: "Inspección, empaquetado, aliasing y ejemplos prácticos"
numbering:
  code: true
---

# Introducción: Los Ladrillos de la Memoria

En C, las **estructuras (`struct`)**, **uniones (`union`)** y **campos de bits (bit-fields)** son las herramientas fundamentales que nos permiten ir más allá de los tipos de datos básicos. Nos dan el poder de modelar entidades complejas del mundo real, optimizar el uso de la memoria hasta el nivel del bit y construir cualquier otra estructura de datos imaginable.

Dominar estos conceptos es crucial. Implica entender no solo la sintaxis, sino cómo C organiza los datos en la memoria, un conocimiento que separa a un programador novato de uno que puede escribir código eficiente, portable y robusto.

Este apunte es un laboratorio práctico. No solo explica la teoría, sino que proporciona ejemplos completos y los comandos para que puedas compilar, ejecutar e inspeccionar el comportamiento de la memoria en tu propio sistema.

> **Advertencia:** Muchos detalles de bajo nivel, como el `padding` y el orden de los bits, son **dependientes de la implementación**. Los ejemplos asumen una arquitectura común (x86_64, little-endian), pero siempre debés verificar en tu plataforma.

# 1. Estructuras (`struct`): Agrupando Datos

Una `struct` es una colección de variables (miembros) de diferentes tipos, agrupadas bajo un solo nombre.

### Declaración y `typedef`

La práctica estándar, como indica la regla {ref}`0x001Eh`, es usar `typedef` para crear un alias de tipo con el sufijo `_t`.

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
- **Operador Flecha (`->`):** Para acceder a miembros a través de un **puntero** a una `struct`.

```c
estudiante_t est;
estudiante_t *p_est = &est;

est.legajo = 54321;      // Acceso directo
p_est->promedio = 9.0f;  // Acceso mediante puntero
```

El acceso `->` es equivalente a usar `(*p_est).promedio`, se prefiere la flecha
para simplificar este uso.

### Estructuras y Memoria: Alineación y Relleno (Padding)

El compilador a puede insertar bytes de relleno (padding), que son invisibles
al programador dentro de las `struct` para alinear los miembros en direcciones
de memoria que sean múltiplos de su tamaño. Esto optimiza la velocidad de acceso
de la CPU.

El problema con esto, es que en algunos casos necesitamos un control exacto de
los bits.

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
- `b` está en el offset 4, no 1. El compilador insertó 3 bytes de padding después de `a`.
- `c` está en el offset 8.
- Se añaden 3 bytes de padding al final para que el tamaño total (12) sea múltiplo del miembro más grande (4), asegurando la alineación en arreglos.

```{exercise}
:label: ejer-layout-1
**Optimización de Padding**

Reordená los miembros de `ejemplo_padding_t` para minimizar su tamaño total. Verificá tu resultado con `sizeof`. ¿Cuál es el orden óptimo y por qué?
```
````{solution} ejer-layout-1
:class: dropdown
El orden óptimo es agrupar los miembros más pequeños: `char a; char c; int b;`.

```c
typedef struct {
    char a;     // 1 byte
    char c;     // 1 byte
    // 2 bytes de padding aquí
    int  b;     // 4 bytes
} ejemplo_optimizado_t;
// sizeof será 8
```
Al agrupar `a` y `c`, el compilador solo necesita 2 bytes de padding para alinear `b`. El tamaño total se reduce a 8 bytes.
````

---

# 2. Uniones (`union`): Un Espacio para Múltiples Propósitos

Una `union` permite que varios miembros compartan la **misma ubicación de
memoria**. Su tamaño es el de su miembro más grande. Solo un miembro puede estar
"activo" a la vez.

### El Patrón de Unión Etiquetada (Tagged Union)

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

# 3. Campos de Bits (Bit-fields): Ahorro Extremo de Memoria

Los bit-fields permiten definir miembros de una `struct` con un ancho en bits exacto, ideal para empaquetar flags o valores pequeños.

### Sintaxis y Ejemplo

```c
typedef struct {
    unsigned int activo      : 1; // 1 bit
    unsigned int modo_op     : 3; // 3 bits (valores 0-7)
    unsigned int prioridad   : 4; // 4 bits (valores 0-15)
} config_t;
```

El compilador empaquetará estos 8 bits en un solo byte (si es posible).

### Laboratorio 2: Inspección de Bit-fields

**`bitfield_inspect.c`**
```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t a : 2;
    uint8_t b : 3;
    uint8_t c : 3;
} packed_byte_t;

int main() {
    packed_byte_t data;
    data.a = 3; // 11b
    data.b = 5; // 101b
    data.c = 7; // 111b

    // Imprimimos la estructura como un solo byte
    printf("sizeof(packed_byte_t) = %zu\n", sizeof(packed_byte_t));
    printf("Byte resultante: 0x%02X\n", *(uint8_t*)&data);
    return 0;
}
```

**Compilación y Ejecución:**
```bash
gcc -std=c11 -Wall bitfield_inspect.c -o bitfield_inspect
./bitfield_inspect
```

**Análisis:**
La salida `0xFD` (o `11111101` en binario) puede parecer sorprendente. El orden en que el compilador asigna los bits dentro del byte es **implementation-defined**. No asumas un orden específico si necesitás portabilidad.

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

void imprimir_estado_paquete(uint8_t byte_estado) {
    estado_paquete_t estado = *(estado_paquete_t*)&byte_estado;

    printf("--- Estado del Paquete (0x%02X) ---\n", byte_estado);
    printf("  ACK: %s\n", estado.es_ack ? "Sí" : "No");
    printf("  FIN: %s\n", estado.es_fin ? "Sí" : "No");
    printf("  Tipo: %u\n", estado.tipo_paquete);
    printf("  Checksum: %u\n", estado.checksum);
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

# 4. Conclusión

- **`struct`**: La herramienta por defecto para agrupar datos relacionados. Entender el padding es clave para optimizar memoria.
- **`union`**: Útil para ahorrar memoria cuando los datos son mutuamente excluyentes. Usá siempre **uniones etiquetadas** para evitar errores de tipo.
- **Bit-fields**: Una técnica de optimización avanzada para empaquetar datos a nivel de bit. Poderosa, pero no portable para formatos de archivo o red.

El dominio de estas herramientas te da un control preciso sobre la representación de tus datos, una habilidad que define a un programador de C competente.
