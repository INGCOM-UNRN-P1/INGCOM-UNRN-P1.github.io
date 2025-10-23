---
title: Guía completa de Visual Studio Code
short_title: Guía VSCode
subtitle: Instalación y primeros pasos.
---

## ¿Por qué elegir VS Code?

Visual Studio Code (VS Code) es un editor de código desarrollado por Microsoft
que se ha convertido en el estándar de facto para el desarrollo moderno. Es
gratuito, open source, y extremadamente poderoso gracias a su ecosistema de
extensiones.

### Ventajas principales

- **Gratuito y open source**: Sin limitaciones ni costos ocultos
- **Multiplataforma**: Funciona en Linux, Windows y macOS de forma idéntica
- **Ecosistema de extensiones**: Miles de extensiones para cualquier lenguaje o
  framework
- **IntelliSense potente**: Autocompletado inteligente y sugerencias
  contextuales
- **Git integrado**: Control de versiones nativo sin herramientas externas
- **Terminal integrada**: Bash, PowerShell o cualquier terminal desde dentro del
  editor
- **Debugging avanzado**: Depurador visual para múltiples lenguajes
- **Liveshare**: Colaboración en tiempo real con otros desarrolladores

:::{note} Origenes

VS Code fue lanzado en 2015 y rápidamente se volvió el editor más
popular entre desarrolladores según encuestas de Stack Overflow. Su combinación
de simplicidad y potencia lo hace ideal tanto para principiantes como expertos.


:::

## Instalación en diferentes sistemas

### Linux (Ubuntu/Debian)

#### Método 1: Paquete .deb (recomendado)

```bash
# Descargar e instalar el paquete oficial
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'

sudo apt update
sudo apt install code
```

#### Método 2: Snap (alternativo)

```bash
sudo snap install --classic code
```

#### Método 3: AppImage (portable)

```bash
# Descargar desde el sitio oficial
wget "https://code.visualstudio.com/sha/download?build=stable&os=linux-x64" -O code.AppImage
chmod +x code.AppImage
./code.AppImage
```

### Linux (CentOS/RHEL/Fedora)

```bash
# Agregar repositorio de Microsoft
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'

# Instalar
sudo dnf check-update
sudo dnf install code

# O en sistemas más antiguos con yum
sudo yum check-update
sudo yum install code
```

### macOS

#### Método 1: Descarga directa (simple)

