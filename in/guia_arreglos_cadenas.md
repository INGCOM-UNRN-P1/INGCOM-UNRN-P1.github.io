# Guía para aprender C desde cero: Arreglos y Cadenas (sin punteros)

```{note}
Esta guía está diseñada para quienes se inician en el lenguaje de programación C. Nos centraremos en dos estructuras fundamentales: **arreglos** y **cadenas de caracteres**. Se excluyen punteros y aspectos más avanzados del lenguaje.
```

---

## ¿Qué es un arreglo?

Un **arreglo** es una secuencia finita de elementos del mismo tipo, almacenados contiguamente en memoria, y accedidos por su índice. Permiten almacenar y trabajar con colecciones de datos fijos.

### Sintaxis de declaración:

```c
int numeros[10]; // arreglo de 10 enteros
```

### Acceso a los elementos:

```c
numeros[0] = 42;
int x = numeros[1];
```

### Inicialización directa:

```c
int dias[7] = {1, 2, 3, 4, 5, 6, 7};
```

---

## Iterar sobre un arreglo

Una operación común con arreglos es recorrerlos con un bucle `for`:

```c
for (int i = 0; i < 10; i++) {
    printf("Elemento %d: %d\n", i, numeros[i]);
}
```

---

## Arreglos de caracteres: Cadenas

Una **cadena** en C es simplemente un arreglo de caracteres que termina con un carácter nulo (`'\0'`).

### Declaración e inicialización:

```c
char saludo[6] = {'H', 'o', 'l', 'a', '!', '\0'};
```

O bien:

```c
char saludo[] = "Hola!"; // El compilador agrega el '\0'
```

### Acceso a caracteres individuales:

```c
printf("Primera letra: %c\n", saludo[0]);
```

### Recorrer una cadena:

```c
for (int i = 0; saludo[i] != '\0'; i++) {
    printf("%c\n", saludo[i]);
}
```

---

## Funciones comunes para cadenas (sin usar punteros)

Podemos implementar funciones para operar con cadenas sin recurrir a punteros:

### Longitud de una cadena:

```c
int longitud(const char cadena[], int tam) {
    int i = 0;
    while (i < tam && cadena[i] != '\0') {
        i++;
    }
    return i;
}
```

---

## Cadenas seguras: estrategias

La manipulación insegura de cadenas puede causar errores graves. Estas son algunas estrategias para hacerlo correctamente **sin punteros**:

### 1. Reservar tamaño suficiente

Siempre asegurate de que el arreglo tenga espacio para el `\0`:

```c
char nombre[21]; // Hasta 20 letras + terminador nulo
```

### 2. Inicializar con cuidado

Si copiás carácter por carácter, asegurate de agregar el `\0`:

```c
char copia[6];
for (int i = 0; i < 5; i++) {
    copia[i] = saludo[i];
}
copia[5] = '\0';
```

### 3. Limitar operaciones por tamaño

Funciones como esta evitan leer más allá del arreglo:

```c
void imprimir(const char s[], int tam) {
    for (int i = 0; i < tam && s[i] != '\0'; i++) {
        putchar(s[i]);
    }
    putchar('\n');
}
```

### 4. Definir constantes para los tamaños

```c
#define MAX_NOMBRE 30
char nombre[MAX_NOMBRE];
```

Así evitamos "números mágicos" y podemos ajustar con facilidad.

---

## Buenas prácticas con arreglos y cadenas

- **Nunca accedas fuera de los límites del arreglo**.
- **Evitá suposiciones sobre tamaños de cadenas.** Usá siempre `\0` como terminador.
- **Revisá que todas tus cadenas estén correctamente terminadas.**
- **Preferí recorrer arreglos con **``** con límites claros.**

---

## Ejemplo final: contar vocales

```c
int contar_vocales(const char cadena[], int tam) {
    int contador = 0;
    for (int i = 0; i < tam && cadena[i] != '\0'; i++) {
        char c = cadena[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}
```

---

## Conclusión

Los arreglos y cadenas son estructuras fundamentales en C. Aprender a usarlas con precaución y claridad es clave antes de avanzar a temas más complejos como punteros o estructuras dinámicas.

Practicar su uso con ejemplos reales y desarrollar funciones simples alrededor de ellos te formará una base sólida en programación estructurada.

---

```{warning}
Evitar el uso de funciones como `gets()` o cualquier manipulación de cadenas sin control de tamaño. En esta etapa, mantenete en operaciones seguras y bien limitadas.
```

```{tip}
El compilador no siempre te avisará de errores de acceso fuera de límite en arreglos. ¡Revisá tu lógica y escribí tus propios chequeos!
```

