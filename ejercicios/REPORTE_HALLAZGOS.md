# Reporte de Auditoría y Hallazgos: Banco de Ejercicios de Programación 1

**Fecha de auditoría:** 2026-09-23  
**Herramienta de evaluación:** TypeSafe Jev (`jev-1.13.0` / System One) + Script
determinista de análisis estático  
**Universo analizado:** 35 archivos Markdown en `ejercicios/`  
**Volumen total:** 681 ejercicios identificados

---

## 1. Resumen Ejecutivo y Métricas Consolidadas

El estado actual del banco de ejercicios presenta fallas estructurales
sistemáticas que impiden su uso autónomo y riguroso por parte de los
estudiantes. El 91.4% de los archivos se encuentra clasificado en nivel
**DEFICIENTE**. Además de la corrupción sintáctica, se detectó una severa
**filtración de prerrequisitos prematuros (_concept leakage_)**, violando la
progresión curricular acumulativa del apunte.

| Métrica Global                                                 |   Valor Obtenido    | Umbral Mínimo Aceptable |            Estado             |
| :------------------------------------------------------------- | :-----------------: | :---------------------: | :---------------------------: |
| **Índice de Calidad Global Promedio**                          |   **22.49 / 100**   |       $\ge 70.0$        |          ❌ Crítico           |
| **Archivos en DEFICIENTE**                                     | **32 / 35 (91.4%)** |           $0$           |          ❌ Crítico           |
| **Archivos en MEJORABLE**                                      |  **3 / 35 (8.6%)**  |         $\le 5$         |      ⚠️ Requiere ajuste       |
| **Archivos en BUENO / EXCELENTE**                              |   **0 / 35 (0%)**   |          $35$           |        ❌ Inexistente         |
| **Claridad Pedagógica Promedio (Jev Score)**                   |   **0.71 / 3.00**   |       $\ge 2.20$        |    ❌ Fractura sintáctica     |
| **Completitud Técnica Promedio (Jev Score)**                   |   **0.85 / 3.00**   |       $\ge 2.20$        | ❌ Ausencia de especificación |
| **Presencia de Casos de Prueba ($P_{test}$ Noul)**             |      **0.13**       |       $\ge 0.85$        | ❌ 87% de déficit de pruebas  |
| **Probabilidad de Texto Truncado ($P_{trunc}$ Noul)**          |      **0.82**       |       $\le 0.05$        |     ❌ 82% de prevalencia     |
| **Líneas/Viñetas con Truncamiento Sintáctico**                 |   **864 líneas**    |           $0$           |    ❌ Corrupción de texto     |
| **Ocurrencias de Boilerplate `[*plus ultra*]`**                |  **1.901 bloques**  |            —            |     ❌ Clonación acrítica     |
| **Fuga de Conceptos Prematuros ($P_{leak}$ en Bloques 2 y 3)** |   **0.95 – 0.98**   |       $\le 0.05$        |  ❌ Violación de progresión   |

---

## 2. Taxonomía de Patologías Críticas Detectadas

### Patología 1: Truncamiento mecánico de enunciados y viñetas (864 casos)

Múltiples archivos sufrieron un proceso de corte o generación truncada donde las
viñetas se interrumpen abruptamente antes de cerrar la idea, terminando en
preposiciones, artículos o comas.

- **Evidencia directa en `bloque_1_fundamentos/1_basicos_y_secuencias.md`:**
  - Línea 50:
    `- **Proceso:** Se debe utilizar un lazo que itere desde $N$ hacia abajo, hasta`
  - Línea 51:
    `- **Pausa:** Dentro del lazo, después de imprimir cada número, el programa`
  - Línea 52:
    `- **Salida:** Tras finalizar el lazo, se debe imprimir el mensaje final`
  - Línea 92:
    `- **Proceso:** Se utiliza una función de la biblioteca estándar para enviar`
  - Línea 125:
    `- **Variables:** Se necesita una variable para almacenar el nombre del`
  - Línea 126:
    `- **Entrada:** El programa debe primero mostrar un mensaje pidiendo al usuario`
  - Línea 127:
    `- **Funciones de Lectura:** Se puede usar scanf() para leer la entrada, pero`
  - Línea 170:
    `- **Entrada:** Se deben leer dos números enteros, n (inicio del rango) y m`
  - Línea 171:
    `- **Proceso:** Se utiliza un lazo for que recorra cada número i desde n`
  - Línea 172:
    `- **Condición de Paridad:** Dentro del lazo, para cada número i, se debe`

### Patología 2: Clonación indiscriminada de consignas "Plus Ultra" (1.901 casos)

Los bloques `[*plus ultra*]` fueron inyectados mediante plantillas fijas sin
correspondencia semántica con el ejercicio, produciendo consignas absurdas e
inaplicables.

