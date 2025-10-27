---
title: Ejercicios de punteros
short_title: 5. Punteros
---

Ejercicios diseñados para afianzar el uso de punteros, la aritmética de punteros
y el paso de variables por referencia.

## 1: Referencias y Aritmética

### 1.1: Duplicar valor

Implementar `void duplicar(int *numero)` que modifique el valor de la variable
original.

### 1.2: División Lenta II

Implementar
`int division_lenta(int dividendo, int divisor, int *cociente, int *resto)`.
Los resultados se devuelven modificando las variables a las que apuntan
`cociente` y `resto`.

Utilicen el retorno para indicar si la división fue correcta o nó.

### 1.3: Estadísticas de Arreglo

Implementar
`void estadisticas(int arr[], size_t n, int *min, int *max, double *prom)`.

### 1.4: Largo seguro con punteros

Implementar `size_t largo_seguro(const char *str, size_t capacidad)`.
**Lógica**: Inicializar un puntero `const char *fin = str;`. Iterar con
`while (*fin != '\0' && (size_t)(fin - str) < capacidad) { fin++; }`. El largo
es `fin - str`.

## 2: Manipulación con Punteros

### 2.1: Ordenamiento con `intercambia`

Implementar un algoritmo de ordenamiento (ej. Burbuja) que para intercambiar
elementos llame a `void intercambia(int *a, int *b)`.

### 2.2: Búsqueda de subcadena

Implementar `char* busqueda(const char *cadena, const char *buscado)`. Se debe
retornar un puntero al inicio de la primera ocurrencia de `buscado` dentro de
`cadena`, o `NULL`.

### 2.3: Inversión de arreglo

Implementar `void invertir(int *inicio, int *fin)`. Se intercambia `*inicio` con
`*fin` y se avanza `inicio` y retrocede `fin` hasta que se crucen.

## 3: Punteros a Punteros

### 3.1: Modificar Puntero

Implementar `void asignar_memoria(int **ptr, int valor)` que reserve memoria para un entero, le asigne el `valor` y modifique el puntero original para que apunte a esa memoria.

**Uso esperado:**
```c
int *p = NULL;
asignar_memoria(&p, 42);
// Ahora *p contiene 42
```

### 3.2: Matriz como Puntero a Puntero

Implementar `int** crear_matriz(int filas, int columnas)` que reserve memoria para una matriz dinámica usando un puntero a punteros. Cada fila debe ser un arreglo independiente.

**Recordatorio:** También implementar `void liberar_matriz(int **matriz, int filas)`.

### 3.3: Arreglo de Cadenas

Implementar `void ordenar_cadenas(char **cadenas, int n)` que ordene un arreglo de punteros a cadenas lexicográficamente usando `strcmp`.

**Ejemplo:**
```c
char *palabras[] = {"hola", "adios", "casa", "barco"};
ordenar_cadenas(palabras, 4);
// Resultado: {"adios", "barco", "casa", "hola"}
```

## 4: Aritmética de Punteros Avanzada

### 4.1: Recorrido con Punteros

Implementar `int suma_arreglo_ptr(int *inicio, int *fin)` que sume todos los elementos entre `inicio` (inclusive) y `fin` (exclusive) usando solo aritmética de punteros, sin índices.

**Restricción:** No usar `[]`, solo `*`, `++`, `--`.

### 4.2: Copiar Arreglos

Implementar `void copiar(int *destino, const int *origen, size_t n)` que copie `n` elementos de `origen` a `destino` usando solo punteros.

**Estrategia:** `while (n--) { *destino++ = *origen++; }`

### 4.3: Buscar Elemento

Implementar `int* buscar_elemento(int *inicio, int *fin, int valor)` que retorne un puntero al primer elemento igual a `valor`, o `NULL` si no se encuentra.

### 4.4: Diferencia entre Punteros

Implementar `size_t distancia(const int *p1, const int *p2)` que calcule cuántos elementos hay entre dos punteros del mismo arreglo.

