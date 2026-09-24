---
title: 'Ejercicios: Control de Flujo'
short_title: '5. Control'
subtitle: 'Problemas y soluciones sobre lazos y condicionales en C'
---

(control-flujo-ejercicios)=
# Ejercicios: Control de Flujo

## Prerrequisitos y Entorno Requerido
Antes de abordar y compilar los ejercicios de esta guía, se requiere:
1. **Entorno de Compilación:** Compilador GCC 9+ o Clang bajo estándar estricto **ISO C11** (`-std=c11 -Wall -Wextra -Werror -pedantic`).
2. **Conceptos de Control de Flujo:** Operadores relacionales (`<`, `<=`, `>`, `>=`, `==`, `!=`), operadores lógicos de cortocircuito (`&&`, `||`, `!`) y bifurcaciones `if`/`else if`/`else`/`switch`.
3. **Lazos Estructurados e Invariantes:** Iteraciones acotadas con `for`, lazos gobernados por condición con `while`/`do-while` y banderas de control booleanas (`stdbool.h`) evitando saltos incondicionales (`break`/`continue`).

## Acerca de

Estos ejercicios tienen como propósito ejercitar la lógica condicional, las estructuras de repetición y el control de flujo estructurado y seguro en C11.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-control-flujo`

---

## Estructuras Condicionales

(ej_b1_c03b_01)=
### Ejercicio 1.03b.01 - Condición de Aprobación ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03b_01_aprobacion

Implementá una función pura que evalúe la condición académica según la nota
entera recibida:
- `"Promociona"` si la nota es mayor o igual a 6.
- `"Aprueba"` si la nota está comprendida entre 4 y 5 inclusive.
- `"Desaprueba"` si la nota es menor a 4.

```c
const char *evaluar_condicion_aprobacion(int nota);
```

**Tabla de Vectores de Prueba:**

| Nota de Entrada | Condición Retornada |
| :--- | :--- |
| `10` | `"Promociona"` |
| `6` | `"Promociona"` |
| `5` | `"Aprueba"` |
| `4` | `"Aprueba"` |
| `3` | `"Desaprueba"` |
| `0` | `"Desaprueba"` |

::::{solution}
```c
#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *evaluar_condicion_aprobacion(int nota) {
    if (nota >= 6) {
        return "Promociona";
    } else if (nota >= 4) {
        return "Aprueba";
    } else {
        return "Desaprueba";
    }
}

int main(void) {
    assert(strcmp(evaluar_condicion_aprobacion(10), "Promociona") == 0);
    assert(strcmp(evaluar_condicion_aprobacion(6), "Promociona") == 0);
    assert(strcmp(evaluar_condicion_aprobacion(5), "Aprueba") == 0);
    assert(strcmp(evaluar_condicion_aprobacion(4), "Aprueba") == 0);
    assert(strcmp(evaluar_condicion_aprobacion(3), "Desaprueba") == 0);
    assert(strcmp(evaluar_condicion_aprobacion(0), "Desaprueba") == 0);
    return 0;
}
```
::::
:::

---

## Estructuras de Repetición (Lazos)

(ej_b1_c03b_02)=
### Ejercicio 1.03b.02 - Cuenta descendente ⭐⭐☆☆☆

:::{exercise}
:label: lazo_while 
:enumerator: while
Escribí un programa en C que imprima los números del 10 al 1 de forma
descendente usando un lazo `while`.
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {exercise} -->

:::{solution} lazo_while
:label: solucion-lazo_while
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
int main(void)
{
    int i = 10;
    while (i >= 1)
    {
        printf("%d\n", i);
        i = i - 1;
    }
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} lazo_while -->

(ej_b1_c03b_03)=
### Ejercicio 1.03b.03 - Múltiplos de 3 ⭐⭐☆☆☆

:::{exercise}
:label: lazo_for
:enumerator: for
Usá un lazo `for` para mostrar los números múltiplos de 3 comprendidos en el
rango de 0 a 30 inclusive.
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

:::
<!-- {exercise} -->

:::{solution} lazo_for
:label: solucion-lazo_for
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
int main(void)
{
    for (int i = 0; i <= 30; i = i + 1)
    {
        if (i % 3 == 0)
        {
            printf("%d es múltiplo de 3\n", i);
        }
    }
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} lazo_for -->

(ej_b1_c03b_04)=
### Ejercicio 1.03b.04 - Verificación de Clave con Límite de Intentos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03b_04_clave_intentos

Implementá una función determinística que procese un arreglo de intentos de clave
contra una clave secreta esperada, deteniéndose apenas acierte o al agotar los
intentos, retornando si el acceso fue concedido.

```c
bool verificar_clave_intentos(const int *intentos, size_t n, int clave_secreta);
```

**Tabla de Vectores de Prueba:**

| Intentos Ingresados | Clave Secreta | Retorno Esperado |
| :--- | :--- | :--- |
| `[1111, 2222, 1234]` | `1234` | `true` (concedido al 3er intento) |
| `[1234]` | `1234` | `true` (concedido al 1er intento) |
| `[9999, 8888, 7777]` | `1234` | `false` (agotados) |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool verificar_clave_intentos(const int *intentos, size_t n, int clave_secreta) {
    if (intentos == NULL || n == 0) {
        return false;
    }
    size_t i = 0;
    bool concedido = false;
    do {
        if (intentos[i] == clave_secreta) {
            concedido = true;
        }
        i++;
    } while (i < n && !concedido);

    return concedido;
}

int main(void) {
    int intentos_ok[] = {1111, 2222, 1234};
    assert(verificar_clave_intentos(intentos_ok, 3, 1234));

    int inmediato[] = {1234};
    assert(verificar_clave_intentos(inmediato, 1, 1234));

    int fallidos[] = {9999, 8888, 7777};
    assert(!verificar_clave_intentos(fallidos, 3, 1234));

    assert(!verificar_clave_intentos(NULL, 0, 1234));
    return 0;
}
```
::::
:::

