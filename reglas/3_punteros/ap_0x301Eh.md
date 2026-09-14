---
title: "Antipatrón AP-0x301Eh: Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo"
short_title: "AP-0x301Eh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x301Eh)=
# Antipatrón AP-0x301Eh: Reserva de buffer con malloc(strlen(s)) sin espacio para byte nulo

:::{admonition} Regla de Estilo Asociada: 0x300Bh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Bh: Usá siempre sizeof en las asignaciones de memoria dinámica, prefiriendo sizeof(*ptr)](0x300Bh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x301Eh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

El buffer para copiar una cadena se reserva con el largo exacto que reporta
`strlen`:

```c
char *dup = malloc(strlen(s));
strcpy(dup, s);
```

El `+ 1` que debería acompañar a `strlen` no está.

## Diagnóstico

### Mecanismo del defecto

`strlen` cuenta los caracteres **hasta, sin incluir,** el byte nulo `'\0'`. Una
cadena `"dato"` tiene `strlen` igual a 4, pero ocupa 5 bytes: `d`, `a`, `t`,
`o` y `'\0'`. Al reservar `strlen(s)` bytes, falta lugar para el terminador.

`strcpy` copia los 4 caracteres **y** el `'\0'`, es decir 5 bytes en un bloque
de 4. Es un *off-by-one* de escritura: se escribe un byte fuera del bloque
reservado. Ese byte pisa metadatos del asignador o el comienzo de otro bloque.
Además, la cadena resultante queda sin terminador si por casualidad el byte
siguiente no era cero.

### Consecuencia observable

- Corrupción de heap de a un byte, muy difícil de rastrear.
- La cadena puede quedar sin terminar y provocar lecturas fuera de límites en
  `printf`, `strcmp` o cualquier función de cadenas.
- `heap-buffer-overflow` bajo AddressSanitizer, señalado exactamente en el
  `strcpy`.

## Fundamento en el estándar C11

- C11 §7.24.6.3p3: `strlen` devuelve el número de caracteres que preceden al
  terminador.
- C11 §7.24.2.3p2: `strcpy` copia la cadena **incluido el carácter nulo final**.
- C11 §7.22.3p1: `malloc` reserva exactamente los bytes pedidos. No hay margen
  implícito.
- La regla 0x300Bh exige dimensionar la reserva con `sizeof`; para cadenas, el
  patrón correcto es `(strlen(s) + 1) * sizeof(*dup)`.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
char *duplicar(const char *s)
{
    char *dup = malloc(strlen(s));
    if (dup == NULL) {
        return NULL;
    }
    strcpy(dup, s);
    return dup;
}
```

### ✅ Código refactorizado

```c
char *duplicar(const char *s)
{
    char *dup = malloc((strlen(s) + 1) * sizeof(*dup));
    if (dup == NULL) {
        return NULL;
    }
    strcpy(dup, s);
    return dup;
}
```

El `+ 1` es para el terminador; `sizeof(*dup)` deja el cálculo preparado para
cualquier tipo de carácter.

### ✅ Alternativa robusta con `memcpy`

```c
size_t largo = strlen(s) + 1;
char *dup = malloc(largo * sizeof(*dup));
if (dup == NULL) {
    return NULL;
}
memcpy(dup, s, largo);
```

### ⚠️ Casos límite

- Si `s` es `NULL`, `strlen(s)` es UB; hay que validar antes.
- Cadenas vacías: `strlen("") == 0`, por lo que la reserva correcta es 1 byte.
- `snprintf` con el tamaño correcto evita el `strcpy`, pero no exime del `+ 1`
  en la reserva.
- En lectura con `fgets`, el buffer debe contemplar terminador y eventual
  salto de línea.

## Errores típicos al compilar o ejecutar

```text
# Con AddressSanitizer:
ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...
WRITE of size 1 at 0x... thread T0
#0 0x... in __interceptor_strcpy
#1 0x... in duplicar programa.c:7

# Con glibc:
$ ./programa
malloc(): corrupted top size
Aborted (core dumped)
```

## Checklist de verificación

- [ ] ¿Toda reserva de cadena suma `+ 1` por el terminador?
- [ ] ¿Usé `sizeof(*ptr)` y no un número fijo?
- [ ] ¿Validé que la cadena de origen no sea `NULL`?
- [ ] ¿La copia deja lugar para el `'\0'`?

## Reglas relacionadas

* {ref}`0x300Bh` — dimensionar con `sizeof`.
* {ref}`0x5004h` — operaciones seguras con cadenas.
* {ref}`0x5006h` — preferir `fgets` sobre `gets`/`scanf`.
* [AP-0x3027h: Cálculo erróneo de tamaño para struct dinámico con miembro flexible](ap_0x3027h.md) — otro cálculo de tamaño incompleto.
