---
title: "Marco Canónico de Editorialización de Ejercicios"
short_title: "Marco Editorial"
subtitle: "Estándar de calidad, plantilla unificada, progresión curricular y criterios de verificación para el banco de ejercicios de Programación 1"
---

(marco-editorial-ejercicios)=
# Marco Canónico de Editorialización de Ejercicios

Este documento establece el estándar normativo para la redacción, estructuración, progresión didáctica y verificación de ejercicios en la cátedra de Programación 1. Su cumplimiento es obligatorio para todo ejercicio nuevo o refactorizado.

---

## 1. Principios de Diseño Pedagógico

1. **Autonomía y Claridad:** La consigna debe ser autosuficiente. El estudiante no debe inferir precondiciones, tipos de datos, propiedad de memoria ni convenciones de índices.
2. **Contratos Formales:** Toda función solicitada debe contar con su prototipo C11 exacto, especificando precondiciones, postcondiciones y comportamiento ante entradas inválidas o punteros nulos.
3. **Verificabilidad Inmediata:** Todo ejercicio debe incluir una suite mínima de vectores de prueba reproducibles (casos normales, casos límite y errores controlados).
4. **Scaffolding Progresivo y Acumulativo:** Las dificultades se introducen de manera gradual. Un ejercicio no puede exigir conceptos no introducidos formalmente en el capítulo actual o en los anteriores del apunte teórico (`apunte/`).
5. **Plus Ultra Pertinente:** Las extensiones *plus ultra* deben surgir de la naturaleza específica del problema (casos de borde reales, optimización de recursos, generalización), prohibiéndose terminantemente el pegado de plantillas genéricas o descontextualizadas.

---

## 2. Progresión Curricular y Prohibición de Filtración Conceptual (*Zero Leakage*)

La estructura y numeración del banco de ejercicios replica de forma biunívoca los capítulos del apunte teórico (`apunte/`). **Ningún ejercicio puede utilizar ni exigir herramientas sintácticas o modelos conceptuales que pertenezcan a capítulos posteriores.**

### Matriz de Techos Conceptuales por Bloque y Capítulo

