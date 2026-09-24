---
title: "Ejercicios: Archivos Binarios"
short_title: "5. Archivos Binarios"
---

# Ejercicios de Archivos Binarios

## Acerca de

Estos ejercicios tienen como propósito dominar la manipulación, persistencia estructurada
y acceso aleatorio mediante flujos binarios en C11 utilizando las primitivas `fopen`,
`fread`, `fwrite`, `fseek`, y `ftell`.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-estructuras`
- {ref}`capitulo-archivos-texto`

### Cuestiones de Estilo Aplicables
- **Chequeo de E/S binaria:** Al invocar `fread` y `fwrite`, es mandatorio validar que
  la cantidad de bloques leídos o escritos coincida con el número solicitado.
- **Acceso aleatorio seguro:** Al utilizar `fseek`, calcular los desplazamientos
  multiplicando el índice por `sizeof(tipo_t)` con origen explícito (`SEEK_SET`).
- **Limpieza de recursos:** Todo archivo abierto con `fopen` debe cerrarse con `fclose`.

---

## Estructura de Datos Base

Para los siguientes ejercicios, se utilizará la estructura canónica `producto_t`:

```{code-block} c
:linenos:
typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
} producto_t;
```

---

## Escritura y Lectura Secuencial

(ej_b4_c04_01)=
### Ejercicio 4.04.01 - Serialización de Inventario en Archivo Binario ⭐⭐☆☆☆

:::{exercise}
:label: guardar_inventario
:enumerator: binarios-1

Implementá una función `bool guardar_inventario(const char *ruta, const producto_t *productos, size_t cantidad)`
que guarde un arreglo contiguo de `producto_t` en el archivo binario especificado por `ruta`.
La apertura debe realizarse en modo escritura binaria (`"wb"`). La escritura del lote debe
efectuarse en una única operación `fwrite` y retornar `true` solo si se escribieron exactamente
todos los elementos solicitados.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fwrite`, persistencia de structs, manejo de punteros `FILE *`.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `bool guardar_inventario(const char *ruta, const producto_t *productos, size_t cantidad);`
- **Precondiciones:** `ruta != NULL`, `productos != NULL` (si `cantidad > 0`).
- **Postcondiciones:** Retorna `true` si el archivo se abrió y se escribieron exactamente `cantidad` registros; `false` en caso de error.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`cantidad`, productos) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | 2 productos válidos, ruta accesible | `true` | Escritura exitosa de bloque contiguo |
| **Borde (Cero)** | `cantidad = 0`, productos válidos | `true` | Archivo creado con 0 bytes de contenido |
| **Error (Ruta Inválida)**| Ruta en directorio inexistente | `false` | Fallo de apertura controlado (`fopen == NULL`) |
| **Error (Puntero Nulo)** | `ruta = NULL` | `false` | Manejo defensivo de precondición |

:::
<!-- {exercise} -->

::::{solution} guardar_inventario
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
} producto_t;

bool guardar_inventario(const char *ruta, const producto_t *productos, size_t cantidad)
{
    if (ruta == NULL || (productos == NULL && cantidad > 0))
    {
        return false;
    }

    FILE *archivo = fopen(ruta, "wb");
    if (archivo == NULL)
    {
        return false;
    }

    if (cantidad == 0)
    {
        fclose(archivo);
        return true;
    }

    size_t escritos = fwrite(productos, sizeof(producto_t), cantidad, archivo);
    fclose(archivo);

    return escritos == cantidad;
}

int main(void)
{
    const char *test_path = "test_inventario_tmp.dat";

    producto_t catalogo[2] = {
        {"SKU-001", "Sensor DHT22", 15, 1250.50f},
        {"SKU-002", "Arduino Nano", 8, 4500.00f}
    };

    // Caso normal
    assert(guardar_inventario(test_path, catalogo, 2) == true);

    // Caso cero elementos
    assert(guardar_inventario(test_path, catalogo, 0) == true);

    // Caso defensivo puntero nulo
    assert(guardar_inventario(NULL, catalogo, 2) == false);

    remove(test_path);
    return 0;
}
```

::::
<!-- {solution} guardar_inventario -->

---

(ej_b4_c04_02)=
### Ejercicio 4.04.02 - Carga y Conteo de Inventario Persistido ⭐⭐☆☆☆

:::{exercise}
:label: cargar_inventario
:enumerator: binarios-2

Implementá una función `size_t cargar_inventario(const char *ruta, producto_t *destino, size_t capacidad_maxima)`
que abra el archivo binario en modo lectura (`"rb"`), lea secuencialmente registro por registro
utilizando `fread` y almacene los elementos en el arreglo `destino` sin superar `capacidad_maxima`.
La función debe devolver la cantidad real de registros leídos con éxito.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fread`, detección de fin de archivo (`feof`), buffers fijos.  
**Techo conceptual:** Prohibido el uso de memoria dinámica.

