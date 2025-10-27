---
title: "Ejercicios: Análisis de Código"
short_title: "17. Análisis de Código"
---

## Acerca de

A diferencia de otros ejercicios, el objetivo aquí no es escribir código, sino
**analizarlo**. La capacidad de leer, entender y razonar sobre un código
existente es una habilidad tan importante como la de escribirlo. Estos
ejercicios están diseñados para aplicar los conceptos teóricos de los apuntes
sobre [](../extras/notes-roles.md) y [](../extras/notes-estado.md).

:::{note} Habilidades a desarrollar
- **Comprensión de código**: Leer y entender código escrito por otros
- **Identificación de patrones**: Reconocer roles y propósitos de variables
- **Análisis de flujo de control**: Seguir la ejecución paso a paso
- **Debugging mental**: Identificar posibles problemas sin ejecutar el código
:::

## 1: Identificación de Roles de Variables

### 1.1: Análisis de una Función

:::{exercise} rol_promedio
:label: rol_promedio

Dado el siguiente código, identificá el "rol" principal de cada una de las
variables listadas.

```c
#include <stdbool.h>

// Encuentra el promedio de los números positivos en un arreglo.
double promedio_positivos(const int arreglo[], size_t n, bool *exito) {
    double suma = 0.0;       // Variable 1
    int contador = 0;        // Variable 2
    *exito = false;          // Variable 3 (a través del puntero)

    for (size_t i = 0; i < n; i++) { // Variable 4
        if (arreglo[i] > 0) {
            suma = suma + arreglo[i];
            contador++;
        }
    }

    if (contador > 0) {
        *exito = true;
        return suma / contador; // Variable 5 (implícita)
    }

    return 0.0;
}
```

**Tarea**: Para cada una de las siguientes variables, describí su rol principal:

1.  `suma`
2.  `contador`
3.  `exito` (el valor al que apunta)
4.  `i`
5.  El valor de retorno de la función.

:::

:::{solution} rol_promedio 
:class: dropdown

1.  **`suma`**: **Acumulador**. Su propósito es acumular la suma de los valores
    positivos encontrados.
2.  **`contador`**: **Contador**. Su rol es contar cuántos números positivos se
    han encontrado.
3.  **`exito`**: **Bandera (Flag)**. Se utiliza para señalizar al código que
    llama a la función si la operación fue exitosa (es decir, si se encontró al
    menos un número positivo).
4.  **`i`**: **Variable de Control de Bucle (Iterador)**. Su único propósito es
    controlar las iteraciones del bucle `for`.
5.  **Valor de retorno**: **Variable de Salida**. Contiene el resultado
    principal del cálculo de la función. 
    
:::

### 1.2: Análisis de Función de Búsqueda

:::{exercise} rol_busqueda
:label: rol_busqueda

Analizá el siguiente código que busca el elemento máximo en un arreglo:

```c
#include <stdbool.h>
#include <limits.h>

int encontrar_maximo(const int arr[], size_t tam, bool *encontrado) {
    int maximo = INT_MIN;     // Variable A
    bool hay_elementos = false; // Variable B
    *encontrado = false;      // Variable C
    
    for (size_t indice = 0; indice < tam; indice++) { // Variable D
        if (!hay_elementos || arr[indice] > maximo) {
            maximo = arr[indice];
            hay_elementos = true;
        }
    }
    
    *encontrado = hay_elementos;
    return maximo;
}
```

**Tarea**: Identificá el rol de cada variable:

1. `maximo`
2. `hay_elementos`
3. `encontrado` (valor apuntado)
4. `indice`
:::


:::{solution} rol_busqueda
:class: dropdown

1. **`maximo`**: **Variable de Mejor Candidato/Guardián**. Mantiene el valor máximo encontrado hasta el momento.
2. **`hay_elementos`**: **Bandera de Inicialización**. Indica si ya se procesó al menos un elemento para inicializar correctamente la comparación.
3. **`encontrado`**: **Parámetro de Salida/Bandera de Estado**. Comunica al llamador si la operación fue exitosa.
4. **`indice`**: **Variable de Control de Bucle/Iterador**. Controla el recorrido del arreglo.

:::

### 1.3: Análisis de Función con Múltiples Roles

:::{exercise} roles_multiples
:label: roles_multiples

Examiná esta función más compleja que procesa datos de ventas:

```c
#include <stdio.h>

typedef struct {
    double total_ventas;
    int dias_con_ventas;
    double promedio_diario;
    bool hay_ventas;
} reporte_ventas_t;

reporte_ventas_t procesar_ventas(const double ventas[], int dias) {
    reporte_ventas_t resultado = {0.0, 0, 0.0, false}; // Variable A
    double acumulado = 0.0;        // Variable B
    int dias_activos = 0;          // Variable C
    bool primera_venta = true;     // Variable D
    double venta_maxima = 0.0;     // Variable E
    
    for (int dia = 0; dia < dias; dia++) { // Variable F
        if (ventas[dia] > 0) {
            acumulado += ventas[dia];
            dias_activos++;
            
            if (primera_venta || ventas[dia] > venta_maxima) {
                venta_maxima = ventas[dia];
                primera_venta = false;
            }
        }
    }
    
    if (dias_activos > 0) {
        resultado.total_ventas = acumulado;
        resultado.dias_con_ventas = dias_activos;
        resultado.promedio_diario = acumulado / dias_activos;
        resultado.hay_ventas = true;
    }
    
    printf("Venta máxima registrada: %.2f\n", venta_maxima);
    return resultado;
}
```

**Tarea**: Identificá el rol principal de cada variable marcada:

1. `resultado`
2. `acumulado`
3. `dias_activos`
4. `primera_venta`
5. `venta_maxima`
6. `dia`
:::

:::{solution} roles_multiples
:class: dropdown

1. **`resultado`**: **Variable de Salida Estructurada**. Encapsula múltiples valores de retorno en una estructura.
2. **`acumulado`**: **Acumulador**. Suma todas las ventas válidas encontradas.
3. **`dias_activos`**: **Contador**. Cuenta los días que tuvieron ventas positivas.
4. **`primera_venta`**: **Bandera de Primera Vez**. Controla la inicialización correcta del máximo.
5. **`venta_maxima`**: **Variable de Mejor Candidato/Guardián**. Mantiene el valor de venta más alto encontrado.
6. **`dia`**: **Variable de Control de Bucle/Iterador**. Controla la iteración a través de los días.

:::

## 2: Descripción del Estado de un Programa

### 2.1: Fotografía de la Memoria

:::{exercise} estado_1
:label: estado_1

Dado el siguiente programa, describí el estado completo de la memoria (Pila y
Montículo) en el momento exacto en que la ejecución llega a la línea marcada
como `// PUNTO DE ANÁLISIS`. No es necesario indicar direcciones de memoria
exactas, pero sí la relación entre ellas.

```c
#include <stdlib.h>

char* crear_copia(const char* original) {
    int largo = 0;
    while (original[largo] != '\0') {
        largo++;
    }

    char* copia = malloc(largo + 1);

    // PUNTO DE ANÁLISIS

    for (int i = 0; i <= largo; i++) {
        copia[i] = original[i];
    }
    return copia;
}

int main() {
    char* saludo_original = "Hola";
    char* saludo_copiado = NULL;

    saludo_copiado = crear_copia(saludo_original);

    free(saludo_copiado);
    return 0;
}
```

**Tarea**: Completá la siguiente plantilla describiendo los valores de las
variables en cada marco de la pila y el estado del montículo.

- **Pila (Stack)**:
  - **Marco de `main`**:
    - `saludo_original` (puntero): ?
    - `saludo_copiado` (puntero): ?
  - **Marco de `crear_copia`**:
    - `original` (puntero): ?
    - `largo` (entero): ?
    - `copia` (puntero): ?
    - `i` (entero): ?
- **Montículo (Heap)**:
  - ?
- **Segmento de Datos (Solo Lectura)**:
  - ?

:::

:::{solution} estado_1 
:class: dropdown

- **Pila (Stack)**:
  - **Marco de `main`**:
    - `saludo_original` (puntero): Contiene la dirección de memoria de la cadena
      literal "Hola".
    - `saludo_copiado` (puntero): Su valor es `NULL` en este punto, ya que la
      asignación se produce después de que `crear_copia` retorne.
  - **Marco de `crear_copia`**:
    - `original` (puntero): Contiene una copia de la dirección de
      `saludo_original`, por lo que también apunta a la cadena literal "Hola".
    - `largo` (entero): Su valor es `4` (calculado por el bucle `while`).
    - `copia` (puntero): Contiene la dirección de memoria del nuevo bloque de 5
      bytes reservado por `malloc` en el montículo.
    - `i` (entero): Aún no ha sido inicializada, por lo que su valor es
      indeterminado (basura).
