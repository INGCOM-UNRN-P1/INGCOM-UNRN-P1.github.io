// Implementación de funciones matemáticas

#include "matematica.h"

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

double dividir(int a, int b) {
    if (b == 0) {
        return 0.0;  // En una implementación real, manejar el error apropiadamente
    }
    return (double)a / b;
}
