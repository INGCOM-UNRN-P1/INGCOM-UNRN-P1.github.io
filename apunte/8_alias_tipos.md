---
title: 'Definición de Tipos y Alias'
short_title: Alias y Enumeraciones
subtitle: 'Typedef y enum en C'
---

(alias-de-tipos-con-typedef)=
## Alias de Tipos con `typedef`

En C, el mecanismo nativo para crear nombres alternativos o **alias** de tipos de datos es la palabra clave `typedef`. A diferencia de lo que ocurre en otros lenguajes, `typedef` no introduce un nuevo tipo de dato físicamente diferente para el compilador; simplemente asocia un identificador secundario a un tipo existente (primitivo, puntero, estructura o enumeración) para simplificar la escritura o mejorar la abstracción conceptual del código.

(sintaxis-basica)=
### Sintaxis Básica

La declaración se asemeja a la de una variable estándar, pero precedida por `typedef`:

```{code-block}c
typedef tipo_existente nuevo_nombre_t;
```

Por ejemplo, si necesitás trabajar con enteros que representen distancias en metros y querés que el código exprese con claridad esa unidad:

```{code-block}c
typedef double metros_t;

// Ahora podés usar 'metros_t' como un tipo estándar
metros_t distancia_casa = 1500.50;
metros_t altura_edificio = 45.2;
```

Físicamente, `distancia_casa` es un `double`. El compilador simplemente reemplazará sintácticamente `metros_t` por `double` durante el análisis semántico.

(abstraccion-de-plataforma)=
### Abstracción de Plataforma

Uno de los usos más rigurosos de `typedef` es garantizar la portabilidad e independencia del hardware. Tipos de datos como `int` o `long` pueden variar su tamaño en bytes dependiendo de la arquitectura de la CPU (16, 32 o 64 bits). 

Mediante `typedef`, se pueden definir alias que denoten explícitamente el ancho físico del tipo de dato, facilitando la compilación del mismo código en múltiples plataformas:

```{code-block}c
// Definiciones basadas en la arquitectura del compilador
typedef signed char        entero8_t;
typedef short int          entero16_t;
typedef int                entero32_t;
typedef long long int      entero64_t;
```

*(Nota: En el C estándar moderno, estas definiciones ya se encuentran normalizadas en la cabecera estándar `<stdint.h>` mediante los tipos `int8_t`, `int16_t`, `int32_t` e `int64_t`)*.

(regla-de-estilo-de-la-catedra-el-sufijo-t)=
### Regla de Estilo de la Cátedra: El sufijo `_t`

Para mantener la claridad y coherencia en el código desarrollado, la cátedra impone la regla **{ref}`0x3004h`**, la cual establece que **todo alias de tipo creado mediante `typedef` debe finalizar de forma obligatoria con el sufijo `_t`** (por ejemplo, `metros_t`, `velocidad_t`, `nodo_t`). Esto permite distinguir instantáneamente los tipos personalizados de las variables y constantes en cualquier bloque de código.


A lo largo de este apunte le iremos dando uso a este concepto de manera gradual, particularmente para simplificar la declaración de estructuras complejas (Capítulo [](10_estructuras)) y la definición de Tipos de Datos Abstractos (Capítulo [](18_tad)).

---

(ejercicios-de-autoevaluacion-alias-de-tipos)=
### Ejercicios de Autoevaluación (Alias de Tipos)

:::{exercise}
:label: ej-typedef-metros-velocidad
Escribí tres declaraciones `typedef` de acuerdo con la regla de la cátedra {ref}`0x3004h`: `distancia_t` y `tiempo_t` como alias de `double`, y `velocidad_t` como alias de `double`. Luego, escribí una pequeña función que reciba una distancia y un tiempo, y retorne la velocidad correspondiente utilizando dichos alias.
:::

:::{solution} ej-typedef-metros-velocidad
:class: dropdown
```c
#include <stdio.h>

// Definición de alias con el sufijo _t obligatorio
typedef double distancia_t;
typedef double tiempo_t;
typedef double velocidad_t;

velocidad_t calcular_velocidad(distancia_t d, tiempo_t t) {
    if (t <= 0.0) {
        return 0.0;
    }
    return d / t;
}
```
:::

