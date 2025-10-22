#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *direccion;
    const char *descripcion;
} informacion_t;

int compara_direcciones(const void *izq, const void *der) {
    const informacion_t *izquierda = (const informacion_t *)izq;
    const informacion_t *derecha = (const informacion_t *)der;
    
    // Comparación directa de los punteros, casteando a long long para un ordenamiento numérico.
    if ((long long)izquierda->direccion < (long long)derecha->direccion) {
        return -1;
    } else if ((long long)izquierda->direccion > (long long)derecha->direccion) {
        return 1;
    } else {
        return 0;
    }
}

void *obtener_direccion_estatica(void) {
    static int func_static = 100; 
    return (void *)&func_static;
}

int global = 20;
int global_no_inic;
const char *literal = "Cadena de solo lectura";

int main(void)
{
    int local = 30;
    static int estatica = 25;
    int *dinamica = (int *)malloc(sizeof(int));
    
    informacion_t direcciones[8]; 
    int count = 0;

    direcciones[count++] = (informacion_t){
        .direccion = (void *)main, 
        .descripcion = "Codigo (Segmento Text: main)"
    };
    
    direcciones[count++] = (informacion_t){
        .direccion = (void *)literal,
         .descripcion = "Cadena Literal (Segmento R/O Data)"
        };

    direcciones[count++] = (informacion_t){
        .direccion = (void *)&global,
        .descripcion = "global (Segmento Data)"
    };
    direcciones[count++] = (informacion_t){
        .direccion = (void *)&estatica,
        .descripcion = "estatica global (Segmento Data)"
    };
    
    direcciones[count++] = (informacion_t){
        .direccion = obtener_direccion_estatica(),
        .descripcion = "estatica de funcion (Segmento Data)"
    };
    
    direcciones[count++] = (informacion_t){
        .direccion = (void *)&global_no_inic,
        .descripcion = "global_no_inicializada (Segmento BSS)"
    };
    
    if (dinamica != NULL)
    {
        *dinamica = 76;
        direcciones[count++] = (informacion_t){
            .direccion = (void *)dinamica, 
            .descripcion = "dinamica (Segmento Heap)"
        };
    }
    
    direcciones[count++] = (informacion_t){
        .direccion = (void *)&local,
        .descripcion = "local (Segmento Stack)"
    };

    if (count > 0) {
        qsort(direcciones, count, sizeof(informacion_t), compara_direcciones);

        printf("Direcciones de memoria ordenadas:\n");
        printf("---------------------------------\n");
        
        for (int i = count - 1 ; i >= 0; i--) {
            printf("%-40s: %p\n", direcciones[i].descripcion, direcciones[i].direccion);
        }
        
        if (dinamica != NULL) {
            free(dinamica);
        }
    } else {
        fprintf(stderr, "Error: No se pudieron recolectar direcciones.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
