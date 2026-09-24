---
title: 'Ejercicios sobre Funciones'
short_title: '6. Funciones'
subtitle: 'Problemas y soluciones sobre modularización en C'
---

# Ejercicios sobre Funciones

## Acerca de

Estos ejercicios tienen como finalidad practicar la descomposición modular de
problemas en funciones puras y reutilizables en C11, definiendo firmas con sus tipos de datos
adecuados para los parámetros y valores de retorno, respetando contratos pre y postcondición.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-funciones-descomposicion`

### Cuestiones de Estilo Aplicables
- **Resolución mediante funciones:** Según la {ref}`0x2008h`, la lógica debe ser encapsulada
  en funciones independientes.
- **Nomenclatura en funciones:** Los nombres de funciones y variables locales
  deben seguir la convención `snake_case` en minúsculas, de acuerdo con las
  reglas {ref}`0x2009h` y {ref}`0x0102h`.
- **Separación de entrada/salida:** En concordancia con la {ref}`0x2002h`, se debe evitar que las
  funciones de cálculo realicen entrada/salida (`printf`/`scanf`) a menos que ese sea su propósito
  explícito. Deben retornar valores o códigos de estado.

---

(ej_b1_c04_01)=
### Ejercicio 1.04.01 - Duplicación Aritmética Escalar ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-doble
:enumerator: funciones-1

Escribí una función pura `int doble(int n)` que reciba un número entero y retorne el
resultado de multiplicarlo por 2. Probala exhaustivamente mediante aserciones unitarias.

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** Tipos primitivos (`int`), retorno de valor, paso por valor.  
**Techo conceptual:** Prohibido el uso de punteros o variables globales.

#### Contrato de la Función
- **Firma:** `int doble(int n);`
- **Precondiciones:** `INT_MIN / 2 <= n <= INT_MAX / 2` (sin desbordamiento).
- **Postcondiciones:** Retorna exactamente $2 \times n$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `n` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `5` | `10` | Entero positivo estándar |
| **Normal** | `-7` | `-14` | Entero negativo estándar |
| **Borde (Cero)** | `0` | `0` | Elemento absorbente del producto |
| **Extremal** | `1000000` | `2000000` | Magnitud grande sin overflow |

:::
<!-- {exercise} -->

::::{solution} ej-funcion-doble
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>

int doble(int n)
{
    return 2 * n;
}

int main(void)
{
    assert(doble(5) == 10);
    assert(doble(-7) == -14);
    assert(doble(0) == 0);
    assert(doble(1000000) == 2000000);
    return 0;
}
```

::::
<!-- {solution} ej-funcion-doble -->

---

(ej_b1_c04_02)=
### Ejercicio 1.04.02 - Máximo de Dos Enteros ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-mayor
:enumerator: funciones-2

Implementá una función `int mayor(int a, int b)` que reciba dos enteros y devuelva el
mayor de ellos. En caso de igualdad, debe devolver cualquiera de los dos.

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** Condicionales `if-else`, operadores relacionales.  
**Techo conceptual:** Prohibido el uso de bibliotecas matemáticas (`<math.h>`).

#### Contrato de la Función
- **Firma:** `int mayor(int a, int b);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna $a$ si $a \ge b$; de lo contrario retorna $b$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`a`, `b`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `10, 7` | `10` | Primer argumento estrictamente mayor |
| **Normal** | `3, 15` | `15` | Segundo argumento estrictamente mayor |
| **Borde (Iguales)** | `42, 42` | `42` | Valores idénticos |
| **Normal (Negativos)**| `-20, -5` | `-5` | Comparación estricta con signos negativos |

:::
<!-- {exercise} -->

::::{solution} ej-funcion-mayor
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>

int mayor(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

int main(void)
{
    assert(mayor(10, 7) == 10);
    assert(mayor(3, 15) == 15);
    assert(mayor(42, 42) == 42);
    assert(mayor(-20, -5) == -5);
    return 0;
}
```

::::
<!-- {solution} ej-funcion-mayor -->

---

(ej_b1_c04_03)=
### Ejercicio 1.04.03 - Predicado Booleano de Paridad ⭐⭐☆☆☆

:::{exercise}
:label: ej-funcion-par-impar
:enumerator: funciones-3

