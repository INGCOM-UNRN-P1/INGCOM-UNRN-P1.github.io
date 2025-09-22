---
title: Ejercicios de Arreglos (Estáticos)
short_title: 3. Arreglos
---

Ejercicios para practicar la manipulación de arreglos de tamaño fijo. Un arreglo
es una colección de elementos del mismo tipo almacenados en ubicaciones de
memoria contiguas.

---

## 1: Operaciones Básicas

### 1.1: Carga y Muestra

#### Descripción
Crear dos funciones complementarias para manejar arreglos: una para que el usuario ingrese datos y llene un arreglo, y otra para mostrar el contenido del arreglo de una forma clara y legible.

#### Lógica y Consideraciones
-   **`cargar_arreglo`:**
    -   **Entrada:** Un arreglo y su tamaño.
    -   **Proceso:** Usar un lazo `for` que itere desde 0 hasta `tamaño-1`. En cada iteración, solicitar al usuario un número y almacenarlo en la posición correspondiente del arreglo (`arreglo[i]`).
-   **`mostrar_arreglo`:**
    -   **Entrada:** Un arreglo y su tamaño.
    -   **Proceso:** Usar un lazo `for` para recorrer el arreglo.
    -   **Salida:** Imprimir los elementos de una forma legible, por ejemplo, entre corchetes y separados por comas.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO cargar_arreglo(REF arreglo, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        ESCRIBIR "Ingrese el elemento ", i, ":"
        LEER arreglo[i]
    FIN PARA
FIN PROCEDIMIENTO

PROCEDIMIENTO mostrar_arreglo(arreglo, tamano)
INICIO
    ESCRIBIR "[" SIN SALTO DE LÍNEA
    PARA i DESDE 0 HASTA tamano-1 HACER
        ESCRIBIR arreglo[i]
        SI i < tamano-1 ENTONCES
            ESCRIBIR ", " SIN SALTO DE LÍNEA
        FIN SI
    FIN PARA
    ESCRIBIR "]"
FIN PROCEDIMIENTO
```
:::

### 1.2: Suma

#### Descripción
Calcular la suma de todos los elementos contenidos en un arreglo de números.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Variables:** Se necesita una variable `acumulador` (o `suma`) inicializada en 0.
-   **Proceso:** Recorrer el arreglo con un lazo `for`. En cada iteración, sumar el elemento actual al `acumulador`.
-   **Salida:** La función debe devolver el valor final del `acumulador`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION sumar_arreglo(arreglo, tamano)
VARIABLES:
    suma (tipo de dato del arreglo)
INICIO
    suma = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        suma = suma + arreglo[i]
    FIN PARA
    RETORNAR suma
FIN FUNCION
```
:::

### 1.3: Promedio

#### Descripción
Calcular el valor promedio (media aritmética) de los elementos de un arreglo.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Reutilización:** Se puede reutilizar la función `sumar_arreglo` del ejercicio anterior.
-   **Proceso:**
    1.  Calcular la suma total de los elementos.
    2.  Dividir la suma por el número de elementos (tamaño del arreglo).
-   **Tipos de Datos:** Si la suma y el tamaño son enteros, la división puede ser entera. Para un promedio preciso, es importante convertir al menos uno de los operandos a un tipo de punto flotante antes de la división.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION promedio_arreglo(arreglo, tamano)
VARIABLES:
    suma (tipo de dato del arreglo)
INICIO
    SI tamano == 0 RETORNAR 0

    suma = sumar_arreglo(arreglo, tamano)
    RETORNAR suma / (real)tamano
FIN FUNCION
```

### 1.4: Productoria

#### Descripción
Calcular el producto de todos los elementos de un arreglo.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Variables:** Se necesita un `acumulador` inicializado en 1 (no en 0, ya que cualquier cosa multiplicada por 0 es 0).
-   **Proceso:** Recorrer el arreglo con un lazo `for`. En cada iteración, multiplicar el `acumulador` por el elemento actual.
-   **Caso Especial:** Si el arreglo contiene un 0, el producto final será 0.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION productoria_arreglo(arreglo, tamano)
VARIABLES:
    producto (tipo de dato del arreglo)
INICIO
    producto = 1
    PARA i DESDE 0 HASTA tamano-1 HACER
        producto = producto * arreglo[i]
    FIN PARA
    RETORNAR producto
FIN FUNCION
```
:::
---

## 2: Búsqueda y Estadísticas

### 2.1: Máximo y Mínimo

#### Descripción
Encontrar los valores más grande (máximo) y más pequeño (mínimo) dentro de un arreglo de números.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:**
    1.  Inicializar dos variables, `maximo` y `minimo`, con el valor del primer elemento del arreglo (`arreglo[0]`).
    2.  Recorrer el arreglo con un lazo `for` comenzando desde el segundo elemento (`i=1`).
    3.  En cada iteración, comparar el elemento actual `arreglo[i]` con `maximo`. Si `arreglo[i]` es mayor, actualizar `maximo`.
    4.  Hacer lo mismo para `minimo`, actualizándolo si `arreglo[i]` es menor.
-   **Salida:** Devolver los valores de `maximo` y `minimo` (por ejemplo, usando punteros).

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO encontrar_max_min(arreglo, tamano, REF maximo, REF minimo)
INICIO
    SI tamano == 0 ENTONCES TERMINAR // Arreglo vacío

    maximo = arreglo[0]
    minimo = arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] > maximo ENTONCES
            maximo = arreglo[i]
        FIN SI
        SI arreglo[i] < minimo ENTONCES
            minimo = arreglo[i]
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 2.2: Casi Máximo

