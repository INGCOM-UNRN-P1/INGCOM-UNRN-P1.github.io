---
title: 'Ejercicios Resueltos: Archivos de Texto'
short_title: '3b. Ejercicios Archivos'
subtitle: 'Problemas y soluciones detalladas sobre streams y persistencia en C'
---

# Ejercicios Resueltos: Archivos de Texto

## Acerca de

Estos ejercicios resueltos profundizan en la manipulación y persistencia de
datos usando streams de entrada/salida estándar y archivos de texto formateados
en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-archivos-texto`

### Cuestiones de Estilo Aplicables
- **Manejo defensivo de archivos:** Asegurá siempre la validación del puntero
  retornado por `fopen` y liberá el descriptor de archivo llamando a `fclose` en
  todas las ramas de control de errores.
- **Validación de buffer:** Evitá desbordamientos de buffer pasando siempre la
  capacidad límite al leer flujos con `fgets`.
(ejercicio_13_1)=
## Ejercicio 13.1 - s Propuestos ⭐⭐☆☆☆

(ejercicio_13_2)=

:::{hint} Lógica y Consideraciones

-   **[*plus ultra*]:** Validar estrictamente los datos de entrada para manejar
    valores fuera de rango o tipos inválidos.
-   **[*plus ultra*]:** Permitir el procesamiento interactivo continuo mediante
    un lazo hasta que el usuario elija finalizar.

:::
<!-- {hint} Lógica y Consideraciones -->

### Ejercicio 13.2 - b.1 - Escribir un diario personal ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_1
:enumerator: 1

**Escribir un diario personal**

Creá una función que reciba el nombre de un archivo y una cadena de texto. La
función debe abrir el archivo en modo "append" (añadir) y escribir la cadena de
texto seguida de un salto de línea. Asegurate de manejar todos los posibles
errores de apertura, escritura y cierre.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_1
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR -1

/**
 * Agrega una entrada de texto a un archivo de diario.
 *
 * @param nombre_archivo La ruta del archivo de diario.
 *      #PRE: No puede ser NULL.
 * @param entrada El texto a agregar en el diario.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si la entrada se escribió correctamente, ERROR en caso
   contrario.
 *
 * @post El archivo especificado por nombre_archivo contendrá la nueva entrada
 *       al final del mismo, seguida de un salto de línea.
 */
int agregar_entrada_diario(const char *nombre_archivo, const char *entrada)
{
    // 1. Abrir el archivo en modo "append" (añadir)
    FILE *p_archivo = fopen(nombre_archivo, "a");
    if (p_archivo == NULL)
    {
        perror("Error al abrir el diario");
        return ERROR;
    }

    // 2. Escribir la entrada
    if (fputs(entrada, p_archivo) == EOF)
    {
        perror("Error al escribir la entrada en el diario");
        fclose(p_archivo);
        return ERROR;
    }

    // 3. Escribir el salto de línea
    if (fputc('\n', p_archivo) == EOF)
    {
        perror("Error al escribir el salto de línea");
        fclose(p_archivo);
        return ERROR;
    }

    // 4. Cerrar el archivo
    if (fclose(p_archivo) != 0)
    {
        perror("Error al cerrar el diario");
        return ERROR;
    }

    return EXITO;
}

int main(void)
{
    const char *MI_DIARIO = "diario.txt";
    int resultado = 0;

    printf("Escribiendo primera entrada...\n");
    resultado = agregar_entrada_diario(MI_DIARIO, "Hoy fue un día soleado.");
    if (resultado == ERROR)
    {
        fprintf(stderr, "No se pudo escribir la primera entrada.\n");
        return EXIT_FAILURE;
    }

    printf("Escribiendo segunda entrada...\n");
    resultado = agregar_entrada_diario(MI_DIARIO, "Aprendí a manejar archivos en
    C.");
    if (resultado == ERROR)
    {
        fprintf(stderr, "No se pudo escribir la segunda entrada.\n");
        return EXIT_FAILURE;
    }

    printf("Entradas agregadas al diario '%s' con éxito.\n", MI_DIARIO);

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_1 -->
(ejercicio_13_3)=
### Ejercicio 13.3 - b.2 - Contador de líneas ⭐⭐⭐☆☆

:::{exercise}
:label: ejercicio_archivos_2
:enumerator: 2

**Contador de líneas**

Escribí una función que reciba el nombre de un archivo, lo lea y devuelva la
cantidad de líneas que contiene. Una línea se define como una secuencia de
caracteres terminada por un `\n`. La función debe devolver un número negativo en
caso de error.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_2
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define MAX_LONGITUD_LINEA 1024
#define ERROR_APERTURA -1
#define ERROR_LECTURA -2

/**
 * Cuenta el número de líneas en un archivo de texto.
 *
 * @param nombre_archivo La ruta del archivo a leer.
 *      #PRE: No puede ser NULL.
 *
 * @returns El número de líneas contadas si la operación es exitosa.
 *          Retorna ERROR_APERTURA si el archivo no puede abrirse.
 *          Retorna ERROR_LECTURA si ocurre un error durante la lectura.
 *
 * @post El archivo no es modificado.
 */
int contar_lineas(const char *nombre_archivo)
{
    int cantidad_lineas = 0;
    FILE *p_archivo = NULL;
    char buffer[MAX_LONGITUD_LINEA];

    p_archivo = fopen(nombre_archivo, "r");
    if (p_archivo == NULL)
    {
        perror("Error al abrir el archivo para contar líneas");
        return ERROR_APERTURA;
    }

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        cantidad_lineas++;
    }

    // Después del lazo, verificar si salimos por error o por fin de archivo
    if (ferror(p_archivo))
    {
        perror("Error de lectura mientras se contaban las líneas");
        cantidad_lineas = ERROR_LECTURA; // Sobrescribimos el conteo con un
        código de error
    }

    if (fclose(p_archivo) != 0)
    {
        perror("Error al cerrar el archivo después de contar");
        if (cantidad_lineas >= 0) // No sobrescribir un error de lectura previo
        {
            cantidad_lineas = ERROR_APERTURA; // Reutilizamos código de error
        }
    }

    return cantidad_lineas;
}

int main(void)
{
    const char *NOMBRE_ARCHIVO = "diario.txt";
    // Crear un archivo de prueba primero
    FILE *p_archivo_prueba = fopen(NOMBRE_ARCHIVO, "w");
    if (p_archivo_prueba != NULL)
    {
        fputs("Primera línea.\n", p_archivo_prueba);
        fputs("Segunda línea.\n", p_archivo_prueba);
        fputs("Tercera línea.\n", p_archivo_prueba);
        fclose(p_archivo_prueba);
    }

    printf("Contando líneas en el archivo '%s'...\n", NOMBRE_ARCHIVO);
    int lineas = contar_lineas(NOMBRE_ARCHIVO);

    if (lineas >= 0)
    {
        printf("El archivo contiene %d líneas.\n", lineas);
    }
    else
    {
        fprintf(stderr, "Ocurrió un error al procesar el archivo (código:
        %d).\n", lineas);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_2 -->
(ejercicio_13_4)=
### Ejercicio 13.4 - b.3 - Copiar un archivo de texto ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_3
:enumerator: 3

**Copiar un archivo de texto**

Implementá una función que copie el contenido de un archivo de origen a un
archivo de destino. La función debe leer el archivo de origen línea por línea y
escribir cada línea en el archivo de destino. Debe manejar errores para ambos
archivos (apertura, lectura, escritura y cierre).

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_3
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXITO 0
#define ERROR -1
#define MAX_BUFFER 4096

/**
 * Copia el contenido de un archivo de texto a otro.
 *
 * @param ruta_origen La ruta del archivo a leer.
 *      #PRE: No puede ser NULL.
 * @param ruta_destino La ruta del archivo donde se escribirá el contenido.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si la copia fue completamente exitosa, ERROR si ocurrió algún
   fallo.
 *
 * @post Si la operación es exitosa, el archivo en ruta_destino tendrá el mismo
 *       contenido que el de ruta_origen.
 */
int copiar_archivo(const char *ruta_origen, const char *ruta_destino)
{
    int estado_operacion = EXITO;
    FILE *p_origen = NULL;
    FILE *p_destino = NULL;
    char buffer[MAX_BUFFER];
    bool continuar_lazo = true;

    p_origen = fopen(ruta_origen, "r");
    if (p_origen == NULL)
    {
        perror("Error al abrir el archivo de origen");
        estado_operacion = ERROR;
    }

    if (estado_operacion == EXITO)
    {
        p_destino = fopen(ruta_destino, "w");
        if (p_destino == NULL)
        {
            perror("Error al abrir el archivo de destino");
            estado_operacion = ERROR;
        }
    }

    while (estado_operacion == EXITO && continuar_lazo)
    {
        if (fgets(buffer, sizeof(buffer), p_origen) != NULL)
        {
            if (fputs(buffer, p_destino) == EOF)
            {
                perror("Error al escribir en el archivo de destino");
                estado_operacion = ERROR;
            }
        }
        else
        {
            continuar_lazo = false; // Se terminó de leer o hubo un error
        }
    }

    // Verificar si el lazo terminó por un error de lectura
    if (p_origen != NULL && ferror(p_origen))
    {
        perror("Error de lectura en el archivo de origen");
        estado_operacion = ERROR;
    }

    // Cerrar ambos archivos, verificando errores en cada cierre
    if (p_origen != NULL && fclose(p_origen) != 0)
    {
        perror("Error al cerrar el archivo de origen");
        estado_operacion = ERROR;
    }
    if (p_destino != NULL && fclose(p_destino) != 0)
    {
        perror("Error al cerrar el archivo de destino");
        estado_operacion = ERROR;
    }

    return estado_operacion;
}

int main(void)
{
    const char *ARCHIVO_ORIGEN = "original.txt";
    const char *ARCHIVO_COPIA = "copia.txt";

    // Crear archivo original de prueba
    FILE *p_temp = fopen(ARCHIVO_ORIGEN, "w");
    if (p_temp != NULL)
    {
        fprintf(p_temp, "Línea 1 del original.\n");
        fprintf(p_temp, "Línea 2 con algunos caracteres especiales: áéíóú.\n");
        fprintf(p_temp, "Fin del archivo original.\n");
        fclose(p_temp);
    }

    printf("Copiando '%s' a '%s'...\n", ARCHIVO_ORIGEN, ARCHIVO_COPIA);
    if (copiar_archivo(ARCHIVO_ORIGEN, ARCHIVO_COPIA) == EXITO)
    {
        printf("Archivo copiado con éxito.\n");
    }
    else
    {
        fprintf(stderr, "La copia del archivo falló.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_3 -->
(ejercicio_13_5)=
### Ejercicio 13.5 - b.4 - Registrar eventos en un log ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_4
:enumerator: 4

**Registrar eventos en un log**

Crea una función `registrar_evento` que reciba un mensaje y lo añada a un
archivo llamado `eventos.log`. La función debe asegurarse de que cada mensaje
nuevo se agregue al final del archivo, sin borrar el contenido anterior. Por
simplicidad, no es necesario agregar una marca de tiempo.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_4
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR -1
#define ARCHIVO_LOG "eventos.log"

/**
 * Registra un mensaje de evento en un archivo de log.
 *
 * @param mensaje El mensaje a registrar.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si el evento se registró correctamente, ERROR en caso
   contrario.
 *
 * @post El archivo de log contendrá el nuevo mensaje al final.
 */
int registrar_evento(const char *mensaje)
{
    int resultado = EXITO;
    FILE *p_log = fopen(ARCHIVO_LOG, "a");

    if (p_log == NULL)
    {
        perror("Error al abrir el archivo de log");
        resultado = ERROR;
    }
    else
    {
        // Escribir el mensaje y un salto de línea
        if (fprintf(p_log, "%s\n", mensaje) < 0)
        {
            perror("Error al escribir en el archivo de log");
            resultado = ERROR;
        }

        // Cerrar el archivo
        if (fclose(p_log) != 0)
        {
            perror("Error al cerrar el archivo de log");
            resultado = ERROR;
        }
    }

    return resultado;
}

int main(void)
{
    printf("Registrando eventos...\n");

    if (registrar_evento("[INFO] El sistema ha iniciado.") != EXITO)
    {
        fprintf(stderr, "Fallo al registrar el primer evento.\n");
        return EXIT_FAILURE;
    }

    if (registrar_evento("[WARN] El disco está casi lleno.") != EXITO)
    {
        fprintf(stderr, "Fallo al registrar el segundo evento.\n");
        return EXIT_FAILURE;
    }

    if (registrar_evento("[FATAL] No se pudo conectar a la base de datos.") !=
    EXITO)
    {
        fprintf(stderr, "Fallo al registrar el tercer evento.\n");
        return EXIT_FAILURE;
    }

    printf("Eventos registrados en '%s'.\n", ARCHIVO_LOG);

    return EXIT_SUCCESS;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_4 -->
(ejercicio_13_6)=
### Ejercicio 13.6 - b.5 - Procesar un archivo CSV de ventas ⭐⭐☆☆☆

:::::{exercise}
:label: ejercicio_archivos_5
:enumerator: 5

**Procesar un archivo CSV de ventas**

Escribí una función que lea un archivo `ventas.csv` con el formato
`producto,precio,cantidad`. Por cada línea, debe calcular el total (precio *
cantidad) y mostrarlo en pantalla. La función debe ignorar líneas mal formadas o
vacías.

**Ejemplo de `ventas.csv`:**
``` csv
Teclado Mecanico,150.50,2
Mouse Gamer,75.00,5
Monitor 24 pulgadas,300.25,1
# Esto es un comentario, debe ser ignorado
Webcam,no_es_un_precio,3
```
<!-- csv -->

::::{solution} ejercicio_archivos_5
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1
#define MAX_LINEA 256
#define MAX_PRODUCTO 100

/**
 * Procesa un archivo CSV de ventas, calculando e imprimiendo el total por
   línea.
 *
 * @param nombre_archivo La ruta del archivo CSV a procesar.
 *      #PRE: No puede ser NULL.
 *
 * @returns EXITO si el archivo se procesó (incluso si algunas líneas fallaron),
 *          ERROR si no se pudo abrir el archivo o hubo un error de lectura
            irrecuperable.
 *
 * @post Se imprimirán en la salida estándar los totales de las líneas bien
   formadas.
 */
int procesar_ventas(const char *nombre_archivo)
{
    int estado_general = EXITO;
    FILE *p_archivo = fopen(nombre_archivo, "r");
    char buffer[MAX_LINEA];
    size_t numero_linea = 0;

    if (p_archivo == NULL)
    {
        perror("No se pudo abrir el archivo de ventas");
        return ERROR;
    }

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        numero_linea++;

        // Ignorar líneas vacías o comentarios usando lógica positiva conforme a
        la regla 0x1002h
        if (buffer[0] != '\n' && buffer[0] != '#')
        {
            char nombre_producto[MAX_PRODUCTO];
            double precio = 0.0;
            int cantidad = 0;

            // Usar sscanf para parsear la línea. Formato:
            string-hasta-coma,double,int
            int campos_leidos = sscanf(buffer, "%99[^,],%lf,%d",
            nombre_producto, &precio, &cantidad);

            if (campos_leidos == 3)
            {
                double total_linea = precio * (double)cantidad;
                printf("Línea %zu: Producto \x27%s\x27, Total: %.2f\n",
                numero_linea, nombre_producto, total_linea);
            }
            else
            {
                fprintf(stderr, "[Advertencia] Línea %zu mal formada: %s",
                numero_linea, buffer);
            }
        }
    }

    if (ferror(p_archivo))
    {
        perror("Ocurrió un error de lectura");
        estado_general = ERROR;
    }

    if (fclose(p_archivo) != 0)
    {
        perror("Error al cerrar el archivo de ventas");
        estado_general = ERROR;
    }

    return estado_general;
}

int main(void)
{
    const char *ARCHIVO_VENTAS = "ventas.csv";

    // Crear archivo de ventas de prueba
    FILE *p_temp = fopen(ARCHIVO_VENTAS, "w");
    if (p_temp != NULL)
    {
        fprintf(p_temp, "Teclado Mecanico,150.50,2\n");
        fprintf(p_temp, "Mouse Gamer,75.00,5\n");
        fprintf(p_temp, "\n"); // Línea vacía
        fprintf(p_temp, "Monitor 24 pulgadas,300.25,1\n");
        fprintf(p_temp, "# Esto es un comentario, debe ser ignorado\n");
        fprintf(p_temp, "Webcam,no_es_un_precio,3\n"); // Línea mal formada
        fclose(p_temp);
    }

    printf("Procesando archivo \x27%s\x27...\n", ARCHIVO_VENTAS);
    if (procesar_ventas(ARCHIVO_VENTAS) == ERROR)
    {
        fprintf(stderr, "No se pudo completar el procesamiento del archivo.\n");
        return EXIT_FAILURE;
    }

    printf("\nProcesamiento finalizado.\n");
    return EXIT_SUCCESS;
}

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_5 -->
(ejercicio_13_7)=
### Ejercicio 13.7 - b.6 - Inversión de archivo ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_6
:enumerator: 6

**Inversión de archivo**

Implementá una función `int invertir_archivo(const char *origen, const char
*destino)` que reciba el nombre de un archivo de texto existente (`origen`) y
genere un nuevo archivo (`destino`) que contenga exactamente el mismo texto pero
invertido carácter por carácter (es decir, el último carácter del original será
el primero del nuevo, y así sucesivamente). La función debe usar `fseek` y
`ftell` para determinar el tamaño del archivo y leer los caracteres desde el
final hacia el principio. Debe retornar `0` en caso de éxito y un valor negativo
ante fallas de apertura, posicionamiento o escritura.

-   **[*plus ultra*]:** Garantizar la terminación con `\0` y prevenir
    desbordamientos de búfer validando la capacidad máxima.
-   **[*plus ultra*]:** Soportar la lectura de cadenas con espacios y múltiples
    líneas de manera robusta.

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_6
:class: dropdown

:::{code-block}c
:linenos:
#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR_APERTURA -1
#define ERROR_POSICIONAMIENTO -2
#define ERROR_ESCRITURA -3

int invertir_archivo(const char *origen, const char *destino)
{
    FILE *p_origen = fopen(origen, "r");
    if (p_origen == NULL)
    {
        perror("Error al abrir el archivo de origen");
        return ERROR_APERTURA;
    }

    FILE *p_destino = fopen(destino, "w");
    if (p_destino == NULL)
    {
        perror("Error al abrir el archivo de destino");
        fclose(p_origen);
        return ERROR_APERTURA;
    }

    // Determinar el tamaño del archivo de origen usando fseek y ftell
    if (fseek(p_origen, 0L, SEEK_END) != 0)
    {
        perror("Error al posicionarse al final del archivo");
        fclose(p_origen);
        fclose(p_destino);
        return ERROR_POSICIONAMIENTO;
    }

    long tamanio = ftell(p_origen);
    if (tamanio == -1L)
    {
        perror("Error al obtener la posición actual (tamaño)");
        fclose(p_origen);
        fclose(p_destino);
        return ERROR_POSICIONAMIENTO;
    }

    // Leer carácter por carácter desde el final hacia el inicio
    for (long i = tamanio - 1; i >= 0; i--)
    {
        if (fseek(p_origen, i, SEEK_SET) != 0)
        {
            perror("Error de posicionamiento en el lazo");
            fclose(p_origen);
            fclose(p_destino);
            return ERROR_POSICIONAMIENTO;
        }

        int c = fgetc(p_origen);
        if (c == EOF)
        {
            perror("Error al leer carácter");
            fclose(p_origen);
            fclose(p_destino);
            return ERROR_POSICIONAMIENTO;
        }

        if (fputc(c, p_destino) == EOF)
        {
            perror("Error al escribir carácter en destino");
            fclose(p_origen);
            fclose(p_destino);
            return ERROR_ESCRITURA;
        }
    }

    fclose(p_origen);
    if (fclose(p_destino) != 0)
    {
        perror("Error al cerrar el archivo de destino");
        return ERROR_ESCRITURA;
    }

    return EXITO;
}

int main(void)
{
    const char *ORIGEN = "entrada.txt";
    const char *DESTINO = "salida_invertida.txt";

    // Crear un archivo de prueba
    FILE *f = fopen(ORIGEN, "w");
    if (f != NULL)
    {
        fputs("Ingenieria en Computacion UNRN", f);
        fclose(f);
    }

    printf("Invirtiendo archivo \x27%s\x27 en \x27%s\x27...\n", ORIGEN,
    DESTINO);
    if (invertir_archivo(ORIGEN, DESTINO) == EXITO)
    {
        printf("Archivo invertido exitosamente.\n");
    }
    else
    {
        printf("Ocurrió un error al invertir el archivo.\n");
    }

    return 0;
}

:::
<!-- {code-block}c -->

::::
<!-- {solution} ejercicio_archivos_6 -->

