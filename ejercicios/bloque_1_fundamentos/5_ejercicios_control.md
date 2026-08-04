---
title: 'Ejercicios: Control de Flujo'
short_title: '5. Control'
subtitle: 'Problemas y soluciones sobre lazos y condicionales en C'
---

(control-flujo-ejercicios)=
# Ejercicios: Control de Flujo

## Acerca de

Estos ejercicios tienen como propósito ejercitar la lógica condicional, las
estructuras de repetición y el control de flujo estructurado y seguro en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-control-flujo`

### Cuestiones de Estilo Aplicables
- **Estructuras de control y llaves:** De acuerdo con la [Regla
  0x1001h](../../reglas/1_control.md#0x1001h), todas las estructuras de control
  deben utilizar llaves (`{}`).
- **Prohibición de `break` y `continue`:** Según la [Regla
  0x1002h](../../reglas/1_control.md#0x1002h), se encuentra prohibido el uso
  descontrolado de `break` y `continue`. En su lugar, se deben estructurar lazos
  controlados mediante banderas lógicas booleanas.
- **Lazos:** Según la [Regla 0x1003h](../../reglas/1_control.md#0x1003h),
  utilizá el lazo `for` para iteraciones con rango o contador definido y `while`
  para lazos controlados por condiciones lógicas.

---

## Estructuras Condicionales
(ejercicio_4_1)=
### Ejercicio 4.1 - Condición de aprobación ⭐⭐☆☆☆

:::{exercise}
:label: entrada-2
:enumerator: entrada-2

Pedí al usuario que ingrese su nota final (entera) e imprimí su condición:
- "Promociona" si la nota es mayor o igual a 6.
- "Aprueba" si la nota es mayor o igual a 4 pero menor a 6.
- "Desaprueba" si la nota es menor a 4.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

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
<!-- {code-block} c -->

:::
<!-- {solution} entrada-2 -->

---

## Estructuras de Repetición (Lazos)
(ejercicio_4_2)=
### Ejercicio 4.2 - Cuenta descendente ⭐⭐☆☆☆

:::{exercise}
:label: lazo_while 
:enumerator: while

Escribí un programa en C que imprima los números del 10 al 1 de forma
descendente usando un lazo `while`.

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {exercise} -->

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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_while -->
(ejercicio_4_3)=
### Ejercicio 4.3 - Múltiplos de 3 ⭐⭐☆☆☆

:::{exercise}
:label: lazo_for
:enumerator: for
Usá un lazo `for` para mostrar los números múltiplos de 3 comprendidos en el
rango de 0 a 30 inclusive.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

:::{solution} lazo_for
:label: solucion-lazo_for
:class: dropdown
```{code-block} c
:linenos:
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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_for -->
(ejercicio_4_4)=
### Ejercicio 4.4 - Clave de acceso con do-while ⭐⭐☆☆☆

:::{exercise}
:label: lazo_repeat
:enumerator: for

Diseñá un programa con un lazo `do...while` que solicite repetidamente una clave
de acceso numérica al usuario hasta que ingrese el valor correcto `1234`.

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {exercise} -->

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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_repeat -->

---

## Control de Flujo Seguro
(ejercicio_4_5)=
### Ejercicio 4.5 - Refactorización de break ⭐⭐☆☆☆

:::{exercise}
:label: lazo_break
:enumerator: break
Modificá el siguiente programa para eliminar la instrucción `break` prohibida,
estructurando correctamente el lazo:

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
<!-- {code-block} c -->

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

:::{solution} lazo_break
:label: solucion-lazo_break
:class: dropdown
Se reestructura el lazo reemplazando el `for` e implementando un lazo `while`
controlado por una bandera lógica booleana (`bool`) del encabezado `<stdbool.h>`
que se establece en `false` al alcanzar la condición de parada:

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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_break -->
(ejercicio_4_6)=
### Ejercicio 4.6 - Refactorización de continue ⭐⭐☆☆☆

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
<!-- {code-block} c -->

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