- **Evidencia directa:**
  - `bloque_3_algoritmos_estructuras/5_recursion.md` (Líneas 50-53, Ejercicio
    25.1: Factorial escalar):
    - `[*plus ultra*]: Implementar encapsulamiento completo manteniendo la definición interna oculta en el archivo .c.`
    - `[*plus ultra*]: Añadir una función de duplicación profunda (*deep copy*) para copiar la estructura de forma segura.`
      _(Inaplicable: el cálculo de un factorial no posee estructuras dinámicas
      ni TDA)._
  - `bloque_2_memoria/1_punteros.md` (Líneas 58-59, Ejercicio 8.2: División
    lenta de enteros):
    - `[*plus ultra*]: Añadir una función de duplicación profunda (*deep copy*) para copiar la estructura de forma segura.`
      _(Inaplicable: divide enteros)._
  - `bloque_2_memoria/1_punteros.md` (Líneas 72-73, Ejercicio 8.3: Estadísticas
    en arreglo unidimensional):
    - `[*plus ultra*]: Optimizar el acceso a memoria respetando el orden por filas (*row-major order*) para mejorar el uso de caché.`
      _(Inaplicable: es un arreglo 1D, no matricial)._
  - `bloque_3_algoritmos_estructuras/2_tad.md` (Líneas 74-75, Ejercicio 22.2:
    Inserción al final de Lista Enlazada):
    - `[*plus ultra*]: Implementar una versión utilizando aritmética de punteros en lugar de indexación directa.`
      _(Inaplicable y peligroso: los nodos de listas dinámicas no son contiguos;
      la aritmética de punteros induce comportamiento indefinido)._
  - `bloque_3_algoritmos_estructuras/4_complejidad.md` (Líneas 39-42, Ejercicio
    24.1: Clasificación asintótica formal de $T(n)$):
    - `[*plus ultra*]: Diseñar la función para devolver un código de estado de error e informar el resultado mediante parámetros de salida.`
      _(Inaplicable: ejercicio analítico/matemático sin código C)._

### Patología 3: Desplazamiento e inversión de anclas MyST

En la casi totalidad de los archivos de los bloques 2 y 3, el ancla
`(ejercicio_X_Y)=` se encuentra ubicada **antes del bloque `{hint}` del
ejercicio anterior**, en lugar de anteceder inmediatamente a su propio
encabezado `### Ejercicio X.Y`.

- **Evidencia directa en `bloque_2_memoria/1_punteros.md`:**
  - Línea 33: `(ejercicio_8_2)=` colocado sobre el hint del Ejercicio 8.1.
  - Línea 45: Encabezado real `### Ejercicio 8.2 - División Lenta II`.
  - Línea 52: `(ejercicio_8_3)=` colocado sobre el hint del Ejercicio 8.2.
  - Línea 64: Encabezado real `### Ejercicio 8.3 - Estadísticas de Arreglo`.
- **Consecuencia:** Toda referencia cruzada `{ref}ejercicio_8_2` traslada al
  alumno a la ayuda del ejercicio anterior.

### Patología 4: Caos en numeración e inconsistencias sintácticas MyST

No existe correlación entre el bloque, el nombre de archivo y la numeración
interna:

- `bloque_2_memoria/1_punteros.md` titula sus ejercicios como `Ejercicio 8.1`,
  `8.2`...
- `bloque_3_algoritmos_estructuras/2_tad.md` arranca en `Ejercicio 22.1`.
- `bloque_2_memoria/4c_ejercicios_memoria.md` titula
  `## Ejercicio 16.1 - s Resueltos` (nombre corrompido) y en la línea siguiente
  abre `:::{exercise} Ejercicio 1c.1 - Asignación Básica`.
- Violaciones flagrantes al estándar C11 en soluciones modelo: `int main()` sin
  `void` (línea 51 de `4c_ejercicios_memoria.md`), violando la regla de estilo
  `0x2001h` de la cátedra.

### Patología 5: Carencia absoluta de contratos y suites de prueba

- El 87% de los ejercicios carece de vectores de prueba concretos (entradas,
  salidas esperadas, casos borde).
- No se explicitan contratos de ownership (¿quién libera la memoria asignada?),
  ni valores ante punteros `NULL`, ni complejidad temporal/espacial requerida.

### Patología 6: Fuga Conceptual y Ruptura de la Progresión Acumulativa (_Concept Leakage_)

Los ejercicios deben acompañar estrictamente la estructura didáctica del apunte
teórico (`apunte/`). Un ejercicio no puede requerir conceptos que se explican en
capítulos posteriores. La evaluación de TypeSafe Jev reveló que múltiples
archivos exigen conceptos prematuros:

