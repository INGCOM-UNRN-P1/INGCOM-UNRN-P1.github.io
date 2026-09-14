---
title: "Antipatrón AP-0x300Dh: Número mágico literal en condición lógica"
short_title: "AP-0x300Dh"
subtitle: "Punteros y Gestión de Memoria (0x30XX)"
---

(ap_0x300Dh)=
# Antipatrón AP-0x300Dh: Número mágico literal en condición lógica

:::{admonition} Regla de Estilo Asociada: 0x300Dh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x300Dh: Utilizá enum en lugar de "números mágicos" para conjuntos de estados y valores constantes](0x300Dh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x300Dh` | Categoría: Punteros y Gestión de Memoria (0x30XX)
:::

## Síntoma en el código del estudiante

Las decisiones de dominio se escriben con literales sueltos:

```c
if (estado == 404) {
    /* ... */
} else if (estado == 500) {
    /* ... */
}
```

El lector no puede saber qué significa `404` ni `500` sin acudir al enunciado.
Lo mismo ocurre con `0`, `1`, `2` usados como modos de un TAD.

## Diagnóstico

### Mecanismo del defecto

Un literal numérico no tiene nombre ni tipo semántico. El compilador solo ve un
`int`; no puede verificar que el valor pertenezca al conjunto válido de estados.
Cuando el conjunto cambia (se agrega un estado, se reordena), hay que cazar
todos los literales repetidos a mano y cada omisión se convierte en un bug
lógico silencioso.

El mismo problema es más grave al pasar estos valores como argumentos: una
firma `void configurar(int modo)` acepta cualquier entero, incluidos los que no
tienen sentido. Un `enum` restringe el dominio y autodocumenta el contrato.

### Consecuencia observable

- Código ilegible sin el enunciado al lado.
- Bugs por desincronización tras cambiar un valor en un solo lugar.
- Imposibilidad de que el compilador advierta sobre un valor inválido.

## Fundamento en el estándar C11

- C11 §6.7.2.2: un `enum` define un conjunto de constantes de tipo entero con
  nombres; el compilador conoce ese conjunto y su tipo subyacente.
- C11 §6.7.2.2p4: los enumeradores tienen tipo `int` (salvo que no quepan), por
  lo que un `switch` sobre `enum` puede cubrirse exhaustivamente.
- La regla 0x0038h extiende el principio a los índices de arreglos: todo literal
  con significado de dominio se reemplaza por una constante simbólica.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
int procesar(int estado)
{
    if (estado == 1) {
        return 0;
    } else if (estado == 2) {
        return 1;
    }
    return -1;
}
```

### ✅ Código refactorizado — enum con nombre

```c
typedef enum {
    ESTADO_NUEVO = 0,
    ESTADO_EN_PROCESO = 1,
    ESTADO_TERMINADO = 2
} estado_t;

int procesar(estado_t estado)
{
    switch (estado) {
    case ESTADO_NUEVO:
        return 0;
    case ESTADO_EN_PROCESO:
        return 1;
    case ESTADO_TERMINADO:
        return 2;
    default:
        return -1;
    }
}
```

### ✅ Alternativa — constantes `#define` para valores externos

```c
#define HTTP_NOT_FOUND 404
#define HTTP_SERVER_ERROR 500

if (codigo == HTTP_NOT_FOUND) {
    /* ... */
}
```

`enum` es preferible cuando los valores forman un conjunto cerrado y
relacionado; `#define` sirve para constantes aisladas.

### ⚠️ Casos límite

- `0` y `1` como cantidades triviales (`i = 0`) son legítimos: no son
  "mágicos", son la identidad de un contador.
- Los `-1` de error suelen merecer un nombre (`ERROR`, `NO_ENCONTRADO`).
- Un `enum` con un único valor no aporta; conviene un `#define` bien nombrado.

## Errores típicos al compilar o ejecutar

```text
# El compilador no detecta un valor fuera de dominio:
$ ./programa
# estado = 7 entra por ninguna rama y devuelve -1 silenciosamente

$ gcc -Wall -Wextra -std=c11 -Wswitch programa.c
# con enum y switch sin default útil, avisa si falta un caso enumerado
```

## Checklist de verificación

- [ ] ¿Los estados del dominio tienen nombres (`enum`) en lugar de literales?
- [ ] ¿El `switch` cubre todos los enumeradores o tiene `default`?
- [ ] ¿Las firmas usan el tipo `enum` en lugar de `int` para esos valores?
- [ ] ¿Las constantes aisladas siguen la convención MAYUSCULAS_SNAKE_CASE?

## Reglas relacionadas

* {ref}`0x300Dh` — enum para conjuntos de estados.
* {ref}`0x0038h` — constantes simbólicas para índices de arreglos.
* {ref}`0x2008h` — valores de retorno numéricos como constantes o enums.
* [AP-0x3019h: Pointer decay en sizeof de arreglo parámetro](ap_0x3019h.md) — otro uso de una constante sin tipo.
