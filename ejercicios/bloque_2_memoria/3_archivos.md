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
- {ref}`trabajando-con-archivos-de-texto-en-c`

### Prerrequisitos Conceptuales
Antes de resolver esta guía, el estudiante debe dominar:
1. Descriptor de archivo y streams en C (`FILE *`) ({ref}`trabajando-con-archivos-de-texto-en-c`).
2. Modos de apertura (`"r"`, `"w"`, `"a"`) y verificación obligatoria contra `NULL` ante archivos inexistentes o sin permisos.
3. Lectura y escritura segura mediante buffers fijos (`fgets`, `fputs`, `fscanf`, `fprintf`).
4. Detección precisa de fin de archivo (`feof`, retorno de `fscanf`/`fgets`) sin lectura redundante.
5. Cierre mandatorio con `fclose` para vaciar búferes y liberar descriptores del sistema operativo.

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

(ej_b2_c04_01)=
### Ejercicio 2.04.01 - ¿Es correcto el formato? ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c04_01_formato_correcto

Desarrollá una función `bool es_formato_correcto(const char *ruta)` que valide
si un archivo cumple el formato numérico especificado:
1. La primera línea contiene un entero $N \ge 0$ (la cantidad esperada).
2. Le siguen exactamente $N$ líneas con un entero cada una.
3. Retorna `true` si el formato coincide exactamente y `false` ante discrepancias o error de apertura.

**Tabla de Vectores de Prueba:**

| Archivo | Contenido | Retorno Esperado |
| :--- | :--- | :--- |
| `valido.txt` | `3\n10\n20\n30\n` | `true` |
| `incompleto.txt` | `3\n10\n20\n` | `false` |
| `exceso.txt` | `2\n10\n20\n30\n` | `false` |
| `inexistente.txt` | No existe | `false` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool es_formato_correcto(const char *ruta) {
    if (ruta == NULL) {
        return false;
    }
    FILE *f = fopen(ruta, "r");
    if (f == NULL) {
        return false;
    }

    int esperado = 0;
    if (fscanf(f, "%d", &esperado) != 1 || esperado < 0) {
        fclose(f);
        return false;
    }

    int leidos = 0;
    int valor = 0;
    while (fscanf(f, "%d", &valor) == 1) {
        leidos++;
    }

    fclose(f);
    return (leidos == esperado);
}

static void crear_archivo_prueba(const char *ruta, const char *contenido) {
    FILE *f = fopen(ruta, "w");
    assert(f != NULL);
    fputs(contenido, f);
    fclose(f);
}

int main(void) {
    const char *f1 = "temp_valido.txt";
    const char *f2 = "temp_incompleto.txt";
    const char *f3 = "temp_exceso.txt";

    crear_archivo_prueba(f1, "3\n10\n20\n30\n");
    crear_archivo_prueba(f2, "3\n10\n20\n");
    crear_archivo_prueba(f3, "2\n10\n20\n30\n");

    assert(es_formato_correcto(f1) == true);
    assert(es_formato_correcto(f2) == false);
    assert(es_formato_correcto(f3) == false);
    assert(es_formato_correcto("archivo_que_no_existe_404.txt") == false);
    assert(es_formato_correcto(NULL) == false);

    remove(f1);
    remove(f2);
    remove(f3);
    return 0;
}
```
::::
:::

(ej_b2_c04_02)=
### Ejercicio 2.04.02 - ¿Está ordenado? ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c04_02_verificar_orden

Implementá una función `int verificar_orden(const char *ruta)` que determine si
los números contenidos en el archivo están ordenados:
- Retorna `1` si la secuencia de $N$ números es estrictamente ascendente o no decreciente ($v_i \le v_{i+1}$).
- Retorna `-1` si es estrictamente descendente o no creciente ($v_i \ge v_{i+1}$).
- Retorna `0` si está desordenada.
- Retorna `-2` ante error de archivo o formato inválido.

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int verificar_orden(const char *ruta) {
    if (ruta == NULL) {
        return -2;
    }
    FILE *f = fopen(ruta, "r");
    if (f == NULL) {
        return -2;
    }

    int n = 0;
    if (fscanf(f, "%d", &n) != 1 || n < 0) {
        fclose(f);
        return -2;
    }

    if (n <= 1) {
        fclose(f);
        return 1; /* Secuencia trivialmente ordenada */
    }

    int anterior = 0;
    if (fscanf(f, "%d", &anterior) != 1) {
        fclose(f);
        return -2;
    }

    bool es_asc = true;
    bool es_desc = true;
    int actual = 0;

    for (int i = 1; i < n; ++i) {
        if (fscanf(f, "%d", &actual) != 1) {
            fclose(f);
            return -2;
        }
        if (actual < anterior) {
            es_asc = false;
        }
        if (actual > anterior) {
            es_desc = false;
        }
        anterior = actual;
    }

    fclose(f);

    if (es_asc) return 1;
    if (es_desc) return -1;
    return 0;
}

static void crear_archivo(const char *ruta, const char *contenido) {
    FILE *f = fopen(ruta, "w");
    assert(f != NULL);
    fputs(contenido, f);
    fclose(f);
}

int main(void) {
    const char *f_asc = "temp_asc.txt";
    const char *f_desc = "temp_desc.txt";
    const char *f_desord = "temp_desord.txt";

    crear_archivo(f_asc, "4\n1\n3\n5\n7\n");
    crear_archivo(f_desc, "4\n9\n6\n4\n2\n");
    crear_archivo(f_desord, "4\n3\n8\n2\n9\n");

    assert(verificar_orden(f_asc) == 1);
    assert(verificar_orden(f_desc) == -1);
    assert(verificar_orden(f_desord) == 0);
    assert(verificar_orden("inexistente_999.txt") == -2);
    assert(verificar_orden(NULL) == -2);

    remove(f_asc);
    remove(f_desc);
    remove(f_desord);
    return 0;
}
```
::::
:::

