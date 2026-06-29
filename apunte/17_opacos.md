---
title: Punteros Opacos y Encapsulamiento en C
short_title: "17 - Opacos"
subtitle: Técnicas de ocultamiento de información y diseño modular
---

## Introducción

Los **punteros opacos** (opaque pointers) son una técnica fundamental en C para implementar **encapsulamiento** y **ocultamiento de información** (information hiding). Esta técnica permite ocultar la implementación interna de una estructura, exponiendo solo una interfaz pública al usuario, de manera análoga al encapsulamiento de miembros privados de una clase en lenguajes orientados a objetos.

El concepto de puntero opaco es esencial para construir **APIs robustas** y **bibliotecas mantenibles**, donde los detalles de implementación pueden cambiar sin romper el código cliente que las utiliza.

:::{important} Conexión con TADs
Los punteros opacos son la técnica de programación central sobre la cual se construyen los Tipos de Datos Abstractos (TADs) en C, concepto que se aborda en detalle en el capítulo siguiente ([](18_tad)).
:::

---

## Motivación: El Problema del Acceso Directo

Considerá una implementación ingenua de un punto geométrico en dos dimensiones donde la estructura está completamente expuesta:

```{code-block}c
:linenos:
// punto_malo.h - NO USAR: Implementación expuesta
typedef struct {
    double x;
    double y;
} punto_t;

// Funciones públicas
punto_t *crear_punto(double x, double y);
void desplazar_punto(punto_t *p, double dx, double dy);
```

### Problemas de Esta Aproximación

**1. Violación del encapsulamiento:**
```{code-block}c
punto_t *p = crear_punto(3.0, 4.0);
// El usuario puede acceder y modificar directamente los campos internos
p->x = -9999.0;  // Modificación directa sin control
```

**2. Imposibilidad de cambiar la implementación:**
Si decidís cambiar la representación interna de coordenadas cartesianas ($x, y$) a coordenadas polares ($radio, angulo$) para optimizar operaciones de rotación, **todo el código cliente se rompe** porque depende de los campos `x` e `y` específicos de la estructura.

**3. Falta de control sobre invariantes:**
No podés validar ni interceptar los cambios en los datos. Si la estructura requiriera que el punto se mantenga dentro de ciertos límites (por ejemplo, un plano acotado de una pantalla), no hay forma de evitar que el usuario asigne coordenadas fuera de rango directamente.

:::{danger} Anti-patrón
Exponer la definición completa de una estructura en el archivo de cabecera es un **anti-patrón** que destruye la abstracción y crea dependencias frágiles.
:::

---

## La Solución: Punteros Opacos

La técnica de punteros opacos consiste en **declarar la estructura en el archivo de cabecera pero definirla en el archivo de implementación**.

:::{tip} Directivas de Estilo para TADs (regla {ref}`0x0035h`)
Las directivas de diseño de la cátedra establecen que todos los Tipos de Datos Abstractos deben diseñarse utilizando punteros opacos. La interfaz expuesta en el archivo `.h` debe ser lo más limpia posible, documentando de manera exhaustiva sus precondiciones, poscondiciones y el comportamiento ante casos de error mediante comentarios estructurados (regla {ref}`0x0035h`).
:::

### Estructura del Patrón

#### Archivo de Cabecera (`.h`) - Interfaz Pública

```{code-block}c
:linenos:
// punto.h - Interfaz pública
#ifndef PUNTO_H
#define PUNTO_H

// Declaración OPACA: el usuario solo ve que existe una estructura
typedef struct punto punto_t;

// Funciones públicas - la interfaz
punto_t *crear_punto(double x, double y);
void destruir_punto(punto_t *punto);

double punto_obtener_x(const punto_t *punto);
double punto_obtener_y(const punto_t *punto);
void punto_desplazar(punto_t *punto, double dx, double dy);

#endif  // PUNTO_H
```

#### Archivo de Implementación (`.c`) - Detalles Privados

