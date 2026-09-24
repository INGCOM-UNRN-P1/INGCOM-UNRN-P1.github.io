---
title: "Ejercicios de Arreglos (Estáticos)"
short_title: "3. Arreglos"
---

# Ejercicios de Arreglos (Estáticos)

## Prerrequisitos y Entorno Requerido
Para abordar y verificar las soluciones de este módulo, se requiere:
1. **Entorno de Compilación:** Compilador GCC 9+ o Clang bajo estándar estricto **ISO C11** (`-std=c11 -Wall -Wextra -Werror -pedantic`).
2. **Conceptos de Arreglos Contiguos:** Declaración e inicialización estática (`int arr[N]`), indexación base-cero, verificación rigurosa de cotas (`0 <= i < n`) para prevenir accesos fuera de rango.
3. **Punteros Decaídos y Const-Correctness:** Paso de arreglos a funciones como puntero decaído y longitud (`const int *arr, size_t n`), preservando inmutabilidad en lecturas y usando `size_t` para índices y dimensiones.

## Acerca de

Ejercicios para practicar la manipulación de arreglos de tamaño fijo en C11. Un arreglo
es una colección de elementos del mismo tipo almacenados en ubicaciones de
memoria contiguas.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-arreglos`
- {ref}`capitulo-secuencias`

---

## Operaciones Básicas

(ej_b2_c03_01)=
### Ejercicio 2.03.01 - Formateo de Arreglos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c03_01_formateo

Implementá una función pura que formatee los elementos de un arreglo entero en un
búfer de caracteres con el formato `"[10, 20, 30]"`. Debe retornar `true` si el
búfer tuvo capacidad suficiente, o `false` ante desbordamientos.

```c
bool formatear_arreglo(const int *arr, size_t n, char *buffer, size_t capacidad);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Capacidad Búfer | Retorno Esperado | Salida Formateada |
| :--- | :--- | :--- | :--- | :--- |
| `[10, 20, 30]` | `3` | `64` | `true` | `"[10, 20, 30]"` |
| `[42]` | `1` | `32` | `true` | `"[42]"` |
| `[]` | `0` | `16` | `true` | `"[]"` |
| `[1, 2, 3]` | `3` | `4` | `false` | Búfer protegido contra overflow |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool formatear_arreglo(const int *arr, size_t n, char *buffer, size_t capacidad) {
    if (buffer == NULL || capacidad < 3) {
        return false;
    }
    if (arr == NULL || n == 0) {
        snprintf(buffer, capacidad, "[]");
        return true;
    }
    size_t offset = 0;
    int esc = snprintf(buffer + offset, capacidad - offset, "[");
    if (esc < 0 || (size_t)esc >= capacidad - offset) return false;
    offset += (size_t)esc;

    for (size_t i = 0; i < n; ++i) {
        if (i > 0) {
            esc = snprintf(buffer + offset, capacidad - offset, ", ");
            if (esc < 0 || (size_t)esc >= capacidad - offset) return false;
            offset += (size_t)esc;
        }
        esc = snprintf(buffer + offset, capacidad - offset, "%d", arr[i]);
        if (esc < 0 || (size_t)esc >= capacidad - offset) return false;
        offset += (size_t)esc;
    }

    esc = snprintf(buffer + offset, capacidad - offset, "]");
    if (esc < 0 || (size_t)esc >= capacidad - offset) return false;
    return true;
}

int main(void) {
    char buf[64] = {0};
    int datos[] = {10, 20, 30};

    assert(formatear_arreglo(datos, 3, buf, sizeof(buf)));
    assert(strcmp(buf, "[10, 20, 30]") == 0);

    int uno[] = {42};
    assert(formatear_arreglo(uno, 1, buf, sizeof(buf)));
    assert(strcmp(buf, "[42]") == 0);

    assert(formatear_arreglo(NULL, 0, buf, sizeof(buf)));
    assert(strcmp(buf, "[]") == 0);

    /* Capacidad insuficiente */
    char corto[4] = {0};
    assert(!formatear_arreglo(datos, 3, corto, sizeof(corto)));

    return 0;
}
```
::::
:::

(ej_b2_c03_02)=
### Ejercicio 2.03.02 - Suma de Elementos de un Arreglo ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c03_02_suma

Calculá la suma de todos los enteros de un arreglo contiguo en tiempo $O(n)$
utilizando acumuladores con rango extendido de 64 bits para prevenir overflow.

```c
long long sumar_elementos(const int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Suma Esperada |
| :--- | :--- | :--- |
| `[1, 2, 3, 4, 5]` | `5` | `15LL` |
| `[-10, 20, -5]` | `3` | `5LL` |
| `[]` | `0` | `0LL` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

long long sumar_elementos(const int *arr, size_t n) {
    if (arr == NULL || n == 0) {
        return 0LL;
    }
    long long suma = 0LL;
    for (size_t i = 0; i < n; ++i) {
        suma += (long long)arr[i];
    }
    return suma;
}

int main(void) {
    int a1[] = {1, 2, 3, 4, 5};
    assert(sumar_elementos(a1, 5) == 15LL);

    int a2[] = {-10, 20, -5};
    assert(sumar_elementos(a2, 3) == 5LL);

    assert(sumar_elementos(NULL, 0) == 0LL);
    return 0;
}
```
::::
:::

(ej_b2_c03_03)=
### Ejercicio 2.03.03 - Promedio Aritmético de Arreglo ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c03_03_promedio

Implementá una función pura que calcule el promedio (media aritmética) de los elementos de un arreglo de enteros, retornando un `double`:
- Si el arreglo es nulo o $n = 0$, retorna `0.0`.

```c
double calcular_promedio(const int *arr, size_t n);
```

**Tabla de Vectores de Prueba:**

| Arreglo | `n` | Promedio Esperado |
| :--- | :--- | :--- |
| `[10, 20, 30]` | `3` | `20.0` |
| `[1, 2]` | `2` | `1.5` |
| `[-5, 5]` | `2` | `0.0` |
| `[]` | `0` | `0.0` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-6

static int casi_igual(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double calcular_promedio(const int *arr, size_t n) {
    if (arr == NULL || n == 0) {
        return 0.0;
    }
    long long suma = 0;
    for (size_t i = 0; i < n; ++i) {
        suma += arr[i];
    }
    return (double)suma / (double)n;
}

int main(void) {
    int a1[] = {10, 20, 30};
    assert(casi_igual(calcular_promedio(a1, 3), 20.0));

    int a2[] = {1, 2};
    assert(casi_igual(calcular_promedio(a2, 2), 1.5));

    int a3[] = {-5, 5};
    assert(casi_igual(calcular_promedio(a3, 2), 0.0));

    assert(casi_igual(calcular_promedio(NULL, 0), 0.0));
    return 0;
}
```
::::
:::

(ej_b2_c03_04)=
### Ejercicio 2.03.04 - Productoria ⭐⭐☆☆☆

Calcular el producto de todos los elementos de un arreglo.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Variables:** Se necesita un `acumulador` inicializado en 1 (no en 0, ya
    que cualquier cosa multiplicada por 0 es 0).
-   **Proceso:** Recorrer el arreglo con un lazo `for`. En cada iteración,
    multiplicar el `acumulador` por el elemento actual.
-   **Caso Especial:** Si el arreglo contiene un 0, el producto final será 0.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION productoria_arreglo(arreglo, tamano)
VARIABLES:
    producto (tipo de dato del arreglo)
INICIO
    producto = 1
    PARA i DESDE 0 HASTA tamano-1 HACER
        producto = producto * arreglo[i]
    FIN PARA
    RETORNAR producto
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Búsqueda y Estadísticas

(ej_b2_c03_05)=
### Ejercicio 2.03.05 - Máximo y mínimo ⭐⭐☆☆☆

Encontrar los valores más grande (máximo) y más pequeño (mínimo) dentro de un
arreglo de números.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:**
    1.  Inicializar dos variables, `maximo` y `minimo`, con el valor del primer
        elemento del arreglo (`arreglo[0]`).
    2.  Recorrer el arreglo con un lazo `for` comenzando desde el segundo
        elemento (`i=1`).
    3.  En cada iteración, comparar el elemento actual `arreglo[i]` con
        `maximo`. Si `arreglo[i]` es mayor, actualizar `maximo`.
    4.  Hacer lo mismo para `minimo`, actualizándolo si `arreglo[i]` es menor.
-   **Salida:** Devolver los valores de `maximo` y `minimo` (por ejemplo, usando
    punteros).
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO encontrar_max_min(arreglo, tamano, REF maximo, REF minimo)
INICIO
    SI tamano == 0 ENTONCES TERMINAR // Arreglo vacío

    maximo = arreglo[0]
    minimo = arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] > maximo ENTONCES
            maximo = arreglo[i]
        FIN SI
        SI arreglo[i] < minimo ENTONCES
            minimo = arreglo[i]
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_06)=
### Ejercicio 2.03.06 - Casi máximo ⭐⭐☆☆☆

