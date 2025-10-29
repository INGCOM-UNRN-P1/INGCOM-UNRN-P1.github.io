---
title: Programación Concurrente con Hilos en C
short_title: Hilos POSIX
subtitle: Multithreading en sistemas Unix/Linux
---

## Introducción a la Programación Concurrente

La **programación concurrente** permite que múltiples secuencias de instrucciones se ejecuten simultáneamente dentro de un mismo proceso. En sistemas Unix/Linux, esto se logra mediante **hilos** (*threads*), unidades de ejecución más livianas que los procesos que comparten el mismo espacio de memoria.

### ¿Por Qué Usar Hilos?

Los hilos permiten:

1. **Aprovechar procesadores multinúcleo**: Ejecutar código verdaderamente en paralelo.
2. **Mejorar la responsividad**: Mantener la interfaz activa mientras se realizan tareas pesadas.
3. **Simplificar arquitecturas**: Modelar naturalmente tareas concurrentes (servidor web con múltiples clientes).
4. **Optimizar uso de recursos**: Compartir memoria en lugar de duplicarla (como con procesos).

### Hilos vs. Procesos

| Característica | Proceso | Hilo |
|----------------|---------|------|
| **Espacio de memoria** | Independiente | Compartido con otros hilos |
| **Creación** | Costosa (`fork`) | Ligera (`pthread_create`) |
| **Comunicación** | IPC (pipes, memoria compartida) | Variables compartidas |
| **Contexto** | PID, memoria, descriptores | Stack propio, registros |
| **Falla** | Aislada | Afecta todo el proceso |

:::{important}
Los hilos comparten el **heap** y las variables globales, pero cada hilo tiene su propio **stack**. Esto significa que las variables locales de una función son privadas de cada hilo, pero las variables globales y dinámicas son compartidas.
:::

## La Biblioteca POSIX Threads (pthreads)

POSIX define una API estándar para hilos llamada **pthreads**. Esta biblioteca está disponible en todos los sistemas Unix/Linux modernos.

### Compilación con pthreads

Para compilar programas que usan pthreads, debés enlazar la biblioteca:

```bash
gcc -pthread programa.c -o programa
```

O alternativamente:

```bash
gcc programa.c -lpthread -o programa
```

:::{note}
La opción `-pthread` es preferible porque además configura las macros de preprocesador necesarias para compilación segura con hilos.
:::

### Cabecera Principal

```c
#include <pthread.h>
```

## Creación y Terminación de Hilos

### Crear un Hilo: `pthread_create`

```c
int pthread_create(pthread_t *thread,
                   const pthread_attr_t *attr,
                   void *(*start_routine)(void *),
                   void *arg);
```

**Parámetros:**
- `thread`: Puntero donde se almacenará el identificador del hilo creado.
- `attr`: Atributos del hilo (generalmente `NULL` para valores por defecto).
- `start_routine`: Función que ejecutará el hilo. Debe tener firma `void* funcion(void*)`.
- `arg`: Argumento que se pasará a la función del hilo.

**Retorna:** `0` si tiene éxito, código de error en caso contrario.

### Ejemplo Básico: Hola Mundo con Hilos

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* saludar(void* arg) {
    int id = *(int*)arg;
    printf("Hola desde el hilo %d\n", id);
    return NULL;
}

int main(void) {
    pthread_t hilo1, hilo2;
    int id1 = 1, id2 = 2;
    
    // Crear dos hilos
    if (pthread_create(&hilo1, NULL, saludar, &id1) != 0) {
        perror("Error creando hilo 1");
        return 1;
    }
    
    if (pthread_create(&hilo2, NULL, saludar, &id2) != 0) {
        perror("Error creando hilo 2");
        return 1;
    }
    
    // Esperar a que terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    
    printf("Ambos hilos terminaron\n");
    return 0;
}
```

**Salida posible:**
```
Hola desde el hilo 1
Hola desde el hilo 2
Ambos hilos terminaron
```

:::{warning}
El orden de ejecución de los hilos **no está garantizado**. En diferentes ejecuciones, el hilo 2 podría imprimir antes que el hilo 1.
:::

### Esperar Terminación: `pthread_join`

```c
int pthread_join(pthread_t thread, void **retval);
```

**Propósito:** Bloquea el hilo llamante hasta que el hilo especificado termine.

**Parámetros:**
- `thread`: Identificador del hilo a esperar.
- `retval`: Puntero donde se almacenará el valor de retorno del hilo (puede ser `NULL`).

```c
void* calcular(void* arg) {
    int* resultado = malloc(sizeof(int));
    *resultado = 42;
    return resultado;
}

int main(void) {
    pthread_t hilo;
    int* resultado;
    
    pthread_create(&hilo, NULL, calcular, NULL);
    pthread_join(hilo, (void**)&resultado);
    
    printf("Resultado: %d\n", *resultado);
    free(resultado);
    return 0;
}
```

### Terminación de un Hilo: `pthread_exit`

```c
void pthread_exit(void *retval);
```

**Propósito:** Termina el hilo actual y devuelve un valor.

```c
void* trabajador(void* arg) {
    // Hacer trabajo...
    
    if (error) {
        pthread_exit((void*)1);  // Retornar código de error
    }
    
    pthread_exit((void*)0);  // Éxito
}
```

:::{note}
Si un hilo ejecuta `return valor;`, es equivalente a `pthread_exit(valor);`. Sin embargo, en la función `main`, `return` termina todo el proceso, no solo el hilo principal.
:::

### Hilos Separados (Detached)

Un hilo puede marcarse como **separado** (*detached*), lo que significa que sus recursos se liberarán automáticamente al terminar, sin necesidad de `pthread_join`.

```c
int pthread_detach(pthread_t thread);
```

```c
void* tarea_independiente(void* arg) {
    printf("Ejecutando tarea independiente\n");
    // Trabajo...
    return NULL;
}