---

## Control de Flujo Seguro

(ej_b1_c03b_05)=
### Ejercicio 1.03b.05 - Refactorización de break ⭐⭐☆☆☆

:::{exercise}
:label: lazo_break
:enumerator: break
Modificá el siguiente programa para eliminar la instrucción `break` prohibida,
estructurando correctamente el lazo:
```{code-block} c
:linenos:
#include <stdio.h>
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("valor actual: %d\n", i);
        if (i == 4)
        {
            break;
        }
    }
    return 0;
}
```
<!-- {code-block} c -->
    desbordamientos de búfer validando la capacidad máxima.
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
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    int i = 0;
    bool continuar = true;
    while (i < 10 && continuar)
    {
        printf("valor actual: %d\n", i);
        if (i == 4)
        {
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

(ej_b1_c03b_06)=
### Ejercicio 1.03b.06 - Refactorización de continue ⭐⭐☆☆☆

:::{exercise}
:label: lazo_continue
:enumerator: continue
Modificá el siguiente código para eliminar la instrucción `continue` prohibida:
```{code-block} c
:linenos:
#include <stdio.h>
int main()
{
    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        printf("i = %d\n", i);
    }
    return 0;
}
```
<!-- {code-block} c -->
    desbordamientos de búfer validando la capacidad máxima.
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
int main(void)
{
    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 != 0)
        {
            printf("i = %d\n", i);
        }
    }
    return 0;
}
```
<!-- {code-block} c -->

:::
<!-- {solution} lazo_continue -->

(ej_b1_c03b_07)=
### Ejercicio 1.03b.07 - Lazo de Clave con Bandera y Timeout ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c03b_07_lazo_flag

Reescribí la validación de clave empleando un lazo `while` gobernado por una
bandera booleana de éxito y un contador de intentos máximos para evitar bloqueos.

```c
int autenticar_usuario(const int *entradas, size_t n, int clave_esperada, size_t max_intentos);
```

**Tabla de Vectores de Prueba:**

| Entradas | `clave_esperada` | `max_intentos` | Intentos Consumidos |
| :--- | :--- | :--- | :--- |
| `[0000, 1234]` | `1234` | `3` | Retorna `2` (éxito al 2do intento) |
| `[1111, 2222, 3333, 1234]` | `1234` | `2` | Retorna `-1` (bloqueado por superar 2) |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int autenticar_usuario(const int *entradas, size_t n, int clave_esperada, size_t max_intentos) {
    if (entradas == NULL || n == 0) {
        return -1;
    }
    size_t intentos = 0;
    bool autenticado = false;

    while (intentos < n && intentos < max_intentos && !autenticado) {
        if (entradas[intentos] == clave_esperada) {
            autenticado = true;
        }
        intentos++;
    }

    return autenticado ? (int)intentos : -1;
}

int main(void) {
    int e1[] = {0, 1234};
    assert(autenticar_usuario(e1, 2, 1234, 3) == 2);

    int e2[] = {1111, 2222, 3333, 1234};
    assert(autenticar_usuario(e2, 4, 1234, 2) == -1);

    return 0;
}
```
::::
:::

