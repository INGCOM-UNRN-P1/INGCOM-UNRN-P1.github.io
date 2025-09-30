---
title: "Patrón de Único Retorno"
short_title: "Refactorización - Único Retorno"
subtitle:
  "Técnicas avanzadas para implementar el patrón de único punto de salida"
---

## Introducción

El **patrón de único retorno** es una práctica de programación que establece que
cada función debe tener exactamente un punto de salida (un solo `return`). Esta
regla, codificada como {ref}`0x0008h` en nuestras pautas de estilo, tiene
profundas implicaciones en la estructura, legibilidad y mantenibilidad del
código.

La implementación de este patrón requiere refactorizar el código de manera
sistemática, transformando múltiples puntos de salida en un flujo de control
unificado que converge en un único `return` al final de la función. Aunque
inicialmente puede parecer restrictivo, este enfoque conduce a un código más
predecible, fácil de depurar y menos propenso a errores de lógica.

:::{important} Beneficios del patrón único retorno

- **Depuración simplificada**: Un solo punto para colocar breakpoints de salida
- **Mantenimiento de invariantes**: Garantiza que el cleanup y validaciones
  finales siempre se ejecuten
- **Flujo de control predecible**: Elimina salidas tempranas que pueden saltear
  lógica importante
- **Código más estructurado**: Fuerza una organización más clara de la lógica de
  la función 
  
:::

## Fundamentos de la Refactorización

### Patrón Base: Variable de Resultado

### Caso 1: Condicionales Simples

**Función Original:**

```c
int ejemplo(int x) {
    if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}
```

**Versión Refactorizada:**

```c
int ejemplo(int x) {
    int resultado = 0;
    if (x > 0) {
        resultado = 1;
    }
    return resultado;
}
```

---

### Bloques Condicionales (`if-else`)

#### Caso 1: `if-else` Simple

**Función Original:**

```c
int clasificar_numero(int n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    } else {
        return 0;
    }
}
```

**Versión Refactorizada:**

```c
int clasificar_numero(int n) {
    int resultado = 0;
    if (n > 0) {
        resultado = 1;
    } else if (n < 0) {
        resultado = -1;
    }
    return resultado;
}
```

En este caso, se puede inicializar `resultado` con el valor más común o por
defecto, y luego asignar el valor dentro de cada rama condicional.

#### Caso 2: `if` dentro de un Lazo

**Función Original:**

```c
int encontrar_primer_par(int numeros[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0) {
            return numeros[i];
        }
    }
    return -1;
}
```

**Versión Refactorizada:**

```c
int encontrar_primer_par(int numeros[], int tam) {
    int resultado = -1;
    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0) {
            resultado = numeros[i];
            break;
        }
    }
    return resultado;
}
```

En este caso, se utiliza una declaración `break` para salir del lazo temprano,
asignando el valor a `resultado` antes de hacerlo.

---

### Lazos (`for`, `while`)

#### Caso 1: Lazo con Salida Temprana

**Función Original:**

```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    for (int i = 0; i < tam; i++) {
        if (nums[i] == objetivo) {
            return true;
        }
    }
    return false;
}
```

**Versión Refactorizada:**

```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    bool encontrado = false;
    for (int i = 0; i < tam; i++) {
        if (nums[i] == objetivo) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}
```

Aquí, `encontrado` se inicializa en `false` y se actualiza si se encuentra el
objetivo. El lazo se rompe inmediatamente después y se devuelve el resultado al
final.

**Otra Versión Refactorizada:**

### Caso 1: Condicionales Simples

**Función Original:**

```c
int ejemplo(int x) {
    if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}
```

**Versión Refactorizada:**

```c
int ejemplo(int x) {
    int resultado = 0;
    if (x > 0) {
        resultado = 1;
    }
    return resultado;
}
```

### Caso 2: Cadenas if-else Complejas

Para cadenas largas de condiciones, el patrón se mantiene consistente:

