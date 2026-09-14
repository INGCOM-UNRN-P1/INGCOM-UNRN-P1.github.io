---
title: "Antipatrón AP-0x100Dh: Variable float o double utilizada como contador de bucle"
short_title: "AP-0x100Dh"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x100Dh)=
# Antipatrón AP-0x100Dh: Variable float o double utilizada como contador de bucle

:::{admonition} Regla de Estilo Asociada: 0x100Dh
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x100Dh: Prohibición de casts de tipo innecesarios o redundantes](0x100Dh.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x100Dh` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

El contador de un `for` se declara `float` o `double` y avanza con incrementos
fraccionarios:

```c
for (float x = 0.0f; x < 1.0f; x += 0.1f)
{
    procesar(x);
}
```

## Diagnóstico

### Mecanismo del defecto

Los tipos `float` y `double` representan los reales con precisión finita
(IEEE-754). El valor `0.1f` no es exactamente un décimo en binario: cada suma
acumula un error de redondeo. La comparación `x < 1.0f` puede volverse verdadera
un número inesperado de veces, o nunca alcanzar el valor de corte exacto.

### Consecuencia observable

El lazo puede ejecutarse una vez de más o de menos, o quedar infinito si el
incremento es tan pequeño que el redondeo lo absorbe. Los conteos "deberían"
dar 10 pero dan 9 u 11 según la plataforma y la optimización. El error no se
reproduce de forma estable entre compiladores.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §6.2.5 y §5.2.4.2.2 describen la representación de los tipos
de punto flotante y sus límites de precisión. La aritmética con estos tipos no
es exacta; usar una variable flotante como índice o contador es una fuente
conocida de errores. La regla `0x100Dh` prohíbe los casts y usos innecesarios de
tipos flotantes en contextos enteros.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
for (float x = 0.0f; x < 1.0f; x += 0.1f)
{
    procesar(x);
}
```

### ✅ Código refactorizado

```c
for (int i = 0; i < 10; i++)
{
    float x = i * 0.1f;
    procesar(x);
}
```

El contador es entero y exacto; el valor flotante se deriva dentro del cuerpo
con una multiplicación, sin acumular error. La cantidad de iteraciones queda
determinada por la cota entera.

## Errores típicos al compilar o ejecutar

```text
No hay error de compilación. En ejecución, el lazo puede dar 9, 10 u 11
iteraciones según la plataforma; con -O2 el compilador puede reordenar la
comparación. Ver el error acumulado con:
printf("%.20f\n", x);  // muestra 0.9999999... en la última iteración
```

## Checklist de verificación

- [ ] ¿Algún `for` usa una variable flotante como contador?
- [ ] ¿La condición de corte depende de una igualdad flotante exacta?
- [ ] ¿Puedo usar un contador entero y derivar el valor flotante?
- [ ] ¿El redondeo IEEE-754 afecta la cantidad de iteraciones?

## Reglas relacionadas

* {ref}`0x100Dh` — norma este antipatrón: evitar usos innecesarios de casts/flotantes.
* {ref}`0x1003h` — el contador de un rango debe ser entero.
* {ref}`0x100Fh` — la condición del `for` debe ser una cota simple.
