#### Simular un `do...while` con `while` y `break`

Si por algún motivo no podés usar `do...while` (por ejemplo, en un lenguaje que no lo tiene), podés simularlo con `while (true)` y `break`:

```c
int clave;
while (1) { // bucle infinito
    printf("Ingresá la clave (123): ");
    scanf("%d", &clave);

    if (clave == 123) {
        break; // salgo del bucle si la clave es correcta
    }
}
```

:::{note} 
Esta técnica es útil para simular comportamientos de control, pero como toda solución con `break`, puede afectar la legibilidad si se abusa de ella. En ejercicios iniciales, se sugiere pensar primero si el `while` o `do...while` no pueden ser resolver el caso de forma más clara. 
:::
