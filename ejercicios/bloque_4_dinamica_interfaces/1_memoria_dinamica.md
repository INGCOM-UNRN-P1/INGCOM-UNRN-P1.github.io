---
title: Ejercicios de Memoria Dinámica
short_title: 6. Memoria Dinámica
---

# Ejercicios de Memoria Dinámica

## Acerca de

A diferencia de la memoria estática (stack), la memoria dinámica (heap) nos permite solicitar y liberar bloques de memoria en tiempo de ejecución, cuyo tamaño puede no ser conocido al momento de compilar. Estos ejercicios se centran en el uso correcto de `malloc`, `calloc`, `realloc` y `free` para gestionar el ciclo de vida de arreglos, cadenas y matrices.

Para más detalles teóricos sobre la gestión de memoria dinámica, consultá [el capítulo de Memoria Dinámica](../../apunte/bloque_4_dinamica_interfaces/1_memoria_dinamica.md) del apunte. Recordá aplicar la regla de estilo de la cátedra {ref}`0x3002h` para asegurar la liberación correcta de recursos y evitar punteros colgantes.

## Arreglos Dinámicos

### Ejercicio 1.1 - Ciclo de vida

Implementar un par de funciones para crear y destruir un arreglo dinámico.

- `int* crear_arreglo(size_t tamano)`: Debe usar `malloc(tamano * sizeof(int))` para reservar un bloque de memoria contiguo para `tamano` enteros. Es crucial verificar si `malloc` devolvió `NULL` (indicando un fallo) antes de retornar el puntero.
- `void liberar_arreglo(int *arr)`: Debe llamar a `free(arr)` para devolver la memoria al sistema. Después de liberar, es una buena práctica asignar `NULL` al puntero para evitar su uso accidental (puntero colgante).

### Ejercicio 1.2 - Duplicadora

Implementar `int* duplicar_arreglo(const int *origen, size_t tamano)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo del mismo tamaño que el original.
2.  Verificar que la reserva de memoria fue exitosa.
3.  Recorrer el arreglo de origen y copiar cada elemento al nuevo arreglo.
4.  Retornar el puntero al nuevo arreglo.

### Ejercicio 1.3 - Fusión de Arreglos Ordenados

Implementar `int* fusionar(const int *a1, size_t n1, const int *a2, size_t n2)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo de tamaño `n1 + n2`.
2.  Usar tres contadores: `i` para `a1`, `j` para `a2`, y `k` para el nuevo arreglo.
3.  Mientras `i < n1` y `j < n2`, comparar `a1[i]` y `a2[j]` y copiar el menor al nuevo arreglo, incrementando el contador correspondiente y `k`.
4.  Al salir del lazo, copiar los elementos restantes del arreglo que no se haya completado.

### Ejercicio 1.4 - Inserción y Eliminación

Crear funciones que modifiquen un arreglo dinámico. Estas operaciones son costosas porque pueden requerir realojar toda la estructura.

- **Inserción**: Para insertar un elemento, primero se debe agrandar el arreglo usando `realloc`. Luego, se deben desplazar los elementos existentes (con `memmove`) para hacer espacio, y finalmente colocar el nuevo elemento.
- **Eliminación**: Para eliminar un elemento, se deben desplazar los elementos posteriores para llenar el vacío. Opcionalmente, se puede usar `realloc` para reducir el tamaño del bloque de memoria.

## Cadenas Dinámicas

### Ejercicio 1.5 - Concatenación dinámica

Implementar `char* concatenar(const char *s1, const char *s2)`. **Algoritmo:**

1.  Calcular la longitud total necesaria: `strlen(s1) + strlen(s2) + 1` (para el `\0`).
2.  Reservar memoria con `malloc` para este tamaño.
3.  Copiar la primera cadena (`s1`) al nuevo bloque.
4.  Concatenar la segunda cadena (`s2`) al final.

### Ejercicio 1.6 - Deduplicador

Implementar `char* deduplicar(const char *s)`. Como el tamaño final es desconocido, una estrategia de dos pasadas es robusta:

1.  **Primera pasada**: Recorrer la cadena `s` con un arreglo auxiliar de contadores para determinar el número de caracteres únicos y, por lo tanto, el tamaño de la cadena resultante.
2.  **Segunda pasada**: Reservar memoria del tamaño exacto y construir la nueva cadena solo con los caracteres únicos.

### Ejercicio 1.7 - Fraccionador (Tokenizer)

Implementar `char** dividir_cadena(const char *s, int *n_palabras)`. Esta función devuelve un arreglo de punteros, donde cada puntero apunta a una palabra alojada dinámicamente.

```{mermaid}
flowchart TD
    subgraph Heap
        H["Hola"]
        M["Mundo"]
    end
    subgraph "Arreglo de Punteros"
        P1["ptr[0]"]
        P2["ptr[1]"]
        P3["ptr[2]"]
    end
    Main["char** resultado"] --> P1
    P1 --> H
    P2 --> M
    P3 --> NUL["NULL"]
```

