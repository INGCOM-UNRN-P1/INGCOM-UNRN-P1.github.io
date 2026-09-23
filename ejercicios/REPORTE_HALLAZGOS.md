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

---

### Fases Siguientes de Mejora Continua

4. **Fase 4: Verificación y Rigor de Compilación (Automated C11 Compiler & Test Harness):**
   - Implementar un runner automatizado (`ejercicios/verificar_ejercicios.mjs`) que extraiga dinámicamente cada solución en C embebida en los documentos Markdown.
   - Compilar cada ejercicio en un entorno de sandbox con flags estrictos de cátedra:
     `gcc -Wall -Wextra -Werror -pedantic -std=c11 -fsanitize=address,undefined`
   - Ejecutar los binarios y verificar aserciones unitarias, asegurando ausencia de fugas de memoria y errores de segmentación.

5. **Fase 5: Cobertura Masiva de Vectores de Prueba y Casos Límite:**
   - Escalar la plantilla canónica de `MARCO_EDITORIAL.md` a las 34 guías de ejercicios restantes en Bloques 1, 2, 3 y 4.
   - Dotar a cada consigna de su tabla de vectores de prueba obligatorios (normales, bordes `NULL`/`0`/desbordamientos y errores).

6. **Fase 6: Integración Continua (CI) y Compuerta Automática de Calidad Jev:**
   - Configurar pipeline automatizado (GitHub Actions / pre-commit hook) que ejecute `verificar_ejercicios.mjs` y `jev-doc-quality.mjs`.
   - Bloquear cualquier fusión o commit que introduzca texto truncado, anclas desfasadas, o filtración conceptual prematura ($P_{leak} > 0.05$).

