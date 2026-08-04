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

### Ejercicio 2.1 - Mostrando valores

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

### Ejercicio 2.2 - Formateo de entrada y salida

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

---

## Ejercicios Adicionales (Práctica Intensiva)

## Ejercicio 1: Par o Impar

**Dificultad:** ⭐☆☆☆☆

Determiná si un número entero es par o impar.

**Orientación:**
- Usá el operador módulo `%`
- Si `numero % 2 == 0`, es par
- Considerá números negativos (funcionan igual)

---

## Ejercicio 2: Mayor de Tres Números

**Dificultad:** ⭐⭐☆☆☆

Leé tres números y determiná cuál es el mayor.

**Orientación:**
- Usá `if-else` anidados o encadenados
- Compará primero dos números, luego el mayor con el tercero
- Considerá el caso de números iguales

---

## Ejercicio 3: Año Bisiesto

**Dificultad:** ⭐⭐☆☆☆

Determiná si un año es bisiesto.

**Reglas:**
- Divisible por 4: bisiesto
- **Excepto** si es divisible por 100: no bisiesto
- **Excepto** si es divisible por 400: bisiesto

**Orientación:**
- Usá operadores lógicos `&&` y `||`
- Condición: `(año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)`

---

## Ejercicio 4: Calificación a Letra

**Dificultad:** ⭐⭐☆☆☆

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

## Ejercicio 5: Calculadora con Menú

**Dificultad:** ⭐⭐⭐☆☆

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

## Ejercicio 6: Triángulo Válido

**Dificultad:** ⭐⭐⭐☆☆

Dados tres lados, determiná si forman un triángulo válido y qué tipo es (equilátero, isósceles, escaleno).

**Orientación:**
- Para ser válido: a + b > c, a + c > b, b + c > a
- Equilátero: los tres lados iguales
- Isósceles: dos lados iguales
- Escaleno: todos diferentes

---

## Ejercicio 7: Mes del Año

**Dificultad:** ⭐⭐⭐☆☆

Dado un número de mes (1-12), mostrá su nombre y cantidad de días.

**Orientación:**
- Usá `switch` para el mes
- Considerá febrero con 28 días (ignorar bisiesto por ahora)
- Manejá entradas inválidas (fuera de 1-12)

---

## Ejercicio 8: Signo Zodiacal

**Dificultad:** ⭐⭐⭐☆☆

Dados día y mes de nacimiento, determiná el signo zodiacal.

**Orientación:**
- Usá múltiples condiciones sobre mes y día
- Ejemplo: Aries es del 21/03 al 19/04
- Validá fechas (día válido para cada mes)

---

## Ejercicio 9: Ordenar Tres Números

**Dificultad:** ⭐⭐⭐☆☆

Leé tres números y mostralos ordenados de menor a mayor.

**Orientación:**
- Compará los tres números entre sí
- Intercambiá valores si es necesario
- Podés usar variables temporales
- Alternativa: usar comparaciones múltiples sin intercambio

---

## Ejercicio 10: Vocales y Consonantes

**Dificultad:** ⭐⭐⭐☆☆

Leé un carácter y determiná si es vocal, consonante, dígito u otro símbolo.

**Orientación:**
- Usá `switch` con múltiples casos para vocales
- Verificá si es letra con `isalpha()` de `<ctype.h>`
- Verificá si es dígito con `isdigit()`
- Considerá mayúsculas y minúsculas

---

## Ejercicio 11: Ecuación de Primer Grado

**Dificultad:** ⭐⭐⭐☆☆

Resolvé ecuaciones de la forma ax + b = 0.

**Casos:**
- Si a = 0 y b = 0: infinitas soluciones
- Si a = 0 y b ≠ 0: sin solución
- Si a ≠ 0: x = -b/a

**Orientación:**
- Manejá los tres casos con `if-else`
- Mostrá mensajes descriptivos para cada caso

---

## Ejercicio 12: Clasificación de IMC

**Dificultad:** ⭐⭐⭐☆☆

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

## Ejercicio 13: Conversor de Calificaciones

**Dificultad:** ⭐⭐⭐⭐☆

Convertí entre diferentes sistemas de calificación: numérica (0-10), letra (A-F), porcentaje (0-100).

**Orientación:**
- Mostrá menú para elegir conversión
- Implementá funciones de mapeo para cada conversión
- Validá rangos de entrada

---

## Ejercicio 14: Operaciones con Fechas

**Dificultad:** ⭐⭐⭐⭐☆

Dadas dos fechas (día, mes, año), determiná cuál es anterior.

**Orientación:**
- Compará primero años, luego meses, finalmente días
- Validá que ambas fechas sean válidas
- Considerá años bisiestos para febrero

---

## Ejercicio 15: Calculadora de Impuestos

**Dificultad:** ⭐⭐⭐⭐☆

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

## Ejercicio 16: Validador de Tarjeta de Crédito

**Dificultad:** ⭐⭐⭐⭐☆

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

## Ejercicio 17: Juego de Adivinanza

**Dificultad:** ⭐⭐⭐⭐☆

El programa elige un número aleatorio entre 1 y 100. El usuario adivina y recibe pistas ("muy alto", "muy bajo").

**Orientación:**
- Usá `rand()` de `<stdlib.h>`
- Inicializá semilla con `srand(time(NULL))`
- Contá intentos
- Usá lazo `while` hasta acertar o límite de intentos

---

## Ejercicio 18: Conversor de Números Romanos

**Dificultad:** ⭐⭐⭐⭐⭐

Convertí un número decimal (1-3999) a números romanos.

**Símbolos:** I=1, V=5, X=10, L=50, C=100, D=500, M=1000

**Orientación:**
- Procesá de mayor a menor: miles, cientos, decenas, unidades
- Manejá casos especiales: 4 (IV), 9 (IX), 40 (XL), 90 (XC), etc.
- Usá múltiples `if` o `switch` por cada orden de magnitud

---

## Ejercicio 19: Calculadora de Tiempo

**Dificultad:** ⭐⭐⭐⭐⭐

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

## Ejercicio 20: Sistema de Menú Multinivel

**Dificultad:** ⭐⭐⭐⭐⭐

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
- **Validación constante:** Verificá siempre que la entrada esté en el rango esperado
- **Mensajes claros:** Informá al usuario qué salió mal y qué se espera
- **Casos extremos:** Probá con valores mínimos, máximos, cero y negativos
- **Claridad:** Usá nombres de variables descriptivos (`esVocal` en lugar de `v`)
:::

:::{note} Operadores Útiles
- **Relacionales:** `<`, `>`, `<=`, `>=`, `==`, `!=`
- **Lógicos:** `&&` (AND), `||` (OR), `!` (NOT)
- **Ternario:** `condicion ? valor_si_cierto : valor_si_falso`
:::

Estas consignas cubren estructuras de control, toma de decisiones, validación de datos y lógica condicional compleja.

