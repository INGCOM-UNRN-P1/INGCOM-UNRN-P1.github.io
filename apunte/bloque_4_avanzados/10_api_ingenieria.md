---
title: 'Ingeniería de APIs y Gestión de Compatibilidad'
short_title: 'Ingeniería de APIs'
subtitle: 'Versionado semántico, estabilidad de ABI y performance de interfaces en C'
---

(versionado-y-compatibilidad)=
## Versionado y Compatibilidad

Un aspecto crítico del diseño de APIs profesionales es la gestión de versiones y
la compatibilidad hacia atrás (_backwards compatibility_).

(versionado-semantico)=
### Versionado Semántico

Se recomienda seguir el esquema **MAJOR.MINOR.PATCH** propuesto por
Preston-Werner [@preston2013]:

- **MAJOR**: Cambios incompatibles en la API (rompen código existente). Ejemplo:
  eliminar una función pública, cambiar la firma de una función, modificar el
  comportamiento documentado de forma incompatible.
- **MINOR**: Nuevas funcionalidades compatibles hacia atrás. Ejemplo: agregar
  nuevas funciones, agregar parámetros opcionales con valores predeterminados,
  agregar nuevos valores a enumeraciones existentes (con cuidado).
- **PATCH**: Correcciones de bugs compatibles hacia atrás. Ejemplo: corregir
  fugas de memoria, corregir comportamiento que no coincide con la
  documentación, mejorar performance sin cambiar la API.

El versionado semántico comunica explícitamente el impacto de actualizar una
dependencia. Un cambio de versión `1.2.3` a `1.2.4` garantiza que es seguro
actualizar sin revisar código, mientras que un cambio a `2.0.0` indica que se
requiere revisión y posiblemente modificaciones.

:::{tip}

**Estabilidad del ABI**

El versionado semántico se aplica típicamente a la API (interfaz a nivel de
código fuente). Sin embargo, en bibliotecas dinámicas (`.so` en Linux, `.dll` en
Windows), también es crucial mantener la estabilidad del ABI (Application Binary
Interface). Cambios que preservan la API pero rompen el ABI incluyen: modificar
el tamaño de estructuras públicas, reordenar campos, cambiar convenciones de
llamada, etc.

Para bibliotecas que deben mantener estabilidad del ABI, el uso de punteros
opacos como se describe en
{ref}`3-encapsulamiento-y-ocultamiento-de-informacion` es esencial.

:::
<!-- {tip} -->

(estrategias-de-evolucion)=
### Estrategias de Evolución

Cuando es necesario cambiar una función existente:

1. **Deprecación Gradual**: Mantener la función antigua, marcarla como obsoleta,
   y ofrecer una alternativa.

```{code-block} c
// Función antigua (deprecada)
// DEPRECADO: Usar lista_agregar_v2() en su lugar
bool lista_agregar(lista_t *lista, int dato);
// Nueva función
bool lista_agregar_v2(lista_t *lista, int dato, size_t *indice_out);
```
<!-- {code-block} c -->

2. **Sobrecarga por Nombre**: Dado que C no soporta sobrecarga de funciones, se
   usan nombres distintos.

```{code-block} c
void dibujar_rectangulo(int x, int y, int ancho, int alto);
void dibujar_rectangulo_ex(int x, int y, int ancho, int alto, color_t color);
```
<!-- {code-block} c -->

3. **Uso de Estructuras de Opciones**: Para funciones con muchos parámetros
   opcionales, se puede usar una estructura de configuración.

```{code-block} c
:linenos:
typedef struct
{
    int ancho;
    int alto;
    color_t color;
    bool borde;
    int grosor_borde;
} rectangulo_config_t;
// Configuración por defecto
rectangulo_config_t rectangulo_config_defecto(void);
// Función que acepta configuración
void dibujar_rectangulo_config(int x, int y,
                               const rectangulo_config_t *config);
```
<!-- {code-block} c -->

(ejercicios-sobre-diseno-de-apis)=
## Ejercicios sobre Diseño de APIs

:::{exercise}
:label: api_pila_basica
:enumerator: api-1

Diseñá la interfaz (archivo `.h`) para una pila (_stack_) de enteros. La pila
debe soportar las operaciones básicas: crear, destruir, apilar (_push_),
desapilar (_pop_), y consultar el tope sin desapilar (_peek_). Incluí
documentación completa con precondiciones y poscondiciones para cada función.

**Requisitos:**
- Usar un tipo opaco `pila_t`.
- Seguir el patrón constructor/destructor.
- Especificar claramente la gestión de memoria.
- Indicar cómo se reportan los errores (ej. pila vacía al desapilar).

:::
<!-- {exercise} -->

::::{solution} api_pila_basica
:class: dropdown

```{code-block} c
:linenos:
#ifndef PILA_H
#define PILA_H
#include <stdbool.h>
#include <stddef.h>
/**
 * Tipo opaco que representa una pila de enteros.
 */
typedef struct pila pila_t;
/**
 * Crea una nueva pila vacía.
 *
 * @returns Puntero a la nueva pila, o NULL si falla la asignación de memoria.
 * @post El llamador debe liberar la memoria con pila_destruir().
 */
pila_t *pila_crear(void);
/**
 * Destruye una pila y libera toda la memoria asociada.
 *
 * @param pila Puntero a la pila a destruir.
 * @post Todos los elementos son liberados. El puntero pila queda inválido.
 */
void pila_destruir(pila_t *pila);
/**
 * Apila un elemento en el tope de la pila.
 *
 * @param pila Pila donde apilar el elemento.
 * @param dato Valor entero a apilar.
 * @returns true si se apiló exitosamente, false si falló la asignación.
 * @pre pila != NULL
 */
bool pila_apilar(pila_t *pila, int dato);
/**
 * Desapila y retorna el elemento del tope de la pila.
 *
 * @param pila Pila de donde desapilar.
 * @param dato Puntero donde almacenar el elemento desapilado.
 * @returns true si se desapiló exitosamente, false si la pila estaba vacía.
 * @pre pila != NULL, dato != NULL
 * @post Si retorna true, *dato contiene el valor desapilado.
 */
bool pila_desapilar(pila_t *pila, int *dato);
/**
 * Consulta el elemento en el tope de la pila sin desapilarlo.
 *
 * @param pila Pila a consultar.
 * @param dato Puntero donde almacenar el elemento del tope.
 * @returns true si hay un elemento, false si la pila está vacía.
 * @pre pila != NULL, dato != NULL
 */
bool pila_peek(const pila_t *pila, int *dato);
/**
 * Verifica si la pila está vacía.
 *
 * @param pila Pila a verificar.
 * @returns true si la pila está vacía, false en caso contrario.
 * @pre pila != NULL
 */
bool pila_esta_vacia(const pila_t *pila);
/**
 * Obtiene el número de elementos en la pila.
 *
 * @param pila Pila a consultar.
 * @returns Cantidad de elementos en la pila.
 * @pre pila != NULL
 */
size_t pila_tamano(const pila_t *pila);
#endif // PILA_H
```
<!-- {code-block} c -->