```{code-block}c
:caption: Refactorización de cadenas if-else complejas
:linenos:

// Múltiples retornos
const char* evaluar_calificacion(int puntaje) {
    if (puntaje >= 90) {
        return "Excelente";
    } else if (puntaje >= 80) {
        return "Muy Bueno";
    } else if (puntaje >= 70) {
        return "Bueno";
    } else if (puntaje >= 60) {
        return "Regular";
    } else {
        return "Insuficiente";
    }
}

// Único retorno
const char* evaluar_calificacion(int puntaje) {
    const char* resultado = "Insuficiente";  // Caso por defecto

    if (puntaje >= 90) {
        resultado = "Excelente";
    } else if (puntaje >= 80) {
        resultado = "Muy Bueno";
    } else if (puntaje >= 70) {
        resultado = "Bueno";
    } else if (puntaje >= 60) {
        resultado = "Regular";
    }

    return resultado;
}
```

### Caso 3: Validación de Parámetros

La validación de entrada es un caso común que requiere cuidado especial:

```{code-block}c
:caption: Refactorización de validación de parámetros
:linenos:

#include <math.h>

// Múltiples retornos para validación
double calcular_raiz_cuadrada(double numero) {
    if (numero < 0) {
        return -1;  // Error: número negativo
    }
    return sqrt(numero);
}

// Único retorno con validación
double calcular_raiz_cuadrada(double numero) {
    double resultado = -1;  // Valor de error por defecto

    if (numero >= 0) {
        resultado = sqrt(numero);
    }

    return resultado;
}

// Versión más robusta con códigos de error
typedef enum {
    CALC_EXITO,
    CALC_ERROR_NUMERO_NEGATIVO,
    CALC_ERROR_PARAMETRO_NULO
} resultado_calculo_t;

resultado_calculo_t calcular_raiz_segura(double numero, double *resultado) {
    resultado_calculo_t estado = CALC_ERROR_PARAMETRO_NULO;

    if (resultado != NULL) {
        *resultado = 0.0;
        estado = CALC_ERROR_NUMERO_NEGATIVO;

        if (numero >= 0) {
            *resultado = sqrt(numero);
            estado = CALC_EXITO;
        }
    }

    return estado;
}
```

## Refactorización de Lazos

### Búsqueda con Salida Temprana

Los lazos de búsqueda son casos clásicos que requieren refactorización
cuidadosa:

```{code-block}c
:caption: Refactorización de búsquedas en lazos
:linenos:

// Múltiples retornos en lazo
int encontrar_maximo(int arr[], int tam) {
    if (tam <= 0) {
        return -1;  // Error
    }

    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Único retorno
int encontrar_maximo(int arr[], int tam) {
    int resultado = -1;  // Valor de error por defecto

    if (tam > 0) {
        resultado = arr[0];
        for (int i = 1; i < tam; i++) {
            if (arr[i] > resultado) {
                resultado = arr[i];
            }
        }
    }

    return resultado;
}
```

### Búsqueda con Condición de Parada

```{code-block}c
:caption: Búsqueda con condición de parada compleja
:linenos:

#include <stdbool.h>

// Múltiples retornos
bool validar_secuencia(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            return false;  // No está ordenada ascendente
        }
        if (arr[i] < 0) {
            return false;  // Contiene números negativos
        }
    }
    return true;
}

// Único retorno con banderas
bool validar_secuencia(int arr[], int tam) {
    bool es_valida = true;

    for (int i = 0; i < tam - 1 && es_valida; i++) {
        if (arr[i] >= arr[i + 1] || arr[i] < 0) {
            es_valida = false;
        }
    }

    return es_valida;
}

// Versión alternativa con break
bool validar_secuencia_alt(int arr[], int tam) {
    bool es_valida = true;

    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] >= arr[i + 1] || arr[i] < 0) {
            es_valida = false;
            break;
        }
    }

    return es_valida;
}
```

## Patrones Avanzados de Refactorización

### Manejo de Recursos con Cleanup

Uno de los beneficios más importantes del patrón único retorno es garantizar que
el cleanup de recursos siempre se ejecute:

```{code-block}c
:caption: Manejo seguro de recursos
:linenos:

#include <stdio.h>
#include <stdlib.h>

// Múltiples retornos - riesgo de fuga de memoria
int procesar_archivo_original(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        return -1;  // ¡No libera memoria!
    }

    char* buffer = malloc(1024);
    if (!buffer) {
        fclose(archivo);
        return -2;  // Fácil olvidar limpiar recursos
    }

    // Procesar archivo...
    if (/* condición de error */) {
        free(buffer);
        fclose(archivo);
        return -3;  // Repetir cleanup en cada salida
    }

    free(buffer);
    fclose(archivo);
    return 0;
}

// Único retorno - cleanup garantizado
int procesar_archivo_seguro(const char* nombre_archivo) {
    int resultado = -1;  // Valor de error por defecto
    FILE* archivo = NULL;
    char* buffer = NULL;

    archivo = fopen(nombre_archivo, "r");
    if (archivo != NULL) {
        buffer = malloc(1024);
        if (buffer != NULL) {
            // Procesar archivo...
            resultado = 0;  // Éxito

            if (/* condición de error */) {
                resultado = -3;
            }
        } else {
            resultado = -2;  // Error de memoria
        }
    }

    // Cleanup garantizado - siempre se ejecuta
    if (buffer != NULL) {
        free(buffer);
    }
    if (archivo != NULL) {
        fclose(archivo);
    }

    return resultado;
}
```

### Patrón de Estado de Ejecución

Para funciones complejas con múltiples fases, podés usar un estado de ejecución:

```{code-block}c
:caption: Patrón de estado de ejecución
:linenos:

typedef enum {
    ESTADO_INICIO,
    ESTADO_VALIDACION,
    ESTADO_PROCESAMIENTO,
    ESTADO_FINALIZACION,
    ESTADO_ERROR
} estado_ejecucion_t;

int operacion_compleja(int* datos, int tam, int parametro) {
    int resultado = -1;
    estado_ejecucion_t estado = ESTADO_INICIO;

    // Fase 1: Validación
    if (estado == ESTADO_INICIO) {
        if (datos == NULL || tam <= 0) {
            estado = ESTADO_ERROR;
        } else {
            estado = ESTADO_VALIDACION;
        }
    }

    // Fase 2: Validación específica
    if (estado == ESTADO_VALIDACION) {
        bool datos_validos = true;
        for (int i = 0; i < tam && datos_validos; i++) {
            if (datos[i] < 0) {
                datos_validos = false;
            }
        }

        if (datos_validos) {
            estado = ESTADO_PROCESAMIENTO;
        } else {
            estado = ESTADO_ERROR;
        }
    }

    // Fase 3: Procesamiento principal
    if (estado == ESTADO_PROCESAMIENTO) {
        int suma = 0;
        for (int i = 0; i < tam; i++) {
            suma += datos[i] * parametro;
        }

        if (suma > 0) {
            resultado = suma;
            estado = ESTADO_FINALIZACION;
        } else {
            estado = ESTADO_ERROR;
        }
    }

    // Fase 4: Finalización (logging, cleanup, etc.)
    if (estado == ESTADO_FINALIZACION) {
        printf("Operación completada exitosamente: %d\n", resultado);
    } else if (estado == ESTADO_ERROR) {
        printf("Error durante la operación\n");
        resultado = -1;
    }

    return resultado;
}
```

### Refactorización de Switch Statements

Los `switch` statements también pueden beneficiarse del patrón único retorno:

