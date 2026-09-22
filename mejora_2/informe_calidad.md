# Informe de calidad — `apunte/`

Fecha: 2026-09-22
Alcance: los 4 bloques de `apunte/` (`bloque_1_fundamentos`, `bloque_2_memoria`,
`bloque_3_algoritmos_estructuras`, `bloque_4_avanzados`) más su integración con
`myst.yml` e `indice.md`. Metodología: auditoría manual transversal (enlaces,
anclas, navegación) + cuatro auditorías dedicadas por bloque.

Este informe reemplaza a `./mejora/` (se ignora su contenido según lo pedido).

---

## Resumen ejecutivo

El apunte tiene **contenido técnico sólido y extenso** (más de 1.1 MB de
Markdown, cientos de ejercicios con solución 1:1 bien emparejada en los
capítulos principales), pero arrastra **daño estructural real y visible**
heredado de al menos dos reorganizaciones de carpetas que no se completaron:

- **3 capítulos completos tienen el H1 equivocado**: `bloque_3/2_tad.md`,
  `bloque_3/3_tad_pilas_colas.md` y `bloque_3/6_complejidad.md` abren
  literalmente con el título de su propia sección final ("Resumen de la
  Unidad" / "Referencias y Lecturas Complementarias") pegado como encabezado
  de apertura. Cualquier lector lo ve en el primer renglón.
- **2 archivos tienen fences de MyST corruptos** que probablemente rompen el
  render: `bloque_1/1_base.md` (un ejercicio sin cerrar que se traga el resto
  del capítulo, confirmado con `myst build`) y `bloque_4/5_binarios_bitwise.md`
  (tres ejercicios con profundidad de `:::` inconsistente, texto duplicado y
  una etiqueta de cierre cruzada).
- **1 archivo está completamente vacío** (`bloque_4/13_struct_avanzado.md`,
  0 bytes) y arrastra **7 archivos satélite huérfanos** (13B–14A) invisibles
  en la navegación.
- **Al menos 33 enlaces Markdown rotos** en todo el apunte, casi todos
  apuntando a una estructura de carpetas vieja (`bloque_3_memoria_estatica`,
  `bloque_2_proyectos`, `bloque_4_dinamica_interfaces`,
  `bloque_4_dinamica_indireccion`) que ya no existe.
- **11 archivos de "ampliación" en bloque 3 y 7 en bloque 4** están fuera de
  `myst.yml`: existen en disco pero un lector normal nunca puede llegar a
  ellos. De esos 18, la mitad son placeholders de una o dos oraciones sin
  ejemplo ni ejercicio.
- Hay **residuos de generación automática** sin limpiar: una frase de LLM
  filtrada al cuerpo de `bloque_2/1_modelo_memoria.md:282` ("De acuerdo. A
  continuación...").
- El propio material **viola dos reglas de estilo que la cátedra enseña**:
  `bloque_1/6_testing_basico.md` usa `if` sin llaves (regla `0x1001h`) y las
  soluciones de ejercicios de `bloque_2/5_memoria_dinamica.md` castean el
  retorno de `malloc` (regla `0x300Ah`).

Lo positivo: la fusión de archivos de ampliación hecha en bloque 2 en esta
misma sesión quedó bien integrada (anclas y referencias cruzadas resuelven
correctamente); el catálogo de reglas (`reglas/`) está sano (289 referencias
`{ref}` a códigos `0xXXXXh` en todo el apunte, cero rotas); y los pares
ejercicio/solución de los capítulos principales grandes están casi siempre
1:1 sin huérfanos.

---

## Hallazgos transversales (todo el repositorio)

### CRÍTICO

**T1. 33 enlaces Markdown rotos**, en su mayoría apuntando a nombres de bloque
de una reorganización anterior que ya no existen (`bloque_3_memoria_estatica`,
`bloque_2_proyectos`, `bloque_4_dinamica_interfaces`,
`bloque_4_dinamica_indireccion`) o a archivos renombrados
(`2_secuencias.md`→`3_secuencias.md`, `6_tad.md`→`3_tad_pilas_colas.md`,
`1_memoria_dinamica.md`→`5_memoria_dinamica.md`, `A_stdlib.md`→`stdlib.md`).
Lista completa con archivo:línea:

| Archivo | Línea | Enlace roto | Destino probable |
| --- | --- | --- | --- |
| `apunte/indice.md` | 169 | `bloque_3_algoritmos_estructuras/7A_stack_frames.md` | archivo no existe, ver T2 |
| `bloque_1_fundamentos/3_control_flujo.md` | 1251 | `../bloque_3_memoria_estatica/3_secuencias.md` | `../bloque_2_memoria/3_secuencias.md` |
| `bloque_1_fundamentos/3_control_flujo.md` | 1253 | `../bloque_2_proyectos/1_compilacion.md` | sin destino directo (contenido ya vive en `5_compilacion.md`) |
| `bloque_1_fundamentos/3_control_flujo.md` | 1255 | `../bloque_3_memoria_estatica/2_punteros.md` | `../bloque_2_memoria/2_punteros.md` |
| `bloque_1_fundamentos/3_control_flujo.md` | 1257 | `../bloque_4_dinamica_interfaces/3_archivos_texto.md` | `../bloque_2_memoria/4_archivos_texto.md` |
| `bloque_1_fundamentos/4_funciones.md` | 422 | `0_estilo.md` | sin destino claro (revisar intención) |
| `bloque_1_fundamentos/5_compilacion.md` | 1217 | `../../referencia/A_stdlib.md` | `../../referencia/stdlib.md` |
| `bloque_2_memoria/2_punteros.md` | 292, 617 | `2_secuencias.md` | `3_secuencias.md` |
| `bloque_2_memoria/2_punteros.md` | 1381, 1412 | `../bloque_4_dinamica_interfaces/1_memoria_dinamica.md` | `5_memoria_dinamica.md` (mismo bloque) |
| `bloque_2_memoria/3_secuencias.md` | 361 | `../bloque_4_dinamica_interfaces/1_memoria_dinamica.md` | `5_memoria_dinamica.md` (mismo bloque) |
| `bloque_2_memoria/3_secuencias.md` | 1120 | `../bloque_4_dinamica_indireccion/3_matrices.md` | `../bloque_3_algoritmos_estructuras/1_matrices.md` |
| `bloque_2_memoria/3_secuencias.md` | 1123 | `../bloque_4_dinamica_indireccion/1_memoria_dinamica.md` | `5_memoria_dinamica.md` (mismo bloque) |
| `bloque_2_memoria/4_archivos_texto.md` | 313 | `../extras/binarios.md` | `../bloque_4_avanzados/4_binarios_archivos.md` |
| `bloque_2_memoria/3_secuencias.md` | 272-275 | (fence `:::` vacío, no un link) | usar ` ```text ` |
| `bloque_3_algoritmos_estructuras/1_matrices.md` | 34 | `2_secuencias.md` | `../bloque_2_memoria/3_secuencias.md` |
| `bloque_3_algoritmos_estructuras/2_tad.md` | 1545 | `1_memoria_dinamica.md` | `../bloque_2_memoria/5_memoria_dinamica.md` |
| `bloque_3_algoritmos_estructuras/3_tad_pilas_colas.md` | 1978 | `1_memoria_dinamica.md` | `../bloque_2_memoria/5_memoria_dinamica.md` |
| `bloque_3_algoritmos_estructuras/6_complejidad.md` | 91, 287, 387, 894 | `6_tad.md` | `3_tad_pilas_colas.md` |
| `bloque_3_algoritmos_estructuras/7_recursividad_intro.md` | 22 | `7A_stack_frames.md` | archivo no existe, ver T2 |
| `bloque_4_avanzados/3_opacos.md` | 1773 | `3_tad.md` (con texto de enlace vacío) | `../bloque_3_algoritmos_estructuras/2_tad.md` |
| `bloque_4_avanzados/6_bitmaps.md` | 37 | `binarios.md`, `bits.md` | `4_binarios_archivos.md`, `5_binarios_bitwise.md` |

**T2. `myst.yml:84` referencia `bloque_3_algoritmos_estructuras/7A_stack_frames.md`,
que no existe en disco.** Rompe la navegación "Bloque 3: Puentes y
ampliaciones" y dos enlaces internos (`indice.md:169`,
`7_recursividad_intro.md:22`) que asumen su existencia. Requiere una decisión
de contenido, no solo un rename (ver plan de acción, Fase 0).

**T3. `bloque_4_avanzados/13_struct_avanzado.md` tiene 0 bytes.** Ver detalle
en la sección de bloque 4.

### IMPORTANTE

**T4. `myst.yml` omite 18 archivos "ampliación" que existen en disco** y no
están enlazados desde ningún capítulo principal ni desde otro archivo del
repo (huérfanos totales, solo alcanzables escribiendo la URL a mano):

- Bloque 3 (7 de 11 ampliaciones): `1B_matrices_vla.md`, `1C_matrices3d.md`
  (parcial, autoenlazado), `1D_fragmentacion_matrices.md`,
  `1E_rendimiento_memoria.md`, `1F_seguridad_memoria.md`,
  `6D_fragmentacion_matrices.md`, `7E_serializacion.md`,
  `7F_estructuras_opacas.md` (parcial, autoenlazado).
- Bloque 4 (7 de 7, el 100% de la familia "13"): `13_struct_avanzado.md`,
  `13B_serializacion.md`, `13C_estructuras_opacas.md`, `13D_union.md`,
  `13E_padding_abi.md`, `13F_bitfields.md`, `14A_enums_avanzados.md`.

**T5. `ejercicios/bloque_3_algoritmos_estructuras/5_recursion.md` existe en
disco pero no está en `myst.yml`** — el único bloque cuya sección de
ejercicios en el TOC no incluye recursividad, pese a que `apunte/bloque_3/
7_recursividad_intro.md` sí es un capítulo del recorrido principal.

**T6. ~~Referencia cruzada rota~~ — descartado, falso positivo.**
`bloque_4_avanzados/7_recursividad_avanzada.md:536` usa
`{ref}`ej-def-mat-cantidad-digitos``. El script de detección de anclas solo
reconocía el patrón `(id)=` y no los `:label:` de directivas
`exercise`/`solution`; esa etiqueta sí existe, como `:label:` del ejercicio
en `bloque_3_algoritmos_estructuras/7_recursividad_intro.md:305`. No requiere
corrección.

**T7. `reporte.md` (sin commitear, raíz del repo) documenta un plan de
reorganización con nomenclatura `NA_tema.md`/`NB_tema.md` que ya no coincide
con el estado real de los archivos** (algunos bloques usan letras hasta la
`F`, no solo `A`/`B`). Mantenerlo sin reconciliar invita a que se repita el
patrón de archivos huérfanos cada vez que alguien lo use como referencia.

**T8. `ejercicios/` tiene 59 enlaces Markdown rotos, fuera del alcance de la
auditoría original** (que se limitó a `apunte/`). Detectados al re-ejecutar el
script de barrido de enlaces después de cerrar la Fase 2. Se concentran en:

| Archivo | Rotos | Patrón |
| --- | --- | --- |
| `bloque_1_fundamentos/4_testing_y_estructura.md` | 18 | `../../reglas/{0_sintaxis,1_control,2_funciones,5_buenas_practicas}.md` |
| `bloque_1_fundamentos/9_refactorizacion_codigo_ofuscado.md` | 14 | ídem |
| `bloque_1_fundamentos/1_basicos_y_secuencias.md` | 4 | ídem |
| `bloque_1_fundamentos/6_funciones_ejercicios.md` | 4 | ídem |
| `bloque_1_fundamentos/5_ejercicios_control.md` | 3 | ídem |
| `bloque_1_fundamentos/2_gradual_ejercicios.md` | 2 | ídem |
| `bloque_1_fundamentos/8_compilacion_y_makefiles.md` | 2 | `../../apunte/bloque_2_proyectos/{1_compilacion,2_makefiles}.md` |
| `bloque_2_memoria/4b_memoria.md` | 2 | `../../apunte/bloque_{3_memoria_estatica,4_dinamica_interfaces}/...` |
| `bloque_1_fundamentos/7_librerias_ejercicios.md` | 1 | `../../apunte/bloque_2_proyectos/1_compilacion.md` |
| `bloque_2_memoria/{2_arreglos,2b_cadenas}.md` | 1 c/u | `../../apunte/bloque_3_memoria_estatica/3_secuencias.md` |
| `bloque_2_memoria/4_memoria_dinamica.md` | 1 | `../../apunte/bloque_4_dinamica_interfaces/1_memoria_dinamica.md` |
| `bloque_2_memoria/4c_ejercicios_memoria.md` | 1 | `../../apunte/bloque_4_dinamica_indireccion/1_memoria_dinamica.md` |
| `bloque_2_memoria/7_alias_tipos_ejercicios.md` | 1 | `../../apunte/bloque_2_proyectos/3_alias_tipos.md` |
| `bloque_2_memoria/8_enums.md` | 1 | `../../apunte/bloque_2_proyectos/4_enums.md` |
| `bloque_3_algoritmos_estructuras/1_matrices.md` | 1 | `../../apunte/bloque_4_dinamica_indireccion/3_matrices.md` |
| `bloque_4_avanzados/2_operaciones_de_bits.md` | 1 | `../../apunte/bloque_3_memoria_estatica/1_modelo_memoria.md` |
| `readme.md` | 1 | `../apunte/0_estilo.md` |

Dos familias de causa raíz, ambas ya vistas en `apunte/`: (a) nombres viejos
de bloque (`bloque_2_proyectos`, `bloque_3_memoria_estatica`,
`bloque_4_dinamica_interfaces`, `bloque_4_dinamica_indireccion`) de la misma
reorganización que generó T1; y (b) una numeración plana vieja de `reglas/`
(`0_sintaxis.md`, `1_control.md`, `2_funciones.md`, `5_buenas_practicas.md`)
anterior a la estructura actual por categorías (`00_formato/`,
`10_control/`, `20_funciones/`, etc.) — 47 de los 59 enlaces rotos son de
este segundo tipo, concentrados en 2 archivos
(`4_testing_y_estructura.md` y `9_refactorizacion_codigo_ofuscado.md`, 32
entre los dos). Corregirlos requiere mapear cada mención genérica
("`reglas/2_funciones.md`") a una regla concreta (`0x20XXh`) usando
`reglas/renumeracion.md`, no un simple reemplazo de ruta — por eso se separa
como fase propia en el plan de acción en vez de sumarse a la Fase 2.

### Fortalezas confirmadas (no exhaustivo, pero verificado)

- Cero anclas `{ref}` duplicadas en todo el repositorio (2700 anclas
  definidas, sin colisiones).
- Las 289 referencias `{ref}` a códigos de regla (`0x3001h`, etc.) dentro de
  `apunte/` resuelven correctamente contra `reglas/`.
- Ninguna figura (SVG/PNG) referenciada en bloque 2 está rota; todas las
  rutas coinciden con archivos físicos.
- La fusión de archivos de ampliación de bloque 2 (hecha en esta sesión)
  quedó limpia: sin referencias colgantes a los 8 archivos eliminados, con
  las anclas nuevas (`funcionamiento-de-la-pila-en-ensamblador-x86-64`,
  `el-allocator-gestion-interna-del-heap`, `memcpy-copia-de-memoria`, `AoS`,
  `cast-aritmetico-vs-cast-de-reinterpretacion`) presentes y bien
  referenciadas.
- Los pares `:::{exercise}`/`:::{solution}` de los capítulos grandes de
  bloque 2 y 3 (`2_tad.md` 15/15, `3_tad_pilas_colas.md` 9/9, etc.) están
  perfectamente emparejados por `:label:`, sin huérfanos.

---

## Bloque 1: Fundamentos

**Veredicto**: contenido técnico sólido, pero con un bug de render real y
defectos de estructura sistemáticos heredados de una reorganización vieja.
Publicable tras una pasada de correcciones puntuales, no tal cual.

### CRÍTICO

1. **`1_base.md:1009`** — el `::::{exercise}` "Ejercicio 4: Integradores"
   nunca cierra (el `:::` de la línea 1038 está pegado a una oración, no en
   línea propia). Confirmado con `myst build --html`: el AST anida **todo el
   resto del archivo** (líneas 1009–1196: la solución, el glosario, la
   síntesis, "próximos pasos" y la figura final) dentro de la caja del
   ejercicio.
2. **H1 faltante en 7 de 8 archivos** (`1_base.md`, `2_gradual.md`,
   `3_control_flujo.md`, `5_compilacion.md`, `6_testing_basico.md`,
   `7_contratos_intro.md`, `8_makefiles.md`): pasan de `(ancla)=` directo a
   `## Introducción` sin `# Título`. Solo `4_funciones.md:15` tiene H1.
3. **4 enlaces rotos en "Próximos Pasos"** — `3_control_flujo.md:1251-1258`
   (ver tabla T1).
4. **Enlace roto a stdlib** — `5_compilacion.md:1217` (ver tabla T1).
5. **Violación de la regla propia `0x1001h`** ("llaves obligatorias"):
   `6_testing_basico.md:293-301`, función `es_bisiesto` con tres `if` sin
   llaves, dentro de un ejercicio que un estudiante puede copiar como
   correcto.

### IMPORTANTE

6. **Duplicación completa de 3 ejercicios de Makefiles** entre
   `5_compilacion.md` (~líneas 2022-2164) y `8_makefiles.md` (~líneas
   246-315), con comentarios de cierre residuales que evidencian un
   copy-paste no limpiado (`<!-- {solution} ej-make-incremental -->` sin
   prefijo, junto al comentario correcto con prefijo).
7. **5 `<!--TODO: completar-->` sin resolver**: `2_gradual.md:130, 150, 173,
   431` y `7_contratos_intro.md:30` — secciones tituladas y vacías, visibles
   en el sitio publicado.
8. **7 comentarios de cierre de figura con ruta incorrecta** en
   `5_compilacion.md` (líneas 77, 230, 1009, 1365, 1397, 1465, 1583, 1643):
   apuntan a `1/nombre.svg` cuando el archivo real está en `5/`. Invisible en
   el render, pero es "código comentado" incorrecto.
9. **`{code-block}c` sin espacio** (decenas de instancias en `4_funciones.md`,
   `5_compilacion.md`, `6_testing_basico.md`): no rompe el build pero es
   inconsistente con la plantilla canónica y con el resto del libro.

### MENOR

10. Forward-references suaves a anclas de bloque 2 (`4_funciones.md:436,612`)
    correctamente enmarcadas como ampliación, pero sin usar un admonition
    `{seealso}` que lo deje explícito.
11. `5_compilacion.md` (2244 líneas) es ~2x el siguiente archivo más largo;
    `7_contratos_intro.md` (305 líneas) y `8_makefiles.md` (352 líneas) son
    notablemente cortos frente al resto.

---

## Bloque 2: Memoria

**Veredicto**: el bloque más grande y, en general, el más maduro. La fusión
de archivos de ampliación hecha hoy quedó bien integrada. Los defectos
detectados son en su mayoría **preexistentes** a esa fusión (confirmado
verificando fecha/contexto de cada hallazgo).

### CRÍTICO

1. **Residuo de IA sin limpiar** — `1_modelo_memoria.md:282`: "De acuerdo. A
   continuación, una ampliación del concepto que generaliza la idea de
   estado...". Texto de una respuesta de LLM filtrado al cuerpo del apunte.
   Preexistente a la fusión de hoy.
2. **Encabezado duplicado/anidado** — `6_aritmetica.md:1891-1894`: `##
   Referencias y Lecturas de Aritmética de Punteros` (H2) inmediatamente
   seguido de `### Referencias y Lecturas de Aritmética de Punteros` (H3),
   mismo título repetido como padre/hijo.
3. **Mismo patrón** — `5_memoria_dinamica.md:2465-2468`: `## Referencias y
   Lecturas Complementarias` (H2) seguido de `### Referencias y Lecturas
   Adicionales` (H3). Ambos casos son preexistentes, no artefactos de la
   fusión de hoy (verificado: la fusión no tocó esas líneas).

### IMPORTANTE

4. **Salto de nivel de heading** — `7_estructuras.md:1378`: `##### El Patrón
   de Unión Etiquetada` (H5) aparece justo después de `### Uniones` (H3),
   saltándose H4.
5. **Ancla desplazada** — `7_estructuras.md:40`: `(estructuras-struct-
   agrupando-datos)=` está 15 líneas antes de su H3 real (línea 55). Inocuo
   (nadie la referencia todavía) pero descuidado.
6. **Casts de `malloc` en soluciones de ejercicios**, violando la regla
   propia `0x300Ah` ("prohibición de casteo redundante de malloc"):
   `5_memoria_dinamica.md`, líneas 1553, 1561, 1613, 1666, 1741, 1833, 1836,
   1941, 1947, 2047, 2053, 2064. El cuerpo principal del capítulo sí usa el
   idioma correcto sin cast; solo las soluciones de ejercicios cambian.
7. **Fence malformado** — `3_secuencias.md:272-275`: una valla `:::`/`:::`
   sin nombre de directiva en vez de un bloque ` ```text `.
8. **6 enlaces rotos** a la estructura de bloques vieja (ver tabla T1).

### MENOR

9. Frontmatter usa `description` en vez de `subtitle` en `1_modelo_memoria.md`,
   `4_archivos_texto.md` y `5_memoria_dinamica.md` (la guía editorial exige
   siempre `subtitle`).
10. `2_punteros.md:28` — salto de heading H2→H4.
11. `10_alias_tipos.md` (6.9K, 209 líneas) es desproporcionadamente corto
    frente al resto del catálogo (todos ≥14K): no cubre `typedef` de
    punteros a función ni de arrays/structs, pese a que ese patrón se usa
    profusamente en `7_estructuras.md`.

### Estado de la fusión de ampliaciones (hecha en esta sesión)

Confirmado limpio: las anclas `funcionamiento-de-la-pila-en-ensamblador-x86-64`,
`el-allocator-gestion-interna-del-heap`, `memcpy-copia-de-memoria`, `AoS` y
`cast-aritmetico-vs-cast-de-reinterpretacion` existen y están bien
referenciadas entre archivos. Ningún archivo quedó apuntando a los 8 nombres
de archivo eliminados (`1A_`, `5A_`, `6A_`, `7A_`, `8A_`, `9A_`). El único
detalle cosmético es que la ancla `capitulo-hardware-memoria` (mencionada
como referencia en el proceso de fusión) no quedó definida en ningún archivo;
como nada la referencia, es inocuo.

---

## Bloque 3: Algoritmos y Estructuras de Datos

**Veredicto**: el bloque con el daño estructural más grave y más visible del
apunte. Tres de siete capítulos principales tienen el título de apertura
equivocado, y más de la mitad de sus archivos de ampliación son huérfanos de
navegación.

### CRÍTICO

1. **`myst.yml:84`** referencia `7A_stack_frames.md`, que no existe (rompe
   navegación; ver T2).
2. **H1 incorrecto, duplicado con la sección final**, en 3 de 7 capítulos:
   - `2_tad.md:8` → `# Resumen de la Unidad` (el resumen real está en el H2
     de la línea 2825).
   - `3_tad_pilas_colas.md:8` → `# Referencias y Lecturas Complementarias`
     (el título real del capítulo no aparece como H1 en ningún lado).
   - `6_complejidad.md:8` → `# Referencias y Lecturas Complementarias` (el H2
     legítimo de referencias está en la línea 1938, con otro texto).
   Cualquier lector ve el capítulo abrir con el título de su propio cierre.
3. **Secciones "## Introducción" completamente vacías** en `2_tad.md:69-73`,
   `3_tad_pilas_colas.md:18-22`, `6_complejidad.md:25-27` y
   `5_contratos_formales.md:18-22` (con una ancla huérfana en esta última,
   línea 20). Contrastan con `4_testing_avanzado.md` y `1_matrices.md`, que
   sí tienen introducción real — confirma que el patrón roto es aislado, no
   un estilo intencional.
4. **`5_contratos_formales.md:8`**: H1 es `# 3. Contratos de Estructuras de
   Datos e Invariantes de Clase`, no coincide con el `title` del frontmatter
   ("Diseño por Contratos Formal y Verificación") y arrastra una numeración
   "3." huérfana.

### IMPORTANTE

5. 4 enlaces rotos a `6_tad.md` en `6_complejidad.md` (líneas 91, 287, 387,
   894) — el destino real es `3_tad_pilas_colas.md`.
6. Enlaces rotos a `1_memoria_dinamica.md` en `2_tad.md:1545` y
   `3_tad_pilas_colas.md:1978` — falta el prefijo `../bloque_2_memoria/` y el
   nombre real es `5_memoria_dinamica.md`.
7. Enlace roto en `1_matrices.md:34` a `2_secuencias.md` — falta la ruta a
   `../bloque_2_memoria/3_secuencias.md`.
8. Enlace roto en `7_recursividad_intro.md:22` a `7A_stack_frames.md`.
9. **5 huérfanos totales de navegación** (ni en `myst.yml` ni enlazados desde
   ningún capítulo): `1B_matrices_vla.md`, `1D_fragmentacion_matrices.md`,
   `1F_seguridad_memoria.md`, `6D_fragmentacion_matrices.md`,
   `7E_serializacion.md`.
10. **2 huérfanos parciales** (solo autoenlazados entre ampliaciones, nunca
    desde un capítulo principal): `1C_matrices3d.md`, `7F_estructuras_opacas.md`.
11. `4_testing_avanzado.md` (8.4K) y `5_contratos_formales.md` (16K) son
    órdenes de magnitud más cortos que sus pares (50-84K) y **no tienen
    ningún bloque `:::{exercise}`**, a diferencia de `2_tad.md` (15) y
    `3_tad_pilas_colas.md` (9).

### MENOR

12. Placeholders sin desarrollar (1-2 párrafos, sin código ni ejercicio):
    `1B`, `1C`, `1D`, `6D`, `7E`.
13. `1_matrices.md` no tiene H1 en absoluto.
14. `bloque_4_avanzados/13B_serializacion.md` y `13C_estructuras_opacas.md`
    (sin commitear) probablemente dupliquen la intención de `7E_serializacion.md`
    y `7F_estructuras_opacas.md` de este bloque — sugiere un plan de mover
    esos temas a bloque 4 que quedó a medio hacer.

### Tabla de archivos de ampliación

| Archivo | ¿En `myst.yml`? | ¿Enlazado desde capítulo principal? | Contenido | ¿Redundante con bloque 2? |
| --- | --- | --- | --- | --- |
| `1A_matrices_dinamicas.md` | Sí | Sí | Real | No |
| `1B_matrices_vla.md` | No | No | Placeholder | Sí, con `6_aritmetica.md` |
| `1C_matrices3d.md` | No | Parcial (autoenlace) | Placeholder mínimo | Parcial |
| `1D_fragmentacion_matrices.md` | No | No | Placeholder | Sí, con `6_aritmetica.md` |
| `1E_rendimiento_memoria.md` | No | No | Real | Parcial (complementa) |
| `1F_seguridad_memoria.md` | No | No | Real | No |
| `2A_ownership_tads.md` | Sí | Sí | Real | No |
| `6A_localidad_representacion.md` | Sí | Sí | Real | No |
| `6D_fragmentacion_matrices.md` | No | No | Placeholder (duplica 1D) | Sí |
| `7E_serializacion.md` | No | No | Placeholder | Posible dup. con bloque 4 `13B` |
| `7F_estructuras_opacas.md` | No | Parcial (autoenlace) | Placeholder | Posible dup. con bloque 4 `13C` |

---

## Bloque 4: Temas Avanzados

**Veredicto**: junto con bloque 3, el más problemático. Un capítulo entero
vacío con toda su familia huérfana, un bug de render confirmado, y tres
capítulos grandes (hilos, sockets, diseño de APIs) sin un solo ejercicio.

### CRÍTICO

1. **`13_struct_avanzado.md` — 0 bytes**, sin frontmatter ni contenido.
2. **`myst.yml` (líneas 85-98) omite por completo la familia "13/14"**: ni
   `13_struct_avanzado`, ni `13B`-`13F`, ni `14A_enums_avanzados` aparecen en
   la navegación ni son referenciados desde ningún otro `.md` del repo —
   huérfanos totales, invisibles en el sitio publicado.
3. **Fences de MyST corruptos en `5_binarios_bitwise.md:316-396`** (ejercicios
   "activar", "intercambio", "mask"):
   - Línea 316: apertura con 9 dos-puntos (inconsistente con el resto del
     archivo).
   - Líneas 321 y 352: cierre `:::` pegado al final de una oración en vez de
     en línea propia — el exercise nunca cierra antes de que arranque la
     solución.
   - Líneas 381-393: párrafo del ejercicio "mask" duplicado literalmente dos
     veces.
   - Línea 396: comentario de cierre dice `<!-- {exercise} intercambio -->`
     en vez de "mask" — evidencia de corte/pegado cruzado entre dos
     ejercicios. Desbalance global del archivo: 25 aperturas de fence vs. 19
     cierres.

### IMPORTANTE

4. 2 enlaces rotos en `6_bitmaps.md:37` (`binarios.md`, `bits.md`).
5. Enlace roto y con texto vacío en `3_opacos.md:1773` (`[](3_tad.md)`); la
   ruta correcta ya se usa bien en la línea 44 del mismo archivo.
6. H1 desalineado con el `title` del frontmatter: `3_opacos.md:8` dice
   `# Referencias y Lecturas Complementarias`; `2_punteros_funciones.md:8`
   dice `# Lecturas Recomendadas` y además tiene un segundo H1 en la línea 21
   (dos H1 en el mismo archivo).
7. **H1 ausente por completo** en 7 capítulos grandes: `5_binarios_bitwise.md`,
   `6_bitmaps.md`, `8_idiomatico.md`, `9_api_diseno.md`, `10_api_ingenieria.md`,
   `11_hilos.md`, `12_sockets.md`.
8. `1_indice_avanzados.md` no tiene frontmatter YAML (sin `title`/`short_title`).
9. **Cero ejercicios** en `9_api_diseno.md` (41K), `11_hilos.md` (40K) y
   `12_sockets.md` (48K), pese a su tamaño. Contrasta con `2_punteros_funciones.md`
   (8), `5_binarios_bitwise.md` (11), `8_idiomatico.md` (10).
10. **Alcance pedagógico cuestionable**: `11_hilos.md` (pthreads, mutex,
    condvars, atomics, OpenMP) y `12_sockets.md` (TCP/UDP, `select`,
    `getaddrinfo`, y **TLS con OpenSSL**) exceden el temario típico de
    "Programación 1" y se solapan con Sistemas Operativos/Redes, sin ninguna
    nota que los enmarque como opcionales.

### MENOR

11. Desbalance leve de fences en `3_opacos.md` (77 vs 78) — revisar con
    linter antes de descartar como falso positivo.
12. Prerrequisitos de los satélites huérfanos citan archivos inexistentes o
    mal referenciados: `13B_serializacion.md` cita `4A_archivos_avanzados.md`
    (no existe); `14A_enums_avanzados.md` cita `11_enums.md` sin indicar
    bloque.

### Estado puntual: familia 13/14

| Archivo | Tamaño | Contenido | Redundancia |
| --- | --- | --- | --- |
| `13_struct_avanzado.md` | 0 B | Vacío total | — |
| `13B_serializacion.md` | 453 B | Placeholder, 1 párrafo | No, tema no cubierto en bloque 2 |
| `13C_estructuras_opacas.md` | 515 B | Placeholder | Sí, totalmente redundante con `3_opacos.md` (52K, 9 ejercicios) |
| `13D_union.md` | 880 B | El más desarrollado: código completo y compilable | No |
| `13E_padding_abi.md` | 475 B | Placeholder | No |
| `13F_bitfields.md` | 451 B | Placeholder | Parcial, con `5_binarios_bitwise.md` |
| `14A_enums_avanzados.md` | 850 B | Placeholder + snippet de 4 líneas | No |

Todos comparten timestamp de archivo (21/9, 15:49-15:52): son claramente
trabajo en progreso de la misma sesión de edición que nunca se integró.

---

## Métricas de apoyo

- Archivos `.md` en `apunte/`: 71 (excluyendo `_build/`).
- Enlaces `.md` rotos detectados: 33.
- Referencias `{ref}` rotas detectadas (excluyendo `_build/` y plantillas de
  `reglas/_guia_editorial.md`): 0 (el único candidato,
  `ej-def-mat-cantidad-digitos`, resultó falso positivo — ver T6).
- Archivos de ampliación (`NA_tema.md`) huérfanos de `myst.yml`: 18 de 27
  (67%).
- Archivos vacíos: 1 (`13_struct_avanzado.md`).
- Bloques con al menos un H1 incorrecto o ausente: 3 de 4 (bloque 1, 3 y 4).
