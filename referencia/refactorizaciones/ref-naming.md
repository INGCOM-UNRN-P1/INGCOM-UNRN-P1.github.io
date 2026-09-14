---
title: "Mejora de Nombres y Comunicación de Intenciones"
short_title: "Cambios de nombres"
subtitle: "Técnicas para elegir nombres que revelen intenciones y mejoren la comprensión"
---
(refactorizacion-naming)=

## Introducción

Los nombres son la forma más básica y fundamental de documentación en el código.
Un buen nombre comunica propósito, tipo, alcance y restricciones sin necesidad
de comentarios adicionales. Por el contrario, nombres pobres oscurecen la
intención, aumentan la carga cognitiva y conducen a errores.

Este apunte presenta técnicas sistemáticas para mejorar los nombres en el
código, desde variables y funciones hasta tipos y constantes, con el objetivo de
hacer el código auto-explicativo y mantener la coherencia en todo el proyecto.

:::{important} Nombres Reveladores de Intención

Como establece {ref}`0x0101h`, los identificadores deben ser descriptivos y
reflejar con precisión su propósito. Un nombre bien elegido es una forma de
documentación que nunca queda desactualizada.

:::
<!-- {important} Nombres Reveladores de Intención -->

## Reglas de estilo que resuelve

Esta refactorización no depende del gusto personal: responde a los problemas
concretos que modelan las reglas de nomenclatura de la cátedra. Cuando un nombre
es críptico, inconsistente, engañoso o está mal formado, hay una regla que
explica por qué y una técnica de esta guía que lo corrige. La tabla siguiente
mapea cada regla con el problema que modela y con la técnica que lo resuelve.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
| :--- | :--- | :--- |
| {ref}`0x0101h` | Identificadores sin propósito claro | Reemplaza nombres crípticos por otros que revelan intención. |
| {ref}`0x0102h` | Variables y parámetros en otras convenciones | Unifica variables locales y argumentos en snake_case. |
| {ref}`0x0103h` | Constantes en minúsculas o camelCase | Pasa los `const` a MAYUSCULAS_SNAKE_CASE. |
| {ref}`0x0104h` | Archivos con mayúsculas, espacios o guiones | Renombra los archivos a snake_case en minúsculas. |
| {ref}`0x0105h` | Funciones en PascalCase, camelCase o abreviaturas | Estandariza los nombres de función en snake_case estricto. |
| {ref}`0x0106h` | Globales sin `static` ni prefijo | Marca las globales como `static` o las prefija con `g_`. |
| {ref}`0x0107h` | Macros `#define` en minúsculas o camelCase | Renombra las macros a MAYUSCULAS_SNAKE_CASE. |
| {ref}`0x0108h` | Identificadores con acentos o `ñ` | Elimina todo carácter no ASCII de los nombres. |
| {ref}`0x0109h` | Nombres que chocan con palabras clave o tipos estándar | Renombra para evitar colisiones con el lenguaje y la biblioteca. |
| {ref}`0x010Ah` | Prefijos `_` y `__` reservados al compilador | Elimina los prefijos reservados del identificador. |
| {ref}`0x010Bh` | Nombres de una letra en alcance amplio o kilométricos | Ajusta la longitud del nombre a su alcance real. |
| {ref}`0x010Ch` | `__` o guion bajo inicial detectados sin auditoría | Aplica el auditor de identificadores reservados. |
| {ref}`0x010Dh` | Constantes simbólicas con convenciones mezcladas | Homogeneiza el estilo de todas las constantes. |
| {ref}`0x010Eh` | Sufijos numéricos (`datos1`, `datos2`) o afijos de tipo | Reemplaza los genéricos numerados por nombres con contexto. |
| {ref}`0x0110h` | Booleanos llamados `flag`, `activo` o `estado` | Renombra con prefijo interrogativo (`es_`, `tiene_`, `puede_`). |
| {ref}`0x0111h` | Nombres negados que se combinan con `!` | Formula los nombres en positivo y evita dobles negaciones. |
| {ref}`0x3004h` | `struct` sin `typedef` ni sufijo `_t` | Define los tipos de estructura con `typedef` y sufijo `_t`. |

## Problemas Comunes con Nombres

### 1. Nombres Crípticos o Abreviados

Los nombres de una o dos letras solo son tolerables en alcances muy locales;
fuera de ahí violan la proporcionalidad que pide {ref}`0x010Bh` y sacrifican la
intención que exige {ref}`0x0101h`.