```{code-block}c
:caption: Refactorización de switch statements
:linenos:

typedef enum {
    OPERACION_SUMA,
    OPERACION_RESTA,
    OPERACION_MULTIPLICACION,
    OPERACION_DIVISION
} tipo_operacion_t;

// Múltiples retornos en switch
double calculadora_original(double a, double b, tipo_operacion_t op) {
    switch (op) {
        case OPERACION_SUMA:
            return a + b;
        case OPERACION_RESTA:
            return a - b;
        case OPERACION_MULTIPLICACION:
            return a * b;
        case OPERACION_DIVISION:
            if (b != 0) {
                return a / b;
            } else {
                return 0;  // Error
            }
        default:
            return 0;  // Operación inválida
    }
}

// Único retorno en switch
double calculadora_refactorizada(double a, double b, tipo_operacion_t op) {
    double resultado = 0;  // Valor por defecto/error

    switch (op) {
        case OPERACION_SUMA:
            resultado = a + b;
            break;
        case OPERACION_RESTA:
            resultado = a - b;
            break;
        case OPERACION_MULTIPLICACION:
            resultado = a * b;
            break;
        case OPERACION_DIVISION:
            if (b != 0) {
                resultado = a / b;
            }
            // Si b == 0, resultado mantiene el valor 0 (error)
            break;
        default:
            resultado = 0;  // Operación inválida
            break;
    }

    return resultado;
}
```

## Técnicas para Casos Complejos

### Funciones con Múltiples Tipos de Retorno

Para funciones que pueden retornar diferentes tipos de información:

```{code-block}c
:caption: Manejo de múltiples tipos de retorno
:linenos:

#include <stdbool.h>
#include <string.h>

typedef struct {
    bool exito;
    int codigo_error;
    char mensaje[256];
    double valor;
} resultado_operacion_t;

// Función que puede fallar de múltiples maneras
resultado_operacion_t operacion_compleja(const char* entrada) {
    resultado_operacion_t resultado = {
        .exito = false,
        .codigo_error = 0,
        .mensaje = "",
        .valor = 0.0
    };

    // Validación de entrada
    if (entrada == NULL) {
        resultado.codigo_error = 1;
        strcpy(resultado.mensaje, "Parámetro de entrada nulo");
    } else if (strlen(entrada) == 0) {
        resultado.codigo_error = 2;
        strcpy(resultado.mensaje, "Entrada vacía");
    } else {
        // Simular procesamiento
        double valor_calculado = strlen(entrada) * 3.14;

        if (valor_calculado > 100) {
            resultado.codigo_error = 3;
            strcpy(resultado.mensaje, "Valor calculado excede límite");
        } else {
            // Éxito
            resultado.exito = true;
            resultado.valor = valor_calculado;
            strcpy(resultado.mensaje, "Operación exitosa");
        }
    }

    return resultado;
}
```

### Refactorización de Funciones Recursivas

Las funciones recursivas también pueden beneficiarse del patrón único retorno:

```{code-block}c
:caption: Refactorización de recursión
:linenos:

// Múltiples retornos en recursión
int factorial_original(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_original(n - 1);
}

// Único retorno en recursión
int factorial_refactorizado(int n) {
    int resultado = 1;

    if (n > 1) {
        resultado = n * factorial_refactorizado(n - 1);
    }

    return resultado;
}

// Versión iterativa como alternativa
int factorial_iterativo(int n) {
    int resultado = 1;

    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}
```

## Consideraciones de Rendimiento y Optimización

### Impacto en Optimizaciones del Compilador

El patrón único retorno puede afectar las optimizaciones automáticas:

```{code-block}c
:caption: Consideraciones de rendimiento
:linenos:

// Versión optimizable por el compilador
int busqueda_optimizable(int arr[], int tam, int objetivo) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == objetivo) {
            return i;  // Compilador puede optimizar salida temprana
        }
    }
    return -1;
}

// Versión con único retorno - menos optimizable
int busqueda_unico_retorno(int arr[], int tam, int objetivo) {
    int resultado = -1;

    for (int i = 0; i < tam; i++) {
        if (arr[i] == objetivo) {
            resultado = i;
            break;  // Ayuda al compilador a optimizar
        }
    }

    return resultado;
}

// Versión sin break - potencialmente menos eficiente
int busqueda_sin_break(int arr[], int tam, int objetivo) {
    int resultado = -1;
    bool encontrado = false;

    for (int i = 0; i < tam && !encontrado; i++) {
        if (arr[i] == objetivo) {
            resultado = i;
            encontrado = true;
        }
    }

    return resultado;
}
```

