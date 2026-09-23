---
title: "Ejercicios de Punteros"
short_title: "2. Punteros"
subtitle: "Dirección de memoria, indirección, pasaje por referencia y punteros constantes"
---

# Ejercicios de Punteros

## Acerca de

Estos ejercicios están diseñados para afianzar el uso de punteros a tipos escalares,
la obtención de direcciones con el operador `&`, la desreferencia con `*`, el pasaje
de parámetros por referencia para simular múltiples retornos, y el uso correcto de
calificadores `const`.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros` (Bloque 2, Capítulo 2)

### Cuestiones de Estilo Aplicables
- **Inicialización de punteros:** Todo puntero que no apunte a un objeto en
  memoria válido debe inicializarse en `NULL` (ver regla de estilo
  {ref}`0x7001h`).
- **Verificación de punteros:** Antes de realizar cualquier desreferencia con
  el operador `*`, es obligatorio verificar que el puntero no sea `NULL`.
- **Punteros a tipos escalares:** En este capítulo solo se manipulan punteros a tipos
  primitivos (`int*`, `double*`, `char*`). No se permite el uso de estructuras (`struct`),
  memoria dinámica (`malloc`/`free`) ni punteros a funciones, los cuales se estudian
  en capítulos posteriores.

---

## Direcciones y Pasaje por Referencia

(ej_b2_c02_01)=
### Ejercicio 2.02.01 - Duplicar Valor por Referencia ⭐⭐☆☆☆

Implementar la función `void duplicar(int *numero)` que modifique el valor de la
variable apuntada duplicando su contenido.

(ej_b2_c02_02)=
### Ejercicio 2.02.02 - División Entera con Retorno Múltiple ⭐⭐☆☆☆

Implementar `int division_lenta(int dividendo, int divisor, int *cociente, int *resto)`.
La función debe validar que `cociente` y `resto` no sean `NULL`, y que `divisor != 0`.
Los resultados se retornan escribiendo en las direcciones apuntadas. La función
retorna `0` en caso de éxito, `-1` si el divisor es cero, y `-2` si alguno de los punteros
de salida es `NULL`.

(ej_b2_c02_03)=
### Ejercicio 2.02.03 - Intercambio de Variables ⭐⭐☆☆☆

Implementar `void intercambiar(int *a, int *b)` que intercambie el contenido de dos
variables enteras utilizando desreferenciación y una variable auxiliar temporal.
Verificar que ambos punteros sean válidos antes de operar.

(ej_b2_c02_04)=
### Ejercicio 2.02.04 - Puntero al Mayor de Dos Números ⭐⭐☆☆☆

Implementar `int *obtener_mayor(int *a, int *b)` que compare los valores de dos enteros
recibidos por puntero y retorne la dirección de memoria (`int*`) de la variable que contenga
el valor mayor. Si son iguales, puede retornar cualquiera de los dos.

---

## Punteros a Punteros Escalares (Sin Memoria Dinámica)

(ej_b2_c02_05)=
### Ejercicio 2.02.05 - Selección de Puntero mediante Indirección Doble ⭐⭐⭐☆☆

Implementar `void seleccionar_puntero(const int *a, const int *b, const int **resultado)`
que evalúe los valores apuntados por `a` y `b`, y asigne a `*resultado` la dirección del mayor.
Este ejercicio ejercita la modificación de un puntero en la función llamadora mediante un
puntero doble (`const int **`), sin recurrir a memoria dinámica.

(ej_b2_c02_06)=
### Ejercicio 2.02.06 - Resetear Puntero Escalar ⭐⭐☆☆☆

Implementar `void anular_puntero(int **ptr)` que verifique si `ptr != NULL` y establezca
`*ptr = NULL`, garantizando que la variable puntero en el llamador quede explícitamente
desconectada.

---

## Punteros Constantes y Cualificadores

(ej_b2_c02_07)=
### Ejercicio 2.02.07 - Puntero a Constante vs Puntero Constante ⭐⭐⭐☆☆

Explicar y ejemplificar en código la semántica de:
1. `const int *p`: puntero a entero constante (el valor no puede modificarse vía `*p`).
2. `int * const p`: puntero constante a entero (la dirección en `p` no puede reasignarse).
3. `const int * const p`: puntero constante a entero constante.

Implementar tres funciones que demuestren qué operaciones compilan y cuáles son rechazadas
por el compilador en cada variante.

(ej_b2_c02_08)=
### Ejercicio 2.02.08 - Lectura Segura con Puntero de Solo Lectura ⭐⭐☆☆☆

Implementar `int acceso_seguro(const int *ptr, int *salida)` que verifique si `ptr` y `salida`
no son `NULL`. Si son válidos, copia el valor de `*ptr` en `*salida` y retorna `0`. Si alguno
es `NULL`, retorna `-1`. El parámetro `ptr` debe ser de solo lectura (`const int *`).

---

## Inicialización y Detección de Errores

(ej_b2_c02_09)=
### Ejercicio 2.02.09 - Inicialización Segura y Detección de Basura ⭐☆☆☆☆

Demostrar experimentalmente el comportamiento de desreferenciar un puntero no inicializado
frente a uno inicializado en `NULL`. Escribir un programa de demostración con captura defensiva
`if (ptr == NULL)` antes de cualquier acceso.
