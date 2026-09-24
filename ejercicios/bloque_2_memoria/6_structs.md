---
title: Ejercicios de Estructuras
short_title: 5. Structs
---

# Ejercicios de Estructuras

## Acerca de

Estos ejercicios tienen como propósito ejercitar el agrupamiento de tipos
heterogéneos bajo una misma entidad de datos empleando la palabra clave `struct`
en C11, así como el paso eficiente por puntero y el acceso a miembros con el operador flecha (`->`).

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-estructuras`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Agrupamiento heterogéneo de datos en C11 mediante la palabra clave `struct` ({ref}`capitulo-estructuras`).
2. Definición de alias limpios mediante `typedef struct nombre nombre_t;`.
3. Paso por valor vs paso por referencia mediante punteros a estructuras (`const nombre_t *`).
4. Operadores de acceso: operador punto (`.`) para variables directas y operador flecha (`->`) para punteros.

### Cuestiones de Estilo Aplicables
- **Inicialización de structs:** Inicializá siempre las estructuras utilizando
  llaves en su declaración (ej. `fraccion_t f = {0, 1};`) para evitar basura en
  sus miembros (ver {ref}`0x7001h`).
- **Paso por puntero constante:** Para evitar el overhead de copiar estructuras por
  valor en la pila de llamadas, pasá punteros a estructuras constantes
  (`const tipo_t *`) cuando la función solo lea los campos.
- **Acceso a miembros:** Utilizá la sintaxis de operador flecha (`p->campo`) cuando se
  opere sobre punteros a estructuras, evitando la indirección parentizada `(*p).campo`.

---

## Modelado Matemático: Fracciones

(ej_b2_c07_01)=
### Ejercicio 2.07.01 - Operaciones Aritméticas con Fracciones ⭐⭐☆☆☆

:::{exercise}
:label: operaciones_fracciones
:enumerator: structs-1

Definí una estructura `fraccion_t` compuesta por dos enteros: `numerador` y `denominador`.
Implementá las funciones aritméticas básicas de suma y multiplicación:
- `fraccion_t fraccion_sumar(fraccion_t a, fraccion_t b)`
- `fraccion_t fraccion_multiplicar(fraccion_t a, fraccion_t b)`

Aplicá la fórmula clásica:
$$\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}, \quad \frac{a}{b} \times \frac{c}{d} = \frac{ac}{bd}$$

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `typedef struct`, paso de structs por valor y retorno de struct.  
**Techo conceptual:** Prohibido el uso de memoria dinámica (`malloc`).

#### Contrato de la Función
- **Firma:** `fraccion_t fraccion_sumar(fraccion_t a, fraccion_t b);`
- **Firma:** `fraccion_t fraccion_multiplicar(fraccion_t a, fraccion_t b);`
- **Precondiciones:** `a.denominador != 0` y `b.denominador != 0`.
- **Postcondiciones:** Retorna una nueva estructura `fraccion_t` con el resultado algebraico exacto.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `a` | Entrada `b` | Suma Esperada | Multiplicación Esperada | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | $1/2$ | $1/3$ | $5/6$ | $1/6$ | Suma y producto con denominadores coprimos |
| **Normal** | $2/5$ | $3/5$ | $25/25$ ($1/1$) | $6/25$ | Mismo denominador |
| **Borde (Cero)**| $0/1$ | $3/4$ | $3/4$ | $0/4$ | Fracción nula como elemento neutro/absorbente |
| **Normal (Negativos)**| $-1/3$ | $2/3$ | $3/9$ | $-2/9$ | Operaciones con numeradores negativos |

:::
<!-- {exercise} -->

::::{solution} operaciones_fracciones
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

typedef struct
{
    int numerador;
    int denominador;
} fraccion_t;

fraccion_t fraccion_sumar(fraccion_t a, fraccion_t b)
{
    assert(a.denominador != 0);
    assert(b.denominador != 0);

    fraccion_t res;
    res.numerador = (a.numerador * b.denominador) + (b.numerador * a.denominador);
    res.denominador = a.denominador * b.denominador;
    return res;
}

fraccion_t fraccion_multiplicar(fraccion_t a, fraccion_t b)
{
    assert(a.denominador != 0);
    assert(b.denominador != 0);

    fraccion_t res;
    res.numerador = a.numerador * b.numerador;
    res.denominador = a.denominador * b.denominador;
    return res;
}

int main(void)
{
    fraccion_t f1 = {1, 2};
    fraccion_t f2 = {1, 3};

    // Caso normal
    fraccion_t suma = fraccion_sumar(f1, f2);
    assert(suma.numerador == 5 && suma.denominador == 6);

    fraccion_t prod = fraccion_multiplicar(f1, f2);
    assert(prod.numerador == 1 && prod.denominador == 6);

    // Caso numerador cero
    fraccion_t f_cero = {0, 1};
    fraccion_t f3 = {3, 4};
    fraccion_t suma_cero = fraccion_sumar(f_cero, f3);
    assert(suma_cero.numerador == 3 && suma_cero.denominador == 4);

    fraccion_t prod_cero = fraccion_multiplicar(f_cero, f3);
    assert(prod_cero.numerador == 0 && prod_cero.denominador == 4);

    return 0;
}
```

