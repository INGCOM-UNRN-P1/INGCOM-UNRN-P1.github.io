---
title: Repositorio de enunciados
short_title: Ejercicios
---

# Repositorio Integral de Ejercicios de Programación 1

Este repositorio constituye la base pedagógica práctica de la asignatura **Programación 1** (UNRN). Su diseño implementa un modelo de **aprendizaje andamiado (*scaffolded learning*)** y progresión gradual según la Taxonomía de Bloom Revisada, guiando al estudiante desde la sintaxis básica hasta la ingeniería de software y tipos abstractos en C11.

## Requisitos Previos y Entorno de Ejecución
- **Compilador C:** GCC (v9+) o Clang configurado en estándar estricto **ISO C11** (`-std=c11 -Wall -Wextra -Werror -pedantic`).
- **Sistema y Dependencias:** Entorno POSIX (Linux/macOS), utilidades `make`, terminal Bash y Node.js (v18+) para verificación automática.
- **Herramientas de Análisis:** Valgrind y LLVM AddressSanitizer (`-fsanitize=address,undefined`) para comprobación rigurosa de memoria.
- **Conocimientos Previos:** Aritmética elemental, álgebra booleana y manejo básico de la línea de comandos.

## Enfoque Metodológico Formativo y Casos Límite
Cada ejercicio articula cuatro fases de dominio cognitivo:
1. **Contratos Formales:** Precondiciones, postcondiciones e invariantes explícitas.
2. **Modularización Pura:** Descomposición en funciones sin variables globales ni efectos colaterales.
3. **Casos Borde y Manejo de Errores:** Validación defensiva ante punteros `NULL`, valores frontera (`0`, `NULL`, tamaños vacíos) y prevención estricta de división por cero o desbordamientos.
4. **Vectores de Prueba:** Pruebas sistemáticas automatizadas en `main(void)` con macro `assert(...)`.
5. **Higiene de Memoria:** Cero fugas en el Heap, verificación con sanitizers y ausencia de dobles liberaciones.

## Flujo de Trabajo y Verificación Rápida
- **Compilación manual estricta:** `gcc -Wall -Wextra -Werror -pedantic -std=c11 archivo.c -o programa`
- **Verificación estructural:** `node ejercicios/verificar_calidad.mjs`
- **Ejecución automatizada de soluciones:** `node ejercicios/verificar_ejercicios.mjs`

---

## ¿Y las prácticas?

Esta colección complementa las guías obligatorias de la cátedra para consolidar el aprendizaje autónomo mediante problemas graduados.

---

## Consideraciones Generales

A seguir siempre y cuando no esté indicada otra cosa:

1.  Resuelvan todos los ejercicios de manera iterativa, a no ser que esté
    indicado puntualmente.
2.  Los números son números enteros, estos incluyen al cero y los negativos.
3.  El nombre del archivo debe ser, el número del ejercicio reemplazando el
    punto por un guion y su apellido, por ejemplo: `1-1_apellido.c`.
4.  Apliquen y completen la plantilla de resolución de ejercicios que está a
    continuación, copiando el título y consigna del ejercicio y luego
    completando con sus datos.
5.  Lo que "resuelve" el enunciado debe estar encapsulado en una función,
    incluso si no está indicado explícitamente.
6.  El código debe seguir estrictamente el [catálogo de reglas de
    estilo](../reglas/indice.md) de la cátedra.
7.  Los ejercicios marcados como \[_plus ultra_\] son variaciones del ejercicio
    para ir «más allá» de la consigna original.

### Plantilla de Archivo y Ejemplo de Referencia

Cada entrega individual debe estructurarse mediante funciones puras, modularización y un conjunto exhaustivo de pruebas en `main(void)`. A continuación se presenta la plantilla estándar de resolución canónica (`1-1_apellido.c`):

