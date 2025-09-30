---
title: Único Retorno
short_title: Refactorizacion - Único retorno
---

Para cumplir con el lineamiento de estilo de tener un solo punto de salida ***`return`*** en nuestras funciones, muchas veces vamos a tener que refactorizar nuestro código, de una forma distinta, dependiendo el caso. Lo que sigue es un resumen de los casos más frecuentes, y opciones de refactorización.

### Refactorización Básica

**Función Original:**

```c
int ejemplo(int x) {
    if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}
```

**Versión Refactorizada:**

```c
int ejemplo(int x) {
    int resultado = 0;
    if (x > 0) {
        resultado = 1;
    }
    return resultado;
}
```

---

### Bloques Condicionales (`if-else`)

#### Caso 1: `if-else` Simple

**Función Original:**

```c
int clasificar_numero(int n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    } else {
        return 0;
    }
}
```

**Versión Refactorizada:**

```c
int clasificar_numero(int n) {
    int resultado = 0;
    if (n > 0) {
        resultado = 1;
    } else if (n < 0) {
        resultado = -1;
    }
    return resultado;
}
```

En este caso, se puede inicializar `resultado` con el valor más común o por defecto, y luego asignar el valor dentro de cada rama condicional.

#### Caso 2: `if` dentro de un Bucle

**Función Original:**

```c
int encontrar_primer_par(int numeros[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0) {
            return numeros[i];
        }
    }
    return -1;
}
```

**Versión Refactorizada:**

```c
int encontrar_primer_par(int numeros[], int tam) {
    int resultado = -1;
    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0) {
            resultado = numeros[i];
            break;
        }
    }
    return resultado;
}
```

En este caso, se utiliza una declaración `break` para salir del bucle temprano, asignando el valor a `resultado` antes de hacerlo.

---

### Bucles (`for`, `while`)

#### Caso 1: Bucle con Salida Temprana

**Función Original:**

```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    for (int i = 0; i < tam; i++) {
        if (nums[i] == objetivo) {
            return true;
        }
    }
    return false;
}
```

**Versión Refactorizada:**

```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    bool encontrado = false;
    for (int i = 0; i < tam; i++) {
        if (nums[i] == objetivo) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}
```

Aquí, `encontrado` se inicializa en `false` y se actualiza si se encuentra el objetivo. El bucle se rompe inmediatamente después y se devuelve el resultado al final.

**Otra Versión Refactorizada:**

```c
bool contiene_objetivo(int nums[], int tam, int objetivo) {
    bool encontrado = false;
    for (int i = 0; i < tam && !encontrado; i++) {
        if (nums[i] == objetivo) {
            encontrado = true;
        }
    }
    return encontrado;
}
```


### Estructuras Anidadas

**Función Original:**

```c
const char* logica_compleja(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            return "Ambos positivos";
        } else {
            return "A positivo, B no positivo";
        }
    } else {
        return "A no positivo";
    }
}
```

**Versión Refactorizada:**

```c
const char* logica_compleja(int a, int b) {
    const char* resultado = "A no positivo";
    if (a > 0) {
        if (b > 0) {
            resultado = "Ambos positivos";
        } else {
            resultado = "A positivo, B no positivo";
        }
    }
    return resultado;
}
```

En condiciones anidadas, se inicializa `resultado` con el caso más general y se refina dentro de cada bloque condicional.

---

### Ejemplo con Procesamiento Posterior al Bucle y Uso de Bloque `if`

En este ejemplo, se muestra cómo refactorizar una función que realiza un procesamiento dentro de un bucle y, después del bucle, evalúa condiciones adicionales que podrían afectar el valor de retorno. La idea es asegurarse de que solo haya un `return` al final de la función, colocando el procesamiento posterior en un bloque `if`.

#### Función Original

```c
const char* analizar_datos(int datos[], int tam, int umbral) {
    for (int i = 0; i < tam; i++) {
        if (datos[i] > umbral) {
            return "Valor encontrado";
        }
    }
    
    if (tam == 0) {
        return "Sin datos";
    } else if (umbral < 0) {
        return "Umbral inválido";
    }
    
    return "Valor no encontrado";
}
```

#### Versión Refactorizada

```c
const char* analizar_datos(int datos[], int tam, int umbral) {
    const char* resultado = "Valor no encontrado";
    
    for (int i = 0; i < tam; i++) {
        if (datos[i] > umbral) {
            resultado = "Valor encontrado";
            break;
        }
    }
    
    if (resultado == "Valor no encontrado") {
        if (tam == 0) {
            resultado = "Sin datos";
        } else if (umbral < 0) {
            resultado = "Umbral inválido";
        }
    }
    
    return resultado;
}
```