- **Montículo (Heap)**:
  - Hay un bloque de **5 bytes** reservado. Su contenido es indeterminado
    (basura), ya que el bucle `for` que lo llena aún no se ha ejecutado.
- **Segmento de Datos (Solo Lectura)**:
  - Contiene la cadena literal `"Hola"` (terminada en nulo), que ocupa 5 bytes.
    La dirección de su primer carácter es a la que apuntan `saludo_original` y
    `original`.

:::

### 2.2: Análisis de Memoria con Estructuras

:::{exercise} estado_struct
:label: estado_struct


Analizá el estado de memoria del siguiente programa en el punto marcado:

```c
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nombre;
    int edad;
    double salario;
} empleado_t;

empleado_t* crear_empleado(const char* nom, int edad_emp, double sal) {
    empleado_t* nuevo = malloc(sizeof(empleado_t));
    
    int len_nombre = strlen(nom);
    nuevo->nombre = malloc(len_nombre + 1);
    strcpy(nuevo->nombre, nom);
    
    nuevo->edad = edad_emp;
    nuevo->salario = sal;
    
    // PUNTO DE ANÁLISIS
    
    return nuevo;
}

int main() {
    empleado_t* emp1 = NULL;
    empleado_t* emp2 = NULL;
    
    emp1 = crear_empleado("Ana García", 28, 45000.0);
    
    return 0;
}
```

**Tarea**: Describí el estado de memoria en el punto de análisis:

:::

:::{solution} estado_struct
:class: dropdown

- **Pila (Stack)**:
  - **Marco de `main`**:
    - `emp1` (puntero): `NULL` (aún no asignado, la función no ha retornado)
    - `emp2` (puntero): `NULL`
  - **Marco de `crear_empleado`**:
    - `nom` (puntero): Apunta a la cadena literal "Ana García" en el segmento de datos
    - `edad_emp` (int): 28
    - `sal` (double): 45000.0
    - `nuevo` (puntero): Apunta al bloque de `sizeof(empleado_t)` bytes en el heap
    - `len_nombre` (int): 10 (longitud de "Ana García")

- **Montículo (Heap)**:
  - **Bloque 1**: `sizeof(empleado_t)` bytes para la estructura empleado
    - `nombre` (puntero): Apunta al segundo bloque en el heap
    - `edad` (int): 28
    - `salario` (double): 45000.0
  - **Bloque 2**: 11 bytes conteniendo "Ana García\0"

- **Segmento de Datos (Solo Lectura)**:
  - Cadena literal "Ana García" (11 bytes incluyendo '\0')

:::

### 2.3: Trazado de Ejecución con Arrays Dinámicos

:::{exercise} traza_ejecucion
:label: traza_ejecucion

Seguí la ejecución del siguiente código y describí el estado en cada punto marcado:

```c
#include <stdlib.h>

int* duplicar_array(int* original, int tam) {
    int* nuevo = malloc(tam * sizeof(int));
    
    // PUNTO A
    
    for (int i = 0; i < tam; i++) {
        nuevo[i] = original[i] * 2;
    }
    
    // PUNTO B
    
    return nuevo;
}

int main() {
    int numeros[3] = {5, 10, 15};
    int* duplicados = NULL;
    
    // PUNTO C
    
    duplicados = duplicar_array(numeros, 3);
    
    // PUNTO D
    
    free(duplicados);
    return 0;
}
```

**Tarea**: Para cada punto (A, B, C, D), describí:
1. Estado de la pila
2. Estado del montículo
3. Valores de las variables relevantes

:::

:::{solution} traza_ejecucion
:class: dropdown

**PUNTO A** (después del malloc en `duplicar_array`):
- **Pila**:
  - **Marco de `main`**: 
    - `numeros[3]`: {5, 10, 15}
    - `duplicados`: NULL
  - **Marco de `duplicar_array`**:
    - `original`: apunta a `numeros[0]` en main
    - `tam`: 3
    - `nuevo`: apunta al bloque malloc'eado en heap
    - `i`: no inicializada (basura)
- **Heap**: Bloque de 12 bytes (3 * sizeof(int)) con contenido indeterminado

**PUNTO B** (después del bucle for):
- **Pila**: Igual que punto A, excepto `i` = 3
- **Heap**: El bloque ahora contiene {10, 20, 30}

**PUNTO C** (antes de llamar a `duplicar_array`):
- **Pila**:
  - **Marco de `main`**:
    - `numeros[3]`: {5, 10, 15}
    - `duplicados`: NULL
- **Heap**: Vacío

**PUNTO D** (después de retornar de `duplicar_array`):
- **Pila**:
  - **Marco de `main`**:
    - `numeros[3]`: {5, 10, 15}
    - `duplicados`: apunta al bloque en heap
- **Heap**: Bloque de 12 bytes conteniendo {10, 20, 30}

:::

## 3: Análisis de Bugs y Problemas

### 3.1: Identificación de Errores de Lógica

:::{exercise} debugging_1
:label: debugging_1

El siguiente código intenta encontrar el segundo elemento más grande en un arreglo, pero contiene errores. Identificá los problemas sin ejecutar el código:

```c
#include <stdio.h>
#include <limits.h>

int segundo_maximo(int arr[], int tam) {
    int maximo = INT_MIN;
    int segundo = INT_MIN;
    
    for (int i = 0; i < tam; i++) {
        if (arr[i] > maximo) {
            segundo = maximo;
            maximo = arr[i];
        } else if (arr[i] > segundo) {
            segundo = arr[i];
        }
    }
    
    return segundo;
}
```

**Tarea**: 
1. ¿Qué problemas podés identificar en este código?
2. ¿En qué casos fallaría?
3. ¿Cómo lo corregirías?

:::

:::{solution} debugging_1
:class: dropdown

**Problemas identificados:**

1. **Falta validación de tamaño**: No verifica que `tam >= 2`, que es el mínimo necesario para tener un segundo máximo.

2. **Elementos duplicados**: Si el máximo se repite, el segundo máximo será igual al máximo, lo cual puede no ser el comportamiento deseado.

3. **Array con menos de 2 elementos únicos**: Si todos los elementos son iguales, no hay un verdadero "segundo máximo".

4. **No maneja el caso de array vacío**: Si `tam == 0`, el comportamiento es indefinido.

**Casos que fallan:**
- Array vacío: `[]`
- Array con un elemento: `[5]`
- Array con elementos iguales: `[3, 3, 3]`
- Array con solo dos valores únicos donde uno se repite: `[5, 3, 5, 5]`

**Corrección sugerida:**
```c
int segundo_maximo_corregido(int arr[], int tam) {
    if (tam < 2) {
        return INT_MIN; // o manejar error apropiadamente
    }
    
    int maximo = INT_MIN;
    int segundo = INT_MIN;
    
    for (int i = 0; i < tam; i++) {
        if (arr[i] > maximo) {
            segundo = maximo;
            maximo = arr[i];
        } else if (arr[i] > segundo && arr[i] != maximo) {
            segundo = arr[i];
        }
    }
    
    // Verificar si realmente hay un segundo máximo
    if (segundo == INT_MIN) {
        // Todos los elementos eran iguales
        return INT_MIN; // o manejar apropiadamente
    }
    
    return segundo;
}
```

:::

### 3.2: Análisis de Memory Leaks

:::{exercise} fugas_1
:label: fugas_1

Identificá los problemas de manejo de memoria en el siguiente código:

```c
#include <stdlib.h>
#include <string.h>

char* procesar_texto(const char* entrada) {
    int len = strlen(entrada);
    char* resultado = malloc(len * 2 + 1);
    char* temp = malloc(len + 1);
    
    strcpy(temp, entrada);
    
    // Duplicar cada carácter
    for (int i = 0; i < len; i++) {
        resultado[i * 2] = temp[i];
        resultado[i * 2 + 1] = temp[i];
    }
    resultado[len * 2] = '\0';
    
    if (len > 10) {
        char* resultado_largo = malloc(len * 3 + 1);
        // Triplicar en lugar de duplicar
        for (int i = 0; i < len; i++) {
            resultado_largo[i * 3] = temp[i];
            resultado_largo[i * 3 + 1] = temp[i];
            resultado_largo[i * 3 + 2] = temp[i];
        }
        resultado_largo[len * 3] = '\0';
        return resultado_largo;
    }
    
    return resultado;
}

int main() {
    char* texto1 = procesar_texto("Hola");
    char* texto2 = procesar_texto("Este es un texto muy largo");
    
    printf("Texto 1: %s\n", texto1);
    printf("Texto 2: %s\n", texto2);
    
    return 0;
}
```

**Tarea**: Identificá todos los memory leaks y problemas de manejo de memoria.

:::

:::{solution} fugas_1
:class: dropdown

**Problemas identificados:**

1. **Memory leak de `temp`**: La variable `temp` se aloca con `malloc()` pero nunca se libera con `free()`. Esto ocurre en ambos caminos de ejecución.

