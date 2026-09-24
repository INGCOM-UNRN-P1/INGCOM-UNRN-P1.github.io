---
title: "Ejercicios: Alias de Tipos"
short_title: "15. Alias de Tipos"
---

# Ejercicios: Alias de Tipos

## Prerrequisitos y Entorno de Ejecución Requerido

Para compilar y verificar las soluciones de este módulo bajo el estándar C11 estricto de cátedra, se requiere:
- **Compilador C11:** GCC 9+ o Clang 11+ configurado con flags `-Wall -Wextra -Werror -pedantic -std=c11`.
- **Entorno POSIX:** Linux o WSL con utilidades estándar y verificación estática.
- **Herramientas de Verificación:** Valgrind (memcheck) y AddressSanitizer (`-fsanitize=address,undefined`) para garantizar la ausencia de lecturas fuera de rango en tablas de enumeración.
- **Conocimientos Previos:** Creación de alias mediante `typedef`, enumeraciones (`enum`), convención institucional del sufijo `_t` y sentencias `switch` exhaustivas con `default`.

## Objetivos Pedagógicos y Competencias (Taxonomía de Bloom)

- **Nivel 2 (Comprensión):** Diferenciar tipos primitivos de alias semánticos de dominio y mapeo entero de enums.
- **Nivel 3 (Aplicación):** Implementar tipos de datos legibles, traductores enum a cadena inmutable y clasificadores de estado en C11.
- **Nivel 4 (Análisis):** Evaluar el tratamiento defensivo de valores fuera de rango y la seguridad de tipos.
- **Andamiaje Progresivo:** Ejercicios andamiados con contratos formales (precondiciones/postcondiciones), tablas de vectores de prueba y suites ejecutables con `assert()`.

### Capítulos de Apunte Correspondientes
- [Alias de tipos](../../apunte/bloque_2_memoria/10_alias_tipos.md)

### Cuestiones de Estilo Aplicables
- **Nombres de tipos:** Por convención de cátedra ({ref}`0x2001h`), todo tipo definido con `typedef` debe llevar el sufijo `_t` (ej. `dia_semana_t`).
- **Validación defensiva:** Validar rangos en `switch` incluyendo siempre la cláusula `default` para manejar valores inesperados.
- **Aserciones:** Utilizar `<assert.h>` para aserciones invariantes en suites de verificación.

---

## Definición de Alias de Tipos

(ej_b2_c10_01)=
### Ejercicio 2.10.01 - Clasificación de Días de la Semana con Enums ⭐⭐☆☆☆

:::{exercise}
:label: enum_basico
:enumerator: enums-1

Definí un tipo enumerado `dia_semana_t` con alias `typedef` para representar los días de la semana
(de `LUNES` a `DOMINGO`), más un centinela `DIA_INVALIDO`.
Implementá una función `tipo_dia_t clasificar_dia(dia_semana_t dia)` que determine si un día
es laboral (`DIA_LABORAL`), fin de semana (`FIN_DE_SEMANA`) o inválido (`ERROR_DIA_INVALIDO`).
Implementá además una función `const char *dia_a_string(dia_semana_t dia)` que devuelva la representación
textual inmutable del día.

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** `typedef`, `enum`, `switch-case`, calificador `const`.  
**Techo conceptual:** Prohibido el uso de memoria dinámica (`malloc`) o punteros a cadenas mutables.

#### Contrato de la Función
- **Firma:** `tipo_dia_t clasificar_dia(dia_semana_t dia);`
- **Firma:** `const char *dia_a_string(dia_semana_t dia);`
- **Precondiciones:** Ninguna (la función maneja explícitamente valores fuera de rango).
- **Postcondiciones:** Retorna `DIA_LABORAL` para lunes a viernes, `FIN_DE_SEMANA` para sábado y domingo, y `ERROR_DIA_INVALIDO` para cualquier otro entero.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`dia`) | Retorno Clasificación | Retorno String | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `LUNES` | `DIA_LABORAL` | `"Lunes"` | Inicio de semana hábil |
| **Normal** | `VIERNES` | `DIA_LABORAL` | `"Viernes"` | Fin de semana hábil |
| **Normal** | `SABADO` | `FIN_DE_SEMANA` | `"Sábado"` | Primer día de descanso |
| **Normal** | `DOMINGO` | `FIN_DE_SEMANA` | `"Domingo"` | Segundo día de descanso |
| **Borde (Centinela)** | `DIA_INVALIDO` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Límite superior del enum |
| **Error (Negativo)** | `-1` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Entero fuera de rango inferior |
| **Error (Desborde)** | `99` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Entero fuera de rango superior |

