---
title: "Simplificación de Condicionales"
short_title: "Refactorización - Condicionales"
subtitle: "Técnicas para clarificar y simplificar lógica condicional compleja"
---

## Introducción

Los condicionales son una parte fundamental de la programación, pero también son una fuente común de complejidad y errores. Un código con lógica condicional compleja es difícil de leer, mantener y testear. La refactorización de condicionales busca hacer la lógica más clara, expresiva y mantenible.

Este apunte presenta técnicas sistemáticas para simplificar expresiones booleanas, reducir anidamiento, y hacer que las condiciones sean auto-explicativas.

:::{important} Claridad en las Condiciones
Como establece {ref}`0x0000h`, la claridad es fundamental. Una condición debe ser inmediatamente comprensible para cualquier lector, revelando su intención sin necesidad de análisis mental elaborado.
:::

## Problemas Comunes con Condicionales

### 1. Anidamiento Excesivo

```c
// Problemático: pirámide de la perdición
if (usuario != NULL) {
    if (usuario->activo) {
        if (usuario->edad >= 18) {
            if (usuario->saldo > 0) {
                procesar_compra(usuario);
            } else {
                printf("Saldo insuficiente\n");
            }
        } else {
            printf("Usuario menor de edad\n");
        }
    } else {
        printf("Usuario inactivo\n");
    }
} else {
    printf("Usuario inválido\n");
}
```

### 2. Condiciones Complejas

```c
// Difícil de entender de un vistazo
if ((estado == ACTIVO || estado == PENDIENTE) && 
    (tipo != TEMPORAL && tipo != PRUEBA) &&
    (saldo > 1000 || credito_disponible > 500) &&
    !(bloqueado || suspendido))
{
    // ...
}
```

### 3. Lógica Duplicada

```c
if (edad >= 18 && edad <= 65 && !jubilado) {
    precio = PRECIO_ADULTO;
}

// Más adelante en el código...
if (edad >= 18 && edad <= 65 && !jubilado) {
    aplicar_descuento();
}
```

### 4. Booleanos Implícitos

```c
// Redundante
if (es_valido() == true) {
    // ...
}

if (contador > 0) {
    return true;
} else {
    return false;
}
```

## Técnicas de Refactorización

### 1. Guardia de Cláusulas (Guard Clauses)

Invertir condiciones para manejar casos especiales temprano y reducir anidamiento.

**Antes:**

```c
void procesar_pedido(pedido_t* pedido) {
    if (pedido != NULL) {
        if (pedido->items_count > 0) {
            if (pedido->cliente != NULL) {
                if (pedido->cliente->saldo >= pedido->total) {
                    // Lógica principal de procesamiento
                    realizar_cargo(pedido);
                    actualizar_inventario(pedido);
                    enviar_confirmacion(pedido);
                } else {
                    printf("Saldo insuficiente\n");
                }
            } else {
                printf("Cliente inválido\n");
            }
        } else {
            printf("Pedido vacío\n");
        }
    } else {
        printf("Pedido nulo\n");
    }
}
```

**Después:**

```c
void procesar_pedido(pedido_t* pedido) {
    // Guardia de cláusulas - validaciones tempranas
    if (pedido == NULL) {
        printf("Pedido nulo\n");
        return;
    }
    
    if (pedido->items_count == 0) {
        printf("Pedido vacío\n");
        return;
    }
    
    if (pedido->cliente == NULL) {
        printf("Cliente inválido\n");
        return;
    }
    
    if (pedido->cliente->saldo < pedido->total) {
        printf("Saldo insuficiente\n");
        return;
    }
    
    // Lógica principal ahora está al mismo nivel
    realizar_cargo(pedido);
    actualizar_inventario(pedido);
    enviar_confirmacion(pedido);
}
```

**Beneficios:**
- Código más plano y fácil de leer
- Casos de error manejados temprano
- Lógica principal clara y sin anidamiento
- Siguiendo el patrón de {ref}`único retorno <ref-unico-retorno>`, podríamos usar `goto` para cleanup centralizado

