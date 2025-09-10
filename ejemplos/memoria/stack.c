
#include <stdio.h>

int* funcionA() {
    int a[10];
    return &a;
}

void funcionB() {
    long int b;
    printf("En funcionB, variable 'b' sin inicializar: %ld\n", b);
    b = 20;
}

void funcionC() {
    short int c;
    printf("En funcionC, variable 'c' sin inicializar: %hd\n", c);
    c = 30;
}

void funcionD() {
    int d;
    printf("En funcionD, variable 'd' sin inicializar: %d\n", d);
}
int main()
{
    funcionA();
    funcionB();
//    funcionC();
    int *b = funcionA();
    b[0] = 10;
    printf("%d\n", b);
    funcionD();
}
