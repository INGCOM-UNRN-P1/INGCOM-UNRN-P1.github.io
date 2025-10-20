// Calculadora RPN usando una pila

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PILA 100

typedef struct {
    double elementos[MAX_PILA];
    int tope;
} Pila;

void pila_inicializar(Pila *p) {
    p->tope = -1;
}

int pila_vacia(const Pila *p) {
    return p->tope == -1;
}

int pila_llena(const Pila *p) {
    return p->tope >= MAX_PILA - 1;
}

int pila_push(Pila *p, double valor) {
    if (pila_llena(p)) {
        return 0;
    }
    p->elementos[++(p->tope)] = valor;
    return 1;
}

int pila_pop(Pila *p, double *valor) {
    if (pila_vacia(p)) {
        return 0;
    }
    *valor = p->elementos[(p->tope)--];
    return 1;
}

// Calculadora RPN (Reverse Polish Notation)
// Ejemplo: "3 4 + 2 *" = (3 + 4) * 2 = 14
int evaluar_rpn(const char *expresion, double *resultado) {
    Pila pila;
    pila_inicializar(&pila);
    
    char *copia = strdup(expresion);
    char *token = strtok(copia, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Es un número
            double num = atof(token);
            pila_push(&pila, num);
        } else {
            // Es un operador
            double b, a;
            if (!pila_pop(&pila, &b) || !pila_pop(&pila, &a)) {
                free(copia);
                return 0;  // Error: no hay suficientes operandos
            }
            
            double res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': 
                    if (b == 0) {
                        free(copia);
                        return 0;  // División por cero
                    }
                    res = a / b;
                    break;
                default:
                    free(copia);
                    return 0;  // Operador no reconocido
            }
            
            pila_push(&pila, res);
        }
        
        token = strtok(NULL, " ");
    }
    
    free(copia);
    
    // Debe quedar exactamente un elemento en la pila
    if (pila.tope != 0) {
        return 0;
    }
    
    *resultado = pila.elementos[0];
    return 1;
}

int main(void) {
    printf("Calculadora RPN (Reverse Polish Notation)\n\n");
    
    const char *expresiones[] = {
        "3 4 +",           // 7
        "15 7 1 1 + - /",  // 3
        "5 1 2 + 4 * + 3 -", // 14
        "3 4 + 2 *"        // 14
    };
    
    int n = sizeof(expresiones) / sizeof(expresiones[0]);
    
    for (int i = 0; i < n; i++) {
        double resultado;
        printf("Expresión: %s\n", expresiones[i]);
        
        if (evaluar_rpn(expresiones[i], &resultado)) {
            printf("Resultado: %.2f\n\n", resultado);
        } else {
            printf("Error al evaluar\n\n");
        }
    }
    
    return 0;
}
