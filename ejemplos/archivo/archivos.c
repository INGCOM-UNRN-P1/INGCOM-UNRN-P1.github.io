#include <stdio.h>
#include <errno.h>

#include <string.h>

int main()
{
    FILE* archivo_1 = fopen("lectura","r");
    if (archivo_1 == NULL)
    {
        int error = errno;
        perror("Al abrir lectura");
        
        printf("errno:%d -- %s\n", error, strerror(errno));
        error = errno;
        printf("errno:%d\n", error);

    }
    while(!feof(archivo_1))
    {
      char c = fgetc(archivo_1);
      
      printf(", %c/%u", c, c);
    }
    printf("\n FIN\n");
}
