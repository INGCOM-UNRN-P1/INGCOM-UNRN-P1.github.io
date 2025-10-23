---
title: "Testing"
short_title: "Testing"
subtitle: "Como asegurarnos de que nuestros programas hagan lo que creemos que hacen"
---

## Testing

El **testing** o prueba de software es una práctica fundamental en el desarrollo que consiste en verificar que el código funciona como se espera bajo diferentes condiciones. En programación, no basta con que el código «parezca» funcionar; es necesario someterlo a pruebas sistemáticas que validen su comportamiento.

### ¿Para qué probar?

Las pruebas cumplen múltiples propósitos esenciales en el ciclo de desarrollo:

- **Validar funcionalidad aislada**: Cada componente debe funcionar correctamente de manera independiente.
- **Detectar errores temprano**: Encontrar bugs durante el desarrollo es significativamente más económico que hacerlo en producción.
- **Facilitar refactorizaciones**: Un conjunto sólido de pruebas permite modificar el código con confianza, sabiendo que las pruebas detectarán cualquier regresión.
- **Mejorar calidad y documentación**: Las pruebas sirven como ejemplos ejecutables de cómo usar el código.
- **Reducir el tiempo de debugging**: Los errores localizados mediante pruebas son más fáciles de diagnosticar.
- **Aumentar la confianza**: Tanto del desarrollador como del usuario final en la estabilidad del sistema.

:::{important}
En proyectos profesionales, el testing no es opcional. Es una práctica estándar que se espera en cualquier código de calidad industrial.
:::

### Tipos de Testing

Existen diferentes niveles de testing, cada uno con un propósito específico:

#### Testing Unitario

Las **pruebas unitarias** verifican el comportamiento de funciones o módulos individuales de forma aislada. Son las pruebas más granulares y fundamentales.

**Características:**
- Rápidas de ejecutar
- Fáciles de diagnosticar cuando fallan
- Deben ser independientes entre sí
- Cubren casos normales, extremos y de error

#### Testing de Integración

Las **pruebas de integración** verifican que múltiples componentes funcionen correctamente cuando se combinan. Por ejemplo, que una función de procesamiento de datos trabaje adecuadamente con las funciones de entrada/salida.

#### Testing de Sistema

Las **pruebas de sistema** evalúan el comportamiento del programa completo, desde la perspectiva del usuario final.

### Anatomía de una Prueba

Una prueba bien estructurada típicamente sigue el patrón **AAA (Arrange-Act-Assert)**:

1. **Arrange (Preparar)**: Configurar los datos y el estado necesario
2. **Act (Actuar)**: Ejecutar la función bajo prueba
3. **Assert (Verificar)**: Comprobar que el resultado es el esperado

```c
void test_suma_positivo_positivo() {
    // Arrange: preparar datos de entrada
    int a = 5, b = 3;
    int esperado = 8;
    
    // Act: ejecutar la función
    int resultado = suma(a, b);
    
    // Assert: verificar el resultado
    assert(resultado == esperado);
}
```

### Casos de Prueba Importantes

Al diseñar pruebas, es crucial considerar diferentes categorías de casos:

#### Casos Normales

Representan el uso típico y esperado de la función:

```c
void test_suma_numeros_positivos() {
    assert(suma(10, 20) == 30);
}

void test_suma_numeros_negativos() {
    assert(suma(-5, -3) == -8);
}
```

#### Casos Límite (Boundary Cases)

Prueban los extremos del dominio de entrada:

```c
void test_suma_con_cero() {
    assert(suma(0, 5) == 5);
    assert(suma(5, 0) == 5);
    assert(suma(0, 0) == 0);
}

void test_suma_valores_maximos() {
    // Probar cerca de los límites del tipo de dato
    assert(suma(INT_MAX - 1, 1) == INT_MAX);
}
```

#### Casos de Error

Verifican el comportamiento ante entradas inválidas o condiciones de error:

```c
void test_division_por_cero() {
    // La función debería manejar este error
    int resultado;
    bool exito = division_segura(10, 0, &resultado);
    assert(exito == false);
}
```

#### Casos de Esquina (Corner Cases)

Combinaciones inusuales pero válidas de condiciones límite:

```c
void test_buscar_en_array_vacio() {
    int array[] = {};
    assert(buscar(array, 0, 42) == -1);
}
```

