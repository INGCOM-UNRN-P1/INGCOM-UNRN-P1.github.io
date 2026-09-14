---
title: "Simplificación de Condicionales"
short_title: "Simplificación de condicionales"
subtitle: "Técnicas para clarificar y simplificar lógica condicional compleja"
---

(refactorizacion-simplify-conditionals)=
## Introducción

Los condicionales son una parte fundamental de la programación, pero también son
una fuente común de complejidad y errores. Un código con lógica condicional
compleja es difícil de leer, mantener y testear. La refactorización de
condicionales busca hacer la lógica más clara, expresiva y mantenible.

Este apunte presenta técnicas sistemáticas para simplificar expresiones
booleanas, reducir anidamiento, y hacer que las condiciones sean
auto-explicativas.

:::{important} Claridad en las Condiciones

Como establece {ref}`0x0001h`, la claridad es fundamental. Una condición debe
ser inmediatamente comprensible para cualquier lector, revelando su intención
sin necesidad de análisis mental elaborado.

:::
<!-- {important} Claridad en las Condiciones -->

## Reglas de estilo que resuelve

Las técnicas de este apunte no son recetas aisladas: cada una responde a un
problema concreto que la cátedra modeló como regla. Detectar el antipatrón y
saber qué reescritura lo elimina es lo que conecta la teoría con el código que
revisás. La siguiente tabla mapea cada regla con el problema que modela y la
técnica de esta guía que lo resuelve.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
| --- | --- | --- |
| {ref}`0x1004h` | Condiciones que combinan varios operadores lógicos sin descomponerse | Se extraen a variables booleanas y funciones predicado con nombre significativo |
| {ref}`0x1013h` | Expresiones que mezclan `&&` y `||` y dejan la agrupación librada a la precedencia | Se agregan paréntesis aclaratorios en cada combinación lógica |
| {ref}`0x1005h` | Condiciones que dependen de la "veracidad" implícita de enteros, punteros o `char` | Se comparan de forma explícita contra `NULL`, `0`, `'\0'` o `true`/`false` |
| {ref}`0x100Bh` | Comparaciones en estilo Yoda (`CONST == variable`) | Se escribe siempre `variable == CONSTANTE`, con la variable a la izquierda |
| {ref}`0x1012h` | Asignaciones embebidas dentro de una estructura de control | La asignación se separa en su propia sentencia antes del `if`, `while` o `for` |
| {ref}`0x1009h` | Uso del operador `=` simple dentro de una condición lógica | La condición se limita a comparar (`==`) y la asignación se mueve afuera |
| {ref}`0x1010h` | Comparaciones encadenadas no idiomáticas (`a < b < c`) | Se reescriben de forma explícita como `a < b && b < c` |
| {ref}`0x1017h` | Condiciones negativas indirectas (`!(...)`) difíciles de leer | Se afirma el caso directo o se aísla la negación en una variable positiva |
| {ref}`0x1015h` | Anidación de más de tres niveles | Guard clauses, retornos anticipados y extracción de funciones |
| {ref}`0x2001h` | Funciones sin validar precondiciones y con el camino feliz anidado | Cláusulas de guarda al inicio y liberación centralizada de recursos |
| {ref}`0x100Fh` | `else` después de una rama que termina con `return` o abandona | La rama alterna se desanida al mismo nivel del `if` |
| {ref}`0x2013h` | Bloques `else` superfluos tras `return`, `exit`, `break`, `continue` o `goto` | Se elimina el `else` y el flujo continúa al mismo nivel |

## Problemas Comunes con Condicionales

### 1. Anidamiento Excesivo

```{code-block} c
:linenos:
// Problemático: pirámide de la perdición
if (usuario != NULL)
{
    if (usuario->activo)
    {
        if (usuario->edad >= 18)
        {
            if (usuario->saldo > 0)
            {
                procesar_compra(usuario);
            }
            else
            {
                printf("Saldo insuficiente\n");
            }
        }
        else
        {
            printf("Usuario menor de edad\n");
        }
    }
    else
    {
        printf("Usuario inactivo\n");
    }
}
else
{
    printf("Usuario inválido\n");
}
```
<!-- {code-block} c -->

La "pirámide de la perdición" es el síntoma clásico de {ref}`0x1015h`: cada
nivel adicional de `if` aleja el camino feliz del borde izquierdo y multiplica
los casos que hay que sostener mentalmente. La respuesta de esta guía es
invertir las condiciones con guard clauses, tal como prescribe {ref}`0x2001h`.

### 2. Condiciones Complejas

```{code-block} c
:linenos:
// Difícil de entender de un vistazo
if ((estado == ACTIVO || estado == PENDIENTE) &&
    (tipo != TEMPORAL && tipo != PRUEBA) &&
    (saldo > 1000 || credito_disponible > 500) && !(bloqueado || suspendido))
{
    // ...
}
```
<!-- {code-block} c -->

Esta condición viola {ref}`0x1004h` porque mezcla demasiadas subexpresiones en
un solo lugar, y agrava {ref}`0x1013h` al combinar `&&` y `||` sin paréntesis
que expliciten la agrupación deseada. Extraer cada grupo a una variable con
nombre es la solución directa.

