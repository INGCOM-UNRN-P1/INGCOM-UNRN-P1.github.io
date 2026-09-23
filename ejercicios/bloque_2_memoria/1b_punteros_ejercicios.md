---
title: Ejercicios de Punteros II
short_title: 4b. Punteros II
---

# Ejercicios de Punteros II

## Acerca de

Estos ejercicios prácticos y aplicados complementan la teoría de punteros,
pasaje por referencia y aritmética básica de indirección de memoria en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros`

### Cuestiones de Estilo Aplicables
- **Validación con aserciones:** Es mandatorio validar mediante `assert` de la cabecera
  `<assert.h>` que los punteros recibidos por parámetros en las funciones no
  sean `NULL` (ver {ref}`0x2008h`).
- **Aritmética de punteros:** Recorré los arreglos operando de manera directa
  sobre punteros y evitando índices lógicos cuando la consigna lo requiera,
  incrementando o decrementando las direcciones físicas de memoria de forma explícita.
- **Tipado seguro:** Utilizá `size_t` para longitudes y `const` para punteros cuyos
  datos referenciados no deban ser modificados.

---

(ej_b2_c02b_01)=
### Ejercicio 2.02b.01 - Intercambio de Valores por Referencia ⭐⭐☆☆☆

:::{exercise}
:label: intercambiar_valores
:enumerator: punteros-1

Implementá un procedimiento `void intercambiar(int *a, int *b)` que reciba dos
punteros a enteros. La función debe intercambiar los valores almacenados en las
variables originales apuntadas por `a` y `b`.

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** Punteros escalares, operador de desreferencia (`*`), aserciones (`assert`).  
**Techo conceptual:** Prohibido el uso de memoria dinámica (`malloc`), `structs` o punteros a punteros.

#### Contrato de la Función
- **Firma:** `void intercambiar(int *a, int *b);`
- **Precondiciones:** `a != NULL` y `b != NULL`. Deben apuntar a posiciones válidas de memoria.
- **Postcondiciones:** El valor desreferenciado en `*a` contendrá el valor previo de `*b`, y `*b` el valor previo de `*a`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`*a`, `*b`) | Estado Posterior (`*a`, `*b`) | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `a = 10, b = 20` | `a = 20, b = 10` | Intercambio estándar de enteros positivos |
| **Normal** | `a = -5, b = 15` | `a = 15, b = -5` | Intercambio con signo opuesto |
| **Borde** | `a = 0, b = 0` | `a = 0, b = 0` | Valores nulos idénticos |
| **Borde (Aliasing)**| `p = &x (a == b == &x)` | `*p` inalterado | Ambas variables apuntan a la misma dirección física |
| **Extremal** | `a = INT_MIN, b = INT_MAX` | `a = INT_MAX, b = INT_MIN` | Rangos extremos de representación entera |

:::
<!-- {exercise} -->

::::{solution} intercambiar_valores
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <limits.h>
#include <stddef.h>

void intercambiar(int *a, int *b)
{
    assert(a != NULL);
    assert(b != NULL);

    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main(void)
{
    // Caso normal
    int x = 10;
    int y = 20;
    intercambiar(&x, &y);
    assert(x == 20 && y == 10);

    // Caso con negativos
    int n1 = -5;
    int n2 = 15;
    intercambiar(&n1, &n2);
    assert(n1 == 15 && n2 == -5);

    // Caso borde ceros
    int c1 = 0;
    int c2 = 0;
    intercambiar(&c1, &c2);
    assert(c1 == 0 && c2 == 0);

    // Caso borde aliasing (mismo puntero)
    int mismo = 42;
    intercambiar(&mismo, &mismo);
    assert(mismo == 42);

    // Caso extremal límites INT
    int min_val = INT_MIN;
    int max_val = INT_MAX;
    intercambiar(&min_val, &max_val);
    assert(min_val == INT_MAX && max_val == INT_MIN);

    return 0;
}
```

::::
<!-- {solution} intercambiar_valores -->

---

(ej_b2_c02b_02)=
### Ejercicio 2.02b.02 - Búsqueda del Valor Máximo en Arreglo ⭐⭐☆☆☆

:::{exercise}
:label: encontrar_maximo
:enumerator: funciones-1

