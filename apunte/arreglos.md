---
title: Arreglos
short_title: 5 - Arreglos
subtitle: Conjuntos de datos.
---

## Arreglos en C

### ¿Qué es un arreglo?

Un arreglo es una colección de elementos del mismo tipo, almacenados en
ubicaciones de memoria **contiguas**. Es una estructura muy útil para almacenar
datos homogéneos y acceder a ellos mediante índices.

```c
int arreglo[8]; // 8 enteros consecutivos
```

### Tamaños y memoria

```c
sizeof(arreglo[0]); // Tamaño del primer elemento
sizeof(arreglo);    // Tamaño total del arreglo
```

Estos tamaños dependen del tipo de datos (por ejemplo, `int` ocupa típicamente 4
bytes).

### Inicialización

La inicialización define los valores que los elementos tendrán al comienzo del
programa. Puede hacerse de forma completa, parcial o implícita:

- Completa, se indica el tamaño y el contenido de todas las posiciones.
- Parcial, se indica un tamaño y el contenido para los primeros elementos,
  rellenando el resto con ceros.
- Sin inicialización, el contenido indeterminado.

Esto afecta directamente la fiabilidad del programa.

```c
int completa[5] = {1, 2, 3, 4, 5};   // [1, 2, 3, 4, 5]
int parcial[5] = {1, 2};             // [1, 2, 0, 0, 0]
int implicita[] = {1, 2, 3};         // [1, 2, 3]
```

### Arreglos como argumentos de funciones

```c
void imprimirArreglo(int arreglo[], int size) {
    // Cuidado: sizeof(arreglo) no da el tamaño total real
}
```

## Funciones puras y control de efectos en C

Cuando se trabaja con funciones que operan sobre arreglos, es fundamental
distinguir entre **funciones puras** y **funciones con efectos secundarios**.
Esta diferenciación permite mejorar la legibilidad del código, facilitar la
depuración y promover una programación más confiable.

### ¿Qué es una función pura?

Una **función pura** es aquella que:

1. **No modifica** ningún estado externo (ni variables globales, ni parámetros
   de entrada).
2. **Siempre retorna el mismo resultado** ante los mismos argumentos.

En otras palabras, su ejecución es predecible y no depende del contexto.

Ejemplo de función pura:

```c
int maximo(int valores[], int cantidad) {
    int max = valores[0];
    for (int i = 1; i < cantidad; i++) {
        if (valores[i] > max) {
            max = valores[i];
        }
    }
    return max;
}
```

Esta función sólo **lee** el contenido del arreglo y **devuelve** un resultado.
No altera el contenido original.

### ¿Qué es una función con efectos secundarios?

Una **función con efectos secundarios** es aquella que **modifica** el estado
del programa más allá de sus variables locales: puede cambiar variables
externas, parámetros pasados por referencia, escribir en pantalla, leer entrada,
etc.

Ejemplo:

```c
void ordenar(int v[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
```

Esta función cambia el contenido del arreglo original: su ejecución **no es
inocua**.

### ¿Por qué distinguirlas?

- **Legibilidad**: un lector puede asumir que una función pura no altera nada,
  lo que simplifica su comprensión.
- **Reutilización**: las funciones puras son más fáciles de testear y componer.
- **Depuración**: los errores son más fáciles de rastrear si las funciones
  tienen efectos bien delimitados.

### Buenas prácticas

- Usá funciones puras para cálculo, conteo o análisis.
- Reservá funciones con efectos para inicialización, transformación explícita o
  interacción con el entorno.
- Documentá claramente qué efectos tiene cada función.
- Cuando una función modifica su entrada, elegí un nombre que lo indique:
  `normalizar`, `ordenar`, `ajustar`, etc.

### Estrategia mixta

En algunos casos, puede ser útil definir **una función pura** que calcule un
resultado y **otra función con efectos** que lo aplique.

Por ejemplo:

```c
int encontrar_maximo(int v[], int cantidad);
void imprimir_maximo(int v[], int cantidad) {
    int m = encontrar_maximo(v, cantidad);
    printf("El máximo es %d\n", m);
}
```