::::
<!-- {solution} api_pila_basica -->

:::{exercise}
:label: api_calculadora_mejorada
:enumerator: api-2

Extendé el módulo `matematica.h` del
{ref}`ejemplo-2-modulo-de-operaciones-matematicas-seguras` para incluir
operaciones de multiplicación y suma, ambas con detección de desbordamiento
(_overflow_). Implementá las funciones y un programa de ejemplo que demuestre el
manejo de errores.

**Pistas:**
- Para detectar desbordamiento en la suma: verificar si `a + b < a` (para
  números sin signo) o usar límites de `INT_MAX`.
- Para la multiplicación: verificar si `a * b / a != b` cuando `a != 0`.

:::
<!-- {exercise} -->

::::{solution} api_calculadora_mejorada
:class: dropdown

```{code-block} c
:linenos:
// Adiciones a matematica.h
#include <limits.h> // Para INT_MAX, INT_MIN
/**
 * Suma dos enteros con detección de desbordamiento.
 *
 * @param a Primer sumando.
 * @param b Segundo sumando.
 * @param resultado Puntero donde almacenar el resultado.
 * @returns MAT_OK si la suma es válida, MAT_ERROR_DESBORDAMIENTO en caso
 * contrario.
 * @pre resultado != NULL
 * @post Si retorna MAT_OK, *resultado = a + b.
 */
mat_error_t mat_sumar(int a, int b, int *resultado);
/**
 * Multiplica dos enteros con detección de desbordamiento.
 *
 * @param a Primer factor.
 * @param b Segundo factor.
 * @param resultado Puntero donde almacenar el resultado.
 * @returns MAT_OK si la multiplicación es válida,
 *          MAT_ERROR_DESBORDAMIENTO en caso contrario.
 * @pre resultado != NULL
 */
mat_error_t mat_multiplicar(int a, int b, int *resultado);
```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// Implementación en matematica.c
mat_error_t mat_sumar(int a, int b, int *resultado)
{
    // Detectar desbordamiento positivo
    if (b > 0 && a > INT_MAX - b)
    {
        return MAT_ERROR_DESBORDAMIENTO;
    }
    // Detectar desbordamiento negativo
    if (b < 0 && a < INT_MIN - b)
    {
        return MAT_ERROR_DESBORDAMIENTO;
    }
    *resultado = a + b;
    return MAT_OK;
}
mat_error_t mat_multiplicar(int a, int b, int *resultado)
{
    // Casos especiales
    if (a == 0 || b == 0)
    {
        *resultado = 0;
        return MAT_OK;
    }
    // Detectar desbordamiento
    if (a > 0)
    {
        if (b > 0 && a > INT_MAX / b)
        {
            return MAT_ERROR_DESBORDAMIENTO;
        }
        if (b < 0 && b < INT_MIN / a)
        {
            return MAT_ERROR_DESBORDAMIENTO;
        }
    }
    else
    { // a < 0
        if (b > 0 && a < INT_MIN / b)
        {
            return MAT_ERROR_DESBORDAMIENTO;
        }
        if (b < 0 && a < INT_MAX / b)
        { // a < 0, b < 0
            return MAT_ERROR_DESBORDAMIENTO;
        }
    }
    *resultado = a * b;
    return MAT_OK;
}
```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// Programa de prueba
#include "matematica.h"
#include <limits.h>
#include <stdio.h>
int main(void)
{
    int resultado = 0;
    mat_error_t error = MAT_OK;
    // Prueba de suma normal
    error = mat_sumar(100, 200, &resultado);
    if (error == MAT_OK)
    {
        printf("100 + 200 = %d\n", resultado);
    }
    // Prueba de desbordamiento en suma
    error = mat_sumar(INT_MAX, 1, &resultado);
    if (error != MAT_OK)
    {
        printf("Desbordamiento detectado: %s\n", mat_error_str(error));
    }
    // Prueba de multiplicación con desbordamiento
    error = mat_multiplicar(INT_MAX / 2, 3, &resultado);
    if (error != MAT_OK)
    {
        printf("Desbordamiento en multiplicación: %s\n", mat_error_str(error));
    }
    return 0;
}
```
<!-- {code-block} c -->

::::
<!-- {solution} api_calculadora_mejorada -->

:::{exercise}
:label: api_buffer_circular
:enumerator: api-3

Diseñá e implementá una API para un buffer circular de tamaño fijo. El buffer
debe permitir escribir y leer bytes, y debe reportar cuando esté lleno o vacío.
Usá el patrón Init/Finalize del {ref}`patron-init-finalize`, de forma que el
usuario pueda declarar el buffer en el stack.

**Operaciones requeridas:**
- `buffer_init()`: Inicializa un buffer con capacidad especificada.
- `buffer_finalize()`: Limpia recursos internos.
- `buffer_escribir()`: Escribe datos en el buffer.
- `buffer_leer()`: Lee datos del buffer.
- `buffer_disponible()`: Consulta cuántos bytes hay disponibles para leer.
- `buffer_espacio_libre()`: Consulta cuánto espacio hay para escribir.

