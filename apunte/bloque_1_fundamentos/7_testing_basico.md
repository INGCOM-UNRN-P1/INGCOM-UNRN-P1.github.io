---
title: Testing y Verificación Básica
short_title: '4b - Testing Básico'
subtitle: 'Pruebas unitarias, aserciones con assert y cobertura de ramas'
---

(capitulo-testing-verificacion)=

## Introducción

El **testing** o prueba de software es una práctica de ingeniería fundamental que consiste en verificar que el código funciona como se espera bajo diferentes condiciones. En programación estructurada, no basta con que el código "parezca" funcionar; es necesario someterlo a pruebas sistemáticas que validen su comportamiento y su estado ante múltiples escenarios de entrada.

### ¿Para qué probar?

Las pruebas cumplen propósitos didácticos y técnicos fundamentales:
*   **Validar funcionalidad aislada:** Garantiza que cada función realice su tarea correctamente de forma independiente.
*   **Detectar errores de forma temprana:** Encontrar bugs durante el desarrollo reduce el costo de depuración física y previene regresiones.
*   **Facilitar refactorizaciones:** Un conjunto sólido de pruebas permite modificar el diseño de una función con total seguridad, confiando en que el compilador y las aserciones alertarán ante cualquier anomalía.
*   **Documentación viva:** Las pruebas unitarias sirven como ejemplos ejecutables reales de cómo debe llamarse una función y qué resultados debe producir.

---

## Desarrollo

### Anatomía de una Prueba Unitaria (AAA)

Las **pruebas unitarias** (*unit tests*) verifican de forma aislada el comportamiento de componentes de software individuales (normalmente funciones específicas). 

Una prueba unitaria robusta se estructura sistemáticamente siguiendo el patrón **AAA (Arrange-Act-Assert)**:

1.  **Arrange (Preparar):** Configura los datos de entrada, las condiciones iniciales y el resultado esperado.
2.  **Act (Actuar):** Invoca la función bajo prueba con los parámetros preparados y captura el valor de retorno.
3.  **Assert (Verificar):** Comprueba que el resultado obtenido coincide exactamente con el valor esperado utilizando aserciones.

```c
#include <assert.h>

// Declaración de la función a probar
int calcular_suma(int a, int b);

void test_suma_valores_positivos(void) {
    // 1. Arrange: Preparar datos
    int a = 5;
    int b = 3;
    int esperado = 8;
    
    // 2. Act: Invocar la función
    int resultado = calcular_suma(a, b);
    
    // 3. Assert: Verificar
    assert(resultado == esperado);
}
```

#### Categorías de Casos de Prueba

Al diseñar una suite de pruebas, se deben contemplar obligatoriamente las siguientes categorías de escenarios:

*   **Casos Normales:** Entradas de datos representativas del flujo de ejecución estándar.
*   **Casos Límite (Boundary Cases):** Valores extremos del dominio de entrada de la función (ej: índices cero, valores máximos como `INT_MAX`, o cadenas de caracteres vacías).
*   **Casos de Error:** Comportamiento ante parámetros de entrada inválidos para garantizar que la función retorne códigos de error en lugar de desreferenciar memoria o provocar fallos.
*   **Casos de Esquina (Corner Cases):** Escenarios no convencionales compuestos por múltiples condiciones límite interactuando en simultáneo (ej: arreglos de tamaño cero o punteros nulos).

### Aserciones con `assert` y Cobertura de Ramas

La herramienta básica para la verificación estática y dinámica en desarrollo C es la macro `assert`, declarada en el archivo de cabecera `<assert.h>`.

#### Funcionamiento de la macro `assert`

La macro evalúa una expresión lógica. Si es verdadera, el programa continúa normalmente; si es falsa, la macro aborta inmediatamente la ejecución del programa mostrando por la salida de error estándar (`stderr`) la expresión lógica fallida, el nombre del archivo fuente y la línea física del código.