:::{solution} lazo_continue
:label: solucion-lazo_continue
:class: dropdown
Se reestructura el lazo de forma segura eliminando la instrucción `continue` y
encerrando el cuerpo restante del lazo dentro de una condición positiva que
filtra los elementos que se desean procesar (en este caso, los impares):

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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_continue -->
(ejercicio_4_7)=
### Ejercicio 4.7 - Lazo de clave con bandera ⭐⭐☆☆☆

:::{exercise}
:label: lazo_flag_break
:enumerator: continue

Reescribí el ingreso de clave de acceso del Ejercicio 5.4 utilizando un lazo
controlado por una bandera booleana (`bool`) en lugar de `do...while`.

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {exercise} -->

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
<!-- {code-block} c -->

:::
<!-- {solution} lazo_flag_break -->

---
(ejercicio_4_8)=
## Ejercicio 4.8 - s de Práctica ⭐⭐☆☆☆

(ejercicio_4_9)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.9 - Mayor de dos números reales ⭐⭐☆☆☆

Escribí un programa que solicite dos números reales al usuario y muestre cuál es
el mayor.
(ejercicio_4_10)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.10 - Números del 1 al 100 ⭐⭐☆☆☆

Diseñá un programa que imprima en pantalla los números enteros del 1 al 100
utilizando un lazo `for`.
(ejercicio_4_11)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.11 - Suma de pares del 1 al 100 ⭐⭐☆☆☆

Desarrollá un algoritmo que sume los números pares comprendidos en el rango del
1 al 100 inclusive.
(ejercicio_4_12)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.12 - Verificación de número primo ⭐⭐☆☆☆

Escribí un programa que solicite un número entero positivo e indique si es un
número primo (divisible únicamente por 1 y por sí mismo).
(ejercicio_4_13)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.13 - Estado de aprobación de calificación ⭐⭐⭐☆☆

Escribí un programa que pida una calificación (0 a 10) e indique si el
estudiante aprobó (calificación mayor o igual a 4).
(ejercicio_4_14)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.14 - Contraseña de caracteres iterativa ⭐⭐☆☆☆

Escribí un programa que solicite repetidamente una contraseña de caracteres al
usuario hasta que coincida con un valor establecido de acceso seguro.
(ejercicio_4_15)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

## Ejercicio 4.15 - Contar del 1 al 10 ⭐☆☆☆☆

Mostrá los números del 1 al 10 usando un lazo `for`.

**Orientación:**
- `for (int i = 1; i <= 10; i++)`
- Imprimí cada número en una línea


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_16)=
## Ejercicio 4.16 - Suma de N Números ⭐☆☆☆☆

Leé un número N y calculá la suma de los primeros N números naturales.

**Orientación:**
- Usá lazo `for` de 1 a N
- Acumulá la suma en una variable
- Alternativa: fórmula directa suma = N × (N+1) / 2


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_17)=
## Ejercicio 4.17 - Tabla de Multiplicar ⭐⭐☆☆☆

Mostrá la tabla de multiplicar de un número ingresado por el usuario (1 a 10).

**Orientación:**
- Leé el número
- Lazo de 1 a 10: `printf("%d x %d = %d\n", num, i, num * i);`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_18)=
## Ejercicio 4.18 - Factorial con While ⭐⭐☆☆☆

Calculá el factorial de N usando un lazo `while`.

**Orientación:**
- Inicializá resultado = 1, contador = N
- Mientras contador > 0: resultado *= contador, contador--
- Manejá caso especial: 0! = 1


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_19)=
## Ejercicio 4.19 - Números Pares en Rango ⭐⭐☆☆☆

Mostrá todos los números pares entre dos valores ingresados.

**Orientación:**
- Leé inicio y fin
- Lazo de inicio a fin
- Usá `if (i % 2 == 0)` para detectar pares
- Alternativa: `for (i = inicio; i <= fin; i += 2)` empezando en par


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_20)=
## Ejercicio 4.20 - Suma hasta Cero ⭐⭐☆☆☆

Leé números enteros hasta que el usuario ingrese 0, luego mostrá la suma total.

**Orientación:**
- Usá `while (true)` o `do-while`
- Leé número
- Si es 0, `break`
- Caso contrario, sumá al acumulador


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_21)=
## Ejercicio 4.21 - Validación de Entrada ⭐⭐⭐☆☆