:::
<!-- {exercise} -->

::::{solution} api_buffer_circular
:class: dropdown

```{code-block} c
:linenos:
#ifndef BUFFER_CIRCULAR_H
#define BUFFER_CIRCULAR_H
#include <stdbool.h>
#include <stddef.h>
#define BUFFER_CAPACIDAD_MAXIMA 1024
/**
 * Estructura de buffer circular de tamaño fijo.
 * El usuario puede declararlo en el stack.
 */
typedef struct
{
    unsigned char datos[BUFFER_CAPACIDAD_MAXIMA];
    size_t capacidad;
    size_t inicio;   // Índice de lectura
    size_t fin;      // Índice de escritura
    size_t cantidad; // Número de bytes almacenados
} buffer_circular_t;
/**
 * Inicializa un buffer circular.
 *
 * @param buffer Puntero al buffer a inicializar.
 * @param capacidad Capacidad del buffer (máximo BUFFER_CAPACIDAD_MAXIMA).
 * @returns true si se inicializó correctamente, false si capacidad es
 * inválida.
 * @pre buffer != NULL
 * @post El buffer queda vacío y listo para usar.
 */
bool buffer_init(buffer_circular_t *buffer, size_t capacidad);
/**
 * Limpia un buffer circular.
 *
 * @param buffer Puntero al buffer a limpiar.
 * @pre buffer != NULL
 * @post El buffer queda vacío.
 */
void buffer_finalize(buffer_circular_t *buffer);
/**
 * Escribe datos en el buffer.
 *
 * @param buffer Buffer donde escribir.
 * @param datos Puntero a los datos a escribir.
 * @param longitud Número de bytes a escribir.
 * @returns Número de bytes efectivamente escritos (puede ser menor que
 * longitud si el buffer está casi lleno).
 * @pre buffer != NULL, datos != NULL
 */
size_t buffer_escribir(buffer_circular_t *buffer, const unsigned char *datos,
                       size_t longitud);
/**
 * Lee datos del buffer.
 *
 * @param buffer Buffer de donde leer.
 * @param datos Puntero al buffer de destino.
 * @param longitud Número máximo de bytes a leer.
 * @returns Número de bytes efectivamente leídos (puede ser menor que longitud
 *          si hay menos datos disponibles).
 * @pre buffer != NULL, datos != NULL
 */
size_t buffer_leer(buffer_circular_t *buffer, unsigned char *datos,
                   size_t longitud);
/**
 * Consulta cuántos bytes hay disponibles para leer.
 *
 * @param buffer Buffer a consultar.
 * @returns Número de bytes disponibles.
 * @pre buffer != NULL
 */
size_t buffer_disponible(const buffer_circular_t *buffer);
/**
 * Consulta cuánto espacio libre hay para escribir.
 *
 * @param buffer Buffer a consultar.
 * @returns Número de bytes libres.
 * @pre buffer != NULL
 */
size_t buffer_espacio_libre(const buffer_circular_t *buffer);
/**
 * Verifica si el buffer está vacío.
 */
bool buffer_esta_vacio(const buffer_circular_t *buffer);
/**
 * Verifica si el buffer está lleno.
 */
bool buffer_esta_lleno(const buffer_circular_t *buffer);
#endif // BUFFER_CIRCULAR_H
```
<!-- {code-block} c -->

```{code-block} c
:linenos:
// Implementación buffer_circular.c
#include "buffer_circular.h"
#include <string.h>
bool buffer_init(buffer_circular_t *buffer, size_t capacidad)
{
    if (capacidad == 0 || capacidad > BUFFER_CAPACIDAD_MAXIMA)
    {
        return false;
    }
    buffer->capacidad = capacidad;
    buffer->inicio = 0;
    buffer->fin = 0;
    buffer->cantidad = 0;
    return true;
}
void buffer_finalize(buffer_circular_t *buffer)
{
    buffer->inicio = 0;
    buffer->fin = 0;
    buffer->cantidad = 0;
}
size_t buffer_escribir(buffer_circular_t *buffer, const unsigned char *datos,
                       size_t longitud)
{
    size_t espacio = buffer->capacidad - buffer->cantidad;
    size_t a_escribir = (longitud < espacio) ? longitud : espacio;
    for (size_t i = 0; i < a_escribir; i++)
    {
        buffer->datos[buffer->fin] = datos[i];
        buffer->fin = (buffer->fin + 1) % buffer->capacidad;
        buffer->cantidad++;
    }
    return a_escribir;
}
size_t buffer_leer(buffer_circular_t *buffer, unsigned char *datos,
                   size_t longitud)
{
    size_t a_leer =
        (longitud < buffer->cantidad) ? longitud : buffer->cantidad;
    for (size_t i = 0; i < a_leer; i++)
    {
        datos[i] = buffer->datos[buffer->inicio];
        buffer->inicio = (buffer->inicio + 1) % buffer->capacidad;
        buffer->cantidad--;
    }
    return a_leer;
}
size_t buffer_disponible(const buffer_circular_t *buffer)
{
    return buffer->cantidad;
}
size_t buffer_espacio_libre(const buffer_circular_t *buffer)
{
    return buffer->capacidad - buffer->cantidad;
}
bool buffer_esta_vacio(const buffer_circular_t *buffer)
{
    return buffer->cantidad == 0;
}
bool buffer_esta_lleno(const buffer_circular_t *buffer)
{
    return buffer->cantidad == buffer->capacidad;
}
```
<!-- {code-block} c -->

::::
<!-- {solution} api_buffer_circular -->

:::{exercise}
:label: api_parser_cli
:enumerator: api-4

Diseñá una API para parsear argumentos de línea de comandos. La API debe
soportar opciones booleanas (flags como `-v` para verbose), opciones con valores
(como `-o archivo.txt`), y argumentos posicionales. Implementá solo la interfaz
(archivo `.h`) con documentación completa.

