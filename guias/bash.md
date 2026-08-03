---
title: Bash para empezar
short_title: Guía Bash
subtitle: Guía para aprender a usar la consola UNIX (Bash) desde cero
---

## ¿Por qué aprender Bash?

Bash (Bourne Again SHell) es un intérprete de comandos que funciona como
interfaz textual entre el usuario y el núcleo del sistema operativo. Permite
ejecutar instrucciones, combinar operaciones y controlar con precisión el
comportamiento del sistema, todo desde una interfaz puramente textual. Su uso
interactivo es el punto de partida para el desarrollo de habilidades avanzadas
en administración y automatización.

Este es descendiente directo del shell de UNIX clásico (`sh`) y, al día de hoy,
sigue siendo la shell por defecto en la mayoría de las distros GNU/Linux y
macOS.

## Filosofía UNIX en 1 minuto

Antes de continuar, es necesario que abordemos un concepto que guia el
desarrollo y uso de un sistema basado en UNIX, como Linux.

> "Haz una cosa y hazla bien."

- Cada comando hace una sola cosa.
- La salida de un comando puede conectarse a la entrada de otro:
  **composición**.
- Todo es un archivo. Sí, _todo_.
- Pequeñas herramientas, combinadas con `|`, pueden resolver problemas
  complejos.

