#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (i < argc)
    {
        printf("el argumento %d es <%s>\n", i, argv[i]);
        i = i + 1;
    }
    return 0;
}
