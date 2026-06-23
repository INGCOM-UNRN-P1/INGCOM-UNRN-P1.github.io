---
title: "Mejora de Nombres y Comunicación de Intenciones"
short_title: "Cambios de nombres"
subtitle: "Técnicas para elegir nombres que revelen intenciones y mejoren la comprensión"
---

## Introducción

Los nombres son la forma más básica y fundamental de documentación en el código. Un buen nombre comunica propósito, tipo, alcance y restricciones sin necesidad de comentarios adicionales. Por el contrario, nombres pobres oscurecen la intención, aumentan la carga cognitiva y conducen a errores.

Este apunte presenta técnicas sistemáticas para mejorar los nombres en el código, desde variables y funciones hasta tipos y constantes, con el objetivo de hacer el código auto-explicativo y mantener la coherencia en todo el proyecto.

:::{important} Nombres Reveladores de Intención
Como establece {ref}`0x0001h`, los identificadores deben ser descriptivos y reflejar con precisión su propósito. Un nombre bien elegido es una forma de documentación que nunca queda desactualizada.
:::

## Problemas Comunes con Nombres

### 1. Nombres Crípticos o Abreviados

```c
// Problemático: nombres sin significado claro
int d;        // ¿días? ¿dinero? ¿distancia?
int tmp;      // temporal... ¿para qué?
int x, y;     // ¿coordenadas? ¿variables matemáticas?
char buf[256]; // ¿buffer de qué?

void proc(int n) {  // ¿procesar qué?
    // ...
}
```

### 2. Nombres Engañosos

```c
// Problemático: nombres que no reflejan el contenido real
int dias_del_mes;  // Contiene el número del mes, no los días
char* get_usuario(); // Retorna NULL si no existe, no "obtiene"
bool validar_email(char* e); // Solo verifica formato, no valida existencia

// Array que NO contiene elementos de ese tipo
usuario_t usuarios_activos[100]; // Puede tener usuarios inactivos
```

### 3. Inconsistencia en Nomenclatura

```c
// Problemático: diferentes convenciones mezcladas
int obtener_edad();
int getAltura();
int fetch_peso();
int edad_recuperar();

typedef struct {
    int ID;           // Mayúsculas
    char* nombre;     // minúsculas
    int EdadPersona;  // PascalCase
} usuario_t;
```

### 4. Nombres Genéricos Sin Contexto

```c
// Problemático: nombres demasiado genéricos
void procesar(void* datos);
int calcular(int a, int b);
char* obtener_valor();
bool es_valido();

typedef struct {
    int valor;
    char* dato;
    void* info;
} elemento_t;
```

### 5. Información de Tipo en el Nombre

```c
// Problemático: notación húngara o prefijos de tipo
int iContador;
char* strNombre;
bool bActivo;
float fPrecio;

// Redundante
char nombre_string[50];
int edad_entero;
```

## Principios para Buenos Nombres

### 1. Revelar Intención

El nombre debe responder: ¿qué es? ¿qué hace? ¿por qué existe?

**Antes:**

```c
int d;  // días transcurridos
int elapsed;  // mejor, pero ¿elapsed desde cuándo?
```

**Después:**

```c
int dias_desde_ultima_modificacion;
int tiempo_transcurrido_en_milisegundos;
```

### 2. Evitar Desinformación

No usar nombres que contradigan el contenido o comportamiento.

**Antes:**

```c
// Engañoso: no es una lista
usuario_t lista_usuarios[100];

// Engañoso: puede retornar NULL
usuario_t* get_usuario_by_id(int id);

// Confuso: ¿incluye o excluye el IVA?
double calcular_precio(double base);
```

**Después:**

```c
usuario_t usuarios[100];
int cantidad_usuarios;

// Retorna NULL si no encuentra
usuario_t* buscar_usuario_por_id(int id);

// Explícito sobre lo que incluye
double calcular_precio_sin_iva(double base);
double calcular_precio_con_iva(double base);
```

### 3. Hacer Distinciones Significativas

Evitar variaciones arbitrarias que no comunican diferencias reales.

