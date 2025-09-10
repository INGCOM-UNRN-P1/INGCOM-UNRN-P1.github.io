```{title}
```

```{note}
Autor: Profesor Neckbeard, gurú de C y el stack manual
```

## Introducción

En C, las estructuras (`struct`) y uniones (`union`) son herramientas fundamentales para agrupar datos relacionados bajo un mismo identificador. Nos permiten construir tipos compuestos, organizar la memoria de forma eficiente y emular ciertas capacidades de lenguajes orientados a objetos.

Esta guía se enfoca exclusivamente en estas construcciones, explicando tanto su sintaxis como su semántica, comportamiento de memoria, alineación, padding y usos idiomáticos. Los ejemplos incluyen explicaciones detalladas para que comprendas no solo cómo se escribe, sino por qué se hace así.

---

## 1. `struct`: Definición y uso básico

Una `struct` (estructura) agrupa varias variables bajo un mismo nombre, formando un nuevo tipo. Cada campo de la estructura puede tener un tipo diferente, lo cual la hace ideal para representar entidades con atributos heterogéneos.

```c
struct Punto {
    int x;
    int y;
};

struct Punto p1;
p1.x = 10;
p1.y = 20;
```

> En este ejemplo, `Punto` representa un punto en el plano cartesiano con coordenadas `x` e `y`. Cada campo se accede mediante el operador punto (`.`).

Puedes declarar e inicializar al mismo tiempo:

```c
struct Punto p2 = { .x = 1, .y = 2 };
```

> La sintaxis con inicializadores nombrados mejora la legibilidad y evita errores en el orden.

También puedes usar `typedef` para evitar repetir `struct` constantemente:

```c
typedef struct Punto {
    int x;
    int y;
} Punto;

Punto p3 = {5, 6};
```

> `typedef` permite crear un alias de tipo. En este caso, `Punto` se puede usar como nombre de tipo directamente, como si fuera `int` o `float`.

---

## 2. Acceso y asignación

Las estructuras pueden ser copiadas, accedidas por puntero o manipuladas campo a campo.

```c
Punto a = {1, 2};
Punto b = a; // Copia miembro a miembro
```

> Esto copia cada campo de `a` en `b`. Es una copia superficial (shallow copy), suficiente para tipos primitivos.

```c
Punto *ptr = &a;
printf("%d", ptr->x);  // Acceso con ->
printf("%d", (*ptr).y); // Acceso con . y desreferenciación
```

> Cuando tenemos un puntero a una estructura, usamos `->` para acceder a los miembros. Alternativamente, podemos desreferenciar con `*` y luego usar `.`.

---

## 3. `struct` anidadas

Una estructura puede contener otras estructuras como campos:

```c
struct Recta {
    Punto inicio;
    Punto fin;
};

struct Recta r = {{0, 0}, {10, 10}};
printf("(%d, %d) -> (%d, %d)\n", r.inicio.x, r.inicio.y, r.fin.x, r.fin.y);
```

> En este caso, `Recta` contiene dos puntos. Al anidar estructuras se facilita la representación de datos jerárquicos o compuestos.

---

## 4. Alineación y padding

### Alineación

El compilador alinea cada campo de una estructura de acuerdo con su tipo. Esto se debe a que algunas arquitecturas requieren que los datos estén alineados a ciertos múltiplos para accederlos eficientemente.

```c
struct A {
    char c;    // 1 byte
    int i;     // 4 bytes
};
```

> Aunque `char` sólo ocupa 1 byte, el `int` siguiente debe empezar en una dirección múltiplo de 4. Por eso se insertan 3 bytes de relleno.

### Controlar padding

Ordenar campos de mayor a menor alineación reduce padding:

```c
struct B {
    int i;
    char c;
};
```

> Este orden reduce el relleno, ya que `int` aparece primero. Aunque el tamaño total sigue siendo 8, la estructura está más alineada y puede optimizar el acceso.

---

## 5. `union`: Memoria compartida