Leé un número entre 1 y 100. Si está fuera de rango, pedí nuevamente hasta que
sea válido.

**Orientación:**
- `do-while` es ideal aquí
- `do { leer numero } while (numero < 1 || numero > 100);`
- Mostrá mensaje de error en cada intento inválido


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_22)=
## Ejercicio 4.22 - Contar Dígitos ⭐⭐⭐☆☆

Contá cuántos dígitos tiene un número entero.

**Orientación:**
- Usá lazo `while (n > 0)`
- Dividí por 10 en cada iteración: `n /= 10`
- Incrementá contador
- Caso especial: 0 tiene 1 dígito


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_23)=
## Ejercicio 4.23 - Número Primo ⭐⭐⭐☆☆

Determiná si un número es primo probando divisibilidad.

**Orientación:**
- Si N <= 1: no primo
- Si N = 2: primo
- Probá divisores de 2 a √N
- Si alguno divide exacto: no primo
- Optimización: después del 2, probar solo impares


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_24)=
## Ejercicio 4.24 - Secuencia de Fibonacci ⭐⭐⭐☆☆

Generá los primeros N números de Fibonacci.

**Orientación:**
- Inicializá `a = 0, b = 1`
- Lazo N veces:
  - Mostrá `a`
  - Calculá siguiente: `temp = a + b; a = b; b = temp`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_25)=
## Ejercicio 4.25 - Búsqueda en Array ⭐⭐⭐☆☆

Buscá un valor en un array. Si lo encontrás, mostrá su posición y `break`.

**Orientación:**
- Recorré array con `for`
- Compará cada elemento con el buscado
- Si coincide: guardá índice, `break`
- Después del lazo: verificá si se encontró


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_26)=
## Ejercicio 4.26 - Menú Interactivo ⭐⭐⭐☆☆

Implementá un menú que se repita hasta que el usuario elija "Salir".

**Orientación:**
- Lazo `while (opcion != SALIR)`
- Mostrá menú
- Leé opción
- `switch` para ejecutar acción
- Opción salir termina el lazo


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_27)=
## Ejercicio 4.27 - Mayor y Menor de N Números ⭐⭐⭐☆☆

Leé N números y encontrá el mayor y menor.

**Orientación:**
- Inicializá `mayor` y `menor` con el primer número
- Lazo desde el segundo número:
  - Si actual > mayor: actualizar mayor
  - Si actual < menor: actualizar menor


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_28)=
## Ejercicio 4.28 - Invertir un Número ⭐⭐⭐⭐☆

Invertí los dígitos de un número (ej: 1234 → 4321).

**Orientación:**
- `invertido = 0`
- Mientras n > 0:
  - `digito = n % 10`
  - `invertido = invertido * 10 + digito`
  - `n /= 10`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_29)=
## Ejercicio 4.29 - Números Perfectos ⭐⭐⭐⭐☆

Encontrá todos los números perfectos hasta N. Un número es perfecto si la suma
de sus divisores (excluyéndolo) es igual al número.

**Ejemplo:** 6 = 1 + 2 + 3

**Orientación:**
- Lazo externo: de 1 a N
- Lazo interno: encontrar divisores de 2 a n/2
- Sumá divisores
- Si suma == número: es perfecto


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_30)=
## Ejercicio 4.30 - Patrón de Asteriscos - Triángulo ⭐⭐⭐⭐☆

Dibujá un triángulo de asteriscos de altura N.

**Ejemplo (N=5):**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

```
*
**
***
****
*****
```

**Orientación:**
- Lazo externo: filas (1 a N)
- Lazo interno: columnas (1 a fila_actual)
- Imprimí asterisco en cada columna
- Nueva línea después de cada fila

---
(ejercicio_4_31)=
## Ejercicio 4.31 - Máximo Común Divisor (Euclides) ⭐⭐⭐⭐☆

Implementá el algoritmo de Euclides iterativo para calcular MCD.

**Algoritmo:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

```
mientras b != 0:
    temp = b
    b = a % b
    a = temp
retornar a
```

**Orientación:**
- Usá lazo `while (b != 0)`
- Guardá resto en variable temporal
- Intercambiá valores

