---
title: "Ejercicios de Punteros"
short_title: "2. Punteros"
subtitle: "Dirección de memoria, indirección, pasaje por referencia y punteros constantes"
---

(ejercicios-punteros-bloque-2)=
# Ejercicios de Punteros

## Acerca de

Estos ejercicios tienen como propósito afianzar los conceptos fundamentales de direccionamiento
físico en memoria, obtención de direcciones mediante el operador `&`, acceso y modificación
de valores mediante desreferenciación con el operador `*`, pasaje de parámetros por referencia
para modificar variables en el llamador, y la semántica de cualificadores `const`.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros` (Bloque 2, Capítulo 2)

### Requisitos Previos y Entorno
- **Conocimientos previos:** Dominio de tipos de datos escalares (`int`, `char`, `double`), operadores aritméticos, estructuras de control (`if`, `while`) y funciones por valor (Bloque 1: Fundamentos).
- **Entorno y herramientas:** Compilador compatible con ISO C11 (`gcc -std=c11 -Wall -Wextra -Werror -pedantic`), entorno POSIX / Linux.

### Cuestiones de Estilo Aplicables
- **Inicialización de punteros:** Todo puntero debe inicializarse en `NULL` si no apunta de inmediato a una variable válida ({ref}`0x7001h`).
- **Verificación defensiva:** Antes de desreferenciar cualquier puntero con `*`, es obligatorio verificar que no sea `NULL`.
- **Techo conceptual estricto:** En este capítulo solo se manipulan variables escalares primitivas (`int`, `double`, `char`). No se permite el uso de estructuras (`struct`), memoria dinámica (`malloc`/`free`) ni punteros a funciones.

---

## Direcciones y Pasaje por Referencia

(ej_b2_c02_01)=
### Ejercicio 2.02.01 - Duplicar Valor por Referencia ⭐⭐☆☆☆

El objetivo es modificar una variable escalar perteneciente al marco de pila de la función llamadora a través de un puntero.

::::{exercise} Duplicar Valor por Referencia
:label: ej-b2-c02-01

**Consigna:**
Implementar una función que reciba la dirección de una variable entera y duplique in-place el valor almacenado en dicha posición. Si el puntero recibido es nulo, la función debe abortar la operación sin realizar accesos inválidos.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Duplica in-place el valor entero apuntado por numero.
 * 
 * @param[in,out] numero Puntero al entero que será duplicado. No debe ser NULL.
 * @return int           0 si la operación fue exitosa, -1 si el puntero es NULL.
 * 
 * @pre  numero debe apuntar a una variable entera válida o ser NULL.
 * @post Si numero != NULL, *numero contiene el doble de su valor previo.
 * @ownership La variable apuntada pertenece a la función llamadora.
 */
int duplicar_valor(int *numero);
```

#### Vectores de Prueba Obligatorios

| Caso | Entrada (`*numero`) | Salida (`*numero`) | Retorno | Comportamiento Evaluado |
| :--- | :--- | :--- | :---: | :--- |
| **Normal 1** | `5` | `10` | `0` | Duplicación de entero positivo. |
| **Normal 2** | `-7` | `-14` | `0` | Duplicación de entero negativo. |
| **Borde** | `0` | `0` | `0` | Elemento neutro / cero. |
| **Error** | Puntero `NULL` | Inalterado | `-1` | Protección contra desreferencia nula. |

:::{hint} Casos Límite y Consideraciones
- No desreferenciar `numero` antes de verificar `if (numero == NULL)`.
- El llamador es responsable de proveer memoria en su propio stack frame.
:::

::::

::::{solution} ej-b2-c02-01
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int duplicar_valor(int *numero)
{
    if (numero == NULL) {
        return -1;
    }
    *numero = (*numero) * 2;
    return 0;
}

