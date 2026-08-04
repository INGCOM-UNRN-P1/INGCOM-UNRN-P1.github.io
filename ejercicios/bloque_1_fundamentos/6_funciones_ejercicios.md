---
title: 'Ejercicios sobre Funciones'
short_title: '6. Funciones'
subtitle: 'Problemas y soluciones sobre modularización en C'
---

# Ejercicios sobre Funciones

## Acerca de

Estos ejercicios tienen como finalidad practicar la descomposición modular de
problemas en funciones en C, definiendo firmas con sus tipos de datos
correspondientes para los parámetros y valores de retorno.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-funciones-descomposicion`

### Cuestiones de Estilo Aplicables
- **Resolución mediante funciones:** Según la [Regla
  0x2009h](../../reglas/2_funciones.md#0x2009h), la lógica debe ser encapsulada
  en funciones independientes.
- **Nomenclatura en funciones:** Los nombres de funciones y variables locales
  deben seguir la convención `snake_case` en minúsculas, de acuerdo con las
  reglas [0x200Ah](../../reglas/2_funciones.md#0x200ah) y
  [0x0007h](../../reglas/0_sintaxis.md#0x0007h).
- **Separación de entrada/salida:** En concordancia con la [Regla
  0x2002h](../../reglas/2_funciones.md#0x2002h), se debe evitar que las
  funciones realicen entrada/salida (I/O) a menos que ese sea su propósito
  explícito.

---

## Definición y Llamada de Funciones
(ejercicio_5_1)=
### Ejercicio 5.1 - Doble de un número ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-doble
Escribí una función que reciba un número entero y devuelva su doble. Probala
desde `main()` con distintos valores.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int doble(int n) {
    return 2 * n;
}

int main(void) {
    printf("Doble de 5: %d\n", doble(5));
    printf("Doble de 12: %d\n", doble(12));
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-funcion-doble -->
(ejercicio_5_2)=
### Ejercicio 5.2 - Mayor de dos números ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-mayor
:enumerator: funciones-2

Programá una función que reciba dos números enteros y retorne el mayor de ellos.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int mayor(int a, int b) {
    int resultado = a;
    if (b > a) {
        resultado = b;
    }
    return resultado;
}

int main(void) {
    int x = 10;
    int y = 7;
    printf("El mayor es: %d\n", mayor(x, y));
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-funcion-mayor -->
(ejercicio_5_3)=
### Ejercicio 5.3 - Paridad de un número ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-par-impar
Definí una función que indique si un número es par o impar. Mostrá el resultado
llamando a la función desde `main()`.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-par-impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

void par_impar(int n) {
    if (n % 2 == 0) {
        printf("%d es par\n", n);
    } else {
        printf("%d es impar\n", n);
    }
}

int main(void) {
    par_impar(7);
    par_impar(12);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-funcion-par-impar -->
(ejercicio_5_4)=
### Ejercicio 5.4 - Promedio de notas ⭐⭐☆☆☆

:::{exercise}
:label: funcion_promedio
:enumerator: funciones-4
Escribí una función que reciba tres notas enteras y devuelva el promedio en
punto flotante. Mostrá el resultado en `main()`.

:::
<!-- {exercise} -->

:::{solution} funcion_promedio
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

float promedio(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

int main(void) {
    printf("Promedio: %.2f\n", promedio(7, 8, 10));
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} funcion_promedio -->
(ejercicio_5_5)=
### Ejercicio 5.5 - Área de rectángulo ⭐⭐☆☆☆

:::{exercise}
:label: funcion_area
Implementá una función `area_rectangulo` que reciba base y altura, y devuelva el
área.

:::
<!-- {exercise} -->

:::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int area_rectangulo(int base, int altura) {
    return base * altura;
}

int main(void) {
    printf("Área: %d\n", area_rectangulo(5, 4));
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} funcion_area -->
(ejercicio_5_6)=
## Ejercicio 5.6 - Funciones Matemáticas Básicas ⭐☆☆☆☆

Creá funciones para operaciones matemáticas: `sumar`, `restar`, `multiplicar`,
`dividir`.

**Orientación:**
- Cada función recibe dos `double` y retorna el resultado
- `dividir` debe verificar divisor != 0
- En `main`, usá las funciones en una calculadora simple

---
(ejercicio_5_7)=
## Ejercicio 5.7 - Función Es Primo ⭐⭐☆☆☆

Implementá `bool es_primo(int n)` que determine si un número es primo.

**Orientación:**
- Probá divisibilidad desde 2 hasta √n
- Optimización: solo verificar impares después del 2
- En `main`, mostrá primos en un rango

---
(ejercicio_5_8)=
## Ejercicio 5.8 - Factorial Recursivo e Iterativo ⭐⭐☆☆☆

Implementá dos versiones de factorial:
- `int factorial_iterativo(int n)`
- `int factorial_recursivo(int n)`

**Orientación:**
- Iterativo: usá lazo
- Recursivo: `n * factorial(n-1)`, caso base: `n <= 1` retorna 1
- Compará tiempos (opcional)

---
(ejercicio_5_9)=
## Ejercicio 5.9 - Conversión de Temperatura ⭐⭐☆☆☆

Creá funciones para convertir temperaturas:
- `celsius_a_fahrenheit`
- `celsius_a_kelvin`
- `fahrenheit_a_celsius`
- `kelvin_a_celsius`

**Orientación:**
- Cada función recibe y retorna `double`
- Mostrá un menú en `main` para elegir conversión

---
(ejercicio_5_10)=
## Ejercicio 5.10 - Validación de Entrada ⭐⭐⭐☆☆

Implementá funciones de validación:
- `int leer_entero(int min, int max)` - lee y valida rango
- `double leer_positivo()` - lee y valida > 0
- `char leer_si_no()` - lee 's' o 'n'

**Orientación:**
- Cada función repite lectura hasta entrada válida
- Mostrá mensajes de error descriptivos
- Usá estas funciones en `main` para varios inputs

---
(ejercicio_5_11)=
## Ejercicio 5.11 - Máximo Común Divisor (MCD) ⭐⭐⭐☆☆

Implementá el algoritmo de Euclides para calcular MCD.

**Algoritmo:**
```
mcd(a, b) = mcd(b, a % b)  si b != 0
mcd(a, 0) = a
```

**Orientación:**
- Implementá versión recursiva e iterativa
- Agregá función `mcm(a, b)` usando: mcm = (a * b) / mcd(a, b)

---
(ejercicio_5_12)=
## Ejercicio 5.12 - Números de Fibonacci ⭐⭐⭐☆☆

Implementá:
- `int fibonacci(int n)` - retorna n-ésimo número de Fibonacci
- `void imprimir_fibonacci(int cantidad)` - muestra los primeros n

**Orientación:**
- Implementá versión recursiva e iterativa
- Compará eficiencia (recursiva es muy lenta para n > 40)

---
(ejercicio_5_13)=
## Ejercicio 5.13 - Operaciones con Dígitos ⭐⭐⭐☆☆

Creá funciones para manipular dígitos de un número:
- `int contar_digitos(int n)`
- `int suma_digitos(int n)`
- `int invertir_numero(int n)`
- `bool es_palindromo(int n)`

**Orientación:**
- Usá división y módulo para extraer dígitos
- `es_palindromo` compara el número con su inverso

---
(ejercicio_5_14)=
## Ejercicio 5.14 - Conversión de Bases ⭐⭐⭐⭐☆

Implementá conversiones entre bases numéricas:
- `int binario_a_decimal(long binario)`
- `long decimal_a_binario(int decimal)`
- Similar para octal y hexadecimal

**Orientación:**
- Para convertir a decimal: suma potencias de la base
- Para convertir desde decimal: divisiones sucesivas
- Validá que los dígitos sean válidos para la base

---
(ejercicio_5_15)=
## Ejercicio 5.15 - Cálculo de Potencia ⭐⭐⭐⭐☆

Implementá tres versiones de potencia:
- `double potencia_simple(double base, int exp)` - O(n)
- `double potencia_rapida(double base, int exp)` - O(log n)
- Manejá exponentes negativos

**Orientación:**
- Simple: multiplica base n veces
- Rápida: si exp es par, `pow(base, exp) = pow(base*base, exp/2)`
- Exponente negativo: `pow(base, -n) = 1 / pow(base, n)`

---
(ejercicio_5_16)=
## Ejercicio 5.16 - Generador de Números Primos ⭐⭐⭐⭐☆

Implementá:
- `bool es_primo(int n)`
- `int siguiente_primo(int desde)`
- `void listar_primos(int inicio, int fin)`
- `int contar_primos(int hasta)`

**Orientación:**
- Optimizá `es_primo` probando solo hasta √n
- Reutilizá funciones entre sí
- `siguiente_primo` busca el próximo primo >= desde

---
(ejercicio_5_17)=
## Ejercicio 5.17 - Combinatoria ⭐⭐⭐⭐☆

Implementá funciones combinatorias:
- `long factorial(int n)`
- `long combinaciones(int n, int k)` - C(n,k) = n! / (k! × (n-k)!)
- `long permutaciones(int n, int k)` - P(n,k) = n! / (n-k)!

**Orientación:**
- Optimizá evitando calcular factoriales completos
- Maneja overflow (usa `long` o `long long`)
- Validá que 0 <= k <= n

---
(ejercicio_5_18)=
## Ejercicio 5.18 - Geometría Modular ⭐⭐⭐⭐☆

Creá funciones para calcular áreas y perímetros de figuras:
- Círculo
- Rectángulo
- Triángulo (con fórmula de Herón)
- Trapecio

**Orientación:**
- Parámetros específicos para cada forma
- Validá dimensiones positivas
- Opcionalmente, usá un menú para elegir figura

---
(ejercicio_5_19)=
## Ejercicio 5.19 - Estadísticas de un Array ⭐⭐⭐⭐☆

Implementá funciones estadísticas para un array de números:
- `double promedio(double arr[], int n)`
- `double mediana(double arr[], int n)`
- `double desviacion_estandar(double arr[], int n)`

**Orientación:**
- Promedio: suma / cantidad
- Mediana: ordenar y tomar el del medio
- Desviación: √(Σ(x - μ)² / n)

---
(ejercicio_5_20)=
## Ejercicio 5.20 - Simulación de Dado ⭐⭐⭐⭐☆

Creá un simulador de lanzamiento de dados:
- `int lanzar_dado(int caras)` - retorna 1 a caras
- `void lanzar_multiples(int cantidad, int caras, int resultados[])`
- `void estadisticas_lanzamientos(int resultados[], int n)`

**Orientación:**
- Usá `rand() % caras + 1`
- Inicializá semilla con `srand(time(NULL))` una sola vez
- Estadísticas: muestra frecuencia de cada número

---
(ejercicio_5_21)=
## Ejercicio 5.21 - Validador de Fechas ⭐⭐⭐⭐☆

Implementá funciones para trabajar con fechas:
- `bool es_fecha_valida(int dia, int mes, int anio)`
- `int dias_del_mes(int mes, int anio)`
- `bool es_bisiesto(int anio)`
- `int dia_del_anio(int dia, int mes, int anio)`

**Orientación:**
- Reutilizá funciones entre sí
- Validá rangos apropiados
- `dia_del_anio` suma días desde inicio del año

---
(ejercicio_5_22)=
## Ejercicio 5.22 - Búsqueda y Ordenamiento ⭐⭐⭐⭐⭐

Implementá algoritmos básicos:
- `int busqueda_lineal(int arr[], int n, int objetivo)`
- `void ordenar_burbuja(int arr[], int n)`
- `void intercambiar(int *a, int *b)`

**Orientación:**
- Búsqueda lineal: O(n), retorna índice o -1
- Burbuja: compara adyacentes e intercambia
- `intercambiar` usa punteros para modificar valores

---
(ejercicio_5_23)=
## Ejercicio 5.23 - Calculadora de Fechas ⭐⭐⭐⭐⭐

Calculá diferencias y sumas con fechas:
- `int diferencia_dias(fecha_t f1, fecha_t f2)`
- `fecha_t sumar_dias(fecha_t f, int dias)`
- `int dia_de_semana(fecha_t f)` - 0=Domingo, 6=Sábado

**Orientación:**
- Definí `typedef struct { int dia, mes, anio; } fecha_t;`
- Convertí fechas a "número de días desde época"
- Usá algoritmo de Zeller para día de semana

---
(ejercicio_5_24)=
## Ejercicio 5.24 - Sistema de Ecuaciones ⭐⭐⭐⭐⭐

Resolvé sistemas de ecuaciones 2×2:
```
a₁x + b₁y = c₁
a₂x + b₂y = c₂
```

Implementá:
- `bool resolver_sistema(double a1, double b1, double c1, 
                          double a2, double b2, double c2,
                          double *x, double *y)`

**Orientación:**
- Usá método de Cramer
- Calculá determinante: det = a1×b2 - a2×b1
- Si det = 0, sistema sin solución única
- x = (c1×b2 - c2×b1) / det
- y = (a1×c2 - a2×c1) / det
- Usá punteros para retornar x e y

---
(ejercicio_5_25)=
## Ejercicio 5.25 - Biblioteca de Strings ⭐⭐⭐⭐⭐

Reimplementá funciones de `<string.h>` sin usarla:
- `int mi_strlen(const char *str)`
- `void mi_strcpy(char *dest, const char *src)`
- `int mi_strcmp(const char *s1, const char *s2)`
- `void mi_strcat(char *dest, const char *src)`
- `char *mi_strchr(const char *str, char c)`

**Orientación:**
- `strlen`: contá hasta '\0'
- `strcpy`: copiá carácter por carácter incluyendo '\0'
- `strcmp`: retorna diferencia del primer carácter distinto
- `strcat`: copiá src al final de dest
- `strchr`: retorna puntero a primera aparición de c
- Verificá límites de destino para evitar buffer overflow

---

## Notas Finales

:::{tip} Diseño de Funciones

- **Una responsabilidad:** Cada función debe hacer una sola cosa bien
- **Nombres descriptivos:** `calcular_promedio` en lugar de `calc`
- **Parámetros mínimos:** No más de 3-4 parámetros si es posible
- **Retorno significativo:** `bool` para éxito/fallo, valores cuando calculás
  algo
- **Sin efectos laterales:** Evitá modificar variables globales

:::
<!-- {tip} Diseño de Funciones -->

:::{note} Documentación

Cada función debe tener:
- Descripción de qué hace
- Descripción de parámetros
- Descripción del valor de retorno
- Precondiciones (qué debe ser cierto antes de llamarla)
- Postcondiciones (qué garantiza después de ejecutarse)

:::
<!-- {note} Documentación -->

Estas consignas practican modularización, reutilización, paso de parámetros y
diseño de interfaces de funciones.

