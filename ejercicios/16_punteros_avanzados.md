---
title: "Ejercicios: Punteros Avanzados"
short_title: "16. Punteros Avanzados"
---

## Acerca de

Estos ejercicios exploran dos conceptos más avanzados relacionados con los punteros en C: los **punteros dobles (`**`)** y los **punteros a función**. Dominar estos temas permite un manejo de memoria más sofisticado y la creación de código más genérico y flexible.

## 1: Punteros Dobles (`**`)

Un puntero doble es un puntero que almacena la dirección de otro puntero. Su uso principal es permitir que una función modifique el puntero original del código que la llamó (simular paso por referencia para punteros).

```{mermaid}
graph TD
    A(main: char *p) -- &p --> B(funcion: char **pp);
    B -- *pp --> A;
    A -- "apunta a" --> C[Heap: "Hola"];
    B -- "**pp accede a" --> C
```

### 1.1: Asignación de Memoria en una Función

#### Descripción
Escribir una función `void alocar_cadena(char **puntero_a_cadena, const char *valor_inicial)` que reciba un puntero doble. La función debe reservar memoria para una nueva cadena, copiar el `valor_inicial` en ella, y hacer que el puntero original en `main` apunte a esta nueva memoria.

:::{hint} Lógica y Consideraciones
- **Parámetro**: El puntero doble `char **puntero_a_cadena` permite modificar el `char *` original.
- **Proceso**:
  1. Dentro de la función, usar `malloc` para reservar la memoria necesaria.
  2. Usar `strcpy` para copiar el `valor_inicial`.
  3. Asignar la nueva dirección de memoria al puntero desreferenciado: `*puntero_a_cadena = nueva_cadena;`.
:::

### 1.2: Devolución de un Arreglo de Cadenas (Tokenizer)

#### Descripción
Reimplementar el ejercicio de "Tokenización" para que la función devuelva un `char**` (un arreglo de cadenas terminado en `NULL`) alojado dinámicamente. La función debe ser `char** dividir_cadena(const char *s, const char *delimitador)`. 

:::{hint} Lógica y Consideraciones
- **Memoria**: La función es responsable de reservar memoria tanto para el arreglo de punteros (`char**`) como para cada una de las cadenas (tokens) individuales.
- **Liberación**: Se debe crear una función `void liberar_tokens(char **tokens)` que recorra el arreglo y libere cada cadena, y finalmente libere el arreglo de punteros.
:::

## 2: Punteros a Función

Un puntero a función almacena la dirección de memoria de una función ejecutable. Permite pasar funciones como argumentos a otras funciones, creando código más genérico y extensible.

### 2.1: `typedef` para un Puntero a Función

#### Descripción
Definir un tipo llamado `operacion_aritmetica_t` usando `typedef` que represente un puntero a una función que toma dos enteros y devuelve un entero.

:::{hint} Sintaxis
`typedef int (*operacion_aritmetica_t)(int, int);`
- `int (*...)`: El puntero devuelve un `int`.
- `operacion_aritmetica_t`: Es el nuevo nombre del tipo.
- `(int, int)`: El puntero apunta a una función que toma dos `int` como parámetros.
:::

### 2.2: Función de Orden Superior (Calculadora)

#### Descripción
Escribir una función `int calculadora(int a, int b, operacion_aritmetica_t operacion)` que reciba dos números y un puntero a una función de operación. La función `calculadora` debe invocar la función pasada como argumento y devolver su resultado.

:::{hint} Lógica y Consideraciones
- **Invocación**: Dentro de `calculadora`, se llama a la función a través del puntero: `return operacion(a, b);`.
- **Uso**: En `main`, se pueden definir funciones `sumar(int, int)` y `restar(int, int)` y pasarlas a `calculadora`.
  - `calculadora(10, 5, sumar);` // Devuelve 15
  - `calculadora(10, 5, restar);` // Devuelve 5
:::

### 2.3: Tabla de Despacho (Dispatch Table)

#### Descripción
Crear una "tabla de despacho" para la calculadora. Esto consiste en un arreglo de punteros a función. El programa debe permitir al usuario elegir una operación (ej. 0 para sumar, 1 para restar) y usar ese índice para llamar a la función correcta desde el arreglo.

:::{hint} Lógica y Consideraciones
- **Arreglo**: `operacion_aritmetica_t operaciones[] = {sumar, restar, multiplicar, dividir};`
- **Llamada**: `int resultado = operaciones[opcion](a, b);`
- **Ventaja**: Reemplaza una estructura `switch` o `if-else` larga por una simple indexación de arreglo, lo que hace el código más compacto y extensible.
:::