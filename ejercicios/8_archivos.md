---
title: Ejercicios de archivos
short_title: 8. Archivos
---

Ejercicios para practicar la lectura y escritura de archivos en C.

## 1: Formato de Archivos

Para los siguientes ejercicios, se trabajará con archivos de texto que contienen
números enteros, uno por línea. El primer número del archivo indica la cantidad
total de números que le siguen.

**Ejemplo `numeros.txt`:**

```text
5
3
-5
3
6
3
```

En este ejemplo, el `5` inicial indica que hay 5 números a continuación.

## 2: Herramientas y Verificación

### 2.1: ¿Es correcto el formato?

Desarrollar una función `bool es_formato_correcto(const char *ruta)`.
**Lógica**: Abrir el archivo, leer el primer número (la cuenta esperada). Luego,
iterar con `fgets` o `fscanf` counting las líneas restantes. Finalmente,
comparar la cuenta real con la esperada.

### 2.2: ¿Está ordenado?

Implementar `int verificar_orden(const char *ruta)`. **Lógica**: Leer el
archivo, guardando el número anterior en cada iteración y comparándolo con el
actual para determinar si la secuencia es ascendente, descendente o desordenada.

## 3: Manipulación de Archivos

### 3.1: Ordenar archivo

Un programa que lea los números de un archivo a un arreglo, ordene el arreglo en
memoria y luego escriba el contenido ordenado a un nuevo archivo, respetando el
formato. **Ejemplo de uso:**
`./ordena_archivo entrada.txt salida_ordenada.txt asc`

### 3.2: Generador lineal

Implementar `generar_lineal(ruta, cantidad, inicio, paso)`. **Ejemplo**:
`generar_lineal("lineal.txt", 5, 10, 2)` debe crear un archivo con:

```text
5
10
12
14
16
18
```

### 3.3: Generador aleatorio

Implementar `generar_aleatorio(ruta, cantidad, min, max)`. **Lógica**: Usar
`srand(time(NULL))` una vez al inicio del programa, y luego
`rand() % (max - min + 1) + min` para generar cada número.

## 4: Ejercicios Adicionales de Archivos

### 4.1: Contar Líneas, Palabras y Caracteres

Implementar una versión simple del comando `wc` de Unix. El programa debe recibir una ruta de archivo y reportar el número total de líneas, palabras y caracteres que contiene.

### 4.2: Copiar Archivo

Crear un programa que copie el contenido de un archivo de origen a un archivo de destino. El programa debe recibir ambas rutas como argumentos. Se puede hacer leyendo y escribiendo línea por línea o en bloques de bytes.

### 4.3: Buscar y Reemplazar en Archivo

Escribir un programa que busque todas las ocurrencias de una cadena en un archivo y las reemplace por otra, guardando el resultado en un nuevo archivo de salida.

### 4.4: Comparar Archivos

Implementar un programa que compare dos archivos de texto e indique si son idénticos o no. Opcionalmente, puede reportar la primera línea y número de columna donde difieren.

### 4.5: Fusionar Archivos

Crear un programa que reciba dos rutas de archivo y fusione su contenido en un tercer archivo. El contenido del segundo archivo debe aparecer después del contenido del primero.

### 4.6: Dividir Archivo Grande

Escribir un programa que divida un archivo de texto grande en varios archivos más pequeños, cada uno con un número máximo de `N` líneas. Los nombres de los archivos de salida pueden ser `parte_1.txt`, `parte_2.txt`, etc.

### 4.7: Archivos CSV - Promedio de Columna

Leer un archivo en formato CSV (valores separados por comas) que contiene datos de estudiantes (ej. `nombre,nota1,nota2`). Calcular el promedio de una columna numérica específica (ej. la segunda columna de notas) e imprimir el resultado.

### 4.8: Archivos Binarios - Guardar y Leer Structs

Definir una `struct` (ej. `producto_t`). Crear un arreglo de estas `structs`, escribirlo en un archivo binario usando `fwrite`, y luego leerlo de vuelta a un nuevo arreglo usando `fread`, verificando que los datos sean correctos.

### 4.9: Log de Eventos

