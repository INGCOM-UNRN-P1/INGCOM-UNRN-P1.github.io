---
title: Tipos de Datos Abstractos, Pilas y Colas
short_title: "Estructuras de datos"
subtitle: Estructuras de datos dinámicas y especializadas
---

(capitulo-tad)=
# Resumen de la Unidad

## Introducción



## Desarrollo

(concepto-y-diseno-de-tads)=
### Concepto y Diseño de TADs


(introduccion_TAD)=
#### Introducción

Un **Tipo de Dato Abstracto** (TAD, del inglés *Abstract Data Type*, ADT) es un
modelo matemático que define un conjunto de datos junto con las operaciones que
pueden realizarse sobre ellos, ocultando los detalles de su implementación. El
concepto de TAD es fundamental en la ciencia de la computación porque establece
una separación clara entre **qué** hace una estructura de datos (su interfaz) y
**cómo** lo hace (su implementación).

Esta abstracción permite que el usuario de la estructura se concentre en
resolver problemas de alto nivel sin preocuparse por los detalles internos de
cómo se almacenan o manipulan los datos. Al mismo tiempo, el implementador tiene
la libertad de optimizar o modificar la representación interna sin afectar al
código que utiliza el TAD, siempre que mantenga la misma interfaz pública.

:::{figure} 3/tad_concepto.svg
:label: fig-tad-concepto
:align: center
:width: 80%

Concepto de Tipo de Dato Abstracto (TAD) como barrera de abstracción. El cliente
opera únicamente a través de la interfaz pública, desconociendo la
representación física.

:::
<!-- {figure} 3/tad_concepto.svg -->

(caracteristicas-de-un-tad)=
#### Características de un TAD

Un TAD se caracteriza por tres componentes esenciales:

1. **Representación de datos:** Estructura interna que almacena la información
   (oculta al usuario).
2. **Operaciones:** Conjunto de funciones que manipulan los datos de manera
   controlada.
3. **Axiomas o invariantes:** Propiedades que deben cumplirse en todo momento
   para garantizar la coherencia de la estructura.

(encapsulamiento-y-abstraccion)=
#### Encapsulamiento y Abstracción

El principio de **encapsulamiento** es el pilar que sostiene a la abstracción:
garantiza que los datos internos de un TAD no puedan ser manipulados de manera
directa desde el código cliente. En C, este ocultamiento físico se implementa a
través de la técnica de **punteros opacos**, declarando tipos incompletos en la
cabecera e implementando sus detalles estructurales en el archivo fuente `.c`.

Para un análisis detallado sobre cómo funciona esta técnica a nivel del
compilador, sus restricciones sintácticas y un ejemplo completo de
implementación opaca, consultá el capítulo previo sobre [](2_opacos.md).

:::{important} Interfaz Clara e Invariantes

La abstracción no se reduce a ocultar información; su objetivo es proveer una
interfaz limpia y coherente que proteja las invariantes internas del TAD y
permita su uso de manera intuitiva y segura.

:::
<!-- {important} Interfaz Clara e Invariantes -->

(tad-vs-estructura-de-datos)=
#### TAD vs. Estructura de Datos

- **TAD**: Es un concepto lógico, una **especificación** de comportamiento (el
  "qué").
- **Estructura de Datos**: Es una implementación concreta, una **organización**
  de datos en memoria (el "cómo").

---

(ejemplos-clasicos-de-tipos-de-datos-abstractos)=
#### Ejemplos Clásicos de Tipos de Datos Abstractos

- **Lista (List)**: Colección ordenada y posicionada de elementos.
- **Pila (Stack)**: Colección LIFO (Last-In, First-Out).
- **Cola (Queue)**: Colección FIFO (First-In, First-Out).
- **Cola de Prioridad (Priority Queue)**: Los elementos se extraen según su
  prioridad.
- **Mapa (Map / Diccionario)**: Colección de pares clave-valor únicos.

---

(metodologia-para-el-diseno-de-un-tad-propio)=
#### Metodología para el Diseño de un TAD Propio

Crear un TAD es un ejercicio de diseño centrado en la abstracción. Seguir un
proceso metodológico asegura que el resultado sea robusto, claro y útil.

1. **Conceptualización**: Identificar la entidad a modelar, sus datos y sus
   reglas.
2. **Definición de la Interfaz Pública**: Listar las operaciones, definir sus
   firmas (parámetros, retorno) y documentar su comportamiento (precondiciones,
   poscondiciones).
3. **Especificación Formal (Opcional)**: Definir axiomas que describan cómo
   interactúan las operaciones.
4. **Elección de la Estructura de Datos**: Evaluar candidatos (arreglos, listas,
   árboles) y analizar su complejidad para cada operación de la interfaz.
5. **Implementación**: Escribir el código, encapsulando la estructura de datos
   interna y exponiendo solo la interfaz pública.

---

(asignacion-de-memoria-estatica-vs-dinamica)=
#### Asignación de Memoria: Estática vs. Dinámica

El diseño e implementación de Tipos de Datos Abstractos en C requiere una
gestión rigurosa de la memoria. La elección entre el ciclo de vida automático en
el *stack* (memoria estática) o el ciclo de vida dinámico en el *heap* (memoria
dinámica) define cómo se almacenan, acceden y destruyen los elementos del TAD.

Para un análisis detallado sobre el funcionamiento del stack, consultá la
sección {ref}`la-pila-stack` en el apunte correspondiente. Asimismo, los
detalles operativos de la asignación dinámica, el uso del heap y la gestión de
errores mediante `malloc`, `realloc` y `free` se abordan en profundidad en
{ref}`el-monton-heap` y {ref}`errores-comunes-y-peligros`.

:::{important}

En este apunte se utiliza prioritariamente la asignación dinámica de memoria en
el heap para permitir que las estructuras de datos tengan un tamaño variable y
flexible en tiempo de ejecución. Recordá aplicar siempre las buenas prácticas de
inicialización y liberación de punteros documentadas en
{ref}`resumen-de-buenas-practicas` (reglas {ref}`0x0003h` y {ref}`0x0036h`).

:::
<!-- {important} -->

(ejercicios-de-concepto-y-diseno-de-tads)=
#### Ejercicios de Concepto y Diseño de TADs








(tipificacion-de-acciones)=
### Tipificación de Acciones


Cuando diseñamos un TAD, las operaciones que lo componen no son arbitrarias.
Cada función cumple un **rol específico** en la manipulación de la estructura de
datos. Clasificar estas operaciones según su propósito permite crear interfaces
coherentes y predecibles, facilitando tanto la implementación como el uso del
TAD.

A continuación se presentan las **siete categorías fundamentales** de
operaciones que típicamente conforman un TAD bien diseñado:

(1-constructor)=
#### 1. Constructor

**Propósito:** "Prepara el terreno".

**Función:** Se encarga de la asignación de memoria e inicialización de la
estructura. El constructor establece el estado inicial válido del TAD,
reservando los recursos necesarios y configurando los invariantes básicos.

**Ejemplos:**
:::{code-block}c
:linenos:
int** crear_matriz(int filas, int col);
int* crear_arreglo(int largo);
pila_t* crear_pila(void);
lista_t* crear_lista(void);

:::
<!-- {code-block}c -->

:::{note}

En C, los constructores siempre devuelven un puntero a la estructura recién
creada, o `NULL` si la creación falla (por ejemplo, por falta de memoria). El
llamador es responsable de verificar el resultado antes de usar la estructura.

:::
<!-- {note} -->

(2-selector)=
#### 2. Selector

**Propósito:** "Recupera información".

**Función:** Obtiene un dato específico que está guardado dentro de la
estructura. Los selectores permiten **acceder** al contenido almacenado sin
modificarlo. Son operaciones de solo lectura sobre los datos del usuario.

**Ejemplos:**
:::{code-block}c
:linenos:
int valor = arreglo[i];
int item = obtener(arreglo_t, indice);
int dato = ver_tope(pila);
int primero = frente(cola);

:::
<!-- {code-block}c -->

:::{important}

Los selectores **no modifican** el estado de la estructura. Deben ser
operaciones seguras que puedan invocarse múltiples veces sin efectos
secundarios. En términos de programación funcional, son funciones puras respecto
al estado del TAD.

:::
<!-- {important} -->

(3-consultor)=
#### 3. Consultor

**Propósito:** "Recupera meta-información".

**Función:** Informa sobre alguna **propiedad intrínseca** de la estructura, no
sobre los datos almacenados por el usuario, sino sobre el estado y
características de la estructura misma. Los consultores responden preguntas
sobre la configuración, capacidad o estado actual del TAD.

**Ejemplos:**
:::{code-block}c
:linenos:
size_t tamanio = sizeof(arreglo);
bool vacia = esta_vacia(pila);
bool encontrado = contiene(lista, valor);
int elementos = largo(lista);
size_t capacidad_actual = capacidad(arreglo_dinamico);

:::
<!-- {code-block}c -->

**Diferencia con Selectores:**
- **Selector:** Devuelve un dato del usuario almacenado → `ver_tope(pila)`
  devuelve el elemento en el tope.
- **Consultor:** Devuelve información sobre la estructura → `esta_vacia(pila)`
  informa si hay elementos o no.

(4-iterador)=
#### 4. Iterador

**Propósito:** "Recorre la información".

**Función:** Provee una entidad que permite **procesar los elementos** de la
estructura uno por uno, de manera secuencial, sin exponer la representación
interna. Los iteradores son fundamentales para abstraer el recorrido de
estructuras complejas.

**Ejemplos:**
:::{code-block}c
:linenos:
iterador_t* iter = crear_iterador(lista);
while (tiene_siguiente(iter)) {
    int actual = siguiente(iter);
    // procesar actual
}
destruir_iterador(iter);

// Alternativamente, con callbacks (soporte genérico):
void procesar(void *dato, void *contexto);
recorrer(lista, procesar, contexto);

:::
<!-- {code-block}c -->

:::{tip}

Los iteradores son especialmente útiles cuando la estructura de datos tiene
múltiples formas de recorrido (por ejemplo, un árbol puede recorrerse en
preorden, inorden o postorden). Cada estrategia puede implementarse como un
iterador diferente sin cambiar la estructura subyacente.

:::
<!-- {tip} -->

(5-mutador)=
#### 5. Mutador

**Propósito:** "Modifica la información".

**Función:** Cambia el **estado o los datos** contenidos en la estructura. Los
mutadores son las operaciones de escritura que alteran el contenido gestionado
por el TAD. Deben mantener los invariantes de la estructura.

**Ejemplos:**
:::{code-block}c
:linenos:
arreglo[i] = valor;
bool exito = insertar(lista, val, pos);
bool exito = apilar(pila, dato);
bool exito = encolar(cola, dato);
bool eliminado = remover(conjunto, elemento);
void modificar(matriz, fila, col, nuevo_valor);