---
(ejercicio_4_8)=
## Ejercicios de Práctica de Control

(ej_b1_c03b_08)=
### Ejercicio 1.03b.08 - Mayor de dos números reales ⭐⭐☆☆☆

Escribí un programa que solicite dos números reales al usuario y muestre cuál es
el mayor.

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_09)=
### Ejercicio 1.03b.09 - Números del 1 al 100 ⭐⭐☆☆☆

Diseñá un programa que imprima en pantalla los números enteros del 1 al 100
utilizando un lazo `for`.

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_10)=
### Ejercicio 1.03b.10 - Suma de pares del 1 al 100 ⭐⭐☆☆☆

Desarrollá un algoritmo que sume los números pares comprendidos en el rango del
1 al 100 inclusive.

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_11)=
### Ejercicio 1.03b.11 - Verificación de número primo ⭐⭐☆☆☆

Escribí un programa que solicite un número entero positivo e indique si es un
número primo (divisible únicamente por 1 y por sí mismo).

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_12)=
### Ejercicio 1.03b.12 - Estado de aprobación de calificación ⭐⭐⭐☆☆

Escribí un programa que pida una calificación (0 a 10) e indique si el
estudiante aprobó (calificación mayor o igual a 4).

:::{hint} Lógica y Consideraciones
definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_13)=
### Ejercicio 1.03b.13 - Contraseña de caracteres iterativa ⭐⭐☆☆☆

Escribí un programa que solicite repetidamente una contraseña de caracteres al
usuario hasta que coincida con un valor establecido de acceso seguro.

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

(ej_b1_c03b_14)=
## Ejercicio 1.03b.14 - Contar del 1 al 10 ⭐☆☆☆☆

Mostrá los números del 1 al 10 usando un lazo `for`.

**Orientación:**
- `for (int i = 1; i <= 10; i++)`
- Imprimí cada número en una línea

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_15)=
## Ejercicio 1.03b.15 - Suma de N Números ⭐☆☆☆☆

Leé un número N y calculá la suma de los primeros N números naturales.

**Orientación:**
- Usá lazo `for` de 1 a N
- Acumulá la suma en una variable
- Alternativa: fórmula directa suma = N × (N+1) / 2

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_16)=
## Ejercicio 1.03b.16 - Tabla de Multiplicar ⭐⭐☆☆☆

Mostrá la tabla de multiplicar de un número ingresado por el usuario (1 a 10).

**Orientación:**
- Leé el número
- Lazo de 1 a 10: `printf("%d x %d = %d\n", num, i, num * i);`

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_17)=
## Ejercicio 1.03b.17 - Factorial con While ⭐⭐☆☆☆

Calculá el factorial de N usando un lazo `while`.

**Orientación:**
- Inicializá resultado = 1, contador = N
- Mientras contador > 0: resultado *= contador, contador--
- Manejá caso especial: 0! = 1

:::{hint} Lógica y Consideraciones
definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_18)=
## Ejercicio 1.03b.18 - Números Pares en Rango ⭐⭐☆☆☆

Mostrá todos los números pares entre dos valores ingresados.

**Orientación:**
- Leé inicio y fin
- Lazo de inicio a fin
- Usá `if (i % 2 == 0)` para detectar pares
- Alternativa: `for (i = inicio; i <= fin; i += 2)` empezando en par

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_19)=
## Ejercicio 1.03b.19 - Suma hasta Cero ⭐⭐☆☆☆

Leé números enteros hasta que el usuario ingrese 0, luego mostrá la suma total.

**Orientación:**
- Usá `while (true)` o `do-while`
- Leé número
- Si es 0, `break`
- Caso contrario, sumá al acumulador

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_20)=
## Ejercicio 1.03b.20 - Validación de Entrada ⭐⭐⭐☆☆

Leé un número entre 1 y 100. Si está fuera de rango, pedí nuevamente hasta que
sea válido.

