---
title: Git Avanzado
subtitle: Dominio completo del control de versiones.
---

(intro-git-avanzado)=
## ¿Por qué aprender Git avanzado?

Esta guía asume que ya manejás los conceptos fundamentales de Git (de la guía
básica) y podés trabajar cómodamente con comandos esenciales del día a día.
Ahora es momento de subir el nivel y aprender las técnicas que usan los
desarrolladores senior para gestionar proyectos complejos, colaborar
eficientemente en equipos grandes, y resolver problemas sofisticados de control
de versiones.

### Lo que vas a aprender

- **Branching y merging**: Estrategias de ramificación profesionales
- **Rebase y rewriting history**: Manipulación avanzada del historial
- **Resolución de conflictos**: Técnicas para manejar fusiones complejas
- **Git workflows**: Flujos de trabajo para equipos y proyectos grandes
- **Hooks y automatización**: Automatizar tareas y validaciones
- **Debugging avanzado**: Técnicas para encontrar y corregir problemas
- **Performance y optimización**: Mantener repositorios grandes eficientes
- **Integración con herramientas**: CI/CD, IDEs, y servicios externos

:::{important} Prerequisitos Esta guía asume que ya dominás:

- Comandos básicos de Git (add, commit, push, pull)
- Trabajo con repositorios remotos
- GitHub básico
- Conceptos de staging area y working directory

Si necesitás repasar estos conceptos, consultá primero la
[Guía de Git para principiantes](./git.md). 

:::
<!-- {important} Prerequisitos Esta guía asume que ya dominás: -->

(conceptos-avanzados)=
## Conceptos avanzados fundamentales

Antes de sumergirnos en técnicas específicas, es crucial entender algunos
conceptos avanzados que aparecerán constantemente.

(referencias-git)=
### Referencias en Git

Git usa un sistema de referencias para identificar commits, ramas, y otros
objetos. Entender estas referencias es fundamental para el trabajo avanzado.

#### Tipos de referencias

```{code-block} bash
:linenos:
# Referencias absolutas
git show 1a2b3c4d5e6f                    # Hash completo del commit
git show 1a2b3c4                         # Hash corto (mínimo 4 caracteres)

# Referencias simbólicas
git show HEAD                            # Último commit de la rama actual
git show HEAD~1                          # Primer padre del HEAD
git show HEAD~3                          # Tres commits atrás
git show HEAD^                           # Primer padre (igual que HEAD~1)
git show HEAD^2                          # Segundo padre (en merges)

# Referencias de ramas
git show main                            # Último commit de la rama main
git show origin/main                     # Último commit conocido del remoto
git show feature/nueva-funcionalidad     # Último commit de la rama feature

# Referencias de tiempo
git show main@{yesterday}                # main como estaba ayer
git show main@{2.weeks.ago}              # main hace 2 semanas
git show HEAD@{5}                        # HEAD hace 5 cambios en reflog

```
<!-- {code-block} bash -->

(objetos-git)=
### Objetos internos de Git

Git almacena todo como objetos inmutables. Entender estos objetos te ayuda a
comprender cómo funciona Git internamente.

#### Los cuatro tipos de objetos

```{code-block} bash
:linenos:
# 1. Blob - contenido de archivos
git cat-file -t 1a2b3c4d    # muestra el tipo: "blob"
git cat-file -p 1a2b3c4d    # muestra el contenido

# 2. Tree - estructura de directorios
git ls-tree HEAD             # muestra el árbol del commit HEAD
git ls-tree -r HEAD          # recursivo, todos los archivos

# 3. Commit - instantánea del proyecto
git cat-file -p HEAD         # muestra la estructura del commit
# Incluye: tree, parent(s), author, committer, message

# 4. Tag - referencia a otros objetos
git show-ref --tags          # listar todos los tags
git cat-file -p v1.0.0       # información del tag

```
<!-- {code-block} bash -->

(indice-staging-avanzado)=
### Índice y staging avanzado

El índice de Git es más poderoso que un simple "área de preparación". Entender
sus capacidades avanzadas te permite workflows más sofisticados.

