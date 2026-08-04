---
title: Ejercicios de Punteros
short_title: 4. Punteros
---

# Ejercicios de Punteros

## Acerca de

Estos ejercicios están diseñados para afianzar el uso de punteros, la aritmética
de punteros, la indirección múltiple y el paso de variables por referencia
simulado en el lenguaje C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros`

### Cuestiones de Estilo Aplicables
- **Inicialización de punteros:** Todo puntero que no apunte a un objeto en
  memoria válido debe inicializarse en `NULL` (ver regla de estilo
  {ref}`0x0003h`).
- **Verificación de punteros:** Antes de realizar cualquier desreferencia con
  los operadores `*` o `->`, es obligatorio verificar que el puntero no sea
  `NULL`.

---

## Referencias y Aritmética
(ejercicio_8_1)=
### Ejercicio 8.1 - Duplicar valor ⭐⭐☆☆☆

Implementar `void duplicar(int *numero)` que modifique el valor de la variable
original.
(ejercicio_8_2)=
### Ejercicio 8.2 - División Lenta II ⭐⭐☆☆☆

Implementar `int division_lenta(int dividendo, int divisor, int *cociente, int
*resto)`. Los resultados se devuelven modificando las variables a las que
apuntan `cociente` y `resto`.

Utilicen el retorno para indicar si la división fue correcta o no.
(ejercicio_8_3)=
### Ejercicio 8.3 - Estadísticas de Arreglo ⭐⭐⭐☆☆

Implementar `void estadisticas(int arr[], size_t n, int *min, int *max, double
*prom)`.
(ejercicio_8_4)=
### Ejercicio 8.4 - Largo seguro con punteros ⭐⭐⭐☆☆

Implementar `size_t largo_seguro(const char *str, size_t capacidad)`.

**Lógica**: Inicializar un puntero `const char *fin = str;`. Iterar con `while
(*fin != '\0' && (size_t)(fin - str) < capacidad) { fin++; }`. El largo es `fin
- str`.

---

## Manipulación con Punteros
(ejercicio_8_5)=
### Ejercicio 8.5 - Ordenamiento con intercambia ⭐⭐☆☆☆

Implementar un algoritmo de ordenamiento (ej. Burbuja) que para intercambiar
elementos llame a `void intercambia(int *a, int *b)`.
(ejercicio_8_6)=
### Ejercicio 8.6 - Búsqueda de subcadena ⭐⭐⭐☆☆

Implementar `char* busqueda(const char *cadena, const char *buscado)`. Se debe
retornar un puntero al inicio de la primera ocurrencia de `buscado` dentro de
`cadena`, o `NULL`.
(ejercicio_8_7)=
### Ejercicio 8.7 - Inversión de arreglo ⭐⭐⭐☆☆

Implementar `void invertir(int *inicio, int *fin)`. Se intercambia `*inicio` con
`*fin` y se avanza `inicio` y retrocede `fin` hasta que se crucen.

---

## Punteros a Punteros
(ejercicio_8_8)=
### Ejercicio 8.8 - Modificar Puntero ⭐⭐⭐☆☆

Implementar `void asignar_memoria(int **ptr, int valor)` que reserve memoria
para un entero, le asigne el `valor` y modifique el puntero original para que
apunte a esa memoria.

**Uso esperado:**
``` c
int *p = NULL;
asignar_memoria(&p, 42);
// Ahora *p contiene 42
```
<!-- c -->
(ejercicio_8_9)=
### Ejercicio 8.9 - Matriz como Puntero a Puntero ⭐⭐⭐☆☆

Implementar `int** crear_matriz(int filas, int columnas)` que reserve memoria
para una matriz dinámica usando un puntero a punteros. Cada fila debe ser un
arreglo independiente.

**Recordatorio:** También implementar `void liberar_matriz(int **matriz, int
filas)`.
(ejercicio_8_10)=
### Ejercicio 8.10 - Arreglo de Cadenas ⭐⭐⭐☆☆

Implementar `void ordenar_cadenas(char **cadenas, int n)` que ordene un arreglo
de punteros a cadenas lexicográficamente usando `strcmp`.

**Ejemplo:**
``` c
char *palabras[] = {"hola", "adios", "casa", "barco"};
ordenar_cadenas(palabras, 4);
// Resultado: {"adios", "barco", "casa", "hola"}
```
<!-- c -->

---

## Aritmética de Punteros Avanzada
(ejercicio_8_11)=
### Ejercicio 8.11 - Recorrido con Punteros ⭐⭐⭐☆☆

Implementar `int suma_arreglo_ptr(int *inicio, int *fin)` que sume todos los
elementos entre `inicio` (inclusive) y `fin` (exclusive) usando solo aritmética
de punteros, sin índices.

**Restricción:** No usar `[]`, solo `*`, `++`, `--`.
(ejercicio_8_12)=
### Ejercicio 8.12 - Copiar Arreglos ⭐⭐⭐☆☆

Implementar `void copiar(int *destino, const int *origen, size_t n)` que copie
`n` elementos de `origen` a `destino` usando solo punteros.

**Estrategia:** `while (n--) { *destino++ = *origen++; }`
(ejercicio_8_13)=
### Ejercicio 8.13 - Buscar Elemento ⭐⭐☆☆☆

Implementar `int* buscar_elemento(int *inicio, int *fin, int valor)` que retorne
un puntero al primer elemento igual a `valor`, o `NULL` si no se encuentra.
(ejercicio_8_14)=
### Ejercicio 8.14 - Distancia entre Punteros ⭐⭐⭐☆☆

Implementar `size_t distancia(const int *p1, const int *p2)` que calcule cuántos
elementos hay entre dos punteros del mismo arreglo.

**Recordatorio:** La diferencia entre punteros del mismo arreglo da el número de
elementos entre ellos.

---

## Punteros Constantes
(ejercicio_8_15)=
### Ejercicio 8.15 - Puntero a Constante vs Puntero Constante ⭐⭐⭐☆☆

Explicar y ejemplificar la diferencia entre:
- `const int *p` - puntero a entero constante (no se puede modificar `*p`)
- `int * const p` - puntero constante a entero (no se puede modificar `p`)
- `const int * const p` - puntero constante a entero constante

Implementar funciones que demuestren cada caso.
(ejercicio_8_16)=
### Ejercicio 8.16 - Función con Parámetros Constantes ⭐⭐☆☆☆

Implementar `int maximo_arreglo(const int *arr, size_t n)` que encuentre el
máximo sin modificar el arreglo original.

**Ventaja:** El `const` documenta que la función no modifica el arreglo y
permite que el compilador detecte modificaciones accidentales.
(ejercicio_8_17)=
### Ejercicio 8.17 - Cadenas de Solo Lectura ⭐⭐⭐☆☆

Implementar `size_t contar_vocales(const char *str)` que cuente vocales sin
modificar la cadena.

---

## Punteros y Estructuras
(ejercicio_8_18)=
### Ejercicio 8.18 - Acceso a Miembros ⭐⭐☆☆☆

Dada una estructura:
``` c
typedef struct {
    int x;
    int y;
} punto_t;
```
<!-- c -->

Implementar `void trasladar(punto_t *p, int dx, int dy)` que modifique las
coordenadas del punto sumando `dx` y `dy`.

**Notación:** Usar el operador `->` para acceder a miembros: `p->x += dx;`
(ejercicio_8_19)=
### Ejercicio 8.19 - Arreglo de Estructuras ⭐⭐⭐☆☆

Implementar `void ordenar_puntos_por_x(punto_t *puntos, int n)` que ordene un
arreglo de puntos según su coordenada `x`.
(ejercicio_8_20)=
### Ejercicio 8.20 - Estructura con Punteros ⭐⭐⭐☆☆

Dada:
``` c
typedef struct {
    char *nombre;
    int edad;
} persona_t;
```
<!-- c -->

Implementar `void crear_persona(persona_t *p, const char *nombre, int edad)` que
inicialice la estructura, reservando memoria para el nombre con `strdup` o
`malloc` + `strcpy`.

**Importante:** También implementar `void liberar_persona(persona_t *p)` que
libere la memoria del nombre.

---

## Punteros a Funciones
(ejercicio_8_21)=
### Ejercicio 8.21 - Callback Simple ⭐☆☆☆☆

Implementar `void aplicar(int *arr, size_t n, void (*func)(int *))` que aplique
una función a cada elemento del arreglo.

**Ejemplo de uso:**
``` c
void duplicar_elemento(int *x) { *x *= 2; }