int main(void) {
    pthread_t hilo;
    
    pthread_create(&hilo, NULL, tarea_independiente, NULL);
    pthread_detach(hilo);  // Ahora el hilo es independiente
    
    // No es necesario pthread_join
    sleep(1);  // Dar tiempo al hilo
    return 0;
}
```

:::{warning} Cuidado con Hilos Detached
Si el proceso principal termina, **todos los hilos terminan** inmediatamente, incluso los detached. Asegurate de que el hilo tenga tiempo suficiente para completar su trabajo.
:::

## Identificación de Hilos

### Obtener el ID del Hilo Actual

```c
pthread_t pthread_self(void);
```

```c
void* funcion(void* arg) {
    pthread_t mi_id = pthread_self();
    printf("Mi ID de hilo: %lu\n", (unsigned long)mi_id);
    return NULL;
}
```

### Comparar IDs de Hilos

```c
int pthread_equal(pthread_t t1, pthread_t t2);
```

Retorna un valor no cero si los IDs son iguales.

```c
if (pthread_equal(pthread_self(), hilo_maestro)) {
    printf("Soy el hilo maestro\n");
}
```

## Sincronización: El Problema de las Condiciones de Carrera

Cuando múltiples hilos acceden a datos compartidos **sin sincronización**, se producen **condiciones de carrera** (*race conditions*), donde el resultado depende del orden impredecible de ejecución.

### Ejemplo de Condición de Carrera

```c
#include <pthread.h>
#include <stdio.h>

int contador = 0;  // Variable compartida

void* incrementar(void* arg) {
    for (int i = 0; i < 100000; i++) {
        contador++;  // ¡NO ES ATÓMICO!
    }
    return NULL;
}

int main(void) {
    pthread_t h1, h2;
    
    pthread_create(&h1, NULL, incrementar, NULL);
    pthread_create(&h2, NULL, incrementar, NULL);
    
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    
    printf("Contador: %d (esperado: 200000)\n", contador);
    return 0;
}
```

**Salida típica:**
```
Contador: 137842 (esperado: 200000)
```

:::{important} ¿Por Qué Falla?
La operación `contador++` se traduce a tres instrucciones de ensamblador:
1. Leer `contador` en un registro
2. Incrementar el registro
3. Escribir el registro de vuelta a `contador`

Si dos hilos ejecutan esto simultáneamente, pueden **entrelazar** estas instrucciones, causando que incrementos se pierdan.
:::

## Mutexes: Exclusión Mutua

Un **mutex** (mutual exclusion) es un mecanismo de sincronización que garantiza que solo un hilo a la vez puede acceder a una sección crítica del código.

### Declaración e Inicialización

```c
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Inicialización estática
```

O dinámicamente:

```c
pthread_mutex_t mutex;
pthread_mutex_init(&mutex, NULL);
```

### Operaciones Básicas

#### Bloquear (Lock)

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

Bloquea el mutex. Si ya está bloqueado por otro hilo, espera hasta que se libere.

#### Desbloquear (Unlock)

```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

Libera el mutex, permitiendo que otro hilo lo adquiera.

#### Intentar Bloquear

```c
int pthread_mutex_trylock(pthread_mutex_t *mutex);
```

Intenta bloquear sin esperar. Retorna `0` si tiene éxito, `EBUSY` si ya está bloqueado.

### Ejemplo Corregido con Mutex

```c
#include <pthread.h>
#include <stdio.h>

int contador = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* incrementar(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        contador++;  // Sección crítica protegida
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t h1, h2;
    
    pthread_create(&h1, NULL, incrementar, NULL);
    pthread_create(&h2, NULL, incrementar, NULL);
    
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    
    printf("Contador: %d (esperado: 200000)\n", contador);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}
```

**Salida garantizada:**
```
Contador: 200000 (esperado: 200000)
```

### Destruir un Mutex

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

Libera los recursos asociados al mutex. Solo debe llamarse cuando ningún hilo lo esté usando.

:::{warning} Reglas Cruciales de Mutexes
1. **Siempre desbloquear**: Todo `lock` debe tener su correspondiente `unlock`.
2. **No bloquear dos veces**: Un hilo que ya tiene el mutex no debe intentar bloquearlo de nuevo (deadlock).
3. **Quien bloquea, desbloquea**: El mismo hilo que hizo `lock` debe hacer `unlock`.
4. **Secciones críticas cortas**: Minimizar el tiempo dentro del mutex para mejorar concurrencia.
:::

## Ejemplo Práctico: Contador con Múltiples Hilos

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_HILOS 4
#define INCREMENTOS_POR_HILO 250000

typedef struct {
    int id;
    int* contador_global;
    pthread_mutex_t* mutex;
} datos_hilo_t;