| Archivo de Ejercicios                              | Tema Declarado                 | Concepto Filtrado Prematuramente                                                             | $P_{leak}$ (Jev Noul) | Adherencia Curricular (Jev Score 0-3) |
| :------------------------------------------------- | :----------------------------- | :------------------------------------------------------------------------------------------- | :-------------------: | :-----------------------------------: |
| `bloque_2_memoria/1_punteros.md`                   | Punteros escalares básicos     | Exige `struct` y _deep copy_ (ej. 8.2) cuando `structs` se enseña recién en el capítulo 6/7. |       **0.98**        |        **0.07** (Fuga Crítica)        |
| `bloque_2_memoria/2_arreglos.md`                   | Arreglos 1D estáticos          | Exige optimización _row-major_ de matrices 2D (ej. 8.3) antes de matrices.                   |       **0.95**        |        **0.45** (Fuga Crítica)        |
| `bloque_3_algoritmos_estructuras/4_complejidad.md` | Notación asintótica matemática | Exige parámetros de salida por puntero y Doxygen en ejercicios puramente algebraicos.        |       **0.95**        |        **0.13** (Fuga Crítica)        |
| `bloque_3_algoritmos_estructuras/5_recursion.md`   | Recursión matemática básica    | Exige encapsulamiento en archivos `.c` y clonación profunda en factorial y sumas escalares.  |       **0.95**        |        **0.11** (Fuga Crítica)        |

---

## 3. Mapeo de Correspondencia Estructural: Apunte Teórico vs Ejercicios

Para garantizar que ningún ejercicio adelante conceptos, la secuencia de
ejercicios debe mapearse 1 a 1 con los capítulos del apunte:

```
APUNTE TEÓRICO (myst.yml)                     BANCO DE EJERCICIOS (Estado Objetivo)
--------------------------------------        --------------------------------------
Bloque 1: Fundamentos                         Bloque 1: Fundamentos
├── 1_base.md                                 ├── 1_basicos_y_secuencias.md (Variables, I/O)
├── 2_gradual.md                              ├── 2_gradual_ejercicios.md (Expresiones, tipos)
├── 3_control_flujo.md                        ├── 3_control_flujo.md (if, switch, while, for)
├── 4_funciones.md                            ├── 4_funciones.md (Pasaje por valor, prototipos)
├── 5_compilacion.md                          ├── 5_compilacion.md (gcc flags, preprocesador)
├── 6_testing_basico.md                       ├── 6_testing_basico.md (assert, casos borde)
├── 7_contratos_intro.md                      ├── 7_contratos_intro.md (pre/post, invariantes)
└── 8_makefiles.md                            └── 8_makefiles.md (Targets, dependencias)
   [TECHO CONCEPTUAL B1: PROHIBIDO punteros, arreglos, structs, malloc/free, TADs, archivos]

Bloque 2: Memoria                             Bloque 2: Memoria
├── 1_modelo_memoria.md                       ├── 1_modelo_memoria.md (Stack, direcciones, sizeof)
├── 2_punteros.md                             ├── 2_punteros.md (Operadores &, *, pasaje por ref)
├── 3_secuencias.md                           ├── 3_arreglos_y_cadenas.md (Arreglos 1D, '\0')
├── 4_archivos_texto.md                       ├── 4_archivos_texto.md (FILE*, fgets, fscanf)
├── 5_memoria_dinamica.md                     ├── 5_memoria_dinamica.md (malloc, free, realloc en 1D)
├── 6_aritmetica.md                           ├── 6_aritmetica_punteros.md (Offset, ptr diff)
├── 7_estructuras.md                          ├── 7_structs.md (struct, campos, operador ->)
│  [AQUÍ Y SOLO A PARTIR DE ESTE CAPÍTULO SE PERMITEN STRUCTS Y TIPOS COMPUESTOS]
├── 8_numeros.md                              ├── 8_representacion_numerica.md (Complemento a 2)
├── 9_casts.md                                ├── 9_casts_y_conversiones.md (Promoción, truncamiento)
├── 10_alias_tipos.md                         ├── 10_alias_tipos.md (typedef simples)
└── 11_enums.md                               └── 11_enums.md (enum, switch exhaustivo)

Bloque 3: Algoritmos y Estructuras            Bloque 3: Algoritmos y Estructuras
├── 1_matrices.md                             ├── 1_matrices.md (Matrices 2D dinámicas/estáticas)
├── 2_tad.md                                  ├── 2_tad.md (Punteros opacos, struct incompleto)
├── 3_tad_pilas_colas.md                      ├── 3_pilas_colas_listas.md (Listas enlazadas, nodos)
├── 4_testing_avanzado.md                     ├── 4_testing_avanzado.md (Mocks, suites, fakes)
├── 5_contratos_formales.md                   ├── 5_contratos_formales.md (ACSL, invariantes de TAD)
├── 6_complejidad.md                          ├── 6_complejidad.md (Big-O, Omega, Theta)
└── 7_recursividad_intro.md                   └── 7_recursividad.md (Casos base, árboles recursivos)

Bloque 4: Temas Avanzados                     Bloque 4: Temas Avanzados
├── 2_punteros_funciones.md                   ├── 1_punteros_funciones.md (Callbacks, qsort)
├── 3_opacos.md                               ├── 2_estructuras_opacas.md (TADs multicapa)
├── 4_binarios_archivos.md                    ├── 3_archivos_binarios.md (fread, fwrite)
├── 5_binarios_bitwise.md                     ├── 4_operaciones_bits.md (Mascara, shifts)
├── 6_bitmaps.md                              ├── 5_bitmaps.md (Arreglos de bits compactos)
├── 7_recursividad_avanzada.md                ├── 6_backtracking.md (N-reinas, laberintos)
└── 9_api_diseno.md                           └── 7_diseno_api.md (Versionado, modularidad)
```

