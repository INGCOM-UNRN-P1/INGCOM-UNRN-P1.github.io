# Informe de Calidad y Estado Actual del Apunte (Jev System One)

**Fecha de ejecución**: 21 de septiembre de 2026  
**Herramienta**: TypeSafe Jev (`jev-latest` / `jev-1.13.0`) via [`scripts/jev-doc-quality.mjs`](file:///home/mrtin/.gemini/config/skills/jev-accelerator/scripts/jev-doc-quality.mjs)  
**Alcance**: 39 documentos Markdown en [`apunte/`](file:///home/mrtin/dev/tools/apunte/apunte)  
**Datos crudos**: [`mejora/evaluacion_inicial.json`](file:///home/mrtin/dev/tools/apunte/mejora/evaluacion_inicial.json)

---

## 1. Métricas Globales Consolidadas

| Métrica | Valor Obtenido | Rango de Referencia |
|---|:---:|:---:|
| **Total de capítulos evaluados** | 39 | 39 |
| **Índice Global Promedio** | **54.21 / 100** | Nivel: **MEJORABLE** |
| **Distribución por Nivel** | 10 BUENO (25.6%) \| 24 MEJORABLE (61.5%) \| 5 DEFICIENTE (12.8%) | Objetivo: ≥ 85% BUENO/EXCELENTE |
| **Documentos sin prerrequisitos explícitos** | **33 de 39 (84.6%)** | Probabilidad `hasClearPrerequisites` ≤ 0.60 |
| **Documentos sin ejemplos ejecutables inmediatos** | **13 de 39 (33.3%)** | Probabilidad `hasRunnableExamples` ≤ 0.60 |

### Promedio por Bloque Temático

| Bloque | Cantidad Archivos | Índice Calidad Promedio | Diagnóstico Principal |
|---|:---:|:---:|---|
| **Bloque 1: Fundamentos** | 8 | **56.8** | Fuerte disparidad: compilación sólida (76), pero funciones (37) carece de scaffolding ejecutable inicial. |
| **Bloque 2: Memoria** | 11 | **57.4** | Aritmética y structs destacados (67, 66), pero modelo de memoria (38) tiene déficit de completitud técnica. |
| **Bloque 3: Algoritmos y Estructuras** | 7 | **50.7** | Bloque más rezagado del contenido troncal. TAD conceptual (33) y complejidad (40) carecen de contexto práctico verificable. |
| **Bloque 4: Tópicos Avanzados** | 12 | **53.6** | Hilos (71) y bitwise (68) sólidos; APIs (44), archivos binarios (46) e índice (15) reducen el promedio. |
| **Índices Generales** | 1 | **31.0** | `indice.md` actúa como sumario estático sin prerequisitos de cursada ni mapa de dependencias. |

---

## 2. Top Deficiencias Críticas Detectadas

Los siguientes capítulos obtuvieron calificación **DEFICIENTE** (< 40 puntos):

1. **[`apunte/bloque_4_avanzados/1_indice_avanzados.md`](file:///home/mrtin/dev/tools/apunte/apunte/bloque_4_avanzados/1_indice_avanzados.md)** (15/100)
   - *Causa*: Lista de viñetas pura, sin explicaciones conceptuales, sin código, ni objetivos formativos.
2. **[`apunte/indice.md`](file:///home/mrtin/dev/tools/apunte/apunte/indice.md)** (31/100)
   - *Causa*: Falta de entorno requerido explícito, sin diagramas de flujo de aprendizaje ni enlaces a herramientas cátedra.
3. **[`apunte/bloque_3_algoritmos_estructuras/2_tad.md`](file:///home/mrtin/dev/tools/apunte/apunte/bloque_3_algoritmos_estructuras/2_tad.md)** (33/100)
   - *Causa*: Rigidez teórica sin snippets de contratos o interfaces funcionales en sus primeros bloques.
4. **[`apunte/bloque_1_fundamentos/4_funciones.md`](file:///home/mrtin/dev/tools/apunte/apunte/bloque_1_fundamentos/4_funciones.md)** (37/100)
   - *Causa*: Trunca el inicio en discusión formal matemática sin un ejemplo inicial elemental de compilación directa y trazado de pila.
5. **[`apunte/bloque_2_memoria/1_modelo_memoria.md`](file:///home/mrtin/dev/tools/apunte/apunte/bloque_2_memoria/1_modelo_memoria.md)** (38/100)
   - *Causa*: Explicación verbal abstracta de memoria virtual sin esquemas ASCII de Stack/Heap ni comandos directos de inspección (`size`, `objdump`, `pmap`).

---

## 3. Patrones Estructurales Sistémicos

A partir de las respuestas probabilísticas de los clasificadores `noul` y `score`:
1. **Falta de Prerrequisitos Formales (84.6%)**: Los documentos inician directamente en prosa narrativa sin un bloque estandarizado de `Prerrequisitos`, `Objetivos de Aprendizaje` y `Comandos de Compilación esperados`.
2. **Código sin Scaffolding Inmediato en Primeras Secciones**: El truncamiento de los primeros 4000 caracteres evaluado por el modelo detecta que la introducción pospone excesivamente el primer bloque de código funcional reproducible.
3. **Comandos de GCC Cátedra Ausentes**: Varios capítulos discuten teoría de C sin explicitar la bandera de compilación estricta de la cátedra (`-Wall -Wextra -std=c11 -pedantic`).

---

## 4. Auditoría pedagógica posterior (`sc_pedagogia`)

**Fecha**: 21 de septiembre de 2026  
**Alcance**: los 39 capítulos de `apunte/`, su estructura de apertura, enlaces
internos, extensión y recursos de aprendizaje. Esta revisión no reemplaza la
línea de base de Jev: evalúa la calidad didáctica del estado actual tras las
fases 1 y 2.

### Fase A: Crítica diagnóstica

#### Transposición didáctica y rigor conceptual

1. **La progresión declarada no siempre coincide con la progresión real.** Hay
   22 capítulos sin prerrequisitos explícitos y 24 sin objetivos observables.
   El estudiante debe inferir qué saber previo activar y qué desempeño se espera,
   en especial en memoria, punteros, testing, matrices e hilos. Eso convierte la
   dificultad propia de C en carga extrínseca evitable.
2. **Algunas aperturas usan rótulos que no enseñan.** “Referencias y Lecturas
   Complementarias”, “Lecturas Recomendadas” y “Ventajas y Desventajas” aparecen
   como encabezado principal antes de introducir el problema. No ofrecen un
   organizador previo ni explican el propósito del capítulo; deben convertirse en
   títulos conceptuales y dejar las referencias para el cierre.
3. **La serialización binaria exige una advertencia de portabilidad.** Presentar
   el volcado directo de un `struct` como reconstrucción inmediata puede inducir
   un modelo mental incorrecto: padding, endianness, tamaño de tipos y punteros
   hacen que ese formato no sea portable ni adecuado para persistir punteros.
4. **Las analogías deben declarar su límite.** Tratar un socket como “archivo
   especial” ayuda a introducir `read`/`write`, pero no explica protocolo,
   límites de mensajes ni que TCP es un flujo de bytes. Sin ese límite favorece
   errores frecuentes de framing y de manejo parcial de E/S.

#### Secuenciación y carga cognitiva

1. **Capítulos muy extensos sin hitos tempranos.** TAD (2853 líneas),
   estructuras (2282), memoria dinámica (2259), compilación (2238) y archivos
   de texto (2147) exponen mucho contenido antes de solicitar una acción breve
   de recuperación o comprobación. La segmentación por subtítulos no basta si
   no existe una pausa con una meta, un ejemplo y una verificación.
2. **Las introducciones vacías o genéricas rompen la continuidad.** Varios
   capítulos intercalan `Introducción` y `Desarrollo` sin contenido o con un
   título que no corresponde al primer concepto. Esa duplicación aumenta la
   navegación y no reduce la dificultad intrínseca.
3. **La práctica aparece tarde o queda fuera del capítulo.** Hay referencias a
   ejercicios en el repositorio, pero no todos los capítulos cierran con una
   tarea mínima alineada a su objetivo. El lector puede reconocer una definición
   sin llegar a aplicar, trazar o verificar el concepto.

#### Alineación objetivo-contenido y navegabilidad

1. **Faltan criterios de logro uniformes.** Los objetivos añadidos en fases
   previas son una mejora, pero el resto de los capítulos no permite decidir qué
   cuenta como comprensión: explicar, predecir, implementar o depurar.
2. **Hay enlaces relativos obsoletos.** Se detectaron `binarios.md`, `bits.md`
   y `6_tad.md`, que no existen en sus directorios actuales. Un enlace roto
   interrumpe la secuencia justo cuando el texto deriva un prerrequisito.
3. **La plantilla usa un bloque de cita único.** Es legible para dos líneas,
   pero listas largas dentro de la cita se vuelven difíciles de escanear. Para
   capítulos complejos conviene separar “Antes de empezar”, “Vas a poder” y
   “Comprobación” en admonitions breves.

### Fase B: Plan de mejora estructurado

| Prioridad | Refactorización didáctica | Refactorización de formato | Corrección conceptual / evidencia de cierre |
| --- | --- | --- | --- |
| Alta | Añadir prerrequisitos, dos objetivos observables y una comprobación final a los 22 capítulos restantes. | Usar un bloque breve y uniforme al comienzo, antes de la introducción. | Cada objetivo debe usar un verbo verificable: trazar, implementar, justificar o depurar. |
| Alta | Corregir los enlaces de dependencia de Bitmaps y Complejidad. | Sustituir enlaces por los nombres y rutas reales de los capítulos. | `myst build --strict` no debe informar enlaces rotos. |
| Alta | Reescribir los primeros 150–250 palabras de los cinco capítulos más extensos como “problema → ejemplo → explicación”. | Convertir encabezados genéricos en títulos conceptuales; mover referencias al final. | Un lector puede compilar o predecir un resultado antes de la exposición extensa. |
| Media | Insertar microactividades de recuperación después de cada concepto de alta carga: punteros, heap, TAD, complejidad, concurrencia. | Emplear listas numeradas, diagramas de estado y tablas de contraste solo donde aclaren una decisión. | Cada actividad tiene respuesta esperada o criterio de corrección. |
| Media | Declarar los límites de analogías y de la persistencia binaria nativa. | Presentar “útil para / no alcanza para” junto a la analogía. | Binarios distingue formato nativo de formato portable; sockets distingue flujo TCP de mensajes. |
| Baja | Añadir una autoevaluación de salida a cada bloque. | Enlazarla desde el índice de bloque y los ejercicios correspondientes. | La autoevaluación cubre al menos recordar, aplicar y justificar. |

### Línea de base actualizada

La línea de base de Jev sigue siendo histórica y no debe presentarse como una
reevaluación posterior. El inventario estático de esta auditoría registra **39
capítulos**, **17 con prerrequisitos explícitos** y **15 con objetivos
explícitos**. La próxima medición debe ejecutarse una vez terminadas las fases
3 a 6 del plan para comparar resultados homogéneos.

---

## 5. Reevaluación de `bloque_2_memoria` (post-remediación de `mejora_2/`)

**Fecha de ejecución**: 22 de septiembre de 2026
**Herramienta**: la misma (`jev-doc-quality.mjs`, `jev-latest`)
**Alcance**: los 11 capítulos de `apunte/bloque_2_memoria/`, ejecutados con
`node mejora/evaluar_lote.mjs` restringido a ese directorio
**Datos crudos**: [`mejora/evaluacion_bloque2.json`](file:///home/mrtin/dev/tools/apunte/mejora/evaluacion_bloque2.json)

Esta reevaluación se hizo después de que `mejora_2/plan_accion.md` completara
sus Fases 0-4 sobre el bloque (fusión de archivos de ampliación, H1/headings,
enlaces rotos, calidad técnica). No sustituye la reevaluación completa de los
39 capítulos que pide la Fase 7 de este plan (sección 4), pero permite medir
si el trabajo de `mejora_2/` movió la aguja en este bloque específico.

### Resultado agregado

| Métrica | Línea de base (sección 1) | Reevaluación bloque 2 |
| --- | --- | --- |
| Índice promedio del bloque | 57.4 | **70.3** (+12.9) |
| Distribución | mezcla de MEJORABLE/BUENO, `1_modelo_memoria.md` DEFICIENTE (38) | **10 BUENO + 1 EXCELENTE**, cero DEFICIENTE |
| `hasClearPrerequisites` | bajo (patrón del 84.6% sin prerrequisitos, ver sección 3) | **11 de 11 en `true`** |

`1_modelo_memoria.md`, el capítulo señalado como DEFICIENTE (38/100) en la
sección 2 de este informe, pasó a **76/100 (BUENO)**. El trabajo de
`mejora_2/` (agregar H1, fusionar las ampliaciones de MMU/TLB/caché dentro
del capítulo, agregar comandos de observación) coincide con la causa que
este informe había señalado ("explicación verbal abstracta... sin esquemas
ni comandos directos de inspección").

### Detalle por archivo

| Archivo | Índice | Nivel | Pedagógico (/3) | Técnico (/3) | Ejemplo ejecutable | Prerrequisitos | Audiencia |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `1_modelo_memoria.md` | 76 | BUENO | 2.28 | 1.78 | Sí | Sí | intermedio |
| `2_punteros.md` | 61 | BUENO | 2.27 | 1.15 | **No** | Sí | intermedio |
| `3_secuencias.md` | 62 | BUENO | 2.21 | 1.24 | Sí | Sí | principiante |
| `4_archivos_texto.md` | 66 | BUENO | 2.68 | 1.30 | **No** | Sí | intermedio |
| `5_memoria_dinamica.md` | 78 | BUENO | 2.51 | 1.86 | Sí | Sí | intermedio |
| `6_aritmetica.md` | 67 | BUENO | 2.28 | 1.42 | Sí | Sí | intermedio |
| `7_estructuras.md` | 83 | EXCELENTE | 2.76 | 1.89 | Sí | Sí | intermedio |
| `8_numeros.md` | 71 | BUENO | 2.40 | 1.50 | Sí | Sí | intermedio |
| `9_casts.md` | 71 | BUENO | 2.44 | 1.47 | Sí | Sí | intermedio |
| `10_alias_tipos.md` | 72 | BUENO | 2.55 | 1.50 | Sí | Sí | intermedio |
| `11_enums.md` | 66 | BUENO | 2.30 | 1.37 | Sí | Sí | intermedio |

### Hallazgos nuevos de esta reevaluación

1. **`technicalCompleteness` es el eje sistemáticamente débil**: los 11
   archivos puntúan entre 1.15 y 1.89 sobre 3, muy por debajo del eje
   pedagógico (2.21-2.76). El modelo evalúa esto sobre los primeros 4000
   caracteres del archivo (el script trunca ahí antes de consultar a Jev),
   así que el diagnóstico es específicamente sobre **la apertura** de cada
   capítulo, no sobre el capítulo completo.
2. **`2_punteros.md` y `4_archivos_texto.md` puntúan `hasRunnableExamples:
   false`** pese a tener decenas de bloques de código más adelante en el
   archivo. Inspeccionando los primeros 4000 caracteres de cada uno: el
   único código presente ahí es una **declaración aislada sin programa
   completo** (`int *ptr_entero;` en `2_punteros.md`;
   `FILE *puntero_archivo;` en `4_archivos_texto.md`), sin `#include`, sin
   `main()`, sin comando de compilación. El clasificador no lo cuenta como
   "runnable". Este es exactamente el patrón que la Fase A de la sección 4
   de este informe describe como "código sin scaffolding inmediato": el
   primer bloque de código *funcional y reproducible* aparece demasiado
   tarde.
3. La reevaluación **confirma, con una herramienta independiente**, la
   remediación de `mejora_2/plan_accion.md`: agregar H1/anclas, fusionar
   contenido y llenar TODOs pendientes tuvo un efecto medible en
   `pedagogicalClarity` y en `hasClearPrerequisites`, pero no toca
   `technicalCompleteness` cerca de la apertura, que sigue siendo débil.
   Esto corrobora el diagnóstico de la Fase 5 de este plan (sección 4):
   reescribir la apertura de los capítulos largos como
   "problema → ejemplo mínimo compilable → explicación", en vez de agregar
   solo el contrato de prerrequisitos/objetivos.

---

## 6. Reevaluación completa de `apunte/` (57 archivos, post-fix de digest)

**Fecha de ejecución**: 22 de septiembre de 2026
**Herramienta**: `jev-doc-quality.mjs` **modificada** (ver más abajo) vía
`node mejora/evaluar_lote.mjs apunte --out evaluacion_totalidad_post_fix.json`
**Alcance**: los 57 archivos `.md` que hoy existen bajo `apunte/` (39 en la
línea de base original + 18 archivos nuevos, sobre todo ampliaciones de
bloque 3 y la familia 13/14 de bloque 4)
**Datos crudos**: [`mejora/evaluacion_totalidad_post_fix.json`](file:///home/mrtin/dev/tools/apunte/mejora/evaluacion_totalidad_post_fix.json)

Antes de esta corrida se modificó `jev-doc-quality.mjs` (herramienta global en
`~/.gemini/config/skills/jev-accelerator/`, no versionada en este repo): el
truncamiento ingenuo a los primeros 4000 caracteres de cada documento —que
subestimaba `hasRunnableExamples` y `technicalCompleteness` en cualquier
capítulo cuyo primer ejemplo apareciera después del carácter 4000— se
reemplazó por un **digest de todo el documento** (apertura + todo bloque de
código/ejercicio encontrado en cualquier parte del archivo, hasta un
presupuesto de caracteres). El JSON de salida ahora informa `analysis.mode`
(`full`/`digest`) para saber qué se le mostró efectivamente al modelo.

### Resultado agregado

| Métrica | Línea de base (sección 1, 39 docs, truncamiento a 4000) | Esta corrida (57 docs, digest completo) |
| --- | --- | --- |
| Índice promedio global | 54.2 | **64.7** |
| Distribución | 10 BUENO, 24 MEJORABLE, 5 DEFICIENTE | **19 EXCELENTE, 23 BUENO, 1 MEJORABLE, 14 DEFICIENTE** |

La comparación no es 1:1 (esta corrida tiene 18 archivos más que la línea de
base, casi todos ampliaciones nuevas de baja calidad que bajan el promedio
global), pero el patrón por bloque es contundente:

| Bloque | n | Índice promedio | Mín | Máx |
| --- | --- | --- | --- | --- |
| Bloque 1: Fundamentos | 8 | **80.4** | 72 | 85 |
| Bloque 2: Memoria | 11 | **79.6** | 73 | 85 |
| Bloque 3: Algoritmos y Estructuras | 18 | 50.5 | 17 | 82 |
| Bloque 4: Tópicos Avanzados | 19 | 62.9 | 1 | 85 |
| `indice.md` | 1 | 65.0 | — | — |

Bloque 1 y bloque 2 —los dos bloques donde `mejora_2/plan_accion.md` completó
sus Fases 0-4 íntegramente— promedian arriba de 79 y **ningún archivo es
DEFICIENTE**. Bloque 3 y bloque 4 quedan muy por debajo, pero no por sus
capítulos principales:

### Los 14 DEFICIENTE (<40) son, sin excepción, archivos de ampliación

| Índice | Archivo | Diagnóstico ya conocido (`mejora_2/plan_accion.md`) |
| --- | --- | --- |
| 1 | `bloque_4_avanzados/13_struct_avanzado.md` | Archivo vacío (0 bytes) — Fase 7, punto 21 |
| 17 | `bloque_3/1D_fragmentacion_matrices.md` | Placeholder, redundante con `6_aritmetica.md` — Fase 6, punto 20 |
| 23 | `bloque_3/7F_estructuras_opacas.md` | Placeholder — Fase 6, punto 20 |
| 24 | `bloque_3/6D_fragmentacion_matrices.md` | Placeholder, duplica `1D` casi palabra por palabra — Fase 6, punto 20 |
| 25 | `bloque_3/7E_serializacion.md` | Placeholder — Fase 6, punto 20 |
| 25 | `bloque_4/13F_bitfields.md` | Candidato a fusionar en `5_binarios_bitwise.md` — Fase 7, punto 21 |
| 26 | `bloque_3/1B_matrices_vla.md` | Placeholder, redundante con `6_aritmetica.md` — Fase 6, punto 20 |
| 29 | `bloque_3/6A_localidad_representacion.md` | En `myst.yml`, pero igual puntúa bajo — ver hallazgo nuevo abajo |
| 29 | `bloque_4/13B_serializacion.md` | Candidato a integrar si se desarrolla el capítulo 13 — Fase 7, punto 21 |
| 30 | `bloque_4/13E_padding_abi.md` | Candidato a integrar — Fase 7, punto 21 |
| 31 | `bloque_3/1C_matrices3d.md` | Placeholder — Fase 6, punto 20 |
| 34 | `bloque_4/13C_estructuras_opacas.md` | Candidato claro a **eliminar**, redundante con `3_opacos.md` — Fase 7, punto 21 |
| 36 | `bloque_3/1A_matrices_dinamicas.md` | En `myst.yml` y enlazado — ver hallazgo nuevo abajo |
| 36 | `bloque_3/1E_rendimiento_memoria.md` | Contenido real, pero corto — ver hallazgo nuevo abajo |

Y el único MEJORABLE (40-59) es también una ampliación:
`bloque_3/2A_ownership_tads.md` (43/100).

**Ningún capítulo principal (numerado sin letra) del recorrido obligatorio
quedó DEFICIENTE ni MEJORABLE.** Esto es una confirmación cuantitativa e
independiente del diagnóstico central de `mejora_2/informe_calidad.md`: el
problema del apunte no es la calidad del contenido troncal, sino el volumen
de archivos de ampliación sin desarrollar o sin integrar a la navegación.

### Hallazgo nuevo: dos archivos de ampliación "buenos" en `myst.yml` puntúan mal igual

`1A_matrices_dinamicas.md` (36) y `6A_localidad_representacion.md` (29) están
en `myst.yml` y enlazados desde su capítulo principal (según el relevamiento
de la Fase 6), pero puntúan DEFICIENTE de todas formas — a diferencia de
`1F_seguridad_memoria.md` (70, BUENO), que no está en `myst.yml` pero sí tiene
contenido sustancial. Esto sugiere que **estar en la navegación no alcanza**:
`1A` y `6A` son cortos y conceptuales (una fórmula, unos bullets) sin ejemplo
compilable propio ni ejercicio, mientras que `1F` tiene bloque de código y un
mini-ejercicio. Al desarrollar estas ampliaciones (Fase 6, punto 20), agregar
al menos un ejemplo compilable no es opcional: es lo que más pesa en el
índice de estos archivos cortos.

### Confirmación del fix de digest a escala completa

De los 57 archivos, 25 se evaluaron en modo `"digest"` (documento más largo
que el presupuesto, se armó el resumen con apertura + bloques de código de
todo el archivo) y 32 en modo `"full"` (documento completo enviado tal cual,
mayormente las ampliaciones cortas). Ningún archivo se evaluó con el
truncamiento viejo. Bloque 2 (el bloque ya medido antes del fix, sección 5)
subió de 70.3 a **79.6** de promedio al pasar del truncamiento a 4000
caracteres al digest completo — una mejora adicional de +9.3 puntos
atribuible pura y exclusivamente al fix de la herramienta, no a cambios en el
contenido del apunte entre una corrida y la otra.