```{code-block} bash
:linenos:
# Agregar cambios parciales (hunk por hunk)
git add -p archivo.txt              # modo patch interactivo
git add -i                          # modo interactivo completo

# Trabajar con el índice directamente
git ls-files --stage                # ver contenido del índice
git diff --cached                   # diferencias entre índice y HEAD
git diff HEAD                       # diferencias entre working tree y HEAD

# Manipulación avanzada del staging
git reset HEAD~1 --soft             # mover HEAD, mantener índice
git reset HEAD~1 --mixed            # mover HEAD, resetear índice (default)
git reset HEAD~1 --hard             # mover HEAD, resetear todo

# Stash avanzado
git stash push -m "trabajo parcial" archivo.txt    # stash de archivo específico
git stash push --keep-index         # stash excepto lo que está en staging
git stash push --include-untracked  # incluir archivos untracked

```
<!-- {code-block} bash -->

(branching-estrategias)=
## Branching y estrategias de ramificación

Las ramas son la funcionalidad más poderosa de Git. Dominar el branching te
permite trabajar en múltiples features simultáneamente, experimentar sin riesgo,
y colaborar eficientemente.

(conceptos-branching)=
### Conceptos fundamentales de branching

```{code-block} bash
:linenos:
# Crear y cambiar ramas
git branch feature/nueva-funcionalidad         # crear rama
git checkout feature/nueva-funcionalidad       # cambiar a rama
git checkout -b feature/otra-funcionalidad     # crear y cambiar en un comando
git switch feature/nueva-funcionalidad         # alternativa moderna a checkout

# Información de ramas
git branch                                     # listar ramas locales
git branch -r                                  # listar ramas remotas
git branch -a                                  # listar todas las ramas
git branch -v                                  # con información de últimos commits
git branch --merged                            # ramas ya fusionadas
git branch --no-merged                         # ramas pendientes de fusionar

# Configuración de tracking
git branch -u origin/feature                   # establecer upstream
git branch --set-upstream-to=origin/feature    # sintaxis alternativa
git push -u origin feature                     # push y establecer upstream

```
<!-- {code-block} bash -->

(merge-strategies)=
### Estrategias de merge

Git ofrece múltiples estrategias para fusionar ramas, cada una apropiada para
diferentes escenarios.

#### Fast-forward merge

```{code-block} bash
:linenos:
# Cuando no hay commits en la rama target después del branch point
git checkout main
git merge feature/simple-change

# El historial queda lineal:
# A - B - C (main) - D - E (feature)
#                    ↑ main después del merge

```
<!-- {code-block} bash -->

#### Three-way merge

```{code-block} bash
:linenos:
# Cuando ambas ramas tienen commits nuevos
git checkout main
git merge feature/complex-change

# Se crea un merge commit:
# A - B - C - F (main)
#     \     /
#      D - E (feature)

```
<!-- {code-block} bash -->

#### Merge strategies específicas

```{code-block} bash
:linenos:
# Forzar merge commit incluso en fast-forward
git merge --no-ff feature/branch

# Merge solo si es fast-forward (fallar si no lo es)
git merge --ff-only feature/branch

# Estrategias de merge para casos complejos
git merge -X ours feature/branch              # preferir "nuestra" versión en conflictos
git merge -X theirs feature/branch            # preferir "su" versión en conflictos
git merge -s ours feature/branch              # ignorar completamente los cambios de la otra rama
git merge -s subtree feature/branch           # para proyectos con subárboles

```
<!-- {code-block} bash -->

(rebase-avanzado)=
### Rebase: Reescribiendo la historia

`git rebase` es una herramienta poderosa para mantener un historial limpio y
lineal. Sin embargo, requiere cuidado porque reescribe la historia.

#### Rebase básico vs merge

```{code-block} bash
:linenos:
# Situación inicial:
# A - B - C (main)
#     \
#      D - E (feature)

# Con merge:
git checkout main
git merge feature
# Resultado: A - B - C - F (main)
#                \     /
#                 D - E

# Con rebase:
git checkout feature
git rebase main
git checkout main
git merge feature  # fast-forward
# Resultado: A - B - C - D' - E' (main, feature)

```
<!-- {code-block} bash -->

#### Rebase interactivo

El rebase interactivo te permite editar, reordenar, combinar o eliminar commits.

