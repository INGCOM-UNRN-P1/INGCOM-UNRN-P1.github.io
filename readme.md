---
title: Bienvenida
authors:
  - name: Martín René Vilugrón
    affiliation: UNRN
exports:
  - format: pdf
    title: Programación 1
    template: plain_latex_book
    output: _build/exports/apunte.pdf
    articles:
      - file: apunte/1_catedra.md
      - file: apunte/2_gradual.md
      - file: apunte/3_funciones.md
      - file: apunte/0_estilo.md
      - file: ejercicios/cuadernillo.md
---
# Bienvenidos a Programación 1

Esta materia se encuentra en el primer año de la carrera de Ingeniería en
Computación de la [Universidad Nacional de Río Negro](https://www.unrn.edu.ar).

Este sitio recopila todo el material común de la cátedra, incluyendo prácticas,
bibliografía y memes.

## Contenido

Primero, está el [apunte](apunte/1_catedra.md), pensado más o menos para ir
siguiendo el dictado de las clases

Después, hay artículos sueltos sobre temas importantes, como por ejemplo,
[cadenas seguras](./extras/cadenas.md),
[El estado de un programa](./extras/estado.md), la guía de
[`printf`](./extras/printf.md), sobre los
[roles de las variables](extras/roles.md) y como
[implementar un lazo `do..while` con `while` y `break`](./extras/simular.md).

## ¡Se aceptan contribuciones!

Este sitio usa MyST Markdown, estamos en fase de configuración, pero el
repositorio tiene bastante material.

Se aceptan Pull Requests con secciones de material y apuntes, vean la guía
oficial de la herramienta para los elementos adicionales de sintaxis disponibles
que aunque no es estrictamente necesario puede sumar un montón.
[MystMD Quickstart](https://mystmd.org/guide/quickstart-myst-markdown)

Esta es una herramienta escrita en Python y Javascript con NodeJS y la forma mas
fácil de ejecutarla en sus computadoras es usar [uv](https://docs.astral.sh/uv/)

```sh
$> uvx --from mystmd myst start
```

Que se encargará de instalar todo lo necesario para comenzar a usar la
herramienta.

## Kudos

- [gonmolina](https://github.com/gonmolina) por la ayuda con MystMD