### Uso de `assert`

La macro `assert` es la herramienta básica para verificar condiciones en C:

```c
#include <assert.h>

// Uso básico
assert(condición); // Si es falsa, termina el programa

// Ejemplos
assert(suma(2, 3) == 5);
assert(resultado != NULL);
assert(tamanio > 0 && tamanio <= MAX_TAMANIO);
```

:::{warning}
**Importante sobre `assert` en producción**

- `assert` está diseñado para desarrollo y debugging
- Se puede desactivar con `#define NDEBUG` antes de incluir `<assert.h>`
- En código de producción compilado con optimizaciones, los `assert` típicamente se eliminan
- Para validaciones que deben ejecutarse siempre, usar estructuras condicionales normales (`if`)

```c
// ✗ NO usar assert para validar entrada del usuario
assert(edad >= 0 && edad <= 150);

// ✓ Usar validación explícita
if (edad < 0 || edad > 150) {
    fprintf(stderr, "Error: edad inválida\n");
    return ERROR_ENTRADA_INVALIDA;
}
```
:::

### Estrategias de Testing

#### Cobertura de Código

La **cobertura** mide qué porcentaje del código es ejecutado por las pruebas. Tipos comunes:

- **Cobertura de líneas**: ¿Se ejecuta cada línea?
- **Cobertura de ramas**: ¿Se prueba cada camino condicional?
- **Cobertura de funciones**: ¿Se llama cada función?

```c
int valor_absoluto(int x) {
    if (x < 0) {        // Rama 1
        return -x;
    }
    return x;           // Rama 2
}

// Para 100% cobertura de ramas:
void test_valor_absoluto() {
    assert(valor_absoluto(-5) == 5);   // Prueba rama 1
    assert(valor_absoluto(5) == 5);    // Prueba rama 2
    assert(valor_absoluto(0) == 0);    // Caso límite
}
```

#### Testing Basado en Propiedades

En lugar de casos específicos, verificar propiedades generales:

```c
void test_suma_conmutativa() {
    // Propiedad: a + b = b + a
    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            assert(suma(i, j) == suma(j, i));
        }
    }
}

void test_suma_elemento_neutro() {
    // Propiedad: x + 0 = x
    for (int i = -100; i <= 100; i++) {
        assert(suma(i, 0) == i);
    }
}
```

### Organización de Tests

Un proyecto bien estructurado separa el código de producción de las pruebas:

```
proyecto/
├── src/
│   ├── calculadora.h
│   ├── calculadora.c
│   └── main.c
├── tests/
│   ├── test_calculadora.c
│   ├── test_utilidades.c
│   └── run_tests.c
└── Makefile
```

Ejemplo de estructura de archivo de pruebas:

```c
// tests/test_calculadora.c
#include <assert.h>
#include <stdio.h>
#include "../src/calculadora.h"

void test_suma() {
    assert(suma(2, 3) == 5);
    assert(suma(-1, 1) == 0);
    printf("✓ test_suma pasó\n");
}

void test_resta() {
    assert(resta(5, 3) == 2);
    assert(resta(3, 5) == -2);
    printf("✓ test_resta pasó\n");
}

int main() {
    printf("Ejecutando pruebas de calculadora...\n");
    test_suma();
    test_resta();
    printf("Todas las pruebas pasaron exitosamente\n");
    return 0;
}
```

### Frameworks de Testing en C

Aunque `assert` es útil para pruebas simples, existen frameworks más completos:

#### Ejemplo con estructura propia

```c
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int ejecutadas;
    int exitosas;
    int fallidas;
} EstadisticasTest;

EstadisticasTest stats = {0, 0, 0};

void verificar(bool condicion, const char* descripcion) {
    stats.ejecutadas++;
    if (condicion) {
        stats.exitosas++;
        printf("  ✓ %s\n", descripcion);
    } else {
        stats.fallidas++;
        printf("  ✗ %s\n", descripcion);
    }
}

void test_operaciones_basicas() {
    printf("\nPruebas de operaciones básicas:\n");
    verificar(suma(2, 3) == 5, "suma de positivos");
    verificar(suma(-2, -3) == -5, "suma de negativos");
    verificar(suma(0, 0) == 0, "suma de ceros");
}

void imprimir_reporte() {
    printf("\n==== REPORTE DE PRUEBAS ====\n");
    printf("Ejecutadas: %d\n", stats.ejecutadas);
    printf("Exitosas:   %d\n", stats.exitosas);
    printf("Fallidas:   %d\n", stats.fallidas);
    printf("Tasa:       %.1f%%\n", 
           100.0 * stats.exitosas / stats.ejecutadas);
}

int main() {
    test_operaciones_basicas();
    imprimir_reporte();
    return stats.fallidas > 0 ? 1 : 0;
}
```