```{code-block} c
:linenos:
// Problemático: nombres sin significado claro
int d;         // ¿días? ¿dinero? ¿distancia?
int tmp;       // temporal... ¿para qué?
int x, y;      // ¿coordenadas? ¿variables matemáticas?
char buf[256]; // ¿buffer de qué?
void proc(int n)
{ // ¿procesar qué?
  // ...
}
```
<!-- {code-block} c -->

### 2. Nombres Engañosos

Un booleano que en realidad verifica una sola condición es un nombre engañoso;
para los booleanos, {ref}`0x0110h` pide un prefijo interrogativo (`es_`, `tiene_`,
`puede_`).

```{code-block} c
:linenos:
// Problemático: nombres que no reflejan el contenido real
int dias_del_mes;            // Contiene el número del mes, no los días
char *get_usuario();         // Retorna NULL si no existe, no "obtiene"
bool validar_email(char *e); // Solo verifica formato, no valida existencia
// Array que NO contiene elementos de ese tipo
usuario_t usuarios_activos[100]; // Puede tener usuarios inactivos
```
<!-- {code-block} c -->

### 3. Inconsistencia en Nomenclatura

Mezclar `obtener_edad`, `getAltura` y `fetch_peso` viola a la vez
{ref}`0x0105h` y {ref}`0x010Dh`: el mismo concepto debería nombrarse con una
única convención.

```{code-block} c
:linenos:
// Problemático: diferentes convenciones mezcladas
int obtener_edad();
int getAltura();
int fetch_peso();
int edad_recuperar();
typedef struct
{
    int ID;          // Mayúsculas
    char *nombre;    // minúsculas
    int EdadPersona; // PascalCase
} usuario_t;
```
<!-- {code-block} c -->

### 4. Nombres Genéricos Sin Contexto

`calcular(int a, int b)` no dice nada ni sobre la operación ni sobre los
argumentos; renombrarlos es también un deber de {ref}`0x0102h`, y los afijos
numerados como `datos1`/`datos2` caen bajo {ref}`0x010Eh`.

```{code-block} c
:linenos:
// Problemático: nombres demasiado genéricos
void procesar(void *datos);
int calcular(int a, int b);
char *obtener_valor();
bool es_valido();
typedef struct
{
    int valor;
    char *dato;
    void *info;
} elemento_t;
```
<!-- {code-block} c -->

### 5. Información de Tipo en el Nombre

La notación húngara y los sufijos de tipo (`nombre_string`, `edad_entero`) son
afijos redundantes que {ref}`0x010Eh` desaconseja.

```{code-block} c
:linenos:
// Problemático: notación húngara o prefijos de tipo
int iContador;
char *strNombre;
bool bActivo;
float fPrecio;
// Redundante
char nombre_string[50];
int edad_entero;
```
<!-- {code-block} c -->

### 6. Colisiones y Prefijos Reservados

```{code-block} c
:linenos:
// Problemático: choca con palabras clave y tipos estándar
int free;        // función de <stdlib.h>
int malloc;      // función de <stdlib.h>
struct open {};  // nombre de función estándar
// Problemático: prefijos reservados al compilador
int _contador;
int __interno;
double __atributo_x;
```
<!-- {code-block} c -->

Estos nombres colisionan con lo que prohíbe {ref}`0x0109h` y usan los prefijos
que {ref}`0x010Ah` y {ref}`0x010Ch` reservan a la implementación. El guion bajo
inicial y el doble guion bajo son territorio del compilador o del sistema:
evitalos siempre.

### 7. Constantes y Macros Inconsistentes

```{code-block} c
:linenos:
// Problemático: las constantes no siguen una única convención
#define maxItems 100
#define TIMEOUT 30
const double tasa_iva = 0.21;
const int MAX_CONEXIONES = 5;
```
<!-- {code-block} c -->

Los `#define` deben ir en MAYUSCULAS_SNAKE_CASE ({ref}`0x0107h`) y las
constantes de cualquier tipo deben ser consistentes entre sí
({ref}`0x0103h`, {ref}`0x010Dh`).

### 8. Archivos y Variables Globales

Un archivo `GestionUsuarios.C` viola {ref}`0x0104h`: los nombres de archivo van
en snake_case y minúsculas (`gestion_usuarios.c`). Una global como
`int contador;` definida sin `static` queda expuesta a todo el programa;
{ref}`0x0106h` exige marcarla `static` o prefijarla con `g_`
(`static int contador;` o `int g_contador;`). Además, nada justifica un
identificador con acentos o `ñ` (`año`, `dirección`): {ref}`0x0108h` los
prohíbe aunque parezcan descriptivos.

## Principios para Buenos Nombres

### 1. Revelar Intención

El nombre debe responder: ¿qué es? ¿qué hace? ¿por qué existe?

**Antes:**

