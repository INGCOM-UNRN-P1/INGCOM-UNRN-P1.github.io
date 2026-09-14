---
title: "Antipatrón AP-0x101Ah: Comparación lógica invertida con strcmp() en condicional"
short_title: "AP-0x101Ah"
subtitle: "Estructuras de Control y Lazos (0x10XX)"
---

(ap_0x101Ah)=
# Antipatrón AP-0x101Ah: Comparación lógica invertida con strcmp() en condicional

:::{admonition} Regla de Estilo Asociada: 0x1005h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la
**[0x1005h: Reemplazá las condiciones ambiguas basadas en la "veracidad" del tipo de dato](0x1005h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x101Ah` | Categoría: Estructuras de Control y Lazos (0x10XX)
:::

## Síntoma en el código del estudiante

Se usa el resultado de `strcmp` directamente como booleano, sin compararlo
contra `0`:

```c
if (strcmp(nombre, "admin"))
{
    dar_acceso();
}
```

## Diagnóstico

### Mecanismo del defecto

`strcmp` devuelve un entero negativo, `0` o positivo según el orden
lexicográfico (ISO/IEC 9899:2011 §7.24.4.2). Devuelve `0` cuando las cadenas son
**iguales**. Al usarlo directamente como condición, el cero se interpreta como
falso y cualquier otro valor como verdadero: la rama se ejecuta cuando las
cadenas son **diferentes**, justo al revés de lo que sugiere el nombre.

### Consecuencia observable

La validación de credenciales, nombres o claves queda invertida: se concede
acceso a cualquier texto que no coincida con el esperado y se lo niega al
correcto. Es un bug grave de seguridad que compila sin advertencias y se
manifiesta como lógica incomprensible.

## Fundamento en el estándar C11

ISO/IEC 9899:2011 §7.24.4.2 especifica el valor de retorno de `strcmp`. Debido
a que `0` significa igualdad, la comparación explícita es obligatoria. La
cátedra exige comparar contra `0` (regla `0x1005h`) y distingue el chequeo de
cadenas del de punteros y caracteres.

## Corrección idiomática

### ❌ Código con el antipatrón

```c
if (strcmp(nombre, "admin"))
{
    dar_acceso();
}
```

### ✅ Código refactorizado

```c
if (strcmp(nombre, "admin") == 0)
{
    dar_acceso();
}

if (strcmp(nombre, "admin") != 0)
{
    denegar_acceso();
}
```

La comparación contra `0` hace explícito que `0` es igualdad y `!= 0` es
desigualdad. El lector ya no tiene que recordar la convención de `strcmp`.

## Errores típicos al compilar o ejecutar

```text
No hay error de compilación ni advertencia por defecto.

En ejecución, la rama se ejecuta para cualquier nombre distinto de "admin":
dar_acceso() se llama con nombres incorrectos. Un atacante entra con
cualquier usuario mientras no se llame "admin".
```

## Checklist de verificación

- [ ] ¿Uso `strcmp` como condición directa?
- [ ] ¿La comparación contra `0` está explícita?
- [ ] ¿Distinguí `== 0` (igualdad) de `!= 0` (desigualdad)?
- [ ] ¿Probé el caso de cadenas iguales y el de cadenas distintas?

## Reglas relacionadas

* {ref}`0x1005h` — norma este antipatrón: comparaciones explícitas por tipo.
* {ref}`0x5006h` — preferir `fgets` para leer cadenas de entrada.
* {ref}`0x5004h` — operaciones seguras con cadenas.
