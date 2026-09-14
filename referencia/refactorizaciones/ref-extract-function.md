---
title: "Extracción de Funciones"
short_title: "Extraer Función"
subtitle: "Descomponer código complejo en funciones cohesivas y reutilizables"
---

(refactorizacion-extract-function)=

## Introducción

La **extracción de funciones** es una de las refactorizaciones más poderosas y
fundamentales en programación. Consiste en identificar fragmentos de código que
realizan una tarea específica y encapsularlos en una función independiente con
un nombre descriptivo.

Esta técnica no solo mejora la legibilidad del código, sino que también promueve
la reutilización, facilita el testing, y ayuda a mantener funciones con un nivel
de abstracción consistente.

:::{important} Principio de Responsabilidad Única

Como establece {ref}`0x0201h`, cada función debe tener una única responsabilidad
bien definida. La extracción de funciones es la herramienta principal para
lograr este objetivo.

:::
<!-- {important} Principio de Responsabilidad Única -->

En el marco de la cátedra, esta es la técnica que permite que los ejercicios se
resuelvan descomponiéndolos en funciones y no dentro de `main` ({ref}`0x2008h`).

## Reglas de estilo que resuelve

La extracción de funciones no es una preferencia estética: es la herramienta
que corrige, de forma verificable, los problemas que modelan las reglas de
estilo de la materia. Cada fragmento extraído ataca un síntoma concreto y deja
el código alineado con la regla correspondiente. La tabla siguiente vincula cada
regla con el problema que modela y la manera en que esta refactorización lo
resuelve.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
| :--- | :--- | :--- |
| {ref}`0x2014h` | Funciones que crecen hasta no caber en una sola idea ni en 25 líneas. | Extraer cada bloque cohesivo en una función corta mantiene el cuerpo por debajo del umbral. |
| {ref}`0x2005h` | Una función que acumula validación, cálculo y presentación. | Cada nueva función recibe exactamente una responsabilidad y un nombre que la declara. |
| {ref}`0x2016h` | Implementar sin haber decidido antes precondiciones y postcondiciones. | Al definir la firma se redacta el contrato —qué recibe, qué garantiza— antes del cuerpo. |
| {ref}`0x200Ah` | Firmas con demasiados parámetros sueltos que el llamador confunde. | Los datos que viajan juntos se empaquetan en un `struct` y se pasan mediante un único puntero. |
| {ref}`0x1015h` | Anidación de cuatro o más niveles que sepulta el camino feliz. | Cada nivel profundo se convierte en una función invocada desde el nivel superior. |
| {ref}`0x2001h` | Validaciones enterradas dentro del flujo principal. | Las validaciones extraídas se invocan como cláusulas de guarda al inicio. |
| {ref}`0x2003h` | Funciones sin propósito, precondición ni postcondición documentados. | Cada función extraída se documenta con su bloque estructurado (`@brief`, `@param`, `@pre`, `@post`, `@returns`). |
| {ref}`0x2008h` | Lógica escrita en un único bloque monolítico dentro de `main`. | El ejercicio se descompone en funciones y `main` queda como orquestador. |
| {ref}`0x0017h` | Muros de sentencias donde no se distinguen las etapas. | Los párrafos lógicos que sobreviven a la extracción quedan separados por líneas en blanco. |
| {ref}`0x7007h` | Parámetros bandera `bool` que eligen entre dos comportamientos. | Los dos comportamientos se separan en dos funciones con nombres explícitos. |

## ¿Cuándo Extraer una Función?

### Señales de que Necesitás Extraer

1. **Código duplicado:** El mismo fragmento aparece en múltiples lugares
2. **Función larga:** Más de 30-50 líneas (depende del contexto) ({ref}`0x2014h`)
3. **Niveles de abstracción mezclados:** Lógica de alto nivel con detalles de
   implementación
4. **Comentario explicativo:** Si necesitás un comentario para explicar un
   bloque, ese bloque debería ser una función
5. **Dificultad para nombrar:** Si no podés describir qué hace la función en una
   frase corta
6. **Anidamiento profundo:** Más de 2-3 niveles de indentación ({ref}`0x1015h`)

### Ejemplo: Comentario que Señala Necesidad de Extracción

