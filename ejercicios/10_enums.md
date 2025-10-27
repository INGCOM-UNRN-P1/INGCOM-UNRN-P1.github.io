---
title: Ejercicios de enumeraciones
short_title: 10. enum/struct/union
---

Ejercicios para trabajar con enumeraciones (`enum`), estructuras (`struct`) y uniones (`union`), desde conceptos básicos hasta aplicaciones avanzadas en modelado de estados y configuración de sistemas.

## 1: Días de la Semana

Crear un tipo `enum` para representar los días de la semana y funciones básicas para trabajar con ellos.

```c
enum dia_semana {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};
```

### 1.1: Día Siguiente

Implementar una función que retorne el día siguiente al día proporcionado. El día siguiente a `DOMINGO` es `LUNES`.

```c
enum dia_semana dia_siguiente(enum dia_semana dia_actual);
```

### 1.2: Es Día Laboral

Implementar una función que determine si un día es laboral (lunes a viernes).

```c
bool es_dia_laboral(enum dia_semana dia);
```

### 1.3: Nombre del Día

Implementar una función que retorne el nombre del día como cadena de texto. Esta función ilustra el patrón de conversión enum-a-string.

```c
const char* nombre_dia(enum dia_semana dia);
```

## 2: Estados de Conexión

Modelar los estados de una conexión de red usando enumeraciones.

```c
enum estado_red {
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    DESCONECTANDO,
    ERROR_TIMEOUT,
    ERROR_AUTH
};
```

### 2.1: Máquina de Estados

Implementar una función que procese transiciones de estado. La función debe recibir el estado actual y un evento, y retornar el nuevo estado según las reglas de transición.

```c
enum evento_red {
    EVENTO_CONECTAR,
    EVENTO_DESCONECTAR,
    EVENTO_TIMEOUT,
    EVENTO_ERROR
};

enum estado_red procesar_evento(enum estado_red estado, enum evento_red evento);
```

**Reglas de transición sugeridas:**
- `DESCONECTADO` + `EVENTO_CONECTAR` → `CONECTANDO`
- `CONECTANDO` + `EVENTO_TIMEOUT` → `ERROR_TIMEOUT`
- `CONECTANDO` + `EVENTO_ERROR` → `ERROR_AUTH`
- `CONECTADO` + `EVENTO_DESCONECTAR` → `DESCONECTANDO`
- `DESCONECTANDO` + transición completa → `DESCONECTADO`

### 2.2: Validación de Estado

Implementar una función que valide si un valor numérico corresponde a un estado válido de la enumeración. Usar el patrón del valor centinela.

```c
enum estado_red {
    DESCONECTADO,
    CONECTANDO,
    CONECTADO,
    DESCONECTANDO,
    ERROR_TIMEOUT,
    ERROR_AUTH,
    _ESTADO_MAX  // Valor centinela
};

bool estado_valido(int valor);
```

## 3: Sistema de Permisos con Flags

Implementar un sistema de permisos usando flags de bits. Este ejercicio demuestra cómo combinar múltiples opciones en un único valor.

```c
enum permisos {
    PERMISO_LECTURA    = 1 << 0,  // 0x01
    PERMISO_ESCRITURA  = 1 << 1,  // 0x02
    PERMISO_EJECUCION  = 1 << 2,  // 0x04
    PERMISO_ELIMINAR   = 1 << 3   // 0x08
};
```

### 3.1: Verificar Permiso

Implementar una función que verifique si un conjunto de permisos incluye un permiso específico.

```c
bool tiene_permiso(unsigned int permisos_actuales, enum permisos permiso);
```

### 3.2: Agregar y Quitar Permisos

Implementar funciones para modificar el conjunto de permisos.

```c
unsigned int agregar_permiso(unsigned int permisos, enum permisos nuevo);
unsigned int quitar_permiso(unsigned int permisos, enum permisos remover);
```

### 3.3: Listar Permisos Activos

