---
title: Ejercicios de Punteros
short_title: 4. Punteros
---

# Ejercicios de Punteros

## Acerca de

Estos ejercicios están diseñados para afianzar el uso de punteros, la aritmética de punteros, la indirección múltiple y el paso de variables por referencia simulado en el lenguaje C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-punteros`

### Cuestiones de Estilo Aplicables
- **Inicialización de punteros:** Todo puntero que no apunte a un objeto en memoria válido debe inicializarse en `NULL` (ver regla de estilo {ref}`0x0003h`).
- **Verificación de punteros:** Antes de realizar cualquier desreferencia con los operadores `*` o `->`, es obligatorio verificar que el puntero no sea `NULL`.

---

## Referencias y Aritmética

### Ejercicio 4.1 - Duplicar valor

Implementar `void duplicar(int *numero)` que modifique el valor de la variable original.

### Ejercicio 4.2 - División Lenta II

Implementar `int division_lenta(int dividendo, int divisor, int *cociente, int *resto)`. Los resultados se devuelven modificando las variables a las que apuntan `cociente` y `resto`.

Utilicen el retorno para indicar si la división fue correcta o no.

### Ejercicio 4.3 - Estadísticas de Arreglo

Implementar `void estadisticas(int arr[], size_t n, int *min, int *max, double *prom)`.

### Ejercicio 4.4 - Largo seguro con punteros

Implementar `size_t largo_seguro(const char *str, size_t capacidad)`.

**Lógica**: Inicializar un puntero `const char *fin = str;`. Iterar con `while (*fin != '\0' && (size_t)(fin - str) < capacidad) { fin++; }`. El largo es `fin - str`.

---

## Manipulación con Punteros

### Ejercicio 4.5 - Ordenamiento con intercambia

Implementar un algoritmo de ordenamiento (ej. Burbuja) que para intercambiar elementos llame a `void intercambia(int *a, int *b)`.

### Ejercicio 4.6 - Búsqueda de subcadena

Implementar `char* busqueda(const char *cadena, const char *buscado)`. Se debe retornar un puntero al inicio de la primera ocurrencia de `buscado` dentro de `cadena`, o `NULL`.

### Ejercicio 4.7 - Inversión de arreglo

Implementar `void invertir(int *inicio, int *fin)`. Se intercambia `*inicio` con `*fin` y se avanza `inicio` y retrocede `fin` hasta que se crucen.

---

## Punteros a Punteros

### Ejercicio 4.8 - Modificar Puntero

Implementar `void asignar_memoria(int **ptr, int valor)` que reserve memoria para un entero, le asigne el `valor` y modifique el puntero original para que apunte a esa memoria.

**Uso esperado:**
```c
int *p = NULL;
asignar_memoria(&p, 42);
// Ahora *p contiene 42
```

### Ejercicio 4.9 - Matriz como Puntero a Puntero

Implementar `int** crear_matriz(int filas, int columnas)` que reserve memoria para una matriz dinámica usando un puntero a punteros. Cada fila debe ser un arreglo independiente.

**Recordatorio:** También implementar `void liberar_matriz(int **matriz, int filas)`.

### Ejercicio 4.10 - Arreglo de Cadenas

Implementar `void ordenar_cadenas(char **cadenas, int n)` que ordene un arreglo de punteros a cadenas lexicográficamente usando `strcmp`.

**Ejemplo:**
```c
char *palabras[] = {"hola", "adios", "casa", "barco"};
ordenar_cadenas(palabras, 4);
// Resultado: {"adios", "barco", "casa", "hola"}
```

---

## Aritmética de Punteros Avanzada

### Ejercicio 4.11 - Recorrido con Punteros

Implementar `int suma_arreglo_ptr(int *inicio, int *fin)` que sume todos los elementos entre `inicio` (inclusive) y `fin` (exclusive) usando solo aritmética de punteros, sin índices.

**Restricción:** No usar `[]`, solo `*`, `++`, `--`.

### Ejercicio 4.12 - Copiar Arreglos

Implementar `void copiar(int *destino, const int *origen, size_t n)` que copie `n` elementos de `origen` a `destino` usando solo punteros.

**Estrategia:** `while (n--) { *destino++ = *origen++; }`

### Ejercicio 4.13 - Buscar Elemento

Implementar `int* buscar_elemento(int *inicio, int *fin, int valor)` que retorne un puntero al primer elemento igual a `valor`, o `NULL` si no se encuentra.

### Ejercicio 4.14 - Distancia entre Punteros

Implementar `size_t distancia(const int *p1, const int *p2)` que calcule cuántos elementos hay entre dos punteros del mismo arreglo.

**Recordatorio:** La diferencia entre punteros del mismo arreglo da el número de elementos entre ellos.

---

## Punteros Constantes

### Ejercicio 4.15 - Puntero a Constante vs Puntero Constante

Explicar y ejemplificar la diferencia entre:
- `const int *p` - puntero a entero constante (no se puede modificar `*p`)
- `int * const p` - puntero constante a entero (no se puede modificar `p`)
- `const int * const p` - puntero constante a entero constante

Implementar funciones que demuestren cada caso.

### Ejercicio 4.16 - Función con Parámetros Constantes

Implementar `int maximo_arreglo(const int *arr, size_t n)` que encuentre el máximo sin modificar el arreglo original.

**Ventaja:** El `const` documenta que la función no modifica el arreglo y permite que el compilador detecte modificaciones accidentales.

### Ejercicio 4.17 - Cadenas de Solo Lectura

Implementar `size_t contar_vocales(const char *str)` que cuente vocales sin modificar la cadena.

---

## Punteros y Estructuras

### Ejercicio 4.18 - Acceso a Miembros

Dada una estructura:
```c
typedef struct {
    int x;
    int y;
} punto_t;
```

Implementar `void trasladar(punto_t *p, int dx, int dy)` que modifique las coordenadas del punto sumando `dx` y `dy`.

**Notación:** Usar el operador `->` para acceder a miembros: `p->x += dx;`

### Ejercicio 4.19 - Arreglo de Estructuras

Implementar `void ordenar_puntos_por_x(punto_t *puntos, int n)` que ordene un arreglo de puntos según su coordenada `x`.

### Ejercicio 4.20 - Estructura con Punteros

Dada:
```c
typedef struct {
    char *nombre;
    int edad;
} persona_t;
```

Implementar `void crear_persona(persona_t *p, const char *nombre, int edad)` que inicialice la estructura, reservando memoria para el nombre con `strdup` o `malloc` + `strcpy`.

**Importante:** También implementar `void liberar_persona(persona_t *p)` que libere la memoria del nombre.

---

## Punteros a Funciones

### Ejercicio 4.21 - Callback Simple

Implementar `void aplicar(int *arr, size_t n, void (*func)(int *))` que aplique una función a cada elemento del arreglo.

**Ejemplo de uso:**
```c
void duplicar_elemento(int *x) { *x *= 2; }

