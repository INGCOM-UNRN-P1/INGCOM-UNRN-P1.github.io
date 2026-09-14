---
title: "Refactorización de Variables y Alcance"
short_title: "Optimización de variables"
subtitle: "Optimización del alcance, inicialización y gestión de variables"
---

(refactorizacion-variables)=

## Introducción

La gestión apropiada de variables es fundamental para escribir código claro,
seguro y mantenible. Este apunte cubre técnicas de refactorización enfocadas en
mejorar el uso de variables: reducir su alcance, mejorar la inicialización,
eliminar variables temporales innecesarias, y aplicar el principio de
inmutabilidad cuando sea posible.

Un buen manejo de variables no solo hace el código más legible, sino que también
previene errores sutiles relacionados con el estado mutable y reduce la carga
cognitiva al leer el código.

:::{important} Principio de Mínimo Alcance

Como establece {ref}`0x7001h`, las variables deben inicializarse siempre con un
valor conocido. Además, el alcance de una variable debe ser el mínimo necesario
para su función, reduciendo la posibilidad de errores y facilitando el
razonamiento sobre el código.

:::
<!-- {important} Principio de Mínimo Alcance -->

## Reglas de estilo que resuelve

Esta refactorización ataca, de manera conjunta, los problemas que modelan varias
reglas de la cátedra: declaraciones lejanas a su uso, variables sin inicializar,
reutilización de un mismo nombre para propósitos distintos, bloques de
declaraciones y asignaciones desalineados, y operaciones que conviene separar.
Cada técnica de las que siguen resuelve uno o más de esos problemas; la tabla
los mapea de forma explícita para que puedas ir de la regla a la técnica.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
|-------|---------------------|----------------------------------------|
| {ref}`0x7001h` | Variables locales que se leen antes de recibir un valor conocido. | Se inicializan en el punto de declaración o se valida y retorna temprano antes de usarlas. |
| {ref}`0x6003h` | Declaraciones agrupadas al inicio, lejos de donde se usan. | Se mueve cada declaración al punto más cercano a su primer uso. |
| {ref}`0x2006h` | Variables con un alcance más amplio que el necesario. | Se limita el alcance con bloques, variables de lazo y extracción de funciones. |
| {ref}`0x6004h` | Una misma variable usada para propósitos distintos. | Se separa en variables independientes con nombres descriptivos. |
| {ref}`0x301Ch` | Variables locales declaradas con `const` y sin inicializar. | Se les asigna un valor inmediato que el compilador puede verificar. |
| {ref}`0x7005h` | Campos de estructuras o arreglos que quedan sin inicializar. | Se usa inicialización designada (`{0}` o `.campo = valor`) para cubrir todos los campos. |
| {ref}`0x3003h` | Asignación y comparación mezcladas en una sola línea. | Se parte la expresión en pasos separados y legibles. |
| {ref}`0x2011h` | Asignaciones múltiples sin lectura intermedia (dead store). | Se elimina el temporal o se escribe directamente el resultado calculado. |
| {ref}`0x0002h` | Varias declaraciones en una misma línea (`int i, j, k;`). | Se declara una variable por línea. |
| {ref}`0x0008h` | Declaraciones y asignaciones consecutivas sin alinear. | Se alinean verticalmente para que el bloque se lea de un vistazo. |

## Problemas Comunes con Variables

### 1. Alcance Innecesariamente Amplio

```{code-block} c
:linenos:
// Problemático: variables declaradas al inicio de funciones largas
void procesar_datos()
{
    int i, j, k;
    int resultado;
    double temporal;
    char buffer[256];
    // ... muchas líneas de código ...
    // i solo se usa aquí
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    // ... más código ...
    // temporal solo se usa aquí
    temporal = calcular_algo();
}
```
<!-- {code-block} c -->

### 2. Variables sin Inicializar

```{code-block} c
:linenos:
// Peligroso: variables no inicializadas
int calcular_suma(int *arr, int n)
{
    int suma; // ¡Valor indeterminado!
    if (n > 0)
    {
        suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma += arr[i];
        }
    }
    return suma; // Puede retornar basura si n <= 0
}
```
<!-- {code-block} c -->

### 3. Variables Temporales Innecesarias

