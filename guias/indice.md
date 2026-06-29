---
title: Índice de Guías
short_title: Índice
subtitle: Acceso al material y manuales de herramientas complementarias
---

# Índice de Material Complementario

En esta sección se listan las guías y manuales de referencia técnica desarrollados para acompañar el trayecto de la materia. Estos materiales cubren desde el uso básico de la consola y sistemas de control de versiones, hasta aspectos avanzados de compilación y optimización.

---

## 1. Vida de Consola y Control de Versiones

El dominio de la interfaz de línea de comandos y el control de versiones es un requisito esencial para el desarrollo profesional y la entrega automatizada.

*   **[Bash para principiantes](bash.md)**: Manual introductorio a la shell UNIX (Bash). Cubre comandos esenciales de navegación, manipulación de archivos, redirecciones (`>`, `<`), tuberías (`|`) y scripts básicos de automatización.
*   **[Git básico](git.md)**: Guía paso a paso para el control de versiones distribuido. Explica el flujo de trabajo estándar (`add`, `commit`, `push`, `pull`), la gestión de ramas y la resolución de conflictos.
*   **[Git avanzado](git_avanzado.md)**: Técnicas avanzadas para el saneamiento de repositorios, reescritura de historial (`rebase`, `cherry-pick`, `amend`) y estrategias complejas de ramificación.
*   **[Uso de GitHub](github.md)**: Flujos de trabajo específicos de la cátedra para la entrega de proyectos usando Pull Requests, autenticación remota mediante claves SSH o PAT, y canales de consulta (Discussions e Issues).

---

## 2. Compilación y Entorno de Desarrollo

Comprender las etapas de traducción de código fuente a lenguaje de máquina es clave para optimizar y depurar programas en C.

*   **[Entorno de desarrollo](entorno.md)**: Configuración inicial del entorno de desarrollo modular en sistemas Windows, Linux y macOS.
*   **[Instalación del compilador](compilador.md)**: Guía detallada de instalación manual de GCC/MinGW-w64 en Windows y su vinculación con las variables de entorno del sistema.
*   **[Compilador GCC](gcc.md)**: Manual profundo sobre la suite de compilación de GNU. Detalla banderas de compilación (`-Wall`, `-Wextra`, `-Wpedantic`), optimizaciones, modularidad y depuración.
*   **[Compilador Clang/LLVM](clang.md)**: Guía completa de Clang y LLVM. Explica la arquitectura modular en tres fases, uso básico, optimización, herramientas integradas (`clang-format`, `clang-tidy`, `clangd`), depuración con `lldb` e integración con CMake y Ninja en el entorno CLANG64.

---

## 3. Documentación y Productividad

Herramientas para formalizar la especificación de interfaces de software y optimizar el flujo diario de trabajo.

*   **[Doxygen (documentación)](doxygen.md)**: Guía de uso y configuración de Doxygen. Explica cómo estructurar comentarios con notación `@` para generar documentación técnica en HTML y automatizar su despliegue mediante GitHub Actions.
*   **[Markdown](markdown.md)**: Sintaxis básica y avanzada de Markdown para la redacción de informes técnicos y el archivo `README.md` de tus proyectos.
*   **[VSCode](vscode.md)**: Configuración recomendada de extensiones, formateadores y herramientas de depuración integrada para Visual Studio Code.
*   **[Herramientas generales](herramientas.md)**: Breve catálogo de utilidades auxiliares en sistemas POSIX.

---

## 4. Reflexión Crítica y Tecnologías Emergentes

Material de análisis sobre el rol y el impacto de los asistentes de inteligencia artificial en la formación académica.

*   **[Crítica IA](critica_ia.md)**: Ensayo y lineamientos éticos sobre los límites de los modelos de lenguaje en el diseño de algoritmos.
*   **[IA aprendizaje](ia_aprendizaje.md)**: Buenas prácticas para el uso responsable de asistentes cognitivos como herramientas de andamiaje pedagógico, evitando la delegación ciega de código.