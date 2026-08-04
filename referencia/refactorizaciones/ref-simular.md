---
title: "Técnicas de Simulación de Estructuras de Control"
short_title: "Estructuras de control"
subtitle: "Alternativas y patrones para simular comportamientos de lazos"
---

## Introducción

En ciertas situaciones de programación, podés encontrarte con la necesidad de
simular comportamientos de estructuras de control que no están disponibles en el
lenguaje que estás usando, o que querés evitar por razones de estilo o
compatibilidad. Este apunte explora técnicas para simular diversas estructuras
de control usando construcciones más básicas, con especial énfasis en la
simulación de `do...while` usando `while` y otras alternativas.

La comprensión de estas técnicas no solo es útil para casos específicos donde
las estructuras originales no están disponibles, sino que también proporciona
una comprensión más profunda de cómo funcionan internamente los lazos y las
estructuras de control.

:::{important} Filosofía de diseñ o Aunque estas técnicas son valiosas de

conocer, siempre preferí usar las estructuras de control nativas cuando estén
disponibles. La simulación debe ser una herramienta de último recurso o para
casos muy específicos donde aporta claridad al código ({ref}`0x0000h`).

:::
<!-- {important} Filosofía de diseñ o Aunque estas técnicas son valiosas de -->

## Simulación de `do...while` con `while`

### Método 1: lazo Infinito con `break`

La técnica más directa para simular un `do...while` es usar un lazo `while(1)`
con una condición de salida explícita:

:::{code-block}c
:caption: Simulación básica de do...while
:linenos:

// Comportamiento deseado (do...while):
// do {
//     // código del lazo
// } while (condicion);

// Simulación equivalente:
while (1) {
    // código del lazo

    if (!condicion) {
        break;
    }
}

:::
<!-- {code-block}c -->

### Ejemplo Práctico: Validación de Entrada

:::{code-block}c
:caption: Validación de entrada con simulación de do...while
:linenos:

#include <stdio.h>
#include <stdbool.h>

int main() {
    int clave;
    bool clave_valida = false;

    printf("=== Sistema de Autenticación ===\n");

    while (1) {
        printf("Ingresá la clave (123): ");
        scanf("%d", &clave);

        if (clave == 123) {
            clave_valida = true;
            break;
        } else {
            printf("Clave incorrecta. Intentá nuevamente.\n");
        }
    }

    printf("Acceso concedido.\n");
    return 0;
}

:::
<!-- {code-block}c -->

### Método 2: Variable de Control Booleana

Una alternativa más explícita es usar una variable booleana para controlar la
continuación del lazo:

:::{code-block}c
:caption: Simulación con variable de control
:linenos:

#include <stdbool.h>

int validar_entrada() {
    bool continuar = true;
    int numero;

    while (continuar) {
        printf("Ingresá un número entre 1 y 10: ");
        scanf("%d", &numero);

        if (numero >= 1 && numero <= 10) {
            printf("Número válido: %d\n", numero);
            continuar = false;  // Salir del lazo
        } else {
            printf("Número fuera de rango. Intentá nuevamente.\n");
        }
    }

    return numero;
}

:::
<!-- {code-block}c -->

### Método 3: Función con Retorno Temprano

Para casos más complejos, podés encapsular la lógica en una función y usar
`return` para salir:

:::{code-block}c
:caption: Simulación con función y return
:linenos:

#include <stdio.h>
#include <string.h>

void procesar_comandos() {
    char comando[50];

    printf("Intérprete de comandos (escribí 'salir' para terminar)\n");

    while (1) {
        printf(">>> ");
        fgets(comando, sizeof(comando), stdin);

        // Remover salto de línea
        comando[strcspn(comando, "\n")] = 0;

        if (strcmp(comando, "salir") == 0) {
            printf("¡Hasta luego!\n");
            return;
        }

        if (strcmp(comando, "ayuda") == 0) {
            printf("Comandos disponibles: ayuda, version, salir\n");
        } else if (strcmp(comando, "version") == 0) {
            printf("Intérprete v1.0\n");
        } else if (strlen(comando) > 0) {
            printf("Comando desconocido: '%s'\n", comando);
        }
    }
}

:::
<!-- {code-block}c -->

## Simulación de Otras Estructuras de Control

### Simulación de `for` con `while`

En algunos contextos educativos o de depuración, puede ser útil convertir lazos
`for` a `while`:

:::{code-block}c
:caption: Conversión de for a while
:linenos:

// lazo for original:
// for (int i = 0; i < n; i++) {
//     // código del lazo
// }

// Simulación equivalente con while:
{
    int i = 0;                  // Inicialización
    while (i < n) {            // Condición
        // código del lazo
        i++;                   // Incremento
    }
}

:::
<!-- {code-block}c -->

### Simulación de `switch` con `if-else`

Para casos donde `switch` no está disponible o es preferible evitarlo:

:::{code-block}c
:caption: Simulación de switch con if-else encadenados
:linenos:

typedef enum {
    OPCION_NUEVA_PARTIDA,
    OPCION_CARGAR_PARTIDA,
    OPCION_CONFIGURACION,
    OPCION_SALIR
} opcion_menu_t;