```{code-block} c
:linenos:
/*
===============================================================================
Cátedra de Programación 1 - Universidad Nacional de Río Negro
Ejercicio 1.01.01 - Ejemplo de Estructura Canónica
Consigna: Implementar una función pura que valide si un entero es par.
Autor: Alumno Ejemplo
GitHub: @alumno-unrn
===============================================================================
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Determina si un número entero es par.
 * @param n Número entero de entrada.
 * @return true si n es divisible por 2, false en caso contrario.
 */
bool es_par(int n)
{
    return (n % 2 == 0);
}

int main(void)
{
    /* Casos de prueba exhaustivos */
    assert(es_par(0) == true);
    assert(es_par(2) == true);
    assert(es_par(-4) == true);
    assert(es_par(1) == false);
    assert(es_par(-7) == false);

    printf("Todos los vectores de prueba superados con éxito.\n");
    return 0;
}
```
<!-- {code-block} c -->

### Niveles de Dificultad

Todos los ejercicios se encuentran clasificados con la etiqueta
`**Dificultad:**` según su nivel de complejidad:

- ⭐☆☆☆☆ - **Básico:** Aplicación directa de 1-2 conceptos fundamentales.
- ⭐⭐☆☆☆ - **Fácil:** Combina 2-3 conceptos simples o estructuras elementales.
- ⭐⭐⭐☆☆ - **Intermedio:** Requiere diseño algorítmico o manejo de datos.
- ⭐⭐⭐⭐☆ - **Avanzado:** Múltiples conceptos integrados, indirección o
  optimización.
- ⭐⭐⭐⭐⭐ - **Experto:** Problemas complejos de arquitectura o algoritmos
  avanzados.

### Consignas Plus Ultra

Cada ejercicio incluye consignas opcionales marcadas como **`[*plus ultra*]`**
(frase en latín que significa «más allá»). Estas consignas están diseñadas para
ir más allá de la consigna base y profundizar el aprendizaje mediante:

- **Validación y Casos de Borde:** Manejo robusto de errores, valores límite y
  prevención de comportamientos indefinidos.
- **Optimización y Rendimiento:** Mejora en el uso de memoria, tiempo de
  ejecución y eficiencia algorítmica.
- **Extensión y Abstracción:** Generalización de soluciones, diseño de
  interfaces reutilizables o soporte para nuevas funcionalidades.

---

## Guía Metodológica de Andamiaje Pedagógico (Scaffolded Learning)

Para asegurar una progresión cognitiva sólida desde los fundamentos sintácticos hasta la creación de arquitecturas complejas de software, recomendamos abordar cada problema aplicando un proceso estructurado en cuatro etapas consecutivas:

### 1. Descomposición y Contratos Formales (Nivel Bloom 1-2: Recordar y Comprender)
- **Definición de Dominio:** Identificá con precisión el tipo de dato y el rango de las entradas válidas.
- **Precondiciones y Postcondiciones:** Documentá qué asume la función respecto a sus argumentos (por ejemplo, punteros no nulos, divisores distintos de cero) y qué garantías ofrece al retornar.
- **Firma Inmutable y Encapsulamiento:** Ocultá detalles internos y utilizá cualificadores `const` en punteros de solo lectura para evitar mutaciones accidentales.

### 2. Implementación Modular Pura (Nivel Bloom 3: Aplicar)
- **Funciones de Responsabilidad Única:** Descomponé el problema en submódulos pequeños y cohesivos.
- **Invariantes de Bucle:** Asegurá que cada iteración aproxime el estado hacia la condición de terminación, previniendo lazos infinitos y accesos fuera de rango.
- **Cero Efectos Secundarios:** Prohibí tajantemente variables globales y mutaciones fuera del ámbito estricto de los parámetros pasados por referencia.

