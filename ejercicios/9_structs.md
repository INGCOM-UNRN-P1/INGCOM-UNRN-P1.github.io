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

- Suma: $$\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}$$
- Resta: $$\frac{a}{b} - \frac{c}{d} = \frac{ad - bc}{bd}$$
- Multiplicación: $$\frac{a}{b} \times \frac{c}{d} = \frac{ac}{bd}$$
- División: $$\frac{a}{b} \div \frac{c}{d} = \frac{ad}{bc}$$

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
    int horas;d
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

## 5: Modelado de Datos del Mundo Real

### 5.1: Punto y Círculo

Definir `struct punto_t { double x, y; }` y `struct circulo_t { punto_t centro; double radio; }`. Crear funciones para:
- Calcular la distancia entre dos puntos.
- Determinar si un punto está dentro de un círculo.

### 5.2: Rectángulo

Definir `struct rectangulo_t` usando dos `punto_t` (esquina superior izquierda e inferior derecha). Implementar funciones para calcular su área y su perímetro.

### 5.3: Estudiante y Curso

Definir `struct estudiante_t` (nombre, legajo, promedio) y `struct curso_t` (nombre, un arreglo de estudiantes, cantidad de estudiantes). Crear funciones para:
- Añadir un estudiante a un curso.
- Encontrar al estudiante con el mejor promedio del curso.
- Calcular el promedio general del curso.

### 5.4: Vector 3D

Definir `struct vector3d_t { double x, y, z; }`. Implementar funciones para:
- Suma y resta de vectores.
- Producto escalar.
- Producto vectorial.
- Magnitud (longitud) del vector.

### 5.5: Color RGB

Definir `struct color_rgb_t { unsigned char r, g, b; }`. Crear una función que mezcle dos colores, promediando sus componentes `r`, `g` y `b`.

### 5.6: Libro de Biblioteca

Definir `struct libro_t` (título, autor, ISBN, disponible). Simular una pequeña biblioteca con un arreglo de `libro_t`. Implementar funciones para:
- Buscar un libro por título o ISBN.
- Prestar un libro (cambiar su estado a no disponible).
- Devolver un libro.

### 5.7: Fecha

Definir `struct fecha_t { int dia, mes, anio; }`. Crear una función `void avanzar_un_dia(fecha_t* fecha)` que incremente la fecha en un día, manejando correctamente los fines de mes y los años bisiestos.

### 5.8: Polinomio

Representar un polinomio usando una `struct` que contenga el grado y un arreglo (o puntero) a sus coeficientes. Implementar una función que evalúe el polinomio para un valor `x` dado, usando el método de Horner.

### 5.9: Número Complejo

Definir `struct complejo_t { double real, imag; }`. Implementar funciones para las cuatro operaciones aritméticas básicas (suma, resta, multiplicación, división) con números complejos.

### 5.10: Inventario de Producto

Definir `struct producto_t` (código, descripción, precio, stock). Crear un programa que gestione un inventario (un arreglo de productos) permitiendo añadir, buscar, actualizar stock y eliminar productos.

### 5.11: `struct` Anidada (Dirección)

Crear una `struct` `direccion_t` (calle, numero, ciudad, codigo_postal) y anidarla dentro de una `struct` `persona_t` (nombre, edad, direccion). Escribir una función que imprima los datos completos de una persona.

### 5.12: Campos de Bits (Bitfields)

Usar campos de bits en una `struct` para empaquetar 8 banderas booleanas (flags) en un solo byte. Demostrar cómo establecer, limpiar y verificar el estado de un bit individual.

### 5.13: Uniones (`union`)

Definir una `union` llamada `valor_t` que pueda almacenar un `int`, un `float` o un `char*`. Escribir una `struct` `variable_t` que contenga un `tipo` (enum) y la `union valor_t`, para crear una variable que pueda contener diferentes tipos de datos de forma segura.

### 5.14: `typedef` con `struct` Anónima