---

## Manipulación de Archivos

(ej_b2_c04_03)=
### Ejercicio 2.04.03 - Ordenar archivo ⭐⭐☆☆☆

Un programa que lea los números de un archivo a un arreglo, ordene el arreglo en
memoria y luego escriba el contenido ordenado a un nuevo archivo, respetando el
formato.

**Ejemplo de uso:**
`./ordena_archivo entrada.txt salida_ordenada.txt asc`

(ej_b2_c04_04)=
### Ejercicio 2.04.04 - Generador Lineal de Archivos ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c04_04_generador_lineal

Implementá una función `bool generar_lineal(const char *ruta, int cantidad, int inicio, int paso)` que genere un archivo numérico formateado:
1. La primera línea registra `cantidad`.
2. Las líneas subsiguientes registran los valores en progresión aritmética: $inicio + i \times paso$.
3. Retorna `true` si la escritura finalizó con éxito y `false` ante parámetros inválidos (`cantidad < 0` o `ruta == NULL`) o error de apertura.

**Tabla de Vectores de Prueba:**

| Parámetros `(cantidad, inicio, paso)` | Retorno Esperado | Contenido Escrito |
| :--- | :--- | :--- |
| `(5, 10, 2)` | `true` | `5\n10\n12\n14\n16\n18\n` |
| `(0, 5, 1)` | `true` | `0\n` |
| `(-3, 1, 1)` | `false` | No crea archivo |
| `(4, 0, 0)` | `true` | `4\n0\n0\n0\n0\n` |

::::{solution}
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool generar_lineal(const char *ruta, int cantidad, int inicio, int paso) {
    if (ruta == NULL || cantidad < 0) {
        return false;
    }
    FILE *f = fopen(ruta, "w");
    if (f == NULL) {
        return false;
    }

    if (fprintf(f, "%d\n", cantidad) < 0) {
        fclose(f);
        return false;
    }

    int val = inicio;
    for (int i = 0; i < cantidad; ++i) {
        if (fprintf(f, "%d\n", val) < 0) {
            fclose(f);
            return false;
        }
        val += paso;
    }

    fclose(f);
    return true;
}

