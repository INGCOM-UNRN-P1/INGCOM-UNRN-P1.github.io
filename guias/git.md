---
title: Guía git base
subtitle: Git para principiantes, control de versiones esencial.
---

(intro-git)=
## ¿Por qué usar Git?

Git es un sistema de control de versiones distribuido que te permite llevar un
registro detallado de los cambios en tu código. Es como tener un "historial de
cambios" súper poderoso que no solo guarda qué cambió, sino también quién lo
cambió, cuándo y por qué.

Esta guía te llevará desde la {ref}`instalacion-git` hasta dominar los
{ref}`comandos-esenciales` para uso diario, incluyendo cómo trabajar con
{ref}`repositorios-remotos` como GitHub. Al final entenderás perfectamente el
{ref}`flujo-trabajo-basico` que usan los desarrolladores profesionales.

### Ventajas del control de versiones

- **Historial completo**: Podés ver cada cambio que hiciste en tu proyecto
- **Respaldo automático**: Tu código está seguro, nunca más vas a perder trabajo
- **Experimentación segura**: Probá cambios sin miedo a romper lo que funciona
- **Colaboración**: Trabajá con otros sin pisar el código del compañero
- **Portabilidad**: Llevá tu proyecto completo a cualquier computadora

:::{note} Un poco de historia

Git fue creado por Linus Torvalds (el mismo creador de Linux) en 2005. Hoy en
día es el estándar de facto para control de versiones en el desarrollo de
software.

:::
<!-- {note} Un poco de historia -->

(conceptos-fundamentales)=
## Conceptos fundamentales

Antes de empezar a usar Git, es importante entender algunos conceptos clave.
Estos conceptos aparecerán constantemente cuando uses los
{ref}`comandos-esenciales` y entender bien la diferencia entre el
{ref}`working-directory`, {ref}`staging-area` y los {ref}`commit-concepto` es
fundamental para dominar Git.

(repositorio-concepto)=
### Repositorio (repo)

Es una carpeta de proyecto que Git está "controlando". Contiene todos los
archivos de tu proyecto más un historial completo de sus cambios.

(commit-concepto)=
### commit

Es como una "foto" de tu proyecto en un momento específico. Cada commit tiene:

- Los cambios realizados
- Un mensaje descriptivo
- Fecha y hora
- Autor del cambio

(working-directory)=
### Working Directory (Directorio de trabajo)

Es donde tenés los archivos en los que estás trabajando actualmente.

(staging-area)=
### Staging Area (Área de preparación)

Es un espacio intermedio donde "preparás" los cambios antes de confirmarlos con
un commit.

(estados-archivos)=
### Estados de los archivos

:::{mermaid}

graph LR
    A[Untracked] --> B[Staged]
    B --> C[Committed]
    C --> D[Modified]
    D --> B

:::
<!-- {mermaid} -->

- **Untracked**: Git no conoce el archivo
- **Staged**: El archivo está preparado para el próximo commit
- **Committed**: El archivo está guardado en el historial
- **Modified**: El archivo fue modificado desde el último commit

(instalacion-configuracion)=
## Instalación y configuración inicial

(instalacion-git)=
### Instalación

**En Linux (Ubuntu/Debian):**

``` bash
sudo apt update
sudo apt install git
```
<!-- bash -->

**En Linux (CentOS/RHEL/Fedora):**

``` bash
sudo dnf install git
```
<!-- bash -->

**En macOS:**

``` bash
# Con Homebrew
brew install git

# O usar el que viene con Xcode
xcode-select --install
```
<!-- bash -->

**En Windows:**