**Antes:**

```c
void copiar_cadena(char* a1, char* a2);
void procesar_datos1(int* datos);
void procesar_datos2(int* datos);
void procesar_datos_final(int* datos);

typedef struct {
    char* info;
    char* data;
    char* contenido;
} registro_t;
```

**Después:**

```c
void copiar_cadena(const char* origen, char* destino);
void validar_datos(int* datos);
void transformar_datos(int* datos);
void guardar_datos(int* datos);

typedef struct {
    char* titulo;
    char* descripcion;
    char* cuerpo;
} documento_t;
```

### 4. Usar Nombres Pronunciables

Facilita la comunicación verbal sobre el código.

**Antes:**

```c
struct usrmgr {
    int nusrs;
    char* usrnm[100];
    int usrsts;
};

int gnymdhms(void);  // generation year, month, day, hour, minute, second
```

**Después:**

```c
typedef struct {
    int cantidad_usuarios;
    char* nombres_usuario[100];
    int estado_usuarios;
} gestor_usuarios_t;

typedef struct {
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
} marca_temporal_t;

marca_temporal_t obtener_marca_temporal_actual(void);
```

### 5. Usar Nombres Buscables

Evitar nombres de una sola letra excepto en contextos muy locales.

**Antes:**

```c
// Difícil de buscar
for (int i = 0; i < 7; i++) {
    double s = 0;
    for (int j = 0; j < n; j++) {
        s += a[j] * b[i];
    }
    r[i] = s;
}
```

**Después:**

```c
const int DIAS_SEMANA = 7;

for (int dia = 0; dia < DIAS_SEMANA; dia++) {
    double suma_diaria = 0;
    
    for (int transaccion = 0; transaccion < cantidad_transacciones; transaccion++) {
        suma_diaria += montos[transaccion] * factores[dia];
    }
    
    resultados[dia] = suma_diaria;
}
```

### 6. Evitar Codificación de Tipo

No usar notación húngara ni prefijos de tipo.

**Antes:**

```c
int iEdad;
char* strNombre;
bool bActivo;
float fPrecio;
struct user_struct {
    int iId;
};
```

**Después:**

```c
int edad;
char* nombre;
bool activo;
float precio;

typedef struct {
    int id;
} usuario_t;
```

### 7. Nombres de Clases y Estructuras

Usar sustantivos o frases nominales.

**Antes:**

```c
typedef struct {
    // ...
} procesar_t;

typedef struct {
    // ...
} manager_t;

typedef struct {
    // ...
} data_t;
```

**Después:**

```c
typedef struct {
    // ...
} procesador_pedidos_t;

typedef struct {
    // ...
} gestor_usuarios_t;

typedef struct {
    // ...
} configuracion_sistema_t;
```

### 8. Nombres de Funciones

Usar verbos o frases verbales.

**Antes:**

```c
int cuenta();
void nombre(char* n);
bool estado();
```

**Después:**

```c
int contar_elementos();
void establecer_nombre(const char* nombre);
bool esta_activo();
```

## Técnicas de Refactorización de Nombres

### 1. Renombrado de Variables

**Antes:**

```c
void calcular() {
    int n = obtener_cantidad();
    double p = obtener_precio();
    double d = 0.15;
    double r = n * p * (1 - d);
    
    printf("Total: %.2f\n", r);
}
```

**Después:**

```c
void calcular_total_con_descuento() {
    int cantidad_items = obtener_cantidad();
    double precio_unitario = obtener_precio();
    const double DESCUENTO_MAYORISTA = 0.15;
    double total = cantidad_items * precio_unitario * (1 - DESCUENTO_MAYORISTA);
    
    printf("Total: %.2f\n", total);
}
```

### 2. Renombrado de Funciones por Intención

**Antes:**

```c
bool chequear(usuario_t* u) {
    return u->edad >= 18 && !u->bloqueado;
}

void hacer(pedido_t* p) {
    // procesar pago y envío
}

int get(int id) {
    // busca y retorna
}
```

**Después:**

