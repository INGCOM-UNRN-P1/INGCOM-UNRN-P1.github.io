---
title: "Ejercicios: Archivos Binarios"
short_title: "15. Archivos Binarios"
---

## Acerca de

Estos ejercicios se centran en la manipulación de archivos binarios, una técnica esencial para la persistencia de datos de forma eficiente y precisa. A diferencia de los archivos de texto, los archivos binarios guardan los datos en su representación de memoria cruda, lo que es ideal para `structs` y arreglos numéricos. Las funciones clave para estos ejercicios son `fwrite` y `fread`.

Para los siguientes ejercicios, utilizaremos la `struct` `producto_t`:

```c
typedef struct {
    char sku[12];
    char nombre[30];
    int stock;
    float precio;
} producto_t;
```

## 1: Escritura de Registros

### 1.1: Guardar Inventario

#### Descripción
Escribir una función que reciba un arreglo de `producto_t` y su tamaño, y guarde todos los productos en un archivo binario llamado `inventario.dat`.

:::{hint} Lógica y Consideraciones
- **Apertura**: El archivo debe abrirse en modo escritura binaria (`"wb"`).
- **Escritura**: Utilizar una única llamada a `fwrite` para escribir el arreglo completo. La sintaxis sería `fwrite(productos, sizeof(producto_t), cantidad, archivo);`.
- **Verificación**: Es crucial verificar que el valor devuelto por `fwrite` sea igual a la `cantidad` de productos que se intentaron escribir.
:::

## 2: Lectura de Registros

### 2.1: Cargar Inventario

#### Descripción
Escribir una función que lea todos los registros de `inventario.dat` y los muestre por pantalla.

:::{hint} Lógica y Consideraciones
- **Apertura**: Abrir el archivo en modo lectura binaria (`"rb"`).
- **Lectura**: Usar un bucle `while` que intente leer un registro a la vez con `fread`. El bucle continuará mientras `fread` devuelva 1 (indicando que un registro fue leído exitosamente).
- **Búfer**: Se necesita una única variable de tipo `producto_t` que actúe como búfer para recibir los datos de cada registro leído.
- **Manejo de EOF**: Al final del bucle, verificar `feof` y `ferror` para asegurarse de que la lectura terminó porque se llegó al final del archivo y no por un error.
:::

## 3: Acceso Aleatorio

### 3.1: Leer Registro Específico

#### Descripción
Implementar una función `producto_t leer_registro(int n)` que lea y devuelva el `n`-ésimo registro del archivo `inventario.dat` sin leer los registros anteriores.

:::{hint} Lógica y Consideraciones
- **Posicionamiento**: Utilizar `fseek` para mover el puntero del archivo directamente a la posición deseada. La posición se calcula como `n * sizeof(producto_t)`.
- **Origen**: El desplazamiento debe hacerse desde el inicio del archivo (`SEEK_SET`).
- **Lectura**: Una vez posicionado, usar `fread` para leer un solo registro.
:::

### 3.2: Actualizar Registro

#### Descripción
Implementar una función `void actualizar_stock(int n, int nuevo_stock)` que modifique únicamente el stock del `n`-ésimo registro en el archivo.

:::{hint} Lógica y Consideraciones
- **Apertura**: El archivo debe abrirse en un modo que permita tanto lectura como escritura, sin borrar el contenido: `"rb+"`.
- **Proceso**: 
  1. Usar `fseek` para posicionarse al inicio del registro `n`.
  2. Usar `fread` para leer el registro actual en una variable `producto_t`.
  3. Modificar el campo `stock` en la variable.
  4. **Crucial**: Usar `fseek` de nuevo para volver a la misma posición (porque la lectura movió el puntero).
  5. Usar `fwrite` para sobrescribir el registro en el archivo con la estructura ya modificada.
:::