:::{exercise}
:label: ej-typedef-portabilidad
Implementá la declaración de tres alias de tipo (`u8_t`, `u16_t`, `u32_t`) que representen de forma explícita enteros sin signo de 8, 16 y 32 bits en una arquitectura donde `char` tiene 8 bits, `short` tiene 16 bits e `int` tiene 32 bits.
:::

:::{solution} ej-typedef-portabilidad
:class: dropdown
```c
typedef unsigned char      u8_t;
typedef unsigned short     u16_t;
typedef unsigned int       u32_t;
```
Estas declaraciones garantizan la portabilidad porque si el código se porta a un microcontrolador donde `int` ocupa 16 bits, solo es necesario redefinir el alias `u32_t` a `unsigned long` en un único archivo centralizado, sin alterar las declaraciones de variables a lo largo de todo el proyecto.
:::

:::{exercise}
:label: ej-typedef-alias-redundante
Explicá de forma conceptual si la expresión `typedef float real_t;` define un tipo de dato físicamente diferente para el compilador y si es válido realizar asignaciones directas sin conversión de tipo entre variables `float` y `real_t`.
:::

:::{solution} ej-typedef-alias-redundante
:class: dropdown
No define un nuevo tipo de dato físicamente diferente.
`typedef` introduce únicamente un **sinónimo o alias sintáctico** en la tabla de símbolos del compilador. Físicamente, el compilador trata a las variables `real_t` como variables de tipo `float` estándar. Por lo tanto, realizar la asignación directa entre variables de ambos tipos es totalmente válido y no requiere ningún moldeo de tipo (*cast*), ya que no existe incompatibilidad alguna.
:::

---

(enumeraciones-en-c)=
## Enumeraciones en C

Las **enumeraciones** (`enum`) constituyen un mecanismo fundamental en el lenguaje C para la definición de tipos de datos que representan un **conjunto finito y discreto** de valores con nombres simbólicos. A diferencia de usar valores literales o constantes dispersas en el código, las enumeraciones proporcionan una abstracción semántica que mejora considerablemente la legibilidad, mantenibilidad y robustez del programa.

:::{note} Construcción sobre Fundamentos
Este capítulo asume familiaridad con los tipos de datos básicos de C presentados en el [](2_gradual), particularmente los tipos enteros y el concepto de constantes. Las enumeraciones son esencialmente una forma elegante de trabajar con conjuntos de constantes enteras relacionadas.
:::

Desde una perspectiva técnica, las enumeraciones son esencialmente **constantes enteras nombradas** que el compilador traduce en tiempo de compilación. Sin embargo, permiten modelar de forma explícita conjuntos limitados de valores, estados o categorías.

(enum-vs-const-vs-define)=
### `enum` vs `const` vs `#define`

Si este concepto resulta similar a las constantes `const` y a los literales de
preprocesador `#define` estás en lo cierto y todas las consideraciones de uso
aplican para cualquiera de los tres conceptos.

```{figure} 8/enum_concept.svg
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

(sintaxis-y-declaracion)=
### Sintaxis y Declaración

#### Declaración Básica

La sintaxis fundamental para declarar una enumeración sigue el patrón estándar
de C para tipos definidos por el usuario:

```{code-block}c
:caption: Sintaxis básica de enumeración
:linenos:

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

(alcance-y-namespaces)=
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

En el contexto de la programación, un **namespace** o espacio de nombres (ver término en el {ref}`glosario-alias`) es una región del código donde un conjunto de identificadores es visible y accesible sin ambigüedad. Es un mecanismo fundamental para organizar y separar lógicamente los nombres, evitando colisiones entre identificadores que de otro modo compartirían el mismo nombre.

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

(ejercicios-de-autoevaluacion-sintaxis-y-namespaces)=
### Ejercicios de Autoevaluación (Sintaxis y Namespaces)

:::{exercise}
:label: ej-enum-namespace-colision
Explicá por qué el siguiente fragmento de código genera un error en tiempo de compilación y reescribilo aplicando la solución recomendada por buenas prácticas:
```c
enum estado_conexion { APAGADO, CONECTANDO, ACTIVO };
enum estado_alarma { APAGADO, ALERTA, DISPARADO };
```
:::