```{code-block}c
:linenos:
// punto.c - Implementación privada
#include "punto.h"
#include <stdlib.h>

// Definición COMPLETA de la estructura - solo visible aquí
struct punto {
    double x;
    double y;
};

punto_t *crear_punto(double x, double y) {
    punto_t *p = malloc(sizeof(*p));
    if (p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

void destruir_punto(punto_t *punto) {
    free(punto);
}

double punto_obtener_x(const punto_t *punto) {
    if (punto == NULL) {
        return 0.0;
    }
    return punto->x;
}

double punto_obtener_y(const punto_t *punto) {
    if (punto == NULL) {
        return 0.0;
    }
    return punto->y;
}

void punto_desplazar(punto_t *punto, double dx, double dy) {
    if (punto == NULL) {
        return;
    }
    punto->x += dx;
    punto->y += dy;
}
```

#### Código Cliente

```{code-block}c
:linenos:
// main.c - Usuario de la interfaz
#include <stdio.h>
#include "punto.h"

int main(void) {
    punto_t *p = crear_punto(3.0, 4.0);
    if (p == NULL) {
        fprintf(stderr, "Error al crear el punto\n");
        return 1;
    }
    
    // El usuario SOLO puede usar la interfaz pública
    punto_desplazar(p, 1.5, -2.0);
    printf("Punto: (%.1f, %.1f)\n", punto_obtener_x(p), punto_obtener_y(p));
    
    // Esto NO COMPILA: el usuario no puede acceder a los campos internos
    // p->x = 10.0;  // ERROR: incomplete type 'struct punto'
    
    destruir_punto(p);
    p = NULL;
    return 0;
}
```

:::{warning} Gestión de Recursos y Robustez (regla {ref}`0x0003h` y {ref}`0x0036h`)
Dado que las instancias de tipos opacos se alocan dinámicamente en el heap, es mandatorio que el constructor inicialice todos sus campos a valores seguros o `NULL` (regla {ref}`0x0003h`). Asimismo, al destruir la estructura mediante su función liberadora, debe asignarse `NULL` al puntero en el ámbito del cliente para evitar el uso accidental de punteros colgantes (regla {ref}`0x0036h`).
:::

---

## Análisis Técnico: ¿Cómo Funciona?

### Tipo Incompleto (Incomplete Type)

Cuando declarás:
```{code-block}c
:linenos:
typedef struct punto punto_t;
```

Sin dar la definición completa, creás un **tipo incompleto** (*incomplete type*). El compilador sabe que existe una estructura llamada `punto`, pero no conoce su contenido ni tamaño.

### Restricciones del Tipo Incompleto

Con un tipo incompleto, el código cliente **solo puede**:

1. **Declarar punteros** al tipo:
   ```{code-block}c
   punto_t *p;  // ✅ Permitido
   ```

2. **Pasar punteros** a funciones:
   ```{code-block}c
   punto_desplazar(p, 1.0, 2.0);  // ✅ Permitido
   ```

3. **Usar punteros** en expresiones que no requieran el tamaño:
   ```{code-block}c
   if (p == NULL) { ... }  // ✅ Permitido
   ```

### Operaciones Prohibidas

El código cliente **NO puede**:

1. **Declarar instancias** por valor:
   ```{code-block}c
   punto_t p;  // ❌ ERROR: incomplete type
   ```

2. **Acceder a miembros**:
   ```{code-block}c
   p->x = 5.0;  // ❌ ERROR: incomplete type
   ```

3. **Usar sizeof**:
   ```{code-block}c
   sizeof(punto_t);  // ❌ ERROR: incomplete type
   ```

4. **Desreferenciar**:
   ```{code-block}c
   punto_t copia = *p;  // ❌ ERROR: incomplete type
   ```

### Compilación Separada y el Rol del Enlazador

Para entender por qué es posible trabajar con tipos incompletos en C, debemos analizar el proceso de **compilación separada**:

1. **La Fase de Compilación:** Cada archivo fuente `.c` (ej. `main.c` y `punto.c`) se compila de manera independiente para producir un archivo objeto (ej. `main.o` y `punto.o`).
   - Cuando el compilador procesa `main.c`, solo lee la cabecera `punto.h`. Al encontrar la declaración de tipo opaco `typedef struct punto punto_t;`, registra `punto_t` como un tipo incompleto.
   - El compilador no necesita saber cuántos campos tiene `struct punto` ni su tamaño total en memoria para compilar `main.c`. Solo necesita saber el tamaño de las variables declaradas en `main.c`. Dado que en `main.c` solo se declaran **punteros** a `punto_t` (como `punto_t *p`), y el tamaño de cualquier puntero a estructura en C es constante (típicamente 8 bytes en sistemas de 64 bits, sin importar a qué estructura apunte), el compilador puede reservar el espacio adecuado y generar el archivo objeto `main.o` con éxito.