Encontrar el segundo elemento más grande en un arreglo. Este ejercicio requiere
un seguimiento más cuidadoso que simplemente encontrar el máximo.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Variables:** Se necesitan dos variables: `maximo` y `segundo_maximo`.
    Inicializarlas con el menor valor posible o con los dos primeros elementos
    del arreglo de forma ordenada.
-   **Proceso:**
    1.  Recorrer el arreglo.
    2.  Si el elemento actual `x` es mayor que `maximo`:
        a. `segundo_maximo` toma el valor de `maximo`.
        b. `maximo` toma el valor de `x`.
    3.  Si no, si `x` es mayor que `segundo_maximo` y diferente de `maximo`, se
        actualiza `segundo_maximo` a `x`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION encontrar_segundo_maximo(arreglo, tamano)
VARIABLES:
    maximo, segundo_maximo
INICIO
    // Inicializar con los dos primeros elementos o valores muy bajos
    maximo = MINIMO_VALOR_POSIBLE
    segundo_maximo = MINIMO_VALOR_POSIBLE

    PARA cada elemento x EN arreglo HACER
        SI x > maximo ENTONCES
            segundo_maximo = maximo
            maximo = x
        SINO SI x > segundo_maximo Y x < maximo ENTONCES
            segundo_maximo = x
        FIN SI
    FIN PARA
    RETORNAR segundo_maximo
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_07)=
### Ejercicio 2.03.07 - Búsqueda de elemento ⭐⭐☆☆☆

Implementar una búsqueda lineal para encontrar la primera ocurrencia de un
elemento específico dentro de un arreglo. Si se encuentra, se debe devolver su
índice.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y el elemento a buscar.
-   **Proceso:** Recorrer el arreglo con un lazo `for` desde el índice 0.
-   **Condición:** En cada iteración, comparar el elemento actual del arreglo
    con el elemento buscado. Si son iguales, se ha encontrado.
-   **Salida:** Si se encuentra el elemento, la función debe devolver el índice
    actual. Si el lazo termina sin encontrar el elemento, se debe devolver un
    valor especial que indique que no se encontró, como `-1`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION busqueda_lineal(arreglo, tamano, buscado)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] == buscado ENTONCES
            RETORNAR i // Elemento encontrado
        FIN SI
    FIN PARA
    RETORNAR -1 // Elemento no encontrado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_08)=
### Ejercicio 2.03.08 - Contar repeticiones ⭐⭐☆☆☆

Contar cuántas veces aparece un número específico en un arreglo.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y el elemento a contar.
-   **Variables:** Un `contador` inicializado en 0.
-   **Proceso:** Recorrer el arreglo con un lazo. En cada iteración, si el
    elemento actual es igual al elemento buscado, incrementar el `contador`.
-   **Salida:** Devolver el valor final del `contador`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION contar_repeticiones(arreglo, tamano, buscado)
VARIABLES:
    contador (entero)
INICIO
    contador = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] == buscado ENTONCES
            contador = contador + 1
        FIN SI
    FIN PARA
    RETORNAR contador
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_09)=
### Ejercicio 2.03.09 - Elemento más cercano ⭐⭐☆☆☆

Dado un arreglo y un valor de referencia, encontrar el elemento en el arreglo
que tiene la menor diferencia absoluta con dicho valor.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y un valor de referencia.
-   **Variables:** Se necesitan variables para guardar la `menor_diferencia`
    encontrada hasta el momento y el `elemento_mas_cercano`.
-   **Proceso:**
    1.  Inicializar `menor_diferencia` con un valor muy grande y
        `elemento_mas_cercano` con el primer elemento.
    2.  Recorrer el arreglo. Para cada elemento, calcular la `diferencia_actual`
        (el valor absoluto de `elemento - referencia`).
    3.  Si `diferencia_actual` es menor que `menor_diferencia`, actualizar
        `menor_diferencia` y `elemento_mas_cercano`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION encontrar_mas_cercano(arreglo, tamano, referencia)