---
(ejercicio_4_32)=
## Ejercicio 4.32 - Número de Armstrong ⭐⭐⭐⭐☆

Determiná si un número es Armstrong (suma de sus dígitos elevados a la cantidad
de dígitos igual al número).

**Ejemplo:** 153 = 1³ + 5³ + 3³ = 153

**Orientación:**
- Primer lazo: contar dígitos
- Segundo lazo: sumar dígitos elevados a esa potencia
- Comparar suma con número original
- Usá `pow()` de `<math.h>`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_33)=
## Ejercicio 4.33 - Simulación de Cajero Automático ⭐⭐⭐⭐⭐

Simulá un cajero con saldo inicial. Menú: depositar, retirar, consultar, salir.

**Requisitos:**
- No permitir retiros mayores al saldo
- Validar montos positivos
- Mostrar saldo después de cada operación
- Lazo hasta que elija salir

**Orientación:**
- Variable `saldo` inicial
- Lazo principal con menú
- `switch` para operaciones
- Validaciones antes de modificar saldo


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_34)=
## Ejercicio 4.34 - Criba de Eratóstenes ⭐⭐⭐⭐⭐

Encontrá todos los números primos hasta N usando la Criba de Eratóstenes.

**Algoritmo:**
1. Creá array booleano de tamaño N+1, todos en `true`
2. Marcá 0 y 1 como no primos
3. Para cada número i de 2 a √N:
   - Si i es primo (marcado `true`):
     - Marcá todos sus múltiplos como no primos
4. Los que quedaron en `true` son primos

**Orientación:**
- Array: `bool es_primo[N+1]`
- Lazo externo: `i` de 2 a √N
- Lazo interno: múltiplos de `i` (desde i², incrementando de i en i)
- Mostrá todos los marcados como primos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_35)=
## Ejercicio 4.35 - s Adicionales de Patrones ⭐⭐☆☆☆

(ejercicio_4_36)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 4.36 - Pirámide Centrada ⭐⭐⭐⭐⭐

Dibujá una pirámide centrada de asteriscos.

**Ejemplo (N=5):**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

```
    *
   ***
  *****
 *******
*********
```

**Orientación:**
- Para cada fila i (de 0 a N-1):
  - Imprimí (N-i-1) espacios
  - Imprimí (2*i+1) asteriscos
  - Nueva línea

---
(ejercicio_4_37)=
### Ejercicio 4.37 - Rombo ⭐⭐⭐⭐⭐

Dibujá un rombo de asteriscos.

**Orientación:**
- Mitad superior: pirámide creciente
- Mitad inferior: pirámide decreciente
- Mismo principio de espacios y asteriscos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Problemas de Lazos Anidados
(ejercicio_4_38)=
### Ejercicio 4.38 - Tabla de Multiplicar Completa ⭐⭐⭐⭐☆

Mostrá tabla de multiplicar del 1 al 10 (todas las tablas).

**Orientación:**
- Lazo externo: números del 1 al 10
- Lazo interno: multiplicadores del 1 al 10
- Formato: "3 x 4 = 12"


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_39)=
### Ejercicio 4.39 - Números Primos en Rango ⭐⭐⭐⭐☆

Mostrá todos los números primos entre A y B.

**Orientación:**
- Lazo externo: números de A a B
- Lazo interno: verificar si es primo (función del ejercicio 9)
- Imprimí solo los primos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Problemas de Validación y Control
(ejercicio_4_40)=
### Ejercicio 4.40 - Juego de Adivinanza Mejorado ⭐⭐⭐⭐⭐

El programa elige un número aleatorio. El usuario tiene máximo 7 intentos.

**Orientación:**
- `rand() % 100 + 1` para número aleatorio
- Lazo con contador de intentos
- Dar pistas ("muy alto", "muy bajo")
- `break` si adivina
- Después del lazo: verificar si ganó o perdió


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Notas Finales

:::{tip} Elección del Lazo Apropiado

**`for`:** Cuando sabés cuántas iteraciones hacer
- Recorrer arrays
- Contar de A a B
- N iteraciones fijas

