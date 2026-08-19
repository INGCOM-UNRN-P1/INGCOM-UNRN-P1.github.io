---
title: Documentación con Doxygen
short_title: Guía Doxygen
subtitle: Generación de documentación automática para C, C++ y Java en la cátedra
---

# Documentación con Doxygen

La documentación es una parte fundamental de la ingeniería de software. En el
ámbito académico, documentar el código no solo facilita la legibilidad, sino que
también promueve el rigor conceptual al obligar a formalizar las precondiciones,
postcondiciones e invariantes del diseño de software.

En la cátedra se utiliza **Doxygen** para compilar la documentación técnica de
las interfaces públicas directamente desde los comentarios del código fuente.
Esta guía detalla la configuración y las buenas prácticas para estructurar el
código de tus entregas.

---

## 1. Instalación de Doxygen y dependencias

Para generar la documentación localmente, debés contar con el motor de Doxygen y
opcionalmente con **Graphviz** para renderizar los diagramas de dependencias y
llamadas (árboles de ejecución).

```{code-block} bash
:linenos:
# En distribuciones basadas en Debian/Ubuntu (como Ubuntu WSL)
sudo apt-get update
sudo apt-get install -y doxygen graphviz

# En Arch Linux
sudo pacman -S doxygen graphviz

# En macOS (utilizando Homebrew)
brew install doxygen graphviz

```
<!-- {code-block} bash -->

:::{note}

Si bien no es obligatorio generar los gráficos localmente para pasar los tests
de la cátedra, sí se recomienda tener Graphviz instalado para verificar la
estructura modular de las dependencias antes de realizar la entrega.

:::
<!-- {note} -->

---

## 2. Configuración mediante el `Doxyfile`

El archivo de configuración principal de Doxygen se llama `Doxyfile`. Este
archivo contiene directivas clave que le indican al motor qué archivos procesar,
qué formatos generar (HTML, LaTeX, etc.) y cómo estructurar la salida.

### Creación del archivo de configuración inicial

Para generar un archivo con las opciones por defecto en la raíz de tu proyecto,
ejecutá:

``` bash
doxygen -g Doxyfile
```
<!-- bash -->

### Configuración recomendada para la cátedra

Debés modificar el `Doxyfile` generado para ajustarlo a las directrices de la
cátedra. A continuación se detallan las opciones principales:

| Parámetro | Valor recomendado | Propósito |
| :--- | :---: | :--- |
| `PROJECT_NAME` | `"Tu Proyecto"` | Nombre que se mostrará en el encabezado de las páginas HTML. |
| `OUTPUT_DIRECTORY` | `docs` | Carpeta de salida para todos los archivos generados. |
| `GENERATE_HTML` | `YES` | Genera documentación en formato web interactivo. |
| `GENERATE_LATEX` | `NO` | Desactiva LaTeX, salvo que la entrega lo solicite explícitamente. |
| `INPUT` | `src include` | Lista de directorios que contienen código fuente y cabeceras. |
| `FILE_PATTERNS` | `*.c *.h *.java` | Extensiones de archivo que Doxygen debe analizar. |
| `RECURSIVE` | `YES` | Indica que debe buscar recursivamente dentro de subdirectorios. |
| `EXTRACT_ALL` | `YES` | Asegura que se procesen incluso las funciones sin documentación explícita. |
| `GENERATE_TREEVIEW` | `YES` | Añade un panel de navegación lateral en la documentación web. |
| `HAVE_DOT` | `YES` | Activa la generación de gráficos de herencia y dependencias (requiere Graphviz). |
| `CALL_GRAPH` | `YES` | Genera diagramas detallados de los flujos de llamadas de funciones. |
| `CALLER_GRAPH` | `YES` | Genera diagramas que muestran quién invoca a cada función. |

Para asegurar la uniformidad en las entregas, podés anexar el siguiente bloque
institucional de configuración al final de tu `Doxyfile`:

```{code-block} ini
:linenos:
# --- Configuración institucional UNRN ---
OUTPUT_LANGUAGE = Spanish
OPTIMIZE_OUTPUT_FOR_C = YES
GENERATE_TREEVIEW = YES
FULL_PATH_NAMES = NO
STRIP_FROM_PATH = include/ src/
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
EXTRACT_LOCAL_CLASSES = YES
EXTRACT_LOCAL_METHODS = YES
WARN_IF_UNDOCUMENTED = YES
USE_MDFILE_AS_MAINPAGE = README.md

```
<!-- {code-block} ini -->

:::{important}

La directiva `USE_MDFILE_AS_MAINPAGE = README.md` permite que la página de
bienvenida de la documentación HTML generada coincida exactamente con la portada
de tu proyecto. Asegurate de mantener tu archivo `README.md` actualizado y bien
estructurado.