```{code-block} c
:linenos:
void procesar_pedido(pedido_t *pedido)
{
    // Validar datos del cliente
    if (pedido->cliente.nombre == NULL || strlen(pedido->cliente.nombre) == 0)
    {
        return;
    }
    if (pedido->cliente.email == NULL || !strchr(pedido->cliente.email, '@'))
    {
        return;
    }
    // Calcular total con impuestos
    double subtotal = 0;
    for (int i = 0; i < pedido->num_items; i++)
    {
        subtotal += pedido->items[i].precio * pedido->items[i].cantidad;
    }
    double impuestos = subtotal * 0.21;
    double total = subtotal + impuestos;
    // Guardar en base de datos
    // ...
}
```
<!-- {code-block} c -->

Los comentarios son indicadores claros: cada bloque debería ser una función.

## Proceso de Extracción

### Paso 1: Identificar el Fragmento

Seleccionar el bloque de código que realiza una tarea cohesiva.

### Paso 2: Analizar Dependencias

Identificar:

- **Variables locales usadas:** Se convertirán en parámetros
- **Variables modificadas:** Se retornarán o pasarán por referencia
- **Variables declaradas internamente:** Permanecen en la nueva función

### Paso 3: Elegir Nombre Descriptivo

El nombre debe describir **qué** hace, no **cómo** lo hace:

- `validar_cliente()` ✓
- `verificar_nombre_y_email()` ✗ (demasiado específico)
- `proceso1()` ✗ (no descriptivo)

### Paso 4: Determinar Firma

Decidir parámetros y tipo de retorno basándose en el análisis de dependencias.
Es el momento de escribir el contrato de la función —qué recibe, qué garantiza,
qué devuelve y qué casos no admite— antes de tocar su cuerpo ({ref}`0x2016h`).

### Paso 5: Extraer y Reemplazar

Crear la nueva función y reemplazar el código original con una llamada.

### Paso 6: Probar

Verificar que el comportamiento no cambió.

## Casos Prácticos

### Caso 1: Extracción Básica - Validación

**Código Original:**

```{code-block} c
:linenos:
int procesar_usuario(const char *nombre, const char *email, int edad)
{
    // Validación embebida en la función principal
    if (nombre == NULL || strlen(nombre) < 3)
    {
        printf("Nombre inválido\n");
        return -1;
    }
    if (email == NULL || !strchr(email, '@'))
    {
        printf("Email inválido\n");
        return -1;
    }
    if (edad < 18 || edad > 120)
    {
        printf("Edad inválida\n");
        return -1;
    }
    // Lógica principal
    printf("Usuario %s registrado\n", nombre);
    return 0;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
bool validar_nombre(const char *nombre)
{
    if (nombre == NULL || strlen(nombre) < 3)
    {
        printf("Nombre inválido\n");
        return false;
    }
    return true;
}
bool validar_email(const char *email)
{
    if (email == NULL || !strchr(email, '@'))
    {
        printf("Email inválido\n");
        return false;
    }
    return true;
}
bool validar_edad(int edad)
{
    if (edad < 18 || edad > 120)
    {
        printf("Edad inválida\n");
        return false;
    }
    return true;
}
int procesar_usuario(const char *nombre, const char *email, int edad)
{
    if (!validar_nombre(nombre))
        return -1;
    if (!validar_email(email))
        return -1;
    if (!validar_edad(edad))
        return -1;
    // Lógica principal ahora es clara
    printf("Usuario %s registrado\n", nombre);
    return 0;
}
```
<!-- {code-block} c -->

**Beneficios:**

- Funciones reutilizables
- Testing independiente de cada validación
- `procesar_usuario` ahora es más legible
- Cada función tiene una única responsabilidad ({ref}`0x2005h`)

### Caso 2: Extracción con Múltiples Valores de Retorno

**Código Original:**

