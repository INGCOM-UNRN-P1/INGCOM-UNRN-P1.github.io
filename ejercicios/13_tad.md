---
title: "Ejercicios: Tipos de Datos Abstractos"
short_title: "13. TAD, Pilas y Colas"
---

Ejercicios para dominar la implementación de Tipos de Datos Abstractos, desde listas enlazadas básicas hasta pilas y colas con diferentes estrategias de implementación. Estos ejercicios refuerzan los conceptos de encapsulamiento, abstracción y gestión de memoria dinámica.

## 1: Lista Enlazada Simple - Operaciones Básicas

Implementar un TAD de lista enlazada simple con su interfaz completa.

```c
// lista.h
typedef struct lista lista_t;

lista_t* crear_lista(void);
void destruir_lista(lista_t* lista);
bool lista_vacia(const lista_t* lista);
size_t lista_longitud(const lista_t* lista);
```

### 1.1: Inserción al Inicio

Implementar la operación de insertar un elemento al principio de la lista. Esta operación debe tener complejidad $O(1)$.

```c
bool insertar_al_inicio(lista_t* lista, int dato);
```

### 1.2: Inserción al Final

Implementar la operación de insertar un elemento al final de la lista. Analizar la complejidad: $O(n)$ sin puntero al último, $O(1)$ con puntero al último.

```c
bool insertar_al_final(lista_t* lista, int dato);
```

### 1.3: Ver Primero y Último

Implementar operaciones para obtener el primer y último elemento sin modificar la lista.

```c
bool ver_primero(const lista_t* lista, int* dato);
bool ver_ultimo(const lista_t* lista, int* dato);
```

### 1.4: Borrar Primero

Implementar la operación de eliminar el primer elemento y retornar su valor. Complejidad: $O(1)$.

```c
bool borrar_primero(lista_t* lista, int* dato);
```

## 2: Lista Enlazada - Operaciones de Búsqueda

### 2.1: Buscar Elemento

Implementar una función que determine si un elemento está presente en la lista. Retornar `true` si lo encuentra.

```c
bool lista_pertenece(const lista_t* lista, int dato);
```

**Complejidad:** $O(n)$ en el peor caso.

### 2.2: Obtener Elemento en Posición

Implementar una función que retorne el elemento en una posición específica (índice basado en 0).

```c
bool lista_obtener(const lista_t* lista, size_t posicion, int* dato);
```

Retornar `false` si la posición es inválida.

### 2.3: Contar Ocurrencias

Implementar una función que cuente cuántas veces aparece un elemento en la lista.

```c
size_t lista_contar(const lista_t* lista, int dato);
```

## 3: Lista Enlazada - Operaciones Avanzadas

### 3.1: Insertar en Posición

Implementar una función que inserte un elemento en una posición específica.

```c
bool lista_insertar_en(lista_t* lista, size_t posicion, int dato);
```

**Casos especiales:**
- Posición 0: insertar al inicio
- Posición >= longitud: insertar al final
- Posición intermedia: recorrer hasta la posición

### 3.2: Eliminar por Valor

Implementar una función que elimine la primera ocurrencia de un valor específico.

```c
bool lista_eliminar_valor(lista_t* lista, int dato);
```

Retornar `true` si se eliminó, `false` si no se encontró.

### 3.3: Invertir Lista

Implementar una función que invierta el orden de los elementos de la lista modificando los punteros.

```c
void lista_invertir(lista_t* lista);
```

**Estrategia:** Recorrer la lista cambiando la dirección de cada enlace.

**Complejidad:** $O(n)$ en tiempo, $O(1)$ en espacio.

## 4: Lista Doblemente Enlazada

Implementar una lista doblemente enlazada donde cada nodo tiene punteros al siguiente y al anterior.

```c
// lista_doble.h
typedef struct lista_doble lista_doble_t;

lista_doble_t* crear_lista_doble(void);
void destruir_lista_doble(lista_doble_t* lista);
bool insertar_inicio_doble(lista_doble_t* lista, int dato);
bool insertar_final_doble(lista_doble_t* lista, int dato);
bool borrar_inicio_doble(lista_doble_t* lista, int* dato);
bool borrar_final_doble(lista_doble_t* lista, int* dato);
```