2. **Memory leak de `resultado`**: Cuando `len > 10`, se aloca `resultado` pero luego se aloca `resultado_largo` y se retorna este último, perdiendo la referencia a `resultado` sin liberarlo.

3. **Memory leaks en `main`**: Las variables `texto1` y `texto2` reciben memoria alocada dinámicamente pero nunca se libera.

4. **Uso innecesario de memoria**: El `temp` es redundante ya que se puede trabajar directamente con `entrada`.

**Código corregido:**
```c
char* procesar_texto_corregido(const char* entrada) {
    int len = strlen(entrada);
    char* resultado;
    
    if (len > 10) {
        resultado = malloc(len * 3 + 1);
        for (int i = 0; i < len; i++) {
            resultado[i * 3] = entrada[i];
            resultado[i * 3 + 1] = entrada[i];
            resultado[i * 3 + 2] = entrada[i];
        }
        resultado[len * 3] = '\0';
    } else {
        resultado = malloc(len * 2 + 1);
        for (int i = 0; i < len; i++) {
            resultado[i * 2] = entrada[i];
            resultado[i * 2 + 1] = entrada[i];
        }
        resultado[len * 2] = '\0';
    }
    
    return resultado;
}

int main() {
    char* texto1 = procesar_texto_corregido("Hola");
    char* texto2 = procesar_texto_corregido("Este es un texto muy largo");
    
    printf("Texto 1: %s\n", texto1);
    printf("Texto 2: %s\n", texto2);
    
    // Liberar memoria
    free(texto1);
    free(texto2);
    
    return 0;
}
```

:::

## 4: Análisis de Eficiencia y Optimización

### 4.1: Análisis de Complejidad Temporal

:::{exercise} eficiencia_1
:label: eficiencia_1

Analizá la complejidad temporal del siguiente algoritmo de búsqueda:

```c
#include <stdbool.h>

bool buscar_par_suma(int arr[], int tam, int objetivo) {
    // Busca si existe un par de números que sumen al objetivo
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i] + arr[j] == objetivo) {
                return true;
            }
        }
    }
    return false;
}

bool buscar_par_suma_optimizado(int arr[], int tam, int objetivo) {
    // Versión con array ordenado (asumimos que está ordenado)
    int izq = 0;
    int der = tam - 1;
    
    while (izq < der) {
        int suma_actual = arr[izq] + arr[der];
        if (suma_actual == objetivo) {
            return true;
        } else if (suma_actual < objetivo) {
            izq++;
        } else {
            der--;
        }
    }
    return false;
}
```

**Tarea**: 
1. ¿Cuál es la complejidad temporal de cada función?
2. ¿Cuáles son las variables de control y qué roles cumplen?
3. ¿En qué escenarios cada algoritmo sería más apropiado?

:::

:::{solution} eficiencia_1
:class: dropdown

**Análisis de `buscar_par_suma`:**
- **Complejidad temporal**: $O(n^2)$ - hay dos bucles anidados que recorren el array
- **Variables de control**: 
  - `i`: Iterador externo (rol: control de bucle principal)
  - `j`: Iterador interno (rol: control de bucle secundario, siempre j > i)
- **Complejidad espacial**: $O(1)$ - solo usa variables locales

**Análisis de `buscar_par_suma_optimizado`:**
- **Complejidad temporal**: $O(n)$ - cada elemento se visita máximo una vez
- **Variables de control**:
  - `izq`: Puntero izquierdo (rol: guardián del límite inferior)
  - `der`: Puntero derecho (rol: guardián del límite superior)
  - `suma_actual`: Variable temporal (rol: almacén de cálculo intermedio)
- **Complejidad espacial**: $O(1)$

**Escenarios apropiados:**
- **Primer algoritmo**: Cuando el array NO está ordenado y no podemos/queremos ordenarlo
- **Segundo algoritmo**: Cuando el array YA está ordenado o el costo de ordenarlo es amortizable

**Trade-offs:**
- Si necesitamos ordenar: $O(n log n) + O(n)$ vs $O(n^2)$
- Si ya está ordenado: $O(n)$ vs $O(n^2)$ - clara ventaja para el optimizado

:::

### 4.2: Análisis de Uso de Memoria

:::{exercise} eficiencia_2
:label: eficiencia_2

Compará el uso de memoria de estas dos implementaciones que calculan factoriales:

```c
// Versión recursiva
long factorial_recursivo(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursivo(n - 1);
}

// Versión iterativa
long factorial_iterativo(int n) {
    long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Versión con memoización
#include <stdlib.h>

static long* cache = NULL;
static int cache_size = 0;

long factorial_memoizado(int n) {
    if (n <= 1) {
        return 1;
    }
    
    // Inicializar cache si es necesario
    if (cache == NULL || n >= cache_size) {
        int nuevo_tamaño = n + 1;
        cache = realloc(cache, nuevo_tamaño * sizeof(long));
        
        // Inicializar nuevos elementos
        for (int i = cache_size; i < nuevo_tamaño; i++) {
            cache[i] = -1; // Valor que indica "no calculado"
        }
        cache_size = nuevo_tamaño;
    }
    
    // Verificar si ya está en cache
    if (cache[n] != -1) {
        return cache[n];
    }
    
    // Calcular y almacenar en cache
    cache[n] = n * factorial_memoizado(n - 1);
    return cache[n];
}
```

**Tarea**: Analizá cada implementación en términos de:
1. Uso de memoria de la pila
2. Uso de memoria del heap
3. Variables y sus roles
4. Trade-offs entre tiempo y espacio

:::

:::{solution} eficiencia_2
:class: dropdown

**Versión Recursiva:**
- **Pila**: $O(n)$ - cada llamada recursiva agrega un marco a la pila
- **Heap**: $O(1)$ - no usa memoria dinámica
- **Variables**: Solo el parámetro `n` en cada marco (rol: parámetro de entrada)
- **Riesgo**: Stack overflow para valores grandes de n

**Versión Iterativa:**
- **Pila**: $O(1)$ - un solo marco de función
- **Heap**: $O(1)$ - no usa memoria dinámica  
- **Variables**:
  - `resultado`: Acumulador para el producto
  - `i`: Variable de control de bucle
- **Ventajas**: Uso mínimo de memoria, sin riesgo de stack overflow

**Versión Memoizada:**
- **Pila**: $O(n)$ - similar a recursiva en la primera llamada, $O(1)$ en llamadas subsecuentes
- **Heap**: $O(n)$ - array para almacenar resultados calculados
- **Variables**:
  - `cache`: Array estático global (rol: almacén de resultados)
  - `cache_size`: Contador de tamaño actual (rol: guardián de límites)
- **Trade-off**: Usa más memoria pero acelera dramáticamente cálculos repetidos

**Comparación de Trade-offs:**

| Aspecto | Recursiva | Iterativa | Memoizada |
|---------|-----------|-----------|-----------|
| Tiempo (primera llamada) | $O(n)$ | $O(n)$ | $O(n)$ |
| Tiempo (llamadas repetidas) | $O(n)$ | $O(n)$ | $O(1)$ |
| Espacio en pila | $O(n)$ | $O(1)$ | $O(n)$→$O(1)$ |
| Espacio en heap | $O(1)$ | $O(1)$ | $O(n)$ |
| Legibilidad | Alta | Media | Baja |
| Riesgo de overflow | Alto | Bajo | Medio |

:::

## 5: Ejercicios de Síntesis

### 5.1: Análisis Integral de Sistema

:::{exercise} analisis_1
:label: analisis_1

Analizá el siguiente sistema completo que gestiona una lista de estudiantes:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} estudiante_t;

typedef struct {
    estudiante_t* lista;
    int cantidad;
    int capacidad;
} sistema_estudiantes_t;

sistema_estudiantes_t* inicializar_sistema(int capacidad_inicial) {
    sistema_estudiantes_t* sistema = malloc(sizeof(sistema_estudiantes_t));
    
    sistema->lista = malloc(capacidad_inicial * sizeof(estudiante_t));
    sistema->cantidad = 0;
    sistema->capacidad = capacidad_inicial;
    
    return sistema;
}

bool agregar_estudiante(sistema_estudiantes_t* sistema, 
                       const char* nombre, int edad, float promedio) {
    
    if (sistema->cantidad >= sistema->capacidad) {
        // Redimensionar
        int nueva_capacidad = sistema->capacidad * 2;
        estudiante_t* nueva_lista = realloc(sistema->lista, 
                                          nueva_capacidad * sizeof(estudiante_t));
        
        if (nueva_lista == NULL) {
            return false;
        }
        
        sistema->lista = nueva_lista;
        sistema->capacidad = nueva_capacidad;
    }
    
    // Agregar nuevo estudiante
    strcpy(sistema->lista[sistema->cantidad].nombre, nombre);
    sistema->lista[sistema->cantidad].edad = edad;
    sistema->lista[sistema->cantidad].promedio = promedio;
    sistema->cantidad++;
    
    return true;
}

