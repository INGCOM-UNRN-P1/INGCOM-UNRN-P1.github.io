---
title: 'Ejercicios Resueltos: Archivos de Texto'
short_title: '3b. Ejercicios Archivos'
subtitle: 'Problemas y soluciones detalladas sobre streams y persistencia en C'
---

# Ejercicios Resueltos: Archivos de Texto

## Acerca de

Estos ejercicios profundizan en la manipulación, lectura formateada, escritura y
persistencia de datos usando streams estándar de E/S (`FILE *`) en C11.

### Capítulos de Apunte Correspondientes
- {ref}`trabajando-con-archivos-de-texto-en-c`

### Cuestiones de Estilo Aplicables
- **Manejo defensivo de archivos:** Asegurá siempre la validación del puntero
  retornado por `fopen` y liberá el descriptor de archivo llamando a `fclose` en
  todas las ramas de control de errores.
- **Validación de buffer:** Evitá desbordamientos de buffer pasando siempre la
  capacidad límite al leer flujos con `fgets`.
- **Limpieza de recursos:** Si se generan archivos temporales durante la ejecución de
  pruebas, deben eliminarse sistemáticamente con `remove()` al concluir.

---

(ej_b2_c04b_01)=
### Ejercicio 2.04b.01 - Escritura de Entradas en un Diario Personal ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_1
:enumerator: 1

Implementá una función `int agregar_entrada_diario(const char *nombre_archivo, const char *entrada)`
que abra el archivo especificado en modo adición (*append*, `"a"`) y escriba la cadena de
texto seguida de un salto de línea (`\n`). La función debe manejar defensivamente los errores
de apertura, escritura y cierre.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fopen` con modo `"a"`, `fputs`, `fputc`, `fclose`.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `int agregar_entrada_diario(const char *nombre_archivo, const char *entrada);`
- **Precondiciones:** `nombre_archivo != NULL`, `entrada != NULL`.
- **Postcondiciones:** Retorna `0` en caso de éxito. Retorna `-1` si falla la apertura, escritura o cierre. El archivo contiene la cadena agregada al final con un `\n`.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`nombre_archivo`, `entrada`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | Archivo accesible, `"Primer registro"` | `0` | Escritura correcta en modo append |
| **Normal (Múltiple)** | Mismo archivo, `"Segundo registro"` | `0` | Adición consecutiva sin truncar |
| **Borde (Vacía)** | Archivo accesible, `""` | `0` | Escribe solo salto de línea |
| **Error (Ruta Nula)**| `NULL`, `"Texto"` | `-1` | Validación defensiva de precondición |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_1
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1

int agregar_entrada_diario(const char *nombre_archivo, const char *entrada)
{
    if (nombre_archivo == NULL || entrada == NULL)
    {
        return ERROR;
    }

    FILE *p_archivo = fopen(nombre_archivo, "a");
    if (p_archivo == NULL)
    {
        return ERROR;
    }

    if (fputs(entrada, p_archivo) == EOF)
    {
        fclose(p_archivo);
        return ERROR;
    }

    if (fputc('\n', p_archivo) == EOF)
    {
        fclose(p_archivo);
        return ERROR;
    }

    if (fclose(p_archivo) != 0)
    {
        return ERROR;
    }

    return EXITO;
}

int main(void)
{
    const char *test_file = "test_diario_tmp.txt";
    remove(test_file);

    // Caso normal
    assert(agregar_entrada_diario(test_file, "Primera entrada") == EXITO);

    // Caso múltiple
    assert(agregar_entrada_diario(test_file, "Segunda entrada") == EXITO);

    // Caso cadena vacía
    assert(agregar_entrada_diario(test_file, "") == EXITO);

    // Caso punteros nulos
    assert(agregar_entrada_diario(NULL, "Texto") == ERROR);
    assert(agregar_entrada_diario(test_file, NULL) == ERROR);

    // Verificar contenido persistido
    FILE *f = fopen(test_file, "r");
    assert(f != NULL);
    char buf[128];
    assert(fgets(buf, sizeof(buf), f) != NULL);
    assert(strcmp(buf, "Primera entrada\n") == 0);
    assert(fgets(buf, sizeof(buf), f) != NULL);
    assert(strcmp(buf, "Segunda entrada\n") == 0);
    assert(fgets(buf, sizeof(buf), f) != NULL);
    assert(strcmp(buf, "\n") == 0);
    fclose(f);

    remove(test_file);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_1 -->

---

(ej_b2_c04b_02)=
### Ejercicio 2.04b.02 - Conteo Seguro de Líneas en Archivo de Texto ⭐⭐⭐☆☆

:::{exercise}
:label: ejercicio_archivos_2
:enumerator: 2

Escribí una función `int contar_lineas(const char *nombre_archivo)` que lea un archivo
de texto y retorne la cantidad de líneas que contiene. Una línea se define como cada bloque
delimitado por un carácter `\n`. En caso de que el archivo no termine con `\n` pero contenga
caracteres residuales antes de EOF, debe contabilizarse como línea final.
Si ocurre un error de apertura o lectura, la función debe devolver un valor negativo.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fopen`, `fgets`, `ferror`, detección de EOF.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `int contar_lineas(const char *nombre_archivo);`
- **Precondiciones:** `nombre_archivo != NULL`.
- **Postcondiciones:** Retorna el total de líneas $\ge 0$. Retorna `-1` si no puede abrirse y `-2` si ocurre error de lectura.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`nombre_archivo`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | Archivo con 3 líneas con `\n` | `3` | Conteo exacto estándar |
| **Borde (Vacío)** | Archivo de 0 bytes | `0` | Archivo vacío sin líneas |
| **Borde (1 Línea)** | 1 línea con `\n` | `1` | Archivo mínimo unitario |
| **Error (Inexistente)**| Ruta inexistente | `-1` | Fallo controlado de apertura |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_2
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD_LINEA 1024
#define ERROR_APERTURA -1
#define ERROR_LECTURA -2

