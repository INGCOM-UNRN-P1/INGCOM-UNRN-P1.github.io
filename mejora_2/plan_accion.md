# Plan de acción — `apunte/`

Compañero de `informe_calidad.md`. Cada fase es ejecutable de forma
independiente y no requiere terminar la anterior, pero el orden refleja
impacto/riesgo: primero lo que rompe el render o es invisible para el
lector, después la limpieza de navegación y enlaces, luego las decisiones de
contenido (fusionar/eliminar/desarrollar), y por último lo cosmético.

Cada tarea indica: archivo(s), acción concreta, y si requiere una decisión
editorial (no solo mecánica) antes de tocarla.

---

## Fase 0 — Bugs de render (bloqueantes, arreglar primero) — ✅ Completada

**Estado**: resuelta íntegramente. Los tres puntos de esta fase se corrigieron
tal como estaban planteados, y de paso aparecieron 5 ejercicios más con la
misma corrupción de fences en `5_binarios_bitwise.md` (`multiplicacion`,
`get_bit`, `set_bit`, `clear_bit`, `potencia`) que no estaban en el rango
316-396 originalmente auditado — se repararon también. Ver commits
`d3fd0d8`..`da387fb`.

Estos tres afectan directamente lo que ve un lector del sitio publicado.

1. **`bloque_1_fundamentos/1_base.md:1009-1038`** — cerrar correctamente el
   `::::{exercise}` "Ejercicio 4: Integradores" con `::::` antes de
   `:::{solution}`, y sacar el `:::` que quedó pegado al final de la oración
   en la línea 1038. Verificar con `myst build --html` que el AST ya no anida
   el resto del capítulo dentro del ejercicio.
2. **`bloque_4_avanzados/5_binarios_bitwise.md:316-396`** — reparar los tres
   ejercicios corruptos ("activar", "intercambio", "mask"): normalizar
   profundidad de `:::`, sacar el `:::` embebido en prosa, eliminar el
   párrafo duplicado de "mask", corregir el comentario de cierre que dice
   "intercambio" en vez de "mask". Verificar render con `myst build`.
3. **`myst.yml:84`** — quitar la entrada `7A_stack_frames.md` (no existe) de
   inmediato para que el build no falle, aunque sea un parche temporal hasta
   resolver la Fase 3 (decisión sobre ese contenido). Al quitarla, también
   arreglar los dos enlaces que asumen su existencia: `indice.md:169` y
   `bloque_3_algoritmos_estructuras/7_recursividad_intro.md:22`.

**Costo estimado**: 30-45 min. **Riesgo si no se hace**: el sitio publicado
muestra contenido mal anidado o un enlace de navegación roto.

---

## Fase 1 — Integridad estructural (H1, headings, anclas) — ✅ Completada

Mecánico en su mayoría, alto impacto en percepción de calidad.

**Estado**: resuelta íntegramente, incluyendo los 12 puntos originales. Ver
commits `0d9b272`, `534bc38`, `10b03f5`, `880884e`. Al verificar el resultado
con un script propio (H1 ausente/duplicado, saltos de nivel de heading,
balance de fences `:::`) aparecieron 4 hallazgos que no estaban en el informe
original — están documentados en la sección siguiente.

