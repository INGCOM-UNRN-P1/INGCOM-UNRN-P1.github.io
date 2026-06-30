---
title: Testing y Verificación en C
short_title: 'Testing'
description: 'Estrategias de prueba, uso de assert, TDD, frameworks de testing en C, y relación con el diseño por contratos.'
---

(testing-capitulo)=

(testing)=
## Testing

El **testing** o prueba de software es una práctica fundamental en el desarrollo que consiste en verificar que el código funciona como se espera bajo diferentes condiciones. En programación, no basta con que el código «parezca» funcionar; es necesario someterlo a pruebas sistemáticas que validen su comportamiento.

(para-que-probar)=
### ¿Para qué probar?

Las pruebas cumplen múltiples propósitos esenciales en el ciclo de desarrollo:

- **Validar funcionalidad aislada**: Cada componente debe funcionar correctamente de manera independiente.
- **Detectar errores temprano**: Encontrar bugs durante el desarrollo es significativamente más económico que hacerlo en producción.
- **Facilitar refactorizaciones**: Un conjunto sólido de pruebas permite modificar el código con confianza, sabiendo que las pruebas detectarán cualquier regresión.
- **Mejorar calidad y documentación**: Las pruebas sirven como ejemplos ejecutables de cómo usar el código.
- **Reducir el tiempo de debugging**: Los errores localizados mediante pruebas son más fáciles de diagnosticar.
- **Aumentar la confianza**: Tanto del desarrollador como del usuario final en la estabilidad del sistema.

:::{important}
En proyectos profesionales, el testing no es opcional. Es una práctica estándar que se espera en cualquier código de calidad industrial.
:::

(tipos-de-testing)=
### Tipos de Testing

Existen diferentes niveles de testing, cada uno con un propósito específico:

#### Testing Unitario

Las **pruebas unitarias** verifican el comportamiento de funciones o módulos individuales de forma aislada. Son las pruebas más granulares y fundamentales.

**Características:**
- Rápidas de ejecutar
- Fáciles de diagnosticar cuando fallan
- Deben ser independientes entre sí
- Cubren casos normales, extremos y de error

#### Testing de Integración

Las **pruebas de integración** verifican que múltiples componentes funcionen correctamente cuando se combinan. Por ejemplo, que una función de procesamiento de datos trabaje adecuadamente con las funciones de entrada/salida.

#### Testing de Sistema

Las **pruebas de sistema** evalúan el comportamiento del programa completo, desde la perspectiva del usuario final.

(anatomia-de-una-prueba)=
### Anatomía de una Prueba

Una prueba bien estructurada típicamente sigue el patrón **AAA (Arrange-Act-Assert)**:

1. **Arrange (Preparar)**: Configurar los datos y el estado necesario
2. **Act (Actuar)**: Ejecutar la función bajo prueba
3. **Assert (Verificar)**: Comprobar que el resultado es el esperado

```{code-block}c
:linenos:
void test_suma_positivo_positivo() {
    // Arrange: preparar datos de entrada
    int a = 5, b = 3;
    int esperado = 8;
    
    // Act: ejecutar la función
    int resultado = suma(a, b);
    
    // Assert: verificar el resultado
    assert(resultado == esperado);
}
```

(casos-de-prueba-importantes)=
### Casos de Prueba Importantes

Al diseñar pruebas, es crucial considerar diferentes categorías de casos:

#### Casos Normales

Representan el uso típico y esperado de la función:

```{code-block}c
:linenos:
void test_suma_numeros_positivos() {
    assert(suma(10, 20) == 30);
}

void test_suma_numeros_negativos() {
    assert(suma(-5, -3) == -8);
}
```

#### Casos Límite (Boundary Cases)

Prueban los extremos del dominio de entrada:

```{code-block}c
:linenos:
void test_suma_con_cero() {
    assert(suma(0, 5) == 5);
    assert(suma(5, 0) == 5);
    assert(suma(0, 0) == 0);
}

void test_suma_valores_maximos() {
    // Probar cerca de los límites del tipo de dato
    assert(suma(INT_MAX - 1, 1) == INT_MAX);
}
```

#### Casos de Error

Verifican el comportamiento ante entradas inválidas o condiciones de error:

```{code-block}c
:linenos:
void test_division_por_cero() {
    // La función debería manejar este error
    int resultado;
    bool exito = division_segura(10, 0, &resultado);
    assert(exito == false);
}
```

#### Casos de Esquina (Corner Cases)

Combinaciones inusuales pero válidas de condiciones límite:

```{code-block}c
:linenos:
void test_buscar_en_array_vacio() {
    int array[] = {};
    assert(buscar(array, 0, 42) == -1);
}
```

(ejercicios-de-autoevaluacion-conceptos-y-aaa)=
### Ejercicios de Autoevaluación (Conceptos y AAA)

:::{exercise}
:label: ej-test-aaa-structure
Escribí una prueba unitaria para una función llamada `invertir_cadena(char *cadena)` estructurada bajo el patrón AAA (Arrange-Act-Assert).
:::