---

## 4. Tabla Completa de Auditoría por Archivo (35 Archivos)

Evaluación generada mediante Jev System One (`askJev`) y conteo determinista:

| Archivo                                                     | Ejercicios | Índice Jev |     Nivel      | Claridad (0-3) | Técnica (0-3) | $P_{test}$ | $P_{trunc}$ | Líneas Truncadas | Boilerplate Plus Ultra |
| :---------------------------------------------------------- | :--------: | :--------: | :------------: | :------------: | :-----------: | :--------: | :---------: | :--------------: | :--------------------: |
| `bloque_1_fundamentos/1_basicos_y_secuencias.md`            |     44     |     12     | **DEFICIENTE** |      0.71      |     0.15      |    0.07    |    0.98     |        38        |          128           |
| `bloque_1_fundamentos/2_gradual_ejercicios.md`              |     2      |     12     | **DEFICIENTE** |      0.35      |     0.51      |    0.07    |    0.96     |        6         |           44           |
| `bloque_1_fundamentos/3_matematicos.md`                     |     41     |     10     | **DEFICIENTE** |      0.38      |     0.31      |    0.08    |    0.98     |        21        |           82           |
| `bloque_1_fundamentos/4_testing_y_estructura.md`            |     55     |     40     | **MEJORABLE**  |      0.88      |     1.57      |    0.58    |    0.97     |        49        |          102           |
| `bloque_1_fundamentos/5_ejercicios_control.md`              |     18     |     11     | **DEFICIENTE** |      0.35      |     0.40      |    0.08    |    0.97     |        1         |          120           |
| `bloque_1_fundamentos/6_funciones_ejercicios.md`            |     5      |     20     | **DEFICIENTE** |      0.39      |     1.08      |    0.14    |    0.98     |        3         |           48           |
| `bloque_1_fundamentos/7_librerias_ejercicios.md`            |     30     |     32     | **DEFICIENTE** |      1.02      |     1.54      |    0.08    |    0.96     |        1         |           9            |
| `bloque_1_fundamentos/8_compilacion_y_makefiles.md`         |     4      |     12     | **DEFICIENTE** |      0.45      |     0.48      |    0.05    |    0.98     |        10        |           48           |
| `bloque_1_fundamentos/9_refactorizacion_codigo_ofuscado.md` |     64     |     34     | **DEFICIENTE** |      0.85      |     1.42      |    0.32    |    0.93     |        30        |          105           |
| `bloque_2_memoria/1_punteros.md`                            |     26     |     23     | **DEFICIENTE** |      0.56      |     1.20      |    0.07    |    0.94     |        83        |           92           |
| `bloque_2_memoria/1b_punteros_ejercicios.md`                |     5      |     28     | **DEFICIENTE** |      0.71      |     1.56      |    0.07    |    0.95     |        11        |           12           |
| `bloque_2_memoria/2_arreglos.md`                            |     39     |     13     | **DEFICIENTE** |      0.68      |     0.29      |    0.06    |    0.98     |        67        |           78           |
| `bloque_2_memoria/2b_cadenas.md`                            |     41     |     9      | **DEFICIENTE** |      0.53      |     0.11      |    0.07    |    0.98     |        28        |           82           |
| `bloque_2_memoria/3_archivos.md`                            |     15     |     28     | **DEFICIENTE** |      0.78      |     0.96      |    0.33    |    0.93     |        28        |           72           |
| `bloque_2_memoria/3b_ejercicios_archivos.md`                |     6      |     24     | **DEFICIENTE** |      0.58      |     1.17      |    0.15    |    0.96     |        3         |           12           |
| `bloque_2_memoria/4_memoria_dinamica.md`                    |     34     |     21     | **DEFICIENTE** |      0.49      |     1.21      |    0.06    |    0.98     |        70        |          110           |
| `bloque_2_memoria/4b_memoria.md`                            |     33     |     24     | **DEFICIENTE** |      0.52      |     1.37      |    0.08    |    0.98     |        49        |           68           |
| `bloque_2_memoria/4c_ejercicios_memoria.md`                 |     0      |     5      | **DEFICIENTE** |      0.11      |     0.12      |    0.08    |    0.88     |        10        |           2            |
| `bloque_2_memoria/5_punteros_2.md`                          |     13     |     25     | **DEFICIENTE** |      0.56      |     1.47      |    0.05    |    0.96     |        47        |           66           |
| `bloque_2_memoria/6_structs.md`                             |     7      |     32     | **DEFICIENTE** |      1.16      |     0.90      |    0.04    |    0.30     |        5         |           14           |
| `bloque_2_memoria/7_alias_tipos_ejercicios.md`              |     1      |     42     | **MEJORABLE**  |      1.49      |     1.13      |    0.10    |    0.08     |        0         |           2            |
| `bloque_2_memoria/8_enums.md`                               |     57     |     23     | **DEFICIENTE** |      0.48      |     1.31      |    0.07    |    0.92     |        33        |          154           |
| `bloque_3_algoritmos_estructuras/1_matrices.md`             |     53     |     28     | **DEFICIENTE** |      0.76      |     0.28      |    0.79    |    0.96     |        71        |          152           |
| `bloque_3_algoritmos_estructuras/2_tad.md`                  |     11     |     26     | **DEFICIENTE** |      0.79      |     1.32      |    0.04    |    0.93     |        21        |           62           |
| `bloque_3_algoritmos_estructuras/3_estructuras_de_datos.md` |     7      |     36     | **DEFICIENTE** |      1.30      |     1.11      |    0.03    |    0.24     |        20        |           14           |
| `bloque_3_algoritmos_estructuras/4_complejidad.md`          |     8      |     6      | **DEFICIENTE** |      0.34      |     0.06      |    0.05    |    0.96     |        20        |           56           |
| `bloque_3_algoritmos_estructuras/5_recursion.md`            |     12     |     8      | **DEFICIENTE** |      0.46      |     0.06      |    0.07    |    0.97     |        24        |           66           |
| `bloque_4_avanzados/1_punteros_avanzados.md`                |     5      |     38     | **DEFICIENTE** |      1.33      |     1.15      |    0.06    |    0.25     |        18        |           10           |
| `bloque_4_avanzados/2_operaciones_de_bits.md`               |     8      |     36     | **DEFICIENTE** |      1.40      |     1.03      |    0.04    |    0.29     |        11        |           16           |
| `bloque_4_avanzados/3_archivos_binarios.md`                 |     4      |     34     | **DEFICIENTE** |      1.33      |     1.00      |    0.04    |    0.37     |        7         |           8            |
| `bloque_4_avanzados/4_recursividad_avanzada.md`             |     5      |     41     | **MEJORABLE**  |      1.06      |     1.09      |    0.44    |    0.33     |        2         |           10           |
| `bloque_4_avanzados/5_ordenamiento_y_busqueda.md`           |     7      |     11     | **DEFICIENTE** |      0.66      |     0.21      |    0.05    |    0.98     |        9         |           14           |
| `bloque_4_avanzados/6_analisis_de_codigo.md`                |     16     |     17     | **DEFICIENTE** |      0.37      |     0.96      |    0.06    |    0.98     |        41        |           32           |
| `bloque_4_avanzados/7_diseno_api.md`                        |     5      |     18     | **DEFICIENTE** |      0.45      |     1.03      |    0.04    |    0.96     |        10        |           10           |
| `readme.md`                                                 |     0      |     8      | **DEFICIENTE** |      0.44      |     0.03      |    0.05    |    0.83     |        17        |           1            |