```c
#include <assert.h>

void procesar_indice(int *arreglo, int idx) {
    // Aserción de desarrollo para verificar precondiciones físicas
    assert(arreglo != NULL);
    assert(idx >= 0);
}
```

:::{warning} Uso Correcto de `assert` vs. Validaciones de Producción
*   **assert es para depuración:** Los `assert` se diseñan para detectar errores del programador durante la fase de desarrollo.
*   **Efecto de NDEBUG:** Si compilás el código con la macro `#define NDEBUG` (o con la bandera `-DNDEBUG` en GCC), el preprocesador **elimina por completo todos los asserts** del código binario final.
*   **Consecuencia de Seguridad:** Nunca debés utilizar `assert` para validar errores de ejecución inevitables (como ingresos de datos erróneos del usuario, archivos inexistentes o fallos de `malloc`). Si los colocás en un `assert`, el control de errores desaparecerá silenciosamente en la versión compilada para producción.

```c
// ✗ ANTIPATRÓN: Si NDEBUG está activo, la validación se descarta y el programa fallará catastróficamente.
assert(edad >= 0 && edad <= 150);

// ✓ DISEÑO CORRECTO: Validación persistente que siempre se evalúa en ejecución.
if (edad < 0 || edad > 150) {
    return ERROR_EDAD_INVALIDA;
}
```
:::

#### Cobertura de Ramas (Branch Coverage)

La cobertura de código indica qué caminos lógicos de nuestras funciones fueron ejecutados durante las pruebas. El estándar riguroso para programación estructurada es lograr el **100% de cobertura de ramas** (*branch coverage*), garantizando que se prueben tanto las condiciones verdaderas como las falsas de cada bifurcación del flujo de control.

```c
int valor_absoluto(int x) {
    if (x < 0) { // Bifurcación en rama 1 y rama 2
        return -x;
    }
    return x;
}

// Para lograr 100% de cobertura de ramas debemos invocar:
assert(valor_absoluto(-5) == 5); // Cubre la rama verdadera (x < 0)
assert(valor_absoluto(5) == 5);  // Cubre la rama falsa (x >= 0)
```

---

## Ejercicios de Autoevaluación

### Anatomía de Pruebas Unitarias

:::{exercise}
:label: ej-test-aaa-structure
Escribí una prueba unitaria para una función llamada `invertir_cadena(char *cadena)` estructurada de forma clara bajo el patrón AAA.
:::

:::{solution} ej-test-aaa-structure
:class: dropdown
```c
#include <assert.h>
#include <string.h>

void test_invertir_cadena_palabra_simple(void) {
    // 1. Arrange: Preparar el estado y datos de entrada
    char entrada[] = "hola";
    const char *esperado = "aloh";

    // 2. Act: Ejecutar la función bajo prueba
    invertir_cadena(entrada);

    // 3. Assert: Verificar el resultado
    assert(strcmp(entrada, esperado) == 0);
}
```
:::

:::{exercise}
:label: ej-test-boundary-cases
Dada la firma de función `int buscar_elemento(const int *arr, size_t n, int elem);`, enumerá al menos tres casos límite (*boundary cases*) y un caso de esquina (*corner case*) que debas incorporar obligatoriamente en tu suite de pruebas.
:::

:::{solution} ej-test-boundary-cases
:class: dropdown
*   **Casos límite (Boundary cases):**
    1.  `n == 1`: El arreglo posee un único elemento, y coincide con el buscado (`arr[0] == elem`).
    2.  `n == 1`: El arreglo posee un único elemento, y no coincide con el buscado (`arr[0] != elem`).
    3.  `elem` se encuentra exactamente en la primera posición del arreglo (`arr[0] == elem`).
    4.  `elem` se encuentra exactamente en la última posición del arreglo (`arr[n-1] == elem`).
*   **Caso de esquina (Corner case):**
    *   `n == 0` (búsqueda en un arreglo vacío). En este caso, la función debe abortar o retornar error de forma segura en lugar de desreferenciar.
:::

### Aserciones y Cobertura de Ramas