Mostrar cómo usar `typedef` para crear un tipo de dato a partir de una `struct` anónima. Compararlo con la definición estándar de `struct` y luego un `typedef`.

### 5.15: Comparación de `structs`

Implementar una función que compare dos `structs` de tipo `persona_t` (del ejercicio 5.11) y devuelva si son iguales o no. La igualdad se define como tener todos los campos (incluyendo la dirección anidada) idénticos.
```

## 6: Más Estructuras de Datos y Algoritmos

### 6.1: Mazo de Cartas

Definir una `struct` para una carta (`palo`, `valor`) y otra para un `mazo` (un arreglo de 52 cartas). Implementar funciones para:
- `crear_mazo()`: Genera un mazo ordenado.
- `barajar_mazo(mazo_t* mazo)`: Desordena las cartas aleatoriamente.
- `repartir_carta(mazo_t* mazo)`: Devuelve la carta de arriba del mazo.

### 6.2: Nodo de Lista Enlazada

Definir `struct nodo_t { int dato; struct nodo_t* siguiente; }`. Implementar las funciones básicas para manipular una lista enlazada simple:
- `insertar_al_principio(struct nodo_t** cabeza, int dato)`
- `imprimir_lista(struct nodo_t* cabeza)`
- `liberar_lista(struct nodo_t** cabeza)`

### 6.3: Nodo de Árbol Binario

Definir `struct arbol_nodo_t { int dato; struct arbol_nodo_t* izq; struct arbol_nodo_t* der; }`. Implementar una función para insertar un nuevo nodo en un Árbol de Búsqueda Binaria (BST) y otra para imprimir el árbol en orden (in-order traversal).

### 6.4: Transacción Bancaria

Definir `struct transaccion_t` (fecha, tipo, monto) y `struct cuenta_t` (nro_cuenta, saldo, arreglo dinámico de transacciones). Implementar una función que agrega una transacción a una cuenta, actualiza el saldo y usa `realloc` para agrandar el historial de transacciones.

### 6.5: Partícula en Simulación Física

Definir una `struct particula_t` que contenga su posición, velocidad y aceleración (usando la `struct vector3d_t` del ejercicio 5.4). Implementar una función `actualizar_estado(particula_t* p, double dt)` que actualice la posición y velocidad de la partícula después de un pequeño intervalo de tiempo `dt`.

### 6.6: Agenda de Contactos

Definir `struct contacto_t` (nombre, telefono, email). Crear un programa que gestione una agenda (usando un arreglo dinámico de `contacto_t`) que permita añadir, buscar por nombre y eliminar contactos.

### 6.7: Alineación de Structs (`#pragma pack`)

Demostrar cómo la alineación de memoria afecta el `sizeof` de una `struct`. Crear una `struct` con miembros `char`, `int`, y `char`. Imprimir su tamaño. Luego, reordenar los miembros o usar `#pragma pack(1)` y volver a imprimir el tamaño para observar la diferencia.

### 6.8: Arreglos de Longitud Flexible

Demostrar el uso de un *flexible array member* en C99. Definir una `struct` que contenga un contador y un arreglo de longitud no especificada al final (ej. `int datos[]`). Escribir una función que reserve memoria para esta `struct` más `N` enteros adicionales para los datos.

### 6.9: Asignación de Structs y Copia Superficial

Crear una `struct` que contenga un puntero (`char*`). Asignar memoria para la `struct` y para el puntero. Luego, hacer una asignación directa (`struct_b = struct_a;`). Modificar la cadena a través de `struct_b` y mostrar que el cambio se refleja en `struct_a`, demostrando la copia superficial.

### 6.10: Puntero a Función en una Struct

Definir una `struct` `operacion_t` que contenga un puntero a una función que toma dos `int` y devuelve un `int`. Crear un arreglo de estas `structs` para implementar una calculadora donde cada `struct` representa una operación (ej. suma, resta).
