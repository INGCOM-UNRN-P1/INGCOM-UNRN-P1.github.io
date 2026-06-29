## Ejercicios sobre funciones

(funcion_doble)=
```{exercise}
:label: funcion_doble
Escribí una función que reciba un número entero y devuelva su doble. Probala desde `main()` con distintos valores.
```

:::{solution} funcion_doble
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int doble(int n) {
    return 2 * n;
}

int main() {
    printf("Doble de 5: %d\n", doble(5));
    printf("Doble de 12: %d\n", doble(12));
    return 0;
}
```
:::

:::{exercise}
:label: funcion_mayor
:enumerator: funciones-2

Programá una función que reciba dos números enteros y retorne el mayor de ellos.
```

:::{solution} funcion_mayor
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int mayor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 10;
    int y = 7;
    printf("El mayor es: %d\n", mayor(x, y));
    return 0;
}
```
:::

(funcion_par_impar)=
```{exercise}
:label: funcion_par_impar
Definí una función que indique si un número es par o impar. Mostrá el resultado llamando a la función desde `main()`.
```

:::{solution} funcion_par_impar
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

void par_impar(int n) {
    if (n % 2 == 0) {
        printf("%d es par\n", n);
    } else {
        printf("%d es impar\n", n);
    }
}

int main() {
    par_impar(7);
    par_impar(12);
    return 0;
}
```
:::

:::{exercise}
:label: funcion_promedio
:enumerator: funciones-4
Escribí una función que reciba tres notas enteras y devuelva el promedio en punto flotante. Mostrá el resultado en `main()`.
:::

:::{solution} funcion_promedio
:class: dropdown
```{code-block} c
:linenos:
#include <stdio.h>

float promedio(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

int main() {
    printf("Promedio: %.2f\n", promedio(7, 8, 10));
    return 0;
}
```
:::

:::{exercise}
:label: funcion_area
Implementá una función `area_rectangulo` que reciba base y altura, y devuelva el área.
:::

:::{solution} funcion_area
:class: dropdown

```{code-block} c
:linenos:
#include <stdio.h>

int area_rectangulo(int base, int altura) {
    return base * altura;
}

int main() {
    printf("Área: %d\n", area_rectangulo(5, 4));
    return 0;
}
```
:::