``` c
int d;       // días transcurridos
int elapsed; // mejor, pero ¿elapsed desde cuándo?
```
<!-- c -->

**Después:**

``` c
int dias_desde_ultima_modificacion;
int tiempo_transcurrido_en_milisegundos;
```
<!-- c -->

### 2. Evitar Desinformación

No usar nombres que contradigan el contenido o comportamiento.

**Antes:**

```{code-block} c
:linenos:
// Engañoso: no es una lista
usuario_t lista_usuarios[100];
// Engañoso: puede retornar NULL
usuario_t *get_usuario_by_id(int id);
// Confuso: ¿incluye o excluye el IVA?
double calcular_precio(double base);
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
usuario_t usuarios[100];
int cantidad_usuarios;
// Retorna NULL si no encuentra
usuario_t *buscar_usuario_por_id(int id);
// Explícito sobre lo que incluye
double calcular_precio_sin_iva(double base);
double calcular_precio_con_iva(double base);
```
<!-- {code-block} c -->

### 3. Hacer Distinciones Significativas

Evitar variaciones arbitrarias que no comunican diferencias reales.

**Antes:**

```{code-block} c
:linenos:
void copiar_cadena(char *a1, char *a2);
void procesar_datos1(int *datos);
void procesar_datos2(int *datos);
void procesar_datos_final(int *datos);
typedef struct
{
    char *info;
    char *data;
    char *contenido;
} registro_t;
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void copiar_cadena(const char *origen, char *destino);
void validar_datos(int *datos);
void transformar_datos(int *datos);
void guardar_datos(int *datos);
typedef struct
{
    char *titulo;
    char *descripcion;
    char *cuerpo;
} documento_t;
```
<!-- {code-block} c -->

### 4. Usar Nombres Pronunciables

Facilita la comunicación verbal sobre el código; para eso hay que evitar
caracteres no ASCII ({ref}`0x0108h`) y elegir una longitud acorde al alcance
({ref}`0x010Bh`).

**Antes:**

```{code-block} c
:linenos:
struct usrmgr
{
    int nusrs;
    char *usrnm[100];
    int usrsts;
};
int gnymdhms(void); // generation year, month, day, hour, minute, second
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef struct
{
    int cantidad_usuarios;
    char *nombres_usuario[100];
    int estado_usuarios;
} gestor_usuarios_t;
typedef struct
{
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
} marca_temporal_t;
marca_temporal_t obtener_marca_temporal_actual(void);
```
<!-- {code-block} c -->

### 5. Usar Nombres Buscables

Evitar nombres de una sola letra excepto en contextos muy locales
({ref}`0x010Bh`); además, los valores fijos deben extraerse a constantes con
nombre en MAYUSCULAS_SNAKE_CASE ({ref}`0x0103h`).

**Antes:**

```{code-block} c
:linenos:
// Difícil de buscar
for (int i = 0; i < 7; i++)
{
    double s = 0;
    for (int j = 0; j < n; j++)
    {
        s += a[j] * b[i];
    }
    r[i] = s;
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
const int DIAS_SEMANA = 7;
for (int dia = 0; dia < DIAS_SEMANA; dia++)
{
    double suma_diaria = 0;
    for (int transaccion = 0; transaccion < cantidad_transacciones;
         transaccion++)
    {
        suma_diaria += montos[transaccion] * factores[dia];
    }
    resultados[dia] = suma_diaria;
}
```
<!-- {code-block} c -->

### 6. Evitar Codificación de Tipo

No usar notación húngara ni prefijos de tipo: son afijos redundantes que rechaza
{ref}`0x010Eh`. La estructura debe declararse con `typedef` y sufijo `_t` según
{ref}`0x3004h`.

**Antes:**

```{code-block} c
:linenos:
int iEdad;
char *strNombre;
bool bActivo;
float fPrecio;
struct user_struct
{
    int iId;
};
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
int edad;
char *nombre;
bool activo;
float precio;
typedef struct
{
    int id;
} usuario_t;
```
<!-- {code-block} c -->

### 7. Nombres de Clases y Estructuras

Usar sustantivos o frases nominales y, en C, definir cada tipo con `typedef` y
sufijo `_t` ({ref}`0x3004h`).

**Antes:**

```{code-block} c
:linenos:
typedef struct
{
    // ...
} procesar_t;
typedef struct
{
    // ...
} manager_t;
typedef struct
{
    // ...
} data_t;
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef struct
{
    // ...
} procesador_pedidos_t;
typedef struct
{
    // ...
} gestor_usuarios_t;
typedef struct
{
    // ...
} configuracion_sistema_t;
```
<!-- {code-block} c -->

### 8. Nombres de Funciones