void* trabajador(void* arg) {
    datos_hilo_t* datos = (datos_hilo_t*)arg;
    
    for (int i = 0; i < INCREMENTOS_POR_HILO; i++) {
        pthread_mutex_lock(datos->mutex);
        (*datos->contador_global)++;
        pthread_mutex_unlock(datos->mutex);
    }
    
    printf("Hilo %d terminó\n", datos->id);
    return NULL;
}

int main(void) {
    pthread_t hilos[NUM_HILOS];
    datos_hilo_t datos[NUM_HILOS];
    int contador = 0;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    // Crear hilos
    for (int i = 0; i < NUM_HILOS; i++) {
        datos[i].id = i;
        datos[i].contador_global = &contador;
        datos[i].mutex = &mutex;
        
        if (pthread_create(&hilos[i], NULL, trabajador, &datos[i]) != 0) {
            perror("Error creando hilo");
            return 1;
        }
    }
    
    // Esperar terminación
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }
    
    printf("\nContador final: %d\n", contador);
    printf("Esperado: %d\n", NUM_HILOS * INCREMENTOS_POR_HILO);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}
```

## Variables de Condición

Las **variables de condición** permiten que hilos esperen hasta que se cumpla cierta condición, liberando eficientemente el CPU mientras esperan.

### Declaración e Inicialización

```c
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  // Estática

// O dinámica:
pthread_cond_t cond;
pthread_cond_init(&cond, NULL);
```

### Operaciones Principales

#### Esperar

```c
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
```

**Comportamiento:**
1. Libera el mutex
2. Bloquea el hilo hasta recibir señal
3. Re-adquiere el mutex antes de retornar

#### Señalizar

```c
int pthread_cond_signal(pthread_cond_t *cond);  // Despierta UN hilo
int pthread_cond_broadcast(pthread_cond_t *cond);  // Despierta TODOS los hilos
```

### Patrón Productor-Consumidor

Problema clásico: Un productor genera datos, un consumidor los procesa.

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t no_vacio;
    pthread_cond_t no_lleno;
} buffer_t;

void buffer_init(buffer_t* b) {
    b->count = 0;
    b->in = 0;
    b->out = 0;
    pthread_mutex_init(&b->mutex, NULL);
    pthread_cond_init(&b->no_vacio, NULL);
    pthread_cond_init(&b->no_lleno, NULL);
}

void buffer_destroy(buffer_t* b) {
    pthread_mutex_destroy(&b->mutex);
    pthread_cond_destroy(&b->no_vacio);
    pthread_cond_destroy(&b->no_lleno);
}

void producir(buffer_t* b, int item) {
    pthread_mutex_lock(&b->mutex);
    
    // Esperar mientras el buffer esté lleno
    while (b->count == BUFFER_SIZE) {
        pthread_cond_wait(&b->no_lleno, &b->mutex);
    }
    
    // Insertar item
    b->buffer[b->in] = item;
    b->in = (b->in + 1) % BUFFER_SIZE;
    b->count++;
    
    printf("Producido: %d (buffer: %d/%d)\n", item, b->count, BUFFER_SIZE);
    
    // Señalizar que hay items
    pthread_cond_signal(&b->no_vacio);
    pthread_mutex_unlock(&b->mutex);
}

int consumir(buffer_t* b) {
    pthread_mutex_lock(&b->mutex);
    
    // Esperar mientras el buffer esté vacío
    while (b->count == 0) {
        pthread_cond_wait(&b->no_vacio, &b->mutex);
    }
    
    // Extraer item
    int item = b->buffer[b->out];
    b->out = (b->out + 1) % BUFFER_SIZE;
    b->count--;
    
    printf("Consumido: %d (buffer: %d/%d)\n", item, b->count, BUFFER_SIZE);
    
    // Señalizar que hay espacio
    pthread_cond_signal(&b->no_lleno);
    pthread_mutex_unlock(&b->mutex);
    
    return item;
}

void* productor(void* arg) {
    buffer_t* b = (buffer_t*)arg;
    
    for (int i = 1; i <= 20; i++) {
        producir(b, i);
        usleep(100000);  // Simular trabajo
    }
    
    return NULL;
}

void* consumidor(void* arg) {
    buffer_t* b = (buffer_t*)arg;
    
    for (int i = 0; i < 20; i++) {
        int item = consumir(b);
        usleep(150000);  // Simular procesamiento
    }
    
    return NULL;
}

int main(void) {
    buffer_t buffer;
    buffer_init(&buffer);
    
    pthread_t hilo_prod, hilo_cons;
    
    pthread_create(&hilo_prod, NULL, productor, &buffer);
    pthread_create(&hilo_cons, NULL, consumidor, &buffer);
    
    pthread_join(hilo_prod, NULL);
    pthread_join(hilo_cons, NULL);
    
    buffer_destroy(&buffer);
    printf("Programa finalizado\n");
    return 0;
}
```

:::{important} Patrón While, No If
Siempre usar `while` (no `if`) para verificar la condición antes de `pthread_cond_wait`. Esto protege contra **señales espurias** (*spurious wakeups*), donde el hilo puede despertar sin que nadie haya señalizado.

```c
// CORRECTO
while (condicion_no_cumplida) {
    pthread_cond_wait(&cond, &mutex);
}

// INCORRECTO
if (condicion_no_cumplida) {
    pthread_cond_wait(&cond, &mutex);
}
```
:::

