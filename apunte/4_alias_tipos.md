---
title: 'Definición de Tipos y Alias'
short_title: '4 - Alias y Enumeraciones'
subtitle: 'Typedef y enum en C'
---

(alias-tipos-capitulo)=

(enums-capitulo)=
## `Enum`eraciones en C

Las **enumeraciones** (`enum`) constituyen un mecanismo fundamental en el lenguaje C para la definición de tipos de datos que representan un **conjunto finito y discreto** de valores con nombres simbólicos. A diferencia de usar valores literales o constantes dispersas en el código, las enumeraciones proporcionan una abstracción semántica que mejora considerablemente la legibilidad, mantenibilidad y robustez del programa.

:::{note} Construcción sobre Fundamentos
Este capítulo asume familiaridad con los tipos de datos básicos de C presentados en el [](2_gradual), particularmente los tipos enteros y el concepto de constantes. Las enumeraciones son esencialmente una forma elegante de trabajar con conjuntos de constantes enteras relacionadas.
:::

Desde una perspectiva técnica, las enumeraciones son esencialmente **constantes enteras nombradas** que el compilador traduce en tiempo de compilación. Sin embargo, permiten modelar de forma explícita conjuntos limitados de valores, estados o categorías.

### `enum` vs `const` vs `#define`

Si este concepto resulta similar a las constantes `const` y a los literales de
preprocesador `#define` estás en lo cierto y todas las consideraciones de uso
aplican para cualquiera de los tres conceptos.

```{figure} 4/enum_concept.svg
:name: fig-enum-concept
:alt: Concepto de enumeraciones vs números mágicos
:align: center

Las enumeraciones proporcionan nombres simbólicos a valores enteros, transformando números mágicos en código legible y mantenible.
```

Aunque es posible definir constantes enteras con `#define` o una serie de
variables `const`, el uso de `enum` es la práctica superior y más segura para
agrupar _constantes relacionadas_. A diferencia de las macros de preprocesador
(`#define`), que carecen de tipo y pueden contaminar el espacio de nombres
global, `enum` crea un **tipo de dato distinto**. Esto mejora la **seguridad de
tipos** y permite que el compilador detecte errores lógicos, como intentar
comparar un día de la semana con un color. Además, los `enum` **auto-numeran**
sus miembros secuencialmente, reduciendo la posibilidad de errores manuales y
simplificando el mantenimiento. Esta agrupación lógica no solo hace el código
más legible y auto-documentado, sino que también es reconocida por los
depuradores, que pueden mostrar los nombres de las constantes (`LUNES`,
`MARTES`) en lugar de sus valores numéricos (`0`, `1`), facilitando enormemente
la depuración.

### Sintaxis y Declaración

#### Declaración Básica

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

#### Ejemplo

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

### Alcance y Namespaces

:::{note} Espacios de Nombres (*name spaces*) según la norma ISO/IEC 9899
Es fundamental no confundir la terminología específica de los *name spaces* en el estándar de C con los *namespaces* explícitos de lenguajes como C++ o C#. Conforme al apartado 6.2.3 del estándar ISO/IEC 9899, C clasifica los identificadores de un mismo ámbito en cuatro categorías independientes de espacios de nombres para evitar colisiones cruzadas:
1. **Etiquetas de sentencias (label names):** Identificadores referenciados por la sentencia `goto`, delimitados por el carácter `:`.
2. **Etiquetas de tipos (tags):** Los nombres identificadores precedidos por las palabras clave `struct`, `union` o `enum`.
3. **Miembros de estructuras o uniones (members):** Cada estructura o unión declara su propio espacio de nombres para sus miembros, encapsulándolos detrás del operador de acceso de miembros (como `.` o `->`).
4. **Identificadores ordinarios (ordinary identifiers):** Comprende a las variables, funciones, alias de tipos declarados con `typedef`, constantes declaradas en `enum` y parámetros de funciones.