:::
<!-- {code-block}c -->

:::{important}

Los mutadores deben garantizar que la estructura permanece en un estado
**válido** después de la operación. Por ejemplo, si una pila tiene un invariante
de que `tope < capacidad`, la operación `apilar` debe verificar esta condición
antes de agregar un elemento, y devolver `false` o redimensionar la estructura
si es necesario.

:::
<!-- {important} -->

(6-conversor)=
#### 6. Conversor

**Propósito:** "Crea una estructura similar".

**Función:** Genera una **nueva estructura** o representación a partir del
contenido de la estructura actual. Los conversores transforman el TAD en otro
formatos, típicamente para interoperabilidad o presentación.

**Ejemplos:**
:::{code-block}c
:linenos:
char* cadena = a_cadena(arreglo, largo);
int* subconjunto = rebanar(arreglo, desde, hasta);
lista_t* sublista = copiar_sublista(lista, inicio, fin);
arreglo_t* arr = lista_a_arreglo(lista);
char* representacion = serializar(estructura);

:::
<!-- {code-block}c -->

:::{note}

Los conversores típicamente **asignan memoria nueva** para el resultado. El
llamador es responsable de liberar estos recursos cuando ya no los necesite.
Esto debe documentarse claramente en la especificación de la función.

:::
<!-- {note} -->

**Diferencia con Selectores:**
- **Selector:** Devuelve una *referencia* a datos existentes → `obtener(arreglo,
  5)` devuelve el elemento en posición 5.
- **Conversor:** Crea una *nueva estructura* con datos derivados →
  `rebanar(arreglo, 2, 5)` crea un nuevo arreglo con copia de elementos 2-5.

(7-destructor)=
#### 7. Destructor

**Propósito:** "Libera los recursos".

**Función:** Se encarga de **liberar la memoria** asignada y otros recursos
externos (archivos, conexiones, etc.) para evitar fugas (*memory leaks*). El
destructor es la operación final en el ciclo de vida de una instancia del TAD.

**Ejemplos:**
:::{code-block}c
:linenos:
void liberar_arreglo(int** arreglo);
void destruir_matriz(int filas, int*** matriz);
void destruir_pila(pila_t** pila);
void destruir_lista(lista_t** lista, void (*destruir_dato)(void*));

:::
<!-- {code-block}c -->

:::{warning} Responsabilidad del Destructor

El destructor debe liberar **recursivamente** toda la memoria asociada con la
estructura. Si el TAD almacena punteros a otras estructuras dinámicas, el
destructor debe liberarlas también, o bien aceptar una función de destrucción
personalizada como parámetro para delegar esa responsabilidad al usuario.

:::
<!-- {warning} Responsabilidad del Destructor -->

**Patrones comunes:**
:::{code-block}c
:linenos:
// Destructor seguro con doble puntero (datos copiados)
void destruir_pila_int(pila_t** pila) {
    if (pila == NULL || *pila == NULL) return;
    free((*pila)->elementos);
    free(*pila);
    *pila = NULL;
}

// Destructor seguro con doble puntero y callback (datos por referencia)
void destruir_lista(lista_t** lista, void (*destruir_dato)(void*)) {
    if (lista == NULL || *lista == NULL) return;
    nodo_t* actual = (*lista)->inicio;
    while (actual) {
        nodo_t* siguiente = actual->siguiente;
        if (destruir_dato != NULL && actual->dato != NULL)
            destruir_dato(actual->dato);
        free(actual);
        actual = siguiente;
    }
    free(*lista);
    *lista = NULL;
}

:::
<!-- {code-block}c -->

(resumen-de-tipificacion)=
#### Resumen de Tipificación

La siguiente tabla resume las siete categorías de operaciones:

| Tipo | Propósito | Modifica Estado | Retorna | Ejemplo |
|------|-----------|-----------------|---------|---------|
| **Constructor** | Prepara el terreno | — | Puntero nuevo | `crear_pila()` |
| **Selector** | Recupera información | ✗ | Dato almacenado | `ver_tope(pila)` |
| **Consultor** | Recupera meta-información | ✗ | Propiedad de la estructura | `esta_vacia(pila)` |
| **Iterador** | Recorre la información | ✗* | Elemento siguiente | `siguiente(iter)` |
| **Mutador** | Modifica la información | ✓ | Estado de éxito | `apilar(pila, dato)` |
| **Conversor** | Crea estructura similar | ✗ | Nueva estructura | `pila_a_arreglo(pila)` |
| **Destructor** | Libera recursos | — | `void` | `destruir_pila(pila)` |

*\* El iterador puede mantener estado interno de posición, pero no modifica la
estructura recorrida.*

:::{tip} Aplicación Práctica

Cuando diseñes un nuevo TAD, usá esta tipificación como lista de verificación:
1. ¿Tengo un constructor que inicializa correctamente?
2. ¿Qué datos necesito seleccionar?
3. ¿Qué propiedades debo consultar?
4. ¿Cómo se recorrerá la estructura?
5. ¿Qué modificaciones son válidas?
6. ¿A qué otros formatos debo convertir?
7. ¿Liberé todos los recursos en el destructor?

Esta clasificación no solo organiza tu código, sino que comunica claramente la
**intención** de cada función a quienes usen tu TAD.

:::
<!-- {tip} Aplicación Práctica -->

(ejercicios-de-tipificacion-de-acciones)=
#### Ejercicios de Tipificación de Acciones








(listas-enlazadas-tad-secuencia)=
### Listas Enlazadas (TAD Secuencia)


Una **secuencia** es una colección ordenada de elementos donde cada elemento
tiene una posición definida. Es uno de los TADs más fundamentales en
programación, ya que representa la idea abstracta de "una serie de cosas en
orden".

(interfaz-del-tad-secuencia)=
#### Interfaz del TAD Secuencia

El TAD Secuencia define las siguientes operaciones esenciales:

- **crear():** Crea una secuencia vacía.
- **insertar_al_inicio(secuencia, elemento):** Agrega un elemento al principio.
- **insertar_al_final(secuencia, elemento):** Agrega un elemento al final.
- **insertar_en_posicion(secuencia, posicion, elemento):** Inserta un elemento
  en una posición específica.
- **eliminar(secuencia, elemento):** Elimina la primera ocurrencia de un
  elemento.
- **buscar(secuencia, elemento):** Busca un elemento y retorna su posición o
  indicador de no encontrado.
- **obtener(secuencia, posicion):** Retorna el elemento en una posición dada.
- **tamanio(secuencia):** Retorna la cantidad de elementos.
- **es_vacia(secuencia):** Verifica si la secuencia está vacía.
- **destruir(secuencia):** Libera todos los recursos asociados.

(multiples-implementaciones)=
#### Múltiples Implementaciones

Lo poderoso de un TAD es que esta misma interfaz puede implementarse de
diferentes maneras, cada una con sus ventajas y desventajas. Las dos
implementaciones más comunes de una secuencia son:

1. **Implementación con arreglo:** Los elementos se almacenan en posiciones
   contiguas de memoria.
2. **Implementación con lista enlazada:** Los elementos se almacenan en nodos
   dispersos, conectados mediante punteros.

:::{note}

La misma interfaz de secuencia puede implementarse con arreglos (memoria
contigua) o con listas enlazadas (nodos dispersos), cada una con diferentes
características de rendimiento.

:::
<!-- {note} -->

:::{important} Poder de la Abstracción

El código que usa una secuencia no necesita saber si está implementada con
arreglos o listas enlazadas. Esto permite cambiar la implementación sin
modificar el código cliente, eligiendo la mejor opción según las necesidades de
rendimiento.

:::
<!-- {important} Poder de la Abstracción -->

(6_tad-comparacion-de-implementaciones)=
#### Comparación de Implementaciones

| Aspecto | Arreglo | Lista Enlazada |
|---------|---------|----------------|
| **Acceso aleatorio** | $O(1)$ directo por índice | $O(n)$ requiere recorrido |
| **Insertar al inicio** | $O(n)$ desplazamiento | $O(1)$ ajustar punteros |
| **Insertar al final** | $O(1)$ si hay espacio* | $O(1)$ o $O(n)$** |
| **Búsqueda** | $O(n)$ recorrido | $O(n)$ recorrido |
| **Memoria** | Contigua, eficiente caché | Dispersa, overhead de punteros |
| **Tamaño** | Fijo o costoso redimensionar | Dinámico, crece según necesidad |

* Si el arreglo está lleno, requiere $O(n)$ para redimensionar.  
** $O(1)$ si se mantiene puntero al final, $O(n)$ si no.

:::{tip} Complejidad Asintótica

Las notaciones $O(1)$, $O(n)$, etc., describen el **comportamiento asintótico**
del tiempo de ejecución. Para entender en profundidad qué significa la notación
Big-O, cómo analizar algoritmos formalmente, y las diferentes notaciones
asintóticas (Omega, Theta), consultá {ref}`capitulo-complejidad`.

:::
<!-- {tip} Complejidad Asintótica -->

(implementacion-de-secuencia-con-listas)=
#### Implementación de Secuencia con Listas

Una **lista enlazada** es una implementación del TAD Secuencia donde los
elementos se almacenan en nodos individuales conectados mediante punteros. A
diferencia de los arreglos, los nodos no necesitan estar en posiciones contiguas
de memoria, lo que permite inserciones y eliminaciones eficientes al inicio.


Esta es una de las estructuras de datos dinámicas más fundamentales y sirve como
base para implementar otros TADs como pilas y colas.

(ventajas-de-las-listas-enlazadas)=
#### Ventajas de las Listas Enlazadas

- **Tamaño dinámico:** Crece y decrece según las necesidades sin
  redimensionamiento.
- **Inserción y eliminación eficientes:** $O(1)$ si tenemos la referencia al
  nodo.
- **No requiere reorganización:** Al insertar o eliminar elementos intermedios.

(desventajas-de-las-listas-enlazadas)=
#### Desventajas de las Listas Enlazadas

- **Acceso secuencial:** No hay acceso directo por índice ($O(n)$).
- **Mayor uso de memoria:** Cada nodo requiere espacio adicional para punteros.
- **Menos eficiente en caché:** La no contigüidad en memoria reduce el
  rendimiento.

:::{note} Implementando la Interfaz de Secuencia

Las operaciones de la lista enlazada implementan directamente las operaciones
del TAD Secuencia. Por ejemplo, `insertar_al_inicio` de la lista corresponde a
la operación abstracta de la secuencia.

:::
<!-- {note} Implementando la Interfaz de Secuencia -->

(lista-enlazada-simple)=
#### Lista Enlazada Simple

En una lista enlazada simple, cada nodo apunta únicamente al siguiente nodo de
la secuencia. El último nodo apunta a `NULL`, indicando el final de la lista.

