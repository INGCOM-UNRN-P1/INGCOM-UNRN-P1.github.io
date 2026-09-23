---
title: "Ejercicios: Punteros Avanzados y Genericidad"
short_title: "4. Punteros Avanzados"
---

# Ejercicios de Punteros Avanzados y Genericidad

## Acerca de

Estos ejercicios tienen como fin practicar el uso de la indirección múltiple
mediante punteros dobles y la abstracción mediante punteros a funciones para
implementar callbacks y genericidad en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros-funciones`

### Cuestiones de Estilo Aplicables
- **Uso de aserciones en punteros:** Validá siempre que los punteros dobles y de
  función no sean `NULL` antes de desreferenciarlos o invocarlos (ver
  {ref}`0x2008h`).
- **Definición de alias:** Empleá `typedef` para declarar firmas de punteros a
  funciones legibles en tus programas (ver reglas en {ref}`0x0101h`).

---

## Punteros Dobles (`**`)

Un puntero doble es un puntero que almacena la dirección de otro puntero. Su uso
principal es permitir que una función modifique el puntero original del código
que la llamó (simular paso por referencia para punteros).

:::{mermaid}

flowchart TD
    A["main: char *p"] -- "&p" --> B["funcion: char **pp"]
    B -- "*pp" --> A
    A -- "apunta a" --> C["Heap: Hola"]
    B -- "**pp accede a" --> C

:::
<!-- {mermaid} -->
(ejercicio_26_1)=
### Ejercicio 26.1 - Asignación de Memoria en una Función ⭐⭐☆☆☆

Escribir una función `void alocar_cadena(char **puntero_a_cadena, const char
*valor_inicial)` que reciba un puntero doble. La función debe reservar memoria
para una nueva cadena, copiar el `valor_inicial` en ella, y hacer que el puntero
original en `main` apunte a esta nueva memoria.

**Lógica y Consideraciones:**
- **Parámetro**: El puntero doble `char **puntero_a_cadena` permite modificar el
  `char *` original.
- **Proceso**:
  1. Dentro de la función, usar `malloc` para reservar la memoria necesaria.
  2. Usar `strcpy` para copiar el `valor_inicial`.
  3. Asignar la nueva dirección de memoria al puntero desreferenciado:
     `*puntero_a_cadena = nueva_cadena;`.

(ejercicio_26_2)=
### Ejercicio 26.2 - Devolución de un Arreglo de Cadenas (Tokenizer) ⭐⭐⭐☆☆

Reimplementar el ejercicio de "Tokenización" para que la función devuelva un
`char**` (un arreglo de cadenas terminado en `NULL`) alojado dinámicamente. La
función debe ser `char** dividir_cadena(const char *s, const char
*delimitador)`.

**Lógica y Consideraciones:**
- **Memoria**: La función es responsable de reservar memoria tanto para el
  arreglo de punteros (`char**`) como para cada una de las cadenas (tokens)
  individuales.
- **Liberación**: Se debe crear una función `void liberar_tokens(char **tokens)`
  que recorra el arreglo y libere cada cadena, y finalmente libere el arreglo de
  punteros.

---

## Punteros a Función

Un puntero a función almacena la dirección de memoria de una función ejecutable.
Permite pasar funciones como argumentos a otras funciones, creando código más
genérico y extensible.
(ejercicio_26_3)=
### Ejercicio 26.3 - Typedef para un Puntero a Función ⭐⭐⭐☆☆

Definir un tipo llamado `operacion_aritmetica_t` usando `typedef` que represente
un puntero a una función que toma dos enteros y devuelve un entero.

**Sintaxis:**
`typedef int (*operacion_aritmetica_t)(int, int);`
- `int (*...)`: El puntero devuelve un `int`.
- `operacion_aritmetica_t`: Es el nuevo nombre del tipo.
- `(int, int)`: El puntero apunta a una función que toma dos `int` como
  parámetros.

(ejercicio_26_4)=
### Ejercicio 26.4 - Función de Orden Superior (Calculadora) ⭐⭐☆☆☆

Escribir una función `int calculadora(int a, int b, operacion_aritmetica_t
operacion)` que reciba dos números y un puntero a una función de operación. La
función `calculadora` debe invocar la función pasada como argumento y devolver
su resultado.

**Lógica y Consideraciones:**
- **Invocación**: Dentro de `calculadora`, se llama a la función a través del
  puntero: `return operacion(a, b);`.
- **Uso**: En `main`, se pueden definir funciones `sumar(int, int)` y
  `restar(int, int)` y pasarlas a `calculadora`.
  - `calculadora(10, 5, sumar);` // Devuelve 15
  - `calculadora(10, 5, restar);` // Devuelve 5

(ejercicio_26_5)=
### Ejercicio 26.5 - Tabla de Despacho (Dispatch Table) ⭐⭐☆☆☆

Crear una "tabla de despacho" para la calculadora. Esto consiste en un arreglo
de punteros a función. El programa debe permitir al usuario elegir una operación
(ej. 0 para sumar, 1 para restar) y usar ese índice para llamar a la función
correcta desde el arreglo.

**Lógica y Consideraciones:**
- **Arreglo**: `operacion_aritmetica_t operaciones[] = {sumar, restar,
  multiplicar, dividir};`
- **Llamada**: `int resultado = operaciones[opcion](a, b);`
- **Ventaja**: Reemplaza una estructura `switch` o `if-else` larga por una
  simple indexación de arreglo, lo que hace el código más compacto y extensible.

