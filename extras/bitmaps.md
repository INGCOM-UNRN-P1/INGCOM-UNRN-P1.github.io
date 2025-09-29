---
title: Creación de Imágenes de Mapa de Bits
short_title: Bitmaps
subtitle: Para crear salidas gráficas.
numbering:
  code: true
---

## Introducción

El formato de archivo de mapa de bits (BMP, de _Bitmap_), también conocido como
mapa de bits independiente del dispositivo (DIB), es un formato de imagen
rasterizada desarrollado por Microsoft. Su principal característica, en su
variante más común, es la simplicidad: no utiliza compresión, lo que significa
que cada píxel se almacena directamente con su valor de color. Esto hace que los
archivos sean grandes en comparación con formatos como PNG o JPEG, pero a su
vez, muy fáciles de leer y escribir mediante programación, lo que los convierte
en una excelente herramienta de aprendizaje.

En este apunte, exploraremos cómo crear un archivo BMP desde cero en C,
manejando directamente la escritura de las cabeceras y los datos de los píxeles
en el archivo. Seguiremos las pautas de estilo de {ref}`0x0000h` para asegurar
que nuestro código sea claro y mantenible.

:::{note} Antes de seguir

Es importante que, antes de encarar esta guía, ya hayas leído los apuntes sobre
estructuras, [archivos binarios](binarios.md) y [manipulación de bits](bits.md)
para entender todo sin dificultad.

:::

## ¿Cómo son los archivos?

Un archivo BMP se compone principalmente de tres o cuatro partes:

1.  **Cabecera del Archivo (File Header):** Identifica el archivo como un BMP y
    contiene información sobre su tamaño total.
2.  **Cabecera de Información (DIB Header):** Describe los atributos de la
    imagen, como sus dimensiones y profundidad de color.
3.  **Tabla de Colores (Paleta):** Opcional. Se utiliza para imágenes con 256
    colores o menos (8 bits, 4 bits, 1 bit).
4.  **Datos de Píxeles (Pixel Array):** Una secuencia de bytes que definen el
    color de cada píxel de la imagen.

## Alineación de Estructuras y `#pragma pack`

Antes de definir las estructuras de las cabeceras, debemos abordar un concepto
crucial: la **alineación de memoria**.

### ¿Qué es la Alineación y por qué existe?

Por razones de rendimiento, los compiladores de C suelen añadir bytes de relleno
(padding) invisibles dentro de las estructuras. El objetivo es que cada miembro
de la estructura comience en una dirección de memoria que sea un múltiplo de su
propio tamaño. Por ejemplo, un `uint32_t` (4 bytes) se alineará preferentemente
en una dirección de memoria divisible por 4. Acceder a datos alineados es mucho
más rápido para la mayoría de las arquitecturas de CPU.

### El Problema con los Formatos de Archivo

Los formatos de archivo binarios como BMP definen una secuencia de bytes exacta
y contigua. No hay bytes de relleno. Si declaramos una `struct` en C y la
escribimos directamente en un archivo, el compilador podría haber insertado
bytes de padding, corrompiendo el archivo y haciéndolo ilegible para otros
programas.

Por ejemplo, nuestra `cabecera_archivo_bmp_t` tiene un `uint16_t` seguido de un
`uint32_t`. Un compilador podría añadir 2 bytes de relleno después del
`uint16_t` para que el `uint32_t` comience en una dirección alineada a 4 bytes.
Esto haría que la estructura tuviera 16 bytes en memoria en lugar de los 14 que
especifica el formato BMP.

### La Solución: `#pragma pack`

Para solucionar esto, usamos la directiva de preprocesador `#pragma pack`. Esta
directiva le indica al compilador cómo debe alinear los miembros de una
estructura.

- `#pragma pack(push, 1)`: Esta línea guarda la configuración de alineación
  actual y establece una nueva alineación de **1 byte**. Esto le dice al
  compilador que no inserte ningún byte de relleno y empaquete los miembros de
  la estructura uno junto al otro, tal como lo requiere el formato de archivo.
- `#pragma pack(pop)`: Restaura la configuración de alineación que guardamos
  previamente. Es una buena práctica hacerlo para no afectar otras estructuras
  en el resto del programa.

## Paso 1: Las Estructuras de Cabecera

Ahora sí, definimos las estructuras para las cabeceras del BMP, envueltas en las
directivas `#pragma pack`.

:::{tip} Estilo

