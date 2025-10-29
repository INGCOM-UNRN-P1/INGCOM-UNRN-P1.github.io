---
title: Único Retorno
short_title: Único retorno
---

## Motivación

Con el objetivo de mejorar la legibilidad del código en C que desarrollamos, es importante plantear nuestros programas con un único punto de salida. Esto se logra empleando una sola vez la instrucción `return` por función.

### Mantenibilidad del código

Tener un solo punto de salida en una función facilita la lectura y comprensión del código. Cuando un desarrollador revisa una función, sabe que todo el flujo lógico de la misma converge hacia un único lugar donde se termina la ejecución y se devuelve un valor.

Esto es especialmente útil en funciones largas o complejas, donde múltiples `return` pueden dificultar el seguimiento del flujo de ejecución.

### Depuración más sencilla

Durante el proceso de depuración, es más sencillo poner un punto de ruptura (breakpoint) en un único `return` para inspeccionar el estado final de la función. Con múltiples `return`, se requeriría establecer varios puntos de ruptura o realizar pasos adicionales para entender cuál de ellos se alcanzó.

### Manejo uniforme de recursos

En funciones que manejan recursos como memoria dinámica, archivos abiertos, o conexiones de red, tener un único `return` permite asegurarse de que todos los recursos se liberen adecuadamente antes de que la función termine. Esto previene fugas de memoria y asegura que los recursos se cierren de manera ordenada.

Con múltiples `return`, el riesgo de olvidarse de liberar algún recurso antes de la salida de la función aumenta considerablemente.

### Legibilidad y claridad

El uso de un único `return` también refuerza una estructura clara de la función. El código se organiza de manera que todas las condiciones y acciones necesarias se resuelvan antes de llegar al punto de retorno. Esto fomenta un estilo de programación más estructurado y predecible.

### Contrapunto

Hay casos donde múltiples `return` pueden parecer más naturales o eficientes, especialmente en funciones muy cortas o en situaciones donde un error se detecta tempranamente. Sin embargo, en esos casos, es importante evaluar si la simplicidad del código justifica romper la regla general y asegurarse de que no afectará la mantenibilidad a largo plazo.

## Refactorización

La refactorización es el proceso de modificar la estructura interna de un código existente sin alterar su comportamiento externo. El objetivo principal de la refactorización es mejorar la calidad del código, haciéndolo más legible, mantenible y extensible. Este proceso se realiza de manera gradual y controlada para evitar la introducción de errores.

De esta forma, la mejor forma de llevarlo a cabo es luego de que tenemos implementadas pruebas unitarias de forma que podemos garantizar que el código no modifica su comportamiento.

:::{important}
El patrón de único retorno es una práctica de programación que establece que cada función debe tener exactamente un punto de salida (un solo `return`). Esta regla tiene profundas implicaciones en la estructura, legibilidad y mantenibilidad del código.

**Beneficios principales:**
- Depuración simplificada: Un solo punto para colocar breakpoints de salida
- Mantenimiento de invariantes: Garantiza que el cleanup y validaciones finales siempre se ejecuten
- Flujo de control predecible: Elimina salidas tempranas que pueden saltear lógica importante
- Código más estructurado: Fuerza una organización más clara de la lógica de la función
:::

## Casos de Refactorización

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

:::{note}
La técnica fundamental consiste en declarar una variable auxiliar `resultado` al inicio de la función, inicializándola con el valor por defecto o más común, y luego asignar valores según las condiciones evaluadas.
:::

#### Retorno directo

Para casos simples como el anterior, cuando trabajamos con expresiones booleanas, podemos aprovechar que los operadores relacionales en C dan un valor de tipo `int` directamente:

```c
int ejemplo(int x) {
    return x > 0;
}
```

Esta forma es más concisa y mantiene un único retorno.

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

:::{tip}
En pos de que los cambios en el código sean mínimos, la estructura debiera de cambiar lo menos posible. Se puede inicializar `resultado` con el valor del caso `else` para ahorrarse esa rama condicional. Sin embargo, el uso de valores "imposibles" (como `9999` en un caso donde los valores válidos son `-1`, `0`, `1`) hace más fácil detectar problemas estructurales en los condicionales más complejos.
:::

#### Caso 2: `if` dentro de un Lazo

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

En este caso, se utiliza una declaración `break` para salir del lazo temprano, asignando el valor a `resultado` antes de hacerlo.

---

### Lazos (`for`, `while`)

#### Caso 1: Lazo con Salida Temprana

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

Aquí, `encontrado` se inicializa en `false` y se actualiza si se encuentra el objetivo. El lazo se rompe inmediatamente después y se devuelve el resultado al final.

#### Versión alternativa: Condición en el lazo

En lugar de usar `break`, se puede incluir la condición directamente en el lazo:

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

Esta variante evita el uso de `break` y hace que la condición de salida del lazo sea más explícita.

---

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

### Procesamiento Posterior al Lazo

En este ejemplo, se muestra cómo refactorizar una función que realiza un procesamiento dentro de un lazo y, después del lazo, evalúa condiciones adicionales que podrían afectar el valor de retorno. La idea es asegurarse de que solo haya un `return` al final de la función, colocando el procesamiento posterior en un bloque `if`.

**Función Original:**

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

**Versión Refactorizada:**

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

:::{important}
La clave en este patrón es realizar el procesamiento posterior dentro de un bloque condicional que verifique si el resultado no fue modificado durante el lazo. Esto permite manejar múltiples casos de error o validación después de la búsqueda principal.
:::

