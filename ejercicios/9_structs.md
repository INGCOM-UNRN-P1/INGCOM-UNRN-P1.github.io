---
title: Ejercicios de structs
short_title: 9. structs
---

Ejercicios para modelar datos complejos utilizando estructuras (`struct`), desde conceptos básicos hasta aplicaciones más avanzadas en modelado de datos y algoritmos.

## 1: Fracciones

Desarrollar un tipo `fraccion_t` y las funciones necesarias para operar con fracciones. El objetivo es encapsular el numerador y el denominador en una única entidad.

```c
typedef struct {
    int numerador;
    int denominador;
} fraccion_t;
```

### 1.1: Operaciones Aritméticas

Implementar funciones que tomen dos fracciones y retornen el resultado de la operación.

- **Suma**: $$\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}$$
- **Resta**: $$\frac{a}{b} - \frac{c}{d} = \frac{ad - bc}{bd}$$
- **Multiplicación**: $$\frac{a}{b} \times \frac{c}{d} = \frac{ac}{bd}$$
- **División**: $$\frac{a}{b} \div \frac{c}{d} = \frac{ad}{bc}$$

### 1.2: Simplificación

Implementar una función que modifique una fracción para llevarla a su mínima expresión. La simplificación se realiza dividiendo numerador y denominador por su **Máximo Común Divisor (MCD)**.

## 2: División con Resto

La división entera en C (`/` y `%`) produce dos resultados. El objetivo es unificar estas operaciones en una única función que retorne una `struct` con el cociente y el resto, basándose en el algoritmo de la división.

$$dividendo = divisor \times cociente + resto, \quad \text{donde } 0 \le resto < |divisor|$$

```c
typedef struct {
    int cociente;
    int resto;
} division_t;

division_t division_lenta(int dividendo, int divisor);
```

## 3: Medición de Tiempo

Desarrollar una estructura `tiempo_t` para representar un instante o duración en horas, minutos y segundos, junto con funciones para manipularla.

```c
typedef struct {
    int horas;
    int minutos;
    int segundos;
} tiempo_t;
```

### 3.1: Suma de Tiempos

Implementar una función que sume dos `tiempo_t`. El resultado debe ser normalizado para que los segundos y minutos no excedan 59.

- $S_{total} = t_1.segundos + t_2.segundos$
- $M_{acarreo} = S_{total} / 60$
- $S_{resultado} = S_{total} \% 60$
- $M_{total} = t_1.minutos + t_2.minutos + M_{acarreo}$
- $H_{acarreo} = M_{total} / 60$
- $M_{resultado} = M_{total} \% 60$
- $H_{resultado} = t_1.horas + t_2.horas + H_{acarreo}$

### 3.2: Comparación de Tiempos

Implementar una función que compare dos `tiempo_t` y devuelva un valor que indique si el primero es anterior, igual o posterior al segundo. Una estrategia es convertir ambos tiempos a una unidad común (ej. segundos totales) para facilitar la comparación.

$$t_{en\_segundos} = horas \times 3600 + minutos \times 60 + segundos$$

## 4: Tipos de Datos Compuestos

### 4.1: Arreglos con Capacidad

Encapsular un arreglo en una estructura para agrupar el contenedor de datos, su longitud actual y su capacidad máxima. Esto previene errores de desbordamiento de búfer y simplifica pasar la información del arreglo a funciones.

```c
#define CAPACIDAD_MAX 100
typedef struct {
    int datos[CAPACIDAD_MAX];
    size_t longitud; // Elementos actualmente en uso
} arreglo_t;
```

Este ejercicio puede ser mejorado con memoria dinámica, para lo cual, es necesario agregar
un atributo mas con el tamaño en memoria pedido para `datos`.

### 4.2: Cadenas Seguras II

Aplicar el mismo principio a las cadenas de caracteres para crear un tipo `cadena_segura_t` que gestione su propia capacidad y longitud, evitando los peligros asociados a las cadenas de C estándar.

```c
#define CAPACIDAD_MAX_CADENA 256
typedef struct {
    char datos[CAPACIDAD_MAX_CADENA];
    size_t longitud;
} cadena_segura_t;
```