int main(void) {
    const char *tmp = "temp_lineal_test.txt";

    assert(generar_lineal(tmp, 5, 10, 2) == true);

    /* Verificar lectura */
    FILE *f = fopen(tmp, "r");
    assert(f != NULL);
    int n = 0;
    assert(fscanf(f, "%d", &n) == 1 && n == 5);
    int esperados[] = {10, 12, 14, 16, 18};
    for (int i = 0; i < 5; ++i) {
        int v = 0;
        assert(fscanf(f, "%d", &v) == 1 && v == esperados[i]);
    }
    fclose(f);
    remove(tmp);

    /* Casos defensivos */
    assert(generar_lineal(NULL, 5, 1, 1) == false);
    assert(generar_lineal("temp_invalido.txt", -2, 1, 1) == false);

    return 0;
}
```
::::
:::

(ej_b2_c04_05)=
### Ejercicio 2.04.05 - Generador aleatorio ⭐⭐☆☆☆

Implementar `generar_aleatorio(ruta, cantidad, min, max)`.

**Lógica**: Usar `srand(time(NULL))` una vez al inicio del programa, y luego
`rand() % (max - min + 1) + min` para generar cada número.

---

## Operaciones Avanzadas

(ej_b2_c04_06)=
### Ejercicio 2.04.06 - Contar Líneas, Palabras y Caracteres ⭐⭐☆☆☆

Implementar una versión simple del comando `wc` de Unix. El programa debe
recibir una ruta de archivo y reportar el número total de líneas, palabras y
caracteres que contiene.

(ej_b2_c04_07)=
### Ejercicio 2.04.07 - Copiar Archivo ⭐⭐☆☆☆

Crear un programa que copie el contenido de un archivo de origen a un archivo de
destino. El programa debe recibir ambas rutas como argumentos. Se puede hacer
leyendo y escribiendo línea por línea o en bloques de bytes.

(ej_b2_c04_08)=
### Ejercicio 2.04.08 - Buscar y Reemplazar en Archivo ⭐⭐☆☆☆

Escribir un programa que busque todas las ocurrencias de una cadena en un
archivo y las reemplace por otra, guardando el resultado en un nuevo archivo de
salida.

(ej_b2_c04_09)=
### Ejercicio 2.04.09 - Comparar Archivos ⭐⭐⭐☆☆

Implementar un programa que compare dos archivos de texto e indique si son
idénticos o no. Opcionalmente, puede reportar la primera línea y número de
columna donde difieren.

(ej_b2_c04_10)=
### Ejercicio 2.04.10 - Fusionar Archivos ⭐⭐⭐☆☆

Crear un programa que reciba dos rutas de archivo y fusione su contenido en un
tercer archivo. El contenido del segundo archivo debe aparecer después del
contenido del primero.

(ej_b2_c04_11)=
### Ejercicio 2.04.11 - Dividir Archivo Grande ⭐⭐☆☆☆

Escribir un programa que divida un archivo de texto grande en varios archivos
más pequeños, cada uno con un número máximo de $N$ líneas. Los nombres de los
archivos de salida pueden ser `parte_1.txt`, `parte_2.txt`, etc.

(ej_b2_c04_12)=
### Ejercicio 2.04.12 - Archivos CSV - Promedio de Columna ⭐⭐⭐☆☆

Leer un archivo en formato CSV (valores separados por comas) que contiene datos
de estudiantes (ej. `nombre,nota1,nota2`). Calcular el promedio de una columna
numérica específica (ej. la segunda columna de notas) e imprimir el resultado.

(ej_b2_c04_13)=
## Ejercicio 2.04.13 - Crear Archivo de Texto ⭐☆☆☆☆

Creá un archivo de texto y escribí "Hola, archivo!" en él.

**Orientación:**
- `FILE *fp = fopen("salida.txt", "w");`
- Verificá: `if (fp == NULL) { perror("Error"); return 1; }`
- Escribí: `fprintf(fp, "Hola, archivo!\n");`
- Cerrá: `fclose(fp);`

---

(ej_b2_c04_14)=
## Ejercicio 2.04.14 - Leer Archivo Completo ⭐☆☆☆☆

Leé y mostrá todo el contenido de un archivo de texto.

**Orientación:**
- Abrí en modo "r"
- Leé línea por línea con `fgets(buffer, tamaño, fp)`
- Mientras no sea EOF: `while (fgets(...) != NULL)`
- Mostrá cada línea en stdout

---

(ej_b2_c04_15)=
### Ejercicio 2.04.15 - Conteo Robusto de Líneas en Archivo de Texto ⭐⭐☆☆☆

:::{exercise}
:label: ej_b2_c04_15_contar_lineas
:enumerator: archivos-15

Implementá una función defensiva que cuente la cantidad de líneas en un archivo de texto:
```c
long contar_lineas_archivo(const char *ruta);
```
La función debe leer el archivo carácter por carácter utilizando `fgetc`.
Una línea se delimita por el carácter `'\n'`. Si el archivo contiene datos pero el último registro no finaliza con `'\n'`, esa última línea también debe ser contabilizada. Si el archivo está completamente vacío ($0$ bytes), debe retornar `0`. Si `ruta == NULL` o el archivo no puede abrirse, debe retornar `-1`.

**Nivel de Bloom:** Nivel 3 (Aplicación).  
**Conceptos requeridos:** Flujos de entrada de texto (`FILE *`, `fgetc`), detección de fin de archivo (`EOF`), manejo de casos sin delimitador final.  
**Techo conceptual:** Prohibido el uso de memoria dinámica innecesaria o cargar todo el archivo en un búfer.

#### Contrato de la Función
- **Firma:** `long contar_lineas_archivo(const char *ruta);`
- **Precondiciones:** `ruta != NULL`.
- **Postcondiciones:** Retorna el número de líneas $\ge 0$, o `-1` ante error de apertura. Todo archivo abierto debe cerrarse con `fclose`.

#### Tabla de Vectores de Prueba

| Contenido del Archivo | Retorno Esperado | Justificación Técnica |
| :--- | :--- | :--- |
| `"Uno\nDos\nTres\n"` | `3` | Tres líneas terminadas con `'\n'` |
| `"Linea unica sin salto"` | `1` | Archivo con texto sin salto final |
| `""` (0 bytes) | `0` | Archivo vacío |
| Archivo inexistente / `NULL` | `-1` | Error defensivo de apertura |

:::

::::{solution} ej_b2_c04_15_contar_lineas
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

long contar_lineas_archivo(const char *ruta)
{
    if (ruta == NULL)
    {
        return -1;
    }

    FILE *f = fopen(ruta, "r");
    if (f == NULL)
    {
        return -1;
    }

    long total_lineas = 0;
    int c = 0;
    int ultimo_c = '\n';

    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n')
        {
            total_lineas++;
        }
        ultimo_c = c;
    }

    // Si el archivo no termina en '\n' y no estaba vacío
    if (ultimo_c != '\n')
    {
        total_lineas++;
    }

    fclose(f);
    return total_lineas;
}

int main(void)
{
    const char *tmp_3 = "test_3_lineas.txt";
    FILE *f = fopen(tmp_3, "w");
    assert(f != NULL);
    fputs("Uno\nDos\nTres\n", f);
    fclose(f);
    assert(contar_lineas_archivo(tmp_3) == 3);
    remove(tmp_3);

    const char *tmp_sin_salto = "test_sin_salto.txt";
    f = fopen(tmp_sin_salto, "w");
    assert(f != NULL);
    fputs("Linea unica sin salto", f);
    fclose(f);
    assert(contar_lineas_archivo(tmp_sin_salto) == 1);
    remove(tmp_sin_salto);

    const char *tmp_vacio = "test_vacio.txt";
    f = fopen(tmp_vacio, "w");
    assert(f != NULL);
    fclose(f);
    assert(contar_lineas_archivo(tmp_vacio) == 0);
    remove(tmp_vacio);

    // Archivo inexistente y ruta NULL
    assert(contar_lineas_archivo("archivo_fantasma_404.txt") == -1);
    assert(contar_lineas_archivo(NULL) == -1);

    return 0;
}
```