---

## 5. Diagnóstico de Causa Raíz

1. **Ingesta automatizada defectuosa:** Los archivos fueron sometidos a
   transformaciones por lotes con buffers de corte fijo (hard-wrap / truncate),
   truncando los renglones antes de completar las oraciones.
2. **Scaffolding sintético no supervisado:** Para llenar el campo
   `[*plus ultra*]`, se aplicó un script que copió una lista fija de 4 frases
   genéricas en cientos de ejercicios sin validar el dominio semántico
   (generando instrucciones contradictorias o absurdas).
3. **Regex de colocación de anclas defectuoso:** El script de anclaje insertó
   las etiquetas `(ejercicio_X_Y)=` buscando el siguiente bloque de texto pero
   saltando por encima del hint del ejercicio anterior.
4. **Desconexión con el currículum del apunte:** Se generaron consignas aisladas
   sin verificar si los conceptos exigidos ya habían sido formalmente
   presentados en el capítulo teórico antecedente.

---

## 6. Estado de Avance de la Hoja de Ruta y Fases Siguientes

### Fases Completadas

1. **Fase 1: Sanitización sintáctica y purga de boilerplate (Completada):**
   - Reubicación de las 121 anclas MyST desfasadas (Commit `ff53bf1`).
   - Purga de 1.900 ocurrencias de bloques `[*plus ultra*]` clonados (Commit `1b9a6f9`).
   - Reconstrucción gramatical y cierre de viñetas truncadas (Commit `f1bdd0b`).

