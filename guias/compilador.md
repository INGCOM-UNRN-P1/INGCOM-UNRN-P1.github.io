---
title: Instalación del Compilador GCC
short_title: Instalación GCC
subtitle: Guía paso a paso para configurar MinGW-w64 y variables de entorno en Windows
---

# Instalación del Compilador en Windows

Esta es la guía de instalación _manual_ del entorno, no es la que recomendamos, ya que la construida para la cátedra tiene unas herramientas extras.

Para compilar programas en lenguaje C/C++ en tu entorno local de Windows, debés instalar el puerto de GCC (MinGW-w64) y configurar la variable de entorno `PATH` del sistema.

---

## 1. Descarga del compilador

Descargá la suite de compilación MinGW-w64 desde el repositorio oficial:

[Enlace de descarga de MinGW-w64 (WinLibs)](https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-18.1.8-12.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-14.2.0-llvm-18.1.8-mingw-w64ucrt-12.0.0-r1.zip)

---

## 2. Extracción de los archivos

1.  Ubicá el archivo ZIP descargado en tu Explorador de archivos.
2.  Hacé clic derecho sobre el archivo y seleccioná la opción **Extraer aquí** (o utilizá tu gestor de descompresión preferido).
3.  Este proceso generará un directorio llamado `mingw64`.

---

## 3. Reubicación del directorio

Debés mover la carpeta descomprimida directamente al directorio raíz de tu disco de sistema para evitar rutas con espacios en blanco o caracteres especiales que entorpezcan el proceso de compilación.

1.  Hacé clic derecho sobre la carpeta `mingw64` extraída.
2.  Seleccioná la opción **Mover a** (o cortar con Ctrl+X) y dirigite a **Disco Local (C:)**.
3.  Pegá el directorio allí, asegurándote de que la ruta final sea exactamente `C:\mingw64`.

```{figure} images/compilacion-1.png
:alt: Captura de pantalla de la ventana del explorador de Windows mostrando el menú contextual con la opción 'Mover a' seleccionada para trasladar la carpeta mingw64 hacia el Disco Local C.
:align: center
:width: 80%

Selección y movimiento de la carpeta del compilador.
```

```{figure} images/compilacion-2.png
:alt: Captura de pantalla del explorador de archivos mostrando la raíz del disco C con la carpeta mingw64 ubicada correctamente junto a las carpetas del sistema.
:align: center
:width: 80%

Ruta final de instalación del compilador en el Disco Local C.
```

:::{note}
Pasos de instalación optimizados por JeanFranco99.
:::

---

## 4. Configuración de la variable de entorno `PATH`

Para poder invocar a `gcc` desde cualquier terminal de comandos, debés asociar la carpeta de binarios del compilador a la variable del sistema `PATH`.

1.  Hacé clic derecho sobre **Este Equipo** en el Explorador de archivos de Windows y seleccioná **Propiedades** (o ingresá a la ventana de Configuración → Acerca de).

```{figure} images/compilacion-3.png
:alt: Captura de pantalla del menú contextual de 'Este Equipo' en el explorador de archivos, destacando la opción 'Propiedades' en la parte inferior.
:align: center
:width: 80%

Acceso a las propiedades del equipo.
```

```{figure} images/compilacion-4.png
:alt: Captura de pantalla del panel de información del sistema en la configuración de Windows, señalando el enlace a la Configuración Avanzada del Sistema en el panel lateral.
:align: center
:width: 80%

Panel de información del sistema.
```

2.  Hacé clic en el enlace **Configuración avanzada del sistema** ubicado en la sección lateral derecha.
3.  En la ventana emergente de *Propiedades del sistema*, seleccioná la pestaña *Opciones avanzadas* y hacé clic en el botón **Variables de entorno**.

```{figure} images/compilacion-5.png
:alt: Captura de pantalla de la ventana flotante 'Propiedades del sistema', enfocada en la pestaña 'Opciones avanzadas' y destacando con un recuadro el botón inferior 'Variables de entorno'.
:align: center
:width: 80%

Acceso a la ventana de Variables de entorno.
```

```{figure} images/compilacion-6.png
:alt: Captura de pantalla de la ventana 'Variables de entorno', dividida en Variables de usuario y Variables del sistema. Se destaca la variable del sistema llamada Path seleccionada.
:align: center
:width: 80%

Lista de variables del sistema en Windows.
```

4.  En la sección inferior de *Variables del sistema*, ubicá la variable **Path** y hacé clic en el botón **Editar**.
5.  Hacé clic en el botón **Nuevo** en el panel lateral derecho y agregá la siguiente ruta exacta:
    `C:\mingw64\bin`

```{figure} images/compilacion-7.png
:alt: Captura de pantalla del diálogo 'Editar variable de entorno'. Se observa una lista de rutas existentes y el botón 'Nuevo' destacado para ingresar la ruta del compilador.
:align: center
:width: 80%

Agregar nueva ruta de búsqueda al sistema.
```

6.  Presioná **Aceptar** en todas las ventanas abiertas para aplicar y guardar los cambios.

```{figure} images/compilacion-8.png
:alt: Captura de pantalla de la lista de rutas dentro de la variable Path, mostrando en la parte inferior la entrada C:\mingw64\bin añadida correctamente.
:align: center
:width: 80%

Variable de entorno PATH configurada con éxito.
```

---

## 5. Reinicio de sesión y comprobación

Cerrá tu sesión de usuario en Windows (o reiniciá el equipo) para que la nueva variable `PATH` se propague de manera correcta por todos los hilos del entorno del escritorio.

:::{note}
En sistemas Windows 11 modernos, por lo general no es necesario reiniciar el equipo ni cerrar la sesión para que los cambios surtan efecto en nuevas terminales.
:::

Para verificar que la suite se instaló correctamente, abrí una consola de comandos (presioná las teclas {kbd}`WIN` + {kbd}`R`, escribí `cmd` y presioná Enter) e introducí la siguiente instrucción:

```bash
gcc --version
```

El sistema debe responder imprimiendo la versión instalada de GCC (por ejemplo, `gcc (MinGW-w64...) 14.2.0`).

---

## 6. Configuración de Visual Studio Code

Para contar con un editor de código optimizado, descargá e instalá el software desde la página oficial:

[Sitio oficial de descarga de Visual Studio Code](https://code.visualstudio.com/)

Posteriormente, debés consultar la [Guía de VSCode](vscode.md) en este repositorio para instalar las extensiones del compilador de la cátedra.

