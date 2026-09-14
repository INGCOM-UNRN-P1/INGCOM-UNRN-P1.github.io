---
title: "Antipatrón AP-0x301Dh: Comparación sintáctica errónea de puntero con carácter nulo '\0'"
short_title: "AP-0x301Dh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Dh)=
# Antipatrón AP-0x301Dh: Comparación sintáctica errónea de puntero con carácter nulo '\0'

:::{admonition} Regla de Estilo Asociada: 0x3008h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x3008h: Los punteros nulos deben ser inicializados y comparados con NULL, no con 0](0x3008h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Dh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

Para detectar el fin de una cadena se compara el **puntero** con el carácter
nulo:

```c
if (str == '\0') {
    /* ... */
}
```

El estudiante quiso preguntar "¿la cadena está vacía?" o "¿llegué al final?",
pero comparó la dirección con el valor cero.

## Diagnóstico

### Mecanismo del defecto

`'\0'` es una constante de tipo `int` con valor `0`. Al comparar un puntero
contra ella, C convierte el `0` en la **constante de puntero nulo**, de modo que
`str == '\0'` es equivalente a `str == NULL`. La expresión compila y no advierte
nada, pero no mide el contenido de la cadena: solo pregunta si el puntero es
nulo.

Para saber si el primer carácter es el terminador hay que **desreferenciar**:
`*str == '\0'` o, con azúcar, `str[0] == '\0'`. Recién ahí se lee el objeto
apuntado.

Una sutileza: `'\0'` es entero, no carácter. La comparación idiomática de
caracteres es contra `'\0'`, pero la de punteros es contra `NULL`; mezclar
dominios es el error de fondo.

### Consecuencia observable

- La condición nunca es verdadera para un puntero válido, así que el caso
  "cadena vacía" no se detecta.
- Posible desreferencia posterior de un puntero que se creía no nulo.
- Silencio total del compilador: es una comparación legal y peligrosa.

## Fundamento en el estándar C11

- C11 §6.3.2.3p3: la constante entera `0` se convierte en puntero nulo al
  compararla con un puntero.
- C11 §6.5.3.2: para examinar el carácter apuntado hay que aplicar `*`.
- C11 §7.24.1: el terminador de una cadena es el carácter nulo `'\0'`.
- La regla 0x3008h separa los dos dominios: `NULL` para punteros, `'\0'` para
  caracteres.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
if (str == '\0') {
    return 0;
}
```

### ✅ Código refactorizado — primer carácter

```c
if (str == NULL) {
    return -1;
}
if (*str == '\0') {
    return 0;
}
```

### ✅ Recorrido de cadena con la distinción correcta

```c
while (*str != '\0') {
    procesar(*str);
    str++;
}
```

Acá `*str` es un `char` y se compara contra `'\0'`, que es su contraparte
natural.

### ⚠️ Casos límite

- `if (str[0] == '\0')` es equivalente y también correcto.
- `if (str == NULL)` sigue siendo necesario antes de desreferenciar.
- No confundir `'\0'` (carácter nulo) con `"0"` (cadena que contiene el dígito
  cero) ni con `'0'` (carácter dígito).
- En comparaciones de punteros siempre `NULL`; la cátedra prohíbe `!= 0` para
  punteros.

## Errores típicos al compilar o ejecutar

```text
$ gcc -Wall -Wextra -std=c11 programa.c
# sin advertencia: la comparación puntero/0 es legal

$ ./programa
# la rama de "cadena vacía" nunca se ejecuta y el flujo continúa
Segmentation fault (core dumped)
```

## Checklist de verificación

- [ ] ¿Comparo caracteres con `'\0'` y punteros con `NULL`?
- [ ] ¿Desreferencié (`*str` o `str[0]`) antes de comparar el contenido?
- [ ] ¿Verifiqué `str != NULL` antes de desreferenciarlo?
- [ ] ¿Ninguna comparación de puntero usa `0` o `'\0'` en lugar de `NULL`?

## Reglas relacionadas

* {ref}`0x3008h` — `NULL` para punteros, no `0`.
* {ref}`0x1005h` — comparaciones explícitas, sin *truthiness*.
* {ref}`0x5004h` — operaciones seguras con cadenas.
* [AP-0x3008h: Chequeo innecesario antes de free()](ap_0x3008h.md) — mismo campo de comparaciones de punteros.