### 2. Extracción de Condiciones a Variables Booleanas

**Antes:**

```c
if (usuario->edad >= 18 && usuario->edad <= 65 && 
    !usuario->jubilado && usuario->activo &&
    (usuario->tipo == REGULAR || usuario->tipo == PREMIUM)) {
    aplicar_beneficio(usuario);
}
```

**Después:**

```c
bool es_adulto_en_edad_laboral = usuario->edad >= 18 && 
                                  usuario->edad <= 65 && 
                                  !usuario->jubilado;

bool es_usuario_activo_valido = usuario->activo &&
                                 (usuario->tipo == REGULAR || 
                                  usuario->tipo == PREMIUM);

if (es_adulto_en_edad_laboral && es_usuario_activo_valido) {
    aplicar_beneficio(usuario);
}
```

**Beneficios:**
- Condiciones autodocumentadas
- Reutilizables
- Más fáciles de testear individualmente

### 3. Extracción de Condiciones a Funciones

Para lógica compleja o reutilizable:

**Antes:**

```c
void procesar_descuento(cliente_t* cliente, double total) {
    if ((cliente->compras_totales > 10000 && cliente->antiguedad > 365) ||
        (cliente->referidos >= 5) ||
        (cliente->tipo == VIP && cliente->activo)) {
        aplicar_descuento_premium(total);
    }
}
```

**Después:**

```c
bool es_cliente_fiel(const cliente_t* cliente) {
    return cliente->compras_totales > 10000 && 
           cliente->antiguedad > 365;
}

bool es_buen_referidor(const cliente_t* cliente) {
    return cliente->referidos >= 5;
}

bool es_vip_activo(const cliente_t* cliente) {
    return cliente->tipo == VIP && cliente->activo;
}

bool califica_para_descuento_premium(const cliente_t* cliente) {
    return es_cliente_fiel(cliente) ||
           es_buen_referidor(cliente) ||
           es_vip_activo(cliente);
}

void procesar_descuento(cliente_t* cliente, double total) {
    if (califica_para_descuento_premium(cliente)) {
        aplicar_descuento_premium(total);
    }
}
```

**Beneficios:**
- Nombres descriptivos documentan la lógica de negocio
- Funciones testeables independientemente
- Reutilizables en otros contextos
- Fácil modificar criterios de elegibilidad

### 4. Simplificación de Booleanos

**Antes:**

```c
bool es_valido(int valor) {
    if (valor > 0 && valor < 100) {
        return true;
    } else {
        return false;
    }
}

// Comparación redundante
if (esta_activo() == true) {
    // ...
}

if (contador > 0 == false) {
    // ...
}
```

**Después:**

```c
bool es_valido(int valor) {
    return valor > 0 && valor < 100;
}

// Uso directo del booleano
if (esta_activo()) {
    // ...
}

if (!esta_activo()) {
    // ...
}

if (contador == 0) {
    // ...
}
```

### 5. Reemplazo de Condicionales con Polimorfismo (simulado en C)

Para casos donde múltiples `if-else` determinan comportamiento:

**Antes:**

```c
double calcular_area(figura_t* figura) {
    if (figura->tipo == CIRCULO) {
        return PI * figura->datos.circulo.radio * 
               figura->datos.circulo.radio;
    } else if (figura->tipo == RECTANGULO) {
        return figura->datos.rectangulo.ancho * 
               figura->datos.rectangulo.alto;
    } else if (figura->tipo == TRIANGULO) {
        return 0.5 * figura->datos.triangulo.base * 
               figura->datos.triangulo.altura;
    }
    return 0;
}
```

**Después (con punteros a función):**