### 3. Lógica Duplicada

```{code-block} c
:linenos:
if (edad >= 18 && edad <= 65 && !jubilado)
{
    precio = PRECIO_ADULTO;
}
// Más adelante en el código...
if (edad >= 18 && edad <= 65 && !jubilado)
{
    aplicar_descuento();
}
```
<!-- {code-block} c -->

### 4. Booleanos Implícitos

```{code-block} c
:linenos:
// Redundante
if (es_valido() == true)
{
    // ...
}
if (contador > 0)
{
    return true;
}
else
{
    return false;
}
```
<!-- {code-block} c -->

Comparar un booleano contra `true` o `false` no aporta información y depende de
la "veracidad" del tipo; reescribilo de forma explícita como pide
{ref}`0x1005h`. Tampoco inviertas el orden a la manera de Yoda
(`true == es_valido`): la variable va siempre a la izquierda, según
{ref}`0x100Bh`.

## Técnicas de Refactorización

### 1. Guardia de Cláusulas (Guard Clauses)

Invertir condiciones para manejar casos especiales temprano y reducir
anidamiento.

**Antes:**

```{code-block} c
:linenos:
void procesar_pedido(pedido_t *pedido)
{
    if (pedido != NULL)
    {
        if (pedido->items_count > 0)
        {
            if (pedido->cliente != NULL)
            {
                if (pedido->cliente->saldo >= pedido->total)
                {
                    // Lógica principal de procesamiento
                    realizar_cargo(pedido);
                    actualizar_inventario(pedido);
                    enviar_confirmacion(pedido);
                }
                else
                {
                    printf("Saldo insuficiente\n");
                }
            }
            else
            {
                printf("Cliente inválido\n");
            }
        }
        else
        {
            printf("Pedido vacío\n");
        }
    }
    else
    {
        printf("Pedido nulo\n");
    }
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void procesar_pedido(pedido_t *pedido)
{
    // Guardia de cláusulas - validaciones tempranas
    if (pedido == NULL)
    {
        printf("Pedido nulo\n");
        return;
    }
    if (pedido->items_count == 0)
    {
        printf("Pedido vacío\n");
        return;
    }
    if (pedido->cliente == NULL)
    {
        printf("Cliente inválido\n");
        return;
    }
    if (pedido->cliente->saldo < pedido->total)
    {
        printf("Saldo insuficiente\n");
        return;
    }
    // Lógica principal ahora está al mismo nivel
    realizar_cargo(pedido);
    actualizar_inventario(pedido);
    enviar_confirmacion(pedido);
}
```
<!-- {code-block} c -->

**Beneficios:**
- Código más plano y fácil de leer
- Casos de error manejados temprano
- Lógica principal clara y sin anidamiento
- Siguiendo el patrón de {ref}`único retorno <ref-unico-retorno>`, podríamos
  usar `goto` para cleanup centralizado

Invertir la condición para abandonar temprano es exactamente lo que prescriben
{ref}`0x2001h` y {ref}`0x1015h`. Además, cuando una rama termina en `return`, el
`else` que la sigue sobra: hay que desanidarlo según {ref}`0x100Fh` y
{ref}`0x2013h`.

### 2. Extracción de Condiciones a Variables Booleanas

**Antes:**

``` c
if (usuario->edad >= 18 && usuario->edad <= 65 && !usuario->jubilado &&
    usuario->activo && (usuario->tipo == REGULAR || usuario->tipo == PREMIUM))
{
    aplicar_beneficio(usuario);
}
```
<!-- c -->

**Después:**

```{code-block} c
:linenos:
bool es_adulto_en_edad_laboral =
    usuario->edad >= 18 && usuario->edad <= 65 && !usuario->jubilado;
bool es_usuario_activo_valido =
    usuario->activo && (usuario->tipo == REGULAR || usuario->tipo == PREMIUM);
if (es_adulto_en_edad_laboral && es_usuario_activo_valido)
{
    aplicar_beneficio(usuario);
}
```
<!-- {code-block} c -->

**Beneficios:**
- Condiciones autodocumentadas
- Reutilizables
- Más fáciles de testear individualmente

Dar nombre a cada subexpresión es la técnica que responde a {ref}`0x1004h` y,
de paso, deja explícita la agrupación que reclama {ref}`0x1013h`.

### 3. Extracción de Condiciones a Funciones

Para lógica compleja o reutilizable:

**Antes:**

```{code-block} c
:linenos:
void procesar_descuento(cliente_t *cliente, double total)
{
    if ((cliente->compras_totales > 10000 && cliente->antiguedad > 365) ||
        (cliente->referidos >= 5) || (cliente->tipo == VIP && cliente->activo))
    {
        aplicar_descuento_premium(total);
    }
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
bool es_cliente_fiel(const cliente_t *cliente)
{
    return cliente->compras_totales > 10000 && cliente->antiguedad > 365;
}
bool es_buen_referidor(const cliente_t *cliente)
{
    return cliente->referidos >= 5;
}
bool es_vip_activo(const cliente_t *cliente)
{
    return cliente->tipo == VIP && cliente->activo;
}
bool califica_para_descuento_premium(const cliente_t *cliente)
{
    return es_cliente_fiel(cliente) || es_buen_referidor(cliente) ||
           es_vip_activo(cliente);
}
void procesar_descuento(cliente_t *cliente, double total)
{
    if (califica_para_descuento_premium(cliente))
    {
        aplicar_descuento_premium(total);
    }
}
```
<!-- {code-block} c -->