```
+-----------------------------------------------------------------------------------+
| BLOQUE 1: FUNDAMENTOS (Capítulos 1 a 8)                                           |
| Conceptos permitidos: Variables escalares, operadores aritméticos/lógicos,        |
| condicionales (if, switch), lazos (while, for, do-while), modularización básica   |
| con funciones por valor, entrada/salida elemental por consola (printf, scanf).    |
|                                                                                   |
| ⛔ TECHO CONCEPTUAL: PROHIBIDO punteros (*, &), arreglos ([]), cadenas dinámicas, |
|    malloc/free, struct, typedef struct, enum, union, archivos y TDA opaco.        |
+-----------------------------------------------------------------------------------+
                                         │
                                         ▼
+-----------------------------------------------------------------------------------+
| BLOQUE 2: MEMORIA (Capítulos 1 a 11)                                              |
|                                                                                   |
| • Cap. 2 (Punteros básicos): Operadores & y *, pasaje por referencia escalar      |
|   (int*, float*, char*).                                                          |
|   ⛔ PROHIBIDO: struct, malloc/free, TDA opaco, deep copy.                        |
|                                                                                   |
| • Cap. 3 (Secuencias / Arreglos y Cadenas): Arreglos unidimensionales estáticos,  |
|   indexación, cadenas terminadas en '\0', funciones básicas de <string.h>.        |
|   ⛔ PROHIBIDO: matrices 2D dinámicas, struct, malloc/free, listas.               |
|                                                                                   |
| • Cap. 4 (Archivos de Texto): FILE*, fopen, fclose, fgets, fputs, fprintf, fscanf.|
|   ⛔ PROHIBIDO: archivos binarios (fread/fwrite), serialización de structs.       |
|                                                                                   |
| • Cap. 5 (Memoria Dinámica): malloc, calloc, realloc, free sobre arreglos 1D      |
|   y tipos escalares primitivos.                                                   |
|   ⛔ PROHIBIDO: structs dinámicos, nodos autoreferenciados, TDA opaco.            |
|                                                                                   |
| • Cap. 6 (Aritmética de Punteros): Offsets, incrementos, resta (ptrdiff_t).       |
|                                                                                   |
| • Cap. 7 (Estructuras): AQUÍ Y SOLO A PARTIR DE ESTE CAPÍTULO se introducen       |
|   los structs (declaración, campos, operadores . y ->, copia plana).              |
|                                                                                   |
| • Caps. 8 a 11 (Números, Casts, Alias, Enums): Complemento a 2, conversiones,     |
|   typedef y enums exhaustivos.                                                    |
+-----------------------------------------------------------------------------------+
                                         │
                                         ▼
+-----------------------------------------------------------------------------------+
| BLOQUE 3: ALGORITMOS Y ESTRUCTURAS (Capítulos 1 a 7)                              |
|                                                                                   |
| • Cap. 1 (Matrices): Matrices 2D estáticas y dinámicas (bloque vs array de ptrs). |
|                                                                                   |
| • Cap. 2 (TAD): Puntero opaco, struct incompleto en .h, implementación en .c,    |
|   encapsulamiento estricto e invariantes.                                         |
|                                                                                   |
| • Cap. 3 (Pilas, Colas y Listas): Nodos dinámicos enlazados, estructuras          |
|   autoreferenciadas.                                                              |
|   ⛔ PROHIBIDO: Aritmética de punteros sobre nodos de listas enlazadas.          |
|                                                                                   |
| • Cap. 6 (Complejidad): Notación Big-O, Omega, Theta.                             |
|   ⛔ PROHIBIDO: Exigir código o Doxygen en análisis asintótico puramente formal.  |
|                                                                                   |
| • Cap. 7 (Recursividad): Casos base explícitos, árboles de llamadas.             |
|   ⛔ PROHIBIDO: Exigir encapsulamiento en archivos .c o deep copy en algoritmos    |
|      escalares simples (factorial, suma, fibonacci).                              |
+-----------------------------------------------------------------------------------+
                                         │
                                         ▼
+-----------------------------------------------------------------------------------+
| BLOQUE 4: TEMAS AVANZADOS                                                         |
| Punteros a funciones (callbacks, qsort), estructuras opacas multicapa,            |
| archivos binarios (fread/fwrite), operaciones bitwise (&, |, ^, ~, <<, >>),       |
| bitmaps, backtracking, diseño e ingeniería de APIs en C.                          |
+-----------------------------------------------------------------------------------+
```

---

## 3. Esquema de Numeración y Anclaje Canónico

Para erradicar la disparidad de numeración y el desplazamiento de anclas, cada ejercicio adopta una codificación jerárquica estricta:

### Formato de Ancla y Título
```markdown
(ej_b<B>_c<CC>_<NN>)=
### Ejercicio <B>.<CC>.<NN> - <Título Descriptivo> ⭐⭐⭐☆☆
```

Donde:
- `<B>`: Número del Bloque didáctico (`1` a `4`).
- `<CC>`: Número de dos dígitos del capítulo correspondiente en el apunte (`01` a `12`).
- `<NN>`: Número correlativo del ejercicio dentro de ese capítulo (`01` a `99`).

*Ejemplo:*
- `(ej_b2_c02_01)=`: Ejercicio 2.02.01 – Puntero para duplicar entero por referencia (Bloque 2, Capítulo 2: Punteros, Ejercicio 1).
- `(ej_b2_c07_01)=`: Ejercicio 2.07.01 – Definición e inicialización de estructura punto 2D (Bloque 2, Capítulo 7: Estructuras, Ejercicio 1).

---

## 4. Taxonomía de Dificultad (Bloom)