Las constantes de una enumeración residen en el espacio de nombres de los **identificadores ordinarios**. En consecuencia, no están encapsuladas jerárquicamente dentro de la etiqueta del tipo `enum` al que pertenecen, lo que obliga a adoptar prefijos o nombres descriptivos singulares para evitar colisiones con variables u otras constantes ordinarias dentro del mismo bloque de alcance.
:::

#### Concepto de Namespace

En el contexto de la programación, un **namespace** (espacio de nombres) es una región del código donde un conjunto de identificadores es visible y accesible sin ambigüedad. Es un mecanismo fundamental para organizar y separar lógicamente los nombres, evitando colisiones entre identificadores que de otro modo compartirían el mismo nombre.

Formalmente, un namespace define un **contexto de resolución de nombres**: cuando el compilador encuentra un identificador, debe determinar a qué entidad se refiere consultando el namespace activo. En C, este concepto está implícito en el sistema de alcances (_scope_), pero no existe un mecanismo explícito de namespaces como en lenguajes posteriores (C++, Java, Rust).

En C, las constantes de enumeración se ubican en el **namespace global** de identificadores ordinarios, compartiendo este espacio con nombres de variables, funciones y otros símbolos. Esto significa que una constante `APAGADO` de un `enum` entra en conflicto con cualquier otra variable, función o constante de enumeración que se llame `APAGADO` en el mismo ámbito de compilación.

La **contaminación del namespace** se refiere al problema de introducir demasiados identificadores en un mismo ámbito, incrementando la probabilidad de conflictos por nombres duplicados o similares. Este problema es particularmente relevante en enumeraciones porque cada constante introduce un identificador independiente en el namespace, a diferencia de los miembros de una `struct` que están contenidos dentro del namespace de la estructura.

#### Problema de Contaminación del Namespace

Un aspecto importante a considerar es que los identificadores de las constantes de enumeración se encuentran en el **namespace global** (en C89/C90) o en el namespace del ámbito donde se declara la enumeración (en estándares más recientes).

```{code-block}c
:caption: Conflictos potenciales de nombres
:linenos:

enum estado_motor {
    APAGADO,
    ENCENDIDO,
    ERROR
};

enum estado_luz {
    APAGADO,    // Error: redefinición de APAGADO
    PRENDIDO,
    PARPADEANDO
};
```

#### Solución con Prefijos

Una práctica recomendada es usar **prefijos consistentes** para evitar colisiones:

```{code-block}c
:caption: Uso de prefijos para evitar conflictos
:linenos:

enum motor_estado {
    MOTOR_APAGADO,
    MOTOR_ENCENDIDO,
    MOTOR_ERROR
};

enum luz_estado {
    LUZ_APAGADA,
    LUZ_PRENDIDA, 
    LUZ_PARPADEANDO
};
```

:::{tip} Convenciones de nomenclatura

Seguí una convención consistente en tu proyecto:
- **Prefijo del dominio** + **ESTADO/ACCIÓN** en mayúsculas
- Ejemplo: `HTTP_OK`, `HTTP_NOT_FOUND`, `FILE_CREATED`, `FILE_ERROR`
- Esto mejora la legibilidad y previene conflictos de nombres

:::

### Asignación de Valores

#### Asignación Automática

Por defecto, se asignan valores enteros consecutivos comenzando desde `0`:

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

#### Asignación Explícita

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

#### Uso de Expresiones Constantes

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

### Definición de Tipos con `typedef`

Para mejorar la legibilidad, es recomendable usar `typedef`, a continuación en
este mismo apunte, veremos otros usos típicos de esta expresión.

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

:::{tip} Estilo
Usá el sufijo `_t` para tipos definidos con `typedef`, siguiendo las
convenciones del estándar POSIX. Esto hace evidente que se trata de un tipo de
dato y no de una variable ({ref}`0x0001h`).
:::