```{code-block} c
:linenos:
void analizar_ventas(double ventas[], int n)
{
    // Calcular estadísticas
    double total = 0;
    double maximo = ventas[0];
    double minimo = ventas[0];
    for (int i = 0; i < n; i++)
    {
        total += ventas[i];
        if (ventas[i] > maximo)
            maximo = ventas[i];
        if (ventas[i] < minimo)
            minimo = ventas[i];
    }
    double promedio = total / n;
    printf("Total: %.2f\n", total);
    printf("Promedio: %.2f\n", promedio);
    printf("Máximo: %.2f\n", maximo);
    printf("Mínimo: %.2f\n", minimo);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
typedef struct
{
    double total;
    double promedio;
    double maximo;
    double minimo;
} estadisticas_t;
estadisticas_t calcular_estadisticas(const double ventas[], int n)
{
    estadisticas_t stats = {0};
    if (n == 0)
        return stats;
    stats.maximo = ventas[0];
    stats.minimo = ventas[0];
    for (int i = 0; i < n; i++)
    {
        stats.total += ventas[i];
        if (ventas[i] > stats.maximo)
            stats.maximo = ventas[i];
        if (ventas[i] < stats.minimo)
            stats.minimo = ventas[i];
    }
    stats.promedio = stats.total / n;
    return stats;
}
void mostrar_estadisticas(estadisticas_t stats)
{
    printf("Total: %.2f\n", stats.total);
    printf("Promedio: %.2f\n", stats.promedio);
    printf("Máximo: %.2f\n", stats.maximo);
    printf("Mínimo: %.2f\n", stats.minimo);
}
void analizar_ventas(const double ventas[], int n)
{
    estadisticas_t stats = calcular_estadisticas(ventas, n);
    mostrar_estadisticas(stats);
}
```
<!-- {code-block} c -->

**Beneficios:**

- Separación de cálculo y presentación
- Función de cálculo es testeable y reutilizable
- Diferentes formatos de salida sin cambiar lógica

### Caso 3: Extracción de Lazo Complejo

**Código Original:**

```{code-block} c
:linenos:
void procesar_archivo(const char *ruta)
{
    FILE *f = fopen(ruta, "r");
    char linea[256];
    int lineas_procesadas = 0;
    int lineas_con_error = 0;
    while (fgets(linea, sizeof(linea), f))
    {
        // Limpiar salto de línea
        linea[strcspn(linea, "\n")] = '\0';
        // Saltar líneas vacías
        if (strlen(linea) == 0)
            continue;
        // Saltar comentarios
        if (linea[0] == '#')
            continue;
        // Parsear línea
        char *separador = strchr(linea, '=');
        if (separador == NULL)
        {
            lineas_con_error++;
            continue;
        }
        *separador = '\0';
        char *clave = linea;
        char *valor = separador + 1;
        // Trim whitespace
        while (*clave == ' ')
            clave++;
        while (*valor == ' ')
            valor++;
        // Procesar par clave-valor
        printf("%s -> %s\n", clave, valor);
        lineas_procesadas++;
    }
    fclose(f);
    printf("Procesadas: %d, Errores: %d\n", lineas_procesadas,
           lineas_con_error);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
bool es_linea_valida(const char *linea)
{
    return strlen(linea) > 0 && linea[0] != '#';
}
bool parsear_par_clave_valor(char *linea, char **clave, char **valor)
{
    char *separador = strchr(linea, '=');
    if (separador == NULL)
    {
        return false;
    }
    *separador = '\0';
    *clave = linea;
    *valor = separador + 1;
    // Trim whitespace
    while (**clave == ' ')
        (*clave)++;
    while (**valor == ' ')
        (*valor)++;
    return true;
}
void procesar_linea_config(char *linea, int *procesadas, int *errores)
{
    // Limpiar salto de línea
    linea[strcspn(linea, "\n")] = '\0';
    if (!es_linea_valida(linea))
    {
        return;
    }
    char *clave;
    char *valor;
    if (!parsear_par_clave_valor(linea, &clave, &valor))
    {
        (*errores)++;
        return;
    }
    printf("%s -> %s\n", clave, valor);
    (*procesadas)++;
}
void procesar_archivo(const char *ruta)
{
    FILE *f = fopen(ruta, "r");
    if (f == NULL)
    {
        printf("Error abriendo archivo\n");
        return;
    }
    char linea[256];
    int lineas_procesadas = 0;
    int lineas_con_error = 0;
    while (fgets(linea, sizeof(linea), f))
    {
        procesar_linea_config(linea, &lineas_procesadas, &lineas_con_error);
    }
    fclose(f);
    printf("Procesadas: %d, Errores: %d\n", lineas_procesadas,
           lineas_con_error);
}
```
<!-- {code-block} c -->

**Beneficios:**

