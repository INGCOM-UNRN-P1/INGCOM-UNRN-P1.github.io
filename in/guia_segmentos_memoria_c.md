````mystmd
# Guía de Segmentos de Memoria y Alcance de Variables en C

_Autor: El Profe Neckbeard - Compilando bits desde los tiempos del PDP-11_

---

## 📦 Introducción

Cuando un programa en C se ejecuta, el sistema operativo le asigna una porción de memoria para trabajar. Esta memoria está organizada en **segmentos** con propósitos específicos. Entender cómo se estructura esta memoria y cómo se almacenan las variables es fundamental para escribir programas eficientes, seguros y mantenibles.

Esta guía explica:

- Cómo está organizada la memoria de un programa en C.
- Qué tipos de variables existen según su alcance y duración.
- Cómo el compilador y el sistema gestionan estos elementos.

---

## 🧠 Organización de la Memoria en C

El espacio de direcciones de un programa típico en C se divide en varios **segmentos de memoria**. Cada segmento tiene una función específica y aloja distintos tipos de información.

```text
+------------------+ <- Dirección más alta (ej: 0xFFFFFFFF)
|      Stack       | <- Pila: variables locales, llamadas a funciones
+------------------+
|      Heap        | <- Memoria dinámica (¡no vista aquí aún!)
+------------------+
|   Segmento BSS   | <- Variables globales no inicializadas
+------------------+
| Segmento de Datos| <- Variables globales inicializadas
+------------------+
|  Segmento de Código  | <- Instrucciones de programa (funciones)
+------------------+ <- Dirección más baja (ej: 0x00000000)
````

### 📁 Segmento de Código (Text Segment)

Contiene el código ejecutable del programa, es decir, las instrucciones de máquina generadas por el compilador. Es común que este segmento sea de solo lectura para evitar que el programa se automodifique, lo cual sería un grave riesgo de seguridad.

Ejemplo:

```c
int suma(int a, int b) {
    return a + b;
}
```

La función `suma` reside en el segmento de código.

### 📂 Segmento de Datos (Data Segment)

Aquí se almacenan todas las variables globales o estáticas **que han sido inicializadas explícitamente**. Estas variables existen durante todo el tiempo de vida del programa. El segmento de datos es parte de la memoria estática.

Ejemplo:

```c
int global = 42; // Se guarda en el segmento de datos
```

### 📂 Segmento BSS

El segmento BSS (Block Started by Symbol) almacena variables globales o estáticas **que no han sido inicializadas explícitamente** por el programador. El sistema se encarga de inicializarlas a cero.

Ejemplo:

```c
static int contador; // Se guarda en BSS, y se inicializa en 0
```

### 🧱 Stack (Pila)

La pila es un segmento dinámico que crece hacia direcciones más bajas. Se utiliza para gestionar las llamadas a funciones, incluyendo:

- Los parámetros de la función.
- Las variables locales.
- La dirección de retorno (para saber dónde continuar luego de la función).

Cada llamada a función genera un **marco de pila** (stack frame), y al retornar de la función ese marco se destruye. Esta propiedad hace que las variables locales **desaparezcan automáticamente** al salir de su contexto.

Ejemplo:

```c
void funcion() {
    int local = 10; // Vive en el stack
}
```

### 🚫 Heap (Reservado)

Este segmento no será cubierto en detalle aquí, pero vale la pena saber que se usa para almacenar memoria dinámica, asignada en tiempo de ejecución. Usualmente se gestiona con funciones como `malloc` y `free`, y requiere punteros.

---

## 🔍 Alcance (Scope) y Duración (Lifetime) de Variables

En C, cada variable tiene dos atributos importantes:

- Su **alcance** (dónde se puede usar)
- Su **duración** (cuánto tiempo vive en memoria)

### 📌 Tipos de Alcance

| Alcance | Descripción                                            | Ejemplo                                  |
| ------- | ------------------------------------------------------ | ---------------------------------------- |
| Local   | Sólo visible dentro de una función o bloque            | `int x = 5;` dentro de `main()`          |
| Global  | Visible desde cualquier función del archivo            | `int g = 10;` fuera de funciones         |
| Bloque  | Visible sólo dentro del bloque `{}` donde fue definida | Declarada dentro de un `if`, `for`, etc. |

La visibilidad de una variable restringe qué funciones o bloques pueden acceder a ella. Esto es fundamental para evitar errores de programación, ya que limita el uso accidental de una variable donde no corresponde.

### ⏳ Tipos de Duración

| Duración   | Cuándo se crea                  | Cuándo se destruye       | Ejemplo                      |
| ---------- | ------------------------------- | ------------------------ | ---------------------------- |
| Automática | Al entrar a un bloque o función | Al salir del bloque      | Variables locales            |
| Estática   | Al inicio del programa          | Al finalizar el programa | Variables globales, `static` |

La duración determina cuánto tiempo la variable ocupa memoria. Las variables automáticas sólo viven mientras se ejecuta su bloque. Las estáticas existen todo el tiempo, aunque no siempre estén accesibles.

### 🎯 Modificador `static`

El modificador `static` cambia el **tiempo de vida** de una variable local para que se mantenga entre llamadas a la función.

```c
void ejemplo() {
    static int contador = 0; // Sólo se inicializa una vez
    contador++;
    printf("%d\n", contador);
}
```

Cada vez que se llama `ejemplo()`, el valor anterior de `contador` persiste. Es útil para mantener estado interno en funciones.

Si se usa `static` con variables globales, su visibilidad se limita al archivo actual.

---

## 📚 Variables Globales vs Locales

### Globales

- Están disponibles en cualquier función del archivo.
- Su valor persiste durante toda la ejecución del programa.
- Se almacenan en el segmento de datos o BSS.
- Si no se declara `static`, pueden ser accedidas desde otros archivos.

Ejemplo:

```c
int contadorGlobal = 0;
```

### Locales

- Sólo existen dentro de la función o bloque en que fueron declaradas.
- Se almacenan en la pila.
- Se destruyen automáticamente al finalizar la ejecución del bloque.

Ejemplo:

```c
void funcion() {
    int local = 123; // No visible fuera de "funcion"
}
```

---

## 🔒 Buenas Prácticas

- **Preferir variables locales** siempre que sea posible. Facilitan el razonamiento sobre el código.
- **Evitar variables globales**, salvo que su uso esté justificado (ej. configuración global).
- **Usar **``** para encapsular** variables dentro de funciones o archivos.
- **Inicializar todas las variables**: ayuda a prevenir errores sutiles o comportamiento indefinido.
- **Mantener funciones puras**: si es posible, que no modifiquen estado global.

---

## 🧙‍♂️ Sabiduría del Neckbeard

> "Entender cómo la memoria está segmentada es como entender el plano de tu castillo. Sólo así podrás defenderlo de dragones, bugs y segmentation faults."

---

## ✅ Ejercicio de Revisión

1. ¿Dónde se almacena una variable `int x = 5;` dentro de `main()`?
2. ¿Qué pasa si declaro `static int x = 0;` dentro de una función?
3. ¿Cuál es la diferencia entre `int x;` declarado globalmente y localmente?
4. ¿Qué ocurre con una variable global `int g;` no inicializada?
5. ¿Cuándo usarías `static` en una variable global?

---

## 🧩 Bonus Track: Variables Externas (extern)

El keyword `extern` permite referenciar una variable global que ha sido definida en **otro archivo fuente**. Se usa comúnmente en programas grandes donde el código está distribuido en varios archivos.

```c
// archivo1.c
int compartida = 42; // Definición

// archivo2.c
extern int compartida; // Declaración
```

Sin `extern`, intentar acceder a `compartida` en `archivo2.c` causaría un error de compilación.

---

## 📌 Conclusión

La gestión de memoria en C no es sólo una cuestión de optimización, es una cuestión de supervivencia. Comprender los segmentos de memoria, el alcance y duración de las variables es el primer paso para escribir código robusto y libre de errores sutiles.

Y recuerda:

> "Un buen C coder no deja variables sin inicializar, ni segmentos sin conocer."

```
```
