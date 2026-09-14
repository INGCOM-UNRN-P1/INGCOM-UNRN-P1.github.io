---
title: "Eliminación de Números Mágicos"
short_title: "Números mágicos"
subtitle: "Convertir literales en constantes con nombre significativo"
---

(refactorizacion-magic-numbers)=

## Introducción

Un **número mágico** (magic number) es un valor literal numérico que aparece
directamente en el código sin explicación de su significado o propósito. Estos
valores dificultan la comprensión del código, su mantenimiento y aumentan la
probabilidad de errores cuando se necesita modificar el valor en múltiples
lugares.

La refactorización para eliminar números mágicos consiste en reemplazarlos por
constantes con nombres descriptivos que expresen claramente su propósito y
significado en el contexto del programa. Es, en esencia, la aplicación directa
de {ref}`0x0112h`.

:::{important} Principio de Autodocumentación

Como establece {ref}`0x0101h`, los identificadores deben ser descriptivos. Las
constantes con nombre no solo evitan errores, sino que también documentan el
código, haciendo explícito el significado de cada valor.

:::
<!-- {important} Principio de Autodocumentación -->

## Reglas de estilo que resuelve

Esta refactorización no es una técnica aislada: resuelve de forma directa varios
problemas que la cátedra modela como reglas de estilo. Cada regla captura un
síntoma distinto del mismo vicio de fondo —dejar valores literales sueltos en el
código— y esta guía ofrece la técnica concreta para eliminarlo. La tabla
siguiente mapea cada regla con el problema que modela y con la forma en que la
refactorización lo resuelve.

| Regla | Problema que modela | Cómo lo resuelve esta refactorización |
| :--- | :--- | :--- |
| {ref}`0x0112h` | Todo literal con significado queda suelto en la expresión y obliga a inferir su propósito del contexto. | Reemplaza cada literal por una constante simbólica (`const`, `#define` o `enum`) con nombre de dominio. |
| {ref}`0x010Fh` | Los índices fijos de arreglo escritos como literales (por ejemplo `vec[7]`) esconden qué campo representan y se desalinean si cambia la estructura. | Nombra cada posición con una constante simbólica o de `enum`, de modo que el índice también se autodocumente. |
| {ref}`0x0103h` | Una constante `const` en minúsculas o `camelCase` se confunde con una variable mutable. | Declara las constantes `const` en `MAYUSCULAS_SNAKE_CASE` como parte del propio reemplazo del literal. |
| {ref}`0x0107h` | Una macro escrita en minúsculas parece una función o variable y oculta su expansión textual. | Nombra las macros de `#define` en `MAYUSCULAS_SNAKE_CASE` al extraer un literal. |
| {ref}`0x300Dh` | Conjuntos de estados o valores relacionados aparecen como literales dispersos (`estado == 2`) que se confunden entre sí. | Agrupa esos valores en un `enum` con nombres de dominio que comparten semántica. |
| {ref}`0x2007h` | Valores de retorno y códigos de error numéricos (`return -1`) no comunican su causa al lector. | Define los valores de retorno como constantes simbólicas o `enum` al extraer el literal. |
| {ref}`0x5001h` | Un arreglo dimensionado con un valor calculado en runtime (VLA) puede desbordar la pila o no compilar. | Extrae el tamaño a una constante de tiempo de compilación (`#define`, `enum` o literal) y dimensiónalo con ella. |

## ¿Por Qué Son Problemáticos los Números Mágicos?

### 1. Falta de Claridad

**Código con números mágicos:**

``` c
if (edad >= 18 && edad < 65)
{
    aplicar_descuento(precio * 0.85);
}
```
<!-- c -->

**Preguntas que surgen:**
- ¿Por qué 18? ¿Mayoría de edad? ¿Edad mínima para conducir?
- ¿Por qué 65? ¿Jubilación? ¿Algún límite legal?
- ¿Qué significa 0.85? ¿15% de descuento? ¿85% del precio?

### 2. Mantenimiento Difícil

