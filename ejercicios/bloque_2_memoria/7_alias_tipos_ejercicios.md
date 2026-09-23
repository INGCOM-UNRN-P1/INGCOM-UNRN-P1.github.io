---
title: "Ejercicios: Alias de Tipos"
short_title: "15. Alias de Tipos"
---

# Ejercicios: Alias de Tipos

## Acerca de

Estos ejercicios permiten consolidar el uso de alias de tipos (`typedef`) y enumeraciones (`enum`) en
C11 para modelar dominios semánticos claros, legibles y robustos contra valores fuera de rango.

### Capítulos de Apunte Correspondientes
- [Alias de tipos](../../apunte/bloque_2_memoria/10_alias_tipos.md)

### Cuestiones de Estilo Aplicables
- **Nombres de tipos:** Por convención de cátedra ({ref}`0x2001h`), todo tipo definido con `typedef` debe llevar el sufijo `_t` (ej. `dia_semana_t`).
- **Validación defensiva:** Validar rangos en `switch` incluyendo siempre la cláusula `default` para manejar valores inesperados.
- **Aserciones:** Utilizar `<assert.h>` para aserciones invariantes en suites de verificación.

---

## Definición de Alias de Tipos

(ej_b2_c10_01)=
### Ejercicio 2.10.01 - Clasificación de Días de la Semana con Enums ⭐⭐☆☆☆

:::{exercise}
:label: enum_basico
:enumerator: enums-1

Definí un tipo enumerado `dia_semana_t` con alias `typedef` para representar los días de la semana
(de `LUNES` a `DOMINGO`), más un centinela `DIA_INVALIDO`.
Implementá una función `tipo_dia_t clasificar_dia(dia_semana_t dia)` que determine si un día
es laboral (`DIA_LABORAL`), fin de semana (`FIN_DE_SEMANA`) o inválido (`ERROR_DIA_INVALIDO`).
Implementá además una función `const char *dia_a_string(dia_semana_t dia)` que devuelva la representación
textual inmutable del día.

**Nivel de Bloom:** Nivel 2 (Comprensión) y Nivel 3 (Aplicación).  
**Conceptos requeridos:** `typedef`, `enum`, `switch-case`, calificador `const`.  
**Techo conceptual:** Prohibido el uso de memoria dinámica (`malloc`) o punteros a cadenas mutables.

#### Contrato de la Función
- **Firma:** `tipo_dia_t clasificar_dia(dia_semana_t dia);`
- **Firma:** `const char *dia_a_string(dia_semana_t dia);`
- **Precondiciones:** Ninguna (la función maneja explícitamente valores fuera de rango).
- **Postcondiciones:** Retorna `DIA_LABORAL` para lunes a viernes, `FIN_DE_SEMANA` para sábado y domingo, y `ERROR_DIA_INVALIDO` para cualquier otro entero.

#### Tabla de Vectores de Prueba Obligatorios

| Tipo de Caso | Entrada (`dia`) | Retorno Clasificación | Retorno String | Justificación Técnica |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | `LUNES` | `DIA_LABORAL` | `"Lunes"` | Inicio de semana hábil |
| **Normal** | `VIERNES` | `DIA_LABORAL` | `"Viernes"` | Fin de semana hábil |
| **Normal** | `SABADO` | `FIN_DE_SEMANA` | `"Sábado"` | Primer día de descanso |
| **Normal** | `DOMINGO` | `FIN_DE_SEMANA` | `"Domingo"` | Segundo día de descanso |
| **Borde (Centinela)** | `DIA_INVALIDO` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Límite superior del enum |
| **Error (Negativo)** | `-1` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Entero fuera de rango inferior |
| **Error (Desborde)** | `99` | `ERROR_DIA_INVALIDO` | `"Día inválido"` | Entero fuera de rango superior |

:::
<!-- {exercise} -->

::::{solution} enum_basico
:class: dropdown

```{code-block} c
:linenos:
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    LUNES = 0,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO,
    DIA_INVALIDO
} dia_semana_t;

typedef enum
{
    DIA_LABORAL,
    FIN_DE_SEMANA,
    ERROR_DIA_INVALIDO
} tipo_dia_t;

tipo_dia_t clasificar_dia(dia_semana_t dia)
{
    switch (dia)
    {
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

const char *dia_a_string(dia_semana_t dia)
{
    static const char *const nombres[] = {
        "Lunes", "Martes", "Miércoles", "Jueves",
        "Viernes", "Sábado", "Domingo"
    };

    if (dia < LUNES || dia >= DIA_INVALIDO)
    {
        return "Día inválido";
    }
    return nombres[dia];
}

int main(void)
{
    // Casos normales días laborales
    assert(clasificar_dia(LUNES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(LUNES), "Lunes") == 0);

    assert(clasificar_dia(MIERCOLES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(MIERCOLES), "Miércoles") == 0);

    assert(clasificar_dia(VIERNES) == DIA_LABORAL);
    assert(strcmp(dia_a_string(VIERNES), "Viernes") == 0);

    // Casos normales fin de semana
    assert(clasificar_dia(SABADO) == FIN_DE_SEMANA);
    assert(strcmp(dia_a_string(SABADO), "Sábado") == 0);

    assert(clasificar_dia(DOMINGO) == FIN_DE_SEMANA);
    assert(strcmp(dia_a_string(DOMINGO), "Domingo") == 0);

    // Casos de error y fuera de rango
    assert(clasificar_dia(DIA_INVALIDO) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string(DIA_INVALIDO), "Día inválido") == 0);

    assert(clasificar_dia((dia_semana_t)-1) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string((dia_semana_t)-1), "Día inválido") == 0);

    assert(clasificar_dia((dia_semana_t)99) == ERROR_DIA_INVALIDO);
    assert(strcmp(dia_a_string((dia_semana_t)99), "Día inválido") == 0);

    return 0;
}
```

::::
<!-- {solution} enum_basico -->
