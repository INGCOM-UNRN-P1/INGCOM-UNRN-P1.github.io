---
title: Guía de Markdown (GitHub Flavored)
short_title: Guía Markdown (GFM)
description: Guía completa de sintaxis Markdown para documentación técnica y académica
---

# Guía de Markdown (GitHub Flavored)

## Introducción

Markdown es un lenguaje de marcado ligero diseñado para ser **fácil de leer y escribir**, incluso en su forma sin procesar. Fue creado por John Gruber en 2004 con el objetivo de permitir que las personas escriban documentos formateados usando una sintaxis simple basada en texto plano.

### ¿Por qué Markdown?

- **Simplicidad**: La sintaxis es intuitiva y se aprende rápidamente
- **Portabilidad**: Los archivos `.md` son texto plano, funcionan en cualquier editor
- **Versionable**: Al ser texto plano, funciona perfectamente con Git y permite trackear cambios de forma muy simple
- **Conversión**: Se puede exportar a HTML, PDF, y otros formatos
- **Enfoque en el contenido**: Te permite concentrarte en escribir sin preocuparte por el formato visual
- **Ubicuidad**: La sintaxis se usa en múltiples plataformas, incluso WhatsApp soporta algunas funciones de formato con esta sintaxis

### GitHub Flavored Markdown (GFM)

Esta guía cubre específicamente **GitHub Flavored Markdown (GFM)**, una variante extendida de Markdown que:

- Agrega características útiles como tablas, listas de tareas y resaltado de sintaxis
- Es el estándar utilizado en GitHub para README, issues, pull requests y documentación
- Es compatible con MyST (Markedly Structured Text), usado en esta documentación
- Permite embeber HTML limitado para casos especiales

### Estructura del documento

Los documentos Markdown bien estructurados facilitan la lectura y la navegación. Usá encabezados para organizar jerárquicamente el contenido, lo que además genera automáticamente una tabla de contenido navegable.

## Encabezados

Los encabezados estructuran el documento y crean la **tabla de contenido** automáticamente. Usá un único `#` para el título principal del documento, y luego jerarquizá las secciones con `##`, `###`, etc.

Los encabezados se crean con el símbolo `#`. Cuantos más `#`, menor el nivel del encabezado.

```markdown
# Encabezado de nivel 1
## Encabezado de nivel 2
### Encabezado de nivel 3
#### Encabezado de nivel 4
##### Encabezado de nivel 5
###### Encabezado de nivel 6
```

**Uso recomendado:**
- `#` para el título del documento (solo uno por archivo)
- `##` para secciones principales
- `###` para subsecciones
- `####` en adelante para divisiones menores

Los encabezados también permiten navegación directa mediante anclas automáticas: `#encabezado-de-nivel-1`

## Énfasis de Texto

El énfasis sirve para **destacar conceptos importantes** o *enfatizar términos técnicos*. Usá negrita para conceptos clave y cursiva para términos extranjeros, variables o énfasis suave.

Podés enfatizar texto usando asteriscos o guiones bajos.

```markdown
*Texto en cursiva* o _también en cursiva_

**Texto en negrita** o __también en negrita__

***Texto en negrita y cursiva*** o ___también en negrita y cursiva___

~~Texto tachado~~
```

**Resultado:**

*Texto en cursiva* o _también en cursiva_

**Texto en negrita** o __también en negrita__

***Texto en negrita y cursiva*** o ___también en negrita y cursiva___

~~Texto tachado~~

## Listas

Las listas organizan información en puntos o pasos. Usá **listas no ordenadas** cuando el orden no importa (características, requisitos, opciones) y **listas ordenadas** para secuencias, pasos o rankings.

### Listas no ordenadas

Ideales para enumerar elementos sin jerarquía o prioridad específica. Usá `*`, `-` o `+` para crear listas no ordenadas.

```markdown
* Primer elemento
* Segundo elemento
* Tercer elemento
  * Sub-elemento
  * Otro sub-elemento
```

### Listas ordenadas