void procesar_opcion_menu(opcion_menu_t opcion) {
    if (opcion == OPCION_NUEVA_PARTIDA) {
        printf("Iniciando nueva partida...\n");
    } else if (opcion == OPCION_CARGAR_PARTIDA) {
        printf("Cargando partida guardada...\n");
    } else if (opcion == OPCION_CONFIGURACION) {
        printf("Abriendo configuración...\n");
    } else if (opcion == OPCION_SALIR) {
        printf("Saliendo del juego...\n");
    } else {
        printf("Opción inválida: %d\n", opcion);
    }
}

:::
<!-- {code-block}c -->

## Patrones Avanzados de Simulación

### Máquina de Estados sin `switch`

Para sistemas complejos que requieren máquinas de estado:

:::{code-block}c
:caption: Máquina de estados con tabla de funciones
:linenos:

#include <stdio.h>

typedef enum {
    ESTADO_MENU,
    ESTADO_JUGANDO,
    ESTADO_PAUSA,
    ESTADO_GAME_OVER,
    ESTADO_SALIR,
    ESTADO_MAX
} estado_juego_t;

typedef struct {
    estado_juego_t estado_actual;
    int puntuacion;
    int vidas;
} contexto_juego_t;

// Prototipos de funciones de estado
void manejar_estado_menu(contexto_juego_t *ctx);
void manejar_estado_jugando(contexto_juego_t *ctx);
void manejar_estado_pausa(contexto_juego_t *ctx);
void manejar_estado_game_over(contexto_juego_t *ctx);

// Tabla de funciones para simular switch
typedef void (*funcion_estado_t)(contexto_juego_t *);

static funcion_estado_t tabla_estados[ESTADO_MAX] = {
    [ESTADO_MENU] = manejar_estado_menu,
    [ESTADO_JUGANDO] = manejar_estado_jugando,
    [ESTADO_PAUSA] = manejar_estado_pausa,
    [ESTADO_GAME_OVER] = manejar_estado_game_over
};

void ejecutar_maquina_estados(contexto_juego_t *ctx) {
    while (ctx->estado_actual != ESTADO_SALIR) {
        if (ctx->estado_actual < ESTADO_MAX &&
        tabla_estados[ctx->estado_actual]) {
            tabla_estados[ctx->estado_actual](ctx);
        } else {
            fprintf(stderr, "Estado inválido: %d\n", ctx->estado_actual);
            ctx->estado_actual = ESTADO_SALIR;
        }
    }
}

void manejar_estado_menu(contexto_juego_t *ctx) {
    printf("=== MENÚ PRINCIPAL ===\n");
    printf("1. Jugar\n2. Salir\n");

    int opcion;
    printf("Selecciona opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        ctx->estado_actual = ESTADO_JUGANDO;
        ctx->puntuacion = 0;
        ctx->vidas = 3;
    } else if (opcion == 2) {
        ctx->estado_actual = ESTADO_SALIR;
    }
}

void manejar_estado_jugando(contexto_juego_t *ctx) {
    printf("Jugando... Puntuación: %d, Vidas: %d\n",
           ctx->puntuacion, ctx->vidas);

    // Simular eventos del juego
    ctx->puntuacion += 10;

    if (ctx->puntuacion >= 100) {
        printf("¡Ganaste!\n");
        ctx->estado_actual = ESTADO_GAME_OVER;
    } else {
        // Continuar jugando o ir a menú
        printf("Presiona 1 para continuar, 2 para ir al menú: ");
        int opcion;
        scanf("%d", &opcion);

        if (opcion == 2) {
            ctx->estado_actual = ESTADO_MENU;
        }
    }
}

void manejar_estado_pausa(contexto_juego_t *ctx) {
    printf("Juego en pausa. Presiona cualquier tecla para continuar...\n");
    getchar();
    ctx->estado_actual = ESTADO_JUGANDO;
}

void manejar_estado_game_over(contexto_juego_t *ctx) {
    printf("=== GAME OVER ===\n");
    printf("Puntuación final: %d\n", ctx->puntuacion);
    ctx->estado_actual = ESTADO_MENU;
}

:::
<!-- {code-block}c -->

### Simulación de lazos Anidados con Funciones

Para evitar lazos anidados complejos que violan la regla de claridad:

:::{code-block}c
:caption: Desensamblado de lazos anidados
:linenos:

#include <stdbool.h>

#define FILAS 3
#define COLUMNAS 4

// En lugar de lazos anidados complejos:
void procesar_matriz_compleja_anidado(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > 0) {
                for (int k = 0; k < matriz[i][j]; k++) {
                    // Lógica compleja aquí...
                    printf("Procesando elemento [%d][%d], iteración %d\n", i, j,
                    k);
                }
            }
        }
    }
}

// Simulación con funciones separadas:
void procesar_elemento(int fila, int columna, int valor) {
    if (valor <= 0) return;

    for (int k = 0; k < valor; k++) {
        printf("Procesando elemento [%d][%d], iteración %d\n", fila, columna,
        k);
    }
}