**Recordatorio:** La diferencia entre punteros del mismo arreglo da el número de elementos entre ellos.

## 5: Punteros Constantes

### 5.1: Puntero a Constante vs Puntero Constante

Explicar y ejemplificar la diferencia entre:
- `const int *p` - puntero a entero constante (no se puede modificar `*p`)
- `int * const p` - puntero constante a entero (no se puede modificar `p`)
- `const int * const p` - puntero constante a entero constante

Implementar funciones que demuestren cada caso.

### 5.2: Función con Parámetros Constantes

Implementar `int maximo_arreglo(const int *arr, size_t n)` que encuentre el máximo sin modificar el arreglo original.

**Ventaja:** El `const` documenta que la función no modifica el arreglo y permite que el compilador detecte modificaciones accidentales.

### 5.3: Cadenas de Solo Lectura

Implementar `size_t contar_vocales(const char *str)` que cuente vocales sin modificar la cadena.

## 6: Punteros y Estructuras

### 6.1: Acceso a Miembros

Dada una estructura:
```c
typedef struct {
    int x;
    int y;
} punto_t;
```

Implementar `void trasladar(punto_t *p, int dx, int dy)` que modifique las coordenadas del punto sumando `dx` y `dy`.

**Notación:** Usar el operador `->` para acceder a miembros: `p->x += dx;`

### 6.2: Arreglo de Estructuras

Implementar `void ordenar_puntos_por_x(punto_t *puntos, int n)` que ordene un arreglo de puntos según su coordenada `x`.

### 6.3: Estructura con Punteros

Dada:
```c
typedef struct {
    char *nombre;
    int edad;
} persona_t;
```

Implementar `void crear_persona(persona_t *p, const char *nombre, int edad)` que inicialice la estructura, reservando memoria para el nombre con `strdup` o `malloc` + `strcpy`.

**Importante:** También implementar `void liberar_persona(persona_t *p)` que libere la memoria del nombre.

## 7: Punteros a Funciones

### 7.1: Callback Simple

Implementar `void aplicar(int *arr, size_t n, void (*func)(int *))` que aplique una función a cada elemento del arreglo.

**Ejemplo de uso:**
```c
void duplicar_elemento(int *x) { *x *= 2; }

int arr[] = {1, 2, 3, 4, 5};
aplicar(arr, 5, duplicar_elemento);
// arr ahora es {2, 4, 6, 8, 10}
```

### 7.2: Ordenamiento Genérico

Implementar `void ordenar_generico(void *arr, size_t n, size_t tam_elemento, int (*comparar)(const void*, const void*))` que ordene un arreglo de cualquier tipo usando una función de comparación personalizada.

**Pista:** Similar a `qsort` de la biblioteca estándar. Usar `memcpy` para intercambiar elementos.

### 7.3: Tabla de Funciones

Crear un arreglo de punteros a funciones para una calculadora:
```c
typedef double (*operacion_t)(double, double);

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

operacion_t operaciones[] = {sumar, restar, multiplicar, dividir};
```

Implementar un menú que permita seleccionar y ejecutar operaciones usando este arreglo.

## 8: Punteros Nulos y Validación

### 8.1: Validación de Punteros

Implementar `int acceso_seguro(int *ptr, int *resultado)` que verifique si `ptr` es `NULL` antes de acceder. Si es válido, copiar `*ptr` a `*resultado` y retornar 1. Si es `NULL`, retornar 0.

**Buena práctica:** Siempre verificar punteros antes de desreferenciarlos.

### 8.2: Retorno Seguro

Implementar `int* buscar_max(int *arr, size_t n)` que retorne un puntero al elemento máximo del arreglo, o `NULL` si el arreglo está vacío o el puntero es `NULL`.

### 8.3: Inicialización de Punteros

Demostrar el problema de punteros sin inicializar y cómo evitarlo siempre inicializando en `NULL`:
```c
int *p = NULL;  // Buena práctica
// vs
int *p;         // Peligroso: contiene basura
```