:::{solution} ej-test-aaa-structure
:class: dropdown
```c
#include <assert.h>
#include <string.h>

void test_invertir_cadena_palabra_simple() {
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
- **Casos límite (Boundary cases)**:
  1. `n == 1`: El arreglo posee un único elemento, y coincide con el buscado (`arr[0] == elem`).
  2. `n == 1`: El arreglo posee un único elemento, y no coincide con el buscado (`arr[0] != elem`).
  3. `elem` se encuentra en la primera posición del arreglo (`arr[0] == elem`).
  4. `elem` se encuentra en la última posición del arreglo (`arr[n-1] == elem`).
- **Caso de esquina (Corner case)**:
  - `n == 0` (búsqueda en un arreglo vacío). En este caso, la función debe abortar o retornar error de forma segura antes de desreferenciar el puntero.
:::

:::{exercise}
:label: ej-test-unitario-vs-integracion
Explicá conceptualmente la diferencia que existe entre una prueba unitaria (*unit test*) y una prueba de integración, y fundamentá por qué es crucial el aislamiento en las pruebas unitarias.
:::

:::{solution} ej-test-unitario-vs-integracion
:class: dropdown
- **Prueba Unitaria**: Verifica la corrección de un único componente de software (normalmente una función individual) de forma completamente aislada de cualquier otro módulo o recurso externo (disco, red, base de datos).
- **Prueba de Integración**: Verifica la correcta interacción y comunicación entre dos o más módulos integrados del sistema.
El aislamiento en las pruebas unitarias es crucial porque asegura que si la prueba falla, la causa raíz del error se encuentra exclusivamente en la unidad bajo prueba. Si no existiera aislamiento, un fallo en una biblioteca de red externa podría hacer fallar el test unitario de un algoritmo de ordenamiento, haciendo que el diagnóstico del error sea complejo y confuso.
:::

---

(uso-de-assert)=
### Uso de `assert`

La macro `assert` es la herramienta básica para verificar condiciones en C:

```{code-block}c
:linenos:
#include <assert.h>

// Uso básico
assert(condición); // Si es falsa, termina el programa

// Ejemplos
assert(suma(2, 3) == 5);
assert(resultado != NULL);
assert(tamanio > 0 && tamanio <= MAX_TAMANIO);
```

:::{warning}
**Importante sobre `assert` en producción**

- `assert` está diseñado para desarrollo y debugging
- Se puede desactivar con `#define NDEBUG` antes de incluir `<assert.h>`
- En código de producción compilado con optimizaciones, los `assert` típicamente se eliminan
- Para validaciones que deben ejecutarse siempre, usar estructuras condicionales normales (`if`)

```{code-block}c
:linenos:
// ✗ NO usar assert para validar entrada del usuario
assert(edad >= 0 && edad <= 150);

// ✓ Usar validación explícita
if (edad < 0 || edad > 150) {
    fprintf(stderr, "Error: edad inválida\n");
    return ERROR_ENTRADA_INVALIDA;
}
```
:::

(estrategias-de-testing)=
### Estrategias de Testing

#### Cobertura de Código

La **cobertura** mide qué porcentaje del código es ejecutado por las pruebas. Tipos comunes:

- **Cobertura de líneas**: ¿Se ejecuta cada línea?
- **Cobertura de ramas**: ¿Se prueba cada camino condicional?
- **Cobertura de funciones**: ¿Se llama cada función?

```{code-block}c
:linenos:
int valor_absoluto(int x) {
    if (x < 0) {        // Rama 1
        return -x;
    }
    return x;           // Rama 2
}

// Para 100% cobertura de ramas:
void test_valor_absoluto() {
    assert(valor_absoluto(-5) == 5);   // Prueba rama 1
    assert(valor_absoluto(5) == 5);    // Prueba rama 2
    assert(valor_absoluto(0) == 0);    // Caso límite
}
```

#### Testing Basado en Propiedades

En lugar de casos específicos, verificar propiedades generales:

```{code-block}c
:linenos:
void test_suma_conmutativa() {
    // Propiedad: a + b = b + a
    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            assert(suma(i, j) == suma(j, i));
        }
    }
}

void test_suma_elemento_neutro() {
    // Propiedad: x + 0 = x
    for (int i = -100; i <= 100; i++) {
        assert(suma(i, 0) == i);
    }
}
```

(organizacion-de-tests)=
### Organización de Tests

Un proyecto bien estructurado separa el código de producción de las pruebas:

```
proyecto/
├── src/
│   ├── calculadora.h
│   ├── calculadora.c
│   └── main.c
├── tests/
│   ├── test_calculadora.c
│   ├── test_utilidades.c
│   └── run_tests.c
└── Makefile
```

Ejemplo de estructura de archivo de pruebas:

```{code-block}c
:linenos:
// tests/test_calculadora.c
#include <assert.h>
#include <stdio.h>
#include "../src/calculadora.h"

void test_suma() {
    assert(suma(2, 3) == 5);
    assert(suma(-1, 1) == 0);
    printf("✓ test_suma pasó\n");
}

void test_resta() {
    assert(resta(5, 3) == 2);
    assert(resta(3, 5) == -2);
    printf("✓ test_resta pasó\n");
}

int main() {
    printf("Ejecutando pruebas de calculadora...\n");
    test_suma();
    test_resta();
    printf("Todas las pruebas pasaron exitosamente\n");
    return 0;
}
```

(frameworks-de-testing-en-c)=
### Frameworks de Testing en C

Aunque `assert` es útil para pruebas simples, existen frameworks más completos:

#### Ejemplo con estructura propia

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int ejecutadas;
    int exitosas;
    int fallidas;
} EstadisticasTest;

EstadisticasTest stats = {0, 0, 0};

void verificar(bool condicion, const char* descripcion) {
    stats.ejecutadas++;
    if (condicion) {
        stats.exitosas++;
        printf("  ✓ %s\n", descripcion);
    } else {
        stats.fallidas++;
        printf("  ✗ %s\n", descripcion);
    }
}

void test_operaciones_basicas() {
    printf("\nPruebas de operaciones básicas:\n");
    verificar(suma(2, 3) == 5, "suma de positivos");
    verificar(suma(-2, -3) == -5, "suma de negativos");
    verificar(suma(0, 0) == 0, "suma de ceros");
}

void imprimir_reporte() {
    printf("\n==== REPORTE DE PRUEBAS ====\n");
    printf("Ejecutadas: %d\n", stats.ejecutadas);
    printf("Exitosas:   %d\n", stats.exitosas);
    printf("Fallidas:   %d\n", stats.fallidas);
    printf("Tasa:       %.1f%%\n", 
           100.0 * stats.exitosas / stats.ejecutadas);
}

