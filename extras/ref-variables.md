---
title: "Refactorización de Variables y Alcance"
short_title: "Refactorización - Variables"
subtitle: "Optimización del alcance, inicialización y gestión de variables"
---

## Introducción

La gestión apropiada de variables es fundamental para escribir código claro, seguro y mantenible. Este apunte cubre técnicas de refactorización enfocadas en mejorar el uso de variables: reducir su alcance, mejorar la inicialización, eliminar variables temporales innecesarias, y aplicar el principio de inmutabilidad cuando sea posible.

Un buen manejo de variables no solo hace el código más legible, sino que también previene errores sutiles relacionados con el estado mutable y reduce la carga cognitiva al leer el código.

:::{important} Principio de Mínimo Alcance
Como establece {ref}`0x0003h`, las variables deben inicializarse siempre con un valor conocido. Además, el alcance de una variable debe ser el mínimo necesario para su función, reduciendo la posibilidad de errores y facilitando el razonamiento sobre el código.
:::

## Problemas Comunes con Variables

### 1. Alcance Innecesariamente Amplio

```c
// Problemático: variables declaradas al inicio de funciones largas
void procesar_datos() {
    int i, j, k;
    int resultado;
    double temporal;
    char buffer[256];
    
    // ... muchas líneas de código ...
    
    // i solo se usa aquí
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    // ... más código ...
    
    // temporal solo se usa aquí
    temporal = calcular_algo();
}
```

### 2. Variables sin Inicializar

```c
// Peligroso: variables no inicializadas
int calcular_suma(int* arr, int n) {
    int suma;  // ¡Valor indeterminado!
    
    if (n > 0) {
        suma = 0;
        for (int i = 0; i < n; i++) {
            suma += arr[i];
        }
    }
    
    return suma;  // Puede retornar basura si n <= 0
}
```

### 3. Variables Temporales Innecesarias

```c
// Verboso: temporales que no agregan claridad
int obtener_edad() {
    int edad_temporal = 25;
    return edad_temporal;
}

double calcular_precio(double base, double descuento) {
    double precio_con_descuento = base * (1 - descuento);
    double precio_final = precio_con_descuento;
    return precio_final;
}
```

### 4. Reutilización Inapropiada de Variables

