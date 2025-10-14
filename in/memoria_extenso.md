---
title: "Memoria en C: Apunte Extendido"
short_title: "Memoria C"
subtitle: "Modelos, segmentos, stack, heap y prácticas seguras"
numbering:
  code: true
---

# Introducción

Comprender cómo funciona la **memoria** en C es esencial para escribir programas
robustos y eficientes. C expone directamente la gestión de memoria al
programador: no hay un recolector de basura automático como en otros lenguajes.
Esto brinda **flexibilidad y control**, pero también implica **responsabilidad**
—la causa más común de errores en C está relacionada con el mal uso de la
memoria.

Este apunte amplía y organiza el tema de **memoria en C**: los segmentos de un
programa, el uso de la pila (*stack*), la memoria dinámica (*heap*), los punteros
y las buenas prácticas de estilo y depuración.

---

# 1. Segmentos de memoria en un programa C

Cuando un programa en C se carga en memoria, se organizan diferentes **segmentos**:

:::{list-table} Segmentos principales de un programa en C
:header-rows: 1

* - Segmento
  - Contenido
  - Ejemplo
* - **Texto (text)**
  - Código ejecutable del programa
  - Instrucciones de funciones `main`, `printf`, etc.
* - **Datos estáticos inicializados (data)**
  - Variables globales con valor inicial distinto de cero
  - `int x = 5;`
* - **Datos estáticos no inicializados (bss)**
  - Variables globales sin inicialización explícita
  - `static int contador;`
* - **Heap**
  - Memoria dinámica gestionada en tiempo de ejecución
  - `malloc`, `calloc`, `realloc`
* - **Stack**
  - Variables locales y control de llamadas a funciones
  - Variables automáticas dentro de `main`
:::

:::{tip} Estilo
Las variables globales están prohibidas según la regla {ref}`0x000Bh`. 
Su uso en los segmentos de datos debe restringirse a casos muy justificados.
:::

---

# 2. La pila (Stack)

El *stack* es un área de memoria de crecimiento dinámico que almacena:

- Variables locales automáticas.
- Dirección de retorno de funciones.
- Parámetros pasados por valor.

### Ejemplo de uso del stack

```c
#include <stdio.h>

void f(int n)
{
    int local = n * 2;
    printf("local = %d\n", local);
}

int main(void)
{
    int x = 42;
    f(x);
    return 0;
}
```

Aquí `x` y `local` residen en el stack en marcos de activación diferentes.

:::{note}
El tamaño del stack es limitado. Una recursión infinita o arreglos automáticos
muy grandes pueden producir un **stack overflow**.
:::

---

# 3. El heap

El *heap* es la región de memoria usada para **asignación dinámica** en tiempo de
ejecución. Se administra con las funciones:

- `malloc(size_t n)` — asigna `n` bytes sin inicializar.
- `calloc(size_t nmemb, size_t size)` — asigna e inicializa a cero.
- `realloc(void *ptr, size_t n)` — redimensiona un bloque existente.
- `free(void *ptr)` — libera un bloque previamente asignado.

### Ejemplo

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n = 5;
    int *arr = malloc(n * sizeof(*arr));
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)i * 10;
    }

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
```

:::{important}
Toda memoria pedida con `malloc` debe ser liberada con `free` ({ref}`0x001Ah`).
Además, luego de `free` es buena práctica asignar `NULL` al puntero para evitar
pointers colgantes.
:::

---

# 4. Visualización de memoria

Podemos inspeccionar la memoria de un programa en ejecución con **gdb**.

### Sesión mínima

```bash
gcc -g memoria_demo.c -o memoria_demo
gdb -q ./memoria_demo
```

Dentro de `gdb`:

```gdb
break main
run
info proc mappings    # Muestra el layout de memoria del proceso
x/16xb &arr           # Inspecciona 16 bytes en hexadecimal a partir de &arr
```

---

# 5. Endianness

El **endianness** define cómo se almacenan los bytes de valores mayores a 1 byte.

- **Little endian**: el byte menos significativo se almacena primero.
- **Big endian**: el byte más significativo se almacena primero.

Ejemplo con `0x11223344` en un entero de 32 bits:

- Little endian: `44 33 22 11`
- Big endian: `11 22 33 44`

Podemos detectar el endianness en C:

```c
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t x = 0x11223344;
    unsigned char *p = (unsigned char *)&x;
    printf("Bytes: %02x %02x %02x %02x\n", p[0], p[1], p[2], p[3]);
    return 0;
}
```

---

# 6. Errores comunes en la gestión de memoria

- **Fugas (leaks):** no liberar memoria (`malloc` sin `free`).
- **Punteros colgantes:** usar memoria después de liberarla.
- **Desbordamientos:** escribir más allá de un arreglo asignado.
- **Uso de punteros no inicializados.**

Estos errores pueden detectarse con **valgrind**:

```bash
valgrind --leak-check=full ./mi_programa
```

---

# 7. Buenas prácticas

- Inicializar punteros en `NULL` ({ref}`0x0022h`).
- Documentar si una función transfiere propiedad de memoria ({ref}`0x0020h`).
- Liberar en el orden inverso al de asignación ({ref}`0x002Ah`).
- Evitar variables globales ({ref}`0x000Bh`).
- Limitar el scope de variables ({ref}`0x0011h`).

---

# 8. Ejercicio guiado

```exercise
:label: mem-ejemplo
Escribí un programa que:
1. Declare un arreglo dinámico de `double` de tamaño `n` leído desde stdin.
2. Inicialice el arreglo con los cuadrados de los índices.
3. Imprima los resultados.
4. Verificá con `valgrind` que no existan fugas de memoria.
```

```solution
:for: mem-ejemplo
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n;
    scanf("%zu", &n);
    double *arr = malloc(n * sizeof(*arr));
    if (!arr) return 1;
    for (size_t i = 0; i < n; i++) {
        arr[i] = (double)i * (double)i;
    }
    for (size_t i = 0; i < n; i++) {
        printf("%zu^2 = %.2f\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
```
```

---

# 9. Conclusión

El dominio de la memoria en C implica:

- Conocer la organización en segmentos (text, data, bss, stack, heap).
- Diferenciar variables automáticas, estáticas y dinámicas.
- Usar correctamente punteros y funciones de asignación/liberación.
- Aplicar siempre las reglas de estilo y buenas prácticas.

Con la práctica y el uso de herramientas de inspección (`gdb`, `valgrind`,
`hexdump`), la memoria deja de ser una fuente de errores misteriosos y pasa a
ser un recurso bajo control del programador.

