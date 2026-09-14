---
title: "Antipatrón AP-0x400Ah: Lectura de cadenas con scanf() sin límite de ancho en buffer fijo"
short_title: "AP-0x400Ah"
subtitle: "Gestión de Archivos y Errores (0x40XX)"
---

(ap_0x400Ah)=
# Antipatrón AP-0x400Ah: Lectura de cadenas con scanf() sin límite de ancho en buffer fijo

:::{admonition} Regla de Estilo Asociada: 0x400Ah
:class: tip
La transgresión descripta en este antipatrón se encuentra normada por la **[0x400Ah: Prohibición de operar sobre flujos de archivo tras haber invocado fclose() (use-after-close)](0x400Ah.md)**.
:::

:::{admonition} Diagnóstico de Antipatrón
:class: warning
Código de auditoría: `AP-0x400Ah` | Categoría: Gestión de Archivos y Errores (0x40XX)
:::

## Síntoma en el código del estudiante
Se lee una cadena con `scanf("%s", buf)` o `fscanf(f, "%s", buf)` sobre un
arreglo de tamaño fijo, sin indicar un ancho máximo. A veces el arreglo es
pequeño (10 o 20 bytes) y el dato proviene del usuario o de un archivo externo.

## Diagnóstico
### Mecanismo del defecto
El especificador `%s` de `scanf` lee caracteres hasta encontrar un espacio en
blanco, sin límite superior. La función no conoce el tamaño del arreglo destino:
solo recibe el puntero. Si la entrada es más larga que el búfer, escribe más
allá del final, pisando variables contiguas en la pila (u otras zonas del
programa).

Este es el desbordamiento de búfer (*buffer overflow*) canónico. No es un error
de compilación: el compilador no puede saber cuántos caracteres tendrá la
entrada. El daño depende de qué haya después del arreglo en memoria: puede
corromper otra variable, el marco de pila, la dirección de retorno o provocar la
caída del proceso. Un atacante puede aprovecharlo para redirigir el flujo de
ejecución.

### Consecuencia observable
Con entradas cortas todo funciona y el defecto permanece latente. Con una
entrada larga, el programa produce "stack smashing detected" (cuando el
canario de pila de GCC detecta la corrupción) o una violación de segmento. En
el mejor caso, una variable vecina cambia de valor sin explicación.

## Fundamento en el estándar C11
ISO/IEC 9899:2011 §7.21.6.2 define `fscanf` y su conversión `%s`: si no se
especifica un ancho de campo, la función lee tantos caracteres no blancos como
encuentre. El estándar no limita la escritura al tamaño del objeto apuntado,
porque no lo conoce; la responsabilidad de acotar es del programador. El ancho
debe reservar un byte para el terminador nulo, como indica la conversión de
cadenas.

## Corrección idiomática
### ❌ Código con el antipatrón
```c
char buf[10];
scanf("%s", buf);
```
Por qué es incorrecto: una entrada de 10 o más caracteres escribe fuera de
`buf`. El terminador nulo agrega un byte más, de modo que incluso 9 caracteres
más el `'\0'` ya alcanzan el límite exacto.

### ✅ Código refactorizado
```c
char buf[10];
if (scanf("%9s", buf) != 1) {
    return -1;
}

char linea[64];
if (fgets(linea, sizeof(linea), stdin) == NULL) {
    return -1;
}
```
El ancho `%9s` reserva los 9 caracteres útiles y deja lugar para el `'\0'`. Para
leer una línea completa —que es lo habitual— `fgets` acota por construcción
porque recibe el tamaño del búfer ({ref}`0x5006h`).

## Errores típicos al compilar o ejecutar
No hay advertencia de compilación en el caso general. El fallo aparece en
ejecución con una entrada larga.
```text
$ ./saludar
Ingrese su nombre: un_nombre_demasiado_largo
*** stack smashing detected ***: terminated
Aborted (core dumped)
```
Con suerte, el daño es silencioso y corrompe otra variable.
```text
$ ./configurar
Ingrese usuario: administrador_de_sistemas
usuario = administrador_de_sistemas
permisos = 1919905620     <-- variable vecina corrompida
```

## Checklist de verificación
- [ ] ¿Acoté el ancho de todo `%s` a `tamanio_del_buffer - 1`?
- [ ] ¿Verifiqué el retorno de `scanf`/`fscanf`?
- [ ] ¿Prefiero `fgets` para leer cadenas y líneas?
- [ ] ¿Compilé con `-Wall -Wextra` y `-D_FORTIFY_SOURCE=2`?

## Reglas relacionadas
* {ref}`0x400Ah` — regla asociada sobre el estado del flujo de E/S.
* {ref}`0x5006h` — preferir `fgets` sobre `gets` y `scanf` para cadenas.
* {ref}`0x5004h` — todas las operaciones con cadenas deben ser seguras.
* {ref}`0x5008h` — prohibición de funciones obsoletas o inseguras.