:::
<!-- {important} -->

---

## 3. Comentarios del código con notación `@`

En la cátedra se prefiere el uso de la notación `@` en lugar del símbolo `\`
para definir los tags de Doxygen. Los bloques de documentación deben empezar
siempre con la firma `/**` (en C/Java) o `///`.

### Tags esenciales para funciones y métodos

| Tag | Argumento | Propósito |
| :--- | :--- | :--- |
| `@brief` | Descripción resumida | Explicación en una línea de la función o módulo. |
| `@param` | `nombre` descripción | Documenta el propósito de un parámetro de entrada. |
| `@return` | descripción | Detalla el valor de retorno y sus condiciones (ej: `NULL` si falla). |
| `@note` | texto aclaratorio | Información adicional importante para el usuario de la API. |
| `@warning` | advertencia | Restricciones críticas de uso o potenciales comportamientos indefinidos. |
| `@see` | referencia | Enlace a otras funciones o tipos relacionados. |
| `@throws` / `@exception` | `TipoException` descripción | (Solo Java/C++) Documenta excepciones lanzadas. |

---

## 4. Ejemplos de uso práctico

### Ejemplo 1: Archivo de cabecera en C (`punto.h`)

En C, la documentación de la API pública debe realizarse en el archivo de
cabecera `.h` y no en la implementación `.c`. Esto permite que el usuario del
módulo comprenda la interfaz sin necesidad de inspeccionar el código de bajo
nivel.

:::{tip}

Recordá que, de acuerdo con las buenas prácticas de la cátedra, todos tus
archivos de cabecera deben implementar guardas de inclusión para evitar
redefiniciones de tipos, tal como se especifica en la regla {ref}`0x5003h`.

:::
<!-- {tip} -->

```{code-block} c
:linenos:
/**
 * @file punto.h
 * @brief Definición del Tipo de Dato Abstracto (TDA) Punto.
 * @author Cátedra de Programación I
 * @date 2026
 */
#ifndef PUNTO_H
#define PUNTO_H
/**
 * @struct punto_t
 * @brief Representa una coordenada bidimensional en un plano cartesiano.
 */
typedef struct
{
    double x; /**< Coordenada en el eje de las abscisas (horizontal). */
    double y; /**< Coordenada en el eje de las ordenadas (vertical). */
} punto_t;
/**
 * @brief Crea un nuevo punto a partir de sus coordenadas cartesianas.
 *
 * @param x Coordenada en el eje horizontal.
 * @param y Coordenada en el eje vertical.
 * @return punto_t El punto inicializado.
 *
 * @note Este método no realiza asignaciones de memoria dinámica en la pila
 *       de llamadas principal del sistema.
 */
punto_t punto_crear(double x, double y);
/**
 * @brief Calcula la distancia euclidiana entre dos puntos.
 *
 * La fórmula implementada es:
 * \f[
 * d = \sqrt{(p_1.x - p_2.x)^2 + (p_1.y - p_2.y)^2}
 * \f]
 *
 * @param p1 Primer punto de referencia.
 * @param p2 Segundo punto de referencia.
 * @return double La distancia entre ambos puntos expresada en unidades
 * lineales.
 * @warning Si se pasan puntos con coordenadas no inicializadas, el
 * comportamiento es indefinido.
 */
double punto_distancia(punto_t p1, punto_t p2);
#endif // PUNTO_H
```
<!-- {code-block} c -->

### Ejemplo 2: Clase estructurada en Java (`Pila.java`)

En Java, se documentan tanto las clases como sus campos e interfaces públicas
mediante comentarios de Javadoc estructurados compatibles con Doxygen.

```{code-block} java
:linenos:
package ar.edu.unrn.p1.tad;

import java.util.EmptyStackException;

/**
 * Representa una estructura de datos lineal de tipo LIFO (Last In, First Out).
 * Esta implementación no admite elementos nulos.
 *
 * @author Cátedra de Programación I
 * @version 1.1
 * @param <T> Tipo genérico de los elementos almacenados en la pila.
 */
public class Pila<T> {

    private java.util.List<T> elementos;

    /**
     * Constructor por defecto. Inicializa la pila vacía sin elementos preasignados.
     */
    public Pila() {
        this.elementos = new java.util.ArrayList<>();
    }

    /**
     * Inserta un nuevo elemento en el tope de la pila.
     *
     * @param elemento Objeto a apilar.
     * @throws IllegalArgumentException si el elemento provisto es nulo.
     */
    public void apilar(T elemento) {
        if (elemento == null) {
            throw new IllegalArgumentException("No se pueden apilar valores nulos");
        }
        this.elementos.add(elemento);
    }

