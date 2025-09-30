---
title: "Enumeraciones (enum)"
short_title: "B - Enumeraciones"
subtitle: "Tipos de datos definidos por el usuario para valores discretos"
---

## Enumeraciones en C

Las **enumeraciones** (`enum`) constituyen un mecanismo fundamental en el
lenguaje C para la definición de tipos de datos que representan un conjunto
finito y discreto de valores con nombres simbólicos. A diferencia de usar
valores literales o constantes dispersas en el código, las enumeraciones
proporcionan una abstracción semántica que mejora considerablemente la
legibilidad, mantenibilidad y robustez del programa.

Desde una perspectiva técnica, las enumeraciones son esencialmente **constantes
enteras nombradas** que el compilador traduce en tiempo de compilación. Sin
embargo, su valor conceptual trasciende esta implementación subyacente, ya que
permiten modelar de forma explícita conceptos del dominio del problema que
naturalmente tienen un conjunto limitado de estados o categorías.

:::{note} Ventajas conceptuales

Las enumeraciones permiten que el código exprese **intención semántica** en
lugar de meros valores numéricos. En lugar de recordar que el estado "conectado"
corresponde al valor 2, podés usar directamente `ESTADO_CONECTADO`, lo que hace
el código autoexplicativo según la regla {ref}`0x0000h`.

:::

## Sintaxis y Declaración

### Declaración Básica

La sintaxis fundamental para declarar una enumeración sigue el patrón estándar
de C para tipos definidos por el usuario:

```{code-block}c
:caption: Sintaxis básica de enumeración

enum nombre_enumeracion {
    IDENTIFICADOR_1,
    IDENTIFICADOR_2,
    IDENTIFICADOR_3,
    // ... más identificadores
};
```

### Ejemplo Práctico

```{code-block}c
:caption: Definición de estados de conexión
:linenos:

enum estado_conexion {
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    ERROR_CONEXION
};

// Uso en variables
enum estado_conexion estado_actual = DESCONECTADO;
```

## Asignación de Valores

### Asignación Automática

Por defecto, C asigna valores enteros consecutivos comenzando desde 0:

```{code-block}c
:caption: Asignación automática de valores

enum dias_semana {
    LUNES,      // 0
    MARTES,     // 1
    MIERCOLES,  // 2
    JUEVES,     // 3
    VIERNES,    // 4
    SABADO,     // 5
    DOMINGO     // 6
};
```

### Asignación Explícita

Podés especificar valores explícitos para cualquier constante. Los valores no
especificados continúan la secuencia desde el último valor asignado:

```{code-block}c
:caption: Asignación mixta de valores
:linenos:

enum codigo_error {
    EXITO = 0,
    ERROR_ARCHIVO = 100,
    ERROR_MEMORIA,          // 101
    ERROR_PERMISOS,         // 102
    ERROR_CRITICO = 500,
    ERROR_FATAL             // 501
};
```

### Uso de Expresiones Constantes

Las asignaciones pueden utilizar expresiones constantes evaluables en tiempo de
compilación:

```{code-block}c
:caption: Uso de expresiones constantes en enums

#define BASE_ERROR 1000

enum errores_sistema {
    ERROR_KERNEL = BASE_ERROR,
    ERROR_DRIVER = BASE_ERROR + 50,
    ERROR_HARDWARE = BASE_ERROR + 100,
    ERROR_FIRMWARE = ERROR_HARDWARE + 10
};
```

## Definición de Tipos con `typedef`

Para mejorar la legibilidad y seguir las convenciones modernas de C, es
recomendable usar `typedef` con enumeraciones:

```{code-block}c
:caption: Definición de tipo enum con typedef
:linenos:

typedef enum {
    OPERACION_SUMA,
    OPERACION_RESTA,
    OPERACION_MULTIPLICACION,
    OPERACION_DIVISION
} operacion_matematica_t;

// Uso simplificado
operacion_matematica_t operacion = OPERACION_SUMA;

// En lugar de:
// enum operacion_matematica operacion = OPERACION_SUMA;
```

:::{tip} Cuestiones de estilo

Usá el sufijo `_t` para tipos definidos con `typedef`, siguiendo las
convenciones del estándar POSIX. Esto hace evidente que se trata de un tipo de
dato y no de una variable ({ref}`0x0001h`).

