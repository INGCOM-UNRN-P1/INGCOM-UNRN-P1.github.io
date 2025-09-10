````myst
# Guía de Memoria Dinámica en C

> _"There is no glory in malloc if you can't free."_

---

## Introducción

Bienvenidos, aprendices del arte arcano del lenguaje C. Aquí comienza vuestro viaje hacia la comprensión de uno de los aspectos más poderosos y peligrosos de C: **la memoria dinámica**. El stack es para los pusilánimes; el heap, en cambio, es territorio de guerreros. Pero antes de invocar `malloc()`, debemos entender los fundamentos.

En los programas escritos en C, existen varias formas de reservar y gestionar memoria. La memoria automática (en la pila o *stack*) se asigna y libera automáticamente cuando se entra y se sale de funciones. Pero esta memoria es limitada en tamaño y duración. Para estructuras más complejas, más grandes o que deben sobrevivir más allá del alcance de una función, usamos **memoria dinámica**, ubicada en una región llamada **heap**.

---

## ¿Qué es la memoria dinámica?

La memoria dinámica es aquella que se solicita en tiempo de ejecución, es decir, mientras el programa está en funcionamiento. No se declara con un tamaño fijo como en:

```c
int arr[100];
````

sino que se reserva con funciones especiales que permiten elegir cuántos bytes se necesitan en cada momento.

Esto permite:

- Crear estructuras de datos de tamaño variable (listas, árboles, etc.)
- Adaptar el uso de memoria según los datos disponibles en tiempo de ejecución
- Controlar la duración de la vida útil de los datos más allá del alcance de una función

---

## El Heap: tierra de memoria dinámica

El **heap** es una región de memoria controlada por el sistema operativo y gestionada por el programador. A diferencia del stack, donde los datos se organizan de forma automática y ordenada (LIFO), el heap requiere que el programador reserve (`malloc`, `calloc`) y libere (`free`) manualmente los bloques de memoria.

### Características del heap:

- **Tamaño más flexible**: su límite lo impone el sistema operativo y los recursos disponibles.
- **Accesible desde cualquier parte del programa**: los punteros a memoria dinámica pueden compartirse entre funciones.
- **Menor velocidad de acceso**: debido a la gestión dinámica y a que no se usan registros de CPU de forma directa como con el stack.

Es la herramienta más poderosa cuando se necesita flexibilidad y estructuras de datos dinámicas.

---

## Funciones para gestionar memoria dinámica

Estas son tus herramientas. Conócelas bien, porque mal utilizadas pueden causar errores sutiles y difíciles de depurar.

### `malloc(size_t size)`

Reserva un bloque de memoria sin inicializar de `size` bytes. El contenido del bloque es **indeterminado**.

```c
int *arr = malloc(10 * sizeof(int));
```

Si la reserva falla (por falta de memoria disponible), `malloc()` devuelve `NULL`. Siempre se debe verificar:

```c
if (arr == NULL) {
    // Error: no se pudo reservar memoria
}
```

### `calloc(size_t nmemb, size_t size)`

Reserva un bloque de memoria para un arreglo de `nmemb` elementos, cada uno de `size` bytes. A diferencia de `malloc()`, **inicializa toda la memoria a cero**.

```c
int *arr = calloc(10, sizeof(int)); // 10 enteros inicializados en 0
```

### `realloc(void *ptr, size_t new_size)`

Cambia el tamaño de un bloque previamente asignado, copiando su contenido al nuevo bloque. Si el nuevo tamaño es menor, el contenido sobrante se pierde. Si es mayor, el contenido nuevo queda sin inicializar.

```c
arr = realloc(arr, 20 * sizeof(int));
```

Usar `realloc()` incorrectamente puede provocar pérdida de datos. Es recomendable usar un puntero temporal:

```c
int *tmp = realloc(arr, 20 * sizeof(int));
if (tmp != NULL) {
    arr = tmp;
}
```

### `free(void *ptr)`

Libera un bloque de memoria previamente asignado. No se debe usar el puntero luego de esta llamada.

```c
free(arr);
arr = NULL; // para evitar uso posterior
```

---

## Fragmentación de memoria

El heap no es una pila ordenada. A medida que se reservan y liberan bloques de memoria de distintos tamaños, puede quedar fragmentado. Hay dos tipos principales:

### Fragmentación externa

Ocurre cuando hay suficiente memoria libre en total, pero no hay un bloque contiguo suficientemente grande como para satisfacer una nueva solicitud de memoria.

```
[###][   ][#####][   ][##][     ] <- Bloques usados y libres separados
```

Aunque sumando todos los bloques libres haya suficiente espacio, no se puede usar de forma continua.

### Fragmentación interna

Suele ocurrir debido a la alineación de memoria o por pedir más de lo necesario. Por ejemplo, si se pide 13 bytes y el sistema asigna bloques de 16 bytes por alineación, se desperdician 3 bytes.

```
malloc(13) -> se asignan 16 bytes
```

### Consecuencias

- Menor eficiencia del uso del heap
- Posible agotamiento artificial de la memoria disponible
- Dificultad para realizar asignaciones grandes en el futuro

### Estrategias del sistema para mitigar

- **First Fit**: busca el primer bloque libre adecuado
- **Best Fit**: busca el bloque más justo posible (puede ser más lento)
- **Buddy Allocator**: divide bloques en potencias de dos para facilitar la combinación al liberar

Estas estrategias pueden implementarse en el *runtime* del sistema operativo o en bibliotecas del lenguaje.

---

## Reutilización de memoria

Cuando se libera un bloque de memoria, ese espacio puede ser utilizado nuevamente por futuras llamadas a `malloc()`. Sin embargo, no se garantiza que se asigne inmediatamente.

### Importancia de la limpieza

- El contenido de la memoria liberada permanece hasta que sea sobrescrito.
- Si no se establece el puntero a `NULL`, es posible acceder accidentalmente a memoria liberada, causando errores impredecibles.

### Técnica defensiva:

```c
free(ptr);
ptr = NULL;
```

Esto evita el acceso a punteros colgantes o *dangling pointers*.

---

## Buenas prácticas del neckbeard

- **Verificá siempre los retornos** de `malloc`, `calloc`, `realloc`
- **Inicializá** la memoria si vas a usarla inmediatamente (`calloc` es ideal)
- **Liberá todo lo que reservás**, preferentemente en el orden inverso al de la asignación
- **Usá herramientas como **`` para detectar fugas y errores de uso de memoria
- **Encapsulá la gestión de memoria** en funciones para reducir el riesgo de errores (por ejemplo, crear y destruir estructuras con funciones dedicadas)

---

## Errores comunes

- **Fugas de memoria**: no se llama a `free()`
- **Punteros colgantes**: se usa un puntero después de `free()`
- **Liberar dos veces**: llamar a `free()` dos veces sobre el mismo puntero
- **Perder el puntero original con **`` si falla:

```c
// Incorrecto:
ptr = realloc(ptr, nuevo_tam); // si falla, ptr se pierde
```

```c
// Correcto:
void *tmp = realloc(ptr, nuevo_tam);
if (tmp != NULL) ptr = tmp;
```

---

## Cierre

Dominar la memoria dinámica en C es entrar en un terreno sin red de seguridad. Aquí no hay recolectores de basura ni protecciones automáticas. El poder es total, pero la responsabilidad también lo es.

**Recordá:** una mala gestión de memoria puede llevar a fallos de segmentación, corrupción de datos o problemas de seguridad (como sobreescritura de buffers o ejecución de código arbitrario).

Bienvenido al mundo real, hacker.

```c
// Hasta la próxima:
free(tu_duda);
tu_duda = NULL;
```

```
```
