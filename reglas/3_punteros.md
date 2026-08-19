---
title: Punteros y Gestión de Memoria
short_title: Punteros y Memoria
subtitle: Reglas de estilo para el uso seguro de punteros y memoria dinámica en C
---

(0x30XXh)=
# Punteros y Gestión de Memoria (`0x30XX`)

(0x3001h)=
## Regla `0x3001h`: Siempre verificá la asignación exitosa de memoria dinámica

Toda asignación de memoria dinámica realizada con `malloc`, `calloc` o `realloc`
debe ser seguida inmediatamente por una comprobación contra `NULL` antes de su
uso.

``` c
ptr = malloc(sizeof(*ptr));
if (ptr == NULL)
{
    // Manejo de error de memoria insuficiente
}
```
<!-- c -->

(0x3002h)=
## Regla `0x3002h`: Liberá siempre la memoria dinámica y asigná `NULL` al puntero para evitar punteros colgantes

Por cada asignación de memoria dinámica debe existir una correspondiente
liberación con `free()`. Inmediatamente después de liberar la memoria, asigná
`NULL` al puntero para prevenir fallos por acceso a punteros colgantes
(*dangling pointers*).

``` c
free(ptr);
ptr = NULL;
```
<!-- c -->

### Simetría en la liberación de recursos

La liberación de memoria debe realizarse al mismo nivel de abstracción que su
asignación. Si se encapsula la creación de una estructura con una función
`crear_recurso`, se debe proveer una función `liberar_recurso` correspondiente.

```{code-block} c
:linenos:
recurso_t *crear_recurso()
{
    recurso_t *r = malloc(sizeof(*r));
    return r;
}
void liberar_recurso(recurso_t *r)
{
    free(r);
}
```
<!-- {code-block} c -->

(0x3003h)=
## Regla `0x3003h`: No mezcles operaciones de asignación y comparación en una sola línea

Mantener las asignaciones y comparaciones en líneas separadas previene errores
lógicos sutiles y facilita el rastreo de excepciones.

``` diff
- if ((ptr = malloc(tamaño)) == NULL)
- {
+ ptr = malloc(tamaño);
+ if (ptr == NULL)
+ {
```
<!-- diff -->

(0x3004h)=
## Regla `0x3004h`: Utilizá `typedef` para definir tipos de estructuras con el sufijo `_t`

Esto simplifica el manejo sintáctico del código en C. Los alias de tipo creados
con `typedef` deben terminar obligatoriamente con el sufijo `_t`.

- **Incorrecto:**
  ```c
  struct mi_estructura var;
  ```
- **Correcto:**
  ```c
  typedef struct
  {
      int campo1;
  } mi_estructura_t;
  mi_estructura_t var;
  ```

(0x3005h)=
## Regla `0x3005h`: Minimizá el uso de múltiples niveles de indirección (punteros a punteros)

Los punteros a punteros (`**`) o de niveles superiores de indirección complican
la lectura y el razonamiento sobre la memoria. Deben evitarse siempre que no
sean estrictamente requeridos.

- **Incorrecto:**
  ```c
  void obtener_datos(int **ptr_datos, size_t *tamano)
  { /* ... */
  }
  ```
- **Correcto:**
  ```c
  int *obtener_datos(size_t *tamano_out)
  { /* ... */
  }
  ```

(0x3006h)=
## Regla `0x3006h`: Documentá la propiedad de los recursos al utilizar punteros

Cuando una función recibe o devuelve un puntero a memoria dinámica, la
documentación de la función debe especificar explícitamente cuál es el módulo
responsable de liberar dicha memoria (el dueño del recurso).

```{code-block} c
:linenos:
/**
 * Crea un nuevo recurso.
 * @returns Un puntero al nuevo recurso. El llamador es dueño y responsable
 *          de liberar esta memoria mediante liberar_recurso().
 */
recurso_t *crear_recurso();
```
<!-- {code-block} c -->

(0x3007h)=
## Regla `0x3007h`: Los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique

Usar `const` en los parámetros de tipo puntero establece un contrato de solo
lectura, previniendo efectos secundarios no deseados sobre los datos de origen.

``` c
// Correcto: La función lee el dato apuntado pero garantiza no modificarlo.
void imprimir_saludo(const char *nombre)
{
    printf("Hola, %s!\n", nombre);
}
```
<!-- c -->

(0x3008h)=
## Regla `0x3008h`: Los punteros nulos deben ser inicializados y comparados con `NULL`, no con `0`

La macro `NULL` debe utilizarse para mantener la coherencia semántica en
operaciones con punteros.

- **Incorrecto:**
  ```c
  int *ptr = 0;
  if (ptr == 0)
  { /* ... */
  }
  ```
- **Correcto:**
  ```c
  int *ptr = NULL;
  if (ptr == NULL)
  { /* ... */
  }
  ```

(0x3009h)=
## Regla `0x3009h`: Documentá explícitamente los casos en que una función puede retornar `NULL`

Si una función que devuelve un puntero puede fallar y retornar `NULL`, este
escenario debe ser explícito en la documentación de retorno de la función.

``` c
/**
 * Busca un elemento en la estructura.
 * @returns Un puntero al elemento si se encuentra, o NULL si no existe.
 */
elemento_t *buscar_elemento(int id);
```
<!-- c -->

(0x300Ah)=
## Regla `0x300Ah`: Utilizá `cast` explícito al convertir tipos de punteros

Las conversiones de tipos de punteros deben ser siempre explícitas en el código
fuente para mejorar la claridad de conversión de tipos de datos.

``` c
void *mem = malloc(sizeof(int));
if (mem != NULL)
{
    int *ptr = (int *)mem; // Cast explícito
}
```
<!-- c -->