**Ejemplo de uso esperado:**
```{code-block} c
:linenos:
parser_t *parser = parser_crear("Mi Programa", "1.0");
parser_agregar_flag(parser, 'v', "verbose", "Modo verbose");
parser_agregar_opcion(parser, 'o', "output", "Archivo de salida", "stdout");
parser_parsear(parser, argc, argv);
bool verbose = parser_obtener_flag(parser, "verbose");
const char *salida = parser_obtener_opcion(parser, "output");
```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

::::{solution} api_parser_cli
:class: dropdown

```{code-block} c
:linenos:
#ifndef PARSER_CLI_H
#define PARSER_CLI_H
#include <stdbool.h>
/**
 * Tipo opaco que representa un parseador de argumentos de línea de comandos.
 */
typedef struct parser parser_t;
/**
 * Crea un nuevo parseador de argumentos.
 *
 * @param nombre_programa Nombre del programa (para mensajes de ayuda).
 * @param version Versión del programa.
 * @returns Puntero al parseador creado, o NULL si falla.
 * @pre nombre_programa != NULL, version != NULL
 * @post El llamador debe liberar con parser_destruir().
 */
parser_t *parser_crear(const char *nombre_programa, const char *version);
/**
 * Destruye un parseador y libera sus recursos.
 *
 * @param parser Parseador a destruir.
 * @post El puntero parser queda inválido.
 */
void parser_destruir(parser_t *parser);
/**
 * Agrega una opción booleana (flag) al parseador.
 *
 * @param parser Parseador al cual agregar el flag.
 * @param corto Carácter para la forma corta (ej. 'v' para -v).
 * @param largo Cadena para la forma larga (ej. "verbose" para --verbose).
 * @param descripcion Descripción para el mensaje de ayuda.
 * @returns true si se agregó exitosamente, false en caso de error.
 * @pre parser != NULL, largo != NULL
 */
bool parser_agregar_flag(parser_t *parser, char corto, const char *largo,
                         const char *descripcion);
/**
 * Agrega una opción con valor al parseador.
 *
 * @param parser Parseador al cual agregar la opción.
 * @param corto Carácter para la forma corta (ej. 'o' para -o).
 * @param largo Cadena para la forma larga (ej. "output" para --output).
 * @param descripcion Descripción para el mensaje de ayuda.
 * @param valor_defecto Valor por defecto si la opción no es especificada.
 * @returns true si se agregó exitosamente, false en caso de error.
 * @pre parser != NULL, largo != NULL
 */
bool parser_agregar_opcion(parser_t *parser, char corto, const char *largo,
                           const char *descripcion, const char *valor_defecto);
/**
 * Parsea los argumentos de línea de comandos.
 *
 * @param parser Parseador a utilizar.
 * @param argc Número de argumentos (desde main).
 * @param argv Vector de argumentos (desde main).
 * @returns true si el parseo fue exitoso, false si hubo errores.
 * @pre parser != NULL, argv != NULL, argc >= 1
 * @post Si retorna false, usar parser_obtener_error() para obtener detalles.
 */
bool parser_parsear(parser_t *parser, int argc, char *argv[]);
/**
 * Obtiene el valor de un flag booleano.
 *
 * @param parser Parseador a consultar.
 * @param nombre Nombre largo del flag.
 * @returns true si el flag fue especificado, false en caso contrario.
 * @pre parser != NULL, nombre != NULL
 * @pre parser_parsear() debe haber sido llamado previamente.
 */
bool parser_obtener_flag(const parser_t *parser, const char *nombre);
/**
 * Obtiene el valor de una opción.
 *
 * @param parser Parseador a consultar.
 * @param nombre Nombre largo de la opción.
 * @returns Valor de la opción, o el valor por defecto si no fue especificada.
 * @pre parser != NULL, nombre != NULL
 * @pre parser_parsear() debe haber sido llamado previamente.
 * @post La cadena retornada es propiedad del parser y válida hasta
 *       que parser_destruir() sea llamado.
 */
const char *parser_obtener_opcion(const parser_t *parser, const char *nombre);
/**
 * Obtiene los argumentos posicionales (no opciones).
 *
 * @param parser Parseador a consultar.
 * @param cantidad Puntero donde almacenar el número de argumentos
 * posicionales.
 * @returns Vector de cadenas con los argumentos posicionales.
 * @pre parser != NULL, cantidad != NULL
 * @post El vector retornado es propiedad del parser.
 */
const char **parser_obtener_argumentos(const parser_t *parser, int *cantidad);
/**
 * Muestra el mensaje de ayuda en la salida estándar.
 *
 * @param parser Parseador con las opciones definidas.
 * @pre parser != NULL
 */
void parser_mostrar_ayuda(const parser_t *parser);
/**
 * Obtiene el mensaje de error del último parseo fallido.
 *
 * @param parser Parseador a consultar.
 * @returns Cadena con el mensaje de error, o NULL si no hubo error.
 * @pre parser != NULL
 * @post La cadena retornada es propiedad del parser.
 */
const char *parser_obtener_error(const parser_t *parser);
#endif // PARSER_CLI_H
```
<!-- {code-block} c -->

::::
<!-- {solution} api_parser_cli -->

:::{exercise}
:label: api_json_simple
:enumerator: api-5

Diseñá una API minimalista para leer archivos JSON simples (solo objetos con
pares clave-valor donde los valores son cadenas o números). La API debe permitir
cargar un archivo JSON y consultar valores por clave. Aplicá todos los
principios de diseño vistos: tipo opaco, manejo de errores consistente,
documentación completa, y uso de `const` apropiado.

:::
<!-- {exercise} -->

::::{solution} api_json_simple
:class: dropdown