```{code-block} bash
:linenos:
# Rebase interactivo de los últimos 3 commits
git rebase -i HEAD~3

# En el editor se abre algo así:
# pick 1a2b3c4 Add feature X
# pick 5d6e7f8 Fix bug in feature X
# pick 9g0h1i2 Update documentation
#
# Comandos disponibles:
# pick = usar el commit tal como está
# reword = usar el commit pero editar el mensaje
# edit = usar el commit pero parar para hacer amends
# squash = fusionar este commit con el anterior
# fixup = como squash pero descartar el mensaje de este commit
# drop = eliminar el commit

```
<!-- {code-block} bash -->

#### Casos de uso avanzados de rebase

```{code-block} bash
:linenos:
# Rebase sobre otra rama
git rebase upstream/main                    # rebase sobre upstream
git rebase main feature                     # rebase feature sobre main

# Rebase con rango específico
git rebase --onto main feature~3 feature   # rebase últimos 3 commits de feature sobre main

# Rebase preservando merges
git rebase --preserve-merges main           # mantener estructura de merge commits

# Rebase con estrategia específica
git rebase -X theirs main                   # en conflictos, preferir la otra rama

# Continuar/abortar rebase
git rebase --continue                       # continuar después de resolver conflictos
git rebase --abort                         # cancelar rebase y volver al estado original
git rebase --skip                          # saltar el commit actual

```
<!-- {code-block} bash -->

:::{warning} Regla de oro del rebase

**Nunca hagas rebase de commits que ya
fueron pusheados y compartidos con otros**. El rebase reescribe la historia, y
si otros ya tienen esos commits, crearás problemas de sincronización.

Rebase solo commits locales o en ramas que solo vos usás. 

:::
<!-- {warning} Regla de oro del rebase -->

(resolucion-conflictos)=
## Resolución avanzada de conflictos

Los conflictos son inevitables en el desarrollo colaborativo. Saber resolverlos
eficientemente es una habilidad esencial.

(anatomia-conflictos)=
### Anatomía de un conflicto

```{code-block} bash
:linenos:
# Cuando Git no puede fusionar automáticamente, marca los conflictos:
<<<<<<< HEAD
Código de la rama actual (HEAD)
=======
Código de la rama que se está fusionando
>>>>>>> feature/nueva-funcionalidad

```
<!-- {code-block} bash -->

#### Herramientas para resolución de conflictos

```{code-block} bash
:linenos:
# Ver el estado de conflictos
git status                              # archivos en conflicto
git diff                               # ver diferencias con marcas de conflicto
git diff --name-only --diff-filter=U  # solo nombres de archivos en conflicto

# Herramientas de merge
git mergetool                          # abrir herramienta gráfica configurada
git mergetool --tool=vimdiff          # usar herramienta específica
git mergetool --tool=meld             # usar Meld (Linux)
git mergetool --tool=opendiff         # usar FileMerge (macOS)

# Configurar herramienta de merge por defecto
git config --global merge.tool vimdiff
git config --global merge.tool vscode  # VS Code

```
<!-- {code-block} bash -->

#### Estrategias avanzadas de resolución

```{code-block} bash
:linenos:
# Ver diferentes versiones del archivo
git show :1:archivo.txt               # versión base (common ancestor)
git show :2:archivo.txt               # versión de HEAD (nuestra)
git show :3:archivo.txt               # versión de la rama que se fusiona (su)

# Checkout de versiones específicas
git checkout --ours archivo.txt       # usar nuestra versión
git checkout --theirs archivo.txt     # usar su versión

# Resolver conflictos en masa
git checkout --ours .                 # usar nuestra versión para todos
git checkout --theirs .               # usar su versión para todos

# Reset específico después de merge fallido
git merge --abort                     # cancelar merge y volver al estado anterior
git reset --hard HEAD                 # descartar todos los cambios

```
<!-- {code-block} bash -->

(git-workflows)=
## Git Workflows para equipos

Los workflows definen cómo los equipos usan Git para colaborar eficientemente.
Elegir el workflow correcto es crucial para la productividad del equipo.

(gitflow-workflow)=
### Git Flow

