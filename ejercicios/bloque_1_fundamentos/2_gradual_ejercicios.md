---
title: Ejercicios de Entrada y Salida Gradual
short_title: 2. Entrada/Salida Gradual
---

# Ejercicios de Entrada y Salida Gradual

## Acerca de

Estos ejercicios tienen como fin afianzar las operaciones de entrada y salida
básica en C empleando `printf` y `scanf`, promoviendo la declaración e
inicialización correcta de variables con tipos primitivos básicos.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-introduccion-c`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Función principal `main` y tipo de retorno `int` ({ref}`capitulo-introduccion-c`).
2. Declaración e inicialización estricta de tipos de datos primitivos (`int`, `float`, `char`).
3. Especificadores de formato para salida con `printf` (`%d`, `%.2f`, `%c`).
4. Especificadores de formato y validación de retorno de lectura segura con `scanf` y `sscanf`.

### Cuestiones de Estilo Aplicables
- **Inicialización de Variables:** De acuerdo con la {ref}`0x7001h`, siempre se deben inicializar las
  variables a un valor conocido en su declaración.
- **Robustez en Entrada de Datos:** Al utilizar `scanf`, se debe validar su
  valor de retorno y realizar el purgado del buffer de entrada cuando sea
  necesario para evitar comportamientos indefinidos (ver {ref}`0x1005h`).

---

## Lectura y Escritura Básica

(ej_b1_c02_01)=
### Ejercicio 1.02.01 - Declaración e Inicialización de Tipos Primitivos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c02_01_valores

Escribí un programa en C11 que declare e inicialice variables para una edad
(`int`), una altura en metros (`float`) y la inicial del nombre (`char`),
formateando los valores en un búfer o en la salida estándar respetando las
reglas de inicialización estricta.

**Tabla de Vectores de Prueba:**

| Variable | Tipo | Valor Inicializado | Especificador `printf` | Salida Formateada |
| :--- | :--- | :--- | :--- | :--- |
| `edad` | `int` | `20` | `%d` | `Edad: 20` |
| `altura` | `float` | `1.82f` | `%.2f` | `Altura: 1.82` |
| `inicial` | `char` | `'J'` | `%c` | `Inicial: J` |

::::{solution}
```c
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void) {
    int edad = 20;
    float altura = 1.82f;
    char inicial = 'J';

    char buffer[128] = {0};
    int escritos = snprintf(buffer, sizeof(buffer), "Edad: %d, Altura: %.2f, Inicial: %c", edad, (double)altura, inicial);
    assert(escritos > 0 && escritos < (int)sizeof(buffer));
    assert(strcmp(buffer, "Edad: 20, Altura: 1.82, Inicial: J") == 0);

    return 0;
}
```
::::
:::

(ej_b1_c02_02)=
### Ejercicio 1.02.02 - Validación de Formato de Entrada ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c02_02_entrada

Diseñá una función pura que procese una cadena de entrada simulando la lectura
de inicial, edad y promedio, validando que los tres campos se analicen
correctamente y rechazando entradas malformadas.

```c
bool parsear_datos(const char *entrada, char *inicial, int *edad, float *promedio);
```

**Tabla de Vectores de Prueba:**

| Cadena de Entrada | Retorno Esperado | Valores Parseados |
| :--- | :--- | :--- |
| `"J 20 8.75"` | `true` | `inicial='J', edad=20, promedio=8.75` |
| `"M 25"` (incompleta) | `false` | Inalterados o rechazados |
| `""` (vacía) | `false` | Retorno `false` |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool parsear_datos(const char *entrada, char *inicial, int *edad, float *promedio) {
    if (entrada == NULL || inicial == NULL || edad == NULL || promedio == NULL) {
        return false;
    }
    int leidos = sscanf(entrada, " %c %d %f", inicial, edad, promedio);
    return leidos == 3;
}

int main(void) {
    char ini = ' ';
    int ed = 0;
    float prom = 0.0f;

    assert(parsear_datos("J 20 8.75", &ini, &ed, &prom));
    assert(ini == 'J');
    assert(ed == 20);
    assert(prom > 8.74f && prom < 8.76f);

    assert(!parsear_datos("M 25", &ini, &ed, &prom));
    assert(!parsear_datos("", &ini, &ed, &prom));
    assert(!parsear_datos(NULL, &ini, &ed, &prom));

    return 0;
}
```
::::
:::

