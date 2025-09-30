---
title: Roles de variables
short_title: Notas - Roles
subtitle: Para que podemos usar variables.
---

# Roles de Variables en Programación

¡Hola a todos! Hoy vamos a sumergirnos en un concepto fundamental en
programación que nos ayudará a entender mejor cómo las variables no solo
almacenan valores, sino que cumplen **roles específicos** dentro de nuestros
programas. A menudo, cuando empezamos a programar, pensamos en las variables
simplemente como "cajas" para guardar datos. Sin embargo, si profundizamos un
poco más, veremos que muchas de ellas tienen un propósito particular, casi como
si tuvieran una "función" o un "papel" en el algoritmo.

---

## El "Rol" de una Variable

En programación, el **rol de una variable** se refiere a la función o propósito
específico que una variable desempeña dentro de un algoritmo. No es solo lo que
la variable _contiene_, sino para _qué_ la usamos. Identificar el rol de una
variable nos permite diseñar algoritmos más claros, eficientes y fáciles de
depurar. Es como asignar una tarea a cada miembro de un equipo; cada uno tiene
su función y sabe qué hacer.

Vamos a explorar algunos de los roles más comunes que encontramos en la
programación, usando ejemplos en **C**.

---

### Acumulador

Un **acumulador** es una variable que se utiliza para **sumar o acumular
valores** a lo largo de un proceso. Generalmente, se inicializa en cero antes de
que comience el proceso de acumulación.

---

### Ejemplo de Acumulador en C

Imaginemos que queremos calcular la suma de los primeros N números enteros.

```c
#include <stdio.h>

int main() {
    int n;
    int suma = 0; // Aquí, 'suma' es nuestro acumulador
    printf("Ingrese un numero entero N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        suma = suma + i; // Se acumulan los valores en cada iteración
    }

    printf("La suma de los primeros %d numeros es: %d\n", n, suma);
    return 0;
}
```

En este ejemplo, la variable `suma` tiene el rol de **acumulador**. En cada
iteración del bucle `for`, se le suma el valor actual de `i`, acumulando así la
suma total.

---

### Contador

Un **contador** es una variable que se utiliza para **contar la ocurrencia de un
evento** o para **llevar un registro del número de iteraciones** en un bucle. Se
incrementa o decrementa en un valor fijo (usualmente 1) cada vez que el evento
ocurre.

---

### Ejemplo de Contador en C

Supongamos que queremos contar cuántos números pares hay en un rango dado.

```c
#include <stdio.h>

int main() {
    int inicio, fin;
    int contadorPares = 0; // Aquí, 'contadorPares' es nuestro contador

    printf("Ingrese el inicio del rango: ");
    scanf("%d", &inicio);
    printf("Ingrese el fin del rango: ");
    scanf("%d", &fin);

    for (int i = inicio; i <= fin; i++) {
        if (i % 2 == 0) {
            contadorPares++; // Se incrementa el contador si el número es par
        }
    }

    printf("En el rango de %d a %d, hay %d numeros pares.\n", inicio, fin, contadorPares);
    return 0;
}
```

En este caso, `contadorPares` tiene el rol de **contador**. Cada vez que
encontramos un número par, incrementamos su valor en 1.

---

### Bandera (o Flag)

Una **bandera** (o _flag_) es una variable booleana (o entera que simula un
booleano, como 0 o 1) que se utiliza para **señalizar una condición o estado**.
Su valor cambia para indicar que un evento ha ocurrido o que una determinada
situación es verdadera o falsa.

---

### Ejemplo de Bandera en C

Vamos a buscar si un número específico está presente en un array.

```c
#include <stdio.h>
#include <stdbool.h> // Para usar el tipo de dato bool

int main() {
    int numeros[] = {10, 25, 4, 30, 8, 15};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    int numeroBuscado = 8;
    bool encontrado = false; // Aquí, 'encontrado' es nuestra bandera

    for (int i = 0; i < tamano; i++) {
        if (numeros[i] == numeroBuscado) {
            encontrado = true; // La bandera se activa si encontramos el número
            break; // Podemos salir del bucle una vez que lo encontramos
        }
    }

    if (encontrado) {
        printf("El numero %d fue encontrado en el array.\n", numeroBuscado);
    } else {
        printf("El numero %d NO fue encontrado en el array.\n", numeroBuscado);
    }

    return 0;
}
```

La variable `encontrado` es una **bandera**. Se inicializa en `false` y se
cambia a `true` si el `numeroBuscado` es hallado en el array. Luego, podemos
usar el estado de esta bandera para tomar una decisión.

---

## Otros Roles de Variables

Además de los acumuladores, contadores y banderas, las variables pueden adoptar
una variedad de roles, algunos más específicos o que surgen en contextos
particulares.

---

### Variable de Control de Bucle (o Iterador)

Este es un rol que a menudo usamos sin siquiera pensarlo. La **variable de
control de bucle** es la que se encarga de controlar las repeticiones de un
ciclo, generalmente incrementándose o decrementándose en cada iteración hasta
que se cumple una condición de finalización.