::::
<!-- {solution} operaciones_fracciones -->

---

(ej_b2_c07_02)=
### Ejercicio 2.07.02 - Simplificación de Fracción mediante MCD ⭐⭐☆☆☆

:::{exercise}
:label: simplificar_fraccion
:enumerator: structs-2

Implementá una función `fraccion_t fraccion_simplificar(fraccion_t f)` que reduzca
la fracción a su mínima expresión irreducible dividiendo ambos términos por su
Máximo Común Divisor (MCD, calculado mediante el algoritmo euclidiano).
Si el denominador es negativo, transferí el signo al numerador para mantener la
convención estándar ($denominador > 0$).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Algoritmo euclidiano de MCD, lógica de signos, `struct` de entrada/salida.  
**Techo conceptual:** Prohibido el uso de variables globales.

#### Contrato de la Función
- **Firma:** `fraccion_t fraccion_simplificar(fraccion_t f);`
- **Precondiciones:** `f.denominador != 0`.
- **Postcondiciones:** Retorna `r` tal que `MCD(|r.numerador|, r.denominador) == 1` y `r.denominador > 0`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `f` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | $4/8$ | $1/2$ | Simplificación común divisible |
| **Normal (Coprimos)**| $7/11$ | $7/11$ | Fracción ya irreducible |
| **Borde (Cero)** | $0/5$ | $0/1$ | Fracción cero reducible a denominador 1 |
| **Normal (Signo Denominador)**| $3/-6$ | $-1/2$ | Normalización de signo al numerador |
| **Normal (Doble Negativo)**| $-4/-8$ | $1/2$ | Cancelación de signos negativos |

:::
<!-- {exercise} -->

::::{solution} simplificar_fraccion
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdlib.h>

typedef struct
{
    int numerador;
    int denominador;
} fraccion_t;

static int calcular_mcd(int a, int b)
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

fraccion_t fraccion_simplificar(fraccion_t f)
{
    assert(f.denominador != 0);

    if (f.numerador == 0)
    {
        fraccion_t cero = {0, 1};
        return cero;
    }

    int mcd = calcular_mcd(f.numerador, f.denominador);
    fraccion_t res;
    res.numerador = f.numerador / mcd;
    res.denominador = f.denominador / mcd;

    if (res.denominador < 0)
    {
        res.numerador = -res.numerador;
        res.denominador = -res.denominador;
    }

    return res;
}

