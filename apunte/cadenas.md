# Guía definitiva para aprender a programar en C desde cero (con foco en cadenas)

> *"Si podés domar punteros y cadenas en C, podés domar dragones en cualquier lenguaje."*

---

## Introducción

Bienvenido, aspirante a programador. Hoy vas a entrar al templo del Lenguaje C, con el objetivo claro de dominar uno de los aspectos más traicioneros pero fundamentales: **las cadenas de caracteres**. C no te va a cuidar. No hay cuerdas de seguridad, no hay "strings" como en Python. Acá sos vos, el puntero, y el abismo de la memoria.

Esta guía no se trata de más de lo mismo. Acá vas a aprender desde el nivel más bajo, sin atajos. Al final, vas a entender cómo funcionan las cadenas *de verdad*.

---

## Nivel 1: El alfabeto binario

Antes de trabajar con cadenas, entendamos qué es una cadena:

- En C, una cadena es un **array de **``.
- Cada `char` ocupa un byte (8 bits).
- El final de la cadena está marcado por un byte especial: `\0`, el **carácter nulo**.

Ejemplo:

```c
char saludo[] = "Hola";
```

Esto crea un array con los siguientes bytes:

```
'H' 'o' 'l' 'a' '\0'
```

### Recordá:

- Las comillas dobles (`"`) crean automáticamente el `\0` al final.
- El tipo `char *` apunta al primer `char` de una cadena.

---

## Nivel 2: Declarar y usar cadenas

### Declarar una cadena literal:

```c
char *nombre = "Ada";
```

Esto apunta a una cadena constante. **No la modifiques**.

### Declarar una cadena modificable:

```c
char nombre[] = "Ada";
nombre[0] = 'E';  // Válido
```

### Lectura de cadenas:

```c
char buffer[100];
scanf("%s", buffer); // Se detiene en espacio
```

### Recomendación neckbeard:

Usá `fgets` para evitar desbordes:

```c
fgets(buffer, sizeof(buffer), stdin);
```

---

## Nivel 3: Funciones para cadenas

Estas funciones viven en `<string.h>`:

- `strlen(s)` - Devuelve la longitud SIN contar `\0`.
- `strcpy(dest, src)` - Copia `src` en `dest`. (PELIGRO si no hay suficiente espacio)
- `strncpy(dest, src, n)` - Copia hasta `n` caracteres.
- `strcmp(s1, s2)` - Compara cadenas (0 si son iguales).
- `strcat(dest, src)` - Concatena `src` al final de `dest`.

### Ejemplo de uso seguro:

```c
char destino[100];
strncpy(destino, "Hola", sizeof(destino) - 1);
destino[sizeof(destino) - 1] = '\0'; // Siempre cerrar con nulo
```

---

## Nivel 4: Recorrer una cadena manualmente

```c
char *s = "Ejemplo";
while (*s != '\0') {
    putchar(*s);
    s++;
}
```

O usando índices:

```c
char s[] = "Ejemplo";
for (int i = 0; s[i] != '\0'; i++) {
    putchar(s[i]);
}
```

### Pregunta clave:

¿Cuánto mide la cadena?

```c
strlen(s); // pero nunca te olvides del +1 si reservás memoria
```

---

## Nivel 5: Efectos secundarios y pasaje a funciones

### Las cadenas se pasan como punteros:

```c
void gritar(char *s) {
    while (*s) {
        *s = toupper(*s);
        s++;
    }
}
```

Esta función **modifica la cadena original**.

### Si no querés modificar:

```c
void mostrar(const char *s) {
    printf("%s\n", s);
}
```

Siempre que no modifiques, **usá **``. Ayuda al compilador y a tu yo del futuro.

---

## Nivel 6: Alocación dinámica de cadenas

```c
char *copia = malloc(strlen(original) + 1);
if (copia != NULL) {
    strcpy(copia, original);
}
```

Y al final:

```c
free(copia);
```

### Consejos de sabio:

- Siempre pedí un byte extra para el `\0`.
- Nunca trabajes con `malloc` sin chequear el `NULL`.
- Nunca pierdas el puntero original retornado por `malloc`.

---

## Nivel 7: Errores comunes que te van a romper la cabeza

- **Olvidarse del **`` al armar una cadena "a mano".
- **Desbordar arrays** con `strcpy`, `scanf`, `strcat`.
- **Modificar cadenas literales** (`char *s = "hola"; s[0] = 'H'; // SEGFAULT`)
- **No liberar memoria** de `malloc`.

---

## Nivel final: Cadenas como tipo de dato

En C no hay tipos "string" nativos, pero podés definir abstracciones:

```c
typedef struct {
    char *data;
    size_t len;
} String;
```

Podés implementar tus propias funciones:

```c
String string_crear(const char *texto);
void string_destruir(String *s);
void string_concatenar(String *a, const String *b);
```

---

## Epílogo

Dominar las cadenas en C es como aprender a usar una katana afilada. Si sos descuidado, te cortás. Pero si la dominás, nada se te va a resistir.

> *"Primero aprendés a no hacer segmentation fault. Después, aprendés a evitarlo. Al final, aprendés a debuguearlo sin miedo."*

Felicitaciones. Si llegaste hasta acá, sos uno menos en la Matrix. Segí practicando.

---

### Bonus Hack

Compilá con:

```bash
gcc -Wall -Wextra -pedantic -g tu_codigo.c -o tu_programa
```

Y usá `valgrind`:

```bash
valgrind ./tu_programa
```

No es opcional. Es sobrevivir o morir con dignidad.

