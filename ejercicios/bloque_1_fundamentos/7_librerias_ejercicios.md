---
title: 'Ejercicios: Creación de Librerías de Funciones'
short_title: '7. Librerías de Funciones'
subtitle: 'Diseño, encapsulamiento e implementación de módulos reutilizables en C'
---

# Ejercicios: Creación de Librerías de Funciones

## Acerca de

La creación de librerías de funciones (módulos reutilizables) permite estructurar
programas de forma limpia, probable y mantenible. 

Para resolver los siguientes ejercicios se recomienda utilizar como base la [**Plantilla para Librerías de la Cátedra (UNRN)**](https://github.com/INGCOM-UNRN-P1/plantilla-libreria), organizando el proyecto con la siguiente estructura modular:

- **`include/`**: Archivos de cabecera (`.h`) públicos con los prototipos, guardas de inclusión (`#ifndef...`) y documentación.
- **`src/`**: Archivos de implementación (`.c`) con la lógica y funciones auxiliares ocultas mediante `static`.
- **`examples/`**: Programas de demostración con `main()` que consumen la librería.
- **`tests/`**: Suite de pruebas unitarias para validar las pre/postcondiciones.
- **`Makefile`**: Automatización para compilar (`make`), probar (`make test`), ejecutar (`make run`) y limpiar (`make clean`).

Asimismo, mediante el script `./manage.sh` (`rename`, `add-module`, `build`, `test`) podés administrar la librería y posteriormente integrarla en proyectos más grandes o TPs usando `./tp.sh add-lib <nombre_libreria> <url_git>`.

En este bloque de ejercicios vas a diseñar módulos temáticos independientes, definiendo interfaces claras y contratos robustos (precondiciones, postcondiciones y códigos de estado).

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-funciones-descomposicion`
- [Compilación](../../apunte/bloque_1_fundamentos/5_compilacion.md)

### Prerrequisitos y Entorno Requerido
Para compilar y resolver los módulos de esta guía se requiere:
1. **Entorno de compilación:** GCC 11 o superior con soporte para el estándar C11 (`-std=c11`) bajo Linux/POSIX.
2. **Dependencias del sistema:** Biblioteca matemática de C (`libm`), enlazada explícitamente mediante el flag `-lm`.
3. **Conceptos previos de arquitectura de software:**
   - Separación estricta entre cabecera pública (`.h`) e implementación privada (`.c`) ({ref}`capitulo-funciones-descomposicion`).
   - Guardas del preprocesador contra inclusión múltiple (`#ifndef LIB_H`, `#define LIB_H`, `#endif`).
   - Visibilidad interna y ocultamiento de símbolos auxiliares con el calificador `static`.
   - Comparación numérica con tolerancia épsilon (`fabs(a - b) < 1e-6`) para aserciones con punto flotante.

---

## 1. Librerías Matemáticas y Numéricas

(ej_b1_c04b_01)=
### Ejercicio 1.04b.01 - Librería de Operaciones Geométricas 2D ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c04b_01_geometria2d

Diseñá e implementá un módulo para cálculos geométricos en 2D:
- `double geo_distancia(double x1, double y1, double x2, double y2)`: distancia euclídea.
- `double geo_area_rectangulo(double ancho, double alto)`: área de un rectángulo (retorna `-1.0` si alguna dimensión es negativa).
- `double geo_perimetro_rectangulo(double ancho, double alto)`: perímetro de un rectángulo (retorna `-1.0` si alguna dimensión es negativa).

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Parámetros Entrada | Función Invocada | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| Distancia origen a (3,4) | `(0, 0, 3, 4)` | `geo_distancia` | `5.0` |
| Rectángulo 4x5 | `(4.0, 5.0)` | `geo_area_rectangulo` | `20.0` |
| Rectángulo 4x5 | `(4.0, 5.0)` | `geo_perimetro_rectangulo` | `18.0` |
| Dimensión inválida | `(-2.0, 5.0)` | `geo_area_rectangulo` | `-1.0` |

::::{solution}
```c
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-7

static int casi_igual(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double geo_distancia(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

double geo_area_rectangulo(double ancho, double alto) {
    if (ancho < 0.0 || alto < 0.0) {
        return -1.0;
    }
    return ancho * alto;
}

double geo_perimetro_rectangulo(double ancho, double alto) {
    if (ancho < 0.0 || alto < 0.0) {
        return -1.0;
    }
    return 2.0 * (ancho + alto);
}

int main(void) {
    assert(casi_igual(geo_distancia(0.0, 0.0, 3.0, 4.0), 5.0));
    assert(casi_igual(geo_distancia(1.0, 1.0, 1.0, 1.0), 0.0));

    assert(casi_igual(geo_area_rectangulo(4.0, 5.0), 20.0));
    assert(casi_igual(geo_perimetro_rectangulo(4.0, 5.0), 18.0));

    /* Casos defensivos */
    assert(casi_igual(geo_area_rectangulo(-1.0, 5.0), -1.0));
    assert(casi_igual(geo_perimetro_rectangulo(4.0, -2.0), -1.0));

    return 0;
}
```
::::
:::

---

(ej_b1_c04b_02)=
### Ejercicio 1.04b.02 - Librería de Conversión de Unidades ⭐⭐☆☆☆

:::{exercise}
:label: ej_b1_c04b_02_conversiones

Creá un módulo de conversión de unidades termodinámicas y cinemáticas:
- `double conv_celsius_a_fahrenheit(double c)`
- `double conv_fahrenheit_a_celsius(double f)`
- `double conv_kmh_a_ms(double kmh)`
- `double conv_ms_a_kmh(double ms)`

**Tabla de Vectores de Prueba:**

| Magnitud | Entrada | Función Invocada | Resultado Esperado | Tolerancia |
| :--- | :--- | :--- | :--- | :--- |
| Temperatura | `0.0 °C` | `conv_celsius_a_fahrenheit` | `32.0 °F` | `1e-6` |
| Temperatura | `212.0 °F`| `conv_fahrenheit_a_celsius` | `100.0 °C` | `1e-6` |
| Velocidad | `36.0 km/h` | `conv_kmh_a_ms` | `10.0 m/s` | `1e-6` |
| Velocidad | `10.0 m/s` | `conv_ms_a_kmh` | `36.0 km/h` | `1e-6` |

::::{solution}
```c
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-6

static int casi_igual(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double conv_celsius_a_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double conv_fahrenheit_a_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double conv_kmh_a_ms(double kmh) {
    return kmh / 3.6;
}

double conv_ms_a_kmh(double ms) {
    return ms * 3.6;
}

int main(void) {
    assert(casi_igual(conv_celsius_a_fahrenheit(0.0), 32.0));
    assert(casi_igual(conv_celsius_a_fahrenheit(100.0), 212.0));
    assert(casi_igual(conv_fahrenheit_a_celsius(32.0), 0.0));
    assert(casi_igual(conv_fahrenheit_a_celsius(212.0), 100.0));

    assert(casi_igual(conv_kmh_a_ms(36.0), 10.0));
    assert(casi_igual(conv_ms_a_kmh(10.0), 36.0));

    return 0;
}
```
::::
:::

---

(ej_b1_c04b_03)=
### Ejercicio 1.04b.03 - Librería de Estadística Básica ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b1_c04b_03_estadistica

Implementá un módulo para cálculo de estadísticas básicas sobre arreglos de punto flotante en C11:
- `double est_media(const double *datos, size_t n)`: retorna la media aritmética, o `0.0` si `n == 0` o `datos == NULL`.
- `double est_minimo(const double *datos, size_t n)`: retorna el valor mínimo del arreglo.
- `double est_maximo(const double *datos, size_t n)`: retorna el valor máximo del arreglo.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Arreglo de Datos | Función Invocada | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| Muestra estándar | `[2.0, 4.0, 6.0]` | `est_media` | `4.0` |
| Rango extremos | `[10.5, -3.2, 8.0, 15.1]` | `est_minimo` / `est_maximo` | `-3.2` / `15.1` |
| Arreglo unitario | `[42.0]` | `est_media` | `42.0` |
| Puntero nulo | `NULL, 0` | `est_media` | `0.0` |

::::{solution}
```c
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-6

static int casi_igual(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double est_media(const double *datos, size_t n) {
    if (datos == NULL || n == 0) {
        return 0.0;
    }
    double suma = 0.0;
    for (size_t i = 0; i < n; ++i) {
        suma += datos[i];
    }
    return suma / (double)n;
}

double est_minimo(const double *datos, size_t n) {
    if (datos == NULL || n == 0) {
        return 0.0;
    }
    double min = datos[0];
    for (size_t i = 1; i < n; ++i) {
        if (datos[i] < min) {
            min = datos[i];
        }
    }
    return min;
}

double est_maximo(const double *datos, size_t n) {
    if (datos == NULL || n == 0) {
        return 0.0;
    }
    double max = datos[0];
    for (size_t i = 1; i < n; ++i) {
        if (datos[i] > max) {
            max = datos[i];
        }
    }
    return max;
}

int main(void) {
    double m1[3] = {2.0, 4.0, 6.0};
    assert(casi_igual(est_media(m1, 3), 4.0));

    double m2[4] = {10.5, -3.2, 8.0, 15.1};
    assert(casi_igual(est_minimo(m2, 4), -3.2));
    assert(casi_igual(est_maximo(m2, 4), 15.1));

    double m3[1] = {42.0};
    assert(casi_igual(est_media(m3, 1), 42.0));

    assert(casi_igual(est_media(NULL, 0), 0.0));
    assert(casi_igual(est_minimo(NULL, 0), 0.0));
    assert(casi_igual(est_maximo(NULL, 0), 0.0));

    return 0;
}
```
::::
:::

(ej_b1_c04b_04)=
### Ejercicio 1.04b.04 - Librería de Números Primos y Factorización ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b1_c04b_04_primos

Implementá una biblioteca para la verificación y generación de números primos con tipado estricto:
- `bool primo_es_primo(unsigned long n)`: retorna `true` si $n$ es primo ($n \ge 2$), `false` en caso contrario.
- `unsigned long primo_siguiente(unsigned long n)`: retorna el menor número primo estrictamente mayor que $n$.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Parámetro `n` | `primo_es_primo` | `primo_siguiente` |
| :--- | :--- | :--- | :--- |
| Primer primo | `2` | `true` | `3` |
| Número compuesto | `4` | `false` | `5` |
| Primo impar | `13` | `true` | `17` |
| Casos límite | `0`, `1` | `false` | `2` |

::::{solution}
```c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool primo_es_primo(unsigned long n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (unsigned long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

unsigned long primo_siguiente(unsigned long n) {
    if (n < 2) {
        return 2;
    }
    unsigned long candidato = n + 1;
    while (!primo_es_primo(candidato)) {
        candidato++;
    }
    return candidato;
}

int main(void) {
    assert(primo_es_primo(0) == false);
    assert(primo_es_primo(1) == false);
    assert(primo_es_primo(2) == true);
    assert(primo_es_primo(3) == true);
    assert(primo_es_primo(4) == false);
    assert(primo_es_primo(13) == true);
    assert(primo_es_primo(25) == false);

    assert(primo_siguiente(0) == 2);
    assert(primo_siguiente(1) == 2);
    assert(primo_siguiente(2) == 3);
    assert(primo_siguiente(4) == 5);
    assert(primo_siguiente(13) == 17);

    return 0;
}
```
::::
:::

---

(ej_b1_c04b_05)=
### Ejercicio 1.04b.05 - Librería de Trigonometría y Resolución de Triángulos ⭐⭐⭐☆☆

:::{exercise}
:label: ej_b1_c04b_05_trigonometria
:enumerator: librerias-5

Diseñá un módulo de cálculos geométricos y trigonométricos en C11 utilizando `<math.h>`:
```c
double trigo_hipotenusa(double cateto1, double cateto2);
double trigo_angulo_vector(double x, double y);
bool trigo_resolver_triangulo_sss(double a, double b, double c,
                                  double *alpha, double *beta, double *gamma);
```
- `trigo_hipotenusa`: Calcula $\sqrt{c_1^2 + c_2^2}$ utilizando `hypot` o la fórmula de Pitágoras.
- `trigo_angulo_vector`: Calcula el ángulo polar en radianes en el rango $[-\pi, \pi]$ mediante `atan2(y, x)`.
- `trigo_resolver_triangulo_sss`: Determina los tres ángulos interiores (en radianes) a partir de las longitudes de los lados $a, b, c$ usando el teorema del coseno:
  $$\cos(\alpha) = \frac{b^2 + c^2 - a^2}{2bc}$$
  Retorna `false` si los lados no cumplen la desigualdad triangular estricta ($a+b>c$, $a+c>b$, $b+c>a$) o si alguno de los punteros de salida es `NULL`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** Funciones de `<math.h>` (`hypot`, `atan2`, `acos`), validación de desigualdades geométricas, paso por referencia.  
**Techo conceptual:** Prohibido el uso de valores no numéricos (`NaN`) o divisiones por cero sin validación previa.

#### Contrato de las Funciones
- **Precondiciones:** Lados y catetos estrictamente positivos. Punteros de salida no nulos para `trigo_resolver_triangulo_sss`.
- **Postcondiciones:** Retorna `true` y escribe los ángulos cuya suma es exactamente $\pi$ radianes.

#### Tabla de Vectores de Prueba

| Triángulo ($a, b, c$) | Retorno | Ángulos ($\alpha, \beta, \gamma$) | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| Equilátero ($2, 2, 2$) | `true` | $\pi/3, \pi/3, \pi/3$ | Tres ángulos iguales a $60^\circ$ |
| Rectángulo ($3, 4, 5$) | `true` | $\gamma = \pi/2$ | Hipotenusa opuesta al ángulo recto |
| Inválido ($1, 2, 10$) | `false` | Sin escrituras | Viola desigualdad triangular ($1 + 2 < 10$) |
| Puntero nulo | `false` | Sin escrituras | Rechazo defensivo |

:::

::::{solution} ej_b1_c04b_05_trigonometria
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#define EPSILON 1e-6

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static bool casi_iguales(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

double trigo_hipotenusa(double cateto1, double cateto2)
{
    return hypot(cateto1, cateto2);
}

double trigo_angulo_vector(double x, double y)
{
    return atan2(y, x);
}

bool trigo_resolver_triangulo_sss(double a, double b, double c,
                                  double *alpha, double *beta, double *gamma)
{
    if (alpha == NULL || beta == NULL || gamma == NULL)
    {
        return false;
    }

    if (a <= 0.0 || b <= 0.0 || c <= 0.0)
    {
        return false;
    }

    // Desigualdad triangular estricta
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }

    double cos_a = (b * b + c * c - a * a) / (2.0 * b * c);
    double cos_b = (a * a + c * c - b * b) / (2.0 * a * c);
    double cos_c = (a * a + b * b - c * c) / (2.0 * a * b);

    *alpha = acos(cos_a);
    *beta = acos(cos_b);
    *gamma = acos(cos_c);

    return true;
}

int main(void)
{
    // Hipotenusa
    assert(casi_iguales(trigo_hipotenusa(3.0, 4.0), 5.0));

    // Ángulo polar vector (1, 1) = pi/4
    assert(casi_iguales(trigo_angulo_vector(1.0, 1.0), M_PI / 4.0));

    // Triángulo equilátero
    double a = 0.0, b = 0.0, c = 0.0;
    assert(trigo_resolver_triangulo_sss(2.0, 2.0, 2.0, &a, &b, &c) == true);
    assert(casi_iguales(a, M_PI / 3.0));
    assert(casi_iguales(b, M_PI / 3.0));
    assert(casi_iguales(c, M_PI / 3.0));
    assert(casi_iguales(a + b + c, M_PI));

    // Triángulo rectángulo (3, 4, 5) -> gamma opuesto al lado 5 es pi/2
    assert(trigo_resolver_triangulo_sss(3.0, 4.0, 5.0, &a, &b, &c) == true);
    assert(casi_iguales(c, M_PI / 2.0));

    // Triángulo inválido
    assert(trigo_resolver_triangulo_sss(1.0, 2.0, 10.0, &a, &b, &c) == false);

    // Punteros nulos
    assert(trigo_resolver_triangulo_sss(3.0, 4.0, 5.0, NULL, &b, &c) == false);

    return 0;
}
```

::::
<!-- {solution} ej_b1_c04b_05_trigonometria -->

---

## 2. Librerías de Manipulación de Texto y Cadenas

(ej_b1_c04b_06)=
### Ejercicio 1.04b.06 - Biblioteca de Strings seguros ⭐⭐⭐⭐⭐

Reimplementá funciones estándar de `<string.h>` en la librería `seguras.h` y `seguras.c`:
- `int mi_strlen(const char *str, size_t len_str)`
- `void mi_strcpy(char *dest, size_t len_dest, const char *src, size_t len_src)`
- `int mi_strcmp(const char *s1, size_t len_s1, const char *s2, size_t len_s2)`
- `void mi_strcat(char *dest, size_t len_dest, const char *src, size_t len_src)`
- `char *mi_strchr(const char *str, size_t len_str, char c)`

**Orientación:**
- `strlen`: contá hasta `'\0'` o hasta alcanzar `len_str`
- `strcpy`: copiá carácter por carácter respetando los límites de tamaño
- `strcmp`: retorna la diferencia numérica del primer carácter distinto dentro de los límites
- `strcat`: copiá `src` al final de `dest` sin sobrepasar `len_dest`
- `strchr`: retorna puntero a la primera aparición de `c` dentro del límite indicado
- Verificá límites de destino para evitar desbordamientos de búfer.

---

(ej_b1_c04b_07)=
### Ejercicio 1.04b.07 - Librería de Transformación de Cadenas Seguras ⭐⭐⭐☆☆

Diseñá `str_transform.h` y `str_transform.c`:
- `void str_a_mayusculas(char *str, size_t len_str)`
- `void str_a_minusculas(char *str, size_t len_str)`
- `void str_capitalizar(char *str, size_t len_str)` (primera letra de cada palabra en mayúscula)
- `void str_invertir(char *str, size_t len_str)`
- `void str_recortar_espacios(char *str, size_t len_str)` (elimina espacios al inicio y al final)

:::{hint} Lógica y Consideraciones
- Usá funciones de `<ctype.h>` como `toupper` y `tolower`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_08)=
### Ejercicio 1.04b.08 - Librería de Búsqueda y Conteo en Texto ⭐⭐⭐☆☆

Implementá la librería `text_search.h` y `text_search.c`:
- `size_t text_contar_palabras(const char *texto, size_t len_texto)`
- `size_t text_contar_caracter(const char *texto, size_t len_texto, char c)`
- `size_t text_contar_vocales(const char *texto, size_t len_texto)`
- `bool text_es_palindromo(const char *texto, size_t len_texto)`

:::{hint} Lógica y Consideraciones
- Para comprobar palíndromos podés ignorar diferencias entre mayúsculas y minúsculas y caracteres no alfabéticos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_09)=
### Ejercicio 1.04b.09 - Librería de Formateo y Padding de Texto ⭐⭐⭐☆☆

Diseñá `str_format.h` y `str_format.c`:
- `bool str_pad_left(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`
- `bool str_pad_right(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`
- `bool str_centrar(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`

:::{hint} Lógica y Consideraciones
- Garantizá siempre la terminación de la cadena resultante con `'\0'`. Retorná `false` si `dest_size` no alcanza.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_10)=
### Ejercicio 1.04b.10 - Librería de Sanitización e Inspección de Entradas ⭐⭐⭐☆☆

Creá `sanitizer.h` y `sanitizer.c`:
- `bool san_es_entero_valido(const char *str, size_t len_str)`
- `bool san_es_decimal_valido(const char *str, size_t len_str)`
- `bool san_es_email_basico(const char *str, size_t len_str)` (presencia de `@` y al menos un `.`)
- `void san_reemplazar_caracter(char *str, size_t len_str, char viejo, char nuevo)`

:::{hint} Lógica y Consideraciones
- Utilizá esta librería para validar la entrada ingresada por el usuario antes de convertirla a tipos numéricos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 3. Librerías de Manejo de Arreglos y Matrices

(ej_b1_c04b_11)=
### Ejercicio 1.04b.11 - Librería de Vectores de Enteros ⭐⭐⭐☆☆

Diseñá la librería `vec_int.h` y `vec_int.c` para operar sobre arreglos estáticos de enteros:
- `void vec_int_imprimir(const int *v, size_t n)`
- `int vec_int_suma(const int *v, size_t n)`
- `double vec_int_promedio(const int *v, size_t n)`
- `ssize_t vec_int_buscar_primero(const int *v, size_t n, int elem)`
- `size_t vec_int_contar_ocurrencias(const int *v, size_t n, int elem)`

:::{hint} Lógica y Consideraciones
- Usá `ssize_t` para devolver `-1` cuando el elemento buscado no se encuentre.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_12)=
### Ejercicio 1.04b.12 - Librería de Ordenamiento y Búsqueda ⭐⭐⭐⭐☆

Creá `sort_search.h` y `sort_search.c`:
- `void sort_burbuja(int *v, size_t n)`
- `void sort_seleccion(int *v, size_t n)`
- `void sort_insercion(int *v, size_t n)`
- `ssize_t busqueda_binaria(const int *v, size_t n, int elem)`

:::{hint} Lógica y Consideraciones
- Recordá que `busqueda_binaria` requiere que el arreglo esté previamente ordenado.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_13)=
### Ejercicio 1.04b.13 - Librería de Operaciones sobre Matrices 2D ⭐⭐⭐⭐☆

Diseñá `matriz2d.h` y `matriz2d.c` para matrices con dimensiones fijas o pasadas linealmente:
- `void mat_sumar(size_t filas, size_t cols, const double A[filas][cols], const double B[filas][cols], double C[filas][cols])`
- `void mat_multiplicar_escalar(size_t filas, size_t cols, double M[filas][cols], double escalar)`
- `void mat_transponer(size_t filas, size_t cols, const double A[filas][cols], double T[cols][filas])`
- `double mat_traza(size_t n, const double A[n][n])`

:::{hint} Lógica y Consideraciones
- Usá VLA (Variable Length Arrays) en los parámetros para permitir sintaxis limpia de matrices 2D en C99+.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_14)=
### Ejercicio 1.04b.14 - Librería de Manipulación de Conjuntos sobre Arreglos ⭐⭐⭐⭐☆

Implementá `conjunto_arr.h` y `conjunto_arr.c`:
- `size_t conj_union(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `size_t conj_interseccion(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `size_t conj_diferencia(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `bool conj_pertenece(const int *A, size_t nA, int elem)`

:::{hint} Lógica y Consideraciones
- Las funciones retornan la cantidad efectiva de elementos colocados en el arreglo resultado `C`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_15)=
### Ejercicio 1.04b.15 - Librería de Transformación y Filtrado de Arreglos ⭐⭐⭐⭐☆

Diseñá `array_utils.h` y `array_utils.c` para procesar secuencias numéricas mediante funciones modulares:
- `size_t arr_filtrar_pares(const int *src, size_t n, int *dest)`: copia solo los valores pares a `dest` y retorna la cantidad colocada.
- `size_t arr_filtrar_mayores_que(const int *src, size_t n, int umbral, int *dest)`: copia solo los valores mayores que `umbral`.
- `void arr_escalar(int *v, size_t n, int factor)`: multiplica cada elemento del arreglo por un factor escalar.
- `long long arr_sumatoria(const int *v, size_t n)`: calcula la suma total de los elementos.

:::{hint} Lógica y Consideraciones
- Utilizá el calificador `const` en los arreglos de solo lectura y documentá precondiciones claras para cada función.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 4. Librerías de Utilidades del Sistema y E/S

(ej_b1_c04b_16)=
### Ejercicio 1.04b.16 - Librería de Validación de Entradas de Usuario ⭐⭐☆☆☆

Diseñá `input_val.h` y `input_val.c` para simplificar la lectura segura desde `stdin`:
- `int leer_entero_rango(const char *mensaje, size_t len_msg, int min, int max)`
- `double leer_double_positivo(const char *mensaje, size_t len_msg)`
- `bool leer_confirmacion_s_n(const char *mensaje, size_t len_msg)`
- `void leer_cadena_segura(const char *mensaje, size_t len_msg, char *buffer, size_t tam)`

:::{hint} Lógica y Consideraciones
- Limpiá el búfer de entrada `stdin` ante errores de formato para evitar lazos infinitos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_17)=
### Ejercicio 1.04b.17 - Librería de Fechas y Calendario ⭐⭐⭐☆☆

Creá `fechas.h` y `fechas.c`:
- `bool fecha_es_bisiesto(int anio)`
- `bool fecha_es_valida(int dia, int mes, int anio)`
- `int fecha_dias_del_mes(int mes, int anio)`
- `int fecha_diferencia_dias(int d1, int m1, int a1, int d2, int m2, int a2)`

:::{hint} Lógica y Consideraciones
- Tené en cuenta años bisiestos (divisibles por 4 y no por 100, salvo divisibles por 400).
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_18)=
### Ejercicio 1.04b.18 - Librería de Consola y Formato de Salida ⭐⭐☆☆☆

Diseñá `console_ui.h` y `console_ui.c`:
- `void ui_limpiar_pantalla(void)`
- `void ui_imprimir_titulo(const char *titulo, size_t len_titulo, char adorno)`
- `void ui_imprimir_barra_progreso(size_t actual, size_t total, int ancho)`
- `void ui_esperar_tecla(void)`

:::{hint} Lógica y Consideraciones
- Empleá secuencias de escape ANSI cuando sea posible para el control del terminal de forma portable.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_19)=
### Ejercicio 1.04b.19 - Librería de Medición de Tiempos de Ejecución ⭐⭐⭐☆☆

Implementá `cronometro.h` y `cronometro.c`:
- `void crono_iniciar(void)`
- `double crono_detener_ms(void)`
- `double crono_lapso_ms(void)`

:::{hint} Lógica y Consideraciones
- Utilizá `clock()` de `<time.h>` o `clock_gettime()` para medir el tiempo transcurrido en milisegundos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_20)=
### Ejercicio 1.04b.20 - Librería de Generación Numérica Pseudoaleatoria ⭐⭐⭐☆☆

Creá `azar.h` y `azar.c`:
- `void azar_inicializar(unsigned int semilla)`
- `int azar_entero_en_rango(int min, int max)`
- `double azar_double_0_1(void)`
- `bool azar_probabilidad(double p)` (retorna `true` con probabilidad `p` entre 0.0 y 1.0)
- `void azar_desordenar_arreglo(int *v, size_t n)`

:::{hint} Lógica y Consideraciones
- Encapsulá `rand()` y `srand()` de `<stdlib.h>` asegurando una distribución uniforme mediante operaciones adecuadas.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 5. Librerías de Simulación y Dominios Específicos

(ej_b1_c04b_21)=
### Ejercicio 1.04b.21 - Librería de Física: Cinemática ⭐⭐☆☆☆

Diseñá `fisica_cinematica.h` y `fisica_cinematica.c`:
- `double fis_posicion_mru(double x0, double v, double t)`
- `double fis_posicion_mruv(double x0, double v0, double a, double t)`
- `double fis_velocidad_mruv(double v0, double a, double t)`
- `double fis_tiempo_caida_libre(double altura, double g)`

:::{hint} Lógica y Consideraciones
- Definí una constante adecuada para la aceleración de la gravedad $g = 9.81$.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_22)=
### Ejercicio 1.04b.22 - Librería de Finanzas Básicas ⭐⭐☆☆☆