::::
<!-- {solution} ej_b2_c04_15_contar_lineas -->

(ej_b2_c04_16)=
## Ejercicio 2.04.16 - Copiar Archivo ⭐⭐☆☆☆

Copiá el contenido de un archivo a otro.

**Orientación:**
- Abrí origen en "r"
- Abrí destino en "w"
- Leé carácter por carácter del origen
- Escribí en destino con `fputc`
- Cerrá ambos archivos

---

(ej_b2_c04_17)=
## Ejercicio 2.04.17 - Contar Palabras ⭐⭐⭐☆☆

Contá la cantidad de palabras en un archivo de texto.

**Orientación:**
- Palabra: secuencia de caracteres no-espacio
- Estado: dentro/fuera de palabra
- Al encontrar espacio después de no-espacio: incrementar contador
- Usá `isspace()` de `<ctype.h>`

---

(ej_b2_c04_18)=
## Ejercicio 2.04.18 - Agregar al Final ⭐⭐☆☆☆

Agregá texto al final de un archivo existente sin sobrescribir.

**Orientación:**
- Modo "a" (append)
- `fopen("archivo.txt", "a")`
- Todo lo que escribas se agrega al final
- Si el archivo no existe, se crea

---

(ej_b2_c04_19)=
## Ejercicio 2.04.19 - Buscar Palabra ⭐⭐⭐☆☆