Usar verbos o frases verbales, en snake_case estricto ({ref}`0x0105h`) y con
prefijo interrogativo cuando retornan un booleano ({ref}`0x0110h`).

**Antes:**

``` c
int cuenta();
void nombre(char *n);
bool estado();
```
<!-- c -->

**Después:**

``` c
int contar_elementos();
void establecer_nombre(const char *nombre);
bool esta_activo();
```
<!-- c -->

## Técnicas de Refactorización de Nombres

### 1. Renombrado de Variables

Las locales y los parámetros van en snake_case ({ref}`0x0102h`); los valores
fijos que aparecen en el cuerpo se elevan a constantes en MAYUSCULAS_SNAKE_CASE
({ref}`0x0103h`) y las variables de poco uso no deben quedar en una sola letra
({ref}`0x010Bh`).

**Antes:**

```{code-block} c
:linenos:
void calcular()
{
    int n = obtener_cantidad();
    double p = obtener_precio();
    double d = 0.15;
    double r = n * p * (1 - d);
    printf("Total: %.2f\n", r);
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void calcular_total_con_descuento()
{
    int cantidad_items = obtener_cantidad();
    double precio_unitario = obtener_precio();
    const double DESCUENTO_MAYORISTA = 0.15;
    double total =
        cantidad_items * precio_unitario * (1 - DESCUENTO_MAYORISTA);
    printf("Total: %.2f\n", total);
}
```
<!-- {code-block} c -->

### 2. Renombrado de Funciones por Intención

Los nombres de función siguen snake_case estricto ({ref}`0x0105h`); los
predicados booleanos usan prefijo interrogativo ({ref}`0x0110h`) y se formulan
en positivo para no arrastrar dobles negaciones ({ref}`0x0111h`).

**Antes:**

```{code-block} c
:linenos:
bool chequear(usuario_t *u)
{
    return u->edad >= 18 && !u->bloqueado;
}
void hacer(pedido_t *p)
{
    // procesar pago y envío
}
int get(int id)
{
    // busca y retorna
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
bool puede_realizar_compra(const usuario_t *usuario)
{
    return usuario->edad >= 18 && !usuario->bloqueado;
}
void procesar_pedido_completo(pedido_t *pedido)
{
    procesar_pago(pedido);
    iniciar_envio(pedido);
}
int buscar_indice_por_id(int id)
{
    // busca y retorna índice, -1 si no encuentra
}
```
<!-- {code-block} c -->

### 3. Contexto en Nombres de Estructuras

El tipo se define con `typedef` y sufijo `_t` ({ref}`0x3004h`), y sus campos
evitan repetir el contexto del tipo o llevar prefijos innecesarios
({ref}`0x010Bh`).

**Antes:**

```{code-block} c
:linenos:
typedef struct
{
    char *calle;
    char *numero;
    char *ciudad;
    char *provincia;
    char *codigo_postal;
} direccion_t;
typedef struct
{
    char *nombre;
    direccion_t direccion;
    // Redundante con el contexto
    char *direccion_calle;
    char *direccion_numero;
} cliente_t;
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef struct
{
    char *calle;
    char *numero;
    char *ciudad;
    char *provincia;
    char *codigo_postal;
} direccion_t;
typedef struct
{
    char *nombre;
    direccion_t domicilio; // Evita redundancia
} cliente_t;
// Uso
printf("Calle: %s\n", cliente.domicilio.calle); // Claro por contexto
```
<!-- {code-block} c -->

### 4. Nombres Consistentes para Conceptos Similares

Un mismo concepto debe usar un mismo verbo y una misma convención
({ref}`0x010Dh`, {ref}`0x0105h`).

**Antes:**

``` c
usuario_t *obtener_usuario(int id);
producto_t *fetch_producto(int id);
pedido_t *recuperar_pedido(int id);
factura_t *get_factura(int id);
```
<!-- c -->

**Después:**

```{code-block} c
:linenos:
usuario_t *buscar_usuario(int id);
producto_t *buscar_producto(int id);
pedido_t *buscar_pedido(int id);
factura_t *buscar_factura(int id);
// O usando un patrón diferente pero consistente:
usuario_t *obtener_usuario_por_id(int id);
producto_t *obtener_producto_por_id(int id);
pedido_t *obtener_pedido_por_id(int id);
factura_t *obtener_factura_por_id(int id);
```
<!-- {code-block} c -->

### 5. Agregar Contexto Significativo

Agrupar los datos en un tipo con `typedef` y sufijo `_t` ({ref}`0x3004h`) evita
variables sueltas con nombres ambiguos y da contexto a cada campo
({ref}`0x0102h`).

**Antes:**