Si el descuento cambia de 15% a 20%, debés:
- Buscar todas las ocurrencias de `0.85`
- Determinar cuáles corresponden a este descuento específico
- Cambiar `0.85` por `0.80`
- Esperar no haber modificado un `0.85` que significaba otra cosa

### 3. Propensión a Errores

```{code-block} c
:linenos:
// Archivo 1
if (intentos >= 3)
{
    bloquear_cuenta();
}
// Archivo 2
if (intentos > 3)
{ // ¿Error? ¿Inconsistencia?
    notificar_administrador();
}
```
<!-- {code-block} c -->

¿El límite es 3 o 4? La inconsistencia genera bugs sutiles.

### 4. Duplicación Oculta

``` c
char buffer[256];
char nombre[256];
char direccion[256];
```
<!-- c -->

Si `256` se repite porque representa el mismo concepto (por ejemplo, longitud
máxima de entrada), debería ser una constante compartida.

## Tipos de Números Mágicos

### 1. Literales Numéricos

Los más comunes y evidentes. Esta es la forma canónica que ataca {ref}`0x0112h`:

```{code-block} c
:linenos:
// Malo
if (temperatura > 100)
{
    activar_alarma();
}
// Bueno
const int TEMPERATURA_EBULLICION_AGUA = 100;
if (temperatura > TEMPERATURA_EBULLICION_AGUA)
{
    activar_alarma();
}
```
<!-- {code-block} c -->

### 2. Factores de Conversión

Los factores son literales con significado: también les aplica {ref}`0x0112h`.

```{code-block} c
:linenos:
// Malo
double metros = pies * 0.3048;
double kilogramos = libras * 0.453592;
// Bueno
const double METROS_POR_PIE = 0.3048;
const double KG_POR_LIBRA = 0.453592;
double metros = pies * METROS_POR_PIE;
double kilogramos = libras * KG_POR_LIBRA;
```
<!-- {code-block} c -->

### 3. Tamaños de Buffer

El tamaño de un arreglo debe ser una constante de tiempo de compilación, tal
como exige {ref}`0x5001h`; cuando se extrae con `#define`, además rige
{ref}`0x0107h` para nombrarla en `MAYUSCULAS_SNAKE_CASE`.

```{code-block} c
:linenos:
// Malo
char nombre[50];
char apellido[50];
fgets(nombre, 50, stdin);
// Bueno
#define MAX_NOMBRE 50
char nombre[MAX_NOMBRE];
char apellido[MAX_NOMBRE];
fgets(nombre, MAX_NOMBRE, stdin);
```
<!-- {code-block} c -->

### 4. Códigos de Estado o Error

Los conjuntos de estados relacionados piden un `enum` según {ref}`0x300Dh`, y
los valores de retorno con significado propio deben nombrarse como indica
{ref}`0x2007h`.

```{code-block} c
:linenos:
// Malo
if (resultado == -1)
{
    printf("Error\n");
}
else if (resultado == 0)
{
    printf("OK\n");
}
else if (resultado == 1)
{
    printf("Advertencia\n");
}
// Bueno
enum estado_resultado
{
    RESULTADO_ERROR = -1,
    RESULTADO_EXITO = 0,
    RESULTADO_ADVERTENCIA = 1
};
if (resultado == RESULTADO_ERROR)
{
    printf("Error\n");
}
else if (resultado == RESULTADO_EXITO)
{
    printf("OK\n");
}
else if (resultado == RESULTADO_ADVERTENCIA)
{
    printf("Advertencia\n");
}
```
<!-- {code-block} c -->

### 5. Límites y Umbrales

```{code-block} c
:linenos:
// Malo
if (calificacion >= 60)
{
    printf("Aprobado\n");
}
// Bueno
const int CALIFICACION_MINIMA_APROBACION = 60;
if (calificacion >= CALIFICACION_MINIMA_APROBACION)
{
    printf("Aprobado\n");
}
```
<!-- {code-block} c -->

## Técnicas de Refactorización

### Método 1: Constantes con `const`