void procesar_fila(int matriz[COLUMNAS], int fila) {
    for (int j = 0; j < COLUMNAS; j++) {
        procesar_elemento(fila, j, matriz[j]);
    }
}

void procesar_matriz_compleja_funcional(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        procesar_fila(matriz[i], i);
    }
}

:::
<!-- {code-block}c -->

## Técnicas para Evitar `goto`

Aunque `goto` puede ser útil en casos específicos, su uso puede complicar el
flujo del programa:

### Método 1: Funciones de Limpieza

:::{code-block}c
:caption: Evitar goto con funciones de limpieza
:linenos:

#include <stdio.h>
#include <stdlib.h>

// Problemático con goto:
// int procesar_archivo_con_goto(const char *nombre) {
//     FILE *archivo = NULL;
//     char *buffer = NULL;
//     int resultado = -1;
//
//     archivo = fopen(nombre, "r");
//     if (!archivo) goto cleanup;
//
//     buffer = malloc(1024);
//     if (!buffer) goto cleanup;
//
//     // Procesar archivo...
//     resultado = 0;
//
// cleanup:
//     if (buffer) free(buffer);
//     if (archivo) fclose(archivo);
//     return resultado;
// }

// Alternativa sin goto:
typedef struct {
    FILE *archivo;
    char *buffer;
    int resultado;
} recursos_t;

void limpiar_recursos(recursos_t *recursos) {
    if (recursos->buffer) {
        free(recursos->buffer);
        recursos->buffer = NULL;
    }

    if (recursos->archivo) {
        fclose(recursos->archivo);
        recursos->archivo = NULL;
    }
}

int procesar_archivo_sin_goto(const char *nombre) {
    recursos_t recursos = {0};

    recursos.archivo = fopen(nombre, "r");
    if (!recursos.archivo) {
        limpiar_recursos(&recursos);
        return -1;
    }

    recursos.buffer = malloc(1024);
    if (!recursos.buffer) {
        limpiar_recursos(&recursos);
        return -1;
    }

    // Procesar archivo...
    printf("Procesando archivo: %s\n", nombre);
    recursos.resultado = 0;

    limpiar_recursos(&recursos);
    return recursos.resultado;
}

:::
<!-- {code-block}c -->

### Método 2: Banderas de Estado

:::{code-block}c
:caption: Uso de banderas en lugar de goto
:linenos:

#include <stdbool.h>

int procesar_datos_complejos() {
    bool error_ocurrido = false;
    int resultado = 0;

    // Paso 1
    if (!error_ocurrido) {
        printf("Ejecutando paso 1...\n");
        if (/* condición de error */) {
            error_ocurrido = true;
            resultado = -1;
        }
    }

    // Paso 2
    if (!error_ocurrido) {
        printf("Ejecutando paso 2...\n");
        if (/* otra condición de error */) {
            error_ocurrido = true;
            resultado = -2;
        }
    }

    // Paso 3
    if (!error_ocurrido) {
        printf("Ejecutando paso 3...\n");
        // Lógica final
        resultado = 1; // éxito
    }

    if (error_ocurrido) {
        printf("Error durante el procesamiento: código %d\n", resultado);
    } else {
        printf("Procesamiento completado exitosamente.\n");
    }

    return resultado;
}

:::
<!-- {code-block}c -->

## Consideraciones de Rendimiento

### Impacto en la Optimización del Compilador

Las simulaciones pueden afectar las optimizaciones automáticas del compilador:

:::{code-block}c
:caption: Consideraciones de rendimiento
:linenos:

#include <stdio.h>

// Versión optimizable (compilador puede desenrollar el lazo)
void lazo_simple_optimizable(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
}

// Versión menos optimizable (lógica más compleja para el compilador)
void lazo_simulado_complejo(int n) {
    int i = 0;
    bool continuar = true;

    while (continuar) {
        printf("%d ", i);
        i++;

        if (i >= n) {
            continuar = false;
        }
    }
}

// Versión equilibrada (clara para humanos, optimizable para compilador)
void lazo_simulado_optimizable(int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", i);
        i++;
    }
}

:::
<!-- {code-block}c -->

### Medición de Rendimiento

:::{code-block}c
:caption: Comparación de rendimiento entre técnicas
:linenos:

#include <time.h>

void benchmark_lazos(int iteraciones) {
    clock_t inicio, fin;

    // Benchmark lazo for nativo
    inicio = clock();
    for (int i = 0; i < iteraciones; i++) {
        // Operación trivial para evitar optimización completa
        volatile int temp = i * 2;
    }
    fin = clock();

    double tiempo_for = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    // Benchmark simulación while
    inicio = clock();
    int i = 0;
    while (i < iteraciones) {
        volatile int temp = i * 2;
        i++;
    }
    fin = clock();

    double tiempo_while = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Rendimiento para %d iteraciones:\n", iteraciones);
    printf("  lazo for:     %.6f segundos\n", tiempo_for);
    printf("  Simulación while: %.6f segundos\n", tiempo_while);
    printf("  Diferencia:    %.2f%%\n",
           ((tiempo_while - tiempo_for) / tiempo_for) * 100);
}