Perfectas para instrucciones paso a paso, algoritmos o cualquier secuencia donde el orden sea importante. Usá números seguidos de un punto.

```markdown
1. Primer elemento
2. Segundo elemento
3. Tercer elemento
   1. Sub-elemento
   2. Otro sub-elemento
```

## Enlaces

Los enlaces conectan tu documento con recursos externos o internos. Usá enlaces para referenciar documentación oficial, otros archivos del proyecto, o recursos web relevantes.

```markdown
[Texto del enlace](https://ejemplo.com)

[Enlace con título](https://ejemplo.com "Título opcional")

[Enlace a archivo local](./archivo.md)

<https://ejemplo.com>
```

**Casos de uso:**
- Enlaces a documentación oficial o referencias externas
- Navegación entre archivos del proyecto
- Enlaces a secciones específicas usando anclas: `[Ver sección](#encabezados)`

## Imágenes

Las imágenes ilustran conceptos, muestran capturas de pantalla de interfaces, diagramas o resultados esperados. El texto alternativo es crucial para accesibilidad y cuando la imagen no puede cargarse.

```markdown
![Texto alternativo](ruta/a/imagen.png)

![Texto alternativo](ruta/a/imagen.png "Título opcional")
```

**Casos de uso:**
- Capturas de pantalla de interfaces o configuraciones
- Diagramas que complementan explicaciones textuales
- Resultados esperados de ejecución de programas
- Gráficos o visualizaciones de datos

## Código

El código es fundamental en documentación técnica. Usá **código en línea** para mencionar funciones, variables o comandos dentro de un párrafo, y **bloques de código** para ejemplos completos que se puedan copiar y ejecutar.

### Código en línea

Ideal para mencionar funciones, variables, comandos o fragmentos pequeños dentro de un texto. Usá comillas invertidas simples.

```markdown
Usá la función `printf()` para imprimir.
```

**Casos de uso:**
- Nombres de funciones: `malloc()`, `free()`
- Variables: `int contador`
- Comandos: `gcc -Wall`
- Valores literales: `NULL`, `0`

### Bloques de código

Esenciales para mostrar ejemplos completos de código fuente. Especificá el lenguaje para habilitar el resaltado de sintaxis, lo que mejora significativamente la legibilidad.

````markdown
```c
#include <stdio.h>

int main() {
    printf("Hola Mundo\n");
    return 0;
}
```
````

Lenguajes comunes: `c`, `python`, `java`, `javascript`, `bash`, `sql`, `html`, `css`, etc.

**Casos de uso:**
- Ejemplos de código completos y ejecutables
- Snippets de configuración
- Comandos de terminal (usando `bash` o `sh`)
- Salida de programas (usando `text` o sin especificar)

## Citas

Las citas destacan fragmentos de texto importantes, referencias textuales de documentación oficial, o notas importantes que deben diferenciarse del texto principal.

Usá el símbolo `>` para crear citas.

```markdown
> Esta es una cita.
> Puede tener múltiples líneas.
>
> Y múltiples párrafos.
```

**Resultado:**

> Esta es una cita.
> Puede tener múltiples líneas.
>
> Y múltiples párrafos.

**Casos de uso:**
- Citar especificaciones o estándares oficiales
- Destacar advertencias o notas importantes
- Referencias textuales de documentación
- Resaltar mensajes de error o salidas importantes

## Líneas horizontales

Las líneas horizontales separan secciones temáticas diferentes dentro del documento. Usálas con moderación para indicar cambios de tema importantes, no entre cada sección.

```markdown
---

***

___
```

**Casos de uso:**
- Separar secciones conceptualmente diferentes
- Delimitar ejemplos largos del texto principal
- Separar contenido principal de apéndices o notas finales

## Tablas

Las tablas organizan información estructurada de forma comparativa. Son ideales para mostrar opciones, comparar características, listar parámetros de funciones, o presentar datos relacionados.

Las tablas se crean con barras verticales `|` y guiones `-`.

