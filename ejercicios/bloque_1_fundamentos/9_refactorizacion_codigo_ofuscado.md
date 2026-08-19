---
title: "Ejercicios: Refactorización de Código Ofuscado"
short_title: "9. Refactorización de Código Ofuscado"
subtitle: "Deconstrucción, análisis y transformación de código críptico a C idiomático y limpio"
---

# Ejercicios: Refactorización de Código Ofuscado

## Acerca de

En el desarrollo profesional de software, la mayor parte del tiempo se destina a
**leer, entender y mantener código existente**. Con frecuencia te encontrarás
con
código mal estructurado, con nombres crípticos de una sola letra, números
mágicos
sin explicación, anidaciones excesivas o dependencias ocultas de variables
globales.

El objetivo de este cuadernillo es desarrollar tu agudeza analítica mediante la
**deconstrucción y refactorización** de fragmentos de código intencionalmente
ofuscados.

:::{warning} Temas de estos ejercicios

Ojo que estos ejercicios contienen sintaxis que vamos a ver más adelante, en
particular
matrices y arreglos.

**Y están construidos con el máximo nivel de aspereza**

:::
<!-- {warning} Temas de estos ejercicios -->

### Metodología de Trabajo para Cada Ejercicio

Para resolver cada ejercicio debés:
1. **Analizar el código ofuscado:** Determinar qué hace el algoritmo, cuáles son
   sus datos de entrada y salida, y qué invariantes o precondiciones asume.
2. **Identificar "olores de código" (*code smells*) y violaciones de estilo:**
   Nombres crípticos, operador ternario no permitido, falta de llaves Allman,
   variables reutilizadas, números mágicos, efectos secundarios, etc.
