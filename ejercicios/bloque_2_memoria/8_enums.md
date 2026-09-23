---
title: "Ejercicios de enumeraciones"
short_title: "10. enum/struct/union"
---

# Ejercicios de enumeraciones

## Acerca de

Estos ejercicios te permitirán practicar y consolidar el uso de enumeraciones
(`enum`), estructuras (`struct`) y uniones (`union`) en C, desde conceptos
básicos hasta aplicaciones avanzadas en el modelado de estados y la
configuración de sistemas.

Para profundizar en los conceptos teóricos, podés consultar el siguiente
capítulo del apunte:
- [Enumeraciones y Estructuras de
  Datos](../../apunte/bloque_2_memoria/11_enums.md)

## Días de la Semana

Crear un tipo `enum` para representar los días de la semana y funciones básicas
para trabajar con ellos.

```{code-block} c
:linenos:
enum dia_semana
{
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};
```
<!-- {code-block} c -->
(ejercicio_20_1)=
### Ejercicio 20.1 - Día siguiente ⭐⭐☆☆☆

Implementar una función que retorne el día siguiente al día proporcionado. El
día siguiente a `DOMINGO` es `LUNES`.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
enum dia_semana dia_siguiente(enum dia_semana dia_actual);
```
<!-- c -->
(ejercicio_20_2)=
### Ejercicio 20.2 - Es día laboral ⭐⭐☆☆☆

Implementar una función que determine si un día es laboral (lunes a viernes).


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool es_dia_laboral(enum dia_semana dia);
```
<!-- c -->
(ejercicio_20_3)=
### Ejercicio 20.3 - Nombre del día ⭐⭐☆☆☆

Implementar una función que retorne el nombre del día como cadena de texto. Esta
función ilustra el patrón de conversión enum-a-string.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
const char *nombre_dia(enum dia_semana dia);
```
<!-- c -->

## Estados de Conexión

Modelar los estados de una conexión de red usando enumeraciones.

```{code-block} c
:linenos:
enum estado_red
{
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    DESCONECTANDO,
    ERROR_TIMEOUT,
    ERROR_AUTH
};
```
<!-- {code-block} c -->
(ejercicio_20_4)=
### Ejercicio 20.4 - Máquina de estados ⭐⭐⭐☆☆

Implementar una función que procese transiciones de estado. La función debe
recibir el estado actual y un evento, y retornar el nuevo estado según las
reglas de transición.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum evento_red
{
    EVENTO_CONECTAR,
    EVENTO_DESCONECTAR,
    EVENTO_TIMEOUT,
    EVENTO_ERROR
};
enum estado_red procesar_evento(enum estado_red estado,
                                enum evento_red evento);
```
<!-- {code-block} c -->

**Reglas de transición sugeridas:**
- `DESCONECTADO` + `EVENTO_CONECTAR` → `CONECTANDO`
- `CONECTANDO` + `EVENTO_TIMEOUT` → `ERROR_TIMEOUT`
- `CONECTANDO` + `EVENTO_ERROR` → `ERROR_AUTH`
- `CONECTADO` + `EVENTO_DESCONECTAR` → `DESCONECTANDO`
- `DESCONECTANDO` + transición completa → `DESCONECTADO`
(ejercicio_20_5)=
### Ejercicio 20.5 - Validación de estado ⭐⭐⭐☆☆

Implementar una función que valide si un valor numérico corresponde a un estado
válido de la enumeración. Usar el patrón del valor centinela.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum estado_red
{
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    DESCONECTANDO,
    ERROR_TIMEOUT,
    ERROR_AUTH,
    _ESTADO_MAX // Valor centinela
};
bool estado_valido(int valor);
```
<!-- {code-block} c -->

## Sistema de Permisos con Flags

Implementar un sistema de permisos usando flags de bits. Este ejercicio
demuestra cómo combinar múltiples opciones en un único valor.

```{code-block} c
:linenos:
enum permisos
{
    PERMISO_LECTURA = 1 << 0,   // 0x01
    PERMISO_ESCRITURA = 1 << 1, // 0x02
    PERMISO_EJECUCION = 1 << 2, // 0x04
    PERMISO_ELIMINAR = 1 << 3   // 0x08
};
```
<!-- {code-block} c -->
(ejercicio_20_6)=
### Ejercicio 20.6 - Verificar permiso ⭐⭐☆☆☆

Implementar una función que verifique si un conjunto de permisos incluye un
permiso específico.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool tiene_permiso(unsigned int permisos_actuales, enum permisos permiso);
```
<!-- c -->
(ejercicio_20_7)=
### Ejercicio 20.7 - Agregar y quitar permisos ⭐⭐☆☆☆

Implementar funciones para modificar el conjunto de permisos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
unsigned int agregar_permiso(unsigned int permisos, enum permisos nuevo);
unsigned int quitar_permiso(unsigned int permisos, enum permisos remover);
```
<!-- c -->
(ejercicio_20_8)=
### Ejercicio 20.8 - Listar permisos activos ⭐⭐☆☆☆

Implementar una función que imprima todos los permisos activos en un conjunto de
permisos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void mostrar_permisos(unsigned int permisos);
```
<!-- c -->

## Colores RGB con Enum

Definir una enumeración para colores predefinidos y una estructura para
representar colores RGB personalizados.

```{code-block} c
:linenos:
enum color_predefinido
{
    COLOR_NEGRO,
    COLOR_BLANCO,
    COLOR_ROJO,
    COLOR_VERDE,
    COLOR_AZUL,
    COLOR_AMARILLO,
    COLOR_MAGENTA,
    COLOR_CIAN
};
typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_t;
```
<!-- {code-block} c -->
(ejercicio_20_9)=
### Ejercicio 20.9 - Conversión de color predefinido a RGB ⭐⭐☆☆☆

Implementar una función que convierta un color predefinido a sus componentes
RGB.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
rgb_t color_a_rgb(enum color_predefinido color);
```
<!-- c -->

**Valores sugeridos:**
- `COLOR_ROJO`: (255, 0, 0)
- `COLOR_VERDE`: (0, 255, 0)
- `COLOR_AZUL`: (0, 0, 255)
- `COLOR_AMARILLO`: (255, 255, 0)
(ejercicio_20_10)=
### Ejercicio 20.10 - Mezcla de colores ⭐⭐☆☆☆

Implementar una función que mezcle dos colores RGB usando promedio aritmético.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
rgb_t mezclar_colores(rgb_t c1, rgb_t c2);
```
<!-- c -->

## Configuración de Dispositivo con Unión Etiquetada

Implementar una unión etiquetada para almacenar diferentes tipos de
configuración de dispositivos.

