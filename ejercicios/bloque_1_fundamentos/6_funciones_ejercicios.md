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
- **Resolución mediante funciones:** Según la {ref}`0x2008h`, la lógica debe ser encapsulada
  en funciones independientes.
- **Nomenclatura en funciones:** Los nombres de funciones y variables locales
  deben seguir la convención `snake_case` en minúsculas, de acuerdo con las
  reglas {ref}`0x2009h` y
  {ref}`0x0102h`.
- **Separación de entrada/salida:** En concordancia con la {ref}`0x2002h`, se debe evitar que las
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
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen (`@param`, `@return`).
-   **[*plus ultra*]:** Escribir una función de prueba con assert() que verifique casos positivos, negativos y cero.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
int doble(int n)
{
    return 2 * n;
}
int main(void)
{
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
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Implementar una función que calcule el mayor de tres números reutilizando la función mayor de dos.
-   **[*plus ultra*]:** Escribir aserciones con assert() para verificar el comportamiento con números iguales.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
int mayor(int a, int b)
{
    int resultado = a;
    if (b > a)
    {
        resultado = b;
    }
    return resultado;
}
int main(void)
{
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
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Hacer que la función retorne un bool en lugar de imprimir directamente en consola.
-   **[*plus ultra*]:** Escribir pruebas unitarias que verifiquen paridad en números pares, impares y negativos.

:::
<!-- {exercise} -->

:::{solution} ej-funcion-par-impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
void par_impar(int n)
{
    if (n % 2 == 0)
    {
        printf("%d es par\n", n);
    }
    else
    {
        printf("%d es impar\n", n);
    }
}
int main(void)
{
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
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Validar que las notas se encuentren en el rango [1, 10] retornando un código de error si alguna es inválida.
-   **[*plus ultra*]:** Escribir aserciones para verificar el cálculo del promedio con decimales.

:::
<!-- {exercise} -->

:::{solution} funcion_promedio
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>
float promedio(int a, int b, int c)
{
    return (a + b + c) / 3.0f;
}
int main(void)
{
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
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Validar que la base y la altura sean valores positivos (`@pre base > 0 && altura > 0`).
-   **[*plus ultra*]:** Implementar una función complementaria para calcular el perímetro.

:::
<!-- {exercise} -->

:::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
int area_rectangulo(int base, int altura)
{
    return base * altura;
}
int main(void)
{
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


:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Manejar la división por cero retornando un código de error o valor centinela.
-   **[*plus ultra*]:** Diseñar una suite de pruebas con assert() para cada una de las operaciones básicas.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_7)=
## Ejercicio 5.7 - Función Es Primo ⭐⭐☆☆☆

Implementá `bool es_primo(int n)` que determine si un número es primo.

**Orientación:**
- Probá divisibilidad desde 2 hasta √n
- Optimización: solo verificar impares después del 2
- En `main`, mostrá primos en un rango


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Optimizar la función probando divisores únicamente hasta sqrt(n).
-   **[*plus ultra*]:** Documentar las precondiciones (`@pre n >= 1`) y postcondiciones con Doxygen.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    cola (*tail recursion*) para reducir el consumo de pila.
    realizadas para analizar la complejidad empírica.

-   **[*plus ultra*]:** Validar que n >= 0 retornando -1 en caso de error y usar long long para el resultado.
-   **[*plus ultra*]:** Escribir pruebas unitarias comparando que ambas versiones produzcan exactamente el mismo resultado.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Modularizar las fórmulas asegurando que no haya operaciones de entrada/salida dentro de las funciones.
-   **[*plus ultra*]:** Escribir aserciones para verificar puntos clave (ej. 0 °C == 32 °F, 100 °C == 212 °F).

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Modularizar la lectura para que el mensaje de error sea configurable por parámetro.
-   **[*plus ultra*]:** Permitir un número máximo de reintentos antes de retornar un código de fallo.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_11)=
## Ejercicio 5.11 - Máximo Común Divisor (MCD) ⭐⭐⭐☆☆

Implementá el algoritmo de Euclides para calcular MCD.

**Algoritmo:**

:::{hint} Lógica y Consideraciones
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Implementar una función auxiliar para calcular el Mínimo Común Múltiplo (MCM).
-   **[*plus ultra*]:** Escribir pruebas unitarias con assert() verificando propiedades como mcd(a, b) == mcd(b, a).

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Usar tipos enteros de 64 bits (long long o uint64_t) para calcular términos más altos.
-   **[*plus ultra*]:** Escribir pruebas unitarias con assert() para los primeros 10 términos de la sucesión.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Modularizar cada operación en una función pura con una única responsabilidad.
-   **[*plus ultra*]:** Documentar con Doxygen las precondiciones sobre números negativos.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    errores de E/S con `ferror` y `feof`.
    archivo en todos los caminos de ejecución.

-   **[*plus ultra*]:** Validar que los dígitos de la cadena binaria sean exclusivamente 0 o 1.
-   **[*plus ultra*]:** Escribir pruebas con assert() verificando conversiones de ida y vuelta (round-trip).

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_15)=
## Ejercicio 5.15 - Cálculo de Potencia ⭐⭐⭐⭐☆

Implementá dos versiones de cálculo de potencia:
- `double potencia_iterativa(double base, int exp)`: calculada mediante multiplicaciones sucesivas.
- `double potencia_rapida(double base, int exp)`: calculada mediante exponenciación binaria (reduciendo a la mitad el exponente en cada paso).
- Manejá exponentes negativos retornando `1.0 / potencia(base, -exp)`.

**Orientación:**
- Simple: multiplica base n veces
- Rápida: si exp es par, `pow(base, exp) = pow(base*base, exp/2)`
- Exponente negativo: `pow(base, -n) = 1 / pow(base, n)`


:::{hint} Lógica y Consideraciones
    valores fuera de rango o tipos inválidos.
    un lazo hasta que el usuario elija finalizar.

-   **[*plus ultra*]:** Verificar que la versión iterativa y la rápida retornen el mismo resultado dentro de una tolerancia con assert.
-   **[*plus ultra*]:** Manejar el caso especial base=0 y exp=0.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    definición interna oculta en el archivo `.c`.
    para copiar la estructura de forma segura.

-   **[*plus ultra*]:** Modularizar la función siguiente_primo reutilizando es_primo.
-   **[*plus ultra*]:** Escribir pruebas con assert() para verificar primos conocidos.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Prevenir desbordamientos simplificando factores comunes antes de multiplicar en C(n, k).
-   **[*plus ultra*]:** Validar las precondiciones con assert (0 <= k && k <= n).

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Modularizar cada figura geométrica en una función independiente con documentación completa.
-   **[*plus ultra*]:** Escribir pruebas unitarias validando áreas de figuras conocidas.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    filas (*row-major order*) para mejorar el uso de caché.
    estrictamente dentro de los límites del contenedor.

-   **[*plus ultra*]:** Validar que n > 0 y usar el calificador const en los arreglos de solo lectura.
-   **[*plus ultra*]:** Escribir pruebas con assert() para verificar el cálculo del promedio y la desviación.

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Modularizar el cálculo de frecuencias en una función independiente.
-   **[*plus ultra*]:** Escribir pruebas unitarias verificando que los valores generados estén en el rango [1, caras].

:::
<!-- {hint} Lógica y Consideraciones -->

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


:::{hint} Lógica y Consideraciones
    error e informar el resultado mediante parámetros de salida.
    especificando precondiciones y postcondiciones.

-   **[*plus ultra*]:** Modularizar la función reutilizando es_bisiesto y dias_del_mes.
-   **[*plus ultra*]:** Escribir pruebas unitarias exhaustivas para fechas límites (ej. 29 de febrero en años bisiestos y no bisiestos).

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_22)=
## Ejercicio 5.22 - Búsqueda y Algoritmos sobre Arreglos ⭐⭐⭐⭐⭐

Implementá funciones modulares para operaciones sobre arreglos de enteros:
- `int busqueda_lineal(const int arr[], int n, int objetivo)`: retorna el índice de la primera aparición o `-1`.
- `int encontrar_maximo(const int arr[], int n)`: retorna el valor máximo contenido en el arreglo.
- `int contar_ocurrencias(const int arr[], int n, int valor)`: cuenta cuántas veces aparece un elemento.

**Orientación:**
- Usá el calificador `const` en los arreglos para garantizar que las funciones de consulta no los modifiquen
- Validá que `n > 0` antes de buscar el máximo


:::{hint} Lógica y Consideraciones
    evitar fallos de segmentación.
    punteros en lugar de indexación directa.

-   **[*plus ultra*]:** Usar el calificador const en el arreglo de entrada para garantizar que la función sea de solo lectura.
-   **[*plus ultra*]:** Escribir pruebas unitarias con assert() para elementos presentes, ausentes y arreglos vacíos.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_23)=
## Ejercicio 5.23 - Funciones de Calendario y Fechas ⭐⭐⭐⭐⭐

