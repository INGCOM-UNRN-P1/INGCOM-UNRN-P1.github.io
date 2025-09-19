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
iterar con `fgets` o `fscanf` contando las líneas restantes. Finalmente,
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
