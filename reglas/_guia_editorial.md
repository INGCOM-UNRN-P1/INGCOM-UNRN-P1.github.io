---
title: "Guía editorial interna para la redacción de reglas y antipatrones"
short_title: "Guía editorial"
subtitle: "Plantilla canónica, criterios de exhaustividad y convenciones MyST del catálogo de cátedra"
---

(guia-editorial)=
# Guía editorial interna para la redacción de reglas y antipatrones

Este documento es de uso interno del equipo docente. **No forma parte del
recorrido público del libro**; describe cómo se redacta cada ficha para que
todo el catálogo resulte uniforme, verificable y pedagógicamente sólido.

## 1. Principios de redacción

Toda ficha debe poder responder, sin que el lector consulte otra fuente, estas
cinco preguntas:

1. ¿Qué exige exactamente la norma? (enunciado normativo, sin ambigüedad)
2. ¿Por qué existe? (causa raíz: error de compilación, comportamiento
   indefinido, bug silencioso, deuda de mantenibilidad o vulnerabilidad)
3. ¿Cómo se ve una violación real? (contraejemplos tomados del código
   estudiantil típico)
4. ¿Cómo se corrige? (código conforme idiomático, no solo "lo correcto")
5. ¿Cómo la detecto y verifico? (herramienta, comando, señal observable)

Reglas de oro:

- **Un hecho por afirmación.** No mezclar justificación y ejemplo en la misma
  frase.
- **Explicar el "porqué" antes del "cómo".** El estudiante debe entender la
  consecuencia antes de memorizar la forma.
- **Nombrar el mecanismo.** "Es peligroso" no enseña; "desreferenciar un
  puntero a un marco de pila ya destruido produce comportamiento indefinido
  (C11 §6.5.3.2)" sí.
- **Contraste antes/después.** Todo concepto se ancla con un par
  ❌/✅ mínimamente ejecutable.
- **Español rioplatense, voseo, código en inglés.** El texto en español; los
  identificadores y la sintaxis en inglés (`while`, `return`, `size_t`).

## 2. Plantilla canónica de una regla de estilo

```markdown
---
title: "Regla 0xXXXXh: <título canónico>"
short_title: "0xXXXXh"
subtitle: "<Categoría larga (0xYYXX)>"
---

(0xXXXXh)=
# 0xXXXXh: <título canónico>

:::{admonition} Categoría: <Categoría larga (0xYYXX)>
:class: note
Código de regla: `0xXXXXh` | Soporta corrección automática: **Sí/No**
:::

:::{seealso} Antipatrones didácticos relacionados
* **[AP-0xZZZZh: título](ap_0xZZZZh.md)** — una línea de qué defecto cubre.
:::

## Enunciado normativo

> **DEBE** / **NO DEBE** ...

Una o dos frases que fijen el alcance sin ambigüedad.

## ¿Por qué existe esta regla?

### El problema

Explicación causal. Qué ocurre realmente en el compilador, el enlazador, la
pila, el heap o el modelo de memoria.

### Consecuencias de violarla

| Tipo de consecuencia | Efecto concreto |
| :--- | :--- |
| Compilación | ... |
| Comportamiento indefinido | ... |
| Bug silencioso | ... |
| Mantenibilidad | ... |

### Fundamento en el estándar y en la cátedra

Referencia normativa (ISO/IEC 9899:2011 §...) y por qué la cátedra la adopta
como obligatoria.

## Alcance y excepciones

Qué cubre, qué no, y los casos legítimamente exceptuados. Si no hay
excepciones, decirlo explícitamente.

## Ejemplos exhaustivos

### ❌ Contraejemplo 1 — <nombre del defecto>

```c
...
```

Por qué falla: ...

### ❌ Contraejemplo 2 — ...

### ✅ Ejemplo conforme 1 — ...

### ✅ Ejemplo conforme 2 — ...

### ⚠️ Casos límite

Discusión de bordes: valores extremos, tipos, plataformas, refactorizaciones.

## Cómo detectarla

| Herramienta | Comando | Señal |
| :--- | :--- | :--- |
| `gaff` | `gaff check archivo.c` | ... |
| `gcc` / `clang` | `gcc -Wall -Wextra -std=c11 ...` | ... |

## Checklist de autocontrol

- [ ] ...
- [ ] ...

## Reglas relacionadas

* {ref}`0xYYYYh` — relación (complementa / refuerza / puede entrar en tensión).
```

