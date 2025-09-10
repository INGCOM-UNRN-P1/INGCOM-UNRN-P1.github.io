#include <stdio.h>
#include <stdlib.h>

void imprimidor(const char lacadena[], const size_t capacidad)
{
	int i = 0;
	int bandera = 1;
	while (i<capacidad && bandera)
	{
    	printf("%d%c, ",i, lacadena[i]);
    	if (lacadena[i] == '\0')
    	{
	    	bandera = 0;
    	}
    	i++;
    }
    printf("\n");
}

int main()
{
    char cad[] = "Hola Mundo!";
    size_t size = sizeof(cad) / sizeof(cad[0]);
    imprimidor(cad, size);
    return 0;
}