```c
typedef double (*calcular_area_fn)(const void* datos);

typedef struct {
    int tipo;
    calcular_area_fn calcular_area;
    void* datos;
} figura_t;

double calcular_area_circulo(const void* datos) {
    const circulo_t* c = (const circulo_t*)datos;
    return PI * c->radio * c->radio;
}

double calcular_area_rectangulo(const void* datos) {
    const rectangulo_t* r = (const rectangulo_t*)datos;
    return r->ancho * r->alto;
}

double calcular_area_triangulo(const void* datos) {
    const triangulo_t* t = (const triangulo_t*)datos;
    return 0.5 * t->base * t->altura;
}

double calcular_area(const figura_t* figura) {
    return figura->calcular_area(figura->datos);
}
```

### 6. Tabla de Decisión

Para lógica compleja con múltiples combinaciones:

**Antes:**

```c
char* obtener_categoria(int edad, bool estudiante, bool empleado) {
    if (edad < 18 && estudiante) {
        return "ESTUDIANTE_MENOR";
    } else if (edad < 18 && !estudiante) {
        return "MENOR";
    } else if (edad >= 18 && edad < 65 && estudiante) {
        return "ESTUDIANTE_ADULTO";
    } else if (edad >= 18 && edad < 65 && empleado) {
        return "EMPLEADO";
    } else if (edad >= 18 && edad < 65) {
        return "ADULTO";
    } else if (edad >= 65 && empleado) {
        return "JUBILADO_ACTIVO";
    } else {
        return "JUBILADO";
    }
}
```

**Después (con tabla):**

```c
typedef struct {
    bool (*condicion)(int edad, bool estudiante, bool empleado);
    const char* categoria;
} regla_categoria_t;

bool es_estudiante_menor(int edad, bool estudiante, bool empleado) {
    return edad < 18 && estudiante;
}

bool es_menor(int edad, bool estudiante, bool empleado) {
    return edad < 18 && !estudiante;
}

bool es_estudiante_adulto(int edad, bool estudiante, bool empleado) {
    return edad >= 18 && edad < 65 && estudiante;
}

bool es_empleado(int edad, bool estudiante, bool empleado) {
    return edad >= 18 && edad < 65 && empleado;
}

bool es_adulto(int edad, bool estudiante, bool empleado) {
    return edad >= 18 && edad < 65 && !estudiante && !empleado;
}

bool es_jubilado_activo(int edad, bool estudiante, bool empleado) {
    return edad >= 65 && empleado;
}

bool es_jubilado(int edad, bool estudiante, bool empleado) {
    return edad >= 65 && !empleado;
}

const regla_categoria_t REGLAS_CATEGORIA[] = {
    {es_estudiante_menor, "ESTUDIANTE_MENOR"},
    {es_menor, "MENOR"},
    {es_estudiante_adulto, "ESTUDIANTE_ADULTO"},
    {es_empleado, "EMPLEADO"},
    {es_adulto, "ADULTO"},
    {es_jubilado_activo, "JUBILADO_ACTIVO"},
    {es_jubilado, "JUBILADO"}
};

const int NUM_REGLAS = sizeof(REGLAS_CATEGORIA) / sizeof(REGLAS_CATEGORIA[0]);

const char* obtener_categoria(int edad, bool estudiante, bool empleado) {
    for (int i = 0; i < NUM_REGLAS; i++) {
        if (REGLAS_CATEGORIA[i].condicion(edad, estudiante, empleado)) {
            return REGLAS_CATEGORIA[i].categoria;
        }
    }
    return "DESCONOCIDO";
}
```

### 7. Uso de `switch` en lugar de `if-else` en cadena

Para comparaciones de igualdad con un valor:

**Antes:**

```c
void procesar_comando(char comando) {
    if (comando == 'A') {
        avanzar();
    } else if (comando == 'R') {
        retroceder();
    } else if (comando == 'I') {
        girar_izquierda();
    } else if (comando == 'D') {
        girar_derecha();
    } else if (comando == 'P') {
        parar();
    } else {
        printf("Comando inválido\n");
    }
}
```

**Después:**

```c
void procesar_comando(char comando) {
    switch (comando) {
        case 'A':
            avanzar();
            break;
        case 'R':
            retroceder();
            break;
        case 'I':
            girar_izquierda();
            break;
        case 'D':
            girar_derecha();
            break;
        case 'P':
            parar();
            break;
        default:
            printf("Comando inválido\n");
            break;
    }
}
```

