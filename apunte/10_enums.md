---
title: "Enumeraciones (enum)"
short_title: "11 - enum/struct/union"
subtitle: "Tipos de datos compuestos"
---

## `Enum`eraciones en C

Las **enumeraciones** (`enum`) constituyen un mecanismo fundamental en el
lenguaje C para la definición de tipos de datos que representan un **conjunto
finito y discreto** de valores con nombres simbólicos. A diferencia de usar
valores literales o constantes dispersas en el código, las enumeraciones
proporcionan una abstracción semántica que mejora considerablemente la
legibilidad, mantenibilidad y robustez del programa.

Desde una perspectiva técnica, las enumeraciones son esencialmente **constantes
enteras nombradas** que el compilador traduce en tiempo de compilación. Sin
embargo, permiten modelar de forma explícita conjuntos limitados de valores,
estados o categorías.


### `enum` vs `const` vs `#define`

Si este concepto te parece similar a las constantes `const` y a los literales
de preprocesador `#define` estás en lo cierto y todas las consideraciones de uso
aplican para cualquiera de los tres conceptos.

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
} bit_flag_t
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
// TODO: Completar
```

### Mejores Prácticas

#### 1. Usar Enumeraciones para Máquinas de Estado

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

# Introducción: Los Ladrillos de la Memoria

En C, las **estructuras (`struct`)**, **uniones (`union`)** y **campos de bits
(bit-fields)** son las herramientas fundamentales que nos permiten ir más allá
de los tipos de datos básicos. Nos dan el poder de modelar entidades complejas
del mundo real, optimizar el uso de la memoria hasta el nivel del bit y
construir cualquier otra estructura de datos imaginable.

Dominar estos conceptos es crucial. Implica entender no solo la sintaxis, sino
cómo C organiza los datos en la memoria, un conocimiento que separa a un
programador novato de uno que puede escribir código eficiente, portable y
robusto.

Este apunte es un laboratorio práctico. No solo explica la teoría, sino que
proporciona ejemplos completos y los comandos para que puedas compilar, ejecutar
e inspeccionar el comportamiento de la memoria en tu propio sistema.

:::{warning}

Muchos detalles de bajo nivel, como el `padding` y el orden de los bits, son **dependientes de la implementación**. Los ejemplos asumen una arquitectura común (x86_64, little-endian), pero siempre debés verificar en tu plataforma.

:::

# 1. Estructuras (`struct`): Agrupando Datos

Una `struct` es una colección de variables (miembros) de diferentes tipos,
agrupadas bajo un solo nombre.

### Declaración y `typedef`

La práctica estándar, como indica la regla {ref}`0x001Eh`, es usar `typedef`
para crear un alias de tipo con el sufijo `_t`.

```c
typedef struct {
    char inicial;
    int legajo;
    float promedio;
} estudiante_t;

// Inicialización con inicializadores designados (preferido)
estudiante_t estudiante1 = { .inicial = 'J', .legajo = 12345, .promedio = 8.5f };
```

### Acceso a Miembros: `.` vs `->`

- **Operador Punto (`.`):** Para acceder a miembros de una variable `struct`.
- **Operador Flecha (`->`):** Para acceder a miembros a través de un **puntero**
  a una `struct`.

```c
estudiante_t est;
estudiante_t *p_est = &est;

est.legajo = 54321;      // Acceso directo
p_est->promedio = 9.0f;  // Acceso mediante puntero
```

El acceso `->` es equivalente a usar `(*p_est).promedio`, se prefiere la flecha
para simplificar este uso.

### Estructuras y Memoria: Alineación y Relleno (Padding)

El compilador a puede insertar bytes de relleno (padding), que son invisibles al
programador dentro de las `struct` para alinear los miembros en direcciones de
memoria que sean múltiplos de su tamaño. Esto optimiza la velocidad de acceso de
la CPU.

El problema con esto, es que en algunos casos necesitamos un control exacto de
los bits.

#### El "operador" `offsetof`

`offsetof` es una macro definida en el archivo de cabecera `<stddef.h>`. Su
propósito es calcular el **desplazamiento en bytes** de un miembro específico
dentro de una estructura (`struct`) o unión (`union`), desde el inicio de la
misma.

En otras palabras, te dice cuántos bytes hay entre el comienzo de la estructura
y el comienzo de uno de sus miembros.

##### ¿Para qué sirve?

Su principal utilidad reside en situaciones donde necesitas conocer la posición
exacta de un miembro dentro de una estructura sin tener una instancia de esa
estructura. Esto es común en programación de bajo nivel, {term}`serialización`
de datos y al trabajar con _buffers_ de memoria genéricos.

### Sintaxis

La sintaxis es la siguiente:

```c
size_t offsetof(type, member);
```

- `type`: Es el nombre del tipo de la estructura (ej. `struct MiEstructura`).
- `member`: Es el nombre del miembro de la estructura del cual querés saber el
  desplazamiento.

La macro devuelve un valor de tipo `size_t`, que es un tipo entero sin signo
capaz de representar el tamaño de cualquier objeto en memoria.

---

## Ejemplo Práctico

Imagina que tienes la siguiente estructura:

```c
#include <stdio.h>
#include <stddef.h>

