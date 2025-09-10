# Guía definitiva de punteros, efectos secundarios y temas relacionados en C

> Por el viejo barbudo que compila sin warnings

---

## ¿Por qué esta guía?

Porque ya sabés declarar arreglos y manejar cadenas, pero estás jugando con fuego sin saberlo. Si no sabés qué son realmente los punteros, no sabés por qué tu programa hace cosas raras o por qué algo se imprime distinto cada vez que corrés tu código.

Esta guía es para vos, joven padawan del stack.

---

## 1. Qué es un puntero, sin rodeos

Un puntero es una variable que almacena una **dirección de memoria**. En otras palabras, es una variable cuyo valor apunta hacia otra variable o hacia un lugar específico de la memoria.

```c
int x = 42;
int *p = &x;
```

- `x` guarda el valor `42`.
- `&x` es "la dirección de memoria de `x`".
- `p` es un puntero a entero, que guarda esa dirección.
- `*p` es el contenido de la dirección que apunta `p`, o sea, `42`.

### Recordá:

| Símbolo | Significado                        |
| ------- | ---------------------------------- |
| `*`     | Valor apuntado (dereferenciar)     |
| `&`     | Dirección de memoria (referenciar) |

La confusión común es que `*` se usa tanto para declarar punteros como para acceder a lo que apuntan. No son lo mismo:

```c
int *p;     // declaración: p es un puntero a entero
*p = 10;    // uso: escribir en la dirección apuntada por p
```

---

## 2. Arreglos y cadenas: no eran lo que pensabas

Cuando escribís:

```c
char saludo[] = "Hola";
```

Estás declarando un arreglo, pero al usarlo en funciones, como:

```c
printf("%s", saludo);
```

lo que en realidad pasa es que **el nombre del arreglo se convierte en un puntero al primer elemento**.

Lo mismo con:

```c
void imprimir(char s[]) {
    printf("%s", s);
}
```

¡Eso es trampa! `char s[]` es sintaxis azucarada para `char *s`. O sea, estás pasando un puntero.

Este fenómeno se llama **degradación de arreglo a puntero** y tiene implicancias importantes que veremos más adelante.

---

## 3. Efectos secundarios: el lado oscuro del puntero

Cuando pasás una variable a una función, se copia:

```c
void duplicar(int x) {
    x = x * 2;
}
```

Esto no modifica la variable original. Pero si pasás su dirección:

```c
void duplicar(int *px) {
    *px = *px * 2;
}
```

Ahora sí. Porque trabajás sobre la memoria original.

```c
int a = 5;
duplicar(&a);
```

Ahora `a == 10`. Esto se llama **efecto secundario**: una función que modifica algo fuera de su ámbito.

### Efectos secundarios comunes con punteros:

- Modificar arreglos
- Modificar estructuras
- Cambiar el valor de una variable

---

## 4. Punteros y funciones

### Pasaje por dirección

```c
void intercambiar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

Llamada:

```c
intercambiar(&x, &y);
```

### Efectos secundarios: cuidado

Si no documentás qué modifica una función, tu código se vuelve un pantano de bugs.

Evitalo:

- Comentando
- Nombrando bien la función (`modificar_algo`, `actualizar_estado`, etc.)
- Separando funciones puras (sin efectos) de impuras

---

## 5. Const y punteros: el ancla de seguridad

```c
void imprimir(const char *mensaje);
```

`const` indica que **la función no debe modificar el contenido apuntado**. Esto permite al compilador detectar errores si intentás hacer `mensaje[0] = 'X';`

Usá `const` siempre que no vayas a modificar lo apuntado.

También podés tener combinaciones:

```c
const int *p; // puntero a entero constante (no puedo modificar *p)
int *const q; // puntero constante a entero (no puedo cambiar q)
```

---

## 6. Punteros dobles: punteros a punteros

```c
int **pp;
```

Esto es una dirección que apunta a una dirección que apunta a un entero. Se usa para:

- Simular "pasaje por referencia" (modificar un puntero desde una función)

Ejemplo:

```c
void cambiar_puntero(int **pp) {
    static int nuevo = 99;
    *pp = &nuevo;
}
```

---

## 7. Punteros nulos y validación

Nunca asumas que un puntero apunta a algo.

```c
if (ptr != NULL) {
    // seguro
}
```

De hecho, inicializá siempre los punteros:

```c
int *p = NULL;
```

Esto evita comportamientos indefinidos por acceder a memoria no válida.

---

## 8. Punteros colgantes

Un puntero colgante apunta a memoria que ya no es válida. Esto puede ocurrir si el puntero se refiere a una variable local que ya salió de ámbito.

```c
int *funcion() {
    int x = 5;
    return &x; // MAL: x deja de existir al salir de la función
}
```

Evitalo asegurándote de no retornar direcciones de variables locales.

---

## 9. La triple amenaza: punteros, structs y funciones

Punteros permiten pasar estructuras grandes sin copiarlas.

```c
typedef struct {
    char nombre[100];
    int edad;
} Persona;

