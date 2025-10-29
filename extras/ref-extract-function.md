---
title: "Extracción de Funciones"
short_title: "Extraer Función"
subtitle: "Descomponer código complejo en funciones cohesivas y reutilizables"
---

## Introducción

La **extracción de funciones** es una de las refactorizaciones más poderosas y fundamentales en programación. Consiste en identificar fragmentos de código que realizan una tarea específica y encapsularlos en una función independiente con un nombre descriptivo.

Esta técnica no solo mejora la legibilidad del código, sino que también promueve la reutilización, facilita el testing, y ayuda a mantener funciones con un nivel de abstracción consistente.

:::{important} Principio de Responsabilidad Única
Como establece {ref}`0x000Ah`, cada función debe tener una única responsabilidad bien definida. La extracción de funciones es la herramienta principal para lograr este objetivo.
:::

## ¿Cuándo Extraer una Función?

### Señales de que Necesitás Extraer

1. **Código duplicado:** El mismo fragmento aparece en múltiples lugares
2. **Función larga:** Más de 30-50 líneas (depende del contexto)
3. **Niveles de abstracción mezclados:** Lógica de alto nivel con detalles de implementación
4. **Comentario explicativo:** Si necesitás un comentario para explicar un bloque, ese bloque debería ser una función
5. **Dificultad para nombrar:** Si no podés describir qué hace la función en una frase corta
6. **Anidamiento profundo:** Más de 2-3 niveles de indentación

### Ejemplo: Comentario que Señala Necesidad de Extracción

```c
void procesar_pedido(pedido_t* pedido) {
    // Validar datos del cliente
    if (pedido->cliente.nombre == NULL || 
        strlen(pedido->cliente.nombre) == 0) {
        return;
    }
    if (pedido->cliente.email == NULL ||
        !strchr(pedido->cliente.email, '@')) {
        return;
    }
    
    // Calcular total con impuestos
    double subtotal = 0;
    for (int i = 0; i < pedido->num_items; i++) {
        subtotal += pedido->items[i].precio * pedido->items[i].cantidad;
    }
    double impuestos = subtotal * 0.21;
    double total = subtotal + impuestos;
    
    // Guardar en base de datos
    // ...
}
```

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

### Paso 5: Extraer y Reemplazar

Crear la nueva función y reemplazar el código original con una llamada.

### Paso 6: Probar

Verificar que el comportamiento no cambió.

## Casos Prácticos

### Caso 1: Extracción Básica - Validación

**Código Original:**

```c
int procesar_usuario(const char* nombre, const char* email, int edad) {
    // Validación embebida en la función principal
    if (nombre == NULL || strlen(nombre) < 3) {
        printf("Nombre inválido\n");
        return -1;
    }
    
    if (email == NULL || !strchr(email, '@')) {
        printf("Email inválido\n");
        return -1;
    }
    
    if (edad < 18 || edad > 120) {
        printf("Edad inválida\n");
        return -1;
    }
    
    // Lógica principal
    printf("Usuario %s registrado\n", nombre);
    return 0;
}
```

**Código Refactorizado:**

```c
bool validar_nombre(const char* nombre) {
    if (nombre == NULL || strlen(nombre) < 3) {
        printf("Nombre inválido\n");
        return false;
    }
    return true;
}

bool validar_email(const char* email) {
    if (email == NULL || !strchr(email, '@')) {
        printf("Email inválido\n");
        return false;
    }
    return true;
}

bool validar_edad(int edad) {
    if (edad < 18 || edad > 120) {
        printf("Edad inválida\n");
        return false;
    }
    return true;
}

int procesar_usuario(const char* nombre, const char* email, int edad) {
    if (!validar_nombre(nombre)) return -1;
    if (!validar_email(email)) return -1;
    if (!validar_edad(edad)) return -1;
    
    // Lógica principal ahora es clara
    printf("Usuario %s registrado\n", nombre);
    return 0;
}
```

**Beneficios:**
- Funciones reutilizables
- Testing independiente de cada validación
- `procesar_usuario` ahora es más legible
- Cada función tiene una única responsabilidad

