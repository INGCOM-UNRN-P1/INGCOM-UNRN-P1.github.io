---
title: "Códigos de Error con Múltiples Causas"
short_title: "Errores Múltiples"
subtitle: "Manejo de errores compuestos mediante bitmasks"
---

## Introducción

En muchas situaciones reales, una operación puede fallar por múltiples razones simultáneas. Por ejemplo, al validar datos de un formulario, pueden existir varios campos inválidos al mismo tiempo. Reportar solo el primer error obliga al usuario a corregir y reintentar múltiples veces. Una mejor solución es reportar **todas** las causas de error simultáneamente.

Este apunte presenta técnicas para manejar múltiples códigos de error usando **bitmasks con enumeraciones**, permitiendo representar y comunicar combinaciones de errores de forma eficiente y expresiva.

:::{important} Errores Compuestos
Cuando múltiples validaciones pueden fallar independientemente, es más útil reportar todas las fallas simultáneamente en lugar de forzar al usuario a corregir de a uno. Las bitmasks permiten representar combinaciones de errores en un solo valor entero.
:::

## Problema: Un Solo Código de Error

### Enfoque Tradicional (Un Error)

```c
typedef enum {
    ERROR_NINGUNO = 0,
    ERROR_NOMBRE_VACIO,
    ERROR_EMAIL_INVALIDO,
    ERROR_EDAD_FUERA_RANGO,
    ERROR_TELEFONO_INVALIDO
} error_validacion_t;

error_validacion_t validar_usuario(const usuario_t* usuario) {
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0) {
        return ERROR_NOMBRE_VACIO;  // Retorna solo el primero
    }
    
    if (!es_email_valido(usuario->email)) {
        return ERROR_EMAIL_INVALIDO;  // Nunca llega aquí si nombre falla
    }
    
    if (usuario->edad < 18 || usuario->edad > 120) {
        return ERROR_EDAD_FUERA_RANGO;
    }
    
    if (!es_telefono_valido(usuario->telefono)) {
        return ERROR_TELEFONO_INVALIDO;
    }
    
    return ERROR_NINGUNO;
}
```

**Problema:** Si el nombre está vacío Y el email es inválido, el usuario solo sabrá del nombre. Deberá corregir y volver a intentar para descubrir el siguiente error.

## Solución: Códigos de Error con Bitmasks

### Definición con Potencias de 2

Para representar múltiples errores simultáneamente, cada código de error debe ser una potencia de 2 (un único bit activado):

```c
typedef enum {
    ERROR_NINGUNO           = 0,      // 0b00000000
    ERROR_NOMBRE_VACIO      = 1 << 0, // 0b00000001
    ERROR_EMAIL_INVALIDO    = 1 << 1, // 0b00000010
    ERROR_EDAD_FUERA_RANGO  = 1 << 2, // 0b00000100
    ERROR_TELEFONO_INVALIDO = 1 << 3, // 0b00001000
    ERROR_DNI_INVALIDO      = 1 << 4, // 0b00010000
    ERROR_DIRECCION_VACIA   = 1 << 5, // 0b00100000
    ERROR_CIUDAD_INVALIDA   = 1 << 6  // 0b01000000
} errores_validacion_t;

// Tipo para almacenar combinaciones
typedef unsigned int errores_t;
```

### Acumular Múltiples Errores

```c
errores_t validar_usuario(const usuario_t* usuario) {
    errores_t errores = ERROR_NINGUNO;
    
    // Validar cada campo independientemente
    if (usuario->nombre == NULL || strlen(usuario->nombre) == 0) {
        errores |= ERROR_NOMBRE_VACIO;  // OR para acumular
    }
    
    if (!es_email_valido(usuario->email)) {
        errores |= ERROR_EMAIL_INVALIDO;
    }
    
    if (usuario->edad < 18 || usuario->edad > 120) {
        errores |= ERROR_EDAD_FUERA_RANGO;
    }
    
    if (!es_telefono_valido(usuario->telefono)) {
        errores |= ERROR_TELEFONO_INVALIDO;
    }
    
    if (!es_dni_valido(usuario->dni)) {
        errores |= ERROR_DNI_INVALIDO;
    }
    
    return errores;
}
```

### Verificar Presencia de Errores