**Orientación:**
- `do-while` es ideal aquí
- `do { leer numero } while (numero < 1 || numero > 100);`
- Mostrá mensaje de error en cada intento inválido

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_21)=
## Ejercicio 1.03b.21 - Contar Dígitos ⭐⭐⭐☆☆

Contá cuántos dígitos tiene un número entero.

**Orientación:**
- Usá lazo `while (n > 0)`
- Dividí por 10 en cada iteración: `n /= 10`
- Incrementá contador
- Caso especial: 0 tiene 1 dígito

:::{hint} Lógica y Consideraciones
definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_22)=
## Ejercicio 1.03b.22 - Número Primo ⭐⭐⭐☆☆

Determiná si un número es primo probando divisibilidad.

**Orientación:**
- Si N <= 1: no primo
- Si N = 2: primo
- Probá divisores de 2 a √N
- Si alguno divide exacto: no primo
- Optimización: después del 2, probar solo impares

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_23)=
## Ejercicio 1.03b.23 - Secuencia de Fibonacci ⭐⭐⭐☆☆

Generá los primeros N números de Fibonacci.

**Orientación:**
- Inicializá `a = 0, b = 1`
- Lazo N veces:
  - Mostrá `a`
  - Calculá siguiente: `temp = a + b; a = b; b = temp`

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_24)=
## Ejercicio 1.03b.24 - Búsqueda en Array ⭐⭐⭐☆☆

Buscá un valor en un array. Si lo encontrás, mostrá su posición y `break`.

**Orientación:**
- Recorré array con `for`
- Compará cada elemento con el buscado
- Si coincide: guardá índice, `break`
- Después del lazo: verificá si se encontró

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_25)=
### Ejercicio 1.03b.25 - Validador de Fechas Gregorianas y Regla de Bisiestos ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b1_c03b_25_validador_fecha

Implementá una función pura de validación temporal en el calendario gregoriano:

```c
bool es_bisiesto(int anio);
bool fecha_es_valida(int dia, int mes, int anio);
```

**Reglas de cálculo:**
1. **Regla gregoriana de años bisiestos:** Un año es bisiesto si es divisible por 4, excepto si es divisible por 100, a menos que también sea divisible por 400.
2. **Validación de rangos:**
   - `anio >= 1` (era común).
   - `mes` entre `1` y `12`.
   - `dia` entre `1` y el límite superior de dicho mes (febrero: 28 días, o 29 en año bisiesto; abril, junio, septiembre, noviembre: 30 días; enero, marzo, mayo, julio, agosto, octubre, diciembre: 31 días).

#### Tabla de Vectores de Prueba Obligatorios

| Fecha $(D, M, A)$ | Bisiesto | Validación Esperada | Justificación |
| :--- | :--- | :--- | :--- |
| `29, 2, 2024` | Sí | `true` | Año bisiesto divisible por 4 y no por 100 |
| `29, 2, 1900` | No | `false` | Divisible por 100 pero no por 400 (no bisiesto) |
| `29, 2, 2000` | Sí | `true` | Divisible por 400 (bisiesto secular) |
| `31, 4, 2023` | No | `false` | Abril tiene 30 días |
| `31, 12, 2023`| No | `true` | Diciembre tiene 31 días |
| `0, 5, 2023`  | No | `false` | Día fuera de rango inferior |
| `15, 13, 2023`| No | `false` | Mes fuera de rango superior |

:::

::::{solution} ej_b1_c03b_25_validador_fecha
:class: dropdown

```{code-block} c
:linenos:
#include <stdbool.h>
#include <assert.h>

bool es_bisiesto(int anio)
{
    if (anio <= 0)
    {
        return false;
    }
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

bool fecha_es_valida(int dia, int mes, int anio)
{
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1)
    {
        return false;
    }

    int dias_mes = 31;

    switch (mes)
    {
    case 2:
        dias_mes = es_bisiesto(anio) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias_mes = 30;
        break;
    default:
        dias_mes = 31;
        break;
    }

    return (dia <= dias_mes);
}

int main(void)
{
    /* Pruebas de bisiestos */
    assert(es_bisiesto(2024) == true);
    assert(es_bisiesto(1900) == false);
    assert(es_bisiesto(2000) == true);
    assert(es_bisiesto(2023) == false);

    /* Fechas válidas */
    assert(fecha_es_valida(29, 2, 2024) == true);
    assert(fecha_es_valida(29, 2, 2000) == true);
    assert(fecha_es_valida(31, 12, 2023) == true);
    assert(fecha_es_valida(30, 4, 2023) == true);

    /* Fechas inválidas */
    assert(fecha_es_valida(29, 2, 1900) == false);
    assert(fecha_es_valida(29, 2, 2023) == false);
    assert(fecha_es_valida(31, 4, 2023) == false);
    assert(fecha_es_valida(0, 5, 2023) == false);
    assert(fecha_es_valida(15, 13, 2023) == false);
    assert(fecha_es_valida(15, 5, 0) == false);

    return 0;
}
```