```{code-block} c
:linenos:
void imprimir_direccion()
{
    char *calle;
    char *numero;
    char *ciudad;
    // ... código
    printf("%s %s, %s\n", calle, numero, ciudad);
}
// En otro lugar
char *calle;  // ¿De qué?
char *numero; // ¿De qué?
char *ciudad; // ¿De qué?
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
typedef struct
{
    char *calle;
    char *numero;
    char *ciudad;
    char *provincia;
    char *codigo_postal;
} direccion_t;
void imprimir_direccion(const direccion_t *direccion)
{
    printf("%s %s, %s\n", direccion->calle, direccion->numero,
           direccion->ciudad);
}
```
<!-- {code-block} c -->

## Casos Prácticos Completos

Cada caso muestra un módulo completo antes y después. En todos ellos se resuelven
la intención de los nombres ({ref}`0x0101h`), la convención snake_case de
variables y funciones ({ref}`0x0102h`, {ref}`0x0105h`), las constantes
simbólicas ({ref}`0x0103h`, {ref}`0x010Dh`) y la definición de tipos con sufijo
`_t` ({ref}`0x3004h`).

### Caso 1: Sistema de Gestión de Inventario

**Código Original:**

```{code-block} c
:linenos:
typedef struct
{
    int id;
    char *n;
    int q;
    float p;
    int min;
    int max;
    char *cat;
} item_t;
int chk(item_t *i)
{
    return i->q >= i->min;
}
void upd(item_t *i, int cant)
{
    i->q += cant;
}
int proc(item_t *items, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!chk(&items[i]))
        {
            c++;
        }
    }
    return c;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef struct
{
    int codigo_producto;
    char *nombre;
    int cantidad_en_stock;
    float precio_unitario;
    int stock_minimo;
    int stock_maximo;
    char *categoria;
} producto_t;
bool tiene_stock_suficiente(const producto_t *producto)
{
    return producto->cantidad_en_stock >= producto->stock_minimo;
}
void actualizar_stock(producto_t *producto, int cantidad_a_agregar)
{
    producto->cantidad_en_stock += cantidad_a_agregar;
}
int contar_productos_con_stock_bajo(const producto_t *productos,
                                    int cantidad_productos)
{
    int productos_con_stock_bajo = 0;
    for (int i = 0; i < cantidad_productos; i++)
    {
        if (!tiene_stock_suficiente(&productos[i]))
        {
            productos_con_stock_bajo++;
        }
    }
    return productos_con_stock_bajo;
}
```
<!-- {code-block} c -->

### Caso 2: Procesamiento de Datos de Sensores

**Código Original:**

```{code-block} c
:linenos:
typedef struct
{
    double v;
    long t;
    int s;
} reading_t;
double calc(reading_t *r, int n)
{
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (r[i].s == 1)
        {
            sum += r[i].v;
            cnt++;
        }
    }
    return cnt > 0 ? sum / cnt : 0;
}
bool val(reading_t *r)
{
    return r->v >= 0 && r->v <= 100 && r->s == 1;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef enum
{
    SENSOR_ERROR = 0,
    SENSOR_OK = 1,
    SENSOR_ADVERTENCIA = 2
} estado_sensor_t;
typedef struct
{
    double temperatura_celsius;
    long marca_temporal_unix;
    estado_sensor_t estado;
} lectura_sensor_t;
double calcular_temperatura_promedio(const lectura_sensor_t *lecturas,
                                     int cantidad_lecturas)
{
    double suma_temperaturas = 0;
    int lecturas_validas = 0;
    for (int i = 0; i < cantidad_lecturas; i++)
    {
        if (lecturas[i].estado == SENSOR_OK)
        {
            suma_temperaturas += lecturas[i].temperatura_celsius;
            lecturas_validas++;
        }
    }
    return (lecturas_validas > 0) ? suma_temperaturas / lecturas_validas : 0;
}
bool es_lectura_valida(const lectura_sensor_t *lectura)
{
    const double TEMPERATURA_MINIMA = 0.0;
    const double TEMPERATURA_MAXIMA = 100.0;
    return lectura->temperatura_celsius >= TEMPERATURA_MINIMA &&
           lectura->temperatura_celsius <= TEMPERATURA_MAXIMA &&
           lectura->estado == SENSOR_OK;
}
```
<!-- {code-block} c -->

### Caso 3: Sistema de Autenticación

**Código Original:**

