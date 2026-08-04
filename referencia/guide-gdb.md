---
title: Guía Práctica y Referencia Completa de Depuración con GDB
short_title: Guía GDB
subtitle: Inspección de ejecución, control de flujo, puntos de interrupción, análisis de la pila de llamadas (stack frames) y examen de memoria en lenguaje C
---

## Introducción

GNU Debugger (`gdb`) es el depurador estándar del sistema GNU y una herramienta
indispensable en el desarrollo y diagnóstico de software en C. Permite ejecutar
programas de forma controlada, detener la ejecución en instantes específicos,
examinar el estado interno de las variables, inspeccionar la pila de llamadas
(*call stack*) y rastrear la causa exacta de fallos críticos como los errores de
segmentación (*segmentation fault*).

Para aprovechar las capacidades de `gdb`, el programa debe compilarse incluyendo
información de depuración simbólica mediante el modificador `-g` en `gcc`:

``` bash
gcc -g -Wall -Wextra -std=c99 main.c -o programa
```
<!-- bash -->

:::{note}

El indicador `-g` no altera la lógica de ejecución del programa, sino que añade
tablas de símbolos que vinculan las direcciones de memoria física con los
nombres de variables y números de línea del código fuente.

:::
<!-- {note} -->

---

## Compilación y Modos de Invocación

Existen distintas formas de iniciar una sesión de depuración con `gdb` según el
escenario de análisis:

### 1. Invocación Directa

``` bash
gdb ./programa
```
<!-- bash -->

### 2. Invocación con Argumentos de Línea de Comandos

Si el ejecutable requiere argumentos de entrada, pueden pasarse mediante la
opción `--args`:

``` bash
gdb --args ./programa archivo_entrada.txt 100
```
<!-- bash -->

También es posible especificar o modificar los argumentos dentro de la propia
consola de `gdb` antes de iniciar la ejecución:

``` gdb
(gdb) set args archivo_entrada.txt 100
```
<!-- gdb -->

### 3. Depuración de un Proceso en Ejecución (Attach)

Si un programa se encuentra colgado o ejecutándose en segundo plano, `gdb` puede
vincularse a su PID (Process ID):

``` bash
gdb --pid=12345
```
<!-- bash -->

### 4. Análisis Post-Mortem mediante Core Dumps

Cuando un programa falla catastróficamente con un *Segmentation Fault*, el
sistema operativo puede generar un archivo *core dump* que registra el estado
completo de la memoria al momento del colapso. Para analizarlo:

``` bash
gdb ./programa core
```
<!-- bash -->

---

## Control de Ejecución y Navegación

Una vez dentro de la consola interactiva de `gdb`, la ejecución se controla
mediante los siguientes comandos principales:

| Comando | Abreviatura | Descripción |
| :--- | :---: | :--- |
| `run` | `r` | Inicia o reinicia la ejecución del programa desde el comienzo. |
| `continue` | `c` | Reanuda la ejecución hasta encontrar el siguiente *breakpoint* o la finalización. |
| `step` | `s` | Ejecuta la siguiente línea de código, **ingresando** al cuerpo de la función si la hay. |
| `next` | `n` | Ejecuta la siguiente línea de código, **saltando** la ejecución interna de funciones llamadas. |
| `finish` | `fin` | Continúa la ejecución hasta retornar de la función actual. |
| `until` | `u` | Continúa la ejecución hasta alcanzar una línea posterior a la actual (útil para salir de lazos/bucles). |
| `quit` | `q` | Finaliza la sesión de depuración y sale de `gdb`. |

---

## Puntos de Interrupción (Breakpoints) y Puntos de Observación (Watchpoints)

Los *breakpoints* suspenden la ejecución del programa antes de que se ejecute la
instrucción señalada.

### Breakpoints Simples

``` gdb
(gdb) break main
(gdb) break 45
(gdb) break mi_modulo.c:120
```
<!-- gdb -->

### Breakpoints Condicionales

Permiten pausar la ejecución únicamente si se cumple una condición booleana
específica. Resultan fundamentales para analizar errores que suceden tras
múltiples iteraciones de un lazo:

``` gdb
(gdb) break procesar_elemento if i == 500
(gdb) break 78 if ptr == NULL
```
<!-- gdb -->

### Puntos de Observación (Watchpoints)

Un *watchpoint* no se asocia a una línea de código sino a una variable o
dirección de memoria. La ejecución se suspende automáticamente cada vez que el
valor de dicha memoria **cambia**:

``` gdb
(gdb) watch contador
(gdb) rwatch lectura_var   # Pausa cuando la variable es LEÍDA
(gdb) awatch acceso_var    # Pausa cuando la variable es LEÍDA o ESCRITA
```
<!-- gdb -->

### Gestión de Breakpoints

* `info breakpoints` (o `info b`): Lista todos los puntos de interrupción y
  observación configurados, mostrando su número identificador (ID).
* `delete <id>`: Elimina el breakpoint indicado.
* `disable <id>` / `enable <id>`: Desactiva o reactiva temporalmente un
  breakpoint sin eliminarlo.
* `clear <linea>`: Elimina el breakpoint situado en la línea especificada.

---

## Inspección de Variables y Estado del Programa

### Imprimir Expresiones (`print`)

El comando `print` (abreviado `p`) evalúa e imprime cualquier variable o
expresión válida en C:

``` gdb
(gdb) print total
(gdb) print arreglo[0]
(gdb) print *puntero
(gdb) print estructura.campo
(gdb) print (a + b) / 2
```
<!-- gdb -->

Es posible especificar especificadores de formato para la impresión de los
valores:

``` gdb
(gdb) print/x variable   # Imprime en hexadecimal
(gdb) print/d variable   # Imprime en decimal entero
(gdb) print/t variable   # Imprime en formato binario
(gdb) print/c variable   # Imprime como carácter ASCII
(gdb) print/s cadena     # Imprime como cadena de caracteres (char *)
```
<!-- gdb -->

### Muestra Automática (`display`)

El comando `display` evalúa y muestra automáticamente una expresión en pantalla
cada vez que la ejecución se detiene (al avanzar paso a paso con `step` o
`next`):

``` gdb
(gdb) display i
(gdb) display arreglo[i]
(gdb) info display       # Muestra expresiones activas
(gdb) undisplay <id>     # Desactiva la muestra automática del ID especificado
```
<!-- gdb -->

---

## Análisis de la Pila de Llamadas (Stack Frames)

Cada invocación a una función crea un registro de activación o *frame* en la
pila de memoria (*stack*), conteniendo sus parámetros y variables locales.

### Comando Backtrace

Cuando ocurre un error o la ejecución se detiene, el comando `backtrace` (o
`bt`) muestra la pila completa de llamadas desde la función actual hasta `main`:

``` gdb
(gdb) backtrace
#0  0x0000000000401142 in desreferenciar (ptr=0x0) at main.c:12
#1  0x0000000000401185 in procesar_datos (tabla=0x7fffffffde00) at main.c:25
#2  0x00000000004011cb in main () at main.c:34
```
<!-- gdb -->

### Navegación entre Frames

Permite cambiar el contexto de la inspección a distintas funciones de la cadena
de llamadas sin reanudar la ejecución:

* `frame <numero>` (o `f`): Selecciona el registro de activación especificado.
* `up`: Sube un nivel en la pila de llamadas (hacia la función llamante).
* `down`: Baja un nivel en la pila de llamadas (hacia la función llamada).

### Inspección del Frame Seleccionado

``` gdb
(gdb) info locals    # Muestra los valores de todas las variables locales del frame actual
(gdb) info args      # Muestra los argumentos pasados a la función del frame actual
```
<!-- gdb -->

---

## Inspección Directa de Memoria (`x`)

El comando `examine` (abreviado `x`) permite inspeccionar bloques de memoria
cruda a partir de una dirección o puntero. Su sintaxis general es:

$$\text{x/Nuf } \langle\text{dirección}\rangle$$

Donde:
* **N**: Cantidad de unidades de memoria a examinar.
* **u**: Unidad de tamaño (`b`: bytes, `h`: 2 bytes / halfword, `w`: 4 bytes /
  word, `g`: 8 bytes / giant word).
* **f**: Formato de visualización (`x`: hexadecimal, `d`: decimal firmado, `u`:
  decimal no firmado, `c`: carácter, `s`: cadena de caracteres, `i`: instrucción
  en ensamblador).

### Ejemplos Prácticos

1. **Examinar 8 enteros en hexadecimal**:
   ```gdb
   (gdb) x/8wx ptr_arreglo
   ```
2. **Examinar la cadena apuntada por un puntero**:
   ```gdb
   (gdb) x/s cadena_ptr
   ```
3. **Examinar 16 bytes de memoria en formato binario**:
   ```gdb
   (gdb) x/16bt &variable
   ```

