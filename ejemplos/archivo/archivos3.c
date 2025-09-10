#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo = fopen("archivo.txt", "w");
    if (archivo != NULL)
    {
        int caracteres_escritos = fprintf(archivo, "Esto es un mensaje.");
        if (caracteres_escritos < 0)
        {
            perror("Error al escribir en el archivo");
        }
        fclose(archivo);
    }
    else
    {
        perror("Error al abrir el archivo");
    }
}