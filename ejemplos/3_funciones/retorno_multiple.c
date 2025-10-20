// Simulando retorno múltiple con punteros

#include <stdio.h>
#include <stdbool.h>

// Función que "retorna" múltiples valores mediante punteros
void division_entera(int dividendo, int divisor, int *cociente, int *resto) {
    *cociente = dividendo / divisor;
    *resto = dividendo % divisor;
}

// Función que valida y retorna resultado
bool raiz_cuadrada_entera(int n, int *resultado) {
    if (n < 0) {
        return false;  // No se puede calcular
    }
    
    // Búsqueda lineal simple
    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            *resultado = i;
            return true;
        }
    }
    
    return false;  // No es un cuadrado perfecto
}

// Función que encuentra mínimo y máximo
void min_max(int arr[], int n, int *minimo, int *maximo) {
    *minimo = arr[0];
    *maximo = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < *minimo) {
            *minimo = arr[i];
        }
        if (arr[i] > *maximo) {
            *maximo = arr[i];
        }
    }
}

int main(void) {
    // División entera con resto
    int cociente, resto;
    division_entera(17, 5, &cociente, &resto);
    printf("17 / 5 = %d (resto %d)\n\n", cociente, resto);
    
    // Validación con retorno booleano
    int raiz;
    if (raiz_cuadrada_entera(25, &raiz)) {
        printf("La raíz cuadrada de 25 es %d\n", raiz);
    }
    
    if (!raiz_cuadrada_entera(26, &raiz)) {
        printf("26 no es un cuadrado perfecto\n\n");
    }
    
    // Mínimo y máximo
    int numeros[] = {42, 15, 73, 8, 56, 29};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int min, max;
    
    min_max(numeros, n, &min, &max);
    printf("Arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nMínimo: %d, Máximo: %d\n", min, max);
    
    return 0;
}