Buscá si una palabra específica existe en un archivo y mostrá la línea.

**Orientación:**
- Leé línea por línea con `fgets`
- Usá `strstr(linea, palabra)` para buscar
- Si `strstr` no retorna NULL: palabra encontrada
- Mostrá número de línea y contenido

---

(ej_b2_c04_20)=
## Ejercicio 2.04.20 - Estadísticas de Archivo ⭐⭐⭐☆☆

Calculá: líneas, palabras, caracteres y bytes de un archivo.

**Orientación:**
- Similar a `wc` de Unix
- Contadores para cada métrica
- Recorré el archivo completo
- Para bytes: `ftell(fp)` al final, o contar en lectura

---

(ej_b2_c04_21)=
## Ejercicio 2.04.21 - Invertir Líneas ⭐⭐⭐⭐☆

Leé un archivo y escribí sus líneas en orden inverso en otro archivo.

**Orientación:**
- Opción 1: Leé todo en array dinámico de strings, escribí al revés
- Opción 2: Leé dos veces (primera cuenta líneas, segunda lee y posiciona)
- Recordá liberar memoria dinámica

---

(ej_b2_c04_22)=
## Ejercicio 2.04.22 - Archivo CSV a Struct ⭐⭐⭐⭐☆

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

(ej_b2_c04_23)=
## Ejercicio 2.04.23 - Merge de Archivos Ordenados ⭐⭐⭐⭐☆

Dados dos archivos con números ordenados, generá un tercer archivo con todos
ordenados.

**Orientación:**
- Abrí ambos archivos de entrada y uno de salida
- Leé un número de cada archivo
- Escribí el menor en salida
- Avanzá el archivo del que se tomó el número
- Cuando uno se acabe, copiá el resto del otro

---

(ej_b2_c04_24)=
## Ejercicio 2.04.24 - Reemplazar Palabra ⭐⭐⭐⭐☆

Reemplazá todas las ocurrencias de una palabra por otra en un archivo.

**Orientación:**
- Leé archivo completo en memoria o procesá línea por línea
- Para cada línea, buscá la palabra con `strstr`
- Cuando encontrás: copiá parte antes, palabra nueva, parte después
- Escribí en archivo temporal
- Al final: renombrá temporal al original

---

(ej_b2_c04_25)=
## Ejercicio 2.04.25 - Archivo Binario - Escribir Enteros ⭐⭐⭐☆☆

Escribí un array de enteros en un archivo binario.

**Orientación:**
- Modo "wb" (write binary)
- `fwrite(array, sizeof(int), cantidad, fp)`
- Verificá cantidad escrita: `size_t escritos = fwrite(...)`

---

(ej_b2_c04_26)=
## Ejercicio 2.04.26 - Archivo Binario - Leer Enteros ⭐⭐⭐☆☆

Leé enteros de un archivo binario y mostralos.

**Orientación:**
- Modo "rb" (read binary)
- `fread(array, sizeof(int), cantidad, fp)`
- Leé hasta EOF: `while (fread(&num, sizeof(int), 1, fp) == 1)`

---

(ej_b2_c04_27)=
## Ejercicio 2.04.27 - Archivo Binario de Estructuras ⭐⭐⭐⭐☆

Guardá y leé array de estructuras en archivo binario.

**Orientación:**
- `fwrite(&persona, sizeof(persona_t), 1, fp)`
- `fread(&persona, sizeof(persona_t), 1, fp)`
- Escribí todo el array: `fwrite(array, sizeof(persona_t), n, fp)`
- **Cuidado:** Punteros dentro de structs no se serializan bien

---

(ej_b2_c04_28)=
## Ejercicio 2.04.28 - Acceso Aleatorio ⭐⭐⭐⭐☆

Implementá CRUD (Create, Read, Update, Delete) sobre archivo binario de
registros.

**Orientación:**
- Usa `fseek(fp, offset, SEEK_SET)` para posicionarte
- Offset del registro i: `i * sizeof(registro_t)`
- `ftell(fp)` para obtener posición actual
- Marcá registros eliminados con flag en lugar de borrar físicamente