```{code-block} c
:linenos:
enum tipo_dispositivo
{
    DISPOSITIVO_SENSOR_TEMP,
    DISPOSITIVO_MOTOR,
    DISPOSITIVO_LED
};
typedef struct
{
    double temperatura_min;
    double temperatura_max;
} config_sensor_t;
typedef struct
{
    unsigned int velocidad_rpm;
    bool direccion_horaria;
} config_motor_t;
typedef struct
{
    unsigned char intensidad;
    enum color_predefinido color;
} config_led_t;
typedef struct
{
    enum tipo_dispositivo tipo;
    union
    {
        config_sensor_t sensor;
        config_motor_t motor;
        config_led_t led;
    } config;
} dispositivo_t;
```
<!-- {code-block} c -->
(ejercicio_20_11)=
### Ejercicio 20.11 - Configurar dispositivo ⭐⭐☆☆☆

Implementar funciones para configurar cada tipo de dispositivo de forma segura.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
dispositivo_t crear_sensor(double temp_min, double temp_max);
dispositivo_t crear_motor(unsigned int rpm, bool horario);
dispositivo_t crear_led(unsigned char intensidad,
                        enum color_predefinido color);
```
<!-- c -->
(ejercicio_20_12)=
### Ejercicio 20.12 - Imprimir configuración ⭐⭐☆☆☆

Implementar una función que imprima la configuración de un dispositivo según su
tipo. Este ejercicio demuestra el uso correcto de uniones etiquetadas.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar el retorno de asignación de memoria y
    garantizar la liberación total de recursos en caso de error.
-   **[*plus ultra*]:** Verificar la ausencia de fugas de memoria (*memory
    leaks*) mediante Valgrind o AddressSanitizer.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void imprimir_dispositivo(const dispositivo_t *dispositivo);
```
<!-- c -->

## Códigos de Error

Definir una enumeración exhaustiva para códigos de error de un sistema.

```{code-block} c
:linenos:
enum codigo_error
{
    ERROR_NINGUNO = 0,
    ERROR_MEMORIA,
    ERROR_ARCHIVO_NO_ENCONTRADO,
    ERROR_PERMISO_DENEGADO,
    ERROR_ARGUMENTO_INVALIDO,
    ERROR_TIMEOUT,
    ERROR_CONEXION,
    ERROR_DESCONOCIDO
};
```
<!-- {code-block} c -->
(ejercicio_20_13)=
### Ejercicio 20.13 - Mensaje de error ⭐⭐☆☆☆

Implementar una función que retorne un mensaje descriptivo para cada código de
error.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
const char *mensaje_error(enum codigo_error error);
```
<!-- c -->
(ejercicio_20_14)=
### Ejercicio 20.14 - Tipo de resultado ⭐⭐⭐☆☆

Implementar un tipo `resultado_t` que encapsule un valor de retorno o un código
de error usando unión etiquetada.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    enum codigo_error error;
    union
    {
        int valor_int;
        double valor_double;
        void *valor_ptr;
    } datos;
} resultado_t;
```
<!-- {code-block} c -->

Implementar funciones auxiliares:

``` c
resultado_t resultado_ok_int(int valor);
resultado_t resultado_error(enum codigo_error error);
bool resultado_es_error(const resultado_t *resultado);
```
<!-- c -->

## Estados de Reproducción Multimedia

Modelar un reproductor multimedia con estados y modos de reproducción.

```{code-block} c
:linenos:
enum estado_reproductor
{
    ESTADO_DETENIDO,
    ESTADO_REPRODUCIENDO,
    ESTADO_PAUSADO,
    ESTADO_AVANZANDO,
    ESTADO_RETROCEDIENDO
};
enum modo_reproduccion
{
    MODO_NORMAL,
    MODO_REPETIR_UNO,
    MODO_REPETIR_TODOS,
    MODO_ALEATORIO
};
```
<!-- {code-block} c -->
(ejercicio_20_15)=
### Ejercicio 20.15 - Controlador de reproducción ⭐⭐☆☆☆

Implementar una estructura que encapsule el estado completo del reproductor.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    enum estado_reproductor estado;
    enum modo_reproduccion modo;
    unsigned int pista_actual;
    unsigned int total_pistas;
} reproductor_t;
```
<!-- {code-block} c -->
(ejercicio_20_16)=
### Ejercicio 20.16 - Comandos de control ⭐⭐☆☆☆

Implementar funciones para controlar el reproductor.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void reproducir(reproductor_t *rep);
void pausar(reproductor_t *rep);
void detener(reproductor_t *rep);
void siguiente_pista(reproductor_t *rep);
void anterior_pista(reproductor_t *rep);
```
<!-- c -->

Las funciones deben respetar el estado actual y el modo de reproducción.

## Prioridades y Niveles de Log

Implementar un sistema de logging con niveles de prioridad.

```{code-block} c
:linenos:
enum nivel_log
{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
};
```
<!-- {code-block} c -->
(ejercicio_20_17)=
### Ejercicio 20.17 - Filtrado de logs ⭐⭐☆☆☆

Implementar una función que determine si un mensaje debe ser registrado según el
nivel mínimo configurado.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool debe_registrar(enum nivel_log nivel_mensaje, enum nivel_log nivel_minimo);
```
<!-- c -->
(ejercicio_20_18)=
### Ejercicio 20.18 - Formateo de mensaje de log ⭐⭐☆☆☆

Implementar una función que formatee un mensaje de log incluyendo el nivel como
prefijo.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void log_mensaje(enum nivel_log nivel, const char *mensaje);
```
<!-- c -->

Ejemplo de salida: `[ERROR] Archivo no encontrado`

## Protocolo de Comunicación

Diseñar estructuras para un protocolo simple de comunicación usando campos de
bits.

```{code-block} c
:linenos:
enum tipo_mensaje
{
    MSG_DATOS = 0,
    MSG_ACK = 1,
    MSG_NACK = 2,
    MSG_RESET = 3
};
typedef struct
{
    unsigned int tipo : 2;      // 2 bits para tipo (0-3)
    unsigned int prioridad : 2; // 2 bits para prioridad (0-3)
    unsigned int secuencia : 4; // 4 bits para número de secuencia (0-15)
} cabecera_mensaje_t;
```
<!-- {code-block} c -->
(ejercicio_20_19)=
### Ejercicio 20.19 - Crear y decodificar cabecera ⭐⭐☆☆☆

Implementar funciones para construir y extraer información de la cabecera.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
cabecera_mensaje_t crear_cabecera(enum tipo_mensaje tipo,
                                  unsigned int prioridad,
                                  unsigned int secuencia);
void imprimir_cabecera(cabecera_mensaje_t cabecera);
```
<!-- c -->
(ejercicio_20_20)=
### Ejercicio 20.20 - Validación de cabecera ⭐⭐☆☆☆

Implementar una función que valide que los valores de una cabecera están dentro
de los rangos permitidos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool cabecera_valida(cabecera_mensaje_t cabecera);
```
<!-- c -->

## Opciones de Compilación con Flags

