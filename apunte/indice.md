---
title: Índice del Apunte
short_title: Índice
subtitle: Índice estructurado del material didáctico por bloques conceptuales
---

# Índice Temático del Apunte

El material de estudio de la cátedra está organizado físicamente en cuatro bloques didácticos secuenciales y una sección de contenidos avanzados. Esta estructura proporciona un andamiaje progresivo para el desarrollo de tus habilidades de programación.

---

## Bloque 1: Fundamentos del Control de Flujo y Modularización

Este bloque introduce la sintaxis básica de C, la gestión del estado, las bifurcaciones y los lazos, la descomposición modular y las bases lógicas de la verificación de software.

*   **[1. Fundamentos de Algoritmos](bloque_1_fundamentos/1_base.md)**: Representación de lógica, diagramas de flujo y variables.
*   **[2. Introducción a C y Estado](bloque_1_fundamentos/2_gradual.md)**: Sintaxis básica, tipos primitivos, roles de variables y estado del programa.
*   **[3. Estructuras de Control de Flujo](bloque_1_fundamentos/3_control_flujo.md)**: Decisiones condicionales, lazos (estructuras de repetición) y manejo del buffer de entrada.
*   **[4. Modularización y Ámbitos](bloque_1_fundamentos/4_funciones.md)**: Firmas de funciones, ámbitos de almacenamiento (`static`) y descomposición top-down.
*   **[5. Testing y Aserciones Básicas](bloque_1_fundamentos/5_testing_basico.md)**: Introducción al patrón AAA, la macro `assert` y la cobertura de ramas.
*   **[6. Introducción a la Recursividad](bloque_1_fundamentos/6_recursividad_intro.md)**: Fundamentos de recursión simple y anatomía cualitativa del Stack Frame.
*   **[7. Introducción a Contratos de Software](bloque_1_fundamentos/7_contratos_intro.md)**: Precondiciones, postcondiciones e invariantes de lazo informales.

---

## Bloque 2: Estructuración y Compilación de Proyectos

Conceptos necesarios para construir programas divididos en múltiples archivos fuente, gestionando la compilación automatizada de proyectos de mediana escala.

*   **[1. Fases de Compilación en C](bloque_2_proyectos/1_compilacion.md)**: Cabeceras `.h`, preprocesador, enlazado y argumentos de `main`.
*   **[2. Automatización con Makefiles](bloque_2_proyectos/2_makefiles.md)**: Compilación incremental, grafo de dependencias y objetivos ficticios (.PHONY).
*   **[3. Alias de Tipos (typedef)](bloque_2_proyectos/3_alias_tipos.md)**: Creación de alias de tipos personalizados y reglas de estilo.
*   **[4. Tipos Enumerativos (enum)](bloque_2_proyectos/4_enums.md)**: Declaración de constantes nombradas, colisiones en espacios de nombres y switch defensivo.

---

## Bloque 3: Disposición de Memoria y Estructuras Estáticas

Análisis físico del direccionamiento lógico de variables, jerarquías de caché de CPU, arreglos estáticos, indirectación física con punteros y empaquetamiento de estructuras.

*   **[1. Modelo Físico de Memoria](bloque_3_memoria_estatica/1_modelo_memoria.md)**: Organización de RAM (Stack vs Heap) y hardware de memoria caché del procesador.
*   **[2. Arreglos Unidimensionales y Strings](bloque_3_memoria_estatica/2_secuencias.md)**: Secuencias de datos estáticas, degradación y gestión segura de cadenas de caracteres.
*   **[3. Matrices Multidimensionales](bloque_3_memoria_estatica/3_matrices.md)**: Disposición *Row-Major* en RAM y optimización de localidad espacial para evitar fallos de caché.
*   **[4. Indirección Física y Punteros](bloque_3_memoria_estatica/4_punteros.md)**: Punteros físicos, operador de dirección `&` e indirección `*`, y simulación de paso por referencia.
*   **[5. Estructuras y Tipos Compuestos](bloque_3_memoria_estatica/5_estructuras.md)**: Registros compuestos (`struct`, `union`) y alineación en memoria (*padding*).
*   **[6. Representación de Números](bloque_3_memoria_estatica/6_numeros.md)**: Límites de representación física, desbordamientos e imprecisión de punto flotante.
*   **[7. Conversión de Tipos (Casts)](bloque_3_memoria_estatica/7_casts.md)**: Promoción entera, coerción aritmética implícita y conversión explícita.

---

## Bloque 4: Gestión Dinámica de Recursos e Interfaces Avanzadas

Asignación y liberación controlada de recursos del sistema, persistencia física de archivos, punteros a funciones, genericidad, tipos opacos y Tipos de Datos Abstractos.

*   **[1. Memoria Dinámica en el Heap](bloque_4_dinamica_interfaces/1_memoria_dinamica.md)**: Alocación con `malloc`/`free`, punteros colgantes y detección de fugas de memoria.
*   **[2. Aritmética de Direcciones y Doble Indirección](bloque_4_dinamica_interfaces/2_aritmetica.md)**: Aritmética de punteros, redimensionamiento con `realloc` y matrices dinámicas (`int **`).
*   **[3. Persistencia y Archivos de Texto](bloque_4_dinamica_interfaces/3_archivos_texto.md)**: Manejo físico de archivos de texto empleando streams de caracteres (`FILE *`).
*   **[4. Callbacks y Genericidad](bloque_4_dinamica_interfaces/4_punteros_funciones.md)**: Punteros a funciones y diseño paramétrico empleando punteros genéricos `void*`.
*   **[5. Encapsulamiento y Tipos Opacos](bloque_4_dinamica_interfaces/5_opacos.md)**: Ocultamiento estricto de información mediante tipos de datos incompletos en C.
*   **[6. Tipos de Datos Abstractos (TAD)](bloque_4_dinamica_interfaces/6_tad.md)**: Definición de TAD, interfaces y contratos aplicados a la estructura Secuencia (listas enlazadas).
*   **[7. Pilas, Colas y Deques](bloque_4_dinamica_interfaces/7_tad_pilas_colas.md)**: Estructuras con restricciones semánticas de acceso LIFO y FIFO.
*   **[8. Testing Avanzado y Automatización](bloque_4_dinamica_interfaces/8_testing_avanzado.md)**: Frameworks de pruebas personalizadas y testing basado en propiedades.
*   **[9. Diseño por Contratos Formal](bloque_4_dinamica_interfaces/9_contratos_formales.md)**: Lógica de Primer Orden, tripletas de Hoare, cálculo de wp, Frame Problem y ACSL.
*   **[10. Complejidad Algorítmica](bloque_4_dinamica_interfaces/10_complejidad.md)**: Eficiencia de algoritmos y de TADs, notación asintótica Big-O, límites de hardware y P vs NP.
