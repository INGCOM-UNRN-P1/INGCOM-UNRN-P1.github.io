---
title: "Enumeraciones (enum)"
short_title: "B - Enums" 
subtitle: "Definiendo tipos de datos con valores nombrados"
---

## Introducción a las Enumeraciones

Las **enumeraciones** (declaradas con la palabra clave `enum`) son un tipo de dato que permite definir un conjunto de constantes enteras con nombres significativos. Representan una forma elegante y segura de trabajar con valores discretos que tienen un significado específico en el dominio del problema, reemplazando el uso de "números mágicos" que reducen la legibilidad del código.

En lugar de usar valores literales como `0`, `1`, `2` para representar estados, direcciones o categorías, las enumeraciones proporcionan nombres descriptivos que hacen el código más expresivo y mantenible.

```{code-block}c
:caption: Comparación entre números mágicos y enumeraciones
:linenos:

// Problemático: números mágicos sin contexto
int estado = 2;
if (estado == 1) {
    printf("Procesando...\n");
}

// Claro: enumeración con nombres significativos
enum estado_procesamiento {
    ESPERANDO,
    PROCESANDO, 
    COMPLETADO,
    ERROR
};

enum estado_procesamiento estado = PROCESANDO;
if (estado == PROCESANDO) {
    printf("Procesando...\n");
}
```

## Sintaxis y Declaración Básica

### Declaración Simple

Una enumeración se declara usando la palabra clave `enum` seguida de un identificador y la lista de constantes entre llaves:

```{code-block}c
enum nombre_enumeracion {
    CONSTANTE1,
    CONSTANTE2,
    CONSTANTE3
};
```

Por defecto, la primera constante tiene valor `0`, la segunda `1`, y así sucesivamente.

```{code-block}c
:caption: Enumeración básica con valores automáticos
:linenos:

enum dia_semana {
    LUNES,    // 0
    MARTES,   // 1  
    MIERCOLES,// 2
    JUEVES,   // 3
    VIERNES,  // 4
    SABADO,   // 5
    DOMINGO   // 6
};
```

### Asignación Explícita de Valores

Podés asignar valores específicos a las constantes. Las constantes siguientes continuarán secuencialmente desde el último valor asignado:

```{code-block}c
:caption: Enumeración con valores explícitos
:linenos:

enum codigo_error {
    EXITO = 0,
    ERROR_ARCHIVO = 10,
    ERROR_MEMORIA = 11,    // 11 (10 + 1)
    ERROR_PERMISO = 20,
    ERROR_RED = 21         // 21 (20 + 1)
};
```

### Declaración e Instanciación Simultánea

Podés declarar variables del tipo `enum` al mismo tiempo que defines la enumeración:

```{code-block}c
:caption: Declaración con variables inmediatas
:linenos:

enum color {
    ROJO,
    VERDE, 
    AZUL
} color_favorito, color_coche = ROJO;
```

## Alcance y Namespaces

### Problema de Contaminación del Namespace

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
    APAGADO,    // ❌ Error: redefinición de APAGADO
    PRENDIDO,
    PARPADEANDO
};
```

### Solución con Prefijos

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

## Usos Prácticos y Patrones Comunes

### Estados de Máquinas de Estado Finitas

Las enumeraciones son ideales para representar los estados en máquinas de estado finitas:

```{code-block}c
:caption: Implementación de una máquina de estados
:linenos:

enum conexion_estado {
    CONN_DESCONECTADO,
    CONN_CONECTANDO,
    CONN_CONECTADO,
    CONN_DESCONECTANDO,
    CONN_ERROR
};

enum conexion_estado procesar_conexion(enum conexion_estado estado_actual, 
                                      char evento) {
    switch (estado_actual) {
        case CONN_DESCONECTADO:
            if (evento == 'c') return CONN_CONECTANDO;
            break;
            
        case CONN_CONECTANDO:
            if (evento == 'o') return CONN_CONECTADO;
            if (evento == 'e') return CONN_ERROR;
            break;
            
        case CONN_CONECTADO:
            if (evento == 'd') return CONN_DESCONECTANDO;
            break;
            
        case CONN_DESCONECTANDO:
            if (evento == 'f') return CONN_DESCONECTADO;
            break;
            
        case CONN_ERROR:
            if (evento == 'r') return CONN_DESCONECTADO;
            break;
    }
    return estado_actual;
}
```

### Códigos de Error y Resultado

```{code-block}c
:caption: Sistema de códigos de error robusto
:linenos:

enum resultado {
    RESULTADO_EXITO = 0,
    RESULTADO_ERROR_MEMORIA = -1,
    RESULTADO_ERROR_ARCHIVO = -2,
    RESULTADO_ERROR_ARGUMENTO = -3,
    RESULTADO_ERROR_PERMISO = -4,
    RESULTADO_ERROR_RED = -5
};

enum resultado abrir_archivo(const char *nombre_archivo, FILE **archivo) {
    if (nombre_archivo == NULL || archivo == NULL) {
        return RESULTADO_ERROR_ARGUMENTO;
    }
    
    *archivo = fopen(nombre_archivo, "r");
    if (*archivo == NULL) {
        return RESULTADO_ERROR_ARCHIVO;
    }
    
    return RESULTADO_EXITO;
}
```

### Opciones de Configuración

```{code-block}c
:caption: Configuraciones y modos de operación
:linenos:

enum log_nivel {
    LOG_DEBUG = 0,
    LOG_INFO = 1,
    LOG_ADVERTENCIA = 2,
    LOG_ERROR = 3,
    LOG_CRITICO = 4
};

enum formato_salida {
    FORMATO_TEXTO,
    FORMATO_JSON,
    FORMATO_XML,
    FORMATO_CSV
};

void escribir_log(enum log_nivel nivel, const char *mensaje) {
    const char *nivel_str[] = {
        [LOG_DEBUG] = "DEBUG",
        [LOG_INFO] = "INFO", 
        [LOG_ADVERTENCIA] = "WARN",
        [LOG_ERROR] = "ERROR",
        [LOG_CRITICO] = "CRITICAL"
    };
    
    printf("[%s] %s\n", nivel_str[nivel], mensaje);
}
```

## Mejores Prácticas

### 1. Definir un Valor "Inválido" o "Desconocido"

```{code-block}c
:caption: Incluir estados de error o valores por defecto
:linenos:

enum tipo_vehiculo {
    VEHICULO_DESCONOCIDO = 0,  // Valor por defecto
    VEHICULO_AUTO,
    VEHICULO_MOTO, 
    VEHICULO_CAMION,
    VEHICULO_BUS,
    VEHICULO_CANTIDAD  // Útil para validación y iteración
};

bool es_vehiculo_valido(enum tipo_vehiculo tipo) {
    return tipo > VEHICULO_DESCONOCIDO && tipo < VEHICULO_CANTIDAD;
}
```

### 2. Usar `typedef` para Simplificar la Sintaxis

```{code-block}c
:caption: Simplificación con typedef
:linenos:

typedef enum {
    HTTP_OK = 200,
    HTTP_NOT_FOUND = 404,
    HTTP_INTERNAL_ERROR = 500
} http_status_t;

// Uso más limpio
http_status_t procesar_peticion(void) {
    // ... lógica de procesamiento
    return HTTP_OK;
}
```

### 3. Validación de Valores de Enumeración

```{code-block}c
:caption: Funciones de validación y conversión
:linenos:

typedef enum {
    COLOR_ROJO,
    COLOR_VERDE,
    COLOR_AZUL,
    COLOR_CANTIDAD
} color_t;

const char* color_a_string(color_t color) {
    static const char* nombres[] = {
        [COLOR_ROJO] = "Rojo",
        [COLOR_VERDE] = "Verde", 
        [COLOR_AZUL] = "Azul"
    };
    
    if (color >= COLOR_CANTIDAD) {
        return "Color inválido";
    }
    
    return nombres[color];
}

bool string_a_color(const char* str, color_t* color) {
    if (strcmp(str, "rojo") == 0) {
        *color = COLOR_ROJO;
        return true;
    } else if (strcmp(str, "verde") == 0) {
        *color = COLOR_VERDE;
        return true;
    } else if (strcmp(str, "azul") == 0) {
        *color = COLOR_AZUL;
        return true;
    }
    
    return false;
}
```

## Pitfalls y Errores Comunes

### 1. Comparación Accidental con Enteros

```{code-block}c
:caption: Problema de comparación de tipos
:linenos:

typedef enum { LUNES, MARTES, MIERCOLES } dia_t;

dia_t hoy = MARTES;

// Problemático: compila pero es conceptualmente incorrecto
if (hoy == 1) { 
    printf("Es martes\n");
}

