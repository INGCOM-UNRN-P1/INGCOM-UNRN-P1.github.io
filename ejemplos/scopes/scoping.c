 
#include <stdio.h>

int main()
{
    int a = 10;
    printf("1 - %d\n",a);
    for(int i = 0 ; i < 3 ; i++)
    {
        a++;
        printf("A - %d\n",a);
        int a = 15;
        printf("B - %d\n",a);
        a++;
    }
    printf("2 - %d\n",a);
    return 0;
}