Implementá una función pura `bool es_par(int n)` que determine la paridad de un número entero.
En estricto cumplimiento de la regla de estilo {ref}`0x2002h`, la función no debe imprimir en pantalla,
sino retornar un valor booleano (`true` o `false` mediante `<stdbool.h>`).

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** Operador módulo `%`, tipo `bool`, evaluación lógica.  
**Techo conceptual:** Prohibido el uso de operaciones de E/S dentro de la función.

#### Contrato de la Función
- **Firma:** `bool es_par(int n);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna `true` si $n \pmod 2 == 0$; de lo contrario retorna `false`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `n` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal (Par)** | `12` | `true` | Número par positivo |
| **Normal (Impar)** | `7` | `false` | Número impar positivo |
| **Borde (Cero)** | `0` | `true` | Cero es par ($0 = 2 \times 0$) |
| **Normal (Negativo Par)**| `-8` | `true` | Mantiene paridad con signo negativo |
| **Normal (Negativo Impar)**| `-15` | `false` | Mantiene imparidad con signo negativo |

:::
<!-- {exercise} -->

::::{solution} ej-funcion-par-impar
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool es_par(int n)
{
    return (n % 2) == 0;
}

int main(void)
{
    assert(es_par(12) == true);
    assert(es_par(7) == false);
    assert(es_par(0) == true);
    assert(es_par(-8) == true);
    assert(es_par(-15) == false);
    return 0;
}
```

::::
<!-- {solution} ej-funcion-par-impar -->

---

(ej_b1_c04_04)=
### Ejercicio 1.04.04 - Promedio Ponderado de Notas en Punto Flotante ⭐⭐☆☆☆

:::{exercise}
:label: funcion_promedio
:enumerator: funciones-4

Escribí una función `double calcular_promedio(int a, int b, int c)` que reciba tres
calificaciones enteras no negativas y calcule su media aritmética en punto flotante
utilizando conversión explícita (*casting*) para evitar la pérdida de precisión por división entera.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Tipos `double`, conversión de tipos primitivos, precedencia de operadores.  
**Techo conceptual:** Prohibido el uso de variables globales.

#### Contrato de la Función
- **Firma:** `double calcular_promedio(int a, int b, int c);`
- **Precondiciones:** `a >= 0`, `b >= 0`, `c >= 0`.
- **Postcondiciones:** Retorna exactamente $\frac{a + b + c}{3.0}$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`a, b, c`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `7, 8, 10` | `8.3333...` | Promedio con parte fraccionaria periódica |
| **Normal (Entero)** | `6, 8, 10` | `8.0` | Promedio con división entera exacta |
| **Borde (Ceros)** | `0, 0, 0` | `0.0` | Calificación mínima |
| **Borde (Máximos)** | `10, 10, 10` | `10.0` | Calificación máxima idéntica |

:::
<!-- {exercise} -->

::::{solution} funcion_promedio
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>

double calcular_promedio(int a, int b, int c)
{
    return (double)(a + b + c) / 3.0;
}

int main(void)
{
    assert(fabs(calcular_promedio(7, 8, 10) - (25.0 / 3.0)) < 0.0001);
    assert(fabs(calcular_promedio(6, 8, 10) - 8.0) < 0.0001);
    assert(fabs(calcular_promedio(0, 0, 0) - 0.0) < 0.0001);
    assert(fabs(calcular_promedio(10, 10, 10) - 10.0) < 0.0001);
    return 0;
}
```

::::
<!-- {solution} funcion_promedio -->

---

(ej_b1_c04_05)=
### Ejercicio 1.04.05 - Cálculo de Superficie de Rectángulo ⭐⭐☆☆☆

:::{exercise}
:label: funcion_area
:enumerator: funciones-5

Implementá una función `long calcular_area_rectangulo(int base, int altura)` que calcule
el área de una figura rectangular. La función debe validar que las dimensiones sean positivas
y retornar `-1` si alguna de las medidas es inválida ($\le 0$).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Control de flujo defensivo, tipos de retorno ampliados (`long`).  
**Techo conceptual:** Prohibido el uso de macros para el cálculo.

#### Contrato de la Función
- **Firma:** `long calcular_area_rectangulo(int base, int altura);`
- **Precondiciones:** Ninguna (valida internamente).
- **Postcondiciones:** Retorna `base * altura` si `base > 0 && altura > 0`; de lo contrario retorna `-1`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`base, altura`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `5, 4` | `20` | Superficie estándar |
| **Borde (Cuadrado)** | `6, 6` | `36` | Caso equilátero |
| **Error (Cero)** | `0, 10` | `-1` | Dimensión nula inválida |
| **Error (Negativo)** | `-5, 4` | `-1` | Dimensión negativa inválida |

:::
<!-- {exercise} -->

::::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>

long calcular_area_rectangulo(int base, int altura)
{
    if (base <= 0 || altura <= 0)
    {
        return -1;
    }
    return (long)base * (long)altura;
}

int main(void)
{
    assert(calcular_area_rectangulo(5, 4) == 20);
    assert(calcular_area_rectangulo(6, 6) == 36);
    assert(calcular_area_rectangulo(0, 10) == -1);
    assert(calcular_area_rectangulo(-5, 4) == -1);
    assert(calcular_area_rectangulo(5, -4) == -1);
    return 0;
}
```

