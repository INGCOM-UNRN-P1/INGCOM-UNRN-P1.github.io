---
title: Bienvenida a Programación 1
authors:
  - name: Martín René Vilugrón
    affiliation: UNRN
---

# Bienvenidos a Programación 1

Les damos la bienvenida a la cursada de Programación 1, una materia fundamental del primer año de la carrera de Ingeniería en Computación de la [Universidad Nacional de Río Negro](https://www.unrn.edu.ar).

Este sitio es el corazón digital de la cátedra: un espacio donde encontrarán el material de estudio, las guías de trabajos prácticos, la bibliografía recomendada y, por qué no, algún que otro meme para amenizar el viaje.

## El arte de pensar antes de programar

Antes de sumergirnos en el lenguaje C, es crucial entender una idea central que guiará toda la materia: **programar no es solo aprender una sintaxis, es desarrollar una forma de pensar**. El lenguaje es la herramienta, pero el verdadero desafío y la habilidad que buscamos forjar residen en la construcción de soluciones lógicas y estructuradas a problemas complejos.

Programar es dar instrucciones precisas a una computadora, una entidad que no interpreta ambigüedades. Cada paso debe estar perfectamente definido. Omitir un detalle puede hacer que todo falle. Por ello, aprenderemos a **pensar como una máquina** en términos de lógica, pero también a **estructurar el pensamiento como un ser humano inteligente**.

:::{figure} apunte/2/think.jpg
:alt: Roll Safe thinking
:align: center

_Pensar es más importante que escribir._
:::

## ¿Qué encontrarán en este sitio?

Este repositorio está organizado para acompañarlos de manera gradual en su aprendizaje. El contenido se divide en varias secciones clave:

### El Apunte de Cátedra

El [material principal de la materia](apunte/0_catedra.md) está diseñado para seguir el ritmo de las clases. Comienza con una introducción gradual al lenguaje C y avanza progresivamente hacia conceptos más complejos.

### Guías de Trabajos Prácticos

Las [prácticas](practicas/TP0-2024.md) son el campo de entrenamiento. Aquí aplicarán la teoría vista en clase para resolver problemas concretos, afianzando el conocimiento y ganando experiencia.

### Ejercicios Adicionales

En la sección de [ejercicios](ejercicios/cuadernillo.md) encontrarán problemas de todo tipo para seguir practicando y desafiando sus habilidades.

### Artículos y Guías Complementarias

Hay una sección de [temas extras](extras/binarios.md) que profundiza sobre herramientas y conceptos importantes, como el uso de [`printf`](./extras/printf.md), la gestión del [estado de un programa](./extras/estado.md) o los [roles de las variables](extras/roles.md).

## Las herramientas del oficio

Para empezar a programar, necesitarán un conjunto básico de herramientas. La buena noticia es que no hace falta nada extravagante.

- **Compilador de C:** `gcc` o `clang` son los estándares en la industria.
- **Editor de texto:** Usen el que prefieran, desde `vim` o `nano` en la terminal, hasta editores más completos como VSCode o CodeBlocks.
- **Una terminal:** Se familiarizarán con la línea de comandos, una herramienta indispensable para cualquier desarrollador.

En sistemas Debian/Ubuntu, pueden instalar todo lo necesario con un solo comando:

```bash
sudo apt install build-essential
```

Para Windows, pueden seguir la [guía de instalación del compilador](./guias/compilador.md).

:::{warning} ¡No se detengan por las herramientas!
Si encuentran problemas en esta etapa, es crucial que los resuelvan cuanto antes. No dejen que una dificultad con la configuración frene su aprendizaje. Consulten en clase o en el espacio de [Discussions del proyecto](https://github.com/orgs/INGCOM-UNRN-P1/discussions).
:::

## Sobre las reglas de estilo

A lo largo de la cursada, haremos hincapié en la importancia de escribir código claro, consistente y legible. Adherirse a un conjunto de [reglas de estilo](apunte/0_estilo.md) no es una restricción arbitraria, sino una práctica profesional fundamental que facilita la colaboración y el mantenimiento del software.

Un buen estilo eleva la calidad del código no solo en su funcionalidad, sino también en su claridad. Para más detalles, pueden consultar la regla sobre la claridad y prolijidad ({ref}`0x0000h`).

## ¡Se aceptan contribuciones!

Este sitio es un proyecto vivo y en constante mejora. Está construido con [MyST Markdown](https://mystmd.org/), una herramienta que combina la simplicidad de Markdown con la potencia de la documentación técnica.

Si encuentran errores, tienen sugerencias para mejorar una explicación o quieren añadir nuevo material, **¡sus contribuciones son bienvenidas!** Participar en el proyecto es una excelente manera de aprender y de ayudar a sus compañeros.

Para ejecutar el sitio en su computadora, la forma más sencilla es usar [uv](https://docs.astral.sh/uv/):

```sh
$> uvx --from mystmd myst start
```

Este comando se encargará de instalar todo lo necesario para previsualizar los cambios en tiempo real.

### Documentos como Código

Este sitio abraza la filosofía de "documentos como código". Todo el contenido, incluyendo el texto y los diagramas, se escribe en texto plano. Usamos [MyST Markdown](https://mystmd.org/) para el contenido, y los diagramas se generan directamente desde el código fuente usando herramientas como [Mermaid](https://mermaid.js.org/) y [Svgbob](https://svgbob.com/).

Esto significa que los diagramas de flujo, esquemas y otras visualizaciones son tan fáciles de editar y versionar como el resto del apunte. ¡Animate a proponer mejoras visuales también!

### Agradecimientos

- A [gonmolina](https://github.com/gonmolina) por la ayuda inicial con MyST Markdown.