Modelar opciones de compilación como flags combinables.

```{code-block} c
:linenos:
enum opcion_compilacion
{
    OPT_NINGUNA = 0,
    OPT_OPTIMIZAR = 1 << 0,      // -O
    OPT_DEBUG = 1 << 1,          // -g
    OPT_WARNINGS = 1 << 2,       // -Wall
    OPT_WARNINGS_EXTRA = 1 << 3, // -Wextra
    OPT_PEDANTIC = 1 << 4        // -pedantic
};
```
<!-- {code-block} c -->
(ejercicio_20_21)=
### Ejercicio 20.21 - Generar línea de comandos ⭐⭐☆☆☆

Implementar una función que genere una cadena con las opciones de compilación
correspondientes a los flags activos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void generar_comando_compilacion(unsigned int opciones, char *buffer,
                                 size_t tam);
```
<!-- c -->

Ejemplo: Si `opciones` tiene `OPT_DEBUG | OPT_WARNINGS`, el buffer debe contener
`"-g -Wall"`.
(ejercicio_20_22)=
### Ejercicio 20.22 - Detectar conflictos ⭐⭐☆☆☆

Implementar una función que detecte combinaciones incompatibles de opciones.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool opciones_compatibles(unsigned int opciones);
```
<!-- c -->

Por ejemplo, `OPT_OPTIMIZAR` y `OPT_DEBUG` podrían considerarse incompatibles en
ciertos contextos.

## Menú de Aplicación

Implementar un sistema de menú interactivo usando enumeraciones.

```{code-block} c
:linenos:
enum opcion_menu
{
    MENU_NUEVO = 1,
    MENU_ABRIR,
    MENU_GUARDAR,
    MENU_CERRAR,
    MENU_SALIR,
    MENU_INVALIDO = -1
};
```
<!-- {code-block} c -->
(ejercicio_20_23)=
### Ejercicio 20.23 - Parser de opción ⭐⭐☆☆☆

Implementar una función que convierta la entrada del usuario en una opción del
menú.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
enum opcion_menu parsear_opcion(int entrada);
```
<!-- c -->
(ejercicio_20_24)=
### Ejercicio 20.24 - Ejecutor de menú ⭐⭐☆☆☆

Implementar una función que ejecute la acción correspondiente a cada opción del
menú.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void ejecutar_opcion(enum opcion_menu opcion);
```
<!-- c -->
(ejercicio_20_25)=
### Ejercicio 20.25 - Menú interactivo completo ⭐⭐☆☆☆

Implementar un lazo principal que muestre el menú, lea la opción del usuario y
ejecute la acción hasta que el usuario seleccione `MENU_SALIR`.

## Tipos de Figuras Geométricas con Unión

Combinar enumeraciones, estructuras y uniones para representar diferentes
figuras geométricas.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum tipo_figura
{
    FIGURA_CIRCULO,
    FIGURA_RECTANGULO,
    FIGURA_TRIANGULO
};
typedef struct
{
    double radio;
} circulo_t;
typedef struct
{
    double base;
    double altura;
} rectangulo_t;
typedef struct
{
    double lado_a;
    double lado_b;
    double lado_c;
} triangulo_t;
typedef struct
{
    enum tipo_figura tipo;
    union
    {
        circulo_t circulo;
        rectangulo_t rectangulo;
        triangulo_t triangulo;
    } datos;
} figura_t;
```
<!-- {code-block} c -->
(ejercicio_20_26)=
### Ejercicio 20.26 - Cálculo de área ⭐⭐☆☆☆

Implementar una función que calcule el área de cualquier figura usando su tipo y
datos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double calcular_area(const figura_t *figura);
```
<!-- c -->

**Fórmulas:**
- Círculo: $A = \pi r^2$
- Rectángulo: $A = base \times altura$
- Triángulo (Fórmula de Herón):
  - $s = \frac{a+b+c}{2}$
  - $A = \sqrt{s(s-a)(s-b)(s-c)}$
(ejercicio_20_27)=
### Ejercicio 20.27 - Constructores de figuras ⭐⭐⭐☆☆

Implementar funciones para crear cada tipo de figura de forma segura.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
figura_t crear_circulo(double radio);
figura_t crear_rectangulo(double base, double altura);
figura_t crear_triangulo(double a, double b, double c);
```
<!-- c -->

## Conversión entre Enums y Strings
(ejercicio_20_28)=
### Ejercicio 20.28 - Tabla de conversión ⭐⭐☆☆☆

Implementar un sistema genérico para convertir entre valores enum y strings
usando tablas de conversión.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    int valor;
    const char *nombre;
} enum_string_t;
// Ejemplo de uso con días de la semana
const enum_string_t tabla_dias[] = {
    {LUNES, "Lunes"},
    {MARTES, "Martes"},
    {MIERCOLES, "Miércoles"},
    // ...
};
```
<!-- {code-block} c -->
(ejercicio_20_29)=
### Ejercicio 20.29 - Funciones de conversión genéricas ⭐⭐☆☆☆

Implementar funciones genéricas que usen la tabla para realizar conversiones.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
const char *enum_a_string(int valor, const enum_string_t *tabla, size_t tam);
int string_a_enum(const char *nombre, const enum_string_t *tabla, size_t tam,
                  int valor_defecto);
```
<!-- c -->

## Estado de Juego

Modelar el estado de un juego simple usando múltiples enumeraciones.

```{code-block} c
:linenos:
enum estado_juego
{
    JUEGO_MENU,
    JUEGO_JUGANDO,
    JUEGO_PAUSADO,
    JUEGO_GAME_OVER,
    JUEGO_VICTORIA
};
enum dificultad
{
    DIFICULTAD_FACIL,
    DIFICULTAD_NORMAL,
    DIFICULTAD_DIFICIL,
    DIFICULTAD_EXPERTO
};
typedef struct
{
    enum estado_juego estado;
    enum dificultad dificultad;
    unsigned int puntuacion;
    unsigned int nivel;
    unsigned int vidas;
} juego_t;
```
<!-- {code-block} c -->
(ejercicio_20_30)=
### Ejercicio 20.30 - Inicializar juego ⭐☆☆☆☆

Implementar una función que inicialice un juego nuevo con la dificultad
especificada.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
juego_t inicializar_juego(enum dificultad dif);
```
<!-- c -->

La dificultad debe afectar el número inicial de vidas y otros parámetros.
(ejercicio_20_31)=
### Ejercicio 20.31 - Gestión de estado ⭐⭐⭐☆☆

