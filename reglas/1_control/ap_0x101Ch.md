---
title: "Antipatrón AP-0x101Ch: Bucle infinito con salida condicionada exclusivamente por exit()"
short_title: "AP-0x101Ch"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x101Ch)=
# Antipatrón AP-0x101Ch: Bucle infinito con salida condicionada exclusivamente por exit()

:::{admonition} Regla de Estilo Asociada: 0x1002h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x1002h: Restringí el uso de break y continue; preferí lazos con bandera de control](0x1002h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x101Ch` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

Un lazo `while (1)` termina el programa entero mediante `exit()` en lugar de
salir de forma estructurada:

```c
while (1)
{
    if (fin)
    {
        exit(0);
    }
    procesar();
}
```

## Diagnóstico

### Mecanismo del defecto

`exit()` termina el proceso completo (ISO/IEC 9899:2011 §7.22.4.4): abandona el
lazo, la función y toda la cadena de llamadas. El control nunca vuelve al
llamador, con lo que se omite cualquier limpieza pendiente definida después del
lazo (liberar memoria, cerrar archivos, restaurar estado).

### Consecuencia observable

El programa termina "correctamente" para el usuario, pero deja recursos sin
liberar y evita que el código de limpieza se ejecute. En pruebas unitarias, la
función no puede retornar y la prueba muere con el proceso; no se puede
distinguir el éxito del fallo ni continuar con el siguiente caso.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §7.22.4.4 define `exit` como terminación del programa que
registra las funciones de `atexit` y cierra los flujos, pero no ejecuta el
código de limpieza local. La cátedra exige que el corte se exprese en la
estructura del lazo (regla `0x1002h`): una bandera de control o, si el propósito
es salir de la función, un `return`.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
while (1)
{
    if (fin)
    {
        exit(0);
    }
    procesar();
}
```

### ✅ Código refactorizado

```c
bool terminar = false;
while (!terminar)
{
    if (fin)
    {
        terminar = true;
    }
    else
    {
        procesar();
    }
}
```

La bandera expone la condición de corte y el lazo sale por su encabezado. Si el
corte debe abandonar la función, se usa `return` y el llamador retoma el control.

## Errores típicos al compilar o ejecutar

```text
No hay error de compilación.

En ejecución, la memoria asignada en procesar() no se libera; un
detector como valgrind o -fsanitize=address reporta:
ERROR: LeakSanitizer: detected memory leaks
directly lost: ... bytes in ... blocks

En una suite de pruebas, la prueba que invoca esta función termina
el proceso y las pruebas siguientes no se ejecutan.
```

## Checklist de verificación

- [ ] ¿El lazo sale con `exit()` en lugar de una condición?
- [ ] ¿Hay recursos que deban liberarse antes de salir?
- [ ] ¿Puedo usar una bandera de control o un `return`?
- [ ] ¿El código posterior al lazo debe ejecutarse siempre?

## Reglas relacionadas

* {ref}`0x1002h` — norma este antipatrón: banderas de control en lugar de saltos.
* {ref}`0x2001h` — retornos anticipados y limpieza centralizada.
* {ref}`0x3002h` — liberar la memoria dinámica y anular el puntero.