VARIABLES:
    menor_diferencia, diferencia_actual (reales)
    elemento_cercano (tipo del arreglo)
INICIO
    menor_diferencia = VALOR_INFINITO
    PARA cada elemento x EN arreglo HACER
        diferencia_actual = VALOR_ABSOLUTO(x - referencia)
        SI diferencia_actual < menor_diferencia ENTONCES
            menor_diferencia = diferencia_actual
            elemento_cercano = x
        FIN SI
    FIN PARA
    RETORNAR elemento_cercano
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Manipulación de Arreglos

(ej_b2_c03_10)=
### Ejercicio 2.03.10 - Inversión ⭐⭐☆☆☆

Invertir el orden de los elementos de un arreglo _in-place_, es decir, sin usar
un segundo arreglo para almacenar el resultado temporalmente.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Utilizar dos índices (o punteros): `inicio` comenzando en 0 y
    `fin` comenzando en `tamaño-1`.
-   Usar un lazo `while` que se ejecute mientras `inicio < fin`.
-   En cada iteración:
    1.  Intercambiar los elementos en las posiciones `inicio` y `fin`.
    2.  Incrementar `inicio` y decrementar `fin` para moverse hacia el centro
        del arreglo.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO invertir_arreglo(REF arreglo, tamano)
VARIABLES:
    inicio, fin, temporal (enteros)
INICIO
    inicio = 0
    fin = tamano - 1
    MIENTRAS inicio < fin HACER
        // Intercambiar elementos
        temporal = arreglo[inicio]
        arreglo[inicio] = arreglo[fin]
        arreglo[fin] = temporal

        inicio = inicio + 1
        fin = fin - 1
    FIN MIENTRAS
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_11)=
### Ejercicio 2.03.11 - Copia ⭐⭐☆☆☆

Copiar todos los elementos de un arreglo de origen a un arreglo de destino.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo de origen, un arreglo de destino y el tamaño.
-   **Precondición:** El arreglo de destino debe tener suficiente capacidad para
    albergar todos los elementos del arreglo de origen.
-   **Proceso:** Recorrer el arreglo de origen con un lazo `for` y, en cada
    iteración, asignar el elemento de origen al elemento correspondiente en el
    arreglo de destino: `destino[i] = origen[i]`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO copiar_arreglo(origen, REF destino, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        destino[i] = origen[i]
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_12)=
### Ejercicio 2.03.12 - Deduplicación ⭐⭐☆☆☆

Eliminar los elementos duplicados de un arreglo, conservando solo la primera
aparición de cada elemento. La función debe modificar el arreglo _in-place_ y
devolver el nuevo tamaño lógico.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso (si el orden no importa):** Ordenar el arreglo primero. Luego,
    recorrerlo con dos punteros (`lectura` y `escritura`). Si el elemento actual
    es diferente al anterior, se copia a la posición de `escritura` y se avanza
    `escritura`.
-   **Proceso (si el orden importa):** Usar un lazo anidado o una estructura de
    datos auxiliar (como un hash set) para llevar un registro de los elementos
    ya vistos.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION deduplicar_arreglo(REF arreglo, tamano)
INICIO
    SI tamano == 0 RETORNAR 0

    ORDENAR(arreglo, tamano)

    indice_escritura = 1
    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] != arreglo[i-1] ENTONCES
            arreglo[indice_escritura] = arreglo[i]
            indice_escritura = indice_escritura + 1
        FIN SI
    FIN PARA
    RETORNAR indice_escritura
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Verificación

(ej_b2_c03_13)=
### Ejercicio 2.03.13 - ¿Está ordenado? ⭐⭐☆☆☆

Verificar si un arreglo está ordenado de forma ascendente.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Recorrer el arreglo desde el primer elemento hasta el
    penúltimo. En cada posición `i`, comparar el elemento `arreglo[i]` con el
    siguiente, `arreglo[i+1]`.
-   **Condición de Salida:** Si en algún momento se encuentra que `arreglo[i] >
    arreglo[i+1]`, el arreglo no está ordenado y la función puede devolver
    `falso` inmediatamente.
-   **Salida:** Si el lazo termina sin encontrar ninguna inversión de orden,
    significa que el arreglo está ordenado y la función devuelve `verdadero`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION esta_ordenado(arreglo, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-2 HACER
        SI arreglo[i] > arreglo[i+1] ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_14)=
### Ejercicio 2.03.14 - Solo positivos ⭐⭐☆☆☆

Verificar si todos los elementos de un arreglo son números positivos (mayores
que cero).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Recorrer el arreglo con un lazo.
-   **Condición de Salida:** En cuanto se encuentre un elemento que sea menor o
    igual a cero, se puede concluir que no todos son positivos y devolver
    `falso`.
-   **Salida:** Si el lazo se completa sin encontrar ningún número no positivo,
    devolver `verdadero`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION son_todos_positivos(arreglo, tamano)
INICIO
    PARA cada elemento x EN arreglo HACER
        SI x <= 0 ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Operaciones Avanzadas con Arreglos

(ej_b2_c03_15)=
### Ejercicio 2.03.15 - Rotación de arreglo ⭐⭐⭐☆☆

Implementar una función que rote los elementos de un arreglo `k` posiciones
hacia la derecha. Esto significa que los últimos `k` elementos se moverán al
principio del arreglo, y el resto de los elementos se desplazarán hacia la
derecha.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño `n`, y el número de posiciones a rotar
    `k`.
-   **Proceso (con arreglo auxiliar):**
    1.  Crear un arreglo temporal del mismo tamaño.
    2.  Recorrer el arreglo original. Para cada elemento en la posición `i`, su
        nueva posición en el arreglo temporal será `(i + k) % n`.
    3.  Copiar el contenido del arreglo temporal de vuelta al original.
-   **Proceso (in-place, más avanzado):**
    1.  Invertir todo el arreglo.
    2.  Invertir los primeros `k` elementos.
    3.  Invertir los `n-k` elementos restantes.
-   **Módulo:** Es útil calcular `k = k % n` al principio, por si `k` es mayor
    que `n`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO rotar_derecha(REF arreglo, n, k)
VARIABLES:
    temporal (arreglo de tamaño n)
INICIO
    k = k MOD n // Manejar rotaciones mayores que n

    PARA i DESDE 0 HASTA n-1 HACER
        nueva_pos = (i + k) MOD n
        temporal[nueva_pos] = arreglo[i]
    FIN PARA

    // Copiar de vuelta al arreglo original
    PARA i DESDE 0 HASTA n-1 HACER
        arreglo[i] = temporal[i]
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_16)=
### Ejercicio 2.03.16 - Fusión de arreglos ⭐⭐⭐☆☆

