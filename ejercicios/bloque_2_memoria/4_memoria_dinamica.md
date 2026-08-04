---
title: Ejercicios de Memoria Dinámica
short_title: 6. Memoria Dinámica
---

# Ejercicios de Memoria Dinámica

## Acerca de

A diferencia de la memoria estática (stack), la memoria dinámica (heap) nos
permite solicitar y liberar bloques de memoria en tiempo de ejecución, cuyo
tamaño puede no ser conocido al momento de compilar. Estos ejercicios se centran
en el uso correcto de `malloc`, `calloc`, `realloc` y `free` para gestionar el
ciclo de vida de arreglos, cadenas y matrices.

Para más detalles teóricos sobre la gestión de memoria dinámica, consultá [el
capítulo de Memoria
Dinámica](../../apunte/bloque_4_dinamica_interfaces/1_memoria_dinamica.md) del
apunte. Recordá aplicar la regla de estilo de la cátedra {ref}`0x3002h` para
asegurar la liberación correcta de recursos y evitar punteros colgantes.

## Arreglos Dinámicos
(ejercicio_14_1)=
### Ejercicio 14.1 - Ciclo de vida ⭐⭐☆☆☆

Implementar un par de funciones para crear y destruir un arreglo dinámico.

- `int* crear_arreglo(size_t tamano)`: Debe usar `malloc(tamano * sizeof(int))`
  para reservar un bloque de memoria contiguo para `tamano` enteros. Es crucial
  verificar si `malloc` devolvió `NULL` (indicando un fallo) antes de retornar
  el puntero.
- `void liberar_arreglo(int *arr)`: Debe llamar a `free(arr)` para devolver la
  memoria al sistema. Después de liberar, es una buena práctica asignar `NULL`
  al puntero para evitar su uso accidental (puntero colgante).
(ejercicio_14_2)=
### Ejercicio 14.2 - Duplicadora ⭐⭐☆☆☆

Implementar `int* duplicar_arreglo(const int *origen, size_t tamano)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo del mismo tamaño que el original.
2.  Verificar que la reserva de memoria fue exitosa.
3.  Recorrer el arreglo de origen y copiar cada elemento al nuevo arreglo.
4.  Retornar el puntero al nuevo arreglo.
(ejercicio_14_3)=
### Ejercicio 14.3 - Fusión de Arreglos Ordenados ⭐⭐⭐☆☆

Implementar `int* fusionar(const int *a1, size_t n1, const int *a2, size_t n2)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo de tamaño `n1 + n2`.
2.  Usar tres contadores: `i` para `a1`, `j` para `a2`, y `k` para el nuevo
    arreglo.
3.  Mientras `i < n1` y `j < n2`, comparar `a1[i]` y `a2[j]` y copiar el menor
    al nuevo arreglo, incrementando el contador correspondiente y `k`.
4.  Al salir del lazo, copiar los elementos restantes del arreglo que no se haya
    completado.
(ejercicio_14_4)=
### Ejercicio 14.4 - Inserción y Eliminación ⭐⭐☆☆☆

Crear funciones que modifiquen un arreglo dinámico. Estas operaciones son
costosas porque pueden requerir realojar toda la estructura.

- **Inserción**: Para insertar un elemento, primero se debe agrandar el arreglo
  usando `realloc`. Luego, se deben desplazar los elementos existentes (con
  `memmove`) para hacer espacio, y finalmente colocar el nuevo elemento.
- **Eliminación**: Para eliminar un elemento, se deben desplazar los elementos
  posteriores para llenar el vacío. Opcionalmente, se puede usar `realloc` para
  reducir el tamaño del bloque de memoria.

## Cadenas Dinámicas
(ejercicio_14_5)=
### Ejercicio 14.5 - Concatenación dinámica ⭐⭐⭐☆☆

Implementar `char* concatenar(const char *s1, const char *s2)`. **Algoritmo:**

1.  Calcular la longitud total necesaria: `strlen(s1) + strlen(s2) + 1` (para el
    `\0`).