Implementar una función `void log_evento(const char* mensaje)` que abra un archivo de log en modo "append" (añadir al final), escriba la fecha y hora actual seguida del mensaje, y luego cierre el archivo.

### 4.10: Numerar Líneas de un Archivo

Leer un archivo de texto y escribir su contenido en un nuevo archivo, pero con cada línea precedida por su número de línea y un tabulador. (ej. `1\tPrimera línea...`).

### 4.11: Eliminar Comentarios de Código C

Leer un archivo de código fuente `.c` y generar una versión sin comentarios. El programa debe ser capaz de manejar tanto comentarios de una línea (`// ...`) como de múltiples líneas (`/* ... */`).

### 4.12: Archivo de Configuración (.ini)

Escribir funciones para leer y buscar valores en un archivo de configuración simple con formato `clave=valor`. La función `char* obtener_valor(const char* ruta, const char* clave)` debe devolver el valor asociado a una clave o `NULL` si no se encuentra.

### 4.13: Tail de un Archivo

Implementar una versión simple del comando `tail`. El programa debe recibir un número `N` y una ruta de archivo, y mostrar las últimas `N` líneas de ese archivo.

### 4.14: Verificar Existencia de Archivo

Escribir una función `bool archivo_existe(const char* ruta)` que verifique si un archivo existe en la ruta especificada sin intentar abrirlo para lectura. Se puede usar la función `stat` de `<sys/stat.h>`.

### 4.15: Fusión Ordenada de Archivos

Dados dos archivos de texto que contienen números enteros ordenados de forma ascendente (uno por línea), fusionarlos en un tercer archivo que también quede ordenado. El algoritmo no debe cargar todos los números a memoria a la vez.

## 5: Más Ejercicios de Archivos

### 5.1: Head de un Archivo

Implementar una versión simple del comando `head`. El programa debe recibir un número `N` y una ruta de archivo, y mostrar las primeras `N` líneas de ese archivo.

### 5.2: Grep Simple

Crear una versión simplificada de `grep`. El programa debe recibir una cadena (patrón) y una ruta de archivo, y debe imprimir todas las líneas del archivo que contengan esa cadena.

### 5.3: Encriptación XOR de Archivo

Escribir un programa que encripte/desencripte un archivo aplicando una operación XOR byte a byte con una clave de un solo carácter. Al aplicar la misma operación dos veces, se recupera el archivo original.

### 5.4: Checksum de Archivo

Implementar un programa que calcule un checksum simple para un archivo. Una forma de hacerlo es sumar el valor de cada byte del archivo y obtener el resultado módulo 2^16.

### 5.5: Acceso Aleatorio a Registros

Dado un archivo binario que contiene una secuencia de `structs` de tamaño fijo, implementar una función que lea el registro número `n` del archivo usando `fseek` para posicionar el puntero del archivo directamente, sin leer los registros anteriores.

### 5.6: Obtener Tamaño de Archivo

Escribir una función que devuelva el tamaño de un archivo en bytes. La implementación debe usar `fseek` para ir al final del archivo y `ftell` para obtener la posición, que corresponde al tamaño.

### 5.7: Invertir Contenido de Archivo

Crear un programa que genere un nuevo archivo cuyo contenido sea el del archivo original pero en orden inverso, byte por byte. Esto requiere leer el archivo original desde el final hacia el principio.

### 5.8: Analizador de Logs

Leer un archivo de log donde cada línea tiene un formato como `[NIVEL]: Mensaje` (ej. `[ERROR]: Fallo la conexión`). El programa debe contar cuántas entradas hay de cada nivel (ERROR, WARNING, INFO) y mostrar un resumen.

### 5.9: Crear Archivo BMP Simple

Investigar el formato de archivo BMP y escribir un programa que genere un archivo `.bmp` válido y muy simple, como una imagen de 10x10 píxeles de un solo color. Esto implica escribir cuidadosamente los bytes del encabezado del archivo y luego los datos de los píxeles.

### 5.10: Diff Simple de Archivos

Implementar una versión simplificada de `diff`. El programa debe comparar dos archivos de texto línea por línea y mostrar las líneas que son diferentes, indicando de qué archivo provienen.
