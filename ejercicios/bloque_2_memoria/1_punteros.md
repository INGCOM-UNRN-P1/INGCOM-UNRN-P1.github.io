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

### Ejercicio 4.1 - Duplicar valor

Implementar `void duplicar(int *numero)` que modifique el valor de la variable
original.

### Ejercicio 4.2 - División Lenta II

Implementar `int division_lenta(int dividendo, int divisor, int *cociente, int
*resto)`. Los resultados se devuelven modificando las variables a las que
apuntan `cociente` y `resto`.

Utilicen el retorno para indicar si la división fue correcta o no.

### Ejercicio 4.3 - Estadísticas de Arreglo

Implementar `void estadisticas(int arr[], size_t n, int *min, int *max, double
*prom)`.

### Ejercicio 4.4 - Largo seguro con punteros

Implementar `size_t largo_seguro(const char *str, size_t capacidad)`.

**Lógica**: Inicializar un puntero `const char *fin = str;`. Iterar con `while
(*fin != '\0' && (size_t)(fin - str) < capacidad) { fin++; }`. El largo es `fin
- str`.

---

## Manipulación con Punteros

### Ejercicio 4.5 - Ordenamiento con intercambia

Implementar un algoritmo de ordenamiento (ej. Burbuja) que para intercambiar
elementos llame a `void intercambia(int *a, int *b)`.

### Ejercicio 4.6 - Búsqueda de subcadena

Implementar `char* busqueda(const char *cadena, const char *buscado)`. Se debe
retornar un puntero al inicio de la primera ocurrencia de `buscado` dentro de
`cadena`, o `NULL`.

### Ejercicio 4.7 - Inversión de arreglo

Implementar `void invertir(int *inicio, int *fin)`. Se intercambia `*inicio` con
`*fin` y se avanza `inicio` y retrocede `fin` hasta que se crucen.

---

## Punteros a Punteros

### Ejercicio 4.8 - Modificar Puntero

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

### Ejercicio 4.9 - Matriz como Puntero a Puntero

Implementar `int** crear_matriz(int filas, int columnas)` que reserve memoria
para una matriz dinámica usando un puntero a punteros. Cada fila debe ser un
arreglo independiente.

**Recordatorio:** También implementar `void liberar_matriz(int **matriz, int
filas)`.

### Ejercicio 4.10 - Arreglo de Cadenas

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

### Ejercicio 4.11 - Recorrido con Punteros

Implementar `int suma_arreglo_ptr(int *inicio, int *fin)` que sume todos los
elementos entre `inicio` (inclusive) y `fin` (exclusive) usando solo aritmética
de punteros, sin índices.

**Restricción:** No usar `[]`, solo `*`, `++`, `--`.

### Ejercicio 4.12 - Copiar Arreglos

Implementar `void copiar(int *destino, const int *origen, size_t n)` que copie
`n` elementos de `origen` a `destino` usando solo punteros.

**Estrategia:** `while (n--) { *destino++ = *origen++; }`

### Ejercicio 4.13 - Buscar Elemento

Implementar `int* buscar_elemento(int *inicio, int *fin, int valor)` que retorne
un puntero al primer elemento igual a `valor`, o `NULL` si no se encuentra.

### Ejercicio 4.14 - Distancia entre Punteros

Implementar `size_t distancia(const int *p1, const int *p2)` que calcule cuántos
elementos hay entre dos punteros del mismo arreglo.

**Recordatorio:** La diferencia entre punteros del mismo arreglo da el número de
elementos entre ellos.

---

## Punteros Constantes

### Ejercicio 4.15 - Puntero a Constante vs Puntero Constante

Explicar y ejemplificar la diferencia entre:
- `const int *p` - puntero a entero constante (no se puede modificar `*p`)
- `int * const p` - puntero constante a entero (no se puede modificar `p`)
- `const int * const p` - puntero constante a entero constante

Implementar funciones que demuestren cada caso.

### Ejercicio 4.16 - Función con Parámetros Constantes

Implementar `int maximo_arreglo(const int *arr, size_t n)` que encuentre el
máximo sin modificar el arreglo original.

**Ventaja:** El `const` documenta que la función no modifica el arreglo y
permite que el compilador detecte modificaciones accidentales.

### Ejercicio 4.17 - Cadenas de Solo Lectura

Implementar `size_t contar_vocales(const char *str)` que cuente vocales sin
modificar la cadena.

---

## Punteros y Estructuras

### Ejercicio 4.18 - Acceso a Miembros

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

### Ejercicio 4.19 - Arreglo de Estructuras

Implementar `void ordenar_puntos_por_x(punto_t *puntos, int n)` que ordene un
arreglo de puntos según su coordenada `x`.