## 3. Plantilla canónica de un antipatrón didáctico

Los antipatrones documentan el **defecto observado**, no la norma. Su código
siempre es `AP-0xXXXXh` y debe declarar la regla que lo norma.

```markdown
---
title: "Antipatrón AP-0xXXXXh: <título>"
short_title: "AP-0xXXXXh"
subtitle: "<Categoría larga (0xYYXX)>"
---

(ap_0xXXXXh)=
# Antipatrón AP-0xXXXXh: <título>

:::{admonition} Regla de Estilo Asociada: 0xYYYYh
:class: tip
La transgresión descripta se encuentra normada por la
**[0xYYYYh: <título>](0xYYYYh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0xXXXXh` | Categoría: <Categoría larga>
:::

## Síntoma en el código del estudiante

Cómo se reconoce a simple vista.

## Diagnóstico

### Mecanismo del defecto

Qué hace realmente el compilador o el runtime.

### Consecuencia observable

Mensaje de error, fallo en runtime, resultado incorrecto.

## Fundamento en el estándar C11

## Corrección idiomática

### ❌ Código con el antipatrón

```c
...
```

### ✅ Código refactorizado

```c
...
```

## Errores típicos al compilar o ejecutar

```text
...
```

## Checklist de verificación

- [ ] ...

## Reglas relacionadas

* {ref}`0xYYYYh` — ...
```

## 4. Convenciones MyST obligatorias

- **Frontmatter:** siempre `title`, `short_title`, `subtitle`. No omitir
  ninguno.
- **Ancla:** la línea `(0xXXXXh)=` (o `(ap_0xXXXXh)=`) debe permanecer
  **exacta**; de ella dependen los `{ref}` distribuidos en todo el apunte.
- **Jerarquía:** un único `#` (H1) por archivo, luego `##` (H2) y `###` (H3).
  Nunca saltar de H1 a H3.
- **Directivas MyST:** usar vallas de dos puntos (`:::{admonition}`) y
  cerrarlas con `:::`. Los bloques de código usan vallas triples con lenguaje
  (` ```c `).
- **Referencias cruzadas:** usar `{ref}`0xXXXXh`` sólo si el ancla existe. No
  inventar códigos.
- **Sin código comentado** ni bloques vacíos.
- **Longitud:** una ficha de regla razonable ronda entre 90 y 160 líneas;
  ninguna debe quedar por debajo de 60.
- **ASCII:** los identificadores no llevan tildes ni `ñ`; el texto narrativo sí.

## 5. Criterios de exhaustividad de los ejemplos

Una ficha cumple el estándar editorial sólo si:

1. Aporta **al menos dos contraejemplos distintos** (no variantes del mismo).
2. Aporta **al menos dos ejemplos conformes**, uno de ellos con el caso
   general y otro que muestre la interacción con otras reglas.
3. Incluye **una sección de casos límite** con valores extremos
   (`INT_MAX`, cadenas vacías, `NULL`, `0`) cuando el dominio lo permita.
4. Cada ejemplo lleva una frase de justificación, no sólo el código.
5. No repite textualmente el enunciado de la regla en la justificación.

## 6. Ejemplo completo de referencia

Las fichas {ref}`0x6001h` y {ref}`0x2014h` de este mismo directorio son las
fichas de referencia canónica. Toda ficha nueva o reescrita debe parecerse a
ellas en estructura y profundidad.