---

(ej_b2_c04_29)=
## Ejercicio 2.04.29 - Log de Eventos ⭐⭐⭐⭐☆

Implementá sistema de logging que agregue eventos con timestamp a un archivo.

**Orientación:**
- Modo "a" para append
- Cada línea: `[timestamp] nivel: mensaje`
- Timestamp: `time()` y `strftime()`
- Niveles: INFO, WARNING, ERROR
- Función: `void log_evento(const char *nivel, const char *msg)`

---

(ej_b2_c04_30)=
## Ejercicio 2.04.30 - Compresión RLE Simple ⭐⭐⭐⭐⭐

Implementá compresión Run-Length Encoding: caracteres repetidos se almacenan
como `<contador><carácter>`.

**Ejemplo:** "aaabbcccc" → "3a2b4c"

**Orientación:**
- Leé carácter por carácter
- Contá repeticiones consecutivas
- Escribí contador + carácter en salida
- Descompresión: leé contador, repetí carácter esas veces

---

(ej_b2_c04_31)=
## Ejercicio 2.04.31 - Índice de Archivo ⭐⭐⭐⭐⭐

Creá un índice de palabras con sus posiciones (número de línea) en el archivo.

**Orientación:**
- Diccionario: palabra → lista de líneas
- Leé archivo, parseá palabras
- Para cada palabra: agregá número de línea actual a su lista
- Escribí índice ordenado en archivo de salida

---

(ej_b2_c04_32)=
## Ejercicio 2.04.32 - Diferencia Entre Archivos (diff simple) ⭐⭐⭐⭐⭐

Implementá versión simple de `diff`: mostrá líneas diferentes entre dos
archivos.

**Orientación:**
- Abrí ambos archivos
- Leé línea por línea de ambos simultáneamente
- Compará con `strcmp`
- Si difieren: mostrá número de línea y contenido de ambas
- Manejá archivos de diferente longitud

---

(ej_b2_c04_33)=
## Ejercicio 2.04.33 - s Adicionales ⭐⭐☆☆☆

(ej_b2_c04_34)=
### Ejercicio 2.04.34 - Cifrado César ⭐⭐⭐⭐☆

Cifrá/descifrá un archivo usando cifrado César (rotación de N posiciones en
alfabeto).

**Orientación:**
- Para cifrar: `c_cifrado = ((c - 'a' + n) % 26) + 'a'`
- Para descifrar: `c_original = ((c - 'a' - n + 26) % 26) + 'a'`
- Mantené espacios y puntuación sin cambios

---

(ej_b2_c04_35)=
### Ejercicio 2.04.35 - Archivo de Configuración ⭐⭐⭐⭐☆

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

(ej_b2_c04_36)=
### Ejercicio 2.04.36 - Serialización JSON Simple ⭐⭐⭐⭐⭐

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
if (fp == NULL)
{
    perror("Error al abrir archivo");
    return EXIT_FAILURE;
}
// Usar archivo...
if (fclose(fp) != 0)
{
    perror("Error al cerrar archivo");
}
```
<!-- {code-block} c -->

**Verificar operaciones:**
```{code-block} c
:linenos:
if (fprintf(fp, "texto") < 0)
{
    // Error al escribir
}
if (fread(buffer, size, count, fp) != count)
{
    if (feof(fp))
    {
        // Fin de archivo
    }
    else
    {
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
   fprintf(fp, "texto"); // PELIGRO: si fopen falló
   ```

2. **No cerrar archivos:**
   ```c
   // Memory leak y posible pérdida de datos
   fopen(...); // Sin fclose
   ```

3. **Buffer overflow con fgets:**
   ```c
   char buffer[10];
   fgets(buffer, 100, fp); // MAL: tamaño > buffer
   fgets(buffer, 10, fp);  // BIEN
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
   fflush(fp); // O fseek(fp, 0, SEEK_CUR)
   fwrite(...);
   ```

:::
<!-- {warning} Errores Comunes -->

:::{tip} Patrones Útiles

**Leer línea por línea:**
``` c
char linea[256];
while (fgets(linea, sizeof(linea), fp) != NULL)
{
    // Procesar linea
}
```
<!-- c -->

**Leer hasta EOF:**
``` c
int c;
while ((c = fgetc(fp)) != EOF)
{
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