Acá utilizamos `typedef` para crear alias de nuestras
estructuras con el sufijo `_t`, siguiendo la regla {ref}`0x001Eh`. También
usamos tipos de ancho fijo como `uint16_t` de `<stdint.h>` para garantizar la
portabilidad y el tamaño exacto de los campos. 

:::

```{code}c
:linenos:

#include <stdint.h>

// Desactiva el padding para que la estructura coincida con el formato del archivo.
#pragma pack(push, 1)

/**
 * @brief Cabecera de archivo BMP (14 bytes).
 * Contiene información general sobre el archivo de mapa de bits.
 */
typedef struct {
    uint16_t tipo;              // 'BM' (0x4D42) para identificar el formato.
    uint32_t tamano_archivo;    // Tamaño total del archivo en bytes.
    uint16_t reservado1;        // No se usa, debe ser 0.
    uint16_t reservado2;        // No se usa, debe ser 0.
    uint32_t offset_datos;      // Distancia en bytes desde el inicio del archivo hasta los datos de píxeles.
} cabecera_archivo_bmp_t;

/**
 * @brief Cabecera de información del bitmap (DIB header, 40 bytes).
 * Contiene detalles sobre la imagen.
 */
typedef struct {
    uint32_t tamano_cabecera;   // Tamaño de esta cabecera (40 bytes).
    int32_t  ancho;             // Ancho de la imagen en píxeles.
    int32_t  alto;              // Alto de la imagen en píxeles.
    uint16_t planos;            // Número de planos de color (siempre 1).
    uint16_t bits_por_pixel;    // Profundidad de color (ej. 1, 8, 24).
    uint32_t compresion;        // Tipo de compresión (0 para sin compresión).
    uint32_t tamano_imagen;     // Tamaño de los datos de píxeles en bytes (incluyendo padding).
    int32_t  resolucion_x;      // Píxeles por metro en X (generalmente 0).
    int32_t  resolucion_y;      // Píxeles por metro en Y (generalmente 0).
    uint32_t colores_usados;    // Número de colores en la paleta (0 para 24-bit).
    uint32_t colores_importantes; // Número de colores importantes (0 = todos).
} cabecera_info_bmp_t;

// Restaura la configuración de padding original.
#pragma pack(pop)
```

## Ejemplo 1: Crear una imagen de 24 bits (True Color)

Una imagen de 24 bits es la más sencilla de crear, ya que no requiere una paleta
de colores. Cada píxel se representa por tres bytes: uno para el azul (Blue),
uno para el verde (Green) y uno para el rojo (Red), en ese orden (BGR).

### Datos de Píxeles en 24 bits

Los datos de los píxeles se escriben en el archivo de una manera muy específica:

1.  **Orden de Filas:** Se escriben desde la fila **inferior** de la imagen
    hasta la **superior**.
2.  **Orden de Píxeles:** Dentro de cada fila, los píxeles se escriben de
    izquierda a derecha.
3.  **Orden de Colores:** Cada píxel se almacena en formato **BGR** (Azul,
    Verde, Rojo), no en el más común RGB.
4.  **Relleno (Padding):** Cada fila de píxeles debe ocupar un número de bytes
    que sea múltiplo de 4. Si la cantidad de bytes de los píxeles de una fila
    (ancho \* 3) no es múltiplo de 4, se deben añadir bytes de relleno (con
    valor 0) al final de la fila hasta alcanzar el siguiente múltiplo de 4.

La fórmula para calcular el padding es: `(4 - (ancho_en_pixeles * 3) % 4) % 4`.

### Código de Ejemplo

La siguiente función crea una imagen BMP de 24 bits con un degradado de azul a
negro.

:::{tip} Estilo

Observá cómo las variables tienen nombres descriptivos (`ancho`,
`alto`, `tamano_fila`, etc.), como dicta la regla {ref}`0x0001h`. Además, la
función tiene un único punto de salida. Para lograrlo sin `goto`, utilizamos una
variable de estado (`exito`) y anidamos las operaciones en bloques `if`. Si un
paso falla, la variable `exito` se establece en `false` y los bloques
posteriores no se ejecutan, llevando el control directamente al bloque de
limpieza final. Este patrón cumple con la regla {ref}`0x0008h`.

:::