// Correcto: usar la constante de enumeración
if (hoy == MARTES) {
    printf("Es martes\n"); 
}
```

### 2. Asumir Valores Específicos

```{code-block}c
:caption: Dependencia peligrosa de valores numéricos
:linenos:

typedef enum {
    BAJO,     // ¿0?
    MEDIO,    // ¿1?
    ALTO      // ¿2?
} prioridad_t;

// Peligroso: asumir valores específicos
void imprimir_prioridad_mal(prioridad_t p) {
    char* nombres[] = {"Bajo", "Medio", "Alto"};
    printf("%s\n", nombres[p]); // ¿Qué pasa si cambian los valores?
}

// Robusto: verificar rangos
void imprimir_prioridad_bien(prioridad_t p) {
    switch(p) {
        case BAJO:  printf("Bajo\n"); break;
        case MEDIO: printf("Medio\n"); break;
        case ALTO:  printf("Alto\n"); break;
        default:    printf("Prioridad inválida\n"); break;
    }
}
```

### 3. Mezclar Enumeraciones de Diferentes Tipos

```{code-block}c
:caption: Mezcla accidental de tipos de enumeración
:linenos:

typedef enum { ROJO, VERDE, AZUL } color_t;
typedef enum { PEQUEÑO, MEDIANO, GRANDE } tamaño_t;

color_t color = ROJO;
tamaño_t tamaño = GRANDE;

// Compila pero es lógicamente incorrecto
if (color == tamaño) {  // Ambos valen 0 y 2 respectivamente
    printf("¡Coincidencia extraña!\n");
}
```

### 4. No Manejar Todos los Casos en Switch

```{code-block}c
:caption: Switch statements incompletos
:linenos:

typedef enum {
    FORMATO_PDF,
    FORMATO_HTML, 
    FORMATO_DOCX,
    FORMATO_TXT
} formato_documento_t;

// Peligroso: no maneja todos los casos
void exportar_documento_mal(formato_documento_t formato) {
    switch(formato) {
        case FORMATO_PDF:
            generar_pdf();
            break;
        case FORMATO_HTML:
            generar_html();
            break;
        // ¿Qué pasa con FORMATO_DOCX y FORMATO_TXT?
    }
}

// Completo: maneja todos los casos + default
void exportar_documento_bien(formato_documento_t formato) {
    switch(formato) {
        case FORMATO_PDF:
            generar_pdf();
            break;
        case FORMATO_HTML:
            generar_html();
            break;
        case FORMATO_DOCX:
            generar_docx();
            break;
        case FORMATO_TXT:
            generar_txt();
            break;
        default:
            fprintf(stderr, "Formato no soportado: %d\n", formato);
            break;
    }
}
```

## Enumeraciones Avanzadas

### Enumeraciones con Bits (Flags)

Para casos donde querés combinar múltiples opciones, podés usar potencias de 2:

```{code-block}c
:caption: Enumeraciones como flags de bits
:linenos:

typedef enum {
    PERMISO_NINGUNO = 0,
    PERMISO_LECTURA = 1,      // 0001
    PERMISO_ESCRITURA = 2,    // 0010
    PERMISO_EJECUCION = 4,    // 0100
    PERMISO_ADMINISTRADOR = 8 // 1000
} permisos_t;

// Combinación de permisos usando OR bitwise
permisos_t permisos_usuario = PERMISO_LECTURA | PERMISO_ESCRITURA;

// Verificar permisos usando AND bitwise
bool tiene_permiso_lectura(permisos_t permisos) {
    return (permisos & PERMISO_LECTURA) != 0;
}

// Agregar un permiso
permisos_t agregar_permiso(permisos_t permisos, permisos_t nuevo_permiso) {
    return permisos | nuevo_permiso;
}

// Quitar un permiso
permisos_t quitar_permiso(permisos_t permisos, permisos_t permiso_a_quitar) {
    return permisos & (~permiso_a_quitar);
}
```

### Enumeraciones Anónimas para Constantes

```{code-block}c
:caption: Uso de enums anónimas para constantes
:linenos:

// En lugar de #define, usar enum anónima
enum {
    BUFFER_SIZE = 1024,
    MAX_CONEXIONES = 100,
    TIMEOUT_SEGUNDOS = 30
};

// Ventaja: estas constantes tienen tipo int y siguen las reglas de scope de C
```

## Compatibilidad y Portabilidad

### Tamaño de las Enumeraciones

El estándar C no especifica el tamaño de las enumeraciones, pero garantiza que pueden almacenar todos los valores definidos:

```{code-block}c
:caption: Verificación del tamaño de enumeraciones
:linenos:

#include <stdio.h>

typedef enum {
    VALOR_PEQUEÑO = 1,
    VALOR_GRANDE = 100000
} mi_enum_t;

int main() {
    printf("Tamaño de enum: %zu bytes\n", sizeof(mi_enum_t));
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    
    // Generalmente serán iguales, pero no está garantizado
    return 0;
}
```

### Conversiones y Casting

```{code-block}c
:caption: Manejo seguro de conversiones
:linenos:

typedef enum {
    PRIORIDAD_BAJA = 1,
    PRIORIDAD_MEDIA = 5,
    PRIORIDAD_ALTA = 10
} prioridad_t;

// Conversión segura de int a enum
prioridad_t int_a_prioridad(int valor) {
    switch(valor) {
        case 1:  return PRIORIDAD_BAJA;
        case 5:  return PRIORIDAD_MEDIA;  
        case 10: return PRIORIDAD_ALTA;
        default: return (prioridad_t)-1; // Valor de error
    }
}

// Validación antes de usar
bool usar_prioridad(int valor_entrada) {
    prioridad_t p = int_a_prioridad(valor_entrada);
    if (p == (prioridad_t)-1) {
        printf("Valor de prioridad inválido: %d\n", valor_entrada);
        return false;
    }
    
    // Usar p de forma segura...
    return true;
}
```

## Integración con Estructuras

### Enumeraciones como Miembros de Estructuras

```{code-block}c
:caption: Enums en estructuras para modelar entidades complejas
:linenos:

typedef enum {
    VEHICULO_AUTO,
    VEHICULO_MOTO,
    VEHICULO_CAMION
} tipo_vehiculo_t;

typedef enum {
    ESTADO_NUEVO,
    ESTADO_USADO,
    ESTADO_REPARACION
} estado_vehiculo_t;

typedef struct {
    char marca[50];
    char modelo[50];
    int año;
    tipo_vehiculo_t tipo;
    estado_vehiculo_t estado;
    double precio;
} vehiculo_t;

// Función que usa múltiples enumeraciones
double calcular_descuento(const vehiculo_t* vehiculo) {
    double descuento = 0.0;
    
    // Descuento por tipo
    switch(vehiculo->tipo) {
        case VEHICULO_AUTO:
            descuento = 0.05; // 5%
            break;
        case VEHICULO_MOTO:
            descuento = 0.10; // 10%
            break;
        case VEHICULO_CAMION:
            descuento = 0.03; // 3%
            break;
    }
    
    // Descuento adicional por estado
    if (vehiculo->estado == ESTADO_USADO) {
        descuento += 0.15; // 15% adicional
    }
    
    return descuento;
}
```

## Debugging y Herramientas de Desarrollo

### Funciones de Debug para Enumeraciones

```{code-block}c
:caption: Utilidades de debugging
:linenos:

typedef enum {
    ESTADO_INICIALIZANDO,
    ESTADO_PROCESANDO,
    ESTADO_COMPLETADO,
    ESTADO_ERROR
} estado_tarea_t;

#ifdef DEBUG
const char* estado_a_string_debug(estado_tarea_t estado) {
    switch(estado) {
        case ESTADO_INICIALIZANDO: return "INICIALIZANDO";
        case ESTADO_PROCESANDO: return "PROCESANDO";
        case ESTADO_COMPLETADO: return "COMPLETADO";
        case ESTADO_ERROR: return "ERROR";
        default: return "ESTADO_DESCONOCIDO";
    }
}

#define DEBUG_PRINT_ESTADO(estado) \
    printf("[DEBUG] Estado actual: %s (%d)\n", estado_a_string_debug(estado), estado)
#else
#define DEBUG_PRINT_ESTADO(estado) ((void)0)
#endif

// Uso en el código
void procesar_tarea(void) {
    estado_tarea_t estado = ESTADO_INICIALIZANDO;
    DEBUG_PRINT_ESTADO(estado);
    
    // ... lógica de procesamiento
    estado = ESTADO_PROCESANDO;
    DEBUG_PRINT_ESTADO(estado);
    
    // ...
}
```

## Ejercicios

```{exercise}
:label: enum-basico
:enumerator: enum-1

Creá una enumeración para representar los días de la semana y escribí una función que determine si un día dado es fin de semana o no.