int main(void)
{
    int val = 21;
    assert(duplicar_valor(&val) == 0);
    assert(val == 42);

    int cero = 0;
    assert(duplicar_valor(&cero) == 0);
    assert(cero == 0);

    assert(duplicar_valor(NULL) == -1);

    printf("Ejercicio 2.02.01: Tests superados exitosamente.\n");
    return 0;
}
```

**Justificación técnica:**
Se utiliza desreferencia directa `*numero` para mutar el objeto en la dirección provista. El retorno indica explícitamente éxito (`0`) o error de puntero nulo (`-1`) evitando comportamiento indefinido según C11 §6.5.3.2.

::::

---

(ej_b2_c02_02)=
### Ejercicio 2.02.02 - División Entera con Retorno Múltiple ⭐⭐☆☆☆

En C las funciones solo pueden retornar un valor directo por registro. El pasaje por referencia permite obtener múltiples resultados computados en una única invocación.

::::{exercise} División Entera con Retorno Múltiple
:label: ej-b2-c02-02

**Consigna:**
Implementar una función que calcule simultáneamente el cociente y el resto de la división entera entre dos números, almacenando los resultados en variables provistas por el llamador a través de punteros.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Calcula el cociente y resto de una división entera.
 * 
 * @param[in]  dividendo  Número entero a dividir.
 * @param[in]  divisor    Número entero divisor. Debe ser distinto de cero.
 * @param[out] cociente   Puntero donde se almacenará dividendo / divisor.
 * @param[out] resto      Puntero donde se almacenará dividendo % divisor.
 * @return int            0 en éxito; -1 si divisor == 0; -2 si algún puntero es NULL.
 * 
 * @pre  divisor != 0, cociente != NULL, resto != NULL.
 * @post *cociente contiene dividendo / divisor; *resto contiene dividendo % divisor.
 * @ownership Memoria administrada por el llamador.
 */
int division_entera(int dividendo, int divisor, int *cociente, int *resto);
```

#### Vectores de Prueba Obligatorios

| Caso | `dividendo` | `divisor` | `*cociente` | `*resto` | Retorno | Comportamiento Evaluado |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Normal 1** | `17` | `5` | `3` | `2` | `0` | División exacta con resto positivo. |
| **Normal 2** | `20` | `4` | `5` | `0` | `0` | División exacta con resto cero. |
| **Borde** | `0` | `9` | `0` | `0` | `0` | Dividendo cero. |
| **Error 1** | `10` | `0` | Inalterado | Inalterado | `-1` | División por cero capturada. |
| **Error 2** | `10` | `2` | `NULL` | Inalterado | `-2` | Puntero de salida nulo. |

:::{hint} Casos Límite y Consideraciones
- Validar primero los punteros de salida (`cociente == NULL || resto == NULL`).
- Luego validar que `divisor != 0`.
:::

::::

::::{solution} ej-b2-c02-02
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int division_entera(int dividendo, int divisor, int *cociente, int *resto)
{
    if (cociente == NULL || resto == NULL) {
        return -2;
    }
    if (divisor == 0) {
        return -1;
    }
    *cociente = dividendo / divisor;
    *resto = dividendo % divisor;
    return 0;
}

int main(void)
{
    int c = 0, r = 0;
    assert(division_entera(17, 5, &c, &r) == 0);
    assert(c == 3 && r == 2);

    assert(division_entera(10, 0, &c, &r) == -1);
    assert(division_entera(10, 2, NULL, &r) == -2);
    assert(division_entera(10, 2, &c, NULL) == -2);

    printf("Ejercicio 2.02.02: Tests superados exitosamente.\n");
    return 0;
}
```

**Justificación técnica:**
Se desacopla la señal de estado (código de retorno) de los canales de datos (*out parameters*), conforme a la regla de cátedra {ref}`0x2002h`.

::::

---

(ej_b2_c02_03)=
### Ejercicio 2.02.03 - Intercambio de Variables ⭐⭐☆☆☆

El intercambio in-place es la operación atómica básica de ordenamientos y permutaciones.

::::{exercise} Intercambio de Variables
:label: ej-b2-c02-03

**Consigna:**
Implementar una función que intercambie el contenido de dos variables enteras en memoria utilizando una variable auxiliar temporal.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Intercambia los valores de dos enteros apuntados por a y b.
 * 
 * @param[in,out] a Puntero al primer entero.
 * @param[in,out] b Puntero al segundo entero.
 * @return int      0 en éxito, -1 si algún puntero es NULL.
 */
int intercambiar(int *a, int *b);
```

#### Vectores de Prueba Obligatorios

| Caso | Antes (`*a`, `*b`) | Después (`*a`, `*b`) | Retorno | Comportamiento Evaluado |
| :--- | :---: | :---: | :---: | :--- |
| **Normal** | `(10, 20)` | `(20, 10)` | `0` | Intercambio de valores disjuntos. |
| **Borde** | `(42, 42)` | `(42, 42)` | `0` | Punteros con igual valor. |
| **Aliasing** | `a == b` | Inalterado | `0` | Mismo puntero pasado a ambos argumentos. |
| **Error** | `(NULL, &b)` | Inalterado | `-1` | Puntero nulo en `a`. |

::::

