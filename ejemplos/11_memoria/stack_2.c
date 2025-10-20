#include <stdio.h>

long func_2(int a, long b);

int func_1(int a, int b, long c)
{
    int m;
    int n;
    m = m + a;
    n = n + b;
//    printf("a=%d - b=%d - c=%d\n", a, b, c);
    printf("m=%d - n=%d\n", m, n);
    return a+b+c;
}

long func_2(int a, long b)
{
    int x;
    long y;
    x = x + a;
    y = y + b;
//    printf("a=%d - b=%ld\n", a, b);
//    printf("x=%d - y=%ld\n", x, y);
    return b + a;
}


int main()
{
    int uno = 2;
    int dos = 10;
    int tres = 100;
    long cuatro;

    int calculo_uno;
    long calculo_dos;
    
    calculo_uno = func_1(uno, dos, tres);
    calculo_dos = func_2(uno, cuatro);
    calculo_uno = func_1(uno, dos, tres);

    
//    calculo_dos = func_2(uno, cuatro);

    printf("calculo_uno=%d\n", calculo_uno);
//    printf("calculo_uno=%d, calculo_dos=%ld\n", calculo_uno, calculo_dos);
    

}
