# Manual del Entorno de Desarrollo Portable

Este manual describe el funcionamiento, la arquitectura y las herramientas del entorno de desarrollo portable C/Python diseñado para Windows. El objetivo principal es brindarte un espacio de trabajo aislado y autocontenido que no dependa de variables globales de tu máquina host.

---

## 1. Arquitectura del Entorno

El entorno está diseñado bajo el principio de aislamiento absoluto. A continuación se presenta el diagrama de bloques que detalla cómo se organizan y comunican sus componentes:

```{image} images/arquitectura_entorno.svg
:alt: Arquitectura del Entorno Portable
:align: center
:width: 100%
```

### Componentes Físicos y Lógicos

*   **Lanzadores de Sesión (`launch.bat` / `launch.ps1`):** Son las puertas de entrada al entorno. Se encargan de calcular la ruta raíz dinámica (`PORTABLE_ROOT`), inyectar las variables de entorno locales de sesión, sanear el archivo de configuración de WezTerm y lanzar la consola o el editor de código.
*   **Directorio `bin/` (PATH Local):** Contiene herramientas y scripts de automatización propios del entorno portable. Esta carpeta se prepende al `PATH` de la sesión de manera que sus comandos tengan prioridad.
*   **Subsistema MSYS2 (`msys64/`):** Provee el userland de estilo Unix (Bash, pacman, git, ssh) en la carpeta `usr/bin` y el compilador Clang junto con las herramientas nativas de desarrollo en la carpeta `clang64/bin`.
*   **Editor de Código VS Code (`vscode/`):** Instalado en modo portable gracias al subdirectorio `vscode/data/`, que almacena las extensiones (como la extensión de C/C++ y Python) y la configuración de usuario sin alterar los directorios del host.
*   **HOME Aislado (`home/`):** Funciona como tu directorio personal local. Cualquier configuración de sesión, historial de comandos o claves SSH se guarda aquí.

---

## 2. Inicialización y Arranque

Para arrancar el entorno tenés dos cargadores principales en la raíz del directorio:

### Lanzar la Consola Portable (WezTerm)
*   **CMD:** Ejecutá `launch.bat`.
*   **PowerShell:** Ejecutá `.\launch.ps1`.

```{note}
Si por alguna razón WezTerm no se encuentra instalado o falla, los lanzadores caerán de forma automática a una sesión Bash interactiva en la consola nativa del sistema, asegurando que nunca te quedes sin terminal.
```

### Lanzar VS Code Portable
*   **CMD:** Ejecutá `launch-vscode.bat`.
*   **PowerShell:** Ejecutá `.\launch-vscode.ps1`.

VS Code heredará de forma directa todas las variables de entorno locales (compiladores, bibliotecas y herramientas de Git), por lo que vas a poder compilar y depurar directamente desde el editor sin configuraciones adicionales.

---

## 3. Herramientas Especiales de Automatización (`bin/`)

En la carpeta `bin/` tenés disponibles scripts de Bash agregados al `PATH` para simplificar la administración del entorno. Ejecutalos directamente desde tu terminal:

### Diagnóstico de Salud del Entorno
Si notás problemas con algún compilador o querés verificar el estado de las herramientas, ejecutá:
```bash
diagnose-env.sh
```
Este script genera un informe técnico detallado en `diagnose.log` con las versiones de Clang, CMake, Python, Git, Doxygen, los paquetes activos de pacman y el contenido físico de la carpeta `bin/`.

### Sincronización y Actualización de Paquetes
Para actualizar la base de datos de paquetes locales o instalar dependencias faltantes, ejecutá:
```bash
update-packages.sh
```
El script realiza un `pacman -Syu` de forma segura dentro del subsistema portable y consolida la instalación de herramientas clave.

### Configuración Aislada de Git y GitHub
Para registrar tu identidad de autor para commits de Git e iniciar sesión de forma segura y portable en GitHub CLI (`gh`), ejecutá:
```bash
configure-git.sh
```
Tus credenciales de autenticación se guardarán de forma local en tu `home/` portable y no afectarán a las credenciales globales del host.

### Instalador Automatizado de Librerías de C
Si necesitás compilar e instalar bibliotecas externas directamente desde repositorios de GitHub en tu prefijo portable de `/clang64`, utilizá:
```bash
install-lib.sh <usuario/repositorio_github> [rama_o_tag]
```
El script descargará, compilará y copiará las cabeceras e instalables de manera desatendida.