#### Descripción
Encontrar el segundo elemento más grande en un arreglo. Este ejercicio requiere un seguimiento más cuidadoso que simplemente encontrar el máximo.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Variables:** Se necesitan dos variables: `maximo` y `segundo_maximo`. Inicializarlas con el menor valor posible o con los dos primeros elementos del arreglo de forma ordenada.
-   **Proceso:**
    1.  Recorrer el arreglo.
    2.  Si el elemento actual `x` es mayor que `maximo`:
        a. `segundo_maximo` toma el valor de `maximo`.
        b. `maximo` toma el valor de `x`.
    3.  Si no, si `x` es mayor que `segundo_maximo` y diferente de `maximo`, se actualiza `segundo_maximo` a `x`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION encontrar_segundo_maximo(arreglo, tamano)
VARIABLES:
    maximo, segundo_maximo
INICIO
    // Inicializar con los dos primeros elementos o valores muy bajos
    maximo = MINIMO_VALOR_POSIBLE
    segundo_maximo = MINIMO_VALOR_POSIBLE

    PARA cada elemento x EN arreglo HACER
        SI x > maximo ENTONCES
            segundo_maximo = maximo
            maximo = x
        SINO SI x > segundo_maximo Y x < maximo ENTONCES
            segundo_maximo = x
        FIN SI
    FIN PARA
    RETORNAR segundo_maximo
FIN FUNCION
```
:::

### 2.3: Búsqueda de Elemento

#### Descripción
Implementar una búsqueda lineal para encontrar la primera ocurrencia de un elemento específico dentro de un arreglo. Si se encuentra, se debe devolver su índice.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y el elemento a buscar.
-   **Proceso:** Recorrer el arreglo con un lazo `for` desde el índice 0.
-   **Condición:** En cada iteración, comparar el elemento actual del arreglo con el elemento buscado. Si son iguales, se ha encontrado.
-   **Salida:** Si se encuentra el elemento, la función debe devolver el índice actual. Si el lazo termina sin encontrar el elemento, se debe devolver un valor especial que indique que no se encontró, como `-1`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION busqueda_lineal(arreglo, tamano, buscado)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] == buscado ENTONCES
            RETORNAR i // Elemento encontrado
        FIN SI
    FIN PARA
    RETORNAR -1 // Elemento no encontrado
FIN FUNCION
```
:::

### 2.4: Contar Repeticiones

#### Descripción
Contar cuántas veces aparece un número específico en un arreglo.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y el elemento a contar.
-   **Variables:** Un `contador` inicializado en 0.
-   **Proceso:** Recorrer el arreglo con un lazo. En cada iteración, si el elemento actual es igual al elemento buscado, incrementar el `contador`.
-   **Salida:** Devolver el valor final del `contador`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION contar_repeticiones(arreglo, tamano, buscado)
VARIABLES:
    contador (entero)
INICIO
    contador = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] == buscado ENTONCES
            contador = contador + 1
        FIN SI
    FIN PARA
    RETORNAR contador
FIN FUNCION
```
:::

### 2.5: Elemento más Cercano

#### Descripción
Dado un arreglo y un valor de referencia, encontrar el elemento en el arreglo que tiene la menor diferencia absoluta con dicho valor.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño y un valor de referencia.
-   **Variables:** Se necesitan variables para guardar la `menor_diferencia` encontrada hasta el momento y el `elemento_mas_cercano`.
-   **Proceso:**
    1.  Inicializar `menor_diferencia` con un valor muy grande y `elemento_mas_cercano` con el primer elemento.
    2.  Recorrer el arreglo. Para cada elemento, calcular la `diferencia_actual` (el valor absoluto de `elemento - referencia`).
    3.  Si `diferencia_actual` es menor que `menor_diferencia`, actualizar `menor_diferencia` y `elemento_mas_cercano`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION encontrar_mas_cercano(arreglo, tamano, referencia)
VARIABLES:
    menor_diferencia, diferencia_actual (reales)
    elemento_cercano (tipo del arreglo)
INICIO
    menor_diferencia = VALOR_INFINITO
    PARA cada elemento x EN arreglo HACER
        diferencia_actual = VALOR_ABSOLUTO(x - referencia)
        SI diferencia_actual < menor_diferencia ENTONCES
            menor_diferencia = diferencia_actual
            elemento_cercano = x
        FIN SI
    FIN PARA
    RETORNAR elemento_cercano
FIN FUNCION
```
:::

---

## 3: Manipulación de Arreglos

### 3.1: Inversión

#### Descripción
Invertir el orden de los elementos de un arreglo _in-place_, es decir, sin usar un segundo arreglo para almacenar el resultado temporalmente.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Utilizar dos índices (o punteros): `inicio` comenzando en 0 y `fin` comenzando en `tamaño-1`.
-   Usar un lazo `while` que se ejecute mientras `inicio < fin`.
-   En cada iteración:
    1.  Intercambiar los elementos en las posiciones `inicio` y `fin`.
    2.  Incrementar `inicio` y decrementar `fin` para moverse hacia el centro del arreglo.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO invertir_arreglo(REF arreglo, tamano)
VARIABLES:
    inicio, fin, temporal (enteros)
INICIO
    inicio = 0
    fin = tamano - 1
    MIENTRAS inicio < fin HACER
        // Intercambiar elementos
        temporal = arreglo[inicio]
        arreglo[inicio] = arreglo[fin]
        arreglo[fin] = temporal

        inicio = inicio + 1
        fin = fin - 1
    FIN MIENTRAS
