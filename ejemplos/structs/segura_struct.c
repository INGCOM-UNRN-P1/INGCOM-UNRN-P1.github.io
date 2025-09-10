#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int capacidad;
    char* cadena;
}cadena_t;

cadena_t* crear(int capacidad)
{
    cadena_t *retorno;
    retorno = (cadena_t*) malloc(sizeof(cadena_t));
    (*retorno).cadena = (char*) malloc(sizeof(char)*capacidad);
    retorno->capacidad = capacidad;
    return retorno;
}

void liberar(cadena_t *segura)
{
    free(segura->cadena);
    free(segura);
}

enum semana {LUNES = -10, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

typedef enum Error {
...
}error_t;

int main()
{
    enum semana dia = MIERCOLES;
    printf("%d\n", dia);
    int numero = DOMINGO;

}

