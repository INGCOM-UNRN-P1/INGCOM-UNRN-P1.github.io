# Estructura de la Memoria en C

Cuando un programa en C se ejecuta, el sistema operativo le asigna un espacio de
memoria virtual. Esta memoria no es un bloque monolítico, sino que se organiza
en varios segmentos, cada uno con un propósito específico. Comprender esta
estructura es fundamental para entender cómo funcionan los programas, cómo se
gestionan las variables y cómo pueden surgir ciertos errores como los _stack
overflows_ o los _memory leaks_.

Los principales segmentos de memoria son:

1.  **Segmento de Código (o Texto)**: Almacena las instrucciones del programa en
    lenguaje de máquina. Es de solo lectura para evitar que el programa se
    modifique a sí mismo accidentalmente.
2.  **Segmento de Datos**: Contiene las variables globales y estáticas que son
    inicializadas por el programador.
3.  **Segmento BSS (Block Started by Symbol)**: Contiene las variables globales
    y estáticas que no son inicializadas explícitamente y se inicializan a cero
    por defecto.
4.  **Heap (Montón)**: Es una región de memoria para la asignación dinámica. El
    programador la gestiona manualmente.
5.  **Stack (Pila)**: Es una estructura de datos LIFO (Last-In, First-Out) que
    se utiliza para gestionar la ejecución de funciones.

---

## El Stack (Pila)

El Stack es una de las partes más activas de la memoria durante la ejecución de
un programa. Su función principal es llevar un registro de las llamadas a
funciones. Cada vez que se invoca una función, se crea un nuevo "marco de pila"
(_stack frame_) en la cima del stack.

### ¿Qué contiene un Stack Frame?

Un marco de pila contiene toda la información necesaria para la ejecución de una
función:

- **Variables locales**: Las variables declaradas dentro de la función.
- **Argumentos de la función**: Los valores pasados a la función.
- **Dirección de retorno**: La dirección de la instrucción a la que el programa
  debe volver cuando la función termine.
- **Puntero al marco de pila anterior**: Para poder restaurar el estado anterior
  al finalizar la función.

```c
void funcion_b(int arg2) {
    int var_local_b = 20;
    // ...
}

void funcion_a(int arg1) {
    int var_local_a = 10;
    funcion_b(var_local_a);
}

int main() {
    funcion_a(5);
    return 0;
}
```

Cuando `main` llama a `funcion_a`, se crea un marco para `funcion_a` en el
stack. Luego, cuando `funcion_a` llama a `funcion_b`, se apila un nuevo marco
para `funcion_b` encima del de `funcion_a`.

### Reutilización del Espacio en el Stack

La característica más importante del stack es su naturaleza automática y
eficiente. Cuando una función retorna, su marco de pila se "destruye". En
realidad, no se borra la memoria, sino que el puntero del stack
(`stack pointer`) simplemente se mueve hacia atrás, liberando el espacio.

:::{important} El espacio liberado en el stack queda disponible para la
siguiente llamada a función. Esto significa que la memoria del stack se
**reutiliza constantemente**. :::

Para ilustrar esto de forma más clara, consideremos el siguiente programa que
"ensucia" el stack a propósito para ver qué ocurre.

```c
#include <stdio.h>

// Esta función llena su marco de pila con valores específicos.
void funcion_carga() {
    int datos[4] = {100, 200, 300, 400};
    printf("-> Entrando a funcion_carga. El stack contiene datos definidos.\n");
    // Al salir de esta función, el marco de pila se libera,
    // pero los valores pueden permanecer en la memoria.
}

// Esta función declara variables locales pero no las inicializa.
void funcion_lectura() {
    int basura[4];
    printf("-> Entrando a funcion_lectura. Las variables locales no se inicializaron.\n");
    printf("   Contenido de 'basura':\n");
    for (int i = 0; i < 4; i++) {
        // Imprimimos los valores "fantasma" que quedaron en el stack.
        printf("   basura[%d] = %d\n", i, basura[i]);
    }
}

int main() {
    // Primero, llamamos a la función que "ensucia" el stack.
    funcion_carga();

    printf("\n--- Espacio en el stack fue liberado y será reutilizado ---\n\n");

    // Luego, llamamos a la función que leerá la memoria reutilizada.
    funcion_lectura();

    return 0;
}
```

