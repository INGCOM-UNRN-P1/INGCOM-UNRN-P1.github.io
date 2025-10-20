// Macros del preprocesador

#include <stdio.h>

// Macros simples
#define PI 3.14159
#define MAX_BUFFER 1024
#define VERDADERO 1
#define FALSO 0

// Macros con parámetros
#define CUADRADO(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Macro multilínea
#define SWAP(a, b, tipo) do { \
    tipo temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

// Macros condicionales
#ifdef DEBUG
    #define LOG(msg) printf("DEBUG: %s\n", msg)
#else
    #define LOG(msg)
#endif

// Stringificación
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Concatenación
#define CONCAT(a, b) a##b

int main(void) {
    // Uso de constantes
    printf("PI = %f\n", PI);
    printf("MAX_BUFFER = %d\n\n", MAX_BUFFER);
    
    // Macros con parámetros
    int x = 5;
    printf("CUADRADO(%d) = %d\n", x, CUADRADO(x));
    
    int a = 10, b = 20;
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n\n", a, b, MIN(a, b));
    
    // SWAP
    printf("Antes: a = %d, b = %d\n", a, b);
    SWAP(a, b, int);
    printf("Después: a = %d, b = %d\n\n", a, b);
    
    // Stringificación
    printf("TOSTRING(100) = %s\n", TOSTRING(100));
    printf("TOSTRING(PI) = %s\n\n", TOSTRING(PI));
    
    // Concatenación
    int var1 = 10;
    int var2 = 20;
    printf("var1 = %d\n", var1);
    printf("CONCAT(var, 2) = %d\n\n", CONCAT(var, 2));
    
    // Información del compilador
    printf("Archivo: %s\n", __FILE__);
    printf("Línea: %d\n", __LINE__);
    printf("Fecha: %s\n", __DATE__);
    printf("Hora: %s\n", __TIME__);
    
    // Macro condicional
    LOG("Este mensaje solo aparece en modo DEBUG");
    
    return 0;
}