### 4.1: Ventajas de la Lista Doble

Implementar las operaciones de borrar al final y recorrer en sentido inverso, demostrando la ventaja de tener doble enlace.

**Complejidad de borrar al final:**
- Lista simple: $O(n)$ (necesita encontrar el penúltimo)
- Lista doble: $O(1)$ (tiene puntero al último y su anterior)

### 4.2: Iterador Bidireccional

Implementar un iterador que pueda moverse en ambas direcciones.

```c
typedef struct lista_iter lista_iter_t;

lista_iter_t* lista_iter_crear(lista_doble_t* lista);
bool lista_iter_avanzar(lista_iter_t* iter);
bool lista_iter_retroceder(lista_iter_t* iter);
int lista_iter_ver_actual(const lista_iter_t* iter);
bool lista_iter_al_final(const lista_iter_t* iter);
void lista_iter_destruir(lista_iter_t* iter);
```

## 5: Lista Circular

Implementar una lista circular enlazada donde el último nodo apunta al primero.

```c
typedef struct lista_circular lista_circular_t;

lista_circular_t* crear_lista_circular(void);
bool insertar_circular(lista_circular_t* lista, int dato);
bool lista_circular_vacia(const lista_circular_t* lista);
```

### 5.1: Rotar Lista

Implementar una función que "rote" la lista circular, haciendo que el primer elemento pase a ser el último.

```c
void lista_circular_rotar(lista_circular_t* lista);
```

**Complejidad:** $O(1)$ (solo mover el puntero de cabeza al siguiente).

### 5.2: Problema de Josephus

Usar la lista circular para resolver el problema de Josephus: $n$ personas en círculo, se elimina cada $k$-ésima persona. ¿Quién sobrevive?

```c
int josephus(int n, int k);
```

## 6: Pila (Stack) - Implementación con Lista

Implementar un TAD Pila usando una lista enlazada como estructura subyacente.

```c
// pila.h
typedef struct pila pila_t;

pila_t* pila_crear(void);
void pila_destruir(pila_t* pila);
bool pila_esta_vacia(const pila_t* pila);
bool pila_apilar(pila_t* pila, int dato);
bool pila_desapilar(pila_t* pila, int* dato);
bool pila_ver_tope(const pila_t* pila, int* dato);
size_t pila_cantidad(const pila_t* pila);
```

### 6.1: Todas las Operaciones

Implementar todas las operaciones del TAD Pila con complejidad $O(1)$ cada una.

**Invariante de la pila:**
- El tope de la pila corresponde al inicio de la lista enlazada
- Todas las operaciones se realizan en la cabeza de la lista

### 6.2: Pila de Enteros vs Pila Genérica

Analizar cómo se podría extender la pila para almacenar cualquier tipo de dato usando punteros `void*`.

```c
bool pila_apilar_generico(pila_t* pila, void* dato);
```

## 7: Pila - Implementación con Arreglo Dinámico

Implementar un TAD Pila usando un arreglo dinámico con capacidad variable.

```c
// pila_arreglo.h
typedef struct pila_arr pila_arr_t;

pila_arr_t* pila_arr_crear(size_t capacidad_inicial);
void pila_arr_destruir(pila_arr_t* pila);
bool pila_arr_apilar(pila_arr_t* pila, int dato);
bool pila_arr_desapilar(pila_arr_t* pila, int* dato);
```

### 7.1: Redimensionamiento Automático

Implementar la lógica de redimensionamiento:
- Duplicar capacidad cuando está llena
- Reducir a la mitad cuando está 25% llena (para evitar thrashing)

**Complejidad amortizada:** $O(1)$ por operación.

### 7.2: Comparación de Implementaciones

Analizar ventajas y desventajas:

| Aspecto | Lista Enlazada | Arreglo Dinámico |
|---------|----------------|------------------|
| Memoria | Más overhead (punteros) | Mejor localidad de caché |
| Tamaño | Crece orgánicamente | Crece de a saltos |
| Operaciones | Siempre $O(1)$ | $O(1)$ amortizado |

