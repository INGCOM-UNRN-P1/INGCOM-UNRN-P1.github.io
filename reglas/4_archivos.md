---
title: Gestión de Archivos y Errores
short_title: Archivos y Errores
subtitle: Reglas de estilo para el manejo de archivos y diagnóstico de errores en C
---

(0x40XXh)=
# Gestión de Archivos y Errores (`0x40XX`)

(0x4001h)=
## Regla `0x4001h`: Manejá correctamente la apertura y cierre de archivos

Siempre validá que el puntero devuelto por `fopen` no sea `NULL` antes de operar sobre él, y cerrá el recurso mediante `fclose`.

```c
FILE *archivo = fopen("datos.txt", "r");
if (archivo == NULL)
{
    perror("Error al abrir archivo");
    return ERROR_ARCHIVO;
}
// ...
fclose(archivo);
```

(0x4002h)=
## Regla `0x4002h`: Validá los retornos de las operaciones de lectura y escritura de archivos

Funciones como `fread`, `fwrite`, `fgetc`, `fgets`, `fprintf` y `fscanf` devuelven valores de control. Es obligatorio verificar dichos retornos para asegurar transferencias completas e identificar fallos o el fin de archivo (EOF).

- **Incorrecto (escritura ciega):**
  ```c
  FILE *archivo = fopen("salida.bin", "wb");
  int datos[3] = {10, 20, 30};
  fwrite(datos, sizeof(int), 3, archivo); // Si falla el disco, no nos enteramos
  fclose(archivo);
  ```
- **Correcto (validando elementos escritos):**
  ```c
  FILE *archivo = fopen("salida.bin", "wb");
  if (archivo != NULL)
  {
      int datos[3] = {10, 20, 30};
      size_t escritos = fwrite(datos, sizeof(int), 3, archivo);
      if (escritos < 3)
      {
          fprintf(stderr, "Error: Escritura incompleta en disco.\n");
      }
      fclose(archivo);
  }
  ```

(0x4003h)=
## Regla `0x4003h`: Utilizá `errno`, `perror` y `strerror` para reportar fallos del sistema operativo de manera precisa

Cualquier fallo en llamadas de sistema de archivos (como fallos en `fopen`, `fread` o `fwrite`) establece un código de error global en la variable `errno` de `<errno.h>`. Debés usar `perror` o `strerror` de `<string.h>` para imprimir o formatear mensajes legibles de diagnóstico.

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *archivo = fopen("config.cfg", "r");
if (archivo == NULL)
{
    // perror imprime automáticamente el mensaje asociado al errno actual
    perror("Fallo al cargar config.cfg");
    
    // O podés usar strerror para obtener la cadena correspondiente
    fprintf(stderr, "Detalle técnico: %s (código %d)\n", strerror(errno), errno);
}
```

(0x4004h)=
## Regla `0x4004h`: Asegurá la simetría de recursos al abrir y cerrar archivos en el mismo nivel de abstracción

La función que abre un archivo debe ser la misma responsable de cerrarlo, o bien se debe delegar formalmente su propiedad a una estructura/módulo administrador simétrico. Esto evita descriptores de archivo huérfanos que agoten el límite del sistema operativo.

- **Incorrecto (el llamador abre, pero el archivo queda abierto si no recuerda cerrarlo):**
  ```c
  void leer_datos(FILE *f) {
      // Procesa...
  }
  ```
- **Correcto (encapsulación clara y simetría):**
  ```c
  void procesar_archivo(const char *ruta) {
      FILE *f = fopen(ruta, "r");
      if (f != NULL) {
          leer_datos(f);
          fclose(f);
      }
  }
  ```

(0x4005h)=
## Regla `0x4005h`: Evitá el uso de offsets y posiciones fijas codificadas a mano en archivos binarios sin validar sus dimensiones

Cuando leés o escribís en una posición específica de un archivo binario mediante `fseek`, debés validar que la posición de destino sea válida y no exceda las dimensiones físicas del archivo. Calculá el tamaño del archivo usando `fseek` y `ftell` antes de realizar saltos aleatorios.

```c
FILE *archivo = fopen("datos.bin", "rb");
if (archivo != NULL)
{
    // Obtener tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    rewind(archivo);

    long offset = 100 * sizeof(registro_t);
    if (offset < tamano)
    {
        fseek(archivo, offset, SEEK_SET);
        // Operación de lectura segura
    }
    fclose(archivo);
}
```