:::

## Enumeraciones como Parámetros de Función

Las enumeraciones proporcionan una interfaz más segura y expresiva para
funciones que requieren parámetros de un conjunto limitado de valores:

```{code-block}c
:caption: Uso de enums como parámetros de función
:linenos:

typedef enum {
    NIVEL_DEBUG,
    NIVEL_INFO,
    NIVEL_WARNING,
    NIVEL_ERROR,
    NIVEL_CRITICAL
} nivel_log_t;

void escribir_log(nivel_log_t nivel, const char *mensaje) {
    ...
```

## Validación y Manejo Seguro

### Validación de Rangos

Aunque C no proporciona verificación automática de tipos `enum`, podés
implementar validación explícita:

```{code-block}c
:caption: Validación de valores de enumeración
:linenos:

typedef enum {
    ESTADO_INICIAL,
    ESTADO_PROCESANDO,
    ESTADO_COMPLETADO,
    ESTADO_ERROR,
    // Centinela para validación
    ESTADO_MAX
} estado_proceso_t;

bool es_estado_valido(int valor) {
    return (valor >= ESTADO_INICIAL && valor < ESTADO_MAX);
}

bool cambiar_estado(estado_proceso_t *estado_actual, estado_proceso_t nuevo_estado) {
    if (!es_estado_valido(nuevo_estado)) {
        fprintf(stderr, "Error: Estado inválido %d\n", nuevo_estado);
        return false;
    }

    *estado_actual = nuevo_estado;
    return true;
}
```

### Patrón de Validación con Switch

Una técnica robusta es usar `switch` con manejo explícito de casos inválidos:

```{code-block}c
:caption: Validación robusta con switch
:linenos:

typedef enum {
    FORMATO_JSON,
    FORMATO_XML,
    FORMATO_CSV,
    FORMATO_YAML
} formato_archivo_t;

const char *obtener_extension(formato_archivo_t formato) {
    switch (formato) {
        case FORMATO_JSON:
            return ".json";
        case FORMATO_XML:
            return ".xml";
        case FORMATO_CSV:
            return ".csv";
        case FORMATO_YAML:
            return ".yaml";
        default:
            fprintf(stderr, "Error: formato de archivo desconocido: %d\n", formato);
            return NULL;
    }
}
```

## Enumeraciones con Flags (Bit Flags)

Para representar combinaciones de opciones, podés usar enumeraciones con valores
que son potencias de 2:

```{code-block}c
:caption: Enumeración de flags para permisos
:linenos:

typedef enum {
    PERMISO_NINGUNO = 0,
    PERMISO_LECTURA = 1,        // 0001
    PERMISO_ESCRITURA = 2,      // 0010
    PERMISO_EJECUCION = 4,      // 0100
} bit_flag_t
```

## Problemas Comunes

### 1. Falta de Verificación de Tipo

C permite asignar cualquier valor entero a una variable `enum` sin advertencias:

```{code-block}c
:caption: Problema: asignación de valores arbitrarios
:linenos:

typedef enum {
    ROJO,
    VERDE,
    AZUL
} color_t;

color_t color = 42;  // ¡Compilará sin error!

// Esto puede causar problemas en switch statements
switch (color) {
    case ROJO:
        printf("Rojo\n");
        break;
    case VERDE:
        printf("Verde\n");
        break;
    case AZUL:
        printf("Azul\n");
        break;
    // Sin default, el valor 42 no es manejado
}
```

**Solución**: Siempre incluí un caso `default` y validación explícita:

```{code-block}c
:caption: Solución: manejo defensivo
:linenos:

switch (color) {
    case ROJO:
        printf("Rojo\n");
        break;
    case VERDE:
        printf("Verde\n");
        break;
    case AZUL:
        printf("Azul\n");
        break;
    default:
        fprintf(stderr, "Error: color inválido %d\n", color);
        return ERROR_VALOR_INVALIDO;
}
```

### 2. Dependencia de Valores Numéricos Específicos

```{code-block}c
:caption: Problema: dependencia frágil de valores

typedef enum {
    ENERO = 1,
    FEBRERO,    // 2
    MARZO       // 3
    // ...
} mes_t;

// Código frágil que depende de valores específicos
int dias_mes[] = {0, 31, 28, 31 /* ... */}; // ¡Índice 0 sin usar!
int dias = dias_mes[mes]; // Asume que ENERO == 1
```