int main(void)
{
    // Caso simplificación normal
    fraccion_t f1 = {4, 8};
    fraccion_t s1 = fraccion_simplificar(f1);
    assert(s1.numerador == 1 && s1.denominador == 2);

    // Caso ya irreducible
    fraccion_t f2 = {7, 11};
    fraccion_t s2 = fraccion_simplificar(f2);
    assert(s2.numerador == 7 && s2.denominador == 11);

    // Caso cero
    fraccion_t f3 = {0, 5};
    fraccion_t s3 = fraccion_simplificar(f3);
    assert(s3.numerador == 0 && s3.denominador == 1);

    // Caso normalizar signo denominador
    fraccion_t f4 = {3, -6};
    fraccion_t s4 = fraccion_simplificar(f4);
    assert(s4.numerador == -1 && s4.denominador == 2);

    // Caso doble negativo
    fraccion_t f5 = {-4, -8};
    fraccion_t s5 = fraccion_simplificar(f5);
    assert(s5.numerador == 1 && s5.denominador == 2);

    return 0;
}
```

::::
<!-- {solution} simplificar_fraccion -->

---

## Retorno Múltiple Encapsulado

(ej_b2_c07_03)=
### Ejercicio 2.07.03 - Estructura de División Entera Lenta ⭐⭐⭐☆☆

:::{exercise}
:label: division_lenta_struct
:enumerator: structs-3

Definí la estructura:
```c
typedef struct
{
    int cociente;
    int resto;
} division_t;
```
Implementá la función `division_t division_lenta(int dividendo, int divisor)` que
calcule el cociente y el resto de la división euclidiana utilizando únicamente
restas sucesivas (para enteros no negativos $dividendo \ge 0, divisor > 0$).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Bucles `while`, structs como valor de retorno compuesto.  
**Techo conceptual:** Prohibido el uso directo de los operadores `/` y `%`.

#### Contrato de la Función
- **Firma:** `division_t division_lenta(int dividendo, int divisor);`
- **Precondiciones:** `dividendo >= 0`, `divisor > 0`.
- **Postcondiciones:** Retorna `res` tal que `dividendo == res.cociente * divisor + res.resto` y `0 <= res.resto < divisor`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`dividendo`, `divisor`) | Retorno Esperado (`cociente`, `resto`) | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | $14, 3$ | `cociente = 4, resto = 2` | División estándar con resto no nulo ($14 = 3 \times 4 + 2$) |
| **Normal (Exacta)**| $15, 5$ | `cociente = 3, resto = 0` | División exacta con resto cero |
| **Borde (Menor)** | $2, 5$ | `cociente = 0, resto = 2` | Dividendo estrictamente menor al divisor |
| **Borde (Cero)** | $0, 7$ | `cociente = 0, resto = 0` | Dividendo cero |
| **Borde (Iguales)**| $9, 9$ | `cociente = 1, resto = 0` | Dividendo igual a divisor |

:::
<!-- {exercise} -->

::::{solution} division_lenta_struct
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>

typedef struct
{
    int cociente;
    int resto;
} division_t;

division_t division_lenta(int dividendo, int divisor)
{
    assert(dividendo >= 0);
    assert(divisor > 0);

    division_t resultado;
    resultado.cociente = 0;
    resultado.resto = dividendo;

    while (resultado.resto >= divisor)
    {
        resultado.resto -= divisor;
        resultado.cociente++;
    }

    return resultado;
}

int main(void)
{
    // Caso con resto
    division_t d1 = division_lenta(14, 3);
    assert(d1.cociente == 4 && d1.resto == 2);

    // Caso exacta
    division_t d2 = division_lenta(15, 5);
    assert(d2.cociente == 3 && d2.resto == 0);

    // Caso dividendo menor que divisor
    division_t d3 = division_lenta(2, 5);
    assert(d3.cociente == 0 && d3.resto == 2);

    // Caso dividendo cero
    division_t d4 = division_lenta(0, 7);
    assert(d4.cociente == 0 && d4.resto == 0);

    // Caso iguales
    division_t d5 = division_lenta(9, 9);
    assert(d5.cociente == 1 && d5.resto == 0);

    return 0;
}
```

::::
<!-- {solution} division_lenta_struct -->

---

## Normalización y Acarreo de Unidades

(ej_b2_c07_04)=
### Ejercicio 2.07.04 - Normalización y Suma de Tiempos ⭐⭐☆☆☆

:::{exercise}
:label: suma_tiempos
:enumerator: structs-4

Definí la estructura:
```c
typedef struct
{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;
```
Implementá `tiempo_t sumar_tiempos(tiempo_t t1, tiempo_t t2)` que compute la duración total
acumulada normalizando los segundos y minutos en base sexagesimal ($segundos < 60, minutos < 60$).

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Aritmética modular (`/`, `%`), paso por valor de structs.  
**Techo conceptual:** Tiempos estrictamente no negativos.