## Casos Prácticos Completos

### Caso 1: Validación de Formulario

**Código Original:**

```c
bool validar_formulario(const char* nombre, 
                         const char* email,
                         const char* telefono,
                         int edad) {
    if (nombre != NULL) {
        if (strlen(nombre) >= 3) {
            if (email != NULL) {
                if (strchr(email, '@') != NULL) {
                    if (strlen(email) >= 5) {
                        if (telefono != NULL) {
                            if (strlen(telefono) >= 8) {
                                if (edad >= 18) {
                                    if (edad <= 120) {
                                        return true;
                                    } else {
                                        printf("Edad muy alta\n");
                                    }
                                } else {
                                    printf("Debe ser mayor de edad\n");
                                }
                            } else {
                                printf("Teléfono muy corto\n");
                            }
                        } else {
                            printf("Teléfono nulo\n");
                        }
                    } else {
                        printf("Email muy corto\n");
                    }
                } else {
                    printf("Email sin @\n");
                }
            } else {
                printf("Email nulo\n");
            }
        } else {
            printf("Nombre muy corto\n");
        }
    } else {
        printf("Nombre nulo\n");
    }
    return false;
}
```

**Código Refactorizado:**

```c
bool validar_nombre(const char* nombre) {
    if (nombre == NULL) {
        printf("Nombre nulo\n");
        return false;
    }
    
    if (strlen(nombre) < 3) {
        printf("Nombre muy corto\n");
        return false;
    }
    
    return true;
}

bool validar_email(const char* email) {
    if (email == NULL) {
        printf("Email nulo\n");
        return false;
    }
    
    if (strlen(email) < 5) {
        printf("Email muy corto\n");
        return false;
    }
    
    if (strchr(email, '@') == NULL) {
        printf("Email sin @\n");
        return false;
    }
    
    return true;
}

bool validar_telefono(const char* telefono) {
    if (telefono == NULL) {
        printf("Teléfono nulo\n");
        return false;
    }
    
    if (strlen(telefono) < 8) {
        printf("Teléfono muy corto\n");
        return false;
    }
    
    return true;
}

bool validar_edad(int edad) {
    if (edad < 18) {
        printf("Debe ser mayor de edad\n");
        return false;
    }
    
    if (edad > 120) {
        printf("Edad muy alta\n");
        return false;
    }
    
    return true;
}

bool validar_formulario(const char* nombre, 
                         const char* email,
                         const char* telefono,
                         int edad) {
    return validar_nombre(nombre) &&
           validar_email(email) &&
           validar_telefono(telefono) &&
           validar_edad(edad);
}
```

### Caso 2: Cálculo de Descuento Complejo

**Código Original:**

```c
double calcular_descuento(double monto, 
                           int cantidad,
                           bool es_miembro,
                           bool es_primera_compra,
                           const char* codigo_promo) {
    double descuento = 0;
    
    if (cantidad > 10 && monto > 1000) {
        if (es_miembro) {
            if (strcmp(codigo_promo, "VERANO") == 0) {
                descuento = 0.30;
            } else if (strcmp(codigo_promo, "FLASH") == 0) {
                if (cantidad > 20) {
                    descuento = 0.35;
                } else {
                    descuento = 0.25;
                }
            } else {
                descuento = 0.20;
            }
        } else {
            if (es_primera_compra) {
                descuento = 0.15;
            } else {
                descuento = 0.10;
            }
        }
    } else if (cantidad > 5 || monto > 500) {
        if (es_miembro) {
            descuento = 0.15;
        } else {
            descuento = 0.05;
        }
    } else {
        if (es_primera_compra) {
            descuento = 0.10;
        }
    }
    
    return descuento;
}
```

**Código Refactorizado:**