- Descargá Git desde [git-scm.com](https://git-scm.com)
- O usá Git Bash que viene incluido

(configuracion-inicial)=
### Configuración inicial

Antes de usar Git por primera vez, configurá tu identidad. Esta información
aparecerá en todos los {ref}`commit-concepto` que hagas:

``` bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@ejemplo.com"
```
<!-- bash -->

Configuraciones útiles adicionales:

```{code-block} bash
:linenos:
# Editor por defecto (opcional)
git config --global core.editor "code --wait"  # VS Code
git config --global core.editor "nano"         # Nano (simple)

# Colores en la terminal
git config --global color.ui auto

# Verificar configuración
git config --list

```
<!-- {code-block} bash -->

(primeros-pasos)=
## Primeros pasos: tu primer repositorio

(crear-repositorio)=
### Crear un nuevo repositorio

``` bash
# Crear directorio y entrar
mkdir mi-proyecto
cd mi-proyecto

# Inicializar Git
git init
```
<!-- bash -->

Esto crea una carpeta oculta `.git` donde Git guarda toda la información del
repositorio. Una vez inicializado, podés comenzar a usar todos los
{ref}`comandos-esenciales` para gestionar tus archivos.

(primer-commit)=
### Tu primer commit

```{code-block} bash
:linenos:
# Crear un archivo
echo "# Mi Primer Proyecto" > README.md

# Ver el estado
git status

# Agregar archivo al staging area
git add README.md

# Verificar el estado nuevamente
git status

# Hacer el commit
git commit -m "Primer commit: agregar README"

```
<!-- {code-block} bash -->

:::{tip} Próximo paso Después de tu primer commit, considerá crear un

{ref}`archivo-gitignore` para evitar agregar archivos innecesarios a tu
repositorio. 

Podemos consultar el repositorio
[github/gitignore](https://github.com/github/gitignore)
para ver ejemplos por tipo de proyecto para no tener que analizar de cero que
tenemos
que dejar afuera del repositorio.

:::
<!-- {tip} Próximo paso Después de tu primer commit, considerá crear un -->

:::{tip} Mensajes de commit

Los mensajes de commit deben ser claros y descriptivos. Explicá qué hiciste, no
cómo lo hiciste. Ejemplo: "Agregar validación de email" en lugar de "cambios". Y
aunque para empezar, podemos dejar cualquier cosa, con el tiempo van a ver lo
poderoso que es tener un historial más detallado.

:::
<!-- {tip} Mensajes de commit -->

(comandos-esenciales)=
## Comandos esenciales para uso diario

(git-status)=
### git status - ¿Qué está pasando?

`git status` es tu comando de diagnóstico más importante. Te muestra el estado
actual de tu repositorio, incluyendo qué archivos fueron modificados, cuáles
están en el staging area listos para commit, y cuáles son completamente nuevos
(untracked). Es como preguntarle a Git "¿qué está pasando aquí?" y obtener un
resumen completo de la situación. Usalo constantemente para entender dónde estás
parado antes de hacer cualquier operación.

``` bash
git status
```
<!-- bash -->

Este comando te muestra:

- Qué archivos cambiaron
- Qué está en el staging area
- Qué archivos son nuevos (untracked)

(git-add)=
### git add - Preparar cambios

`git add` es el comando que mueve archivos desde tu directorio de trabajo al
{ref}`staging-area`. Piensa en el staging area como un "área de preparación"
donde seleccionás exactamente qué cambios querés incluir en tu próximo
{ref}`commit-concepto`. Esto te permite hacer commits granulares y específicos,
incluso si modificaste múltiples archivos. Podés agregar archivos individuales,
grupos de archivos, o todos los cambios de una vez. Es fundamental para mantener
un historial limpio y organizado.

```{code-block} bash
:linenos:
# Agregar un archivo específico
git add archivo.txt

# Agregar varios archivos
git add archivo1.txt archivo2.txt

# Agregar todos los archivos modificados
git add .

# Agregar archivos por patrón
git add *.py        # todos los .py
git add src/        # todo en la carpeta src

```
<!-- {code-block} bash -->

(git-commit)=
### git commit - Confirmar cambios

`git commit` toma todos los archivos que están en el {ref}`staging-area` y los
guarda permanentemente en el historial de tu {ref}`repositorio-concepto`. Cada
commit es como una "fotografía" de tu proyecto en ese momento específico, con un
mensaje descriptivo que explica qué cambios se hicieron y por qué. Es
irreversible en el sentido de que una vez hecho el commit, esos cambios quedan
grabados en la historia para siempre. Los buenos mensajes de commit son
cruciales para entender la evolución del proyecto más adelante.

```{code-block} bash
:linenos:
# Commit con mensaje
git commit -m "Descripción del cambio"

# Commit con mensaje más detallado
git commit -m "Título del commit

Descripción más detallada de lo que se cambió
y por qué se hizo el cambio."

# Agregar y hacer commit en un paso (solo archivos ya tracked)
git commit -am "Mensaje del commit"

```
<!-- {code-block} bash -->

(git-log)=
### git log - Historial de cambios

`git log` te muestra el historial completo de commits en tu
{ref}`repositorio-concepto`. Es como un libro de registro que documenta toda la
evolución de tu proyecto, mostrando quién hizo qué cambios, cuándo y por qué.
Cada entrada incluye el hash único del commit, el autor, la fecha y el mensaje
descriptivo. Con diferentes opciones podés personalizar la vista: ver solo una
línea por commit, buscar commits específicos, ver estadísticas de archivos
modificados, o incluso filtrar por autor o fecha. Es esencial para entender cómo
llegó tu proyecto al estado actual.

```{code-block} bash
:linenos:
# Ver historial completo
git log

# Ver historial compacto (una línea por commit)
git log --oneline

# Ver últimos 5 commits
git log -5

# Ver cambios en archivos
git log --stat

# Buscar commits por mensaje
git log --grep="bugfix"

```
<!-- {code-block} bash -->

(git-diff)=
### git diff - Ver diferencias

`git diff` te muestra exactamente qué cambió entre diferentes estados de tu
proyecto. Sin argumentos, compara tu {ref}`working-directory` actual con el
{ref}`staging-area`, mostrándote qué modificaciones aún no agregaste. Con
`--staged` compara el staging area con el último commit, y con referencias
específicas podés comparar cualquier punto en la historia. Cada diferencia se
muestra línea por línea, con colores que indican qué se agregó (verde) y qué se
eliminó (rojo). Es fundamental para revisar tus cambios antes de hacer un commit
y para entender qué modificó alguien más en el código.

```{code-block} bash
:linenos:
# Ver cambios no preparados (working directory vs staging)
git diff

# Ver cambios preparados (staging vs último commit)
git diff --staged

# Ver diferencias de un archivo específico
git diff archivo.txt

# Comparar con un commit anterior
git diff HEAD~1    # comparar con el commit anterior
git diff HEAD~3    # comparar con 3 commits atrás

```
<!-- {code-block} bash -->

(trabajando-archivos)=
## Trabajando con archivos

(agregar-archivos-nuevos)=
### Agregar archivos nuevos

Para que Git empiece a hacer seguimiento de un archivo nuevo, primero tenés que
agregarlo explícitamente con {ref}`git-add`. Los archivos nuevos aparecen como
"untracked" en {ref}`git-status` hasta que los agregues al staging area. Una vez
agregados y confirmados con {ref}`git-commit`, Git comenzará a monitorear todos
los cambios futuros en esos archivos.

```{code-block} bash
:linenos:
# Creamos el archivo
touch nuevo-archivo.py
echo 'print("Hola mundo")' > nuevo-archivo.py

# Git no lo conoce todavía
git status

# Agregarlo al tracking
git add nuevo-archivo.py
git commit -m "Agregar script hola mundo"

```
<!-- {code-block} bash -->

(modificar-archivos)=
### Modificar archivos existentes

Cuando modificás un archivo que Git ya está trackeando, aparecerá como
"modified" en {ref}`git-status`. Git detecta automáticamente todos los cambios,
pero no los incluye en commits hasta que explícitamente los agregues con
{ref}`git-add`. Esto te permite revisar los cambios con {ref}`git-diff` antes de
confirmarlos, asegurándote de que solo incluís las modificaciones que realmente
querés guardar en el historial.

```{code-block} bash
:linenos:
# Modificar archivo
echo 'print("Hola Git!")' >> nuevo-archivo.py

# Ver los cambios
git diff nuevo-archivo.py

# Preparar y confirmar cambios
git add nuevo-archivo.py
git commit -m "Actualizar mensaje de saludo"

```
<!-- {code-block} bash -->

(git-mv)=
### git mv - Renombrar archivos

`git mv` le dice a Git que un archivo fue renombrado o movido, preservando su
historial completo. Es superior a renombrar manualmente porque Git entiende que
es el mismo archivo con nuevo nombre, manteniendo todo el historial de cambios
asociado. Si renombrás manualmente, Git lo ve como un archivo eliminado y otro
nuevo creado, perdiendo la continuidad histórica. Siempre usá `git mv` para
mantener la integridad del historial de versiones.

```{code-block} bash
:linenos:
# Renombrar usando Git (recomendado)
git mv archivo-viejo.txt archivo-nuevo.txt
git commit -m "Renombrar archivo"

# Si ya renombraste manualmente
mv archivo-viejo.txt archivo-nuevo.txt
git add archivo-nuevo.txt
git rm archivo-viejo.txt
git commit -m "Renombrar archivo"

```
<!-- {code-block} bash -->

(git-rm)=
### git rm - Eliminar archivos

`git rm` elimina archivos tanto del sistema de archivos como del tracking de Git
en una sola operación. Es diferente a simplemente borrar el archivo manualmente,
porque también le dice a Git que deje de hacerle seguimiento. Con `--cached`
podés mantener el archivo físicamente pero sacarlo del control de versiones
(útil para archivos que agregaste por error al repo). Es la forma correcta de
"des-trackear" archivos sin perder el trabajo local.

```{code-block} bash
:linenos:
# Eliminar del sistema de archivos y de Git
git rm archivo-innecesario.txt
git commit -m "Eliminar archivo innecesario"

# Solo eliminar de Git (mantener en el sistema)
git rm --cached archivo-secreto.txt
git commit -m "Dejar de trackear archivo secreto"

```
<!-- {code-block} bash -->

(deshaciendo-cambios)=
## Deshaciendo cambios

(git-restore)=
### git restore - Descartar cambios no confirmados

`git restore` (o `git checkout --` en versiones anteriores) descarta
completamente las modificaciones no guardadas en tu {ref}`working-directory`,
regresando los archivos al estado del último commit. Es como un "deshacer"
definitivo para cambios que no querés conservar. Una vez ejecutado, los cambios
se pierden permanentemente, así que usalo solo cuando estés seguro de que querés
eliminar las modificaciones. Es útil cuando experimentaste algo que no funcionó
y querés volver al estado conocido y estable.

```{code-block} bash
:linenos:
# Descartar cambios en un archivo específico
git checkout -- archivo.txt

# Descartar todos los cambios no confirmados
git checkout -- .

# Alternativa moderna (Git 2.23+)
git restore archivo.txt
git restore .

```
<!-- {code-block} bash -->

(git-restore-staged)=
### git restore --staged - Quitar archivos del staging area

`git restore --staged` (o `git reset HEAD` en versiones anteriores) mueve
archivos desde el {ref}`staging-area` de vuelta al {ref}`working-directory` sin
perder los cambios. Es como "desagregar" archivos que agregaste con
{ref}`git-add` pero que decidiste no incluir en el próximo commit. Los cambios
permanecen en tus archivos, solo se quitan del área de preparación. Es perfecto
para cuando agregaste demasiados archivos de una vez y querés hacer commits más
específicos y granulares.

```{code-block} bash
:linenos:
# Quitar archivo específico del staging
git reset HEAD archivo.txt

# Quitar todos los archivos del staging
git reset HEAD

# Alternativa moderna (Git 2.23+)
git restore --staged archivo.txt
git restore --staged .

```
<!-- {code-block} bash -->

(git-commit-amend)=
### git commit --amend - Modificar el último commit

`git commit --amend` te permite "editar" el último commit, ya sea cambiando su
mensaje o agregando archivos que olvidaste incluir. En realidad no modifica el
commit existente, sino que crea uno nuevo reemplazando al anterior. Es
extremadamente útil para corregir errores menores inmediatamente después de
hacer un commit, como typos en el mensaje o archivos olvidados. Sin embargo, es
peligroso si ya compartiste el commit con otros ({ref}`git-push`), porque
cambiar el historial público puede crear conflictos para otros colaboradores.

``` bash
# Cambiar el mensaje del último commit
git commit --amend -m "Mensaje corregido"

# Agregar archivos olvidados al último commit
git add archivo-olvidado.txt
git commit --amend --no-edit
```
<!-- bash -->

:::{important} Cuidado con `--amend`

Solo usá `--amend` en commits que **no hayas compartido con otros** (`git push`)
ya que cambiar el historial público puede causar problemas.

:::
<!-- {important} Cuidado con `--amend` -->

(git-reset-revert)=
### git reset y git revert - Volver atrás en el tiempo

`git reset --hard` mueve tu {ref}`repositorio-concepto` a un commit anterior,
eliminando completamente todos los commits posteriores. Es "destructivo" porque
pierdes permanentemente el trabajo realizado después de ese punto. En contraste,
`git revert` crea un nuevo commit que deshace los cambios de un commit
específico, preservando todo el historial. `git reset` reescribe la historia,
`git revert` la extiende. Para trabajo colaborativo siempre preferí `git revert`
porque no altera el historial que otros podrían tener.

```{code-block} bash
:linenos:
# Ver historial para encontrar el commit
git log --oneline

# Volver a un commit específico (DESTRUCTIVO)
git reset --hard abc1234

# Crear un nuevo commit que deshace cambios (SEGURO)
git revert abc1234

```
<!-- {code-block} bash -->

(archivo-gitignore)=
## Archivo .gitignore

El archivo `.gitignore` le dice a Git qué archivos o carpetas debe ignorar
completamente, como si no existieran. Es esencial para evitar que archivos
temporales, dependencias generadas automáticamente, o información sensible
terminen en tu {ref}`repositorio-concepto`. Una vez que un archivo está listado
en `.gitignore`, Git no lo mostrará en {ref}`git-status` ni permitirá agregarlo
accidentalmente. Es una de las primeras cosas que deberías configurar en
cualquier proyecto nuevo.

Podemos revisar [GitHub/gitignore](https://github.com/github/gitignore) para
ejemplos ajustados a diferentes tipos de proyectos.

(crear-gitignore)=
### Crear .gitignore

``` bash
# Crear el archivo
touch .gitignore
```
<!-- bash -->

### Patrones comunes

```{code-block} gitignore
:linenos:
# Archivos del sistema
.DS_Store
Thumbs.db

# Archivos de backup
*.bak
*.tmp
*~

# Logs
*.log
logs/

# Dependencias
node_modules/
venv/
__pycache__/

# Archivos de configuración local
.env
config.local.json

# Archivos compilados
*.o
*.exe
*.class

# IDEs
.vscode/
.idea/
*.swp
*.swo

```
<!-- {code-block} gitignore -->

(sintaxis-gitignore)=
### Sintaxis de .gitignore

```{code-block} gitignore
:linenos:
archivo.txt         # ignorar archivo específico
*.log              # ignorar todos los .log
logs/              # ignorar carpeta completa
!importante.log    # NO ignorar este archivo (excepción)
docs/**/*.pdf      # ignorar PDFs en docs y subcarpetas
temp/*             # ignorar contenido de temp, pero no temp/

```
<!-- {code-block} gitignore -->

(repositorios-remotos)=
## Trabajando con repositorios remotos

(git-remote)=
### git remote - Conectar con GitHub/GitLab

`git remote` gestiona las conexiones entre tu repositorio local y repositorios
remotos (como GitHub). Un "remoto" es simplemente un repositorio que existe en
otro lugar (servidor, nube, otra computadora) al que podés enviar y desde el
cual podés recibir cambios. Por convención, el remoto principal se llama
"origin". Configurar remotos te permite sincronizar tu trabajo local con
servicios en la nube, colaborar con otros, y tener respaldos automáticos de tu
código.

```{code-block} bash
:linenos:
# Agregar un remoto llamado 'origin'
git remote add origin https://github.com/usuario/mi-proyecto.git

# Ver remotos configurados
git remote -v

# Cambiar URL del remoto
git remote set-url origin https://github.com/usuario/nuevo-repo.git

```
<!-- {code-block} bash -->

(git-push)=
### git push - Subir cambios

`git push` envía tus commits locales al repositorio remoto, sincronizando tu
trabajo con el servidor. Es como "publicar" tus cambios para que otros los vean
o para tener una copia de respaldo en la nube. La primera vez necesitás
especificar con `-u` (upstream) qué rama remota debe trackear tu rama local.
Después de eso, un simple `git push` es suficiente. Solo podés hacer push de
commits que ya confirmaste localmente; los cambios en tu
{ref}`working-directory` o {ref}`staging-area` no se suben hasta que hagas
{ref}`git-commit`.

```{code-block} bash
:linenos:
# Primera vez (establecer upstream)
git push -u origin main

# Siguientes veces
git push

# Push específico
git push origin main

```
<!-- {code-block} bash -->

(git-pull)=
### git pull - Bajar cambios

`git pull` descarga commits del repositorio remoto y los fusiona automáticamente
con tu trabajo local. Es la combinación de `git fetch` (descargar cambios) y
`git merge` (fusionar cambios). Usalo al comenzar a trabajar para asegurarte de
tener la versión más reciente del proyecto, especialmente en proyectos
colaborativos. Si hay conflictos entre tu trabajo local y los cambios remotos,
Git te pedirá que los resuelvas manualmente. Es esencial para mantener tu copia
local sincronizada con el trabajo de otros colaboradores.

``` bash
# Bajar y fusionar cambios del remoto
git pull

# Equivale a hacer:
git fetch    # descargar cambios
git merge    # fusionar cambios
```
<!-- bash -->

(git-clone)=
### git clone - Clonar un repositorio existente

`git clone` descarga una copia completa de un repositorio remoto a tu
computadora local, incluyendo todo el historial de commits, todas las ramas, y
toda la información del proyecto. Es como "fotocopiar" un proyecto completo
desde GitHub (u otro servicio) a tu máquina. Automáticamente configura el remoto
"origin" apuntando al repositorio original y establece el tracking de ramas. Es
la forma estándar de comenzar a trabajar en un proyecto existente o de obtener
el código de cualquier proyecto open source.

```{code-block} bash
:linenos:
# Clonar repositorio
git clone https://github.com/usuario/proyecto.git

# Clonar en carpeta específica
git clone https://github.com/usuario/proyecto.git mi-carpeta

# Ver información del repositorio clonado
cd proyecto
git remote -v
git log --oneline -5

```
<!-- {code-block} bash -->

(flujo-trabajo-basico)=
## Flujo de trabajo básico

(flujo-diario)=
### Flujo diario típico

Este es el flujo que vas a repetir docenas de veces por día cuando trabajes con
Git. Primero verificás el estado con {ref}`git-status`, hacés modificaciones a
tus archivos, revisás los cambios con {ref}`git-diff`, los preparás con
{ref}`git-add`, los confirmás con {ref}`git-commit` con un mensaje descriptivo,
y finalmente los subís con {ref}`git-push`. Este ciclo se vuelve tan natural
como respirar y es la base de todo desarrollo profesional con control de
versiones.

```{code-block} bash
:linenos:
# 1. Ver estado actual
git status

# 2. Hacer cambios en archivos
# ... editar código ...

# 3. Ver qué cambió
git diff

# 4. Preparar cambios
git add .

# 5. Confirmar cambios
git commit -m "Descripción clara del cambio"

# 6. Subir al repositorio remoto
git push

```
<!-- {code-block} bash -->

(flujo-nuevo-proyecto)=
### Flujo para nuevo proyecto

Este flujo te guía desde una carpeta vacía hasta un proyecto completamente
configurado con Git y conectado a un repositorio remoto. Iniciás creando el
{ref}`repositorio-concepto` local con `git init`, configurás el
{ref}`archivo-gitignore` desde el principio para evitar problemas futuros, hacés
tu {ref}`primer-commit`, conectás con el remoto usando {ref}`git-remote`, y
subís todo con {ref}`git-push`. Es el proceso estándar para comenzar cualquier
proyecto nuevo que querés versionar.

```{code-block} bash
:linenos:
# 1. Crear proyecto local
mkdir mi-proyecto
cd mi-proyecto
git init

# 2. Crear archivos iniciales
echo "# Mi Proyecto" > README.md
echo "*.log" > .gitignore

# 3. Primer commit
git add .
git commit -m "Primer commit: estructura inicial"

# 4. Conectar con remoto
git remote add origin https://github.com/usuario/mi-proyecto.git

# 5. Subir código
git push -u origin main

```
<!-- {code-block} bash -->

(comandos-informacion)=
## Comandos de información útiles

(estado-configuracion)=
### Estado y configuración

Estos comandos te dan información crucial sobre el estado actual de tu
repositorio y su configuración. {ref}`git-status` te muestra qué está pasando
ahora, `git config --list` muestra toda tu configuración de Git, y
{ref}`git-remote` con `git log` te dan contexto sobre conexiones remotas e
historial. Son comandos "de solo lectura" que nunca modifican nada, perfectos
para orientarte cuando no estás seguro del estado actual del proyecto.

```{code-block} bash
:linenos:
# Estado actual
git status

# Configuración actual
git config --list

# Información del repositorio
git remote -v
git log --oneline -10

# Ver archivos tracked
git ls-files

# Ver espacio usado
du -sh .git

```
<!-- {code-block} bash -->

### Exploración del historial

```{code-block} bash
:linenos:
# Historial gráfico simple
git log --graph --oneline

# Historial con detalles
git log --stat

# Buscar en commits
git log --grep="fix"
git log --author="mi-nombre"

# Ver cambios de un archivo
git log -p archivo.txt

# Ver quién modificó cada línea
git blame archivo.txt

```
<!-- {code-block} bash -->

## Configuraciones útiles

### Alias para comandos frecuentes

```{code-block} bash
:linenos:
# Crear aliases útiles
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.lg "log --oneline --graph"
git config --global alias.unstage "reset HEAD --"

# Usar los aliases
git st        # equivale a git status
git lg        # log gráfico compacto

```
<!-- {code-block} bash -->

### Configuraciones de editor

```{code-block} bash
:linenos:
# Configurar VS Code como editor
git config --global core.editor "code --wait"

# Configurar Vim
git config --global core.editor "vim"

# Configurar Nano (más simple)
git config --global core.editor "nano"

```
<!-- {code-block} bash -->

### Configuración de colores

``` bash
# Habilitar colores
git config --global color.ui auto
git config --global color.status auto
git config --global color.diff auto
git config --global color.branch auto
```
<!-- bash -->

## Errores comunes y soluciones

### "fatal: not a git repository"

``` bash
# Verificar que estás en un directorio con Git
ls -la | grep .git

# Si no existe, inicializar
git init
```
<!-- bash -->

### "Author identity unknown"

``` bash
# Configurar identidad
git config --global user.name "Tu Nombre"
git config --global user.email "tu@email.com"
```
<!-- bash -->

### Commit sin mensaje

``` bash
# Si se abre un editor, escribir mensaje y guardar
# Para salir de Vim: presionar ESC, luego :wq

# Para evitarlo, siempre usar -m
git commit -m "Mensaje descriptivo"
```
<!-- bash -->

### Archivos grandes en el historial

``` bash
# Ver archivos más grandes en el repo
git ls-tree -r -t -l --full-name HEAD | sort -n -k 4

# Para eliminar archivos grandes del historial (avanzado)
# Considerar usar git-filter-branch o BFG Repo-Cleaner
```
<!-- bash -->

### Problema con line endings (Windows/Linux)

``` bash
# Para Windows (convierte LF a CRLF al checkout)
git config --global core.autocrlf true

# Para Linux/Mac (mantiene LF)
git config --global core.autocrlf input
```
<!-- bash -->

(ejercicios-git-basico)=
## Ejercicios prácticos

::::{exercise} Tu primer repositorio
:label: ejercicio-primer-repo

Este ejercicio integra todo lo que aprendiste sobre {ref}`crear-repositorio`,
{ref}`git-add`, {ref}`git-commit`, y {ref}`archivo-gitignore`. Es tu oportunidad
de practicar el {ref}`flujo-diario` completo.

1. Creá un directorio llamado `mi-blog`
2. Inicializá Git en ese directorio
3. Creá un archivo `index.html` con contenido HTML básico
4. Creá un archivo `.gitignore` que ignore archivos `.tmp` y `.log`
5. Hacé el primer commit con ambos archivos
6. Modificá el `index.html` agregando más contenido
7. Hacé un segundo commit con los cambios :::

:::{solution} ejercicio-primer-repo

```{code-block} bash
:linenos:
# 1. Crear directorio
mkdir mi-blog
cd mi-blog

# 2. Inicializar Git
git init

# 3. Crear archivo HTML
cat > index.html << EOF
<!DOCTYPE html>
<html>
<head>
    <title>Mi Blog</title>
</head>
<body>
    <h1>Bienvenido a mi blog</h1>
    <p>Este es mi primer proyecto con Git.</p>
</body>
</html>
EOF

# 4. Crear .gitignore
echo -e "*.tmp\n*.log" > .gitignore

# 5. Primer commit
git add .
git commit -m "Primer commit: estructura inicial del blog"

# 6. Modificar HTML
cat >> index.html << EOF
    <h2>Primer artículo</h2>
    <p>Aquí escribiré sobre mi experiencia aprendiendo Git.</p>
EOF

# 7. Segundo commit
git add index.html
git commit -m "Agregar primer artículo al blog"

# Verificar historial
git log --oneline

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-primer-repo -->

:::{exercise} Manejo de cambios
:label: ejercicio-manejo-cambios

1. En el proyecto anterior, creá un archivo `estilos.css`
2. Agregalo al staging area pero NO hagas commit todavía
3. Modificá el archivo `index.html` para incluir el CSS
4. Usá `git diff` para ver las diferencias
5. Sacá el CSS del staging area
6. Volvé a agregarlo junto con el HTML modificado
7. Hacé commit de ambos cambios juntos 

:::
<!-- {exercise} Manejo de cambios -->

:::{solution} ejercicio-manejo-cambios

```{code-block} bash
:linenos:
# 1. Crear archivo CSS
cat > estilos.css << EOF
body {
    font-family: Arial, sans-serif;
    margin: 20px;
    background-color: #f5f5f5;
}

h1 {
    color: #333;
    border-bottom: 2px solid #007acc;
}
EOF

# 2. Agregar al staging
git add estilos.css

# 3. Modificar HTML para incluir CSS
sed -i '4i\    <link rel="stylesheet" href="estilos.css">' index.html

# 4. Ver diferencias
git diff                    # cambios en working directory
git diff --staged          # cambios en staging area

# 5. Sacar CSS del staging
git reset HEAD estilos.css

# 6. Agregar ambos archivos
git add .

# 7. Commit conjunto
git commit -m "Agregar estilos CSS y vincular con HTML"

# Verificar resultado
git log --oneline
git status

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-manejo-cambios -->

### Ejercicios adicionales para practicar

#### Nivel Básico

1. **Exploración del historial**: En un proyecto existente, usá diferentes
   opciones de `git log` para explorar el historial de commits.

2. **Práctica con .gitignore**: Creá un proyecto con diferentes tipos de
   archivos (código, imágenes, logs, archivos temporales) y configurá un
   `.gitignore` apropiado.

3. **Simulación de errores**: Practicá deshacer cambios usando `git checkout`,
   `git reset` y `git revert`.

#### Nivel Intermedio

4. **Proyecto completo**: Desarrollá un pequeño sitio web con HTML, CSS y
   JavaScript, usando Git para el control de versiones. Hacé commits frecuentes
   y descriptivos.

5. **Colaboración simulada**: Cloná un repositorio público de GitHub, hacé
   cambios locales y practicá con `git pull` y `git push`.

6. **Historial limpio**: Practicá usar `git commit --amend` para corregir
   commits y mantener un historial limpio.

## Buenas prácticas

### Mensajes de commit

**✅ Buenos ejemplos:**

```
Agregar validación de email en formulario de registro
Corregir bug en cálculo de precios con descuentos
Actualizar documentación de API de usuarios
Refactorizar función de autenticación para mejor legibilidad
```

**❌ Malos ejemplos:**

```
fix
cambios
wip
asdasd
```

### Cuándo hacer commit

- **Hacé commits frecuentes** pero con cambios completos
- **Un commit por funcionalidad** o fix
- **Commits que no rompan el código** (que compile/funcione)
- **Antes de cambios grandes** hacé un commit de respaldo

### Organización de archivos

```
mi-proyecto/
+-- .git/                 # Git (automático, no tocar)
+-- .gitignore           # Qué ignorar
+-- README.md            # Documentación del proyecto
+-- src/                 # Código fuente
|   +-- main.py
|   +-- utils.py
+-- docs/                # Documentación
+-- tests/               # Pruebas
+-- requirements.txt     # Dependencias
```

## Recursos para seguir aprendiendo

### Documentación oficial

- [Git Documentation](https://git-scm.com/doc) - documentación oficial completa
- [Pro Git Book](https://git-scm.com/book) - libro gratuito y completo
- `git help <comando>` - ayuda de cualquier comando

### Herramientas gráficas

- **GitHub Desktop** - cliente gráfico simple para principiantes
- **GitKraken** - cliente gráfico avanzado y visual
- **VS Code Git** - integración nativa en VS Code
- **SourceTree** - cliente gratuito de Atlassian

### Plataformas de hosting

- **GitHub** - la más popular, gratis para repositorios públicos
- **GitLab** - alternativa con CI/CD integrado
- **Bitbucket** - de Atlassian, integra con Jira

### Comandos de referencia rápida

```{code-block} bash
:linenos:
# Configuración inicial
git config --global user.name "Nombre"
git config --global user.email "email@ejemplo.com"

# Repositorio nuevo
git init
git add .
git commit -m "Primer commit"

# Día a día
git status              # ver estado
git add archivo         # preparar archivo
git commit -m "msg"     # confirmar cambios
git push               # subir cambios
git pull               # bajar cambios

# Historial
git log --oneline      # ver commits
git diff               # ver cambios
git show HEAD          # ver último commit

# Deshacer
git checkout -- archivo    # descartar cambios
git reset HEAD archivo     # quitar de staging
git commit --amend         # corregir último commit

```
<!-- {code-block} bash -->

## 🐙 GitHub y Colaboración

Una vez dominados los fundamentos locales de Git, el siguiente paso es conectar tu trabajo con plataformas de alojamiento remoto para colaborar con otros desarrolladores y realizar las entregas de la cátedra.

En esta materia hacemos uso intensivo de **GitHub** y de la herramienta oficial de terminal **GitHub CLI (`gh`)**.

Para profundizar en la configuración de cuentas, autenticación por SSH/PAT, flujos de trabajo con Pull Requests y el uso de la línea de comandos de GitHub, consultá nuestra guía especializada:

👉 **[Uso de GitHub en la Cátedra](github.md)**

---


## Epílogo

Git puede parecer de entrada intimidante, pero con la práctica se convertirá en una herramienta indispensable en tu día a día. Los comandos esenciales vistos en esta guía cubren el 90% de los escenarios del desarrollo cotidiano. Dominando el flujo de trabajo básico y el manejo de repositorios remotos, disponés de una base sólida para colaborar profesionalmente.

:::{tip} Práctica constante
La mejor forma de aprender Git es usándolo en proyectos reales. Empezá con proyectos pequeños e individuales para ganar confianza antes de sumarte a desarrollos colaborativos de gran envergadura.
:::

¡Felicitaciones! Ya contás con el conocimiento necesario para utilizar Git de forma efectiva en tu trabajo diario.

```bash
$ git log --oneline
a1b2c3d (HEAD -> main) docs: completar guía de Git para principiantes
4d5e6f7 feat: agregar conceptos fundamentales y flujo básico
8g9h0i1 init: crear estructura inicial de la guía
```

---

_"El control de versiones no es solo sobre código, es sobre la evolución de las ideas."_