---

## Diagnóstico y Resolución de un Segmentation Fault

Un *Segmentation Fault* ocurre cuando el programa intenta leer o escribir en una
dirección de memoria no válida o no autorizada (por ejemplo, desreferenciar un
puntero `NULL` o acceder a un índice fuera del arreglo).

### Flujo de Diagnóstico Paso a Paso

1. Iniciar el programa dentro de `gdb`:
   ```bash
   gdb ./programa_con_fallo
   ```
2. Iniciar la ejecución con `run`. Cuando el programa colapse, `gdb` capturará
   la señal `SIGSEGV` y pausará la consola:
   ```text
   Program received signal SIGSEGV, Segmentation fault.
   0x0000000000401156 in calcular (matriz=0x0, i=0) at main.c:14
   14          return matriz[i]->valor;
   ```
3. Consultar el *backtrace* para identificar la secuencia de llamadas:
   ```gdb
   (gdb) backtrace
   ```
4. Examinar los valores de las variables involucradas:
   ```gdb
   (gdb) print matriz
   $1 = (int **) 0x0
   ```
   *(Diagnóstico: Se intentó desreferenciar `matriz` cuando su valor era
   `NULL`).*

---

## Modificación de Estado en Tiempo de Ejecución

`gdb` permite modificar variables y alterar el flujo del programa dinámicamente
sin necesidad de recompilar el fuente:

### Asignación de Variables

``` gdb
(gdb) set variable contador = 100
(gdb) set variable ptr = NULL
```
<!-- gdb -->

### Forzar el Retorno de una Función

Es posible abortar la ejecución de una función y forzar el retorno de un valor
específico hacia la función llamante:

``` gdb
(gdb) return 0
```
<!-- gdb -->

---

## Interfaz Gráfica Integrada (TUI Mode)

`gdb` incluye una interfaz gráfica basada en la terminal (*Text User Interface*)
que muestra el código fuente y el registro de ensamblador dividiendo la pantalla
en ventanas.

### Activar y Desactivar TUI

* Activar al iniciar `gdb`:
  ```bash
  gdb -tui ./programa
  ```
* Alternar el modo TUI dentro de la consola: Presionar `Ctrl + X` seguido de `A`
  (o ejecutar `tui enable` / `tui disable`).
* Cambiar diseño de ventanas:
  ```gdb
  (gdb) layout src     # Muestra código fuente y consola
  (gdb) layout regs    # Muestra registros del procesador y código fuente
  (gdb) layout split   # Muestra código fuente y código en ensamblador
  ```

---

## Archivos de Configuración (`.gdbinit`)

Para personalizar el comportamiento de `gdb` (como la presentación visual, alias
de comandos o carga de scripts), se puede crear un archivo de configuración
`.gdbinit` en el directorio de usuario (`~/.gdbinit`) o en el directorio raíz
del proyecto:

```{code-block} gdb
:linenos:
# Configuración recomendada para .gdbinit

# Habilitar resaltado de sintaxis y formato legible para estructuras
set print pretty on
set print array on
set print array-indexes on

# Confirmación automática al salir
set confirm off

# Alias útiles
alias bmain = break main

```
<!-- {code-block} gdb -->

---

## Tabla Resumen de Comandos Rápidos

| Categoría | Comando | Descripción |
| :--- | :--- | :--- |
| **Inicio** | `gdb --args ./prog arg1` | Inicia `gdb` pasando argumentos al ejecutable. |
| **Control** | `r`, `n`, `s`, `c`, `fin` | Iniciar, siguiente línea, ingresar a función, continuar, salir de función. |
| **Puntos de parada** | `b N`, `b func`, `b N if cond` | Breakpoint en línea, función o condicional. |
| **Observación** | `watch var` | Pausa la ejecución al modificar el valor de `var`. |
| **Inspección** | `p var`, `p/x var`, `display var` | Imprime variable, imprime en hexadecimal, muestra automática. |
| **Memoria** | `x/Nuf <dir>` | Examina $N$ unidades de memoria en el formato y tamaño especificados. |
| **Pila (Stack)** | `bt`, `f N`, `info locals` | Muestra la pila de llamadas, selecciona el frame $N$, lista variables locales. |
| **Modificación** | `set var x = val` | Cambia el valor de una variable en tiempo de ejecución. |
| **Interfaz** | `Ctrl + X` + `A` | Activa o desactiva la interfaz TUI. |