```c
// Verificar si hay algún error
bool hay_errores(errores_t errores) {
    return errores != ERROR_NINGUNO;
}

// Verificar un error específico
bool tiene_error(errores_t errores, errores_validacion_t error_especifico) {
    return (errores & error_especifico) != 0;
}

// Uso
errores_t resultado = validar_usuario(&usuario);

if (hay_errores(resultado)) {
    if (tiene_error(resultado, ERROR_NOMBRE_VACIO)) {
        printf("Error: El nombre no puede estar vacío\n");
    }
    
    if (tiene_error(resultado, ERROR_EMAIL_INVALIDO)) {
        printf("Error: El formato del email es inválido\n");
    }
    
    if (tiene_error(resultado, ERROR_EDAD_FUERA_RANGO)) {
        printf("Error: La edad debe estar entre 18 y 120\n");
    }
}
```

## Operaciones con Bitmasks de Error

### Agregar Errores

```c
errores_t errores = ERROR_NINGUNO;

// Agregar un error
errores |= ERROR_NOMBRE_VACIO;

// Agregar múltiples errores a la vez
errores |= (ERROR_EMAIL_INVALIDO | ERROR_EDAD_FUERA_RANGO);
```

### Remover Errores

```c
// Remover un error específico
errores &= ~ERROR_EMAIL_INVALIDO;

// Remover múltiples errores
errores &= ~(ERROR_NOMBRE_VACIO | ERROR_DNI_INVALIDO);
```

### Alternar (Toggle) Errores

```c
// Alternar un error (si está, lo quita; si no está, lo agrega)
errores ^= ERROR_TELEFONO_INVALIDO;
```

### Verificar Todos o Alguno

```c
// Verificar si TODOS los errores especificados están presentes
bool tiene_todos(errores_t errores, errores_t conjunto) {
    return (errores & conjunto) == conjunto;
}

// Verificar si ALGUNO de los errores está presente
bool tiene_alguno(errores_t errores, errores_t conjunto) {
    return (errores & conjunto) != 0;
}

// Uso
if (tiene_todos(resultado, ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO)) {
    printf("Faltan tanto nombre como email\n");
}

if (tiene_alguno(resultado, ERROR_EDAD_FUERA_RANGO | ERROR_DNI_INVALIDO)) {
    printf("Problema con edad o DNI\n");
}
```

### Contar Errores

```c
int contar_errores(errores_t errores) {
    int contador = 0;
    
    // Contar bits activados
    while (errores) {
        contador += errores & 1;
        errores >>= 1;
    }
    
    return contador;
}

// Alternativa más eficiente (GCC builtin)
int contar_errores_rapido(errores_t errores) {
    return __builtin_popcount(errores);
}
```

## Casos Prácticos

### Caso 1: Validación de Formulario Web

```c
typedef enum {
    ERROR_FORM_NINGUNO          = 0,
    ERROR_FORM_USUARIO_VACIO    = 1 << 0,
    ERROR_FORM_PASSWORD_CORTO   = 1 << 1,
    ERROR_FORM_PASSWORD_DEBIL   = 1 << 2,
    ERROR_FORM_EMAIL_INVALIDO   = 1 << 3,
    ERROR_FORM_EDAD_INVALIDA    = 1 << 4,
    ERROR_FORM_TERMINOS_NO_ACEPTADOS = 1 << 5
} errores_formulario_t;

errores_t validar_registro(const formulario_registro_t* form) {
    errores_t errores = ERROR_FORM_NINGUNO;
    
    if (form->usuario == NULL || strlen(form->usuario) < 3) {
        errores |= ERROR_FORM_USUARIO_VACIO;
    }
    
    if (form->password == NULL || strlen(form->password) < 8) {
        errores |= ERROR_FORM_PASSWORD_CORTO;
    } else if (!password_es_fuerte(form->password)) {
        errores |= ERROR_FORM_PASSWORD_DEBIL;
    }
    
    if (!es_email_valido(form->email)) {
        errores |= ERROR_FORM_EMAIL_INVALIDO;
    }
    
    if (form->edad < 13) {
        errores |= ERROR_FORM_EDAD_INVALIDA;
    }
    
    if (!form->acepta_terminos) {
        errores |= ERROR_FORM_TERMINOS_NO_ACEPTADOS;
    }
    
    return errores;
}

void mostrar_errores_formulario(errores_t errores) {
    if (errores == ERROR_FORM_NINGUNO) {
        printf("Formulario válido\n");
        return;
    }
    
    printf("Errores en el formulario:\n");
    
    if (errores & ERROR_FORM_USUARIO_VACIO) {
        printf("  - El nombre de usuario debe tener al menos 3 caracteres\n");
    }
    
    if (errores & ERROR_FORM_PASSWORD_CORTO) {
        printf("  - La contraseña debe tener al menos 8 caracteres\n");
    }
    
    if (errores & ERROR_FORM_PASSWORD_DEBIL) {
        printf("  - La contraseña debe contener mayúsculas, minúsculas y números\n");
    }
    
    if (errores & ERROR_FORM_EMAIL_INVALIDO) {
        printf("  - El formato del email es inválido\n");
    }
    
    if (errores & ERROR_FORM_EDAD_INVALIDA) {
        printf("  - Debe ser mayor de 13 años para registrarse\n");
    }
    
    if (errores & ERROR_FORM_TERMINOS_NO_ACEPTADOS) {
        printf("  - Debe aceptar los términos y condiciones\n");
    }
}
```