## Barreras de Sincronización

Una **barrera** es un punto de sincronización donde todos los hilos deben llegar antes de que cualquiera pueda continuar.

### Declaración e Uso

```c
pthread_barrier_t barrera;
pthread_barrier_init(&barrera, NULL, num_hilos);
```

```c
int pthread_barrier_wait(pthread_barrier_t *barrier);
```

Bloquea hasta que `num_hilos` hilos hayan llamado a `pthread_barrier_wait`.

### Ejemplo: Procesamiento por Fases

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_HILOS 4

pthread_barrier_t barrera;

void* trabajador(void* arg) {
    int id = *(int*)arg;
    
    // Fase 1
    printf("Hilo %d: Fase 1 iniciada\n", id);
    sleep(id);  // Simular trabajo variable
    printf("Hilo %d: Fase 1 completada\n", id);
    
    // Sincronizar antes de fase 2
    pthread_barrier_wait(&barrera);
    
    // Fase 2 (todos inician juntos)
    printf("Hilo %d: Fase 2 iniciada\n", id);
    sleep(1);
    printf("Hilo %d: Fase 2 completada\n", id);
    
    return NULL;
}

int main(void) {
    pthread_t hilos[NUM_HILOS];
    int ids[NUM_HILOS];
    
    pthread_barrier_init(&barrera, NULL, NUM_HILOS);
    
    for (int i = 0; i < NUM_HILOS; i++) {
        ids[i] = i;
        pthread_create(&hilos[i], NULL, trabajador, &ids[i]);
    }
    
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }
    
    pthread_barrier_destroy(&barrera);
    return 0;
}
```

## Read-Write Locks (Cerrojos de Lectura-Escritura)

Permiten que múltiples lectores accedan simultáneamente, pero escritores tienen acceso exclusivo.

### Declaración

```c
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

// O dinámico:
pthread_rwlock_t rwlock;
pthread_rwlock_init(&rwlock, NULL);
```

### Operaciones

```c
pthread_rwlock_rdlock(&rwlock);   // Bloqueo lectura
pthread_rwlock_wrlock(&rwlock);   // Bloqueo escritura
pthread_rwlock_unlock(&rwlock);   // Desbloquear
```

### Ejemplo: Base de Datos Simple

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int datos[100];
    pthread_rwlock_t lock;
} base_datos_t;

void bd_init(base_datos_t* bd) {
    for (int i = 0; i < 100; i++) {
        bd->datos[i] = i;
    }
    pthread_rwlock_init(&bd->lock, NULL);
}

int bd_leer(base_datos_t* bd, int indice) {
    pthread_rwlock_rdlock(&bd->lock);
    int valor = bd->datos[indice];
    printf("Leyendo [%d] = %d\n", indice, valor);
    usleep(10000);  // Simular lectura
    pthread_rwlock_unlock(&bd->lock);
    return valor;
}

void bd_escribir(base_datos_t* bd, int indice, int valor) {
    pthread_rwlock_wrlock(&bd->lock);
    printf("Escribiendo [%d] = %d\n", indice, valor);
    bd->datos[indice] = valor;
    usleep(50000);  // Simular escritura costosa
    pthread_rwlock_unlock(&bd->lock);
}

void* lector(void* arg) {
    base_datos_t* bd = (base_datos_t*)arg;
    for (int i = 0; i < 5; i++) {
        bd_leer(bd, rand() % 100);
    }
    return NULL;
}

void* escritor(void* arg) {
    base_datos_t* bd = (base_datos_t*)arg;
    for (int i = 0; i < 3; i++) {
        int idx = rand() % 100;
        bd_escribir(bd, idx, rand() % 1000);
    }
    return NULL;
}

int main(void) {
    base_datos_t bd;
    bd_init(&bd);
    
    pthread_t lectores[3], escritores[2];
    
    for (int i = 0; i < 3; i++) {
        pthread_create(&lectores[i], NULL, lector, &bd);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&escritores[i], NULL, escritor, &bd);
    }
    
    for (int i = 0; i < 3; i++) {
        pthread_join(lectores[i], NULL);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(escritores[i], NULL);
    }
    
    pthread_rwlock_destroy(&bd->lock);
    return 0;
}
```

## Almacenamiento Local del Hilo (Thread-Local Storage)

Permite que cada hilo tenga su propia copia de una variable.

### Declaración con `__thread`

```c
__thread int mi_variable = 0;  // Cada hilo tiene su propia copia
```

### Ejemplo: Contador por Hilo

```c
#include <pthread.h>
#include <stdio.h>

__thread int contador_local = 0;

void* trabajador(void* arg) {
    int id = *(int*)arg;
    
    for (int i = 0; i < 10; i++) {
        contador_local++;
    }
    
    printf("Hilo %d: contador_local = %d\n", id, contador_local);
    return NULL;
}

int main(void) {
    pthread_t hilos[3];
    int ids[3] = {1, 2, 3};
    
    for (int i = 0; i < 3; i++) {
        pthread_create(&hilos[i], NULL, trabajador, &ids[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }
    
    return 0;
}
```

**Salida:**
```
Hilo 1: contador_local = 10
Hilo 2: contador_local = 10
Hilo 3: contador_local = 10
```

