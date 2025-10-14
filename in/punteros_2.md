# Punteros genéricos y memoria dinámica

### Las excepciones a la Regla: Cuándo un arreglo sigue siendo un arreglo

Aunque la "degradación" de arreglos a punteros es la norma, existen tres
contextos importantes en los que un arreglo no se convierte en un puntero a su
primer elemento y conserva su identidad como un objeto completo. Entender estas
excepciones es clave para dominar el manejo de la memoria en C.

#### 1. Cuando es el operando de `sizeof`

El operador `sizeof` es una consulta que se resuelve en _tiempo de compilación_.
Cuando lo aplicás a un arreglo, el compilador examina la declaración original de
la variable y calcula el espacio total de memoria que ocupa, en lugar de
tratarlo como un puntero.

Esta excepción es la razón por la que `sizeof` puede determinar el tamaño
completo de un arreglo en el mismo ámbito en el que fue declarado, pero no puede
hacerlo dentro de una función a la que el arreglo fue pasado como parámetro
(porque dentro de la función, ya se ha degradado a un puntero).

Esta es la razón por la que declarar el arreglo en el `main` y usar el operador
en el mismo ámbito, funciona. El compilador sabe perfectamente a qué arreglo nos
estamos refiriendo.

#### 2. Cuando es el operando del operador `&` (Dirección de)

Aplicar el operador `&` a un arreglo completo no devuelve un puntero al primer
elemento, sino un **puntero al arreglo entero**. Aunque la dirección numérica
sea la misma, el **tipo de dato** es fundamentalmente diferente, lo que tiene un
gran impacto en la aritmética de punteros.

- Un puntero a un elemento (`int*`) avanza de a un elemento a la vez
  (`sizeof(int)`).

- Un puntero a un arreglo de N elementos (`int (*)[N]`) avanza de a un bloque
  completo de N elementos (`sizeof(int) * N`).

Imaginá un edificio de departamentos: `mi_arreglo` (degradado) te da la
dirección del primer departamento. `&mi_arreglo` te da la dirección de todo el
edificio. La dirección es la misma, pero si avanzás "una unidad", en el primer
caso pasás al siguiente departamento, y en el segundo, ¡pasás al siguiente
edificio!

**Ejemplo Práctico:**

```c
#include <stdio.h>

int main() {
    int mi_arreglo[5] = {1, 2, 3, 4, 5};

    // ptr_elem apunta al primer entero del arreglo.
    int *ptr_elem = mi_arreglo;

    // ptr_arr apunta al arreglo completo de 5 enteros.
    int (*ptr_arr)[5] = &mi_arreglo;

    printf("Dirección inicial (ptr_elem): %p\n", (void*)ptr_elem);
    printf("Dirección inicial (ptr_arr):  %p\n", (void*)ptr_arr);

    // Avanzamos el puntero al siguiente ELEMENTO (4 bytes más allá)
    ptr_elem++;

    // Avanzamos el puntero al siguiente ARREGLO (5 * 4 = 20 bytes más allá)
    ptr_arr++;

    printf("\n--- Después de incrementar ---\n");
    printf("Dirección + 1 (ptr_elem): %p\n", (void*)ptr_elem);
    printf("Dirección + 1 (ptr_arr):  %p\n", (void*)ptr_arr);

    return 0;
}
```

#### 3. Cuando un Literal de Cadena Inicializa un Arreglo

En el momento específico de la declaración de un arreglo de caracteres, un
literal de cadena (texto entre comillas dobles) actúa como un inicializador
especial. El compilador lo utiliza para dos propósitos:

1.  **Determinar el tamaño del arreglo**: El tamaño será la cantidad de
    caracteres más uno, para alojar el carácter nulo final (`\0`).

2.  **Poblar el arreglo**: Los caracteres del literal se copian en el espacio de
    memoria recién asignado para el arreglo.

Una vez que la inicialización ha concluido, la variable es un arreglo de
caracteres como cualquier otro, y se degradará a un puntero en expresiones
posteriores.

**Ejemplo Práctico:**

```c
#include <stdio.h>

int main() {
    // El compilador usa "Hola" para crear un arreglo de 5 bytes
    // {'H', 'o', 'l', 'a', '\0'}
    char saludo_arr[] = "Hola";

    // "Hola" es un literal constante en memoria. ptr_saludo solo apunta a él.
    const char *ptr_saludo = "Hola";

    // sizeof(saludo_arr) devuelve el tamaño del arreglo.
    printf("Tamaño del arreglo (saludo_arr): %zu bytes\n", sizeof(saludo_arr)); // Imprimirá 5

    // sizeof(ptr_saludo) devuelve el tamaño de un puntero.
    printf("Tamaño del puntero (ptr_saludo): %zu bytes\n", sizeof(ptr_saludo)); // Imprimirá 4 u 8

    // Es un arreglo real, por lo que podemos modificarlo.
    saludo_arr[0] = 'h';
    printf("Arreglo modificado: %s\n", saludo_arr); // Imprime "hola"

    // ptr_saludo[0] = 'h'; // ¡ERROR DE COMPILACIÓN O FALLO EN EJECUCIÓN!
                            // Intentar modificar un literal de cadena es comportamiento indefinido.

    return 0;
}
```





## Punteros y structs

Punteros permiten pasar estructuras grandes sin copiarlas.

```c
typedef struct {
    char nombre[100];
    int edad;
} Persona;

void mostrar(const Persona *p) {
    printf("%s tiene %d años", p->nombre, p->edad);
}
```

Usá `->` para acceder a campos a través de un puntero.




## 8. Punteros colgantes

Un puntero colgante apunta a memoria que ya no es válida. Esto puede ocurrir si
el puntero se refiere a una variable local que ya salió de ámbito.

```c
int *funcion() {
    int x = 5;
    return &x; // MAL: x deja de existir al salir de la función
}
```

Evitalo asegurándote de no retornar direcciones de variables locales.



### Arreglos de Punteros (Arreglos 2D Dinámicos)

El otro uso fundamental de los punteros dobles es la creación de estructuras de datos dinámicas, como un arreglo de arreglos. Esto es especialmente útil cuando necesitás una matriz cuyas dimensiones no se conocen en tiempo de compilación.

Un puntero doble `int **matriz` puede ser visto como un puntero al primer elemento de un arreglo de punteros (`int *`). A su vez, cada uno de esos punteros puede apuntar al primer elemento de un arreglo de enteros (`int`).

**Ejemplo: Crear una matriz dinámica**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas = 3;
    int columnas = 4;
    int **matriz;

    // 1. Asignar memoria para un arreglo de punteros (las filas).
    matriz = (int **) malloc(filas * sizeof(int *));
    if (matriz == NULL) return 1;

    // 2. Para cada puntero de fila, asignar memoria para sus columnas.
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *) malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) return 1;
    }

    // 3. Ahora podemos usar la notación de arreglo [fila][columna].
    matriz[1][2] = 99;
    printf("El valor en (1, 2) es: %d\n", matriz[1][2]);

    // 4. Liberar la memoria en el orden inverso a la asignación.
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); // Liberar cada fila.
    }
    free(matriz); // Liberar el arreglo de punteros.

    return 0;
}
```
Este mismo concepto se aplica para crear un arreglo de cadenas (donde `char **cadenas` apunta a un arreglo de `char *`, y cada `char *` apunta a una cadena).