Escribir una función que fusione dos arreglos en un tercer arreglo que contenga
todos los elementos de los dos primeros. Si los arreglos originales están
ordenados, el resultado también debería estarlo (ver Merge Sort).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Dos arreglos (`a1`, `a2`) con sus respectivos tamaños (`n1`,
    `n2`).
-   **Salida:** Un nuevo arreglo de tamaño `n1 + n2`.
-   **Proceso (desordenado):** Simplemente copiar todos los elementos de `a1` al
    nuevo arreglo, y luego todos los elementos de `a2` a continuación.
-   **Proceso (ordenado):** Usar el algoritmo de mezcla de Merge Sort. Con tres
    punteros (`i` para `a1`, `j` para `a2`, `k` para el resultado), comparar
    `a1[i]` y `a2[j]`, copiar el menor al resultado y avanzar el puntero
    correspondiente.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION fusionar_ordenado(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo de tamaño n1+n2)
    i, j, k (enteros)
INICIO
    i=0, j=0, k=0
    MIENTRAS i < n1 Y j < n2 HACER
        SI a1[i] <= a2[j] ENTONCES
            resultado[k] = a1[i]
            i = i + 1
        SINO
            resultado[k] = a2[j]
            j = j + 1
        FIN SI
        k = k + 1
    FIN MIENTRAS

    // Copiar elementos restantes
    MIENTRAS i < n1 HACER
        resultado[k] = a1[i]
        i = i + 1, k = k + 1
    FIN MIENTRAS
    MIENTRAS j < n2 HACER
        resultado[k] = a2[j]
        j = j + 1, k = k + 1
    FIN MIENTRAS

    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_17)=
### Ejercicio 2.03.17 - Intersección de arreglos ⭐⭐⭐☆☆

Crear una función que reciba dos arreglos y devuelva un nuevo arreglo con los
elementos que son comunes a ambos. Cada elemento debe aparecer solo una vez en
el resultado.

:::{hint} Lógica y Consideraciones
-   **Entrada:** Dos arreglos y sus tamaños.
-   **Proceso (con arreglos ordenados):** Usar dos punteros, uno para cada
    arreglo. Si los elementos son iguales, se añade al resultado y se avanzan
    ambos punteros. Si son diferentes, se avanza el puntero del arreglo que
    tenga el elemento más pequeño.
-   **Proceso (con arreglos desordenados):** Usar lazos anidados. Para cada
    elemento del primer arreglo, buscar si existe en el segundo. Para evitar
    duplicados en el resultado, se puede usar una estructura de datos auxiliar
    (hash set) o verificar si el elemento ya fue añadido.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION interseccion(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
    i, j (enteros)
INICIO
    i=0, j=0
    MIENTRAS i < n1 Y j < n2 HACER
        SI a1[i] < a2[j] ENTONCES
            i = i + 1
        SINO SI a2[j] < a1[i] ENTONCES
            j = j + 1
        SINO // Son iguales
            AÑADIR a1[i] a resultado (si no está ya)
            i = i + 1, j = j + 1
        FIN SI
    FIN MIENTRAS
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_18)=
### Ejercicio 2.03.18 - Unión de arreglos ⭐⭐⭐☆☆

Crear una función que reciba dos arreglos y devuelva un nuevo arreglo con todos
los elementos de ambos, sin duplicados.

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Copiar el primer arreglo a un arreglo de resultado temporal.
    2.  Recorrer el segundo arreglo. Para cada elemento, verificar si ya existe
        en el resultado temporal.
    3.  Si no existe, añadirlo.
-   **Optimización:** Usar una tabla hash para llevar un registro de los
    elementos ya añadidos mejora la eficiencia de la búsqueda.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION union_arreglos(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
    // Usar una tabla hash o similar para eficiencia
    elementos_vistos (conjunto)
INICIO
    PARA cada elemento x en a1 HACER
        AÑADIR x a resultado
        AÑADIR x a elementos_vistos
    FIN PARA
    PARA cada elemento y en a2 HACER
        SI y NO ESTÁ EN elementos_vistos ENTONCES
            AÑADIR y a resultado
            AÑADIR y a elementos_vistos
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_19)=
### Ejercicio 2.03.19 - Separar pares e impares ⭐⭐☆☆☆

Reorganizar un arreglo _in-place_ de tal manera que todos los números pares
queden al principio y todos los impares al final. El orden relativo entre los
números pares o entre los impares no necesita conservarse.

:::{hint} Lógica y Consideraciones
-   **Proceso (dos punteros):**
    1.  Usar dos índices, `izquierda` comenzando en 0 y `derecha` en `tamaño-1`.
    2.  Mientras `izquierda < derecha`:
        a. Mover `izquierda` hacia la derecha hasta encontrar un número impar.
        b. Mover `derecha` hacia la izquierda hasta encontrar un número par.
        c. Si `izquierda < derecha`, intercambiar los elementos en esas
        posiciones.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO separar_pares_impares(REF arreglo, tamano)
VARIABLES:
    izquierda, derecha (enteros)
INICIO
    izquierda = 0, derecha = tamano - 1
    MIENTRAS izquierda < derecha HACER
        MIENTRAS arreglo[izquierda] MOD 2 == 0 Y izquierda < derecha HACER
            izquierda = izquierda + 1
        FIN MIENTRAS
        MIENTRAS arreglo[derecha] MOD 2 != 0 Y izquierda < derecha HACER
            derecha = derecha - 1
        FIN MIENTRAS

        SI izquierda < derecha ENTONCES
            INTERCAMBIAR(arreglo[izquierda], arreglo[derecha])
            izquierda = izquierda + 1
            derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_20)=
### Ejercicio 2.03.20 - Algoritmo de Kadane (Suma Máxima de Subarreglo Contiguo) ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b2_c03_20_kadane

Implementá el **Algoritmo de Kadane** en tiempo lineal $\mathcal{O}(n)$ y espacio $\mathcal{O}(1)$ para hallar la suma máxima de un subarreglo contiguo no vacío:

```c
long long max_suma_subarreglo_kadane(const int *arr, size_t n, bool *valido);
```