Esta separación permite testear `encontrar_maximo` independientemente de la
función que interactúa con el usuario.

La claridad y la mantenibilidad del código aumentan significativamente cuando
los efectos secundarios están acotados. En C, donde el lenguaje permite
modificar estructuras con facilidad, es responsabilidad del programador decidir
cuándo hacerlo y comunicarlo de manera explícita.

---

## Proceso de compilación

Cuando escribimos:

```sh
$> gcc -o binario programa.c
```

Estamos realizando múltiples pasos que el compilador automatiza:
**preprocesado**, **compilación**, **ensamblado** y **enlazado**.

### Opciones recomendadas

- `-Wall`: muestra advertencias comunes
- `-Wextra`: más advertencias
- `-Werror`: convierte advertencias en errores

---

## Uso de headers (`.h`)

Los headers permiten:

1. **Organización del código**
2. **Reutilización**
3. **Separación de interfaz e implementación**

### Contenido típico

```c
// Prototipos
int suma(int a, int b);
#define PI 3.14159
```

### Guardas de inclusión

```c
#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H
// contenido
#endif
```

Evitan la inclusión múltiple de un archivo.

### Compilación múltiple

```sh
$> gcc -o binario main.c funciones.c
```

---

## Headers estándar útiles

- `<stdio.h>`: entrada/salida (printf, scanf)
- `<string.h>`: manipulación de cadenas (strlen, strcpy, strcmp)
- `<math.h>`: funciones matemáticas (sqrt, pow, fabs)

Referencias: [cppreference - C](https://es.cppreference.com/w/c)

---

## Makefiles

### ¿Qué es un Makefile?

Es una herramienta para automatizar la compilación, especialmente útil cuando
hay múltiples archivos fuente.

```make
programa: main.c funciones.c
    gcc -o programa main.c funciones.c
```

> 🔸 La indentación debe hacerse con **tabuladores**.

### Reglas comunes

- `make`: compila
- `make clean`: limpia archivos generados
- `make test`: ejecuta pruebas
- `make run`: compila y ejecuta

### Estructura sugerida para TPs

```sh
├── Makefile
└── plantilla
    ├── ejercicio.c
    ├── ejercicio.h
    ├── main.c
    ├── Makefile
    └── prueba.c
```

> ❗ Completar la plantilla antes de duplicarla y ajustar nombres si es
> necesario.

---

## Testing

### ¿Para qué probar?

- Validar funcionalidad aislada
- Detectar errores temprano
- Facilitar refactorizaciones
- Mejorar calidad y documentación

### Ejemplo de prueba

```c
void test_suma_positivo_positivo() {
    int a = 5, b = 3;
    int resultado = suma(a, b);
    assert(resultado == 8);
}
```

### Uso de `assert`

```c
#include <assert.h>
assert(condición); // Si es falsa, termina el programa
```

> ⚠ No se debe usar en producción (`#define NDEBUG` desactiva los asserts)

---

## Contratos

Los **contratos** documentan formalmente lo que una función espera y garantiza.

### Tipos de condiciones

- **Precondición**: requisitos antes de ejecutar
- **Postcondición**: condiciones que deben cumplirse al terminar
- **Invariante**: siempre ciertas durante ejecución (en estructuras iterativas)

### Ejemplo de contrato en documentación

```c
/*
 * @param termino1: número entero entre -128 y 127
 * @param termino2: igual que el anterior
 * @returns: suma entre ambos, rango -256 a 256
 * PRE: números dentro de rango
 * POST: valor dentro del resultado esperado
 */
int suma(int termino1, int termino2);
```

---

## Valores especiales y documentación

- Determinar **valores válidos** y límites.
- Documentar el uso de retornos especiales (`-1`, `'c'`, etc.)
- Documentar **invariantes internas** si aplican.

---

## Conclusión

- Entendimos el proceso de compilación y organización del código.
- Vimos cómo estructurar un proyecto en C usando headers y Makefiles.
- Introdujimos la importancia del testing y la especificación con contratos.

🔁 Reforzaremos estos conceptos en el **TP3**.