struct Usuario {
    int id;
    char inicial;
    double salario;
};

int main() {
    size_t desplazamiento_id = offsetof(struct Usuario, id);
    size_t desplazamiento_inicial = offsetof(struct Usuario, inicial);
    size_t desplazamiento_salario = offsetof(struct Usuario, salario);

    printf("Desplazamiento de 'id': %zu bytes\n", desplazamiento_id);
    printf("Desplazamiento de 'inicial': %zu bytes\n", desplazamiento_inicial);
    printf("Desplazamiento de 'salario': %zu bytes\n", desplazamiento_salario);

    return 0;
}
```

### Posible Salida

La salida de este código podría ser:

```
Desplazamiento de 'id': 0 bytes
Desplazamiento de 'inicial': 4 bytes
Desplazamiento de 'salario': 8 bytes
```

**¿Qué nos dice esta salida?**

1.  **`id`**: Está al puro inicio de la estructura, por lo que su desplazamiento
    es **0**.
2.  **`inicial`**: Comienza en el byte 4. Esto se debe a que el `int` (`id`)
    ocupa 4 bytes, y el compilador puede añadir _relleno_ (padding) para alinear
    los datos en memoria y optimizar el acceso.
3.  **`salario`**: Empieza en el byte 8. Después del `char` (`inicial`), que
    ocupa 1 byte, el compilador ha añadido 3 bytes de relleno antes de `salario`
    para que este `double` (que suele ocupar 8 bytes) comience en una dirección
    de memoria múltiplo de 8, lo cual es más eficiente para el procesador.

---

## Casos de Uso Comunes

1.  **Cálculos de Punteros**: Es fundamental en la "aritmética de punteros"
    avanzada. Por ejemplo, si tienes un puntero a un miembro de una estructura y
    quieres obtener un puntero a la estructura contenedora completa. Una macro
    común para esto es `container_of` en el kernel de Linux, que depende
    internamente de `offsetof`.

2.  **Serialización/Deserialización**: Cuando necesitas guardar una estructura
    en un archivo o enviarla a través de una red, a menudo se convierte a un
    arreglo de bytes. `offsetof` ayuda a saber dónde empieza cada campo en ese
    _buffer_ de bytes.

3.  **Interfaces con otros lenguajes**: Al interactuar con código ensamblador u
    otros lenguajes de bajo nivel, a veces necesitas pasar la ubicación exacta
    de los campos de una estructura.

En resumen, **`offsetof`** es una herramienta poderosa y necesaria en la
programación de sistemas en C para manipular la memoria a un nivel muy preciso,
permitiendo interactuar directamente con la disposición de los datos en las
estructuras.

---

#### Laboratorio 1: Inspección de Layout

Vamos a analizar el layout de una estructura para visualizar el padding.

**`layout_inspect.c`**

```c
#include <stdio.h>
#include <stddef.h>

typedef struct {
    char a;     // 1 byte
    int  b;     // 4 bytes
    char c;     // 1 byte
} ejemplo_padding_t;

int main(void) {
    printf("sizeof(char) = %zu, sizeof(int) = %zu\n", sizeof(char), sizeof(int));
    printf("sizeof(ejemplo_padding_t) = %zu\n\n", sizeof(ejemplo_padding_t));

    printf("offsetof(a) = %zu\n", offsetof(ejemplo_padding_t, a));
    printf("offsetof(b) = %zu\n", offsetof(ejemplo_padding_t, b));
    printf("offsetof(c) = %zu\n", offsetof(ejemplo_padding_t, c));
}
```

**Compilación y Ejecución:**

```bash
gcc -Wextra -Wall -g layout_inspect.c -o layout_inspect
./layout_inspect
```

**Salida Esperada:**

```
sizeof(char) = 1, sizeof(int) = 4
sizeof(ejemplo_padding_t) = 12

offsetof(a) = 0
offsetof(b) = 4
offsetof(c) = 8
```

**Análisis:**

- El tamaño total es 12 bytes, no 6 (1+4+1).
- `b` está en el offset 4, no 1. El compilador insertó 3 bytes de padding
  después de `a`.
- `c` está en el offset 8.
- Se añaden 3 bytes de padding al final para que el tamaño total (12) sea
  múltiplo del miembro más grande (4), asegurando la alineación en arreglos.

```{exercise}
:label: ejer-layout-1
**Optimización de Padding**

