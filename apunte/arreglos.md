---
title: Arreglos
short_title: 4 - Arreglos
subtitle: Conjuntos de datos.
---

## Arreglos en C

### ¿Qué es un arreglo?

Un arreglo es una colección secuencial de elementos del mismo tipo, almacenados
en ubicaciones de memoria contiguas. Es una estructura muy útil para almacenar
datos homogéneos y acceder a ellos mediante índices.

```c
int arreglo[8]; // 8 enteros consecutivos
```

Los arreglos tienen una característica adicional que exploraremos luego,
referida a la memoria y la forma en la que C los ve.

### Operador `sizeof`

Antes de continuar, es necesario que veamos una nueva palabra reservada del
lenguaje, el operador `sizeof`.

Este operador unario se evalúa en tiempo de compilación y nos indica el tamaño
en bytes de un tipo de dato o variable, el valor devuelto es de tipo `size_t`,
un tipo de entero sin signo.

Una de las cuestiones criticadas de C, pero que en definitiva simplifica que el
código pueda funcionar sin cambios entre diferentes arquitecturas de
computadora, es el hecho de que sus tipos numéricos enteros cambian de tamaño
entre plataformas. Este operador existe para que podamos trabajar junto a
`limits.h` para no excedernos de los límites de los números.

Por nombrar un ejemplo, e históricamente, un programa compilado para un
procesador más limitado, verá que sus `int` son de 16-bits (2-bytes), mientras
que en una máquina de escritorio tradicional, serán de 32-bits (4-bytes).

El uso de este operador no se limita a los tipos por defecto, más adelante, es
una pieza clave de la gestión de memoria dinámica por lo que utilizaremos este
operador en un tema posterior luego.

Se puede utilizar de dos formas, para averiguar el tamaño de un tipo de dato y
para averiguar el tamaño de una variable.

```c
sizeof(tipo_de_dato);
size_t tamanio_int = sizeof(int); // 4

int variable;
sizeof(variable); // 4
```

A efectos prácticos, utilizar variables o el tipo directamente es lo mismo, ya
que este operador es resuelto por el compilador.

```c
#include <stdio.h>

int main() {
    printf("Tamaño de char: %zu bytes\n", sizeof(char));
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de float: %zu bytes\n", sizeof(float));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    printf("Tamaño de long long: %zu bytes\n", sizeof(long long));
    return 0;
}
```

Esto daría como salida, en una computadora de escritorio actual:

```
Tamaño de char: 1 bytes
Tamaño de int: 4 bytes
Tamaño de float: 4 bytes
Tamaño de double: 8 bytes
Tamaño de long long: 8 bytes
```

:::{note}

El especificador de formato de `pritnf` para `size_t` es `%zu`. Usar `%d` o
`%lu` podría generar advertencias del compilador.

:::

### Declaración e inicialización de arreglos

Ahora, volviendo al tema principal de este apunte.

La declaración de un arreglo sigue la forma `tipo identificador[cantidad];` para
crear un conjunto de `tipo` por `cantidad` lugares con el `identificador` de
nombre. Siendo cantidad un número constante.

Y luego, con la inicialización definimos los valores que contendrá al comienzo
del programa. Puede hacerse de forma completa, parcial o implícita:

- Completa, se indica el tamaño y el contenido de todas las posiciones.
- Parcial, se indica un tamaño y el contenido para los primeros elementos,
  rellenando el resto con ceros.
- Sin inicialización, el contenido indeterminado.

```c
int completa[5] = {1, 2, 3, 4, 5};   // [1, 2, 3, 4, 5]
int parcial[5] = {1, 2};             // [1, 2, 0, 0, 0]
int implicita[] = {1, 2, 3};         // [1, 2, 3]
```

Tengan en cuenta que no es posible crear un arreglo implícito sin inicializar.

### Arreglos de largo dinámicos (ALV/VLA)

Un arreglo de largo dinámico, es aquel que en lugar de ser declarado con un
número constante, lo es a partir de una variable.

Esto no está permitido y las razones específicas las veremos cuando veamos
memoria dinámica

```c
int cantidad = 0;
printf("de que tamaño es el arreglo?\n");
scanf("%d", &cantidad);
int arreglo[cantidad];
printf("el tamaño es de %zu\n", sizeof(arreglo));
// Que debiera de ser sizeof(int) * cantidad
```

Es importante destacar que un arreglo creado de esta forma no es posible de ser
inicializado, obtendremos el siguiente mensaje:

```
error: variable-sized object may not be initialized except with an empty initializer
```

### Tamaños y memoria

```c
sizeof(completa[0]); // Tamaño de un elemento; sizeof(int)
sizeof(completa);    // Tamaño total; sizeof(int) * 5
sizeof(implicita);   // sizeof(int) * 3
```

Estos tamaños dependen del tipo de datos (por ejemplo, `int` ocupa típicamente 4
bytes).

Podemos aprovechar para obtener el tamaño de un arreglo implicito utilizando
`sizeof`

```c
int numeros[] = {10, 20, 30, 40, 50, 60};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
printf("Cantidad de elementos en el array: %zu\n", cantidad);
```

Que dará como resultado `6`.

### Accediendo y modificando