1. Visitá [code.visualstudio.com](https://code.visualstudio.com)
2. Descargá VS Code para macOS
3. Abrí el archivo .zip descargado
4. Arrastrá Visual Studio Code a la carpeta Applications

#### Método 2: Homebrew (recomendado para desarrolladores)

```bash
# Instalar con Homebrew
brew install --cask visual-studio-code
```

### Windows

#### Método 1: Instalador oficial

1. Descargá el instalador desde
   [code.visualstudio.com](https://code.visualstudio.com)
2. Ejecutá el archivo .exe descargado
3. Seguí el asistente de instalación
4. **Importante**: Marcá las opciones:
   - "Add to PATH" (agregar al PATH)
   - "Register Code as an editor for supported file types"
   - "Add 'Open with Code' action to context menu"

#### Método 2: Winget (Windows 10/11)

```bash
winget install Microsoft.VisualStudioCode
```

#### Método 3: Chocolatey

```bash
choco install vscode
```

## Primera configuración

### Verificar instalación

```bash
# Verificar que VS Code está en el PATH
code --version

# Abrir VS Code desde terminal
code

# Abrir directorio actual en VS Code
code .

# Abrir archivo específico
code mi-archivo.py
```

### Configuración inicial recomendada

Al abrir VS Code por primera vez:

1. **Elegir tema**: `Ctrl+Shift+P` → "Preferences: Color Theme"

   - **Dark+ (default dark)**: tema oscuro por defecto
   - **Light+ (default light)**: tema claro
   - **Monokai**: popular tema oscuro
   - **Solarized Dark**: tema con colores suaves

2. **Configurar idioma**: Si preferís interfaz en español

   - `Ctrl+Shift+P` → "Configure Display Language"
   - Instalar "Spanish Language Pack" si está disponible

3. **Activar autosave**: `File` → `Auto Save`
   - Evita perder trabajo por olvidos

## Interfaz y navegación básica

### Layout principal

```
┌─────────────────────────────────────────────────────┐
│  Menu Bar                                           │
├─────────┬───────────────────────────┬───────────────┤
│Activity │                           │               │
│Bar      │     Editor Area           │  Side Panel   │
│         │                           │  (opcional)   │
│         │                           │               │
├─────────┴───────────────────────────┴───────────────┤
│                Panel Area                           │
│             (Terminal, Output, etc.)                │
├─────────────────────────────────────────────────────┤
│               Status Bar                            │
└─────────────────────────────────────────────────────┘
```

### Activity Bar (barra lateral izquierda)

- **Explorer** (`Ctrl+Shift+E`): Navegador de archivos y carpetas
- **Search** (`Ctrl+Shift+F`): Búsqueda en todo el proyecto
- **Source Control** (`Ctrl+Shift+G`): Integración con Git
- **Run and Debug** (`Ctrl+Shift+D`): Depurador
- **Extensions** (`Ctrl+Shift+X`): Gestión de extensiones

### Atajos de teclado esenciales

#### Navegación y archivos

```bash
Ctrl+N              # Nuevo archivo
Ctrl+O              # Abrir archivo
Ctrl+S              # Guardar archivo
Ctrl+Shift+S        # Guardar como...
Ctrl+W              # Cerrar pestaña actual
Ctrl+Shift+T        # Reabrir última pestaña cerrada
Ctrl+Tab            # Alternar entre pestañas abiertas
Ctrl+P              # Quick Open (buscar archivos)
Ctrl+Shift+P        # Command Palette (todos los comandos)
```

#### Edición

```bash
Ctrl+Z              # Deshacer
Ctrl+Y              # Rehacer
Ctrl+X              # Cortar línea completa (sin selección)
Ctrl+C              # Copiar línea completa (sin selección)
Ctrl+V              # Pegar
Ctrl+Shift+K        # Eliminar línea
Ctrl+Enter          # Insertar línea debajo
Ctrl+Shift+Enter    # Insertar línea arriba
Alt+↑/↓             # Mover línea arriba/abajo
Shift+Alt+↑/↓       # Duplicar línea arriba/abajo
```

#### Búsqueda y reemplazo

```bash
Ctrl+F              # Buscar en archivo actual
Ctrl+H              # Buscar y reemplazar
Ctrl+Shift+F        # Buscar en todo el proyecto
Ctrl+Shift+H        # Reemplazar en todo el proyecto
F3                  # Siguiente ocurrencia
Shift+F3            # Ocurrencia anterior
```

#### Selección múltiple

```bash
Ctrl+D              # Seleccionar siguiente ocurrencia de palabra
Ctrl+Shift+L        # Seleccionar todas las ocurrencias
Alt+Click           # Agregar cursor adicional
Ctrl+Alt+↑/↓        # Agregar cursor arriba/abajo
```

## Extensiones esenciales

Las extensiones son el verdadero poder de VS Code. Acá están las más importantes
para comenzar:

### Extensiones básicas universales

#### 1. **Prettier - Code formatter**

```bash
# Instalar desde terminal
code --install-extension esbenp.prettier-vscode
```

- Formateador automático de código
- Soporta JavaScript, HTML, CSS, JSON, Markdown y más
- Se configura como formateador por defecto

#### 2. **GitLens**

```bash
code --install-extension eamodio.gitlens
```

- Superpoderes para Git integrado
- Ve quién modificó cada línea y cuándo
- Historial de archivos y comparaciones visuales

#### 3. **Auto Rename Tag**

```bash
code --install-extension formulahendry.auto-rename-tag
```

- Renombra automáticamente tags HTML/XML pareados
- Esencial para desarrollo web

#### 4. **Bracket Pair Colorizer** (integrado desde VS Code 1.60+)

- Colorea paréntesis, corchetes y llaves pareados
- Ayuda a identificar bloques de código rápidamente

#### 5. **Live Server**

```bash
code --install-extension ritwickdey.liveserver
```

- Servidor local con recarga automática
- Perfecto para desarrollo web frontend

### Extensiones por lenguaje

#### Python

```bash
code --install-extension ms-python.python
```

- IntelliSense, linting, debugging para Python
- Integración con Jupyter notebooks

#### JavaScript/TypeScript

```bash
code --install-extension ms-vscode.vscode-typescript-next
```

- Soporte avanzado para JS/TS (viene integrado)

#### HTML/CSS

```bash
code --install-extension ecmel.vscode-html-css
```

- Autocompletado de CSS en archivos HTML

#### C/C++

```bash
code --install-extension ms-vscode.cpptools
```

- IntelliSense, debugging y browsing para C++

#### Java

```bash
code --install-extension vscjava.vscode-java-pack
```

- Pack completo para desarrollo Java

### Temas y apariencia

#### Temas populares

```bash
# Tema oscuro muy popular
code --install-extension PKief.material-icon-theme

# Iconos bonitos para archivos
code --install-extension PKief.material-icon-theme

# Tema Dracula
code --install-extension dracula-theme.theme-dracula
```

### Instalar extensiones desde interfaz

1. Abrí la vista de extensiones (`Ctrl+Shift+X`)
2. Buscá el nombre de la extensión
3. Hacé click en "Install"
4. Reiniciá VS Code si es necesario

## Configuración y personalización

### Configuración de usuario vs workspace

VS Code tiene dos niveles de configuración:

- **User Settings**: Aplican a todas las instancias de VS Code
- **Workspace Settings**: Solo para el proyecto/carpeta actual

#### Acceder a configuración

```bash
# Desde Command Palette
Ctrl+Shift+P → "Preferences: Open Settings"

# O con atajo directo
Ctrl+,
```

### Configuraciones esenciales

#### settings.json básico

```json
{
  // Configuración del editor
  "editor.fontSize": 14,
  "editor.tabSize": 4,
  "editor.insertSpaces": true,
  "editor.wordWrap": "on",
  "editor.minimap.enabled": true,
  "editor.renderWhitespace": "selection",
  "editor.formatOnSave": true,

  // Configuración de archivos
  "files.autoSave": "afterDelay",
  "files.autoSaveDelay": 1000,
  "files.trimTrailingWhitespace": true,
  "files.insertFinalNewline": true,

  // Terminal integrada
  "terminal.integrated.fontSize": 12,
  "terminal.integrated.shell.linux": "/bin/bash",

  // Git
  "git.enableSmartCommit": true,
  "git.confirmSync": false,

  // Prettier
  "editor.defaultFormatter": "esbenp.prettier-vscode",
  "prettier.singleQuote": true,
  "prettier.semi": true
}
```

#### Abrir configuración como JSON

```bash
# Command Palette
Ctrl+Shift+P → "Preferences: Open Settings (JSON)"
```

### Snippets personalizados

Los snippets son plantillas de código reutilizables.

#### Crear snippet personalizado

1. `Ctrl+Shift+P` → "Preferences: Configure User Snippets"
2. Elegir lenguaje (ej: "html.json")
3. Agregar snippet:

```json
{
  "HTML5 Boilerplate": {
    "prefix": "html5",
    "body": [
      "<!DOCTYPE html>",
      "<html lang=\"es\">",
      "<head>",
      "    <meta charset=\"UTF-8\">",
      "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">",
      "    <title>$1</title>",
      "</head>",
      "<body>",
      "    $0",
      "</body>",
      "</html>"
    ],
    "description": "HTML5 boilerplate básico"
  }
}
```

Uso: Escribí `html5` y presioná `Tab` para expandir.

## Terminal integrada

Una de las características más útiles de VS Code es su terminal integrada.

### Usar la terminal

```bash
# Abrir/cerrar terminal
Ctrl+`

# Nueva terminal
Ctrl+Shift+`

# Alternar entre terminales
Ctrl+PageUp/PageDown
```

### Configurar terminal por defecto

#### En Linux/macOS

```json
{
  "terminal.integrated.shell.linux": "/bin/bash",
  "terminal.integrated.shell.osx": "/bin/zsh"
}
```

#### En Windows

```json
{
  "terminal.integrated.shell.windows": "C:\\Windows\\System32\\cmd.exe"
  // O para PowerShell:
  // "terminal.integrated.shell.windows": "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
  // O para Git Bash:
  // "terminal.integrated.shell.windows": "C:\\Program Files\\Git\\bin\\bash.exe"
}
```

## Integración con Git

VS Code tiene integración nativa con Git que facilita enormemente el control de
versiones.

### Configuración inicial de Git

Si no configuraste Git globalmente:

```bash
# En la terminal integrada de VS Code
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@ejemplo.com"
```

### Usar Git desde VS Code

#### Inicializar repositorio

1. Abrí carpeta de proyecto (`Ctrl+K Ctrl+O`)
2. Vista Source Control (`Ctrl+Shift+G`)
3. Click "Initialize Repository"

#### Hacer commits

1. Modificá archivos (aparecen en Source Control con "M")
2. Agregá archivos al staging (click en "+")
3. Escribí mensaje de commit
4. `Ctrl+Enter` o click en "✓" para commit

#### Funciones avanzadas

```bash
# Ver diferencias
Click en archivo modificado en Source Control

# Historial de commits
Con GitLens instalado: click en línea → "Git Blame"

# Crear branch
Ctrl+Shift+P → "Git: Create Branch"

# Cambiar branch
Click en nombre de branch en Status Bar
```

## Debugging (depuración)

VS Code incluye un depurador visual potente para múltiples lenguajes.

### Configurar debugging

#### Para Python

1. Creá archivo `.vscode/launch.json` en tu proyecto:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Python: Current File",
      "type": "python",
      "request": "launch",
      "program": "${file}",
      "console": "integratedTerminal"
    }
  ]
}
```

#### Para JavaScript (Node.js)

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Launch Program",
      "type": "node",
      "request": "launch",
      "program": "${file}",
      "console": "integratedTerminal"
    }
  ]
}
```

