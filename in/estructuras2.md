---
title: "Estructuras y Uniones en C: Los Ladrillos de la Memoria"
short_title: "Las struct-uras"
subtitle: "Agrupando datos"
numbering:
  code: true
---

## Introducción: ¿Por qué necesitamos agrupar datos?

En la programación, rara vez trabajamos con datos aislados. Una persona no es
solo un nombre, es un nombre, una edad y una dirección. Un punto en un plano no
es solo un número, son dos coordenadas (`x` e `y`). C, en su núcleo, nos ofrece
tipos básicos como `int`, `float` y `char`, pero no una forma nativa de
representar estas entidades complejas.

Aquí es donde entran las **estructuras (`struct`)**. Son la herramienta que nos
brinda C para crear nuestros propios tipos de datos compuestos, agrupando
variables de diferentes tipos bajo un solo nombre. Dominar las estructuras es el
primer paso para pasar de manejar simples variables a construir sistemas de
datos complejos y organizados.

Este apunte te guiará desde la sintaxis básica hasta los detalles de bajo nivel
sobre cómo las estructuras interactúan con la memoria, y cómo se convierten en
los bloques de construcción para casi cualquier otra estructura de datos que
puedas imaginar.

## `struct`: Agrupando Datos Relacionados

Una `struct` (estructura) es una colección de una o más variables, posiblemente
de diferentes tipos, agrupadas bajo un solo nombre para un manejo conveniente.

### Sintaxis Básica y Declaración

La forma más simple de declarar una estructura es usando la palabra clave
`struct` seguida de un nombre (etiqueta) y una lista de sus miembros entre
llaves.

```c
struct punto_2d {
    int x;
    int y;
};
```

Para usarla, debemos declarar una variable de este nuevo tipo:

```c
// La palabra clave 'struct' es necesaria en la declaración
struct punto_2d p1;

// Accedemos a sus miembros con el operador punto (.)
p1.x = 10;
p1.y = 20;
```

### `typedef`: Creando Alias para Nuestros Tipos

Escribir `struct punto_2d` cada vez es {term}`verboso`. La práctica idiomática
en C es usar `typedef` para crear un alias, permitiéndonos usar el nombre del
tipo directamente.

:::{tip} Estilo

La regla {ref}`0x001Eh` establece que los tipos definidos con `typedef` deben
llevar el sufijo `_t` para identificarlos claramente como tipos.

:::

```c
typedef struct {
    int x;
    int y;
} punto_2d_t;

// Ahora podemos declarar variables de forma más limpia
punto_2d_t p2 = { 1, 2 }; // Inicialización directa
punto_2d_t p3 = { .x = 5, .y = 6 }; // Inicializadores designados
```

La inicialización designada (`.x = 5`) es preferible porque es más legible y
menos propensa a errores si el orden de los campos cambia en el futuro.

### Acceso a Miembros: `.` vs `->`

Hay dos operadores para acceder a los miembros de una estructura:

1.  **Operador Punto (`.`):** Se usa cuando trabajamos directamente con la
    variable de la estructura.
2.  **Operador Flecha (`->`):** Se usa cuando tenemos un **puntero** a una
    estructura. Es un atajo sintáctico para no tener que escribir
    `(*puntero).miembro`.

```c
punto_2d_t punto = { 10, 20 };
punto_2d_t *puntero_a_punto = &punto;

// Acceso directo
printf("Coordenada X: %d\n", punto.x);

// Acceso a través de un puntero
printf("Coordenada Y: %d\n", puntero_a_punto->y);

// La forma larga y equivalente al operador flecha
printf("Coordenada Y (equivalente): %d\n", (*puntero_a_punto).y);
```

:::{note} El uso correcto del operador de acceso mejora la claridad, en línea
con la regla {ref}`0x0000h`. :::

### Inicialización Compleja y Arrays de `struct`

Podemos declarar arreglos de estructuras y inicializarlos en bloque:

```c
punto_2d_t puntos[] = {
    { .x = 0, .y = 0 },
    { .x = 10, .y = 5 },
    { .x = -3, .y = 7 }
};
```

Accedemos igual que en cualquier arreglo:

```c
printf("Primer punto: (%d, %d)\n", puntos[0].x, puntos[0].y);
```

## Estructuras y Memoria: Alineación y Relleno (Padding)

Este es uno de los conceptos más importantes y a menudo pasados por alto. La
forma en que una `struct` se organiza en memoria no es siempre la suma del
tamaño de sus partes.

### ¿Qué es la Alineación y por qué existe?

Por razones de rendimiento, la mayoría de las arquitecturas de CPU acceden a la
memoria de forma más eficiente cuando los datos están **alineados**. Esto
significa que un dato de `N` bytes debe estar en una dirección de memoria que
sea un múltiplo de `N`.

Para cumplir con esto, el compilador de C inserta bytes de **relleno (padding)**
invisibles dentro de las estructuras.

Consideremos esta estructura:

```c
typedef struct {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
} ejemplo_padding_t;
```

Uno podría esperar que `sizeof(ejemplo_padding_t)` fuera `1 + 4 + 1 = 6` bytes.
Sin embargo, lo más probable es que sea **12 bytes** en una arquitectura de 64
bits. ¿Por qué?

- `char a`: Ocupa 1 byte.
- **Relleno**: El compilador inserta 3 bytes de relleno para que el siguiente
  miembro (`int b`) comience en una dirección múltiplo de 4.
