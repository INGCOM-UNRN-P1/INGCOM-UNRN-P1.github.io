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
