---
title: Uso de GitHub en la Cátedra
short_title: Guía GitHub
subtitle: Flujos de trabajo, Pull Requests y herramientas de colaboración en la UNRN
---

# Uso de GitHub en la Cátedra

Esta guía detalla cómo se utiliza la plataforma GitHub como entorno de entrega,
corrección y discusión en la materia. Se asume que comprendés los conceptos
explicados en la guía de [Git básico](git.md).

---

## 1. Creación y configuración de la cuenta

Para las actividades de la materia, debés contar con una cuenta activa en
[GitHub](https://github.com/).

### Registro inicial

1. Visitá [github.com](https://github.com) y creá una cuenta
2. Elegí un username que sea profesional (va a ser parte de tu identidad online)
3. Verificá tu email
4. Configurá tu perfil con foto y descripción

### Crea tu primer repositorio remoto

Ahora que ya sabés usar {ref}`git-clone`, {ref}`git-add`, {ref}`git-commit`, y
{ref}`git-push`, podés conectar tu trabajo local con GitHub. Tenés dos opciones
principales:

```{code-block} bash
:linenos:
# Opción 1: Crear repositorio vacío en GitHub primero
# 1. Click en "New repository" en github.com
# 2. Ingresá nombre, descripción y configuración
# 3. Clonar localmente:

git clone https://github.com/tu-usuario/mi-proyecto.git
cd mi-proyecto

# Crear archivos y hacer primer commit
echo "# Mi Proyecto" > README.md
git add README.md
git commit -m "Initial commit"
git push origin main

```
<!-- {code-block} bash -->

```{code-block} bash
:linenos:
# Opción 2: Subir repositorio local existente
# Crear repositorio vacío en GitHub (sin README)
# Luego conectar tu repo local:

git remote add origin https://github.com/tu-usuario/mi-proyecto.git
git branch -M main
git push -u origin main

```
<!-- {code-block} bash -->

---

## 2. Autenticación y clonación de repositorios

Para interactuar de forma segura con los servidores de GitHub desde tu terminal
local sin ingresar tus credenciales en cada operación, debés configurar un
método de autenticación.

### Opción A: Autenticación por Github CLI (recomendada)

Esta opción es la más sencilla y recomendada, ya que la herramienta oficial de GitHub se encarga de automatizar todo el proceso, incluyendo la generación y registro de claves criptográficas si no contás con ellas.

1.  **Instalar GitHub CLI**: Si aún no lo tenés en tu sistema, seguí las instrucciones de la sección de {ref}`instalacion-github-cli`.
2.  **Iniciar el proceso de autenticación** ejecutando en tu terminal:
    ```bash
    gh auth login
    ```
3.  **Seguir el flujo interactivo en la terminal**:
    *   **What account do you want to log into?** Seleccioná `GitHub.com`.
    *   **What is your preferred protocol for Git operations?** Elegí `SSH` (recomendado) o `HTTPS`.
    *   *Si seleccionaste SSH*:
        *   **Generate a new SSH key to upload to your GitHub account?** Seleccioná `Yes` (si no tenés una clave previa) o elegí una existente de la lista para subirla automáticamente.
        *   **Enter a passphrase for your new SSH key (optional)**: Presioná Enter para dejarla sin contraseña o ingresá una de tu preferencia.
        *   **Title for your SSH key**: Ingresá un título descriptivo (ej. `Notebook UNRN`).
    *   **How would you like to authenticate GitHub CLI?** Seleccioná `Login with a web browser`.
4.  **Completar la autenticación en el navegador**:
    *   La terminal te mostrará un código único de 8 caracteres (ej: `WDAS-12A4`) y te pedirá presionar Enter para abrir tu navegador web.
    *   Pegá el código en la página de GitHub que se abrirá automáticamente e iniciá sesión con tus credenciales.
5.  **Verificar el estado**:
    Una vez autorizado, regresá a la terminal y verificá que la conexión es correcta con:
    ```bash
    gh auth status
    ```

### Opción B: Autenticación por SSH

Consiste en generar un par de claves criptográficas en tu computadora local y
asociar la clave pública a tu cuenta de GitHub.

1.  **Generar la clave SSH** en tu terminal:
    ```bash
    ssh-keygen -t ed25519 -C "tu_email@unrn.edu.ar"
    ```
    *(Presioná Enter en todas las solicitudes para usar la ruta por defecto y
    omitir la contraseña de la clave, si así lo preferís).*

2.  **Iniciar el agente SSH** y añadir la clave:
    ```bash
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/id_ed25519
    ```

3.  **Copiar la clave pública**:
    ```bash
    cat ~/.ssh/id_ed25519.pub
    ```
    Copiá el contenido completo impreso en pantalla.

4.  **Registrar la clave en GitHub**:
    *   Ingresá a GitHub ⇾ Perfil (esquina superior derecha) ⇾ **Settings** ⇾
        **SSH and GPG keys**.
    *   Hacé clic en **New SSH key**, asignale un título (ej: "Notebook
        Cátedra") y pegá la clave pública en el campo correspondiente.

:::{figure} images/github_ssh_key_settings.png
:alt: Captura de pantalla de la interfaz de configuración de claves SSH en GitHub. Se destaca el botón verde 'New SSH Key' en la parte superior derecha, y el formulario con los campos 'Title' (donde se ingresa el nombre de la máquina) y 'Key' (el área de texto grande donde se debe pegar el contenido de la clave pública id_ed25519.pub).
:align: center
:width: 85%

Página de configuración de claves SSH en GitHub.

:::
<!-- {figure} images/github_ssh_key_settings.png -->

5.  **Clonar el repositorio**:
    Una vez configurada la clave, cloná tus proyectos utilizando la dirección
    SSH:
    ```bash
    git clone git@github.com:INGCOM-UNRN-P1/tu-repositorio.git
    ```

### Opción C: Token de Acceso Personal (PAT)

Si preferís usar HTTPS en lugar de SSH, GitHub requiere un Token de Acceso
Personal (PAT) como contraseña de autenticación.

*   Generalo en: **Settings** ⇾ **Developer settings** ⇾ **Personal access
    tokens** ⇾ **Tokens (classic)**.
*   Seleccioná los permisos mínimos de `repo` y guardá el token en un lugar
    seguro. Deberás introducirlo en lugar de tu contraseña tradicional al
    realizar operaciones de subida (`git push`).

---

## 3. El dia a dia con GitHub

```{code-block} bash
:linenos:
# 1. Comenzar el día - sincronizar con remoto
git pull origin main

# 2. Trabajar localmente
# ... hacer cambios en archivos ...
git add .
git commit -m "Implementar nueva funcionalidad"

# 3. Subir cambios al final del día
git push origin main

# 4. Verificar en GitHub web que los cambios están

```
<!-- {code-block} bash -->

#### Mantener historial sincronizado

```{code-block} bash
:linenos:
# Antes de empezar a trabajar siempre:
git status                    # verificar estado local
git pull origin main         # traer últimos cambios

# Después de cada sesión de trabajo:
git log --oneline -5         # revisar commits locales
git push origin main         # subir cambios

```
<!-- {code-block} bash -->

## 3. El flujo de trabajo con Pull Requests (PR)

En la cátedra, cada entrega o corrección de trabajos prácticos se gestiona
mediante un **Pull Request** (Petición de Integración). Un PR es una propuesta
de cambios que permite comparar tu código de entrega contra la rama principal de
control.

### Proceso de envío de una entrega

1.  **Crear una rama local** para la tarea actual, partiendo siempre desde
    `main` actualizada:
    ```bash
    git checkout main
    git pull origin main
    git checkout -b entrega-tp1
    ```
2.  **Realizar los cambios** en el código fuente, documentar las interfaces con
    Doxygen (ver la [Guía de Doxygen](doxygen.md)) y verificar que el proyecto
    compile sin advertencias.
3.  **Subir la rama** al servidor remoto:
    ```bash
    git commit -am "Finaliza la resolución del TP1"
    git push origin entrega-tp1
    ```
4.  **Abrir el Pull Request**:
    *   Ingresá al repositorio del proyecto en la web de GitHub.
    *   Visualizarás un banner indicando que se subió una rama nueva. Hacé clic
        en **Compare & pull request**.
    *   Completá el título del PR con tu nombre y el número de TP.
    *   Creá el PR apuntando tu rama de entrega (`entrega-tp1`) hacia la rama
        principal (`main`).

:::{figure} images/github_compare_pull_request.png
:alt: Captura de pantalla de la página principal del repositorio en GitHub tras subir una nueva rama. Se observa un banner horizontal destacado de color amarillo claro con el mensaje 'entrega-tp1 had recent pushes less than a minute ago' y un botón verde en la derecha rotulado 'Compare & pull request'.
:align: center
:width: 85%

Banner de aviso para iniciar un nuevo Pull Request.

:::
<!-- {figure} images/github_compare_pull_request.png -->

---

## 4. Revisión y respuesta a comentarios

Una vez abierto el Pull Request, los docentes de la cátedra revisarán el código.
Las correcciones se realizan directamente sobre las líneas de código afectadas
en el PR.

### Interacción durante la revisión

*   **Comentarios de línea**: Si recibís observaciones sobre alguna línea en
    particular, se abrirá un hilo de discusión en la pestaña *Conversation* o
    *Files changed* del PR.
*   **Corrección y actualización**: Para corregir lo solicitado, no es necesario
    abrir un nuevo PR. Simplemente debés realizar los cambios correspondientes
    en tu rama local, hacer el commit y subirlo:
    ```bash
    # Luego de corregir el error detectado en el editor:
    git commit -am "Corrige la validación de límites en la estructura"
    git push origin entrega-tp1
    ```
    El Pull Request se actualizará automáticamente con tus nuevos commits.
*   **Responder y resolver**: Una vez implementada la corrección, respondé al
    comentario del docente en GitHub y marcá la conversación como **Resolve
    conversation** si corresponde.

:::{figure} images/github_pr_comments.png
:alt: Captura de pantalla de un comentario de revisión dentro de un Pull Request. Se observa un bloque de código en C con una anotación superpuesta de un docente sugiriendo una mejora, un campo de texto para escribir una respuesta en la parte inferior, y el botón 'Resolve conversation' habilitado en la esquina derecha del hilo.
:align: center
:width: 85%

Hilo de discusión y revisión de código sobre una línea específica en un Pull
Request.

:::
<!-- {figure} images/github_pr_comments.png -->

---

## 5. Consultas con GitHub Discussions

Para canalizar las dudas teóricas y metodológicas de la cursada, la cátedra
utiliza la pestaña **Discussions** del repositorio institucional en lugar del
correo electrónico.

*   **Antes de preguntar**: Usá la barra de búsqueda para verificar si otro
    compañero ya realizó la misma consulta y si ya fue resuelta.
*   **Estructura de la consulta**:
    *   Seleccioná la categoría correspondiente (ej: Q&A, TPs, Teoría).
    *   Proporcioná títulos descriptivos. Evitá títulos genéricos como *"Ayuda
        con el TP"*. Preferí *"Error de segmentación al liberar memoria dinámica
        en TP2"*.
    *   Adjuntá bloques de código legibles usando la sintaxis de código
        Markdown.

---

## 6. Reporte de fallas mediante GitHub Issues

Los **Issues** se reservan exclusivamente para reportar fallas de
infraestructura del entorno, errores ortográficos o conceptuales detectados en
las guías y apuntes, o problemas con las pruebas unitarias provistas por la
cátedra.

:::{important}

No uses los *Issues* para realizar preguntas sobre cómo resolver un ejercicio
práctico. Para ello debés recurrir a *Discussions*.

:::
<!-- {important} -->

Para reportar un error del apunte:
1.  Ingresá a la sección **Issues** del repositorio del apunte.
2.  Hacé clic en **New issue**.
3.  Describí la falla indicando el archivo afectado y sugiriendo la corrección
    correspondiente.

---

(github-intro)=
## 7. GitHub CLI (`gh`)

GitHub CLI (`gh`) es la herramienta oficial de línea de comandos que te permite interactuar directamente con GitHub desde tu terminal local. Esto acelera significativamente el flujo de trabajo al evitar tener que abrir el navegador web para realizar tareas administrativas comunes.

### Explorando repositorios en GitHub

Antes de pasar a la terminal, recordá que la interfaz web de GitHub ofrece pestañas esenciales como:
- **Code**: Para navegar archivos, directorios y ver el historial de commits.
- **Issues**: Para reportar bugs o gestionar tareas pendientes.
- **Pull Requests**: Para revisar, discutir y fusionar contribuciones.
- **Actions**: Para monitorear el estado de los flujos de integración continua (CI/CD).
- **Settings**: Para administrar la configuración del repositorio, colaboradores y claves de acceso.

(github-cli-intro)=
### ¿Qué es GitHub CLI?

`gh` te permite realizar casi cualquier acción que harías en la interfaz web de GitHub, pero directamente desde la terminal, como clonar repositorios de la cátedra, crear pull requests, listar issues o verificar el estado de tus entregas.



(instalacion-github-cli)=
### Instalación de GitHub CLI

#### Linux (Ubuntu/Debian)

```{code-block} bash
:linenos:
# Método oficial
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null
sudo apt update
sudo apt install gh

# Método alternativo con snap
sudo snap install gh

```
<!-- {code-block} bash -->

#### Linux (CentOS/RHEL/Fedora)

``` bash
sudo dnf install gh
```
<!-- bash -->

#### macOS

``` bash
# Con Homebrew
brew install gh

# Con MacPorts
sudo port install gh
```
<!-- bash -->

#### Windows

```{code-block} bash
:linenos:
# Con winget
winget install --id GitHub.cli

# Con Chocolatey
choco install gh

# Con Scoop
scoop install gh

```
<!-- {code-block} bash -->

### Configuración inicial de GitHub CLI

```{code-block} bash
:linenos:
# Autenticarse con GitHub
gh auth login

# Seguir el flujo interactivo:
# 1. Elegir GitHub.com
# 2. Elegir HTTPS o SSH
# 3. Authenticarse con token o browser
# 4. Elegir protocolo preferido

# Verificar autenticación
gh auth status

# Ver configuración actual
gh config list

```
<!-- {code-block} bash -->

(comandos-github-cli)=
### Comandos esenciales de GitHub CLI

#### Gestión de repositorios

```{code-block} bash
:linenos:
# Crear repositorio nuevo
gh repo create mi-nuevo-proyecto --public --clone
gh repo create mi-proyecto-privado --private --clone

# Clonar repositorio
gh repo clone usuario/proyecto
gh repo clone https://github.com/usuario/proyecto.git

# Ver información del repositorio actual
gh repo view

# Ver información de otro repositorio
gh repo view microsoft/vscode

# Listar tus repositorios
gh repo list

# Hacer fork de un repositorio
gh repo fork usuario/proyecto --clone

```
<!-- {code-block} bash -->

#### Issues (problemas/tareas)

```{code-block} bash
:linenos:
# Listar issues del repositorio actual
gh issue list

# Ver issue específico
gh issue view 123

# Crear nuevo issue
gh issue create --title "Bug en validación" --body "Descripción detallada del problema"

# Crear issue interactivo
gh issue create

# Cerrar issue
gh issue close 123

# Asignar issue
gh issue edit 123 --assignee @me

```
<!-- {code-block} bash -->

#### Pull Requests

```{code-block} bash
:linenos:
# Listar pull requests
gh pr list

# Ver pull request específico
gh pr view 456

# Crear pull request
gh pr create --title "Nueva funcionalidad" --body "Descripción de cambios"

# Crear PR interactivo
gh pr create

# Hacer checkout de un PR
gh pr checkout 456

# Mergear pull request
gh pr merge 456

# Cerrar pull request
gh pr close 456

```
<!-- {code-block} bash -->

#### Releases

```{code-block} bash
:linenos:
# Listar releases
gh release list

# Ver release específico
gh release view v1.0.0

# Crear release
gh release create v1.0.0 --title "Primera versión" --notes "Cambios principales"

# Descargar assets de release
gh release download v1.0.0

```
<!-- {code-block} bash -->

#### Gists (snippets de código)

```{code-block} bash
:linenos:
# Crear gist público
gh gist create archivo.py --public

# Crear gist privado
gh gist create archivo.py

# Listar tus gists
gh gist list

# Ver gist específico
gh gist view abc123def456

# Editar gist
gh gist edit abc123def456

```
<!-- {code-block} bash -->

### Workflows comunes con GitHub CLI

#### Flujo completo de nuevo proyecto

```{code-block} bash
:linenos:
# 1. Crear repositorio y clonarlo
gh repo create mi-proyecto --public --clone
cd mi-proyecto

# 2. Crear estructura inicial
echo "# Mi Proyecto" > README.md
echo "node_modules/" > .gitignore
git add .
git commit -m "Initial commit"
git push

# 3. Crear primer issue
gh issue create --title "Setup inicial" --body "Configurar estructura del proyecto"

# 4. Ver el repositorio en GitHub
gh repo view --web

```
<!-- {code-block} bash -->

#### Contribuir a proyecto existente

```{code-block} bash
:linenos:
# 1. Fork del proyecto
gh repo fork usuario/proyecto --clone
cd proyecto

# 2. Crear rama para tu contribución
git checkout -b mi-funcionalidad

# 3. Hacer cambios y commit
# ... editar archivos ...
git add .
git commit -m "Agregar nueva funcionalidad"

# 4. Subir rama
git push origin mi-funcionalidad

# 5. Crear pull request
gh pr create --title "Nueva funcionalidad" --body "Descripción detallada"

# 6. Ver el PR en navegador
gh pr view --web

```
<!-- {code-block} bash -->

#### Gestión de issues como tareas

```{code-block} bash
:linenos:
# Crear lista de tareas para sprint
gh issue create --title "Implementar autenticación" --label "feature"
gh issue create --title "Agregar tests unitarios" --label "testing"
gh issue create --title "Documentar API" --label "documentation"

# Ver dashboard de issues
gh issue list --state open

# Trabajar en issue específico
gh issue view 123
# ... hacer el trabajo ...
git commit -m "Fix #123: implementar autenticación"

# Cerrar issue automáticamente al hacer push
git push

```
<!-- {code-block} bash -->

### Integración con workflow diario

#### Alias útiles para GitHub CLI

```{code-block} bash
:linenos:
# Agregar aliases a tu .bashrc o .zshrc
alias ghs="gh status"
alias ghi="gh issue list"
alias ghp="gh pr list"
alias ghr="gh repo view"
alias ghc="gh pr create"

# O crear aliases de gh
gh alias set prs "pr list"
gh alias set issues "issue list"
gh alias set repo "repo view"

```
<!-- {code-block} bash -->

#### Scripts de automatización

```{code-block} bash
:linenos:
# Script para inicio de día
#!/bin/bash
echo "=== GitHub Dashboard ==="
echo "Repositorio actual:"
gh repo view

echo -e "\nIssues abiertas:"
gh issue list --limit 5

echo -e "\nPull requests pendientes:"
gh pr list --limit 5

echo -e "\nStatus de Actions:"
gh run list --limit 3

```
<!-- {code-block} bash -->

### GitHub Pages - Hosting gratuito

GitHub Pages te permite hospedar sitios web estáticos directamente desde tu
repositorio.

```{code-block} bash
:linenos:
# 1. Crear repositorio para GitHub Pages
gh repo create mi-usuario.github.io --public --clone

# 2. Crear sitio web simple
cd mi-usuario.github.io
cat > index.html << EOF
<!DOCTYPE html>
<html>
<head>
    <title>Mi Portfolio</title>
</head>
<body>
    <h1>Bienvenido a mi sitio</h1>
    <p>Este sitio está hospedado en GitHub Pages</p>
</body>
</html>
EOF

# 3. Subir y activar GitHub Pages
git add .
git commit -m "Add initial website"
git push

# 4. Configurar GitHub Pages desde Settings o CLI
gh api repos/:owner/:repo --method PATCH --field "has_pages=true"

# 5. Tu sitio estará disponible en https://mi-usuario.github.io

```
<!-- {code-block} bash -->

### Ejercicios prácticos con GitHub y CLI

:::{exercise} Setup completo de GitHub
:label: ejercicio-github-setup


1. Creá una cuenta en GitHub si no tenés
2. Instalá GitHub CLI en tu sistema
3. Autenticáte con `gh auth login`
4. Creá un repositorio público llamado `mi-portfolio` usando GitHub CLI
5. Agregá un README.md con información sobre vos
6. Subí el proyecto y verificá que se vea correctamente en GitHub web 

:::
<!-- {exercise} Setup completo de GitHub -->

:::{solution} ejercicio-github-setup

```{code-block} bash
:linenos:
# 1. Crear cuenta en github.com (manual)

# 2. Instalar GitHub CLI (según tu sistema)
# En Ubuntu:
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null
sudo apt update && sudo apt install gh

# 3. Autenticar
gh auth login
# Seguir el flujo interactivo

# 4. Crear repositorio
gh repo create mi-portfolio --public --clone
cd mi-portfolio

# 5. Crear README con información personal
cat > README.md << EOF
# Mi Portfolio

## Sobre mí
Soy un desarrollador aprendiendo Git y GitHub.

## Habilidades
- Git y control de versiones
- Desarrollo web básico
- GitHub y colaboración

## Proyectos
- [Mi Portfolio](https://github.com/$(gh api user --jq '.login')/mi-portfolio)

## Contacto
- GitHub: [@$(gh api user --jq '.login')](https://github.com/$(gh api user --jq '.login'))
- Email: $(gh api user --jq '.email // "email@ejemplo.com"')
EOF

# 6. Subir y verificar
git add README.md
git commit -m "Add portfolio README with personal information"
git push

# Ver en web
gh repo view --web

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-github-setup -->

:::{exercise} Workflow completo con issues y CLI
:label: ejercicio-github-workflow

1. En tu repositorio `mi-portfolio`, creá 3 issues usando GitHub CLI:
   - "Agregar página de proyectos"
   - "Mejorar diseño del README"
   - "Agregar información de contacto"
2. Trabajá en uno de los issues, hacé los cambios necesarios
3. Cerrá el issue automáticamente con el commit message
4. Verificá que el issue se cerró correctamente

:::
<!-- {exercise} Workflow completo con issues y CLI -->

:::{solution} ejercicio-github-workflow

```{code-block} bash
:linenos:
# Asegurate de estar en el repositorio mi-portfolio
cd mi-portfolio

# 1. Crear issues usando GitHub CLI
gh issue create --title "Agregar página de proyectos" --body "Crear una sección dedicada a mostrar mis proyectos con descripciones y enlaces"

gh issue create --title "Mejorar diseño del README" --body "Usar markdown avanzado para hacer el README más atractivo visualmente"

gh issue create --title "Agregar información de contacto" --body "Incluir enlaces a redes sociales y formas de contacto profesional"

# Ver los issues creados
gh issue list

# 2. Trabajar en el primer issue (agregar página de proyectos)
cat >> README.md << EOF

## Mis Proyectos

### 1. Mi Portfolio
- **Descripción**: Mi primera experiencia con Git y GitHub
- **Tecnologías**: Markdown, Git, GitHub
- **Estado**: En desarrollo
- **Link**: [Ver repositorio](https://github.com/$(gh api user --jq '.login')/mi-portfolio)

### 2. Próximos proyectos
- Sitio web personal
- Aplicación de tareas
- Blog técnico

---
*Última actualización: $(date +"%d/%m/%Y")*
EOF

# 3. Commit que cierra automáticamente el issue #1
git add README.md
git commit -m "Add projects section

Close #1 - Agregar página de proyectos

- Agregar sección de proyectos al README
- Incluir proyecto actual y roadmap futuro
- Mejorar estructura general del documento"

git push

# 4. Verificar que el issue se cerró
gh issue list
gh issue view 1

echo "¡El issue #1 debería aparecer como cerrado!"

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-github-workflow -->

(repositorios-especiales-github)=
### Repositorios especiales de GitHub

GitHub tiene varios tipos de repositorios especiales que tienen funcionalidades
únicas más allá del simple hosting de código. Conocer estos repositorios te
permite aprovechar al máximo la plataforma y crear una presencia profesional
sólida.

#### 1. Repositorio de perfil (USERNAME/USERNAME)

El repositorio más importante para tu presencia online es el **repositorio de
perfil**. Este es un repositorio especial que debe tener exactamente el mismo
nombre que tu username de GitHub.

**Características únicas:**

- El README.md se muestra automáticamente en tu página de perfil
- Funciona como tu "carta de presentación" profesional
- Es lo primero que ven los reclutadores y otros desarrolladores
- Permite usar Markdown, imágenes, GIFs, y widgets interactivos

#### 2. GitHub Pages (usuario.github.io)

Un repositorio llamado `tu-usuario.github.io` automáticamente se convierte en tu
sitio web personal.

**Funcionalidades:**

- Hosting gratuito de sitios web estáticos
- Dominio personalizado: `https://tu-usuario.github.io`
- Soporte para Jekyll (generador de sitios estáticos)
- Perfect para portfolios, blogs, o documentación

#### 3. Repositorios .github

Repositorios que empiezan con `.github` tienen funciones especiales:

- **`.github`**: Plantillas de issues, pull requests, y configuración para toda
  tu cuenta
- **`.github.io`**: Alias para tu sitio de GitHub Pages
- **`tu-org/.github`**: Configuración por defecto para toda una organización

#### 4. Gists especiales

Aunque no son repositorios tradicionales, los Gists también tienen
características especiales:

- **Gists públicos**: Se indexan en buscadores
- **Gists con nombre específico**: Pueden embeberse fácilmente
- **Gists con múltiples archivos**: Funcionan como mini-proyectos

:::{exercise} Crear tu repositorio de perfil
:label: ejercicio-repositorio-perfil

En este ejercicio vas a crear tu repositorio de perfil de GitHub, que será tu
carta de presentación profesional. Integrará todo lo aprendido sobre
{ref}`git-clone`, {ref}`git-add`, {ref}`git-commit`, {ref}`git-push`, y
{ref}`comandos-github-cli`.

**Objetivos:**

1. Crear el repositorio especial de perfil usando GitHub CLI
2. Diseñar un README.md profesional con información personal
3. Agregar badges, estadísticas y elementos visuales atractivos
4. Usar el flujo completo Git + GitHub para gestionarlo
5. Entender cómo este repositorio mejora tu presencia online

**Pasos a seguir:**

1. **Preparación inicial**: Verificá que tenés GitHub CLI configurado
2. **Crear repositorio de perfil**: Usar tu username exacto como nombre
3. **Diseñar contenido profesional**: README con secciones bien estructuradas
4. **Agregar elementos interactivos**: Badges, stats, y enlaces
5. **Gestionar con Git**: Usar el flujo completo de commits y push
6. **Verificar resultado**: Confirmar que aparece en tu perfil

**Resultado esperado:** Un perfil de GitHub profesional que muestre tus
habilidades, proyectos e intereses, y que puedas usar como referencia en
aplicaciones laborales. 

:::
<!-- {exercise} Crear tu repositorio de perfil -->

:::{solution} ejercicio-repositorio-perfil
:class: dropdown

```{code-block} bash
:linenos:
# 1. Verificar configuración de GitHub CLI
gh auth status
echo "Tu username actual de GitHub:"
gh api user --jq '.login'

# Guardar username en variable para reutilizar
USERNAME=$(gh api user --jq '.login')
echo "Creando repositorio de perfil para: $USERNAME"

# 2. Crear repositorio especial de perfil
# IMPORTANTE: el nombre debe ser exactamente igual a tu username
gh repo create "$USERNAME" --public --clone --description "Mi repositorio de perfil profesional"
cd "$USERNAME"

# 3. Crear README.md profesional y completo
cat > README.md << EOF
# ¡Hola! 👋 Soy $(gh api user --jq '.name // .login')

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=22&pause=1000&color=2E9EF7&center=true&vCenter=true&width=440&lines=Desarrollador+en+crecimiento;Apasionado+por+la+tecnolog%C3%ADa;Siempre+aprendiendo+algo+nuevo" alt="Typing SVG" />
</div>

## 🚀 Sobre mí

- 🔭 **Actualmente trabajando en:** Proyectos de aprendizaje con Git y GitHub
- 🌱 **Aprendiendo:** Control de versiones, desarrollo web, y mejores prácticas de código
-  **Preguntame sobre:** Git, GitHub, primeros pasos en programación
- 📫 **Contacto:** [Mi email](mailto:$(gh api user --jq '.email // "tu-email@ejemplo.com"'))
- ⚡ **Dato curioso:** Este README fue creado completamente desde la terminal usando Git y GitHub CLI

## 🛠️ Tecnologías y herramientas

### Lenguajes de programación
![HTML](https://img.shields.io/badge/-HTML5-E34F26?style=flat-square&logo=html5&logoColor=white)
![CSS](https://img.shields.io/badge/-CSS3-1572B6?style=flat-square&logo=css3)
![JavaScript](https://img.shields.io/badge/-JavaScript-F7DF1E?style=flat-square&logo=javascript&logoColor=black)
![Python](https://img.shields.io/badge/-Python-3776AB?style=flat-square&logo=python&logoColor=white)

### Herramientas de desarrollo
![Git](https://img.shields.io/badge/-Git-F05032?style=flat-square&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/-GitHub-181717?style=flat-square&logo=github)
![VS Code](https://img.shields.io/badge/-VS%20Code-007ACC?style=flat-square&logo=visual-studio-code)
![Terminal](https://img.shields.io/badge/-Terminal-4D4D4D?style=flat-square&logo=windows-terminal&logoColor=white)

## 📊 Estadísticas de GitHub

<div align="center">
  <img height="180em" src="https://github-readme-stats.vercel.app/api?username=$USERNAME&show_icons=true&theme=tokyonight&include_all_commits=true&count_private=true"/>
  <img height="180em" src="https://github-readme-stats.vercel.app/api/top-langs/?username=$USERNAME&layout=compact&langs_count=7&theme=tokyonight"/>
</div>

## 🏆 GitHub Achievements

<div align="center">
  <img src="https://github-profile-trophy.vercel.app/?username=$USERNAME&theme=tokyonight&row=1&column=6&margin-h=8&margin-w=8&no-bg=false&no-frame=false&title=Commit,Repositories,PullRequest,Issues,Followers,Stars" alt="GitHub Trophies" />
</div>

## 📈 Actividad reciente

<!--START_SECTION:activity-->
<!--END_SECTION:activity-->

## Proyectos destacados

### 🔧 Repositorios principales

- **[mi-portfolio](https://github.com/$USERNAME/mi-portfolio)** - Mi primer proyecto con Git y GitHub
- **[aprendiendo-git](https://github.com/$USERNAME/aprendiendo-git)** - Ejercicios y práctica con control de versiones
- **[proyectos-web](https://github.com/$USERNAME/proyectos-web)** - Colección de proyectos web básicos

### 🚧 En desarrollo

- **Sitio web personal** - Portfolio online con GitHub Pages
- **Blog técnico** - Compartiendo lo que aprendo
- **Proyectos de práctica** - Ejercicios de programación y Git

##  Encuéntrame en

[![LinkedIn](https://img.shields.io/badge/-LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/tu-perfil)
[![Twitter](https://img.shields.io/badge/-Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/tu-usuario)
[![Email](https://img.shields.io/badge/-Email-EA4335?style=for-the-badge&logo=gmail&logoColor=white)](mailto:$(gh api user --jq '.email // "tu-email@ejemplo.com"'))
[![Portfolio](https://img.shields.io/badge/-Portfolio-000000?style=for-the-badge&logo=github&logoColor=white)](https://$USERNAME.github.io)

## Cita que me inspira

> *"El control de versiones no es solo sobre código, es sobre la evolución de las ideas."*

---

<div align="center">
  <img src="https://komarev.com/ghpvc/?username=$USERNAME&color=blueviolet&style=flat-square&label=Visitantes+del+perfil" alt="Visitors" />
</div>

<div align="center">

**¡Gracias por visitar mi perfil!**

*Siempre abierto a nuevas oportunidades y colaboraciones*

</div>
EOF

# 4. Crear archivo de configuración para GitHub Actions (opcional)
mkdir -p .github/workflows
cat > .github/workflows/update-readme.yml << EOF
name: Update README

on:
  schedule:
    - cron: '0 0 * * 0'  # Actualizar cada domingo
  workflow_dispatch:

jobs:
  update-readme:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Update activity
        uses: jamesgeorge007/github-activity-readme@master
        env:
          GITHUB_TOKEN: \${{ secrets.GITHUB_TOKEN }}
EOF

# 5. Agregar .gitignore básico
cat > .gitignore << EOF
# Archivos temporales
*.tmp
*.log
*~

# Archivos del sistema
.DS_Store
Thumbs.db

# Backups
*.backup
EOF

# 6. Flujo completo Git: add, commit, push
echo "Agregando archivos al staging area..."
git add .

echo " Haciendo commit del perfil profesional..."
git commit -m "Add professional profile README

 Features added:
- Personal introduction with typing animation
- Technology badges and skills section
- GitHub statistics and achievement trophies
- Project showcase and social links
- Automated activity updates with GitHub Actions
- Professional styling with emojis and alignment

 Technical implementation:
- Markdown with HTML for enhanced formatting
- External services integration (shields.io, vercel apps)
- GitHub Actions workflow for dynamic content
- Responsive design with proper image sizing
- SEO-friendly structure with semantic headers

Purpose: Professional online presence for networking and job applications"

echo "Subiendo al repositorio remoto..."
git push origin main

# 7. Verificar resultado
echo ""
echo " ¡Repositorio de perfil creado exitosamente!"
echo ""
echo " Verificaciones:"
echo "1. Repositorio en GitHub: https://github.com/$USERNAME/$USERNAME"
echo "2. Tu perfil actualizado: https://github.com/$USERNAME"
echo "3. Verificar con GitHub CLI:"

gh repo view "$USERNAME"

echo ""
echo " Tu README ahora aparece en tu perfil de GitHub como una carta de presentación profesional."
echo "[TIP] Tip: Actualizá regularmente este README con nuevos proyectos y habilidades."
echo ""
echo " Próximos pasos opcionales:"
echo "- Crear repositorio $USERNAME.github.io para tu sitio web personal"
echo "- Agregar más repositorios públicos para mostrar tu trabajo"
echo "- Contribuir a proyectos open source para mejorar tus estadísticas"
echo "- Configurar LinkedIn y otros perfiles para coincidir con tu GitHub"

```
<!-- {code-block} bash -->

:::
<!-- {solution} ejercicio-repositorio-perfil -->

(otros-repositorios-especiales)=
### Guía completa de repositorios especiales

#### Repositorio GitHub Pages (usuario.github.io)

```{code-block} bash
:linenos:
# Crear tu sitio web personal
gh repo create "$USERNAME.github.io" --public --clone
cd "$USERNAME.github.io"

# Crear página web básica
cat > index.html << EOF
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>$(gh api user --jq '.name // .login') - Portfolio</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            line-height: 1.6;
        }
        .hero { text-align: center; padding: 50px 0; }
        .projects { display: grid; grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); gap: 20px; }
        .project { border: 1px solid #ddd; padding: 20px; border-radius: 8px; }
    </style>
</head>
<body>
    <div class="hero">
        <h1>¡Hola! Soy $(gh api user --jq '.name // .login')</h1>
        <p>Desarrollador en crecimiento, apasionado por la tecnología</p>
    </div>

    <section>
        <h2>Sobre mí</h2>
        <p>Estoy aprendiendo desarrollo web y control de versiones con Git y GitHub.</p>
    </section>

    <section>
        <h2>Proyectos</h2>
        <div class="projects">
            <div class="project">
                <h3>Mi Portfolio GitHub</h3>
                <p>Repositorio especial de perfil con información profesional</p>
                <a href="https://github.com/$USERNAME">Ver en GitHub</a>
            </div>
        </div>
    </section>
</body>
</html>
EOF

git add .
git commit -m " Add personal website homepage"
git push origin main

echo " Tu sitio web estará disponible en: https://$USERNAME.github.io"

```
<!-- {code-block} bash -->

#### Repositorio de configuración (.github)

```{code-block} bash
:linenos:
# Crear repositorio para templates y configuración
gh repo create ".github" --public --clone
cd ".github"

# Template para issues
mkdir -p .github/ISSUE_TEMPLATE
cat > .github/ISSUE_TEMPLATE/bug_report.md << EOF
---
name:  Bug Report
about: Reportar un error o problema
title: '[BUG] '
labels: bug
assignees: ''
---

##  Descripción del bug
Una descripción clara y concisa del problema.

## Pasos para reproducir
1. Ir a '...'
2. Hacer click en '....'
3. Scroll down a '....'
4. Ver error

## Comportamiento esperado
Descripción clara de lo que esperabas que pasara.

## Capturas de pantalla (screenshots)
Si es aplicable, agregá screenshots para ayudar a explicar el problema.

## Información del entorno
- OS: [ej. macOS, Windows, Linux]
- Browser: [ej. Chrome, Safari]
- Versión: [ej. 22]
EOF

# Template para feature requests
cat > .github/ISSUE_TEMPLATE/feature_request.md << EOF
---
name: Feature Request
about: Sugerir una nueva funcionalidad
title: '[FEATURE] '
labels: enhancement
assignees: ''
---

## ¿Tu feature request está relacionado a un problema?
Una descripción clara y concisa del problema. Ej. Siempre me frustra cuando [...]

## Describe la solución que te gustaría
Descripción clara y concisa de lo que querés que pase.

## Describe alternativas que consideraste
Descripción clara y concisa de soluciones o features alternativas.

## Contexto adicional
Agregá cualquier otro contexto o screenshots sobre el feature request.
EOF

git add .
git commit -m "Add issue templates for better project management"
git push origin main

```
<!-- {code-block} bash -->

#### Resumen de repositorios especiales

| Repositorio          | Función                       | URL resultante                      |
| -------------------- | ----------------------------- | ----------------------------------- |
| `username/username`  | **Perfil README**             | Se muestra en `github.com/username` |
| `username.github.io` | **Sitio web personal**        | `https://username.github.io`        |
| `.github`            | **Templates y configuración** | Aplicable a todos tus repos         |
| `.github.io`         | **Alias de GitHub Pages**     | Alternativa a `username.github.io`  |

:::{tip} Estrategia de presencia online completa

Para una presencia profesional sólida en GitHub:

1. **Repositorio de perfil**: Tu carta de presentación (README llamativo)
2. **GitHub Pages**: Tu portfolio/CV online (sitio web profesional)
3. **Repositorios de proyectos**: Demostrar habilidades técnicas
4. **Contribuciones open source**: Mostrar colaboración y compromiso
5. **Actividad consistente**: Commits regulares demuestran dedicación 

:::
<!-- {tip} Estrategia de presencia online completa -->

### Buenas prácticas con GitHub

#### Repositorios públicos

- **README claro**: Explicá qué hace tu proyecto y cómo usarlo
- **Licencia**: Agregá un archivo LICENSE apropiado
- **Gitignore**: Configuralo para tu lenguaje/framework
- **Releases**: Usá tags para versiones estables
- **Issues templates**: Facilita el reporte de problemas

#### Perfil profesional

Ya viste en el {ref}`ejercicio-repositorio-perfil` cómo crear un repositorio de
perfil profesional. Acá hay algunos consejos adicionales para maximizar su
impacto:

```{code-block} bash
:linenos:
# El proceso completo está detallado en el ejercicio anterior
# Puntos clave para un perfil efectivo:

# 1. Información personal clara y profesional
# 2. Tecnologías con badges visuales atractivos
# 3. Estadísticas de GitHub dinámicas
# 4. Enlaces a proyectos y redes sociales
# 5. Diseño responsive y bien estructurado

# Ver ejercicio completo: {ref}`ejercicio-repositorio-perfil`
echo "Consulta el ejercicio anterior para el proceso completo paso a paso"

```
<!-- {code-block} bash -->

**Elementos clave de un perfil profesional efectivo:**

- **Header atractivo**: Nombre, título, y animación de texto
- **Sección "Sobre mí"**: Información personal y profesional
- **Tecnologías**: Badges coloridos de lenguajes y herramientas
- **Estadísticas**: GitHub stats automáticas y trophies
- **Proyectos**: Enlaces a repositorios importantes
- **Contacto**: Redes sociales y email profesional
- **Actualización regular**: Mantener información actualizada

#### Colaboración efectiva

- **Commits descriptivos**: Explicá el "qué" y el "por qué"
- **Issues claros**: Usá templates y labels consistentemente
- **Pull requests pequeños**: Cambios enfocados y revisables
- **Documentación**: Mantené README y docs actualizadas

### Troubleshooting común

#### Problemas de autenticación

```{code-block} bash
:linenos:
# Verificar autenticación actual
gh auth status

# Re-autenticar si hay problemas
gh auth logout
gh auth login

# Verificar configuración de Git
git config --global user.name
git config --global user.email

```
<!-- {code-block} bash -->

#### Problemas con permisos

``` bash
# Si tenés problemas de permisos, verificar:
gh repo view
gh auth status

# Para repositorios de organizaciones
gh auth refresh --scopes repo,org:read
```
<!-- bash -->

#### Sincronización de cambios

``` bash
# Si hay conflictos al hacer push
git status
git pull origin main
# Resolver conflictos si existen
git push origin main
```
<!-- bash -->



## 7. Temas conexos

### Integración Continua (CI)

Cada vez que abrís un Pull Request o realizás un `push` a una rama de entrega,
se disparan flujos automáticos de comprobación (GitHub Actions). Estos procesos
se encargan de compilar tu proyecto bajo la suite de compiladores de la cátedra
y correr los tests automáticos.

*   Si el flujo termina de forma correcta, verás un tilde verde (✔).
*   Si falla, verás una cruz roja (❌). Hacé clic en los detalles del fallo para
    verificar qué tests no se superaron o qué error de compilación ocurrió en el
    servidor remoto.

:::{figure} images/github_actions_status.png
:alt: Captura de pantalla del estado de las comprobaciones automáticas de GitHub Actions al final de la página de un Pull Request. Se observa una cruz roja junto al nombre del workflow 'Compilación y Tests' indicando que una comprobación ha fallado, acompañado del enlace 'Details' para acceder al log detallado del compilador.
:align: center
:width: 85%

Visualización del estado de los tests automatizados de integración continua en
el Pull Request.

:::
<!-- {figure} images/github_actions_status.png -->