estudiante_t* buscar_mejor_estudiante(sistema_estudiantes_t* sistema) {
    if (sistema->cantidad == 0) {
        return NULL;
    }
    
    estudiante_t* mejor = &sistema->lista[0];
    
    for (int i = 1; i < sistema->cantidad; i++) {
        if (sistema->lista[i].promedio > mejor->promedio) {
            mejor = &sistema->lista[i];
        }
    }
    
    return mejor;
}

void liberar_sistema(sistema_estudiantes_t* sistema) {
    if (sistema != NULL) {
        free(sistema->lista);
        free(sistema);
    }
}
```

**Tarea**: Realizá un análisis completo del sistema:

1. **Identificación de roles**: Para cada variable en cada función, identificá su rol
2. **Análisis de memoria**: Describí cómo evoluciona el uso de memoria durante la ejecución
3. **Identificación de patrones**: ¿Qué patrones de diseño reconocés?
4. **Análisis de robustez**: ¿Qué validaciones faltan? ¿Qué podría fallar?

:::

:::{solution} analisis_1
:class: dropdown

**1. Identificación de Roles por Función:**

**`inicializar_sistema`:**
- `capacidad_inicial`: Parámetro de entrada (tamaño inicial)
- `sistema`: Variable de salida local (estructura a retornar)

**`agregar_estudiante`:**
- `sistema`: Parámetro de entrada/salida (modificado por referencia)
- `nombre`, `edad`, `promedio`: Parámetros de entrada
- `nueva_capacidad`: Variable temporal (cálculo de redimensión)
- `nueva_lista`: Variable temporal/auxiliar (para verificación de realloc)

**`buscar_mejor_estudiante`:**
- `sistema`: Parámetro de entrada (solo lectura)
- `mejor`: Variable de mejor candidato/guardián
- `i`: Variable de control de bucle

**`liberar_sistema`:**
- `sistema`: Parámetro de entrada (puntero a liberar)

**2. Análisis de Memoria:**

**Estado inicial**: 
- Heap: `sizeof(sistema_estudiantes_t)` + `capacidad_inicial * sizeof(estudiante_t)`
- Pila: Variables locales de cada función

**Durante agregado**: 
- Si `cantidad < capacidad`: Solo se modifica contenido
- Si `cantidad >= capacidad`: Realloc duplica el espacio, posible fragmentación

**3. Patrones de Diseño:**
- **Dynamic Array**: Lista que crece automáticamente
- **Handle Pattern**: El sistema actúa como handle para la colección
- **RAII-like**: Funciones específicas para inicializar y limpiar

**4. Análisis de Robustez - Problemas identificados:**

**Falta de validaciones:**
```c
// En agregar_estudiante - faltan validaciones:
if (sistema == NULL || nombre == NULL) {
    return false;
}
if (strlen(nombre) >= 50) { // nombre muy largo
    return false;
}
if (edad < 0 || edad > 120) { // edad inválida
    return false;
}
if (promedio < 0.0 || promedio > 10.0) { // promedio inválido
    return false;
}
```

**Problemas de robustez:**
- No validación de punteros NULL
- No verificación de límites de strings
- No validación de rangos de datos
- Posible integer overflow en `nueva_capacidad`
- No hay función para verificar estado del sistema

**Mejoras sugeridas:**
- Agregar validaciones de entrada en todas las funciones
- Implementar códigos de error más específicos
- Agregar función de consulta de estado
- Considerar límite máximo de capacidad
- Agregar tests unitarios para cada función

:::

Este ejercicio integra todos los conceptos de análisis de código, roles de variables, manejo de memoria y buenas prácticas de programación en C.

## 11: Análisis Avanzado de Punteros

### 11.1: Punteros y Aliasing

:::{exercise} analisis_aliasing
:label: analisis_aliasing

Analizá el siguiente código que presenta un problema común con punteros:

```c
#include <stdio.h>
#include <string.h>

void procesar_datos(int *p1, int *p2, int valor) {
    *p1 = valor;
    *p2 = valor * 2;
    
    printf("p1 apunta a: %d\n", *p1);
    printf("p2 apunta a: %d\n", *p2);
}

int main(void) {
    int x = 10;
    
    // Caso 1
    procesar_datos(&x, &x, 5);
    printf("Resultado x: %d\n\n", x);
    
    // Caso 2
    int y = 10;
    int z = 20;
    procesar_datos(&y, &z, 5);
    printf("Resultado y: %d, z: %d\n", y, z);
    
    return 0;
}
```

**Tarea**:

1. **Análisis de aliasing**: ¿Qué sucede cuando `p1` y `p2` apuntan a la misma dirección?
2. **Predicción de salida**: ¿Qué valores se imprimirán en cada caso?
3. **Identificación del problema**: ¿Por qué el Caso 1 produce un resultado inesperado?
4. **Roles de variables**: Identificá el rol de `p1`, `p2` y `valor`
5. **Mejoras**: ¿Cómo modificarías la función para prevenir este problema?

:::

:::{solution} analisis_aliasing
:class: dropdown

**1. Análisis de Aliasing:**

En el Caso 1, `p1` y `p2` apuntan a la misma dirección de memoria (`&x`). Esto se llama **aliasing** y provoca que las modificaciones a través de un puntero afecten al otro.

**Secuencia de ejecución en Caso 1:**
```
*p1 = valor;       // x = 5
*p2 = valor * 2;   // x = 10 (sobrescribe el valor anterior)
```

**2. Predicción de Salida:**

**Caso 1:**
```
p1 apunta a: 10    // p1 y p2 apuntan a x, que vale 10
p2 apunta a: 10
Resultado x: 10
```

**Caso 2:**
```
p1 apunta a: 5     // y = 5
p2 apunta a: 10    // z = 10
Resultado y: 5, z: 10
```

**3. Identificación del Problema:**

El problema es que la función asume que `p1` y `p2` apuntan a ubicaciones diferentes. Cuando apuntan a la misma, la segunda asignación sobrescribe la primera, perdiendo el valor original.

**4. Roles de Variables:**

- `p1`: **Parámetro de salida (output parameter)** - modifica el valor apuntado
- `p2`: **Parámetro de salida (output parameter)** - modifica otro valor apuntado
- `valor`: **Parámetro de entrada (input parameter)** - valor base para los cálculos

**5. Mejoras Sugeridas:**

**Opción 1: Verificar aliasing**
```c
void procesar_datos(int *p1, int *p2, int valor) {
    if (p1 == p2) {
        fprintf(stderr, "Error: p1 y p2 no pueden apuntar a la misma dirección\n");
        return;
    }
    *p1 = valor;
    *p2 = valor * 2;
}
```

**Opción 2: Usar `restrict` (C99)**
```c
void procesar_datos(int *restrict p1, int *restrict p2, int valor) {
    *p1 = valor;
    *p2 = valor * 2;
}
```
El keyword `restrict` promete al compilador que los punteros no tienen aliasing.

**Opción 3: Documentar el requisito**
```c
// PRECONDICIÓN: p1 y p2 deben apuntar a ubicaciones diferentes
// POSTCONDICIÓN: *p1 = valor, *p2 = valor * 2
void procesar_datos(int *p1, int *p2, int valor);
```

:::

### 11.2: Punteros Colgantes (Dangling Pointers)

:::{exercise} analisis_dangling
:label: analisis_dangling

Analizá el siguiente código que contiene varios errores relacionados con punteros colgantes:

```c
#include <stdlib.h>
#include <string.h>

// Función A
char* obtener_saludo(void) {
    char saludo[50] = "Hola, mundo!";
    return saludo;  // Línea problemática 1
}

// Función B
int* crear_arreglo_estatico(void) {
    static int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}