**Reglas de cálculo:**
1. **Dominio con negativos:** Si todos los elementos del arreglo son negativos, la suma máxima corresponde al elemento individual menos negativo (por ejemplo, para `{-5, -2, -8}`, la respuesta es `-2`).
2. **Manejo defensivo:** Si `arr == NULL` o `n == 0`, la función retorna `0LL` y asigna `false` al puntero `valido` (si no es `NULL`). Ante éxito, asigna `true` a `*valido`.

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Entrada `arr` ($n$) | Retorno Esperado | `*valido` | Subarreglo Óptimo |
| :--- | :--- | :--- | :--- | :--- |
| **Normal Mixto** | `{-2, 1, -3, 4, -1, 2, 1, -5, 4}`, $n=9$ | `6LL` | `true` | `{4, -1, 2, 1}` |
| **Todos Negativos** | `{-5, -2, -8, -1}`, $n=4$ | `-1LL` | `true` | `{-1}` |
| **Todos Positivos** | `{1, 2, 3, 4}`, $n=4$ | `10LL` | `true` | Todo el arreglo |
| **Elemento Único** | `{-7}`, $n=1$ | `-7LL` | `true` | `{-7}` |
| **Vector Vacío** | `NULL`, $n=0$ | `0LL` | `false` | Inexistente |

:::

::::{solution} ej_b2_c03_20_kadane
:class: dropdown

```{code-block} c
:linenos:
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

long long max_suma_subarreglo_kadane(const int *arr, size_t n, bool *valido)
{
    if (arr == NULL || n == 0)
    {
        if (valido != NULL)
        {
            *valido = false;
        }
        return 0LL;
    }

    if (valido != NULL)
    {
        *valido = true;
    }

    long long max_global = arr[0];
    long long max_actual = arr[0];

    for (size_t i = 1; i < n; i++)
    {
        long long valor = arr[i];
        if (max_actual + valor > valor)
        {
            max_actual += valor;
        }
        else
        {
            max_actual = valor;
        }

        if (max_actual > max_global)
        {
            max_global = max_actual;
        }
    }

    return max_global;
}

int main(void)
{
    bool ok = false;

    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(max_suma_subarreglo_kadane(arr1, 9, &ok) == 6LL && ok == true);

    int arr_neg[] = {-5, -2, -8, -1};
    assert(max_suma_subarreglo_kadane(arr_neg, 4, &ok) == -1LL && ok == true);

    int arr_pos[] = {1, 2, 3, 4};
    assert(max_suma_subarreglo_kadane(arr_pos, 4, &ok) == 10LL && ok == true);

    int arr_uno[] = {-7};
    assert(max_suma_subarreglo_kadane(arr_uno, 1, &ok) == -7LL && ok == true);

    assert(max_suma_subarreglo_kadane(NULL, 0, &ok) == 0LL && ok == false);

    return 0;
}
```

::::
<!-- {solution} ej_b2_c03_20_kadane -->
    -   `max_actual`: La suma máxima del subarreglo que termina en la posición
        actual.
    -   `max_global`: La suma máxima encontrada en todo el arreglo hasta el
        momento.
-   En cada paso `i`:
    1.  `max_actual = MAXIMO(arreglo[i], max_actual + arreglo[i])`
    2.  `max_global = MAXIMO(max_global, max_actual)`
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION kadane(arreglo, tamano)
VARIABLES:
    max_actual, max_global
INICIO
    max_actual = arreglo[0]
    max_global = arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        max_actual = MAXIMO(arreglo[i], max_actual + arreglo[i])
        SI max_actual > max_global ENTONCES
            max_global = max_actual
        FIN SI
    FIN PARA
    RETORNAR max_global
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_21)=
### Ejercicio 2.03.21 - Histograma ⭐⭐☆☆☆

Dado un arreglo de enteros no negativos, el programa debe imprimir un histograma
simple usando asteriscos, donde cada número `n` se representa con una línea de
`n` asteriscos.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Usar lazos anidados.
    1.  El lazo exterior recorre cada elemento del arreglo.
    2.  El lazo interior se ejecuta tantas veces como el valor del elemento
        actual, imprimiendo un asterisco en cada una de sus iteraciones.
    3.  Después del lazo interior, se imprime un salto de línea.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO imprimir_histograma(arreglo, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        ESCRIBIR i, ": " SIN SALTO DE LÍNEA
        PARA j DESDE 1 HASTA arreglo[i] HACER
            ESCRIBIR "*" SIN SALTO DE LÍNEA
        FIN PARA
        ESCRIBIR SALTO DE LÍNEA
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_22)=
### Ejercicio 2.03.22 - Barajar arreglo (Fisher-Yates) ⭐⭐⭐☆☆

Implementar el algoritmo de Fisher-Yates para barajar (desordenar
aleatoriamente) los elementos de un arreglo _in-place_.

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer el arreglo desde el último elemento hasta el segundo (`i` desde
        `n-1` hasta 1).
    2.  En cada iteración, generar un índice aleatorio `j` entre 0 e `i`
        (inclusive).
    3.  Intercambiar el elemento en la posición `i` con el elemento en la
        posición `j`.
-   **Aleatoriedad:** Requiere `srand()` y `rand()`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO barajar_fisher_yates(REF arreglo, tamano)
VARIABLES:
    j, temporal (enteros)
INICIO
    PARA i DESDE tamano-1 HASTA 1 CON PASO -1 HACER
        j = generar_aleatorio(0, i)
        INTERCAMBIAR(arreglo[i], arreglo[j])
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_23)=
### Ejercicio 2.03.23 - Encontrar elemento faltante ⭐⭐☆☆☆

Dado un arreglo que contiene `n-1` números distintos en el rango de 1 a `n`,
encontrar el único número que falta.

:::{hint} Lógica y Consideraciones
-   **Proceso (Suma):**
    1.  Calcular la suma esperada de todos los números de 1 a `n` usando la
        fórmula de la progresión aritmética: `suma_esperada = n * (n + 1) / 2`.
    2.  Calcular la suma real de los elementos en el arreglo dado.
    3.  El número faltante es la diferencia: `suma_esperada - suma_real`.
-   **Proceso (XOR):** El XOR de todos los números del rango con todos los
    números del arreglo dará como resultado el número faltante.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION encontrar_faltante(arreglo, tamano_actual)
VARIABLES:
    n, suma_esperada, suma_real (enteros)
INICIO
    n = tamano_actual + 1
    suma_esperada = n * (n + 1) / 2
    suma_real = sumar_arreglo(arreglo, tamano_actual)
    RETORNAR suma_esperada - suma_real
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_24)=
### Ejercicio 2.03.24 - Encontrar par con suma X ⭐⭐☆☆☆