### 3. Construcción Sistemática de Vectores de Prueba (Nivel Bloom 4: Analizar)
Antes de dar por concluida la implementación, elaborá una tabla de pruebas exhaustiva que contemple cuatro familias críticas de vectores:
- **Casos Típicos / Nominales:** Valores promedio representativos del dominio habitual.
- **Casos de Frontera (Edge Cases):** Límites extremos del dominio (arreglos vacíos con tamaño 0, valores neutros `0` y `1`, cadenas vacías `""`).
- **Casos Patológicos / Error:** Argumentos fuera de rango, punteros `NULL`, divisores nulos o desbordamientos potenciales.
- **Aserciones Automatizadas:** Trasladá la tabla directamente a llamadas `assert(...)` dentro de la función `main(void)`.

### 4. Auditoría y Verificación Estricta (Nivel Bloom 5-6: Evaluar y Crear)
- **Higiene de Compilación:** Verificá que la compilación produzca 0 advertencias bajo las directivas institucionales más rigurosas: `-Wall -Wextra -Werror -pedantic -std=c11`.
- **Integridad Dinámica:** Ejecutá las pruebas bajo AddressSanitizer y Valgrind para garantizar ausencia total de accesos inválidos, desbordamientos de pila/heap o pérdidas de memoria.

---

## Estructura de Ejercicios por Bloques

Los ejercicios se organizan replicando los bloques didácticos de los apuntes
para guiar tu proceso de aprendizaje de manera progresiva.

### Bloque 1: Fundamentos del Control de Flujo y Modularización

Ejercicios iniciales para asimilar la lógica de programación, el uso de
variables, condicionales, lazos iterativos, modularización mediante funciones,
recursividad introductoria y compilación con Makefiles.

*   [**1. Básicos y
    Secuencias**](./bloque_1_fundamentos/1_basicos_y_secuencias.md): Ejercicios
    introductorios para familiarizarse con la sintaxis de C, variables y lógica
    secuencial.
*   [**2. C Gradual**](./bloque_1_fundamentos/2_gradual_ejercicios.md):
    Ejercicios simples de traducción y asimilación gradual de sintaxis en C.
*   [**3. Algoritmos Matemáticos**](./bloque_1_fundamentos/3_matematicos.md):
    Problemas centrados en teoría de números (primos, MCD, potencias y
    secuencias lógicas).
*   [**4. Testing y Estructura de Código**](./bloque_1_fundamentos/4_testing_y_estructura.md):
    Pruebas unitarias con `assert`, eliminación de variables globales, análisis de flujo de control y reglas de estilo.
*   [**5. Control de Flujo y
    Lazos**](./bloque_1_fundamentos/5_ejercicios_control.md): Ejercicios de
    bifurcaciones condicionales y estructuras de repetición seguras.
*   [**6. Modularización y
    Funciones**](./bloque_1_fundamentos/6_funciones_ejercicios.md): Ejercicios
    para estructurar subprogramas mediante firmas, parámetros y deconstrucción
    funcional.
*   [**7. Librerías de
    Funciones**](./bloque_1_fundamentos/7_librerias_ejercicios.md): Ejercicios
    centrados en el diseño, encapsulamiento e implementación de módulos reutilizables `.h` y `.c`.
*   [**8. Compilación y
    Makefiles**](./bloque_1_fundamentos/8_compilacion_y_makefiles.md):
    Ejercicios sobre las etapas de compilación, enlazado físico y automatización
    de la construcción con `make`.
*   [**9. Refactorización de Código Ofuscado**](./bloque_1_fundamentos/9_refactorizacion_codigo_ofuscado.md):
    Deconstrucción, análisis y transformación de código críptico a C limpio, idiomático y modular.

### Bloque 2: Memoria

Ejercicios enfocados en la disposición física de datos en RAM, punteros e
indirección, cadenas de caracteres, persistencia en archivos de texto, memoria
dinámica en el Heap, estructuras compuestas, alias de tipos y enumeraciones.

*   [**1. Punteros e Indirección**](./bloque_2_memoria/1_punteros.md):
    Ejercicios para afianzar el uso de punteros, operador de dirección `&` e
    indirección `*`.
