// Operaciones de tiempo constante - O(1)
// Demuestra complejidad constante

#include <stdio.h>

// Acceso a un elemento por índice - O(1)
int obtener_elemento(int arreglo[], int indice) {
    return arreglo[indice];
}

// Asignación - O(1)
void asignar_elemento(int arreglo[], int indice, int valor) {
    arreglo[indice] = valor;
}

// Operación aritmética - O(1)
int suma_simple(int a, int b) {
    return a + b;
}

int main(void) {
    int numeros[] = {10, 20, 30, 40, 50};
    
    // Acceso directo - siempre toma el mismo tiempo
    printf("Elemento en índice 2: %d\n", obtener_elemento(numeros, 2));
    
    // Modificación directa
    asignar_elemento(numeros, 3, 100);
    printf("Elemento modificado en índice 3: %d\n", numeros[3]);
    
    // Operación aritmética simple
    int resultado = suma_simple(15, 25);
    printf("Suma: %d\n", resultado);
    
    // Todas estas operaciones toman tiempo constante,
    // sin importar el tamaño del arreglo
    
    return 0;
}