- Cada función tiene una responsabilidad clara
- Fácil agregar nuevas validaciones
- Testing unitario de parseo sin I/O
- El error de `fopen` se resuelve con una cláusula de guarda y retorno
  anticipado ({ref}`0x2001h`)
- Lazo principal ahora es simple y legible

### Caso 4: Extracción de Cálculo Complejo

**Código Original:**

```{code-block} c
:linenos:
double calcular_precio_final(double precio_base, int cantidad,
                             bool es_mayorista, const char *codigo_postal)
{
    // Descuento por cantidad
    double descuento_cantidad = 0;
    if (cantidad >= 100)
    {
        descuento_cantidad = 0.20;
    }
    else if (cantidad >= 50)
    {
        descuento_cantidad = 0.15;
    }
    else if (cantidad >= 10)
    {
        descuento_cantidad = 0.10;
    }
    // Descuento mayorista
    double descuento_mayorista = es_mayorista ? 0.05 : 0;
    // Descuento total (no acumulativo lineal)
    double descuento_total = descuento_cantidad + descuento_mayorista;
    if (descuento_total > 0.25)
        descuento_total = 0.25;
    double subtotal = precio_base * cantidad * (1 - descuento_total);
    // Impuesto según región
    double impuesto = 0.21; // IVA estándar
    if (codigo_postal[0] == '9')
    { // Patagonia
        impuesto = 0.10;
    }
    // Cargo por envío
    double envio = 0;
    if (cantidad < 5)
    {
        envio = 500;
    }
    else if (cantidad < 20)
    {
        envio = 300;
    }
    return subtotal * (1 + impuesto) + envio;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
double calcular_descuento_por_cantidad(int cantidad)
{
    if (cantidad >= 100)
        return 0.20;
    if (cantidad >= 50)
        return 0.15;
    if (cantidad >= 10)
        return 0.10;
    return 0.0;
}
double calcular_descuento_mayorista(bool es_mayorista)
{
    return es_mayorista ? 0.05 : 0.0;
}
double calcular_descuento_total(int cantidad, bool es_mayorista)
{
    const double DESCUENTO_MAXIMO = 0.25;
    double descuento = calcular_descuento_por_cantidad(cantidad) +
                       calcular_descuento_mayorista(es_mayorista);
    return (descuento > DESCUENTO_MAXIMO) ? DESCUENTO_MAXIMO : descuento;
}
double calcular_impuesto_regional(const char *codigo_postal)
{
    const double IVA_ESTANDAR = 0.21;
    const double IVA_PATAGONIA = 0.10;
    // Patagonia tiene código postal que empieza con 9
    if (codigo_postal[0] == '9')
    {
        return IVA_PATAGONIA;
    }
    return IVA_ESTANDAR;
}
double calcular_cargo_envio(int cantidad)
{
    if (cantidad < 5)
        return 500.0;
    if (cantidad < 20)
        return 300.0;
    return 0.0;
}
double calcular_precio_final(double precio_base, int cantidad,
                             bool es_mayorista, const char *codigo_postal)
{
    double descuento = calcular_descuento_total(cantidad, es_mayorista);
    double subtotal = precio_base * cantidad * (1 - descuento);
    double impuesto = calcular_impuesto_regional(codigo_postal);
    double total_con_impuesto = subtotal * (1 + impuesto);
    double envio = calcular_cargo_envio(cantidad);
    return total_con_impuesto + envio;
}
```
<!-- {code-block} c -->

**Beneficios:**

- Cada regla de negocio está aislada
- Fácil modificar política de descuentos
- Testing unitario de cada componente
- Función principal muestra el flujo claramente

### Caso 5: Ejemplo Integrador — Varias Reglas a la Vez

Este caso reúne los síntomas anteriores en una sola función. El código ❌
acumula cuatro niveles de anidación, una bandera `bool`, cálculo y presentación
mezclados y ningún contrato documentado. La versión ✅ reparte la lógica en
funciones pequeñas con responsabilidad única y contrato explícito.

**Código Original (❌):**