Escribí una función `int encontrar_maximo(const int *arreglo, size_t n)` que
reciba un puntero al inicio de un arreglo de enteros (marcado con calificador `const`
para garantizar inmutabilidad) y su tamaño `n`. La función debe recorrer el arreglo
usando exclusivamente aritmética de punteros y devolver el valor del elemento más grande.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Punteros a constantes (`const int *`), aritmética de punteros, tipo `size_t`.  
**Techo conceptual:** Prohibido el uso de indexación con corchetes (`arreglo[i]`), memoria dinámica o `structs`.

#### Contrato de la Función
- **Firma:** `int encontrar_maximo(const int *arreglo, size_t n);`
- **Precondiciones:** `arreglo != NULL`, `n > 0`.
- **Postcondiciones:** Retorna el valor `max` perteneciente al arreglo tal que `max >= *(arreglo + i)` para todo `0 <= i < n`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`arreglo`, `n`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `{1, 5, 3, 9, 2}`, `n = 5` | `9` | Máximo en posición intermedia |
| **Borde (Inicio)** | `{99, 10, 5}`, `n = 3` | `99` | Máximo en el primer elemento |
| **Borde (Fin)** | `{2, 4, 88}`, `n = 3` | `88` | Máximo en el último elemento |
| **Borde (Unitario)**| `{-7}`, `n = 1` | `-7` | Arreglo de un solo elemento negativo |
| **Borde (Duplicados)**| `{4, 4, 4, 4}`, `n = 4` | `4` | Todos los elementos idénticos |
| **Extremal** | `{INT_MIN, -100, -1}`, `n = 3` | `-1` | Todos elementos negativos con extremo inferior |

:::
<!-- {exercise} -->

::::{solution} encontrar_maximo
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <limits.h>
#include <stddef.h>

int encontrar_maximo(const int *arreglo, size_t n)
{
    assert(arreglo != NULL);
    assert(n > 0);

    int maximo = *arreglo;
    const int *fin = arreglo + n;

    for (const int *p = arreglo + 1; p < fin; p++)
    {
        if (*p > maximo)
        {
            maximo = *p;
        }
    }
    return maximo;
}

int main(void)
{
    // Caso normal
    const int arr1[] = {1, 5, 3, 9, 2};
    assert(encontrar_maximo(arr1, 5) == 9);

    // Caso máximo al inicio
    const int arr2[] = {99, 10, 5};
    assert(encontrar_maximo(arr2, 3) == 99);

    // Caso máximo al final
    const int arr3[] = {2, 4, 88};
    assert(encontrar_maximo(arr3, 3) == 88);

    // Caso unitario negativo
    const int arr4[] = {-7};
    assert(encontrar_maximo(arr4, 1) == -7);

    // Caso duplicados
    const int arr5[] = {4, 4, 4, 4};
    assert(encontrar_maximo(arr5, 4) == 4);

    // Caso negativos extremos
    const int arr6[] = {INT_MIN, -100, -1};
    assert(encontrar_maximo(arr6, 3) == -1);

    return 0;
}
```

::::
<!-- {solution} encontrar_maximo -->

---

(ej_b2_c02b_03)=
### Ejercicio 2.02b.03 - Copia de Cadenas mediante Punteros ⭐⭐⭐☆☆

:::{exercise}
:label: copiar_cadena
:enumerator: funciones-2

Implementá un procedimiento `void copiar_cadena(char *destino, const char *origen)`
que replique el comportamiento fundamental de `strcpy`. La función debe copiar
cada carácter de `origen` a `destino`, garantizando la inclusión del terminador nulo
`\0` final. La solución debe implementarse utilizando exclusivamente recorrido por
punteros desreferenciados e incrementos continuos.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Punteros a caracteres (`char *`), `const char *`, convención de cadenas finalizadas en `\0`.  
**Techo conceptual:** Prohibido el uso de funciones de `<string.h>` (`strcpy`, `strlen`), memoria dinámica o buffers auxiliares.

#### Contrato de la Función
- **Firma:** `void copiar_cadena(char *destino, const char *origen);`
- **Precondiciones:** `destino != NULL`, `origen != NULL`. El buffer apuntado por `destino` debe tener capacidad suficiente para contener la longitud de `origen` más el terminador `\0`. Las regiones de memoria no deben solaparse.
- **Postcondiciones:** `destino` contendrá exactamente la misma secuencia de bytes que `origen`, finalizando con `\0`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`origen`) | Estado Posterior (`destino`) | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `"Hola C11"` | `"Hola C11\0"` | Cadena estándar con espacios y alfanuméricos |
| **Borde (Vacía)** | `""` | `"\0"` | Cadena vacía (longitud 0, solo carácter nulo) |
| **Borde (1 Char)** | `"Z"` | `"Z\0"` | Cadena de un único carácter |
| **Normal (Puntuación)**| `"puntero -> dato;"` | `"puntero -> dato;\0"` | Caracteres especiales y signos |

:::
<!-- {exercise} -->

::::{solution} copiar_cadena
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <string.h>

void copiar_cadena(char *destino, const char *origen)
{
    assert(destino != NULL);
    assert(origen != NULL);

    while (*origen != '\0')
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

int main(void)
{
    char buffer[64];

    // Caso normal
    copiar_cadena(buffer, "Hola C11");
    assert(strcmp(buffer, "Hola C11") == 0);

    // Caso cadena vacía
    copiar_cadena(buffer, "");
    assert(buffer[0] == '\0');
    assert(strcmp(buffer, "") == 0);

    // Caso un caracter
    copiar_cadena(buffer, "Z");
    assert(strcmp(buffer, "Z") == 0);

    // Caso puntuación
    copiar_cadena(buffer, "puntero -> dato;");
    assert(strcmp(buffer, "puntero -> dato;") == 0);

    return 0;
}
```