| Nivel | Etiqueta | Taxonomía de Bloom | Descripción y Alcance | Tiempo Est. |
| :---: | :--- | :--- | :--- | :---: |
| ⭐☆☆☆☆ | **Básico** | Recordar / Comprender | Sintaxis elemental, operaciones secuenciales, expresiones aritméticas, E/S básica. | 10–15 min |
| ⭐⭐☆☆☆ | **Fácil** | Comprender / Aplicar | Condicionales, lazos definidos (`for`, `while`), modularización con funciones puras por valor. | 15–25 min |
| ⭐⭐⭐☆☆ | **Intermedio** | Aplicar / Analizar | Punteros, pasaje por referencia, mutación in-place, arreglos unidimensionales, cadenas de caracteres (`\0`). | 25–40 min |
| ⭐⭐⭐⭐☆ | **Avanzado** | Analizar / Evaluar | Asignación dinámica de memoria (`malloc`/`free`), structs, matrices dinámicas, lectura/escritura de archivos binarios. | 45–60 min |
| ⭐⭐⭐⭐⭐ | **Experto** | Evaluar / Crear | TADs opacos con invariantes estrictos, estructuras autoreferenciadas (listas, árboles), recursividad profunda, análisis de complejidad asintótica. | 60–90 min |

---

## 5. Plantilla Canónica de Ejercicio (MyST)

Todo ejercicio debe respetar la siguiente estructura MyST. El ancla debe preceder inmediatamente al encabezado `###`:

````markdown
(ej_b<B>_c<CC>_<NN>)=
### Ejercicio <B>.<CC>.<NN> - <Título del Ejercicio> ⭐⭐⭐☆☆

<Descripción breve del problema y su relevancia técnica o conceptual dentro del capítulo del apunte.>

::::{exercise} <Título del Ejercicio>
:label: ej-b<B>-c<CC>-<NN>

**Consigna:**
<Enunciado descriptivo, formal e inequívoco. Detallar qué debe resolver el código sin conceptos de capítulos posteriores.>

#### Contrato de la Función

```{code-block} c
/**
 * @brief <Descripción de la operación>.
 * 
 * @param[in]     param_in  Descripción del parámetro de entrada.
 * @param[out]    param_out Puntero al resultado de salida. No debe ser NULL.
 * @return int              0 si la operación fue exitosa, código de error negativo en fallo.
 * 
 * @pre  param_in cumple con ...
 * @post param_out almacena ...
 * @ownership La memoria apuntada por param_out pertenece al llamador.
 */
int nombre_funcion(int param_in, int *param_out);
```

#### Vectores de Prueba Obligatorios

| Caso | Entrada (`param_in`) | Estado `param_out` | Retorno | Comportamiento Evaluado |
| :--- | :--- | :--- | :---: | :--- |
| **Normal 1** | `10` | `20` | `0` | Operación estándar dentro de rango. |
| **Normal 2** | `0` | `0` | `0` | Elemento neutro / cero. |
| **Borde** | `INT_MAX` | Inalterado | `-1` | Detección de desbordamiento aritmético. |
| **Error** | Puntero `NULL` | Inalterado | `-2` | Validación defensiva de puntero nulo. |

:::{hint} Casos Límite y Consideraciones
- Indicar expresamente cómo responder ante punteros `NULL`, tamaños en cero o valores fuera de rango.
- Especificar si la función reserva memoria en el Heap o si opera sobre memoria provista por el llamador.
:::

:::{admonition} Plus Ultra
:class: tip
- **[Variación contextual 1]:** <Consigna avanzada estrictamente pertinente al ejercicio>.
- **[Variación contextual 2]:** <Optimización o manejo de borde específico del problema>.
:::

::::