Git Flow es un workflow que define roles específicos para diferentes tipos de
ramas.

```{code-block} bash
:linenos:
# Ramas permanentes
main (master)     # código de producción, siempre estable
develop           # rama de integración, próxima release

# Ramas temporales
feature/*         # nuevas funcionalidades
release/*         # preparación de releases
hotfix/*          # fixes urgentes para producción

# Inicializar Git Flow en un repositorio
git flow init

# Trabajar con features
git flow feature start nueva-funcionalidad
git flow feature finish nueva-funcionalidad

# Trabajar con releases
git flow release start 1.2.0
git flow release finish 1.2.0

# Trabajar con hotfixes
git flow hotfix start fix-critico
git flow hotfix finish fix-critico

```
<!-- {code-block} bash -->

(github-flow)=
### GitHub Flow

GitHub Flow es más simple que Git Flow, ideal para proyectos con deploy
continuo.

```{code-block} bash
:linenos:
# 1. Crear rama para nueva feature
git checkout main
git pull origin main
git checkout -b feature/nueva-funcionalidad

# 2. Hacer commits en la rama feature
git add .
git commit -m "Implementar nueva funcionalidad"
git push origin feature/nueva-funcionalidad

# 3. Crear Pull Request en GitHub
# 4. Discusión y review del código
# 5. Merge del Pull Request
# 6. Deploy automático desde main
# 7. Eliminar rama feature

git checkout main
git pull origin main
git branch -d feature/nueva-funcionalidad

```
<!-- {code-block} bash -->

(herramientas-avanzadas)=
## Herramientas avanzadas de Git

(git-bisect)=
### Git Bisect: Búsqueda binaria de bugs

```{code-block} bash
:linenos:
# Iniciar bisect
git bisect start
git bisect bad                    # commit actual tiene el bug
git bisect good HEAD~10           # commit de hace 10 era bueno

# Git automáticamente checkoutea el punto medio
# Probar si el bug está presente
git bisect bad                    # si el bug está presente
git bisect good                   # si el bug NO está presente

# Finalizar bisect
git bisect reset                  # volver al HEAD original

# Bisect automatizado con script
git bisect start HEAD HEAD~10
git bisect run pytest test_que_falla.py    # ejecutar test automáticamente

```
<!-- {code-block} bash -->

(git-reflog)=
### Git Reflog: Recuperar trabajo perdido

```{code-block} bash
:linenos:
# Ver reflog
git reflog                        # reflog de HEAD
git reflog show main              # reflog de rama específica

# Recuperar commits "perdidos"
git reflog
# encuentra el SHA del commit perdido: a1b2c3d
git checkout a1b2c3d
git checkout -b recuperar-trabajo

# Recuperar después de reset accidental
git reset --hard HEAD~3           # "perdemos" 3 commits
git reflog                        # encontrar SHA anterior
git reset --hard HEAD@{1}        # volver al estado anterior

```
<!-- {code-block} bash -->

(ejercicios-avanzados)=
## Ejercicios prácticos avanzados

:::{exercise} ejercicio-rebase-interactivo
:label: ejercicio-rebase-interactivo

**Ejercicio 1: Rebase interactivo para limpiar historial**

Practicá el rebase interactivo para limpiar un historial desordenado antes de
mergear.

**Objetivos:**

1. Reordenar commits lógicamente
2. Combinar commits relacionados
3. Corregir mensajes de commit
4. Eliminar commits innecesarios
5. Crear un historial limpio y profesional 

:::
<!-- {exercise} ejercicio-rebase-interactivo -->

:::{solution} ejercicio-rebase-interactivo

