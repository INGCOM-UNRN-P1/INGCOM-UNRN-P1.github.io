# 62 - Arreglos y cadenas

## 63 - Arreglos

### 64 - Carga de arreglos

Escribir una función que permita cargar un arreglo con números enteros.

### 65 - Suma

Escribir un programa que lea un arreglo de números enteros y calcule la
suma de todos los elementos.

### 66 - Máximo

Crear un programa que encuentre el elemento máximo en un arreglo de
números enteros.

### 67 - Inversión

Implementar un programa que invierta el orden de los elementos en un
arreglo.

### 68 - ¿Esta ordenado?

Escribir un programa que verifique si un arreglo está ordenado de forma
ascendente.

### 69 - Promedio

Crear un programa que encuentre el promedio de los elementos en un
arreglo de números flotantes.

### 70 - Repeticiones

Implementar un programa que cuente cuántas veces aparece un número
específico en un arreglo.

### 71 - Casi máximo

Escribir un programa que encuentre el segundo elemento más grande en un
arreglo de números enteros.

### 72 - Copiadora

Crear un programa que copie los elementos de un arreglo a otro arreglo.

### 73 - Deduplicación

Implementar un programa que elimine todos los elementos duplicados de un
arreglo.

### 74 - Suma de pares

Escribir un programa que encuentre la suma de los elementos en las
posiciones pares de un arreglo.

### 75 - Solo lo positivo

Escribir un programa que verifique si un arreglo contiene solo números
positivos.

### 76 - i-esimo

Implementar un programa que encuentre la posición de un elemento
específico en un arreglo.

### 77 - Productoria

Implementar un programa que encuentre el producto de los elementos en un
arreglo de números enteros.

### 78 - Próximo

Crear un programa que encuentre el elemento más cercano a un valor
específico en un arreglo.

## 79 - Cadenas

### 80 - ¿Cuantas vocales tiene?

Contar la cantidad de vocales en una palabra.

### 81 - ¿Es un palindromo?

Verificar si una palabra es un palíndromo.

### 82 - ¿Es subcadena?

Verificar si una cadena es subcadena de otra.

### 83 - ¿Es un número?

Verificar si una cadena es un número válido.

### 84 - ¿Es un número de teléfono?

Determinar si una cadena es un número de teléfono válido.

### 85 - Anagrama

Verificar si una palabra es un anagrama de otra.

### 86 - ¿Es un acrónimo?

Verificar si una cadena es un acrónimo.

### 87 - Pangrama

Verificar si una cadena es un pangrama, esto es, que contiene todas las
letras del alfabeto.

### 88 - Anagrama de palindromo

Determinar si una palabra es un anagrama de palíndromo.

### 89 - ¿Esta limpia?

Determinar si una cadena contiene solo caracteres alfabéticos.

## 1.9 - Conversiones de base

Aunque *técnicamente* es posible, las conversiones de y hacia valores
distintos a los que son base~10~, van como cadenas de caracteres.

### 56 - Binario a Decimal

Escribir un programa que dado un número binario (base~2~) lo convierta a
decimal (base~10~)

Entrada

1111

Salida

El numero 1111 binario es 15 en decimal

### 57 - Hexadecimal a Decimal

Escribir un programa que dado un número hexadecimal (base~16~) lo
convierta a un número decimal (base~10~)

Entrada

CAFE

Salida

El numero hexadecimal CAFE es 51966 en decimal

### 58 - Decimal a Binario

Escribir un programa que dado un número decimal (base~10~), devuelva el
correspondiente valor en binario (base~2~).

Entrada

254

Salida

El numero 254 en decimal es 11111110 en binario

Para este ejercicio, es necesario definir una operación de concatenación
de caracteres.

### 59 - Decimal a Hexadecimal

Escribir un programa que dado un número decimal (base~10~), devuelva el
correspondiente valor en hexadecimal (base~16~).

Entrada

255

Salida

