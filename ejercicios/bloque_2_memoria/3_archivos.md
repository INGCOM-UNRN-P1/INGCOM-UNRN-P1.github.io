---
title: Ejercicios de Archivos
short_title: 3. Archivos
---

# Ejercicios de Archivos

## Acerca de

Estos ejercicios tienen como fin practicar la interacción de los programas con
dispositivos de almacenamiento mediante streams y archivos de texto formateados
en C.

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-archivos-texto`

### Cuestiones de Estilo Aplicables
- **Cierre de archivos:** Es obligatorio verificar la apertura correcta del
  puntero `FILE *` contra `NULL` y cerrar siempre el archivo con `fclose` para
  evitar leaks de descriptores (ver {ref}`0x3002h`).
- **Control de errores en lectura:** Utilizá la validación del retorno de
  funciones como `fscanf` o `fgets` para controlar de forma segura el fin del
  archivo y evitar la lectura duplicada del último elemento.

---

## Herramientas y Verificación

Para los siguientes ejercicios, se trabajará con archivos de texto que contienen
números enteros, uno por línea. El primer número del archivo indica la cantidad
total de números que le siguen.

**Ejemplo `numeros.txt`:**
```{code-block} text
:linenos:
5
3
-5
3
6
3

```
<!-- {code-block} text -->
En este ejemplo, el `5` inicial indica que hay 5 números a continuación.
(ejercicio_12_1)=
### Ejercicio 12.1 - ¿Es correcto el formato? ⭐⭐☆☆☆

Desarrollar una función `bool es_formato_correcto(const char *ruta)`.

**Lógica**: Abrir el archivo, leer el primer número (la cuenta esperada). Luego,
iterar con `fgets` o `fscanf` contando las líneas restantes. Finalmente,
comparar la cuenta real con la esperada.
(ejercicio_12_2)=
### Ejercicio 12.2 - ¿Está ordenado? ⭐⭐☆☆☆

Implementar `int verificar_orden(const char *ruta)`.

**Lógica**: Leer el archivo, guardando el número anterior en cada iteración y
comparándolo con el actual para determinar si la secuencia es ascendente,
descendente o desordenada.

---

## Manipulación de Archivos
(ejercicio_12_3)=
### Ejercicio 12.3 - Ordenar archivo ⭐⭐☆☆☆

Un programa que lea los números de un archivo a un arreglo, ordene el arreglo en
memoria y luego escriba el contenido ordenado a un nuevo archivo, respetando el
formato.

**Ejemplo de uso:**
`./ordena_archivo entrada.txt salida_ordenada.txt asc`
(ejercicio_12_4)=
### Ejercicio 12.4 - Generador lineal ⭐⭐☆☆☆

Implementar `generar_lineal(ruta, cantidad, inicio, paso)`.

**Ejemplo**: `generar_lineal("lineal.txt", 5, 10, 2)` debe crear un archivo con:
```{code-block} text
:linenos:
5
10
12
14
16
18

