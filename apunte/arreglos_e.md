

















## Funciones puras y control de efectos en C

Cuando se trabaja con funciones que operan sobre arreglos, es fundamental
distinguir entre **funciones puras** y **funciones con efectos secundarios**.
Esta diferenciación permite mejorar la legibilidad del código, facilitar la
depuración y promover una programación más confiable.

### ¿Qué es una función pura?

Una **función pura** es aquella que:

1. **No modifica** ningún estado externo (ni variables globales, ni parámetros
   de entrada).
2. **Siempre retorna el mismo resultado** ante los mismos argumentos.

En otras palabras, su ejecución es predecible y no depende del contexto.

Ejemplo de función pura:

```c
int maximo(int valores[], int cantidad) 
{
    int max = valores[0];
    for (int i = 1; i < cantidad; i++) 
    {
        if (valores[i] > max) 
        {
            max = valores[i];
        }
    }
    return max;
}
```

Esta función sólo **lee** el contenido del arreglo y **devuelve** un resultado.
No altera el contenido original.

### ¿Qué es una función con efectos secundarios?

Una **función con efectos secundarios** es aquella que **modifica** el estado
del programa más allá de sus variables locales: puede cambiar variables
externas, parámetros pasados por referencia, escribir en pantalla, leer entrada,
etc.

Ejemplo:

```c
void ordenar(int v[], int cantidad) 
{
    for (int i = 0; i < cantidad - 1; i++) 
    {
        for (int j = 0; j < cantidad - i - 1; j++) 
        {
            if (v[j] > v[j + 1]) 
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
```

Esta función cambia el contenido del arreglo original: su ejecución **no es
inocua**.

### ¿Por qué distinguirlas?

- **Legibilidad**: un lector puede asumir que una función pura no altera nada,
  lo que simplifica su comprensión.
- **Reutilización**: las funciones puras son más fáciles de testear y componer.
- **Depuración**: los errores son más fáciles de rastrear si las funciones
  tienen efectos bien delimitados.

### Buenas prácticas

- Usá funciones puras para cálculo, conteo o análisis.
- Reservá funciones con efectos para inicialización, transformación explícita o
  interacción con el entorno.
- Documentá claramente qué efectos tiene cada función.
- Cuando una función modifica su entrada, elegí un nombre que lo indique:
  `normalizar`, `ordenar`, `ajustar`, etc.

### Estrategia mixta

En algunos casos, puede ser útil definir **una función pura** que calcule un
resultado y **otra función con efectos** que lo aplique.

Por ejemplo:

```c
int encontrar_maximo(int v[], int cantidad);
void imprimir_maximo(int v[], int cantidad) 
{
    int m = encontrar_maximo(v, cantidad);
    printf("El máximo es %d\n", m);
}
```

Esta separación permite testear `encontrar_maximo` independientemente de la
función que interactúa con el usuario.

---

**Conclusión:**

La claridad y la mantenibilidad del código aumentan significativamente cuando
los efectos secundarios están acotados. En C, donde el lenguaje permite
modificar estructuras con facilidad, es responsabilidad del programador decidir
cuándo hacerlo y comunicarlo de manera explícita.