Implementar funciones para transiciones de estado comunes.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void pausar_juego(juego_t *juego);
void reanudar_juego(juego_t *juego);
void perder_vida(juego_t *juego);
void ganar_nivel(juego_t *juego);
```
<!-- c -->

## Análisis de Tráfico con Enums Aninados

Modelar un sistema de análisis de tráfico de red con múltiples niveles de
clasificación.

```{code-block} c
:linenos:
enum protocolo
{
    PROTOCOLO_TCP,
    PROTOCOLO_UDP,
    PROTOCOLO_ICMP,
    PROTOCOLO_OTRO
};
enum tipo_trafico
{
    TRAFICO_NORMAL,
    TRAFICO_SOSPECHOSO,
    TRAFICO_MALICIOSO
};
typedef struct
{
    enum protocolo proto;
    enum tipo_trafico tipo;
    unsigned int puerto_origen;
    unsigned int puerto_destino;
    size_t bytes_transferidos;
} paquete_red_t;
```
<!-- {code-block} c -->
(ejercicio_20_32)=
### Ejercicio 20.32 - Clasificador de tráfico ⭐⭐☆☆☆

Implementar una función que clasifique un paquete basándose en reglas
heurísticas.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
enum tipo_trafico clasificar_paquete(const paquete_red_t *paquete);
```
<!-- c -->

**Reglas sugeridas:**
- Puertos conocidos (80, 443, 22) → `TRAFICO_NORMAL`
- Puertos altos no estándar → `TRAFICO_SOSPECHOSO`
- Transferencias muy grandes o patrones anómalos → `TRAFICO_MALICIOSO`
(ejercicio_20_33)=
### Ejercicio 20.33 - Estadísticas por protocolo ⭐⭐⭐☆☆

Implementar una función que cuente paquetes por protocolo en un arreglo de
paquetes.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    unsigned int tcp;
    unsigned int udp;
    unsigned int icmp;
    unsigned int otro;
} estadisticas_protocolo_t;
estadisticas_protocolo_t contar_por_protocolo(const paquete_red_t *paquetes,
                                              size_t cantidad);
```
<!-- {code-block} c -->

## Enums en Sistemas de Archivos
(ejercicio_20_34)=
### Ejercicio 20.34 - Permisos de archivo (UNIX) ⭐⭐☆☆☆

Modelar permisos de archivo estilo UNIX usando flags.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum permiso_unix
{
    OWNER_READ = 0400, // 0100000000 en octal
    OWNER_WRITE = 0200,
    OWNER_EXECUTE = 0100,
    GROUP_READ = 0040,
    GROUP_WRITE = 0020,
    GROUP_EXECUTE = 0010,
    OTHER_READ = 0004,
    OTHER_WRITE = 0002,
    OTHER_EXECUTE = 0001
};
```
<!-- {code-block} c -->

Implementar funciones para manipular permisos:

``` c
bool tiene_permiso_unix(unsigned int permisos, enum permiso_unix permiso);
unsigned int agregar_permiso_unix(unsigned int permisos,
                                  enum permiso_unix nuevo);
void mostrar_permisos_unix(unsigned int permisos); // Formato: rwxr-xr--
```
<!-- c -->
(ejercicio_20_35)=
### Ejercicio 20.35 - Tipos de archivo ⭐⭐☆☆☆

Modelar diferentes tipos de archivo en un sistema de archivos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum tipo_archivo
{
    TIPO_REGULAR,
    TIPO_DIRECTORIO,
    TIPO_ENLACE_SIMBOLICO,
    TIPO_ENLACE_DURO,
    TIPO_DISPOSITIVO,
    TIPO_PIPE,
    TIPO_SOCKET
};
typedef struct
{
    char nombre[256];
    enum tipo_archivo tipo;
    size_t tamanio;
    unsigned int permisos;
} archivo_info_t;
```
<!-- {code-block} c -->

## Sistema de Eventos
(ejercicio_20_36)=
### Ejercicio 20.36 - Tipos de eventos de UI ⭐⭐☆☆☆

Modelar eventos de interfaz de usuario.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum tipo_evento
{
    EVENTO_CLICK,
    EVENTO_DOBLE_CLICK,
    EVENTO_PRESIONAR_TECLA,
    EVENTO_SOLTAR_TECLA,
    EVENTO_MOVER_MOUSE,
    EVENTO_SCROLL
};
enum boton_mouse
{
    BOTON_IZQUIERDO = 1,
    BOTON_DERECHO = 2,
    BOTON_MEDIO = 4
};
typedef struct
{
    enum tipo_evento tipo;
    int x, y;             // Coordenadas
    unsigned int botones; // Flags de botones presionados
    unsigned int tecla;
} evento_t;
```
<!-- {code-block} c -->
(ejercicio_20_37)=
### Ejercicio 20.37 - Procesador de eventos ⭐⭐☆☆☆

Implementar un procesador que maneje diferentes tipos de eventos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void procesar_evento(const evento_t *evento);
```
<!-- c -->

## Estados de Procesos (Sistema Operativo)
(ejercicio_20_38)=
### Ejercicio 20.38 - Modelo de estados ⭐⭐⭐☆☆

Modelar el ciclo de vida de un proceso en un sistema operativo.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum estado_proceso
{
    PROCESO_NUEVO,
    PROCESO_LISTO,
    PROCESO_EJECUTANDO,
    PROCESO_BLOQUEADO,
    PROCESO_TERMINADO
};
enum razon_bloqueo
{
    BLOQ_IO,
    BLOQ_MUTEX,
    BLOQ_SEMAFORO,
    BLOQ_MENSAJE
};
typedef struct
{
    int pid;
    enum estado_proceso estado;
    enum razon_bloqueo razon; // Solo válido si estado == BLOQUEADO
    int prioridad;
} proceso_t;
```
<!-- {code-block} c -->
(ejercicio_20_39)=
### Ejercicio 20.39 - Planificador simple ⭐☆☆☆☆

Implementar funciones de transición de estado para un planificador.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool transicion_estado(proceso_t *proceso, enum estado_proceso nuevo_estado);
bool puede_ejecutar(const proceso_t *proceso);
```
<!-- c -->

## Protocolo HTTP
(ejercicio_20_40)=
### Ejercicio 20.40 - Métodos y códigos HTTP ⭐⭐☆☆☆

Modelar métodos y códigos de estado HTTP.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum metodo_http
{
    HTTP_GET,
    HTTP_POST,
    HTTP_PUT,
    HTTP_DELETE,
    HTTP_PATCH,
    HTTP_HEAD,
    HTTP_OPTIONS
};
enum codigo_http
{
    HTTP_200_OK = 200,
    HTTP_201_CREATED = 201,
    HTTP_204_NO_CONTENT = 204,
    HTTP_301_MOVED = 301,
    HTTP_302_FOUND = 302,
    HTTP_400_BAD_REQUEST = 400,
    HTTP_401_UNAUTHORIZED = 401,
    HTTP_403_FORBIDDEN = 403,
    HTTP_404_NOT_FOUND = 404,
    HTTP_500_INTERNAL_ERROR = 500,
    HTTP_503_UNAVAILABLE = 503
};
```
<!-- {code-block} c -->
(ejercicio_20_41)=
### Ejercicio 20.41 - Parser de respuesta HTTP ⭐⭐☆☆☆

