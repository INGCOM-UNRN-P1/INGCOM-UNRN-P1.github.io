#include <stdio.h>

int main() {
    // Declaramos tres variables locales.
    // En muchos compiladores, se colocarán en la memoria (stack) de forma contigua,
    // aunque el orden exacto (ascendente o descendente) no está garantizado.
    int antes = 99;
    int objetivo = 10;
    int despues = 111;

    // Creamos un puntero que apunta a la variable 'objetivo'.
    int *puntero = &objetivo;

    printf("--- Valores Originales ---\n");
    printf("Valor de 'antes':    %d (en la dirección %p)\n", antes, &antes);
    printf("Valor de 'objetivo': %d (en la dirección %p)\n", objetivo, &objetivo);
    printf("Valor de 'despues':   %d (en la dirección %p)\n\n", despues, &despues);

    printf("--- Acceso con Aritmética de Punteros ---\n");
    // El puntero apunta a 'objetivo'.
    printf("El puntero apunta a *puntero: %d\n", *puntero);

    // ABUSO: Intentamos acceder al "vecino" en la dirección anterior.
    // p - 1 avanza (o retrocede) el puntero en sizeof(int) bytes.
    int valor_anterior_leido = *(puntero - 1);
    printf("Leído con *(puntero - 1):     %d\n", valor_anterior_leido);

    // ABUSO: Intentamos acceder al "vecino" en la dirección siguiente.
    int valor_siguiente_leido = *(puntero + 1);
    printf("Leído con *(puntero + 1):     %d\n\n", valor_siguiente_leido);


    printf("--- Modificación Abusiva con Punteros ---\n");
    printf("Modificando el 'vecino' anterior a 777...\n");
    *(puntero - 1) = 777; // Modificamos lo que creemos que es 'despues' o 'antes'

    printf("Modificando el 'vecino' siguiente a 555...\n");
    *(puntero + 1) = 555; // Modificamos lo que creemos que es 'antes' o 'despues'
    printf("\n");


    printf("--- Valores Finales (después del abuso) ---\n");
    printf("Valor de 'antes':    %d\n", antes);
    printf("Valor de 'objetivo': %d\n", objetivo);
    printf("Valor de 'despues':   %d\n", despues);


    return 0;
}