```{code-block} c
:linenos:
typedef enum
{
    ESTADO_PENDIENTE,
    ESTADO_ENVIADO
} estado_t;

typedef struct
{
    const char *cliente;
    double precio;
    int cantidad;
    estado_t estado;
} item_t;

double procesar_pedido(item_t items[], int n, bool aplicar_iva)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].cantidad > 0)
        {
            if (items[i].precio > 0)
            {
                if (items[i].estado == ESTADO_PENDIENTE)
                {
                    if (items[i].cantidad >= 10)
                    {
                        total += items[i].precio * items[i].cantidad * 0.80;
                    }
                    else
                    {
                        total += items[i].precio * items[i].cantidad;
                    }
                }
            }
        }
    }
    if (aplicar_iva)
    {
        total *= 1.21;
    }
    printf("Total: %.2f\n", total);
    return total;
}
```
<!-- {code-block} c -->

**Código Refactorizado (✅):**

```{code-block} c
:linenos:
/** @brief Indica si un ítem participa del total.
 *  @param item Ítem a evaluar.
 *  @pre item no es NULL.
 *  @post Devuelve true solo si cantidad y precio son positivos y el estado
 *        es pendiente.
 *  @returns true si el ítem es facturable.
 */
static bool item_facturable(const item_t *item)
{
    return item != NULL && item->cantidad > 0 && item->precio > 0 &&
           item->estado == ESTADO_PENDIENTE;
}

/** @brief Aplica el descuento por volumen.
 *  @param subtotal Importe bruto del ítem.
 *  @param cantidad Unidades vendidas.
 *  @pre subtotal es mayor o igual que cero.
 *  @post Devuelve el importe con el descuento por volumen.
 *  @returns Importe neto del ítem.
 */
static double descontar_por_volumen(double subtotal, int cantidad)
{
    if (cantidad >= 10)
    {
        return subtotal * 0.80;
    }

    return subtotal;
}

/** @brief Suma los ítems facturables sin impuestos.
 *  @param items Arreglo de ítems.
 *  @param n Cantidad de ítems.
 *  @pre items tiene al menos n elementos.
 *  @post Devuelve la suma neta de los ítems facturables.
 *  @returns Total sin impuestos.
 */
static double total_sin_impuestos(const item_t *items, int n)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (!item_facturable(&items[i]))
        {
            continue;
        }

        double subtotal = items[i].precio * items[i].cantidad;
        total += descontar_por_volumen(subtotal, items[i].cantidad);
    }

    return total;
}

/** @brief Agrega el IVA a un total neto.
 *  @param neto Total sin impuestos.
 *  @pre neto es mayor o igual que cero.
 *  @post Devuelve neto multiplicado por 1.21.
 *  @returns Total con IVA.
 */
static double con_iva(double neto)
{
    return neto * 1.21;
}

int main(void)
{
    item_t items[] = {
        {"Ana", 1000.0, 12, ESTADO_PENDIENTE},
        {"Beto", 500.0, 3, ESTADO_ENVIADO},
    };
    int n = (int)(sizeof(items) / sizeof(items[0]));

    double total = con_iva(total_sin_impuestos(items, n));
    printf("Total: %.2f\n", total);

    return 0;
}
```
<!-- {code-block} c -->

**Reglas que resuelve este ejemplo:**

- Cada función responde a una sola idea y entra en pocas líneas
  ({ref}`0x2014h`, {ref}`0x2005h`).
- `item_facturable` valida la precondición y el lazo descarta con `continue` en
  lugar de anidar cuatro `if` ({ref}`0x1015h`, {ref}`0x2001h`).
- La bandera `bool aplicar_iva` se reemplaza por `con_iva()`, que declara su
  comportamiento en el nombre ({ref}`0x7007h`).
- El contrato de cada función se escribe con `@brief`, `@param`, `@pre`, `@post`
  y `@returns` antes del cuerpo ({ref}`0x2003h`, {ref}`0x2016h`).
- Las etapas de cálculo y de presentación se separan con líneas en blanco
  ({ref}`0x0017h`).
- `main` queda como orquestador que encadena funciones ({ref}`0x2008h`).

## Técnicas Avanzadas

### Composición de Funciones

Construir funciones complejas componiendo funciones simples:

```{code-block} c
:linenos:
// Funciones atómicas
bool es_letra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool es_digito(char c)
{
    return c >= '0' && c <= '9';
}
bool es_espacio(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}
// Función compuesta
bool es_alfanumerico(char c)
{
    return es_letra(c) || es_digito(c);
}
bool es_identificador_valido(const char *str)
{
    if (str == NULL || strlen(str) == 0)
        return false;
    if (!es_letra(str[0]) && str[0] != '_')
        return false;
    for (size_t i = 1; str[i] != '\0'; i++)
    {
        if (!es_alfanumerico(str[i]) && str[i] != '_')
        {
            return false;
        }
    }
    return true;
}
```
<!-- {code-block} c -->