2.  Reservar memoria con `malloc` para este tamaño.
3.  Copiar la primera cadena (`s1`) al nuevo bloque.
4.  Concatenar la segunda cadena (`s2`) al final.
(ejercicio_14_6)=
### Ejercicio 14.6 - Deduplicador ⭐⭐☆☆☆

Implementar `char* deduplicar(const char *s)`. Como el tamaño final es
desconocido, una estrategia de dos pasadas es robusta:

1.  **Primera pasada**: Recorrer la cadena `s` con un arreglo auxiliar de
    contadores para determinar el número de caracteres únicos y, por lo tanto,
    el tamaño de la cadena resultante.
2.  **Segunda pasada**: Reservar memoria del tamaño exacto y construir la nueva
    cadena solo con los caracteres únicos.
(ejercicio_14_7)=
### Ejercicio 14.7 - Fraccionador (Tokenizer) ⭐⭐☆☆☆

Implementar `char** dividir_cadena(const char *s, int *n_palabras)`. Esta
función devuelve un arreglo de punteros, donde cada puntero apunta a una palabra
alojada dinámicamente.

:::{mermaid}

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

:::
<!-- {mermaid} -->

**Algoritmo:**

1.  Contar el número de palabras para saber el tamaño del arreglo `char**`.
2.  Reservar memoria para este arreglo de punteros.
3.  Volver a recorrer la cadena original. Por cada palabra encontrada: a.
    Calcular su longitud. b. Reservar memoria para esa palabra. c. Copiar los
    caracteres de la palabra. d. Asignar el puntero a la nueva palabra en el
    arreglo de punteros.
4.  Terminar el arreglo de punteros con un `NULL` para facilitar su recorrido.

## Matrices Dinámicas
(ejercicio_14_8)=
### Ejercicio 14.8 - Ciclo de vida ⭐⭐☆☆☆

Implementar funciones para reservar y liberar una matriz `m x n` usando un
arreglo de punteros.

- **Reserva**: Se realiza en dos etapas. Primero se reserva el arreglo de
  punteros a las filas, y luego, en un lazo, se reserva la memoria para cada
  fila individual.
- **Liberación**: Debe seguir el orden inverso. Primero, en un lazo, se libera
  la memoria de cada fila, y finalmente se libera el arreglo que contenía los
  punteros a las filas.
(ejercicio_14_9)=
### Ejercicio 14.9 - Multiplicación ⭐⭐☆☆☆

Implementar `int** multiplicar(int **A, int m, int n, int **B, int p, int q)`.
**Algoritmo:**

1.  Verificar que la multiplicación sea posible ($n$ debe ser igual a $p$). 
2.  Reservar memoria para una nueva matriz `C` de dimensiones $m \times q$.
3.  Aplicar el algoritmo de multiplicación de matrices para calcular cada
    elemento $c_{ij}$ y almacenarlo en la nueva matriz. $$ c_{ij} =
    \sum_{k=1}^{n} a_{ik} \cdot b_{kj} $$
4.  Retornar el puntero a la matriz `C`.
(ejercicio_14_10)=
## Ejercicio 14.10 - s Adicionales ⭐⭐☆☆☆

(ejercicio_14_11)=
### Ejercicio 14.11 - Redimensionar Arreglo ⭐⭐⭐☆☆

Implementar una función `int* redimensionar_arreglo(int* arr, size_t
nuevo_tamano)` que utilice `realloc` para cambiar el tamaño de un arreglo
dinámico. La función debe manejar tanto la expansión como la contracción del
arreglo y gestionar posibles fallos de `realloc`.
(ejercicio_14_12)=
### Ejercicio 14.12 - Vector de Crecimiento Dinámico ⭐⭐⭐☆☆

Implementar una estructura `vector_t` que simule un `std::vector` de C++. Debe
contener un puntero a los datos, un tamaño (`size`) y una capacidad
(`capacity`). Crear funciones para:
- `vector_crear()`: Inicializa un vector vacío.
- `vector_push_back(vector_t* v, int dato)`: Añade un elemento al final. Si
  `size == capacity`, debe duplicar la capacidad usando `realloc`.