*   [**1b. Punteros y Ejercicios de
    Referencia**](./bloque_2_memoria/1b_punteros_ejercicios.md): Ejercicios de
    paso por referencia simulado y manipulación de memoria.
*   [**2. Arreglos Unidimensionales**](./bloque_2_memoria/2_arreglos.md):
    Manipulación de arreglos estáticos de tamaño fijo, búsqueda y estadísticas.
*   [**2b. Cadenas de Caracteres (Strings)**](./bloque_2_memoria/2b_cadenas.md):
    Operaciones sobre strings de estilo C y su terminador nulo `\0`.
*   [**3. Persistencia y Archivos de Texto**](./bloque_2_memoria/3_archivos.md):
    Lectura y escritura persistente de archivos formateados mediante streams.
*   [**3b. Ejercicios Adicionales de
    Archivos**](./bloque_2_memoria/3b_ejercicios_archivos.md): Ejercicios de
    manipulación de flujos de texto complejos.
*   [**4. Memoria Dinámica Básica**](./bloque_2_memoria/4_memoria_dinamica.md):
    Asignación con `malloc`, `calloc` y liberación correcta con `free`.
*   [**4b. Memoria Dinámica Avanzada**](./bloque_2_memoria/4b_memoria.md):
    Detección de fugas de memoria, address sanitizers y análisis físico de
    fragmentación del heap.
*   [**4c. Ejercicios Auxiliares de
    Memoria**](./bloque_2_memoria/4c_ejercicios_memoria.md): Ejercicios
    adicionales sobre alocación segura de recursos.
*   [**5. Aritmética de Punteros y
    Indirección**](./bloque_2_memoria/5_punteros_2.md): Ejercicios sobre doble
    indirección y bloques contiguos de memoria.
*   [**6. Estructuras Compuestas (structs)**](./bloque_2_memoria/6_structs.md):
    Modelado lógico y disposición en memoria física de registros y uniones.
*   [**7. Alias de Tipos y
    Proyectos**](./bloque_2_memoria/7_alias_tipos_ejercicios.md): Uso de
    `typedef` para modelar y portar tipos.
*   [**8. Tipos Enumerativos (enums)**](./bloque_2_memoria/8_enums.md):
    Ejercicios sobre enumeraciones y modelado de estados lógicos seguros.

### Bloque 3: Algoritmos y Estructuras de Datos

Ejercicios sobre matrices multidimensionales, Tipos de Datos Abstractos (TAD),
estructuras lineales (listas, pilas, colas) y análisis asintótico de
complejidad.

*   [**1. Matrices
    Multidimensionales**](./bloque_3_algoritmos_estructuras/1_matrices.md):
    Disposición *Row-Major* en RAM y manipulación de arreglos bidimensionales.
*   [**2. Tipos Abstractos de Datos
    (TAD)**](./bloque_3_algoritmos_estructuras/2_tad.md): Encapsulamiento
    estricto e interfaces de TADs empleando tipos incompletos y punteros opacos.
*   [**3. Estructuras de Datos
    Lineales**](./bloque_3_algoritmos_estructuras/3_estructuras_de_datos.md):
    Implementación de listas enlazadas, pilas y colas dinámicas.
*   [**4. Análisis de
    Complejidad**](./bloque_3_algoritmos_estructuras/4_complejidad.md):
    Ejercicios teóricos y empíricos sobre notación asintótica Big-O, límites de
    hardware y Teorema Maestro.
*   [**5. Recursividad**](./bloque_3_algoritmos_estructuras/5_recursion.md):
    Diseño de casos base explícitos, árboles de llamadas recursivas y algoritmos
    sobre secuencias.

### Bloque 4: Temas Avanzados

Ejercicios de nivel avanzado sobre callbacks, operaciones bitwise, archivos
binarios, recursividad avanzada, búsqueda/ordenamiento, análisis de código y
diseño de APIs.

*   [**1. Punteros Avanzados y
    Callbacks**](./bloque_4_avanzados/1_punteros_avanzados.md): Punteros a
    funciones y diseño genérico parametrizado.