**`while`:** Cuando la condición de parada se evalúa al inicio
- Menús interactivos
- Búsquedas
- Procesamiento hasta condición

**`do-while`:** Cuando necesitás ejecutar al menos una vez
- Validación de entrada
- Menús que deben mostrarse al menos una vez
- "Repetir hasta que el usuario confirme"

:::
<!-- {tip} Elección del Lazo Apropiado -->

:::{warning} Errores Comunes

1. **Lazo infinito:** Olvidar incrementar/decrementar variable de control
   ```c
   // MAL
   while (i < 10) {
       printf("%d\n", i);
       // Falta i++
   }
   ```

2. **Off-by-one:** Error en condición de parada
   ```c
   // Quiero 10 iteraciones
   for (int i = 1; i < 10; i++)  // MAL: solo 9 iteraciones
   for (int i = 1; i <= 10; i++) // BIEN: 10 iteraciones
   for (int i = 0; i < 10; i++)  // BIEN: 10 iteraciones
   ```

3. **Modificar variable de control dentro del lazo**
   ```c
   // Confuso
   for (int i = 0; i < 10; i++) {
       i += 2;  // Evitar esto
   }
   ```

4. **Condición incorrecta con `break`**
   ```c
   // Redundante
   while (true) {
       if (condicion) break;
   }
   // Mejor
   while (!condicion) {
       // código
   }
   ```

:::
<!-- {warning} Errores Comunes -->

:::{note} Control de Lazos

**`break`:** Termina el lazo inmediatamente
``` c
for (int i = 0; i < 10; i++) {
    if (condicion) break;  // Sale del lazo
}
```
<!-- c -->

**`continue`:** Salta a la siguiente iteración
``` c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;  // Salta pares
    printf("%d\n", i);  // Solo imprime impares
}
```
<!-- c -->

**Recomendación:** Usá `break` y `continue` con moderación. Preferí condiciones
claras.

:::
<!-- {note} Control de Lazos -->

:::{tip} Optimizaciones

- **Reducir iteraciones:** En búsqueda de primos, probar solo hasta √n
- **Salir temprano:** Usar `break` cuando encontrás lo que buscás
- **Precalcular:** Si una expresión no cambia en el lazo, calculala afuera
- **Evitar trabajo redundante:** Caché resultados que se reusan

:::
<!-- {tip} Optimizaciones -->

Estas consignas cubren todos los aspectos de lazos: `for`, `while`, `do-while`,
lazos anidados, control de flujo y validación con repetición.
(ejercicio_4_41)=
## Ejercicio 4.41 - Mostrar Argumentos ⭐☆☆☆☆

