# 90 - Punteros

### 91 - Ordenamiento II

Implementar una función que, en el ordenamiento de arreglos de números
enteros, haga uso de la función.

void intercambia(int\* izquierda, int\* derecha);

Para hacer los movimientos de los valores en el arreglo en lugar de
hacer las asignaciones entre las posiciones.

### 92 - Duplica

Duplicar el valor de una variable usando punteros

### 93 - División lenta II

Implementar una única función que obtenga el cociente y resto de dos
números enteros.

### 94 - Estadísticas

Implementar una única función que obtenga el mínimo, máximo, suma y
promedio de un arreglo.

### 95 - Intercambio de caracteres

Intercambiar dos caracteres en una misma cadena segura.

int intercambia(char cadena\[\], int capacidad_cadena, int origen, int
destino);

### 96 - Largo seguro II

Encontrar la longitud de una cadena segura empleando aritmética de
punteros y sin usar el operador de arreglos *\[\]*.

int largo_seguro(char \*str, int capacidad_cadena);

### 97 - Búsqueda

Implementar una función que retorne el puntero relativo a una cadena
segura, en donde se encuentre la primera ocurrencia de una segunda.

Retornen *NULL* si no se encuentra.

char\* busqueda(char cadena\[\], int capacidad_cadena, char
busqueda\[\], int capacidad_busqueda);

### 98 - Elimina duplicados

Implementar una función que elimine los duplicados de un arreglo,
retornando el nuevo tamaño.

### 99 - Reemplazo

Implementar una función que reemplace las vocales de una cadena segura
reemplazándolas por un carácter indicado.

### 100 - Inversión

Invertir el orden de los elementos presentes en un arreglo

int invertir(int arreglo\[\], int tamaño);

# 120 - Memoria Dinámica

## 121 - Arreglos II

### 122 - Dinámico

Implementa funciones que reserven memoria para un arreglo de enteros de
tamaño fijo y luego otra función para liberarla esa memoria.

int\* reserva_arreglo_enteros(int tamano);

void libera_arreglo_enteros(int\* arreglo);

### 123 - Duplicadora

Escribe una función que copie un arreglo de enteros en un nuevo arreglo
dinámico del mismo tamaño.

int\* duplica_arreglo(int\* origen, int tamano);

### 124 - Eliminadora

Crea una función que elimine un elemento en una posición específica de
un arreglo dinámico de enteros.

int\* elimina_elemento(int\* arreglo, int tamano, int posicion);

### 125 - Inserción

Escribe una función que inserte un elemento en una posición específica
de un arreglo dinámico de enteros.

int\* inserta_elemento(int\* arreglo, int\* tamano, int posicion, int
valor);

### 126 - Fusionadora

Escribe una función que realice la fusión (merge) de dos arreglos
dinámicos ordenados en orden ascendente.

int\* fusiona_arreglos(int\* arreglo1, int tamano1, int\* arreglo2, int
tamano2);

## 127 - Cadenas II

### 128 - Concatenación dinámica

Crea una función que concatene dos cadenas de caracteres dinámicas.

char\* concatena_cadenas(char\* cadena1, char\* cadena2);

### 129 - Deduplicador

Escribe una función que elimine los caracteres duplicados de una cadena.

int\* elimina_duplicados(int\* arreglo, int\* tamano);

### 130 - Fraccionador (Dificil)

Implementa una función que divida una cadena de caracteres en palabras,
separando por espacios *\' \'* y devuelva un arreglo dinámico de
palabras.

char\*\* divide_cadena_en_palabras(char\* cadena, int\* num_palabras);

## 131 - Matrices II

### 132 - Dinámico

Crea una función que reserve memoria para una matriz de enteros de
tamaño *m* x *n*.

int\*\* reserva_matriz_enteros(int filas, int columnas);

void libera_matriz_enteros(int\*\* matriz, int filas, int columnas);

### 133 - Multiplicación de matrices

Crea una función que multiplique dos matrices dinámicas.

int\*\* multiplica_matrices(int\*\* matriz1, int filas1, int columnas1,

int\*\* matriz2, int filas2, int columnas2);