```c
bool es_compra_grande(double monto, int cantidad) {
    return cantidad > 10 && monto > 1000;
}

bool es_compra_mediana(double monto, int cantidad) {
    return cantidad > 5 || monto > 500;
}

double descuento_miembro_compra_grande(int cantidad, const char* codigo_promo) {
    if (strcmp(codigo_promo, "VERANO") == 0) {
        return 0.30;
    }
    
    if (strcmp(codigo_promo, "FLASH") == 0) {
        return cantidad > 20 ? 0.35 : 0.25;
    }
    
    return 0.20;
}

double descuento_no_miembro_compra_grande(bool es_primera_compra) {
    return es_primera_compra ? 0.15 : 0.10;
}

double calcular_descuento(double monto, 
                           int cantidad,
                           bool es_miembro,
                           bool es_primera_compra,
                           const char* codigo_promo) {
    if (es_compra_grande(monto, cantidad)) {
        if (es_miembro) {
            return descuento_miembro_compra_grande(cantidad, codigo_promo);
        } else {
            return descuento_no_miembro_compra_grande(es_primera_compra);
        }
    }
    
    if (es_compra_mediana(monto, cantidad)) {
        return es_miembro ? 0.15 : 0.05;
    }
    
    return es_primera_compra ? 0.10 : 0.0;
}
```

## Leyes de De Morgan

Útiles para simplificar expresiones booleanas complejas:

**Leyes:**
- `!(A && B)` ≡ `!A || !B`
- `!(A || B)` ≡ `!A && !B`

**Ejemplo:**

```c
// Antes
if (!(activo && validado)) {
    return;
}

// Después (más claro en contexto de guardia)
if (!activo || !validado) {
    return;
}
```

```c
// Antes
if (!(edad < 18 || edad > 65)) {
    aplicar_tarifa_regular();
}

// Después (más claro)
if (edad >= 18 && edad <= 65) {
    aplicar_tarifa_regular();
}
```

## Combinación con el Patrón de Único Retorno

Cuando se aplica el patrón de único retorno (ver {ref}`ref-unico-retorno`), las técnicas de simplificación de condicionales deben adaptarse para mantener un solo punto de salida.

### Guardia de Cláusulas con Único Retorno

**Guard Clauses tradicionales (múltiples returns):**

```c
int procesar_pago(usuario_t* usuario, double monto) {
    if (usuario == NULL) {
        return ERROR_USUARIO_NULL;
    }
    
    if (!usuario->activo) {
        return ERROR_USUARIO_INACTIVO;
    }
    
    if (usuario->saldo < monto) {
        return ERROR_SALDO_INSUFICIENTE;
    }
    
    // Procesar pago
    usuario->saldo -= monto;
    return EXITO;
}
```

**Adaptado a único retorno:**

```c
int procesar_pago(usuario_t* usuario, double monto) {
    int resultado = ERROR_DESCONOCIDO;
    
    if (usuario == NULL) {
        resultado = ERROR_USUARIO_NULL;
    } else if (!usuario->activo) {
        resultado = ERROR_USUARIO_INACTIVO;
    } else if (usuario->saldo < monto) {
        resultado = ERROR_SALDO_INSUFICIENTE;
    } else {
        // Procesar pago
        usuario->saldo -= monto;
        resultado = EXITO;
    }
    
    return resultado;
}
```

### Variables de Estado para Control de Flujo

Cuando se combina único retorno con condicionales complejos, usar variables de estado explícitas mejora la claridad.

**Antes (múltiples returns):**

```c
bool validar_transaccion(transaccion_t* trans) {
    if (trans->monto <= 0) {
        return false;
    }
    
    if (trans->origen == NULL || trans->destino == NULL) {
        return false;
    }
    
    if (trans->origen->saldo < trans->monto) {
        return false;
    }
    
    if (trans->origen->bloqueada || trans->destino->bloqueada) {
        return false;
    }
    
    return true;
}
```

**Después (único retorno con variable de estado):**