- `vector_destruir(vector_t* v)`: Libera toda la memoria.
(ejercicio_14_13)=
### Ejercicio 14.13 - Leer Archivo a Cadena Dinámica ⭐⭐⭐☆☆

Escribir una función `char* leer_archivo_completo(const char* ruta)` que lea
todo el contenido de un archivo de texto y lo devuelva en una única cadena
alojada dinámicamente. El tamaño del archivo no se conoce de antemano.
(ejercicio_14_14)=
### Ejercicio 14.14 - Matriz Triangular Dinámica ⭐⭐⭐☆☆

Crear una función que reserve memoria para una matriz triangular inferior. Cada
fila `i` debe tener `i+1` columnas. La función debe devolver un `int**` y se
debe implementar su correspondiente función de liberación.
(ejercicio_14_15)=
### Ejercicio 14.15 - strdup Propio ⭐⭐☆☆☆

Implementar su propia versión de la función no estándar `strdup`, que recibe una
cadena y devuelve un puntero a una nueva cadena en memoria dinámica con el mismo
contenido.

`char* mi_strdup(const char* s);`
(ejercicio_14_16)=
### Ejercicio 14.16 - calloc vs. malloc ⭐⭐☆☆☆

Escribir un programa que reserve dos arreglos de enteros del mismo tamaño, uno
con `malloc` y otro con `calloc`. Imprimir el contenido de ambos arreglos
inmediatamente después de la reserva para demostrar que `calloc` inicializa la
memoria a cero.
(ejercicio_14_17)=
### Ejercicio 14.17 - Concatenar Múltiples Cadenas ⭐⭐⭐☆☆

Escribir una función `char* concatenar_muchas(char** cadenas, int n_cadenas)`
que reciba un arreglo de cadenas y las una todas en una sola cadena dinámica,
separadas por un espacio.
(ejercicio_14_18)=
### Ejercicio 14.18 - Clonación Profunda de Struct ⭐⭐⭐☆☆

Definir una `struct` que contenga miembros de tipo puntero (ej. `char* nombre`,
`int* notas`). Escribir una función de "clonación profunda" que cree una copia
completamente nueva e independiente de la `struct`, incluyendo la reserva de
nueva memoria para los datos a los que apuntan los punteros.
(ejercicio_14_19)=
### Ejercicio 14.19 - Particionar Arreglo Dinámicamente ⭐⭐⭐☆☆

Escribir una función que reciba un arreglo dinámico y lo divida en dos nuevos
arreglos dinámicos: uno con los números pares y otro con los impares. La función
debe devolver estos dos nuevos arreglos (por ejemplo, a través de punteros por
referencia).
(ejercicio_14_20)=
### Ejercicio 14.20 - Historial de Comandos ⭐⭐☆☆☆

Crear un programa que lea líneas de texto desde la entrada estándar y las
almacene en un "historial" (un arreglo dinámico de cadenas `char**`). El
historial debe crecer dinámicamente a medida que se añaden comandos.
(ejercicio_14_21)=
### Ejercicio 14.21 - Matriz Irregular (Ragged Array) ⭐⭐⭐☆☆

Reservar memoria para una matriz dinámica donde cada fila puede tener un número
diferente de columnas. Las dimensiones (número de columnas de cada fila) se
deben leer de un arreglo de configuración.
(ejercicio_14_22)=
### Ejercicio 14.22 - Liberación Profunda ⭐⭐☆☆☆

Escribir una función `void liberar_historial(char** historial, int n_comandos)`
que libere correctamente toda la memoria utilizada por la estructura del
ejercicio 1.19: primero la memoria de cada cadena individual y luego la memoria
del arreglo de punteros.
(ejercicio_14_23)=
### Ejercicio 14.23 - Buffer de Lectura Dinámico ⭐⭐⭐☆☆

Crear una función que lea una línea completa desde `stdin` (hasta el salto de
línea), alojando dinámicamente la memoria necesaria para la línea sin imponer un
límite de tamaño predefinido. La función podría empezar con un buffer pequeño y
usar `realloc` para agrandarlo según sea necesario.
(ejercicio_14_24)=
### Ejercicio 14.24 - Lista de Compras Dinámica ⭐⭐⭐☆☆