```{code-block} c
:linenos:
typedef struct
{
    char *u;
    char *p;
    int a;
    long lt;
    int fc;
} usr_t;
int auth(usr_t *u, char *p)
{
    if (u->fc >= 3)
    {
        return -2;
    }
    if (strcmp(u->p, p) == 0)
    {
        u->fc = 0;
        u->lt = time(NULL);
        return 0;
    }
    u->fc++;
    return -1;
}
bool chk_t(usr_t *u)
{
    long now = time(NULL);
    return (now - u->lt) < 3600;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef struct
{
    char *nombre_usuario;
    char *hash_password;
    bool activo;
    time_t ultimo_acceso;
    int intentos_fallidos;
} usuario_t;
typedef enum
{
    AUTH_EXITO = 0,
    AUTH_PASSWORD_INCORRECTO = -1,
    AUTH_CUENTA_BLOQUEADA = -2,
    AUTH_USUARIO_INACTIVO = -3
} resultado_autenticacion_t;
resultado_autenticacion_t autenticar_usuario(usuario_t *usuario,
                                             const char *password)
{
    const int MAX_INTENTOS_FALLIDOS = 3;
    if (!usuario->activo)
    {
        return AUTH_USUARIO_INACTIVO;
    }
    if (usuario->intentos_fallidos >= MAX_INTENTOS_FALLIDOS)
    {
        return AUTH_CUENTA_BLOQUEADA;
    }
    if (strcmp(usuario->hash_password, password) == 0)
    {
        usuario->intentos_fallidos = 0;
        usuario->ultimo_acceso = time(NULL);
        return AUTH_EXITO;
    }
    usuario->intentos_fallidos++;
    return AUTH_PASSWORD_INCORRECTO;
}
bool sesion_esta_vigente(const usuario_t *usuario)
{
    const long DURACION_SESION_SEGUNDOS = 3600; // 1 hora
    time_t tiempo_actual = time(NULL);
    time_t tiempo_transcurrido = tiempo_actual - usuario->ultimo_acceso;
    return tiempo_transcurrido < DURACION_SESION_SEGUNDOS;
}
```
<!-- {code-block} c -->

## Convenciones de Nomenclatura

### Funciones

Los nombres de función van en snake_case estricto ({ref}`0x0105h`) y los
predicados booleanos llevan prefijo interrogativo ({ref}`0x0110h`).

**Verbos que indican acción:**

```{code-block} c
:linenos:
// Acciones
void crear_usuario();
void eliminar_producto();
void actualizar_stock();
void guardar_en_archivo();
// Consultas
int obtener_cantidad();
char *leer_linea();
double calcular_total();
// Predicados (retornan bool)
bool es_valido();
bool tiene_permiso();
bool esta_vacio();
bool puede_procesar();
```
<!-- {code-block} c -->

### Variables

Variables locales y parámetros en snake_case ({ref}`0x0102h`), con nombres que
revelan su intención ({ref}`0x0101h`).

**Sustantivos o frases nominales:**

```{code-block} c
:linenos:
// Buenos nombres de variables
int edad_usuario;
double precio_total;
char *nombre_completo;
bool esta_activo;
// Contadores y acumuladores
int cantidad_elementos;
int total_procesados;
double suma_acumulada;
// Índices y posiciones
int indice_actual;
int posicion_cursor;
```
<!-- {code-block} c -->

### Constantes

Las constantes usan MAYUSCULAS_SNAKE_CASE ({ref}`0x0103h`) de forma consistente
({ref}`0x010Dh`), y las macros `#define` siguen la misma convención
({ref}`0x0107h`).

**Mayúsculas con guiones bajos:**

``` c
const int MAX_USUARIOS = 100;
const double TASA_IVA = 0.21;
const char *RUTA_CONFIGURACION = "/etc/app/config.ini";
const int TIMEOUT_CONEXION_SEGUNDOS = 30;
```
<!-- c -->

### Tipos (Estructuras y Enumeraciones)

Cada estructura, enumeración o puntero a función se define con `typedef` y sufijo
`_t` ({ref}`0x3004h`).

**Sufijo `_t` para tipos:**

```{code-block} c
:linenos:
typedef struct
{
    // ...
} usuario_t;
typedef enum
{
    ESTADO_ACTIVO,
    ESTADO_INACTIVO,
    ESTADO_BLOQUEADO
} estado_usuario_t;
typedef int (*funcion_comparacion_t)(const void *, const void *);
```
<!-- {code-block} c -->

## Patrones de Nombres Específicos

### Pares Get/Set

``` c
int obtener_edad(const usuario_t *usuario);
void establecer_edad(usuario_t *usuario, int edad);
char *obtener_nombre(const usuario_t *usuario);
void establecer_nombre(usuario_t *usuario, const char *nombre);
```
<!-- c -->

### Pares Create/Destroy

``` c
usuario_t *crear_usuario(const char *nombre);
void destruir_usuario(usuario_t *usuario);
lista_t *crear_lista(void);
void destruir_lista(lista_t *lista);
```
<!-- c -->

