---
title: "Refactorización de Código Duplicado"
short_title: "Don't Repeat Yourself [DRY]"
subtitle: "Eliminación de duplicación mediante extracción y abstracción"
---

## Introducción

La duplicación de código es uno de los problemas más comunes y perjudiciales en el desarrollo de software. Cada fragmento de código duplicado representa una oportunidad para inconsistencias, bugs y dificultad en el mantenimiento. El principio **DRY (Don't Repeat Yourself)** establece que "cada pieza de conocimiento debe tener una representación única, inequívoca y autoritativa dentro del sistema".

Este apunte presenta técnicas sistemáticas para identificar y eliminar duplicación, mejorando la mantenibilidad, consistencia y calidad general del código.

:::{important} Principio DRY
La duplicación de código multiplica el esfuerzo de mantenimiento y aumenta la probabilidad de inconsistencias. Cada vez que modificás código duplicado, debés recordar modificar todas sus copias. Como establece {ref}`0x0000h`, la claridad y mantenibilidad son fundamentales.
:::

## Tipos de Duplicación

### 1. Duplicación Literal

Código idéntico copiado y pegado.

```c
// Problemático: mismo código en múltiples lugares
void procesar_usuario_web(usuario_t* u) {
    if (u == NULL) {
        log_error("Usuario NULL");
        return;
    }
    if (!u->activo) {
        log_error("Usuario inactivo");
        return;
    }
    if (u->bloqueado) {
        log_error("Usuario bloqueado");
        return;
    }
    // procesar...
}

void procesar_usuario_api(usuario_t* u) {
    if (u == NULL) {
        log_error("Usuario NULL");
        return;
    }
    if (!u->activo) {
        log_error("Usuario inactivo");
        return;
    }
    if (u->bloqueado) {
        log_error("Usuario bloqueado");
        return;
    }
    // procesar...
}
```

### 2. Duplicación Estructural

Código con estructura similar pero diferentes detalles.

```c
// Problemático: estructura duplicada
double calcular_precio_estudiante(int cantidad) {
    const double PRECIO_BASE = 10.0;
    const double DESCUENTO = 0.20;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}

double calcular_precio_adulto(int cantidad) {
    const double PRECIO_BASE = 15.0;
    const double DESCUENTO = 0.10;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}

double calcular_precio_senior(int cantidad) {
    const double PRECIO_BASE = 12.0;
    const double DESCUENTO = 0.30;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}
```

### 3. Duplicación Semántica

Código que hace lo mismo de diferentes maneras.

```c
// Problemático: mismo concepto implementado diferente
bool es_mayor_de_edad_1(int edad) {
    return edad >= 18;
}

bool validar_edad_legal(int edad) {
    if (edad < 18) {
        return false;
    }
    return true;
}

bool puede_votar(int edad) {
    return edad >= 18 ? true : false;
}
```

### 4. Duplicación de Datos

Misma información almacenada en múltiples lugares.

```c
// Problemático: datos redundantes
typedef struct {
    char* nombre;
    char* apellido;
    char* nombre_completo;  // Derivado de nombre + apellido
} persona_t;

typedef struct {
    double precio;
    int cantidad;
    double total;  // Derivado de precio * cantidad
} item_pedido_t;
```

## Técnicas de Eliminación de Duplicación

### 1. Extracción de Función

La técnica más básica: extraer código común a una función.

**Antes:**

```c
void registrar_compra(usuario_t* usuario, producto_t* producto) {
    // Validación duplicada
    if (usuario == NULL) {
        fprintf(stderr, "Error: usuario NULL\n");
        return;
    }
    if (!usuario->activo) {
        fprintf(stderr, "Error: usuario inactivo\n");
        return;
    }
    
    // Lógica de compra...
}

void registrar_venta(usuario_t* usuario, producto_t* producto) {
    // Misma validación duplicada
    if (usuario == NULL) {
        fprintf(stderr, "Error: usuario NULL\n");
        return;
    }
    if (!usuario->activo) {
        fprintf(stderr, "Error: usuario inactivo\n");
        return;
    }
    
    // Lógica de venta...
}
```

**Después:**

```c
bool validar_usuario(const usuario_t* usuario) {
    if (usuario == NULL) {
        fprintf(stderr, "Error: usuario NULL\n");
        return false;
    }
    
    if (!usuario->activo) {
        fprintf(stderr, "Error: usuario inactivo\n");
        return false;
    }
    
    return true;
}

void registrar_compra(usuario_t* usuario, producto_t* producto) {
    if (!validar_usuario(usuario)) {
        return;
    }
    // Lógica de compra...
}

void registrar_venta(usuario_t* usuario, producto_t* producto) {
    if (!validar_usuario(usuario)) {
        return;
    }
    // Lógica de venta...
}
```

### 2. Parametrización

Convertir valores fijos en parámetros.

**Antes:**

```c
double calcular_precio_estudiante(int cantidad) {
    return cantidad * 10.0 * 0.80;  // 20% descuento
}

double calcular_precio_adulto(int cantidad) {
    return cantidad * 15.0 * 0.90;  // 10% descuento
}

double calcular_precio_senior(int cantidad) {
    return cantidad * 12.0 * 0.70;  // 30% descuento
}
```

**Después:**

```c
typedef enum {
    CATEGORIA_ESTUDIANTE,
    CATEGORIA_ADULTO,
    CATEGORIA_SENIOR
} categoria_cliente_t;

typedef struct {
    double precio_base;
    double descuento;
} tarifa_t;

tarifa_t obtener_tarifa(categoria_cliente_t categoria) {
    static const tarifa_t tarifas[] = {
        [CATEGORIA_ESTUDIANTE] = {10.0, 0.20},
        [CATEGORIA_ADULTO] = {15.0, 0.10},
        [CATEGORIA_SENIOR] = {12.0, 0.30}
    };
    
    return tarifas[categoria];
}

double calcular_precio(int cantidad, categoria_cliente_t categoria) {
    tarifa_t tarifa = obtener_tarifa(categoria);
    double subtotal = cantidad * tarifa.precio_base;
    return subtotal * (1.0 - tarifa.descuento);
}
```

### 3. Uso de Estructuras de Datos

Reemplazar código repetitivo con datos.

**Antes:**

```c
char* obtener_nombre_mes(int mes) {
    if (mes == 1) return "Enero";
    if (mes == 2) return "Febrero";
    if (mes == 3) return "Marzo";
    if (mes == 4) return "Abril";
    if (mes == 5) return "Mayo";
    if (mes == 6) return "Junio";
    if (mes == 7) return "Julio";
    if (mes == 8) return "Agosto";
    if (mes == 9) return "Septiembre";
    if (mes == 10) return "Octubre";
    if (mes == 11) return "Noviembre";
    if (mes == 12) return "Diciembre";
    return "Inválido";
}
```

**Después:**

```c
const char* obtener_nombre_mes(int mes) {
    static const char* NOMBRES_MESES[] = {
        "Inválido",  // índice 0
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    
    const int NUM_MESES = sizeof(NOMBRES_MESES) / sizeof(NOMBRES_MESES[0]);
    
    if (mes < 1 || mes >= NUM_MESES) {
        return NOMBRES_MESES[0];
    }
    
    return NOMBRES_MESES[mes];
}
```

### 4. Template Method Pattern (Simulado)

Extraer la estructura común, parametrizar las partes variables.

**Antes:**

```c
void procesar_archivo_texto(const char* ruta) {
    FILE* f = fopen(ruta, "r");
    if (!f) return;
    
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        // Procesar como texto
        printf("Texto: %s", linea);
    }
    
    fclose(f);
}

void procesar_archivo_csv(const char* ruta) {
    FILE* f = fopen(ruta, "r");
    if (!f) return;
    
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        // Procesar como CSV
        char* token = strtok(linea, ",");
        while (token) {
            printf("Campo: %s\n", token);
            token = strtok(NULL, ",");
        }
    }
    
    fclose(f);
}
```

**Después:**

```c
typedef void (*procesador_linea_fn)(char* linea);

void procesar_archivo_generico(const char* ruta, 
                                procesador_linea_fn procesar_linea) {
    FILE* f = fopen(ruta, "r");
    if (!f) {
        fprintf(stderr, "Error abriendo: %s\n", ruta);
        return;
    }
    
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        procesar_linea(linea);
    }
    
    fclose(f);
}

void procesar_linea_texto(char* linea) {
    printf("Texto: %s", linea);
}

void procesar_linea_csv(char* linea) {
    char* token = strtok(linea, ",");
    while (token) {
        printf("Campo: %s\n", token);
        token = strtok(NULL, ",");
    }
}

// Uso
void procesar_archivo_texto(const char* ruta) {
    procesar_archivo_generico(ruta, procesar_linea_texto);
}

void procesar_archivo_csv(const char* ruta) {
    procesar_archivo_generico(ruta, procesar_linea_csv);
}
```

### 5. Extracción a Constantes/Configuración

**Antes:**

```c
void configurar_servidor_web() {
    iniciar_en_puerto(8080);
    establecer_timeout(30);
    establecer_max_conexiones(100);
}

void configurar_servidor_api() {
    iniciar_en_puerto(8080);  // Duplicado
    establecer_timeout(60);
    establecer_max_conexiones(100);  // Duplicado
}
```

**Después:**

```c
typedef struct {
    int puerto;
    int timeout_segundos;
    int max_conexiones;
} configuracion_servidor_t;

const configuracion_servidor_t CONFIG_WEB = {
    .puerto = 8080,
    .timeout_segundos = 30,
    .max_conexiones = 100
};

const configuracion_servidor_t CONFIG_API = {
    .puerto = 8080,
    .timeout_segundos = 60,
    .max_conexiones = 100
};

void configurar_servidor(const configuracion_servidor_t* config) {
    iniciar_en_puerto(config->puerto);
    establecer_timeout(config->timeout_segundos);
    establecer_max_conexiones(config->max_conexiones);
}

// Uso
configurar_servidor(&CONFIG_WEB);
configurar_servidor(&CONFIG_API);
```

## Casos Prácticos Completos

### Caso 1: Validaciones Repetidas

**Código Original:**

```c
bool validar_email(const char* email) {
    if (email == NULL) return false;
    if (strlen(email) == 0) return false;
    if (strlen(email) > 100) return false;
    if (!strchr(email, '@')) return false;
    return true;
}

bool validar_nombre(const char* nombre) {
    if (nombre == NULL) return false;
    if (strlen(nombre) == 0) return false;
    if (strlen(nombre) > 50) return false;
    return true;
}

bool validar_telefono(const char* telefono) {
    if (telefono == NULL) return false;
    if (strlen(telefono) == 0) return false;
    if (strlen(telefono) != 10) return false;
    return true;
}
```

**Código Refactorizado:**

```c
typedef struct {
    size_t longitud_minima;
    size_t longitud_maxima;
    bool requiere_arroba;
} criterios_validacion_t;

bool validar_cadena_con_criterios(const char* cadena, 
                                   const criterios_validacion_t* criterios) {
    if (cadena == NULL) {
        return false;
    }
    
    size_t longitud = strlen(cadena);
    
    if (longitud < criterios->longitud_minima) {
        return false;
    }
    
    if (criterios->longitud_maxima > 0 && longitud > criterios->longitud_maxima) {
        return false;
    }
    
    if (criterios->requiere_arroba && !strchr(cadena, '@')) {
        return false;
    }
    
    return true;
}

bool validar_email(const char* email) {
    const criterios_validacion_t criterios = {
        .longitud_minima = 1,
        .longitud_maxima = 100,
        .requiere_arroba = true
    };
    return validar_cadena_con_criterios(email, &criterios);
}

bool validar_nombre(const char* nombre) {
    const criterios_validacion_t criterios = {
        .longitud_minima = 1,
        .longitud_maxima = 50,
        .requiere_arroba = false
    };
    return validar_cadena_con_criterios(nombre, &criterios);
}

bool validar_telefono(const char* telefono) {
    const criterios_validacion_t criterios = {
        .longitud_minima = 10,
        .longitud_maxima = 10,
        .requiere_arroba = false
    };
    return validar_cadena_con_criterios(telefono, &criterios);
}
```

### Caso 2: Operaciones CRUD Repetitivas

**Código Original:**

```c
// Usuarios
usuario_t* crear_usuario(const char* nombre) {
    usuario_t* u = malloc(sizeof(usuario_t));
    if (!u) return NULL;
    u->nombre = strdup(nombre);
    u->id = generar_id();
    return u;
}

void destruir_usuario(usuario_t* u) {
    if (!u) return;
    free(u->nombre);
    free(u);
}

// Productos (código casi idéntico)
producto_t* crear_producto(const char* nombre) {
    producto_t* p = malloc(sizeof(producto_t));
    if (!p) return NULL;
    p->nombre = strdup(nombre);
    p->id = generar_id();
    return p;
}

void destruir_producto(producto_t* p) {
    if (!p) return;
    free(p->nombre);
    free(p);
}

// Categorías (más duplicación)
categoria_t* crear_categoria(const char* nombre) {
    categoria_t* c = malloc(sizeof(categoria_t));
    if (!c) return NULL;
    c->nombre = strdup(nombre);
    c->id = generar_id();
    return c;
}

void destruir_categoria(categoria_t* c) {
    if (!c) return;
    free(c->nombre);
    free(c);
}
```

**Código Refactorizado:**

```c
// Interfaz común para entidades
typedef struct {
    int id;
    char* nombre;
} entidad_base_t;

// Macros para reducir duplicación
#define IMPLEMENTAR_CREAR(tipo, nombre_tipo) \
    tipo* crear_##nombre_tipo(const char* nombre) { \
        tipo* entidad = malloc(sizeof(tipo)); \
        if (!entidad) return NULL; \
        entidad->nombre = strdup(nombre); \
        entidad->id = generar_id(); \
        return entidad; \
    }

#define IMPLEMENTAR_DESTRUIR(tipo, nombre_tipo) \
    void destruir_##nombre_tipo(tipo* entidad) { \
        if (!entidad) return; \
        free(entidad->nombre); \
        free(entidad); \
    }

// Implementación
IMPLEMENTAR_CREAR(usuario_t, usuario)
IMPLEMENTAR_DESTRUIR(usuario_t, usuario)

IMPLEMENTAR_CREAR(producto_t, producto)
IMPLEMENTAR_DESTRUIR(producto_t, producto)

IMPLEMENTAR_CREAR(categoria_t, categoria)
IMPLEMENTAR_DESTRUIR(categoria_t, categoria)
```

**Alternativa sin macros (más explícita):**

```c
typedef struct {
    void* (*crear)(const char* nombre);
    void (*destruir)(void* entidad);
} operaciones_entidad_t;

void* crear_entidad_generica(size_t tamano, const char* nombre) {
    entidad_base_t* entidad = malloc(tamano);
    if (!entidad) return NULL;
    
    entidad->id = generar_id();
    entidad->nombre = strdup(nombre);
    
    return entidad;
}

void destruir_entidad_generica(void* ptr) {
    if (!ptr) return;
    
    entidad_base_t* entidad = (entidad_base_t*)ptr;
    free(entidad->nombre);
    free(entidad);
}

usuario_t* crear_usuario(const char* nombre) {
    return crear_entidad_generica(sizeof(usuario_t), nombre);
}

void destruir_usuario(usuario_t* usuario) {
    destruir_entidad_generica(usuario);
}
```

### Caso 3: Procesamiento Similar de Diferentes Tipos

**Código Original:**

```c
void procesar_usuarios(usuario_t* usuarios, int n) {
    printf("=== Procesando Usuarios ===\n");
    for (int i = 0; i < n; i++) {
        if (usuarios[i].activo) {
            printf("ID: %d, Nombre: %s\n", 
                   usuarios[i].id, 
                   usuarios[i].nombre);
        }
    }
    printf("Total procesados: %d\n", n);
}

void procesar_productos(producto_t* productos, int n) {
    printf("=== Procesando Productos ===\n");
    for (int i = 0; i < n; i++) {
        if (productos[i].disponible) {
            printf("ID: %d, Nombre: %s\n", 
                   productos[i].id, 
                   productos[i].nombre);
        }
    }
    printf("Total procesados: %d\n", n);
}
```

**Código Refactorizado:**

```c
typedef bool (*filtro_fn)(const void* elemento);
typedef void (*mostrar_fn)(const void* elemento);

void procesar_elementos(const void* elementos,
                         int cantidad,
                         size_t tamano_elemento,
                         const char* tipo,
                         filtro_fn filtro,
                         mostrar_fn mostrar) {
    printf("=== Procesando %s ===\n", tipo);
    
    const unsigned char* ptr = (const unsigned char*)elementos;
    
    for (int i = 0; i < cantidad; i++) {
        const void* elemento = ptr + (i * tamano_elemento);
        
        if (filtro(elemento)) {
            mostrar(elemento);
        }
    }
    
    printf("Total procesados: %d\n", cantidad);
}

// Funciones específicas para usuarios
bool usuario_activo(const void* elem) {
    const usuario_t* u = (const usuario_t*)elem;
    return u->activo;
}

void mostrar_usuario(const void* elem) {
    const usuario_t* u = (const usuario_t*)elem;
    printf("ID: %d, Nombre: %s\n", u->id, u->nombre);
}

// Funciones específicas para productos
bool producto_disponible(const void* elem) {
    const producto_t* p = (const producto_t*)elem;
    return p->disponible;
}

void mostrar_producto(const void* elem) {
    const producto_t* p = (const producto_t*)elem;
    printf("ID: %d, Nombre: %s\n", p->id, p->nombre);
}

// Uso
void procesar_usuarios(usuario_t* usuarios, int n) {
    procesar_elementos(usuarios, n, sizeof(usuario_t),
                       "Usuarios", usuario_activo, mostrar_usuario);
}

void procesar_productos(producto_t* productos, int n) {
    procesar_elementos(productos, n, sizeof(producto_t),
                       "Productos", producto_disponible, mostrar_producto);
}
```

## Cuándo NO Eliminar Duplicación

### 1. Duplicación Accidental

```c
// Similar pero semánticamente diferente
int contar_usuarios_activos() {
    int contador = 0;
    // ...
    return contador;
}

int contar_productos_en_stock() {
    int contador = 0;
    // ...
    return contador;
}
```

Aunque la estructura es similar, representan conceptos diferentes que pueden evolucionar independientemente.

### 2. Duplicación que Aumenta Complejidad

```c
// A veces la abstracción es peor que la duplicación
void validar_formato_simple(const char* str) {
    // Validación directa y clara
    if (strlen(str) < 3 || strlen(str) > 10) {
        return false;
    }
    return true;
}

// No vale la pena crear un framework complejo para esto
```

### 3. Duplicación en Tests

```c
// En tests, cierta duplicación es aceptable para claridad
void test_usuario_valido() {
    usuario_t u = {.nombre = "Juan", .edad = 25};
    assert(validar_usuario(&u));
}

void test_usuario_invalido() {
    usuario_t u = {.nombre = "Ana", .edad = 15};
    assert(!validar_usuario(&u));
}
```

## Estrategia de Refactorización

### Regla de Tres

Esperar hasta ver la duplicación al menos tres veces antes de abstraer:

1. **Primera vez:** Escribir el código
2. **Segunda vez:** Notar la duplicación pero tolerar
3. **Tercera vez:** Refactorizar

### Proceso Gradual

1. **Identificar:** Encontrar código duplicado
2. **Analizar:** ¿Es realmente duplicación o coincidencia?
3. **Extraer:** Crear la abstracción
4. **Probar:** Verificar que funciona
5. **Reemplazar:** Sustituir duplicaciones con la abstracción
6. **Verificar:** Tests pasan, comportamiento no cambió

## Herramientas para Detectar Duplicación

### Búsqueda Manual

```bash
# Buscar funciones similares
grep -n "^void procesar_" *.c

# Encontrar patrones repetidos
grep -r "if (.*== NULL)" .
```

### Análisis Estático

```bash
# CPD (Copy/Paste Detector) de PMD
pmd cpd --minimum-tokens 50 --files .

# SonarQube
# Puede detectar bloques duplicados
```

## Resumen

Técnicas para eliminar duplicación:

1. **Extracción de Función:** Código común a función reutilizable
2. **Parametrización:** Valores fijos a parámetros
3. **Estructuras de Datos:** Código repetitivo a tablas
4. **Template Method:** Estructura común, partes variables parametrizadas
5. **Configuración:** Valores duplicados a constantes/config

**Principios clave:**
- DRY: Don't Repeat Yourself
- Regla de tres: esperar ver 3 veces antes de abstraer
- No sobre-abstraer: balance entre DRY y claridad
- Tests ayudan a refactorizar con confianza
- Duplicación accidental vs estructural

**Beneficios:**
- Mantenimiento más fácil
- Menos bugs por inconsistencias
- Cambios centralizados
- Código más conciso

La eliminación de duplicación debe balancearse con la claridad. No toda similitud requiere abstracción inmediata.