2. **La Fase de Enlazado (Linking):** El enlazador toma los archivos objeto `main.o` y `punto.o` y los une en el ejecutable final.
   - Es en `punto.o` donde reside la definición concreta de `struct punto` y el cuerpo de las funciones (como `crear_punto` y `punto_desplazar`).
   - El enlazador se encarga de resolver las direcciones de las llamadas a funciones en `main.o`, redirigiéndolas a las implementaciones reales presentes en `punto.o`.
   - Así, el ocultamiento es físico: en tiempo de compilación, el cliente no posee la estructura detallada; en tiempo de ejecución, el enlazador conecta las llamadas y las funciones operan sobre el espacio de memoria real asignado dinámicamente en el heap.

```{figure} 17/opacidad_memoria.svg
:label: fig-opacidad-memoria
:align: center
:width: 85%

Representación física en memoria de un puntero opaco. El cliente (main.c) solo almacena la dirección del puntero, mientras que la estructura interna reside en el heap y solo es visible en el ámbito de la implementación (usuario.c).
```

:::{note} El Tamaño del Puntero es Constante
Un puntero en C simplemente almacena una dirección de memoria. Independientemente de si apunta a un tipo básico (`char`, `int`), a una estructura gigante o a un tipo incompleto (puntero opaco), el tamaño requerido para almacenar esa dirección es exactamente el mismo en una arquitectura de hardware específica.
:::

---

## Ventajas de los Punteros Opacos

### 1. Encapsulamiento Fuerte

La implementación está **completamente oculta**. El código cliente no puede (ni accidentalmente) acceder o modificar los campos internos.

```{code-block}c
:linenos:
// Esto NO compila - el compilador protege los detalles internos
punto_t *p = crear_punto(3.0, 4.0);
p->x = 100.0;  // ERROR en tiempo de compilación
```

### 2. Flexibilidad de Implementación

Podés cambiar completamente la implementación interna sin afectar al código cliente:

```{code-block}c
:linenos:
// punto.c - Versión con coordenadas polares (cambio de implementación)
struct punto {
    double radio;
    double angulo; // en radianes
};
```

Si cambiás la implementación a coordenadas polares, las funciones públicas en `punto.c` realizarán la conversión matemática necesaria para retornar la proyección de `x` e `y` cuando el cliente llame a `punto_obtener_x` o `punto_obtener_y`. El código cliente que usa `punto.h` **no necesita modificarse** porque la interfaz pública sigue intacta.

### 3. Mantenimiento de Invariantes

Solo las funciones del módulo pueden modificar la estructura, garantizando que los invariantes se cumplan siempre. Por ejemplo, si tenés un tipo `usuario_t` que representa a un usuario del sistema:

```{code-block}c
:linenos:
bool usuario_establecer_edad(usuario_t *u, int nueva_edad) {
    // Garantiza que la edad no sea negativa
    if (u == NULL || nueva_edad < 0) {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}
```

El código cliente no puede burlar esta validación modificando el campo directamente.

### 4. Compatibilidad Binaria (ABI)

Si la interfaz pública no cambia, podés actualizar la biblioteca compilada (`.so` o `.dll`) sin recompilar las aplicaciones que la usan. Esto es crucial para bibliotecas del sistema.

### 5. Reducción de Dependencias

Los archivos que incluyen `punto.h` no necesitan incluir las dependencias internas de `punto.c` (por ejemplo, `<math.h>` si se usaran funciones trigonométricas), reduciendo tiempos de compilación y acoplamiento.

---

## Patrones de Uso Comunes

### Patrón Constructor/Destructor

Toda estructura opaca alocada dinámicamente debe proveer funciones para crear y destruir instancias:

```{code-block}c
// Convención de nombres: tipo_accion
tipo_t *crear_tipo(parametros);
void destruir_tipo(tipo_t *instancia);
```

**Ejemplo:**
```{code-block}c
:linenos:
usuario_t *usr = crear_usuario("Carlos", 35);
// ... usar usr ...
destruir_usuario(usr);
usr = NULL;
```

#### Destrucción de Colecciones de Punteros Opacos