```{code-block} c
:linenos:
// Verboso: temporales que no agregan claridad
int obtener_edad()
{
    int edad_temporal = 25;
    return edad_temporal;
}
double calcular_precio(double base, double descuento)
{
    double precio_con_descuento = base * (1 - descuento);
    double precio_final = precio_con_descuento;
    return precio_final;
}
```
<!-- {code-block} c -->

### 4. Reutilización Inapropiada de Variables

```{code-block} c
:linenos:
// Confuso: misma variable para propósitos diferentes
void procesar()
{
    int temp;
    temp = leer_entrada();
    validar(temp);
    // temp reutilizada para algo diferente
    temp = calcular_resultado();
    guardar(temp);
    // temp reutilizada nuevamente
    temp = contar_elementos();
    mostrar(temp);
}
```
<!-- {code-block} c -->

## Técnicas de Refactorización

### 1. Reducir Alcance de Variables

Declarar variables en el punto más cercano a su primer uso, tal como piden
{ref}`0x6003h` y {ref}`0x2006h`.

**Antes:**

```{code-block} c
:linenos:
void procesar_archivo(const char *ruta)
{
    FILE *archivo;
    char linea[256];
    int contador;
    int i;
    archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        return;
    }
    contador = 0;
    while (fgets(linea, sizeof(linea), archivo))
    {
        contador++;
    }
    printf("Líneas: %d\n", contador);
    fclose(archivo);
    // i solo se usa aquí
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void procesar_archivo(const char *ruta)
{
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        return;
    }
    int contador = 0;
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo))
    {
        contador++;
    }
    printf("Líneas: %d\n", contador);
    fclose(archivo);
    // i declarada en el lazo
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
}
```
<!-- {code-block} c -->

**Beneficios:**
- Más claro dónde se usa cada variable
- Menos espacio mental para rastrear estado
- Inicialización en el punto de declaración

### 2. Inicialización Segura

Siempre inicializar variables en el punto de declaración, como exige
{ref}`0x7001h`. Cuando el valor depende del flujo, conviene validar y retornar
temprano antes que arrastrar una variable sin inicializar.

**Antes:**

```{code-block} c
:linenos:
int procesar_datos(int *arr, int n)
{
    int suma;
    int maximo;
    int contador;
    if (n > 0)
    {
        suma = 0;
        maximo = arr[0];
        contador = 0;
        for (int i = 0; i < n; i++)
        {
            suma += arr[i];
            if (arr[i] > maximo)
            {
                maximo = arr[i];
            }
            contador++;
        }
    }
    return suma; // ¡Peligro!
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
int procesar_datos(const int *arr, int n)
{
    int suma = 0;
    int maximo = 0;
    int contador = 0;
    if (n > 0)
    {
        maximo = arr[0];
        for (int i = 0; i < n; i++)
        {
            suma += arr[i];
            if (arr[i] > maximo)
            {
                maximo = arr[i];
            }
            contador++;
        }
    }
    return suma;
}
```
<!-- {code-block} c -->

**Mejor aún (con validación temprana):**

```{code-block} c
:linenos:
int procesar_datos(const int *arr, int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int suma = 0;
    int maximo = arr[0];
    for (int i = 0; i < n; i++)
    {
        suma += arr[i];
        if (arr[i] > maximo)
        {
            maximo = arr[i];
        }
    }
    return suma;
}
```
<!-- {code-block} c -->

### 3. Eliminar Variables Temporales Innecesarias

Una temporal que solo se copia una vez suele ser un *dead store* encubierto: se
asigna y nunca se lee con un propósito propio. Eliminarla resuelve lo que modela
{ref}`0x2011h` y, de paso, mantiene la inicialización en la declaración
({ref}`0x7001h`).

**Antes:**

```{code-block} c
:linenos:
double calcular_total(double precio, double cantidad, double impuesto)
{
    double subtotal = precio * cantidad;
    double monto_impuesto = subtotal * impuesto;
    double total = subtotal + monto_impuesto;
    return total;
}
int es_par(int n)
{
    int resto = n % 2;
    int resultado = (resto == 0);
    return resultado;
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
double calcular_total(double precio, double cantidad, double impuesto)
{
    double subtotal = precio * cantidad;
    return subtotal * (1 + impuesto);
}
int es_par(int n)
{
    return n % 2 == 0;
}
```
<!-- {code-block} c -->