### Usar el debugger

1. Poné breakpoints (click izquierda del número de línea)
2. `F5` para iniciar debugging
3. Usar controles:
   - `F5`: Continue
   - `F10`: Step Over
   - `F11`: Step Into
   - `Shift+F11`: Step Out
   - `Shift+F5`: Stop

## Flujos de trabajo comunes

### Desarrollo web básico

#### Estructura de proyecto típica

```
mi-proyecto-web/
├── index.html
├── css/
│   └── styles.css
├── js/
│   └── script.js
└── images/
    └── logo.png
```

#### Workflow con Live Server

1. Instalá Live Server extension
2. Abrí tu proyecto en VS Code
3. Click derecho en `index.html` → "Open with Live Server"
4. El navegador se abre automáticamente
5. Los cambios se reflejan instantáneamente

### Desarrollo Python

#### Setup básico

```bash
# Crear proyecto Python
mkdir mi-proyecto-python
cd mi-proyecto-python
code .

# Crear entorno virtual
python -m venv venv

# Activar entorno virtual
# Linux/macOS:
source venv/bin/activate
# Windows:
venv\Scripts\activate

# Crear archivo requirements.txt
echo "requests==2.28.1" > requirements.txt

# Instalar dependencias
pip install -r requirements.txt
```

#### Configuración de Python en VS Code

1. `Ctrl+Shift+P` → "Python: Select Interpreter"
2. Elegir el intérprete del venv
3. VS Code detecta automáticamente el entorno

### Proyecto con Git

#### Setup completo desde cero

```bash
# Crear directorio y abrir en VS Code
mkdir mi-proyecto
cd mi-proyecto
code .

# Inicializar Git desde terminal integrada
git init

# Crear archivos básicos
touch README.md
echo "node_modules/" > .gitignore

# Hacer primer commit desde Source Control
# 1. Agregar archivos al staging
# 2. Escribir mensaje "Initial commit"
# 3. Commit

# Conectar con GitHub (si tenés repo remoto)
git remote add origin https://github.com/usuario/mi-proyecto.git
git push -u origin main
```

## Ejercicios prácticos

:::{exercise} ejercicio-setup-vscode
:label: ejercicio-setup-vscode

**Ejercicio 1: Setup completo de VS Code**

1. Instalá VS Code en tu sistema usando el método apropiado
2. Configuralo con estas preferencias:
   - Tema oscuro
   - Auto-save activado
   - Formato al guardar activado
3. Instalá estas extensiones esenciales:
   - Prettier
   - GitLens
   - Live Server
4. Verificá que podés abrir VS Code desde terminal con `code .` 

:::

:::{solution} ejercicio-setup-vscode

```bash
# 1. Instalación en Ubuntu/Debian
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
sudo apt update
sudo apt install code

# 2. Configuración básica
# Abrir VS Code
code

# Configurar tema oscuro: Ctrl+Shift+P → "Preferences: Color Theme" → "Dark+ (default dark)"

# Configurar auto-save: File → Auto Save (click para activar)

# 3. Instalar extensiones desde terminal
code --install-extension esbenp.prettier-vscode
code --install-extension eamodio.gitlens
code --install-extension ritwickdey.liveserver

# 4. Verificar instalación
code --version
echo "Si este comando abre VS Code en el directorio actual, ¡todo está funcionando!"
code .

# Configuración adicional en settings.json
# Ctrl+Shift+P → "Preferences: Open Settings (JSON)"
# Agregar:
{
    "files.autoSave": "afterDelay",
    "editor.formatOnSave": true,
    "editor.defaultFormatter": "esbenp.prettier-vscode"
}
```