#### Contrato de la Función
- **Firma:** `tiempo_t sumar_tiempos(tiempo_t t1, tiempo_t t2);`
- **Precondiciones:** $t1, t2$ contienen valores $\ge 0$.
- **Postcondiciones:** Retorna `res` con $0 \le res.segundos < 60$ y $0 \le res.minutos < 60$.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada `t1` | Entrada `t2` | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | $1\text{h } 20\text{m } 15\text{s}$ | $2\text{h } 10\text{m } 20\text{s}$ | $3\text{h } 30\text{m } 35\text{s}$ | Sin acarreo |
| **Borde (Acarreo Segundos)**| $0\text{h } 10\text{m } 45\text{s}$ | $0\text{h } 05\text{m } 30\text{s}$ | $0\text{h } 16\text{m } 15\text{s}$ | $45 + 30 = 75\text{s} \to 1\text{m } 15\text{s}$ |
| **Borde (Acarreo Minutos)** | $1\text{h } 50\text{m } 00\text{s}$ | $2\text{h } 30\text{m } 00\text{s}$ | $4\text{h } 20\text{m } 00\text{s}$ | $50 + 30 = 80\text{m} \to 1\text{h } 20\text{m}$ |
| **Borde (Acarreo Cascada)** | $0\text{h } 59\text{m } 59\text{s}$ | $0\text{h } 00\text{m } 01\text{s}$ | $1\text{h } 00\text{m } 00\text{s}$ | Desborde simultáneo de s y m |

:::
<!-- {exercise} -->

::::{solution} suma_tiempos
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>