int arr[] = {1, 2, 3, 4, 5};
aplicar(arr, 5, duplicar_elemento);
// arr ahora es {2, 4, 6, 8, 10}
```

### Ejercicio 4.22 - Ordenamiento Genérico

Implementar `void ordenar_generico(void *arr, size_t n, size_t tam_elemento, int (*comparar)(const void*, const void*))` que ordene un arreglo de cualquier tipo usando una función de comparación personalizada.

**Pista:** Similar a `qsort` de la biblioteca estándar. Usar `memcpy` para intercambiar elementos.

### Ejercicio 4.23 - Tabla de Funciones

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

---

## Punteros Nulos y Validación

### Ejercicio 4.24 - Validación de Punteros

Implementar `int acceso_seguro(int *ptr, int *resultado)` que verifique si `ptr` es `NULL` antes de acceder. Si es válido, copiar `*ptr` a `*resultado` y retornar 1. Si es `NULL`, retornar 0.

**Buena práctica:** Siempre verificar punteros antes de desreferenciarlos.

### Ejercicio 4.25 - Retorno Seguro

Implementar `int* buscar_max(int *arr, size_t n)` que retorne un puntero al elemento máximo del arreglo, o `NULL` si el arreglo está vacío o el puntero es `NULL`.

### Ejercicio 4.26 - Inicialización de Punteros

Demostrar el problema de punteros sin inicializar y cómo evitarlo siempre inicializando en `NULL`:
```c
int *p = NULL;  // Buena práctica
// vs
int *p;         // Peligroso: contiene basura
```