3. **Refactorizar a C limpio e idiomático:** Reescribir la solución aplicando:
   - Formato **Allman** ([Regla 0x000Bh](../../reglas/0_sintaxis.md#0x000bh)).
   - Nombres autoexplicativos en `snake_case` ([Regla
     0x0007h](../../reglas/0_sintaxis.md#0x0007h)).
   - Eliminación estricta de variables globales ([Regla
     0x2004h](../../reglas/2_funciones.md#0x2004h)).
   - Cláusulas de guarda para evitar anidaciones ([Regla
     0x2001h](../../reglas/2_funciones.md#0x2001h)).
   - Constantes simbólicas para números mágicos ([Regla
     0x0004h](../../reglas/0_sintaxis.md#0x0004h)).
   - Desacople total de `printf`/`scanf` ([Regla
     0x2002h](../../reglas/2_funciones.md#0x2002h)).
4. **Diseñar una suite de pruebas con `assert()`:** Validar que la versión
   refactorizada preserve exactamente el comportamiento esperado ante casos
   normales y bordes.

---

## 1. Expresiones Aritméticas, Asignaciones y Nombres Crípticos

(ejercicio_9_ref_1)=
### Ejercicio 9.1 - El Máximo Comprimido ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-maximo-comprimido
Analizá y refactorizá la siguiente función que utiliza el operador ternario
prohibido y nombres crípticos:

``` c
int f(int a,int b){return(a>b)?a:b;}
```
<!-- c -->

-   **[*plus ultra*]:** Implementar `int obtener_mayor(int primer_numero, int
    segundo_numero)` con estilo Allman y `if-else`.
-   **[*plus ultra*]:** Escribir pruebas unitarias con `assert()` para números
    positivos, negativos e iguales.

:::
<!-- {exercise} -->

:::{solution} ej-ref-maximo-comprimido
:class: dropdown
**Diagnóstico:**
- Violación de la [Regla 0x1007h](../../reglas/1_control.md#0x1007h): uso del
  operador ternario `?:`.
- Violación de la [Regla 0x000Bh](../../reglas/0_sintaxis.md#0x000bh): llaves en
  la misma línea (no es Allman).
- Violación de la [Regla 0x0007h](../../reglas/0_sintaxis.md#0x0007h):
  identificadores de una letra `f, a, b`.

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

int obtener_mayor(int primer_numero, int segundo_numero)
{
    if (primer_numero > segundo_numero)
    {
        return primer_numero;
    }
    else
    {
        return segundo_numero;
    }
}

void test_obtener_mayor(void)
{
    assert(obtener_mayor(10, 5) == 10);
    assert(obtener_mayor(-3, -8) == -3);
    assert(obtener_mayor(7, 7) == 7);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-maximo-comprimido -->

---

(ejercicio_9_ref_2)=
### Ejercicio 9.2 - Geometría sin Nombres ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-area-triangulo
Descifrá el propósito geométrico del siguiente fragmento y refactorizalo:

``` c
double x(double a,double b){return a*b/2.0;}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que las dimensiones sean estrictamente positivas
    retornando `-1.0` si son inválidas.
-   **[*plus ultra*]:** Documentar con etiquetas Doxygen (`@param`, `@pre`,
    `@returns`).

:::
<!-- {exercise} -->

:::{solution} ej-ref-area-triangulo
:class: dropdown
**Diagnóstico:** Calcula el área de un triángulo con base `a` y altura `b`. No
valida dimensiones no positivas.

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

double calcular_area_triangulo(double base, double altura)
{
    if (base <= 0.0 || altura <= 0.0)
    {
        return -1.0;
    }
    return (base * altura) / 2.0;
}

void test_area_triangulo(void)
{
    assert(calcular_area_triangulo(10.0, 5.0) == 25.0);
    assert(calcular_area_triangulo(-2.0, 5.0) == -1.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-area-triangulo -->

---

(ejercicio_9_ref_3)=
### Ejercicio 9.3 - Suma de Cuadrados en Una Línea ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-suma-cuadrados
Analizá el siguiente lazo comprimido y refactorizalo para que sea claro, robusto
y testeable:

``` c
int p(int n){int s=0;for(int i=1;i<=n;i++)s+=i*i;return s;}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que $n \ge 0$.
-   **[*plus ultra*]:** Comparar el resultado del lazo con la fórmula cerrada
    $\frac{n(n+1)(2n+1)}{6}$.

:::
<!-- {exercise} -->

:::{solution} ej-ref-suma-cuadrados
:class: dropdown
**Diagnóstico:** Calcula $\sum_{i=1}^n i^2$. Carece de espacios, llaves Allman y
validación para $n < 0$.

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

int calcular_suma_cuadrados(int limite)
{
    if (limite < 0)
    {
        return -1;
    }
    int acumulador = 0;
    for (int i = 1; i <= limite; i++)
    {
        acumulador += (i * i);
    }
    return acumulador;
}

void test_suma_cuadrados(void)
{
    assert(calcular_suma_cuadrados(0) == 0);
    assert(calcular_suma_cuadrados(3) == 14); // 1 + 4 + 9 = 14
    assert(calcular_suma_cuadrados(-5) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-suma-cuadrados -->

---

(ejercicio_9_ref_4)=
### Ejercicio 9.4 - Conversión Térmica con División Entera Peligrosa ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-conversion-termica
El siguiente código intentó convertir grados Celsius a Fahrenheit, pero tiene
problemas de estilo y posibles riesgos de tipos:

``` c
double k(double c){return(c*9/5)+32;}
```
<!-- c -->

-   **[*plus ultra*]:** Reemplazar los números literales por constantes
    flotantes `9.0 / 5.0` y `32.0`.
-   **[*plus ultra*]:** Validar que la temperatura no sea inferior al cero
    absoluto ($-273.15^\circ\text{C}$).

:::
<!-- {exercise} -->

:::{solution} ej-ref-conversion-termica
:class: dropdown
**Diagnóstico:** Nombres opacos, falta de constantes simbólicas y sin
verificación del límite físico del cero absoluto.

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#define CERO_ABSOLUTO_CELSIUS -273.15
#define FACTOR_ESCALA (9.0 / 5.0)
#define DESPLAZAMIENTO_FAHRENHEIT 32.0

double convertir_celsius_a_fahrenheit(double temperatura_celsius, bool *es_valida)
{
    if (temperatura_celsius < CERO_ABSOLUTO_CELSIUS || es_valida == NULL)
    {
        if (es_valida != NULL)
        {
            *es_valida = false;
        }
        return 0.0;
    }
    *es_valida = true;
    return (temperatura_celsius * FACTOR_ESCALA) + DESPLAZAMIENTO_FAHRENHEIT;
}

void test_conversion_celsius(void)
{
    bool ok = false;
    double f = convertir_celsius_a_fahrenheit(0.0, &ok);
    assert(ok && fabs(f - 32.0) < 1e-6);
    f = convertir_celsius_a_fahrenheit(100.0, &ok);
    assert(ok && fabs(f - 212.0) < 1e-6);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-conversion-termica -->

---

(ejercicio_9_ref_5)=
### Ejercicio 9.5 - Suma de Dígitos Ofuscada ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-suma-digitos
Analizá el siguiente código. ¿Qué hace y cómo falla si recibe un número
negativo?

``` c
int d(int n){int c=0;while(n){c+=n%10;n/=10;}return c;}
```
<!-- c -->

-   **[*plus ultra*]:** Refactorizar usando `abs()` o convirtiendo el número a
    positivo.
-   **[*plus ultra*]:** Escribir tests con `assert()` para números positivos,
    negativos y el cero.

:::
<!-- {exercise} -->

:::{solution} ej-ref-suma-digitos
:class: dropdown
**Diagnóstico:** Suma los dígitos de un número. Para `-123`, `n % 10` produce
restos negativos en C99+, dando una suma errónea (`-1 + -2 + -3 = -6`).

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdlib.h>

int sumar_digitos(int numero)
{
    int n = abs(numero);
    int suma = 0;
    while (n > 0)
    {
        suma += (n % 10);
        n /= 10;
    }
    return suma;
}

void test_sumar_digitos(void)
{
    assert(sumar_digitos(1234) == 10);
    assert(sumar_digitos(-505) == 10);
    assert(sumar_digitos(0) == 0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-suma-digitos -->

---

(ejercicio_9_ref_6)=
### Ejercicio 9.6 - Año Bisiesto Críptico ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-bisiesto-criptico
El siguiente código evalúa años bisiestos en una sola línea condensada sin
validar años negativos:

``` c
bool b(int y){return(y%4==0&&y%100!=0)||(y%400==0);}
```
<!-- c -->

-   **[*plus ultra*]:** Refactorizar con cláusula de guarda para años $\le 0$.
-   **[*plus ultra*]:** Escribir una suite con tests unitarios separados para
    cada rama de decisión.

:::
<!-- {exercise} -->

:::{solution} ej-ref-bisiesto-criptico
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool es_anio_bisiesto(int anio)
{
    if (anio <= 0)
    {
        return false;
    }
    bool es_div_4 = (anio % 4 == 0);
    bool es_div_100 = (anio % 100 == 0);
    bool es_div_400 = (anio % 400 == 0);

    return (es_div_4 && !es_div_100) || es_div_400;
}

void test_es_anio_bisiesto(void)
{
    assert(es_anio_bisiesto(2024) == true);
    assert(es_anio_bisiesto(2023) == false);
    assert(es_anio_bisiesto(1900) == false);
    assert(es_anio_bisiesto(2000) == true);
    assert(es_anio_bisiesto(-4) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-bisiesto-criptico -->

---

(ejercicio_9_ref_7)=
### Ejercicio 9.7 - Sumatoria de Gauss con Nombres Inadecuados ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-gauss-inadecuado
Refactorizá la siguiente fórmula de Gauss:

``` c
int s(int n){return n*(n+1)/2;}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que $n \ge 0$.
-   **[*plus ultra*]:** Usar el tipo `long long` para evitar desbordamientos
    enteros en valores de $n > 65535$.

:::
<!-- {exercise} -->

:::{solution} ej-ref-gauss-inadecuado
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

long long calcular_sumatoria_gauss(int limite_superior)
{
    if (limite_superior < 0)
    {
        return -1;
    }
    long long n = limite_superior;
    return (n * (n + 1)) / 2;
}

void test_sumatoria_gauss(void)
{
    assert(calcular_sumatoria_gauss(0) == 0);
    assert(calcular_sumatoria_gauss(10) == 55);
    assert(calcular_sumatoria_gauss(100) == 5050);
    assert(calcular_sumatoria_gauss(-5) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-gauss-inadecuado -->

---

(ejercicio_9_ref_8)=
### Ejercicio 9.8 - Cilindro con Número Mágico ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-cilindro-magico
Refactorizá la siguiente función que calcula el volumen de un cilindro
eliminando la constante mágica y aplicando contratos:

``` c
double v(double r,double h){return 3.14159265*r*r*h;}
```
<!-- c -->

-   **[*plus ultra*]:** Definir `#define CONSTANTE_PI 3.141592653589793`.
-   **[*plus ultra*]:** Validar que radio y altura sean mayores a cero.

:::
<!-- {exercise} -->

:::{solution} ej-ref-cilindro-magico
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>

#define CONSTANTE_PI 3.14159265358979323846

double calcular_volumen_cilindro(double radio, double altura)
{
    if (radio <= 0.0 || altura <= 0.0)
    {
        return -1.0;
    }
    return CONSTANTE_PI * radio * radio * altura;
}

void test_volumen_cilindro(void)
{
    double vol = calcular_volumen_cilindro(1.0, 10.0);
    assert(fabs(vol - (CONSTANTE_PI * 10.0)) < 1e-6);
    assert(calcular_volumen_cilindro(-1.0, 5.0) == -1.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-cilindro-magico -->

---

## 2. Control de Flujo Espagueti y Anidaciones Profundas

(ejercicio_9_ref_9)=
### Ejercicio 9.9 - El Monstruo de la Flecha (Arrow Code) ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-arrow-code
Refactorizá la siguiente función anidada en forma de flecha aplicando
**cláusulas de guarda** según la [Regla
0x2001h](../../reglas/2_funciones.md#0x2001h):

```{code-block} c
:linenos:
int calificar(int nota, int asistencia)
{
    int r = 0;
    if (asistencia >= 75)
    {
        if (nota >= 0)
        {
            if (nota <= 100)
            {
                if (nota >= 60)
                {
                    if (nota >= 90)
                    {
                        r = 3; // Sobresaliente
                    }
                    else
                    {
                        r = 2; // Aprobado
                    }
                }
                else
                {
                    r = 1; // Reprobado
                }
            }
            else
            {
                r = -1; // Error nota
            }
        }
        else
        {
            r = -1; // Error nota
        }
    }
    else
    {
        r = 0; // Libre
    }
    return r;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Reducir la profundidad máxima de indentación a 1 nivel
    dentro de la función.
-   **[*plus ultra*]:** Escribir pruebas unitarias para cada uno de los valores
    de retorno.

:::
<!-- {exercise} -->

:::{solution} ej-ref-arrow-code
:class: dropdown
**Diagnóstico:** Anidación excesiva de 5 niveles que dificulta el seguimiento de
los casos de error.

**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

#define ESTADO_NOTA_INVALIDA -1
#define ESTADO_LIBRE 0
#define ESTADO_REPROBADO 1
#define ESTADO_APROBADO 2
#define ESTADO_SOBRESALIENTE 3

int clasificar_desempenio(int nota, int asistencia_porcentaje)
{
    if (nota < 0 || nota > 100)
    {
        return ESTADO_NOTA_INVALIDA;
    }
    if (asistencia_porcentaje < 75)
    {
        return ESTADO_LIBRE;
    }
    if (nota >= 90)
    {
        return ESTADO_SOBRESALIENTE;
    }
    if (nota >= 60)
    {
        return ESTADO_APROBADO;
    }
    return ESTADO_REPROBADO;
}

void test_clasificar_desempenio(void)
{
    assert(clasificar_desempenio(95, 80) == ESTADO_SOBRESALIENTE);
    assert(clasificar_desempenio(70, 80) == ESTADO_APROBADO);
    assert(clasificar_desempenio(50, 80) == ESTADO_REPROBADO);
    assert(clasificar_desempenio(80, 50) == ESTADO_LIBRE);
    assert(clasificar_desempenio(105, 80) == ESTADO_NOTA_INVALIDA);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-arrow-code -->

---

(ejercicio_9_ref_10)=
### Ejercicio 9.10 - Menú con Ifs Caóticos ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-menu-ifs
Refactorizá la siguiente selección de opciones a una estructura `switch` clara
con cláusula `default` ([Regla 0x1003h](../../reglas/1_control.md#0x1003h)):

```{code-block} c
:linenos:
double operacion(int op, double a, double b)
{
    if (op == 1) {
        return a + b;
    } else if (op == 2) {
        return a - b;
    } else if (op == 3) {
        return a * b;
    } else if (op == 4) {
        if (b != 0) return a / b;
        else return 0;
    } else {
        return 0;
    }
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Manejar el error de división por cero y opción inválida
    mediante un puntero booleano `bool *ok`.
-   **[*plus ultra*]:** Definir un `enum` con los códigos de operación.

:::
<!-- {exercise} -->

:::{solution} ej-ref-menu-ifs
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

typedef enum
{
    OP_SUMAR = 1,
    OP_RESTAR = 2,
    OP_MULTIPLICAR = 3,
    OP_DIVIDIR = 4
} tipo_operacion_t;

double calcular_operacion(tipo_operacion_t operacion, double a, double b, bool *exito)
{
    if (exito == NULL)
    {
        return 0.0;
    }
    *exito = true;
    switch (operacion)
    {
        case OP_SUMAR:
            return a + b;
        case OP_RESTAR:
            return a - b;
        case OP_MULTIPLICAR:
            return a * b;
        case OP_DIVIDIR:
            if (b == 0.0)
            {
                *exito = false;
                return 0.0;
            }
            return a / b;
        default:
            *exito = false;
            return 0.0;
    }
}

void test_operaciones(void)
{
    bool ok = false;
    assert(calcular_operacion(OP_SUMAR, 3.0, 4.0, &ok) == 7.0 && ok);
    assert(calcular_operacion(OP_DIVIDIR, 10.0, 2.0, &ok) == 5.0 && ok);
    calcular_operacion(OP_DIVIDIR, 10.0, 0.0, &ok);
    assert(!ok);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-menu-ifs -->

---

(ejercicio_9_ref_11)=
### Ejercicio 9.11 - Lazo Espagueti con Banderas Confusas ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-lazo-espagueti
Refactorizá la siguiente función que utiliza lazos infinitos `while(1)`,
variables `flag` crípticas y `break` desordenados para verificar si un número es
primo:

```{code-block} c
:linenos:
int check(int n)
{
    int flag = 1;
    int i = 2;
    if (n <= 1) return 0;
    while (1)
    {
        if (i * i > n) break;
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Eliminar `while(1)` y `break` reemplazándolos por un
    lazo estructurado con condición clara.
-   **[*plus ultra*]:** Optimizar evaluando solo números impares después del 2.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_12)=
### Ejercicio 9.12 - Tarifa de Taxi con Variables Reutilizadas ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-tarifa-taxi
Analizá qué hace la variable `t` en el siguiente fragmento y refactorizá el
cálculo declarando variables de propósito único y constantes claras:

```{code-block} c
:linenos:
double calc(double k, int n)
{
    double t = 150.0; // Bajada de bandera
    if (k > 0) t += k * 80.0;
    if (n == 1) t = t * 1.20; // Recargo nocturno
    return t;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Validar que la distancia `k` no sea negativa.
-   **[*plus ultra*]:** Documentar el cálculo con Doxygen.

:::
<!-- {exercise} -->

:::{solution} ej-ref-tarifa-taxi
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

#define BAJADA_DE_BANDERA 150.0
#define COSTO_POR_KILOMETRO 80.0
#define FACTOR_RECARGO_NOCTURNO 1.20

double calcular_tarifa_taxi(double kilometros, bool es_tarifa_nocturna)
{
    if (kilometros < 0.0)
    {
        return -1.0;
    }
    double costo_distancia = kilometros * COSTO_POR_KILOMETRO;
    double subtotal = BAJADA_DE_BANDERA + costo_distancia;

    if (es_tarifa_nocturna)
    {
        return subtotal * FACTOR_RECARGO_NOCTURNO;
    }
    return subtotal;
}

void test_tarifa_taxi(void)
{
    assert(calcular_tarifa_taxi(10.0, false) == 950.0);
    assert(calcular_tarifa_taxi(10.0, true) == 1140.0);
    assert(calcular_tarifa_taxi(-5.0, false) == -1.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-tarifa-taxi -->

---

(ejercicio_9_ref_13)=
### Ejercicio 9.13 - Expresión Booleana Monolítica de Validación de Fecha ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-fecha-monolitica
El siguiente código comprueba la validez de una fecha en una sola expresión
booleana incomprensible de difícil depuración:

``` c
bool v(int d,int m,int y){return(y>0&&m>=1&&m<=12&&d>=1)&&((m==2&&(((y%4==0&&y%100!=0)||(y%400==0))?d<=29:d<=28))||((m==4||m==6||m==9||m==11)?d<=30:d<=31));}
```
<!-- c -->

-   **[*plus ultra*]:** Descomponer en funciones auxiliares puras `es_bisiesto`
    y `dias_del_mes`.
-   **[*plus ultra*]:** Escribir una suite de tests unitarios estructurada.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_14)=
### Ejercicio 9.14 - Descuento Escalonado con Condiciones Solapadas ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-descuento-solapado
Analizá el siguiente código con condiciones redundantes y números mágicos:

```{code-block} c
:linenos:
double desc(double m)
{
    if (m > 0 && m < 1000) return m;
    if (m >= 1000 && m < 5000) return m * 0.95;
    if (m >= 5000 && m < 10000) return m * 0.90;
    if (m >= 10000) return m * 0.80;
    return 0;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Refactorizar utilizando cláusulas de guarda ordenadas
    sin comparaciones dobles redundantes.
-   **[*plus ultra*]:** Reemplazar los porcentajes por constantes simbólicas.

:::
<!-- {exercise} -->

:::{solution} ej-ref-descuento-solapado
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

#define UMBRAL_NIVEL_1 1000.0
#define UMBRAL_NIVEL_2 5000.0
#define UMBRAL_NIVEL_3 10000.0

#define FACTOR_DESCUENTO_1 0.95
#define FACTOR_DESCUENTO_2 0.90
#define FACTOR_DESCUENTO_3 0.80

double aplicar_descuento_escalonado(double monto_compra)
{
    if (monto_compra <= 0.0)
    {
        return 0.0;
    }
    if (monto_compra >= UMBRAL_NIVEL_3)
    {
        return monto_compra * FACTOR_DESCUENTO_3;
    }
    if (monto_compra >= UMBRAL_NIVEL_2)
    {
        return monto_compra * FACTOR_DESCUENTO_2;
    }
    if (monto_compra >= UMBRAL_NIVEL_1)
    {
        return monto_compra * FACTOR_DESCUENTO_1;
    }
    return monto_compra;
}

void test_descuentos(void)
{
    assert(aplicar_descuento_escalonado(500.0) == 500.0);
    assert(aplicar_descuento_escalonado(2000.0) == 1900.0);
    assert(aplicar_descuento_escalonado(6000.0) == 5400.0);
    assert(aplicar_descuento_escalonado(12000.0) == 9600.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-descuento-solapado -->

---

(ejercicio_9_ref_15)=
### Ejercicio 9.15 - Función Contaminada con Entrada/Salida ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-contaminada-io
La siguiente función viola la [Regla
0x2002h](../../reglas/2_funciones.md#0x2002h) porque realiza `printf` adentro
del cálculo. Refactorizala para que sea una función pura y testeable:

```{code-block} c
:linenos:
#include <stdio.h>

void clasificar_temperatura_ambiente(double temp)
{
    if (temp < 10.0)
    {
        printf("Hace frio\n");
    }
    else if (temp <= 25.0)
    {
        printf("Templado\n");
    }
    else
    {
        printf("Caluroso\n");
    }
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Retornar un `enum` o código entero descriptivo.
-   **[*plus ultra*]:** Escribir tests unitarios con `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-contaminada-io
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

typedef enum
{
    CLIMA_FRIO,
    CLIMA_TEMPLADO,
    CLIMA_CALUROSO
} tipo_clima_t;

tipo_clima_t clasificar_temperatura(double temperatura_celsius)
{
    if (temperatura_celsius < 10.0)
    {
        return CLIMA_FRIO;
    }
    if (temperatura_celsius <= 25.0)
    {
        return CLIMA_TEMPLADO;
    }
    return CLIMA_CALUROSO;
}

void test_clasificar_clima(void)
{
    assert(clasificar_temperatura(5.0) == CLIMA_FRIO);
    assert(clasificar_temperatura(18.0) == CLIMA_TEMPLADO);
    assert(clasificar_temperatura(30.0) == CLIMA_CALUROSO);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-contaminada-io -->

---

(ejercicio_9_ref_16)=
### Ejercicio 9.16 - Búsqueda Lineal con Variables Globales ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-busqueda-global
Refactorizá la siguiente función que depende de variables globales mutables para
retornar la posición de un elemento en un arreglo:

```{code-block} c
:linenos:
int pos_encontrada = -1;

void buscar(int arr[], int n, int x)
{
    pos_encontrada = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            pos_encontrada = i;
            break;
        }
    }
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Retornar el índice directamente como valor de retorno de
    la función pura.
-   **[*plus ultra*]:** Agregar el calificador `const` al arreglo de entrada.

:::
<!-- {exercise} -->

:::{solution} ej-ref-busqueda-global
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

int buscar_primera_aparicion(const int arreglo[], int cantidad_elementos, int objetivo)
{
    if (arreglo == NULL || cantidad_elementos <= 0)
    {
        return -1;
    }
    for (int i = 0; i < cantidad_elementos; i++)
    {
        if (arreglo[i] == objetivo)
        {
            return i;
        }
    }
    return -1;
}

void test_buscar_aparicion(void)
{
    int datos[] = {10, 20, 30, 40};
    assert(buscar_primera_aparicion(datos, 4, 30) == 2);
    assert(buscar_primera_aparicion(datos, 4, 99) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-busqueda-global -->

---

## 3. Algoritmos Comprimidos y Lazos Crípticos

(ejercicio_9_ref_17)=
### Ejercicio 9.17 - Euclides con Operador Coma y Asignaciones Crípticas ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-euclides-coma
Analizá el siguiente código que usa el operador coma `,` para apretar
asignaciones en un lazo:

``` c
int m(int a,int b){int t;while(b)t=b,b=a%b,a=t;return a;}
```
<!-- c -->

-   **[*plus ultra*]:** Refactorizar en estilo Allman, con nombres claros y
    manejo de enteros negativos con `abs()`.
-   **[*plus ultra*]:** Escribir tests unitarios con `assert()`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_18)=
### Ejercicio 9.18 - Inversor de Números con Variables Reutilizadas ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-inversor-reutilizado
Descubrí el algoritmo y refactorizalo:

``` c
int inv(int x){int r=0;while(x>0){r=r*10+x%10;x=x/10;}return r;}
```
<!-- c -->

-   **[*plus ultra*]:** Manejar números negativos conservando su signo.
-   **[*plus ultra*]:** Comprobar palíndromos numéricos reutilizando esta
    función.

:::
<!-- {exercise} -->

:::{solution} ej-ref-inversor-reutilizado
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdlib.h>

int invertir_numero_entero(int numero)
{
    int signo = (numero < 0) ? -1 : 1;
    int n = abs(numero);
    int invertido = 0;

    while (n > 0)
    {
        invertido = (invertido * 10) + (n % 10);
        n /= 10;
    }
    return invertido * signo;
}

void test_invertir_numero(void)
{
    assert(invertir_numero_entero(1234) == 4321);
    assert(invertir_numero_entero(-580) == -85);
    assert(invertir_numero_entero(0) == 0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-inversor-reutilizado -->

---

(ejercicio_9_ref_19)=
### Ejercicio 9.19 - Fibonacci Iterativo Micro-comprimido ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-fibonacci-micro
Refactorizá la siguiente implementación de la secuencia de Fibonacci:

``` c
int fib(int n){int a=0,b=1,c,i;if(!n)return 0;for(i=2;i<=n;i++)c=a+b,a=b,b=c;return b;}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que $n \ge 0$ y usar `long long` para soportar
    términos mayores.
-   **[*plus ultra*]:** Descomponer la lógica con llaves Allman e inicialización
    limpia.

:::
<!-- {exercise} -->

:::{solution} ej-ref-fibonacci-micro
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

long long calcular_fibonacci(int posicion)
{
    if (posicion < 0)
    {
        return -1;
    }
    if (posicion == 0)
    {
        return 0;
    }
    if (posicion == 1)
    {
        return 1;
    }

    long long anterior = 0;
    long long actual = 1;

    for (int i = 2; i <= posicion; i++)
    {
        long long siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }
    return actual;
}

void test_fibonacci(void)
{
    assert(calcular_fibonacci(0) == 0);
    assert(calcular_fibonacci(1) == 1);
    assert(calcular_fibonacci(6) == 8);
    assert(calcular_fibonacci(10) == 55);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-fibonacci-micro -->

---

(ejercicio_9_ref_20)=
### Ejercicio 9.20 - Conteo de Números Armstrong Desordenado ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-armstrong-desordenado
El siguiente código verifica si un número de 3 dígitos es igual a la suma del
cubo de sus dígitos, pero está escrito de forma ilegible:

``` c
int arm(int x){int a=x/100,b=(x/10)%10,c=x%10;return(a*a*a+b*b*b+c*c*c==x)?1:0;}
```
<!-- c -->

-   **[*plus ultra*]:** Eliminar el ternario `?:` y retornar un `bool`.
-   **[*plus ultra*]:** Generalizar para cualquier cantidad de dígitos mediante
    funciones auxiliares.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_21)=
### Ejercicio 9.21 - Factorial con Detección de Desbordamiento Oculto ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-fact-desborde
Refactorizá la siguiente función de factorial:

``` c
long f(int n){if(n<0||n>20)return -1;long r=1;for(int i=2;i<=n;i++)r*=i;return r;}
```
<!-- c -->

-   **[*plus ultra*]:** Reemplazar el número mágico `20` por una constante
    descriptiva `#define MAX_FACTORIAL_LONG 20`.
-   **[*plus ultra*]:** Escribir tests unitarios con `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-fact-desborde
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

#define MAX_N_FACTORIAL_64BITS 20

long long calcular_factorial(int n)
{
    if (n < 0 || n > MAX_N_FACTORIAL_64BITS)
    {
        return -1;
    }
    long long resultado = 1;
    for (int factor = 2; factor <= n; factor++)
    {
        resultado *= factor;
    }
    return resultado;
}

void test_factorial(void)
{
    assert(calcular_factorial(0) == 1);
    assert(calcular_factorial(5) == 120);
    assert(calcular_factorial(21) == -1); // Error de desbordamiento
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-fact-desborde -->

---

(ejercicio_9_ref_22)=
### Ejercicio 9.22 - Números Perfectos con Lazo Ineficiente ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-perfecto-ineficiente
Refactorizá la siguiente función que verifica números perfectos (donde la suma
de divisores propios es igual al número):

``` c
int perf(int n){int s=0;for(int i=1;i<n;i++){if(n%i==0)s+=i;}return s==n;}
```
<!-- c -->

-   **[*plus ultra*]:** Optimizar sumando divisores en pares hasta $\sqrt{n}$.
-   **[*plus ultra*]:** Retornar un `bool` claro y documentar precondiciones.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_23)=
### Ejercicio 9.23 - Cálculo de Potencia Rápida Oculto ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-potencia-rapida
Descifrá el algoritmo y refactorizalo a código limpio:

``` c
double p(double b,int e){double r=1.0;int n=(e<0)?-e:e;while(n){if(n%2)r*=b;b*=b;n/=2;}return(e<0)?1.0/r:r;}
```
<!-- c -->

-   **[*plus ultra*]:** Eliminar los operadores ternarios y usar cláusulas de
    guarda.
-   **[*plus ultra*]:** Escribir tests unitarios para exponentes positivos,
    negativos y cero.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_24)=
### Ejercicio 9.24 - Desglose de Dinero con Lazos Confusos ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-desglose-dinero
Refactorizá la siguiente función que calcula monedas de cambio de manera
ofuscada:

``` c
int c100,c50,c10;
void m(int x){c100=x/100;x%=100;c50=x/50;x%=50;c10=x/10;}
```
<!-- c -->

-   **[*plus ultra*]:** Eliminar las variables globales retornando los
    resultados mediante parámetros o empaquetándolos en funciones atómicas.
-   **[*plus ultra*]:** Validar que el monto no sea negativo.

:::
<!-- {exercise} -->

:::{solution} ej-ref-desglose-dinero
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool desglosar_cambio(int monto, int *monedas_100, int *monedas_50, int *monedas_10)
{
    if (monto < 0 || monedas_100 == NULL || monedas_50 == NULL || monedas_10 == NULL)
    {
        return false;
    }
    *monedas_100 = monto / 100;
    monto %= 100;

    *monedas_50 = monto / 50;
    monto %= 50;

    *monedas_10 = monto / 10;
    return true;
}

void test_desglose_cambio(void)
{
    int m100 = 0, m50 = 0, m10 = 0;
    bool ok = desglosar_cambio(370, &m100, &m50, &m10);
    assert(ok && m100 == 3 && m50 == 1 && m10 == 2);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-desglose-dinero -->

---

## 4. Descomposición Modular y Funciones Reutilizables

(ejercicio_9_ref_25)=
### Ejercicio 9.25 - La Función Monstruo de Facturación ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-funcion-monstruo
La siguiente función viola el Principio de Responsabilidad Única ([Regla
0x2005h](../../reglas/2_funciones.md#0x2005h)) y mezcla E/S con cálculos.
Descomponela en al menos 3 funciones atómicas puras y un `main` interactivo:

```{code-block} c
:linenos:
#include <stdio.h>

void facturar(double p, int cant, int tipo, double saldo)
{
    double sub = p * cant;
    double desc = 0;
    if (tipo == 1) desc = sub * 0.10;
    else if (tipo == 2) desc = sub * 0.20;
    double iva = (sub - desc) * 0.21;
    double total = (sub - desc) + iva;
    printf("Total: %.2f\n", total);
    if (saldo >= total) {
        printf("Pago exitoso. Saldo restante: %.2f\n", saldo - total);
    } else {
        printf("Saldo insuficiente\n");
    }
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Crear `calcular_subtotal`, `calcular_descuento`,
    `calcular_iva` y `verificar_saldo`.
-   **[*plus ultra*]:** Escribir pruebas unitarias con `assert()` para cada
    función pura.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_26)=
### Ejercicio 9.26 - Herón y Clasificación de Triángulos Todo-en-Uno ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-heron-todo-en-uno
Refactorizá la siguiente función separando la validación geométrica, el cálculo
del área por fórmula de Herón y la clasificación del triángulo en funciones
independientes:

```{code-block} c
:linenos:
#include <math.h>

double tri(double a, double b, double c, int *tipo)
{
    if (a+b<=c||a+c<=b||b+c<=a) { *tipo=0; return 0; }
    if (a==b&&b==c) *tipo=1;
    else if (a==b||b==c||a==c) *tipo=2;
    else *tipo=3;
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Usar comparación con tolerancia `fabs(a - b) < 1e-6`
    para punto flotante.
-   **[*plus ultra*]:** Escribir tests unitarios para cada función por separado.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_27)=
### Ejercicio 9.27 - Duplicación de Código de Tiempo (Violación DRY) ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-violacion-dry
El siguiente programa repite tres veces la misma lógica de cálculo de segundos a
HH:MM:SS en diferentes lugares. Aplicá el principio **DRY (Don't Repeat
Yourself)** abstrayendo la lógica en una función reutilizable:

```{code-block} c
:linenos:
void imprimir_tres_horarios(int t1, int t2, int t3)
{
    int h1 = t1 / 3600; int m1 = (t1 % 3600) / 60; int s1 = t1 % 60;
    int h2 = t2 / 3600; int m2 = (t2 % 3600) / 60; int s2 = t2 % 60;
    int h3 = t3 / 3600; int m3 = (t3 % 3600) / 60; int s3 = t3 % 60;
    // ...
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Implementar `void descomponer_segundos(int
    total_segundos, int *h, int *m, int *s)`.
-   **[*plus ultra*]:** Escribir pruebas unitarias para la función de
    descomposición.

:::
<!-- {exercise} -->

:::{solution} ej-ref-violacion-dry
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool descomponer_segundos(int total_segundos, int *horas, int *minutos, int *segundos)
{
    if (total_segundos < 0 || horas == NULL || minutos == NULL || segundos == NULL)
    {
        return false;
    }
    *horas = total_segundos / 3600;
    int resto = total_segundos % 3600;
    *minutos = resto / 60;
    *segundos = resto % 60;
    return true;
}

void test_descomponer_segundos(void)
{
    int h = 0, m = 0, s = 0;
    assert(descomponer_segundos(3665, &h, &m, &s));
    assert(h == 1 && m == 1 && s == 5);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-violacion-dry -->

---

(ejercicio_9_ref_28)=
### Ejercicio 9.28 - Máquina de Estados con Estados Mágicos ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-fsm-estados-magicos
Refactorizá la siguiente máquina de estados que usa números enteros mágicos (`0,
1, 2, 3`) para procesar palabras, sustituyéndolos por un `enum` autoexplicativo
y funciones de transición puras:

```{code-block} c
:linenos:
int st = 0;

void step(char c)
{
    if (st == 0 && c != ' ') st = 1;
    else if (st == 1 && c == ' ') st = 2;
    else if (st == 2 && c != ' ') st = 1;
    else if (c == '\n') st = 3;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Eliminar la variable global `st`.
-   **[*plus ultra*]:** Escribir una suite de pruebas de transición de estados.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_29)=
### Ejercicio 9.29 - Validación de Entrada con Lazos Desacoplados ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-validacion-desacoplada
Refactorizá la siguiente función para separar la lógica de validación matemática
de la lógica interactiva de reintento:

```{code-block} c
:linenos:
#include <stdio.h>

int pedir_entero_rango(int min, int max)
{
    int val;
    while (1) {
        printf("Ingrese valor entre %d y %d: ", min, max);
        if (scanf("%d", &val) == 1) {
            if (val >= min && val <= max) {
                return val;
            }
        }
        printf("Invalido, reintente.\n");
        while (getchar() != '\n'); // Limpia buffer
    }
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Extraer la función pura `bool esta_en_rango(int valor,
    int min, int max)`.
-   **[*plus ultra*]:** Escribir tests con `assert()` para `esta_en_rango`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-validacion-desacoplada
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool esta_en_rango(int valor, int limite_inferior, int limite_superior)
{
    return (valor >= limite_inferior && valor <= limite_superior);
}

void test_esta_en_rango(void)
{
    assert(esta_en_rango(5, 1, 10) == true);
    assert(esta_en_rango(1, 1, 10) == true);
    assert(esta_en_rango(10, 1, 10) == true);
    assert(esta_en_rango(0, 1, 10) == false);
    assert(esta_en_rango(11, 1, 10) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-validacion-desacoplada -->

---

(ejercicio_9_ref_30)=
### Ejercicio 9.30 - Tabla de Multiplicar Formateada y Modularizada ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-tabla-multiplicar-modular
Refactorizá la siguiente función que imprime tablas de multiplicar desacoplando
la generación del producto de la salida por pantalla:

```{code-block} c
:linenos:
#include <stdio.h>

void tabla(int n)
{
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Implementar `int calcular_producto(int multiplicando,
    int multiplicador)`.
-   **[*plus ultra*]:** Formatear las columnas en `imprimir_tabla` con ancho
    fijo `%2d x %2d = %4d`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-tabla-multiplicar-modular
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>

int calcular_producto(int multiplicando, int multiplicador)
{
    return multiplicando * multiplicador;
}

void imprimir_tabla_multiplicar(int numero)
{
    for (int factor = 1; factor <= 10; factor++)
    {
        int resultado = calcular_producto(numero, factor);
        printf("%2d x %2d = %4d\n", numero, factor, resultado);
    }
}

void test_calcular_producto(void)
{
    assert(calcular_producto(7, 8) == 56);
    assert(calcular_producto(0, 5) == 0);
    assert(calcular_producto(-3, 4) == -12);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-tabla-multiplicar-modular -->

---

(ejercicio_9_ref_31)=
### Ejercicio 9.31 - Algoritmo de Luhn Comprimido ⭐⭐⭐⭐⭐

:::{exercise}
:label: ej-ref-luhn-comprimido
El siguiente código implementa el algoritmo de validación de identificación
(Algoritmo de Luhn) para números enteros de longitud variable, pero fue ofuscado
deliberadamente en 4 líneas densas con asignaciones dobles y operadores
ternarios anidados:

``` c
int l(long long n){int s=0,c=0,d;while(n>0){d=n%10;if(c%2!=0){d*=2;if(d>9)d-=9;}s+=d;n/=10;c++;}return(s%10==0)?1:0;}
```
<!-- c -->

**Tu tarea:**
1. Desentrañar cómo opera el conteo de posiciones de derecha a izquierda y la
   duplicación alternada.
2. Identificar todos los code smells (nombres mudos `l, s, c, d`, ternario `?:`,
   falta de llaves Allman, falta de validación de entradas negativas).
3. Refactorizar el algoritmo en funciones modulares puras:
   - `int transformar_digito_luhn(int digito)`: multiplica por 2 y resta 9 si
     supera 9.
   - `bool validar_numero_luhn(long long numero_cuenta)`: calcula la suma total
     y verifica si es múltiplo de 10.
4. Escribir una suite de pruebas con `assert()` que verifique números válidos e
   inválidos reales (ej. `49927398716` es válido).

-   **[*plus ultra*]:** Documentar con contratos `@pre` y `@post`.
-   **[*plus ultra*]:** Validar que números $\le 0$ retornen `false`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_32)=
### Ejercicio 9.32 - Congruencia de Zeller Astronómica ⭐⭐⭐⭐⭐

:::{exercise}
:label: ej-ref-calendario-astronomico
Analizá el siguiente bloque de código. Es un algoritmo astronómico comprimido
que calcula el día de la semana (0=Domingo, 1=Lunes, ..., 6=Sábado) para
cualquier fecha del calendario gregoriano utilizando la **Congruencia de
Zeller** con meses ajustados (marzo=3, ..., diciembre=12, enero=13 del año
anterior, febrero=14 del año anterior):

``` c
int z(int d,int m,int y){if(m<3)m+=12,y--;int k=y%100,j=y/100;int h=(d+13*(m+1)/5+k+k/4+j/4+5*j)%7;return(h+6)%7;}
```
<!-- c -->

**Tu tarea:**
1. Desarmar la fórmula críptica identificando qué representan `k, j, h` y la
   constante `13*(m+1)/5`.
2. Validar que la fecha sea válida antes de evaluar la fórmula (usando
   `es_fecha_valida`).
3. Refactorizar el cálculo en funciones puras, legibles, documentadas con
   Doxygen, con constantes claras y estilo Allman.
4. Escribir una suite de pruebas con `assert()` para fechas históricas
   conocidas:
   - 25 de Mayo de 1810 $\rightarrow$ Viernes (5).
   - 9 de Julio de 1816 $\rightarrow$ Martes (2).
   - 1 de Enero de 2000 $\rightarrow$ Sábado (6).
   - 29 de Febrero de 2024 $\rightarrow$ Jueves (4).

-   **[*plus ultra*]:** Retornar un `enum` con los días de la semana
    `DIA_DOMINGO, DIA_LUNES, ...`.
-   **[*plus ultra*]:** Manejar fechas inválidas retornando `-1` o un código de
    error de estado.

:::
<!-- {exercise} -->

---

## 5. Lazos Anidados, Matrices y Patrones Numéricos

(ejercicio_9_ref_33)=
### Ejercicio 9.33 - Rectángulo de Asteriscos Comprimido ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-rectangulo-asteriscos
Analizá el siguiente código que imprime un rectángulo en consola mediante lazos
anidados en una sola línea y refactorizalo:

``` c
void r(int w,int h){for(int i=0;i<h;i++){for(int j=0;j<w;j++)printf("*");printf("\n");}}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que ancho y alto sean mayores a cero.
-   **[*plus ultra*]:** Modularizar la impresión de una fila de caracteres en
    una función auxiliar `void imprimir_fila(char c, int longitud)`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-rectangulo-asteriscos
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <stdio.h>

void imprimir_fila_caracter(char caracter, int longitud)
{
    for (int columna = 0; columna < longitud; columna++)
    {
        putchar(caracter);
    }
    putchar('\n');
}

void imprimir_rectangulo(int ancho, int alto)
{
    if (ancho <= 0 || alto <= 0)
    {
        return;
    }
    for (int fila = 0; fila < alto; fila++)
    {
        imprimir_fila_caracter('*', ancho);
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-rectangulo-asteriscos -->

---

(ejercicio_9_ref_34)=
### Ejercicio 9.34 - Matriz Identidad con Ternario Críptico ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-matriz-identidad
Refactorizá la siguiente función que determina el valor de cada celda en una
matriz identidad eliminando el ternario prohibido:

``` c
int id(int r,int c){return(r==c)?1:0;}
```
<!-- c -->

-   **[*plus ultra*]:** Escribir una función pura `int
    obtener_valor_identidad(int fila, int columna)` con validación de índices no
    negativos.
-   **[*plus ultra*]:** Testear con `assert()` celdas diagonales y fuera de la
    diagonal.

:::
<!-- {exercise} -->

:::{solution} ej-ref-matriz-identidad
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

int obtener_valor_identidad(int fila, int columna)
{
    if (fila < 0 || columna < 0)
    {
        return -1;
    }
    if (fila == columna)
    {
        return 1;
    }
    return 0;
}

void test_valor_identidad(void)
{
    assert(obtener_valor_identidad(0, 0) == 1);
    assert(obtener_valor_identidad(2, 2) == 1);
    assert(obtener_valor_identidad(0, 3) == 0);
    assert(obtener_valor_identidad(-1, 0) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-matriz-identidad -->

---

(ejercicio_9_ref_35)=
### Ejercicio 9.35 - Conteo de Vocales con Cascada Repetitiva ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-conteo-vocales
El siguiente código cuenta vocales en un arreglo de caracteres pero repite
condiciones `if` de manera poco idiomática:

``` c
int v(char a[], int n){int c=0;for(int i=0;i<n;i++){char x=a[i];if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')c++;}return c;}
```
<!-- c -->

-   **[*plus ultra*]:** Modularizar en una función auxiliar pura `bool
    es_vocal(char c)` usando `switch` o `tolower()`.
-   **[*plus ultra*]:** Agregar `const` al arreglo y escribir tests con
    `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-conteo-vocales
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

bool es_vocal(char caracter)
{
    char c = (char)tolower((unsigned char)caracter);
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int contar_vocales_secuencia(const char caracteres[], int longitud)
{
    if (caracteres == NULL || longitud <= 0)
    {
        return 0;
    }
    int total_vocales = 0;
    for (int i = 0; i < longitud; i++)
    {
        if (es_vocal(caracteres[i]))
        {
            total_vocales++;
        }
    }
    return total_vocales;
}

void test_conteo_vocales(void)
{
    char mensaje[] = {'H', 'o', 'l', 'a', 'M', 'u', 'n', 'd', 'o'};
    assert(contar_vocales_secuencia(mensaje, 9) == 4);
    assert(contar_vocales_secuencia(NULL, 0) == 0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-conteo-vocales -->

---

(ejercicio_9_ref_36)=
### Ejercicio 9.36 - Coeficiente Binomial Redundante ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-coef-binomial
Refactorizá la siguiente función que calcula $\binom{n}{k}$ recalculando 3
factoriales completos de forma ineficiente y propensa a desbordamientos:

``` c
long long fact(int n){long long r=1;for(int i=2;i<=n;i++)r*=i;return r;}
long long binom(int n,int k){if(k<0||k>n)return 0;return fact(n)/(fact(k)*fact(n-k));}
```
<!-- c -->

-   **[*plus ultra*]:** Optimizar calculando $\binom{n}{k} = \prod_{i=1}^k
    \frac{n - k + i}{i}$ para evitar desbordamientos prematuros.
-   **[*plus ultra*]:** Escribir tests unitarios para $\binom{5}{2} = 10$,
    $\binom{10}{0} = 1$ y $\binom{20}{5} = 15504$.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_37)=
### Ejercicio 9.37 - Primos Gemelos con Variables Globales ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-primos-gemelos
Refactorizá la siguiente función que utiliza variables globales para verificar
si dos números son primos gemelos ($p_2 = p_1 + 2$):

```{code-block} c
:linenos:
int g_p1, g_p2;
int son_gem(void)
{
    if (g_p2 != g_p1 + 2) return 0;
    // ...
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Reutilizar una función pura `bool es_primo(int n)`.
-   **[*plus ultra*]:** Diseñar `bool son_primos_gemelos(int primer_numero, int
    segundo_numero)` sin variables globales.

:::
<!-- {exercise} -->

:::{solution} ej-ref-primos-gemelos
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

static bool es_primo_auxiliar(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (int d = 3; d * d <= n; d += 2)
    {
        if (n % d == 0)
        {
            return false;
        }
    }
    return true;
}

bool son_primos_gemelos(int primer_numero, int segundo_numero)
{
    if (segundo_numero != primer_numero + 2)
    {
        return false;
    }
    return es_primo_auxiliar(primer_numero) && es_primo_auxiliar(segundo_numero);
}

void test_primos_gemelos(void)
{
    assert(son_primos_gemelos(3, 5) == true);
    assert(son_primos_gemelos(11, 13) == true);
    assert(son_primos_gemelos(7, 9) == false);
    assert(son_primos_gemelos(4, 6) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-primos-gemelos -->

---

(ejercicio_9_ref_38)=
### Ejercicio 9.38 - Criba de Divisores Estática ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-criba-estatica
Refactorizá la siguiente función que llena un arreglo indicando la cantidad de
divisores propios de cada número:

``` c
void c(int a[],int n){for(int i=1;i<=n;i++){a[i-1]=0;for(int j=1;j<i;j++)if(i%j==0)a[i-1]++;}}
```
<!-- c -->

-   **[*plus ultra*]:** Descomponer en `int contar_divisores_propios(int n)` y
    `void llenar_tabla_divisores(int tabla[], int n)`.
-   **[*plus ultra*]:** Validar que `n > 0` y puntero no nulo.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_39)=
### Ejercicio 9.39 - Suma de Diagonales en Arreglo 2D Plano ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-suma-diagonales
Refactorizá la siguiente función que suma la diagonal principal y secundaria de
una matriz cuadrada de tamaño $N \times N$ representada en un arreglo
unidimensional plano (`arr[i * n + j]`):

``` c
int d(int a[],int n){int s=0;for(int i=0;i<n;i++)s+=a[i*n+i]+a[i*n+(n-1-i)];if(n%2!=0)s-=a[(n/2)*n+(n/2)];return s;}
```
<!-- c -->

-   **[*plus ultra*]:** Explicar por qué se resta el elemento central cuando $n$
    es impar.
-   **[*plus ultra*]:** Refactorizar en estilo Allman con nombres claros.

:::
<!-- {exercise} -->

:::{solution} ej-ref-suma-diagonales
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

int calcular_suma_diagonales(const int matriz_plana[], int dimension)
{
    if (matriz_plana == NULL || dimension <= 0)
    {
        return 0;
    }
    int suma = 0;
    for (int i = 0; i < dimension; i++)
    {
        int indice_diag_principal = (i * dimension) + i;
        int indice_diag_secundaria = (i * dimension) + (dimension - 1 - i);

        suma += matriz_plana[indice_diag_principal];
        suma += matriz_plana[indice_diag_secundaria];
    }

    // Si la dimensión es impar, el elemento central fue sumado dos veces
    if (dimension % 2 != 0)
    {
        int centro = dimension / 2;
        int indice_centro = (centro * dimension) + centro;
        suma -= matriz_plana[indice_centro];
    }

    return suma;
}

void test_suma_diagonales(void)
{
    int m3[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(calcular_suma_diagonales(m3, 3) == 25);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-suma-diagonales -->

---

(ejercicio_9_ref_40)=
### Ejercicio 9.40 - Conjetura de Collatz Caótica ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-collatz-caotica
Refactorizá la siguiente función que cuenta la cantidad de pasos hasta llegar a
1 en la secuencia de Collatz ($3n+1$), la cual mezcla ternarios y lazos
`while(1)`:

``` c
int col(long long n){int c=0;if(n<=0)return -1;while(1){if(n==1)break;n=(n%2==0)?n/2:3*n+1;c++;}return c;}
```
<!-- c -->

-   **[*plus ultra*]:** Eliminar el ternario y el `while(1)`.
-   **[*plus ultra*]:** Escribir tests con `assert()` para `col(1) == 0`,
    `col(6) == 8` y `col(27) == 111`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_41)=
### Ejercicio 9.41 - Transposición de Matriz $3 \times 3$ ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-transposicion-matriz
Refactorizá la siguiente función que transpone una matriz $3 \times 3$ en un
arreglo destino:

``` c
void t(int s[9],int d[9]){for(int i=0;i<3;i++)for(int j=0;j<3;j++)d[j*3+i]=s[i*3+j];}
```
<!-- c -->

-   **[*plus ultra*]:** Definir constantes `#define MAT_FILAS 3` y `#define
    MAT_COLUMNAS 3`.
-   **[*plus ultra*]:** Escribir una suite de tests con `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-transposicion-matriz
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

#define MAT_FILAS 3
#define MAT_COLUMNAS 3

void transponer_matriz_3x3(const int origen[9], int destino[9])
{
    if (origen == NULL || destino == NULL)
    {
        return;
    }
    for (int fila = 0; fila < MAT_FILAS; fila++)
    {
        for (int col = 0; col < MAT_COLUMNAS; col++)
        {
            int idx_origen = (fila * MAT_COLUMNAS) + col;
            int idx_destino = (col * MAT_FILAS) + fila;
            destino[idx_destino] = origen[idx_origen];
        }
    }
}

void test_transposicion_3x3(void)
{
    int orig[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int dest[9] = {0};
    transponer_matriz_3x3(orig, dest);

    assert(dest[0] == 1 && dest[1] == 4 && dest[2] == 7);
    assert(dest[3] == 2 && dest[4] == 5 && dest[5] == 8);
    assert(dest[6] == 3 && dest[7] == 6 && dest[8] == 9);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-transposicion-matriz -->

---

(ejercicio_9_ref_42)=
### Ejercicio 9.42 - Multiplicación de Matrices Cuadradas Comprimida ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-multiplicacion-matrices
Analizá y refactorizá la siguiente función que multiplica dos matrices cuadradas
de tamaño $N \times N$ representadas en arreglos unidimensionales planos:

``` c
void mx(int a[],int b[],int c[],int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++){int s=0;for(int k=0;k<n;k++)s+=a[i*n+k]*b[k*n+j];c[i*n+j]=s;}}
```
<!-- c -->

**Tu tarea:**
1. Descomponer el triple lazo anidado aplicando estilo Allman riguroso y nombres
   autoexplicativos (`fila, columna, indice_k`).
2. Validar que los punteros no sean nulos y que la dimensión $N > 0$.
3. Escribir una función auxiliar para calcular el producto escalar entre una
   fila de $A$ y una columna de $B$.
4. Diseñar pruebas unitarias con `assert()` multiplicando matrices identidad y
   matrices con números enteros conocidos.

-   **[*plus ultra*]:** Documentar con Doxygen precondiciones de no solapamiento
    de punteros.

:::
<!-- {exercise} -->

---

## 6. Validación de Formatos, Parsing y Protocolos Simples

(ejercicio_9_ref_43)=
### Ejercicio 9.43 - Validador de Hora Militar Comprimido ⭐☆☆☆☆

:::{exercise}
:label: ej-ref-hora-militar
Refactorizá la siguiente función de validación de horarios en formato 24 horas:

``` c
int ch(int h,int m,int s){return(h>=0&&h<24&&m>=0&&m<60&&s>=0&&s<60)?1:0;}
```
<!-- c -->

-   **[*plus ultra*]:** Retornar un `bool` y eliminar el operador ternario.
-   **[*plus ultra*]:** Usar constantes para los límites `#define MAX_HORAS 24`,
    `#define MAX_MINUTOS 60`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-hora-militar
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

#define MIN_HORAS 0
#define MAX_HORAS 23
#define MIN_MINUTOS 0
#define MAX_MINUTOS 59
#define MIN_SEGUNDOS 0
#define MAX_SEGUNDOS 59

bool es_horario_valido(int horas, int minutos, int segundos)
{
    if (horas < MIN_HORAS || horas > MAX_HORAS)
    {
        return false;
    }
    if (minutos < MIN_MINUTOS || minutos > MAX_MINUTOS)
    {
        return false;
    }
    if (segundos < MIN_SEGUNDOS || segundos > MAX_SEGUNDOS)
    {
        return false;
    }
    return true;
}

void test_es_horario_valido(void)
{
    assert(es_horario_valido(14, 30, 0) == true);
    assert(es_horario_valido(23, 59, 59) == true);
    assert(es_horario_valido(24, 0, 0) == false);
    assert(es_horario_valido(12, -1, 0) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-hora-militar -->

---

(ejercicio_9_ref_44)=
### Ejercicio 9.44 - Conversor de Caracteres a Entero (`atoi` Casero) ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-atoi-casero
Refactorizá la siguiente función que parsea una secuencia de dígitos ASCII a un
entero:

``` c
int parse(char s[], int n){int r=0,i=0,sg=1;if(s[0]=='-'){sg=-1;i=1;}for(;i<n;i++)r=r*10+(s[i]-'0');return r*sg;}
```
<!-- c -->

-   **[*plus ultra*]:** Validar que todos los caracteres entre `i` y `n` sean
    efectivamente dígitos con `isdigit()`.
-   **[*plus ultra*]:** Retornar un código de estado booleano `bool *exito`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-atoi-casero
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

int convertir_caracteres_a_entero(const char digitos[], int longitud, bool *exito)
{
    if (digitos == NULL || longitud <= 0 || exito == NULL)
    {
        if (exito != NULL)
        {
            *exito = false;
        }
        return 0;
    }

    *exito = true;
    int signo = 1;
    int indice_inicio = 0;

    if (digitos[0] == '-')
    {
        signo = -1;
        indice_inicio = 1;
        if (longitud == 1)
        {
            *exito = false;
            return 0;
        }
    }

    int acumulador = 0;
    for (int i = indice_inicio; i < longitud; i++)
    {
        if (!isdigit((unsigned char)digitos[i]))
        {
            *exito = false;
            return 0;
        }
        acumulador = (acumulador * 10) + (digitos[i] - '0');
    }

    return acumulador * signo;
}

void test_convertir_a_entero(void)
{
    bool ok = false;
    char num1[] = {'1', '2', '3', '4'};
    assert(convertir_caracteres_a_entero(num1, 4, &ok) == 1234 && ok);

    char num2[] = {'-', '5', '0'};
    assert(convertir_caracteres_a_entero(num2, 3, &ok) == -50 && ok);

    char inv[] = {'1', '2', 'x', '4'};
    convertir_caracteres_a_entero(inv, 4, &ok);
    assert(!ok);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-atoi-casero -->

---

(ejercicio_9_ref_45)=
### Ejercicio 9.45 - Validador de Octetos IPv4 Caótico ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-ipv4-caotico
Refactorizá la siguiente función que valida si 4 enteros representan una
dirección IPv4 válida ($0 \le x \le 255$):

``` c
int v4(int a,int b,int c,int d){if(a<0||a>255)return 0;if(b<0||b>255)return 0;if(c<0||c>255)return 0;if(d<0||d>255)return 0;return 1;}
```
<!-- c -->

-   **[*plus ultra*]:** Extraer la función pura `bool es_octeto_valido(int
    octeto)` (principio DRY).
-   **[*plus ultra*]:** Retornar un `bool` e incluir tests unitarios.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_46)=
### Ejercicio 9.46 - Verificador de CUIT/CUIL con Módulo 11 ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-cuit-modulo11
Refactorizá el siguiente cálculo del dígito verificador de un CUIT argentino de
10 dígitos (factores: `5, 4, 3, 2, 7, 6, 5, 4, 3, 2`):

``` c
int dv(int d[10]){int f[10]={5,4,3,2,7,6,5,4,3,2},s=0;for(int i=0;i<10;i++)s+=d[i]*f[i];int r=11-(s%11);if(r==11)return 0;if(r==10)return 9;return r;}
```
<!-- c -->

-   **[*plus ultra*]:** Aplicar estilo Allman y nombres descriptivos.
-   **[*plus ultra*]:** Validar con `assert()` para CUITs conocidos.

:::
<!-- {exercise} -->

:::{solution} ej-ref-cuit-modulo11
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

#define CANTIDAD_DIGITOS_BASE_CUIT 10

int calcular_digito_verificador_cuit(const int primeros_10_digitos[10])
{
    if (primeros_10_digitos == NULL)
    {
        return -1;
    }
    static const int factores_ponderacion[10] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2};

    int suma_ponderada = 0;
    for (int i = 0; i < CANTIDAD_DIGITOS_BASE_CUIT; i++)
    {
        if (primeros_10_digitos[i] < 0 || primeros_10_digitos[i] > 9)
        {
            return -1;
        }
        suma_ponderada += (primeros_10_digitos[i] * factores_ponderacion[i]);
    }

    int resto = suma_ponderada % 11;
    int digito_calculado = 11 - resto;

    if (digito_calculado == 11)
    {
        return 0;
    }
    if (digito_calculado == 10)
    {
        return 9;
    }
    return digito_calculado;
}

void test_cuit_verificador(void)
{
    int digitos_test[10] = {2, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int dv = calcular_digito_verificador_cuit(digitos_test);
    assert(dv >= 0 && dv <= 9);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-cuit-modulo11 -->

---

(ejercicio_9_ref_47)=
### Ejercicio 9.47 - Compactador de Espacios Repetidos ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-compactar-espacios
Refactorizá la siguiente función que copia caracteres de `orig` a `dest`
colapsando múltiples espacios consecutivos en uno solo:

``` c
int comp(char o[],int n,char d[]){int j=0,e=0;for(int i=0;i<n;i++){if(o[i]==' '){if(!e){d[j++]=' ';e=1;}}else{d[j++]=o[i];e=0;}}return j;}
```
<!-- c -->

-   **[*plus ultra*]:** Retornar la nueva longitud escrita en `d`.
-   **[*plus ultra*]:** Escribir tests con `assert()` verificando secuencias con
    múltiples espacios.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_48)=
### Ejercicio 9.48 - Validador de Fortaleza de Contraseña ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-fortaleza-password
Refactorizá la siguiente función que evalúa si una contraseña en arreglo tiene
al menos 8 caracteres, al menos una mayúscula y al menos un dígito:

``` c
int pass(char p[],int n){int u=0,d=0;if(n<8)return 0;for(int i=0;i<n;i++){if(p[i]>='A'&&p[i]<='Z')u=1;if(p[i]>='0'&&p[i]<='9')d=1;}return(u&&d)?1:0;}
```
<!-- c -->

-   **[*plus ultra*]:** Usar `isupper()` e `isdigit()` de `<ctype.h>`.
-   **[*plus ultra*]:** Retornar un `bool` y estructurar con contratos.

:::
<!-- {exercise} -->

:::{solution} ej-ref-fortaleza-password
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

#define LONGITUD_MINIMA_CLAVE 8

bool validar_fortaleza_clave(const char clave[], int longitud)
{
    if (clave == NULL || longitud < LONGITUD_MINIMA_CLAVE)
    {
        return false;
    }

    bool tiene_mayuscula = false;
    bool tiene_digito = false;

    for (int i = 0; i < longitud; i++)
    {
        if (isupper((unsigned char)clave[i]))
        {
            tiene_mayuscula = true;
        }
        if (isdigit((unsigned char)clave[i]))
        {
            tiene_digito = true;
        }
    }

    return tiene_mayuscula && tiene_digito;
}

void test_fortaleza_clave(void)
{
    char c1[] = {'P', 'a', 's', 's', 'w', 'o', 'r', 'd', '1'};
    assert(validar_fortaleza_clave(c1, 9) == true);

    char c2[] = {'p', 'a', 's', 's', '1'};
    assert(validar_fortaleza_clave(c2, 5) == false);

    char c3[] = {'p', 'a', 's', 's', 'w', 'o', 'r', 'd', 's'};
    assert(validar_fortaleza_clave(c3, 9) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-fortaleza-password -->

---

(ejercicio_9_ref_49)=
### Ejercicio 9.49 - Decodificador Run-Length (RLE) Numérico ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-rle-numerico
Refactorizá la siguiente función que decodifica pares `(valor, repeticiones)` en
un arreglo plano:

```{code-block} c
:linenos:
int rle_dec(int pares[], int n_pares, int sal[], int max_sal)
{
    int k=0;
    for(int i=0;i<n_pares*2;i+=2){
        int val=pares[i]; int rep=pares[i+1];
        for(int r=0;r<rep;r++){
            if(k>=max_sal) return -1;
            sal[k++]=val;
        }
    }
    return k;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Validar que `rep >= 0` y no desborde `max_sal`.
-   **[*plus ultra*]:** Aplicar estilo Allman estricto y nombres descriptivos.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_50)=
### Ejercicio 9.50 - Conversor de Números Romanos Básicos ⭐⭐☆☆☆

:::{exercise}
:label: ej-ref-romanos-basicos
Refactorizá la siguiente función que convierte un carácter romano individual a
su valor numérico:

``` c
int r2d(char c){if(c=='I')return 1;if(c=='V')return 5;if(c=='X')return 10;if(c=='L')return 50;if(c=='C')return 100;if(c=='D')return 500;if(c=='M')return 1000;return 0;}
```
<!-- c -->

-   **[*plus ultra*]:** Refactorizar a un `switch` con cláusula `default`
    retornando `-1` ante error ([Regla
    0x1003h](../../reglas/1_control.md#0x1003h)).
-   **[*plus ultra*]:** Escribir tests unitarios con `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-ref-romanos-basicos
:class: dropdown
**Código Refactorizado:**
```{code-block} c
:linenos:
#include <assert.h>

int obtener_valor_simbolo_romano(char simbolo)
{
    switch (simbolo)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

void test_simbolos_romanos(void)
{
    assert(obtener_valor_simbolo_romano('X') == 10);
    assert(obtener_valor_simbolo_romano('M') == 1000);
    assert(obtener_valor_simbolo_romano('A') == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-ref-romanos-basicos -->

---

(ejercicio_9_ref_51)=
### Ejercicio 9.51 - Checksum de Paridad Longitudinal ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-checksum-paridad
Analizá el siguiente algoritmo que calcula la suma de verificación módulo 256
con residuo ajustado sobre un bloque de datos:

``` c
int chk(int d[],int n){int s=0;for(int i=0;i<n;i++)s=(s+d[i])%256;return(256-s)%256;}
```
<!-- c -->

**Tu tarea:**
1. Determinar cómo este checksum asegura que la suma de todos los datos más el
   checksum sea congruente con 0 módulo 256.
2. Refactorizar la función en estilo Allman con constantes simbólicas `#define
   MODULO_CHECKSUM 256`.
3. Validar entradas negativas o punteros nulos.
4. Escribir tests unitarios que verifiquen la invariante $\sum \text{datos} +
   \text{checksum} \equiv 0 \pmod{256}$.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_52)=
### Ejercicio 9.52 - Mini Intérprete de Pila de 4 Instrucciones ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-mini-interprete
El siguiente código implementa una máquina virtual de pila simple para evaluar
expresiones en notación postfija con 4 códigos (`1=PUSH`, `2=ADD`, `3=SUB`,
`4=HALT`):

``` c
int vm(int prg[],int n){int st[32],top=0;for(int i=0;i<n;i++){int op=prg[i];if(op==1)st[top++]=prg[++i];else if(op==2){int b=st[--top],a=st[--top];st[top++]=a+b;}else if(op==3){int b=st[--top],a=st[--top];st[top++]=a-b;}else if(op==4)break;}return st[top-1];}
```
<!-- c -->

**Tu tarea:**
1. Identificar riesgos de desbordamiento de pila (*stack overflow* y *stack
   underflow*).
2. Refactorizar usando un `enum` con los opcodes `OP_PUSH, OP_ADD, OP_SUB,
   OP_HALT`.
3. Extraer funciones auxiliares seguras para `push` y `pop` con verificación de
   límites.
4. Escribir tests unitarios que ejecuten programas de prueba válidos y detecten
   programas con errores.

:::
<!-- {exercise} -->

---

## 7. Desafíos Avanzados y Extra Difíciles

(ejercicio_9_ref_53)=
### Ejercicio 9.53 - Conversor de Base Numérica a Arreglo ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-conversor-base
Refactorizá la siguiente función que convierte un entero positivo a sus dígitos
en una base entre 2 y 16:

```{code-block} c
:linenos:
int base_conv(int n, int b, char out[], int max_len)
{
    char dig[]="0123456789ABCDEF"; int len=0;
    if(n==0){out[0]='0'; return 1;}
    while(n>0&&len<max_len){ out[len++]=dig[n%b]; n/=b; }
    for(int i=0;i<len/2;i++){ char t=out[i]; out[i]=out[len-1-i]; out[len-1-i]=t; }
    return len;
}

```
<!-- {code-block} c -->

-   **[*plus ultra*]:** Validar que $2 \le b \le 16$ y $n \ge 0$.
-   **[*plus ultra*]:** Modularizar la inversión del arreglo en una función
    `invertir_arreglo_char`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_54)=
### Ejercicio 9.54 - Búsqueda Binaria con Riesgo de Desbordamiento ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-busqueda-binaria-overflow
El siguiente código implementa búsqueda binaria pero utiliza el cálculo riesgoso
`int m = (l + r) / 2` que puede desbordar enteros grandes:

``` c
int bsearch(int a[],int n,int x){int l=0,r=n-1;while(l<=r){int m=(l+r)/2;if(a[m]==x)return m;if(a[m]<x)l=m+1;else r=m-1;}return -1;}
```
<!-- c -->

-   **[*plus ultra*]:** Reemplazar por `int medio = l + (r - l) / 2;`.
-   **[*plus ultra*]:** Agregar `const` al arreglo y formatear en Allman.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_55)=
### Ejercicio 9.55 - Ordenamiento Burbuja con Salida Temprana ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-burbuja-temprana
Refactorizá la siguiente función de ordenamiento burbuja escrita en un solo lazo
críptico:

``` c
void bsort(int a[],int n){int s=1;while(s){s=0;for(int i=0;i<n-1;i++)if(a[i]>a[i+1]){int t=a[i];a[i]=a[i+1];a[i+1]=t;s=1;}}}
```
<!-- c -->

**Tu tarea:**
1. Descomponer el algoritmo en dos lazos estructurados `for` en estilo Allman.
2. Extraer la función auxiliar pura `void intercambiar_enteros(int *a, int *b)`.
3. Escribir tests unitarios con `assert()` verificando arreglos desordenados,
   ordenados e invertidos.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_56)=
### Ejercicio 9.56 - Algoritmo de Kadane Comprimido ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-kadane-comprimido
Analizá el siguiente algoritmo que calcula la suma máxima de un subarreglo
contiguo (Algoritmo de Kadane) en una sola línea ofuscada:

``` c
int kad(int a[],int n){int m=a[0],c=a[0];for(int i=1;i<n;i++)c=(a[i]>c+a[i])?a[i]:c+a[i],m=(c>m)?c:m;return m;}
```
<!-- c -->

**Tu tarea:**
1. Eliminar los operadores ternarios y el operador coma `,`.
2. Escribir la lógica en estilo Allman con nombres claros (`maximo_global,
   maximo_actual`).
3. Validar que $N > 0$ y puntero no nulo.
4. Escribir tests unitarios para arreglos con números positivos, negativos y
   mixtos (ej. `{-2, 1, -3, 4, -1, 2, 1, -5, 4}` da `6`).

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_57)=
### Ejercicio 9.57 - Generador Pseudoaleatorio Congruencial (LCG) ⭐⭐⭐☆☆

:::{exercise}
:label: ej-ref-lcg-pseudoaleatorio
Refactorizá la siguiente función que genera el siguiente número pseudoaleatorio
usando la fórmula $X_{n+1} = (a X_n + c) \pmod m$:

``` c
int lcg(int seed){return(seed*1103515245+12345)&0x7FFFFFFF;}
```
<!-- c -->

-   **[*plus ultra*]:** Reemplazar constantes mágicas por `#define
    LCG_MULTIPLICADOR` y `#define LCG_INCREMENTO`.
-   **[*plus ultra*]:** Diseñar la función pura `int
    generar_siguiente_aleatorio(int semilla_actual)`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_58)=
### Ejercicio 9.58 - Ordenamiento por Inserción Compacto ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-insercion-compacto
Refactorizá la siguiente implementación de Insertion Sort:

``` c
void isort(int a[],int n){for(int i=1;i<n;i++){int k=a[i],j=i-1;while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;}}
```
<!-- c -->

**Tu tarea:**
1. Formatear en estilo Allman con llaves explícitas en todos los bloques.
2. Renombrar variables (`elemento_clave, indice_anterior`).
3. Escribir tests unitarios que validen el orden no decreciente del arreglo tras
   la ejecución.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_59)=
### Ejercicio 9.59 - Distancias Manhattan y Euclidiana Todo-en-Uno ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-distancias-vectores
Refactorizá la siguiente función que calcula distancias entre dos vectores de
$N$ dimensiones según un selector de modo:

``` c
double dist(double a[],double b[],int n,int m){double s=0;for(int i=0;i<n;i++){double d=fabs(a[i]-b[i]);s+=(m==1)?d:d*d;}return(m==1)?s:sqrt(s);}
```
<!-- c -->

**Tu tarea:**
1. Descomponer en dos funciones puras independientes:
   `calcular_distancia_manhattan` y `calcular_distancia_euclidiana`.
2. Eliminar el parámetro selector `m` y los operadores ternarios.
3. Escribir tests unitarios con `assert()` comparando con tolerancia `1e-6`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_60)=
### Ejercicio 9.60 - Conteo de Componentes Conexas 1D ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-componentes-conexas-1d
El siguiente código cuenta cuántas secuencias continuas de números positivos
existen en un arreglo:

``` c
int comp1d(int a[],int n){int c=0,in=0;for(int i=0;i<n;i++){if(a[i]>0&&!in){c++;in=1;}else if(a[i]<=0){in=0;}}return c;}
```
<!-- c -->

**Tu tarea:**
1. Refactorizar aplicando estilo Allman y nombres booleanos claros
   (`en_segmento_positivo`).
2. Validar casos de borde: todo positivo, todo negativo, arreglo vacío.
3. Escribir tests unitarios estructurados.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_61)=
### Ejercicio 9.61 - Vecinos de Conway en Cuadrícula $5 \times 5$ ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-conway-vecinos
Analizá y refactorizá la siguiente función que cuenta los vecinos vivos (valor
1) alrededor de una celda $(r, c)$ en una cuadrícula $5 \times 5$:

``` c
int nb(int g[25],int r,int c){int cnt=0;for(int dr=-1;dr<=1;dr++)for(int dc=-1;dc<=1;dc++){if(!dr&&!dc)continue;int nr=r+dr,nc=c+dc;if(nr>=0&&nr<5&&nc>=0&&nc<5)cnt+=g[nr*5+nc];}return cnt;}
```
<!-- c -->

**Tu tarea:**
1. Formatear la doble iteración en estilo Allman.
2. Definir constantes `#define GRILLA_DIMENSION 5`.
3. Extraer la función `bool esta_dentro_de_grilla(int fila, int columna)`.
4. Escribir tests con `assert()` para celdas esquinas, bordes y centrales.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_62)=
### Ejercicio 9.62 - Balanceador de Paréntesis Lineal ⭐⭐⭐⭐☆

:::{exercise}
:label: ej-ref-parentesis-balanceados
Refactorizá la siguiente función que verifica si los paréntesis `(` y `)` de una
cadena están correctamente balanceados:

``` c
int bal(char s[],int n){int d=0;for(int i=0;i<n;i++){if(s[i]=='(')d++;else if(s[i]==')'){d--;if(d<0)return 0;}}return(d==0)?1:0;}
```
<!-- c -->

**Tu tarea:**
1. Eliminar el operador ternario y retornar un `bool`.
2. Validar que un cierre sin apertura previa (`d < 0`) corte inmediatamente
   retornando `false`.
3. Escribir tests unitarios para `"(())"`, `"())("`, `"("` y `""`.

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_63)=
### Ejercicio 9.63 - [EXTRA DIFÍCIL] El Cuadrado Mágico y Verificador de Sudoku $3 \times 3$ ⭐⭐⭐⭐⭐

:::{exercise}
:label: ej-ref-cuadrado-magico-sudoku
El siguiente código evalúa si una matriz $3 \times 3$ plana de 9 elementos
contiene exactamente los dígitos del 1 al 9 sin repetir y si las sumas de todas
sus filas, columnas y diagonales son iguales a 15 (Cuadrado Mágico / Mini
Sudoku):

``` c
int sm(int m[9]){int u[10]={0},s=0;for(int i=0;i<9;i++){int v=m[i];if(v<1||v>9||u[v])return 0;u[v]=1;}for(int i=0;i<3;i++){int r=m[i*3]+m[i*3+1]+m[i*3+2],c=m[i]+m[i+3]+m[i+6];if(r!=15||c!=15)return 0;}int d1=m[0]+m[4]+m[8],d2=m[2]+m[4]+m[6];return(d1==15&&d2==15)?1:0;}
```
<!-- c -->

**Tu tarea:**
1. Desarmar la lógica monolítica identificando los tres pasos:
   - Verificación de permutación de dígitos 1 a 9.
   - Verificación de sumas de las 3 filas y 3 columnas igual a 15.
   - Verificación de las 2 diagonales igual a 15.
2. Descomponer el algoritmo en funciones auxiliares puras y modulares:
   - `bool contiene_digitos_1_a_9_unicos(const int matriz[9])`
   - `bool verificar_filas_y_columnas_magicas(const int matriz[9], int
     suma_esperada)`
   - `bool verificar_diagonales_magicas(const int matriz[9], int suma_esperada)`
   - `bool es_cuadrado_magico_3x3(const int matriz[9])`
3. Aplicar estilo Allman riguroso, constantes `#define CONSTANTE_MAGICA_3X3 15`
   y contratos Doxygen.
4. Escribir una suite de pruebas con `assert()` para el cuadrado mágico clásico
   de Lo Shu:
   $$\begin{pmatrix} 4 & 9 & 2 \\ 3 & 5 & 7 \\ 8 & 1 & 6 \end{pmatrix}$$

:::
<!-- {exercise} -->

---

(ejercicio_9_ref_64)=
### Ejercicio 9.64 - [EXTRA DIFÍCIL] El Cifrador Vigenère Aritmético Cripto-Comprimido ⭐⭐⭐⭐⭐

:::{exercise}
:label: ej-ref-vigenere-aritmetico
Analizá el siguiente bloque de código. Aplica el cifrado de Vigenère sobre un
arreglo de caracteres usando una clave alfabética repetida, ajustando las letras
mayúsculas y minúsculas módulo 26, pero fue condensado en 5 líneas de
expresiones confusas:

``` c
void vig(char t[],int n,char k[],int m,int dec){for(int i=0,j=0;i<n;i++){char c=t[i];if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){int base=(c>='a')?'a':'A';int kbase=(k[j%m]>='a')?'a':'A';int sh=k[j%m]-kbase;if(dec)sh=26-(sh%26);t[i]=(char)(base+((c-base+sh)%26));j++;}}}
```
<!-- c -->

**Tu tarea:**
1. Desentrañar la aritmética modular del desplazamiento tanto para cifrado (`dec
   = 0`) como para descifrado (`dec = 1`).
2. Identificar todos los code smells (ternarios anidados, falta de llaves
   Allman, nombres mudos `t, n, k, m, dec, sh`).
3. Refactorizar el algoritmo en funciones puras y desacopladas:
   - `char desplazar_caracter(char c, int desplazamiento, bool descifrar)`
   - `int obtener_desplazamiento_clave(char c_clave)`
   - `void cifrar_vigenere(char texto[], int long_texto, const char clave[], int
     long_clave)`
   - `void descifrar_vigenere(char texto[], int long_texto, const char clave[],
     int long_clave)`
4. Escribir una suite completa de pruebas unitarias con `assert()` que verifique
   que descifrar un texto cifrado recupere exactamente el mensaje original
   (propiedad de reversibilidad).

:::
<!-- {exercise} -->

---

## Notas Finales

:::{tip} Criterios de Calidad para una Buena Refactorización

- **Preservación del comportamiento:** Todo refactor debe garantizar que los
  resultados matemáticos y lógicos sean idénticos a los del código original.
- **Auto-documentación:** La combinación de nombres descriptivos en `snake_case`
  y funciones con responsabilidad única hace que el código se explique por sí
  mismo sin necesidad de comentarios redundantes.
- **Cobertura con pruebas:** Toda función refactorizada debe acompañarse de su
  respectiva función de prueba automatizada con `assert()`.

:::
<!-- {tip} Criterios de Calidad para una Buena Refactorización -->
