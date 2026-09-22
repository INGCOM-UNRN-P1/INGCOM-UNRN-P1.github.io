---
title: 'Enumeraciones avanzadas'
short_title: 'Enums avanzados'
---

> **Prerrequisitos**: `11_enums.md` y `switch`.

# Enumeraciones avanzadas

Ampliación sobre máquinas de estados, validación de entradas externas,
sentinelas, flags y compatibilidad entre enumeraciones y enteros.

Una enumeración recibida desde un archivo o la red debe validarse antes de
usarla como índice o selector. Para flags, usá una máscara de tipo entero y
documentá qué combinaciones son válidas; un `enum` no impide por sí solo que
una conversión produzca un valor fuera de sus enumeradores.

```c
typedef enum { ESPERA, ACTIVA, TERMINADA } estado_t;
bool estado_valido(int x) { return x >= ESPERA && x <= TERMINADA; }
```

Las máquinas de estados son más fáciles de revisar cuando cada transición
indica estado de entrada, evento y estado de salida.

## Serialización de enumeraciones

Las enumeraciones pueden causar problemas al guardar datos en archivos o
enviarlos por red:

```{code-block} c
:caption: Problema: serialización frágil
typedef enum {
    FORMATO_V1,
    FORMATO_V2,
    FORMATO_V3
} version_formato_t;
// Problemático: si se reordena el enum, los archivos guardados se corrompen
void guardar_configuracion(FILE *archivo, version_formato_t version)
{
    fwrite(&version, sizeof(version), 1, archivo); // ¡Peligroso!
}
```

El valor entero que el compilador asigna a cada enumerador depende del orden
de declaración. Si el `enum` se reordena o se le agrega un valor en el medio
en una versión futura del programa, los archivos guardados con la versión
anterior pasan a interpretarse con los valores nuevos y quedan corruptos.

**Solución**: usar valores explícitos y funciones de conversión:

```{code-block} c
:caption: Solución: serialización robusta
:linenos:
typedef enum {
    FORMATO_V1 = 100,    // Valores explícitos garantizan estabilidad
    FORMATO_V2 = 200,
    FORMATO_V3 = 300
} version_formato_t;
// Función para convertir enum a representación de protocolo estable
uint32_t version_a_protocolo(version_formato_t version)
{
    switch (version)
    {
    case FORMATO_V1:
        return 100;
    case FORMATO_V2:
        return 200;
    case FORMATO_V3:
        return 300;
    default:
        return 0; // Valor de error
    }
}
// Función para convertir desde protocolo a enum
version_formato_t protocolo_a_version(uint32_t valor)
{
    switch (valor)
    {
    case 100:
        return FORMATO_V1;
    case 200:
        return FORMATO_V2;
    case 300:
        return FORMATO_V3;
    default:
        return FORMATO_V1; // Valor por defecto seguro
    }
}
// Guardar de forma segura
void guardar_configuracion(FILE *archivo, version_formato_t version)
{
    uint32_t valor_protocolo = version_a_protocolo(version);
    fwrite(&valor_protocolo, sizeof(uint32_t), 1, archivo);
}
// Cargar de forma segura
version_formato_t cargar_configuracion(FILE *archivo)
{
    uint32_t valor_protocolo = 0;
    fread(&valor_protocolo, sizeof(uint32_t), 1, archivo);
    return protocolo_a_version(valor_protocolo);
}
```

:::{tip} Estabilidad de Protocolo

Al usar valores explícitos y funciones de conversión, podés reorganizar el
`enum` internamente sin romper la compatibilidad con archivos existentes. Las
funciones de conversión actúan como una capa de abstracción entre la
representación interna y el formato persistido.

:::