#### Contrato de la Función
- **Firma:** `size_t cargar_inventario(const char *ruta, producto_t *destino, size_t capacidad_maxima);`
- **Precondiciones:** `ruta != NULL`, `destino != NULL`, `capacidad_maxima > 0`.
- **Postcondiciones:** Retorna el número de registros cargados $N \le \text{capacidad\_maxima}$. Si el archivo no existe, retorna 0.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (Archivo, Capacidad) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | Archivo con 2 registros, `capacidad = 5` | `2` | Carga completa de todos los registros |
| **Borde (Truncado)** | Archivo con 5 registros, `capacidad = 2` | `2` | Detención obligatoria por tope de buffer |
| **Error (Inexistente)**| Archivo inexistente | `0` | Manejo seguro de archivo ausente |

:::
<!-- {exercise} -->

::::{solution} cargar_inventario
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
} producto_t;

size_t cargar_inventario(const char *ruta, producto_t *destino, size_t capacidad_maxima)
{
    if (ruta == NULL || destino == NULL || capacidad_maxima == 0)
    {
        return 0;
    }

    FILE *archivo = fopen(ruta, "rb");
    if (archivo == NULL)
    {
        return 0;
    }

    size_t leidos = 0;
    while (leidos < capacidad_maxima && fread(&destino[leidos], sizeof(producto_t), 1, archivo) == 1)
    {
        leidos++;
    }

    fclose(archivo);
    return leidos;
}

int main(void)
{
    const char *test_path = "test_carga_tmp.dat";

    producto_t catalogo[3] = {
        {"A01", "Resistencia 10k", 100, 25.0f},
        {"A02", "Capacitor 100uF", 50, 45.5f},
        {"A03", "Transistor 2N2222", 30, 80.0f}
    };

    FILE *f = fopen(test_path, "wb");
    assert(f != NULL);
    fwrite(catalogo, sizeof(producto_t), 3, f);
    fclose(f);

    producto_t buffer[5];

    // Caso normal
    size_t total = cargar_inventario(test_path, buffer, 5);
    assert(total == 3);
    assert(strcmp(buffer[0].sku, "A01") == 0);
    assert(strcmp(buffer[2].sku, "A03") == 0);

    // Caso capacidad acotada
    size_t parcial = cargar_inventario(test_path, buffer, 2);
    assert(parcial == 2);

    // Caso archivo inexistente
    assert(cargar_inventario("archivo_fantasma_no_existe.dat", buffer, 5) == 0);

    remove(test_path);
    return 0;
}
```

::::
<!-- {solution} cargar_inventario -->

---

## Acceso Aleatorio con `fseek`

(ej_b4_c04_03)=
### Ejercicio 4.04.03 - Lectura de Registro Específico mediante Desplazamiento ⭐⭐☆☆☆

:::{exercise}
:label: leer_registro
:enumerator: binarios-3

Implementá una función `bool leer_registro(const char *ruta, size_t n, producto_t *resultado)`
que lea directamente el $n$-ésimo registro del archivo binario (0-indexado) sin recorrer los
registros previos, utilizando `fseek` con cálculo de offset exacto.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** `fseek(..., SEEK_SET)`, `sizeof`, verificación de offset.  
**Techo conceptual:** Prohibido el barrido secuencial iterativo.

#### Contrato de la Función
- **Firma:** `bool leer_registro(const char *ruta, size_t n, producto_t *resultado);`
- **Precondiciones:** `ruta != NULL`, `resultado != NULL`.
- **Postcondiciones:** Retorna `true` y copia los datos al puntero `resultado` si el registro $n$ existe en el archivo. Retorna `false` si el índice excede el tamaño o si falla la E/S.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (Índice $n$) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | $n = 1$ (2º elemento) | `true` | Acceso directo a posición intermedia |
| **Borde (Inicio)** | $n = 0$ (1º elemento) | `true` | Acceso al primer registro sin desplazamiento |
| **Error (Fuera de Rango)**| $n = 100$ | `false` | Posición más allá del final del archivo |

:::
<!-- {exercise} -->

::::{solution} leer_registro
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
} producto_t;

bool leer_registro(const char *ruta, size_t n, producto_t *resultado)
{
    if (ruta == NULL || resultado == NULL)
    {
        return false;
    }

    FILE *archivo = fopen(ruta, "rb");
    if (archivo == NULL)
    {
        return false;
    }

    long offset = (long)(n * sizeof(producto_t));
    if (fseek(archivo, offset, SEEK_SET) != 0)
    {
        fclose(archivo);
        return false;
    }

    size_t leidos = fread(resultado, sizeof(producto_t), 1, archivo);
    fclose(archivo);

    return leidos == 1;
}

int main(void)
{
    const char *test_path = "test_seek_tmp.dat";

    producto_t lote[3] = {
        {"S0", "Item Cero", 10, 100.0f},
        {"S1", "Item Uno", 20, 200.0f},
        {"S2", "Item Dos", 30, 300.0f}
    };

    FILE *f = fopen(test_path, "wb");
    assert(f != NULL);
    fwrite(lote, sizeof(producto_t), 3, f);
    fclose(f);

    producto_t reg;

    // Caso inicio (n = 0)
    assert(leer_registro(test_path, 0, &reg) == true);
    assert(strcmp(reg.sku, "S0") == 0);

    // Caso intermedio (n = 1)
    assert(leer_registro(test_path, 1, &reg) == true);
    assert(strcmp(reg.sku, "S1") == 0);

    // Caso último (n = 2)
    assert(leer_registro(test_path, 2, &reg) == true);
    assert(strcmp(reg.sku, "S2") == 0);

    // Caso fuera de rango (n = 5)
    assert(leer_registro(test_path, 5, &reg) == false);

    remove(test_path);
    return 0;
}
```