::::
<!-- {solution} ej_b1_c03b_25_validador_fecha -->

---

(ej_b1_c03b_26)=
## Ejercicio 1.03b.26 - Mayor y Menor de N Números ⭐⭐⭐☆☆

Leé N números y encontrá el mayor y menor.

**Orientación:**
- Inicializá `mayor` y `menor` con el primer número
- Lazo desde el segundo número:
  - Si actual > mayor: actualizar mayor
  - Si actual < menor: actualizar menor

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_27)=
## Ejercicio 1.03b.27 - Invertir un Número ⭐⭐⭐⭐☆

Invertí los dígitos de un número (ej: 1234 → 4321).

**Orientación:**
- `invertido = 0`
- Mientras n > 0:
  - `digito = n % 10`
  - `invertido = invertido * 10 + digito`
  - `n /= 10`

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_28)=
## Ejercicio 1.03b.28 - Números Perfectos ⭐⭐⭐⭐☆

Encontrá todos los números perfectos hasta N. Un número es perfecto si la suma
de sus divisores (excluyéndolo) es igual al número.

**Ejemplo:** 6 = 1 + 2 + 3

**Orientación:**
- Lazo externo: de 1 a N
- Lazo interno: encontrar divisores de 2 a n/2
- Sumá divisores
- Si suma == número: es perfecto

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_29)=
## Ejercicio 1.03b.29 - Patrón de Asteriscos - Triángulo ⭐⭐⭐⭐☆

Dibujá un triángulo de asteriscos de altura N.

**Ejemplo (N=5):**

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
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

(ej_b1_c03b_30)=
## Ejercicio 1.03b.30 - Máximo Común Divisor (Euclides) ⭐⭐⭐⭐☆

Implementá el algoritmo de Euclides iterativo para calcular MCD.

**Algoritmo:**

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
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

(ej_b1_c03b_31)=
## Ejercicio 1.03b.31 - Número de Armstrong ⭐⭐⭐⭐☆

Determiná si un número es Armstrong (suma de sus dígitos elevados a la cantidad
de dígitos igual al número).

**Ejemplo:** 153 = 1³ + 5³ + 3³ = 153

**Orientación:**
- Primer lazo: contar dígitos
- Segundo lazo: sumar dígitos elevados a esa potencia
- Comparar suma con número original
- Usá `pow()` de `<math.h>`

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_32)=
## Ejercicio 1.03b.32 - Simulación de Cajero Automático ⭐⭐⭐⭐⭐

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
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_33)=
## Ejercicio 1.03b.33 - Criba de Eratóstenes ⭐⭐⭐⭐⭐

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
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_4_35)=
## Ejercicios Adicionales de Patrones

(ej_b1_c03b_34)=
### Ejercicio 1.03b.34 - Pirámide Centrada ⭐⭐⭐⭐⭐

Dibujá una pirámide centrada de asteriscos.

**Ejemplo (N=5):**

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
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

(ej_b1_c03b_35)=
### Ejercicio 1.03b.35 - Rombo ⭐⭐⭐⭐⭐

Dibujá un rombo de asteriscos.

**Orientación:**
- Mitad superior: pirámide creciente
- Mitad inferior: pirámide decreciente
- Mismo principio de espacios y asteriscos

:::{hint} Lógica y Consideraciones
definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## Problemas de Lazos Anidados

(ej_b1_c03b_36)=
### Ejercicio 1.03b.36 - Tabla de Multiplicar Completa ⭐⭐⭐⭐☆

Mostrá tabla de multiplicar del 1 al 10 (todas las tablas).

