---
title: Ejercicios de punteros
short_title: 5. Punteros
---

Ejercicios diseñados para afianzar el uso de punteros, la aritmética de punteros
y el paso de variables por referencia.

## 1: Referencias y Aritmética

### 1.1: Duplicar valor

Implementar `void duplicar(int *numero)` que modifique el valor de la variable
original. `*numero = *numero * 2;`

### 1.2: División Lenta II

Implementar
`void division_lenta(int dividendo, int divisor, int *cociente, int *resto)`.
Los resultados se devuelven modificando las variables a las que apuntan
`cociente` y `resto`.

### 1.3: Estadísticas de Arreglo

Implementar
`void estadisticas(int arr[], size_t n, int *min, int *max, double *prom)`.

```{mermaid}
:caption: "Paso por referencia usando punteros"
graph TD
    A(main: int x = 10;) -- &x --> B(duplicar(int* p));
    B -- *p = 20; --> C(Modifica el valor en la dirección de x);
    C --> D(main: x ahora es 20);
```

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