Cuando gestionás una colección (como un array dinámico o una lista enlazada) de punteros opacos, no podés liberar la colección llamando simplemente a `free` sobre ella. Hacerlo generará una **fuga de memoria masiva**, ya que los elementos individuales apuntados seguirán existiendo en el heap sin ninguna referencia para liberarlos.

Debés implementar un lazo de destrucción que recorra la colección elemento por elemento, invocando el destructor específico de cada tipo opaco, y recién entonces liberar la estructura contenedora.

**Ejemplo práctico de destrucción de un array de usuarios:**

```{code-block}c
:linenos:
#define CANT_USUARIOS 5

void liberar_grupo_usuarios(usuario_t **grupo, size_t cantidad) {
    if (grupo == NULL) {
        return;
    }
    
    // Recorremos la colección destruyendo cada elemento individual con un lazo
    for (size_t i = 0; i < cantidad; i++) {
        destruir_usuario(grupo[i]);
        grupo[i] = NULL; // Evita punteros colgantes en el array
    }
    
    // Finalmente, liberamos el array contenedor en sí
    free(grupo);
}
```

### Patrón Getter/Setter

Para acceder a propiedades sin exponer los campos de la estructura:

```{code-block}c
:linenos:
// Getter - solo lectura
const char *usuario_obtener_nombre(const usuario_t *u);
int usuario_obtener_edad(const usuario_t *u);

// Setter - modificación controlada
bool usuario_establecer_edad(usuario_t *u, int nueva_edad);
```

:::{tip} Uso de `const`
Usá `const tipo_t *` en funciones que solo leen, no modifican. Esto documenta la intención y permite al compilador optimizar el código.
:::

### Patrón de Verificación

Siempre verificá punteros nulos y condiciones de error de manera defensiva:

```{code-block}c
:linenos:
bool usuario_establecer_edad(usuario_t *u, int nueva_edad) {
    // Verificaciones defensivas
    if (u == NULL || nueva_edad < 0) {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}
```

---

## Comparación con Otras Técnicas

### vs. Estructuras Expuestas

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

### vs. Void Pointers

```{code-block}c
:linenos:
// Opción 1: Puntero opaco (RECOMENDADO)
typedef struct punto punto_t;
double punto_obtener_x(const punto_t *p);

// Opción 2: Void pointer (EVITAR)
double punto_obtener_x(const void *p);
```

**Problemas de void pointers:**
- Pérdida de type safety (se puede pasar accidentalmente cualquier puntero sin advertencia del compilador).
- No hay verificación de tipos en tiempo de compilación.
- Requiere casts explícitos en la implementación.
- Es más propenso a errores de desarrollo.

:::{danger} Anti-patrón: Void Pointers para Opacos
Aunque `void *` también oculta la implementación, **no es la forma adecuada** en C. Usá siempre punteros opacos con tipos específicos para mantener la seguridad de tipos.
:::

---

## Ejemplo Completo: Usuario Opaco

Este ejemplo implementa un módulo para gestionar un usuario, donde los campos internos (un string dinámico y un entero) se mantienen estrictamente encapsulados.

### Interfaz Pública (`usuario.h`)

```{code-block}c
:linenos:
#ifndef USUARIO_H
#define USUARIO_H

#include <stdbool.h>

// Tipo opaco
typedef struct usuario usuario_t;

// Constructor/Destructor
usuario_t *crear_usuario(const char *nombre, int edad);
void destruir_usuario(usuario_t *u);

// Getters y Setters con validación
const char *usuario_obtener_nombre(const usuario_t *u);
int usuario_obtener_edad(const usuario_t *u);
bool usuario_establecer_edad(usuario_t *u, int nueva_edad);

// Operaciones
void usuario_imprimir(const usuario_t *u);

#endif  // USUARIO_H
```

### Implementación (`usuario.c`)