```c
#include <stdio.h>

int main() {
    // 'i' es la variable de control de bucle
    for (int i = 0; i < 5; i++) {
        printf("Iteracion numero: %d\n", i);
    }
    return 0;
}
```

En este caso, `i` controla cuántas veces se ejecuta el bucle `for` y en qué
punto debe detenerse.

---

### Variable Auxiliar o Temporal

Una **variable auxiliar o temporal** se usa para almacenar un valor de forma
transitoria, generalmente para facilitar una operación que requiere conservar un
dato mientras se manipulan otros. El caso más común es el intercambio de valores
entre dos variables sin perder ninguno.

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int temp; // 'temp' es nuestra variable auxiliar

    printf("Antes del intercambio: a = %d, b = %d\n", a, b);

    temp = a; // Guarda el valor de 'a'
    a = b;    // 'a' toma el valor de 'b'
    b = temp; // 'b' recupera el valor original de 'a' desde 'temp'

    printf("Despues del intercambio: a = %d, b = %d\n", a, b);
    return 0;
}
```

Aquí, `temp` es crucial para no perder el valor original de `a` cuando se lo
asignamos a `b`.

---

### Variable de Estado

Similar a una bandera, pero una **variable de estado** puede tener más de dos
valores, representando diferentes fases, modos o condiciones dentro de un
programa o sistema. Piensa en un semáforo que puede estar en rojo, amarillo o
verde.

```c
#include <stdio.h>

// Definimos constantes para los estados
#define ESTADO_INICIANDO 0
#define ESTADO_PROCESANDO 1
#define ESTADO_FINALIZADO 2

int main() {
    int estadoActual = ESTADO_INICIANDO; // 'estadoActual' es nuestra variable de estado

    printf("Estado actual: %d\n", estadoActual);

    // Simulamos un cambio de estado
    estadoActual = ESTADO_PROCESANDO;
    printf("Nuevo estado: %d\n", estadoActual);

    // Simulamos otro cambio de estado
    estadoActual = ESTADO_FINALIZADO;
    printf("Estado final: %d\n", estadoActual);

    return 0;
}
```

La variable `estadoActual` cambia para indicar la fase en la que se encuentra el
proceso.

---

### Variable de Entrada

Una **variable de entrada** es aquella que se utiliza para almacenar datos que
provienen de una fuente externa al programa, como la entrada del usuario a
través del teclado, la lectura de un archivo o datos recibidos de una red.

```c
#include <stdio.h>

int main() {
    int edad; // 'edad' es una variable de entrada

    printf("Por favor, ingresa tu edad: ");
    scanf("%d", &edad); // Aquí, el valor ingresado se guarda en 'edad'

    printf("Tu edad es: %d años.\n", edad);
    return 0;
}
```

En este ejemplo, `edad` toma el valor que el usuario introduce.

---

### Variable de Salida

Las **variables de salida** se utilizan para almacenar los resultados finales de
un cálculo o proceso, los cuales serán mostrados al usuario o guardados en algún
medio (como un archivo).

```c
#include <stdio.h>

int main() {
    float radio = 5.0;
    float area; // 'area' es una variable de salida (resultado)

    // Calculamos el área del círculo
    area = 3.14159 * radio * radio;

    printf("El area del circulo con radio %.2f es: %.2f\n", radio, area); // Se muestra el valor de 'area'
    return 0;
}
```

Aquí, `area` guarda el resultado del cálculo y luego se imprime.

---

### Variable de Referencia (o Puntero)

Aunque en C los punteros son un concepto más avanzado, un puntero es una
variable que almacena la **dirección de memoria** de otra variable. Su rol es
"apuntar" a datos, permitiendo un acceso y manipulación indirecta de la memoria.

```c
#include <stdio.h>

int main() {
    int numero = 100;
    int *ptrNumero; // 'ptrNumero' es un puntero, su rol es referenciar a 'numero'

    ptrNumero = &numero; // 'ptrNumero' ahora apunta a la dirección de 'numero'

    printf("Valor de numero: %d\n", numero);
    printf("Direccion de numero: %p\n", (void*)&numero);
    printf("Valor al que apunta ptrNumero: %d\n", *ptrNumero); // Desreferencia el puntero
    printf("Valor de ptrNumero (direccion): %p\n", (void*)ptrNumero);

    // Modificando 'numero' a traves del puntero
    *ptrNumero = 200;
    printf("Nuevo valor de numero (modificado via puntero): %d\n", numero);

    return 0;
}
```

El rol de `ptrNumero` es el de una **variable de referencia**, permitiendo
interactuar con `numero` de forma indirecta.

---

## Roles de Variables y Parámetros Útiles en Funciones

Cuando hablamos de funciones, las variables internas y, crucialmente, los
**parámetros** (que son variables que reciben valores cuando se llama a la
función) también asumen roles distintivos:

---

### Parámetro de Entrada

Un **parámetro de entrada** es una variable que recibe un valor de la parte que
llama a la función (el "código invocador"). Su rol es **proporcionar a la
función los datos necesarios** para que realice su tarea. La función usa este
valor, pero generalmente no lo modifica de forma que el llamador vea ese cambio
(a menos que se pase por referencia).

```c
#include <stdio.h>