### Test-Driven Development (TDD)

**TDD** es una metodología donde las pruebas se escriben antes que el código de producción:

1. **Red**: Escribir una prueba que falla
2. **Green**: Escribir el código mínimo para que pase
3. **Refactor**: Mejorar el código manteniendo las pruebas verdes

```c
// Paso 1: Escribir la prueba primero
void test_multiplicar() {
    assert(multiplicar(3, 4) == 12);
    assert(multiplicar(0, 5) == 0);
    assert(multiplicar(-2, 3) == -6);
}

// Paso 2: Implementar la función
int multiplicar(int a, int b) {
    return a * b;
}

// Paso 3: Refactorizar si es necesario
```

:::{tip}
TDD no solo ayuda a escribir código correcto, sino que también guía el diseño. Si una función es difícil de probar, probablemente necesita ser rediseñada.
:::

---

## Contratos

Los **contratos** son especificaciones formales que documentan el comportamiento esperado de una función. Establecen un "acuerdo" entre quien implementa la función y quien la usa, definiendo claramente qué se espera antes de llamarla y qué se garantiza después.

### Filosofía de Diseño por Contrato

El **Design by Contract** (DbC), popularizado por Bertrand Meyer, se basa en la metáfora de contratos legales: cada parte tiene obligaciones y beneficios. En programación:

- El **cliente** (quien llama la función) debe cumplir las precondiciones
- El **proveedor** (la función) debe cumplir las postcondiciones
- Si el cliente cumple su parte, el proveedor garantiza la suya

Esta filosofía ayuda a:
- Clarificar responsabilidades
- Simplificar debugging (¿quién violó el contrato?)
- Mejorar la documentación
- Reducir código defensivo redundante

### Tipos de condiciones

#### Precondición

**Precondiciones** son requisitos que deben cumplirse **antes** de ejecutar la función. Son responsabilidad del código que llama la función.

Ejemplos de precondiciones:
- Parámetros en rangos válidos
- Punteros no nulos
- Archivos abiertos correctamente
- Estado del sistema en condición específica

```c
/*
 * Calcula la raíz cuadrada de un número.
 * PRE: x >= 0
 */
double raiz_cuadrada(double x) {
    assert(x >= 0);  // Verificación en desarrollo
    return sqrt(x);
}
```

#### Postcondición

**Postcondiciones** son garantías que la función promete cumplir **al terminar** su ejecución, siempre que se hayan cumplido las precondiciones.

Ejemplos de postcondiciones:
- Valor de retorno en cierto rango
- Estado del sistema modificado correctamente
- Memoria liberada apropiadamente
- Invariantes preservados

```c
/*
 * Busca un elemento en un array ordenado.
 * PRE: array != NULL, tamanio > 0, array está ordenado
 * POST: 
 *   - Si se encuentra: retorna índice i tal que array[i] == elemento
 *   - Si no se encuentra: retorna -1
 *   - El array no fue modificado
 */
int busqueda_binaria(int* array, int tamanio, int elemento);
```

#### Invariante

**Invariantes** son condiciones que permanecen **siempre verdaderas** durante la ejecución. Existen varios tipos:

**Invariante de lazo**: condición que es verdadera antes y después de cada iteración.

```c
// Calcular suma de elementos
int suma_array(int* array, int n) {
    int suma = 0;
    int i = 0;
    // INVARIANTE: suma contiene la suma de array[0..i-1]
    while (i < n) {
        suma += array[i];
        i++;
        // INVARIANTE se mantiene aquí
    }
    return suma;
}
```

**Invariante de estructura**: propiedad que una estructura de datos mantiene siempre.

```c
typedef struct {
    int* datos;
    int tamanio;
    int capacidad;
} Vector;

// INVARIANTE de Vector:
// - 0 <= tamanio <= capacidad
// - Si tamanio > 0, entonces datos != NULL
// - datos apunta a memoria válida para 'capacidad' elementos
```