:::
<!-- {exercise} -->

::::{solution} enum_basico
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    LUNES = 0,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO,
    DIA_INVALIDO
} dia_semana_t;

typedef enum
{
    DIA_LABORAL,
    FIN_DE_SEMANA,
    ERROR_DIA_INVALIDO
} tipo_dia_t;

tipo_dia_t clasificar_dia(dia_semana_t dia)
{
    switch (dia)
    {
    case LUNES:
    case MARTES:
    case MIERCOLES:
    case JUEVES:
    case VIERNES:
        return DIA_LABORAL;
    case SABADO:
    case DOMINGO:
        return FIN_DE_SEMANA;
    default:
        return ERROR_DIA_INVALIDO;
    }
}

const char *dia_a_string(dia_semana_t dia)
{
    static const char *const nombres[] = {
        "Lunes", "Martes", "Miércoles", "Jueves",
        "Viernes", "Sábado", "Domingo"
    };

    if (dia < LUNES || dia >= DIA_INVALIDO)
    {
        return "Día inválido";
    }
    return nombres[dia];
}

int main(void)
{
    // Casos normales días laborales
    assert(clasificar_dia(LUNES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(LUNES), "Lunes") == 0);

    assert(clasificar_dia(MIERCOLES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(MIERCOLES), "Miércoles") == 0);

    assert(clasificar_dia(VIERNES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(VIERNES), "Viernes") == 0);

    // Casos normales fin de semana
    assert(clasificar_dia(SABADO) == FIN_DE_SEMANA);
    assert(strcmp(dia_a_string(SABADO), "Sábado") == 0);

    assert(clasificar_dia(DOMINGO) == FIN_DE_SEMANA);
    assert(strcmp(dia_a_string(DOMINGO), "Domingo") == 0);

    // Casos de error y fuera de rango
    assert(clasificar_dia(DIA_INVALIDO) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string(DIA_INVALIDO), "Día inválido") == 0);

    assert(clasificar_dia((dia_semana_t)-1) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string((dia_semana_t)-1), "Día inválido") == 0);

    assert(clasificar_dia((dia_semana_t)99) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string((dia_semana_t)99), "Día inválido") == 0);

    return 0;
}
```

::::
<!-- {solution} enum_basico -->

---

(ej_b2_c10_02)=
### Ejercicio 2.10.02 - Distancia Manhattan con Alias de Estructura ⭐⭐☆☆☆

:::{exercise}
:label: alias_punto_manhattan

Definí un alias `punto_2d_t` para un registro con coordenadas enteras `x` e `y`.
Implementá una función pura que calcule la distancia Manhattan entre dos puntos:
$d(p_1, p_2) = |p_1.x - p_2.x| + |p_1.y - p_2.y|$.

```c
typedef struct {
    int x;
    int y;
} punto_2d_t;

int distancia_manhattan(punto_2d_t p1, punto_2d_t p2);
```

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Punto $P_1$ | Punto $P_2$ | Distancia Esperada |
| :--- | :--- | :--- | :--- |
| Puntos idénticos | `(0, 0)` | `(0, 0)` | `0` |
| Primer cuadrante | `(1, 2)` | `(4, 6)` | `3 + 4 = 7` |
| Cuadrantes opuestos | `(-2, 3)` | `(3, -1)` | `5 + 4 = 9` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int x;
    int y;
} punto_2d_t;

int distancia_manhattan(punto_2d_t p1, punto_2d_t p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main(void) {
    punto_2d_t o = {0, 0};
    punto_2d_t p1 = {1, 2};
    punto_2d_t p2 = {4, 6};
    punto_2d_t p3 = {-2, 3};
    punto_2d_t p4 = {3, -1};

    assert(distancia_manhattan(o, o) == 0);
    assert(distancia_manhattan(p1, p2) == 7);
    assert(distancia_manhattan(p3, p4) == 9);

    return 0;
}
```
::::
:::