```{code-block} bash
:linenos:
# 1. Crear escenario con historial desordenado
mkdir proyecto-rebase-demo
cd proyecto-rebase-demo
git init

echo "# Proyecto Demo" > README.md
git add README.md
git commit -m "Initial commit"

git checkout -b feature/user-management

# Crear historial desordenado intencionalmente
echo "class User {}" > user.js
git add user.js
git commit -m "add user"

echo "function validateEmail() {}" >> user.js
git add user.js
git commit -m "oops fix typo"

echo "// TODO: add validation" >> user.js
git add user.js
git commit -m "wip"

echo "class UserService {}" > user-service.js
git add user-service.js
git commit -m "add service"

echo "function validateEmail(email) { return /\S+@\S+\.\S+/.test(email); }" > user.js
git add user.js
git commit -m "fix email validation properly"

# 2. Ver historial actual (desordenado)
echo "=== Historial original (desordenado) ==="
git log --oneline

# 3. Rebase interactivo para limpiar
# Normalmente sería: git rebase -i HEAD~4
# Simularemos la limpieza:

echo -e "\n🔧 Simulando rebase interactivo para limpiar historial..."
echo " Plan: combinar commits relacionados y corregir mensajes"

# Simular la limpieza con reset y nuevos commits
git reset --soft HEAD~4  # soft reset para mantener cambios
git commit -m "feat(user): implement User class with email validation

- Add User class with constructor and methods
- Implement comprehensive email validation with regex
- Add proper input sanitization and error handling"

git add user-service.js
git commit -m "feat(user): add UserService for user operations

- Implement UserService class for user CRUD operations
- Add business logic layer for user management
- Prepare service for database integration"

# 4. Verificar resultado final
echo -e "\n=== Historial después del rebase (limpio) ==="
git log --oneline

echo -e "\n Rebase interactivo completado!"
echo " Limpieza realizada:"
echo "- Eliminados commits temporales y typos"
echo "- Combinados commits relacionados en commits lógicos"
echo "-  Corregidos mensajes siguiendo convención"
echo "- Agregadas descripciones detalladas"
echo -e "\nEl historial ahora está listo para merge a main"

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-rebase-interactivo -->

:::{exercise}
:label: ejercicio-recuperacion-commits

**Ejercicio 2: Recuperación de commits perdidos**

Practicá técnicas de recuperación cuando algo sale mal: commits perdidos, ramas
eliminadas, y archivos borrados.

**Escenarios:**

1. Recuperar commits después de reset --hard destructivo
2. Recuperar rama eliminada accidentalmente
3. Recuperar archivo específico de commit anterior 

:::
<!-- {exercise} -->

:::{solution} ejercicio-recuperacion-commits

```{code-block} bash
:linenos:
# 1. Configurar proyecto para simulacros
mkdir proyecto-recuperacion
cd proyecto-recuperacion
git init

# Crear historial base
echo "# Proyecto de Recuperación" > README.md
git add README.md
git commit -m "feat: initial project setup"

echo "function add(a, b) { return a + b; }" > math.js
git add math.js
git commit -m "feat: add basic math functions"

echo "function subtract(a, b) { return a - b; }" >> math.js
git add math.js
git commit -m "feat: add subtract function"

# Crear rama feature
git checkout -b feature/advanced-math
echo "function multiply(a, b) { return a * b; }" >> math.js
git add math.js
git commit -m "feat: add multiply function"

git checkout main

# 2. ESCENARIO 1: Recuperar después de reset --hard destructivo
echo -e "\nESCENARIO 1: Reset destructivo accidental"
echo "Estado actual:"
git log --oneline

echo -e "\n Simulando reset destructivo que 'pierde' commits..."
git reset --hard HEAD~1  # "perdemos" 1 commit

echo "Estado después del reset:"
git log --oneline

echo -e "\n🔍 Buscando commits perdidos con reflog..."
git reflog | head -5

echo -e "\nRecuperando commits perdidos..."
# Encontrar SHA del estado anterior al reset
previous_head=$(git reflog | grep "HEAD@{1}" | cut -d' ' -f1)
echo "SHA encontrado: $previous_head"

git reset --hard $previous_head
echo -e "\nCommits recuperados exitosamente:"
git log --oneline

# 3. ESCENARIO 2: Recuperar rama eliminada
echo -e "\nESCENARIO 2: Rama eliminada accidentalmente"
git checkout feature/advanced-math
echo "Rama feature/advanced-math activa:"
git log --oneline -2

git checkout main
echo -e "\n Eliminando rama accidentalmente..."
git branch -D feature/advanced-math

echo "Ramas disponibles después de eliminación:"
git branch

echo -e "\n🔍 Buscando última referencia de la rama eliminada..."
git reflog | grep "advanced-math" | head -1