### Pares Open/Close

``` c
archivo_t *abrir_archivo(const char *ruta);
void cerrar_archivo(archivo_t *archivo);
conexion_t *abrir_conexion(const char *host);
void cerrar_conexion(conexion_t *conexion);
```
<!-- c -->

### Pares Begin/End

``` c
void iniciar_transaccion(void);
void finalizar_transaccion(void);
void comenzar_procesamiento(void);
void terminar_procesamiento(void);
```
<!-- c -->

## Antipatrones a Evitar

### 1. Ruido en Nombres

Palabras como "the", "do" o afijos de tipo no agregan información; son los
afijos genéricos que {ref}`0x010Eh` manda eliminar.

```{code-block} c
:linenos:
// Problemático: palabras que no agregan información
int the_numero;
char *a_nombre;
void do_proceso();
typedef struct
{
    int dato_numero;
    char *info_cadena;
} objeto_data_t;
```
<!-- {code-block} c -->

### 2. Diferencias Sutiles

Variantes que solo cambian por un sufijo numérico o una letra son exactamente lo
que {ref}`0x010Eh` y {ref}`0x010Bh` desaconsejan: no comunican diferencias
reales.

``` c
// Problemático: demasiado similar, fácil confundir
void procesar_cliente_activo();
void procesar_clientes_activos();
usuario_t usuario;
usuario_t usuarios; // Plural solo difiere en 's'
```
<!-- c -->

### 3. Nombres Dependientes del Contexto

Las globales con nombres genéricos exponen su significado al archivo donde se
leen; esto lo atacan {ref}`0x0106h` (marcarlas `static` o prefijarlas) y
{ref}`0x010Bh` (darles alcance y longitud coherentes).

```{code-block} c
:linenos:
// Problemático en diferentes archivos
// archivo1.c
int contador; // Cuenta usuarios
// archivo2.c
int contador; // Cuenta productos
// Mejor: específico
int contador_usuarios;
int contador_productos;
```
<!-- {code-block} c -->

## Ejemplo Integrador

Un mismo fragmento puede violar varias reglas a la vez. El módulo siguiente
comete errores de intención, convención, prefijos reservados, codificación de
tipo, booleanos y tipos. La versión refactorizada los resuelve en conjunto.

**❌ Antes:**

```{code-block} c
:linenos:
#define maxUsers 50
int userCount; // global sin static ni prefijo g_

typedef struct
{
    int idUsuario;      // camelCase en campo
    char *nombreCompleto;
    int __estado;       // prefijo reservado y nombre opaco
    int añoAlta;        // carácter no ASCII
} User;                 // sin typedef ni sufijo _t

int CheckUser(User u, int idx) // PascalCase y parámetros pobres
{
    if (!u.__estado)           // doble negación
    {
        return 0;
    }
    return 1;
}

void ProcessAll(User users[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (CheckUser(users[i], i))
        {
            printf("%d\n", users[i].idUsuario);
        }
    }
}
```
<!-- {code-block} c -->

**✅ Después:**

```{code-block} c
:linenos:
#define MAX_USUARIOS 50

static int g_usuarios_activos;

typedef struct
{
    int id_usuario;
    char *nombre_completo;
    bool esta_activo;
    int anio_alta;
} usuario_t;

bool usuario_esta_activo(const usuario_t *usuario)
{
    return usuario->esta_activo;
}

void procesar_usuarios(const usuario_t *usuarios, int cantidad_usuarios)
{
    for (int indice = 0; indice < cantidad_usuarios; indice++)
    {
        if (usuario_esta_activo(&usuarios[indice]))
        {
            printf("%d\n", usuarios[indice].id_usuario);
        }
    }
}
```
<!-- {code-block} c -->

Qué resolvió cada cambio:

- La macro pasó de `maxUsers` a `MAX_USUARIOS` ({ref}`0x0107h`) y la global
  `userCount` se reemplazó por `g_usuarios_activos` con `static`
  ({ref}`0x0106h`).
- El tipo `User` se convirtió en `usuario_t` con `typedef` y sufijo `_t`
  ({ref}`0x3004h`); los campos `idUsuario`, `nombreCompleto` y `añoAlta` ahora
  son `id_usuario`, `nombre_completo` y `anio_alta`, sin caracteres no ASCII
  ({ref}`0x0102h`, {ref}`0x0108h`).
- El campo reservado `__estado` desapareció y se reemplazó por el booleano
  positivo `esta_activo` ({ref}`0x010Ah`, {ref}`0x010Ch`, {ref}`0x0110h`,
  {ref}`0x0111h`).