Reordená los miembros de `ejemplo_padding_t` para minimizar su tamaño total. Verificá tu resultado con `sizeof`. ¿Cuál es el orden óptimo y por qué?
```

````{solution} ejer-layout-1
:class: dropdown
El orden óptimo es agrupar los miembros más pequeños: `char a; char c; int b;`.

```c
typedef struct {
    char a;     // 1 byte
    char c;     // 1 byte
    // 2 bytes de padding aquí
    int  b;     // 4 bytes
} ejemplo_optimizado_t;
// sizeof será 8
```
Al agrupar `a` y `c`, el compilador solo necesita 2 bytes de padding para alinear `b`. El tamaño total se reduce a 8 bytes.
````

---

# 2. Uniones (`union`): Un Espacio para Múltiples Propósitos

Una `union` permite que varios miembros compartan la **misma ubicación de
memoria**. Su tamaño es el de su miembro más grande. Solo un miembro puede estar
"activo" a la vez.

### El Patrón de Unión Etiquetada (Tagged Union)

Por sí mismas, las `union` tienen usos muy limitados ya que no es posible saber
como tenemos que interpretar la información contenida, para esto, se utiliza una
**unión etiquetada**: una `struct` que contiene un `enum` (la etiqueta) y una
`union` (el valor).

**`tagged_union.c`**

```c
#include <stdio.h>

typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_TEXTO
} tipo_dato_t;

typedef struct {
    tipo_dato_t tipo;
    union {
        int i;
        float f;
        const char *s;
    } valor;
} variante_t;

void imprimir_variante(const variante_t *v) {
    switch (v->tipo) {
        case TIPO_INT: printf("Entero: %d\n", v->valor.i); break;
        case TIPO_FLOAT: printf("Flotante: %.2f\n", v->valor.f); break;
        case TIPO_TEXTO: printf("Texto: \"%s\"\n", v->valor.s); break;
    }
}

int main() {
    variante_t v1 = { .tipo = TIPO_INT, .valor.i = 100 };
    variante_t v2 = { .tipo = TIPO_FLOAT, .valor.f = 3.14f };
    variante_t v3 = { .tipo = TIPO_TEXTO, .valor.s = "Hola" };

    imprimir_variante(&v1);
    imprimir_variante(&v2);
    imprimir_variante(&v3);
    return 0;
}
```

Este patrón es la base para implementar tipos de datos polimórficos en C.

```{exercise}
:label: ejer-tagged-union-2
**Procesador de Eventos**

Diseñá una unión etiquetada `evento_t` para un sistema simple. Un evento puede ser:
1.  `EVENTO_TECLA_PRESIONADA`: contiene el código de la tecla (`char`).
2.  `EVENTO_CLICK_MOUSE`: contiene las coordenadas `x` e `y` (`int`).
3.  `EVENTO_SALIR`: no contiene datos adicionales.

Escribí una función `void procesar_evento(const evento_t *evento)` que imprima un mensaje descriptivo según el tipo de evento.
```

````{solution} ejer-tagged-union-2
:class: dropdown
```c
#include <stdio.h>

typedef enum {
    EVENTO_TECLA_PRESIONADA,
    EVENTO_CLICK_MOUSE,
    EVENTO_SALIR
} tipo_evento_t;

typedef struct {
    int x;
    int y;
} pos_mouse_t;

typedef struct {
    tipo_evento_t tipo;
    union {
        char tecla;
        pos_mouse_t pos;
    } datos;
} evento_t;

void procesar_evento(const evento_t *evento) {
    switch (evento->tipo) {
        case EVENTO_TECLA_PRESIONADA:
            printf("Tecla presionada: '%c'\n", evento->datos.tecla);
            break;
        case EVENTO_CLICK_MOUSE:
            printf("Click de mouse en (%d, %d)\n", evento->datos.pos.x, evento->datos.pos.y);
            break;
        case EVENTO_SALIR:
            printf("Evento de salida recibido.\n");
            break;
    }
}