int contar_lineas(const char *nombre_archivo)
{
    if (nombre_archivo == NULL)
    {
        return ERROR_APERTURA;
    }

    FILE *p_archivo = fopen(nombre_archivo, "r");
    if (p_archivo == NULL)
    {
        return ERROR_APERTURA;
    }

    int cantidad_lineas = 0;
    char buffer[MAX_LONGITUD_LINEA];

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        cantidad_lineas++;
    }

    if (ferror(p_archivo))
    {
        fclose(p_archivo);
        return ERROR_LECTURA;
    }

    fclose(p_archivo);
    return cantidad_lineas;
}

int main(void)
{
    const char *test_file = "test_contar_tmp.txt";

    // Caso 3 líneas
    FILE *f = fopen(test_file, "w");
    assert(f != NULL);
    fputs("Linea 1\nLinea 2\nLinea 3\n", f);
    fclose(f);
    assert(contar_lineas(test_file) == 3);

    // Caso archivo vacío
    f = fopen(test_file, "w");
    assert(f != NULL);
    fclose(f);
    assert(contar_lineas(test_file) == 0);

    // Caso 1 línea
    f = fopen(test_file, "w");
    assert(f != NULL);
    fputs("Unica linea\n", f);
    fclose(f);
    assert(contar_lineas(test_file) == 1);

    // Caso archivo inexistente
    assert(contar_lineas("archivo_inexistente_999.txt") == ERROR_APERTURA);

    remove(test_file);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_2 -->

---

(ej_b2_c04b_03)=
### Ejercicio 2.04b.03 - Copia Robusta de Archivo de Texto ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_3
:enumerator: 3

Implementá una función `int copiar_archivo(const char *origen, const char *destino)`
que clone el contenido de un archivo de texto en otro nuevo, leyendo y escribiendo bloque a bloque
mediante un búfer de tamaño acotado. La función debe garantizar que todos los descriptores abiertos
sean cerrados de forma limpia, incluso ante fallas intermedias de escritura.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fopen` (`"r"` y `"w"`), `fgets`, `fputs`, manejo simultáneo de dos archivos.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `int copiar_archivo(const char *origen, const char *destino);`
- **Precondiciones:** `origen != NULL`, `destino != NULL`, `strcmp(origen, destino) != 0`.
- **Postcondiciones:** Retorna `0` en caso de éxito. Retorna `-1` si falla la apertura o copia. El archivo destino contiene exactamente los mismos caracteres que el origen.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`origen`, `destino`) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | Archivo de origen con texto | `0` | Copia fiel y completa |
| **Borde (Vacío)** | Archivo origen de 0 bytes | `0` | Destino creado con 0 bytes |
| **Error (Origen Inexistente)**| Origen inexistente | `-1` | Fallo de apertura de origen |
| **Error (Mismo Archivo)**| Mismo nombre en ambos | `-1` | Prevención de truncamiento accidental |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_3
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1
#define MAX_BUFFER 1024

int copiar_archivo(const char *origen, const char *destino)
{
    if (origen == NULL || destino == NULL || strcmp(origen, destino) == 0)
    {
        return ERROR;
    }

    FILE *f_orig = fopen(origen, "r");
    if (f_orig == NULL)
    {
        return ERROR;
    }

    FILE *f_dest = fopen(destino, "w");
    if (f_dest == NULL)
    {
        fclose(f_orig);
        return ERROR;
    }

    char buffer[MAX_BUFFER];
    int estado = EXITO;

    while (fgets(buffer, sizeof(buffer), f_orig) != NULL)
    {
        if (fputs(buffer, f_dest) == EOF)
        {
            estado = ERROR;
            break;
        }
    }

    if (ferror(f_orig))
    {
        estado = ERROR;
    }

    fclose(f_orig);
    if (fclose(f_dest) != 0)
    {
        estado = ERROR;
    }

    return estado;
}

int main(void)
{
    const char *orig = "test_copia_orig.txt";
    const char *dest = "test_copia_dest.txt";

    // Caso normal
    FILE *f = fopen(orig, "w");
    assert(f != NULL);
    fputs("Línea uno de prueba.\nLínea dos.\n", f);
    fclose(f);

    assert(copiar_archivo(orig, dest) == EXITO);

    FILE *fd = fopen(dest, "r");
    assert(fd != NULL);
    char buf[128];
    assert(fgets(buf, sizeof(buf), fd) != NULL);
    assert(strcmp(buf, "Línea uno de prueba.\n") == 0);
    assert(fgets(buf, sizeof(buf), fd) != NULL);
    assert(strcmp(buf, "Línea dos.\n") == 0);
    fclose(fd);

    // Caso error mismo archivo
    assert(copiar_archivo(orig, orig) == ERROR);

    // Caso error origen inexistente
    assert(copiar_archivo("no_existe.txt", dest) == ERROR);

    remove(orig);
    remove(dest);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_3 -->

---

(ej_b2_c04b_04)=
### Ejercicio 2.04b.04 - Registro de Eventos con Marca de Nivel en Archivo Log ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_4
:enumerator: 4

Implementá una función `int registrar_log(const char *archivo_log, const char *nivel, const char *mensaje)`
que formatee y agregue una línea en un archivo de registro con la sintaxis:
`[NIVEL] mensaje\n`.
El archivo debe abrirse en modo adición (`"a"`). Si los parámetros son nulos, la función debe fallar defensivamente.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fopen` con `"a"`, `fprintf`, control de flujo defensivo.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `int registrar_log(const char *archivo_log, const char *nivel, const char *mensaje);`
- **Precondiciones:** `archivo_log != NULL`, `nivel != NULL`, `mensaje != NULL`.
- **Postcondiciones:** Retorna `0` si se escribió la línea correctamente. Retorna `-1` ante cualquier fallo.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`nivel`, `mensaje`) | Formato Esperado en Archivo | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `"INFO"`, `"Sistema iniciado"` | `"[INFO] Sistema iniciado\n"` | Registro informativo estándar |
| **Normal** | `"ERROR"`, `"Fallo de red"` | `"[ERROR] Fallo de red\n"` | Registro de nivel crítico |
| **Error (Nulo)** | `NULL`, `"Mensaje"` | Retorna `-1` | Rechazo por parámetro nulo |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_4
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1

