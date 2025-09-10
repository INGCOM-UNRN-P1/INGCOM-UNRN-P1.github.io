# Guía definitiva de punteros, efectos secundarios y temas relacionados en C

> Por el viejo barbudo que compila sin warnings

---

## ¿Por qué esta guía?

Porque ya sabés declarar arreglos y manejar cadenas, pero estás jugando con
fuego sin saberlo. Si no sabés qué son realmente los punteros, no sabés por qué
tu programa hace cosas raras o por qué algo se imprime distinto cada vez que
corrés tu código.

Esta guía es para vos, joven padawan del stack.

---

## 1. Qué es un puntero, sin rodeos

Un puntero es una variable que almacena una **dirección de memoria**. En otras
palabras, es una variable cuyo valor apunta hacia otra variable.

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

lo que en realidad pasa es que **el nombre del arreglo se convierte en un
puntero al primer elemento**.

Lo mismo con:

```c
void imprimir(char s[]) {
    printf("%s", s);
}
```

¡Eso es trampa! `char s[]` es sintaxis azucarada para `char *s`. O sea, estás
pasando un puntero.

---

## 3. Efectos secundarios: el lado oscuro del puntero

Cuando pasás una variable a una función, se copia.

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

Ahora `a == 10`. Esto se llama **efecto secundario**: una función que modifica
algo fuera de su ámbito.

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

Si no documentás qué modifica una función, tu código se vuelve un pantano de
bugs.

Evitalo:

- Comentando
- Nombrando bien la función (`modificar_algo`, `actualizar_estado`, etc.)
- Separando funciones puras (sin efectos) de impuras

---

## 5. Const y punteros: el ancla de seguridad

```c
void imprimir(const char *mensaje);
```

`const` indica que **la función no debe modificar el contenido apuntado**. Esto
permite al compilador detectar errores si intentás hacer `mensaje[0] = 'X';`

Usá `const` siempre que no vayas a modificar lo apuntado.

---

## 6. Punteros dobles: punteros a punteros

```c
int **pp;
```

Esto es una dirección que apunta a una dirección que apunta a un entero. Se usa
para:

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

---

## 8. Punteros colgantes

Un puntero colgante apunta a memoria que ya no es válida. Esto puede ocurrir si
el puntero se refiere a una variable local que ya salió de ámbito.

```c
int *funcion() {
    int x = 5;
    return &x; // MAL: x deja de existir al salir de la función
}
```

Evitalo asegurándote de no retornar direcciones de variables locales.

---

## 13. Degradación de arreglos a punteros

Uno de los comportamientos más importantes —y sutiles— en C es que los
**arreglos se "degradan" (decay) a punteros** en la mayoría de los contextos.

### ¿Qué significa esto?

Cuando usás el nombre de un arreglo, como `a`, fuera de una expresión que
declare o defina el arreglo, **lo que el compilador interpreta es un puntero al
primer elemento del arreglo**.

Ejemplo:

```c
int numeros[5] = {1, 2, 3, 4, 5};
int *p = numeros; // equivalente a int *p = &numeros[0];
```

Esto es lo que permite que puedas recorrer un arreglo con punteros:

```c
for (int i = 0; i < 5; i++) {
    printf("%d ", *(p + i));
}
```

### En funciones: el efecto más importante

Cuando pasás un arreglo a una función:

```c
void imprimir(int datos[]) {
    // ...
}
```

...en realidad es equivalente a:

```c
void imprimir(int *datos) {
    // ...
}
```

**La función no recibe una copia del arreglo, sino un puntero al primer
elemento.** Por eso, cualquier modificación dentro de la función afecta al
arreglo original.

Ejemplo:

```c
void llenar(int datos[], int valor, int n) {
    for (int i = 0; i < n; i++) {
        datos[i] = valor;
    }
}

int arreglo[10];
llenar(arreglo, 42, 10); // arreglo queda modificado
```

### ¿Dónde _no_ se degrada?

Hay ciertos contextos donde un arreglo **no se degrada a puntero**:

1. Cuando usás `sizeof` directamente sobre el arreglo:

   ```c
   int a[10];
   printf("%zu\n", sizeof(a));      // imprime 40 (10 * 4)
   printf("%zu\n", sizeof(&a[0]));   // imprime 8 (tamaño del puntero)
   ```

2. Cuando pasás el arreglo por referencia (como `&a`).

3. Cuando es parte de un `struct`.

### Implicancias importantes

- El tamaño del arreglo no se pasa a la función. Hay que pasarlo como parámetro
  adicional.
- Una función **no puede conocer** el tamaño del arreglo que recibió, a menos
  que vos se lo digas.

### Conclusión

::::{hint} Recordá: cuando pasás un arreglo a una función, lo que realmente
pasás es un puntero. Esto permite eficiencia (no se copia el arreglo), pero
también significa que cualquier cambio se propaga. ::::

Este comportamiento es clave para entender los efectos secundarios con arreglos
y punteros.

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

---

## 11. Recursos mentales

Visualizá:

- Memoria como una cinta con casillas
- Punteros como flechas que apuntan a casillas
- `*` como "dame lo que hay allí"
- `&` como "dame la dirección de esto"

---

## 12. Ejercicios sugeridos

1. Escribí una función que reciba un arreglo de enteros y lo invierta **en el
   mismo lugar**.
2. Implementá `strlen` con punteros.
3. Escribí una función `copiar_string` que reciba dos arreglos de `char` y copie
   el contenido del primero en el segundo.
4. Implementá `intercambiar` para arreglos de `char *`.
5. Detectá un puntero colgante en un código malicioso.

---

### Cierre

Aprender punteros es como aprender a manejar espadas: te podés cortar si no
sabés lo que hacés. Pero una vez que dominás el arte, podés escribir código
afilado, elegante y poderoso.

El camino del C es arduo, pero glorioso.

> — "Nunca uses un puntero sin saber a qué apunta, joven aprendiz. Esas son las
> reglas del stack."