Cada hilo incrementa su propia copia, sin interferencia.

## Deadlocks: El Abrazo Mortal

Un **deadlock** (interbloqueo) ocurre cuando dos o más hilos se bloquean mutuamente esperando recursos que el otro posee.

### Ejemplo de Deadlock

```c
pthread_mutex_t mutex_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_b = PTHREAD_MUTEX_INITIALIZER;

void* hilo1_func(void* arg) {
    pthread_mutex_lock(&mutex_a);
    sleep(1);  // Dar tiempo al otro hilo
    pthread_mutex_lock(&mutex_b);  // ¡DEADLOCK!
    
    // Trabajo...
    
    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_a);
    return NULL;
}

void* hilo2_func(void* arg) {
    pthread_mutex_lock(&mutex_b);
    sleep(1);
    pthread_mutex_lock(&mutex_a);  // ¡DEADLOCK!
    
    // Trabajo...
    
    pthread_mutex_unlock(&mutex_a);
    pthread_mutex_unlock(&mutex_b);
    return NULL;
}
```

### Condiciones para Deadlock

Un deadlock requiere **cuatro condiciones simultáneas** (Condiciones de Coffman):

1. **Exclusión mutua**: Los recursos no pueden compartirse.
2. **Retención y espera**: Un hilo retiene recursos mientras espera otros.
3. **No apropiación**: Los recursos no pueden quitarse forzosamente.
4. **Espera circular**: Existe un ciclo de hilos esperando recursos.

### Prevención de Deadlocks

#### Estrategia 1: Orden Global de Bloqueo

Todos los hilos adquieren mutexes en el **mismo orden**.

```c
// CORRECTO: Ambos hilos usan el mismo orden
void* hilo1_func(void* arg) {
    pthread_mutex_lock(&mutex_a);
    pthread_mutex_lock(&mutex_b);
    // Trabajo...
    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_a);
    return NULL;
}

void* hilo2_func(void* arg) {
    pthread_mutex_lock(&mutex_a);  // Mismo orden
    pthread_mutex_lock(&mutex_b);
    // Trabajo...
    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_a);
    return NULL;
}
```

#### Estrategia 2: Bloqueo Atómico con Trylock

```c
void* hilo_seguro(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex_a);
        
        if (pthread_mutex_trylock(&mutex_b) == 0) {
            // Tenemos ambos mutexes
            // Trabajo...
            pthread_mutex_unlock(&mutex_b);
            pthread_mutex_unlock(&mutex_a);
            break;
        } else {
            // No pudimos adquirir mutex_b, liberar mutex_a y reintentar
            pthread_mutex_unlock(&mutex_a);
            usleep(1000);  // Pequeña espera antes de reintentar
        }
    }
    return NULL;
}
```

#### Estrategia 3: Timeout

Usar versiones con timeout (extensiones no estándar o implementaciones propias):

```c
if (pthread_mutex_timedlock(&mutex, &timeout) != 0) {
    // Timeout, liberar recursos y reintentar
}
```

## Buenas Prácticas y Patrones Comunes

### 1. RAII para Mutexes (Cleanup Handlers)

Aunque C no tiene RAII como C++, podés usar cleanup handlers para garantizar liberación:

```c
void cleanup_mutex(void* arg) {
    pthread_mutex_t* mutex = (pthread_mutex_t*)arg;
    pthread_mutex_unlock(mutex);
}

void* hilo_con_cleanup(void* arg) {
    pthread_mutex_t* mutex = (pthread_mutex_t*)arg;
    
    pthread_mutex_lock(mutex);
    pthread_cleanup_push(cleanup_mutex, mutex);
    
    // Trabajo que puede ser cancelado...
    
    pthread_cleanup_pop(1);  // 1 = ejecutar cleanup
    return NULL;
}
```

### 2. Granularidad de Bloqueo

**Bloqueo grueso** (un mutex para todo):
```c
pthread_mutex_lock(&mutex_global);
// Muchas operaciones independientes
pthread_mutex_unlock(&mutex_global);
```

**Bloqueo fino** (múltiples mutexes específicos):
```c
pthread_mutex_lock(&mutex_lista_A);
// Operación en lista A
pthread_mutex_unlock(&mutex_lista_A);

pthread_mutex_lock(&mutex_lista_B);
// Operación en lista B
pthread_mutex_unlock(&mutex_lista_B);
```

:::{tip}
El bloqueo grueso es más simple pero reduce concurrencia. El bloqueo fino permite más paralelismo pero es más complejo y propenso a deadlocks.
:::

### 3. Patrón Double-Checked Locking (con Cuidado)

Este patrón es problemático en C debido a reordenamiento de instrucciones. Usarlo solo con barreras de memoria apropiadas:

```c
// Inicialización perezosa thread-safe
void* recurso = NULL;
pthread_mutex_t mutex_init = PTHREAD_MUTEX_INITIALIZER;

void* obtener_recurso(void) {
    if (recurso == NULL) {  // Primera verificación sin lock
        pthread_mutex_lock(&mutex_init);
        if (recurso == NULL) {  // Segunda verificación con lock
            recurso = inicializar_recurso();
        }
        pthread_mutex_unlock(&mutex_init);
    }
    return recurso;
}
```