typedef struct
{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;

tiempo_t sumar_tiempos(tiempo_t t1, tiempo_t t2)
{
    tiempo_t res;
    int total_segundos = t1.segundos + t2.segundos;
    int acarreo_minutos = total_segundos / 60;
    res.segundos = total_segundos % 60;

    int total_minutos = t1.minutos + t2.minutos + acarreo_minutos;
    int acarreo_horas = total_minutos / 60;
    res.minutos = total_minutos % 60;

    res.horas = t1.horas + t2.horas + acarreo_horas;
    return res;
}

int main(void)
{
    // Sin acarreo
    tiempo_t t1 = {1, 20, 15};
    tiempo_t t2 = {2, 10, 20};
    tiempo_t r1 = sumar_tiempos(t1, t2);
    assert(r1.horas == 3 && r1.minutos == 30 && r1.segundos == 35);

    // Acarreo segundos
    tiempo_t t3 = {0, 10, 45};
    tiempo_t t4 = {0, 5, 30};
    tiempo_t r2 = sumar_tiempos(t3, t4);
    assert(r2.horas == 0 && r2.minutos == 16 && r2.segundos == 15);

    // Acarreo minutos
    tiempo_t t5 = {1, 50, 0};
    tiempo_t t6 = {2, 30, 0};
    tiempo_t r3 = sumar_tiempos(t5, t6);
    assert(r3.horas == 4 && r3.minutos == 20 && r3.segundos == 0);

    // Acarreo en cascada
    tiempo_t t7 = {0, 59, 59};
    tiempo_t t8 = {0, 0, 1};
    tiempo_t r4 = sumar_tiempos(t7, t8);
    assert(r4.horas == 1 && r4.minutos == 0 && r4.segundos == 0);

    return 0;
}
```

::::
<!-- {solution} suma_tiempos -->

---

## Paso por Referencia y Operador Flecha (`->`)

(ej_b2_c07_05)=
### Ejercicio 2.07.05 - Traslación Espacial de Punto Cartesiano ⭐⭐☆☆☆

:::{exercise}
:label: trasladar_punto
:enumerator: structs-5

Dada la estructura:
```c
typedef struct
{
    int x;
    int y;
} punto_t;
```
Implementá un procedimiento `void trasladar(punto_t *p, int dx, int dy)` que modifique
las coordenadas del punto recibido por referencia empleando obligatoriamente el operador flecha (`->`).

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** Punteros a structs, operador `->`, paso por referencia in-place.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `void trasladar(punto_t *p, int dx, int dy);`
- **Precondiciones:** `p != NULL`.
- **Postcondiciones:** `p->x` se incrementa en `dx`, y `p->y` se incrementa en `dy`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Estado Inicial `*p` | Entrada (`dx, dy`) | Estado Posterior `*p` | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `(10, 20)` | `dx = 5, dy = -3` | `(15, 17)` | Traslación con desplazamientos mixtos |
| **Borde (Cero)** | `(5, 5)` | `dx = 0, dy = 0` | `(5, 5)` | Desplazamiento nulo (identidad) |
| **Normal (Negativos)**| `(-10, -10)` | `dx = -5, dy = -5`| `(-15, -15)` | Coordenadas y deltas negativos |

:::
<!-- {exercise} -->

::::{solution} trasladar_punto
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

typedef struct
{
    int x;
    int y;
} punto_t;

void trasladar(punto_t *p, int dx, int dy)
{
    assert(p != NULL);
    p->x += dx;
    p->y += dy;
}

int main(void)
{
    punto_t pt = {10, 20};

    // Caso normal
    trasladar(&pt, 5, -3);
    assert(pt.x == 15 && pt.y == 17);

    // Caso desplazamiento nulo
    trasladar(&pt, 0, 0);
    assert(pt.x == 15 && pt.y == 17);

    // Caso negativos
    punto_t neg = {-10, -10};
    trasladar(&neg, -5, -5);
    assert(neg.x == -15 && neg.y == -15);

    return 0;
}
```

::::
<!-- {solution} trasladar_punto -->

---

(ej_b2_c07_06)=
### Ejercicio 2.07.06 - Ordenamiento de Arreglo de Puntos por Coordenada X ⭐⭐⭐☆☆

:::{exercise}
:label: ordenar_puntos_x
:enumerator: structs-6

Implementá la función `void ordenar_puntos_por_x(punto_t *puntos, size_t n)` que ordene
un arreglo contiguo de `punto_t` en orden ascendente según su miembro `x` (algoritmo burbuja o inserción).
Si dos puntos comparten la misma abscisa `x`, el orden relativo debe desempatarse por la coordenada `y`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Arreglos de structs, acceso a miembros por índice y punteros, criterio de ordenamiento lexicográfico.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `void ordenar_puntos_por_x(punto_t *puntos, size_t n);`
- **Precondiciones:** `puntos != NULL` (si `n > 0`).
- **Postcondiciones:** Para todo $0 \le i < n - 1$: `puntos[i].x <= puntos[i+1].x`. Si son iguales, `puntos[i].y <= puntos[i+1].y`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Arreglo de Entrada ($n$) | Arreglo Ordenado Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `{(5, 2), (1, 9), (3, 4)}`, $n=3$ | `{(1, 9), (3, 4), (5, 2)}` | Ordenamiento por coordenada `x` |
| **Borde (Empate X)** | `{(2, 8), (2, 3), (2, 5)}`, $n=3$ | `{(2, 3), (2, 5), (2, 8)}` | Desempate estricto por `y` |
| **Borde (Unitario)** | `{(10, 20)}`, $n=1$ | `{(10, 20)}` | Arreglo de 1 elemento |
| **Borde (Ya Ordenado)**| `{(1, 1), (2, 2)}`, $n=2$ | `{(1, 1), (2, 2)}` | Arreglo en orden previo |

:::
<!-- {exercise} -->

::::{solution} ordenar_puntos_x
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    int x;
    int y;
} punto_t;

static bool es_mayor(punto_t a, punto_t b)
{
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    return a.y > b.y;
}

void ordenar_puntos_por_x(punto_t *puntos, size_t n)
{
    if (puntos == NULL || n < 2)
    {
        return;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            if (es_mayor(puntos[j], puntos[j + 1]))
            {
                punto_t aux = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = aux;
            }
        }
    }
}