```{code}c
:linenos:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Incluir las definiciones de las estructuras de cabecera aquí...

/**
 * @brief Crea una imagen BMP de 24 bits con un degradado.
 *
 * @param nombre_archivo El nombre del archivo a crear.
 * @param ancho El ancho de la imagen en píxeles.
 * @param alto El alto de la imagen en píxeles.
 * @returns `true` si la imagen se creó con éxito, `false` en caso contrario.
 *
 * @pre nombre_archivo no debe ser NULL.
 * @post Se crea un archivo BMP en disco o se retorna `false`.
 */
bool crear_degradado_bmp_24bit(const char *nombre_archivo, int ancho, int alto) {
    FILE *archivo = NULL;
    uint8_t *fila_pixeles = NULL;
    bool exito = true;

    archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        perror("No se pudo crear el archivo BMP");
        exito = false;
    }

    if (exito) {
        // --- Cálculo de Tamaños y Padding ---
        int padding = (4 - (ancho * 3) % 4) % 4;
        int tamano_fila = (ancho * 3) + padding;
        uint32_t tamano_datos_pixeles = tamano_fila * alto;

        // --- Cabecera de Archivo ---
        cabecera_archivo_bmp_t cabecera_archivo = {
            .tipo = 0x4D42, // 'BM' en little-endian
            .tamano_archivo = sizeof(cabecera_archivo_bmp_t) + sizeof(cabecera_info_bmp_t) + tamano_datos_pixeles,
            .reservado1 = 0,
            .reservado2 = 0,
            .offset_datos = sizeof(cabecera_archivo_bmp_t) + sizeof(cabecera_info_bmp_t)
        };

        // --- Cabecera de Información (DIB) ---
        cabecera_info_bmp_t cabecera_info = {
            .tamano_cabecera = sizeof(cabecera_info_bmp_t),
            .ancho = ancho,
            .alto = alto,
            .planos = 1,
            .bits_por_pixel = 24,
            .compresion = 0, // BI_RGB (sin compresión)
            .tamano_imagen = tamano_datos_pixeles,
            .resolucion_x = 2835, // 72 DPI
            .resolucion_y = 2835, // 72 DPI
            .colores_usados = 0, // No usa paleta
            .colores_importantes = 0
        };

        // --- Escritura de Cabeceras ---
        if (fwrite(&cabecera_archivo, sizeof(cabecera_archivo_bmp_t), 1, archivo) != 1 ||
            fwrite(&cabecera_info, sizeof(cabecera_info_bmp_t), 1, archivo) != 1) {
            exito = false;
        }
    }

    if (exito) {
        // --- Escritura de Datos de Píxeles ---
        fila_pixeles = (uint8_t *)calloc(tamano_fila, 1);
        if (fila_pixeles == NULL) {
            exito = false;
        }
    }

    if (exito) {
        // Escribimos las filas desde abajo hacia arriba (y = 0 es la fila inferior).
        for (int y = 0; y < alto && exito; y++) {
            for (int x = 0; x < ancho; x++) {
                // Creamos un degradado azul que varía con la altura
                uint8_t azul = (uint8_t)((double)y / alto * 255.0);
                uint8_t verde = 0;
                uint8_t rojo = 0;

                // El formato es BGR
                fila_pixeles[x * 3 + 0] = azul;
                fila_pixeles[x * 3 + 1] = verde;
                fila_pixeles[x * 3 + 2] = rojo;
            }

            if (fwrite(fila_pixeles, 1, tamano_fila, archivo) != tamano_fila) {
                exito = false;
            }
        }
    }

    // --- Bloque de Limpieza Centralizado ---
    if (fila_pixeles != NULL) {
        free(fila_pixeles);
    }
    if (archivo != NULL) {
        fclose(archivo);
    }

    return exito;
}
```

## Ejemplo 2: Crear una imagen de 8 bits (Escala de Grises)

Las imágenes de 8 bits utilizan una **paleta de colores** para definir los hasta
256 colores que pueden usar. Los datos de los píxeles, en lugar de contener el
color BGR, contienen un índice (de 0 a 255) que apunta a una entrada en esta
paleta.

### La Paleta de Colores

La paleta se escribe en el archivo justo después de las cabeceras. Para una
imagen en escala de grises, crearemos una paleta donde cada entrada tiene el
mismo valor para R, G y B (ej. R=G=B=128 para un gris medio), creando así 256
tonos de gris.

```{code}c
:linenos:

/**
 * @brief Representa una entrada en la tabla de colores BMP (4 bytes).
 */
typedef struct {
    uint8_t azul;
    uint8_t verde;
    uint8_t rojo;
    uint8_t reservado; // Debe ser 0
} rgb_quad_t;
```

### Código de Ejemplo

Esta función crea una imagen en escala de grises de 8 bits con un degradado
horizontal.

