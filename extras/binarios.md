---
title: Archivos binarios
short_title: Archivos binarios
numbering:
  code: true
---

# Trabajo con Archivos Binarios en C: Una Mirada Profunda

Mientras que los archivos de texto son legibles por humanos y excelentes para
configuraciones o logs, los **archivos binarios** representan el siguiente nivel
en persistencia de datos. Almacenan información en su representación cruda, byte
por byte, tal como reside en la memoria. Este enfoque es indispensable cuando la
eficiencia, la precisión y la estructura de los datos son primordiales.

## ¿Por Qué y Cuándo Usar Archivos Binarios?

La elección entre un archivo de texto y uno binario es una decisión de diseño
fundamental. Optás por el formato binario por las siguientes razones de peso:

1.  **Eficiencia de Espacio y Velocidad**: Esta es la ventaja más significativa.
    Un archivo de texto es inherentemente "verboso". Para guardar el número
    entero `16843009`, un archivo de texto necesita 8 bytes, uno para el
    carácter '1', otro para el '6', y así sucesivamente. En cambio, un archivo
    binario guarda directamente la representación en memoria de ese número. Un
    `int` de 32 bits (4 bytes) se almacena, sin importar su valor, en
    exactamente 4 bytes. Para millones de registros, esto se traduce en un
    ahorro masivo de espacio y en operaciones de E/S mucho más rápidas, ya que
    se transfiere menos información.

2.  **Precisión Numérica Absoluta**: Los números de punto flotante (`float`,
    `double`) son susceptibles a errores de redondeo cuando se convierten a
    texto. Por ejemplo, `0.1` no tiene una representación finita en binario,
    similar a como 1/3 no la tiene en decimal (0.333...). Guardar `0.1` en un
    archivo de texto podría almacenar "0.10000000149011612". Al leerlo de
    vuelta, introducís una imprecisión. El almacenamiento binario evita este
    problema por completo, guardando una copia exacta de los bytes que
    representan a ese `double` en memoria.

3.  **Preservación de Estructuras Complejas**: Esta es la capacidad que define a
    los archivos binarios para el manejo de datos de aplicación. Podés tomar una
    estructura (`struct`), un array de ellas, o cualquier bloque de memoria
    contiguo y volcarlo directamente al disco con una sola operación. Al leerlo,
    el proceso inverso reconstruye la estructura en memoria instantáneamente. Es
    la forma más directa de guardar el "estado" de una parte de tu programa.

La contrapartida es evidente: los archivos binarios no son legibles por humanos.
Abrir un archivo `.dat` en un editor de texto mostrará una secuencia
ininteligible de caracteres, ya que el editor intenta interpretar cada byte como
un carácter ASCII o UTF-8.

## Apertura en Modo Binario: La "b" es la Clave

Para indicarle a la librería estándar que vas a operar con datos crudos, sin
interpretaciones de caracteres de fin de línea u otras conversiones de texto,
añadís una `b` al modo de apertura en `fopen()`.

```{list-table} Modos de Apertura Binaria
:header-rows: 1
:label: table-binary-modes

* - Modo
  - Descripción y Caso de Uso
* - `"rb"`
  - **Read Binary**: Abre para lectura. Es el modo más seguro si solo necesitás consumir datos. Falla si el archivo no existe.
* - `"wb"`
  - **Write Binary**: Abre para escritura. Si el archivo existe, **su contenido se borra sin previo aviso**. Ideal para crear archivos desde cero o para sobrescribir completamente un archivo de resultados.
* - `"ab"`
  - **Append Binary**: Abre para añadir datos al final. Perfecto para archivos de log o para agregar nuevos registros a un archivo existente sin tocar los datos previos.
* - `"rb+"`
  - Abre para lectura y escritura. El archivo debe existir. Te permite leer un registro, modificarlo en memoria y luego sobrescribirlo en la misma posición.
* - `"wb+"`
  - Crea un archivo para lectura y escritura. Borra el contenido si ya existía. Útil para archivos temporales que necesitás escribir y leer repetidamente.
* - `"ab+"`
  - Abre para lectura y para añadir datos al final. Te permite leer cualquier parte del archivo, pero cualquier operación de escritura ocurrirá siempre al final.
```

La gestión de errores con `perror` y `errno` es idéntica a la de los archivos de
texto y es una práctica no negociable.

## `fread` y `fwrite`: El Corazón de la E/S Binaria

Estas son las dos funciones que realizarán todo el trabajo pesado. A diferencia
de `fprintf`, no les importa el _contenido_ de los datos; solo ven secuencias de
bytes. Su trabajo es simple: transferir un bloque de memoria de un origen a un
destino.

