---
title: Repositorio de enunciados
short_title: Ejercicios
---

## ¿Y las prácticas?

La idea de esta sección, como algo separado a las prácticas obligatorias de la cátedra, es que dispongas de una colección amplia de problemas complementarios para consolidar el aprendizaje. Las prácticas de la cátedra siguen un régimen de entrega formal con plazos estrictos y verificación automatizada de estilo y corrección.

---

## Consideraciones generales

A seguir siempre y cuando no esté indicada otra cosa:

1.  Resuelvan todos los ejercicios de manera iterativa, a no ser que esté indicado puntualmente.
2.  Los números son números enteros, estos incluyen al cero y los negativos.
3.  El nombre del archivo debe ser, el número del ejercicio reemplazando el punto por un guion y su apellido, por ejemplo: `1-1_apellido.c`.
4.  Apliquen y completen la plantilla de resolución de ejercicios que está a continuación, copiando el título y consigna del ejercicio y luego completando con sus datos.
5.  Lo que "resuelve" el enunciado debe estar encapsulado en una función, incluso si no está indicado explícitamente.
6.  El código debe seguir estrictamente la [guía de estilo](../apunte/0_estilo.md).
7.  Los ejercicios marcados como \[_plus ultra_\] son variaciones del ejercicio para ir «más allá» de la consigna original.

### Plantilla de archivo

En un archivo llamado `1-1_apellido.c`:

```c
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

---

## Estructura de Ejercicios por Bloques

Los ejercicios se organizan replicando los bloques didácticos de los apuntes para guiar tu proceso de aprendizaje de manera progresiva.

### Bloque 1: Fundamentos del Control de Flujo y Modularización

Ejercicios iniciales para asimilar la lógica de programación, el uso de variables, condicionales, lazos iterativos y modularización mediante funciones básicas.

*   [**0. Cuadernillo de Ejercicios**](./bloque_1_fundamentos/cuadernillo.md): La primera colección de ejercicios guiados de programación y bases de C.
*   [**1. Básicos y Secuencias**](./bloque_1_fundamentos/1_basicos_y_secuencias.md): Ejercicios introductorios para familiarizarse con la sintaxis de C, variables y lógica secuencial.
*   [**2. C Gradual**](./bloque_1_fundamentos/2_gradual_ejercicios.md): Ejercicios simples de traducción y asimilación gradual de sintaxis en C.
*   [**3. Algoritmos Matemáticos**](./bloque_1_fundamentos/3_matematicos.md): Problemas centrados en teoría de números (primos, MCD, potencias y secuencias lógicas).
*   [**5. Control de Flujo y Lazos**](./bloque_1_fundamentos/5_ejercicios_control.md): Ejercicios de bifurcaciones condicionales y estructuras de repetición seguras.
*   [**6. Modularización y Funciones**](./bloque_1_fundamentos/6_funciones_ejercicios.md): Ejercicios para estructurar subprogramas mediante firmas, parámetros y deconstrucción funcional.
*   [**8. Recursividad Introductoria**](./bloque_1_fundamentos/8_recursion.md): Problemas sencillos para iniciar en el pensamiento recursivo y el análisis cualitativo del stack frame.

### Bloque 2: Estructuración y Compilación de Proyectos

Ejercicios orientados a la división del código fuente en múltiples archivos, la creación de alias de tipos, estructuras de datos lógicas y la automatización del proceso de compilación.

*   [**2. Compilación y Makefiles**](./bloque_2_proyectos/2_compilacion_y_makefiles.md): Ejercicios sobre las etapas de compilación, enlazado físico y automatización de la construcción con `make`.
*   [**3. Alias de Tipos y Proyectos**](./bloque_2_proyectos/3_alias_tipos_ejercicios.md): Uso de `typedef` para modelar y portar tipos.
*   [**4. Tipos Enumerativos (enums)**](./bloque_2_proyectos/4_enums.md): Ejercicios sobre enumeraciones y modelado de estados lógicos seguros.

### Bloque 3: Disposición de Memoria y Estructuras Estáticas

Ejercicios enfocados en la disposición física de datos en RAM, el decaimiento de arreglos, la indirección mediante punteros y el empaquetamiento de estructuras compuestas.

*   [**1b. Operaciones con Bits (Bitwise)**](./bloque_3_memoria_estatica/1b_operaciones_de_bits.md): Manipulación de banderas a bajo nivel y operadores a nivel de bits.
*   [**2. Arreglos Unidimensionales**](./bloque_3_memoria_estatica/2_arreglos.md): Manipulación de arreglos estáticos de tamaño fijo, búsqueda y estadísticas.
*   [**2b. Cadenas de Caracteres (Strings)**](./bloque_3_memoria_estatica/2b_cadenas.md): Operaciones sobre strings de estilo C y su terminador nulo `\0`.
*   [**3. Matrices Multidimensionales**](./bloque_3_memoria_estatica/3_matrices.md): Disposición *Row-Major* en RAM y manipulación de arreglos bidimensionales estáticos.
*   [**4. Punteros e Indirección**](./bloque_3_memoria_estatica/4_punteros.md): Ejercicios para afianzar el uso de punteros, operador de dirección `&` e indirección `*`.
*   [**4b. Punteros y Ejercicios de Referencia**](./bloque_3_memoria_estatica/4b_punteros_ejercicios.md): Ejercicios de paso por referencia simulado y manipulación de memoria.
*   [**5. Estructuras Compuestas (structs)**](./bloque_3_memoria_estatica/5_structs.md): Modelado lógico y disposición en memoria física de registros y uniones.

### Bloque 4: Gestión Dinámica de Recursos e Interfaces Avanzadas

Ejercicios sobre el ciclo de vida de la memoria dinámica en el Heap, la persistencia en archivos de texto, punteros a funciones, genericidad, tipos opacos y Tipos de Datos Abstractos (TAD).

*   [**1. Memoria Dinámica Básica**](./bloque_4_dinamica_interfaces/1_memoria_dinamica.md): Asignación con `malloc`, `calloc` y liberación correcta con `free`.
*   [**1b. Memoria Dinámica Avanzada**](./bloque_4_dinamica_interfaces/1b_memoria.md): Detección de fugas de memoria, address sanitizers y análisis físico de fragmentación del heap.
*   [**1c. Ejercicios Auxiliares de Memoria**](./bloque_4_dinamica_interfaces/1c_ejercicios_memoria.md): Ejercicios adicionales sobre alocación segura de recursos.
*   [**2. Aritmética de Punteros y Matrices Dinámicas**](./bloque_4_dinamica_interfaces/2_punteros_2.md): Ejercicios sobre matrices dinámicas dentadas y bloques contiguos de memoria.
*   [**3. Persistencia y Archivos de Texto**](./bloque_4_dinamica_interfaces/3_archivos.md): Lectura y escritura persistente de archivos formateados mediante streams.
*   [**3b. Ejercicios Adicionales de Archivos**](./bloque_4_dinamica_interfaces/3b_ejercicios_archivos.md): Ejercicios de manipulación de flujos de texto complejos.
*   [**4. Punteros Avanzados y Callbacks**](./bloque_4_dinamica_interfaces/4_punteros_avanzados.md): Punteros a funciones y diseño genérico parametrizado.
*   [**6. Tipos Abstractos de Datos (TAD)**](./bloque_4_dinamica_interfaces/6_tad.md): Encapsulamiento estricto e interfaces de TADs empleando tipos incompletos y punteros opacos.
*   [**7. Estructuras de Datos Lineales**](./bloque_4_dinamica_interfaces/7_estructuras_de_datos.md): Implementación de listas enlazadas, pilas y colas dinámicas.
*   [**10. Análisis de Complejidad**](./bloque_4_dinamica_interfaces/10_complejidad.md): Ejercicios teóricos y empíricos sobre notación asintótica Big-O, límites de hardware y Teorema Maestro.

### Bloque 5: Temas Avanzados

Ejercicios de nivel avanzado para profundizar en arquitectura de software, debugging formal, optimización y diseño de APIs seguras y profesionales.

*   [**1. Búsqueda y Ordenamiento Avanzado**](./bloque_5_avanzados/ordenamiento_y_busqueda.md): Algoritmos eficientes de ordenamiento por comparación y búsqueda no lineal.
*   [**2. Archivos Binarios**](./bloque_5_avanzados/archivos_binarios.md): Lectura, escritura y procesamiento físico de archivos estructurados en formato binario.
*   [**3. Recursividad Avanzada**](./bloque_5_avanzados/recursividad_avanzada.md): Algoritmos de backtracking, divide y conquista y memoización dinámica.
*   [**4. Análisis y Debugging de Código**](./bloque_5_avanzados/analisis_de_codigo.md): Lectura, comprensión formal y depuración de bases de código heredadas.
*   [**5. Diseño Profesional de APIs**](./bloque_5_avanzados/diseno_api.md): Principios arquitectónicos de claridad, minimalismo, ocultamiento, versionado e ingeniería de APIs en C.