**Requisitos:**
- Usar nombres descriptivos para las constantes
- La función debe retornar `bool`
- Manejar casos de entrada inválida
```

````{solution} enum-basico
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

bool es_fin_de_semana(dia_semana_t dia) {
    switch(dia) {
        case SABADO:
        case DOMINGO:
            return true;
        case LUNES:
        case MARTES:
        case MIERCOLES:
        case JUEVES:
        case VIERNES:
            return false;
        default:
            printf("Error: día inválido (%d)\n", dia);
            return false;
    }
}

const char* dia_a_string(dia_semana_t dia) {
    switch(dia) {
        case LUNES: return "Lunes";
        case MARTES: return "Martes";
        case MIERCOLES: return "Miércoles";
        case JUEVES: return "Jueves";
        case VIERNES: return "Viernes";
        case SABADO: return "Sábado";
        case DOMINGO: return "Domingo";
        default: return "Día inválido";
    }
}

int main() {
    dia_semana_t hoy = VIERNES;
    
    printf("Hoy es %s\n", dia_a_string(hoy));
    
    if (es_fin_de_semana(hoy)) {
        printf("¡Es fin de semana! 🎉\n");
    } else {
        printf("Es día laboral 💼\n");
    }
    
    return 0;
}
```
````

```{exercise}
:label: enum-maquina-estados
:enumerator: enum-2

Implementá una máquina de estados simple para un semáforo que tenga los estados: ROJO, AMARILLO, VERDE. Creá una función que simule el cambio de estado según la secuencia normal de un semáforo.

**Especificaciones:**
- ROJO → VERDE
- VERDE → AMARILLO  
- AMARILLO → ROJO
- Incluir función para obtener el siguiente estado
- Incluir función para imprimir el estado actual
```

````{solution} enum-maquina-estados  
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <unistd.h> // Para sleep()

typedef enum {
    SEMAFORO_ROJO,
    SEMAFORO_AMARILLO,
    SEMAFORO_VERDE
} estado_semaforo_t;

estado_semaforo_t siguiente_estado(estado_semaforo_t estado_actual) {
    switch(estado_actual) {
        case SEMAFORO_ROJO:
            return SEMAFORO_VERDE;
        case SEMAFORO_VERDE:
            return SEMAFORO_AMARILLO;
        case SEMAFORO_AMARILLO:
            return SEMAFORO_ROJO;
        default:
            printf("Error: estado de semáforo inválido\n");
            return SEMAFORO_ROJO; // Estado seguro por defecto
    }
}

void imprimir_estado(estado_semaforo_t estado) {
    switch(estado) {
        case SEMAFORO_ROJO:
            printf("🔴 ROJO - ALTO\n");
            break;
        case SEMAFORO_AMARILLO:
            printf("🟡 AMARILLO - PRECAUCIÓN\n");
            break;
        case SEMAFORO_VERDE:
            printf("🟢 VERDE - AVANZAR\n");
            break;
        default:
            printf("❌ ESTADO INVÁLIDO\n");
            break;
    }
}

int obtener_duracion(estado_semaforo_t estado) {
    switch(estado) {
        case SEMAFORO_ROJO:     return 5; // 5 segundos
        case SEMAFORO_VERDE:    return 8; // 8 segundos
        case SEMAFORO_AMARILLO: return 2; // 2 segundos
        default:                return 1;
    }
}

void simular_semaforo(int ciclos) {
    estado_semaforo_t estado_actual = SEMAFORO_ROJO;
    
    for (int ciclo = 0; ciclo < ciclos; ciclo++) {
        printf("\n--- Ciclo %d ---\n", ciclo + 1);
        
        for (int cambio = 0; cambio < 3; cambio++) {
            imprimir_estado(estado_actual);
            
            int duracion = obtener_duracion(estado_actual);
            printf("Esperando %d segundos...\n", duracion);
            sleep(duracion);
            
            estado_actual = siguiente_estado(estado_actual);
        }
    }
}

int main() {
    printf("=== SIMULADOR DE SEMÁFORO ===\n");
    simular_semaforo(2); // 2 ciclos completos
    
    return 0;
}
```
````

```{exercise}
:label: enum-flags
:enumerator: enum-3

Creá un sistema de permisos usando enumeraciones como flags de bits. Implementá funciones para:
- Verificar si un usuario tiene un permiso específico
- Agregar un permiso a un usuario
- Quitar un permiso de un usuario  
- Listar todos los permisos de un usuario