:::

:::{exercise} ejercicio-proyecto-web
:label: ejercicio-proyecto-web

**Ejercicio 2: Primer proyecto web con VS Code**

1. Creá un proyecto web simple con HTML, CSS y JavaScript
2. Usá Live Server para preview en tiempo real
3. Configurá Prettier para formateo automático
4. Inicializá Git y hacé commits de tu progreso
5. Agregá un snippet personalizado para estructura HTML 

:::

:::{solution} ejercicio-proyecto-web

```bash
# 1. Crear estructura del proyecto
mkdir mi-primera-web
cd mi-primera-web
code .

# Crear archivos desde terminal integrada de VS Code (Ctrl+`)
mkdir css js
touch index.html css/styles.css js/script.js

# 2. Contenido del index.html
cat > index.html << 'EOF'
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mi Primera Web</title>
    <link rel="stylesheet" href="css/styles.css">
</head>
<body>
    <header>
        <h1>Mi Primera Página Web</h1>
    </header>
    <main>
        <section>
            <h2>Bienvenido</h2>
            <p>Esta es mi primera página creada con VS Code.</p>
            <button id="miBoton">¡Haz click aquí!</button>
        </section>
    </main>
    <script src="js/script.js"></script>
</body>
</html>
EOF

# 3. CSS básico
cat > css/styles.css << 'EOF'
body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 20px;
    background-color: #f4f4f4;
}

header {
    text-align: center;
    margin-bottom: 2rem;
}

h1 {
    color: #333;
    border-bottom: 3px solid #007acc;
    padding-bottom: 10px;
}

section {
    background: white;
    padding: 20px;
    border-radius: 8px;
    box-shadow: 0 2px 5px rgba(0,0,0,0.1);
}

button {
    background-color: #007acc;
    color: white;
    border: none;
    padding: 10px 20px;
    border-radius: 4px;
    cursor: pointer;
    font-size: 16px;
}

button:hover {
    background-color: #005999;
}
EOF

# 4. JavaScript básico
cat > js/script.js << 'EOF'
document.addEventListener('DOMContentLoaded', function() {
    const boton = document.getElementById('miBoton');

    boton.addEventListener('click', function() {
        alert('¡Hola desde VS Code!');
        boton.textContent = '¡Funciona!';
        boton.style.backgroundColor = '#28a745';
    });
});
EOF

# 5. Configurar Live Server
# Click derecho en index.html → "Open with Live Server"
# O Ctrl+Shift+P → "Live Server: Open with Live Server"

# 6. Inicializar Git
git init
echo "node_modules/" > .gitignore

# Hacer commits progresivos
git add index.html css/styles.css
git commit -m "Add HTML structure and basic CSS"

git add js/script.js
git commit -m "Add interactive JavaScript functionality"

git add .gitignore
git commit -m "Add gitignore file"

# 7. Crear snippet HTML personalizado
# Ctrl+Shift+P → "Preferences: Configure User Snippets" → "html.json"
# Agregar este snippet:
{
    "HTML5 Responsive": {
        "prefix": "html5resp",
        "body": [
            "<!DOCTYPE html>",
            "<html lang=\"es\">",
            "<head>",
            "    <meta charset=\"UTF-8\">",
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">",
            "    <title>$1</title>",
            "    <link rel=\"stylesheet\" href=\"css/styles.css\">",
            "</head>",
            "<body>",
            "    $0",
            "    <script src=\"js/script.js\"></script>",
            "</body>",
            "</html>"
        ],
        "description": "HTML5 boilerplate con CSS y JS"
    }
}

echo "¡Proyecto completado! Ahora podés usar 'html5resp' + Tab para crear estructura HTML rápida"
```

:::

### Ejercicios adicionales para practicar

#### Nivel Básico

1. **Familiarización con atajos**: Practicá los atajos esenciales creando y
   editando archivos de texto.

2. **Personalización de tema**: Explorá diferentes temas e iconos hasta
   encontrar tu configuración ideal.

3. **Gestión de extensiones**: Instalá y desinstalá diferentes extensiones para
   entender cómo cambian la funcionalidad.

#### Nivel Intermedio

4. **Multi-cursor editing**: Practicá edición con múltiples cursores para
   modificar varias líneas simultáneamente.

5. **Snippets avanzados**: Creá snippets para tu lenguaje favorito con variables
   y placeholders.

6. **Debugging básico**: Configurá el debugger para un proyecto simple y
   practicá usar breakpoints.

## Consejos y trucos avanzados

### Comandos útiles desde Command Palette

```bash
# Acceso rápido: Ctrl+Shift+P