**Beneficios:**
- Nombres descriptivos documentan la lógica de negocio
- Funciones testeables independientemente
- Reutilizables en otros contextos
- Fácil modificar criterios de elegibilidad

Cada predicado encapsula una porción de la condición original, que es la forma
más robusta de cumplir {ref}`0x1004h`: en lugar de comentar una expresión
enredada, la partimos en funciones cuyo nombre ya documenta la intención.

### 4. Simplificación de Booleanos

**Antes:**

```{code-block} c
:linenos:
bool es_valido(int valor)
{
    if (valor > 0 && valor < 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Comparación redundante
if (esta_activo() == true)
{
    // ...
}
if (contador > 0 == false)
{
    // ...
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
bool es_valido(int valor)
{
    return valor > 0 && valor < 100;
}
// Uso directo del booleano
if (esta_activo())
{
    // ...
}
if (!esta_activo())
{
    // ...
}
if (contador == 0)
{
    // ...
}
```
<!-- {code-block} c -->

El uso directo del booleano elimina la dependencia de la veracidad implícita
({ref}`0x1005h`) y las comparaciones redundantes contra `true`/`false`. El rango
`valor > 0 && valor < 100` se escribe con `&&` explícito, nunca como
`0 < valor < 100`, tal como exige {ref}`0x1010h`. Y cuando la condición original
está negada, conviene afirmarla o aislarla en una variable con nombre positivo,
según {ref}`0x1017h`.

### 5. Reemplazo de Condicionales con Polimorfismo (simulado en C)

Para casos donde múltiples `if-else` determinan comportamiento:

**Antes:**

```{code-block} c
:linenos:
double calcular_area(figura_t *figura)
{
    if (figura->tipo == CIRCULO)
    {
        return PI * figura->datos.circulo.radio * figura->datos.circulo.radio;
    }
    else if (figura->tipo == RECTANGULO)
    {
        return figura->datos.rectangulo.ancho * figura->datos.rectangulo.alto;
    }
    else if (figura->tipo == TRIANGULO)
    {
        return 0.5 * figura->datos.triangulo.base *
               figura->datos.triangulo.altura;
    }
    return 0;
}
```
<!-- {code-block} c -->

**Después (con punteros a función):**

```{code-block} c
:linenos:
typedef double (*calcular_area_fn)(const void *datos);
typedef struct
{
    int tipo;
    calcular_area_fn calcular_area;
    void *datos;
} figura_t;
double calcular_area_circulo(const void *datos)
{
    const circulo_t *c = (const circulo_t *)datos;
    return PI * c->radio * c->radio;
}
double calcular_area_rectangulo(const void *datos)
{
    const rectangulo_t *r = (const rectangulo_t *)datos;
    return r->ancho * r->alto;
}
double calcular_area_triangulo(const void *datos)
{
    const triangulo_t *t = (const triangulo_t *)datos;
    return 0.5 * t->base * t->altura;
}
double calcular_area(const figura_t *figura)
{
    return figura->calcular_area(figura->datos);
}
```
<!-- {code-block} c -->

### 6. Tabla de Decisión

Para lógica compleja con múltiples combinaciones:

**Antes:**

```{code-block} c
:linenos:
char *obtener_categoria(int edad, bool estudiante, bool empleado)
{
    if (edad < 18 && estudiante)
    {
        return "ESTUDIANTE_MENOR";
    }
    else if (edad < 18 && !estudiante)
    {
        return "MENOR";
    }
    else if (edad >= 18 && edad < 65 && estudiante)
    {
        return "ESTUDIANTE_ADULTO";
    }
    else if (edad >= 18 && edad < 65 && empleado)
    {
        return "EMPLEADO";
    }
    else if (edad >= 18 && edad < 65)
    {
        return "ADULTO";
    }
    else if (edad >= 65 && empleado)
    {
        return "JUBILADO_ACTIVO";
    }
    else
    {
        return "JUBILADO";
    }
}
```
<!-- {code-block} c -->

**Después (con tabla):**

