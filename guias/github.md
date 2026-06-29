---
title: Uso de GitHub en la Cátedra
short_title: Guía GitHub
subtitle: Flujos de trabajo, Pull Requests y herramientas de colaboración en la UNRN
---

# Uso de GitHub en la Cátedra

Esta guía detalla cómo se utiliza la plataforma GitHub como entorno de entrega, corrección y discusión en la materia. Se asume que comprendés los conceptos explicados en la guía de [Git básico](git.md).

---

## 1. Creación y configuración de la cuenta

Para las actividades de la materia, debés contar con una cuenta activa en [GitHub](https://github.com/). 

:::{tip}
Registrate utilizando tu correo electrónico institucional de la UNRN. Esto te facilitará el acceso a los beneficios académicos de la plataforma, como el *GitHub Student Developer Pack*, que incluye herramientas de desarrollo gratuitas.
:::

---

## 2. Autenticación y clonación de repositorios

Para interactuar de forma segura con los servidores de GitHub desde tu terminal local sin ingresar tus credenciales en cada operación, debés configurar un método de autenticación.

### Opción A: Autenticación por SSH (Recomendada)

Consiste en generar un par de claves criptográficas en tu computadora local y asociar la clave pública a tu cuenta de GitHub.

1.  **Generar la clave SSH** en tu terminal:
    ```bash
    ssh-keygen -t ed25519 -C "tu_email@unrn.edu.ar"
    ```
    *(Presioná Enter en todas las solicitudes para usar la ruta por defecto y omitir la contraseña de la clave, si así lo preferís).*

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
    *   Ingresá a GitHub ⇾ Perfil (esquina superior derecha) ⇾ **Settings** ⇾ **SSH and GPG keys**.
    *   Hacé clic en **New SSH key**, asignale un título (ej: "Notebook Cátedra") y pegá la clave pública en el campo correspondiente.

```{figure} images/github_ssh_key_settings.png
:alt: Captura de pantalla de la interfaz de configuración de claves SSH en GitHub. Se destaca el botón verde 'New SSH Key' en la parte superior derecha, y el formulario con los campos 'Title' (donde se ingresa el nombre de la máquina) y 'Key' (el área de texto grande donde se debe pegar el contenido de la clave pública id_ed25519.pub).
:align: center
:width: 85%

Página de configuración de claves SSH en GitHub.
```

5.  **Clonar el repositorio**:
    Una vez configurada la clave, cloná tus proyectos utilizando la dirección SSH:
    ```bash
    git clone git@github.com:INGCOM-UNRN-P1/tu-repositorio.git
    ```

### Opción B: Token de Acceso Personal (PAT)

Si preferís usar HTTPS en lugar de SSH, GitHub requiere un Token de Acceso Personal (PAT) como contraseña de autenticación.

*   Generalo en: **Settings** ⇾ **Developer settings** ⇾ **Personal access tokens** ⇾ **Tokens (classic)**.
*   Seleccioná los permisos mínimos de `repo` y guardá el token en un lugar seguro. Deberás introducirlo en lugar de tu contraseña tradicional al realizar operaciones de subida (`git push`).

---

## 3. El flujo de trabajo con Pull Requests (PR)

En la cátedra, cada entrega o corrección de trabajos prácticos se gestiona mediante un **Pull Request** (Petición de Integración). Un PR es una propuesta de cambios que permite comparar tu código de entrega contra la rama principal de control.

### Proceso de envío de una entrega

1.  **Crear una rama local** para la tarea actual, partiendo siempre desde `main` actualizada:
    ```bash
    git checkout main
    git pull origin main
    git checkout -b entrega-tp1
    ```
2.  **Realizar los cambios** en el código fuente, documentar las interfaces con Doxygen (ver la [Guía de Doxygen](doxygen.md)) y verificar que el proyecto compile sin advertencias.
3.  **Subir la rama** al servidor remoto:
    ```bash
    git commit -am "Finaliza la resolución del TP1"
    git push origin entrega-tp1
    ```
4.  **Abrir el Pull Request**:
    *   Ingresá al repositorio del proyecto en la web de GitHub.
    *   Visualizarás un banner indicando que se subió una rama nueva. Hacé clic en **Compare & pull request**.
    *   Completá el título del PR con tu nombre y el número de TP.
    *   Creá el PR apuntando tu rama de entrega (`entrega-tp1`) hacia la rama principal (`main`).

```{figure} images/github_compare_pull_request.png
:alt: Captura de pantalla de la página principal del repositorio en GitHub tras subir una nueva rama. Se observa un banner horizontal destacado de color amarillo claro con el mensaje 'entrega-tp1 had recent pushes less than a minute ago' y un botón verde en la derecha rotulado 'Compare & pull request'.
:align: center
:width: 85%

Banner de aviso para iniciar un nuevo Pull Request.
```

---

## 4. Revisión y respuesta a comentarios

Una vez abierto el Pull Request, los docentes de la cátedra revisarán el código. Las correcciones se realizan directamente sobre las líneas de código afectadas en el PR.

### Interacción durante la revisión

*   **Comentarios de línea**: Si recibís observaciones sobre alguna línea en particular, se abrirá un hilo de discusión en la pestaña *Conversation* o *Files changed* del PR.
*   **Corrección y actualización**: Para corregir lo solicitado, no es necesario abrir un nuevo PR. Simplemente debés realizar los cambios correspondientes en tu rama local, hacer el commit y subirlo:
    ```bash
    # Luego de corregir el error detectado en el editor:
    git commit -am "Corrige la validación de límites en la estructura"
    git push origin entrega-tp1
    ```
    El Pull Request se actualizará automáticamente con tus nuevos commits.
*   **Responder y resolver**: Una vez implementada la corrección, respondé al comentario del docente en GitHub y marcá la conversación como **Resolve conversation** si corresponde.

```{figure} images/github_pr_comments.png
:alt: Captura de pantalla de un comentario de revisión dentro de un Pull Request. Se observa un bloque de código en C con una anotación superpuesta de un docente sugiriendo una mejora, un campo de texto para escribir una respuesta en la parte inferior, y el botón 'Resolve conversation' habilitado en la esquina derecha del hilo.
:align: center
:width: 85%

Hilo de discusión y revisión de código sobre una línea específica en un Pull Request.
```

---

## 5. Consultas con GitHub Discussions

Para canalizar las dudas teóricas y metodológicas de la cursada, la cátedra utiliza la pestaña **Discussions** del repositorio institucional en lugar del correo electrónico.

*   **Antes de preguntar**: Usá la barra de búsqueda para verificar si otro compañero ya realizó la misma consulta y si ya fue resuelta.
*   **Estructura de la consulta**:
    *   Seleccioná la categoría correspondiente (ej: Q&A, TPs, Teoría).
    *   Proporcioná títulos descriptivos. Evitá títulos genéricos como *"Ayuda con el TP"*. Preferí *"Error de segmentación al liberar memoria dinámica en TP2"*.
    *   Adjuntá bloques de código legibles usando la sintaxis de código Markdown.

---

## 6. Reporte de fallas mediante GitHub Issues

Los **Issues** se reservan exclusivamente para reportar fallas de infraestructura del entorno, errores ortográficos o conceptuales detectados en las guías y apuntes, o problemas con las pruebas unitarias provistas por la cátedra.

:::{important}
No uses los *Issues* para realizar preguntas sobre cómo resolver un ejercicio práctico. Para ello debés recurrir a *Discussions*.
:::

Para reportar un error del apunte:
1.  Ingresá a la sección **Issues** del repositorio del apunte.
2.  Hacé clic en **New issue**.
3.  Describí la falla indicando el archivo afectado y sugiriendo la corrección correspondiente.

---

## 7. Temas conexos

### Integración Continua (CI)

Cada vez que abrís un Pull Request o realizás un `push` a una rama de entrega, se disparan flujos automáticos de comprobación (GitHub Actions). Estos procesos se encargan de compilar tu proyecto bajo la suite de compiladores de la cátedra y correr los tests automáticos.

*   Si el flujo termina de forma correcta, verás un tilde verde (✔).
*   Si falla, verás una cruz roja (❌). Hacé clic en los detalles del fallo para verificar qué tests no se superaron o qué error de compilación ocurrió en el servidor remoto.

```{figure} images/github_actions_status.png
:alt: Captura de pantalla del estado de las comprobaciones automáticas de GitHub Actions al final de la página de un Pull Request. Se observa una cruz roja junto al nombre del workflow 'Compilación y Tests' indicando que una comprobación ha fallado, acompañado del enlace 'Details' para acceder al log detallado del compilador.
:align: center
:width: 85%

Visualización del estado de los tests automatizados de integración continua en el Pull Request.
```