::::{solution} ej-b2-c02-03
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int intercambiar(int *a, int *b)
{
    if (a == NULL || b == NULL) {
        return -1;
    }
    if (a == b) {
        return 0;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main(void)
{
    int x = 10, y = 99;
    assert(intercambiar(&x, &y) == 0);
    assert(x == 99 && y == 10);

    // Caso de aliasing (mismo puntero)
    assert(intercambiar(&x, &x) == 0);
    assert(x == 99);

    assert(intercambiar(&x, NULL) == -1);
    printf("Ejercicio 2.02.03: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_04)=
### Ejercicio 2.02.04 - Puntero al Mayor de Dos Números ⭐⭐☆☆☆

Demostrar que una función puede retornar una dirección de memoria preexistente recibida como argumento.

::::{exercise} Puntero al Mayor de Dos Números
:label: ej-b2-c02-04

**Consigna:**
Implementar una función que reciba dos punteros a enteros y retorne la dirección de memoria (`int*`) del argumento cuyo valor desreferenciado sea mayor.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Retorna el puntero a la variable que contiene el mayor valor.
 * 
 * @param[in] a Puntero al primer valor.
 * @param[in] b Puntero al segundo valor.
 * @return int* Dirección de a si *a >= *b; dirección de b si *b > *a; NULL si a o b es NULL.
 */
int *obtener_mayor(int *a, int *b);
```

#### Vectores de Prueba Obligatorios

| Caso | Entrada `(*a, *b)` | Retorno Esperado | Comportamiento Evaluado |
| :--- | :---: | :---: | :--- |
| **Normal 1** | `(15, 3)` | Dirección `a` | Retorna primer puntero si es mayor. |
| **Normal 2** | `(2, 40)` | Dirección `b` | Retorna segundo puntero si es mayor. |
| **Borde** | `(7, 7)` | Dirección `a` | Empate: retorna `a`. |
| **Error** | `(NULL, &b)` | `NULL` | Retorno seguro ante argumento nulo. |

::::

::::{solution} ej-b2-c02-04
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int *obtener_mayor(int *a, int *b)
{
    if (a == NULL || b == NULL) {
        return NULL;
    }
    return (*a >= *b) ? a : b;
}

int main(void)
{
    int n1 = 50, n2 = 100;
    int *res = obtener_mayor(&n1, &n2);
    assert(res == &n2);
    assert(*res == 100);

    assert(obtener_mayor(&n1, NULL) == NULL);
    printf("Ejercicio 2.02.04: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_05)=
### Ejercicio 2.02.05 - Selección de Puntero mediante Indirección Doble ⭐⭐⭐☆☆

Manipulación de punteros a punteros para reasignar direcciones escalares sin invocar `malloc`.

::::{exercise} Selección de Puntero mediante Indirección Doble
:label: ej-b2-c02-05

**Consigna:**
Implementar una función que reciba dos punteros a constantes enteras `a` y `b`, y un puntero doble `resultado`. La función debe hacer que el puntero desreferenciado `*resultado` apunte a la variable que tenga el mayor valor.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Asigna a *resultado la dirección de memoria del mayor valor entre a y b.
 * 
 * @param[in]  a         Puntero constante al primer valor.
 * @param[in]  b         Puntero constante al segundo valor.
 * @param[out] resultado Puntero doble donde se escribirá la dirección ganadora.
 * @return int           0 en éxito, -1 si algún puntero es NULL.
 */
int seleccionar_puntero(const int *a, const int *b, const int **resultado);
```

#### Vectores de Prueba Obligatorios

| Caso | Valores (`*a`, `*b`) | Dirección asignada a `*resultado` | Retorno |
| :--- | :---: | :---: | :---: |
| **Normal 1** | `(100, 20)` | Dirección de `a` | `0` |
| **Normal 2** | `(5, 80)` | Dirección de `b` | `0` |
| **Error** | Puntero `resultado` nulo | Inalterado | `-1` |

::::

::::{solution} ej-b2-c02-05
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int seleccionar_puntero(const int *a, const int *b, const int **resultado)
{
    if (a == NULL || b == NULL || resultado == NULL) {
        return -1;
    }
    *resultado = (*a >= *b) ? a : b;
    return 0;
}

int main(void)
{
    const int x = 40, y = 90;
    const int *ptr_ganador = NULL;

    assert(seleccionar_puntero(&x, &y, &ptr_ganador) == 0);
    assert(ptr_ganador == &y);
    assert(*ptr_ganador == 90);

    assert(seleccionar_puntero(&x, &y, NULL) == -1);
    printf("Ejercicio 2.02.05: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_06)=
### Ejercicio 2.02.06 - Resetear Puntero Escalar ⭐⭐☆☆☆

::::{exercise} Resetear Puntero Escalar
:label: ej-b2-c02-06

**Consigna:**
Implementar una función `int anular_puntero(int **ptr)` que verifique que `ptr != NULL` y establezca la variable apuntada en `NULL`, desconectando de forma segura el puntero del llamador.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Establece *ptr en NULL de forma segura.
 * 
 * @param[in,out] ptr Puntero doble al puntero que se anulará.
 * @return int        0 en éxito, -1 si ptr es NULL.
 */
int anular_puntero(int **ptr);
```

::::

::::{solution} ej-b2-c02-06
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int anular_puntero(int **ptr)
{
    if (ptr == NULL) {
        return -1;
    }
    *ptr = NULL;
    return 0;
}

int main(void)
{
    int dummy = 123;
    int *p = &dummy;

    assert(p != NULL);
    assert(anular_puntero(&p) == 0);
    assert(p == NULL);

    assert(anular_puntero(NULL) == -1);
    printf("Ejercicio 2.02.06: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_07)=
### Ejercicio 2.02.07 - Puntero a Constante vs Puntero Constante ⭐⭐⭐☆☆

::::{exercise} Puntero a Constante vs Puntero Constante
:label: ej-b2-c02-07

**Consigna:**
Implementar una suite de tres funciones que demuestren de forma analítica y práctica la diferencia entre:
1. `const int *p`: puntero mutable hacia un dato inmutable.
2. `int * const p`: puntero inmutable hacia un dato mutable.
3. `const int * const p`: puntero y dato inmutables.

Cada función debe compilar demostrando la operación válida y comentar la operación que provocaría error de compilación.

::::

::::{solution} ej-b2-c02-07
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

// 1. Puede redirigir p, pero no puede mutar *p
int demo_puntero_a_constante(const int *p, const int *otro)
{
    if (p == NULL || otro == NULL) return -1;
    // *p = 50; // ERROR de compilación: read-only location
    p = otro;   // VÁLIDO: el puntero es mutable
    return *p;
}

// 2. Puede mutar *p, pero no puede redirigir p
int demo_puntero_constante(int * const p, int nuevo_valor)
{
    if (p == NULL) return -1;
    *p = nuevo_valor; // VÁLIDO: el dato es mutable
    // p = NULL;      // ERROR de compilación: read-only variable 'p'
    return 0;
}

int main(void)
{
    int x = 10, y = 20;
    assert(demo_puntero_a_constante(&x, &y) == 20);

    assert(demo_puntero_constante(&x, 99) == 0);
    assert(x == 99);

    printf("Ejercicio 2.02.07: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_08)=
### Ejercicio 2.02.08 - Lectura Segura con Puntero de Solo Lectura ⭐⭐☆☆☆

::::{exercise} Lectura Segura con Puntero de Solo Lectura
:label: ej-b2-c02-08

**Consigna:**
Implementar `int acceso_seguro(const int *ptr, int *salida)` que verifique si `ptr` y `salida` son no nulos. Si son válidos, copia el contenido de `*ptr` en `*salida` retornando `0`. Si alguno es nulo, retorna `-1`.

#### Contrato de la Función

```{code-block} c
/**
 * @brief Lee un entero de forma segura protegiendo contra punteros nulos.
 * 
 * @param[in]  ptr    Puntero de solo lectura al valor de entrada.
 * @param[out] salida Puntero donde se almacenará el valor leído.
 * @return int        0 en éxito, -1 si ptr o salida es NULL.
 */
int acceso_seguro(const int *ptr, int *salida);
```

::::

::::{solution} ej-b2-c02-08
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <assert.h>

int acceso_seguro(const int *ptr, int *salida)
{
    if (ptr == NULL || salida == NULL) {
        return -1;
    }
    *salida = *ptr;
    return 0;
}

int main(void)
{
    const int origen = 777;
    int destino = 0;

    assert(acceso_seguro(&origen, &destino) == 0);
    assert(destino == 777);

    assert(acceso_seguro(NULL, &destino) == -1);
    assert(acceso_seguro(&origen, NULL) == -1);

    printf("Ejercicio 2.02.08: Tests superados exitosamente.\n");
    return 0;
}
```

::::

---

(ej_b2_c02_09)=
### Ejercicio 2.02.09 - Inicialización Segura y Detección de Basura ⭐☆☆☆☆

::::{exercise} Inicialización Segura y Detección de Basura
:label: ej-b2-c02-09

**Consigna:**
Escribir un programa que demuestre el valor de la macro `NULL` como centinela en tiempo de ejecución para evitar desreferencias inadvertidas.

::::

::::{solution} ej-b2-c02-09
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool es_puntero_seguro(const int *p)
{
    return p != NULL;
}

int main(void)
{
    int *p_nulo = NULL;
    int x = 12;
    int *p_valido = &x;

    assert(!es_puntero_seguro(p_nulo));
    assert(es_puntero_seguro(p_valido));

    printf("Ejercicio 2.02.09: Tests superados exitosamente.\n");
    return 0;
}
```

::::