FIN PROCEDIMIENTO
```
:::

### 3.2: Copia

#### Descripción
Copiar todos los elementos de un arreglo de origen a un arreglo de destino.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo de origen, un arreglo de destino y el tamaño.
-   **Precondición:** El arreglo de destino debe tener suficiente capacidad para albergar todos los elementos del arreglo de origen.
-   **Proceso:** Recorrer el arreglo de origen con un lazo `for` y, en cada iteración, asignar el elemento de origen al elemento correspondiente en el arreglo de destino: `destino[i] = origen[i]`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO copiar_arreglo(origen, REF destino, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        destino[i] = origen[i]
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 3.3: Deduplicación

#### Descripción
Eliminar los elementos duplicados de un arreglo, conservando solo la primera aparición de cada elemento. La función debe modificar el arreglo _in-place_ y devolver el nuevo tamaño lógico.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso (si el orden no importa):** Ordenar el arreglo primero. Luego, recorrerlo con dos punteros (`lectura` y `escritura`). Si el elemento actual es diferente al anterior, se copia a la posición de `escritura` y se avanza `escritura`.
-   **Proceso (si el orden importa):** Usar un lazo anidado o una estructura de datos auxiliar (como un hash set) para llevar un registro de los elementos ya vistos.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION deduplicar_arreglo(REF arreglo, tamano)
INICIO
    SI tamano == 0 RETORNAR 0

    ORDENAR(arreglo, tamano)

    indice_escritura = 1
    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] != arreglo[i-1] ENTONCES
            arreglo[indice_escritura] = arreglo[i]
            indice_escritura = indice_escritura + 1
        FIN SI
    FIN PARA
    RETORNAR indice_escritura
FIN FUNCION
```
:::

---

## 4: Verificación

### 4.1: ¿Está ordenado?

