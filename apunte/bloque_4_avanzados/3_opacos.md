---
title: Punteros Opacos y Encapsulamiento en C
short_title: 'Encapsulamiento'
subtitle: Técnicas de ocultamiento de información y diseño modular
---

(capitulo-tipos-opacos)=
# Referencias y Lecturas Complementarias

> **Prerrequisitos**: structs, punteros, archivos `.h`/`.c`, TAD y compilación
> modular. Antes de seguir, distinguí una declaración incompleta de la
> definición de una estructura.
>
> **Objetivo**: publicar una interfaz que oculte la representación y conserve
> la responsabilidad de creación y destrucción dentro del módulo.
>
> **Comprobación de salida**: separá qué declaraciones pertenecen al `.h` público y cuáles deben quedar en el `.c` privado.

## Introducción



## Desarrollo

(concepto-y-mecanismo-de-punteros-opacos)=
### Concepto y Mecanismo de Punteros Opacos


Los **punteros opacos** (opaque pointers) son una técnica fundamental en C para
implementar **encapsulamiento** y **ocultamiento de información** (information
hiding). Esta técnica permite ocultar la implementación interna de una
estructura, exponiendo solo una interfaz pública al usuario, de manera análoga
al encapsulamiento de miembros privados de una clase en lenguajes orientados a
objetos.

El concepto de puntero opaco es esencial para construir **APIs robustas** y
**bibliotecas mantenibles**, donde los detalles de implementación pueden cambiar
sin romper el código cliente que las utiliza.

:::{important} Conexión con TADs

Los punteros opacos son la técnica de programación central sobre la cual se
construyen los Tipos de Datos Abstractos (TADs) en C, concepto que se aborda en
detalle en el capítulo de [Tipos Abstractos de Datos](../bloque_3_algoritmos_estructuras/2_tad.md).

:::
<!-- {important} Conexión con TADs -->

---

(motivacion-el-problema-del-acceso-directo)=
#### Motivación: El Problema del Acceso Directo

Considerá una implementación ingenua de un punto geométrico en dos dimensiones
donde la estructura está completamente expuesta:

:::{code-block} c
:linenos:
// punto_malo.h - NO USAR: Implementación expuesta
typedef struct
{
    double x;
    double y;
} punto_t;
// Funciones públicas
punto_t *crear_punto(double x, double y);
void desplazar_punto(punto_t *p, double dx, double dy);

:::
<!-- {code-block} c -->

#### Problemas de Esta Aproximación

**1. Violación del encapsulamiento:**
``` c
punto_t *p = crear_punto(3.0, 4.0);
// El usuario puede acceder y modificar directamente los campos internos
p->x = -9999.0; // Modificación directa sin control
```
<!-- c -->

**2. Imposibilidad de cambiar la implementación:**
Si decidís cambiar la representación interna de coordenadas cartesianas ($x, y$)
a coordenadas polares ($radio, angulo$) para optimizar operaciones de rotación,
**todo el código cliente se rompe** porque depende de los campos `x` e `y`
específicos de la estructura.

**3. Falta de control sobre invariantes:**
No podés validar ni interceptar los cambios en los datos. Si la estructura
requiriera que el punto se mantenga dentro de ciertos límites (por ejemplo, un
plano acotado de una pantalla), no hay forma de evitar que el usuario asigne
coordenadas fuera de rango directamente.

:::{danger} Anti-patrón

Exponer la definición completa de una estructura en el archivo de cabecera es un
**anti-patrón** que destruye la abstracción y crea dependencias frágiles.

:::
<!-- {danger} Anti-patrón -->

---

(la-solucion-punteros-opacos)=
#### La Solución: Punteros Opacos

La técnica de punteros opacos consiste en **declarar la estructura en el archivo
de cabecera pero definirla en el archivo de implementación**.

:::{tip} Directivas de Estilo para TADs (regla {ref}`0x301Dh`)

Las directivas de diseño de la cátedra establecen que todos los Tipos de Datos
Abstractos deben diseñarse utilizando punteros opacos. La interfaz expuesta en
el archivo `.h` debe ser lo más limpia posible, documentando de manera
exhaustiva sus precondiciones, poscondiciones y el comportamiento ante casos de
error mediante comentarios estructurados (regla {ref}`0x301Dh`).

:::
<!-- {tip} Directivas de Estilo para TADs (regla {ref}`0x301Dh`) -->

#### Estructura del Patrón

**Archivo de Cabecera (`.h`) - Interfaz Pública**

:::{code-block} c
:linenos:
// punto.h - Interfaz pública
#ifndef PUNTO_H
#define PUNTO_H
// Declaración OPACA: el usuario solo ve que existe una estructura
typedef struct punto punto_t;
// Funciones públicas - la interfaz
punto_t *crear_punto(double x, double y);
void destruir_punto(punto_t **punto);
double punto_obtener_x(const punto_t *punto);
double punto_obtener_y(const punto_t *punto);
void punto_desplazar(punto_t *punto, double dx, double dy);
#endif // PUNTO_H

:::
<!-- {code-block} c -->

**Archivo de Implementación (`.c`) - Detalles Privados**