::::
<!-- {solution} leer_registro -->

---

(ej_b4_c04_04)=
### Ejercicio 4.04.04 - Modificación In-Situ de un Registro Binario ⭐⭐⭐☆☆

:::{exercise}
:label: actualizar_stock
:enumerator: binarios-4

Implementá una función `bool actualizar_stock(const char *ruta, size_t n, int nuevo_stock)`
que modifique in-situ únicamente el campo `stock` del registro en la posición $n$, abriendo
el archivo en modo lectura/escritura binaria (`"r+b"` o `"rb+"`).
Debés posicionar el cursor con `fseek`, leer el registro existente, alterar el valor de `stock`,
reposicionar el cursor exactamente en el inicio del registro y sobrescribirlo con `fwrite`.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Modos bidireccionales `"rb+"`, reposicionamiento bidireccional de cursor con `fseek`.  
**Techo conceptual:** Prohibido recrear o truncar el archivo con `"wb"`.

#### Contrato de la Función
- **Firma:** `bool actualizar_stock(const char *ruta, size_t n, int nuevo_stock);`
- **Precondiciones:** `ruta != NULL`, `nuevo_stock >= 0`.
- **Postcondiciones:** Retorna `true` si el registro $n$ fue actualizado sin alterar los registros adyacentes; `false` si el registro no existe o falla la E/S.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada ($n$, nuevo stock) | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- | :--- |
| **Normal** | $n = 1$, `nuevo_stock = 99` | `true` | Modificación in-situ de registro intermedio |
| **Borde (Cero)** | $n = 0$, `nuevo_stock = 0` | `true` | Modificación del primer registro a stock nulo |
| **Error (Fuera de Rango)**| $n = 50$, `nuevo_stock = 10` | `false` | Fallo de lectura del registro destino |

:::
<!-- {exercise} -->

::::{solution} actualizar_stock
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
} producto_t;

bool actualizar_stock(const char *ruta, size_t n, int nuevo_stock)
{
    if (ruta == NULL || nuevo_stock < 0)
    {
        return false;
    }

    FILE *archivo = fopen(ruta, "rb+");
    if (archivo == NULL)
    {
        return false;
    }

    long offset = (long)(n * sizeof(producto_t));
    if (fseek(archivo, offset, SEEK_SET) != 0)
    {
        fclose(archivo);
        return false;
    }

    producto_t reg;
    if (fread(&reg, sizeof(producto_t), 1, archivo) != 1)
    {
        fclose(archivo);
        return false;
    }

    reg.stock = nuevo_stock;

    if (fseek(archivo, offset, SEEK_SET) != 0)
    {
        fclose(archivo);
        return false;
    }

    size_t escritos = fwrite(&reg, sizeof(producto_t), 1, archivo);
    fclose(archivo);

    return escritos == 1;
}