echo -e "\nRecuperando rama eliminada..."
deleted_branch_sha=$(git reflog | grep "checkout.*advanced-math" | head -1 | cut -d' ' -f1)
echo "SHA de la rama eliminada: $deleted_branch_sha"

git checkout -b feature/advanced-math-recuperada $deleted_branch_sha
echo -e "\nRama recuperada exitosamente:"
git log --oneline -3

# 4. ESCENARIO 3: Recuperar archivo específico
git checkout main
echo -e "\nESCENARIO 3: Archivo modificado accidentalmente"

echo "Estado actual de math.js:"
cat math.js

echo -e "\n Simulando modificación accidental destructiva..."
echo "// Archivo dañado accidentalmente" > math.js
git add math.js
git commit -m "accidental: file corruption"

echo "Archivo después de modificación:"
cat math.js

echo -e "\nRecuperando versión anterior del archivo..."
git log --oneline -- math.js | head -3

# Recuperar archivo de commit específico
git checkout HEAD~1 -- math.js
echo -e "\nArchivo recuperado:"
cat math.js

git add math.js
git commit -m "fix: restore math.js from previous commit"

echo -e "\nRESUMEN DE RECUPERACIONES:"
echo "Commits recuperados después de reset --hard"
echo "Rama eliminada recuperada con reflog"
echo "Archivo restaurado desde commit anterior"
echo -e "\nTÉCNICAS CLAVE:"
echo "- git reflog: historial de movimientos de HEAD"
echo "- git checkout <commit> -- <file>: recuperar archivo específico"
echo "- git reset --hard <SHA>: restaurar estado completo"

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-recuperacion-commits -->

## Recursos para continuar aprendiendo

### Documentación oficial avanzada

- [Git Pro Book](https://git-scm.com/book) - Capítulos avanzados (7-10)
- [Git Reference](https://git-scm.com/docs) - Documentación completa de comandos
- [Git
  Internals](https://git-scm.com/book/en/v2/Git-Internals-Plumbing-and-Porcelain)
  -
  Cómo funciona Git internamente

### Herramientas avanzadas

- **GitKraken**: Cliente gráfico avanzado para workflows complejos
- **Sourcetree**: Cliente gráfico gratuito de Atlassian
- **Git Extensions**: Herramientas avanzadas para Windows
- **Magit**: Interfaz de Git para Emacs (muy poderosa)

### Workflows y metodologías

- **Conventional Commits**: Estándar para mensajes de commit
- **Semantic Versioning**: Versionado automático basado en commits
- **GitOps**: Gestión de infraestructura con Git
- **Trunk-based Development**: Alternativa a Git Flow

## Epílogo

Dominar Git avanzado te convierte en un desarrollador más eficiente y confiable.
Las técnicas que aprendiste en esta guía son las mismas que usan equipos de
desarrollo en empresas como Google, Facebook, y GitHub.

:::{tip} Práctica continua

El uso avanzado de Git se domina con la práctica. Aplicá estas
técnicas en proyectos reales, experimentá con diferentes workflows, y no tengas
miedo de "romper" cosas en repositorios de prueba. Git tiene herramientas de
recuperación para casi cualquier situación. 

:::
<!-- {tip} Práctica continua -->

El control de versiones avanzado no es solo sobre comandos técnicos - es sobre
metodologías que permiten a equipos grandes trabajar eficientemente, mantener
calidad del código, y entregar software confiable.

Con estas habilidades, estás preparado para contribuir a proyectos open source
complejos, liderar equipos de desarrollo, y diseñar workflows que escalen con el
crecimiento de tu organización.

```{code-block} bash
:linenos:
$ git log --oneline --graph --all
* a1b2c3d (HEAD -> main) docs: complete advanced Git guide
* 4d5e6f7 feat: add advanced workflows and automation
* 8g9h0i1 feat: add branching strategies and merge techniques
* 2m3n4o5 feat: add debugging and recovery techniques
* 6p7q8r9 init: create advanced Git guide structure

```
<!-- {code-block} bash -->

---

_"La maestría en Git no se mide por cuántos comandos conocés, sino por qué tan
elegantemente podés resolver problemas complejos de colaboración."_
