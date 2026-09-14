---
title: "Antipatrón AP-0x500Ah: Macro con argumentos evaluados múltiples veces"
short_title: "AP-0x500Ah"
subtitle: "Compilación, Buenas Prácticas y Seguridad (0x50XX)"
---

(ap_0x500Ah)=
# Antipatrón AP-0x500Ah: Macro con argumentos evaluados múltiples veces

:::{admonition} Regla de Estilo Asociada: 0x500Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x500Ah: Protección obligatoria de parámetros en macros funcionales mediante paréntesis](0x500Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x500Ah` | Categoría: Compilación, Buenas Prácticas y Seguridad (0x50XX)
:::

## Síntoma en el código del estudiante

Macros funcionales cuya expansión aparece repetida en el cuerpo:

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CUADRADO(x) ((x) * (x))
```

Y se las invoca con expresiones que tienen efectos colaterales:

```c
int m = MAX(i++, j);
int c = CUADRADO(x++);
```

El `++` se ejecuta tantas veces como aparece el parámetro en la expansión.

## Diagnóstico

### Mecanismo del defecto

El preprocesador hace **sustitución textual** antes de compilar
(C11 §6.10.3): no hay paso de parámetros real ni copia de valores. Cada
aparición de `a`, `b` o `x` en el cuerpo se reemplaza por el argumento
completo. En `MAX(i++, j)`, la expansión queda
`((i++) > (j) ? (i++) : (j))`, de modo que `i` se incrementa dos veces en
la rama verdadera. Y si dos modificaciones de la misma variable caen sin
punto de secuencia entre medio, el comportamiento es **indefinido**
(C11 §6.5p2).

A esto se suma el problema de precedencia cuando faltan paréntesis:
`#define MULT(a, b) a * b` expande `MULT(2 + 3, 4)` como `2 + 3 * 4`,
que da `14` en vez de `20`.

### Consecuencia observable

- El contador avanza de más: `i` termina en un valor inesperado.
- El resultado numérico cambia sin ningún error ni advertencia.
- El bug se reproduce solo cuando el argumento trae efectos colaterales, por
  eso el código parece "andar" con argumentos simples y falla en producción.

## Fundamento en el estándar C11

Una macro no impone evaluación única ni ordenada: es texto. La forma
correcta de encapsular una operación con evaluación controlada es una
función, y para no perder el rendimiento se usa `static inline`
(C11 §6.7.4), que el compilador puede incrustar. Los paréntesis protectores
siguen siendo obligatorios en macros que no se puedan evitar, conforme a
{ref}`0x500Ah` y {ref}`0x5015h`.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CUADRADO(x) ((x) * (x))

int main(void)
{
    int i = 7;
    int j = 3;
    int m = MAX(i++, j);
    int c = CUADRADO(j++);
    printf("%d %d %d %d\n", m, c, i, j);
    return 0;
}
```

### ✅ Código refactorizado

```c
#include <stdio.h>

static inline int max_int(int a, int b)
{
    return a > b ? a : b;
}

static inline int cuadrado(int x)
{
    return x * x;
}

int main(void)
{
    int i = 7;
    int j = 3;
    int m = max_int(i++, j);
    int c = cuadrado(j++);
    printf("%d %d %d %d\n", m, c, i, j);
    return 0;
}
```

La función recibe **valores**: cada argumento se evalúa una sola vez antes
de entrar al cuerpo, sin importar cuántas veces se use el parámetro.

## Errores típicos al compilar o ejecutar

La mayoría de las veces no hay mensaje: el programa compila y da un
resultado incorrecto. Con `MAX(i++, j)` e `i > j`, `i` se incrementa dos
veces y la salida del código con el antipatrón difiere de la refactorizada:

```text
antipatron: m=8 c=12 i=9 j=5
refactor  : m=7 c=9  i=8 j=4
```

La expresión `CUADRADO(j++)` expande `((j++) * (j++))` y modifica `j` dos
veces sin punto de secuencia: es comportamiento indefinido.

## Checklist de verificación

- [ ] ¿Toda macro funcional tiene cada parámetro entre paréntesis?
- [ ] ¿La expansión repite algún parámetro más de una vez?
- [ ] ¿Se invoca la macro con argumentos que tienen `++`, `--` o llamadas?
- [ ] ¿Convierto la macro en `static inline` cuando la evaluación importa?
- [ ] ¿Compilé con `-Wall -Wextra` y revisé `-Wsequence-point`?

## Reglas relacionadas

* {ref}`0x500Ah` — paréntesis obligatorios en parámetros de macros funcionales.
* {ref}`0x5015h` — paréntesis envolventes en expresiones de macroconstantes.
* {ref}`0x100Eh` — espaciado canónico alrededor del operador ternario.