Al usar `const`, el nombre resultante debe ir en `MAYUSCULAS_SNAKE_CASE`, como
manda {ref}`0x0103h`.

**Ventajas:**
- Type-safe (tiene tipo específico)
- Scope controlado (puede ser local, global, o estática)
- Compatible con debuggers modernos

``` c
const int INTENTOS_MAXIMOS = 3;
const double PI = 3.14159265358979323846;
const char *MENSAJE_BIENVENIDA = "Hola, usuario";
```
<!-- c -->

**Scope local:**

```{code-block} c
:linenos:
void procesar_pedido(double precio)
{
    const double IMPUESTO = 0.21; // IVA en Argentina
    const double DESCUENTO_MAYORISTA = 0.15;
    double total = precio * (1 + IMPUESTO);
    if (es_mayorista())
    {
        total *= (1 - DESCUENTO_MAYORISTA);
    }
    // ...
}
```
<!-- {code-block} c -->

### Método 2: Macros con `#define`

Las macros son el caso explícito de {ref}`0x0107h`: van siempre en
`MAYUSCULAS_SNAKE_CASE`.

**Ventajas:**
- Disponible en todo el archivo (o globalmente si está en .h)
- Puede usarse para definir tamaños de arrays
- Compatible con código legacy

**Desventajas:**
- Sin type-safety
- Puede causar problemas si se redefine
- No tiene scope

```{code-block} c
:linenos:
#define MAX_USUARIOS 100
#define LONGITUD_NOMBRE 50
#define VERSION "1.0.3"
typedef struct
{
    char nombre[LONGITUD_NOMBRE];
    int id;
} usuario_t;
usuario_t usuarios[MAX_USUARIOS];
```
<!-- {code-block} c -->

### Método 3: Enumeraciones

**Ideal para conjuntos de valores relacionados**, exactamente lo que pide
{ref}`0x300Dh`:

```{code-block} c
:linenos:
enum dias_semana
{
    LUNES = 1,
    MARTES = 2,
    MIERCOLES = 3,
    JUEVES = 4,
    VIERNES = 5,
    SABADO = 6,
    DOMINGO = 7
};
enum prioridad_tarea
{
    PRIORIDAD_BAJA,
    PRIORIDAD_MEDIA,
    PRIORIDAD_ALTA,
    PRIORIDAD_CRITICA
};
```
<!-- {code-block} c -->

### Método 4: Variables Static Const en Funciones

Para constantes que solo se usan en una función específica:

``` c
double calcular_area_circulo(double radio)
{
    static const double PI = 3.14159265358979323846;
    return PI * radio * radio;
}
```
<!-- c -->

## Casos Prácticos de Refactorización

### Caso 1: Sistema de Autenticación

**Código Original:**

```{code-block} c
:linenos:
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool autenticar_usuario(const char *usuario, const char *password)
{
    int intentos = 0;
    while (intentos < 3)
    {
        if (strlen(password) < 8)
        {
            printf("Password muy corta\n");
            return false;
        }
        if (strcmp(usuario, "admin") == 0 && strcmp(password, "12345678") == 0)
        {
            return true;
        }
        intentos++;
        if (intentos < 3)
        {
            printf("Intento %d de 3 fallido\n", intentos);
        }
    }
    // Bloquear por 300 segundos
    printf("Cuenta bloqueada por 300 segundos\n");
    return false;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// Constantes de configuración del sistema
const int MAX_INTENTOS_LOGIN = 3;
const int LONGITUD_MINIMA_PASSWORD = 8;
const int TIEMPO_BLOQUEO_SEGUNDOS = 300;
// Credenciales (en producción vendrían de BD)
const char *USUARIO_ADMIN = "admin";
const char *PASSWORD_ADMIN = "12345678"; // Solo para demo
bool autenticar_usuario(const char *usuario, const char *password)
{
    int intentos = 0;
    while (intentos < MAX_INTENTOS_LOGIN)
    {
        if (strlen(password) < LONGITUD_MINIMA_PASSWORD)
        {
            printf("Password debe tener al menos %d caracteres\n",
                   LONGITUD_MINIMA_PASSWORD);
            return false;
        }
        if (strcmp(usuario, USUARIO_ADMIN) == 0 &&
            strcmp(password, PASSWORD_ADMIN) == 0)
        {
            return true;
        }
        intentos++;
        if (intentos < MAX_INTENTOS_LOGIN)
        {
            printf("Intento %d de %d fallido\n", intentos, MAX_INTENTOS_LOGIN);
        }
    }
    printf("Cuenta bloqueada por %d segundos\n", TIEMPO_BLOQUEO_SEGUNDOS);
    return false;
}
```
<!-- {code-block} c -->