```c
bool puede_realizar_compra(const usuario_t* usuario) {
    return usuario->edad >= 18 && !usuario->bloqueado;
}

void procesar_pedido_completo(pedido_t* pedido) {
    procesar_pago(pedido);
    iniciar_envio(pedido);
}

int buscar_indice_por_id(int id) {
    // busca y retorna índice, -1 si no encuentra
}
```

### 3. Contexto en Nombres de Estructuras

**Antes:**

```c
typedef struct {
    char* calle;
    char* numero;
    char* ciudad;
    char* provincia;
    char* codigo_postal;
} direccion_t;

typedef struct {
    char* nombre;
    direccion_t direccion;
    
    // Redundante con el contexto
    char* direccion_calle;
    char* direccion_numero;
} cliente_t;
```

**Después:**

```c
typedef struct {
    char* calle;
    char* numero;
    char* ciudad;
    char* provincia;
    char* codigo_postal;
} direccion_t;

typedef struct {
    char* nombre;
    direccion_t domicilio;  // Evita redundancia
} cliente_t;

// Uso
printf("Calle: %s\n", cliente.domicilio.calle);  // Claro por contexto
```

### 4. Nombres Consistentes para Conceptos Similares

**Antes:**

```c
usuario_t* obtener_usuario(int id);
producto_t* fetch_producto(int id);
pedido_t* recuperar_pedido(int id);
factura_t* get_factura(int id);
```

**Después:**

```c
usuario_t* buscar_usuario(int id);
producto_t* buscar_producto(int id);
pedido_t* buscar_pedido(int id);
factura_t* buscar_factura(int id);

// O usando un patrón diferente pero consistente:
usuario_t* obtener_usuario_por_id(int id);
producto_t* obtener_producto_por_id(int id);
pedido_t* obtener_pedido_por_id(int id);
factura_t* obtener_factura_por_id(int id);
```

### 5. Agregar Contexto Significativo

**Antes:**

```c
void imprimir_direccion() {
    char* calle;
    char* numero;
    char* ciudad;
    
    // ... código
    
    printf("%s %s, %s\n", calle, numero, ciudad);
}

// En otro lugar
char* calle;     // ¿De qué?
char* numero;    // ¿De qué?
char* ciudad;    // ¿De qué?
```

**Después:**

```c
typedef struct {
    char* calle;
    char* numero;
    char* ciudad;
    char* provincia;
    char* codigo_postal;
} direccion_t;

void imprimir_direccion(const direccion_t* direccion) {
    printf("%s %s, %s\n", 
           direccion->calle, 
           direccion->numero, 
           direccion->ciudad);
}
```

## Casos Prácticos Completos

### Caso 1: Sistema de Gestión de Inventario

**Código Original:**

```c
typedef struct {
    int id;
    char* n;
    int q;
    float p;
    int min;
    int max;
    char* cat;
} item_t;

int chk(item_t* i) {
    return i->q >= i->min;
}

void upd(item_t* i, int cant) {
    i->q += cant;
}

int proc(item_t* items, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!chk(&items[i])) {
            c++;
        }
    }
    return c;
}
```

**Código Refactorizado:**

```c
typedef struct {
    int codigo_producto;
    char* nombre;
    int cantidad_en_stock;
    float precio_unitario;
    int stock_minimo;
    int stock_maximo;
    char* categoria;
} producto_t;

bool tiene_stock_suficiente(const producto_t* producto) {
    return producto->cantidad_en_stock >= producto->stock_minimo;
}

void actualizar_stock(producto_t* producto, int cantidad_a_agregar) {
    producto->cantidad_en_stock += cantidad_a_agregar;
}

int contar_productos_con_stock_bajo(const producto_t* productos, int cantidad_productos) {
    int productos_con_stock_bajo = 0;
    
    for (int i = 0; i < cantidad_productos; i++) {
        if (!tiene_stock_suficiente(&productos[i])) {
            productos_con_stock_bajo++;
        }
    }
    
    return productos_con_stock_bajo;
}
```

### Caso 2: Procesamiento de Datos de Sensores

**Código Original:**