```{code-block} c
:linenos:
#ifndef JSON_SIMPLE_H
#define JSON_SIMPLE_H
#include <stdbool.h>
/**
 * Tipo opaco que representa un objeto JSON parseado.
 */
typedef struct json json_t;
/**
 * Tipos de valores JSON soportados.
 */
typedef enum
{
    JSON_TIPO_CADENA,
    JSON_TIPO_NUMERO,
    JSON_TIPO_INVALIDO
} json_tipo_t;
/**
 * Carga y parsea un archivo JSON.
 *
 * @param ruta_archivo Ruta al archivo JSON a cargar.
 * @returns Puntero al objeto JSON parseado, o NULL si falla.
 * @pre ruta_archivo != NULL
 * @post El llamador debe liberar con json_destruir().
 *       Si retorna NULL, usar json_obtener_error() para detalles.
 */
json_t *json_cargar(const char *ruta_archivo);
/**
 * Parsea una cadena JSON.
 *
 * @param contenido Cadena con el contenido JSON.
 * @returns Puntero al objeto JSON parseado, o NULL si falla.
 * @pre contenido != NULL
 * @post El llamador debe liberar con json_destruir().
 */
json_t *json_parsear(const char *contenido);
/**
 * Destruye un objeto JSON y libera sus recursos.
 *
 * @param json Objeto JSON a destruir.
 * @post El puntero json queda inválido.
 */
void json_destruir(json_t *json);
/**
 * Verifica si una clave existe en el objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave a buscar.
 * @returns true si la clave existe, false en caso contrario.
 * @pre json != NULL, clave != NULL
 */
bool json_existe(const json_t *json, const char *clave);
/**
 * Obtiene el tipo de valor asociado a una clave.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @returns Tipo del valor, o JSON_TIPO_INVALIDO si la clave no existe.
 * @pre json != NULL, clave != NULL
 */
json_tipo_t json_obtener_tipo(const json_t *json, const char *clave);
/**
 * Obtiene un valor de cadena del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @param valor_defecto Valor a retornar si la clave no existe o no es cadena.
 * @returns Valor de la clave como cadena, o valor_defecto.
 * @pre json != NULL, clave != NULL
 * @post La cadena retornada es propiedad del objeto JSON.
 */
const char *json_obtener_cadena(const json_t *json, const char *clave,
                                const char *valor_defecto);
/**
 * Obtiene un valor numérico del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @param clave Nombre de la clave.
 * @param valor_defecto Valor a retornar si la clave no existe o no es número.
 * @returns Valor de la clave como double, o valor_defecto.
 * @pre json != NULL, clave != NULL
 */
double json_obtener_numero(const json_t *json, const char *clave,
                           double valor_defecto);
/**
 * Obtiene el número de pares clave-valor en el objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @returns Número de claves en el objeto.
 * @pre json != NULL
 */
size_t json_obtener_num_claves(const json_t *json);
/**
 * Obtiene todas las claves del objeto JSON.
 *
 * @param json Objeto JSON a consultar.
 * @returns Vector de cadenas con las claves, terminado en NULL.
 * @pre json != NULL
 * @post El vector retornado es propiedad del objeto JSON.
 */
const char **json_obtener_claves(const json_t *json);
/**
 * Obtiene el mensaje del último error de parseo.
 *
 * @returns Cadena con el mensaje de error, o NULL si no hubo error.
 * @post La cadena es propiedad de la librería y válida hasta la
 *       próxima operación que pueda generar error.
 */
const char *json_obtener_error(void);
#endif // JSON_SIMPLE_H
```
<!-- {code-block} c -->

**Notas sobre el diseño:**

- Se usa `json_obtener_error()` como función global para obtener errores,
  similar a `errno` en la biblioteca estándar de C.
- Los valores por defecto permiten un uso simple sin necesidad de verificar
  siempre si una clave existe.
- El uso consistente de `const` indica qué funciones modifican el objeto y qué
  datos son propiedad de la librería.
- La API es minimalista pero extensible: se podrían agregar funciones para
  soportar arrays, booleanos, y null en futuras versiones.

::::
<!-- {solution} api_json_simple -->

(performance-y-apis-el-costo-de-la-abstraccion)=
## Performance y APIs: El Costo de la Abstracción

Una preocupación legítima al diseñar APIs con múltiples capas de abstracción es
el impacto en el rendimiento. ¿Cuánto cuesta la llamada a función indirecta?
¿Vale la pena el overhead?

(el-mito-de-la-abstraccion-costosa)=
### El Mito de la Abstracción Costosa