Una vez que un arreglo es declarado e inicializado, sus elementos individuales
pueden ser accedidos y modificados. Cada elemento de un arreglo se comporta como
una variable del tipo de dato del arreglo.

#### Acceso

Para obtener o leer el valor de un elemento específico, se utiliza el operador
de subíndice `[]`. Dentro de los corchetes se coloca el índice del elemento
deseado. Recuerda que los índices en C siempre comienzan en cero.

Acceder a un elemento del arreglo, como `miArreglo[i]`, es una operación que
resulta en un r-value, es decir, el valor contenido en esa posición.

```c
int calificaciones[5] = {10, 8, 9, 7, 10};

// Obtener el valor del primer elemento (índice 0)
int primera = calificaciones[0];

// Obtener el valor del cuarto elemento (índice 3)
int cuarta = calificaciones[3];

printf("La primera calificación es: %d\n", primera);
printf("La cuarta calificación es: %d\n", cuarta);
printf("directamente: %d\n", calificaciones[1]);
```

Y la salida

```
La primera calificación es: 10
La cuarta calificación es: 7
directamente: 8
```

#### Modificación

Para modificar o escribir un nuevo valor en un elemento, se usa también el
operador de subíndice `[]`, pero esta vez la expresión se coloca en el lado
izquierdo de una asignación (`=`).

En este contexto, la expresión `miArreglo[i]` se comporta como un l-value, ya
que representa una ubicación de memoria específica y modificable.

```c

int edades[4] = {20, 25, 22, 28};

// 1. Mostrar el valor original del tercer elemento (índice 2)
printf("La edad original en el índice 2 es: %d\n", edades[2]);

// 2. Modificar el valor en el índice 2.
// 'edades[2]' aquí es un l-value.
edades[2] = 23;

// 3. Mostrar el valor modificado para confirmar el cambio.
// 'edades[2]' aquí se evalúa como un r-value.
printf("La nueva edad en el índice 2 es: %d\n", edades[2]);

return 0;

}
```

Y su salida
```
La edad original en el índice 2 es: 22
La nueva edad en el índice 2 es: 23
```

#### Modificación del arreglo en sí

Sin embargo, asignar al nombre de un arreglo, no es posible y esta es una 
**constante** que se fija en tiempo de compilación. Por lo tanto, el nombre
de un arreglo es un **l-value no modificable**.

Esto significa que, aunque representa una ubicación de memoria (es un l-value),
no puedes asignarle una nueva dirección. Intentar hacerlo resultará en un error
de compilación.

Un ejemplo de asignación inválida:

El siguiente código intenta asignar una nueva dirección de memoria al arreglo
`arr1`, lo cual es ilegal.

```{code} c
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {10, 20, 30, 40, 50};

arr1 = arr2; // Error: expression is not assignable.
```

El nombre 'arr1' es un l-value no modificable por lo que no puede cambiar a otro
arreglo, esto es algo que el compilador impedirá pasar.

### Recorriendo la secuencia

Los lazos definidos son ideales para recorrer arreglos.

```c
int numeros[] = {10, 20, 30, 40, 50, 60};
size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

for (size_t i = 0; i < cantidad; i++) {
    printf("Elemento %zu: %d\n", i, numeros[i]);
}
```

Tengan muy presente que C no verificará los limites del arreglo en un lazo y,
como veremos en clases, pueden obtener resultados interesantes.

## Arreglos y funciones, como que falta algo

Varias de las cuestiones de esta parte del apunte, tienen que ver con un concepto
que veremos más adelante, aquí, solo dejaré los efectos que tiene cuando lo
utilizamos en funciones, las razones por la que todo esto sucede, las veremos mas
adelante.

Los arreglos viajan de una forma diferente a los valores que hemos visto hasta
ahora, lo que se copia, es la dirección de memoria al inicio del "bloque" de
valores.

### Arreglos como argumentos de funciones

Al trabajar con arreglos en funciones, es muy importante tener en cuenta que el
tamaño del mismo, no va con el argumento.

```c
void imprimirArreglo(int arreglo[], size_t size) {
    // Cuidado: sizeof(arreglo) no da el tamaño total real
}
```

De momento, implica que cuando debamos pasar un arreglo como argumento, lo debemos
de hacer con un valor de tipo `int` o `size_t` para no excedernos de sus límites.

Cuando pasamos un arreglo como argumento en una función, los cambios que sean hechos
en el contenido del mismo, se verán reflejados en el argumento _fuera_ de la función.

Esto significa que si nuestra función modifica el arreglo, está provocando un
efecto secundario en el argumento, ¡pero solo si lo modificamos!.

La búsqueda del máximo, es un ejemplo de función pura sobre arreglos.

```c
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

Mientras que el ordenamiento no lo es, observen que, incluso, se transforma
en un procedimiento.

```c
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

### Arreglos como valores de retorno

Es también importante, que una función no puede retornar un arreglo que fuere
creado dentro de sí. Una de las razones es que no podemos retornar el tamaño del
mismo junto al arreglo en sí.

La otra razón amerita una clase completa y tiene que ver con lo mismo que pasa
cuando van como argumentos.

:::{warning} Creación de arreglos

Es muy importante que tengan presente que no es posible retornar arreglos
creados en funciones.

Y como siempre van a ser argumentos, créenlos exclusivamente en el `main` y
luego pásenlos a partir de ahí.

:::