## 8: Aplicaciones de Pilas

### 8.1: Verificar Paréntesis Balanceados

Implementar una función que verifique si una expresión tiene paréntesis, corchetes y llaves correctamente balanceados.

```c
bool parentesis_balanceados(const char* expresion);
```

**Algoritmo:**
1. Recorrer la expresión carácter por carácter
2. Si es apertura `({[`, apilar
3. Si es cierre `)}]`, desapilar y verificar que coincida
4. Al final, la pila debe estar vacía

**Ejemplos:**
- `"(())"` → `true`
- `"({[]})"` → `true`
- `"([)]"` → `false` (mal anidado)
- `"(()"` → `false` (falta cerrar)

### 8.2: Evaluación de Expresiones Postfijas (RPN)

Implementar un evaluador de notación polaca inversa usando una pila.

```c
int evaluar_postfija(const char* expresion);
```

**Algoritmo:**
1. Leer token por token
2. Si es número, apilar
3. Si es operador, desapilar dos operandos, aplicar operación, apilar resultado

**Ejemplos:**
- `"3 4 +"` → 7
- `"3 4 + 5 *"` → 35
- `"15 7 1 1 + - / 3 * 2 1 1 + + -"` → 5

### 8.3: Conversión Infija a Postfija

Implementar el algoritmo de Shunting Yard para convertir expresiones infijas a postfijas.

```c
char* infija_a_postfija(const char* expresion_infija);
```

**Ejemplo:**
- Entrada: `"(3 + 4) * 5"`
- Salida: `"3 4 + 5 *"`

**Algoritmo:**
1. Usar pila para operadores
2. Manejar precedencia y asociatividad
3. Procesar paréntesis correctamente

## 9: Cola (Queue) - Implementación con Lista

Implementar un TAD Cola usando una lista enlazada.

```c
// cola.h
typedef struct cola cola_t;

cola_t* cola_crear(void);
void cola_destruir(cola_t* cola);
bool cola_esta_vacia(const cola_t* cola);
bool cola_encolar(cola_t* cola, int dato);
bool cola_desencolar(cola_t* cola, int* dato);
bool cola_ver_primero(const cola_t* cola, int* dato);
size_t cola_cantidad(const cola_t* cola);
```

### 9.1: Implementación Eficiente

Para lograr $O(1)$ en encolar y desencolar, mantener dos punteros:
- `frente`: apunta al primer elemento (para desencolar)
- `final`: apunta al último elemento (para encolar)

```c
struct cola {
    nodo_t* frente;
    nodo_t* final;
    size_t cantidad;
};
```

### 9.2: Casos Especiales

Manejar correctamente:
- Cola vacía: ambos punteros NULL
- Un solo elemento: frente == final
- Desencolar el último: actualizar ambos punteros a NULL

## 10: Cola - Implementación con Arreglo Circular

Implementar una cola usando un arreglo circular con índices móviles.

```c
// cola_circular.h
typedef struct cola_circular cola_circular_t;

cola_circular_t* cola_circular_crear(size_t capacidad);
void cola_circular_destruir(cola_circular_t* cola);
bool cola_circular_encolar(cola_circular_t* cola, int dato);
bool cola_circular_desencolar(cola_circular_t* cola, int* dato);
```

### 10.1: Gestión de Índices

Implementar la lógica de índices circulares:

```c
struct cola_circular {
    int* datos;
    size_t capacidad;
    size_t frente;      // Índice del primer elemento
    size_t cantidad;    // Elementos actuales
};
```

**Cálculo de posiciones:**
- Siguiente posición: `(indice + 1) % capacidad`
- Posición de encolar: `(frente + cantidad) % capacidad`

### 10.2: Detectar Cola Llena vs Vacía

Resolver el problema de ambigüedad cuando frente == final:
- **Solución 1:** Mantener contador de elementos (`cantidad`)
- **Solución 2:** Sacrificar una celda (llena cuando `(final+1)%cap == frente`)
- **Solución 3:** Usar flag booleano `esta_llena`