Implementar una función que imprima todos los permisos activos en un conjunto de permisos.

```c
void mostrar_permisos(unsigned int permisos);
```

## 4: Colores RGB con Enum

Definir una enumeración para colores predefinidos y una estructura para representar colores RGB personalizados.

```c
enum color_predefinido {
    COLOR_NEGRO,
    COLOR_BLANCO,
    COLOR_ROJO,
    COLOR_VERDE,
    COLOR_AZUL,
    COLOR_AMARILLO,
    COLOR_MAGENTA,
    COLOR_CIAN
};

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_t;
```

### 4.1: Conversión de Color Predefinido a RGB

Implementar una función que convierta un color predefinido a sus componentes RGB.

```c
rgb_t color_a_rgb(enum color_predefinido color);
```

**Valores sugeridos:**
- `COLOR_ROJO`: (255, 0, 0)
- `COLOR_VERDE`: (0, 255, 0)
- `COLOR_AZUL`: (0, 0, 255)
- `COLOR_AMARILLO`: (255, 255, 0)

### 4.2: Mezcla de Colores

Implementar una función que mezcle dos colores RGB usando promedio aritmético.

```c
rgb_t mezclar_colores(rgb_t c1, rgb_t c2);
```

## 5: Configuración de Dispositivo con Unión Etiquetada

Implementar una unión etiquetada para almacenar diferentes tipos de configuración de dispositivos.

```c
enum tipo_dispositivo {
    DISPOSITIVO_SENSOR_TEMP,
    DISPOSITIVO_MOTOR,
    DISPOSITIVO_LED
};

typedef struct {
    double temperatura_min;
    double temperatura_max;
} config_sensor_t;

typedef struct {
    unsigned int velocidad_rpm;
    bool direccion_horaria;
} config_motor_t;

typedef struct {
    unsigned char intensidad;
    enum color_predefinido color;
} config_led_t;

typedef struct {
    enum tipo_dispositivo tipo;
    union {
        config_sensor_t sensor;
        config_motor_t motor;
        config_led_t led;
    } config;
} dispositivo_t;
```

### 5.1: Configurar Dispositivo

Implementar funciones para configurar cada tipo de dispositivo de forma segura.

```c
dispositivo_t crear_sensor(double temp_min, double temp_max);
dispositivo_t crear_motor(unsigned int rpm, bool horario);
dispositivo_t crear_led(unsigned char intensidad, enum color_predefinido color);
```

### 5.2: Imprimir Configuración

Implementar una función que imprima la configuración de un dispositivo según su tipo. Este ejercicio demuestra el uso correcto de uniones etiquetadas.

```c
void imprimir_dispositivo(const dispositivo_t* dispositivo);
```

## 6: Códigos de Error

Definir una enumeración exhaustiva para códigos de error de un sistema.

```c
enum codigo_error {
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

### 6.1: Mensaje de Error

Implementar una función que retorne un mensaje descriptivo para cada código de error.

```c
const char* mensaje_error(enum codigo_error error);
```

### 6.2: Tipo de Resultado

Implementar un tipo `resultado_t` que encapsule un valor de retorno o un código de error usando unión etiquetada.

```c
typedef struct {
    enum codigo_error error;
    union {
        int valor_int;
        double valor_double;
        void* valor_ptr;
    } datos;
} resultado_t;
```

Implementar funciones auxiliares:

```c
resultado_t resultado_ok_int(int valor);
resultado_t resultado_error(enum codigo_error error);
bool resultado_es_error(const resultado_t* resultado);
```

## 7: Estados de Reproducción Multimedia

Modelar un reproductor multimedia con estados y modos de reproducción.

```c
enum estado_reproductor {
    ESTADO_DETENIDO,
    ESTADO_REPRODUCIENDO,
    ESTADO_PAUSADO,
    ESTADO_AVANZANDO,
    ESTADO_RETROCEDIENDO
};