---

(ej_b2_c10_03)=
### Ejercicio 2.10.03 - Aritmética de Números Complejos con Alias de Tipos ⭐⭐⭐☆☆

:::{exercise}
:label: alias_numeros_complejos

Definí un tipo con alias `complejo_t` para representar números complejos con componentes flotantes de doble precisión (`real` e `imag`).
Implementá funciones puras para sumar y multiplicar dos números complejos:
- $(a + bi) + (c + di) = (a + c) + (b + d)i$
- $(a + bi) \times (c + di) = (ac - bd) + (ad + bc)i$

```c
typedef struct {
    double real;
    double imag;
} complejo_t;

complejo_t complejo_sumar(complejo_t c1, complejo_t c2);
complejo_t complejo_multiplicar(complejo_t c1, complejo_t c2);
```

#### Contrato de las Funciones
- **Precondiciones:** Componentes numéricas finitas.
- **Postcondiciones:** Retornan por valor una nueva estructura `complejo_t` con el resultado exacto.

#### Tabla de Vectores de Prueba

| Tipo de Caso | $C_1$ | $C_2$ | Suma Esperada | Producto Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Normal** | $3 + 2i$ | $1 + 4i$ | $4 + 6i$ | $(3 - 8) + (12 + 2)i = -5 + 14i$ | Aritmética compleja estándar |
| **Elemento Neutro**| $5 - 7i$ | $1 + 0i$ | $6 - 7i$ | $5 - 7i$ | Neutro del producto |
| **Complejo Puro**| $0 + 1i$ | $0 + 1i$ | $0 + 2i$ | $-1 + 0i$ | Propiedad $i^2 = -1$ |

:::

::::{solution} alias_numeros_complejos
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#define EPSILON 1e-9

typedef struct
{
    double real;
    double imag;
} complejo_t;