// Función C
int* crear_arreglo_dinamico(void) {
    int* arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

// Función D
void procesar_y_liberar(int** ptr) {
    free(*ptr);
    // Línea problemática 2: no se asigna NULL
}

int main(void) {
    // Escenario 1
    char* s1 = obtener_saludo();
    printf("%s\n", s1);  // Comportamiento indefinido
    
    // Escenario 2
    int* arr1 = crear_arreglo_estatico();
    printf("%d\n", arr1[0]);  // OK
    
    // Escenario 3
    int* arr2 = crear_arreglo_dinamico();
    printf("%d\n", arr2[0]);  // OK
    free(arr2);
    
    // Escenario 4
    int* arr3 = crear_arreglo_dinamico();
    procesar_y_liberar(&arr3);
    printf("%d\n", arr3[0]);  // Línea problemática 3: uso después de free
    
    return 0;
}
```

**Tarea**:

1. **Identificar punteros colgantes**: ¿En qué líneas hay punteros colgantes?
2. **Clasificar errores**: Para cada error, explicá por qué ocurre
3. **Análisis de memoria**: Describí el estado de la memoria en cada escenario
4. **Comportamiento**: ¿Qué podría pasar al ejecutar este código?
5. **Correcciones**: Proponé soluciones para cada problema identificado

:::

:::{solution} analisis_dangling
:class: dropdown

**1. Identificación de Punteros Colgantes:**

**Línea problemática 1:** `return saludo;` en `obtener_saludo()`
**Línea problemática 3:** `printf("%d\n", arr3[0]);` después de `procesar_y_liberar()`

**2. Clasificación de Errores:**

**Error 1: Retornar dirección de variable local**
```c
char* obtener_saludo(void) {
    char saludo[50] = "Hola, mundo!";
    return saludo;  // ¡ERROR!
}
```
**Problema:** `saludo` es un arreglo local en el stack. Cuando la función retorna, el stack frame se destruye y la memoria ya no es válida. El puntero retornado apunta a memoria inválida.

**Error 2: No anular puntero después de free**
```c
void procesar_y_liberar(int** ptr) {
    free(*ptr);
    // Debería: *ptr = NULL;
}
```
**Problema:** Después de `free()`, el puntero sigue apuntando a la misma dirección, pero esa memoria ya fue liberada. Esto es un **dangling pointer**.

**3. Análisis de Memoria por Escenario:**

**Escenario 1:**
```
Stack antes de retornar:
[saludo: "Hola, mundo!"] <- puntero s1 apuntará aquí

Stack después de retornar:
[basura o datos de otra función] <- s1 apunta a zona inválida
```
**Resultado:** Comportamiento indefinido. Podría funcionar "por casualidad" o crashear.

**Escenario 2:**
```
Segmento de datos (static):
arr1 -> [1][2][3][4][5]  <- Permanece durante toda la ejecución
```
**Resultado:** OK. Las variables static persisten.

**Escenario 3:**
```
Heap:
arr2 -> [1][2][3][4][5]  <- Memoria reservada con malloc
... uso ...
free(arr2)               <- Memoria liberada
arr2 sigue apuntando aquí (pero ya no es válido)
```
**Resultado:** OK porque se usa antes de free.

**Escenario 4:**
```
Heap:
arr3 -> [1][2][3][4][5]
free(*ptr)               <- Memoria liberada
arr3 -> [???] (memoria inválida)  <- Dangling pointer
printf("%d\n", arr3[0])  <- Acceso a memoria liberada
```
**Resultado:** Comportamiento indefinido. Podría:
- Imprimir basura
- Causar segmentation fault
- "Funcionar" si la memoria no fue reutilizada aún

**4. Comportamiento al Ejecutar:**

- **Escenario 1:** Probablemente imprime basura o el saludo "por suerte"
- **Escenario 2:** Funciona correctamente
- **Escenario 3:** Funciona correctamente
- **Escenario 4:** Comportamiento indefinido, muy probable crash

**5. Correcciones:**

**Corrección Función A - Opción 1: Usar malloc**
```c
char* obtener_saludo(void) {
    char* saludo = malloc(50);
    if (saludo == NULL) return NULL;
    strcpy(saludo, "Hola, mundo!");
    return saludo;  // OK: memoria en heap persiste
}
// El llamador debe hacer free(saludo)
```

**Corrección Función A - Opción 2: Usar static**
```c
char* obtener_saludo(void) {
    static char saludo[50] = "Hola, mundo!";
    return saludo;  // OK: variable static persiste
}
// NOTA: No es thread-safe
```

**Corrección Función A - Opción 3: Pasar buffer**
```c
void obtener_saludo(char* buffer, size_t tam) {
    if (buffer == NULL || tam < 14) return;
    strcpy(buffer, "Hola, mundo!");
}
// Uso:
char saludo[50];
obtener_saludo(saludo, sizeof(saludo));
```

**Corrección Función D:**
```c
void procesar_y_liberar(int** ptr) {
    if (ptr == NULL || *ptr == NULL) return;
    free(*ptr);
    *ptr = NULL;  // IMPORTANTE: Anular el puntero
}
```

**Corrección main():**
```c
int* arr3 = crear_arreglo_dinamico();
procesar_y_liberar(&arr3);
// No usar arr3 aquí
if (arr3 != NULL) {  // Esto ahora es false
    printf("%d\n", arr3[0]);
}
```

**Buenas Prácticas:**
1. Siempre anular punteros después de `free()`
2. No retornar direcciones de variables locales
3. Documentar quién es responsable de liberar memoria
4. Usar herramientas como Valgrind para detectar estos errores
5. Considerar patrones como RAII (en C con funciones de limpieza)

:::

### 11.3: Aritmética de Punteros y Límites de Arreglos

:::{exercise} analisis_aritmetica
:label: analisis_aritmetica

Analizá este código que manipula arreglos usando aritmética de punteros:

```c
#include <stdio.h>
#include <string.h>

void funcion_a(int *arr, size_t n) {
    int *p = arr;
    int *fin = arr + n;
    
    while (p < fin) {
        *p = *p * 2;
        p++;
    }
}

void funcion_b(int *arr, size_t n) {
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

void funcion_c(char *destino, const char *origen) {
    while (*origen != '\0') {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

void funcion_d(int *arr, size_t n) {
    int *inicio = arr;
    int *fin = arr + n - 1;
    
    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        
        inicio++;
        fin--;
    }
}

int main(void) {
    int arreglo[5] = {1, 2, 3, 4, 5};
    
    funcion_a(arreglo, 5);
    funcion_b(arreglo, 5);
    
    char origen[] = "Hola";
    char destino[10];
    funcion_c(destino, origen);
    printf("%s\n", destino);
    
    funcion_d(arreglo, 5);
    funcion_b(arreglo, 5);
    
    return 0;
}
```

**Tarea**:

1. **Propósito de funciones**: Describí qué hace cada función
2. **Análisis de aritmética**: Para cada función, explicá las operaciones con punteros
3. **Roles de punteros**: Identificá el rol de cada puntero en las funciones
4. **Predicción de salida**: ¿Qué imprimirá el programa?
5. **Seguridad**: ¿Qué problemas de seguridad existen? ¿Qué pasa si se pasan parámetros inválidos?
6. **Comparación**: Compará las funciones con versiones equivalentes usando índices

:::

:::{solution} analisis_aritmetica
:class: dropdown

**1. Propósito de Funciones:**

- **`funcion_a`**: Duplica todos los elementos del arreglo
- **`funcion_b`**: Imprime todos los elementos del arreglo
- **`funcion_c`**: Copia una cadena (implementación manual de `strcpy`)
- **`funcion_d`**: Invierte el arreglo in-place

**2. Análisis de Aritmética de Punteros:**

**`funcion_a`:**
```c
int *p = arr;          // p apunta al primer elemento
int *fin = arr + n;    // fin apunta una posición DESPUÉS del último elemento
while (p < fin) {      // Itera mientras p no llegue a fin
    *p = *p * 2;       // Desreferencia: modifica el elemento actual
    p++;               // Avanza al siguiente elemento (p += sizeof(int))
}
```

**Equivalente con índices:**
```c
for (size_t i = 0; i < n; i++) {
    arr[i] = arr[i] * 2;
}
```

**`funcion_b`:**
```c
for (int *p = arr; p < arr + n; p++) {
    // p recorre desde arr[0] hasta arr[n-1]
    printf("%d ", *p);
}
```

**`funcion_c`:**
```c
while (*origen != '\0') {    // Itera hasta encontrar el terminador
    *destino = *origen;      // Copia carácter por carácter
    destino++;               // Avanza ambos punteros
    origen++;
}
*destino = '\0';             // Agrega terminador al destino
```

**`funcion_d`:**
```c
int *inicio = arr;           // Apunta al primer elemento
int *fin = arr + n - 1;      // Apunta al último elemento
while (inicio < fin) {       // Se encuentran en el medio
    // Intercambia *inicio con *fin
    int temp = *inicio;
    *inicio = *fin;
    *fin = temp;
    inicio++;                // Avanzan hacia el centro
    fin--;
}
```

**3. Roles de Punteros:**

**`funcion_a`:**
- `arr`: Parámetro de entrada/salida (array a modificar)
- `p`: Iterador/caminante (walker) - recorre el arreglo
- `fin`: Centinela (sentinel) - marca el límite superior

**`funcion_b`:**
- `arr`: Parámetro de entrada (array a imprimir)
- `p`: Iterador/caminante - recorre el arreglo

**`funcion_c`:**
- `destino`: Parámetro de salida (destino de la copia)
- `origen`: Parámetro de entrada (fuente de datos)
- Ambos actúan como caminantes que avanzan en paralelo

**`funcion_d`:**
- `arr`: Parámetro de entrada/salida
- `inicio`: Caminante que avanza desde el principio
- `fin`: Caminante que retrocede desde el final
- `temp`: Variable auxiliar temporal para intercambio

**4. Predicción de Salida:**

```
Estado inicial: arreglo = {1, 2, 3, 4, 5}

Después de funcion_a: {2, 4, 6, 8, 10}
Salida de funcion_b: "2 4 6 8 10 "

Después de funcion_c: destino = "Hola"
Salida: "Hola"

Después de funcion_d: arreglo = {10, 8, 6, 4, 2}
Salida de funcion_b: "10 8 6 4 2 "
```

**5. Problemas de Seguridad:**

**`funcion_a` y `funcion_b`:**
- **Puntero NULL**: Si `arr == NULL`, desreferencia causa crash
- **n inválido**: Si `n = 0`, funciona pero no hace nada. Si `n` es muy grande, acceso fuera de límites

**Validación sugerida:**
```c
void funcion_a(int *arr, size_t n) {
    if (arr == NULL || n == 0) return;
    // ... resto del código
}
```

**`funcion_c` - Problema crítico:**
```c
void funcion_c(char *destino, const char *origen) {
    // NO verifica el tamaño de destino
    // Puede causar BUFFER OVERFLOW
}
```

**Escenario peligroso:**
```c
char origen[] = "Esta cadena es muy larga";
char destino[5];  // Solo 5 bytes!
funcion_c(destino, origen);  // BUFFER OVERFLOW
```

**Versión segura:**
```c
void funcion_c_segura(char *destino, const char *origen, size_t tam_destino) {
    if (destino == NULL || origen == NULL || tam_destino == 0) return;
    
    while (*origen != '\0' && tam_destino > 1) {
        *destino = *origen;
        destino++;
        origen++;
        tam_destino--;
    }
    *destino = '\0';
}
```

**O usar `strncpy`:**
```c
strncpy(destino, origen, sizeof(destino) - 1);
destino[sizeof(destino) - 1] = '\0';
```

**`funcion_d`:**
- **Puntero NULL**: Crash si `arr == NULL`
- **n = 0**: `arr + n - 1` apunta ANTES de `arr` (comportamiento indefinido)
- **n = 1**: Funciona correctamente (no hace nada)

**Validación sugerida:**
```c
void funcion_d(int *arr, size_t n) {
    if (arr == NULL || n <= 1) return;
    // ... resto del código
}
```

**6. Comparación: Punteros vs Índices**

**Ventajas de punteros:**
- Más eficiente en algunos compiladores (menos operaciones)
- Más "idiomático" en C para ciertos algoritmos
- No necesita calcular `arr[i]` en cada iteración

**Ventajas de índices:**
- Más legible y fácil de entender
- Más seguro (menos probabilidad de errores)
- Mejor para debugging (puedes ver el índice)
- No pierde la referencia al inicio del arreglo

**Comparación de rendimiento:**

Compiladores modernos con optimización suelen generar el mismo código máquina para ambas versiones, así que la legibilidad debería ser el factor decisivo.

**Recomendación:** Usar índices por defecto, punteros solo cuando:
- La lógica sea más clara con punteros (ej: `funcion_d`)
- Se necesite pasar punteros intermedios
- Se implemente una interfaz que requiera punteros

**Ejemplo de refactorización de `funcion_a` con índices:**
```c
void funcion_a(int *arr, size_t n) {
    if (arr == NULL) return;
    for (size_t i = 0; i < n; i++) {
        arr[i] *= 2;
    }
}
```

:::

### 11.4: Punteros a Funciones y Callbacks

:::{exercise} analisis_callbacks
:label: analisis_callbacks

Analizá este código que implementa callbacks usando punteros a funciones:

```c
#include <stdio.h>
#include <stdbool.h>

typedef bool (*predicado_t)(int);
typedef int (*operacion_t)(int);

bool es_par(int n) {
    return n % 2 == 0;
}

bool es_positivo(int n) {
    return n > 0;
}

int duplicar(int n) {
    return n * 2;
}

int cuadrado(int n) {
    return n * n;
}

// Función A
int contar_si(const int *arr, size_t n, predicado_t predicado) {
    int contador = 0;
    for (size_t i = 0; i < n; i++) {
        if (predicado(arr[i])) {
            contador++;
        }
    }
    return contador;
}

// Función B
void aplicar(int *arr, size_t n, operacion_t operacion) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = operacion(arr[i]);
    }
}

// Función C
void procesar(int *arr, size_t n, 
              predicado_t filtro, 
              operacion_t transformacion) {
    for (size_t i = 0; i < n; i++) {
        if (filtro(arr[i])) {
            arr[i] = transformacion(arr[i]);
        }
    }
}

int main(void) {
    int numeros[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5};
    size_t n = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Pares: %d\n", contar_si(numeros, n, es_par));
    printf("Positivos: %d\n", contar_si(numeros, n, es_positivo));
    
    int copia1[] = {1, 2, 3, 4, 5};
    aplicar(copia1, 5, duplicar);
    
    int copia2[] = {-2, -1, 0, 1, 2};
    procesar(copia2, 5, es_positivo, cuadrado);
    
    return 0;
}
```

**Tarea**:

1. **Análisis de tipos**: Explicá qué son `predicado_t` y `operacion_t`
2. **Roles de punteros a función**: ¿Qué rol cumplen en cada función?
3. **Flujo de ejecución**: Trazá el flujo cuando se llama `contar_si(numeros, n, es_par)`
4. **Predicción de resultados**: ¿Qué valores finales tienen `copia1` y `copia2`?
5. **Ventajas del patrón**: ¿Por qué este diseño es mejor que tener múltiples funciones específicas?
6. **Extensión**: ¿Cómo agregarías una función que encuentre el primer elemento que cumple una condición?

:::

:::{solution} analisis_callbacks
:class: dropdown

**1. Análisis de Tipos:**

```c
typedef bool (*predicado_t)(int);
typedef int (*operacion_t)(int);
```

**`predicado_t`**: 
- Es un **tipo de puntero a función**
- La función apuntada debe recibir un `int` y retornar `bool`
- Se usa para funciones que evalúan condiciones/predicados

**`operacion_t`**:
- Es un **tipo de puntero a función**
- La función apuntada debe recibir un `int` y retornar `int`
- Se usa para funciones que transforman valores

**Sintaxis explicada:**
```c
// Sin typedef (más confuso):
bool (*predicado)(int);  // Variable que es puntero a función

// Con typedef (más claro):
predicado_t predicado;   // Variable de tipo "puntero a función"
```

**2. Roles de Punteros a Función:**

**En `contar_si`:**
- `predicado`: **Callback/Strategy** - define la estrategia de filtrado
- Rol: Inyección de dependencia - el comportamiento se define externamente

**En `aplicar`:**
- `operacion`: **Callback/Transformer** - define cómo transformar cada elemento
- Rol: Separación de iteración y operación

**En `procesar`:**
- `filtro`: **Callback/Predicate** - decide qué elementos procesar
- `transformacion`: **Callback/Transformer** - define cómo procesar
- Rol: Composición de comportamientos

**3. Flujo de Ejecución:**

**Llamada:** `contar_si(numeros, n, es_par)`

```
Paso 1: Entrada a contar_si
  arr = &numeros[0]
  n = 9
  predicado = dirección de es_par

Paso 2: Inicialización
  contador = 0

Paso 3: Iteración i=0
  arr[0] = -3
  predicado(-3)  -> llamada a es_par(-3)
    return -3 % 2 == 0  -> false
  if (false) -> no incrementa contador

Paso 4: Iteración i=1
  arr[1] = -2
  predicado(-2)  -> llamada a es_par(-2)
    return -2 % 2 == 0  -> true
  if (true) -> contador++ (contador = 1)

Paso 5: Iteración i=2
  arr[2] = -1
  predicado(-1)  -> es_par(-1) -> false
  No incrementa

Paso 6: Iteración i=3
  arr[3] = 0
  predicado(0)  -> es_par(0) -> true
  contador++ (contador = 2)

... continúa ...

Resultado: contador = 5 (elementos: -2, 0, 2, 4)
```

**4. Predicción de Resultados:**

**`copia1` después de `aplicar(copia1, 5, duplicar)`:**
```
Estado inicial: {1, 2, 3, 4, 5}
Después de aplicar duplicar a cada elemento:
copia1 = {2, 4, 6, 8, 10}
```

**`copia2` después de `procesar(copia2, 5, es_positivo, cuadrado)`:**
```
Estado inicial: {-2, -1, 0, 1, 2}

Procesamiento:
- copia2[0] = -2  -> es_positivo(-2) = false -> no transforma
- copia2[1] = -1  -> es_positivo(-1) = false -> no transforma
- copia2[2] = 0   -> es_positivo(0)  = false -> no transforma
- copia2[3] = 1   -> es_positivo(1)  = true  -> cuadrado(1) = 1
- copia2[4] = 2   -> es_positivo(2)  = true  -> cuadrado(2) = 4

Estado final: {-2, -1, 0, 1, 4}
```

**Salida completa del programa:**
```
Pares: 5
Positivos: 5
```

**5. Ventajas del Patrón:**

**Sin callbacks (enfoque ingenuo):**
```c
int contar_pares(const int *arr, size_t n) {
    int contador = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) contador++;
    }
    return contador;
}