int registrar_log(const char *archivo_log, const char *nivel, const char *mensaje)
{
    if (archivo_log == NULL || nivel == NULL || mensaje == NULL)
    {
        return ERROR;
    }

    FILE *p_log = fopen(archivo_log, "a");
    if (p_log == NULL)
    {
        return ERROR;
    }

    if (fprintf(p_log, "[%s] %s\n", nivel, mensaje) < 0)
    {
        fclose(p_log);
        return ERROR;
    }

    if (fclose(p_log) != 0)
    {
        return ERROR;
    }

    return EXITO;
}

int main(void)
{
    const char *log_file = "test_eventos_tmp.log";
    remove(log_file);

    // Casos normales
    assert(registrar_log(log_file, "INFO", "Sistema iniciado") == EXITO);
    assert(registrar_log(log_file, "ERROR", "Fallo de red") == EXITO);

    // Casos nulos
    assert(registrar_log(NULL, "INFO", "Mensaje") == ERROR);
    assert(registrar_log(log_file, NULL, "Mensaje") == ERROR);
    assert(registrar_log(log_file, "INFO", NULL) == ERROR);

    // Verificar contenido
    FILE *f = fopen(log_file, "r");
    assert(f != NULL);
    char buf[128];
    assert(fgets(buf, sizeof(buf), f) != NULL);
    assert(strcmp(buf, "[INFO] Sistema iniciado\n") == 0);
    assert(fgets(buf, sizeof(buf), f) != NULL);
    assert(strcmp(buf, "[ERROR] Fallo de red\n") == 0);
    fclose(f);

    remove(log_file);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_4 -->

---

(ej_b2_c04b_05)=
### Ejercicio 2.04b.05 - Procesamiento y Suma Total de Ventas en CSV ⭐⭐☆☆☆

:::{exercise}
:label: ejercicio_archivos_5
:enumerator: 5

Implementá una función `double calcular_total_ventas_csv(const char *nombre_archivo)`
que procese un archivo CSV con formato `producto,precio,cantidad`.
La función debe parsear cada línea con `sscanf`, calcular el subtotal (`precio * cantidad`),
acumular el total general de todas las líneas válidas e ignorar comentarios (iniciados con `#`)
o líneas en blanco. Si el archivo no existe o ocurre un error irrecuperable, retorna `-1.0`.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** `fgets`, `sscanf` con máscaras de exclusión (`%99[^,]`), acumuladores en punto flotante.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `double calcular_total_ventas_csv(const char *nombre_archivo);`
- **Precondiciones:** `nombre_archivo != NULL`.
- **Postcondiciones:** Retorna la suma total acumulada $\ge 0.0$. Retorna `-1.0` si el archivo no puede abrirse.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Contenido del Archivo | Total Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | 2 items válidos: `Teclado,100.0,2` y `Mouse,50.0,3` | `350.0` | $100 \times 2 + 50 \times 3 = 350.0$ |
| **Borde (Comentarios)**| Líneas vacías y comentarios `# comentario` intercalados | `350.0` | Omisión correcta de ruido |
| **Borde (Malformado)**| Línea mal formada `Webcam,invalido,3` ignorada | `350.0` | Resiliencia ante datos corruptos |
| **Error (Inexistente)**| Archivo ausente | `-1.0` | Señal de error controlada |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_5
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 256
#define MAX_PRODUCTO 100

double calcular_total_ventas_csv(const char *nombre_archivo)
{
    if (nombre_archivo == NULL)
    {
        return -1.0;
    }

    FILE *p_archivo = fopen(nombre_archivo, "r");
    if (p_archivo == NULL)
    {
        return -1.0;
    }

    char buffer[MAX_LINEA];
    double total_acumulado = 0.0;

    while (fgets(buffer, sizeof(buffer), p_archivo) != NULL)
    {
        if (buffer[0] == '\n' || buffer[0] == '#' || buffer[0] == '\r')
        {
            continue;
        }

        char nombre[MAX_PRODUCTO];
        double precio = 0.0;
        int cantidad = 0;

        int leidos = sscanf(buffer, "%99[^,],%lf,%d", nombre, &precio, &cantidad);
        if (leidos == 3 && precio >= 0.0 && cantidad >= 0)
        {
            total_acumulado += precio * (double)cantidad;
        }
    }

    fclose(p_archivo);
    return total_acumulado;
}

int main(void)
{
    const char *csv_file = "test_ventas_tmp.csv";

    FILE *f = fopen(csv_file, "w");
    assert(f != NULL);
    fputs("Teclado Mecanico,100.0,2\n", f);
    fputs("# Comentario de encabezado\n", f);
    fputs("\n", f);
    fputs("Mouse Gamer,50.0,3\n", f);
    fputs("Webcam,precio_corrupto,1\n", f);
    fclose(f);

    double total = calcular_total_ventas_csv(csv_file);
    assert(fabs(total - 350.0) < 0.001);

    // Caso archivo inexistente
    assert(calcular_total_ventas_csv("inexistente.csv") < 0.0);

    remove(csv_file);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_5 -->

---

(ej_b2_c04b_06)=
### Ejercicio 2.04b.06 - Inversión Carácter por Carácter con `fseek` ⭐⭐⭐☆☆

:::{exercise}
:label: ejercicio_archivos_6
:enumerator: 6

Implementá una función `int invertir_archivo(const char *origen, const char *destino)`
que lea un archivo de texto desde el último carácter hacia el primero empleando `fseek`
con desplazamiento negativo y `SEEK_END`, y escriba el contenido invertido en el archivo `destino`.
Debe retornar `0` en caso de éxito y `-1` ante cualquier fallo de apertura o E/S.

**Nivel de Bloom:** Nivel 3 (Aplicación) y Nivel 4 (Análisis).  
**Conceptos requeridos:** `fseek(f, offset, SEEK_END)`, `ftell`, `fgetc`, `fputc`.  
**Techo conceptual:** Prohibido cargar todo el archivo en un búfer o array en memoria.

#### Contrato de la Función
- **Firma:** `int invertir_archivo(const char *origen, const char *destino);`
- **Precondiciones:** `origen != NULL`, `destino != NULL`, `strcmp(origen, destino) != 0`.
- **Postcondiciones:** Retorna `0` si el archivo fue invertido. Retorna `-1` si falla la apertura o el acceso.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Contenido Origen | Contenido Destino Invertido | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | `"ABC"` | `"CBA"` | Inversión directa simple |
| **Normal** | `"Hola Mundo"` | `"odnuM aloH"` | Preservación de espacios |
| **Borde (1 Char)** | `"X"` | `"X"` | Archivo unitario |
| **Borde (Vacío)** | `""` | `""` | Archivo de 0 bytes |

:::
<!-- {exercise} -->

::::{solution} ejercicio_archivos_6
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1

int invertir_archivo(const char *origen, const char *destino)
{
    if (origen == NULL || destino == NULL || strcmp(origen, destino) == 0)
    {
        return ERROR;
    }

    FILE *f_orig = fopen(origen, "rb");
    if (f_orig == NULL)
    {
        return ERROR;
    }

    if (fseek(f_orig, 0, SEEK_END) != 0)
    {
        fclose(f_orig);
        return ERROR;
    }

    long tamano = ftell(f_orig);
    if (tamano < 0)
    {
        fclose(f_orig);
        return ERROR;
    }

    FILE *f_dest = fopen(destino, "wb");
    if (f_dest == NULL)
    {
        fclose(f_orig);
        return ERROR;
    }

    for (long i = 1; i <= tamano; i++)
    {
        if (fseek(f_orig, -i, SEEK_END) != 0)
        {
            fclose(f_orig);
            fclose(f_dest);
            return ERROR;
        }

        int c = fgetc(f_orig);
        if (c == EOF)
        {
            fclose(f_orig);
            fclose(f_dest);
            return ERROR;
        }

        if (fputc(c, f_dest) == EOF)
        {
            fclose(f_orig);
            fclose(f_dest);
            return ERROR;
        }
    }

    fclose(f_orig);
    if (fclose(f_dest) != 0)
    {
        return ERROR;
    }

    return EXITO;
}

int main(void)
{
    const char *orig = "test_inv_orig.txt";
    const char *dest = "test_inv_dest.txt";

    // Caso normal
    FILE *f = fopen(orig, "wb");
    assert(f != NULL);
    fputs("ABC", f);
    fclose(f);

    assert(invertir_archivo(orig, dest) == EXITO);

    FILE *fd = fopen(dest, "rb");
    assert(fd != NULL);
    char buf[16] = {0};
    assert(fread(buf, 1, 3, fd) == 3);
    assert(strcmp(buf, "CBA") == 0);
    fclose(fd);

    // Caso un caracter
    f = fopen(orig, "wb");
    assert(f != NULL);
    fputs("X", f);
    fclose(f);

    assert(invertir_archivo(orig, dest) == EXITO);

    fd = fopen(dest, "rb");
    assert(fd != NULL);
    memset(buf, 0, sizeof(buf));
    assert(fread(buf, 1, 1, fd) == 1);
    assert(strcmp(buf, "X") == 0);
    fclose(fd);

    remove(orig);
    remove(dest);
    return 0;
}
```

::::
<!-- {solution} ejercicio_archivos_6 -->
