# 🐚 Guía para aprender a usar la consola UNIX (Bash) desde cero

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
explorar y diagnosticar el sistema, asi como verificar rápidamente el
comportamiento de los diferentes pasos que pueden componenr un script de
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

```bash
$ pwd
/home/usuario
$ ls -l
-rw-r--r-- 1 usuario usuario 4096 jul 19 10:23 archivo.txt
$ echo "Hola Mundo!"
Hola Mundo!
```

- `pwd`: imprime el directorio de trabajo actual, útil para orientarse dentro de
  jerarquías complejas de carpetas.
- `ls -l`: lista los archivos del directorio con detalles como permisos,
  propietario, grupo, tamaño y fechas de modificación.
- `echo`: imprime un mensaje en la consola, en este caso, el tradicional "Hola
  Mundo!".

Tengan en cuenta que la terminal es sensible a mayusculas, y las instrucciones
deben tener la forma correcta, o de lo contrario no funcionarán.

```bash
$ PWD
PWD: command not found
```

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

```bash
$ cd proyectos; ls; echo "Directorio explorado"
```

Cada comando se ejecuta en secuencia, incluso si alguno falla. Esto permite
combinar tareas sin necesidad de un script.

- **Separación condicional**:
  - `&&`: solo ejecuta el segundo comando si el primero tiene éxito.
  - `||`: solo ejecuta el segundo comando si el primero falla.
  - Ejemplo:

```bash
$ make && ./programa
```

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

```bash
$ cd /etc
$ pwd
/etc
$ cd ~
$ pwd
/home/usuario
```

### 2.2 Listado de contenidos

- `ls`: lista los archivos del directorio.
- `ls -l`: muestra detalles como permisos y tamaño.
- `ls -a`: incluye archivos ocultos.
- `ls -lh`: usa unidades legibles por humanos.

```bash
$ ls -lh
-rw-r--r-- 1 usuario usuario 1.2K jul 19 10:23 notas.txt
```

### 2.3 Creación de directorios y archivos

- `mkdir nombre`: crea un nuevo directorio.
- `mkdir -p ruta/compuesta`: crea varios niveles si no existen.
- `touch archivo`: crea un archivo vacío o actualiza su fecha de modificación.

```bash
$ mkdir proyectos
$ cd proyectos
$ touch main.c
```

### 2.4 Copia, movimiento y eliminación

- `cp origen destino`: copia archivos.
- `cp -r origen destino`: copia directorios recursivamente.
- `mv origen destino`: mueve o renombra.
- `rm archivo`: elimina archivos.
- `rm -r directorio`: elimina directorios recursivamente.
- `rm -rf`: eliminación forzada, sin confirmación.

```bash
$ cp datos.txt copia.txt
$ mv copia.txt ../backup/
$ rm -r carpeta_antigua
```

### 2.5 Inspección del contenido de archivos

- `cat archivo`: imprime el contenido.
- `less archivo`: permite navegación por páginas (`/` para buscar, `q` para
  salir).
- `head -n N`: muestra las primeras `N` líneas.
- `tail -n N`: muestra las últimas `N` líneas.

```bash
$ head -n 5 log.txt
```

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

```bash
ls -l > listado.txt
```

- Crea (o sobrescribe) el archivo `listado.txt` con la salida del comando.

```bash
echo "Nueva entrada" >> listado.txt
```

- Agrega texto al final del archivo sin sobrescribir el contenido existente.
  Ideal para registros (`logs`).

#### Redirección de entrada (`<`)

```bash
wc -l < listado.txt
```

- El archivo `listado.txt` se utiliza como entrada para contar líneas. Es
  equivalente a `cat listado.txt | wc -l`, pero más eficiente.

#### 2.1.3 Redirección de errores (`2>` y `2>>`)

```bash
ls archivo_inexistente 2> errores.log
```

- Captura los mensajes de error y los guarda en `errores.log`, permitiendo
  separar el flujo de salida del flujo de errores.

```bash
comando >> salida.log 2>> errores.log
```

- Redirige la salida estándar y los errores a archivos distintos sin eliminar el
  contenido previo.

### 2.2 Tuberías (`|`)

Una **pipe** permite conectar la salida de un comando con la entrada de otro.
Esencialmente, permite construir flujos de datos compuestos donde cada etapa
transforma la información de forma sucesiva. Esto habilita una forma modular y
reutilizable de construcción de herramientas.

#### 2.2.1 Ejemplos fundamentales

```bash
ls -l | grep "\.txt"
```

- Filtra los archivos listados para mostrar solo los que terminan en `.txt`.
  `grep` es un filtro que actúa sobre líneas de texto.

```bash
du -sh * | sort -h
```

- Muestra el tamaño de cada archivo o directorio y ordena los resultados
  humanamente, es decir, respetando los sufijos (K, M, G).

```bash
ps aux | grep firefox | awk '{print $2}'
```

- Extrae los identificadores de proceso (PID) relacionados con Firefox. Este
  patrón se usa frecuentemente en automatización de administración de procesos.

### 2.3 Composición: pipes con redirecciones

Se pueden combinar ambas técnicas para realizar flujos complejos:

```bash
cat archivo.txt | grep "error" > errores.txt
```

- El contenido filtrado se redirige directamente a un nuevo archivo. Este patrón
  es común en procesamiento de logs, búsquedas masivas o depuración de sistemas.

```bash
find /var/log -type f | xargs grep -i fail 2>/dev/null > fallas.txt
```

- Busca recursivamente archivos en `/var/log`, y filtra aquellos que contienen
  la palabra "fail" (ignorando mayúsculas). Los errores se descartan y la salida
  se guarda.

## 🔎 6. Búsqueda de archivos y contenido