"Developer: Reload Window"           # Reiniciar VS Code sin cerrar
"Preferences: Open Keyboard Shortcuts" # Personalizar atajos
"View: Toggle Terminal"              # Mostrar/ocultar terminal
"Format Document"                    # Formatear archivo completo
"Transform to Uppercase/Lowercase"   # Cambiar case del texto seleccionado
"Sort Lines Ascending"               # Ordenar líneas alfabéticamente
```

### Navegación eficiente

```bash
Ctrl+G                    # Ir a línea específica
Ctrl+Shift+O             # Ir a símbolo en archivo
Ctrl+T                   # Ir a símbolo en workspace
Ctrl+P                   # Quick Open (buscar archivos)
Ctrl+R                   # Abrir workspace reciente
Alt+← / Alt+→            # Navegar historial de archivos
```

### Edición avanzada

```bash
Ctrl+Shift+\             # Ir a paréntesis/bracket de cierre
Ctrl+]/[                 # Indentar/desindentar
Ctrl+/                   # Comentar/descomentar línea
Shift+Alt+A              # Comentar/descomentar bloque
Ctrl+Shift+↑/↓          # Seleccionar líneas arriba/abajo
Ctrl+L                   # Seleccionar línea completa
```

### Workspace multi-carpeta

VS Code permite trabajar con múltiples carpetas en un solo workspace:

1. `File` → `Add Folder to Workspace`
2. Guardar workspace: `File` → `Save Workspace As`
3. El archivo `.code-workspace` guarda la configuración

## Configuración avanzada para C/C++

Esta sección cubre la configuración profesional de VS Code para desarrollo en C, incluyendo Language Server Protocol (LSP), compilación integrada y debugging visual.

### Instalación de extensiones necesarias

Para trabajar con C en VS Code, necesitás instalar estas extensiones fundamentales:

1. **C/C++ (Microsoft)** - `ms-vscode.cpptools`
   - IntelliSense, debugging y navegación de código
   - Language server oficial de Microsoft

2. **clangd** - `llvm-vs-code-extensions.vscode-clangd` (alternativa recomendada)
   - Language server más rápido y preciso que el de Microsoft
   - Mejor autocompletado y diagnósticos

3. **Makefile Tools** - `ms-vscode.makefile-tools`
   - Soporte para proyectos con Makefiles
   - Compilación integrada

4. **CodeLLDB** - `vadimcn.vscode-lldb` (opcional, para debugging avanzado)
   - Debugger alternativo con mejor visualización

```bash
# Instalar desde terminal
code --install-extension ms-vscode.cpptools
code --install-extension llvm-vs-code-extensions.vscode-clangd
code --install-extension ms-vscode.makefile-tools
```

### Configuración del Language Server: clangd

El Language Server Protocol (LSP) es un estándar que permite a los editores obtener información semántica del código: autocompletado, diagnósticos, navegación, refactoring, etc. Para C, `clangd` es la opción más robusta.

#### Instalación de clangd

```bash
# Ubuntu/Debian
sudo apt install clangd

# Fedora/RHEL
sudo dnf install clang-tools-extra

# macOS
brew install llvm

# Verificar instalación
clangd --version
```

#### Configuración de clangd en VS Code

Creá o editá el archivo `.vscode/settings.json` en tu proyecto:

```json
{
    // Configuración de clangd
    "clangd.path": "/usr/bin/clangd",
    "clangd.arguments": [
        "--background-index",
        "--clang-tidy",
        "--completion-style=detailed",
        "--header-insertion=iwyu",
        "--pch-storage=memory"
    ],
    
    // Desactivar IntelliSense de C/C++ extension para evitar conflictos
    "C_Cpp.intelliSenseEngine": "disabled",
    
    // Configuración de formato (clang-format)
    "editor.formatOnSave": true,
    "C_Cpp.clang_format_style": "{ BasedOnStyle: LLVM, IndentWidth: 4, UseTab: Never }",
    
    // Ayudas visuales
    "editor.bracketPairColorization.enabled": true,
    "editor.guides.bracketPairs": true
}
```

**Explicación de argumentos de clangd:**

- `--background-index`: Indexa el código en segundo plano para navegación rápida
- `--clang-tidy`: Activa análisis estático de código (detecta bugs comunes)
- `--completion-style=detailed`: Autocompletado detallado con documentación
- `--header-insertion=iwyu`: Incluye headers automáticamente ("Include What You Use")
- `--pch-storage=memory`: Usa RAM para headers precompilados (más rápido)

#### Archivo compile_commands.json

Para que clangd entienda tu proyecto, necesita saber cómo compilarlo. Esto se especifica en `compile_commands.json`.

**Método 1: Generar con Make + Bear**

```bash
# Instalar bear (Build EAR - genera compile_commands.json)
sudo apt install bear  # Ubuntu/Debian
sudo dnf install bear  # Fedora

# Generar compile_commands.json
bear -- make

# Esto crea compile_commands.json en el directorio actual
```

**Método 2: Generar manualmente para proyecto simple**

Si tenés un proyecto simple con pocos archivos, podés crear `compile_commands.json` manualmente:

```json
[
  {
    "directory": "/home/usuario/mi-proyecto",
    "command": "gcc -Wall -Wextra -std=c11 -g -o programa main.c lista.c utils.c",
    "file": "main.c"
  },
  {
    "directory": "/home/usuario/mi-proyecto",
    "command": "gcc -Wall -Wextra -std=c11 -g -o programa main.c lista.c utils.c",
    "file": "lista.c"
  },
  {
    "directory": "/home/usuario/mi-proyecto",
    "command": "gcc -Wall -Wextra -std=c11 -g -o programa main.c lista.c utils.c",
    "file": "utils.c"
  }
]
```

**Método 3: Con CMake**

```bash
# CMake genera compile_commands.json automáticamente
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .

# Crear symlink en la raíz del proyecto si CMake está en build/
ln -s build/compile_commands.json compile_commands.json
```

:::{tip} Verificación de clangd

Para verificar que clangd está funcionando correctamente:

1. Abrí un archivo `.c` en VS Code
2. Esperá unos segundos a que clangd indexe
3. Deberías ver:
   - **Autocompletado inteligente** al tipear
   - **Errores subrayados** en tiempo real
   - **Tooltips con documentación** al pasar el mouse
   - **"Go to Definition"** (F12) funcionando

Si no funciona, revisá el output: `View` → `Output` → seleccionar "clangd" en el dropdown.
:::

### Configuración de compilación integrada

VS Code permite compilar tu proyecto sin salir del editor. Hay dos métodos principales:

#### Método 1: Tasks con tasks.json (proyecto simple)

Creá `.vscode/tasks.json`:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar programa",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-Wall",
                "-Wextra",
                "-Wconversion",
                "-std=c11",
                "-g",
                "-o",
                "${workspaceFolder}/programa",
                "${workspaceFolder}/main.c",
                "${workspaceFolder}/lista.c",
                "${workspaceFolder}/utils.c"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "reveal": "always",
                "panel": "shared"
            },
            "problemMatcher": "$gcc"
        },
        {
            "label": "Compilar con sanitizers",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-Wall",
                "-Wextra",
                "-Wconversion",
                "-std=c11",
                "-g",
                "-fsanitize=address",
                "-fsanitize=undefined",
                "-o",
                "${workspaceFolder}/programa-sanitized",
                "${workspaceFolder}/main.c",
                "${workspaceFolder}/lista.c",
                "${workspaceFolder}/utils.c"
            ],
            "group": "build",
            "problemMatcher": "$gcc"
        },
        {
            "label": "Ejecutar programa",
            "type": "shell",
            "command": "${workspaceFolder}/programa",
            "dependsOn": ["Compilar programa"],
            "group": {
                "kind": "test",
                "isDefault": true
            }
        },
        {
            "label": "Limpiar",
            "type": "shell",
            "command": "rm",
            "args": [
                "-f",
                "${workspaceFolder}/programa",
                "${workspaceFolder}/programa-sanitized"
            ],
            "group": "build"
        }
    ]
}
```

**Uso de tasks:**

```bash
# Compilar (task por defecto)
Ctrl+Shift+B

# Ejecutar task específica
Ctrl+Shift+P → "Tasks: Run Task" → elegir task

# Atajo: configurar keybinding personalizado
# File → Preferences → Keyboard Shortcuts → buscar "workbench.action.tasks.runTask"
```

**Explicación de opciones importantes:**

- `"isDefault": true`: Marca la task como predeterminada para `Ctrl+Shift+B`
- `"problemMatcher": "$gcc"`: Parsea la salida de GCC para mostrar errores en el panel "Problems"
- `"dependsOn"`: Ejecuta otra task antes de esta (útil para "compilar y ejecutar")
- `"presentation"`: Controla cómo se muestra la terminal de la task

#### Método 2: Makefile Tools (proyecto con Makefile)

Si tu proyecto usa Makefile, la extensión Makefile Tools provee integración visual.

**Configuración en `.vscode/settings.json`:**

```json
{
    "makefile.extensionOutputFolder": ".vscode",
    "makefile.launchConfigurations": [
        {
            "cwd": "${workspaceFolder}",
            "binaryPath": "${workspaceFolder}/programa",
            "binaryArgs": []
        }
    ],
    "makefile.configurations": [
        {
            "name": "Debug",
            "makeArgs": ["DEBUG=1"]
        },
        {
            "name": "Release",
            "makeArgs": []
        }
    ]
}
```

**Uso:**

- La extensión agrega una barra lateral con targets de Make
- Botón "Build" en la barra de estado para compilar
- Selección de configuración (Debug/Release)
- Navegación visual de targets

:::{important} Variables útiles en tasks y launch configs

VS Code provee variables que podés usar en configuraciones:

- `${workspaceFolder}`: Ruta absoluta del workspace
- `${file}`: Archivo actualmente abierto
- `${fileBasename}`: Nombre del archivo sin ruta
- `${fileBasenameNoExtension}`: Nombre sin extensión
- `${fileDirname}`: Directorio del archivo actual
- `${cwd}`: Directorio de trabajo actual
- `${env:VARIABLE}`: Variable de entorno

Ejemplo: `"${workspaceFolder}/build/${fileBasenameNoExtension}"`
:::

### Configuración de debugging integrado

El debugging visual es una de las características más poderosas de VS Code. Permite ejecutar código paso a paso, inspeccionar variables, establecer breakpoints condicionales, y más.

#### Configuración básica de launch.json

Creá `.vscode/launch.json`:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug programa",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/programa",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Establecer flavor de desensamblado a Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compilar programa",
            "miDebuggerPath": "/usr/bin/gdb",
            "logging": {
                "engineLogging": false
            }
        },
        {
            "name": "Debug con argumentos",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/programa",
            "args": ["archivo.txt", "--verbose"],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "preLaunchTask": "Compilar programa"
        },
        {
            "name": "Debug test específico",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/tests/test_lista",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "preLaunchTask": "Compilar tests"
        },
        {
            "name": "Attach a proceso corriendo",
            "type": "cppdbg",
            "request": "attach",
            "program": "${workspaceFolder}/programa",
            "processId": "${command:pickProcess}",
            "MIMode": "gdb"
        }
    ]
}
```

**Explicación de campos importantes:**

- `"type": "cppdbg"`: Usa el debugger de C/C++ de Microsoft (basado en GDB/LLDB)
- `"request": "launch"`: Inicia el programa (vs. "attach" a proceso existente)
- `"program"`: Ruta al ejecutable a debuggear
- `"args"`: Argumentos de línea de comandos
- `"stopAtEntry": true`: Para en la primera línea de `main()`
- `"preLaunchTask"`: Task a ejecutar antes de debuggear (típicamente, compilar)
- `"MIMode"`: Debugger backend ("gdb" en Linux, "lldb" en macOS)
- `"externalConsole": false`: Usa terminal integrada de VS Code

#### Uso del debugger

**Iniciar debugging:**

```bash
# Iniciar debug de la configuración por defecto
F5