:::{figure} 3/lista_enlazada_simple.svg
:label: fig-lista-enlazada-simple
:align: center
:width: 85%

Estructura física de una Lista Enlazada Simple en el heap.

:::
<!-- {figure} 3/lista_enlazada_simple.svg -->

##### Estructura de un Nodo

:::{code-block}c
:linenos:
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} nodo_t;

typedef struct lista
{
    nodo_t *inicio;
    size_t tamanio;
} lista_t;

:::
<!-- {code-block}c -->

:::{note}

Observá el uso de `struct nodo *` dentro de la definición de `nodo`. Esto es
válido porque el compilador solo necesita saber que `siguiente` es un puntero,
cuyo tamaño es conocido independientemente del tipo completo de `nodo`.

:::
<!-- {note} -->

:::{tip} Aplicación de {ref}`0x0004h`

Notá el uso de espacios alrededor del operador `*` en las declaraciones de
punteros. Según la regla {ref}`0x0004h`, debe haber un espacio antes y después
de cada operador, lo que incluye el asterisco en declaraciones de punteros.
Además, usamos el sufijo `_t` para todos los tipos definidos mediante `typedef`,
siguiendo las convenciones de C estándar.

:::
<!-- {tip} Aplicación de {ref}`0x0004h` -->

##### Creación de una Lista Vacía

:::{code-block}c
:linenos:
lista_t *crear_lista(void)
{
    lista_t *lista = NULL;
    
    lista = malloc(sizeof(lista_t));
    
    if (lista == NULL)
    {
        return NULL;
    }
    
    lista->inicio = NULL;
    lista->tamanio = 0;
    
    return lista;
}

:::
<!-- {code-block}c -->

:::{tip} Aplicación de {ref}`0x0001h` y {ref}`0x0003h`

El nombre `crear_lista` es descriptivo y refleja claramente la operación que
realiza (regla {ref}`0x0001h`). Evitar nombres genéricos como `crear` o `nueva`.
Además, inicializamos el puntero `lista` a `NULL` antes de asignarle memoria
(regla {ref}`0x0003h`).

:::
<!-- {tip} Aplicación de {ref}`0x0001h` y {ref}`0x0003h` -->

:::{note} Verificación de Asignación

Siempre verificamos que `malloc` no retorne `NULL` antes de usar la memoria
asignada. Este patrón es esencial para escribir código robusto. Para más
detalles sobre manejo de errores en asignación dinámica, consultá
{ref}`malloc-memory-allocation`.

:::
<!-- {note} Verificación de Asignación -->

##### Inserción al Inicio

La inserción al inicio es una operación $O(1)$ porque no requiere recorrer la
lista.