```markdown
| Encabezado 1 | Encabezado 2 | Encabezado 3 |
| ------------ | ------------ | ------------ |
| Celda 1      | Celda 2      | Celda 3      |
| Celda 4      | Celda 5      | Celda 6      |
```

### Alineación en tablas

Controlá la alineación del contenido usando `:` en la línea separadora.

```markdown
| Izquierda | Centro | Derecha |
| :-------- | :----: | ------: |
| Texto     | Texto  | Texto   |
| Más texto | Más    | Más     |
```

**Casos de uso:**
- Comparar características entre opciones
- Documentar parámetros de funciones (nombre, tipo, descripción)
- Mostrar resultados de benchmarks o mediciones
- Listar tipos de datos y sus rangos
- Comparar operadores o modificadores

**Resultado:**

| Izquierda | Centro | Derecha |
| :-------- | :----: | ------: |
| Texto     | Texto  | Texto   |
| Más texto | Más    | Más     |

## Listas de tareas

Las listas de tareas permiten trackear progreso en documentos de planificación, guías de ejercicios, o checklists de verificación. Son especialmente útiles en issues de GitHub y documentos colaborativos.

```markdown
- [x] Tarea completada
- [ ] Tarea pendiente
- [ ] Otra tarea pendiente
```

**Resultado:**

- [x] Tarea completada
- [ ] Tarea pendiente
- [ ] Otra tarea pendiente

**Casos de uso:**
- Checklists de instalación o configuración
- Seguimiento de ejercicios completados
- Lista de requisitos o criterios de aceptación
- Planificación de tareas en issues de GitHub

## Escapar caracteres especiales

Para mostrar literalmente caracteres que Markdown interpreta, usá la barra invertida `\`.

```markdown
\* No será una viñeta
\# No será un encabezado
\[No será un enlace](https://ejemplo.com)
```

## HTML en Markdown

GitHub Flavored Markdown permite HTML limitado para casos donde la sintaxis Markdown no es suficiente. Usá HTML con moderación y solo cuando sea necesario.

```markdown
<details>
<summary>Haz clic para expandir</summary>

Contenido oculto que se muestra al expandir.

</details>
```

**Resultado:**

<details>
<summary>Haz clic para expandir</summary>

Contenido oculto que se muestra al expandir.

</details>

**Casos de uso:**
- Secciones colapsables para contenido opcional o avanzado
- Soluciones de ejercicios que querés ocultar inicialmente
- Contenido complementario que no querés que interrumpa el flujo
- Detalles técnicos adicionales para lectores interesados

## Comentarios

Los comentarios son invisibles en el documento renderizado. Usálos para notas internas, recordatorios para revisiones futuras, o para desactivar temporalmente contenido sin borrarlo.

```markdown
<!-- Este es un comentario que no se verá -->
<!-- TODO: Agregar más ejemplos aquí -->
<!-- Sección desactivada temporalmente:
## Contenido en desarrollo
...
-->
```

**Casos de uso:**
- Notas para otros colaboradores
- TODOs y recordatorios de contenido pendiente
- Desactivar secciones temporalmente sin perder el contenido
- Metadatos o anotaciones que no deben publicarse

## Emojis

En GitHub Flavored Markdown, podés usar códigos de emoji.

```markdown
:smile: :heart: :thumbsup: :rocket:
```

Podés encontrar una lista de estos códigos en [rxaviers/emoji-markup](https://gist.github.com/rxaviers/7360908)

## Referencias

Para más información sobre Markdown:

- [Guía oficial de GitHub Flavored Markdown](https://github.github.com/gfm/)
- [Markdown Guide](https://www.markdownguide.org/)

## Consejos prácticos

1. **Legibilidad**: Escribí Markdown pensando en que sea legible incluso en su forma sin procesar.
2. **Consistencia**: Mantené un estilo consistente en todo el documento.
3. **Espaciado**: Dejá líneas en blanco entre bloques para mejor legibilidad.
4. **Anidación**: Usá espacios o tabs para anidar listas correctamente (4 espacios o 1 tab).
5. **Previsualización**: Siempre previsualizá el documento antes de compartirlo.