**Solución**: Desacoplar la lógica del valor numérico:

```{code-block}c
:caption: Solución: mapeo explícito
:linenos:

typedef enum {
    ENERO,
    FEBRERO,
    MARZO,
    // ... otros meses
    MES_INVALIDO
} mes_t;

int obtener_dias_mes(mes_t mes) {
    static const int dias_por_mes[] = {
        31,  // ENERO
        28,  // FEBRERO
        31,  // MARZO
        // ... otros meses
    };

    if (mes < 0 || mes >= MES_INVALIDO) {
        return -1;  // Error
    }

    return dias_por_mes[mes];
}
```

### 3. Problemas de Serialización

Las enumeraciones pueden causar problemas al guardar datos en archivos o
enviarlos por red:

```{code-block}c
:caption: Problema: serialización frágil

typedef enum {
    FORMATO_V1,
    FORMATO_V2,
    FORMATO_V3
} version_formato_t;

// Problemático: si se reordena el enum, los archivos guardados se corrompen
void guardar_configuracion(FILE *archivo, version_formato_t version) {
    fwrite(&version, sizeof(version), 1, archivo);  // ¡Peligroso!
}
```

**Solución**: Usar valores explícitos y funciones de conversión:

```{code-block}c
:caption: Solución: serialización robusta
// TODO: Completar
```

## Mejores Prácticas

### 1. Usar Enumeraciones para Máquinas de Estado

Las enumeraciones son ideales para implementar máquinas de estado finitas:

```{code-block}c
:caption: Máquina de estado con enumeraciones
:linenos:

typedef enum {
    ESTADO_IDLE,
    ESTADO_CONECTANDO,
    ESTADO_AUTENTICANDO,
    ESTADO_CONECTADO,
    ESTADO_DESCONECTANDO,
    ESTADO_ERROR
} estado_conexion_t;

typedef struct {
    estado_conexion_t estado_actual;
    int intentos_reconexion;
    time_t timestamp_ultimo_cambio;
} maquina_estados_t;

bool transicion_valida(estado_conexion_t desde, estado_conexion_t hacia) {
    switch (desde) {
        case ESTADO_IDLE:
            return (hacia == ESTADO_CONECTANDO);
        case ESTADO_CONECTANDO:
            return (hacia == ESTADO_AUTENTICANDO || hacia == ESTADO_ERROR);
        case ESTADO_AUTENTICANDO:
            return (hacia == ESTADO_CONECTADO || hacia == ESTADO_ERROR);
        case ESTADO_CONECTADO:
            return (hacia == ESTADO_DESCONECTANDO || hacia == ESTADO_ERROR);
        case ESTADO_DESCONECTANDO:
            return (hacia == ESTADO_IDLE || hacia == ESTADO_ERROR);
        case ESTADO_ERROR:
            return (hacia == ESTADO_IDLE || hacia == ESTADO_CONECTANDO);
        default:
            return false;
    }
}
```

### 2. Definir Funciones de Utilidad

Creá funciones auxiliares para trabajar con enumeraciones de forma segura:

```{code-block}c
:caption: Funciones de utilidad para enums
:linenos:

typedef enum {
    PRIORIDAD_BAJA,
    PRIORIDAD_NORMAL,
    PRIORIDAD_ALTA,
    PRIORIDAD_CRITICA,
    PRIORIDAD_MAX  // Centinela
} prioridad_t;

const char *prioridad_a_string(prioridad_t prioridad) {
    static const char *nombres[] = {
        "Baja",
        "Normal",
        "Alta",
        "Crítica"
    };

    if (prioridad < 0 || prioridad >= PRIORIDAD_MAX) {
        return "Desconocida";
    }

    return nombres[prioridad];
}

prioridad_t string_a_prioridad(const char *str) {
    if (str == NULL) return -1;

    if (strcmp(str, "Baja") == 0) return PRIORIDAD_BAJA;
    if (strcmp(str, "Normal") == 0) return PRIORIDAD_NORMAL;
    if (strcmp(str, "Alta") == 0) return PRIORIDAD_ALTA;
    if (strcmp(str, "Crítica") == 0) return PRIORIDAD_CRITICA;

    return -1;  // No encontrado
}

bool es_prioridad_valida(prioridad_t prioridad) {
    return (prioridad >= PRIORIDAD_BAJA && prioridad < PRIORIDAD_MAX);
}
```

