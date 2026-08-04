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

### Ejercicio 3.1 - ¿Es correcto el formato?

Desarrollar una función `bool es_formato_correcto(const char *ruta)`.

**Lógica**: Abrir el archivo, leer el primer número (la cuenta esperada). Luego,
iterar con `fgets` o `fscanf` contando las líneas restantes. Finalmente,
comparar la cuenta real con la esperada.

### Ejercicio 3.2 - ¿Está ordenado?

Implementar `int verificar_orden(const char *ruta)`.

**Lógica**: Leer el archivo, guardando el número anterior en cada iteración y
comparándolo con el actual para determinar si la secuencia es ascendente,
descendente o desordenada.

---

## Manipulación de Archivos

### Ejercicio 3.3 - Ordenar archivo

Un programa que lea los números de un archivo a un arreglo, ordene el arreglo en
memoria y luego escriba el contenido ordenado a un nuevo archivo, respetando el
formato.

**Ejemplo de uso:**
`./ordena_archivo entrada.txt salida_ordenada.txt asc`

### Ejercicio 3.4 - Generador lineal

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

### Ejercicio 3.5 - Generador aleatorio

Implementar `generar_aleatorio(ruta, cantidad, min, max)`.

**Lógica**: Usar `srand(time(NULL))` una vez al inicio del programa, y luego
`rand() % (max - min + 1) + min` para generar cada número.

---

## Operaciones Avanzadas

### Ejercicio 3.6 - Contar Líneas, Palabras y Caracteres

Implementar una versión simple del comando `wc` de Unix. El programa debe
recibir una ruta de archivo y reportar el número total de líneas, palabras y
caracteres que contiene.

### Ejercicio 3.7 - Copiar Archivo

Crear un programa que copie el contenido de un archivo de origen a un archivo de
destino. El programa debe recibir ambas rutas como argumentos. Se puede hacer
leyendo y escribiendo línea por línea o en bloques de bytes.

### Ejercicio 3.8 - Buscar y Reemplazar en Archivo

Escribir un programa que busque todas las ocurrencias de una cadena en un
archivo y las reemplace por otra, guardando el resultado en un nuevo archivo de
salida.

### Ejercicio 3.9 - Comparar Archivos

Implementar un programa que compare dos archivos de texto e indique si son
idénticos o no. Opcionalmente, puede reportar la primera línea y número de
columna donde difieren.

### Ejercicio 3.10 - Fusionar Archivos

Crear un programa que reciba dos rutas de archivo y fusione su contenido en un
tercer archivo. El contenido del segundo archivo debe aparecer después del
contenido del primero.

### Ejercicio 3.11 - Dividir Archivo Grande

Escribir un programa que divida un archivo de texto grande en varios archivos
más pequeños, cada uno con un número máximo de `N` líneas. Los nombres de los
archivos de salida pueden ser `parte_1.txt`, `parte_2.txt`, etc.

### Ejercicio 3.12 - Archivos CSV - Promedio de Columna

Leer un archivo en formato CSV (valores separados por comas) que contiene datos
de estudiantes (ej. `nombre,nota1,nota2`). Calcular el promedio de una columna
numérica específica (ej. la segunda columna de notas) e imprimir el resultado.