### Caso 2: Verificación de Permisos

```c
typedef enum {
    PERMISO_NINGUNO      = 0,
    PERMISO_LEER         = 1 << 0,  // 0b00000001
    PERMISO_ESCRIBIR     = 1 << 1,  // 0b00000010
    PERMISO_EJECUTAR     = 1 << 2,  // 0b00000100
    PERMISO_ELIMINAR     = 1 << 3,  // 0b00001000
    PERMISO_COMPARTIR    = 1 << 4,  // 0b00010000
    PERMISO_ADMIN        = 1 << 5   // 0b00100000
} permisos_t;

typedef unsigned int permisos_usuario_t;

// Constantes útiles
const permisos_usuario_t PERMISOS_LECTURA_ESCRITURA = 
    PERMISO_LEER | PERMISO_ESCRIBIR;

const permisos_usuario_t PERMISOS_COMPLETOS = 
    PERMISO_LEER | PERMISO_ESCRIBIR | PERMISO_EJECUTAR | 
    PERMISO_ELIMINAR | PERMISO_COMPARTIR;

bool puede_realizar_accion(permisos_usuario_t permisos_usuario, 
                           permisos_t permiso_requerido) {
    return (permisos_usuario & permiso_requerido) == permiso_requerido;
}

permisos_usuario_t otorgar_permiso(permisos_usuario_t actual, 
                                     permisos_t nuevo_permiso) {
    return actual | nuevo_permiso;
}

permisos_usuario_t revocar_permiso(permisos_usuario_t actual, 
                                     permisos_t permiso_a_revocar) {
    return actual & ~permiso_a_revocar;
}

// Uso
permisos_usuario_t mis_permisos = PERMISO_LEER | PERMISO_ESCRIBIR;

if (puede_realizar_accion(mis_permisos, PERMISO_ELIMINAR)) {
    eliminar_archivo();
} else {
    printf("No tienes permiso para eliminar\n");
}

// Otorgar permiso de ejecución
mis_permisos = otorgar_permiso(mis_permisos, PERMISO_EJECUTAR);

// Revocar permiso de escritura
mis_permisos = revocar_permiso(mis_permisos, PERMISO_ESCRIBIR);
```

### Caso 3: Estado de Conexión de Red

