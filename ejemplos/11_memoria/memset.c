#include <string.h>
#include <stdio.h>

int main()
{
    char str[] = "ghghghghghghghghghghgh";
    puts(str);
    memset(str,'a',35);
    puts(str);
    return 0;
}
