#include <stdio.h>
#include <stdlib.h>

/*
 * Esta estructura se utiliza para recolectar las direcciones de los
 * diferentes objetos en memoria en diferentes lugares.
 */
typedef struct {
  void *direccion;
  const char *descripcion;
} info_direccion_t;

/*
 * Esta función genérica es necesaria para utilizar qsort de la STDLIB.
 * Utiliza punteros genéricos, pero la verdadera mágia la hace `qsort` al
 * recibir un puntero a esta función.
 * 	(si dá el tiempo, vamos a ver este tema)
 */
int compara_direcciones(const void *izquierdo, const void *derecho) {
  const info_direccion_t *info_a = (const info_direccion_t *)izquierdo;
  const info_direccion_t *info_b = (const info_direccion_t *)derecho;

  // Comparación directa de los punteros, casteando a long long para un
  // ordenamiento numérico.
  int retorno = 0;
  if ((long long)info_a->direccion < (long long)info_b->direccion) {
    retorno = -1;
  } else if ((long long)info_a->direccion > (long long)info_b->direccion) {
    retorno = 1;
  } else {
    retorno = 0;
  }
  return retorno;
}

/**
 * Esta funcion nos da la direccion de memoria a una variable local estática
 * (como solo nos interesa la dirección, devolvemos como void)
 */
// Funció n que contiene una variable estática local
void *obtiene_direccion_estatica(void) {
  // La variable estática de función reside en el Segmento Data/BSS (si no se
  // inicializa) En este caso, al estar inicializada, va al Segmento Data.
  static int func_static = 100;
  return (void *)&func_static;
}

int global = 20;
int global_no_inicializada;
const char *literal = "Cadena de solo lectura";

int main(void) {
  int local = 30;
  static int estatica = 25; // Estática global-scope (Segmento Data)
  int *dinamica = (int *)malloc(sizeof(int));

  // Un para cada uno de los tipos de objeto en memoria a analizar.
  info_direccion_t direcciones[8];
  int contador = 0;

  // 1. Segmento de Código (Text Segment)
  direcciones[contador++] = (info_direccion_t){
                    .direccion = (void *)main,
                    .descripcion = "Codigo (Segmento Text: main)"
                };

  // 2. Segmento de Datos de Solo Lectura (R/O Data Segment)
  direcciones[contador++] =
      (info_direccion_t){
                    .direccion = (void *)literal,
                    .descripcion = "Cadena Literal (Segmento R/O Data)"
                };

  // 3. Segmento de Datos Inicializados (Data Segment)
  direcciones[contador++] = (info_direccion_t){
                    .direccion = (void *)&global,
                    .descripcion = "global (Segmento Data)"
                };
  
  // 4. Variable estática global (Segmento Data)      
  direcciones[contador++] =
      (info_direccion_t){
                    .direccion = (void *)&estatica,
                    .descripcion = "estatica global (Segmento Data)"
                };

  // 5. Variable estática dentro de función (Segmento Data)
  direcciones[contador++] =
      (info_direccion_t){
                    .direccion = obtiene_direccion_estatica(),
                    .descripcion = "estatica de funcion (Segmento Data)"
                };

  // 6. Segmento BSS
  direcciones[contador++] = (info_direccion_t){
                    .direccion = (void *)&global_no_inicializada,
                    .descripcion = "global_no_inicializada (Segmento BSS)"
                };

  if (dinamica != NULL) {
    *dinamica = 76;
    // 7. Segmento Heap
    direcciones[contador++] = (info_direccion_t){
                    .direccion = (void *)dinamica,
                    .descripcion = "dinamica (Segmento Heap)"
                };
  }

  // 8. Segmento Stack
  direcciones[contador++] = (info_direccion_t){
                    .direccion = (void *)&local,
                    .descripcion = "local (Segmento Stack)"
                };

  // Direcciones recopiladas, ahora ordenamos e imprimimos

  if (contador > 0) {
    // Ordenación
    qsort(direcciones, contador, sizeof(info_direccion_t), compara_direcciones);

    printf("Direcciones de memoria de todos los segmentos ordenadas:\n");
    printf("--------------------------------------------------------\n");

    // Impresión de resultados (invertidos, así se parece mas al diagrama de la
    // presentación)
    for (int i = contador - 1; i >= 0; i--) {
      printf("%-40s: %p\n", direcciones[i].descripcion,
             direcciones[i].direccion);
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