### Ejemplo completo de contrato en documentación

```c
/*
 * Suma dos números enteros.
 * 
 * @param termino1: número entero entre -128 y 127
 * @param termino2: número entero entre -128 y 127
 * @returns: suma entre ambos, rango -256 a 254
 * 
 * PRE: -128 <= termino1 <= 127
 *      -128 <= termino2 <= 127
 * POST: resultado == termino1 + termino2
 *       -256 <= resultado <= 254
 */
int suma(int termino1, int termino2);
```

### Contratos más complejos

Para funciones que manejan recursos o estructuras de datos:

```c
/*
 * Agrega un elemento al final de un vector dinámico.
 * 
 * @param vec: puntero a vector válido (no NULL)
 * @param elemento: valor a agregar
 * @returns: true si se agregó exitosamente, false si falló
 * 
 * PRE: vec != NULL
 *      vec->datos != NULL || vec->capacidad == 0
 *      INVARIANTE de Vector se cumple
 * 
 * POST: Si retorna true:
 *         - vec->tamanio aumentó en 1
 *         - vec->datos[vec->tamanio-1] == elemento
 *         - INVARIANTE de Vector se mantiene
 *       Si retorna false:
 *         - vec no fue modificado
 *         - Falló la asignación de memoria
 */
bool vector_agregar(Vector* vec, int elemento);
```

### Verificación de Contratos en Código

Los contratos pueden verificarse en desarrollo usando `assert`:

```c
int suma_positivos(int a, int b) {
    // Verificar precondiciones
    assert(a > 0);
    assert(b > 0);
    
    int resultado = a + b;
    
    // Verificar postcondiciones
    assert(resultado > a);
    assert(resultado > b);
    
    return resultado;
}
```

Para validaciones que deben ejecutarse en producción:

```c
typedef enum {
    OK,
    ERROR_PARAMETRO_INVALIDO,
    ERROR_FUERA_DE_RANGO
} CodigoError;

CodigoError dividir(int dividendo, int divisor, double* resultado) {
    // Validación explícita de precondiciones
    if (resultado == NULL) {
        return ERROR_PARAMETRO_INVALIDO;
    }
    if (divisor == 0) {
        return ERROR_FUERA_DE_RANGO;
    }
    
    // Ejecutar operación
    *resultado = (double)dividendo / divisor;
    
    // Postcondición implícita: resultado contiene valor válido
    return OK;
}
```

### Contratos y Testing

Los contratos guían directamente el diseño de pruebas:

```c
// Función con contrato
/*
 * PRE: array != NULL, n > 0
 * POST: retorna el máximo elemento en array[0..n-1]
 */
int encontrar_maximo(int* array, int n);

// Tests derivados del contrato
void test_encontrar_maximo() {
    // Caso normal
    int arr1[] = {3, 7, 2, 9, 1};
    assert(encontrar_maximo(arr1, 5) == 9);
    
    // Caso con un solo elemento
    int arr2[] = {42};
    assert(encontrar_maximo(arr2, 1) == 42);
    
    // Caso con elementos negativos
    int arr3[] = {-5, -2, -8, -1};
    assert(encontrar_maximo(arr3, 4) == -1);
    
    // Caso con elementos iguales
    int arr4[] = {7, 7, 7, 7};
    assert(encontrar_maximo(arr4, 4) == 7);
}

// Tests de violación de precondiciones (en desarrollo)
void test_encontrar_maximo_precondiciones() {
    int arr[] = {1, 2, 3};
    
    // Estas llamadas violarían precondiciones
    // En desarrollo con assert, terminarían el programa
    // En producción, podrían causar comportamiento indefinido
    
    // encontrar_maximo(NULL, 5);  // ✗ Viola: array != NULL
    // encontrar_maximo(arr, 0);   // ✗ Viola: n > 0
    // encontrar_maximo(arr, -1);  // ✗ Viola: n > 0
}
```

### Contratos en Proyectos Reales

En proyectos grandes, los contratos ayudan a modularizar:

```c
// módulo: lista_enlazada.h

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int longitud;
} Lista;

/*
 * Crea una lista vacía.
 * 
 * PRE: ninguna
 * POST: retorna lista con cabeza == NULL, longitud == 0
 *       INVARIANTE de Lista se establece
 */
Lista* lista_crear();

/*
 * Inserta elemento al inicio de la lista.
 * 
 * PRE: lista != NULL
 *      INVARIANTE de Lista se cumple
 * POST: lista->longitud aumentó en 1
 *       nuevo nodo con 'dato' es la nueva cabeza
 *       INVARIANTE de Lista se mantiene
 */
void lista_insertar_inicio(Lista* lista, int dato);

/*
 * Destruye la lista liberando toda la memoria.
 * 
 * PRE: lista != NULL
 * POST: toda la memoria de la lista fue liberada
 *       lista queda inválida (debe asignarse NULL en el código cliente)
 */
void lista_destruir(Lista* lista);

// INVARIANTE de Lista:
// 1. longitud >= 0
// 2. Si longitud == 0, entonces cabeza == NULL
// 3. Si longitud > 0, entonces cabeza != NULL
// 4. El número de nodos alcanzables desde cabeza == longitud
```

:::{note}
Los contratos son especialmente valiosos en interfaces públicas de bibliotecas, donde múltiples desarrolladores usarán las funciones sin conocer su implementación interna.
:::

---

## Valores especiales y documentación

Una práctica común en C es usar **valores especiales** para indicar condiciones de error o estados particulares. Esta práctica requiere documentación clara para evitar malentendidos.

### Valores de Retorno Especiales

#### Códigos de Error Numéricos

```c
/*
 * Busca un elemento en un array.
 * 
 * @returns: índice del elemento (0..n-1) si se encuentra
 *           -1 si no se encuentra
 *           -2 si los parámetros son inválidos
 * 
 * PRE: Si array != NULL, entonces n >= 0
 * POST: Si retorna i >= 0, entonces array[i] == elemento
 *       Si retorna -1, el elemento no está en array
 *       Si retorna -2, array == NULL o n < 0
 */
int buscar(int* array, int n, int elemento) {
    if (array == NULL || n < 0) {
        return -2;
    }
    
    for (int i = 0; i < n; i++) {
        if (array[i] == elemento) {
            return i;
        }
    }
    
    return -1;
}
```

#### Punteros NULL como Indicadores

```c
/*
 * Crea un nodo con el dato especificado.
 * 
 * @returns: puntero al nuevo nodo, o NULL si falla la asignación
 * 
 * PRE: ninguna
 * POST: Si retorna != NULL:
 *         - el nodo tiene nodo->dato == dato
 *         - nodo->siguiente == NULL
 *       Si retorna NULL:
 *         - falló malloc
 */
Nodo* nodo_crear(int dato) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        return NULL;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Uso correcto: verificar retorno
Nodo* nodo = nodo_crear(42);
if (nodo == NULL) {
    fprintf(stderr, "Error: no se pudo crear nodo\n");
    return ERROR_MEMORIA;
}
```

#### Caracteres Especiales

```c
/*
 * Lee el siguiente carácter del archivo.
 * 
 * @returns: carácter leído (0-255), o
 *           EOF (-1) si se alcanzó fin de archivo o hubo error
 * 
 * PRE: archivo != NULL, archivo está abierto para lectura
 * POST: Si retorna != EOF, es un carácter válido
 *       Si retorna EOF, verificar con feof() y ferror()
 */
int leer_caracter(FILE* archivo);
```

### Enumeraciones para Mayor Claridad

Las enumeraciones hacen el código más expresivo y mantenible:

```c
typedef enum {
    EXITO = 0,
    ERROR_ARCHIVO_NO_EXISTE = 1,
    ERROR_PERMISO_DENEGADO = 2,
    ERROR_MEMORIA_INSUFICIENTE = 3,
    ERROR_FORMATO_INVALIDO = 4
} CodigoResultado;

/*
 * Carga datos desde un archivo.
 * 
 * @returns: EXITO si la operación fue exitosa
 *           Código de error específico si falló
 * 
 * PRE: ruta != NULL
 * POST: Si retorna EXITO, *datos contiene la información cargada
 *       Si retorna error, *datos no fue modificado
 */
CodigoResultado cargar_desde_archivo(const char* ruta, Datos* datos);

// Uso
Datos datos;
CodigoResultado resultado = cargar_desde_archivo("config.txt", &datos);

if (resultado != EXITO) {
    switch (resultado) {
        case ERROR_ARCHIVO_NO_EXISTE:
            fprintf(stderr, "El archivo no existe\n");
            break;
        case ERROR_PERMISO_DENEGADO:
            fprintf(stderr, "Permisos insuficientes\n");
            break;
        case ERROR_MEMORIA_INSUFICIENTE:
            fprintf(stderr, "Memoria insuficiente\n");
            break;
        default:
            fprintf(stderr, "Error desconocido\n");
    }
    return 1;
}
```