- `int b`: Ocupa 4 bytes.
- `char c`: Ocupa 1 byte.
- **Relleno final**: La estructura completa también debe tener un tamaño que sea
  múltiplo de su miembro más grande (en este caso, 4 bytes del `int`). Para que
  un arreglo de estas estructuras mantenga la alineación, el compilador añade 3
  bytes de relleno al final, llevando el tamaño total a 12.

### Controlando el Relleno: `#pragma pack`

Cuando interactuamos con formatos de archivo o protocolos de red, estos bytes de
relleno son inaceptables, ya que el formato espera una secuencia de bytes
exacta. Para esto, usamos `#pragma pack`.

```c
#pragma pack(push, 1)
typedef struct {
    char a;
    int b;
    char c;
} ejemplo_compacto_t;
#pragma pack(pop)
```

- `#pragma pack(push, 1)`: Le dice al compilador que guarde la configuración de
  alineación actual y empiece a alinear los siguientes miembros en límites de
  **1 byte**, eliminando efectivamente todo el relleno.
- `#pragma pack(pop)`: Restaura la configuración de alineación original.

Este es el método que usamos en el apunte sobre [mapas de bits](./bitmaps.md)
para asegurar que las cabeceras del archivo BMP se escriban correctamente.

## `union`: Compartiendo un Mismo Espacio

Una `union` es similar a una `struct`, pero con una diferencia fundamental:
todos sus miembros **comparten la misma ubicación de memoria**. El tamaño de la
`union` es el tamaño de su miembro más grande.

Esto significa que solo podés usar **un miembro a la vez**. Escribir en un
miembro sobrescribirá los datos de los demás.

```c
typedef union {
    int i;
    float f;
    char c[4];
} dato_t;

dato_t mi_dato;
mi_dato.i = 1094861636; // En binario: 01000001 01000010 01000011 01000100

printf("Entero: %d\n", mi_dato.i);
printf("Cadena: %s\n", mi_dato.c); // Imprime "ABCD"

mi_dato.f = 3.14f;
// ¡Ahora mi_dato.i y mi_dato.c contienen basura!
```

### El Uso Seguro: Uniones Etiquetadas (Tagged Unions)

Debido a su naturaleza, usar una `union` de forma segura requiere saber qué tipo
de dato está almacenado en ella en un momento dado. El patrón más común y seguro
es la **unión etiquetada**, que combina una `union` con un `enum` dentro de una
`struct`.

```c
typedef enum {
    TIPO_ENTERO,
    TIPO_FLOTANTE,
    TIPO_CADENA
} tipo_valor_t;

typedef struct {
    tipo_valor_t tipo;
    union {
        int   entero;
        float flotante;
        char* cadena;
    } valor;
} variante_t;

void imprimir_variante(const variante_t *v) {
    switch (v->tipo) {
        case TIPO_ENTERO:
            printf("Entero: %d\n", v->valor.entero);
            break;
        case TIPO_FLOTANTE:
            printf("Flotante: %f\n", v->valor.flotante);
            break;
        case TIPO_CADENA:
            printf("Cadena: %s\n", v->valor.cadena);
            break;
    }
}
```

Este patrón permite crear variables que pueden contener diferentes tipos de
datos de forma segura, un concepto fundamental en lenguajes de tipado dinámico.

## `struct` como Bloques de Construcción

La verdadera potencia de las `struct` se revela cuando se usan para construir
estructuras de datos dinámicas y complejas. La clave es su capacidad de
**auto-referencia** a través de punteros.

### Listas Enlazadas

Una lista enlazada es una secuencia de nodos, donde cada nodo contiene un dato y
un puntero al siguiente nodo. Sin `struct`, esto sería imposible de representar
en C.

```c
typedef struct nodo_lista {
    int dato;
    struct nodo_lista *siguiente; // Puntero a una estructura del mismo tipo
} nodo_lista_t;
```

### Árboles Binarios

De forma similar, un nodo de un árbol binario necesita un dato y punteros a sus
dos hijos.

```c
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol *izquierda;
    struct nodo_arbol *derecha;
} nodo_arbol_t;
```

Estas definiciones son la base para implementar casi cualquier estructura de
datos avanzada, desde pilas y colas hasta grafos y tablas de hash.

## Buenas Prácticas y Estilo

- Usar `typedef` con sufijo `_t` para nuevos tipos ({ref}`0x001Eh`).
- Inicializar siempre las estructuras ({ref}`0x0003h`).
- Documentar con `@param`, `@returns`, etc. ({ref}`0x000Ah`).
- Mantener la responsabilidad única ({ref}`0x000Ch`).

## Ejercicios

```exercise
:label: ejercicio-struct
Definí una estructura `persona_t` con nombre, edad y altura. Creá un arreglo de 3 personas e inicializalo.
```

````solution
:for: ejercicio-struct
```c
typedef struct {
    char nombre[50];
    int edad;
    float altura;
} persona_t;

persona_t grupo[3] = {
    { "Ana", 20, 1.65f },
    { "Luis", 25, 1.80f },
    { "Marta", 30, 1.70f }
};
```
````

## Conclusión

Las `struct` y `union` son mucho más que simples agrupaciones de variables. Son
la herramienta principal que C nos ofrece para modelar el mundo real y para
gestionar la memoria de forma estructurada y significativa. Entender cómo
funcionan internamente, incluyendo los detalles de alineación y relleno,
permiten guardar información compleja de una forma eficiente.

## Glosario

:::{glossary}

Verboso : Calificativo para la sintaxis de código que resulta innecesariamente
larga.

Padding : Bytes adicionales insertados por el compilador para alinear los datos.

Tagged Union : Patrón que combina `enum` y `union` para un uso seguro y tipado.

:::
