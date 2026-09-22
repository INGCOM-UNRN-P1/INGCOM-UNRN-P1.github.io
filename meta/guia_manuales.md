---
title: 'Guía editorial para manuales'
short_title: 'Editorialización de manuales'
subtitle: 'Procedimientos reproducibles para herramientas y diagnóstico'
---

# Guía editorial para manuales

Un manual responde cómo realizar una tarea concreta. Debe privilegiar la
reproducción, el diagnóstico y la recuperación frente a la explicación
histórica.

## Plantilla de procedimiento

1. propósito y alcance;
2. entorno probado (sistema, versión, compilador o herramienta);
3. prerrequisitos y archivos de entrada;
4. pasos numerados, con comandos completos;
5. resultado esperado;
6. errores frecuentes y recuperación;
7. limpieza, seguridad y siguiente paso.

Cada comando debe poder copiarse sin completar variables ocultas. Si contiene
`<ruta>`, `$VARIABLE` o una credencial ficticia, explicitar cómo reemplazarlo y
no incluir secretos reales.

## Diagnóstico

Presentar síntomas observables, causa probable y verificación. Diferenciar un
error del usuario, un fallo de instalación y una limitación de plataforma. No
prometer resultados que dependan de una versión no indicada.

## Mantenimiento

Registrar fecha o versión cuando el procedimiento dependa de una herramienta.
Preferir comandos portables y declarar las excepciones para Windows, Linux,
WSL o macOS. Revisar periódicamente enlaces, salidas de ejemplo y nombres de
opciones.