### Anatomía Detallada de sus Parámetros

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

- `void *ptr`: Este es el **puntero al inicio del bloque de memoria** que
  contiene los datos (para `fwrite`) o donde se almacenarán los datos leídos
  (para `fread`). El tipo `void *` (puntero genérico) significa que la función
  puede aceptar un puntero a cualquier tipo de dato: la dirección de un `int`,
  de un `struct`, o de un array. Sos vos quien garantiza que ese puntero es
  válido y apunta a una zona de memoria lo suficientemente grande.
- `size_t size`: Es el **tamaño en bytes de un único elemento** que querés
  transferir. La práctica universal es usar el operador `sizeof()`. Por ejemplo,
  `sizeof(int)`, `sizeof(Producto)`. `size_t` es un tipo entero sin signo,
  adecuado para representar tamaños de objetos.
- `size_t nmemb`: Es el **número de elementos** (cada uno de tamaño `size`) que
  querés transferir. La cantidad total de bytes que se intentará mover es
  `size * nmemb`.
- `FILE *stream`: El identificador del archivo.

### Interpretando el Valor de Retorno: La Clave del Control

Ambas funciones devuelven un `size_t` que representa el **número de elementos
(`nmemb`) leídos o escritos completamente con éxito**. Esta es una distinción
sutil pero crucial. No devuelven el número de bytes.

- **Escenario ideal**: Si pediste escribir 10 `structs` (`nmemb = 10`), `fwrite`
  debería devolver 10. Si pediste leer 5, `fread` debería devolver 5.