enum modo_reproduccion {
    MODO_NORMAL,
    MODO_REPETIR_UNO,
    MODO_REPETIR_TODOS,
    MODO_ALEATORIO
};
```

### 7.1: Controlador de Reproducción

Implementar una estructura que encapsule el estado completo del reproductor.

```c
typedef struct {
    enum estado_reproductor estado;
    enum modo_reproduccion modo;
    unsigned int pista_actual;
    unsigned int total_pistas;
} reproductor_t;
```

### 7.2: Comandos de Control

Implementar funciones para controlar el reproductor.

```c
void reproducir(reproductor_t* rep);
void pausar(reproductor_t* rep);
void detener(reproductor_t* rep);
void siguiente_pista(reproductor_t* rep);
void anterior_pista(reproductor_t* rep);
```

Las funciones deben respetar el estado actual y el modo de reproducción.

## 8: Prioridades y Niveles de Log

Implementar un sistema de logging con niveles de prioridad.

```c
enum nivel_log {
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
};
```

### 8.1: Filtrado de Logs

Implementar una función que determine si un mensaje debe ser registrado según el nivel mínimo configurado.

```c
bool debe_registrar(enum nivel_log nivel_mensaje, enum nivel_log nivel_minimo);
```

### 8.2: Formateo de Mensaje de Log

Implementar una función que formatee un mensaje de log incluyendo el nivel como prefijo.

```c
void log_mensaje(enum nivel_log nivel, const char* mensaje);
```

Ejemplo de salida: `[ERROR] Archivo no encontrado`

## 9: Protocolo de Comunicación

Diseñar estructuras para un protocolo simple de comunicación usando campos de bits.

```c
enum tipo_mensaje {
    MSG_DATOS = 0,
    MSG_ACK = 1,
    MSG_NACK = 2,
    MSG_RESET = 3
};

typedef struct {
    unsigned int tipo : 2;        // 2 bits para tipo (0-3)
    unsigned int prioridad : 2;   // 2 bits para prioridad (0-3)
    unsigned int secuencia : 4;   // 4 bits para número de secuencia (0-15)
} cabecera_mensaje_t;
```

### 9.1: Crear y Decodificar Cabecera

Implementar funciones para construir y extraer información de la cabecera.

```c
cabecera_mensaje_t crear_cabecera(enum tipo_mensaje tipo, 
                                   unsigned int prioridad, 
                                   unsigned int secuencia);

void imprimir_cabecera(cabecera_mensaje_t cabecera);
```

### 9.2: Validación de Cabecera

Implementar una función que valide que los valores de una cabecera están dentro de los rangos permitidos.

```c
bool cabecera_valida(cabecera_mensaje_t cabecera);
```

## 10: Opciones de Compilación con Flags

Modelar opciones de compilación como flags combinables.

```c
enum opcion_compilacion {
    OPT_NINGUNA       = 0,
    OPT_OPTIMIZAR     = 1 << 0,  // -O
    OPT_DEBUG         = 1 << 1,  // -g
    OPT_WARNINGS      = 1 << 2,  // -Wall
    OPT_WARNINGS_EXTRA = 1 << 3, // -Wextra
    OPT_PEDANTIC      = 1 << 4   // -pedantic
};
```

### 10.1: Generar Línea de Comandos

Implementar una función que genere una cadena con las opciones de compilación correspondientes a los flags activos.

```c
void generar_comando_compilacion(unsigned int opciones, char* buffer, size_t tam);
```

Ejemplo: Si `opciones` tiene `OPT_DEBUG | OPT_WARNINGS`, el buffer debe contener `"-g -Wall"`.

### 10.2: Detectar Conflictos

Implementar una función que detecte combinaciones incompatibles de opciones.

```c
bool opciones_compatibles(unsigned int opciones);
```

Por ejemplo, `OPT_OPTIMIZAR` y `OPT_DEBUG` podrían considerarse incompatibles en ciertos contextos.

## 11: Menú de Aplicación

Implementar un sistema de menú interactivo usando enumeraciones.

```c
enum opcion_menu {
    MENU_NUEVO = 1,
    MENU_ABRIR,
    MENU_GUARDAR,
    MENU_CERRAR,
    MENU_SALIR,
    MENU_INVALIDO = -1
};
```

### 11.1: Parser de Opción

Implementar una función que convierta la entrada del usuario en una opción del menú.

```c
enum opcion_menu parsear_opcion(int entrada);
```

### 11.2: Ejecutor de Menú

Implementar una función que ejecute la acción correspondiente a cada opción del menú.

```c
void ejecutar_opcion(enum opcion_menu opcion);
```

### 11.3: Menú Interactivo Completo

Implementar un lazo principal que muestre el menú, lea la opción del usuario y ejecute la acción hasta que el usuario seleccione `MENU_SALIR`.

## 12: Tipos de Figuras Geométricas con Unión

Combinar enumeraciones, estructuras y uniones para representar diferentes figuras geométricas.

```c
enum tipo_figura {
    FIGURA_CIRCULO,
    FIGURA_RECTANGULO,
    FIGURA_TRIANGULO
};