```
<!-- {code-block} text -->
(ejercicio_12_5)=
### Ejercicio 12.5 - Generador aleatorio ⭐⭐☆☆☆

Implementar `generar_aleatorio(ruta, cantidad, min, max)`.

**Lógica**: Usar `srand(time(NULL))` una vez al inicio del programa, y luego
`rand() % (max - min + 1) + min` para generar cada número.

---

## Operaciones Avanzadas
(ejercicio_12_6)=
### Ejercicio 12.6 - Contar Líneas, Palabras y Caracteres ⭐⭐☆☆☆

Implementar una versión simple del comando `wc` de Unix. El programa debe
recibir una ruta de archivo y reportar el número total de líneas, palabras y
caracteres que contiene.
(ejercicio_12_7)=
### Ejercicio 12.7 - Copiar Archivo ⭐⭐☆☆☆

Crear un programa que copie el contenido de un archivo de origen a un archivo de
destino. El programa debe recibir ambas rutas como argumentos. Se puede hacer
leyendo y escribiendo línea por línea o en bloques de bytes.
(ejercicio_12_8)=
### Ejercicio 12.8 - Buscar y Reemplazar en Archivo ⭐⭐☆☆☆

Escribir un programa que busque todas las ocurrencias de una cadena en un
archivo y las reemplace por otra, guardando el resultado en un nuevo archivo de
salida.
(ejercicio_12_9)=
### Ejercicio 12.9 - Comparar Archivos ⭐⭐⭐☆☆

Implementar un programa que compare dos archivos de texto e indique si son
idénticos o no. Opcionalmente, puede reportar la primera línea y número de
columna donde difieren.
(ejercicio_12_10)=
### Ejercicio 12.10 - Fusionar Archivos ⭐⭐⭐☆☆

Crear un programa que reciba dos rutas de archivo y fusione su contenido en un
tercer archivo. El contenido del segundo archivo debe aparecer después del
contenido del primero.
(ejercicio_12_11)=
### Ejercicio 12.11 - Dividir Archivo Grande ⭐⭐☆☆☆

Escribir un programa que divida un archivo de texto grande en varios archivos
más pequeños, cada uno con un número máximo de `N` líneas. Los nombres de los
archivos de salida pueden ser `parte_1.txt`, `parte_2.txt`, etc.
(ejercicio_12_12)=
### Ejercicio 12.12 - Archivos CSV - Promedio de Columna ⭐⭐⭐☆☆

Leer un archivo en formato CSV (valores separados por comas) que contiene datos
de estudiantes (ej. `nombre,nota1,nota2`). Calcular el promedio de una columna
numérica específica (ej. la segunda columna de notas) e imprimir el resultado.
(ejercicio_12_13)=
## Ejercicio 12.13 - Crear Archivo de Texto ⭐☆☆☆☆

Creá un archivo de texto y escribí "Hola, archivo!" en él.

**Orientación:**
- `FILE *fp = fopen("salida.txt", "w");`
- Verificá: `if (fp == NULL) { perror("Error"); return 1; }`
- Escribí: `fprintf(fp, "Hola, archivo!\n");`
- Cerrá: `fclose(fp);`

---
(ejercicio_12_14)=
## Ejercicio 12.14 - Leer Archivo Completo ⭐☆☆☆☆

Leé y mostrá todo el contenido de un archivo de texto.

**Orientación:**
- Abrí en modo "r"
- Leé línea por línea con `fgets(buffer, tamaño, fp)`
- Mientras no sea EOF: `while (fgets(...) != NULL)`
- Mostrá cada línea en stdout

---
(ejercicio_12_15)=
## Ejercicio 12.15 - Contar Líneas ⭐⭐☆☆☆

Contá cuántas líneas tiene un archivo de texto.

**Orientación:**
- Leé carácter por carácter con `fgetc`
- Contador de saltos de línea: `if (c == '\n') lineas++;`
- Considerá última línea sin '\n' al final

---
(ejercicio_12_16)=
## Ejercicio 12.16 - Copiar Archivo ⭐⭐☆☆☆

Copiá el contenido de un archivo a otro.

**Orientación:**
- Abrí origen en "r"
- Abrí destino en "w"
- Leé carácter por carácter del origen
- Escribí en destino con `fputc`
- Cerrá ambos archivos

---
(ejercicio_12_17)=
## Ejercicio 12.17 - Contar Palabras ⭐⭐⭐☆☆

Contá la cantidad de palabras en un archivo de texto.

**Orientación:**
- Palabra: secuencia de caracteres no-espacio
- Estado: dentro/fuera de palabra
- Al encontrar espacio después de no-espacio: incrementar contador
- Usá `isspace()` de `<ctype.h>`

---
(ejercicio_12_18)=
## Ejercicio 12.18 - Agregar al Final ⭐⭐☆☆☆

Agregá texto al final de un archivo existente sin sobrescribir.

**Orientación:**
- Modo "a" (append)
- `fopen("archivo.txt", "a")`
- Todo lo que escribas se agrega al final
- Si el archivo no existe, se crea

---
(ejercicio_12_19)=
## Ejercicio 12.19 - Buscar Palabra ⭐⭐⭐☆☆

Buscá si una palabra específica existe en un archivo y mostrá la línea.

**Orientación:**
- Leé línea por línea con `fgets`
- Usá `strstr(linea, palabra)` para buscar
- Si `strstr` no retorna NULL: palabra encontrada
- Mostrá número de línea y contenido

---
(ejercicio_12_20)=
## Ejercicio 12.20 - Estadísticas de Archivo ⭐⭐⭐☆☆

Calculá: líneas, palabras, caracteres y bytes de un archivo.

**Orientación:**
- Similar a `wc` de Unix
- Contadores para cada métrica
- Recorré el archivo completo
- Para bytes: `ftell(fp)` al final, o contar en lectura

---
(ejercicio_12_21)=
## Ejercicio 12.21 - Invertir Líneas ⭐⭐⭐⭐☆

Leé un archivo y escribí sus líneas en orden inverso en otro archivo.

**Orientación:**
- Opción 1: Leé todo en array dinámico de strings, escribí al revés
- Opción 2: Leé dos veces (primera cuenta líneas, segunda lee y posiciona)
- Recordá liberar memoria dinámica

---
(ejercicio_12_22)=
## Ejercicio 12.22 - Archivo CSV a Struct ⭐⭐⭐⭐☆

Leé un archivo CSV con datos de personas y cargá en array de estructuras.

**Formato CSV:**
```
Juan,Perez,25
Maria,Gomez,30
```

**Orientación:**
- Estructura: `typedef struct { char nombre[50]; char apellido[50]; int edad; }
  persona_t;`
- Leé línea con `fgets`
- Parseá con `sscanf` o `strtok`
- Almacená en array

---
(ejercicio_12_23)=
## Ejercicio 12.23 - Merge de Archivos Ordenados ⭐⭐⭐⭐☆

Dados dos archivos con números ordenados, generá un tercer archivo con todos
ordenados.

**Orientación:**
- Abrí ambos archivos de entrada y uno de salida
- Leé un número de cada archivo
- Escribí el menor en salida
- Avanzá el archivo del que se tomó el número
- Cuando uno se acabe, copiá el resto del otro

---
(ejercicio_12_24)=
## Ejercicio 12.24 - Reemplazar Palabra ⭐⭐⭐⭐☆

Reemplazá todas las ocurrencias de una palabra por otra en un archivo.

**Orientación:**
- Leé archivo completo en memoria o procesá línea por línea
- Para cada línea, buscá la palabra con `strstr`
- Cuando encontrás: copiá parte antes, palabra nueva, parte después
- Escribí en archivo temporal
- Al final: renombrá temporal al original

---
(ejercicio_12_25)=
## Ejercicio 12.25 - Archivo Binario - Escribir Enteros ⭐⭐⭐☆☆

Escribí un array de enteros en un archivo binario.

**Orientación:**
- Modo "wb" (write binary)
- `fwrite(array, sizeof(int), cantidad, fp)`
- Verificá cantidad escrita: `size_t escritos = fwrite(...)`

---
(ejercicio_12_26)=
## Ejercicio 12.26 - Archivo Binario - Leer Enteros ⭐⭐⭐☆☆

Leé enteros de un archivo binario y mostralos.

**Orientación:**
- Modo "rb" (read binary)
- `fread(array, sizeof(int), cantidad, fp)`
- Leé hasta EOF: `while (fread(&num, sizeof(int), 1, fp) == 1)`

---
(ejercicio_12_27)=
## Ejercicio 12.27 - Archivo Binario de Estructuras ⭐⭐⭐⭐☆

Guardá y leé array de estructuras en archivo binario.

**Orientación:**
- `fwrite(&persona, sizeof(persona_t), 1, fp)`
- `fread(&persona, sizeof(persona_t), 1, fp)`
- Escribí todo el array: `fwrite(array, sizeof(persona_t), n, fp)`
- **Cuidado:** Punteros dentro de structs no se serializan bien

---
(ejercicio_12_28)=
## Ejercicio 12.28 - Acceso Aleatorio ⭐⭐⭐⭐☆

Implementá CRUD (Create, Read, Update, Delete) sobre archivo binario de
registros.

**Orientación:**
- Usa `fseek(fp, offset, SEEK_SET)` para posicionarte
- Offset del registro i: `i * sizeof(registro_t)`
- `ftell(fp)` para obtener posición actual
- Marcá registros eliminados con flag en lugar de borrar físicamente

---
(ejercicio_12_29)=
## Ejercicio 12.29 - Log de Eventos ⭐⭐⭐⭐☆

Implementá sistema de logging que agregue eventos con timestamp a un archivo.

**Orientación:**
- Modo "a" para append
- Cada línea: `[timestamp] nivel: mensaje`
- Timestamp: `time()` y `strftime()`
- Niveles: INFO, WARNING, ERROR
- Función: `void log_evento(const char *nivel, const char *msg)`

---
(ejercicio_12_30)=
## Ejercicio 12.30 - Compresión RLE Simple ⭐⭐⭐⭐⭐

Implementá compresión Run-Length Encoding: caracteres repetidos se almacenan
como `<contador><carácter>`.

**Ejemplo:** "aaabbcccc" → "3a2b4c"

**Orientación:**
- Leé carácter por carácter
- Contá repeticiones consecutivas
- Escribí contador + carácter en salida
- Descompresión: leé contador, repetí carácter esas veces

---
(ejercicio_12_31)=
## Ejercicio 12.31 - Índice de Archivo ⭐⭐⭐⭐⭐

Creá un índice de palabras con sus posiciones (número de línea) en el archivo.

**Orientación:**
- Diccionario: palabra → lista de líneas
- Leé archivo, parseá palabras
- Para cada palabra: agregá número de línea actual a su lista
- Escribí índice ordenado en archivo de salida

---
(ejercicio_12_32)=
## Ejercicio 12.32 - Diferencia Entre Archivos (diff simple) ⭐⭐⭐⭐⭐

Implementá versión simple de `diff`: mostrá líneas diferentes entre dos
archivos.

**Orientación:**
- Abrí ambos archivos
- Leé línea por línea de ambos simultáneamente
- Compará con `strcmp`
- Si difieren: mostrá número de línea y contenido de ambas
- Manejá archivos de diferente longitud

---
(ejercicio_12_33)=
## Ejercicio 12.33 - s Adicionales ⭐⭐☆☆☆

(ejercicio_12_34)=
### Ejercicio 12.34 - Cifrado César ⭐⭐⭐⭐☆

Cifrá/descifrá un archivo usando cifrado César (rotación de N posiciones en
alfabeto).

**Orientación:**
- Para cifrar: `c_cifrado = ((c - 'a' + n) % 26) + 'a'`
- Para descifrar: `c_original = ((c - 'a' - n + 26) % 26) + 'a'`
- Mantené espacios y puntuación sin cambios

---
(ejercicio_12_35)=
### Ejercicio 12.35 - Archivo de Configuración ⭐⭐⭐⭐☆

Leé archivo de configuración estilo `clave=valor`.

**Ejemplo:**
```
puerto=8080
host=localhost
timeout=30
```

**Orientación:**
- Parseá cada línea buscando '='
- Parte antes: clave, parte después: valor
- Almacená en estructura o diccionario
- Ignorá líneas vacías y comentarios (empiezan con #)

---
(ejercicio_12_36)=
### Ejercicio 12.36 - Serialización JSON Simple ⭐⭐⭐⭐⭐

Escribí y leé una estructura simple en formato JSON.

**Orientación:**
- Escribir: formateá manualmente con `fprintf`
- Leer: parseá línea por línea o carácter por carácter
- Solo soportá tipos básicos: string, int, bool
- No necesita soportar anidamiento complejo

---

## Notas Finales

:::{danger} Manejo de Errores Crítico

**Siempre verificar:**
```{code-block} c
:linenos:
FILE *fp = fopen("archivo.txt", "r");
if (fp == NULL) {
    perror("Error al abrir archivo");
    return EXIT_FAILURE;
}