void mostrar(const Persona *p) {
    printf("%s tiene %d años", p->nombre, p->edad);
}
```

Usá `->` para acceder a campos a través de un puntero.

---

## 10. Buenas prácticas neckbeardianas

- Inicializá todos los punteros a `NULL`.
- Siempre chequeá que no sean `NULL` antes de usarlos.
- Usá `const` donde puedas.
- Nunca retornes punteros a variables locales.
- Documentá claramente los efectos secundarios de cada función.
- Dibujá diagramas mentales de la memoria.
- Nunca te fíes de un puntero sin antes validarlo.

---

## 11. Recursos mentales

Visualizá:

- Memoria como una cinta con casillas numeradas
- Punteros como flechas que apuntan a casillas
- `*` como "dame lo que hay allí"
- `&` como "dame la dirección de esto"
- Arreglos como una serie de casillas contiguas

---

## 12. Ejercicios sugeridos

1. Escribí una función que reciba un arreglo de enteros y lo invierta **en el mismo lugar**.
2. Implementá `strlen` con punteros.
3. Escribí una función `copiar_string` que reciba dos arreglos de `char` y copie el contenido del primero en el segundo.
4. Implementá `intercambiar` para arreglos de `char *`.
5. Detectá un puntero colgante en un código malicioso.

---

## 13. Degradación de arreglos a punteros

Una de las reglas más fundamentales y a la vez más invisibles del lenguaje C es que **los arreglos se "degradan" a punteros en la mayoría de los contextos**. Esto significa que, aunque escribas `int arreglo[10]`, muchas veces el compilador lo tratará como si fuera `int *`.

### ¿Qué significa "degradar"?

Cuando usás el nombre de un arreglo por sí solo (sin subíndices, sin `sizeof`, etc.), C lo interpreta automáticamente como la **dirección del primer elemento del arreglo**.

```c
int numeros[5] = {1, 2, 3, 4, 5};
int *p = numeros;           // equivalente a int *p = &numeros[0];
int primero = *numeros;     // accede a numeros[0]
```

Esto explica por qué podés usar aritmética de punteros con arreglos:

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", *(numeros + i)); // igual que numeros[i]
}
```

### Pasaje de arreglos a funciones

Cuando pasás un arreglo a una función, **lo que se pasa realmente es un puntero**. No se copia el contenido del arreglo, sino que se pasa la dirección de su primer elemento.

```c
void imprimir(int datos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");
}

int numeros[5] = {10, 20, 30, 40, 50};
imprimir(numeros, 5); // "numeros" se degrada a un puntero
```

Aunque el parámetro esté escrito como `int datos[]`, C lo interpreta como `int *datos`. Esto significa que **la función puede modificar el contenido del arreglo original**, porque trabaja sobre su misma memoria.

### Implicancias

- Las funciones no conocen el tamaño del arreglo recibido.
- Hay que pasar el tamaño como un parámetro adicional.
- Se pueden producir efectos secundarios si la función escribe en el arreglo.

### ¿Cuándo *no* se degrada un arreglo?

Hay algunos contextos donde el arreglo *no* se convierte automáticamente en un puntero:

1. **Cuando se usa **``** directamente sobre el arreglo:**

   ```c
   int a[10];
   printf("%zu\n", sizeof(a));     // imprime 40 (si int ocupa 4 bytes)
   printf("%zu\n", sizeof(&a[0]));  // imprime 8 (tamaño del puntero)
   ```

2. **Cuando se pasa como argumento por referencia:**

   ```c
   int a[5];
   int (*p)[5] = &a; // puntero a arreglo de 5 enteros, sin degradar
   ```

3. **Cuando forma parte de un **``**:**

   ```c
   typedef struct {
       int datos[10];
   } Contenedor;

   Contenedor c;
   sizeof(c.datos); // 40 (el arreglo no se degrada)
   ```

### Conclusión

Comprender la degradación de arreglos a punteros es esencial para entender el comportamiento real del código C. Especialmente en el contexto de funciones, esta conversión automática permite una gran eficiencia, pero también introduce la posibilidad de efectos secundarios si no se maneja con cuidado.

> "Los arreglos son una ilusión del preprocesador. El puntero es la verdad detrás de la máscara."

---

## Cierre

Aprender punteros es como aprender a manejar espadas: te podés cortar si no sabés lo que hacés. Pero una vez que dominás el arte, podés escribir código afilado, elegante y poderoso.

El camino del C es arduo, pero glorioso.

> — "Nunca uses un puntero sin saber a qué apunta, joven aprendiz. Esas son las reglas del stack."