```{code}c
:linenos:

// Incluir cabeceras y estructuras...

bool crear_degradado_bmp_8bit(const char *nombre_archivo, int ancho, int alto) {
    FILE *archivo = NULL;
    uint8_t *fila_indices = NULL;
    bool exito = true;

    archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        perror("No se pudo crear el archivo BMP");
        exito = false;
    }

    if (exito) {
        int padding = (4 - ancho % 4) % 4;
        int tamano_fila = ancho + padding;
        uint32_t tamano_datos_pixeles = tamano_fila * alto;
        uint32_t tamano_paleta = 256 * sizeof(rgb_quad_t);
        uint32_t offset_datos = sizeof(cabecera_archivo_bmp_t) + sizeof(cabecera_info_bmp_t) + tamano_paleta;

        cabecera_archivo_bmp_t cabecera_archivo = {
            .tipo = 0x4D42,
            .tamano_archivo = offset_datos + tamano_datos_pixeles,
            .reservado1 = 0,
            .reservado2 = 0,
            .offset_datos = offset_datos
        };

        cabecera_info_bmp_t cabecera_info = {
            .tamano_cabecera = sizeof(cabecera_info_bmp_t),
            .ancho = ancho,
            .alto = alto,
            .planos = 1,
            .bits_por_pixel = 8,
            .compresion = 0,
            .tamano_imagen = tamano_datos_pixeles,
            .resolucion_x = 2835,
            .resolucion_y = 2835,
            .colores_usados = 256, // Indicamos que usamos 256 colores
            .colores_importantes = 256 // O 0 para indicar que todos son importantes
        };

        // --- Escritura de Cabeceras y Paleta ---
        if (fwrite(&cabecera_archivo, 1, sizeof(cabecera_archivo_bmp_t), archivo) != sizeof(cabecera_archivo_bmp_t) ||
            fwrite(&cabecera_info, 1, sizeof(cabecera_info_bmp_t), archivo) != sizeof(cabecera_info_bmp_t)) {
            exito = false;
        } else {
            rgb_quad_t paleta[256];
            for (int i = 0; i < 256; i++) {
                paleta[i].rojo = (uint8_t)i;
                paleta[i].verde = (uint8_t)i;
                paleta[i].azul = (uint8_t)i;
                paleta[i].reservado = 0;
            }
            if (fwrite(paleta, sizeof(rgb_quad_t), 256, archivo) != 256) {
                exito = false;
            }
        }
    }

    if (exito) {
        fila_indices = (uint8_t *)calloc(tamano_fila, 1);
        if (fila_indices == NULL) {
            exito = false;
        }
    }

    if (exito) {
        for (int y = 0; y < alto && exito; y++) {
            for (int x = 0; x < ancho; x++) {
                // El valor del píxel es el índice en la paleta (degradado horizontal)
                uint8_t indice_gris = (uint8_t)((double)x / ancho * 255.0);
                fila_indices[x] = indice_gris;
            }
            if (fwrite(fila_indices, 1, tamano_fila, archivo) != tamano_fila) {
                exito = false;
            }
        }
    }

    // --- Limpieza ---
    if (fila_indices != NULL) {
        free(fila_indices);
    }
    if (archivo != NULL) {
        fclose(archivo);
    }

    return exito;
}
```

## Poniéndolo todo junto

Para compilar y ejecutar los ejemplos, podemos usar una función `main` como la
siguiente:

```{code}c
:linenos:

int main() {
    if (crear_degradado_bmp_24bit("degradado_24bit.bmp", 256, 256)) {
        printf("Imagen de 24 bits creada con éxito.\n");
    }

    if (crear_degradado_bmp_8bit("degradado_8bit.bmp", 256, 256)) {
        printf("Imagen de 8 bits creada con éxito.\n");
    }

    return 0;
}
```

## Conclusión

Crear archivos BMP en C es un excelente ejercicio para entender cómo se
estructuran los datos a bajo nivel y cómo interactuar con archivos binarios.
Aunque hemos cubierto los casos más comunes (24 y 8 bits sin compresión), el
formato BMP es más versátil y soporta otras profundidades de color y tipos de
compresión.

Al escribir código que maneja formatos de archivo, es vital prestar atención a
los detalles como el `padding`, el orden de los bytes (_endianness_) y seguir
las especificaciones del formato al pie de la letra. Afortunadamente, el formato
BMP utiliza el orden little-endian, el mismo que usan las arquitecturas x86 y
ARM modernas, por lo que generalmente no necesitamos preocuparnos por la
conversión del orden de bytes.