```c
typedef enum {
    RED_OK               = 0,
    RED_SIN_CONEXION     = 1 << 0,
    RED_TIMEOUT          = 1 << 1,
    RED_DNS_FALLO        = 1 << 2,
    RED_SSL_ERROR        = 1 << 3,
    RED_CERTIFICADO_INVALIDO = 1 << 4,
    RED_PUERTO_BLOQUEADO = 1 << 5,
    RED_PROXY_ERROR      = 1 << 6
} errores_red_t;

typedef struct {
    errores_t errores;
    int codigo_http;
    char* mensaje;
} resultado_conexion_t;

resultado_conexion_t conectar_servidor(const char* url) {
    resultado_conexion_t resultado = {
        .errores = RED_OK,
        .codigo_http = 0,
        .mensaje = NULL
    };
    
    // Intentar resolver DNS
    if (!resolver_dns(url)) {
        resultado.errores |= RED_DNS_FALLO;
    }
    
    // Verificar conectividad básica
    if (!hay_conexion_internet()) {
        resultado.errores |= RED_SIN_CONEXION;
    }
    
    // Intentar conexión
    if (!conectar_con_timeout(url, 5000)) {
        resultado.errores |= RED_TIMEOUT;
    }
    
    // Verificar SSL si es HTTPS
    if (es_https(url) && !verificar_ssl(url)) {
        resultado.errores |= RED_SSL_ERROR;
        
        if (!certificado_valido(url)) {
            resultado.errores |= RED_CERTIFICADO_INVALIDO;
        }
    }
    
    return resultado;
}

void diagnosticar_conexion(const resultado_conexion_t* resultado) {
    if (resultado->errores == RED_OK) {
        printf("Conexión exitosa\n");
        return;
    }
    
    printf("Problemas detectados:\n");
    
    if (resultado->errores & RED_SIN_CONEXION) {
        printf("  [CRÍTICO] No hay conexión a Internet\n");
    }
    
    if (resultado->errores & RED_DNS_FALLO) {
        printf("  [ERROR] No se pudo resolver el nombre de dominio\n");
    }
    
    if (resultado->errores & RED_TIMEOUT) {
        printf("  [ERROR] Tiempo de espera agotado\n");
    }
    
    if (resultado->errores & RED_SSL_ERROR) {
        printf("  [ADVERTENCIA] Error en la conexión SSL\n");
    }
    
    if (resultado->errores & RED_CERTIFICADO_INVALIDO) {
        printf("  [ADVERTENCIA] El certificado no es válido o ha expirado\n");
    }
    
    // Sugerencias según la combinación
    if ((resultado->errores & RED_SIN_CONEXION) && 
        (resultado->errores & RED_DNS_FALLO)) {
        printf("\nSugerencia: Verifica tu conexión de red\n");
    } else if (resultado->errores & RED_CERTIFICADO_INVALIDO) {
        printf("\nSugerencia: Verifica la fecha del sistema\n");
    }
}
```

### Caso 4: Validación de Documento

```c
typedef enum {
    DOC_VALIDO               = 0,
    DOC_ENCABEZADO_INVALIDO  = 1 << 0,
    DOC_FORMATO_CORRUPTO     = 1 << 1,
    DOC_VERSION_NO_SOPORTADA = 1 << 2,
    DOC_FIRMA_INVALIDA       = 1 << 3,
    DOC_CHECKSUM_ERROR       = 1 << 4,
    DOC_METADATOS_FALTANTES  = 1 << 5,
    DOC_CONTENIDO_TRUNCADO   = 1 << 6
} errores_documento_t;

errores_t validar_documento(const documento_t* doc) {
    errores_t errores = DOC_VALIDO;
    
    // Validaciones independientes
    if (!validar_encabezado(doc)) {
        errores |= DOC_ENCABEZADO_INVALIDO;
    }
    
    if (!validar_formato(doc)) {
        errores |= DOC_FORMATO_CORRUPTO;
    }
    
    if (doc->version > VERSION_MAX_SOPORTADA) {
        errores |= DOC_VERSION_NO_SOPORTADA;
    }
    
    if (!verificar_firma_digital(doc)) {
        errores |= DOC_FIRMA_INVALIDA;
    }
    
    if (!verificar_checksum(doc)) {
        errores |= DOC_CHECKSUM_ERROR;
    }
    
    if (!tiene_metadatos_requeridos(doc)) {
        errores |= DOC_METADATOS_FALTANTES;
    }
    
    if (doc->tamanio_real < doc->tamanio_esperado) {
        errores |= DOC_CONTENIDO_TRUNCADO;
    }
    
    return errores;
}

bool es_error_critico(errores_t errores) {
    // Errores que impiden procesar el documento
    const errores_t ERRORES_CRITICOS = 
        DOC_FORMATO_CORRUPTO | DOC_CHECKSUM_ERROR | DOC_CONTENIDO_TRUNCADO;
    
    return (errores & ERRORES_CRITICOS) != 0;
}

bool es_error_recuperable(errores_t errores) {
    // Errores que permiten continuar con precaución
    const errores_t ERRORES_RECUPERABLES = 
        DOC_METADATOS_FALTANTES | DOC_VERSION_NO_SOPORTADA;
    
    return (errores & ERRORES_RECUPERABLES) != 0 && !es_error_critico(errores);
}
```

