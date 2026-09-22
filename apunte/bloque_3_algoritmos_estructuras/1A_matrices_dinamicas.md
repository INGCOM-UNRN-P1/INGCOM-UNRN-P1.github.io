---
title: 'Matrices dinámicas para algoritmos'
short_title: 'Matrices dinámicas'
subtitle: 'Representación, ownership y algoritmos sobre matrices'
---

(capitulo-matrices-dinamicas-b3)=
> **Prerrequisitos**: `apunte/bloque_2_memoria/6_aritmetica.md` y
> `1_matrices.md`.
>
> **Objetivo**: elegir una representación de matriz y justificar su costo de
> acceso, inicialización y destrucción.

# Matrices dinámicas para algoritmos

Este apunte concentra lo que el Bloque 2 debe dejar preparado: la matriz
contigua, la matriz de punteros y el puntero a array. Aquí se estudian sus
consecuencias algorítmicas: recorridos row-major, localidad, multiplicación,
validación de dimensiones y matrices tridimensionales.

## Regla de ownership

Cada constructor debe documentar quién libera la matriz. Un bloque contiguo se
libera con un `free`; una matriz de punteros requiere liberar primero cada fila y
después el vector de filas. Si una reserva intermedia falla, el constructor debe
destruir todo lo adquirido hasta ese momento.

## Relación con el Bloque 2

El capítulo 6 del Bloque 2 explica la aritmética de `matriz[i * columnas + j]` y
la liberación. Este capítulo no repite esa API: la usa para analizar algoritmos,
costos y localidad. Las matrices 3D también pertenecen aquí porque su interés
principal es el layout y el recorrido algorítmico, no la sintaxis de `malloc`.