**Cuando las temporales SÍ agregan valor:**

```{code-block} c
:linenos:
// Temporales útiles para claridad
double calcular_factura(const item_t *items, int n, double tasa_iva)
{
    double subtotal = calcular_subtotal(items, n);
    double descuento = calcular_descuento_aplicable(subtotal);
    double subtotal_con_descuento = subtotal - descuento;
    double iva = subtotal_con_descuento * tasa_iva;
    double total = subtotal_con_descuento + iva;
    return total;
}
```
<!-- {code-block} c -->

### 4. Separar Variables con Propósitos Diferentes

No reutilizar variables para diferentes propósitos ({ref}`0x6004h`): cada
variable nueva se declara en su propia línea, una por línea ({ref}`0x0002h`), en
lugar de agruparlas al inicio.

**Antes:**

```{code-block} c
:linenos:
void procesar()
{
    int valor;
    // Primer uso: entrada
    valor = leer_entrada();
    validar(valor);
    // Segundo uso: resultado intermedio (diferente significado)
    valor = calcular_resultado(valor);
    transformar(valor);
    // Tercer uso: contador (totalmente diferente)
    valor = 0;
    for (int i = 0; i < 10; i++)
    {
        if (condicion(i))
        {
            valor++;
        }
    }
    printf("Contados: %d\n", valor);
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void procesar()
{
    int entrada = leer_entrada();
    validar(entrada);
    int resultado = calcular_resultado(entrada);
    transformar(resultado);
    int elementos_contados = 0;
    for (int i = 0; i < 10; i++)
    {
        if (condicion(i))
        {
            elementos_contados++;
        }
    }
    printf("Contados: %d\n", elementos_contados);
}
```
<!-- {code-block} c -->

**Beneficios:**
- Cada variable tiene un propósito claro
- Nombres descriptivos autodocumentan el código
- Más fácil rastrear el flujo de datos

### 5. Usar `const` para Valores Inmutables

Aplicar `const` a variables que no deben cambiar. Recordá que el detector de
{ref}`0x301Ch` exige que esas variables locales con `const` estén inicializadas:
el valor debe quedar fijo en la misma declaración.

**Antes:**

```{code-block} c
:linenos:
void procesar_pedido(pedido_t *pedido)
{
    double tasa_iva = 0.21;
    double descuento_vip = 0.15;
    int max_intentos = 3;
    // ... código que NO debería modificar estas variables
    tasa_iva = 0.10; // ¡Bug! Cambio accidental
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void procesar_pedido(pedido_t *pedido)
{
    const double TASA_IVA = 0.21;
    const double DESCUENTO_VIP = 0.15;
    const int MAX_INTENTOS = 3;
    // ... código
    // TASA_IVA = 0.10;  // Error de compilación: assignment of read-only
    // variable
}
```
<!-- {code-block} c -->

**Aplicar `const` a parámetros que no se modifican:**

```{code-block} c
:linenos:
// Antes
void procesar_datos(int *arr, int n, configuracion_t *config)
{
    // ...
}
// Después
void procesar_datos(const int *arr, int n, const configuracion_t *config)
{
    // Garantiza que no modificamos arr ni config
}
```
<!-- {code-block} c -->

### 6. Extracción a Variables con Nombre

Dar nombres significativos a expresiones complejas. Al extraer, declarás una
variable por línea ({ref}`0x0002h`) y podés alinear el bloque de asignaciones
consecutivas para facilitar el escaneo ({ref}`0x0008h`).

**Antes:**

```{code-block} c
:linenos:
if ((usuario->edad >= 18 && usuario->edad <= 65) &&
    (usuario->saldo > 1000 || usuario->credito > 500) && !usuario->bloqueado)
{
    procesar_transaccion(usuario);
}
// Cálculo complejo sin contexto
double total = precio * cantidad * (1 - (cantidad > 10 ? 0.15 : 0.05)) * 1.21;
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
bool es_edad_valida = usuario->edad >= 18 && usuario->edad <= 65;
bool tiene_fondos = usuario->saldo > 1000 || usuario->credito > 500;
bool puede_operar = es_edad_valida && tiene_fondos && !usuario->bloqueado;
if (puede_operar)
{
    procesar_transaccion(usuario);
}
// Cálculo con variables intermedias
const double TASA_IVA = 0.21;
double descuento = (cantidad > 10) ? 0.15 : 0.05;
double subtotal = precio * cantidad;
double subtotal_con_descuento = subtotal * (1 - descuento);
double total = subtotal_con_descuento * (1 + TASA_IVA);
```
<!-- {code-block} c -->