:::{solution} ej-enum-namespace-colision
:class: dropdown
El error se debe a que las constantes de enumeración residen en el **namespace de los identificadores ordinarios**. Las etiquetas `APAGADO` de ambas enumeraciones colisionan en el mismo ámbito global, provocando un error de redefinición de símbolo.
La solución consiste en añadir **prefijos únicos** a los miembros de cada enumeración para evitar colisiones:
```c
enum estado_conexion { CON_APAGADO, CON_CONECTANDO, CON_ACTIVO };
enum estado_alarma { ALA_APAGADA, ALA_ALERTA, ALA_DISPARADA };
```
:::

:::{exercise}
:label: ej-enum-sintaxis-declaracion
Declará una enumeración para representar los niveles de severidad de un error de sistema (`SEV_BAJA`, `SEV_MEDIA`, `SEV_ALTA`, `SEV_CRITICA`). Luego, mostrá la sintaxis necesaria para declarar una variable de este tipo e inicializarla con la constante de severidad alta.
:::

:::{solution} ej-enum-sintaxis-declaracion
:class: dropdown
```c
// Declaración de la enumeración
enum nivel_severidad {
    SEV_BAJA,
    SEV_MEDIA,
    SEV_ALTA,
    SEV_CRITICA
};

// Declaración e inicialización de la variable
enum nivel_severidad severidad_actual = SEV_ALTA;
```
:::

:::{exercise}
:label: ej-enum-const-define
Mencioná al menos dos ventajas importantes que presenta el uso de enumeraciones (`enum`) en comparación con el uso de macros del preprocesador (`#define`) para establecer conjuntos de constantes relacionadas.
:::

:::{solution} ej-enum-const-define
:class: dropdown
1. **Seguridad y Tipado**: `enum` crea un tipo de dato identificable por el compilador, lo que permite realizar comprobaciones de tipo y advertir si pasamos un valor incoherente, a diferencia de `#define` que realiza un reemplazo de texto literal sin validación semántica.
2. **Numeración Automática**: El compilador asigna valores de forma secuencial y automática, reduciendo la posibilidad de asignar manualmente valores duplicados en el conjunto.
3. **Depuración**: Los depuradores (como GDB) retienen los nombres simbólicos de las constantes de una enumeración, facilitando la inspección del estado de variables en memoria, mientras que las macros se pierden en el preprocesamiento mostrando únicamente números mágicos en el depurador.
:::

---

(asignacion-de-valores)=
### Asignación de Valores

#### Asignación Automática

Por defecto, se asignan valores enteros consecutivos comenzando desde `0`:

```{code-block}c
:caption: Asignación automática de valores
:linenos:

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
:linenos:

#define BASE_ERROR 1000

enum errores_sistema {
    ERROR_KERNEL = BASE_ERROR,
    ERROR_DRIVER = BASE_ERROR + 50,
    ERROR_HARDWARE = BASE_ERROR + 100,
    ERROR_FIRMWARE = ERROR_HARDWARE + 10
};
```

(definicion-de-tipos-con-typedef)=
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

(enumeraciones-como-parametros-de-funcion)=
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

(validacion-y-manejo-seguro)=
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

(enumeraciones-con-flags-bit-flags)=
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

(problemas-comunes)=
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

(mejores-practicas)=
### Mejores Prácticas

#### 1. Usar Enumeraciones para Máquinas de Estado

Las enumeraciones son ideales para implementar máquinas de estado finitas:

```{figure} 8/enum_state_machine.svg
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

(consideraciones-de-rendimiento)=
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

(interoperabilidad-con-interfaces-de-programacion-api-del-sistema)=
### Interoperabilidad con Interfaces de Programación (API) del Sistema

Muchas **APIs** o Interfaces de Programación de Aplicaciones (ver término en el {ref}`glosario-alias`) del sistema operativo usan enumeraciones. Es importante entender sus valores:

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

(ejercicios-de-autoevaluacion-asignacion-y-utilidades)=
### Ejercicios de Autoevaluación (Asignación y Utilidades)

:::{exercise}
:label: ej-enum-valores-secuencia
Dada la enumeración:
`enum control { PAUSA = 5, REPRODUCIR, PARAR = 10, GRABAR };`
Deducí formalmente el valor entero asignado por el compilador a cada una de las constantes del conjunto.
:::

:::{solution} ej-enum-valores-secuencia
:class: dropdown
El compilador realiza las siguientes asignaciones:
- `PAUSA`: Toma el valor explícito `5`.
- `REPRODUCIR`: Toma el valor siguiente en secuencia, es decir, `6`.
- `PARAR`: Toma el valor explícito `10`.
- `GRABAR`: Toma el valor siguiente en secuencia desde el último definido, es decir, `11`.
:::

:::{exercise}
:label: ej-enum-switch-defensivo
Escribí una función en C que tome como parámetro una variable de tipo `estado_transaccion_t` y retorne una cadena de caracteres constante (`const char *`) con el nombre textual del estado. Implementá un diseño defensivo con un caso `default` que maneje valores inválidos.
:::

:::{solution} ej-enum-switch-defensivo
:class: dropdown
```c
#include <stdio.h>

const char *obtener_nombre_estado(estado_transaccion_t estado) {
    switch (estado) {
        case TRANSACCION_PENDIENTE:
            return "Pendiente";
        case TRANSACCION_PROCESANDO:
            return "Procesando";
        case TRANSACCION_COMPLETADA:
            return "Completada";
        case TRANSACCION_FALLIDA:
            return "Fallida";
        case TRANSACCION_CANCELADA:
            return "Cancelada";
        default:
            // Switch defensivo obligatorio (Regla 0x1008h)
            fprintf(stderr, "Error: estado de transacción inválido: %d\n", estado);
            return "Desconocido";
    }
}
```
:::

:::{exercise}
:label: ej-enum-bit-flags
Declará una enumeración `permisos_red_t` utilizando potencias de 2 (representación en bits) para representar los permisos de `CONECTAR`, `ENVIAR` y `RECIBIR`. Luego, escribí una expresión en C que combine los permisos de `CONECTAR` y `ENVIAR` en una única variable mediante operadores lógicos binarios.
:::

:::{solution} ej-enum-bit-flags
:class: dropdown
```c
typedef enum {
    PERM_NINGUNO = 0,
    PERM_CONECTAR = 1,  // 0b0001
    PERM_ENVIAR = 2,    // 0b0010
    PERM_RECIBIR = 4    // 0b0100
} permisos_red_t;

// Combinación de permisos mediante operador OR a nivel de bits (|)
permisos_red_t mis_permisos = PERM_CONECTAR | PERM_ENVIAR; // Resulta en 3 (0b0011)
```
:::

---

(documentacion-de-enumeraciones)=
### Documentación de Enumeraciones

La documentación adecuada de enumeraciones es esencial para comunicar el propósito de cada valor, las relaciones entre valores y las restricciones de uso. Al igual que con las estructuras, existen dos enfoques principales para documentar enumeraciones.

#### Enfoque 1: Bloque de Documentación Único

Este enfoque utiliza un único bloque de comentario antes de la definición de la enumeración para describir su propósito y todos sus valores. Es ideal para enumeraciones simples donde los valores son autoexplicativos.

```{code-block}c
:linenos:
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

(enfoque-2-documentacion-distribuida)=
### Enfoque 2: Documentación Distribuida

Este enfoque combina un bloque de comentario general con comentarios individuales para cada valor. Es preferible cuando cada valor requiere explicación específica o tiene restricciones particulares.

```{code-block}c
:linenos:
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

(ejemplo-completo-enumeracion-con-valores-explicitos)=
### Ejemplo Completo: Enumeración con Valores Explícitos

Para enumeraciones con valores explícitos o que representan códigos de protocolo, la documentación debe ser exhaustiva:

```{code-block}c
:linenos:
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