## 11: Aplicaciones de Colas

### 11.1: Simulación de Cola de Atención

Simular una cola de atención donde llegan clientes aleatoriamente y son atendidos en orden FIFO.

```c
typedef struct {
    int id_cliente;
    int tiempo_llegada;
} cliente_t;

void simular_cola_atencion(int num_clientes, int tiempo_atencion_promedio);
```

Calcular:
- Tiempo promedio de espera
- Tiempo máximo de espera
- Longitud máxima de la cola

### 11.2: BFS (Breadth-First Search) en Grafos

Implementar recorrido en anchura de un grafo usando una cola.

```c
void bfs(grafo_t* grafo, int nodo_inicio);
```

**Algoritmo:**
1. Encolar nodo inicial y marcarlo como visitado
2. Mientras la cola no esté vacía:
   - Desencolar un nodo
   - Procesar el nodo
   - Encolar todos sus vecinos no visitados

### 11.3: Cola de Prioridad (Heap)

Extender el concepto de cola para que los elementos se desenccolen según su prioridad, no por orden de llegada.

```c
typedef struct cola_prioridad cola_prioridad_t;

bool cola_prioridad_encolar(cola_prioridad_t* cola, int dato, int prioridad);
bool cola_prioridad_desencolar(cola_prioridad_t* cola, int* dato);
```

Implementar usando un min-heap para obtener $O(\log n)$ en ambas operaciones.

## 12: Deque (Double-Ended Queue)

Implementar un TAD Deque que permita insertar y eliminar por ambos extremos.

```c
// deque.h
typedef struct deque deque_t;

deque_t* deque_crear(void);
void deque_destruir(deque_t* deque);
bool deque_insertar_primero(deque_t* deque, int dato);
bool deque_insertar_ultimo(deque_t* deque, int dato);
bool deque_remover_primero(deque_t* deque, int* dato);
bool deque_remover_ultimo(deque_t* deque, int* dato);
bool deque_ver_primero(const deque_t* deque, int* dato);
bool deque_ver_ultimo(const deque_t* deque, int* dato);
```

### 12.1: Implementación Óptima

Usar lista doblemente enlazada con punteros a ambos extremos para lograr $O(1)$ en todas las operaciones.

### 12.2: Aplicación - Ventana Deslizante

Usar un deque para resolver el problema de "máximo en ventana deslizante": dado un arreglo y un tamaño de ventana, encontrar el máximo en cada ventana.

```c
int* maximos_ventana(int* arreglo, size_t n, size_t k, size_t* tam_resultado);
```

**Ejemplo:**
- Entrada: `[1, 3, -1, -3, 5, 3, 6, 7]`, `k=3`
- Salida: `[3, 3, 5, 5, 6, 7]`

## 13: Pila con Mínimo en O(1)

Diseñar una pila que soporte obtener el mínimo elemento en tiempo constante.

```c
typedef struct pila_min pila_min_t;

pila_min_t* pila_min_crear(void);
bool pila_min_apilar(pila_min_t* pila, int dato);
bool pila_min_desapilar(pila_min_t* pila, int* dato);
bool pila_min_obtener_minimo(const pila_min_t* pila, int* minimo);
```

### 13.1: Estrategia de Implementación

Usar dos pilas:
1. Pila principal: almacena todos los datos
2. Pila de mínimos: en cada posición guarda el mínimo hasta ese punto

**Invariante:** El tope de pila_minimos siempre contiene el mínimo de pila_principal.

### 13.2: Optimización de Espacio

Implementar versión que solo almacene mínimos cuando cambian, reduciendo uso de memoria.

## 14: Cola Usando Dos Pilas

Implementar una cola usando dos pilas como estructuras internas.

```c
typedef struct {
    pila_t* pila_entrada;
    pila_t* pila_salida;
} cola_con_pilas_t;

bool cola_pilas_encolar(cola_con_pilas_t* cola, int dato);
bool cola_pilas_desencolar(cola_con_pilas_t* cola, int* dato);
```