```c
// Confuso: misma variable para propósitos diferentes
void procesar() {
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

## Técnicas de Refactorización

### 1. Reducir Alcance de Variables

Declarar variables en el punto más cercano a su primer uso.

**Antes:**

```c
void procesar_archivo(const char* ruta) {
    FILE* archivo;
    char linea[256];
    int contador;
    int i;
    
    archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        return;
    }
    
    contador = 0;
    while (fgets(linea, sizeof(linea), archivo)) {
        contador++;
    }
    
    printf("Líneas: %d\n", contador);
    
    fclose(archivo);
    
    // i solo se usa aquí
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}
```

**Después:**

```c
void procesar_archivo(const char* ruta) {
    FILE* archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        return;
    }
    
    int contador = 0;
    char linea[256];
    
    while (fgets(linea, sizeof(linea), archivo)) {
        contador++;
    }
    
    printf("Líneas: %d\n", contador);
    fclose(archivo);
    
    // i declarada en el lazo
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}
```

**Beneficios:**
- Más claro dónde se usa cada variable
- Menos espacio mental para rastrear estado
- Inicialización en el punto de declaración

### 2. Inicialización Segura

Siempre inicializar variables en el punto de declaración.

**Antes:**

```c
int procesar_datos(int* arr, int n) {
    int suma;
    int maximo;
    int contador;
    
    if (n > 0) {
        suma = 0;
        maximo = arr[0];
        contador = 0;
        
        for (int i = 0; i < n; i++) {
            suma += arr[i];
            if (arr[i] > maximo) {
                maximo = arr[i];
            }
            contador++;
        }
    }
    
    return suma;  // ¡Peligro!
}
```

**Después:**

```c
int procesar_datos(const int* arr, int n) {
    int suma = 0;
    int maximo = 0;
    int contador = 0;
    
    if (n > 0) {
        maximo = arr[0];
        
        for (int i = 0; i < n; i++) {
            suma += arr[i];
            if (arr[i] > maximo) {
                maximo = arr[i];
            }
            contador++;
        }
    }
    
    return suma;
}
```

**Mejor aún (con validación temprana):**

```c
int procesar_datos(const int* arr, int n) {
    if (n <= 0) {
        return 0;
    }
    
    int suma = 0;
    int maximo = arr[0];
    
    for (int i = 0; i < n; i++) {
        suma += arr[i];
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    
    return suma;
}
```

### 3. Eliminar Variables Temporales Innecesarias

**Antes:**

```c
double calcular_total(double precio, double cantidad, double impuesto) {
    double subtotal = precio * cantidad;
    double monto_impuesto = subtotal * impuesto;
    double total = subtotal + monto_impuesto;
    return total;
}

int es_par(int n) {
    int resto = n % 2;
    int resultado = (resto == 0);
    return resultado;
}
```

**Después:**

```c
double calcular_total(double precio, double cantidad, double impuesto) {
    double subtotal = precio * cantidad;
    return subtotal * (1 + impuesto);
}

int es_par(int n) {
    return n % 2 == 0;
}
```

**Cuando las temporales SÍ agregan valor:**

```c
// Temporales útiles para claridad
double calcular_factura(const item_t* items, int n, double tasa_iva) {
    double subtotal = calcular_subtotal(items, n);
    double descuento = calcular_descuento_aplicable(subtotal);
    double subtotal_con_descuento = subtotal - descuento;
    double iva = subtotal_con_descuento * tasa_iva;
    double total = subtotal_con_descuento + iva;
    
    return total;
}
```

### 4. Separar Variables con Propósitos Diferentes

No reutilizar variables para diferentes propósitos.

**Antes:**

```c
void procesar() {
    int valor;
    
    // Primer uso: entrada
    valor = leer_entrada();
    validar(valor);
    
    // Segundo uso: resultado intermedio (diferente significado)
    valor = calcular_resultado(valor);
    transformar(valor);
    
    // Tercer uso: contador (totalmente diferente)
    valor = 0;
    for (int i = 0; i < 10; i++) {
        if (condicion(i)) {
            valor++;
        }
    }
    
    printf("Contados: %d\n", valor);
}
```

**Después:**

```c
void procesar() {
    int entrada = leer_entrada();
    validar(entrada);
    
    int resultado = calcular_resultado(entrada);
    transformar(resultado);
    
    int elementos_contados = 0;
    for (int i = 0; i < 10; i++) {
        if (condicion(i)) {
            elementos_contados++;
        }
    }
    
    printf("Contados: %d\n", elementos_contados);
}
```

**Beneficios:**
- Cada variable tiene un propósito claro
- Nombres descriptivos autodocumentan el código
- Más fácil rastrear el flujo de datos

### 5. Usar `const` para Valores Inmutables

Aplicar `const` a variables que no deben cambiar.

**Antes:**

```c
void procesar_pedido(pedido_t* pedido) {
    double tasa_iva = 0.21;
    double descuento_vip = 0.15;
    int max_intentos = 3;
    
    // ... código que NO debería modificar estas variables
    
    tasa_iva = 0.10;  // ¡Bug! Cambio accidental
}
```

**Después:**

```c
void procesar_pedido(pedido_t* pedido) {
    const double TASA_IVA = 0.21;
    const double DESCUENTO_VIP = 0.15;
    const int MAX_INTENTOS = 3;
    
    // ... código
    
    // TASA_IVA = 0.10;  // Error de compilación: assignment of read-only variable
}
```

**Aplicar `const` a parámetros que no se modifican:**

```c
// Antes
void procesar_datos(int* arr, int n, configuracion_t* config) {
    // ...
}

// Después
void procesar_datos(const int* arr, int n, const configuracion_t* config) {
    // Garantiza que no modificamos arr ni config
}
```

### 6. Extracción a Variables con Nombre

Dar nombres significativos a expresiones complejas.

**Antes:**

```c
if ((usuario->edad >= 18 && usuario->edad <= 65) &&
    (usuario->saldo > 1000 || usuario->credito > 500) &&
    !usuario->bloqueado) {
    procesar_transaccion(usuario);
}

// Cálculo complejo sin contexto
double total = precio * cantidad * (1 - (cantidad > 10 ? 0.15 : 0.05)) * 1.21;
```

**Después:**

```c
bool es_edad_valida = usuario->edad >= 18 && usuario->edad <= 65;
bool tiene_fondos = usuario->saldo > 1000 || usuario->credito > 500;
bool puede_operar = es_edad_valida && tiene_fondos && !usuario->bloqueado;

if (puede_operar) {
    procesar_transaccion(usuario);
}

// Cálculo con variables intermedias
const double TASA_IVA = 0.21;
double descuento = (cantidad > 10) ? 0.15 : 0.05;
double subtotal = precio * cantidad;
double subtotal_con_descuento = subtotal * (1 - descuento);
double total = subtotal_con_descuento * (1 + TASA_IVA);
```

### 7. Variables de Lazo en el Alcance Mínimo

**Antes (estilo C89):**

```c
void procesar() {
    int i, j;
    
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    // i todavía existe y tiene valor 10
    
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 3; i++) {  // Reutiliza i
            printf("%d,%d\n", i, j);
        }
    }
}
```

**Después (C99+):**

```c
void procesar() {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
    // i ya no existe aquí
    
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 3; i++) {  // Nueva i, no confusión
            printf("%d,%d\n", i, j);
        }
    }
}
```

## Casos Prácticos Completos

### Caso 1: Análisis de Texto

**Código Original:**

```c
void analizar_texto(const char* texto) {
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
    
    for (i = 0; i < longitud; i++) {
        caracter_actual = texto[i];
        
        if (caracter_actual == '\n') {
            lineas++;
        }
        
        if (!isalnum(caracter_actual) && !isspace(caracter_actual)) {
            caracteres_especiales++;
        }
        
        if (isspace(caracter_actual)) {
            en_palabra = 0;
        } else if (!en_palabra) {
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

**Código Refactorizado:**

```c
typedef struct {
    int palabras;
    int lineas;
    int caracteres_especiales;
} estadisticas_texto_t;

bool es_caracter_especial(char c) {
    return !isalnum(c) && !isspace(c);
}

estadisticas_texto_t analizar_texto(const char* texto) {
    estadisticas_texto_t stats = {
        .palabras = 0,
        .lineas = 1,
        .caracteres_especiales = 0
    };
    
    bool en_palabra = false;
    const int longitud = strlen(texto);
    
    for (int i = 0; i < longitud; i++) {
        const char caracter_actual = texto[i];
        
        if (caracter_actual == '\n') {
            stats.lineas++;
        }
        
        if (es_caracter_especial(caracter_actual)) {
            stats.caracteres_especiales++;
        }
        
        if (isspace(caracter_actual)) {
            en_palabra = false;
        } else if (!en_palabra) {
            en_palabra = true;
            stats.palabras++;
        }
    }
    
    return stats;
}

void mostrar_estadisticas(estadisticas_texto_t stats) {
    printf("Palabras: %d\n", stats.palabras);
    printf("Líneas: %d\n", stats.lineas);
    printf("Caracteres especiales: %d\n", stats.caracteres_especiales);
}
```

**Mejoras aplicadas:**
- Variables declaradas cerca de su uso
- Inicialización en la declaración
- Variables de lazo con alcance reducido
- Uso de `const` para valores inmutables
- Nombres descriptivos
- Separación de lógica de cálculo y presentación

### Caso 2: Procesamiento de Transacciones

**Código Original:**

```c
int procesar_transacciones(transaccion_t* trans, int n) {
    int i, j;
    double total, subtotal, impuesto, descuento;
    int aprobadas, rechazadas, pendientes;
    int resultado;
    char estado;
    
    total = 0;
    aprobadas = 0;
    rechazadas = 0;
    pendientes = 0;
    
    for (i = 0; i < n; i++) {
        subtotal = trans[i].monto;
        
        // Calcular descuento
        if (trans[i].tipo == VIP) {
            descuento = 0.15;
        } else if (trans[i].tipo == REGULAR) {
            descuento = 0.05;
        } else {
            descuento = 0;
        }
        
        subtotal = subtotal * (1 - descuento);
        impuesto = subtotal * 0.21;
        total = subtotal + impuesto;
        
        trans[i].total = total;
        
        // Validar
        if (trans[i].cuenta_origen == NULL) {
            estado = 'R';
        } else if (trans[i].cuenta_origen->saldo < total) {
            estado = 'R';
        } else {
            estado = 'A';
        }
        
        if (estado == 'A') {
            aprobadas++;
        } else if (estado == 'R') {
            rechazadas++;
        }
        
        trans[i].estado = estado;
    }
    
    printf("Aprobadas: %d, Rechazadas: %d\n", aprobadas, rechazadas);
    
    resultado = (rechazadas == 0) ? 0 : -1;
    return resultado;
}
```

**Código Refactorizado:**

```c
typedef struct {
    int aprobadas;
    int rechazadas;
} resumen_procesamiento_t;

double calcular_descuento_tipo(tipo_cliente_t tipo) {
    switch (tipo) {
        case VIP:     return 0.15;
        case REGULAR: return 0.05;
        default:      return 0.0;
    }
}

double calcular_total_transaccion(double monto, tipo_cliente_t tipo) {
    const double TASA_IVA = 0.21;
    
    double descuento = calcular_descuento_tipo(tipo);
    double subtotal = monto * (1 - descuento);
    double impuesto = subtotal * TASA_IVA;
    
    return subtotal + impuesto;
}

bool validar_transaccion(const transaccion_t* trans) {
    if (trans->cuenta_origen == NULL) {
        return false;
    }
    
    if (trans->cuenta_origen->saldo < trans->total) {
        return false;
    }
    
    return true;
}

resumen_procesamiento_t procesar_transacciones(transaccion_t* trans, int n) {
    resumen_procesamiento_t resumen = {0};
    
    for (int i = 0; i < n; i++) {
        trans[i].total = calcular_total_transaccion(trans[i].monto, 
                                                     trans[i].tipo);
        
        bool aprobada = validar_transaccion(&trans[i]);
        trans[i].estado = aprobada ? 'A' : 'R';
        
        if (aprobada) {
            resumen.aprobadas++;
        } else {
            resumen.rechazadas++;
        }
    }
    
    printf("Aprobadas: %d, Rechazadas: %d\n", 
           resumen.aprobadas, resumen.rechazadas);
    
    return resumen;
}
```

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

```c
void mostrar_info_usuario(usuario_t* u) {
    printf("Nombre: %s %s\n", u->nombre, u->apellido);
    printf("Edad: %d\n", calcular_edad(u->fecha_nacimiento));
    printf("Categoría: %s\n", 
           es_premium(u) ? "Premium" : "Regular");
    printf("Estado: %s\n", 
           u->activo && !u->bloqueado ? "Activo" : "Inactivo");
}
```

**Después:**

```c
void mostrar_info_usuario(const usuario_t* u) {
    const char* nombre_completo = formatear_nombre(u->nombre, u->apellido);
    const int edad = calcular_edad(u->fecha_nacimiento);
    const char* categoria = es_premium(u) ? "Premium" : "Regular";
    const bool operativo = u->activo && !u->bloqueado;
    const char* estado = operativo ? "Activo" : "Inactivo";
    
    printf("Nombre: %s\n", nombre_completo);
    printf("Edad: %d\n", edad);
    printf("Categoría: %s\n", categoria);
    printf("Estado: %s\n", estado);
}
```

### Patrón: Replacement of Temp with Query

**Antes:**

```c
double calcular_precio(item_t* item) {
    double precio_base = item->precio * item->cantidad;
    if (precio_base > 1000) {
        return precio_base * 0.95;
    } else {
        return precio_base * 0.98;
    }
}
```

**Después:**

```c
double obtener_precio_base(const item_t* item) {
    return item->precio * item->cantidad;
}

double calcular_precio(const item_t* item) {
    const double precio_base = obtener_precio_base(item);
    const double descuento = (precio_base > 1000) ? 0.95 : 0.98;
    
    return precio_base * descuento;
}
```

## Antipatrones a Evitar

### 1. Variables Globales Innecesarias

```c
// Problemático
int contador_global = 0;

void procesar_item(item_t* item) {
    contador_global++;
    // ...
}
```

**Mejor:**

```c
typedef struct {
    int items_procesados;
    // ... otros datos de contexto
} contexto_procesamiento_t;

void procesar_item(item_t* item, contexto_procesamiento_t* ctx) {
    ctx->items_procesados++;
    // ...
}
```

### 2. Variables "God" (Demasiado Propósito)

```c
// Problemático
int datos;  // Usado para todo

datos = leer_archivo();
datos = procesar(datos);
datos = validar(datos);
datos = contar_elementos(datos);
```

### 3. Variables con Nombres No Descriptivos

```c
// Problemático
int d;  // días? dinero? datos?
int tmp;
int x, y, z;
```

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

El manejo apropiado de variables es fundamental para código seguro, claro y mantenible.