### Enumeraciones como Parámetros de Función

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

### Validación y Manejo Seguro

#### Validación de Rangos

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

#### Patrón de Validación con `switch`

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

### Enumeraciones con Flags (Bit Flags)

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
} bit_flag_t;
```

### Problemas Comunes

#### 1. Falta de Verificación de Tipo

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

#### 2. Dependencia de Valores Numéricos Específicos

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

#### 3. Problemas de Serialización

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
:linenos:

typedef enum {
    FORMATO_V1 = 100,    // Valores explícitos garantizan estabilidad
    FORMATO_V2 = 200,
    FORMATO_V3 = 300
} version_formato_t;

// Función para convertir enum a representación de protocolo estable
uint32_t version_a_protocolo(version_formato_t version) {
    switch (version) {
        case FORMATO_V1: return 100;
        case FORMATO_V2: return 200;
        case FORMATO_V3: return 300;
        default: return 0;  // Valor de error
    }
}

// Función para convertir desde protocolo a enum
version_formato_t protocolo_a_version(uint32_t valor) {
    switch (valor) {
        case 100: return FORMATO_V1;
        case 200: return FORMATO_V2;
        case 300: return FORMATO_V3;
        default: return FORMATO_V1;  // Valor por defecto seguro
    }
}

// Guardar de forma segura
void guardar_configuracion(FILE *archivo, version_formato_t version) {
    uint32_t valor_protocolo = version_a_protocolo(version);
    fwrite(&valor_protocolo, sizeof(uint32_t), 1, archivo);
}

// Cargar de forma segura
version_formato_t cargar_configuracion(FILE *archivo) {
    uint32_t valor_protocolo = 0;
    fread(&valor_protocolo, sizeof(uint32_t), 1, archivo);
    return protocolo_a_version(valor_protocolo);
}
```

:::{tip} Estabilidad de Protocolo
Al usar valores explícitos y funciones de conversión, podés reorganizar el `enum` internamente sin romper la compatibilidad con archivos existentes. Las funciones de conversión actúan como una capa de abstracción entre la representación interna y el formato persistido.
:::

### Mejores Prácticas

#### 1. Usar Enumeraciones para Máquinas de Estado

Las enumeraciones son ideales para implementar máquinas de estado finitas:

```{figure} 4/enum_state_machine.svg
:name: fig-enum-state-machine
:alt: Máquina de estado con enumeraciones
:align: center

Ejemplo de una máquina de estados de conexión implementada con enumeraciones, mostrando estados y transiciones válidas.
```

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

#### 2. Definir Funciones de Utilidad

Creá funciones auxiliares para trabajar con enumeraciones de forma segura:

```{code-block}c
:caption: Funciones de utilidad para enums
:linenos:

typedef enum {
    PRIORIDAD_ERRONEA = -1,
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
    if (str == NULL) {
        return PRIORIDAD_ERRONEA;
    }

    if (strcmp(str, "Baja") == 0) {
        return PRIORIDAD_BAJA;
    }
    if (strcmp(str, "Normal") == 0) {
        return PRIORIDAD_NORMAL;
    }
    if (strcmp(str, "Alta") == 0) {
        return PRIORIDAD_ALTA;
    }
    if (strcmp(str, "Crítica") == 0) {
        return PRIORIDAD_CRITICA;
    }

    return PRIORIDAD_ERRONEA;  // No encontrado
}

bool es_prioridad_valida(prioridad_t prioridad) {
    return (prioridad >= PRIORIDAD_BAJA && prioridad < PRIORIDAD_MAX);
}
```

#### 3. Documentar el Propósito y Rangos

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

#### 4. Usar Enumeraciones para Códigos de Retorno

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

### Consideraciones de Rendimiento

#### Tamaño en Memoria

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

### Interoperabilidad con Interfaces de Programación (API) del Sistema

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

---

### Documentación de Enumeraciones