### Ejercicio 4.20 - Estructura con Punteros

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

### Ejercicio 4.21 - Callback Simple

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

### Ejercicio 4.22 - Ordenamiento Genérico

Implementar `void ordenar_generico(void *arr, size_t n, size_t tam_elemento, int
(*comparar)(const void*, const void*))` que ordene un arreglo de cualquier tipo
usando una función de comparación personalizada.

**Pista:** Similar a `qsort` de la biblioteca estándar. Usar `memcpy` para
intercambiar elementos.

### Ejercicio 4.23 - Tabla de Funciones

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

### Ejercicio 4.24 - Validación de Punteros

Implementar `int acceso_seguro(int *ptr, int *resultado)` que verifique si `ptr`
es `NULL` antes de acceder. Si es válido, copiar `*ptr` a `*resultado` y
retornar 1. Si es `NULL`, retornar 0.

**Buena práctica:** Siempre verificar punteros antes de desreferenciarlos.

### Ejercicio 4.25 - Retorno Seguro

Implementar `int* buscar_max(int *arr, size_t n)` que retorne un puntero al
elemento máximo del arreglo, o `NULL` si el arreglo está vacío o el puntero es
`NULL`.

### Ejercicio 4.26 - Inicialización de Punteros

Demostrar el problema de punteros sin inicializar y cómo evitarlo siempre
inicializando en `NULL`:
``` c
int *p = NULL;  // Buena práctica
// vs
int *p;         // Peligroso: contiene basura
```
<!-- c -->

---

## Ejercicios Adicionales (Práctica Intensiva)

## Ejercicio 1: Intercambio con Punteros

**Dificultad:** ⭐☆☆☆☆

Implementá `void intercambiar(int *a, int *b)` que intercambie dos valores.

**Orientación:**
- Usá una variable temporal
- Desreferenciá con `*a` para acceder al valor
- En `main`, mostrá valores antes y después

---

## Ejercicio 2: Encontrar Mayor con Puntero

**Dificultad:** ⭐⭐☆☆☆

Implementá `int *mayor(int *a, int *b)` que retorne puntero al mayor de dos números.

**Orientación:**
- Compará `*a` y `*b`
- Retorná el puntero apropiado
- En `main`, desreferenciá el resultado para mostrar el valor

---

## Ejercicio 3: División con Resto

**Dificultad:** ⭐⭐☆☆☆

Implementá `void dividir(int dividendo, int divisor, int *cociente, int *resto)`.

**Orientación:**
- Usá punteros para "retornar" múltiples valores
- `*cociente = dividendo / divisor;`
- `*resto = dividendo % divisor;`
- Verificá que divisor != 0

---

## Ejercicio 4: Estadísticas de Array

**Dificultad:** ⭐⭐⭐☆☆

Implementá `void estadisticas(int arr[], int n, int *min, int *max, double *prom)`.

**Orientación:**
- Recorré el array para encontrar mínimo y máximo
- Calculá promedio
- Almacená resultados en las direcciones apuntadas

---

## Ejercicio 5: Puntero al Medio

**Dificultad:** ⭐⭐⭐☆☆

Implementá `int *elemento_medio(int arr[], int n)` que retorne puntero al elemento del medio.

**Orientación:**
- Si n es impar: retorna `&arr[n/2]`
- Si n es par: retorna `&arr[n/2 - 1]` (o el que prefieras)
- En `main`, modificá el elemento usando el puntero retornado

---

## Ejercicio 6: Recorrer Array con Punteros

**Dificultad:** ⭐⭐⭐☆☆

Implementá `int suma_array(int *arr, int n)` usando **aritmética de punteros**.

**Orientación:**
- No uses índices `[]`
- Usá `*arr` para acceder al primer elemento
- Incrementá el puntero: `arr++` para avanzar
- Recorré: `for (int *p = arr; p < arr + n; p++)`

---

## Ejercicio 7: Invertir Array In-Place

**Dificultad:** ⭐⭐⭐☆☆

Implementá `void invertir(int *arr, int n)` usando dos punteros.

**Orientación:**
- Puntero `inicio` apunta al primer elemento
- Puntero `fin` apunta al último
- Intercambiá valores y mové punteros hacia el centro
- Detené cuando `inicio >= fin`

---

## Ejercicio 8: Buscar Valor en Array

**Dificultad:** ⭐⭐⭐☆☆

Implementá `int *buscar(int *arr, int n, int valor)` que retorne puntero al elemento encontrado o NULL.