typedef struct {
    double radio;
} circulo_t;

typedef struct {
    double base;
    double altura;
} rectangulo_t;

typedef struct {
    double lado_a;
    double lado_b;
    double lado_c;
} triangulo_t;

typedef struct {
    enum tipo_figura tipo;
    union {
        circulo_t circulo;
        rectangulo_t rectangulo;
        triangulo_t triangulo;
    } datos;
} figura_t;
```

### 12.1: Cálculo de Área

Implementar una función que calcule el área de cualquier figura usando su tipo y datos.

```c
double calcular_area(const figura_t* figura);
```

**Fórmulas:**
- Círculo: $A = \pi r^2$
- Rectángulo: $A = base \times altura$
- Triángulo (Fórmula de Herón):
  - $s = \frac{a+b+c}{2}$
  - $A = \sqrt{s(s-a)(s-b)(s-c)}$

### 12.2: Constructores de Figuras

Implementar funciones para crear cada tipo de figura de forma segura.

```c
figura_t crear_circulo(double radio);
figura_t crear_rectangulo(double base, double altura);
figura_t crear_triangulo(double a, double b, double c);
```

## 13: Conversión entre Enums y Strings

### 13.1: Tabla de Conversión

Implementar un sistema genérico para convertir entre valores enum y strings usando tablas de conversión.

```c
typedef struct {
    int valor;
    const char* nombre;
} enum_string_t;

// Ejemplo de uso con días de la semana
const enum_string_t tabla_dias[] = {
    {LUNES, "Lunes"},
    {MARTES, "Martes"},
    {MIERCOLES, "Miércoles"},
    // ...
};
```

### 13.2: Funciones de Conversión Genéricas

Implementar funciones genéricas que usen la tabla para realizar conversiones.

```c
const char* enum_a_string(int valor, const enum_string_t* tabla, size_t tam);
int string_a_enum(const char* nombre, const enum_string_t* tabla, size_t tam, int valor_defecto);
```

## 14: Estado de Juego

Modelar el estado de un juego simple usando múltiples enumeraciones.

```c
enum estado_juego {
    JUEGO_MENU,
    JUEGO_JUGANDO,
    JUEGO_PAUSADO,
    JUEGO_GAME_OVER,
    JUEGO_VICTORIA
};

enum dificultad {
    DIFICULTAD_FACIL,
    DIFICULTAD_NORMAL,
    DIFICULTAD_DIFICIL,
    DIFICULTAD_EXPERTO
};