::::{solution} ej-b<B>-c<CC>-<NN>
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// Implementación de referencia conforme a las reglas de estilo de la cátedra
int nombre_funcion(int param_in, int *param_out)
{
    if (param_out == NULL) {
        return -2;
    }
    // Lógica ...
    *param_out = param_in * 2;
    return 0;
}

// Suite de pruebas unitarias mínimas
int main(void)
{
    int res = 0;
    
    // Test caso normal
    assert(nombre_funcion(10, &res) == 0);
    assert(res == 20);
    
    // Test puntero NULL
    assert(nombre_funcion(10, NULL) == -2);
    
    printf("Todos los tests pasaron correctamente.\n");
    return 0;
}
```

**Justificación técnica:**
<Explicación de invariantes, decisiones de diseño, complejidad temporal/espacial y prevención de comportamiento indefinido según C11>.

::::
````

---

## 6. Reglas Obligatorias de Redacción y Código

1. **Ubicación Inmediata de Anclas:**
   - La etiqueta `(ej_b<B>_c<CC>_<NN>)=` **debe colocarse inmediatamente antes** del encabezado `### Ejercicio`.
   - Se prohíbe interponer bloques `{hint}`, `{tip}` o llamadas intermedias entre el ancla y su encabezado.
2. **Prototipos y Tipos Conformes a C11:**
   - Para longitudes, índices y tamaños de buffers: usar `size_t`.
   - Para valores de verdad: usar `bool` (requiere `#include <stdbool.h>`).
   - Para firmas principales: `int main(void)`, jamás `int main()` vacío (regla de cátedra `0x2001h`).
   - Siempre declarar parámetros constantes como `const` (ej. `const char *`, `const int *`).
3. **Manejo de Errores e Invariantes:**
   - Nunca utilizar `exit()` o `abort()` dentro de funciones de biblioteca o auxiliares (regla `0x2002h`).
   - La comunicación de errores se realiza mediante valor de retorno o puntero de estado.
4. **Prohibición de Texto Truncado:**
   - Ninguna viñeta puede finalizar sin punto o con conjunciones o preposiciones colgantes (`el`, `de`, `hasta`, `pero`, etc.).
   - Toda lista de requerimientos debe cerrar gramaticalmente sus proposiciones.
5. **Cero Boilerplate en Plus Ultra:**
   - Queda vetado el uso repetitivo de frases plantilla como "Añadir función de duplicación profunda" o "Optimizar acceso por orden de filas" cuando el problema no trate estructuras dinámicas o matrices 2D.
6. **Validación de Fuga de Conceptos con Jev:**
   - Antes de dar por aprobado un archivo de ejercicios, se ejecuta la verificación de System One con Jev para asegurar que $P_{leak} < 0.05$.

---

## 7. Checklist de Verificación de Calidad Editorial (QA Gate)

Antes de fusionar o publicar cualquier ejercicio en el repositorio:

- [ ] **Alineación con Apunte:** El ejercicio solo utiliza conceptos del capítulo correspondiente o previos.
- [ ] **Anclaje:** El ancla MyST precede directamente a la cabecera `### Ejercicio`.
- [ ] **Gramática:** Cero oraciones o viñetas truncadas.
- [ ] **Firma C11:** Prototipo completo con tipos exactos de la biblioteca estándar.
- [ ] **Contrato:** Precondiciones, postcondiciones y propiedad de memoria explicitadas.
- [ ] **Test Vectors:** Tabla con al menos 3 casos de prueba (normal, borde, error).
- [ ] **Solución Conforme:** El código compila limpiamente con:
  ```bash
  gcc -Wall -Wextra -Werror -pedantic -std=c11 -fsanitize=address,undefined ejercicio.c -o ejercicio
  ```
- [ ] **Valgrind:** En ejercicios de memoria dinámica, la ejecución no produce fugas ni accesos inválidos (`valgrind --leak-check=full`).
- [ ] **Plus Ultra Contextual:** Consignas de extensión directamente vinculadas al dominio del ejercicio.
