#include <stdio.h>

unsigned long long ackermann(int m, int n){
    printf("%d/%d\n", n, m); 
    if ( m == 0 )
    {
        return n + 1;
    }
    else if ( ( m > 0 ) && ( n == 0 ) )
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}


int main()
{
    int n = 4;
    int m = 2;
    unsigned long long int resultado = ackermann(n, m);
    printf("n=%d, m=%d ackermann=%llu\n", n, m, resultado);
    return 0;
}