::::
<!-- {solution} funcion_area -->

---

(ej_b1_c04_06)=
### Ejercicio 1.04.06 - División Real Segura con Código de Estado ⭐⭐☆☆☆

:::{exercise}
:label: funcion_division_segura
:enumerator: funciones-6

Implementá una función `bool dividir_seguro(double dividendo, double divisor, double *resultado)`
que efectúe la división en punto flotante sin incurrir en división por cero.
La función debe verificar que el divisor no sea nulo ($\pm 0.0$), asignar el cociente
en `*resultado` y retornar `true`. Si el divisor es cero o `resultado` es nulo, debe retornar `false`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Parámetros de salida por puntero, código de retorno booleano, comparación con `0.0`.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `bool dividir_seguro(double dividendo, double divisor, double *resultado);`
- **Precondiciones:** `resultado != NULL`.
- **Postcondiciones:** Retorna `true` y almacena el cociente en `*resultado` si `divisor != 0.0`. Retorna `false` ante error.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`dividendo, divisor`) | Retorno Booleano | Valor Almacenado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `10.0, 2.0` | `true` | `5.0` | División exacta de positivos |
| **Normal (Fraccionario)**| `7.0, 2.0` | `true` | `3.5` | Cociente con parte decimal |
| **Error (División Cero)**| `5.0, 0.0` | `false` | Inalterado | Prevención de indeterminación `inf`/`nan` |
| **Error (Puntero Nulo)** | `5.0, 2.0, NULL` | `false` | Ninguno | Manejo defensivo de precondición |

:::
<!-- {exercise} -->

::::{solution} funcion_division_segura
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

bool dividir_seguro(double dividendo, double divisor, double *resultado)
{
    if (resultado == NULL || fabs(divisor) < 1e-9)
    {
        return false;
    }

    *resultado = dividendo / divisor;
    return true;
}

int main(void)
{
    double res = 0.0;

    assert(dividir_seguro(10.0, 2.0, &res) == true);
    assert(fabs(res - 5.0) < 0.0001);

    assert(dividir_seguro(7.0, 2.0, &res) == true);
    assert(fabs(res - 3.5) < 0.0001);

    assert(dividir_seguro(5.0, 0.0, &res) == false);
    assert(dividir_seguro(5.0, 2.0, NULL) == false);

    return 0;
}
```

::::
<!-- {solution} funcion_division_segura -->

---

(ej_b1_c04_07)=
### Ejercicio 1.04.07 - Predicado de Primalidad Optimizado ⭐⭐⭐☆☆

:::{exercise}
:label: funcion_es_primo
:enumerator: funciones-7

Implementá una función `bool es_primo(int n)` que determine si un número entero positivo es primo.
El algoritmo debe optimizarse verificando divisibilidad únicamente hasta $\lfloor \sqrt{n} \rfloor$,
descartando en primer lugar los números menores o iguales a 1 y los números pares mayores a 2.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Bucles `for`, optimización con cota cuadrática (`i * i <= n`), evaluación lógica.  
**Techo conceptual:** Prohibido el cómputo de listas o arreglos auxiliares.

#### Contrato de la Función
- **Firma:** `bool es_primo(int n);`
- **Precondiciones:** Ninguna.
- **Postcondiciones:** Retorna `true` si $n$ posee exactamente dos divisores positivos distintos ($1$ y $n$).

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `n` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal (Primo)** | `13` | `true` | Primo impar estándar |
| **Normal (Compuesto)** | `15` | `false` | Divisible por $3$ y $5$ |
| **Borde (Primo Par)** | `2` | `true` | Único número primo par |
| **Borde (Uno)** | `1` | `false` | La unidad no es prima |
| **Borde (Negativo)** | `-7` | `false` | Enteros negativos excluidos |

:::
<!-- {exercise} -->

::::{solution} funcion_es_primo
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool es_primo(int n)
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

    for (int i = 3; (long)i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    assert(es_primo(13) == true);
    assert(es_primo(15) == false);
    assert(es_primo(2) == true);
    assert(es_primo(1) == false);
    assert(es_primo(0) == false);
    assert(es_primo(-7) == false);
    assert(es_primo(29) == true);
    assert(es_primo(49) == false);
    return 0;
}
```