---

## Casos Avanzados

### Lazos Anidados con Múltiples Condiciones de Salida

Cuando trabajamos con lazos anidados, mantener un único retorno requiere técnicas más sofisticadas.

**Función Original:**

```c
int buscar_en_matriz(int matriz[][10], int filas, int cols, int objetivo) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if (matriz[i][j] == objetivo) {
                return 1;
            }
        }
    }
    return 0;
}
```

**Versión Refactorizada con variable de control:**

```c
int buscar_en_matriz(int matriz[][10], int filas, int cols, int objetivo) {
    int encontrado = 0;
    
    for (int i = 0; i < filas && !encontrado; i++) {
        for (int j = 0; j < cols && !encontrado; j++) {
            if (matriz[i][j] == objetivo) {
                encontrado = 1;
            }
        }
    }
    
    return encontrado;
}
```

### Gestión de Recursos con Limpieza

Una ventaja crítica del patrón de único retorno es la gestión segura de recursos.

**Función Original:**

```c
int procesar_archivo(const char* nombre) {
    FILE* archivo = fopen(nombre, "r");
    if (archivo == NULL) {
        return -1;
    }
    
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), archivo) == NULL) {
        fclose(archivo);  // Repetición de limpieza
        return -2;
    }
    
    if (procesar_datos(buffer) != 0) {
        fclose(archivo);  // Repetición de limpieza
        return -3;
    }
    
    fclose(archivo);
    return 0;
}
```

**Versión Refactorizada:**

```c
int procesar_archivo(const char* nombre) {
    int resultado = 0;
    FILE* archivo = fopen(nombre, "r");
    
    if (archivo == NULL) {
        resultado = -1;
    } else {
        char buffer[100];
        
        if (fgets(buffer, sizeof(buffer), archivo) == NULL) {
            resultado = -2;
        } else if (procesar_datos(buffer) != 0) {
            resultado = -3;
        }
        
        fclose(archivo);  // Limpieza en un solo lugar
    }
    
    return resultado;
}
```

:::{tip}
Esta técnica asegura que los recursos siempre se liberen correctamente, independientemente del camino de ejecución. Con múltiples `return`, es fácil olvidar liberar recursos en alguna de las salidas.
:::

### Procesamiento por Fases

Para funciones complejas que realizan múltiples operaciones, organizar el código en fases claramente delimitadas mejora la legibilidad.

**Versión Refactorizada:**

```c
int procesar_datos_complejos(int* numeros, int tam, double* promedio, int* maximo) {
    int resultado = -1;  // Valor de error por defecto

    // Fase 1: Validación
    if (numeros != NULL && tam > 0) {
        // Fase 2: Cálculo principal
        long suma = 0;
        int max = numeros[0];

        for (int i = 0; i < tam; i++) {
            suma += numeros[i];
            if (numeros[i] > max) {
                max = numeros[i];
            }
        }

        // Fase 3: Asignación de resultados
        if (promedio != NULL) {
            *promedio = (double)suma / tam;
        }
        if (maximo != NULL) {
            *maximo = max;
        }

        resultado = 0;  // Éxito
    }

    return resultado;
}
```

### Funciones de Búsqueda con Índice

**Función Original:**

```c
int buscar_indice(int* arreglo, int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arreglo[i] == valor) {
            return i;
        }
    }
    return -1;
}
```

**Versión Refactorizada:**

```c
int buscar_indice(int* arreglo, int tam, int valor) {
    int indice = -1;
    
    for (int i = 0; i < tam && indice == -1; i++) {
        if (arreglo[i] == valor) {
            indice = i;
        }
    }
    
    return indice;
}
```

---

## Consideraciones Especiales

### Funciones Muy Simples

Para funciones extremadamente simples, el patrón de único retorno puede parecer verboso:

```c
// Función simple - múltiples retornos
bool es_par(int numero) {
    return numero % 2 == 0;
}

// Versión con único retorno (consistente pero más verbosa)
bool es_par_consistente(int numero) {
    bool resultado = false;
    
    if (numero % 2 == 0) {
        resultado = true;
    }
    
    return resultado;
}
```

Sin embargo, mantener la consistencia en todo el código facilita su lectura y mantenimiento, especialmente en proyectos donde colaboran múltiples desarrolladores.

### Operador Ternario

Para asignaciones condicionales simples, el operador ternario puede ser útil manteniendo el único retorno:

```c
int maximo(int a, int b) {
    int resultado = (a > b) ? a : b;
    return resultado;
}

// O más concisamente
int maximo(int a, int b) {
    return (a > b) ? a : b;
}
```

---

## Resumen

El patrón de único retorno se implementa mediante:

1. **Variable de resultado:** Declarar una variable al inicio que almacenará el valor a retornar
2. **Inicialización apropiada:** Asignar un valor por defecto o de error a la variable
3. **Asignaciones condicionales:** Modificar el resultado según las condiciones evaluadas
4. **Control de flujo:** Usar `break` o condiciones en lazos para salir temprano sin `return`
5. **Limpieza centralizada:** Colocar la liberación de recursos antes del único `return`
6. **Organización por fases:** Estructurar funciones complejas en bloques lógicos secuenciales

La refactorización hacia este patrón mejora la mantenibilidad, facilita la depuración y reduce errores relacionados con la gestión de recursos, especialmente en código complejo o de larga duración.

