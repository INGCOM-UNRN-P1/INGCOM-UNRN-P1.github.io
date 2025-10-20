# Ejemplos de Código para Programación 1

Este directorio contiene ejemplos de código organizados por tema, siguiendo la numeración de los apuntes.

## Organización

Cada subdirectorio corresponde a un apunte:

- `1_base/` - Introducción a la programación y conceptos básicos
- `2_gradual/` - Características de C y herramientas
- `3_funciones/` - Funciones y alcances
- `4_secuencias/` - Arreglos y cadenas
- `5_compilacion/` - Proceso de compilación
- `6_matrices/` - Matrices (arreglos bidimensionales)
- `7_punteros/` - Punteros y memoria
- `8_archivos/` - Manejo de archivos
- `9_argumentos/` - Argumentos de línea de comandos
- `10_enums/` - Enumeraciones
- `11_memoria/` - Gestión de memoria dinámica
- `12_complejidad/` - Análisis de complejidad algorítmica
- `13_tad/` - Tipos Abstractos de Datos
- `14_estructuras/` - Estructuras de datos (pilas, colas)
- `15_recursividad/` - Recursión

## Uso

Para compilar cualquier ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -pedantic archivo.c -o programa
./programa
```

Para ejemplos con múltiples archivos (como `5_compilacion/modular/`), usá el `Makefile` provisto:

```bash
cd 5_compilacion/modular
make
./programa
```

## Contribuir

Al agregar nuevos ejemplos, seguí estas pautas:

1. Usá nombres descriptivos para los archivos
2. Incluí comentarios explicativos
3. Seguí las reglas de estilo documentadas en `/apunte/0_estilo.md`
4. Asegurate de que el código compile sin warnings