### 3. Documentar el Propósito y Rangos

```{code-block}c
:caption: Documentación completa de enumeraciones
:linenos:

/**
 * Estados posibles de una transacción bancaria.
 *
 * TRANSACCION_PENDIENTE: Transacción creada pero no procesada
 * TRANSACCION_PROCESANDO: En curso, no se puede cancelar
 * TRANSACCION_COMPLETADA: Exitosamente finalizada
 * TRANSACCION_FALLIDA: Error durante el procesamiento
 * TRANSACCION_CANCELADA: Cancelada por el usuario o sistema
 *
 * Nota: Los valores numéricos son secuenciales desde 0.
 * No dependas de valores específicos para lógica de negocio.
 */
typedef enum {
    TRANSACCION_PENDIENTE,
    TRANSACCION_PROCESANDO,
    TRANSACCION_COMPLETADA,
    TRANSACCION_FALLIDA,
    TRANSACCION_CANCELADA,
    TRANSACCION_MAX_ESTADOS
} estado_transaccion_t;
```

### 4. Usar Enumeraciones para Códigos de Retorno

Las enumeraciones proporcionan códigos de retorno más expresivos que simples
enteros:

```{code-block}c
:caption: Códigos de retorno con enumeraciones
:linenos:

typedef enum {
    RESULTADO_EXITO = 0,
    RESULTADO_ERROR_PARAMETRO_NULO,
    RESULTADO_ERROR_MEMORIA_INSUFICIENTE,
    RESULTADO_ERROR_ARCHIVO_NO_EXISTE,
    RESULTADO_ERROR_PERMISOS_INSUFICIENTES,
    RESULTADO_ERROR_FORMATO_INVALIDO,
    RESULTADO_ERROR_CONEXION_PERDIDA,
    RESULTADO_ERROR_TIMEOUT,
    RESULTADO_ERROR_DESCONOCIDO
} resultado_operacion_t;

resultado_operacion_t procesar_archivo(const char *ruta_archivo, void **datos_salida) {
    if (ruta_archivo == NULL || datos_salida == NULL) {
        return RESULTADO_ERROR_PARAMETRO_NULO;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) {
        return RESULTADO_ERROR_ARCHIVO_NO_EXISTE;
    }

    // ... lógica de procesamiento

    fclose(archivo);
    return RESULTADO_EXITO;
}

// Uso expresivo
resultado_operacion_t resultado = procesar_archivo("datos.txt", &buffer);
if (resultado != RESULTADO_EXITO) {
    fprintf(stderr, "Error procesando archivo: %d\n", resultado);
    return resultado;
}
```

## Consideraciones de Rendimiento

### Tamaño en Memoria

Las enumeraciones tienen el tamaño de un `int` por defecto, pero el estándar
permite al compilador elegir el tipo entero más pequeño que pueda representar
todos los valores:

```{code-block}c
:caption: Análisis de tamaño de enums

typedef enum {
    PEQUENO_A,
    PEQUENO_B,
    PEQUENO_C
} enum_pequeno_t;

typedef enum {
    GRANDE_A = 0,
    GRANDE_B = 1000000
} enum_grande_t;

// En muchos compiladores:
// sizeof(enum_pequeno_t) podría ser 1 byte
// sizeof(enum_grande_t) será 4 bytes (int)
```

## Interoperabilidad con Interfaces de Programación (API) del Sistema

Muchas APIs del sistema operativo usan enumeraciones. Es importante entender sus
valores:

```{code-block}c
:caption: Integración con APIs del sistema
:linenos:

#include <sys/types.h>
#include <sys/stat.h>

typedef enum {
    TIPO_ARCHIVO_REGULAR,
    TIPO_ARCHIVO_DIRECTORIO,
    TIPO_ARCHIVO_ENLACE,
    TIPO_ARCHIVO_DESCONOCIDO
} tipo_archivo_t;

tipo_archivo_t obtener_tipo_archivo(const char *ruta) {
    struct stat info;
    if (stat(ruta, &info) != 0) {
        return TIPO_ARCHIVO_DESCONOCIDO;
    }

    if (S_ISREG(info.st_mode)) {
        return TIPO_ARCHIVO_REGULAR;
    } else if (S_ISDIR(info.st_mode)) {
        return TIPO_ARCHIVO_DIRECTORIO;
    } else if (S_ISLNK(info.st_mode)) {
        return TIPO_ARCHIVO_ENLACE;
    }

    return TIPO_ARCHIVO_DESCONOCIDO;
}
```