**Orientación:**
- Recorré con puntero
- Si encontrás el valor, retorná puntero a esa posición
- Si no lo encontrás, retorná NULL
- En `main`, verificá NULL antes de desreferenciar

---

## Ejercicio 9: Copiar String

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `void copiar_string(char *dest, const char *src)` usando punteros.

**Orientación:**
- Copiá carácter por carácter: `*dest++ = *src++`
- Detené al encontrar '\0'
- Usá `const` para src (no debe modificarse)
- **Cuidado:** asumí que dest tiene espacio suficiente

---

## Ejercicio 10: Longitud de String

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `int longitud_string(const char *str)` usando punteros.

**Orientación:**
- Contá caracteres hasta '\0'
- Versión 1: `while (*str++) count++;`
- Versión 2: `return str_fin - str_inicio;` (aritmética de punteros)

---

## Ejercicio 11: Concatenar Strings

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `void concatenar(char *dest, const char *src)` usando punteros.

**Orientación:**
- Avanzá `dest` hasta '\0'
- Copiá `src` desde esa posición
- Asegurate de copiar el '\0' final

---

## Ejercicio 12: Comparar Strings

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `int comparar_strings(const char *s1, const char *s2)` usando punteros.

**Orientación:**
- Retorná: negativo si s1 < s2, 0 si iguales, positivo si s1 > s2
- Compará carácter por carácter
- Detené al encontrar diferencia o '\0'
- Retorná `*s1 - *s2` en el primer carácter diferente

---

## Ejercicio 13: Buscar Subcadena

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `char *buscar_subcadena(const char *texto, const char *patron)`.

**Orientación:**
- Retorná puntero a primera aparición de patron en texto
- Retorná NULL si no se encuentra
- Compará subcadenas en cada posición

---

## Ejercicio 14: Eliminar Espacios

**Dificultad:** ⭐⭐⭐⭐☆

Implementá `void eliminar_espacios(char *str)` que elimine espacios in-place.

**Orientación:**
- Usá dos punteros: uno para leer, otro para escribir
- Copiá solo caracteres no-espacio
- Terminá con '\0'

---

## Ejercicio 15: Matriz como Puntero a Puntero

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá funciones para trabajar con matriz dinámica (`int **matriz`):
- `int **crear_matriz(int filas, int cols)`
- `void liberar_matriz(int **matriz, int filas)`
- `void mostrar_matriz(int **matriz, int filas, int cols)`

**Orientación:**
- `crear_matriz`: asigna array de punteros, luego cada fila
- Verificá cada `malloc`
- `liberar_matriz`: libera filas primero, luego el array de punteros

---

## Ejercicio 16: Rotación de Array

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá `void rotar_izquierda(int *arr, int n, int k)` usando punteros.

**Orientación:**
- k posiciones hacia la izquierda
- Guardá los primeros k elementos temporalmente
- Mové el resto hacia adelante
- Colocá los guardados al final
- Optimización: `k = k % n`

---

## Ejercicio 17: Transponer Matriz

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá `void transponer(int **matriz, int filas, int cols, int ***resultado)`.

**Orientación:**
- Crea una nueva matriz `cols × filas`
- `resultado[j][i] = matriz[i][j]`
- Usá triple puntero para modificar puntero en función llamadora

---

## Ejercicio 18: Ordenamiento con Función Comparadora

**Dificultad:** ⭐⭐⭐⭐⭐

Implementá `void ordenar(int *arr, int n, int (*comparar)(int, int))`.

**Orientación:**
- Recibe puntero a función comparadora
- La función comparadora retorna: <0 si a<b, 0 si iguales, >0 si a>b
- Implementá bubble sort usando la función comparadora
- En `main`, pasá funciones para orden ascendente/descendente

---

## Ejercicio 19: Lista Enlazada Simple

**Dificultad:** ⭐⭐⭐⭐⭐

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

## Ejercicio 20: Parser de Argumentos

**Dificultad:** ⭐⭐⭐⭐⭐

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

:::{tip} Buenas Prácticas
- **Inicializá punteros:** `int *ptr = NULL;`
- **Después de free:** `ptr = NULL;` para evitar uso accidental
- **const para proteger:** `const int *ptr` previene modificación
- **Valgrind es tu amigo:** Detecta leaks y accesos inválidos
:::

:::{note} Compilación y Testing
```bash
# Compilar con máximas advertencias
gcc -Wall -Wextra -Werror -std=c99 programa.c -o programa

# Verificar memoria con Valgrind
valgrind --leak-check=full ./programa
```
:::

Estas consignas cubren conceptos fundamentales y avanzados de punteros: aritmética, paso por referencia, punteros a funciones, estructuras dinámicas, y gestión de memoria.

