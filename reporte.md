# Auditoría y propuesta de secuenciación — `apunte/bloque_2_memoria`

:::{important} Estado de este documento (reconciliado)

Este documento es la **auditoría original de bloque 2** que motivó gran parte
del trabajo posterior. Las secciones 1-9 (diagnóstico y plan) siguen siendo
un registro histórico válido de por qué se tomaron las decisiones de
secuenciación y separación de contenido. La **sección 10 ("Estado de
implementación") estaba desactualizada** — afirmaba que se habían creado
archivos de ampliación (`4A`, `5B`-`5D`, `6B`-`6D`, `7B`, `7C`, `11A`) que en
realidad nunca se escribieron, y que los que sí existían (`1A`, `1B`, `1C`,
`5A`, `6A`, `7A`, `8A`, `9A`) seguirían siendo archivos separados — cuando en
esta sesión se fusionó su contenido directamente dentro de los capítulos
principales en vez de mantenerlos aparte. Se corrigió abajo para reflejar el
estado real.

**Para el estado de calidad vigente de todo `apunte/` (no solo bloque 2) y el
plan de acción activo, la fuente de verdad es
[`mejora_2/informe_calidad.md`](mejora_2/informe_calidad.md) y
[`mejora_2/plan_accion.md`](mejora_2/plan_accion.md)**, que además cubren
bloque 1, 3, 4 y `ejercicios/`, fuera del alcance de este documento.

:::

## Criterio de intervención

La numeración principal se conserva porque forma parte de la navegación y de las referencias existentes. El objetivo no es renombrar todo el bloque, sino convertir los capítulos principales en un recorrido progresivo y sacar del camino obligatorio los contenidos de ampliación.

**Decisión definitiva:** `apunte/bloque_2_memoria` conserva toda su estructura y es
la fuente canónica de memoria, representación y ownership. No se trasladan
capítulos al Bloque 3. Los enlaces del Bloque 3 son puentes de aplicación y no
reemplazan a los apuntes del bloque 2.

La convención propuesta es:

```text
N_tema.md       contenido principal, necesario para continuar
NA_tema.md      ampliación avanzada del capítulo N
NB_tema.md      segunda ampliación avanzada del capítulo N
```

Los capítulos avanzados no deben ser prerrequisitos de capítulos posteriores. Las referencias a ellos deben aparecer como “lectura avanzada” o “continuación opcional”.

## Fase A — Diagnóstico

### 1. Problema global de secuenciamiento

El orden actual es:

```text
1 modelo de memoria
2 punteros
3 secuencias
4 archivos
5 memoria dinámica
6 aritmética de punteros
7 estructuras
8 números
9 casts
10 typedef
11 enum
```

Las dependencias reales no siguen ese orden:

- `malloc`, `sizeof`, `size_t` y los tamaños de matrices requieren tipos numéricos y conversiones que aparecen en 8 y 9.
- `5_memoria_dinamica.md` declara `struct` como prerrequisito aunque el capítulo principal de estructuras es el 7.
- El propio capítulo 5 dice que “sigue a estructuras y tipos” ([líneas 18–22](apunte/bloque_2_memoria/5_memoria_dinamica.md:18)), contradiciendo su posición.
- `6_aritmetica.md` profundiza en estructuras con punteros y enlaza al capítulo 7 antes de que el estudiante lo haya recorrido ([líneas 17–22](apunte/bloque_2_memoria/6_aritmetica.md:17)).
- `7_estructuras.md` usa `malloc`, `free`, `enum`, `bool`, `time_t` y tipos de `<stdint.h>` sin que todos estén consolidados como prerrequisitos.
- `10_alias_tipos.md` y `11_enums.md` están correctamente ubicados después de varios usos de `typedef` y `enum`, pero sus conceptos se usan antes en ejemplos de 6 y 7.

### 2. Secuencia principal recomendada

Sin cambiar la numeración, el recorrido obligatorio debería quedar conceptualmente así:

```text
1 modelo de memoria
8 números y tamaños básicos
9 conversiones y casts
2 punteros
3 secuencias
5 memoria dinámica
6 aritmética de punteros y matrices básicas
7 estructuras básicas
10 typedef
11 enums
4 archivos
```

La numeración física puede mantenerse por compatibilidad, pero el índice o la documentación del bloque debe declarar esta dependencia conceptual. Como mejora posterior, puede evaluarse renumerar el bloque, pero no es necesario para resolver el problema actual.

### 3. Carga cognitiva

El bloque ronda las 16.000 líneas. Los capítulos 5, 6 y 7 tienen aproximadamente 2290, 1844 y 2516 líneas. Se mezclan tres niveles que deben separarse:

1. fundamentos obligatorios;
2. buenas prácticas de implementación;
3. ABI, allocator, explotación, SIMD, caché y detalles de hardware.

El camino principal debe responder una pregunta por capítulo. Las explicaciones de allocator, ensamblador, matrices 3D, layouts especializados, optimización de caché y explotación deben ir a archivos `A`, `B`, etc.

## 4. `5_memoria_dinamica.md`: núcleo obligatorio

### Resultado: núcleo conservado y completado

1. duración y propiedad;
2. `malloc`;
3. comprobación de `NULL`;
4. `sizeof(*puntero)`;
5. `free`;
6. fuga, dangling pointer, double free y acceso fuera de límites;
7. `calloc`;
8. `realloc` con puntero temporal;
9. ownership y simetría crear/destruir;
10. ejercicios compilables.

### Resultado: lecturas fuera del camino principal

Mover a los siguientes apuntes:

- `5A_allocator.md`: allocator, overhead, first fit, best fit, next fit, listas segregadas, coalescing, `sbrk` y `mmap`.
- `5B_seguridad_memoria.md`: UAF como vulnerabilidad, double free explotable, buffer overflow y modelos de ataque.
- `5C_rendimiento_memoria.md`: fragmentación, pools y costo de asignaciones; la comparación algorítmica continúa en el Bloque 3.
- `5D_ensamblador_stack.md`: prólogo y epílogo x86-64; la conexión pedagógica con recursividad está en el Bloque 3.

### Correcciones técnicas aplicadas

- Precisar el estado de `realloc(ptr, 0)` por versión del estándar; mantener únicamente la recomendación práctica de usar `free`.
- No afirmar que `calloc` convierte necesariamente todos los campos puntero en `NULL`; distingue “bits cero” de “puntero nulo”.
- No decir que `free` devuelve siempre memoria al sistema operativo: normalmente la devuelve al allocator del proceso.
- Aclarar que asignar `NULL` solo invalida la variable anulada; no elimina aliases colgantes.
- Separar “puntero no nulo” de “puntero válido”.
- Controlar overflow antes de `cantidad * sizeof(T)` y de todas las multiplicaciones de tamaños.
- Eliminar “tamaño ilimitado” como descripción de `malloc`.
- Reemplazar la recomendación simplista de `strncpy` por una API con capacidad explícita o `snprintf`.
- Completar las secciones marcadas `TODO` antes de presentar el capítulo como terminado.

El ejemplo de buffer overflow usa `datos_maliciosos_largos` sin declarar y no incluye `<string.h>` ([líneas 872–881](apunte/bloque_2_memoria/5_memoria_dinamica.md:872)). Debe compilarse o marcarse explícitamente como pseudocódigo.

## 5. `6_aritmetica.md`: núcleo obligatorio

### Problema actual

El capítulo se llama aritmética de punteros, pero comienza con unas 250 líneas que repiten memoria dinámica, fragmentación, `calloc`, `realloc`, `memset`, `memcpy` y VLA. La aritmética aparece demasiado tarde.

### Secuencia interna propuesta

1. `a[i]` como `*(a + i)`;
2. escala de `p + 1` según `sizeof(*p)`;
3. rango válido y puntero one-past-the-end;
4. resta de punteros del mismo arreglo;
5. recorrido y búsqueda con punteros;
6. doble indirección;
7. matriz dentada;
8. bloque contiguo con índice lineal;
9. puntero a array para columnas constantes;
10. liberación y ownership de cada representación.

### Apuntes avanzados derivados

- `6A_matrices3d.md`: matrices tridimensionales, layouts contiguos y punteros a arrays multidimensionales.
- `6B_matrices_vla.md`: VLA y tipos modificados variables, explicado como extensión/variante de C99 y separado de la regla de la cátedra.
- `6C_memcpy_memmove.md`: copia de objetos, solapamiento, representación de bytes y límites de aliasing.
- `6D_fragmentacion_matrices.md`: fragmentación, pools y comparación de representaciones con mediciones.

### Correcciones técnicas necesarias

- Eliminar la repetición de contenidos de 5 o convertirla en un breve repaso con enlaces.
- Reparar el bloque de doble indirección: contiene texto corrupto como `o reasignar memoria` y `original if (*ptr != NULL)` ([líneas 700–714](apunte/bloque_2_memoria/6_aritmetica.md:700)).
- Reparar comentarios partidos como `memoria asignada` en el ejemplo de recursos.
- Usar `size_t` para filas, columnas e índices.
- Verificar overflow en `filas * columnas * sizeof(T)`.
- Renombrar “Bloque Único con Cast Avanzado”: no hay un cast; es un puntero a array (`int (*matriz)[COLUMNAS]`).
- Presentar primero un arreglo unidimensional antes de saltar a matrices dinámicas.
- Explicar que prohibir VLA es una decisión de la cátedra; no afirmar que el estándar C los prohíbe.

## 6. `7_estructuras.md`: núcleo obligatorio

### Debe conservar

1. declaración de `struct`;
2. inicialización, copia y acceso;
3. `.` frente a `->`;
4. punteros a estructuras;
5. estructuras con miembros dinámicos;
6. destructor y liberación en orden inverso;
7. padding básico y `sizeof`/`offsetof`.

### Apuntes avanzados derivados

- `7A_union.md`: `union`, miembro activo, representaciones y tagged unions.
- `7B_padding_abi.md`: alineación, ABI, padding final, `offsetof`, `alignof` y diferencias entre plataformas.
- `7C_bitfields.md`: campos de bits, orden, padding y portabilidad.
- `7D_aos_soa.md`: AoS, SoA, caché y SIMD.
- `7E_serializacion.md`: serialización, endianness, protocolos y por qué no debe copiarse una estructura directamente a la red.
- `7F_estructuras_opacas.md`: punteros opacos, invariantes y encapsulación de TAD.

### Correcciones técnicas necesarias

- Corregir ejemplos no compilables: `conexión bool usar_tls`, `etc.char descripcion` y `específico char firma_digital` ([líneas 415–473](apunte/bloque_2_memoria/7_estructuras.md:415)).
- Añadir headers completos para `bool`, `time_t`, `int32_t`, `uint32_t`, `uint8_t` y funciones de cadenas.
- Declarar y validar `nombre` en el constructor dinámico de `persona_t`.
- Hacer coherente el destructor con el patrón de doble puntero; si debe anular el puntero del llamador, recibir `persona_t **`.
- Presentar `offsetof` como macro, no como prototipo de función.
- Distinguir garantías del estándar, decisiones del ABI y observaciones de GCC/x86-64.
- No definir alineación como “múltiplo del tamaño del tipo”; son propiedades relacionadas pero no idénticas.
- Presentar ordenar miembros “de mayor a menor” como heurística que debe verificarse con `sizeof` y `offsetof`, no como regla universal.
- Reformular la explicación de `union`: el tamaño puede incluir padding y la lectura de miembros alternativos requiere explicar las reglas del estándar y las dependencias de implementación.
- No anunciar bit-fields como objetivo del capítulo principal si se desarrollan únicamente en un apunte avanzado.
- Retirar del texto principal la sección “¿Entra en el parcial?”.

## 7. Otros capítulos del camino principal

### `1_modelo_memoria.md`

Debe quedar como base conceptual: objetos, duración, almacenamiento automático/estático/dinámico, stack/heap como modelo práctico y límites del modelo. La jerarquía de caché, MMU y detalles físicos deben pasar a `1A_hardware_memoria.md`.

### `8_numeros.md`

Debe adelantarse conceptualmente aunque conserve su nombre. Tiene que introducir antes de memoria dinámica:

- `sizeof`;
- `size_t`;
- rangos;
- overflow de tamaños;
- promociones básicas.

El tratamiento de IEEE 754 y errores numéricos puede pasar a `8A_punto_flotante.md`.

### `9_casts.md`

Debe cubrir solo conversiones necesarias para leer los ejemplos del bloque. El aliasing, reinterpretación de bits y conversiones dependientes de representación pueden pasar a `9A_aliasing_reinterpretacion.md`.

### `10_alias_tipos.md` y `11_enums.md`

Pueden mantenerse en el camino principal, pero deben aparecer antes de los ejemplos que ya usan `typedef` y `enum`. Las enumeraciones defensivas, namespaces y máquinas de estados pueden extenderse en `11A_enums_avanzados.md`.

### `4_archivos_texto.md`

Debe quedar después de cadenas y ownership. El acceso aleatorio, buffering avanzado y archivos binarios pueden derivarse a `4A_archivos_avanzados.md`.

## 8. Convención de los apuntes avanzados

Cada archivo avanzado debe:

- declarar explícitamente sus prerrequisitos;
- enlazar desde el capítulo principal mediante una sección “Lectura avanzada”;
- no ser necesario para resolver los ejercicios básicos posteriores;
- incluir ejemplos compilables o marcarlos como pseudocódigo;
- separar hechos garantizados por C de detalles de plataforma;
- indicar si presupone Linux, x86-64, GCC o una ABI concreta.

El camino principal debería contener aproximadamente el 60–70 % del contenido actual, pero reducirse a objetivos pequeños, ejemplos compilables y ejercicios con feedback. El resto puede conservarse como ampliación `A`, `B`, etc., sin perder material ni sobrecargar el recorrido obligatorio.

## 9. Prioridad de implementación

1. Crear el índice conceptual del bloque y declarar qué capítulos son camino principal.
2. Recortar 5, 6 y 7, dejando solo los contenidos necesarios para continuar.
3. Crear los apuntes avanzados derivados (`5A`–`5D`, `6A`–`6D`, `7A`–`7F`).
4. Reparar todos los bloques de código corruptos o incompletos.
5. Mover 8 y 9 conceptualmente antes de 5, aunque sus nombres se mantengan.
6. Completar los `TODO` del camino principal.
7. Validar los ejemplos con GCC, `-Wall -Wextra -pedantic` y sanitizers.

La prioridad no es eliminar contenido, sino separar el recorrido mínimo del material de profundización. Así se conserva la estructura de grandes rasgos, se mantienen las referencias existentes y el estudiante puede avanzar desde memoria y punteros hasta estructuras dinámicas sin atravesar primero allocator, SIMD, ABI o explotación.

## 10. Estado de implementación (reconciliado con `mejora_2/`)

La primera ronda de refactorización del bloque hizo lo siguiente,
efectivamente:

- se corrigieron los ejemplos corruptos de doble indirección y estructuras
  citados en las secciones 4-6 (`datos_maliciosos_largos` sin declarar,
  `conexión bool usar_tls`, `etc.char descripcion`, comentarios partidos como
  `o reasignar memoria` en aislamiento) — verificado: ninguno de esos
  fragmentos corruptos aparece ya en `5_memoria_dinamica.md`,
  `6_aritmetica.md` ni `7_estructuras.md`;
- se corrigieron las explicaciones de `calloc`, `realloc`, `free`, VLA,
  `offsetof`, padding y `union` señaladas en las correcciones técnicas;
- se agregó una comprobación explícita de overflow para tamaños de asignación;
- se reemplazó la recomendación insegura de `strncpy` por una copia basada en
  capacidad y `snprintf`;
- se completaron los `TODO`/`COMPLETAR` pendientes del camino principal de
  bloque 2.

Lo que **no** ocurrió como estaba planeado, y se corrige acá: **no se creó la
familia completa de archivos `A`-`D` por capítulo.** Solo llegaron a existir
`1A_hardware_memoria.md`, `1B_stack_frames.md`, `1C_ensamblador_stack.md`,
`5A_allocator.md`, `6A_memcpy_memmove.md`, `7A_aos_soa.md`,
`8A_punto_flotante.md` y `9A_aliasing_reinterpretacion.md` — nunca se
escribieron `4A_archivos_avanzados.md`, `5B_seguridad_memoria.md`,
`5C_rendimiento_memoria.md`, `5D_ensamblador_stack.md` (ese contenido quedó
en `1C_ensamblador_stack.md`), `6B_matrices_vla.md`, `6C_memcpy_memmove.md`
(el contenido real terminó en `6A_memcpy_memmove.md`), `6D_fragmentacion_matrices.md`,
`7B_padding_abi.md`, `7C_bitfields.md`, `7D_aos_soa.md` (contenido real en
`7A_aos_soa.md`), `7E_serializacion.md`, `7F_estructuras_opacas.md` ni
`11A_enums_avanzados.md`. `myst.yml` e `indice.md` sí llegaron a referenciar
varios de esos nombres inexistentes, lo cual generaba navegación rota (ver
`mejora_2/informe_calidad.md`, hallazgos de bloque 2).

**Corrección aplicada en la sesión que reconcilia este documento** (ver
`mejora_2/plan_accion.md`, Fase 1 de la fusión de bloque 2): en vez de
completar la familia `A`-`D` faltante, se **fusionó el contenido de los 8
archivos que sí existían directamente dentro de sus capítulos principales**
(`1_modelo_memoria.md`, `5_memoria_dinamica.md`, `6_aritmetica.md`,
`7_estructuras.md`, `8_numeros.md`, `9_casts.md`) como secciones "Lectura
avanzada" o "Alcance" internas, con anclas propias para referencias
cruzadas, y se **eliminaron los 8 archivos satélite**. La convención
`NA_tema.md` para bloque 2 queda abandonada: bloque 2 no tiene archivos de
ampliación separados. (Los temas de matrices 3D, VLA, uniones, bitfields,
serialización y estructuras opacas que iban a vivir en `6B`-`6D`/`7B`-`7F`
nunca llegaron a escribirse ni antes ni después de esta fusión; siguen sin
cobertura dedicada en bloque 2, y **no deben confundirse** con los archivos
de nombre similar que sí existen en `bloque_3_algoritmos_estructuras/`
—`1C_matrices3d.md`, `1B_matrices_vla.md`, `6D_fragmentacion_matrices.md`,
`7E_serializacion.md`, `7F_estructuras_opacas.md`—, que son ampliaciones
propias de ese bloque, con su propio contenido, y cuyo destino se decide en
la Fase 3 de `mejora_2/plan_accion.md`.)

Sobre los puentes al Bloque 3: se **crearon 3 de los 4 planeados**
(`1A_matrices_dinamicas.md`, `2A_ownership_tads.md`,
`6A_localidad_representacion.md`, enlazados desde `1_matrices.md`,
`2_tad.md` y `6_complejidad.md` respectivamente). El cuarto,
`7A_stack_frames.md` (puente desde `7_recursividad_intro.md`), **nunca se
creó**, pese a que `myst.yml`, `indice.md` y el propio
`7_recursividad_intro.md` lo referenciaban como si existiera — enlace roto
detectado y corregido en la Fase 0 de `mejora_2/plan_accion.md`,
redirigiendo esas tres referencias a la sección "Anatomía de un Stack Frame"
que ya cubre ese contenido dentro de `bloque_2_memoria/1_modelo_memoria.md`.

En síntesis: el diagnóstico técnico de las secciones 1-9 (qué corregir, qué
mover fuera del camino obligatorio) fue acertado y se ejecutó; el mecanismo
elegido para "mover fuera del camino obligatorio" terminó siendo integración
inline con secciones opcionales en vez de archivos satélite `A`-`D`
separados, y no todos los archivos satélite planeados llegaron a escribirse
antes de ese cambio de rumbo.

## 11. Relación con el Bloque 3 (sin mover la estructura)

El Bloque 3 se conserva como contexto posterior y consumidor de los conceptos de
memoria. La estructura definitiva de `apunte/bloque_2_memoria` no se modifica ni
se trasladan capítulos fuera de ella. Los siguientes límites sirven para evitar
duplicaciones y ordenar enlaces, no para cambiar la ubicación de los apuntes.

### Hallazgos en el Bloque 3

- `1_matrices.md` mezcla matrices estáticas, recorridos y álgebra lineal con
  matrices dinámicas del heap. El Bloque 2 conserva la representación y el
  Bloque 3 aplica algoritmos sobre ella; cada capítulo debe enlazar al otro sin
  redefinir la misma API.
- El constructor de matriz contigua de `1_matrices.md` calcula
  `filas * columnas * sizeof(*matriz)` sin comprobar overflow. La misma
  precondición debe enseñarse una sola vez en el Bloque 2 y reutilizarse aquí.
- `2_tad.md` vuelve a explicar ownership, constructores, destructores,
  estructuras opacas, `void *` y callbacks. Es el lugar correcto para aplicar
  esos patrones, pero debe enlazar al capítulo 5 del Bloque 2 en vez de redefinir
  la semántica básica de `malloc`.
- `3_tad_pilas_colas.md` implementa listas, arreglos dinámicos y `realloc`; su
  foco debe ser la interfaz y la complejidad de `push`, `pop`, `enqueue` y
  `dequeue`, no volver a enseñar cómo reservar memoria.
- `6_complejidad.md` contiene el análisis amortizado de arreglos dinámicos,
  localidad y trade-offs. Por ello `5C_rendimiento_memoria.md` y `7D_aos_soa.md`
  deben ser puentes hacia este capítulo, no contenidos obligatorios del bloque 2.
- `7_recursividad_intro.md` vuelve a explicar stack frames, `rsp`, límites de
  stack y detalles físicos. La recursividad básica debe quedarse con caso base,
  medida decreciente y traza; los detalles de ABI pasan a `7A_stack_frames.md`.
- `5_contratos_formales.md` es el destino natural de invariantes y contratos de
  TAD. En el Bloque 2 solo deben aparecer precondiciones informales de memoria,
  no lógica de Hoare ni `weakest precondition`.

| Tema | Tratamiento definitivo en Bloque 2 | Relación con Bloque 3 |
|---|---|---|
| Matrices | aritmética de punteros, representación, ownership y liberación | algoritmos matriciales, recorridos, row-major y caché consumen esta base |
| Estructuras dinámicas | `malloc`, `free`, miembros puntero y destructor básico | TAD agrega interfaz, representación oculta e invariantes |
| `void *` y callbacks | conversión básica, límites y ownership | TAD aplica genericidad, callbacks y contenedores reutilizables |
| AoS/SoA | explicación introductoria y límites | Bloque 3 puede medir localidad y trade-offs |
| Complejidad | costo local de una asignación y un recorrido | Bloque 3 formaliza Big-O, amortización y espacio |
| Stack frames | duración automática y retorno de funciones | recursividad puede ampliar con ABI x86-64 |
| Contratos | precondiciones y ownership informales | Bloque 3 formaliza invariantes, `assert` y Hoare |

### Transferencias concretas (reconciliado)

1. `6_aritmetica.md` enlaza a `1_matrices.md` como aplicación posterior, sin
   delegar allí la explicación de ownership o liberación.
2. ~~`6A_matrices3d.md`, `7D_aos_soa.md` y `7F_estructuras_opacas.md`
   permanecen dentro del Bloque 2~~ — **no existen archivos con esos nombres
   en bloque 2** (ver sección 10). El equivalente de `7D_aos_soa.md` es
   `7A_aos_soa.md`, fusionado dentro de `7_estructuras.md`. Matrices 3D y
   estructuras opacas no tienen ampliación dedicada en bloque 2; existen
   `1C_matrices3d.md` y `7F_estructuras_opacas.md` en **bloque 3**, con
   contenido propio de ese bloque, sin relación de fusión con bloque 2.
3. El ejemplo `arreglo_t` permanece en memoria dinámica como integración de
   ownership. `2_tad.md` puede reutilizarlo como caso de estudio sin copiar su
   implementación.
4. ~~`5D_ensamblador_stack.md` se enlaza desde recursividad~~ — ese archivo no
   llegó a crearse; el contenido de ensamblador x86-64 vive en
   `1C_ensamblador_stack.md`, fusionado dentro de
   `1_modelo_memoria.md`/`5_memoria_dinamica.md`. `7_recursividad_intro.md`
   enlaza a esa sección real (ancla
   `funcionamiento-de-la-pila-en-ensamblador-x86-64`), no a un archivo
   `5D`/`7A` separado — ver Fase 0 de `mejora_2/plan_accion.md`.
5. La sección de contratos de estructuras de 7 permanece informal; la lógica de
   Hoare y `weakest precondition` queda exclusivamente en el Bloque 3.

### Nuevo recorrido entre bloques

```text
Bloque 2: memoria y representación
  arreglos → punteros → malloc/free → matrices como representación
                         ↓
Bloque 3: algoritmos y estructuras
  matrices y recorridos → TAD e interfaz → listas/pilas/colas
  → complejidad → contratos → testing → recursividad
```

El principio de relación es simple: el bloque 2 enseña **cómo viven y se
representan los objetos**; el bloque 3 enseña **qué algoritmos y abstracciones se
construyen sobre ellos**, sin alterar la estructura definitiva del bloque 2.