complejo_t complejo_sumar(complejo_t c1, complejo_t c2)
{
    complejo_t res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

complejo_t complejo_multiplicar(complejo_t c1, complejo_t c2)
{
    complejo_t res;
    res.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    res.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return res;
}

static bool son_iguales(complejo_t a, complejo_t b)
{
    return fabs(a.real - b.real) < EPSILON && fabs(a.imag - b.imag) < EPSILON;
}

int main(void)
{
    complejo_t c1 = {3.0, 2.0};
    complejo_t c2 = {1.0, 4.0};

    complejo_t suma = complejo_sumar(c1, c2);
    assert(son_iguales(suma, (complejo_t){4.0, 6.0}));

    complejo_t prod = complejo_multiplicar(c1, c2);
    assert(son_iguales(prod, (complejo_t){-5.0, 14.0}));

    // Neutro
    complejo_t neutro = {1.0, 0.0};
    complejo_t c3 = {5.0, -7.0};
    assert(son_iguales(complejo_multiplicar(c3, neutro), c3));

    // i * i = -1
    complejo_t i_puro = {0.0, 1.0};
    assert(son_iguales(complejo_multiplicar(i_puro, i_puro), (complejo_t){-1.0, 0.0}));

    return 0;
}
```

::::
<!-- {solution} alias_numeros_complejos -->

---

(ej_b2_c10_04)=
### Ejercicio 2.10.04 - Álgebra Vectorial 3D con Alias de Tipos ⭐⭐⭐☆☆

:::{exercise}
:label: alias_vector3d_algebra
:enumerator: alias-4

En gráficos por computadora y simulaciones de física, las operaciones geométricas sobre el espacio euclidiano $\mathbb{R}^3$ se modelan mediante tipos estructurados con alias expresivos.

Definí el alias de tipo:
```c
typedef struct {
    double x;
    double y;
    double z;
} vector3d_t;
```

Implementá las siguientes funciones de álgebra vectorial tridimensional:
1. `double vector3d_producto_punto(vector3d_t a, vector3d_t b)`: retorna el producto escalar $\mathbf{a} \cdot \mathbf{b} = a_x b_x + a_y b_y + a_z b_z$.
2. `vector3d_t vector3d_producto_cruz(vector3d_t a, vector3d_t b)`: retorna el producto vectorial ortogonal:
   $$\mathbf{a} \times \mathbf{b} = (a_y b_z - a_z b_y, a_z b_x - a_x b_z, a_x b_y - a_y b_x)$$
3. `double vector3d_norma(vector3d_t v)`: calcula la magnitud euclidiana $\|\mathbf{v}\| = \sqrt{\mathbf{v} \cdot \mathbf{v}}$.

#### Tabla de Vectores de Prueba Obligatorios

| Operación | Vector A | Vector B | Resultado Esperado | Propiedad Matemática |
| :--- | :--- | :--- | :--- | :--- |
| **Producto Punto** | `(1, 2, 3)` | `(4, -5, 6)` | $1\times 4 - 2\times 5 + 3\times 6 = 12.0$ | Escalar con términos mixtos |
| **Producto Cruz Canónico**| `(1, 0, 0)` ($\mathbf{\hat{i}}$) | `(0, 1, 0)` ($\mathbf{\hat{j}}$) | `(0, 0, 1)` ($\mathbf{\hat{k}}$) | Regla de la mano derecha |
| **Producto Cruz Paralelo**| `(2, 4, 6)` | `(1, 2, 3)` | `(0, 0, 0)` | Vectores colineales tienen producto cruz nulo |
| **Norma Euclidiana** | `(0, 3, 4)` | N/A | $5.0$ | Triángulo rectángulo pitagórico |

:::
<!-- {exercise} alias_vector3d_algebra -->

::::{solution} alias_vector3d_algebra
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define EPSILON 1e-7

typedef struct {
    double x;
    double y;
    double z;
} vector3d_t;

double vector3d_producto_punto(vector3d_t a, vector3d_t b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

vector3d_t vector3d_producto_cruz(vector3d_t a, vector3d_t b) {
    vector3d_t res;
    res.x = (a.y * b.z) - (a.z * b.y);
    res.y = (a.z * b.x) - (a.x * b.z);
    res.z = (a.x * b.y) - (a.y * b.x);
    return res;
}

double vector3d_norma(vector3d_t v) {
    return sqrt(vector3d_producto_punto(v, v));
}

static bool vec_iguales(vector3d_t a, vector3d_t b) {
    return fabs(a.x - b.x) < EPSILON &&
           fabs(a.y - b.y) < EPSILON &&
           fabs(a.z - b.z) < EPSILON;
}

int main(void) {
    vector3d_t v1 = {1.0, 2.0, 3.0};
    vector3d_t v2 = {4.0, -5.0, 6.0};

    // 1. Producto punto
    double dot = vector3d_producto_punto(v1, v2);
    assert(fabs(dot - 12.0) < EPSILON);

    // 2. Producto cruz i x j = k
    vector3d_t i_hat = {1.0, 0.0, 0.0};
    vector3d_t j_hat = {0.0, 1.0, 0.0};
    vector3d_t k_esperado = {0.0, 0.0, 1.0};
    assert(vec_iguales(vector3d_producto_cruz(i_hat, j_hat), k_esperado));

    // 3. Vectores paralelos tienen producto cruz cero
    vector3d_t colineal = {2.0, 4.0, 6.0};
    vector3d_t cero = {0.0, 0.0, 0.0};
    assert(vec_iguales(vector3d_producto_cruz(v1, colineal), cero));

    // 4. Norma
    vector3d_t v_norma = {0.0, 3.0, 4.0};
    assert(fabs(vector3d_norma(v_norma) - 5.0) < EPSILON);

    return 0;
}
```

::::
<!-- {solution} alias_vector3d_algebra -->

