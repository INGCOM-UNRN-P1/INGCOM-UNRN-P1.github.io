---
title: Arreglos
short_title: 4 - Arreglos
subtitle: Conjuntos de datos.
---

## Arreglos en C

### Definición de Arreglo

Un arreglo es una colección secuencial de elementos del mismo tipo, almacenados
en ubicaciones de memoria contiguas. Es una estructura de datos fundamental para
almacenar y manipular conjuntos de datos homogéneos mediante el uso de índices.

```c
int arreglo[8]; // Declara un arreglo de 8 enteros consecutivos.
```

Los arreglos en C poseen características particulares relacionadas con la
gestión de memoria y la forma en que el lenguaje los interpreta, aspectos que se
explorarán en detalle más adelante.

### El Operador `sizeof`

Para comprender mejor el manejo de memoria de los arreglos, es necesario
introducir el operador `sizeof`.

Este es un operador unario que se evalúa en tiempo de compilación. Su función es
determinar el tamaño en bytes de un tipo de dato o de una variable. El valor que
retorna es de tipo `size_t`, un tipo de entero sin signo.

Una característica del lenguaje C es que los tamaños de sus tipos de datos
numéricos pueden variar entre diferentes arquitecturas de hardware. El operador
`sizeof` permite escribir código portable que no dependa de un tamaño de tipo de
dato fijo, facilitando la adaptación del software a distintas plataformas.

Por ejemplo, históricamente, un `int` en sistemas de 16-bits ocupa 2 bytes,
mientras que en sistemas de 32-bits o 64-bits, comúnmente ocupa 4 bytes.

El uso de `sizeof` es crucial en la gestión de memoria dinámica, un tema que se
abordará posteriormente. Se puede aplicar tanto a tipos de datos como a
variables:

```c
sizeof(tipo_de_dato);
size_t tamanio_int = sizeof(int); // Generalmente 4 en sistemas modernos.

int variable;
sizeof(variable); // También 4, si la variable es de tipo int.
```

En la práctica, el resultado es el mismo si se utiliza una variable o su tipo,
ya que el operador es evaluado por el compilador.

```c
#include <stdio.h>

int main() {
    printf("Tamaño de char: %zu bytes", sizeof(char));
    printf("Tamaño de int: %zu bytes", sizeof(int));
    printf("Tamaño de float: %zu bytes", sizeof(float));
    printf("Tamaño de double: %zu bytes", sizeof(double));
    printf("Tamaño de long long: %zu bytes", sizeof(long long));
    return 0;
}
```

La salida de este código en una computadora de escritorio actual sería:

```
Tamaño de char: 1 bytes
Tamaño de int: 4 bytes
Tamaño de float: 4 bytes
Tamaño de double: 8 bytes
Tamaño de long long: 8 bytes
```

:::{note}

Para imprimir un valor de tipo `size_t` con `printf`, se utiliza el
especificador de formato `%zu`. El uso de `%d` o `%lu` puede provocar
advertencias del compilador debido a posibles inconsistencias de tipo.

:::

### Declaración e Inicialización

La declaración de un arreglo sigue la sintaxis `tipo identificador[cantidad];`,
donde `cantidad` debe ser una expresión constante entera.

La inicialización define los valores iniciales del arreglo. Existen varias
formas:

- **Completa**: Se especifica el tamaño y el valor para cada una de las
  posiciones.
- **Parcial**: Se especifica un tamaño y se proveen valores para los primeros
  elementos. Los elementos restantes se inicializan automáticamente a cero.
- **Implícita**: No se especifica el tamaño; el compilador lo infiere a partir
  del número de elementos en la lista de inicialización.
- **Sin inicialización**: El contenido del arreglo es indeterminado (contiene
  "basura").

```c
int completa[5] = {1, 2, 3, 4, 5};   // [1, 2, 3, 4, 5]
int parcial[5] = {1, 2};             // [1, 2, 0, 0, 0]
int implicita[] = {1, 2, 3};         // [1, 2, 3] (tamaño 3)
```

Es importante notar que no es posible declarar un arreglo de tamaño implícito
sin inicializarlo.

### Arreglos de Longitud Variable (VLA)

Un Arreglo de Longitud Variable (VLA, por sus siglas en inglés) es aquel cuyo
tamaño se determina en tiempo de ejecución mediante una variable, en lugar de
una constante.

```c
int cantidad = 0;
printf("Ingrese el tamaño del arreglo:
");
scanf("%d", &cantidad);

int arreglo[cantidad]; // Declaración de un VLA

printf("El tamaño del arreglo en bytes es: %zu
", sizeof(arreglo));
// El resultado será sizeof(int) * cantidad
```

Esta característica tiene limitaciones importantes. Por ejemplo, un VLA no puede
ser inicializado en su declaración. Intentarlo producirá un error de
compilación:

```
error: variable-sized object may not be initialized
```

Las implicaciones y el uso correcto de la memoria dinámica, que es la
alternativa recomendada a los VLA, se abordarán en un capítulo posterior.

### Tamaños y Memoria

El operador `sizeof` puede ser utilizado para obtener el tamaño de un arreglo
completo o de uno de sus elementos.

```c
int completa[5] = {1, 2, 3, 4, 5};
int implicita[] = {1, 2, 3};

sizeof(completa[0]); // Tamaño de un elemento: sizeof(int)
sizeof(completa);    // Tamaño total del arreglo: sizeof(int) * 5
sizeof(implicita);   // Tamaño total del arreglo: sizeof(int) * 3
```

Es posible utilizar el operador `sizeof` para determinar la cantidad de
elementos en un arreglo inicializado implícitamente:

```c
int numeros[] = {10, 20, 30, 40, 50, 60};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
printf("Cantidad de elementos en el arreglo: %zu
", cantidad);
```