*   [**2. Operaciones con Bits
    (Bitwise)**](./bloque_4_avanzados/2_operaciones_de_bits.md): Manipulación de
    banderas a bajo nivel y operadores a nivel de bits.
*   [**3. Archivos Binarios**](./bloque_4_avanzados/3_archivos_binarios.md):
    Lectura, escritura y procesamiento físico de archivos estructurados en
    formato binario.
*   [**4. Recursividad
    Avanzada**](./bloque_4_avanzados/4_recursividad_avanzada.md): Algoritmos de
    backtracking, divide y conquista y memoización dinámica.
*   [**5. Búsqueda y Ordenamiento
    Avanzado**](./bloque_4_avanzados/5_ordenamiento_y_busqueda.md): Algoritmos
    eficientes de ordenamiento por comparación y búsqueda no lineal.
*   [**6. Análisis y Debugging de
    Código**](./bloque_4_avanzados/6_analisis_de_codigo.md): Lectura,
    comprensión formal y depuración de bases de código heredadas.
*   [**7. Diseño Profesional de APIs**](./bloque_4_avanzados/7_diseno_api.md):
    Principios arquitectónicos de claridad, minimalismo, ocultamiento,
    versionado e ingeniería de APIs en C.

---

## Matriz Pedagógica y Resultados de Aprendizaje

El plan formativo de la cátedra articula las competencias según la Taxonomía de Bloom Revisada:

| Bloque Temático | Nivel Cognitivo Principal | Competencia Adquirida | Evidencia Evaluativa |
| :--- | :--- | :--- | :--- |
| **Bloque 1: Fundamentos** | Nivel 1 (Recordar) a Nivel 3 (Aplicar) | Control de flujo, descomposición algorítmica modular y compilación limpia | Programas compilables con 0 warnings bajo C11 |
| **Bloque 2: Memoria** | Nivel 3 (Aplicar) a Nivel 4 (Analizar) | Gestión del direccionamiento físico, aritmética de punteros y Heap seguro | Cero fugas de memoria con ASan y Valgrind |
| **Bloque 3: Algoritmos** | Nivel 4 (Analizar) a Nivel 5 (Evaluar) | Abstracción con Tipos Opacos (TADs) y medición de complejidad temporal/espacial | Instrumentación empírica y contrastación Big-O |
| **Bloque 4: Avanzados** | Nivel 5 (Evaluar) a Nivel 6 (Crear) | Diseño de APIs seguras, callbacks de orden superior y persistencia binaria | Arquitecturas basadas en handles y FSM |

---

## Verificación Automatizada y Entorno de Pruebas

Toda solución debe validarse localmente antes de integrarse al repositorio mediante el arnés de verificación institucional:

### 1. Verificación Estructural y de Reglas de Calidad
Comprueba que los bloques `{exercise}`, tablas de prueba obligatorias y soluciones `{solution}` cumplan con el estándar de documentación:
```bash
node ejercicios/verificar_calidad.mjs
```

### 2. Extracción, Compilación C11 y Ejecución de Aserciones
Extrae automáticamente los bloques de código C, invoca a `gcc` bajo directivas estrictas y ejecuta las aserciones de prueba en un entorno seguro:
```bash
node ejercicios/verificar_ejercicios.mjs
```

**Banderas de Compilación Requeridas:**
```bash
gcc -Wall -Wextra -Werror -pedantic -std=c11 solucion.c -o solucion
```

### 3. Criterio de Aceptación Institucional
Una entrega o solución se considera aprobada únicamente cuando:
1. Compila con **cero advertencias (0 warnings)** y **cero errores**.
2. Todas las aserciones `assert(...)` del `main(void)` retornan con código de salida `0`.
3. No existen accesos fuera de límites (*out-of-bounds*) ni dobles liberaciones (*double-free*).
4. El mensaje de commit respeta la convención de commits semánticos (*Conventional Commits*).