(0x300Bh)=
## Regla `0x300Bh`: Usá siempre `sizeof` en las asignaciones de memoria dinámica, prefiriendo `sizeof(*ptr)`

El uso de `sizeof` dinámico en asignación reduce errores ante cambios de tipos
en refactorizaciones de variables.

- **Incorrecto:**
  ```c
  int *ptr = malloc(4);
  ```
- **Correcto:**
  ```c
  int *ptr = malloc(sizeof(*ptr));
  ```

(0x300Ch)=
## Regla `0x300Ch`: Verificá siempre los límites de los arreglos antes de acceder a sus elementos

El acceso fuera de límites de un arreglo (`out-of-bounds`) es un error grave.
Los índices deben ser explícitamente validados antes de acceder a un elemento.

``` c
int arreglo[10];
int indice = 9;
if (indice >= 0 && indice < 10)
{
    arreglo[indice] = 5;
}
```
<!-- c -->

(0x300Dh)=
## Regla `0x300Dh`: Utilizá `enum` en lugar de "números mágicos" para conjuntos de estados y valores constantes

Las enumeraciones explican la semántica de un conjunto de constantes enteras
relacionadas.

- **Incorrecto (uso de enteros crudos):**
  ```c
  void procesar_estado(int estado)
  {
      if (estado == 0)
      { /* ... */
      }
  }
  ```
- **Correcto:**
  ```c
  typedef enum
  {
      ESTADO_INACTIVO,
      ESTADO_ACTIVO
  } estado_t;
  void procesar_estado(estado_t estado)
  {
      if (estado == ESTADO_ACTIVO)
      { /* ... */
      }
  }
  ```

(0x300Eh)=
## Regla `0x300Eh`: Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos

Si una función acepta que sus argumentos punteros sean `NULL`, se debe indicar
el comportamiento esperado. Si no los acepta, se debe documentar como una
precondición explícita.

```{code-block} c
:linenos:
/**
 * Procesa la información.
 * @param datos Puntero a los datos. No debe ser NULL.
 * @pre datos != NULL
 */
void procesar_datos(const datos_t *datos);
```
<!-- {code-block} c -->

(0x300Fh)=
## Regla `0x300Fh`: Liberá la memoria en el orden inverso a su asignación

Esto es crítico en estructuras de datos anidadas, como matrices dinámicas 2D o
listas enlazadas, para evitar dejar memoria inaccesible en el heap.

``` c
for (size_t i = 0; i < filas; i++)
{
    free(matriz[i]); // Libera las subasignaciones primero
}
free(matriz); // Libera el contenedor principal
matriz = NULL;
```
<!-- c -->

(0x3010h)=
## Regla `0x3010h`: Las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`

`size_t` es un tipo entero sin signo que garantiza portabilidad para contener el
tamaño máximo posible de un objeto en memoria.

- **Incorrecto:**
  ```c
  void imprimir_arreglo(const int arreglo[], int tamano);
  ```
- **Correcto:**
  ```c
  void imprimir_arreglo(const int arreglo[], size_t tamano)
  {
      for (size_t i = 0; i < tamano; i++)
      {
          printf("%d ", arreglo[i]);
      }
  }
  ```

(0x3011h)=
## Regla `0x3011h`: Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar `const void*`

Si una función recibe un puntero genérico `void*` y no modifica el contenido de
la memoria apuntada, se **debe** declarar obligatoriamente el parámetro como
`const void*`. Se prohíbe pasar `void*` sin calificador `const` si la operación
es de solo lectura.

- **Incorrecto:**
``` c
void imprimir_bytes(void *datos, size_t tamano)
{
    unsigned char *ptr = (unsigned char *)datos; // Firma insegura
    // ...
}
```
<!-- c -->

- **Correcto:**
```{code-block} c
:linenos:
void imprimir_bytes(const void *datos, size_t tamano)
{
    const unsigned char *ptr = (const unsigned char *)datos;
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%02x ", ptr[i]);
    }
}
```
<!-- {code-block} c -->

(0x0035h)=
## Regla `0x0035h`: Diseñá los Tipos de Datos Abstractos utilizando punteros opacos

Los Tipos de Datos Abstractos (TAD) deben diseñarse ocultando su representación
física de datos mediante punteros opacos. La cabecera pública `.h` solo debe
exponer la declaración del tipo incompleto y las firmas de sus funciones de
interfaz. Toda la estructura interna y los detalles de implementación deben
definirse en el archivo `.c` correspondiente.

- **Cabecera Correcta (`usuario.h`):**
``` c
typedef struct usuario usuario_t;
usuario_t *crear_usuario(const char *nombre, int edad);
void destruir_usuario(usuario_t *u);
```
<!-- c -->

- **Implementación Correcta (`usuario.c`):**
``` c
struct usuario
{
    char *nombre;
    int edad;
};
```
<!-- c -->

(0x0036h)=
## Regla `0x0036h`: Asigná `NULL` al puntero tras liberar un recurso opaco en el ámbito del cliente

Al destruir o liberar una instancia de un tipo opaco mediante su función
destructora, es mandatorio asignar `NULL` al puntero correspondiente en el
código del cliente para evitar el uso accidental de punteros colgantes o
referencias inválidas.

- **Incorrecto:**
``` c
usuario_t *u = crear_usuario("Carlos", 30);
// ...
destruir_usuario(u);
usuario_imprimir(u); // ¡Puntero colgante y comportamiento indefinido!
```
<!-- c -->

- **Correcto:**
``` c
usuario_t *u = crear_usuario("Carlos", 30);
// ...
destruir_usuario(u);
u = NULL; // Evita uso accidental
```
<!-- c -->