int main() {
    evento_t ev1 = { .tipo = EVENTO_TECLA_PRESIONADA, .datos.tecla = 'q' };
    evento_t ev2 = { .tipo = EVENTO_CLICK_MOUSE, .datos.pos = {120, 80} };
    evento_t ev3 = { .tipo = EVENTO_SALIR };

    procesar_evento(&ev1);
    procesar_evento(&ev2);
    procesar_evento(&ev3);
    return 0;
}
```
````

---

# 3. Campos de Bits (Bit-fields): Ahorro Extremo de Memoria

Los bit-fields permiten definir miembros de una `struct` con un ancho en bits
exacto, ideal para empaquetar flags o valores pequeños.

### Sintaxis y Ejemplo

```c
typedef struct {
    unsigned int activo      : 1; // 1 bit
    unsigned int modo_op     : 3; // 3 bits (valores 0-7)
    unsigned int prioridad   : 4; // 4 bits (valores 0-15)
} config_t;
```

El compilador empaquetará estos 8 bits en un solo byte (si es posible).

### Laboratorio 2: Inspección de Bit-fields

**`bitfield_inspect.c`**

```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t a : 2;
    uint8_t b : 3;
    uint8_t c : 3;
} packed_byte_t;

int main() {
    packed_byte_t data;
    data.a = 3; // 11b
    data.b = 5; // 101b
    data.c = 7; // 111b

    // Imprimimos la estructura como un solo byte
    printf("sizeof(packed_byte_t) = %zu\n", sizeof(packed_byte_t));
    printf("Byte resultante: 0x%02X\n", *(uint8_t*)&data);
    return 0;
}
```

**Compilación y Ejecución:**

```bash
gcc -Wextra -Wall bitfield_inspect.c -o bitfield_inspect
./bitfield_inspect
```

**Análisis:** La salida `0xFD` (o `11111101` en binario) puede parecer
sorprendente. El orden en que el compilador asigna los bits dentro del byte es
**implementation-defined**. No asumas un orden específico si necesitás
portabilidad.

```{exercise}
:label: ejer-bitfield-2
**Decodificador de Paquetes**

Un protocolo de red envía un byte de estado con la siguiente estructura de bits:
- Bit 0: `es_ack` (1=ACK, 0=NACK)
- Bit 1: `es_fin` (1=Fin de transmisión)
- Bits 2-4: `tipo_paquete` (un número de 0 a 7)
- Bits 5-7: `checksum` (un número de 0 a 7)

Creá una `struct` con bit-fields para representar este byte. Escribí una función que reciba un `unsigned char` y lo imprima de forma legible usando la estructura.
```

````{solution} ejer-bitfield-2
:class: dropdown
```c
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t es_ack : 1;
    uint8_t es_fin : 1;
    uint8_t tipo_paquete : 3;
    uint8_t checksum : 3;
} estado_paquete_t;

void imprimir_estado_paquete(uint8_t byte_estado) {
    estado_paquete_t estado = *(estado_paquete_t*)&byte_estado;

    printf("--- Estado del Paquete (0x%02X) ---\n", byte_estado);
    printf("  ACK: %s\n", estado.es_ack ? "Sí" : "No");
    printf("  FIN: %s\n", estado.es_fin ? "Sí" : "No");
    printf("  Tipo: %u\n", estado.tipo_paquete);
    printf("  Checksum: %u\n", estado.checksum);
    printf("----------------------------------\n");
}

int main() {
    // Ejemplo: ACK=1, FIN=0, Tipo=5 (101b), Checksum=3 (011b)
    // Binario: 011 101 0 1 -> 0xDA
    uint8_t paquete = 0b01110101;
    imprimir_estado_paquete(paquete);
    return 0;
}
```
````

## Glosario

:::{glossary}

enumeración : Un tipo de dato en C que define un conjunto de constantes enteras
nombradas. Permite asociar nombres simbólicos significativos a valores
numéricos, mejorando la legibilidad del código y reduciendo errores relacionados
con el uso de "números mágicos".

constante enumerada : Cada uno de los identificadores definidos dentro de una
enumeración. Por defecto, reciben valores enteros consecutivos comenzando desde
0, pero pueden tener valores explícitos asignados por el programador.

tipo opaco : Un tipo de dato cuya implementación interna está oculta al código
cliente. Las enumeraciones pueden usarse para crear tipos opacos que encapsulan
conjuntos de valores válidos sin exponer su representación numérica subyacente.

máquina de estados finita : Un modelo computacional que consiste en un número
finito de estados, transiciones entre esos estados, y acciones. Las
enumeraciones son ideales para representar los estados posibles en este tipo de
sistemas.

flag de bits : Una técnica donde se usan valores que son potencias de 2 para
representar opciones que pueden combinarse usando operadores bitwise. Cada bit
en la representación binaria representa una opción específica que puede estar
activada o desactivada.

valor centinela : Un valor especial que marca el final o límite de un conjunto
de valores válidos. En enumeraciones, se usa frecuentemente un elemento
adicional (como `ENUM_MAX`) para facilitar la validación de rangos y iteración.

serialización : El proceso de convertir datos en memoria a un formato que puede
almacenarse en un archivo o transmitirse por la red. Las enumeraciones requieren
cuidado especial durante la serialización para mantener compatibilidad cuando
cambian las definiciones.

:::