::::
<!-- {solution} copiar_cadena -->

---

(ej_b2_c02b_04)=
### Ejercicio 2.02b.04 - Suma de Arreglo con Rango Semiapierto de Punteros ⭐⭐⭐☆☆

:::{exercise}
:label: sumar_arreglo_punteros
:enumerator: funciones-3

Diseñá una función `int sumar_arreglo(const int *inicio, const int *fin)` que
reciba un puntero al primer elemento de un arreglo y un puntero a la dirección
inmediatamente posterior al último elemento (rango semiabierto `[inicio, fin)`).
La función debe acumular y retornar la suma de los enteros iterando con un
puntero desde `inicio` mientras `p < fin`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Aritmética de punteros, comparación de direcciones en el mismo objeto (`p < fin`), convención de iteradores en memoria.  
**Techo conceptual:** Prohibido el cómputo de índices enteros auxiliares (`i = 0`).

#### Contrato de la Función
- **Firma:** `int sumar_arreglo(const int *inicio, const int *fin);`
- **Precondiciones:** `inicio != NULL`, `fin != NULL`, `inicio <= fin`. Ambos deben pertenecer al mismo bloque contiguo de memoria.
- **Postcondiciones:** Devuelve $\sum_{p=inicio}^{fin-1} *p$. Si `inicio == fin`, devuelve `0`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`arreglo`, rango) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `{1, 2, 3, 4, 5}`, `fin = inicio + 5` | `15` | Suma estándar de positivos |
| **Borde (Rango Vacío)**| `{10, 20}`, `fin = inicio` | `0` | Longitud cero (`inicio == fin`) |
| **Borde (1 Elemento)**| `{42}`, `fin = inicio + 1` | `42` | Arreglo de un solo escalar |
| **Normal (Opuestos)** | `{10, -10, 25, -25}`, `fin = inicio + 4` | `0` | Cancelación simétrica exacta |
| **Normal (Subrango)** | `{10, 20, 30, 40}`, `inicio + 1, inicio + 3` | `50` | Subrango central `[20, 30]` |

:::
<!-- {exercise} -->

::::{solution} sumar_arreglo_punteros
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