**Beneficios:**
- Fácil ajustar la política de seguridad (cambiar 3 intentos a 5, etc.)
- Claro qué representa cada valor
- Un solo lugar para modificar cada parámetro

### Caso 2: Procesamiento de Temperaturas

**Código Original:**

```{code-block} c
:linenos:
void procesar_temperatura(double temp_fahrenheit)
{
    double temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
    if (temp_celsius < 0)
    {
        printf("Congelación\n");
    }
    else if (temp_celsius < 25)
    {
        printf("Frío\n");
    }
    else if (temp_celsius < 35)
    {
        printf("Agradable\n");
    }
    else
    {
        printf("Calor\n");
    }
    // Alarma si supera 100°C
    if (temp_celsius > 100)
    {
        activar_alarma();
    }
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
// Constantes de conversión
const double FAHRENHEIT_OFFSET = 32.0;
const double CELSIUS_A_FAHRENHEIT_FACTOR = 9.0 / 5.0;
const double FAHRENHEIT_A_CELSIUS_FACTOR = 5.0 / 9.0;
// Umbrales de temperatura en Celsius
const double TEMP_CONGELACION = 0.0;
const double TEMP_FRIO = 25.0;
const double TEMP_AGRADABLE = 35.0;
const double TEMP_EBULLICION_AGUA = 100.0;
double fahrenheit_a_celsius(double fahrenheit)
{
    return (fahrenheit - FAHRENHEIT_OFFSET) * FAHRENHEIT_A_CELSIUS_FACTOR;
}
void procesar_temperatura(double temp_fahrenheit)
{
    double temp_celsius = fahrenheit_a_celsius(temp_fahrenheit);
    if (temp_celsius < TEMP_CONGELACION)
    {
        printf("Congelación\n");
    }
    else if (temp_celsius < TEMP_FRIO)
    {
        printf("Frío\n");
    }
    else if (temp_celsius < TEMP_AGRADABLE)
    {
        printf("Agradable\n");
    }
    else
    {
        printf("Calor\n");
    }
    if (temp_celsius > TEMP_EBULLICION_AGUA)
    {
        activar_alarma();
    }
}
```
<!-- {code-block} c -->

### Caso 3: Gestión de Archivos

**Código Original:**

```{code-block} c
:linenos:
#include <stdio.h>
void procesar_archivo(const char *ruta)
{
    char buffer[1024];
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        printf("Error abriendo archivo\n");
        return;
    }
    while (fgets(buffer, 1024, stdin) != NULL)
    {
        // Procesar línea
        if (strlen(buffer) > 512)
        {
            printf("Línea muy larga (max 512)\n");
            continue;
        }
    }
    fclose(archivo);
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
#include <stdio.h>
#include <string.h>
// Configuración de buffers
#define TAMANO_BUFFER_LECTURA 1024
#define LONGITUD_MAXIMA_LINEA 512
// Mensajes de error
const char *MSG_ERROR_APERTURA = "Error abriendo archivo";
const char *MSG_LINEA_LARGA = "Línea muy larga (max %d caracteres)";
void procesar_archivo(const char *ruta)
{
    char buffer[TAMANO_BUFFER_LECTURA];
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        printf("%s\n", MSG_ERROR_APERTURA);
        return;
    }
    while (fgets(buffer, TAMANO_BUFFER_LECTURA, archivo) != NULL)
    {
        // Procesar línea
        if (strlen(buffer) > LONGITUD_MAXIMA_LINEA)
        {
            printf(MSG_LINEA_LARGA, LONGITUD_MAXIMA_LINEA);
            printf("\n");
            continue;
        }
        // ... más procesamiento
    }
    fclose(archivo);
}
```
<!-- {code-block} c -->