**Permisos a implementar:**
- Lectura
- Escritura  
- Ejecución
- Administración
```

````{solution} enum-flags
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    PERMISO_NINGUNO = 0,
    PERMISO_LECTURA = 1,        // 0001
    PERMISO_ESCRITURA = 2,      // 0010
    PERMISO_EJECUCION = 4,      // 0100
    PERMISO_ADMINISTRACION = 8  // 1000
} permisos_t;

bool tiene_permiso(permisos_t permisos, permisos_t permiso_consulta) {
    return (permisos & permiso_consulta) != 0;
}

permisos_t agregar_permiso(permisos_t permisos, permisos_t nuevo_permiso) {
    return permisos | nuevo_permiso;
}

permisos_t quitar_permiso(permisos_t permisos, permisos_t permiso_a_quitar) {
    return permisos & (~permiso_a_quitar);
}

void listar_permisos(permisos_t permisos) {
    printf("Permisos activos:\n");
    
    if (permisos == PERMISO_NINGUNO) {
        printf("  - Ningún permiso\n");
        return;
    }
    
    if (tiene_permiso(permisos, PERMISO_LECTURA)) {
        printf("  - Lectura\n");
    }
    
    if (tiene_permiso(permisos, PERMISO_ESCRITURA)) {
        printf("  - Escritura\n");
    }
    
    if (tiene_permiso(permisos, PERMISO_EJECUCION)) {
        printf("  - Ejecución\n");
    }
    
    if (tiene_permiso(permisos, PERMISO_ADMINISTRACION)) {
        printf("  - Administración\n");
    }
}

const char* permiso_a_string(permisos_t permiso) {
    switch(permiso) {
        case PERMISO_LECTURA: return "Lectura";
        case PERMISO_ESCRITURA: return "Escritura";
        case PERMISO_EJECUCION: return "Ejecución";
        case PERMISO_ADMINISTRACION: return "Administración";
        default: return "Permiso desconocido";
    }
}

void demostrar_sistema_permisos(void) {
    printf("=== DEMO: SISTEMA DE PERMISOS ===\n\n");
    
    // Usuario inicial sin permisos
    permisos_t usuario = PERMISO_NINGUNO;
    printf("Usuario inicial:\n");
    listar_permisos(usuario);
    
    // Agregar permisos básicos
    printf("\n--- Agregando permisos de lectura y escritura ---\n");
    usuario = agregar_permiso(usuario, PERMISO_LECTURA);
    usuario = agregar_permiso(usuario, PERMISO_ESCRITURA);
    listar_permisos(usuario);
    
    // Verificar permisos específicos
    printf("\n--- Verificando permisos ---\n");
    printf("¿Tiene permiso de lectura? %s\n", 
           tiene_permiso(usuario, PERMISO_LECTURA) ? "SÍ" : "NO");
    printf("¿Tiene permiso de ejecución? %s\n", 
           tiene_permiso(usuario, PERMISO_EJECUCION) ? "SÍ" : "NO");
    
    // Agregar más permisos
    printf("\n--- Promoviendo a administrador ---\n");
    usuario = agregar_permiso(usuario, PERMISO_ADMINISTRACION);
    usuario = agregar_permiso(usuario, PERMISO_EJECUCION);
    listar_permisos(usuario);
    
    // Quitar un permiso
    printf("\n--- Quitando permiso de escritura ---\n");
    usuario = quitar_permiso(usuario, PERMISO_ESCRITURA);
    listar_permisos(usuario);
}

int main() {
    demostrar_sistema_permisos();
    return 0;
}
```
````

## Resumen

Las enumeraciones son una herramienta poderosa para escribir código más legible, mantenible y menos propenso a errores. Key takeaways:

:::{important} Puntos clave sobre enumeraciones

**Ventajas principales:**
- **Legibilidad:** Reemplazan números mágicos con nombres significativos
- **Mantenibilidad:** Cambios centralizados en la definición
- **Detección de errores:** El compilador puede detectar algunos errores de tipo
- **Documentación:** Las enumeraciones sirven como documentación del código

**Mejores prácticas:**
- Usar prefijos para evitar colisiones de nombres
- Incluir valores para casos inválidos o desconocidos
- Validar entradas antes de usar enumeraciones
- Manejar todos los casos en declaraciones `switch`
- Considerar `typedef` para simplificar la sintaxis

**Casos de uso comunes:**
- Estados de máquinas de estados finitas
- Códigos de error y resultado
- Configuraciones y opciones
- Flags de bits para permisos o características
- Tipos categóricos del dominio del problema
:::