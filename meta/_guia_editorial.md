---
title: "Guía editorial interna para la redacción de reglas y antipatrones"
short_title: "Guía editorial"
subtitle: "Plantilla canónica, criterios de exhaustividad y convenciones MyST del catálogo de cátedra"
---

(guia-editorial-interna-para-la-redaccion-de-reglas-y-antipatrones)=
# Guía editorial interna para la redacción de reglas y antipatrones

Este documento es de uso interno del equipo docente. **No forma parte del
recorrido público del libro**; describe cómo se redacta cada ficha para que
todo el catálogo resulte uniforme, verificable y pedagógicamente sólido.

(1-principios-de-redaccion)=
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

(2-plantilla-canonica-de-una-regla-de-estilo)=
## 2. Plantilla canónica de una regla de estilo

```{code-block} markdown
:linenos:
---
title: "Regla 0xXXXXh: <título canónico>"
short_title: "0xXXXXh"
subtitle: "<Categoría larga (0xYYXX)>"
---

(0xxxxxh-titulo-canonico)=
# 0xXXXXh: <título canónico>

:::{admonition} Categoría: <Categoría larga (0xYYXX)>
:class: note
Código de regla: `0xXXXXh` | Soporta corrección automática: **Sí/No**

:::
<!-- {admonition} Categoría: <Categoría larga (0xYYXX)> -->

:::{seealso} Antipatrones didácticos relacionados

* **[AP-0xZZZZh: título](../reglas/ap_0xZZZZh.md)** — una línea de qué defecto cubre.

:::
<!-- {seealso} Antipatrones didácticos relacionados -->

(enunciado-normativo)=
## Enunciado normativo

> **DEBE** / **NO DEBE** ...

Una o dos frases que fijen el alcance sin ambigüedad.

(por-que-existe-esta-regla)=
## ¿Por qué existe esta regla?

(el-problema)=
### El problema

Explicación causal. Qué ocurre realmente en el compilador, el enlazador, la
pila, el heap o el modelo de memoria.

(consecuencias-de-violarla)=
### Consecuencias de violarla

| Tipo de consecuencia | Efecto concreto |
| :--- | :--- |
| Compilación | ... |
| Comportamiento indefinido | ... |
| Bug silencioso | ... |
| Mantenibilidad | ... |

(fundamento-en-el-estandar-y-en-la-catedra)=
### Fundamento en el estándar y en la cátedra

Referencia normativa (ISO/IEC 9899:2011 §...) y por qué la cátedra la adopta
como obligatoria.

(alcance-y-excepciones)=
## Alcance y excepciones

Qué cubre, qué no, y los casos legítimamente exceptuados. Si no hay
excepciones, decirlo explícitamente.

(ejemplos-exhaustivos)=
## Ejemplos exhaustivos

(contraejemplo-1-nombre-del-defecto)=
### ❌ Contraejemplo 1 — <nombre del defecto>

```` c
...
````
<!-- c -->

Por qué falla: ...

(contraejemplo-2)=
### ❌ Contraejemplo 2 — ...

(ejemplo-conforme-1)=
### ✅ Ejemplo conforme 1 — ...

(ejemplo-conforme-2)=
### ✅ Ejemplo conforme 2 — ...

(casos-limite)=
### ⚠️ Casos límite

Discusión de bordes: valores extremos, tipos, plataformas, refactorizaciones.

(como-detectarla)=
## Cómo detectarla

| Herramienta | Comando | Señal |
| :--- | :--- | :--- |
| `gaff` | `gaff check archivo.c` | ... |
| `gcc` / `clang` | `gcc -Wall -Wextra -std=c11 ...` | ... |

(checklist-de-autocontrol)=
## Checklist de autocontrol

- [ ] ...
- [ ] ...

(reglas-relacionadas)=
## Reglas relacionadas

* {ref}`0xYYYYh` — relación (complementa / refuerza / puede entrar en tensión).

```
<!-- {code-block} markdown -->

(3-plantilla-canonica-de-un-antipatron-didactico)=
## 3. Plantilla canónica de un antipatrón didáctico

Los antipatrones documentan el **defecto observado**, no la norma. Su código
siempre es `AP-0xXXXXh` y debe declarar la regla que lo norma.

```{code-block} markdown
:linenos:
---
title: "Antipatrón AP-0xXXXXh: <título>"
short_title: "AP-0xXXXXh"
subtitle: "<Categoría larga (0xYYXX)>"
---

(antipatron-ap-0xxxxxh-titulo)=
# Antipatrón AP-0xXXXXh: <título>

:::{admonition} Regla de Estilo Asociada: 0xYYYYh
:class: tip
La transgresión descripta se encuentra normada por la
**[0xYYYYh: <título>](../reglas/0xYYYYh.md)**.

:::
<!-- {admonition} Regla de Estilo Asociada: 0xYYYYh -->

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0xXXXXh` | Categoría: <Categoría larga>

:::
<!-- {admonition} Diagnóstico de Antipatrón -->

(sintoma-en-el-codigo-del-estudiante)=
## Síntoma en el código del estudiante

Cómo se reconoce a simple vista.

(diagnostico)=
## Diagnóstico

(mecanismo-del-defecto)=
### Mecanismo del defecto

Qué hace realmente el compilador o el runtime.

(consecuencia-observable)=
### Consecuencia observable

Mensaje de error, fallo en runtime, resultado incorrecto.

(fundamento-en-el-estandar-c11)=
## Fundamento en el estándar C11

(correccion-idiomatica)=
## Corrección idiomática

(codigo-con-el-antipatron)=
### ❌ Código con el antipatrón

```` c
...
````
<!-- c -->

(codigo-refactorizado)=
### ✅ Código refactorizado

```` c
...
````
<!-- c -->

(errores-tipicos-al-compilar-o-ejecutar)=
## Errores típicos al compilar o ejecutar

```` text
...
````
<!-- text -->

(checklist-de-verificacion)=
## Checklist de verificación

- [ ] ...

(reglas-relacionadas)=
## Reglas relacionadas

* {ref}`0xYYYYh` — ...

```
<!-- {code-block} markdown -->

(4-convenciones-myst-obligatorias)=
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

(5-criterios-de-exhaustividad-de-los-ejemplos)=
## 5. Criterios de exhaustividad de los ejemplos

Una ficha cumple el estándar editorial sólo si:

1. Aporta **al menos dos contraejemplos distintos** (no variantes del mismo).
2. Aporta **al menos dos ejemplos conformes**, uno de ellos con el caso
   general y otro que muestre la interacción con otras reglas.
3. Incluye **una sección de casos límite** con valores extremos
   (`INT_MAX`, cadenas vacías, `NULL`, `0`) cuando el dominio lo permita.
4. Cada ejemplo lleva una frase de justificación, no sólo el código.
5. No repite textualmente el enunciado de la regla en la justificación.

(6-ejemplo-completo-de-referencia)=
## 6. Ejemplo completo de referencia

Las fichas {ref}`0x6001h` y {ref}`0x2014h` de este mismo directorio son las
fichas de referencia canónica. Toda ficha nueva o reescrita debe parecerse a
ellas en estructura y profundidad.