```{code-block}c
:linenos:
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición completa del usuario - solo visible aquí
struct usuario {
    char *nombre;
    int edad;
};

usuario_t *crear_usuario(const char *nombre, int edad) {
    if (nombre == NULL || edad < 0) {
        return NULL;
    }
    
    // Alocación robusta desreferenciando el puntero (regla {ref}`0x0003h`)
    usuario_t *u = malloc(sizeof(*u));
    if (u == NULL) {
        return NULL;
    }
    
    u->nombre = malloc(strlen(nombre) + 1);
    if (u->nombre == NULL) {
        free(u);
        return NULL;
    }
    memcpy(u->nombre, nombre, strlen(nombre) + 1);
    
    u->edad = edad;
    return u;
}

void destruir_usuario(usuario_t *u) {
    if (u == NULL) {
        return;
    }
    
    // Primero liberamos los recursos internos
    free(u->nombre);
    // Luego liberamos la estructura contenedora
    free(u);
}

const char *usuario_obtener_nombre(const usuario_t *u) {
    if (u == NULL) {
        return NULL;
    }
    return u->nombre;
}

int usuario_obtener_edad(const usuario_t *u) {
    if (u == NULL) {
        return -1;
    }
    return u->edad;
}

bool usuario_establecer_edad(usuario_t *u, int nueva_edad) {
    if (u == NULL || nueva_edad < 0) {
        return false;
    }
    u->edad = nueva_edad;
    return true;
}

void usuario_imprimir(const usuario_t *u) {
    if (u == NULL) {
        return;
    }
    printf("Usuario: %s | Edad: %d\n", u->nombre, u->edad);
}
```

### Uso del Cliente

```{code-block}c
:linenos:
#include <stdio.h>
#include "usuario.h"

int main(void) {
    usuario_t *u = crear_usuario("Martín", 21);
    if (u == NULL) {
        return 1;
    }
    
    usuario_imprimir(u);
    
    // Intento de modificación válida
    if (usuario_establecer_edad(u, 22)) {
        printf("Edad actualizada con éxito.\n");
    }
    
    // Intento de asignación inválida
    if (!usuario_establecer_edad(u, -5)) {
        printf("Error: no se admiten edades negativas.\n");
    }
    
    usuario_imprimir(u);
    
    destruir_usuario(u);
    u = NULL;
    return 0;
}
```

---



---

(contratos-modulos)=
## Contratos en Módulos C

El diseño de punteros opacos impone una separación estricta entre interfaz e implementación. Para formalizar esa separación, el **Diseño por Contratos** proporciona el marco conceptual: cada función de la interfaz tiene precondiciones (qué exige del cliente) y poscondiciones (qué garantiza al cliente).

## Introducción

El **Diseño por Contratos** (Design by Contract, DbC) es una metodología formal de desarrollo de software introducida por Bertrand Meyer en el lenguaje Eiffel. Se fundamenta en la metáfora de un contrato legal entre partes: cada componente de software tiene **obligaciones** (precondiciones que debe garantizar el cliente) y **beneficios** (postcondiciones que garantiza el proveedor). Este enfoque transforma el desarrollo de software de una actividad artesanal a una disciplina ingenieril rigurosa.

```{figure} 22/contract_metaphor.svg
:label: fig-metaphor
:align: center
:width: 90%

Metáfora del contrato: cliente y proveedor tienen obligaciones y derechos mutuos, formalizados mediante precondiciones y postcondiciones.
```

:::{important} Beneficios del Diseño por Contratos

1. **Documentación ejecutable**: Los contratos son especificaciones precisas y verificables
2. **Detección temprana de errores**: Violaciones se detectan en el punto exacto de falla
3. **Facilita testing**: Los contratos definen casos de prueba automáticamente
4. **Mejora mantenibilidad**: El comportamiento esperado está explícito
5. **Razonamiento formal**: Permite demostraciones matemáticas de corrección
:::

La formalización mediante Lógica de Primer Orden (LPO) proporciona el rigor matemático necesario para especificar, verificar y razonar sobre la corrección de programas.

## Punteros Opacos en Bibliotecas Estándar

Muchas bibliotecas conocidas usan punteros opacos:

### POSIX: FILE

```{code-block}c
:linenos:
// stdio.h
typedef struct _IO_FILE FILE;

FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);
```

No sabés cómo está implementado `FILE` internamente, pero podés usarlo a través de punteros.

### OpenSSL

```{code-block}c
:linenos:
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;

SSL_CTX *SSL_CTX_new(const SSL_METHOD *method);
SSL *SSL_new(SSL_CTX *ctx);
```

### GTK+ (GUI)

```{code-block}c
:linenos:
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;

GtkWidget *gtk_window_new(GtkWindowType type);
```