Implementar funciones para trabajar con HTTP.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
const char *metodo_a_string(enum metodo_http metodo);
const char *codigo_a_mensaje(enum codigo_http codigo);
bool es_codigo_exito(enum codigo_http codigo);          // 2xx
bool es_codigo_error_cliente(enum codigo_http codigo);  // 4xx
bool es_codigo_error_servidor(enum codigo_http codigo); // 5xx
```
<!-- c -->

## Semáforo (Sistema de Control)
(ejercicio_20_42)=
### Ejercicio 20.42 - Estados de semáforo ⭐⭐⭐☆☆

Modelar un sistema de semáforo de tráfico.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum estado_semaforo
{
    SEMAFORO_ROJO,
    SEMAFORO_AMARILLO,
    SEMAFORO_VERDE,
    SEMAFORO_INTERMITENTE
};
enum direccion_trafico
{
    DIR_NORTE_SUR,
    DIR_ESTE_OESTE,
    DIR_TODAS
};
typedef struct
{
    enum estado_semaforo estado;
    enum direccion_trafico direccion_activa;
    int tiempo_restante; // Segundos
} semaforo_t;
```
<!-- {code-block} c -->
(ejercicio_20_43)=
### Ejercicio 20.43 - Controlador de semáforo ⭐⭐☆☆☆

Implementar la lógica de transición de un semáforo.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void actualizar_semaforo(semaforo_t *semaforo);
enum estado_semaforo siguiente_estado(enum estado_semaforo actual);
bool puede_pasar(const semaforo_t *semaforo, enum direccion_trafico direccion);
```
<!-- c -->

## Transacciones de Base de Datos
(ejercicio_20_44)=
### Ejercicio 20.44 - Estados de transacción ⭐⭐⭐☆☆

Modelar el ciclo de vida de una transacción.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum estado_transaccion
{
    TX_INICIADA,
    TX_ACTIVA,
    TX_PREPARADA,
    TX_COMPROMETIDA,
    TX_ABORTADA
};
enum tipo_aislamiento
{
    AISLAMIENTO_READ_UNCOMMITTED,
    AISLAMIENTO_READ_COMMITTED,
    AISLAMIENTO_REPEATABLE_READ,
    AISLAMIENTO_SERIALIZABLE
};
typedef struct
{
    unsigned long id;
    enum estado_transaccion estado;
    enum tipo_aislamiento aislamiento;
    int num_operaciones;
} transaccion_t;
```
<!-- {code-block} c -->
(ejercicio_20_45)=
### Ejercicio 20.45 - Gestor de transacciones ⭐⭐☆☆☆

Implementar funciones para gestionar transacciones.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
transaccion_t iniciar_transaccion(enum tipo_aislamiento aislamiento);
bool commit_transaccion(transaccion_t *tx);
bool rollback_transaccion(transaccion_t *tx);
bool puede_hacer_commit(const transaccion_t *tx);
```
<!-- c -->

## Tipos de Datos SQL
(ejercicio_20_46)=
### Ejercicio 20.46 - Tipos de columna ⭐⭐☆☆☆

Modelar tipos de datos SQL y sus propiedades.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum tipo_sql
{
    SQL_INT,
    SQL_BIGINT,
    SQL_FLOAT,
    SQL_DOUBLE,
    SQL_VARCHAR,
    SQL_TEXT,
    SQL_DATE,
    SQL_DATETIME,
    SQL_BOOLEAN,
    SQL_BLOB
};
enum constraint_sql
{
    CONSTRAINT_NINGUNO = 0,
    CONSTRAINT_NOT_NULL = 1 << 0,
    CONSTRAINT_UNIQUE = 1 << 1,
    CONSTRAINT_PRIMARY_KEY = 1 << 2,
    CONSTRAINT_FOREIGN_KEY = 1 << 3,
    CONSTRAINT_AUTO_INCREMENT = 1 << 4
};
typedef struct
{
    char nombre[64];
    enum tipo_sql tipo;
    unsigned int constraints;
    int longitud; // Para VARCHAR
} columna_t;
```
<!-- {code-block} c -->
(ejercicio_20_47)=
### Ejercicio 20.47 - Validación de columnas ⭐⭐☆☆☆

Implementar funciones para validar definiciones de columnas.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool es_tipo_numerico(enum tipo_sql tipo);
bool es_tipo_texto(enum tipo_sql tipo);
bool constraints_validos(unsigned int constraints);
size_t tamanio_tipo(enum tipo_sql tipo);
```
<!-- c -->

## Formatos de Imagen
(ejercicio_20_48)=
### Ejercicio 20.48 - Tipos y formatos ⭐⭐☆☆☆

Modelar diferentes formatos de imagen y sus propiedades.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum formato_imagen
{
    FORMATO_JPEG,
    FORMATO_PNG,
    FORMATO_GIF,
    FORMATO_BMP,
    FORMATO_WEBP,
    FORMATO_TIFF,
    FORMATO_SVG
};
enum modo_color
{
    COLOR_ESCALA_GRISES,
    COLOR_RGB,
    COLOR_RGBA,
    COLOR_CMYK,
    COLOR_INDEXADO
};
typedef struct
{
    enum formato_imagen formato;
    enum modo_color modo;
    int ancho;
    int alto;
    int profundidad_bits;
    bool tiene_transparencia;
    bool es_animado;
} metadata_imagen_t;
```
<!-- {code-block} c -->
(ejercicio_20_49)=
### Ejercicio 20.49 - Análisis de formatos ⭐⭐☆☆☆

Implementar funciones para analizar propiedades de formatos.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
bool soporta_transparencia(enum formato_imagen formato);
bool soporta_animacion(enum formato_imagen formato);
bool es_formato_comprimido(enum formato_imagen formato);
const char *extension_formato(enum formato_imagen formato);
```
<!-- c -->

## Sistema de Notificaciones
(ejercicio_20_50)=
### Ejercicio 20.50 - Niveles de notificación ⭐⭐☆☆☆

Modelar un sistema de notificaciones con prioridades.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum nivel_notificacion
{
    NOTIF_DEBUG,
    NOTIF_INFO,
    NOTIF_ADVERTENCIA,
    NOTIF_ERROR,
    NOTIF_CRITICO
};
enum canal_notificacion
{
    CANAL_NINGUNO = 0,
    CANAL_CONSOLE = 1 << 0,
    CANAL_EMAIL = 1 << 1,
    CANAL_SMS = 1 << 2,
    CANAL_PUSH = 1 << 3,
    CANAL_SYSLOG = 1 << 4
};
typedef struct
{
    enum nivel_notificacion nivel;
    unsigned int canales;
    char mensaje[256];
    time_t timestamp;
} notificacion_t;
```
<!-- {code-block} c -->
(ejercicio_20_51)=
### Ejercicio 20.51 - Gestor de notificaciones ⭐⭐☆☆☆