### Caso 2: Extracción con Múltiples Valores de Retorno

**Código Original:**

```c
void analizar_ventas(double ventas[], int n) {
    // Calcular estadísticas
    double total = 0;
    double maximo = ventas[0];
    double minimo = ventas[0];
    
    for (int i = 0; i < n; i++) {
        total += ventas[i];
        if (ventas[i] > maximo) maximo = ventas[i];
        if (ventas[i] < minimo) minimo = ventas[i];
    }
    
    double promedio = total / n;
    
    printf("Total: %.2f\n", total);
    printf("Promedio: %.2f\n", promedio);
    printf("Máximo: %.2f\n", maximo);
    printf("Mínimo: %.2f\n", minimo);
}
```

**Código Refactorizado:**

```c
typedef struct {
    double total;
    double promedio;
    double maximo;
    double minimo;
} estadisticas_t;

estadisticas_t calcular_estadisticas(const double ventas[], int n) {
    estadisticas_t stats = {0};
    
    if (n == 0) return stats;
    
    stats.maximo = ventas[0];
    stats.minimo = ventas[0];
    
    for (int i = 0; i < n; i++) {
        stats.total += ventas[i];
        if (ventas[i] > stats.maximo) stats.maximo = ventas[i];
        if (ventas[i] < stats.minimo) stats.minimo = ventas[i];
    }
    
    stats.promedio = stats.total / n;
    return stats;
}

void mostrar_estadisticas(estadisticas_t stats) {
    printf("Total: %.2f\n", stats.total);
    printf("Promedio: %.2f\n", stats.promedio);
    printf("Máximo: %.2f\n", stats.maximo);
    printf("Mínimo: %.2f\n", stats.minimo);
}

void analizar_ventas(const double ventas[], int n) {
    estadisticas_t stats = calcular_estadisticas(ventas, n);
    mostrar_estadisticas(stats);
}
```

**Beneficios:**
- Separación de cálculo y presentación
- Función de cálculo es testeable y reutilizable
- Diferentes formatos de salida sin cambiar lógica

### Caso 3: Extracción de Lazo Complejo

**Código Original:**

```c
void procesar_archivo(const char* ruta) {
    FILE* f = fopen(ruta, "r");
    char linea[256];
    int lineas_procesadas = 0;
    int lineas_con_error = 0;
    
    while (fgets(linea, sizeof(linea), f)) {
        // Limpiar salto de línea
        linea[strcspn(linea, "\n")] = '\0';
        
        // Saltar líneas vacías
        if (strlen(linea) == 0) continue;
        
        // Saltar comentarios
        if (linea[0] == '#') continue;
        
        // Parsear línea
        char* separador = strchr(linea, '=');
        if (separador == NULL) {
            lineas_con_error++;
            continue;
        }
        
        *separador = '\0';
        char* clave = linea;
        char* valor = separador + 1;
        
        // Trim whitespace
        while (*clave == ' ') clave++;
        while (*valor == ' ') valor++;
        
        // Procesar par clave-valor
        printf("%s -> %s\n", clave, valor);
        lineas_procesadas++;
    }
    
    fclose(f);
    printf("Procesadas: %d, Errores: %d\n", 
           lineas_procesadas, lineas_con_error);
}
```

**Código Refactorizado:**

```c
bool es_linea_valida(const char* linea) {
    return strlen(linea) > 0 && linea[0] != '#';
}

bool parsear_par_clave_valor(char* linea, char** clave, char** valor) {
    char* separador = strchr(linea, '=');
    if (separador == NULL) {
        return false;
    }
    
    *separador = '\0';
    *clave = linea;
    *valor = separador + 1;
    
    // Trim whitespace
    while (**clave == ' ') (*clave)++;
    while (**valor == ' ') (*valor)++;
    
    return true;
}

void procesar_linea_config(char* linea, int* procesadas, int* errores) {
    // Limpiar salto de línea
    linea[strcspn(linea, "\n")] = '\0';
    
    if (!es_linea_valida(linea)) {
        return;
    }
    
    char* clave;
    char* valor;
    
    if (!parsear_par_clave_valor(linea, &clave, &valor)) {
        (*errores)++;
        return;
    }
    
    printf("%s -> %s\n", clave, valor);
    (*procesadas)++;
}

void procesar_archivo(const char* ruta) {
    FILE* f = fopen(ruta, "r");
    if (f == NULL) {
        printf("Error abriendo archivo\n");
        return;
    }
    
    char linea[256];
    int lineas_procesadas = 0;
    int lineas_con_error = 0;
    
    while (fgets(linea, sizeof(linea), f)) {
        procesar_linea_config(linea, &lineas_procesadas, &lineas_con_error);
    }
    
    fclose(f);
    printf("Procesadas: %d, Errores: %d\n", 
           lineas_procesadas, lineas_con_error);
}
```