:::
<!-- {code-block}c -->

## Mejores Prácticas para Simulación

### 1. Prioridad de Claridad

Siempre preferí la construcción más clara y natural del lenguaje:

:::{code-block}c
:caption: Priorizar claridad sobre simulación
:linenos:

// Innecesariamente complejo
void ejemplo_malo() {
    int i = 0;
    while (1) {
        if (i >= 10) break;
        printf("%d\n", i);
        i++;
    }
}

// Claro y directo
void ejemplo_bueno() {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}

:::
<!-- {code-block}c -->

### 2. Documentación de Intención

Cuando uses simulación, documentá el porqué:

:::{code-block}c
:caption: Documentación de intención en simulaciones
:linenos:

/**
 * Simula comportamiento do...while para mantener compatibilidad
 * con compiladores que no soportan C99.
 *
 * Comportamiento equivalente:
 * do {
 *     procesar_entrada(&entrada);
 * } while (!entrada.es_valida);
 */
void validar_entrada_compatible() {
    entrada_t entrada;

    while (1) {
        procesar_entrada(&entrada);

        if (entrada.es_valida) {
            break;
        }
    }
}

:::
<!-- {code-block}c -->

### 3. Pruebas de Equivalencia

Verificá que la simulación sea equivalente al comportamiento original:

:::{code-block}c
:caption: Verificación de equivalencia
:linenos:

void test_equivalencia_do_while() {
    int contador_original = 0;
    int contador_simulado = 0;

    // Comportamiento original (do...while)
    int i = 0;
    do {
        contador_original++;
        i++;
    } while (i < 5);

    // Simulación
    i = 0;
    while (1) {
        contador_simulado++;
        i++;

        if (!(i < 5)) {
            break;
        }
    }

    // Verificar equivalencia
    assert(contador_original == contador_simulado);
    printf("Simulación verificada: %d == %d iteraciones\n",
           contador_original, contador_simulado);
}

:::
<!-- {code-block}c -->

## Casos de Uso Específicos

### 1. Menús Interactivos

:::{code-block}c
:caption: Menú interactivo robusto
:linenos:

typedef enum {
    MENU_OPCION_NUEVA_TAREA = 1,
    MENU_OPCION_LISTAR_TAREAS,
    MENU_OPCION_COMPLETAR_TAREA,
    MENU_OPCION_SALIR
} opcion_menu_t;

void mostrar_menu() {
    printf("\n=== GESTOR DE TAREAS ===\n");
    printf("1. Nueva tarea\n");
    printf("2. Listar tareas\n");
    printf("3. Completar tarea\n");
    printf("4. Salir\n");
    printf("Selecciona opción: ");
}

void ejecutar_menu_principal() {
    int opcion;
    bool salir = false;

    while (!salir) {
        mostrar_menu();

        if (scanf("%d", &opcion) != 1) {
            // Limpiar buffer en caso de entrada inválida
            while (getchar() != '\n');
            printf("Entrada inválida. Usa números del 1 al 4.\n");
            continue;
        }

        if (opcion == MENU_OPCION_NUEVA_TAREA) {
            printf("Creando nueva tarea...\n");
        } else if (opcion == MENU_OPCION_LISTAR_TAREAS) {
            printf("Listando tareas...\n");
        } else if (opcion == MENU_OPCION_COMPLETAR_TAREA) {
            printf("Completando tarea...\n");
        } else if (opcion == MENU_OPCION_SALIR) {
            printf("¡Hasta luego!\n");
            salir = true;
        } else {
            printf("Opción inválida: %d\n", opcion);
        }
    }
}

:::
<!-- {code-block}c -->

### 2. Procesamiento de Archivos con Manejo de Errores

:::{code-block}c
:caption: Procesamiento robusto de archivos
:linenos:

#include <errno.h>
#include <string.h>

typedef enum {
    RESULTADO_EXITO,
    RESULTADO_ERROR_APERTURA,
    RESULTADO_ERROR_LECTURA,
    RESULTADO_ERROR_PROCESAMIENTO
} resultado_procesamiento_t;

resultado_procesamiento_t procesar_archivo_robusto(const char *ruta) {
    FILE *archivo = NULL;
    char linea[256];
    int linea_numero = 0;
    bool error_encontrado = false;
    resultado_procesamiento_t resultado = RESULTADO_EXITO;

    // Intentar abrir archivo
    archivo = fopen(ruta, "r");
    if (!archivo) {
        printf("Error abriendo '%s': %s\n", ruta, strerror(errno));
        return RESULTADO_ERROR_APERTURA;
    }

    printf("📖 Procesando archivo: %s\n", ruta);

    // Simular do...while para procesar líneas
    while (1) {
        if (!fgets(linea, sizeof(linea), archivo)) {
            if (feof(archivo)) {
                break; // Fin de archivo normal
            } else {
                printf("Error leyendo línea %d: %s\n",
                       linea_numero + 1, strerror(errno));
                resultado = RESULTADO_ERROR_LECTURA;
                error_encontrado = true;
                break;
            }
        }

        linea_numero++;

        // Simular procesamiento de línea
        if (strlen(linea) == 0) {
            continue; // Saltar líneas vacías
        }

        // Remover salto de línea
        linea[strcspn(linea, "\n")] = 0;

        printf("  Línea %d: %s\n", linea_numero, linea);

        // Simular condición de error en procesamiento
        if (strstr(linea, "ERROR") != NULL) {
            printf("Error en contenido, línea %d: %s\n",
                   linea_numero, linea);
            resultado = RESULTADO_ERROR_PROCESAMIENTO;
            error_encontrado = true;
            break;
        }
    }

    fclose(archivo);

    if (!error_encontrado) {
        printf("Archivo procesado exitosamente: %d líneas\n", linea_numero);
    }

    return resultado;
}