    /**
     * Desapila y retorna el elemento ubicado en el tope de la pila.
     *
     * @return El elemento desapilado.
     * @throws EmptyStackException si se intenta desapilar de una pila que no contiene elementos.
     */
    public T desapilar() {
        if (this.estaVacia()) {
            throw new EmptyStackException();
        }
        return this.elementos.remove(this.elementos.size() - 1);
    }

    /**
     * Verifica el estado de ocupación de la pila.
     *
     * @return true si la pila no posee elementos, false en caso contrario.
     */
    public boolean estaVacia() {
        return this.elementos.isEmpty();
    }
}

```
<!-- {code-block} java -->

---

## 5. Compilación local de la documentación

Una vez configurado el `Doxyfile` y documentados los archivos del proyecto, se
puede compilar la documentación localmente utilizando la terminal.

1.  Ubicarse en el directorio raíz de la entrega (donde reside el `Doxyfile`).
2.  Ejecutar el comando de compilación:

``` bash
doxygen Doxyfile
```
<!-- bash -->

Este proceso analizará el código fuente y creará la carpeta `docs/` con las
subcarpetas `html/` (y `latex/` si estuviese habilitada). Para visualizar la
página principal interactiva, se debe abrir en el navegador web el archivo:

`docs/html/index.html`

:::{figure} images/doxygen_html_output.png
:alt: Captura de pantalla de la interfaz web generada por Doxygen. Se observa el panel lateral izquierdo con el árbol jerárquico de archivos y miembros, y el panel principal detallando la documentación de la estructura punto_t y la función punto_distancia con su respectivo diagrama de flujo de llamadas de Graphviz.
:align: center
:width: 90%

Previsualización de la documentación HTML generada y su estructura de
navegación.

:::
<!-- {figure} images/doxygen_html_output.png -->

---

## 6. Automatización y despliegue (GitHub Actions)

Es altamente recomendable configurar un proceso de integración continua (CI)
para compilar y publicar la documentación automáticamente en **GitHub Pages**
tras cada cambio en el repositorio.

Creá el archivo `.github/workflows/doxygen.yml` con el siguiente contenido:

```{code-block} yaml
:linenos:
name: Compilación automática de documentación

on:
  push:
    branches:
      - main
    paths:
      - '**.c'
      - '**.cpp'
      - '**.h'
      - '**.hpp'
      - '**.java'
      - 'Doxyfile'
      - 'README.md'

permissions:
  contents: write

jobs:
  build-docs:
    runs-on: ubuntu-latest

    steps:
      - name: Clonar el repositorio
        uses: actions/checkout@v4

      - name: Instalar Doxygen y Graphviz
        run: |
          sudo apt-get update
          sudo apt-get install -y doxygen graphviz

      - name: Generar documentación técnica
        run: doxygen Doxyfile

      - name: Desplegar en GitHub Pages
        uses: peaceiris/actions-gh-pages@v4
        with:
          github_token: ${{ secrets.GITHUB_TOKEN }}
          publish_dir: docs/html

```
<!-- {code-block} yaml -->

---

## 7. Diagnóstico y resolución de advertencias comunes

Doxygen emitirá advertencias en la terminal si encuentra incoherencias. Mantener
la compilación libre de warnings es un requisito para la entrega de proyectos:

*   **`warning: Member xxx (variable) of class yyy is not documented`**
    *   *Causa:* Tenés habilitado `WARN_IF_UNDOCUMENTED = YES` y hay un miembro
        público o privado sin su bloque correspondiente de documentación.
    *   *Solución:* Añadir un bloque breve con `@brief` o un comentario de línea
        tipo `/**< descripción */`.
*   **`warning: parameter 'x' of member yyy is not found in the argument list of
    ...`**
    *   *Causa:* El tag `@param` documenta un parámetro con un nombre que no
        coincide con el prototipo de la función (suele pasar tras
        refactorizaciones de código).
    *   *Solución:* Corregir la firma del tag `@param` para que coincida
        exactamente con la variable del parámetro en la firma de la función.
*   **`warning: return type of member xxx is not documented`**
    *   *Causa:* La función retorna un tipo que no es `void` pero omitiste el
        tag `@return`.
    *   *Solución:* Incorporar el bloque `@return` describiendo el valor
        retornado.
*   **`warning: Could not open file xxx`**
    *   *Causa:* La directiva `INPUT` en el `Doxyfile` apunta a carpetas o
        archivos inexistentes.
    *   *Solución:* Ajustar las rutas en `INPUT` para que coincidan con la
        jerarquía real de directorios del proyecto.