# Seleccionar configuración y debuggear
Ctrl+Shift+D → seleccionar config → F5

# Ejecutar sin debuggear
Ctrl+F5
```

**Controles de debugging:**

```bash
F5          # Continuar ejecución
F10         # Step Over (ejecutar línea, no entrar en funciones)
F11         # Step Into (entrar en función)
Shift+F11   # Step Out (salir de función actual)
Shift+F5    # Detener debugging
Ctrl+Shift+F5  # Reiniciar debugging
```

**Breakpoints:**

- **Click izquierdo** en el margen izquierdo del editor (aparece punto rojo)
- **Breakpoint condicional**: Click derecho → "Add Conditional Breakpoint"
  - Ejemplo: `i == 50` (para solo cuando `i` es 50)
  - Ejemplo: `strcmp(nombre, "test") == 0`
- **Logpoint**: Imprime mensaje sin detener ejecución
  - Click derecho → "Add Logpoint"
  - Ejemplo: `"Valor de i: {i}, ptr: {ptr}"`

**Paneles de debugging:**

1. **Variables**: Inspección de variables locales y globales
   - Expandir estructuras y punteros
   - Click derecho → "Add to Watch" para monitorear

2. **Watch**: Expresiones personalizadas a monitorear
   - Agregar expresiones como `lista->tamanio`, `*ptr`, etc.
   - Se evalúan en cada paso

3. **Call Stack**: Pila de llamadas actual
   - Click en frame para ver variables en ese contexto
   - Útil para entender cómo llegaste a un punto

4. **Breakpoints**: Lista de todos los breakpoints
   - Habilitar/deshabilitar sin eliminar
   - Ver condiciones

5. **Debug Console**: Ejecutar expresiones arbitrarias
   - Evaluar variables: `p variable`
   - Llamar funciones: `call mi_funcion(42)`
   - Usar comandos GDB directamente: `-exec info registers`

#### Debugging avanzado: Pretty Printers

GDB puede ser configurado para mostrar estructuras complejas de forma legible mediante *pretty printers*.

**Ejemplo: Pretty printer para lista enlazada**

Creá `.gdbinit` en el directorio de tu proyecto:

```python
# .gdbinit - Pretty printers personalizados