Dado un arreglo de números y un valor `X`, determinar si existe un par de
elementos en el arreglo cuya suma sea exactamente `X`.

:::{hint} Lógica y Consideraciones
-   **Proceso (Ordenando):**
    1.  Ordenar el arreglo.
    2.  Usar dos punteros: `izquierda` en el inicio y `derecha` en el final.
    3.  Mientras `izquierda < derecha`:
        a. Calcular la suma `s = arreglo[izquierda] + arreglo[derecha]`.
        b. Si `s == X`, se encontró el par.
        c. Si `s < X`, se necesita una suma mayor, así que se mueve `izquierda`
        a la derecha.
        d. Si `s > X`, se necesita una suma menor, así que se mueve `derecha` a
        la izquierda.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION existe_par_con_suma(arreglo, tamano, X)
VARIABLES:
    izquierda, derecha, suma (enteros)
INICIO
    ORDENAR(arreglo, tamano)
    izquierda = 0, derecha = tamano - 1

    MIENTRAS izquierda < derecha HACER
        suma = arreglo[izquierda] + arreglo[derecha]
        SI suma == X ENTONCES
            RETORNAR VERDADERO
        SINO SI suma < X ENTONCES
            izquierda = izquierda + 1
        SINO
            derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
    RETORNAR FALSO
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_25)=
### Ejercicio 2.03.25 - Mediana de un arreglo ⭐⭐⭐☆☆

Calcular la mediana de un arreglo. La mediana es el valor que se encuentra en la
posición central de un arreglo ordenado. Si el arreglo tiene un número par de
elementos, la mediana es el promedio de los dos elementos centrales.

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Ordenar el arreglo.
    2.  Determinar el índice del medio: `medio = tamano / 2`.
    3.  Si el tamaño es impar, la mediana es `arreglo[medio]`.
    4.  Si el tamaño es par, la mediana es `(arreglo[medio - 1] +
        arreglo[medio]) / 2.0`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION calcular_mediana(arreglo, tamano)
INICIO
    ORDENAR(arreglo, tamano)
    SI tamano MOD 2 != 0 ENTONCES
        RETORNAR arreglo[tamano / 2]
    SINO
        RETORNAR (arreglo[tamano/2 - 1] + arreglo[tamano/2]) / 2.0
    FIN SI
    FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_26)=
### Ejercicio 2.03.26 - Moda de un arreglo ⭐⭐⭐☆☆

Encontrar la moda de un arreglo, que es el elemento que aparece con mayor
frecuencia.

:::{hint} Lógica y Consideraciones
-   **Proceso (con ordenamiento):**
    1.  Ordenar el arreglo. Esto agrupa los elementos iguales.
    2.  Recorrer el arreglo y contar la longitud de cada secuencia de elementos
        idénticos.
    3.  Llevar un registro del elemento con la frecuencia más alta encontrada
        hasta el momento.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION encontrar_moda(arreglo, tamano)
VARIABLES:
    moda, max_frecuencia, frec_actual, elemento_actual
INICIO
    ORDENAR(arreglo, tamano)
    moda = arreglo[0], max_frecuencia = 1, frec_actual = 1

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] == arreglo[i-1] ENTONCES
            frec_actual = frec_actual + 1
        SINO
            frec_actual = 1
        FIN SI
        SI frec_actual > max_frecuencia ENTONCES
            max_frecuencia = frec_actual
            moda = arreglo[i]
        FIN SI
    FIN PARA
    RETORNAR moda
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_27)=
### Ejercicio 2.03.27 - Rellenar con secuencia aritmética ⭐⭐☆☆☆

Escribir una función que llene un arreglo con los términos de una secuencia
aritmética, dados un valor de inicio, un tamaño y un paso (la diferencia
constante entre términos).

:::{hint} Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño, un valor de `inicio` y un `paso`.
-   **Proceso:** Recorrer el arreglo con un lazo `for`. Para cada índice `i`, el
    valor a asignar es `inicio + (i * paso)`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO rellenar_secuencia(REF arreglo, tamano, inicio, paso)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        arreglo[i] = inicio + (i * paso)
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_28)=
### Ejercicio 2.03.28 - Diferencia simétrica ⭐⭐☆☆☆

Calcular la diferencia simétrica entre dos arreglos. El resultado debe ser un
nuevo arreglo que contenga los elementos que están en uno de los arreglos, pero
no en ambos.

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Iterar sobre el primer arreglo. Para cada elemento, verificar si está en
        el segundo. Si NO está, añadirlo al resultado.
    2.  Iterar sobre el segundo arreglo. Para cada elemento, verificar si está
        en el primero. Si NO está, añadirlo al resultado.
-   **Optimización:** Usar tablas hash para las búsquedas puede hacer el proceso
    mucho más eficiente.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION diferencia_simetrica(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
INICIO
    PARA cada elemento x en a1 HACER
        SI x NO ESTÁ EN a2 ENTONCES
            AÑADIR x a resultado
        FIN SI
    FIN PARA
    PARA cada elemento y en a2 HACER
        SI y NO ESTÁ EN a1 ENTONCES
            AÑADIR y a resultado
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_29)=
### Ejercicio 2.03.29 - Conteo de inversiones ⭐⭐☆☆☆

Contar el número de "inversiones" en un arreglo. Una inversión es un par de
índices `(i, j)` tales que `i < j` y `arr[i] > arr[j]`. Un arreglo perfectamente
ordenado tiene 0 inversiones.

:::{hint} Lógica y Consideraciones
-   **Proceso (Fuerza Bruta):** Usar dos lazos anidados. El lazo exterior itera
    con `i` desde 0 hasta `n-2`. El lazo interior itera con `j` desde `i+1`
    hasta `n-1`. Si `arreglo[i] > arreglo[j]`, se incrementa un contador.
-   **Complejidad:** La solución de fuerza bruta es O(n^2). Existen algoritmos
    más eficientes basados en Merge Sort.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION contar_inversiones(arreglo, tamano)
VARIABLES:
    contador (entero)
INICIO
    contador = 0
    PARA i DESDE 0 HASTA tamano-2 HACER
        PARA j DESDE i+1 HASTA tamano-1 HACER
            SI arreglo[i] > arreglo[j] ENTONCES
                contador = contador + 1
            FIN SI
        FIN PARA
    FIN PARA
    RETORNAR contador
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

## Más Manipulación de Arreglos

