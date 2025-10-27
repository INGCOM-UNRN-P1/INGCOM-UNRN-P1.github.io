---
title: Repositorio de enunciados
short_title: Ejercicios
---

## ¿Y las practicas?

La idea de esta sección, como algo separado a las prácticas, es que tengan más
ejercicios para hacer. Las prácticas están con un régimen de entrega que tiene
plazos más verificación de cuestiones de estilo y otras cosas.

```{note}
"Más allá" Frase en latín utilizada por Carlos I, durante la
    época de Colón.
    
[Wikipedia - Plus_ultra_(lema)](https://es.wikipedia.org/wiki/Plus_ultra_(lema))
```

## Consideraciones generales

A seguir siempre y cuando no esté indicada otra cosa:

1.  Resuelvan todos los ejercicios de manera iterativa, a no ser que esté
    indicado puntualmente.
2.  Los números son números enteros, estos incluyen al cero y los negativos.
3.  El nombre del archivo debe ser, el número del ejercicio reemplazando el
    punto por un guion y su apellido, por ejemplo\
    _1-1_vilugron.c_
4.  Apliquen y completen la plantilla de resolución de ejercicios que está a
    continuación, en la misma, copien el título y consigna del ejercicio
    primero. Y luego completen con sus datos.
5.  Lo que 'resuelve' el enunciado, debe de estar en una función. Incluso si no
    hay una indicada explicitamente.
6.  El código debe seguir la [guía de estilo](../apunte/0_estilo.md).
7.  Los ejercicios marcados como \[_plus ultra_\] son variaciones del ejercicio,
    con otras formas para ir «más allá» de la consigna original.

```{note}
"Más allá" Frase en latín utilizada por Carlos I, durante la
    época de Colón.

[Wikipedia - Plus_ultra_(lema)](https://es.wikipedia.org/wiki/Plus_ultra_(lema))
```

### Plantilla de archivo

En un archivo llamado

```{code} textc
:label: plantilla_c
:filename: 1-1_apellido.c
:caption: Para tener todo ordenado
/*
Ejercicio 1.1 – Hola Mundo
Porque hay que empezar por algún lado, escribir un programa que
imprima "Hola, mundo!" en la pantalla.
Este ejercicio nos permitirá verificar el que el entorno de
programación funciona.
-----------------
Nombre y Apellido
Usuario Github
*/

// prototipos

// main

// implementaciones

```

A pesar de que varios de los ejercicios son combinables, es mejor hacerlo cuando
veamos funciones, cosa de simplificar las cosas.

## Ejercicios

Aquí encontrarás todos los ejercicios de la cátedra, organizados en dos categorías principales para facilitar tu progresión en el aprendizaje de C. Cada sección agrupa problemas relacionados con conceptos específicos del lenguaje.

:::{note} Números repetidos

Los números de los conjuntos de ejercicios se repiten por una diferencia en forma
de armar y agrupar los ejercicios.

Se empezó por una separación temática y despues se mezcló por el número de página del apunte.

```
¯\_(ツ)_/¯
```

:::


### Fundamentos

Ejercicios básicos para construir bases sólidas en programación C. Estos ejercicios cubren desde los conceptos más elementales hasta las estructuras de datos fundamentales.

- [**1. Básicos y Secuencias**](./1_basicos_y_secuencias.md): Ejercicios
  introductorios para familiarizarse con la sintaxis de C, el control de flujo y
  las operaciones fundamentales.

- [**2. Matemáticos**](./2_matematicos.md): Problemas centrados en algoritmos de
  teoría de números, como primos, MCD, y propiedades numéricas.

- [**3. Arreglos (Estáticos)**](./3_arreglos.md): Ejercicios para la
  manipulación de arreglos de tamaño fijo, incluyendo operaciones de búsqueda,
  ordenamiento y estadísticas.

- [**4. Cadenas**](./4_cadenas.md): Problemas relacionados con la manipulación
  de cadenas de caracteres estilo C, como análisis, transformaciones y
  conversiones.

