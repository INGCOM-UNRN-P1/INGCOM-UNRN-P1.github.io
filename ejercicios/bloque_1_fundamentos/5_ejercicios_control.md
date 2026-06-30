---
title: 'Ejercicios: Control de Flujo'
short_title: '5. Control'
subtitle: 'Problemas y soluciones sobre lazos y condicionales en C'
---

(control-flujo-ejercicios)=
# Ejercicios: Control de Flujo

## Acerca de

Estos ejercicios tienen como propósito ejercitar la lógica condicional, las estructuras de repetición y el control de flujo estructurado y seguro en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-control-flujo`

### Cuestiones de Estilo Aplicables
- **Estructuras de control y llaves:** De acuerdo con la [Regla 0x1001h](../../reglas/1_control.md#0x1001h), todas las estructuras de control deben utilizar llaves (`{}`).
- **Prohibición de `break` y `continue`:** Según la [Regla 0x1002h](../../reglas/1_control.md#0x1002h), se encuentra prohibido el uso descontrolado de `break` y `continue`. En su lugar, se deben estructurar lazos controlados mediante banderas lógicas booleanas.
- **Lazos:** Según la [Regla 0x1003h](../../reglas/1_control.md#0x1003h), utilizá el lazo `for` para iteraciones con rango o contador definido y `while` para lazos controlados por condiciones lógicas.

---

## Estructuras Condicionales

### Ejercicio 5.1 - Condición de aprobación

:::{exercise}
:label: entrada-2
:enumerator: entrada-2

Pedí al usuario que ingrese su nota final (entera) e imprimí su condición:
- "Promociona" si la nota es mayor o igual a 6.
- "Aprueba" si la nota es mayor o igual a 4 pero menor a 6.
- "Desaprueba" si la nota es menor a 4.
:::

:::{solution} entrada-2
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main(void)
{
    int nota = 0;
    printf("Ingrese la nota: ");
    if (scanf("%d", &nota) != 1) {
        printf("Error al leer la nota.\n");
        return 1;
    }

    if (nota >= 6) {
        printf("Promociona\n");
    } else if (nota >= 4) {
        printf("Aprueba\n");
    } else {
        printf("Desaprueba\n");
    }
    return 0;
}
```
:::

---

## Estructuras de Repetición (Lazos)

### Ejercicio 5.2 - Cuenta descendente

:::{exercise}
:label: lazo_while 
:enumerator: while

Escribí un programa en C que imprima los números del 10 al 1 de forma descendente usando un lazo `while`.
:::

:::{solution} lazo_while
:label: solucion-lazo_while
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int main(void) {
    int i = 10;
    while (i >= 1) {
        printf("%d\n", i);
        i = i - 1;
    }
    return 0;
}
```
:::

### Ejercicio 5.3 - Múltiplos de 3

:::{exercise}
:label: lazo_for
:enumerator: for
Usá un lazo `for` para mostrar los números múltiplos de 3 comprendidos en el rango de 0 a 30 inclusive.
:::

:::{solution} lazo_for
:label: solucion-lazo_for
:class: dropdown
```c
#include <stdio.h>

int main(void) {
    for (int i = 0; i <= 30; i = i + 1) {
        if (i % 3 == 0) {
            printf("%d es múltiplo de 3\n", i);
        }
    }
    return 0;
}
```
:::

### Ejercicio 5.4 - Clave de acceso con do-while

:::{exercise}
:label: lazo_repeat
:enumerator: for

Diseñá un programa con un lazo `do...while` que solicite repetidamente una clave de acceso numérica al usuario hasta que ingrese el valor correcto `1234`.
:::

:::{solution} lazo_repeat
:label: solucion-lazo_repeat
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

int main(void) {
    int clave = 0;
    int clave_correcta = 1234;

    do {
        printf("Ingrese la clave: ");
        if (scanf("%d", &clave) != 1) {
            printf("Error al leer la clave.\n");
            return 1;
        }

        if (clave != clave_correcta) {
            printf("Clave incorrecta. Reintente.\n");
        }
    } while (clave != clave_correcta);

    printf("Acceso concedido.\n");
    return 0;
}
```
:::