Mostrá todos los argumentos recibidos.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
int main(int argc, char *argv[]) {
    printf("Cantidad de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}

```
<!-- {code-block} c -->
- `argv[0]` es el nombre del programa

---
(ejercicio_4_42)=
## Ejercicio 4.42 - Saludo Personalizado ⭐☆☆☆☆

Lee un nombre desde argv y saludá.

**Uso:** `./saludo Juan`

**Orientación:**
- Verificá: `if (argc != 2) { fprintf(stderr, "Uso: %s <nombre>\n", argv[0]);
  return 1; }`
- Usá: `printf("Hola, %s!\n", argv[1]);`


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_43)=
## Ejercicio 4.43 - Suma de Dos Números ⭐⭐☆☆☆

Sumá dos números pasados como argumentos.

**Uso:** `./suma 5 3`

**Orientación:**
- Verificá `argc == 3`
- Convertí con `atoi`: `int a = atoi(argv[1]);`
- O mejor: `strtol(argv[1], NULL, 10)` para validación


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_44)=
## Ejercicio 4.44 - Calculadora Simple ⭐⭐⭐☆☆

Implementá calculadora: `./calc <num1> <operador> <num2>`

**Uso:** `./calc 10 + 5`

**Orientación:**
- `argc == 4`
- `argv[2]` es el operador: `+`, `-`, `*`, `/`
- Usá `switch` o `if-else` para operación
- Validá división por cero


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_45)=
## Ejercicio 4.45 - Flags Booleanos ⭐⭐⭐☆☆

Procesá flags opcionales `-v` (verbose) y `-h` (help).

**Uso:** `./programa -v archivo.txt`

**Orientación:**
- Recorré `argv` buscando strings que empiecen con `-`
- `if (strcmp(argv[i], "-v") == 0) verbose = true;`
- Argumentos no-flag son archivos u otros datos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_46)=
## Ejercicio 4.46 - Concatenar Argumentos ⭐⭐☆☆☆

Concatená todos los argumentos (excepto argv[0]) en un string.

**Uso:** `./concat Hola mundo desde C`
**Salida:** `Hola mundo desde C`

**Orientación:**
- Recorré argv desde índice 1
- Concatená con espacios intermedios
- Usá `strcat` o manualmente con índices


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_47)=
## Ejercicio 4.47 - Conversor de Temperatura ⭐⭐⭐☆☆

Convertí temperatura según flags.

**Uso:** `./temp -c 100` (Celsius a Fahrenheit)
**Uso:** `./temp -f 212` (Fahrenheit a Celsius)

**Orientación:**
- Flag determina dirección de conversión
- Valor viene después del flag
- Mostrá resultado formateado


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_48)=
## Ejercicio 4.48 - Procesar Archivo(s) ⭐⭐⭐☆☆

Lee uno o más archivos pasados como argumentos y mostrá su contenido.

**Uso:** `./cat archivo1.txt archivo2.txt`

**Orientación:**
- Cada argv[i] (i > 0) es un archivo
- Abrí cada uno, leé y mostrá
- Si falla abrir: mostrar error, continuar con siguiente


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_49)=
## Ejercicio 4.49 - Flag con Valor ⭐⭐⭐⭐☆

Procesá flag que requiere un valor: `-n <cantidad>`

**Uso:** `./programa -n 10 archivo.txt`

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-n") == 0) {
        if (i + 1 < argc) {
            cantidad = atoi(argv[++i]);  // Incrementa i
        } else {
            fprintf(stderr, "Flag -n requiere valor\n");
        }
    }
}

```
<!-- {code-block} c -->

---
(ejercicio_4_50)=
## Ejercicio 4.50 - Múltiples Flags ⭐⭐⭐⭐☆

Implementá programa con varios flags: `-v` (verbose), `-o <salida>`, `-n <num>`

**Uso:** `./programa -v -o salida.txt -n 100 entrada.txt`

**Orientación:**
- Variables para cada flag
- Lazo procesando argv
- Flags pueden estar en cualquier orden
- Argumentos sin `-` son archivos de entrada


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar la correcta apertura del archivo y controlar
    errores de E/S con `ferror` y `feof`.
-   **[*plus ultra*]:** Soportar rutas complejas y asegurar el cierre del
    archivo en todos los caminos de ejecución.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_51)=
## Ejercicio 4.51 - Validación de Argumentos ⭐⭐⭐☆☆

Validá que números sean realmente números.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
char *endptr;
long num = strtol(argv[1], &endptr, 10);
if (*endptr != '\0') {
    fprintf(stderr, "Error: '%s' no es un número válido\n", argv[1]);
    return 1;
}

```
<!-- {code-block} c -->
- `strtol` pone en `endptr` el primer carácter no-numérico
- Si `*endptr != '\0'`, hay caracteres inválidos

---
(ejercicio_4_52)=
## Ejercicio 4.52 - Ayuda Automática ⭐⭐⭐☆☆

Mostrá ayuda si se pasa `-h` o `--help`, o si argumentos son incorrectos.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
void mostrar_ayuda(const char *programa) {
    printf("Uso: %s [opciones] archivo\n", programa);
    printf("Opciones:\n");
    printf("  -h, --help    Mostrar esta ayuda\n");
    printf("  -v            Modo verbose\n");
    printf("  -o <archivo>  Archivo de salida\n");
}

if (argc < 2 || strcmp(argv[1], "-h") == 0 || 
    strcmp(argv[1], "--help") == 0) {
    mostrar_ayuda(argv[0]);
    return 0;
}

```
<!-- {code-block} c -->

---
(ejercicio_4_53)=
## Ejercicio 4.53 - Grep Simplificado ⭐⭐⭐⭐☆

Buscá patrón en archivo(s).

**Uso:** `./grep "patron" archivo1.txt archivo2.txt`

**Orientación:**
- `argv[1]` es el patrón
- `argv[2...]` son archivos
- Leé cada archivo línea por línea
- Si línea contiene patrón (`strstr`), mostrala


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_54)=
## Ejercicio 4.54 - Wc (Word Count) Simplificado ⭐⭐⭐⭐☆