**Algoritmo:**

1.  Contar el número de palabras para saber el tamaño del arreglo `char**`.
2.  Reservar memoria para este arreglo de punteros.
3.  Volver a recorrer la cadena original. Por cada palabra encontrada: a. Calcular su longitud. b. Reservar memoria para esa palabra. c. Copiar los caracteres de la palabra. d. Asignar el puntero a la nueva palabra en el arreglo de punteros.
4.  Terminar el arreglo de punteros con un `NULL` para facilitar su recorrido.

## Matrices Dinámicas

### Ejercicio 1.8 - Ciclo de vida

Implementar funciones para reservar y liberar una matriz `m x n` usando un arreglo de punteros.

- **Reserva**: Se realiza en dos etapas. Primero se reserva el arreglo de punteros a las filas, y luego, en un lazo, se reserva la memoria para cada fila individual.
- **Liberación**: Debe seguir el orden inverso. Primero, en un lazo, se libera la memoria de cada fila, y finalmente se libera el arreglo que contenía los punteros a las filas.

### Ejercicio 1.9 - Multiplicación

Implementar `int** multiplicar(int **A, int m, int n, int **B, int p, int q)`.
**Algoritmo:**

1.  Verificar que la multiplicación sea posible ($n$ debe ser igual a $p$). 
2.  Reservar memoria para una nueva matriz `C` de dimensiones $m \times q$.
3.  Aplicar el algoritmo de multiplicación de matrices para calcular cada elemento $c_{ij}$ y almacenarlo en la nueva matriz. $$ c_{ij} = \sum_{k=1}^{n} a_{ik} \cdot b_{kj} $$
4.  Retornar el puntero a la matriz `C`.

## Ejercicios Adicionales

### Ejercicio 1.10 - Redimensionar Arreglo

Implementar una función `int* redimensionar_arreglo(int* arr, size_t nuevo_tamano)` que utilice `realloc` para cambiar el tamaño de un arreglo dinámico. La función debe manejar tanto la expansión como la contracción del arreglo y gestionar posibles fallos de `realloc`.

### Ejercicio 1.11 - Vector de Crecimiento Dinámico

Implementar una estructura `vector_t` que simule un `std::vector` de C++. Debe contener un puntero a los datos, un tamaño (`size`) y una capacidad (`capacity`). Crear funciones para:
- `vector_crear()`: Inicializa un vector vacío.
- `vector_push_back(vector_t* v, int dato)`: Añade un elemento al final. Si `size == capacity`, debe duplicar la capacidad usando `realloc`.
- `vector_destruir(vector_t* v)`: Libera toda la memoria.

### Ejercicio 1.12 - Leer Archivo a Cadena Dinámica

Escribir una función `char* leer_archivo_completo(const char* ruta)` que lea todo el contenido de un archivo de texto y lo devuelva en una única cadena alojada dinámicamente. El tamaño del archivo no se conoce de antemano.

### Ejercicio 1.13 - Matriz Triangular Dinámica

Crear una función que reserve memoria para una matriz triangular inferior. Cada fila `i` debe tener `i+1` columnas. La función debe devolver un `int**` y se debe implementar su correspondiente función de liberación.

### Ejercicio 1.14 - strdup Propio

Implementar su propia versión de la función no estándar `strdup`, que recibe una cadena y devuelve un puntero a una nueva cadena en memoria dinámica con el mismo contenido.

`char* mi_strdup(const char* s);`

### Ejercicio 1.15 - calloc vs. malloc

Escribir un programa que reserve dos arreglos de enteros del mismo tamaño, uno con `malloc` y otro con `calloc`. Imprimir el contenido de ambos arreglos inmediatamente después de la reserva para demostrar que `calloc` inicializa la memoria a cero.

### Ejercicio 1.16 - Concatenar Múltiples Cadenas

Escribir una función `char* concatenar_muchas(char** cadenas, int n_cadenas)` que reciba un arreglo de cadenas y las una todas en una sola cadena dinámica, separadas por un espacio.

### Ejercicio 1.17 - Clonación Profunda de Struct

Definir una `struct` que contenga miembros de tipo puntero (ej. `char* nombre`, `int* notas`). Escribir una función de "clonación profunda" que cree una copia completamente nueva e independiente de la `struct`, incluyendo la reserva de nueva memoria para los datos a los que apuntan los punteros.

### Ejercicio 1.18 - Particionar Arreglo Dinámicamente

Escribir una función que reciba un arreglo dinámico y lo divida en dos nuevos arreglos dinámicos: uno con los números pares y otro con los impares. La función debe devolver estos dos nuevos arreglos (por ejemplo, a través de punteros por referencia).

### Ejercicio 1.19 - Historial de Comandos

Crear un programa que lea líneas de texto desde la entrada estándar y las almacene en un "historial" (un arreglo dinámico de cadenas `char**`). El historial debe crecer dinámicamente a medida que se añaden comandos.

