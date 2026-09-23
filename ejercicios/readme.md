---
title: Repositorio de enunciados
short_title: Ejercicios
---

## ¿Y las prácticas?

La idea de esta sección, como algo separado a las prácticas obligatorias de la
cátedra, es que dispongas de una colección amplia de problemas complementarios
para consolidar el aprendizaje. Las prácticas de la cátedra siguen un régimen de
entrega formal con plazos estrictos y verificación automatizada de estilo y
corrección.

---

## Consideraciones generales

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

### Plantilla de archivo

En un archivo llamado `1-1_apellido.c`:

```{code-block} c
:linenos:
/*
Ejercicio 1.1 – Hola Mundo
Escribir un programa que imprima "Hola, mundo!" en la pantalla.
Este ejercicio nos permitirá verificar que el entorno de programación funciona.
-----------------
Nombre y Apellido
Usuario Github
*/
// prototipos
// main
// implementaciones
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