int main() {
    test_operaciones_basicas();
    imprimir_reporte();
    return stats.fallidas > 0 ? 1 : 0;
}
```

(test-driven-development-tdd)=
### Test-Driven Development (TDD)

**TDD** es una metodología donde las pruebas se escriben antes que el código de producción:

1. **Red**: Escribir una prueba que falla
2. **Green**: Escribir el código mínimo para que pase
3. **Refactor**: Mejorar el código manteniendo las pruebas verdes

```{code-block}c
:linenos:
// Paso 1: Escribir la prueba primero
void test_multiplicar() {
    assert(multiplicar(3, 4) == 12);
    assert(multiplicar(0, 5) == 0);
    assert(multiplicar(-2, 3) == -6);
}

// Paso 2: Implementar la función
int multiplicar(int a, int b) {
    return a * b;
}

// Paso 3: Refactorizar si es necesario
```

:::{tip}
TDD no solo ayuda a escribir código correcto, sino que también guía el diseño. Si una función es difícil de probar, probablemente necesita ser rediseñada.
:::

---

(ejercicios-de-autoevaluacion-assert-y-cobertura)=
### Ejercicios de Autoevaluación (assert y Cobertura)

:::{exercise}
:label: ej-test-assert-production
Explicá de forma detallada por qué es un anti-patrón de seguridad crítico escribir `assert(malloc(100) != NULL);` en C y qué consecuencias provoca la definición de la macro `NDEBUG` en producción.
:::

:::{solution} ej-test-assert-production
:class: dropdown
La macro `assert(condición)` es una herramienta de depuración en desarrollo. Cuando el software se compila para producción, es una práctica estándar definir la macro de optimización `#define NDEBUG`, lo que desactiva y elimina por completo todas las líneas de `assert` durante el preprocesamiento del compilador.
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

void test_es_bisiesto_ramas() {
    assert(es_bisiesto(2000) == true);  // Evalúa VERDADERO la rama 1 (divisible por 400)
    assert(es_bisiesto(1900) == false); // Evalúa FALSO la rama 1 y VERDADERO la rama 2 (divisible por 100)
    assert(es_bisiesto(2024) == true);  // Evalúa FALSAS rama 1 y 2, y VERDADERO la rama 3 (divisible por 4)
    assert(es_bisiesto(2023) == false); // Evalúa FALSAS todas las ramas (camino por defecto final)
}
```
:::

:::{exercise}
:label: ej-test-propiedades-conmutativa
Implementá una prueba basada en propiedades en C que valide de manera sistemática que la operación de multiplicación de enteros es asociativa para cualquier par de valores en el intervalo $[-20, 20]$.
:::

:::{solution} ej-test-propiedades-conmutativa
:class: dropdown
```c
#include <assert.h>

void test_propiedad_asociativa_multiplicacion() {
    // Propiedad: (a * b) * c == a * (b * c)
    for (int a = -20; a <= 20; a++) {
        for (int b = -20; b <= 20; b++) {
            for (int c = -20; c <= 20; c++) {
                int resultado1 = (a * b) * c;
                int resultado2 = a * (b * c);
                assert(resultado1 == resultado2);
            }
        }
    }
}
```
:::

---

(contratos)=
## Contratos

Los **contratos** son especificaciones formales que documentan el comportamiento esperado de una función. Establecen un "acuerdo" entre quien implementa la función y quien la usa, definiendo claramente qué se espera antes de llamarla y qué se garantiza después.

(filosofia-de-diseno-por-contrato)=
### Filosofía de Diseño por Contrato

El **Design by Contract** (DbC), popularizado por Bertrand Meyer, se basa en la metáfora de contratos legales: cada parte tiene obligaciones y beneficios. En programación:

- El **cliente** (quien llama la función) debe cumplir las precondiciones
- El **proveedor** (la función) debe cumplir las postcondiciones
- Si el cliente cumple su parte, el proveedor garantiza la suya

Esta filosofía ayuda a:
- Clarificar responsabilidades
- Simplificar debugging (¿quién violó el contrato?)
- Mejorar la documentación
- Reducir código defensivo redundante

(tipos-de-condiciones)=
### Tipos de condiciones

#### Precondición

**Precondiciones** son requisitos que deben cumplirse **antes** de ejecutar la función. Son responsabilidad del código que llama la función.

Ejemplos de precondiciones:
- Parámetros en rangos válidos
- Punteros no nulos
- Archivos abiertos correctamente
- Estado del sistema en condición específica

```{code-block}c
:linenos:
/*
 * Calcula la raíz cuadrada de un número.
 * PRE: x >= 0
 */
double raiz_cuadrada(double x) {
    assert(x >= 0);  // Verificación en desarrollo
    return sqrt(x);
}
```

#### Postcondición

**Postcondiciones** son garantías que la función promete cumplir **al terminar** su ejecución, siempre que se hayan cumplido las precondiciones.

Ejemplos de postcondiciones:
- Valor de retorno en cierto rango
- Estado del sistema modificado correctamente
- Memoria liberada apropiadamente
- Invariantes preservados

```{code-block}c
:linenos:
/*
 * Busca un elemento en un array ordenado.
 * PRE: array != NULL, tamanio > 0, array está ordenado
 * POST: 
 *   - Si se encuentra: retorna índice i tal que array[i] == elemento
 *   - Si no se encuentra: retorna -1
 *   - El array no fue modificado
 */