[Filosofía UNIX](https://es.wikipedia.org/wiki/Filosof%C3%ADa_de_Unix)

## Interacción básica con Bash

La consola Bash permite una interacción directa con el sistema operativo
mediante una interfaz de línea de comandos. Este uso interactivo es ideal
explorar y diagnosticar el sistema, así como verificar rápidamente el
comportamiento de los diferentes pasos que pueden componer un script de
automatización.

### ¿Qué es el uso interactivo?

Es la forma más inmediata de ejecutar comandos directamente en el shell. Cada
instrucción escrita en el prompt (`$`) es interpretada y ejecutada de inmediato
por Bash. Este modo de trabajo es crucial para comprender el comportamiento del
sistema operativo, ya que permite realizar pruebas rápidas, verificar
configuraciones, analizar resultados y familiarizarse con herramientas
disponibles.

Más adelante, vamos a ver el _otro_ uso que tiene bash, la parte de scripting
que nos permite ejecutar un conjunto de acciones como una sola.

### Características clave

- **Retroalimentación sincrónica**: cada comando produce una salida
  inmediatamente después de su ejecución, lo que permite comprobar que pasó de
  forma directa.
- **Exploración estructurada**: mediante comandos, es posible navegar por la
  estructura de directorios del sistema, inspeccionar y modificar archivos.
- **Validación progresiva**: el entorno permite realizar pruebas incrementales
  sin necesidad de desarrollar scripts completos. Esto permite verificar
  hipótesis operativas antes de automatizar.
- **Entorno altamente configurable**: Bash permite ajustar dinámicamente
  variables, definir funciones y modificar el comportamiento del entorno sin
  necesidad de privilegios administrativos.

### Ejemplo introductorio

```{code-block} bash
:linenos:
$ pwd
/home/usuario
$ ls -l
-rw-r--r-- 1 usuario usuario 4096 jul 19 10:23 archivo.txt
$ echo "Hola Mundo!"
Hola Mundo!

```
<!-- {code-block} bash -->

- `pwd`: imprime el directorio de trabajo actual, útil para orientarse dentro de
  jerarquías complejas de carpetas.
- `ls -l`: lista los archivos del directorio con detalles como permisos,
  propietario, grupo, tamaño y fechas de modificación.
- `echo`: imprime un mensaje en la consola, en este caso, el tradicional "Hola
  Mundo!".

Tengan en cuenta que la terminal es sensible a mayusculas, y las instrucciones
deben tener la forma correcta, o de lo contrario no funcionarán.

``` bash
$ PWD
PWD: command not found
```
<!-- bash -->

### Funcionalidades prácticas

- **Historial de comandos**: navegación con las teclas ↑ y ↓ permite acceder
  rápidamente a comandos anteriores.
- **Autocompletado**: pulsar `Tab` completa rutas de archivos y comandos, lo
  cual evita errores de tipeo y facilita el su uso.
- **Patrones con comodines** (globs):
  - `*`: representa cualquier cantidad de caracteres.
  - `?`: representa un solo carácter.
  - Ejemplo: `ls *.txt` lista todos los archivos con extensión `.txt`.
- **Encadenamiento de comandos**:

``` bash
$ cd proyectos; ls; echo "Directorio explorado"
```
<!-- bash -->

Cada comando se ejecuta en secuencia, incluso si alguno falla. Esto permite
combinar tareas sin necesidad de un script.

- **Separación condicional**:
  - `&&`: solo ejecuta el segundo comando si el primero tiene éxito.
  - `||`: solo ejecuta el segundo comando si el primero falla.
  - Ejemplo:

``` bash
$ make && ./programa
```
<!-- bash -->

## Primeros pasos en la terminal

### 🔹 ¿Cómo abro Bash?

- En Linux: Ctrl+Alt+T o buscá "Terminal"
- En macOS: Spotlight > Terminal
- En Windows: `WSL` o Git Bash. (no viene instalado, y es necesario seguir la
  guia de instalación)

## 2. Comandos para cambiar directorios y manipular archivos

El sistema de archivos en UNIX está organizado jerárquicamente. Los comandos de
Bash permiten interactuar con esta estructura de forma precisa, tanto para
navegación como para la gestión de archivos y directorios.

### 2.1 Navegación por directorios

- `pwd`: muestra el directorio actual.
- `cd <ruta>`: cambia al directorio especificado.
  - Relativo: `cd documentos`
  - Absoluto: `cd /home/usuario/documentos`
- `cd ~`: accede al directorio personal del usuario.
- `cd -`: vuelve al directorio anterior.

```{code-block} bash
:linenos:
$ cd /etc
$ pwd
/etc
$ cd ~
$ pwd
/home/usuario

```
<!-- {code-block} bash -->

### 2.2 Listado de contenidos

- `ls`: lista los archivos del directorio.
- `ls -l`: muestra detalles como permisos y tamaño.
- `ls -a`: incluye archivos ocultos.
- `ls -lh`: usa unidades legibles por humanos.

``` bash
$ ls -lh
-rw-r--r-- 1 usuario usuario 1.2K jul 19 10:23 notas.txt
```
<!-- bash -->

### 2.3 Creación de directorios y archivos

- `mkdir nombre`: crea un nuevo directorio.
- `mkdir -p ruta/compuesta`: crea varios niveles si no existen.
- `touch archivo`: crea un archivo vacío o actualiza su fecha de modificación.

``` bash
$ mkdir proyectos
$ cd proyectos
$ touch main.c
```
<!-- bash -->

### 2.4 Copia, movimiento y eliminación

- `cp origen destino`: copia archivos.
- `cp -r origen destino`: copia directorios recursivamente.
- `mv origen destino`: mueve o renombra.
- `rm archivo`: elimina archivos.
- `rm -r directorio`: elimina directorios recursivamente.
- `rm -rf`: eliminación forzada, sin confirmación.

``` bash
$ cp datos.txt copia.txt
$ mv copia.txt ../backup/
$ rm -r carpeta_antigua
```
<!-- bash -->

### 2.5 Inspección del contenido de archivos

- `cat archivo`: imprime el contenido.
- `less archivo`: permite navegación por páginas (`/` para buscar, `q` para
  salir).
- `head -n N`: muestra las primeras `N` líneas.
- `tail -n N`: muestra las últimas `N` líneas.

``` bash
$ head -n 5 log.txt
```
<!-- bash -->

Estas herramientas son esenciales para verificar contenido, diagnosticar errores
y explorar datos.

## Redirecciones y Pipes en Bash

La capacidad de Bash para redirigir flujos de entrada y salida, así como
conectar comandos mediante tuberías, es una herramienta poderosa para construir
flujos de procesamiento de datos. Estas capacidades son centrales para cualquier
entorno de scripting, administración de sistemas o desarrollo de herramientas
CLI.

### Redirecciones estándar

Las redirecciones permiten controlar cómo los programas leen o escriben datos
mediante los tres flujos estándar:

- **stdin (0)**: entrada estándar (por defecto el teclado).
- **stdout (1)**: salida estándar (por defecto la pantalla).
- **stderr (2)**: salida de errores (también por defecto la pantalla, pero se
  puede redirigir por separado).

#### Redirección de salida (`>` y `>>`)

``` bash
ls -l > listado.txt
```
<!-- bash -->

- Crea (o sobrescribe) el archivo `listado.txt` con la salida del comando.

``` bash
echo "Nueva entrada" >> listado.txt
```
<!-- bash -->

- Agrega texto al final del archivo sin sobrescribir el contenido existente.
  Ideal para registros (`logs`).

#### Redirección de entrada (`<`)

``` bash
wc -l < listado.txt
```
<!-- bash -->

- El archivo `listado.txt` se utiliza como entrada para contar líneas. Es
  equivalente a `cat listado.txt | wc -l`, pero más eficiente.

#### 2.1.3 Redirección de errores (`2>` y `2>>`)

``` bash
ls archivo_inexistente 2> errores.log
```
<!-- bash -->

- Captura los mensajes de error y los guarda en `errores.log`, permitiendo
  separar el flujo de salida del flujo de errores.

``` bash
comando >> salida.log 2>> errores.log
```
<!-- bash -->

- Redirige la salida estándar y los errores a archivos distintos sin eliminar el
  contenido previo.

### 2.2 Tuberías (`|`)

Una **pipe** permite conectar la salida de un comando con la entrada de otro.
Esencialmente, permite construir flujos de datos compuestos donde cada etapa
transforma la información de forma sucesiva. Esto habilita una forma modular y
reutilizable de construcción de herramientas.

#### 2.2.1 Ejemplos fundamentales

``` bash
ls -l | grep "\.txt"
```
<!-- bash -->

- Filtra los archivos listados para mostrar solo los que terminan en `.txt`.
  `grep` es un filtro que actúa sobre líneas de texto.

``` bash
du -sh * | sort -h
```
<!-- bash -->

- Muestra el tamaño de cada archivo o directorio y ordena los resultados
  humanamente, es decir, respetando los sufijos (K, M, G).

``` bash
ps aux | grep firefox | awk '{print $2}'
```
<!-- bash -->

- Extrae los identificadores de proceso (PID) relacionados con Firefox. Este
  patrón se usa frecuentemente en automatización de administración de procesos.

### 2.3 Composición: pipes con redirecciones

Se pueden combinar ambas técnicas para realizar flujos complejos:

``` bash
cat archivo.txt | grep "error" > errores.txt
```
<!-- bash -->

- El contenido filtrado se redirige directamente a un nuevo archivo. Este patrón
  es común en procesamiento de logs, búsquedas masivas o depuración de sistemas.

``` bash
find /var/log -type f | xargs grep -i fail 2>/dev/null > fallas.txt
```
<!-- bash -->

- Busca recursivamente archivos en `/var/log`, y filtra aquellos que contienen
  la palabra "fail" (ignorando mayúsculas). Los errores se descartan y la salida
  se guarda.

## 🔎 6. Búsqueda de archivos y contenido

``` bash
find . -name "*.txt"          # Busca archivos por nombre
grep "palabra" archivo.txt    # Busca texto en archivo
grep -r "funcion" src/        # Busca recursivamente
```
<!-- bash -->

##  7. Variables y comandos útiles

```{code-block} bash
:linenos:
mi_var="Hola mundo"
echo $mi_var

# Variables de entorno
echo $HOME
echo $PATH

# Comando útil
which bash      # Ruta del ejecutable
type ls         # Muestra si es alias, función, o comando

```
<!-- {code-block} bash -->

## 🧱 8. Permisos y ejecución

``` bash
chmod +x script.sh      # Hace ejecutable un archivo
ls -l                   # Muestra permisos
```
<!-- bash -->

Permisos: `rwx` (lectura, escritura, ejecución) Ejemplo: `-rwxr-xr--` → usuario
puede todo, grupo solo lee y ejecuta, otros solo leen.

## 🔁 9. Control de procesos

``` bash
ps aux            # Lista todos los procesos
top               # Monitor en tiempo real
kill PID          # Termina un proceso por ID
&                 # Ejecuta en segundo plano
ctrl + z          # Pausa proceso (fg/bg para retomarlo)
```
<!-- bash -->

## 4. Introducción intuitiva a los scripts en Bash

Un **script** de Bash es un archivo de texto que contiene una secuencia de
comandos que Bash puede ejecutar en orden. Se utilizan para automatizar tareas
que normalmente se realizarían manualmente en la consola, con la ventaja
adicional de ser reutilizables, replicables y versionables.

### 4.1 ¿Qué es un script?

Un script puede verse como un programa simple escrito en lenguaje de comandos.
Es útil cuando se requiere repetir una serie de instrucciones o realizar tareas
complejas que involucran lógica condicional, lazos y estructuras de control.

### 4.2 Estructura básica de un script

``` bash
#!/bin/bash
# Este es un comentario

echo "Hola, mundo"
date
```
<!-- bash -->

- `#!/bin/bash`: indica que el script debe ejecutarse con Bash.
- `echo`: imprime texto.
- `date`: muestra la fecha y hora actual.

### 4.3 Ejemplo aplicado: respaldo automático

```{code-block} bash
:linenos:
#!/bin/bash
ORIGEN="$HOME/documentos"
DESTINO="$HOME/respaldo"
FECHA=$(date +%Y-%m-%d)

mkdir -p "$DESTINO"
cp -r "$ORIGEN" "$DESTINO/respaldo-$FECHA"
echo "Respaldo completado en $DESTINO/respaldo-$FECHA"

```
<!-- {code-block} bash -->

Este script:

- Define un origen y un destino.
- Usa la fecha como sufijo del respaldo.
- Crea el directorio si no existe.
- Copia los archivos.
- Informa al usuario al finalizar.

### 4.4 Permisos y ejecución

Para que un script sea ejecutable:

``` bash
chmod +x script.sh
./script.sh
```
<!-- bash -->

Esto le otorga permisos de ejecución y lo ejecuta desde el directorio actual.

### 4.5 Consideraciones formales

Desde una perspectiva de diseño de software, los scripts son herramientas de
automatización declarativa. En muchas ocasiones pueden formar parte de
**pipelines de CI/CD**, herramientas de despliegue, diagnósticos y pruebas
automatizadas.

Por ello, se recomienda aplicar buenas prácticas como:

- Validar argumentos.
- Documentar cada paso.
- Manejar errores adecuadamente.
- Utilizar nombres de variables legibles.

### 📘 11. Control de flujo

```{code-block} bash
:linenos:
# Condicional
if [ -f archivo.txt ]; then
  echo "Existe"
else
  echo "No existe"
fi

# lazo for
for archivo in *.txt; do
  echo "$archivo tiene $(wc -l < "$archivo") líneas"
done

# lazo while
while read linea; do
  echo "Línea: $linea"
done < archivo.txt

```
<!-- {code-block} bash -->

### 🧪 12. Globs, wildcards y expansión

Los patrones de expansión (globs) son una herramienta fundamental para el manejo
eficiente de archivos múltiples.

```{code-block} bash
:linenos:
*.txt       # todos los .txt
?           # un solo caracter
[abc]*      # comienza con a, b o c
[0-9]*      # comienza con un dígito
[!0-9]*     # NO comienza con un dígito
**/*.py     # todos los .py recursivamente (bash 4.0+)

echo {1..5}       # 1 2 3 4 5
echo {a..d}.txt   # a.txt b.txt c.txt d.txt
echo {001..100}   # números con padding de ceros
echo archivo.{txt,md,py}  # archivo.txt archivo.md archivo.py

```
<!-- {code-block} bash -->

**Expansión avanzada:**

```{code-block} bash
:linenos:
# Expansión aritmética
echo $((5 + 3))           # 8
echo $((2**3))            # 8 (potencia)

# Expansión de comandos
echo "Hoy es $(date +%A)"
echo "Archivos: $(ls | wc -l)"

# Expansión de parámetros
archivo="documento.txt"
echo "${archivo%.*}"      # documento (sin extensión)
echo "${archivo##*/}"     # documento.txt (solo nombre)
echo "${archivo:-backup}" # valor por defecto

```
<!-- {code-block} bash -->

### 📊 13. Comandos de análisis y procesamiento de texto

Bash incluye herramientas poderosas para el procesamiento de texto que forman el
corazón de la filosofía UNIX.

#### 13.1 Herramientas de análisis

```{code-block} bash
:linenos:
# wc - contar líneas, palabras, caracteres
wc -l archivo.txt         # líneas
wc -w archivo.txt         # palabras
wc -c archivo.txt         # caracteres

# sort - ordenar contenido
sort archivo.txt          # orden alfabético
sort -n numeros.txt       # orden numérico
sort -r archivo.txt       # orden inverso
sort -k2 datos.csv        # ordenar por segunda columna

# uniq - eliminar duplicados (requiere entrada ordenada)
sort archivo.txt | uniq   # elimina duplicados
sort archivo.txt | uniq -c # cuenta ocurrencias

```
<!-- {code-block} bash -->

#### 13.2 Búsqueda y filtrado

```{code-block} bash
:linenos:
# grep - búsqueda de patrones
grep "patrón" archivo.txt           # busca líneas que contengan "patrón"
grep -i "patrón" archivo.txt        # búsqueda sin distinción de mayúsculas
grep -r "patrón" directorio/        # búsqueda recursiva
grep -n "patrón" archivo.txt        # muestra números de línea
grep -v "patrón" archivo.txt        # líneas que NO contengan "patrón"
grep -E "patrón1|patrón2" archivo   # expresiones regulares extendidas

# find - búsqueda de archivos
find . -name "*.txt"                # archivos .txt en directorio actual
find /home -user juan -size +1M     # archivos de juan mayores a 1MB
find . -type d -name "test*"        # directorios que empiecen con "test"
find . -mtime -7                    # archivos modificados últimos 7 días
find . -executable -type f          # archivos ejecutables

```
<!-- {code-block} bash -->

#### 13.3 Transformación de texto

```{code-block} bash
:linenos:
# sed - editor de flujo
sed 's/viejo/nuevo/' archivo.txt        # reemplaza primera ocurrencia por línea
sed 's/viejo/nuevo/g' archivo.txt       # reemplaza todas las ocurrencias
sed '5d' archivo.txt                    # elimina línea 5
sed -n '10,20p' archivo.txt             # muestra líneas 10 a 20

# awk - procesamiento de texto estructurado
awk '{print $1}' datos.txt              # imprime primera columna
awk -F',' '{print $2}' datos.csv        # usa coma como separador
awk '{sum+=$3} END {print sum}' datos   # suma tercera columna
awk 'NR>1 {print $0}' archivo           # omite primera línea (header)

# cut - extraer columnas
cut -d',' -f1,3 datos.csv               # columnas 1 y 3 de CSV
cut -c1-10 archivo.txt                  # primeros 10 caracteres

```
<!-- {code-block} bash -->

### 🔧 14. Administración del sistema

#### 14.1 Información del sistema

```{code-block} bash
:linenos:
# Información básica
uname -a                    # información completa del sistema
whoami                      # usuario actual
id                          # información de usuario y grupos
uptime                      # tiempo de funcionamiento y carga
df -h                       # espacio en disco (human readable)
free -h                     # memoria RAM disponible
lscpu                       # información del procesador

# Procesos
ps aux                      # todos los procesos
ps -ef | grep nginx         # procesos específicos
top                         # monitor en tiempo real
htop                        # versión mejorada de top (si está instalada)
jobs                        # trabajos en segundo plano

```
<!-- {code-block} bash -->

#### 14.2 Gestión de procesos

```{code-block} bash
:linenos:
# Control de procesos
command &                   # ejecutar en segundo plano
nohup command &            # ejecutar sin depender de la terminal
kill PID                    # terminar proceso por ID
kill -9 PID                # forzar terminación
killall nombre_proceso      # terminar por nombre
ctrl + z                   # suspender proceso (en terminal)
fg                         # traer proceso suspendido al primer plano
bg                         # enviar proceso suspendido al segundo plano

```
<!-- {code-block} bash -->

#### 14.3 Variables de entorno

```{code-block} bash
:linenos:
# Gestión de variables
export VAR="valor"          # crear/modificar variable de entorno
echo $PATH                  # mostrar PATH actual
env                         # listar todas las variables de entorno
unset VAR                   # eliminar variable

# Variables útiles
echo $HOME                  # directorio personal
echo $USER                  # nombre de usuario
echo $SHELL                 # shell actual
echo $PWD                   # directorio actual

```
<!-- {code-block} bash -->

###  15. Redirección y tuberías avanzadas

#### 15.1 Redirección de entrada/salida

```{code-block} bash
:linenos:
# Redirección básica
comando > archivo           # sobrescribir archivo con salida
comando >> archivo          # agregar al final del archivo
comando < archivo           # usar archivo como entrada
comando 2> errores.log      # redirigir errores a archivo
comando &> todo.log         # redirigir todo (salida + errores)

# Redirección avanzada
comando 2>&1                # redirigir errores a salida estándar
comando | tee archivo.log   # mostrar en pantalla Y guardar en archivo
comando > /dev/null 2>&1    # descartar toda la salida

```
<!-- {code-block} bash -->

#### 15.2 Tuberías complejas

```{code-block} bash
:linenos:
# Combinaciones útiles
cat archivo.log | grep ERROR | sort | uniq -c | sort -nr
# ↳ errores únicos ordenados por frecuencia

ls -la | awk '{sum+=$5} END {print "Total:", sum, "bytes"}'
# ↳ suma el tamaño total de archivos

ps aux | sort -k3 -nr | head -5
# ↳ procesos que más CPU consumen

find . -name "*.log" | xargs grep -l "ERROR"
# ↳ archivos .log que contienen "ERROR"

```
<!-- {code-block} bash -->

### 🧙 16. Trucos de la terminal

#### 16.1 Navegación en el historial

``` bash
!!                          # repite el último comando
!n                          # repite el comando número n del historial
!grep                       # repite el último comando que comienza con "grep"
!?archivo                   # repite el último comando que contiene "archivo"
^viejo^nuevo               # reemplaza "viejo" por "nuevo" en último comando
```
<!-- bash -->

#### 16.2 Atajos de teclado esenciales

```{code-block} bash
:linenos:
ctrl + r                   # búsqueda inversa en el historial
ctrl + a                   # ir al inicio de la línea
ctrl + e                   # ir al final de la línea
ctrl + w                   # borrar palabra anterior
ctrl + k                   # borrar desde cursor al final
ctrl + u                   # borrar toda la línea
ctrl + l                   # limpiar pantalla (equivale a 'clear')
ctrl + c                   # interrumpir proceso actual
ctrl + d                   # cerrar terminal o EOF
ctrl + z                   # suspender proceso actual

```
<!-- {code-block} bash -->

#### 16.3 Alias y funciones útiles

```{code-block} bash
:linenos:
# Alias comunes
alias l='ls -lah'
alias gs='git status'
alias ll='ls -alF'
alias la='ls -A'
alias grep='grep --color=auto'
alias ..='cd ..'
alias ...='cd ../..'

# Funciones útiles
function mkcd() {
    mkdir -p "$1" && cd "$1"
}

function backup() {
    cp "$1" "$1.backup.$(date +%Y%m%d_%H%M%S)"
}

function extract() {
    case "$1" in
        *.tar.gz) tar -xzf "$1" ;; 
        *.zip) unzip "$1" ;; 
        *.rar) unrar e "$1" ;; 
        *) echo "Formato no soportado" ;; 
    esac
}

```
<!-- {code-block} bash -->

### 🔍 17. Expresiones regulares en Bash

Las expresiones regulares son patrones que permiten búsquedas y manipulaciones
complejas de texto.

#### 17.1 Sintaxis básica

```{code-block} bash
:linenos:
# Metacaracteres básicos
.                          # cualquier carácter
*                          # cero o más del anterior
+                          # uno o más del anterior (ERE)
?                          # cero o uno del anterior (ERE)
^                          # inicio de línea
$                          # fin de línea
[]                         # clase de caracteres
[^]                        # negación de clase

# Ejemplos con grep
grep '^[A-Z]' archivo.txt          # líneas que empiezan con mayúscula
grep '[0-9]\\{3\}' archivo.txt      # exactamente 3 dígitos
grep -E '[0-9]{2,4}' archivo.txt   # entre 2 y 4 dígitos
grep '\\b[A-Za-z]+@[A-Za-z]+\\.[A-Za-z]+\\b' emails.txt  # emails básicos

```
<!-- {code-block} bash -->

#### 17.2 Aplicaciones prácticas

```{code-block} bash
:linenos:
# Validar formato de fecha (YYYY-MM-DD)
echo "2023-12-25" | grep -E '^[0-9]{4}-[0-9]{2}-[0-9]{2}$'

# Extraer números de teléfono
grep -E '\\([0-9]{3}\\) [0-9]{3}-[0-9]{4}' contactos.txt

# Buscar direcciones IP
grep -E '([0-9]{1,3}\\.){3}[0-9]{1,3}' logs.txt

# Encontrar URLs
grep -E 'https?://[A-Za-z0-9.-]+\\.[A-Za-z]{2,}' texto.html

```
<!-- {code-block} bash -->

### 🔐 18. Seguridad básica

#### 18.1 Principios de seguridad

```{code-block} bash
:linenos:
# Nunca hagas esto (¡puede destruir el sistema!)
sudo rm -rf /              # elimina TODO el sistema
:(){ :|:& };:              # fork bomb - puede colapsar el sistema

# Uso responsable de sudo
sudo -l                    # ver permisos de sudo
sudo -u usuario comando    # ejecutar como otro usuario
sudo !!                    # ejecutar último comando con sudo

```
<!-- {code-block} bash -->

#### 18.2 Permisos de archivos

```{code-block} bash
:linenos:
# Entender permisos (rwx para owner, group, others)
ls -l archivo.txt          # -rw-r--r-- significa rw-/r--/r--
chmod 755 script.sh        # rwxr-xr-x (ejecutable para owner)
chmod u+x archivo          # agregar ejecución para owner
chmod go-w archivo         # quitar escritura para group y others
chown usuario:grupo archivo # cambiar propietario

# Umask - permisos por defecto
umask 022                  # archivos nuevos: 644, directorios: 755
umask 077                  # archivos nuevos: 600, directorios: 700

```
<!-- {code-block} bash -->

#### 18.3 Validación en scripts

```{code-block} bash
:linenos:
#!/bin/bash
# Ejemplo de script seguro

# Validar argumentos
if [ $# -lt 1 ]; then
    echo "Uso: $0 <archivo>"
    exit 1
fi

archivo="$1"

# Validar que el archivo existe
if [ ! -f "$archivo" ]; then
    echo "Error: El archivo '$archivo' no existe"
    exit 1
fi

# Validar permisos de lectura
if [ ! -r "$archivo" ]; then
    echo "Error: No se puede leer '$archivo'"
    exit 1
fi

echo "Procesando archivo seguro: $archivo"

```
<!-- {code-block} bash -->

### 🧹 19. Buenas prácticas avanzadas

#### 19.1 Scripting robusto

```{code-block} bash
:linenos:
#!/bin/bash
# Script con buenas prácticas

# Configuración estricta
set -euo pipefail  # salir en error, variables no definidas, errores en pipes

# Variables de configuración
readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly TEMP_DIR="/tmp/mi_script_$$"
readonly LOG_FILE="${SCRIPT_DIR}/mi_script.log"

# Función de limpieza
cleanup() {
    local exit_code=$?
    [ -d "$TEMP_DIR" ] && rm -rf "$TEMP_DIR"
    exit $exit_code
}
trap cleanup EXIT

# Función de logging
log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*" | tee -a "$LOG_FILE"
}

# Crear directorio temporal
mkdir -p "$TEMP_DIR"

log "Script iniciado"
# ... resto del script
log "Script completado"

```
<!-- {code-block} bash -->

#### 19.2 Manejo de errores

```{code-block} bash
:linenos:
# Verificar comandos críticos
if ! command -v git &> /dev/null; then
    echo "Error: git no está instalado"
    exit 1
fi

# Timeout para comandos que pueden colgarse
timeout 30s wget https://ejemplo.com/archivo.zip || {
    echo "Error: Timeout en descarga"
    exit 1
}

# Retry con backoff exponencial
retry_command() {
    local max_attempts=3
    local delay=1
    local attempt=1
    
    while [ $attempt -le $max_attempts ]; do
        if "$@"; then
            return 0
        fi
        
        echo "Intento $attempt falló, reintentando en ${delay}s..."
        sleep $delay
        delay=$((delay * 2))
        attempt=$((attempt + 1))
    done
    
    return 1
}

```
<!-- {code-block} bash -->

### 📈 20. Monitoreo y debugging

#### 20.1 Debugging de scripts

```{code-block} bash
:linenos:
# Ejecutar con traza
bash -x script.sh          # muestra cada comando antes de ejecutarlo
bash -v script.sh          # muestra líneas del script mientras las lee

# Dentro del script
set -x                     # activar modo debug
comando_a_debuggear
set +x                     # desactivar modo debug

# Variables de debugging
export PS4='+ ${BASH_SOURCE}:${LINENO}: ${FUNCNAME[0]:+${FUNCNAME[0]}(): }'

```
<!-- {code-block} bash -->

#### 20.2 Monitoreo del sistema

```{code-block} bash
:linenos:
# Monitoreo de recursos
watch -n 1 'df -h'         # espacio en disco cada segundo
watch -n 2 'free -h'       # memoria cada 2 segundos
iostat 1                   # I/O cada segundo
sar -u 1 5                # CPU usage cada segundo, 5 veces

# Logs del sistema
tail -f /var/log/syslog    # seguir log del sistema en tiempo real
journalctl -f              # logs de systemd en tiempo real
dmesg | tail               # mensajes del kernel

# Análisis de red
netstat -tuln              # puertos abiertos
ss -tuln                   # versión moderna de netstat
lsof -i :80                # procesos usando puerto 80

```
<!-- {code-block} bash -->

### 🚀 21. Automatización con cron

#### 21.1 Sintaxis de crontab

```{code-block} bash
:linenos:
# Editar crontab personal
crontab -e

# Formato: minuto hora día mes día_semana comando
# * * * * * comando
# | | | | |
# | | | | +--- día de la semana (0-7, 0 y 7 = domingo)
# | | | +----- mes (1-12)
# | | +------- día del mes (1-31)
# | +--------- hora (0-23)
# +----------- minuto (0-59)

# Ejemplos
0 2 * * *    /home/user/backup.sh          # diario a las 2 AM
30 14 * * 1  /home/user/weekly.sh          # lunes a las 2:30 PM
0 0 1 * *    /home/user/monthly.sh         # primer día del mes
*/15 * * * * /home/user/monitor.sh         # cada 15 minutos

```
<!-- {code-block} bash -->

#### 21.2 Tareas comunes automatizadas

```{code-block} bash
:linenos:
# Script de backup automatizado
#!/bin/bash
# /home/user/scripts/backup.sh

BACKUP_DIR="/backup"
SOURCE_DIR="/home/user/documents"
DATE=$(date +%Y%m%d_%H%M%S)

mkdir -p "$BACKUP_DIR"
tar -czf "$BACKUP_DIR/backup_$DATE.tar.gz" "$SOURCE_DIR"

# Mantener solo los últimos 7 backups
find "$BACKUP_DIR" -name "backup_*.tar.gz" -mtime +7 -delete

echo "Backup completado: backup_$DATE.tar.gz"

```
<!-- {code-block} bash -->

### 22. Ejercicios prácticos avanzados

:::{exercise} ejercicio-estructura-proyecto
:label: ejercicio-estructura-proyecto

**Ejercicio 1: Estructura de proyecto automatizada**

Creá un script que genere automáticamente una estructura completa de proyecto
con las siguientes características:
- Directorio principal con el nombre del proyecto (pasado como argumento)
- Subdirectorios: `src/`, `docs/`, `tests/`, `config/`
- Archivos iniciales: `README.md`, `LICENSE`, `.gitignore`
- El script debe validar que no existe ya un directorio con ese nombre

:::
<!-- {exercise} ejercicio-estructura-proyecto -->

:::{solution} ejercicio-estructura-proyecto

```{code-block} bash
:linenos:
#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Uso: $0 <nombre_proyecto>"
    exit 1
fi

proyecto="$1"

if [ -d "$proyecto" ]; then
    echo "Error: El directorio '$proyecto' ya existe"
    exit 1
fi

echo "Creando estructura del proyecto '$proyecto'..."
mkdir -p "$proyecto"/{src,docs,tests,config}

# Crear archivos iniciales
cat > "$proyecto/README.md" << EOF
# $proyecto

Descripción del proyecto.

## Instalación

## Uso

## Contribuir
EOF

cat > "$proyecto/.gitignore" << EOF
# Archivos temporales
*.tmp
*.log
*~

# Directorios de compilación
build/
dist/
EOF

echo "MIT License" > "$proyecto/LICENSE"

echo "Proyecto '$proyecto' creado exitosamente"
tree "$proyecto" 2>/dev/null || ls -la "$proyecto"

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-estructura-proyecto -->

:::{exercise} ejercicio-analizador-logs
:label: ejercicio-analizador-logs

**Ejercicio 2: Analizador de logs web**

Desarrollá un script que analice un archivo de log de servidor web (formato
Apache/Nginx) y genere un reporte con:
- Top 10 IPs que más requests hicieron
- Top 10 páginas más visitadas
- Errores 4xx y 5xx
- Estadísticas por hora del día

:::
<!-- {exercise} ejercicio-analizador-logs -->

:::{solution} ejercicio-analizador-logs

```{code-block} bash
:linenos:
#!/bin/bash

LOG_FILE="$1"

if [ ! -f "$LOG_FILE" ]; then
    echo "Uso: $0 <archivo_log>"
    exit 1
fi

echo "=== ANÁLISIS DE LOG: $LOG_FILE ==="
echo

echo "Top 10 IPs:"
awk '{print $1}' "$LOG_FILE" | sort | uniq -c | sort -nr | head -10
echo

echo "Top 10 páginas más visitadas:"
awk '{print $7}' "$LOG_FILE" | sort | uniq -c | sort -nr | head -10
echo

echo "Errores 4xx y 5xx:"
awk '$9 ~ /^[45]/ {print $9}' "$LOG_FILE" | sort | uniq -c | sort -nr
echo

echo "Requests por hora:"
awk '{print substr($4, 13, 2)}' "$LOG_FILE" | sort -n | uniq -c

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-analizador-logs -->

:::{exercise} ejercicio-monitor-recursos
:label: ejercicio-monitor-recursos

**Ejercicio 3: Monitor de recursos del sistema**

Creá un script de monitoreo que:
- Verifique el uso de CPU, memoria y disco
- Envíe alertas si algún recurso supera el 80%
- Guarde un log histórico de métricas
- Ejecute acciones correctivas automáticas (opcional)

:::
<!-- {exercise} ejercicio-monitor-recursos -->

:::{solution} ejercicio-monitor-recursos

```{code-block} bash
:linenos:
#!/bin/bash

LOG_DIR="/var/log/monitor"
LOG_FILE="$LOG_DIR/recursos.log"
ALERT_FILE="$LOG_DIR/alertas.log"
THRESHOLD=80

mkdir -p "$LOG_DIR"

get_cpu_usage() {
    top -bn1 | grep "Cpu(s)" | awk '{print $2}' | cut -d'%' -f1
}

get_memory_usage() {
    free | grep Mem | awk '{printf "%.0f", $3/$2 * 100.0}'
}

get_disk_usage() {
    df / | tail -1 | awk '{print $5}' | cut -d'%' -f1
}

log_metrics() {
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    local cpu=$(get_cpu_usage)
    local memory=$(get_memory_usage)
    local disk=$(get_disk_usage)
    
    echo "$timestamp,CPU:$cpu,MEM:$memory,DISK:$disk" >> "$LOG_FILE"
    
    # Verificar alertas
    if (( $(echo "$cpu > $THRESHOLD" | bc -l) )); then
        echo "$timestamp: ALERTA CPU: $cpu%" >> "$ALERT_FILE"
    fi
    
    if [ "$memory" -gt "$THRESHOLD" ]; then
        echo "$timestamp: ALERTA MEMORIA: $memory%" >> "$ALERT_FILE"
    fi
    
    if [ "$disk" -gt "$THRESHOLD" ]; then
        echo "$timestamp: ALERTA DISCO: $disk%" >> "$ALERT_FILE"
        # Acción correctiva: limpiar archivos temporales
        find /tmp -type f -atime +7 -delete 2>/dev/null
    fi
}

log_metrics

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-monitor-recursos -->

### 23. Ejercicios para practicar

:::{note}

Los siguientes ejercicios están organizados por nivel de dificultad.
Recomendamos resolverlos en orden para construir progresivamente las habilidades
necesarias.

:::
<!-- {note} -->

#### 23.1 Nivel Principiante

1. **Navegación básica**: Creá la estructura `proyectos/2024/bash/ejercicios`
   usando un solo comando y navegá hasta el último directorio.

2. **Manipulación de archivos**: Creá 5 archivos de texto con nombres
   `archivo1.txt` a `archivo5.txt`, escribí contenido diferente en cada uno
   usando `echo`.

3. **Alias personalizados**: Definí los siguientes alias en tu `~/.bashrc`:
   - `ll` para `ls -alF`
   - `la` para `ls -A`
   - `..` para `cd ..`
   - `grep` para `grep --color=auto`

#### 23.2 Nivel Intermedio

4. **Script contador**: Escribí un script que cuente cuántos archivos hay de
   cada extensión en un directorio dado como argumento.

5. **Backup inteligente**: Creá un script que haga backup de un directorio, pero
   solo de los archivos modificados en los últimos N días (N como parámetro).

6. **Limpiador de duplicados**: Desarrollá un script que encuentre y
   opcionalmente elimine archivos duplicados basándose en su checksum MD5.

#### 23.3 Nivel Avanzado

7. **Parser de configuración**: Escribí un script que lea un archivo de
   configuración en formato `clave=valor` y permita consultar valores
   específicos.

8. **Sincronizador de directorios**: Implementá un script que sincronice dos
   directorios, copiando archivos nuevos y actualizados del origen al destino.

9. **Dashboard de sistema**: Creá un script que muestre en tiempo real
   (actualizándose cada segundo) el estado del sistema: CPU, memoria, procesos
   top, conexiones de red.

#### 23.4 Desafíos Especiales

10. **Mini shell**: Implementá un shell básico que pueda ejecutar comandos
    simples, manejar pipes y redirecciones básicas.

11. **Cron automático**: Desarrollá un sistema que monitoree un directorio y
    ejecute automáticamente scripts que se coloquen en él.

12. **Generador de reportes**: Creá un script que genere reportes HTML de uso
    del sistema basándose en logs históricos.

###  24. Recursos para seguir

#### 24.1 Documentación oficial

- `man bash` → la biblia completa de Bash
- `info bash` → documentación GNU más detallada
- `bash --help` → ayuda rápida de opciones
- `help comando` → ayuda para built-ins de Bash

#### 24.2 Recursos en línea

- [TLDP Advanced Bash Guide](https://tldp.org/LDP/abs/html/) → guía avanzada
  completa
- [explainshell.com](https://explainshell.com/) → explica comandos complejos
- [ShellCheck](https://www.shellcheck.net/) → linter para scripts de shell
- [Bash Hackers Wiki](https://wiki.bash-hackers.org/) → documentación
  comunitaria

#### 24.3 Herramientas de diagnóstico

``` bash
apropos comando             # cuando no recordás el nombre exacto
whatis comando             # descripción breve de un comando
which comando              # ubicación del ejecutable
type comando               # tipo de comando (built-in, alias, función)
command -V comando         # información detallada del comando
```
<!-- bash -->

#### 24.4 Libros recomendados

- "Learning the Bash Shell" por Cameron Newham
- "Bash Cookbook" por Carl Albing y JP Vossen
- "Classic Shell Scripting" por Arnold Robbins

### 25. Consejos finales para el dominio de Bash

:::{tip} Práctica progresiva

La maestría en Bash se adquiere gradualmente. Comenzá con comandos simples y
progresivamente incorporá técnicas más avanzadas. Cada script que escribas es
una oportunidad de aprendizaje.

:::
<!-- {tip} Práctica progresiva -->

#### 25.1 Metodología de aprendizaje

1. **Experimentación segura**: Siempre probá comandos nuevos en un entorno
   controlado antes de usarlos en datos importantes.

2. **Lectura de código**: Estudiá scripts existentes en `/usr/bin`,
   `/usr/local/bin` y repositorios de GitHub.

3. **Documentación activa**: Comentá vos scripts no solo para otros, sino para
   vos mismo en el futuro.

4. **Versionado**: Usá Git para versionar tus scripts y seguir su evolución.

#### 25.2 Patrones comunes

```{code-block} bash
:linenos:
# Validación robusta de argumentos
validate_args() {
    if [ $# -lt 1 ]; then
        echo "Uso: $0 <arg1> [arg2]" >&2
        exit 1
    fi
}

# Detección de dependencias
check_dependencies() {
    local deps=("git" "curl" "jq")
    for dep in "${deps[@]}"; do
        if ! command -v "$dep" &> /dev/null; then
            echo "Error: $dep no está instalado" >&2
            exit 1
        fi
    done
}

# Configuración por defecto con override
CONFIG_FILE="${CONFIG_FILE:-"$HOME/.mi_script.conf"}"
VERBOSE="${VERBOSE:-false}"
DRY_RUN="${DRY_RUN:-false}"

```
<!-- {code-block} bash -->

#### 25.3 Integración con el ecosistema

Bash no existe en el vacío. Su verdadero poder emerge cuando se integra con:

- **Control de versiones**: Git hooks, scripts de despliegue
- **Automatización**: CI/CD pipelines, cron jobs
- **Monitoreo**: Nagios, Zabbix, scripts de health check
- **Contenedores**: Docker entrypoints, Kubernetes jobs
- **Infraestructura**: Terraform, Ansible, provisioning scripts

### 26. Ejercicios finales de integración

:::{exercise}
:label: ejercicio-devops-pipeline

**Proyecto Final: Pipeline DevOps Completo**

Implementá un pipeline completo que incluya:
1. Script de build que compile código, ejecute tests y genere artefactos
2. Script de deploy que publique en diferentes entornos (dev, staging, prod)
3. Script de rollback que permita volver a versión anterior
4. Monitor de salud que verifique que el deploy fue exitoso

:::
<!-- {exercise} -->

:::{exercise}
:label: ejercicio-toolkit-administrador

**Proyecto Final: Toolkit del Administrador**

Desarrollá un conjunto de herramientas que incluya:
1. Instalador automático de software con detección de distribución
2. Configurador de seguridad básica del sistema
3. Monitor de logs con detección de patrones sospechosos
4. Generador de reportes de sistema automatizado

:::
<!-- {exercise} -->

## [FINAL] Epílogo

Ahora tenés un conocimiento sólido de Bash que va desde los conceptos básicos
hasta técnicas avanzadas de scripting y administración de sistemas. Como diría
el viejo Ken Thompson:

> _"Cuando usás una interfaz gráfica, estás a 3 clicks de borrar todo. En la
  consola, sabés exactamente qué estás haciendo."_

### El camino hacia la maestría

El dominio de Bash es un proceso continuo. Cada problema que resuelvas con la
terminal te va a enseñar algo nuevo sobre la elegancia y el poder de la
filosofía UNIX. Recordá que:

- **La práctica hace al maestro**: Intentá resolver problemas cotidianos con
  scripts en lugar de hacerlos manualmente.
- **La comunidad es tu aliada**: Compartí tus scripts y aprendé de otros en
  GitHub, Stack Overflow y foros especializados.
- **La documentación es tu guía**: Siempre consultá `man`, `info` y recursos
  oficiales cuando tengas dudas.

### Próximos pasos recomendados

1. **Automatizá tu flujo de trabajo**: Identificá tareas repetitivas y
   automatizalas.
2. **Explorá herramientas complementarias**: `tmux`, `vim`, `git`, `docker`.
3. **Estudiá sistemas de administración**: `systemd`, configuración de
   servidores, Docker.
4. **Contribuí a proyectos open source**: Muchos proyectos necesitan mejoras en
   sus scripts de build y deploy.

:::{important} Filosofía de crecimiento continuo

En el mundo de la programación y administración de sistemas, Bash es tu
compañero de viaje constante. Desde automatizar deploys hasta diagnosticar
problemas de producción, las habilidades que desarrollaste acá te van a
acompañar a lo largo de toda tu carrera técnica.

:::
<!-- {important} Filosofía de crecimiento continuo -->

¡Nos vemos en el prompt, `~$`!

```{code-block} bash
:linenos:
$ echo "¡Felicitaciones! Ahora sos parte del club del shell avanzado."
¡Felicitaciones! Ahora sos parte del club del shell avanzado.
$ fortune | cowsay
 ________________________________
/ La terminal es el lienzo del     \
\ programador experto.             /
 --------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\n                ||----w |
                ||     ||

```
<!-- {code-block} bash -->

---

"Unix is not just an operating system, it's a way of thinking." - Brian
Kernighan