Crear un programa interactivo que permita al usuario gestionar una lista de
compras. Las opciones deben ser:
1. Añadir producto (cadena dinámica).
2. Eliminar producto.
3. Mostrar lista.
La lista debe ser un arreglo de `char*` que se ajuste dinámicamente.
(ejercicio_14_25)=
### Ejercicio 14.25 - Manejo de Errores de malloc ⭐⭐☆☆☆

Modificar uno de los ejercicios anteriores (ej. 1.2, Duplicadora) para que, si
`malloc` o `realloc` devuelven `NULL`, el programa lo notifique con un mensaje
de error claro a `stderr` y termine de forma controlada (ej.
`exit(EXIT_FAILURE)`), en lugar de fallar por desreferenciar un puntero nulo.

## Más Ejercicios de Memoria Dinámica
(ejercicio_14_26)=
### Ejercicio 14.26 - Filtro de Arreglo Dinámico ⭐⭐⭐☆☆

Crear una función que reciba un arreglo dinámico, su tamaño y un puntero a una
función "predicado" (`bool (*pred)(int)`). La función debe devolver un **nuevo**
arreglo dinámico que contenga únicamente los elementos del arreglo original para
los cuales el predicado devuelve `true`.
(ejercicio_14_27)=
### Ejercicio 14.27 - Mapa Simple (Clave-Valor) ⭐☆☆☆☆

Implementar una estructura para un mapa simple (diccionario) que almacene pares
clave-valor (`char*`-`int`). El mapa debe usar un arreglo dinámico de `struct
par {char* clave; int valor;}`. La tabla debe crecer usando `realloc` cuando se
quede sin espacio.
(ejercicio_14_28)=
### Ejercicio 14.28 - Unir Líneas de Archivo ⭐⭐☆☆☆

Escribir un programa que lea todas las líneas de un archivo y las almacene en un
arreglo dinámico de cadenas (`char**`). Luego, crear una función que una todas
estas cadenas en una sola, separadas por un espacio, y la devuelva como una
nueva cadena dinámica.
(ejercicio_14_29)=
### Ejercicio 14.29 - Sub-arreglo Dinámico ⭐⭐⭐☆☆

Crear una función `int* sub_arreglo(const int* arr, size_t inicio, size_t fin)`
que devuelva un nuevo arreglo dinámico conteniendo una copia de los elementos
del arreglo original desde el índice `inicio` hasta `fin-1`.
(ejercicio_14_30)=
### Ejercicio 14.30 - Matriz Dinámica en Bloque Contiguo ⭐⭐⭐☆☆

Implementar la creación y liberación de una matriz `M x N` de dos formas:
1.  Como un arreglo de punteros a filas (el método tradicional).
2.  Como un único bloque de memoria contigua de `M*N` elementos, y un arreglo de
    punteros `int**` donde cada puntero `[i]` se calcula para que apunte a la
    fila `i` dentro del bloque contiguo. Comparar la complejidad de liberación
    de ambas.
(ejercicio_14_31)=
### Ejercicio 14.31 - realloc con NULL ⭐⭐☆☆☆

Escribir un pequeño programa que demuestre que `realloc(NULL, n)` se comporta de
manera idéntica a `malloc(n)`. Verificar que la memoria se asigna correctamente.
(ejercicio_14_32)=
### Ejercicio 14.32 - realloc con Tamaño Cero ⭐⭐☆☆☆

Escribir un pequeño programa que demuestre que `realloc(ptr, 0)` se comporta de
manera idéntica a `free(ptr)`. Verificar que el puntero original ya no es válido
después de la operación.
(ejercicio_14_33)=
### Ejercicio 14.33 - Arreglo Dinámico de Structs ⭐⭐⭐☆☆

Alojar dinámicamente un arreglo de `structs` (ej. `producto_t` de un ejercicio
anterior). Implementar funciones para añadir y buscar elementos en este arreglo,
usando `realloc` para expandir el arreglo cuando sea necesario.
(ejercicio_14_34)=
### Ejercicio 14.34 - Implementar getline ⭐⭐☆☆☆

