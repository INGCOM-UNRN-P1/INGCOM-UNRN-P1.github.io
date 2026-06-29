---
title: Índice de Referencia
short_title: Referencias
subtitle: Compendio de guías, algoritmos y técnicas de refactorización para C
---

# Índice de Referencia y Material Complementario

En esta sección se consolidan las guías de consulta rápida, compendios de algoritmos de la cátedra y guías de refactorización para escribir código C limpio, robusto y conforme a los estándares.

## Guías y Manuales de Referencia

*   **[](A_stdlib.md)**: Manual de referencia de la Biblioteca Estándar de C (Standard Library) organizado por archivos de cabecera (*headers*).
*   **[](B_ordenamiento.md)**: Compendio detallado de algoritmos de búsqueda (secuencial, binaria) y ordenamiento (burbuja, selección, inserción, QuickSort, MergeSort, HeapSort) junto con su análisis de complejidad temporal y espacial.
*   **[](guide-makefiles.md)**: Guía práctica y recetas de automatización de compilación de proyectos modulares utilizando `make` y archivos `Makefile`.
*   **[](guide-printf.md)**: Manual de uso y especificadores de formato para las funciones de entrada y salida estándar con formato (`printf` y `scanf`).

## Guías de Refactorización de Código

Por si llegas acá de forma directa, una refactorización es una forma de cambiar el código, que no altera su funcionamiento, pero mejora alguno de sus aspectos, como la legibilidad.

*   **[](refactorizaciones/ref-dry.md)**: El principio *Don't Repeat Yourself* (DRY), cómo evitar duplicación de código e integrar componentes reutilizables.
*   **[](refactorizaciones/ref-extract-function.md)**: Técnicas y criterios de diseño para extraer funciones y reducir el tamaño y complejidad de rutinas individuales.
*   **[](refactorizaciones/ref-magic-numbers.md)**: Identificación y reemplazo de números mágicos por constantes descriptivas (`#define` y enumerados).
*   **[](refactorizaciones/ref-naming.md)**: Buenas prácticas en la nomenclatura de variables, funciones, alias de tipos y estructuras para mejorar la legibilidad.
*   **[](refactorizaciones/ref-simplify-conditionals.md)**: Criterios y álgebra de Boole aplicada para simplificar expresiones condicionales anidadas o complejas.
*   **[](refactorizaciones/ref-simular.md)**: Simulación del pasaje de parámetros por referencia en C utilizando direcciones de memoria física y punteros.
*   **[](refactorizaciones/ref-unico-retorno.md)**: Criterios pedagógicos del uso de múltiples retornos frente al retorno único, y el patrón de retorno anticipado (*early return*).
*   **[](refactorizaciones/ref-variables.md)**: Gestión correcta del ciclo de vida, inicialización y ámbito de variables para prevenir estados inconsistentes.

---

## Sugerencias de Nuevas Referencias para Incorporar

Para enriquecer el material didáctico de la cátedra, se propone la inclusión de los siguientes documentos de referencia en futuras revisiones:

1.  **Guía Práctica de Depuración con GDB**:
    *   *Propósito*: Instruir a los alumnos en el uso de GNU Debugger (GDB) para inspeccionar la pila de llamadas (*stack frames*), colocar puntos de interrupción (*breakpoints*), realizar ejecuciones paso a paso y evaluar variables en tiempo de ejecución.
2.  **Diagnóstico de Memoria Dinámica con Valgrind y AddressSanitizer**:
    *   *Propósito*: Manual de lectura e interpretación de reportes de fugas de memoria (*memory leaks*), accesos inválidos (lecturas fuera de rango en heap/stack) y uso de memoria liberada.
3.  **El Preprocesador de C en Profundidad**:
    *   *Propósito*: Documentar de forma avanzada las directivas de inclusión condicional (`#ifdef`, `#ifndef`), el uso correcto de macros parametrizadas con paréntesis defensivos y la prevención de colisiones de nombres.
4.  **Guía de Estilo y Convenciones de la Cátedra (Reglas de Codificación)**:
    *   *Propósito*: Un compendio que resuma y justifique con ejemplos las reglas de estilo obligatorias del curso (por ejemplo, el sufijo `_t` en `typedef`, el asterisco pegado a la variable en punteros y la prohibición absoluta de variables globales mutables).
5.  **Entrada y Salida en Binario**:
    *   *Propósito*: Manual complementario de manipulación de archivos binarios utilizando `fread`, `fwrite`, `fseek` y `ftell`, detallando el impacto físico del alineamiento de estructuras (*padding*) al persistir datos directo de la memoria al disco.