**Orientación:**
- Lazo externo: números del 1 al 10
- Lazo interno: multiplicadores del 1 al 10
- Formato: "3 x 4 = 12"

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_37)=
### Ejercicio 1.03b.37 - Números Primos en Rango ⭐⭐⭐⭐☆

Mostrá todos los números primos entre A y B.

**Orientación:**
- Lazo externo: números de A a B
- Lazo interno: verificar si es primo (función del ejercicio 9)
- Imprimí solo los primos

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## Problemas de Validación y Control

(ej_b1_c03b_38)=
### Ejercicio 1.03b.38 - Juego de Adivinanza Mejorado ⭐⭐⭐⭐⭐

El programa elige un número aleatorio. El usuario tiene máximo 7 intentos.

**Orientación:**
- `rand() % 100 + 1` para número aleatorio
- Lazo con contador de intentos
- Dar pistas ("muy alto", "muy bajo")
- `break` si adivina
- Después del lazo: verificar si ganó o perdió

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
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
   while (i < 10)
   {
       printf("%d\n", i);
       // Falta i++
   }
   ```

2. **Off-by-one:** Error en condición de parada
   ```c
   // Quiero 10 iteraciones
   for (int i = 1; i < 10; i++)         // MAL: solo 9 iteraciones
       for (int i = 1; i <= 10; i++)    // BIEN: 10 iteraciones
           for (int i = 0; i < 10; i++) // BIEN: 10 iteraciones
   ```

3. **Modificar variable de control dentro del lazo**
   ```c
   // Confuso
   for (int i = 0; i < 10; i++)
   {
       i += 2; // Evitar esto
   }
   ```

4. **Condición incorrecta con `break`**
   ```c
   // Redundante
   while (true)
   {
       if (condicion)
           break;
   }
   // Mejor
   while (!condicion)
   {
       // código
   }
   ```

:::
<!-- {warning} Errores Comunes -->

:::{note} Control de Lazos

**`break`:** Termina el lazo inmediatamente
``` c
for (int i = 0; i < 10; i++)
{
    if (condicion)
        break; // Sale del lazo
}
```
<!-- c -->

**`continue`:** Salta a la siguiente iteración
``` c
for (int i = 0; i < 10; i++)
{
    if (i % 2 == 0)
        continue;      // Salta pares
    printf("%d\n", i); // Solo imprime impares
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

(ej_b1_c03b_39)=
## Ejercicio 1.03b.39 - Mostrar Argumentos ⭐☆☆☆☆

Mostrá todos los argumentos recibidos.

**Orientación:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
int main(int argc, char *argv[])
{
    printf("Cantidad de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}
```
<!-- {code-block} c -->
- `argv[0]` es el nombre del programa

---

(ej_b1_c03b_40)=
## Ejercicio 1.03b.40 - Saludo Personalizado ⭐☆☆☆☆

Lee un nombre desde argv y saludá.

**Uso:** `./saludo Juan`

**Orientación:**
- Verificá: `if (argc != 2) { fprintf(stderr, "Uso: %s <nombre>\n", argv[0]);
  return 1; }`
- Usá: `printf("Hola, %s!\n", argv[1]);`

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_41)=
## Ejercicio 1.03b.41 - Suma de Dos Números ⭐⭐☆☆☆

Sumá dos números pasados como argumentos.

**Uso:** `./suma 5 3`

**Orientación:**
- Verificá `argc == 3`
- Convertí con `atoi`: `int a = atoi(argv[1]);`
- O mejor: `strtol(argv[1], NULL, 10)` para validación

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_42)=
## Ejercicio 1.03b.42 - Calculadora Simple ⭐⭐⭐☆☆

Implementá calculadora: `./calc <num1> <operador> <num2>`

**Uso:** `./calc 10 + 5`

**Orientación:**
- `argc == 4`
- `argv[2]` es el operador: `+`, `-`, `*`, `/`
- Usá `switch` o `if-else` para operación
- Validá división por cero

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_43)=
## Ejercicio 1.03b.43 - Flags Booleanos ⭐⭐⭐☆☆

Procesá flags opcionales `-v` (verbose) y `-h` (help).

**Uso:** `./programa -v archivo.txt`

**Orientación:**
- Recorré `argv` buscando strings que empiecen con `-`
- `if (strcmp(argv[i], "-v") == 0) verbose = true;`
- Argumentos no-flag son archivos u otros datos

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_44)=
## Ejercicio 1.03b.44 - Concatenar Argumentos ⭐⭐☆☆☆

Concatená todos los argumentos (excepto argv[0]) en un string.

**Uso:** `./concat Hola mundo desde C`
**Salida:** `Hola mundo desde C`

**Orientación:**
- Recorré argv desde índice 1
- Concatená con espacios intermedios
- Usá `strcat` o manualmente con índices

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_45)=
## Ejercicio 1.03b.45 - Conversor de Temperatura ⭐⭐⭐☆☆

Convertí temperatura según flags.

**Uso:** `./temp -c 100` (Celsius a Fahrenheit)
**Uso:** `./temp -f 212` (Fahrenheit a Celsius)

**Orientación:**
- Flag determina dirección de conversión
- Valor viene después del flag
- Mostrá resultado formateado

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_46)=
## Ejercicio 1.03b.46 - Procesamiento de Texto desde Consola ⭐⭐⭐☆☆

Leé texto carácter por carácter desde la entrada estándar (`stdin`) hasta encontrar `EOF` y mostralo en mayúsculas.

**Orientación:**
- Usá `getchar()` dentro de un lazo `while ((c = getchar()) != EOF)`
- Convertí cada letra con `toupper(c)` de `<ctype.h>`
- Imprimí cada carácter procesado con `putchar()`

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_47)=
## Ejercicio 1.03b.47 - Flag con Valor ⭐⭐⭐⭐☆

Procesá flag que requiere un valor: `-n <cantidad>`

**Uso:** `./programa -n 10 archivo.txt`

**Orientación:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
for (int i = 1; i < argc; i++)
{
    if (strcmp(argv[i], "-n") == 0)
    {
        if (i + 1 < argc)
        {
            cantidad = atoi(argv[++i]); // Incrementa i
        }
        else
        {
            fprintf(stderr, "Flag -n requiere valor\n");
        }
    }
}
```
<!-- {code-block} c -->

---

(ej_b1_c03b_48)=
## Ejercicio 1.03b.48 - Múltiples Flags ⭐⭐⭐⭐☆

Implementá programa con varios flags: `-v` (verbose), `-o <salida>`, `-n <num>`

**Uso:** `./programa -v -o salida.txt -n 100 entrada.txt`

**Orientación:**
- Variables para cada flag
- Lazo procesando argv
- Flags pueden estar en cualquier orden
- Argumentos sin `-` son archivos de entrada

:::{hint} Lógica y Consideraciones
errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_49)=
## Ejercicio 1.03b.49 - Validación de Argumentos ⭐⭐⭐☆☆

Validá que números sean realmente números.

**Orientación:**

:::{hint} Lógica y Consideraciones
evitar fallos de segmentación.
    punteros en lugar de indexación directa.
:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
char *endptr;
long num = strtol(argv[1], &endptr, 10);
if (*endptr != '\0')
{
    fprintf(stderr, "Error: '%s' no es un número válido\n", argv[1]);
    return 1;
}
```
<!-- {code-block} c -->
- `strtol` pone en `endptr` el primer carácter no-numérico
- Si `*endptr != '\0'`, hay caracteres inválidos

---

(ej_b1_c03b_50)=
## Ejercicio 1.03b.50 - Ayuda Automática ⭐⭐⭐☆☆

Mostrá ayuda si se pasa `-h` o `--help`, o si argumentos son incorrectos.

**Orientación:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
void mostrar_ayuda(const char *programa)
{
    printf("Uso: %s [opciones] archivo\n", programa);
    printf("Opciones:\n");
    printf("  -h, --help    Mostrar esta ayuda\n");
    printf("  -v            Modo verbose\n");
    printf("  -o <archivo>  Archivo de salida\n");
}
if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
{
    mostrar_ayuda(argv[0]);
    return 0;
}
```
<!-- {code-block} c -->

---

(ej_b1_c03b_51)=
## Ejercicio 1.03b.51 - Grep Simplificado ⭐⭐⭐⭐☆

Buscá patrón en archivo(s).

**Uso:** `./grep "patron" archivo1.txt archivo2.txt`

**Orientación:**
- `argv[1]` es el patrón
- `argv[2...]` son archivos
- Leé cada archivo línea por línea
- Si línea contiene patrón (`strstr`), mostrala

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_52)=
## Ejercicio 1.03b.52 - Wc (Word Count) Simplificado ⭐⭐⭐⭐☆

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
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_53)=
## Ejercicio 1.03b.53 - Sort con Opciones ⭐⭐⭐⭐⭐

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
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_54)=
## Ejercicio 1.03b.54 - Procesamiento de Lote ⭐⭐⭐⭐⭐