:::
<!-- {code-block}c -->

## Ejercicios

:::{exercise}
:label: simular_menu_calculadora
:enumerator: simulacion-1

Implementá una calculadora simple que use simulación de `do...while` para
mostrar un menú repetitivo. La calculadora debe soportar operaciones básicas (+,
-, *, /) y continuar ejecutándose hasta que el usuario elija salir. Incluí
validación de entrada y manejo de errores (como división por cero).

:::
<!-- {exercise} -->

::::{solution} simular_menu_calculadora
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    OPERACION_SUMA = 1,
    OPERACION_RESTA,
    OPERACION_MULTIPLICACION,
    OPERACION_DIVISION,
    OPERACION_SALIR
} operacion_t;

void mostrar_menu_calculadora() {
    printf("\n=== CALCULADORA SIMPLE ===\n");
    printf("1. Suma (+)\n");
    printf("2. Resta (-)\n");
    printf("3. Multiplicación (*)\n");
    printf("4. División (/)\n");
    printf("5. Salir\n");
    printf("Selecciona operación: ");
}

bool obtener_numeros(double *a, double *b) {
    printf("Ingresa el primer número: ");
    if (scanf("%lf", a) != 1) {
        printf("Entrada inválida para el primer número\n");
        while (getchar() != '\n'); // Limpiar buffer
        return false;
    }

    printf("Ingresa el segundo número: ");
    if (scanf("%lf", b) != 1) {
        printf("Entrada inválida para el segundo número\n");
        while (getchar() != '\n'); // Limpiar buffer
        return false;
    }

    return true;
}

void ejecutar_calculadora() {
    int opcion;
    double num1, num2, resultado;
    bool continuar = true;

    printf("¡Bienvenido a la calculadora!\n");

    // Simulación de do...while usando while(1) + break
    while (continuar) {
        mostrar_menu_calculadora();

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida. Usa números del 1 al 5.\n");
            while (getchar() != '\n'); // Limpiar buffer
            continue;
        }

        if (opcion == OPERACION_SALIR) {
            printf("¡Gracias por usar la calculadora!\n");
            continuar = false;
            continue;
        }

        if (opcion < OPERACION_SUMA || opcion > OPERACION_DIVISION) {
            printf("Opción inválida: %d\n", opcion);
            continue;
        }

        if (!obtener_numeros(&num1, &num2)) {
            continue;
        }

        // Procesar operación
        bool operacion_valida = true;

        if (opcion == OPERACION_SUMA) {
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
        } else if (opcion == OPERACION_RESTA) {
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
        } else if (opcion == OPERACION_MULTIPLICACION) {
            resultado = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
        } else if (opcion == OPERACION_DIVISION) {
            if (num2 == 0.0) {
                printf("Error: División por cero no está permitida\n");
                operacion_valida = false;
            } else {
                resultado = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            }
        }

        if (operacion_valida) {
            printf("Operación completada\n");
        }
    }
}

int main() {
    ejecutar_calculadora();
    return 0;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} simular_menu_calculadora -->

:::{exercise}
:label: maquina_estados_sin_switch
:enumerator: simulacion-2

Diseñá una máquina de estados para simular el comportamiento de un cajero
automático sin usar `switch`. El sistema debe manejar estados como: inicio, PIN,
selección de operación, consulta de saldo, retiro de dinero y finalización. Usá
una tabla de funciones o if-else encadenados para manejar las transiciones.

:::
<!-- {exercise} -->

::::{solution} maquina_estados_sin_switch
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    ESTADO_INICIO,
    ESTADO_VALIDAR_PIN,
    ESTADO_MENU_PRINCIPAL,
    ESTADO_CONSULTAR_SALDO,
    ESTADO_RETIRAR_DINERO,
    ESTADO_FINALIZAR,
    ESTADO_ERROR,
    ESTADO_MAX
} estado_cajero_t;

typedef struct {
    estado_cajero_t estado_actual;
    int pin_correcto;
    int intentos_pin;
    double saldo_cuenta;
    bool sesion_activa;
} contexto_cajero_t;

// Prototipos de funciones de estado
void estado_inicio(contexto_cajero_t *ctx);
void estado_validar_pin(contexto_cajero_t *ctx);
void estado_menu_principal(contexto_cajero_t *ctx);
void estado_consultar_saldo(contexto_cajero_t *ctx);
void estado_retirar_dinero(contexto_cajero_t *ctx);
void estado_finalizar(contexto_cajero_t *ctx);
void estado_error(contexto_cajero_t *ctx);