## 5: Modelado de Datos del Mundo Real

### 5.1: Punto y Círculo

Definir estructuras para representar un punto en un plano 2D y un círculo. Implementar funciones geométricas básicas.

- `struct punto_t { double x, y; }`
- `struct circulo_t { punto_t centro; double radio; }`

**Funciones:**
- **Distancia entre dos puntos** $P_1(x_1, y_1)$ y $P_2(x_2, y_2)$:
  $$d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$
- **Punto dentro de un círculo**: Un punto $P$ está dentro de un círculo si su distancia al centro es menor o igual al radio.
  $$distancia(P, C.centro) \le C.radio$$

### 5.2: Rectángulo

Definir un rectángulo mediante dos puntos opuestos (esquina superior izquierda e inferior derecha). Implementar funciones para calcular su área y perímetro.

- `struct rectangulo_t { punto_t sup_izq; punto_t inf_der; }`

**Fórmulas:**
- Ancho: $w = |inf\_der.x - sup\_izq.x|$
- Alto: $h = |sup\_izq.y - inf\_der.y|$
- Área: $A = w \times h$
- Perímetro: $P = 2(w + h)$

### 5.3: Estudiante y Curso

Modelar entidades de un dominio académico.

- `struct estudiante_t` (nombre, legajo, promedio)
- `struct curso_t` (nombre, un arreglo de estudiantes, cantidad de estudiantes)

**Funciones:**
- Añadir un estudiante a un curso (gestionando la capacidad del arreglo).
- Encontrar al estudiante con el mejor promedio del curso.
- Calcular el promedio general del curso:
  $$Promedio_{curso} = \frac{\sum_{i=1}^{N} promedio_i}{N}$$

### 5.4: Vector 3D

Definir una estructura para un vector en el espacio 3D y sus operaciones fundamentales.

- `struct vector3d_t { double x, y, z; }`

**Operaciones para vectores** $V_1(x_1, y_1, z_1)$ y $V_2(x_2, y_2, z_2)$:
- **Suma**: $V_1 + V_2 = (x_1+x_2, y_1+y_2, z_1+z_2)$
- **Resta**: $V_1 - V_2 = (x_1-x_2, y_1-y_2, z_1-z_2)$
- **Producto escalar**: $V_1 \cdot V_2 = x_1x_2 + y_1y_2 + z_1z_2$
- **Producto vectorial**: $V_1 \times V_2 = (y_1z_2 - z_1y_2, z_1x_2 - x_1z_2, x_1y_2 - y_1x_2)$
- **Magnitud (norma)**: $||V|| = \sqrt{x^2 + y^2 + z^2}$

### 5.5: Color RGB

Definir un color con componentes Rojo, Verde y Azul. Implementar una función que mezcle dos colores.

- `struct color_rgb_t { unsigned char r, g, b; }`

**Función de mezcla (promedio):**
- $R_{mezcla} = (C_1.r + C_2.r) / 2$
- $G_{mezcla} = (C_1.g + C_2.g) / 2$
- $B_{mezcla} = (C_1.b + C_2.b) / 2$

### 5.6: Libro de Biblioteca

Simular una pequeña biblioteca. Definir una estructura para un libro y gestionar una colección.

- `struct libro_t` (título, autor, ISBN, disponible)

**Funcionalidades:**
- Buscar un libro por título o ISBN en un arreglo de `libro_t`.
- Prestar un libro (cambiar su estado a no disponible).
- Devolver un libro (cambiar su estado a disponible).

### 5.7: Fecha

Definir una estructura para una fecha y una función que la incremente en un día, manejando meses y años bisiestos.

- `struct fecha_t { int dia, mes, anio; }`

**Regla de año bisiesto:** Un año es bisiesto si es divisible por 4, a menos que sea divisible por 100 pero no por 400.
$$((anio \% 4 == 0) \land (anio \% 100 \neq 0)) \lor (anio \% 400 == 0)$$

### 5.8: Polinomio

Representar un polinomio y evaluarlo eficientemente.

- `struct polinomio_t` (grado, puntero a coeficientes `double*`)