typedef struct {
    enum estado_juego estado;
    enum dificultad dificultad;
    unsigned int puntuacion;
    unsigned int nivel;
    unsigned int vidas;
} juego_t;
```

### 14.1: Inicializar Juego

Implementar una función que inicialice un juego nuevo con la dificultad especificada.

```c
juego_t inicializar_juego(enum dificultad dif);
```

La dificultad debe afectar el número inicial de vidas y otros parámetros.

### 14.2: Gestión de Estado

Implementar funciones para transiciones de estado comunes.

```c
void pausar_juego(juego_t* juego);
void reanudar_juego(juego_t* juego);
void perder_vida(juego_t* juego);
void ganar_nivel(juego_t* juego);
```

## 15: Análisis de Tráfico con Enums Anidados

Modelar un sistema de análisis de tráfico de red con múltiples niveles de clasificación.

```c
enum protocolo {
    PROTOCOLO_TCP,
    PROTOCOLO_UDP,
    PROTOCOLO_ICMP,
    PROTOCOLO_OTRO
};

enum tipo_trafico {
    TRAFICO_NORMAL,
    TRAFICO_SOSPECHOSO,
    TRAFICO_MALICIOSO
};

typedef struct {
    enum protocolo proto;
    enum tipo_trafico tipo;
    unsigned int puerto_origen;
    unsigned int puerto_destino;
    size_t bytes_transferidos;
} paquete_red_t;
```

### 15.1: Clasificador de Tráfico

Implementar una función que clasifique un paquete basándose en reglas heurísticas.

```c
enum tipo_trafico clasificar_paquete(const paquete_red_t* paquete);
```

**Reglas sugeridas:**
- Puertos conocidos (80, 443, 22) → `TRAFICO_NORMAL`
- Puertos altos no estándar → `TRAFICO_SOSPECHOSO`
- Transferencias muy grandes o patrones anómalos → `TRAFICO_MALICIOSO`

### 15.2: Estadísticas por Protocolo

Implementar una función que cuente paquetes por protocolo en un arreglo de paquetes.

```c
typedef struct {
    unsigned int tcp;
    unsigned int udp;
    unsigned int icmp;
    unsigned int otro;
} estadisticas_protocolo_t;

estadisticas_protocolo_t contar_por_protocolo(const paquete_red_t* paquetes, size_t cantidad);
```

## 16: Enums en Sistemas de Archivos

### 16.1: Permisos de Archivo (UNIX)

Modelar permisos de archivo estilo UNIX usando flags.

```c
enum permiso_unix {
    OWNER_READ    = 0400,  // 0100000000 en octal
    OWNER_WRITE   = 0200,
    OWNER_EXECUTE = 0100,
    GROUP_READ    = 0040,
    GROUP_WRITE   = 0020,
    GROUP_EXECUTE = 0010,
    OTHER_READ    = 0004,
    OTHER_WRITE   = 0002,
    OTHER_EXECUTE = 0001
};
```

Implementar funciones para manipular permisos:

```c
bool tiene_permiso_unix(unsigned int permisos, enum permiso_unix permiso);
unsigned int agregar_permiso_unix(unsigned int permisos, enum permiso_unix nuevo);
void mostrar_permisos_unix(unsigned int permisos);  // Formato: rwxr-xr--
```

### 16.2: Tipos de Archivo

Modelar diferentes tipos de archivo en un sistema de archivos.

```c
enum tipo_archivo {
    TIPO_REGULAR,
    TIPO_DIRECTORIO,
    TIPO_ENLACE_SIMBOLICO,
    TIPO_ENLACE_DURO,
    TIPO_DISPOSITIVO,
    TIPO_PIPE,
    TIPO_SOCKET
};

typedef struct {
    char nombre[256];
    enum tipo_archivo tipo;
    size_t tamanio;
    unsigned int permisos;
} archivo_info_t;
```

## 17: Sistema de Eventos

### 17.1: Tipos de Eventos de UI

Modelar eventos de interfaz de usuario.

```c
enum tipo_evento {
    EVENTO_CLICK,
    EVENTO_DOBLE_CLICK,
    EVENTO_PRESIONAR_TECLA,
    EVENTO_SOLTAR_TECLA,
    EVENTO_MOVER_MOUSE,
    EVENTO_SCROLL
};

