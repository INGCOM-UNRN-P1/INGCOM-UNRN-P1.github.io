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