```c
bool validar_transaccion(const transaccion_t* trans) {
    bool es_valida = true;
    
    if (trans->monto <= 0) {
        es_valida = false;
    } else if (trans->origen == NULL || trans->destino == NULL) {
        es_valida = false;
    } else if (trans->origen->saldo < trans->monto) {
        es_valida = false;
    } else if (trans->origen->bloqueada || trans->destino->bloqueada) {
        es_valida = false;
    }
    
    return es_valida;
}
```

### Combinando Predicados y Único Retorno

**Con múltiples returns:**

```c
bool puede_realizar_compra(const usuario_t* u, double monto) {
    if (!es_usuario_valido(u)) return false;
    if (!tiene_saldo_suficiente(u, monto)) return false;
    if (!esta_dentro_limite_diario(u, monto)) return false;
    return true;
}
```

**Con único retorno:**

```c
bool puede_realizar_compra(const usuario_t* u, double monto) {
    bool puede = false;
    
    if (es_usuario_valido(u) &&
        tiene_saldo_suficiente(u, monto) &&
        esta_dentro_limite_diario(u, monto)) {
        puede = true;
    }
    
    return puede;
}
```

**O de manera más concisa:**

```c
bool puede_realizar_compra(const usuario_t* u, double monto) {
    return es_usuario_valido(u) &&
           tiene_saldo_suficiente(u, monto) &&
           esta_dentro_limite_diario(u, monto);
}
```

### Caso Práctico: Autenticación con Único Retorno

**Antes (múltiples returns):**

```c
int autenticar(const char* usuario, const char* password) {
    if (usuario == NULL || password == NULL) {
        return AUTH_ERROR_PARAMETROS;
    }
    
    usuario_t* u = buscar_usuario(usuario);
    if (u == NULL) {
        return AUTH_ERROR_USUARIO_NO_EXISTE;
    }
    
    if (u->intentos_fallidos >= MAX_INTENTOS) {
        return AUTH_ERROR_BLOQUEADO;
    }
    
    if (!verificar_password(u, password)) {
        u->intentos_fallidos++;
        return AUTH_ERROR_PASSWORD_INCORRECTO;
    }
    
    u->intentos_fallidos = 0;
    u->ultimo_acceso = time(NULL);
    return AUTH_EXITO;
}
```

**Después (único retorno con flujo claro):**

```c
int autenticar(const char* usuario, const char* password) {
    int resultado = AUTH_ERROR_DESCONOCIDO;
    usuario_t* u = NULL;
    
    // Validación de parámetros
    if (usuario == NULL || password == NULL) {
        resultado = AUTH_ERROR_PARAMETROS;
    } else {
        u = buscar_usuario(usuario);
        
        if (u == NULL) {
            resultado = AUTH_ERROR_USUARIO_NO_EXISTE;
        } else if (u->intentos_fallidos >= MAX_INTENTOS) {
            resultado = AUTH_ERROR_BLOQUEADO;
        } else if (!verificar_password(u, password)) {
            u->intentos_fallidos++;
            resultado = AUTH_ERROR_PASSWORD_INCORRECTO;
        } else {
            // Autenticación exitosa
            u->intentos_fallidos = 0;
            u->ultimo_acceso = time(NULL);
            resultado = AUTH_EXITO;
        }
    }
    
    return resultado;
}
```

### Manejo de Recursos con Único Retorno

El patrón de único retorno es especialmente útil cuando se manejan recursos que deben liberarse.

**Antes (múltiples returns, riesgo de fugas):**

```c
char* leer_archivo(const char* ruta) {
    FILE* f = fopen(ruta, "r");
    if (f == NULL) {
        return NULL;
    }
    
    fseek(f, 0, SEEK_END);
    long tam = ftell(f);
    if (tam < 0) {
        fclose(f);  // Fácil olvidar esto
        return NULL;
    }
    
    char* buffer = malloc(tam + 1);
    if (buffer == NULL) {
        fclose(f);  // Y esto
        return NULL;
    }
    
    fseek(f, 0, SEEK_SET);
    size_t leidos = fread(buffer, 1, tam, f);
    if (leidos != tam) {
        free(buffer);  // Y esto
        fclose(f);     // Y esto
        return NULL;
    }
    
    buffer[tam] = '\0';
    fclose(f);
    return buffer;
}
```