:::{code-block} c
:linenos:
// punto.c - Implementación privada
#include "punto.h"
#include <stdlib.h>
// Definición COMPLETA de la estructura - solo visible aquí
struct punto
{
    double x;
    double y;
};
punto_t *crear_punto(double x, double y)
{
    punto_t *p = malloc(sizeof(*p));
    if (p == NULL)
    {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}
void destruir_punto(punto_t **punto)
{
    if (punto != NULL && *punto != NULL)
    {
        free(*punto);
        *punto = NULL;
    }
}
double punto_obtener_x(const punto_t *punto)
{
    if (punto == NULL)
    {
        return 0.0;
    }
    return punto->x;
}
double punto_obtener_y(const punto_t *punto)
{
    if (punto == NULL)
    {
        return 0.0;
    }
    return punto->y;
}
void punto_desplazar(punto_t *punto, double dx, double dy)
{
    if (punto == NULL)
    {
        return;
    }
    punto->x += dx;
    punto->y += dy;
}

:::
<!-- {code-block} c -->

**Código Cliente**

:::{code-block} c
:linenos:
// main.c - Usuario de la interfaz
#include "punto.h"
#include <stdio.h>
int main(void)
{
    punto_t *p = crear_punto(3.0, 4.0);
    if (p == NULL)
    {
        fprintf(stderr, "Error al crear el punto\n");
        return 1;
    }
    // El usuario SOLO puede usar la interfaz pública
    punto_desplazar(p, 1.5, -2.0);
    printf("Punto: (%.1f, %.1f)\n", punto_obtener_x(p), punto_obtener_y(p));
    // Esto NO COMPILA: el usuario no puede acceder a los campos internos
    // p->x = 10.0;  // ERROR: incomplete type 'struct punto'
    destruir_punto(&p);
    return 0;
}

:::
<!-- {code-block} c -->

:::{warning} Gestión de Recursos y Robustez (regla {ref}`0x7001h` y {ref}`0x301Eh`)

Dado que las instancias de tipos opacos se alocan dinámicamente en el heap, es
mandatorio que el constructor inicialice todos sus campos a valores seguros o
`NULL` (regla {ref}`0x7001h`). Asimismo, al destruir la estructura mediante su
función liberadora, debe asignarse `NULL` al puntero en el ámbito del cliente
para evitar el uso accidental de punteros colgantes (regla {ref}`0x301Eh`).

:::
<!-- {warning} Gestión de Recursos y Robustez (regla {ref}`0x7001h` y {ref}`0x301Eh`) -->

(patron-destruccion-seguro)=
##### Patrón de Destrucción Seguro: Puntero Simple vs. Doble Puntero

En el diseño de destructores para tipos opacos y TADs en C, existen dos
aproximaciones clásicas:

1. **Destructor Simple (Puntero Simple):**
   ```c
   void destruir_punto(punto_t *p)
   {
       if (p == NULL)
           return;
       free(p);
   }
   ```
   *Funcionamiento:* Se libera la memoria en el Heap, pero la variable puntero
   en el ámbito del cliente (el llamador) continúa almacenando la dirección de
   memoria liberada. Esto genera un **puntero colgante** (*dangling pointer*).
   Es responsabilidad exclusiva del programador cliente asignar de forma manual
   `p = NULL;` inmediatamente después de la llamada. Si el cliente olvida este
   paso, cualquier desreferencia posterior resultará en comportamiento
   indefinido o fallas de seguridad de tipo *Use-After-Free* (UAF).

2. **Destructor Seguro (Doble Puntero - Recomendado y Unificado):**
   ```c
   void destruir_punto(punto_t **p)
   {
       if (p == NULL || *p == NULL)
           return;
       free(*p);
       *p = NULL; // Aniquilación automática del puntero del cliente
   }
   ```
   *Funcionamiento:* Al pasar la dirección del puntero del cliente (`&p`), el
   destructor no solo libera la memoria en el Heap, sino que también **pone a
   `NULL` la variable del cliente en su propio ámbito**. Esto mitiga por
   completo el riesgo de punteros colgantes de forma automática y transparente.

Por cuestiones de consistencia, robustez y seguridad de memoria, **la cátedra
exige unificar todos los destructores de tipos opacos y TADs bajo la firma de
doble puntero (`**self`)** y anular la referencia en el cliente.
<!-- {warning} Gestión de Recursos y Robustez (regla {ref}`0x7001h` y {ref}`0x301Eh`) -->

---

(analisis-tecnico-como-funciona)=
#### Análisis Técnico: ¿Cómo Funciona?

**Tipo Incompleto (Incomplete Type)**

Cuando declarás:
:::{code-block} c
:linenos:
typedef struct punto punto_t;

:::
<!-- {code-block} c -->

Sin dar la definición completa, creás un **tipo incompleto** (*incomplete
type*). El compilador sabe que existe una estructura llamada `punto`, pero no
conoce su contenido ni tamaño.

**Restricciones del Tipo Incompleto**

Con un tipo incompleto, el código cliente **solo puede**:

1. **Declarar punteros** al tipo:
   ```{code-block} c
   punto_t *p; // ✅ Permitido
   ```

2. **Pasar punteros** a funciones:
   ```{code-block} c
   punto_desplazar(p, 1.0, 2.0); // ✅ Permitido
   ```

3. **Usar punteros** en expresiones que no requieran el tamaño:
   ```{code-block} c
   if (p == NULL)
   {
       ...
   } // ✅ Permitido
   ```

**Operaciones Prohibidas**

El código cliente **NO puede**:

1. **Declarar instancias** por valor:
   ```{code-block} c
   punto_t p; // ❌ ERROR: incomplete type
   ```

2. **Acceder a miembros**:
   ```{code-block} c
   p->x = 5.0; // ❌ ERROR: incomplete type
   ```

3. **Usar sizeof**:
   ```{code-block} c
   sizeof(punto_t); // ❌ ERROR: incomplete type
   ```

4. **Desreferenciar**:
   ```{code-block} c
   punto_t copia = *p; // ❌ ERROR: incomplete type
   ```

**Compilación Separada y el Rol del Enlazador**

Para entender por qué es posible trabajar con tipos incompletos en C, debemos
analizar el proceso de **compilación separada**:

1. **La Fase de Compilación:** Cada archivo fuente `.c` (ej. `main.c` y
   `punto.c`) se compila de manera independiente para producir un archivo objeto
   (ej. `main.o` y `punto.o`).
   - Cuando el compilador procesa `main.c`, solo lee la cabecera `punto.h`. Al
     encontrar la declaración de tipo opaco `typedef struct punto punto_t;`,
     registra `punto_t` como un tipo incompleto.
   - El compilador no necesita saber cuántos campos tiene `struct punto` ni su
     tamaño total en memoria para compilar `main.c`. Solo necesita saber el
     tamaño de las variables declaradas en `main.c`. Dado que en `main.c` solo
     se declaran **punteros** a `punto_t` (como `punto_t *p`), y el tamaño de
     cualquier puntero a estructura en C es constante (típicamente 8 bytes en
     sistemas de 64 bits, sin importar a qué estructura apunte), el compilador
     puede reservar el espacio adecuado y generar el archivo objeto `main.o` con
     éxito.
2. **La Fase de Enlazado (Linking):** El enlazador toma los archivos objeto
   `main.o` y `punto.o` y los une en el ejecutable final.
   - Es en `punto.o` donde reside la definición concreta de `struct punto` y el
     cuerpo de las funciones (como `crear_punto` y `punto_desplazar`).
   - El enlazador se encarga de resolver las direcciones de las llamadas a
     funciones en `main.o`, redirigiéndolas a las implementaciones reales
     presentes en `punto.o`.
   - Así, el ocultamiento es físico: en tiempo de compilación, el cliente no
     posee la estructura detallada; en tiempo de ejecución, el enlazador conecta
     las llamadas y las funciones operan sobre el espacio de memoria real
     asignado dinámicamente en el heap.

:::{figure} 3/opacidad_memoria.svg
:label: fig-opacidad-memoria
:align: center
:width: 85%

Representación física en memoria de un puntero opaco. El cliente (main.c) solo
almacena la dirección del puntero, mientras que la estructura interna reside en
el heap y solo es visible en el ámbito de la implementación (usuario.c).

:::
<!-- {figure} 3/opacidad_memoria.svg -->
<!-- {figure} 2/opacidad_memoria.svg -->

:::{note} El Tamaño del Puntero es Constante

Un puntero en C simplemente almacena una dirección de memoria.
Independientemente de si apunta a un tipo básico (`char`, `int`), a una
estructura gigante o a un tipo incompleto (puntero opaco), el tamaño requerido
para almacenar esa dirección es exactamente el mismo en una arquitectura de
hardware específica.

:::
<!-- {note} El Tamaño del Puntero es Constante -->

---

(ejercicios-concepto-y-mecanismo)=
#### Ejercicios: Concepto y Mecanismo







---


(patrones-de-diseno-ventajas-y-limitaciones)=
### Patrones de Diseño, Ventajas y Limitaciones


(ventajas-de-los-punteros-opacos)=
#### Ventajas de los Punteros Opacos

**1. Encapsulamiento Fuerte**

La implementación está **completamente oculta**. El código cliente no puede (ni
accidentalmente) acceder o modificar los campos internos.

:::{code-block} c
:linenos:
// Esto NO compila - el compilador protege los detalles internos
punto_t *p = crear_punto(3.0, 4.0);
p->x = 100.0; // ERROR en tiempo de compilación

:::
<!-- {code-block} c -->

::{warning} Límites del Encapsulamiento en C (Convenio vs Compilación)

Es fundamental comprender que en C el encapsulamiento no está garantizado a
nivel de hardware o de forma inviolable por el compilador (como en lenguajes con
modificadores de acceso como `private` en Java o C++). Se trata de un **convenio
de diseño o contrato**.

Un programador cliente malintencionado o descuidado podría:
1. Re-declarar la estructura `struct punto` de forma idéntica en su propio
   código.
2. Realizar un casteo explícito del puntero opaco `punto_t *` a un tipo de
   estructura que exponga sus miembros.

Por lo tanto, la opacidad en C protege contra errores accidentales y
acoplamientos indeseados, pero no constituye una barrera de seguridad
informática infranqueable.
:::::
<!-- {code-block} c -->

**2. Flexibilidad de Implementación**

Podés cambiar completamente la implementación interna sin afectar al código
cliente:

:::{code-block} c
:linenos:
// punto.c - Versión con coordenadas polares (cambio de implementación)
struct punto
{
    double radio;
    double angulo; // en radianes
};

:::
<!-- {code-block} c -->

Si cambiás la implementación a coordenadas polares, las funciones públicas en
`punto.c` realizarán la conversión matemática necesaria para retornar la
proyección de `x` e `y` cuando el cliente llame a `punto_obtener_x` o
`punto_obtener_y`. El código cliente que usa `punto.h` **no necesita
modificarse** porque la interfaz pública sigue intacta.

**3. Mantenimiento de Invariantes**

Solo las funciones del módulo pueden modificar la estructura, garantizando que
los invariantes se cumplan siempre. Por ejemplo, si tenés un tipo `usuario_t`
que representa a un usuario del sistema:

:::{code-block} c
:linenos:
bool usuario_establecer_edad(usuario_t *u, int nueva_edad)
{
    // Garantiza que la edad no sea negativa
    if (u == NULL || nueva_edad < 0)
    {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}

:::
<!-- {code-block} c -->

El código cliente no puede burlar esta validación modificando el campo
directamente.

**4. Compatibilidad Binaria (ABI)**

Si la interfaz pública no cambia, podés actualizar la biblioteca compilada
(`.so` o `.dll`) sin recompilar las aplicaciones que la usan. Esto es crucial
para bibliotecas del sistema.

**5. Reducción de Dependencias**

Los archivos que incluyen `punto.h` no necesitan incluir las dependencias
internas de `punto.c` (por ejemplo, `<math.h>` si se usaran funciones
trigonométricas), reduciendo tiempos de compilación y acoplamiento.

---

(patrones-de-uso-comunes)=
#### Patrones de Uso Comunes

**Patrón Constructor/Destructor**

Toda estructura opaca alocada dinámicamente debe proveer funciones para crear y
destruir instancias:

:::{code-block} c

// Convención de nombres: tipo_accion
tipo_t *crear_tipo(parametros);
void destruir_tipo(tipo_t **instancia);

:::
<!-- {code-block} c -->

**Ejemplo:**
:::{code-block} c
:linenos:
usuario_t *usr = crear_usuario("Carlos", 35);
// ... usar usr ...
destruir_usuario(&usr);

:::
<!-- {code-block} c -->

**Destrucción de Colecciones de Punteros Opacos**

Cuando gestionás una colección (como un array dinámico o una lista enlazada) de
punteros opacos, no podés liberar la colección llamando simplemente a `free`
sobre ella. Hacerlo generará una **fuga de memoria masiva**, ya que los
elementos individuales apuntados seguirán existiendo en el heap sin ninguna
referencia para liberarlos.

Debés implementar un lazo de destrucción que recorra la colección elemento por
elemento, invocando el destructor específico de cada tipo opaco, y recién
entonces liberar la estructura contenedora.

**Ejemplo práctico de destrucción de un array de usuarios:**

:::{code-block} c
:linenos:
#define CANT_USUARIOS 5
void liberar_grupo_usuarios(usuario_t **grupo, size_t cantidad)
{
    if (grupo == NULL)
    {
        return;
    }
    // Recorremos la colección destruyendo cada elemento individual con un lazo
    for (size_t i = 0; i < cantidad; i++)
    {
        destruir_usuario(&grupo[i]);
    }
    // Finalmente, liberamos el array contenedor en sí
    free(grupo);
}

:::
<!-- {code-block} c -->

**Patrón Getter/Setter**

Para acceder a propiedades sin exponer los campos de la estructura:

:::{code-block} c
:linenos:
// Getter - solo lectura
const char *usuario_obtener_nombre(const usuario_t *u);
int usuario_obtener_edad(const usuario_t *u);
// Setter - modificación controlada
bool usuario_establecer_edad(usuario_t *u, int nueva_edad);

:::
<!-- {code-block} c -->

:::{tip} Uso de `const`

Usá `const tipo_t *` en funciones que solo leen, no modifican. Esto documenta la
intención y permite al compilador optimizar el código.

:::
<!-- {tip} Uso de `const` -->

**Patrón de Verificación**

Siempre verificá punteros nulos y condiciones de error de manera defensiva:

:::{code-block} c
:linenos:
bool usuario_establecer_edad(usuario_t *u, int nueva_edad)
{
    // Verificaciones defensivas
    if (u == NULL || nueva_edad < 0)
    {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}

:::
<!-- {code-block} c -->

---

(comparacion-con-otras-tecnicas)=
#### Comparación con Otras Técnicas

**vs. Estructuras Expuestas**

:::{table} Comparación con Estructuras Expuestas
:label: tbl-comparacion-expuestas

| Aspecto | Puntero Opaco | Estructura Expuesta |
| :--- | :--- | :--- |
| **Encapsulamiento** | ✅ Fuerte | ❌ Ninguno |
| **Cambios de implementación** | ✅ No rompen código cliente | ❌ Rompen todo el código dependiente |
| **Protección de invariantes** | ✅ Garantizada por la API | ❌ Imposible de controlar |
| **Rendimiento** | ✅ Similar (indirección de puntero) | ✅ Similar |
| **Depuración (Debugging)** | ⚠️ Más complejo (campos ocultos) | ✅ Directo y simple |
| **Alocación en Stack** | ❌ No disponible | ✅ Permitido |

:::
<!-- {table} Comparación con Estructuras Expuestas -->

**vs. Void Pointers**

:::{code-block} c
:linenos:
// Opción 1: Puntero opaco (RECOMENDADO)
typedef struct punto punto_t;
double punto_obtener_x(const punto_t *p);
// Opción 2: Void pointer (EVITAR)
double punto_obtener_x(const void *p);

:::
<!-- {code-block} c -->

**Problemas de void pointers:**
- Pérdida de type safety (se puede pasar accidentalmente cualquier puntero sin
  advertencia del compilador).
- No hay verificación de tipos en tiempo de compilación.
- Requiere casts explícitos en la implementación.
- Es más propenso a errores de desarrollo.

:::{danger} Anti-patrón: Void Pointers para Opacos

Aunque `void *` también oculta la implementación, **no es la forma adecuada** en
C. Usá siempre punteros opacos con tipos específicos para mantener la seguridad
de tipos.

:::
<!-- {danger} Anti-patrón: Void Pointers para Opacos -->

---

(ejemplo-completo-usuario-opaco)=
#### Ejemplo Completo: Usuario Opaco

Este ejemplo implementa un módulo para gestionar un usuario, donde los campos
internos (un string dinámico y un entero) se mantienen estrictamente
encapsulados.

**Interfaz Pública (`usuario.h`)**

:::{code-block} c
:linenos:
#ifndef USUARIO_H
#define USUARIO_H
#include <stdbool.h>
// Tipo opaco
typedef struct usuario usuario_t;
// Constructor/Destructor
usuario_t *crear_usuario(const char *nombre, int edad);
void destruir_usuario(usuario_t **u);
// Getters y Setters con validación
const char *usuario_obtener_nombre(const usuario_t *u);
int usuario_obtener_edad(const usuario_t *u);
bool usuario_establecer_edad(usuario_t *u, int nueva_edad);
// Operaciones
void usuario_imprimir(const usuario_t *u);
#endif // USUARIO_H

:::
<!-- {code-block} c -->

**Implementación (`usuario.c`)**

:::{code-block} c
:linenos:
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definición completa del usuario - solo visible aquí
struct usuario
{
    char *nombre;
    int edad;
};
usuario_t *crear_usuario(const char *nombre, int edad)
{
    if (nombre == NULL || edad < 0)
    {
        return NULL;
    }
    // Alocación robusta desreferenciando el puntero (regla {ref}`0x7001h`)
    usuario_t *u = malloc(sizeof(*u));
    if (u == NULL)
    {
        return NULL;
    }
    u->nombre = malloc(strlen(nombre) + 1);
    if (u->nombre == NULL)
    {
        free(u);
        return NULL;
    }
    memcpy(u->nombre, nombre, strlen(nombre) + 1);
    u->edad = edad;
    return u;
}
void destruir_usuario(usuario_t **u)
{
    if (u == NULL || *u == NULL)
    {
        return;
    }
    // Primero liberamos los recursos internos
    free((*u)->nombre);
    // Luego liberamos la estructura contenedora
    free(*u);
    *u = NULL;
}
const char *usuario_obtener_nombre(const usuario_t *u)
{
    if (u == NULL)
    {
        return NULL;
    }
    return u->nombre;
}
int usuario_obtener_edad(const usuario_t *u)
{
    if (u == NULL)
    {
        return -1;
    }
    return u->edad;
}
bool usuario_establecer_edad(usuario_t *u, int nueva_edad)
{
    if (u == NULL || nueva_edad < 0)
    {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}
void usuario_imprimir(const usuario_t *u)
{
    if (u == NULL)
    {
        return;
    }
    printf("Usuario: %s | Edad: %d\n", u->nombre, u->edad);
}

:::
<!-- {code-block} c -->

**Uso del Cliente**

:::{code-block} c
:linenos:
#include "usuario.h"
#include <stdio.h>
int main(void)
{
    usuario_t *u = crear_usuario("Martín", 21);
    if (u == NULL)
    {
        return 1;
    }
    usuario_imprimir(u);
    // Intento de modificación válida
    if (usuario_establecer_edad(u, 22))
    {
        printf("Edad actualizada con éxito.\n");
    }
    // Intento de asignación inválida
    if (!usuario_establecer_edad(u, -5))
    {
        printf("Error: no se admiten edades negativas.\n");
    }
    usuario_imprimir(u);
    destruir_usuario(&u);
    return 0;
}

:::
<!-- {code-block} c -->

---

(punteros-opacos-en-bibliotecas-estandar)=
#### Punteros Opacos en Bibliotecas Estándar

Muchas bibliotecas conocidas usan punteros opacos:

**POSIX: FILE**

:::{code-block} c
:linenos:
// stdio.h
typedef struct _IO_FILE FILE;
FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);

:::
<!-- {code-block} c -->

No sabés cómo está implementado `FILE` internamente, pero podés usarlo a través
de punteros.

**OpenSSL**

:::{code-block} c
:linenos:
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;
SSL_CTX *SSL_CTX_new(const SSL_METHOD *method);
SSL *SSL_new(SSL_CTX *ctx);

:::
<!-- {code-block} c -->

**GTK+ (GUI)**

:::{code-block} c
:linenos:
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;
GtkWidget *gtk_window_new(GtkWindowType type);

:::
<!-- {code-block} c -->

Todos estos ejemplos siguen el mismo patrón de puntero opaco.

---

(5_opacos-buenas-practicas)=
#### Buenas Prácticas

**1. Convenciones de Nombres**

:::{code-block} c
:linenos:
// Patrón: tipo_t para el tipo, crear_tipo/destruir_tipo para funciones
typedef struct usuario usuario_t;
usuario_t *crear_usuario(const char *nombre, int edad);
void destruir_usuario(usuario_t **u);

:::
<!-- {code-block} c -->

**2. Documentación Clara**

:::{code-block} c
:linenos:
/**
 * Crea una nueva instancia de un usuario.
 *
 * @param nombre Cadena de caracteres que representa el nombre (no debe ser
   NULL).
 * @param edad Entero no negativo que representa la edad.
 * @return Puntero al usuario creado, o NULL si falla la asignación de memoria
 o los parámetros son inválidos.
 */
usuario_t *crear_usuario(const char *nombre, int edad);
/**
 * Destruye al usuario liberando toda la memoria asociada.
 *
 * @param u Usuario a destruir. Puede ser NULL.
 */
void destruir_usuario(usuario_t **u);

:::
<!-- {code-block} c -->

**3. Manejo de Errores Consistente**

:::{code-block} c
:linenos:
// Retornar NULL en creación si falla
tipo_t *crear_tipo(void)
{
    tipo_t *t = malloc(sizeof(*t));
    if (t == NULL)
    {
        return NULL; // Indicación clara de fallo al cliente
    }
    // ... inicialización ...
    return t;
}
// Retornar bool en operaciones para reportar éxito o fracaso
bool tipo_operar(tipo_t *t, int dato)
{
    if (t == NULL)
    {
        return false; // Fallo: puntero inválido
    }
    // ... operación ...
    return true; // Éxito
}

:::
<!-- {code-block} c -->

**4. Tolerancia a NULL**

:::{code-block} c
:linenos:
void destruir_tipo(tipo_t **t)
{
    // Tolerante a NULL - comportamiento similar a free()
    if (t == NULL || *t == NULL)
    {
        return;
    }
    // ... liberación ...
    free(*t);
    *t = NULL;
}

:::
<!-- {code-block} c -->

**5. Uso de `const` para Intenciones**

:::{code-block} c
:linenos:
// Solo lectura - no modifica la estructura
double punto_obtener_x(const punto_t *punto);
// Modifica la estructura
void punto_desplazar(punto_t *punto, double dx, double dy);

:::
<!-- {code-block} c -->

---

(limitaciones-y-consideraciones)=
#### Limitaciones y Consideraciones

**1. Pérdida de Acceso Directo**

No podés acceder directamente a los campos para debugging o inspección rápida en
herramientas tradicionales:

:::{code-block} c
:linenos:
// En GDB:
(gdb) print punto->x Cannot access memory at address 0x0 : incomplete type

:::
<!-- {code-block} c -->

**Solución:** Proveer funciones de inspección para debugging si es necesario:
:::{code-block} c
:linenos:
#ifdef DEBUG
void punto_debug_print(const punto_t *p);
#endif

:::
<!-- {code-block} c -->

**2. No se Puede Alocar en el Stack**

:::{code-block} c
:linenos:
// Esto NO compila con puntero opaco
punto_t p; // ERROR: incomplete type
// Debés usar el heap
punto_t *p = crear_punto(3.0, 4.0);

:::
<!-- {code-block} c -->

**Implicación:** Siempre hay un costo asociado a la alocación dinámica de
memoria mediante `malloc` y `free`.

**3. Dificultad para Copiar**

No podés realizar una copia superficial por asignación directa:

:::{code-block} c
:linenos:
punto_t copia = *original; // ERROR: incomplete type

:::
<!-- {code-block} c -->

**Solución:** Proveer una función de copia explícita (clonación):
:::{code-block} c
:linenos:
punto_t *punto_clonar(const punto_t *original);

:::
<!-- {code-block} c -->

**4. Compatibilidad con Análisis Estático**

Algunas herramientas de análisis estático tienen dificultades para verificar el
uso de memoria en tipos incompletos fuera de su archivo de implementación.
Asegurate de que Valgrind y las opciones de compilación sanitizer rastreen
correctamente todo el ciclo de vida de estas estructuras.

---

(ejercicios-patrones-y-buenas-practicas)=
#### Ejercicios: Patrones y Buenas Prácticas







---


(contratos-en-modulos-c)=
### Contratos en Módulos C


El diseño de punteros opacos impone una separación estricta entre interfaz e
implementación. Para formalizar esa separación, el **Diseño por Contratos**
proporciona el marco conceptual: cada función de la interfaz tiene
precondiciones (qué exige del cliente) y poscondiciones (qué garantiza al
cliente).

(introduccion-al-diseno-por-contratos)=
#### Introducción al Diseño por Contratos

El **Diseño por Contratos** (Design by Contract, DbC) es una metodología formal
de desarrollo de software introducida por Bertrand Meyer en el lenguaje Eiffel.
Se fundamenta en la metáfora de un contrato legal entre partes: cada componente
de software tiene **obligaciones** (precondiciones que debe garantizar el
cliente) y **beneficios** (postcondiciones que garantiza el proveedor). Este
enfoque transforma el desarrollo de software de una actividad artesanal a una
disciplina ingenieril rigurosa.

:::{figure} ../bloque_1_fundamentos/7/contract_metaphor.svg
:label: fig-metaphor
:align: center
:width: 90%

Metáfora del contrato: cliente y proveedor tienen obligaciones y derechos
mutuos, formalizados mediante precondiciones y postcondiciones.

:::
<!-- {figure} ../bloque_1_fundamentos/7/contract_metaphor.svg -->

:::{important} Beneficios del Diseño por Contratos

1. **Documentación ejecutable**: Los contratos son especificaciones precisas y
   verificables
2. **Detección temprana de errores**: Violaciones se detectan en el punto exacto
   de falla
3. **Facilita testing**: Los contratos definen casos de prueba automáticamente
4. **Mejora mantenibilidad**: El comportamiento esperado está explícito
5. **Razonamiento formal**: Permite demostraciones matemáticas de corrección

:::
<!-- {important} Beneficios del Diseño por Contratos -->

La formalización mediante Lógica de Primer Orden (LPO) proporciona el rigor
matemático necesario para especificar, verificar y razonar sobre la corrección
de programas.

---

## Ejercicios de Autoevaluación

::::{exercise}
:label: ejercicio-opaco-1-mecanismo
Considerá la siguiente declaración de una estructura expuesta que representa un
vector en $\mathbb{R}^3$ en un archivo de cabecera:

:::{code-block} c

typedef struct
{
    double x;
    double y;
    double z;
} vector3d_t;
vector3d_t vector_crear(double x, double y, double z);
vector3d_t vector_sumar(vector3d_t v1, vector3d_t v2);

:::
<!-- {code-block} c -->

Modificá este diseño aplicando el patrón de puntero opaco. Escribí el nuevo
archivo de cabecera (`vector3d.h`) y explicá qué restricciones de compilación
experimentará el código cliente si intenta declarar una variable local
`vector3d_t vec;` en la pila.

::::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-1-mecanismo
:class: dropdown
El archivo de cabecera modificado (`vector3d.h`) utilizando un puntero opaco
debe declarar el tipo de forma incompleta:

:::{code-block} c

#ifndef VECTOR3D_H
#define VECTOR3D_H
// Declaración opaca del tipo incompleto
typedef struct vector3d vector3d_t;
// Constructor y destructor
vector3d_t *vector_crear(double x, double y, double z);
void vector_destruir(vector3d_t **v);
// Operaciones que manipulan el tipo a través de punteros
vector3d_t *vector_sumar(const vector3d_t *v1, const vector3d_t *v2);
double vector_obtener_x(const vector3d_t *v);
double vector_obtener_y(const vector3d_t *v);
double vector_obtener_z(const vector3d_t *v);
#endif // VECTOR3D_H

:::
<!-- {code-block} c -->

**Restricciones de compilación para el cliente:**
Si el cliente intenta declarar `vector3d_t vec;` en su archivo (por ejemplo, en
`main.c`), el compilador arrojará un error indicando que `vector3d_t` es un
**tipo incompleto** (*incomplete type*).

Esto ocurre porque el compilador procesa cada archivo de código fuente de manera
independiente. Al compilar `main.c`, solo tiene acceso a `vector3d.h`, que
declara la existencia de `struct vector3d` pero no su definición completa. Como
el compilador no sabe cuántos bytes ocupa la estructura ni qué campos contiene,
no puede calcular el espacio en memoria necesario en la pila para `vec`,
impidiendo la declaración por valor.

::::
<!-- {solution} ejercicio-opaco-1-mecanismo -->

::::{exercise}
:label: ejercicio-opaco-2-mecanismo
Analizá el siguiente fragmento de código cliente que utiliza el TAD `punto_t`
definido mediante punteros opacos:

:::{code-block} c

#include "punto.h"
#include <stdlib.h>
int main(void)
{
    punto_t *p = malloc(sizeof(punto_t));
    return 0;
}

:::
<!-- {code-block} c -->

Explicá detalladamente por qué este código falla en tiempo de compilación y cuál
es la forma correcta de resolver la alocación de memoria dinámica desde la
perspectiva de la interfaz del TAD.

::::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-2-mecanismo
:class: dropdown
El código falla en tiempo de compilación debido a que intenta aplicar el
operador `sizeof` sobre un tipo incompleto.

1. **Razón del fallo:** El compilador necesita conocer la definición completa de
   la estructura apuntada por `punto_t` (es decir, `struct punto`) para evaluar
   `sizeof(punto_t)`. Dado que esa definición está encapsulada en el archivo de
   implementación `punto.c` y no es visible para el archivo del cliente, el
   compilador no puede determinar el tamaño del tipo y genera un error.
2. **Forma correcta:** La alocación de memoria de un tipo opaco es
   responsabilidad exclusiva del propio módulo. El cliente nunca debe llamar a
   `malloc` directamente para instanciar el objeto. Debe invocar al constructor
   provisto por la API del TAD:

:::{code-block} c

int main(void)
{
    // El constructor interno en punto.c se encarga de malloc y de conocer el
    sizeof punto_t *p = crear_punto(3.0, 4.0);
    if (p == NULL)
    {
        return 1;
    }
    // ...
    destruir_punto(&p);
    return 0;
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ejercicio-opaco-2-mecanismo -->

:::{exercise}
:label: ejercicio-opaco-3-mecanismo
A menudo se confunde el ocultamiento de tipos con el uso de punteros genéricos
(`void *`). Explicá la diferencia fundamental entre usar `typedef struct usuario
usuario_t;` y `void *` en una API en términos de seguridad de tipos (*type
safety*) en tiempo de compilación. Proporcioná un ejemplo donde el compilador no
pueda advertir un error conceptual debido al uso de `void *`.

:::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-3-mecanismo
:class: dropdown
La diferencia fundamental radica en la **seguridad de tipos** (*type safety*)
que ofrece el compilador:

- Con **punteros opacos** (`usuario_t *`), el compilador trata al puntero como
  un tipo único y específico. Si intentás pasar un puntero de otro tipo (por
  ejemplo, `cuenta_t *`) a una función que espera `usuario_t *`, el compilador
  detectará la discrepancia de tipos y generará una advertencia o error en
  tiempo de compilación.
- Con **punteros genéricos** (`void *`), C permite la conversión implícita
  bidireccional entre `void *` y cualquier otro tipo de puntero sin necesidad de
  un cast explícito. Esto anula la capacidad del compilador para verificar si
  los argumentos pasados son correctos.

**Ejemplo problemático con `void *`:**

:::{code-block} c

// API mal diseñada usando void*
void destruir_usuario(void *u);
// Código cliente erróneo
cuenta_t *mi_cuenta = crear_cuenta(12345, "Juan", 1000.0);
// Error conceptual: pasamos un tipo cuenta_t* a un destructor de usuario_t*
destruir_usuario(
    mi_cuenta); // El compilador no advierte el error y compila sin
quejas.

:::
<!-- {code-block} c -->

Si hubiésemos definido `destruir_usuario(usuario_t *u)` con un tipo opaco, el
compilador habría detectado que `mi_cuenta` (de tipo `cuenta_t *`) no coincide
con el tipo esperado, previniendo un potencial fallo grave (fuga de memoria o
corrupción) en tiempo de ejecución.

::::
<!-- {solution} ejercicio-opaco-3-mecanismo -->

:::{exercise}
:label: ejercicio-opaco-1-patrones
Diseñá la interfaz pública (`cuenta.h`) y la implementación (`cuenta.c`) de un
TAD `cuenta_t` (Cuenta Bancaria) utilizando punteros opacos. El TAD debe
almacenar el número de cuenta (`long`), el nombre del titular (`char *` alocado
dinámicamente) y el saldo (`double`).

Implementá las siguientes operaciones:
1. `cuenta_t *crear_cuenta(long nro, const char *titular, double saldo_inicial)`
2. `void destruir_cuenta(cuenta_t **c)`
3. `bool cuenta_depositar(cuenta_t *c, double monto)`
4. `bool cuenta_extraer(cuenta_t *c, double monto)`
5. `double cuenta_obtener_saldo(const cuenta_t *c)`

Evitá saldos negativos, montos de depósitos o extracciones no válidos, y
asegurate de liberar toda la memoria dinámica.

:::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-1-patrones
:class: dropdown
**Interfaz Pública (`cuenta.h`):**

:::{code-block} c

#ifndef CUENTA_H
#define CUENTA_H
#include <stdbool.h>
typedef struct cuenta cuenta_t;
cuenta_t *crear_cuenta(long nro, const char *titular, double saldo_inicial);
void destruir_cuenta(cuenta_t **c);
bool cuenta_depositar(cuenta_t *c, double monto);
bool cuenta_extraer(cuenta_t *c, double monto);
double cuenta_obtener_saldo(const cuenta_t *c);
#endif // CUENTA_H

:::
<!-- {code-block} c -->

**Archivo de Implementación (`cuenta.c`):**

:::{code-block} c

#include "cuenta.h"
#include <stdlib.h>
#include <string.h>
struct cuenta
{
    long nro_cuenta;
    char *titular;
    double saldo;
};
cuenta_t *crear_cuenta(long nro, const char *titular, double saldo_inicial)
{
    if (titular == NULL || saldo_inicial < 0.0)
    {
        return NULL;
    }
    cuenta_t *c = malloc(sizeof(*c));
    if (c == NULL)
    {
        return NULL;
    }
    c->nro_cuenta = nro;
    c->titular = malloc(strlen(titular) + 1);
    if (c->titular == NULL)
    {
        free(c);
        return NULL;
    }
    strcpy(c->titular, titular);
    c->saldo = saldo_inicial;
    return c;
}
void destruir_cuenta(cuenta_t **c)
{
    if (c == NULL || *c == NULL)
    {
        return;
    }
    free((*c)->titular);
    free(*c);
    *c = NULL;
}
bool cuenta_depositar(cuenta_t *c, double monto)
{
    if (c == NULL || monto <= 0.0)
    {
        return false;
    }
    c->saldo += monto;
    return true;
}
bool cuenta_extraer(cuenta_t *c, double monto)
{
    if (c == NULL || monto <= 0.0 || c->saldo < monto)
    {
        return false;
    }
    c->saldo -= monto;
    return true;
}
double cuenta_obtener_saldo(const cuenta_t *c)
{
    if (c == NULL)
    {
        return 0.0;
    }
    return c->saldo;
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ejercicio-opaco-1-patrones -->

::::{exercise}
:label: ejercicio-opaco-2-patrones
Considerá que disponés de un arreglo dinámico que contiene punteros a la
estructura opaca `cuenta_t` del ejercicio anterior. Escribí una función en C con
la siguiente firma:

:::{code-block} c

void cartera_destruir(cuenta_t **cartera, size_t cantidad);

:::
<!-- {code-block} c -->

Esta función debe liberar de forma completa tanto cada cuenta individual como el
arreglo que las contiene. Explicá qué ocurriría con la memoria del heap si
llamaras directamente a `free(cartera)` sin recorrer el arreglo con un lazo.

::::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-2-patrones
:class: dropdown
**Implementación de la función:**

:::{code-block} c

#include "cuenta.h"
#include <stdlib.h>
void cartera_destruir(cuenta_t **cartera, size_t cantidad)
{
    if (cartera == NULL)
    {
        return;
    }
    // Liberamos cada cuenta individual recorriendo el arreglo con un lazo
    for (size_t i = 0; i < cantidad; i++)
    {
        destruir_cuenta(&cartera[i]);
        cartera[i] = NULL; // Evitamos punteros colgantes en el arreglo
    }
    // Liberamos el arreglo contenedor
    free(cartera);
}

:::
<!-- {code-block} c -->

**Explicación:**
Si llamaras directamente a `free(cartera)` sin recorrer el arreglo, liberarías
únicamente el bloque de memoria que almacena los punteros (las direcciones de
memoria). Sin embargo, cada una de las estructuras `cuenta_t` alocadas
dinámicamente, junto con las cadenas `titular` asociadas a ellas, permanecerían
en el heap.

Al perderse el arreglo `cartera`, el programa ya no tendría forma de conocer las
direcciones de memoria de esas cuentas para liberarlas. Esto provocaría una
**fuga de memoria** (*memory leak*) severa.

::::
<!-- {solution} ejercicio-opaco-2-patrones -->

:::{exercise}
:label: ejercicio-opaco-3-patrones
Cuando diseñás un getter para una cadena almacenada en una estructura opaca (por
ejemplo, `const char *cuenta_obtener_titular(const cuenta_t *c)`), se suele
retornar directamente el puntero interno `c->titular`.

Explicá:
1. Por qué calificar el retorno con `const` es fundamental para la seguridad del
   diseño.
2. Qué riesgos asume el cliente si realiza un cast explícito para remover el
   calificador `const` y modifica el contenido de la cadena.
3. Qué alternativa de implementación existe si quisiéramos independizar
   completamente al cliente del ciclo de vida de la estructura interna.

:::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-3-patrones
:class: dropdown
1. **Importancia del calificador `const`:** Al retornar `const char *`, le
   indicás al compilador y al programador cliente que la cadena devuelta es de
   solo lectura. Esto impide que el código cliente intente modificar los
   caracteres directamente o intente liberar la memoria usando `free()`,
   protegiendo la consistencia de los datos del TAD.
2. **Riesgos de remover `const` mediante cast:** Si el cliente hace un cast
   explícito (por ejemplo, `char *t = (char *)cuenta_obtener_titular(c)`) y
   altera la cadena:
   - Puede romper invariantes de la estructura, por ejemplo alterando la
     longitud de la cadena de forma que cause desbordamientos de búfer en
     futuras operaciones internas del TAD.
   - Puede corromper la memoria del heap si escribe más caracteres de los
     reservados.
   - Si la estructura se destruye llamando a `destruir_cuenta`, el puntero que
     tiene el cliente pasará a apuntar a memoria liberada (puntero colgante), y
     cualquier acceso posterior causará un comportamiento indefinido.
3. **Alternativa de diseño:** La alternativa es retornar una **copia dinámica**
   de la cadena (por ejemplo, usando `strdup` o `malloc` + `strcpy`). En este
   caso, el cliente pasa a ser el propietario del recurso devuelto y asume la
   obligación de liberarlo:

:::{code-block} c

// Firma del getter alternativo
char *cuenta_clonar_titular(const cuenta_t *c)
{
    if (c == NULL || c->titular == NULL)
    {
        return NULL;
    }
    char *copia = malloc(strlen(c->titular) + 1);
    if (copia != NULL)
    {
        strcpy(copia, c->titular);
    }
    return copia; // El cliente debe liberar esta memoria con free()
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ejercicio-opaco-3-patrones -->

::::{exercise}
:label: ejercicio-opaco-1-contratos
Para la función constructora del TAD usuario:

:::{code-block} c

usuario_t *crear_usuario(const char *nombre, int edad);

:::
<!-- {code-block} c -->

1. Escribí las precondiciones y poscondiciones formales en lenguaje natural
   técnico y utilizando expresiones lógicas para representar el contrato.
2. Explicá cómo se relacionan estas condiciones con el valor de retorno en caso
   de falla de alocación de memoria.

::::
<!-- {exercise} -->

:::{solution} ejercicio-opaco-1-contratos
:class: dropdown
**1. Especificación del Contrato:**

- **Precondiciones (obligaciones del cliente):**
  - El puntero `nombre` no debe ser nulo: $\text{nombre} \neq \text{NULL}$.
  - El valor de la edad debe ser no negativo: $\text{edad} \geq 0$.

- **Poscondiciones (garantías del proveedor):**
  - Si la alocación tiene éxito, se retorna un puntero `u` válido ($u \neq
    \text{NULL}$) tal que:
    - Su edad coincide con el parámetro: $\text{usuario\_obtener\_edad}(u) =
      \text{edad}$.
    - Su nombre es equivalente a la cadena original:
      $\text{strcmp}(\text{usuario\_obtener\_nombre}(u), \text{nombre}) = 0$.
  - Si falla la asignación de memoria, retorna `NULL`.

**2. Relación con fallas de memoria:**
El contrato contempla la posibilidad de que la memoria se agote. La garantía de
retornar una estructura válida está sujeta a la disponibilidad de recursos del
sistema. Por lo tanto, el retorno de `NULL` es la representación formal de un
incumplimiento de la poscondición por fuerza mayor, lo cual obliga al cliente a
verificar siempre que el valor de retorno no sea nulo antes de utilizarlo.

:::
<!-- {solution} ejercicio-opaco-1-contratos -->

:::{exercise}
:label: ejercicio-opaco-2-contratos
En el desarrollo de TADs con punteros opacos, a menudo surge la duda sobre si
usar aserciones (`assert`) o estructuras de control (`if`) para verificar el
estado de los punteros recibidos.

Establecé una regla de diseño clara indicando en qué casos debe usarse cada una
y ejemplificá con fragmentos de código para el caso de una función de
desreferencia como `usuario_obtener_edad`.

:::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-2-contratos
:class: dropdown
**Regla de diseño:**

- **Aserciones (`assert`):** Se utilizan para capturar **errores de
  programación** (bugs del desarrollador) en tiempo de desarrollo/depuración. Se
  aplican sobre condiciones que bajo un diseño correcto *nunca* deberían ser
  falsas (por ejemplo, violaciones flagrantes del contrato por parte del
  cliente).
- **Verificaciones defensivas (`if`):** Se utilizan para manejar situaciones de
  error que pueden ocurrir legítimamente durante la ejecución normal del
  programa (por ejemplo, fallas en la alocación de memoria, entradas del usuario
  final que requieren validación, o fallos de E/S).

**Ejemplo de desreferencia con `assert` (Enfoque DbC estricto):**
Si el contrato de la función exige explícitamente que el puntero sea válido,
pasar `NULL` es un bug del cliente:

:::{code-block} c

#include <assert.h>
int usuario_obtener_edad(const usuario_t *u)
{
    // Si u es NULL, el cliente violó la precondición del contrato.
    // Detenemos el programa de inmediato para alertar al desarrollador.
    assert(u != NULL);
    return u->edad;
}

:::
<!-- {code-block} c -->

**Ejemplo de verificación defensiva (Enfoque tolerante):**
Si se decide que la API sea tolerante al puntero nulo y maneje el error
devolviendo un valor centinela:

:::{code-block} c

int usuario_obtener_edad(const usuario_t *u)
{
    if (u == NULL)
    {
        return -1; // Valor centinela que indica error sin abortar la ejecución
    }
    return u->edad;
}

:::
<!-- {code-block} c -->

::::
<!-- {solution} ejercicio-opaco-2-contratos -->

::::{exercise}
:label: ejercicio-opaco-3-contratos
Definí el concepto de **invariante de representación** en el contexto de un TAD
implementado con punteros opacos. Proponé las invariantes de representación para
la estructura `cuenta_t` del ejercicio anterior y escribí una función interna de
verificación:

:::{code-block} c

static bool cuenta_validar_invariante(const cuenta_t *c);

:::
<!-- {code-block} c -->

Explicá en qué partes de la implementación del módulo deberías invocar este
validador para asegurar el cumplimiento del contrato.

::::
<!-- {exercise} -->

::::{solution} ejercicio-opaco-3-contratos
:class: dropdown
**Invariante de representación:**
Es una propiedad lógica referida a los campos internos de la estructura de datos
que debe cumplirse obligatoriamente para cualquier instancia del TAD en todo
estado estable (es decir, antes y después de cualquier operación pública).

**Invariantes para `cuenta_t`:**
1. El puntero al objeto cuenta no debe ser nulo.
2. El puntero al titular de la cuenta no debe ser nulo (`c->titular != NULL`).
3. El saldo de la cuenta no debe ser negativo (`c->saldo >= 0.0`).

**Función de verificación interna (`cuenta.c`):**

:::{code-block} c

#include <stdbool.h>
static bool cuenta_validar_invariante(const cuenta_t *c)
{
    if (c == NULL)
    {
        return false;
    }
    if (c->titular == NULL)
    {
        return false;
    }
    if (c->saldo < 0.0)
    {
        return false;
    }
    return true;
}

:::
<!-- {code-block} c -->

**Ubicación de las invocaciones:**
Para garantizar la integridad del TAD, esta función debe invocarse en los
siguientes puntos:
1. **Al finalizar el constructor:** Justo antes de retornar el puntero creado,
   para asegurar que el objeto se entrega en un estado inicial válido.
2. **Al ingresar a cualquier función mutadora (como depositar o extraer):** Se
   verifica al inicio de la función (precondición del estado interno) y al
   finalizar la operación (antes del `return`), asegurando que la lógica interna
   de la función no corrompió las invariantes de representación de la
   estructura.

::::
<!-- {solution} ejercicio-opaco-3-contratos -->

## Glosario

:::{glossary}

Tipo opaco 
: Un tipo de dato cuya implementación interna está oculta al código
cliente. Generalmente, como un puntero a una estructura cuya estructura no se
expone
fuera de la librería. Se dice que esta está "Encapsulada".

API (Interfaz de Programación de Aplicaciones)
: Conjunto de firmas de funciones y tipos expuestos para el cliente.

Encapsulamiento
: Principio que oculta los detalles de implementación interna.

:::
<!-- {glossary} -->

## Síntesis y Resumen

(5_opacos-resumen)=
### Resumen


Los punteros opacos son una técnica esencial para construir software modular y
mantenible en C:

:::{important} Conceptos Clave

**¿Qué es un puntero opaco?**
- Declaración de estructura en `.h` sin definición completa.
- Definición completa solo en `.c`.
- El usuario solo manipula punteros, no la estructura directamente.

**Ventajas:**
1. **Encapsulamiento fuerte:** Imposible acceder a campos internos.
2. **Flexibilidad:** Cambiar la implementación sin romper el código cliente.
3. **Invariantes garantizados:** Solo las funciones del módulo modifican la
   estructura.
4. **Compatibilidad binaria:** Actualizar la biblioteca sin recompilar las
   aplicaciones.

**Patrón típico:**
```{code-block} c
:linenos:
// tipo.h
typedef struct tipo tipo_t;
tipo_t *crear_tipo(...);
void destruir_tipo(tipo_t *t);
bool tipo_operacion(tipo_t *t, ...);
// tipo.c
struct tipo
{
    // Campos privados
};

```
<!-- {code-block} c -->

**Conexiones:**
- Fundamental para implementar TADs (ver [](3_tad.md)).
- Requiere memoria dinámica (ver {ref}`capitulo-memoria-dinamica`).
- Usado extensivamente en bibliotecas del sistema y APIs públicas.

:::
<!-- {important} Conceptos Clave -->

:::{tip} Cuándo Usar Punteros Opacos

**Usar cuando:**
- Diseñás una API pública o biblioteca.
- Querés ocultar detalles de implementación.
- Necesitás cambiar la implementación sin romper la compatibilidad.
- Implementás un TAD con invariantes estrictos.

**No usar cuando:**
- Usás estructuras simples sin lógica ni invariantes (ej: `punto2d_t {double x,
  y;}`).
- La performance crítica requiere acceso directo en línea (inlining).
- Se trata de código puramente interno de un módulo que no se expone
  externamente.

:::
<!-- {tip} Cuándo Usar Punteros Opacos -->

Dominar los punteros opacos es esencial para escribir código C profesional,
mantenible y robusto. Es la base del diseño modular en C y el equivalente más
cercano al encapsulamiento de la programación orientada a objetos.

## Referencias y Lecturas de Tipos Opacos

(referencias-lecturas-opacos)=
### Referencias y Lecturas de Tipos Opacos


(5_opacos-textos-fundamentales)=
#### Textos Fundamentales

- {cite:t}`hanson_c_1996`. *C Interfaces and Implementations*. Capítulo 1:
  Interfaces. Tratamiento exhaustivo de punteros opacos y diseño de interfaces.

- {cite:t}`kernighan_c_2014`. *The C Programming Language*. Capítulo 6:
  Structures. Sección sobre tipos incompletos.

- {cite:t}`king_c_2008`. *C Programming: A Modern Approach*. Capítulo 19:
  Program Design. Information hiding y modularidad.

(documentacion-de-estandares)=
#### Documentación de Estándares

- **ISO C99 Standard** (6.2.5): Definición formal de tipos incompletos.
- **ISO C11 Standard** (6.7.2.3): Declaraciones de estructuras y tipos opacos.

(articulos-y-recursos)=
#### Artículos y Recursos

- **"Object-Oriented Programming With ANSI-C"** - Axel-Tobias Schreiner. Uso
  avanzado de punteros opacos para simular OOP.

- **POSIX API Design Guidelines** - Ejemplos de APIs del sistema que usan
  punteros opacos extensivamente.

---
