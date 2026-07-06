---
title: "Ejercicios: Archivos Binarios"
short_title: "5. Archivos Binarios"
---

# Ejercicios de Archivos Binarios

## Acerca de

Estos ejercicios tienen como propósito familiarizarse con la manipulación y persistencia de estructuras complejas de datos en almacenamiento mediante flujos binarios crudos empleando las funciones de la biblioteca estándar de C.

### Capítulos de Apunte Correspondientes
- {ref}capitulo-estructuras
- {ref}capitulo-archivos-texto

### Cuestiones de Estilo Aplicables
- **Chequeo de lectura/escritura:** Al invocar `fread` y `fwrite`, es mandatorio validar que la cantidad de elementos leídos o escritos coincida exactamente con el parámetro solicitado antes de asumir el éxito de la operación.
- **Acceso seguro mediante offsets:** Al realizar accesos aleatorios con `fseek`, calculá los offsets multiplicando el índice de registro por el tamaño estático del struct (`sizeof`), previniendo desalineaciones físicas del puntero del archivo.

---

## Escritura de Registros

Para los siguientes ejercicios, utilizaremos la `struct` `producto_t`:

```c
typedef struct {
    char sku[12];
    char nombre[30];
    int stock;
    float precio;
} producto_t;
```

### Ejercicio 5.8 - Guardar Inventario

Escribir una función que reciba un arreglo de `producto_t` y su tamaño, y guarde todos los productos en un archivo binario llamado `inventario.dat`.

**Lógica y Consideraciones:**
- **Apertura**: El archivo debe abrirse en modo escritura binaria (`"wb"`).
- **Escritura**: Utilizar una única llamada a `fwrite` para escribir el arreglo completo. La sintaxis sería `fwrite(productos, sizeof(producto_t), cantidad, archivo);`.
- **Verificación**: Es crucial verificar que el valor devuelto por `fwrite` sea igual a la `cantidad` de productos que se intentaron escribir.

---

## Lectura de Registros

### Ejercicio 5.9 - Cargar Inventario

Escribir una función que lea todos los registros de `inventario.dat` y los muestre por pantalla.

**Lógica y Consideraciones:**
- **Apertura**: Abrir el archivo en modo lectura binaria (`"rb"`).
- **Lectura**: Usar un lazo `while` que intente leer un registro a la vez con `fread`. El lazo continuará mientras `fread` devuelva 1 (indicando que un registro fue leído exitosamente).
- **Búfer**: Se necesita una única variable de tipo `producto_t` que actúe como búfer para recibir los datos de cada registro leído.
- **Manejo de EOF**: Al final del lazo, verificar `feof` y `ferror` para asegurarse de que la lectura terminó porque se llegó al final del archivo y no por un error.

---

## Acceso Aleatorio

### Ejercicio 5.10 - Leer Registro Específico

Implementar una función `producto_t leer_registro(int n)` que lea y devuelva el `n`-ésimo registro del archivo `inventario.dat` sin leer los registros anteriores.

**Lógica y Consideraciones:**
- **Posicionamiento**: Utilizar `fseek` para mover el puntero del archivo directamente a la posición deseada. La posición se calcula como `n * sizeof(producto_t)`.
- **Origen**: El desplazamiento debe hacerse desde el inicio del archivo (`SEEK_SET`).
- **Lectura**: Una vez posicionado, usar `fread` para leer un solo registro.

### Ejercicio 5.11 - Actualizar Registro

Implementar una función `void actualizar_stock(int n, int nuevo_stock)` que modifique únicamente el stock del `n`-ésimo registro en el archivo.

**Lógica y Consideraciones:**
- **Apertura**: El archivo debe abrirse en un modo que permita tanto lectura como escritura, sin borrar el contenido: `"rb+"`.
- **Proceso**: 
  1. Usar `fseek` para posicionarse al inicio del registro `n`.
  2. Usar `fread` para leer el registro actual en una variable `producto_t`.
  3. Modificar el campo `stock` en la variable.
  4. **Crucial**: Usar `fseek` de nuevo para volver a la misma posición (porque la lectura movió el puntero).
  5. Usar `fwrite` para sobrescribir el registro en el archivo con la estructura ya modificada.