:::{warning}
En C, este patrón puede fallar sin barreras de memoria apropiadas (memory fences). Para casos simples, mejor usar `pthread_once`:

```c
static pthread_once_t once = PTHREAD_ONCE_INIT;
static void* recurso;

void inicializar(void) {
    recurso = inicializar_recurso();
}

void* obtener_recurso(void) {
    pthread_once(&once, inicializar);
    return recurso;
}
```
:::

### 4. Cancelación de Hilos

Podés cancelar un hilo desde otro:

```c
pthread_t hilo;
// ...
pthread_cancel(hilo);  // Solicitar cancelación
```

El hilo objetivo debe estar preparado para cancelación:

```c
void* hilo_cancelable(void* arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    
    while (1) {
        pthread_testcancel();  // Punto de cancelación
        // Trabajo...
    }
    
    return NULL;
}
```

## Ejemplo Completo: Pool de Hilos Trabajadores

Un patrón común es tener un pool de hilos que procesan tareas de una cola.

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_WORKERS 4
#define QUEUE_SIZE 100

typedef void (*tarea_func_t)(void*);

typedef struct tarea {
    tarea_func_t funcion;
    void* argumento;
    struct tarea* siguiente;
} tarea_t;

typedef struct {
    tarea_t* cabeza;
    tarea_t* cola;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t hay_trabajo;
    pthread_cond_t hay_espacio;
    bool shutdown;
} cola_tareas_t;

typedef struct {
    pthread_t hilos[NUM_WORKERS];
    cola_tareas_t cola;
} thread_pool_t;

// Inicializar cola
void cola_init(cola_tareas_t* cola) {
    cola->cabeza = NULL;
    cola->cola = NULL;
    cola->count = 0;
    cola->shutdown = false;
    pthread_mutex_init(&cola->mutex, NULL);
    pthread_cond_init(&cola->hay_trabajo, NULL);
    pthread_cond_init(&cola->hay_espacio, NULL);
}

// Agregar tarea a la cola
void cola_push(cola_tareas_t* cola, tarea_func_t funcion, void* argumento) {
    pthread_mutex_lock(&cola->mutex);
    
    // Esperar si la cola está llena
    while (cola->count >= QUEUE_SIZE && !cola->shutdown) {
        pthread_cond_wait(&cola->hay_espacio, &cola->mutex);
    }
    
    if (cola->shutdown) {
        pthread_mutex_unlock(&cola->mutex);
        return;
    }
    
    // Crear nueva tarea
    tarea_t* nueva = malloc(sizeof(tarea_t));
    nueva->funcion = funcion;
    nueva->argumento = argumento;
    nueva->siguiente = NULL;
    
    // Agregar a la cola
    if (cola->cola == NULL) {
        cola->cabeza = nueva;
        cola->cola = nueva;
    } else {
        cola->cola->siguiente = nueva;
        cola->cola = nueva;
    }
    
    cola->count++;
    
    // Señalizar que hay trabajo
    pthread_cond_signal(&cola->hay_trabajo);
    pthread_mutex_unlock(&cola->mutex);
}

// Extraer tarea de la cola
tarea_t* cola_pop(cola_tareas_t* cola) {
    pthread_mutex_lock(&cola->mutex);
    
    // Esperar mientras no haya trabajo
    while (cola->count == 0 && !cola->shutdown) {
        pthread_cond_wait(&cola->hay_trabajo, &cola->mutex);
    }
    
    if (cola->shutdown && cola->count == 0) {
        pthread_mutex_unlock(&cola->mutex);
        return NULL;
    }
    
    // Extraer tarea
    tarea_t* tarea = cola->cabeza;
    cola->cabeza = tarea->siguiente;
    
    if (cola->cabeza == NULL) {
        cola->cola = NULL;
    }
    
    cola->count--;
    
    // Señalizar que hay espacio
    pthread_cond_signal(&cola->hay_espacio);
    pthread_mutex_unlock(&cola->mutex);
    
    return tarea;
}

// Función del worker
void* worker_thread(void* arg) {
    cola_tareas_t* cola = (cola_tareas_t*)arg;
    
    while (1) {
        tarea_t* tarea = cola_pop(cola);
        
        if (tarea == NULL) {
            // Shutdown
            break;
        }
        
        // Ejecutar tarea
        tarea->funcion(tarea->argumento);
        free(tarea);
    }
    
    printf("Worker terminando\n");
    return NULL;
}

// Crear thread pool
thread_pool_t* pool_create(void) {
    thread_pool_t* pool = malloc(sizeof(thread_pool_t));
    cola_init(&pool->cola);
    
    // Crear workers
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_create(&pool->hilos[i], NULL, worker_thread, &pool->cola);
    }
    
    return pool;
}

// Agregar trabajo al pool
void pool_add_work(thread_pool_t* pool, tarea_func_t funcion, void* argumento) {
    cola_push(&pool->cola, funcion, argumento);
}

// Destruir thread pool
void pool_destroy(thread_pool_t* pool) {
    // Señalizar shutdown
    pthread_mutex_lock(&pool->cola.mutex);
    pool->cola.shutdown = true;
    pthread_cond_broadcast(&pool->cola.hay_trabajo);
    pthread_mutex_unlock(&pool->cola.mutex);
    
    // Esperar a todos los workers
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_join(pool->hilos[i], NULL);
    }
    
    // Limpiar
    pthread_mutex_destroy(&pool->cola.mutex);
    pthread_cond_destroy(&pool->cola.hay_trabajo);
    pthread_cond_destroy(&pool->cola.hay_espacio);
    
    free(pool);
}

