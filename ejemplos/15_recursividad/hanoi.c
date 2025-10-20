// Torres de Hanoi - Ejemplo clásico de recursión

#include <stdio.h>

// Contador de movimientos
static int movimientos = 0;

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        movimientos++;
        printf("Movimiento %d: Mover disco 1 de %c a %c\n", 
               movimientos, origen, destino);
        return;
    }
    
    // Mover n-1 discos de origen a auxiliar usando destino
    hanoi(n - 1, origen, auxiliar, destino);
    
    // Mover el disco más grande de origen a destino
    movimientos++;
    printf("Movimiento %d: Mover disco %d de %c a %c\n", 
           movimientos, n, origen, destino);
    
    // Mover n-1 discos de auxiliar a destino usando origen
    hanoi(n - 1, auxiliar, destino, origen);
}

int main(void) {
    int n = 3;
    
    printf("Torres de Hanoi con %d discos\n", n);
    printf("=============================\n\n");
    
    hanoi(n, 'A', 'C', 'B');
    
    printf("\nTotal de movimientos: %d\n", movimientos);
    printf("Fórmula: 2^n - 1 = 2^%d - 1 = %d\n", n, (1 << n) - 1);
    
    return 0;
}