int busqueda_binaria(int* array, int tamanio, int elemento);
```

#### Invariante

**Invariantes** son condiciones que permanecen **siempre verdaderas** durante la ejecución. Existen varios tipos:

**Invariante de lazo**: condición que es verdadera antes y después de cada iteración.

```{code-block}c
:linenos:
// Calcular suma de elementos
int suma_array(int* array, int n) {
    int suma = 0;
    int i = 0;
    // INVARIANTE: suma contiene la suma de array[0..i-1]
    while (i < n) {
        suma += array[i];
        i++;
        // INVARIANTE se mantiene aquí
    }
    return suma;
}
```

**Invariante de estructura**: propiedad que una estructura de datos mantiene siempre.

```{code-block}c
:linenos:
typedef struct {
    int* datos;
    int tamanio;
    int capacidad;
} Vector;

// INVARIANTE de Vector:
// - 0 <= tamanio <= capacidad
// - Si tamanio > 0, entonces datos != NULL
// - datos apunta a memoria válida para 'capacidad' elementos
```

(ejemplo-completo-de-contrato-en-documentacion)=
### Ejemplo completo de contrato en documentación

```{code-block}c
:linenos:
/*
 * Suma dos números enteros.
 * 
 * @param termino1: número entero entre -128 y 127
 * @param termino2: número entero entre -128 y 127
 * @returns: suma entre ambos, rango -256 a 254
 * 
 * PRE: -128 <= termino1 <= 127
 *      -128 <= termino2 <= 127
 * POST: resultado == termino1 + termino2
 *       -256 <= resultado <= 254
 */
int suma(int termino1, int termino2);
```

(contratos-mas-complejos)=
### Contratos más complejos

Para funciones que manejan recursos o estructuras de datos:

```{code-block}c
:linenos:
/*
 * Agrega un elemento al final de un vector dinámico.
 * 
 * @param vec: puntero a vector válido (no NULL)
 * @param elemento: valor a agregar
 * @returns: true si se agregó exitosamente, false si falló
 * 
 * PRE: vec != NULL
 *      vec->datos != NULL || vec->capacidad == 0
 *      INVARIANTE de Vector se cumple
 * 
 * POST: Si retorna true:
 *         - vec->tamanio aumentó en 1
 *         - vec->datos[vec->tamanio-1] == elemento
 *         - INVARIANTE de Vector se mantiene
 *       Si retorna false:
 *         - vec no fue modificado
 *         - Falló la asignación de memoria
 */
bool vector_agregar(Vector* vec, int elemento);
```

(verificacion-de-contratos-en-codigo)=
### Verificación de Contratos en Código

Los contratos pueden verificarse en desarrollo usando `assert`:

```{code-block}c
:linenos:
int suma_positivos(int a, int b) {
    // Verificar precondiciones
    assert(a > 0);
    assert(b > 0);
    
    int resultado = a + b;
    
    // Verificar postcondiciones
    assert(resultado > a);
    assert(resultado > b);
    
    return resultado;
}
```

Para validaciones que deben ejecutarse en producción:

```{code-block}c
:linenos:
typedef enum {
    OK,
    ERROR_PARAMETRO_INVALIDO,
    ERROR_FUERA_DE_RANGO
} CodigoError;

CodigoError dividir(int dividendo, int divisor, double* resultado) {
    // Validación explícita de precondiciones
    if (resultado == NULL) {
        return ERROR_PARAMETRO_INVALIDO;
    }
    if (divisor == 0) {
        return ERROR_FUERA_DE_RANGO;
    }
    
    // Ejecutar operación
    *resultado = (double)dividendo / divisor;
    
    // Postcondición implícita: resultado contiene valor válido
    return OK;
}
```

(contratos-y-testing)=
### Contratos y Testing

Los contratos guían directamente el diseño de pruebas:

```{code-block}c
:linenos:
// Función con contrato
/*
 * PRE: array != NULL, n > 0
 * POST: retorna el máximo elemento en array[0..n-1]
 */
int encontrar_maximo(int* array, int n);

// Tests derivados del contrato
void test_encontrar_maximo() {
    // Caso normal
    int arr1[] = {3, 7, 2, 9, 1};
    assert(encontrar_maximo(arr1, 5) == 9);
    
    // Caso con un solo elemento
    int arr2[] = {42};
    assert(encontrar_maximo(arr2, 1) == 42);
    
    // Caso con elementos negativos
    int arr3[] = {-5, -2, -8, -1};
    assert(encontrar_maximo(arr3, 4) == -1);
    
    // Caso con elementos iguales
    int arr4[] = {7, 7, 7, 7};
    assert(encontrar_maximo(arr4, 4) == 7);
}

// Tests de violación de precondiciones (en desarrollo)
void test_encontrar_maximo_precondiciones() {
    int arr[] = {1, 2, 3};
    
    // Estas llamadas violarían precondiciones
    // En desarrollo con assert, terminarían el programa
    // En producción, podrían causar comportamiento indefinido
    
    // encontrar_maximo(NULL, 5);  // ✗ Viola: array != NULL
    // encontrar_maximo(arr, 0);   // ✗ Viola: n > 0
    // encontrar_maximo(arr, -1);  // ✗ Viola: n > 0
}
```

(contratos-en-proyectos-reales)=
### Contratos en Proyectos Reales

En proyectos grandes, los contratos ayudan a modularizar:

```{code-block}c
:linenos:
// módulo: lista_enlazada.h

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int longitud;
} Lista;

/*
 * Crea una lista vacía.
 * 
 * PRE: ninguna
 * POST: retorna lista con cabeza == NULL, longitud == 0
 *       INVARIANTE de Lista se establece
 */
Lista* lista_crear();

/*
 * Inserta elemento al inicio de la lista.
 * 
 * PRE: lista != NULL
 *      INVARIANTE de Lista se cumple
 * POST: lista->longitud aumentó en 1
 *       nuevo nodo con 'dato' es la nueva cabeza
 *       INVARIANTE de Lista se mantiene
 */
void lista_insertar_inicio(Lista* lista, int dato);