La documentación adecuada de enumeraciones es esencial para comunicar el propósito de cada valor, las relaciones entre valores y las restricciones de uso. Al igual que con las estructuras, existen dos enfoques principales para documentar enumeraciones.

#### Enfoque 1: Bloque de Documentación Único

Este enfoque utiliza un único bloque de comentario antes de la definición de la enumeración para describir su propósito y todos sus valores. Es ideal para enumeraciones simples donde los valores son autoexplicativos.

```c
/**
 * Representa los niveles de severidad de un mensaje de log.
 * 
 * Los niveles están ordenados de menor a mayor severidad.
 * Usá DEBUG para mensajes detallados durante el desarrollo,
 * INFO para eventos normales, WARNING para situaciones anómalas
 * pero recuperables, ERROR para fallos que impiden operaciones
 * específicas, y CRITICAL para fallos que comprometen el sistema.
 * 
 * Valores:
 *   - NIVEL_DEBUG: Información de depuración detallada
 *   - NIVEL_INFO: Mensajes informativos de operación normal
 *   - NIVEL_WARNING: Advertencias que no impiden la operación
 *   - NIVEL_ERROR: Errores que impiden operaciones específicas
 *   - NIVEL_CRITICAL: Fallos críticos del sistema
 */
typedef enum {
    NIVEL_DEBUG,
    NIVEL_INFO,
    NIVEL_WARNING,
    NIVEL_ERROR,
    NIVEL_CRITICAL
} nivel_log_t;
```

**Ventajas:**
- Proporciona contexto general sobre el uso de la enumeración.
- Mantiene la definición visualmente limpia.
- Facilita explicar relaciones de orden o jerarquía entre valores.

**Desventajas:**
- La separación entre documentación y valores puede dificultar actualizaciones.
- Puede volverse verbosa si cada valor requiere explicación extensa.

### Enfoque 2: Documentación Distribuida

Este enfoque combina un bloque de comentario general con comentarios individuales para cada valor. Es preferible cuando cada valor requiere explicación específica o tiene restricciones particulares.

```c
/**
 * Representa los estados posibles de un proceso de compilación.
 * 
 * El proceso debe seguir el flujo: INICIAL -> ANALIZANDO -> COMPILANDO
 * -> ENLAZANDO -> COMPLETADO. En caso de error en cualquier etapa,
 * transiciona a ERROR_* correspondiente.
 */
typedef enum {
    COMPILACION_INICIAL,         // Estado inicial antes de comenzar
    COMPILACION_ANALIZANDO,      // Análisis léxico y sintáctico en progreso
    COMPILACION_COMPILANDO,      // Generación de código objeto
    COMPILACION_ENLAZANDO,       // Enlazado de módulos y bibliotecas
    COMPILACION_COMPLETADO,      // Proceso finalizado exitosamente
    COMPILACION_ERROR_SINTAXIS,  // Error de sintaxis detectado
    COMPILACION_ERROR_SEMANTICO, // Error semántico detectado
    COMPILACION_ERROR_ENLAZADO,  // Error durante el enlazado
    COMPILACION_ERROR_IO         // Error de entrada/salida
} estado_compilacion_t;
```

**Ventajas:**
- Cada valor tiene su documentación adyacente, facilitando mantenimiento.
- Permite especificar detalles únicos de cada valor.
- Ideal para enumeraciones con valores heterogéneos.

**Desventajas:**
- Puede hacer la definición más extensa visualmente.
- Requiere disciplina para mantener comentarios en todos los valores.

### Ejemplo Completo: Enumeración con Valores Explícitos

Para enumeraciones con valores explícitos o que representan códigos de protocolo, la documentación debe ser exhaustiva:

```c
/**
 * Códigos de estado HTTP más comunes.
 * 
 * Esta enumeración define los códigos de estado definidos en RFC 7231
 * y RFC 7235. Los valores están organizados por categoría:
 *   - 2xx: Respuestas exitosas
 *   - 4xx: Errores del cliente
 *   - 5xx: Errores del servidor
 * 
 * Los valores numéricos son los códigos HTTP estándar y NO deben
 * modificarse para mantener compatibilidad con el protocolo.
 */
typedef enum {
    HTTP_OK = 200,                      // Solicitud exitosa
    HTTP_CREATED = 201,                 // Recurso creado exitosamente
    HTTP_NO_CONTENT = 204,              // Exitosa, sin contenido en respuesta
    
    HTTP_BAD_REQUEST = 400,             // Sintaxis de solicitud inválida
    HTTP_UNAUTHORIZED = 401,            // Autenticación requerida o fallida
    HTTP_FORBIDDEN = 403,               // Servidor rechaza la solicitud
    HTTP_NOT_FOUND = 404,               // Recurso no encontrado
    HTTP_METHOD_NOT_ALLOWED = 405,      // Método HTTP no permitido
    
    HTTP_INTERNAL_SERVER_ERROR = 500,   // Error interno del servidor
    HTTP_NOT_IMPLEMENTED = 501,         // Funcionalidad no implementada
    HTTP_SERVICE_UNAVAILABLE = 503      // Servicio temporalmente no disponible
} codigo_http_t;
```

#### Documentación de Enumeraciones con Flags

Para enumeraciones que representan flags combinables, la documentación debe explicar cómo combinarlos:

```c
/**
 * Flags para control de permisos de archivo.
 * 
 * Estos flags pueden combinarse usando el operador OR (|) para
 * especificar múltiples permisos simultáneamente.
 * 
 * Ejemplo de uso:
 *   permisos_t permisos = PERMISO_LECTURA | PERMISO_ESCRITURA;
 * 
 * Para verificar permisos, usá el operador AND (&):
 *   if (permisos & PERMISO_LECTURA) { ... }
 * 
 * IMPORTANTE: Los valores son potencias de 2 para permitir
 * operaciones bitwise. NO modifiques estos valores.
 */
typedef enum {
    PERMISO_NINGUNO = 0,        // Sin permisos (0b0000)
    PERMISO_LECTURA = 1,        // Permite lectura (0b0001)
    PERMISO_ESCRITURA = 2,      // Permite escritura (0b0010)
    PERMISO_EJECUCION = 4,      // Permite ejecución (0b0100)
    PERMISO_ELIMINACION = 8,    // Permite eliminación (0b1000)
    PERMISO_TODOS = 15          // Todos los permisos (0b1111)
} permisos_archivo_t;
```

### Recomendaciones Generales para Enumeraciones

1. **Significado de los valores:** Explicá claramente qué representa cada valor y cuándo debe usarse.

2. **Orden y secuencia:** Si el orden de los valores es significativo (ej. severidad, estados), documentá esta relación.

3. **Valores explícitos:** Si asignás valores explícitos, documentá por qué (compatibilidad con protocolo, serialización, etc.).

4. **Valores centinela:** Si incluís valores como `_MAX`, `_INVALID` o `_UNKNOWN`, explicá su propósito.

5. **Restricciones:** Documentá cualquier restricción en el uso, transiciones válidas entre estados, o combinaciones permitidas.

6. **Compatibilidad:** Si la enumeración se serializa o se usa en interfaces externas, advertí sobre la necesidad de mantener estabilidad de valores.

Para más detalles sobre el estilo de comentarios, consultá la {ref}`regla 0x0032h <0x0032h>` sobre cómo escribir comentarios que expliquen el "porqué" y no el "qué".

---

### Ejercicios

```{exercise}
:label: enum_basico
:enumerator: enums-1

Definí una enumeración para representar los días de la semana.
Escribí una función que reciba un día y retorne si es día laboral
o fin de semana. Incluí validación para valores inválidos.
```

````{solution}
:for: enum_basico
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