```{code-block}c
:linenos:
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

(recomendaciones-generales-para-enumeraciones)=
### Recomendaciones Generales para Enumeraciones

1. **Significado de los valores:** Explicá claramente qué representa cada valor y cuándo debe usarse.

2. **Orden y secuencia:** Si el orden de los valores es significativo (ej. severidad, estados), documentá esta relación.

3. **Valores explícitos:** Si asignás valores explícitos, documentá por qué (compatibilidad con protocolo, serialización, etc.).

4. **Valores centinela:** Si incluís valores como `_MAX`, `_INVALID` o `_UNKNOWN`, explicá su propósito.

5. **Restricciones:** Documentá cualquier restricción en el uso, transiciones válidas entre estados, o combinaciones permitidas.

6. **Compatibilidad:** Si la enumeración se serializa o se usa en interfaces externas, advertí sobre la necesidad de mantener estabilidad de valores.

Para más detalles sobre el estilo de comentarios, consultá la {ref}`regla 0x0032h  <0x000Ah>` sobre cómo escribir comentarios que expliquen el "porqué" y no el "qué".


(ejercicios-de-autoevaluacion-documentacion-y-apis)=
### Ejercicios de Autoevaluación (Documentación y APIs)

:::{exercise}
:label: ej-enum-doc-doxygen
Escribí la definición y documentación compatible con Doxygen utilizando el enfoque distribuido para una enumeración llamada `estado_disco_t` que contenga los estados `DISCO_IDLE`, `DISCO_LECTURA`, `DISCO_ESCRITURA` y `DISCO_ERROR`.
:::

:::{solution} ej-enum-doc-doxygen
:class: dropdown
```c
/**
 * @brief Estados operativos de la unidad de almacenamiento.
 */
typedef enum {
    DISCO_IDLE,       ///< El disco se encuentra inactivo, listo para operaciones
    DISCO_LECTURA,    ///< El disco se encuentra leyendo sectores
    DISCO_ESCRITURA,  ///< El disco se encuentra escribiendo sectores
    DISCO_ERROR       ///< La unidad experimentó un fallo físico de E/S
} estado_disco_t;
```
:::

:::{exercise}
:label: ej-enum-api-cast
Explicá detalladamente por qué es un fallo crítico de seguridad no validar los rangos de un entero recibido desde una red o archivo externo antes de realizarle un moldeo de tipo (*cast*) a una enumeración `color_t` en C.
:::

:::{solution} ej-enum-api-cast
:class: dropdown
En el lenguaje C, el compilador no realiza comprobaciones de límites en tiempo de ejecución al asignar o moldear tipos numéricos a enumeraciones.
Si se realiza un *cast* incondicional de un entero externo (por ejemplo, el valor `99`) a la enumeración `color_t` (que solo tiene mapeados valores válidos del `0` al `2`), el programa aceptará ese valor inválido. Si este valor se utiliza posteriormente como índice de acceso en un arreglo de cadenas de colores o dentro de una estructura `switch` sin `default`, provocará desbordamiento de búfer o comportamientos indefinidos graves en tiempo de ejecución.
:::

:::{exercise}
:label: ej-enum-val-max-centinela
Escribí una función de validación en C llamada `es_nivel_valido` que reciba un entero y retorne un valor booleano (`bool`) indicando si es un miembro válido de la enumeración `nivel_log_t`, utilizando una constante centinela `NIVEL_MAX`.
:::

:::{solution} ej-enum-val-max-centinela
:class: dropdown
Primero definimos la enumeración incorporando el centinela al final:
```c
typedef enum {
    NIVEL_DEBUG,
    NIVEL_INFO,
    NIVEL_WARNING,
    NIVEL_ERROR,
    NIVEL_CRITICAL,
    // Centinela que contiene automáticamente el tamaño del conjunto
    NIVEL_MAX
} nivel_log_t;
```
La función de validación correspondiente es:
```c
#include <stdbool.h>

bool es_nivel_valido(int valor) {
    // Las constantes inician en 0, por lo que validamos el intervalo [0, NIVEL_MAX - 1]
    return (valor >= NIVEL_DEBUG && valor < NIVEL_MAX);
}
```
:::

---

(glosario)=
## Glosario

:::{glossary}
Espacio de Nombres (Namespace)
: Región lógica de un programa diseñada para agrupar identificadores (variables, funciones, tipos) y evitar colisiones de nombres. C no posee namespaces explícitos, sino que organiza sus identificadores en cuatro categorías implícitas de espacios de nombres dentro de cada ámbito.

API (Interfaz de Programación de Aplicaciones)
: Conjunto de firmas de funciones, definiciones de tipos y constantes expuestas por una biblioteca o el sistema operativo para permitir que un programa de usuario invoque y consuma sus servicios de forma abstracta.
:::

