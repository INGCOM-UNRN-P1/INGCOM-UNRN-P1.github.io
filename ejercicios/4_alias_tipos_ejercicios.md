---

### Ejercicios

```{exercise}
:label: enum_basico
:enumerator: enums-1

Definí una enumeración para representar los días de la semana.
Escribí una función que reciba un día y retorne si es día laboral
o fin de semana. Incluí validación para valores inválidos.
```

````{solution} enum_basico
:class: dropdown

```{code-block}c
:linenos:
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO,
    DIA_INVALIDO
} dia_semana_t;

typedef enum {
    DIA_LABORAL,
    FIN_DE_SEMANA,
    ERROR_DIA_INVALIDO
} tipo_dia_t;

tipo_dia_t clasificar_dia(dia_semana_t dia) {
    switch (dia) {
        case LUNES:
        case MARTES:
        case MIERCOLES:
        case JUEVES:
        case VIERNES:
            return DIA_LABORAL;
        case SABADO:
        case DOMINGO:
            return FIN_DE_SEMANA;
        default:
            return ERROR_DIA_INVALIDO;
    }
}

const char *dia_a_string(dia_semana_t dia) {
    static const char *nombres[] = {
        "Lunes", "Martes", "Miércoles", "Jueves",
        "Viernes", "Sábado", "Domingo"
    };

    if (dia < 0 || dia >= DIA_INVALIDO) {
        return "Día inválido";
    }

    return nombres[dia];
}

int main() {
    for (int i = LUNES; i <= DOMINGO; i++) {
        dia_semana_t dia = (dia_semana_t)i;
        tipo_dia_t tipo = clasificar_dia(dia);

        printf("%s: ", dia_a_string(dia));
        switch (tipo) {
            case DIA_LABORAL:
                printf("Día laboral\n");
                break;
            case FIN_DE_SEMANA:
                printf("Fin de semana\n");
                break;
            case ERROR_DIA_INVALIDO:
                printf("Error: día inválido\n");
                break;
        }
    }

    // Probar con valor inválido
    dia_semana_t dia_malo = (dia_semana_t)42;
    tipo_dia_t resultado = clasificar_dia(dia_malo);
    if (resultado == ERROR_DIA_INVALIDO) {
        printf("Detección correcta de día inválido: %d\n", dia_malo);
    }

    return 0;
}
```
````