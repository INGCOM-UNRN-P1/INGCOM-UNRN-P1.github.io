---
title: Ejercicios de Entrada y Salida Gradual
short_title: 2. Entrada/Salida Gradual
---

# Ejercicios de Entrada y Salida Gradual

## Acerca de

Estos ejercicios tienen como fin afianzar las operaciones de entrada y salida básica en C empleando `printf` y `scanf`, promoviendo la declaración e inicialización correcta de variables con tipos primitivos básicos.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-introduccion-c`

### Cuestiones de Estilo Aplicables
- **Inicialización de Variables:** De acuerdo con la [Regla 0x0003h](../../reglas/0_sintaxis.md#0x0003h), siempre se deben inicializar las variables a un valor conocido en su declaración.
- **Robustez en Entrada de Datos:** Al utilizar `scanf`, se debe validar su valor de retorno y realizar el purgado del buffer de entrada cuando sea necesario para evitar comportamientos indefinidos (ver [Regla 0x1005h](../../reglas/1_control.md#0x1005h)).

---

## Lectura y Escritura Básica

### Ejercicio 2.1 - Mostrando valores

:::{exercise}
:label: Mostrando valores
:enumerator: Valores
Escribí un programa en C que declare e inicialice variables para tu edad, tu altura en metros y tu inicial de nombre, y muestre sus valores en la consola.
:::

:::{solution} Mostrando valores
:class: dropdown

```{code-block} c
:linenos:

#include <stdio.h>

int main(void) {
    int edad = 20;
    float altura = 1.82f;
    char inicial = 'J';

    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}
```
:::

### Ejercicio 2.2 - Formateo de entrada y salida

:::{exercise}
:label: entrada-1
Pedí al usuario que ingrese su inicial de nombre, edad y calificación promedio, y mostralos formateados en pantalla.
:::

:::{solution} entrada-1
:class: dropdown
```{code-block} c
:linenos:

#include <stdio.h>

int main(void) {
    char inicial = ' ';
    int edad = 0;
    float promedio = 0.0f;

    printf("Ingrese su inicial: ");
    if (scanf(" %c", &inicial) != 1) {
        printf("Error al leer la inicial.\n");
        return 1;
    }

    printf("Ingrese su edad: ");
    if (scanf("%d", &edad) != 1) {
        printf("Error al leer la edad.\n");
        return 1;
    }

    printf("Ingrese su promedio: ");
    if (scanf("%f", &promedio) != 1) {
        printf("Error al leer el promedio.\n");
        return 1;
    }

    printf("Inicial: %c, Edad: %d, Promedio: %.2f\n", inicial, edad, promedio);
    return 0;
}
```
:::