enum boton_mouse {
    BOTON_IZQUIERDO = 1,
    BOTON_DERECHO = 2,
    BOTON_MEDIO = 4
};

typedef struct {
    enum tipo_evento tipo;
    int x, y;  // Coordenadas
    unsigned int botones;  // Flags de botones presionados
    unsigned int tecla;
} evento_t;
```

### 17.2: Procesador de Eventos

Implementar un procesador que maneje diferentes tipos de eventos.

```c
void procesar_evento(const evento_t* evento);
```

## 18: Estados de Procesos (Sistema Operativo)

### 18.1: Modelo de Estados

Modelar el ciclo de vida de un proceso en un sistema operativo.

```c
enum estado_proceso {
    PROCESO_NUEVO,
    PROCESO_LISTO,
    PROCESO_EJECUTANDO,
    PROCESO_BLOQUEADO,
    PROCESO_TERMINADO
};

enum razon_bloqueo {
    BLOQ_IO,
    BLOQ_MUTEX,
    BLOQ_SEMAFORO,
    BLOQ_MENSAJE
};

typedef struct {
    int pid;
    enum estado_proceso estado;
    enum razon_bloqueo razon;  // Solo válido si estado == BLOQUEADO
    int prioridad;
} proceso_t;
```

### 18.2: Planificador Simple

Implementar funciones de transición de estado para un planificador.

```c
bool transicion_estado(proceso_t* proceso, enum estado_proceso nuevo_estado);
bool puede_ejecutar(const proceso_t* proceso);
```

## 19: Protocolo HTTP

### 19.1: Métodos y Códigos HTTP

Modelar métodos y códigos de estado HTTP.

```c
enum metodo_http {
    HTTP_GET,
    HTTP_POST,
    HTTP_PUT,
    HTTP_DELETE,
    HTTP_PATCH,
    HTTP_HEAD,
    HTTP_OPTIONS
};