## Funciones Auxiliares Genéricas

### Conversión a Cadenas

```c
typedef struct {
    errores_validacion_t codigo;
    const char* mensaje;
} mapeo_error_t;

const mapeo_error_t MENSAJES_ERROR[] = {
    {ERROR_NOMBRE_VACIO, "El nombre no puede estar vacío"},
    {ERROR_EMAIL_INVALIDO, "Formato de email inválido"},
    {ERROR_EDAD_FUERA_RANGO, "La edad debe estar entre 18 y 120"},
    {ERROR_TELEFONO_INVALIDO, "Formato de teléfono inválido"},
    {ERROR_DNI_INVALIDO, "DNI inválido"},
    {ERROR_DIRECCION_VACIA, "La dirección no puede estar vacía"},
    {ERROR_CIUDAD_INVALIDA, "Ciudad no válida"}
};

void imprimir_errores(errores_t errores) {
    if (errores == ERROR_NINGUNO) {
        printf("Sin errores\n");
        return;
    }
    
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    
    printf("Errores encontrados:\n");
    for (int i = 0; i < num_errores; i++) {
        if (errores & MENSAJES_ERROR[i].codigo) {
            printf("  - %s\n", MENSAJES_ERROR[i].mensaje);
        }
    }
}
```

### Construcción de JSON con Errores

```c
char* errores_a_json(errores_t errores) {
    if (errores == ERROR_NINGUNO) {
        return strdup("{\"errores\": []}");
    }
    
    // Buffer dinámico (simplificado)
    char buffer[1024] = "{\"errores\": [";
    bool primero = true;
    
    const int num_errores = sizeof(MENSAJES_ERROR) / sizeof(MENSAJES_ERROR[0]);
    
    for (int i = 0; i < num_errores; i++) {
        if (errores & MENSAJES_ERROR[i].codigo) {
            if (!primero) {
                strcat(buffer, ", ");
            }
            strcat(buffer, "\"");
            strcat(buffer, MENSAJES_ERROR[i].mensaje);
            strcat(buffer, "\"");
            primero = false;
        }
    }
    
    strcat(buffer, "]}");
    return strdup(buffer);
}
```

## Límites y Consideraciones

### Número Máximo de Errores

Con un `unsigned int` (32 bits), podés representar hasta **32 errores diferentes**. Si necesitás más:

```c
// Para 64 errores
typedef unsigned long long errores_extendido_t;

typedef enum {
    ERROR_1  = 1ULL << 0,
    ERROR_2  = 1ULL << 1,
    // ...
    ERROR_64 = 1ULL << 63
} errores_64_t;
```

### Arrays de Bitmasks

Para sistemas muy complejos con cientos de posibles errores:

```c
#define NUM_PALABRAS_ERROR 4  // 4 * 32 = 128 errores posibles

typedef struct {
    unsigned int palabras[NUM_PALABRAS_ERROR];
} errores_multiples_t;

void agregar_error(errores_multiples_t* errores, int numero_error) {
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    
    if (palabra < NUM_PALABRAS_ERROR) {
        errores->palabras[palabra] |= (1U << bit);
    }
}

bool tiene_error_multiples(const errores_multiples_t* errores, int numero_error) {
    int palabra = numero_error / 32;
    int bit = numero_error % 32;
    
    if (palabra < NUM_PALABRAS_ERROR) {
        return (errores->palabras[palabra] & (1U << bit)) != 0;
    }
    
    return false;
}
```

## Buenas Prácticas

### 1. Documentar los Códigos

```c
/**
 * Códigos de error para validación de usuarios.
 * Pueden combinarse usando OR bitwise (|).
 * 
 * Ejemplo:
 *   errores_t resultado = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
 */
typedef enum {
    ERROR_NINGUNO           = 0,      ///< Sin errores
    ERROR_NOMBRE_VACIO      = 1 << 0, ///< Nombre NULL o vacío
    ERROR_EMAIL_INVALIDO    = 1 << 1, ///< Formato email inválido
    ERROR_EDAD_FUERA_RANGO  = 1 << 2  ///< Edad < 18 o > 120
} errores_validacion_t;
```

### 2. Usar Nombres Descriptivos