int contar_positivos(const int *arr, size_t n) {
    int contador = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > 0) contador++;
    }
    return contador;
}

int contar_negativos(const int *arr, size_t n) {
    // Otra función casi idéntica...
}
// ¡Mucha duplicación!
```

**Con callbacks (enfoque genérico):**
```c
// Una sola función, infinitas posibilidades
int contar_si(const int *arr, size_t n, predicado_t pred);

// Uso:
contar_si(arr, n, es_par);
contar_si(arr, n, es_positivo);
contar_si(arr, n, es_negativo);
contar_si(arr, n, es_multiplo_de_tres);
// ... cualquier predicado
```

**Ventajas:**
1. **DRY (Don't Repeat Yourself)**: Evita duplicación de código
2. **Extensibilidad**: Agregar nuevas condiciones sin modificar código existente
3. **Composición**: Combinar comportamientos (como en `procesar`)
4. **Testabilidad**: Más fácil probar funciones pequeñas e independientes
5. **Reusabilidad**: Las funciones de alto nivel sirven para múltiples propósitos

**Patrón de diseño:** **Strategy Pattern** - el comportamiento se selecciona en tiempo de ejecución

**6. Extensión - Encontrar Primer Elemento:**

```c
int* encontrar_si(int *arr, size_t n, predicado_t predicado) {
    for (size_t i = 0; i < n; i++) {
        if (predicado(arr[i])) {
            return &arr[i];  // Retorna puntero al primer elemento que cumple
        }
    }
    return NULL;  // No se encontró
}