Implementar una versión simplificada de la función `getline` de POSIX. La
función `ssize_t mi_getline(char **lineptr, size_t *n, FILE *stream)` debe leer
una línea de `stream`, almacenarla en un buffer apuntado por `*lineptr` y
expandir dicho buffer con `realloc` si es necesario.
(ejercicio_14_35)=
### Ejercicio 14.35 - Pila (Stack) Dinámica ⭐⭐⭐☆☆

Implementar una Pila (Stack) usando un arreglo dinámico. La estructura debe
tener capacidad y tamaño. Cuando la pila se llena, su capacidad debe duplicarse.
Cuando el tamaño es un cuarto de la capacidad, esta debe reducirse a la mitad.
Implementar `push`, `pop` y `peek`.
(ejercicio_14_36)=
## Ejercicio 14.36 - Array Dinámico Simple ⭐☆☆☆☆

Leé un tamaño `n`, creá un array dinámico de `n` enteros, llenalo, mostralo y
liberalo.

**Orientación:**
- `int *arr = malloc(n * sizeof(int));`
- Verificá: `if (arr == NULL) return 1;`
- Al final: `free(arr);`

---
(ejercicio_14_37)=
## Ejercicio 14.37 - String Dinámico ⭐⭐☆☆☆

Leé un string de tamaño arbitrario (hasta 1000 caracteres), almacenalo
dinámicamente con el tamaño exacto.

**Orientación:**
- Leé en buffer temporal: `char temp[1001];`
- Asigná memoria exacta: `strlen(temp) + 1`
- Copiá con `strcpy`
- Liberá al final

---
(ejercicio_14_38)=
## Ejercicio 14.38 - Redimensionar Array ⭐⭐⭐☆☆

Implementá un programa que permita agregar elementos dinámicamente a un array,
redimensionándolo cuando se llene.

**Orientación:**
- Mantené `capacidad` actual y `tamanio` usado
- Cuando `tamanio == capacidad`, duplicá capacidad con `realloc`
- `arr = realloc(arr, nueva_capacidad * sizeof(int));`
- Verificá que `realloc` no retorne NULL

---
(ejercicio_14_39)=
## Ejercicio 14.39 - Copiar String Dinámicamente ⭐⭐⭐☆☆

Implementá `char *duplicar_string(const char *src)` que retorne una copia
dinámica.

**Orientación:**
- Calculá longitud con `strlen`
- Asigná `strlen + 1` bytes (para '\0')
- Copiá con `strcpy`
- El llamador es responsable de liberar

---
(ejercicio_14_40)=
## Ejercicio 14.40 - Concatenar Strings Dinámicamente ⭐⭐⭐☆☆

Implementá `char *concatenar(const char *s1, const char *s2)` que retorne
concatenación en memoria dinámica.

**Orientación:**
- Longitud total = `strlen(s1) + strlen(s2) + 1`
- Copiá s1 primero, luego s2
- Retorná el nuevo string

---
(ejercicio_14_41)=
## Ejercicio 14.41 - Matriz Dentada ⭐⭐⭐⭐☆

Creá una matriz donde cada fila tiene diferente cantidad de columnas.

**Orientación:**
- `int **matriz = malloc(filas * sizeof(int*));`
- Para cada fila: `matriz[i] = malloc(cols[i] * sizeof(int));`
- Liberá en orden inverso: filas primero, luego array de punteros

---
(ejercicio_14_42)=
## Ejercicio 14.42 - Lista de Strings ⭐⭐⭐⭐☆

Leé N strings y almacenalos en un array dinámico de strings.

**Orientación:**
- `char **strings = malloc(n * sizeof(char*));`
- Para cada string: asigná memoria exacta
- Liberá cada string individualmente, luego el array

---
(ejercicio_14_43)=
## Ejercicio 14.43 - Histograma Dinámico ⭐⭐⭐⭐☆

Leé números hasta EOF y creá un histograma de frecuencias (0-9).