4. **H1 equivocado en bloque 3** (el hallazgo más visible de todo el apunte):
   - `2_tad.md:8`: cambiar `# Resumen de la Unidad` por el título real del
     capítulo (usar el `title` del frontmatter como referencia, p. ej.
     "Tipos de Datos Abstractos, Pilas y Colas"); el H2 legítimo de resumen
     ya existe en la línea 2825 como `## Síntesis y Resumen` — no duplicar.
   - `3_tad_pilas_colas.md:8`: cambiar `# Referencias y Lecturas
     Complementarias` por el título real del capítulo.
   - `6_complejidad.md:8`: mismo arreglo; el H2 legítimo de referencias está
     en la línea 1938.
   - `5_contratos_formales.md:8`: reemplazar `# 3. Contratos de Estructuras
     de Datos e Invariantes de Clase` por el `title` del frontmatter ("Diseño
     por Contratos Formal y Verificación"), sin numeración huérfana.
5. **Rellenar las secciones "## Introducción" vacías**: `2_tad.md:69-73`,
   `3_tad_pilas_colas.md:18-22`, `6_complejidad.md:25-27`,
   `5_contratos_formales.md:18-22` (además reubicar el ancla huérfana de esta
   última). Usar como referencia el estilo de introducción de
   `4_testing_avanzado.md` o `1_matrices.md` (2-4 párrafos que sitúan el
   capítulo y conectan con el anterior).
6. **Agregar H1 faltante** (7 archivos en bloque 1: `1_base.md`,
   `2_gradual.md`, `3_control_flujo.md`, `5_compilacion.md`,
   `6_testing_basico.md`, `7_contratos_intro.md`, `8_makefiles.md`; 7
   archivos en bloque 4: `5_binarios_bitwise.md`, `6_bitmaps.md`,
   `8_idiomatico.md`, `9_api_diseno.md`, `10_api_ingenieria.md`,
   `11_hilos.md`, `12_sockets.md`) inmediatamente después de la ancla
   `(capitulo-*)=`, reflejando el `title` del frontmatter. Usar
   `4_funciones.md` como plantilla del patrón correcto.
7. **Corregir H1 con texto equivocado**: `bloque_4/3_opacos.md:8` (dice
   "Referencias y Lecturas Complementarias") y
   `bloque_4/2_punteros_funciones.md:8` (dice "Lecturas Recomendadas", y
   además tiene un segundo H1 en la línea 21 que hay que eliminar).
8. **Agregar frontmatter faltante** a `bloque_4/1_indice_avanzados.md`
   (`title`, `short_title`).
9. **Arreglar saltos de nivel de heading**: `bloque_2/7_estructuras.md:1378`
   (H5 tras H3, falta H4 o bajar a H4), `bloque_2/2_punteros.md:28` (H4 tras
   H2, falta H3).
10. **Reubicar ancla desplazada**: `bloque_2/7_estructuras.md:40` — mover
    `(estructuras-struct-agrupando-datos)=` justo encima de su H3 real
    (línea 55).
11. **Aplanar encabezados "Referencias" duplicados/anidados**:
    `bloque_2/6_aritmetica.md:1891-1894` y
    `bloque_2/5_memoria_dinamica.md:2465-2468` — dejar un único `##` como en
    el resto del libro.
12. **Quitar el residuo de IA** en `bloque_2/1_modelo_memoria.md:282`
    ("De acuerdo. A continuación...") y reescribir como transición editorial
    normal.

**Costo estimado**: 3-4 horas (bloque 3 es el más largo por el volumen de
introducciones a redactar). **Riesgo si no se hace**: percepción de
descuido/calidad baja en la primera impresión de 6 capítulos distintos.

---

## Hallazgos adicionales (detectados al ejecutar la Fase 1, no estaban en el informe original)

La auditoría inicial (una pasada por bloque con subagentes) no revisó
exhaustivamente cada archivo; al corregir la Fase 1 y verificar con un script
propio (H1 ausente/duplicado, saltos de nivel de heading, balance de fences)
aparecieron estos 4 puntos nuevos:

35. **6 capítulos más sin H1 en bloque 2**, no detectados por la auditoría
    original: `3_secuencias.md`, `6_aritmetica.md`, `8_numeros.md`,
    `9_casts.md`, `10_alias_tipos.md`, `11_enums.md`. El problema de H1
    faltante en bloque 2 era más extendido de lo reportado (7 de 11 capítulos
    del bloque, no solo los mencionados originalmente). **Ya corregido** en
    el commit `534bc38`.
36. **2 fences de MyST corruptos adicionales**, mismo patrón que la Fase 0
    pero en archivos no cubiertos por ese rango:
    - `bloque_4_avanzados/3_opacos.md:436-452` — un `{warning}` abría con
      `::{warning}` (2 colons, por debajo del mínimo de 3) y cerraba con
      `:::::` (5 colons) bajo un comentario de control que decía
      `<!-- {code-block} c -->` en vez de `{warning}`.
    - `bloque_3_algoritmos_estructuras/3_tad_pilas_colas.md:494-500` — un
      `{note}` abría con 5 colons y cerraba con 4.
    **Ya corregido** en los commits `10b03f5` y `880884e`.
38. **2 referencias `{ref}` rotas preexistentes en `ejercicios/bloque_2_memoria/`**,
    no relacionadas con ningún cambio de esta sesión: `3_archivos.md` y
    `3b_ejercicios_archivos.md` referencian `{ref}`capitulo-archivos-texto``,
    y `5_punteros_2.md` referencia `{ref}`capitulo-aritmetica-punteros``.
    Ninguna de las dos anclas existe ni existió nunca en `apunte/` (no es un
    problema de renombrado, el nombre nunca se definió). Se agrega a la Fase
    2 como ítem 19b — el directorio `ejercicios/` no estaba dentro del
    alcance de la auditoría original y probablemente tenga más casos
    similares sin relevar.

---

## Fase 2 — Barrido de enlaces rotos en `apunte/` — ✅ Completada

Puramente mecánico una vez que se conoce el mapeo correcto (ya está en la
tabla T1 de `informe_calidad.md`). Se puede hacer con `grep`/`sed` dirigido,
archivo por archivo, y verificar después con el mismo script de detección
usado en la auditoría (recorrer todos los `.md`, extraer `]($ruta)`, resolver
contra el sistema de archivos).

**Estado**: resuelta íntegramente (items 13-19, 19b). Verificado con el script
de barrido: `apunte/` tiene **0 enlaces `.md` rotos y 0 referencias `{ref}`
rotas** después de esta fase. Al re-ejecutar el mismo barrido sobre
`ejercicios/` (fuera del alcance original) aparecieron 59 enlaces rotos más —
ver hallazgo T8 en `informe_calidad.md` y la Fase 2b más abajo.

13. Bloque 1: 4 enlaces en `3_control_flujo.md:1251-1258` + 1 en
    `5_compilacion.md:1217`.
14. Bloque 2: 6 enlaces en `2_punteros.md` (4) y `3_secuencias.md` (2) +
    `4_archivos_texto.md:313`.
15. Bloque 3: 4 en `6_complejidad.md`, 2 (`1_memoria_dinamica.md`) en
    `2_tad.md`/`3_tad_pilas_colas.md`, 1 en `1_matrices.md:34`.
16. Bloque 4: 2 en `6_bitmaps.md:37`, 1 en `3_opacos.md:1773`.
17. Fence malformado (no un link, pero mismo barrido): `bloque_2/
    3_secuencias.md:272-275` — reemplazar la valla `:::`/`:::` vacía por
    ` ```text `.
18. ~~Referencia `{ref}` rota: `bloque_4/7_recursividad_avanzada.md:536`~~ —
    **falso positivo, no requiere acción**. El ejercicio
    `ej-def-mat-cantidad-digitos` sí existe como `:label:` de un
    `:::{exercise}` en `bloque_3_algoritmos_estructuras/7_recursividad_intro.md:305`.
    El script de detección de anclas rotas solo buscaba el patrón
    `(id)=`, no los `:label:` de directivas `exercise`/`solution`
    (sphinx-exercise), por eso lo marcó como roto. Es la única referencia
    `{ref}` del apunte que apunta a un label de ejercicio en vez de a un
    ancla de sección; si el build de MyST la resuelve sin warning, no hace
    falta tocarla.
19. Agregar `ejercicios/bloque_3_algoritmos_estructuras/5_recursion.md` a
    `myst.yml` (falta en la sección "Bloque 3" de ejercicios).
19b. (Hallazgo 38) Corregir o quitar las 2 referencias `{ref}` rotas en
    `ejercicios/bloque_2_memoria/3_archivos.md`,
    `3b_ejercicios_archivos.md` (`capitulo-archivos-texto`) y
    `5_punteros_2.md` (`capitulo-aritmetica-punteros`) — apuntar a las
    anclas reales `capitulo-archivos-texto` → no existe, usar
    `{ref}`capitulo-modelo-memoria`` o el ancla correcta de
    `4_archivos_texto.md`; y `capitulo-aritmetica-punteros` → probablemente
    `introduccion_aritmetica_punteros` en `6_aritmetica.md`. Verificar caso
    por caso antes de reemplazar.

**Costo estimado**: 1-2 horas. **Riesgo si no se hace**: navegación rota
silenciosa — el lector hace clic y llega a un 404 o a MyST resolviendo mal la
ruta.

---

## Fase 2b — Barrido de enlaces rotos en `ejercicios/` (hallazgo T8, fuera del alcance original)

`ejercicios/` no estaba en el alcance de la auditoría inicial (que cubrió los
4 bloques de `apunte/`). Al reutilizar el script de detección de la Fase 2
sobre este directorio aparecieron 59 enlaces rotos (detalle completo en T8 de
`informe_calidad.md`). Se separa de la Fase 2 porque una parte no es un
simple problema de ruta:

39. **33 enlaces a nombres de bloque viejos** (`bloque_2_proyectos`,
    `bloque_3_memoria_estatica`, `bloque_4_dinamica_interfaces`,
    `bloque_4_dinamica_indireccion`) — mismo mapeo mecánico que la Fase 2,
    aplicado a `ejercicios/bloque_1_fundamentos/{7_librerias_ejercicios,
    8_compilacion_y_makefiles}.md`, `ejercicios/bloque_2_memoria/{2_arreglos,
    2b_cadenas,4_memoria_dinamica,4b_memoria,4c_ejercicios_memoria,
    7_alias_tipos_ejercicios,8_enums}.md`,
    `ejercicios/bloque_3_algoritmos_estructuras/1_matrices.md` y
    `ejercicios/bloque_4_avanzados/2_operaciones_de_bits.md`.
40. **1 enlace** en `ejercicios/readme.md` a `../apunte/0_estilo.md` (mismo
    archivo inexistente que el hallazgo de `4_funciones.md` en la Fase 2;
    reemplazar por referencias `{ref}` a los códigos `0xXXXXh` puntuales, no
    por un único archivo).
41. **47 enlaces a una numeración plana vieja de `reglas/`**
    (`0_sintaxis.md`, `1_control.md`, `2_funciones.md`,
    `5_buenas_practicas.md`), concentrados en
    `bloque_1_fundamentos/4_testing_y_estructura.md` (18) y
    `9_refactorizacion_codigo_ofuscado.md` (14). A diferencia de los puntos
    39-40, esto **no es un simple rename**: cada mención genérica a
    "`reglas/2_funciones.md`" hay que resolverla a la regla `0x2XXXh`
    concreta que el texto está citando, usando `reglas/renumeracion.md` como
    mapa, y convertirla a `{ref}`0xXXXXh`` (el patrón que ya usa el resto del
    apunte). Requiere leer cada cita en contexto, no admite `sed` masivo.

**Costo estimado**: 1 hora para 39-40 (mecánico); 3-4 horas para 41 (requiere
lectura caso por caso). **Riesgo si no se hace**: los enlaces desde los
ejercicios hacia las reglas de estilo citadas —justamente el material que un
estudiante consulta al resolver un ejercicio— no llevan a ningún lado.

---

## Fase 3 — Decisiones de contenido (huérfanos y placeholders)

Estas tareas requieren decidir, no solo ejecutar. Recomiendo resolverlas en
una sola sesión de trabajo mirando ambos bloques a la vez, porque hay
solapamiento directo entre bloque 3 y bloque 4 (serialización y estructuras
opacas aparecen en ambos).

20. **Bloque 3 — ampliaciones**:
    - Integrar a `myst.yml` y enlazar desde su capítulo principal:
      `1E_rendimiento_memoria.md` y `1F_seguridad_memoria.md` (tienen
      contenido real).
    - Eliminar por redundancia pura con `bloque_2/6_aritmetica.md`:
      `1B_matrices_vla.md`, `1D_fragmentacion_matrices.md`,
      `6D_fragmentacion_matrices.md` (este último además duplica casi
      palabra por palabra a `1D`).
    - `1C_matrices3d.md`: decidir si se fusiona su fórmula de indexación
      dentro de `1A_matrices_dinamicas.md` (mismo tema, mayor cohesión) o se
      elimina por ser un placeholder de una fórmula sin desarrollo.
    - `7E_serializacion.md` y `7F_estructuras_opacas.md`: ver punto 21 antes
      de decidir (dependen de qué se haga con bloque 4).
22. **Reconciliar `reporte.md`** (sin commitear, raíz del repo): una vez
    tomadas las decisiones de 20-21, actualizar ese documento para que
    refleje el estado real, o archivarlo/eliminarlo si ya cumplió su
    propósito. Evita que quede como fuente de verdad falsa para futuras
    ediciones.


**Costo estimado**: 2-3 horas de decisión + 3-5 horas de escritura según lo
que se elija desarrollar. **Riesgo si no se hace**: el repo sigue
acumulando contenido fantasma que ningún lector ve y que confunde a quien
edite después (ya pasó dos veces: bloque 2 tenía el mismo patrón antes de la
fusión de esta sesión).

---

## Fase 4 — Calidad técnica y pedagógica

24. **Quitar los casts de `malloc`/`calloc`/`realloc`** en las 12 soluciones
    de ejercicios de `bloque_2/5_memoria_dinamica.md` (líneas listadas en el
    informe, hallazgo bloque 2 #6) para que no contradigan la regla `0x300Ah`
    citada en el mismo apunte.
25. **Agregar llaves** a los tres `if` de `es_bisiedo` en
    `bloque_1/6_testing_basico.md:293-301` (viola `0x1001h`).
26. **Eliminar la duplicación de ejercicios de Makefiles** entre
    `bloque_1/5_compilacion.md` (~2022-2164) y `8_makefiles.md` (~246-315):
    dejarlos solo en `8_makefiles.md` y, si hace falta continuidad narrativa
    en `5_compilacion.md`, referenciarlos con `{ref}` en vez de repetir el
    texto completo.
27. **Resolver los 5 `<!--TODO: completar-->`** en `2_gradual.md` (130, 150,
    173, 431) y `7_contratos_intro.md:30` — son secciones tituladas y
    vacías, visibles en el sitio.
28. **Agregar ejercicios con solución** a los capítulos que hoy tienen cero:
    `bloque_3/4_testing_avanzado.md`, `bloque_3/5_contratos_formales.md`,
    `bloque_4/9_api_diseno.md`, `bloque_4/11_hilos.md`,
    `bloque_4/12_sockets.md`. Priorizar los dos de bloque 3 primero (son
    capítulos del recorrido principal, no ampliaciones).
29. **Ampliar `bloque_2/10_alias_tipos.md`** con dos secciones nuevas:
    `typedef` de punteros a función y `typedef` de structs/arrays anónimos —
    el patrón `typedef struct {...} nombre_t;` se usa en todo el libro
    (empezando por `7_estructuras.md`) pero nunca se explica formalmente acá.

**Costo estimado**: 4-6 horas. **Riesgo si no se hace**: el material
contradice sus propias reglas de estilo (24, 25) y dos capítulos completos
del recorrido principal quedan sin forma de autoevaluación (28).

---

## Fase 5 — Cosmético / consistencia menor

Bajo impacto individual, pero acumulativo. Bueno para una pasada de
find/replace dedicada, no urgente.

30. `{code-block}c` → `{code-block} c` (con espacio) en `4_funciones.md`,
    `5_compilacion.md`, `6_testing_basico.md` (decenas de instancias).
31. Corregir 7 comentarios de cierre de figura con ruta `1/` en
    `5_compilacion.md` (deberían decir `5/`).
32. Frontmatter: cambiar `description` por `subtitle` en
    `1_modelo_memoria.md`, `4_archivos_texto.md`, `5_memoria_dinamica.md`.
33. Unificar las líneas de subtítulo sin marcado que aparecen tras `##
    Desarrollo` en varios capítulos (ej. "Los Ladrillos de la memoria" en
    `7_estructuras.md:53`): decidir si se convierten en heading `###` o se
    quitan, y aplicar el mismo criterio en todo el libro.
34. Envolver los forward-references suaves a anclas de bloque 2 desde
    `bloque_1/4_funciones.md:436,612` en un admonition `{seealso}` explícito
    en vez de un `{ref}` inline suelto.

**Costo estimado**: 1-2 horas.


## Fase 6 - Mejoras y correcciones en bloque 4

21. **Bloque 4 — familia 13/14**: decidir entre dos caminos, no dejarlo como
    está:
    - **(a) Desarrollar el capítulo 13 real**: escribir
      `13_struct_avanzado.md` como capítulo índice/introductorio, fusionar
      `13D_union.md` (el único con código completo) y `13E_padding_abi.md`
      como sus secciones, agregar a `myst.yml`, y decidir el destino de
      `13C_estructuras_opacas.md` (candidato claro a **eliminar**: es
      puramente redundante con `3_opacos.md`, que ya cubre el tema con 52K y
      9 ejercicios) y `13F_bitfields.md` (candidato a fusionar como nota
      breve dentro de `5_binarios_bitwise.md`, que ya cubre bitfields con
      ejemplos).
    - **(b) Eliminar toda la familia** si no hay planes reales de
      desarrollarla en el corto plazo — mantenerla vacía/huérfana no aporta
      valor y ensucia el repo.
    - En cualquier caso, `13B_serializacion.md` y `14A_enums_avanzados.md`
      son los más aprovechables si se elige (a): tienen frontmatter correcto
      y al menos una idea desarrollable.
    - Esta decisión determina qué pasa con `7E_serializacion.md`/
      `7F_estructuras_opacas.md` de bloque 3 (punto 20): si el tema vive en
      bloque 4, eliminar los de bloque 3 y dejar solo un enlace cruzado; si
      vive en bloque 3, eliminar los de bloque 4.
    - (Hallazgo 37) El bloque huérfano "PARA INTEGRAR" sobre serialización de
      `enum` al final de `12_sockets.md:1948-2037` es contenido ya escrito y
      completo (código + tip) que encaja naturalmente en
      `14A_enums_avanzados.md` si se elige la opción (a): resolvería de paso
      que ese archivo hoy sea el más débil de la familia (un párrafo + 4
      líneas de código). Moverlo implica quitar el marcador `PARA INTEGRAR`
      y las líneas en blanco sobrantes de `12_sockets.md`.
23. **Decisión editorial sobre alcance de `11_hilos.md` y `12_sockets.md`**:
    ¿pertenecen al programa de "Programación 1"? Si sí, marcarlos
    explícitamente como ampliación optativa/de nivelación (con un admonition
    al inicio) y agregarles ejercicios acordes a su tamaño. Si no, evaluar
    moverlos a un apunte de nivel posterior. En cualquier caso, el bloque de
    TLS/OpenSSL en `12_sockets.md` (líneas 1839-1840) es el punto más alejado
    del temario típico y merece la decisión más explícita.
37. **Contenido huérfano sin integrar en `bloque_4_avanzados/12_sockets.md`,
    líneas 1948-2037** (~90 líneas): al final del capítulo, después de la
    sección "Resumen", aparece un bloque delimitado literalmente con
    `PARA INTEGRAR` que desarrolla **serialización de `enum`** — un tema sin
    ninguna relación con sockets. Es casi con certeza contenido que pertenece
    a `14A_enums_avanzados.md` o a `11_enums.md` y quedó pegado al final del
    archivo equivocado. **No se tocó**: es una decisión de ubicación de
    contenido, no una corrección mecánica de heading. Agregar a la Fase 3:
    mover este bloque a donde corresponda (evaluar junto con el punto 21,
    familia 13/14 de bloque 4) y, si el destino es `14A_enums_avanzados.md`,
    aprovecharlo como el desarrollo real que ese archivo hoy no tiene.

---

## Higiene de repositorio (transversal, hacer en paralelo)

- El `git status` actual tiene **17 archivos sin commitear** (6 modificados
  de la fusión de bloque 2 de esta sesión + 11 nuevos de bloque 3 + 7 nuevos
  de bloque 4, más `reporte.md` y esta carpeta `mejora_2/`). Recomiendo
  commitear en al menos 3 tandas lógicas separadas: (1) fusión de bloque 2 ya
  hecha, (2) los nuevos archivos de ampliación de bloque 3/4 tal como están
  hoy —para tener un punto de referencia antes de tocarlos en la Fase 3—, (3)
  este informe y plan.
- Antes de borrar cualquier archivo huérfano de la Fase 3, confirmar que no
  hay trabajo en curso de otra persona sobre esos archivos (son todos de la
  misma tanda de edición del 21/9, mismo timestamp — probablemente seguro,
  pero vale la pena preguntar si hay contexto que este informe no capturó).

---

## Resumen de esfuerzo total estimado

| Fase | Foco | Estimado | Estado |
| --- | --- | --- | --- |
| 0 | Bugs de render bloqueantes | 30-45 min | ✅ Completada |
| 1 | H1/headings/anclas | 3-4 h | ✅ Completada |
| 2 | Enlaces rotos en `apunte/` (13-19, 19b) | 1-2 h | ✅ Completada |
| 2b | Enlaces rotos en `ejercicios/` (39-41) | 4-5 h | Pendiente |
| 3 | Decisiones de contenido + desarrollo | 5-8 h | Pendiente |
| 4 | Calidad técnica/pedagógica | 4-6 h | Pendiente |
| 5 | Cosmético | 1-2 h | Pendiente |
| **Total** | | **~19-28 h** | |

Las fases 0 y 1 dejaron 4 hallazgos nuevos (ver sección "Hallazgos
adicionales" entre Fase 1 y Fase 2), ya incorporados a las fases 2 y 3
correspondientes.