**Función de evaluación (Método de Horner):** Para un polinomio $P(x) = a_n x^n + \dots + a_1 x + a_0$, el método consiste en reescribirlo como:
$$P(x) = a_0 + x(a_1 + x(a_2 + \dots + x(a_{n-1} + a_n x)\dots))$$ 
Esto reduce el número de multiplicaciones y es numéricamente más estable.

### 5.9: Número Complejo

Definir una estructura para números complejos y sus operaciones aritméticas.

- `struct complejo_t { double real, imag; }`

**Operaciones para** $C_1 = a+bi$ y $C_2 = c+di$:
- **Suma**: $(a+c) + (b+d)i$
- **Resta**: $(a-c) + (b-d)i$
- **Multiplicación**: $(ac - bd) + (ad + bc)i$
- **División**: $\frac{C_1}{C_2} = \left(\frac{ac+bd}{c^2+d^2}\right) + \left(\frac{bc-ad}{c^2+d^2}\right)i$

### 5.10: Inventario de Producto

Modelar un producto para un sistema de inventario.

- `struct producto_t` (código, descripción, precio, stock)

**Programa de gestión:** Crear un programa que use un arreglo de `producto_t` para:
- Añadir nuevos productos.
- Buscar un producto por su código.
- Actualizar el stock de un producto.
- Eliminar un producto del inventario.

### 5.11: `struct` Anidada (Dirección)

Demostrar la composición de `structs` anidando una dentro de otra.

- `struct direccion_t` (calle, numero, ciudad, codigo_postal)
- `struct persona_t` (nombre, edad, `direccion_t` direccion)

**Función:** Escribir una función que reciba una `persona_t` e imprima todos sus datos, incluyendo la dirección completa.

### 5.12: Campos de Bits (Bitfields)

Utilizar campos de bits para empaquetar datos de forma eficiente a nivel de bits, ideal para representar flags o estados con memoria mínima.

**Ejercicio:** Definir una `struct` que use campos de bits para almacenar 8 banderas booleanas (flags) en un solo `unsigned char`. Demostrar cómo establecer, limpiar y verificar el estado de un bit individual.

### 5.13: Uniones (`union`)

Explorar el uso de uniones para que una variable pueda almacenar diferentes tipos de datos en el mismo espacio de memoria.

**Ejercicio:** Definir una `union valor_t` que pueda ser un `int`, `float` o `char*`. Crear una `struct variable_t` que contenga un `enum` para el tipo y la `union valor_t`. Esto se conoce como "unión etiquetada" y permite un polimorfismo rudimentario en C.

### 5.14: `typedef` con `struct` Anónima

Mostrar una forma común y concisa de definir un tipo de `struct` usando `typedef` directamente con una `struct` anónima.

**Ejercicio:** Definir un tipo `punto_t` usando `typedef struct { double x, y; } punto_t;`. Comparar esta sintaxis con la alternativa de dos pasos (`struct punto_t { ... }; typedef struct punto_t punto_t;`).

### 5.15: Comparación de `structs`

Implementar una función para comparar si dos `structs` son idénticas.

**Ejercicio:** Implementar `bool son_iguales(persona_t p1, persona_t p2)` (usando la `struct` del ejercicio 5.11). La igualdad requiere que todos los campos, incluyendo los de la `struct` anidada `direccion_t`, sean idénticos.

## 6: Más Estructuras de Datos y Algoritmos

### 6.1: Mazo de Cartas

Modelar un mazo de cartas de póker.

- `struct carta_t` (palo, valor) donde `palo` y `valor` pueden ser `enum`.
- `struct mazo_t` (un arreglo de 52 `carta_t`).

**Funciones:**
- `crear_mazo()`: Genera un mazo ordenado con las 52 cartas.
- `barajar_mazo(mazo_t* mazo)`: Desordena las cartas aleatoriamente (ej. algoritmo de Fisher-Yates).
- `repartir_carta(mazo_t* mazo)`: Devuelve la carta de arriba del mazo y actualiza el estado del mazo.

### 6.2: Nodo de Lista Enlazada

Implementar la estructura de datos fundamental para una lista enlazada simple.

