// Comparación de complejidades
// Visualiza el crecimiento de diferentes complejidades

#include <stdio.h>
#include <math.h>

void comparar_complejidades(int n) {
    printf("\nPara n = %d:\n", n);
    printf("O(1):        %d operaciones\n", 1);
    printf("O(log n):    %.0f operaciones\n", log2(n));
    printf("O(n):        %d operaciones\n", n);
    printf("O(n log n):  %.0f operaciones\n", n * log2(n));
    printf("O(n²):       %d operaciones\n", n * n);
    printf("O(2^n):      %.0f operaciones\n", pow(2, n < 20 ? n : 20));
}

int main(void) {
    printf("Comparación de Complejidades Algorítmicas\n");
    printf("==========================================\n");
    
    comparar_complejidades(10);
    comparar_complejidades(100);
    comparar_complejidades(1000);
    comparar_complejidades(10000);
    
    printf("\nNota: O(2^n) limitado a n=20 para evitar overflow\n");
    
    return 0;
}