/*
 * Destruye la lista liberando toda la memoria.
 * 
 * PRE: lista != NULL
 * POST: toda la memoria de la lista fue liberada
 *       lista queda inválida (debe asignarse NULL en el código cliente)
 */
void lista_destruir(Lista* lista);

// INVARIANTE de Lista:
// 1. longitud >= 0
// 2. Si longitud == 0, entonces cabeza == NULL
// 3. Si longitud > 0, entonces cabeza != NULL
// 4. El número de nodos alcanzables desde cabeza == longitud
```

:::{note}
Los contratos son especialmente valiosos en interfaces públicas de bibliotecas, donde múltiples desarrolladores usarán las funciones sin conocer su implementación interna.
:::

---

(ejercicios-de-autoevaluacion-diseno-por-contrato)=
### Ejercicios de Autoevaluación (Diseño por Contrato)

:::{exercise}
:label: ej-contrato-raiz-cuadrada
Documentá de forma formal el contrato (precondiciones y postcondiciones) de una función llamada `calcular_logaritmo(double x)` y escribí su implementación en C utilizando `assert` para validar las restricciones del cliente.
:::

:::{solution} ej-contrato-raiz-cuadrada
:class: dropdown
```c
#include <assert.h>
#include <math.h>

/*
 * Calcula el logaritmo natural de un número real.
 * 
 * @param x: Número real de entrada
 * @returns: Logaritmo natural de x
 * 
 * PRE: x > 0.0 (El logaritmo solo está definido para reales positivos)
 * POST: Si e = 2.71828..., entonces e^(resultado) es aproximadamente x
 */
double calcular_logaritmo(double x) {
    // Validación del contrato del cliente
    assert(x > 0.0);
    return log(x);
}
```
:::

:::{exercise}
:label: ej-contrato-invariante-lazo
Dada una función que realiza la búsqueda secuencial de un elemento en un arreglo, identificá y documentá el invariante de lazo (*loop invariant*) del lazo de búsqueda.
:::

:::{solution} ej-contrato-invariante-lazo
:class: dropdown
```c
int buscar(const int *arr, size_t n, int elem) {
    size_t i = 0;
    
    // INVARIANTE DE LAZO: El elemento 'elem' no se encuentra en el subarreglo arr[0 .. i-1]
    while (i < n) {
        if (arr[i] == elem) {
            return (int)i;
        }
        i++;
        // El invariante se mantiene: tras avanzar i, sabemos que elem no está en arr[0 .. i-1]
    }
    return -1;
}
```
:::

:::{exercise}
:label: ej-contrato-invariante-structure
Escribí las invariantes de estructura de datos para un TAD de tipo `Cola` implementado mediante una lista enlazada simple que registre referencias al `nodo_inicio`, `nodo_fin` y la `cantidad` de elementos.
:::

:::{solution} ej-contrato-invariante-structure
:class: dropdown
Las invariantes de estructura para el TAD `Cola` son:
1. `cantidad >= 0`.
2. Si `cantidad == 0`, entonces `nodo_inicio == NULL` y `nodo_fin == NULL`.
3. Si `cantidad == 1`, entonces `nodo_inicio == nodo_fin` y `nodo_inicio != NULL`.
4. Si `cantidad > 1`, entonces `nodo_inicio != NULL`, `nodo_fin != NULL` y `nodo_inicio != nodo_fin`.
5. El número total de nodos alcanzables recorriendo el puntero `siguiente` desde `nodo_inicio` hasta llegar a `NULL` es exactamente igual a `cantidad`.
:::

---

(valores-especiales-y-documentacion)=
## Valores especiales y documentación

Una práctica común en C es usar **valores especiales** para indicar condiciones de error o estados particulares. Esta práctica requiere documentación clara para evitar malentendidos.

(valores-de-retorno-especiales)=
### Valores de Retorno Especiales

#### Códigos de Error Numéricos

```{code-block}c
:linenos:
/*
 * Busca un elemento en un array.
 * 
 * @returns: índice del elemento (0..n-1) si se encuentra
 *           -1 si no se encuentra
 *           -2 si los parámetros son inválidos
 * 
 * PRE: Si array != NULL, entonces n >= 0
 * POST: Si retorna i >= 0, entonces array[i] == elemento
 *       Si retorna -1, el elemento no está en array
 *       Si retorna -2, array == NULL o n < 0
 */
int buscar(int* array, int n, int elemento) {
    if (array == NULL || n < 0) {
        return -2;
    }
    
    for (int i = 0; i < n; i++) {
        if (array[i] == elemento) {
            return i;
        }
    }
    
    return -1;
}
```

#### Punteros NULL como Indicadores

```{code-block}c
:linenos:
/*
 * Crea un nodo con el dato especificado.
 * 
 * @returns: puntero al nuevo nodo, o NULL si falla la asignación
 * 
 * PRE: ninguna
 * POST: Si retorna != NULL:
 *         - el nodo tiene nodo->dato == dato
 *         - nodo->siguiente == NULL
 *       Si retorna NULL:
 *         - falló malloc
 */
Nodo* nodo_crear(int dato) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return NULL;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Uso correcto: verificar retorno
Nodo* nodo = nodo_crear(42);
if (nodo == NULL) {
    fprintf(stderr, "Error: no se pudo crear nodo\n");
    return ERROR_MEMORIA;
}
```

#### Caracteres Especiales

```{code-block}c
:linenos:
/*
 * Lee el siguiente carácter del archivo.
 * 
 * @returns: carácter leído (0-255), o
 *           EOF (-1) si se alcanzó fin de archivo o hubo error
 * 
 * PRE: archivo != NULL, archivo está abierto para lectura
 * POST: Si retorna != EOF, es un carácter válido
 *       Si retorna EOF, verificar con feof() y ferror()
 */