(ej_b1_c02_03)=
### Ejercicio 1.02.03 - Determinación de Paridad ⭐☆☆☆☆

:::{exercise}
:label: ej_b1_c02_03_paridad

Implementá una función pura que determine si un número entero es par:
```c
bool es_par(int numero);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Número Entrada | Retorno Esperado | Justificación |
| :--- | :--- | :--- | :--- |
| Par positivo | `42` | `true` | `42 % 2 == 0` |
| Impar positivo | `17` | `false` | `17 % 2 != 0` |
| Cero | `0` | `true` | `0 % 2 == 0` |
| Par negativo | `-8` | `true` | `-8 % 2 == 0` |
| Impar negativo | `-9` | `false` | `-9 % 2 != 0` |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool es_par(int numero) {
    return (numero % 2) == 0;
}

int main(void) {
    assert(es_par(42) == true);
    assert(es_par(17) == false);
    assert(es_par(0) == true);
    assert(es_par(-8) == true);
    assert(es_par(-9) == false);

    return 0;
}
```
::::
:::

---

(ej_b1_c02_04)=
### Ejercicio 1.02.04 - Mayor de Tres Números ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c02_04_mayor_tres

Implementá una función pura que determine el valor máximo entre tres números enteros:
```c
int mayor_de_tres(int a, int b, int c);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada `(a, b, c)` | Retorno Esperado | Justificación |
| :--- | :--- | :--- | :--- |
| Primero mayor | `(30, 10, 20)` | `30` | `30 > 10` y `30 > 20` |
| Segundo mayor | `(5, 50, -2)` | `50` | `50` es el máximo |
| Tercero mayor | `(-10, -5, 0)` | `0` | `0` supera a los negativos |
| Todos iguales | `(7, 7, 7)` | `7` | Valor común |

::::{solution}
```c
#include <stdio.h>
#include <assert.h>

