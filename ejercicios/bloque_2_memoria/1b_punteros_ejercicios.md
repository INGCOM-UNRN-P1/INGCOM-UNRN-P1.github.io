---
title: Ejercicios de Punteros II
short_title: 4b. Punteros II
---

# Ejercicios de Punteros II

## Acerca de

Estos ejercicios prácticos y aplicados complementan la teoría de punteros y
aritmética básica de indirección de memoria en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros`

### Cuestiones de Estilo Aplicables
- **Uso de aserciones:** Es mandatorio validar mediante `assert` de la cabecera
  `<assert.h>` que los punteros recibidos por parámetros en las funciones no
  sean `NULL` (ver {ref}`0x2009h`).
- **Aritmética de punteros:** Recorré los arreglos operando de manera directa
  sobre los punteros de control y evitando índices lógicos temporales,
  incrementando o decrementando las direcciones físicas de memoria de forma
  explícita.

---
(ejercicio_9_1)=
## Ejercicio 9.1 - s ⭐⭐☆☆☆

(ejercicio_9_2)=
### Ejercicio 9.2 - b.1 - Intercambiar valores ⭐⭐☆☆☆

:::{exercise}
:label: intercambiar_valores
:enumerator: punteros-1

Implementá un procedimiento `void intercambiar(int *a, int *b)` que reciba dos
punteros a enteros. La función debe intercambiar los valores de las variables
originales a las que apuntan estos punteros.

:::
<!-- {exercise} -->

::::{solution} intercambiar_valores
:class: dropdown

:::{code-block}c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void intercambiar(int *a, int *b) {
  assert(a != NULL);
  assert(b != NULL);
  int temporal = *a; // Guardamos el valor al que apunta 'a'
  *a = *b;           // Asignamos al lugar de 'a' el valor al que apunta 'b'
  *b = temporal;     // Asignamos al lugar de 'b' el valor guardado
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} intercambiar_valores -->
(ejercicio_9_3)=
### Ejercicio 9.3 - b.2 - Encontrar máximo ⭐⭐☆☆☆

:::{exercise}
:label: encontrar_maximo
:enumerator: funciones-1

Escribí una función `int encontrar_maximo(const int *arreglo, size_t n)` que
reciba un puntero al inicio de un arreglo de enteros (marcado como `const` para
no modificarlo) y su tamaño. La función debe recorrer el arreglo usando el
puntero y devolver el valor del elemento más grande.

:::
<!-- {exercise} -->

::::{solution} encontrar_maximo
:class: dropdown

:::{code-block}c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int encontrar_maximo(const int *arreglo, size_t n) {
  assert(arreglo != NULL);
  if (n == 0) {
    return 0; // O un valor de error apropiado
  }

  int maximo = *arreglo; // Suponemos que el primer elemento es el máximo

  // Avanzamos el puntero por el resto del arreglo
  for (size_t i = 1; i < n; i++) {
    // Usamos aritmética de punteros para acceder al siguiente elemento
    if (*(arreglo + i) > maximo) {
      maximo = *(arreglo + i);
    }
  }
  return maximo;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} encontrar_maximo -->
(ejercicio_9_4)=
### Ejercicio 9.4 - b.3 - Copiar cadena ⭐⭐⭐☆☆

:::{exercise}
:label: copiar_cadena
:enumerator: funciones-2

Implementá un procedimiento `void copiar_cadena(char *destino, const char
*origen)`. La función debe copiar la cadena de caracteres de `origen` a
`destino`, incluyendo el carácter nulo final (`\0`). Debés resolverlo
recorriendo las cadenas exclusivamente con punteros.

:::
<!-- {exercise} -->

::::{solution} copiar_cadena
:class: dropdown

:::{code-block}c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void copiar_cadena(char *destino, const char *origen) {
  assert(destino != NULL);
  assert(origen != NULL);
  // Mientras el valor al que apunta 'origen' no sea el carácter nulo...
  while (*origen != '\0') {
    *destino = *origen; // Copiamos el valor
    origen++;           // Avanzamos el puntero de origen
    destino++;          // Avanzamos el puntero de destino
  }
  *destino = '\0'; // Aseguramos que la cadena destino termine con el nulo
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} copiar_cadena -->
(ejercicio_9_5)=
### Ejercicio 9.5 - b.4 - Sumar arreglo con punteros ⭐⭐⭐☆☆

:::{exercise}
:label: sumar_arreglo_punteros
:enumerator: funciones-3

Creá una función `int sumar_arreglo(const int *inicio, const int *fin)` que
reciba un puntero al primer elemento de un arreglo y un puntero a la dirección
de memoria inmediatamente posterior al último elemento. La función debe sumar
los elementos del arreglo iterando con un puntero desde `inicio` hasta que
alcance a `fin`.

:::
<!-- {exercise} -->

::::{solution} sumar_arreglo_punteros
:class: dropdown

:::{code-block}c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int sumar_arreglo(const int *inicio, const int *fin) {
  assert(inicio != NULL);
  assert(fin != NULL);
  int suma = 0;
  // Iteramos mientras el puntero 'p' no haya llegado al puntero 'fin'
  for (const int *p = inicio; p < fin; p++) {
    suma += *p; // Sumamos el valor al que apunta 'p'
  }
  return suma;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} sumar_arreglo_punteros -->
(ejercicio_9_6)=
### Ejercicio 9.6 - b.5 - Invertir arreglo in-place ⭐⭐⭐☆☆

:::{exercise}
:label: invertir_arreglo_inplace
:enumerator: punteros-2

Implementá un procedimiento `void invertir_arreglo(int *arreglo, size_t n)` que
invierta el orden de los elementos de un arreglo "in-place" (sin usar un arreglo
auxiliar). Utilizá dos punteros: uno que apunte al inicio del arreglo y otro que
apunte al final. Intercambiá los valores a los que apuntan y mové los punteros
hacia el centro hasta que se crucen.

:::
<!-- {exercise} -->

::::{solution} invertir_arreglo_inplace
:class: dropdown

:::{code-block}c
:linenos:
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void invertir_arreglo(int *arreglo, size_t n) {
  assert(arreglo != NULL);
  if (n < 2) {
    return; // No hay nada que invertir
  }
  int *inicio = arreglo;
  int *fin = arreglo + n - 1;

  while (inicio < fin) {
    // Intercambiamos los valores
    int temp = *inicio;
    *inicio = *fin;
    *fin = temp;

    // Movemos los punteros hacia el centro
    inicio++;
    fin--;
  }
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} invertir_arreglo_inplace -->