- **Escenario de fallo**: Si el valor devuelto es **menor** que `nmemb`, algo
  interrumpió la operación.
  - Para `fwrite`: Un retorno menor a `nmemb` es un error inequívoco. La causa
    más común es que se llenó el disco.
  - Para `fread`: Un retorno menor a `nmemb` es ambiguo. Pudo haber ocurrido un
    **error de lectura** (un fallo en el disco duro) o, más comúnmente, se
    **alcanzó el final del archivo (EOF)** antes de poder leer todos los
    elementos que solicitaste (lo que se conoce como "lectura corta" o "short
    read").

Para resolver esta ambigüedad en `fread`, inmediatamente después de detectar una
lectura corta, debés usar `feof(stream)` y `ferror(stream)`.

## Escribiendo Datos Binarios (`fwrite`)

Guardar una estructura o un array de ellas es el caso de uso por excelencia.

```{code-block} c
:caption: Escribiendo un array de structs con fwrite
:label: fwrite-example

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sku[20];
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

int main(void) {
    FILE *archivo_salida = fopen("inventario.dat", "wb");
    if (!archivo_salida) {
        perror("No se pudo crear inventario.dat");
        return EXIT_FAILURE;
    }

    Producto productos[3] = {
        {"SKU001", "Teclado Mecanico", 50, 15000.50f},
        {"SKU002", "Mouse Gamer", 120, 8500.75f},
        {"SKU003", "Monitor 24 pulgadas", 30, 89999.00f}
    };

    size_t num_productos = sizeof(productos) / sizeof(Producto);

    // Escribimos el array completo de una sola vez.
    // fwrite toma la dirección del primer elemento, 'productos',
    // y copia sizeof(Producto) * num_productos bytes desde esa
    // dirección directamente al archivo.
    size_t elementos_escritos = fwrite(productos, sizeof(Producto), num_productos, archivo_salida);

    if (elementos_escritos < num_productos) {
        perror("Error de escritura: no se guardaron todos los registros");
        fclose(archivo_salida);
        return EXIT_FAILURE;
    }

    printf("Se escribieron %zu productos en 'inventario.dat'.\n", elementos_escritos);

    // El cierre es crucial para asegurar que el búfer final se escriba en el disco.
    fclose(archivo_salida);
    return EXIT_SUCCESS;
}
```

## Leyendo Datos Binarios (`fread`)

La lectura es el espejo de la escritura. Es fundamental que la definición del
`struct` que uses para leer sea **exactamente idéntica** a la que usaste para
escribir.

```{code-block} c
:caption: Lectura secuencial y robusta con fread
:label: fread-example

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sku[20];
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

void imprimir_producto(const Producto *p) {
    printf("SKU: %s\nNombre: %s\nCantidad: %d\nPrecio: %.2f\n\n",
           p->sku, p->nombre, p->cantidad, p->precio);
}

int main(void) {
    FILE *archivo_entrada = fopen("inventario.dat", "rb");
    if (!archivo_entrada) {
        perror("No se pudo abrir inventario.dat");
        return EXIT_FAILURE;
    }

    Producto un_producto; // Buffer en memoria para alojar un producto a la vez

    printf("--- Contenido del Inventario ---\n");
    // El bucle intenta leer un producto (nmemb=1) en cada iteración.
    // Continúa mientras fread devuelva 1, indicando una lectura exitosa.
    while (fread(&un_producto, sizeof(Producto), 1, archivo_entrada) == 1) {
        imprimir_producto(&un_producto);
    }

    // Al salir del bucle, fread devolvió 0. Debemos averiguar por qué.
    if (ferror(archivo_entrada)) {
        perror("Ocurrió un error de E/S durante la lectura");
    } else if (feof(archivo_entrada)) {
        // Esta es la condición de salida normal y esperada.
        printf("--- Fin del archivo alcanzado con éxito ---\n");
    }

    fclose(archivo_entrada);
    return EXIT_SUCCESS;
}
```

## Posicionamiento: El Poder de `fseek` en Modo Binario

En archivos binarios, `fseek` brilla. Como cada registro tiene un tamaño fijo y
conocido, y no hay caracteres "especiales", la aritmética de punteros es directa
y fiable. Podés saltar a cualquier registro con un simple cálculo.

`fseek(archivo, N * sizeof(Registro), SEEK_SET);` te posicionará exactamente al
inicio del registro `N+1`.

```{code-block} c
:caption: Acceso aleatorio para modificar un registro
:label: fseek-binary-update

// ... (incluir headers y struct Producto como antes) ...

int main(void) {
    // Abrimos en modo "rb+" para leer y escribir sobre el mismo archivo.
    FILE *archivo = fopen("inventario.dat", "rb+");
    if (!archivo) {
        perror("No se pudo abrir inventario.dat en modo actualización");
        return EXIT_FAILURE;
    }

    int n_registro_a_modificar = 1; // Vamos a modificar el segundo producto (Mouse)

    // 1. Nos posicionamos al inicio del registro que queremos modificar.
    long offset = n_registro_a_modificar * sizeof(Producto);
    if (fseek(archivo, offset, SEEK_SET) != 0) {
        perror("Error al posicionar el puntero con fseek");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    // 2. Leemos el registro actual en esa posición para tener sus datos.
    Producto producto_a_modificar;
    if (fread(&producto_a_modificar, sizeof(Producto), 1, archivo) != 1) {
        fprintf(stderr, "No se pudo leer el registro a modificar.\n");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    printf("Producto a modificar:\n");
    imprimir_producto(&producto_a_modificar);

    // 3. Modificamos los datos en nuestra variable en memoria.
    producto_a_modificar.cantidad = 95; // Actualizamos el stock
    producto_a_modificar.precio = 9100.00f; // Cambió el precio

    // 4. VOLVEMOS a posicionar el puntero, porque la lectura anterior lo movió.
    if (fseek(archivo, offset, SEEK_SET) != 0) {
        perror("Error al reposicionar el puntero para escribir");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    // 5. Sobrescribimos el registro en el archivo con los nuevos datos.
    if (fwrite(&producto_a_modificar, sizeof(Producto), 1, archivo) != 1) {
        perror("Error al sobrescribir el registro modificado");
    } else {
        printf("\nRegistro actualizado con éxito.\n");
    }

    fclose(archivo);
    return EXIT_SUCCESS;
}
```

:::{warning} Cuestiones Críticas de Portabilidad

Un archivo binario generado en una máquina puede no ser legible en otra. Esto se
debe a dos problemas principales:

1.  **Endianness (Orden de Bytes)**: Las arquitecturas de CPU pueden ser
    _little-endian_ (como Intel x86, donde el byte menos significativo se
    almacena primero) o _big-endian_ (como algunas arquitecturas de red o
    PowerPC, donde el byte más significativo va primero). Un `int` con valor 258
    (0x0102) se guardaría como `02 01` en little-endian y `01 02` en big-endian.
2.  **Padding (Relleno) de Estructuras**: Para optimizar el acceso a memoria, el
    compilador puede insertar bytes de relleno invisibles entre los miembros de
    un `struct` para que cada miembro comience en una dirección de memoria
    alineada. La forma en que se realiza este relleno puede variar entre
    compiladores y arquitecturas.

Para crear archivos binarios verdaderamente portables, debés definir un formato
de archivo estricto, leer y escribir cada campo individualmente y convertir los
tipos multibyte a un formato estándar, como el orden de bytes de red
(`network byte order`), usando funciones como `htonl()` y `ntohl()`.

:::