:::{exercise}
:label: ej-test-assert-production
Explicá de forma detallada por qué es un anti-patrón de seguridad crítico escribir `assert(malloc(100) != NULL);` en C y qué consecuencias provoca la definición de la macro `NDEBUG` en producción.
:::

:::{solution} ej-test-assert-production
:class: dropdown
La macro `assert(condición)` se desactiva y remueve físicamente del código compilado cuando se define la constante `#define NDEBUG`. 

Si escribimos `assert(malloc(100) != NULL);`, en la compilación de producción la llamada entera a `malloc` será eliminada del ejecutable. Por ende, la memoria nunca se reservará y el programa experimentará fallos silenciosos por desreferenciación de punteros no inicializados. Las asignaciones de recursos deben validarse con condicionales `if` tradicionales.
:::

:::{exercise}
:label: ej-test-cobertura-ramas
Dada la función:
```c
bool es_bisiesto(int anio) {
    if (anio % 400 == 0) return true;
    if (anio % 100 == 0) return false;
    if (anio % 4 == 0) return true;
    return false;
}
```
Escribí un conjunto de pruebas unitarias mínimo que garantice el 100% de cobertura de ramas (*branch coverage*).
:::

:::{solution} ej-test-cobertura-ramas
:class: dropdown
Para lograr el 100% de cobertura de ramas debemos forzar a que cada sentencia condicional tome caminos verdaderos y falsos:
```c
#include <assert.h>

void test_es_bisiesto_ramas(void) {
    assert(es_bisiesto(2000) == true);  // Evalúa VERDADERO la rama 1 (divisible por 400)
    assert(es_bisiesto(1900) == false); // Evalúa FALSO la rama 1 y VERDADERO la rama 2 (divisible por 100)
    assert(es_bisiesto(2024) == true);  // Evalúa FALSAS rama 1 y 2, y VERDADERO la rama 3 (divisible por 4)
    assert(es_bisiesto(2023) == false); // Evalúa FALSAS todas las ramas (camino por defecto final)
}
```
:::

---

## Glosario

::{glossary}
Prueba unitaria (Unit Test)
: Método de verificación que examina de forma aislada el comportamiento de bloques individuales de código fuente (habitualmente funciones).

AAA (Arrange-Act-Assert)
: Patrón estructurado para redactar pruebas unitarias en tres pasos: Preparar (Arrange), Actuar (Act) y Verificar (Assert).

Caso límite (Boundary Case)
: Caso de prueba diseñado para evaluar valores de entrada que están en los límites o extremos del rango de validez.

Caso de esquina (Corner Case)
: Caso de prueba excepcional donde se combinan en simultáneo múltiples condiciones o factores límite del sistema.

Cobertura de ramas (Branch Coverage)
: Métrica que mide el porcentaje de bifurcaciones condicionales que han sido evaluadas en caminos verdaderos y falsos durante la ejecución de las pruebas.
:::

---

## Síntesis y Resumen

En esta unidad cubriste los fundamentos prácticos del testeo de software en C:
- **Estructura AAA**: El diseño de pruebas unitarias se organiza separando la configuración de la entrada (Arrange), la llamada a la función (Act) y la comprobación del resultado (Assert).
- **Macro assert**: Es una herramienta exclusiva de desarrollo para comprobar precondiciones. El uso de la macro `NDEBUG` en producción elimina todos los `assert`, por lo que las validaciones esenciales del sistema deben realizarse mediante `if` tradicionales.
- **Cobertura de ramas**: Una suite de pruebas robusta aspira al 100% de cobertura de ramas, asegurando que todos los caminos condicionales posibles del programa hayan sido recorridos y validados.

---

## References y Lecturas Complementarias

- Myers, G. J., Sandler, C., & Badgett, T. (2011). *The Art of Software Testing*. John Wiley & Sons.
- Meszaros, G. (2007). *xUnit Test Patterns: Refactoring Test Code*. Pearson Education.
- ISO/IEC 9899 Language Standard Section 7.2: Diagnostics `<assert.h>`.