(ej_b2_c03_30)=
### Ejercicio 2.03.30 - Picos y valles ⭐⭐☆☆☆

Escribir una función que encuentre todos los "picos" en un arreglo. Un pico es
un elemento que es estrictamente mayor que sus dos vecinos (el anterior y el
siguiente). Los elementos en los extremos no pueden ser picos.

:::{hint} Lógica y Consideraciones
-   **Proceso:** Recorrer el arreglo desde el segundo elemento (`i=1`) hasta el
    penúltimo (`i=n-2`).
-   **Condición:** En cada posición `i`, verificar si `arreglo[i] >
    arreglo[i-1]` Y `arreglo[i] > arreglo[i+1]`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO encontrar_picos(arreglo, tamano)
INICIO
    PARA i DESDE 1 HASTA tamano-2 HACER
        SI arreglo[i] > arreglo[i-1] Y arreglo[i] > arreglo[i+1] ENTONCES
            ESCRIBIR arreglo[i], " es un pico en el índice ", i
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_31)=
### Ejercicio 2.03.31 - Subarreglo más largo con suma cero ⭐⭐⭐☆☆

Dado un arreglo de enteros (positivos y negativos), encontrar la longitud del
subarreglo contiguo más largo cuya suma de elementos sea cero.

:::{hint} Lógica y Consideraciones
-   **Proceso (Tabla Hash):**
    1.  Usar una tabla hash para almacenar las sumas acumuladas y sus primeros
        índices de aparición.
    2.  Recorrer el arreglo, manteniendo una `suma_actual`.
    3.  Si `suma_actual` ya se ha visto antes en el índice `j`, entonces el
        subarreglo desde `j+1` hasta la posición actual tiene suma cero.
        Calcular su longitud y actualizar la longitud máxima.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION subarreglo_suma_cero(arreglo, tamano)
VARIABLES:
    mapa_sumas (tabla hash)
    suma, max_longitud (enteros)
INICIO
    suma = 0, max_longitud = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        suma = suma + arreglo[i]
        SI suma == 0 ENTONCES
            max_longitud = i + 1
        SINO SI mapa_sumas CONTIENE suma ENTONCES
            max_longitud = MAXIMO(max_longitud, i - mapa_sumas[suma])
        SINO
            mapa_sumas[suma] = i
        FIN SI
    FIN PARA
    RETORNAR max_longitud
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_32)=
### Ejercicio 2.03.32 - Reorganizar positivos y negativos ⭐⭐☆☆☆

Reorganizar un arreglo _in-place_ de tal manera que todos los números negativos
aparezcan antes que todos los números positivos. El orden relativo entre los
números del mismo signo no es importante.

:::{hint} Lógica y Consideraciones
-   **Proceso (similar a separar pares/impares):** Usar dos punteros,
    `izquierda` y `derecha`. Mover `izquierda` hasta encontrar un número
    positivo y `derecha` hasta encontrar uno negativo. Luego, intercambiarlos y
    continuar hasta que los punteros se crucen.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO reorganizar_signos(REF arreglo, tamano)
VARIABLES:
    izquierda, derecha (enteros)
INICIO
    izquierda = 0, derecha = tamano - 1
    MIENTRAS izquierda <= derecha HACER
        SI arreglo[izquierda] < 0 Y arreglo[derecha] < 0 ENTONCES
            izquierda = izquierda + 1
        SINO SI arreglo[izquierda] > 0 Y arreglo[derecha] < 0 ENTONCES
            INTERCAMBIAR(arreglo[izquierda], arreglo[derecha])
            izquierda = izquierda + 1, derecha = derecha - 1
        SINO SI arreglo[izquierda] > 0 Y arreglo[derecha] > 0 ENTONCES
            derecha = derecha - 1
        SINO
            izquierda = izquierda + 1, derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_33)=
### Ejercicio 2.03.33 - Producto de los demás elementos ⭐⭐☆☆☆

Dado un arreglo de números, crear un nuevo arreglo donde cada elemento en la
posición `i` sea el producto de todos los demás números del arreglo original,
pero sin usar el operador de división.

:::{hint} Lógica y Consideraciones
-   **Proceso (dos pasadas):**
    1.  Crear un arreglo `resultado`.
    2.  **Primera pasada (izquierda a derecha):** Recorrer el arreglo. Para cada
        `i`, `resultado[i]` será el producto de todos los elementos a su
        izquierda. Mantener un acumulador `izquierda_prod`.
    3.  **Segunda pasada (derecha a izquierda):** Recorrer el arreglo al revés.
        Mantener un acumulador `derecha_prod`. Multiplicar `resultado[i]` por
        `derecha_prod` para incorporar los productos de la derecha.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION producto_de_los_demas(arreglo, tamano)
VARIABLES:
    resultado (arreglo de tamaño n)
    izquierda_prod, derecha_prod
INICIO
    izquierda_prod = 1
    PARA i DESDE 0 HASTA tamano-1 HACER
        resultado[i] = izquierda_prod
        izquierda_prod = izquierda_prod * arreglo[i]
    FIN PARA

    derecha_prod = 1
    PARA i DESDE tamano-1 HASTA 0 CON PASO -1 HACER
        resultado[i] = resultado[i] * derecha_prod
        derecha_prod = derecha_prod * arreglo[i]
    FIN PARA

    RETORNAR resultado
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_34)=
### Ejercicio 2.03.34 - Arreglo de frecuencias ⭐⭐⭐☆☆

Dado un arreglo de enteros que contiene números en un rango conocido (por
ejemplo, de 0 a 99), crear un "arreglo de frecuencias" que cuente cuántas veces
aparece cada número.

:::{hint} Lógica y Consideraciones
-   **Proceso:**
    1.  Crear un nuevo arreglo `frecuencias` del tamaño del rango (ej. 100),
        inicializado todo en 0.
    2.  Recorrer el arreglo de entrada. Para cada número `x`, usarlo como índice
        en el arreglo de frecuencias e incrementar la cuenta:
        `frecuencias[x]++`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION calcular_frecuencias(arreglo, tamano, rango_max)
VARIABLES:
    frecuencias (arreglo de tamaño rango_max, inicializado en 0)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        numero = arreglo[i]
        frecuencias[numero] = frecuencias[numero] + 1
    FIN PARA
    RETORNAR frecuencias
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_35)=
### Ejercicio 2.03.35 - ¿Es subconjunto? ⭐⭐☆☆☆

