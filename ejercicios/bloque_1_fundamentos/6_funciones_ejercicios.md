---
title: 'Ejercicios sobre Funciones'
short_title: '6. Funciones'
subtitle: 'Problemas y soluciones sobre modularización en C'
---

# Ejercicios sobre Funciones

## Acerca de

Estos ejercicios tienen como finalidad practicar la descomposición modular de problemas en funciones en C, definiendo firmas con sus tipos de datos correspondientes para los parámetros y valores de retorno.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-funciones-descomposicion`

### Cuestiones de Estilo Aplicables
- **Resolución mediante funciones:** Según la [Regla 0x2009h](../../reglas/2_funciones.md#0x2009h), la lógica debe ser encapsulada en funciones independientes.
- **Nomenclatura en funciones:** Los nombres de funciones y variables locales deben seguir la convención `snake_case` en minúsculas, de acuerdo con las reglas [0x200Ah](../../reglas/2_funciones.md#0x200ah) y [0x0007h](../../reglas/0_sintaxis.md#0x0007h).
- **Separación de entrada/salida:** En concordancia con la [Regla 0x2002h](../../reglas/2_funciones.md#0x2002h), se debe evitar que las funciones realicen entrada/salida (I/O) a menos que ese sea su propósito explícito.

---

## Definición y Llamada de Funciones

### Ejercicio 6.1 - Doble de un número

:::{exercise}
:label: funcion_doble
Escribí una función que reciba un número entero y devuelva su doble. Probala desde `main()` con distintos valores.
:::

:::{solution} funcion_doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int doble(int n) {
    return 2 * n;
}

int main(void) {
    printf("Doble de 5: %d\n", doble(5));
    printf("Doble de 12: %d\n", doble(12));
    return 0;
}
```
:::

### Ejercicio 6.2 - Mayor de dos números

:::{exercise}
:label: funcion_mayor
:enumerator: funciones-2

Programá una función que reciba dos números enteros y retorne el mayor de ellos.
:::

:::{solution} funcion_mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int mayor(int a, int b) {
    int resultado = a;
    if (b > a) {
        resultado = b;
    }
    return resultado;
}

int main(void) {
    int x = 10;
    int y = 7;
    printf("El mayor es: %d\n", mayor(x, y));
    return 0;
}
```
:::

### Ejercicio 6.3 - Paridad de un número

:::{exercise}
:label: funcion_par_impar
Definí una función que indique si un número es par o impar. Mostrá el resultado llamando a la función desde `main()`.
:::

:::{solution} funcion_par_impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

void par_impar(int n) {
    if (n % 2 == 0) {
        printf("%d es par\n", n);
    } else {
        printf("%d es impar\n", n);
    }
}

int main(void) {
    par_impar(7);
    par_impar(12);
    return 0;
}
```
:::

### Ejercicio 6.4 - Promedio de notas

:::{exercise}
:label: funcion_promedio
:enumerator: funciones-4
Escribí una función que reciba tres notas enteras y devuelva el promedio en punto flotante. Mostrá el resultado en `main()`.
:::

:::{solution} funcion_promedio
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

float promedio(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

int main(void) {
    printf("Promedio: %.2f\n", promedio(7, 8, 10));
    return 0;
}
```
:::

### Ejercicio 6.5 - Área de rectángulo

:::{exercise}
:label: funcion_area
Implementá una función `area_rectangulo` que reciba base y altura, y devuelva el área.
:::

:::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int area_rectangulo(int base, int altura) {
    return base * altura;
}

int main(void) {
    printf("Área: %d\n", area_rectangulo(5, 4));
    return 0;
}
```
:::