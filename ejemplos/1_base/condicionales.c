// Estructuras de control condicionales

#include <stdio.h>

int main(void) {
    // if-else
    int numero = 15;
    printf("Evaluando número: %d\n", numero);
    
    if (numero > 0) {
        printf("El número es positivo\n");
    } else if (numero < 0) {
        printf("El número es negativo\n");
    } else {
        printf("El número es cero\n");
    }
    
    // Operador ternario
    char *paridad = (numero % 2 == 0) ? "par" : "impar";
    printf("El número es %s\n", paridad);
    
    // switch
    int dia = 3;
    printf("\nDía %d: ", dia);
    switch (dia) {
        case 1:
            printf("Lunes\n");
            break;
        case 2:
            printf("Martes\n");
            break;
        case 3:
            printf("Miércoles\n");
            break;
        case 4:
            printf("Jueves\n");
            break;
        case 5:
            printf("Viernes\n");
            break;
        case 6:
        case 7:
            printf("Fin de semana\n");
            break;
        default:
            printf("Día inválido\n");
    }
    
    return 0;
}