int mayor_de_tres(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int main(void) {
    assert(mayor_de_tres(30, 10, 20) == 30);
    assert(mayor_de_tres(5, 50, -2) == 50);
    assert(mayor_de_tres(-10, -5, 0) == 0);
    assert(mayor_de_tres(7, 7, 7) == 7);
    return 0;
}
```
::::
:::

(ej_b1_c02_05)=
### Ejercicio 1.02.05 - Determinación de Año Bisiesto ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c02_05_bisiesto

Implementá una función que determine si un año del calendario gregoriano es bisiesto:
- Un año es bisiesto si es divisible por 4.
- Excepto si es divisible por 100, salvo que también sea divisible por 400.
- Años menores o iguales a 0 se consideran inválidos y retornan `false`.

```c
bool es_bisiesto(int anio);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Año Entrada | Retorno Esperado | Regla Aplicada |
| :--- | :--- | :--- | :--- |
| Secundario bisiesto | `2024` | `true` | Divisible por 4 y no por 100 |
| Fin de siglo común | `1900` | `false` | Divisible por 100 pero no por 400 |
| Fin de siglo bisiesto | `2000` | `true` | Divisible por 400 |
| Año común | `2023` | `false` | No divisible por 4 |
| Año no positivo | `-4` | `false` | Rechazo por contrato |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool es_bisiesto(int anio) {
    if (anio <= 0) {
        return false;
    }
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int main(void) {
    assert(es_bisiesto(2024) == true);
    assert(es_bisiesto(1900) == false);
    assert(es_bisiesto(2000) == true);
    assert(es_bisiesto(2023) == false);
    assert(es_bisiesto(0) == false);
    assert(es_bisiesto(-4) == false);

    return 0;
}
```
::::
:::

---

(ej_b1_c02_06)=
## Ejercicio 1.02.06 - Calificación a Letra ⭐⭐☆☆☆

Convertí una calificación numérica (0-100) a letra (A, B, C, D, F).

**Escala:**
- 90-100: A
- 80-89: B
- 70-79: C
- 60-69: D
- 0-59: F

**Orientación:**
- Usá `if-else if-else` encadenados
- Verificá que la calificación esté en rango 0-100
- Opcionalmente, usá `switch` dividiendo por 10

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_07)=
## Ejercicio 1.02.07 - Calculadora con Menú ⭐⭐⭐☆☆

Implementá una calculadora que muestre un menú y ejecute la operación elegida.

**Menú:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

```
1. Sumar
2. Restar
3. Multiplicar
4. Dividir
5. Salir
```

**Orientación:**
- Usá `switch` para el menú
- Verificá división por cero
- Permití múltiples operaciones (lazo)

---

(ej_b1_c02_08)=
## Ejercicio 1.02.08 - Triángulo Válido ⭐⭐⭐☆☆

Dados tres lados, determiná si forman un triángulo válido y qué tipo es
(equilátero, isósceles, escaleno).

**Orientación:**
- Para ser válido: a + b > c, a + c > b, b + c > a
- Equilátero: los tres lados iguales
- Isósceles: dos lados iguales
- Escaleno: todos diferentes

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_09)=
## Ejercicio 1.02.09 - Mes del Año ⭐⭐⭐☆☆

Dado un número de mes (1-12), mostrá su nombre y cantidad de días.

**Orientación:**
- Usá `switch` para el mes
- Considerá febrero con 28 días (ignorar bisiesto por ahora)
- Manejá entradas inválidas (fuera de 1-12)

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_10)=
## Ejercicio 1.02.10 - Signo Zodiacal ⭐⭐⭐☆☆

Dados día y mes de nacimiento, determiná el signo zodiacal.

**Orientación:**
- Usá múltiples condiciones sobre mes y día
- Ejemplo: Aries es del 21/03 al 19/04
- Validá fechas (día válido para cada mes)

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_11)=
## Ejercicio 1.02.11 - Ordenar Tres Números ⭐⭐⭐☆☆

Leé tres números y mostralos ordenados de menor a mayor.

**Orientación:**
- Compará los tres números entre sí
- Intercambiá valores si es necesario
- Podés usar variables temporales
- Alternativa: usar comparaciones múltiples sin intercambio

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_12)=
## Ejercicio 1.02.12 - Vocales y Consonantes ⭐⭐⭐☆☆

Leé un carácter y determiná si es vocal, consonante, dígito u otro símbolo.

**Orientación:**
- Usá `switch` con múltiples casos para vocales
- Verificá si es letra con `isalpha()` de `<ctype.h>`
- Verificá si es dígito con `isdigit()`
- Considerá mayúsculas y minúsculas

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_13)=
## Ejercicio 1.02.13 - Ecuación de Primer Grado ⭐⭐⭐☆☆

Resolvé ecuaciones de la forma ax + b = 0.

**Casos:**
- Si a = 0 y b = 0: infinitas soluciones
- Si a = 0 y b ≠ 0: sin solución
- Si a ≠ 0: x = -b/a

**Orientación:**
- Manejá los tres casos con `if-else`
- Mostrá mensajes descriptivos para cada caso

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_14)=
## Ejercicio 1.02.14 - Clasificación de IMC ⭐⭐⭐☆☆

Calculá el IMC y clasificá según la categoría.

**Categorías:**
- < 18.5: Bajo peso
- 18.5-24.9: Normal
- 25-29.9: Sobrepeso
- 30-34.9: Obesidad I
- 35-39.9: Obesidad II
- ≥ 40: Obesidad III

**Orientación:**
- Calculá IMC = peso / (altura²)
- Usá `if-else if` para clasificar
- Validá que altura > 0

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_15)=
## Ejercicio 1.02.15 - Conversor de Calificaciones ⭐⭐⭐⭐☆

Convertí entre diferentes sistemas de calificación: numérica (0-10), letra
(A-F), porcentaje (0-100).

**Orientación:**
- Mostrá menú para elegir conversión
- Implementá funciones de mapeo para cada conversión
- Validá rangos de entrada

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_16)=
## Ejercicio 1.02.16 - Operaciones con Fechas ⭐⭐⭐⭐☆

Dadas dos fechas (día, mes, año), determiná cuál es anterior.

**Orientación:**
- Compará primero años, luego meses, finalmente días
- Validá que ambas fechas sean válidas
- Considerá años bisiestos para febrero

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_17)=
## Ejercicio 1.02.17 - Calculadora de Impuestos ⭐⭐⭐⭐☆

Calculá impuesto a las ganancias según tramos.

**Ejemplo de tramos:**
- $0 - $10,000: 0%
- $10,001 - $30,000: 10%
- $30,001 - $60,000: 15%
- $60,001+: 20%

**Orientación:**
- Calculá impuesto acumulativo por tramo
- No apliques tasa mayor al monto total, solo al excedente
- Mostrá salario neto (bruto - impuesto)

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_18)=
## Ejercicio 1.02.18 - Validador de Tarjeta de Crédito ⭐⭐⭐⭐☆

Implementá el algoritmo de Luhn para validar números de tarjeta.

**Algoritmo:**
1. De derecha a izquierda, duplicá cada segundo dígito
2. Si el resultado > 9, restá 9
3. Sumá todos los dígitos
4. Si suma % 10 = 0, es válida

**Orientación:**
- Procesá el número dígito por dígito
- Usá división y módulo para extraer dígitos
- Implementá sin arrays (solo con variables)

:::{hint} Lógica y Consideraciones
filas (*row-major order*) para mejorar el uso de caché.
    estrictamente dentro de los límites del contenedor.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_19)=
## Ejercicio 1.02.19 - Juego de Adivinanza ⭐⭐⭐⭐☆

El programa elige un número aleatorio entre 1 y 100. El usuario adivina y recibe
pistas ("muy alto", "muy bajo").

**Orientación:**
- Usá `rand()` de `<stdlib.h>`
- Inicializá semilla con `srand(time(NULL))`
- Contá intentos
- Usá lazo `while` hasta acertar o límite de intentos

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_20)=
## Ejercicio 1.02.20 - Conversor de Números Romanos ⭐⭐⭐⭐⭐

Convertí un número decimal (1-3999) a números romanos.

**Símbolos:** I=1, V=5, X=10, L=50, C=100, D=500, M=1000

**Orientación:**
- Procesá de mayor a menor: miles, cientos, decenas, unidades
- Manejá casos especiales: 4 (IV), 9 (IX), 40 (XL), 90 (XC), etc.
- Usá múltiples `if` o `switch` por cada orden de magnitud

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_21)=
## Ejercicio 1.02.21 - Calculadora de Tiempo ⭐⭐⭐⭐⭐

Realizá operaciones con tiempos en formato HH:MM:SS (sumar, restar, comparar).

**Operaciones:**
- Sumar dos tiempos
- Restar dos tiempos
- Comparar cuál es mayor

**Orientación:**
- Convertí todo a segundos para operar
- Después convertí de vuelta a HH:MM:SS
- Manejá acarreo (60 segundos = 1 minuto, etc.)
- Validá formato de entrada

:::{hint} Lógica y Consideraciones
valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c02_22)=
## Ejercicio 1.02.22 - Sistema de Menú Multinivel ⭐⭐⭐⭐⭐

Implementá un sistema de menús con submenús.

**Estructura:**

:::{hint} Lógica y Consideraciones
desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.
:::
<!-- {hint} Lógica y Consideraciones -->

```
MENÚ PRINCIPAL
1. Calculadora
   1.1. Básica
   1.2. Científica
2. Conversiones
   2.1. Temperatura
   2.2. Distancia
3. Salir
```

**Orientación:**
- Usá `switch` anidados
- Implementá navegación hacia atrás
- Validá opciones en cada nivel
- Mantené el programa en lazo hasta "Salir"

---

## Notas Finales

:::{tip} Buenas Prácticas

- **Validación constante:** Verificá siempre que la entrada esté en el rango
  esperado
- **Mensajes claros:** Informá al usuario qué salió mal y qué se espera
- **Casos extremos:** Probá con valores mínimos, máximos, cero y negativos
- **Claridad:** Usá nombres de variables descriptivos (`es_vocal` en lugar de
  `v`)

:::
<!-- {tip} Buenas Prácticas -->

:::{note} Operadores Útiles

- **Relacionales:** `<`, `>`, `<=`, `>=`, `==`, `!=`
- **Lógicos:** `&&` (AND), `||` (OR), `!` (NOT)
- **Condicionales:** `if`, `else if`, `else` para bifurcar el flujo de ejecución

:::
<!-- {note} Operadores Útiles -->

Estas consignas cubren estructuras de control, toma de decisiones, validación de
datos y lógica condicional compleja.

