#include <stdio.h>

void indirecto(char **doble, char **cadena)
{
    *doble = *cadena;
    return 10;
}

int main()
{
    char cad[] = "HolaHola";
    char otro[] = "ChauChau";


    char *a = cad;
    char *b = otro;

    printf("cad: <%s> - otro<%s>\n", cad, otro);
    indirecto(&a, &b);
    printf("cad: <%s> - otro<%s>\n", cad, otro);
    return 0;
}