// Usar archivo...

if (fclose(fp) != 0) {
    perror("Error al cerrar archivo");
}

```
<!-- {code-block} c -->

**Verificar operaciones:**
```{code-block} c
:linenos:
if (fprintf(fp, "texto") < 0) {
    // Error al escribir
}

if (fread(buffer, size, count, fp) != count) {
    if (feof(fp)) {
        // Fin de archivo
    } else {
        // Error de lectura
    }
}

```
<!-- {code-block} c -->

:::
<!-- {danger} Manejo de Errores Crítico -->

:::{tip} Modos de Apertura

| Modo | Descripción | Crea | Trunca | Posición |
|------|-------------|------|--------|----------|
| `"r"` | Read | No | No | Inicio |
| `"w"` | Write | Sí | Sí | Inicio |
| `"a"` | Append | Sí | No | Final |
| `"r+"` | Read/Write | No | No | Inicio |
| `"w+"` | Read/Write | Sí | Sí | Inicio |
| `"a+"` | Read/Append | Sí | No | Final |

Agregar `b` para binario: `"rb"`, `"wb"`, `"ab"`, etc.

:::
<!-- {tip} Modos de Apertura -->

:::{note} Funciones Clave

**Texto:**
- `fgets(buffer, size, fp)` - Lee línea
- `fputs(string, fp)` - Escribe string
- `fprintf(fp, formato, ...)` - Escribe formateado
- `fscanf(fp, formato, ...)` - Lee formateado

**Binario:**
- `fread(buffer, size, count, fp)` - Lee bloques
- `fwrite(buffer, size, count, fp)` - Escribe bloques

**Posicionamiento:**
- `fseek(fp, offset, origen)` - Mueve posición
  - `SEEK_SET`: desde inicio
  - `SEEK_CUR`: desde posición actual
  - `SEEK_END`: desde final
- `ftell(fp)` - Retorna posición actual
- `rewind(fp)` - Va al inicio (equiv. `fseek(fp, 0, SEEK_SET)`)

**Estado:**
- `feof(fp)` - Verifica fin de archivo
- `ferror(fp)` - Verifica error
- `clearerr(fp)` - Limpia flags de error/EOF

:::
<!-- {note} Funciones Clave -->

:::{warning} Errores Comunes

1. **No verificar NULL:**
   ```c
   FILE *fp = fopen("archivo.txt", "r");
   fprintf(fp, "texto");  // PELIGRO: si fopen falló
   ```

2. **No cerrar archivos:**
   ```c
   // Memory leak y posible pérdida de datos
   fopen(...);  // Sin fclose
   ```

3. **Buffer overflow con fgets:**
   ```c
   char buffer[10];
   fgets(buffer, 100, fp);  // MAL: tamaño > buffer
   fgets(buffer, 10, fp);   // BIEN
   ```

4. **Modo binario vs texto:**
   ```c
   // En Windows, modo texto convierte \n ↔ \r\n
   // Para datos binarios, siempre usar "rb"/"wb"
   ```

5. **Mezclar lectura/escritura sin flush:**
   ```c
   // En modo "r+", necesitas fflush o fseek entre read/write
   fread(...);
   fflush(fp);  // O fseek(fp, 0, SEEK_CUR)
   fwrite(...);
   ```

:::
<!-- {warning} Errores Comunes -->

:::{tip} Patrones Útiles

**Leer línea por línea:**
``` c
char linea[256];
while (fgets(linea, sizeof(linea), fp) != NULL) {
    // Procesar linea
}
```
<!-- c -->

**Leer hasta EOF:**
``` c
int c;
while ((c = fgetc(fp)) != EOF) {
    // Procesar carácter
}
```
<!-- c -->

**Tamaño de archivo:**
``` c
fseek(fp, 0, SEEK_END);
long tamaño = ftell(fp);
rewind(fp);
```
<!-- c -->

**Leer archivo completo en memoria:**
```{code-block} c
:linenos:
fseek(fp, 0, SEEK_END);
long tam = ftell(fp);
rewind(fp);
char *contenido = malloc(tam + 1);
fread(contenido, 1, tam, fp);
contenido[tam] = '\0';

```
<!-- {code-block} c -->

:::
<!-- {tip} Patrones Útiles -->

Estas consignas cubren operaciones de archivo desde básicas hasta avanzadas,
tanto en modo texto como binario, preparando para manejo robusto de persistencia
de datos.