```c
typedef struct {
    double v;
    long t;
    int s;
} reading_t;

double calc(reading_t* r, int n) {
    double sum = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (r[i].s == 1) {
            sum += r[i].v;
            cnt++;
        }
    }
    
    return cnt > 0 ? sum / cnt : 0;
}

bool val(reading_t* r) {
    return r->v >= 0 && r->v <= 100 && r->s == 1;
}
```

**Código Refactorizado:**

```c
typedef enum {
    SENSOR_ERROR = 0,
    SENSOR_OK = 1,
    SENSOR_ADVERTENCIA = 2
} estado_sensor_t;

typedef struct {
    double temperatura_celsius;
    long marca_temporal_unix;
    estado_sensor_t estado;
} lectura_sensor_t;

double calcular_temperatura_promedio(const lectura_sensor_t* lecturas, 
                                      int cantidad_lecturas) {
    double suma_temperaturas = 0;
    int lecturas_validas = 0;
    
    for (int i = 0; i < cantidad_lecturas; i++) {
        if (lecturas[i].estado == SENSOR_OK) {
            suma_temperaturas += lecturas[i].temperatura_celsius;
            lecturas_validas++;
        }
    }
    
    return (lecturas_validas > 0) ? suma_temperaturas / lecturas_validas : 0;
}

bool es_lectura_valida(const lectura_sensor_t* lectura) {
    const double TEMPERATURA_MINIMA = 0.0;
    const double TEMPERATURA_MAXIMA = 100.0;
    
    return lectura->temperatura_celsius >= TEMPERATURA_MINIMA &&
           lectura->temperatura_celsius <= TEMPERATURA_MAXIMA &&
           lectura->estado == SENSOR_OK;
}
```

### Caso 3: Sistema de Autenticación

**Código Original:**

```c
typedef struct {
    char* u;
    char* p;
    int a;
    long lt;
    int fc;
} usr_t;

int auth(usr_t* u, char* p) {
    if (u->fc >= 3) {
        return -2;
    }
    
    if (strcmp(u->p, p) == 0) {
        u->fc = 0;
        u->lt = time(NULL);
        return 0;
    }
    
    u->fc++;
    return -1;
}

bool chk_t(usr_t* u) {
    long now = time(NULL);
    return (now - u->lt) < 3600;
}
```

**Código Refactorizado:**

```c
typedef struct {
    char* nombre_usuario;
    char* hash_password;
    bool activo;
    time_t ultimo_acceso;
    int intentos_fallidos;
} usuario_t;

typedef enum {
    AUTH_EXITO = 0,
    AUTH_PASSWORD_INCORRECTO = -1,
    AUTH_CUENTA_BLOQUEADA = -2,
    AUTH_USUARIO_INACTIVO = -3
} resultado_autenticacion_t;

resultado_autenticacion_t autenticar_usuario(usuario_t* usuario, 
                                               const char* password) {
    const int MAX_INTENTOS_FALLIDOS = 3;
    
    if (!usuario->activo) {
        return AUTH_USUARIO_INACTIVO;
    }
    
    if (usuario->intentos_fallidos >= MAX_INTENTOS_FALLIDOS) {
        return AUTH_CUENTA_BLOQUEADA;
    }
    
    if (strcmp(usuario->hash_password, password) == 0) {
        usuario->intentos_fallidos = 0;
        usuario->ultimo_acceso = time(NULL);
        return AUTH_EXITO;
    }
    
    usuario->intentos_fallidos++;
    return AUTH_PASSWORD_INCORRECTO;
}

bool sesion_esta_vigente(const usuario_t* usuario) {
    const long DURACION_SESION_SEGUNDOS = 3600;  // 1 hora
    
    time_t tiempo_actual = time(NULL);
    time_t tiempo_transcurrido = tiempo_actual - usuario->ultimo_acceso;
    
    return tiempo_transcurrido < DURACION_SESION_SEGUNDOS;
}
```

## Convenciones de Nomenclatura

### Funciones

**Verbos que indican acción:**

