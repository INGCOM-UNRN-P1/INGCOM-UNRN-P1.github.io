---
title: "Ejercicios: Análisis de Código"
short_title: "17. Análisis de Código"
---

## Acerca de

A diferencia de otros ejercicios, el objetivo aquí no es escribir código, sino
**analizarlo**. La capacidad de leer, entender y razonar sobre un código
existente es una habilidad tan importante como la de escribirlo. Estos
ejercicios están diseñados para aplicar los conceptos teóricos de los apuntes
sobre **Roles de Variables** y **Estado de un Programa**.

## 1: Identificación de Roles de Variables

### 1.1: Análisis de una Función

#### Descripción

Dado el siguiente código, identificá el "rol" principal de cada una de las
variables listadas, basándote en las definiciones del apunte `extras/roles.md`.

```c
#include <stdbool.h>

// Encuentra el promedio de los números positivos en un arreglo.
double promedio_positivos(const int arreglo[], size_t n, bool *exito) {
    double suma = 0.0;       // Variable 1
    int contador = 0;        // Variable 2
    *exito = false;          // Variable 3 (a través del puntero)

    for (size_t i = 0; i < n; i++) { // Variable 4
        if (arreglo[i] > 0) {
            suma = suma + arreglo[i];
            contador++;
        }
    }

    if (contador > 0) {
        *exito = true;
        return suma / contador; // Variable 5 (implícita)
    }

    return 0.0;
}
```

**Tarea**: Para cada una de las siguientes variables, describí su rol principal:

1.  `suma`
2.  `contador`
3.  `exito` (el valor al que apunta)
4.  `i`
5.  El valor de retorno de la función.

:::{solution} Roles 
:class: dropdown

1.  **`suma`**: **Acumulador**. Su propósito es acumular la suma de los valores
    positivos encontrados.
2.  **`contador`**: **Contador**. Su rol es contar cuántos números positivos se
    han encontrado.
3.  **`exito`**: **Bandera (Flag)**. Se utiliza para señalizar al código que
    llama a la función si la operación fue exitosa (es decir, si se encontró al
    menos un número positivo).
4.  **`i`**: **Variable de Control de Bucle (Iterador)**. Su único propósito es
    controlar las iteraciones del bucle `for`.
5.  **Valor de retorno**: **Variable de Salida**. Contiene el resultado
    principal del cálculo de la función. 
    
:::

## 2: Descripción del Estado de un Programa

### 2.1: Fotografía de la Memoria

#### Descripción

Dado el siguiente programa, describí el estado completo de la memoria (Pila y
Montículo) en el momento exacto en que la ejecución llega a la línea marcada
como `// PUNTO DE ANÁLISIS`. No es necesario indicar direcciones de memoria
exactas, pero sí la relación entre ellas.

```c
#include <stdlib.h>

char* crear_copia(const char* original) {
    int largo = 0;
    while (original[largo] != '\0') {
        largo++;
    }

    char* copia = malloc(largo + 1);

    // PUNTO DE ANÁLISIS

    for (int i = 0; i <= largo; i++) {
        copia[i] = original[i];
    }
    return copia;
}

int main() {
    char* saludo_original = "Hola";
    char* saludo_copiado = NULL;

    saludo_copiado = crear_copia(saludo_original);

    free(saludo_copiado);
    return 0;
}
```

**Tarea**: Completá la siguiente plantilla describiendo los valores de las
variables en cada marco de la pila y el estado del montículo.

- **Pila (Stack)**:
  - **Marco de `main`**:
    - `saludo_original` (puntero): ?
    - `saludo_copiado` (puntero): ?
  - **Marco de `crear_copia`**:
    - `original` (puntero): ?
    - `largo` (entero): ?
    - `copia` (puntero): ?
    - `i` (entero): ?
- **Montículo (Heap)**:
  - ?
- **Segmento de Datos (Solo Lectura)**:
  - ?

:::{solution} Estado del Programa 
:class: dropdown

- **Pila (Stack)**:
  - **Marco de `main`**:
    - `saludo_original` (puntero): Contiene la dirección de memoria de la cadena
      literal "Hola".
    - `saludo_copiado` (puntero): Su valor es `NULL` en este punto, ya que la
      asignación se produce después de que `crear_copia` retorne.
  - **Marco de `crear_copia`**:
    - `original` (puntero): Contiene una copia de la dirección de
      `saludo_original`, por lo que también apunta a la cadena literal "Hola".
    - `largo` (entero): Su valor es `4` (calculado por el bucle `while`).
    - `copia` (puntero): Contiene la dirección de memoria del nuevo bloque de 5
      bytes reservado por `malloc` en el montículo.
    - `i` (entero): Aún no ha sido inicializada, por lo que su valor es
      indeterminado (basura).
- **Montículo (Heap)**:
  - Hay un bloque de **5 bytes** reservado. Su contenido es indeterminado
    (basura), ya que el bucle `for` que lo llena aún no se ha ejecutado.
- **Segmento de Datos (Solo Lectura)**:
  - Contiene la cadena literal `"Hola"` (terminada en nulo), que ocupa 5 bytes.
    La dirección de su primer carácter es a la que apuntan `saludo_original` y
    `original`.

:::