Implementar una función que determine si un arreglo `A` es un subconjunto de
otro arreglo `B`. Esto significa que todos los elementos de `A` deben estar
presentes en `B`.

:::{hint} Lógica y Consideraciones
-   **Proceso (con ordenamiento):**
    1.  Ordenar ambos arreglos, `A` y `B`.
    2.  Usar dos punteros, `i` para `A` y `j` para `B`.
    3.  Recorrer ambos arreglos. Si `A[i] == B[j]`, se encontró una
        coincidencia, avanzar ambos. Si `A[i] > B[j]`, avanzar `j`. Si `A[i] <
        B[j]`, significa que `A[i]` no está en `B`, por lo que no es
        subconjunto.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION es_subconjunto(A, nA, B, nB)
VARIABLES:
    i, j (enteros)
INICIO
    ORDENAR(A, nA)
    ORDENAR(B, nB)
    i = 0, j = 0
    MIENTRAS i < nA Y j < nB HACER
        SI A[i] > B[j] ENTONCES
            j = j + 1
        SINO SI A[i] == B[j] ENTONCES
            i = i + 1, j = j + 1
        SINO // A[i] < B[j]
            RETORNAR FALSO
        FIN SI
    FIN MIENTRAS

    RETORNAR (i == nA)
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_36)=
### Ejercicio 2.03.36 - Mover ceros al final ⭐⭐☆☆☆

Escribir una función que mueva todos los ceros de un arreglo al final del mismo,
manteniendo el orden relativo de los elementos no nulos.

:::{hint} Lógica y Consideraciones
-   **Proceso (un solo recorrido):**
    1.  Usar un índice `posicion_no_cero` inicializado en 0.
    2.  Recorrer el arreglo. Si el elemento actual no es cero, se coloca en la
        posición `posicion_no_cero` y se incrementa `posicion_no_cero`.
    3.  Después del primer lazo, todos los elementos no nulos están al principio
        en su orden original. Llenar el resto del arreglo con ceros.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO mover_ceros_final(REF arreglo, tamano)
VARIABLES:
    posicion_no_cero (entero)
INICIO
    posicion_no_cero = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] != 0 ENTONCES
            arreglo[posicion_no_cero] = arreglo[i]
            posicion_no_cero = posicion_no_cero + 1
        FIN SI
    FIN PARA

    PARA i DESDE posicion_no_cero HASTA tamano-1 HACER
        arreglo[i] = 0
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_37)=
### Ejercicio 2.03.37 - Líderes en un arreglo ⭐⭐⭐☆☆

Encontrar todos los "líderes" en un arreglo. Un elemento es un líder si es mayor
que todos los elementos que se encuentran a su derecha. El elemento más a la
derecha siempre es un líder.

:::{hint} Lógica y Consideraciones
-   **Proceso (recorrido inverso):** La forma más eficiente es recorrer el
    arreglo de derecha a izquierda.
    1.  El último elemento siempre es un líder. Guardarlo como `maximo_derecha`.
    2.  Iterar desde el penúltimo elemento hacia el principio.
    3.  Si el elemento actual es mayor que `maximo_derecha`, es un nuevo líder.
        Imprimirlo y actualizar `maximo_derecha`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
PROCEDIMIENTO encontrar_lideres(arreglo, tamano)
VARIABLES:
    maximo_derecha (entero)
INICIO
    maximo_derecha = arreglo[tamano-1]
    ESCRIBIR maximo_derecha

    PARA i DESDE tamano-2 HASTA 0 CON PASO -1 HACER
        SI arreglo[i] > maximo_derecha ENTONCES
            maximo_derecha = arreglo[i]
            ESCRIBIR maximo_derecha
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_38)=
### Ejercicio 2.03.38 - Máxima diferencia ⭐⭐☆☆☆

Encontrar la máxima diferencia `arr[j] - arr[i]` en un arreglo, con la condición
de que el índice `j` sea mayor que el índice `i`.

:::{hint} Lógica y Consideraciones
-   **Proceso (un solo recorrido):**
    1.  Mantener dos variables: `max_diferencia` y `min_elemento`.
    2.  Inicializar `max_diferencia` a un valor muy bajo y `min_elemento` con el
        primer elemento.
    3.  Recorrer el arreglo desde el segundo elemento. En cada paso:
        a. Actualizar `max_diferencia` si `elemento_actual - min_elemento` es
        mayor.
        b. Actualizar `min_elemento` si `elemento_actual` es menor.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION max_diferencia(arreglo, tamano)
VARIABLES:
    max_diferencia, min_elemento
INICIO
    min_elemento = arreglo[0]
    max_diferencia = arreglo[1] - arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI (arreglo[i] - min_elemento) > max_diferencia ENTONCES
            max_diferencia = arreglo[i] - min_elemento
        FIN SI
        SI arreglo[i] < min_elemento ENTONCES
            min_elemento = arreglo[i]
        FIN SI
    FIN PARA
    RETORNAR max_diferencia
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->

(ej_b2_c03_39)=
### Ejercicio 2.03.39 - Punto de equilibrio ⭐⭐☆☆☆

Encontrar un "punto de equilibrio" en un arreglo. Es un índice tal que la suma
de los elementos a su izquierda es igual a la suma de los elementos a su
derecha. Si no existe, devolver -1.

:::{hint} Lógica y Consideraciones
-   **Proceso (dos pasadas):**
    1.  Calcular la suma total de todos los elementos del arreglo.
    2.  Inicializar `suma_izquierda = 0`.
    3.  Recorrer el arreglo. En cada posición `i`:
        a. `suma_derecha = suma_total - suma_izquierda - arreglo[i]`.
        b. Si `suma_izquierda == suma_derecha`, se encontró el punto.
        c. Actualizar `suma_izquierda = suma_izquierda + arreglo[i]`.
:::
<!-- {hint} Lógica y Consideraciones -->

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
:linenos:
FUNCION encontrar_equilibrio(arreglo, tamano)
VARIABLES:
    suma_total, suma_izquierda
INICIO
    suma_total = sumar_arreglo(arreglo, tamano)
    suma_izquierda = 0

    PARA i DESDE 0 HASTA tamano-1 HACER
        suma_total = suma_total - arreglo[i]
        SI suma_izquierda == suma_total ENTONCES
            RETORNAR i
        FIN SI
        suma_izquierda = suma_izquierda + arreglo[i]
    FIN PARA

    RETORNAR -1
FIN FUNCION

```
<!-- {code-block} pseudocode -->

:::
<!-- {tip} Ayuda (pseudocódigo) -->
