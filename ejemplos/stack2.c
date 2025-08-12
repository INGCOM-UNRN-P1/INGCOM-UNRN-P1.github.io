#include <stdio.h>

char* puntero_a_cadena()
{
	char cadena[] = "hola mundo";
	return cadena;
}

int main()
{
    char *puntero = puntero_a_cadena();
    printf("<%s>\n", puntero); 
}