### Ejecución y Análisis

Al compilar y ejecutar este código, la salida más probable será:

```text
-> Entrando a funcion_carga. El stack contiene datos definidos.

--- Espacio en el stack fue liberado y será reutilizado ---

-> Entrando a funcion_lectura. Las variables locales no se inicializaron.
   Contenido de 'basura':
   basura[0] = 100
   basura[1] = 200
   basura[2] = 300
   basura[3] = 400
```

**¿Qué sucedió?**

1.  `main` llama a `funcion_carga()`. Se reserva espacio en el stack para el
    arreglo `datos`, que se llena con los valores `{100, 200, 300, 400}`.
2.  `funcion_carga()` termina. Su marco de pila se libera. El puntero del stack
    retrocede, pero los datos escritos en esa zona de memoria no se borran.
3.  `main` llama a `funcion_lectura()`. El sistema operativo reutiliza el
    espacio que acaba de liberar `funcion_carga` para el nuevo marco de pila.
4.  El arreglo `basura` se declara en este nuevo marco, ocupando la misma
    posición de memoria que antes ocupaba `datos`. Como `basura` no se
    inicializa, simplemente "hereda" los valores que estaban previamente en esa
    memoria.

Este comportamiento, aunque predecible en este ejemplo, puede variar dependiendo
del compilador, el sistema operativo y las optimizaciones.

:::{warning} Confiar en los "datos fantasma" que quedan en el stack es una **muy
mala práctica** y una fuente común de comportamiento indefinido. Las variables
locales siempre deben ser inicializadas antes de su uso. :::

---

## El Heap (Montón)

A diferencia del stack, el Heap es una región de memoria que no se gestiona
automáticamente. Está destinada a la **asignación dinámica de memoria**, es
decir, para objetos de datos cuyo tamaño o tiempo de vida no se conoce en tiempo
de compilación.

:::{note} La gestión del Heap se realiza de forma manual a través de funciones
como `malloc()`, `calloc()`, `realloc()` y `free()`. :::

El Heap es más flexible que el stack, pero también más lento y propenso a
errores si no se gestiona con cuidado. Los detalles sobre su funcionamiento,
fragmentación y los problemas comunes como los _memory leaks_ (fugas de memoria)
se tratarán en un apunte posterior dedicado exclusivamente a la gestión de
memoria dinámica.

Para resumir las diferencias clave entre el Stack y el Heap, podemos usar la
siguiente tabla comparativa:

:::{table} Comparación entre Stack y Heap :label: tbl-stack-heap

| Característica      | Stack (Pila)                                        | Heap (Montón)                                      |
| :------------------ | :-------------------------------------------------- | :------------------------------------------------- |
| **Gestión**         | Automática (por el compilador y el SO)              | Manual (por el programador)                        |
| **Velocidad**       | Muy rápida (solo se mueve un puntero)               | Más lenta (implica buscar bloques libres)          |
| **Tamaño**          | Fijo y limitado                                     | Flexible y grande (limitado por la RAM disponible) |
| **Estructura**      | LIFO (Last-In, First-Out)                           | Sin un orden particular (puede fragmentarse)       |
| **Contenido**       | Variables locales, argumentos, dirección de retorno | Datos cuyo tamaño se conoce en tiempo de ejecución |
| **Funciones Clave** | (ninguna, es automático)                            | `malloc()`, `free()`, `calloc()`, `realloc()`      |
| **Errores Comunes** | Stack Overflow (pila llena)                         | Memory Leaks (fugas), Punteros colgantes           |

:::

## Conclusión

Comprender la dicotomía entre el Stack y el Heap es un pilar en la programación
en C. Mientras que el Stack ofrece una gestión de memoria rápida y automática
para el ámbito de las funciones, el Heap proporciona la flexibilidad necesaria
para manejar datos dinámicos y complejos cuyo ciclo de vida no está atado a una
función específica.

Una gestión inadecuada de cualquiera de estos segmentos puede llevar a errores
graves y difíciles de depurar. Por ello, es crucial no solo conocer su
funcionamiento teórico, sino también aplicar buenas prácticas para garantizar la
estabilidad y eficiencia de nuestros programas.