### Caso 4: Validación de Datos

**Código Original:**

```{code-block} c
:linenos:
bool validar_usuario(const char *nombre, int edad, double salario)
{
    if (strlen(nombre) < 3 || strlen(nombre) > 50)
    {
        return false;
    }
    if (edad < 18 || edad > 120)
    {
        return false;
    }
    if (salario < 0 || salario > 1000000)
    {
        return false;
    }
    return true;
}
```
<!-- {code-block} c -->

**Código Refactorizado:**

```{code-block} c
:linenos:
// Límites de validación
const int LONGITUD_MINIMA_NOMBRE = 3;
const int LONGITUD_MAXIMA_NOMBRE = 50;
const int EDAD_MINIMA = 18;
const int EDAD_MAXIMA = 120;
const double SALARIO_MINIMO = 0.0;
const double SALARIO_MAXIMO = 1000000.0;
bool validar_nombre(const char *nombre)
{
    size_t longitud = strlen(nombre);
    return longitud >= LONGITUD_MINIMA_NOMBRE &&
           longitud <= LONGITUD_MAXIMA_NOMBRE;
}
bool validar_edad(int edad)
{
    return edad >= EDAD_MINIMA && edad <= EDAD_MAXIMA;
}
bool validar_salario(double salario)
{
    return salario >= SALARIO_MINIMO && salario <= SALARIO_MAXIMO;
}
bool validar_usuario(const char *nombre, int edad, double salario)
{
    return validar_nombre(nombre) && validar_edad(edad) &&
           validar_salario(salario);
}
```
<!-- {code-block} c -->

### Caso 5: Ejemplo Integrador

Los casos anteriores atacaban una regla por vez. En el código real los vicios
aparecen juntos, así que conviene ver una refactorización que resuelve varias
reglas a la vez sobre el mismo fragmento.

**❌ Código original:**

```{code-block} c
:linenos:
#include <stdio.h>
double promediar(double notas[])
{
    double suma = 0;
    for (int i = 0; i < 5; i++) // 5: cantidad de notas
    {
        suma += notas[i];
    }
    return suma / 5;
}
int estado_alumno(double promedio, int asistencias)
{
    if (promedio < 60) // umbral de aprobación
    {
        return -1; // ¿desaprobado? ¿error?
    }
    if (asistencias < 3) // mínimo de asistencias
    {
        return -2; // ¿libre? ¿otro error?
    }
    return 0;
}
void imprimir_total(double matriz[][8])
{
    printf("%.2f\n", matriz[0][7]); // ¿qué es la columna 7?
}
```
<!-- {code-block} c -->

En este fragmento conviven un umbral literal (`60`), una cantidad repetida
(`5`), códigos de retorno sin nombre (`-1`, `-2`, `0`), un índice de arreglo
críptico (`7`) y un tamaño de columna fijo (`8`).

**✅ Código refactorizado:**

```{code-block} c
:linenos:
#include <stdio.h>
// Tamaños y políticas (tiempo de compilación)
#define CANTIDAD_NOTAS 5
#define MINIMO_ASISTENCIAS 3
#define COLUMNAS_MATRIZ 8
// Umbral como constante `const` en MAYUSCULAS_SNAKE_CASE
const double PROMEDIO_APROBACION = 60.0;
// Estados y posiciones con nombre de dominio
enum estado_alumno
{
    ESTADO_APROBADO = 0,
    ESTADO_DESAPROBADO = -1,
    ESTADO_LIBRE = -2
};
enum columna_totales
{
    COLUMNA_PARCIALES = 0,
    COLUMNA_TOTAL = 7
};
double promediar(const double notas[])
{
    double suma = 0.0;
    for (int i = 0; i < CANTIDAD_NOTAS; i++)
    {
        suma += notas[i];
    }
    return suma / CANTIDAD_NOTAS;
}
enum estado_alumno evaluar_alumno(double promedio, int asistencias)
{
    if (promedio < PROMEDIO_APROBACION)
    {
        return ESTADO_DESAPROBADO;
    }
    if (asistencias < MINIMO_ASISTENCIAS)
    {
        return ESTADO_LIBRE;
    }
    return ESTADO_APROBADO;
}
void imprimir_total(const double matriz[][COLUMNAS_MATRIZ])
{
    printf("%.2f\n", matriz[0][COLUMNA_TOTAL]);
}
```
<!-- {code-block} c -->