// Tabla de funciones para simular switch
typedef void (*funcion_estado_t)(contexto_cajero_t *);

static funcion_estado_t tabla_estados[ESTADO_MAX] = {
    [ESTADO_INICIO] = estado_inicio,
    [ESTADO_VALIDAR_PIN] = estado_validar_pin,
    [ESTADO_MENU_PRINCIPAL] = estado_menu_principal,
    [ESTADO_CONSULTAR_SALDO] = estado_consultar_saldo,
    [ESTADO_RETIRAR_DINERO] = estado_retirar_dinero,
    [ESTADO_FINALIZAR] = estado_finalizar,
    [ESTADO_ERROR] = estado_error
};

void inicializar_cajero(contexto_cajero_t *ctx) {
    ctx->estado_actual = ESTADO_INICIO;
    ctx->pin_correcto = 1234;
    ctx->intentos_pin = 0;
    ctx->saldo_cuenta = 1500.00;
    ctx->sesion_activa = false;
}

void ejecutar_cajero(contexto_cajero_t *ctx) {
    // Simulación de do...while para la máquina de estados
    while (1) {
        if (ctx->estado_actual >= ESTADO_MAX) {
            printf("Estado inválido: %d\n", ctx->estado_actual);
            ctx->estado_actual = ESTADO_ERROR;
        }

        // Ejecutar función del estado actual (simulando switch con tabla)
        if (tabla_estados[ctx->estado_actual]) {
            tabla_estados[ctx->estado_actual](ctx);
        }

        // Condición de salida del lazo
        if (ctx->estado_actual == ESTADO_FINALIZAR) {
            break;
        }
    }
}

void estado_inicio(contexto_cajero_t *ctx) {
    printf("\n" "=" * 40 "\n");
    printf("BIENVENIDO AL CAJERO AUTOMÁTICO\n");
    printf("=" * 40 "\n");
    printf("Por favor, inserte su tarjeta...\n");
    printf("Presiona Enter para continuar: ");

    while (getchar() != '\n'); // Esperar Enter

    ctx->estado_actual = ESTADO_VALIDAR_PIN;
}

void estado_validar_pin(contexto_cajero_t *ctx) {
    int pin_ingresado;

    printf("\nVALIDACIÓN DE PIN\n");
    printf("Ingrese su PIN (4 dígitos): ");

    if (scanf("%d", &pin_ingresado) != 1) {
        printf("PIN inválido. Use solo números.\n");
        while (getchar() != '\n'); // Limpiar buffer
        ctx->intentos_pin++;
    } else if (pin_ingresado == ctx->pin_correcto) {
        printf("PIN correcto. Acceso autorizado.\n");
        ctx->sesion_activa = true;
        ctx->intentos_pin = 0;
        ctx->estado_actual = ESTADO_MENU_PRINCIPAL;
        return;
    } else {
        printf("PIN incorrecto.\n");
        ctx->intentos_pin++;
    }

    if (ctx->intentos_pin >= 3) {
        printf("Demasiados intentos fallidos. Tarjeta bloqueada.\n");
        ctx->estado_actual = ESTADO_ERROR;
    } else {
        printf("Intentos restantes: %d\n", 3 - ctx->intentos_pin);
    }
}

void estado_menu_principal(contexto_cajero_t *ctx) {
    int opcion;

    printf("\nMENÚ PRINCIPAL\n");
    printf("1. Consultar saldo\n");
    printf("2. Retirar dinero\n");
    printf("3. Finalizar sesión\n");
    printf("Seleccione opción: ");

    if (scanf("%d", &opcion) != 1) {
        printf("Opción inválida.\n");
        while (getchar() != '\n'); // Limpiar buffer
        return;
    }

    // Simulación de switch con if-else encadenados
    if (opcion == 1) {
        ctx->estado_actual = ESTADO_CONSULTAR_SALDO;
    } else if (opcion == 2) {
        ctx->estado_actual = ESTADO_RETIRAR_DINERO;
    } else if (opcion == 3) {
        ctx->estado_actual = ESTADO_FINALIZAR;
    } else {
        printf("Opción inválida: %d\n", opcion);
    }
}

void estado_consultar_saldo(contexto_cajero_t *ctx) {
    printf("\nCONSULTA DE SALDO\n");
    printf("Su saldo actual es: $%.2f\n", ctx->saldo_cuenta);

    printf("\nPresiona Enter para volver al menú principal: ");
    while (getchar() != '\n'); // Limpiar buffer anterior
    while (getchar() != '\n'); // Esperar Enter

    ctx->estado_actual = ESTADO_MENU_PRINCIPAL;
}

