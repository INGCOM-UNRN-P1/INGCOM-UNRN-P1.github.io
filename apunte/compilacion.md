---
title: Compilación
short_title: 5 - Compilación
subtitle: Haciendonos entender por la computadora.
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