// Uso:
int numeros[] = {-3, -2, -1, 0, 1, 2, 3};
int *primer_positivo = encontrar_si(numeros, 7, es_positivo);

if (primer_positivo != NULL) {
    printf("Primer positivo: %d\n", *primer_positivo);
} else {
    printf("No hay positivos\n");
}
```

**Extensión adicional - Con contexto:**

A veces los callbacks necesitan estado adicional. Se puede extender usando un puntero `void*`:

```c
typedef bool (*predicado_ctx_t)(int, void*);

int contar_si_ctx(const int *arr, size_t n, 
                   predicado_ctx_t pred, void* contexto) {
    int contador = 0;
    for (size_t i = 0; i < n; i++) {
        if (pred(arr[i], contexto)) {
            contador++;
        }
    }
    return contador;
}

// Ejemplo: contar mayores que un umbral
bool es_mayor_que(int valor, void* ctx) {
    int umbral = *(int*)ctx;
    return valor > umbral;
}

// Uso:
int umbral = 3;
int cantidad = contar_si_ctx(numeros, n, es_mayor_que, &umbral);
```

**Comparación con otros lenguajes:**

Esta técnica en C es la base de conceptos más avanzados en otros lenguajes:
- **C++**: Templates, functors, lambdas
- **Python**: Lambdas, funciones de orden superior
- **JavaScript**: Callbacks, `map`, `filter`, `reduce`

**Ejemplo equivalente en Python:**
```python
numeros = [-3, -2, -1, 0, 1, 2, 3, 4, 5]
pares = len(list(filter(lambda x: x % 2 == 0, numeros)))
positivos = len(list(filter(lambda x: x > 0, numeros)))
```

:::

### 11.5: Análisis Integral - Sistema de Gestión con Punteros

:::{exercise} analisis_integral_punteros
:label: analisis_integral_punteros

Analizá este sistema completo que utiliza múltiples conceptos de punteros:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo_t;

typedef struct {
    nodo_t* primero;
    nodo_t* ultimo;
    size_t tamanio;
} lista_t;

// Función 1
lista_t* lista_crear(void) {
    lista_t* lista = malloc(sizeof(lista_t));
    if (lista == NULL) return NULL;
    
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->tamanio = 0;
    
    return lista;
}

// Función 2
bool lista_insertar_final(lista_t* lista, int dato) {
    if (lista == NULL) return false;
    
    nodo_t* nuevo = malloc(sizeof(nodo_t));
    if (nuevo == NULL) return false;
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (lista->primero == NULL) {
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    } else {
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
    
    lista->tamanio++;
    return true;
}

// Función 3
bool lista_eliminar_primero(lista_t* lista, int* dato) {
    if (lista == NULL || lista->primero == NULL) return false;
    
    nodo_t* temp = lista->primero;
    *dato = temp->dato;
    
    lista->primero = temp->siguiente;
    if (lista->primero == NULL) {
        lista->ultimo = NULL;
    }
    
    free(temp);
    lista->tamanio--;
    return true;
}

// Función 4
void lista_destruir(lista_t* lista) {
    if (lista == NULL) return;
    
    nodo_t* actual = lista->primero;
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
}

// Función 5
void lista_aplicar(lista_t* lista, void (*func)(int*, void*), void* extra) {
    if (lista == NULL || func == NULL) return;
    
    nodo_t* actual = lista->primero;
    while (actual != NULL) {
        func(&actual->dato, extra);
        actual = actual->siguiente;
    }
}

// Función 6
lista_t* lista_filtrar(const lista_t* lista, bool (*pred)(int, void*), void* extra) {
    if (lista == NULL || pred == NULL) return NULL;
    
    lista_t* nueva = lista_crear();
    if (nueva == NULL) return NULL;
    
    nodo_t* actual = lista->primero;
    while (actual != NULL) {
        if (pred(actual->dato, extra)) {
            if (!lista_insertar_final(nueva, actual->dato)) {
                lista_destruir(nueva);
                return NULL;
            }
        }
        actual = actual->siguiente;
    }
    
    return nueva;
}

// Callbacks de ejemplo
void duplicar_dato(int* dato, void* extra) {
    *dato *= 2;
}

bool es_mayor_que(int dato, void* extra) {
    int limite = *(int*)extra;
    return dato > limite;
}

int main(void) {
    lista_t* lista = lista_crear();
    
    for (int i = 1; i <= 5; i++) {
        lista_insertar_final(lista, i);
    }
    
    printf("Lista original (tamaño %zu): ", lista->tamanio);
    nodo_t* actual = lista->primero;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
    
    lista_aplicar(lista, duplicar_dato, NULL);
    
    int limite = 5;
    lista_t* filtrada = lista_filtrar(lista, es_mayor_que, &limite);
    
    printf("Lista filtrada (>5): ");
    actual = filtrada->primero;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
    
    lista_destruir(lista);
    lista_destruir(filtrada);
    
    return 0;
}
```

**Tarea**:

1. **Análisis completo de punteros**: Identificá todos los tipos de punteros usados y su propósito
2. **Diagrama de memoria**: Dibujá el estado de la memoria después de insertar 3 elementos
3. **Roles de variables**: Para cada función, identificá los roles de todas las variables
4. **Análisis de invariantes**: ¿Qué invariantes mantiene la estructura?
5. **Gestión de memoria**: Trazá el ciclo de vida de la memoria en todo el programa
6. **Análisis de robustez**: ¿Qué podría fallar? ¿Qué validaciones existen y cuáles faltan?
7. **Complejidad**: Analizá la complejidad temporal y espacial de cada función

:::

:::{solution} analisis_integral_punteros
:class: dropdown

**1. Análisis Completo de Punteros:**

**Tipos de punteros identificados:**

a) **Puntero a estructura (`lista_t*`):**
   - Maneja el TAD lista como handle opaco
   - Permite modificar la estructura desde funciones
   
b) **Puntero a nodo (`nodo_t*`):**
   - Enlaces en la lista enlazada
   - Variables temporales para recorrido
   
c) **Puntero a dato (`int*`):**
   - Parámetro de salida en `lista_eliminar_primero`
   - Parámetro de entrada/salida en callbacks
   
d) **Puntero a función:**
   - `void (*func)(int*, void*)` en `lista_aplicar`
   - `bool (*pred)(int, void*)` en `lista_filtrar`
   
e) **Puntero genérico (`void*`):**
   - Contexto adicional para callbacks
   - Permite pasar datos de cualquier tipo

**2. Diagrama de Memoria (después de 3 inserciones):**