int leer_caracter(FILE* archivo);
```

(enumeraciones-para-mayor-claridad)=
### Enumeraciones para Mayor Claridad

Las enumeraciones hacen el código más expresivo y mantenible:

```{code-block}c
:linenos:
typedef enum {
    EXITO = 0,
    ERROR_ARCHIVO_NO_EXISTE = 1,
    ERROR_PERMISO_DENEGADO = 2,
    ERROR_MEMORIA_INSUFICIENTE = 3,
    ERROR_FORMATO_INVALIDO = 4
} CodigoResultado;

/*
 * Carga datos desde un archivo.
 * 
 * @returns: EXITO si la operación fue exitosa
 *           Código de error específico si falló
 * 
 * PRE: ruta != NULL
 * POST: Si retorna EXITO, *datos contiene la información cargada
 *       Si retorna error, *datos no fue modificado
 */
CodigoResultado cargar_desde_archivo(const char* ruta, Datos* datos);

// Uso
Datos datos;
CodigoResultado resultado = cargar_desde_archivo("config.txt", &datos);

if (resultado != EXITO) {
    switch (resultado) {
        case ERROR_ARCHIVO_NO_EXISTE:
            fprintf(stderr, "El archivo no existe\n");
            break;
        case ERROR_PERMISO_DENEGADO:
            fprintf(stderr, "Permisos insuficientes\n");
            break;
        case ERROR_MEMORIA_INSUFICIENTE:
            fprintf(stderr, "Memoria insuficiente\n");
            break;
        default:
            fprintf(stderr, "Error desconocido\n");
    }
    return 1;
}
```

(valores-centinela)=
### Valores Centinela

Los **valores centinela** marcan el final de una secuencia:

```{code-block}c
:linenos:
// Strings en C: centinela '\0'
char nombre[] = "Hola";  // Internamente: {'H','o','l','a','\0'}

// Array terminado en centinela
int numeros[] = {1, 2, 3, 4, 5, -1};  // -1 marca el final

/*
 * Suma elementos hasta encontrar el centinela.
 * 
 * PRE: array contiene -1 como último elemento
 * POST: retorna suma de todos los elementos antes del -1
 */
int sumar_hasta_centinela(int* array) {
    int suma = 0;
    int i = 0;
    
    while (array[i] != -1) {
        suma += array[i];
        i++;
    }
    
    return suma;
}
```

(documentacion-de-invariantes-internas)=
### Documentación de Invariantes Internas

Las invariantes internas ayudan a razonar sobre el código:

```{code-block}c
:linenos:
typedef struct {
    int* buffer;
    int capacidad;
    int inicio;
    int final;
    int cantidad;
} ColaCircular;

/*
 * INVARIANTES de ColaCircular:
 * 
 * 1. 0 <= cantidad <= capacidad
 * 2. 0 <= inicio < capacidad
 * 3. 0 <= final < capacidad
 * 4. Si cantidad == 0, la cola está vacía
 * 5. Si cantidad == capacidad, la cola está llena
 * 6. Los elementos válidos están en las posiciones
 *    (inicio + i) % capacidad para i en [0, cantidad)
 */

/*
 * Agrega un elemento a la cola.
 * 
 * PRE: cola != NULL
 *      INVARIANTES se cumplen
 *      cantidad < capacidad (hay espacio)
 * POST: elemento agregado en posición 'final'
 *       cantidad aumentó en 1
 *       final avanzó (con wrap-around)
 *       INVARIANTES se mantienen
 */
void cola_encolar(ColaCircular* cola, int elemento) {
    assert(cola != NULL);
    assert(cola->cantidad < cola->capacidad);
    
    // Preservar invariantes
    cola->buffer[cola->final] = elemento;
    cola->final = (cola->final + 1) % cola->capacidad;
    cola->cantidad++;
    
    // Verificar que las invariantes siguen cumpliéndose
    assert(cola->cantidad <= cola->capacidad);
    assert(cola->inicio >= 0 && cola->inicio < cola->capacidad);
    assert(cola->final >= 0 && cola->final < cola->capacidad);
}
```

(documentacion-de-rangos-validos)=
### Documentación de Rangos Válidos

Especificar claramente los rangos válidos previene errores:

```{code-block}c
:linenos:
/*
 * Establece el brillo de un LED.
 * 
 * @param brillo: intensidad entre 0 (apagado) y 255 (máximo)
 * 
 * PRE: 0 <= brillo <= 255
 * POST: LED configurado con el brillo especificado
 * 
 * NOTA: Valores fuera de rango se ajustan automáticamente:
 *       brillo < 0 se trata como 0
 *       brillo > 255 se trata como 255
 */
void led_set_brillo(int brillo) {
    if (brillo < 0) brillo = 0;
    if (brillo > 255) brillo = 255;
    
    // Configurar hardware
    PWM_DUTY = brillo;
}

/*
 * Alternativa: sin ajuste automático
 * 
 * @returns: true si se configuró exitosamente
 *           false si brillo está fuera de rango
 * 
 * PRE: ninguna
 * POST: Si retorna true, LED configurado con brillo especificado
 *       Si retorna false, LED no fue modificado
 */
bool led_set_brillo_estricto(int brillo) {
    if (brillo < 0 || brillo > 255) {
        return false;
    }
    
    PWM_DUTY = brillo;
    return true;
}
```

(testing-de-valores-especiales)=
### Testing de Valores Especiales

Los valores especiales deben probarse explícitamente:

```{code-block}c
:linenos:
void test_buscar_valores_especiales() {
    int array[] = {10, 20, 30, 40, 50};
    
    // Casos de éxito
    assert(buscar(array, 5, 30) == 2);
    
    // Caso de elemento no encontrado
    assert(buscar(array, 5, 100) == -1);
    
    // Casos de parámetros inválidos
    assert(buscar(NULL, 5, 30) == -2);
    assert(buscar(array, -1, 30) == -2);
    
    // Casos límite
    assert(buscar(array, 0, 10) == -1);  // Array "vacío"
    assert(buscar(array, 1, 10) == 0);   // Un solo elemento
}

