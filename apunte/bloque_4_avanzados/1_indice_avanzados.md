(capitulo-indice-avanzados)=
# Bloque 4: Ruta de aprendizaje avanzada

> **Prerrequisitos**: haber completado los bloques 1 a 3: funciones, punteros,
> memoria dinámica, archivos de texto, TAD, contratos y complejidad. Se trabaja
> con GCC 11+ en Linux/WSL2 y los flags `-Wall -Wextra -std=c11 -pedantic`.
>
> **Objetivos**: 1. Elegir una ruta de estudio del bloque según sus dependencias. 2. Verificar que se domina un prerrequisito antes de avanzar.
>
> **Comprobación de salida**: seleccioná un módulo final y enumerá los conceptos previos que necesitás para abordarlo.

Este bloque no es una colección de temas independientes: propone una ruta para
pasar de escribir programas correctos a diseñar componentes de C reutilizables,
eficientes y capaces de interactuar con el sistema operativo.

## Cómo recorrer el bloque

1. **Representación y persistencia.** Empezá por [archivos binarios](4_binarios_archivos.md)
   y [operaciones bitwise](5_binarios_bitwise.md). Necesitás dominar `FILE *`,
   `fread`/`fwrite`, arreglos y conversiones de tipos. El resultado es poder
   describir datos como bytes sin perder de vista su formato.
2. **Aplicación integrada.** Continuá con [bitmaps](6_bitmaps.md): integra
   archivos binarios, structs, padding y operaciones de bits en un formato real.
   Antes de avanzar, deberías poder abrir, validar y escribir un archivo BMP.
3. **Control del flujo complejo.** Estudiá [recursividad avanzada](7_recursividad_avanzada.md)
   si ya podés seguir un stack frame y analizar casos base. El objetivo es
   justificar terminación, costo y uso de memoria de backtracking.
4. **Diseño de componentes.** Luego abordá [C idiomático](8_idiomatico.md),
   [diseño de APIs](9_api_diseno.md) e [ingeniería de APIs](10_api_ingenieria.md).
   Requieren contratos, TAD y compilación modular; culminan en una biblioteca
   con una interfaz estable y una implementación intercambiable.
5. **Extensiones de sistemas.** [Hilos](11_hilos.md) requiere dominio de
   punteros, estado compartido y APIs; [sockets](12_sockets.md) añade archivos,
   manejo de errores y el modelo cliente-servidor. Estudialos al final: ambos
   hacen visibles errores de diseño que en programas secuenciales pueden pasar
   inadvertidos.

## Mapa de dependencias

| Módulo | Depende de | Evidencia de dominio |
| --- | --- | --- |
| Binarios y bits | memoria, structs, archivos | serializar datos sin asumir tamaños ni endianness |
| Bitmaps | binarios y bits | transformar un BMP preservando su cabecera |
| Recursividad avanzada | recursión, stack, complejidad | explicar caso base, llamada recursiva y costo |
| APIs | TAD, contratos, Makefiles | separar `.h` público de `.c` privado |
| Hilos y sockets | APIs, errores, recursos | liberar recursos en todos los caminos de ejecución |

:::{tip}
No avances por orden de numeración si te falta un prerrequisito: volvé al
capítulo enlazado, resolvé un ejemplo pequeño y retomá la ruta.
:::