Aplicá operación a múltiples archivos.

**Uso:** `./batch -op <operacion> archivo1 archivo2 ...`

**Operaciones:** `upper`, `lower`, `reverse`, `count`

**Orientación:**
- Flag `-op` determina operación
- Aplicá a todos los archivos siguientes
- Escribí resultado en archivo.out para cada uno

:::{hint} Lógica y Consideraciones
errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_55)=
## Ejercicio 1.03b.55 - Configuración desde Archivo y Args ⭐⭐⭐⭐⭐

Leé configuración de archivo, permitiendo override por línea de comandos.

**Uso:** `./programa -c config.txt -n 50`

**Orientación:**
- Leé config.txt primero (formato `clave=valor`)
- Argumentos de línea de comandos sobrescriben config
- Precedencia: defaults < archivo < args

:::{hint} Lógica y Consideraciones
errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c03b_56)=
## Ejercicio 1.03b.56 - Pipeline Simulado ⭐⭐⭐⭐⭐

Implementá programa que puede leer de stdin o archivo.

**Uso:** 
- `./proceso archivo.txt`
- `cat archivo.txt | ./proceso`

**Orientación:**

:::{hint} Lógica y Consideraciones
errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.
:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
FILE *entrada;
if (argc > 1)
{
    entrada = fopen(argv[1], "r");
}
else
{
    entrada = stdin; // Lee de stdin
}
```
<!-- {code-block} c -->
- Permite composición estilo Unix

---

(ej_b1_c03b_57)=
## Ejercicio 1.03b.57 - Getopt Simplificado ⭐⭐⭐⭐⭐

Implementá tu propia versión simplificada de `getopt` para parsear flags.

**Orientación:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
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

(ej_b1_c03b_58)=
## Ejercicio 1.03b.58 - Sistema de Comandos ⭐⭐⭐⭐⭐

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
desbordamientos de búfer validando la capacidad máxima.
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
   int n = atoi(argv[1]); // Puede acceder fuera de límites
   // BIEN
   if (argc < 2)
   {
       fprintf(stderr, "Faltan argumentos\n");
       return 1;
   }
   int n = atoi(argv[1]);
   ```