```{code-block} c
:linenos:
typedef struct
{
    bool (*condicion)(int edad, bool estudiante, bool empleado);
    const char *categoria;
} regla_categoria_t;
bool es_estudiante_menor(int edad, bool estudiante, bool empleado)
{
    return edad < 18 && estudiante;
}
bool es_menor(int edad, bool estudiante, bool empleado)
{
    return edad < 18 && !estudiante;
}
bool es_estudiante_adulto(int edad, bool estudiante, bool empleado)
{
    return edad >= 18 && edad < 65 && estudiante;
}
bool es_empleado(int edad, bool estudiante, bool empleado)
{
    return edad >= 18 && edad < 65 && empleado;
}
bool es_adulto(int edad, bool estudiante, bool empleado)
{
    return edad >= 18 && edad < 65 && !estudiante && !empleado;
}
bool es_jubilado_activo(int edad, bool estudiante, bool empleado)
{
    return edad >= 65 && empleado;
}
bool es_jubilado(int edad, bool estudiante, bool empleado)
{
    return edad >= 65 && !empleado;
}
const regla_categoria_t REGLAS_CATEGORIA[] = {
    {es_estudiante_menor, "ESTUDIANTE_MENOR"},
    {es_menor, "MENOR"},
    {es_estudiante_adulto, "ESTUDIANTE_ADULTO"},
    {es_empleado, "EMPLEADO"},
    {es_adulto, "ADULTO"},
    {es_jubilado_activo, "JUBILADO_ACTIVO"},
    {es_jubilado, "JUBILADO"}};
const int NUM_REGLAS = sizeof(REGLAS_CATEGORIA) / sizeof(REGLAS_CATEGORIA[0]);
const char *obtener_categoria(int edad, bool estudiante, bool empleado)
{
    for (int i = 0; i < NUM_REGLAS; i++)
    {
        if (REGLAS_CATEGORIA[i].condicion(edad, estudiante, empleado))
        {
            return REGLAS_CATEGORIA[i].categoria;
        }
    }
    return "DESCONOCIDO";
}
```
<!-- {code-block} c -->

### 7. Uso de `switch` en lugar de `if-else` en cadena

Para comparaciones de igualdad con un valor:

**Antes:**

```{code-block} c
:linenos:
void procesar_comando(char comando)
{
    if (comando == 'A')
    {
        avanzar();
    }
    else if (comando == 'R')
    {
        retroceder();
    }
    else if (comando == 'I')
    {
        girar_izquierda();
    }
    else if (comando == 'D')
    {
        girar_derecha();
    }
    else if (comando == 'P')
    {
        parar();
    }
    else
    {
        printf("Comando inválido\n");
    }
}
```
<!-- {code-block} c -->

**Después:**

