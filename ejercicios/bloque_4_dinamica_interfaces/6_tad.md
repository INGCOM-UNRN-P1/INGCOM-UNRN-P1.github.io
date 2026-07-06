---
title: "Ejercicios: Tipos de Datos Abstractos"
short_title: "6. TAD"
---

# Ejercicios de Tipos de Datos Abstractos

## Acerca de

Estos ejercicios tienen como propósito dominar el diseño e implementación de Tipos de Datos Abstractos (TAD) en C, aplicando un encapsulamiento estricto mediante punteros opacos y la manipulación de listas enlazadas dinámicas.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-tad`

### Cuestiones de Estilo Aplicables
- **Encapsulamiento estricto:** La estructura del nodo y de la lista debe definirse únicamente en el archivo de implementación `.c`, exponiendo al llamador solo el tipo incompleto (`typedef struct lista lista_t;`) en el `.h` (ver {ref}`0x3002h`).
- **Gestión de memoria:** El destructor de la lista debe encargarse de recorrer y liberar de forma segura cada nodo individual en el Heap antes de liberar la estructura de control.

---

## Lista Enlazada Simple - Operaciones Básicas

Implementar un TAD de lista enlazada simple con su interfaz completa.

```c
// lista.h
typedef struct lista lista_t;

lista_t* crear_lista(void);
void destruir_lista(lista_t* lista);
bool lista_vacia(const lista_t* lista);
size_t lista_longitud(const lista_t* lista);
```

### Ejercicio 6.1 - Inserción al Inicio

Implementar la operación de insertar un elemento al principio de la lista. Esta operación debe tener complejidad $O(1)$.

```c
bool insertar_al_inicio(lista_t* lista, int dato);
```

### Ejercicio 6.2 - Inserción al Final

Implementar la operación de insertar un elemento al final de la lista. Analizar la complejidad: $O(n)$ sin puntero al último, $O(1)$ con puntero al último.

```c
bool insertar_al_final(lista_t* lista, int dato);
```

### Ejercicio 6.3 - Ver Primero y Último

Implementar operaciones para obtener el primer y último elemento sin modificar la lista.

```c
bool ver_primero(const lista_t* lista, int* dato);
bool ver_ultimo(const lista_t* lista, int* dato);
```

### Ejercicio 6.4 - Borrar Primero

Implementar la operación de eliminar el primer elemento y retornar su valor. Complejidad: $O(1)$.

```c
bool borrar_primero(lista_t* lista, int* dato);
```

---

## Lista Enlazada - Operaciones de Búsqueda

### Ejercicio 6.5 - Buscar Elemento

Implementar una función que determine si un elemento está presente en la lista. Retornar `true` si lo encuentra.

```c
bool lista_pertenece(const lista_t* lista, int dato);
```

**Complejidad:** $O(n)$ en el peor caso.

### Ejercicio 6.6 - Obtener Elemento en Posición

Implementar una función que retorne el elemento en una posición específica (índice basado en 0).

```c
bool lista_obtener(const lista_t* lista, size_t posicion, int* dato);
```

Retornar `false` si la posición es inválida.

### Ejercicio 6.7 - Contar Ocurrencias

Implementar una función que cuente cuántas veces aparece un elemento en la lista.

```c
size_t lista_contar(const lista_t* lista, int dato);
```

---

## Lista Enlazada - Operaciones Avanzadas

### Ejercicio 6.8 - Insertar en Posición

Implementar una función que inserte un elemento en una posición específica.

```c
bool lista_insertar_en(lista_t* lista, size_t posicion, int dato);
```

**Casos especiales:**
- Posición 0: insertar al inicio.
- Posición >= longitud: insertar al final.
- Posición intermedia: recorrer hasta la posición.

### Ejercicio 6.9 - Eliminar por Valor

Implementar la operación de eliminar todas las ocurrencias de un elemento y liberar sus nodos correspondientes en memoria.

```c
bool lista_eliminar(lista_t* lista, int dato);
```

### Ejercicio 6.10 - Invertir Lista

Reorganizar los enlaces de los nodos de la lista para invertir su orden de manera destructiva (in-place, $O(n)$ tiempo, $O(1)$ memoria).

```c
void lista_invertir(lista_t* lista);
```

### Ejercicio 6.11 - Concatenar Listas

Desarrollar una función que anexe de forma destructiva todos los elementos de la segunda lista al final de la primera.

```c
void lista_concatenar(lista_t* destino, lista_t* origen);
```