int sumar_arreglo(const int *inicio, const int *fin)
{
    assert(inicio != NULL);
    assert(fin != NULL);
    assert(inicio <= fin);

    int suma = 0;
    for (const int *p = inicio; p < fin; p++)
    {
        suma += *p;
    }
    return suma;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    // Caso normal
    assert(sumar_arreglo(arr, arr + 5) == 15);

    // Caso rango vacío (longitud 0)
    assert(sumar_arreglo(arr, arr) == 0);

    // Caso un elemento
    assert(sumar_arreglo(arr + 2, arr + 3) == 3);

    // Caso opuestos
    int opuestos[] = {10, -10, 25, -25};
    assert(sumar_arreglo(opuestos, opuestos + 4) == 0);

    // Caso subrango interno
    int sub[] = {10, 20, 30, 40};
    assert(sumar_arreglo(sub + 1, sub + 3) == 50);

    return 0;
}
```

::::
<!-- {solution} sumar_arreglo_punteros -->

---

(ej_b2_c02b_05)=
### Ejercicio 2.02b.05 - Inversión In-Place con Dos Punteros Convergentes ⭐⭐⭐☆☆

:::{exercise}
:label: invertir_arreglo_inplace
:enumerator: punteros-2

Implementá un procedimiento `void invertir_arreglo(int *arreglo, size_t n)` que
invierta el orden de los elementos de un arreglo "in-place" (con complejidad espacial $O(1)$,
sin usar memoria auxiliar ni arrays secundarios). Utilizá el patrón de dos punteros
convergentes: uno posicionado en el inicio y otro en el último elemento (`arreglo + n - 1`),
intercambiando los elementos referenciados y aproximándose hasta cruzarse.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Aritmética de punteros, paso por referencia in-place, convergencia de punteros (`inicio < fin`).  
**Techo conceptual:** Prohibido el uso de memoria dinámica (`malloc`), arreglos temporales (`int aux[n]`) o `structs`.

#### Contrato de la Función
- **Firma:** `void invertir_arreglo(int *arreglo, size_t n);`
- **Precondiciones:** `arreglo != NULL`. Si `n == 0`, no realiza acción.
- **Postcondiciones:** Para cada $0 \le i < n$, el elemento en la posición física $i$ contendrá el valor original previo en $n - 1 - i$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`arreglo`, `n`) | Estado Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal (Impar)** | `{1, 2, 3, 4, 5}`, `n = 5` | `{5, 4, 3, 2, 1}` | Arreglo de tamaño impar (el elemento central no se mueve) |
| **Normal (Par)** | `{10, 20, 30, 40}`, `n = 4` | `{40, 30, 20, 10}` | Arreglo de tamaño par (todos los elementos se intercambian) |
| **Borde (Unitario)** | `{99}`, `n = 1` | `{99}` | No altera arreglo de un solo elemento |
| **Borde (Vacío)** | `arreglo != NULL`, `n = 0` | Sin modificación | Arreglo vacío de longitud cero |
| **Normal (Negativos)**| `{-1, 0, 1}`, `n = 3` | `{1, 0, -1}` | Mantiene corrección con signos |

:::
<!-- {exercise} -->

::::{solution} invertir_arreglo_inplace
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

void invertir_arreglo(int *arreglo, size_t n)
{
    assert(arreglo != NULL);

    if (n < 2)
    {
        return;
    }

    int *inicio = arreglo;
    int *fin = arreglo + n - 1;

    while (inicio < fin)
    {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

int main(void)
{
    // Caso tamaño impar
    int imp[] = {1, 2, 3, 4, 5};
    invertir_arreglo(imp, 5);
    assert(imp[0] == 5 && imp[1] == 4 && imp[2] == 3 && imp[3] == 2 && imp[4] == 1);

    // Caso tamaño par
    int par[] = {10, 20, 30, 40};
    invertir_arreglo(par, 4);
    assert(par[0] == 40 && par[1] == 30 && par[2] == 20 && par[3] == 10);

    // Caso unitario
    int unit[] = {99};
    invertir_arreglo(unit, 1);
    assert(unit[0] == 99);

    // Caso vacío (n = 0)
    int vacio[] = {1};
    invertir_arreglo(vacio, 0);
    assert(vacio[0] == 1);

    // Caso negativos
    int neg[] = {-1, 0, 1};
    invertir_arreglo(neg, 3);
    assert(neg[0] == 1 && neg[1] == 0 && neg[2] == -1);

    return 0;
}
```

::::
<!-- {solution} invertir_arreglo_inplace -->