Este código imprimirá `6`.

### Acceso y Modificación de Elementos

Los elementos de un arreglo pueden ser accedidos y modificados individualmente,
comportándose como variables del tipo base del arreglo.

#### Acceso

Para leer el valor de un elemento, se utiliza el operador de subíndice `[]` con
el índice del elemento deseado. Es importante recordar que los índices en C
comienzan en cero. Una expresión de acceso como `miArreglo[i]` es un "r-value",
ya que representa un valor que puede ser leído.

```c
int calificaciones[5] = {10, 8, 9, 7, 10};

// Obtener el valor del primer elemento (índice 0)
int primera = calificaciones[0];

// Obtener el valor del cuarto elemento (índice 3)
int cuarta = calificaciones[3];

printf("La primera calificación es: %d
", primera);
printf("La cuarta calificación es: %d
", cuarta);
printf("Acceso directo al segundo elemento: %d
", calificaciones[1]);
```

Salida:

```
La primera calificación es: 10
La cuarta calificación es: 7
Acceso directo al segundo elemento: 8
```

#### Modificación

Para escribir un nuevo valor en un elemento, la expresión de subíndice
`miArreglo[i]` se coloca en el lado izquierdo de una operación de asignación. En
este contexto, la expresión es un "l-value", ya que representa una ubicación de
memoria modificable.

```c
int edades[4] = {20, 25, 22, 28};

// 1. Mostrar el valor original del tercer elemento (índice 2)
printf("La edad original en el índice 2 es: %d
", edades[2]);

// 2. Modificar el valor en el índice 2. 'edades[2]' es un l-value.
edades[2] = 23;

// 3. Mostrar el valor modificado. 'edades[2]' se evalúa como un r-value.
printf("La nueva edad en el índice 2 es: %d
", edades[2]);
```

Salida:

```
La edad original en el índice 2 es: 22
La nueva edad en el índice 2 es: 23
```

#### Modificación del Arreglo en sí

El identificador de un arreglo es una constante que representa la dirección de
inicio del bloque de memoria asignado. Por esta razón, el nombre de un arreglo
es un **l-value no modificable**.

Esto significa que no se le puede asignar una nueva dirección de memoria.
Intentar hacerlo resultará en un error de compilación.

```c
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {10, 20, 30, 40, 50};

// La siguiente línea es ilegal y causará un error de compilación.
arr1 = arr2; // Error: expression is not assignable.
```

El compilador impide esta operación porque `arr1` no puede ser reasignado para
apuntar a otra ubicación de memoria.

### Recorrido de Arreglos

Los bucles, especialmente el bucle `for`, son la estructura de control ideal
para iterar sobre los elementos de un arreglo.

```c
int numeros[] = {10, 20, 30, 40, 50, 60};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

for (size_t i = 0; i < cantidad; i++) {
    printf("Elemento %zu: %d
", i, numeros[i]);
}
```

Es crucial tener presente que C no realiza una verificación de los límites del
arreglo durante la iteración. Acceder a un índice fuera de los límites del
arreglo (`i >= cantidad`) conduce a un comportamiento indefinido, un tipo de
error que puede ser difícil de depurar.

## Uso de Arreglos en Funciones

El comportamiento de los arreglos cuando se utilizan con funciones está
relacionado con la gestión de memoria y los punteros, conceptos que se tratarán
en profundidad más adelante. En esta sección, se describirán los efectos
prácticos de pasar arreglos a funciones.

A diferencia de los tipos de datos primitivos, cuando un arreglo se pasa a una
función, lo que se transfiere no es una copia de todos sus elementos, sino la
dirección de memoria de su primer elemento.

### Arreglos como Argumentos de Funciones

Al pasar un arreglo a una función, su tamaño no se transfiere implícitamente.
Dentro de la función, el operador `sizeof` aplicado al argumento del arreglo no
devolverá el tamaño total del arreglo original.

```c
void imprimirArreglo(int arreglo[], size_t size) {
    // sizeof(arreglo) aquí no es el tamaño total del arreglo.
    // Devolverá el tamaño de un puntero.
}
```

Por lo tanto, es una práctica estándar pasar el tamaño del arreglo como un
argumento adicional para evitar accesos fuera de los límites.

Cualquier modificación realizada a los elementos del arreglo dentro de la
función afectará al arreglo original en el código que realizó la llamada. Esto
se debe a que la función opera directamente sobre la memoria del arreglo
original, lo que se conoce como "paso por referencia". Esto constituye un efecto
secundario.

Una función que busca el valor máximo en un arreglo es un ejemplo de una función
pura si no modifica el arreglo.

```c
// Función pura: no modifica el estado del arreglo.
int maximo(int valores[], int cantidad) {
    int max = valores[0];
    for (int i = 1; i < cantidad; i++) {
        if (valores[i] > max) {
            max = valores[i];
        }
    }
    return max;
}
```

En contraste, una función que ordena un arreglo modifica su contenido y, por lo
tanto, no es una función pura. Generalmente, estas operaciones se implementan
como procedimientos (funciones `void`).

```c
// Procedimiento con efecto secundario: modifica el arreglo.
void ordenar(int v[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
```

### Arreglos como Valores de Retorno

Es importante destacar que una función no puede retornar un arreglo local (un
arreglo creado en su propio ámbito). Las razones técnicas se relacionan con el
ciclo de vida de las variables locales y la gestión de la pila de llamadas,
temas que se abordarán posteriormente.

:::{warning} Creación y Retorno de Arreglos

No es posible retornar arreglos creados localmente en una función. La práctica
recomendada es declarar los arreglos en la función llamante (por ejemplo,
`main`) y pasarlos a otras funciones para su procesamiento.

:::