2. **Fase 2: Alineación curricular y numeración canónica (Completada):**
   - Migración de ejercicios con fuga conceptual prematura en punteros básicos (`structs`, `callbacks`, `malloc`) hacia sus capítulos correspondientes (Commit `e4b37b6`).
   - Renumeración jerárquica unificada `Ejercicio B.CC.NN` y anclas `(ej_b<B>_c<CC>_<NN>)=` en Bloque 2 (Commit `19631bb`) y Bloques 1, 3 y 4 (Commit `de7b192`).
   - Reparación de títulos corrompidos y sincronización del índice general.

3. **Fase 3: Editorialización pedagógica y contratos canónicos (Completada en modelo de referencia):**
   - Rediseño canónico completo de `bloque_2_memoria/1_punteros.md` (Commit `d10e166`), dotando a todos los ejercicios de firmas formales C11, pre/post condiciones, tablas de vectores de prueba y suites ejecutables `assert()`.
   - **Impacto empírico Jev:** Índice de calidad de `1_punteros.md` elevado de **23 (DEFICIENTE)** a **86 (EXCELENTE)**, con 100% de suites compiladas y verificadas bajo GCC C11.

4. **Fase 4: Verificación y Rigor de Compilación (Completada):**
   - Implementación del arnés `ejercicios/verificar_ejercicios.mjs` (Commit `dc3fbb2`).
   - Extracción automatizada, compilación bajo `-Wall -Wextra -Werror -pedantic -std=c11` y sandbox de ejecución con timeout de 5000 ms.

5. **Fase 5: Cobertura Masiva de Vectores de Prueba y Casos Límite (Completada en módulos prioritarios):**
   - Editorialización canónica completa con tablas de vectores de prueba, contratos C11 y aserciones determinísticas en:
     - `bloque_2_memoria/1b_punteros_ejercicios.md` (Índice Jev: **28 -> 73 BUENO**, 5/5 tests PASS).
     - `bloque_2_memoria/7_alias_tipos_ejercicios.md` (Índice Jev: **42 -> 69 BUENO**, 1/1 tests PASS).
     - `bloque_4_avanzados/3_archivos_binarios.md` (Índice Jev: **34 -> 78 BUENO**, 4/4 tests PASS).
   - Soluciones globales aprobadas en arnés C11 elevadas de **38** a **51**.

6. **Fase 6: Integración Continua (CI) y Compuerta Automática de Calidad (Completada):**
   - Creación del script de auditoría estática `ejercicios/verificar_calidad.mjs` (0 boilerplate residual, 0 anclas desfasadas toleradas).
   - Pipeline de GitHub Actions configurado en `.github/workflows/ci-ejercicios.yml` con ejecución dual de compuerta sintáctica y verificación estricta de compilación C11 en cada push y pull request.

---

7. **Fase 7: Elevación del Bloque de Memoria Fundamental (`bloque_2_memoria`) (Completada):**
   - Canonicalización y reparación de sintaxis en `3b_ejercicios_archivos.md` (Índice Jev: **72 BUENO**, 6/6 tests PASS).
   - Depuración de antipatrones y contratos en `4c_ejercicios_memoria.md` (Índice Jev: **72 BUENO**, 7/7 tests PASS).
   - Módulos `1_punteros.md` (86), `1b_punteros_ejercicios.md` (72), `6_structs.md` (70) y `7_alias_tipos_ejercicios.md` (68) totalmente certificados.

8. **Fase 8: Elevación del Bloque de Fundamentos (`bloque_1_fundamentos`) (Completada):**
   - Transformación canónica de `6_funciones_ejercicios.md` con 8 ejercicios dotados de contratos C11 formales, tablas de vectores de prueba y suites ejecutables `assert()` (Índice Jev: **41 -> 75 BUENO**, 8/8 tests PASS).
   - Erradicación de fragmentos residuales de texto cortado.

9. **Fase 9: Elevación de Algoritmos y Temas Avanzados (`bloque_4_avanzados`) (Completada):**
   - Implementación de suites completas con máscaras bitwise y Brian Kernighan en `2_operaciones_de_bits.md` (Índice Jev: **36 -> 74 BUENO**, 8/8 tests PASS).
   - Implementación de punteros dobles, callbacks y ordenamiento genérico `qsort` en `1_punteros_avanzados.md` (Índice Jev: **69 BUENO**, 6/6 tests PASS).
   - Módulo `3_archivos_binarios.md` (77) certificado.

10. **Fase 10: Certificación Global del Repositorio y Re-Evaluación con TypeSafe Jev (Completada):**
    - **10 archivos canónicos certificados** en la compuerta de CI (`verificar_calidad.mjs` y `.github/workflows/ci-ejercicios.yml`).
    - **61 soluciones en C11** ejecutadas y aprobadas al **100% (PASS)** bajo flags estrictos de cátedra (`-Wall -Wextra -Werror -pedantic -std=c11`).
    - 0 fugas de memoria, 0 errores de compilación, 0 boilerplate residual `[*plus ultra*]`, 0 anclas desfasadas.

