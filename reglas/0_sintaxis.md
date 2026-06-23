---
title: Sintaxis Básica y Nomenclatura
short_title: Sintaxis y Nomenclatura
subtitle: Reglas de estilo para el formato visual y nombres en C
---

# 1. Sintaxis Básica y Nomenclatura (`0x00XX`)

(0x0000h)=
## Regla `0x0000h`: La claridad y prolijidad son de máxima importancia

El código debe ser claro y fácil de entender para cualquier lector, no solo para su autor. Un código limpio y prolijo previene errores, facilita el mantenimiento y mejora la colaboración en equipo. La claridad es siempre preferible a técnicas de programación ofuscadas que solo complican la comprensión.

```diff
- for (int i = 0, j = 10; i < j; i++, j--) { printf("%d", i+j); }
+ int i = 0;
+ int j = 10;
+ while (i < j)
+ {
+     printf("%d", i + j);
+     i++;
+     j--;
+ }
```

(0x0001h)=
## Regla `0x0001h`: Los identificadores deben ser descriptivos

Los nombres de variables, funciones y demás identificadores deben reflejar con precisión su propósito. Esto contribuye a que el código sea autodescriptivo, minimizando la necesidad de comentarios adicionales. El uso de nombres significativos facilita la lectura y la comprensión.

- Identificadores inadecuados:

```c
int a, b;
a = obtener_precio();
b = calcular_descuento(a);
```

- Identificadores adecuados:

```c
int precio, descuento;
precio = obtener_precio();
descuento = calcular_descuento(precio);
```

#### Sin embargo, no debés temer el uso de nombres de variables cortos

Bajo ciertas condiciones, los nombres cortos son aceptables y hasta preferibles:

1.  Si el ámbito de la variable es reducido (visible en una sola pantalla).
2.  Si la variable se utiliza con alta frecuencia en ese ámbito.
3.  Si existe un identificador de una o dos letras cuyo significado es obvio en el contexto (matemático, contadores, etc.).

Probá y observá si el nombre corto contribuye a la legibilidad.

El ejemplo canónico es el uso de `i` y `j` como variables de control en lazos. Otras situaciones se presentan al implementar algoritmos matemáticos donde la notación es estándar.

(0x0002h)=
## Regla `0x0002h`: Una declaración de variable por línea

```diff
-int a, b, c;
+int a;
+int b;
+int c;
```

(0x0003h)=
## Regla `0x0003h`: Siempre debés inicializar las variables a un valor conocido

Es imperativo que una variable utilizada como R-Value contenga un valor conocido antes de su uso.

Aunque un sistema operativo moderno pueda inicializar la memoria en `0`, la reutilización de la misma puede introducir valores residuales. No debés confiar en una inicialización implícita.

- Incorrecto:

```c
int contador;
```

- Correcto:

```c
int contador = 0;
```

:::{note} Opciones de compilación

El compilador le advertirá sobre el uso de variables sin inicializar, pero solo si activás las verificaciones y mensajes adicionales correspondientes.

:::

#### Esto incluye evitar inicializaciones implícitas en estructuras.

- Incorrecto:

```c
struct Datos datos;
```

- Correcto:

```c
struct Datos datos = {0};
```

(0x0004h)=
## Regla `0x0004h`: Un espacio antes y después de cada operador binario

```diff
-uno=dos+tres;
+uno = dos + tres;
```

- **Incorrecto:**
  ```c
  resultado=valor1*valor2+offset;
  ```
- **Correcto:**
  ```c
  resultado = valor1 * valor2 + offset;
  ```

(0x0005h)=
## Regla `0x0005h`: Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves

Esto permite una alineación consistente y mejora la legibilidad de la estructura del código.

- **Incorrecto (indentación inconsistente):**
```c
void funcion() {
int x = 10;
if (x > 5) {
        printf("Mayor");
    }
}
```
- **Correcto (indentación de 4 espacios):**
```c
void funcion() {
    int x = 10;
    if (x > 5) {
        printf("Mayor");
    }
}
```

Esto aplica incluso para bloques de una sola línea.
```diff
- if (condicion) accion;
+ if (condicion) {
+     accion;
+ }
```

(0x0006h)=
## Regla `0x0006h`: El asterisco de los punteros debe declararse junto al identificador

Esta convención facilita la identificación visual de una variable como puntero y mejora la claridad.

```diff
-int* ptr;
+int *ptr;
```

(0x0007h)=
## Regla `0x0007h`: Los argumentos de función y las variables locales deben usar `snake_case` en minúsculas

- **Incorrecto:**
  ```c
  int miVariable;
  void miFuncion(int UnArgumento) { /* ... */ }
  ```
- **Correcto:**
  ```c
  int mi_variable;
  void mi_funcion(int un_argumento) { /* ... */ }
  ```

(0x0008h)=
## Regla `0x0008h`: Las constantes (`const` o `#define`) deben nombrarse en `MAYUSCULAS_SNAKE_CASE`

Esta convención de estilo de nomenclatura mejora la legibilidad. Un identificador en mayúsculas actúa como una señal visual inmediata, indicando que se trata de un valor inmutable.

- **Incorrecto:**
  ```c
  const int diasDeLaSemana = 7;
  #define pi 3.14159f
  ```
- **Correcto:**
  ```c
  const int DIAS_DE_LA_SEMANA = 7;
  #define PI 3.14159f

  float calcular_circunferencia(float radio) {
      return 2 * PI * radio;
  }
  ```

(0x0009h)=
## Regla `0x0009h`: Las líneas de código no deben exceder los 79 caracteres

Nunca debés escribir líneas que excedan los 79 caracteres. El límite de 80 columnas es un estándar de facto que facilita la lectura y la visualización de código en paralelo. Las líneas largas fatigan la vista y requieren desplazamiento horizontal.

- **Incorrecto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que definitivamente excede el límite de 79 caracteres y hace que el código sea mucho más difícil de leer para otros desarrolladores.\n");
  ```
- **Correcto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que se divide "
         "en múltiples líneas para cumplir con el estándar de 80 columnas.\n");
  ```

(0x000Ah)=
## Regla `0x000Ah`: Escribí comentarios que expliquen el "porqué", no el "qué"

Los comentarios deben aportar valor y aclarar la intención detrás del código, no parafrasear lo que el código ya expresa de forma evidente. El código en sí mismo debe ser lo suficientemente claro para explicar *qué* hace.

- **Incorrecto (Comentario obvio y redundante):**
  ```c
  // Incrementa i en 1
  i++;
  ```
- **Correcto (Comentario que explica la intención):**
  ```c
  // Se utiliza un índice inverso para procesar los elementos desde el final,
  // ya que el último elemento tiene un significado especial en el protocolo.
  for (size_t i = tamano - 1; i < tamano; i--) {
      // ...
  }
  ```