## Ejercicios

```{exercise}
:label: enum_basico
:enumerator: enums-1

Definí una enumeración para representar los días de la semana. 
Escribí una función que reciba un día y retorne si es día laboral
o fin de semana. Incluí validación para valores inválidos.
```

````{solution} enum_basico
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO,
    DIA_INVALIDO
} dia_semana_t;

typedef enum {
    DIA_LABORAL,
    FIN_DE_SEMANA,
    ERROR_DIA_INVALIDO
} tipo_dia_t;

tipo_dia_t clasificar_dia(dia_semana_t dia) {
    switch (dia) {
        case LUNES:
        case MARTES:
        case MIERCOLES:
        case JUEVES:
        case VIERNES:
            return DIA_LABORAL;
        case SABADO:
        case DOMINGO:
            return FIN_DE_SEMANA;
        default:
            return ERROR_DIA_INVALIDO;
    }
}

const char *dia_a_string(dia_semana_t dia) {
    static const char *nombres[] = {
        "Lunes", "Martes", "Miércoles", "Jueves",
        "Viernes", "Sábado", "Domingo"
    };

    if (dia < 0 || dia >= DIA_INVALIDO) {
        return "Día inválido";
    }

    return nombres[dia];
}

int main() {
    for (int i = LUNES; i <= DOMINGO; i++) {
        dia_semana_t dia = (dia_semana_t)i;
        tipo_dia_t tipo = clasificar_dia(dia);

        printf("%s: ", dia_a_string(dia));
        switch (tipo) {
            case DIA_LABORAL:
                printf("Día laboral\n");
                break;
            case FIN_DE_SEMANA:
                printf("Fin de semana\n");
                break;
            case ERROR_DIA_INVALIDO:
                printf("Error: día inválido\n");
                break;
        }
    }

    // Probar con valor inválido
    dia_semana_t dia_malo = (dia_semana_t)42;
    tipo_dia_t resultado = clasificar_dia(dia_malo);
    if (resultado == ERROR_DIA_INVALIDO) {
        printf("Detección correcta de día inválido: %d\n", dia_malo);
    }

    return 0;
}
```
````

## Glosario

:::{glossary}

enumeración
: Un tipo de dato en C que define un conjunto de constantes enteras
nombradas. Permite asociar nombres simbólicos significativos a valores
numéricos, mejorando la legibilidad del código y reduciendo errores relacionados
con el uso de "números mágicos".

constante enumerada
: Cada uno de los identificadores definidos dentro de una
enumeración. Por defecto, reciben valores enteros consecutivos comenzando desde
0, pero pueden tener valores explícitos asignados por el programador.

tipo opaco
: Un tipo de dato cuya implementación interna está oculta al código
cliente. Las enumeraciones pueden usarse para crear tipos opacos que encapsulan
conjuntos de valores válidos sin exponer su representación numérica subyacente.

máquina de estados finita
: Un modelo computacional que consiste en un número
finito de estados, transiciones entre esos estados, y acciones. Las
enumeraciones son ideales para representar los estados posibles en este tipo de
sistemas.

flag de bits
: Una técnica donde se usan valores que son potencias de 2 para
representar opciones que pueden combinarse usando operadores bitwise. Cada bit
en la representación binaria representa una opción específica que puede estar
activada o desactivada.

valor centinela
: Un valor especial que marca el final o límite de un conjunto
de valores válidos. En enumeraciones, se usa frecuentemente un elemento
adicional (como `ENUM_MAX`) para facilitar la validación de rangos y iteración.

serialización
: El proceso de convertir datos en memoria a un formato que puede
almacenarse en un archivo o transmitirse por la red. Las enumeraciones requieren
cuidado especial durante la serialización para mantener compatibilidad cuando
cambian las definiciones.

:::