Reglas resueltas de un solo golpe: {ref}`0x0112h` (constantes simbólicas para
todo literal con significado), {ref}`0x010Fh` (el índice `7` pasó a
`COLUMNA_TOTAL`), {ref}`0x0103h` (`PROMEDIO_APROBACION` en
`MAYUSCULAS_SNAKE_CASE`), {ref}`0x0107h` (las macros `CANTIDAD_NOTAS`,
`MINIMO_ASISTENCIAS` y `COLUMNAS_MATRIZ`), {ref}`0x300Dh` (`enum` para los
estados), {ref}`0x2007h` (los códigos de retorno `-1`, `-2` y `0` ahora tienen
nombre) y {ref}`0x5001h` (el arreglo se dimensiona con la constante
`COLUMNAS_MATRIZ`).

## Números Mágicos Aceptables

### El Número 0 y 1

En contextos obvios, `0` y `1` generalmente no necesitan ser constantes:

``` c
// Aceptable
int contador = 0;
int resultado = funcion() + 1;
```
<!-- c -->

### Potencias de 2 Comunes

En algunos contextos de bajo nivel:

``` c
// Generalmente aceptable en contextos de bits
int mascara = valor & 0xFF;
int desplazamiento = numero << 8;
```
<!-- c -->

### Índices de Arrays

Los índices `0`, `1` y `2` y las variables de iteración quedan exceptuados por
su uso idiomático, pero un índice fijo mayor que 2 es un número mágico y cae
bajo {ref}`0x010Fh`: hay que nombrarlo con una constante simbólica o de `enum`.

``` c
// Aceptable
char primer_caracter = cadena[0];
char ultimo_caracter = cadena[strlen(cadena) - 1];
```

```{code-block} c
:linenos:
// Malo: ¿qué campo es la posición 7?
total = registro[7];
// Bueno: el índice también se autodocumenta
enum campo_registro
{
    CAMPO_LEGAJO = 0,
    CAMPO_NOMBRE = 1,
    CAMPO_SUELDO = 2,
    CAMPO_TOTAL = 7
};
total = registro[CAMPO_TOTAL];
```
<!-- {code-block} c -->

## Patrón de Organización de Constantes

### Opción 1: Archivo de Configuración

**config.h:**

```{code-block} c
:linenos:
#ifndef CONFIG_H
#define CONFIG_H
// Configuración del sistema
#define VERSION_MAYOR 1
#define VERSION_MENOR 0
#define VERSION_PATCH 3
// Límites del sistema
#define MAX_USUARIOS 100
#define MAX_CONEXIONES_SIMULTANEAS 50
#define TIMEOUT_CONEXION_SEGUNDOS 30
// Tamaños de buffer
#define TAMANO_BUFFER_GENERAL 1024
#define LONGITUD_MAXIMA_NOMBRE 50
#define LONGITUD_MAXIMA_EMAIL 100
// Configuración de negocio
const double IVA_ARGENTINA = 0.21;
const int EDAD_MINIMA_CONDUCTOR = 18;
const int PUNTOS_LICENCIA_INICIAL = 0;
#endif // CONFIG_H
```
<!-- {code-block} c -->

### Opción 2: Constantes por Módulo

Cada módulo define sus propias constantes en su archivo .c:

