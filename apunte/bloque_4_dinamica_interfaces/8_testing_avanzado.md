---
title: Testing Avanzado y Automatización
short_title: 'Testing Avanzado'
subtitle: 'Estructuras de pruebas, frameworks y testing basado en propiedades en C'
---

(capitulo-testing-avanzado)=
# Testing Avanzado y Automatización

## Introducción

A medida que el tamaño y complejidad de los proyectos de software se incrementa (como al diseñar Tipos Abstractos de Datos dinámicos), las aserciones básicas aisladas en el código fuente resultan insuficientes. Es imperativo estructurar suites de prueba modulares y automatizar su compilación y ejecución.

## Desarrollo

### Testing Avanzado y Organización de Pruebas

Un proyecto de calidad industrial debe separar físicamente el código de producción del código de pruebas unitarias. Esto mantiene limpia la entrega del ejecutable final y permite compilar los módulos de testing únicamente cuando sea necesario.

#### Estructura de Directorios Estándar

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

#### Automatización de Compilación en el Makefile

El archivo `Makefile` debe definir un objetivo específico (típicamente `test` o `check`) que compile los archivos de prueba vinculándolos con los objetos de producción, y ejecute el binario resultante:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

## Objetivos principales
all: programa

programa: src/main.o src/calculadora.o
	$(CC) $(CFLAGS) -o programa src/main.o src/calculadora.o

## Objetivo de Pruebas Unitarias
test: tests/run_tests.o src/calculadora.o
	$(CC) $(CFLAGS) -o run_tests tests/run_tests.o src/calculadora.o
	./run_tests

clean:
	rm -f src/*.o tests/*.o programa run_tests
```

### Testing Basado en Propiedades y TDD

#### Testing Basado en Propiedades (Property-Based Testing)

En lugar de verificar valores de entrada específicos e individuales, el **testing basado en propiedades** valida que se cumplan axiomas y teoremas matemáticos generales de la función para cualquier entrada dentro de un rango determinado.

```c
#include <assert.h>

void test_suma_conmutativa(void) {
    // Axioma: a + b == b + a
    for (int i = -50; i <= 50; i++) {
        for (int j = -50; j <= 50; j++) {
            assert(suma(i, j) == suma(j, i));
        }
    }
}

void test_suma_elemento_neutro(void) {
    // Axioma: x + 0 == x
    for (int i = -100; i <= 100; i++) {
        assert(suma(i, 0) == i);
    }
}
```

#### Test-Driven Development (TDD)

El **TDD** es una metodología de diseño de software donde la prueba unitaria se escribe antes que el código de producción:

1.  **Red (Rojo):** Escribir una prueba que falle (ya que la función aún no está implementada).
2.  **Green (Verde):** Escribir la cantidad mínima de código de producción para que la prueba pase.
3.  **Refactor (Refactorizar):** Limpiar y optimizar el código escrito garantizando que todas las pruebas sigan pasando (en verde).

### Estructuración de Frameworks de Testing Personalizados

En proyectos más complejos, es útil construir un arnés de pruebas personalizado para capturar estadísticas detalladas de éxito y fallos sin abortar inmediatamente el binario completo ante el primer error.

```c
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int ejecutadas;
    int exitosas;
    int fallidas;
} stats_t;

static stats_t stats = {0, 0, 0};

void verificar(bool condicion, const char* descripcion) {
    stats.ejecutadas++;
    if (condicion) {
        stats.exitosas++;
        printf("  ✓ [OK] %s\n", descripcion);
    } else {
        stats.fallidas++;
        printf("  ✗ [FAIL] %s\n", descripcion);
    }
}

// Ejemplo de suite
void suite_aritmetica(void) {
    printf("\nEjecutando Suite Aritmética:\n");
    verificar(suma(2, 2) == 4, "Suma de enteros positivos");
    verificar(resta(5, 10) == -5, "Resta con resultado negativo");
}

int main(void) {
    suite_aritmetica();
    
    printf("\n==== Reporte Final ====\n");
    printf("Pruebas ejecutadas: %d\n", stats.ejecutadas);
    printf("Exitosas:          %d\n", stats.exitosas);
    printf("Fallidas:          %d\n", stats.fallidas);
    
    return stats.fallidas > 0 ? 1 : 0;
}
```

## Ejercicios de Autoevaluación

:::{exercise}
:label: ej-test-unitario-vs-integracion
Explicá la diferencia conceptual que existe entre una prueba unitaria (*unit test*) y una prueba de integración, y fundamentá por qué es crucial el aislamiento en las pruebas unitarias.
:::

:::{solution} ej-test-unitario-vs-integracion
:class: dropdown
*   **Prueba Unitaria:** Verifica la corrección de un único componente de software (normalmente una función individual) de forma completamente aislada de cualquier otro módulo o recurso externo (disco, red, base de datos).
*   **Prueba de Integración:** Verifica la correcta interacción y comunicación entre dos o más módulos integrados del sistema.

El aislamiento en las pruebas unitarias es crucial porque asegura que si la prueba falla, la causa raíz del error se encuentra exclusivamente en la unidad bajo prueba. Si no existiera aislamiento, un fallo en una biblioteca de red externa podría hacer fallar el test unitario de un algoritmo de ordenamiento, haciendo que el diagnóstico del error sea complejo y confuso.
:::

:::{exercise}
:label: ej-test-propiedades-conmutativa
Implementá una prueba basada en propiedades en C que valide de manera sistemática que la operación de multiplicación de enteros es asociativa para cualquier combinación de tres valores en el intervalo $[-20, 20]$.
:::

:::{solution} ej-test-propiedades-conmutativa
:class: dropdown
```c
#include <assert.h>

void test_propiedad_asociativa_multiplicacion(void) {
    // Propiedad asociativa: (a * b) * c == a * (b * c)
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

## Glosario

- **Pruebas Unitarias (Unit Testing)**: Pruebas que validan el comportamiento de componentes individuales.
- **Mock**: Objeto simulado para imitar el comportamiento de componentes reales en pruebas.
- **Assert (Aseveración)**: Expresión lógica utilizada en pruebas para comprobar que se cumple una condición.

## Síntesis y Resumen

En este apunte se han presentado los conceptos fundamentales sobre estructuración de tests, testing basado en propiedades y frameworks personalizados en C, haciendo hincapié en la importancia de mantener las pruebas aisladas y automatizadas.

## Referencias y Lecturas Complementarias

No se especifican lecturas complementarias para este tema.