python
import gdb

class ListaPrinter:
    """Pretty printer para lista_t"""
    def __init__(self, val):
        self.val = val

    def to_string(self):
        largo = self.val['largo']
        return f"lista_t con {largo} elementos"

    def children(self):
        """Itera sobre los nodos de la lista"""
        nodo = self.val['primero']
        count = 0
        while nodo != 0:
            yield (f'[{count}]', nodo['dato'])
            nodo = nodo['siguiente']
            count += 1

def lookup_type(val):
    """Registra pretty printers"""
    if str(val.type) == 'lista_t *':
        return ListaPrinter(val.dereference())
    return None

gdb.pretty_printers.append(lookup_type)

end
```

Ahora al inspeccionar una `lista_t` en el debugger, verás los elementos expandidos automáticamente.

:::{note} Permisos de .gdbinit

Por seguridad, GDB puede requerir que permitas cargar `.gdbinit` locales:

```bash
# Agregar a ~/.gdbinit
add-auto-load-safe-path /home/usuario/mi-proyecto/.gdbinit

# O permitir todos (menos seguro)
set auto-load safe-path /
```
:::

#### Debugging con Valgrind integrado

Podés ejecutar Valgrind desde VS Code y parsear su salida:

**Task en `tasks.json`:**

```json
{
    "label": "Valgrind memcheck",
    "type": "shell",
    "command": "valgrind",
    "args": [
        "--leak-check=full",
        "--show-leak-kinds=all",
        "--track-origins=yes",
        "--verbose",
        "--log-file=valgrind-out.txt",
        "${workspaceFolder}/programa"
    ],
    "dependsOn": ["Compilar programa"],
    "group": "test",
    "presentation": {
        "reveal": "always"
    }
}
```

**Launch config para debugging con Valgrind:**

```json
{
    "name": "Debug con Valgrind",
    "type": "cppdbg",
    "request": "launch",
    "program": "/usr/bin/valgrind",
    "args": [
        "--leak-check=full",
        "--track-origins=yes",
        "${workspaceFolder}/programa"
    ],
    "stopAtEntry": false,
    "cwd": "${workspaceFolder}",
    "environment": [],
    "externalConsole": false,
    "MIMode": "gdb"
}
```

### Configuración completa de ejemplo

Aquí hay una estructura completa de `.vscode/` para un proyecto típico en C:

```bash
mi-proyecto/
├── .vscode/
│   ├── c_cpp_properties.json  # Configuración de IntelliSense
│   ├── launch.json            # Configuraciones de debugging
│   ├── settings.json          # Settings específicos del proyecto
│   └── tasks.json             # Tasks de compilación
├── src/
│   ├── main.c
│   ├── lista.c
│   └── lista.h
├── tests/
│   └── test_lista.c
├── Makefile
├── compile_commands.json
└── .gdbinit
```

**`.vscode/c_cpp_properties.json`** (solo si no usás clangd):

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

### Atajos de teclado útiles para C

Agregá estos keybindings personalizados en `File` → `Preferences` → `Keyboard Shortcuts` (JSON):

```json
[
    {
        "key": "ctrl+shift+b",
        "command": "workbench.action.tasks.build"
    },
    {
        "key": "ctrl+shift+t",
        "command": "workbench.action.tasks.test"
    },
    {
        "key": "f5",
        "command": "workbench.action.debug.start",
        "when": "debuggersAvailable && debugState == 'inactive'"
    },
    {
        "key": "ctrl+k ctrl+i",
        "command": "editor.action.showHover",
        "when": "editorTextFocus"
    }
]
```

:::{tip} Workflow recomendado

Un workflow eficiente para desarrollo en C con VS Code:

1. **Escribir código** con autocompletado de clangd
2. **Compilar** con `Ctrl+Shift+B`
3. **Ver errores** en panel "Problems" (`Ctrl+Shift+M`)
4. **Navegar a error** con `F8` (siguiente error)
5. **Ejecutar** con task o `Ctrl+F5` (sin debug)
6. **Debuggear** con `F5` si hay problema
7. **Verificar memoria** con task de Valgrind
8. **Commit** cuando todo funciona

Este ciclo iterativo, completamente dentro de VS Code, es mucho más rápido que cambiar entre editor, terminal, y debugger separados.
:::

### Problemas específicos de C/C++

#### clangd no funciona o da errores

```bash
# Verificar que clangd está instalado
which clangd
clangd --version

# Ver output de clangd en VS Code
# View → Output → seleccionar "clangd" en dropdown

# Verificar que compile_commands.json existe
ls -la compile_commands.json

# Regenerar compile_commands.json
bear -- make clean && bear -- make
```

**Error común**: "clangd: compile commands not found"

Solución: Asegurate de que `compile_commands.json` esté en la raíz del workspace.

#### GDB no inicia o crashea

```bash
# Verificar instalación de GDB
gdb --version

