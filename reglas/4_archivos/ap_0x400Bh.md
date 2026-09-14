---
title: "Antipatrón AP-0x400Bh: Omisión de verificación de retorno NULL en fopen()"
short_title: "AP-0x400Bh"
subtitle: "Gestión de Archivos y Errores (0x40XX)"
---

(ap_0x400Bh)=
# Antipatrón AP-0x400Bh: Omisión de verificación de retorno NULL en fopen()

:::{admonition} Regla de Estilo Asociada: 0x4001h
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x4001h: Manejá correctamente la apertura y cierre de archivos](0x4001h.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x400Bh` | Categoría: Gestión de Archivos y Errores (0x40XX)
:::

## Síntoma en el código del estudiante
Se llama a `fopen` y, sin comprobar el resultado, se usa el puntero de inmediato
en `fread`, `fgets`, `fgetc`, `fprintf` o `fclose`. También aparece la apertura
anidada dentro de otra llamada de E/S, donde la verificación es directamente
imposible (ver error típico).

## Diagnóstico
### Mecanismo del defecto
`fopen` retorna un puntero a `FILE` si la apertura tuvo éxito y `NULL` si
falló. Las causas de fallo son variadas: el archivo no existe, la ruta es
inválida, faltan permisos, el proceso agotó sus descriptores o el medio de
almacenamiento dio error. El programador no controla la mayoría de esas
condiciones.

En C, `NULL` es una dirección inválida. Las funciones de `stdio` no verifican
que el puntero que reciben sea válido: asumen que el llamador cumplió el
contrato. Entonces, al ejecutar `fread` o `fgets` con `NULL`, la biblioteca
intenta acceder a la estructura interna del flujo en la dirección 0 y el
proceso recibe una violación de segmento. El defecto no es un resultado
incorrecto: es una caída.

### Consecuencia observable
El programa termina abruptamente con `Segmentation fault (core dumped)` en la
primera operación de E/S, sin haber reportado la causa real (el archivo
faltante, el permiso denegado). El mensaje de caída no menciona la ruta ni el
motivo, por lo que el diagnóstico queda a cargo del programador.

## Fundamento en el estándar C11
ISO/IEC 9899:2011 §7.21.5.3 define `fopen` y establece que retorna `NULL` si la
apertura falla. La validez de todas las operaciones posteriores depende de un
retorno no nulo; desreferenciar un puntero nulo es comportamiento indefinido
(§6.5.3.2). La cátedra exige la comprobación inmediata porque toda la categoría
0x40XX presupone un flujo válido.

## Corrección idiomática
### ❌ Código con el antipatrón
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
fclose(f);
```
Por qué es incorrecto: si `datos.txt` no existe, `f` es `NULL` y `fread`
desreferencia la dirección 0. El programa cae en la lectura y el usuario nunca
se entera de que el archivo faltaba.

### ✅ Código refactorizado
```c
#include <stdio.h>

FILE *f = fopen("datos.txt", "r");
if (f == NULL) {
    perror("datos.txt");
    return -1;
}
if (fread(&elem, sizeof(elem), 1, f) != 1) {
    perror("fread");
}
fclose(f);
```
La comprobación inmediata evita la desreferencia, `perror` informa la causa del
sistema ({ref}`0x4003h`), el retorno de `fread` se verifica ({ref}`0x4002h`) y
el flujo se cierra en el mismo nivel en que se abrió ({ref}`0x4004h`).

## Errores típicos al compilar o ejecutar
No hay error de compilación obligatorio. Con optimizaciones y advertencias
estrictas puede aparecer una alerta de posible desreferencia nula.
```text
warning: null pointer dereference [-Wnull-dereference]
```
En ejecución, la caída es inmediata.
```text
$ ./leer
Segmentation fault (core dumped)
```
Si la apertura se anidó en otra llamada, el compilador directamente no puede
avisar.
```text
$ ./cargar
Segmentation fault (core dumped)
```

## Checklist de verificación
- [ ] ¿Comprobé `if (f == NULL)` inmediatamente después de cada `fopen`?
- [ ] ¿Reporté la causa con `perror` o `strerror`?
- [ ] ¿Evité anidar `fopen` dentro de otra función de E/S?
- [ ] ¿Cierro el flujo con `fclose` en el mismo nivel en que lo abrí?

## Reglas relacionadas
* {ref}`0x4001h` — regla asociada: verificar la apertura y cerrar el flujo.
* {ref}`0x4003h` — `perror`/`strerror` para diagnosticar el fallo de apertura.
* {ref}`0x4009h` — prohibición de anidar `fopen` en funciones de E/S.
* {ref}`0x4004h` — la propiedad y el cierre simétrico del recurso.
