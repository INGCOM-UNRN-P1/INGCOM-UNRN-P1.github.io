---
title: "Antipatrón AP-0x200Bh: Función con excesiva cantidad de parámetros (> 5)"
short_title: "AP-0x200Bh"
subtitle: "Funciones y Modularización (0x20XX)"
---

(ap_0x200Bh)=
# Antipatrón AP-0x200Bh: Función con excesiva cantidad de parámetros (> 5)

:::{admonition} Regla de Estilo Asociada: 0x200Bh
:class: tip
La transgresión descripta se encuentra normada por la
**[0x200Bh: Modularización: una función no debe exceder 4 parámetros de entrada](0x200Bh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x200Bh` | Categoría: Funciones y Modularización (0x20XX)
:::

## Síntoma en el código del estudiante

Firmas que ocupan más de una línea y llamadas donde hay que contar posiciones
con el dedo. Los parámetros suelen ser del mismo tipo (`int`, `const char *`),
lo que deja la puerta abierta a intercambios silenciosos.

## Diagnóstico

### Mecanismo del defecto

Cada parámetro es un valor que el llamador debe copiar a un registro o a la
pila en un orden posicional fijo. Cuando varios comparten el mismo tipo, el
compilador no puede distinguir un intercambio: `crear(30, 40123456)` y
`crear(40123456, 30)` son la misma llamada válida, pero una está mal. La firma
larga también dispersa la responsabilidad: es probable que la función esté
haciendo varias cosas ({ref}`0x2005h`).

Además, agregar un parámetro obliga a editar todas las llamadas, y un `struct`
que agrupe los datos relacionados cambiaría la firma sin afectar a los
llamadores. La pila recibe más argumentos de los necesarios y el acoplamiento
crece.

### Consecuencia observable

Resultados incorrectos por argumentos intercambiados que el compilador no
detecta, y llamadas ilegibles que el docente no puede revisar de un vistazo. La
regla {ref}`0x200Bh` es el disparador: superar cuatro parámetros obliga a
modelar el conjunto.

## Fundamento en el estándar C11

La lista de parámetros de una función se declara en su prototipo y cada
parámetro tiene duración automática (§6.9.1). El estándar no impone un límite
de cantidad, pero el orden posicional es la única forma de asociarlos, lo que
hace frágil cualquier lista larga. Los arreglos se ajustan a punteros
(§6.7.6.3), de modo que "más parámetros" nunca es una solución de memoria,
solo de legibilidad.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
void crear_usuario(const char *nombre, const char *apellido, int edad,
                   int dni, const char *mail, const char *telefono);
```

### ✅ Código refactorizado

```c
struct usuario_t {
    const char *nombre;
    const char *apellido;
    int edad;
    int dni;
    const char *mail;
    const char *telefono;
};

void crear_usuario(const struct usuario_t *u);
```

## Errores típicos al compilar o ejecutar

```text
# No hay error de compilación: el bug es silencioso.
$ ./programa
usuario creado con dni=31 y edad=40123456   # argumentos intercambiados
```

## Checklist de verificación

- [ ] ¿La función supera los cuatro parámetros?
- [ ] ¿Los parámetros del mismo tipo podrían intercambiarse sin error?
- [ ] ¿Los datos que viajan juntos forman una entidad que puedo nombrar?
- [ ] ¿Puedo leer la llamada sin contar posiciones?

## Reglas relacionadas

* {ref}`0x200Bh` — regla que norma este defecto: máximo cuatro parámetros.
* {ref}`0x2005h` — parámetros de más suelen indicar responsabilidades de más.
* {ref}`0x3004h` — el `struct` que agrupa los datos se define con sufijo `_t`.
* {ref}`0x3007h` — el `struct` de solo lectura se pasa como `const`.