:::{code-block}c
:linenos:
bool insertar_al_inicio(lista_t *lista, int dato)
{
    nodo_t *nuevo = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = lista->inicio;
    
    lista->inicio = nuevo;
    lista->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Inserción al Final

La inserción al final requiere recorrer toda la lista para encontrar el último
nodo ($O(n)$).

:::{code-block}c
:linenos:
bool insertar_al_final(lista_t *lista, int dato)
{
    nodo_t *nuevo = NULL;
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    
    if (lista->inicio == NULL)
    {
        lista->inicio = nuevo;
    }
    else
    {
        actual = lista->inicio;
        
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        
        actual->siguiente = nuevo;
    }
    
    lista->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{important}

Una optimización común es mantener un puntero adicional `fin` en la estructura
`lista_t` que apunte al último nodo, reduciendo la inserción al final a $O(1)$.

:::
<!-- {important} -->

##### Búsqueda

:::{code-block}c
:linenos:
nodo_t *buscar(const lista_t *lista, int dato)
{
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return NULL;
    }
    
    actual = lista->inicio;
    
    while (actual != NULL)
    {
        if (actual->dato == dato)
        {
            return actual;
        }
        
        actual = actual->siguiente;
    }
    
    return NULL;
}

:::
<!-- {code-block}c -->

:::{tip} Aplicación de {ref}`0x0000h` y {ref}`0x0035h`

El uso de `const lista_t *` indica que la función no modifica la lista,
mejorando la claridad del código (regla {ref}`0x0000h`). Además, seguimos la
convención de espaciado de la regla {ref}`0x0004h` con el operador `*`.

:::
<!-- {tip} Aplicación de {ref}`0x0000h` y {ref}`0x0035h` -->

##### Eliminación

La eliminación de un nodo requiere mantener una referencia al nodo anterior para
poder actualizar su puntero `siguiente`.

:::{code-block}c
:linenos:
bool eliminar(lista_t *lista, int dato)
{
    nodo_t *actual = NULL;
    nodo_t *anterior = NULL;
    
    if (lista == NULL || lista->inicio == NULL)
    {
        return false;
    }
    
    actual = lista->inicio;
    anterior = NULL;
    
    while (actual != NULL && actual->dato != dato)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if (actual == NULL)
    {
        return false;
    }
    
    if (anterior == NULL)
    {
        lista->inicio = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
    actual = NULL;
    lista->tamanio--;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{tip} Aplicación de {ref}`0x0036h`

Observá que después de `free(actual)`, asignamos `NULL` al puntero para prevenir
su uso accidental. Aunque en este caso el puntero está a punto de salir de
ámbito, es una buena práctica que previene errores.

:::
<!-- {tip} Aplicación de {ref}`0x0036h` -->

##### Recorrido

:::{code-block}c
:linenos:
void imprimir_lista(const lista_t *lista)
{
    nodo_t *actual = NULL;
    
    if (lista == NULL)
    {
        return;
    }
    
    actual = lista->inicio;
    
    printf("Lista: ");
    
    while (actual != NULL)
    {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    
    printf("\n");
}

:::
<!-- {code-block}c -->

##### Destrucción de la Lista

Es fundamental liberar toda la memoria asignada para evitar fugas.

:::{code-block}c
:linenos:
void destruir_lista(lista_t *lista)
{
    nodo_t *actual = NULL;
    nodo_t *siguiente = NULL;
    
    if (lista == NULL)
    {
        return;
    }
    
    actual = lista->inicio;
    
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
    lista = NULL;
}

:::
<!-- {code-block}c -->

:::{warning}

Nunca accedas a un nodo después de haberlo liberado con `free`. Por eso
guardamos `siguiente` antes de liberar `actual`. Este es un error común que
puede causar comportamiento indefinido. Para más información sobre este y otros
errores relacionados con memoria, consultá {ref}`errores-comunes-y-peligros`.

:::
<!-- {warning} -->

:::{important} Gestión de Memoria en TADs

La destrucción apropiada de estructuras de datos es crítica para evitar fugas de
memoria. Observá el patrón: primero liberamos todos los nodos recursivamente, y
finalmente liberamos la estructura contenedora. Para más detalles sobre patrones
de liberación y técnicas avanzadas, consultá {ref}`capitulo-memoria-dinamica`.

:::
<!-- {important} Gestión de Memoria en TADs -->

:::{figure} 3/lista_operaciones.svg
:label: fig-lista-operaciones
:align: center
:width: 90%

Operaciones lógicas de inserción y remoción de nodos en una Lista Enlazada.

:::
<!-- {figure} 3/lista_operaciones.svg -->

(lista-doblemente-enlazada)=
#### Lista Doblemente Enlazada

Una lista doblemente enlazada extiende la lista simple agregando un puntero
adicional en cada nodo que apunta al nodo anterior. Esto permite el recorrido
bidireccional de la lista.

:::{figure} 3/lista_enlazada_doble.svg
:label: fig-lista-enlazada-doble
:align: center
:width: 85%

Estructura física de una Lista Doblemente Enlazada. Cada nodo almacena punteros
a su predecesor y a su sucesor.

:::
<!-- {figure} 3/lista_enlazada_doble.svg -->

##### Estructura

:::{code-block}c
:linenos:
typedef struct nodo_doble
{
    int dato;
    struct nodo_doble *anterior;
    struct nodo_doble *siguiente;
} nodo_doble_t;

typedef struct lista_doble
{
    nodo_doble_t *inicio;
    nodo_doble_t *fin;
    size_t tamanio;
} lista_doble_t;

:::
<!-- {code-block}c -->

##### Ventajas sobre la Lista Simple

- **Recorrido bidireccional:** Se puede recorrer en ambas direcciones.
- **Eliminación más eficiente:** Si tenemos un puntero al nodo, podemos
  eliminarlo sin necesidad de buscar el nodo anterior.
- **Inserción antes de un nodo:** Podemos insertar antes de un nodo dado sin
  recorrer la lista.

##### Desventajas

- **Mayor uso de memoria:** Cada nodo requiere un puntero adicional.
- **Mayor complejidad:** Más punteros que actualizar en cada operación.

##### Inserción al Inicio

:::{code-block}c
:linenos:
bool insertar_al_inicio_doble(lista_doble_t *lista, int dato)
{
    nodo_doble_t *nuevo = NULL;
    
    if (lista == NULL)
    {
        return false;
    }
    
    nuevo = malloc(sizeof(nodo_doble_t));
    
    if (nuevo == NULL)
    {
        return false;
    }
    
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = lista->inicio;
    
    if (lista->inicio != NULL)
    {
        lista->inicio->anterior = nuevo;
    }
    else
    {
        lista->fin = nuevo;
    }
    
    lista->inicio = nuevo;
    lista->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Eliminación de un Nodo

La ventaja principal es que si tenemos un puntero al nodo a eliminar, podemos
hacerlo sin buscar el nodo anterior.

:::{code-block}c
:linenos:
bool eliminar_nodo_doble(lista_doble_t *lista, nodo_doble_t *nodo)
{
    if (lista == NULL || nodo == NULL)
    {
        return false;
    }
    
    // Actualizar el puntero siguiente del nodo anterior
    if (nodo->anterior != NULL)
    {
        nodo->anterior->siguiente = nodo->siguiente;
    }
    else
    {
        // El nodo es el primero
        lista->inicio = nodo->siguiente;
    }
    
    // Actualizar el puntero anterior del nodo siguiente
    if (nodo->siguiente != NULL)
    {
        nodo->siguiente->anterior = nodo->anterior;
    }
    else
    {
        // El nodo es el último
        lista->fin = nodo->anterior;
    }
    
    free(nodo);
    lista->tamanio--;
    
    return true;
}

:::
<!-- {code-block}c -->

:::{tip} Aplicación de {ref}`0x0000h`

Observá cómo la estructura del código refleja claramente la lógica: primero se
actualizan los punteros de los nodos adyacentes, luego se libera el nodo. Esta
organización facilita la comprensión.

:::
<!-- {tip} Aplicación de {ref}`0x0000h` -->

(lista-circular)=
#### Lista Circular

Una **lista circular** es una variante donde el último nodo apunta de nuevo al
primero, formando un ciclo. Puede ser simple o doblemente enlazada. Son útiles
en aplicaciones que requieren procesamiento cíclico, como buffers circulares o
sistemas round-robin.

(ejercicios-de-listas-enlazadas)=
#### Ejercicios de Listas Enlazadas








(arreglos-dinamicos-tad-secuencia)=
### Arreglos Dinámicos (TAD Secuencia)



Para demostrar el poder de la abstracción del TAD, presentamos ahora una
implementación alternativa del TAD Secuencia utilizando arreglos en lugar de
listas enlazadas. Esta implementación ofrece diferentes características de
rendimiento, pero mantiene la misma interfaz conceptual.

(secuencia-con-arreglo-dinamico)=
#### Secuencia con Arreglo Dinámico

Un arreglo dinámico combina las ventajas del acceso aleatorio de los arreglos
con la flexibilidad de tamaño de las estructuras dinámicas.

:::{code-block}c
:linenos:
typedef struct secuencia_arreglo
{
    int *elementos;
    size_t tamanio;
    size_t capacidad;
} secuencia_arreglo_t;

:::
<!-- {code-block}c -->

:::{note} Campos de la Estructura

- `elementos`: Puntero al arreglo dinámico que almacena los datos.
- `tamanio`: Cantidad actual de elementos en la secuencia.
- `capacidad`: Espacio total asignado (puede ser mayor que `tamanio`).

:::
<!-- {note} Campos de la Estructura -->

##### Creación de una Secuencia con Arreglo

:::{code-block}c
:linenos:
#define CAPACIDAD_INICIAL 10

secuencia_arreglo_t *crear_secuencia_arreglo(void)
{
    secuencia_arreglo_t *sec = NULL;
    
    sec = malloc(sizeof(secuencia_arreglo_t));
    
    if (sec == NULL)
    {
        return NULL;
    }
    
    sec->elementos = malloc(CAPACIDAD_INICIAL * sizeof(int));
    
    if (sec->elementos == NULL)
    {
        free(sec);
        return NULL;
    }
    
    sec->tamanio = 0;
    sec->capacidad = CAPACIDAD_INICIAL;
    
    return sec;
}

:::
<!-- {code-block}c -->

##### Redimensionamiento Automático

Cuando la capacidad se agota, el arreglo debe redimensionarse. Una estrategia
común es duplicar la capacidad:

:::{code-block}c
:linenos:
bool redimensionar(secuencia_arreglo_t *sec)
{
    size_t nueva_capacidad = 0;
    int *nuevo_arreglo = NULL;
    
    if (sec == NULL)
    {
        return false;
    }
    
    nueva_capacidad = sec->capacidad * 2;
    nuevo_arreglo = realloc(sec->elementos, nueva_capacidad * sizeof(int));
    
    if (nuevo_arreglo == NULL)
    {
        return false;
    }
    
    sec->elementos = nuevo_arreglo;
    sec->capacidad = nueva_capacidad;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Insertar al Final

:::{code-block}c
:linenos:
bool insertar_al_final_arreglo(secuencia_arreglo_t *sec, int dato)
{
    if (sec == NULL)
    {
        return false;
    }
    
    if (sec->tamanio >= sec->capacidad)
    {
        if (!redimensionar(sec))
        {
            return false;
        }
    }
    
    sec->elementos[sec->tamanio] = dato;
    sec->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Acceso por Índice

Esta es la operación donde los arreglos brillan: acceso $O(1)$.

:::{code-block}c
:linenos:
bool obtener_elemento(const secuencia_arreglo_t *sec, size_t indice, int *dato)
{
    if (sec == NULL || dato == NULL || indice >= sec->tamanio)
    {
        return false;
    }
    
    *dato = sec->elementos[indice];
    
    return true;
}

:::
<!-- {code-block}c -->

##### Insertar en Posición Específica

Requiere desplazar elementos, resultando en $O(n)$.

:::{code-block}c
:linenos:
bool insertar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos, int
dato)
{
    size_t i = 0;
    
    if (sec == NULL || pos > sec->tamanio)
    {
        return false;
    }
    
    if (sec->tamanio >= sec->capacidad)
    {
        if (!redimensionar(sec))
        {
            return false;
        }
    }
    
    for (i = sec->tamanio; i > pos; i--)
    {
        sec->elementos[i] = sec->elementos[i - 1];
    }
    
    sec->elementos[pos] = dato;
    sec->tamanio++;
    
    return true;
}

:::
<!-- {code-block}c -->

##### Destruir la Secuencia

:::{code-block}c
:linenos:
void destruir_secuencia_arreglo(secuencia_arreglo_t **sec)
{
    if (sec == NULL || *sec == NULL)
    {
        return;
    }
    
    free((*sec)->elementos);
    (*sec)->elementos = NULL;
    free(*sec);
    *sec = NULL;
}

:::
<!-- {code-block}c -->

(comparacion-arreglo-vs-lista-enlazada-como-secuencia)=
#### Comparación: Arreglo vs Lista Enlazada como Secuencia

Ahora que hemos visto ambas implementaciones del TAD Secuencia, podemos
compararlas directamente:

| Operación | Secuencia con Arreglo | Secuencia con Lista |
|-----------|----------------------|---------------------|
| `obtener(posicion)` | $O(1)$ | $O(n)$ |
| `insertar_al_inicio(dato)` | $O(n)$ | $O(1)$ |
| `insertar_al_final(dato)` | $O(1)$ amortizado* | $O(1)$ o $O(n)$** |
| `insertar_en_posicion(pos, dato)` | $O(n)$ | $O(n)$ |
| `buscar(dato)` | $O(n)$ | $O(n)$ |
| `eliminar(dato)` | $O(n)$ | $O(n)$ |

* $O(1)$ en promedio, pero ocasionalmente $O(n)$ cuando se redimensiona.  
** $O(1)$ si se mantiene puntero al final, $O(n)$ si no.

:::{note} Análisis de Complejidad

Esta tabla muestra las complejidades temporales en notación Big-O, que describe
el **peor caso** del algoritmo. Para realizar análisis formal de algoritmos,
consultá {ref}`capitulo-complejidad`.

:::
<!-- {note} Análisis de Complejidad -->

:::{important} Eligiendo la Implementación Correcta

- **Usá arreglos** cuando necesitás acceso aleatorio frecuente o querés
  aprovechar la localidad de caché.
- **Usá listas enlazadas** cuando las inserciones/eliminaciones al inicio sean
  frecuentes o el tamaño varíe mucho.
- **Ambas son válidas** implementaciones del mismo TAD Secuencia, demostrando el
  poder de la abstracción.

:::
<!-- {important} Eligiendo la Implementación Correcta -->

:::{tip} El Patrón Strategy

Esta separación entre interfaz e implementación es un ejemplo del patrón de
diseño **Strategy**. El código cliente puede trabajar con "secuencias" sin
importar la implementación subyacente, permitiendo optimizar según el caso de
uso.

:::
<!-- {tip} El Patrón Strategy -->

(complejidad-temporal-de-las-operaciones)=
#### Complejidad Temporal de las Operaciones

La eficiencia de las operaciones es un criterio fundamental al elegir una
estructura de datos:

| Operación | Lista Simple | Lista Doble |
|-----------|--------------|-------------|
| Insertar al inicio | $O(1)$ | $O(1)$ |
| Insertar al final | $O(n)$ o $O(1)$* | $O(1)$ |
| Eliminar al inicio | $O(1)$ | $O(1)$ |
| Eliminar al final | $O(n)$ | $O(1)$ |
| Buscar elemento | $O(n)$ | $O(n)$ |
| Acceso por índice | $O(n)$ | $O(n)$ |

\* $O(1)$ si se mantiene un puntero al final.

:::{important}

La notación Big-O describe el comportamiento asintótico en el peor caso. En
casos promedio o con estructuras auxiliares, las complejidades pueden variar.
Para un análisis formal y riguroso del análisis asintótico, incluyendo las
notaciones Omega ($\Omega$) y Theta ($\Theta$), consultá
{ref}`capitulo-complejidad`.

:::
<!-- {important} -->

(comparacion-arreglos-vs-listas-enlazadas-como-secuencias)=
#### Comparación: Arreglos vs. Listas Enlazadas como Secuencias

Ya hemos visto en detalle cómo tanto los arreglos dinámicos como las listas
enlazadas pueden implementar el TAD Secuencia. Esta tabla resume las diferencias
clave entre ambas implementaciones:

| Característica | Arreglos Dinámicos | Listas Enlazadas |
|----------------|-------------------|------------------|
| Tamaño | Redimensionable (costo amortizado) | Dinámico sin redimensionamiento |
| Acceso por índice | $O(1)$ | $O(n)$ |
| Inserción al inicio | $O(n)$ (desplazamiento) | $O(1)$ |
| Inserción al final | $O(1)$ amortizado | $O(1)$ o $O(n)$ |
| Uso de memoria | Contiguo, eficiente en caché | Disperso, overhead por punteros |
| Fragmentación | No sufre | Puede fragmentar el heap |
| Mejor caso de uso | Acceso aleatorio frecuente | Inserciones/eliminaciones frecuentes |

:::{note} Consideraciones de Rendimiento

La elección entre arreglos y listas enlazadas tiene profundas implicaciones de
rendimiento más allá de la complejidad algorítmica. Los arreglos tienen mejor
localidad de memoria, lo que resulta en mejor uso del caché del procesador. Las
listas enlazadas, al tener nodos dispersos en memoria, sufren más penalizaciones
por accesos a memoria. Para un análisis detallado del impacto del caché y la
localidad de memoria, consultá {ref}`jerarquia-de-memoria-y-cache`.

Para ver implementaciones concretas de ambas aproximaciones, consultá las
secciones anteriores sobre "Listas Enlazadas: Implementación de Secuencia" y
"Arreglos: Implementación Alternativa de Secuencia".

:::
<!-- {note} Consideraciones de Rendimiento -->

:::{important} El Poder de la Abstracción

El concepto clave aquí es que **ambas estructuras implementan el mismo TAD
Secuencia**. El código que utiliza una secuencia puede ser escrito de forma
genérica, permitiendo cambiar entre implementaciones según las necesidades de
rendimiento específicas sin reescribir la lógica de negocio.

:::
<!-- {important} El Poder de la Abstracción -->

(ejercicios-de-arreglos-dinamicos)=
#### Ejercicios de Arreglos Dinámicos









(genericidad-y-callbacks)=
### Genericidad y Callbacks


(consideraciones-de-implementacion)=
#### Consideraciones de Implementación


(manejo-de-errores)=
#### Manejo de Errores

En C no existen excepciones nativas, por lo que el manejo de errores debe
realizarse mediante códigos de retorno o valores especiales. Las convenciones
comunes incluyen:

- Retornar `bool` para indicar éxito (`true`) o fracaso (`false`).
- Retornar punteros: `NULL` indica error.
- Usar parámetros de salida para retornar datos cuando el valor de retorno se
  usa para el estado.

:::{tip} Aplicación de {ref}`0x0035h` y {ref}`0x0036h`

Documentá exhaustivamente la interfaz pública de tu TAD, especificando el
comportamiento ante casos de error, condiciones previas y posteriores de cada
función.

:::
<!-- {tip} Aplicación de {ref}`0x0035h` y {ref}`0x0036h` -->

(invariantes)=
#### Invariantes

Un **invariante** es una propiedad que siempre debe ser verdadera en una
estructura de datos bien formada. Por ejemplo:

- En una lista: si `inicio == NULL`, entonces `tamanio == 0`.
- En una secuencia con arreglo: `tamanio <= capacidad`.

Mantener estos invariantes es responsabilidad de las funciones de manipulación
del TAD.

(seguridad-y-robustez)=
#### Seguridad y Robustez

:::{code-block}c
:linenos:
bool operacion_segura(estructura_t *est, int dato)
{
    if (est == NULL)
    {
        fprintf(stderr, "Error: estructura NULL en operacion_segura\n");
        return false;
    }
    
    return true;
}

:::
<!-- {code-block}c -->

:::{warning}

La programación defensiva es especialmente importante en TADs porque el usuario
no puede ver la implementación interna. Cada función pública debe validar sus
precondiciones.

:::
<!-- {warning} -->

:::{note} Validación y Depuración

Para técnicas avanzadas de validación y depuración de errores relacionados con
memoria en estructuras dinámicas, consultá [Capítulo: Memoria Dinámica — sección
Valgrind](1_memoria_dinamica.md). Herramientas como Valgrind son invaluables
para detectar fugas de memoria y accesos inválidos en TADs complejos.

:::
<!-- {note} Validación y Depuración -->

(introduccion-a-la-genericidad)=
#### Introducción a la Genericidad


En los ejemplos anteriores, diseñamos estructuras que almacenan un tipo de dato
específico (como enteros `int`). Sin embargo, en el desarrollo real de software
a menudo necesitás estructuras reutilizables que puedan almacenar *cualquier*
tipo de información (números reales, caracteres, structs personalizadas, etc.).
Para lograr esto en C estándar sin tener que duplicar el código, se recurre a la
**genericidad elemental** utilizando punteros genéricos `void*` y **funciones
callback**.

(genericidad-con-void)=
#### Genericidad con `void*`

Un puntero a `void` (`void*`) es un puntero especial que puede almacenar la
dirección de cualquier objeto, sin importar su tipo. En C, podés convertir
cualquier puntero a `void*` y viceversa sin necesidad de un cast explícito.

Al diseñar un TAD genérico, la representación de datos interna no guarda el
valor directamente, sino un puntero `void*` que apunta a la dirección de memoria
donde se encuentra el dato real.

:::{warning} Pérdida de Seguridad de Tipos

El compilador no puede verificar a qué tipo de dato apunta un `void*`. Tampoco
podés desreferenciar un puntero `void*` directamente (`*ptr`), ni realizar
aritmética de punteros con él, ya que su tamaño asociado es desconocido. Es tu
responsabilidad como programador recordar el tipo subyacente y realizar la
conversión correspondiente cuando extraigas el dato.

:::
<!-- {warning} Pérdida de Seguridad de Tipos -->

(funciones-callback)=
#### Funciones Callback

Como el TAD genérico maneja direcciones a ciegas (`void*`), no sabe cómo
comparar los elementos, cómo imprimirlos o cómo destruirlos de forma segura.
Para solucionar esto, el TAD delega estas tareas al código cliente mediante
**punteros a funciones** o **callbacks**.

Una función callback es una función escrita por el programador cliente que se
pasa como argumento a las funciones del TAD para que este la ejecute en momentos
específicos de su ciclo de vida (por ejemplo, al liberar los datos en el
destructor o al buscar un elemento).

##### Estructura de un TAD Genérico

Veamos cómo se define una lista enlazada simple genérica:

:::{code-block}c
:linenos:
typedef struct nodo_generico
{
    void *dato;                    /* Puntero al dato de usuario */
    struct nodo_generico *siguiente;
} nodo_generico_t;

typedef struct lista_generica
{
    nodo_generico_t *inicio;
    size_t tamanio;
} lista_generica_t;

:::
<!-- {code-block}c -->

##### Implementación del Destructor Genérico con Callback

Para destruir la lista y liberar la memoria de manera segura, el TAD no puede
simplemente invocar `free(nodo->dato)`, porque el dato podría ser una estructura
compleja que requiera liberar sus propios campos internos. Por ende, recibimos
un callback de destrucción:

:::{code-block}c
:linenos:
/* Firma de la función callback de destrucción */
typedef void (*destruir_dato_fn)(void *);

void destruir_lista_generica(lista_generica_t **lista, destruir_dato_fn
destruir_dato)
{
    if (lista == NULL || *lista == NULL)
    {
        return;
    }
    
    nodo_generico_t *actual = (*lista)->inicio;
    while (actual != NULL) /* Lazo de liberación */
    {
        nodo_generico_t *siguiente = actual->siguiente;
        
        if (destruir_dato != NULL && actual->dato != NULL)
        {
            destruir_dato(actual->dato);
        }
        
        free(actual);
        actual = siguiente;
    }
    
    free(*lista);
    *lista = NULL;
}

:::
<!-- {code-block}c -->

##### Ejemplo de Uso del Cliente

Imaginemos que queremos almacenar una estructura `persona_t` en nuestra lista
genérica:

:::{code-block}c
:linenos:
typedef struct
{
    char *nombre;
    int edad;
} persona_t;

/* Callback personalizado para destruir una persona */
void destruir_persona(void *ptr)
{
    if (ptr == NULL) return;
    persona_t *p = (persona_t *)ptr;
    free(p->nombre); /* Liberamos el recurso interno */
    free(p);         /* Liberamos el struct */
}

/* En el programa principal: */
int main(void)
{
    lista_generica_t *mi_lista = crear_lista_generica();
    
    persona_t *juan = malloc(sizeof(persona_t));
    if (juan != NULL)
    {
        juan->nombre = malloc(strlen("Juan") + 1);
        if (juan->nombre != NULL)
        {
            strcpy(juan->nombre, "Juan");
        }
        juan->edad = 20;
    }
    
    /* Insertamos pasándolo como void* */
    insertar_al_inicio_generico(mi_lista, juan);
    
    /* ... procesamos la lista ... */
    
    /* Al finalizar, destruimos la lista delegando la liberación */
    destruir_lista_generica(&mi_lista, destruir_persona);
    
    return 0;
}

:::
<!-- {code-block}c -->

(callbacks-de-comparacion)=
#### Callbacks de Comparación

En colecciones genéricas (`void*`), el tipo de dato subyacente es desconocido
por la estructura. Por lo tanto, operaciones que dependen del valor de los
elementos (como la búsqueda de un elemento específico, el ordenamiento o la
inserción ordenada) no pueden realizarse con los operadores tradicionales (`==`,
`<`, `>`).

Para resolver esto, delegamos la lógica de comparación al cliente a través de un
**callback de comparación** (`comparar_fn`).

##### Definición del Tipo
El callback sigue la firma estándar de funciones de comparación (como `strcmp` o
la de `qsort` en `<stdlib.h>`):

:::{code-block}c
:linenos:
typedef int (*comparar_fn)(const void *a, const void *b);

:::
<!-- {code-block}c -->

Esta función debe recibir dos punteros genéricos constantes y retornar:
* Un valor **menor a cero** si el primer elemento es menor que el segundo.
* **Cero** si ambos elementos son equivalentes.
* Un valor **mayor a cero** si el primer elemento es mayor que el segundo.

##### Ejemplo Práctico: Búsqueda Genérica
A continuación se presenta cómo el módulo de la lista genérica implementa la
búsqueda secuencial, y cómo el código cliente la consume.

**En la biblioteca (`lista_generica.c`):**
:::{code-block}c
:linenos:
void *lista_buscar_generica(const lista_generica_t *lista, const void *clave,
comparar_fn comparar) {
    if (lista == NULL || comparar == NULL) {
        return NULL;
    }
    
    nodo_generico_t *actual = lista->inicio;
    // Recorremos la lista con un lazo buscando coincidencia
    while (actual != NULL) {
        if (comparar(actual->dato, clave) == 0) {
            return actual->dato; // Retorna el dato coincidente hallado
        }
        actual = actual->siguiente;
    }
    
    return NULL; // No encontrado
}

:::
<!-- {code-block}c -->

**En el programa cliente (`main.c`):**
:::{code-block}c
:linenos:
// Callback de comparación personalizado para el tipo persona_t
int comparar_personas_por_nombre(const void *a, const void *b) {
    const persona_t *p1 = (const persona_t *)a;
    const char *nombre_buscado = (const char *)b;
    return strcmp(p1->nombre, nombre_buscado);
}

int main(void) {
    // ... supongamos que la lista ya está creada y poblada con personas ...
    
    const char *buscar_nombre = "Juan";
    persona_t *encontrado = (persona_t *)lista_buscar_generica(
        mi_lista, 
        buscar_nombre, 
        comparar_personas_por_nombre
    );
    
    if (encontrado != NULL) {
        printf("Persona hallada: %s, edad: %d\n", encontrado->nombre,
        encontrado->edad);
    } else {
        printf("Persona '%s' no encontrada.\n", buscar_nombre);
    }
    
    // ... destruir lista ...
    return 0;
}

:::
<!-- {code-block}c -->

(ejercicios-de-genericidad-y-callbacks)=
#### Ejercicios de Genericidad y Callbacks

## Ejercicios de Autoevaluación

:::{exercise}
:label: ejercicio-tad-punto-interfaz

Diseñá la interfaz pública (`punto.h`) de un Tipo de Dato Abstracto `punto_t`
que represente un punto en el plano cartesiano bidimensional. El diseño debe
cumplir estrictamente con el principio de ocultamiento de la información
utilizando un puntero opaco. Definí las firmas para las siguientes operaciones
elementales:
1. Crear un punto a partir de sus coordenadas $(x, y)$.
2. Obtener la coordenada $x$.
3. Obtener la coordenada $y$.
4. Calcular la distancia euclídea entre dos puntos.
5. Modificar las coordenadas del punto.
6. Destruir el punto liberando su memoria.

:::
<!-- {exercise} -->

:::{solution} ejercicio-tad-punto-interfaz
:class: dropdown

La interfaz pública en el archivo de cabecera `punto.h` debe declarar el tipo de
forma incompleta para actuar como puntero opaco, ocultando la estructura interna
al código cliente:

```{code-block} c
:linenos:
#ifndef PUNTO_H
#define PUNTO_H

#include <stdbool.h>

/* Declaración incompleta del tipo. La estructura se define en punto.c */
typedef struct punto punto_t;

/* 
 * Constructor: Crea un nuevo punto en el heap.
 * Retorna un puntero al punto creado o NULL si falla la asignación de memoria.
 */
punto_t *punto_crear(double x, double y);

/*
 * Selectores: Retornan las coordenadas del punto.
 * Precondición: el punto no debe ser NULL.
 */
double punto_obtener_x(const punto_t *punto);
double punto_obtener_y(const punto_t *punto);

/*
 * Consultor: Calcula la distancia euclídea entre p1 y p2.
 * Precondición: ambos puntos deben ser válidos (no NULL).
 */
double punto_distancia(const punto_t *p1, const punto_t *p2);

/*
 * Mutador: Modifica las coordenadas del punto.
 * Retorna true si la operación fue exitosa, o false si el punto es NULL.
 */
bool punto_modificar(punto_t *punto, double nuevo_x, double nuevo_y);

/*
 * Destructor: Libera toda la memoria asociada al punto.
 */
void punto_destruir(punto_t **punto);

#endif /* PUNTO_H */

```
<!-- {code-block} c -->
<!-- c -->

:::
<!-- {solution} ejercicio-tad-punto-interfaz -->

:::{exercise}
:label: ejercicio-tad-fraccion

Siguiendo la metodología de diseño de TADs, escribí el archivo de cabecera
(`fraccion.h`) para representar números racionales (`fraccion_t`). Asegurá que
las fracciones se mantengan siempre en su forma irreducible (invariante del TAD)
tras realizar cualquier operación. Definí las operaciones básicas de creación,
suma, y conversión a número en punto flotante (`double`).

:::
<!-- {exercise} -->

:::{solution} ejercicio-tad-fraccion
:class: dropdown

El archivo `fraccion.h` define la interfaz. Para asegurar el invariante de que
toda fracción esté simplificada, la implementación del constructor y de los
mutadores debe calcular el máximo común divisor (MCD) y dividir los términos por
este valor.

```{code-block} c
:linenos:
#ifndef FRACCION_H
#define FRACCION_H

#include <stdbool.h>

/* Tipo de dato abstracto fraccion_t como puntero opaco */
typedef struct fraccion fraccion_t;

/* 
 * Constructor: Crea una fracción simplificada en el heap.
 * Precondición: el denominador no debe ser cero.
 * Retorna NULL si el denominador es cero o si falla la memoria.
 */
fraccion_t *fraccion_crear(int numerador, int denominador);

/*
 * Mutador: Suma dos fracciones y retorna una nueva fracción simplificada.
 * Retorna NULL en caso de error de memoria.
 */
fraccion_t *fraccion_sumar(const fraccion_t *f1, const fraccion_t *f2);

/*
 * Conversor: Devuelve el valor decimal equivalente de la fracción.
 */
double fraccion_a_decimal(const fraccion_t *fraccion);

/*
 * Destructor: Libera la memoria de la fracción.
 */
void fraccion_destruir(fraccion_t **fraccion);

#endif /* FRACCION_H */

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-tad-fraccion -->

:::{exercise}
:label: ejercicio-tad-fecha-invariantes

Identificá y describí formalmente los invariantes de representación de un TAD
`fecha_t` que almacena de manera privada el día, el mes y el año como números
enteros. Explicá cómo influye la existencia de años bisiestos en la validación
de estos invariantes y qué papel juegan las funciones de interfaz en su
preservación.

:::
<!-- {exercise} -->

:::{solution} ejercicio-tad-fecha-invariantes
:class: dropdown

Los invariantes de representación son propiedades lógicas que deben mantenerse
verdaderas durante todo el ciclo de vida de la estructura. Para el TAD
`fecha_t`, definido de forma interna como:

``` c
struct fecha {
    int dia;
    int mes;
    int anio;
};
```
<!-- c -->

Los invariantes formales son:
1. $1 \le \text{mes} \le 12$.
2. $\text{anio} \ne 0$ (si se asume la inexistencia del año cero en el
   calendario gregoriano).
3. $1 \le \text{dia} \le \text{dias\_del\_mes(mes, anio)}$, donde:
   - Para meses 1, 3, 5, 7, 8, 10 y 12: el límite es 31.
   - Para meses 4, 6, 9 y 11: el límite es 30.
   - Para el mes 2 (febrero): el límite es 29 si el año es bisiesto, y 28 en
     caso contrario.

**Influencia de los años bisiestos:**
Un año es bisiesto si es divisible por 4 pero no por 100, excepto que sea
divisible por 400. La función interna de validación debe computar esta regla
para asegurar que fechas como el 29 de febrero de 2024 sean válidas, pero el 29
de febrero de 2023 no lo sea.

**Preservación de los invariantes:**
- **Constructores y Mutadores:** Son las únicas operaciones que pueden modificar
  el estado. Tienen la obligación de validar rigurosamente los parámetros
  recibidos antes de realizar cualquier asignación. Si los datos violan las
  reglas, la operación debe abortarse retornando un error (por ejemplo, `NULL` o
  `false`).
- **Selectores y Consultores:** Al ser de solo lectura, no pueden violar los
  invariantes, pero confían en que se mantuvieron válidos previamente.

:::
<!-- {solution} ejercicio-tad-fecha-invariantes -->

:::{exercise}
:label: ejercicio-tipificacion-firmas

Dada la interfaz de un TAD `conjunto_t` que almacena valores enteros únicos,
clasificá cada una de las siguientes firmas de función en una de las siete
categorías de tipificación de acciones (Constructor, Selector, Consultor,
Iterador, Mutador, Conversor, Destructor):

```{code-block} c
:linenos:
conjunto_t *conjunto_crear(void);
bool conjunto_insertar(conjunto_t *c, int elemento);
bool conjunto_pertenece(const conjunto_t *c, int elemento);
size_t conjunto_cardinalidad(const conjunto_t *c);
int *conjunto_a_arreglo(const conjunto_t *c, size_t *tam);
void conjunto_destruir(conjunto_t **c);
conjunto_iter_t *conjunto_iter_crear(const conjunto_t *c);

```
<!-- {code-block} c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-tipificacion-firmas
:class: dropdown

La clasificación correspondiente es:

1. `conjunto_crear`: **Constructor**. Reserva memoria e inicializa un nuevo
   conjunto vacío.
2. `conjunto_insertar`: **Mutador**. Modifica el estado del conjunto agregando
   un elemento.
3. `conjunto_pertenece`: **Selector**. Recupera información interna buscando la
   presencia del elemento en la estructura sin modificarla.
4. `conjunto_cardinalidad`: **Consultor**. Retorna meta-información sobre la
   estructura (la cantidad total de elementos que contiene).
5. `conjunto_a_arreglo`: **Conversor**. Crea y retorna una nueva estructura (un
   arreglo dinámico en el heap) con el contenido del conjunto. El cliente debe
   liberar el arreglo generado.
6. `conjunto_destruir`: **Destructor**. Libera la memoria del conjunto y todos
   los recursos asociados.
7. `conjunto_iter_crear`: **Iterador** (en particular, constructor de un
   iterador externo). Retorna un objeto especializado para recorrer los
   elementos de manera secuencial.

:::
<!-- {solution} ejercicio-tipificacion-firmas -->

:::{exercise}
:label: ejercicio-tipificacion-conversor-pila

Escribí la implementación de un conversor para una estructura `pila_t` de
enteros que cumpla la siguiente firma:

``` c
int *pila_a_arreglo(const pila_t *pila, size_t *cantidad);
```
<!-- c -->

La función debe devolver un arreglo en el heap con los elementos de la pila
ordenados desde el tope hacia la base, sin alterar el estado de la pila original
(usando únicamente las operaciones públicas del TAD: `crear`, `apilar`,
`desapilar`, `ver_tope`, `esta_vacia` y `destruir`).

:::
<!-- {exercise} -->

:::{solution} ejercicio-tipificacion-conversor-pila
:class: dropdown

Dado que la función recibe un puntero constante `const pila_t *` y no podemos
modificar la pila original directamente, debemos desapilar los elementos a una
pila auxiliar para obtenerlos, y luego restaurarlos a la pila original. Al no
poder alterar la pila cliente, usamos un lazo para volcarla temporalmente en una
pila auxiliar.

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdbool.h>

/* Suponemos la existencia de las funciones públicas del TAD pila_t */
typedef struct pila pila_t;
pila_t *pila_crear(void);
bool pila_apilar(pila_t *p, int dato);
int pila_desapilar(pila_t *p);
int pila_ver_tope(const pila_t *p);
bool pila_esta_vacia(const pila_t *p);
void pila_destruir(pila_t **p);

int *pila_a_arreglo(const pila_t *pila, size_t *cantidad)
{
    if (pila == NULL || cantidad == NULL)
    {
        return NULL;
    }

    /* Creamos dos pilas auxiliares para no alterar el estado final */
    pila_t *aux = pila_crear();
    if (aux == NULL)
    {
        return NULL;
    }

    size_t count = 0;
    
    /* Desapilamos de la pila (suponiendo que removemos el const para la copia interna) */
    pila_t *pila_trabajo = (pila_t *)pila; /* Cast de conveniencia para usar la interfaz */
    
    while (!pila_esta_vacia(pila_trabajo))
    {
        int valor = pila_desapilar(pila_trabajo);
        pila_apilar(aux, valor);
        count++;
    }

    int *arreglo = malloc(count * sizeof(int));
    if (arreglo == NULL)
    {
        /* Si falla la asignación, restauramos la pila original antes de salir */
        while (!pila_esta_vacia(aux))
        {
            pila_apilar(pila_trabajo, pila_desapilar(aux));
        }
        pila_destruir(&aux);
        return NULL;
    }

    /* Al reconstruir, guardamos en el arreglo.
       Los elementos en aux están invertidos.
       Para guardarlos del tope a la base en el arreglo: */
    size_t i = 0;
    while (!pila_esta_vacia(aux))
    {
        int valor = pila_desapilar(aux);
        arreglo[i] = valor;
        pila_apilar(pila_trabajo, valor); /* Restauramos el elemento a la pila original */
        i++;
    }

    pila_destruir(&aux);
    *cantidad = count;
    return arreglo;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-tipificacion-conversor-pila -->

:::{exercise}
:label: ejercicio-tipificacion-destructor-callback

Diseñá e implementá el destructor de un TAD `tabla_hash_t` que almacena punteros
genéricos a datos en sus celdas. La función de destrucción debe aceptar una
función callback para que el cliente defina cómo destruir el dato almacenado en
cada nodo, controlando las fugas de memoria. La firma debe ser:

``` c
void tabla_destruir(tabla_hash_t **tabla, void (*destruir_dato)(void *));
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-tipificacion-destructor-callback
:class: dropdown

El destructor del TAD es responsable de liberar la estructura de soporte de la
tabla, delegando la liberación de los datos de usuario a la función callback
provista:

```{code-block} c
:linenos:
#include <stdlib.h>

typedef struct nodo_hash
{
    char *clave;
    void *valor;
    struct nodo_hash *siguiente;
} nodo_hash_t;

struct tabla_hash
{
    nodo_hash_t **baldes;
    size_t capacidad;
    size_t cantidad;
};

void tabla_destruir(tabla_hash_t **tabla, void (*destruir_dato)(void *))
{
    if (tabla == NULL || *tabla == NULL)
    {
        return;
    }

    tabla_hash_t *t = *tabla;
    /* Recorremos todos los baldes del arreglo */
    for (size_t i = 0; i < t->capacidad; i++)
    {
        nodo_hash_t *actual = t->baldes[i];
        
        /* Lazo para recorrer y liberar la lista enlazada de colisiones */
        while (actual != NULL)
        {
            nodo_hash_t *siguiente = actual->siguiente;
            
            /* Liberamos la clave */
            free(actual->clave);
            actual->clave = NULL;
            
            /* Si el cliente pasó un callback, liberamos el valor genérico */
            if (destruir_dato != NULL && actual->valor != NULL)
            {
                destruir_dato(actual->valor);
            }
            
            /* Liberamos el nodo en sí */
            free(actual);
            actual = siguiente;
        }
    }

    /* Liberamos el arreglo de baldes y la estructura contenedora */
    free(t->baldes);
    t->baldes = NULL;
    free(t);
    *tabla = NULL;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-tipificacion-destructor-callback -->

:::{exercise}
:label: ejercicio-lista-fusionar

Dadas dos listas enlazadas simples ordenadas de forma creciente, implementá una
función en C que las fusione en una nueva lista enlazada también ordenada, sin
modificar las listas originales (es decir, creando copias de los nodos). La
firma de la función es:

``` c
lista_t *fusionar_listas(const lista_t *lista1, const lista_t *lista2);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-lista-fusionar
:class: dropdown

Para resolver este ejercicio de manera limpia, recorremos ambas listas
simultáneamente mediante un lazo, comparando los elementos actuales de cada una.
Insertamos el menor en la nueva lista de forma secuencial y avanzamos el puntero
correspondiente.

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdbool.h>

/* Suponemos declaradas las estructuras lista_t y nodo_t del apunte */

lista_t *fusionar_listas(const lista_t *lista1, const lista_t *lista2)
{
    if (lista1 == NULL || lista2 == NULL)
    {
        return NULL;
    }

    lista_t *resultado = crear_lista();
    if (resultado == NULL)
    {
        return NULL;
    }

    nodo_t *n1 = lista1->inicio;
    nodo_t *n2 = lista2->inicio;

    /* Lazo principal de comparación */
    while (n1 != NULL && n2 != NULL)
    {
        if (n1->dato <= n2->dato)
        {
            if (!insertar_al_final(resultado, n1->dato))
            {
                destruir_lista(resultado);
                return NULL;
            }
            n1 = n1->siguiente;
        }
        else
        {
            if (!insertar_al_final(resultado, n2->dato))
            {
                destruir_lista(resultado);
                return NULL;
            }
            n2 = n2->siguiente;
        }
    }

    /* Lazo para vaciar los elementos restantes de la lista 1, si quedan */
    while (n1 != NULL)
    {
        if (!insertar_al_final(resultado, n1->dato))
        {
            destruir_lista(resultado);
            return NULL;
        }
        n1 = n1->siguiente;
    }

    /* Lazo para vaciar los elementos restantes de la lista 2, si quedan */
    while (n2 != NULL)
    {
        if (!insertar_al_final(resultado, n2->dato))
        {
            destruir_lista(resultado);
            return NULL;
        }
        n2 = n2->siguiente;
    }

    return resultado;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-lista-fusionar -->

:::{exercise}
:label: ejercicio-lista-ciclo

Implementá una función en C que determine si una lista enlazada simple contiene
un ciclo (es decir, si un nodo apunta a un elemento anterior de la secuencia,
provocando un lazo infinito al recorrerla). Usá el algoritmo de detección de
ciclos de Floyd (conocido como algoritmo de "la liebre y la tortuga") que
utiliza dos punteros recorriendo la estructura a diferentes velocidades.

``` c
bool tiene_ciclo(const lista_t *lista);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-lista-ciclo
:class: dropdown

El algoritmo utiliza dos punteros: uno rápido (la liebre) que avanza de a dos
nodos por iteración del lazo, y uno lento (la tortuga) que avanza de a un nodo.
Si hay un ciclo, la liebre eventualmente alcanzará a la tortuga. Si no lo hay,
la liebre llegará a `NULL`.

```{code-block} c
:linenos:
#include <stdbool.h>
#include <stdlib.h>

bool tiene_ciclo(const lista_t *lista)
{
    if (lista == NULL || lista->inicio == NULL)
    {
        return false;
    }

    nodo_t *lento = lista->inicio;
    nodo_t *rapido = lista->inicio;

    /* Lazo de recorrido a dos velocidades */
    while (rapido != NULL && rapido->siguiente != NULL)
    {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;

        /* Si los punteros coinciden en la misma dirección de memoria, hay un ciclo */
        if (lento == rapido)
        {
            return true;
        }
    }

    return false;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-lista-ciclo -->

:::{exercise}
:label: ejercicio-lista-invertir

Escribí una función iterativa en C que invierta *in-place* el orden de los
elementos de una lista enlazada simple. La operación debe modificar directamente
los enlaces de los nodos existentes, sin asignar nueva memoria para nodos ni
cambiar sus datos internos. La firma debe ser:

``` c
void invertir_lista(lista_t *lista);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-lista-invertir
:class: dropdown

Para invertir la lista *in-place*, recorremos la estructura con un lazo
manteniendo tres punteros temporales: `anterior`, `actual` y `siguiente`. En
cada iteración reorientamos el puntero `siguiente` del nodo actual hacia el nodo
`anterior`.

```{code-block} c
:linenos:
#include <stdlib.h>

void invertir_lista(lista_t *lista)
{
    if (lista == NULL || lista->inicio == NULL)
    {
        return;
    }

    nodo_t *anterior = NULL;
    nodo_t *actual = lista->inicio;
    nodo_t *siguiente = NULL;

    /* Lazo para invertir los enlaces */
    while (actual != NULL)
    {
        siguiente = actual->siguiente;  /* Guardamos el resto de la lista */
        actual->siguiente = anterior;  /* Invertimos el enlace del nodo */
        
        /* Avanzamos los punteros de control hacia la derecha */
        anterior = actual;
        actual = siguiente;
    }

    /* El último nodo procesado (anterior) es el nuevo inicio de la lista */
    lista->inicio = anterior;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-lista-invertir -->

:::{exercise}
:label: ejercicio-arreglo-insertar-posicion

Implementá la función de inserción en una posición específica de la secuencia
implementada con arreglo dinámico. La función debe desplazar los elementos
necesarios hacia la derecha para hacer espacio al nuevo dato, y debe
redimensionar la capacidad del arreglo al doble utilizando la función
`redimensionar()` si se encuentra lleno. La firma es:

``` c
bool insertar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos, int dato);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-arreglo-insertar-posicion
:class: dropdown

La solución requiere verificar primero la validez del puntero y de la posición
de inserción. Si el tamaño alcanzó la capacidad máxima, se invoca a la función
de redimensionamiento. Luego, mediante un lazo inverso, se desplazan los
elementos desde la última posición hacia la derecha hasta llegar al índice de
destino, donde se almacena el nuevo elemento.

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdbool.h>

/* Suponemos definida la estructura secuencia_arreglo_t del apunte */

bool insertar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos, int dato)
{
    if (sec == NULL || pos > sec->tamanio)
    {
        return false;
    }

    /* Redimensionamiento si el arreglo está lleno */
    if (sec->tamanio >= sec->capacidad)
    {
        if (!redimensionar(sec))
        {
            return false;
        }
    }

    /* Desplazamos los elementos hacia la derecha para abrir espacio */
    for (size_t i = sec->tamanio; i > pos; i--)
    {
        sec->elementos[i] = sec->elementos[i - 1];
    }

    /* Insertamos el nuevo valor en la posición libre y actualizamos el tamaño */
    sec->elementos[pos] = dato;
    sec->tamanio++;

    return true;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-arreglo-insertar-posicion -->

:::{exercise}
:label: ejercicio-arreglo-eliminar-encoger

Implementá una función para eliminar un elemento en una posición dada de una
secuencia con arreglo dinámico, desplazando los elementos restantes hacia la
izquierda para cubrir la vacante. Además, para optimizar el uso de la memoria,
si la cantidad de elementos cae por debajo del 25% de la capacidad contratada,
la función debe reducir a la mitad la capacidad del arreglo en el heap,
asegurando que nunca sea menor que la capacidad inicial. La firma es:

``` c
bool eliminar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos);
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-arreglo-eliminar-encoger
:class: dropdown

El algoritmo desplaza los elementos del arreglo hacia la izquierda para
sobreescribir el elemento eliminado. Tras reducir el tamaño, verifica si se
cumple la condición de reducción de memoria ($4 \times \text{tamanio} <
\text{capacidad}$) y que no se reduzca por debajo de la capacidad inicial mínima
(por ejemplo, `CAPACIDAD_INICIAL` = 10).

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdbool.h>

#define CAPACIDAD_INICIAL 10

bool eliminar_en_posicion_arreglo(secuencia_arreglo_t *sec, size_t pos)
{
    if (sec == NULL || pos >= sec->tamanio)
    {
        return false;
    }

    /* Desplazamos los elementos siguientes hacia la izquierda */
    for (size_t i = pos; i < sec->tamanio - 1; i++)
    {
        sec->elementos[i] = sec->elementos[i + 1];
    }
    
    sec->tamanio--;

    /* Verificamos si podemos encoger la capacidad para ahorrar memoria */
    if (sec->tamanio < sec->capacidad / 4 && sec->capacidad / 2 >= CAPACIDAD_INICIAL)
    {
        size_t nueva_capacidad = sec->capacidad / 2;
        int *nuevo_arreglo = realloc(sec->elementos, nueva_capacidad * sizeof(int));
        
        /* Si falla realloc al achicar, no consideramos error fatal, mantenemos capacidad */
        if (nuevo_arreglo != NULL)
        {
            sec->elementos = nuevo_arreglo;
            sec->capacidad = nueva_capacidad;
        }
    }

    return true;
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-arreglo-eliminar-encoger -->

:::{exercise}
:label: ejercicio-arreglo-filtrar-complejidad

Compará de manera asintótica en el peor caso la complejidad temporal del proceso
de filtrar una secuencia (remover todos los elementos que no cumplan con un
determinado criterio) en dos escenarios:
1. La secuencia está implementada mediante una Lista Enlazada Simple.
2. La secuencia está implementada mediante un Arreglo Dinámico que realiza
   desplazamientos por cada eliminación.

Describí estrategias de optimización para cada caso y justificá tus respuestas
utilizando notaciones asintóticas.

:::
<!-- {exercise} -->

:::{solution} ejercicio-arreglo-filtrar-complejidad
:class: dropdown

**1. Escenario con Lista Enlazada Simple:**
- **Complejidad del peor caso:** $O(n)$, donde $n$ es la cantidad de elementos.
- **Justificación:** Recorrer la lista requiere visitar cada nodo
  secuencialmente. Si un nodo debe eliminarse, la reconexión de punteros y la
  liberación con `free` toman tiempo constante $O(1)$. Solo necesitamos mantener
  un puntero al nodo anterior.
- **Optimización:** Mantener un puntero auxiliar al nodo `anterior` durante el
  lazo para evitar tener que buscarlo desde el inicio de la lista, asegurando
  que cada nodo se procese en $O(1)$.

**2. Escenario con Arreglo Dinámico:**
- **Complejidad del peor caso (ingenua):** $O(n^2)$.
- **Justificación:** Si se recorre el arreglo y por cada elemento a eliminar se
  llama a una función que desplaza los elementos restantes hacia la izquierda,
  en el peor caso (por ejemplo, si eliminamos casi todos los elementos)
  realizaremos $O(n)$ desplazamientos de tamaño proporcional a $n$ por cada
  remoción, resultando en un comportamiento cuadrático.
- **Optimización ($O(n)$ temporal y $O(1)$ espacial):** Podemos aplicar la
  técnica de los **dos índices** en un solo lazo. Usamos un índice de lectura
  que recorre todo el arreglo elemento por elemento, y un índice de escritura
  que indica dónde debe copiarse el siguiente elemento que *sí* pasa el filtro.
  Una vez terminado el lazo, actualizamos el tamaño de la secuencia a la
  posición final del índice de escritura. Esto reduce la complejidad a un único
  paso lineal $O(n)$ con un mínimo costo de copiado.

:::
<!-- {solution} ejercicio-arreglo-filtrar-complejidad -->

:::{exercise}
:label: ejercicio-genericidad-buscar-lineal

Implementá una función genérica de búsqueda para la lista enlazada genérica. La
función debe recorrer la estructura buscando un elemento que coincida con una
clave de búsqueda, utilizando un callback de comparación provisto por el
usuario. La firma debe ser:

``` c
void *lista_buscar_generica(const lista_generica_t *lista, const void *clave, int (*comparar)(const void *, const void *));
```
<!-- c -->

Retorná el puntero al dato almacenado en la lista si se encuentra una
coincidencia (cuando el callback retorne `0`), o `NULL` si no se encuentra.

:::
<!-- {exercise} -->

:::{solution} ejercicio-genericidad-buscar-lineal
:class: dropdown

La función realiza una búsqueda lineal clásica sobre los nodos genéricos. En
cada paso del lazo se invoca al callback `comparar`, pasándole como argumentos
el campo `dato` almacenado en el nodo y la `clave` de búsqueda recibida.

```{code-block} c
:linenos:
#include <stdlib.h>

/* Suponemos definidas las estructuras de lista genérica del apunte */

void *lista_buscar_generica(const lista_generica_t *lista, const void *clave, int (*comparar)(const void *, const void *))
{
    if (lista == NULL || comparar == NULL)
    {
        return NULL;
    }

    nodo_generico_t *actual = lista->inicio;

    /* Lazo de búsqueda lineal */
    while (actual != NULL)
    {
        /* Invocamos al callback pasándole el dato del nodo y la clave buscada */
        if (comparar(actual->dato, clave) == 0)
        {
            return actual->dato; /* Retornamos el dato original hallado */
        }
        
        actual = actual->siguiente;
    }

    return NULL; /* No se encontró coincidencia en la lista */
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-genericidad-buscar-lineal -->

:::{exercise}
:label: ejercicio-genericidad-filtrar-destruir

Escribí una función genérica que filtre los elementos de una lista enlazada
genérica de `void*`. La función debe evaluar cada elemento usando un callback
"predicado" (que retorna `true` si el elemento debe conservarse y `false` si
debe eliminarse). Para los elementos que no cumplan la condición, se debe
remover el nodo de la lista, liberar la memoria del nodo y utilizar un callback
de destrucción para liberar los recursos del dato en sí. La firma es:

``` c
void lista_filtrar_generica(lista_generica_t *lista, bool (*predicado)(const void *), void (*destruir_dato)(void *));
```
<!-- c -->

:::
<!-- {exercise} -->

:::{solution} ejercicio-genericidad-filtrar-destruir
:class: dropdown

Para implementar esta función de manera segura, debemos mantener un puntero al
nodo `anterior` para desvincular correctamente los nodos eliminados de la
secuencia. Además, guardamos la referencia al nodo `siguiente` antes de liberar
el nodo `actual` para no perder la conexión de la lista en el lazo.

```{code-block} c
:linenos:
#include <stdlib.h>
#include <stdbool.h>

void lista_filtrar_generica(lista_generica_t *lista, bool (*predicado)(const void *), void (*destruir_dato)(void *))
{
    if (lista == NULL || predicado == NULL)
    {
        return;
    }

    nodo_generico_t *actual = lista->inicio;
    nodo_generico_t *anterior = NULL;

    /* Lazo de recorrido y filtrado */
    while (actual != NULL)
    {
        nodo_generico_t *siguiente = actual->siguiente;

        if (!predicado(actual->dato))
        {
            /* El elemento no cumple el predicado: debe eliminarse */
            if (anterior == NULL)
            {
                /* Eliminamos el primer elemento */
                lista->inicio = siguiente;
            }
            else
            {
                /* Saltamos el nodo actual en el encadenamiento */
                anterior->siguiente = siguiente;
            }

            /* Liberamos los recursos del dato de usuario si se proveyó callback */
            if (destruir_dato != NULL && actual->dato != NULL)
            {
                destruir_dato(actual->dato);
            }

            /* Liberamos la memoria física del nodo */
            free(actual);
            lista->tamanio--;
        }
        else
        {
            /* Si se conserva el nodo, este pasa a ser el anterior para el siguiente paso */
            anterior = actual;
        }

        actual = siguiente;
    }
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-genericidad-filtrar-destruir -->

:::{exercise}
:label: ejercicio-genericidad-callback-alumno

Dada la estructura de un alumno de la universidad:

``` c
typedef struct {
    int padron;
    char *nombre;
    double promedio;
} alumno_t;
```
<!-- c -->

Escribí una función callback de comparación compatible con la firma estándar
`int (*comparar)(const void *, const void *)`. La función debe comparar dos
alumnos por promedio en orden descendente. Si tienen el mismo promedio, la
comparación debe dirimirse por padrón en orden ascendente (menor padrón
primero).

:::
<!-- {exercise} -->

:::{solution} ejercicio-genericidad-callback-alumno
:class: dropdown

La función callback debe realizar primero la conversión segura de los punteros
constantes `void*` a punteros del tipo `alumno_t*`. Luego, realiza las
comparaciones correspondientes respetando los signos esperados por el contrato
de las funciones de ordenación y búsqueda.

```{code-block} c
:linenos:
#include <string.h>

typedef struct {
    int padron;
    char *nombre;
    double promedio;
} alumno_t;

int comparar_alumnos(const void *a, const void *b)
{
    /* Casting de punteros genéricos constantes a tipos concretos */
    const alumno_t *alumno_a = (const alumno_t *)a;
    const alumno_t *alumno_b = (const alumno_t *)b;

    /* Comparación por promedio en orden descendente */
    if (alumno_a->promedio > alumno_b->promedio)
    {
        return -1; /* alumno_a va antes porque tiene mayor promedio */
    }
    if (alumno_a->promedio < alumno_b->promedio)
    {
        return 1;  /* alumno_b va antes */
    }

    /* Desempate por padrón en orden ascendente */
    if (alumno_a->padron < alumno_b->padron)
    {
        return -1; /* Menor padrón primero */
    }
    if (alumno_a->padron > alumno_b->padron)
    {
        return 1;
    }

    return 0; /* Alumnos equivalentes en promedio y padrón */
}

```
<!-- {code-block} c -->

:::
<!-- {solution} ejercicio-genericidad-callback-alumno -->

## Glosario

:::{glossary}

TAD (Tipo Abstracto de Datos)
: Modelo matemático para tipos de datos definidos por su comportamiento y
operaciones.

Pila (Stack)
: Estructura de datos LIFO.

Cola (Queue)
: Estructura de datos FIFO.

Encapsulación
: Ocultamiento de la representación de datos del cliente.

:::
<!-- {glossary} -->

## Síntesis y Resumen

(resumen-de-la-unidad)=
### Resumen de la Unidad


En este apunte hemos cubierto:
- **El concepto de TAD** y la separación de interfaz e implementación.
- **El TAD Secuencia** como abstracción fundamental, implementado mediante
  arreglos dinámicos y listas enlazadas.
- **Listas enlazadas simples, dobles y circulares**, con sus operaciones
  fundamentales.
- **Diferencia física de asignación estática y dinámica** en memoria.

Para continuar con estructuras lineales de acceso restringido, consultá
{ref}`capitulo-tad-pilas-colas`.

(referencias-lecturas-tad)=
## Referencias y Lecturas Complementarias

- **King, K. N.** [@king_c_2008]. *C Programming: A Modern Approach* (2.ª
  edición). W. W. Norton & Company.
  - Revisá el **Capítulo 19: Program Design**, que introduce el concepto de
    encapsulamiento, ocultamiento de información y la distinción entre interfaz
    y TAD en C.
- **Sedgewick, R. y Wayne, K.** [@sedgewick_algorithms_2011]. *Algorithms* (4.ª
  edición). Addison-Wesley.
  - Consultá el **Capítulo 1: Fundamentals**, sección de APIs y tipos de datos
    abstractos, para una perspectiva sobre cómo estructurar colecciones
    genéricas mediante listas enlazadas.
- **Cormen, T. H. y otros** [@cormen_introduction_2009]. *Introduction to
  Algorithms* (3.ª edición). MIT Press.
  - Estudiá el **Capítulo 10: Elementary Data Structures**, donde se explica en
    detalle el funcionamiento lógico de listas enlazadas y estructuras lineales
    elementales.
- **Hanson, D. R.** [@hanson_c_1996]. *C Interfaces and Implementations*.
  Addison-Wesley.
  - Consultá los capítulos iniciales para comprender el diseño de APIs
    abstractas basadas en punteros opacos de forma profesional.
