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

### Cuestiones de Estilo Aplicables
- **Inicialización de Variables:** De acuerdo con la [Regla
  0x0003h](../../reglas/0_sintaxis.md#0x0003h), siempre se deben inicializar las
  variables a un valor conocido en su declaración.
- **Robustez en Entrada de Datos:** Al utilizar `scanf`, se debe validar su
  valor de retorno y realizar el purgado del buffer de entrada cuando sea
  necesario para evitar comportamientos indefinidos (ver [Regla
  0x1005h](../../reglas/1_control.md#0x1005h)).

---

## Lectura y Escritura Básica
(ejercicio_2_1)=
### Ejercicio 2.1 - Mostrando valores ⭐⭐☆☆☆

:::{exercise}
:label: Mostrando valores
:enumerator: Valores
Escribí un programa en C que declare e inicialice variables para tu edad, tu
altura en metros y tu inicial de nombre, y muestre sus valores en la consola.

:::
<!-- {exercise} -->

:::{solution} Mostrando valores
:class: dropdown

```{code-block} c
:linenos:

#include <stdio.h>

int main(void) {
    int edad = 20;
    float altura = 1.82f;
    char inicial = 'J';

    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} Mostrando valores -->
(ejercicio_2_2)=
### Ejercicio 2.2 - Formateo de entrada y salida ⭐⭐☆☆☆

:::{exercise}
:label: entrada-1
Pedí al usuario que ingrese su inicial de nombre, edad y calificación promedio,
y mostralos formateados en pantalla.

:::
<!-- {exercise} -->

:::{solution} entrada-1
:class: dropdown
```{code-block} c
:linenos:

#include <stdio.h>

int main(void) {
    char inicial = ' ';
    int edad = 0;
    float promedio = 0.0f;

    printf("Ingrese su inicial: ");
    if (scanf(" %c", &inicial) != 1) {
        printf("Error al leer la inicial.\n");
        return 1;
    }

    printf("Ingrese su edad: ");
    if (scanf("%d", &edad) != 1) {
        printf("Error al leer la edad.\n");
        return 1;
    }

    printf("Ingrese su promedio: ");
    if (scanf("%f", &promedio) != 1) {
        printf("Error al leer el promedio.\n");
        return 1;
    }

    printf("Inicial: %c, Edad: %d, Promedio: %.2f\n", inicial, edad, promedio);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} entrada-1 -->
(ejercicio_2_3)=
## Ejercicio 2.3 - Par o Impar ⭐☆☆☆☆

Determiná si un número entero es par o impar.

**Orientación:**
- Usá el operador módulo `%`
- Si `numero % 2 == 0`, es par
- Considerá números negativos (funcionan igual)

---
(ejercicio_2_4)=
## Ejercicio 2.4 - Mayor de Tres Números ⭐⭐☆☆☆

Leé tres números y determiná cuál es el mayor.

**Orientación:**
- Usá `if-else` anidados o encadenados
- Compará primero dos números, luego el mayor con el tercero
- Considerá el caso de números iguales

---
(ejercicio_2_5)=
## Ejercicio 2.5 - Año Bisiesto ⭐⭐☆☆☆

Determiná si un año es bisiesto.

**Reglas:**
- Divisible por 4: bisiesto
- **Excepto** si es divisible por 100: no bisiesto
- **Excepto** si es divisible por 400: bisiesto

**Orientación:**
- Usá operadores lógicos `&&` y `||`
- Condición: `(año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)`

---
(ejercicio_2_6)=
## Ejercicio 2.6 - Calificación a Letra ⭐⭐☆☆☆

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

---
(ejercicio_2_7)=
## Ejercicio 2.7 - Calculadora con Menú ⭐⭐⭐☆☆

Implementá una calculadora que muestre un menú y ejecute la operación elegida.

**Menú:**
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
(ejercicio_2_8)=
## Ejercicio 2.8 - Triángulo Válido ⭐⭐⭐☆☆

Dados tres lados, determiná si forman un triángulo válido y qué tipo es
(equilátero, isósceles, escaleno).

**Orientación:**
- Para ser válido: a + b > c, a + c > b, b + c > a
- Equilátero: los tres lados iguales
- Isósceles: dos lados iguales
- Escaleno: todos diferentes

---
(ejercicio_2_9)=
## Ejercicio 2.9 - Mes del Año ⭐⭐⭐☆☆

Dado un número de mes (1-12), mostrá su nombre y cantidad de días.

**Orientación:**
- Usá `switch` para el mes
- Considerá febrero con 28 días (ignorar bisiesto por ahora)
- Manejá entradas inválidas (fuera de 1-12)

---
(ejercicio_2_10)=
## Ejercicio 2.10 - Signo Zodiacal ⭐⭐⭐☆☆

Dados día y mes de nacimiento, determiná el signo zodiacal.

**Orientación:**
- Usá múltiples condiciones sobre mes y día
- Ejemplo: Aries es del 21/03 al 19/04
- Validá fechas (día válido para cada mes)

---
(ejercicio_2_11)=
## Ejercicio 2.11 - Ordenar Tres Números ⭐⭐⭐☆☆

Leé tres números y mostralos ordenados de menor a mayor.

**Orientación:**
- Compará los tres números entre sí
- Intercambiá valores si es necesario
- Podés usar variables temporales
- Alternativa: usar comparaciones múltiples sin intercambio

---
(ejercicio_2_12)=
## Ejercicio 2.12 - Vocales y Consonantes ⭐⭐⭐☆☆

Leé un carácter y determiná si es vocal, consonante, dígito u otro símbolo.

**Orientación:**
- Usá `switch` con múltiples casos para vocales
- Verificá si es letra con `isalpha()` de `<ctype.h>`
- Verificá si es dígito con `isdigit()`
- Considerá mayúsculas y minúsculas

---
(ejercicio_2_13)=
## Ejercicio 2.13 - Ecuación de Primer Grado ⭐⭐⭐☆☆

Resolvé ecuaciones de la forma ax + b = 0.

**Casos:**
- Si a = 0 y b = 0: infinitas soluciones
- Si a = 0 y b ≠ 0: sin solución
- Si a ≠ 0: x = -b/a

**Orientación:**
- Manejá los tres casos con `if-else`
- Mostrá mensajes descriptivos para cada caso

---
(ejercicio_2_14)=
## Ejercicio 2.14 - Clasificación de IMC ⭐⭐⭐☆☆

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

---
(ejercicio_2_15)=
## Ejercicio 2.15 - Conversor de Calificaciones ⭐⭐⭐⭐☆

Convertí entre diferentes sistemas de calificación: numérica (0-10), letra
(A-F), porcentaje (0-100).

**Orientación:**
- Mostrá menú para elegir conversión
- Implementá funciones de mapeo para cada conversión
- Validá rangos de entrada

---
(ejercicio_2_16)=
## Ejercicio 2.16 - Operaciones con Fechas ⭐⭐⭐⭐☆

Dadas dos fechas (día, mes, año), determiná cuál es anterior.

**Orientación:**
- Compará primero años, luego meses, finalmente días
- Validá que ambas fechas sean válidas
- Considerá años bisiestos para febrero

---
(ejercicio_2_17)=
## Ejercicio 2.17 - Calculadora de Impuestos ⭐⭐⭐⭐☆

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

---
(ejercicio_2_18)=
## Ejercicio 2.18 - Validador de Tarjeta de Crédito ⭐⭐⭐⭐☆

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

---
(ejercicio_2_19)=
## Ejercicio 2.19 - Juego de Adivinanza ⭐⭐⭐⭐☆

El programa elige un número aleatorio entre 1 y 100. El usuario adivina y recibe
pistas ("muy alto", "muy bajo").

**Orientación:**
- Usá `rand()` de `<stdlib.h>`
- Inicializá semilla con `srand(time(NULL))`
- Contá intentos
- Usá lazo `while` hasta acertar o límite de intentos

---
(ejercicio_2_20)=
## Ejercicio 2.20 - Conversor de Números Romanos ⭐⭐⭐⭐⭐

Convertí un número decimal (1-3999) a números romanos.

**Símbolos:** I=1, V=5, X=10, L=50, C=100, D=500, M=1000

**Orientación:**
- Procesá de mayor a menor: miles, cientos, decenas, unidades
- Manejá casos especiales: 4 (IV), 9 (IX), 40 (XL), 90 (XC), etc.
- Usá múltiples `if` o `switch` por cada orden de magnitud

---
(ejercicio_2_21)=
## Ejercicio 2.21 - Calculadora de Tiempo ⭐⭐⭐⭐⭐

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

---
(ejercicio_2_22)=
## Ejercicio 2.22 - Sistema de Menú Multinivel ⭐⭐⭐⭐⭐

Implementá un sistema de menús con submenús.

**Estructura:**
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
- **Claridad:** Usá nombres de variables descriptivos (`esVocal` en lugar de
  `v`)

:::
<!-- {tip} Buenas Prácticas -->

:::{note} Operadores Útiles

- **Relacionales:** `<`, `>`, `<=`, `>=`, `==`, `!=`
- **Lógicos:** `&&` (AND), `||` (OR), `!` (NOT)
- **Ternario:** `condicion ? valor_si_cierto : valor_si_falso`

:::
<!-- {note} Operadores Útiles -->

Estas consignas cubren estructuras de control, toma de decisiones, validación de
datos y lógica condicional compleja.