### Extracción con Parámetros de Configuración

```{code-block} c
:linenos:
typedef struct
{
    double descuento_mayorista;
    double impuesto_estandar;
    double impuesto_reducido;
    double cargo_envio_pequeno;
    double cargo_envio_mediano;
} configuracion_precios_t;
double calcular_precio_con_config(double precio_base, int cantidad,
                                  bool es_mayorista,
                                  const configuracion_precios_t *config)
{
    // Uso de configuración inyectada
    double descuento = es_mayorista ? config->descuento_mayorista : 0.0;
    double subtotal = precio_base * cantidad * (1 - descuento);
    // ... resto del cálculo usando config
    return subtotal;
}
```
<!-- {code-block} c -->

Conviene vigilar el `bool es_mayorista`: si el valor de la bandera cambia por
completo el comportamiento, la regla de parámetros bandera pide separar cada
caso en una función con nombre propio ({ref}`0x7007h`).

### Extracción con Callbacks

Para lógica parametrizable:

```{code-block} c
:linenos:
typedef bool (*criterio_filtro_t)(int valor);
bool es_par(int valor)
{
    return valor % 2 == 0;
}
bool es_positivo(int valor)
{
    return valor > 0;
}
int contar_elementos_que_cumplen(const int *arr, int n,
                                 criterio_filtro_t criterio)
{
    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (criterio(arr[i]))
        {
            contador++;
        }
    }
    return contador;
}
// Uso
int pares = contar_elementos_que_cumplen(arr, n, es_par);
int positivos = contar_elementos_que_cumplen(arr, n, es_positivo);
```
<!-- {code-block} c -->

## Antipatrones a Evitar

### 1. Sobre-Extracción

```{code-block} c
:linenos:
// Excesivo - funciones triviales que no agregan valor
int incrementar(int x)
{
    return x + 1;
}
int decrementar(int x)
{
    return x - 1;
}
// Uso innecesariamente verboso
for (int i = 0; i < n; i = incrementar(i))
{
    // ...
}
```
<!-- {code-block} c -->

### 2. Funciones con Demasiados Parámetros

```{code-block} c
:linenos:
// Problemático
void procesar(int a, int b, int c, int d, int e, int f, int g)
{
    // Difícil de usar y mantener
}
// Mejor: usar estructura
typedef struct
{
    int param_a;
    int param_b;
    int param_c;
    // ...
} parametros_procesamiento_t;
void procesar(const parametros_procesamiento_t *params)
{
    // Más claro
}
```
<!-- {code-block} c -->

El empaquetado en un `struct` es justamente lo que exige la regla de
modularización: una función no debe superar los cuatro parámetros de entrada
({ref}`0x200Ah`).

### 3. Funciones con Efectos Secundarios Ocultos

```{code-block} c
:linenos:
// Problemático
int calcular_total(int *contador_global)
{
    (*contador_global)++; // Efecto secundario oculto
    return *contador_global * 100;
}
// Mejor: efecto secundario explícito o función pura
int calcular_total_puro(int contador)
{
    return contador * 100;
}
```
<!-- {code-block} c -->

## Guía de Decisión

### ¿Debería Extraer Esta Función?

**SÍ, si:**

- Se repite en múltiples lugares
- Tiene más de 20-30 líneas
- Mezcla niveles de abstracción
- Requiere comentario explicativo
- Es difícil de testear en su contexto actual
- Tiene anidamiento profundo (>3 niveles)

**NO, si:**

- Es trivial (1-2 líneas obvias)
- Solo se usa una vez y está clara en contexto
- La extracción oscurece en lugar de clarificar
- Requeriría demasiados parámetros (>5-6)

### Niveles de Abstracción

Una función bien diseñada mantiene un nivel de abstracción consistente:

```{code-block} c
:linenos:
// Mal: mezcla niveles de abstracción
void procesar_pedido(pedido_t *pedido)
{
    // Alto nivel
    if (!validar_pedido(pedido))
        return;
    // Bajo nivel - no pertenece aquí
    for (int i = 0; i < pedido->num_items; i++)
    {
        if (pedido->items[i].precio < 0)
        {
            return;
        }
    }
    // Alto nivel
    guardar_pedido(pedido);
}
// Bien: nivel consistente
void procesar_pedido(pedido_t *pedido)
{
    if (!validar_pedido(pedido))
        return;
    if (!validar_items(pedido))
        return;
    guardar_pedido(pedido);
}
```
<!-- {code-block} c -->

Además del nivel de abstracción, la extracción deja naturalmente párrafos
separados por líneas en blanco: las sentencias que colaboran en una misma etapa
quedan agrupadas y los bloques lógicos, separados ({ref}`0x0017h`).

## Diagnóstico y refactorización

Usá esta tabla para reconocer el síntoma en el código propio y elegir la
técnica de extracción que corresponde.

| Regla | Síntoma en el código | Técnica de esta guía |
| :--- | :--- | :--- |
| {ref}`0x2014h` | Cuerpo que supera las 25 líneas y mezcla etapas. | Extraer cada etapa en una función corta de una sola idea. |
| {ref}`0x2005h` | La función "hace y además": leer, validar y calcular. | Aislar cada responsabilidad en su propia función. |
| {ref}`0x2016h` | Decisiones de borde tomadas a mitad de la implementación. | Redactar el contrato al definir la firma. |
| {ref}`0x200Ah` | Firma con cinco o más parámetros sueltos. | Empaquetar los datos que viajan juntos en un `struct` y pasar un puntero. |
| {ref}`0x1015h` | Cuarto nivel de `if`/`for` anidado. | Extraer el bloque interno a una función. |
| {ref}`0x2001h` | Validaciones enterradas en ramas profundas. | Mover las precondiciones a guardas al inicio. |
| {ref}`0x2003h` | Función sin propósito, precondición ni postcondición escritas. | Documentar con `@brief`, `@param`, `@pre`, `@post` y `@returns`. |
| {ref}`0x2008h` | Toda la solución dentro de `main`. | Descomponer en funciones y dejar `main` como orquestador. |
| {ref}`0x0017h` | Muro de sentencias sin etapas visibles. | Agrupar por etapa y separar con una línea en blanco. |
| {ref}`0x7007h` | Llamada `imprimir(lista, true)` sin saber qué hace el `true`. | Separar en dos funciones con nombres explícitos. |

## Resumen

La extracción de funciones es fundamental para:

1. **Legibilidad:** Nombres descriptivos documentan el código
2. **Reutilización:** DRY (Don't Repeat Yourself)
3. **Testing:** Funciones pequeñas son más fáciles de testear
4. **Mantenibilidad:** Cambios localizados y predecibles
5. **Abstracción:** Ocultar complejidad de implementación

**Proceso:**

1. Identificar fragmento cohesivo
2. Analizar dependencias
3. Elegir nombre descriptivo
4. Determinar firma
5. Extraer y reemplazar
6. Probar

**Principios:**

- Una responsabilidad por función
- Nivel de abstracción consistente
- Nombres que describen QUÉ, no CÓMO
- Minimizar efectos secundarios
- Preferir funciones puras cuando sea posible

La extracción de funciones es una habilidad que se desarrolla con práctica. Al
principio puede parecer tedioso, pero con el tiempo se vuelve una segunda
naturaleza que mejora dramáticamente la calidad del código.

## Checklist de verificación

- [ ] ¿Cada función cabe en una sola idea y en 25 líneas? ({ref}`0x2014h`)
- [ ] ¿Puedo describir cada función con una frase sin "y"? ({ref}`0x2005h`)
- [ ] ¿Escribí el contrato de cada función antes de implementarla? ({ref}`0x2016h`)
- [ ] ¿Ninguna función supera los cuatro parámetros de entrada? ({ref}`0x200Ah`)
- [ ] ¿La anidación se mantiene en tres niveles o menos? ({ref}`0x1015h`)
- [ ] ¿Las precondiciones se validan con guardas y retornos anticipados al inicio? ({ref}`0x2001h`)
- [ ] ¿Cada función tiene su bloque de documentación estructurada? ({ref}`0x2003h`)
- [ ] ¿Separé las etapas con líneas en blanco, eliminé los parámetros bandera `bool` y dejé `main` como orquestador? ({ref}`0x0017h`, {ref}`0x7007h`, {ref}`0x2008h`)