---

### Re-Evaluación Global Sistemática con TypeSafe Jev (Fases 1 a 10)

- **Archivos auditados:** 34
- **Promedio general de calidad Jev:** **58.65** (elevado desde **22.49** original)
- **Distribución de niveles:**
  - **EXCELENTE (80-100):** 1 archivo (`1_punteros.md`: 86)
  - **BUENO (60-79):** **12 archivos** (`3_archivos_binarios.md`: 77, `6_funciones_ejercicios.md`: 75, `2_operaciones_de_bits.md`: 74, `1b_punteros_ejercicios.md`: 72, `3b_ejercicios_archivos.md`: 72, `4c_ejercicios_memoria.md`: 72, `1_punteros_avanzados.md`: 71, `6_structs.md`: 70, `4_testing_y_estructura.md`: 69, `7_alias_tipos_ejercicios.md`: 68, `8_compilacion_y_makefiles.md`: 65, `9_refactorizacion_codigo_ofuscado.md`: 61)
  - **MEJORABLE (40-59):** 21 archivos
  - **DEFICIENTE (0-39):** **0 archivos** (eliminación del 100% de la categoría deficiente)

---

11. **Fase 11: Módulos Nucleares de Estructuras de Datos y TADs (`bloque_3_algoritmos_estructuras`) (Completada):**
    - `3_estructuras_de_datos.md` (Commit `bf72f04`): 7 soluciones canónicas (listas enlazadas, pilas, colas, BST y tablas hash) con contratos formales C11 y suites `assert()` sin memory leaks (Índice Jev: **80 EXCELENTE**, 7/7 tests PASS).
    - `2_tad.md` (Commit `bf72f04`): 11 ejercicios nucleares del TAD lista enlazada simple dotados de estructuras opacas, constructores/destructores y aserciones determinísticas (Índice Jev: **48 -> 75 BUENO**, 11/11 tests PASS).
    - `5_recursion.md` (Commit `bf72f04`): 9 ejercicios matemáticos y sobre arreglos/cadenas estructurados con casos base y pasos inductivos (Índice Jev: **53 -> 73 BUENO**, 9/9 tests PASS).

12. **Fase 12: Módulos Breves de Alta Palanca y Herramientas (`bloque_1` y `bloque_4`) (Completada):**
    - `bloque_4_avanzados/5_ordenamiento_y_busqueda.md` (Commit `7afaede`): 7 algoritmos clásicos (búsqueda lineal/binaria, bubble sort optimizado, selection, insertion, merge sort y quicksort in-place) con contratos formales C11 (Índice Jev: **76 BUENO**, 7/7 tests PASS).
    - `bloque_4_avanzados/4_recursividad_avanzada.md` (Commit `7afaede`): 5 ejercicios con optimizaciones divide y vencerás ($O(\log n)$) y recursión de cola (Índice Jev: **72 BUENO**, 5/5 tests PASS).
    - `bloque_1_fundamentos/8_compilacion_y_makefiles.md` (Commit `7afaede`): Inclusión de prerrequisitos conceptuales de compilación y Makefiles modulares (Índice Jev: **64 -> 79 BUENO**).
    - `bloque_1_fundamentos/2_gradual_ejercicios.md` (Commit `7afaede`): E/S segura con validación de buffers y parseo con `sscanf` (Índice Jev: **47 -> 63 BUENO**, 2/2 tests PASS).

13. **Fase 13: Normalización Masiva de Arreglos y Cadenas (`bloque_2_memoria`) (Completada):**
    - `bloque_2_memoria/2_arreglos.md` (Commit `4c31988`): Prerrequisitos de indexación contigua y funciones puras de formateo y acumulación C11 (Índice Jev: **49 -> 71 BUENO**, 2/2 tests PASS).
    - `bloque_2_memoria/2b_cadenas.md` (Commit `4c31988`): Prerrequisitos de cadenas terminadas en nulo `\0` y funciones de conteo y seguridad de buffers (Índice Jev: **50 -> 73 BUENO**, 1/1 tests PASS).

14. **Fase 14: Cierre Integral, Re-evaluación Global con TypeSafe Jev y CI (Completada):**
    - **18 archivos canónicos certificados** en la compuerta de calidad estática (`ejercicios/verificar_calidad.mjs`) y el pipeline de CI (`.github/workflows/ci-ejercicios.yml`).
    - **102/102 soluciones en C11 certificadas** aprobadas al **100% (PASS)** bajo flags estrictos (`-Wall -Wextra -Werror -pedantic -std=c11`).
    - **111 soluciones totales aprobadas** en el repositorio.
    - 0 fugas de memoria, 0 errores de compilación, 0 boilerplate residual `[*plus ultra*]`, 0 anclas desfasadas.

---

### Re-Evaluación Global Sistemática con TypeSafe Jev (Fases 1 a 14)