void estado_retirar_dinero(contexto_cajero_t *ctx) {
    double monto;

    printf("\nRETIRO DE DINERO\n");
    printf("Saldo disponible: $%.2f\n", ctx->saldo_cuenta);
    printf("Ingrese monto a retirar: $");

    if (scanf("%lf", &monto) != 1) {
        printf("Monto inválido.\n");
        while (getchar() != '\n'); // Limpiar buffer
        ctx->estado_actual = ESTADO_MENU_PRINCIPAL;
        return;
    }

    if (monto <= 0) {
        printf("El monto debe ser mayor a cero.\n");
    } else if (monto > ctx->saldo_cuenta) {
        printf("Saldo insuficiente.\n");
    } else {
        ctx->saldo_cuenta -= monto;
        printf("Retiro exitoso de $%.2f\n", monto);
        printf("Nuevo saldo: $%.2f\n", ctx->saldo_cuenta);
        printf("Por favor, retire su dinero de la bandeja.\n");
    }

    printf("\nPresiona Enter para volver al menú principal: ");
    while (getchar() != '\n'); // Limpiar buffer anterior
    while (getchar() != '\n'); // Esperar Enter

    ctx->estado_actual = ESTADO_MENU_PRINCIPAL;
}

void estado_finalizar(contexto_cajero_t *ctx) {
    printf("\nFINALIZANDO SESIÓN\n");
    printf("Gracias por usar nuestros servicios.\n");
    printf("Por favor, retire su tarjeta.\n");
    printf("¡Que tenga un buen día!\n");

    ctx->sesion_activa = false;
}

void estado_error(contexto_cajero_t *ctx) {
    printf("\nERROR DEL SISTEMA\n");
    printf("Se ha producido un error. La sesión será terminada.\n");
    printf("Si el problema persiste, contacte al servicio técnico.\n");

    ctx->estado_actual = ESTADO_FINALIZAR;
}

int main() {
    contexto_cajero_t cajero;
    inicializar_cajero(&cajero);
    ejecutar_cajero(&cajero);

    return 0;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} maquina_estados_sin_switch -->

:::{exercise}
:label: validacion_entrada_robusta
:enumerator: simulacion-3

Creá un sistema de validación de entrada de datos robusto que simule un
`do...while` para solicitar información de usuario. El sistema debe validar:
nombre (solo letras y espacios), edad (18-99 años), email (formato básico), y
teléfono (solo números). Implementá diferentes técnicas de simulación para cada
tipo de validación.

:::
<!-- {exercise} -->

::::{solution} validacion_entrada_robusta
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char nombre[100];
    int edad;
    char email[150];
    char telefono[20];
} datos_usuario_t;

// Función auxiliar para limpiar buffer de entrada
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Validación 1: Nombre (usando while infinito con break)
bool validar_nombre(char *nombre, size_t max_len) {
    printf("\nINGRESO DE NOMBRE\n");

    while (1) { // Simulación de do...while
        printf("Ingrese su nombre completo (solo letras y espacios): ");

        if (!fgets(nombre, max_len, stdin)) {
            printf("Error leyendo entrada. Intente nuevamente.\n");
            continue;
        }

        // Remover salto de línea
        nombre[strcspn(nombre, "\n")] = 0;

        // Validar que no esté vacío
        if (strlen(nombre) == 0) {
            printf("El nombre no puede estar vacío.\n");
            continue;
        }

        // Validar que solo contenga letras y espacios
        bool valido = true;
        for (size_t i = 0; i < strlen(nombre); i++) {
            if (!isalpha(nombre[i]) && nombre[i] != ' ') {
                valido = false;
                break;
            }
        }

        if (!valido) {
            printf("El nombre solo debe contener letras y espacios.\n");
            continue;
        }

        // Validar longitud mínima
        if (strlen(nombre) < 2) {
            printf("El nombre debe tener al menos 2 caracteres.\n");
            continue;
        }

        printf("Nombre válido: %s\n", nombre);
        return true;
    }
}

// Validación 2: Edad (usando variable de control booleana)
bool validar_edad(int *edad) {
    bool entrada_valida = false;
    char buffer[50];

    printf("\nINGRESO DE EDAD\n");

    while (!entrada_valida) { // Simulación con variable de control
        printf("Ingrese su edad (18-99 años): ");

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error leyendo entrada. Intente nuevamente.\n");
            continue;
        }

        // Intentar convertir a entero
        char *endptr;
        long edad_temp = strtol(buffer, &endptr, 10);

        // Validar que la conversión fue exitosa
        if (endptr == buffer || *endptr != '\n') {
            printf("Por favor ingrese un número válido.\n");
            continue;
        }

        // Validar rango
        if (edad_temp < 18 || edad_temp > 99) {
            printf("La edad debe estar entre 18 y 99 años.\n");
            continue;
        }

        *edad = (int)edad_temp;
        entrada_valida = true; // Salir del lazo
        printf("Edad válida: %d años\n", *edad);
    }

    return true;
}