Creá `finanzas.h` y `finanzas.c`:
- `double fin_interes_simple(double capital, double tasa, double tiempo)`
- `double fin_interes_compuesto(double capital, double tasa, int periodos)`
- `double fin_cuota_prestamo(double capital, double tasa_mensual, int meses)`
- `double fin_valor_futuro_anualidad(double cuota, double tasa, int periodos)`

:::{hint} Lógica y Consideraciones
- Usá `pow()` de `<math.h>` para los cálculos con exponencial.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_23)=
### Ejercicio 1.04b.23 - Librería de Geometría 3D ⭐⭐⭐☆☆

Diseñá `geometria3d.h` y `geometria3d.c`:
- `double geo3d_volumen_esfera(double radio)`
- `double geo3d_area_esfera(double radio)`
- `double geo3d_volumen_cilindro(double radio, double altura)`
- `double geo3d_volumen_cono(double radio, double altura)`
- `double geo3d_distancia_puntos(double x1, double y1, double z1, double x2, double y2, double z2)`

:::{hint} Lógica y Consideraciones
- Verificá que el radio y la altura sean mayores a 0.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_24)=
### Ejercicio 1.04b.24 - Librería de Conversión de Bases Numéricas ⭐⭐⭐☆☆

Implementá `bases.h` y `bases.c`:
- `bool base_dec_a_binario(unsigned int dec, char *buf, size_t buf_size)`
- `bool base_dec_a_hex(unsigned int dec, char *buf, size_t buf_size)`
- `unsigned int base_binario_a_dec(const char *bin_str, size_t len_str)`
- `unsigned int base_hex_a_dec(const char *hex_str, size_t len_str)`