### Ejercicio 1.20 - Matriz Irregular (Ragged Array)

Reservar memoria para una matriz dinámica donde cada fila puede tener un número diferente de columnas. Las dimensiones (número de columnas de cada fila) se deben leer de un arreglo de configuración.

### Ejercicio 1.21 - Liberación Profunda

Escribir una función `void liberar_historial(char** historial, int n_comandos)` que libere correctamente toda la memoria utilizada por la estructura del ejercicio 1.19: primero la memoria de cada cadena individual y luego la memoria del arreglo de punteros.

### Ejercicio 1.22 - Buffer de Lectura Dinámico

Crear una función que lea una línea completa desde `stdin` (hasta el salto de línea), alojando dinámicamente la memoria necesaria para la línea sin imponer un límite de tamaño predefinido. La función podría empezar con un buffer pequeño y usar `realloc` para agrandarlo según sea necesario.

### Ejercicio 1.23 - Lista de Compras Dinámica

Crear un programa interactivo que permita al usuario gestionar una lista de compras. Las opciones deben ser:
1. Añadir producto (cadena dinámica).
2. Eliminar producto.
3. Mostrar lista.
La lista debe ser un arreglo de `char*` que se ajuste dinámicamente.

### Ejercicio 1.24 - Manejo de Errores de malloc

Modificar uno de los ejercicios anteriores (ej. 1.2, Duplicadora) para que, si `malloc` o `realloc` devuelven `NULL`, el programa lo notifique con un mensaje de error claro a `stderr` y termine de forma controlada (ej. `exit(EXIT_FAILURE)`), en lugar de fallar por desreferenciar un puntero nulo.

## Más Ejercicios de Memoria Dinámica

### Ejercicio 1.25 - Filtro de Arreglo Dinámico

Crear una función que reciba un arreglo dinámico, su tamaño y un puntero a una función "predicado" (`bool (*pred)(int)`). La función debe devolver un **nuevo** arreglo dinámico que contenga únicamente los elementos del arreglo original para los cuales el predicado devuelve `true`.

### Ejercicio 1.26 - Mapa Simple (Clave-Valor)

Implementar una estructura para un mapa simple (diccionario) que almacene pares clave-valor (`char*`-`int`). El mapa debe usar un arreglo dinámico de `struct par {char* clave; int valor;}`. La tabla debe crecer usando `realloc` cuando se quede sin espacio.

### Ejercicio 1.27 - Unir Líneas de Archivo

Escribir un programa que lea todas las líneas de un archivo y las almacene en un arreglo dinámico de cadenas (`char**`). Luego, crear una función que una todas estas cadenas en una sola, separadas por un espacio, y la devuelva como una nueva cadena dinámica.

### Ejercicio 1.28 - Sub-arreglo Dinámico

Crear una función `int* sub_arreglo(const int* arr, size_t inicio, size_t fin)` que devuelva un nuevo arreglo dinámico conteniendo una copia de los elementos del arreglo original desde el índice `inicio` hasta `fin-1`.

### Ejercicio 1.29 - Matriz Dinámica en Bloque Contiguo

Implementar la creación y liberación de una matriz `M x N` de dos formas:
1.  Como un arreglo de punteros a filas (el método tradicional).
2.  Como un único bloque de memoria contigua de `M*N` elementos, y un arreglo de punteros `int**` donde cada puntero `[i]` se calcula para que apunte a la fila `i` dentro del bloque contiguo. Comparar la complejidad de liberación de ambas.

### Ejercicio 1.30 - realloc con NULL

Escribir un pequeño programa que demuestre que `realloc(NULL, n)` se comporta de manera idéntica a `malloc(n)`. Verificar que la memoria se asigna correctamente.

### Ejercicio 1.31 - realloc con Tamaño Cero

Escribir un pequeño programa que demuestre que `realloc(ptr, 0)` se comporta de manera idéntica a `free(ptr)`. Verificar que el puntero original ya no es válido después de la operación.

### Ejercicio 1.32 - Arreglo Dinámico de Structs

Alojar dinámicamente un arreglo de `structs` (ej. `producto_t` de un ejercicio anterior). Implementar funciones para añadir y buscar elementos en este arreglo, usando `realloc` para expandir el arreglo cuando sea necesario.

### Ejercicio 1.33 - Implementar getline

Implementar una versión simplificada de la función `getline` de POSIX. La función `ssize_t mi_getline(char **lineptr, size_t *n, FILE *stream)` debe leer una línea de `stream`, almacenarla en un buffer apuntado por `*lineptr` y expandir dicho buffer con `realloc` si es necesario.

### Ejercicio 1.34 - Pila (Stack) Dinámica

Implementar una Pila (Stack) usando un arreglo dinámico. La estructura debe tener capacidad y tamaño. Cuando la pila se llena, su capacidad debe duplicarse. Cuando el tamaño es un cuarto de la capacidad, esta debe reducirse a la mitad. Implementar `push`, `pop` y `peek`.