**Beneficios:**
- Cada función tiene una responsabilidad clara
- Fácil agregar nuevas validaciones
- Testing unitario de parseo sin I/O
- Lazo principal ahora es simple y legible

### Caso 4: Extracción de Cálculo Complejo

**Código Original:**

```c
double calcular_precio_final(double precio_base, 
                              int cantidad, 
                              bool es_mayorista,
                              const char* codigo_postal) {
    // Descuento por cantidad
    double descuento_cantidad = 0;
    if (cantidad >= 100) {
        descuento_cantidad = 0.20;
    } else if (cantidad >= 50) {
        descuento_cantidad = 0.15;
    } else if (cantidad >= 10) {
        descuento_cantidad = 0.10;
    }
    
    // Descuento mayorista
    double descuento_mayorista = es_mayorista ? 0.05 : 0;
    
    // Descuento total (no acumulativo lineal)
    double descuento_total = descuento_cantidad + descuento_mayorista;
    if (descuento_total > 0.25) descuento_total = 0.25;
    
    double subtotal = precio_base * cantidad * (1 - descuento_total);
    
    // Impuesto según región
    double impuesto = 0.21;  // IVA estándar
    if (codigo_postal[0] == '9') {  // Patagonia
        impuesto = 0.10;
    }
    
    // Cargo por envío
    double envio = 0;
    if (cantidad < 5) {
        envio = 500;
    } else if (cantidad < 20) {
        envio = 300;
    }
    
    return subtotal * (1 + impuesto) + envio;
}
```

**Código Refactorizado:**

```c
double calcular_descuento_por_cantidad(int cantidad) {
    if (cantidad >= 100) return 0.20;
    if (cantidad >= 50) return 0.15;
    if (cantidad >= 10) return 0.10;
    return 0.0;
}

double calcular_descuento_mayorista(bool es_mayorista) {
    return es_mayorista ? 0.05 : 0.0;
}

double calcular_descuento_total(int cantidad, bool es_mayorista) {
    const double DESCUENTO_MAXIMO = 0.25;
    
    double descuento = calcular_descuento_por_cantidad(cantidad) +
                       calcular_descuento_mayorista(es_mayorista);
    
    return (descuento > DESCUENTO_MAXIMO) ? DESCUENTO_MAXIMO : descuento;
}

double calcular_impuesto_regional(const char* codigo_postal) {
    const double IVA_ESTANDAR = 0.21;
    const double IVA_PATAGONIA = 0.10;
    
    // Patagonia tiene código postal que empieza con 9
    if (codigo_postal[0] == '9') {
        return IVA_PATAGONIA;
    }
    
    return IVA_ESTANDAR;
}

double calcular_cargo_envio(int cantidad) {
    if (cantidad < 5) return 500.0;
    if (cantidad < 20) return 300.0;
    return 0.0;
}

double calcular_precio_final(double precio_base, 
                              int cantidad, 
                              bool es_mayorista,
                              const char* codigo_postal) {
    double descuento = calcular_descuento_total(cantidad, es_mayorista);
    double subtotal = precio_base * cantidad * (1 - descuento);
    
    double impuesto = calcular_impuesto_regional(codigo_postal);
    double total_con_impuesto = subtotal * (1 + impuesto);
    
    double envio = calcular_cargo_envio(cantidad);
    
    return total_con_impuesto + envio;
}
```