### Valores Centinela

Los **valores centinela** marcan el final de una secuencia:

```c
// Strings en C: centinela '\0'
char nombre[] = "Hola";  // Internamente: {'H','o','l','a','\0'}

// Array terminado en centinela
int numeros[] = {1, 2, 3, 4, 5, -1};  // -1 marca el final

/*
 * Suma elementos hasta encontrar el centinela.
 * 
 * PRE: array contiene -1 como último elemento
 * POST: retorna suma de todos los elementos antes del -1
 */
int sumar_hasta_centinela(int* array) {
    int suma = 0;
    int i = 0;
    
    while (array[i] != -1) {
        suma += array[i];
        i++;
    }
    
    return suma;
}
```

### Documentación de Invariantes Internas

Las invariantes internas ayudan a razonar sobre el código:

```c
typedef struct {
    int* buffer;
    int capacidad;
    int inicio;
    int final;
    int cantidad;
} ColaCircular;

/*
 * INVARIANTES de ColaCircular:
 * 
 * 1. 0 <= cantidad <= capacidad
 * 2. 0 <= inicio < capacidad
 * 3. 0 <= final < capacidad
 * 4. Si cantidad == 0, la cola está vacía
 * 5. Si cantidad == capacidad, la cola está llena
 * 6. Los elementos válidos están en las posiciones
 *    (inicio + i) % capacidad para i en [0, cantidad)
 */

/*
 * Agrega un elemento a la cola.
 * 
 * PRE: cola != NULL
 *      INVARIANTES se cumplen
 *      cantidad < capacidad (hay espacio)
 * POST: elemento agregado en posición 'final'
 *       cantidad aumentó en 1
 *       final avanzó (con wrap-around)
 *       INVARIANTES se mantienen
 */
void cola_encolar(ColaCircular* cola, int elemento) {
    assert(cola != NULL);
    assert(cola->cantidad < cola->capacidad);
    
    // Preservar invariantes
    cola->buffer[cola->final] = elemento;
    cola->final = (cola->final + 1) % cola->capacidad;
    cola->cantidad++;
    
    // Verificar que las invariantes siguen cumpliéndose
    assert(cola->cantidad <= cola->capacidad);
    assert(cola->inicio >= 0 && cola->inicio < cola->capacidad);
    assert(cola->final >= 0 && cola->final < cola->capacidad);
}
```

### Documentación de Rangos Válidos

Especificar claramente los rangos válidos previene errores:

```c
/*
 * Establece el brillo de un LED.
 * 
 * @param brillo: intensidad entre 0 (apagado) y 255 (máximo)
 * 
 * PRE: 0 <= brillo <= 255
 * POST: LED configurado con el brillo especificado
 * 
 * NOTA: Valores fuera de rango se ajustan automáticamente:
 *       brillo < 0 se trata como 0
 *       brillo > 255 se trata como 255
 */
void led_set_brillo(int brillo) {
    if (brillo < 0) brillo = 0;
    if (brillo > 255) brillo = 255;
    
    // Configurar hardware
    PWM_DUTY = brillo;
}

/*
 * Alternativa: sin ajuste automático
 * 
 * @returns: true si se configuró exitosamente
 *           false si brillo está fuera de rango
 * 
 * PRE: ninguna
 * POST: Si retorna true, LED configurado con brillo especificado
 *       Si retorna false, LED no fue modificado
 */
bool led_set_brillo_estricto(int brillo) {
    if (brillo < 0 || brillo > 255) {
        return false;
    }
    
    PWM_DUTY = brillo;
    return true;
}
```

### Testing de Valores Especiales

Los valores especiales deben probarse explícitamente:

```c
void test_buscar_valores_especiales() {
    int array[] = {10, 20, 30, 40, 50};
    
    // Casos de éxito
    assert(buscar(array, 5, 30) == 2);
    
    // Caso de elemento no encontrado
    assert(buscar(array, 5, 100) == -1);
    
    // Casos de parámetros inválidos
    assert(buscar(NULL, 5, 30) == -2);
    assert(buscar(array, -1, 30) == -2);
    
    // Casos límite
    assert(buscar(array, 0, 10) == -1);  // Array "vacío"
    assert(buscar(array, 1, 10) == 0);   // Un solo elemento
}

void test_valores_centinela() {
    int numeros[] = {5, 10, 15, -1};
    assert(sumar_hasta_centinela(numeros) == 30);
    
    int vacio[] = {-1};
    assert(sumar_hasta_centinela(vacio) == 0);
}
```

---

## Mejores Prácticas de Testing

### 1. Tests Independientes

Cada test debe ser independiente de los demás:

```c
// ✗ MAL: tests dependientes
int contador_global = 0;

void test_incremento_1() {
    contador_global++;
    assert(contador_global == 1);
}

void test_incremento_2() {
    contador_global++;
    assert(contador_global == 2);  // ¡Depende del test anterior!
}

// ✓ BIEN: tests independientes
void test_incremento_desde_cero() {
    int contador = 0;
    contador++;
    assert(contador == 1);
}

void test_incremento_desde_diez() {
    int contador = 10;
    contador++;
    assert(contador == 11);
}
```

### 2. Nombres Descriptivos

Los nombres deben describir qué se prueba y bajo qué condiciones:

```c
// ✗ MAL: nombres ambiguos
void test1() { ... }
void test_suma() { ... }

// ✓ BIEN: nombres descriptivos
void test_suma_dos_numeros_positivos() { ... }
void test_suma_con_overflow() { ... }
void test_suma_numeros_negativos() { ... }
```

### 3. Un Concepto por Test

Cada test debe verificar un solo aspecto:

```c
// ✗ MAL: test sobrecargado
void test_lista() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    lista_insertar(lista, 2);
    assert(lista_tamanio(lista) == 2);
    assert(lista_esta_vacia(lista) == false);
    lista_eliminar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    lista_destruir(lista);
}

// ✓ BIEN: tests específicos
void test_lista_insertar_aumenta_tamanio() {
    Lista* lista = lista_crear();
    assert(lista_tamanio(lista) == 0);
    
    lista_insertar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    
    lista_insertar(lista, 2);
    assert(lista_tamanio(lista) == 2);
    
    lista_destruir(lista);
}

void test_lista_con_elementos_no_esta_vacia() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    
    assert(lista_esta_vacia(lista) == false);
    
    lista_destruir(lista);
}

void test_lista_eliminar_reduce_tamanio() {
    Lista* lista = lista_crear();
    lista_insertar(lista, 1);
    lista_insertar(lista, 2);
    
    lista_eliminar(lista, 1);
    assert(lista_tamanio(lista) == 1);
    
    lista_destruir(lista);
}
```

### 4. Evitar Lógica Compleja en Tests

Los tests deben ser simples y obvios:

```c
// ✗ MAL: lógica en el test
void test_suma_complejo() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            assert(suma(i, i) == i * 2);
        } else {
            assert(suma(i, i + 1) == i * 2 + 1);
        }
    }
}

// ✓ BIEN: casos explícitos
void test_suma_numeros_pares() {
    assert(suma(0, 0) == 0);
    assert(suma(2, 2) == 4);
    assert(suma(4, 4) == 8);
}

void test_suma_numeros_impares() {
    assert(suma(1, 2) == 3);
    assert(suma(3, 4) == 7);
    assert(suma(5, 6) == 11);
}
```

### 5. Usar Funciones Auxiliares para Setup

Cuando varios tests necesitan la misma preparación:

```c
// Función auxiliar para crear configuración común
Lista* crear_lista_con_elementos(int n) {
    Lista* lista = lista_crear();
    for (int i = 0; i < n; i++) {
        lista_insertar(lista, i * 10);
    }
    return lista;
}

void test_lista_obtener_primero() {
    Lista* lista = crear_lista_con_elementos(5);
    assert(lista_obtener(lista, 0) == 0);
    lista_destruir(lista);
}

void test_lista_obtener_ultimo() {
    Lista* lista = crear_lista_con_elementos(5);
    assert(lista_obtener(lista, 4) == 40);
    lista_destruir(lista);
}
```

