---
title: Ejercicios de Memoria Dinámica
short_title: 6. Memoria Dinámica
---

## Acerca de

A diferencia de la memoria estática (stack), la memoria dinámica (heap) nos
permite solicitar y liberar bloques de memoria en tiempo de ejecución, cuyo
tamaño puede no ser conocido al momento de compilar. Estos ejercicios se centran
en el uso correcto de `malloc`, `calloc`, `realloc` y `free` para gestionar el
ciclo de vida de arreglos, cadenas y matrices.

```{mermaid}
:caption: "Ciclo de vida de la memoria dinámica"
graph TD
    A(Programa) -- malloc(size) --> B(Heap: Bloque de memoria reservado);
    B -- Puntero devuelto --> A;
    A -- usa la memoria --> A;
    A -- free(puntero) --> C(Heap: Bloque liberado);
```

## 1: Arreglos Dinámicos

### 1.1: Ciclo de vida

Implementar un par de funciones para crear y destruir un arreglo dinámico.

- `int* crear_arreglo(size_t tamano)`: Debe usar `malloc(tamano * sizeof(int))`
  para reservar un bloque de memoria contiguo para `tamano` enteros. Es crucial
  verificar si `malloc` devolvió `NULL` (indicando un fallo) antes de retornar
  el puntero.
- `void liberar_arreglo(int *arr)`: Debe llamar a `free(arr)` para devolver la
  memoria al sistema. Después de liberar, es una buena práctica asignar `NULL`
  al puntero para evitar su uso accidental (puntero colgante).

### 1.2: Duplicadora

Implementar `int* duplicar_arreglo(const int *origen, size_t tamano)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo del mismo tamaño que el original.
2.  Verificar que la reserva de memoria fue exitosa.
3.  Recorrer el arreglo de origen y copiar cada elemento al nuevo arreglo.
4.  Retornar el puntero al nuevo arreglo.

### 1.3: Fusión de Arreglos Ordenados

Implementar `int* fusionar(const int *a1, size_t n1, const int *a2, size_t n2)`.
**Algoritmo:**

1.  Reservar memoria para un nuevo arreglo de tamaño `n1 + n2`.
2.  Usar tres contadores: `i` para `a1`, `j` para `a2`, y `k` para el nuevo
    arreglo.
3.  Mientras `i < n1` y `j < n2`, comparar `a1[i]` y `a2[j]` y copiar el menor
    al nuevo arreglo, incrementando el contador correspondiente y `k`.
4.  Al salir del bucle, copiar los elementos restantes del arreglo que no se
    haya completado.

### 1.4: Inserción y Eliminación

Crear funciones que modifiquen un arreglo dinámico. Estas operaciones son
costosas porque pueden requerir realojar toda la estructura.

- **Inserción**: Para insertar un elemento, primero se debe agrandar el arreglo
  usando `realloc`. Luego, se deben desplazar los elementos existentes (con
  `memmove`) para hacer espacio, y finalmente colocar el nuevo elemento.
- **Eliminación**: Para eliminar un elemento, se deben desplazar los elementos
  posteriores para llenar el vacío. Opcionalmente, se puede usar `realloc` para
  reducir el tamaño del bloque de memoria.

## 2: Cadenas Dinámicas

### 2.1: Concatenación dinámica

Implementar `char* concatenar(const char *s1, const char *s2)`. **Algoritmo:**

1.  Calcular la longitud total necesaria: `strlen(s1) + strlen(s2) + 1` (para el
    `\0`).
2.  Reservar memoria con `malloc` para este tamaño.
3.  Copiar la primera cadena (`s1`) al nuevo bloque.
4.  Concatenar la segunda cadena (`s2`) al final.

### 2.2: Deduplicador

Implementar `char* deduplicar(const char *s)`. Como el tamaño final es
desconocido, una estrategia de dos pasadas es robusta:

1.  **Primera pasada**: Recorrer la cadena `s` con un arreglo auxiliar de
    contadores para determinar el número de caracteres únicos y, por lo tanto,
    el tamaño de la cadena resultante.
2.  **Segunda pasada**: Reservar memoria del tamaño exacto y construir la nueva
    cadena solo con los caracteres únicos.

### 2.3: Fraccionador (Tokenizer)

Implementar `char** dividir_cadena(const char *s, int *n_palabras)`. Esta
función devuelve un arreglo de punteros, donde cada puntero apunta a una palabra
alojada dinámicamente.

```{mermaid}
:caption: "Estructura de un arreglo de cadenas dinámicas (char**)"
graph TD
    subgraph Heap
        H(Hola) --- M(Mundo)
    end
    subgraph Arreglo de Punteros
        P1(ptr[0]) --> H;
        P2(ptr[1]) --> M;
        P3(ptr[2]) --> NUL(NULL);
    end
    Main(char** resultado) --> P1;
```

**Algoritmo:**

1.  Contar el número de palabras para saber el tamaño del arreglo `char**`.
2.  Reservar memoria para este arreglo de punteros.
3.  Volver a recorrer la cadena original. Por cada palabra encontrada: a.
    Calcular su longitud. b. Reservar memoria para esa palabra. c. Copiar los
    caracteres de la palabra. d. Asignar el puntero a la nueva palabra en el
    arreglo de punteros.
4.  Terminar el arreglo de punteros con un `NULL` para facilitar su recorrido.

## 3: Matrices Dinámicas

### 3.1: Ciclo de vida

Implementar funciones para reservar y liberar una matriz `m x n` usando un
arreglo de punteros.

- **Reserva**: Se realiza en dos etapas. Primero se reserva el arreglo de
  punteros a las filas, y luego, en un bucle, se reserva la memoria para cada
  fila individual.
- **Liberación**: Debe seguir el orden inverso. Primero, en un bucle, se libera
  la memoria de cada fila, y finalmente se libera el arreglo que contenía los
  punteros a las filas.

### 3.2: Multiplicación

Implementar `int** multiplicar(int **A, int m, int n, int **B, int p, int q)`.
**Algoritmo:**

1.  Verificar que la multiplicación sea posible ($n$ debe ser igual a $p$).
2.  Reservar memoria para una nueva matriz `C` de dimensiones $m \times q$.
3.  Aplicar el algoritmo de multiplicación de matrices para calcular cada
    elemento $c_{ij}$ y almacenarlo en la nueva matriz. $$ c*{ij} =
    \sum*{k=1}^{n} a*{ik} \cdot b*{kj} $$
4.  Retornar el puntero a la matriz `C`.

```

```
