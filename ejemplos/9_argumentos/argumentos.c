#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

void implacable(char *cadena, size_t capacidad)
{
    size_t i = 0;
    while (i < capacidad){
        if (isalnum(*(cadena + i)))
        {
            putchar(*(cadena + i));
        }
        else
        {
            putchar('_');
        }
        i++;
    }
}

int main(int argc, char* argv[]){
    int i = 0;
    implacable(argv[0], 500);
    if (argc < 2){
        printf("falta un argumento!, se esperan 2\n");
    }
    else
    {
        errno = 0;
        char *fin;
        long numero = strtol(argv[1], &fin, 10);
        printf("el numero es %ld\n", numero);
        printf("--%s--\n", fin);
        if (fin == argv[1])
        {
            printf("no convirtio nada\n");
        }
    }
    printf("hay %d argumentos\n", argc);
    while (i < argc)
    {
        printf("%d - %s\n", i, argv[i]);
        i++;
    }
    return 0;
}