Una `union` permite definir varias variables que comparten la misma región de memoria. Sólo una puede usarse a la vez:

```c
union Dato {
    int i;
    float f;
    char c;
};

union Dato d;
d.i = 42;
printf("%d\n", d.i); // Válido
```

> Asignar luego otro campo sobrescribe el anterior:

```c
d.f = 3.14; // Ahora d.i tiene valor indefinido
```

> Las uniones se usan cuando sólo se necesita uno de varios tipos en un momento determinado, y se desea ahorrar memoria.

### Uso típico

Implementar tipos variantes (similar a enums con payload):

```c
typedef struct {
    enum { INT, FLOAT, CHAR } tipo;
    union {
        int i;
        float f;
        char c;
    } valor;
} Variante;

Variante v;
v.tipo = FLOAT;
v.valor.f = 3.14f;
```

> Esta técnica permite emular polimorfismo simple, controlando qué tipo está activo mediante una etiqueta (`tipo`).

---

## 6. Alineación en uniones

Una `union` tiene el tamaño del miembro más grande y una alineación compatible con todos sus miembros.

```c
union U {
    char c;   // 1 byte
    int i;    // 4 bytes
    double d; // 8 bytes
};
```

> Tamaño de `U` será 8 bytes, con alineación de `double` (8 bytes usualmente). Esto garantiza que cualquier campo se pueda usar sin provocar fallos de alineación.

---

## 7. Comparación entre `struct` y `union`

| Característica    | `struct`           | `union`                 |
| ----------------- | ------------------ | ----------------------- |
| Memoria usada     | Suma de los campos | Tamaño del más grande   |
| Acceso simultáneo | Todos los campos   | Sólo uno a la vez       |
| Uso típico        | Datos relacionados | Representación variante |

> Esta tabla resume las diferencias clave. Las estructuras son ideales para representar entidades completas, mientras que las uniones sirven para representar datos que pueden adoptar diferentes formas.

---

## 8. Inicialización

### `struct`:

```c
Punto p = {1, 2};
```

> Asigna `x = 1`, `y = 2` en orden de declaración.

### `union`:

```c
union Dato d = {.i = 42};
```

> Inicializa el campo `i`, los demás quedan indeterminados.

---

## 9. Estructuras y funciones

Las estructuras pueden ser:

- Pasadas por valor (copia completa)
- Modificadas por referencia (usando punteros)

```c
void mover(Punto *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
```

> Usar punteros permite modificar la estructura original dentro de la función. Si se pasa por valor, se trabaja con una copia y no afecta el original.

---

## 10. Idiomas del hacker: uso idiomático

- *Tagged Unions*: combinar `enum` + `union` para tipos polimórficos
- *Bit fields*: definir campos de bits para manejar flags o estructuras de red

```c
struct Flags {
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int reservado : 6;
};
```

> Esto define una estructura de 8 bits, con dos flags y 6 bits reservados. Es muy usado en protocolos o controladores.

- *Structs empaquetadas* para IO, redes, dispositivos

```c
#pragma pack(push, 1)
struct CabeceraRed {
    uint8_t tipo;
    uint16_t longitud;
};
#pragma pack(pop)
```

> Esto elimina padding, importante cuando los datos deben coincidir byte a byte con un formato externo.

---

## 11. Buenas prácticas

- Siempre inicializá estructuras para evitar basura
- Preferí `typedef` para claridad en tipos
- Documentá cada campo de una estructura para que su significado sea claro
- En `union`, usá una etiqueta (`enum`) para rastrear el campo activo
- Tené en cuenta la alineación si hacés IO binaria, estructuras en red o dispositivos

---

## Conclusión

Las `struct` y `union` en C son herramientas poderosas. Aprender a dominarlas no solo mejora la calidad de tu código, sino que también te da el control fino sobre la memoria que C promete. Como diría cualquier hacker veterano: *"si no entendés la memoria, no entendés C"*.

```{admonition}
En el futuro exploraremos cómo combinar estructuras con memoria dinámica para construir listas enlazadas, árboles y más.
```