### 14.1: Algoritmo de Transferencia

**Encolar:** Siempre apilar en `pila_entrada`.

**Desencolar:**
1. Si `pila_salida` no está vacía, desapilar de ella
2. Si está vacía, transferir todos los elementos de `pila_entrada` a `pila_salida`
3. Desapilar de `pila_salida`

**Complejidad amortizada:** $O(1)$ por operación.

### 14.2: Análisis de Complejidad

Explicar por qué aunque transferir es $O(n)$, la complejidad amortizada es $O(1)$:
- Cada elemento se transfiere exactamente una vez
- Si se hacen $n$ operaciones, el costo total es $O(n)$
- Costo promedio por operación: $O(1)$

## 15: Pila Usando Dos Colas

Implementar una pila usando dos colas como estructuras internas.

```c
typedef struct {
    cola_t* cola_principal;
    cola_t* cola_auxiliar;
} pila_con_colas_t;

bool pila_colas_apilar(pila_con_colas_t* pila, int dato);
bool pila_colas_desapilar(pila_con_colas_t* pila, int* dato);
```

### 15.1: Estrategia de Implementación

**Apilar:** Encolar en `cola_principal`.

**Desapilar:**
1. Pasar todos los elementos excepto el último de `cola_principal` a `cola_auxiliar`
2. El último elemento es el resultado
3. Intercambiar los roles de las colas

**Complejidad:** $O(1)$ para apilar, $O(n)$ para desapilar.

### 15.2: Versión Alternativa

Implementar versión donde apilar cuesta $O(n)$ pero desapilar cuesta $O(1)$:
- Al apilar nuevo elemento, encolarlo en `cola_auxiliar`
- Transferir todos de `cola_principal` a `cola_auxiliar`
- Intercambiar roles

## 16: Lista con Iterador Interno

Implementar una lista con iterador interno que permita recorrer sin exponer la estructura interna.

```c
typedef bool (*lista_visitar)(int dato, void* extra);

void lista_iterar(lista_t* lista, lista_visitar visitar, void* extra);
```

### 16.1: Uso del Iterador Interno

El iterador llama a la función `visitar` para cada elemento. Si `visitar` retorna `false`, se detiene la iteración.

**Ejemplo de uso:**

```c
bool imprimir(int dato, void* extra) {
    printf("%d ", dato);
    return true;  // Continuar iterando
}

lista_iterar(mi_lista, imprimir, NULL);
```

### 16.2: Operaciones con Iterador

Implementar operaciones comunes usando el iterador interno:

```c
bool lista_todos(lista_t* lista, bool (*predicado)(int dato));
bool lista_alguno(lista_t* lista, bool (*predicado)(int dato));
```

## 17: Lista Ordenada

Implementar un TAD de lista que mantiene sus elementos siempre ordenados.

```c
typedef struct lista_ordenada lista_ordenada_t;

lista_ordenada_t* lista_ordenada_crear(void);
bool lista_ordenada_insertar(lista_ordenada_t* lista, int dato);
bool lista_ordenada_pertenece(const lista_ordenada_t* lista, int dato);
```

### 17.1: Inserción Ordenada

Implementar inserción que encuentre la posición correcta para mantener el orden.

**Complejidad:** $O(n)$ en el peor caso (lista enlazada simple).

**Optimización:** Usar skip list para reducir a $O(\log n)$ en promedio.

### 17.2: Búsqueda Binaria

Analizar por qué búsqueda binaria no es eficiente en lista enlazada:
- No hay acceso aleatorio en $O(1)$
- Llegar al elemento medio cuesta $O(n)$

**Conclusión:** Para búsqueda binaria, usar arreglo dinámico en lugar de lista enlazada.

## 18: Merge de Listas Ordenadas

Implementar una función que combine dos listas ordenadas en una nueva lista ordenada.

```c
lista_t* lista_merge(const lista_t* lista1, const lista_t* lista2);
```

### 18.1: Algoritmo de Merge