En sistemas modernos, el costo de una llamada a función bien diseñada es
despreciable en la vasta mayoría de los casos. Knuth [@knuth1974] famosamente
advirtió: "La optimización prematura es la raíz de todos los males" (*"premature
optimization is the root of all evil"*). Esta observación, basada en décadas de
experiencia, enfatiza que el tiempo de desarrollo debe invertirse en claridad y
corrección antes que en optimizaciones especulativas.

El compilador moderno realiza optimizaciones agresivas que eliminan gran parte
del overhead de la abstracción, incluyendo:

- **Inlining**: Funciones pequeñas y frecuentemente llamadas se insertan
  directamente en el sitio de llamada, eliminando completamente el overhead de
  la llamada a función. Los compiladores modernos con optimización `-O2` o
  superior realizan inlining automático basado en heurísticas de
  costo-beneficio.

- **Link-Time Optimization (LTO)**: Optimizaciones entre unidades de
  compilación, permitiendo inlining incluso de funciones definidas en otros
  archivos objeto. LTO permite al compilador tener una visión global del
  programa y tomar decisiones de optimización más informadas.

- **Constant Propagation y Dead Code Elimination**: El compilador puede propagar
  constantes a través de llamadas a función y eliminar código que nunca se
  ejecuta, reduciendo dramáticamente el tamaño y mejorando la localidad del
  cache.

Un estudio de Mytkowicz et al. [@mytkowicz2009] demostró que diferencias en
performance son frecuentemente atribuidas incorrectamente a causas obvias (como
llamadas a función), cuando en realidad factores como la alineación de código en
memoria, el estado del cache, y efectos del layout de memoria tienen impactos
más significativos. Este estudio es una advertencia sobre la importancia de
medir, no asumir.

:::{important}

**Regla de Oro: Medir, No Asumir**

Antes de sacrificar claridad por performance:

1. **Perfilá** (*profile*) tu código con herramientas como `gprof`, `perf`, o
   Valgrind/Callgrind [@nethercote2007].
2. **Identificá** los verdaderos cuellos de botella (*hotspots*). Típicamente,
   el 90% del tiempo se gasta en el 10% del código.
3. **Optimizá** solo ese 10%, manteniendo el resto del código claro y
   mantenible.
4. **Verificá** que la optimización realmente mejoró el rendimiento de forma
   significativa.

Como observa Martin [@martin2008], "El código limpio es más fácil de optimizar
que el código sucio", porque es más fácil identificar y modificar las partes
críticas cuando el código es comprensible.

:::
<!-- {important} -->

(cuando-preocuparse-por-performance)=
### Cuándo Preocuparse por Performance

La performance sí importa en contextos específicos:

1. **Lazos Internos Críticos (_Hot Paths_)**: Código que se ejecuta millones o
   miles de millones de veces por segundo, como kernels de procesamiento de
   señales, codecs de video/audio, motores de rendering 3D, o algoritmos
   criptográficos. En estos casos, incluso el overhead de una única instrucción
   puede acumularse significativamente.

2. **Sistemas de Tiempo Real Duro**: Donde límites temporales estrictos
   (*deadlines*) son obligatorios y su incumplimiento puede tener consecuencias
   catastróficas (sistemas de control industrial, aviación, dispositivos
   médicos). En estos sistemas, no solo importa la performance promedio, sino
   también la varianza y el peor caso (*worst-case execution time*, WCET).

3. **Sistemas Embebidos con Recursos Limitados**: Microcontroladores con
   kilobytes de RAM y megahertz de clock, donde cada byte de código y cada ciclo
   de CPU cuenta. En estos entornos, las asignaciones dinámicas pueden estar
   completamente prohibidas.

4. **Algoritmos de Complejidad Crítica**: Cuando la elección de estructura de
   datos o algoritmo afecta la complejidad asintótica (por ejemplo, $O(n)$ vs.
   $O(n^2)$), el diseño de la API debe facilitar el uso eficiente, no
   obstaculizarlo.

En estos casos, las APIs pueden exponer versiones "unsafe" optimizadas junto a
versiones "safe" con verificaciones completas:

```{code-block} c
:linenos:
// Versión con verificaciones completas: segura pero más lenta
bool lista_insertar(lista_t *lista, size_t pos, void *elem);
// Versión sin verificaciones para lazos críticos: rápida pero peligrosa
// PRECONDICIÓN: pos < lista->tamanio, lista != NULL, elem != NULL
// El incumplimiento de las precondiciones resulta en comportamiento indefinido
void lista_insertar_unsafe(lista_t *lista, size_t pos, void *elem);
```
<!-- {code-block} c -->

Esta estrategia es común en bibliotecas de sistemas. Por ejemplo, la librería
estándar de C ofrece `strcpy` (rápida pero peligrosa) y `strncpy` (más segura
pero requiere especificar tamaño). Bibliotecas modernas como OpenSSL exponen
APIs de alto nivel simples para casos comunes y APIs de bajo nivel complejas
para casos que requieren máximo control.

(testing-de-apis-validacion-del-contrato)=
### Testing de APIs: Validación del Contrato

El testing de una API no solo verifica que el código funciona, sino que valida
que el *contrato* se cumple. Beck [@beck2002] popularizó el desarrollo guiado
por tests (*Test-Driven Development*, TDD), donde los tests se escriben antes
que el código de producción, sirviendo como especificación ejecutable.

**Niveles de testing para APIs:**

1. **Tests de Contrato**: Verifican que las precondiciones, poscondiciones e
   invariantes documentados se cumplen. Por ejemplo, si la documentación dice
   que `lista_crear()` retorna `NULL` en caso de fallo, debe haber un test que
   verifique este comportamiento.

2. **Tests de Casos Límite**: Proban comportamiento en fronteras (listas vacías,
   tamaño máximo, valores nulos, etc.). Muchos bugs se esconden en estos casos
   extremos.

3. **Tests de Estrés**: Crean miles de objetos, realizan millones de
   operaciones, buscan fugas de memoria con Valgrind [@nethercote2007].

4. **Tests de Uso Incorrecto**: Verifican que la API se comporta razonablemente
   (idealmente, falla de forma predecible) cuando se usa incorrectamente. Por
   ejemplo, pasar `NULL` donde no está permitido debería causar un `assert` en
   modo debug, no un crash silencioso.

```{code-block} c
:linenos:
// Ejemplo de test de contrato
void test_lista_agregar_retorna_true_en_exito(void)
{
    lista_t *lista = lista_crear();
    assert(lista != NULL);
    // Postcondición: agregar elemento debe retornar true
    bool resultado = lista_agregar(lista, 42);
    assert(resultado == true);
    // Invariante: el tamaño debe incrementarse
    assert(lista_largo(lista) == 1);
    lista_destruir(lista);
}
```
<!-- {code-block} c -->

**Property-Based Testing:**

Una técnica avanzada, popularizada por QuickCheck [@claessen2000], genera
automáticamente cientos de casos de test basados en propiedades declaradas. Por
ejemplo, para una lista: "agregar N elementos y luego consultar el largo debe
retornar N".

(documentacion-de-apis-el-contrato-escrito)=
## Documentación de APIs: El Contrato Escrito

La documentación no es opcional; es parte integral del contrato entre la API y
sus usuarios. Una función sin documentación es una función cuyo comportamiento
es indefinido desde la perspectiva del usuario.

(elementos-esenciales-de-documentacion)=
### Elementos Esenciales de Documentación

Cada función pública debe documentar:

1. **Propósito**: ¿Qué hace la función en términos de alto nivel?
2. **Parámetros**: Significado, unidades, restricciones de cada parámetro.
3. **Valor de Retorno**: Qué representa, qué valores son posibles.
4. **Precondiciones**: Qué debe ser verdadero antes de llamar la función.
5. **Poscondiciones**: Qué será verdadero después de que la función retorne
   exitosamente.
6. **Efectos Secundarios**: ¿Modifica argumentos? ¿Accede a recursos externos?
7. **Gestión de Memoria**: ¿Quién aloja? ¿Quién libera?
8. **Manejo de Errores**: ¿Cómo reporta errores? ¿Qué errores son posibles?
9. **Thread-Safety**: ¿Es seguro llamar desde múltiples hilos concurrentemente?
10. **Complejidad**: Si es relevante, complejidad temporal y espacial ($O(n)$,
    etc.).

(formato-de-documentacion-doxygen)=
### Formato de Documentación: Doxygen

Doxygen [@doxygen2023] es el estándar de facto para documentación de APIs en
C/C++. Usa comentarios especialmente formateados que pueden ser procesados para
generar HTML, PDF, y man pages.

```{code-block} c
:linenos:
/**
 * @brief Busca un elemento en una lista ordenada usando búsqueda binaria.
 *
 * Esta función implementa el algoritmo de búsqueda binaria, que requiere
 * que la lista esté ordenada en orden ascendente.
 *
 * @param lista Lista donde buscar. Debe estar ordenada.
 * @param elemento Elemento a buscar.
 * @param[out] indice_out Si no es NULL y se encuentra el elemento,
 *                        se almacena aquí el índice donde fue encontrado.
 *
 * @return true si el elemento fue encontrado, false en caso contrario.
 *
 * @pre lista != NULL
 * @pre La lista debe estar ordenada en orden ascendente.
 * @post Si retorna true, *indice_out contiene el índice del elemento.
 * @post La lista no es modificada.
 *
 * @note Complejidad: O(log n) donde n es el tamaño de la lista.
 * @note Thread-safe: Sí, siempre que no se modifique la lista
 * concurrentemente.
 *
 * @see lista_ordenar() para ordenar una lista antes de buscar.
 */
bool lista_buscar_binaria(const lista_t *lista, int elemento,
                          size_t *indice_out);
```
<!-- {code-block} c -->

Esta documentación es exhaustiva pero necesaria. Comunica el contrato completo y
permite al usuario de la API trabajar con confianza.

(estudio-de-caso-apis-exitosas-en-la-practica)=
## Estudio de Caso: APIs Exitosas en la Práctica

Analizar APIs exitosas y ampliamente adoptadas revela patrones comunes y
lecciones valiosas.

(posix-el-estandar-de-facto)=
### POSIX: El Estándar de Facto

POSIX (Portable Operating System Interface) [@ieee2018] es quizás el ejemplo más
exitoso de diseño de API en C. Define interfaces estándar para interacción con
el sistema operativo (archivos, procesos, hilos, señales, etc.) que han sido
adoptadas por prácticamente todos los sistemas Unix-like y muchos otros.

**Principios de diseño de POSIX:**

- **Simplicidad Conceptual**: Las abstracciones son pocas pero poderosas.
  "Everything is a file" permite unificar E/S de archivos, dispositivos, pipes y
  sockets bajo una interfaz común (`open`, `read`, `write`, `close`).

- **Composabilidad**: Los programas POSIX están diseñados para ser combinados
  mediante pipes y redirección. Esta filosofía, heredada de Unix [@raymond2003],
  enfatiza hacer una cosa y hacerla bien.

- **Gestión Explícita de Errores**: Todas las funciones que pueden fallar
  retornan valores que indican éxito o fracaso, y establecen la variable global
  `errno` con detalles del error. Aunque el uso de una variable global para
  errores es controversial (viola el principio de estado explícito), ha probado
  ser práctico en contexto de llamadas al sistema.

- **Estabilidad a Largo Plazo**: POSIX ha mantenido compatibilidad hacia atrás
  por décadas. Código escrito para POSIX en los 80s frecuentemente compila y
  ejecuta sin cambios en sistemas modernos.

**Lecciones:**

- La estabilidad y compatibilidad a largo plazo son más valiosas que la
  perfección teórica. Una API "suficientemente buena" que se mantiene estable es
  preferible a una API "perfecta" que cambia constantemente.

- Las abstracciones simples y uniformes (como el descriptor de archivo) pueden
  aplicarse a dominios inesperados, aumentando la utilidad de la API más allá de
  sus casos de uso originales.

La API POSIX [@ieee2018] define interfaces para sistemas Unix-like y ha
sobrevivido décadas. Sus lecciones:

- **Simplicidad**: Funciones hacen una cosa y la hacen bien (`fopen`, `read`,
  `write`).
- **Composabilidad**: Funciones pequeñas se combinan para crear funcionalidad
  compleja.
- **Consistencia**: Patrones repetidos (descriptores de archivo, códigos de
  error) facilitan el aprendizaje.

(sqlite-la-libreria-mas-deployada-del-mundo)=
### SQLite: La Librería más Deployada del Mundo

SQLite [@hipp2020] es probablemente la librería C más ampliamente desplegada en
el planeta. Se encuentra en miles de millones de dispositivos: smartphones,
navegadores web, sistemas operativos, aviones, y prácticamente cualquier sistema
que necesite almacenar datos estructurados localmente. Su éxito se debe en gran
parte a decisiones de diseño deliberadas:

**Principios de diseño de SQLite:**

- **Zero Configuration**: No requiere instalación, configuración ni
  administración de servidor. La librería es completamente autocontenida.

- **Single File Database**: Toda la base de datos (tablas, índices, schema,
  datos) reside en un único archivo del sistema operativo, facilitando backup,
  transferencia y versionado.

- **API Minimalista pero Poderosa**: Pocas funciones esenciales (`sqlite3_open`,
  `sqlite3_exec`, `sqlite3_prepare_v2`, `sqlite3_step`, `sqlite3_finalize`)
  permiten realizar operaciones SQL completas. La API es fácil de aprender pero
  suficientemente expresiva para casos de uso avanzados.

- **Backward Compatibility Extrema**: SQLite mantiene un compromiso de
  compatibilidad hacia atrás virtualmente infinito. Bases de datos creadas hace
  20 años pueden ser leídas por versiones modernas sin conversión. Este
  compromiso es posible gracias al uso de punteros opacos y al diseño cuidadoso
  de la ABI.

- **Testing Exhaustivo**: SQLite tiene una cobertura de testing que excede el
  100% del código (más líneas de test que de código producto), incluyendo
  testing de errores de hardware y condiciones excepcionales [@hipp2020].

Richard Hipp, creador de SQLite, enfatiza que "SQLite es software embebido, no
un producto con clientes". Esta filosofía de diseño como componente
reutilizable, no como servicio independiente, informa cada decisión de API. El
objetivo es que SQLite "simplemente funcione" sin que el usuario tenga que
pensar en ella.

(git-porcelain-vs-plumbing)=
### Git: Porcelain vs Plumbing

Git [@chacon2014] es el sistema de control de versiones más utilizado del mundo.
Su diseño de API es notable por la separación explícita en dos niveles de
abstracción:

**Arquitectura de dos niveles:**

- **Plumbing (Fontanería)**: Comandos de bajo nivel, estables y diseñados para
  scripting y automatización. Ejemplos: `git hash-object`, `git cat-file`, `git
  update-index`. Estos comandos exponen directamente los objetos internos de Git
  (blobs, trees, commits) y garantizan estabilidad de interfaz a largo plazo.

- **Porcelain (Porcelana)**: Comandos de alto nivel, user-friendly, diseñados
  para uso humano. Ejemplos: `git add`, `git commit`, `git push`. Estos comandos
  pueden cambiar su comportamiento o flags en nuevas versiones para mejorar la
  experiencia de usuario.

**Lecciones de diseño:**

Esta separación es brillante porque permite:

1. **Evolución de UX**: Los comandos de alto nivel pueden mejorar (mejor
   mensajes de error, nuevos flags, comportamiento más intuitivo) sin romper
   scripts y herramientas que dependen de Git.

2. **Estabilidad para Automatización**: Scripts y herramientas de terceros
   pueden confiar en que los comandos de *plumbing* mantendrán su comportamiento
   indefinidamente.

3. **Acceso a Primitivas**: Usuarios avanzados y herramientas pueden construir
   funcionalidad compleja combinando comandos de bajo nivel.

El diseño de Git demuestra que no es necesario elegir entre simplicidad para
principiantes y poder para expertos. Una API puede ofrecer ambos mediante
niveles de abstracción apropiados, cada uno con su propio contrato de
estabilidad.

(conclusion-disenar-para-el-usuario)=
## Conclusión: Diseñar para el Usuario

El diseño de una buena interfaz en C es un ejercicio de empatía y disciplina.
Requiere que te pongas en el lugar del programador que utilizará tu código. ¿Es
la interfaz clara? ¿Es predecible? ¿Es segura? ¿Oculta la complejidad
innecesaria?

Al aplicar estos principios y las reglas de estilo, no solo estarás creando
funciones, sino componentes de software robustos, modulares y profesionales.
Estarás construyendo "contratos" en los que otros desarrolladores pueden
confiar, asegurando la mantenibilidad y longevidad de tu código.

Como observa Stroustrup [@stroustrup2012], diseñador de C++: "El diseño de
bibliotecas es el diseño de lenguajes". Una buena API extiende el lenguaje con
un vocabulario nuevo, expresivo y coherente para resolver problemas de un
dominio específico.

(principios-clave-a-recordar)=
### Principios Clave a Recordar

1. **Claridad sobre Cleverness**: Un código claro y simple es superior a uno
   "inteligente" pero difícil de entender. Como dice la regla {ref}`0x0001h`, la
   claridad y prolijidad son fundamentales.

2. **Contratos Explícitos**: Las precondiciones y poscondiciones no son
   decoración, son especificaciones formales del comportamiento esperado.

3. **Encapsulamiento Riguroso**: La información que no necesita ser pública, no
   debe serlo. Los tipos opacos son tu herramienta principal para lograr esto.

4. **Errores sin Sorpresas**: Los errores deben ser reportados de manera
   predecible y consistente. El usuario de tu API debe poder manejarlos de forma
   adecuada a su contexto.

5. **Evolución Controlada**: Una API bien diseñada puede evolucionar sin romper
   código existente, mediante deprecación gradual y versionado semántico.

6. **Testing como Diseño**: Los tests no solo verifican corrección; informan y
   validan el diseño desde la perspectiva del usuario.

7. **Performance Consciente pero no Obsesiva**: Optimizá lo que importa, después
   de medir. La claridad y corrección primero, optimización después.

El dominio de estos principios te diferencia de un programador amateur de uno
profesional. Es la diferencia entre escribir código que funciona hoy y escribir
código que seguirá siendo valioso dentro de años.

(referencias-adicionales-y-lecturas-recomendadas)=
## Referencias Adicionales y Lecturas Recomendadas

Para profundizar en los temas tratados, se recomiendan las siguientes lecturas:

- **"The C Programming Language"** [@kernighan1988]: El libro definitivo sobre
  C, escrito por los creadores del lenguaje.
- **"Expert C Programming: Deep C Secrets"** [@linden1994]: Discute sutilezas y
  patrones idiomáticos avanzados de C.
- **"Large-Scale C++ Software Design"** [@lakos1996]: Aunque enfocado en C++,
  muchos principios aplican directamente a C, especialmente sobre diseño modular
  y gestión de dependencias.
- **"The Art of Unix Programming"** [@raymond2003]: Filosofía y principios de
  diseño de software Unix, altamente relevante para APIs en C.
- **"API Design for C++"** [@reddy2011]: Exhaustivo tratamiento de diseño de
  APIs, con muchos principios aplicables a C.
- **"Code Complete"** [@mcconnell_code_2004]: Guía comprensiva de construcción
  de software de alta calidad.
- **"Clean Code"** [@martin2008]: Principios de código limpio y mantenible.

---

:::{tip} Estilo

En este apunte se aplicaron los principios de diseño de APIs descriptos en las
reglas {ref}`0x0001h` (claridad y prolijidad), {ref}`0x0101h` (nomenclatura),
{ref}`0x0201h` (documentación), y {ref}`0x3002h` (gestión de memoria),
demostrando su aplicación práctica en el diseño de interfaces profesionales.

:::
<!-- {tip} Estilo -->
