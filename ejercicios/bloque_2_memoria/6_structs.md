---
title: Ejercicios de Estructuras
short_title: 5. Structs
---

# Ejercicios de Estructuras

## Acerca de

Estos ejercicios tienen como propósito ejercitar el agrupamiento de tipos
heterogéneos bajo una misma entidad de datos empleando la palabra clave `struct`
en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-estructuras`

### Cuestiones de Estilo Aplicables
- **Inicialización de structs:** Inicializá siempre las estructuras utilizando
  llaves en su declaración (ej. `fraccion_t f = {0, 1};`) para evitar basura en
  sus miembros (ver {ref}`0x0003h`).
- **Paso de estructuras:** Para evitar el overhead de copiar estructuras por
  valor en el stack frame de la llamada, pasá punteros a estructuras
  (`fraccion_t *`) junto con la constante de solo lectura `const` cuando
  corresponda.

---

## Fracciones

Desarrollar un tipo `fraccion_t` y las funciones necesarias para operar con
fracciones. El objetivo es encapsular el numerador y el denominador en una única
entidad.

``` c
typedef struct {
    int numerador;
    int denominador;
} fraccion_t;
```
<!-- c -->

### Ejercicio 5.1 - Operaciones Aritméticas

Implementar funciones que tomen dos fracciones y retornen el resultado de la
operación.

- **Suma**: $$\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}$$
- **Resta**: $$\frac{a}{b} - \frac{c}{d} = \frac{ad - bc}{bd}$$
- **Multiplicación**: $$\frac{a}{b} \times \frac{c}{d} = \frac{ac}{bd}$$
- **División**: $$\frac{a}{b} \div \frac{c}{d} = \frac{ad}{bc}$$

### Ejercicio 5.2 - Simplificación

Implementar una función que modifique una fracción para llevarla a su mínima
expresión. La simplificación se realiza dividiendo numerador y denominador por
su **Máximo Común Divisor (MCD)**.

---

## División con Resto

### Ejercicio 5.3 - Estructura de división

La división entera en C (`/` y `%`) produce dos resultados. El objetivo es
unificar estas operaciones en una única función que retorne una `struct` con el
cociente y el resto, basándose en el algoritmo de la división.

$$dividendo = divisor \times cociente + resto, \quad \text{donde } 0 \le resto < |divisor|$$

``` c
typedef struct {
    int cociente;
    int resto;
} division_t;

division_t division_lenta(int dividendo, int divisor);
```
<!-- c -->

---

## Medición de Tiempo

Desarrollar una estructura `tiempo_t` para representar un instante o duración en
horas, minutos y segundos, junto con funciones para manipularla.

``` c
typedef struct {
    int horas;
    int minutos;
    int segundos;
} tiempo_t;
```
<!-- c -->

### Ejercicio 5.4 - Suma de Tiempos

Implementar una función que sume dos `tiempo_t`. El resultado debe ser
normalizado para que los segundos y minutos no excedan 59.

- $S_{total} = t_1.segundos + t_2.segundos$
- $M_{acarreo} = S_{total} / 60$
- $S_{resultado} = S_{total} \% 60$
- $M_{total} = t_1.minutos + t_2.minutos + M_{acarreo}$
- $H_{acarreo} = M_{total} / 60$
- $M_{resultado} = M_{total} \% 60$
- $H_{resultado} = t_1.horas + t_2.horas + H_{acarreo}$

### Ejercicio 5.5 - Comparación de Tiempos

Implementar una función que compare dos `tiempo_t` y devuelva un valor que
indique si el primero es anterior, igual o posterior al segundo. Una estrategia
es convertir ambos tiempos a una unidad común (ej. segundos totales) para
facilitar la comparación.

$$t_{en\_segundos} = horas \times 3600 + minutos \times 60 + segundos$$

---

## Tipos de Datos Compuestos

### Ejercicio 5.6 - Arreglos con Capacidad

Encapsular un arreglo en una estructura para agrupar el contenedor de datos, su
longitud actual y su capacidad máxima. Esto previene errores de desbordamiento
de búfer y simplifica pasar la información del arreglo a funciones.

``` c
#define CAPACIDAD_MAX 100
typedef struct {
    int datos[CAPACIDAD_MAX];
    size_t longitud; // Elementos actualmente en uso
} arreglo_t;
```
<!-- c -->

Este ejercicio puede ser mejorado con memoria dinámica, para lo cual es
necesario agregar un atributo más con el tamaño en memoria pedido para `datos`.

### Ejercicio 5.7 - Cadenas Seguras II

Aplicar el mismo principio a las cadenas de caracteres para crear un tipo
`cadena_segura_t` que gestione su propia capacidad y longitud, evitando los
peligros asociados a las cadenas de C estándar.

``` c
#define CAPACIDAD_MAX_CADENA 256
typedef struct {
    char datos[CAPACIDAD_MAX_CADENA];
    size_t longitud;
} cadena_segura_t;
```
<!-- c -->
