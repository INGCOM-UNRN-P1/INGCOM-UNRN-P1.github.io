#include <stdio.h>

int main()
{

int val = 10;
int val2 = 20;
const int* const ptr = &val; // Puntero constante a un int constante

// Ejemplo 1: No se puede modificar el valor a través del puntero
 *ptr = 15; // Esto daría un error de compilación ❌

// Ejemplo 2: No se puede reasignar el puntero
//ptr = &val2; // Esto daría un error de compilación ❌
    return 0;
}