Contá líneas, palabras y caracteres de archivos.

**Uso:** `./wc [-l] [-w] [-c] archivo(s)`

**Flags:**
- `-l`: solo líneas
- `-w`: solo palabras
- `-c`: solo caracteres
- Sin flags: todo

**Orientación:**
- Procesá flags para saber qué contar
- Para cada archivo, calculá métricas
- Mostrá según flags activos


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_55)=
## Ejercicio 4.55 - Sort con Opciones ⭐⭐⭐⭐⭐

Ordená líneas de archivo con opciones.

**Uso:** `./sort [-r] [-n] archivo.txt`

**Flags:**
- `-r`: orden reverso
- `-n`: orden numérico (en lugar de lexicográfico)

**Orientación:**
- Leé archivo completo en array de strings
- Ordená según flags
- Usá `qsort` con función comparadora apropiada


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_56)=
## Ejercicio 4.56 - Procesamiento de Lote ⭐⭐⭐⭐⭐

Aplicá operación a múltiples archivos.

**Uso:** `./batch -op <operacion> archivo1 archivo2 ...`

**Operaciones:** `upper`, `lower`, `reverse`, `count`

**Orientación:**
- Flag `-op` determina operación
- Aplicá a todos los archivos siguientes
- Escribí resultado en archivo.out para cada uno


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar la correcta apertura del archivo y controlar
    errores de E/S con `ferror` y `feof`.
-   **[*plus ultra*]:** Soportar rutas complejas y asegurar el cierre del
    archivo en todos los caminos de ejecución.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_57)=
## Ejercicio 4.57 - Configuración desde Archivo y Args ⭐⭐⭐⭐⭐

Leé configuración de archivo, permitiendo override por línea de comandos.

**Uso:** `./programa -c config.txt -n 50`

**Orientación:**
- Leé config.txt primero (formato `clave=valor`)
- Argumentos de línea de comandos sobrescriben config
- Precedencia: defaults < archivo < args


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar la correcta apertura del archivo y controlar
    errores de E/S con `ferror` y `feof`.
-   **[*plus ultra*]:** Soportar rutas complejas y asegurar el cierre del
    archivo en todos los caminos de ejecución.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_58)=
## Ejercicio 4.58 - Pipeline Simulado ⭐⭐⭐⭐⭐

Implementá programa que puede leer de stdin o archivo.

**Uso:** 
- `./proceso archivo.txt`
- `cat archivo.txt | ./proceso`

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar la correcta apertura del archivo y controlar
    errores de E/S con `ferror` y `feof`.
-   **[*plus ultra*]:** Soportar rutas complejas y asegurar el cierre del
    archivo en todos los caminos de ejecución.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
FILE *entrada;
if (argc > 1) {
    entrada = fopen(argv[1], "r");
} else {
    entrada = stdin;  // Lee de stdin
}

```
<!-- {code-block} c -->
- Permite composición estilo Unix

---
(ejercicio_4_59)=
## Ejercicio 4.59 - Getopt Simplificado ⭐⭐⭐⭐⭐

Implementá tu propia versión simplificada de `getopt` para parsear flags.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
int getopt_simple(int argc, char *argv[], const char *optstring);
```
<!-- c -->
- `optstring`: "vhn:" (v y h sin valor, n con valor)
- Retorna carácter del flag o -1
- Variable global `optarg` con valor del flag

---
(ejercicio_4_60)=
## Ejercicio 4.60 - Sistema de Comandos ⭐⭐⭐⭐⭐

Implementá programa con subcomandos estilo Git.

**Uso:** 
- `./tool add archivo.txt`
- `./tool remove archivo.txt`
- `./tool list`