::::
<!-- {solution} funcion_es_primo -->

---

(ej_b1_c04_08)=
### Ejercicio 1.04.08 - Máximo Común Divisor Euclidiano ⭐⭐⭐☆☆

:::{exercise}
:label: funcion_mcd_euclides
:enumerator: funciones-8

Implementá una función `int calcular_mcd(int a, int b)` que calcule el Máximo Común Divisor
entre dos números enteros utilizando el algoritmo clásico de Euclides en forma iterativa:
$MCD(a, b) = MCD(b, a \pmod b)$ hasta que $b = 0$.
La función debe operar correctamente aun cuando se reciban argumentos negativos (tomando su valor absoluto).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Bucle `while`, operador `%`, función `abs()` de `<stdlib.h>`.  
**Techo conceptual:** Prohibido el uso de variables globales.

#### Contrato de la Función
- **Firma:** `int calcular_mcd(int a, int b);`
- **Precondiciones:** Al menos uno de los dos enteros debe ser distinto de cero.
- **Postcondiciones:** Retorna el máximo entero positivo $d$ tal que $d \mid a$ y $d \mid b$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`a, b`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `48, 18` | `6` | Divisor común euclidiano estándar |
| **Normal (Coprimos)** | `17, 13` | `1` | Primos entre sí |
| **Borde (Cero)** | `0, 25` | `25` | $MCD(0, b) = |b|$ |
| **Normal (Negativos)**| `-24, 36` | `12` | Invarianza ante signo de entrada |

:::
<!-- {exercise} -->

::::{solution} funcion_mcd_euclides
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdlib.h>

int calcular_mcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main(void)
{
    assert(calcular_mcd(48, 18) == 6);
    assert(calcular_mcd(17, 13) == 1);
    assert(calcular_mcd(0, 25) == 25);
    assert(calcular_mcd(-24, 36) == 12);
    assert(calcular_mcd(100, 100) == 100);
    return 0;
}
```

::::
<!-- {solution} funcion_mcd_euclides -->

---

(ej_b1_c04_09)=
### Ejercicio 1.04.09 - Resolución de Ecuación Cuadrática y Discriminante ⭐⭐⭐☆☆

:::{exercise}
:label: funcion_resolver_cuadratica
:enumerator: funciones-9

Implementá una función pura que determine las raíces reales de una ecuación cuadrática de la forma $ax^2 + bx + c = 0$ comunicando los resultados mediante punteros y clasificando el tipo de solución:

```c
typedef enum {
    CUADRATICA_DEGENERADA,
    CUADRATICA_SIN_REALES,
    CUADRATICA_RAIZ_DOBLE,
    CUADRATICA_DOS_REALES
} tipo_solucion_t;

