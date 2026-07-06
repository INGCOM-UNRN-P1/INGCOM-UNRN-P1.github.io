---
title: Bienvenida a Programación 1
authors:
  - name: Martín René Vilugrón
    linkedin: https://www.linkedin.com/in/martinvilu/
    github: martinvilu
    youtube: https://www.youtube.com/@programacion-i-ingcom
    email: mrvilugron@unrn.edu.ar
    affiliation: Universidad Nacional de Rio Negro - Sede Andina
affiliations:
  - name: Universidad Nacional de Rio Negro
    ror: 048zgak80

---

# Bienvenidos a Programación 1

Les damos la bienvenida a la cursada de Programación 1, una materia fundamental del primer año de la carrera de Ingeniería en Computación de la [Universidad Nacional de Río Negro](https://www.unrn.edu.ar).

Este es un espacio donde encontrarán el material de estudio, las guías de trabajos prácticos, la bibliografía recomendada y, por qué no, algún que otro meme para amenizar el viaje.

## El arte de pensar antes de programar

Antes de sumergirnos en el lenguaje C, es crucial entender una idea central que guiará toda la materia: **programar no es solo aprender una sintaxis, es desarrollar una forma de pensar**. El lenguaje es la herramienta, pero el verdadero desafío y la habilidad que buscamos forjar residen en la construcción de soluciones lógicas y estructuradas a problemas complejos.

Programar es dar instrucciones precisas a una computadora, una entidad que no interpreta ambigüedades. Cada paso debe estar perfectamente definido. Omitir un detalle puede hacer que todo falle. Por ello, aprenderemos a **pensar como una máquina** en términos de lógica, pero también a **estructurar el pensamiento como un ser humano inteligente**.

:::{figure} apunte/bloque_1_fundamentos/2/think.jpg
:alt: Roll Safe thinking
:align: center

_Pensar es más importante que escribir._
:::

## ¿Qué van a encontrar acá?

Este apunte está organizado para acompañarlos de manera gradual en su aprendizaje. El contenido se divide en varias secciones clave:

### El Apunte de Cátedra

El [material principal de la materia](apunte/indice.md) está estructurado en cinco bloques progresivos:
- **[Bloque 1: Fundamentos](apunte/bloque_1_fundamentos/1_base.md)**: Bases de la computación, control de flujo, funciones, recursividad introductoria y nociones de contratos.
- **[Bloque 2: Estructuración y Proyectos](apunte/bloque_2_proyectos/1_compilacion.md)**: Compilación, Makefiles, alias de tipos y enumeraciones.
- **[Bloque 3: Disposición de Memoria y Estructuras Estáticas](apunte/bloque_3_memoria_estatica/1_modelo_memoria.md)**: Modelo de memoria (Stack y Code), secuencias, matrices, punteros y estructuras de datos estáticas.
- **[Bloque 4: Gestión Dinámica de Recursos e Interfaces](apunte/bloque_4_dinamica_interfaces/1_memoria_dinamica.md)**: Memoria dinámica (Heap), aritmética de punteros, archivos de texto, punteros a funciones, tipos opacos, TADs (listas, pilas y colas), testing y contratos formales.
- **[Bloque 5: Temas Avanzados](apunte/bloque_5_avanzados/1_indice_avanzados.md)**: Archivos binarios, operaciones bitwise, manipulación de imágenes BMP, recursividad avanzada, C idiomático y diseño de APIs.

### Ejercicios para hacer

Las [prácticas y cuadernillos de autoevaluación](ejercicios/readme.md) están organizados para seguir de cerca cada bloque del apunte. Es el campo de entrenamiento fundamental para fijar conceptos y resolver problemas mediante código real.

### Artículos y Guías Complementarias

La cátedra hace uso extensivo de control de versiones con [Git](guias/git.md) y [GitHub](guias/github.md), por lo que es de lectura recomendada.

Disponemos de un [Índice de Guías](guias/indice.md) complementarias que cubren herramientas del ecosistema de desarrollo. Si estás comenzando, debés seguir la guía para configurar tu [Entorno de Desarrollo](guias/entorno.md) paso a paso.




:::{warning} ¡No se detengan por las herramientas!
Si encuentran problemas en esta etapa, es crucial que los resuelvan cuanto antes. No dejen que una dificultad con la configuración frene su aprendizaje. Consulten en clase o en el espacio de [Discussions del proyecto](https://github.com/orgs/INGCOM-UNRN-P1/discussions).
:::

## Sobre las reglas de estilo

A lo largo de la cursada, haremos hincapié en la importancia de escribir código claro, consistente y legible. Adherirse a un conjunto de [reglas de estilo](reglas/indice.md) no es una restricción arbitraria, sino una práctica profesional fundamental que facilita la colaboración y el mantenimiento del software.

Un buen estilo eleva la calidad del código no solo en su funcionalidad, sino también en su claridad. Para más detalles, pueden consultar la regla sobre la claridad y prolijidad ({ref}`0x0000h`).

## Ejercicios Complejos y Proyectos Multiarquivo

Para los ejercicios de mayor complejidad que requieran modularización avanzada, estructuración en múltiples archivos o para la entrega de Trabajos Prácticos (TPs), la cátedra provee un repositorio base que debés clonar y utilizar:
- **Plantilla de Proyecto**: [INGCOM-UNRN-P1/plantilla-TP](https://github.com/INGCOM-UNRN-P1/plantilla-TP)

Este repositorio plantilla incluye un **Makefile** preconfigurado para automatizar las tareas del ciclo de vida del software:
- `make`: Compila el programa principal (`main.c` y `prueba.c`).
- `make run`: Ejecuta el programa del archivo principal (`main`).
- `make test`: Ejecuta el suite de pruebas unitarias (`prueba`).
- `make clean`: Limpia los archivos binarios compilados e intermedios (`.o`, `.a`, `.exe`).
- `make librerias`: Compila todas las librerías compartidas del proyecto.
- `make ejercicio1`: Compila el ejercicio 1 (pudiendo compilar los demás modificando el número final).

> [!IMPORTANT]
> - Luego de cargar las librerías en tu espacio de trabajo, no olvides compilarlas con `make librerias` antes de darles uso en tus ejercicios.
> - Recordá no enviar nunca archivos compilados o intermedios al control de versiones de Git. Ejecutá `make clean` en la raíz del proyecto antes de hacer un commit o push.

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