**Orientación:**
- `argv[1]` es el subcomando
- `argv[2...]` son argumentos del subcomando
- Cada subcomando tiene su propia lógica
- `switch` o tabla de funciones para dispatch


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

---

## Notas Finales

:::{tip} Convenciones de Argumentos

**Orden típico:**
```
programa [opciones] [argumentos_posicionales]
```

**Formatos de flags:**
- Short: `-v`, `-n 10`
- Long: `--verbose`, `--number=10`
- Combinados: `-vvv` o `-abc` (equiv. `-a -b -c`)

**Convenciones:**
- `-h` o `--help`: ayuda
- `-v` o `--version`: versión
- `-`: stdin (entrada estándar)
- `--`: fin de opciones, resto son argumentos

:::
<!-- {tip} Convenciones de Argumentos -->

:::{warning} Errores Comunes

1. **No validar argc:**
   ```c
   // MAL
   int n = atoi(argv[1]);  // Puede acceder fuera de límites
   
   // BIEN
   if (argc < 2) {
       fprintf(stderr, "Faltan argumentos\n");
       return 1;
   }
   int n = atoi(argv[1]);
   ```

2. **Asumir orden de flags:**
   ```c
   // Poco robusto
   if (strcmp(argv[1], "-v") == 0) ...
   
   // Mejor: recorrer buscando flags
   for (int i = 1; i < argc; i++) {
       if (strcmp(argv[i], "-v") == 0) verbose = true;
   }
   ```

3. **No validar conversiones:**
   ```c
   int n = atoi("abc");  // Retorna 0, sin error
   
   // Mejor:
   char *end;
   long n = strtol(argv[1], &end, 10);
   if (*end != '\0') { /* error */ }
   ```

4. **Olvidar incrementar índice con flags que tienen valor:**
   ```c
   if (strcmp(argv[i], "-n") == 0) {
       n = atoi(argv[i+1]);  // Usá i+1
       // FALTA: i++; para saltar el valor
   }
   ```

:::
<!-- {warning} Errores Comunes -->

:::{note} Funciones de Conversión

| Función | Tipo destino | Validación | Base |
|---------|--------------|------------|------|
| `atoi` | int | ❌ No | 10 |
| `atol` | long | ❌ No | 10 |
| `atof` | double | ❌ No | - |
| `strtol` | long | ✅ Sí | Cualquiera |
| `strtod` | double | ✅ Sí | - |
| `sscanf` | Varios | ✅ Parcial | - |

**Recomendación:** Usar `strtol`/`strtod` para conversiones robustas.

:::
<!-- {note} Funciones de Conversión -->

:::{tip} Patrones de Parsing

**Flags simples:**
```{code-block} c
:linenos:
bool verbose = false;
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
        verbose = true;
    }
}

```
<!-- {code-block} c -->

**Flags con valor:**
```{code-block} c
:linenos:
const char *output = NULL;
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
        output = argv[++i];
    }
}

```
<!-- {code-block} c -->

**Separar flags de argumentos:**
```{code-block} c
:linenos:
int num_archivos = 0;
char *archivos[MAX];

for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
        // Procesar flag
    } else {
        archivos[num_archivos++] = argv[i];
    }
}

```
<!-- {code-block} c -->

:::
<!-- {tip} Patrones de Parsing -->

:::{note} getopt (estándar POSIX)

La biblioteca estándar provee `getopt` para parsing robusto:

```{code-block} c
:linenos:
#include <unistd.h>

int opt;
while ((opt = getopt(argc, argv, "vhn:o:")) != -1) {
    switch (opt) {
        case 'v': verbose = true; break;
        case 'h': mostrar_ayuda(); break;
        case 'n': num = atoi(optarg); break;
        case 'o': output = optarg; break;
        default: return 1;
    }
}

// optind es el índice del primer argumento no-flag
for (int i = optind; i < argc; i++) {
    // Procesar archivos
}

```
<!-- {code-block} c -->

`getopt_long` soporta flags largos (`--verbose`).

:::
<!-- {note} getopt (estándar POSIX) -->

Estas consignas cubren procesamiento de argumentos desde básico hasta sistemas
complejos estilo herramientas Unix, esenciales para programas de línea de
comandos profesionales.