// Ejemplo de tarea
void tarea_ejemplo(void* arg) {
    int id = *(int*)arg;
    printf("Ejecutando tarea %d en hilo %lu\n", id, pthread_self());
    sleep(1);  // Simular trabajo
    free(arg);
}

int main(void) {
    thread_pool_t* pool = pool_create();
    
    // Agregar 20 tareas
    for (int i = 0; i < 20; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pool_add_work(pool, tarea_ejemplo, id);
    }
    
    // Esperar un poco para que se procesen
    sleep(6);
    
    // Destruir pool
    pool_destroy(pool);
    printf("Pool destruido, programa terminando\n");
    
    return 0;
}
```

## Depuración de Programas Multihilo

### Helgrind (Valgrind)

Detecta condiciones de carrera y errores de sincronización:

```bash
valgrind --tool=helgrind ./programa
```

### Thread Sanitizer (TSan)

Compilá con soporte para TSan:

```bash
gcc -g -fsanitize=thread programa.c -pthread -o programa
./programa
```

TSan detecta:
- Condiciones de carrera
- Deadlocks
- Uso incorrecto de primitivas de sincronización

### GDB con Hilos

```bash
gdb ./programa
(gdb) break pthread_create
(gdb) run
(gdb) info threads           # Listar todos los hilos
(gdb) thread 2               # Cambiar al hilo 2
(gdb) where                  # Stack trace del hilo actual
(gdb) thread apply all bt    # Stack traces de todos los hilos
```

## Consideraciones de Rendimiento

### 1. Overhead de Creación de Hilos

Crear hilos es costoso. Si necesitás crear muchos hilos para tareas cortas, usá un **thread pool**.

### 2. Granularidad vs. Overhead

Muy poca concurrencia → no aprovechás todos los núcleos  
Demasiada concurrencia → overhead de sincronización domina

**Regla práctica:** Número de hilos ≈ número de núcleos disponibles para tareas CPU-bound.

```c
#include <unistd.h>

int num_nucleos = sysconf(_SC_NPROCESSORS_ONLN);
```

### 3. Caché y False Sharing

Cuando múltiples hilos modifican datos en la **misma línea de caché** (típicamente 64 bytes), se produce **false sharing**:

```c
// MAL: Contadores en la misma línea de caché
struct {
    int contador_hilo1;
    int contador_hilo2;
} compartido;

// MEJOR: Separar con padding
struct {
    int contador_hilo1;
    char padding[60];
    int contador_hilo2;
} compartido;
```

### 4. Operaciones Atómicas

Para operaciones simples como incrementos, considerar operaciones atómicas en lugar de mutexes:

```c
#include <stdatomic.h>

atomic_int contador = ATOMIC_VAR_INIT(0);

void incrementar(void) {
    atomic_fetch_add(&contador, 1);  // Atómico, sin mutex
}
```

:::{note}
Las operaciones atómicas son más eficientes que mutexes para operaciones simples, pero no reemplazan mutexes para secciones críticas complejas.
:::

## Patrones de Diseño Comunes

### 1. Fork-Join

Dividir trabajo en subtareas paralelas y luego combinar resultados:

```c
void* procesar_rango(void* arg) {
    int* rango = (int*)arg;
    int inicio = rango[0];
    int fin = rango[1];
    
    int suma_local = 0;
    for (int i = inicio; i < fin; i++) {
        suma_local += array[i];
    }
    
    return (void*)(intptr_t)suma_local;
}

int suma_paralela(int* array, int n, int num_hilos) {
    pthread_t hilos[num_hilos];
    int rangos[num_hilos][2];
    int rango_size = n / num_hilos;
    
    // Fork: Crear hilos
    for (int i = 0; i < num_hilos; i++) {
        rangos[i][0] = i * rango_size;
        rangos[i][1] = (i == num_hilos - 1) ? n : (i + 1) * rango_size;
        pthread_create(&hilos[i], NULL, procesar_rango, rangos[i]);
    }
    
    // Join: Combinar resultados
    int suma_total = 0;
    for (int i = 0; i < num_hilos; i++) {
        void* resultado;
        pthread_join(hilos[i], &resultado);
        suma_total += (int)(intptr_t)resultado;
    }
    
    return suma_total;
}
```

### 2. Pipeline

Dividir procesamiento en etapas, cada una manejada por un hilo:

```
[Hilo 1: Leer datos] → [Hilo 2: Procesar] → [Hilo 3: Escribir resultados]
```

### 3. Master-Worker

Un hilo maestro distribuye trabajo a workers:

```c
// Maestro
void* maestro(void* arg) {
    while (hay_trabajo()) {
        tarea_t tarea = obtener_siguiente_tarea();
        agregar_a_cola(tarea);
    }
    return NULL;
}

// Worker
void* worker(void* arg) {
    while (1) {
        tarea_t tarea = extraer_de_cola();
        if (tarea == NULL) break;
        procesar(tarea);
    }
    return NULL;
}
```

## Errores Comunes y Cómo Evitarlos

### 1. Olvidar Inicializar/Destruir Primitivas

```c
// MAL
pthread_mutex_t mutex;
pthread_mutex_lock(&mutex);  // ¡Comportamiento indefinido!

