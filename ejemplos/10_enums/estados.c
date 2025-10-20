// Enumeraciones para máquinas de estado

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    APAGADO,
    ENCENDIDO,
    PAUSADO,
    ERROR
} EstadoDispositivo;

typedef struct {
    EstadoDispositivo estado;
    int temperatura;
} Dispositivo;

void inicializar_dispositivo(Dispositivo *disp) {
    disp->estado = APAGADO;
    disp->temperatura = 20;
}

bool encender(Dispositivo *disp) {
    if (disp->estado == APAGADO) {
        disp->estado = ENCENDIDO;
        printf("Dispositivo encendido\n");
        return true;
    }
    printf("No se puede encender desde el estado actual\n");
    return false;
}

bool pausar(Dispositivo *disp) {
    if (disp->estado == ENCENDIDO) {
        disp->estado = PAUSADO;
        printf("Dispositivo pausado\n");
        return true;
    }
    printf("Solo se puede pausar si está encendido\n");
    return false;
}

bool reanudar(Dispositivo *disp) {
    if (disp->estado == PAUSADO) {
        disp->estado = ENCENDIDO;
        printf("Dispositivo reanudado\n");
        return true;
    }
    printf("Solo se puede reanudar si está pausado\n");
    return false;
}

bool apagar(Dispositivo *disp) {
    if (disp->estado != APAGADO) {
        disp->estado = APAGADO;
        printf("Dispositivo apagado\n");
        return true;
    }
    printf("Ya está apagado\n");
    return false;
}

const char *estado_a_cadena(EstadoDispositivo estado) {
    switch (estado) {
        case APAGADO:   return "APAGADO";
        case ENCENDIDO: return "ENCENDIDO";
        case PAUSADO:   return "PAUSADO";
        case ERROR:     return "ERROR";
        default:        return "DESCONOCIDO";
    }
}

int main(void) {
    Dispositivo dispositivo;
    inicializar_dispositivo(&dispositivo);
    
    printf("Estado inicial: %s\n\n", estado_a_cadena(dispositivo.estado));
    
    encender(&dispositivo);
    printf("Estado: %s\n\n", estado_a_cadena(dispositivo.estado));
    
    pausar(&dispositivo);
    printf("Estado: %s\n\n", estado_a_cadena(dispositivo.estado));
    
    // Intento inválido
    encender(&dispositivo);
    printf("\n");
    
    reanudar(&dispositivo);
    printf("Estado: %s\n\n", estado_a_cadena(dispositivo.estado));
    
    apagar(&dispositivo);
    printf("Estado: %s\n", estado_a_cadena(dispositivo.estado));
    
    return 0;
}