- [**5. Punteros**](./5_punteros.md): Ejercicios diseñados para afianzar el uso
  de punteros, la aritmética de punteros y el paso de variables por referencia.

- [**6. Memoria Dinámica**](./6_memoria_dinamica.md): Prácticas sobre la gestión
  de memoria con `malloc`, `calloc`, `realloc` y `free` para arreglos, cadenas y
  matrices de tamaño variable.

- [**7. Matrices**](./7_matrices.md): Ejercicios para trabajar con arreglos
  bidimensionales, cubriendo operaciones aritméticas y de manipulación.

- [**8. Archivos**](./8_archivos.md): Problemas de persistencia de datos,
  incluyendo lectura, escritura y manipulación de archivos de texto.

- [**9. Structs**](./9_structs.md): Ejercicios para modelar datos complejos
  utilizando estructuras, como fracciones, fechas y tipos de datos compuestos.

- [**10. Enums**](./10_enums.md): Ejercicios sobre enumeraciones y su uso en combinación con estructuras para modelar datos más complejos.

- [**10. Recursión**](./10_recursion.md): Problemas para practicar el
  pensamiento recursivo y la implementación de algoritmos sin el uso de lazos
  explícitos.

### Avanzados

Ejercicios de nivel avanzado que profundizan en técnicas sofisticadas de programación, análisis de algoritmos, y diseño de software profesional.

- [**11. Memoria Dinámica Avanzada**](./11_memoria.md): Ejercicios avanzados sobre gestión de memoria, incluyendo el modelo de memoria del proceso, patrones de gestión, detección de errores con herramientas como Valgrind y AddressSanitizer, análisis de fragmentación y optimización.

- [**11. Búsqueda y Ordenamiento**](./11_ordenamiento_y_busqueda.md): Algoritmos de ordenamiento y técnicas de búsqueda eficientes.

- [**12. Punteros Avanzados**](./12_punteros_2.md): Ejercicios sobre memoria dinámica avanzada, estructuras con punteros anidados, matrices dinámicas con diferentes enfoques (dentadas, bloque único, cast avanzado), y patrones de gestión de memoria complejos.

- [**12. Operaciones con Bits**](./12_operaciones_de_bits.md): Manipulación de bits y operaciones a nivel de bits.

- [**13. TAD (Tipos Abstractos de Datos)**](./13_tad.md): Diseño e implementación de tipos abstractos de datos con encapsulamiento apropiado.

- [**13. Estructuras de Datos**](./13_estructuras_de_datos.md): Implementación de estructuras de datos clásicas como listas, pilas, colas y árboles.

- [**14. Análisis de Complejidad**](./14_complejidad.md): Ejercicios sobre análisis asintótico de algoritmos, notaciones Big-O, Omega y Theta, análisis de lazos y recursión, Teorema Maestro, límites inferiores, y técnicas de optimización. Incluye tanto análisis teórico como medición empírica de performance.

- [**14. Compilación y Makefiles**](./14_compilacion_y_makefiles.md): Proceso de compilación, enlazado y automatización con makefiles.

- [**15. Recursividad Avanzada**](./15_recursividad.md): Técnicas avanzadas de recursión, incluyendo backtracking, divide y conquista, y optimización con memoización.

- [**15. Archivos Binarios**](./15_archivos_binarios.md): Lectura y escritura de archivos en formato binario.

- [**16. Punteros Avanzados II**](./16_punteros_avanzados.md): Técnicas avanzadas con punteros, incluyendo punteros a funciones y estructuras complejas.

- [**17. Análisis de Código**](./17_analisis_de_codigo.md): Lectura, comprensión y debugging de código existente.

- [**Diseño de APIs**](./diseno_api.md): Ejercicios sobre diseño profesional de interfaces y librerías en C, cubriendo principios de claridad, encapsulamiento, manejo de errores, tipos opacos, contratos de interfaz, versionado, testing, y patrones de diseño. Incluye ejercicios conceptuales y prácticos para desarrollar habilidades en arquitectura de software.