### Medición de Rendimiento

```{code-block}c
:caption: Comparación de rendimiento
:linenos:

#include <time.h>
#include <stdio.h>

void benchmark_busqueda(int* arr, int tam, int objetivo, int iteraciones) {
    clock_t inicio, fin;
    volatile int resultado;  // Evitar optimización completa

    // Benchmark versión con múltiples retornos
    inicio = clock();
    for (int i = 0; i < iteraciones; i++) {
        resultado = busqueda_optimizable(arr, tam, objetivo);
    }
    fin = clock();
    double tiempo_original = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    // Benchmark versión con único retorno
    inicio = clock();
    for (int i = 0; i < iteraciones; i++) {
        resultado = busqueda_unico_retorno(arr, tam, objetivo);
    }
    fin = clock();
    double tiempo_refactorizado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Rendimiento para %d iteraciones:\n", iteraciones);
    printf("  Múltiples retornos: %.6f segundos\n", tiempo_original);
    printf("  Único retorno:      %.6f segundos\n", tiempo_refactorizado);
    printf("  Diferencia:         %.2f%%\n",
           ((tiempo_refactorizado - tiempo_original) / tiempo_original) * 100);
}
```

## Mejores Prácticas y Recomendaciones

### 1. Inicialización Estratégica

```{code-block}c
:caption: Estrategias de inicialización
:linenos:

// Inicializar con valor más probable
bool validar_email(const char* email) {
    bool es_valido = false;  // Asumir inválido hasta probar lo contrario

    if (email != NULL && strlen(email) > 0) {
        // Lógica de validación...
        es_valido = true;  // Solo cambiar si pasa todas las validaciones
    }

    return es_valido;
}

// Inicializar con valor neutro o de identidad
int sumar_pares(int arr[], int tam) {
    int suma = 0;  // Elemento neutro de la suma

    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 == 0) {
            suma += arr[i];
        }
    }

    return suma;
}
```

### 2. Uso Apropiado de `break`

```{code-block}c
:caption: Cuándo usar break vs condiciones en lazo
:linenos:

// Usar break para salida temprana clara
int encontrar_elemento(int arr[], int tam, int objetivo) {
    int indice = -1;

    for (int i = 0; i < tam; i++) {
        if (arr[i] == objetivo) {
            indice = i;
            break;  // Salida temprana clara
        }
    }

    return indice;
}

// Usar condición en lazo para lógica compleja
bool validar_todos(int arr[], int tam) {
    bool todos_validos = true;
    int i = 0;

    while (i < tam && todos_validos) {
        if (arr[i] < 0 || arr[i] > 100) {
            todos_validos = false;
        }
        i++;
    }

    return todos_validos;
}
```

### 3. Documentación del Flujo de Control

```{code-block}c
:caption: Documentación clara del flujo
:linenos:

/**
 * Procesa un arreglo de números y calcula estadísticas básicas.
 *
 * @param numeros Arreglo de enteros a procesar
 * @param tam Tamaño del arreglo
 * @param promedio Puntero donde almacenar el promedio (puede ser NULL)
 * @param maximo Puntero donde almacenar el máximo (puede ser NULL)
 *
 * @return 0 en caso de éxito, -1 si los parámetros son inválidos
 *
 * Flujo de control:
 * 1. Validación de parámetros
 * 2. Cálculo de suma y máximo en un solo paso
 * 3. Cálculo de promedio si se solicita
 * 4. Retorno único con código de estado
 */
int calcular_estadisticas(int numeros[], int tam, double* promedio, int* maximo) {
    int resultado = -1;  // Valor de error por defecto

    // Fase 1: Validación
    if (numeros != NULL && tam > 0) {
        // Fase 2: Cálculo principal
        long suma = 0;
        int max = numeros[0];

        for (int i = 0; i < tam; i++) {
            suma += numeros[i];
            if (numeros[i] > max) {
                max = numeros[i];
            }
        }

        // Fase 3: Asignación de resultados
        if (promedio != NULL) {
            *promedio = (double)suma / tam;
        }
        if (maximo != NULL) {
            *maximo = max;
        }

        resultado = 0;  // Éxito
    }

    return resultado;
}
```