```bash
find . -name "*.txt"          # Busca archivos por nombre
grep "palabra" archivo.txt    # Busca texto en archivo
grep -r "funcion" src/        # Busca recursivamente
```

## 🧮 7. Variables y comandos útiles

```bash
mi_var="Hola mundo"
echo $mi_var

# Variables de entorno
echo $HOME
echo $PATH

# Comando útil
which bash      # Ruta del ejecutable
type ls         # Muestra si es alias, función, o comando
```

## 🧱 8. Permisos y ejecución

```bash
chmod +x script.sh      # Hace ejecutable un archivo
ls -l                   # Muestra permisos
```

Permisos: `rwx` (lectura, escritura, ejecución) Ejemplo: `-rwxr-xr--` → usuario
puede todo, grupo solo lee y ejecuta, otros solo leen.

## 🔁 9. Control de procesos

```bash
ps aux            # Lista todos los procesos
top               # Monitor en tiempo real
kill PID          # Termina un proceso por ID
&                 # Ejecuta en segundo plano
ctrl + z          # Pausa proceso (fg/bg para retomarlo)
```

## 4. Introducción intuitiva a los scripts en Bash

Un **script** de Bash es un archivo de texto que contiene una secuencia de
comandos que Bash puede ejecutar en orden. Se utilizan para automatizar tareas
que normalmente se realizarían manualmente en la consola, con la ventaja
adicional de ser reutilizables, replicables y versionables.

### 4.1 ¿Qué es un script?

Un script puede verse como un programa simple escrito en lenguaje de comandos.
Es útil cuando se requiere repetir una serie de instrucciones o realizar tareas
complejas que involucran lógica condicional, bucles y estructuras de control.

### 4.2 Estructura básica de un script

```bash
#!/bin/bash
# Este es un comentario

echo "Hola, mundo"
date
```

- `#!/bin/bash`: indica que el script debe ejecutarse con Bash.
- `echo`: imprime texto.
- `date`: muestra la fecha y hora actual.

### 4.3 Ejemplo aplicado: respaldo automático

```bash
#!/bin/bash
ORIGEN="$HOME/documentos"
DESTINO="$HOME/respaldo"
FECHA=$(date +%Y-%m-%d)

mkdir -p "$DESTINO"
cp -r "$ORIGEN" "$DESTINO/respaldo-$FECHA"
echo "Respaldo completado en $DESTINO/respaldo-$FECHA"
```

Este script:

- Define un origen y un destino.
- Usa la fecha como sufijo del respaldo.
- Crea el directorio si no existe.
- Copia los archivos.
- Informa al usuario al finalizar.

### 4.4 Permisos y ejecución

Para que un script sea ejecutable:

```bash
chmod +x script.sh
./script.sh
```

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

```bash
# Condicional
if [ -f archivo.txt ]; then
  echo "Existe"
else
  echo "No existe"
fi

# Bucle for
for archivo in *.txt; do
  echo "$archivo tiene $(wc -l < "$archivo") líneas"
done

# Bucle while
while read linea; do
  echo "Línea: $linea"
done < archivo.txt
```

### 🧪 12. Globs, wildcards y expansión

```bash
*.txt       # todos los .txt
?           # un solo caracter
[abc]*      # comienza con a, b o c

echo {1..5}       # 1 2 3 4 5
echo {a..d}.txt   # a.txt b.txt c.txt d.txt
```

## 🧙 13. Trucos de la terminal

- `!!` → repite el último comando
- `!n` → repite el comando número n del historial
- `!grep` → repite el último comando que comienza con "grep"
- `ctrl + r` → búsqueda inversa en el historial
- `alias` → crea atajos personalizados:

  ```bash
  alias l='ls -lah'
  alias gs='git status'
  ```

- `man comando` → abre el manual del comando

Una recomendación general, es que, a pesar de que son aceptados, la terminal es
mas facil de usar cuando los archivos y directorios no tienen espacios o acentos.

Esto lo van a descubrir ustedes mismos con el uso regular de la consola de todas formas.

## 🔐 14. Seguridad básica

- Nunca hagas `sudo rm -rf /`
- Usá `sudo` con criterio: es como dispararte en el pie con root.
- Validá entradas si escribís scripts.

## 🧹 15. Buenas prácticas

- Escribí scripts portables (`#!/bin/bash`, no `/bin/sh` si usás características
  propias de Bash).
- Usá comillas `"${var}"` siempre que puedas, para evitar errores con espacios.
- Probá scripts en entornos controlados antes de correrlos en producción.

## 📚 16. Recursos para seguir

- `man bash` → la biblia
- [TLDP Advanced Bash Guide](https://tldp.org/LDP/abs/html/)
- `bash --help`
- [explainshell.com](https://explainshell.com/)
- `apropos comando` → cuando no recordás el nombre

## 🧩 17. Ejercicios para practicar

1. Crear una estructura de carpetas `proyectos/2025/julio` con un solo comando.
2. Escribir un script que cuente cuántos archivos `.c` hay en un directorio.
3. Crear un alias llamado `ll` para `ls -lAh`.
4. Escribir un script que recorra todos los `.txt` y diga cuántas líneas tiene
   cada uno.
5. Automatizar con `cron` una tarea que borre los logs viejos cada semana.

## 🏁 Epílogo

Ahora sabés lo suficiente como para dejar de copiar-pegar comandos sin entender.
Como diría el viejo Ken Thompson:

> _"Cuando usás una interfaz gráfica, estás a 3 clicks de borrar todo. En la
> consola, sabés exactamente qué estás haciendo."_

¡Nos vemos en el prompt, `~$`!

```bash
$ echo "¡Felicitaciones! Ya sos parte del club del shell."
```