:::{hint} Lógica y Consideraciones
- Asegurá la validación de los caracteres recibidos en las cadenas fuente.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_25)=
### Ejercicio 1.04b.25 - Librería de Criptografía Clásica ⭐⭐⭐☆☆

Diseñá `cripto_simple.h` y `cripto_simple.c`:
- `void cripto_cesar_cifrar(char *texto, size_t len_texto, int desplazamiento)`
- `void cripto_cesar_descifrar(char *texto, size_t len_texto, int desplazamiento)`
- `void cripto_xor_transformar(char *texto, size_t len_texto, char clave)`

:::{hint} Lógica y Consideraciones
- El cifrado César debe mantener las letras minúsculas y mayúsculas en sus respectivos rangos alfabéticos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 6. Librerías Avanzadas y Estructuración Compleja

(ej_b1_c04b_26)=
### Ejercicio 1.04b.26 - Librería de Manejo de Colores RGB ⭐⭐⭐☆☆

Creá `color_utils.h` y `color_utils.c` para cálculos de color mediante operaciones aritméticas y fórmulas estándar:
- `double color_luminancia(unsigned char r, unsigned char g, unsigned char b)`: calcula la luminosidad relativa ($0.2126R + 0.7152G + 0.0722B$).
- `unsigned char color_escala_grises(unsigned char r, unsigned char g, unsigned char b)`: calcula el promedio de intensidad.
- `unsigned char color_mezclar_componente(unsigned char c1, unsigned char c2, double factor)`: realiza una interpolación lineal entre dos colores.