Todos estos ejemplos siguen el mismo patrón de puntero opaco.

---

## Buenas Prácticas

### 1. Convenciones de Nombres

```{code-block}c
:linenos:
// Patrón: tipo_t para el tipo, crear_tipo/destruir_tipo para funciones
typedef struct usuario usuario_t;

usuario_t *crear_usuario(const char *nombre, int edad);
void destruir_usuario(usuario_t *u);
```

### 2. Documentación Clara

```{code-block}c
:linenos:
/**
 * Crea una nueva instancia de un usuario.
 * 
 * @param nombre Cadena de caracteres que representa el nombre (no debe ser NULL).
 * @param edad Entero no negativo que representa la edad.
 * @return Puntero al usuario creado, o NULL si falla la asignación de memoria o los parámetros son inválidos.
 */
usuario_t *crear_usuario(const char *nombre, int edad);

/**
 * Destruye al usuario liberando toda la memoria asociada.
 * 
 * @param u Usuario a destruir. Puede ser NULL.
 */
void destruir_usuario(usuario_t *u);
```

### 3. Manejo de Errores Consistente

```{code-block}c
:linenos:
// Retornar NULL en creación si falla
tipo_t *crear_tipo(void) {
    tipo_t *t = malloc(sizeof(*t));
    if (t == NULL) {
        return NULL;  // Indicación clara de fallo al cliente
    }
    // ... inicialización ...
    return t;
}

// Retornar bool en operaciones para reportar éxito o fracaso
bool tipo_operar(tipo_t *t, int dato) {
    if (t == NULL) {
        return false;  // Fallo: puntero inválido
    }
    // ... operación ...
    return true;  // Éxito
}
```

### 4. Tolerancia a NULL

```{code-block}c
:linenos:
void destruir_tipo(tipo_t *t) {
    // Tolerante a NULL - comportamiento similar a free()
    if (t == NULL) {
        return;
    }
    // ... liberación ...
}
```

### 5. Uso de `const` para Intenciones

```{code-block}c
:linenos:
// Solo lectura - no modifica la estructura
double punto_obtener_x(const punto_t *punto);

// Modifica la estructura
void punto_desplazar(punto_t *punto, double dx, double dy);
```

---

## Limitaciones y Consideraciones

### 1. Pérdida de Acceso Directo

No podés acceder directamente a los campos para debugging o inspección rápida en herramientas tradicionales:

```{code-block}c
:linenos:
// En GDB:
(gdb) print punto->x
Cannot access memory at address 0x0: incomplete type
```

**Solución:** Proveer funciones de inspección para debugging si es necesario:
```{code-block}c
:linenos:
#ifdef DEBUG
void punto_debug_print(const punto_t *p);
#endif
```

### 2. No se Puede Alocar en el Stack

```{code-block}c
:linenos:
// Esto NO compila con puntero opaco
punto_t p;  // ERROR: incomplete type

// Debés usar el heap
punto_t *p = crear_punto(3.0, 4.0);
```

**Implicación:** Siempre hay un costo asociado a la alocación dinámica de memoria mediante `malloc` y `free`.

### 3. Dificultad para Copiar

No podés realizar una copia superficial por asignación directa:

```{code-block}c
:linenos:
punto_t copia = *original;  // ERROR: incomplete type
```

**Solución:** Proveer una función de copia explícita (clonación):
```{code-block}c
:linenos:
punto_t *punto_clonar(const punto_t *original);
```

### 4. Compatibilidad con Análisis Estático

Algunas herramientas de análisis estático tienen dificultades para verificar el uso de memoria en tipos incompletos fuera de su archivo de implementación. Asegurate de que Valgrind y las opciones de compilación sanitizer rastreen correctamente todo el ciclo de vida de estas estructuras.

---

## Ejercicios

```{exercise}
:label: ejercicio-opaco-1

Implementá un TAD `cuenta_t` (Cuenta Bancaria) usando punteros opacos con las siguientes operaciones:

- `crear_cuenta(long nro_cuenta, const char *titular, double saldo_inicial)`
- `destruir_cuenta(cuenta)`
- `cuenta_depositar(cuenta, monto)`
- `cuenta_extraer(cuenta, monto)`
- `cuenta_obtener_saldo(cuenta)`
- `cuenta_obtener_titular(cuenta)`

Garantizá que los saldos y depósitos no sean negativos e implementá una validación para evitar extracciones mayores al saldo disponible.
```

