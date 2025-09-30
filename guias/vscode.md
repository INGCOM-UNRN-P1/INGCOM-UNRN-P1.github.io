---
title: Guía completa de Visual Studio Code
short_title: VSCode
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

:::{note} VS Code fue lanzado en 2015 y rápidamente se volvió el editor más
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

:::{exercise} :label: ejercicio-setup-vscode

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
4. Verificá que podés abrir VS Code desde terminal con `code .` :::

:::{solution} :for: ejercicio-setup-vscode

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

:::{exercise} :label: ejercicio-proyecto-web

**Ejercicio 2: Primer proyecto web con VS Code**

1. Creá un proyecto web simple con HTML, CSS y JavaScript
2. Usá Live Server para preview en tiempo real
3. Configurá Prettier para formateo automático
4. Inicializá Git y hacé commits de tu progreso
5. Agregá un snippet personalizado para estructura HTML :::

:::{solution} :for: ejercicio-proyecto-web

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

:::{tip} Aprendizaje progresivo No trates de aprender todas las funcionalidades
de una vez. Empezá con lo básico (editar, guardar, terminal) y gradualmente
incorporá nuevas herramientas. Cada developer tiene su setup personalizado que
evolucionó con el tiempo. :::

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

$ echo "¡Listo para programar como un profesional!"
¡Listo para programar como un profesional!
```

---

_"Un buen editor no es solo una herramienta, es una extensión de tu
pensamiento."_