void test_valores_centinela() {
    int numeros[] = {5, 10, 15, -1};
    assert(sumar_hasta_centinela(numeros) == 30);
    
    int vacio[] = {-1};
    assert(sumar_hasta_centinela(vacio) == 0);
}
```

---

(mejores-practicas-de-testing)=
## Mejores Prácticas de Testing

(1-tests-independientes)=
### 1. Tests Independientes

Cada test debe ser independiente de los demás:

```{code-block}c
:linenos:
// ✗ MAL: tests dependientes
int contador_global = 0;

void test_incremento_1() {
    contador_global++;
    assert(contador_global == 1);
}

void test_incremento_2() {
    contador_global++;
    assert(contador_global == 2);  // ¡Depende del test anterior!
}

// ✓ BIEN: tests independientes
void test_incremento_desde_cero() {
    int contador = 0;
    contador++;
    assert(contador == 1);
}

void test_incremento_desde_diez() {
    int contador = 10;
    contador++;
    assert(contador == 11);
}
```

(2-nombres-descriptivos)=
### 2. Nombres Descriptivos

Los nombres deben describir qué se prueba y bajo qué condiciones:

```{code-block}c
:linenos:
// ✗ MAL: nombres ambiguos
void test1() { ... }
void test_suma() { ... }

// ✓ BIEN: nombres descriptivos
void test_suma_dos_numeros_positivos() { ... }
void test_suma_con_overflow() { ... }
void test_suma_numeros_negativos() { ... }
```

(3-un-concepto-por-test)=
### 3. Un Concepto por Test

Cada test debe verificar un solo aspecto:

```{code-block}c
:linenos:
// ✗ MAL: test sobrecargado
void test_lista() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    lista_insertar(lista, 2);
    assert(lista_tamanio(lista) == 2);
    assert(lista_esta_vacia(lista) == false);
    lista_eliminar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    lista_destruir(lista);
}

// ✓ BIEN: tests específicos
void test_lista_insertar_aumenta_tamanio() {
    Lista* lista = lista_crear();
    assert(lista_tamanio(lista) == 0);
    
    lista_insertar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    
    lista_insertar(lista, 2);
    assert(lista_tamanio(lista) == 2);
    
    lista_destruir(lista);
}

void test_lista_con_elementos_no_esta_vacia() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    
    assert(lista_esta_vacia(lista) == false);
    
    lista_destruir(lista);
}

void test_lista_eliminar_reduce_tamanio() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    lista_insertar(lista, 2);
    
    lista_eliminar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    
    lista_destruir(lista);
}
```

(4-evitar-logica-compleja-en-tests)=
### 4. Evitar Lógica Compleja en Tests

Los tests deben ser simples y obvios:

```{code-block}c
:linenos:
// ✗ MAL: lógica en el test
void test_suma_complejo() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            assert(suma(i, i) == i * 2);
        } else {
            assert(suma(i, i + 1) == i * 2 + 1);
        }
    }
}

// ✓ BIEN: casos explícitos
void test_suma_numeros_pares() {
    assert(suma(0, 0) == 0);
    assert(suma(2, 2) == 4);
    assert(suma(4, 4) == 8);
}

void test_suma_numeros_impares() {
    assert(suma(1, 2) == 3);
    assert(suma(3, 4) == 7);
    assert(suma(5, 6) == 11);
}
```

(5-usar-funciones-auxiliares-para-setup)=
### 5. Usar Funciones Auxiliares para Setup

Cuando varios tests necesitan la misma preparación:

```{code-block}c
:linenos:
// Función auxiliar para crear configuración común
Lista* crear_lista_con_elementos(int n) {
    Lista* lista = lista_crear();
    for (int i = 0; i < n; i++) {
        lista_insertar(lista, i * 10);
    }
    return lista;
}

void test_lista_obtener_primero() {
    Lista* lista = crear_lista_con_elementos(5);
    assert(lista_obtener(lista, 0) == 0);
    lista_destruir(lista);
}

void test_lista_obtener_ultimo() {
    Lista* lista = crear_lista_con_elementos(5);
    assert(lista_obtener(lista, 4) == 40);
    lista_destruir(lista);
}
```

---

(integracion-de-testing-en-el-flujo-de-trabajo)=
## Integración de Testing en el Flujo de Trabajo

(makefile-con-tests)=
### Makefile con Tests

```makefile
(compilacion-del-proyecto)=
# Compilación del proyecto
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = src/calculadora.c src/utilidades.c
TESTS = tests/test_calculadora.c tests/test_utilidades.c

(targets-principales)=
# Targets principales
all: programa

programa: src/main.c $(SRC)
	$(CC) $(CFLAGS) -o programa src/main.c $(SRC)

(target-para-tests)=
# Target para tests
test: test_calculadora test_utilidades
	@echo "=== Ejecutando todas las pruebas ==="
	./test_calculadora
	./test_utilidades
	@echo "=== Todas las pruebas completadas ==="

test_calculadora: tests/test_calculadora.c src/calculadora.c
	$(CC) $(CFLAGS) -o test_calculadora tests/test_calculadora.c src/calculadora.c

test_utilidades: tests/test_utilidades.c src/utilidades.c
	$(CC) $(CFLAGS) -o test_utilidades tests/test_utilidades.c src/utilidades.c

(limpieza)=
# Limpieza
clean:
	rm -f programa test_calculadora test_utilidades *.o

(test-programa)=
# Test + programa
build-all: programa test