Similar al paso de merge en merge sort:
1. Comparar cabezas de ambas listas
2. Tomar el menor e insertarlo en resultado
3. Avanzar en la lista correspondiente
4. Repetir hasta que una lista se agote
5. Anexar el resto de la otra lista

**Complejidad:** $O(n + m)$ donde $n$ y $m$ son las longitudes.

### 18.2: Merge Destructivo

Implementar versión que reutilice los nodos existentes en lugar de crear nuevos.

```c
lista_t* lista_merge_destructivo(lista_t* lista1, lista_t* lista2);
```

**Ventaja:** No requiere memoria adicional para nodos.

## 19: Invertir Grupos en Lista

Implementar una función que invierta la lista de a grupos de $k$ elementos.

```c
void lista_invertir_grupos(lista_t* lista, size_t k);
```

**Ejemplo con k=3:**
- Entrada: `1 → 2 → 3 → 4 → 5 → 6 → 7`
- Salida: `3 → 2 → 1 → 6 → 5 → 4 → 7`

### 19.1: Algoritmo

1. Recorrer la lista de a $k$ elementos
2. Invertir cada grupo de $k$
3. Enlazar correctamente los grupos invertidos
4. Si el último grupo tiene menos de $k$, puede invertirse o dejarse

**Complejidad:** $O(n)$ con un solo recorrido.

### 19.2: Casos Especiales

Manejar:
- $k = 1$: no hacer nada
- $k \geq n$: invertir toda la lista
- Lista vacía o con un elemento

## 20: Análisis de Complejidad de TADs

Completar la siguiente tabla comparativa de complejidades para diferentes implementaciones:

### 20.1: Tabla Comparativa

| Operación | Lista Simple | Lista Doble | Arreglo Estático | Arreglo Dinámico |
|-----------|--------------|-------------|------------------|------------------|
| Insertar al inicio | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Insertar al final | $O(n)$ sin tail<br>$O(1)$ con tail | $O(1)$ | $O(1)$ si hay espacio<br>$O(n)$ si está lleno | $O(1)$ amortizado |
| Borrar al inicio | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Borrar al final | $O(n)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| Buscar | $O(n)$ | $O(n)$ | $O(n)$<br>$O(\log n)$ si ordenado | $O(n)$<br>$O(\log n)$ si ordenado |
| Acceso por índice | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ |
| Memoria overhead | Alta (punteros) | Muy alta (doble punteros) | Baja | Baja + desperdicio |

### 20.2: Decisiones de Diseño

Para cada escenario, elegir la estructura de datos óptima y justificar:

**a) Sistema que inserta mayormente al inicio y necesita eliminar al inicio:**
- **Respuesta:** Lista enlazada simple o pila
- **Justificación:** Ambas operaciones en $O(1)$

**b) Buffer circular de tamaño fijo para streaming:**
- **Respuesta:** Arreglo circular (cola circular)
- **Justificación:** $O(1)$ en todas las operaciones, mejor localidad de caché

**c) Historial de navegador (necesita recorrer hacia atrás y adelante):**
- **Respuesta:** Lista doblemente enlazada
- **Justificación:** Navegación bidireccional eficiente

**d) Lista de reproducción que necesita acceso aleatorio:**
- **Respuesta:** Arreglo dinámico
- **Justificación:** Acceso por índice en $O(1)$

**e) Cola de tareas con prioridades:**
- **Respuesta:** Heap (cola de prioridad)
- **Justificación:** Inserción y extracción del mínimo/máximo en $O(\log n)$

### 20.3: Trade-offs de Memoria vs Velocidad

Analizar para cada implementación:

**Lista Enlazada:**
- **Pros:** Crece orgánicamente, inserciones/eliminaciones rápidas en extremos
- **Contras:** Overhead de punteros (50% más memoria), mala localidad de caché

**Arreglo Dinámico:**
- **Pros:** Acceso aleatorio $O(1)$, excelente localidad de caché
- **Contras:** Redimensionamiento costoso, puede desperdiciar memoria

**Solución híbrida:** Unrolled list (lista de bloques de arreglos) combina ambas ventajas.