```{code-block} c
:linenos:
// usuario.c
static const int LONGITUD_MINIMA_PASSWORD = 8;
static const int MAX_INTENTOS_LOGIN = 3;
// archivo.c
static const int TAMANO_BUFFER = 4096;
static const char *EXTENSION_TEMPORAL = ".tmp";
```
<!-- {code-block} c -->

### Opción 3: Enumeraciones Agrupadas

```{code-block} c
:linenos:
// Códigos de error del sistema
enum codigos_error
{
    ERROR_EXITO = 0,
    ERROR_MEMORIA = -1,
    ERROR_ARCHIVO_NO_ENCONTRADO = -2,
    ERROR_PERMISOS = -3,
    ERROR_FORMATO_INVALIDO = -4
};
// Niveles de log
enum nivel_log
{
    LOG_DEBUG = 0,
    LOG_INFO = 1,
    LOG_WARNING = 2,
    LOG_ERROR = 3,
    LOG_FATAL = 4
};
```
<!-- {code-block} c -->

## Proceso de Refactorización Paso a Paso

### 1. Identificar Números Mágicos

Buscar literales numéricos en el código:

``` bash
# Con grep
grep -n "[^a-zA-Z][0-9]\+[^a-zA-Z]" archivo.c

# Revisar manualmente cada ocurrencia
```
<!-- bash -->

### 2. Analizar Contexto

Para cada número, preguntarse:
- ¿Qué representa?
- ¿Se usa en múltiples lugares?
- ¿Podría cambiar en el futuro?
- ¿Es claro su significado para otros desarrolladores?

### 3. Elegir Nombre Descriptivo

El nombre debe ser:
- Auto-explicativo
- En mayúsculas para constantes
- Prefijo del módulo si es global

```{code-block} c
:linenos:
// Malo
const int MAX = 100;
// Mejor
const int MAX_USUARIOS = 100;
// Mejor aún
const int MAX_USUARIOS_SISTEMA = 100;
```
<!-- {code-block} c -->

### 4. Determinar Scope

- **Global:** Si se usa en múltiples archivos → `.h`
- **Archivo:** Si se usa solo en un archivo → `static const` en `.c`
- **Función:** Si se usa solo en una función → `const` local

### 5. Reemplazar Todas las Ocurrencias

Usar búsqueda y reemplazo con cuidado:

``` c
// Buscar: \b100\b (expresión regular)
// Reemplazar caso por caso, verificando contexto
```
<!-- c -->

### 6. Verificar con Tests

Ejecutar tests para asegurar que el comportamiento no cambió.

## Refactorización en Código Legacy

### Estrategia Incremental

No intentar refactorizar todo a la vez:

1. **Priorizar:** Números más críticos o problemáticos primero
2. **Por módulo:** Refactorizar archivo por archivo
3. **Con tests:** Cada cambio debe tener tests que lo validen

### Ejemplo de Refactorización Gradual

**Iteración 1: Identificar candidatos**

```{code-block} c
:linenos:
// Marcar con comentarios
if (temperatura > 100)
{ // MAGIC: punto de ebullición
    alarma();
}
if (intentos >= 3)
{ // MAGIC: máximo de intentos
    bloquear();
}
```
<!-- {code-block} c -->

**Iteración 2: Extraer constantes locales**

```{code-block} c
:linenos:
const int PUNTO_EBULLICION = 100;
if (temperatura > PUNTO_EBULLICION)
{
    alarma();
}
const int MAX_INTENTOS = 3;
if (intentos >= MAX_INTENTOS)
{
    bloquear();
}
```
<!-- {code-block} c -->

**Iteración 3: Centralizar si es necesario**

Mover a archivo de configuración si se repite.

## Antipatrones a Evitar

### 1. Sobre-Constantes

```{code-block} c
:linenos:
// Excesivo
const int UNO = 1;
const int CERO = 0;
const int VERDADERO = 1;
// Innecesario
for (int i = CERO; i < MAX; i = i + UNO)
{
    // ...
}
```
<!-- {code-block} c -->

### 2. Constantes Obvias