#### Descripción
Verificar si un arreglo está ordenado de forma ascendente.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Recorrer el arreglo desde el primer elemento hasta el penúltimo. En cada posición `i`, comparar el elemento `arreglo[i]` con el siguiente, `arreglo[i+1]`.
-   **Condición de Salida:** Si en algún momento se encuentra que `arreglo[i] > arreglo[i+1]`, el arreglo no está ordenado y la función puede devolver `falso` inmediatamente.
-   **Salida:** Si el lazo termina sin encontrar ninguna inversión de orden, significa que el arreglo está ordenado y la función devuelve `verdadero`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION esta_ordenado(arreglo, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-2 HACER
        SI arreglo[i] > arreglo[i+1] ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION
```
:::

### 4.2: Solo Positivos

#### Descripción
Verificar si todos los elementos de un arreglo son números positivos (mayores que cero).

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo y su tamaño.
-   **Proceso:** Recorrer el arreglo con un lazo.
-   **Condición de Salida:** En cuanto se encuentre un elemento que sea menor o igual a cero, se puede concluir que no todos son positivos y devolver `falso`.
-   **Salida:** Si el lazo se completa sin encontrar ningún número no positivo, devolver `verdadero`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION son_todos_positivos(arreglo, tamano)
INICIO
    PARA cada elemento x EN arreglo HACER
        SI x <= 0 ENTONCES
            RETORNAR FALSO
        FIN SI
    FIN PARA
    RETORNAR VERDADERO
FIN FUNCION
```
:::

---

## 5: Operaciones Avanzadas con Arreglos

### 5.1: Rotación de Arreglo

#### Descripción
Implementar una función que rote los elementos de un arreglo `k` posiciones hacia la derecha. Esto significa que los últimos `k` elementos se moverán al principio del arreglo, y el resto de los elementos se desplazarán hacia la derecha.

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño `n`, y el número de posiciones a rotar `k`.
-   **Proceso (con arreglo auxiliar):**
    1.  Crear un arreglo temporal del mismo tamaño.
    2.  Recorrer el arreglo original. Para cada elemento en la posición `i`, su nueva posición en el arreglo temporal será `(i + k) % n`.
    3.  Copiar el contenido del arreglo temporal de vuelta al original.
-   **Proceso (in-place, más avanzado):**
    1.  Invertir todo el arreglo.
    2.  Invertir los primeros `k` elementos.
    3.  Invertir los `n-k` elementos restantes.
-   **Módulo:** Es útil calcular `k = k % n` al principio, por si `k` es mayor que `n`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO rotar_derecha(REF arreglo, n, k)
VARIABLES:
    temporal (arreglo de tamaño n)
INICIO
    k = k MOD n // Manejar rotaciones mayores que n

    PARA i DESDE 0 HASTA n-1 HACER
        nueva_pos = (i + k) MOD n
        temporal[nueva_pos] = arreglo[i]
    FIN PARA

    // Copiar de vuelta al arreglo original
    PARA i DESDE 0 HASTA n-1 HACER
        arreglo[i] = temporal[i]
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.2: Fusión de Arreglos

#### Descripción
Escribir una función que fusione dos arreglos en un tercer arreglo que contenga todos los elementos de los dos primeros. Si los arreglos originales están ordenados, el resultado también debería estarlo (ver Merge Sort).

#### Lógica y Consideraciones
-   **Entrada:** Dos arreglos (`a1`, `a2`) con sus respectivos tamaños (`n1`, `n2`).
-   **Salida:** Un nuevo arreglo de tamaño `n1 + n2`.
-   **Proceso (desordenado):** Simplemente copiar todos los elementos de `a1` al nuevo arreglo, y luego todos los elementos de `a2` a continuación.
-   **Proceso (ordenado):** Usar el algoritmo de mezcla de Merge Sort. Con tres punteros (`i` para `a1`, `j` para `a2`, `k` para el resultado), comparar `a1[i]` y `a2[j]`, copiar el menor al resultado y avanzar el puntero correspondiente.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocodev
FUNCION fusionar_ordenado(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo de tamaño n1+n2)
    i, j, k (enteros)
INICIO
    i=0, j=0, k=0
    MIENTRAS i < n1 Y j < n2 HACER
        SI a1[i] <= a2[j] ENTONCES
            resultado[k] = a1[i]
            i = i + 1
        SINO
            resultado[k] = a2[j]
            j = j + 1
        FIN SI
        k = k + 1
    FIN MIENTRAS

    // Copiar elementos restantes
    MIENTRAS i < n1 HACER
        resultado[k] = a1[i]
        i = i + 1, k = k + 1
    FIN MIENTRAS
    MIENTRAS j < n2 HACER
        resultado[k] = a2[j]
        j = j + 1, k = k + 1
    FIN MIENTRAS

    RETORNAR resultado
FIN FUNCION
```
:::

### 5.3: Intersección de Arreglos

#### Descripción
Crear una función que reciba dos arreglos y devuelva un nuevo arreglo con los elementos que son comunes a ambos. Cada elemento debe aparecer solo una vez en el resultado.

#### Lógica y Consideraciones
-   **Entrada:** Dos arreglos y sus tamaños.
-   **Proceso (con arreglos ordenados):** Usar dos punteros, uno para cada arreglo. Si los elementos son iguales, se añade al resultado y se avanzan ambos punteros. Si son diferentes, se avanza el puntero del arreglo que tenga el elemento más pequeño.
-   **Proceso (con arreglos desordenados):** Usar lazos anidados. Para cada elemento del primer arreglo, buscar si existe en el segundo. Para evitar duplicados en el resultado, se puede usar una estructura de datos auxiliar (hash set) o verificar si el elemento ya fue añadido.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION interseccion(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
    i, j (enteros)
INICIO
    i=0, j=0
    MIENTRAS i < n1 Y j < n2 HACER
        SI a1[i] < a2[j] ENTONCES
            i = i + 1
        SINO SI a2[j] < a1[i] ENTONCES
            j = j + 1
        SINO // Son iguales
            AÑADIR a1[i] a resultado (si no está ya)
            i = i + 1, j = j + 1
        FIN SI
    FIN MIENTRAS
    RETORNAR resultado
FIN FUNCION
```
:::

### 5.4: Unión de Arreglos

#### Descripción
Crear una función que reciba dos arreglos y devuelva un nuevo arreglo con todos los elementos de ambos, sin duplicados.

#### Lógica y Consideraciones
-   **Proceso:**
    1.  Copiar el primer arreglo a un arreglo de resultado temporal.
    2.  Recorrer el segundo arreglo. Para cada elemento, verificar si ya existe en el resultado temporal.
    3.  Si no existe, añadirlo.
-   **Optimización:** Usar una tabla hash para llevar un registro de los elementos ya añadidos mejora la eficiencia de la búsqueda.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION union_arreglos(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
    // Usar una tabla hash o similar para eficiencia
    elementos_vistos (conjunto)
INICIO
    PARA cada elemento x en a1 HACER
        AÑADIR x a resultado
        AÑADIR x a elementos_vistos
    FIN PARA
    PARA cada elemento y en a2 HACER
        SI y NO ESTÁ EN elementos_vistos ENTONCES
            AÑADIR y a resultado
            AÑADIR y a elementos_vistos
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION
```
:::

### 5.5: Separar Pares e Impares

#### Descripción
Reorganizar un arreglo _in-place_ de tal manera que todos los números pares queden al principio y todos los impares al final. El orden relativo entre los números pares o entre los impares no necesita conservarse.

#### Lógica y Consideraciones
-   **Proceso (dos punteros):**
    1.  Usar dos índices, `izquierda` comenzando en 0 y `derecha` en `tamaño-1`.
    2.  Mientras `izquierda < derecha`:
        a. Mover `izquierda` hacia la derecha hasta encontrar un número impar.
        b. Mover `derecha` hacia la izquierda hasta encontrar un número par.
        c. Si `izquierda < derecha`, intercambiar los elementos en esas posiciones.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO separar_pares_impares(REF arreglo, tamano)
VARIABLES:
    izquierda, derecha (enteros)
INICIO
    izquierda = 0, derecha = tamano - 1
    MIENTRAS izquierda < derecha HACER
        MIENTRAS arreglo[izquierda] MOD 2 == 0 Y izquierda < derecha HACER
            izquierda = izquierda + 1
        FIN MIENTRAS
        MIENTRAS arreglo[derecha] MOD 2 != 0 Y izquierda < derecha HACER
            derecha = derecha - 1
        FIN MIENTRAS

        SI izquierda < derecha ENTONCES
            INTERCAMBIAR(arreglo[izquierda], arreglo[derecha])
            izquierda = izquierda + 1
            derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
FIN PROCEDIMIENTO
```
:::

### 5.6: Algoritmo de Kadane (Suma Máxima de Subarreglo)

#### Descripción
Implementar el algoritmo de Kadane para encontrar la suma del subarreglo contiguo que tenga la suma más grande. El arreglo puede contener números negativos.

#### Lógica y Consideraciones
-   **Proceso:** Se recorre el arreglo una sola vez, manteniendo dos variables:
    -   `max_actual`: La suma máxima del subarreglo que termina en la posición actual.
    -   `max_global`: La suma máxima encontrada en todo el arreglo hasta el momento.
-   En cada paso `i`:
    1.  `max_actual = MAXIMO(arreglo[i], max_actual + arreglo[i])`
    2.  `max_global = MAXIMO(max_global, max_actual)`

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION kadane(arreglo, tamano)
VARIABLES:
    max_actual, max_global
INICIO
    max_actual = arreglo[0]
    max_global = arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        max_actual = MAXIMO(arreglo[i], max_actual + arreglo[i])
        SI max_actual > max_global ENTONCES
            max_global = max_actual
        FIN SI
    FIN PARA
    RETORNAR max_global
FIN FUNCION
```
:::

### 5.7: Histograma

#### Descripción
Dado un arreglo de enteros no negativos, el programa debe imprimir un histograma simple usando asteriscos, donde cada número `n` se representa con una línea de `n` asteriscos.

#### Lógica y Consideraciones
-   **Proceso:** Usar lazos anidados.
    1.  El lazo exterior recorre cada elemento del arreglo.
    2.  El lazo interior se ejecuta tantas veces como el valor del elemento actual, imprimiendo un asterisco en cada una de sus iteraciones.
    3.  Después del lazo interior, se imprime un salto de línea.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO imprimir_histograma(arreglo, tamano)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        ESCRIBIR i, ": " SIN SALTO DE LÍNEA
        PARA j DESDE 1 HASTA arreglo[i] HACER
            ESCRIBIR "*" SIN SALTO DE LÍNEA
        FIN PARA
        ESCRIBIR SALTO DE LÍNEA
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.8: Barajar Arreglo (Fisher-Yates)

#### Descripción
Implementar el algoritmo de Fisher-Yates para barajar (desordenar aleatoriamente) los elementos de un arreglo _in-place_.

#### Lógica y Consideraciones
-   **Proceso:**
    1.  Recorrer el arreglo desde el último elemento hasta el segundo (`i` desde `n-1` hasta 1).
    2.  En cada iteración, generar un índice aleatorio `j` entre 0 e `i` (inclusive).
    3.  Intercambiar el elemento en la posición `i` con el elemento en la posición `j`.
-   **Aleatoriedad:** Requiere `srand()` y `rand()`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO barajar_fisher_yates(REF arreglo, tamano)
VARIABLES:
    j, temporal (enteros)
INICIO
    PARA i DESDE tamano-1 HASTA 1 CON PASO -1 HACER
        j = generar_aleatorio(0, i)
        INTERCAMBIAR(arreglo[i], arreglo[j])
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.9: Encontrar Elemento Faltante

#### Descripción
Dado un arreglo que contiene `n-1` números distintos en el rango de 1 a `n`, encontrar el único número que falta.

#### Lógica y Consideraciones
-   **Proceso (Suma):**
    1.  Calcular la suma esperada de todos los números de 1 a `n` usando la fórmula de la progresión aritmética: `suma_esperada = n * (n + 1) / 2`.
    2.  Calcular la suma real de los elementos en el arreglo dado.
    3.  El número faltante es la diferencia: `suma_esperada - suma_real`.
-   **Proceso (XOR):** El XOR de todos los números del rango con todos los números del arreglo dará como resultado el número faltante.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
```pseudocode
FUNCION encontrar_faltante(arreglo, tamano_actual)
VARIABLES:
    n, suma_esperada, suma_real (enteros)
INICIO
    n = tamano_actual + 1
    suma_esperada = n * (n + 1) / 2
    suma_real = sumar_arreglo(arreglo, tamano_actual)
    RETORNAR suma_esperada - suma_real
FIN FUNCION
```
:::

### 5.10: Encontrar Par con Suma X

#### Descripción
Dado un arreglo de números y un valor `X`, determinar si existe un par de elementos en el arreglo cuya suma sea exactamente `X`.

#### Lógica y Consideraciones
-   **Proceso (Ordenando):**
    1.  Ordenar el arreglo.
    2.  Usar dos punteros: `izquierda` en el inicio y `derecha` en el final.
    3.  Mientras `izquierda < derecha`:
        a. Calcular la suma `s = arreglo[izquierda] + arreglo[derecha]`.
        b. Si `s == X`, se encontró el par.
        c. Si `s < X`, se necesita una suma mayor, así que se mueve `izquierda` a la derecha.
        d. Si `s > X`, se necesita una suma menor, así que se mueve `derecha` a la izquierda.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION existe_par_con_suma(arreglo, tamano, X)
VARIABLES:
    izquierda, derecha, suma (enteros)
INICIO
    ORDENAR(arreglo, tamano)
    izquierda = 0, derecha = tamano - 1

    MIENTRAS izquierda < derecha HACER
        suma = arreglo[izquierda] + arreglo[derecha]
        SI suma == X ENTONCES
            RETORNAR VERDADERO
        SINO SI suma < X ENTONCES
            izquierda = izquierda + 1
        SINO
            derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
    RETORNAR FALSO
FIN FUNCION
```
:::

### 5.11: Mediana de un Arreglo

#### Descripción
Calcular la mediana de un arreglo. La mediana es el valor que se encuentra en la posición central de un arreglo ordenado. Si el arreglo tiene un número par de elementos, la mediana es el promedio de los dos elementos centrales.

#### Lógica y Consideraciones
-   **Proceso:**
    1.  Ordenar el arreglo.
    2.  Determinar el índice del medio: `medio = tamano / 2`.
    3.  Si el tamaño es impar, la mediana es `arreglo[medio]`.
    4.  Si el tamaño es par, la mediana es `(arreglo[medio - 1] + arreglo[medio]) / 2.0`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION calcular_mediana(arreglo, tamano)
INICIO
    ORDENAR(arreglo, tamano)
    SI tamano MOD 2 != 0 ENTONCES
        RETORNAR arreglo[tamano / 2]
    SINO
        RETORNAR (arreglo[tamano/2 - 1] + arreglo[tamano/2]) / 2.0
    FIN SI
FIN FUNCION
```
:::

### 5.12: Moda de un Arreglo

#### Descripción
Encontrar la moda de un arreglo, que es el elemento que aparece con mayor frecuencia.

#### Lógica y Consideraciones
-   **Proceso (con ordenamiento):**
    1.  Ordenar el arreglo. Esto agrupa los elementos iguales.
    2.  Recorrer el arreglo y contar la longitud de cada secuencia de elementos idénticos.
    3.  Llevar un registro del elemento con la frecuencia más alta encontrada hasta el momento.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION encontrar_moda(arreglo, tamano)
VARIABLES:
    moda, max_frecuencia, frec_actual, elemento_actual
INICIO
    ORDENAR(arreglo, tamano)
    moda = arreglo[0], max_frecuencia = 1, frec_actual = 1

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI arreglo[i] == arreglo[i-1] ENTONCES
            frec_actual = frec_actual + 1
        SINO
            frec_actual = 1
        FIN SI
        SI frec_actual > max_frecuencia ENTONCES
            max_frecuencia = frec_actual
            moda = arreglo[i]
        FIN SI
    FIN PARA
    RETORNAR moda
FIN FUNCION
```
:::

### 5.13: Rellenar con Secuencia Aritmética

#### Descripción
Escribir una función que llene un arreglo con los términos de una secuencia aritmética, dados un valor de inicio, un tamaño y un paso (la diferencia constante entre términos).

#### Lógica y Consideraciones
-   **Entrada:** Un arreglo, su tamaño, un valor de `inicio` y un `paso`.
-   **Proceso:** Recorrer el arreglo con un lazo `for`. Para cada índice `i`, el valor a asignar es `inicio + (i * paso)`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO rellenar_secuencia(REF arreglo, tamano, inicio, paso)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        arreglo[i] = inicio + (i * paso)
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 5.14: Diferencia Simétrica

#### Descripción
Calcular la diferencia simétrica entre dos arreglos. El resultado debe ser un nuevo arreglo que contenga los elementos que están en uno de los arreglos, pero no en ambos.

#### Lógica y Consideraciones
-   **Proceso:**
    1.  Iterar sobre el primer arreglo. Para cada elemento, verificar si está en el segundo. Si NO está, añadirlo al resultado.
    2.  Iterar sobre el segundo arreglo. Para cada elemento, verificar si está en el primero. Si NO está, añadirlo al resultado.
-   **Optimización:** Usar tablas hash para las búsquedas puede hacer el proceso mucho más eficiente.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION diferencia_simetrica(a1, n1, a2, n2)
VARIABLES:
    resultado (arreglo)
INICIO
    PARA cada elemento x en a1 HACER
        SI x NO ESTÁ EN a2 ENTONCES
            AÑADIR x a resultado
        FIN SI
    FIN PARA
    PARA cada elemento y en a2 HACER
        SI y NO ESTÁ EN a1 ENTONCES
            AÑADIR y a resultado
        FIN SI
    FIN PARA
    RETORNAR resultado
FIN FUNCION
```
:::

### 5.15: Conteo de Inversiones

#### Descripción
Contar el número de "inversiones" en un arreglo. Una inversión es un par de índices `(i, j)` tales que `i < j` y `arr[i] > arr[j]`. Un arreglo perfectamente ordenado tiene 0 inversiones.

#### Lógica y Consideraciones
-   **Proceso (Fuerza Bruta):** Usar dos lazos anidados. El lazo exterior itera con `i` desde 0 hasta `n-2`. El lazo interior itera con `j` desde `i+1` hasta `n-1`. Si `arreglo[i] > arreglo[j]`, se incrementa un contador.
-   **Complejidad:** La solución de fuerza bruta es O(n^2). Existen algoritmos más eficientes basados en Merge Sort.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION contar_inversiones(arreglo, tamano)
VARIABLES:
    contador (entero)
INICIO
    contador = 0
    PARA i DESDE 0 HASTA tamano-2 HACER
        PARA j DESDE i+1 HASTA tamano-1 HACER
            SI arreglo[i] > arreglo[j] ENTONCES
                contador = contador + 1
            FIN SI
        FIN PARA
    FIN PARA
    RETORNAR contador
FIN FUNCION
```
:::

---

## 6: Más Manipulación de Arreglos

### 6.1: Picos y Valles

#### Descripción
Escribir una función que encuentre todos los "picos" en un arreglo. Un pico es un elemento que es estrictamente mayor que sus dos vecinos (el anterior y el siguiente). Los elementos en los extremos no pueden ser picos.

#### Lógica y Consideraciones
-   **Proceso:** Recorrer el arreglo desde el segundo elemento (`i=1`) hasta el penúltimo (`i=n-2`).
-   **Condición:** En cada posición `i`, verificar si `arreglo[i] > arreglo[i-1]` Y `arreglo[i] > arreglo[i+1]`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO encontrar_picos(arreglo, tamano)
INICIO
    PARA i DESDE 1 HASTA tamano-2 HACER
        SI arreglo[i] > arreglo[i-1] Y arreglo[i] > arreglo[i+1] ENTONCES
            ESCRIBIR arreglo[i], " es un pico en el índice ", i
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 6.2: Subarreglo Más Largo con Suma Cero

#### Descripción
Dado un arreglo de enteros (positivos y negativos), encontrar la longitud del subarreglo contiguo más largo cuya suma de elementos sea cero.

#### Lógica y Consideraciones
-   **Proceso (Tabla Hash):**
    1.  Usar una tabla hash para almacenar las sumas acumuladas y sus primeros índices de aparición.
    2.  Recorrer el arreglo, manteniendo una `suma_actual`.
    3.  Si `suma_actual` ya se ha visto antes en el índice `j`, entonces el subarreglo desde `j+1` hasta la posición actual tiene suma cero. Calcular su longitud y actualizar la longitud máxima.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION subarreglo_suma_cero(arreglo, tamano)
VARIABLES:
    mapa_sumas (tabla hash)
    suma, max_longitud (enteros)
INICIO
    suma = 0, max_longitud = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        suma = suma + arreglo[i]
        SI suma == 0 ENTONCES
            max_longitud = i + 1
        SINO SI mapa_sumas CONTIENE suma ENTONCES
            max_longitud = MAXIMO(max_longitud, i - mapa_sumas[suma])
        SINO
            mapa_sumas[suma] = i
        FIN SI
    FIN PARA
    RETORNAR max_longitud
FIN FUNCION
```
:::

### 6.3: Reorganizar Positivos y Negativos

#### Descripción
Reorganizar un arreglo _in-place_ de tal manera que todos los números negativos aparezcan antes que todos los números positivos. El orden relativo entre los números del mismo signo no es importante.

#### Lógica y Consideraciones
-   **Proceso (similar a separar pares/impares):** Usar dos punteros, `izquierda` y `derecha`. Mover `izquierda` hasta encontrar un número positivo y `derecha` hasta encontrar uno negativo. Luego, intercambiarlos y continuar hasta que los punteros se crucen.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO reorganizar_signos(REF arreglo, tamano)
VARIABLES:
    izquierda, derecha (enteros)
INICIO
    izquierda = 0, derecha = tamano - 1
    MIENTRAS izquierda <= derecha HACER
        SI arreglo[izquierda] < 0 Y arreglo[derecha] < 0 ENTONCES
            izquierda = izquierda + 1
        SINO SI arreglo[izquierda] > 0 Y arreglo[derecha] < 0 ENTONCES
            INTERCAMBIAR(arreglo[izquierda], arreglo[derecha])
            izquierda = izquierda + 1, derecha = derecha - 1
        SINO SI arreglo[izquierda] > 0 Y arreglo[derecha] > 0 ENTONCES
            derecha = derecha - 1
        SINO
            izquierda = izquierda + 1, derecha = derecha - 1
        FIN SI
    FIN MIENTRAS
FIN PROCEDIMIENTO
```
:::

### 6.4: Producto de los Demás Elementos

#### Descripción
Dado un arreglo de números, crear un nuevo arreglo donde cada elemento en la posición `i` sea el producto de todos los demás números del arreglo original, pero sin usar el operador de división.

#### Lógica y Consideraciones
-   **Proceso (dos pasadas):**
    1.  Crear un arreglo `resultado`.
    2.  **Primera pasada (izquierda a derecha):** Recorrer el arreglo. Para cada `i`, `resultado[i]` será el producto de todos los elementos a su izquierda. Mantener un acumulador `izquierda_prod`.
    3.  **Segunda pasada (derecha a izquierda):** Recorrer el arreglo al revés. Mantener un acumulador `derecha_prod`. Multiplicar `resultado[i]` por `derecha_prod` para incorporar los productos de la derecha.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION producto_de_los_demas(arreglo, tamano)
VARIABLES:
    resultado (arreglo de tamaño n)
    izquierda_prod, derecha_prod
INICIO
    izquierda_prod = 1
    PARA i DESDE 0 HASTA tamano-1 HACER
        resultado[i] = izquierda_prod
        izquierda_prod = izquierda_prod * arreglo[i]
    FIN PARA

    derecha_prod = 1
    PARA i DESDE tamano-1 HASTA 0 CON PASO -1 HACER
        resultado[i] = resultado[i] * derecha_prod
        derecha_prod = derecha_prod * arreglo[i]
    FIN PARA

    RETORNAR resultado
FIN FUNCION
```
:::

### 6.5: Arreglo de Frecuencias

#### Descripción
Dado un arreglo de enteros que contiene números en un rango conocido (por ejemplo, de 0 a 99), crear un "arreglo de frecuencias" que cuente cuántas veces aparece cada número.

#### Lógica y Consideraciones
-   **Proceso:**
    1.  Crear un nuevo arreglo `frecuencias` del tamaño del rango (ej. 100), inicializado todo en 0.
    2.  Recorrer el arreglo de entrada. Para cada número `x`, usarlo como índice en el arreglo de frecuencias e incrementar la cuenta: `frecuencias[x]++`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION calcular_frecuencias(arreglo, tamano, rango_max)
VARIABLES:
    frecuencias (arreglo de tamaño rango_max, inicializado en 0)
INICIO
    PARA i DESDE 0 HASTA tamano-1 HACER
        numero = arreglo[i]
        frecuencias[numero] = frecuencias[numero] + 1
    FIN PARA
    RETORNAR frecuencias
FIN FUNCION
```
:::

### 6.6: ¿Es Subconjunto?

#### Descripción
Implementar una función que determine si un arreglo `A` es un subconjunto de otro arreglo `B`. Esto significa que todos los elementos de `A` deben estar presentes en `B`.

#### Lógica y Consideraciones
-   **Proceso (con ordenamiento):**
    1.  Ordenar ambos arreglos, `A` y `B`.
    2.  Usar dos punteros, `i` para `A` y `j` para `B`.
    3.  Recorrer ambos arreglos. Si `A[i] == B[j]`, se encontró una coincidencia, avanzar ambos. Si `A[i] > B[j]`, avanzar `j`. Si `A[i] < B[j]`, significa que `A[i]` no está en `B`, por lo que no es subconjunto.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION es_subconjunto(A, nA, B, nB)
VARIABLES:
    i, j (enteros)
INICIO
    ORDENAR(A, nA)
    ORDENAR(B, nB)
    i = 0, j = 0
    MIENTRAS i < nA Y j < nB HACER
        SI A[i] > B[j] ENTONCES
            j = j + 1
        SINO SI A[i] == B[j] ENTONCES
            i = i + 1, j = j + 1
        SINO // A[i] < B[j]
            RETORNAR FALSO
        FIN SI
    FIN MIENTRAS

    RETORNAR (i == nA)
FIN FUNCION
```
:::

### 6.7: Mover Ceros al Final

#### Descripción
Escribir una función que mueva todos los ceros de un arreglo al final del mismo, manteniendo el orden relativo de los elementos no nulos.

#### Lógica y Consideraciones
-   **Proceso (un solo recorrido):**
    1.  Usar un índice `posicion_no_cero` inicializado en 0.
    2.  Recorrer el arreglo. Si el elemento actual no es cero, se coloca en la posición `posicion_no_cero` y se incrementa `posicion_no_cero`.
    3.  Después del primer lazo, todos los elementos no nulos están al principio en su orden original. Llenar el resto del arreglo con ceros.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO mover_ceros_final(REF arreglo, tamano)
VARIABLES:
    posicion_no_cero (entero)
INICIO
    posicion_no_cero = 0
    PARA i DESDE 0 HASTA tamano-1 HACER
        SI arreglo[i] != 0 ENTONCES
            arreglo[posicion_no_cero] = arreglo[i]
            posicion_no_cero = posicion_no_cero + 1
        FIN SI
    FIN PARA

    PARA i DESDE posicion_no_cero HASTA tamano-1 HACER
        arreglo[i] = 0
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 6.8: Líderes en un Arreglo

#### Descripción
Encontrar todos los "líderes" en un arreglo. Un elemento es un líder si es mayor que todos los elementos que se encuentran a su derecha. El elemento más a la derecha siempre es un líder.

#### Lógica y Consideraciones
-   **Proceso (recorrido inverso):** La forma más eficiente es recorrer el arreglo de derecha a izquierda.
    1.  El último elemento siempre es un líder. Guardarlo como `maximo_derecha`.
    2.  Iterar desde el penúltimo elemento hacia el principio.
    3.  Si el elemento actual es mayor que `maximo_derecha`, es un nuevo líder. Imprimirlo y actualizar `maximo_derecha`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
PROCEDIMIENTO encontrar_lideres(arreglo, tamano)
VARIABLES:
    maximo_derecha (entero)
INICIO
    maximo_derecha = arreglo[tamano-1]
    ESCRIBIR maximo_derecha

    PARA i DESDE tamano-2 HASTA 0 CON PASO -1 HACER
        SI arreglo[i] > maximo_derecha ENTONCES
            maximo_derecha = arreglo[i]
            ESCRIBIR maximo_derecha
        FIN SI
    FIN PARA
FIN PROCEDIMIENTO
```
:::

### 6.9: Máxima Diferencia

#### Descripción
Encontrar la máxima diferencia `arr[j] - arr[i]` en un arreglo, con la condición de que el índice `j` sea mayor que el índice `i`.

#### Lógica y Consideraciones
-   **Proceso (un solo recorrido):**
    1.  Mantener dos variables: `max_diferencia` y `min_elemento`.
    2.  Inicializar `max_diferencia` a un valor muy bajo y `min_elemento` con el primer elemento.
    3.  Recorrer el arreglo desde el segundo elemento. En cada paso:
        a. Actualizar `max_diferencia` si `elemento_actual - min_elemento` es mayor.
        b. Actualizar `min_elemento` si `elemento_actual` es menor.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION max_diferencia(arreglo, tamano)
VARIABLES:
    max_diferencia, min_elemento
INICIO
    min_elemento = arreglo[0]
    max_diferencia = arreglo[1] - arreglo[0]

    PARA i DESDE 1 HASTA tamano-1 HACER
        SI (arreglo[i] - min_elemento) > max_diferencia ENTONCES
            max_diferencia = arreglo[i] - min_elemento
        FIN SI
        SI arreglo[i] < min_elemento ENTONCES
            min_elemento = arreglo[i]
        FIN SI
    FIN PARA
    RETORNAR max_diferencia
FIN FUNCION
```
:::

### 6.10: Punto de Equilibrio

#### Descripción
Encontrar un "punto de equilibrio" en un arreglo. Es un índice tal que la suma de los elementos a su izquierda es igual a la suma de los elementos a su derecha. Si no existe, devolver -1.

#### Lógica y Consideraciones
-   **Proceso (dos pasadas):**
    1.  Calcular la suma total de todos los elementos del arreglo.
    2.  Inicializar `suma_izquierda = 0`.
    3.  Recorrer el arreglo. En cada posición `i`:
        a. `suma_derecha = suma_total - suma_izquierda - arreglo[i]`.
        b. Si `suma_izquierda == suma_derecha`, se encontró el punto.
        c. Actualizar `suma_izquierda = suma_izquierda + arreglo[i]`.

:::{tip} Ayuda (pseudocódigo)
:class: dropdown
```{code-block} pseudocode
FUNCION encontrar_equilibrio(arreglo, tamano)
VARIABLES:
    suma_total, suma_izquierda
INICIO
    suma_total = sumar_arreglo(arreglo, tamano)
    suma_izquierda = 0

    PARA i DESDE 0 HASTA tamano-1 HACER
        suma_total = suma_total - arreglo[i]
        SI suma_izquierda == suma_total ENTONCES
            RETORNAR i
        FIN SI
        suma_izquierda = suma_izquierda + arreglo[i]
    FIN PARA

    RETORNAR -1
FIN FUNCION
```
:::