- Las funciones `CheckUser` y `ProcessAll` se volvieron
  `usuario_esta_activo` y `procesar_usuarios` ({ref}`0x0105h`), y el índice
  genérico `idx` se convirtió en `indice` ({ref}`0x010Eh`).

## Diagnóstico y refactorización

Usá esta tabla para ir del síntoma observado en el código hasta la técnica de
esta guía que lo corrige.

| Regla | Síntoma en el código | Técnica de esta guía |
| :--- | :--- | :--- |
| {ref}`0x0101h` | `int d;`, `void proc(int n)` sin significado | Renombrar revelando intención (secciones 1 a 8 de principios). |
| {ref}`0x0102h` | Campos o parámetros en `camelCase` (`idUsuario`) | Unificar variables locales y parámetros en snake_case. |
| {ref}`0x0103h` | `const double tasa_iva = 0.21;` en minúsculas | Elevar a `TASA_IVA` en MAYUSCULAS_SNAKE_CASE. |
| {ref}`0x0104h` | `GestionUsuarios.C` con mayúsculas | Renombrar el archivo a `gestion_usuarios.c`. |
| {ref}`0x0105h` | `CheckUser`, `getAltura`, `ProcessAll` | Unificar en snake_case estricto (`usuario_esta_activo`). |
| {ref}`0x0106h` | `int userCount;` global visible en todo el programa | Marcar `static` o prefijar con `g_`. |
| {ref}`0x0107h` | `#define maxItems 100` | Renombrar a `MAX_ITEMS`. |
| {ref}`0x0108h` | `int añoAlta;` con `ñ` | Sustituir por `anio_alta`. |
| {ref}`0x0109h` | `int free;`, `struct open {};` | Renombrar para evitar palabras clave y funciones estándar. |
| {ref}`0x010Ah` | `int __interno;`, `int _contador;` | Quitar los prefijos reservados al compilador. |
| {ref}`0x010Bh` | `int i` en función larga o nombre kilométrico | Ajustar la longitud del nombre a su alcance. |
| {ref}`0x010Ch` | Auditoría de `__` o guion bajo inicial | Pasar el auditor de identificadores reservados. |
| {ref}`0x010Dh` | `tasa_iva` junto a `MAX_CONEXIONES` | Homogeneizar la convención de constantes. |
| {ref}`0x010Eh` | `datos1`, `datos2`, `strNombre`, `idx` | Eliminar sufijos numéricos y afijos de tipo. |
| {ref}`0x0110h` | `bool activo;` o `bool flag;` | Renombrar a `esta_activo` con prefijo interrogativo. |
| {ref}`0x0111h` | `if (!no_hay_error)` | Formular en positivo y evitar dobles negaciones. |
| {ref}`0x3004h` | `struct user_struct { ... };` sin `typedef` | Definir `usuario_t` con `typedef` y sufijo `_t`. |

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

Los buenos nombres son inversión, no gasto. El tiempo dedicado a elegir nombres
apropiados se recupera ampliamente en mantenimiento y comprensión.

## Checklist de verificación

- [ ] ¿Cada identificador revela su intención ({ref}`0x0101h`) y tiene una
      longitud proporcional a su alcance ({ref}`0x010Bh`)?
- [ ] ¿Variables locales y parámetros están en snake_case ({ref}`0x0102h`) y las
      funciones en snake_case estricto ({ref}`0x0105h`)?
- [ ] ¿Las constantes `const` ({ref}`0x0103h`) y las macros `#define`
      ({ref}`0x0107h`) usan MAYUSCULAS_SNAKE_CASE de forma consistente
      ({ref}`0x010Dh`)?
- [ ] ¿Los nombres de archivo están en snake_case y minúsculas
      ({ref}`0x0104h`)?
- [ ] ¿Toda variable global es `static` o lleva prefijo `g_` ({ref}`0x0106h`)?
- [ ] ¿Evitaste acentos y `ñ` en identificadores ({ref}`0x0108h`) y colisiones
      con palabras clave o tipos estándar ({ref}`0x0109h`)?
- [ ] ¿Ningún nombre usa prefijos reservados con `_` o `__`
      ({ref}`0x010Ah`, {ref}`0x010Ch`)?
- [ ] ¿Evitaste identificadores genéricos con sufijos numéricos o afijos de tipo
      ({ref}`0x010Eh`)?
- [ ] ¿Los booleanos llevan prefijo interrogativo ({ref}`0x0110h`) y los nombres
      están en positivo, sin dobles negaciones ({ref}`0x0111h`)?
- [ ] ¿Los tipos de estructura usan `typedef` y sufijo `_t` ({ref}`0x3004h`)?
