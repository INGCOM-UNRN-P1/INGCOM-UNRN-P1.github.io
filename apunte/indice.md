---
title: Índice del Apunte
short_title: Índice
subtitle: Índice estructurado del material didáctico por bloques conceptuales
---

# Índice Temático del Apunte

> **Prerrequisitos**: Una computadora con Windows o GNU/Linux y disposición para compilar ejemplos en Linux/WSL2.
>
> **Objetivos**: 1. Ubicar el capítulo previo necesario para un tema nuevo. 2. Planificar una ruta de estudio por bloques y dependencias.
>
> **Comprobación de salida**: elegí un tema del Bloque 4 e identificá los capítulos que debés dominar antes de estudiarlo.

El material de estudio de la cátedra está organizado físicamente en cuatro
bloques didácticos secuenciales. Esta estructura proporciona un andamiaje
progresivo para el desarrollo de tus habilidades de programación.

## El entorno

Para Windows y Linux, la cátedra ha creado un conjunto de scripts que se encargan de la
creación del espacio de trabajo, que además, está separado de la configuración
de lo que esté en la cátedra. [INGCOM-UNRN-P1/entorno](https://github.com/INGCOM-UNRN-P1/entorno)

Este se encarga de descargar todas las herramientas necesarias para trabajar,
compilar, editar y ejecutar el código que desarrollaras.

Podés verificar la instalación con:

```bash
gcc --version
make --version
```

Los ejemplos se compilan, salvo indicación contraria, con:

```bash
gcc -Wall -Wextra -std=c11 -pedantic archivo.c -o programa
```

## Metodología de estudio

En cada capítulo seguí este ciclo: leé el objetivo, ejecutá el ejemplo mínimo,
modificá una sola condición para observar su efecto y recién entonces resolvé
los ejercicios. Conservá los warnings del compilador: son parte de la
retroalimentación, no texto para ignorar. Si un capítulo depende de otro,
volvé al concepto previo antes de memorizar una solución.

## Matriz de dependencias conceptuales

| Para estudiar | Antes dominá | Resultado esperado |
| --- | --- | --- |
| Bloque 1 | lógica elemental y uso de terminal | programas C pequeños compilables |
| Bloque 2 | variables, control y funciones | explicar direcciones, vida útil y recursos |
| Bloque 3 | punteros, memoria dinámica y testing básico | diseñar y probar TADs |
| Bloque 4 | bloques 1–3, contratos y compilación modular | integrar APIs y recursos de sistema |

---

## Bloque 1: Fundamentos del Control de Flujo y Modularización

Este bloque introduce la sintaxis básica de C, la gestión del estado, las
bifurcaciones y los lazos, la descomposición modular, la compilación
automatizada de proyectos y las bases lógicas de la verificación de software.

*   **[1. Fundamentos de Algoritmos](bloque_1_fundamentos/1_base.md)**:
    Representación de lógica, diagramas de flujo y variables.
*   **[2. Introducción a C y Estado](bloque_1_fundamentos/2_gradual.md)**:
    Sintaxis básica, tipos primitivos, roles de variables y estado del programa.
*   **[3. Estructuras de Control de
    Flujo](bloque_1_fundamentos/3_control_flujo.md)**: Decisiones condicionales,
    lazos (estructuras de repetición) y manejo del buffer de entrada.
*   **[4. Modularización y Ámbitos](bloque_1_fundamentos/4_funciones.md)**:
    Firmas de funciones, ámbitos de almacenamiento (`static`) y descomposición
    top-down.
*   **[5. Fases de Compilación en C](bloque_1_fundamentos/5_compilacion.md)**:
    Cabeceras `.h`, preprocesador, enlazado y argumentos de `main`.
*   **[6. Testing y Aserciones
    Básicas](bloque_1_fundamentos/6_testing_basico.md)**: Introducción al patrón
    AAA, la macro `assert` y la cobertura de ramas.
*   **[7. Introducción a Contratos de
    Software](bloque_1_fundamentos/7_contratos_intro.md)**: Precondiciones,
    postcondiciones e invariantes de lazo informales.
*   **[8. Automatización con Makefiles](bloque_1_fundamentos/8_makefiles.md)**:
    Compilación incremental, grafo de dependencias y objetivos ficticios
    (.PHONY).

---

## Bloque 2: Memoria

Este bloque avanza desde la ubicación y representación de un valor hasta la
administración explícita de recursos. No es una lista de técnicas
intercambiables: cada etapa activa un conocimiento necesario para la siguiente.

:::{important} Ruta recomendada

Completá los capítulos en este orden. Los nombres de archivo conservan su
numeración histórica, pero la navegación y la secuencia didáctica siguen las
dependencias conceptuales.

:::

*   **[1. Modelo Físico de Memoria](bloque_2_memoria/1_modelo_memoria.md)**:
    Organización de RAM (Stack vs Heap) y hardware de memoria caché del
    procesador.
*   **[2. Indirección Física y Punteros](bloque_2_memoria/2_punteros.md)**:
    Punteros físicos, operador de dirección `&` e indirección `*`, y simulación
    de pasaje por referencia.
*   **[3. Arreglos Unidimensionales y Strings](bloque_2_memoria/3_secuencias.md)**:
    Secuencias de datos estáticas, decaimiento a puntero y gestión segura de cadenas 
    de caracteres.
*   **[4. Representación de Números](bloque_2_memoria/8_numeros.md)**: Límites
    de representación física, desbordamientos e imprecisión de punto flotante.
*   **[5. Conversión de Tipos (Casts)](bloque_2_memoria/9_casts.md)**: Promoción
    entera, coerción aritmética implícita y conversión explícita.
*   **[6. Estructuras y Tipos Compuestos](bloque_2_memoria/7_estructuras.md)**:
    Registros compuestos (`struct`, `union`) y alineación en memoria
    (*padding*).
*   **[7. Alias de Tipos (typedef)](bloque_2_memoria/10_alias_tipos.md)**:
    Creación de alias de tipos personalizados y reglas de estilo.
*   **[8. Tipos Enumerativos (enum)](bloque_2_memoria/11_enums.md)**:
    Declaración de constantes nombradas, colisiones en espacios de nombres y
    switch defensivo.
*   **[9. Memoria Dinámica en el Heap](bloque_2_memoria/5_memoria_dinamica.md)**:
    Alocación con `malloc`/`free`, propiedad de recursos y detección de fugas.
*   **[10. Aritmética de Direcciones y Matrices Dinámicas](bloque_2_memoria/6_aritmetica.md)**:
    Aritmética de punteros, doble indirección y estrategias de matrices dinámicas.
*   **[11. Persistencia y Archivos de Texto](bloque_2_memoria/4_archivos_texto.md)**:
    Aplicación integradora de punteros, cadenas y ciclo de vida de recursos con `FILE *`.

---

## Bloque 3: Algoritmos y Estructuras de Datos

Uso de matrices multidimensionales, Tipos de Datos Abstractos (TADs),
estructuras lineales con contratos informales y formales, análisis asintótico de
complejidad e introducción a la recursividad.

*   **[1. Matrices Multidimensionales](bloque_3_algoritmos_estructuras/1_matrices.md)**:
    Disposición *Row-Major* en RAM y optimización de localidad espacial para
    evitar fallos de caché.
*   **[2. Tipos de Datos Abstractos (TAD)](bloque_3_algoritmos_estructuras/2_tad.md)**: Definición de TAD,
    interfaces y contratos aplicados a la estructura Secuencia (listas
    enlazadas).
*   **[3. Pilas, Colas y
    Deques](bloque_3_algoritmos_estructuras/3_tad_pilas_colas.md)**: Estructuras
    con restricciones semánticas de acceso LIFO y FIFO.
*   **[4. Testing Avanzado y
    Automatización](bloque_3_algoritmos_estructuras/4_testing_avanzado.md)**:
    Frameworks de pruebas personalizadas y testing basado en propiedades.
*   **[5. Diseño por Contratos y
    Aserciones](bloque_3_algoritmos_estructuras/5_contratos_formales.md)**:
    Precondiciones, postcondiciones e invariantes de estructura usando
    `assert.h` en C estándar.
*   **[6. Complejidad
    Algorítmica](bloque_3_algoritmos_estructuras/6_complejidad.md)**: Eficiencia
    de algoritmos y de TADs, notación asintótica Big-O, límites de hardware y P
    vs NP.
*   **[7. Introducción a la
    Recursividad](bloque_3_algoritmos_estructuras/7_recursividad_intro.md)**:
    Fundamentos de recursión simple y anatomía cualitativa del Stack Frame.

---

## Bloque 4: Temas Avanzados

Tópicos de optimización a bajo nivel, encapsulamiento, manipulación de bits,
recursividad avanzada y diseño arquitectónico de APIs robustas en C.

*   **[1. Índice de Temas Avanzados](bloque_4_avanzados/1_indice_avanzados.md)**: Resumen y guía
    didáctica de contenidos avanzados.
*   **[2. Callbacks y Genericidad](bloque_4_avanzados/2_punteros_funciones.md)**: Punteros a
    funciones y diseño paramétrico empleando punteros genéricos `void*`.
*   **[3. Encapsulamiento y Tipos Opacos](bloque_4_avanzados/3_opacos.md)**:
    Ocultamiento estricto de información mediante tipos de datos incompletos en
    C.
*   **[4. Archivos Binarios](bloque_4_avanzados/4_binarios_archivos.md)**:
    Persistencia en disco de estructuras binarias mediante `fread` y `fwrite`.
*   **[5. Operaciones Bitwise](bloque_4_avanzados/5_binarios_bitwise.md)**:
    Álgebra de Boole a nivel de bit y máscaras.
*   **[6. Manipulación de Bitmaps (BMP)](bloque_4_avanzados/6_bitmaps.md)**:
    Lectura, edición y escritura de imágenes rasterizadas BMP.
*   **[7. Recursividad Avanzada](bloque_4_avanzados/7_recursividad_avanzada.md)**: Backtracking y
    optimización cualitativa.
*   **[8. C Idiomático y Patrones](bloque_4_avanzados/8_idiomatico.md)**:
    Modismos del lenguaje C y refactorización orientada a seguridad.
*   **[9. Diseño de APIs](bloque_4_avanzados/9_api_diseno.md)**: Principios para
    interfaces cohesivas y seguras.
*   **[10. Ingeniería de APIs](bloque_4_avanzados/10_api_ingenieria.md)**:
    Modularización a gran escala y versionado de interfaces.
*   **[11. Concurrencia e Hilos](bloque_4_avanzados/11_hilos.md)**: Hilos POSIX
    (`pthreads`) y primitivas de sincronización.
*   **[12. Programación con Sockets](bloque_4_avanzados/12_sockets.md)**:
    Comunicación en red mediante sockets UNIX.
