#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int valor = 0;
    FILE *archivo = fopen("archivo.txt", "w");
    scanf("%d", &valor);
    if (archivo == NULL)
    {
        perror("fopen() fallo");
    }
    else
    {
        fclose(archivo);
    }
}