// BIEN
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// o
pthread_mutex_init(&mutex, NULL);
```

### 2. Bloquear el Mismo Mutex Dos Veces

```c
pthread_mutex_lock(&mutex);
// ...
pthread_mutex_lock(&mutex);  // ¡DEADLOCK!
```

Solución: Usar mutexes recursivos si realmente necesitás anidamiento:

```c
pthread_mutexattr_t attr;
pthread_mutexattr_init(&attr);
pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
pthread_mutex_init(&mutex, &attr);
```

### 3. No Proteger Datos Compartidos

```c
// Compartido entre hilos
int saldo = 1000;

// MAL: Sin protección
void retirar(int monto) {
    if (saldo >= monto) {  // Condición de carrera
        saldo -= monto;
    }
}

// BIEN: Con mutex
pthread_mutex_t mutex_saldo = PTHREAD_MUTEX_INITIALIZER;

void retirar(int monto) {
    pthread_mutex_lock(&mutex_saldo);
    if (saldo >= monto) {
        saldo -= monto;
    }
    pthread_mutex_unlock(&mutex_saldo);
}
```

### 4. Pasar Punteros a Variables Locales

```c
// MAL
void crear_hilos(void) {
    for (int i = 0; i < 10; i++) {
        pthread_create(&hilos[i], NULL, trabajador, &i);  // ¡Todos ven la misma variable!
    }
}

// BIEN
void crear_hilos(void) {
    int* ids = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        ids[i] = i;
        pthread_create(&hilos[i], NULL, trabajador, &ids[i]);
    }
}
```

### 5. No Verificar Códigos de Error

```c
// MAL
pthread_create(&hilo, NULL, funcion, NULL);

// BIEN
if (pthread_create(&hilo, NULL, funcion, NULL) != 0) {
    perror("Error creando hilo");
    exit(1);
}
```

## Comparación con Otras Alternativas

### OpenMP

Para paralelismo de datos simple, OpenMP es más sencillo:

```c
#include <omp.h>

#pragma omp parallel for
for (int i = 0; i < n; i++) {
    procesar(array[i]);
}
```

Compilar con: `gcc -fopenmp programa.c`

### Procesos vs. Hilos

| Aspecto | Procesos (fork) | Hilos (pthreads) |
|---------|-----------------|------------------|
| Aislamiento | Total | Comparten memoria |
| Seguridad | Mayor | Menor |
| Comunicación | IPC | Variables compartidas |
| Overhead | Mayor | Menor |
| Uso típico | Servidores, aislamiento | Aplicaciones, paralelismo |

## Referencias y Recursos

### Libros Recomendados

- **"Programming with POSIX Threads"** - David R. Butenhof  
  La referencia definitiva sobre pthreads.

- **"The Art of Multiprocessor Programming"** - Maurice Herlihy & Nir Shavit  
  Teoría profunda sobre programación concurrente.

- **"C Programming: A Modern Approach"** - K. N. King  
  Capítulos sobre pthreads con enfoque práctico.

### Documentación Online

- `man pthread_create`, `man pthread_mutex_lock`, etc.
- [POSIX Threads Programming (LLNL)](https://hpc-tutorials.llnl.gov/posix/)
- [GNU C Library Manual - POSIX Threads](https://www.gnu.org/software/libc/manual/html_node/POSIX-Threads.html)

### Herramientas

- **Valgrind + Helgrind**: Detección de race conditions
- **Thread Sanitizer (TSan)**: Análisis de concurrencia
- **perf**: Análisis de rendimiento en Linux
- **htop**: Visualizar hilos en ejecución

## Resumen

La programación con hilos en C mediante pthreads permite aprovechar el paralelismo de hardware moderno, pero requiere disciplina y comprensión de los mecanismos de sincronización:

:::{important} Conceptos Clave

1. **Hilos comparten memoria**: Eficiente pero requiere sincronización cuidadosa.
2. **Mutexes protegen secciones críticas**: Garantizan exclusión mutua.
3. **Variables de condición coordinan hilos**: Permiten esperar condiciones eficientemente.
4. **Deadlocks son peligrosos**: Prevenirlos con orden global de bloqueo.
5. **Condiciones de carrera son sutiles**: Usar herramientas como Helgrind y TSan.
6. **Rendimiento no es automático**: El overhead de sincronización puede dominar para problemas pequeños.
7. **Depuración es más difícil**: Errores no determinísticos requieren herramientas especializadas.
:::

:::{tip} Cuándo Usar Hilos

**Usar hilos cuando:**
- Necesitás paralelismo verdadero (tareas CPU-intensivas)
- Múltiples tareas concurrentes naturalmente (servidor web)
- Compartir datos entre tareas es importante

**No usar hilos cuando:**
- El problema es inherentemente secuencial
- El overhead de sincronización supera los beneficios
- La complejidad no justifica el beneficio de rendimiento
- Podés usar procesos para aislamiento más seguro
:::

La programación concurrente es un tema profundo y complejo. Este apunte cubre los fundamentos, pero dominar hilos requiere práctica, experiencia con errores comunes, y estudio continuo de patrones y técnicas avanzadas.
