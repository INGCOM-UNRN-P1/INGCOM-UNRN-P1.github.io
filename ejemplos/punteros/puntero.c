#include <stdio.h>

int funcion(int sz, int arr[sz])
{
    printf("size%ld / %ld\n", sizeof(arr), sizeof(arr[0]));
}

int main()
{
int arr[10] = {1};

int a = 5;
int b = 10;
const int *const ptr = &a;

printf("%ld\n", sizeof(ptr));

//ptr = &b; // Error: No se puede cambiar la dirección a la que apunta 'ptr'.
//*ptr = 20; // Correcto: Se puede modificar el valor de 'a' a través de 'ptr'.

}