int main(void)
{
    // Caso normal
    punto_t pts1[3] = {{5, 2}, {1, 9}, {3, 4}};
    ordenar_puntos_por_x(pts1, 3);
    assert(pts1[0].x == 1 && pts1[1].x == 3 && pts1[2].x == 5);

    // Caso empate en X
    punto_t pts2[3] = {{2, 8}, {2, 3}, {2, 5}};
    ordenar_puntos_por_x(pts2, 3);
    assert(pts2[0].y == 3 && pts2[1].y == 5 && pts2[2].y == 8);

    // Caso un elemento
    punto_t pts3[1] = {{10, 20}};
    ordenar_puntos_por_x(pts3, 1);
    assert(pts3[0].x == 10 && pts3[0].y == 20);

    return 0;
}
```

::::
<!-- {solution} ordenar_puntos_x -->

---

(ej_b2_c07_07)=
### Ejercicio 2.07.07 - Encapsulamiento de Arreglo Seguro con Longitud y Capacidad ⭐⭐⭐☆☆

:::{exercise}
:label: arreglo_seguro_struct
:enumerator: structs-7

Definí la estructura:
```c
#define CAPACIDAD_MAX 8
typedef struct
{
    int datos[CAPACIDAD_MAX];
    size_t longitud;
} arreglo_seguro_t;
```
Implementá las operaciones:
- `void arreglo_inicializar(arreglo_seguro_t *arr)`: Inicializa la estructura con `longitud = 0`.
- `bool arreglo_insertar(arreglo_seguro_t *arr, int valor)`: Agrega `valor` al final si hay capacidad disponible, retornando `true`. Si el arreglo está lleno, retorna `false` sin corromper la memoria.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Encapsulamiento de capacidad y longitud, programación defensiva, paso por puntero mutador.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `void arreglo_inicializar(arreglo_seguro_t *arr);`
- **Firma:** `bool arreglo_insertar(arreglo_seguro_t *arr, int valor);`
- **Precondiciones:** `arr != NULL`.
- **Postcondiciones:** `arreglo_insertar` incrementa `arr->longitud` en 1 y asigna `valor` si `arr->longitud < CAPACIDAD_MAX`. Retorna `false` si la estructura está saturada.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Estado Inicial (`longitud`) | Inserción (`valor`) | Retorno | Estado Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | $0$ (vacío) | $42$ | `true` | `longitud = 1, datos[0] = 42` | Inserción en estructura recién inicializada |
| **Normal** | $1$ | $99$ | `true` | `longitud = 2, datos[1] = 99` | Inserción sucesiva |
| **Borde (Límite)** | $7$ (`CAPACIDAD_MAX - 1`)| $10$ | `true` | `longitud = 8` (lleno) | Inserción del último elemento admisible |
| **Error (Saturación)**| $8$ (lleno) | $999$ | `false` | `longitud = 8` inalterada | Prevención defensiva de desbordamiento |

:::
<!-- {exercise} -->

::::{solution} arreglo_seguro_struct
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#define CAPACIDAD_MAX 8

typedef struct
{
    int datos[CAPACIDAD_MAX];
    size_t longitud;
} arreglo_seguro_t;

void arreglo_inicializar(arreglo_seguro_t *arr)
{
    assert(arr != NULL);
    arr->longitud = 0;
}

bool arreglo_insertar(arreglo_seguro_t *arr, int valor)
{
    assert(arr != NULL);

    if (arr->longitud >= CAPACIDAD_MAX)
    {
        return false;
    }

    arr->datos[arr->longitud] = valor;
    arr->longitud++;
    return true;
}

int main(void)
{
    arreglo_seguro_t mi_arr;
    arreglo_inicializar(&mi_arr);
    assert(mi_arr.longitud == 0);

    // Inserción normal
    assert(arreglo_insertar(&mi_arr, 10) == true);
    assert(arreglo_insertar(&mi_arr, 20) == true);
    assert(mi_arr.longitud == 2);
    assert(mi_arr.datos[0] == 10 && mi_arr.datos[1] == 20);

    // Llenar hasta capacidad máxima (8 elementos)
    for (int i = 2; i < CAPACIDAD_MAX; i++)
    {
        assert(arreglo_insertar(&mi_arr, i * 10) == true);
    }
    assert(mi_arr.longitud == CAPACIDAD_MAX);

    // Intento de desbordamiento (debe fallar limpiamente)
    assert(arreglo_insertar(&mi_arr, 999) == false);
    assert(mi_arr.longitud == CAPACIDAD_MAX);

    return 0;
}
```

::::
<!-- {solution} arreglo_seguro_struct -->
