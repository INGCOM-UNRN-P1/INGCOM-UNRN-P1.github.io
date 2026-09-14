---
title: "Refactorización de Código Duplicado"
short_title: "Don't Repeat Yourself [DRY]"
subtitle: "Eliminación de duplicación mediante extracción y abstracción"
---

(refactorizacion-dry)=

## Introducción

La duplicación de código es uno de los problemas más comunes y perjudiciales en
el desarrollo de software. Cada fragmento de código duplicado representa una
oportunidad para inconsistencias, bugs y dificultad en el mantenimiento. El
principio **DRY (Don't Repeat Yourself)** establece que "cada pieza de
conocimiento debe tener una representación única, inequívoca y autoritativa
dentro del sistema".

Este apunte presenta técnicas sistemáticas para identificar y eliminar
duplicación, mejorando la mantenibilidad, consistencia y calidad general del
código.

:::{important} Principio DRY

La duplicación de código multiplica el esfuerzo de mantenimiento y aumenta la
probabilidad de inconsistencias. Cada vez que modificás código duplicado, debés
recordar modificar todas sus copias. Como establece {ref}`0x0001h`, la claridad
y mantenibilidad son fundamentales.

:::
<!-- {important} Principio DRY -->

## Reglas de estilo que resuelve

Las técnicas de este apunte no son un conjunto de recetas sueltas: son la forma
práctica de resolver los problemas que modelan las reglas de estilo de la
cátedra. Cuando el código duplica lógica, mezcla responsabilidades o arrastra
firmas ilegibles, no hace falta inventar un criterio nuevo; basta con aplicar la
refactorización correspondiente y verificar contra la regla que la origina. La
tabla siguiente mapea cada regla con el defecto que describe y con la técnica
que lo elimina.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
| :--- | :--- | :--- |
| {ref}`0x2015h` | El mismo bloque de lógica aparece dos o más veces. | Extracción de función: el bloque pasa a una función con nombre propio que se invoca desde cada lugar. |
| {ref}`0x2008h` | El ejercicio se resuelve en `main` o en un bloque monolítico. | Cada paso del procesamiento se aísla en funciones con responsabilidad propia y `main` solo orquesta. |
| {ref}`0x2005h` | Una función acumula validación, cálculo e impresión. | Las técnicas separan cada responsabilidad para que toda función se describa con una sola frase, sin "y". |
| {ref}`0x200Ah` | Firmas con más de cuatro parámetros que viajan juntos. | Parametrización con `struct`: los datos relacionados se empaquetan y cruzan la frontera en un único puntero. |
| {ref}`0x7007h` | Un parámetro `bool` selecciona entre dos comportamientos. | Se reemplaza la bandera por funciones específicas o por un `enum` de dominio con nombres de intención. |
| {ref}`0x0001h` | El código ofuscado o repetido obliga a retener demasiado contexto. | La abstracción con nombres claros baja la carga cognitiva y deja visible la intención de cada paso. |

## Tipos de Duplicación

### 1. Duplicación Literal

Código idéntico copiado y pegado.

```{code-block} c
:linenos:
// Problemático: mismo código en múltiples lugares
void procesar_usuario_web(usuario_t *u)
{
    if (u == NULL)
    {
        log_error("Usuario NULL");
        return;
    }
    if (!u->activo)
    {
        log_error("Usuario inactivo");
        return;
    }
    if (u->bloqueado)
    {
        log_error("Usuario bloqueado");
        return;
    }
    // procesar...
}
void procesar_usuario_api(usuario_t *u)
{
    if (u == NULL)
    {
        log_error("Usuario NULL");
        return;
    }
    if (!u->activo)
    {
        log_error("Usuario inactivo");
        return;
    }
    if (u->bloqueado)
    {
        log_error("Usuario bloqueado");
        return;
    }
    // procesar...
}
```
<!-- {code-block} c -->

### 2. Duplicación Estructural

Código con estructura similar pero diferentes detalles.

```{code-block} c
:linenos:
// Problemático: estructura duplicada
double calcular_precio_estudiante(int cantidad)
{
    const double PRECIO_BASE = 10.0;
    const double DESCUENTO = 0.20;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}
double calcular_precio_adulto(int cantidad)
{
    const double PRECIO_BASE = 15.0;
    const double DESCUENTO = 0.10;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}
double calcular_precio_senior(int cantidad)
{
    const double PRECIO_BASE = 12.0;
    const double DESCUENTO = 0.30;
    double subtotal = cantidad * PRECIO_BASE;
    double descuento = subtotal * DESCUENTO;
    return subtotal - descuento;
}
```
<!-- {code-block} c -->

### 3. Duplicación Semántica

Código que hace lo mismo de diferentes maneras.

```{code-block} c
:linenos:
// Problemático: mismo concepto implementado diferente
bool es_mayor_de_edad_1(int edad)
{
    return edad >= 18;
}
bool validar_edad_legal(int edad)
{
    if (edad < 18)
    {
        return false;
    }
    return true;
}
bool puede_votar(int edad)
{
    return edad >= 18 ? true : false;
}
```
<!-- {code-block} c -->

### 4. Duplicación de Datos

Misma información almacenada en múltiples lugares.

```{code-block} c
:linenos:
// Problemático: datos redundantes
typedef struct
{
    char *nombre;
    char *apellido;
    char *nombre_completo; // Derivado de nombre + apellido
} persona_t;
typedef struct
{
    double precio;
    int cantidad;
    double total; // Derivado de precio * cantidad
} item_pedido_t;
```
<!-- {code-block} c -->

## Técnicas de Eliminación de Duplicación

### 1. Extracción de Función

La técnica más básica: extraer código común a una función. Es la respuesta
directa a {ref}`0x2015h`, que prohíbe copiar y pegar el mismo bloque de lógica
dos o más veces.

**Antes:**

```{code-block} c
:linenos:
void registrar_compra(usuario_t *usuario, producto_t *producto)
{
    // Validación duplicada
    if (usuario == NULL)
    {
        fprintf(stderr, "Error: usuario NULL\n");
        return;
    }
    if (!usuario->activo)
    {
        fprintf(stderr, "Error: usuario inactivo\n");
        return;
    }
    // Lógica de compra...
}
void registrar_venta(usuario_t *usuario, producto_t *producto)
{
    // Misma validación duplicada
    if (usuario == NULL)
    {
        fprintf(stderr, "Error: usuario NULL\n");
        return;
    }
    if (!usuario->activo)
    {
        fprintf(stderr, "Error: usuario inactivo\n");
        return;
    }
    // Lógica de venta...
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
bool validar_usuario(const usuario_t *usuario)
{
    if (usuario == NULL)
    {
        fprintf(stderr, "Error: usuario NULL\n");
        return false;
    }
    if (!usuario->activo)
    {
        fprintf(stderr, "Error: usuario inactivo\n");
        return false;
    }
    return true;
}
void registrar_compra(usuario_t *usuario, producto_t *producto)
{
    if (!validar_usuario(usuario))
    {
        return;
    }
    // Lógica de compra...
}
void registrar_venta(usuario_t *usuario, producto_t *producto)
{
    if (!validar_usuario(usuario))
    {
        return;
    }
    // Lógica de venta...
}
```
<!-- {code-block} c -->

### 2. Parametrización

Convertir valores fijos en parámetros.

**Antes:**

```{code-block} c
:linenos:
double calcular_precio_estudiante(int cantidad)
{
    return cantidad * 10.0 * 0.80; // 20% descuento
}
double calcular_precio_adulto(int cantidad)
{
    return cantidad * 15.0 * 0.90; // 10% descuento
}
double calcular_precio_senior(int cantidad)
{
    return cantidad * 12.0 * 0.70; // 30% descuento
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef enum
{
    CATEGORIA_ESTUDIANTE,
    CATEGORIA_ADULTO,
    CATEGORIA_SENIOR
} categoria_cliente_t;
typedef struct
{
    double precio_base;
    double descuento;
} tarifa_t;
tarifa_t obtener_tarifa(categoria_cliente_t categoria)
{
    static const tarifa_t tarifas[] = {[CATEGORIA_ESTUDIANTE] = {10.0, 0.20},
                                       [CATEGORIA_ADULTO] = {15.0, 0.10},
                                       [CATEGORIA_SENIOR] = {12.0, 0.30}};
    return tarifas[categoria];
}
double calcular_precio(int cantidad, categoria_cliente_t categoria)
{
    tarifa_t tarifa = obtener_tarifa(categoria);
    double subtotal = cantidad * tarifa.precio_base;
    return subtotal * (1.0 - tarifa.descuento);
}
```
<!-- {code-block} c -->

### 3. Uso de Estructuras de Datos

Reemplazar código repetitivo con datos.

**Antes:**

```{code-block} c
:linenos:
char *obtener_nombre_mes(int mes)
{
    if (mes == 1)
        return "Enero";
    if (mes == 2)
        return "Febrero";
    if (mes == 3)
        return "Marzo";
    if (mes == 4)
        return "Abril";
    if (mes == 5)
        return "Mayo";
    if (mes == 6)
        return "Junio";
    if (mes == 7)
        return "Julio";
    if (mes == 8)
        return "Agosto";
    if (mes == 9)
        return "Septiembre";
    if (mes == 10)
        return "Octubre";
    if (mes == 11)
        return "Noviembre";
    if (mes == 12)
        return "Diciembre";
    return "Inválido";
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
const char *obtener_nombre_mes(int mes)
{
    static const char *NOMBRES_MESES[] = {
        "Inválido", // índice 0
        "Enero",      "Febrero", "Marzo",     "Abril",
        "Mayo",       "Junio",   "Julio",     "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    const int NUM_MESES = sizeof(NOMBRES_MESES) / sizeof(NOMBRES_MESES[0]);
    if (mes < 1 || mes >= NUM_MESES)
    {
        return NOMBRES_MESES[0];
    }
    return NOMBRES_MESES[mes];
}
```
<!-- {code-block} c -->

### 4. Template Method Pattern (Simulado)

Extraer la estructura común, parametrizar las partes variables. El resultado
deja el esqueleto en una función y las variantes en funciones separadas, que es
la forma de resolver el ejercicio mediante funciones que exige {ref}`0x2008h`.
Además, reemplazar el `bool` que elegía entre texto y CSV por un puntero a
función evita el parámetro bandera que prohíbe {ref}`0x7007h`.

**Antes:**

```{code-block} c
:linenos:
void procesar_archivo_texto(const char *ruta)
{
    FILE *f = fopen(ruta, "r");
    if (!f)
        return;
    char linea[256];
    while (fgets(linea, sizeof(linea), f))
    {
        // Procesar como texto
        printf("Texto: %s", linea);
    }
    fclose(f);
}
void procesar_archivo_csv(const char *ruta)
{
    FILE *f = fopen(ruta, "r");
    if (!f)
        return;
    char linea[256];
    while (fgets(linea, sizeof(linea), f))
    {
        // Procesar como CSV
        char *token = strtok(linea, ",");
        while (token)
        {
            printf("Campo: %s\n", token);
            token = strtok(NULL, ",");
        }
    }
    fclose(f);
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef void (*procesador_linea_fn)(char *linea);
void procesar_archivo_generico(const char *ruta,
                               procesador_linea_fn procesar_linea)
{
    FILE *f = fopen(ruta, "r");
    if (!f)
    {
        fprintf(stderr, "Error abriendo: %s\n", ruta);
        return;
    }
    char linea[256];
    while (fgets(linea, sizeof(linea), f))
    {
        procesar_linea(linea);
    }
    fclose(f);
}
void procesar_linea_texto(char *linea)
{
    printf("Texto: %s", linea);
}
void procesar_linea_csv(char *linea)
{
    char *token = strtok(linea, ",");
    while (token)
    {
        printf("Campo: %s\n", token);
        token = strtok(NULL, ",");
    }
}
// Uso
void procesar_archivo_texto(const char *ruta)
{
    procesar_archivo_generico(ruta, procesar_linea_texto);
}
void procesar_archivo_csv(const char *ruta)
{
    procesar_archivo_generico(ruta, procesar_linea_csv);
}
```
<!-- {code-block} c -->

### 5. Extracción a Constantes/Configuración

**Antes:**

```{code-block} c
:linenos:
void configurar_servidor_web()
{
    iniciar_en_puerto(8080);
    establecer_timeout(30);
    establecer_max_conexiones(100);
}
void configurar_servidor_api()
{
    iniciar_en_puerto(8080); // Duplicado
    establecer_timeout(60);
    establecer_max_conexiones(100); // Duplicado
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef struct
{
    int puerto;
    int timeout_segundos;
    int max_conexiones;
} configuracion_servidor_t;
const configuracion_servidor_t CONFIG_WEB = {
    .puerto = 8080, .timeout_segundos = 30, .max_conexiones = 100};
const configuracion_servidor_t CONFIG_API = {
    .puerto = 8080, .timeout_segundos = 60, .max_conexiones = 100};
void configurar_servidor(const configuracion_servidor_t *config)
{
    iniciar_en_puerto(config->puerto);
    establecer_timeout(config->timeout_segundos);
    establecer_max_conexiones(config->max_conexiones);
}
// Uso
configurar_servidor(&CONFIG_WEB);
configurar_servidor(&CONFIG_API);
```
<!-- {code-block} c -->

## Casos Prácticos Completos

### Caso 1: Validaciones Repetidas

**Código Original:**

```{code-block} c
:linenos:
bool validar_email(const char *email)
{
    if (email == NULL)
        return false;
    if (strlen(email) == 0)
        return false;
    if (strlen(email) > 100)
        return false;
    if (!strchr(email, '@'))
        return false;
    return true;
}
bool validar_nombre(const char *nombre)
{
    if (nombre == NULL)
        return false;
    if (strlen(nombre) == 0)
        return false;
    if (strlen(nombre) > 50)
        return false;
    return true;
}
bool validar_telefono(const char *telefono)
{
    if (telefono == NULL)
        return false;
    if (strlen(telefono) == 0)
        return false;
    if (strlen(telefono) != 10)
        return false;
    return true;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef struct
{
    size_t longitud_minima;
    size_t longitud_maxima;
    bool requiere_arroba;
} criterios_validacion_t;
bool validar_cadena_con_criterios(const char *cadena,
                                  const criterios_validacion_t *criterios)
{
    if (cadena == NULL)
    {
        return false;
    }
    size_t longitud = strlen(cadena);
    if (longitud < criterios->longitud_minima)
    {
        return false;
    }
    if (criterios->longitud_maxima > 0 &&
        longitud > criterios->longitud_maxima)
    {
        return false;
    }
    if (criterios->requiere_arroba && !strchr(cadena, '@'))
    {
        return false;
    }
    return true;
}
bool validar_email(const char *email)
{
    const criterios_validacion_t criterios = {
        .longitud_minima = 1, .longitud_maxima = 100, .requiere_arroba = true};
    return validar_cadena_con_criterios(email, &criterios);
}
bool validar_nombre(const char *nombre)
{
    const criterios_validacion_t criterios = {
        .longitud_minima = 1, .longitud_maxima = 50, .requiere_arroba = false};
    return validar_cadena_con_criterios(nombre, &criterios);
}
bool validar_telefono(const char *telefono)
{
    const criterios_validacion_t criterios = {.longitud_minima = 10,
                                              .longitud_maxima = 10,
                                              .requiere_arroba = false};
    return validar_cadena_con_criterios(telefono, &criterios);
}
```
<!-- {code-block} c -->

Cada validador conserva una única responsabilidad —describir sus criterios y
delegar la comprobación—, lo que cumple {ref}`0x2005h`. Al empaquetar los
criterios en un `struct`, la función de validación deja de recibir una lista
larga de parámetros sueltos y pasa a recibir dos, en la línea de {ref}`0x200Ah`.

### Caso 2: Operaciones CRUD Repetitivas

**Código Original:**

```{code-block} c
:linenos:
// Usuarios
usuario_t *crear_usuario(const char *nombre)
{
    usuario_t *u = malloc(sizeof(usuario_t));
    if (!u)
        return NULL;
    u->nombre = strdup(nombre);
    u->id = generar_id();
    return u;
}
void destruir_usuario(usuario_t *u)
{
    if (!u)
        return;
    free(u->nombre);
    free(u);
}
// Productos (código casi idéntico)
producto_t *crear_producto(const char *nombre)
{
    producto_t *p = malloc(sizeof(producto_t));
    if (!p)
        return NULL;
    p->nombre = strdup(nombre);
    p->id = generar_id();
    return p;
}
void destruir_producto(producto_t *p)
{
    if (!p)
        return;
    free(p->nombre);
    free(p);
}
// Categorías (más duplicación)
categoria_t *crear_categoria(const char *nombre)
{
    categoria_t *c = malloc(sizeof(categoria_t));
    if (!c)
        return NULL;
    c->nombre = strdup(nombre);
    c->id = generar_id();
    return c;
}
void destruir_categoria(categoria_t *c)
{
    if (!c)
        return;
    free(c->nombre);
    free(c);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
// Interfaz común para entidades
typedef struct
{
    int id;
    char *nombre;
} entidad_base_t;
// Macros para reducir duplicación
#define IMPLEMENTAR_CREAR(tipo, nombre_tipo)                                  \
    tipo *crear_##nombre_tipo(const char *nombre)                             \
    {                                                                         \
        tipo *entidad = malloc(sizeof(tipo));                                 \
        if (!entidad)                                                         \
            return NULL;                                                      \
        entidad->nombre = strdup(nombre);                                     \
        entidad->id = generar_id();                                           \
        return entidad;                                                       \
    }
#define IMPLEMENTAR_DESTRUIR(tipo, nombre_tipo)                               \
    void destruir_##nombre_tipo(tipo *entidad)                                \
    {                                                                         \
        if (!entidad)                                                         \
            return;                                                           \
        free(entidad->nombre);                                                \
        free(entidad);                                                        \
    }
// Implementación
IMPLEMENTAR_CREAR(usuario_t, usuario)
IMPLEMENTAR_DESTRUIR(usuario_t, usuario)
IMPLEMENTAR_CREAR(producto_t, producto)
IMPLEMENTAR_DESTRUIR(producto_t, producto)
IMPLEMENTAR_CREAR(categoria_t, categoria)
IMPLEMENTAR_DESTRUIR(categoria_t, categoria)
```
<!-- {code-block} c -->

**Alternativa sin macros (más explícita):**

```{code-block} c
:linenos:
typedef struct
{
    void *(*crear)(const char *nombre);
    void (*destruir)(void *entidad);
} operaciones_entidad_t;
void *crear_entidad_generica(size_t tamano, const char *nombre)
{
    entidad_base_t *entidad = malloc(tamano);
    if (!entidad)
        return NULL;
    entidad->id = generar_id();
    entidad->nombre = strdup(nombre);
    return entidad;
}
void destruir_entidad_generica(void *ptr)
{
    if (!ptr)
        return;
    entidad_base_t *entidad = (entidad_base_t *)ptr;
    free(entidad->nombre);
    free(entidad);
}
usuario_t *crear_usuario(const char *nombre)
{
    return crear_entidad_generica(sizeof(usuario_t), nombre);
}
void destruir_usuario(usuario_t *usuario)
{
    destruir_entidad_generica(usuario);
}
```
<!-- {code-block} c -->

### Caso 3: Procesamiento Similar de Diferentes Tipos

**Código Original:**

```{code-block} c
:linenos:
void procesar_usuarios(usuario_t *usuarios, int n)
{
    printf("=== Procesando Usuarios ===\n");
    for (int i = 0; i < n; i++)
    {
        if (usuarios[i].activo)
        {
            printf("ID: %d, Nombre: %s\n", usuarios[i].id, usuarios[i].nombre);
        }
    }
    printf("Total procesados: %d\n", n);
}
void procesar_productos(producto_t *productos, int n)
{
    printf("=== Procesando Productos ===\n");
    for (int i = 0; i < n; i++)
    {
        if (productos[i].disponible)
        {
            printf("ID: %d, Nombre: %s\n", productos[i].id,
                   productos[i].nombre);
        }
    }
    printf("Total procesados: %d\n", n);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef bool (*filtro_fn)(const void *elemento);
typedef void (*mostrar_fn)(const void *elemento);
void procesar_elementos(const void *elementos, int cantidad,
                        size_t tamano_elemento, const char *tipo,
                        filtro_fn filtro, mostrar_fn mostrar)
{
    printf("=== Procesando %s ===\n", tipo);
    const unsigned char *ptr = (const unsigned char *)elementos;
    for (int i = 0; i < cantidad; i++)
    {
        const void *elemento = ptr + (i * tamano_elemento);
        if (filtro(elemento))
        {
            mostrar(elemento);
        }
    }
    printf("Total procesados: %d\n", cantidad);
}
// Funciones específicas para usuarios
bool usuario_activo(const void *elem)
{
    const usuario_t *u = (const usuario_t *)elem;
    return u->activo;
}
void mostrar_usuario(const void *elem)
{
    const usuario_t *u = (const usuario_t *)elem;
    printf("ID: %d, Nombre: %s\n", u->id, u->nombre);
}
// Funciones específicas para productos
bool producto_disponible(const void *elem)
{
    const producto_t *p = (const producto_t *)elem;
    return p->disponible;
}
void mostrar_producto(const void *elem)
{
    const producto_t *p = (const producto_t *)elem;
    printf("ID: %d, Nombre: %s\n", p->id, p->nombre);
}
// Uso
void procesar_usuarios(usuario_t *usuarios, int n)
{
    procesar_elementos(usuarios, n, sizeof(usuario_t), "Usuarios",
                       usuario_activo, mostrar_usuario);
}
void procesar_productos(producto_t *productos, int n)
{
    procesar_elementos(productos, n, sizeof(producto_t), "Productos",
                       producto_disponible, mostrar_producto);
}
```
<!-- {code-block} c -->

### Caso 4: Ejemplo integrador — Validación, cálculo y notificación

Este caso reúne varias reglas a la vez. La función original valida al cliente,
calcula el total, imprime y notifica, todo en un mismo cuerpo con parámetros
sueltos y banderas booleanas.

**❌ Código original:**

```c
void registrar_pedido(const char *cliente, int producto_id, int cantidad,
                      double precio_unitario, bool aplicar_descuento,
                      bool enviar_correo)
{
    if (cliente == NULL || strlen(cliente) == 0) {
        return;
    }
    if (cantidad <= 0 || precio_unitario <= 0.0) {
        return;
    }
    double subtotal = cantidad * precio_unitario;
    double total = aplicar_descuento ? subtotal * 0.90 : subtotal;
    printf("Cliente: %s | Total: %.2f\n", cliente, total);
    if (enviar_correo) {
        printf("Correo a %s\n", cliente);
    }
}
```

La firma tiene seis parámetros ({ref}`0x200Ah`), dos de ellos `bool` que
seleccionan comportamiento ({ref}`0x7007h`), y la función hace validación,
cálculo, impresión y notificación ({ref}`0x2005h`). Si la validación del cliente
se repite en otro punto del programa, además se duplica la lógica
({ref}`0x2015h`).

**✅ Código refactorizado:**

```c
typedef struct
{
    const char *cliente;
    int producto_id;
    int cantidad;
    double precio_unitario;
    double descuento;
} pedido_t;

typedef enum
{
    SIN_NOTIFICACION,
    NOTIFICAR_CORREO
} notificacion_t;

static bool pedido_valido(const pedido_t *pedido)
{
    if (pedido == NULL || pedido->cliente == NULL) {
        return false;
    }
    return pedido->cantidad > 0 && pedido->precio_unitario > 0.0;
}

static double calcular_total(const pedido_t *pedido)
{
    double subtotal = pedido->cantidad * pedido->precio_unitario;
    return subtotal * (1.0 - pedido->descuento);
}

static void mostrar_pedido(const pedido_t *pedido, double total)
{
    printf("Cliente: %s | Total: %.2f\n", pedido->cliente, total);
}

static void notificar_correo(const pedido_t *pedido)
{
    printf("Correo a %s\n", pedido->cliente);
}

void registrar_pedido(const pedido_t *pedido, notificacion_t notificacion)
{
    if (!pedido_valido(pedido)) {
        return;
    }
    double total = calcular_total(pedido);
    mostrar_pedido(pedido, total);
    if (notificacion == NOTIFICAR_CORREO) {
        notificar_correo(pedido);
    }
}
```

El `struct pedido_t` agrupa los datos que siempre viajan juntos y reduce la
firma a dos parámetros, cumpliendo {ref}`0x200Ah`. El descuento pasa a ser un
dato y la notificación se modela con el `enum` `notificacion_t`, de modo que
desaparecen las banderas `bool` de {ref}`0x7007h`. Cada paso se extrae a su
propia función ({ref}`0x2015h`) y `registrar_pedido` solo orquesta, como pide
{ref}`0x2008h`. La validación, el cálculo y la salida quedan en funciones de una
sola responsabilidad ({ref}`0x2005h`), con nombres que describen la intención
sin abreviaturas crípticas ({ref}`0x0001h`).

## Cuándo NO Eliminar Duplicación

### 1. Duplicación Accidental

```{code-block} c
:linenos:
// Similar pero semánticamente diferente
int contar_usuarios_activos()
{
    int contador = 0;
    // ...
    return contador;
}
int contar_productos_en_stock()
{
    int contador = 0;
    // ...
    return contador;
}
```
<!-- {code-block} c -->

Aunque la estructura es similar, representan conceptos diferentes que pueden
evolucionar independientemente.

### 2. Duplicación que Aumenta Complejidad

```{code-block} c
:linenos:
// A veces la abstracción es peor que la duplicación
void validar_formato_simple(const char *str)
{
    // Validación directa y clara
    if (strlen(str) < 3 || strlen(str) > 10)
    {
        return false;
    }
    return true;
}
// No vale la pena crear un framework complejo para esto
```
<!-- {code-block} c -->

### 3. Duplicación en Tests

```{code-block} c
:linenos:
// En tests, cierta duplicación es aceptable para claridad
void test_usuario_valido()
{
    usuario_t u = {.nombre = "Juan", .edad = 25};
    assert(validar_usuario(&u));
}
void test_usuario_invalido()
{
    usuario_t u = {.nombre = "Ana", .edad = 15};
    assert(!validar_usuario(&u));
}
```
<!-- {code-block} c -->

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

``` bash
# Buscar funciones similares
grep -n "^void procesar_" *.c

# Encontrar patrones repetidos
grep -r "if (.*== NULL)" .
```
<!-- bash -->

### Análisis Estático

``` bash
# CPD (Copy/Paste Detector) de PMD
pmd cpd --minimum-tokens 50 --files .

# SonarQube
# Puede detectar bloques duplicados
```
<!-- bash -->

## Diagnóstico y refactorización

Usá esta tabla como guía rápida: identificá el síntoma en tu código, mirá la
regla que lo modela y aplicá la técnica correspondiente de la guía.

| Regla | Síntoma en el código | Técnica de esta guía |
| :--- | :--- | :--- |
| {ref}`0x2015h` | El mismo `if`, la misma fórmula o el mismo bloque repegados en dos lugares. | Extracción de función y Template Method. |
| {ref}`0x2008h` | Toda la lógica vive en `main` o en un bloque monolítico. | Descomposición en funciones con `main` como orquestador. |
| {ref}`0x2005h` | Una función "valida, calcula e imprime" y su nombre necesita un "y". | Separación de responsabilidades en funciones distintas. |
| {ref}`0x200Ah` | Firma de cinco o más parámetros, varios del mismo tipo. | Parametrización con `struct` y paso por puntero `const`. |
| {ref}`0x7007h` | `procesar(x, true, false)` sin significado evidente en la llamada. | Funciones específicas o `enum` de dominio en lugar de `bool`. |
| {ref}`0x0001h` | Nombres crípticos y sentencias densas que obligan a retener contexto. | Abstracción con nombres de dominio y código paso a paso. |

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

La eliminación de duplicación debe balancearse con la claridad. No toda
similitud requiere abstracción inmediata.

## Checklist de verificación

- [ ] ¿Extraje a una función todo bloque de lógica repetido dos o más veces, en línea con {ref}`0x2015h`?
- [ ] ¿Cada paso del ejercicio quedó resuelto mediante funciones y `main` solo orquesta, como pide {ref}`0x2008h`?
- [ ] ¿Puedo describir cada función con una sola frase, sin "y", según {ref}`0x2005h`?
- [ ] ¿Ninguna función supera los cuatro parámetros de entrada ({ref}`0x200Ah`)?
- [ ] ¿Eliminé los parámetros bandera de tipo `bool` en favor de funciones con nombre o de un `enum` ({ref}`0x7007h`)?
- [ ] ¿Los nombres de funciones, variables y tipos son claros y sin abreviaturas crípticas ({ref}`0x0001h`)?
- [ ] ¿Verifiqué que el comportamiento no cambió después de refactorizar, ejecutando las pruebas?