:::{hint} Lógica y Consideraciones
- Validá que `factor` se encuentre en el rango $[0.0, 1.0]$.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_27)=
### Ejercicio 1.04b.27 - Librería de Evaluación de Expresiones lógicas ⭐⭐⭐⭐☆

Diseñá `eval_logica.h` y `eval_logica.c`:
- `bool eval_and_3(bool a, bool b, bool c)`
- `bool eval_or_3(bool a, bool b, bool c)`
- `bool eval_xor(bool a, bool b)`
- `bool eval_implicacion(bool p, bool q)`
- `bool eval_equivalencia(bool p, bool q)`

:::{hint} Lógica y Consideraciones
- Expresá las tablas de verdad en funciones puras sin efectos secundarios.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_28)=
### Ejercicio 1.04b.28 - Librería de Gestión de Estados y Banderas Booleanas ⭐⭐⭐⭐☆

Implementá `flags.h` y `flags.c` para gestionar conjuntos de opciones mediante arreglos booleanos:
- `void flag_activar(bool banderas[], size_t n, size_t indice)`: activa la bandera en la posición indicada.
- `void flag_desactivar(bool banderas[], size_t n, size_t indice)`: desactiva la bandera indicada.
- `bool flag_consultar(const bool banderas[], size_t n, size_t indice)`: consulta el estado de la bandera.
- `void flag_reiniciar_todas(bool banderas[], size_t n, bool valor_defecto)`: asigna un valor uniforme a todas las banderas.
- `size_t flag_contar_activas(const bool banderas[], size_t n)`: cuenta cuántas banderas están en `true`.