int main(void)
{
    const char *test_path = "test_update_tmp.dat";

    producto_t lote[2] = {
        {"A1", "Item A", 10, 100.0f},
        {"B2", "Item B", 20, 200.0f}
    };

    FILE *f = fopen(test_path, "wb");
    assert(f != NULL);
    fwrite(lote, sizeof(producto_t), 2, f);
    fclose(f);

    // Actualizar registro 1 (B2)
    assert(actualizar_stock(test_path, 1, 99) == true);

    // Verificar persistencia del registro 1 y que el registro 0 no se alteró
    f = fopen(test_path, "rb");
    assert(f != NULL);
    producto_t verificacion[2];
    fread(verificacion, sizeof(producto_t), 2, f);
    fclose(f);

    assert(verificacion[0].stock == 10);
    assert(verificacion[1].stock == 99);
    assert(strcmp(verificacion[1].sku, "B2") == 0);

    // Caso fuera de rango
    assert(actualizar_stock(test_path, 10, 50) == false);

    remove(test_path);
    return 0;
}
```

::::
<!-- {solution} actualizar_stock -->

---

(ej_b4_c04_05)=
### Ejercicio 4.04.05 - Borrado Lógico y Auditoría de Registros Binarios ⭐⭐⭐⭐☆

:::{exercise}
:label: baja_logica_binaria
:enumerator: binarios-5

En sistemas embebidos y bases de datos transaccionales, el borrado físico de registros es costoso porque
requiere reescribir todo el archivo. En su lugar, se utiliza el **borrado lógico** mediante una bandera de estado.

Dada la siguiente estructura de registro:
```c
typedef struct {
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
    bool activo;
} item_inventario_t;
```

Implementá dos funciones:
1. `bool marcar_baja_logica(const char *ruta, size_t n)`: abre el archivo en `"rb+"`, posiciona el cursor en el registro $n$, lee el registro, actualiza `activo = false`, y lo sobrescribe in-situ.
2. `size_t contar_registros_activos(const char *ruta)`: recorre secuencialmente el archivo en modo `"rb"` y retorna cuántos registros tienen `activo == true`. Si el archivo no existe o está vacío, retorna `0`.

**Nivel de Bloom:** Nivel 4 (Análisis).  
**Conceptos requeridos:** Modos bidireccionales `"rb+"`, `fseek` relativo al tamaño de estructura, lectura secuencial `fread`, banderas de borrado lógico.  
**Techo conceptual:** Prohibido compactar o recrear el archivo en disco.

#### Contrato de las Funciones
- **Firma 1:** `bool marcar_baja_logica(const char *ruta, size_t n);`
- **Firma 2:** `size_t contar_registros_activos(const char *ruta);`
- **Precondiciones:** `ruta != NULL`.
- **Postcondiciones:** `marcar_baja_logica` retorna `true` si el registro fue dado de baja lógicamente, `false` si no existe o falla la E/S.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Estado Inicial (3 registros activos) | Acción | Conteo de Activos Posterior | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | 3 registros activos | Baja de registro 1 | `2` | Modificación in-situ de bandera de estado |
| **Borde (Primer registro)**| 2 registros activos restantes | Baja de registro 0 | `1` | Baja lógica de cabecera |
| **Error (Fuera de Rango)**| 1 registro activo | Baja de registro 10 | `1` (sin cambios) | Rechazo seguro ante offset inválido |

:::
<!-- {exercise} -->

::::{solution} baja_logica_binaria
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char sku[12];
    char nombre[32];
    int stock;
    float precio;
    bool activo;
} item_inventario_t;

bool marcar_baja_logica(const char *ruta, size_t n)
{
    if (ruta == NULL)
    {
        return false;
    }

    FILE *archivo = fopen(ruta, "rb+");
    if (archivo == NULL)
    {
        return false;
    }

    long offset = (long)(n * sizeof(item_inventario_t));
    if (fseek(archivo, offset, SEEK_SET) != 0)
    {
        fclose(archivo);
        return false;
    }

    item_inventario_t reg;
    if (fread(&reg, sizeof(item_inventario_t), 1, archivo) != 1)
    {
        fclose(archivo);
        return false;
    }

    reg.activo = false;

    if (fseek(archivo, offset, SEEK_SET) != 0)
    {
        fclose(archivo);
        return false;
    }

    size_t escritos = fwrite(&reg, sizeof(item_inventario_t), 1, archivo);
    fclose(archivo);

    return escritos == 1;
}

size_t contar_registros_activos(const char *ruta)
{
    if (ruta == NULL)
    {
        return 0;
    }

    FILE *archivo = fopen(ruta, "rb");
    if (archivo == NULL)
    {
        return 0;
    }

    size_t total_activos = 0;
    item_inventario_t reg;

    while (fread(&reg, sizeof(item_inventario_t), 1, archivo) == 1)
    {
        if (reg.activo)
        {
            total_activos++;
        }
    }

    fclose(archivo);
    return total_activos;
}

int main(void)
{
    const char *test_path = "test_baja_logica_tmp.dat";

    item_inventario_t lote[3] = {
        {"SKU-1", "Teclado", 15, 45.0f, true},
        {"SKU-2", "Mouse", 30, 25.0f, true},
        {"SKU-3", "Monitor", 8, 180.0f, true}
    };

    FILE *f = fopen(test_path, "wb");
    assert(f != NULL);
    fwrite(lote, sizeof(item_inventario_t), 3, f);
    fclose(f);

    // Conteo inicial
    assert(contar_registros_activos(test_path) == 3);

    // Baja del registro intermedio (Mouse)
    assert(marcar_baja_logica(test_path, 1) == true);
    assert(contar_registros_activos(test_path) == 2);

    // Baja del primer registro (Teclado)
    assert(marcar_baja_logica(test_path, 0) == true);
    assert(contar_registros_activos(test_path) == 1);

    // Intento fuera de rango
    assert(marcar_baja_logica(test_path, 10) == false);
    assert(contar_registros_activos(test_path) == 1);

    // Archivo inexistente
    assert(contar_registros_activos("archivo_que_no_existe_xyz.dat") == 0);

    remove(test_path);
    return 0;
}
```