Implementar funciones para filtrar y enviar notificaciones.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Diseñar la función para devolver un código de estado de
    error e informar el resultado mediante parámetros de salida.
-   **[*plus ultra*]:** Documentar la función con etiquetas Doxygen
    especificando precondiciones y postcondiciones.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void enviar_notificacion(const notificacion_t *notif);
bool debe_notificar(enum nivel_notificacion nivel,
                    enum nivel_notificacion nivel_minimo);
unsigned int canales_para_nivel(enum nivel_notificacion nivel);
```
<!-- c -->

## Compresión de Datos
(ejercicio_20_52)=
### Ejercicio 20.52 - Algoritmos de compresión ⭐⭐☆☆☆

Modelar diferentes algoritmos de compresión y sus niveles.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
enum algoritmo_compresion
{
    COMP_NINGUNO,
    COMP_DEFLATE,
    COMP_GZIP,
    COMP_BZIP2,
    COMP_LZMA,
    COMP_ZSTD,
    COMP_LZ4
};
enum nivel_compresion
{
    NIVEL_MINIMO = 1,
    NIVEL_RAPIDO = 3,
    NIVEL_NORMAL = 5,
    NIVEL_MAXIMO = 9
};
typedef struct
{
    enum algoritmo_compresion algoritmo;
    enum nivel_compresion nivel;
    size_t tamanio_original;
    size_t tamanio_comprimido;
    double ratio; // tamanio_comprimido / tamanio_original
} resultado_compresion_t;
```
<!-- {code-block} c -->
(ejercicio_20_53)=
### Ejercicio 20.53 - Análisis de compresión ⭐⭐☆☆☆

Implementar funciones para analizar rendimiento de compresión.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
double calcular_ratio(const resultado_compresion_t *resultado);
double porcentaje_ahorro(const resultado_compresion_t *resultado);
bool es_algoritmo_rapido(enum algoritmo_compresion alg);
const char *nombre_algoritmo(enum algoritmo_compresion alg);
```
<!-- c -->

## Máquina de Estados Finita Genérica
(ejercicio_20_54)=
### Ejercicio 20.54 - Framework de FSM ⭐⭐☆☆☆

Implementar un framework genérico para máquinas de estados finitas.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
#define MAX_ESTADOS 32
#define MAX_TRANSICIONES 64
typedef enum
{
    FSM_ESTADO_0,
    FSM_ESTADO_1,
    FSM_ESTADO_2,
    // ... más estados
    FSM_ESTADO_MAX
} estado_fsm_t;
typedef enum
{
    FSM_EVENTO_0,
    FSM_EVENTO_1,
    // ... más eventos
    FSM_EVENTO_MAX
} evento_fsm_t;
typedef struct
{
    estado_fsm_t desde;
    estado_fsm_t hasta;
    evento_fsm_t evento;
    void (*accion)(void *contexto);
} transicion_t;
typedef struct
{
    estado_fsm_t estado_actual;
    transicion_t transiciones[MAX_TRANSICIONES];
    int num_transiciones;
    void *contexto;
} maquina_estados_t;
```
<!-- {code-block} c -->
(ejercicio_20_55)=
### Ejercicio 20.55 - Motor de FSM ⭐⭐☆☆☆

Implementar el motor que procesa eventos y ejecuta transiciones.


:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Implementar encapsulamiento completo manteniendo la
    definición interna oculta en el archivo `.c`.
-   **[*plus ultra*]:** Añadir una función de duplicación profunda (*deep copy*)
    para copiar la estructura de forma segura.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
void fsm_inicializar(maquina_estados_t *fsm, estado_fsm_t inicial);
bool fsm_agregar_transicion(maquina_estados_t *fsm, transicion_t trans);
bool fsm_procesar_evento(maquina_estados_t *fsm, evento_fsm_t evento);
estado_fsm_t fsm_estado_actual(const maquina_estados_t *fsm);
```
<!-- c -->

## Análisis Comparativo de Enums
(ejercicio_20_56)=
### Ejercicio 20.56 - Comparación de implementaciones ⭐⭐☆☆☆

Analizar diferentes formas de implementar el mismo concepto:

**Opción 1: Enum simple**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
enum dia
{
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};
```
<!-- c -->

**Opción 2: Enum con valores explícitos**
``` c
enum dia
{
    LUNES = 1,
    MARTES = 2,
    MIERCOLES = 3,
    JUEVES = 4,
    VIERNES = 5,
    SABADO = 6,
    DOMINGO = 7
};
```
<!-- c -->

**Opción 3: Flags con potencias de 2**
``` c
enum dia
{
    LUNES = 1 << 0,
    MARTES = 1 << 1,
    MIERCOLES = 1 << 2,
    JUEVES = 1 << 3,
    VIERNES = 1 << 4,
    SABADO = 1 << 5,
    DOMINGO = 1 << 6
};
```
<!-- c -->

Discutir casos de uso, ventajas y desventajas de cada enfoque.
(ejercicio_20_57)=
### Ejercicio 20.57 - Tamaño y rendimiento ⭐⭐☆☆☆

Investigar y documentar:
- Tamaño en memoria de enums (usualmente `sizeof(int)`)
- Rendimiento de operaciones con enums vs constantes
- Optimizaciones del compilador con enums
- Diferencias entre C y C++ en el manejo de enums

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar el retorno de asignación de memoria y
    garantizar la liberación total de recursos en caso de error.
-   **[*plus ultra*]:** Verificar la ausencia de fugas de memoria (*memory
    leaks*) mediante Valgrind o AddressSanitizer.

:::
<!-- {hint} Lógica y Consideraciones -->

(ejercicio_20_58)=
## Ejercicio 20.58 - Enumeración de Días ⭐☆☆☆☆

Definí una enumeración para días de la semana y mostrá el nombre según el valor.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef enum
{
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
} dia_semana_t;
```
<!-- c -->
- Usá `switch` para convertir enum a string

---
(ejercicio_20_59)=
## Ejercicio 20.59 - Estructura Punto 2D ⭐☆☆☆☆

Definí estructura para punto en 2D y función para calcular distancia entre dos
puntos.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct
{
    double x;
    double y;
} punto_t;
```
<!-- c -->
- Distancia: `sqrt((p2.x - p1.x)² + (p2.y - p1.y)²)`

---
(ejercicio_20_60)=
## Ejercicio 20.60 - Estructura Fecha ⭐⭐☆☆☆

Creá estructura para fecha y función de validación.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct
{
    int dia;
    int mes;
    int anio;
} fecha_t;
```
<!-- c -->
- Validar: 1 ≤ mes ≤ 12, día según mes, considerar bisiestos

---
(ejercicio_20_61)=
## Ejercicio 20.61 - Estructura Persona ⭐⭐☆☆☆

Definí estructura persona y función para mostrar información.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
} persona_t;
```
<!-- c -->
- Función `void mostrar_persona(const persona_t *p)`