.PHONY: all test clean build-all
```

(flujo-de-desarrollo-recomendado)=
### Flujo de Desarrollo Recomendado

1. **Escribir/modificar código**
2. **Ejecutar tests**: `make test`
3. **Si fallan**: corregir y volver al paso 2
4. **Si pasan**: compilar programa completo: `make all`
5. **Commit**: guardar cambios con git

```bash
(flujo-tipico)=
# Flujo típico
$ make test           # Verificar que no rompimos nada
$ # ... hacer cambios ...
$ make test           # Probar cambios
$ make all            # Compilar programa
$ git add .
$ git commit -m "Implementada función X con tests"
```

(ejercicios-de-autoevaluacion-valores-especiales-y-modularizacion)=
### Ejercicios de Autoevaluación (Valores Especiales y Modularización)

:::{exercise}
:label: ej-test-valor-centinela-string
Implementá una función `longitud_string` utilizando el centinela `'\0'` para recorrerla y escribí un test unitario que verifique su comportamiento en el caso límite de una cadena vacía.
:::

:::{solution} ej-test-valor-centinela-string
:class: dropdown
```c
#include <assert.h>
#include <stddef.h>

size_t longitud_string(const char *cadena) {
    if (cadena == NULL) return 0;
    
    size_t longitud = 0;
    // Recorrido hasta encontrar el valor centinela '\0'
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

void test_longitud_cadena_vacia() {
    const char *vacio = "";
    assert(longitud_string(vacio) == 0); // Caso límite centinela inmediato
}
```
:::

:::{exercise}
:label: ej-test-independencia
Explicá por qué es de vital importancia que las pruebas unitarias sean independientes entre sí y qué problemas lógicos ocurren al compartir un estado global mutable en las pruebas.
:::

:::{solution} ej-test-independencia
:class: dropdown
La independencia de las pruebas garantiza que el resultado de un test no se vea afectado por la ejecución o el éxito/fallo de otros tests previos.
Si los tests comparten un estado global mutable (por ejemplo, una variable global contador), el test B asumirá que el estado está en un punto inicial, pero si el test A falló o modificó dicho estado global, el test B fallará por causas ajenas a su código. Adicionalmente, impide la ejecución de pruebas de forma aleatoria o en paralelo, dificultando la localización de bugs.
:::

:::{exercise}
:label: ej-test-makefile-integration
Escribí una regla de Makefile simplificada llamada `test` que compile una suite de pruebas `tests/run_tests.c` junto al módulo `src/operaciones.c` and ejecute el binario de forma automática, deteniendo la compilación si las pruebas fallan.
:::

:::{solution} ej-test-makefile-integration
:class: dropdown
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

test: tests/run_tests.c src/operaciones.c
	$(CC) $(CFLAGS) -o run_tests tests/run_tests.c src/operaciones.c
	@echo "Ejecutando pruebas unitarias..."
	./run_tests
	@echo "Pruebas pasadas exitosamente."
```
*(Nota: En los Makefiles, si el ejecutable `./run_tests` retorna un código de salida distinto de 0 debido a un fallo en un assert, el comando Makefile se interrumpirá e indicará que el target falló).*
:::

---

(conclusion)=
## Conclusión

El testing y los contratos son herramientas fundamentales del desarrollo de software profesional. Estos conceptos no son "extras opcionales", sino prácticas estándar que todo programador debe dominar.

(conceptos-clave)=
### Conceptos Clave

- **Testing** valida que el código funciona correctamente bajo diversas condiciones
- **Contratos** documentan formalmente las expectativas de cada función
- **Precondiciones** definen qué debe ser cierto antes de llamar una función
- **Postcondiciones** garantizan qué será cierto después de la ejecución
- **Invariantes** son propiedades que siempre se mantienen
- **Valores especiales** requieren documentación clara y testing explícito

(beneficios-de-estas-practicas)=
### Beneficios de Estas Prácticas

1. **Código más robusto**: Los errores se detectan temprano
2. **Mejor diseño**: Pensar en tests mejora la estructura del código
3. **Documentación viva**: Los contratos y tests documentan el uso correcto
4. **Refactorización segura**: Los tests permiten cambiar código con confianza
5. **Debugging más fácil**: Las fallas están localizadas y son reproducibles
6. **Colaboración efectiva**: Los contratos clarifican responsabilidades

:::{important}
En la industria del software, el testing no es negociable. Proyectos sin tests son considerados "código legacy" incluso si fueron escritos ayer. Las empresas esperan que los desarrolladores sepan escribir y mantener tests como parte natural de su trabajo.
:::

(aplicacion-en-trabajos-practicos)=
### Aplicación en Trabajos Prácticos

Estos conceptos se aplicarán directamente en los trabajos prácticos del curso:

- **TP3 y siguientes**: se esperan funciones con contratos documentados
- **Evaluación**: incluye la calidad y completitud de las pruebas
- **Código profesional**: seguir estas prácticas es parte de la nota conceptual

:::{tip}
No esperes a que te pidan tests. Escríbelos desde el principio. Es más fácil mantener tests existentes que agregar testing a código ya escrito. Además, los tests te ayudarán a ti mismo durante el desarrollo.
:::

---

(recursos-adicionales)=
## Recursos Adicionales

Para profundizar en testing y contratos:

- **Frameworks de testing en C**: Check, Unity, CUnit, MinUnit
- **Herramientas de análisis**: Valgrind (memoria), GDB (debugging), gcov (cobertura)
- **Metodologías**: TDD (Test-Driven Development), BDD (Behavior-Driven Development)
- **Verificación formal**: Para sistemas críticos, existen herramientas como Frama-C que pueden verificar formalmente contratos en C

(proximos-pasos)=
### Próximos Pasos

1. Practicar escribiendo tests para funciones simples
2. Documentar contratos en las funciones que escribas
3. Ejecutar tests regularmente durante el desarrollo
4. Analizar la cobertura de tus tests
5. Refactorizar con confianza apoyándote en los tests
