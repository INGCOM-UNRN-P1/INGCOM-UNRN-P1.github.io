---
title: "Ejercicios: Testing, Variables Globales y Estructura de Código"
short_title: "4. Testing y Estructura"
subtitle: "Pruebas unitarias, eliminación de variables globales, análisis de flujo y buenas prácticas"
---

# Ejercicios: Testing, Variables Globales y Estructura de Código

## Acerca de

El testing y el diseño estructurado de código son disciplinas indispensables
para
asegurar la confiabilidad de los programas en C. En este bloque no solo vas a
escribir código nuevo, sino también a **leer, analizar, depurar y refactorizar**
programas existentes.

Aprenderás a identificar el impacto negativo de las variables globales mutables,
diseñar suites de pruebas unitarias automatizadas con `assert()`, analizar la
cobertura de ramas de ejecución y aplicar las reglas de estilo institucional
(Allman, contratos y desacoplamiento de entrada/salida).

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-testing-verificacion`
- {ref}`capitulo-funciones-descomposicion`
- {ref}`capitulo-control-flujo`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Pruebas unitarias basadas en aserciones (`assert`) y patrón Arrange-Act-Assert (AAA) ({ref}`capitulo-testing-verificacion`).
2. Regla institucional de funciones puras desacopladas de E/S ({ref}`0x2002h`).
3. Prohibición estricta de variables globales mutables y paso explícito de contexto ({ref}`0x2004h`).
4. Estructuración de runners y métricas de prueba mediante códigos de retorno en `main`.

### Cuestiones de Estilo Aplicables
- **Variables Globales Prohibidas:** Según la {ref}`0x2004h`, está estrictamente prohibido el
  uso de variables globales.
- **Una aserción por función de prueba:** Según la {ref}`0x8001h`, cada función de test debe
  validar
  un escenario o comportamiento específico.
- **Desacoplamiento de E/S:** En conformidad con la {ref}`0x2002h`, las funciones de cálculo deben
  ser puras y no contener `printf` ni `scanf`.
- **Cláusulas de Guarda:** Según la {ref}`0x2001h`, se deben usar retornos
  anticipados para evitar anidaciones profundas.
- **Estilo Allman:** Según la {ref}`0x0007h`, las llaves deben colocarse en su
  propia línea alineadas con el bloque.

---

## 1. Conceptos Fundamentales de Testing y Aserciones

(ej_b1_c06_01)=
### Ejercicio 1.06.01 - Anatomía de una aserción ⭐☆☆☆☆

:::{exercise}
:label: ej-test-anatomia
Analizá el siguiente código y respondé:
1. ¿Qué biblioteca estándar se debe incluir para utilizar la macro `assert`?
2. ¿Qué ocurre exactamente en tiempo de ejecución si la condición evaluada
   resulta verdadera (`true`)?
3. ¿Qué ocurre si la condición resulta falsa (`false`)?

```{code-block} c
:linenos:
#include <assert.h>

int cuadrado(int n)
{
    return n * n;
}