---
(ejercicio_20_62)=
## Ejercicio 20.62 - Array de Estructuras ⭐⭐⭐☆☆

Creá array de estudiantes y función para encontrar el de mayor promedio.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct
{
    char nombre[50];
    float promedio;
} estudiante_t;
estudiante_t clase[30];
```
<!-- c -->
- Recorré array comparando promedios

---
(ejercicio_20_63)=
## Ejercicio 20.63 - Enumeración con Valores Explícitos ⭐⭐☆☆☆

Definí enumeración para códigos de error HTTP.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_BAD_REQUEST = 400,
    HTTP_NOT_FOUND = 404,
    HTTP_SERVER_ERROR = 500
} http_status_t;
```
<!-- {code-block} c -->

---
(ejercicio_20_64)=
## Ejercicio 20.64 - Estructura Anidada ⭐⭐⭐☆☆

Creá estructura para dirección y persona que incluya dirección.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    char calle[100];
    int numero;
    char ciudad[50];
} direccion_t;
typedef struct
{
    char nombre[50];
    direccion_t direccion; // Estructura anidada
} persona_t;
```
<!-- {code-block} c -->

---
(ejercicio_20_65)=
## Ejercicio 20.65 - Estructura con Puntero ⭐⭐⭐☆☆

Definí estructura nodo para lista enlazada.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct nodo
{
    int dato;
    struct nodo *siguiente; // Puntero a mismo tipo
} nodo_t;
```
<!-- c -->
- Funciones: crear_nodo, insertar_inicio, mostrar_lista

---
(ejercicio_20_66)=
## Ejercicio 20.66 - Union para Tipos Múltiples ⭐⭐⭐☆☆

Usá union para almacenar valor que puede ser int, float o char.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR
} tipo_t;
typedef struct
{
    tipo_t tipo;
    union
    {
        int i;
        float f;
        char c;
    } valor;
} variable_t;
```
<!-- {code-block} c -->
- El tipo indica cuál campo de la union es válido

---
(ejercicio_20_67)=
## Ejercicio 20.67 - Inicialización Designada ⭐⭐☆☆☆

Practicá diferentes formas de inicializar estructuras.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
// Orden
punto_t p1 = {3.0, 4.0};
// Designadores (C99)
punto_t p2 = {.x = 3.0, .y = 4.0};
punto_t p3 = {.y = 4.0, .x = 3.0}; // Orden no importa
// Parcial (resto en 0)
punto_t p4 = {.x = 3.0};
```
<!-- {code-block} c -->

---
(ejercicio_20_68)=
## Ejercicio 20.68 - Rectángulo con Puntos ⭐⭐⭐☆☆

Definí rectángulo con dos puntos (esquinas opuestas) y calcula área/perímetro.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

``` c
typedef struct
{
    punto_t superior_izq;
    punto_t inferior_der;
} rectangulo_t;
```
<!-- c -->
- Área: ancho × alto
- Perímetro: 2 × (ancho + alto)

---
(ejercicio_20_69)=
## Ejercicio 20.69 - Biblioteca de Libros ⭐⭐⭐⭐☆

Sistema con estructuras para libro, autor, editorial.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    char nombre[50];
    int anio_nacimiento;
} autor_t;
typedef struct
{
    char titulo[100];
    autor_t autor;
    int anio_publicacion;
    float precio;
} libro_t;
```
<!-- {code-block} c -->
- Funciones: buscar por título, filtrar por autor, ordenar por precio

---
(ejercicio_20_70)=
## Ejercicio 20.70 - Enum como Flags (Bits) ⭐⭐⭐⭐☆

Usá enum para permisos de archivo estilo Unix.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar la correcta apertura del archivo y controlar
    errores de E/S con `ferror` y `feof`.
-   **[*plus ultra*]:** Soportar rutas complejas y asegurar el cierre del
    archivo en todos los caminos de ejecución.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    PERM_READ = 1 << 0,    // 0001
    PERM_WRITE = 1 << 1,   // 0010
    PERM_EXECUTE = 1 << 2, // 0100
} permisos_t;
// Combinar permisos con OR
int permisos = PERM_READ | PERM_WRITE;
// Verificar con AND
if (permisos & PERM_READ)
{ /* tiene lectura */
}
```
<!-- {code-block} c -->

---
(ejercicio_20_71)=
## Ejercicio 20.71 - Struct con Padding ⭐⭐⭐⭐☆

Explorá alineación de memoria en estructuras.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Verificar el retorno de asignación de memoria y
    garantizar la liberación total de recursos en caso de error.
-   **[*plus ultra*]:** Verificar la ausencia de fugas de memoria (*memory
    leaks*) mediante Valgrind o AddressSanitizer.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    char c;       // 1 byte + 3 padding
    int i;        // 4 bytes
    char d;       // 1 byte + 3 padding
} mal_alineada_t; // Total: 12 bytes
typedef struct
{
    int i;         // 4 bytes
    char c;        // 1 byte
    char d;        // 1 byte + 2 padding
} bien_alineada_t; // Total: 8 bytes
```
<!-- {code-block} c -->
- Usá `sizeof()` para ver diferencias

---
(ejercicio_20_72)=
## Ejercicio 20.72 - Registro de Paquetes de Red con Enums y Structs ⭐⭐⭐⭐⭐

Implementá un sistema de clasificación y manejo de paquetes de red combinando tipos enumerados y estructuras:

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que los campos de puerto y tamaño se encuentren dentro de los rangos válidos del protocolo.
-   **[*plus ultra*]:** Modularizar la función de formateo para imprimir el paquete como una cadena estructurada.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    PROTO_TCP,
    PROTO_UDP,
    PROTO_ICMP
} protocolo_t;

typedef enum
{
    ESTADO_PENDIENTE,
    ESTADO_EN_TRANSITO,
    ESTADO_ENTREGADO,
    ESTADO_DESCARTADO
} estado_paquete_t;

typedef struct
{
    unsigned int id;
    protocolo_t protocolo;
    estado_paquete_t estado;
    unsigned short puerto_origen;
    unsigned short puerto_destino;
    size_t bytes_datos;
} paquete_red_t;
```
<!-- {code-block} c -->
- Funciones: `paquete_crear`, `paquete_actualizar_estado`, `paquete_mostrar_info`

---
(ejercicio_20_73)=
## Ejercicio 20.73 - Polimorfismo con Union ⭐⭐⭐⭐⭐