### 7. Variables de Lazo en el Alcance Mínimo

**Antes (estilo C89):**

```{code-block} c
:linenos:
void procesar()
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    // i todavía existe y tiene valor 10
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 3; i++)
        { // Reutiliza i
            printf("%d,%d\n", i, j);
        }
    }
}
```
<!-- {code-block} c -->

**Después (C99+):**

```{code-block} c
:linenos:
void procesar()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    // i ya no existe aquí
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        { // Nueva i, no confusión
            printf("%d,%d\n", i, j);
        }
    }
}
```
<!-- {code-block} c -->

## Casos Prácticos Completos

### Caso 1: Análisis de Texto

**Código Original:**

```{code-block} c
:linenos:
void analizar_texto(const char *texto)
{
    int i, j, k;
    int longitud, palabras, lineas, caracteres_especiales;
    char caracter_actual, caracter_anterior;
    int en_palabra;
    longitud = strlen(texto);
    palabras = 0;
    lineas = 1;
    caracteres_especiales = 0;
    en_palabra = 0;
    caracter_anterior = ' ';
    for (i = 0; i < longitud; i++)
    {
        caracter_actual = texto[i];
        if (caracter_actual == '\n')
        {
            lineas++;
        }
        if (!isalnum(caracter_actual) && !isspace(caracter_actual))
        {
            caracteres_especiales++;
        }
        if (isspace(caracter_actual))
        {
            en_palabra = 0;
        }
        else if (!en_palabra)
        {
            en_palabra = 1;
            palabras++;
        }
        caracter_anterior = caracter_actual;
    }
    printf("Palabras: %d\n", palabras);
    printf("Líneas: %d\n", lineas);
    printf("Caracteres especiales: %d\n", caracteres_especiales);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

La estructura `stats` se inicializa de forma designada, cubriendo todos los
campos aunque algunos arranquen en cero ({ref}`0x7005h`).

```{code-block} c
:linenos:
typedef struct
{
    int palabras;
    int lineas;
    int caracteres_especiales;
} estadisticas_texto_t;
bool es_caracter_especial(char c)
{
    return !isalnum(c) && !isspace(c);
}
estadisticas_texto_t analizar_texto(const char *texto)
{
    estadisticas_texto_t stats = {
        .palabras = 0, .lineas = 1, .caracteres_especiales = 0};
    bool en_palabra = false;
    const int longitud = strlen(texto);
    for (int i = 0; i < longitud; i++)
    {
        const char caracter_actual = texto[i];
        if (caracter_actual == '\n')
        {
            stats.lineas++;
        }
        if (es_caracter_especial(caracter_actual))
        {
            stats.caracteres_especiales++;
        }
        if (isspace(caracter_actual))
        {
            en_palabra = false;
        }
        else if (!en_palabra)
        {
            en_palabra = true;
            stats.palabras++;
        }
    }
    return stats;
}
void mostrar_estadisticas(estadisticas_texto_t stats)
{
    printf("Palabras: %d\n", stats.palabras);
    printf("Líneas: %d\n", stats.lineas);
    printf("Caracteres especiales: %d\n", stats.caracteres_especiales);
}
```
<!-- {code-block} c -->

**Mejoras aplicadas:**
- Variables declaradas cerca de su uso
- Inicialización en la declaración
- Variables de lazo con alcance reducido
- Uso de `const` para valores inmutables
- Nombres descriptivos
- Separación de lógica de cálculo y presentación

### Caso 2: Procesamiento de Transacciones

**Código Original:**

```{code-block} c
:linenos:
int procesar_transacciones(transaccion_t *trans, int n)
{
    int i, j;
    double total, subtotal, impuesto, descuento;
    int aprobadas, rechazadas, pendientes;
    int resultado;
    char estado;
    total = 0;
    aprobadas = 0;
    rechazadas = 0;
    pendientes = 0;
    for (i = 0; i < n; i++)
    {
        subtotal = trans[i].monto;
        // Calcular descuento
        if (trans[i].tipo == VIP)
        {
            descuento = 0.15;
        }
        else if (trans[i].tipo == REGULAR)
        {
            descuento = 0.05;
        }
        else
        {
            descuento = 0;
        }
        subtotal = subtotal * (1 - descuento);
        impuesto = subtotal * 0.21;
        total = subtotal + impuesto;
        trans[i].total = total;
        // Validar
        if (trans[i].cuenta_origen == NULL)
        {
            estado = 'R';
        }
        else if (trans[i].cuenta_origen->saldo < total)
        {
            estado = 'R';
        }
        else
        {
            estado = 'A';
        }
        if (estado == 'A')
        {
            aprobadas++;
        }
        else if (estado == 'R')
        {
            rechazadas++;
        }
        trans[i].estado = estado;
    }
    printf("Aprobadas: %d, Rechazadas: %d\n", aprobadas, rechazadas);
    resultado = (rechazadas == 0) ? 0 : -1;
    return resultado;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

El resumen se inicializa con `{0}` para no dejar ningún campo con basura
({ref}`0x7005h`).

```{code-block} c
:linenos:
typedef struct
{
    int aprobadas;
    int rechazadas;
} resumen_procesamiento_t;
double calcular_descuento_tipo(tipo_cliente_t tipo)
{
    switch (tipo)
    {
    case VIP:
        return 0.15;
    case REGULAR:
        return 0.05;
    default:
        return 0.0;
    }
}
double calcular_total_transaccion(double monto, tipo_cliente_t tipo)
{
    const double TASA_IVA = 0.21;
    double descuento = calcular_descuento_tipo(tipo);
    double subtotal = monto * (1 - descuento);
    double impuesto = subtotal * TASA_IVA;
    return subtotal + impuesto;
}
bool validar_transaccion(const transaccion_t *trans)
{
    if (trans->cuenta_origen == NULL)
    {
        return false;
    }
    if (trans->cuenta_origen->saldo < trans->total)
    {
        return false;
    }
    return true;
}
resumen_procesamiento_t procesar_transacciones(transaccion_t *trans, int n)
{
    resumen_procesamiento_t resumen = {0};
    for (int i = 0; i < n; i++)
    {
        trans[i].total =
            calcular_total_transaccion(trans[i].monto, trans[i].tipo);
        bool aprobada = validar_transaccion(&trans[i]);
        trans[i].estado = aprobada ? 'A' : 'R';
        if (aprobada)
        {
            resumen.aprobadas++;
        }
        else
        {
            resumen.rechazadas++;
        }
    }
    printf("Aprobadas: %d, Rechazadas: %d\n", resumen.aprobadas,
           resumen.rechazadas);
    return resumen;
}
```
<!-- {code-block} c -->

**Mejoras aplicadas:**
- Extracción de funciones para cálculos
- Variables con alcance reducido
- Uso de `const` para parámetros de solo lectura
- Nombres descriptivos
- Eliminación de variables temporales innecesarias
- Estructura para retornar múltiples valores

## Patrones Avanzados

### Patrón: Computed Variables (Variables Calculadas)

**Antes:**

```{code-block} c
:linenos:
void mostrar_info_usuario(usuario_t *u)
{
    printf("Nombre: %s %s\n", u->nombre, u->apellido);
    printf("Edad: %d\n", calcular_edad(u->fecha_nacimiento));
    printf("Categoría: %s\n", es_premium(u) ? "Premium" : "Regular");
    printf("Estado: %s\n", u->activo && !u->bloqueado ? "Activo" : "Inactivo");
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void mostrar_info_usuario(const usuario_t *u)
{
    const char *nombre_completo = formatear_nombre(u->nombre, u->apellido);
    const int edad = calcular_edad(u->fecha_nacimiento);
    const char *categoria = es_premium(u) ? "Premium" : "Regular";
    const bool operativo = u->activo && !u->bloqueado;
    const char *estado = operativo ? "Activo" : "Inactivo";
    printf("Nombre: %s\n", nombre_completo);
    printf("Edad: %d\n", edad);
    printf("Categoría: %s\n", categoria);
    printf("Estado: %s\n", estado);
}
```
<!-- {code-block} c -->

### Patrón: Replacement of Temp with Query

**Antes:**

```{code-block} c
:linenos:
double calcular_precio(item_t *item)
{
    double precio_base = item->precio * item->cantidad;
    if (precio_base > 1000)
    {
        return precio_base * 0.95;
    }
    else
    {
        return precio_base * 0.98;
    }
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
double obtener_precio_base(const item_t *item)
{
    return item->precio * item->cantidad;
}
double calcular_precio(const item_t *item)
{
    const double precio_base = obtener_precio_base(item);
    const double descuento = (precio_base > 1000) ? 0.95 : 0.98;
    return precio_base * descuento;
}
```
<!-- {code-block} c -->

## Antipatrones a Evitar

### 1. Variables Globales Innecesarias

```{code-block} c
:linenos:
// Problemático
int contador_global = 0;
void procesar_item(item_t *item)
{
    contador_global++;
    // ...
}
```
<!-- {code-block} c -->

**Mejor:**

```{code-block} c
:linenos:
typedef struct
{
    int items_procesados;
    // ... otros datos de contexto
} contexto_procesamiento_t;
void procesar_item(item_t *item, contexto_procesamiento_t *ctx)
{
    ctx->items_procesados++;
    // ...
}
```
<!-- {code-block} c -->

### 2. Variables "God" (Demasiado Propósito)

Además de violar {ref}`0x6004h`, esta variable encadena asignaciones que nunca se
leen antes de la siguiente: cada línea pisa el valor anterior, un *dead store*
que modela {ref}`0x2011h`.

```{code-block} c
:linenos:
// Problemático
int datos; // Usado para todo
datos = leer_archivo();
datos = procesar(datos);
datos = validar(datos);
datos = contar_elementos(datos);
```
<!-- {code-block} c -->

### 3. Variables con Nombres No Descriptivos

``` c
// Problemático
int d; // días? dinero? datos?
int tmp;
int x, y, z;
```
<!-- c -->

### 4. Asignación y Comparación Mezcladas

Mezclar una asignación con una comparación dentro de una misma expresión produce
errores difíciles de ver, como el clásico `if (estado = 'A')`. La regla
{ref}`0x3003h` pide no combinar ambas operaciones en una sola línea.

```{code-block} c
:linenos:
// Problemático: asigna 'A' en lugar de comparar
char estado = leer_estado();
if (estado = 'A')
{
    procesar();
}
```

**Mejor:**

```{code-block} c
:linenos:
char estado = leer_estado();
if (estado == 'A')
{
    procesar();
}
```

## Ejemplo integrador

En este ejemplo resolvemos varias reglas a la vez. El código original declara
todo al inicio ({ref}`0x0002h`, {ref}`0x6003h`), deja variables sin inicializar
({ref}`0x7001h`), mezcla asignación con comparación ({ref}`0x3003h`), reutiliza
`total` para la suma y para el promedio ({ref}`0x6004h`, {ref}`0x2011h`) y
mantiene un alcance amplio para `i` y `j` ({ref}`0x2006h`).

**❌ Antes:**

```{code-block} c
:linenos:
double promedio_activos(pedido_t *pedidos, int n)
{
    int i, j;
    double total;
    int cantidad;
    total = 0;
    cantidad = 0;
    for (i = 0; i < n; i++)
    {
        if (pedidos[i].estado = 'A')
        {
            total = total + pedidos[i].monto;
            cantidad = cantidad + 1;
        }
    }
    if (cantidad > 0)
    {
        total = total / cantidad; // total cambia de significado
    }
    return total;
}
```

**✅ Después:**

```{code-block} c
:linenos:
typedef struct
{
    double suma;
    int cantidad;
} acumulado_t;

acumulado_t acumular_activos(const pedido_t *pedidos, int n)
{
    acumulado_t acc = {.suma = 0.0, .cantidad = 0};
    for (int i = 0; i < n; i++)
    {
        const bool activo = pedidos[i].estado == 'A';
        if (activo)
        {
            acc.suma += pedidos[i].monto;
            acc.cantidad++;
        }
    }
    return acc;
}

double promedio_activos(const pedido_t *pedidos, int n)
{
    const acumulado_t acc = acumular_activos(pedidos, n);
    if (acc.cantidad == 0)
    {
        return 0.0;
    }
    return acc.suma / acc.cantidad;
}
```

Cada variable nace cerca de su uso ({ref}`0x6003h`), arranca con un valor
conocido ({ref}`0x7001h`) y la estructura se inicializa campo a campo cubriendo
todos sus miembros ({ref}`0x7005h`). El resultado de la comparación se guarda en
un `const bool` ({ref}`0x301Ch`), el acumulador tiene un único propósito
({ref}`0x6004h`) y su alcance queda acotado a cada función ({ref}`0x2006h`). Las
declaraciones consecutivas se declaran una por línea ({ref}`0x0002h`) y se
alinean ({ref}`0x0008h`).

## Diagnóstico y refactorización

Usá esta tabla como guía rápida: ubicá el síntoma en tu código y saltá a la
técnica de esta guía que lo resuelve.

| Regla | Síntoma en el código | Técnica de esta guía |
|-------|----------------------|----------------------|
| {ref}`0x7001h` | Una variable local se lee sin haber recibido nunca un valor. | Inicialización Segura |
| {ref}`0x6003h` | Las declaraciones están amontonadas al inicio y el uso queda lejos. | Reducir Alcance de Variables |
| {ref}`0x2006h` | Un índice o acumulador vive más allá del bloque que lo necesita. | Reducir Alcance de Variables / Variables de Lazo en el Alcance Mínimo |
| {ref}`0x6004h` | El mismo nombre guarda primero una entrada y luego un contador. | Separar Variables con Propósitos Diferentes |
| {ref}`0x301Ch` | Hay `const` locales sin inicializar o inicializados tarde. | Usar `const` para Valores Inmutables |
| {ref}`0x7005h` | Una estructura o arreglo se declara y solo se llenan algunos campos. | Ejemplo integrador / Casos Prácticos Completos |
| {ref}`0x3003h` | Aparece `if (x = y)` donde se quería comparar. | Antipatrón 4: Asignación y Comparación Mezcladas |
| {ref}`0x2011h` | Se asigna dos veces a la misma variable sin leer la primera. | Eliminar Variables Temporales Innecesarias |
| {ref}`0x0002h` | Una línea declara `int i, j, k;`. | Separar Variables con Propósitos Diferentes / Ejemplo integrador |
| {ref}`0x0008h` | Declaraciones o asignaciones consecutivas quedan desalineadas. | Extracción a Variables con Nombre / Ejemplo integrador |

## Resumen

Técnicas para mejorar el manejo de variables:

1. **Alcance Mínimo:** Declarar variables lo más cerca posible de su uso
2. **Inicialización Segura:** Siempre inicializar en la declaración
3. **Eliminar Temporales:** Remover variables que no agregan claridad
4. **Una Variable, Un Propósito:** No reutilizar variables
5. **Inmutabilidad:** Usar `const` siempre que sea posible
6. **Nombres Significativos:** Variables que autodocumentan
7. **Variables Calculadas:** Dar nombres a expresiones complejas

**Principios clave:**
- Minimizar alcance reduce complejidad
- La inicialización previene bugs sutiles
- `const` comunica intención y previene errores
- Nombres descriptivos son documentación
- Cada variable debe tener un propósito claro y único

El manejo apropiado de variables es fundamental para código seguro, claro y
mantenible.

## Checklist de verificación

Pasá esta lista antes de dar por cerrada una refactorización de variables:

- [ ] Toda variable local arranca con un valor conocido ({ref}`0x7001h`).
- [ ] Cada variable se declara lo más cerca posible de su primer uso ({ref}`0x6003h`).
- [ ] El alcance de cada variable es el mínimo necesario ({ref}`0x2006h`).
- [ ] Ninguna variable se reutiliza para propósitos distintos ({ref}`0x6004h`).
- [ ] Las variables `const` locales están inicializadas en su declaración ({ref}`0x301Ch`).
- [ ] Los campos de estructuras y los arreglos quedan todos inicializados ({ref}`0x7005h`).
- [ ] No queda ninguna asignación mezclada con una comparación ({ref}`0x3003h`).
- [ ] No hay asignaciones múltiples sin lectura intermedia ({ref}`0x2011h`).
- [ ] Hay una sola declaración por línea ({ref}`0x0002h`).
- [ ] Las declaraciones y asignaciones consecutivas están alineadas ({ref}`0x0008h`).