``` c
// Obvio, no mejora la claridad
const int DIAS_EN_SEMANA = 7;
const int MESES_EN_ANIO = 12;
// Pero en contexto específico puede ser útil:
const int DIAS_LABORABLES_SEMANA = 5;
```
<!-- c -->

### 3. Nombres Vagos

```{code-block} c
:linenos:
// Malo
const int LIMITE = 100;
const int MAX = 50;
// Bueno
const int LIMITE_VELOCIDAD_KMH = 100;
const int MAX_CARACTERES_COMENTARIO = 50;
```
<!-- {code-block} c -->

## Diagnóstico y refactorización

Antes de tocar el código, conviene reconocer el síntoma. La tabla siguiente
relaciona cada regla con la señal concreta que la delata y con la técnica de
esta guía que la remedia.

| Regla | Síntoma en el código | Técnica de esta guía |
| :--- | :--- | :--- |
| {ref}`0x0112h` | Un literal con significado aparece suelto (`if (edad > 120)`, `precio * 0.85`). | Extraer una constante simbólica con nombre de dominio (`const`, `#define` o `enum`). |
| {ref}`0x010Fh` | Se accede a posiciones fijas con literales mayores que 2 (`registro[7]`). | Nombrar cada posición con una constante simbólica o de `enum` (sección «Índices de Arrays»). |
| {ref}`0x0103h` | Una constante `const` está en minúsculas o `camelCase` (`const int maxUsuarios`). | Renombrarla en `MAYUSCULAS_SNAKE_CASE` al extraer el literal. |
| {ref}`0x0107h` | Una macro `#define` está en minúsculas (`#define maxBuffer 50`). | Renombrarla en `MAYUSCULAS_SNAKE_CASE` (Método 2). |
| {ref}`0x300Dh` | Estados o categorías comparados contra literales (`if (estado == 2)`). | Agrupar los valores en un `enum` con nombres de dominio (Método 3). |
| {ref}`0x2007h` | Valores de retorno literales (`return -1;`) sin causa comunicada. | Definir el valor de retorno con un `enum` o constante simbólica (Caso 5). |
| {ref}`0x5001h` | Arreglos dimensionados con un valor calculado en runtime (VLA) o con un literal repetido. | Extraer el tamaño a una constante de tiempo de compilación y usarla para dimensionar. |

## Resumen

La eliminación de números mágicos es una refactorización fundamental que:

1. **Mejora la legibilidad:** El código se autodocumenta
2. **Facilita el mantenimiento:** Cambios centralizados
3. **Reduce errores:** Valores consistentes en todo el código
4. **Documenta decisiones:** Los nombres explican el "por qué"

**Reglas clave:**
- Usar `const` para type-safety cuando sea posible
- Usar `#define` para tamaños de arrays y compatibilidad legacy
- Usar `enum` para conjuntos de valores relacionados
- Nombres descriptivos y auto-explicativos
- Scope apropiado (local cuando sea posible)

El tiempo invertido en esta refactorización se recupera rápidamente en
mantenimiento y prevención de bugs.

## Checklist de verificación

- [ ] Todo literal con significado del fragmento quedó reemplazado por una
      constante simbólica, conforme a {ref}`0x0112h`.
- [ ] Ningún arreglo se indexa con literales mayores que 2; cada posición fija
      tiene nombre propio, según {ref}`0x010Fh`.
- [ ] Las constantes `const` están en `MAYUSCULAS_SNAKE_CASE` ({ref}`0x0103h`).
- [ ] Las macros `#define` están en `MAYUSCULAS_SNAKE_CASE` ({ref}`0x0107h`).
- [ ] Los estados y conjuntos de valores relacionados se declararon con `enum`
      ({ref}`0x300Dh`).
- [ ] Los valores de retorno y códigos de error numéricos tienen nombre
      simbólico ({ref}`0x2007h`).
- [ ] Los arreglos estáticos se dimensionan con una constante de tiempo de
      compilación y no con un VLA ({ref}`0x5001h`).
- [ ] El comportamiento del código no cambió: los tests siguen pasando.