Creá sistema de figuras geométricas con union.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    CIRCULO,
    RECTANGULO,
    TRIANGULO
} tipo_figura_t;
typedef struct
{
    punto_t centro;
    double radio;
} circulo_t;
typedef struct
{
    punto_t p1, p2;
} rectangulo_t;
typedef struct
{
    tipo_figura_t tipo;
    union
    {
        circulo_t circulo;
        rectangulo_t rectangulo;
    } datos;
} figura_t;
double calcular_area(const figura_t *f);
```
<!-- {code-block} c -->

---
(ejercicio_20_74)=
## Ejercicio 20.74 - Cola con Struct ⭐⭐⭐⭐☆

Implementá cola FIFO con estructura.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    int *datos;
    int frente;
    int fin;
    int capacidad;
    int tamanio;
} cola_t;
```
<!-- {code-block} c -->
- Funciones: crear, encolar, desencolar, esta_llena, destruir

---
(ejercicio_20_75)=
## Ejercicio 20.75 - Inventario de Dispositivos de Red con Enums y Structs ⭐⭐⭐⭐⭐

Representá un inventario de dispositivos y conexiones con tipos y estados enumerados:

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar que las direcciones IP ingresadas tengan un formato numérico coherente.
-   **[*plus ultra*]:** Implementar una función para listar todos los dispositivos que se encuentren en un estado específico.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    DISP_ROUTER,
    DISP_SWITCH,
    DISP_SERVIDOR,
    DISP_TERMINAL
} tipo_dispositivo_t;

typedef enum
{
    CONEXION_ACTIVA,
    CONEXION_INACTIVA,
    CONEXION_FALLA
} estado_conexion_t;

typedef struct
{
    unsigned int id;
    char hostname[32];
    tipo_dispositivo_t tipo;
    estado_conexion_t estado;
    unsigned int ip;
} dispositivo_t;
```
<!-- {code-block} c -->
- Funciones: `dispositivo_crear`, `dispositivo_cambiar_estado`, `dispositivo_imprimir`

---
(ejercicio_20_76)=
## Ejercicio 20.76 - Base de Datos Simple ⭐⭐⭐⭐⭐

Sistema CRUD para empleados.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef struct
{
    int id;
    char nombre[50];
    char departamento[50];
    float salario;
} empleado_t;
typedef struct
{
    empleado_t *empleados;
    int cantidad;
    int capacidad;
} base_datos_t;
```
<!-- {code-block} c -->
- Funciones: crear, agregar, buscar, actualizar, eliminar, listar

---
(ejercicio_20_77)=
## Ejercicio 20.77 - Máquina de Estados con Enum ⭐⭐⭐⭐⭐

Implementá máquina de estados finitos.

**Orientación:**

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para
    evitar fallos de segmentación.
-   **[*plus ultra*]:** Implementar una versión utilizando aritmética de
    punteros en lugar de indexación directa.

:::
<!-- {hint} Lógica y Consideraciones -->

```{code-block} c
:linenos:
typedef enum
{
    ESTADO_INICIO,
    ESTADO_PROCESANDO,
    ESTADO_PAUSA,
    ESTADO_ERROR,
    ESTADO_FIN
} estado_t;
typedef enum
{
    EVENTO_INICIAR,
    EVENTO_PAUSAR,
    EVENTO_REANUDAR,
    EVENTO_ERROR,
    EVENTO_COMPLETAR
} evento_t;
typedef struct
{
    estado_t estado_actual;
    // Datos del contexto
} maquina_t;
estado_t transicion(estado_t actual, evento_t evento);
```
<!-- {code-block} c -->

---

## Notas Finales

:::{tip} Convenciones de Nomenclatura

**Enumeraciones:**
``` c
typedef enum
{
    COLOR_ROJO,
    COLOR_VERDE,
    COLOR_AZUL
} color_t;
```
<!-- c -->
- Sufijo `_t` para el tipo
- Prefijo común para los valores

**Estructuras:**
``` c
typedef struct
{
    // campos
} nombre_t;
```
<!-- c -->
- Sufijo `_t` indica que es un tipo definido por el usuario

:::
<!-- {tip} Convenciones de Nomenclatura -->

:::{note} Tamaño y Alineación

**Obtener tamaño:**
``` c
printf("Tamaño: %zu bytes\n", sizeof(estructura_t));
```
<!-- c -->

**Offset de campos:**
``` c
#include <stddef.h>
printf("Offset de campo: %zu\n", offsetof(estructura_t, campo));
```
<!-- c -->

**Alineación:**
- Campos se alinean a múltiplos de su tamaño
- Estructura completa se alinea al mayor campo
- Reordenar campos puede ahorrar memoria

:::
<!-- {note} Tamaño y Alineación -->

:::{warning} Errores Comunes

1. **Olvidar typedef:**
   ```c
   struct punto
   {
       int x, y;
   };
   struct punto p; // Necesitas "struct"
   typedef struct
   {
       int x, y;
   } punto_t;
   punto_t p; // Más limpio
   ```

2. **Union sin tipo discriminador:**
   ```c
   // MAL: no sabés qué campo es válido
   union
   {
       int i;
       float f;
   } valor;
   // BIEN: con tipo
   struct
   {
       enum
       {
           INT,
           FLOAT
       } tipo;
       union
       {
           int i;
           float f;
       } valor;
   } variable;
   ```

3. **Comparación de structs:**
   ```c
   // MAL: no se puede comparar directamente
   if (p1 == p2)
   {
   }
   // BIEN: comparar campo por campo
   if (p1.x == p2.x && p1.y == p2.y)
   {
   }
   ```

4. **Copiar structs con punteros:**
   ```c
   typedef struct
   {
       char *nombre; // Puntero
   } persona_t;
   persona_t p2 = p1; // Copia shallow: ambos apuntan al mismo nombre
   // Necesitas copia profunda manual
   ```

:::
<!-- {warning} Errores Comunes -->

:::{tip} Inicialización

**Cero:**
``` c
estructura_t s = {0}; // Todo en cero
```
<!-- c -->

**Designadores C99:**
``` c
punto_t p = {.x = 10, .y = 20};
```
<!-- c -->

**Compuesta (C99):**
``` c
punto_t p = (punto_t){.x = 10, .y = 20};
```
<!-- c -->

**Array de structs:**
``` c
punto_t puntos[] = {{1, 2}, {3, 4}, {.x = 5, .y = 6}};
```
<!-- c -->

:::
<!-- {tip} Inicialización -->

:::{note} Estructuras Opacas

**Encapsulamiento:**
```{code-block} c
:linenos:
// archivo.h
typedef struct archivo archivo_t; // Declaración opaca
archivo_t *abrir_archivo(const char *ruta);
// archivo.c
struct archivo
{ // Definición oculta
    FILE *fp;
    int linea;
};
```
<!-- {code-block} c -->
- Usuario solo ve puntero, no puede acceder a campos
- Facilita cambios internos sin romper código cliente

:::
<!-- {note} Estructuras Opacas -->

Estas consignas cubren tipos de datos personalizados desde básicos hasta
sistemas complejos, preparando para diseño de TADs profesionales.