:::{hint} Lógica y Consideraciones
- Validá que `indice < n` antes de acceder a las posiciones del arreglo.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_29)=
### Ejercicio 1.04b.29 - Librería de Manejo de Registro de Logs ⭐⭐⭐⭐☆

Diseñá `logger.h` y `logger.c`:
- `typedef enum { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR } log_nivel_t`
- `void log_set_nivel_minimo(log_nivel_t nivel)`
- `void log_mensaje(log_nivel_t nivel, const char *modulo, size_t len_mod, const char *mensaje, size_t len_msg)`

:::{hint} Lógica y Consideraciones
- Los mensajes con un nivel inferior al nivel mínimo configurado deben ser ignorados.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ej_b1_c04b_30)=
### Ejercicio 1.04b.30 - Librería de Verificación de Integridad (Checksum) ⭐⭐⭐⭐⭐

Creá `checksum.h` y `checksum.c`:
- `unsigned char chk_luhn_calcular(const char *digitos, size_t len_digitos)`: algoritmo de Luhn para números de tarjeta/identificación.
- `bool chk_luhn_validar(const char *digitos, size_t len_digitos)`
- `unsigned char chk_suma_paridad(const unsigned char *datos, size_t len)`
- `uint16_t chk_fletcher16(const unsigned char *datos, size_t len)`

---

## Notas Finales

:::{tip} Diseño de Librerías y Estructura del Proyecto
- **Estructura limpia:** Ubicá los archivos `.h` en `include/` y los `.c` en `src/`.
- **Ejemplos y Tests:** Agregá un programa de prueba en `examples/` y pruebas unitarias en `tests/`.
- **Automatización:** Proveé un `Makefile` con los objetivos `make`, `make test`, `make run` y `make clean`.
- **Guardas de inclusión:** Usá siempre `#ifndef NOMBRE_H`, `#define NOMBRE_H` y `#endif` en cada cabecera.
- **Encapsulamiento:** Ocultá funciones auxiliares usando la palabra clave `static` dentro del archivo `.c` en `src/`.
- **Prefijos de funciones:** Utilizá prefijos en los nombres de las funciones (ej. `geo_`, `str_`, `mat_`) para evitar colisiones de nombres.
:::
<!-- {tip} Diseño de Librerías y Estructura del Proyecto -->