::::
<!-- {solution} baja_logica_binaria -->

---

(ej_b4_c04_06)=
### Ejercicio 4.04.06 - Integridad de Cabecera Binaria con Magic Number y Checksum ⭐⭐⭐☆☆

:::{exercise}
:label: cabecera_binaria_checksum
:enumerator: binarios-6

En formatos binarios profesionales (como imágenes PNG, ejecutables ELF o contenedores de base de datos), los primeros bytes del archivo forman una **cabecera estructurada** que identifica el formato (*magic number*), la versión del esquema y mecanismos de detección de corrupción mediante sumas de verificación (*checksum*).

Dada la siguiente cabecera empaquetada:
```c
#define MAGIC_UNRN 0x50314150U /* "P1AP" */

typedef struct {
    uint32_t magic;
    uint16_t version;
    uint16_t cant_bytes;
    uint32_t checksum;
} cabecera_archivo_t;
```

Implementá dos funciones de persistencia robusta:
1. `bool escribir_archivo_protegido(const char *ruta, const uint8_t *payload, uint16_t tam)`:
   - Calcula el *checksum* sumando algebraicamente cada byte de `payload` (`uint32_t`).
   - Escribe la estructura `cabecera_archivo_t` al inicio y luego el arreglo `payload`.
   - Cierra el archivo y retorna `true` ante éxito o `false` ante error de E/S o punteros nulos.
2. `bool verificar_y_leer_archivo(const char *ruta, uint8_t *buffer_out, uint16_t cap, uint16_t *bytes_leidos)`:
   - Abre el archivo en `"rb"`.
   - Lee la cabecera y verifica que `magic == MAGIC_UNRN`, `version == 1` y `cant_bytes <= cap`.
   - Lee `cant_bytes` del payload, calcula la suma de comprobación y verifica que coincida con `checksum`.
   - Si todo es correcto, escribe `*bytes_leidos = cant_bytes` y retorna `true`. Si hay corrupción o inconsistencia, retorna `false`.

**Nivel de Bloom:** Nivel 4 (Análisis / Aplicación).  
**Conceptos requeridos:** `uint32_t`, lectura/escritura de cabeceras, cálculo determinístico de sumas de comprobación, validación de integridad.

#### Tabla de Vectores de Prueba Obligatorios

| Caso de Prueba | Entrada de Datos | Acción / Modificación | Retorno Esperado | Estado de Verificación |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | Payload `{0x10, 0x20, 0x30, 0x40}` | Escritura y lectura directa | `true` | Checksum válido (`0xA0`) |
| **Cabecera Inválida** | Payload normal | Se altera el magic number a `0x00` | `false` | Detección de formato desconocido |
| **Corrupción de Payload** | Payload normal | Se muta un byte de datos en disco | `false` | Detección de checksum discordante |
| **Buffer insuficiente** | Payload de 4 bytes | Capacidad de buffer solicitada = 2 | `false` | Prevención de buffer overflow |

