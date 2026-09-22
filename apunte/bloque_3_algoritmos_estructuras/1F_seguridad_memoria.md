---
title: 'Seguridad de memoria en C'
short_title: 'Seguridad de memoria'
---

> **Prerrequisitos**: `5_memoria_dinamica.md` y sanitizers.

# Seguridad de memoria

Ampliación opcional sobre buffer overflow, use-after-free, double free y
validación de límites. Los ejemplos de vulnerabilidad deben ser mínimos,
compilables y ejecutarse únicamente en un entorno controlado.

## Regla de análisis

Separá siempre el bug de su posible explotación. Un acceso fuera de límites ya
es comportamiento indefinido aunque no produzca un ataque observable.

Herramientas recomendadas:

```bash
gcc -std=c11 -Wall -Wextra -g -fsanitize=address,undefined programa.c
valgrind --leak-check=full ./programa
```

## Disciplina de revisión

Para cada buffer escribí capacidad, cantidad válida y propietario. Validá
`cantidad <= capacidad` antes de indexar y comprobá el producto antes de una
reserva. Conservá el valor original de `realloc` hasta conocer el resultado.
Un sanitizer ayuda a localizar el primer acceso inválido, pero no demuestra la
ausencia de errores: completá la revisión con pruebas de límites, entradas
vacías, tamaños máximos y rutas de error.

:::{dropdown} Mini-ejercicio

Explicá por qué `strncpy(dest, src, n)` no es una solución general: puede no
terminar la cadena y puede ocultar truncamientos. Una interfaz que recibe la
capacidad y usa `snprintf` debe informar si el resultado fue truncado.

:::