**Orientación:**
- Asigná array dinámico de 10 enteros (inicializado a 0)
- Usá `calloc(10, sizeof(int))` para inicialización automática
- Incrementá contador según el dígito
- Mostrá histograma visual con asteriscos

---
(ejercicio_14_44)=
## Ejercicio 14.44 - Vector Dinámico (Estructura) ⭐⭐⭐⭐☆

Implementá un vector dinámico encapsulado en estructura:
``` c
typedef struct {
    int *datos;
    size_t tamanio;
    size_t capacidad;
} vector_t;
```
<!-- c -->

Funciones:
- `vector_t *crear_vector()`
- `void agregar(vector_t *v, int valor)`
- `void destruir_vector(vector_t *v)`

**Orientación:**
- `crear_vector` asigna estructura y array inicial
- `agregar` redimensiona si es necesario
- `destruir_vector` libera datos y luego estructura

---
(ejercicio_14_45)=
## Ejercicio 14.45 - Leer Archivo Completo en Memoria ⭐⭐⭐⭐☆

Leé un archivo de texto completo en memoria dinámica.

**Orientación:**
- Obtené tamaño con `fseek` y `ftell`
- Asigná `tamanio + 1` bytes
- Leé todo con `fread`
- Terminá con '\0'
- Liberá memoria al terminar

---
(ejercicio_14_46)=
## Ejercicio 14.46 - Merge de Arrays ⭐⭐⭐⭐☆

Implementá `int *merge(int *arr1, int n1, int *arr2, int n2)` que retorne un
nuevo array con ambos ordenados.

**Orientación:**
- Asigná array de tamaño `n1 + n2`
- Usá dos índices para recorrer ambos arrays
- Copiá el menor en cada paso
- Liberá los arrays originales si ya no se usan

---
(ejercicio_14_47)=
## Ejercicio 14.47 - Lista Enlazada con Memoria Dinámica ⭐⭐⭐⭐⭐

Implementá lista enlazada completamente dinámica:
``` c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;
```
<!-- c -->

Funciones:
- `nodo_t *crear_nodo(int valor)`
- `void insertar_ordenado(nodo_t **cabeza, int valor)`
- `void eliminar_valor(nodo_t **cabeza, int valor)`
- `void liberar_lista(nodo_t **cabeza)`

**Orientación:**
- Cada nodo se asigna con `malloc`
- `insertar_ordenado` encuentra posición correcta
- `eliminar_valor` busca, reenlaza y libera
- `liberar_lista` recorre y libera todos los nodos

---
(ejercicio_14_48)=
## Ejercicio 14.48 - Árbol Binario de Búsqueda ⭐⭐⭐⭐⭐

Implementá un ABB (Árbol Binario de Búsqueda):
``` c
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol *izquierdo;
    struct nodo_arbol *derecho;
} nodo_arbol_t;
```
<!-- c -->

Funciones:
- `nodo_arbol_t *insertar(nodo_arbol_t *raiz, int valor)`
- `bool buscar(nodo_arbol_t *raiz, int valor)`
- `void liberar_arbol(nodo_arbol_t *raiz)`

**Orientación:**
- Inserción recursiva: menor a izquierda, mayor a derecha
- Búsqueda recursiva similar
- Liberación: postorden (izquierdo, derecho, raíz)

---
(ejercicio_14_49)=
## Ejercicio 14.49 - Tabla Hash Simple ⭐⭐⭐⭐⭐

Implementá una tabla hash con encadenamiento:
```{code-block} c
:linenos:
typedef struct entrada {
    char *clave;
    int valor;
    struct entrada *siguiente;
} entrada_t;

typedef struct {
    entrada_t **tabla;
    size_t tamanio;
} hash_t;

```
<!-- {code-block} c -->

Funciones:
- `hash_t *crear_hash(size_t tam)`
- `void insertar(hash_t *h, const char *clave, int valor)`
- `int *buscar(hash_t *h, const char *clave)`
- `void destruir_hash(hash_t *h)`

**Orientación:**
- Función hash simple: suma de caracteres % tamaño
- Encadenamiento para colisiones
- Destruir: libera cadenas, claves, y tabla