enum codigo_http {
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

### 19.2: Parser de Respuesta HTTP

Implementar funciones para trabajar con HTTP.

```c
const char* metodo_a_string(enum metodo_http metodo);
const char* codigo_a_mensaje(enum codigo_http codigo);
bool es_codigo_exito(enum codigo_http codigo);  // 2xx
bool es_codigo_error_cliente(enum codigo_http codigo);  // 4xx
bool es_codigo_error_servidor(enum codigo_http codigo);  // 5xx
```

## 20: Semáforo (Sistema de Control)

### 20.1: Estados de Semáforo

Modelar un sistema de semáforo de tráfico.

```c
enum estado_semaforo {
    SEMAFORO_ROJO,
    SEMAFORO_AMARILLO,
    SEMAFORO_VERDE,
    SEMAFORO_INTERMITENTE
};

enum direccion_trafico {
    DIR_NORTE_SUR,
    DIR_ESTE_OESTE,
    DIR_TODAS
};

typedef struct {
    enum estado_semaforo estado;
    enum direccion_trafico direccion_activa;
    int tiempo_restante;  // Segundos
} semaforo_t;
```

### 20.2: Controlador de Semáforo

Implementar la lógica de transición de un semáforo.

```c
void actualizar_semaforo(semaforo_t* semaforo);
enum estado_semaforo siguiente_estado(enum estado_semaforo actual);
bool puede_pasar(const semaforo_t* semaforo, enum direccion_trafico direccion);
```

## 21: Transacciones de Base de Datos

### 21.1: Estados de Transacción

Modelar el ciclo de vida de una transacción.

```c
enum estado_transaccion {
    TX_INICIADA,
    TX_ACTIVA,
    TX_PREPARADA,
    TX_COMPROMETIDA,
    TX_ABORTADA
};

enum tipo_aislamiento {
    AISLAMIENTO_READ_UNCOMMITTED,
    AISLAMIENTO_READ_COMMITTED,
    AISLAMIENTO_REPEATABLE_READ,
    AISLAMIENTO_SERIALIZABLE
};

typedef struct {
    unsigned long id;
    enum estado_transaccion estado;
    enum tipo_aislamiento aislamiento;
    int num_operaciones;
} transaccion_t;
```

### 21.2: Gestor de Transacciones

Implementar funciones para gestionar transacciones.

```c
transaccion_t iniciar_transaccion(enum tipo_aislamiento aislamiento);
bool commit_transaccion(transaccion_t* tx);
bool rollback_transaccion(transaccion_t* tx);
bool puede_hacer_commit(const transaccion_t* tx);
```

## 22: Tipos de Datos SQL

### 22.1: Tipos de Columna

Modelar tipos de datos SQL y sus propiedades.

```c
enum tipo_sql {
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

enum constraint_sql {
    CONSTRAINT_NINGUNO     = 0,
    CONSTRAINT_NOT_NULL    = 1 << 0,
    CONSTRAINT_UNIQUE      = 1 << 1,
    CONSTRAINT_PRIMARY_KEY = 1 << 2,
    CONSTRAINT_FOREIGN_KEY = 1 << 3,
    CONSTRAINT_AUTO_INCREMENT = 1 << 4
};

typedef struct {
    char nombre[64];
    enum tipo_sql tipo;
    unsigned int constraints;
    int longitud;  // Para VARCHAR
} columna_t;
```

### 22.2: Validación de Columnas

Implementar funciones para validar definiciones de columnas.

```c
bool es_tipo_numerico(enum tipo_sql tipo);
bool es_tipo_texto(enum tipo_sql tipo);
bool constraints_validos(unsigned int constraints);
size_t tamanio_tipo(enum tipo_sql tipo);
```

## 23: Formatos de Imagen

### 23.1: Tipos y Formatos

Modelar diferentes formatos de imagen y sus propiedades.

```c
enum formato_imagen {
    FORMATO_JPEG,
    FORMATO_PNG,
    FORMATO_GIF,
    FORMATO_BMP,
    FORMATO_WEBP,
    FORMATO_TIFF,
    FORMATO_SVG
};

enum modo_color {
    COLOR_ESCALA_GRISES,
    COLOR_RGB,
    COLOR_RGBA,
    COLOR_CMYK,
    COLOR_INDEXADO
};

typedef struct {
    enum formato_imagen formato;
    enum modo_color modo;
    int ancho;
    int alto;
    int profundidad_bits;
    bool tiene_transparencia;
    bool es_animado;
} metadata_imagen_t;
```

### 23.2: Análisis de Formatos

Implementar funciones para analizar propiedades de formatos.

```c
bool soporta_transparencia(enum formato_imagen formato);
bool soporta_animacion(enum formato_imagen formato);
bool es_formato_comprimido(enum formato_imagen formato);
const char* extension_formato(enum formato_imagen formato);
```

## 24: Sistema de Notificaciones

### 24.1: Niveles de Notificación

Modelar un sistema de notificaciones con prioridades.

```c
enum nivel_notificacion {
    NOTIF_DEBUG,
    NOTIF_INFO,
    NOTIF_ADVERTENCIA,
    NOTIF_ERROR,
    NOTIF_CRITICO
};

enum canal_notificacion {
    CANAL_NINGUNO  = 0,
    CANAL_CONSOLE  = 1 << 0,
    CANAL_EMAIL    = 1 << 1,
    CANAL_SMS      = 1 << 2,
    CANAL_PUSH     = 1 << 3,
    CANAL_SYSLOG   = 1 << 4
};

typedef struct {
    enum nivel_notificacion nivel;
    unsigned int canales;
    char mensaje[256];
    time_t timestamp;
} notificacion_t;
```

### 24.2: Gestor de Notificaciones

Implementar funciones para filtrar y enviar notificaciones.

```c
void enviar_notificacion(const notificacion_t* notif);
bool debe_notificar(enum nivel_notificacion nivel, enum nivel_notificacion nivel_minimo);
unsigned int canales_para_nivel(enum nivel_notificacion nivel);
```

## 25: Compresión de Datos

### 25.1: Algoritmos de Compresión

Modelar diferentes algoritmos de compresión y sus niveles.

```c
enum algoritmo_compresion {
    COMP_NINGUNO,
    COMP_DEFLATE,
    COMP_GZIP,
    COMP_BZIP2,
    COMP_LZMA,
    COMP_ZSTD,
    COMP_LZ4
};

enum nivel_compresion {
    NIVEL_MINIMO = 1,
    NIVEL_RAPIDO = 3,
    NIVEL_NORMAL = 5,
    NIVEL_MAXIMO = 9
};

typedef struct {
    enum algoritmo_compresion algoritmo;
    enum nivel_compresion nivel;
    size_t tamanio_original;
    size_t tamanio_comprimido;
    double ratio;  // tamanio_comprimido / tamanio_original
} resultado_compresion_t;
```

### 25.2: Análisis de Compresión

Implementar funciones para analizar rendimiento de compresión.

```c
double calcular_ratio(const resultado_compresion_t* resultado);
double porcentaje_ahorro(const resultado_compresion_t* resultado);
bool es_algoritmo_rapido(enum algoritmo_compresion alg);
const char* nombre_algoritmo(enum algoritmo_compresion alg);
```

## 26: Máquina de Estados Finita Genérica

### 26.1: Framework de FSM

Implementar un framework genérico para máquinas de estados finitas.

```c
#define MAX_ESTADOS 32
#define MAX_TRANSICIONES 64

typedef enum {
    FSM_ESTADO_0,
    FSM_ESTADO_1,
    FSM_ESTADO_2,
    // ... más estados
    FSM_ESTADO_MAX
} estado_fsm_t;

typedef enum {
    FSM_EVENTO_0,
    FSM_EVENTO_1,
    // ... más eventos
    FSM_EVENTO_MAX
} evento_fsm_t;

typedef struct {
    estado_fsm_t desde;
    estado_fsm_t hasta;
    evento_fsm_t evento;
    void (*accion)(void* contexto);
} transicion_t;

typedef struct {
    estado_fsm_t estado_actual;
    transicion_t transiciones[MAX_TRANSICIONES];
    int num_transiciones;
    void* contexto;
} maquina_estados_t;
```

### 26.2: Motor de FSM

Implementar el motor que procesa eventos y ejecuta transiciones.

```c
void fsm_inicializar(maquina_estados_t* fsm, estado_fsm_t inicial);
bool fsm_agregar_transicion(maquina_estados_t* fsm, transicion_t trans);
bool fsm_procesar_evento(maquina_estados_t* fsm, evento_fsm_t evento);
estado_fsm_t fsm_estado_actual(const maquina_estados_t* fsm);
```

## 27: Análisis Comparativo de Enums

### 27.1: Comparación de Implementaciones

Analizar diferentes formas de implementar el mismo concepto:

**Opción 1: Enum simple**
```c
enum dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
```

**Opción 2: Enum con valores explícitos**
```c
enum dia { LUNES=1, MARTES=2, MIERCOLES=3, JUEVES=4, VIERNES=5, SABADO=6, DOMINGO=7 };
```

**Opción 3: Flags con potencias de 2**
```c
enum dia { 
    LUNES=1<<0, MARTES=1<<1, MIERCOLES=1<<2, JUEVES=1<<3, 
    VIERNES=1<<4, SABADO=1<<5, DOMINGO=1<<6 
};
```

Discutir casos de uso, ventajas y desventajas de cada enfoque.

### 27.2: Tamaño y Rendimiento

Investigar y documentar:
- Tamaño en memoria de enums (usualmente `sizeof(int)`)
- Rendimiento de operaciones con enums vs constantes
- Optimizaciones del compilador con enums
- Diferencias entre C y C++ en el manejo de enums