El numero 255 en decimal es FF en hexadecimal

Para este ejercicio, es necesario definir una operación de concatenación
de caracteres.

### 60 - Conversiones de base

Escribir un programa que dado un número empleando la siguiente notación,
complete todas las otras conversiones.

-   *0bNNNN* → Binario (base~2~)

-   *0cNNNN* → Octal (base~8~)

-   *0dNNNN* → Decimal (base~10~)

-   *0xNNNN* → Hexadecimal (base~16~)

En donde *N* es un dígito válido para esa base numérica.

Entrada

0xC0FFEE

Salida

El valor

hexadecimal: BEEF

es tambien:

binario: 110000001111111111101110

octal: 60177756

decimal: 12648430

### 61 - Conversión general de bases

Convertir un número decimal, a su representación en una base arbitraria,
entre 2 y la cantidad de caracteres alfanuméricos *\[0-9A-Z\]*.







# 101 - Matrices

## 102 - Matrices tradicionales

Comencemos con matrices de números enteros

Implementar funciones para operaciones con matrices de números enteros,
en un solo archivo y en donde las funciones *pueden* retornar un valor
ante los posibles errores que se encuentren.

[Mas información sobre las
operaciones](https://www.matesfacil.com/matrices/resueltos-matrices-suma.html)

### 103 - Mostrar una matriz

Implementar una función que imprima por pantalla una matriz, incluyendo
sus dimensiones.

int producto_escalar(int filas, int columnas, int
matriz\[\]\[columnas\]);

### 104 - Multiplicación por un escalar.

El término **multiplicación escalar** se refiere al producto de un
número real por una matriz. En la multiplicación escalar, cada entrada
en la matriz se multiplica por el escalar dado.

int producto_escalar(int filas, int columnas, int
matriz\[\]\[columnas\], int escalar);

### 105 - Suma de matrices

La suma de matrices, es solo posible con matrices de las mismas
dimensiones, esta operación requiere de un tercer argumento de matriz
para almacenar el resultado.

En la suma de matrices, se toma el elemento en la misma ubicación en
ambas matrices y se suma, para cada uno de ellos.

int suma_matriz(int filas_1, int columnas_1, int
matriz_1\[\]\[columnas_1\],

int filas_2, int columnas_2, int matriz_2\[\]\[columnas_2\],

int filas_r, int columnas_r, int resultado\[\]\[columnas_r\]);

# 106 - Archivos

## 107 - Herramientas

108 - ¿Cómo son los archivos?

La idea es trabajar con archivos que contengan números enteros, uno por
línea, en donde el primer número, es la cantidad de números que contiene
el archivo.

La idea es trabajar con archivos que contengan números enteros, uno por
línea, en donde el primer número, es la cantidad de números que contiene
el archivo.

\$\> cat archivo_numeros.txt

5

3

-5

3

6

3

Usen esta forma de guardar números así podemos intercambiar algoritmos
más adelante.

109 - Para generar números aleatorios

Es necesario contar con estas librerias

#include \<time.h\>

#include \<stdlib.h\>

Y en la función que genera el número en sí:

srand(time(NULL)); // La inicialización, debiera ser llamado una sola
vez.

int random_number = rand() % max + min; // Devuelve un numero aleatorio
entre min y max

(No es la *mejor* forma de generarlo pero si es simple)

### 110 - 111 - es_correcto?

Desarrollar el programa y funciones necesarias para indicar si el
archivo esta en el formato indicado.

Si el primer número realmente indica cuantos números contiene el
archivo.

\$\> ./es_correcto archivo_numeros.txt

Si

\$\> echo \$? 1

### 112 - 113 - esta_ordenado?

Implementar la función *esta_ordenado* que dado un conjunto de números,
indique:

-   Sí está o no ordenado y
-   En qué sentido lo está (ascendente o descendente).

El programa que hace uso de esta función debe de aceptar el nombre de
archivo por línea de comandos y mostrar por pantalla (y retornar el
código de salida)

\$\> ./esta_ordenado archivo_numeros.txt

Si - ascendente

\$\> echo \$? 1

Utilicen como código de retorno, *1* descendente,*0* no ordenado y 2
como ordenado de forma ascendente.

### 114 - 115 - ordena

Aprovechando la funció de ordenamiento del TP2, construyan un programa
que permita cargar y ordenar un archivo con números.

*\$\> ./esta_ordenado archivo_numeros.txt*

*No*

*\$\> ./ordena archivo_numeros.txt asc archivo_ordenado.txt*

*\$\> ./esta_ordenado archivo_ordenado.txt*

*Si - ascendente*

Este es un ejemplo, en el que primero va el archivo de entrada, luego va
el sentido en el que se ordenará y finalmente donde será guardado el
resultado.

### 116 - 117 - generador_lineal

El objetivo de este programa es la generación de archivos con números
enteros consecutivos, en donde el programa debe recibir la cantidad de
números a generar junto al valor inicial y paso.

\$\> ./generador_lineal archivo_numeros.txt 10000 -100 2

Generando archivo_numeros.txt

Con 10000 numeros desde -100 aumentando de a 2

En este ejemplo, se creará el archivo *archivo_numeros.txt* con *10000*
números a partir de *-100* de forma ascendente

El signo de este argumento indica la dirección en la que se generan los
números.

### 118 - 119 - generador_aleatorio

El objetivo de este programa es la generación de archivos con números
enteros al azar, en donde debemos indicar la cantidad de números a
generar junto a su rango (mínimo y máximo)

\$\> ./generador_aleatorio archivo_numeros.txt 10000 -100 100

Generando archivo_numeros.txt

Con 10000 numeros entre -100 y 100

En este ejemplo, se creará el archivo archivo_numeros.txt con 10000
números entre -100 y 100.

# 134 - Estructuras

## 135 - Fracciones

Desarrollar las funciones necesarias para operar con fracciones de
números enteros.

typedef struct fraccion{

int numerador;

int denominador;

} fraccion_t;

Operaciones a implementar:

-   Mostrar una fracción por consola.

-   Suma entre fracciones

-   Multiplicación entre fracciones

-   Suma con un número entero.

El *main* para este ejercicio debe utilizar todas estas operaciones.

Este ejercicio no requiere de la utilización de punteros.

## 136 - División II

Unificar las funciones de división lenta del ejercicio [división
lenta](#1.4.2.División lenta|outline) de forma que la función retorne
una estructura representando los valores posibles.

Mantengan separado lo que 'entra' de lo que sale; dividendo y divisor
por un lado, cociente y resto por otro.

Crear las funciones de soporte necesarias como \'mostrar\'

## 137 - Tiempo

Desarrollar una estructura y funciones que permitan realizar las
siguientes operaciones con tiempo expresado en horas, minutos y
segundos.

-   Crear *tiempo_t*

-   Mostrar *tiempo_t*

-   Sumar dos *tiempo_t*

-   Comparar dos *tiempo_t*, indicando:

> *-1* si el primero es más chico

> *0* si son iguales

> *1* si el primero es más grande

## 138 - 139 - Arreglos II

Reusando lo que ya tenemos sobre este tema, desarrollar una estructura y
funciones de soporte para arreglos, en la que su capacidad y largo están
en una estructura.

(Sí, la capacidad es fija, pero volveremos a este ejercicio en el TP
siguiente en donde la capacidad puede variar).

Funcionalidad a implementar.

-   Cargar

-   Mostrar

-   Fusionar

-   Ordenar

## 140 - 141 - Cadenas Seguras II

Seguimos reutilizando, desarrollar una estructura y las funciones de
soporte para integrar la información de capacidad con las cadenas.

Funcionalidad a implementar.

-   Largo

-   Mostrar (el *%s* no funciona más)

-   Insertar en una posición

-   Copiar una cadena en otra.