# Probar debuggear manualmente
gdb ./programa
(gdb) run
(gdb) quit

# Si falla, puede ser problema de permisos ptrace
# En Linux, permitir ptrace para debugging
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
```

#### Breakpoints no funcionan o se "saltan"

**Causas comunes:**

1. **Compilado sin `-g`**: Asegurate de que tu task/Makefile incluye `-g`
   ```bash
   gcc -g -Wall -Wextra -o programa main.c
   ```

2. **Optimización activada**: `-O2` o `-O3` pueden eliminar código
   ```bash
   # Para debug, usar -O0 (sin optimización)
   gcc -g -O0 -o programa main.c
   ```

3. **Código inline**: Funciones muy pequeñas pueden ser inlined
   - Solución: Usar `-fno-inline` durante debug

#### IntelliSense no muestra sugerencias

```bash
# Si usas clangd y C/C++ extension simultáneamente:
# Desactivar IntelliSense de C/C++ extension
# En settings.json:
{
    "C_Cpp.intelliSenseEngine": "disabled"
}

# Recargar window
Ctrl+Shift+P → "Developer: Reload Window"
```

#### Errores de "undefined reference" al compilar

Esto indica problema de linkeo, no del editor. Verificá:

```bash
# Asegurate de linkear todas las bibliotecas necesarias
# En tasks.json, args debe incluir todos los .c
"args": [
    "-o", "programa",
    "main.c",
    "lista.c",      // ← No olvidar implementaciones
    "utils.c",
    "-lm"           // ← Bibliotecas del sistema si son necesarias
]
```

#### Variables no se muestran en debugger

```bash
# Compilar sin optimizaciones
gcc -g -O0 -o programa main.c

# Algunas variables pueden ser optimizadas incluso con -O0
# Usar 'volatile' para forzar que se mantengan:
volatile int debug_var = 42;
```

## Resolución de problemas comunes

### VS Code no abre desde terminal

```bash
# En Linux, agregar al PATH si es necesario
echo 'export PATH="$PATH:/usr/share/code/bin"' >> ~/.bashrc
source ~/.bashrc

# Verificar instalación
which code
code --version
```

### Extensiones no cargan

```bash
# Reiniciar con extensiones deshabilitadas
code --disable-extensions

# Ver logs de extensiones
# Help → Toggle Developer Tools → Console
```

### Performance lenta

```bash
# Excluir archivos/carpetas grandes de búsqueda
# Configuración → Files: Exclude
# Agregar: **/node_modules, **/.git

# Desactivar extensiones innecesarias
# Extensions → Gear icon → Disable
```

### Problemas de formateo

```bash
# Verificar formateador por defecto
# Ctrl+Shift+P → "Format Document With..."
# Elegir Prettier o el apropiado

# Configurar formateador en settings.json
{
    "editor.defaultFormatter": "esbenp.prettier-vscode",
    "[python]": {
        "editor.defaultFormatter": "ms-python.black-formatter"
    }
}
```

## Recursos para seguir aprendiendo

### Documentación oficial

- [VS Code Documentation](https://code.visualstudio.com/docs) - documentación
  completa oficial
- [VS Code Tips and Tricks](https://code.visualstudio.com/docs/getstarted/tips-and-tricks) -
  consejos oficiales
- [Keyboard Shortcuts Reference](https://code.visualstudio.com/shortcuts/) - PDF
  con todos los atajos

### Extensiones recomendadas por área

#### Desarrollo web

- **Live Server**: Servidor local con hot reload
- **Auto Rename Tag**: Renombrado automático de tags HTML
- **CSS Peek**: Ver definiciones CSS desde HTML
- **Emmet**: Expansión rápida de HTML/CSS (viene integrado)

#### Python

- **Python**: Soporte oficial de Microsoft
- **Pylance**: Language server avanzado
- **Python Docstring Generator**: Generador automático de docstrings

#### Git y colaboración

- **GitLens**: Superpoderes para Git
- **Live Share**: Colaboración en tiempo real
- **Git Graph**: Visualización gráfica del historial

#### Productividad

- **TODO Highlight**: Resaltar comentarios TODO/FIXME
- **Bookmarks**: Marcadores en código
- **Path Intellisense**: Autocompletado de rutas de archivos

### Cursos y tutoriales

- **VS Code Can Do That?**: Serie de videos oficiales de Microsoft
- **Traversy Media**: Tutoriales de VS Code en YouTube
- **FreeCodeCamp**: Curso gratuito de VS Code

### Comunidad

- [VS Code subreddit](https://reddit.com/r/vscode)
- [GitHub Issues](https://github.com/microsoft/vscode/issues) - reportar bugs o
  solicitar features
- [VS Code Blog](https://code.visualstudio.com/blogs/) - novedades y updates

## Epílogo

VS Code es más que un editor: es una plataforma de desarrollo completa que crece
con vos. Empezás con funcionalidades básicas y gradualmente incorporás
extensiones y configuraciones que se adaptan a tu estilo de trabajo y
necesidades específicas.

:::{tip} Aprendizaje progresivo 

No trates de aprender todas las funcionalidades
de una vez. Empezá con lo básico (editar, guardar, terminal) y gradualmente
incorporá nuevas herramientas. Cada developer tiene su setup personalizado que
evolucionó con el tiempo. 

:::

La belleza de VS Code está en su balance perfecto entre simplicidad para
principiantes y potencia para expertos. Con la configuración básica que viste en
esta guía, ya tenés todo lo necesario para ser productivo. A medida que
desarrolles más proyectos, vas a descubrir nuevas extensiones y trucos que van a
hacer tu workflow aún más eficiente.

¡Felicitaciones! Ya tenés las herramientas para convertir VS Code en tu ambiente
de desarrollo ideal.

```bash
$ code --version
1.84.2
f1b07bd25dfad64b0167beb15359ae573aecd2cc
x64

$ echo "¡Listo para programar!"
¡Listo para programar!
```

---