## Casos Especiales y Excepciones

### Cuándo Considerar Múltiples Retornos

Aunque el patrón único retorno es generalmente preferible, hay casos donde
múltiples retornos pueden ser más claros:

```{code-block}c
:caption: Casos donde múltiples retornos pueden ser apropiados
:linenos:

// Funciones de validación muy simples
bool es_par(int numero) {
    return numero % 2 == 0;
}

// Funciones matemáticas puras
double maximo(double a, double b) {
    return (a > b) ? a : b;
}

// Sin embargo, para consistencia con el estilo, podríamos refactorizar:
bool es_par_consistente(int numero) {
    bool resultado = false;

    if (numero % 2 == 0) {
        resultado = true;
    }

    return resultado;
}
```

### Refactorización de Funciones de Biblioteca

```{code-block}c
:caption: Adaptación de patrones de biblioteca estándar
:linenos:

#include <string.h>

// Simulando comportamiento de funciones como strcmp
int comparar_cadenas(const char* str1, const char* str2) {
    int resultado = 0;

    if (str1 != NULL && str2 != NULL) {
        int comparacion = strcmp(str1, str2);

        if (comparacion < 0) {
            resultado = -1;
        } else if (comparacion > 0) {
            resultado = 1;
        }
        // Si comparacion == 0, resultado mantiene valor 0
    } else if (str1 == NULL && str2 != NULL) {
        resultado = -1;
    } else if (str1 != NULL && str2 == NULL) {
        resultado = 1;
    }
    // Si ambos son NULL, resultado mantiene valor 0

    return resultado;
}
```




```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    bool encontrado = false;
    for (int i = 0; i < tam && !encontrado; i++) {
        if (nums[i] == objetivo) {
            encontrado = true;
        }
    }
    return encontrado;
}
```


### Estructuras Anidadas

**Función Original:**

```c
const char* logica_compleja(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            return "Ambos positivos";
        } else {
            return "A positivo, B no positivo";
        }
    } else {
        return "A no positivo";
    }
}
```

**Versión Refactorizada:**

```c
const char* logica_compleja(int a, int b) {
    const char* resultado = "A no positivo";
    if (a > 0) {
        if (b > 0) {
            resultado = "Ambos positivos";
        } else {
            resultado = "A positivo, B no positivo";
        }
    }
    return resultado;
}
```

En condiciones anidadas, se inicializa `resultado` con el caso más general y se refina dentro de cada bloque condicional.

---

### Ejemplo con Procesamiento Posterior al Lazo y Uso de Bloque `if`

En este ejemplo, se muestra cómo refactorizar una función que realiza un procesamiento dentro de un lazo y, después del lazo, evalúa condiciones adicionales que podrían afectar el valor de retorno. La idea es asegurarse de que solo haya un `return` al final de la función, colocando el procesamiento posterior en un bloque `if`.

#### Función Original

```c
const char* analizar_datos(int datos[], int tam, int umbral) {
    for (int i = 0; i < tam; i++) {
        if (datos[i] > umbral) {
            return "Valor encontrado";
        }
    }

    if (tam == 0) {
        return "Sin datos";
    } else if (umbral < 0) {
        return "Umbral inválido";
    }

    return "Valor no encontrado";
}
```

#### Versión Refactorizada

```c
const char* analizar_datos(int datos[], int tam, int umbral) {
    const char* resultado = "Valor no encontrado";

    for (int i = 0; i < tam; i++) {
        if (datos[i] > umbral) {
            resultado = "Valor encontrado";
            break;
        }
    }

    if (resultado == "Valor no encontrado") {
        if (tam == 0) {
            resultado = "Sin datos";
        } else if (umbral < 0) {
            resultado = "Umbral inválido";
        }
    }

    return resultado;
}
```
````