int main(void)
{
    assert(cuadrado(4) == 16);
    assert(cuadrado(-3) == 9);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-anatomia
:class: dropdown
1. Se incluye `<assert.h>`.
2. Si la condición es `true`, el programa continúa su ejecución normal sin
   ninguna interrupción ni mensaje.
3. Si la condición es `false`, la macro `assert` aborta inmediatamente el
   programa con `SIGABRT` e imprime en `stderr` el nombre del archivo, el número
   de línea, la función y el texto exacto de la condición que falló.

:::
<!-- {solution} ej-test-anatomia -->

---

(ej_b1_c06_02)=
### Ejercicio 1.06.02 - Patrón AAA (Arrange - Act - Assert) ⭐☆☆☆☆

:::{exercise}
:label: ej-test-patron-aaa
Identificá y comentá las tres etapas del patrón AAA en la siguiente función de
prueba unitaria:

```{code-block} c
:linenos:
void test_calcular_promedio_tres_notas(void)
{
    int nota1 = 8;
    int nota2 = 6;
    int nota3 = 10;
    double esperado = 8.0;

    double resultado = calcular_promedio(nota1, nota2, nota3);

    assert(resultado == esperado);
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-patron-aaa
:class: dropdown
```{code-block} c
:linenos:
void test_calcular_promedio_tres_notas(void)
{
    // 1. Arrange (Preparar): Definición de datos de entrada y resultado esperado
    int nota1 = 8;
    int nota2 = 6;
    int nota3 = 10;
    double esperado = 8.0;

    // 2. Act (Actuar): Invocación de la función bajo prueba
    double resultado = calcular_promedio(nota1, nota2, nota3);

    // 3. Assert (Verificar): Comprobación de que el resultado coincide con lo esperado
    assert(resultado == esperado);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-patron-aaa -->

---

(ej_b1_c06_03)=
### Ejercicio 1.06.03 - Refactorización de pruebas acumuladas ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-una-asercion
El siguiente bloque de pruebas viola la {ref}`0x8001h` (una aserción o caso por función
de prueba). Refactorizalo en funciones independientes con nombres descriptivos:

```{code-block} c
:linenos:
void test_todas_las_operaciones(void)
{
    assert(sumar(2, 3) == 5);
    assert(sumar(-1, 1) == 0);
    assert(restar(10, 4) == 6);
    assert(restar(3, 8) == -5);
    assert(multiplicar(3, 4) == 12);
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-una-asercion
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

void test_sumar_positivos(void)
{
    assert(sumar(2, 3) == 5);
}

void test_sumar_opuestos(void)
{
    assert(sumar(-1, 1) == 0);
}

void test_restar_positivo_mayor(void)
{
    assert(restar(10, 4) == 6);
}

void test_restar_resultado_negativo(void)
{
    assert(restar(3, 8) == -5);
}

void test_multiplicar_positivos(void)
{
    assert(multiplicar(3, 4) == 12);
}

void correr_todas_las_pruebas(void)
{
    test_sumar_positivos();
    test_sumar_opuestos();
    test_restar_positivo_mayor();
    test_restar_resultado_negativo();
    test_multiplicar_positivos();
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-una-asercion -->

---

(ej_b1_c06_04)=
### Ejercicio 1.06.04 - Efectos colaterales prohibidos dentro de assert ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-side-effects-assert
Analizá el siguiente código. ¿Qué error crítico ocurrirá si este programa se
compila en modo Release con `-DNDEBUG`?

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>

int procesar_siguiente_item(int *indice)
{
    return (*indice)++;
}

int main(void)
{
    int idx = 0;
    assert(procesar_siguiente_item(&idx) == 0);
    assert(procesar_siguiente_item(&idx) == 1);
    printf("Índice final: %d\n", idx);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-side-effects-assert
:class: dropdown
Cuando se define `NDEBUG`, el preprocesador reemplaza todas las macros
`assert(x)` por nada (bloque vacío `((void)0)`).

En consecuencia, las llamadas a `procesar_siguiente_item(&idx)` **desaparecen
por completo del código ejecutable**, por lo que `idx` nunca se incrementa y el
programa finaliza imprimiendo `Índice final: 0` en lugar de `2`.

**Forma correcta:**
``` c
int idx = 0;
int r1 = procesar_siguiente_item(&idx);
assert(r1 == 0);
int r2 = procesar_siguiente_item(&idx);
assert(r2 == 1);
```
<!-- c -->

:::
<!-- {solution} ej-test-side-effects-assert -->

---

(ej_b1_c06_05)=
### Ejercicio 1.06.05 - Particiones de Equivalencia ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-particiones-equivalencia
Dada la siguiente especificación de la función `clasificar_edad`:
- Entrada: `edad` (entero).
- Retorno:
  - `1`: Menor de edad (`edad < 18`)
  - `2`: Adulto (`18 <= edad <= 64`)
  - `3`: Adulto mayor (`edad >= 65`)
  - `-1`: Edad inválida (`edad < 0` o `edad > 130`)

Diseñá el conjunto mínimo de valores de prueba para cubrir todas las
**particiones de equivalencia** válidas e inválidas.

:::
<!-- {exercise} -->

:::{solution} ej-test-particiones-equivalencia
:class: dropdown
Las particiones de equivalencia mínimas son:
1. **Inválida negativa:** `edad = -5` $\rightarrow$ Esperado: `-1`
2. **Menor de edad:** `edad = 10` $\rightarrow$ Esperado: `1`
3. **Adulto:** `edad = 30` $\rightarrow$ Esperado: `2`
4. **Adulto mayor:** `edad = 70` $\rightarrow$ Esperado: `3`
5. **Inválida excesiva:** `edad = 150` $\rightarrow$ Esperado: `-1`

```{code-block} c
:linenos:
#include <assert.h>

int clasificar_edad(int edad)
{
    if (edad < 0 || edad > 130)
    {
        return -1;
    }
    if (edad < 18)
    {
        return 1;
    }
    if (edad <= 64)
    {
        return 2;
    }
    return 3;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-particiones-equivalencia -->

---

(ej_b1_c06_06)=
### Ejercicio 1.06.06 - Análisis de Valores de Borde (Boundary Values) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-valores-borde
Tomando la función `clasificar_edad` del ejercicio anterior, identificá los
**valores de borde exactos** (límites) que deben ser testeados para asegurar que
no existan errores de tipo *off-by-one* (`<` en vez de `<=`).

:::
<!-- {exercise} -->

:::{solution} ej-test-valores-borde
:class: dropdown
Valores de borde críticos:
- Límite inferior de validez: `-1` (inválido) y `0` (válido, menor).
- Frontera menor/adulto: `17` (menor) y `18` (adulto).
- Frontera adulto/mayor: `64` (adulto) y `65` (mayor).
- Límite superior de validez: `130` (mayor) y `131` (inválido).

```{code-block} c
:linenos:
void test_bordes_clasificar_edad(void)
{
    assert(clasificar_edad(-1) == -1);
    assert(clasificar_edad(0) == 1);
    assert(clasificar_edad(17) == 1);
    assert(clasificar_edad(18) == 2);
    assert(clasificar_edad(64) == 2);
    assert(clasificar_edad(65) == 3);
    assert(clasificar_edad(130) == 3);
    assert(clasificar_edad(131) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-valores-borde -->

---

(ej_b1_c06_07)=
### Ejercicio 1.06.07 - Comparación de punto flotante en testing ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-comparacion-float
Analizá por qué la siguiente prueba puede fallar inesperadamente en C y escribí
una función auxiliar `son_cercanos(double a, double b, double epsilon)` para
solucionarlo:

``` c
double tercio = 1.0 / 3.0;
assert(tercio * 3.0 == 1.0); // ¡Peligro de precisión!
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-comparacion-float
:class: dropdown
En aritmética binaria de punto flotante (IEEE 754), números como `0.1` o
`1.0/3.0` no tienen representación exacta finita, lo que produce pequeñas
discrepancias en los últimos decimales.

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

bool son_cercanos(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}

void test_suma_decimales(void)
{
    double resultado = 0.1 + 0.2;
    double esperado = 0.3;
    assert(son_cercanos(resultado, esperado, 1e-9));
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-comparacion-float -->

---

(ej_b1_c06_08)=
### Ejercicio 1.06.08 - Aserciones defensivas vs Validación de Usuario ⭐☆☆☆☆

:::{exercise}
:label: ej-test-defensiva-vs-usuario
Explicá con claridad la diferencia conceptual entre:
1. Validar datos ingresados por el usuario por teclado con `scanf` y
   condicionales `if`.
2. Validar precondiciones internas del programador con `assert()`.

:::
<!-- {exercise} -->

:::{solution} ej-test-defensiva-vs-usuario
:class: dropdown
1. **Validación de Usuario (`if` / manejo de errores):** Es obligatoria para
   entradas externas incontrolables (teclado, archivos, red). El programa debe
   manejar el error con gracia, avisar al usuario y recuperarse.
2. **Aserciones (`assert`):** Son herramientas de depuración para detectar bugs
   de lógica del programador (violaciones de contrato que "nunca deberían
   ocurrir" si el código estuviera bien escrito).

:::
<!-- {solution} ej-test-defensiva-vs-usuario -->

---

(ej_b1_c06_09)=
### Ejercicio 1.06.09 - Función pura para cálculo de descuento ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-calculo-descuento
Diseñá una función pura `double aplicar_descuento(double precio_base, double
porcentaje)` que:
- Si `precio_base < 0` o `porcentaje < 0` o `porcentaje > 100`, retorne `-1.0`.
- De lo contrario, retorne el precio final descontado.

Escribí su suite completa de pruebas unitarias cubriendo casos normales, bordes
e inválidos.

:::
<!-- {exercise} -->

:::{solution} ej-test-calculo-descuento
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

double aplicar_descuento(double precio_base, double porcentaje)
{
    if (precio_base < 0.0 || porcentaje < 0.0 || porcentaje > 100.0)
    {
        return -1.0;
    }
    return precio_base * (1.0 - (porcentaje / 100.0));
}

void test_descuento_normal(void)
{
    assert(aplicar_descuento(200.0, 25.0) == 150.0);
}

void test_descuento_cero(void)
{
    assert(aplicar_descuento(100.0, 0.0) == 100.0);
}

void test_descuento_total(void)
{
    assert(aplicar_descuento(100.0, 100.0) == 0.0);
}

void test_descuento_precio_invalido(void)
{
    assert(aplicar_descuento(-50.0, 10.0) == -1.0);
}

void test_descuento_porcentaje_invalido(void)
{
    assert(aplicar_descuento(100.0, 150.0) == -1.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-calculo-descuento -->

---

(ej_b1_c06_10)=
### Ejercicio 1.06.10 - Estructura de Runner de Tests sin bibliotecas ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-runner-basico
Implementá un pequeño ejecutor de pruebas en C con retorno de conteos en `main`
para contabilizar pruebas ejecutadas y aprobadas sin usar variables globales.

**Tabla de Vectores de Prueba:**

| Caso de Prueba | Entrada | Función Evaluada | Retorno Esperado |
| :--- | :--- | :--- | :--- |
| Cuadrado positivo | `4` | `cuadrado(4)` | `16` |
| Cuadrado cero | `0` | `cuadrado(0)` | `0` |
| Cuadrado negativo | `-3` | `cuadrado(-3)` | `9` |

:::
<!-- {exercise} -->

:::{solution} ej-test-runner-basico
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>

int test_cuadrado_positivo(void)
{
    assert(2 * 2 == 4);
    return 1;
}

int test_cuadrado_cero(void)
{
    assert(0 * 0 == 0);
    return 1;
}

int main(void)
{
    int pasados = 0;
    int totales = 0;

    totales++;
    pasados += test_cuadrado_positivo();

    totales++;
    pasados += test_cuadrado_cero();

    printf("Resultados: %d/%d tests aprobados.\n", pasados, totales);
    return (pasados == totales) ? 0 : 1;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-runner-basico -->

---

## 2. Variables Globales y Efectos Colaterales

(ej_b1_c06_11)=
### Ejercicio 1.06.11 - El misterio del test que falla según el orden ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-misterio-orden
Analizá el siguiente código. ¿Por qué `test_dos()` pasa exitosamente si se
ejecuta primero, pero falla si se ejecuta después de `test_uno()`?

```{code-block} c
:linenos:
#include <assert.h>

int total_acumulado = 0; // Variable global

void acumular(int valor)
{
    total_acumulado += valor;
}

void test_uno(void)
{
    acumular(5);
    acumular(10);
    assert(total_acumulado == 15);
}

void test_dos(void)
{
    acumular(20);
    assert(total_acumulado == 20); // ¿Por qué falla si corre después de test_uno?
}

int main(void)
{
    test_uno();
    test_dos();
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-misterio-orden
:class: dropdown
`total_acumulado` es una variable global mutable. Al terminar `test_uno()`, su
valor queda en `15`. Cuando inicia `test_dos()`, `acumular(20)` suma 20 a 15,
resultando en `35` en lugar de `20`, provocando la caída del `assert`.

**Refactorización a función pura:**
```{code-block} c
:linenos:
int acumular(int total_actual, int valor)
{
    return total_actual + valor;
}

void test_uno(void)
{
    int total = 0;
    total = acumular(total, 5);
    total = acumular(total, 10);
    assert(total == 15);
}

void test_dos(void)
{
    int total = 0;
    total = acumular(total, 20);
    assert(total == 20);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-misterio-orden -->

---

(ej_b1_c06_12)=
### Ejercicio 1.06.12 - Sombreado de Variables (Shadowing) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-shadowing
Leé el siguiente fragmento e indicá qué imprime en consola y por qué:

```{code-block} c
:linenos:
#include <stdio.h>

int factor = 10; // Global

int multiplicar(int valor)
{
    int factor = 2; // Local con mismo nombre que la global
    return valor * factor;
}

int main(void)
{
    int resultado = multiplicar(5);
    printf("Resultado: %d, Factor: %d\n", resultado, factor);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-shadowing
:class: dropdown
Imprime: `Resultado: 10, Factor: 10`.

La variable local `factor = 2` dentro de `multiplicar` oculta ("ensombrece") a
la variable global `factor = 10` durante el alcance de la función. Al salir de
la función, la global permanece inalterada con valor `10`. La bandera `-Wshadow`
alerta explícitamente sobre estas declaraciones ambiguas.

:::
<!-- {solution} ej-test-shadowing -->

---

(ej_b1_c06_13)=
### Ejercicio 1.06.13 - Refactorización de Cuenta Bancaria con Estado Global ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-refactor-banco
El siguiente código implementa operaciones bancarias usando estado global.
Refactorizalo a funciones puras que reciban el saldo como parámetro y retornen
el nuevo saldo:

```{code-block} c
:linenos:
double saldo_global = 0.0;

void depositar(double monto)
{
    if (monto > 0)
    {
        saldo_global += monto;
    }
}

bool extraer(double monto)
{
    if (monto > 0 && saldo_global >= monto)
    {
        saldo_global -= monto;
        return true;
    }
    return false;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-refactor-banco
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

double depositar(double saldo_actual, double monto)
{
    if (monto <= 0.0 || saldo_actual < 0.0)
    {
        return saldo_actual;
    }
    return saldo_actual + monto;
}

double extraer(double saldo_actual, double monto, bool *exito)
{
    if (monto <= 0.0 || monto > saldo_actual)
    {
        *exito = false;
        return saldo_actual;
    }
    *exito = true;
    return saldo_actual - monto;
}

void test_operaciones_bancarias_puras(void)
{
    double saldo = 1000.0;
    bool ok = false;

    saldo = depositar(saldo, 500.0);
    assert(saldo == 1500.0);

    saldo = extraer(saldo, 200.0, &ok);
    assert(ok == true);
    assert(saldo == 1300.0);

    saldo = extraer(saldo, 2000.0, &ok);
    assert(ok == false);
    assert(saldo == 1300.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-refactor-banco -->

---

(ej_b1_c06_14)=
### Ejercicio 1.06.14 - Clasificación de funciones: Puras vs Impuras ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-puras-vs-impuras
Clasificá cada una de las siguientes funciones en **Pura** o **Impura**,
justificando en cada caso:

```{code-block} c
:linenos:
int g_contador = 0;

// Función 1
int duplicar(int x) {
    return x * 2;
}

// Función 2
int obtener_siguiente(void) {
    return ++g_contador;
}

// Función 3
int sumar_con_log(int a, int b) {
    printf("Sumando %d y %d\n", a, b);
    return a + b;
}

// Función 4
bool es_positivo(int n) {
    return n > 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-puras-vs-impuras
:class: dropdown
1. **`duplicar` (Pura):** Para el mismo valor de entrada siempre devuelve el
   mismo resultado y no produce ningún efecto secundario.
2. **`obtener_siguiente` (Impura):** Modifica y depende de la variable global
   `g_contador`. Llamadas sucesivas devuelven valores distintos.
3. **`sumar_con_log` (Impura):** Produce un efecto secundario en la consola
   mediante `printf`.
4. **`es_positivo` (Pura):** Cálculo determinístico basado únicamente en su
   parámetro.

:::
<!-- {solution} ej-test-puras-vs-impuras -->

---

(ej_b1_c06_15)=
### Ejercicio 1.06.15 - Variable `static` local vs Variable Global ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-static-local
Analizá el siguiente código. ¿Qué valores retorna en las sucesivas llamadas?
¿Por qué una variable `static` local también genera problemas para el testing
unitario independiente?

```{code-block} c
:linenos:
int contador_llamadas(void)
{
    static int veces = 0;
    veces++;
    return veces;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-static-local
:class: dropdown
La primera llamada retorna `1`, la segunda `2`, la tercera `3`, etc.

Aunque su alcance está restringido a la función, su tiempo de vida es durante
toda la ejecución del programa. Esto retiene estado mutable entre pruebas,
imposibilitando correr tests unitarios aislados y repetibles sin reiniciar el
binario.

:::
<!-- {solution} ej-test-static-local -->

---

(ej_b1_c06_16)=
### Ejercicio 1.06.16 - Modificación inadvertida de bandera global ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-bandera-global
Descubrí el bug en este programa donde dos funciones manipulan la misma variable
global `hay_error`:

```{code-block} c
:linenos:
#include <stdbool.h>
#include <stdio.h>

bool hay_error = false;

void validar_rango(int x)
{
    if (x < 0 || x > 100)
    {
        hay_error = true;
    }
}

void validar_paridad(int x)
{
    if (x % 2 != 0)
    {
        hay_error = true;
    }
    else
    {
        hay_error = false; // ¡Peligro!
    }
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-bandera-global
:class: dropdown
`validar_rango(-5)` detecta el error y pone `hay_error = true`. Pero luego
`validar_paridad(4)` como `4` es par, ejecuta la rama `else` y pone `hay_error =
false`, **borrando el error detectado previamente**.

**Refactorización:**
```{code-block} c
:linenos:
bool es_rango_valido(int x)
{
    return (x >= 0 && x <= 100);
}

bool es_par(int x)
{
    return (x % 2 == 0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-bandera-global -->

---

(ej_b1_c06_17)=
### Ejercicio 1.06.17 - Acoplamiento espurio entre módulos ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-acoplamiento-espurio
Explicá por qué compartir variables globales entre diferentes archivos `.c`
(usando `extern`) rompe el principio de modularidad y hace que un fallo en un
módulo rompa silenciosamente a otro.

:::
<!-- {exercise} -->

:::{solution} ej-test-acoplamiento-espurio
:class: dropdown
Cuando dos módulos acceden a una variable global compartida mediante `extern`:
1. No existe un contrato explícito sobre quién tiene derecho a modificarla ni
   cuándo.
2. Es imposible razonar sobre el estado de un módulo sin inspeccionar todo el
   código fuente del otro.
3. Las pruebas unitarias de un módulo requieren simular o sincronizar el estado
   global del otro, eliminando el aislamiento.

:::
<!-- {solution} ej-test-acoplamiento-espurio -->

---

(ej_b1_c06_18)=
### Ejercicio 1.06.18 - Conversor de Temperaturas desacoplado de estado ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-temperatura-desacoplada
Implementá las siguientes funciones puras de conversión sin usar variables
globales ni llamadas a `printf`:
- `double celsius_a_fahrenheit(double c)`
- `double fahrenheit_a_celsius(double f)`
- `double celsius_a_kelvin(double c)`

Escribí una función de prueba para cada conversión verificando los puntos fijos
conocidos ($0^\circ\text{C} = 32^\circ\text{F}$, $100^\circ\text{C} =
212^\circ\text{F}$, $0^\circ\text{C} = 273.15\text{ K}$).

:::
<!-- {exercise} -->

:::{solution} ej-test-temperatura-desacoplada
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

bool son_cercanos(double a, double b, double eps)
{
    return fabs(a - b) < eps;
}

double celsius_a_fahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

double fahrenheit_a_celsius(double f)
{
    return (f - 32.0) * 5.0 / 9.0;
}

double celsius_a_kelvin(double c)
{
    return c + 273.15;
}

void test_celsius_a_fahrenheit_cero(void)
{
    assert(son_cercanos(celsius_a_fahrenheit(0.0), 32.0, 1e-6));
}

void test_celsius_a_fahrenheit_ebullicion(void)
{
    assert(son_cercanos(celsius_a_fahrenheit(100.0), 212.0, 1e-6));
}

void test_celsius_a_kelvin_cero(void)
{
    assert(son_cercanos(celsius_a_kelvin(0.0), 273.15, 1e-6));
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-temperatura-desacoplada -->

---

(ej_b1_c06_19)=
### Ejercicio 1.06.19 - Simulación de cronómetro sin estado global ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-cronometro-puro
Diseñá funciones para manipular el tiempo acumulado en segundos representándolo
como un valor entero pasado por parámetro:
- `int tiempo_avanzar(int tiempo_actual, int segundos_delta)`
- `int tiempo_reiniciar(void)`
- `int tiempo_obtener_minutos(int tiempo_total)`
- `int tiempo_obtener_segundos(int tiempo_total)`

Escribí las pruebas unitarias que validen avances sucesivos.

:::
<!-- {exercise} -->

:::{solution} ej-test-cronometro-puro
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

int tiempo_avanzar(int tiempo_actual, int segundos_delta)
{
    if (segundos_delta < 0)
    {
        return tiempo_actual;
    }
    return tiempo_actual + segundos_delta;
}

int tiempo_reiniciar(void)
{
    return 0;
}

int tiempo_obtener_minutos(int tiempo_total)
{
    return tiempo_total / 60;
}

int tiempo_obtener_segundos(int tiempo_total)
{
    return tiempo_total % 60;
}

void test_cronometro_avance(void)
{
    int t = tiempo_reiniciar();
    t = tiempo_avanzar(t, 45);
    t = tiempo_avanzar(t, 30);
    assert(t == 75);
    assert(tiempo_obtener_minutos(t) == 1);
    assert(tiempo_obtener_segundos(t) == 15);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-cronometro-puro -->

---

(ej_b1_c06_20)=
### Ejercicio 1.06.20 - Detección de fugas de estado entre funciones ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-fuga-estado
Dado el siguiente código con una variable global oculta:

```{code-block} c
:linenos:
int ultimo_resultado = 0;

int multiplicar_y_guardar(int a, int b)
{
    ultimo_resultado = a * b;
    return ultimo_resultado;
}

```
<!-- {code-block} c -->

Explicá qué problema de diseño introduce `ultimo_resultado` si dos partes del
programa invocan la función en momentos intercalados.

:::
<!-- {exercise} -->

:::{solution} ej-test-fuga-estado
:class: dropdown
Si una parte del programa llama a `multiplicar_y_guardar(3, 4)`, el resultado
esperado es `12`. Pero si otra parte del programa llama a
`multiplicar_y_guardar(10, 2)` antes de que la primera lea `ultimo_resultado`,
el valor se sobrescribe a `20`, corrompiendo los datos del primer llamador.

:::
<!-- {solution} ej-test-fuga-estado -->

---

(ej_b1_c06_21)=
### Ejercicio 1.06.21 - Calculadora con memoria local vs global ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-calculadora-memoria
Implementá una calculadora donde el valor acumulado en memoria sea una variable
local gestionada en `main` o en las pruebas, utilizando funciones puras:
- `double calc_sumar(double acumulador, double valor)`
- `double calc_restar(double acumulador, double valor)`
- `double calc_multiplicar(double acumulador, double valor)`
- `double calc_dividir(double acumulador, double valor, bool *ok)`

Escribí pruebas unitarias para cada operación y una prueba para una secuencia de
operaciones combinadas.

:::
<!-- {exercise} -->

:::{solution} ej-test-calculadora-memoria
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

double calc_sumar(double acumulador, double valor)
{
    return acumulador + valor;
}

double calc_restar(double acumulador, double valor)
{
    return acumulador - valor;
}

double calc_multiplicar(double acumulador, double valor)
{
    return acumulador * valor;
}

double calc_dividir(double acumulador, double valor, bool *ok)
{
    if (valor == 0.0)
    {
        *ok = false;
        return acumulador;
    }
    *ok = true;
    return acumulador / valor;
}

void test_secuencia_calculadora(void)
{
    double acc = 0.0;
    bool ok = false;

    acc = calc_sumar(acc, 50.0);
    acc = calc_multiplicar(acc, 2.0);
    acc = calc_restar(acc, 20.0);
    acc = calc_dividir(acc, 4.0, &ok);

    assert(ok == true);
    assert(acc == 20.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-calculadora-memoria -->

---

(ej_b1_c06_22)=
### Ejercicio 1.06.22 - Máquina de Estados Finita Pura ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-fsm-pura
Modelá un validador de contraseña simple (estados: `0 = INICIO`, `1 =
TIENE_LONGITUD`, `2 = VALIDA`, `-1 = ERROR`) mediante una función pura de
transición:
`int transicion_estado(int estado_actual, char entrada)`

Escribí pruebas unitarias que simulen la secuencia de caracteres `a`, `b`, `1`
para verificar la transición de estados paso a paso sin variables globales.

:::
<!-- {exercise} -->

:::{solution} ej-test-fsm-pura
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <ctype.h>

int transicion_estado(int estado_actual, char entrada)
{
    if (estado_actual == 0)
    {
        return isalpha(entrada) ? 1 : -1;
    }
    if (estado_actual == 1)
    {
        return isdigit(entrada) ? 2 : 1;
    }
    if (estado_actual == 2)
    {
        return 2;
    }
    return -1;
}

void test_fsm_camino_exitoso(void)
{
    int estado = 0;
    estado = transicion_estado(estado, a);
    assert(estado == 1);
    estado = transicion_estado(estado, b);
    assert(estado == 1);
    estado = transicion_estado(estado, '9\);
    assert(estado == 2);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-fsm-pura -->

---

## 3. Lectura, Análisis y Flujo de Control

(ej_b1_c06_23)=
### Ejercicio 1.06.23 - Cobertura de Ramas (Branch Coverage) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-cobertura-ramas-cuadernillo
Dada la siguiente función de aprobación:

```{code-block} c
:linenos:
int evaluar_alumno(int parcial1, int parcial2, int asistencia_pct)
{
    if (asistencia_pct < 75)
    {
        return 0; // Libre por asistencia
    }
    if (parcial1 >= 60 && parcial2 >= 60)
    {
        return 2; // Promocionado
    }
    if (parcial1 >= 40 || parcial2 >= 40)
    {
        return 1; // Regular
    }
    return 0; // Reprobado
}

```
<!-- {code-block} c -->

¿Cuántas pruebas unitarias como mínimo se requieren para lograr el **100% de
cobertura de ramas (Branch Coverage)**? Escribí los casos de prueba con sus
valores de entrada y salida esperada.

:::
<!-- {exercise} -->

:::{solution} ej-test-cobertura-ramas
:class: dropdown
Se requieren al menos 5 casos de prueba para cubrir todas las ramas:
1. `asistencia_pct < 75` (ej. 50, 80, 80) $\rightarrow$ `0`
2. `parcial1 >= 60 && parcial2 >= 60` (ej. 80, 70, 80) $\rightarrow$ `2`
3. `parcial1 >= 60` pero `parcial2 < 60` y `>= 40` (ej. 70, 50, 80)
   $\rightarrow$ `1`
4. `parcial1 < 60` pero `parcial2 >= 40` (ej. 30, 50, 80) $\rightarrow$ `1`
5. Ambos parciales `< 40` con asistencia (ej. 30, 20, 80) $\rightarrow$ `0`

:::
<!-- {solution} ej-test-cobertura-ramas -->

---

(ej_b1_c06_24)=
### Ejercicio 1.06.24 - Detección de Código Muerto (Dead Code) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-dead-code
Analizá la siguiente función e identificá qué bloque de código es **código
muerto** (nunca podrá ejecutarse bajo ninguna circunstancia):

```{code-block} c
:linenos:
int calcular_tarifa(int edad)
{
    if (edad < 0)
    {
        return -1;
    }
    if (edad >= 0 && edad <= 12)
    {
        return 50;
    }
    if (edad > 12)
    {
        return 100;
    }
    // ¿Puede ejecutarse esta línea alguna vez?
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-dead-code
:class: dropdown
La línea `return 0;` al final es **código muerto** porque los tres bloques `if`
anteriores cubren exhaustivamente todos los números enteros posibles ($
ext{edad} < 0$, $0 \le  ext{edad} \le 12$, $    ext{edad} > 12$).

**Versión refactorizada y limpia:**
```{code-block} c
:linenos:
int calcular_tarifa(int edad)
{
    if (edad < 0)
    {
        return -1;
    }
    if (edad <= 12)
    {
        return 50;
    }
    return 100;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-dead-code -->

---

(ej_b1_c06_25)=
### Ejercicio 1.06.25 - Cortocircuito Lógico y Orden de Evaluación ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-cortocircuito
Analizá el comportamiento de las operaciones con cortocircuito lógico (`&&` y
`||`). ¿Qué imprime el siguiente código y por qué la función `incrementar` no
siempre es invocada?

```{code-block} c
:linenos:
#include <stdio.h>

int llamadas = 0;

int incrementar(void)
{
    llamadas++;
    return 1;
}

int main(void)
{
    int a = 0;
    if (a != 0 && incrementar())
    {
        printf("Rama 1\n");
    }
    printf("Llamadas tras primer if: %d\n", llamadas);

    int b = 1;
    if (b == 1 || incrementar())
    {
        printf("Rama 2\n");
    }
    printf("Llamadas tras segundo if: %d\n", llamadas);
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-cortocircuito
:class: dropdown
Imprime:
```
Llamadas tras primer if: 0
Rama 2
Llamadas tras segundo if: 0
```
- En `a != 0 && incrementar()`, como `a != 0` es falso, el operador `&&` evalúa
  a falso sin evaluar la segunda parte.
- En `b == 1 || incrementar()`, como `b == 1` es verdadero, el operador `||`
  evalúa a verdadero sin evaluar la segunda parte.
En ningún caso se ejecuta `incrementar()`.

:::
<!-- {solution} ej-test-cortocircuito -->

---

(ej_b1_c06_26)=
### Ejercicio 1.06.26 - Cláusulas de Guarda vs Código en Flecha ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-guardas-vs-flecha
Refactorizá la siguiente función anidada aplicando **cláusulas de guarda** según
la {ref}`0x2001h`:

```{code-block} c
:linenos:
int procesar_pedido(int cantidad, double precio_unitario, bool cliente_vip)
{
    int resultado = -1;
    if (cantidad > 0)
    {
        if (precio_unitario > 0.0)
        {
            if (cliente_vip)
            {
                resultado = (int)(cantidad * precio_unitario * 0.85);
            }
            else
            {
                resultado = (int)(cantidad * precio_unitario);
            }
        }
    }
    return resultado;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-guardas-vs-flecha
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

int procesar_pedido(int cantidad, double precio_unitario, bool cliente_vip)
{
    if (cantidad <= 0 || precio_unitario <= 0.0)
    {
        return -1;
    }
    if (cliente_vip)
    {
        return (int)(cantidad * precio_unitario * 0.85);
    }
    return (int)(cantidad * precio_unitario);
}

void test_pedido_invalido_cantidad(void)
{
    assert(procesar_pedido(0, 10.0, false) == -1);
}

void test_pedido_invalido_precio(void)
{
    assert(procesar_pedido(5, -2.0, false) == -1);
}

void test_pedido_regular(void)
{
    assert(procesar_pedido(10, 10.0, false) == 100);
}

void test_pedido_vip(void)
{
    assert(procesar_pedido(10, 10.0, true) == 85);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-guardas-vs-flecha -->

---

(ej_b1_c06_27)=
### Ejercicio 1.06.27 - Detección de Fallthrough accidental en switch ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-fallthrough-switch
Descubrí el bug en la siguiente función de cálculo de días de un mes y
corregilo:

```{code-block} c
:linenos:
int dias_del_mes(int mes)
{
    int dias = 0;
    switch (mes)
    {
        case 2:
            dias = 28;
        case 4:
        case 6:
        case 9:
        case 11:
            dias = 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias = 31;
        default:
            dias = -1;
    }
    return dias;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-fallthrough-switch
:class: dropdown
En el código original falta la instrucción `break;` al final de cada grupo de
casos. Por lo tanto, para cualquier mes, la ejecución continúa cayendo
(*fallthrough*) hasta el bloque `default`, retornando siempre `-1`.

**Solución:**
```{code-block} c
:linenos:
int dias_del_mes(int mes)
{
    switch (mes)
    {
        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return -1;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-fallthrough-switch -->

---

(ej_b1_c06_28)=
### Ejercicio 1.06.28 - Detección de Error Off-by-one en Lazos ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-off-by-one
El siguiente algoritmo debe sumar los primeros $N$ números naturales ($1 + 2 +
\dots + N$). Descubrí el error en la condición del lazo:

```{code-block} c
:linenos:
int suma_primeros_n(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int total = 0;
    for (int i = 1; i < n; i++) // ¿Qué error hay acá?
    {
        total += i;
    }
    return total;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-off-by-one
:class: dropdown
El lazo utiliza `i < n`, lo que omite sumar el último valor $N$. Para $N=4$,
suma $1+2+3 = 6$ en lugar de $1+2+3+4 = 10$.

**Corrección:**
```{code-block} c
:linenos:
int suma_primeros_n(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-off-by-one -->

---

(ej_b1_c06_29)=
### Ejercicio 1.06.29 - Desacople de Entrada/Salida para Testabilidad ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-desacople-io
La siguiente función no se puede someter a pruebas unitarias automatizadas
porque lee con `scanf` e imprime con `printf`. Refactorizala en dos funciones:
una de cálculo puro y otra para la interacción con el usuario:

```{code-block} c
:linenos:
void calcular_imc_interactivo(void)
{
    float peso = 0.0f;
    float altura = 0.0f;
    printf("Ingrese peso en kg: ");
    scanf("%f", &peso);
    printf("Ingrese altura en m: ");
    scanf("%f", &altura);

    float imc = peso / (altura * altura);
    if (imc < 18.5f)
    {
        printf("Bajo peso\n");
    }
    else if (imc < 25.0f)
    {
        printf("Normal\n");
    }
    else
    {
        printf("Sobrepeso\n");
    }
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-desacople-io
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

float calcular_imc(float peso, float altura)
{
    if (peso <= 0.0f || altura <= 0.0f)
    {
        return -1.0f;
    }
    return peso / (altura * altura);
}

int clasificar_imc(float imc)
{
    if (imc <= 0.0f)
    {
        return -1; // Inválido
    }
    if (imc < 18.5f)
    {
        return 1; // Bajo peso
    }
    if (imc < 25.0f)
    {
        return 2; // Normal
    }
    return 3; // Sobrepeso
}

void test_calculo_y_clasificacion_imc(void)
{
    float imc = calcular_imc(70.0f, 1.75f);
    assert(imc > 22.8f && imc < 22.9f);
    assert(clasificar_imc(imc) == 2);
    assert(clasificar_imc(16.0f) == 1);
    assert(clasificar_imc(28.0f) == 3);
    assert(clasificar_imc(-1.0f) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-desacople-io -->

---

(ej_b1_c06_30)=
### Ejercicio 1.06.30 - Tabla de Traza de Ejecución (Trace Table) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-tabla-traza
Construí una tabla de traza paso a paso para la llamada `mcd(18, 12)` mostrando
los valores de las variables en cada iteración del lazo:

```{code-block} c
:linenos:
int mcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-tabla-traza
:class: dropdown
| Iteración | `a` (inicio) | `b` (inicio) | `temp` (`b`) | `a % b` | `b` (nuevo) | `a` (nuevo) | Condición (`b != 0`) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Inicio** | 18 | 12 | - | - | - | - | `true` |
| **1** | 18 | 12 | 12 | 6 | 6 | 12 | `true` |
| **2** | 12 | 6 | 6 | 0 | 0 | 6 | `false` |
| **Fin** | 6 | 0 | - | - | - | - | Retorna `6` |

:::
<!-- {solution} ej-test-tabla-traza -->

---

(ej_b1_c06_31)=
### Ejercicio 1.06.31 - Principio de Responsabilidad Única (SRP) ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-srp-refactor
La siguiente función realiza tres tareas simultáneas: calcular la suma de un
arreglo, buscar el máximo y contar negativos. Refactorizala en tres funciones
atómicas según la {ref}`0x2005h`:

``` c
void procesar_todo(const int arr[], int n, int *suma, int *maximo, int *negativos);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-srp-refactor
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

int calcular_suma(const int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

int encontrar_maximo(const int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int contar_negativos(const int arr[], int n)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            cont++;
        }
    }
    return cont;
}

void test_funciones_atomicas(void)
{
    int datos[] = {3, -1, 8, -5, 2};
    assert(calcular_suma(datos, 5) == 7);
    assert(encontrar_maximo(datos, 5) == 8);
    assert(contar_negativos(datos, 5) == 2);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-srp-refactor -->

---

(ej_b1_c06_32)=
### Ejercicio 1.06.32 - Testeo de Año Bisiesto Exhaustivo ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-bisiesto-exhaustivo
Implementá `bool es_bisiesto(int anio)` y diseñá una suite de pruebas que
verifique las cuatro reglas del calendario gregoriano:
1. Años múltiplos de 4 no múltiplos de 100 (ej. 2024 $\rightarrow$ `true`).
2. Años no múltiplos de 4 (ej. 2023 $\rightarrow$ `false`).
3. Años múltiplos de 100 pero no de 400 (ej. 1900 $\rightarrow$ `false`).
4. Años múltiplos de 400 (ej. 2000 $\rightarrow$ `true`).

:::
<!-- {exercise} -->

:::{solution} ej-test-bisiesto-exhaustivo
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool es_bisiesto(int anio)
{
    if (anio <= 0)
    {
        return false;
    }
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));
}

void test_bisiesto_multiplo_4(void)
{
    assert(es_bisiesto(2024) == true);
}

void test_no_bisiesto_comun(void)
{
    assert(es_bisiesto(2023) == false);
}

void test_no_bisiesto_fin_de_siglo(void)
{
    assert(es_bisiesto(1900) == false);
}

void test_bisiesto_cuatrisecular(void)
{
    assert(es_bisiesto(2000) == true);
}

void test_bisiesto_invalido(void)
{
    assert(es_bisiesto(-400) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-bisiesto-exhaustivo -->

---

(ej_b1_c06_33)=
### Ejercicio 1.06.33 - Detección de mutación en arreglos de solo lectura ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-const-arrays
Analizá el siguiente código. ¿Por qué agregar el calificador `const` en la firma
de `buscar_elemento` previene bugs accidentales de modificación en las pruebas?

``` c
// Incorrecto:
int buscar_elemento(int arr[], int n, int objetivo);

// Correcto (seguro):
int buscar_elemento(const int arr[], int n, int objetivo);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-const-arrays
:class: dropdown
El calificador `const` garantiza contractualmente que la función es de **solo
lectura**. Si por error un programador escribe `arr[i] = 0;` en lugar de `if
(arr[i] == 0)`, el compilador rechaza la compilación con un error inmediato
(`assignment of read-only location`), evitando corromper los datos del llamador.

:::
<!-- {solution} ej-test-const-arrays -->

---

(ej_b1_c06_34)=
### Ejercicio 1.06.34 - Búsqueda de errores lógicos con aserciones de invariante ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-invariantes-lazo
En el siguiente algoritmo para calcular la división entera por restas sucesivas,
agregá una aserción al final que verifique la invariante matemática fundamental:
$\text{dividendo} = \text{divisor} \times \text{cociente} + \text{resto}$.

```{code-block} c
:linenos:
void division_lenta(int dividendo, int divisor, int *cociente, int *resto)
{
    assert(divisor > 0);
    assert(dividendo >= 0);

    int c = 0;
    int r = dividendo;
    while (r >= divisor)
    {
        r -= divisor;
        c++;
    }
    *cociente = c;
    *resto = r;

    // Aserción de invariante:
    assert(dividendo == (divisor * (*cociente)) + (*resto));
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-invariantes-lazo
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

void test_division_con_invariante(void)
{
    int c = 0;
    int r = 0;

    division_lenta(10, 3, &c, &r);
    assert(c == 3 && r == 1);

    division_lenta(20, 5, &c, &r);
    assert(c == 4 && r == 0);

    division_lenta(3, 7, &c, &r);
    assert(c == 0 && r == 3);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-invariantes-lazo -->

---

## 4. Estilo, Estructura y Contratos

(ej_b1_c06_35)=
### Ejercicio 1.06.35 - Verificación de Estilo Allman ⭐☆☆☆☆

:::{exercise}
:label: ej-test-estilo-allman
Identificá las violaciones de la {ref}`0x0007h` (Estilo Allman) en el siguiente
código y reescribilo con las llaves correctamente alineadas en su propia línea:

```{code-block} c
:linenos:
// Código mal formateado:
int valor_absoluto(int n) {
    if (n < 0) {
        return -n;
    } else {
        return n;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-estilo-allman
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

int valor_absoluto(int n)
{
    if (n < 0)
    {
        return -n;
    }
    else
    {
        return n;
    }
}

void test_valor_absoluto(void)
{
    assert(valor_absoluto(-12) == 12);
    assert(valor_absoluto(0) == 0);
    assert(valor_absoluto(15) == 15);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-estilo-allman -->

---

(ej_b1_c06_36)=
### Ejercicio 1.06.36 - Eliminación de Números Mágicos ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-numeros-magicos
Refactorizá la siguiente función reemplazando todos los **números mágicos** por
constantes simbólicas (`#define` o `const`) descriptivas según la {ref}`0x0003h`:

```{code-block} c
:linenos:
double calcular_costo_envio(double peso)
{
    if (peso <= 5.0)
    {
        return 500.0;
    }
    if (peso <= 20.0)
    {
        return 500.0 + (peso - 5.0) * 80.0;
    }
    return 1700.0 + (peso - 20.0) * 120.0;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-numeros-magicos
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

#define PESO_LIMITE_LIVIANO 5.0
#define PESO_LIMITE_MEDIO 20.0
#define TARIFA_BASE_LIVIANO 500.0
#define TARIFA_BASE_MEDIO 1700.0
#define COSTO_KG_MEDIO 80.0
#define COSTO_KG_PESADO 120.0

double calcular_costo_envio(double peso)
{
    if (peso <= 0.0)
    {
        return -1.0;
    }
    if (peso <= PESO_LIMITE_LIVIANO)
    {
        return TARIFA_BASE_LIVIANO;
    }
    if (peso <= PESO_LIMITE_MEDIO)
    {
        return TARIFA_BASE_LIVIANO + (peso - PESO_LIMITE_LIVIANO) * COSTO_KG_MEDIO;
    }
    return TARIFA_BASE_MEDIO + (peso - PESO_LIMITE_MEDIO) * COSTO_KG_PESADO;
}

void test_costo_envio_limites(void)
{
    assert(calcular_costo_envio(5.0) == 500.0);
    assert(calcular_costo_envio(10.0) == 900.0);
    assert(calcular_costo_envio(20.0) == 1700.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-numeros-magicos -->

---

(ej_b1_c06_37)=
### Ejercicio 1.06.37 - Documentación de Contratos con Doxygen ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-contratos-doxygen
Escribí el bloque de documentación estructurada con etiquetas Doxygen (`@brief`,
`@param`, `@pre`, `@returns`, `@post`) para la función
`calcular_potencia_entera`:

```{code-block} c
:linenos:
/**
 * @brief ...
 * @param base ...
 * @param exponente ...
 * @param ok ...
 * @pre ...
 * @returns ...
 * @post ...
 */
int calcular_potencia_entera(int base, int exponente, bool *ok);

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-contratos-doxygen
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

/**
 * @brief Calcula la potencia entera de una base elevada a un exponente no negativo.
 *
 * @param base Base entera.
 * @param exponente Exponente entero.
 * @param ok Puntero a booleano de estado de éxito.
 *
 * @pre `exponente >= 0`
 * @pre `ok != NULL`
 *
 * @returns El resultado de base^exponente si ok es true, o 0 en caso de error.
 *
 * @post Si exponente == 0, el retorno es 1 y *ok == true.
 */
int calcular_potencia_entera(int base, int exponente, bool *ok)
{
    if (ok == NULL || exponente < 0)
    {
        if (ok != NULL)
        {
            *ok = false;
        }
        return 0;
    }
    *ok = true;
    int resultado = 1;
    for (int i = 0; i < exponente; i++)
    {
        resultado *= base;
    }
    return resultado;
}

void test_potencia_contrato(void)
{
    bool ok = false;
    assert(calcular_potencia_entera(2, 3, &ok) == 8 && ok);
    assert(calcular_potencia_entera(5, 0, &ok) == 1 && ok);
    calcular_potencia_entera(2, -1, &ok);
    assert(ok == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-contratos-doxygen -->

---

(ej_b1_c06_38)=
### Ejercicio 1.06.38 - Inicialización obligatoria de variables ⭐☆☆☆☆

:::{exercise}
:label: ej-test-inicializacion-vars
Analizá qué comportamiento indefinido (*Undefined Behavior*) ocurre en la
siguiente función y corregilo aplicando la {ref}`0x7001h`:

```{code-block} c
:linenos:
int contar_multiplos(const int arr[], int n, int divisor)
{
    int contador; // ¡Variable no inicializada!
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % divisor == 0)
        {
            contador++;
        }
    }
    return contador;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-inicializacion-vars
:class: dropdown
Al no inicializarse, `contador` contiene un valor residual indeterminado
proveniente de la memoria de la pila. El incremento `contador++` genera
comportamiento indefinido y resultados erróneos impredecibles.

**Corrección:**
```{code-block} c
:linenos:
int contar_multiplos(const int arr[], int n, int divisor)
{
    if (divisor == 0)
    {
        return -1;
    }
    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % divisor == 0)
        {
            contador++;
        }
    }
    return contador;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-inicializacion-vars -->

---

(ej_b1_c06_39)=
### Ejercicio 1.06.39 - Organización de Archivo `.c` Estándar ⭐☆☆☆☆

:::{exercise}
:label: ej-test-organizacion-archivo
Ordená las siguientes secciones de un archivo `.c` según la {ref}`0x5005h`:
- Implementación de funciones públicas
- Inclusiones de bibliotecas estándar (`<stdio.h>`)
- Inclusiones de cabeceras propias (`"modulo.h"`)
- Función `main`
- Definición de macros `#define`
- Prototipos de funciones privadas (`static`)
- Implementación de funciones privadas (`static`)

:::
<!-- {exercise} -->

:::{solution} ej-test-organizacion-archivo
:class: dropdown
El orden estándar según la Regla `0x5005h` es:
1. Inclusiones de bibliotecas estándar (`#include <stdio.h>`).
2. Inclusiones de cabeceras del proyecto (`#include "modulo.h"`).
3. Definición de macros y constantes (`#define`).
4. Prototipos de funciones privadas (`static int auxiliar(void);`).
5. Función `main` (si es el archivo principal) o funciones públicas.
6. Implementación de funciones privadas (`static`).

:::
<!-- {solution} ej-test-organizacion-archivo -->

---

(ej_b1_c06_40)=
### Ejercicio 1.06.40 - Red de Seguridad: Default en Switch ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-default-switch
¿Por qué toda sentencia `switch` debe contener obligatoriamente una cláusula
`default` según la {ref}`0x1003h`, incluso
si el programador cree haber cubierto todos los casos posibles?

:::
<!-- {exercise} -->

:::{solution} ej-test-default-switch
:class: dropdown
El bloque `default` actúa como una red de seguridad defensiva ante datos
imprevistos, corrupción de memoria o adición futura de nuevos valores en el
dominio que no fueron contemplados.

```{code-block} c
:linenos:
#include <assert.h>

int obtener_dias_trimestre(int trimestre)
{
    switch (trimestre)
    {
        case 1:
            return 90;
        case 2:
            return 91;
        case 3:
            return 92;
        case 4:
            return 92;
        default:
            return -1; // Captura de valores inválidos
    }
}

void test_trimestres(void)
{
    assert(obtener_dias_trimestre(1) == 90);
    assert(obtener_dias_trimestre(5) == -1);
    assert(obtener_dias_trimestre(-1) == -1);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-default-switch -->

---

(ej_b1_c06_41)=
### Ejercicio 1.06.41 - Nombres de Variables Autoexplicativos ⭐☆☆☆☆

:::{exercise}
:label: ej-test-nombres-variables
Refactorizá el siguiente código reemplazando los nombres de variables crípticos
por identificadores claros en `snake_case` según la {ref}`0x0102h`:

```{code-block} c
:linenos:
// Código críptico:
double c(double p, double d, double t)
{
    double r = p - (p * (d / 100.0));
    double f = r + (r * (t / 100.0));
    return f;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-nombres-variables
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>

double calcular_precio_final(double precio_base, double porcentaje_descuento, double porcentaje_impuesto)
{
    double precio_con_descuento = precio_base - (precio_base * (porcentaje_descuento / 100.0));
    double precio_final = precio_con_descuento + (precio_con_descuento * (porcentaje_impuesto / 100.0));
    return precio_final;
}

void test_precio_final(void)
{
    assert(calcular_precio_final(100.0, 10.0, 21.0) == 108.9);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-nombres-variables -->

---

(ej_b1_c06_42)=
### Ejercicio 1.06.42 - Prohibición de Reutilización de Variables ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-reutilizacion-variables
Analizá qué problema de legibilidad y mantenimiento tiene el siguiente código
donde la variable `aux` se usa para tres propósitos completamente distintos:

```{code-block} c
:linenos:
int calcular_estadisticas_ventas(int ventas[], int n)
{
    int aux = 0;
    // Uso 1: acumular suma
    for (int i = 0; i < n; i++)
    {
        aux += ventas[i];
    }
    int promedio = aux / n;

    // Uso 2: buscar maximo
    aux = ventas[0];
    for (int i = 1; i < n; i++)
    {
        if (ventas[i] > aux)
        {
            aux = ventas[i];
        }
    }
    return aux;
}

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-reutilizacion-variables
:class: dropdown
Reutilizar la misma variable para propósitos disímiles dificulta la lectura,
impide agregar aserciones claras sobre estados intermedios y propaga errores si
un bloque asume que la variable conserva su valor anterior.

:::
<!-- {solution} ej-test-reutilizacion-variables -->

---

(ej_b1_c06_43)=
### Ejercicio 1.06.43 - Flags de Compilación Obligatorios ⭐☆☆☆☆

:::{exercise}
:label: ej-test-flags-compilacion
Explicá qué detecta cada uno de los siguientes flags de `gcc` y por qué son
obligatorios en las buenas prácticas de ingeniería ({ref}`0x5002h`):
- `-Wall`
- `-Wextra`
- `-Werror`
- `-Wpedantic`

:::
<!-- {exercise} -->

:::{solution} ej-test-flags-compilacion
:class: dropdown
- `-Wall`: Habilita todas las advertencias comunes sobre construcciones dudosas
  (variables no usadas, conversiones implícitas riesgosas).
- `-Wextra`: Habilita advertencias adicionales más rigurosas (comparaciones con
  signo/sin signo, parámetros no utilizados).
- `-Werror`: Trata todas las advertencias como errores de compilación,
  impidiendo generar el binario si existen problemas.
- `-Wpedantic`: Exige estricto apego al estándar ISO de C, rechazando
  extensiones propietarias del compilador.

:::
<!-- {solution} ej-test-flags-compilacion -->

---

(ej_b1_c06_44)=
### Ejercicio 1.06.44 - Funciones Auxiliares Privadas `static` ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-funciones-static
Explicá por qué las funciones auxiliares de un módulo `.c` que no forman parte
de la interfaz pública deben declararse obligatoriamente con el calificador
`static`.

:::
<!-- {exercise} -->

:::{solution} ej-test-funciones-static
:class: dropdown
El calificador `static` en una función a nivel de archivo restringe su
visibilidad exclusivamente a la unidad de traducción actual (*internal
linkage*). Esto encapsula los detalles de implementación internos y previene
errores de símbolos duplicados en tiempo de enlace (*linker collision*).

:::
<!-- {solution} ej-test-funciones-static -->

---

## 5. Suites de Pruebas Integradoras y Diagnóstico

(ej_b1_c06_45)=
### Ejercicio 1.06.45 - Suite de Pruebas: Validador de Fecha ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-fechas
Implementá una función pura `bool es_fecha_valida(int dia, int mes, int anio)` y
construí una suite completa de pruebas unitarias que cubra:
- Días válidos para meses de 31 días.
- Días válidos para meses de 30 días.
- Casos válidos e inválidos de febrero en año bisiesto (29/02/2024 vs
  29/02/2023).
- Días negativos o mayores a 31.
- Meses fuera del rango 1 a 12.
- Años menores o iguales a cero.

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-fechas
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool es_bisiesto_aux(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool es_fecha_valida(int dia, int mes, int anio)
{
    if (anio <= 0 || mes < 1 || mes > 12 || dia < 1)
    {
        return false;
    }
    int dias_max = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dias_max = 30;
    }
    else if (mes == 2)
    {
        dias_max = es_bisiesto_aux(anio) ? 29 : 28;
    }
    return dia <= dias_max;
}

void test_fecha_31_dias(void)
{
    assert(es_fecha_valida(31, 1, 2024) == true);
    assert(es_fecha_valida(32, 1, 2024) == false);
}

void test_fecha_30_dias(void)
{
    assert(es_fecha_valida(30, 4, 2024) == true);
    assert(es_fecha_valida(31, 4, 2024) == false);
}

void test_febrero_bisiesto(void)
{
    assert(es_fecha_valida(29, 2, 2024) == true);
    assert(es_fecha_valida(29, 2, 2023) == false);
}

void test_fecha_mes_invalido(void)
{
    assert(es_fecha_valida(15, 13, 2024) == false);
    assert(es_fecha_valida(15, 0, 2024) == false);
}

void correr_pruebas_fechas(void)
{
    test_fecha_31_dias();
    test_fecha_30_dias();
    test_febrero_bisiesto();
    test_fecha_mes_invalido();
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-fechas -->

---

(ej_b1_c06_46)=
### Ejercicio 1.06.46 - Suite de Pruebas: Tarifa de Estacionamiento ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-estacionamiento
Una playa de estacionamiento cobra según las siguientes reglas:
- Primera hora o fracción: $200 (tarifa base).
- Cada hora adicional: $150.
- Si el tiempo supera las 6 horas, se aplica un descuento del 10% sobre el
  total.
- Máximo cobro diario: $1200.

Implementá la función pura `double calcular_estacionamiento(int minutos)` y
diseñá su suite de pruebas exhaustiva.

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-estacionamiento
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

double calcular_estacionamiento(int minutos)
{
    if (minutos <= 0)
    {
        return 0.0;
    }
    int horas = (minutos + 59) / 60; // Redondeo hacia arriba a la hora siguiente
    double total = 200.0;
    if (horas > 1)
    {
        total += (horas - 1) * 150.0;
    }
    if (horas > 6)
    {
        total *= 0.90;
    }
    if (total > 1200.0)
    {
        total = 1200.0;
    }
    return total;
}

void test_estacionamiento_primera_hora(void)
{
    assert(calcular_estacionamiento(30) == 200.0);
    assert(calcular_estacionamiento(60) == 200.0);
}

void test_estacionamiento_horas_adicionales(void)
{
    assert(calcular_estacionamiento(61) == 350.0); // 2 horas
    assert(calcular_estacionamiento(180) == 500.0); // 3 horas
}

void test_estacionamiento_descuento_larga_estadia(void)
{
    // 7 horas = 200 + 6*150 = 1100. Con 10% desc = 990.
    assert(calcular_estacionamiento(420) == 990.0);
}

void test_estacionamiento_tope_maximo(void)
{
    assert(calcular_estacionamiento(1440) == 1200.0);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-estacionamiento -->

---

(ej_b1_c06_47)=
### Ejercicio 1.06.47 - Diagnóstico de Aserción Fallida ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-diagnostico-fallo
Al ejecutar una suite de pruebas, la terminal reporta el siguiente mensaje:

```
assertion failed: mcd(0, 5) == 5, file tests.c, line 42, function test_mcd_cero
Aborted (core dumped)
```

Analizá la causa raíz del fallo en la función `mcd(a, b)` y corregila:

``` c
int mcd(int a, int b)
{
    if (b == 0) return a;
    return mcd(b, a % b); // ¿Qué ocurre si a=0 y b=5 en la primera llamada?
}
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ej-test-diagnostico-fallo
:class: dropdown
Si se pasa `a = 0` y `b = 5`, la primera llamada no entra en `b == 0`. Llama a
`mcd(5, 0 % 5)` que es `mcd(5, 0)`, el cual entra en `b == 0` y retorna `5`.

Si la función original no contempla `a < 0` o `b < 0`, los módulos con signo en
C pueden generar números negativos. La corrección robusta es:

```{code-block} c
:linenos:
#include <assert.h>
#include <stdlib.h>

int mcd(int a, int b)
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

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-diagnostico-fallo -->

---

(ej_b1_c06_48)=
### Ejercicio 1.06.48 - Test de Regresión ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-regresion
Explicá el concepto de **Test de Regresión** (*Regression Test*):
1. ¿Cuál es el procedimiento correcto a seguir cuando un usuario o tester
   descubre un bug en producción?
2. ¿Por qué se debe escribir primero la prueba automatizada que reproduzca el
   fallo antes de modificar el código?

:::
<!-- {exercise} -->

:::{solution} ej-test-regresion
:class: dropdown
1. **Procedimiento:**
   - Reproducir el bug reportado.
   - Escribir una prueba unitaria específica que falle debido a ese bug.
   - Modificar el código fuente hasta que la prueba pase.
   - Incorporar la nueva prueba a la suite continua del proyecto.
2. Escribir la prueba primero confirma científicamente la existencia del bug y
   asegura que la corrección realmente solucione la causa raíz sin depender de
   verificaciones manuales.

:::
<!-- {solution} ej-test-regresion -->

---

(ej_b1_c06_49)=
### Ejercicio 1.06.49 - Suite de Pruebas: Desglose de Billetes ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-billetes
Implementá una función pura que calcule la cantidad mínima de billetes de $1000,
$500, $200 y $100 para un monto dado:
`bool desglosar_monto(int monto, int *b1000, int *b500, int *b200, int *b100)`

Diseñá la suite de pruebas unitarias cubriendo:
- Montos exactos de una sola denominación (ej. $3000).
- Montos combinados (ej. $3800 $\rightarrow$ 3x1000, 1x500, 1x200, 1x100).
- Montos no múltiplos de 100 (debe retornar `false`).
- Montos negativos o cero.

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-billetes
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

bool desglosar_monto(int monto, int *b1000, int *b500, int *b200, int *b100)
{
    if (monto <= 0 || monto % 100 != 0 || !b1000 || !b500 || !b200 || !b100)
    {
        return false;
    }
    *b1000 = monto / 1000;
    monto %= 1000;

    *b500 = monto / 500;
    monto %= 500;

    *b200 = monto / 200;
    monto %= 200;

    *b100 = monto / 100;
    return true;
}

void test_desglose_combinado(void)
{
    int mil = 0, quin = 0, dosc = 0, cien = 0;
    bool ok = desglosar_monto(3800, &mil, &quin, &dosc, &cien);
    assert(ok == true);
    assert(mil == 3 && quin == 1 && dosc == 1 && cien == 1);
}

void test_desglose_monto_invalido(void)
{
    int mil = 0, quin = 0, dosc = 0, cien = 0;
    assert(desglosar_monto(350, &mil, &quin, &dosc, &cien) == false);
    assert(desglosar_monto(-100, &mil, &quin, &dosc, &cien) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-billetes -->

---

(ej_b1_c06_50)=
### Ejercicio 1.06.50 - Suite de Pruebas: Validador de Números Primos ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-primos
Implementá la función pura `bool es_primo(int n)` con optimización hasta
$\sqrt{n}$ y diseñá su suite de pruebas con `assert()`:
- Casos no primos menores o iguales a 1 ($0, 1, -7$).
- Primer número primo ($2$).
- Primos pares e impares pequeños ($2, 3, 5, 7, 11, 13$).
- Compuestos impares que aparentan ser primos ($9, 15, 21, 25, 27, 49$).
- Primos grandes conocidos ($997$).

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-primos
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
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void test_primos_menores_o_iguales_uno(void)
{
    assert(es_primo(0) == false);
    assert(es_primo(1) == false);
    assert(es_primo(-7) == false);
}

void test_primos_basicos(void)
{
    assert(es_primo(2) == true);
    assert(es_primo(3) == true);
    assert(es_primo(13) == true);
    assert(es_primo(997) == true);
}

void test_compuestos_impares(void)
{
    assert(es_primo(9) == false);
    assert(es_primo(25) == false);
    assert(es_primo(49) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-primos -->

---

(ej_b1_c06_51)=
### Ejercicio 1.06.51 - Testeo de Funciones con Códigos de Error ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-codigos-error
Diseñá una función pura para calcular la velocidad promedio $v = d / t$:
`int calcular_velocidad(double distancia, double tiempo, double *velocidad)`

Códigos de retorno:
- `0`: Éxito.
- `1`: Distancia inválida (`distancia < 0`).
- `2`: Tiempo inválido (`tiempo <= 0`).
- `3`: Puntero `velocidad` nulo (`NULL`).

Escribí pruebas unitarias para cada uno de los 4 códigos posibles.

:::
<!-- {exercise} -->

:::{solution} ej-test-codigos-error
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stddef.h>

int calcular_velocidad(double distancia, double tiempo, double *velocidad)
{
    if (velocidad == NULL)
    {
        return 3;
    }
    if (distancia < 0.0)
    {
        return 1;
    }
    if (tiempo <= 0.0)
    {
        return 2;
    }
    *velocidad = distancia / tiempo;
    return 0;
}

void test_velocidad_exito(void)
{
    double v = 0.0;
    int codigo = calcular_velocidad(100.0, 2.0, &v);
    assert(codigo == 0);
    assert(v == 50.0);
}

void test_velocidad_distancia_invalida(void)
{
    double v = -99.0;
    int codigo = calcular_velocidad(-10.0, 2.0, &v);
    assert(codigo == 1);
    assert(v == -99.0);
}

void test_velocidad_tiempo_invalido(void)
{
    double v = -99.0;
    int codigo = calcular_velocidad(100.0, 0.0, &v);
    assert(codigo == 2);
    assert(v == -99.0);
}

void test_velocidad_puntero_nulo(void)
{
    int codigo = calcular_velocidad(100.0, 2.0, NULL);
    assert(codigo == 3);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-codigos-error -->

---

(ej_b1_c06_52)=
### Ejercicio 1.06.52 - Suite de Pruebas: Palíndromo Numérico ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-suite-palindromo
Implementá `bool es_numero_capicua(int n)` mediante funciones auxiliares puras
(`invertir_numero`) y construí su suite de pruebas:
- Números de 1 solo dígito (siempre son capicúas: `0, 1, 7`).
- Números pares capicúas (`1221`, `44`).
- Números impares capicúas (`12321`, `505`).
- Números no capicúas (`123`, `100`).
- Números negativos (por convención, retornan `false`).

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-palindromo
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>

int invertir_entero(int n)
{
    int invertido = 0;
    while (n > 0)
    {
        invertido = (invertido * 10) + (n % 10);
        n /= 10;
    }
    return invertido;
}

bool es_numero_capicua(int n)
{
    if (n < 0)
    {
        return false;
    }
    if (n < 10)
    {
        return true;
    }
    return n == invertir_entero(n);
}

void test_capicua_un_digito(void)
{
    assert(es_numero_capicua(0) == true);
    assert(es_numero_capicua(7) == true);
}

void test_capicua_multiples_digitos(void)
{
    assert(es_numero_capicua(1221) == true);
    assert(es_numero_capicua(12321) == true);
    assert(es_numero_capicua(123) == false);
    assert(es_numero_capicua(-121) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-palindromo -->

---

(ej_b1_c06_53)=
### Ejercicio 1.06.53 - Suite de Pruebas: Validador de Triángulo ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-triangulo
Implementá `int clasificar_triangulo(double a, double b, double c)`:
- `0`: No es triángulo válido (viola desigualdad triangular o lados $\le 0$).
- `1`: Equilátero (3 lados iguales).
- `2`: Isósceles (2 lados iguales).
- `3`: Escaleno (3 lados distintos).

Diseñá la suite de pruebas unitarias verificando cada clase y casos degenerados
($a + b = c$).

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-triangulo
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdbool.h>

bool lados_cercanos(double x, double y)
{
    return fabs(x - y) < 1e-6;
}

int clasificar_triangulo(double a, double b, double c)
{
    if (a <= 0.0 || b <= 0.0 || c <= 0.0)
    {
        return 0;
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return 0; // Desigualdad triangular violada
    }
    if (lados_cercanos(a, b) && lados_cercanos(b, c))
    {
        return 1; // Equilátero
    }
    if (lados_cercanos(a, b) || lados_cercanos(a, c) || lados_cercanos(b, c))
    {
        return 2; // Isósceles
    }
    return 3; // Escaleno
}

void test_triangulo_invalido(void)
{
    assert(clasificar_triangulo(1.0, 2.0, 3.0) == 0); // Degenerado
    assert(clasificar_triangulo(-1.0, 2.0, 2.0) == 0);
}

void test_triangulo_tipos(void)
{
    assert(clasificar_triangulo(5.0, 5.0, 5.0) == 1);
    assert(clasificar_triangulo(5.0, 5.0, 8.0) == 2);
    assert(clasificar_triangulo(3.0, 4.0, 5.0) == 3);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-triangulo -->

---

(ej_b1_c06_54)=
### Ejercicio 1.06.54 - Suite de Pruebas: Conversión de Segundos a Tiempo ⭐⭐☆☆☆

:::{exercise}
:label: ej-test-suite-segundos-tiempo
Implementá `bool segundos_a_tiempo(int total_segundos, int *horas, int *minutos,
int *segundos)` y diseñá su suite de pruebas con `assert()`:
- `total_segundos = 0` $\rightarrow$ `0h 0m 0s`.
- `total_segundos = 59` $\rightarrow$ `0h 0m 59s`.
- `total_segundos = 60` $\rightarrow$ `0h 1m 0s`.
- `total_segundos = 3661` $\rightarrow$ `1h 1m 1s`.
- `total_segundos = 86399` $\rightarrow$ `23h 59m 59s`.
- `total_segundos = -5` $\rightarrow$ `false`.

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-segundos-tiempo
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

bool segundos_a_tiempo(int total_segundos, int *horas, int *minutos, int *segundos)
{
    if (total_segundos < 0 || !horas || !minutos || !segundos)
    {
        return false;
    }
    *horas = total_segundos / 3600;
    int resto = total_segundos % 3600;
    *minutos = resto / 60;
    *segundos = resto % 60;
    return true;
}

void test_segundos_a_tiempo_normal(void)
{
    int h = 0, m = 0, s = 0;
    bool ok = segundos_a_tiempo(3661, &h, &m, &s);
    assert(ok == true);
    assert(h == 1 && m == 1 && s == 1);
}

void test_segundos_a_tiempo_cero(void)
{
    int h = 0, m = 0, s = 0;
    bool ok = segundos_a_tiempo(0, &h, &m, &s);
    assert(ok == true);
    assert(h == 0 && m == 0 && s == 0);
}

void test_segundos_a_tiempo_invalido(void)
{
    int h = 0, m = 0, s = 0;
    assert(segundos_a_tiempo(-10, &h, &m, &s) == false);
    assert(segundos_a_tiempo(100, NULL, &m, &s) == false);
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-segundos-tiempo -->

---

(ej_b1_c06_55)=
### Ejercicio 1.06.55 - Suite Integradora de Evaluación de Sistema de Calificaciones ⭐⭐⭐☆☆

:::{exercise}
:label: ej-test-suite-integradora
Diseñá una biblioteca modular completa para la gestión de notas de un curso con
las siguientes especificaciones:
1. `bool validar_nota(int nota)`: valida que la nota esté entre 1 y 10.
2. `double calcular_promedio_curso(const int notas[], int cantidad)`: calcula el
   promedio de notas válidas.
3. `int contar_aprobados(const int notas[], int cantidad, int nota_minima)`:
   cuenta cuántos alumnos superan o igualan la nota mínima.
4. `int estado_final_alumno(int parcial1, int parcial2, int recuperatorio)`:
   - Si `parcial1 >= 4` y `parcial2 >= 4`, la nota final es el promedio de
     ambos.
   - Si uno de los dos es $< 4$, se reemplaza la nota reprobada por la del
     `recuperatorio`. Si luego de esto ambas son $\ge 4$, aprueba.
   - Retorna `-1` si algún dato es inválido, `0` si reprueba, o la nota final
     entera.

Construí una suite integradora de pruebas unitarias automatizadas que cubra
todos los caminos y bordes con un runner central.

:::
<!-- {exercise} -->

:::{solution} ej-test-suite-integradora
:class: dropdown
```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool validar_nota(int nota)
{
    return (nota >= 1 && nota <= 10);
}

double calcular_promedio_curso(const int notas[], int cantidad)
{
    if (notas == NULL || cantidad <= 0)
    {
        return -1.0;
    }
    int suma = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (!validar_nota(notas[i]))
        {
            return -1.0;
        }
        suma += notas[i];
    }
    return (double)suma / cantidad;
}

int contar_aprobados(const int notas[], int cantidad, int nota_minima)
{
    if (notas == NULL || cantidad <= 0 || !validar_nota(nota_minima))
    {
        return -1;
    }
    int aprobados = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (notas[i] >= nota_minima)
        {
            aprobados++;
        }
    }
    return aprobados;
}

int estado_final_alumno(int p1, int p2, int rec)
{
    if (!validar_nota(p1) || !validar_nota(p2))
    {
        return -1;
    }
    if (p1 >= 4 && p2 >= 4)
    {
        return (p1 + p2) / 2;
    }
    if (!validar_nota(rec))
    {
        return 0; // Reprobado sin recuperatorio válido
    }
    if (p1 < 4 && rec >= 4 && p2 >= 4)
    {
        return (rec + p2) / 2;
    }
    if (p2 < 4 && rec >= 4 && p1 >= 4)
    {
        return (p1 + rec) / 2;
    }
    return 0;
}

void test_sistema_calificaciones(void)
{
    int notas[] = {7, 8, 4, 10, 6};
    assert(calcular_promedio_curso(notas, 5) == 7.0);
    assert(contar_aprobados(notas, 5, 6) == 4);

    // Caso directo aprobado
    assert(estado_final_alumno(8, 6, 0) == 7);

    // Caso recupera primer parcial
    assert(estado_final_alumno(2, 8, 6) == 7);

    // Caso recupera segundo parcial
    assert(estado_final_alumno(7, 3, 5) == 6);

    // Caso reprueba recuperatorio
    assert(estado_final_alumno(2, 8, 3) == 0);

    // Caso notas inválidas
    assert(estado_final_alumno(12, 8, 5) == -1);
}

int main(void)
{
    test_sistema_calificaciones();
    printf("¡Suite integradora ejecutada con 100%% de éxito!\n");
    return 0;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ej-test-suite-integradora -->

---

## Notas Finales

:::{tip} Buenas Prácticas para Testing en C

- **Funciones puras:** Diseñá funciones que dependan únicamente de sus
  parámetros y retornen su resultado sin alterar variables externas.
- **Sin variables globales:** Eliminá completamente el estado global para
  garantizar que tus pruebas sean reproducibles y corran en cualquier orden.
- **Aserciones específicas:** Una aserción por función de prueba para que los
  reportes de error identifiquen exactamente el escenario fallido.
- **Cobertura exhaustiva:** Asegurate de contemplar casos normales, casos de
  borde y entradas inválidas.

:::
<!-- {tip} Buenas Prácticas para Testing en C -->