:::
<!-- {exercise} cabecera_binaria_checksum -->

::::{solution} cabecera_binaria_checksum
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define MAGIC_UNRN 0x50314150U /* "P1AP" */

typedef struct {
    uint32_t magic;
    uint16_t version;
    uint16_t cant_bytes;
    uint32_t checksum;
} cabecera_archivo_t;

static uint32_t calcular_checksum(const uint8_t *datos, uint16_t tam) {
    uint32_t suma = 0;
    for (uint16_t i = 0; i < tam; i++) {
        suma += datos[i];
    }
    return suma;
}

bool escribir_archivo_protegido(const char *ruta, const uint8_t *payload, uint16_t tam) {
    if (ruta == NULL || (tam > 0 && payload == NULL)) {
        return false;
    }

    FILE *f = fopen(ruta, "wb");
    if (f == NULL) {
        return false;
    }

    cabecera_archivo_t hdr;
    hdr.magic = MAGIC_UNRN;
    hdr.version = 1;
    hdr.cant_bytes = tam;
    hdr.checksum = calcular_checksum(payload, tam);

    if (fwrite(&hdr, sizeof(cabecera_archivo_t), 1, f) != 1) {
        fclose(f);
        return false;
    }

    if (tam > 0 && fwrite(payload, sizeof(uint8_t), tam, f) != tam) {
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

bool verificar_y_leer_archivo(const char *ruta, uint8_t *buffer_out, uint16_t cap, uint16_t *bytes_leidos) {
    if (ruta == NULL || buffer_out == NULL || bytes_leidos == NULL) {
        return false;
    }

    FILE *f = fopen(ruta, "rb");
    if (f == NULL) {
        return false;
    }

    cabecera_archivo_t hdr;
    if (fread(&hdr, sizeof(cabecera_archivo_t), 1, f) != 1) {
        fclose(f);
        return false;
    }

    if (hdr.magic != MAGIC_UNRN || hdr.version != 1 || hdr.cant_bytes > cap) {
        fclose(f);
        return false;
    }

    if (hdr.cant_bytes > 0 && fread(buffer_out, sizeof(uint8_t), hdr.cant_bytes, f) != hdr.cant_bytes) {
        fclose(f);
        return false;
    }

    fclose(f);

    uint32_t suma_calculada = calcular_checksum(buffer_out, hdr.cant_bytes);
    if (suma_calculada != hdr.checksum) {
        return false;
    }

    *bytes_leidos = hdr.cant_bytes;
    return true;
}

int main(void) {
    const char *test_file = "test_chk_tmp.bin";
    uint8_t datos_orig[4] = {0x10, 0x20, 0x30, 0x40};
    uint8_t buffer_dest[16];
    uint16_t leidos = 0;

    // Caso Normal
    assert(escribir_archivo_protegido(test_file, datos_orig, 4) == true);
    assert(verificar_y_leer_archivo(test_file, buffer_dest, sizeof(buffer_dest), &leidos) == true);
    assert(leidos == 4);
    assert(buffer_dest[0] == 0x10 && buffer_dest[3] == 0x40);

    // Buffer insuficiente
    assert(verificar_y_leer_archivo(test_file, buffer_dest, 2, &leidos) == false);

    // Corrupción de payload en disco
    FILE *f = fopen(test_file, "rb+");
    assert(f != NULL);
    assert(fseek(f, (long)sizeof(cabecera_archivo_t), SEEK_SET) == 0);
    fputc(0xFF, f); // Altera el primer byte del payload
    fclose(f);
    assert(verificar_y_leer_archivo(test_file, buffer_dest, sizeof(buffer_dest), &leidos) == false);

    // Corrupción de magic number
    f = fopen(test_file, "rb+");
    assert(f != NULL);
    assert(fseek(f, 0, SEEK_SET) == 0);
    uint32_t bad_magic = 0;
    fwrite(&bad_magic, sizeof(uint32_t), 1, f);
    fclose(f);
    assert(verificar_y_leer_archivo(test_file, buffer_dest, sizeof(buffer_dest), &leidos) == false);

    remove(test_file);
    return 0;
}
```
::::
<!-- {solution} cabecera_binaria_checksum -->