**Beneficios:**
- Cada regla de negocio está aislada
- Fácil modificar política de descuentos
- Testing unitario de cada componente
- Función principal muestra el flujo claramente

## Técnicas Avanzadas

### Composición de Funciones

Construir funciones complejas componiendo funciones simples:

```c
// Funciones atómicas
bool es_letra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool es_digito(char c) {
    return c >= '0' && c <= '9';
}

bool es_espacio(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

// Función compuesta
bool es_alfanumerico(char c) {
    return es_letra(c) || es_digito(c);
}

bool es_identificador_valido(const char* str) {
    if (str == NULL || strlen(str) == 0) return false;
    if (!es_letra(str[0]) && str[0] != '_') return false;
    
    for (size_t i = 1; str[i] != '\0'; i++) {
        if (!es_alfanumerico(str[i]) && str[i] != '_') {
            return false;
        }
    }
    
    return true;
}
```

### Extracción con Parámetros de Configuración

```c
typedef struct {
    double descuento_mayorista;
    double impuesto_estandar;
    double impuesto_reducido;
    double cargo_envio_pequeno;
    double cargo_envio_mediano;
} configuracion_precios_t;

double calcular_precio_con_config(double precio_base,
                                   int cantidad,
                                   bool es_mayorista,
                                   const configuracion_precios_t* config) {
    // Uso de configuración inyectada
    double descuento = es_mayorista ? config->descuento_mayorista : 0.0;
    double subtotal = precio_base * cantidad * (1 - descuento);
    
    // ... resto del cálculo usando config
    
    return subtotal;
}
```

### Extracción con Callbacks

Para lógica parametrizable:

```c
typedef bool (*criterio_filtro_t)(int valor);

bool es_par(int valor) {
    return valor % 2 == 0;
}

bool es_positivo(int valor) {
    return valor > 0;
}

int contar_elementos_que_cumplen(const int* arr, 
                                  int n,
                                  criterio_filtro_t criterio) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(arr[i])) {
            contador++;
        }
    }
    return contador;
}

// Uso
int pares = contar_elementos_que_cumplen(arr, n, es_par);
int positivos = contar_elementos_que_cumplen(arr, n, es_positivo);
```

## Antipatrones a Evitar

### 1. Sobre-Extracción

```c
// Excesivo - funciones triviales que no agregan valor
int incrementar(int x) {
    return x + 1;
}

int decrementar(int x) {
    return x - 1;
}

// Uso innecesariamente verboso
for (int i = 0; i < n; i = incrementar(i)) {
    // ...
}
```

### 2. Funciones con Demasiados Parámetros

```c
// Problemático
void procesar(int a, int b, int c, int d, int e, int f, int g) {
    // Difícil de usar y mantener
}

// Mejor: usar estructura
typedef struct {
    int param_a;
    int param_b;
    int param_c;
    // ...
} parametros_procesamiento_t;

void procesar(const parametros_procesamiento_t* params) {
    // Más claro
}
```

### 3. Funciones con Efectos Secundarios Ocultos

```c
// Problemático
int calcular_total(int* contador_global) {
    (*contador_global)++;  // Efecto secundario oculto
    return *contador_global * 100;
}

// Mejor: efecto secundario explícito o función pura
int calcular_total_puro(int contador) {
    return contador * 100;
}
```

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

```c
// Mal: mezcla niveles de abstracción
void procesar_pedido(pedido_t* pedido) {
    // Alto nivel
    if (!validar_pedido(pedido)) return;
    
    // Bajo nivel - no pertenece aquí
    for (int i = 0; i < pedido->num_items; i++) {
        if (pedido->items[i].precio < 0) {
            return;
        }
    }
    
    // Alto nivel
    guardar_pedido(pedido);
}

// Bien: nivel consistente
void procesar_pedido(pedido_t* pedido) {
    if (!validar_pedido(pedido)) return;
    if (!validar_items(pedido)) return;
    guardar_pedido(pedido);
}
```

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

La extracción de funciones es una habilidad que se desarrolla con práctica. Al principio puede parecer tedioso, pero con el tiempo se vuelve una segunda naturaleza que mejora dramáticamente la calidad del código.