- `struct nodo_t { int dato; struct nodo_t* siguiente; }`

**Funciones básicas:**
- `insertar_al_principio(struct nodo_t** cabeza, int dato)`
- `imprimir_lista(struct nodo_t* cabeza)`
- `liberar_lista(struct nodo_t** cabeza)`

### 6.3: Nodo de Árbol Binario

Implementar la estructura de un nodo para un árbol binario.

- `struct arbol_nodo_t { int dato; struct arbol_nodo_t* izq; struct arbol_nodo_t* der; }`

**Funciones para un Árbol de Búsqueda Binaria (BST):**
- `insertar_nodo(struct arbol_nodo_t** raiz, int dato)`
- `imprimir_in_order(struct arbol_nodo_t* raiz)` (recorrido en orden: izquierda, raíz, derecha)

### 6.4: Transacción Bancaria

Modelar una cuenta bancaria con un historial de transacciones de tamaño dinámico.

- `struct transaccion_t` (fecha, tipo, monto)
- `struct cuenta_t` (nro_cuenta, saldo, `transaccion_t*` historial, `size_t` num_transacciones)

**Función clave:** Implementar una función que agregue una transacción a una cuenta, actualice el saldo y use `realloc` para agrandar el arreglo del historial de transacciones.

### 6.5: Partícula en Simulación Física

Modelar una partícula simple para una simulación física.

- `struct particula_t` (posición, velocidad, aceleración, todas de tipo `vector3d_t` del ejercicio 5.4).

**Función de actualización (Integración de Euler):**
Implementar `actualizar_estado(particula_t* p, double dt)` que actualice la posición y velocidad después de un intervalo de tiempo `dt`.
- $v_{final} = v_{inicial} + a \cdot dt$
- $p_{final} = p_{inicial} + v_{inicial} \cdot dt$

### 6.6: Agenda de Contactos

Gestionar una agenda de contactos usando un arreglo dinámico.

- `struct contacto_t` (nombre, telefono, email)

**Programa de gestión:** Crear un programa que permita añadir, buscar por nombre y eliminar contactos de un arreglo dinámico de `contacto_t`, usando `realloc` para ajustar su tamaño.

### 6.7: Alineación de Structs (`#pragma pack`)

Investigar cómo el compilador organiza los miembros de una `struct` en memoria y el impacto en su tamaño total (`sizeof`).

**Ejercicio:** Crear una `struct` con miembros `char`, `int`, y `char`. Imprimir su `sizeof`. Luego, reordenar los miembros para agruparlos por tamaño o usar la directiva `#pragma pack(1)` y volver a imprimir el tamaño para observar cómo el *padding* (relleno) de memoria es eliminado o reducido.

### 6.8: Arreglos de Longitud Flexible

Explorar la característica de C99 que permite declarar un arreglo como último miembro de una `struct` sin un tamaño fijo.

**Ejercicio:** Definir `struct texto_t { size_t longitud; char contenido[]; }`. Escribir una función que reserve memoria para esta `struct` más `N` caracteres adicionales para el `contenido`, demostrando cómo crear objetos de tamaño variable.

### 6.9: Asignación de Structs y Copia Superficial

Demostrar el comportamiento por defecto de la asignación de `structs` que contienen punteros.

**Ejercicio:** Crear una `struct` que contenga un `char*`. Asignar memoria para la `struct` y para el puntero (`malloc`). Luego, crear una segunda `struct` y asignarle la primera (`struct_b = struct_a;`). Modificar la cadena a través de `struct_b` y mostrar que el cambio se refleja en `struct_a`, evidenciando que solo se copió el puntero (copia superficial), no los datos a los que apunta.

### 6.10: Puntero a Función en una Struct

Usar punteros a funciones dentro de `structs` para asociar datos con comportamiento (un pilar de la programación orientada a objetos).

**Ejercicio:** Definir `typedef int (*operacion_func)(int, int);`. Crear `struct operacion_t { char simbolo; operacion_func func; }`. Implementar un arreglo de `operacion_t` para una calculadora, donde cada elemento contiene el símbolo (`+`, `-`, etc.) y el puntero a la función correspondiente.