int arr[] = {1, 2, 3, 4, 5};
aplicar(arr, 5, duplicar_elemento);
// arr ahora es {2, 4, 6, 8, 10}
```
<!-- c -->
(ejercicio_8_22)=
### Ejercicio 8.22 - Ordenamiento Genérico ⭐⭐☆☆☆

Implementar `void ordenar_generico(void *arr, size_t n, size_t tam_elemento, int
(*comparar)(const void*, const void*))` que ordene un arreglo de cualquier tipo
usando una función de comparación personalizada.

**Pista:** Similar a `qsort` de la biblioteca estándar. Usar `memcpy` para
intercambiar elementos.
(ejercicio_8_23)=
### Ejercicio 8.23 - Tabla de Funciones ⭐⭐☆☆☆

Crear un arreglo de punteros a funciones para una calculadora:
```{code-block} c
:linenos:
typedef double (*operacion_t)(double, double);

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

operacion_t operaciones[] = {sumar, restar, multiplicar, dividir};

```
<!-- {code-block} c -->

Implementar un menú que permita seleccionar y ejecutar operaciones usando este
arreglo.

---

## Punteros Nulos y Validación
(ejercicio_8_24)=
### Ejercicio 8.24 - Validación de Punteros ⭐⭐⭐☆☆

Implementar `int acceso_seguro(int *ptr, int *resultado)` que verifique si `ptr`
es `NULL` antes de acceder. Si es válido, copiar `*ptr` a `*resultado` y
retornar 1. Si es `NULL`, retornar 0.

**Buena práctica:** Siempre verificar punteros antes de desreferenciarlos.
(ejercicio_8_25)=
### Ejercicio 8.25 - Retorno Seguro ⭐⭐☆☆☆

Implementar `int* buscar_max(int *arr, size_t n)` que retorne un puntero al
elemento máximo del arreglo, o `NULL` si el arreglo está vacío o el puntero es
`NULL`.
(ejercicio_8_26)=
### Ejercicio 8.26 - Inicialización de Punteros ⭐☆☆☆☆

Demostrar el problema de punteros sin inicializar y cómo evitarlo siempre
inicializando en `NULL`:
``` c
int *p = NULL;  // Buena práctica
// vs
int *p;         // Peligroso: contiene basura
```
<!-- c -->
(ejercicio_8_27)=
## Ejercicio 8.27 - Intercambio con Punteros ⭐☆☆☆☆

Implementá `void intercambiar(int *a, int *b)` que intercambie dos valores.

**Orientación:**
- Usá una variable temporal
- Desreferenciá con `*a` para acceder al valor
- En `main`, mostrá valores antes y después

---
(ejercicio_8_28)=
## Ejercicio 8.28 - Encontrar Mayor con Puntero ⭐⭐☆☆☆

Implementá `int *mayor(int *a, int *b)` que retorne puntero al mayor de dos
números.

**Orientación:**
- Compará `*a` y `*b`
- Retorná el puntero apropiado
- En `main`, desreferenciá el resultado para mostrar el valor

---
(ejercicio_8_29)=
## Ejercicio 8.29 - División con Resto ⭐⭐☆☆☆

Implementá `void dividir(int dividendo, int divisor, int *cociente, int
*resto)`.

**Orientación:**
- Usá punteros para "retornar" múltiples valores
- `*cociente = dividendo / divisor;`
- `*resto = dividendo % divisor;`
- Verificá que divisor != 0

---
(ejercicio_8_30)=
## Ejercicio 8.30 - Estadísticas de Array ⭐⭐⭐☆☆

Implementá `void estadisticas(int arr[], int n, int *min, int *max, double
*prom)`.

**Orientación:**
- Recorré el array para encontrar mínimo y máximo
- Calculá promedio
- Almacená resultados en las direcciones apuntadas

---
(ejercicio_8_31)=
## Ejercicio 8.31 - Puntero al Medio ⭐⭐⭐☆☆

Implementá `int *elemento_medio(int arr[], int n)` que retorne puntero al
elemento del medio.

**Orientación:**
- Si n es impar: retorna `&arr[n/2]`
- Si n es par: retorna `&arr[n/2 - 1]` (o el que prefieras)
- En `main`, modificá el elemento usando el puntero retornado

---
(ejercicio_8_32)=
## Ejercicio 8.32 - Recorrer Array con Punteros ⭐⭐⭐☆☆

Implementá `int suma_array(int *arr, int n)` usando **aritmética de punteros**.

**Orientación:**
- No uses índices `[]`
- Usá `*arr` para acceder al primer elemento
- Incrementá el puntero: `arr++` para avanzar
- Recorré: `for (int *p = arr; p < arr + n; p++)`

---
(ejercicio_8_33)=
## Ejercicio 8.33 - Invertir Array In-Place ⭐⭐⭐☆☆

Implementá `void invertir(int *arr, int n)` usando dos punteros.

**Orientación:**
- Puntero `inicio` apunta al primer elemento
- Puntero `fin` apunta al último
- Intercambiá valores y mové punteros hacia el centro
- Detené cuando `inicio >= fin`

---
(ejercicio_8_34)=
## Ejercicio 8.34 - Buscar Valor en Array ⭐⭐⭐☆☆

Implementá `int *buscar(int *arr, int n, int valor)` que retorne puntero al
elemento encontrado o NULL.

**Orientación:**
- Recorré con puntero
- Si encontrás el valor, retorná puntero a esa posición
- Si no lo encontrás, retorná NULL
- En `main`, verificá NULL antes de desreferenciar

---
(ejercicio_8_35)=
## Ejercicio 8.35 - Copiar String ⭐⭐⭐⭐☆

Implementá `void copiar_string(char *dest, const char *src)` usando punteros.

**Orientación:**
- Copiá carácter por carácter: `*dest++ = *src++`
- Detené al encontrar '\0'
- Usá `const` para src (no debe modificarse)
- **Cuidado:** asumí que dest tiene espacio suficiente

---
(ejercicio_8_36)=
## Ejercicio 8.36 - Longitud de String ⭐⭐⭐⭐☆

Implementá `int longitud_string(const char *str)` usando punteros.

**Orientación:**
- Contá caracteres hasta '\0'
- Versión 1: `while (*str++) count++;`
- Versión 2: `return str_fin - str_inicio;` (aritmética de punteros)

---
(ejercicio_8_37)=
## Ejercicio 8.37 - Concatenar Strings ⭐⭐⭐⭐☆

Implementá `void concatenar(char *dest, const char *src)` usando punteros.

**Orientación:**
- Avanzá `dest` hasta '\0'
- Copiá `src` desde esa posición
- Asegurate de copiar el '\0' final

---
(ejercicio_8_38)=
## Ejercicio 8.38 - Comparar Strings ⭐⭐⭐⭐☆

Implementá `int comparar_strings(const char *s1, const char *s2)` usando
punteros.

**Orientación:**
- Retorná: negativo si s1 < s2, 0 si iguales, positivo si s1 > s2
- Compará carácter por carácter
- Detené al encontrar diferencia o '\0'
- Retorná `*s1 - *s2` en el primer carácter diferente

---
(ejercicio_8_39)=
## Ejercicio 8.39 - Buscar Subcadena ⭐⭐⭐⭐☆

Implementá `char *buscar_subcadena(const char *texto, const char *patron)`.

**Orientación:**
- Retorná puntero a primera aparición de patron en texto
- Retorná NULL si no se encuentra
- Compará subcadenas en cada posición

---
(ejercicio_8_40)=
## Ejercicio 8.40 - Eliminar Espacios ⭐⭐⭐⭐☆

Implementá `void eliminar_espacios(char *str)` que elimine espacios in-place.

**Orientación:**
- Usá dos punteros: uno para leer, otro para escribir
- Copiá solo caracteres no-espacio
- Terminá con '\0'

---
(ejercicio_8_41)=
## Ejercicio 8.41 - Matriz como Puntero a Puntero ⭐⭐⭐⭐⭐

Implementá funciones para trabajar con matriz dinámica (`int **matriz`):
- `int **crear_matriz(int filas, int cols)`
- `void liberar_matriz(int **matriz, int filas)`
- `void mostrar_matriz(int **matriz, int filas, int cols)`

**Orientación:**
- `crear_matriz`: asigna array de punteros, luego cada fila
- Verificá cada `malloc`
- `liberar_matriz`: libera filas primero, luego el array de punteros

---
(ejercicio_8_42)=
## Ejercicio 8.42 - Rotación de Array ⭐⭐⭐⭐⭐

Implementá `void rotar_izquierda(int *arr, int n, int k)` usando punteros.

**Orientación:**
- k posiciones hacia la izquierda
- Guardá los primeros k elementos temporalmente
- Mové el resto hacia adelante
- Colocá los guardados al final
- Optimización: `k = k % n`

---
(ejercicio_8_43)=
## Ejercicio 8.43 - Transponer Matriz ⭐⭐⭐⭐⭐

Implementá `void transponer(int **matriz, int filas, int cols, int
***resultado)`.

**Orientación:**
- Crea una nueva matriz `cols × filas`
- `resultado[j][i] = matriz[i][j]`
- Usá triple puntero para modificar puntero en función llamadora

---
(ejercicio_8_44)=
## Ejercicio 8.44 - Ordenamiento con Función Comparadora ⭐⭐⭐⭐⭐

Implementá `void ordenar(int *arr, int n, int (*comparar)(int, int))`.

**Orientación:**
- Recibe puntero a función comparadora
- La función comparadora retorna: <0 si a<b, 0 si iguales, >0 si a>b
- Implementá bubble sort usando la función comparadora
- En `main`, pasá funciones para orden ascendente/descendente

---
(ejercicio_8_45)=
## Ejercicio 8.45 - Lista Enlazada Simple ⭐⭐⭐⭐⭐

Implementá una lista enlazada con:
- `struct nodo { int dato; struct nodo *siguiente; };`
- `void insertar_inicio(struct nodo **cabeza, int valor)`
- `void mostrar_lista(struct nodo *cabeza)`
- `void liberar_lista(struct nodo **cabeza)`

**Orientación:**
- `insertar_inicio` modifica puntero cabeza (necesita `**`)
- Nuevo nodo apunta a cabeza actual, luego actualiza cabeza
- `liberar_lista` recorre y libera cada nodo

---
(ejercicio_8_46)=
## Ejercicio 8.46 - Parser de Argumentos ⭐⭐⭐⭐⭐

Implementá un parser que procese argumentos de línea de comandos con flags:
```
./programa -n 100 -s "texto" -v
```

**Orientación:**
- Recorré `argv` con punteros
- Detectá flags con `-`
- Si flag requiere valor, avanzá al siguiente `argv`
- Almacená valores parseados en estructura
- Manejá flags booleanos (presencia indica true)

---

## Notas Finales

:::{danger} Peligros Comunes con Punteros

- **Desreferenciar NULL:** Siempre verificá antes: `if (ptr != NULL)`
- **Punteros colgantes:** No uses memoria después de `free`
- **Fugas de memoria:** Cada `malloc` debe tener su `free`
- **Buffer overflow:** Verificá límites al escribir en arrays
- **Aritmética incorrecta:** `ptr + 1` avanza `sizeof(tipo)` bytes, no 1 byte

:::
<!-- {danger} Peligros Comunes con Punteros -->

:::{tip} Buenas Prácticas

- **Inicializá punteros:** `int *ptr = NULL;`
- **Después de free:** `ptr = NULL;` para evitar uso accidental
- **const para proteger:** `const int *ptr` previene modificación
- **Valgrind es tu amigo:** Detecta leaks y accesos inválidos

:::
<!-- {tip} Buenas Prácticas -->

:::{note} Compilación y Testing

``` bash
# Compilar con máximas advertencias
gcc -Wall -Wextra -Werror -std=c99 programa.c -o programa

# Verificar memoria con Valgrind
valgrind --leak-check=full ./programa
```
<!-- bash -->

:::
<!-- {note} Compilación y Testing -->

Estas consignas cubren conceptos fundamentales y avanzados de punteros:
aritmética, paso por referencia, punteros a funciones, estructuras dinámicas, y
gestión de memoria.

