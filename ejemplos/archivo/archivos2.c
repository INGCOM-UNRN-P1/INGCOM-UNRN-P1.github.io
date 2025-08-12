#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    strtonum();
    FILE *archivo = fopen("sololectura.txt", "w");
    if (archivo == NULL)
    {
        printf("%d - %s\n", errno, strerror(errno));
        perror("fopen() fallo");
    }
    else
    {
        fclose(archivo);
    }
}