// 'num1' y 'num2' son parámetros de entrada
int sumar(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

int main() {
    int a = 5;
    int b = 3;
    int sumaTotal;

    // 'a' y 'b' se pasan como argumentos a los parámetros de entrada 'num1' y 'num2'
    sumaTotal = sumar(a, b);
    printf("La suma es: %d\n", sumaTotal);
    return 0;
}
```

En la función `sumar`, `num1` y `num2` son **parámetros de entrada**. Reciben
los valores `5` y `3` respectivamente, y la función los usa para realizar la
suma.

---

### Parámetro de Salida (a través de Punteros)

En C, como los parámetros se pasan "por valor" por defecto (lo que significa que
la función recibe una copia del valor y los cambios internos no afectan al
original), para que una función pueda **modificar una variable del llamador y
"devolver" un resultado a través de ella**, necesitamos usar **punteros**. Un
parámetro que es un puntero y se usa con este fin se convierte en un **parámetro
de salida**.

```c
#include <stdio.h>

// 'resultado' es un parámetro de salida (puntero)
void dividir(int dividendo, int divisor, int *cociente, int *resto) {
    if (divisor != 0) {
        *cociente = dividendo / divisor; // Modifica el valor apuntado por 'cociente'
        *resto = dividendo % divisor;   // Modifica el valor apuntado por 'resto'
    } else {
        printf("Error: Division por cero.\n");
        // Podríamos asignar valores especiales o manejar el error de otra forma
        *cociente = 0;
        *resto = 0;
    }
}

int main() {
    int num1 = 17;
    int num2 = 5;
    int miCociente;
    int miResto;

    // Pasamos las direcciones de 'miCociente' y 'miResto'
    dividir(num1, num2, &miCociente, &miResto);

    printf("%d dividido por %d es: Cociente = %d, Resto = %d\n", num1, num2, miCociente, miResto);
    return 0;
}
```

Aquí, `cociente` y `resto` son **parámetros de salida**. La función `dividir`
escribe directamente en las ubicaciones de memoria de `miCociente` y `miResto`
en la función `main` a través de sus punteros, permitiendo que `main` acceda a
los resultados de la división.

---

### Parámetro de Entrada/Salida (a través de Punteros)

Similar al parámetro de salida, un **parámetro de entrada/salida** es un puntero
que permite a la función **leer un valor inicial del llamador y luego
modificarlo**, devolviendo el valor modificado al llamador. Su rol es tanto
recibir datos como devolver datos alterados.

```c
#include <stdio.h>

// 'contador' es un parámetro de entrada/salida
void incrementarContador(int *contador) {
    printf("Valor del contador al entrar a la funcion: %d\n", *contador);
    (*contador)++; // Incrementa el valor apuntado por 'contador'
    printf("Valor del contador al salir de la funcion: %d\n", *contador);
}

int main() {
    int miVariableContador = 10;

    printf("Valor inicial de miVariableContador: %d\n", miVariableContador);

    // Pasamos la dirección de 'miVariableContador'
    incrementarContador(&miVariableContador);

    printf("Valor final de miVariableContador: %d\n", miVariableContador);
    return 0;
}
```

En este caso, `contador` en `incrementarContador` es un **parámetro de
entrada/salida**. La función lee el valor inicial de `miVariableContador`
(`10`), lo incrementa a `11`, y ese cambio se refleja directamente en
`miVariableContador` en `main`.

---

### Variable Local Temporal (en funciones)

Dentro de una función, las variables locales a menudo asumen roles temporales
similares a la variable auxiliar que vimos antes. Su alcance se limita a la
función, y su rol es **servir como espacio de trabajo para cálculos
intermedios** que no necesitan ser devueltos directamente.

```c
#include <stdio.h>

float calcularPromedio(int a, int b, int c) {
    // 'sumaTemporal' es una variable local temporal
    int sumaTemporal = a + b + c;
    float promedio = (float)sumaTemporal / 3.0; // 'promedio' es una variable de salida local
    return promedio;
}

int main() {
    float resultadoPromedio = calcularPromedio(10, 20, 30);
    printf("El promedio es: %.2f\n", resultadoPromedio);
    return 0;
}
```

Aquí, `sumaTemporal` es una **variable local temporal** dentro de
`calcularPromedio`. Su único propósito es almacenar la suma intermedia antes de
calcular el promedio final.

---

### La Importancia de los Roles

Entender estos roles te da una perspectiva más rica sobre cómo funcionan tus
programas. No se trata solo de saber qué tipo de dato almacena una variable,
sino **para qué la estás usando**. Reconocer estos patrones te ayudará a:

- **Escribir código más limpio y legible.**
- **Depurar errores más fácilmente.**
- **Diseñar algoritmos más eficientes y comprensibles.**

Comprender estos roles, especialmente la distinción entre pasar por valor y
pasar por referencia (con punteros) para lograr parámetros de salida o
entrada/salida, es **crucial para diseñar funciones robustas y predecibles en
C**. Te ayuda a definir claramente la "interfaz" de tu función: qué necesita
para trabajar y qué tipo de resultados puede ofrecer de vuelta al código que la
llama.