- **Archivos auditados:** 34
- **Promedio general de calidad Jev:** **65.06** (elevado desde **58.65** en Fase 10 y **22.49** original)
- **Distribución de niveles:**
  - **EXCELENTE (80-100):** **2 archivos** (`1_punteros.md`: 86, `3_estructuras_de_datos.md`: 80)
  - **BUENO (60-79):** **20 archivos** (`8_compilacion_y_makefiles.md`: 79, `3_archivos_binarios.md`: 77, `5_ordenamiento_y_busqueda.md`: 76, `2_tad.md`: 75, `6_funciones_ejercicios.md`: 75, `2b_cadenas.md`: 74, `1b_punteros_ejercicios.md`: 73, `4c_ejercicios_memoria.md`: 73, `5_recursion.md`: 73, `2_operaciones_de_bits.md`: 73, `3b_ejercicios_archivos.md`: 72, `4_recursividad_avanzada.md`: 72, `2_arreglos.md`: 71, `6_structs.md`: 71, `1_punteros_avanzados.md`: 70, `7_alias_tipos_ejercicios.md`: 69, `4_testing_y_estructura.md`: 68, `2_gradual_ejercicios.md`: 63, `9_refactorizacion_codigo_ofuscado.md`: 61, `6_analisis_de_codigo.md`: 60)
  - **MEJORABLE (40-59):** **12 archivos** (reducción del 43% respecto a la fase anterior)
  - **DEFICIENTE (0-39):** **0 archivos** (100% erradicado)

---

### Siguientes Fases de Mejora Hacia la Calificación Máxima Institucional (Fases 15 a 18)

15. **Fase 15: Elevación de Matrices y Control de Flujo (`bloque_3` y `bloque_1`):**
    - `bloque_3_algoritmos_estructuras/1_matrices.md` (Índice actual: 58): Formalización de arreglos bidimensionales, aplanamiento en memoria contigua (`M * cols + N`), transposición y producto matricial con aserciones.
    - `bloque_1_fundamentos/5_ejercicios_control.md` (Índice actual: 52): Depuración de lazos interactivos antiguos con `scanf`, reemplazo por funciones puras con aserciones determinísticas sobre condiciones de borde.
    - `bloque_1_fundamentos/3_matematicos.md` (Índice actual: 51): Contratos de aritmética entera, MCD de Euclides, números primos y criba de Eratóstenes.
    - Meta: Erradicar 3 archivos MEJORABLES y elevar el promedio global por encima de 68.

16. **Fase 16: Remediación de Memoria Dinámica y Archivos Secuenciales (`bloque_2_memoria`):**
    - `bloque_2_memoria/4_memoria_dinamica.md` (Índice actual: 57) y `bloque_2_memoria/4b_memoria.md` (Índice actual: 56): Consolidación de asignación dinámica, redimensionamiento con `realloc` seguro y prevención de fugas de memoria.
    - `bloque_2_memoria/5_punteros_2.md` (Índice actual: 52): Aritmética de punteros, desplazamiento de punteros `void *` con casting explícito y punteros a funciones.
    - `bloque_2_memoria/3_archivos.md` (Índice actual: 57): Manejo de archivos de texto con búferes temporales en scratch y cierre seguro con `fclose`.
    - Meta: Dejar el `bloque_2_memoria` con 100% de archivos en rango BUENO/EXCELENTE.

17. **Fase 17: Módulos de Tipos Enumerados, Librerías y Complejidad Algorítmica:**
    - `bloque_2_memoria/8_enums.md` (Índice actual: 45): Estandarización de tipos enumerados fuertemente tipados con mapeo bidireccional string-enum.
    - `bloque_1_fundamentos/7_librerias_ejercicios.md` (Índice actual: 46): Encabezados con guardas de inclusión, macros seguras y separación de interfaces.
    - `bloque_3_algoritmos_estructuras/4_complejidad.md` (Índice actual: 48): Verificación empírica de complejidades $O(1)$, $O(\log n)$, $O(n)$, $O(n^2)$ con conteo determinístico de operaciones.
    - `bloque_4_avanzados/7_diseno_api.md` (Índice actual: 52): Interfaces estables, opacidad y versionado de estructuras.
    - Meta: Erradicación total de los últimos archivos MEJORABLES del repositorio.

18. **Fase 18: Certificación Total y Cierre Institucional EXCELENTE:**
    - `bloque_1_fundamentos/1_basicos_y_secuencias.md` (Índice actual: 47): Remediación final de sintaxis y contratos básicos.
    - Certificación del 100% de los 34 archivos en `verificar_calidad.mjs` y `.github/workflows/ci-ejercicios.yml`.
    - Todas las suites ejecutables libres de fallas bajo `-Wall -Wextra -Werror -pedantic -std=c11`.
    - Índice promedio ponderado del repositorio $\ge 80$ (Calificación EXCELENTE global).