```c
// Acciones
void crear_usuario();
void eliminar_producto();
void actualizar_stock();
void guardar_en_archivo();

// Consultas
int obtener_cantidad();
char* leer_linea();
double calcular_total();

// Predicados (retornan bool)
bool es_valido();
bool tiene_permiso();
bool esta_vacio();
bool puede_procesar();
```

### Variables

**Sustantivos o frases nominales:**

```c
// Buenos nombres de variables
int edad_usuario;
double precio_total;
char* nombre_completo;
bool esta_activo;

// Contadores y acumuladores
int cantidad_elementos;
int total_procesados;
double suma_acumulada;

// Índices y posiciones
int indice_actual;
int posicion_cursor;
```

### Constantes

**Mayúsculas con guiones bajos:**

```c
const int MAX_USUARIOS = 100;
const double TASA_IVA = 0.21;
const char* RUTA_CONFIGURACION = "/etc/app/config.ini";
const int TIMEOUT_CONEXION_SEGUNDOS = 30;
```

### Tipos (Estructuras y Enumeraciones)

**Sufijo `_t` para tipos:**

```c
typedef struct {
    // ...
} usuario_t;

typedef enum {
    ESTADO_ACTIVO,
    ESTADO_INACTIVO,
    ESTADO_BLOQUEADO
} estado_usuario_t;

typedef int (*funcion_comparacion_t)(const void*, const void*);
```

## Patrones de Nombres Específicos

### Pares Get/Set

```c
int obtener_edad(const usuario_t* usuario);
void establecer_edad(usuario_t* usuario, int edad);

char* obtener_nombre(const usuario_t* usuario);
void establecer_nombre(usuario_t* usuario, const char* nombre);
```

### Pares Create/Destroy

```c
usuario_t* crear_usuario(const char* nombre);
void destruir_usuario(usuario_t* usuario);

lista_t* crear_lista(void);
void destruir_lista(lista_t* lista);
```

### Pares Open/Close

```c
archivo_t* abrir_archivo(const char* ruta);
void cerrar_archivo(archivo_t* archivo);

conexion_t* abrir_conexion(const char* host);
void cerrar_conexion(conexion_t* conexion);
```

### Pares Begin/End

```c
void iniciar_transaccion(void);
void finalizar_transaccion(void);

void comenzar_procesamiento(void);
void terminar_procesamiento(void);
```

## Antipatrones a Evitar

### 1. Ruido en Nombres

```c
// Problemático: palabras que no agregan información
int the_numero;
char* a_nombre;
void do_proceso();

typedef struct {
    int dato_numero;
    char* info_cadena;
} objeto_data_t;
```

### 2. Diferencias Sutiles

```c
// Problemático: demasiado similar, fácil confundir
void procesar_cliente_activo();
void procesar_clientes_activos();

usuario_t usuario;
usuario_t usuarios;  // Plural solo difiere en 's'
```

### 3. Nombres Dependientes del Contexto

```c
// Problemático en diferentes archivos
// archivo1.c
int contador;  // Cuenta usuarios

// archivo2.c
int contador;  // Cuenta productos

// Mejor: específico
int contador_usuarios;
int contador_productos;
```

## Resumen

Principios para buenos nombres:

1. **Revelar Intención:** El nombre debe ser auto-explicativo
2. **Evitar Desinformación:** No usar nombres engañosos
3. **Distinciones Significativas:** Diferencias claras y útiles
4. **Pronunciables:** Facilita la comunicación
5. **Buscables:** Evitar nombres de una letra en alcance amplio
6. **Sin Codificación:** No notación húngara
7. **Sustantivos para Datos:** Clases, estructuras, variables
8. **Verbos para Acciones:** Funciones
9. **Consistencia:** Mismo concepto, mismo nombre
10. **Contexto Apropiado:** Ni muy poco ni demasiado

**Beneficios:**
- Código auto-documentado
- Menor necesidad de comentarios
- Más fácil de entender y mantener
- Reduce errores por confusión
- Facilita colaboración

Los buenos nombres son inversión, no gasto. El tiempo dedicado a elegir nombres apropiados se recupera ampliamente en mantenimiento y comprensión.