```{code-block} c
:linenos:
void procesar_comando(char comando)
{
    switch (comando)
    {
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
<!-- {code-block} c -->

## Casos Prácticos Completos

### Caso 1: Validación de Formulario

**Código Original:**

```{code-block} c
:linenos:
bool validar_formulario(const char *nombre, const char *email,
                        const char *telefono, int edad)
{
    if (nombre != NULL)
    {
        if (strlen(nombre) >= 3)
        {
            if (email != NULL)
            {
                if (strchr(email, '@') != NULL)
                {
                    if (strlen(email) >= 5)
                    {
                        if (telefono != NULL)
                        {
                            if (strlen(telefono) >= 8)
                            {
                                if (edad >= 18)
                                {
                                    if (edad <= 120)
                                    {
                                        return true;
                                    }
                                    else
                                    {
                                        printf("Edad muy alta\n");
                                    }
                                }
                                else
                                {
                                    printf("Debe ser mayor de edad\n");
                                }
                            }
                            else
                            {
                                printf("Teléfono muy corto\n");
                            }
                        }
                        else
                        {
                            printf("Teléfono nulo\n");
                        }
                    }
                    else
                    {
                        printf("Email muy corto\n");
                    }
                }
                else
                {
                    printf("Email sin @\n");
                }
            }
            else
            {
                printf("Email nulo\n");
            }
        }
        else
        {
            printf("Nombre muy corto\n");
        }
    }
    else
    {
        printf("Nombre nulo\n");
    }
    return false;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
bool validar_nombre(const char *nombre)
{
    if (nombre == NULL)
    {
        printf("Nombre nulo\n");
        return false;
    }
    if (strlen(nombre) < 3)
    {
        printf("Nombre muy corto\n");
        return false;
    }
    return true;
}
bool validar_email(const char *email)
{
    if (email == NULL)
    {
        printf("Email nulo\n");
        return false;
    }
    if (strlen(email) < 5)
    {
        printf("Email muy corto\n");
        return false;
    }
    if (strchr(email, '@') == NULL)
    {
        printf("Email sin @\n");
        return false;
    }
    return true;
}
bool validar_telefono(const char *telefono)
{
    if (telefono == NULL)
    {
        printf("Teléfono nulo\n");
        return false;
    }
    if (strlen(telefono) < 8)
    {
        printf("Teléfono muy corto\n");
        return false;
    }
    return true;
}
bool validar_edad(int edad)
{
    if (edad < 18)
    {
        printf("Debe ser mayor de edad\n");
        return false;
    }
    if (edad > 120)
    {
        printf("Edad muy alta\n");
        return false;
    }
    return true;
}
bool validar_formulario(const char *nombre, const char *email,
                        const char *telefono, int edad)
{
    return validar_nombre(nombre) && validar_email(email) &&
           validar_telefono(telefono) && validar_edad(edad);
}
```
<!-- {code-block} c -->

### Caso 2: Cálculo de Descuento Complejo

**Código Original:**

```{code-block} c
:linenos:
double calcular_descuento(double monto, int cantidad, bool es_miembro,
                          bool es_primera_compra, const char *codigo_promo)
{
    double descuento = 0;
    if (cantidad > 10 && monto > 1000)
    {
        if (es_miembro)
        {
            if (strcmp(codigo_promo, "VERANO") == 0)
            {
                descuento = 0.30;
            }
            else if (strcmp(codigo_promo, "FLASH") == 0)
            {
                if (cantidad > 20)
                {
                    descuento = 0.35;
                }
                else
                {
                    descuento = 0.25;
                }
            }
            else
            {
                descuento = 0.20;
            }
        }
        else
        {
            if (es_primera_compra)
            {
                descuento = 0.15;
            }
            else
            {
                descuento = 0.10;
            }
        }
    }
    else if (cantidad > 5 || monto > 500)
    {
        if (es_miembro)
        {
            descuento = 0.15;
        }
        else
        {
            descuento = 0.05;
        }
    }
    else
    {
        if (es_primera_compra)
        {
            descuento = 0.10;
        }
    }
    return descuento;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
bool es_compra_grande(double monto, int cantidad)
{
    return cantidad > 10 && monto > 1000;
}
bool es_compra_mediana(double monto, int cantidad)
{
    return cantidad > 5 || monto > 500;
}
double descuento_miembro_compra_grande(int cantidad, const char *codigo_promo)
{
    if (strcmp(codigo_promo, "VERANO") == 0)
    {
        return 0.30;
    }
    if (strcmp(codigo_promo, "FLASH") == 0)
    {
        return cantidad > 20 ? 0.35 : 0.25;
    }
    return 0.20;
}
double descuento_no_miembro_compra_grande(bool es_primera_compra)
{
    return es_primera_compra ? 0.15 : 0.10;
}
double calcular_descuento(double monto, int cantidad, bool es_miembro,
                          bool es_primera_compra, const char *codigo_promo)
{
    if (es_compra_grande(monto, cantidad))
    {
        if (es_miembro)
        {
            return descuento_miembro_compra_grande(cantidad, codigo_promo);
        }
        else
        {
            return descuento_no_miembro_compra_grande(es_primera_compra);
        }
    }
    if (es_compra_mediana(monto, cantidad))
    {
        return es_miembro ? 0.15 : 0.05;
    }
    return es_primera_compra ? 0.10 : 0.0;
}
```
<!-- {code-block} c -->

## Leyes de De Morgan

Útiles para simplificar expresiones booleanas complejas:

**Leyes:**
- `!(A && B)` ≡ `!A || !B`
- `!(A || B)` ≡ `!A && !B`

**Ejemplo:**

```{code-block} c
:linenos:
// Antes
if (!(activo && validado))
{
    return;
}
// Después (más claro en contexto de guardia)
if (!activo || !validado)
{
    return;
}
```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// Antes
if (!(edad < 18 || edad > 65))
{
    aplicar_tarifa_regular();
}
// Después (más claro)
if (edad >= 18 && edad <= 65)
{
    aplicar_tarifa_regular();
}
```
<!-- {code-block} c -->

Negar una disyunción y reescribirla como conjunción afirmativa es una
aplicación directa de {ref}`0x1017h`: la condición queda en forma positiva y
directa. Además, el rango se expresa como `edad >= 18 && edad <= 65` con `&&`
explícito, nunca como `18 <= edad <= 65`, tal como prohíbe {ref}`0x1010h`.

## Ejemplo Integrador: Varias Reglas en una Sola Función

Hasta acá vimos las técnicas por separado. En el código real suelen aparecer
varias violaciones a la vez, y la refactorización consiste en aplicarlas todas
sobre la misma función. El siguiente ejemplo reúne la mayoría de las reglas de
la tabla inicial.

**Antes (❌):**

```c
int procesar_envio(pedido_t *pedido)
{
    if (pedido != NULL)
    {
        if (pedido->items > 0)
        {
            if (pedido->peso < 50)
            {
                if (pedido->cliente != NULL)
                {
                    int zona;
                    if ((zona = calcular_zona(pedido)) == ZONA_NACIONAL)
                    {
                        if (pedido->prioridad && 0 < pedido->distancia < 1000 || pedido->cliente->vip)
                        {
                            return ENVIO_EXPRESS;
                        }
                        else
                        {
                            return ENVIO_ESTANDAR;
                        }
                    }
                    else
                    {
                        return ENVIO_INTERNACIONAL;
                    }
                }
                else
                {
                    return SIN_CLIENTE;
                }
            }
            else
            {
                return PESO_EXCEDIDO;
            }
        }
        else
        {
            return SIN_ITEMS;
        }
    }
    else
    {
        return PEDIDO_NULO;
    }
}
```

Este código viola, al mismo tiempo:

- {ref}`0x1015h`: hay cuatro niveles de anidación; el camino feliz queda
  sepultado.
- {ref}`0x2001h`: no hay validación temprana de precondiciones; cada error
  aparece al final de una pirámide.
- {ref}`0x1012h` y {ref}`0x1009h`: la asignación `zona = calcular_zona(pedido)`
  está embebida en la condición del `if`.
- {ref}`0x100Bh`: la comparación `0 < pedido->distancia` invierte el orden y
  deja la constante a la izquierda.
- {ref}`0x1010h`: `0 < pedido->distancia < 1000` es una comparación encadenada
  que en C no significa lo que parece.
- {ref}`0x1005h`: `pedido->prioridad` depende de la veracidad implícita del
  campo en lugar de comparar contra `true`/`false`.
- {ref}`0x1004h`: la condición combina demasiadas subexpresiones en una sola
  línea, sin nombrar ninguna.
- {ref}`0x1013h`: dentro de esa misma condición conviven `&&` y `||` sin
  paréntesis que expliciten la agrupación deseada, que queda librada a la
  precedencia.
- {ref}`0x100Fh` y {ref}`0x2013h`: cada rama que termina en `return` arrastra un
  `else` perfectamente evitable.

**Después (✅):**

```c
bool es_envio_nacional(int zona)
{
    return zona == ZONA_NACIONAL;
}

bool es_envio_corto(const pedido_t *pedido)
{
    return pedido->distancia > 0 && pedido->distancia < 1000;
}

int procesar_envio(const pedido_t *pedido)
{
    // Guardas: el camino de error sale primero (0x2001h, 0x1015h)
    if (pedido == NULL)
    {
        return PEDIDO_NULO;
    }
    if (pedido->items == 0)
    {
        return SIN_ITEMS;
    }
    if (pedido->peso >= 50)
    {
        return PESO_EXCEDIDO;
    }
    if (pedido->cliente == NULL)
    {
        return SIN_CLIENTE;
    }

    // La asignación va en su propia sentencia (0x1012h, 0x1009h)
    int zona = calcular_zona(pedido);

    // Variable a la izquierda, condición afirmativa (0x100Bh, 0x1017h)
    if (!es_envio_nacional(zona))
    {
        return ENVIO_INTERNACIONAL;
    }

    // Rango explícito con && y comparación de bool directa (0x1010h, 0x1005h)
    if (pedido->prioridad == true &&
        (es_envio_corto(pedido) || pedido->cliente->vip))
    {
        return ENVIO_EXPRESS;
    }
    return ENVIO_ESTANDAR;
}
```

Después de la refactorización no queda ningún `else` tras un `return`, no hay
más de dos niveles de anidación, y cada subexpresión tiene nombre o comparación
explícita. La lógica que antes dependía de la precedencia y del orden de
evaluación ahora se lee tal cual se ejecuta; lo que cambió es cuánto esfuerzo
cuesta leerla y auditarla.

(ref-unico-retorno)=
## Combinación con el Patrón de Único Retorno

Cuando se aplica el patrón de único retorno (ver {ref}`ref-unico-retorno`), las
técnicas de simplificación de condicionales deben adaptarse para mantener un
solo punto de salida.

### Guardia de Cláusulas con Único Retorno

**Guard Clauses tradicionales (múltiples returns):**

```{code-block} c
:linenos:
int procesar_pago(usuario_t *usuario, double monto)
{
    if (usuario == NULL)
    {
        return ERROR_USUARIO_NULL;
    }
    if (!usuario->activo)
    {
        return ERROR_USUARIO_INACTIVO;
    }
    if (usuario->saldo < monto)
    {
        return ERROR_SALDO_INSUFICIENTE;
    }
    // Procesar pago
    usuario->saldo -= monto;
    return EXITO;
}
```
<!-- {code-block} c -->

**Adaptado a único retorno:**

```{code-block} c
:linenos:
int procesar_pago(usuario_t *usuario, double monto)
{
    int resultado = ERROR_DESCONOCIDO;
    if (usuario == NULL)
    {
        resultado = ERROR_USUARIO_NULL;
    }
    else if (!usuario->activo)
    {
        resultado = ERROR_USUARIO_INACTIVO;
    }
    else if (usuario->saldo < monto)
    {
        resultado = ERROR_SALDO_INSUFICIENTE;
    }
    else
    {
        // Procesar pago
        usuario->saldo -= monto;
        resultado = EXITO;
    }
    return resultado;
}
```
<!-- {code-block} c -->

### Variables de Estado para Control de Flujo

Cuando se combina único retorno con condicionales complejos, usar variables de
estado explícitas mejora la claridad.

**Antes (múltiples returns):**

```{code-block} c
:linenos:
bool validar_transaccion(transaccion_t *trans)
{
    if (trans->monto <= 0)
    {
        return false;
    }
    if (trans->origen == NULL || trans->destino == NULL)
    {
        return false;
    }
    if (trans->origen->saldo < trans->monto)
    {
        return false;
    }
    if (trans->origen->bloqueada || trans->destino->bloqueada)
    {
        return false;
    }
    return true;
}
```
<!-- {code-block} c -->

**Después (único retorno con variable de estado):**

```{code-block} c
:linenos:
bool validar_transaccion(const transaccion_t *trans)
{
    bool es_valida = true;
    if (trans->monto <= 0)
    {
        es_valida = false;
    }
    else if (trans->origen == NULL || trans->destino == NULL)
    {
        es_valida = false;
    }
    else if (trans->origen->saldo < trans->monto)
    {
        es_valida = false;
    }
    else if (trans->origen->bloqueada || trans->destino->bloqueada)
    {
        es_valida = false;
    }
    return es_valida;
}
```
<!-- {code-block} c -->

### Combinando Predicados y Único Retorno

**Con múltiples returns:**

```{code-block} c
:linenos:
bool puede_realizar_compra(const usuario_t *u, double monto)
{
    if (!es_usuario_valido(u))
        return false;
    if (!tiene_saldo_suficiente(u, monto))
        return false;
    if (!esta_dentro_limite_diario(u, monto))
        return false;
    return true;
}
```
<!-- {code-block} c -->

**Con único retorno:**

```{code-block} c
:linenos:
bool puede_realizar_compra(const usuario_t *u, double monto)
{
    bool puede = false;
    if (es_usuario_valido(u) && tiene_saldo_suficiente(u, monto) &&
        esta_dentro_limite_diario(u, monto))
    {
        puede = true;
    }
    return puede;
}
```
<!-- {code-block} c -->

**O de manera más concisa:**

``` c
bool puede_realizar_compra(const usuario_t *u, double monto)
{
    return es_usuario_valido(u) && tiene_saldo_suficiente(u, monto) &&
           esta_dentro_limite_diario(u, monto);
}
```
<!-- c -->

### Caso Práctico: Autenticación con Único Retorno

**Antes (múltiples returns):**

```{code-block} c
:linenos:
int autenticar(const char *usuario, const char *password)
{
    if (usuario == NULL || password == NULL)
    {
        return AUTH_ERROR_PARAMETROS;
    }
    usuario_t *u = buscar_usuario(usuario);
    if (u == NULL)
    {
        return AUTH_ERROR_USUARIO_NO_EXISTE;
    }
    if (u->intentos_fallidos >= MAX_INTENTOS)
    {
        return AUTH_ERROR_BLOQUEADO;
    }
    if (!verificar_password(u, password))
    {
        u->intentos_fallidos++;
        return AUTH_ERROR_PASSWORD_INCORRECTO;
    }
    u->intentos_fallidos = 0;
    u->ultimo_acceso = time(NULL);
    return AUTH_EXITO;
}
```
<!-- {code-block} c -->

**Después (único retorno con flujo claro):**

```{code-block} c
:linenos:
int autenticar(const char *usuario, const char *password)
{
    int resultado = AUTH_ERROR_DESCONOCIDO;
    usuario_t *u = NULL;
    // Validación de parámetros
    if (usuario == NULL || password == NULL)
    {
        resultado = AUTH_ERROR_PARAMETROS;
    }
    else
    {
        u = buscar_usuario(usuario);
        if (u == NULL)
        {
            resultado = AUTH_ERROR_USUARIO_NO_EXISTE;
        }
        else if (u->intentos_fallidos >= MAX_INTENTOS)
        {
            resultado = AUTH_ERROR_BLOQUEADO;
        }
        else if (!verificar_password(u, password))
        {
            u->intentos_fallidos++;
            resultado = AUTH_ERROR_PASSWORD_INCORRECTO;
        }
        else
        {
            // Autenticación exitosa
            u->intentos_fallidos = 0;
            u->ultimo_acceso = time(NULL);
            resultado = AUTH_EXITO;
        }
    }
    return resultado;
}
```
<!-- {code-block} c -->

### Manejo de Recursos con Único Retorno

El patrón de único retorno es especialmente útil cuando se manejan recursos que
deben liberarse.

**Antes (múltiples returns, riesgo de fugas):**

```{code-block} c
:linenos:
char *leer_archivo(const char *ruta)
{
    FILE *f = fopen(ruta, "r");
    if (f == NULL)
    {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long tam = ftell(f);
    if (tam < 0)
    {
        fclose(f); // Fácil olvidar esto
        return NULL;
    }
    char *buffer = malloc(tam + 1);
    if (buffer == NULL)
    {
        fclose(f); // Y esto
        return NULL;
    }
    fseek(f, 0, SEEK_SET);
    size_t leidos = fread(buffer, 1, tam, f);
    if (leidos != tam)
    {
        free(buffer); // Y esto
        fclose(f);    // Y esto
        return NULL;
    }
    buffer[tam] = '\0';
    fclose(f);
    return buffer;
}
```
<!-- {code-block} c -->

**Después (único retorno, liberación garantizada):**

```{code-block} c
:linenos:
char *leer_archivo(const char *ruta)
{
    char *resultado = NULL;
    FILE *f = NULL;
    char *buffer = NULL;
    f = fopen(ruta, "r");
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        long tam = ftell(f);
        if (tam >= 0)
        {
            buffer = malloc(tam + 1);
            if (buffer != NULL)
            {
                fseek(f, 0, SEEK_SET);
                size_t leidos = fread(buffer, 1, tam, f);
                if (leidos == tam)
                {
                    buffer[tam] = '\0';
                    resultado = buffer;
                    buffer = NULL; // No liberar si exitoso
                }
            }
        }
    }
    // Limpieza centralizada
    if (buffer != NULL)
    {
        free(buffer);
    }
    if (f != NULL)
    {
        fclose(f);
    }
    return resultado;
}
```
<!-- {code-block} c -->

### Variables de Control para Lazos

El patrón de único retorno se combina bien con variables de control en lazos.

**Antes (con break/return):**

```{code-block} c
:linenos:
int buscar_elemento(const int *arr, int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == valor)
        {
            return i; // Retorno temprano
        }
    }
    return -1;
}
```
<!-- {code-block} c -->

**Después (único retorno):**

```{code-block} c
:linenos:
int buscar_elemento(const int *arr, int n, int valor)
{
    int indice = -1;
    for (int i = 0; i < n && indice == -1; i++)
    {
        if (arr[i] == valor)
        {
            indice = i;
        }
    }
    return indice;
}
```
<!-- {code-block} c -->

### Balance entre Claridad y Único Retorno

:::{tip} Pragmatismo

En funciones muy simples, los múltiples returns pueden ser más claros. El patrón
de único retorno es más valioso en:
- Funciones que manejan recursos
- Funciones con lógica compleja
- Código que requiere depuración frecuente
- Proyectos con estándares estrictos

:::
<!-- {tip} Pragmatismo -->

**Funciones simples - múltiples returns aceptables:**

```{code-block} c
:linenos:
bool es_par(int n)
{
    return n % 2 == 0;
}
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}
```
<!-- {code-block} c -->

**Funciones complejas - único retorno preferible:**

```{code-block} c
:linenos:
int procesar_pedido_complejo(pedido_t *pedido, contexto_t *ctx)
{
    int resultado = ERROR_DESCONOCIDO;
    recurso_t *recurso = NULL;
    // Múltiples validaciones y manejo de recursos
    if (validar_pedido(pedido))
    {
        recurso = adquirir_recurso(ctx);
        if (recurso != NULL)
        {
            if (procesar_con_recurso(pedido, recurso))
            {
                resultado = EXITO;
            }
            else
            {
                resultado = ERROR_PROCESAMIENTO;
            }
        }
        else
        {
            resultado = ERROR_RECURSO;
        }
    }
    else
    {
        resultado = ERROR_VALIDACION;
    }
    // Limpieza garantizada
    if (recurso != NULL)
    {
        liberar_recurso(recurso);
    }
    return resultado;
}
```
<!-- {code-block} c -->

## Diagnóstico y refactorización

Para auditar código existente, conviene recorrer los síntomas de izquierda a
derecha y aplicar la técnica correspondiente. La siguiente tabla funciona como
guía rápida de diagnóstico.

| Regla | Síntoma en el código | Técnica de esta guía |
| --- | --- | --- |
| {ref}`0x1004h` | Condición larga con varios `&&` y `||` sin partir | Extracción de condiciones a variables booleanas y funciones predicado |
| {ref}`0x1013h` | Mezcla de `&&` y `||` sin paréntesis que marquen la agrupación | Paréntesis aclaratorios en cada combinación lógica |
| {ref}`0x1005h` | `if (puntero)`, `if (entero)` o `if (es_valido() == true)` | Comparación explícita contra `NULL`, `0` o `true`/`false` |
| {ref}`0x100Bh` | `if (NULL == puntero)`, `while (0 == i)` | Reordenar a `variable == CONSTANTE` |
| {ref}`0x1012h` | `if ((x = f()) != 0)` | Extraer la asignación a una sentencia propia |
| {ref}`0x1009h` | `while (c = getchar())` con `=` simple | Separar asignación y comparar con `==` en la condición |
| {ref}`0x1010h` | `0 <= x <= 10`, `a < b < c` | Reescribir como `a < b && b < c` |
| {ref}`0x1017h` | `if (!(activo && validado))` | Forma afirmativa o variable con nombre positivo |
| {ref}`0x1015h` | Pirámide de `if` con más de tres niveles | Guard clauses, inversión de condición y extracción de función |
| {ref}`0x2001h` | Validaciones al final del camino feliz | Cláusulas de guarda al inicio con retornos anticipados |
| {ref}`0x100Fh` | `else` después de una rama que retorna | Desanidar la rama alterna al nivel del `if` |
| {ref}`0x2013h` | `else` tras `return`, `break`, `continue` o `goto` | Eliminar el `else` y continuar el flujo |

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

La claridad en los condicionales es esencial para código mantenible y libre de
bugs.

## Checklist de verificación

Antes de dar por cerrada una refactorización de condicionales, verificá:

- [ ] Ninguna condición mezcla `&&` y `||` sin paréntesis aclaratorios
  ({ref}`0x1013h`).
- [ ] Toda condición compleja está partida en variables o funciones con nombre
  ({ref}`0x1004h`).
- [ ] Las comparaciones usan el tipo explícito (`NULL`, `0`, `'\0'`,
  `true`/`false`) y no la veracidad implícita ({ref}`0x1005h`).
- [ ] La variable o expresión está a la izquierda y la constante a la derecha,
  sin estilo Yoda ({ref}`0x100Bh`).
- [ ] No queda ninguna asignación embebida en un `if`, `while` o `for`
  ({ref}`0x1012h`, {ref}`0x1009h`).
- [ ] No hay comparaciones encadenadas del tipo `a < b < c`
  ({ref}`0x1010h`).
- [ ] Las condiciones se leen en forma afirmativa y directa ({ref}`0x1017h`).
- [ ] La anidación no supera los tres niveles ({ref}`0x1015h`).
- [ ] Las precondiciones se validan con guard clauses y retornos anticipados
  ({ref}`0x2001h`).
- [ ] No queda ningún `else` redundante después de una sentencia terminal
  ({ref}`0x100Fh`, {ref}`0x2013h`).