---

## Control de Flujo Seguro

### Ejercicio 5.5 - Refactorización de break

:::{exercise}
:label: lazo_break
:enumerator: break
Modificá el siguiente programa para eliminar la instrucción `break` prohibida, estructurando correctamente el lazo:

```{code-block} c
:linenos:
#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("valor actual: %d\n", i);
        if (i == 4) {
            break;
        }
    }
    return 0;
}
```
:::

:::{solution} lazo_break
:label: solucion-lazo_break
:class: dropdown
Se reestructura el lazo reemplazando el `for` e implementando un lazo `while` controlado por una bandera lógica booleana (`bool`) del encabezado `<stdbool.h>` que se establece en `false` al alcanzar la condición de parada:

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int i = 0;
    bool continuar = true;
    while (i < 10 && continuar) {
        printf("valor actual: %d\n", i);
        if (i == 4) {
            continuar = false;
        }
        i++;
    }
    return 0;
}
```
:::

### Ejercicio 5.6 - Refactorización de continue

:::{exercise}
:label: lazo_continue
:enumerator: continue
Modificá el siguiente código para eliminar la instrucción `continue` prohibida:

```{code-block} c
:linenos:
#include <stdio.h>

int main()
{
    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("i = %d\n", i);
    }
    return 0;
}
```
:::

:::{solution} lazo_continue
:label: solucion-lazo_continue
:class: dropdown
Se reestructura el lazo de forma segura eliminando la instrucción `continue` y encerrando el cuerpo restante del lazo dentro de una condición positiva que filtra los elementos que se desean procesar (en este caso, los impares):

```{code-block} c
:linenos:
#include <stdio.h>

int main(void) {
    for (int i = 0; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("i = %d\n", i);
        }
    }
    return 0;
}
```
:::

### Ejercicio 5.7 - Lazo de clave con bandera

:::{exercise}
:label: lazo_flag_break
:enumerator: continue

Reescribí el ingreso de clave de acceso del Ejercicio 5.4 utilizando un lazo controlado por una bandera booleana (`bool`) en lugar de `do...while`.
:::

:::{solution} lazo_flag_break
:label: solucion-lazo_flag_break
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int clave = 0;
    int clave_correcta = 1234;
    bool clave_correcta_ingresada = false;

    while (clave_correcta_ingresada == false) {
        printf("Ingrese la clave de acceso: ");
        if (scanf("%d", &clave) != 1) {
            printf("Error al leer la clave.\n");
            return 1;
        }

        if (clave == clave_correcta) {
            printf("Acceso concedido.\n");
            clave_correcta_ingresada = true; // Se modifica el estado de la bandera
        } else {
            printf("Clave incorrecta. Intente nuevamente.\n");
        }
    }
    return 0;
}
```
:::

---

## Ejercicios de Práctica

### Ejercicio 5.8 - Mayor de dos números reales
Escribí un programa que solicite dos números reales al usuario y muestre cuál es el mayor.

### Ejercicio 5.9 - Números del 1 al 100
Diseñá un programa que imprima en pantalla los números enteros del 1 al 100 utilizando un lazo `for`.

### Ejercicio 5.10 - Suma de pares del 1 al 100
Desarrollá un algoritmo que sume los números pares comprendidos en el rango del 1 al 100 inclusive.

### Ejercicio 5.11 - Verificación de número primo
Escribí un programa que solicite un número entero positivo e indique si es un número primo (divisible únicamente por 1 y por sí mismo).

### Ejercicio 5.12 - Estado de aprobación de calificación
Escribí un programa que pida una calificación (0 a 10) e indique si el estudiante aprobó (calificación mayor o igual a 4).

### Ejercicio 5.13 - Contraseña de caracteres iterativa
Escribí un programa que solicite repetidamente una contraseña de caracteres al usuario hasta que coincida con un valor establecido de acceso seguro.
