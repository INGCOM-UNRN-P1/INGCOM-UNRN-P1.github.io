---
title: Ejercicios de structs
short_title: 9. structs
---

Ejercicios para modelar datos complejos utilizando estructuras (`struct`).

## 1: Fracciones

Desarrollar un tipo `fraccion_t` y las funciones necesarias para operar con
fracciones.

```c
typedef struct {
    int numerador;
    int denominador;
} fraccion_t;
```

### 1.1: Operaciones Aritméticas

Implementar funciones para suma, resta, multiplicación y división.

- Suma: $$frac{a}{b} + frac{c}{d} = frac{ad + bc}{bd}$
- Resta: $$frac{a}{b} - frac{c}{d} = frac{ad - bc}{bd}$
- Multiplicación: $$frac{a}{b} \times frac{c}{d} = frac{ac}{bd}$
- División: $$frac{a}{b} \div frac{c}{d} = frac{ad}{bc}$

### 1.2: Simplificación

La simplificación se realiza dividiendo numerador y denominador por su Máximo
Común Divisor (MCD).

## 2: División con Resto

Unificar las funciones de división lenta para que retornen una única `struct`.

```c
typedef struct {
    int cociente;
    int resto;
} division_t;

division_t division_lenta(int dividendo, int divisor);
```

## 3: Medición de Tiempo

Desarrollar una estructura `tiempo_t` y sus funciones.

```c
typedef struct {
    int horas;
    int minutos;
    int segundos;
} tiempo_t;
```

### 3.1: Suma de Tiempos

Al sumar, se debe normalizar el resultado. Si `segundos >= 60`, se incrementan
los minutos y se ajustan los segundos. Lo mismo aplica para los minutos y las
horas.

### 3.2: Comparación de Tiempos

Implementar una función que determine si un `tiempo_t` es anterior, igual o
posterior a otro.

## 4: Tipos de Datos Compuestos

### 4.1: Arreglos con Capacidad

Encapsular un arreglo en una estructura para pasar la capacidad y la longitud
juntas.

```c
#define CAPACIDAD_MAX 100
typedef struct {
    int datos[CAPACIDAD_MAX];
    size_t longitud;
} arreglo_t;
```

### 4.2: Cadenas Seguras II

Similar al anterior, para cadenas.

```c
#define CAPACIDAD_MAX_CADENA 256
typedef struct {
    char datos[CAPACIDAD_MAX_CADENA];
    size_t longitud;
} cadena_segura_t;
```