---

## Integración de Testing en el Flujo de Trabajo

### Makefile con Tests

```makefile
# Compilación del proyecto
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = src/calculadora.c src/utilidades.c
TESTS = tests/test_calculadora.c tests/test_utilidades.c

# Targets principales
all: programa

programa: src/main.c $(SRC)
	$(CC) $(CFLAGS) -o programa src/main.c $(SRC)

# Target para tests
test: test_calculadora test_utilidades
	@echo "=== Ejecutando todas las pruebas ==="
	./test_calculadora
	./test_utilidades
	@echo "=== Todas las pruebas completadas ==="

test_calculadora: tests/test_calculadora.c src/calculadora.c
	$(CC) $(CFLAGS) -o test_calculadora tests/test_calculadora.c src/calculadora.c

test_utilidades: tests/test_utilidades.c src/utilidades.c
	$(CC) $(CFLAGS) -o test_utilidades tests/test_utilidades.c src/utilidades.c

# Limpieza
clean:
	rm -f programa test_calculadora test_utilidades *.o

# Test + programa
build-all: programa test

.PHONY: all test clean build-all
```

### Flujo de Desarrollo Recomendado

1. **Escribir/modificar código**
2. **Ejecutar tests**: `make test`
3. **Si fallan**: corregir y volver al paso 2
4. **Si pasan**: compilar programa completo: `make all`
5. **Commit**: guardar cambios con git

```bash
# Flujo típico
$ make test           # Verificar que no rompimos nada
$ # ... hacer cambios ...
$ make test           # Probar cambios
$ make all            # Compilar programa
$ git add .
$ git commit -m "Implementada función X con tests"
```

---

## Conclusión

El testing y los contratos son herramientas fundamentales del desarrollo de software profesional. Estos conceptos no son "extras opcionales", sino prácticas estándar que todo programador debe dominar.

### Conceptos Clave

- **Testing** valida que el código funciona correctamente bajo diversas condiciones
- **Contratos** documentan formalmente las expectativas de cada función
- **Precondiciones** definen qué debe ser cierto antes de llamar una función
- **Postcondiciones** garantizan qué será cierto después de la ejecución
- **Invariantes** son propiedades que siempre se mantienen
- **Valores especiales** requieren documentación clara y testing explícito

### Beneficios de Estas Prácticas

1. **Código más robusto**: Los errores se detectan temprano
2. **Mejor diseño**: Pensar en tests mejora la estructura del código
3. **Documentación viva**: Los contratos y tests documentan el uso correcto
4. **Refactorización segura**: Los tests permiten cambiar código con confianza
5. **Debugging más fácil**: Las fallas están localizadas y son reproducibles
6. **Colaboración efectiva**: Los contratos clarifican responsabilidades

:::{important}
En la industria del software, el testing no es negociable. Proyectos sin tests son considerados "código legacy" incluso si fueron escritos ayer. Las empresas esperan que los desarrolladores sepan escribir y mantener tests como parte natural de su trabajo.
:::

### Aplicación en Trabajos Prácticos

Estos conceptos se aplicarán directamente en los trabajos prácticos del curso:

- **TP3 y siguientes**: se esperan funciones con contratos documentados
- **Evaluación**: incluye la calidad y completitud de las pruebas
- **Código profesional**: seguir estas prácticas es parte de la nota conceptual

:::{tip}
No esperes a que te pidan tests. Escríbelos desde el principio. Es más fácil mantener tests existentes que agregar testing a código ya escrito. Además, los tests te ayudarán a ti mismo durante el desarrollo.
:::

---

## Recursos Adicionales

Para profundizar en testing y contratos:

- **Frameworks de testing en C**: Check, Unity, CUnit, MinUnit
- **Herramientas de análisis**: Valgrind (memoria), GDB (debugging), gcov (cobertura)
- **Metodologías**: TDD (Test-Driven Development), BDD (Behavior-Driven Development)
- **Verificación formal**: Para sistemas críticos, existen herramientas como Frama-C que pueden verificar formalmente contratos en C

### Próximos Pasos

1. Practicar escribiendo tests para funciones simples
2. Documentar contratos en las funciones que escribas
3. Ejecutar tests regularmente durante el desarrollo
4. Analizar la cobertura de tus tests
5. Refactorizar con confianza apoyándote en los tests
