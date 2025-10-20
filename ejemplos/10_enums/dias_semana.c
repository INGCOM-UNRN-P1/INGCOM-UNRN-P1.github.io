// Uso práctico de enumeraciones: días de la semana

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
} DiaSemana;

// Retorna el nombre del día
const char *dia_a_cadena(DiaSemana dia) {
    switch (dia) {
        case LUNES:    return "Lunes";
        case MARTES:   return "Martes";
        case MIERCOLES: return "Miércoles";
        case JUEVES:   return "Jueves";
        case VIERNES:  return "Viernes";
        case SABADO:   return "Sábado";
        case DOMINGO:  return "Domingo";
        default:       return "Desconocido";
    }
}

// Verifica si es día laboral
bool es_dia_laboral(DiaSemana dia) {
    return dia >= LUNES && dia <= VIERNES;
}

// Retorna el siguiente día
DiaSemana dia_siguiente(DiaSemana dia) {
    return (dia + 1) % 7;
}

int main(void) {
    DiaSemana hoy = MIERCOLES;
    
    printf("Hoy es %s\n", dia_a_cadena(hoy));
    printf("¿Es día laboral? %s\n", es_dia_laboral(hoy) ? "Sí" : "No");
    
    DiaSemana manana = dia_siguiente(hoy);
    printf("Mañana es %s\n\n", dia_a_cadena(manana));
    
    // Recorrer toda la semana
    printf("Días de la semana:\n");
    for (DiaSemana dia = LUNES; dia <= DOMINGO; dia++) {
        printf("%s", dia_a_cadena(dia));
        if (es_dia_laboral(dia)) {
            printf(" (laboral)");
        }
        printf("\n");
    }
    
    return 0;
}