// Validación 3: Email (usando función con return temprano)
bool obtener_email_valido(char *email, size_t max_len) {
    printf("\nINGRESO DE EMAIL\n");

    while (1) {
        printf("Ingrese su email: ");

        if (!fgets(email, max_len, stdin)) {
            printf("Error leyendo entrada. Intente nuevamente.\n");
            continue;
        }

        // Remover salto de línea
        email[strcspn(email, "\n")] = 0;

        // Validar longitud mínima
        if (strlen(email) < 5) {
            printf("El email es demasiado corto.\n");
            continue;
        }

        // Buscar @ (validación básica)
        char *at_pos = strchr(email, '@');
        if (!at_pos) {
            printf("El email debe contener '@'.\n");
            continue;
        }

        // Validar que @ no esté al inicio o al final
        if (at_pos == email || at_pos == email + strlen(email) - 1) {
            printf("El '@' no puede estar al inicio o al final.\n");
            continue;
        }

        // Buscar punto después del @
        char *dot_pos = strchr(at_pos, '.');
        if (!dot_pos) {
            printf("El email debe contener un punto después del '@'.\n");
            continue;
        }

        // Validar que haya caracteres después del último punto
        if (dot_pos == email + strlen(email) - 1) {
            printf("Debe haber caracteres después del último punto.\n");
            continue;
        }

        printf("Email válido: %s\n", email);
        return true; // Return temprano para salir
    }
}

// Validación 4: Teléfono (usando contador de intentos)
bool validar_telefono(char *telefono, size_t max_len) {
    int intentos = 0;
    const int max_intentos = 3;

    printf("\n📱 INGRESO DE TELÉFONO\n");

    while (intentos < max_intentos) { // Simulación con límite de intentos
        printf("Ingrese su teléfono (solo números, 8-15 dígitos): ");

        if (!fgets(telefono, max_len, stdin)) {
            printf("Error leyendo entrada.\n");
            intentos++;
            continue;
        }

        // Remover salto de línea
        telefono[strcspn(telefono, "\n")] = 0;

        // Validar que solo contenga dígitos
        bool solo_numeros = true;
        size_t len = strlen(telefono);

        if (len == 0) {
            printf("El teléfono no puede estar vacío.\n");
            intentos++;
            continue;
        }

        for (size_t i = 0; i < len; i++) {
            if (!isdigit(telefono[i])) {
                solo_numeros = false;
                break;
            }
        }

        if (!solo_numeros) {
            printf("El teléfono solo debe contener números.\n");
            intentos++;
            continue;
        }

        // Validar longitud
        if (len < 8 || len > 15) {
            printf("El teléfono debe tener entre 8 y 15 dígitos.\n");
            intentos++;
            continue;
        }

        printf("Teléfono válido: %s\n", telefono);
        return true;
    }

    printf("Demasiados intentos fallidos para el teléfono.\n");
    return false;
}

void mostrar_resumen(const datos_usuario_t *datos) {
    printf("\n" "=" * 50 "\n");
    printf("RESUMEN DE DATOS INGRESADOS\n");
    printf("=" * 50 "\n");
    printf("Nombre:    %s\n", datos->nombre);
    printf("Edad:      %d años\n", datos->edad);
    printf("Email:     %s\n", datos->email);
    printf("Teléfono:  %s\n", datos->telefono);
    printf("=" * 50 "\n");
    printf("Todos los datos han sido validados correctamente.\n");
}

bool confirmar_datos(const datos_usuario_t *datos) {
    char respuesta[10];

    mostrar_resumen(datos);

    while (1) {
        printf("\n¿Los datos son correctos? (s/n): ");

        if (!fgets(respuesta, sizeof(respuesta), stdin)) {
            printf("Error leyendo respuesta.\n");
            continue;
        }

        respuesta[strcspn(respuesta, "\n")] = 0;

        if (strlen(respuesta) != 1) {
            printf("Por favor ingrese solo 's' o 'n'.\n");
            continue;
        }

        char opcion = tolower(respuesta[0]);
        if (opcion == 's') {
            return true;
        } else if (opcion == 'n') {
            return false;
        } else {
            printf("Respuesta inválida. Use 's' para sí o 'n' para no.\n");
        }
    }
}

int main() {
    datos_usuario_t datos;
    bool datos_completos = false;

    printf("SISTEMA DE REGISTRO DE USUARIO\n");
    printf("Por favor, complete los siguientes datos:\n");

    // lazo principal usando simulación de do...while
    while (!datos_completos) {
        // Limpiar estructura
        memset(&datos, 0, sizeof(datos));

        // Validar cada campo usando diferentes técnicas de simulación
        if (!validar_nombre(datos.nombre, sizeof(datos.nombre))) {
            printf("Error validando nombre. Reiniciando proceso.\n");
            continue;
        }

        if (!validar_edad(&datos.edad)) {
            printf("Error validando edad. Reiniciando proceso.\n");
            continue;
        }

        if (!obtener_email_valido(datos.email, sizeof(datos.email))) {
            printf("Error validando email. Reiniciando proceso.\n");
            continue;
        }

        if (!validar_telefono(datos.telefono, sizeof(datos.telefono))) {
            printf("Error validando teléfono. Reiniciando proceso.\n");
            continue;
        }

        // Confirmar datos con el usuario
        if (confirmar_datos(&datos)) {
            datos_completos = true;
            printf("\nRegistro completado exitosamente!\n");
        } else {
            printf("\nReiniciando el proceso de registro...\n");
        }
    }

    return 0;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} validacion_entrada_robusta -->
