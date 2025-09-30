---
title: "Ejercicios: Análisis de Código"
short_title: "17. Análisis de Código"
---

## Acerca de

A diferencia de otros ejercicios, el objetivo aquí no es escribir código, sino
**analizarlo**. La capacidad de leer, entender y razonar sobre un código
existente es una habilidad tan importante como la de escribirlo. Estos
ejercicios están diseñados para aplicar los conceptos teóricos de los apuntes
sobre **Roles de Variables** y **Estado de un Programa**.

:::{note} Habilidades a desarrollar
- **Comprensión de código**: Leer y entender código escrito por otros
- **Identificación de patrones**: Reconocer roles y propósitos de variables
- **Análisis de flujo de control**: Seguir la ejecución paso a paso
- **Debugging mental**: Identificar posibles problemas sin ejecutar el código
:::

## 1: Identificación de Roles de Variables

### 1.1: Análisis de una Función

#### Descripción

Dado el siguiente código, identificá el "rol" principal de cada una de las
variables listadas, basándote en las definiciones del apunte `extras/roles.md`.

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

:::{solution} Roles 
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

#### Descripción

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

:::{solution} Roles Búsqueda
:class: dropdown

1. **`maximo`**: **Variable de Mejor Candidato/Guardián**. Mantiene el valor máximo encontrado hasta el momento.
2. **`hay_elementos`**: **Bandera de Inicialización**. Indica si ya se procesó al menos un elemento para inicializar correctamente la comparación.
3. **`encontrado`**: **Parámetro de Salida/Bandera de Estado**. Comunica al llamador si la operación fue exitosa.
4. **`indice`**: **Variable de Control de Bucle/Iterador**. Controla el recorrido del arreglo.

:::

### 1.3: Análisis de Función con Múltiples Roles

#### Descripción

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

:::{solution} Roles Múltiples
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

#### Descripción

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

:::{solution} Estado del Programa 
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

#### Descripción

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

:::{solution} Estado con Estructuras
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

#### Descripción

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

:::{solution} Trazado de Ejecución
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

#### Descripción

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

:::{solution} Análisis de Bugs
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

#### Descripción

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

:::{solution} Memory Leaks
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

#### Descripción

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

:::{solution} Análisis de Complejidad
:class: dropdown

**Análisis de `buscar_par_suma`:**
- **Complejidad temporal**: O(n²) - hay dos bucles anidados que recorren el array
- **Variables de control**: 
  - `i`: Iterador externo (rol: control de bucle principal)
  - `j`: Iterador interno (rol: control de bucle secundario, siempre j > i)
- **Complejidad espacial**: O(1) - solo usa variables locales

**Análisis de `buscar_par_suma_optimizado`:**
- **Complejidad temporal**: O(n) - cada elemento se visita máximo una vez
- **Variables de control**:
  - `izq`: Puntero izquierdo (rol: guardián del límite inferior)
  - `der`: Puntero derecho (rol: guardián del límite superior)
  - `suma_actual`: Variable temporal (rol: almacén de cálculo intermedio)
- **Complejidad espacial**: O(1)

**Escenarios apropiados:**
- **Primer algoritmo**: Cuando el array NO está ordenado y no podemos/queremos ordenarlo
- **Segundo algoritmo**: Cuando el array YA está ordenado o el costo de ordenarlo es amortizable

**Trade-offs:**
- Si necesitamos ordenar: O(n log n) + O(n) vs O(n²)
- Si ya está ordenado: O(n) vs O(n²) - clara ventaja para el optimizado

:::

### 4.2: Análisis de Uso de Memoria

#### Descripción

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

:::{solution} Análisis de Memoria
:class: dropdown

**Versión Recursiva:**
- **Pila**: O(n) - cada llamada recursiva agrega un marco a la pila
- **Heap**: O(1) - no usa memoria dinámica
- **Variables**: Solo el parámetro `n` en cada marco (rol: parámetro de entrada)
- **Riesgo**: Stack overflow para valores grandes de n

**Versión Iterativa:**
- **Pila**: O(1) - un solo marco de función
- **Heap**: O(1) - no usa memoria dinámica  
- **Variables**:
  - `resultado`: Acumulador para el producto
  - `i`: Variable de control de bucle
- **Ventajas**: Uso mínimo de memoria, sin riesgo de stack overflow

**Versión Memoizada:**
- **Pila**: O(n) - similar a recursiva en la primera llamada, O(1) en llamadas subsecuentes
- **Heap**: O(n) - array para almacenar resultados calculados
- **Variables**:
  - `cache`: Array estático global (rol: almacén de resultados)
  - `cache_size`: Contador de tamaño actual (rol: guardián de límites)
- **Trade-off**: Usa más memoria pero acelera dramáticamente cálculos repetidos

**Comparación de Trade-offs:**

| Aspecto | Recursiva | Iterativa | Memoizada |
|---------|-----------|-----------|-----------|
| Tiempo (primera llamada) | O(n) | O(n) | O(n) |
| Tiempo (llamadas repetidas) | O(n) | O(n) | O(1) |
| Espacio en pila | O(n) | O(1) | O(n)→O(1) |
| Espacio en heap | O(1) | O(1) | O(n) |
| Legibilidad | Alta | Media | Baja |
| Riesgo de overflow | Alto | Bajo | Medio |

:::

## 5: Ejercicios de Síntesis

### 5.1: Análisis Integral de Sistema

#### Descripción

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

:::{solution} Análisis Integral
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