Implementá funciones modulares para operaciones con fechas representadas mediante sus componentes (`dia`, `mes`, `anio`):
- `bool es_fecha_valida(int dia, int mes, int anio)`: valida si una terna corresponde a una fecha real del calendario gregoriano.
- `int dias_transcurridos(int d1, int m1, int a1, int d2, int m2, int a2)`: calcula la cantidad de días entre dos fechas válidas.
- `int dia_de_semana(int dia, int mes, int anio)`: retorna el día de la semana (0=Domingo, 1=Lunes, ..., 6=Sábado) aplicando la congruencia de Zeller.

**Orientación:**
- Modularizá el cálculo de año bisiesto en una función auxiliar `bool es_bisiesto(int anio)`
- Validá las precondiciones de cada función antes de calcular


:::{hint} Lógica y Consideraciones
    desbordamientos de búfer validando la capacidad máxima.
    líneas de manera robusta.

-   **[*plus ultra*]:** Validar que las fechas sean válidas antes de calcular diferencias.
-   **[*plus ultra*]:** Escribir pruebas unitarias con assert() para fechas históricas y bisiestos.

:::
<!-- {hint} Lógica y Consideraciones -->

---
(ejercicio_5_24)=
## Ejercicio 5.24 - Sistema de Ecuaciones 2x2 ⭐⭐⭐⭐⭐

Implementá funciones modulares para resolver y verificar sistemas de ecuaciones lineales 2×2 mediante la regla de Cramer:

:::{hint} Lógica y Consideraciones
    evitar fallos de segmentación.
    punteros en lugar de indexación directa.

-   **[*plus ultra*]:** Modularizar el cálculo del determinante en una función auxiliar pura.
-   **[*plus ultra*]:** Escribir pruebas con assert() verificando sistemas con solución única y sistemas sin solución (det == 0).

:::
<!-- {hint} Lógica y Consideraciones -->

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
- Retorná un código booleano indicando si el determinante es no nulo y el sistema tiene solución única

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