---
(ejercicio_14_50)=
## Ejercicio 14.50 - Pool de Memoria ⭐⭐⭐⭐⭐

Implementá un allocator simple que asigna de un pool preasignado.

**Orientación:**
- Asigná bloque grande inicial con `malloc`
- Mantené puntero a espacio libre
- `pool_alloc(size)` retorna puntero y avanza
- `pool_free()` libera todo el pool de una vez
- No soporta liberación individual

---
(ejercicio_14_51)=
## Ejercicio 14.51 - Parser de CSV Dinámico ⭐⭐⭐⭐⭐

Leé un archivo CSV y almacená datos en estructura dinámica.

**Orientación:**
- Leé línea por línea con `fgets`
- Parseá con `strtok` o manualmente
- Almacená en array dinámico de estructuras
- Redimensioná si es necesario
- Liberá todo al terminar

---
(ejercicio_14_52)=
## Ejercicio 14.52 - Cache LRU ⭐⭐⭐⭐⭐

Implementá un cache LRU (Least Recently Used) con tamaño fijo.

**Orientación:**
- Usá lista doblemente enlazada + hash para O(1)
- Al acceder, mové nodo al frente
- Si está llena, eliminá el último
- Liberá al destruir cache

---
(ejercicio_14_53)=
## Ejercicio 14.53 - Grafo con Listas de Adyacencia ⭐⭐⭐⭐⭐

Implementá grafo dirigido con listas de adyacencia dinámicas.

**Orientación:**
- Array dinámico de listas (una por vértice)
- Cada lista contiene vecinos dinámicamente
- Función para agregar arista
- Liberación: cada lista, luego array

---
(ejercicio_14_54)=
## Ejercicio 14.54 - Simulador de Memoria ⭐⭐⭐⭐⭐

Implementá un simulador que registre todas las asignaciones/liberaciones.

**Orientación:**
- Envolvé `malloc` y `free`
- Mantené registro de bloques activos
- Detectá double-free y memory leaks
- Mostrá estadísticas al final

---
(ejercicio_14_55)=
## Ejercicio 14.55 - Sistema de Gestión de Memoria Personalizado ⭐⭐⭐⭐⭐

Implementá tu propio `malloc` y `free` usando `sbrk` o un buffer grande.

**Orientación:**
- Mantené lista de bloques libres/ocupados
- Algoritmo first-fit o best-fit
- Metadata en cada bloque (tamaño, ocupado)
- Coalescencia de bloques libres adyacentes

---

## Notas Finales

:::{danger} Errores Fatales a Evitar

1. **No verificar NULL:** Siempre: `if (ptr == NULL) { handle error; }`
2. **Olvidar free:** Cada `malloc` debe tener su `free` correspondiente
3. **Double free:** Liberar el mismo puntero dos veces
4. **Use after free:** Usar memoria después de liberarla
5. **Memory leak:** Perder referencias sin liberar

:::
<!-- {danger} Errores Fatales a Evitar -->

:::{tip} Herramientas de Debugging

```{code-block} bash
:linenos:
# Valgrind - detecta leaks y accesos inválidos
valgrind --leak-check=full --show-leak-kinds=all ./programa

# AddressSanitizer - más rápido, menos completo
gcc -fsanitize=address -g programa.c -o programa
./programa

# Verificar código de salida de Valgrind
valgrind ./programa
echo $?  # 0 si no hay errores

```
<!-- {code-block} bash -->

:::
<!-- {tip} Herramientas de Debugging -->

:::{note} Patrones Comunes

1. **Siempre liberar en orden inverso a asignación**
2. **Usar `calloc` para inicialización a cero**
3. **Verificar `realloc` antes de reasignar puntero original**
4. **Mantener punteros a NULL después de `free`**
5. **Encapsular estructuras dinámicas en funciones de gestión**

:::
<!-- {note} Patrones Comunes -->

Estas consignas cubren todos los aspectos de memoria dinámica: asignación
básica, redimensionamiento, estructuras complejas, gestión avanzada y prevención
de errores.