2. **Asumir orden de flags:**
   ```c
   // Poco robusto
   if (strcmp(argv[1], "-v") == 0)
       ...
           // Mejor: recorrer buscando flags
           for (int i = 1; i < argc; i++)
       {
           if (strcmp(argv[i], "-v") == 0)
               verbose = true;
       }
   ```

3. **No validar conversiones:**
   ```c
   int n = atoi("abc"); // Retorna 0, sin error
   // Mejor:
   char *end;
   long n = strtol(argv[1], &end, 10);
   if (*end != '\0')
   { /* error */
   }
   ```

4. **Olvidar incrementar índice con flags que tienen valor:**
   ```c
   if (strcmp(argv[i], "-n") == 0)
   {
       n = atoi(argv[i + 1]); // Usá i+1
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
for (int i = 1; i < argc; i++)
{
    if (strcmp(argv[i], "-v") == 0)
    {
        verbose = true;
    }
}
```
<!-- {code-block} c -->

**Flags con valor:**
```{code-block} c
:linenos:
const char *output = NULL;
for (int i = 1; i < argc; i++)
{
    if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
    {
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
for (int i = 1; i < argc; i++)
{
    if (argv[i][0] == '-')
    {
        // Procesar flag
    }
    else
    {
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
while ((opt = getopt(argc, argv, "vhn:o:")) != -1)
{
    switch (opt)
    {
    case 'v':
        verbose = true;
        break;
    case 'h':
        mostrar_ayuda();
        break;
    case 'n':
        num = atoi(optarg);
        break;
    case 'o':
        output = optarg;
        break;
    default:
        return 1;
    }
}
// optind es el índice del primer argumento no-flag
for (int i = optind; i < argc; i++)
{
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