```c
// Bien: nombres claros
ERROR_NOMBRE_VACIO
ERROR_EMAIL_INVALIDO

// Mal: nombres crípticos
ERR_1
ERR_NOM
E_MAIL
```

### 3. Agrupar Errores Relacionados

```c
// Errores de entrada
const errores_t ERRORES_ENTRADA = 
    ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO | ERROR_DNI_INVALIDO;

// Errores de rango
const errores_t ERRORES_RANGO = 
    ERROR_EDAD_FUERA_RANGO | ERROR_FECHA_INVALIDA;

// Verificar grupo
if (errores & ERRORES_ENTRADA) {
    printf("Hay problemas con los datos de entrada\n");
}
```

### 4. Separar Errores de Advertencias

```c
typedef enum {
    // Errores (bits 0-15)
    ERROR_NOMBRE_VACIO      = 1 << 0,
    ERROR_EMAIL_INVALIDO    = 1 << 1,
    
    // Advertencias (bits 16-31)
    WARN_PASSWORD_DEBIL     = 1 << 16,
    WARN_NOMBRE_LARGO       = 1 << 17
} validacion_t;

const validacion_t MASCARA_ERRORES = 0x0000FFFF;
const validacion_t MASCARA_ADVERTENCIAS = 0xFFFF0000;

bool solo_advertencias(validacion_t resultado) {
    return (resultado & MASCARA_ERRORES) == 0 && 
           (resultado & MASCARA_ADVERTENCIAS) != 0;
}
```

## Comparación con Alternativas

### vs. Array de Códigos

**Bitmask:**
```c
errores_t errores = ERROR_NOMBRE_VACIO | ERROR_EMAIL_INVALIDO;
// Tamaño: 4 bytes (un int)
// Verificación: O(1)
```

**Array:**
```c
int errores[] = {ERROR_NOMBRE_VACIO, ERROR_EMAIL_INVALIDO};
int num_errores = 2;
// Tamaño: 8+ bytes (dos ints + contador)
// Verificación: O(n)
```

### vs. Lista Enlazada

**Bitmask:**
- Tamaño fijo y predecible
- No requiere memoria dinámica
- Operaciones muy rápidas
- Limitado a número fijo de errores

**Lista:**
- Tamaño variable
- Requiere malloc/free
- Operaciones más lentas
- Ilimitado número de errores

## Integración con Otros Patrones

### Con Único Retorno

```c
errores_t procesar_formulario(const formulario_t* form) {
    errores_t resultado = ERROR_NINGUNO;
    
    // Acumular errores
    resultado |= validar_campos(form);
    resultado |= validar_formato(form);
    resultado |= validar_coherencia(form);
    
    // Único retorno con todos los errores acumulados
    return resultado;
}
```

### Con Códigos de Estado

```c
typedef struct {
    bool exito;
    errores_t errores;
    void* datos;
} resultado_operacion_t;

resultado_operacion_t realizar_operacion(const datos_t* entrada) {
    resultado_operacion_t resultado = {
        .exito = false,
        .errores = ERROR_NINGUNO,
        .datos = NULL
    };
    
    resultado.errores = validar_entrada(entrada);
    
    if (resultado.errores == ERROR_NINGUNO) {
        resultado.datos = procesar(entrada);
        resultado.exito = (resultado.datos != NULL);
    }
    
    return resultado;
}
```

## Resumen

**Ventajas de códigos de error con bitmasks:**

1. **Eficiencia:** Representar múltiples errores en un solo entero
2. **Expresividad:** Operaciones bitwise claras y concisas
3. **Completitud:** Reportar todos los problemas simultáneamente
4. **Flexibilidad:** Combinar, agregar, remover errores fácilmente
5. **Performance:** Operaciones muy rápidas (solo operaciones de bits)

**Cuándo usar:**
- Validaciones con múltiples campos independientes
- Permisos y flags de estado
- Diagnóstico de problemas complejos
- APIs que deben reportar errores detallados

**Cuándo evitar:**
- Si solo hay un posible error a la vez
- Cuando necesitás más de 32-64 códigos diferentes
- Si la información del error es muy compleja (usa estructuras)

Los códigos de error con bitmasks son una herramienta poderosa para mejorar la usabilidad de APIs y aplicaciones, permitiendo comunicar de forma eficiente y completa todas las causas de un problema.
