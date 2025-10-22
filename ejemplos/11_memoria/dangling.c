#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p_num = NULL;
    p_num = (int *)malloc(sizeof(int));
    
    if (p_num == NULL) {
        perror("Asignación de memoria:");
        return 1;
    }
    
    *p_num = 42;
    printf("Paso 1: El puntero apunta a la dirección %p.\n", (void *)p_num);
    printf("Paso 2: El valor en esa dirección es: %d\n\n", *p_num);

    printf("Paso 3: Liberando la memoria con free(p_num)...\n");
    free(p_num);
    
    // --- ¡PELIGRO! ---
    // En este punto, `p_num` se ha convertido en un "dangling pointer".
    // Todavía contiene la dirección de memoria anterior, pero ya no nos
    // pertenece y acceder a ella es un COMPORTAMIENTO INDEFINIDO.

    printf("Paso 4: p_num es ahora un puntero colgante (dangling pointer).\n");
    printf("         Todavía apunta a: %p, pero esta memoria ya no es nuestra.\n\n", (void *)p_num);

    // 5. Intentamos usar el puntero colgante (esto es un error grave).
    // El programa podría fallar (Segmentation fault), podría imprimir un valor
    // basura, o podría parecer que funciona (lo que es peor, porque el error está oculto).
    printf("Paso 5: Intentando acceder al puntero colgante (comportamiento indefinido)...\n");
    // La siguiente línea es peligrosa y no debe hacerse en código real.
    printf("         El valor en la memoria liberada podría ser: %d (¡valor basura o crash!)\n\n", *p_num);
    
    // --- SOLUCIÓN ---
    // 6. La buena práctica es establecer el puntero a NULL después de liberarlo.
    // Esto previene que se use accidentalmente.
    p_num = NULL;
    printf("Paso 6: Se establece el puntero a NULL para evitar su uso.\n");

    // 7. Ahora, si intentamos usar el puntero, podemos verificar si es nulo.
    if (p_num == NULL) {
        printf("         El puntero es %p, no se puede acceder a él.\n", p_num);
    } else {
        // Este código no se ejecutará.
        printf("Valor: %d\n", *p_num);
    }
    return 0;
}