```{exercise}
:label: ejercicio-opaco-2

Diseñá un TAD `rectangulo_t` con puntero opaco. Debe soportar:

- `crear_rectangulo(double ancho, double alto)`
- `destruir_rectangulo(rectangulo)`
- `rectangulo_obtener_area(rectangulo)`
- `rectangulo_obtener_perimetro(rectangulo)`
- `rectangulo_redimensionar(rectangulo, nuevo_ancho, nuevo_alto)`

Asegurá mediante invariantes que el ancho y el alto sean siempre mayores a cero.
```

````{exercise}
:label: ejercicio-opaco-3

Convertí la siguiente estructura expuesta a un diseño basado en puntero opaco:

```{code-block}c
:linenos:
// fecha.h - ANTES (expuesta)
typedef struct {
    int dia;
    int mes;
    int anio;
} fecha_t;

void inicializar_fecha(fecha_t *f, int d, int m, int a);
bool es_bisiesto(const fecha_t *f);
```

Rediseñala con puntero opaco y funciones apropiadas de creación, destrucción y acceso.
````

---

## Referencias y Lecturas Complementarias

### Textos Fundamentales

- {cite:t}`hanson_c_1996`. *C Interfaces and Implementations*. Capítulo 1: Interfaces. Tratamiento exhaustivo de punteros opacos y diseño de interfaces.

- {cite:t}`kernighan_c_2014`. *The C Programming Language*. Capítulo 6: Structures. Sección sobre tipos incompletos.

- {cite:t}`king_c_2008`. *C Programming: A Modern Approach*. Capítulo 19: Program Design. Information hiding y modularidad.

### Documentación de Estándares

- **ISO C99 Standard** (6.2.5): Definición formal de tipos incompletos.
- **ISO C11 Standard** (6.7.2.3): Declaraciones de estructuras y tipos opacos.

### Artículos y Recursos

- **"Object-Oriented Programming With ANSI-C"** - Axel-Tobias Schreiner. Uso avanzado de punteros opacos para simular OOP.

- **POSIX API Design Guidelines** - Ejemplos de APIs del sistema que usan punteros opacos extensivamente.

---

## Resumen

Los punteros opacos son una técnica esencial para construir software modular y mantenible en C:

:::{important} Conceptos Clave

**¿Qué es un puntero opaco?**
- Declaración de estructura en `.h` sin definición completa.
- Definición completa solo en `.c`.
- El usuario solo manipula punteros, no la estructura directamente.

**Ventajas:**
1. **Encapsulamiento fuerte:** Imposible acceder a campos internos.
2. **Flexibilidad:** Cambiar la implementación sin romper el código cliente.
3. **Invariantes garantizados:** Solo las funciones del módulo modifican la estructura.
4. **Compatibilidad binaria:** Actualizar la biblioteca sin recompilar las aplicaciones.

**Patrón típico:**
```{code-block}c
:linenos:
// tipo.h
typedef struct tipo tipo_t;
tipo_t *crear_tipo(...);
void destruir_tipo(tipo_t *t);
bool tipo_operacion(tipo_t *t, ...);

// tipo.c
struct tipo {
    // Campos privados
};
```

**Conexiones:**
- Fundamental para implementar TADs (ver [](18_tad)).
- Requiere memoria dinámica (ver {ref}`memoria-dinamica-capitulo`).
- Usado extensivamente en bibliotecas del sistema y APIs públicas.
:::

:::{tip} Cuándo Usar Punteros Opacos
**Usar cuando:**
- Diseñás una API pública o biblioteca.
- Querés ocultar detalles de implementación.
- Necesitás cambiar la implementación sin romper la compatibilidad.
- Implementás un TAD con invariantes estrictos.

**No usar cuando:**
- Usás estructuras simples sin lógica ni invariantes (ej: `punto2d_t {double x, y;}`).
- La performance crítica requiere acceso directo en línea (inlining).
- Se trata de código puramente interno de un módulo que no se expone externamente.
:::

Dominar los punteros opacos es esencial para escribir código C profesional, mantenible y robusto. Es la base del diseño modular en C y el equivalente más cercano al encapsulamiento de la programación orientada a objetos.