tipo_solucion_t resolver_cuadratica(double a, double b, double c, double *x1, double *x2);
```

**Reglas de cálculo y estabilidad numérica:**
1. Si $|a| < 10^{-9}$, la ecuación no es estrictamente cuadrática; la función debe retornar `CUADRATICA_DEGENERADA` sin calcular raíces de segundo orden.
2. Se calcula el discriminante $\Delta = b^2 - 4ac$.
   - Si $\Delta < -10^{-9}$: no existen soluciones en el cuerpo real $\mathbb{R}$. Retorna `CUADRATICA_SIN_REALES`.
   - Si $|\Delta| \le 10^{-9}$: existe una raíz doble real en $x = -b / (2a)$. Asigna dicho valor a `*x1` y `*x2` y retorna `CUADRATICA_RAIZ_DOBLE`.
   - Si $\Delta > 10^{-9}$: existen dos raíces reales distintas calculadas mediante la fórmula resolvente $x = \frac{-b \pm \sqrt{\Delta}}{2a}$. Asigna a `*x1` la menor y a `*x2` la mayor, retornando `CUADRATICA_DOS_REALES`.
3. Si los punteros de salida `x1` o `x2` son nulos, la función debe limitarse a clasificar el tipo de solución sin provocar accesos indebidos de memoria.

#### Tabla de Vectores de Prueba Obligatorios

| Coeficientes $(a, b, c)$ | Clasificación Esperada | Raíces $(x_1, x_2)$ | Justificación Matemática |
| :--- | :--- | :--- | :--- |
| `0.0, 3.0, -6.0` | `CUADRATICA_DEGENERADA` | Sin modificar | Coeficiente principal nulo (lineal) |
| `1.0, 0.0, 1.0` | `CUADRATICA_SIN_REALES` | Sin modificar | $\Delta = -4 < 0$ (raíces complejas) |
| `1.0, -4.0, 4.0` | `CUADRATICA_RAIZ_DOBLE` | `x1 = 2.0, x2 = 2.0` | $\Delta = 0$ (trinomio cuadrado perfecto) |
| `1.0, -5.0, 6.0` | `CUADRATICA_DOS_REALES` | `x1 = 2.0, x2 = 3.0` | $\Delta = 1 > 0 \implies (x-2)(x-3) = 0$ |

:::

::::{solution} funcion_resolver_cuadratica
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stddef.h>

typedef enum {
    CUADRATICA_DEGENERADA,
    CUADRATICA_SIN_REALES,
    CUADRATICA_RAIZ_DOBLE,
    CUADRATICA_DOS_REALES
} tipo_solucion_t;

tipo_solucion_t resolver_cuadratica(double a, double b, double c, double *x1, double *x2)
{
    const double EPSILON = 1e-9;

    if (fabs(a) < EPSILON)
    {
        return CUADRATICA_DEGENERADA;
    }

    double discriminante = (b * b) - (4.0 * a * c);

    if (discriminante < -EPSILON)
    {
        return CUADRATICA_SIN_REALES;
    }

    if (fabs(discriminante) <= EPSILON)
    {
        double raiz = -b / (2.0 * a);
        if (x1 != NULL)
        {
            *x1 = raiz;
        }
        if (x2 != NULL)
        {
            *x2 = raiz;
        }
        return CUADRATICA_RAIZ_DOBLE;
    }

    double raiz_delta = sqrt(discriminante);
    double r1 = (-b - raiz_delta) / (2.0 * a);
    double r2 = (-b + raiz_delta) / (2.0 * a);

    if (r1 > r2)
    {
        double temp = r1;
        r1 = r2;
        r2 = temp;
    }

    if (x1 != NULL)
    {
        *x1 = r1;
    }
    if (x2 != NULL)
    {
        *x2 = r2;
    }

    return CUADRATICA_DOS_REALES;
}

int main(void)
{
    double r1 = 0.0;
    double r2 = 0.0;

    /* Caso degenerado (a = 0) */
    assert(resolver_cuadratica(0.0, 3.0, -6.0, &r1, &r2) == CUADRATICA_DEGENERADA);

    /* Sin raíces reales (x^2 + 1 = 0) */
    assert(resolver_cuadratica(1.0, 0.0, 1.0, &r1, &r2) == CUADRATICA_SIN_REALES);

    /* Raíz doble ((x - 2)^2 = x^2 - 4x + 4 = 0) */
    assert(resolver_cuadratica(1.0, -4.0, 4.0, &r1, &r2) == CUADRATICA_RAIZ_DOBLE);
    assert(fabs(r1 - 2.0) < 1e-6);
    assert(fabs(r2 - 2.0) < 1e-6);

    /* Dos raíces reales ((x - 2)(x - 3) = x^2 - 5x + 6 = 0) */
    assert(resolver_cuadratica(1.0, -5.0, 6.0, &r1, &r2) == CUADRATICA_DOS_REALES);
    assert(fabs(r1 - 2.0) < 1e-6);
    assert(fabs(r2 - 3.0) < 1e-6);

    /* Seguridad ante punteros NULL */
    assert(resolver_cuadratica(1.0, -5.0, 6.0, NULL, NULL) == CUADRATICA_DOS_REALES);

    return 0;
}
```

::::
<!-- {solution} funcion_resolver_cuadratica -->