**Después (único retorno, liberación garantizada):**

```c
char* leer_archivo(const char* ruta) {
    char* resultado = NULL;
    FILE* f = NULL;
    char* buffer = NULL;
    
    f = fopen(ruta, "r");
    if (f != NULL) {
        fseek(f, 0, SEEK_END);
        long tam = ftell(f);
        
        if (tam >= 0) {
            buffer = malloc(tam + 1);
            
            if (buffer != NULL) {
                fseek(f, 0, SEEK_SET);
                size_t leidos = fread(buffer, 1, tam, f);
                
                if (leidos == tam) {
                    buffer[tam] = '\0';
                    resultado = buffer;
                    buffer = NULL;  // No liberar si exitoso
                }
            }
        }
    }
    
    // Limpieza centralizada
    if (buffer != NULL) {
        free(buffer);
    }
    if (f != NULL) {
        fclose(f);
    }
    
    return resultado;
}
```

### Variables de Control para Lazos

El patrón de único retorno se combina bien con variables de control en lazos.

**Antes (con break/return):**

```c
int buscar_elemento(const int* arr, int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i;  // Retorno temprano
        }
    }
    return -1;
}
```

**Después (único retorno):**

```c
int buscar_elemento(const int* arr, int n, int valor) {
    int indice = -1;
    
    for (int i = 0; i < n && indice == -1; i++) {
        if (arr[i] == valor) {
            indice = i;
        }
    }
    
    return indice;
}
```

### Balance entre Claridad y Único Retorno

:::{tip} Pragmatismo
En funciones muy simples, los múltiples returns pueden ser más claros. El patrón de único retorno es más valioso en:
- Funciones que manejan recursos
- Funciones con lógica compleja
- Código que requiere depuración frecuente
- Proyectos con estándares estrictos
:::

**Funciones simples - múltiples returns aceptables:**

```c
bool es_par(int n) {
    return n % 2 == 0;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}
```

**Funciones complejas - único retorno preferible:**

```c
int procesar_pedido_complejo(pedido_t* pedido, contexto_t* ctx) {
    int resultado = ERROR_DESCONOCIDO;
    recurso_t* recurso = NULL;
    
    // Múltiples validaciones y manejo de recursos
    if (validar_pedido(pedido)) {
        recurso = adquirir_recurso(ctx);
        
        if (recurso != NULL) {
            if (procesar_con_recurso(pedido, recurso)) {
                resultado = EXITO;
            } else {
                resultado = ERROR_PROCESAMIENTO;
            }
        } else {
            resultado = ERROR_RECURSO;
        }
    } else {
        resultado = ERROR_VALIDACION;
    }
    
    // Limpieza garantizada
    if (recurso != NULL) {
        liberar_recurso(recurso);
    }
    
    return resultado;
}
```

## Resumen

Técnicas para simplificar condicionales:

1. **Guard Clauses:** Validaciones tempranas para reducir anidamiento
2. **Variables Booleanas:** Dar nombres descriptivos a condiciones complejas
3. **Funciones de Predicado:** Encapsular lógica condicional reutilizable
4. **Simplificación Booleana:** Retornar expresiones directamente
5. **Polimorfismo:** Reemplazar condicionales con despacho dinámico
6. **Tablas de Decisión:** Para lógica compleja con muchas combinaciones
7. **Switch:** En lugar de cadenas if-else para valores discretos
8. **Único Retorno:** Combinar con condicionales para mejor manejo de recursos

**Principios clave:**
- Una condición debe ser inmediatamente comprensible
- Preferir código plano sobre anidamiento profundo
- Usar nombres descriptivos que documenten la intención
- Extraer condiciones complejas a funciones
- Aplicar Leyes de De Morgan para clarificar negaciones
- El único retorno facilita manejo de recursos y depuración
- Balance entre claridad y consistencia según el contexto

La claridad en los condicionales es esencial para código mantenible y libre de bugs.