```
Stack (main):
┌────────────────┐
│ lista  ───────┼─────┐
└────────────────┘     │
                       │
Heap:                  ↓
┌─────────────────────────┐
│ lista_t                 │
│ ┌─────────┬───────────┐│
│ │primero─┼─┐         ││
│ │ultimo──┼─┼───┐     ││
│ │tamanio:3│ │   │     ││
│ └─────────┴─┼───┼─────┘│
└─────────────┼───┼───────┘
              │   │
              ↓   │
    ┌─────────────────┐
    │ nodo_t (dato=1) │
    │ ┌────┬────────┐ │
    │ │ 1  │siguiente┼─┐
    │ └────┴────────┘ │ │
    └─────────────────┘ │
                        ↓
              ┌─────────────────┐
              │ nodo_t (dato=2) │
              │ ┌────┬────────┐ │
              │ │ 2  │siguiente┼─┐
              │ └────┴────────┘ │ │
              └─────────────────┘ │
                                  ↓
                        ┌─────────────────┐
                        │ nodo_t (dato=3) │
                        │ ┌────┬────────┐ │
                        │ │ 3  │  NULL  │ │◄─┐
                        │ └────┴────────┘ │  │
                        └─────────────────┘  │
                                             │
        ultimo apunta aquí ──────────────────┘
```

**3. Roles de Variables por Función:**

**`lista_crear`:**
- `lista`: Variable local de salida - estructura recién creada

**`lista_insertar_final`:**
- `lista`: Parámetro de entrada/salida - se modifica
- `dato`: Parámetro de entrada - valor a insertar
- `nuevo`: Variable temporal - nodo recién creado

**`lista_eliminar_primero`:**
- `lista`: Parámetro de entrada/salida - se modifica
- `dato`: Parámetro de salida - valor extraído
- `temp`: Variable temporal - guarda referencia para free

**`lista_destruir`:**
- `lista`: Parámetro de entrada - estructura a liberar
- `actual`: Caminante/iterador - recorre la lista
- `siguiente`: Variable temporal - guarda siguiente antes de liberar actual

**`lista_aplicar`:**
- `lista`: Parámetro de entrada/salida - se pueden modificar elementos
- `func`: Callback - operación a aplicar
- `extra`: Contexto - datos adicionales para callback
- `actual`: Caminante - recorre la lista

**`lista_filtrar`:**
- `lista`: Parámetro de entrada - lista original (const, no modificable)
- `pred`: Callback - condición de filtrado
- `extra`: Contexto - datos para predicado
- `nueva`: Variable local de salida - lista filtrada
- `actual`: Caminante - recorre lista original

**4. Invariantes de la Estructura:**

**Invariantes mantenidos:**

1. **Si `primero == NULL`, entonces `ultimo == NULL`** (lista vacía)
2. **Si `primero != NULL`, entonces `ultimo != NULL`** (lista no vacía)
3. **`ultimo->siguiente == NULL`** (último nodo apunta a NULL)
4. **`tamanio` refleja la cantidad real de nodos**
5. **Si `tamanio == 0`, entonces `primero == NULL`**
6. **Si `tamanio == 1`, entonces `primero == ultimo`**
7. **Todos los nodos son alcanzables desde `primero` siguiendo los enlaces**

**Verificación en operaciones:**

**Insertar en lista vacía:**
```c
if (lista->primero == NULL) {
    lista->primero = nuevo;
    lista->ultimo = nuevo;  // Mantiene invariante 1
}
```

**Eliminar último elemento:**
```c
lista->primero = temp->siguiente;
if (lista->primero == NULL) {
    lista->ultimo = NULL;  // Mantiene invariante 1
}
```

**5. Gestión de Memoria - Ciclo de Vida:**

**Fase 1: Creación**
```
malloc(lista_t)     → Heap block 1
```

**Fase 2: Inserciones (i=1 a 5)**
```
malloc(nodo_t) → Heap block 2 (dato=1)
malloc(nodo_t) → Heap block 3 (dato=2)
malloc(nodo_t) → Heap block 4 (dato=3)
malloc(nodo_t) → Heap block 5 (dato=4)
malloc(nodo_t) → Heap block 6 (dato=5)
```

**Fase 3: Aplicar duplicar**
```
No hay nuevas allocations
Se modifican datos in-place
```

**Fase 4: Filtrar**
```
malloc(lista_t)    → Heap block 7 (nueva lista)
malloc(nodo_t)     → Heap block 8 (dato=6)
malloc(nodo_t)     → Heap block 9 (dato=8)
malloc(nodo_t)     → Heap block 10 (dato=10)
```

**Fase 5: Destrucción**
```
free(block 2), free(block 3), ..., free(block 6)
free(block 1)
free(block 8), free(block 9), free(block 10)
free(block 7)
```

**Total memoria usada:** ~10-12 bloques heap en el pico de ejecución

**6. Análisis de Robustez:**

**Validaciones existentes:**

✅ Verificación de `NULL` en `lista_crear` después de `malloc`
✅ Verificación de `NULL` en `lista_insertar_final`
✅ Verificación de lista vacía en `lista_eliminar_primero`
✅ Verificación de `NULL` en `lista_destruir`
✅ Verificación de parámetros en `lista_aplicar` y `lista_filtrar`

**Problemas potenciales identificados:**

❌ **`lista_crear` no verifica malloc de lista:**
```c
lista_t* lista = malloc(sizeof(lista_t));
if (lista == NULL) return NULL;  // ✅ PERO...
// No inicializa campos si malloc falla parcialmente
```

❌ **`lista_insertar_final` no verifica malloc de nuevo nodo:**
Sí lo hace, está correcto.

❌ **Falta de manejo de errores propagado:**
```c
if (!lista_insertar_final(nueva, actual->dato)) {
    lista_destruir(nueva);  // ✅ Buena práctica
    return NULL;
}
```

❌ **`lista_aplicar` no maneja excepciones en callback:**
Si el callback falla (ej. acceso inválido), no hay forma de recuperarse.

**Mejoras sugeridas:**

```c
// 1. Agregar función de validación
bool lista_es_valida(const lista_t* lista) {
    if (lista == NULL) return false;
    
    // Verificar invariantes
    if (lista->primero == NULL && lista->ultimo != NULL) return false;
    if (lista->primero != NULL && lista->ultimo == NULL) return false;
    
    // Contar nodos
    size_t contador = 0;
    nodo_t* actual = lista->primero;
    while (actual != NULL && contador <= lista->tamanio) {
        contador++;
        actual = actual->siguiente;
    }
    
    return contador == lista->tamanio;
}

// 2. Agregar códigos de error más específicos
typedef enum {
    LISTA_OK = 0,
    LISTA_ERROR_MEMORIA,
    LISTA_ERROR_PARAMETRO_INVALIDO,
    LISTA_ERROR_LISTA_VACIA
} lista_error_t;

// 3. Versión robusta de insertar
lista_error_t lista_insertar_final_v2(lista_t* lista, int dato) {
    if (lista == NULL) return LISTA_ERROR_PARAMETRO_INVALIDO;
    
    nodo_t* nuevo = malloc(sizeof(nodo_t));
    if (nuevo == NULL) return LISTA_ERROR_MEMORIA;
    
    // ... resto de la lógica
    return LISTA_OK;
}
```

**7. Complejidad Temporal y Espacial:**

**`lista_crear`:**
- Temporal: $O(1)$
- Espacial: $O(1)$ - un bloque de tamaño fijo

**`lista_insertar_final`:**
- Temporal: $O(1)$ - acceso directo al último
- Espacial: $O(1)$ - un nodo nuevo

**`lista_eliminar_primero`:**
- Temporal: $O(1)$ - acceso directo al primero
- Espacial: $O(1)$ - libera un nodo

**`lista_destruir`:**
- Temporal: $O(n)$ - recorre todos los nodos
- Espacial: $O(1)$ - usa espacio constante auxiliar

**`lista_aplicar`:**
- Temporal: $O(n \cdot T_{callback})$ - aplica callback a cada elemento
- Espacial: $O(1)$ - sin memoria adicional (modificación in-place)

**`lista_filtrar`:**
- Temporal: $O(n \cdot (T_{pred} + T_{insertar})) = O(n)$ - recorre y copia elementos filtrados
- Espacial: $O(k)$ - nueva lista con k elementos (k ≤ n)

**Comparación con otras implementaciones:**

| Operación | Lista Enlazada | Arreglo Dinámico |
|-----------|----------------|------------------|
| Insertar al final | $O(1)$ con tail | $O(1)$ amortizado |
| Eliminar primero | $O(1)$ | $O(n)$ (desplazar) |
| Acceso por índice | $O(n)$ | $O(1)$ |
| Memoria overhead | Alta (punteros) | Baja + desperdicio |

**Conclusión:** Esta implementación es óptima para operaciones en los extremos, pero ineficiente para acceso aleatorio.

:::

---

Estos 5 ejercicios cubren conceptos avanzados de punteros incluyendo aliasing, punteros colgantes, aritmética de punteros, callbacks con punteros a funciones, y un análisis integral de un sistema completo con múltiples tipos de punteros.
